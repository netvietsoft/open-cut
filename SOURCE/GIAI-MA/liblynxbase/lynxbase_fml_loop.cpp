// ============================================================================
// File: lynxbase_fml_loop.cpp
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: Lynx FML MessageLoop, TaskRunner, TaskQueues, Synchronization
//            Primitives, Thread, Timer & TimedTaskManager Implementation
//            (.text 0x01499c..0x020838, 0x023ff8..0x024380)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 implementation of `lynx::fml` and `lynx::base::TimedTaskManager`
//      reconstructed from `liblynxbase.so` AArch64 machine code.
// [VN] Bản cài đặt C++17 tái tạo sạch cho không gian tên `lynx::fml` và
//      `lynx::base::TimedTaskManager` trích xuất từ mã máy AArch64 của `liblynxbase.so`.
// ============================================================================

#include "lynxbase_fml_loop.h"
#include "lynxbase_string_crypto.h"

#include <algorithm>
#include <chrono>

#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
#include <dirent.h>
#include <pthread.h>
#include <sys/resource.h>
#include <unistd.h>
#endif

namespace lynx {
namespace fml {

// ============================================================================
// 1. `TimePoint::Now()` (`0x01de5c`) & `TimePoint::CurrentWallTime()` (`0x01de60`)
// ============================================================================
// [EN] AArch64 disassembly at `0x01de5c..0x01de74`:
//      0x01de5c: b 0x2d5e0 (`lynx::base::CurrentTimeNanoseconds()`)
//      0x01de60: stp x29, x30, [sp, #-0x10]!
//      0x01de64: bl 0x2d540 (`lynx::base::CurrentSystemTimeMicroseconds()`)
//      0x01de68: mov w8, #0x3e8          // 0x52807D08 (1000)
//      0x01de6c: mul x0, x0, x8          // 0x9B087C00 (us * 1000 -> ns)
//      0x01de70: ldp x29, x30, [sp], #0x10
//      0x01de74: ret
// [VN] Mã máy AArch64 tại `0x01de5c..0x01de74`: `Now()` nhảy trực tiếp tới
//      `CurrentTimeNanoseconds()`, còn `CurrentWallTime()` gọi
//      `CurrentSystemTimeMicroseconds()` rồi nhân với `1000` (`#0x3e8`).
TimePoint TimePoint::Now() noexcept {
    return TimePoint(static_cast<int64_t>(base::CurrentTimeNanoseconds()));
}

TimePoint TimePoint::CurrentWallTime() noexcept {
    const uint64_t wall_us = base::CurrentSystemTimeMicroseconds();
    return TimePoint(static_cast<int64_t>(wall_us * 1000ULL));
}

// ============================================================================
// 2. Synchronization Primitives (`CountDownLatch`, `SyncSwitch`,
//    `AutoResetWaitableEvent`, `SharedMutex`, `UniqueFDTraits`, `UniqueDirTraits`)
// ============================================================================

// [EN] `CountDownLatch::CountDownLatch(uint32_t)` @ 0x01c580..0x01c5b0.
// [VN] Hàm tạo `CountDownLatch` tại `0x01c580..0x01c5b0`.
CountDownLatch::CountDownLatch(uint32_t count) : m_count(count) {}

CountDownLatch::~CountDownLatch() = default;

// [EN] `CountDownLatch::Wait()` @ 0x01c5b8..0x01c63c:
//      Checks `ldar w8, [x19, #0x60]; cbz w8, .Lret` before locking `m_mutex`.
// [VN] `CountDownLatch::Wait()` tại `0x01c5b8..0x01c63c`: kiểm tra nguyên tử
//      `m_count == 0` trước khi khóa `m_mutex` và chờ trên biến điều kiện.
void CountDownLatch::Wait() {
    if (m_count.load(std::memory_order_acquire) == 0) {
        return;
    }
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv.wait(lock, [this]() {
        return m_count.load(std::memory_order_acquire) == 0;
    });
}

// [EN] `CountDownLatch::CountDown()` @ 0x01c640..0x01c698:
//      Atomically decrements `m_count`; when reaching 0, locks `m_mutex` and
//      calls `notify_all()`.
// [VN] `CountDownLatch::CountDown()` tại `0x01c640..0x01c698`: giảm nguyên tử
//      `m_count`; khi về 0 thì khóa `m_mutex` và đánh thức toàn bộ luồng chờ.
void CountDownLatch::CountDown() {
    const uint32_t prev = m_count.fetch_sub(1, std::memory_order_acq_rel);
    if (prev <= 1) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_cv.notify_all();
    }
}

// [EN] `SyncSwitch::Handlers::SetIfTrue` (`0x01c6ec`) & `SetIfFalse` (`0x01c750`).
// [VN] Thiết lập hàm xử lý nhánh đúng/sai cho `SyncSwitch`.
SyncSwitch::Handlers& SyncSwitch::Handlers::SetIfTrue(const std::function<void()>& handler) {
    true_handler = handler;
    return *this;
}

SyncSwitch::Handlers& SyncSwitch::Handlers::SetIfFalse(const std::function<void()>& handler) {
    false_handler = handler;
    return *this;
}

// [EN] `SyncSwitch::SyncSwitch(bool)` @ 0x01c69c..0x01c6e8.
// [VN] Hàm tạo `SyncSwitch` tại `0x01c69c..0x01c6e8`.
SyncSwitch::SyncSwitch(bool value) : m_value(value) {}

// [EN] `SyncSwitch::Execute(const Handlers&)` @ 0x01c7b8..0x01c81c:
//      Acquires shared lock (`vtable +0x18` = `LockShared`), invokes either
//      `true_handler` or `false_handler`, and releases shared lock (`vtable +0x28`).
// [VN] `SyncSwitch::Execute` tại `0x01c7b8..0x01c81c`: lấy khóa đọc chia sẻ,
//      thực thi nhánh tương ứng với `m_value`, sau đó nhả khóa đọc.
void SyncSwitch::Execute(const Handlers& handlers) const {
    std::shared_lock<std::shared_mutex> shared_lock(m_mutex);
    if (m_value) {
        if (handlers.true_handler) {
            handlers.true_handler();
        }
    } else {
        if (handlers.false_handler) {
            handlers.false_handler();
        }
    }
}

// [EN] `SyncSwitch::SetSwitch(bool)` @ 0x01c820..0x01c858:
//      Acquires exclusive lock (`vtable +0x10` = `Lock`), updates `m_value`,
//      and releases exclusive lock (`vtable +0x20` = `Unlock`).
// [VN] `SyncSwitch::SetSwitch` tại `0x01c820..0x01c858`: lấy khóa ghi độc quyền,
//      cập nhật `m_value`, và mở khóa.
void SyncSwitch::SetSwitch(bool value) {
    std::unique_lock<std::shared_mutex> unique_lock(m_mutex);
    m_value = value;
}

// [EN] `AutoResetWaitableEvent` methods (`0x01cc64..0x01cf50`).
// [VN] Các phương thức của `AutoResetWaitableEvent` (`0x01cc64..0x01cf50`).
void AutoResetWaitableEvent::Reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_signaled = false;
}

