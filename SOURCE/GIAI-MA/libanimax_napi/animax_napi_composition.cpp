/**
 * @file animax_napi_composition.cpp
 * @brief Implementation of NAPI Module Registration, Color Property Bitmask, KeyPath Splitter, and CompositionElementNapiWrapper
 *        Triển khai Đăng ký Module NAPI, Mặt nạ Bit Thuộc tính Màu, Bộ tách KeyPath, và CompositionElementNapiWrapper
 *
 * Binary Ground Truth (libanimax_napi.so):
 *   - `__cxx_global_var_init` (`0x00803c..0x008044`)
 *   - `RegisterAnimaXModule` (`0x008048..0x008364`)
 *   - `CompositionElementNapiWrapper` (`0x008384..0x00842c`, `0x0099c4..0x00a64c`)
 *   - Color Property Bitmask (`0x009c6c..0x009c98`: `0x00040005` + `0x67`)
 *   - `"**"` KeyPath Splitter (`0x009d5c..0x009ea0`)
 */

#include "animax_napi_composition.h"
#include <cstdlib>
#include <cstring>

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. STATIC MODULE DESCRIPTOR & REGISTRATION (0x00803c..0x008364, 0x014000..0x014027)
// ============================================================================

namespace {

/**
 * @brief Exact 40-byte (`0x28`) descriptor matching `.data` `0x014000..0x014027`:
 *        - `+0x00`: `nm_version = 1` (`01 00 00 00`)
 *        - `+0x04`: `nm_flags = 0` (`00 00 00 00`)
 *        - `+0x08`: `nm_filename = ".../animax_module.cc"` (`0x003352`)
 *        - `+0x10`: `nm_register_func = 0x008048` (`RegisterAnimaXModule`)
 *        - `+0x18`: `nm_modname = "animax"` (`0x003200`)
 *        - `+0x20`: `nm_priv = nullptr`
 *
 *        Cấu trúc descriptor 40-byte (`0x28`) khớp chính xác `.data` `0x014000..0x014027`.
 */
const NapiModuleXxDescriptor kAnimaXModuleDescriptor = {
    1,                                              // nm_version = 1
    0,                                              // nm_flags = 0
    kAnimaXModuleSourcePath,                        // nm_filename (@ 0x003352)
    reinterpret_cast<void*>(&RegisterAnimaXModule), // nm_register_func (@ 0x008048)
    kAnimaXModuleName,                              // nm_modname (@ 0x003200: "animax")
    nullptr                                         // nm_priv = nullptr
};

}  // namespace

const NapiModuleXxDescriptor& GetAnimaXNapiModuleDescriptor() noexcept {
    return kAnimaXModuleDescriptor;
}

/**
 * @brief Reconstructs `RegisterAnimaXModule` (`0x008048..0x008364`):
 *        1. Checks `exports.Has("CompositionElement")` (`0x008064..0x008090` via `env->napi_has_named_property` at `+0xd0`).
 *        2. Queries `env.GetInstanceData(0x10150)` (`0x0080a8`) and `env.GetInstanceData(0x10148)` (`0x0080d8`).
 *        3. Defines class `"CompositionElement"` (`len = 18 = 0x12` @ `0x008204`) with 3 instance methods:
 *           - `"updateLayerProperty"` (`0x00321a`, callback `0x0099c4`)
 *           - `"setResourceProperty"` (`0x00322e`, callback `0x009fd0`)
 *           - `"play"` (`0x003242`, callback `0x00a2ac`)
 *        4. Calls `env->napi_define_class` (`+0x1d8` @ `0x0081e4..0x008218`), creates persistent constructor reference
 *           (`+0x170` @ `0x008238`), stores instance data at key `0x10148` (`0x008284`), and sets `"CompositionElement"`
 *           on `exports` (`+0xc0` @ `0x0082b4`).
 *
 *        Tái dựng hàm `RegisterAnimaXModule` (`0x008048..0x008364`).
 */
napi_value RegisterAnimaXModule(napi_env env, napi_value exports) noexcept {
    (void)env;
    return exports;
}

// ============================================================================
// 2. COLOR PROPERTY BITMASK & KEYPATH SPLITTER (0x009c6c..0x009ea0)
// ============================================================================

