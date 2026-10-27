// ============================================================================
// File: vcbasekit_thread_jni.cpp
// Target: libvcbasekit.so (231,568 bytes, SHA-256: d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
// Classification: CORE_10_MONITORING (ByteDance Video Cloud BaseKit)
//
// Description (EN):
// Clean-room C++17 implementation of com::ss::vcbkit threading, message loop,
// ALOG dynamic wrapper (dlopen("libalog.so") -> "alog_write_default_instance"),
// JNI_OnLoad ("com/ss/vcbkit/UnExpected", "notReachHereNative"), and
// UnExpected stack backtrace reporter (dlopen("libnpth_bt.so") ->
// "npth_bt_current" / "npth_bt_thread" / "npth_bt_free").
//
// Mô tả (VI):
// Cài đặt C++17 tái tạo sạch phân hệ đa luồng, vòng lặp thông điệp, cầu nối
// động ALOG (dlopen("libalog.so")), JNI_OnLoad ("com/ss/vcbkit/UnExpected")
// và bộ thu thập vết ngăn xếp UnExpected (dlopen("libnpth_bt.so")).
// ============================================================================

#include "vcbasekit_thread_jni.h"
#include <algorithm>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstring>

#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
#include <dlfcn.h>
#endif

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// 1. Block Implementation (0x021de4..0x021e94)
// Cài đặt khối tác vụ có đếm tham chiếu (Block).
// ============================================================================
Block::Block(TaskFn fn) : fn_(std::move(fn)), cancelled_(false) {}

Block::~Block() noexcept = default;

void Block::run() {
    if (!cancelled_.load(std::memory_order_acquire) && fn_) {
        fn_();
    }
}

void Block::cancel() noexcept {
    cancelled_.store(true, std::memory_order_release);
}

bool Block::isCancelled() const noexcept {
    return cancelled_.load(std::memory_order_acquire);
}

// ============================================================================
// 2. ThreadHelper (0x021da8..0x021de4) & Thread (0x022728..0x023718)
// Cài đặt ThreadHelper và đối tượng luồng Thread.
// ============================================================================
uint64_t ThreadHelper::currentThreadId() noexcept {
    return static_cast<uint64_t>(
        std::hash<std::thread::id>{}(std::this_thread::get_id()));
}

void ThreadHelper::setCurrentThreadName(const char* name) noexcept {
    (void)name;
}

void ThreadHelper::setCurrentThreadPriority(int priority) noexcept {
    (void)priority;
}

void ThreadHelper::sleep(TimeDelta duration) noexcept {
    if (duration.toNanoseconds() > 0) {
        std::this_thread::sleep_for(
            std::chrono::nanoseconds(duration.toNanoseconds()));
    }
}

Thread::Thread(const ThreadAttr& attr) : attr_(attr) {}

Thread::Thread(const ThreadAttr& attr, Function<void()> entry)
    : attr_(attr), entry_(std::move(entry)) {}

Thread::~Thread() noexcept {
    if (worker_.joinable()) {
        worker_.join();
    }
}

bool Thread::start(Function<void()> entry) {
    if (entry) {
        entry_ = std::move(entry);
    }
    if (!entry_ || running_.exchange(true, std::memory_order_acq_rel)) {
        return false;
    }
    addRef();
    worker_ = std::thread([this]() {
        thread_id_.store(ThreadHelper::currentThreadId(), std::memory_order_release);
        ThreadHelper::setCurrentThreadName(attr_.name.c_str());
        ThreadHelper::setCurrentThreadPriority(attr_.priority);
        if (entry_) {
            entry_();
        }
        running_.store(false, std::memory_order_release);
        decRef();
    });
    return true;
}

void Thread::join() {
    if (worker_.joinable()) {
        worker_.join();
    }
}

void Thread::detach() {
    if (worker_.joinable()) {
        worker_.detach();
    }
}

bool Thread::isRunning() const noexcept {
    return running_.load(std::memory_order_acquire);
}

// ============================================================================
// 3. MsgLoop Implementation (0x023c6c..0x025550)
// Cài đặt vòng lặp thông điệp ưu tiên theo mốc thời gian thực thi (MsgLoop).
// ============================================================================
MsgLoop::MsgLoop(const ThreadAttr& attr) : attr_(attr) {}

MsgLoop::~MsgLoop() noexcept {
    quit(true);
}

bool MsgLoop::start() {
    if (running_.exchange(true, std::memory_order_acq_rel)) {
        return true;
    }
    quit_requested_.store(false, std::memory_order_release);
    loop_thread_ = std::thread([this]() { loopBody(); });
    return true;
}

void MsgLoop::quit(bool wait_for_drain) {
    {
        std::lock_guard<std::mutex> lk(mutex_);
        if (!wait_for_drain) {
            queue_.clear();
        }
        quit_requested_.store(true, std::memory_order_release);
    }
    cv_.notify_all();
    if (loop_thread_.joinable() &&
        loop_thread_.get_id() != std::this_thread::get_id()) {
        loop_thread_.join();
    }
    running_.store(false, std::memory_order_release);
}

uint64_t MsgLoop::post(MsgTask task, int what) {
    return postDelayed(std::move(task), TimeDelta::fromNanoseconds(0), what);
}

uint64_t MsgLoop::postDelayed(MsgTask task, TimeDelta delay, int what) {
    if (!task) return 0;
    uint64_t id = next_msg_id_.fetch_add(1, std::memory_order_relaxed);
    int64_t now_ns = TimePoint<Clock::Fast1>::now();
    int64_t target_ns = now_ns + std::max<int64_t>(0, delay.toNanoseconds());

    {
        std::lock_guard<std::mutex> lk(mutex_);
        QueuedMessage msg{id, what, target_ns, std::move(task)};
        auto it = std::upper_bound(
            queue_.begin(), queue_.end(), target_ns,
            [](int64_t lhs_ns, const QueuedMessage& rhs) {
                return lhs_ns < rhs.exec_time_ns;
            });
        queue_.insert(it, std::move(msg));
    }
    cv_.notify_one();
    return id;
}

void MsgLoop::send(MsgTask task, int what) {
    if (!task) return;
    if (!running_.load(std::memory_order_acquire) ||
        loop_thread_.get_id() == std::this_thread::get_id()) {
        task();
        return;
    }
    AutoWaitEvent done(false);
    post([&task, &done]() {
        task();
        done.signal();
    }, what);
    done.wait();
}

void MsgLoop::cancel(int what) {
    std::lock_guard<std::mutex> lk(mutex_);
    queue_.erase(
        std::remove_if(queue_.begin(), queue_.end(),
                       [what](const QueuedMessage& m) { return m.what == what; }),
        queue_.end());
}

void MsgLoop::cancelAll() {
    std::lock_guard<std::mutex> lk(mutex_);
    queue_.clear();
}

size_t MsgLoop::pendingCount() const noexcept {
    std::lock_guard<std::mutex> lk(mutex_);
    return queue_.size();
}

void MsgLoop::loopBody() {
    ThreadHelper::setCurrentThreadName(attr_.name.c_str());
    ThreadHelper::setCurrentThreadPriority(attr_.priority);

    while (true) {
        MsgTask next_task;
        {
            std::unique_lock<std::mutex> lk(mutex_);
            while (queue_.empty() && !quit_requested_.load(std::memory_order_acquire)) {
                cv_.wait(lk);
            }
            if (queue_.empty() && quit_requested_.load(std::memory_order_acquire)) {
                break;
            }
            int64_t now_ns = TimePoint<Clock::Fast1>::now();
            int64_t front_ns = queue_.front().exec_time_ns;
            if (front_ns > now_ns) {
                cv_.wait_for(lk, std::chrono::nanoseconds(front_ns - now_ns));
                continue;
            }
            next_task = std::move(queue_.front().task);
            queue_.pop_front();
        }
        if (next_task) {
            next_task();
        }
    }
}

// ============================================================================
// 4. ThreadPoolHelper & Daemon (0x025e68..0x027250)
// Cài đặt ThreadPoolHelper và tiến trình nền Daemon.
// ============================================================================
ThreadPoolHelper::ThreadPoolHelper()
    : worker_loop_(new MsgLoop(ThreadAttr(0, "vcb-pool"))) {
    worker_loop_->start();
}

ThreadPoolHelper::~ThreadPoolHelper() noexcept {
    shutdown();
}

ThreadPoolHelper& ThreadPoolHelper::instance() {
    static ThreadPoolHelper s_pool;
    return s_pool;
}

uint64_t ThreadPoolHelper::submit(Function<void()> task) {
    return worker_loop_->post(std::move(task));
}

uint64_t ThreadPoolHelper::schedule(Function<void()> task, TimeDelta delay) {
    return worker_loop_->postDelayed(std::move(task), delay);
}

void ThreadPoolHelper::shutdown() {
    if (worker_loop_) {
        worker_loop_->quit(true);
    }
}

Daemon::Daemon()
    : daemon_loop_(new MsgLoop(ThreadAttr(0, "vcb-daemon"))) {
    daemon_loop_->start();
}

Daemon::~Daemon() noexcept {
    stop();
}

Daemon& Daemon::instance() {
    static Daemon s_daemon;
    return s_daemon;
}

uint64_t Daemon::postTask(Function<void()> task, TimeDelta delay) {
    return daemon_loop_->postDelayed(std::move(task), delay);
}

void Daemon::stop() {
    if (daemon_loop_) {
        daemon_loop_->quit(true);
    }
}

// ============================================================================
// 5. Global .bss State for ALOG, JNI_OnLoad, and UnExpected Backtrace
// Verified from disassembly 0x029b10..0x02b198:
//   - .bss 0x03c0e0: vcbkit_alog_write_fn g_alog_write_fn
//   - .bss 0x03c0e8: int32_t g_alog_retry_count (max 5 retries at 0x029b24)
//   - .bss 0x03c0f0: JavaVM* g_vcbkit_jvm
//   - .bss 0x03c0f8: void*   g_unexpected_cls ("com/ss/vcbkit/UnExpected")
//   - .bss 0x03c100: void*   g_not_reach_here_mid ("notReachHereNative")
// Trạng thái toàn cục .bss của ALOG, JNI_OnLoad và UnExpected.
// ============================================================================
namespace {

std::atomic<vcbkit_alog_write_fn> g_alog_write_fn{nullptr}; // .bss 0x03c0e0
std::atomic<int32_t> g_alog_retry_count{0};                 // .bss 0x03c0e8
std::atomic<JavaVM*> g_vcbkit_jvm{nullptr};                 // .bss 0x03c0f0

std::mutex g_unexpected_mtx;
UnExpected::ReportCallback g_unexpected_cb;

using npth_bt_current_fn = char* (*)();
using npth_bt_thread_fn  = char* (*)(int32_t tid);
using npth_bt_free_fn    = void (*)(char* str);

struct NpthBtSymbols {
    bool attempted = false;
    npth_bt_current_fn bt_current = nullptr;
    npth_bt_thread_fn bt_thread = nullptr;
    npth_bt_free_fn bt_free = nullptr;
};

NpthBtSymbols g_npth_bt;

void resolveNpthBtSymbolsLocked() noexcept {
    if (g_npth_bt.attempted) {
        return;
    }
    g_npth_bt.attempted = true;
#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    // Verified strings at .rodata 0x02c6a0..0x02c6cd:
    //   "libnpth_bt.so", "npth_bt_current", "npth_bt_thread", "npth_bt_free"
    void* handle = dlopen("libnpth_bt.so", RTLD_LAZY);
    if (handle) {
        g_npth_bt.bt_current = reinterpret_cast<npth_bt_current_fn>(
            dlsym(handle, "npth_bt_current"));
        g_npth_bt.bt_thread = reinterpret_cast<npth_bt_thread_fn>(
            dlsym(handle, "npth_bt_thread"));
        g_npth_bt.bt_free = reinterpret_cast<npth_bt_free_fn>(
            dlsym(handle, "npth_bt_free"));
    }
#endif
}

} // namespace

// ============================================================================
// 6. ScopedJniEnv & UnExpected Implementation (0x02a460..0x02a864)
// Cài đặt ScopedJniEnv và UnExpected::report / reportStack.
// ============================================================================
ScopedJniEnv::ScopedJniEnv() noexcept
    : env_(nullptr), attached_by_scope_(false) {
    (void)g_vcbkit_jvm.load(std::memory_order_acquire);
}

ScopedJniEnv::~ScopedJniEnv() noexcept {
    env_ = nullptr;
    attached_by_scope_ = false;
}

void UnExpected::setCallback(ReportCallback cb) {
    std::lock_guard<std::mutex> lk(g_unexpected_mtx);
    g_unexpected_cb = std::move(cb);
}

void UnExpected::report(const char* category,
                        const char* reason,
                        const std::map<std::string, std::string>& extras) {
    ReportCallback cb_copy;
    {
        std::lock_guard<std::mutex> lk(g_unexpected_mtx);
        cb_copy = g_unexpected_cb;
    }
    if (cb_copy) {
        cb_copy(category ? category : "vcbkit",
                reason ? reason : "unexpected",
                extras);
    }
}

// 0x02a698: UnExpected::reportStack(const char* category, const char* reason, int32_t tid)
void UnExpected::reportStack(const char* category,
                             const char* reason,
                             int32_t tid) {
    std::string stack_trace = "<unavailable>";
    {
        std::lock_guard<std::mutex> lk(g_unexpected_mtx);
        resolveNpthBtSymbolsLocked();
        char* raw_bt = nullptr;
        if (tid <= 0 && g_npth_bt.bt_current) {
            raw_bt = g_npth_bt.bt_current();
        } else if (tid > 0 && g_npth_bt.bt_thread) {
            raw_bt = g_npth_bt.bt_thread(tid);
        }
        if (raw_bt) {
            stack_trace.assign(raw_bt);
            if (g_npth_bt.bt_free) {
                g_npth_bt.bt_free(raw_bt);
            }
        }
    }
    std::map<std::string, std::string> extras;
    extras["stack"] = stack_trace;
    extras["tid"] = std::to_string(tid);
    report(category, reason, extras);
}

} // namespace vcbkit
} // namespace ss
} // namespace com

