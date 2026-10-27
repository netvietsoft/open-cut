// ============================================================================
// File: vcbasekit_thread_jni.h
// Target: libvcbasekit.so (231,568 bytes, SHA-256: d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
// Classification: CORE_10_MONITORING (ByteDance Video Cloud BaseKit)
//
// Description (EN):
// Clean-room C++17 header for com::ss::vcbkit threading, message loop,
// ALOG dynamic bridge, and JNI UnExpected stack-reporting subsystem:
//   - Block (0x021de4..0x021e94)
//   - ThreadHelper (0x021da8..0x021de4) & Thread (0x022728..0x023718)
//   - MsgLoop (0x023c6c..0x025550), ThreadPoolHelper (0x025e68..0x0264a0),
//     and Daemon (0x026850..0x027250)
//   - vcbkit_init_logger_wrapper & vcbkit_logm/logs/logf/logl (0x029b10..0x02a458)
//   - ScopedJniEnv (0x02a460..0x02a55c), JNI_OnLoad (0x02a55c..0x02a694),
//     UnExpected (0x02a698..0x02a864), and vcbkit_unexpected_reach (0x02a868)
//
// Mô tả (VI):
// Header C++17 tái tạo sạch phân hệ đa luồng, vòng lặp thông điệp, cầu nối
// động ALOG và báo cáo ngoại lệ JNI UnExpected của com::ss::vcbkit.
// ============================================================================

#pragma once

#include "vcbasekit_sync_string.h"
#include <deque>
#include <map>
#include <thread>

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// 1. Block — Reference-Counted Task Closure (0x021de4..0x021e94)
// Đóng gói tác vụ thực thi có đếm tham chiếu (Block).
// ============================================================================
class Block : public BaseRef {
public:
    using TaskFn = Function<void()>;

    explicit Block(TaskFn fn);            // 0x021de4
    ~Block() noexcept override;           // 0x021e38

    void run();                           // 0x021e50
    void cancel() noexcept;               // 0x021e78
    bool isCancelled() const noexcept;    // 0x021e88

private:
    TaskFn fn_;
    std::atomic<bool> cancelled_{false};
};

// ============================================================================
// 2. ThreadHelper (0x021da8..0x021de4) & Thread (0x022728..0x023718)
// Trợ giúp thao tác luồng hệ điều hành (ThreadHelper) và đối tượng luồng (Thread).
// ============================================================================
class ThreadHelper {
public:
    static uint64_t currentThreadId() noexcept;                      // 0x021da8
    static void setCurrentThreadName(const char* name) noexcept;     // 0x021db8
    static void setCurrentThreadPriority(int priority) noexcept;     // 0x021dc8
    static void sleep(TimeDelta duration) noexcept;                  // 0x021dd8
};

class Thread : public BaseRef {
public:
    explicit Thread(const ThreadAttr& attr = ThreadAttr());          // 0x022728
    Thread(const ThreadAttr& attr, Function<void()> entry);          // 0x0227a0
    ~Thread() noexcept override;                                     // 0x022830

    bool start(Function<void()> entry = nullptr);                    // 0x022890
    void join();                                                     // 0x022a10
    void detach();                                                   // 0x022ac0
    bool isRunning() const noexcept;                                 // 0x022b20
    uint64_t id() const noexcept { return thread_id_.load(std::memory_order_acquire); }
    const std::string& name() const noexcept { return attr_.name; }

private:
    ThreadAttr attr_;
    Function<void()> entry_;
    std::thread worker_;
    std::atomic<bool> running_{false};
    std::atomic<uint64_t> thread_id_{0};
};

// ============================================================================
// 3. MsgLoop — Priority / Delayed Message Queue Loop (0x023c6c..0x025550)
// Vòng lặp thông điệp hỗ trợ gửi đồng bộ, bất đồng bộ và trễ theo thời gian.
// ============================================================================
class MsgLoop : public BaseRef {
public:
    using MsgTask = Function<void()>;

    struct QueuedMessage {
        uint64_t msg_id = 0;
        int what = 0;
        int64_t exec_time_ns = 0;
        MsgTask task;
    };

    explicit MsgLoop(const ThreadAttr& attr = ThreadAttr(0, "vcb-msgloop")); // 0x023c6c
    ~MsgLoop() noexcept override;                                            // 0x023d80

    bool start();                                                            // 0x023e20
    void quit(bool wait_for_drain = true);                                   // 0x023f10
    uint64_t post(MsgTask task, int what = 0);                               // 0x024100
    uint64_t postDelayed(MsgTask task, TimeDelta delay, int what = 0);       // 0x024240
    void send(MsgTask task, int what = 0);                                   // 0x0243a0
    void cancel(int what);                                                   // 0x024520
    void cancelAll();                                                        // 0x024600
    size_t pendingCount() const noexcept;

private:
    void loopBody();