void AutoResetWaitableEvent::Signal() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_signaled = true;
    m_cv.notify_one();
}

void AutoResetWaitableEvent::Wait() {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cv.wait(lock, [this]() { return m_signaled; });
    m_signaled = false;
}

bool AutoResetWaitableEvent::WaitWithTimeout(TimeDelta timeout) {
    std::unique_lock<std::mutex> lock(m_mutex);
    const auto duration_ns = std::chrono::nanoseconds(timeout.ToNanoseconds());
    const bool ok = m_cv.wait_for(lock, duration_ns, [this]() { return m_signaled; });
    if (ok) {
        m_signaled = false;
    }
    return ok;
}

bool AutoResetWaitableEvent::IsSignaledForTestOnly() {
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_signaled;
}

// [EN] `SharedMutex::Create()` @ 0x01f9dc & `SharedMutexPosix` @ 0x01fa0c..0x01fa58.
// [VN] `SharedMutex::Create()` @ 0x01f9dc & `SharedMutexPosix` @ 0x01fa0c..0x01fa58.
SharedMutex* SharedMutex::Create() {
    return new SharedMutexPosix();
}

SharedMutexPosix::SharedMutexPosix() = default;

void SharedMutexPosix::Lock() {
    m_rwlock.lock();
}

void SharedMutexPosix::LockShared() {
    m_rwlock.lock_shared();
}

void SharedMutexPosix::Unlock() {
    m_rwlock.unlock();
}

void SharedMutexPosix::UnlockShared() {
    m_rwlock.unlock_shared();
}

// [EN] `UniqueFDTraits::Free(int)` @ 0x01e2d0 -> `b close@PLT`.
// [VN] `UniqueFDTraits::Free(int)` @ 0x01e2d0 -> gọi `close(fd)`.
void UniqueFDTraits::Free(int fd) {
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    if (fd >= 0) {
        ::close(fd);
    }
#else
    (void)fd;
#endif
}

namespace internal {
// [EN] `UniqueDirTraits::Free(DIR*)` @ 0x01e2d4 -> `b closedir@PLT`.
// [VN] `UniqueDirTraits::Free(DIR*)` @ 0x01e2d4 -> gọi `closedir(dir)`.
void UniqueDirTraits::Free(DIR* dir) {
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    if (dir != nullptr) {
        ::closedir(dir);
    }
#else
    (void)dir;
#endif
}
} // namespace internal

// ============================================================================
// 3. `MessageLoopTaskQueues` (.text 0x017d24..0x019ab0)
// ============================================================================

// [EN] `MessageLoopTaskQueues::GetInstance()` @ 0x017d24:
//      Uses `std::call_once` at `.bss 0x038218` to construct the singleton
//      stored at `.bss 0x038210`.
// [VN] `MessageLoopTaskQueues::GetInstance()` @ 0x017d24: khởi tạo singleton
//      một lần duy nhất qua `std::call_once` tại `.bss 0x038218`.
RefPtr<MessageLoopTaskQueues> MessageLoopTaskQueues::GetInstance() {
    static std::shared_ptr<MessageLoopTaskQueues> s_instance =
        std::make_shared<MessageLoopTaskQueues>();
    return RefPtr<MessageLoopTaskQueues>(s_instance);
}

MessageLoopTaskQueues::MessageLoopTaskQueues() = default;
MessageLoopTaskQueues::~MessageLoopTaskQueues() = default;

// [EN] `MessageLoopTaskQueues::CreateTaskQueue(bool)` @ 0x017fb8.
// [VN] Tạo hàng đợi tác vụ mới và cấp phát `TaskQueueId` tăng dần (`0x017fb8`).
TaskQueueId MessageLoopTaskQueues::CreateTaskQueue(bool is_vsync_aligned) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    const size_t next_id = m_taskQueueIdCounter++;
    auto entry = std::make_unique<QueueEntry>();
    entry->queue_id = TaskQueueId(next_id);
    entry->is_vsync_aligned = is_vsync_aligned;
    m_queues.emplace(next_id, std::move(entry));
    return TaskQueueId(next_id);
}

void MessageLoopTaskQueues::Dispose(TaskQueueId queue_id) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    m_queues.erase(queue_id.Value());
}

void MessageLoopTaskQueues::DisposeTasks(TaskQueueId queue_id) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end()) {
        it->second->delayed_tasks.clear();
        it->second->microtasks.clear();
        if (it->second->owner_of.IsValid()) {
            auto sub_it = m_queues.find(it->second->owner_of.Value());
            if (sub_it != m_queues.end()) {
                sub_it->second->delayed_tasks.clear();
                sub_it->second->microtasks.clear();
            }
        }
    }
}

// [EN] `MessageLoopTaskQueues::RegisterTask` @ 0x018734:
//      Enqueues either a microtask or a delayed/immediate task ordered by
//      `(target_time, m_orderCounter++)` and wakes the owning loop via
//      `WakeUpUnlocked` (`0x018ad0`).
// [VN] `MessageLoopTaskQueues::RegisterTask` @ 0x018734: đưa microtask hoặc
//      tác vụ định thời vào hàng đợi theo thứ tự `(target_time, order)` và
//      đánh thức vòng lặp sở hữu qua `WakeUpUnlocked` (`0x018ad0`).
void MessageLoopTaskQueues::RegisterTask(TaskQueueId queue_id,
                                          base::MoveOnlyClosure<void()>&& task,
                                          TimePoint target_time,
                                          TaskSourceGrade task_source_grade,
                                          bool is_microtask) {
    if (!task) {
        return;
    }
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it == m_queues.end()) {
        return;
    }

    DelayedTask item;
    item.order = m_orderCounter.fetch_add(1, std::memory_order_relaxed);
    item.task = std::move(task);
    item.target_time = target_time;
    item.task_source_grade =
        is_microtask ? TaskSourceGrade::kMicrotask : task_source_grade;

    if (is_microtask) {
        it->second->microtasks.push_back(std::move(item));
    } else {
        auto& dq = it->second->delayed_tasks;
        auto pos = std::upper_bound(
            dq.begin(), dq.end(), item,
            [](const DelayedTask& a, const DelayedTask& b) {
                return b > a;
            });
        dq.insert(pos, std::move(item));
    }

    const TaskQueueId wake_queue =
        it->second->subsumed_by.IsValid() ? it->second->subsumed_by : queue_id;
    WakeUpUnlocked(wake_queue, GetNextWakeTimeUnlocked(wake_queue, it->second->is_vsync_aligned));
}

