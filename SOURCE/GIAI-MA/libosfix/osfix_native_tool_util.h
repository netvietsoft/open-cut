/**
 * @file osfix_native_tool_util.h
 * @brief Clean-Room C++17 Reconstruction of com.bytedance.osfix.NativeToolUtil
 *        (0x005d50..0x0090d0 in libosfix.so).
 *        Tái cấu trúc C++17 Clean-Room của com.bytedance.osfix.NativeToolUtil
 *        (0x005d50..0x0090d0 trong libosfix.so).
 *
 * Exported JNI Symbols Covered / Các biểu tượng JNI xuất khẩu được bao phủ:
 *   1. Java_com_bytedance_osfix_NativeToolUtil_nativeCrash         (0x005e7c, size 0x0004)
 *   2. Java_com_bytedance_osfix_NativeToolUtil_nativeOOM           (0x005e80, size 0x0070)
 *   3. Java_com_bytedance_osfix_NativeToolUtil_logSoLoader         (0x005ef0, size 0x00f4)
 *   4. Java_com_bytedance_osfix_NativeToolUtil_nlogcatI            (0x006168, size 0x0070)
 *   5. Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall    (0x0064ec, size 0x0084)
 *   6. Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode  (0x006570, size 0x0108)
 *   7. Java_com_bytedance_osfix_NativeToolUtil_is64runtime         (0x006b50, size 0x0008)
 *   8. Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen         (0x006b58, size 0x009c)
 *   9. Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen   (0x008d58, size 0x00e4)
 */

#ifndef NEXTAI_OPENCUT_OSFIX_NATIVE_TOOL_UTIL_H_
#define NEXTAI_OPENCUT_OSFIX_NATIVE_TOOL_UTIL_H_

#include "osfix_types.h"

