/**
 * @file lynxtrace_types.h
 * @brief Exact ELF64 AArch64 ABI structures, `.rodata` strings, `.data.rel.ro`
 *        JNI & vtable layouts, `.data`/`.bss` singleton layout, and Perfetto
 *        proto-zero model types for `liblynxtrace.so` (`51,200 bytes`).
 *        Cấu trúc ABI ELF64 AArch64 chính xác, chuỗi `.rodata`, bố cục JNI &
 *        vtable trong `.data.rel.ro`, singleton `.data`/`.bss`, và các kiểu
 *        Perfetto cho `liblynxtrace.so` (`51,200 byte`).
 *
 * Binary Ground Truth / Thực tế Nhị phân (`liblynxtrace.so` — 51,200 bytes):
 * - Architecture: ELF64 AArch64 little-endian (`EM_AARCH64`)
 * - ELF64 Section Geometry:
 *   - `.dynsym`       : `0x000320` (`1,056 bytes`, `44` symbols: `[001]..[009]` = 9 imports, `[010]..[043]` = **34 exported functions**)
 *   - `.dynstr`       : `0x000a18` (`2,785 bytes`)
 *   - `.rela.dyn`     : `0x001500` (`1,488 bytes`, `62` `R_AARCH64_RELATIVE` relocations)
 *   - `.rela.plt`     : `0x001ad0` (`240 bytes`, `10` `R_AARCH64_JUMP_SLOT` relocations -> PLT `0x004240..0x0042d0`)
 *   - `.rodata`       : `0x001bc0..0x001e9d` (`734 bytes`, 27 JNI strings)
 *   - `.text`         : `0x004000..0x004213` (`532 bytes`, 18 subroutines)
 *   - `.plt`          : `0x004220..0x0042df` (`192 bytes`)
 *   - `.data.rel.ro`  : `0x008000..0x0081f7` (`504 bytes`: `.dso_handle` @ `0x008000`, `TraceController` 13-slot vtable @ `0x008018..0x008078`, `TraceController` 4 JNI methods @ `0x008080..0x0080df`, `JavaRef<jobject>` vtable @ `0x0080f0..0x008100`, `TraceEvent` 10 JNI methods @ `0x008108..0x0081f7`)
 *   - `.fini_array`   : `0x0081f8..0x008207` (`16 bytes`: `0x004010`, `0x004000`)
 *   - `.got.plt`      : `0x0083b8..0x00841f` (`104 bytes`)
 *   - `.data`         : `0x00c000..0x00c00f` (`16 bytes`: `lynx::trace::TraceController` singleton instance `{vptr = 0x008018, delegate = nullptr}`)
 *   - `.bss`          : `0x00c010..0x00c027` (`24 bytes`: `+0x00 (0x00c010)` `uint64_t guard_var`, `+0x08 (0x00c018)` `jclass g_trace_controller_class`, `+0x10 (0x00c020)` `jclass g_trace_event_class`)
 *
 * Evidence Classification:
 * - `OBSERVED`: Exact ELF64 geometry, 34 exported `.dynsym` functions, 62 `.rela.dyn` relocations,
 *   10 `.rela.plt` relocations, `JNI_OnLoad` (`0x00403c`), `TraceController::Instance()` (`0x0040fc`),
 *   13-slot `TraceController` vtable (`0x008018..0x008078`), and release-mode fast-return thunks.
 * - `NEW_DESIGN`: Configurable runtime telemetry ring buffer for OpenCut Perfetto & Systrace profiling
 *   when `SetProductionTelemetryEnabled(true)` is active (defaults to exact release binary behavior).
 */

#ifndef NEXTAI_OPENCUT_LYNXTRACE_TYPES_H_
#define NEXTAI_OPENCUT_LYNXTRACE_TYPES_H_

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <map>
#include <string>
#include <vector>