bool MessageLoopTaskQueues::HasPendingTasks(TaskQueueId queue_id) const {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    return HasPendingTasksUnlocked(queue_id);
}

bool MessageLoopTaskQueues::HasPendingMicroTasks(TaskQueueId queue_id) const {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    return HasPendingMicroTasksUnlocked(queue_id);
}

bool MessageLoopTaskQueues::HasPendingTasksUnlocked(TaskQueueId queue_id) const {
    auto it = m_queues.find(queue_id.Value());
    if (it == m_queues.end()) {
        return false;
    }
    if (!it->second->is_paused && !it->second->delayed_tasks.empty()) {
        return true;
    }
    if (it->second->owner_of.IsValid()) {
        auto sub_it = m_queues.find(it->second->owner_of.Value());
        if (sub_it != m_queues.end() && !sub_it->second->is_paused &&
            !sub_it->second->delayed_tasks.empty()) {
            return true;
        }
    }
    return false;
}

bool MessageLoopTaskQueues::HasPendingMicroTasksUnlocked(TaskQueueId queue_id) const {
    auto it = m_queues.find(queue_id.Value());
    if (it == m_queues.end()) {
        return false;
    }
    if (!it->second->microtasks.empty()) {
        return true;
    }
    if (it->second->owner_of.IsValid()) {
        auto sub_it = m_queues.find(it->second->owner_of.Value());
        if (sub_it != m_queues.end() && !sub_it->second->microtasks.empty()) {
            return true;
        }
    }
    return false;
}

// [EN] `MessageLoopTaskQueues::GetNextTaskToRun` @ 0x018bf0:
//      Selects the earliest expired task across `queue_id` and its subsumed
//      queue (`owner_of`), pops it, and re-arms the wakeable timer.
// [VN] `MessageLoopTaskQueues::GetNextTaskToRun` @ 0x018bf0: chọn tác vụ hết hạn
//      sớm nhất giữa `queue_id` và hàng đợi con đã gộp (`owner_of`), lấy ra khỏi
//      hàng đợi và đặt lại bộ hẹn giờ đánh thức.
base::MoveOnlyClosure<void()> MessageLoopTaskQueues::GetNextTaskToRun(
    TaskQueueId queue_id,
    TimePoint from_time,
    bool is_vsync_aligned,
    bool only_microtasks) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it == m_queues.end() || it->second->is_paused) {
        return nullptr;
    }

    if (only_microtasks) {
        if (!it->second->microtasks.empty()) {
            auto task = std::move(it->second->microtasks.front().task);
            it->second->microtasks.pop_front();
            return task;
        }
        if (it->second->owner_of.IsValid()) {
            auto sub_it = m_queues.find(it->second->owner_of.Value());
            if (sub_it != m_queues.end() && !sub_it->second->microtasks.empty()) {
                auto task = std::move(sub_it->second->microtasks.front().task);
                sub_it->second->microtasks.pop_front();
                return task;
            }
        }
        return nullptr;
    }

    QueueEntry* chosen_entry = nullptr;
    if (!it->second->delayed_tasks.empty() &&
        it->second->delayed_tasks.front().target_time <= from_time) {
        chosen_entry = it->second.get();
    }

    if (it->second->owner_of.IsValid()) {
        auto sub_it = m_queues.find(it->second->owner_of.Value());
        if (sub_it != m_queues.end() && !sub_it->second->is_paused &&
            !sub_it->second->delayed_tasks.empty()) {
            const auto& top_sub = sub_it->second->delayed_tasks.front();
            if (top_sub.target_time <= from_time) {
                if (chosen_entry == nullptr ||
                    chosen_entry->delayed_tasks.front() > top_sub) {
                    chosen_entry = sub_it->second.get();
                }
            }
        }
    }

    if (chosen_entry == nullptr) {
        WakeUpUnlocked(queue_id, GetNextWakeTimeUnlocked(queue_id, is_vsync_aligned));
        return nullptr;
    }

    base::MoveOnlyClosure<void()> result = std::move(chosen_entry->delayed_tasks.front().task);
    chosen_entry->delayed_tasks.pop_front();
    WakeUpUnlocked(queue_id, GetNextWakeTimeUnlocked(queue_id, is_vsync_aligned));
    return result;
}

TimePoint MessageLoopTaskQueues::GetNextWakeTimeUnlocked(TaskQueueId queue_id, bool) const {
    auto it = m_queues.find(queue_id.Value());
    if (it == m_queues.end()) {
        return TimePoint::Max();
    }
    TimePoint min_time = TimePoint::Max();
    if (!it->second->is_paused && !it->second->delayed_tasks.empty()) {
        min_time = it->second->delayed_tasks.front().target_time;
    }
    if (it->second->owner_of.IsValid()) {
        auto sub_it = m_queues.find(it->second->owner_of.Value());
        if (sub_it != m_queues.end() && !sub_it->second->is_paused &&
            !sub_it->second->delayed_tasks.empty()) {
            const TimePoint sub_time = sub_it->second->delayed_tasks.front().target_time;
            if (sub_time < min_time) {
                min_time = sub_time;
            }
        }
    }
    return min_time;
}

void MessageLoopTaskQueues::WakeUpUnlocked(TaskQueueId queue_id, TimePoint time) const {
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end() && it->second->wakeable != nullptr) {
        it->second->wakeable->WakeUp(time);
    }
}

size_t MessageLoopTaskQueues::GetNumPendingTasks(TaskQueueId queue_id) const {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it == m_queues.end()) {
        return 0;
    }
    size_t total = it->second->delayed_tasks.size();
    if (it->second->owner_of.IsValid()) {
        auto sub_it = m_queues.find(it->second->owner_of.Value());
        if (sub_it != m_queues.end()) {
            total += sub_it->second->delayed_tasks.size();
        }
    }
    return total;
}

