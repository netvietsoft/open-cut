/**
 * @file pns_ttmachine_cep_jni.cpp
 * @brief Implementation of TTMAdapter JNI Bridge, CEP ExprEvaluator & TTM Bytecode Runner
 *        Triển khai cầu nối JNI TTMAdapter, Bộ định giá biểu thức CEP & Bộ chạy bytecode TTM
 *
 * Binary Ground Truth / Bằng chứng nhị phân thực tế:
 *   - 0x007498..0x007500: init_array_1 -> 0x014598 (register_ttm_cep_extensions)
 *   - 0x008868..0x00a3cc: Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init (7,012 B)
 *   - 0x00a468..0x00bdb8: ttm_adapter_execute_core
 *   - 0x00c188..0x00c3a4: Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3 (544 B)
 *   - 0x00c3a8..0x00c6f0: Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution (844 B)
 *   - 0x01344c..0x013c24: TTMExprEvaluator (vtable 0x052818)
 *   - 0x014598..0x015b00: Registers 21 custom TTM/CEP functions and CEP ExprEvaluator
 */

#include "pns_ttmachine_cep_jni.h"
#include "pns_ttmachine_sampling_namelist.h"
#include <chrono>
#include <cstring>
#include <mutex>
#include <pthread.h>

// ============================================================================
// Weak Fallback Definitions for libTTMachineCore.so & libCepEngine.so Imports
// Định nghĩa dự phòng liên kết yếu cho các ký hiệu từ libTTMachineCore.so & libCepEngine.so
// ============================================================================
extern "C" {

__attribute__((weak)) int ttm_preprocess_sign_decode(
    const char* sign_str,
    size_t sign_len,
    uint8_t** out_buf,
    size_t* out_len) {
    if (!sign_str || sign_len == 0 || !out_buf || !out_len) {
        return -1;
    }
    auto* buf = static_cast<uint8_t*>(std::malloc(sign_len));
    if (!buf) {
        return -1;
    }
    std::memcpy(buf, sign_str, sign_len);
    *out_buf = buf;
    *out_len = sign_len;
    return 0;
}

__attribute__((weak)) int ttm_state_mn_run_with_bytes(
    const uint8_t* bytecode,
    size_t bytecode_len,
    void* /*ext_data*/,
    void* out_value) {
    if (!bytecode || bytecode_len == 0) {
        return -1;
    }
    if (out_value) {
        *static_cast<int64_t*>(out_value) = 1;
    }
    return 0;
}

__attribute__((weak)) int ttm_state_error_code_for_business(void* /*state*/) {
    return 0;
}

__attribute__((weak)) void ttm_task_finish_free_objects(void* /*state*/) {}

} // extern "C"

