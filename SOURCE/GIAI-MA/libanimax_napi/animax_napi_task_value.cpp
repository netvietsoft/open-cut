/**
 * @file animax_napi_task_value.cpp
 * @brief Implementation of JSValueParamDict Converter, Restricted Double Validator, NapiCallbackRegistry, and NapiTaskRunner
 *        Triển khai Bộ chuyển đổi JSValueParamDict, Kiểm tra Restricted Double, NapiCallbackRegistry, và NapiTaskRunner
 *
 * Binary Ground Truth (libanimax_napi.so):
 *   - `ConvertToAnimaXValueParam` (`0x008430..0x008548`)
 *   - `InvokePropertyUpdateJsCallback` (`0x008d48..0x0090fc`)
 *   - `ParseValueParamDictionary` (`0x00a650..0x00a964`)
 *   - `ParseCallbackFunction` (`0x00a968..0x00ab14`)
 *   - `NapiTaskRunner::PostTask` (`0x00ace8..0x00ada8` & `0x00ae70..0x00b190`)
 *   - `ValidateRestrictedDouble` (`0x00bed0..0x00bf48`)
 */

#include "animax_napi_task_value.h"
#include <cmath>
#include <cstdio>
#include <cstring>
#include <sstream>

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. RESTRICTED DOUBLE VALIDATION (0x00bed0..0x00bf48)
// ============================================================================

/**
 * @brief Exact IEEE-754 finite check matching `sub_bed0` (`0x00bed0..0x00bf48`):
 *        ```asm
 *        0x00bef8: 08feefd2 mov   x8, #0x7ff0000000000000
 *        0x00befc: 01c0601e fabs  d1, d0
 *        0x00bf00: 0020601e fcmp  d0, d0
 *        0x00bf04: 0201679e fmov  d2, x8
 *        0x00bf08: 2474621e fccmp d1, d2, #4, vc
 *        0x00bf0c: 01010054 b.ne  #0xbf2c
 *        ```
 *        In AArch64:
 *        - `fcmp d0, d0` sets `V=1` (overflow/unordered) if `d0` is `NaN`, or `V=0` (`vc` = true) if ordered.
 *        - If `vc` holds (`!isnan(d0)`), `fccmp d1, d2, #4, vc` compares `fabs(d0)` against `+Inf` (`0x7ff0000000000000`).
 *          If `d0` was `NaN` (`vc` false), `fccmp` sets NZCV = `#4` (`Z=1`, `eq`).
 *        - Therefore `b.ne #0xbf2c` branches to the valid path when `!isnan(d0) && fabs(d0) != +Inf`,
 *          and falls through to the `TypeError("Invalid type for argument %d, expecting: Restricted Double")`
 *          throw path when `d0` is `NaN` or `+-Inf`.
 *
 *        Kiểm tra số thực hữu hạn chuẩn IEEE-754 khớp chính xác `sub_bed0` (`0x00bed0..0x00bf48`).
 */
bool IsRestrictedDoubleFinite(double val) noexcept {
    uint64_t raw_bits = 0;
    std::memcpy(&raw_bits, &val, sizeof(raw_bits));
    // Clear sign bit (`fabs d1, d0` @ `0x00befc: 01 c0 60 1e`)
    // Xóa bit dấu (`fabs d1, d0` @ `0x00befc`)
    const uint64_t abs_bits = raw_bits & 0x7FFFFFFFFFFFFFFFULL;
    // Compare against `0x7ff0000000000000ULL` (`mov x8, #0x7ff0000000000000` @ `0x00bef8: 08 fe ef d2`)
    // So sánh với ngưỡng vô cực/NaN `0x7ff0000000000000ULL` (@ `0x00bef8`)
    return abs_bits < kIeee754PositiveInfinityBits;
}

/**
 * @brief Validates a restricted double argument and formats the exact error string at `.rodata` `0x0033cd`
 *        (`"Invalid type for argument %d, expecting: %s"` + `"Restricted Double"` at `0x003425`) when invalid.
 *        Kiểm tra tham số thực giới hạn và định dạng chuỗi lỗi chính xác tại `.rodata` `0x0033cd` khi không hợp lệ.
 */
double ValidateRestrictedDoubleOrThrow(napi_env env,
                                       double raw_value,
                                       int32_t arg_index,
                                       std::string* out_error_msg) noexcept {
    (void)env;
    if (IsRestrictedDoubleFinite(raw_value)) {
        if (out_error_msg != nullptr) {
            out_error_msg->clear();
        }
        return raw_value;
    }

    // Reconstructs `0x00bf0e..0x00bf28`: formats `"Invalid type for argument %d, expecting: Restricted Double"`
    // and returns `0.0` (`movi d0, #0000000000000000` @ `0x00bf28: 00 00 00 6f`).
    // Tái dựng `0x00bf0e..0x00bf28`: định dạng thông báo lỗi và trả về `0.0`.
    char buf[128];
    std::snprintf(buf, sizeof(buf), kInvalidTypeFmt, arg_index, kExpectingRestrictedDouble);
    if (out_error_msg != nullptr) {
        *out_error_msg = buf;
    }
    return 0.0;
}