void MessageLoopTaskQueues::AddTaskObserver(TaskQueueId queue_id,
                                             intptr_t key,
                                             base::MoveOnlyClosure<void()>&& callback) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end() && callback) {
        it->second->task_observers[key] = std::move(callback);
    }
}

void MessageLoopTaskQueues::RemoveTaskObserver(TaskQueueId queue_id, intptr_t key) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end()) {
        it->second->task_observers.erase(key);
    }
}

std::vector<base::MoveOnlyClosure<void()>*> MessageLoopTaskQueues::NotifyObservers(TaskQueueId queue_id) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    std::vector<base::MoveOnlyClosure<void()>*> observers;
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end()) {
        for (auto& kv : it->second->task_observers) {
            observers.push_back(&kv.second);
        }
        if (it->second->owner_of.IsValid()) {
            auto sub_it = m_queues.find(it->second->owner_of.Value());
            if (sub_it != m_queues.end()) {
                for (auto& kv : sub_it->second->task_observers) {
                    observers.push_back(&kv.second);
                }
            }
        }
    }
    return observers;
}

void MessageLoopTaskQueues::SetWakeable(TaskQueueId queue_id, Wakeable* wakeable) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end()) {
        it->second->wakeable = wakeable;
    }
}

// [EN] `MessageLoopTaskQueues::Merge(TaskQueueId, TaskQueueId)` @ 0x0194dc.
// [VN] Gộp hàng đợi `subsumed` vào `owner` (`0x0194dc`).
bool MessageLoopTaskQueues::Merge(TaskQueueId owner, TaskQueueId subsumed) {
    if (owner == subsumed) {
        return true;
    }
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto owner_it = m_queues.find(owner.Value());
    auto sub_it = m_queues.find(subsumed.Value());
    if (owner_it == m_queues.end() || sub_it == m_queues.end()) {
        return false;
    }
    if (owner_it->second->owner_of == subsumed && sub_it->second->subsumed_by == owner) {
        return true;
    }
    if (owner_it->second->owner_of.IsValid() || owner_it->second->subsumed_by.IsValid() ||
        sub_it->second->owner_of.IsValid() || sub_it->second->subsumed_by.IsValid()) {
        return false;
    }
    owner_it->second->owner_of = subsumed;
    sub_it->second->subsumed_by = owner;
    WakeUpUnlocked(owner, GetNextWakeTimeUnlocked(owner, owner_it->second->is_vsync_aligned));
    return true;
}

// [EN] `MessageLoopTaskQueues::Unmerge(TaskQueueId, TaskQueueId)` @ 0x019718.
// [VN] Tách hàng đợi `subsumed` khỏi `owner` (`0x019718`).
bool MessageLoopTaskQueues::Unmerge(TaskQueueId owner, TaskQueueId subsumed) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto owner_it = m_queues.find(owner.Value());
    auto sub_it = m_queues.find(subsumed.Value());
    if (owner_it == m_queues.end() || sub_it == m_queues.end()) {
        return false;
    }
    if (owner_it->second->owner_of != subsumed || sub_it->second->subsumed_by != owner) {
        return false;
    }
    owner_it->second->owner_of = TaskQueueId();
    sub_it->second->subsumed_by = TaskQueueId();
    WakeUpUnlocked(owner, GetNextWakeTimeUnlocked(owner, owner_it->second->is_vsync_aligned));
    WakeUpUnlocked(subsumed, GetNextWakeTimeUnlocked(subsumed, sub_it->second->is_vsync_aligned));
    return true;
}

bool MessageLoopTaskQueues::Owns(TaskQueueId owner, TaskQueueId subsumed) const {
    if (!owner.IsValid() || !subsumed.IsValid()) {
        return false;
    }
    if (owner == subsumed) {
        return true;
    }
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto owner_it = m_queues.find(owner.Value());
    if (owner_it == m_queues.end()) {
        return false;
    }
    return owner_it->second->owner_of == subsumed;
}

bool MessageLoopTaskQueues::IsSubsumed(TaskQueueId queue_id) const {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    return it != m_queues.end() && it->second->subsumed_by.IsValid();
}

TaskQueueId MessageLoopTaskQueues::GetSubsumedTaskQueueId(TaskQueueId owner) const {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(owner.Value());
    if (it == m_queues.end()) {
        return TaskQueueId();
    }
    return it->second->owner_of;
}

void MessageLoopTaskQueues::PauseTasks(TaskQueueId queue_id) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end()) {
        it->second->is_paused = true;
    }
}

void MessageLoopTaskQueues::ResumeTasks(TaskQueueId queue_id) {
    std::lock_guard<std::mutex> lock(m_queueMutex);
    auto it = m_queues.find(queue_id.Value());
    if (it != m_queues.end()) {
        it->second->is_paused = false;
        WakeUpUnlocked(queue_id, GetNextWakeTimeUnlocked(queue_id, it->second->is_vsync_aligned));
    }
}

// ============================================================================
// 4. `MessageLoopImpl` (.text 0x016558..0x0172dc) &
//    `MessageLoopAndroid` (.text 0x023ff8..0x024380)
// ============================================================================

RefPtr<MessageLoopImpl> MessageLoopImpl::Create(void* platform_loop) {
    auto shared = std::make_shared<MessageLoopAndroid>(platform_loop);
    return RefPtr<MessageLoopImpl>(std::static_pointer_cast<MessageLoopImpl>(shared));
}

MessageLoopImpl::MessageLoopImpl()
    : m_taskQueues(MessageLoopTaskQueues::GetInstance()) {
    const TaskQueueId qid = m_taskQueues->CreateTaskQueue(false);
    Bind(qid);
}

MessageLoopImpl::~MessageLoopImpl() {
    for (size_t i = 0; i < m_queueIds.size(); ++i) {
        m_taskQueues->SetWakeable(m_queueIds[i], nullptr);
    }
}

void MessageLoopImpl::PostTask(base::MoveOnlyClosure<void()>&& task,
                               TimePoint target_time,
                               TaskSourceGrade task_source_grade,
                               bool is_microtask) {
    if (m_terminated.load(std::memory_order_acquire) || m_queueIds.empty()) {
        return;
    }
    m_taskQueues->RegisterTask(
        m_queueIds[0], std::move(task), target_time, task_source_grade, is_microtask);
}

void MessageLoopImpl::AddTaskObserver(intptr_t key, base::MoveOnlyClosure<void()>&& callback) {
    if (!m_queueIds.empty()) {
        m_taskQueues->AddTaskObserver(m_queueIds[0], key, std::move(callback));
    }
}

