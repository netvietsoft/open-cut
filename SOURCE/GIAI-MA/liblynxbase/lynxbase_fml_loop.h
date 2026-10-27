// ============================================================================
// File: lynxbase_fml_loop.h
// Target: liblynxbase.so (232,080 bytes, SHA-256: 6f73cb643285f2b6f59960dde9c053141e6f546429faaf7fa66bbae9e1a0d61d)
// Subsystem: Lynx FML MessageLoop, TaskRunner, TaskQueues, Synchronization
//            Primitives, Thread, Timer & TimedTaskManager
//            (.text 0x01499c..0x020838, 0x023ff8..0x024380)
// Task ID: TASK-123-RECONSTRUCTION-LIBLYNXBASE (TASK_SO_121_liblynxbase)
// ============================================================================
// [EN] Clean-room C++17 header declaring the Lynx FML (`lynx::fml`) event loop,
//      multi-grade task queue dispatcher (`MessageLoopTaskQueues`), Android
//      ALooper/timerfd integration (`MessageLoopAndroid`), thread pool
//      (`ConcurrentMessageLoop`), synchronization primitives (`CountDownLatch`,
//      `SyncSwitch`, `AutoResetWaitableEvent`, `SharedMutex`), and
//      `lynx::base::TimedTaskManager`.
// [VN] File header C++17 tái tạo sạch vòng lặp sự kiện Lynx FML (`lynx::fml`),
//      bộ điều phối hàng đợi tác vụ đa mức ưu tiên (`MessageLoopTaskQueues`),
//      tích hợp ALooper/timerfd Android (`MessageLoopAndroid`), hồ luồng
//      (`ConcurrentMessageLoop`), nguyên hàm đồng bộ (`CountDownLatch`,
//      `SyncSwitch`, `AutoResetWaitableEvent`, `SharedMutex`), và
//      `lynx::base::TimedTaskManager`.
// ============================================================================

#ifndef LYNXBASE_FML_LOOP_H_
#define LYNXBASE_FML_LOOP_H_

#include "lynxbase_types.h"

#include <condition_variable>
#include <deque>
#include <map>
#include <shared_mutex>
#include <thread>

namespace lynx {
namespace fml {

class MessageLoopImpl;
class TaskRunner;

// ============================================================================
// 1. Synchronization Primitives (`CountDownLatch`, `SyncSwitch`,
//    `AutoResetWaitableEvent`, `SharedMutex`, `UniqueFD`, `UniqueDir`)
// ============================================================================

// [EN] `lynx::fml::CountDownLatch` (.text 0x01c580..0x01c698).
// [VN] Chốt đếm ngược đồng bộ luồng `lynx::fml::CountDownLatch` (.text 0x01c580..0x01c698).
class CountDownLatch {
public:
    explicit CountDownLatch(uint32_t count);
    ~CountDownLatch();

    void Wait();
    void CountDown();

private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    std::atomic<uint32_t> m_count{0};
};

// [EN] `lynx::fml::SyncSwitch` (.text 0x01c69c..0x01c858).
//      Uses `SharedMutex` so `Execute` acquires a shared read lock while
//      `SetSwitch` acquires an exclusive write lock.
// [VN] Công tắc đồng bộ đọc-nhiều/ghi-độc-quyền `lynx::fml::SyncSwitch` (.text 0x01c69c..0x01c858).
class SyncSwitch {
public:
    struct Handlers {
        Handlers& SetIfTrue(const std::function<void()>& handler);
        Handlers& SetIfFalse(const std::function<void()>& handler);

        std::function<void()> true_handler = []() {};
        std::function<void()> false_handler = []() {};
    };

    explicit SyncSwitch(bool value = false);
    ~SyncSwitch() = default;