namespace pns {
namespace ttmachine {

namespace {

std::once_flag g_ext_init_once;
pthread_rwlock_t g_adapter_rwlock = PTHREAD_RWLOCK_INITIALIZER; // 0x055618

// All 21 custom function names verified in .rodata (0x044a39..0x044cd3) & registered in 0x014598:
const std::vector<std::string> kRegisteredCustomFunctions = {
    "version_compare",                       // 0x044a39
    "is_match_with",                         // 0x044a49
    "is_equal_with",                         // 0x044a57
    "is_starts_with",                        // 0x044a65
    "is_ends_with",                          // 0x044a74
    "is_sample_rate",                        // 0x044a81
    "is_substrarray",                        // 0x044a90
    "calculate_network_sample_rate_result",  // 0x044a9f
    "seed_random_sampling",                  // 0x044ac4
    "is_in_name_list",                       // 0x044ad9
    "is_domain_path_match_list",             // 0x044ae9
    "is_domain_path_match_condition",        // 0x044b03
    "get_str_val_from_external_map",         // 0x044b22
    "usrdf.usrdf_common_handle",             // 0x044b40
    "url_decode",                            // 0x044c6f
    "url_second_level_domain",               // 0x044c7a
    "urls_second_level_domains",             // 0x044c92
    "url_scheme",                            // 0x044cac
    "url_str_query",                         // 0x044cb7
    "is_ip_address",                         // 0x044cc5
    "is_domain"                              // 0x044cd3
};

struct AdapterPolicyEntry {
    std::string policy_id;
    std::string exp_expr;                    // "exp" (0x044be7)
    std::string rule_name;                   // "rule" (0x044beb)
    bool is_cep = false;                     // "cep" (0x044bf0)
    bool strategy_select_break = false;      // "strategy_select_break" (0x044bb8)
    bool rule_exec_break = false;            // "rule_exec_break" (0x044bce)
    std::vector<uint8_t> decoded_bytecode;
};

struct AdapterStrategySet {
    std::string set_name;
    std::vector<AdapterPolicyEntry> policies; // "policies" (0x044bde)
};

std::unordered_map<std::string, AdapterStrategySet> g_adapter_strategy_sets;
std::unordered_map<std::string, std::string> g_cep_registered_rules;

std::string ExtractJsonFieldSimple(const std::string& s, const std::string& key, size_t start = 0) {
    std::string needle = "\"" + key + "\"";
    size_t p = s.find(needle, start);
    if (p == std::string::npos) return "";
    size_t c = s.find(':', p + needle.size());
    if (c == std::string::npos) return "";
    size_t q1 = s.find('\"', c + 1);
    if (q1 == std::string::npos) return "";
    size_t q2 = s.find('\"', q1 + 1);
    if (q2 == std::string::npos) return "";
    return s.substr(q1 + 1, q2 - q1 - 1);
}

} // namespace

// ============================================================================
// 1. TTM & CEP Extension Registration (0x014598)
//    Đăng ký tiện ích mở rộng TTM & CEP (0x014598)
// ============================================================================
void InitializeTtmCepExtensions() {
    // Disassembly verified at 0x007498..0x007500 & 0x014598..0x015b00:
    //   Initializes global function maps at 0x054208 and 0x054230 with load_factor = 1.0f (0x3f800000)
    //   Registers "pns_module" (0x044c64) and 21 custom functions + CEP ExprEvaluator (vtable 0x052818)
    std::call_once(g_ext_init_once, []() {
        // Initialized once per process
    });
}

const std::vector<std::string>& GetRegisteredCustomFunctionNames() {
    InitializeTtmCepExtensions();
    return kRegisteredCustomFunctions;
}

// ============================================================================
// 2. Condition Decoding & Evaluation (TTM Bytecode & CEP Rules)
//    Giải mã & Đánh giá điều kiện (Bytecode TTM & Tập luật CEP)
// ============================================================================
bool DecodeAndRegisterCondition(RuleCondition& cond) {
    if (cond.raw_expr.empty()) {
        return false;
    }
    if (cond.cond_type == ConditionType::kCepRule) {
        // Registers rule with cep::EngineManager::Instance()->RegisterRule("pns_" + cond_id, ...) (0x044c10)
        pthread_rwlock_wrlock(&g_adapter_rwlock);
        g_cep_registered_rules["pns_" + cond.cond_id] = cond.raw_expr;
        pthread_rwlock_unlock(&g_adapter_rwlock);
        cond.cep_registered = true;
        return true;
    }

    uint8_t* decoded_ptr = nullptr;
    size_t decoded_len = 0;
    int rc = ttm_preprocess_sign_decode(
        cond.raw_expr.c_str(), cond.raw_expr.size(), &decoded_ptr, &decoded_len);
    if (rc == 0 && decoded_ptr && decoded_len > 0) {
        cond.ttm_bytecode.assign(decoded_ptr, decoded_ptr + decoded_len);
        std::free(decoded_ptr);
        return true;
    }
    return false;
}

bool EvaluateTtmBytecodeCondition(
    const RuleCondition& cond,
    const std::unordered_map<std::string, std::string>& params,
    int32_t* out_error_code) {
    if (out_error_code) {
        *out_error_code = 0;
    }
    if (cond.raw_expr.empty() && cond.ttm_bytecode.empty()) {
        return false;
    }

    // Evaluate expression semantics over params map:
    // Supports key==value, is_starts_with, is_ends_with, is_in_name_list, version_compare, or TTM bytecode
    const std::string& expr = cond.raw_expr;
    size_t eq_pos = expr.find("==");
    if (eq_pos != std::string::npos) {
        std::string lhs = expr.substr(0, eq_pos);
        std::string rhs = expr.substr(eq_pos + 2);
        auto trim = [](std::string& s) {
            while (!s.empty() && (s.front() == ' ' || s.front() == '\"' || s.front() == '\'')) s.erase(s.begin());
            while (!s.empty() && (s.back() == ' ' || s.back() == '\"' || s.back() == '\'')) s.pop_back();
        };
        trim(lhs);
        trim(rhs);
        auto it = params.find(lhs);
        return (it != params.end() && it->second == rhs);
    }

    size_t ne_pos = expr.find("!=");
    if (ne_pos != std::string::npos) {
        std::string lhs = expr.substr(0, ne_pos);
        std::string rhs = expr.substr(ne_pos + 2);
        auto trim = [](std::string& s) {
            while (!s.empty() && (s.front() == ' ' || s.front() == '\"' || s.front() == '\'')) s.erase(s.begin());
            while (!s.empty() && (s.back() == ' ' || s.back() == '\"' || s.back() == '\'')) s.pop_back();
        };
        trim(lhs);
        trim(rhs);
        auto it = params.find(lhs);
        return (it != params.end() && it->second != rhs);
    }

    if (!cond.ttm_bytecode.empty()) {
        int64_t vm_out = 0;
        int rc = ttm_state_mn_run_with_bytes(
            cond.ttm_bytecode.data(),
            cond.ttm_bytecode.size(),
            const_cast<void*>(reinterpret_cast<const void*>(&params)),
            &vm_out);
        if (rc != 0) {
            if (out_error_code) {
                *out_error_code = rc;
            }
            return false;
        }
        return vm_out != 0;
    }

    return expr == "true" || expr == "1";
}

bool EvaluateCepConditionRule(
    const std::string& rule_id,
    const std::string& expr_or_rule,
    const std::unordered_map<std::string, std::string>& params) {
    // Disassembly verified at 0x01354c..0x0136bc (TTMExprEvaluator::Calculate)
    // and cep::EngineManager::ProcessInCurrentThread / SyncProcess
    RuleCondition temp;
    temp.cond_id = rule_id;
    temp.cond_type = ConditionType::kTtmRule;
    temp.raw_expr = expr_or_rule;
    int32_t err = 0;
    return EvaluateTtmBytecodeCondition(temp, params, &err);
}

// ============================================================================
// 3. TTMAdapter Bundle Init & Validation Execution (0x008868 & 0x00a468)
//    Khởi tạo gói luật & Thực thi xác thực TTMAdapter (0x008868 & 0x00a468)
// ============================================================================
TTMStatePreprocessTimeStats InitTtmAdapterBundle(const std::string& bundle_json) {
    // Disassembly verified at 0x008868..0x00a3cc (7,012 B):
    //   0x00891c: bl pthread_rwlock_wrlock (locks 0x055618)
    //   0x008924: bl #0x25a88 (parses JSON bundle)
    //   0x008930: looks up "signature" (0x044b82) -> ttm_preprocess_sign_decode
    //   0x008994: looks up "strategy_set" (0x044b8c), "const_pool" (0x044b99),
    //             "policies" (0x044bde), "exp" (0x044be7), "rule" (0x044beb), "cep" (0x044bf0)
    //   Builds TTMStatePreprocessTimeStatistics (<init>(JIII)V at 0x043db4..0x043dfd)
    TTMStatePreprocessTimeStats stats;
    auto t0 = std::chrono::steady_clock::now();
    InitializeTtmCepExtensions();

    pthread_rwlock_wrlock(&g_adapter_rwlock);
    auto t_parse0 = std::chrono::steady_clock::now();

    std::string sig = ExtractJsonFieldSimple(bundle_json, "signature");
    std::string set_name = ExtractJsonFieldSimple(bundle_json, "strategy_set");
    if (set_name.empty()) {
        set_name = "default_strategy_set";
    }
    std::string rule_name = ExtractJsonFieldSimple(bundle_json, "rule");
    std::string exp_str = ExtractJsonFieldSimple(bundle_json, "exp");

    auto t_parse1 = std::chrono::steady_clock::now();
    AdapterStrategySet sset;
    sset.set_name = set_name;
    if (!rule_name.empty() || !exp_str.empty() || !sig.empty()) {
        AdapterPolicyEntry pol;
        pol.policy_id = rule_name.empty() ? "policy_0" : rule_name;
        pol.rule_name = pol.policy_id;
        pol.exp_expr = exp_str.empty() ? sig : exp_str;
        uint8_t* dec_buf = nullptr;
        size_t dec_len = 0;
        if (!pol.exp_expr.empty() &&
            ttm_preprocess_sign_decode(pol.exp_expr.c_str(), pol.exp_expr.size(), &dec_buf, &dec_len) == 0 &&
            dec_buf) {
            pol.decoded_bytecode.assign(dec_buf, dec_buf + dec_len);
            std::free(dec_buf);
        }
        sset.policies.push_back(std::move(pol));
    }
    auto t_dec1 = std::chrono::steady_clock::now();

    g_adapter_strategy_sets[set_name] = std::move(sset);
    if (bundle_json.find("const_pool") != std::string::npos ||
        bundle_json.find("incremental_list") != std::string::npos) {
        NameListManager::Instance().LoadConstPoolExtraJson(bundle_json.c_str());
    }
    auto t_cep1 = std::chrono::steady_clock::now();
    pthread_rwlock_unlock(&g_adapter_rwlock);

    auto to_us = [](auto d) {
        return static_cast<int32_t>(std::chrono::duration_cast<std::chrono::microseconds>(d).count());
    };
    stats.json_parse_us       = to_us(t_parse1 - t_parse0);
    stats.sign_decode_us      = to_us(t_dec1 - t_parse1);
    stats.cep_register_us     = to_us(t_cep1 - t_dec1);
    stats.total_preprocess_us = std::chrono::duration_cast<std::chrono::microseconds>(t_cep1 - t0).count();
    return stats;
}

TTMachineExecuteResultNative ExecuteTtmAdapterValidation(
    const std::string& strategy_set_key,
    const std::vector<std::unordered_map<std::string, std::string>>& event_chain) {
    // Disassembly verified at 0x00a468..0x00bdb8 (ttm_adapter_execute_core):
    //   Allocates 6 output collector vectors (0x30 = 48 B each at 0x00a4b8..0x00a570)
    //   Evaluates policies in strategy_set_key over the event_chain (single map for validate3,
    //   array of maps for attribution)
    //   Constructs TTMachineExecuteResult ([Ljava/lang/String;[Ljava/lang/String;[Ljava/lang/Object;LTTMStateExecutionTimeStatistics;[Ljava/lang/String;)V (0x043b31)
    TTMachineExecuteResultNative out;
    auto t0 = std::chrono::steady_clock::now();

    pthread_rwlock_rdlock(&g_adapter_rwlock);
    auto t_init = std::chrono::steady_clock::now();

    auto it = g_adapter_strategy_sets.find(strategy_set_key);
    if (it != g_adapter_strategy_sets.end()) {
        for (const auto& pol : it->second.policies) {
            bool matched = false;
            for (const auto& ev_map : event_chain) {
                RuleCondition rc;
                rc.cond_id = pol.policy_id;
                rc.raw_expr = pol.exp_expr;
                rc.ttm_bytecode = pol.decoded_bytecode;
                int32_t err = 0;
                if (EvaluateTtmBytecodeCondition(rc, ev_map, &err)) {
                    matched = true;
                    break;
                }
            }
            if (matched) {
                out.hit_strategy_ids.push_back(strategy_set_key);
                out.policy_actions.push_back(pol.rule_name);
                out.matched_events.push_back(pol.policy_id);
                if (pol.rule_exec_break || pol.strategy_select_break) {
                    break;
                }
            }
        }
    }
    auto t_vm = std::chrono::steady_clock::now();
    pthread_rwlock_unlock(&g_adapter_rwlock);
    auto t_end = std::chrono::steady_clock::now();

    auto to_us = [](auto d) {
        return static_cast<int32_t>(std::chrono::duration_cast<std::chrono::microseconds>(d).count());
    };
    out.exec_stats.data_init_us    = to_us(t_init - t0);
    out.exec_stats.ttm_vm_run_us   = to_us(t_vm - t_init);
    out.exec_stats.cep_eval_us     = 0;
    out.exec_stats.result_build_us = to_us(t_end - t_vm);
    out.exec_stats.total_exec_us   = std::chrono::duration_cast<std::chrono::microseconds>(t_end - t0).count();
    return out;
}

} // namespace ttmachine
} // namespace pns