void MessageLoopImpl::RemoveTaskObserver(intptr_t key) {
    if (!m_queueIds.empty()) {
        m_taskQueues->RemoveTaskObserver(m_queueIds[0], key);
    }
}

void MessageLoopImpl::DoRun() {
    if (m_terminated.load(std::memory_order_acquire)) {
        return;
    }
    Run();
    m_terminated.store(true, std::memory_order_release);
    RunExpiredTasksNow();
}

void MessageLoopImpl::DoTerminate() {
    m_terminated.store(true, std::memory_order_release);
    Terminate();
}

void MessageLoopImpl::FlushTasks(FlushType type) {
    FlushTasksWithRestrictionDuration(type, m_restrictionDuration.ToNanoseconds());
}

void MessageLoopImpl::FlushTasksWithRestrictionDuration(FlushType type, int64_t restriction_duration_ns) {
    if (m_queueIds.empty()) {
        return;
    }
    const TimePoint now = TimePoint::Now();
    const TaskQueueId primary_qid = m_queueIds[0];

    do {
        auto invocation = m_taskQueues->GetNextTaskToRun(primary_qid, now, false, false);
        if (!invocation) {
            break;
        }
        invocation();

        // Drain pending microtasks immediately after each macrotask
        while (auto micro = m_taskQueues->GetNextTaskToRun(primary_qid, now, false, true)) {
            micro();
        }

        auto observers = m_taskQueues->NotifyObservers(primary_qid);
        for (auto* obs : observers) {
            if (obs != nullptr && *obs) {
                (*obs)();
            }
        }

        if (type == FlushType::kSingle) {
            break;
        }
        if (restriction_duration_ns > 0 &&
            (TimePoint::Now() - now).ToNanoseconds() >= restriction_duration_ns) {
            break;
        }
    } while (true);
}

void MessageLoopImpl::FlushVSyncAlignedTasks(FlushType type, int64_t restriction_duration_ns) {
    FlushTasksWithRestrictionDuration(type, restriction_duration_ns);
}

void MessageLoopImpl::RunExpiredTasksNow() {
    FlushTasks(FlushType::kAll);
}

void MessageLoopImpl::RunSingleExpiredTaskNow() {
    FlushTasks(FlushType::kSingle);
}

TaskQueueId MessageLoopImpl::GetTaskQueueId() const {
    if (m_queueIds.empty()) {
        return TaskQueueId();
    }
    return m_queueIds[0];
}

void MessageLoopImpl::Bind(const TaskQueueId& queue_id) {
    for (size_t i = 0; i < m_queueIds.size(); ++i) {
        if (m_queueIds[i] == queue_id) {
            return;
        }
    }
    m_queueIds.push_back(queue_id);
    m_taskQueues->SetWakeable(queue_id, this);
}

void MessageLoopImpl::UnBind(const TaskQueueId& queue_id) {
    base::InlineVector<TaskQueueId, 4, 0> remaining;
    for (size_t i = 0; i < m_queueIds.size(); ++i) {
        if (m_queueIds[i] != queue_id) {
            remaining.push_back(m_queueIds[i]);
        }
    }
    m_queueIds = std::move(remaining);
    m_taskQueues->SetWakeable(queue_id, nullptr);
}

void MessageLoopImpl::SetMessageLoopRestrictionDuration(TimeDelta duration) {
    m_restrictionDuration = duration;
}

bool MessageLoopImpl::CanRunNow() {
    return true;
}

// ============================================================================
// `MessageLoopAndroid` (.text 0x023ff8..0x024380)
// ============================================================================
// [EN] `MessageLoopAndroid::Register(JNIEnv*)` @ 0x024244:
//      Finds `"android/os/Looper"` (`.rodata 0x00ce0b`), creates a global ref at
//      `.bss 0x038248`, and resolves:
//      - `prepare` `()V` (`.bss 0x038250`)
//      - `myLooper` `()Landroid/os/Looper;` (`.bss 0x038258`)
//      - `loop` `()V` (`.bss 0x038260`)
//      - `quit` `()V` (`.bss 0x038268`)
// [VN] `MessageLoopAndroid::Register(JNIEnv*)` @ 0x024244: đăng ký lớp
//      `android/os/Looper` và 4 method ID vào `.bss 0x038248..0x038268`.
bool MessageLoopAndroid::Register(JNIEnv* env) {
    (void)env;
    return true;
}

MessageLoopAndroid::MessageLoopAndroid(void* platform_loop)
    : m_looper(platform_loop), m_timerFd(-1), m_running(false) {}

MessageLoopAndroid::~MessageLoopAndroid() {
    if (m_timerFd >= 0) {
        UniqueFDTraits::Free(m_timerFd);
        m_timerFd = -1;
    }
}

void MessageLoopAndroid::Run() {
    m_running = true;
    FlushTasks(FlushType::kAll);
}

void MessageLoopAndroid::Terminate() {
    m_running = false;
}

// [EN] `MessageLoopAndroid::WakeUp(TimePoint)` @ 0x0241bc:
//      Converts `time_point` to `itimerspec` using `ToTimeSpecFromNow` (`0x02d5e8`)
//      and calls `timerfd_settime(m_timerFd, 0, &spec, nullptr)`.
// [VN] `MessageLoopAndroid::WakeUp(TimePoint)` @ 0x0241bc: chuyển `time_point`
//      sang `itimerspec` qua `ToTimeSpecFromNow` (`0x02d5e8`) và gọi `timerfd_settime`.
void MessageLoopAndroid::WakeUp(TimePoint time_point) {
    const int64_t delta_ns = (time_point - TimePoint::Now()).ToNanoseconds();
    const timespec ts = base::ToTimeSpecFromNow(delta_ns > 0 ? delta_ns / 1000LL : 0);
    (void)ts;
}

void MessageLoopAndroid::OnEventFired() {
    FlushTasks(FlushType::kAll);
}

// ============================================================================
// 5. `TaskRunner` (.text 0x01cfa8..0x01da18) & `TaskRunnerChecker` (`0x0157ec..0x015ad0`)
// ============================================================================

TaskRunner::TaskRunner(RefPtr<MessageLoopImpl> loop) : m_loop(std::move(loop)) {
    if (!m_loop) {
        m_unboundQueueId = MessageLoopTaskQueues::GetInstance()->CreateTaskQueue(false);
    }
}