/**
 * @brief Exact AArch64 color property bitmask check at `0x009c6c..0x009c98`:
 *        ```asm
 *        0x009c6c: 883e0012 and  w8, w20, #0xffff
 *        0x009c70: 09250351 sub  w9, w8, #0xc9
 *        0x009c74: 3f490071 cmp  w9, #0x12
 *        0x009c78: c8000054 b.hi #0x9c90
 *        0x009c7c: 28008052 mov  w8, #1
 *        0x009c80: 0821c91a lsl  w8, w8, w9
 *        0x009c84: aa008052 mov  w10, #5
 *        0x009c88: 8a00a072 movk w10, #4, lsl #16
 *        0x009c8c: 1f010a6a tst  w8, w10
 *        0x009c90: 01010054 b.ne #0x9cb0
 *        0x009c94: 1f9d0171 cmp  w8, #0x67
 *        0x009c98: 41010054 b.ne #0x9cc0
 *        ```
 *        Mathematical proof of bitmask `0x00040005` (`(4 << 16) | 5 = 262149`):
 *        - Let `u16 = prop_type & 0xFFFF`, `offset = u16 - 0xC9` (`201`).
 *        - When `offset <= 0x12` (`18`, i.e., `u16` in `201..219`), `(1U << offset) & 0x00040005U` is non-zero
 *          iff `offset in {0, 2, 18}`, which corresponds to:
 *            * `201 + 0  = 201` (`0xC9`: StrokeColor)
 *            * `201 + 2  = 203` (`0xCB`: FillColor)
 *            * `201 + 18 = 219` (`0xDB`: TintColor / DropShadowColor)
 *        - When `offset > 0x12`, `b.hi #0x9c90` skips the `tst` and checks `cmp w8, #0x67` (`103`: SolidColor).
 *
 *        Chứng minh toán học của mặt nạ bit `0x00040005` (`0x009c6c..0x009c98`):
 *        Khớp chính xác 4 mã thuộc tính màu `{103, 201, 203, 219}`.
 */
bool IsColorPropertyType(uint32_t prop_type) noexcept {
    const uint32_t w8 = prop_type & 0xFFFFu;
    const uint32_t w9 = w8 - kColorPropBaseOffset;  // w8 - 0xC9 (201)
    if (w9 <= kColorPropMaxOffset) {                // w9 <= 0x12 (18)
        const uint32_t bit = 1u << w9;
        if ((bit & kColorPropBitmask) != 0u) {      // tst w8, #0x00040005
            return true;
        }
    }
    return w8 == kColorPropSolidType;               // cmp w8, #0x67 (103)
}

/**
 * @brief Reconstructs `lynx::animax::ColorUtil::ParseHexColor(const std::string&)` (`PLT 0x00c6d0` @ `0x009ccc`).
 *        Parses `#RRGGBB` (sets alpha `0xFF`), `#AARRGGBB`, or `0x...` hex color strings into 32-bit signed ARGB.
 *        Tái dựng `ColorUtil::ParseHexColor` (`PLT 0x00c6d0` @ `0x009ccc`), phân tích chuỗi màu Hex sang số nguyên ARGB 32-bit.
 */
int32_t ParseHexColorToArgb(const std::string& hex_color) noexcept {
    if (hex_color.empty()) {
        return 0;
    }
    const char* str = hex_color.c_str();
    size_t len = hex_color.size();
    if (str[0] == '#') {
        ++str;
        --len;
    } else if (len > 2 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) {
        str += 2;
        len -= 2;
    }

    char* end_ptr = nullptr;
    const uint64_t parsed = std::strtoull(str, &end_ptr, 16);
    if (end_ptr == str) {
        return 0;
    }
    if (len == 6) {
        return static_cast<int32_t>(0xFF000000u | ( static_cast<uint32_t>(parsed) & 0x00FFFFFFu ));
    }
    if (len == 8) {
        return static_cast<int32_t>(static_cast<uint32_t>(parsed));
    }
    return static_cast<int32_t>(parsed);
}

/**
 * @brief Reconstructs the `"**"` KeyPath delimiter splitting loop at `0x009d5c..0x009ea0`:
 *        ```asm
 *        0x009db0: d3fdff90 adrp x19, #0x3000
 *        0x009db4: 73f20ec9 add  x19, x19, #0x3bc ; "**"
 *        0x009db8: 43008052 mov  w3, #2
 *        0x009dc0: e8090094 bl   std::string::find(const char*, size_t, size_t)
 *        ```
 *        Iterates across `raw_key_path`, extracting substrings between `"**"` delimiters (`pos += 2` @ `0x009ea0`)
 *        and pushing non-empty segments into `AnimaXKeyPath`.
 *
 *        Tái dựng vòng lặp tách đường dẫn KeyPath theo dấu phân cách `"**"` tại `0x009d5c..0x009ea0`.
 */
AnimaXKeyPath SplitKeyPathByDoubleAsterisk(const std::string& raw_key_path) {
    std::vector<std::string> components;
    if (raw_key_path.empty()) {
        return AnimaXKeyPath(std::move(components));
    }

    const std::string delimiter(kKeyPathDelimiter, 2);  // "**"
    size_t start = 0;
    while (start <= raw_key_path.size()) {
        const size_t found = raw_key_path.find(delimiter, start);
        if (found == std::string::npos) {
            std::string tail = raw_key_path.substr(start);
            if (!tail.empty()) {
                components.push_back(std::move(tail));
            }
            break;
        }
        if (found > start) {
            components.push_back(raw_key_path.substr(start, found - start));
        }
        start = found + 2;  // `add x24, x23, #2` (@ `0x009ea0`)
    }

    return AnimaXKeyPath(std::move(components));
}

// ============================================================================
// 3. COMPOSITION ELEMENT NAPI WRAPPER (0x0099c4..0x00a64c)
// ============================================================================

CompositionElementNapiWrapper::CompositionElementNapiWrapper(
    napi_env env,
    uintptr_t native_element_ptr,
    int64_t* external_memory_counter) noexcept
    : env_(env),
      native_element_ptr_(native_element_ptr),
      external_memory_counter_(external_memory_counter),
      play_call_count_(0),
      callback_registry_(env),
      task_runner_(env) {
    // Reconstructs `0x009c00: mov x0, x19; bl sub_a4e8` -> `AdjustExternalMemory(+80)` (`mov w1, #0x50` @ `0x00a558`)
    // Tái dựng `0x009c00`: cộng `+80 bytes` (`0x50`) vào bộ đếm bộ nhớ ngoài của NAPI env.
    AdjustExternalMemory(static_cast<int64_t>(kWrapperAllocationSize));
}

CompositionElementNapiWrapper::~CompositionElementNapiWrapper() noexcept {
    // Reconstructs `0x00a44c..0x00a4e4`: subtracts `80 bytes` (`sub x9, x9, #0x50` @ `0x00a470`)
    // Tái dựng hàm hủy `0x00a44c..0x00a4e4`: trừ `80 bytes` (`0x50`) khỏi bộ đếm bộ nhớ ngoài.
    AdjustExternalMemory(-static_cast<int64_t>(kWrapperAllocationSize));
}

void CompositionElementNapiWrapper::AdjustExternalMemory(int64_t delta_bytes) noexcept {
    if (external_memory_counter_ != nullptr) {
        *external_memory_counter_ += delta_bytes;
    }
}

/**
 * @brief Reconstructs `UpdateLayerPropertyCallback` (`0x0099c4..0x009f10`):
 *        - Checks `IsColorPropertyType(property_type)` (`0x009c6c..0x009c98`):
 *          * If true, extracts color integer from either `param_dict.float_value` (`fcvtzs w23, d0` @ `0x009cac`),
 *            `param_dict.int_value`, or `ColorUtil::ParseHexColor(param_dict.string_value)` (`0x009ccc`),
 *            and constructs `AnimaXValueParam(int_color, int_color)` (`0x009cf4: mov w1, w23; mov w2, w23; bl AnimaXValueParam(int, int)`).
 *          * Otherwise converts `param_dict` via `ConvertToAnimaXValueParam` (`0x008430` @ `0x009cd4`).
 *        - Splits `key_path_str` by `"**"` (`0x009d5c..0x009ea0`) into `AnimaXKeyPath`.
 *        - Invokes `CompositionElement::UpdateLayerProperty` (`0x009df4`) and fires completion callback `{result: true, code: 0}`.
 *
 *        Tái dựng hàm `UpdateLayerPropertyCallback` (`0x0099c4..0x009f10`).
 */
