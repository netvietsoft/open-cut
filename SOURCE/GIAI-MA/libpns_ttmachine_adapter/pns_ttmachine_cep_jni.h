/**
 * @file pns_ttmachine_cep_jni.h
 * @brief TTMAdapter JNI Bridge, CEP ExprEvaluator & TTM Bytecode Execution for libpns_ttmachine_adapter.so
 *        Cầu nối JNI TTMAdapter, Bộ định giá biểu thức CEP & Thực thi bytecode TTM cho libpns_ttmachine_adapter.so
 *
 * Disassembly Reference / Tham chiếu Disassembly:
 *   - 0x007498..0x007500: init_array_1 (initializes global maps at 0x054208 & 0x054230 -> jumps to 0x014598)
 *   - 0x008868..0x00a3cc: Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init (7,012 B)
 *   - 0x00a468..0x00bdb8: ttm_adapter_execute_core (runs TTM bytecode & CEP rules, builds TTMachineExecuteResult)
 *   - 0x00c188..0x00c3a4: Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3 (544 B)
 *   - 0x00c3a8..0x00c6f0: Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution (844 B)
 *   - 0x01344c..0x013c24: TTMExprEvaluator (vtable 0x052818, overrides cep::ExprEvaluator::Init & Calculate)
 *   - 0x014598..0x015b00: register_ttm_cep_extensions (registers 21 custom functions & CEP ExprEvaluator)
 */

#ifndef NEXTAI_OPENCUT_PNS_TTMACHINE_CEP_JNI_H_
#define NEXTAI_OPENCUT_PNS_TTMACHINE_CEP_JNI_H_

#include "pns_ttmachine_types.h"

namespace pns {
namespace ttmachine {

// ============================================================================
// 1. TTMachineExecuteResult & Time Statistics (0x043af2, 0x043bca, 0x043db4)
//    Kết quả thực thi TTMachine & Thống kê thời gian (0x043af2, 0x043bca, 0x043db4)
// ============================================================================
struct TTMStatePreprocessTimeStats {
    int64_t total_preprocess_us = 0;   // <init>(JIII)V at 0x043dfd
    int32_t json_parse_us = 0;
    int32_t sign_decode_us = 0;
    int32_t cep_register_us = 0;
};

struct TTMStateExecutionTimeStats {
    int64_t total_exec_us = 0;         // <init>(JIIII)V at 0x043c12
    int32_t data_init_us = 0;
    int32_t ttm_vm_run_us = 0;
    int32_t cep_eval_us = 0;
    int32_t result_build_us = 0;
};

struct TTMachineExecuteResultNative {
    std::vector<std::string> hit_strategy_ids;
    std::vector<std::string> policy_actions;
    std::vector<std::string> matched_events; // "matchedEvents" (0x044c34)
    std::vector<std::string> attribution_tags;
    TTMStateExecutionTimeStats exec_stats;
};

// ============================================================================
// 2. TTM & CEP Extension Registration (0x014598) & Condition Evaluation
//    Đăng ký tiện ích mở rộng TTM & CEP (0x014598) & Đánh giá điều kiện
// ============================================================================
void InitializeTtmCepExtensions();
const std::vector<std::string>& GetRegisteredCustomFunctionNames();

bool DecodeAndRegisterCondition(RuleCondition& cond);
bool EvaluateTtmBytecodeCondition(
    const RuleCondition& cond,
    const std::unordered_map<std::string, std::string>& params,
    int32_t* out_error_code);
bool EvaluateCepConditionRule(
    const std::string& rule_id,
    const std::string& expr_or_rule,
    const std::unordered_map<std::string, std::string>& params);

// Core TTMAdapter bundle parser & executor (0x008868 & 0x00a468)
// Bộ phân tích gói luật & thực thi lõi TTMAdapter (0x008868 & 0x00a468)
TTMStatePreprocessTimeStats InitTtmAdapterBundle(const std::string& bundle_json);
TTMachineExecuteResultNative ExecuteTtmAdapterValidation(
    const std::string& strategy_set_key,
    const std::vector<std::unordered_map<std::string, std::string>>& event_chain);

} // namespace ttmachine
} // namespace pns

// ============================================================================
// 3. Exported JNI Symbols for com.bytedance.pns.pns_ttmachine_adapter.TTMAdapter
//    Các ký hiệu JNI xuất ra cho com.bytedance.pns.pns_ttmachine_adapter.TTMAdapter
// ============================================================================
extern "C" {

// 0x008868 (7,012 B): Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init
JNIEXPORT jobject JNICALL Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init(
    JNIEnv* env,
    jclass clazz,
    jstring config_json);

// 0x00c188 (544 B): Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3
JNIEXPORT jobject JNICALL Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3(
    JNIEnv* env,
    jclass clazz,
    jstring strategy_set_name,
    jobject param_map);

// 0x00c3a8 (844 B): Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution
JNIEXPORT jobject JNICALL Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution(
    JNIEnv* env,
    jclass clazz,
    jstring strategy_set_name,
    jobjectArray param_map_array);

} // extern "C"

#endif // NEXTAI_OPENCUT_PNS_TTMACHINE_CEP_JNI_H_