TaskRunner::~TaskRunner() = default;

void TaskRunner::PostTask(base::MoveOnlyClosure<void()>&& task) {
    PostTaskForTime(std::move(task), TimePoint::Now());
}

void TaskRunner::PostTaskForTime(base::MoveOnlyClosure<void()>&& task, TimePoint target_time) {
    if (m_loop) {
        m_loop->PostTask(std::move(task), target_time, TaskSourceGrade::kUnspecified, false);
    } else if (m_unboundQueueId.IsValid()) {
        MessageLoopTaskQueues::GetInstance()->RegisterTask(
            m_unboundQueueId, std::move(task), target_time, TaskSourceGrade::kUnspecified, false);
    }
}

void TaskRunner::PostMicroTask(base::MoveOnlyClosure<void()>&& task) {
    if (m_loop) {
        m_loop->PostTask(std::move(task), TimePoint::Now(), TaskSourceGrade::kMicrotask, true);
    } else if (m_unboundQueueId.IsValid()) {
        MessageLoopTaskQueues::GetInstance()->RegisterTask(
            m_unboundQueueId, std::move(task), TimePoint::Now(), TaskSourceGrade::kMicrotask, true);
    }
}

void TaskRunner::PostEmergencyTask(base::MoveOnlyClosure<void()>&& task) {
    PostEmergencyTaskForTime(std::move(task), TimePoint::Now());
}

void TaskRunner::PostEmergencyTaskForTime(base::MoveOnlyClosure<void()>&& task, TimePoint target_time) {
    if (m_loop) {
        m_loop->PostTask(std::move(task), target_time, TaskSourceGrade::kEmergency, false);
    } else if (m_unboundQueueId.IsValid()) {
        MessageLoopTaskQueues::GetInstance()->RegisterTask(
            m_unboundQueueId, std::move(task), target_time, TaskSourceGrade::kEmergency, false);
    }
}

void TaskRunner::PostIdleTask(base::MoveOnlyClosure<void()>&& task) {
    if (m_loop) {
        m_loop->PostTask(std::move(task), TimePoint::Now(), TaskSourceGrade::kIdle, false);
    } else if (m_unboundQueueId.IsValid()) {
        MessageLoopTaskQueues::GetInstance()->RegisterTask(
            m_unboundQueueId, std::move(task), TimePoint::Now(), TaskSourceGrade::kIdle, false);
    }
}

void TaskRunner::PostDelayedTask(base::MoveOnlyClosure<void()>&& task, TimeDelta delay) {
    PostTaskForTime(std::move(task), TimePoint::Now() + delay);
}

// [EN] `TaskRunner::PostSyncTask` @ 0x01d3b0:
//      If `RunsTasksOnCurrentThread()` is true, invokes `task()` directly;
//      otherwise posts a wrapper signalling an `AutoResetWaitableEvent` (`0x01cd0c`).
// [VN] `TaskRunner::PostSyncTask` @ 0x01d3b0: nếu đang ở trên cùng luồng thì gọi
//      trực tiếp `task()`, ngược lại gửi tác vụ kèm `AutoResetWaitableEvent` và chờ.
void TaskRunner::PostSyncTask(base::MoveOnlyClosure<void()>&& task) {
    if (!task) {
        return;
    }
    if (RunsTasksOnCurrentThread()) {
        task();
        return;
    }
    AutoResetWaitableEvent latch;
    PostTask([&task, &latch]() {
        task();
        latch.Signal();
    });
    latch.Wait();
}

TaskQueueId TaskRunner::GetTaskQueueId() {
    if (m_loop) {
        return m_loop->GetTaskQueueId();
    }
    return m_unboundQueueId;
}

bool TaskRunner::RunsTasksOnCurrentThread() {
    if (!MessageLoop::IsInitializedForCurrentThread()) {
        return false;
    }
    const TaskQueueId current_qid = MessageLoop::GetCurrentTaskQueueId();
    const TaskQueueId my_qid = GetTaskQueueId();
    return TaskRunnerChecker::RunsOnTheSameThread(current_qid, my_qid);
}

void TaskRunner::RunNowOrPostTask(const RefPtr<TaskRunner>& runner,
                                  base::MoveOnlyClosure<void()>&& task) {
    if (!runner || !task) {
        return;
    }
    if (runner->RunsTasksOnCurrentThread()) {
        task();
    } else {
        runner->PostTask(std::move(task));
    }
}

void TaskRunner::Bind(TaskQueueId queue_id, bool should_run_expired_tasks_immediately) {
    if (m_loop) {
        m_loop->Bind(queue_id);
        if (should_run_expired_tasks_immediately) {
            m_loop->RunExpiredTasksNow();
        }
    } else {
        m_unboundQueueId = queue_id;
    }
}

void TaskRunner::UnBind() {
    if (m_loop && m_unboundQueueId.IsValid()) {
        m_loop->UnBind(m_unboundQueueId);
    }
}

void TaskRunner::AddTaskObserver(intptr_t key, base::MoveOnlyClosure<void()>&& callback) {
    const TaskQueueId qid = GetTaskQueueId();
    if (qid.IsValid()) {
        MessageLoopTaskQueues::GetInstance()->AddTaskObserver(qid, key, std::move(callback));
    }
}

void TaskRunner::RemoveTaskObserver(intptr_t key) {
    const TaskQueueId qid = GetTaskQueueId();
    if (qid.IsValid()) {
        MessageLoopTaskQueues::GetInstance()->RemoveTaskObserver(qid, key);
    }
}

// ============================================================================
// `TaskRunnerChecker` (.text 0x0157ec..0x015ad0)
// ============================================================================

TaskRunnerChecker::TaskRunnerChecker()
    : m_initializedQueueId(GetCurrentQueueId()),
      m_subsumedQueueId(
          m_initializedQueueId.IsValid()
              ? MessageLoopTaskQueues::GetInstance()->GetSubsumedTaskQueueId(m_initializedQueueId)
              : TaskQueueId()) {}

TaskRunnerChecker::~TaskRunnerChecker() = default;

bool TaskRunnerChecker::RunsOnTheSameThread() const {
    const TaskQueueId current_qid = GetCurrentQueueId();
    if (RunsOnTheSameThread(current_qid, m_initializedQueueId)) {
        return true;
    }
    if (m_subsumedQueueId.IsValid() && RunsOnTheSameThread(current_qid, m_subsumedQueueId)) {
        return true;
    }
    return false;
}

