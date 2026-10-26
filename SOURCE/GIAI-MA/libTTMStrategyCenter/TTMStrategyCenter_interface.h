// ==============================================================================
// FILE: ttmstrategycenter_interface.h
// TARGET: libTTMStrategyCenter.so (395,664 bytes, 899 dynamic symbols, 16 JNI methods)
// PURPOSE: Unified Public C++17 Interface & Facade Engine for TTMStrategyCenter
//          (Giao diện C++17 công khai hợp nhất & Engine Facade cho TTMStrategyCenter)
// EVIDENCE CLASSIFICATION: OBSERVED (ELF64 .dynsym + .rodata + .data.rel.ro)
// ==============================================================================

#pragma once

#include "ttmstrategycenter_types.h"
#include "ttmstrategycenter_bdi_feature.h"
#include "ttmstrategycenter_data_wrappers.h"
#include "ttmstrategycenter_cep_engine.h"
#include "ttmstrategycenter_bytedt_jni.h"

#include <cstdint>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

namespace NextAI::OpenCut::TTMStrategyCenter {

/**
 * [EN] Unified facade class orchestrating all four native subsystems of libTTMStrategyCenter.so:
 *      1. Universal BDI (Business Data Interface) & Feature Center (`0x22fe0`..`0x27714`)
 *      2. TTMExtDataInterface & ttm_sc_map / ttm_sc_list / TTMExtJson (`0x28568`..`0x47504`)
 *      3. CEP (Complex Event Processing) & TTM Machine Rule Evaluator (`0x32df8`..`0x4c174`)
 *      4. ByteDT Gradient Boosted Decision Tree Engine & 16 JNI Bridges (`0x2e6cc`..`0x4ea30`)
 *
 * [VN] Lớp Facade hợp nhất điều phối cả 4 phân hệ native của libTTMStrategyCenter.so:
 *      1. Universal BDI (Giao diện Dữ liệu Nghiệp vụ) & Feature Center (`0x22fe0`..`0x27714`)
 *      2. TTMExtDataInterface & ttm_sc_map / ttm_sc_list / TTMExtJson (`0x28568`..`0x47504`)
 *      3. CEP (Xử lý Sự kiện Phức hợp) & Bộ đánh giá luật TTM Machine (`0x32df8`..`0x4c174`)
 *      4. Động cơ cây quyết định ByteDT GBDT & 16 cầu nối JNI (`0x2e6cc`..`0x4ea30`)
 */
class TtmstrategycenterEngine {
public:
    /**
     * [EN] Diagnostic telemetry snapshot of the TTMStrategyCenter native engine.
     * [VN] Bản chụp thông số chẩn đoán của engine native TTMStrategyCenter.
     */
    struct EngineDiagnostics {
        bool initialized{false};
        std::size_t registered_bdi_functions{0};
        std::size_t active_cep_biz_streams{0};
        std::size_t active_bytedt_models{0};
        std::uint64_t total_rules_evaluated{0};
        std::uint64_t total_cep_events_dispatched{0};
        std::uint64_t total_bytedt_predictions{0};
        int last_error_code{0};
        std::string last_error_message{};
    };

    TtmstrategycenterEngine();
    virtual ~TtmstrategycenterEngine();

    // Non-copyable, movable (Không sao chép, hỗ trợ di chuyển)
    TtmstrategycenterEngine(const TtmstrategycenterEngine&) = delete;
    TtmstrategycenterEngine& operator=(const TtmstrategycenterEngine&) = delete;

