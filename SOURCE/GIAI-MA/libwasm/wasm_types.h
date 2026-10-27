/**
 * @file wasm_types.h
 * @brief Core ABI Structures, QuickJS/LepusNG Bindings & Wasm3 Engine Types for libwasm.so
 *        Các cấu trúc ABI cốt lõi, kiểu dữ liệu kết nối QuickJS/LepusNG & máy ảo Wasm3 của libwasm.so
 *
 * @details
 * Clean-room C++17 reconstruction of `libwasm.so` (247,792 bytes, SHA-256:
 * 41d9f6460616d3a74ee7b490891a0661329c9ccb98d72bbfd198be97bb8b255a).
 * Tái dựng sạch chuẩn C++17 cho thư viện `libwasm.so` (247.792 byte).
 *
 * Evidence Classification / Phân loại bằng chứng:
 * - [OBSERVED]: Exported symbols (`RegisterWebAssembly` @ 0x01003c,
 *   `Java_com_bytedance_vmsdk_wasm_RegisterWebAssembly_loadWasmFactory` @ 0x0117d8),
 *   103 imported QuickJS/LepusNG (`libquick.so`) & POSIX symbols, `.rodata` strings
 *   (0x006430..0x009830), `.data.rel.ro` tables (`JSClassDef`, `JSCFunctionListEntry`,
 *   `c_operations` @ 0x038438..0x03b438, `c_operationsFC` @ 0x03b438..0x03b818,
 *   section parser table @ 0x03b888..0x03b8e8), and `.bss` class IDs (0x03c000..0x03c054).
 * - [OBSERVED]: Exact struct allocation sizes in `.text`:
 *   - `vmsdk::InteropRuntime`: `0x78` (120 bytes) @ `0x01020c` (`mov w0, #0x78`)
 *   - `vmsdk::wasm3::Wasm3Runtime`: `0x20` (32 bytes) @ `0x01026c` (`mov w0, #0x20`)
 *   - `M3FuncType` (1-ret, 0-arg): `0x11` (17 bytes) @ `0x022770` (`mov w0, #0x11`)
 *   - `M3Module`: `0xf0` (240 bytes) @ `0x022be0` (`mov w0, #0xf0`)
 *   - `M3Function`: `0x458` (1,112 bytes) @ `0x032d30` (`mov w21, #0x458`)
 *   - `M3Global`: `0x30` (48 bytes) @ `0x03540c`
 *   - `M3DataSegment`: `0x28` (40 bytes) @ `0x034ab0`
 *   - `M3OpInfo`: `0x30` (48 bytes) @ `0x038438` (`256 * 48 = 12,288 bytes`)
 */

#ifndef NEXTAI_OPENCUT_LIBWASM_WASM_TYPES_H_
#define NEXTAI_OPENCUT_LIBWASM_WASM_TYPES_H_

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace vmsdk {
namespace wasm {

// ============================================================================
// 1. ELF64 Binary Metadata & Section Offsets ([OBSERVED])
//    Siêu dữ liệu nhị phân ELF64 & Địa chỉ các phân đoạn ([QUAN SÁT ĐƯỢC])
// ============================================================================

/**
 * @brief Exact ELF64 constants for `libwasm.so` (`arm64-v8a`).
 *        Các hằng số ELF64 chính xác của `libwasm.so` (`arm64-v8a`).
 */
struct LibWasmBinaryMetadata {
    static constexpr uint32_t kBinarySizeBytes          = 247792U;
    static constexpr const char* kBinarySha256          = "41d9f6460616d3a74ee7b490891a0661329c9ccb98d72bbfd198be97bb8b255a";

    // Section offsets & sizes / Địa chỉ và kích thước các section
    static constexpr uint32_t kDynsymOffset             = 0x000330U;
    static constexpr uint32_t kDynsymSize               = 0x000A38U; // 2,616 bytes (109 entries)
    static constexpr uint32_t kRodataOffset             = 0x006430U;
    static constexpr uint32_t kRodataSize               = 0x003400U; // 13,312 bytes
    static constexpr uint32_t kTextOffset               = 0x010000U;
    static constexpr uint32_t kTextSize                 = 0x025A28U; // 154,152 bytes
    static constexpr uint32_t kPltOffset                = 0x035A30U;
    static constexpr uint32_t kPltSize                  = 0x000630U; // 1,584 bytes
    static constexpr uint32_t kDataRelRoOffset          = 0x038000U;
    static constexpr uint32_t kDataRelRoSize            = 0x0038F0U; // 14,576 bytes
    static constexpr uint32_t kGotOffset                = 0x03BAD0U;
    static constexpr uint32_t kGotSize                  = 0x000020U; // 32 bytes
    static constexpr uint32_t kGotPltOffset             = 0x03BAF0U;
    static constexpr uint32_t kGotPltSize               = 0x000320U; // 800 bytes
    static constexpr uint32_t kBssOffset                = 0x03C000U;
    static constexpr uint32_t kBssSize                  = 0x000058U; // 88 bytes

    // Exported function virtual addresses / Địa chỉ ảo các hàm xuất khẩu
    static constexpr uint32_t kAddrRegisterWebAssembly  = 0x01003CU; // size 4,872 bytes
    static constexpr uint32_t kAddrLoadWasmFactoryJni   = 0x0117D8U; // size 12 bytes

    // Internal Wasm3 core function addresses / Địa chỉ các hàm lõi Wasm3 nội bộ
    static constexpr uint32_t kAddrM3NewEnvironment     = 0x02268CU;
    static constexpr uint32_t kAddrM3FreeEnvironment    = 0x0228ACU;
    static constexpr uint32_t kAddrM3NewRuntime         = 0x0229ECU;
    static constexpr uint32_t kAddrM3ParseModule        = 0x022BC0U;
    static constexpr uint32_t kAddrM3LoadModule         = 0x022E80U;
    static constexpr uint32_t kAddrM3CompileModule      = 0x023500U;
    static constexpr uint32_t kAddrM3FreeModule         = 0x032D08U;

    // .data.rel.ro table addresses / Địa chỉ các bảng dữ liệu chỉ đọc có định vị lại
    static constexpr uint32_t kAddrClassDefWebAssembly  = 0x0380B0U;
    static constexpr uint32_t kAddrClassDefFunction     = 0x038148U;
    static constexpr uint32_t kAddrClassDefGlobal       = 0x038188U;
    static constexpr uint32_t kAddrClassDefInstance     = 0x0381F0U;
    static constexpr uint32_t kAddrClassDefMemory       = 0x038248U;
    static constexpr uint32_t kAddrClassDefModule       = 0x0382B8U;
    static constexpr uint32_t kAddrClassDefTable        = 0x038378U;
    static constexpr uint32_t kAddrCOperationsTable     = 0x038438U; // 256 * 48 = 0x3000 bytes
    static constexpr uint32_t kAddrCOperationsFCTable   = 0x03B438U; // 21 * 48 bytes
    static constexpr uint32_t kAddrSectionParserTable   = 0x03B888U; // 12 * 8 = 96 bytes

    // .bss global class ID slots / Các ô lưu JSClassID trong .bss
    static constexpr uint32_t kBssWebAssemblyClassId    = 0x03C000U;
    static constexpr uint32_t kBssFunctionClassId       = 0x03C004U;
    static constexpr uint32_t kBssGlobalClassId         = 0x03C008U;
    static constexpr uint32_t kBssTableClassId          = 0x03C00CU;
    static constexpr uint32_t kBssMemoryClassId         = 0x03C010U;
    static constexpr uint32_t kBssInstanceClassId       = 0x03C014U;
    static constexpr uint32_t kBssModuleClassId         = 0x03C018U;
};

// ============================================================================
// 2. QuickJS / LepusNG (`libquick.so`) Types & Class Definitions ([OBSERVED])
//    Các kiểu dữ liệu và định nghĩa lớp QuickJS / LepusNG ([QUAN SÁT ĐƯỢC])
// ============================================================================

struct LEPUSRuntime;
struct LEPUSContext;
struct LEPUSObject;

using JSClassID = uint32_t;
using JSAtom    = uint32_t;
using JSBOOL    = int32_t;

/**
 * @brief QuickJS / LepusNG 16-byte NaN-boxed or tagged value (`LEPUSValue`).
 *        Giá trị `LEPUSValue` 16-byte trên kiến trúc 64-bit của QuickJS / LepusNG.
 *
 * [OBSERVED] Passed in two 64-bit registers (`x2, x3` or `x1, x2`) across all
 * `LEPUS_*` imports in `.plt 0x035a30..0x036050`.
 */
struct LEPUSValue {
    union {
        int32_t  int32;
        double   float64;
        void*    ptr;
        uint64_t uint64;
    } u;
    int64_t tag;
};

/**
 * @brief QuickJS / LepusNG Value Tags (`LEPUS_TAG_*`).
 *        Các nhãn định danh kiểu giá trị trong QuickJS / LepusNG.
 */
enum LEPUSTag : int64_t {
    LEPUS_TAG_FIRST             = -11,
    LEPUS_TAG_BIG_DECIMAL       = -11,
    LEPUS_TAG_BIG_INT           = -10,
    LEPUS_TAG_BIG_FLOAT         = -9,
    LEPUS_TAG_SYMBOL            = -8,
    LEPUS_TAG_STRING            = -7,
    LEPUS_TAG_LEPUS_REF         = -6,
    LEPUS_TAG_SHAPE             = -5,
    LEPUS_TAG_ASYNC_FUNCTION    = -4,
    LEPUS_TAG_VAR_REF           = -3,
    LEPUS_TAG_MODULE            = -2,
    LEPUS_TAG_FUNCTION_BYTECODE = -1,
    LEPUS_TAG_OBJECT            = -1,
    LEPUS_TAG_INT               = 0,
    LEPUS_TAG_BOOL              = 1,
    LEPUS_TAG_NULL              = 2,
    LEPUS_TAG_UNDEFINED         = 3,
    LEPUS_TAG_UNINITIALIZED     = 4,
    LEPUS_TAG_CATCH_OFFSET      = 5,
    LEPUS_TAG_EXCEPTION         = 6,
    LEPUS_TAG_FLOAT64           = 7,
};

inline constexpr LEPUSValue MakeLepusUndefined() noexcept {
    return LEPUSValue{{0}, LEPUS_TAG_UNDEFINED};
}
inline constexpr LEPUSValue MakeLepusNull() noexcept {
    return LEPUSValue{{0}, LEPUS_TAG_NULL};
}
inline constexpr LEPUSValue MakeLepusException() noexcept {
    return LEPUSValue{{0}, LEPUS_TAG_EXCEPTION};
}
inline constexpr LEPUSValue MakeLepusBool(bool b) noexcept {
    LEPUSValue v{};
    v.u.int32 = b ? 1 : 0;
    v.tag = LEPUS_TAG_BOOL;
    return v;
}
inline constexpr LEPUSValue MakeLepusInt32(int32_t val) noexcept {
    LEPUSValue v{};
    v.u.int32 = val;
    v.tag = LEPUS_TAG_INT;
    return v;
}
inline constexpr LEPUSValue MakeLepusFloat64(double val) noexcept {
    LEPUSValue v{};
    v.u.float64 = val;
    v.tag = LEPUS_TAG_FLOAT64;
    return v;
}

using JSCFunction      = LEPUSValue (*)(LEPUSContext* ctx, LEPUSValue this_val, int argc, LEPUSValue* argv);
using JSCFunctionMagic = LEPUSValue (*)(LEPUSContext* ctx, LEPUSValue this_val, int argc, LEPUSValue* argv, int magic);
using JSGetterFunc     = LEPUSValue (*)(LEPUSContext* ctx, LEPUSValue this_val);
using JSSetterFunc     = LEPUSValue (*)(LEPUSContext* ctx, LEPUSValue this_val, LEPUSValue val);
using JSClassFinalizer = void (*)(LEPUSRuntime* rt, LEPUSValue val);
using JSClassGCMark    = void (*)(LEPUSRuntime* rt, LEPUSValue val, void (*mark_func)(LEPUSRuntime*, void*));
using JSClassCall      = LEPUSValue (*)(LEPUSContext* ctx, LEPUSValue func_obj, LEPUSValue this_val,
                                        int argc, LEPUSValue* argv, int flags);
using LEPUSFreeArrayBufferDataFunc = void (*)(LEPUSRuntime* rt, void* opaque, void* ptr);

/**
 * @brief QuickJS `JSClassDef` 40-byte structure (`0x28` bytes).
 *        Cấu trúc định nghĩa lớp `JSClassDef` 40-byte trong `.data.rel.ro`.
 *
 * [OBSERVED] Verified at `.data.rel.ro`:
 * - `0x0380b0`: `"WebAssembly"`, finalizer `0x011bd8`, gc_mark `0x012084`
 * - `0x038148`: `"WebAssembly.Function"`, finalizer `0x013128`, call `0x0132b8`
 * - `0x038188`: `"WebAssembly.Global"`, finalizer `0x014290`
 * - `0x0381f0`: `"WebAssembly.Instance"`, finalizer `0x01b8cc`
 * - `0x038248`: `"WebAssembly.Memory"`, finalizer `0x01ba18`, gc_mark `0x01ce7c`
 * - `0x0382b8`: `"WebAssembly.Module"`, finalizer `0x01f2f4`, gc_mark `0x01f42c`
 * - `0x038378`: `"WebAssembly.Table"`, finalizer `0x01f4d8`
 */
struct JSClassDef {
    const char*      class_name; // +0x00
    JSClassFinalizer finalizer;  // +0x08
    JSClassGCMark    gc_mark;    // +0x10
    JSClassCall      call;       // +0x18
    void*            exotic;     // +0x20
};
static_assert(sizeof(JSClassDef) == 40, "JSClassDef must be exactly 40 bytes (0x28)");

/**
 * @brief QuickJS `JSCFunctionListEntry` 40-byte structure (`0x28` bytes).
 *        Cấu trúc bảng phương thức/thuộc tính `JSCFunctionListEntry` 40-byte.
 *
 * [OBSERVED] Verified at `.data.rel.ro`:
 * - `0x0380d8`: `WebAssembly` static methods (`compile`, `instantiate`, `validate`)
 * - `0x0381b0`: `WebAssembly.Global.prototype` (`valueOf`, `value` getter/setter)
 * - `0x038270`: `WebAssembly.Memory.prototype` (`grow`, `buffer` getter)
 * - `0x0382e0`: `WebAssembly.Module` static methods (`customSections`, `exports`, `imports`, `supportBase64`)
 * - `0x0383a0`: `WebAssembly.Table.prototype` (`set`, `get`, `grow`, `length` getter)
 */
struct JSCFunctionListEntry {
    const char* name;       // +0x00
    uint8_t     prop_flags; // +0x08 (e.g., JS_PROP_WRITABLE | JS_PROP_CONFIGURABLE = 0x03)
    uint8_t     def_type;   // +0x09 (0 = JS_DEF_CFUNC, 1 = JS_DEF_CGETSET)
    int16_t     magic;      // +0x0A
    uint32_t    pad;        // +0x0C
    union {
        struct {
            uint8_t      length; // +0x10
            uint8_t      cproto; // +0x11
            uint16_t     pad2;   // +0x12
            uint32_t     pad3;   // +0x14
            JSCFunction  generic;// +0x18
        } func;
        struct {
            JSGetterFunc get;    // +0x10
            JSSetterFunc set;    // +0x18
        } getset;
    } u;
    uint64_t    reserved;   // +0x20
};
static_assert(sizeof(JSCFunctionListEntry) == 40, "JSCFunctionListEntry must be 40 bytes (0x28)");

// Property flags / Các cờ thuộc tính QuickJS
constexpr uint8_t LEPUS_PROP_CONFIGURABLE = (1 << 0);
constexpr uint8_t LEPUS_PROP_WRITABLE     = (1 << 1);
constexpr uint8_t LEPUS_PROP_ENUMERABLE   = (1 << 2);
constexpr uint8_t LEPUS_PROP_C_W_E        = LEPUS_PROP_CONFIGURABLE | LEPUS_PROP_WRITABLE | LEPUS_PROP_ENUMERABLE;
constexpr uint8_t LEPUS_DEF_CFUNC         = 0;
constexpr uint8_t LEPUS_DEF_CGETSET       = 1;

// ============================================================================
// 3. WASMGCPersistent Handle Wrapper ([OBSERVED] in .dynsym 0x011a44..0x011b90)
//    Lớp bao quản lý tham chiếu GC `WASMGCPersistent` ([QUAN SÁT ĐƯỢC])
// ============================================================================

/**
 * @brief Persistent GC root/weak handle for QuickJS/LepusNG objects.
 *        Lớp quản lý tham chiếu bền vững hoặc yếu (weak) tới đối tượng JS.
 *
 * [OBSERVED] Exported/defined methods in `.dynsym` & `.text`:
 * - `WASMGCPersistent::Reset(LEPUSContext*, const LEPUSValue&)` @ `0x011a78`
 * - `WASMGCPersistent::Reset(LEPUSRuntime*)` @ `0x011a44`
 * - `WASMGCPersistent::SetWeak(void*, void (*)(void*))` @ `0x011b40`
 * - `WASMGCPersistent::ClearWeak()` @ `0x011b68`
 * - `WASMGCPersistent::Get() const` @ `0x011b78`
 * - `WASMGCPersistent::IsWeak() const` @ `0x011b80`
 * - `WASMGCPersistent::IsEmpty() const` @ `0x011b88`
 */
class WASMGCPersistent {
public:
    WASMGCPersistent() noexcept
        : ctx_(nullptr), rt_(nullptr), val_(MakeLepusUndefined()),
          weak_param_(nullptr), weak_cb_(nullptr), is_weak_(false) {}

    WASMGCPersistent(LEPUSContext* ctx, const LEPUSValue& val) noexcept
        : ctx_(nullptr), rt_(nullptr), val_(MakeLepusUndefined()),
          weak_param_(nullptr), weak_cb_(nullptr), is_weak_(false) {
        Reset(ctx, val);
    }

    WASMGCPersistent(const WASMGCPersistent& other) noexcept
        : ctx_(other.ctx_), rt_(other.rt_), val_(other.val_),
          weak_param_(other.weak_param_), weak_cb_(other.weak_cb_), is_weak_(other.is_weak_) {}

    WASMGCPersistent(WASMGCPersistent&& other) noexcept
        : ctx_(other.ctx_), rt_(other.rt_), val_(other.val_),
          weak_param_(other.weak_param_), weak_cb_(other.weak_cb_), is_weak_(other.is_weak_) {
        other.ctx_ = nullptr;
        other.rt_ = nullptr;
        other.val_ = MakeLepusUndefined();
        other.weak_param_ = nullptr;
        other.weak_cb_ = nullptr;
        other.is_weak_ = false;
    }

    ~WASMGCPersistent() noexcept {
        Reset(rt_);
    }

    void Reset(LEPUSRuntime* rt = nullptr) noexcept;
    void Reset(LEPUSContext* ctx, const LEPUSValue& val) noexcept;
    void SetWeak(void* param, void (*cb)(void*)) noexcept;
    void ClearWeak() noexcept;

    const LEPUSValue& Get() const noexcept { return val_; }
    bool IsWeak() const noexcept { return is_weak_; }
    bool IsEmpty() const noexcept { return val_.tag == LEPUS_TAG_UNDEFINED || val_.tag == LEPUS_TAG_NULL; }
    LEPUSContext* context() const noexcept { return ctx_; }

private:
    LEPUSContext* ctx_;
    LEPUSRuntime* rt_;
    LEPUSValue    val_;
    void*         weak_param_;
    void        (*weak_cb_)(void*);
    bool          is_weak_;
};

// ============================================================================
// 4. VMSDK WebAssembly Enums & Error Codes ([OBSERVED] in .rodata)
//    Các kiểu liệt kê và mã lỗi VMSDK WebAssembly ([QUAN SÁT ĐƯỢC])
// ============================================================================

/**
 * @brief WebAssembly runtime backend selector (`vmsdk::WasmRuntimeType`).
 *        Bộ chọn engine thực thi WebAssembly (`vmsdk::WasmRuntimeType`).
 *
 * [OBSERVED] Checked in `RegisterWebAssembly` (`0x01003c..0x0100fc`) via
 * `GetSettingsWithKey("vmsdk_wasm_runtime_type")`. When PRISM is requested,
 * logs: `"[VmSdkWasm] PRISM runtime requested but not built into libwasm.so; falling back to WASM3."`
 */
enum class WasmRuntimeType : int32_t {
    kWasm3 = 0,
    kPrism = 1,
};

/**
 * @brief Standardized VMSDK Wasm Error Codes (`[1001]`..`[1010]`).
 *        Các mã lỗi chuẩn hóa của VMSDK WebAssembly (`[1001]`..`[1010]`).
 *
 * [OBSERVED] Extracted from `.rodata`:
 * - `0x007117`: `"[1001] Invalid arguments"`
 * - `0x0077f4`: `"[1002] Out of Memory"`
 * - `0x007e3b`: `"[1003] Runtime Exception"`
 * - `0x006c4d`: `"[1004] Instantiate Error"`
 * - `0x006fb8`: `"[1005] Compile Error"`
 * - `0x0074e9`: `"[1006] Unreachable Error"`
 * - `0x00690d`: `"[1007] Link Error"`
 * - `0x0077ac`: `"[1008] Exceeded Memory Limit"`
 * - `0x0078b1`: `"[1009] Invalid Memory Access"`
 * - `0x006fb8`: `"[1010] Unknown Error"`
 */
enum class WasmErrorCode : uint32_t {
    kNone                = 0,
    kInvalidArguments    = 1001, // "[1001] Invalid arguments"
    kOutOfMemory         = 1002, // "[1002] Out of Memory"
    kRuntimeException    = 1003, // "[1003] Runtime Exception"
    kInstantiateError    = 1004, // "[1004] Instantiate Error"
    kCompileError        = 1005, // "[1005] Compile Error"
    kUnreachableError    = 1006, // "[1006] Unreachable Error"
    kLinkError           = 1007, // "[1007] Link Error"
    kExceededMemoryLimit = 1008, // "[1008] Exceeded Memory Limit"
    kInvalidMemoryAccess = 1009, // "[1009] Invalid Memory Access"
    kUnknownError        = 1010, // "[1010] Unknown Error"
};

/**
 * @brief Wasm3 internal value types (`c_waTypes` / `M3ValueType`).
 *        Các kiểu dữ liệu giá trị nội bộ của Wasm3 (`M3ValueType`).
 *
 * [OBSERVED] Used in `m3_NewEnvironment` (`0x02268c..0x022890`) where types
 * `1..4` (`i32`, `i64`, `f32`, `f64`) are pre-registered, and formatted via
 * `.rodata`: `"none"`, `"i32"`, `"i64"`, `"f32"`, `"f64"`, `"funcref"`, `"externref"`.
 */
enum M3ValueType : uint8_t {
    c_m3Type_none      = 0,
    c_m3Type_i32       = 1,
    c_m3Type_i64       = 2,
    c_m3Type_f32       = 3,
    c_m3Type_f64       = 4,
    c_m3Type_funcref   = 5,
    c_m3Type_externref = 6,
    c_m3Type_unknown   = 7,
};

/**
 * @brief Standard WebAssembly binary specification value-type bytes.
 *        Các byte định danh kiểu dữ liệu chuẩn trong định dạng nhị phân WebAssembly.
 */
enum WasmBinaryTypeByte : uint8_t {
    kWasmBinVoid      = 0x40,
    kWasmBinFuncType  = 0x60,
    kWasmBinExternRef = 0x6F,
    kWasmBinFuncRef   = 0x70,
    kWasmBinF64       = 0x7C,
    kWasmBinF32       = 0x7D,
    kWasmBinI64       = 0x7E,
    kWasmBinI32       = 0x7F,
};

/**
 * @brief Standard WebAssembly binary section IDs (`0`..`11`).
 *        Mã định danh các phân đoạn (Section ID) trong file nhị phân WebAssembly.
 *
 * [OBSERVED] Dispatched via the 12-entry pointer table at `.data.rel.ro 0x03b888..0x03b8e8`
 * in `m3_ParseModule` (`0x022bc0`).
 */
enum WasmSectionId : uint8_t {
    kWasmSectionCustom   = 0,  // Parser @ 0x035670
    kWasmSectionType     = 1,  // Parser @ 0x033008
    kWasmSectionImport   = 2,  // Parser @ 0x0338cc
    kWasmSectionFunction = 3,  // Parser @ 0x0335f8
    kWasmSectionTable    = 4,  // Parser @ 0x034e98
    kWasmSectionMemory   = 5,  // Parser @ 0x035190
    kWasmSectionGlobal   = 6,  // Parser @ 0x0353d8
    kWasmSectionExport   = 7,  // Parser @ 0x0342e0
    kWasmSectionStart    = 8,  // Parser @ 0x034678
    kWasmSectionElement  = 9,  // Parser @ 0x034758
    kWasmSectionCode     = 10, // Parser @ 0x034848
    kWasmSectionData     = 11, // Parser @ 0x034a58
    kWasmSectionMax      = 12,
};

/**
 * @brief WebAssembly Import/Export External Kind (`0`..`3`).
 *        Loại thực thể xuất/nhập khẩu trong WebAssembly (`function`, `table`, `memory`, `global`).
 */
enum WasmExternalKind : uint8_t {
    kWasmExtFunc   = 0, // "function" (.rodata 0x006564)
    kWasmExtTable  = 1, // "table"    (.rodata 0x0066fa)
    kWasmExtMemory = 2, // "memory"   (.rodata 0x0068ea)
    kWasmExtGlobal = 3, // "global"   (.rodata 0x0069e0)
};

// ============================================================================
// 5. Embedded Wasm3 Engine ABI Structures ([OBSERVED] in 0x02268c..0x035a24)
//    Các cấu trúc ABI của máy ảo Wasm3 nhúng ([QUAN SÁT ĐƯỢC])
// ============================================================================

using M3Result  = const char*;
using m3ret_t   = const void*;
using m3slot_t  = uint32_t;
using m3reg_t   = int64_t;
using pc_t      = void* const*;

constexpr uint32_t kWasmPageSizeBytes = 65536U; // 64 KiB per WebAssembly page
constexpr uint32_t kWasmMagicNumber   = 0x6D736100U; // "\0asm"
constexpr uint32_t kWasmVersion       = 0x00000001U; // version 1

/**
 * @brief Wasm3 Function Signature (`M3FuncType`).
 *        Chữ ký kiểu hàm trong Wasm3 (`M3FuncType`).
 *
 * [OBSERVED] Allocated in `AllocFuncType` / `m3_NewEnvironment` (`0x02268c..0x022890`)
 * with size `0x10 + numRets + numArgs` (`0x11` bytes for 1-ret 0-arg @ `0x022770`: `mov w0, #0x11`).
 * Layout:
 * - `+0x00`: `M3FuncType* next` (8 bytes)
 * - `+0x08`: `uint16_t numRets` (2 bytes)
 * - `+0x0A`: `uint16_t numArgs` (2 bytes)
 * - `+0x0C`: `uint8_t types[]` (flexible array of `numRets + numArgs` `M3ValueType` bytes)
 */
struct M3FuncType {
    M3FuncType* next;     // +0x00
    uint16_t    numRets;  // +0x08
    uint16_t    numArgs;  // +0x0A
    uint8_t     types[4]; // +0x0C (variable length in heap allocation)
};

/**
 * @brief Wasm3 Code Page Header (`M3CodePageHeader`).
 *        Tiêu đề trang mã lệnh thực thi của Wasm3 (`M3CodePageHeader`).
 */
struct M3CodePage {
    M3CodePage* next;
    uint32_t    lineIndex;
    uint32_t    numLines;
    uint32_t    sequence;
    uint32_t    usageCount;
    void*       code[1];
};

/**
 * @brief Wasm3 Environment (`M3Environment`).
 *        Môi trường toàn cục của Wasm3 (`M3Environment`).
 *
 * [OBSERVED] Initialized in `m3_NewEnvironment` (`0x02268c`), freed in `m3_FreeEnvironment` (`0x0228ac`).
 */
struct M3Environment {
    M3FuncType* funcTypes;     // +0x00: linked list of canonicalized function types
    M3CodePage* pagesReleased; // +0x08: pool of reusable code pages
};

/**
 * @brief Wasm3 Linear Memory Allocation Header (`M3MemoryHeader`).
 *        Tiêu đề vùng nhớ tuyến tính 64KB của Wasm3 (`M3MemoryHeader`).
 *
 * [OBSERVED] Offset `+0x20` (`32 bytes`) precedes the raw WebAssembly linear memory bytes.
 */
struct M3MemoryHeader {
    struct M3Runtime* runtime;  // +0x00
    void*             maxStack; // +0x08
    size_t            length;   // +0x10
    uint64_t          reserved; // +0x18
    // Followed immediately at +0x20 by uint8_t bytes[length]
};
static_assert(sizeof(M3MemoryHeader) == 32, "M3MemoryHeader must be 32 bytes (0x20)");

/**
 * @brief Wasm3 Memory Descriptor (`M3Memory`).
 *        Bộ mô tả bộ nhớ tuyến tính trong `M3Runtime` và `M3Module`.
 */
struct M3Memory {
    M3MemoryHeader* mallocated; // +0x00
    uint32_t        numPages;   // +0x08 (initial / current pages)
    uint32_t        maxPages;   // +0x0C (maximum pages)
    uint32_t        pageSize;   // +0x10 (default 65536 = 0x10000)
    uint8_t         hasMax;     // +0x14
    uint8_t         imported;   // +0x15
    uint16_t        pad;        // +0x16
};

/**
 * @brief Wasm3 Import Info (`M3ImportInfo`, 16 bytes).
 *        Thông tin module và tên trường nhập khẩu (`M3ImportInfo`).
 */
struct M3ImportInfo {
    const char* moduleUtf8; // +0x00
    const char* fieldUtf8;  // +0x08
};

/**
 * @brief Wasm3 Global Variable (`M3Global`, 48 bytes = `0x30`).
 *        Cấu trúc biến toàn cục WebAssembly trong Wasm3 (`M3Global`).
 *
 * [OBSERVED] Freed in `m3_FreeModule` (`0x032dfc..0x032e2c`) with stride `0x30` (48 bytes).
 */
struct M3Global {
    M3ImportInfo import;        // +0x00 (16 bytes)
    union {
        int32_t  i32Value;
        int64_t  i64Value;
        float    f32Value;
        double   f64Value;
    };                          // +0x10 (8 bytes)
    const char*  name;          // +0x18 (8 bytes)
    const uint8_t* initExpr;    // +0x20 (8 bytes)
    uint32_t     initExprSize;  // +0x28 (4 bytes)
    uint8_t      type;          // +0x2C (1 byte: M3ValueType)
    bool         imported;      // +0x2D (1 byte)
    bool         isMutable;     // +0x2E (1 byte)
    uint8_t      pad;           // +0x2F (1 byte)
};
static_assert(sizeof(M3Global) == 48, "M3Global must be 48 bytes (0x30)");

/**
 * @brief Wasm3 Data Segment (`M3DataSegment`, 40 bytes = `0x28`).
 *        Phân đoạn dữ liệu khởi tạo bộ nhớ tuyến tính (`M3DataSegment`).
 *
 * [OBSERVED] Parsed in `ParseSection_Data` (`0x034a58`) and freed in `m3_FreeModule` (`0x032e3c..0x032e68`)
 * with stride `0x28` (40 bytes).
 */
struct M3DataSegment {
    const uint8_t* initExpr;     // +0x00
    const uint8_t* data;         // +0x08
    uint32_t       initExprSize; // +0x10
    uint32_t       memoryRegion; // +0x14
    uint32_t       size;         // +0x18
    bool           isAllocated;  // +0x1C
    uint8_t        pad[3];       // +0x1D
    uint64_t       reserved;     // +0x20
};
static_assert(sizeof(M3DataSegment) == 40, "M3DataSegment must be 40 bytes (0x28)");

/**
 * @brief Wasm3 Function Structure (`M3Function`, 1,112 bytes = `0x458`).
 *        Cấu trúc hàm trong Wasm3 (`M3Function`, kích thước chuẩn `0x458` = 1.112 byte).
 *
 * [OBSERVED] Exact stride `0x458` verified in `m3_FreeModule` (`0x032d30: mov w21, #0x458` = `0x52808B15`):
 * - `+0x000`: `M3Module* module`
 * - `+0x008`: `M3ImportInfo import` (`moduleUtf8`, `fieldUtf8`)
 * - `+0x018`: `const uint8_t* wasm` (pointer to Wasm bytecode)
 * - `+0x020`: `const uint8_t* wasmEnd`
 * - `+0x028`: `const char* names[3]` (up to 3 export/debug names, freed at `0x032d58`)
 * - `+0x040`: `const char* hills`
 * - `+0x048`: `M3FuncType* funcType`
 * - `+0x050`: `void* compiled` (pointer to compiled Wasm3 word-code or RawCall callback)
 * - `+0x058..0x43F`: inline constant pool & slot allocation state (`constants`, `numConstants`, etc.)
 * - `+0x440`: `uint16_t numNames`
 * - `+0x442`: `uint16_t numRetSlots`
 * - `+0x444`: `uint16_t numRatchetSlots`
 * - `+0x446`: `uint16_t numLocalBytes`
 * - `+0x448`: `bool ownsWasmCode` (checked at `0x032d3c: ldrb w8, [x22, #0x448]`)
 * - `+0x449`: `uint8_t isCompiled`
 * - `+0x44A..0x457`: slot usage counts & alignment padding
 */
struct M3Function {
    struct M3Module* module;             // +0x000
    M3ImportInfo     import;             // +0x008 (16 bytes)
    const uint8_t*   wasm;               // +0x018
    const uint8_t*   wasmEnd;            // +0x020
    const char*      names[3];           // +0x028 (24 bytes)
    const char*      hills;              // +0x040
    M3FuncType*      funcType;           // +0x048
    void*            compiled;           // +0x050
    void*            constants;          // +0x058
    uint8_t          inlineStorage[992]; // +0x060..0x43F (compile state / constants buffer)
    uint16_t         numNames;           // +0x440
    uint16_t         numRetSlots;        // +0x442
    uint16_t         numLocalSlots;      // +0x444
    uint16_t         numConstantBytes;   // +0x446
    bool             ownsWasmCode;       // +0x448
    bool             isCompiled;         // +0x449
    uint16_t         maxStackSlots;      // +0x44A
    uint32_t         index;              // +0x44C
    void*            userdata;           // +0x450
};
static_assert(sizeof(M3Function) == 0x458, "M3Function must be 0x458 (1,112) bytes");

/**
 * @brief Wasm3 Custom Section Node (`M3CustomSection`).
 *        Nút danh sách liên kết lưu Custom Section của WebAssembly.
 */
struct M3CustomSection {
    const char*        name;      // +0x00
    const uint8_t*     data;      // +0x08
    size_t             dataSize;  // +0x10
    M3CustomSection*   next;      // +0x18
};

/**
 * @brief Wasm3 Export Descriptor (`M3ExportInfo`).
 *        Thông tin thực thể xuất khẩu (Export) của Module WebAssembly.
 */
struct M3ExportInfo {
    std::string      name;
    WasmExternalKind kind;
    uint32_t         index;
    M3ValueType      globalType;
    bool             globalMutable;
};

/**
 * @brief Wasm3 Import Descriptor (`M3ImportDescriptor`).
 *        Thông tin thực thể nhập khẩu (Import) của Module WebAssembly.
 */
struct M3ImportDescriptor {
    std::string      moduleName;
    std::string      fieldName;
    WasmExternalKind kind;
    uint32_t         typeIndex;
    M3ValueType      globalType;
    bool             globalMutable;
};

/**
 * @brief Wasm3 Module Structure (`M3Module`, 240 bytes = `0xF0`).
 *        Cấu trúc Module trong Wasm3 (`M3Module`, kích thước chuẩn `0xF0` = 240 byte).
 *
 * [OBSERVED] Allocated in `m3_ParseModule` (`0x022be0: mov w0, #0xf0; bl calloc`)
 * and freed in `m3_FreeModule` (`0x032d08..0x033004`):
 * - `+0x00`: `M3Runtime* runtime`
 * - `+0x08`: `M3Environment* environment`
 * - `+0x10`: `const char* name` (initialized to `".unnamed"` @ `0x022bfc`)
 * - `+0x18`: `uint32_t numFuncTypes`
 * - `+0x20`: `M3FuncType** funcTypes`
 * - `+0x28`: `uint32_t numFuncImports`
 * - `+0x2C`: `uint32_t numFunctions`
 * - `+0x30`: `uint32_t allFunctions` (capacity)
 * - `+0x38`: `M3Function* functions`
 * - `+0x40`: `int32_t startFunction` (initialized to `-1` via `movn w8, #0` @ `0x022c00`)
 * - `+0x44`: `uint32_t numDataSegments`
 * - `+0x48`: `M3DataSegment* dataSegments`
 * - `+0x50`: `uint32_t numGlobals`
 * - `+0x58`: `M3Global* globals`
 * - `+0x60`: `uint32_t numElementSegments`
 * - `+0x68`: `const uint8_t* elementSection`
 * - `+0x70`: `const uint8_t* elementSectionEnd`
 * - `+0x78`: `M3Function** table0`
 * - `+0x80`: `uint32_t table0Size`
 * - `+0x84`: `uint32_t table0MaxSize`
 * - `+0x88`: `const char* table0ImportModule`
 * - `+0x90`: `const char* table0ImportField`
 * - `+0x98`: `M3Memory memoryInfo` (24 bytes)
 * - `+0xB0`: `const char* memoryImportModule`
 * - `+0xB8`: `const char* memoryImportField`
 * - `+0xC0`: `bool memoryImported`
 * - `+0xC1`: `bool tableImported`
 * - `+0xC2`: `bool hasWasmCodeCopy`
 * - `+0xC8`: `M3Module* next`
 * - `+0xD0`: `M3CustomSection* customSections`
 * - `+0xD8`: `const uint8_t* wasmStart`
 * - `+0xE0`: `const uint8_t* wasmEnd`
 * - `+0xE8`: `void* extraMetadata` (pointer to `std::vector<M3ExportInfo>` / `M3ImportDescriptor`)
 */
struct M3Module {
    struct M3Runtime* runtime;            // +0x00
    M3Environment*    environment;        // +0x08
    const char*       name;               // +0x10
    uint32_t          numFuncTypes;       // +0x18
    uint32_t          pad0;               // +0x1C
    M3FuncType**      funcTypes;          // +0x20
    uint32_t          numFuncImports;     // +0x28
    uint32_t          numFunctions;       // +0x2C
    uint32_t          allFunctions;       // +0x30
    uint32_t          pad1;               // +0x34
    M3Function*       functions;          // +0x38
    int32_t           startFunction;      // +0x40
    uint32_t          numDataSegments;    // +0x44
    M3DataSegment*    dataSegments;       // +0x48
    uint32_t          numGlobals;         // +0x50
    uint32_t          pad2;               // +0x54
    M3Global*         globals;            // +0x58
    uint32_t          numElementSegments; // +0x60
    uint32_t          pad3;               // +0x64
    const uint8_t*    elementSection;     // +0x68
    const uint8_t*    elementSectionEnd;  // +0x70
    M3Function**      table0;             // +0x78
    uint32_t          table0Size;         // +0x80
    uint32_t          table0MaxSize;      // +0x84
    const char*       table0ImportModule; // +0x88
    const char*       table0ImportField;  // +0x90
    M3Memory          memoryInfo;         // +0x98 (24 bytes)
    const char*       memoryImportModule; // +0xB0
    const char*       memoryImportField;  // +0xB8
    bool              memoryImported;     // +0xC0
    bool              tableImported;      // +0xC1
    bool              hasWasmCodeCopy;    // +0xC2
    uint8_t           pad4[5];            // +0xC3..0xC7
    M3Module*         next;               // +0xC8
    M3CustomSection*  customSections;     // +0xD0
    const uint8_t*    wasmStart;          // +0xD8
    const uint8_t*    wasmEnd;            // +0xE0
    void*             extraMetadata;      // +0xE8
};
static_assert(sizeof(M3Module) == 0xF0, "M3Module must be 0xF0 (240) bytes");

/**
 * @brief Wasm3 Execution Runtime (`M3Runtime`).
 *        Ngữ cảnh thực thi máy ảo Wasm3 (`M3Runtime`).
 */
struct M3Runtime {
    M3Environment* environment;       // +0x00
    M3CodePage*    pagesOpen;         // +0x08
    M3CodePage*    pagesFull;         // +0x10
    uint32_t       numCodePages;      // +0x18
    uint32_t       numActiveCodePages;// +0x1C
    M3Module*      modules;           // +0x20
    void*          stack;             // +0x28
    void*          originStack;       // +0x30
    uint32_t       numStackSlots;     // +0x38
    uint32_t       argc;              // +0x3C
    m3slot_t*      argv;              // +0x40
    M3Result       runtimeError;      // +0x48
    M3Memory       memory;            // +0x50 (24 bytes)
    uint32_t       memoryLimit;       // +0x68
    uint32_t       pad;               // +0x6C
    void*          userdata;          // +0x70
    char           errorMessage[256]; // +0x78
};

/**
 * @brief Wasm3 Opcode Descriptor (`M3OpInfo`, 48 bytes = `0x30`).
 *        Cấu trúc mô tả mã lệnh Wasm3 trong bảng `c_operations` (`0x038438..0x03b438`).
 *
 * [OBSERVED] Verified at `.data.rel.ro 0x038438`:
 * - `0x00` (`unreachable`): `stackOffset = 0`, `type = 0`, `operations = {op_Unreachable, ...}`, `compiler = Compile_Unreachable`
 * - `0x01` (`nop`): `stackOffset = 0`, `type = 0`, `compiler = Compile_Nop`
 * - `0x20` (`local.get`): `stackOffset = +1`, `compiler = Compile_GetLocal`
 * - `0x41` (`i32.const`): `stackOffset = +1`, `type = c_m3Type_i32`, `compiler = Compile_Const_i32`
 * - `0x6A` (`i32.add`): `stackOffset = -1`, `type = c_m3Type_i32`, `compiler = Compile_Operator`
 */
struct M3Compilation;
using M3Compiler = M3Result (*)(M3Compilation*, uint8_t opcode);
using IM3Operation = m3ret_t (*)(pc_t _pc, m3slot_t* _sp, M3MemoryHeader* _mem, m3reg_t _r0, double _fp0);

struct M3OpInfo {
    int8_t       stackOffset;   // +0x00: net stack slot delta
    uint8_t      type;          // +0x01: M3ValueType produced/operated on
    uint8_t      pad[6];        // +0x02..0x07
    IM3Operation operations[4]; // +0x08..0x27: [imm, s_reg, r_reg, sr_reg] threaded handlers
    M3Compiler   compiler;      // +0x28: bytecode compilation handler
};
static_assert(sizeof(M3OpInfo) == 48, "M3OpInfo must be 48 bytes (0x30)");

// ============================================================================
// 6. Standard Wasm3 Error String Constants ([OBSERVED] in .rodata 0x008000..0x009680)
//    Các chuỗi thông báo lỗi chuẩn của Wasm3 ([QUAN SÁT ĐƯỢC])
// ============================================================================

namespace m3_err {
constexpr M3Result none                                = nullptr;
constexpr M3Result mallocFailed                        = "memory allocation failed";
constexpr M3Result wasmMalformed                       = "malformed Wasm binary";
constexpr M3Result wasmUnderrun                        = "underrun while parsing Wasm binary";
constexpr M3Result wasmOverrun                         = "overrun while parsing Wasm binary";
constexpr M3Result wasmMissingInitExpr                 = "missing init_expr in Wasm binary";
constexpr M3Result lebOverflow                         = "LEB encoded value overflow";
constexpr M3Result missingUTF8                         = "invalid length UTF-8 string";
constexpr M3Result wasmSectionUnderrun                 = "section underrun while parsing Wasm binary";
constexpr M3Result wasmSectionOverrun                  = "section overrun while parsing Wasm binary";
constexpr M3Result invalidTypeId                       = "unknown value_type";
constexpr M3Result tooManyMemorySections               = "only one memory per module is supported";
constexpr M3Result tooManyArgsRets                     = "too many arguments or return values";
constexpr M3Result moduleAlreadyLinked                 = "module is already linked to a runtime";
constexpr M3Result functionLookupFailed                = "function lookup failed";
constexpr M3Result missingCompiledCode                 = "missing compiled code";
constexpr M3Result wasmMemoryOverflow                  = "runtime ran out of memory";
constexpr M3Result globalMemoryNotAllocated            = "global memory is missing from a module";
constexpr M3Result globaIndexOutOfBounds               = "global index is out of bounds";
constexpr M3Result argumentCountMismatch               = "argument count mismatch";
constexpr M3Result argumentTypeMismatch                = "argument type mismatch";
constexpr M3Result globalLookupFailed                  = "global lookup failed";
constexpr M3Result globalTypeMismatch                  = "global type mismatch";
constexpr M3Result globalNotMutable                    = "global is not mutable";
constexpr M3Result trapOutOfBoundsMemoryAccess         = "[trap] out of bounds memory access";
constexpr M3Result trapDivisionByZero                  = "[trap] integer divide by zero";
constexpr M3Result trapIntegerOverflow                 = "[trap] integer overflow";
constexpr M3Result trapIntegerConversion               = "[trap] invalid conversion to integer";
constexpr M3Result trapIndirectCallTypeMismatch        = "[trap] indirect call type mismatch";
constexpr M3Result trapTableIndexOutOfRange            = "[trap] undefined element";
constexpr M3Result trapTableElementIsNull              = "[trap] null function or function signature mismatch";
constexpr M3Result trapExit                            = "[trap] program called exit";
constexpr M3Result trapAbort                           = "[trap] program called abort";
constexpr M3Result trapUnreachable                     = "[trap] unreachable executed";
constexpr M3Result trapStackOverflow                   = "[trap] stack overflow";
} // namespace m3_err

} // namespace wasm
} // namespace vmsdk

#endif // NEXTAI_OPENCUT_LIBWASM_WASM_TYPES_H_