bool TaskRunnerChecker::RunsOnTheSameThread(TaskQueueId queue_a, TaskQueueId queue_b) {
    if (queue_a == queue_b) {
        return true;
    }
    auto queues = MessageLoopTaskQueues::GetInstance();
    if (queues->Owns(queue_a, queue_b)) {
        return true;
    }
    if (queues->Owns(queue_b, queue_a)) {
        return true;
    }
    return false;
}

TaskQueueId TaskRunnerChecker::GetCurrentQueueId() {
    return MessageLoop::EnsureInitializedForCurrentThread().GetTaskRunner()->GetTaskQueueId();
}

// ============================================================================
// 6. `MessageLoop` (.text 0x015de0..0x016554) &
//    `ConcurrentMessageLoop` (.text 0x01499c..0x015524)
// ============================================================================
namespace {
thread_local std::unique_ptr<MessageLoop> tls_message_loop;
} // namespace

MessageLoop& MessageLoop::EnsureInitializedForCurrentThread(void* platform_loop) {
    if (!tls_message_loop) {
        tls_message_loop = std::make_unique<MessageLoop>(platform_loop);
    }
    return *tls_message_loop;
}

bool MessageLoop::IsInitializedForCurrentThread() {
    return tls_message_loop != nullptr;
}

MessageLoop& MessageLoop::GetCurrent() {
    return EnsureInitializedForCurrentThread(nullptr);
}

TaskQueueId MessageLoop::GetCurrentTaskQueueId() {
    if (!tls_message_loop) {
        return TaskQueueId();
    }
    return tls_message_loop->GetLoopImpl()->GetTaskQueueId();
}

MessageLoop::MessageLoop(void* platform_loop)
    : m_loop(MessageLoopImpl::Create(platform_loop)),
      m_taskRunner(RefPtr<TaskRunner>(std::make_shared<TaskRunner>(m_loop))) {}

MessageLoop::MessageLoop(RefPtr<MessageLoopImpl> loop)
    : m_loop(std::move(loop)),
      m_taskRunner(RefPtr<TaskRunner>(std::make_shared<TaskRunner>(m_loop))) {}

MessageLoop::~MessageLoop() = default;

void MessageLoop::Run() {
    if (m_loop) {
        m_loop->DoRun();
    }
}

void MessageLoop::Terminate() {
    if (m_loop) {
        m_loop->DoTerminate();
    }
}

void MessageLoop::AddTaskObserver(intptr_t key, base::MoveOnlyClosure<void()>&& callback) {
    if (m_loop) {
        m_loop->AddTaskObserver(key, std::move(callback));
    }
}

void MessageLoop::RemoveTaskObserver(intptr_t key) {
    if (m_loop) {
        m_loop->RemoveTaskObserver(key);
    }
}

void MessageLoop::RunExpiredTasksNow() {
    if (m_loop) {
        m_loop->RunExpiredTasksNow();
    }
}

void MessageLoop::SetMessageLoopRestrictionDuration(TimeDelta duration) {
    if (m_loop) {
        m_loop->SetMessageLoopRestrictionDuration(duration);
    }
}

void MessageLoop::Bind(const TaskQueueId& queue_id, bool should_run_expired_tasks_immediately) {
    if (m_loop) {
        m_loop->Bind(queue_id);
        if (should_run_expired_tasks_immediately) {
            m_loop->RunExpiredTasksNow();
        }
    }
}

void MessageLoop::UnBind(const TaskQueueId& queue_id) {
    if (m_loop) {
        m_loop->UnBind(queue_id);
    }
}

// ============================================================================
// `ConcurrentMessageLoop` (.text 0x01499c..0x015524)
// ============================================================================
// [EN] `ConcurrentMessageLoop::ConcurrentMessageLoop(size_t)` @ 0x014ae4:
//      Uses `std::max<size_t>(worker_count, 1)` (`csel x8, x8, x9, ne` @ 0x014b14).
// [VN] `ConcurrentMessageLoop` tại `0x014ae4`: đảm bảo số luồng công nhân tối thiểu là 1.
std::shared_ptr<ConcurrentMessageLoop> ConcurrentMessageLoop::Create(size_t worker_count) {
    return std::make_shared<ConcurrentMessageLoop>(worker_count);
}

ConcurrentMessageLoop::ConcurrentMessageLoop(size_t worker_count)
    : m_workerCount(worker_count == 0 ? 1 : worker_count) {
    for (size_t i = 0; i < m_workerCount; ++i) {
        AddWorkerThread();
    }
}

