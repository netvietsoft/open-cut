// ==============================================================================
// FILE: ttmstrategycenter_interface.cpp
// TARGET: libTTMStrategyCenter.so (395,664 bytes, 899 dynamic symbols, 16 JNI methods)
// PURPOSE: Implementation of Unified Facade TtmstrategycenterEngine orchestrating
//          Universal BDI, TTMExtDataInterface, CEP EngineManager, and ByteDT GBDT
//          (Triển khai Facade hợp nhất TtmstrategycenterEngine điều phối Universal BDI,
//          TTMExtDataInterface, CEP EngineManager và ByteDT GBDT)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly & Symbol Cross-References)
// ==============================================================================

#include "ttmstrategycenter_interface.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <sstream>

namespace NextAI::OpenCut::TTMStrategyCenter {

// ==============================================================================
// Lifecycle Construction & Destruction (Vòng đời Khởi tạo & Hủy)
// ==============================================================================

TtmstrategycenterEngine::TtmstrategycenterEngine() {
    // [EN] Automatically initialize the Universal BDI table and CEP Evaluator on construction.
    // [VN] Tự động khởi tạo bảng Universal BDI và bộ đánh giá CEP khi tạo đối tượng.
    Initialize(nullptr);
}

TtmstrategycenterEngine::~TtmstrategycenterEngine() {
    Shutdown();
}

bool TtmstrategycenterEngine::Initialize(JavaVM* vm) {
    std::lock_guard<std::mutex> lock(mutex_);
    if (initialized_) {
        return true;
    }

    // [EN] Step 1: Store JavaVM pointer if provided (`g_vm` @ `0x64270`)
    // [VN] Bước 1: Lưu con trỏ JavaVM nếu được cung cấp (`g_vm` @ `0x64270`)
    if (vm != nullptr) {
        g_vm = vm;
    }

    // [EN] Step 2: Populate the 17 Universal BDI functions into `an_ttm_platform_universal_bdi_address_map` (`0x64140`)
    //      Matches `AnTTMPlatformUniversalBdiFunLoader::{base ctor}()` (`0x2324c`, 10,216 bytes)
    // [VN] Bước 2: Nạp 17 hàm Universal BDI vào `an_ttm_platform_universal_bdi_address_map` (`0x64140`)
    //      Khớp với `AnTTMPlatformUniversalBdiFunLoader::{base ctor}()` (`0x2324c`, 10.216 byte)
    AnTTMPlatformUniversalBdiFunLoader loader;
    (void)loader;

    // [EN] Step 3: Register the Feature Center callback (`AnTTMRegisterGetFeatureValueFunc` @ `0x26aa4`)
    // [VN] Bước 3: Đăng ký callback Feature Center (`AnTTMRegisterGetFeatureValueFunc` @ `0x26aa4`)
    AnTTMRegisterGetFeatureValueFunc(&AnTTMGetFeatureValue);

    // [EN] Step 4: Register the TTM CEP Expression Evaluator with `cep::EngineManager::Instance()`
    //      Matches `registerTTMCEPExprEvaluator()` (`0x34704`, 588 bytes)
    // [VN] Bước 4: Đăng ký bộ đánh giá biểu thức TTM CEP với `cep::EngineManager::Instance()`
    //      Khớp với `registerTTMCEPExprEvaluator()` (`0x34704`, 588 byte)
    registerTTMCEPExprEvaluator();

    initialized_ = true;
    last_error_code_ = 0;
    last_error_message_.clear();
    return true;
}

void TtmstrategycenterEngine::Shutdown() {
    std::lock_guard<std::mutex> lock(mutex_);
    if (!initialized_) {
        return;
    }

    // [EN] Clean up all CEP business streams in `cep::EngineManager::Instance()` (`0x47504`)
    // [VN] Dọn dẹp toàn bộ luồng nghiệp vụ CEP trong `cep::EngineManager::Instance()` (`0x47504`)
    cep::EngineManager::Instance().Clean("", "");

    initialized_ = false;
}

// ==============================================================================
// Subsystem 3: Strategy Rule Bytecode Execution (`ttm_sc_process` @ `0x35d34`)
// ==============================================================================

bool TtmstrategycenterEngine::EvaluateStrategyRule(
    const std::vector<std::uint8_t>& rule_bytecode,
    const std::unordered_map<std::string, std::any>& context_params,
    TTMStateCode& out_state_code,
    std::string& out_json_result) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        if (!initialized_) {
            out_state_code = TTMStateCode::kEngineNotInitialized;
            last_error_code_ = static_cast<int>(out_state_code);
            last_error_message_ = "TtmstrategycenterEngine is not initialized";
            return false;
        }
        ++total_rules_evaluated_;
    }

    if (rule_bytecode.empty()) {
        out_state_code = TTMStateCode::kInvalidBytecode;
        return false;
    }

    // [EN] Wrap `context_params` into a `ttm_sc_map` (`0x36088`) and invoke `ttm_sc_process` (`0x35d34`)
    // [VN] Đóng gói `context_params` vào `ttm_sc_map` (`0x36088`) và gọi `ttm_sc_process` (`0x35d34`)
    auto input_map = std::make_shared<ttm_sc_map>();
    for (const auto& kv : context_params) {
        input_map->SetValueForKey(kv.first, kv.second);
    }

    __TTMTransparentStruct input_transparent{};
    input_transparent.ext_interface = input_map.get();
    input_transparent.origin_data = input_map.get();
    input_transparent.origin_data_type = static_cast<int>(TTMDataType::kTypeDict);

    TTMValue result_val{};
    result_val.type = TTMDataType::kTypeNull;

    out_state_code = ttm_sc_process(
        rule_bytecode.data(),
        rule_bytecode.size(),
        &input_transparent,
        &result_val,
        nullptr);

    if (out_state_code != TTMStateCode::kSuccess) {
        std::lock_guard<std::mutex> lock(mutex_);
        last_error_code_ = static_cast<int>(out_state_code);
        last_error_message_ = "ttm_sc_process failed with state code " + std::to_string(last_error_code_);
        return false;
    }

    // [EN] Serialize output `TTMValue` into JSON string representation
    // [VN] Tuần tự hóa `TTMValue` đầu ra thành chuỗi biểu diễn JSON
    std::ostringstream oss;
    switch (result_val.type) {
        case TTMDataType::kTypeBool:
            oss << (result_val.bool_val ? "true" : "false");
            break;
        case TTMDataType::kTypeInt:
            oss << result_val.int_val;
            break;
        case TTMDataType::kTypeDouble:
            oss << result_val.double_val;
            break;
        case TTMDataType::kTypeString:
            oss << "\"" << (result_val.str_val ? result_val.str_val : "") << "\"";
            break;
        default:
            oss << "{\"status\":\"ok\",\"type\":" << static_cast<int>(result_val.type) << "}";
            break;
    }
    out_json_result = oss.str();
    return true;
}

