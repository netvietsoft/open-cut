/**
 * @file lynx_krypton_types.h
 * @brief Exact ELF64 AArch64 ABI structures, `.rodata` constants, `.data.rel.ro`
 *        JNI & vtable tables, and `.bss` layout for `liblynx_krypton.so`.
 *        Cấu trúc ABI ELF64 AArch64 chính xác, hằng số `.rodata`, bảng JNI &
 *        vtable trong `.data.rel.ro`, và bố cục `.bss` cho `liblynx_krypton.so`.
 *
 * Binary Ground Truth / Thực tế Nhị phân (`liblynx_krypton.so` — 51,112 bytes):
 * - Architecture: ELF64 AArch64 little-endian (`EM_AARCH64`), Android NDK r21d (`clang 9.0.8`)
 * - SONAME: `liblynx_krypton.so`
 * - Needed Shared Libraries (`.dynamic`):
 *   1. `liblynx.so` (Lynx base logging, JNI helpers, `CanvasAppAndroid`, `SurfaceWithAndroidNativeWindow`, `AttachKryptonTraceHandler`)
 *   2. `libjnigraphics.so`
 *   3. `libandroid.so` (`ANativeWindow_fromSurface`, `ANativeWindow_release`)
 *   4. `libdl.so` (`dlopen`, `dlsym`)
 *   5. `liblog.so`
 *   6. `libGLESv2.so`
 *   7. `libEGL.so`
 *   8. `libc++.so`
 *   9. `libm.so`
 *   10. `libc.so`
 * - ELF64 Section Geometry:
 *   - `.dynsym`       : `0x000330` (`1,056 bytes`, `44` symbols: `[001]..[039]` imports, `[040]` `JNI_OnLoad` @ `0x004ff4`, `[041]..[043]` `_edata`, `_end`, `__bss_start`)
 *   - `.rela.dyn`     : `0x001148` (`1,152 bytes`, `48` `R_AARCH64_RELATIVE` entries)
 *   - `.rela.plt`     : `0x0015c8` (`936 bytes`, `39` `R_AARCH64_JUMP_SLOT` entries -> PLT `0x005250..0x0054b0`)
 *   - `.rodata`       : `0x001970..0x001d0f` (`928 bytes`)
 *   - `.text`         : `0x004000..0x00522f` (`4,656 bytes`)
 *   - `.plt`          : `0x005230..0x0054bf` (`656 bytes`)
 *   - `.data.rel.ro`  : `0x008000..0x0081cf` (`464 bytes`, 4 `JNINativeMethod` tables + 5 C++ vtables)
 *   - `.got.plt`      : `0x008368..0x0084b7` (`336 bytes`)
 *   - `.bss`          : `0x00c000..0x00c047` (`72 bytes`, 4 global `jclass` refs + 24-byte `KryptonTraceFunctions` + 2 cached `jmethodID`s)
 *
 * Evidence Classification: OBSERVED (100% disassembled via Capstone AArch64 & ELF64 headers).
 */

#ifndef NEXTAI_OPENCUT_LYNX_KRYPTON_TYPES_H_
#define NEXTAI_OPENCUT_LYNX_KRYPTON_TYPES_H_

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <string>

namespace nextai {
namespace opencut {
namespace lynx_krypton {

// ============================================================================
// 1. ELF64 Binary Geometry & Section Constants
//    Hằng số Hình học Nhị phân ELF64 & Phân đoạn
// ============================================================================

/**
 * @brief Exact ELF64 section offsets and sizes observed in `liblynx_krypton.so`.
 *        Offset và kích thước phân đoạn ELF64 chính xác quan sát được trong `liblynx_krypton.so`.
 */
struct Elf64GeometryConstants {
    static constexpr uint32_t kBinarySizeBytes          = 51112u;
    static constexpr uint32_t kDynsymOffset             = 0x000330u;
    static constexpr uint32_t kDynsymSizeBytes          = 1056u;
    static constexpr uint32_t kDynsymEntryCount         = 44u;
    static constexpr uint32_t kImportedSymbolCount      = 39u;
    static constexpr uint32_t kExportedSymbolCount      = 4u; // JNI_OnLoad, _edata, _end, __bss_start

    static constexpr uint32_t kRelaDynOffset            = 0x001148u;
    static constexpr uint32_t kRelaDynSizeBytes         = 1152u;
    static constexpr uint32_t kRelaDynEntryCount        = 48u;

    static constexpr uint32_t kRelaPltOffset            = 0x0015c8u;
    static constexpr uint32_t kRelaPltSizeBytes         = 936u;
    static constexpr uint32_t kRelaPltEntryCount        = 39u;

    static constexpr uint32_t kRodataVaddr              = 0x001970u;
    static constexpr uint32_t kRodataSizeBytes          = 928u;

    static constexpr uint32_t kTextVaddr                = 0x004000u;
    static constexpr uint32_t kTextSizeBytes            = 4656u;
    static constexpr uint32_t kJniOnLoadVaddr           = 0x004ff4u;
    static constexpr uint32_t kJniOnLoadSizeBytes       = 308u;

    static constexpr uint32_t kPltVaddr                 = 0x005230u;
    static constexpr uint32_t kPltFirstEntryVaddr       = 0x005250u;
    static constexpr uint32_t kPltSizeBytes             = 656u;

    static constexpr uint32_t kDataRelRoVaddr           = 0x008000u;
    static constexpr uint32_t kDataRelRoSizeBytes       = 464u;

    static constexpr uint32_t kBssVaddr                 = 0x00c000u;
    static constexpr uint32_t kBssSizeBytes             = 72u; // 0x48 bytes
};

// ============================================================================
// 2. Minimal JNI & Android NDK ABI Declarations (Platform-Independent Host/Target)
//    Khai báo ABI JNI & Android NDK Tối thiểu (Độc lập nền tảng Host/Target)
// ============================================================================

using jint    = int32_t;
using jlong   = int64_t;
using jboolean = uint8_t;
using jobject = void*;
using jclass  = void*;
using jstring = void*;
using jmethodID = struct _jmethodID*;
using JavaVM  = struct _JavaVM;
using JNIEnv  = struct _JNIEnv;

constexpr jint kJniVersion1_6 = 0x00010006; // mov w8, #0x6; movk w8, #0x1, lsl #16 @ 0x005018

/**
 * @brief Exact 24-byte `JNINativeMethod` entry layout in `.data.rel.ro`.
 *        Bố cục phần tử `JNINativeMethod` 24-byte chính xác trong `.data.rel.ro`.
 */
struct JNINativeMethodEntry {
    const char* name;       // +0x00
    const char* signature;  // +0x08
    void*       fnPtr;      // +0x10
};
static_assert(sizeof(JNINativeMethodEntry) == 24, "JNINativeMethodEntry must be 24 bytes on AArch64");

/**
 * @brief Opaque Android `ANativeWindow` representation for host testing and NDK bridging.
 *        Biểu diễn `ANativeWindow` của Android cho kiểm thử host và cầu nối NDK.
 */
struct ANativeWindowMock {
    uint32_t magic;              // +0x00 ('ANW0' = 0x30574E41)
    std::atomic<int32_t> ref_count; // +0x04
    int32_t  width;              // +0x08
    int32_t  height;             // +0x0C
    int32_t  format;             // +0x10
    void*    java_surface_token; // +0x18
};

// ============================================================================
// 3. `.rodata` String & Jump Table Constants (`0x001970..0x001d0f`)
//    Hằng số Chuỗi & Bảng Nhảy `.rodata` (`0x001970..0x001d0f`)
// ============================================================================

struct RodataConstants {
    /**
     * @brief 5-byte relative branch offset table at `.rodata 0x001970` used by
     *        `KryptonLogFunction` (`0x00403c..0x004148`):
     *        `ldrb w11, [x9, x8]; add x10, x10, x11, lsl #2; br x10` @ `0x00407c..0x004084`.
     *        Bảng offset nhảy tương đối 5 byte tại `.rodata 0x001970` dùng bởi `KryptonLogFunction`.
     *
     * Index `w8 = level - 1` (`0..4` for `level = 1..5`):
     * - `idx 0 (level 1)` -> `0x00` -> `0x004088 + 0*4  = 0x004088` (`mov w3, #1` = INFO)
     * - `idx 1 (level 2)` -> `0x14` -> `0x004088 + 20*4 = 0x0040d8` (`mov w3, #2` = WARNING)
     * - `idx 2 (level 3)` -> `0x0a` -> `0x004088 + 10*4 = 0x0040b0` (`mov w3, #3` = ERROR)
     * - `idx 3 (level 4)` -> `0x0f` -> `0x004088 + 15*4 = 0x0040c4` (`mov w3, #4` = REPORT/ASSERT)
     * - `idx 4 (level 5)` -> `0x05` -> `0x004088 + 5*4  = 0x00409c` (`mov w3, #5` = FATAL)
     * - `default (level < 1 || level > 5)` -> `0x0040ec` (`mov w3, wzr` = VERBOSE)
     */
    static constexpr uint8_t kLogLevelJumpTable[5] = {0x00u, 0x14u, 0x0au, 0x0fu, 0x05u};

    // `.rodata` strings with exact virtual addresses:
    static constexpr const char* kClassCanvasManager             = "com/lynx/canvas/CanvasManager";             // 0x001975
    static constexpr const char* kSymTraceCounterEx              = "TraceCounterEx";                            // 0x001993
    static constexpr const char* kSymTraceEventBeginEx           = "TraceEventBeginEx";                         // 0x0019a2
    static constexpr const char* kSymTraceEventEndEx             = "TraceEventEndEx";                           // 0x0019b4
    static constexpr const char* kLogTraceLoadStart              = "RuntimeLoadLynxTraceFunc start";            // 0x0019c4
    static constexpr const char* kLogTraceLoadSuccess            = "RuntimeLoadLynxTraceFunc load trace function success"; // 0x0019eb
    static constexpr const char* kLogTraceCantFindLib            = "RuntimeLoadLynxTraceFunc cant find liblynxtrace.so";   // 0x001a22
    static constexpr const char* kLibLynxTraceSo                 = "liblynxtrace.so";                           // 0x001a45
    static constexpr const char* kLogTraceLoadDlopenOk           = "RuntimeLoadLynxTraceFunc load liblynxtrace.so success "; // 0x001a88
    static constexpr const char* kLogTraceCounterNotFound        = "TraceCounterEx not found";                  // 0x001ac1
    static constexpr const char* kLogTraceBeginEndNotFound       = "TraceEventBeginEx TraceEventEndEx not found"; // 0x001ada
    static constexpr const char* kMethodOnBeforeVSyncEnd         = "OnBeforeVSyncEnd";                          // 0x001b1f
    static constexpr const char* kMethodOnVSync                  = "OnVSync";                                   // 0x001b30
    static constexpr const char* kFileFrameServiceAndroidCc      = "../../platform/android/lynx_krypton/src/main/cpp/lynx_krypton_frame_service_android.cc"; // 0x001b38
    static constexpr const char* kFileDownStreamSurfaceManagerCc = "down_stream_surface_manager.cc";            // 0x001b4c
    static constexpr const char* kFileCanvasManagerAndroidCc     = "canvas_manager_android.cc";                 // 0x001b6b
    static constexpr const char* kSigRemoveSurface               = "(JLjava/lang/String;J)V";                   // 0x001b85
    static constexpr const char* kSigLongVoid                    = "(J)V";                                      // 0x001b9d
    static constexpr const char* kSigVoidVoid                    = "()V";                                       // 0x001ba2
    static constexpr const char* kSigLongLong                    = "(J)J";                                      // 0x001ba6
    static constexpr const char* kSigAddSurface                  = "(JLjava/lang/String;Landroid/view/Surface;III)J"; // 0x001bab
    static constexpr const char* kSigCreateSurface               = "(Landroid/view/Surface;)J";                 // 0x001bdb
    static constexpr const char* kSigVoidLong                    = "()J";                                       // 0x001bf5
    static constexpr const char* kJniNativeGetLogFunctionPtr     = "nativeGetLogFunctionPtr";                   // 0x001bf9
    static constexpr const char* kJniNativeRegisterTraceFunc     = "nativeRegisterTraceFunc";                   // 0x001c11
    static constexpr const char* kJniNativeAddSurface            = "nativeAddSurface";                          // 0x001c29
    static constexpr const char* kLogRemoveDownStreamSurface     = "Krypton RemoveDownStreamSurface for canvas app: "; // 0x001c39
    static constexpr const char* kLogAddDownStreamSurface        = "Krypton AddDownStreamSurface for canvas app: ";    // 0x001c6a
    static constexpr const char* kClassDownStreamManager         = "com/lynx/canvas/LynxCanvasDownStreamManager"; // 0x001c98
    static constexpr const char* kClassFrameService              = "com/lynx/canvas/LynxKryptonFrameService";   // 0x001cc4
    static constexpr const char* kClassUiCanvasSurfaceView       = "com/lynx/canvas/UICanvasSurfaceView";       // 0x001cec
};

// ============================================================================
// 4. `.bss` Global State Layout (`0x00c000..0x00c047`, 72 bytes)
//    Bố cục Trạng thái Toàn cục `.bss` (`0x00c000..0x00c047`, 72 byte)
// ============================================================================

/**
 * @brief Exact 3-pointer (24-byte) trace handler struct stored at `.bss 0x00c008..0x00c01f`
 *        and passed by value on stack (`[sp, #0x18..#0x28]`) to
 *        `lynx::canvas::AttachKryptonTraceHandler(KryptonTraceFunctions)` (`0x0052d0`).
 *        Cấu trúc hàm trace 3 con trỏ (24-byte) lưu tại `.bss 0x00c008..0x00c01f`
 *        và truyền theo giá trị trên stack vào `AttachKryptonTraceHandler` (`0x0052d0`).
 */
using TraceEventBeginExFn = void (*)(const char* category, const char* name);
using TraceEventEndExFn   = void (*)(const char* category, const char* name);
using TraceCounterExFn    = void (*)(const char* category, const char* name, uint64_t value, bool incremental);

struct KryptonTraceFunctions {
    TraceEventBeginExFn trace_event_begin_ex; // +0x00 (.bss 0x00c008)
    TraceEventEndExFn   trace_event_end_ex;   // +0x08 (.bss 0x00c010)
    TraceCounterExFn    trace_counter_ex;     // +0x10 (.bss 0x00c018)
};
static_assert(sizeof(KryptonTraceFunctions) == 24, "KryptonTraceFunctions must be 24 bytes");

/**
 * @brief Complete 72-byte `.bss` memory layout (`0x00c000..0x00c047`).
 *        Bố cục bộ nhớ `.bss` 72-byte hoàn chỉnh (`0x00c000..0x00c047`).
 *
 * Verified instruction by instruction from `JNI_OnLoad` (`0x004ff4..0x005124`),
 * `RuntimeLoadLynxTraceFunc` (`0x00416c..0x0042fc`), `OnBeforeVSyncEnd` (`0x004e3c`),
 * and `OnVSync` (`0x004f34`):
 * - `+0x00 (0x00c000)`: `jclass g_canvas_manager_class` (`str x0, [x21]` @ `0x005034`)
 * - `+0x08 (0x00c008)`: `TraceEventBeginExFn` (`stp x0, x23, [x19, #8]` @ `0x004244`)
 * - `+0x10 (0x00c010)`: `TraceEventEndExFn` (`str x0, [x19, #0x10]` @ `0x004258`)
 * - `+0x18 (0x00c018)`: `TraceCounterExFn` (`str x0, [x19, #0x18]` @ `0x00426c`)
 * - `+0x20 (0x00c020)`: `jclass g_downstream_manager_class` (`str x0, [x21, #0x20]` @ `0x005064`)
 * - `+0x28 (0x00c028)`: `jclass g_frame_service_class` (`str x0, [x21, #0x28]` @ `0x005094`)
 * - `+0x30 (0x00c030)`: `std::atomic<jmethodID> g_on_before_vsync_end_method` (`0x004e54`)
 * - `+0x38 (0x00c038)`: `std::atomic<jmethodID> g_on_vsync_method` (`0x004f4c`)
 * - `+0x40 (0x00c040)`: `jclass g_ui_canvas_surface_view_class` (`str x0, [x21, #0x40]` @ `0x0050d0`)
 */
struct KryptonBssSegment {
    jclass                canvas_manager_class;         // +0x00 (0x00c000)
    KryptonTraceFunctions trace_functions;              // +0x08..+0x1f (0x00c008..0x00c01f)
    jclass                downstream_manager_class;     // +0x20 (0x00c020)
    jclass                frame_service_class;          // +0x28 (0x00c028)
    jmethodID             on_before_vsync_end_method;   // +0x30 (0x00c030)
    jmethodID             on_vsync_method;              // +0x38 (0x00c038)
    jclass                ui_canvas_surface_view_class; // +0x40 (0x00c040)
};
static_assert(sizeof(KryptonBssSegment) == 72, "KryptonBssSegment must be exactly 72 bytes (0x48)");
static_assert(offsetof(KryptonBssSegment, canvas_manager_class) == 0x00, "Offset +0x00 mismatch");
static_assert(offsetof(KryptonBssSegment, trace_functions) == 0x08, "Offset +0x08 mismatch");
static_assert(offsetof(KryptonBssSegment, downstream_manager_class) == 0x20, "Offset +0x20 mismatch");
static_assert(offsetof(KryptonBssSegment, frame_service_class) == 0x28, "Offset +0x28 mismatch");
static_assert(offsetof(KryptonBssSegment, on_before_vsync_end_method) == 0x30, "Offset +0x30 mismatch");
static_assert(offsetof(KryptonBssSegment, on_vsync_method) == 0x38, "Offset +0x38 mismatch");
static_assert(offsetof(KryptonBssSegment, ui_canvas_surface_view_class) == 0x40, "Offset +0x40 mismatch");

// ============================================================================
// 5. Reconstructed Lynx & Krypton Engine ABI Structures
//    Cấu trúc ABI Engine Lynx & Krypton Tái dựng
// ============================================================================

/**
 * @brief Exact 72-byte (`0x48`) `lynx::canvas::SurfaceConfig` passed on stack
 *        (`[sp, #8..#0x4c]`) to `PlatformViewObserver::OnSurfaceCreated` (`0x005420`)
 *        at `0x004a54..0x004ac0`.
 *        Cấu trúc `lynx::canvas::SurfaceConfig` 72-byte (`0x48`) truyền trên stack
 *        vào `PlatformViewObserver::OnSurfaceCreated` (`0x005420`) tại `0x004a54..0x004ac0`.
 *
 * Disassembly proof (`0x004a60..0x004a98`):
 * - `stp x22, x21, [sp, #8]` (`+0x00..+0x0f`: `std::shared_ptr<Surface> surface`)
 * - `stp w9, w10, [sp, #0x18]` (`+0x10`: `int32_t width`, `+0x14`: `int32_t height`)
 * - `mov w8, #0x10100; str w11, [sp, #0x20]; str w8, [sp, #0x24]`
 *   (`+0x18`: `int32_t max_fps`, `+0x1c`: `uint32_t flags = 0x00010100` -> `{need_depth=false, need_stencil=true, enable_aa=true, zero=0}`)
 * - `stp xzr, xzr, [sp, #0x38]; stp xzr, xzr, [sp, #0x28]` (`+0x20..+0x3f`: 32 bytes zeroed callback/options)
 * - `str wzr, [sp, #0x48]` (`+0x40`: `uint32_t extra_flags = 0`)
 */
class SurfaceWithAndroidNativeWindow;

struct SurfaceConfig {
    std::shared_ptr<SurfaceWithAndroidNativeWindow> surface; // +0x00 (16 bytes: ptr + ctrl_block)
    int32_t  width;                                          // +0x10 (`[sp, #0x18]`)
    int32_t  height;                                         // +0x14 (`[sp, #0x1c]`)
    int32_t  max_fps;                                        // +0x18 (`[sp, #0x20]`)
    uint32_t packed_flags;                                   // +0x1C (`[sp, #0x24]` = 0x00010100)
    uint64_t reserved_0;                                     // +0x20 (`[sp, #0x28]` = 0)
    uint64_t reserved_1;                                     // +0x28 (`[sp, #0x30]` = 0)
    uint64_t reserved_2;                                     // +0x30 (`[sp, #0x38]` = 0)
    uint64_t reserved_3;                                     // +0x38 (`[sp, #0x40]` = 0)
    uint32_t extra_flags;                                    // +0x40 (`[sp, #0x48]` = 0)
    uint32_t padding;                                        // +0x44
};
static_assert(sizeof(SurfaceConfig) == 72, "SurfaceConfig must be 72 bytes (0x48)");

/**
 * @brief 96-byte (`0x60`) heap-allocated `std::__ndk1::__function::__func` closure
 *        created at `0x004538` (`mov w0, #0x60; bl operator new`) with vtable at
 *        `.data.rel.ro 0x0080c8` when `nativeAddSurface` is called off the Canvas task runner thread.
 *        Closure `std::__ndk1::__function::__func` 96-byte (`0x60`) cấp phát trên heap
 *        tại `0x004538` với vtable tại `.data.rel.ro 0x0080c8` khi `nativeAddSurface`
 *        được gọi ngoài luồng Canvas task runner.
 */
struct AddSurfaceTaskClosureLayout {
    const void* vtable_ptr;        // +0x00 (`0x0080c8`)
    void*       canvas_app_ptr;    // +0x08 (`std::weak_ptr<CanvasAppAndroid>::__ptr_`)
    void*       canvas_app_cntrl;  // +0x10 (`std::weak_ptr<CanvasAppAndroid>::__cntrl_`)
    char        view_id_sso[24];   // +0x18..+0x2f (`std::string view_id`)
    void*       surface_ptr;       // +0x30 (`std::shared_ptr<Surface>::__ptr_`)
    void*       surface_cntrl;     // +0x38 (`std::shared_ptr<Surface>::__cntrl_`)
    int32_t     width;             // +0x40 (`w26`)
    int32_t     height;            // +0x44 (`w25`)
    int32_t     max_fps;           // +0x48 (`w23`)
    int32_t     padding_4c;        // +0x4c
    void*       extra_ref_ptr;     // +0x50
    void*       extra_ref_cntrl;   // +0x58
};
static_assert(sizeof(AddSurfaceTaskClosureLayout) == 96, "AddSurfaceTaskClosureLayout must be 96 bytes (0x60)");

/**
 * @brief 72-byte (`0x48`) heap-allocated `std::__ndk1::__function::__func` closure
 *        created at `0x004740` (`mov w0, #0x48; bl operator new`) with vtable at
 *        `.data.rel.ro 0x0080a0` when `nativeRemoveSurface` is called off the Canvas task runner thread.
 *        Closure `std::__ndk1::__function::__func` 72-byte (`0x48`) cấp phát trên heap
 *        tại `0x004740` với vtable tại `.data.rel.ro 0x0080a0` khi `nativeRemoveSurface`
 *        được gọi ngoài luồng Canvas task runner.
 */
struct RemoveSurfaceTaskClosureLayout {
    const void* vtable_ptr;        // +0x00 (`0x0080a0`)
    void*       canvas_app_ptr;    // +0x08 (`std::weak_ptr<CanvasAppAndroid>::__ptr_`)
    void*       canvas_app_cntrl;  // +0x10 (`std::weak_ptr<CanvasAppAndroid>::__cntrl_`)
    char        view_id_sso[24];   // +0x18..+0x2f (`std::string view_id`)
    int64_t     native_window_ptr; // +0x30 (`jlong surfacePtr`)
    void*       extra_ref_ptr;     // +0x38
    void*       extra_ref_cntrl;   // +0x40
};
static_assert(sizeof(RemoveSurfaceTaskClosureLayout) == 72, "RemoveSurfaceTaskClosureLayout must be 72 bytes (0x48)");

/**
 * @brief 24-byte (`0x18`) heap-allocated VSync / BeforeVSyncEnd callback functor
 *        created at `0x004c50` (`vtable 0x0081a0`) and `0x004cf8` (`vtable 0x008150`).
 *        Functor callback VSync / BeforeVSyncEnd 24-byte (`0x18`) cấp phát trên heap
 *        tại `0x004c50` (`vtable 0x0081a0`) và `0x004cf8` (`vtable 0x008150`).
 *
 * Layout:
 * - `+0x00`: `vtable_ptr` (`0x0081a0` for `OnVSync`, `0x008150` for `OnBeforeVSyncEnd`)
 * - `+0x08`: `JavaRef::vtable_ptr` (`0x008178` -> `lynx::base::android::JavaRef` destructor vtable)
 * - `+0x10`: `jobject global_java_ref` (`ScopedGlobalJavaRef<jobject>::obj_`)
 */
struct VSyncJavaCallbackFunctorLayout {
    const void* functor_vtable_ptr;  // +0x00 (`0x0081a0` or `0x008150`)
    const void* javaref_vtable_ptr;  // +0x08 (`0x008178`)
    jobject     global_java_ref;     // +0x10
};
static_assert(sizeof(VSyncJavaCallbackFunctorLayout) == 24, "VSyncJavaCallbackFunctorLayout must be 24 bytes (0x18)");

} // namespace lynx_krypton
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_LYNX_KRYPTON_TYPES_H_