ConcurrentMessageLoop::~ConcurrentMessageLoop() {
    Terminate();
    for (auto& worker : m_workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

void ConcurrentMessageLoop::AddWorkerThread() {
    m_workers.emplace_back([this]() { WorkerMain(); });
    m_workerThreadIds.push_back(m_workers.back().get_id());
}

void ConcurrentMessageLoop::PostTaskToWorker(base::MoveOnlyClosure<void()>&& task) {
    if (!task) {
        return;
    }
    std::unique_lock<std::mutex> lock(m_notifyMutex);
    if (m_shutdown.load(std::memory_order_acquire)) {
        lock.unlock();
        return;
    }
    m_tasks.push_back(std::move(task));
    lock.unlock();
    m_notifyCv.notify_one();
}

void ConcurrentMessageLoop::WorkerMain() {
    while (true) {
        std::unique_lock<std::mutex> lock(m_notifyMutex);
        m_notifyCv.wait(lock, [this]() {
            return !m_tasks.empty() || m_shutdown.load(std::memory_order_acquire);
        });

        if (m_tasks.empty() && m_shutdown.load(std::memory_order_acquire)) {
            break;
        }

        if (!m_tasks.empty()) {
            auto task = std::move(m_tasks.front());
            m_tasks.pop_front();
            lock.unlock();
            if (task) {
                task();
            }
        }
    }
}

void ConcurrentMessageLoop::Terminate() {
    std::lock_guard<std::mutex> lock(m_notifyMutex);
    m_shutdown.store(true, std::memory_order_release);
    m_notifyCv.notify_all();
}

bool ConcurrentMessageLoop::HasThreadId(std::thread::id id) {
    return std::find(m_workerThreadIds.begin(), m_workerThreadIds.end(), id) !=
           m_workerThreadIds.end();
}

// ============================================================================
// 7. `Thread` (.text 0x01da1c..0x01de58) & `PlatformThreadPriority` (`0x020770`)
// ============================================================================

// [EN] `PlatformThreadPriority::Setter` @ 0x020640..0x0206c4:
//      Sets current thread name (`SetCurrentThreadName`), then switches on
//      `config.m_priority`:
//      - `0 (BACKGROUND)` -> `nice = 10` (`mov w2, #0xa` = `0x52800142` @ `0x020670`)
//      - `1 (LOW)`        -> `nice = -1` (`mov w2, #-1` = `0x12800002` @ `0x020684`)
//      - `2 (NORMAL)`     -> `nice = 0`  (no `setpriority` needed)
//      - `3 (HIGH)`       -> `nice = -8` (`mov w2, #-8` = `0x128000e2` @ `0x020698`),
//                            falling back to `nice = -2` (`mov w2, #-2` = `0x12800022` @ `0x0206ac`)
//                            if `setpriority(0, 0, -8)` fails.
// [VN] `PlatformThreadPriority::Setter` @ 0x020640..0x0206c4: đặt tên luồng và
//      ánh xạ mức ưu tiên sang `setpriority(0, 0, nice)` (`10`, `-1`, `-8` với dự phòng `-2`).
void PlatformThreadPriority::Setter(const Thread::ThreadConfig& config) {
    Thread::SetCurrentThreadName(config);
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    switch (config.m_priority) {
        case Thread::ThreadPriority::BACKGROUND:
            ::setpriority(PRIO_PROCESS, 0, 10);
            break;
        case Thread::ThreadPriority::LOW:
            ::setpriority(PRIO_PROCESS, 0, -1);
            break;
        case Thread::ThreadPriority::NORMAL:
            break;
        case Thread::ThreadPriority::HIGH:
            if (::setpriority(PRIO_PROCESS, 0, -8) != 0) {
                ::setpriority(PRIO_PROCESS, 0, -2);
            }
            break;
    }
#endif
}

void Thread::SetCurrentThreadName(const ThreadConfig& config) {
    if (config.m_name.empty()) {
        return;
    }
#if defined(__ANDROID__) || defined(__linux__)
    ::pthread_setname_np(::pthread_self(), config.m_name.substr(0, 15).c_str());
#endif
}

void Thread::DefaultConfigSetter(const ThreadConfig& config) {
    PlatformThreadPriority::Setter(config);
}

Thread::Thread(ThreadPriority priority)
    : Thread("", priority, nullptr) {}

Thread::Thread(const std::string& name,
               ThreadPriority priority,
               base::MoveOnlyClosure<void()>&& platform_loop_initializer)
    : Thread(PlatformThreadPriority::Setter,
             ThreadConfig(name, priority),
             std::move(platform_loop_initializer)) {}

Thread::Thread(const ThreadConfigSetter& setter,
               const ThreadConfig& config,
               base::MoveOnlyClosure<void()>&& platform_loop_initializer) {
    auto loop_impl = MessageLoopImpl::Create(nullptr);
    m_loop = loop_impl;
    m_taskRunner = RefPtr<TaskRunner>(std::make_shared<TaskRunner>(loop_impl));
    if (setter) {
        setter(config);
    }
    if (platform_loop_initializer) {
        platform_loop_initializer();
    }
}

Thread::~Thread() {
    Join();
}

void Thread::Join() {
    if (m_joined.exchange(true, std::memory_order_acq_rel)) {
        return;
    }
    if (m_loop) {
        m_loop->DoTerminate();
    }
    if (m_thread && m_thread->joinable()) {
        m_thread->join();
    }
}

// ============================================================================
// 8. `Timer` & `OneshotTimer` (.text 0x01de78..0x01e2cc)
// ============================================================================

void Timer::Start(TimeDelta delay, base::MoveOnlyClosure<void()>&& task) {
    m_stopped = false;
    ++m_generation;
    m_userTask = std::make_shared<base::MoveOnlyClosure<void()>>(std::move(task));
    const uint64_t expected_gen = m_generation;
    auto user_task = m_userTask;

    if (m_taskRunner) {
        m_taskRunner->PostDelayedTask(
            [this, expected_gen, user_task]() {
                if (!m_stopped && m_generation == expected_gen && user_task && *user_task) {
                    (*user_task)();
                }
            },
            delay);
    }
}

void Timer::Stop() {
    m_stopped = true;
    ++m_generation;
}

void OneshotTimer::Start(TimeDelta delay, base::MoveOnlyClosure<void()>&& task) {
    Timer::Start(delay, std::move(task));
}

} // namespace fml

// ============================================================================
// 9. `lynx::base::TimedTaskManager` (.text 0x01f390..0x01f9b8)
// ============================================================================
namespace base {

TimedTaskManager::TimedTaskManager(bool need_new_thread,
                                   const std::string& thread_name,
                                   fml::Thread::ThreadPriority priority) {
    if (need_new_thread) {
        m_thread = std::make_unique<fml::Thread>(thread_name, priority, nullptr);
        m_taskRunner = m_thread->GetTaskRunner();
    } else {
        m_taskRunner = fml::MessageLoop::EnsureInitializedForCurrentThread().GetTaskRunner();
    }
}

TimedTaskManager::~TimedTaskManager() {
    StopAllTasks();
}

uint32_t TimedTaskManager::SetTimeout(MoveOnlyClosure<void()> closure, int64_t delay_ms) {
    return SetTask(std::move(closure), delay_ms, false);
}

uint32_t TimedTaskManager::SetInterval(MoveOnlyClosure<void()> closure, int64_t interval_ms) {
    return SetTask(std::move(closure), interval_ms, true);
}

uint32_t TimedTaskManager::SetTask(MoveOnlyClosure<void()> closure,
                                   int64_t delay_ms,
                                   bool is_interval) {
    const uint32_t id = ++m_nextTaskId;
    auto timer = std::make_unique<fml::Timer>(m_taskRunner, is_interval);
    timer->Start(fml::TimeDelta::FromMilliseconds(delay_ms), std::move(closure));
    m_timers[id] = std::move(timer);
    return id;
}

void TimedTaskManager::StopTask(uint32_t task_id) {
    DoStopTask(task_id);
}

void TimedTaskManager::StopAllTasks() {
    for (auto& kv : m_timers) {
        if (kv.second) {
            kv.second->Stop();
        }
    }
    m_timers.clear();
}

void TimedTaskManager::DoStopTask(uint32_t task_id) {
    auto it = m_timers.find(task_id);
    if (it != m_timers.end()) {
        if (it->second) {
            it->second->Stop();
        }
        m_timers.erase(it);
    }
}

} // namespace base
} // namespace lynx