// ==============================================================================
// Subsystem 3: CEP Event Dispatch (`cep::EngineManager::OnEvent` @ `0x48ba4`)
// ==============================================================================

cep::Result TtmstrategycenterEngine::DispatchCepEvent(
    const std::string& biz_name,
    const std::string& event_name,
    std::int64_t timestamp_ms,
    const std::unordered_map<std::string, std::any>& event_payload) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        ++total_cep_events_dispatched_;
    }

    auto map_wrapper = std::make_shared<ttm_sc_map>();
    for (const auto& kv : event_payload) {
        map_wrapper->SetValueForKey(kv.first, kv.second);
    }
    map_wrapper->SetValueForKey("event_name", std::any(event_name));
    map_wrapper->SetValueForKey("timestamp", std::any(timestamp_ms));

    auto event_wrapper = std::make_shared<cep::TTMMapCepEvent>(
        event_name, timestamp_ms, map_wrapper);

    return cep::EngineManager::Instance().OnEvent(biz_name, event_wrapper);
}

// ==============================================================================
// Subsystem 4: ByteDT GBDT Inference (`predict_raw` @ `0x4cf68` / `predict_leaf` @ `0x4d174`)
// ==============================================================================

int TtmstrategycenterEngine::RunByteDtInference(
    std::int64_t engine_handle,
    const std::vector<float>& dense_features,
    bool include_leaf_indices,
    std::vector<float>& out_probabilities,
    std::vector<float>& out_raw_margins,
    std::vector<int>& out_leaf_indices) {
    {
        std::lock_guard<std::mutex> lock(mutex_);
        ++total_bytedt_predictions_;
    }

    if (engine_handle == 0 || dense_features.empty()) {
        return transformByteDtErrorToTTMErrorCode(
            static_cast<std::int8_t>(bytedt::ByteDTErrorCode::kInvalidInput));
    }

    auto* engine = reinterpret_cast<bytedt::ByteDT*>(engine_handle);
    bytedt::Input input{};
    input.features = dense_features.data();
    input.num_features = static_cast<int>(dense_features.size());
    input.missing_value = NAN;

    bytedt::ByteDTErrorCode err_code = bytedt::ByteDTErrorCode::kSuccess;
    bytedt::RunInfo run_info{};

    bytedt::PredictResult pred = engine->predict(input, err_code, &run_info);
    if (err_code != bytedt::ByteDTErrorCode::kSuccess) {
        int ttm_err = transformByteDtErrorToTTMErrorCode(static_cast<std::int8_t>(err_code));
        std::lock_guard<std::mutex> lock(mutex_);
        last_error_code_ = ttm_err;
        last_error_message_ = "ByteDT inference error: " + std::to_string(ttm_err);
        return ttm_err;
    }

    out_probabilities = std::move(pred.probabilities);
    out_raw_margins = std::move(pred.raw_preds);

    if (include_leaf_indices) {
        bytedt::ByteDTErrorCode leaf_err = bytedt::ByteDTErrorCode::kSuccess;
        out_leaf_indices = engine->predict_leaf(input, leaf_err, &run_info);
        if (leaf_err != bytedt::ByteDTErrorCode::kSuccess) {
            return transformByteDtErrorToTTMErrorCode(static_cast<std::int8_t>(leaf_err));
        }
    } else {
        out_leaf_indices.clear();
    }

    return transformByteDtErrorToTTMErrorCode(static_cast<std::int8_t>(bytedt::ByteDTErrorCode::kSuccess));
}

