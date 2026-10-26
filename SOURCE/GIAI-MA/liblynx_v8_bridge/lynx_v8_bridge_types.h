// ============================================================================
// File: lynx_v8_bridge_types.h
// Target: liblynx_v8_bridge.so (117,008 bytes, 26 ELF64 sections, 188 .dynsym)
// SHA-256: a056a8578279f5b2aa07946891d83c060858fcdde25c31096bb3cdd09a53ad65
// Task ID: TASK-109-RECONSTRUCTION-LIBLYNX_V8_BRIDGE / TASK_SO_134_liblynx_v8_bridge
// Description:
//   [EN] Exact ABI structures, ELF64 section offsets, .rodata string literals,
//        V8 internal tag constants, and MurmurHash64A / Robin-Hood hash bucket
//        definitions reconstructed from liblynx_v8_bridge.so AArch64 opcodes.
//   [VN] Các cấu trúc ABI chính xác, offset phân đoạn ELF64, chuỗi hằng .rodata,
//        hằng số tag nội bộ V8, và định nghĩa băm MurmurHash64A / bucket băm
//        tái dựng từ mã máy AArch64 của liblynx_v8_bridge.so.
// ============================================================================

#pragma once

#include <atomic>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace lynx {
namespace v8_bridge {

// ============================================================================
// [EN] 1. ELF64 Binary Metadata & Section Layout (1:1 VA == File Offset)
// [VN] 1. Siêu dữ liệu nhị phân ELF64 & Bố cục phân đoạn (1:1 VA == File Offset)
// ============================================================================
struct ElfSectionMetadata {
    uint32_t index;
    const char* name;
    uint64_t virtual_address;
    uint64_t file_offset;
    uint64_t size_bytes;
};

constexpr uint64_t kLibLynxV8BridgeSizeBytes = 117008ULL;
constexpr const char* kLibLynxV8BridgeSha256 =
    "a056a8578279f5b2aa07946891d83c060858fcdde25c31096bb3cdd09a53ad65";

constexpr uint64_t kRodataVaStart     = 0x0062f0ULL;
constexpr uint64_t kRodataSizeBytes   = 1386ULL;      // 0x0062f0..0x006859
constexpr uint64_t kTextVaStart       = 0x00c000ULL;
constexpr uint64_t kTextSizeBytes     = 33912ULL;     // 0x00c000..0x014477
constexpr uint64_t kPltVaStart        = 0x014480ULL;
constexpr uint64_t kPltSizeBytes      = 2752ULL;      // 0x014480..0x014f3f
constexpr uint64_t kDataRelRoVaStart  = 0x018000ULL;
constexpr uint64_t kDataRelRoSizeBytes = 2280ULL;     // 0x018000..0x0188e7
constexpr uint64_t kDataVaStart       = 0x01c000ULL;
constexpr uint64_t kDataSizeBytes     = 144ULL;       // 0x01c000..0x01c08f
constexpr uint64_t kBssVaStart        = 0x01c090ULL;
constexpr uint64_t kBssSizeBytes      = 72ULL;        // 0x01c090..0x01c0d7

// ============================================================================
// [EN] 2. Exact .rodata Offsets (VA == File Offset in 0x0062f0..0x006859)
// [VN] 2. Offset chính xác trong .rodata (VA == File Offset tại 0x0062f0..0x006859)
// ============================================================================
namespace rodata {
    // 7-byte relative jump-table for lynx::piper::Value::Kind switch @ 0x012dd0:
    // bytes: {0x00, 0x04, 0x08, 0x11, 0x17, 0x20, 0x26} -> br (0x012df8 + b*4)
    constexpr uint64_t kValueKindJumpTableOffset         = 0x006300ULL;
    constexpr uint64_t kStrBytecodeDisabledOffset        = 0x006307ULL; // "v8 bytecode is disabled in this LynxView"
    constexpr uint64_t kStrV8ContextWrapperInitOffset    = 0x006330ULL; // "V8ContextWrapper Init"
    constexpr uint64_t kStrNotStringOrStringObjOffset    = 0x006346ULL; // "value from v8 is not a string or string object"
    constexpr uint64_t kStrNativeErrorOffset             = 0x006375ULL; // "NativeError"
    constexpr uint64_t kStrV8ContextWrapperDtorOffset    = 0x006381ULL; // "~V8ContextWrapper"
    constexpr uint64_t kStrHostFunctionOffset            = 0x006393ULL; // "hostFunction"
    constexpr uint64_t kStrNullOffset                    = 0x0063a0ULL; // "Null"
    constexpr uint64_t kStrCallOffset                    = 0x0063a5ULL; // "call"
    constexpr uint64_t kStrSettingNapiFactoryOffset      = 0x0063aaULL; // "Setting napi factory from external"
    constexpr uint64_t kStrStackOffset                   = 0x0063cdULL; // "stack"
    constexpr uint64_t kStrLengthOffset                  = 0x0063d3ULL; // "length"
    constexpr uint64_t kStrJsiHeaderOffset               = 0x0063daULL; // "jsi.h"
    constexpr uint64_t kStrV8RuntimeHeaderPathOffset     = 0x0063e0ULL; // "/ws/.../lynx/core/runtime/jsi/v8/v8_runtime.h"
    constexpr uint64_t kStrToStringOffset                = 0x006465ULL; // "toString"
    constexpr uint64_t kStrHostFunctionFlagOffset        = 0x00646eULL; // "hostFunctionFlag"
    constexpr uint64_t kStrValueOfOffset                 = 0x00647fULL; // "valueOf"
    constexpr uint64_t kStrV8RuntimeFinalizeOffset       = 0x006487ULL; // "V8Runtime::Finalize"
    constexpr uint64_t kStrV8ObjectValueOffset           = 0x00649bULL; // "V8ObjectValue"
    constexpr uint64_t kStrV8SymbolValueOffset           = 0x0064a9ULL; // "V8SymbolValue"
    constexpr uint64_t kStrV8StringValueOffset           = 0x0064b7ULL; // "V8StringValue"
    constexpr uint64_t kStrInitIsolateOffset             = 0x0064c5ULL; // "lynx V8IsolateInstanceImpl::InitIsolate"
    constexpr uint64_t kStrCauseOffset                   = 0x0064edULL; // "cause"
    constexpr uint64_t kStrJSIContextReleaseOffset       = 0x0064f3ULL; // "JSIContext Release"
    constexpr uint64_t kStrNameOffset                    = 0x006506ULL; // "name"
    constexpr uint64_t kStrUsingV8BytecodeOffset         = 0x00650bULL; // "using v8 bytecode"
    constexpr uint64_t kStrEvalJSBytecodeOffset          = 0x00651dULL; // "evaluateJavaScriptBytecode"
    constexpr uint64_t kStrV8IsolateInstanceDtorOffset   = 0x006538ULL; // "lynx ~V8IsolateInstance"
    constexpr uint64_t kStrStackAddFailedOffset          = 0x006550ULL; // "stack add failed"
    constexpr uint64_t kStrCauseAddFailedOffset          = 0x006561ULL; // "cause add failed"
    constexpr uint64_t kStrNameAddFailedOffset           = 0x006572ULL; // "name add failed"
    constexpr uint64_t kStrV8HostObjectCcOffset          = 0x006582ULL; // "v8_host_object.cc"
    constexpr uint64_t kStrV8HelperCcPathOffset          = 0x006594ULL; // "/ws/.../lynx/core/runtime/jsi/v8/v8_helper.cc"
    constexpr uint64_t kStrV8HostFunctionCcOffset        = 0x006619ULL; // "v8_host_function.cc"
    constexpr uint64_t kStrV8ContextWrapperImplCcOffset  = 0x00662dULL; // "v8_context_wrapper_impl.cc"
    constexpr uint64_t kStrV8IsolateWrapperImplCcOffset  = 0x006648ULL; // "v8_isolate_wrapper_impl.cc"
    constexpr uint64_t kStrV8RuntimeCcOffset             = 0x006663ULL; // "v8_runtime.cc"
    constexpr uint64_t kStrJniV8BridgeCcOffset           = 0x006671ULL; // "jni_v8_bridge.cc"
    constexpr uint64_t kStrLynxValPrivateKeyOffset       = 0x006682ULL; // "__lynx_val__"
    constexpr uint64_t kStrToJSONOffset                  = 0x00668fULL; // "toJSON"
    constexpr uint64_t kStrRequestGCOffset               = 0x006696ULL; // "RequestGC"
    constexpr uint64_t kStrEvaluateJSStartUrlOffset      = 0x0066a0ULL; // "V8Runtime::evaluateJavaScript start url="
    constexpr uint64_t kStrJSIContextDtorOffset          = 0x0066c9ULL; // "~JSIContext;"
    constexpr uint64_t kStrBytecodeNotSupportedOffset    = 0x0066d6ULL; // "evaluateJavaScriptBytecode not supported in v8"
    constexpr uint64_t kStrExceptionCallingObjOffset     = 0x006705ULL; // "Exception calling object as function. MaybeLocal empty."
    constexpr uint64_t kStrErrorCreateFailedOffset       = 0x00673dULL; // "error create failed."
    constexpr uint64_t kStrHostObjectSetPropErrOffset    = 0x006756ULL; // "V8HostObjectProxy::setProperty Error!"
    constexpr uint64_t kStrHostObjectGetPropErrOffset    = 0x00677cULL; // "V8HostObjectProxy::getProperty Error!"
    constexpr uint64_t kStrHostObjectGetNamesErrOffset   = 0x0067a2ULL; // "V8HostObjectProxy::getPropertyNames Error!"
    constexpr uint64_t kStrHostFuncCallbackErrOffset     = 0x0067cdULL; // "V8HostFunctionProxy::FunctionCallback Error!"
    constexpr uint64_t kStrIsoIsNullOffset               = 0x0067faULL; // "iso is null!"
    constexpr uint64_t kStrGetV8MaxHeapSizeOffset        = 0x00680bULL; // "get v8 MaxHeapSize: "
    constexpr uint64_t kSymUrlLynxCoreOffset             = 0x006820ULL; // "lynx_core" (Exported [179])
    constexpr uint64_t kSymUrlHostOffset                 = 0x00682aULL; // "file://lynx" (Exported [185])
    constexpr uint64_t kStrUrlFileSharedOffset           = 0x006840ULL; // "file://shared"
    constexpr uint64_t kStrUrlFileViewOffset             = 0x00684eULL; // "file://view"
} // namespace rodata

// ============================================================================
// [EN] 3. V8 Internal Tagged-Pointer & InstanceType Constants (AArch64 Opcodes)
// [VN] 3. Hằng số Con trỏ Gắn thẻ & InstanceType Nội bộ V8 (Mã máy AArch64)
// ============================================================================
// Verified at 0x00db74..0x00db98, 0x00dc88..0x00dcd8, 0x00df74..0x00df8c,
// 0x013e7c..0x013e88, and 0x01417c..0x0141ac:
//   and x9, x8, #3 ; cmp x9, #1 (kHeapObjectTag == 1)
//   ldur x9, [x8, #-1]          (load HeapObject Map pointer at offset -1)
//   ldurh w9, [x9, #0xb]        (load Map::instance_type uint16_t at offset +11)
//   cmp w9, #0x80 / #0x7f       (FIRST_NONSTRING_TYPE == 0x80)
//   cmp w9, #0x83               (ODDBALL_TYPE == 0x83 = 131)
//   ldur w8, [x8, #0x2b]        (Oddball::kind_ offset +43 = 0x2b)
//     kind == 3 -> Null ("Null" @ 0x0063a0, ValueKind::Null = 1)
//     kind == 5 -> Undefined (0x500000000 >> 32 == 5, ValueKind::Undefined = 0)
//   cmp w9, #0x410              (JS_OBJECT_TYPE == 0x410 = 1040)
//   sub w10, w10, #0x421; cmp w10, #0x3e9 (JS_SPECIAL_API_OBJECT range 0x421..0x80a)
constexpr uint64_t kV8HeapObjectTagMask         = 0x3ULL;
constexpr uint64_t kV8HeapObjectTag             = 0x1ULL;
constexpr int64_t  kV8MapPointerOffset          = -1LL;
constexpr int64_t  kV8MapInstanceTypeOffset     = 0x0bLL; // +11 bytes from Map raw ptr
constexpr uint16_t kV8FirstNonStringType        = 0x0080U; // Strings have instance_type <= 0x7f
constexpr uint16_t kV8OddballInstanceType       = 0x0083U; // 131
constexpr int64_t  kV8OddballKindOffset         = 0x2bLL;  // +43 bytes from Oddball raw ptr
constexpr uint32_t kV8OddballKindNull           = 3U;
constexpr uint32_t kV8OddballKindUndefined      = 5U;
constexpr uint16_t kV8JsObjectInstanceType      = 0x0410U; // 1040
constexpr uint16_t kV8SpecialApiObjTypeMin      = 0x0421U; // 1057
constexpr uint16_t kV8SpecialApiObjTypeSpan     = 0x03e9U; // 1001 (up to 0x080a)
constexpr int64_t  kV8FastInternalField0Offset  = 0x17LL;  // [x8, #0x17] inlined internal field 0

// ============================================================================
// [EN] 4. MurmurHash64A Constant @ 0x00e9b8..0x00e9f0
// [VN] 4. Hằng số băm MurmurHash64A tại 0x00e9b8..0x00e9f0
// ============================================================================
// Disassembly @ 0x00e9bc..0x00e9d4:
//   mov  x10, #0x2d69
//   movk x10, #0xeb38, lsl #16
//   movk x10, #0xea08, lsl #32
//   movk x10, #0x9ddf, lsl #48
// -> x10 = 0x9ddfea08eb382d69ULL (CityHash / MurmurHash64A kMul mixing constant)
constexpr uint64_t kLynxPointerHashMultiplier = 0x9ddfea08eb382d69ULL;
constexpr uint32_t kLynxPointerHashShift      = 47U;

} // namespace v8_bridge