    void Execute(const Handlers& handlers) const;
    void SetSwitch(bool value);

private:
    mutable std::shared_mutex m_mutex;
    bool m_value{false};
};

// [EN] `lynx::fml::AutoResetWaitableEvent` (.text 0x01cc64..0x01cf50).
// [VN] Sự kiện chờ tự động đặt lại `lynx::fml::AutoResetWaitableEvent` (.text 0x01cc64..0x01cf50).
class AutoResetWaitableEvent {
public:
    AutoResetWaitableEvent() = default;
    ~AutoResetWaitableEvent() = default;

    void Signal();
    void Reset();
    void Wait();
    bool WaitWithTimeout(TimeDelta timeout);
    bool IsSignaledForTestOnly();

private:
    std::mutex m_mutex;
    std::condition_variable m_cv;
    bool m_signaled{false};
};

// [EN] `lynx::fml::SharedMutex` & `SharedMutexPosix` (.text 0x01f9dc..0x01fa58).
// [VN] Mutex chia sẻ đa luồng `lynx::fml::SharedMutex` (.text 0x01f9dc..0x01fa58).
class SharedMutex {
public:
    static SharedMutex* Create();
    virtual ~SharedMutex() = default;

    virtual void Lock() = 0;
    virtual void LockShared() = 0;
    virtual void Unlock() = 0;
    virtual void UnlockShared() = 0;
};

class SharedMutexPosix final : public SharedMutex {
public:
    SharedMutexPosix();
    ~SharedMutexPosix() override = default;

    void Lock() override;
    void LockShared() override;
    void Unlock() override;
    void UnlockShared() override;

private:
    std::shared_mutex m_rwlock;
};

// [EN] `lynx::fml::UniqueFDTraits::Free(int)` (.text 0x01e2d0 -> `close(fd)`).
// [VN] Giải phóng file descriptor (`0x01e2d0` -> `close(fd)`).
struct UniqueFDTraits {
    static int InvalidValue() noexcept { return -1; }
    static bool IsValid(int value) noexcept { return value >= 0; }
    static void Free(int fd);
};

namespace internal {
// [EN] `lynx::fml::internal::UniqueDirTraits::Free(DIR*)` (.text 0x01e2d4 -> `closedir`).
// [VN] Đóng con trỏ thư mục `DIR*` (`0x01e2d4` -> `closedir`).
struct UniqueDirTraits {
    static DIR* InvalidValue() noexcept { return nullptr; }
    static bool IsValid(DIR* value) noexcept { return value != nullptr; }
    static void Free(DIR* dir);
};
} // namespace internal

// ============================================================================
// 2. `MessageLoopTaskQueues` (.text 0x017d24..0x019ab0)
// ============================================================================
struct DelayedTask {
    size_t order{0};
    base::MoveOnlyClosure<void()> task;
    TimePoint target_time;
    TaskSourceGrade task_source_grade{TaskSourceGrade::kUnspecified};

    bool operator>(const DelayedTask& other) const noexcept {
        if (target_time == other.target_time) {
            return order > other.order;
        }
        return target_time > other.target_time;
    }
};

class MessageLoopTaskQueues {
public:
    // [EN] Singleton accessor (`0x017d24`) guarded by `std::once_flag` at `.bss 0x038218`.
    // [VN] Truy xuất singleton (`0x017d24`) bảo vệ bởi `std::once_flag` tại `.bss 0x038218`.
    static RefPtr<MessageLoopTaskQueues> GetInstance();

    MessageLoopTaskQueues();
    ~MessageLoopTaskQueues();

    TaskQueueId CreateTaskQueue(bool is_vsync_aligned = false);
    void Dispose(TaskQueueId queue_id);
    void DisposeTasks(TaskQueueId queue_id);

    void RegisterTask(TaskQueueId queue_id,
                      base::MoveOnlyClosure<void()>&& task,
                      TimePoint target_time,
                      TaskSourceGrade task_source_grade = TaskSourceGrade::kUnspecified,
                      bool is_microtask = false);

    bool HasPendingTasks(TaskQueueId queue_id) const;
    bool HasPendingMicroTasks(TaskQueueId queue_id) const;