// ==============================================================================
// Subsystem 1: Universal BDI Invocation (`an_ttm_platform_universal_bdi_address_map` @ `0x64140`)
// ==============================================================================

bool TtmstrategycenterEngine::InvokeUniversalBdi(
    const std::string& bdi_name,
    TTMContext* ctx,
    const TTMParam* params,
    std::size_t param_count,
    TTMValue* out_return_value) {
    if (out_return_value == nullptr) {
        return false;
    }

    const auto& bdi_map = GetUniversalBdiAddressMap();
    auto it = bdi_map.find(bdi_name);
    if (it == bdi_map.end() || it->second == nullptr) {
        std::lock_guard<std::mutex> lock(mutex_);
        last_error_code_ = -404;
        last_error_message_ = "Universal BDI function not found: " + bdi_name;
        return false;
    }

    using BdiFuncPtr = void (*)(TTMContext*, const TTMParam*, std::size_t, TTMValue*);
    auto fn = reinterpret_cast<BdiFuncPtr>(it->second);
    fn(ctx, params, param_count, out_return_value);
    return true;
}

TtmstrategycenterEngine::EngineDiagnostics TtmstrategycenterEngine::GetDiagnostics() const {
    std::lock_guard<std::mutex> lock(mutex_);
    EngineDiagnostics diag{};
    diag.initialized = initialized_;
    diag.registered_bdi_functions = GetUniversalBdiAddressMap().size();
    diag.active_cep_biz_streams = 0;
    diag.active_bytedt_models = 0;
    diag.total_rules_evaluated = total_rules_evaluated_;
    diag.total_cep_events_dispatched = total_cep_events_dispatched_;
    diag.total_bytedt_predictions = total_bytedt_predictions_;
    diag.last_error_code = last_error_code_;
    diag.last_error_message = last_error_message_;
    return diag;
}

} // namespace NextAI::OpenCut::TTMStrategyCenter