namespace nextai {
namespace opencut {
namespace lynxtrace {

// ============================================================================
// 1. ELF64 Binary Geometry & Section Constants
//    Hằng số Hình học Nhị phân ELF64 & Phân đoạn
// ============================================================================

struct Elf64GeometryConstants {
    static constexpr uint32_t kBinarySizeBytes          = 51200u;
    static constexpr uint32_t kDynsymOffset             = 0x000320u;
    static constexpr uint32_t kDynsymSizeBytes          = 1056u;
    static constexpr uint32_t kDynsymEntryCount         = 44u;
    static constexpr uint32_t kImportedSymbolCount      = 9u;
    static constexpr uint32_t kExportedSymbolCount      = 34u; // [010]..[043]

    static constexpr uint32_t kDynstrOffset             = 0x000a18u;
    static constexpr uint32_t kDynstrSizeBytes          = 2785u;

    static constexpr uint32_t kRelaDynOffset            = 0x001500u;
    static constexpr uint32_t kRelaDynSizeBytes         = 1488u;
    static constexpr uint32_t kRelaDynEntryCount        = 62u;

    static constexpr uint32_t kRelaPltOffset            = 0x001ad0u;
    static constexpr uint32_t kRelaPltSizeBytes         = 240u;
    static constexpr uint32_t kRelaPltEntryCount        = 10u;

    static constexpr uint32_t kRodataVaddr              = 0x001bc0u;
    static constexpr uint32_t kRodataSizeBytes          = 734u;

    static constexpr uint32_t kTextVaddr                = 0x004000u;
    static constexpr uint32_t kTextSizeBytes            = 532u;
    static constexpr uint32_t kJniOnLoadVaddr           = 0x00403cu;
    static constexpr uint32_t kJniOnLoadSizeBytes       = 188u;
    static constexpr uint32_t kTraceControllerInstVaddr = 0x0040fcu;
    static constexpr uint32_t kTraceControllerInstSize  = 96u;

    static constexpr uint32_t kPltVaddr                 = 0x004220u;
    static constexpr uint32_t kPltSizeBytes             = 192u;

    static constexpr uint32_t kDataRelRoVaddr           = 0x008000u;
    static constexpr uint32_t kDataRelRoSizeBytes       = 504u;

    static constexpr uint32_t kFiniArrayVaddr           = 0x0081f8u;
    static constexpr uint32_t kFiniArraySizeBytes       = 16u;

    static constexpr uint32_t kDataVaddr                = 0x00c000u;
    static constexpr uint32_t kDataSizeBytes            = 16u;