    base::MoveOnlyClosure<void()> GetNextTaskToRun(
        TaskQueueId queue_id,
        TimePoint from_time,
        bool is_vsync_aligned = false,
        bool only_microtasks = false);

    size_t GetNumPendingTasks(TaskQueueId queue_id) const;

    void AddTaskObserver(TaskQueueId queue_id, intptr_t key, base::MoveOnlyClosure<void()>&& callback);
    void RemoveTaskObserver(TaskQueueId queue_id, intptr_t key);
    std::vector<base::MoveOnlyClosure<void()>*> NotifyObservers(TaskQueueId queue_id);

    void SetWakeable(TaskQueueId queue_id, Wakeable* wakeable);

    // [EN] Queue merging (`Merge` @ 0x0194dc, `Unmerge` @ 0x019718, `Owns` @ 0x019820).
    // [VN] Hợp nhất và tách hàng đợi tác vụ (`Merge` @ 0x0194dc, `Unmerge` @ 0x019718).
    bool Merge(TaskQueueId owner, TaskQueueId subsumed);
    bool Unmerge(TaskQueueId owner, TaskQueueId subsumed);
    bool Owns(TaskQueueId owner, TaskQueueId subsumed) const;
    bool IsSubsumed(TaskQueueId queue_id) const;
    TaskQueueId GetSubsumedTaskQueueId(TaskQueueId owner) const;

    void PauseTasks(TaskQueueId queue_id);
    void ResumeTasks(TaskQueueId queue_id);

private:
    struct QueueEntry {
        TaskQueueId queue_id;
        bool is_vsync_aligned{false};
        bool is_paused{false};
        Wakeable* wakeable{nullptr};
        TaskQueueId owner_of{TaskQueueId::kUnmerged};
        TaskQueueId subsumed_by{TaskQueueId::kUnmerged};
        std::deque<DelayedTask> delayed_tasks;
        std::deque<DelayedTask> microtasks;
        std::map<intptr_t, base::MoveOnlyClosure<void()>> task_observers;
    };

    void WakeUpUnlocked(TaskQueueId queue_id, TimePoint time) const;
    bool HasPendingTasksUnlocked(TaskQueueId queue_id) const;
    bool HasPendingMicroTasksUnlocked(TaskQueueId queue_id) const;
    TimePoint GetNextWakeTimeUnlocked(TaskQueueId queue_id, bool is_vsync_aligned) const;

    mutable std::mutex m_queueMutex;
    size_t m_taskQueueIdCounter{0};
    std::atomic<size_t> m_orderCounter{0};
    std::map<size_t, std::unique_ptr<QueueEntry>> m_queues;
};

// ============================================================================
// 3. `MessageLoopImpl` (.text 0x016558..0x0172dc, vtable @ 0x034190) &
//    `MessageLoopAndroid` (.text 0x023ff8..0x024380, vtable @ 0x034500)
// ============================================================================
class MessageLoopImpl : public Wakeable {
public:
    static RefPtr<MessageLoopImpl> Create(void* platform_loop = nullptr);

    MessageLoopImpl();
    ~MessageLoopImpl() override;

    virtual void Run() = 0;
    virtual void Terminate() = 0;

    void PostTask(base::MoveOnlyClosure<void()>&& task,
                  TimePoint target_time,
                  TaskSourceGrade task_source_grade = TaskSourceGrade::kUnspecified,
                  bool is_microtask = false);

    void AddTaskObserver(intptr_t key, base::MoveOnlyClosure<void()>&& callback);
    void RemoveTaskObserver(intptr_t key);

    void DoRun();
    void DoTerminate();

    void FlushTasks(FlushType type);
    void FlushTasksWithRestrictionDuration(FlushType type, int64_t restriction_duration_ns);
    void FlushVSyncAlignedTasks(FlushType type, int64_t restriction_duration_ns);

    void RunExpiredTasksNow();
    void RunSingleExpiredTaskNow();

    TaskQueueId GetTaskQueueId() const;
    const base::InlineVector<TaskQueueId, 4, 0>& GetTaskQueueIds() const { return m_queueIds; }

    virtual void Bind(const TaskQueueId& queue_id);
    virtual void UnBind(const TaskQueueId& queue_id);
    virtual void SetMessageLoopRestrictionDuration(TimeDelta duration);
    virtual bool CanRunNow();

protected:
    RefPtr<MessageLoopTaskQueues> m_taskQueues;
    base::InlineVector<TaskQueueId, 4, 0> m_queueIds;
    std::atomic<bool> m_terminated{false};
    TimeDelta m_restrictionDuration{TimeDelta::Zero()};
};

// [EN] Android platform `MessageLoopImpl` backed by `ALooper` + `timerfd_create`
//      (`CLOCK_MONOTONIC = 1`, flags `TFD_NONBLOCK | TFD_CLOEXEC = 0x80800` @ `0x024024`).
// [VN] Lớp `MessageLoopImpl` trên nền tảng Android dùng `ALooper` + `timerfd_create`
//      (`CLOCK_MONOTONIC = 1`, cờ `0x80800` tại `0x024024`).
class MessageLoopAndroid final : public MessageLoopImpl {
public:
    // [EN] `MessageLoopAndroid::Register(JNIEnv*)` @ 0x024244: caches
    //      `android/os/Looper` and `prepare`/`myLooper`/`loop`/`quit` at `.bss 0x038248..0x038268`.
    // [VN] `MessageLoopAndroid::Register(JNIEnv*)` @ 0x024244: lưu đệm lớp
    //      `android/os/Looper` và 4 method ID tại `.bss 0x038248..0x038268`.
    static bool Register(JNIEnv* env);

    explicit MessageLoopAndroid(void* platform_loop = nullptr);
    ~MessageLoopAndroid() override;

    void Run() override;
    void Terminate() override;
    void WakeUp(TimePoint time_point) override;

    void OnEventFired();

private:
    void* m_looper{nullptr};
    int m_timerFd{-1};
    bool m_running{false};
};

// ============================================================================
// 4. `TaskRunner` (.text 0x01cfa8..0x01da18, vtable @ 0x034260) &
//    `TaskRunnerChecker` (.text 0x0157ec..0x015ad0)
// ============================================================================
class TaskRunner {
public:
    explicit TaskRunner(RefPtr<MessageLoopImpl> loop);
    virtual ~TaskRunner();

    virtual void PostTask(base::MoveOnlyClosure<void()>&& task);
    virtual void PostTaskForTime(base::MoveOnlyClosure<void()>&& task, TimePoint target_time);
    virtual void PostMicroTask(base::MoveOnlyClosure<void()>&& task);
    virtual void PostEmergencyTask(base::MoveOnlyClosure<void()>&& task);
    virtual void PostEmergencyTaskForTime(base::MoveOnlyClosure<void()>&& task, TimePoint target_time);
    virtual void PostIdleTask(base::MoveOnlyClosure<void()>&& task);
    virtual void PostDelayedTask(base::MoveOnlyClosure<void()>&& task, TimeDelta delay);
    virtual void PostSyncTask(base::MoveOnlyClosure<void()>&& task);

    virtual TaskQueueId GetTaskQueueId();
    virtual bool RunsTasksOnCurrentThread();

    void RunNowOrPostTask(const RefPtr<TaskRunner>& runner, base::MoveOnlyClosure<void()>&& task);

    void Bind(TaskQueueId queue_id, bool should_run_expired_tasks_immediately = false);
    void UnBind();

    const RefPtr<MessageLoopImpl>& GetLoop() const { return m_loop; }

    void AddTaskObserver(intptr_t key, base::MoveOnlyClosure<void()>&& callback);
    void RemoveTaskObserver(intptr_t key);

    void SetDelegate(TaskRunnerDelegate* delegate) { m_delegate = delegate; }

protected:
    RefPtr<MessageLoopImpl> m_loop;
    TaskQueueId m_unboundQueueId;
    TaskRunnerDelegate* m_delegate{nullptr};
};

class TaskRunnerChecker {
public:
    TaskRunnerChecker();
    ~TaskRunnerChecker();

    bool RunsOnTheSameThread() const;
    TaskQueueId GetTaskQueueId() const { return m_initializedQueueId; }

    static bool RunsOnTheSameThread(TaskQueueId queue_a, TaskQueueId queue_b);
    static TaskQueueId GetCurrentQueueId();

private:
    TaskQueueId m_initializedQueueId;
    TaskQueueId m_subsumedQueueId;
};

// ============================================================================
// 5. `MessageLoop` (.text 0x015de0..0x016554) &
//    `ConcurrentMessageLoop` (.text 0x01499c..0x015524)
// ============================================================================
class MessageLoop {
public:
    static MessageLoop& EnsureInitializedForCurrentThread(void* platform_loop = nullptr);
    static bool IsInitializedForCurrentThread();
    static MessageLoop& GetCurrent();
    static TaskQueueId GetCurrentTaskQueueId();

    explicit MessageLoop(void* platform_loop = nullptr);
    explicit MessageLoop(RefPtr<MessageLoopImpl> loop);
    ~MessageLoop();

    void Run();
    void Terminate();

    const RefPtr<TaskRunner>& GetTaskRunner() const { return m_taskRunner; }
    const RefPtr<MessageLoopImpl>& GetLoopImpl() const { return m_loop; }

    void AddTaskObserver(intptr_t key, base::MoveOnlyClosure<void()>&& callback);
    void RemoveTaskObserver(intptr_t key);
    void RunExpiredTasksNow();
    void SetMessageLoopRestrictionDuration(TimeDelta duration);

    void Bind(const TaskQueueId& queue_id, bool should_run_expired_tasks_immediately = false);
    void UnBind(const TaskQueueId& queue_id);

private:
    RefPtr<MessageLoopImpl> m_loop;
    RefPtr<TaskRunner> m_taskRunner;
};

class ConcurrentMessageLoop {
public:
    static std::shared_ptr<ConcurrentMessageLoop> Create(size_t worker_count = 0);

    explicit ConcurrentMessageLoop(size_t worker_count = 0);
    ~ConcurrentMessageLoop();

    size_t GetWorkerCount() const { return m_workerCount; }
    void PostTaskToWorker(base::MoveOnlyClosure<void()>&& task);
    void Terminate();
    bool HasThreadId(std::thread::id id);

private:
    void WorkerMain();
    void AddWorkerThread();

    size_t m_workerCount{1};
    std::mutex m_notifyMutex;
    std::condition_variable m_notifyCv;
    std::deque<base::MoveOnlyClosure<void()>> m_tasks;
    std::vector<std::thread> m_workers;
    std::vector<std::thread::id> m_workerThreadIds;
    std::atomic<bool> m_shutdown{false};
};

// ============================================================================
// 6. `Thread` (.text 0x01da1c..0x01de58) & `PlatformThreadPriority` (`0x020770`)
// ============================================================================
class Thread {
public:
    enum class ThreadPriority : int32_t {
        BACKGROUND = 0,
        LOW = 1,
        NORMAL = 2,
        HIGH = 3,
    };

    struct ThreadConfig {
        ThreadConfig() = default;
        explicit ThreadConfig(const std::string& name, ThreadPriority priority = ThreadPriority::NORMAL)
            : m_name(name), m_priority(priority) {}

        std::string m_name;
        ThreadPriority m_priority{ThreadPriority::NORMAL};
    };

    using ThreadConfigSetter = std::function<void(const ThreadConfig&)>;

    explicit Thread(ThreadPriority priority = ThreadPriority::NORMAL);
    explicit Thread(const std::string& name,
                    ThreadPriority priority = ThreadPriority::NORMAL,
                    base::MoveOnlyClosure<void()>&& platform_loop_Initializer = nullptr);
    explicit Thread(const ThreadConfigSetter& setter,
                    const ThreadConfig& config = ThreadConfig(),
                    base::MoveOnlyClosure<void()>&& platform_loop_Initializer = nullptr);
    ~Thread();

    const RefPtr<TaskRunner>& GetTaskRunner() const { return m_taskRunner; }
    const RefPtr<MessageLoopImpl>& GetLoop() const { return m_loop; }
    void Join();

    static void SetCurrentThreadName(const ThreadConfig& config);
    static void DefaultConfigSetter(const ThreadConfig& config);

private:
    std::unique_ptr<std::thread> m_thread;
    RefPtr<TaskRunner> m_taskRunner;
    RefPtr<MessageLoopImpl> m_loop;
    std::atomic<bool> m_joined{false};
};

class PlatformThreadPriority {
public:
    // [EN] `PlatformThreadPriority::Setter` @ 0x020770: maps `ThreadPriority`
    //      to `setpriority(PRIO_PROCESS = 0, 0, nice)` (`0 -> 10`, `1 -> 5`,
    //      `2 -> 0`, `3 -> -2` (`0x12800022`)).
    // [VN] `PlatformThreadPriority::Setter` @ 0x020770: ánh xạ `ThreadPriority`
    //      sang `setpriority(PRIO_PROCESS = 0, 0, nice)`.
    static void Setter(const Thread::ThreadConfig& config);
};

// ============================================================================
// 7. `Timer` & `OneshotTimer` (.text 0x01de78..0x01e2cc)
// ============================================================================
class Timer {
public:
    explicit Timer(const RefPtr<TaskRunner>& task_runner, bool is_periodic = false)
        : m_taskRunner(task_runner), m_isPeriodic(is_periodic) {}
    virtual ~Timer() { Stop(); }

    void Start(TimeDelta delay, base::MoveOnlyClosure<void()>&& task);
    void Stop();
    bool IsStopped() const noexcept { return m_stopped; }

protected:
    RefPtr<TaskRunner> m_taskRunner;
    bool m_isPeriodic{false};
    bool m_stopped{true};
    uint64_t m_generation{0};
    std::shared_ptr<base::MoveOnlyClosure<void()>> m_userTask;
};

class OneshotTimer final : public Timer {
public:
    explicit OneshotTimer(const RefPtr<TaskRunner>& task_runner)
        : Timer(task_runner, false) {}

    void Start(TimeDelta delay, base::MoveOnlyClosure<void()>&& task);
};

} // namespace fml

// ============================================================================
// 8. `lynx::base::TimedTaskManager` (.text 0x01f390..0x01f9b8)
// ============================================================================
namespace base {

class TimedTaskManager {
public:
    explicit TimedTaskManager(
        bool need_new_thread = true,
        const std::string& thread_name = "lynx_timed_task_thread",
        fml::Thread::ThreadPriority priority = fml::Thread::ThreadPriority::NORMAL);
    ~TimedTaskManager();

    uint32_t SetTimeout(MoveOnlyClosure<void()> closure, int64_t delay_ms);
    uint32_t SetInterval(MoveOnlyClosure<void()> closure, int64_t interval_ms);

    void StopTask(uint32_t task_id);
    void StopAllTasks();

private:
    uint32_t SetTask(MoveOnlyClosure<void()> closure, int64_t delay_ms, bool is_interval);
    void DoStopTask(uint32_t task_id);

    std::unique_ptr<fml::Thread> m_thread;
    fml::RefPtr<fml::TaskRunner> m_taskRunner;
    uint32_t m_nextTaskId{0};
    std::unordered_map<uint32_t, std::unique_ptr<fml::Timer>> m_timers;
};

} // namespace base
} // namespace lynx

#endif // LYNXBASE_FML_LOOP_H_