// ============================================================================
// [EN] 5. lynx::base::Observer & ObserverList (Exported Symbols [180..182])
// [VN] 5. lynx::base::Observer & ObserverList (Biểu tượng xuất [180..182])
// ============================================================================
namespace base {

class Observer {
public:
    virtual ~Observer() = default;
    // [EN] Vtable slot +0x10 (offset 16): invoked by ForEachObserver() @ 0x013574..0x01357c
    //      via bl #0x14428 (`ldr x8, [x8, #0x10]; br x8`).
    // [VN] Khe vtable +0x10 (offset 16): được gọi bởi ForEachObserver() tại 0x013574..0x01357c
    //      thông qua bl #0x14428 (`ldr x8, [x8, #0x10]; br x8`).
    virtual void OnNotify() = 0;
};

// [EN] Intrusive circular doubly-linked list node (`24 bytes = 0x18`), allocated via
//      `operator new(0x18)` at `0x0133ac..0x0133b4` inside `AddObserver`.
// [VN] Nút danh sách liên kết đôi vòng nội xâm (`24 bytes = 0x18`), cấp phát qua
//      `operator new(0x18)` tại `0x0133ac..0x0133b4` bên trong `AddObserver`.
struct ObserverNode {
    ObserverNode* prev; // +0x00
    ObserverNode* next; // +0x08
    Observer* observer; // +0x10
};

static_assert(sizeof(ObserverNode) == 24, "ObserverNode ABI size must be 24 bytes (0x18)");

// [EN] Exported class `lynx::base::ObserverList` (`24 bytes = 0x18` header: sentinel
//      `prev_` at +0x00, `next_` at +0x08, `count_` at +0x10).
// [VN] Lớp xuất khẩu `lynx::base::ObserverList` (`24 bytes = 0x18` phần đầu: nút canh
//      `prev_` tại +0x00, `next_` tại +0x08, `count_` tại +0x10).
class ObserverList {
public:
    ObserverList() noexcept
        : tail_(reinterpret_cast<ObserverNode*>(this)),
          head_(reinterpret_cast<ObserverNode*>(this)),
          count_(0) {}