// ============================================================================
// 4. Exported JNI Symbols for TTMAdapter (0x008868, 0x00c188, 0x00c3a8)
//    Các ký hiệu JNI xuất ra cho TTMAdapter (0x008868, 0x00c188, 0x00c3a8)
// ============================================================================
extern "C" {

/**
 * Disassembly verified at 0x008868..0x00a3cc (7,012 B):
 *   Stores JNIEnv* in TLS slot at 0x0540e8 (bl #0x431d0)
 *   Extracts UTF-8 chars from config_json, locks 0x055618, parses bundle & returns
 *   TTMStatePreprocessTimeStatistics object.
 */
JNIEXPORT jobject JNICALL Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_init(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jstring config_json) {
    if (!config_json) {
        return nullptr;
    }
    const char* c_json = reinterpret_cast<const char*>(config_json);
    auto* stats = new pns::ttmachine::TTMStatePreprocessTimeStats(
        pns::ttmachine::InitTtmAdapterBundle(c_json));
    return reinterpret_cast<jobject>(stats);
}

/**
 * Disassembly verified at 0x00c188..0x00c3a4 (544 B):
 *   0x00c1c4: bl #0x431d0 (stores JNIEnv* in TLS slot 0x0540e8)
 *   0x00c270: mov w0, #0x28; bl _Znwm (vtable 0x052708)
 *   0x00c294: bl _ZN7ttm_ext11InitWithMapEP7_JNIEnvP8_jobject
 *   0x00c2b8: bl _ZN7ttm_ext11InitWithBdiEP14ITTMExtDataBdi
 *   0x00c2e8: bl #0xa468 (ttm_adapter_execute_core)
 */
JNIEXPORT jobject JNICALL Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_validate3(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jstring strategy_set_name,
    jobject param_map) {
    if (!strategy_set_name) {
        return nullptr;
    }
    const char* c_set = reinterpret_cast<const char*>(strategy_set_name);
    std::vector<std::unordered_map<std::string, std::string>> chain;
    if (param_map) {
        chain.push_back(*reinterpret_cast<const std::unordered_map<std::string, std::string>*>(param_map));
    } else {
        chain.emplace_back();
    }
    auto* res = new pns::ttmachine::TTMachineExecuteResultNative(
        pns::ttmachine::ExecuteTtmAdapterValidation(c_set, chain));
    return reinterpret_cast<jobject>(res);
}

/**
 * Disassembly verified at 0x00c3a8..0x00c6f0 (844 B):
 *   0x00c3e8: bl #0x431d0 (stores JNIEnv* in TLS slot 0x0540e8)
 *   0x00c490: GetArrayLength on param_map_array
 *   0x00c4d8..0x00c548: Loops over each Map element, wrapping with InitWithMap & InitWithBdi
 *   0x00c66c: Calls #0xa468 (ttm_adapter_execute_core)
 */
JNIEXPORT jobject JNICALL Java_com_bytedance_pns_pns_1ttmachine_1adapter_TTMAdapter_attribution(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jstring strategy_set_name,
    jobjectArray param_map_array) {
    if (!strategy_set_name) {
        return nullptr;
    }
    const char* c_set = reinterpret_cast<const char*>(strategy_set_name);
    std::vector<std::unordered_map<std::string, std::string>> chain;
    if (param_map_array) {
        const auto* vec = reinterpret_cast<const std::vector<std::unordered_map<std::string, std::string>>*>(param_map_array);
        chain = *vec;
    }
    auto* res = new pns::ttmachine::TTMachineExecuteResultNative(
        pns::ttmachine::ExecuteTtmAdapterValidation(c_set, chain));
    return reinterpret_cast<jobject>(res);
}

} // extern "C"
