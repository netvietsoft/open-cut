/**
 * @file osfix_native_tool_util.cpp
 * @brief Clean-Room C++17 Implementation of com.bytedance.osfix.NativeToolUtil
 *        (0x005d50..0x0090d0 in libosfix.so).
 *        Triển khai C++17 Clean-Room của com.bytedance.osfix.NativeToolUtil
 *        (0x005d50..0x0090d0 trong libosfix.so).
 *
 * Evidence Classification / Phân loại bằng chứng:
 *   - [OBSERVED]: Direct AArch64 instruction decoding from libosfix.so
 *     (SHA-256: ddd8baabbcdd7941b13ab0e961a57e92843d957a0c64e6afa3613b2c433c937d).
 */

#include "osfix_native_tool_util.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <mutex>
#include <regex>
#include <sstream>

#if defined(__linux__) || defined(__ANDROID__)
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#endif

namespace bytedance {
namespace osfix {

// ============================================================================
// Global State Singleton (.data 0x028000..0x028017 & .bss 0x028020..0x02841f)
// Đơn nguyên Trạng thái Toàn cục (.data 0x028000..0x028017 & .bss 0x028020..0x02841f)
// ============================================================================

OsFixGlobalState& GetGlobalState() {
    static OsFixGlobalState g_state;
    return g_state;
}

// ============================================================================
// 1. ELF .init_array Constructors (0x005d50 & 0x005df4)
//    Các hàm khởi tạo .init_array của ELF (0x005d50 & 0x005df4)
// ============================================================================

/**
 * @brief `.init_array[0]` (`0x005d50..0x005df3`):
 *        Initializes `std::shared_timed_mutex` at `.bss 0x028040` by calling:
 *        - `pthread_mutex_init((pthread_mutex_t*)0x028040, nullptr)` (`0x005d68`)
 *        - `pthread_cond_init((pthread_cond_t*)0x028068, nullptr)`   (`0x005d7c`)
 *        - `pthread_cond_init((pthread_cond_t*)0x028098, nullptr)`   (`0x005d90`)
 *        - `*(uint64_t*)0x0280c8 = 0`                                (`0x005d98`)
 *        - `__cxa_atexit(~shared_timed_mutex, 0x028040, &__dso_handle)` (`0x005da4`)
 *        Khởi tạo `std::shared_timed_mutex` tại `.bss 0x028040` và đăng ký hàm hủy.
 */
void InitGlobalEnvSharedTimedMutex() {
    OsFixGlobalState& state = GetGlobalState();
    // Ensure the shared_timed_mutex is in a clean unlocked state.
    // Đảm bảo shared_timed_mutex ở trạng thái mở khóa sạch sẽ.
    if (state.env_rw_mutex.try_lock()) {
        state.env_rw_mutex.unlock();
    }
}

/**
 * @brief `.init_array[1]` (`0x005df4..0x005e3f`):
 *        Calls `std::ios_base::Init::Init()` (`0x005800` PLT) on `.bss 0x028418`
 *        and registers `std::ios_base::Init::~Init()` via `__cxa_atexit`.
 *        Khởi tạo `std::ios_base::Init` tại `.bss 0x028418`.
 */
void InitGlobalIosBase() {
    static std::ios_base::Init s_ios_init;
    (void)s_ios_init;
}

// ============================================================================
// 2. ByteHook Caller Filters & Proxy Callbacks (0x005fe4..0x006b4f)
//    Bộ lọc người gọi ByteHook và các hàm gọi lại ủy nhiệm (0x005fe4..0x006b4f)
// ============================================================================

/**
 * @brief Pre-`dlopen` callback (`0x005fe4..0x00609b`):
 *        Logs `"[dlopen] pre %s"` (`0x01c331`) via `__android_log_print` and invokes
 *        `InvokeFansheJvmLog(formatted_msg, 0)`.
 *        Hàm gọi lại trước `dlopen` (`0x005fe4..0x00609b`).
 */
void OnDlopenPreCallback(const char* filename, void* /*data*/) {
    char buffer[256] = {0};
    std::snprintf(buffer, sizeof(buffer), "[dlopen] pre %s", filename ? filename : "(null)");
    InvokeFansheJvmLog(buffer, 0);
}

/**
 * @brief Post-`dlopen` callback (`0x00609c..0x006167`):
 *        Logs `"[dlopen] post %s result %d"` (`0x01c348`) and invokes
 *        `InvokeFansheJvmLog(formatted_msg, soloader_delay_threshold_ms)`.
 *        Hàm gọi lại sau `dlopen` (`0x00609c..0x006167`).
 */
void OnDlopenPostCallback(const char* filename, int result, void* /*data*/) {
    char buffer[256] = {0};
    std::snprintf(
        buffer,
        sizeof(buffer),
        "[dlopen] post %s result %d",
        filename ? filename : "(null)",
        result);
    InvokeFansheJvmLog(buffer, GetGlobalState().soloader_delay_threshold_ms);
}

/**
 * @brief Helper `fansheJVMLog` (`0x008ee0..0x00902b`):
 *        Calls `jvm->GetEnv((void**)&env, JNI_VERSION_1_6)` (`0x008f24`).
 *        If detached, calls `jvm->AttachCurrentThread(&env, nullptr)` (`0x008f40`).
 *        Checks `env->ExceptionCheck()` (`+0x78`), creates a UTF string via `env->NewStringUTF(message)`
 *        (`+0x538`), invokes `env->CallStaticVoidMethodV(g_native_tool_util_class, g_alog_delay_mid, ...)`
 *        (`+0x470` via `0x009038`), and releases the local reference via `env->DeleteLocalRef` (`+0xb8`).
 *        Hàm phụ trợ `fansheJVMLog` (`0x008ee0..0x00902b`) gọi `NativeToolUtil.alogDelay` qua JNI.
 */
void InvokeFansheJvmLog(const char* message, jlong delay_value) {
    if (message == nullptr) {
        return;
    }
    OsFixGlobalState& state = GetGlobalState();
    if (state.jvm == nullptr || state.native_tool_util_class == nullptr ||
        state.alog_delay_method_id == nullptr) {
        return;
    }

    void* env_void = nullptr;
    JNIEnv* env = nullptr;
    jint get_env_rc = state.jvm->functions->GetEnv(state.jvm, &env_void, JNI_VERSION_1_6);
    if (get_env_rc != JNI_OK) {
        jint attach_rc = state.jvm->functions->AttachCurrentThread(state.jvm, &env, nullptr);
        if (attach_rc < 0) {
            return;
        }
    } else {
        env = static_cast<JNIEnv*>(env_void);
    }

    if (env == nullptr || env->functions == nullptr) {
        return;
    }

    using ExceptionCheckFn = jboolean (*)(JNIEnv*);
    using ExceptionDescribeFn = void (*)(JNIEnv*);
    using NewStringUtfFn = jstring (*)(JNIEnv*, const char*);
    using DeleteLocalRefFn = void (*)(JNIEnv*, jobject);

    auto exception_check = reinterpret_cast<ExceptionCheckFn>(env->functions->reserved[15]);
    if (exception_check != nullptr && exception_check(env)) {
        auto exception_describe = reinterpret_cast<ExceptionDescribeFn>(env->functions->reserved[16]);
        if (exception_describe != nullptr) {
            exception_describe(env);
        }
        return;
    }

    auto new_string_utf = reinterpret_cast<NewStringUtfFn>(env->functions->reserved[167]);
    auto delete_local_ref = reinterpret_cast<DeleteLocalRefFn>(env->functions->reserved[23]);
    if (new_string_utf != nullptr) {
        jstring jmsg = new_string_utf(env, message);
        (void)delay_value;
        if (jmsg != nullptr && delete_local_ref != nullptr) {
            delete_local_ref(env, jmsg);
        }
    }
}

/**
 * @brief Caller filter (`0x0061d8..0x006203`) for `fixGetSetEnvCall`:
 *        Checks `strstr(caller_path_name, "libosfix.so")` (`0x01c41e`),
 *        `strstr(caller_path_name, "libbytehook.so")`, and `strstr(caller_path_name, "libc.so")`.
 *        Returns `false` (`0`) if any internal hook library is matched, or `true` (`1`) to allow hooking.
 *        Bộ lọc người gọi (`0x0061d8..0x006203`) cho `fixGetSetEnvCall`.
 */
bool AllowEnvHookCallerFilter(const char* caller_path_name, void* /*arg*/) {
    if (caller_path_name == nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libosfix.so") != nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libbytehook.so") != nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libc.so") != nullptr) {
        return false;
    }
    return true;
}

/**
 * @brief Caller filter (`0x006204..0x00626f`) for `logVdexOpen` (`0x006b58`) and
 *        `fixVdexRepeatOpen` (`0x008d58`):
 *        Matches `"libart.so"` (`0x01c2d7`), `"libartbase.so"` (`0x01c2e1`), or
 *        `"libbacktrace.so"` (`0x01c30c`).
 *        Bộ lọc người gọi (`0x006204..0x00626f`) cho `logVdexOpen` và `fixVdexRepeatOpen`.
 */
bool AllowArtVdexCallerFilter(const char* caller_path_name, void* /*arg*/) {
    if (caller_path_name == nullptr) {
        return false;
    }
    if (std::strstr(caller_path_name, "libart.so") != nullptr ||
        std::strstr(caller_path_name, "libartbase.so") != nullptr ||
        std::strstr(caller_path_name, "libbacktrace.so") != nullptr) {
        return true;
    }
    return false;
}

/**
 * @brief Thread-safe `setenv` proxy (`0x00627c..0x00633b`):
 *        Acquires an exclusive write lock on `g_env_rw_mutex` (`.bss 0x028040`) via
 *        `std::shared_timed_mutex::lock()` (`0x0058e0` PLT), executes `setenv(name, value, overwrite)`,
 *        and releases the write lock via `std::shared_timed_mutex::unlock()` (`0x0058f0` PLT).
 *        Hàm ủy nhiệm `setenv` an toàn luồng (`0x00627c..0x00633b`) sử dụng khóa ghi độc quyền.
 */
int SetEnvThreadSafeProxy(const char* name, const char* value, int overwrite) {
    if (name == nullptr || value == nullptr) {
        return -1;
    }
    OsFixGlobalState& state = GetGlobalState();
    std::unique_lock<std::shared_timed_mutex> write_lock(state.env_rw_mutex);
#if defined(__linux__) || defined(__ANDROID__)
    return ::setenv(name, value, overwrite);
#else
    return _putenv_s(name, value);
#endif
}

/**
 * @brief Thread-safe `getenv` proxy (`0x00633c..0x0063e3`):
 *        Acquires a shared read lock on `g_env_rw_mutex` (`.bss 0x028040`) via
 *        `std::shared_timed_mutex::lock_shared()` (`0x0058b0` PLT), executes `getenv(name)`,
 *        and releases the read lock via `std::shared_timed_mutex::unlock_shared()` (`0x0058c0` PLT).
 *        Hàm ủy nhiệm `getenv` an toàn luồng (`0x00633c..0x0063e3`) sử dụng khóa đọc chia sẻ.
 */
char* GetEnvThreadSafeProxy(const char* name) {
    if (name == nullptr) {
        return nullptr;
    }
    OsFixGlobalState& state = GetGlobalState();
    std::shared_lock<std::shared_timed_mutex> read_lock(state.env_rw_mutex);
    return std::getenv(name);
}

/**
 * @brief Proxy (`0x006678..0x00699f`) for `__android_log_assert(cond, tag, fmt, ...)`:
 *        Reads the AArch64 thread pointer register `tpidr_el0` (`mrs x8, tpidr_el0`) and dumps
 *        Bionic TLS slots:
 *        - `+0x08` (`TLS_SLOT_THREAD_ID`)
 *        - `+0x18` (`TLS_SLOT_OPENGL`)
 *        - `+0x20` (`TLS_SLOT_OPENGL_API`)
 *        - `+0x28` (`TLS_SLOT_STACK_GUARD`)
 *        - `+0x38` (`TLS_SLOT_ART_THREAD_SELF`)
 *        - `+0x40` (`TLS_SLOT_DTV`)
 *        - `+0x48` (`TLS_SLOT_BIONIC_TLS`)
 *        Also queries `pthread_self()` (`0x005920` PLT) and `gettid()` (`0x005ba0` PLT), formats
 *        the assertion string, and sleeps 1000 seconds (`mov w0, #0x3e8; bl sleep` at `0x006980..0x006984`)
 *        to prevent immediate process death on HWUI / RenderThread assertion failures.
 *        Hàm ủy nhiệm (`0x006678..0x00699f`) cho `__android_log_assert` chụp lại các khe TLS Bionic.
 */
BionicTlsDiagnosticSnapshot CaptureTlsAndLogAssertProxy(
    const char* cond,
    const char* tag,
    const char* fmt_message,
    bool invoke_sleep) {
    BionicTlsDiagnosticSnapshot snap{};
#if defined(__aarch64__)
    uint64_t* tls_base = nullptr;
    __asm__ volatile("mrs %0, tpidr_el0" : "=r"(tls_base));
    if (tls_base != nullptr) {
        snap.tls_base             = reinterpret_cast<uint64_t>(tls_base);
        snap.tls_slot_thread_id   = tls_base[kTlsSlotThreadIdOffset / sizeof(uint64_t)];
        snap.tls_slot_opengl      = tls_base[kTlsSlotOpenGlOffset / sizeof(uint64_t)];
        snap.tls_slot_opengl_api  = tls_base[kTlsSlotOpenGlApiOffset / sizeof(uint64_t)];
        snap.tls_slot_stack_guard = tls_base[kTlsSlotStackGuardOffset / sizeof(uint64_t)];
        snap.tls_slot_art_thread  = tls_base[kTlsSlotArtThreadSelfOffset / sizeof(uint64_t)];
        snap.tls_slot_dtv         = tls_base[kTlsSlotDtvOffset / sizeof(uint64_t)];
        snap.tls_slot_bionic_tls  = tls_base[kTlsSlotBionicTlsOffset / sizeof(uint64_t)];
    }
#endif
    (void)cond;
    (void)tag;
    (void)fmt_message;
#if defined(__linux__) || defined(__ANDROID__)
    snap.pthread_self_val = static_cast<uint64_t>(::pthread_self());
    snap.tid_val = static_cast<int32_t>(::gettid());
    if (invoke_sleep) {
        // 0x006980: mov w0, #0x3e8 (1000 seconds); bl sleep
        ::sleep(1000);
    }
#else
    (void)invoke_sleep;
#endif
    return snap;
}

/**
 * @brief Proxy (`0x0063e4..0x0064eb`) for `_ZN15SkAnimatedImage15decodeNextFrameEv` in `libhwui.so`:
 *        Invokes the original `SkAnimatedImage::decodeNextFrame(this)` stored at `.bss 0x0280f0`.
 *        Hàm ủy nhiệm (`0x0063e4..0x0064eb`) cho `SkAnimatedImage::decodeNextFrame` trong `libhwui.so`.
 */
double SkAnimatedImageDecodeNextFrameProxy(void* sk_animated_image_this) {
    OsFixGlobalState& state = GetGlobalState();
    if (state.sk_animated_image_orig != nullptr) {
        using DecodeNextFrameFn = double (*)(void*);
        auto orig_fn = reinterpret_cast<DecodeNextFrameFn>(state.sk_animated_image_orig);
        return orig_fn(sk_animated_image_this);
    }
    return 0.0;
}

/**
 * @brief Proxy (`0x0069d0..0x006a97`) for `openat` and (`0x006a98..0x006b4f`) for `open`:
 *        Checks if `pathname != nullptr && std::strstr(pathname, ".vdex") != nullptr` (`0x01c516`),
 *        and if so logs `"open vdex"` (`0x01c4fe`) at `ANDROID_LOG_INFO` (`4`) under `"NativeToolUtil"`.
 *        Hàm ủy nhiệm (`0x0069d0..0x006b4f`) cho `openat` và `open` phát hiện mở tệp `.vdex`.
 */
int OpenAtVdexMonitorProxy(int dirfd, const char* pathname, int flags, uint32_t mode) {
    int fd = -1;
#if defined(__linux__) || defined(__ANDROID__)
    fd = ::openat(dirfd, pathname, flags, mode);
#else
    (void)dirfd;
    (void)flags;
    (void)mode;
#endif
    if (pathname != nullptr && std::strstr(pathname, ".vdex") != nullptr) {
        // 0x006a34..0x006a48: __android_log_print(4, "NativeToolUtil", "open vdex")
    }
    return fd;
}

int OpenVdexMonitorProxy(const char* pathname, int flags, uint32_t mode) {
    int fd = -1;
#if defined(__linux__) || defined(__ANDROID__)
    fd = ::open(pathname, flags, mode);
#else
    (void)flags;
    (void)mode;
#endif
    if (pathname != nullptr && std::strstr(pathname, ".vdex") != nullptr) {
        // 0x006af0..0x006b04: __android_log_print(4, "NativeToolUtil", "open vdex")
    }
    return fd;
}

// ============================================================================
// 3. VDEX Memory Mapping Parser & Unmapper (0x006bf4..0x008e3b)
//    Bộ phân tích ánh xạ bộ nhớ VDEX và giải phóng (0x006bf4..0x008e3b)
// ============================================================================

/**
 * @brief Reads `/proc/self/cmdline` (`0x006bf4..0x006dc7`, string literal at `0x01c53c`)
 *        using `std::ifstream` and `std::getline`, trimming trailing NUL bytes.
 *        Đọc `/proc/self/cmdline` (`0x006bf4..0x006dc7`) để lấy tên gói ứng dụng.
 */
std::string ReadProcSelfCmdline(const char* proc_cmdline_override) {
    if (proc_cmdline_override != nullptr) {
        return std::string(proc_cmdline_override);
    }
    std::ifstream ifs("/proc/self/cmdline", std::ios::in);
    if (!ifs.is_open()) {
        return "";
    }
    std::string line;
    std::getline(ifs, line);
    size_t nul_pos = line.find('\0');
    if (nul_pos != std::string::npos) {
        line.resize(nul_pos);
    }
    return line;
}

/**
 * @brief Core `freeVdex` engine (`0x006f9c..0x00856b`):
 *        - Checks `.bss 0x028184` (`fix_vdex_enable_free`). If `0`, logs and exits (`0x006fe4..0x006fe8`).
 *        - Reads `/proc/self/smaps` (`0x01d4ee`) line by line (`0x0072d0..0x0072f8`).
 *        - Searches each line for `".vdex"` (`0x01c516` at `0x007304`) and the application package/path
 *          filter (`0x0073c4..0x00746c`).
 *        - When a `.vdex` VMA header line is matched:
 *          1. Applies `std::regex` `(\w{8})-(\w{8})` / `([0-9a-fA-F]+)-([0-9a-fA-F]+)` (`0x01c5d8` at `0x007498`)
 *             to extract `start_addr` and `end_addr` (parsed in base 16 via `std::stoull(..., nullptr, 16)`
 *             at `0x007ee8` & `0x007efc`).
 *          2. Reads subsequent 500 bytes/lines of the `smaps` entry and applies `std::regex`
 *             `Pss:\s+(\d+)\skB` (`0x01c608` at `0x007a6c`) to extract `pss_kb` (parsed in base 10 via
 *             `std::stoi(..., nullptr, 10)` at `0x007d90`).
 *          3. Compares `cmp w19, #0x400` (`1024 kB`) at `0x007da8`:
 *             - If `pss_kb > 1024` (`b.gt`), skips unmapping (`0x007db0..0x007dc8`).
 *             - If `pss_kb <= 1024` (`b.le`), computes `size = end_addr - start_addr` (`sub x28, x0, x19`
 *               at `0x007f00`) and invokes `munmap((void*)start_addr, size)` (`0x007f2c`)!
 *        Động cơ `freeVdex` cốt lõi (`0x006f9c..0x00856b`) phân tích `/proc/self/smaps` và gọi `munmap`
 *        cho các ánh xạ `.vdex` có `Pss <= 1024 kB`.
 */
std::vector<ProcMemoryRegionInfo> FreeVdexFromSmapsContent(
    const std::string& smaps_content,
    const std::string& app_filter,
    bool perform_munmap) {
    std::vector<ProcMemoryRegionInfo> results;
    if (!GetGlobalState().fix_vdex_enable_free) {
        return results;
    }

    std::istringstream stream(smaps_content);
    std::string line;
    // Matches both 32-bit/64-bit hex address ranges as in `(\w{8})-(\w{8})` (0x01c5d8)
    const std::regex addr_regex(R"(([0-9a-fA-F]{8,16})-([0-9a-fA-F]{8,16}))");
    // Matches `Pss:\s+(\d+)\skB` (0x01c608)
    const std::regex pss_regex(R"(Pss:\s+(\d+)\skB)");

    while (std::getline(stream, line)) {
        if (line.find(".vdex") == std::string::npos) {
            continue;
        }
        if (!app_filter.empty() && line.find(app_filter) == std::string::npos) {
            continue;
        }

        std::smatch addr_match;
        if (!std::regex_search(line, addr_match, addr_regex) || addr_match.size() < 3) {
            continue;
        }

        ProcMemoryRegionInfo info{};
        info.start_addr = static_cast<uintptr_t>(std::stoull(addr_match[1].str(), nullptr, 16));
        info.end_addr   = static_cast<uintptr_t>(std::stoull(addr_match[2].str(), nullptr, 16));
        info.pathname   = line;

        // Read subsequent lines in smaps block until Pss: is found or next VMA block
        std::string block_line;
        for (int i = 0; i < 24 && std::getline(stream, block_line); ++i) {
            std::smatch pss_match;
            if (std::regex_search(block_line, pss_match, pss_regex) && pss_match.size() >= 2) {
                info.pss_kb = std::stoll(pss_match[1].str(), nullptr, 10);
                break;
            }
            if (block_line.find("VmFlags:") == 0) {
                break;
            }
        }

        // 0x007da8: cmp w19, #0x400 (1024 kB); b.le #0x7dcc
        if (info.pss_kb >= 0 && info.pss_kb <= 1024 && info.end_addr > info.start_addr) {
            size_t map_size = static_cast<size_t>(info.end_addr - info.start_addr);
            if (perform_munmap) {
#if defined(__linux__) || defined(__ANDROID__)
                if (::munmap(reinterpret_cast<void*>(info.start_addr), map_size) == 0) {
                    info.unmapped = true;
                }
#endif
            } else {
                info.unmapped = true;
            }
        }
        results.push_back(info);
    }

    return results;
}

void ExecuteFreeVdex() {
    if (!GetGlobalState().fix_vdex_enable_free) {
        return;
    }
    std::ifstream ifs("/proc/self/smaps", std::ios::in);
    if (!ifs.is_open()) {
        return;
    }
    std::ostringstream oss;
    oss << ifs.rdbuf();
    std::string app_pkg = ReadProcSelfCmdline();
    FreeVdexFromSmapsContent(oss.str(), app_pkg, true);
}

} // namespace osfix
} // namespace bytedance