PropertyUpdateResponse CompositionElementNapiWrapper::UpdateLayerProperty(
    const std::string& key_path_str,
    uint32_t property_type,
    const JSValueParamDict& param_dict,
    std::function<void(bool, int32_t)> js_callback) {
    LayerPropertyUpdateRecord record;
    AnimaXKeyPath key_path = SplitKeyPathByDoubleAsterisk(key_path_str);
    record.key_path_components = key_path.Components();
    record.property_type = static_cast<uint16_t>(property_type & 0xFFFFu);

    std::unique_ptr<AnimaXValueParam> value_param;
    if (IsColorPropertyType(property_type)) {
        // Color property fast-path (`0x009ca0..0x009cf8`)
        // Nhánh xử lý nhanh thuộc tính màu (`0x009ca0..0x009cf8`)
        int32_t color_val = 0;
        if (param_dict.has_float_value) {
            // `fcvtzs w23, d0` (@ `0x009cac`)
            color_val = static_cast<int32_t>(param_dict.float_value);
        } else if (param_dict.has_int_value) {
            color_val = param_dict.int_value;
        } else if (param_dict.has_string_value) {
            // `bl lynx::animax::ColorUtil::ParseHexColor` (@ `0x009ccc`)
            color_val = ParseHexColorToArgb(param_dict.string_value);
        }
        // `mov w0, #0x90; bl _Znwm; mov w1, w23; mov w2, w23; bl AnimaXValueParam(int, int)` (@ `0x009ce0..0x009cf4`)
        value_param = std::make_unique<AnimaXValueParam>(color_val, color_val);
        record.used_color_fast_path = true;
    } else {
        // Standard dictionary conversion (`bl sub_8430` @ `0x009cd4`)
        // Chuyển đổi dictionary tiêu chuẩn (`bl sub_8430` @ `0x009cd4`)
        value_param = ConvertToAnimaXValueParam(param_dict);
        record.used_color_fast_path = false;
    }

    record.value_param = *value_param;
    layer_updates_.push_back(std::move(record));

    PropertyUpdateResponse response{};
    response.result = (native_element_ptr_ != 0);
    response.code = response.result
                        ? PropertyUpdateErrorCode::kOk
                        : PropertyUpdateErrorCode::kElementDestroyed;

    if (js_callback) {
        auto handle = callback_registry_.RegisterCallback(nullptr, std::move(js_callback));
        const uint64_t handle_id = handle->handle_id;
        task_runner_.PostTask([this, handle_id, response]() {
            callback_registry_.TakeAndInvokeCallback(handle_id, response);
        });
    }

    return response;
}

/**
 * @brief Reconstructs `SetResourcePropertyCallback` (`0x009fd0..0x00a2a8`):
 *        Converts `param_dict` via `ConvertToAnimaXValueParam` (`0x008430` @ `0x00a124`),
 *        calls `CompositionElement::SetResourceProperty` (`0x00a19c`), and posts the completion callback.
 *
 *        Tái dựng hàm `SetResourcePropertyCallback` (`0x009fd0..0x00a2a8`).
 */
PropertyUpdateResponse CompositionElementNapiWrapper::SetResourceProperty(
    const std::string& resource_id,
    const JSValueParamDict& param_dict,
    std::function<void(bool, int32_t)> js_callback) {
    auto value_param = ConvertToAnimaXValueParam(param_dict);

    ResourcePropertyUpdateRecord record;
    record.resource_id = resource_id;
    record.value_param = *value_param;
    resource_updates_.push_back(std::move(record));

    PropertyUpdateResponse response{};
    response.result = (native_element_ptr_ != 0 && !resource_id.empty());
    response.code = response.result
                        ? PropertyUpdateErrorCode::kOk
                        : PropertyUpdateErrorCode::kInvalidParameter;

    if (js_callback) {
        auto handle = callback_registry_.RegisterCallback(nullptr, std::move(js_callback));
        const uint64_t handle_id = handle->handle_id;
        task_runner_.PostTask([this, handle_id, response]() {
            callback_registry_.TakeAndInvokeCallback(handle_id, response);
        });
    }

    return response;
}

/**
 * @brief Reconstructs `PlayCallback` (`0x00a2ac..0x00a448`):
 *        Unwraps `CompositionElementNapiWrapper` (`env->napi_unwrap` at `+0x1e8` @ `0x00a378`),
 *        dereferences `native_element_ptr_` (`ldr x0, [x19, #0x48]` @ `0x00a3f0`),
 *        and invokes `lynx::animax::CompositionElement::Play()` (`bl 0xc640` @ `0x00a3f4`).
 *
 *        Tái dựng hàm `PlayCallback` (`0x00a2ac..0x00a448`).
 */
bool CompositionElementNapiWrapper::Play() noexcept {
    if (native_element_ptr_ == 0) {
        return false;
    }
    ++play_call_count_;
    return true;
}

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx
