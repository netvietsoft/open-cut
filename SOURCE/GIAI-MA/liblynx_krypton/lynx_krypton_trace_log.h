/**
 * @file lynx_krypton_trace_log.h
 * @brief Declarations for `com.lynx.canvas.CanvasManager` native methods,
 *        `KryptonLogFunction` (`0x00403c..0x004148`), and `RuntimeLoadLynxTraceFunc`
 *        (`0x00416c..0x0042fc`) in `liblynx_krypton.so`.
 *        Khai báo các phương thức native của `com.lynx.canvas.CanvasManager`,
 *        `KryptonLogFunction` (`0x00403c..0x004148`), và `RuntimeLoadLynxTraceFunc`
 *        (`0x00416c..0x0042fc`) trong `liblynx_krypton.so`.
 */

#ifndef NEXTAI_OPENCUT_LYNX_KRYPTON_TRACE_LOG_H_
#define NEXTAI_OPENCUT_LYNX_KRYPTON_TRACE_LOG_H_

#include "lynx_krypton_types.h"

#include <sstream>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynx_krypton {

/**
 * @brief Signature of the Krypton C++ log callback returned by `nativeGetLogFunctionPtr` (`0x004160`).
 *        Chữ ký hàm callback log C++ của Krypton được trả về bởi `nativeGetLogFunctionPtr` (`0x004160`).
 *
 * Disassembly at `0x00403c..0x004068`:
 * - `w0`: `int32_t krypton_log_level`
 * - `x1`: `const std::string* tag` (`ldrb w8, [x1]` SSO flag check @ `0x0040d8`)
 * - `x2`: `const std::string* message` (`ldrb w8, [x2]` SSO flag check @ `0x004100`)
 */
using KryptonLogCallbackFn = void (*)(int32_t level, const std::string& tag, const std::string& message);

/**
 * @brief Record of a single `lynx::base::logging::LogMessage` emission for verification.
 *        Bản ghi một thông điệp log `lynx::base::logging::LogMessage` phục vụ đối soát.
 */
struct LynxLogRecord {
    const char* file;
    int32_t     line;
    int32_t     severity;
    std::string formatted_text;
};

/**
 * @brief Exact reconstruction of `lynx::base::logging::LogMessage` (`0x005280` / `0x0052a0`).
 *        Tái dựng chính xác `lynx::base::logging::LogMessage` (`0x005280` / `0x0052a0`).
 *
 * Stack buffer size in `liblynx_krypton.so`: `296 bytes` (`0x128`), where `stream()` is
 * accessed at `this + 0x08` (`add x0, sp, #0x38` when `this = sp + 0x30` @ `0x0040ec`).
 */
class LynxLogMessage {
public:
    LynxLogMessage(const char* file, int32_t line, int32_t severity) noexcept;
    ~LynxLogMessage() noexcept;

    std::ostringstream& stream() noexcept { return stream_; }

    static int32_t GetMinLogLevel() noexcept;
    static void SetMinLogLevel(int32_t min_level) noexcept;
    static std::vector<LynxLogRecord> GetCapturedLogs();
    static void ClearCapturedLogs();

private:
    const char*        file_;
    int32_t            line_;
    int32_t            severity_;
    std::ostringstream stream_;
};

/**
 * @brief Maps a Krypton log level (`w0`) to a Lynx `LogMessage` severity (`w2`)
 *        using the exact 5-byte relative branch offset table at `.rodata 0x001970`.
 *        Ánh xạ mức log Krypton (`w0`) sang mức độ nghiêm trọng `LogMessage` của Lynx (`w2`)
 *        bằng bảng nhảy tương đối 5 byte tại `.rodata 0x001970`.
 *
 * Exact AArch64 instruction trace (`0x00406c..0x0040c0`):
 * ```asm
 * 0x00406c: sub  w8, w0, #1
 * 0x004070: cmp  w8, #4
 * 0x004074: b.hi #0x4094           ; default -> w2 = 0 (LOG_VERBOSE)
 * 0x004078: adrp x9, #0x1000
 * 0x00407c: add  x9, x9, #0x970    ; .rodata 0x001970 = {0x05, 0x09, 0x0b, 0x0d, 0x07}
 * 0x004080: adr  x10, #0x4088
 * 0x004084: ldrb w11, [x9, x8, uxtw]
 * 0x004088: add  x10, x10, x11, lsl #2
 * 0x00408c: br   x10
 * ```
 */
int32_t MapKryptonLogLevelToLynxSeverity(int32_t krypton_level) noexcept;

/**
 * @brief Exact libc++ `std::__ndk1::basic_string<char>` SSO (Short String Optimization)
 *        pointer & length extractor observed at `0x0040d8..0x004124` and `0x004150..0x00415c`.
 *        Trình trích xuất con trỏ & độ dài SSO của `std::__ndk1::basic_string<char>`
 *        quan sát tại `0x0040d8..0x004124` và `0x004150..0x00415c`.
 */
struct LibcxxStringView {
    const char* data;
    size_t      size;
};

LibcxxStringView ExtractLibcxxStringView(const std::string& str) noexcept;

/**
 * @brief Sub_00403c (`0x00403c..0x004148`, 272 bytes): `KryptonLogFunction`.
 *        Hàm callback log `KryptonLogFunction` (`0x00403c..0x004148`, 272 byte).
 */
void KryptonLogFunction(int32_t level, const std::string& tag, const std::string& message);

/**
 * @brief `Java_com_lynx_canvas_CanvasManager_nativeGetLogFunctionPtr` (`0x004160..0x004168`).
 *        Phương thức JNI trả về con trỏ hàm `KryptonLogFunction` (`0x00403c`).
 */
jlong CanvasManager_nativeGetLogFunctionPtr(JNIEnv* env, jobject jcaller) noexcept;

/**
 * @brief `Java_com_lynx_canvas_CanvasManager_nativeRegisterTraceFunc` (`0x00416c..0x0042fc`).
 *        Loads `liblynxtrace.so` via `dlopen(..., RTLD_LAZY=2)`, resolves `TraceEventBeginEx`,
 *        `TraceEventEndEx`, `TraceCounterEx` via `dlsym`, stores them into `.bss 0x00c008..0x00c018`,
 *        and invokes `lynx::canvas::AttachKryptonTraceHandler`.
 *        Tải `liblynxtrace.so` qua `dlopen(..., RTLD_LAZY=2)`, phân giải 3 biểu tượng trace qua `dlsym`,
 *        lưu vào `.bss 0x00c008..0x00c018`, và gọi `lynx::canvas::AttachKryptonTraceHandler`.
 */
void CanvasManager_nativeRegisterTraceFunc(JNIEnv* env, jobject jcaller);

/**
 * @brief Accessor to global `.bss` state (`0x00c000..0x00c047`) and trace handler state.
 *        Hàm truy cập trạng thái `.bss` toàn cục (`0x00c000..0x00c047`) và trạng thái bộ xử lý trace.
 */
KryptonBssSegment& GetKryptonBssState() noexcept;
const KryptonTraceFunctions& GetAttachedKryptonTraceHandler() noexcept;
uint32_t GetAttachKryptonTraceHandlerCallCount() noexcept;
void SetSimulateLibLynxTraceDlopenFailure(bool fail_dlopen, bool fail_begin_end, bool fail_counter) noexcept;
void ResetKryptonTraceAndBssState() noexcept;

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LYNX_KRYPTON_TRACE_LOG_H_
