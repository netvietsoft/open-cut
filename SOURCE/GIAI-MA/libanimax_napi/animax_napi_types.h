/**
 * @file animax_napi_types.h
 * @brief Exact ABI Struct Layouts, Enumerations, and .rodata/.data Constants for libanimax_napi.so
 *        Bố cục Struct ABI chính xác, Kiểu liệt kê và Hằng số .rodata/.data cho libanimax_napi.so
 *
 * Binary Ground Truth (libanimax_napi.so — 84,064 bytes, 25 ELF64 sections, AArch64):
 *   - .rodata:      VA 0x003198, size 0x0002f7 (759 bytes)
 *   - .text:        VA 0x008000, size 0x00444c (17,484 bytes)
 *   - .plt:         VA 0x00c450, size 0x000590 (1,424 bytes, 87 PLT entries)
 *   - .data.rel.ro: VA 0x010000, size 0x0003f8 (1,016 bytes)
 *   - .init_array:  VA 0x010408, size 0x000008 (points to 0x00803c -> napi_module_register_xx)
 *   - .data:        VA 0x014000, size 0x000028 (40 bytes: napi_module_xx descriptor)
 */

#ifndef OPENCUT_ANIMAX_NAPI_TYPES_H_
#define OPENCUT_ANIMAX_NAPI_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

// Forward declarations for opaque N-API handles matching .dynsym mangled names
// Khai báo trước cho các con trỏ N-API khớp với tên mangled trong .dynsym
struct napi_env__;
typedef napi_env__* napi_env;

struct napi_value__;
typedef napi_value__* napi_value;

struct napi_ref__;
typedef napi_ref__* napi_ref;

struct napi_callback_info__;
typedef napi_callback_info__* napi_callback_info;

typedef napi_value (*napi_callback)(napi_env env, napi_callback_info info);
typedef void (*napi_finalize)(napi_env env, void* finalize_data, void* finalize_hint);

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. .rodata STRING & NUMERIC CONSTANTS (0x003198..0x00348f)
// 1. CÁC HẰNG SỐ CHUỖI & SỐ TRONG .rodata (0x003198..0x00348f)
// ============================================================================

/**
 * .rodata 0x003198:
 *   0x003198: 07 00 00 00 00 00 00 00  (uint64_t = 7)
 *   0x0031a0: "updateLayerProperty"
 *   0x0031b4: "UpdateLayerProperty"
 *   0x0031c8: "setResourceProperty"
 *   0x0031dc: "SetResourceProperty"
 *   0x0031f0: "play"
 *   0x0031f5: "frameIndex"
 *   0x003200: "animax"
 *   0x003207: "CompositionElement"
 *   0x00321a: ", napi status"
 *   0x003228: "failed to call napi_define_class"
 *   0x003249: "Received non-object type for %s"
 *   0x003269: "Invalid type for %s, expecting: %s"
 *   0x00328c: "Not enough arguments for %s.%s(), expecting: %s"
 *   0x0032bc: "Constructor"
 *   0x0032c8: "failed to call napi_wrap"
 *   0x0032e1: "Callback Function"
 *   0x0032f3: "ValueParam"
 *   0x0032fe: "boolValue"
 *   0x003308: "stringValue"
 *   0x003314: "doubleValue"
 *   0x003320: "Restricted Double"
 *   0x003332: "argument %d"
 *   0x00333e: "napi_task_runner.cc"
 *   0x003352: "/ws/228/bytebus/repositories/6c0393699fcd03972a83c20caa7f6810/f6f025cc47d595ac17a01dd771d04b0d/animax/src/jsbridge/bindings/animax/animax_module.cc"
 *   0x0033e6: "pointY"
 *   0x0033ed: "pointX"
 *   0x0033f4: "4"
 *   0x0033f6: "1"
 *   0x0033f8: "The OnLoadCallback callback is not callable."
 *   0x003425: "**"
 *   0x003428: "Class constructors cannot be invoked without 'new'"
 *   0x00345b: "Failed to PostTask on Napi JS Thread, Napi Status: "
 */
