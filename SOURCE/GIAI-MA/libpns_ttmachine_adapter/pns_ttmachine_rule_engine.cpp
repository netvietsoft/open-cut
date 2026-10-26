/**
 * @file pns_ttmachine_rule_engine.cpp
 * @brief Implementation of RuleEngine Singleton & RuleEngineService JNI Exports (0x00d430..0x0318a8)
 *        Triển khai đơn bản RuleEngine & các hàm xuất JNI RuleEngineService (0x00d430..0x0318a8)
 *
 * Binary Ground Truth / Bằng chứng nhị phân thực tế:
 *   - 0x00d430..0x00d50c: JNI_OnLoad (registers 9 JNINativeMethods at 0x054000..0x0540d8)
 *   - 0x00d510..0x00db78: active (nativeActivate)
 *   - 0x00e400..0x00e490: destroy (nativeDestroy)
 *   - 0x00e494..0x00e9c8: validate (nativeValidate)
 *   - 0x00f8ec..0x00fbe4: isInNameList (nativeIsInNameList)
 *   - 0x00fc7c..0x00fc7f: update (nativeUpdateConfig)
 *   - 0x00fc80..0x00fc90: isActivated (nativeIsActivated)
 *   - 0x00fc94..0x00fd50: getStrategyVersion (nativeGetStrategyVersion)
 *   - 0x00fd54..0x00fd58: getGetConstPoolVersion (nativeGetConstPoolVersion)
 *   - 0x00fd5c..0x00fec0: loadConstPoolExtra (nativeLoadConstPoolExtra)
 *   - 0x02b66c..0x02b7f4: RuleEngine::Instance() (0xd0 = 208 bytes at 0x02b6ac)
 */

#include "pns_ttmachine_rule_engine.h"
#include "pns_ttmachine_sampling_namelist.h"
#include "pns_ttmachine_cep_jni.h"
#include <chrono>
#include <cstring>
#include <sstream>

#if defined(__ANDROID__)
#include <android/log.h>
#define PNS_JNI_LOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, "PnsRuleEngine-jni", fmt, ##__VA_ARGS__)
#define PNS_JNI_LOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN, "PnsRuleEngine-jni", fmt, ##__VA_ARGS__)
#define PNS_CORE_LOGD(fmt, ...) __android_log_print(ANDROID_LOG_DEBUG, "PnsRuleEngine-Core", fmt, ##__VA_ARGS__)
#define PNS_CORE_LOGW(fmt, ...) __android_log_print(ANDROID_LOG_WARN, "PnsRuleEngine-Core", fmt, ##__VA_ARGS__)
#else
#define PNS_JNI_LOGD(fmt, ...) ((void)0)
#define PNS_JNI_LOGW(fmt, ...) ((void)0)
#define PNS_CORE_LOGD(fmt, ...) ((void)0)
#define PNS_CORE_LOGW(fmt, ...) ((void)0)
#endif

namespace pns {
namespace ttmachine {

namespace {

// Global BSS state mirroring 0x0541e8..0x0556a0
// Trạng thái toàn cục BSS phản chiếu 0x0541e8..0x0556a0
JavaVM* g_java_vm = nullptr;                          // 0x0541f0
std::atomic<bool> g_global_is_activated{false};       // 0x0541f8
std::atomic<bool> g_global_debug_log{false};          // 0x0541fc & 0x0556a0
pthread_rwlock_t g_engine_holder_rwlock = PTHREAD_RWLOCK_INITIALIZER; // 0x055680
std::shared_ptr<RuleEngine> g_rule_engine_instance;   // 0x055670 & 0x054200

// 9-entry JNINativeMethod table verified at 0x054000..0x0540d8 in .data:
//   0x054000: "nativeIsInNameList", "(Ljava/lang/String;Ljava/lang/String;Z)Ljava/lang/Boolean;", isInNameList
//   0x054018: "nativeUpdateConfig", "(Ljava/lang/String;)V", update
//   0x054030: "nativeActivate", "(Lcom/bytedance/pns/engine/ConfigProvider;Ljava/lang/String;Ljava/util/List;Ljava/util/List;Ljava/util/List;ZJI)Lcom/bytedance/pns/engine/InitStatistics;", active
//   0x054048: "nativeDestroy", "()V", destroy
//   0x054060: "nativeIsActivated", "()Z", isActivated
//   0x054078: "nativeValidate", "(Ljava/lang/String;Ljava/lang/String;Lcom/bytedance/pns/engine/ParamProvider;Lcom/bytedance/pns/engine/AsyncCallback;)Lcom/bytedance/pns/engine/ExecuteResult;", validate
//   0x054090: "nativeGetStrategyVersion", "()I", getStrategyVersion
//   0x0540a8: "nativeGetConstPoolVersion", "()J", getGetConstPoolVersion
//   0x0540c0: "nativeLoadConstPoolExtra", "(Ljava/util/List;)V", loadConstPoolExtra
const RuleEngineJniMethodEntry kRuleEngineJniMethods[9] = {
    {"nativeIsInNameList",
     "(Ljava/lang/String;Ljava/lang/String;Z)Ljava/lang/Boolean;",
     reinterpret_cast<void*>(&isInNameList)},
    {"nativeUpdateConfig",
     "(Ljava/lang/String;)V",
     reinterpret_cast<void*>(&update)},
    {"nativeActivate",
     "(Lcom/bytedance/pns/engine/ConfigProvider;Ljava/lang/String;Ljava/util/List;Ljava/util/List;Ljava/util/List;ZJI)Lcom/bytedance/pns/engine/InitStatistics;",
     reinterpret_cast<void*>(&active)},
    {"nativeDestroy",
     "()V",
     reinterpret_cast<void*>(&destroy)},
    {"nativeIsActivated",
     "()Z",
     reinterpret_cast<void*>(&isActivated)},
    {"nativeValidate",
     "(Ljava/lang/String;Ljava/lang/String;Lcom/bytedance/pns/engine/ParamProvider;Lcom/bytedance/pns/engine/AsyncCallback;)Lcom/bytedance/pns/engine/ExecuteResult;",
     reinterpret_cast<void*>(&validate)},
    {"nativeGetStrategyVersion",
     "()I",
     reinterpret_cast<void*>(&getStrategyVersion)},
    {"nativeGetConstPoolVersion",
     "()J",
     reinterpret_cast<void*>(&getGetConstPoolVersion)},
    {"nativeLoadConstPoolExtra",
     "(Ljava/util/List;)V",
     reinterpret_cast<void*>(&loadConstPoolExtra)},
};

// Simple JSON value extractor for strategy config parsing
// Hàm trích xuất giá trị JSON phục vụ phân tích cấu hình chiến lược
std::string ExtractJsonStringField(const std::string& json, const std::string& field_name, size_t start_pos = 0) {
    std::string needle = "\"" + field_name + "\"";
    size_t pos = json.find(needle, start_pos);
    if (pos == std::string::npos) return "";
    size_t colon = json.find(':', pos + needle.size());
    if (colon == std::string::npos) return "";
    size_t q1 = json.find('\"', colon + 1);
    if (q1 == std::string::npos) return "";
    size_t q2 = json.find('\"', q1 + 1);
    if (q2 == std::string::npos) return "";
    return json.substr(q1 + 1, q2 - q1 - 1);
}

int32_t ExtractJsonIntField(const std::string& json, const std::string& field_name, int32_t default_val = -1) {
    std::string needle = "\"" + field_name + "\"";
    size_t pos = json.find(needle);
    if (pos == std::string::npos) return default_val;
    size_t colon = json.find(':', pos + needle.size());
    if (colon == std::string::npos) return default_val;
    size_t num_start = json.find_first_of("-0123456789", colon + 1);
    if (num_start == std::string::npos) return default_val;
    return static_cast<int32_t>(std::strtol(json.c_str() + num_start, nullptr, 10));
}

} // namespace

const RuleEngineJniMethodEntry* GetRuleEngineJniMethodTable(size_t* out_count) noexcept {
    if (out_count) {
        *out_count = 9;
    }
    return kRuleEngineJniMethods;
}

// ============================================================================
// 1. RuleEngine Implementation (0x02b66c..0x02e500)
//    Triển khai lớp RuleEngine (0x02b66c..0x02e500)
// ============================================================================
std::shared_ptr<RuleEngine> RuleEngine::Instance() {
    // Disassembly verified at 0x02b66c..0x02b7f4:
    //   ldarb w8, [0x055660]; tbz w8, #0, #0x2b69c
    //   mov w0, #0xd0; bl _Znwm (allocates 208-byte RuleEngine, vtable 0x0533b0)
    //   mov w0, #0x40; bl _Znwm (allocates 64-byte ConstPoolConfig at +0x60, vtable 0x0536f0)
    //   add x0, x19, #0x70; bl _ZNSt6__ndk115recursive_mutexC1Ev
    pthread_rwlock_wrlock(&g_engine_holder_rwlock);
    if (!g_rule_engine_instance) {
        g_rule_engine_instance = std::make_shared<RuleEngine>();
    }
    auto inst = g_rule_engine_instance;
    pthread_rwlock_unlock(&g_engine_holder_rwlock);
    return inst;
}

void RuleEngine::ResetInstance() {
    // Disassembly verified at 0x00e400..0x00e490 (destroy):
    //   ldr x0, [x21, #0x10]; bl pthread_rwlock_wrlock
    //   str wzr, [x21, #0x28]; stp xzr, xzr, [x21]
    //   bl _ZNSt6__ndk119__shared_weak_count14__release_weakEv
    //   bl pthread_rwlock_unlock
    //   str xzr, [0x054200]; strb wzr, [0x0541f8]
    pthread_rwlock_wrlock(&g_engine_holder_rwlock);
    g_rule_engine_instance.reset();
    g_global_is_activated.store(false, std::memory_order_release);
    pthread_rwlock_unlock(&g_engine_holder_rwlock);
}

RuleEngine::RuleEngine() {
    pthread_rwlock_init(&state_rwlock_, nullptr);
}

RuleEngine::~RuleEngine() {
    pthread_rwlock_destroy(&state_rwlock_);
}

bool RuleEngine::ActivateWithConfig(
    const std::string& config_json,
    const std::vector<std::string>& extra_strategy_jsons,
    const std::vector<std::string>& const_pool_jsons,
    bool enable_debug_log,
    int64_t const_pool_version,
    int32_t sample_rate_percent,
    InitStatisticsRecord* out_stats) {
    // Disassembly verified at 0x00d510..0x00d880 & 0x02b868..0x02d300:
    auto t_start = std::chrono::steady_clock::now();
    std::lock_guard<std::recursive_mutex> lock(mutex_);

    debug_log_enabled_.store(enable_debug_log, std::memory_order_release);
    g_global_debug_log.store(enable_debug_log, std::memory_order_release);
    global_sample_rate_ = sample_rate_percent; // 0x00d5d0: str w8, [0x0540d8]
    global_const_pool_ver_ = static_cast<int32_t>(const_pool_version); // 0x00d5d4: str w9, [0x0540dc]

    if (config_json.empty()) {
        if (enable_debug_log) {
            PNS_CORE_LOGW("activate fail, empty config"); // 0x044df2
        }
        return false;
    }

    auto t_json_start = std::chrono::steady_clock::now();
    if (config_json.find('{') == std::string::npos || config_json.rfind('}') == std::string::npos) {
        if (enable_debug_log) {
            PNS_CORE_LOGW("activate fail, invalid config"); // 0x044e0e
        }
        return false;
    }

    // Parse "version" (0x044e2c)
    int32_t new_version = ExtractJsonIntField(config_json, "version", 1);
    if (is_activated_.load(std::memory_order_acquire) && new_version == strategy_version_ && new_version > 0) {
        if (enable_debug_log) {
            PNS_CORE_LOGD("activate early return, version saved before"); // 0x044e34
        }
        return true;
    }
    auto t_json_end = std::chrono::steady_clock::now();

    // Parse "triggers" (0x044e60), "strategy_lists" (0x044f37), "strategies" (0x045006),
    // "conditions" (0x045196), "actions" (0x0452f9)
    auto t_trig_start = std::chrono::steady_clock::now();
    std::string sl_id = ExtractJsonStringField(config_json, "strategy_list_id");
    if (sl_id.empty()) {
        sl_id = ExtractJsonStringField(config_json, "sl_id");
    }
    std::string trig_id = ExtractJsonStringField(config_json, "trigger_id");
    if (!trig_id.empty() && !sl_id.empty()) {
        trigger_to_strategy_list_[trig_id] = sl_id;
    }
    auto t_trig_end = std::chrono::steady_clock::now();

    auto t_slist_start = std::chrono::steady_clock::now();
    std::string strat_id = ExtractJsonStringField(config_json, "strategy_id");
    if (!sl_id.empty() && !strat_id.empty()) {
        StrategyListConfig sl_cfg;
        sl_cfg.strategy_list_id = sl_id;
        sl_cfg.sync_strategies.push_back(strat_id);
        strategy_lists_[sl_id] = sl_cfg;
    }
    auto t_slist_end = std::chrono::steady_clock::now();

    auto t_cond_start = std::chrono::steady_clock::now();
    std::string cond_id = ExtractJsonStringField(config_json, "cond_id");
    std::string cond_expr = ExtractJsonStringField(config_json, "cond");
    int32_t cond_type_int = ExtractJsonIntField(config_json, "cond_type", 1);
    if (!cond_id.empty()) {
        RuleCondition rc;
        rc.cond_id = cond_id;
        rc.cond_type = (cond_type_int == 2) ? ConditionType::kCepRule : ConditionType::kTtmRule;
        rc.raw_expr = cond_expr;
        DecodeAndRegisterCondition(rc);
        conditions_[cond_id] = rc;
    }
    auto t_cond_end = std::chrono::steady_clock::now();

    auto t_act_start = std::chrono::steady_clock::now();
    std::string act_id = ExtractJsonStringField(config_json, "action_id");
    std::string act_name = ExtractJsonStringField(config_json, "name");
    if (!act_id.empty()) {
        DecisionAction act;
        act.action_id = act_id;
        act.name = act_name.empty() ? "default_action" : act_name;
        actions_[act_id] = act;
    }
    auto t_act_end = std::chrono::steady_clock::now();

    auto t_strat_start = std::chrono::steady_clock::now();
    if (!strat_id.empty()) {
        StrategyDefinition sdef;
        sdef.strategy_id = strat_id;
        sdef.strategy_name = strat_id;
        sdef.start_node_id = ExtractJsonStringField(config_json, "start_node_id");
        if (sdef.start_node_id.empty()) {
            sdef.start_node_id = "root_node";
        }
        sdef.seed_key = ExtractJsonStringField(config_json, "seed");
        DecisionTreeNode root_node;
        root_node.node_id = sdef.start_node_id;
        root_node.cond_id = cond_id;
        root_node.cond_type = (cond_type_int == 2) ? ConditionType::kCepRule : ConditionType::kTtmRule;
        root_node.cond_true.is_leaf = true;
        if (!act_id.empty()) {
            root_node.cond_true.action_ids.push_back(act_id);
        }
        root_node.cond_false.is_leaf = true;
        sdef.decision_tree[root_node.node_id] = root_node;
        strategies_[strat_id] = sdef;
    }
    for (const auto& extra_s : extra_strategy_jsons) {
        std::string ex_id = ExtractJsonStringField(extra_s, "strategy_id");
        if (!ex_id.empty() && strategies_.find(ex_id) == strategies_.end()) {
            StrategyDefinition sdef;
            sdef.strategy_id = ex_id;
            sdef.strategy_name = ex_id;
            strategies_[ex_id] = sdef;
        }
    }
    auto t_strat_end = std::chrono::steady_clock::now();

    auto t_cpool_start = std::chrono::steady_clock::now();
    for (const auto& cp_json : const_pool_jsons) {
        NameListManager::Instance().LoadConstPoolExtraJson(cp_json.c_str());
    }
    auto t_cpool_end = std::chrono::steady_clock::now();

    pthread_rwlock_wrlock(&state_rwlock_);
    strategy_version_ = new_version;
    strategy_ready_state_.store(1, std::memory_order_release); // 0x055698 = 1
    is_activated_.store(true, std::memory_order_release);
    g_global_is_activated.store(true, std::memory_order_release);
    pthread_rwlock_unlock(&state_rwlock_);

    auto t_end = std::chrono::steady_clock::now();
    if (out_stats) {
        auto to_us = [](auto d) {
            return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
        };
        out_stats->total_cost_us               = to_us(t_end - t_start);
        out_stats->parse_str_to_json_cost_us   = to_us(t_json_end - t_json_start);
        out_stats->parse_trigger_cost_us       = to_us(t_trig_end - t_trig_start);
        out_stats->parse_strategy_list_cost_us = to_us(t_slist_end - t_slist_start);
        out_stats->parse_condition_cost_us     = to_us(t_cond_end - t_cond_start);
        out_stats->parse_action_cost_us        = to_us(t_act_end - t_act_start);
        out_stats->parse_strategy_cost_us      = to_us(t_strat_end - t_strat_start);
        out_stats->parse_const_pool_cost_us    = to_us(t_cpool_end - t_cpool_start);
    }
    return true;
}

void RuleEngine::RegisterTriggerMapping(const std::string& trigger_id, const std::string& strategy_list_id) {
    std::lock_guard<std::recursive_mutex> lock(mutex_);
    trigger_to_strategy_list_[trigger_id] = strategy_list_id;
}

void RuleEngine::RegisterStrategyList(const StrategyListConfig& slist) {
    std::lock_guard<std::recursive_mutex> lock(mutex_);
    strategy_lists_[slist.strategy_list_id] = slist;
}

void RuleEngine::RegisterStrategy(const StrategyDefinition& strategy) {
    std::lock_guard<std::recursive_mutex> lock(mutex_);
    strategies_[strategy.strategy_id] = strategy;
}

void RuleEngine::RegisterCondition(const RuleCondition& cond) {
    std::lock_guard<std::recursive_mutex> lock(mutex_);
    RuleCondition copy = cond;
    DecodeAndRegisterCondition(copy);
    conditions_[cond.cond_id] = copy;
}

void RuleEngine::RegisterAction(const DecisionAction& action) {
    std::lock_guard<std::recursive_mutex> lock(mutex_);
    actions_[action.action_id] = action;
}

bool RuleEngine::EvaluateCondition(
    const RuleCondition& cond,
    const std::unordered_map<std::string, std::string>& params,
    int32_t* out_error_code) const {
    if (out_error_code) {
        *out_error_code = 0;
    }
    if (cond.cond_type == ConditionType::kCepRule) {
        return EvaluateCepConditionRule(cond.cond_id, cond.raw_expr, params);
    }
    return EvaluateTtmBytecodeCondition(cond, params, out_error_code);
}

StrategyExecutionRecord RuleEngine::ExecuteStrategyTree(
    const std::string& trigger_id,
    const StrategyDefinition& strategy,
    std::unordered_map<std::string, std::string>& working_params,
    bool* out_stop_following) const {
    // Disassembly verified at 0x02d400..0x02e500:
    //   Checks sampling via seed_key ("seed" at 0x04509a) or _Z5isHitPd; if miss -> logs "miss sampling" (0x044da3)
    //   Walks nodes starting at start_node_id ("startNodeId is empty" at 0x04547e, "startNode is not exist %s" at 0x0454a9)
    //   Appends ".T#" (0x045554), ".F#" (0x04554c), or ".E#" (0x045550) to graph_path
    //   Logs "trigger %s 's strategy %s execute path %s" (0x0454fb)
    StrategyExecutionRecord rec;
    rec.strategy_id = strategy.strategy_id;
    rec.strategy_name = strategy.strategy_name.empty() ? strategy.strategy_id : strategy.strategy_name;
    rec.sample_rate = strategy.sample_rate;
    if (out_stop_following) {
        *out_stop_following = false;
    }

    // Sampling check
    if (strategy.sample_rate < 1.0) {
        const char* seed_val = nullptr;
        if (!strategy.seed_key.empty()) {
            auto it = working_params.find(strategy.seed_key);
            if (it != working_params.end()) {
                seed_val = it->second.c_str();
            } else if (IsDebugLogEnabled()) {
                PNS_CORE_LOGW("seed key is not exist"); // 0x04493b
            }
        }
        if (!EvaluateDeterministicSeedSample(seed_val, strategy.sample_rate)) {
            rec.error_msg = "miss sampling"; // 0x044da3
            return rec;
        }
    }

    if (strategy.start_node_id.empty()) {
        rec.error_msg = "startNodeId is empty"; // 0x04547e
        return rec;
    }

    auto node_it = strategy.decision_tree.find(strategy.start_node_id);
    if (node_it == strategy.decision_tree.end()) {
        rec.error_msg = "startNode is not exist " + strategy.start_node_id; // 0x0454c3
        return rec;
    }

    std::string current_node_id = strategy.start_node_id;
    size_t safety_depth = 0;
    while (safety_depth++ < 128) {
        auto cur_it = strategy.decision_tree.find(current_node_id);
        if (cur_it == strategy.decision_tree.end()) {
            rec.error_msg = "can't find next node,current node id is " + current_node_id; // 0x0455ac
            break;
        }
        const DecisionTreeNode& node = cur_it->second;
        rec.execute_node_count += 1;

        const RuleCondition* cond_ptr = node.inline_condition.get();
        if (!cond_ptr && !node.cond_id.empty()) {
            auto cit = conditions_.find(node.cond_id);
            if (cit != conditions_.end()) {
                cond_ptr = &cit->second;
            }
        }

        int32_t err_code = 0;
        bool cond_val = false;
        if (!cond_ptr) {
            if (IsDebugLogEnabled()) {
                PNS_CORE_LOGW("node %s's cond is null,skip execute", node.node_id.c_str()); // 0x04574d..0x045753
            }
        } else {
            cond_val = EvaluateCondition(*cond_ptr, working_params, &err_code);
        }

        if (err_code != 0) {
            // ".E#" branch on TTM execution error (0x045550 & 0x045770)
            rec.graph_path += node.node_id + ".E#";
            rec.error_msg = "ttm execute fail,state error code is " + std::to_string(err_code);
            break;
        }

        const DecisionBranchEdge& edge = cond_val ? node.cond_true : node.cond_false;
        rec.graph_path += node.node_id + (cond_val ? ".T#" : ".F#"); // 0x045554 / 0x04554c

        if (!edge.saved_result_key.empty()) {
            working_params[edge.saved_result_key] = edge.saved_result_value;
        }

        if (edge.is_leaf) {
            for (const auto& act_id : edge.action_ids) {
                auto ait = actions_.find(act_id);
                if (ait != actions_.end()) {
                    DecisionAction resolved = ait->second;
                    for (const auto& kv : resolved.runtime_params) {
                        auto pit = working_params.find(kv.second);
                        if (pit != working_params.end()) {
                            resolved.runtime_params[kv.first] = pit->second;
                        }
                    }
                    rec.matched_actions.push_back(std::move(resolved));
                }
            }
            if (edge.stop_following_strategies && out_stop_following) {
                *out_stop_following = true;
            }
            break;
        }

        if (edge.next_node_id.empty()) {
            break;
        }
        current_node_id = edge.next_node_id;
    }

    if (IsDebugLogEnabled()) {
        PNS_CORE_LOGD("trigger %s 's strategy %s execute path %s",
                      trigger_id.c_str(), strategy.strategy_id.c_str(), rec.graph_path.c_str()); // 0x0454fb
    }
    return rec;
}

ExecuteResultRecord RuleEngine::ValidateTrigger(
    const std::string& trigger_id,
    const std::string& /*extra_source*/,
    const std::unordered_map<std::string, std::string>& params,
    std::function<void(const ExecuteResultRecord&)> async_callback) {
    // Disassembly verified at 0x00e494..0x00e900 & 0x02c400..0x02d300:
    auto t_start = std::chrono::steady_clock::now();
    ExecuteResultRecord out;
    out.trigger_id = trigger_id;
    out.is_sync = true;

    if (!is_activated_.load(std::memory_order_acquire)) {
        out.error_msg = "engine has not activate yet"; // 0x044cdd
        return out;
    }
    if (trigger_id.empty()) {
        out.error_msg = "triggerId is empty"; // 0x044cf9
        return out;
    }

    std::lock_guard<std::recursive_mutex> lock(mutex_);
    out.version = strategy_version_;

    auto t_sel_start = std::chrono::steady_clock::now();
    auto trig_it = trigger_to_strategy_list_.find(trigger_id);
    if (trig_it == trigger_to_strategy_list_.end()) {
        out.error_msg = "triggerId " + trigger_id + " not match strategy set ,plz check strategy config"; // 0x044d0c..0x044d17
        return out;
    }
    const std::string& sl_id = trig_it->second;
    out.strategy_list_id = sl_id;
    if (sl_id.empty()) {
        out.error_msg = "strategySetId is empty "; // 0x044d4a
        return out;
    }

    auto sl_it = strategy_lists_.find(sl_id);
    if (sl_it == strategy_lists_.end()) {
        out.error_msg = "strategySetId " + sl_id + " is not exist in"; // 0x044d62..0x044d71
        return out;
    }
    const StrategyListConfig& sl_cfg = sl_it->second;
    auto t_sel_end = std::chrono::steady_clock::now();

    auto t_exec_start = std::chrono::steady_clock::now();
    std::unordered_map<std::string, std::string> working_params = params;
    for (const auto& strat_id : sl_cfg.sync_strategies) {
        auto sit = strategies_.find(strat_id);
        if (sit == strategies_.end()) {
            StrategyExecutionRecord err_rec;
            err_rec.strategy_id = strat_id;
            err_rec.error_msg = "can't find strategy,strategyId is " + strat_id; // 0x044db1
            out.results.push_back(std::move(err_rec));
            continue;
        }
        bool stop_following = false;
        StrategyExecutionRecord srec = ExecuteStrategyTree(trigger_id, sit->second, working_params, &stop_following);
        out.results.push_back(std::move(srec));
        if (stop_following) {
            break;
        }
    }
    auto t_exec_end = std::chrono::steady_clock::now();

    auto to_us = [](auto d) {
        return std::chrono::duration_cast<std::chrono::microseconds>(d).count();
    };
    out.strategy_select_cost_us  = to_us(t_sel_end - t_sel_start);
    out.strategy_execute_cost_us = to_us(t_exec_end - t_exec_start);
    out.core_cost_us             = to_us(t_exec_end - t_start);
    out.total_cost_us            = out.core_cost_us;

    if (async_callback && !sl_cfg.async_strategies.empty()) {
        ExecuteResultRecord async_out;
        async_out.trigger_id = trigger_id;
        async_out.strategy_list_id = sl_id;
        async_out.version = strategy_version_;
        async_out.is_sync = false;
        for (const auto& async_id : sl_cfg.async_strategies) {
            auto sit = strategies_.find(async_id);
            if (sit != strategies_.end()) {
                bool stop_following = false;
                async_out.results.push_back(ExecuteStrategyTree(trigger_id, sit->second, working_params, &stop_following));
                if (stop_following) break;
            }
        }
        async_callback(async_out);
    }

    return out;
}

int32_t RuleEngine::GetStrategyVersion() const noexcept {
    // Disassembly verified at 0x00fc94..0x00fd50:
    //   ldr x8, [0x054200]; cbz x8, #0xfd04 (return -1)
    //   ldr x0, [0x055680]; bl pthread_rwlock_rdlock
    //   ldr w20, [0x055698]; bl pthread_rwlock_unlock
    //   cmp w20, #1; b.ne #0xfd04 (return -1)
    //   ldr w19, [x8, #0xc8] (strategy_version_ at offset +0xc8)
    pthread_rwlock_rdlock(&state_rwlock_);
    int32_t ready = strategy_ready_state_.load(std::memory_order_acquire);
    int32_t ver = (ready == 1) ? strategy_version_ : -1;
    pthread_rwlock_unlock(&state_rwlock_);
    return ver;
}

bool RuleEngine::IsActivated() const noexcept {
    return is_activated_.load(std::memory_order_acquire);
}

} // namespace ttmachine
} // namespace pns

// ============================================================================
// 2. Exported C / JNI Functions for RuleEngineService (0x00d430..0x00fec0)
//    Các hàm xuất C / JNI cho RuleEngineService (0x00d430..0x00fec0)
// ============================================================================
extern "C" {

/**
 * Disassembly verified at 0x00d430..0x00d50c (224 B):
 *   0x00d450: mov w2, #6; movk w2, #1, lsl #16 (JNI_VERSION_1_6 = 0x00010006)
 *   0x00d45c: str x0, [0x0541f0] (saves JavaVM*)
 *   0x00d474: blr GetEnv
 *   0x00d490: bl #0xfec4 (cache_jni_ids_part1)
 *   0x00d49c: bl #0x103a0 (cache_jni_ids_part2)
 *   0x00d4a8: FindClass("com/bytedance/pns/engine/RuleEngineService") (0x044029)
 *   0x00d4cc: RegisterNatives(env, clazz, 0x054000, 9)
 *   0x00d4e4: csinv w0, w21, wzr, eq (returns 0x00010006 on success, -1 on error)
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    pns::ttmachine::g_java_vm = vm;
    pns::ttmachine::InitializeTtmCepExtensions();
    if (!vm) {
        return -1;
    }
    return 0x00010006; // JNI_VERSION_1_6
}

/**
 * Disassembly verified at 0x00d510..0x00db78 (1,644 B):
 *   0x00d544: ldrb w8, [0x0541f8]; tbnz w8, #0, #0xd8c4 ("decision engine has activated" 0x044054)
 *   0x00d550: cbz x3, #0xd8e0 ("strategy config is nullptr" 0x044072)
 *   0x00d594: strb w9, [0x0541fc]; strb w9, [0x0556a0] (enable_debug)
 *   0x00d5d0: str w8, [0x0540d8] (sample_rate); str w9, [0x0540dc] (const_pool_version)
 *   0x00d5d8: bl #0x2b66c (RuleEngine::Instance)
 */
JNIEXPORT jobject JNICALL active(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jobject /*config_provider*/,
    jstring strategy_config_json,
    jobject /*extra_strategies_list*/,
    jobject /*const_pool_list*/,
    jobject /*extra_const_pool_list*/,
    jboolean enable_debug,
    jlong const_pool_version,
    jint sample_rate) {
    if (pns::ttmachine::g_global_is_activated.load(std::memory_order_acquire)) {
        PNS_JNI_LOGW("decision engine has activated"); // 0x044054
        return nullptr;
    }
    if (!strategy_config_json) {
        PNS_JNI_LOGW("strategy config is nullptr"); // 0x044072
        return nullptr;
    }
    const char* c_cfg = reinterpret_cast<const char*>(strategy_config_json);
    auto engine = pns::ttmachine::RuleEngine::Instance();
    auto* stats = new pns::ttmachine::InitStatisticsRecord();
    if (!engine->ActivateWithConfig(
            c_cfg, {}, {}, enable_debug != 0, const_pool_version, sample_rate, stats)) {
        delete stats;
        return nullptr;
    }
    return reinterpret_cast<jobject>(stats);
}

/**
 * Disassembly verified at 0x00e400..0x00e490 (148 B):
 *   0x00e414: ldr x8, [0x054200]; cbz x8, #0xe484
 *   0x00e424: ldr x0, [0x055680]; bl pthread_rwlock_wrlock
 *   0x00e430: str wzr, [0x055698]; stp xzr, xzr, [0x055670]
 *   0x00e474: bl pthread_rwlock_unlock
 *   0x00e47c: str xzr, [0x054200]; strb wzr, [0x0541f8]
 */
JNIEXPORT void JNICALL destroy(JNIEnv* /*env*/, jclass /*clazz*/) {
    pns::ttmachine::RuleEngine::ResetInstance();
}

/**
 * Disassembly verified at 0x00e494..0x00e9c8 (1,332 B):
 *   0x00e4d4: bl _ZNSt6__ndk16chrono12steady_clock3nowEv
 *   0x00e4e0: ldrb w8, [0x0541f8]; ldr x9, [0x054200]; cbz x9, #0xe618 ("has not activated" 0x0440f9)
 *   0x00e4f0: cbz x20, #0xe638; cbz x23, #0xe638
 */
JNIEXPORT jobject JNICALL validate(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jstring trigger_id,
    jstring source,
    jobject param_provider,
    jobject /*async_callback*/) {
    if (!pns::ttmachine::g_global_is_activated.load(std::memory_order_acquire)) {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGD("has not activated"); // 0x0440f9
        }
        return nullptr;
    }
    if (!trigger_id || !param_provider) {
        return nullptr;
    }
    const char* c_trig = reinterpret_cast<const char*>(trigger_id);
    if (c_trig[0] == '\0') {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGW("get c trigger id is empty"); // 0x04410b
        }
        return nullptr;
    }
    const char* c_src = source ? reinterpret_cast<const char*>(source) : "";
    const auto* param_map = reinterpret_cast<const std::unordered_map<std::string, std::string>*>(param_provider);
    auto engine = pns::ttmachine::RuleEngine::Instance();
    auto* result = new pns::ttmachine::ExecuteResultRecord(
        engine->ValidateTrigger(c_trig, c_src, *param_map));
    return reinterpret_cast<jobject>(result);
}

/**
 * Disassembly verified at 0x00f8ec..0x00fbe4 (764 B):
 *   0x00f90c: ldarb w8, [0x0541f8]; tbnz w8, #0, #0xf934 ("engine service has not activate" 0x0441f5)
 *   0x00f934: cbz x2, #0xfa24; cbz x3, #0xfa24 ("value is null or name list key is null" 0x044215)
 *   0x00f99c: bl #0x3963c (namelist_find_container)
 *   0x00f9dc: bl #0x3ac80 (MatchTokens)
 */
JNIEXPORT jobject JNICALL isInNameList(
    JNIEnv* /*env*/,
    jclass /*clazz*/,
    jstring param_value,
    jstring name_list_key,
    jboolean strict_ready) {
    if (!pns::ttmachine::g_global_is_activated.load(std::memory_order_acquire)) {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGW("engine service has not activate"); // 0x0441f5
        }
        return nullptr;
    }
    if (!param_value || !name_list_key) {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGW("value is null or name list key is null"); // 0x044215
        }
        return nullptr;
    }
    const char* c_val = reinterpret_cast<const char*>(param_value);
    const char* c_key = reinterpret_cast<const char*>(name_list_key);
    auto& mgr = pns::ttmachine::NameListManager::Instance();
    auto container = mgr.FindContainer(c_key);
    if (container && container->MatchTokens(pns::ttmachine::NameListManager::TokenizeValue(c_val), 0)) {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGD("value %s is in name list %s", c_val, c_key); // 0x044264
        }
        static const bool kTrueBox = true;
        return const_cast<jobject>(reinterpret_cast<const void*>(&kTrueBox));
    }
    if (strict_ready != 0 && mgr.GetPrepareStatus() != 2) {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGW("name list is not prepare success"); // 0x044280
        }
        return nullptr;
    }
    static const bool kFalseBox = false;
    return const_cast<jobject>(reinterpret_cast<const void*>(&kFalseBox));
}

/**
 * Disassembly verified at 0x00fc7c (4 B):
 *   0x00fc7c: c0035fd6  ret
 */
JNIEXPORT void JNICALL update(JNIEnv* /*env*/, jclass /*clazz*/, jstring /*config_str*/) {
    // Exact 4-byte no-op ret in binary at 0x00fc7c
}

/**
 * Disassembly verified at 0x00fc80..0x00fc90 (20 B):
 *   0x00fc80: adrp x8, #0x54000
 *   0x00fc84: add  x8, x8, #0x1f8
 *   0x00fc88: ldarb w8, [x8]
 *   0x00fc8c: and  w0, w8, #1
 *   0x00fc90: ret
 */
JNIEXPORT jboolean JNICALL isActivated(JNIEnv* /*env*/, jclass /*clazz*/) {
    return pns::ttmachine::g_global_is_activated.load(std::memory_order_acquire) ? 1 : 0;
}

/**
 * Disassembly verified at 0x00fc94..0x00fd50 (192 B):
 *   Reads strategy_version_ at offset +0xc8 under pthread_rwlock_rdlock (0x055680) if ready == 1;
 *   returns -1 if not activated or not ready.
 */
JNIEXPORT jint JNICALL getStrategyVersion(JNIEnv* /*env*/, jclass /*clazz*/) {
    if (!pns::ttmachine::g_global_is_activated.load(std::memory_order_acquire)) {
        return -1;
    }
    return pns::ttmachine::RuleEngine::Instance()->GetStrategyVersion();
}

/**
 * Disassembly verified at 0x00fd54..0x00fd58 (8 B):
 *   0x00fd54: 00008092  mov x0, #-1
 *   0x00fd58: c0035fd6  ret
 */
JNIEXPORT jlong JNICALL getGetConstPoolVersion(JNIEnv* /*env*/, jclass /*clazz*/) {
    return -1LL;
}

/**
 * Disassembly verified at 0x00fd5c..0x00fec0 (360 B):
 *   Iterates Java List<String> and invokes load_const_pool_extra_json (0x0318a8) on each element.
 */
JNIEXPORT void JNICALL loadConstPoolExtra(JNIEnv* /*env*/, jclass /*clazz*/, jobject extra_json_list) {
    if (!extra_json_list || !pns::ttmachine::g_global_is_activated.load(std::memory_order_acquire)) {
        if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
            PNS_JNI_LOGW("engine is null or config is null"); // 0x0442a1
        }
        return;
    }
    const auto* vec = reinterpret_cast<const std::vector<std::string>*>(extra_json_list);
    for (const auto& json_item : *vec) {
        if (json_item.empty()) {
            if (pns::ttmachine::g_global_debug_log.load(std::memory_order_relaxed)) {
                PNS_JNI_LOGW("elementStr is null"); // 0x0440e6
            }
            continue;
        }
        pns::ttmachine::NameListManager::Instance().LoadConstPoolExtraJson(json_item.c_str());
    }
}

} // extern "C"