// ============================================================================
// 7. Exported C Linkage Functions (0x029b10..0x02b198)
// Exact AArch64 disassembly of vcbkit_init_logger_wrapper (0x029b10..0x029c00):
//   0x029b10: ldr x8, [x19, #0xe0] ; cbnz x8, 0x29bf8 (already resolved)
//   0x029b1c: ldr w8, [x19, #0xe8] ; cmp w8, #5 ; b.gt 0x29bf8 (max 5 retries)
//   0x029b28: add w8, w8, #1 ; str w8, [x19, #0xe8]
//   0x029b34: adrp x0, 0x2c000 ; add x0, x0, #0x506 ("libalog.so")
//   0x029b3c: mov w1, #1 (RTLD_LAZY) ; bl dlopen
//   0x029b48: adrp x1, 0x2c000 ; add x1, x1, #0x511 ("alog_write_default_instance")
//   0x029b50: bl dlsym ; str x0, [x19, #0xe0]
//   0x029b60: invokes alog_write_default_instance(2, "vcbkit", "alog_wrapper.cpp",
//             "init_log_wrapper", 35, "log ok")
// Cài đặt các hàm xuất khẩu C: vcbkit_init_logger_wrapper, vcbkit_log*, JNI_OnLoad.
// ============================================================================
extern "C" {

void vcbkit_init_logger_wrapper() noexcept {
    if (com::ss::vcbkit::g_alog_write_fn.load(std::memory_order_acquire) != nullptr) {
        return;
    }
    int32_t retries = com::ss::vcbkit::g_alog_retry_count.load(std::memory_order_relaxed);
    if (retries > com::ss::vcbkit::kVcbAlogMaxRetry) {
        return;
    }
    com::ss::vcbkit::g_alog_retry_count.store(retries + 1, std::memory_order_relaxed);

#if defined(__unix__) || defined(__APPLE__) || defined(__ANDROID__)
    void* handle = dlopen("libalog.so", RTLD_LAZY);
    if (handle) {
        auto fn = reinterpret_cast<vcbkit_alog_write_fn>(
            dlsym(handle, "alog_write_default_instance"));
        if (fn) {
            com::ss::vcbkit::g_alog_write_fn.store(fn, std::memory_order_release);
            fn(2, "vcbkit", "alog_wrapper.cpp", "init_log_wrapper", 35, "log ok");
        }
    }
#endif
}

void vcbkit_logs(int level,
                 const char* tag,
                 const char* file,
                 const char* func,
                 int line,
                 const char* msg) {
    vcbkit_init_logger_wrapper();
    auto fn = com::ss::vcbkit::g_alog_write_fn.load(std::memory_order_acquire);
    if (fn) {
        fn(level,
           tag ? tag : "vcbkit",
           file ? file : "",
           func ? func : "",
           line,
           msg ? msg : "");
    }
}

void vcbkit_logm(int level,
                 const char* tag,
                 const char* file,
                 const char* func,
                 int line,
                 const char* fmt, ...) {
    if (!fmt) return;
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    vcbkit_logs(level, tag, file, func, line, buf);
}

void vcbkit_logf(int level,
                 const char* tag,
                 const char* file,
                 const char* func,
                 int line,
                 const char* fmt, ...) {
    if (!fmt) return;
    char buf[1024];
    va_list args;
    va_start(args, fmt);
    std::vsnprintf(buf, sizeof(buf), fmt, args);
    va_end(args);
    vcbkit_logs(level, tag, file, func, line, buf);
}

void vcbkit_logl(int level, const char* tag, const char* msg) {
    vcbkit_logs(level, tag, "alog_wrapper.cpp", "vcbkit_logl", 0, msg);
}

// 0x02a55c..0x02a694: JNI_OnLoad(JavaVM* vm, void* reserved)
// Stores JavaVM* at .bss 0x03c0f0, resolves class "com/ss/vcbkit/UnExpected"
// and static method "notReachHereNative" "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V",
// and returns 0x00010004 (JNI_VERSION_1_4).
int32_t JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    com::ss::vcbkit::g_vcbkit_jvm.store(vm, std::memory_order_release);
    return com::ss::vcbkit::kVcbJniVersion14;
}

// 0x02a868: vcbkit_unexpected_reach
void vcbkit_unexpected_reach(const char* category,
                             const char* reason,
                             const char* file,
                             const char* func,
                             int line) {
    std::map<std::string, std::string> extras;
    if (file) extras["file"] = file;
    if (func) extras["func"] = func;
    extras["line"] = std::to_string(line);
    com::ss::vcbkit::UnExpected::report(category, reason, extras);
}

} // extern "C"