    ThreadAttr attr_;
    mutable std::mutex mutex_;
    std::condition_variable cv_;
    std::deque<QueuedMessage> queue_;
    std::thread loop_thread_;
    std::atomic<bool> running_{false};
    std::atomic<bool> quit_requested_{false};
    std::atomic<uint64_t> next_msg_id_{1};
};

// ============================================================================
// 4. ThreadPoolHelper & Daemon (0x025e68..0x027250)
// Hồ luồng chia sẻ (ThreadPoolHelper) và tiến trình nền định kỳ (Daemon).
// ============================================================================
class ThreadPoolHelper {
public:
    static ThreadPoolHelper& instance();                                     // 0x025e68
    uint64_t submit(Function<void()> task);                                  // 0x025f20
    uint64_t schedule(Function<void()> task, TimeDelta delay);               // 0x026040
    void shutdown();                                                         // 0x026210

private:
    ThreadPoolHelper();
    ~ThreadPoolHelper() noexcept;

    RefPtr<MsgLoop> worker_loop_;
};

class Daemon {
public:
    static Daemon& instance();                                               // 0x026850
    uint64_t postTask(Function<void()> task, TimeDelta delay = TimeDelta()); // 0x026920
    void stop();                                                             // 0x026b40

private:
    Daemon();
    ~Daemon() noexcept;

    RefPtr<MsgLoop> daemon_loop_;
};

// ============================================================================
// 5. ScopedJniEnv (0x02a460..0x02a55c) & UnExpected (0x02a698..0x02b198)
// Verified from JNI_OnLoad (0x02a55c..0x02a694):
//   - .bss 0x03c0f0: JavaVM* g_vcbkit_jvm
//   - .bss 0x03c0f8: jclass  g_unexpected_cls ("com/ss/vcbkit/UnExpected" at 0x02c5af)
//   - .bss 0x03c100: jmethodID g_not_reach_here_mid
//     ("notReachHereNative", "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V"
//      at 0x02c5c8 & 0x02c5db)
//   - Returns 0x00010004 (JNI_VERSION_1_4)
// Quản lý phạm vi JNIEnv tự động (ScopedJniEnv) và báo cáo lỗi UnExpected.
// ============================================================================
constexpr int32_t kVcbJniVersion14 = 0x00010004; // JNI_VERSION_1_4 (0x02a67c: mov w0, #0x10004)
constexpr int32_t kVcbAlogMaxRetry = 5;          // 0x029b24: cmp w8, #5 ; b.gt 0x29bf8

class ScopedJniEnv {
public:
    ScopedJniEnv() noexcept;          // 0x02a460
    ~ScopedJniEnv() noexcept;         // 0x02a508

    JNIEnv* get() const noexcept { return env_; }
    explicit operator bool() const noexcept { return env_ != nullptr; }

private:
    JNIEnv* env_{nullptr};
    bool attached_by_scope_{false};
};

class UnExpected {
public:
    using ReportCallback = Function<void(const std::string& category,
                                         const std::string& reason,
                                         const std::map<std::string, std::string>& extras)>;

    static void setCallback(ReportCallback cb);
    static void report(const char* category,
                       const char* reason,
                       const std::map<std::string, std::string>& extras = {});
    static void reportStack(const char* category,
                            const char* reason,
                            int32_t tid = 0); // 0x02a698
};

} // namespace vcbkit
} // namespace ss
} // namespace com

// ============================================================================
// 6. Exported C Linkage Functions: ALOG Wrapper, JNI_OnLoad, UnExpected Reach
// Các hàm xuất khẩu chuẩn C: Cầu nối ALOG, JNI_OnLoad và vcbkit_unexpected_reach.
// ============================================================================
extern "C" {

using vcbkit_alog_write_fn = void (*)(int level,
                                      const char* tag,
                                      const char* file,
                                      const char* func,
                                      int line,
                                      const char* msg);

void vcbkit_init_logger_wrapper() noexcept; // 0x029b10
void vcbkit_logm(int level, const char* tag, const char* file, const char* func, int line, const char* fmt, ...); // 0x029c00
void vcbkit_logs(int level, const char* tag, const char* file, const char* func, int line, const char* msg);      // 0x029df0
void vcbkit_logf(int level, const char* tag, const char* file, const char* func, int line, const char* fmt, ...); // 0x029fd0
void vcbkit_logl(int level, const char* tag, const char* msg);                                                    // 0x02a230

int32_t JNI_OnLoad(JavaVM* vm, void* reserved); // 0x02a55c

void vcbkit_unexpected_reach(const char* category,
                             const char* reason,
                             const char* file,
                             const char* func,
                             int line); // 0x02a868

} // extern "C"
