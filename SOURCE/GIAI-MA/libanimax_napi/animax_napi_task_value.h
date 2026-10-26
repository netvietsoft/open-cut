/**
 * @file animax_napi_task_value.h
 * @brief JSValueParamDict Parser, Restricted Double Validator, NapiTaskRunner, and Async Callback Bridge
 *        Bộ phân tích JSValueParamDict, Kiểm tra Restricted Double, NapiTaskRunner, và Cầu nối Callback Bất đồng bộ
 *
 * Binary Ground Truth (libanimax_napi.so):
 *   - `ConvertToAnimaXValueParam` (`0x008430..0x008548`)
 *   - `InvokePropertyUpdateJsCallback` (`0x008d48..0x0090fc`)
 *   - `ParseValueParamDictionary` (`0x00a650..0x00a964`)
 *   - `ParseCallbackFunction` (`0x00a968..0x00ab14`)
 *   - `NapiTaskRunner::PostTask` (`0x00ace8..0x00ada8` & `0x00ae70..0x00b190`)
 *   - `ValidateRestrictedDouble` (`0x00bed0..0x00bf48`: `0x7ff0000000000000ULL` IEEE-754 finite check)
 */

#ifndef OPENCUT_ANIMAX_NAPI_TASK_VALUE_H_
#define OPENCUT_ANIMAX_NAPI_TASK_VALUE_H_

#include "animax_napi_types.h"
#include "animax_napi_hash_stl.h"
#include <functional>
#include <memory>
#include <mutex>
#include <unordered_map>

namespace lynx {
namespace animax {
namespace napi_bridge {

// ============================================================================
// 1. RESTRICTED DOUBLE & VALUE PARAM CONVERSION (0x008430..0x008548, 0x00a650..0x00a964, 0x00bed0..0x00bf48)
// ============================================================================

/**
 * @brief Validates that a double value is finite (`!isnan(d) && fabs(d) != +Inf`),
 *        matching `sub_bed0` (`0x00bed0..0x00bf48`):
 *        ```asm
 *        0x00bef8: 08feefd2 mov   x8, #0x7ff0000000000000
 *        0x00befc: 01c0601e fabs  d1, d0
 *        0x00bf00: 0020601e fcmp  d0, d0
 *        0x00bf04: 0201679e fmov  d2, x8
 *        0x00bf08: 2474621e fccmp d1, d2, #4, vc
 *        0x00bf0c: 01010054 b.ne  #0xbf2c
 *        ```
 *        Xác thực số thực double là hữu hạn (`!isnan(d) && fabs(d) != +Inf`),
 *        khớp với `sub_bed0` (`0x00bed0..0x00bf48`).
 */
bool IsRestrictedDoubleFinite(double val) noexcept;

/**
 * @brief Validates a restricted double and throws a JS TypeError (`"Invalid type for argument %d, expecting: Restricted Double"`)
 *        returning `0.0` on NaN/Inf (`0x00bed0..0x00bf48`).
 *        Kiểm tra số thực double giới hạn và ném lỗi JS TypeError trả về `0.0` nếu là NaN/Inf.
 */
double ValidateRestrictedDoubleOrThrow(napi_env env,
                                       double raw_value,
                                       int32_t arg_index,
                                       std::string* out_error_msg = nullptr) noexcept;

/**
 * @brief Converts a `JSValueParamDict` (`64 bytes = 0x40`) into a heap-allocated
 *        `AnimaXValueParam` (`144 bytes = 0x90`), matching `sub_8430` (`0x008430..0x008548`).
 *        Chuyển đổi `JSValueParamDict` (`64 bytes = 0x40`) thành `AnimaXValueParam`
 *        (`144 bytes = 0x90`) cấp phát trên heap, khớp với `sub_8430` (`0x008430..0x008548`).
 */
std::unique_ptr<AnimaXValueParam> ConvertToAnimaXValueParam(const JSValueParamDict& dict);

// ============================================================================
// 2. CALLBACK REGISTRY & NAPI TASK RUNNER (0x008d48..0x0090fc, 0x00a968..0x00b190)
// ============================================================================

/**
 * @brief 80-byte (`0x50`) callback handle allocated in `ParseCallbackFunction` (`0x00a9b0: mov w0, #0x50; bl _Znwm`).
 *        Cấu trúc quản lý callback 80-byte (`0x50`) cấp phát trong `ParseCallbackFunction` (`0x00a9b0`).
 */
struct JsCallbackHandle {
    void* registry_owner{nullptr};                      // +0x00
    std::shared_ptr<void> registry_control_block{};     // +0x08..+0x17
    napi_env env{nullptr};                              // +0x18
    napi_ref func_ref{nullptr};                         // +0x20
    std::function<void(bool, int32_t)> native_invoker;  // +0x28..+0x47
    uint64_t handle_id{0};                              // +0x48
};

/**
 * @brief Per-`napi_env` callback registry (`56 bytes = 0x38` allocated at `0x00a9f8`,
 *        stored at `env.SetInstanceData(0x101f0, ...)` @ `0x00aa50` with `max_load_factor = 1.0f = 0x3f800000` @ `0x00aa2c`).
 *        Sổ đăng ký callback theo từng `napi_env` (`56 bytes = 0x38` cấp phát tại `0x00a9f8`,
 *        lưu tại `env.SetInstanceData(0x101f0, ...)` @ `0x00aa50`).
 */
class NapiCallbackRegistry {
public:
    static constexpr uintptr_t kInstanceDataKey = 0x101f0u;
    static constexpr uint32_t kDefaultMaxLoadFactorBits = 0x3f800000u;  // 1.0f (@ 0x00aa2c)

