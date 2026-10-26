// ============================================================================
// File: orbuculumadapter_runtime_hooks.cpp
// Target Binary: liborbuculumadapter.so (149,936 bytes)
// SHA-256: c79326a4419e98be93ce70b6b08f70a82852980d7322dadb3d5edac7ea179785
//
// [EN] Clean-room C++17 implementation of the ShadowHook libc `setenv`/`getenv`
//      symbol export table (0x011db4..0x012468), the 2-thread `SandboxTP-%zu`
//      asynchronous ThreadPool (0x0124d0..0x013124), `sendAsync` telemetry
//      dispatch (0x00c5e0), dynamic `dlopen`/`dlsym` peer bridges to
//      `liborbuculum.so` and `libpumbaa-network.so` (0x00eb48..0x011da0), and
//      the TLS `sigsetjmp`/`siglongjmp` SignalCrashGuard (0x014400..0x014928).
// [VN] Triển khai C++17 tái tạo sạch cho bảng xuất biểu tượng qua ShadowHook
//      `setenv`/`getenv` của libc (0x011db4..0x012468), hồ 2 luồng bất đồng bộ
//      `SandboxTP-%zu` (0x0124d0..0x013124), bộ điều phối telemetry `sendAsync`
//      (0x00c5e0), cầu nối `dlopen`/`dlsym` động tới `liborbuculum.so` và
//      `libpumbaa-network.so` (0x00eb48..0x011da0), cùng lớp bảo vệ chống sập
//      tín hiệu TLS `sigsetjmp`/`siglongjmp` SignalCrashGuard (0x014400..0x014928).
// ============================================================================

#include "orbuculumadapter_runtime_hooks.h"

#include <chrono>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "orbuculumadapter_config_parser.h"

#if defined(__ANDROID__) || defined(__linux__)
#include <dlfcn.h>
#include <pthread.h>
#include <setjmp.h>
#endif

