/**
 * @file animax_napi_composition.h
 * @brief NAPI Module Registration, CompositionElement Class Wrapper, KeyPath Splitter, and Color Property Bitmask
 *        Đăng ký Module NAPI, Lớp bao CompositionElement, Bộ tách KeyPath, và Mặt nạ Bit Thuộc tính Màu
 *
 * Binary Ground Truth (libanimax_napi.so):
 *   - `__cxx_global_var_init` (`0x00803c..0x008044`): registers `.data` `0x014000` (`NapiModuleXxDescriptor`)
 *   - `RegisterAnimaXModule` (`0x008048..0x008364`): defines JS class `"CompositionElement"` (`0x003207`)
 *   - `CompositionElementWrapper` (`80 bytes = 0x50` @ `0x009b90`, destructor at `0x00a44c..0x00a4e4`)
 *   - `UpdateLayerPropertyCallback` (`0x0099c4..0x009f10`): color bitmask `0x00040005` / `0x67` (`0x009c6c..0x009c98`)
 *     + `"**"` KeyPath splitting (`0x009d5c..0x009ea0`)
 *   - `SetResourcePropertyCallback` (`0x009fd0..0x00a2a8`)
 *   - `PlayCallback` (`0x00a2ac..0x00a448`)
 *   - `AdjustExternalMemory` (`0x00a4e8..0x00a64c`: `±80 bytes` = `+0x50` / `-0x50`)
 */

#ifndef OPENCUT_ANIMAX_NAPI_COMPOSITION_H_
#define OPENCUT_ANIMAX_NAPI_COMPOSITION_H_

#include "animax_napi_types.h"
#include "animax_napi_hash_stl.h"
#include "animax_napi_task_value.h"
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. STATIC MODULE DESCRIPTOR & REGISTRATION (0x00803c..0x008364, 0x014000..0x014027)
// ============================================================================

/**
 * @brief Returns the exact 40-byte (`0x28`) `NapiModuleXxDescriptor` located at `.data` `0x014000..0x014027`.
 *        Trả về cấu trúc `NapiModuleXxDescriptor` 40-byte (`0x28`) chính xác tại `.data` `0x014000..0x014027`.
 */
const NapiModuleXxDescriptor& GetAnimaXNapiModuleDescriptor() noexcept;

/**
 * @brief Reconstructs `RegisterAnimaXModule(Napi::Env, Napi::Object)` (`0x008048..0x008364`).
 *        Tái dựng hàm `RegisterAnimaXModule(Napi::Env, Napi::Object)` (`0x008048..0x008364`).
 */
napi_value RegisterAnimaXModule(napi_env env, napi_value exports) noexcept;

// ============================================================================
// 2. COLOR PROPERTY BITMASK & KEYPATH SPLITTER (0x009c6c..0x009ea0)
// ============================================================================

/**
 * @brief Reconstructs the exact AArch64 color property bitmask check at `0x009c6c..0x009c98`:
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
 *        Returns `true` iff `(prop_type & 0xFFFF)` is `103` (`0x67`), `201` (`0xc9`), `203` (`0xcb`), or `219` (`0xdb`).
 *
 *        Tái dựng phép kiểm tra mặt nạ bit thuộc tính màu AArch64 tại `0x009c6c..0x009c98`:
 *        Trả về `true` khi và chỉ khi `(prop_type & 0xFFFF)` thuộc `{103, 201, 203, 219}`.
 */
bool IsColorPropertyType(uint32_t prop_type) noexcept;

/**
 * @brief Reconstructs `lynx::animax::ColorUtil::ParseHexColor(const std::string&)` (`PLT 0x00c6d0` called at `0x009ccc`),
 *        supporting `#RRGGBB`, `#AARRGGBB`, `0xRRGGBB`, `0xAARRGGBB`, and `rgba(r,g,b,a)` formats into ARGB32 `int32_t`.
 *        Tái dựng hàm `ColorUtil::ParseHexColor` (`PLT 0x00c6d0` gọi tại `0x009ccc`), chuyển chuỗi màu Hex sang ARGB32 `int32_t`.
 */
int32_t ParseHexColorToArgb(const std::string& hex_color) noexcept;

/**
 * @brief Reconstructs the `"**"` KeyPath delimiter splitting loop at `0x009d5c..0x009ea0`:
 *        Repeatedly searches for `"**"` (`.rodata` `0x0033bc`, length `2`) via `std::string::find("**", pos, 2)`
 *        (`0x009dc0`) and pushes each non-empty segment into `AnimaXKeyPath::components_`.
 *
 *        Tái dựng vòng lặp tách đường dẫn KeyPath theo dấu phân cách `"**"` tại `0x009d5c..0x009ea0`.
 */
AnimaXKeyPath SplitKeyPathByDoubleAsterisk(const std::string& raw_key_path);

// ============================================================================
// 3. COMPOSITION ELEMENT NAPI WRAPPER (0x008384..0x00842c, 0x0099c4..0x00a64c)
// ============================================================================

/**
 * @brief Recorded invocation of `UpdateLayerProperty` on the underlying `lynx::animax::CompositionElement`.
 *        Bản ghi lệnh gọi `UpdateLayerProperty` trên đối tượng gốc `lynx::animax::CompositionElement`.
 */