    explicit NapiCallbackRegistry(napi_env env) noexcept;
    ~NapiCallbackRegistry() noexcept;

    std::shared_ptr<JsCallbackHandle> RegisterCallback(
        napi_ref func_ref,
        std::function<void(bool, int32_t)> invoker);

    bool TakeAndInvokeCallback(uint64_t handle_id, const PropertyUpdateResponse& response);

    size_t ActiveCount() const noexcept;

private:
    napi_env env_;
    float max_load_factor_;
    mutable std::mutex mutex_;
    std::unordered_map<uint64_t, std::shared_ptr<JsCallbackHandle>> callbacks_;
    uint64_t next_id_;
};

/**
 * @brief Reconstructs `NapiTaskRunner` (`0x00ace8..0x00ada8` & `0x00ae70..0x00b190`)
 *        which posts completion tasks back onto the Napi JS thread (`env + 0x370`)
 *        and logs to `lynx::animax::LogMessage("napi_task_runner.cc", 176, ERROR=4)` on failure.
 *        Tái dựng `NapiTaskRunner` (`0x00ace8..0x00ada8` & `0x00ae70..0x00b190`)
 *        đẩy tác vụ hoàn thành về luồng JS Napi (`env + 0x370`) và ghi log lỗi nếu thất bại.
 */
class NapiTaskRunner {
public:
    static constexpr int32_t kLogLineNumber = 176;                  // 0xb0 (@ 0x00af44)
    static constexpr size_t kErrorPrefixLength = 51;                // 0x33 (@ 0x00af68 / 0x00af88)

    explicit NapiTaskRunner(napi_env env) noexcept;
    ~NapiTaskRunner() noexcept = default;

    bool PostTask(std::function<void()> task, int32_t simulated_napi_status = 0);

    const std::string& LastErrorLog() const noexcept { return last_error_log_; }

private:
    napi_env env_;
    std::string last_error_log_;
};

}  // namespace napi_bridge
}  // namespace animax
}  // namespace lynx

#endif  // OPENCUT_ANIMAX_NAPI_TASK_VALUE_H_