    ~ObserverList() noexcept;

    // Exported [180] @ 0x0133a0 (SZ=64): _ZN4lynx4base12ObserverList11AddObserverEPNS0_8ObserverE
    void AddObserver(Observer* obs);

    // Exported [181] @ 0x0133e0 (SZ=220): _ZN4lynx4base12ObserverList14RemoveObserverEPNS0_8ObserverE
    void RemoveObserver(Observer* obs);

    // Exported [182] @ 0x013538 (SZ=88): _ZN4lynx4base12ObserverList15ForEachObserverEv
    void ForEachObserver();

    size_t size() const noexcept { return count_; }
    bool empty() const noexcept { return count_ == 0; }

private:
    ObserverNode* tail_; // +0x00 (sentinel prev pointer)
    ObserverNode* head_; // +0x08 (sentinel next pointer)
    size_t count_;       // +0x10 (element count)
};

} // namespace base

// ============================================================================
// [EN] 6. lynx::piper JSI Value, Buffer, PreparedJavaScript & JSError Types
// [VN] 6. Các kiểu dữ liệu JSI Value, Buffer, PreparedJavaScript & JSError
// ============================================================================
namespace piper {

class Runtime;

// [EN] Verified at `0x00dc18..0x00dd78` (V8 Local<Value> -> lynx::piper::Value) and
//      `0x012dd0..0x012ec4` (lynx::piper::Value -> V8 Local<Value> via 7-way jump table @ 0x006300).
// [VN] Xác minh tại `0x00dc18..0x00dd78` (V8 Local<Value> -> lynx::piper::Value) và
//      `0x012dd0..0x012ec4` (lynx::piper::Value -> V8 Local<Value> qua bảng nhảy 7 nhánh @ 0x006300).
enum class ValueKind : int32_t {
    UndefinedKind = 0, // Jump offset +0x00 -> 0x012df8 (isolate_ + 0x118 Undefined slot)
    NullKind      = 1, // Jump offset +0x04 -> 0x012e08 (isolate_ + 0x128 Null slot)
    BooleanKind   = 2, // Jump offset +0x08 -> 0x012e18 (isolate_ + 0x130 True / 0x138 False)
    NumberKind    = 3, // Jump offset +0x11 -> 0x012e3c (v8::Number::New(isolate, double))
    SymbolKind    = 4, // Jump offset +0x17 -> 0x012e54 (cloneSymbol + V8SymbolValue extract)
    StringKind    = 5, // Jump offset +0x20 -> 0x012e78 (cloneString + V8StringValue extract)
    ObjectKind    = 6  // Jump offset +0x26 -> 0x012e90 (cloneObject + V8ObjectValue extract)
};

// [EN] Base class for V8-backed JSI PointerValue (`24 bytes = 0x18`, allocated via
//      `operator new(0x18)` at `0x00dda4`, `0x00de8c` (`0x20` for ObjectValue), `0x00deec`).
// [VN] Lớp cơ sở cho JSI PointerValue trên nền V8 (`24 bytes = 0x18`, cấp phát qua
//      `operator new(0x18)` tại `0x00dda4`, `0x00de8c` (`0x20` cho ObjectValue), `0x00deec`).
struct V8PointerValue {
    virtual ~V8PointerValue();
    virtual void invalidate();          // +0x10 in vtable (`0x00da90`, `0x00db04`)
    virtual const char* Name() const;   // +0x18 in vtable (`"V8SymbolValue"`, `"V8StringValue"`, `"V8ObjectValue"`)

    void* isolate_ptr{nullptr};         // +0x08: v8::Isolate*
    uint64_t global_handle_slot{0};     // +0x10: v8::Persistent / GlobalizeReference handle
    bool is_protected{false};           // +0x18: present on V8ObjectValue (32-byte allocation)
};

struct JSIValue {
    ValueKind kind{ValueKind::UndefinedKind}; // +0x00
    int32_t padding{0};                       // +0x04
    union {
        bool boolean_val;                     // +0x08 (Kind == 2)
        double number_val;                    // +0x08 (Kind == 3)
        V8PointerValue* pointer_val;          // +0x08 (Kind == 4, 5, 6)
        uint64_t raw_bits;
    } data{0};
};

static_assert(sizeof(JSIValue) == 16, "JSIValue ABI size must be 16 bytes (0x10)");

class Buffer {
public:
    virtual ~Buffer() = default;
    virtual size_t size() const = 0;        // +0x10 in vtable
    virtual const uint8_t* data() const = 0;// +0x18 in vtable
};

class StringBuffer final : public Buffer {
public:
    explicit StringBuffer(std::string s) : data_(std::move(s)) {}
    size_t size() const override { return data_.size(); }
    const uint8_t* data() const override {
        return reinterpret_cast<const uint8_t*>(data_.data());
    }
private:
    std::string data_;
};

// [EN] `V8JavaScriptPreparation` (`80 bytes = 0x50`), allocated at `0x013220..0x0132a0`
//      (`mov w0, #0x50; bl operator new`). Inherits `lynx::piper::PreparedJavaScript`.
// [VN] `V8JavaScriptPreparation` (`80 bytes = 0x50`), cấp phát tại `0x013220..0x0132a0`
//      (`mov w0, #0x50; bl operator new`). Kế thừa `lynx::piper::PreparedJavaScript`.
struct V8JavaScriptPreparation {
    virtual ~V8JavaScriptPreparation() = default;
    std::string source_url;                  // +0x08..0x1f (24 bytes libc++ std::string)
    std::shared_ptr<const Buffer> buf;       // +0x20..0x2f (16 bytes shared_ptr)
    bool has_bytecode_option{false};         // +0x30
    std::string bytecode_cache_url;          // +0x30/0x38..0x47
    bool cache_hit{false};                   // +0x48
};

// [EN] `V8CpuProfileNodeRecord` (`120 bytes = 0x78`), verified at `0x00c9f0..0x00cd0c`:
//      `mov w11, #0x78; sdiv x20, x8, x11` @ `0x00cc20..0x00cc30` and `umull x0, w20, w8`
//      where `w8 = #0x78` @ `0x00cf6c..0x00cf70`.
// [VN] `V8CpuProfileNodeRecord` (`120 bytes = 0x78`), xác minh tại `0x00c9f0..0x00cd0c`:
//      `mov w11, #0x78; sdiv x20, x8, x11` @ `0x00cc20..0x00cc30` và `umull x0, w20, w8`
//      với `w8 = #0x78` @ `0x00cf6c..0x00cf70`.
struct V8CpuProfileNodeRecord {
    uint32_t node_id{0};                     // +0x00: v8::CpuProfileNode::GetNodeId()
    int32_t script_id{0};                    // +0x04: GetScriptId() (or converted string)
    std::string script_id_str;               // +0x08..0x1f: std::to_string(GetScriptId())
    std::string script_resource_name;        // +0x20..0x37: GetScriptResourceNameStr()
    std::string function_name;               // +0x38..0x4f: GetFunctionNameStr()
    int32_t line_number{0};                  // +0x50: GetLineNumber()
    int32_t column_number{0};                // +0x54: GetColumnNumber()
    uint32_t hit_count{0};                   // +0x58
    uint32_t padding{0};                     // +0x5c
    std::vector<int32_t> children_ids;       // +0x60..0x77 (24 bytes std::vector<int32_t>)
};

static_assert(sizeof(V8CpuProfileNodeRecord) == 120,
              "V8CpuProfileNodeRecord ABI size must be 120 bytes (0x78)");

struct V8CpuProfileResult {
    int64_t start_time_us{0};                // +0x00: v8::CpuProfile::GetStartTime()
    int64_t end_time_us{0};                  // +0x08: v8::CpuProfile::GetEndTime()
    std::vector<int32_t> samples;            // +0x10..0x27: GetSample(i)->GetNodeId()
    std::vector<int64_t> time_deltas;        // +0x28..0x3f: GetSampleTimestamp(i)
    std::vector<V8CpuProfileNodeRecord> nodes;// +0x40..0x57: TopDownRoot DFS nodes (stride 0x78)
};

} // namespace piper
} // namespace lynx