static constexpr uint64_t kRodataHeaderConst7 = 7ULL;  // @ 0x003198
static constexpr const char* kMethodUpdateLayerProperty    = "updateLayerProperty";     // @ 0x0031a0
static constexpr const char* kNameUpdateLayerProperty      = "UpdateLayerProperty";     // @ 0x0031b4
static constexpr const char* kMethodSetResourceProperty    = "setResourceProperty";     // @ 0x0031c8
static constexpr const char* kNameSetResourceProperty      = "SetResourceProperty";     // @ 0x0031dc
static constexpr const char* kMethodPlay                   = "play";                    // @ 0x0031f0
static constexpr const char* kPropFrameIndex               = "frameIndex";              // @ 0x0031f5
static constexpr const char* kModuleNameAnimax             = "animax";                  // @ 0x003200
static constexpr const char* kClassCompositionElement      = "CompositionElement";      // @ 0x003207
static constexpr const char* kSuffixNapiStatus             = ", napi status";           // @ 0x00321a
static constexpr const char* kErrNapiDefineClass           = "failed to call napi_define_class"; // @ 0x003228
static constexpr const char* kFmtReceivedNonObject         = "Received non-object type for %s";  // @ 0x003249
static constexpr const char* kFmtInvalidType               = "Invalid type for %s, expecting: %s"; // @ 0x003269
static constexpr const char* kFmtNotEnoughArgs             = "Not enough arguments for %s.%s(), expecting: %s"; // @ 0x00328c
static constexpr const char* kMethodConstructor            = "Constructor";             // @ 0x0032bc
static constexpr const char* kErrNapiWrap                  = "failed to call napi_wrap";// @ 0x0032c8
static constexpr const char* kTypeCallbackFunction         = "Callback Function";       // @ 0x0032e1
static constexpr const char* kTypeValueParam               = "ValueParam";              // @ 0x0032f3
static constexpr const char* kPropBoolValue                = "boolValue";               // @ 0x0032fe
static constexpr const char* kPropStringValue              = "stringValue";             // @ 0x003308
static constexpr const char* kPropDoubleValue              = "doubleValue";             // @ 0x003314
static constexpr const char* kTypeRestrictedDouble         = "Restricted Double";       // @ 0x003320
static constexpr const char* kFmtArgumentIdx               = "argument %d";             // @ 0x003332
static constexpr const char* kFileNapiTaskRunnerCc         = "napi_task_runner.cc";     // @ 0x00333e
static constexpr const char* kFileAnimaxModuleCc =
    "/ws/228/bytebus/repositories/6c0393699fcd03972a83c20caa7f6810/"
    "f6f025cc47d595ac17a01dd771d04b0d/animax/src/jsbridge/bindings/animax/animax_module.cc"; // @ 0x003352
static constexpr const char* kPropPointY                   = "pointY";                  // @ 0x0033e6
static constexpr const char* kPropPointX                   = "pointX";                  // @ 0x0033ed
static constexpr const char* kExpectedArgs4                = "4";                       // @ 0x0033f4
static constexpr const char* kExpectedArgs1                = "1";                       // @ 0x0033f6
static constexpr const char* kErrOnLoadCallbackNotCallable = "The OnLoadCallback callback is not callable."; // @ 0x0033f8
static constexpr const char* kKeyPathWildcard              = "**";                      // @ 0x003425
static constexpr const char* kErrConstructorWithoutNew     = "Class constructors cannot be invoked without 'new'"; // @ 0x003428
static constexpr const char* kErrFailedToPostTask          = "Failed to PostTask on Napi JS Thread, Napi Status: "; // @ 0x00345b

// ============================================================================
// 2. .data NAPI MODULE DESCRIPTOR (40 bytes = 0x28 @ 0x014000..0x014027)
// 2. BỘ MÔ TẢ MODULE NAPI TRONG .data (40 bytes = 0x28 @ 0x014000..0x014027)
// ============================================================================

/**
 * @brief Matches `.data` at `0x014000..0x014027` passed to `napi_module_register_xx` (`0x00803c`).
 *        Khớp với `.data` tại `0x014000..0x014027` truyền vào `napi_module_register_xx` (`0x00803c`).
 *
 * Relocations in `.rela.dyn`:
 *   - `OFF=0x014008 ADD=0x3352` (`kFileAnimaxModuleCc`)
 *   - `OFF=0x014010 ADD=0x8048` (`RegisterAnimaXModule`)
 *   - `OFF=0x014018 ADD=0x3200` (`"animax"`)
 */
struct NapiModuleXxDescriptor {
    int32_t nm_version;                                      // +0x00: 1
    uint32_t nm_flags;                                       // +0x04: 0
    const char* nm_filename;                                 // +0x08: 0x003352
    napi_value (*nm_register_func)(napi_env, napi_value);    // +0x10: 0x008048
    const char* nm_modname;                                  // +0x18: 0x003200 ("animax")
    void* nm_priv;                                           // +0x20: nullptr
};
static_assert(sizeof(NapiModuleXxDescriptor) == 0x28, "NapiModuleXxDescriptor must be 40 bytes");

// ============================================================================
// 3. LAYER & RESOURCE PROPERTY TYPES & COLOR BITMASK (0x009c6c..0x009c98)
// 3. KIỂU THUỘC TÍNH LỚP & TÀI NGUYÊN & BITMASK MÀU (0x009c6c..0x009c98)
// ============================================================================

/**
 * @brief LayerPropertyType values verified at `0x009c6c..0x009c98`:
 *        - Color property types:
 *          * `103` (`0x67`: Solid/Layer Color)
 *          * `201` (`0xc9`: Fill Color, bit 0 of `0x00040005`)
 *          * `203` (`0xcb`: Stroke Color, bit 2 of `0x00040005`)
 *          * `219` (`0xdb`: Text/Effect Color, bit 18 of `0x00040005`)
 */
enum class LayerPropertyType : uint16_t {
    kPosition       = 100,
    kScale          = 101,
    kRotation       = 102,
    kColor          = 103,  // 0x67 (`cmp w8, #0x67` @ 0x009c94)
    kOpacity        = 104,
    kFillColor      = 201,  // 0xc9 (`sub w9, w8, #0xc9` @ 0x009c70, bit 0)
    kFillOpacity    = 202,
    kStrokeColor    = 203,  // 0xcb (bit 2 of 0x00040005)
    kStrokeWidth    = 204,
    kTextColor      = 219,  // 0xdb (bit 18 of 0x00040005)
};

enum class ResourcePropertyType : uint16_t {
    kImageSource    = 1,
    kTextContent    = 2,
    kExternalAsset  = 3,
};

enum class AnimaXLogLevel : int32_t {
    kVerbose = 0,
    kDebug   = 1,
    kInfo    = 2,
    kWarn    = 3,
    kError   = 4,  // `mov w3, #4` @ 0x00af20
};

/**
 * @brief Exact bitmask predicate from `0x009c6c..0x009c98` determining whether
 *        a `LayerPropertyType` represents an ARGB color value.
 *        Hàm vị từ bitmask chính xác từ `0x009c6c..0x009c98` xác định xem
 *        `LayerPropertyType` có phải là giá trị màu ARGB hay không.
 */
inline constexpr bool IsLayerColorPropertyType(uint16_t prop_type) noexcept {
    const uint32_t offset = static_cast<uint32_t>(prop_type) - 0xC9u;  // prop_type - 201
    if (offset <= 0x12u) {                                             // <= 18 (201..219)
        if (((1u << offset) & 0x00040005u) != 0u) {
            return true;
        }
    }
    return prop_type == 0x67u;  // 103
}

// ============================================================================
// 4. JS VALUE PARAM DICTIONARY ABI (64 bytes = 0x40 @ 0x00a650..0x00a964)
// 4. BỐ CỤC ABI TỪ ĐIỂN THAM SỐ GIÁ TRỊ JS (64 bytes = 0x40 @ 0x00a650..0x00a964)
// ============================================================================

/**
 * @brief 64-byte (`0x40`) dictionary unpacked from JS `ValueParam` object in
 *        `ParseValueParamDictionary` (`0x00a650..0x00a964`) and consumed by
 *        `ConvertToAnimaXValueParam` (`0x008430..0x008548`).
 *        Từ điển 64-byte (`0x40`) giải nén từ đối tượng JS `ValueParam` trong
 *        `ParseValueParamDictionary` (`0x00a650..0x00a964`) và được tiêu thụ bởi
 *        `ConvertToAnimaXValueParam` (`0x008430..0x008548`).
 *
 * Exact Offsets Verified in Disassembly:
 *   +0x00: uint8_t     has_bool_value    (`strb w9, [x20]` @ 0x00a728, `ldrb w8, [x20]` @ 0x008490)
 *   +0x01: uint8_t     has_double_value  (`strb w8, [x20, #1]` @ 0x00a768, `ldrb w8, [x20, #1]` @ 0x0084e8)
 *   +0x02: uint8_t     has_frame_index   (`mov w8, #0x10000; str w8, [x0]` @ 0x00a698..0x00a6a8, `strb w8, [x20, #2]` @ 0x00a7b8)
 *   +0x03: uint8_t     has_point_x       (`strb w8, [x20, #3]` @ 0x00a7f8, `ldrb w8, [x20, #3]` @ 0x0084b8)
 *   +0x04: uint8_t     has_point_y       (`strb w8, [x20, #4]` @ 0x00a838, `ldrb w8, [x20, #4]` @ 0x0084c0)
 *   +0x05: uint8_t     has_string_value  (`strb w8, [x20, #5]` @ 0x00a95c, `ldrb w8, [x1, #5]` @ 0x008458)
 *   +0x06: uint8_t     bool_value        (`strb w8, [x20, #6]` @ 0x00a724, `ldrb w21, [x20, #6]` @ 0x008498)
 *   +0x07: uint8_t     pad_07
 *   +0x08: double      double_value      (`str d0, [x20, #8]` @ 0x00a764, `ldr d8, [x20, #8]` @ 0x0084f0)
 *   +0x10: int32_t     frame_index       (`mov w9, #-1; str w9, [x0, #0x10]` @ 0x00a69c..0x00a6ac, `ldr w20, [x20, #0x10]` @ 0x00c0d8)
 *   +0x14: int32_t     pad_14
 *   +0x18: double      point_x           (`str d0, [x20, #0x18]` @ 0x00a7f4, `ldp d8, d9, [x20, #0x18]` @ 0x0084c8)
 *   +0x20: double      point_y           (`str d0, [x20, #0x20]` @ 0x00a834)
 *   +0x28: std::string string_value      (24 bytes `+0x28..+0x3f`, `add x1, x20, #0x28` @ 0x008460)
 */
struct JSValueParamDict {
    uint8_t has_bool_value{0};      // +0x00
    uint8_t has_double_value{0};    // +0x01
    uint8_t has_frame_index{1};     // +0x02 (initialized via 0x00010000 word store at +0x00)
    uint8_t has_point_x{0};         // +0x03
    uint8_t has_point_y{0};         // +0x04
    uint8_t has_string_value{0};    // +0x05
    uint8_t bool_value{0};          // +0x06
    uint8_t pad_07{0};              // +0x07
    double double_value{0.0};       // +0x08
    int32_t frame_index{-1};        // +0x10
    int32_t pad_14{0};              // +0x14
    double point_x{0.0};            // +0x18
    double point_y{0.0};            // +0x20
    std::string string_value{};     // +0x28..+0x3f (24 bytes on Android NDK libc++)
};

// ============================================================================
// 5. ANIMAX VALUE PARAM & REQUEST OBJECTS (144 bytes = 0x90 @ 0x00c0dc)
// 5. ĐỐI TƯỢNG THAM SỐ GIÁ TRỊ & YÊU CẦU ANIMAX (144 bytes = 0x90 @ 0x00c0dc)
// ============================================================================

/**
 * @brief Represents `lynx::animax::AnimaXValueParam` (`144 bytes = 0x90` allocated
 *        at `0x008510`, `0x009ce0`, `0x00c0dc`: `mov w0, #0x90; bl _Znwm`).
 *        Đại diện cho `lynx::animax::AnimaXValueParam` (`144 bytes = 0x90` cấp phát
 *        tại `0x008510`, `0x009ce0`, `0x00c0dc`: `mov w0, #0x90; bl _Znwm`).
 */
struct AnimaXValueParam {
    enum class Kind : uint32_t {
        kEmpty  = 0,
        kBool   = 1,
        kInt    = 2,
        kDouble = 3,
        kPoint  = 4,
        kString = 5,
    };

    Kind kind{Kind::kEmpty};
    int32_t frame_index{-1};
    bool bool_val{false};
    int32_t int_val{0};
    double double_val_0{0.0};
    double double_val_1{0.0};
    std::string string_val{};
    uint8_t reserved_abi_padding[80]{};

    AnimaXValueParam() noexcept = default;
    AnimaXValueParam(const std::string& str, int32_t frame)
        : kind(Kind::kString), frame_index(frame), string_val(str) {}
    AnimaXValueParam(bool b, int32_t frame) noexcept
        : kind(Kind::kBool), frame_index(frame), bool_val(b) {}
    AnimaXValueParam(double x, double y, int32_t frame) noexcept
        : kind(Kind::kPoint), frame_index(frame), double_val_0(x), double_val_1(y) {}
    AnimaXValueParam(double d, int32_t frame) noexcept
        : kind(Kind::kDouble), frame_index(frame), double_val_0(d) {}
    AnimaXValueParam(int32_t color_int, int32_t frame) noexcept
        : kind(Kind::kInt), frame_index(frame), int_val(color_int) {}
};

/**
 * @brief Represents `lynx::animax::PropertyUpdateResponse` passed to update callbacks
 *        (`IsSuccess()` @ `0x008d94`, `GetErrorType()` @ `0x008da0`).
 *        Đại diện cho `lynx::animax::PropertyUpdateResponse` truyền vào callback cập nhật
 *        (`IsSuccess()` @ `0x008d94`, `GetErrorType()` @ `0x008da0`).
 */
class PropertyUpdateResponse {
public:
    PropertyUpdateResponse(bool success = true, int32_t error_type = 0) noexcept
        : is_success_(success), error_type_(error_type) {}

    bool IsSuccess() const noexcept { return is_success_; }
    int32_t GetErrorType() const noexcept { return error_type_; }

private:
    bool is_success_;
    int32_t error_type_;
};

// ============================================================================
// 6. COMPOSITION ELEMENT & PLAYER HOLDER ABI (80 B = 0x50 @ 0x00a370, 48 B = 0x30 @ 0x00a46c)
// 6. BỐ CỤC ABI COMPOSITION ELEMENT & PLAYER HOLDER (80 B = 0x50 @ 0x00a370, 48 B = 0x30 @ 0x00a46c)
// ============================================================================

class AnimaXPlayerMock;

/**
 * @brief 48-byte (`0x30`) external memory holder allocated at `0x00a46c` (`mov w0, #0x30; bl _Znwm`)
 *        with vtable at `.data.rel.ro 0x010018` (`0x008378` / `0x00bf9c`).
 *        Tracks external memory adjustment (`0x20 = 32 bytes` @ `0x00a4e8`, `0x00bff0`).
 *        Trình giữ bộ nhớ ngoài 48-byte (`0x30`) cấp phát tại `0x00a46c` (`mov w0, #0x30; bl _Znwm`)
 *        với vtable tại `.data.rel.ro 0x010018` (`0x008378` / `0x00bf9c`).
 */
struct AnimaXPlayerExternalHolder {
    void* vptr{nullptr};                          // +0x00 -> 0x010018 / 0x0103d0
    void* owner_composition_element{nullptr};     // +0x08 -> CompositionElement* (+0x18 subobject)
    size_t current_external_bytes{0};             // +0x10 -> 0x20 (32 bytes)
    size_t reported_external_bytes{0};            // +0x18 -> 0x20 (32 bytes)
    std::weak_ptr<AnimaXPlayerMock> weak_player;  // +0x20..+0x2f (16 bytes: ptr + control_block*)
};

/**
 * @brief 80-byte (`0x50`) `CompositionElement` C++ object allocated in `ConstructorCallback`
 *        (`0x00a370: mov w0, #0x50; bl _Znwm`).
 *        Đối tượng C++ `CompositionElement` 80-byte (`0x50`) cấp phát trong `ConstructorCallback`
 *        (`0x00a370: mov w0, #0x50; bl _Znwm`).
 *
 * Exact Layout Verified at `0x00a370..0x00a5d0`:
 *   +0x00: void*                       vptr_primary        (0x010278 -> 0x0100c0 -> 0x010168)
 *   +0x08: void*                       script_wrappable_p1
 *   +0x10: void*                       script_wrappable_p2
 *   +0x18: void*                       vptr_secondary      (0x0102c8 -> 0x010110 -> 0x0101b8)
 *   +0x20: napi_env                    env_                (stored at +0x20 @ 0x00a3e8)
 *   +0x28: napi_ref                    wrapper_ref_        (created via CreateReference @ 0x00a3ec..0x00a40c)
 *   +0x30: napi_env                    ctor_env_           (stored at +0x30 @ 0x00a3a4)
 *   +0x38: AnimaXPlayerExternalHolder* player_holder_      (48-byte holder stored at +0x38 @ 0x00a4b0)
 *   +0x40: napi_env                    wrap_env_           (stored at +0x40 @ 0x00a5c8)
 *   +0x48: napi_ref                    wrap_ref_           (stored at +0x48 @ 0x00a5c8)
 */
struct CompositionElementObject {
    void* vptr_primary{nullptr};                  // +0x00
    void* script_wrappable_p1{nullptr};           // +0x08
    void* script_wrappable_p2{nullptr};           // +0x10
    void* vptr_secondary{nullptr};                // +0x18
    napi_env env{nullptr};                        // +0x20
    napi_ref wrapper_ref{nullptr};                // +0x28
    napi_env ctor_env{nullptr};                   // +0x30
    AnimaXPlayerExternalHolder* player_holder{nullptr}; // +0x38
    napi_env wrap_env{nullptr};                   // +0x40
    napi_ref wrap_ref{nullptr};                   // +0x48
};
static_assert(sizeof(CompositionElementObject) == 0x50, "CompositionElementObject must be 80 bytes");

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx

#endif  // OPENCUT_ANIMAX_NAPI_TYPES_H_