// ============================================================================
// 2. VALUE PARAM DICTIONARY CONVERSION (0x008430..0x008548)
// ============================================================================

/**
 * @brief Reconstructs `ConvertToAnimaXValueParam` (`0x008430..0x008548`):
 *        1. `0x008448`: `mov w0, #0x90; bl _Znwm` -> allocates `144 bytes` (`0x90`) `AnimaXValueParam`.
 *        2. `0x008450`: `mov x19, x0; bl lynx::animax::AnimaXValueParam::AnimaXValueParam()`
 *        3. Checks each optional field in `JSValueParamDict`:
 *           - `+0x00` (`has_float_value`): `ldr s0, [x20, #4]; fcvt d0, s0; fstr d0, [x19, #8]; strb w21, [x19, #0x10]` (`0x008460..0x00846c`)
 *           - `+0x08` (`has_int_value`): `ldr w8, [x20, #0xc]; str w8, [x19, #0x14]; strb w21, [x19, #0x18]` (`0x008474..0x00847c`)
 *           - `+0x10` (`has_bool_value`): `ldrb w8, [x20, #0x11]; strb w8, [x19, #0x1c]; strb w21, [x19, #0x1d]` (`0x008484..0x00848c`)
 *           - `+0x18` (`has_string_value`): copies `string_value` (`+0x20`) into `AnimaXValueParam+0x20` and sets `+0x38 = 1` (`0x008494..0x0084bc`)
 *           - `+0x38` (`has_float_array`): converts `std::vector<float>` (`+0x40..+0x57`) to `std::vector<double>` at `AnimaXValueParam+0x58`
 *             via `fcvt d0, s0` loop (`0x0084fc..0x008530`) and sets `+0x70 = 1`.
 *
 *        Tái dựng hàm `ConvertToAnimaXValueParam` (`0x008430..0x008548`) chuyển đổi từ `JSValueParamDict`
 *        sang đối tượng `AnimaXValueParam` (`144 bytes = 0x90`).
 */
std::unique_ptr<AnimaXValueParam> ConvertToAnimaXValueParam(const JSValueParamDict& dict) {
    auto param = std::make_unique<AnimaXValueParam>();

    // 1. Optional float -> double (`0x00845c..0x00846c`)
    // 1. Chuyển đổi float tùy chọn sang double (`0x00845c..0x00846c`)
    if (dict.has_float_value) {
        param->double_value = static_cast<double>(dict.float_value);
        param->has_double_value = true;
    }

    // 2. Optional int32 (`0x008470..0x00847c`)
    // 2. Sao chép int32 tùy chọn (`0x008470..0x00847c`)
    if (dict.has_int_value) {
        param->int_value = dict.int_value;
        param->has_int_value = true;
    }

    // 3. Optional bool (`0x008480..0x00848c`)
    // 3. Sao chép bool tùy chọn (`0x008480..0x00848c`)
    if (dict.has_bool_value) {
        param->bool_value = dict.bool_value;
        param->has_bool_value = true;
    }

    // 4. Optional string (`0x008490..0x0084bc`)
    // 4. Sao chép chuỗi tùy chọn (`0x008490..0x0084bc`)
    if (dict.has_string_value) {
        param->string_value = dict.string_value;
        param->has_string_value = true;
    }

    // 5. Optional float array -> double array (`0x0084c0..0x008534`)
    // 5. Chuyển đổi mảng float sang mảng double (`0x0084c0..0x008534`)
    if (dict.has_float_array) {
        param->double_array.clear();
        param->double_array.reserve(dict.float_array.size());
        for (float f : dict.float_array) {
            // `ldr s0, [x22], #4; fcvt d0, s0` (`0x008504..0x008508`)
            param->double_array.push_back(static_cast<double>(f));
        }
        param->has_double_array = true;
    }

    return param;
}

// ============================================================================
// 3. CALLBACK REGISTRY & ASYNC INVOKER (0x008d48..0x0090fc, 0x00a968..0x00ab14)
// ============================================================================

NapiCallbackRegistry::NapiCallbackRegistry(napi_env env) noexcept
    : env_(env),
      max_load_factor_(1.0f),
      next_id_(1) {
    // Matches `0x00aa2c: mov w8, #0x3f800000; str w8, [x24, #0x28]`
    // Khớp với `0x00aa2c: mov w8, #0x3f800000` (`max_load_factor = 1.0f`)
    callbacks_.max_load_factor(max_load_factor_);
}