namespace bytedance {
namespace osfix {

// ============================================================================
// 1. ELF .init_array Constructors (0x005d50 & 0x005df4)
//    Các hàm khởi tạo .init_array của ELF (0x005d50 & 0x005df4)
// ============================================================================

/**
 * @brief `.init_array[0]` (`0x005d50..0x005df3`): Initializes the global
 *        `std::shared_timed_mutex` at `.bss 0x028040` and registers its destructor.
 *        Khởi tạo `std::shared_timed_mutex` toàn cục tại `.bss 0x028040` và đăng ký hàm hủy.
 */
void InitGlobalEnvSharedTimedMutex();

/**
 * @brief `.init_array[1]` (`0x005df4..0x005e3f`): Initializes `std::ios_base::Init`
 *        at `.bss 0x028418` for `<iostream>` / `<fstream>` / `<sstream>` usage.
 *        Khởi tạo `std::ios_base::Init` tại `.bss 0x028418` cho luồng C++ chuẩn.
 */
void InitGlobalIosBase();

// ============================================================================
// 2. ByteHook Caller Filters & Proxy Callbacks (0x005fe4..0x006b4f)
//    Bộ lọc người gọi ByteHook và các hàm gọi lại ủy nhiệm (0x005fe4..0x006b4f)
// ============================================================================

/**
 * @brief Pre-`dlopen` callback (`0x005fe4..0x00609b`) registered by `logSoLoader`.
 *        Logs `"[dlopen] pre %s"` (`0x01c331`).
 *        Hàm gọi lại trước `dlopen` (`0x005fe4..0x00609b`) được đăng ký bởi `logSoLoader`.
 */
void OnDlopenPreCallback(const char* filename, void* data);

/**
 * @brief Post-`dlopen` callback (`0x00609c..0x006167`) registered by `logSoLoader`.
 *        Logs `"[dlopen] post %s result %d"` (`0x01c348`) and invokes `fansheJVMLog` (`0x008ee0`).
 *        Hàm gọi lại sau `dlopen` (`0x00609c..0x006167`) được đăng ký bởi `logSoLoader`.
 */
void OnDlopenPostCallback(const char* filename, int result, void* data);

/**
 * @brief Helper `fansheJVMLog` (`0x008ee0..0x00902b`) that attaches the current thread
 *        if needed and invokes `NativeToolUtil.alogDelay(String, long)` via JNI.
 *        Hàm phụ trợ `fansheJVMLog` (`0x008ee0..0x00902b`) gắn luồng hiện tại vào JVM
 *        và gọi `NativeToolUtil.alogDelay(String, long)` qua JNI.
 */
void InvokeFansheJvmLog(const char* message, jlong delay_value);

/**
 * @brief Caller filter (`0x0061d8..0x006203`) for `fixGetSetEnvCall`.
 *        Returns `false` if `caller_path_name` ends with `"libosfix.so"`, `"libbytehook.so"`,
 *        or `"libc.so"`; returns `true` otherwise.
 *        Bộ lọc người gọi (`0x0061d8..0x006203`) cho `fixGetSetEnvCall`.
 */
bool AllowEnvHookCallerFilter(const char* caller_path_name, void* arg);

/**
 * @brief Caller filter (`0x006204..0x00626f`) for `logVdexOpen` and `fixVdexRepeatOpen`.
 *        Matches `"libart.so"`, `"libartbase.so"`, or `"libbacktrace.so"`.
 *        Bộ lọc người gọi (`0x006204..0x00626f`) cho `logVdexOpen` và `fixVdexRepeatOpen`.
 */
bool AllowArtVdexCallerFilter(const char* caller_path_name, void* arg);

/**
 * @brief Thread-safe `setenv` proxy (`0x00627c..0x00633b`) that acquires an exclusive writer
 *        lock (`std::shared_timed_mutex::lock()` / `unlock()`) on `.bss 0x028040`.
 *        Hàm ủy nhiệm `setenv` an toàn luồng (`0x00627c..0x00633b`) khóa ghi độc quyền
 *        trên `std::shared_timed_mutex` tại `.bss 0x028040`.
 */
int SetEnvThreadSafeProxy(const char* name, const char* value, int overwrite);

/**
 * @brief Thread-safe `getenv` proxy (`0x00633c..0x0063e3`) that acquires a shared reader
 *        lock (`std::shared_timed_mutex::lock_shared()` / `unlock_shared()`) on `.bss 0x028040`.
 *        Hàm ủy nhiệm `getenv` an toàn luồng (`0x00633c..0x0063e3`) khóa đọc chia sẻ
 *        trên `std::shared_timed_mutex` tại `.bss 0x028040`.
 */
char* GetEnvThreadSafeProxy(const char* name);

/**
 * @brief Proxy (`0x006678..0x00699f`) for `__android_log_assert(cond, tag, fmt, ...)`.
 *        Captures Bionic TLS slots from `tpidr_el0` (`+0x08`, `+0x18`, `+0x20`, `+0x28`,
 *        `+0x38`, `+0x40`, `+0x48`), logs diagnostic info, and sleeps 1000 seconds (`0x3e8`).
 *        Hàm ủy nhiệm (`0x006678..0x00699f`) cho `__android_log_assert` thu thập khe TLS Bionic.
 */
BionicTlsDiagnosticSnapshot CaptureTlsAndLogAssertProxy(
    const char* cond,
    const char* tag,
    const char* fmt_message,
    bool invoke_sleep = false);

/**
 * @brief Proxy (`0x0063e4..0x0064eb`) for `SkAnimatedImage::decodeNextFrame(void*)` in `libhwui.so`.
 *        Logs `"[decodeNextFrame] enter"` (`0x01c3a5`) and `"[decodeNextFrame] exit"` (`0x01c3bc`).
 *        Hàm ủy nhiệm (`0x0063e4..0x0064eb`) cho `SkAnimatedImage::decodeNextFrame` trong `libhwui.so`.
 */
double SkAnimatedImageDecodeNextFrameProxy(void* sk_animated_image_this);

/**
 * @brief Proxy (`0x0069d0..0x006a97`) for `openat(int dirfd, const char* pathname, int flags, mode_t mode)`
 *        and (`0x006a98..0x006b4f`) for `open(const char* pathname, int flags, mode_t mode)`.
 *        Logs `"open vdex"` (`0x01c4fe`) when `strstr(pathname, ".vdex")` (`0x01c516`) matches.
 *        Hàm ủy nhiệm (`0x0069d0..0x006b4f`) cho `openat` và `open` ghi nhật ký khi mở tệp `.vdex`.
 */
int OpenAtVdexMonitorProxy(int dirfd, const char* pathname, int flags, uint32_t mode);
int OpenVdexMonitorProxy(const char* pathname, int flags, uint32_t mode);

// ============================================================================
// 3. VDEX Memory Mapping Parser & Unmapper (0x006bf4..0x008e3b)
//    Bộ phân tích ánh xạ bộ nhớ VDEX và giải phóng (0x006bf4..0x008e3b)
// ============================================================================

/**
 * @brief Reads `/proc/self/cmdline` (`0x006bf4..0x006dc7`) to determine the current
 *        package process name for `.vdex` path matching.
 *        Đọc `/proc/self/cmdline` (`0x006bf4..0x006dc7`) để lấy tên tiến trình gói hiện tại.
 */
std::string ReadProcSelfCmdline(const char* proc_cmdline_override = nullptr);

/**
 * @brief Core `freeVdex` engine (`0x006f9c..0x00856b`):
 *        Scans `/proc/self/smaps` (`0x01d4ee`) for `.vdex` (`0x01c516`) mappings belonging to
 *        the application, parses the address range via `(\w{8})-(\w{8})` / `(\w+)-(\w+)` and
 *        `Pss:\s+(\d+)\skB` (`0x01c608`), and if `pss_kb <= 1024` (`0x400`), unmaps the region
 *        via `munmap((void*)start, end - start)`!
 *        Động cơ `freeVdex` cốt lõi (`0x006f9c..0x00856b`): Quét `/proc/self/smaps` tìm các vùng
 *        nhớ `.vdex`, phân tích phạm vi địa chỉ và `Pss`, nếu `pss_kb <= 1024` (`0x400`) thì
 *        gọi `munmap` để giải phóng vùng địa chỉ ảo.
 *
 * @param smaps_content Optional in-memory `/proc/self/smaps` text for deterministic unit testing.
 * @param app_filter    Optional package/path substring filter.
 * @param perform_munmap If true, invokes real `munmap`; if false, simulates unmapping safely.
 * @return Vector of parsed `.vdex` regions and whether each was unmapped.
 */
std::vector<ProcMemoryRegionInfo> FreeVdexFromSmapsContent(
    const std::string& smaps_content,
    const std::string& app_filter = "",
    bool perform_munmap = false);

/**
 * @brief Executes `freeVdex` (`0x006f9c..0x00856b`) against `/proc/self/smaps`.
 *        Thực thi `freeVdex` (`0x006f9c..0x00856b`) trên `/proc/self/smaps`.
 */
void ExecuteFreeVdex();

} // namespace osfix
} // namespace bytedance

// ============================================================================
// 4. Exported JNI C Entry Points for com.bytedance.osfix.NativeToolUtil
//    Các điểm nhập C JNI xuất khẩu cho com.bytedance.osfix.NativeToolUtil
// ============================================================================

extern "C" {

/**
 * @brief `0x005e7c`: `brk #1` (`0xd4200020`).
 */
void Java_com_bytedance_osfix_NativeToolUtil_nativeCrash(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x005e80..0x005eef`: Allocates 50 MB (`0x3200000` bytes) chunks in a loop.
 */
void Java_com_bytedance_osfix_NativeToolUtil_nativeOOM(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x005ef0..0x005fe3`: Registers ByteHook dlopen callbacks and caches `alogDelay`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_logSoLoader(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz,
    bytedance::osfix::jlong delay_threshold_ms);

/**
 * @brief `0x006168..0x0061d7`: Logs a Java string at `ANDROID_LOG_INFO` level under `"NativeToolUtil"`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_nlogcatI(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz,
    bytedance::osfix::jstring message);

/**
 * @brief `0x0064ec..0x00656f`: Hooks `setenv` and `getenv` with a `std::shared_timed_mutex`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_fixGetSetEnvCall(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x006570..0x006677`: Hooks `__android_log_assert` and `SkAnimatedImage::decodeNextFrame`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_logGetEnvErrorCode(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x006b50..0x006b57`: Returns `JNI_TRUE` (`1`) on AArch64 (`mov w0, #1; ret`).
 */
bytedance::osfix::jboolean Java_com_bytedance_osfix_NativeToolUtil_is64runtime(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x006b58..0x006bf3`: Hooks `open` and `openat` in `libart.so` / `libartbase.so` to log `.vdex` opens.
 */
void Java_com_bytedance_osfix_NativeToolUtil_logVdexOpen(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz);

/**
 * @brief `0x008d58..0x008e3b`: Hooks `art::DexFileFromMemory::Create` and `BacktraceCurrent::UnwindThread`
 *        to unmap redundant `.vdex` mappings via `freeVdex()`.
 */
void Java_com_bytedance_osfix_NativeToolUtil_fixVdexRepeatOpen(
    bytedance::osfix::JNIEnv* env,
    bytedance::osfix::jclass clazz,
    bytedance::osfix::jboolean enable_free);

} // extern "C"

#endif // NEXTAI_OPENCUT_OSFIX_NATIVE_TOOL_UTIL_H_