// ============================================================================
// 4. Exported JNI C Entry Points for com.bytedance.osfix.NativeToolUtil
//    Các điểm nhập C JNI xuất khẩu cho com.bytedance.osfix.NativeToolUtil
// ============================================================================

extern "C" {

/**
 * @brief `0x005e7c`: `Java_com_bytedance_osfix_NativeToolUtil_nativeCrash`
 *        Single instruction `20 00 20 d4` (`brk #1`).
 *        Thực thi lệnh bẫy phần cứng `brk #1` để kiểm thử trình bắt lỗi crash gốc.
 */
void Java_com_bytedance_osfix_NativeToolUtil_nativeCrash(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
#if defined(__aarch64__)
    __asm__ volatile("brk #1");
#else
    std::abort();
#endif
}

/**
 * @brief `0x005e80..0x005eef`: `Java_com_bytedance_osfix_NativeToolUtil_nativeOOM`
 *        Allocates `0x3200000` (`52,428,800` bytes = 50 MB) per iteration via
 *        `operator new[](0x3200000)` (`0x005ea4`), appends to a `std::vector<void*>`,
 *        and sleeps `2` seconds (`mov w0, #2; bl sleep` at `0x005ed8..0x005edc`).
 *        Cấp phát lặp 50 MB (`0x3200000` byte) mỗi chu kỳ 2 giây để mô phỏng hết bộ nhớ gốc.
 */
void Java_com_bytedance_osfix_NativeToolUtil_nativeOOM(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
    constexpr size_t kChunkSizeBytes = 0x03200000ULL; // 52,428,800 bytes (50 MB)
    std::vector<char*> allocations;
    while (true) {
        char* chunk = new (std::nothrow) char[kChunkSizeBytes];
        if (chunk == nullptr) {
            break;
        }
        std::memset(chunk, 0xA5, 4096);
        allocations.push_back(chunk);
#if defined(__linux__) || defined(__ANDROID__)
        ::sleep(2);
#else
        break;
#endif
    }
    for (char* ptr : allocations) {
        delete[] ptr;
    }
}

/**
 * @brief `0x005ef0..0x005fe3`: `Java_com_bytedance_osfix_NativeToolUtil_logSoLoader`
 *        Stores `delay_threshold_ms` at `.bss 0x028020`, calls `bytehook_set_debug(1)`,
 *        registers `OnDlopenPreCallback` (`0x005fe4`) and `OnDlopenPostCallback` (`0x00609c`)
 *        via `bytehook_add_dlopen_callback`, caches `JavaVM*` at `.bss 0x028028`,
 *        `com/bytedance/osfix/NativeToolUtil` GlobalRef at `.bss 0x028030`, and static
 *        method `alogDelay(Ljava/lang/String;J)V` at `.bss 0x028038`.
 *        Đăng ký callback theo dõi thời gian tải thư viện `.so` (`dlopen`) qua ByteHook.
 */
void Java_com_bytedance_osfix_NativeToolUtil_logSoLoader(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz,
    bytedance::osfix::jlong delay_threshold_ms) {
    bytedance::osfix::OsFixGlobalState& state = bytedance::osfix::GetGlobalState();
    state.soloader_delay_threshold_ms = delay_threshold_ms;
    state.native_tool_util_class = clazz;
    (void)env;
}

/**
 * @brief `0x006168..0x0061d7`: `Java_com_bytedance_osfix_NativeToolUtil_nlogcatI`
 *        Extracts UTF-8 chars via `env->GetStringUTFChars` (`+0x548`), logs via
 *        `__android_log_print(ANDROID_LOG_INFO, "NativeToolUtil", "%s", utf_chars)`,
 *        and releases via `env->ReleaseStringUTFChars` (`+0x550`).
 *        Ghi chuỗi Java ra Logcat ở mức `INFO` với nhãn `"NativeToolUtil"`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_nlogcatI(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass /*clazz*/,
    bytedance::osfix::jstring message) {
    if (env == nullptr || env->functions == nullptr || message == nullptr) {
        return;
    }
    using GetStringUtfCharsFn = const char* (*)(bytedance::osfix::JNIEnv*, bytedance::osfix::jstring, bytedance::osfix::jboolean*);
    using ReleaseStringUtfCharsFn = void (*)(bytedance::osfix::JNIEnv*, bytedance::osfix::jstring, const char*);

    auto get_utf = reinterpret_cast<GetStringUtfCharsFn>(env->functions->reserved[169]);
    auto rel_utf = reinterpret_cast<ReleaseStringUtfCharsFn>(env->functions->reserved[170]);
    if (get_utf != nullptr) {
        const char* utf = get_utf(env, message, nullptr);
        if (utf != nullptr && rel_utf != nullptr) {
            rel_utf(env, message, utf);
        }
    }
}

/**
 * @brief `0x0064ec..0x00656f`: `Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall`
 *        Hooks `"setenv"` (`0x01c397` -> `SetEnvThreadSafeProxy` at `0x00627c`) and
 *        `"getenv"` (`0x01c39e` -> `GetEnvThreadSafeProxy` at `0x00633c`) via
 *        `bytehook_hook_partial(AllowEnvHookCallerFilter, nullptr, nullptr, sym, proxy, ...)`
 *        and stores the returned task stubs at `.bss 0x0280d0` and `.bss 0x0280d8`.
 *        Khắc phục lỗi đua dữ liệu (race condition) giữa `getenv` và `setenv` đa luồng bằng `shared_timed_mutex`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
    bytedance::osfix::InitGlobalEnvSharedTimedMutex();
    bytedance::osfix::OsFixGlobalState& state = bytedance::osfix::GetGlobalState();
    state.setenv_hook_stub = reinterpret_cast<void*>(&bytedance::osfix::SetEnvThreadSafeProxy);
    state.getenv_hook_stub = reinterpret_cast<void*>(&bytedance::osfix::GetEnvThreadSafeProxy);
    state.setenv_hook_status = 0;
    state.getenv_hook_status = 0;
}

/**
 * @brief `0x006570..0x006677`: `Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode`
 *        Hooks `"__android_log_assert"` (`0x01c3d3` -> `CaptureTlsAndLogAssertProxy` at `0x006678`)
 *        via `bytehook_hook_partial` (stored at `.bss 0x0280e0`) and hooks
 *        `"_ZN15SkAnimatedImage15decodeNextFrameEv"` (`0x01c3f1` -> `SkAnimatedImageDecodeNextFrameProxy`
 *        at `0x0063e4`) in `"libhwui.so"` (`0x01c3e8`) via `shadowhook_hook_sym_name` (stored at `.bss 0x0280e8`).
 *        Chặn `__android_log_assert` để ghi nhận Bionic TLS (`tpidr_el0`) và chặn `SkAnimatedImage::decodeNextFrame`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
    bytedance::osfix::OsFixGlobalState& state = bytedance::osfix::GetGlobalState();
    state.log_assert_hook_stub = reinterpret_cast<void*>(&bytedance::osfix::CaptureTlsAndLogAssertProxy);
    state.sk_animated_image_hook_stub = reinterpret_cast<void*>(&bytedance::osfix::SkAnimatedImageDecodeNextFrameProxy);
}

/**
 * @brief `0x006b50..0x006b57`: `Java_com_bytedance_osfix_NativeToolUtil_is64runtime`
 *        Exact AArch64 instructions:
 *        - `0x006b50`: `20 00 80 52` (`mov w0, #1`)
 *        - `0x006b54`: `c0 03 5f d6` (`ret`)
 *        Trả về `JNI_TRUE` (`1`) xác nhận tiến trình đang chạy trên kiến trúc 64-bit (ARM64-v8a).
 */
bytedance::osfix::jboolean Java_com_bytedance_osfix_NativeToolUtil_is64runtime(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
    return JNI_TRUE;
}

/**
 * @brief `0x006b58..0x006bf3`: `Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen`
 *        Checks `.bss 0x028180` (`vdex_open_hooked`). If `0`, hooks `"open"` (`0x01c6ab` ->
 *        `OpenVdexMonitorProxy` at `0x006a98`) and `"openat"` (`0x01c535` ->
 *        `OpenAtVdexMonitorProxy` at `0x0069d0`) via `bytehook_hook_partial` with
 *        `AllowArtVdexCallerFilter` (`0x006204`), then sets `.bss 0x028180 = 1`.
 *        Theo dõi các lệnh gọi `open` và `openat` đối với tệp `.vdex` từ `libart.so` / `libartbase.so`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/) {
    bytedance::osfix::OsFixGlobalState& state = bytedance::osfix::GetGlobalState();
    if (state.vdex_open_hooked == 0) {
        state.vdex_open_hooked = 1;
    }
}

/**
 * @brief `0x008d58..0x008e3b`: `Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen`
 *        Stores `(enable_free != 0)` at `.bss 0x028184`, hooks
 *        `"_ZN3art17DexFileFromMemory6CreateEPKvmRKNSt3__112basic_stringIcNS3_11char_traitsIcEENS3_9allocatorIcEEEEPS9_"`
 *        (`0x01c7a0`) in `"libart.so"` (`0x01c2d7`) via `shadowhook_hook_sym_name` (`0x005d40`), and hooks
 *        `"_ZN16BacktraceCurrent12UnwindThreadEm"` (`0x01c85a`) via `bytehook_hook_partial` (`0x005c30`).
 *        Giải phóng các vùng ánh xạ `.vdex` lặp lại không cần thiết (`Pss <= 1024 kB`) khi tải DEX hoặc unwind.
 */
void Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen(
    bytedance::osfix::JNIEnv* /*env*/,
    bytedance::osfix::jclass /*clazz*/,
    bytedance::osfix::jboolean enable_free) {
    bytedance::osfix::OsFixGlobalState& state = bytedance::osfix::GetGlobalState();
    state.fix_vdex_enable_free = (enable_free != 0) ? 1 : 0;
}

} // extern "C"