    /**
     * [EN] Initializes the Strategy Center native runtime, loading all 17 Universal BDI
     *      functions (`AnTTMPlatformUniversalBdiFunLoader` @ `0x2324c`), registering the
     *      TTMCEPExprEvaluator (`registerTTMCEPExprEvaluator` @ `0x34704`), and binding
     *      the Feature Center callback (`AnTTMRegisterGetFeatureValueFunc` @ `0x26aa4`).
     * [VN] Khởi tạo runtime native Strategy Center, nạp toàn bộ 17 hàm Universal BDI
     *      (`AnTTMPlatformUniversalBdiFunLoader` @ `0x2324c`), đăng ký TTMCEPExprEvaluator
     *      (`registerTTMCEPExprEvaluator` @ `0x34704`), và gắn callback Feature Center
     *      (`AnTTMRegisterGetFeatureValueFunc` @ `0x26aa4`).
     */
    bool Initialize(JavaVM* vm = nullptr);

    /**
     * [EN] Releases all active CEP business streams, ByteDT engines, and cached JNI handles.
     * [VN] Giải phóng toàn bộ luồng nghiệp vụ CEP, các engine ByteDT và các handle JNI đã lưu.
     */
    void Shutdown();

    /**
     * [EN] Executes a compiled TTM Machine rule bytecode stream against an input context map
     *      (delegates to `ttm_sc_process` @ `0x35d34`).
     * [VN] Thực thi luồng bytecode luật TTM Machine đã biên dịch trên map ngữ cảnh đầu vào
     *      (ủy quyền cho `ttm_sc_process` @ `0x35d34`).
     */
    bool EvaluateStrategyRule(
        const std::vector<std::uint8_t>& rule_bytecode,
        const std::unordered_map<std::string, std::any>& context_params,
        TTMStateCode& out_state_code,
        std::string& out_json_result);

    /**
     * [EN] Dispatches an event to the CEP EngineManager (`cep::EngineManager::OnEvent` @ `0x48ba4`)
     *      and returns matched sequence pattern results.
     * [VN] Phát một sự kiện tới CEP EngineManager (`cep::EngineManager::OnEvent` @ `0x48ba4`)
     *      và trả về kết quả chuỗi sự kiện khớp mẫu.
     */
    cep::Result DispatchCepEvent(
        const std::string& biz_name,
        const std::string& event_name,
        std::int64_t timestamp_ms,
        const std::unordered_map<std::string, std::any>& event_payload);

    /**
     * [EN] Runs a GBDT inference pass on a loaded ByteDT model instance (`predict_raw` @ `0x4cf68`
     *      or `predict_leaf` @ `0x4d174`) and maps error codes via `transformByteDtErrorToTTMErrorCode` (`0x4d21c`).
     * [VN] Chạy suy luận GBDT trên thực thể mô hình ByteDT đã nạp (`predict_raw` @ `0x4cf68`
     *      hoặc `predict_leaf` @ `0x4d174`) và ánh xạ mã lỗi qua `transformByteDtErrorToTTMErrorCode` (`0x4d21c`).
     */
    int RunByteDtInference(
        std::int64_t engine_handle,
        const std::vector<float>& dense_features,
        bool include_leaf_indices,
        std::vector<float>& out_probabilities,
        std::vector<float>& out_raw_margins,
        std::vector<int>& out_leaf_indices);

    /**
     * [EN] Invokes one of the 17 registered `"universal.*"` BDI functions by name.
     * [VN] Gọi một trong 17 hàm BDI `"universal.*"` đã đăng ký theo tên.
     */
    bool InvokeUniversalBdi(
        const std::string& bdi_name,
        TTMContext* ctx,
        const TTMParam* params,
        std::size_t param_count,
        TTMValue* out_return_value);

    /**
     * [EN] Returns current diagnostic metrics of the engine.
     * [VN] Trả về các chỉ số chẩn đoán hiện tại của engine.
     */
    EngineDiagnostics GetDiagnostics() const;

private:
    mutable std::mutex mutex_;
    bool initialized_{false};
    std::uint64_t total_rules_evaluated_{0};
    std::uint64_t total_cep_events_dispatched_{0};
    std::uint64_t total_bytedt_predictions_{0};
    int last_error_code_{0};
    std::string last_error_message_{};
};

} // namespace NextAI::OpenCut::TTMStrategyCenter