struct LayerPropertyUpdateRecord {
    std::vector<std::string> key_path_components;
    uint16_t property_type{0};
    AnimaXValueParam value_param{};
    bool used_color_fast_path{false};
};

/**
 * @brief Recorded invocation of `SetResourceProperty` (`0x009fd0..0x00a2a8`).
 *        Bản ghi lệnh gọi `SetResourceProperty` (`0x009fd0..0x00a2a8`).
 */
struct ResourcePropertyUpdateRecord {
    std::string resource_id;
    AnimaXValueParam value_param{};
};

/**
 * @brief Reconstructs the 80-byte (`0x50`) `CompositionElement` NAPI ObjectWrap class
 *        allocated at `0x009b90` (`mov w0, #0x50; bl _Znwm`), with vtable at `.data.rel.ro` `0x010160`
 *        and external memory adjustment `±80 bytes` (`0x00a558` / `0x00a470`).
 *
 *        Tái dựng lớp bao NAPI ObjectWrap `CompositionElement` 80-byte (`0x50`)
 *        cấp phát tại `0x009b90`, với vtable tại `.data.rel.ro` `0x010160` và điều chỉnh bộ nhớ ngoài `±80 bytes`.
 */
class CompositionElementNapiWrapper {
public:
    static constexpr size_t kWrapperAllocationSize = 0x50u;  // 80 bytes (@ 0x009b90 / 0x00a558)
    static constexpr uintptr_t kConstructorRefKey = 0x10148u;
    static constexpr uintptr_t kWrapperCheckKey   = 0x10150u;
    static constexpr uintptr_t kExtMemTrackerKey  = 0x101e8u;

    CompositionElementNapiWrapper(napi_env env,
                                  uintptr_t native_element_ptr,
                                  int64_t* external_memory_counter = nullptr) noexcept;
    virtual ~CompositionElementNapiWrapper() noexcept;

    /**
     * @brief Reconstructs `UpdateLayerProperty` (`0x0099c4..0x009f10`):
     *        1. Splits `key_path_str` by `"**"` into `AnimaXKeyPath` (`0x009d5c..0x009ea0`).
     *        2. Evaluates `IsColorPropertyType(property_type)` (`0x009c6c..0x009c98`):
     *           - If color property (`103, 201, 203, 219`), constructs `AnimaXValueParam(int, int)` (`0x009cf4`)
     *             from either `int_value` / `float_value` (`fcvtzs w23, d0` @ `0x009cac`) or `ParseHexColor(string_value)` (`0x009ccc`).
     *           - Otherwise calls `ConvertToAnimaXValueParam(dict)` (`0x008430`).
     *        3. Dispatches `CompositionElement::UpdateLayerProperty` (`PLT 0x00c620` @ `0x009df4`)
     *           and invokes the optional completion callback via `NapiCallbackRegistry` / `NapiTaskRunner`.
     *
     *        Tái dựng phương thức `UpdateLayerProperty` (`0x0099c4..0x009f10`).
     */
    PropertyUpdateResponse UpdateLayerProperty(
        const std::string& key_path_str,
        uint32_t property_type,
        const JSValueParamDict& param_dict,
        std::function<void(bool, int32_t)> js_callback = nullptr);

    /**
     * @brief Reconstructs `SetResourceProperty` (`0x009fd0..0x00a2a8`):
     *        Converts `JSValueParamDict` via `ConvertToAnimaXValueParam` (`0x008430`) and invokes
     *        `CompositionElement::SetResourceProperty(const std::string&, std::unique_ptr<AnimaXValueParam>, Callback)`
     *        (`PLT 0x00c630` @ `0x00a19c`).
     *
     *        Tái dựng phương thức `SetResourceProperty` (`0x009fd0..0x00a2a8`).
     */
    PropertyUpdateResponse SetResourceProperty(
        const std::string& resource_id,
        const JSValueParamDict& param_dict,
        std::function<void(bool, int32_t)> js_callback = nullptr);

    /**
     * @brief Reconstructs `Play` (`0x00a2ac..0x00a448`):
     *        Invokes `CompositionElement::Play()` (`PLT 0x00c640` @ `0x00a3f4`).
     *        Tái dựng phương thức `Play` (`0x00a2ac..0x00a448`): gọi `CompositionElement::Play()`.
     */
    bool Play() noexcept;

    uintptr_t NativeElementPtr() const noexcept { return native_element_ptr_; }
    uint32_t PlayCallCount() const noexcept { return play_call_count_; }
    const std::vector<LayerPropertyUpdateRecord>& LayerUpdates() const noexcept { return layer_updates_; }
    const std::vector<ResourcePropertyUpdateRecord>& ResourceUpdates() const noexcept { return resource_updates_; }

private:
    void AdjustExternalMemory(int64_t delta_bytes) noexcept;

    napi_env env_;
    uintptr_t native_element_ptr_;
    int64_t* external_memory_counter_;
    uint32_t play_call_count_;
    NapiCallbackRegistry callback_registry_;
    NapiTaskRunner task_runner_;
    std::vector<LayerPropertyUpdateRecord> layer_updates_;
    std::vector<ResourcePropertyUpdateRecord> resource_updates_;
};

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx

#endif  // OPENCUT_ANIMAX_NAPI_COMPOSITION_H_