#if defined(__ANDROID__) && __has_include(<android/log.h>)
#include <android/log.h>
#define ORBU_LOGI(fmt, ...) \
    __android_log_print(ANDROID_LOG_INFO, kLogTag, fmt, ##__VA_ARGS__)
#define ORBU_LOGE(fmt, ...) \
    __android_log_print(ANDROID_LOG_ERROR, kLogTag, fmt, ##__VA_ARGS__)
#else
#define ORBU_LOGI(fmt, ...) ((void)0)
#define ORBU_LOGE(fmt, ...) ((void)0)
#endif

// ============================================================================
// [EN] Weak declarations for ByteDance ShadowHook symbols imported from
//      libshadowhook.so (.dynsym 47, 81, 82, 91, 95).
// [VN] Khai báo liên kết yếu cho các biểu tượng ByteDance ShadowHook nhập từ
//      libshadowhook.so (.dynsym 47, 81, 82, 91, 95).
// ============================================================================
extern "C" {
#if defined(__GNUC__) || defined(__clang__)
__attribute__((weak)) int shadowhook_init(int mode, bool debuggable);
__attribute__((weak)) void* shadowhook_hook_sym_name(
    const char* lib_name,
    const char* sym_name,
    void* new_addr,
    void** orig_addr);
__attribute__((weak)) int shadowhook_unhook(void* stub);
__attribute__((weak)) int shadowhook_get_init_errno();
__attribute__((weak)) const char* shadowhook_to_errmsg(int error_number);
#endif
}

namespace nextai {
namespace opencut {
namespace orbuculumadapter {

namespace {

// ============================================================================
// [EN] Singleton SandboxThreadPoolState at .bss 0x028e98 (guarded by 0x028f48)
// [VN] Singleton SandboxThreadPoolState tại .bss 0x028e98 (bảo vệ bởi 0x028f48)
// ============================================================================
SandboxThreadPoolState& GetSandboxThreadPool() {
    static SandboxThreadPoolState s_pool;
    static std::once_flag s_init_once;
    std::call_once(s_init_once, []() {
        // [EN] Reconstructed from 0x01259c..0x0128ec: spawns exactly 2 worker threads
        //      named "SandboxTP-0" and "SandboxTP-1" (max 15 chars via pthread_setname_np).
        // [VN] Phục dựng từ 0x01259c..0x0128ec: khởi tạo đúng 2 luồng xử lý
        //      đặt tên "SandboxTP-0" và "SandboxTP-1" (tối đa 15 ký tự qua pthread_setname_np).
        constexpr size_t kNumWorkerThreads = 2;
        s_pool.workers.reserve(kNumWorkerThreads);
        for (size_t idx = 0; idx < kNumWorkerThreads; ++idx) {
            s_pool.workers.emplace_back([idx]() {
                char thread_name[32]{};
                std::snprintf(thread_name, sizeof(thread_name), "SandboxTP-%zu", idx);
                thread_name[15] = '\0';
#if defined(__ANDROID__) || defined(__linux__)
                pthread_setname_np(pthread_self(), thread_name);
#endif
                // [EN] Worker loop reconstructed from 0x0128f0..0x012be8
                // [VN] Vòng lặp luồng xử lý phục dựng từ 0x0128f0..0x012be8
                for (;;) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(s_pool.queue_mutex);
                        s_pool.queue_cv.wait(lock, []() {
                            return s_pool.stop_flag.load(std::memory_order_acquire) ||
                                   !s_pool.task_queue.empty();
                        });
                        if (s_pool.stop_flag.load(std::memory_order_acquire) &&
                            s_pool.task_queue.empty()) {
                            return;
                        }
                        task = std::move(s_pool.task_queue.front());
                        s_pool.task_queue.pop_front();
                    }
                    if (task) {
                        task();
                    }
                }
            });
        }
    });
    return s_pool;
}

// ============================================================================
// [EN] Signal Crash Guard TLS State (0x014400..0x014928, .bss 0x028f50..0x028fd0)
// [VN] Trạng thái TLS Bảo vệ Chống Sập Tín hiệu (0x014400..0x014928, .bss 0x028f50..0x028fd0)
// ============================================================================
#if defined(__ANDROID__) || defined(__linux__)
struct TlsCrashGuardSlot {
    sigjmp_buf jump_buffer;
    volatile sig_atomic_t active = 0;
};

thread_local TlsCrashGuardSlot g_tls_crash_slot;
std::once_flag g_sigaction_init_once;
struct sigaction g_prev_sigsegv {};
struct sigaction g_prev_sigbus {};
struct sigaction g_prev_sigabrt {};

void SignalCrashHandler(int sig, siginfo_t* info, void* ucontext) {
    if (g_tls_crash_slot.active != 0) {
        g_tls_crash_slot.active = 0;
        siglongjmp(g_tls_crash_slot.jump_buffer, sig != 0 ? sig : 1);
    }
    struct sigaction* prev = nullptr;
    if (sig == SIGSEGV) {
        prev = &g_prev_sigsegv;
    } else if (sig == SIGBUS) {
        prev = &g_prev_sigbus;
    } else if (sig == SIGABRT) {
        prev = &g_prev_sigabrt;
    }
    if (prev != nullptr &&
        (prev->sa_flags & SA_SIGINFO) &&
        prev->sa_sigaction != nullptr) {
        prev->sa_sigaction(sig, info, ucontext);
        return;
    }
    if (prev != nullptr &&
        prev->sa_handler != SIG_DFL &&
        prev->sa_handler != SIG_IGN &&
        prev->sa_handler != nullptr) {
        prev->sa_handler(sig);
        return;
    }
    std::signal(sig, SIG_DFL);
    std::raise(sig);
}

void EnsureSignalHandlersInstalled() {
    std::call_once(g_sigaction_init_once, []() {
        struct sigaction sa {};
        sa.sa_sigaction = &SignalCrashHandler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = SA_SIGINFO | SA_NODEFER;
        sigaction(SIGSEGV, &sa, &g_prev_sigsegv);
        sigaction(SIGBUS, &sa, &g_prev_sigbus);
        sigaction(SIGABRT, &sa, &g_prev_sigabrt);
    });
}
#endif

}  // namespace

// ============================================================================
// 1. SHADOWHOOK SETENV / GETENV HOOKS & EXPORT TABLE (0x011db4..0x012468)
// ============================================================================

/**
 * [EN] Reconstructed from `0x011db4..0x011e70` (`hooked_setenv`):
 *      1. Logs `"hooked_setenv key=%s, value=%s, overwrite=%d"` if `native_debug` is true.
 *      2. Acquires exclusive write lock on `g_env_rw_mutex` (`0x0287b8`).
 *      3. Calls `orig_setenv_fn(name, value, overwrite)` (`0x028878`).
 *      4. Releases exclusive write lock and returns result.
 * [VN] Phục dựng từ `0x011db4..0x011e70` (`hooked_setenv`):
 *      1. Ghi log `"hooked_setenv key=%s, value=%s, overwrite=%d"` nếu `native_debug` bật.
 *      2. Khóa ghi độc quyền trên `g_env_rw_mutex` (`0x0287b8`).
 *      3. Gọi `orig_setenv_fn(name, value, overwrite)` (`0x028878`).
 *      4. Mở khóa ghi độc quyền và trả về kết quả.
 */
int HookedSetenv(const char* name, const char* value, int overwrite) {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (state.native_debug) {
        ORBU_LOGI(
            "hooked_setenv key=%s, value=%s, overwrite=%d",
            name ? name : "(null)",
            value ? value : "(null)",
            overwrite);
    }

    std::unique_lock<std::shared_timed_mutex> write_lock(state.env_rw_mutex);
    using SetenvFn = int (*)(const char*, const char*, int);
    if (state.orig_setenv_fn != nullptr) {
        return reinterpret_cast<SetenvFn>(state.orig_setenv_fn)(name, value, overwrite);
    }
#if defined(__ANDROID__) || defined(__linux__)
    return ::setenv(name, value, overwrite);
#else
    return (name != nullptr && value != nullptr) ? 0 : -1;
#endif
}

/**
 * [EN] Reconstructed from `0x011e74..0x01204c` (`hooked_getenv`):
 *      1. Checks `state.env_table_initialized` (`0x028d34`) and `name != nullptr`.
 *      2. Iterates `i = 0 .. state.env_export_count - 1` (`0x028d30`) over
 *         `state.env_export_table` (`0x028930`, stride 128 bytes):
 *         - Compares `std::strcmp(name, entry.name) == 0`.
 *         - If matched, returns `entry.value` (`+0x40`, containing `"%p"` address string)
 *           directly without touching `libc` environment variables!
 *      3. If not in the 5-entry export table, acquires shared read lock on
 *         `state.env_rw_mutex` (`0x0287b8`) and calls `orig_getenv_fn(name)` (`0x028880`).
 * [VN] Phục dựng từ `0x011e74..0x01204c` (`hooked_getenv`):
 *      1. Kiểm tra `state.env_table_initialized` (`0x028d34`) và `name != nullptr`.
 *      2. Duyệt `i = 0 .. state.env_export_count - 1` (`0x028d30`) trên
 *         `state.env_export_table` (`0x028930`, bước nhảy 128 byte):
 *         - So sánh `std::strcmp(name, entry.name) == 0`.
 *         - Nếu khớp, trả về `entry.value` (`+0x40`, chứa chuỗi địa chỉ `"%p"`)
 *           trực tiếp mà không cần truy cập biến môi trường của `libc`!
 *      3. Nếu không thuộc bảng xuất 5 mục, khóa đọc chia sẻ trên `state.env_rw_mutex`
 *         (`0x0287b8`) và gọi `orig_getenv_fn(name)` (`0x028880`).
 */
char* HookedGetenv(const char* name) {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (state.env_table_initialized && name != nullptr) {
        const uint32_t count = state.env_export_count;
        for (uint32_t idx = 0; idx < count && idx < 8; ++idx) {
            if (std::strcmp(name, state.env_export_table[idx].name) == 0) {
                if (state.native_debug) {
                    ORBU_LOGI(
                        "getenv key=%s, value=%s",
                        state.env_export_table[idx].name,
                        state.env_export_table[idx].value);
                }
                return state.env_export_table[idx].value;
            }
        }
    }

    std::shared_lock<std::shared_timed_mutex> read_lock(state.env_rw_mutex);
    using GetenvFn = char* (*)(const char*);
    char* val = nullptr;
    if (state.orig_getenv_fn != nullptr) {
        val = reinterpret_cast<GetenvFn>(state.orig_getenv_fn)(name);
    } else if (name != nullptr) {
        val = std::getenv(name);
    }

    if (state.native_debug) {
        ORBU_LOGI(
            "hooked_getenv key=%s, value=%s",
            name ? name : "null",
            val ? val : "null");
    }
    return val;
}

/**
 * [EN] Reconstructed from `0x012174..0x012354` (`setupEnvTable`):
 *      Clears 1032 bytes at `.bss 0x028930` (`memset(0x028930, 0, 0x408)`),
 *      formats 5 function pointers via `snprintf(buf, 64, "%p", fn_ptr)`, and
 *      stores them into the 5 `EnvExportEntry` slots (`128 bytes` each):
 *        [0] `"orbuculumIsProceedRequest"`              -> `0x011178`
 *        [1] `"orbuculumIsProceedRequestForTTNet"`      -> `0x00eb48`
 *        [2] `"orbuculumIsProceedResponseImpl"`         -> `0x011808`
 *        [3] `"orbuculumRegisterLiveShutdownCallback"`  -> `0x00d490`
 *        [4] `"orbuculumIsProceedSeiField"`             -> `0x00d2e8`
 *      Sets `env_export_count = 5` (`0x028d30`) and `env_table_initialized = true` (`0x028d34`).
 * [VN] Phục dựng từ `0x012174..0x012354` (`setupEnvTable`):
 *      Xóa 1032 byte tại `.bss 0x028930` (`memset(0x028930, 0, 0x408)`),
 *      định dạng 5 con trỏ hàm qua `snprintf(buf, 64, "%p", fn_ptr)`, và
 *      lưu vào 5 ô `EnvExportEntry` (mỗi ô `128 byte`):
 *        [0] `"orbuculumIsProceedRequest"`              -> `0x011178`
 *        [1] `"orbuculumIsProceedRequestForTTNet"`      -> `0x00eb48`
 *        [2] `"orbuculumIsProceedResponseImpl"`         -> `0x011808`
 *        [3] `"orbuculumRegisterLiveShutdownCallback"`  -> `0x00d490`
 *        [4] `"orbuculumIsProceedSeiField"`             -> `0x00d2e8`
 *      Đặt `env_export_count = 5` (`0x028d30`) và `env_table_initialized = true` (`0x028d34`).
 */
bool SetupEnvExportTable(
    void* fn_is_proceed_request,
    void* fn_is_proceed_request_ttnet,
    void* fn_is_proceed_response,
    void* fn_register_live_shutdown,
    void* fn_is_proceed_sei_field) {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    std::memset(state.env_export_table, 0, sizeof(state.env_export_table));
    state.env_export_count = 0;
    state.env_table_initialized = false;

    struct SymbolBinding {
        const char* symbol_name;
        void* fn_address;
    };

    const SymbolBinding kBindings[5] = {
        {"orbuculumIsProceedRequest", fn_is_proceed_request},
        {"orbuculumIsProceedRequestForTTNet", fn_is_proceed_request_ttnet},
        {"orbuculumIsProceedResponseImpl", fn_is_proceed_response},
        {"orbuculumRegisterLiveShutdownCallback", fn_register_live_shutdown},
        {"orbuculumIsProceedSeiField", fn_is_proceed_sei_field},
    };

    for (size_t i = 0; i < 5; ++i) {
        char formatted_addr[64]{};
        const int written = std::snprintf(
            formatted_addr, sizeof(formatted_addr), "%p", kBindings[i].fn_address);
        if (written <= 0 || static_cast<size_t>(written) >= sizeof(formatted_addr)) {
            ORBU_LOGE("Failed to format address for %s", kBindings[i].symbol_name);
            return false;
        }
        std::strncpy(state.env_export_table[i].name, kBindings[i].symbol_name, 63);
        state.env_export_table[i].name[63] = '\0';
        std::strncpy(state.env_export_table[i].value, formatted_addr, 63);
        state.env_export_table[i].value[63] = '\0';
        state.env_export_count = static_cast<uint32_t>(i + 1);
    }

    state.env_table_initialized = true;
    return true;
}

/**
 * [EN] Reconstructed from `0x012050..0x012170` (`hookAndSetupEnv`):
 *      1. Calls `shadowhook_init(0, false)` (`w0 = 0, w1 = 0`).
 *      2. Hooks `"libc.so"` `"setenv"` via `shadowhook_hook_sym_name("libc.so", "setenv",
 *         HookedSetenv, &orig_setenv_fn)` and saves stub at `0x028868`.
 *      3. Hooks `"libc.so"` `"getenv"` via `shadowhook_hook_sym_name("libc.so", "getenv",
 *         HookedGetenv, &orig_getenv_fn)` and saves stub at `0x028870`.
 *      4. Calls `SetupEnvExportTable` (`0x012174`). Returns `0` on success, `-1` on failure.
 * [VN] Phục dựng từ `0x012050..0x012170` (`hookAndSetupEnv`):
 *      1. Gọi `shadowhook_init(0, false)` (`w0 = 0, w1 = 0`).
 *      2. Hook `"libc.so"` `"setenv"` qua `shadowhook_hook_sym_name("libc.so", "setenv",
 *         HookedSetenv, &orig_setenv_fn)` và lưu stub tại `0x028868`.
 *      3. Hook `"libc.so"` `"getenv"` qua `shadowhook_hook_sym_name("libc.so", "getenv",
 *         HookedGetenv, &orig_getenv_fn)` và lưu stub tại `0x028870`.
 *      4. Gọi `SetupEnvExportTable` (`0x012174`). Trả về `0` nếu thành công, `-1` nếu lỗi.
 */
int32_t HookAndSetupEnv(
    void* fn_is_proceed_request,
    void* fn_is_proceed_request_ttnet,
    void* fn_is_proceed_response,
    void* fn_register_live_shutdown,
    void* fn_is_proceed_sei_field) {
    GlobalRuntimeState& state = GetGlobalRuntimeState();

#if defined(__GNUC__) || defined(__clang__)
    if (&shadowhook_init != nullptr) {
        const int init_rc = shadowhook_init(0, false);
        if (init_rc != 0) {
            const int err_no = (&shadowhook_get_init_errno != nullptr)
                                   ? shadowhook_get_init_errno()
                                   : init_rc;
            const char* err_msg = (&shadowhook_to_errmsg != nullptr)
                                      ? shadowhook_to_errmsg(err_no)
                                      : "unknown";
            ORBU_LOGE("init failed: %d, %s", err_no, err_msg);
            return -1;
        }
    }

    if (&shadowhook_hook_sym_name != nullptr) {
        state.shadowhook_stub_setenv = shadowhook_hook_sym_name(
            "libc.so",
            "setenv",
            reinterpret_cast<void*>(&HookedSetenv),
            &state.orig_setenv_fn);
        if (state.shadowhook_stub_setenv == nullptr) {
            ORBU_LOGE("hook setenv failed.");
            return -1;
        }

        state.shadowhook_stub_getenv = shadowhook_hook_sym_name(
            "libc.so",
            "getenv",
            reinterpret_cast<void*>(&HookedGetenv),
            &state.orig_getenv_fn);
        if (state.shadowhook_stub_getenv == nullptr) {
            ORBU_LOGE("hook getenv failed.");
            return -1;
        }
    }
#endif

    if (!SetupEnvExportTable(
            fn_is_proceed_request,
            fn_is_proceed_request_ttnet,
            fn_is_proceed_response,
            fn_register_live_shutdown,
            fn_is_proceed_sei_field)) {
        ORBU_LOGE("setEnv error.");
        return -1;
    }

    ORBU_LOGI("hook setenv and getenv success.");
    return 0;
}

/**
 * [EN] Reconstructed from `0x012358..0x012438` (`unhookSetenvAndGetenv`):
 *      Calls `shadowhook_unhook` on `shadowhook_stub_setenv` (`0x028868`) and
 *      `shadowhook_stub_getenv` (`0x028870`) and clears the stub pointers.
 * [VN] Phục dựng từ `0x012358..0x012438` (`unhookSetenvAndGetenv`):
 *      Gọi `shadowhook_unhook` trên `shadowhook_stub_setenv` (`0x028868`) và
 *      `shadowhook_stub_getenv` (`0x028870`) đồng thời xóa các con trỏ stub.
 */
void UnhookSetenvAndGetenv() {
    GlobalRuntimeState& state = GetGlobalRuntimeState();
    if (state.shadowhook_stub_setenv != nullptr) {
#if defined(__GNUC__) || defined(__clang__)
        if (&shadowhook_unhook != nullptr) {
            const int rc = shadowhook_unhook(state.shadowhook_stub_setenv);
            if (rc == 0) {
                ORBU_LOGI("unhook setenv success.");
            }
        }
#endif
        state.shadowhook_stub_setenv = nullptr;
    }

    if (state.shadowhook_stub_getenv != nullptr) {
#if defined(__GNUC__) || defined(__clang__)
        if (&shadowhook_unhook != nullptr) {
            const int rc = shadowhook_unhook(state.shadowhook_stub_getenv);
            if (rc == 0) {
                ORBU_LOGI("unhook getenv success.");
            }
        }
#endif
        state.shadowhook_stub_getenv = nullptr;
    }
}

/**
 * [EN] Reconstructed from `0x012440..0x012468`: stores callback atomically at `.bss 0x028d40`.
 * [VN] Phục dựng từ `0x012440..0x012468`: lưu callback nguyên tử tại `.bss 0x028d40`.
 */
void RegisterJavaPropertyCallback(QueryJavaPropertyCallbackFn cb) {
    GetGlobalRuntimeState().query_java_prop_cb.store(cb, std::memory_order_seq_cst);
}

/**
 * [EN] Reconstructed from `0x01246c..0x0124cc`: loads callback from `.bss 0x028d40`
 *      and invokes it if non-null; otherwise returns `""`.
 * [VN] Phục dựng từ `0x01246c..0x0124cc`: nạp callback từ `.bss 0x028d40`
 *      và gọi nếu khác null; ngược lại trả về `""`.
 */
std::string InvokeJavaPropertyCallback(const std::string& key) {
    const QueryJavaPropertyCallbackFn cb =
        GetGlobalRuntimeState().query_java_prop_cb.load(std::memory_order_seq_cst);
    if (cb != nullptr) {
        return cb(key);
    }
    return std::string();
}

// ============================================================================
// 2. SANDBOX THREAD POOL & ASYNC TELEMETRY REPORTER (0x00c5e0, 0x0124d0..0x013124)
// ============================================================================

void EnqueueSandboxTask(std::function<void()> task) {
    if (!task) {
        return;
    }
    SandboxThreadPoolState& pool = GetSandboxThreadPool();
    {
        std::lock_guard<std::mutex> lock(pool.queue_mutex);
        if (pool.stop_flag.load(std::memory_order_acquire)) {
            return;
        }
        pool.task_queue.push_back(std::move(task));
    }
    pool.queue_cv.notify_one();
}

void ShutdownSandboxThreadPool() {
    SandboxThreadPoolState& pool = GetSandboxThreadPool();
    {
        std::lock_guard<std::mutex> lock(pool.queue_mutex);
        pool.stop_flag.store(true, std::memory_order_release);
    }
    pool.queue_cv.notify_all();
    for (std::thread& worker : pool.workers) {
        if (worker.joinable()) {
            worker.join();
        }
    }
}

/**
 * [EN] Reconstructed from `0x00c5e0..0x00c860` (`sendAsync`):
 *      1. Checks `g_send_report_cb` (`0x028230`). If null, returns immediately.
 *      2. Packages all 9 arguments (`channel`, `url_or_key`, `method_or_val`,
 *         `headers_str`, `body_str`, `dataflow_id`, `sandbox_result`, `is_hit_rule`,
 *         `duration_us`) into a task functor (`0x00c9bc`) and submits it to
 *         `GetSandboxThreadPool()` (`0x0124d0`) via `EnqueueSandboxTask` (`0x012dd4`).
 * [VN] Phục dựng từ `0x00c5e0..0x00c860` (`sendAsync`):
 *      1. Kiểm tra `g_send_report_cb` (`0x028230`). Nếu null, thoát ngay lập tức.
 *      2. Đóng gói cả 9 tham số (`channel`, `url_or_key`, `method_or_val`,
 *         `headers_str`, `body_str`, `dataflow_id`, `sandbox_result`, `is_hit_rule`,
 *         `duration_us`) vào hàm tác vụ (`0x00c9bc`) và đưa vào hàng đợi
 *         `GetSandboxThreadPool()` (`0x0124d0`) qua `EnqueueSandboxTask` (`0x012dd4`).
 */
void SendReportAsync(
    const std::string& channel,
    const std::string& url_or_key,
    const std::string& method_or_val,
    const std::string& headers_str,
    const std::string& body_str,
    int32_t dataflow_id,
    int32_t sandbox_result,
    bool is_hit_rule,
    int64_t duration_us) {
    const SendReportCallbackFn cb = GetGlobalRuntimeState().send_report_cb;
    if (cb == nullptr) {
        return;
    }

    EnqueueSandboxTask([cb,
                        channel,
                        url_or_key,
                        method_or_val,
                        headers_str,
                        body_str,
                        dataflow_id,
                        sandbox_result,
                        is_hit_rule,
                        duration_us]() {
        cb(channel,
           url_or_key,
           method_or_val,
           headers_str,
           body_str,
           dataflow_id,
           sandbox_result,
           is_hit_rule,
           duration_us);
    });
}

// ============================================================================
// 3. SIGNAL CRASH GUARD & DYNAMIC PEER BRIDGES (0x00d390..0x015ff0)
// ============================================================================

/**
 * [EN] Reconstructed from `0x00d390..0x00d480`, `0x010bf4..0x011174`, `0x014400..0x014928`:
 *      Installs signal handlers (`SIGSEGV`, `SIGBUS`, `SIGABRT`), arms thread-local
 *      `sigsetjmp(buf, 1)` slot, runs `protected_fn()`, and disarms the slot.
 * [VN] Phục dựng từ `0x00d390..0x00d480`, `0x010bf4..0x011174`, `0x014400..0x014928`:
 *      Cài đặt trình xử lý tín hiệu (`SIGSEGV`, `SIGBUS`, `SIGABRT`), kích hoạt ô
 *      cục bộ luồng `sigsetjmp(buf, 1)`, chạy `protected_fn()`, và hủy kích hoạt ô.
 */
int32_t ExecuteWithSignalCrashGuard(
    const std::function<int32_t()>& protected_fn,
    int32_t fallback_return_value) {
    if (!protected_fn) {
        return fallback_return_value;
    }
#if defined(__ANDROID__) || defined(__linux__)
    EnsureSignalHandlersInstalled();
    g_tls_crash_slot.active = 1;
    if (sigsetjmp(g_tls_crash_slot.jump_buffer, 1) == 0) {
        const int32_t rc = protected_fn();
        g_tls_crash_slot.active = 0;
        return rc;
    }
    g_tls_crash_slot.active = 0;
    return fallback_return_value;
#else
    try {
        return protected_fn();
    } catch (...) {
        return fallback_return_value;
    }
#endif
}

/**
 * [EN] Reconstructed from `0x00eda8..0x00f060` inside `orbuculumIsProceedRequestForTTNet`:
 *      1. Lazily opens `"libpumbaa-network.so"` (`RTLD_LAZY = 1`) stored at `.bss 0x028778`.
 *      2. If `(sdk_enable_strategy & 0x02) != 0`, resolves `"domainIdentityRecognizeV2"`
 *         (`.bss 0x028780`); otherwise resolves `"domainIdentityRecognize"` (`.bss 0x028788`).
 *      3. Invokes the domain recognizer with `url` inside `ExecuteWithSignalCrashGuard`.
 * [VN] Phục dựng từ `0x00eda8..0x00f060` bên trong `orbuculumIsProceedRequestForTTNet`:
 *      1. Mở lười `"libpumbaa-network.so"` (`RTLD_LAZY = 1`) lưu tại `.bss 0x028778`.
 *      2. Nếu `(sdk_enable_strategy & 0x02) != 0`, phân giải `"domainIdentityRecognizeV2"`
 *         (`.bss 0x028780`); ngược lại phân giải `"domainIdentityRecognize"` (`.bss 0x028788`).
 *      3. Gọi hàm nhận diện tên miền với `url` bên trong `ExecuteWithSignalCrashGuard`.
 */
std::string RecognizeDomainIdentityViaPumbaa(const std::string& url) {
#if defined(__ANDROID__) || defined(__linux__)
    static void* s_pumbaa_handle = nullptr;
    using DomainRecognizeFn = std::string (*)(const std::string&);
    static DomainRecognizeFn s_recognize_v2 = nullptr;
    static DomainRecognizeFn s_recognize_v1 = nullptr;

    if (s_pumbaa_handle == nullptr) {
        s_pumbaa_handle = dlopen("libpumbaa-network.so", RTLD_LAZY);
    }
    if (s_pumbaa_handle == nullptr) {
        return std::string();
    }

    const int32_t strategy = GetGlobalRuntimeState().sdk_enable_strategy;
    DomainRecognizeFn target_fn = nullptr;
    if ((strategy & 0x02) != 0) {
        if (s_recognize_v2 == nullptr) {
            s_recognize_v2 = reinterpret_cast<DomainRecognizeFn>(
                dlsym(s_pumbaa_handle, "domainIdentityRecognizeV2"));
        }
        target_fn = s_recognize_v2;
    } else {
        if (s_recognize_v1 == nullptr) {
            s_recognize_v1 = reinterpret_cast<DomainRecognizeFn>(
                dlsym(s_pumbaa_handle, "domainIdentityRecognize"));
        }
        target_fn = s_recognize_v1;
    }

    if (target_fn == nullptr) {
        return std::string();
    }

    std::string recognized;
    ExecuteWithSignalCrashGuard(
        [&]() -> int32_t {
            recognized = target_fn(url);
            return 0;
        },
        0);
    return recognized;
#else
    (void)url;
    return std::string();
#endif
}

/**
 * [EN] Reconstructed from `0x00ffac..0x010920` (`handleByPumbaaForSandboxWrapper`):
 *      1. Lazily opens `"libpumbaa-network.so"` (`.bss 0x0287a8`) and resolves
 *         `"handleByPumbaaForSandbox"` (`.bss 0x0287b0`).
 *      2. Clones `headers` and inserts `"x-metasec-event-source" = "Native SO"`.
 *      3. Selects action code: if `pumbaa_strategy == 2`, uses `"4425"` (notify only);
 *         if `pumbaa_strategy == 3`, uses `"4427"` (intercept).
 *      4. Queries `"get_user_region"` (`0x01246c`) and sets `"is_in_sandbox_region"` to
 *         `"1"` if non-empty, else `"0"`.
 *      5. Calls `handleByPumbaaForSandbox(url, method, headers, body, metadata, action)`
 *         and measures elapsed microseconds (`steady_clock::now()`, `smulh` by
 *         `0x431bde82d7b634db >> 18`, i.e., `ns / 1000` or `ms`).
 *      6. Checks if `(result == 0x1002)` (`4098` = intercepted) and dispatches
 *         `SendReportAsync("NETWORK", ...)` (`0x00c5e0`).
 * [VN] Phục dựng từ `0x00ffac..0x010920` (`handleByPumbaaForSandboxWrapper`):
 *      1. Mở lười `"libpumbaa-network.so"` (`.bss 0x0287a8`) và phân giải
 *         `"handleByPumbaaForSandbox"` (`.bss 0x0287b0`).
 *      2. Sao chép `headers` và chèn `"x-metasec-event-source" = "Native SO"`.
 *      3. Chọn mã hành động: nếu `pumbaa_strategy == 2`, dùng `"4425"` (chỉ thông báo);
 *         nếu `pumbaa_strategy == 3`, dùng `"4427"` (chặn).
 *      4. Truy vấn `"get_user_region"` (`0x01246c`) và đặt `"is_in_sandbox_region"` bằng
 *         `"1"` nếu khác rỗng, ngược lại `"0"`.
 *      5. Gọi `handleByPumbaaForSandbox(url, method, headers, body, metadata, action)`
 *         và đo thời gian thực thi (`steady_clock::now()`, `smulh` bởi
 *         `0x431bde82d7b634db >> 18`).
 *      6. Kiểm tra `(result == 0x1002)` (`4098` = bị chặn) và gửi báo cáo bất đồng bộ
 *         `SendReportAsync("NETWORK", ...)` (`0x00c5e0`).
 */
int32_t InvokePumbaaSandboxValidate(
    const std::string& url,
    const std::string& method,
    const std::map<std::string, std::string>& headers,
    const std::string& body,
    const std::map<std::string, std::string>& metadata,
    int32_t pumbaa_strategy) {
    std::map<std::string, std::string> enriched_headers = headers;
    enriched_headers[kHeaderMetasecEventSource] = kEventSourceNativeSo;

    std::string action_code;
    if (pumbaa_strategy == 2) {
        action_code = kPumbaaActionNotifyOnly;
    } else if (pumbaa_strategy == 3) {
        action_code = kPumbaaActionIntercept;
    }

    std::map<std::string, std::string> enriched_meta = metadata;
    const std::string user_region = InvokeJavaPropertyCallback("get_user_region");
    enriched_meta["is_in_sandbox_region"] = user_region.empty() ? "0" : "1";

    const auto start_tp = std::chrono::steady_clock::now();
    int32_t pumbaa_rc = 0;

#if defined(__ANDROID__) || defined(__linux__)
    static void* s_pumbaa_handle = nullptr;
    using HandleByPumbaaFn = int32_t (*)(
        const std::string&,
        const std::string&,
        const std::map<std::string, std::string>&,
        const std::string&,
        std::map<std::string, std::string>&,
        const std::string&);
    static HandleByPumbaaFn s_handle_fn = nullptr;

    if (s_pumbaa_handle == nullptr) {
        s_pumbaa_handle = dlopen("libpumbaa-network.so", RTLD_LAZY);
    }
    if (s_pumbaa_handle != nullptr && s_handle_fn == nullptr) {
        s_handle_fn = reinterpret_cast<HandleByPumbaaFn>(
            dlsym(s_pumbaa_handle, "handleByPumbaaForSandbox"));
    }
    if (s_handle_fn != nullptr) {
        pumbaa_rc = ExecuteWithSignalCrashGuard(
            [&]() -> int32_t {
                return s_handle_fn(
                    url, method, enriched_headers, body, enriched_meta, action_code);
            },
            0);
    }
#endif

    const auto end_tp = std::chrono::steady_clock::now();
    const int64_t elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                   end_tp - start_tp)
                                   .count();

    int32_t dfid_int = -1;
    const auto dfid_it = enriched_meta.find(kHeaderDataflowId);
    if (dfid_it != enriched_meta.end()) {
        dfid_int = ParseDataflowIdStringToInt(dfid_it->second);
    }

    const std::string serialized_headers = SerializeHeadersToRfcString(headers);
    const bool is_intercepted = (pumbaa_rc == 0x1002);
    SendReportAsync(
        kSandboxChannelNetwork,
        url,
        method,
        serialized_headers,
        body,
        dfid_int,
        pumbaa_rc,
        is_intercepted,
        elapsed_ms);

    return is_intercepted ? 1 : 0;
}

/**
 * [EN] Reconstructed from `0x010af8..0x011174` (`callOrbuculumIsProceedRequestImpl`):
 *      1. Lazily opens `"liborbuculum.so"` (`.bss 0x028798`) and resolves
 *         `"orbuculumIsProceedRequestImpl"` (`.bss 0x0287a0`).
 *      2. Calls `orbuculumIsProceedRequestImpl(url, method, headers, body.c_str(),
 *         body_len, metadata)` inside `ExecuteWithSignalCrashGuard` (`0x010bf4..0x010ccc`).
 *      3. Computes elapsed duration (`steady_clock::now()` divided by `10^6` via
 *         `smulh 0x431bde82d7b634db >> 18` at `0x010db0`).
 *      4. Parses `"x-tt-dataflow-id"` from `metadata` via `ParseDataflowIdStringToInt` (`0x00ca60`),
 *         serializes headers via `SerializeHeadersToRfcString` (`0x010924`), and dispatches
 *         `SendReportAsync("NETWORK", ...)` (`0x00c5e0`).
 * [VN] Phục dựng từ `0x010af8..0x011174` (`callOrbuculumIsProceedRequestImpl`):
 *      1. Mở lười `"liborbuculum.so"` (`.bss 0x028798`) và phân giải
 *         `"orbuculumIsProceedRequestImpl"` (`.bss 0x0287a0`).
 *      2. Gọi `orbuculumIsProceedRequestImpl(url, method, headers, body.c_str(),
 *         body_len, metadata)` bên trong `ExecuteWithSignalCrashGuard` (`0x010bf4..0x010ccc`).
 *      3. Tính thời gian thực thi (`steady_clock::now()` chia `10^6` qua
 *         `smulh 0x431bde82d7b634db >> 18` tại `0x010db0`).
 *      4. Phân tích `"x-tt-dataflow-id"` từ `metadata` qua `ParseDataflowIdStringToInt` (`0x00ca60`),
 *         tuần tự hóa header qua `SerializeHeadersToRfcString` (`0x010924`), và gửi báo cáo
 *         bất đồng bộ `SendReportAsync("NETWORK", ...)` (`0x00c5e0`).
 */
int32_t InvokeOrbuculumProceedRequestImpl(
    const std::string& url,
    const std::string& method,
    const std::map<std::string, std::string>& headers,
    const std::string& body,
    size_t body_len,
    const std::map<std::string, std::string>& metadata) {
    const auto start_tp = std::chrono::steady_clock::now();
    int32_t orbu_rc = 0;

#if defined(__ANDROID__) || defined(__linux__)
    static void* s_orbu_handle = nullptr;
    using ProceedRequestImplFn = int32_t (*)(
        const std::string&,
        const std::string&,
        const std::map<std::string, std::string>&,
        const char*,
        size_t,
        const std::map<std::string, std::string>&);
    static ProceedRequestImplFn s_proceed_req_fn = nullptr;

    if (s_orbu_handle == nullptr) {
        s_orbu_handle = dlopen("liborbuculum.so", RTLD_LAZY);
    }
    if (s_orbu_handle != nullptr && s_proceed_req_fn == nullptr) {
        s_proceed_req_fn = reinterpret_cast<ProceedRequestImplFn>(
            dlsym(s_orbu_handle, "orbuculumIsProceedRequestImpl"));
    }
    if (s_proceed_req_fn != nullptr) {
        orbu_rc = ExecuteWithSignalCrashGuard(
            [&]() -> int32_t {
                return s_proceed_req_fn(
                    url, method, headers, body.c_str(), body_len, metadata);
            },
            0);
    }
#else
    (void)body_len;
#endif

    const auto end_tp = std::chrono::steady_clock::now();
    const int64_t elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                   end_tp - start_tp)
                                   .count();

    int32_t dfid_int = -1;
    const auto dfid_it = metadata.find(kHeaderDataflowId);
    if (dfid_it != metadata.end()) {
        dfid_int = ParseDataflowIdStringToInt(dfid_it->second);
    }

    const std::string serialized_headers = SerializeHeadersToRfcString(headers);
    SendReportAsync(
        kSandboxChannelNetwork,
        url,
        method,
        serialized_headers,
        body,
        dfid_int,
        orbu_rc,
        false,
        elapsed_ms);

    return orbu_rc;
}

/**
 * [EN] Reconstructed from `0x011808..0x011da0` (`orbuculumIsProceedResponseImpl`):
 *      1. Checks `sdk_enable_strategy & 0x01` (`tbz w8, #0, 0x11d4c`). If disabled, returns `0`.
 *      2. Validates `url != nullptr`, `method != nullptr`, and `IsUrlMatchingComplianceScheme(url)`.
 *      3. Parses `req_headers`, `resp_headers`, and `metadata_kv` via `ParseHttpHeadersUnified` (`0x00b99c`).
 *      4. Lazily opens `"liborbuculum.so"` and resolves `"orbuculumIsProceedResponseImpl"` (`.bss 0x028858`).
 *      5. Executes `orbuculumIsProceedResponseImpl` inside `ExecuteWithSignalCrashGuard`.
 * [VN] Phục dựng từ `0x011808..0x011da0` (`orbuculumIsProceedResponseImpl`):
 *      1. Kiểm tra `sdk_enable_strategy & 0x01` (`tbz w8, #0, 0x11d4c`). Nếu tắt, trả về `0`.
 *      2. Kiểm tra `url != nullptr`, `method != nullptr`, và `IsUrlMatchingComplianceScheme(url)`.
 *      3. Phân tích `req_headers`, `resp_headers`, và `metadata_kv` qua `ParseHttpHeadersUnified` (`0x00b99c`).
 *      4. Mở lười `"liborbuculum.so"` và phân giải `"orbuculumIsProceedResponseImpl"` (`.bss 0x028858`).
 *      5. Thực thi `orbuculumIsProceedResponseImpl` bên trong `ExecuteWithSignalCrashGuard`.
 */
int32_t InvokeOrbuculumProceedResponseImpl(
    const char* url,
    const char* method,
    const char* req_headers,
    const char* req_body,
    size_t req_body_len,
    int32_t status_code,
    const char* resp_headers,
    const char* resp_body,
    size_t resp_body_len,
    const char* metadata_kv) {
    const GlobalRuntimeState& state = GetGlobalRuntimeState();
    if ((state.sdk_enable_strategy & 0x01) == 0) {
        return 0;
    }
    if (url == nullptr || method == nullptr) {
        return 0;
    }

    const std::string url_str(url);
    if (!IsUrlMatchingComplianceScheme(url_str)) {
        return 0;
    }

    const std::string method_str(method);
    const std::map<std::string, std::string> parsed_req_headers =
        ParseHttpHeadersUnified(req_headers ? req_headers : "");
    const std::map<std::string, std::string> parsed_resp_headers =
        ParseHttpHeadersUnified(resp_headers ? resp_headers : "");
    const std::map<std::string, std::string> parsed_metadata =
        ParseHttpHeadersUnified(metadata_kv ? metadata_kv : "");

#if defined(__ANDROID__) || defined(__linux__)
    static void* s_orbu_handle = nullptr;
    using ProceedResponseImplFn = int32_t (*)(
        const std::string&,
        const std::string&,
        const std::map<std::string, std::string>&,
        const char*,
        size_t,
        int32_t,
        const std::map<std::string, std::string>&,
        const char*,
        size_t,
        const std::map<std::string, std::string>&);
    static ProceedResponseImplFn s_proceed_resp_fn = nullptr;

    if (s_orbu_handle == nullptr) {
        s_orbu_handle = dlopen("liborbuculum.so", RTLD_LAZY);
    }
    if (s_orbu_handle != nullptr && s_proceed_resp_fn == nullptr) {
        s_proceed_resp_fn = reinterpret_cast<ProceedResponseImplFn>(
            dlsym(s_orbu_handle, "orbuculumIsProceedResponseImpl"));
    }
    if (s_proceed_resp_fn != nullptr) {
        return ExecuteWithSignalCrashGuard(
            [&]() -> int32_t {
                return s_proceed_resp_fn(
                    url_str,
                    method_str,
                    parsed_req_headers,
                    req_body,
                    req_body_len,
                    status_code,
                    parsed_resp_headers,
                    resp_body,
                    resp_body_len,
                    parsed_metadata);
            },
            0);
    }
#else
    (void)req_body;
    (void)req_body_len;
    (void)status_code;
    (void)resp_body;
    (void)resp_body_len;
#endif
    return 0;
}

}  // namespace orbuculumadapter
}  // namespace opencut
}  // namespace nextai