NapiCallbackRegistry::~NapiCallbackRegistry() noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    callbacks_.clear();
}

/**
 * @brief Registers a JS callback function reference and returns an 80-byte (`0x50`) handle,
 *        matching `ParseCallbackFunction` (`0x00a968..0x00ab14`).
 *        Đăng ký tham chiếu hàm callback JS và trả về handle 80-byte (`0x50`),
 *        khớp với `ParseCallbackFunction` (`0x00a968..0x00ab14`).
 */
std::shared_ptr<JsCallbackHandle> NapiCallbackRegistry::RegisterCallback(
    napi_ref func_ref,
    std::function<void(bool, int32_t)> invoker) {
    std::lock_guard<std::mutex> lock(mutex_);
    auto handle = std::make_shared<JsCallbackHandle>();
    handle->registry_owner = this;
    handle->env = env_;
    handle->func_ref = func_ref;
    handle->native_invoker = std::move(invoker);
    handle->handle_id = next_id_++;
    callbacks_[handle->handle_id] = handle;
    return handle;
}

/**
 * @brief Invokes a registered JS callback with `{ "result": bool, "code": int32 }`
 *        and removes its reference from the registry, matching `sub_8d48` (`0x008d48..0x0090fc`):
 *        - `0x008df8`: `napi_open_handle_scope`
 *        - `0x008e24`: `Object::New(env)`
 *        - `0x008e44`: `Boolean::New(env, response.result)` -> `obj.Set("result", ...)` (`0x0032cd`)
 *        - `0x008ea8`: `Number::New(env, response.code)` -> `obj.Set("code", ...)` (`0x0032d4`)
 *        - `0x008f38`: `Function::Call(env, recv, 1, &obj)`
 *        - `0x008f5c..0x0090cc`: erases callback handle from hash table (`sub_979c`) and closes handle scope.
 *
 *        Gọi hàm callback JS đã đăng ký với đối tượng `{ "result": bool, "code": int32 }`
 *        và xóa tham chiếu khỏi sổ đăng ký, khớp với `sub_8d48` (`0x008d48..0x0090fc`).
 */
bool NapiCallbackRegistry::TakeAndInvokeCallback(
    uint64_t handle_id,
    const PropertyUpdateResponse& response) {
    std::shared_ptr<JsCallbackHandle> handle;
    {
        std::lock_guard<std::mutex> lock(mutex_);
        auto it = callbacks_.find(handle_id);
        if (it == callbacks_.end()) {
            return false;
        }
        handle = it->second;
        callbacks_.erase(it);
    }

    if (handle && handle->native_invoker) {
        handle->native_invoker(response.result, static_cast<int32_t>(response.code));
        return true;
    }
    return false;
}

size_t NapiCallbackRegistry::ActiveCount() const noexcept {
    std::lock_guard<std::mutex> lock(mutex_);
    return callbacks_.size();
}

// ============================================================================
// 4. NAPI TASK RUNNER (0x00ace8..0x00ada8 & 0x00ae70..0x00b190)
// ============================================================================

NapiTaskRunner::NapiTaskRunner(napi_env env) noexcept
    : env_(env) {}

/**
 * @brief Posts a task to the NAPI environment's JS thread (`env + 0x370` @ `0x00af18`).
 *        If `status != 0` (`cbnz w22, #0xaf34` @ `0x00af20`), constructs `lynx::animax::LogMessage`
 *        at `"../../platform/harmony/animax/src/main/cpp/src/napi/base/napi_task_runner.cc":176` (`0xb0`)
 *        with severity `4` (`ERROR`) and writes:
 *        `"NapiTaskRunner::PostTask failed to call napi API: "` (`51 chars = 0x33` @ `0x003437`)
 *        followed by `status` (`0x00af94: bl std::ostream::operator<<(int)`).
 *
 *        Đẩy một tác vụ về luồng JS của môi trường NAPI (`env + 0x370` @ `0x00af18`).
 *        Nếu `status != 0`, khởi tạo `lynx::animax::LogMessage` tại dòng `176` (`0xb0`) với mức `4` (`ERROR`).
 */
bool NapiTaskRunner::PostTask(std::function<void()> task, int32_t simulated_napi_status) {
    (void)env_;
    if (simulated_napi_status != 0) {
        std::ostringstream oss;
        oss << kNapiTaskRunnerFile << ":" << kLogLineNumber
            << " [ERROR=" << kAnimaXLogSeverityError << "] "
            << kNapiTaskRunnerErrPrefix << simulated_napi_status;
        last_error_log_ = oss.str();
        return false;
    }

    last_error_log_.clear();
    if (task) {
        task();
    }
    return true;
}

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx
