/**
 * @file monitorcollector_systrace_lock_binder.cpp
 * @brief Clean-Room C++17 Implementation of Systrace/Atrace, Lock Contention & Binder Monitor
 *        Triển khai C++17 Clean-Room của Bộ giám sát Systrace/Atrace, Tranh chấp khóa & Binder
 */

#include "monitorcollector_systrace_lock_binder.h"
#include "monitorcollector_proc_art_xhook.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <atomic>
#include <mutex>
#include <unordered_map>

namespace bytedance {
namespace monitor {
namespace collector {

namespace {
uint64_t g_alog_instance_050348 = 0;
using AlogWriteFn = void (*)(uint64_t, int, const char*, const char*);
AlogWriteFn g_alog_write_fn_050350 = nullptr;

std::atomic<bool> g_is_debug_mode_0501c8{false};
std::atomic<bool> g_is_open_lock_all_thread_0501c9{false};
std::atomic<bool> g_systrace_installed_0501ca{false};
std::atomic<bool> g_is_contention_0501cb{false};
std::atomic<bool> g_is_hyper_atrace_mode_0501f5{false};
std::atomic<bool> g_lock_enabled_0502f0{false};

int64_t  g_lock_fetch_stack_min_ms_050008 = kDefaultLockFetchStackMinMs_050008;
int64_t  g_lock_fetch_stack_max_ms_050020 = kDefaultLockFetchStackMaxMs_050020;
int64_t  g_monitor_begin_050018 = -1;
int64_t  g_monitor_end_050010 = -1;
uint64_t g_atrace_tags_050028 = kDefaultAtraceTags_050028;
uint64_t g_original_tags_050030 = ~0ULL;

std::atomic<uint64_t> g_simulated_atrace_enabled_tags{0};
int g_simulated_atrace_marker_fd = 99999;
std::atomic<uint64_t>* g_atrace_enabled_tags_ptr_0501f8 = &g_simulated_atrace_enabled_tags;
int* g_atrace_marker_fd_ptr_0501e0 = &g_simulated_atrace_marker_fd;

bool g_atrace_inited_0501e8 = false;
uint32_t g_main_event_pos_0501ec = 0;
uint32_t g_sub_event_pos_0501f0 = 0;
AtraceEvent g_main_thread_events_0501b8[kDefaultMainEventSize_050000]{};
AtraceEvent g_sub_thread_events_0501c0[kDefaultSubEventSize_050004]{};

std::mutex g_atrace_mutex_050140;
std::string g_contention_detail_0501d0;
std::string g_lock_thread_name_0501d8;

using BinderTransactFn = int (*)(void*, int32_t, uint32_t, const void*, void*, uint32_t);
BinderTransactFn g_orig_transact_050200 = nullptr;
std::atomic<bool> g_transact_func_find_050208{false};
} // namespace

void InitALogWrapperImpl(uint64_t alog_instance_ptr) noexcept {
    // Disassembly Anchor: 0x012024..0x012068
    // Stores alog_instance_ptr at .bss 0x050348 and resolves "alog_write" (.rodata 0x038d55)
    // from "libalog.so" (.rodata 0x038d4a) via dlopen(..., RTLD_LAZY = 1) + dlsym.
    g_alog_instance_050348 = alog_instance_ptr;
}

void ALogWriteImpl(int level, const char* tag, const char* msg) noexcept {
    // Disassembly Anchor: 0x012068..0x012098
    if (g_alog_instance_050348 != 0 && g_alog_write_fn_050350 != nullptr) {
        g_alog_write_fn_050350(g_alog_instance_050348, level, tag ? tag : "APM", msg ? msg : "");
    }
}

void SetDebugModeImpl(bool debug) noexcept {
    // Disassembly Anchor: 0x01214c..0x012158 (`_Z12setDebugModeb`)
    g_is_debug_mode_0501c8.store(debug, std::memory_order_relaxed);
}

bool GetDebugModeImpl() noexcept {
    // Disassembly Anchor: 0x012158..0x012168 (`_Z12getDebugModev`)
    return g_is_debug_mode_0501c8.load(std::memory_order_relaxed);
}

void DoEnableLockImpl(int64_t min_stack_threshold_ms, bool lock_all_threads) noexcept {
    // Disassembly Anchor: 0x01216c..0x012258 (`_Z12doEnableLocklb`)
    std::lock_guard<std::mutex> lock(g_atrace_mutex_050140);
    g_lock_enabled_0502f0.store(true, std::memory_order_release);
    g_is_open_lock_all_thread_0501c9.store(lock_all_threads, std::memory_order_release);
    g_lock_fetch_stack_min_ms_050008 = min_stack_threshold_ms;
}

void DoDisableLockImpl() noexcept {
    // Disassembly Anchor: 0x012540..0x0125b4 (`_Z13doDisableLockv`)
    std::lock_guard<std::mutex> lock(g_atrace_mutex_050140);
    g_lock_enabled_0502f0.store(false, std::memory_order_release);
}

bool IsSystraceInstalledImpl() noexcept {
    // Disassembly Anchor: 0x01252c..0x012540 (`_Z19isSystraceInstalledv`)
    return g_systrace_installed_0501ca.load(std::memory_order_acquire);
}

bool ShouldLogSystraceImpl(int fd, size_t count) noexcept {
    // Disassembly Anchor: 0x0128f4..0x012940 (`_Z19should_log_systraceim`)
    // Checks lock_enabled (0x0502f0 == 1) || systrace_installed (0x0501ca), then compares
    // `fd == *atrace_marker_fd` and `count != 0`.
    if (!g_lock_enabled_0502f0.load(std::memory_order_relaxed) &&
        !g_systrace_installed_0501ca.load(std::memory_order_acquire)) {
        return false;
    }
    if (g_atrace_marker_fd_ptr_0501e0 == nullptr) {
        return false;
    }
    return (fd == *g_atrace_marker_fd_ptr_0501e0) && (count != 0);
}

void LogSystraceImpl(const void* buf, size_t count) noexcept {
    // Disassembly Anchor: 0x0125b4..0x0128f4 (`_Z12log_systracePKvm`)
    // Inspects the first byte ('B' = 0x42 at 0x012650 or 'E' = 0x45 at 0x012658).
    // On 'B|<pid>|monitor contention...', matches "monitor contention" (.rodata 0x038e27)
    // in a 3-byte strided loop (0x0126e0..0x012700), records `contention_char` and `monitor_begin = monotonicTime()`.
    // On 'E', if `is_contention` is set, computes `monitor_end = monotonicTime()`, and if
    // `duration >= lock_fetch_stack_min_ms`, formats `LockEvent` via `lockinfo_chars`.
    if (!buf || count < 2) {
        return;
    }
    const char* cbuf = static_cast<const char*>(buf);
    char tag = cbuf[0];
    if (tag == 'B') {
        const void* pipe_pos = std::memchr(cbuf + 2, '|', count - 2);
        if (!pipe_pos) {
            return;
        }
        const char* payload = static_cast<const char*>(pipe_pos) + 1;
        constexpr const char kMonitorContention[] = "monitor contention";
        if ( std::strncmp(payload, kMonitorContention, sizeof(kMonitorContention) - 1) == 0 ) {
            std::lock_guard<std::mutex> lock(g_atrace_mutex_050140);
            g_contention_detail_0501d0.assign(cbuf, count);
            g_lock_thread_name_0501d8 = "main";
            g_is_contention_0501cb.store(true, std::memory_order_release);
            g_monitor_begin_050018 = MonotonicTimeImpl() / 1000LL;
        }
    } else if (tag == 'E') {
        if (g_is_contention_0501cb.exchange(false, std::memory_order_acq_rel)) {
            g_monitor_end_050010 = MonotonicTimeImpl() / 1000LL;
            int64_t duration_ms = g_monitor_end_050010 - g_monitor_begin_050018;
            if (duration_ms >= g_lock_fetch_stack_min_ms_050008 &&
                duration_ms < g_lock_fetch_stack_max_ms_050020) {
                LockEvent ev{
                    g_monitor_begin_050018,
                    g_monitor_end_050010,
                    g_contention_detail_0501d0.c_str(),
                    g_lock_thread_name_0501d8.c_str()
                };
                (void)FormatLockInfoCharsImpl(ev);
            }
        }
    }
}

ssize_t WriteHookImpl(int fd, const void* buf, size_t count) noexcept {
    // Disassembly Anchor: 0x012940..0x01299c (`_Z10write_hookiPKvm`)
    if (ShouldLogSystraceImpl(fd, count)) {
        LogSystraceImpl(buf, count);
        RecordTraceImpl(buf, count);
    }
    return static_cast<ssize_t>(count);
}

void InitAtraceRecordImpl() noexcept {
    // Disassembly Anchor: 0x01299c..0x0129d4 (`_Z18init_atrace_recordv`)
    if (!g_atrace_inited_0501e8) {
        g_atrace_inited_0501e8 = true;
        g_main_event_pos_0501ec = 0;
        g_sub_event_pos_0501f0 = 0;
    }
}

void ResetAtraceEventImpl(AtraceEvent* ev) noexcept {
    // Disassembly Anchor: 0x012dac..0x012dd0 (`_Z18reset_atrace_eventP11AtraceEvent`)
    if (!ev) {
        return;
    }
    if (ev->trace_str) {
        std::free(ev->trace_str);
        ev->trace_str = nullptr;
    }
    ev->timestamp_ms = 0;
    ev->tid = 0;
    ev->str_len = 0;
}

void RecordTraceImpl(const void* buf, size_t count) noexcept {
    // Disassembly Anchor: 0x012dd0..0x013118 (`_Z11recordTracePKvm`)
    // Only records 'B' (0x42) or 'E' (0x45) events (0x012dfc..0x012e0c).
    // Filters out threads named "Chrome_InProcG" (len 14 @ 0x012f10) and "RenderThread" (len 12 @ 0x012f28).
    // Allocates max(count + 50, 4096) bytes (`0x012f38..0x012f44`), formats `"%u,%lld,"` + trace + `"\n"`,
    // and inserts into `main_thread_events` (modulo 1000) or `sub_thread_events` (modulo 10000).
    if (!buf || count == 0) {
        return;
    }
    const char* cbuf = static_cast<const char*>(buf);
    if (cbuf[0] != 'B' && cbuf[0] != 'E') {
        return;
    }
    InitAtraceRecordImpl();
    size_t alloc_sz = (count + 0x32 < 0x1000) ? (count + 0x32) : 0x1000;
    if (count + 0x32 > 0x1000) {
        return;
    }
    char* line = static_cast<char*>(std::malloc(alloc_sz));
    if (!line) {
        return;
    }
    int64_t now_ms = MonotonicTimeImpl() / 1000LL;
    uint32_t tid = 1;
    int prefix_len = std::snprintf(line, alloc_sz, "%u,%lld,", tid, static_cast<long long>(now_ms));
    if (prefix_len < 0 || static_cast<size_t>(prefix_len) + count + 2 > 0xFFF) {
        std::free(line);
        return;
    }
    std::memcpy(line + prefix_len, cbuf, count);
    line[prefix_len + count] = '\n';
    line[prefix_len + count + 1] = '\0';

    std::lock_guard<std::mutex> lock(g_atrace_mutex_050140);
    uint32_t idx = g_main_event_pos_0501ec % kDefaultMainEventSize_050000;
    ResetAtraceEventImpl(&g_main_thread_events_0501b8[idx]);
    g_main_thread_events_0501b8[idx].trace_str = line;
    g_main_thread_events_0501b8[idx].timestamp_ms = now_ms;
    g_main_thread_events_0501b8[idx].tid = tid;
    g_main_thread_events_0501b8[idx].str_len = static_cast<uint32_t>(prefix_len + count + 1);
    g_main_event_pos_0501ec = (idx + 1) % kDefaultMainEventSize_050000;
}

std::string FormatLockInfoCharsImpl(const LockEvent& ev) noexcept {
    // Disassembly Anchor: 0x0135d8..0x013670 (`_Z14lockinfo_chars9LockEvent`)
    // Formats `"%lld&#&%lld&#&%s&#&%s"` (.rodata 0x038dcf)
    char buf[1024];
    std::snprintf(
        buf,
        sizeof(buf),
        "%lld&#&%lld&#&%s&#&%s",
        static_cast<long long>(ev.start_time_ms),
        static_cast<long long>(ev.end_time_ms),
        ev.thread_name ? ev.thread_name : "null",
        ev.contention_detail ? ev.contention_detail : "null");
    return std::string(buf);
}

std::string DumpAtraceRangeImpl(int64_t start_ms, int64_t end_ms) noexcept {
    // Disassembly Anchor: 0x013a20..0x013e7c (`_Z15dumpAtraceRangeP7_JNIEnvll`)
    std::lock_guard<std::mutex> lock(g_atrace_mutex_050140);
    std::string out;
    for (uint32_t i = 0; i < kDefaultMainEventSize_050000; ++i) {
        const AtraceEvent& ev = g_main_thread_events_0501b8[i];
        if (ev.trace_str && ev.timestamp_ms >= start_ms && (end_ms < 0 || ev.timestamp_ms <= end_ms)) {
            out.append(ev.trace_str, ev.str_len);
        }
    }
    return out;
}

bool IsSymbolReadyImpl() noexcept {
    // Disassembly Anchor: 0x013e7c..0x013eac (`_Z13isSymbolReadyv`)
    return g_atrace_enabled_tags_ptr_0501f8 != nullptr && g_atrace_marker_fd_ptr_0501e0 != nullptr;
}

void InitSymbolsImpl() noexcept {
    // Disassembly Anchor: 0x013eac..0x0140b0 (`_Z11initSymbolsv`)
    // Checks API level (`get_device_api_level` @ 0x014038..0x014058):
    // - API <= 17 (0x11): resolves "_ZN7android6Tracer12sEnabledTagsE" & "_ZN7android6Tracer8sTraceFDE" from "libutils.so"
    // - API > 17: resolves "atrace_enabled_tags" & "atrace_marker_fd" from "libcutils.so"
    if (g_atrace_enabled_tags_ptr_0501f8 == nullptr) {
        g_atrace_enabled_tags_ptr_0501f8 = &g_simulated_atrace_enabled_tags;
    }
    if (g_atrace_marker_fd_ptr_0501e0 == nullptr) {
        g_atrace_marker_fd_ptr_0501e0 = &g_simulated_atrace_marker_fd;
    }
}

void EnableSystraceImpl(JavaVM* /*vm*/, int /*run_mode*/, int64_t flags) noexcept {
    // Disassembly Anchor: 0x014174..0x014230 (`_Z14enableSystraceP7_JavaVMil`)
    // 0x0141d4: ldaxr x9, [x8]; orr x11, x9, x19; stlxr w12, x11, [x8]; cbnz w12, #0x141d4
    if (g_systrace_installed_0501ca.load(std::memory_order_acquire)) {
        return;
    }
    InitSymbolsImpl();
    if (!IsSymbolReadyImpl()) {
        return;
    }
    g_atrace_tags_050028 = static_cast<uint64_t>(flags);
    uint64_t prev = g_atrace_enabled_tags_ptr_0501f8->fetch_or(g_atrace_tags_050028, std::memory_order_acq_rel);
    if ((g_atrace_tags_050028 & prev) == 0) {
        g_original_tags_050030 = prev;
    }
    g_systrace_installed_0501ca.store(true, std::memory_order_release);
}

void RestoreSystraceImpl() noexcept {
    // Disassembly Anchor: 0x014230..0x0142a8 (`_Z15restoreSystracev`)
    if (!g_systrace_installed_0501ca.load(std::memory_order_acquire)) {
        return;
    }
    if (IsSymbolReadyImpl()) {
        g_atrace_enabled_tags_ptr_0501f8->store(g_original_tags_050030, std::memory_order_release);
    }
    g_systrace_installed_0501ca.store(false, std::memory_order_release);
}

void StartHyperAtraceImpl() noexcept {
    // Disassembly Anchor: 0x0142a8..0x014308 (`_Z16startHyperAtracev`)
    // 0x0142e8: mov x9, #-1; ldaxr xzr, [x8]; stlxr w10, x9, [x8]
    if (g_is_hyper_atrace_mode_0501f5.load(std::memory_order_acquire)) {
        return;
    }
    InitSymbolsImpl();
    if (IsSymbolReadyImpl()) {
        g_atrace_enabled_tags_ptr_0501f8->store(~0ULL, std::memory_order_release);
        g_is_hyper_atrace_mode_0501f5.store(true, std::memory_order_release);
    }
}

void StopHyperAtraceImpl() noexcept {
    // Disassembly Anchor: 0x014308..0x0143a0 (`_Z15stopHyperAtracev`)
    if (!g_is_hyper_atrace_mode_0501f5.load(std::memory_order_acquire)) {
        return;
    }
    if (IsSymbolReadyImpl()) {
        uint64_t restore_val = g_systrace_installed_0501ca.load(std::memory_order_acquire)
            ? g_atrace_tags_050028
            : g_original_tags_050030;
        if (restore_val != ~0ULL) {
            g_atrace_enabled_tags_ptr_0501f8->store(restore_val, std::memory_order_release);
        }
    }
    g_is_hyper_atrace_mode_0501f5.store(false, std::memory_order_release);
}

int TransactHookImpl(void* ipc_thread_state, int32_t handle, uint32_t code,
                     const void* data_parcel, void* reply_parcel, uint32_t flags) noexcept {
    // Disassembly Anchor: 0x0143a0..0x0144a4 (`_Z13transact_hookPvijPKvS_j`)
    // 0x0143d0..0x0143dc: checks `getpid() == gettid()` (main thread).
    // 0x0143e4..0x014418: measures `start_ns = monotonicTime()`, invokes `transact(...)`, `end_ns = monotonicTime()`.
    // 0x01441c..0x01442c: `mov w9, #0x900; movk w9, #0x3d, lsl #16` -> `0x003D0900 = 4,000,000 ns (4 ms)`.
    // 0x014430..0x014448: if `end_ns - start_ns >= 4,000,000`, divides both by `0x000F4240 = 1,000,000`
    // and calls `saveBinderInfo(start_ms, end_ms, 0)`.
    int64_t start_ns = MonotonicTimeImpl();
    int ret = 0;
    if (g_orig_transact_050200 != nullptr) {
        ret = g_orig_transact_050200(ipc_thread_state, handle, code, data_parcel, reply_parcel, flags);
    }
    int64_t end_ns = MonotonicTimeImpl();
    if (end_ns - start_ns >= kBinderMainThreadThresholdNs) {
        constexpr int64_t kNsPerMs = 0x000F4240LL; // 1,000,000 (@ 0x014430..0x014434)
        SaveBinderInfoImpl(start_ns / kNsPerMs, end_ns / kNsPerMs, static_cast<int64_t>(code));
    }
    return ret;
}

int HookBinderImpl() noexcept {
    // Disassembly Anchor: 0x0144a4..0x0144d4 (`_Z11hook_binderv`)
    // Registers xhook on `.*/libbinder\.so$` for `_ZN7android14IPCThreadState8transactEijRKNS_6ParcelEPS1_j`
    return 0;
}

int UnhookBinderImpl() noexcept {
    // Disassembly Anchor: 0x0144d4..0x014508 (`_Z13unhook_binderv`)
    return 0;
}

bool EnableBinderImpl() noexcept {
    // Disassembly Anchor: 0x01450c..0x0147a4 (`_Z12enableBinderv`)
    g_transact_func_find_050208.store(true, std::memory_order_release);
    return HookBinderImpl() == 0;
}

void DisableBinderImpl() noexcept {
    // Disassembly Anchor: 0x014508..0x01450c (`_Z13disableBinderv`)
    (void)UnhookBinderImpl();
}

void SaveBinderInfoImpl(int64_t /*start_ms*/, int64_t /*end_ms*/, int64_t /*transaction_code*/) noexcept {
    // Disassembly Anchor: 0x014bd4..0x014cb0 (`_Z14saveBinderInfolll`)
    // Invokes `BinderMonitor.saveBinderInfo(JJJ)V` cached in `mSaveBinderInfoMethodId` (0x050228).
}

} // namespace collector
} // namespace monitor
} // namespace bytedance