    static constexpr uint32_t kBssVaddr                 = 0x00c010u;
    static constexpr uint32_t kBssSizeBytes             = 24u;
};

// ============================================================================
// 2. Minimal JNI & Perfetto / Lynx Trace ABI Types
//    Các kiểu dữ liệu ABI JNI & Perfetto / Lynx Trace Tối thiểu
// ============================================================================

using jint         = int32_t;
using jlong        = int64_t;
using jboolean     = uint8_t;
using jobject      = void*;
using jclass       = void*;
using jstring      = void*;
using jobjectArray = void*;
using JavaVM       = struct _JavaVM;
using JNIEnv       = struct _JNIEnv;

constexpr jint     kJniVersion1_6 = 0x00010006; // mov w0, #6; movk w0, #1, lsl #16 @ 0x0040e8
constexpr jboolean kJniFalse      = 0u;
constexpr jboolean kJniTrue       = 1u;

struct JNINativeMethodEntry {
    const char* name;       // +0x00
    const char* signature;  // +0x08
    void*       fnPtr;      // +0x10
};
static_assert(sizeof(JNINativeMethodEntry) == 24, "JNINativeMethodEntry must be 24 bytes");

// ============================================================================
// 3. `.rodata` Constants (`0x001bc0..0x001e9d`, 734 bytes)
//    Các Hằng số Chuỗi `.rodata` (`0x001bc0..0x001e9d`, 734 byte)
// ============================================================================

struct RodataConstants {
    static constexpr const char* kClassTraceController              = "com/lynx/tasm/base/TraceController"; // 0x001bc0
    static constexpr const char* kJniNativeInstant                  = "nativeInstant";                      // 0x001be3
    static constexpr const char* kJniNativeInstantWithProps         = "nativeInstantWithProps";             // 0x001bf1
    static constexpr const char* kJniNativeBeginSectionWithProps    = "nativeBeginSectionWithProps";        // 0x001c08
    static constexpr const char* kJniNativeEndSectionWithProps      = "nativeEndSectionWithProps";          // 0x001c24
    static constexpr const char* kJniNativeCounter                  = "nativeCounter";                      // 0x001c3e
    static constexpr const char* kJniNativeCreateTraceController    = "nativeCreateTraceController";        // 0x001c4c
    static constexpr const char* kJniNativeBeginSection             = "nativeBeginSection";                 // 0x001c68
    static constexpr const char* kJniNativeEndSection               = "nativeEndSection";                   // 0x001c7b
    static constexpr const char* kJniNativeStartTracing             = "nativeStartTracing";                 // 0x001c8c
    static constexpr const char* kJniNativeStopTracing              = "nativeStopTracing";                  // 0x001c9f
    static constexpr const char* kJniNativeCategoryEnabled          = "nativeCategoryEnabled";              // 0x001cb1
    static constexpr const char* kJniNativePerfettoTraceEnabled     = "nativePerfettoTraceEnabled";         // 0x001cc7
    static constexpr const char* kJniNativeSystemTraceEnabled       = "nativeSystemTraceEnabled";           // 0x001ce2
    static constexpr const char* kJniNativeStartStartupTracing      = "nativeStartStartupTracingIfNeeded";  // 0x001cfb

    static constexpr const char* kSigStringBool                     = "(Ljava/lang/String;)Z";              // 0x001d1d
    static constexpr const char* kSigVoidBool                       = "()Z";                                // 0x001d33
    static constexpr const char* kSigCounter                        = "(Ljava/lang/String;Ljava/lang/String;J)V"; // 0x001d37
    static constexpr const char* kSigLongVoid                       = "(J)V";                               // 0x001d60
    static constexpr const char* kSigLongIntVoid                    = "(JI)V";                              // 0x001d65
    static constexpr const char* kSigInstantWithProps               = "(Ljava/lang/String;Ljava/lang/String;JLjava/util/Map;)V"; // 0x001d6b
    static constexpr const char* kSigSectionWithProps               = "(Ljava/lang/String;Ljava/lang/String;Ljava/util/Map;)V";  // 0x001da3
    static constexpr const char* kSigInstant                        = "(Ljava/lang/String;Ljava/lang/String;JLjava/lang/String;)V"; // 0x001dda
    static constexpr const char* kSigSection                        = "(Ljava/lang/String;Ljava/lang/String;)V"; // 0x001e15
    static constexpr const char* kSigVoidLong                       = "()J";                                // 0x001e3d
    static constexpr const char* kSigStartTracing                   = "(JI[Ljava/lang/String;[Ljava/lang/String;Ljava/lang/String;Z)I"; // 0x001e41
    static constexpr const char* kClassTraceEvent                   = "com/lynx/tasm/base/TraceEvent";      // 0x001e80
};

// ============================================================================
// 4. `.data` (`0x00c000..0x00c00f`) & `.bss` (`0x00c010..0x00c027`) Layout
//    Bố cục Phân đoạn `.data` (`16 B`) & `.bss` (`24 B`)
// ============================================================================

/**
 * @brief Exact 16-byte layout of `lynx::trace::TraceController` singleton at `.data 0x00c000`:
 *        - `+0x00 (0x00c000)`: `vptr` initialized to `.data.rel.ro 0x008018` (`off=0x00c000 addend=0x8018` in `.rela.dyn`)
 *        - `+0x08 (0x00c008)`: `delegate_ptr` (`ldr x0, [x0, #8]` in `~TraceController` @ `0x004160`)
 *        Bố cục 16-byte chính xác của singleton `lynx::trace::TraceController` tại `.data 0x00c000`.
 */
struct TraceControllerAbiLayout {
    const void* vptr;         // +0x00 (0x00c000 -> points to 0x008018)
    void*       delegate_ptr; // +0x08 (0x00c008 -> destroyed via vtable+0x08 in ~TraceController @ 0x004178)
};
static_assert(sizeof(TraceControllerAbiLayout) == 16, "TraceControllerAbiLayout must be 16 bytes");

/**
 * @brief Exact 24-byte layout of `.bss` (`0x00c010..0x00c027`):
 *        - `+0x00 (0x00c010)`: `uint64_t guard_var_trace_controller` (`__cxa_guard_acquire` @ `0x004128`)
 *        - `+0x08 (0x00c018)`: `jclass g_trace_controller_class` (`str x0, [x20]` @ `0x004070`)
 *        - `+0x10 (0x00c020)`: `jclass g_trace_event_class` (`str x0, [x20, #8]` @ `0x0040b4`)
 *        Bố cục 24-byte chính xác của `.bss` (`0x00c010..0x00c027`).
 */
struct LynxTraceBssSegment {
    uint64_t guard_var_trace_controller; // +0x00 (0x00c010)
    jclass   trace_controller_class;     // +0x08 (0x00c018)
    jclass   trace_event_class;          // +0x10 (0x00c020)
};
static_assert(sizeof(LynxTraceBssSegment) == 24, "LynxTraceBssSegment must be 24 bytes (0x18)");
static_assert(offsetof(LynxTraceBssSegment, guard_var_trace_controller) == 0x00, "Offset +0x00 mismatch");
static_assert(offsetof(LynxTraceBssSegment, trace_controller_class) == 0x08, "Offset +0x08 mismatch");
static_assert(offsetof(LynxTraceBssSegment, trace_event_class) == 0x10, "Offset +0x10 mismatch");

/**
 * @brief Exact 24-byte layout of `lynx::base::android::ScopedLocalJavaRef<jobject>`
 *        on stack (`[sp, #8..#0x1f]`) in `JNI_OnLoad` (`0x004058..0x0040bc`):
 *        - `+0x00`: `vptr` (`0x0080f0` set in `~JavaRef` @ `0x0041b4..0x0041bc`)
 *        - `+0x08`: `JNIEnv* env`
 *        - `+0x10`: `jobject obj` (`ldr x1, [x0, #0x10]` in `~JavaRef` @ `0x0041b0` and `ldr x1, [sp, #0x10]` in `sub_0041f4` @ `0x0041f8`)
 *        Bố cục 24-byte chính xác của `ScopedLocalJavaRef<jobject>` trên stack trong `JNI_OnLoad`.
 */
struct ScopedLocalJavaRefLayout {
    const void* vptr; // +0x00 (`0x0080f0`)
    JNIEnv*     env;  // +0x08
    jobject     obj;  // +0x10
};
static_assert(sizeof(ScopedLocalJavaRefLayout) == 24, "ScopedLocalJavaRefLayout must be 24 bytes (0x18)");

// ============================================================================
// 5. Lynx Perfetto & Trace Domain Types (For all 34 Exported `.dynsym` Symbols)
//    Các kiểu miền Lynx Perfetto & Trace (Cho toàn bộ 34 biểu tượng xuất `.dynsym`)
// ============================================================================

enum class TraceEventType : int32_t {
    kBegin   = 0,
    kEnd     = 1,
    kInstant = 2,
    kCounter = 3,
};

enum class FlowDirection : int32_t {
    kUnspecified = 0,
    kOut         = 1,
    kIn          = 2,
    kInOut       = 3,
};

struct Track {
    uint64_t uuid = 0;
};

struct ThreadTrack : public Track {
    static ThreadTrack Current() noexcept;
};

struct CounterTrack : public Track {
    const char* name = nullptr;
};

} // namespace lynxtrace
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LYNXTRACE_TYPES_H_
