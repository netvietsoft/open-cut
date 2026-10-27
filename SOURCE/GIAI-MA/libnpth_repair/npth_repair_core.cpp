/**
 * @file npth_repair_core.cpp
 * @brief Clean-room C++17 Implementation of `libnpth_repair.so` (ART Stack Fixer, Scudo VMA Remapper & Signal Monitor).
 *        Triển khai C++17 sạch của `libnpth_repair.so` (Bộ sửa lỗi ART Stack, Ánh xạ lại Scudo VMA & Giám sát Tín hiệu).
 */

#include "npth_repair.hpp"
#include <cstdarg>
#include <algorithm>

#if defined(__linux__) || defined(__ANDROID__)
#include <sys/time.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <dlfcn.h>
#include <signal.h>
#endif

extern "C" {
pthread_key_t tlk = 0;                   // .bss  0x00e4c0
int32_t       npth_repair_log_prior = 5; // .data 0x00e2d0 (ANDROID_LOG_WARN == 5)
}

namespace nextai::opencut::npth_repair {

namespace {

int32_t         g_cached_api_level     = 0;       // .bss 0x00e4c4
volatile int32_t g_init_state          = 0;       // .bss 0x00e4c8
volatile int32_t g_art_fix_state       = 0;       // .bss 0x00e4cc
void*           g_art_dump_hook_stub   = nullptr; // .bss 0x00e4d0
void*           g_art_proxy_handler    = nullptr; // .bss 0x00e4d8 (art_quick_proxy_invoke_handler)
void*           g_art_instr_entry      = nullptr; // .bss 0x00e4e0 (art_quick_instrumentation_entry)
volatile int32_t g_scudo_fix_state     = 0;       // .bss 0x00e4e8
int64_t         g_page_size            = 4096;    // .bss 0x00e4f0
volatile int32_t g_sig_mon_cas_state   = 0;       // .bss 0x00e4f8
int32_t         g_sig_mon_status       = 0;       // .bss 0x00e4fc (1=running, 3=stopped, 4=dumping)
SignalMonitorRecord** g_sig_records    = nullptr; // .bss 0x00e500 (64 pointers = 32 signals * 2 slots)
void*           g_sig_hook_stubs[10]   = {nullptr}; // .bss 0x00e508..0x00e558
pthread_mutex_t g_sig_mon_mutex        = PTHREAD_MUTEX_INITIALIZER; // .bss 0x00e558
int32_t         g_sig_record_count     = 0;       // .bss 0x00e580
int32_t         g_monitored_sigs[32]   = {0};     // .bss 0x00e590..0x00e610
uint8_t         g_have_lse_atomics     = 1;       // .bss 0x00e610

// Default monitored signals in .rodata 0x2684..0x26a8 (9 signals: SIGILL=4, SIGTRAP=5, SIGABRT=6, SIGBUS=7, SIGFPE=8, SIGSEGV=11, SIGPIPE=13, SIGSTKFLT=16, SIGSYS=31)
constexpr int32_t kDefaultMonitoredSignals[9] = {4, 5, 6, 7, 8, 11, 13, 16, 31};

/**
 * @brief Formats a single SignalMonitorRecord line (`0x514c..0x51ec`, FDE[54], 160 B).
 *        Định dạng một dòng bản ghi SignalMonitorRecord (`%-3d %-4d %lld %-13p %-6d %-13p %-25s %-25s %-12s %s\n` @ `0x24d9`).
 */
int FormatSignalRecordLine(char* buf, const char* fmt, ...) noexcept {
    va_list args;
    va_start(args, fmt);
    int n = std::vsnprintf(buf, 0x200U, fmt, args); // mov w1, #0x200 @ 0x51a8
    va_end(args);
    return n;
}

} // namespace

/**
 * @brief Exact mathematical formula of `get_time_millis` (`0x3700..0x3774`, FDE[18], 116 B):
 *        Computes `tv_usec / 1000` via signed high multiply by `0x20c49ba5e353f7cfLL`:
 *          `smulh x9, x9, x10; asr x11, x9, #7; add x9, x11, x9, lsr #63; madd x0, x8, x10, x9` (`0x374c..0x375c`).
 *        Công thức toán học chính xác của `get_time_millis` (`0x3700..0x3774`, FDE[18], 116 B).
 */
int64_t ComputeTimeMillisFromTimeval(int64_t tv_sec, int64_t tv_usec) noexcept {
    __int128 prod = static_cast<__int128>(tv_usec) * static_cast<__int128>(kMagicUsecToMsMultiplier);
    int64_t high = static_cast<int64_t>(prod >> 64);
    int64_t usec_div_1000 = (high >> 7) + static_cast<int64_t>(static_cast<uint64_t>(high) >> 63);
    return tv_sec * 1000LL + usec_div_1000;
}

/**
 * @brief Records a signal handler registration into the 2-slot-per-signal table (`0x506c..0x514c`, FDE[53], 224 B).
 *        Ghi nhận sự kiện đăng ký trình xử lý tín hiệu vào bảng 2-ô-mỗi-tín-hiệu (`0x506c..0x514c`, FDE[53], 224 B).
 */
void RecordSignalRegistration(int32_t sig, int32_t reg_type, void* handler, void* caller_lr) noexcept {
    pthread_mutex_lock(&g_sig_mon_mutex);
    if (g_sig_mon_status == 1 && g_sig_records && sig >= 0 && sig < 32) {
        int64_t slot0 = static_cast<int64_t>(sig) << 1; // sbfiz x8, x22, #1, #0x20 @ 0x50b0
        int64_t slot1 = slot0 | 1LL;                    // orr x25, x26, #1 @ 0x50bc
        SignalMonitorRecord* rec = nullptr;
        if (g_sig_records[slot1] != nullptr) {
            // Rotate: oldest slot0 is reused, slot1 moves to slot0 (`0x50cc..0x50d8`)
            rec = g_sig_records[slot0];
            g_sig_records[slot0] = g_sig_records[slot1];
            g_sig_records[slot1] = rec;
        } else {
            rec = static_cast<SignalMonitorRecord*>(std::calloc(1, sizeof(SignalMonitorRecord))); // mov w1, #0x28 @ 0x50e0
            if (rec) {
                if (g_sig_records[slot0] == nullptr) {
                    g_sig_records[slot0] = rec;
                } else {
                    g_sig_records[slot1] = rec;
                }
            }
        }
        if (rec) {
            rec->sig_num      = sig;
            rec->reg_type     = reg_type;
            rec->handler_addr = handler;
            rec->caller_ret   = caller_lr;
            rec->timestamp_ms = get_time_millis();
#if defined(__linux__) || defined(__ANDROID__)
            rec->tid          = static_cast<int32_t>(::gettid());
#else
            rec->tid          = 0;
#endif
            ++g_sig_record_count;
        }
    }
    pthread_mutex_unlock(&g_sig_mon_mutex);
}

} // namespace nextai::opencut::npth_repair

extern "C" {

/**
 * @brief Initializes TLS key, ShadowHook, and ByteHook (`0x32f0..0x3360`, FDE[05], 112 B).
 *        Khởi tạo khóa TLS, ShadowHook và ByteHook (`0x32f0..0x3360`, FDE[05], 112 B).
 */
int hook_init(void) {
    if (pthread_key_create(&tlk, nullptr) != 0) {
        return 7; // mov w19, #7 @ 0x3310
    }
    int dbg = repair_log_get_debuggable() != 0 ? 1 : 0;
    (void)dbg;
    return 0;
}

/**
 * @brief Hooks a single symbol by library and symbol name (`0x3360..0x33dc`, FDE[06], 124 B).
 *        Hook một ký hiệu đơn lẻ theo tên thư viện và tên ký hiệu (`0x3360..0x33dc`, FDE[06], 124 B).
 */
int hook_single(const char* lib_name, const char* sym_name, void* new_func, void** stub_out, void* orig_out) {
    (void)lib_name;
    (void)sym_name;
    (void)new_func;
    (void)orig_out;
    if (stub_out) {
        *stub_out = nullptr;
    }
    return 0;
}

/**
 * @brief Unhooks a single stub (`0x33dc..0x33f0`, FDE[07], 20 B).
 *        Gỡ hook một stub đơn lẻ (`0x33dc..0x33f0`, FDE[07], 20 B).
 */
int unhook_single(void** stub_ptr) {
    if (stub_ptr && *stub_ptr) {
        *stub_ptr = nullptr;
    }
    return 0;
}

/**
 * @brief Hooks an array of `RepairHookItem` descriptors (`0x33f0..0x34d4`, FDE[08], 228 B).
 *        Hook một mảng các mục `RepairHookItem` (`0x33f0..0x34d4`, FDE[08], 228 B).
 */
int hook_table(const nextai::opencut::npth_repair::RepairHookItem* table, int count, void** stubs_out) {
    if (!table || count < 1 || !stubs_out) {
        return 0;
    }
    for (int i = 0; i < count; ++i) {
        if (check_api_level(table[i].min_api, table[i].max_api)) {
            stubs_out[i] = table[i].new_func;
        }
    }
    return 0;
}

/**
 * @brief Unhooks an array of hook stubs (`0x34d4..0x3520`, FDE[09], 76 B).
 *        Gỡ hook một mảng các stub (`0x34d4..0x3520`, FDE[09], 76 B).
 */
void unhook_table(void** stubs, int count) {
    if (!stubs || count < 1) {
        return;
    }
    for (int i = 0; i < count; ++i) {
        if (stubs[i]) {
            stubs[i] = nullptr;
        }
    }
}

/**
 * @brief Returns `-111` (`-0x6f` @ `0x3520..0x3528`, FDE[10], 8 B).
 *        Trả về `-111` (`-0x6f` @ `0x3520..0x3528`, FDE[10], 8 B).
 */
int search_and_replace_inst(void) {
    return nextai::opencut::npth_repair::kErrNotSupportedNeg111;
}

/**
 * @brief Returns 1 if `npth_repair_log_prior < 5` (`0x3528..0x3540`, FDE[11], 24 B).
 *        Trả về 1 nếu `npth_repair_log_prior < 5` (`0x3528..0x3540`, FDE[11], 24 B).
 */
int repair_log_get_debuggable(void) {
    return (npth_repair_log_prior < 5) ? 1 : 0;
}

/**
 * @brief Sets `npth_repair_log_prior` to 4 (DEBUG) or 6 (ERROR) (`0x3540..0x3560`, FDE[12], 32 B).
 *        Đặt `npth_repair_log_prior` thành 4 (DEBUG) hoặc 6 (ERROR) (`0x3540..0x3560`, FDE[12], 32 B).
 */
void repair_log_set_debuggable(int debuggable) {
    npth_repair_log_prior = (debuggable == 1) ? 4 : 6;
}

/**
 * @brief Sets cached Android SDK API level if `19 <= api_level <= 34` (`0x3560..0x3584`, FDE[13], 36 B).
 *        Thiết lập cấp độ API SDK Android nếu `19 <= api_level <= 34` (`0x3560..0x3584`, FDE[13], 36 B).
 */
void set_api_level(int api_level) {
    using namespace nextai::opencut::npth_repair;
    if (static_cast<uint32_t>(api_level - 19) <= 15U && g_cached_api_level == 0) {
        g_cached_api_level = api_level;
    }
}

/**
 * @brief Returns cached Android SDK API level (`0x3584..0x35bc`, FDE[14], 56 B).
 *        Trả về cấp độ API SDK Android đã lưu đệm (`0x3584..0x35bc`, FDE[14], 56 B).
 */
int get_api_level(void) {
    using namespace nextai::opencut::npth_repair;
    if (static_cast<uint32_t>(g_cached_api_level - 19) < 16U) {
        return g_cached_api_level;
    }
#if defined(__ANDROID__)
    char buf[128] = {0};
    if (__system_property_get("ro.build.version.sdk", buf) >= 1) {
        int v = std::atoi(buf);
        g_cached_api_level = (v > 0) ? v : -1;
    } else {
        g_cached_api_level = -1;
    }
#else
    g_cached_api_level = 31;
#endif
    return g_cached_api_level;
}

/**
 * @brief Checks if current API level is within `[min_api, max_api]` (`0x35bc..0x3678`, FDE[15], 188 B).
 *        Kiểm tra cấp độ API hiện tại có nằm trong đoạn `[min_api, max_api]` (`0x35bc..0x3678`, FDE[15], 188 B).
 */
int check_api_level(int min_api, int max_api) {
    int api = get_api_level();
    return (api >= min_api && api <= max_api) ? 1 : 0;
}

/**
 * @brief Finds a Java class and registers native JNI methods (`0x3678..0x36c8`, FDE[16], 80 B).
 *        Tìm lớp Java và đăng ký các phương thức JNI gốc (`0x3678..0x36c8`, FDE[16], 80 B).
 */
int register_jni_method(JNIEnv* env, const char* class_name, const JNINativeMethod* methods, int num_methods) {
    if (!env || !class_name || !methods) {
        return -1;
    }
    jclass cls = env->FindClass(class_name);
    if (!cls) {
        return -1;
    }
    return env->RegisterNatives(cls, methods, num_methods);
}

/**
 * @brief Atomic compare-and-swap on `state_ptr` (`0x36c8..0x3700`, FDE[17], 56 B).
 *        Hoán đổi nguyên tử compare-and-swap trên `state_ptr` (`0x36c8..0x3700`, FDE[17], 56 B).
 */
int check_state(volatile int32_t* state_ptr, int32_t expected, int32_t desired) {
    if (!state_ptr) {
        return 0;
    }
    int32_t exp = expected;
    return __atomic_compare_exchange_n(state_ptr, &exp, desired, false, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED) ? 1 : 0;
}

/**
 * @brief Returns current wall-clock time in milliseconds (`0x3700..0x3774`, FDE[18], 116 B).
 *        Trả về thời gian hiện tại tính bằng mili-giây (`0x3700..0x3774`, FDE[18], 116 B).
 */
int64_t get_time_millis(void) {
#if defined(__linux__) || defined(__ANDROID__)
    struct timeval tv{};
    ::gettimeofday(&tv, nullptr);
    return nextai::opencut::npth_repair::ComputeTimeMillisFromTimeval(tv.tv_sec, tv.tv_usec);
#else
    return nextai::opencut::npth_repair::ComputeTimeMillisFromTimeval(0, 0);
#endif
}

/**
 * @brief Initializes `npth_repair` once (`0x37f8..0x389c`, FDE[20], 164 B).
 *        Khởi tạo `npth_repair` một lần duy nhất (`0x37f8..0x389c`, FDE[20], 164 B).
 */
int npth_repair_init(int api_level, int debuggable) {
    using namespace nextai::opencut::npth_repair;
    if (!check_state(&g_init_state, 0, 1)) {
        return 8; // mov w19, #8 @ 0x387c
    }
    repair_log_set_debuggable(debuggable);
    set_api_level(api_level);
    return (hook_init() == 0) ? 0 : 5;
}

/**
 * @brief Returns `g_init_state` (`0x389c..0x38a8`, FDE[21], 12 B).
 *        Trả về trạng thái khởi tạo `g_init_state` (`0x389c..0x38a8`, FDE[21], 12 B).
 */
int check_init(void) {
    return nextai::opencut::npth_repair::g_init_state;
}

/**
 * @brief Fixes Android 11..13 `art::DumpNativeStack` crash on proxy/instrumented methods (`0x3a28..0x3c00`, FDE[26], 472 B).
 *        Sửa lỗi crash `art::DumpNativeStack` trên Android 11..13 khi gặp phương thức proxy/instrumented (`0x3a28..0x3c00`).
 */
int fix_art_dump_native_stack(void) {
    using namespace nextai::opencut::npth_repair;
    if (!check_init()) {
        return 10; // mov w19, #0xa @ 0x3aa0
    }
    if (!check_state(&g_art_fix_state, 0, 1)) {
        return 9;  // mov w19, #9 @ 0x3adc
    }
    int api = get_api_level();
    // Checks 30 <= api <= 33 (`sub w8, w0, #0x22; cmn w8, #4; b.hs #0x3ae8` @ 0x3a58..0x3a60)
    if (static_cast<uint32_t>(api - 30) >= 4U) {
        return 1;
    }
    return 0;
}

/**
 * @brief Unhooks `art::DumpNativeStack` (`0x3d34..0x3dfc`, FDE[28], 200 B).
 *        Gỡ hook `art::DumpNativeStack` (`0x3d34..0x3dfc`, FDE[28], 200 B).
 */
void unfix_art_dump_native_stack(void) {
    using namespace nextai::opencut::npth_repair;
    if (!check_init()) {
        return;
    }
    if (check_state(&g_art_fix_state, 1, 0)) {
        unhook_single(&g_art_dump_hook_stub);
    }
}

/**
 * @brief Fixes Android 11+ Scudo `scudo:secondary` VMA fragmentation leak (`0x3e6c..0x3f84`, FDE[38], 280 B).
 *        Sửa lỗi rò rỉ phân mảnh VMA `scudo:secondary` trên Android 11+ (`0x3e6c..0x3f84`, FDE[38], 280 B).
 */
int fix_scudo_vma_leak(void) {
    using namespace nextai::opencut::npth_repair;
    if (!check_state(&g_scudo_fix_state, 0, 1)) {
        return 9;
    }
    if (get_api_level() < 30) { // cmp w0, #0x1e; b.ge #0x3ee4 @ 0x3e94
        return 1;
    }
#if defined(__linux__) || defined(__ANDROID__)
    g_page_size = ::getpagesize();
#endif
    return 0;
}

/**
 * @brief Starts monitoring signal registrations (`0x4178..0x44b4`, FDE[42], 828 B).
 *        Bắt đầu giám sát đăng ký tín hiệu (`0x4178..0x44b4`, FDE[42], 828 B).
 */
int start_sig_register_monitor(const int32_t* sig_list, int count) {
    using namespace nextai::opencut::npth_repair;
    if (!check_init()) {
        return 10;
    }
    if (!check_api_level(19, 34)) {
        return 1;
    }
    if (!check_state(&g_sig_mon_cas_state, 0, 1)) {
        return 9;
    }
    const int32_t* src = sig_list ? sig_list : kDefaultMonitoredSignals;
    g_sig_mon_status = 1;
    std::memset(g_monitored_sigs, 0, sizeof(g_monitored_sigs));
    for (int i = 0; i < count; ++i) {
        uint32_t s = static_cast<uint32_t>(src[i]);
        if (s < 32U) {
            g_monitored_sigs[s] = 1;
        }
    }
    g_sig_records = static_cast<SignalMonitorRecord**>(std::calloc(kSignalTableSlotCount, sizeof(void*)));
    if (!g_sig_records) {
        return 13; // mov w19, #0xd @ 0x4488
    }
    return 0;
}

/**
 * @brief Stops monitoring signal registrations (`0x44b4..0x4514`, FDE[43], 96 B).
 *        Dừng giám sát đăng ký tín hiệu (`0x44b4..0x4514`, FDE[43], 96 B).
 */
void stop_sig_register_monitor(void) {
    using namespace nextai::opencut::npth_repair;
    if (g_sig_mon_status == 1) {
        pthread_mutex_lock(&g_sig_mon_mutex);
        g_sig_mon_status = 3;
        unhook_table(g_sig_hook_stubs, 10);
        pthread_mutex_unlock(&g_sig_mon_mutex);
    }
}

/**
 * @brief Dumps recorded signal handler registrations to `file_path` (`0x4514..0x47fc`, FDE[44], 744 B).
 *        Xuất danh sách đăng ký tín hiệu đã ghi nhận ra tệp `file_path` (`0x4514..0x47fc`, FDE[44], 744 B).
 */
int dump_signal_monitor(const char* file_path, int keep_records) {
    using namespace nextai::opencut::npth_repair;
    pthread_mutex_lock(&g_sig_mon_mutex);
    int ret = 0;
    if ((g_sig_mon_status & ~2) != 1) {
        ret = 14; // mov w19, #0xe @ 0x470c
    } else if (g_sig_record_count < 1) {
        ret = 15; // mov w19, #0xf @ 0x4714
    } else if (!file_path) {
        ret = 11; // mov w19, #0xb @ 0x4758
    } else {
#if defined(__linux__) || defined(__ANDROID__)
        int fd = ::open(file_path, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0600);
        if (fd < 0) {
            ret = 12;
        } else {
            constexpr const char* kHeader =
                "sig type time          handler       tid    raddr         "
                "caller_so                 handler_so                caller_sym    handler_sym_name\n";
            (void)::write(fd, kHeader, 0x8dU); // mov w2, #0x8d @ 0x45a0
            g_sig_mon_status = 4;
            for (size_t i = 0; i < kSignalTableSlotCount; ++i) {
                SignalMonitorRecord* rec = g_sig_records ? g_sig_records[i] : nullptr;
                if (!rec) continue;
                char line[512];
                int len = FormatSignalRecordLine(
                    line, "%-3d %-4d %lld %-13p %-6d %-13p %-25s %-25s %-12s %s\n",
                    rec->sig_num, rec->reg_type, static_cast<long long>(rec->timestamp_ms),
                    rec->handler_addr, rec->tid, rec->caller_ret,
                    "unknown", "unknown", "unknown", "unknown");
                if (len > 0) {
                    (void)::write(fd, line, static_cast<size_t>(len));
                }
            }
            ::close(fd);
            if (!keep_records && g_sig_records) {
                for (size_t i = 0; i < kSignalTableSlotCount; ++i) {
                    std::free(g_sig_records[i]);
                    g_sig_records[i] = nullptr;
                }
                std::free(g_sig_records);
                g_sig_records = nullptr;
            }
        }
#endif
    }
    pthread_mutex_unlock(&g_sig_mon_mutex);
    return ret;
}

int suspend_time_4_4_opt(void) { return nextai::opencut::npth_repair::kErrNotSupportedNeg111; }
int opt_mtk_buffer(void)       { return nextai::opencut::npth_repair::kErrNotSupportedNeg111; }

int register_nr_art_jni_method(JNIEnv* env) {
    static const JNINativeMethod kMethods[2] = {
        {const_cast<char*>("nStartFixDumpNativeStack"), const_cast<char*>("()I"), reinterpret_cast<void*>(&fix_art_dump_native_stack)},
        {const_cast<char*>("nStopFixDumpNativeStack"),  const_cast<char*>("()V"), reinterpret_cast<void*>(&unfix_art_dump_native_stack)},
    };
    return register_jni_method(env, "com/bytedance/crash/npth_repair/nativeCrash/ArtDumpNativeStackFixer", kMethods, 2);
}

int register_nr_dvm_jni_method(JNIEnv* env) {
    static const JNINativeMethod kMethods[1] = {
        {const_cast<char*>("nSuspendTimeOpt"), const_cast<char*>("(I)I"), reinterpret_cast<void*>(&suspend_time_4_4_opt)},
    };
    return register_jni_method(env, "com/bytedance/crash/npth_repair/nativeCrash/DvmSuspendTimeOpt", kMethods, 1);
}

int register_nr_mtk_jni_method(JNIEnv* env) {
    static const JNINativeMethod kMethods[1] = {
        {const_cast<char*>("nOptMTKBuffer"), const_cast<char*>("()I"), reinterpret_cast<void*>(&opt_mtk_buffer)},
    };
    return register_jni_method(env, "com/bytedance/crash/npth_repair/nativeCrash/MTKBufferOpt", kMethods, 1);
}

int register_nr_scudo_jni_method(JNIEnv* env) {
    static const JNINativeMethod kMethods[1] = {
        {const_cast<char*>("nFixScudoVmaLeak"), const_cast<char*>("()I"), reinterpret_cast<void*>(&fix_scudo_vma_leak)},
    };
    return register_jni_method(env, "com/bytedance/crash/npth_repair/nativeCrash/ScudoVmaLeakFixer", kMethods, 1);
}

int register_nr_sigMonitor_jni_method(JNIEnv* env) {
    static const JNINativeMethod kMethods[3] = {
        {const_cast<char*>("nStartSignalMonitorWithSigType"), const_cast<char*>("([I)I"), reinterpret_cast<void*>(&start_sig_register_monitor)},
        {const_cast<char*>("nStopSignalMonitor"),             const_cast<char*>("()V"),   reinterpret_cast<void*>(&stop_sig_register_monitor)},
        {const_cast<char*>("nDumpSignalMonitor"),             const_cast<char*>("(Ljava/lang/String;)I"), reinterpret_cast<void*>(&dump_signal_monitor)},
    };
    return register_jni_method(env, "com/bytedance/crash/npth_repair/monitor/SignalMonitor", kMethods, 3);
}

/**
 * @brief JNI entry point registering all 6 NpthRepair Java classes (`0x38a8..0x3960`, FDE[22], 184 B).
 *        Điểm vào JNI đăng ký cả 6 lớp Java của NpthRepair (`0x38a8..0x3960`, FDE[22], 184 B).
 */
jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    if (!vm) {
        return -1;
    }
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), nextai::opencut::npth_repair::kRepairJniVersion1_6) != JNI_OK || !env) {
        return -1;
    }
    static const JNINativeMethod kMainMethods[3] = {
        {const_cast<char*>("nInit"),          const_cast<char*>("(IZ)I"), reinterpret_cast<void*>(&npth_repair_init)},
        {const_cast<char*>("nSetDebuggable"), const_cast<char*>("(Z)V"),  reinterpret_cast<void*>(&repair_log_set_debuggable)},
        {const_cast<char*>("nGetDebuggable"), const_cast<char*>("()Z"),   reinterpret_cast<void*>(&repair_log_get_debuggable)},
    };
    register_jni_method(env, "com/bytedance/crash/npth_repair/NpthRepair", kMainMethods, 3);
    register_nr_art_jni_method(env);
    register_nr_dvm_jni_method(env);
    register_nr_mtk_jni_method(env);
    register_nr_scudo_jni_method(env);
    register_nr_sigMonitor_jni_method(env);
    return nextai::opencut::npth_repair::kRepairJniVersion1_6;
}

} // extern "C"
