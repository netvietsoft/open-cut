// ============================================================================
// FILE: cepengine_manager_core.h
// TARGET: libCepEngine.so — EngineConfig, Env, EngineCore, EngineManagerInner & EngineManager
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Declares `cep::EngineConfig` (0x13a48..0x14533), `cep::Env` (0x243a8..0x246e3),
//      `cep::EngineCore` (0x15564..0x15eb7), `cep::EngineManagerInner`
//      (0x16608..0x1b59f), and `cep::EngineManager` (0x21d90..0x23e5b).
// [VN] Khai báo `cep::EngineConfig` (0x13a48..0x14533), `cep::Env` (0x243a8..0x246e3),
//      `cep::EngineCore` (0x15564..0x15eb7), `cep::EngineManagerInner`
//      (0x16608..0x1b59f), và `cep::EngineManager` (0x21d90..0x23e5b).
// ============================================================================

#pragma once

#include "cepengine_nfa_evaluator.h"
#include <unordered_set>

namespace cep {

// ============================================================================
// 1. ENGINE CONFIG (`cep::EngineConfig` @ 0x13a48..0x14533, 104 B = 0x68)
// ============================================================================

// [EN] ABI layout verified directly from 0x13a48..0x144bc:
//      +0x00: `std::enable_shared_from_this<EngineConfig>` (`weak_this_`, 16 B)
//      +0x10: `extra_` (`void*`, `str x1, [x0, #0x10]` @ 0x13a5c)
//      +0x18: `match_timeout_inference_strategy_` (`MatchTimeoutInferenceStrategy`, `str w1, [x0, #0x18]` @ 0x13b30)
//      +0x1c: `overwrite_` (`bool`, `strb w9, [x0, #0x1c]` @ 0x13aa4)
//      +0x1d: `debug_` (`bool`, `strb w9, [x0, #0x1d]` @ 0x13aec)
//      +0x20: `max_matched_events_length_` (`long long`, `str x1, [x0, #0x20]` @ 0x13b74)
//      +0x28: `max_matches_count_` (`long long`, `str x1, [x0, #0x28]` @ 0x13bb8)
//      +0x30: `max_queuing_count_` (`long long`, `str x1, [x0, #0x30]` @ 0x13bfc)
//      +0x38: `process_mode_` (`ProcessMode`, `str w1, [x0, #0x38]` @ 0x13c40)
//      +0x40: `variables_` (`std::unordered_map<std::string, std::shared_ptr<DataInterface>>`, 40 B)
// [VN] Bố cục ABI của `cep::EngineConfig` (104 B) đối soát từ 0x13a48..0x144bc:
class EngineConfig : public std::enable_shared_from_this<EngineConfig> {
public:
    using VariableMap = std::unordered_map<std::string, std::shared_ptr<DataInterface>>;

    EngineConfig();                                                                 // @ 0x14458 (104 B)
    explicit EngineConfig(const std::shared_ptr<DataInterface>& data);              // @ 0x144c0 (116 B)
    ~EngineConfig() = default;

    std::shared_ptr<EngineConfig> SetExtra(void* extra);                            // @ 0x13a48 (68 B)
    std::shared_ptr<EngineConfig> SetOverwrite(bool overwrite);                     // @ 0x13a8c (72 B)
    std::shared_ptr<EngineConfig> SetDebug(bool debug);                             // @ 0x13ad4 (72 B)
    std::shared_ptr<EngineConfig> SetMatchTimeoutInferenceStrategy(
        MatchTimeoutInferenceStrategy strategy);                                    // @ 0x13b1c (68 B)
    std::shared_ptr<EngineConfig> SetMaxMatchedEventsLength(long long length);      // @ 0x13b60 (68 B)
    std::shared_ptr<EngineConfig> SetMaxMatchesCount(long long count);              // @ 0x13ba4 (68 B)
    std::shared_ptr<EngineConfig> SetMaxQueuingCount(long long count);              // @ 0x13be8 (68 B)
    std::shared_ptr<EngineConfig> SetProcessMode(ProcessMode mode);                 // @ 0x13c2c (68 B)
    std::shared_ptr<EngineConfig> SetVariables(const VariableMap& vars);            // @ 0x13c70 (96 B)
    bool ParseFromData(const std::shared_ptr<DataInterface>& data);                 // @ 0x13cd0 (1928 B)

    void* extra() const { return extra_; }
    bool overwrite() const { return overwrite_; }
    bool debug() const { return debug_; }
    MatchTimeoutInferenceStrategy match_timeout_inference_strategy() const {
        return match_timeout_inference_strategy_;
    }
    long long max_matched_events_length() const { return max_matched_events_length_; }
    long long max_matches_count() const { return max_matches_count_; }
    long long max_queuing_count() const { return max_queuing_count_; }
    ProcessMode process_mode() const { return process_mode_; }
    const VariableMap& variables() const { return variables_; }

private:
    std::shared_ptr<EngineConfig> SelfOrNull();

    void* extra_ = nullptr;                                                         // +0x10
    MatchTimeoutInferenceStrategy match_timeout_inference_strategy_ = kTimeoutInference; // +0x18
    bool overwrite_ = true;                                                         // +0x1c
    bool debug_ = false;                                                            // +0x1d
    long long max_matched_events_length_ = 100;                                     // +0x20
    long long max_matches_count_ = 100;                                             // +0x28
    long long max_queuing_count_ = 100;                                             // +0x30
    ProcessMode process_mode_ = kProcessAsync;                                      // +0x38
    VariableMap variables_;                                                         // +0x40
};

// ============================================================================
// 2. ENVIRONMENT SINGLETON (`cep::Env` @ 0x243a8..0x246e3, `.bss 0x5c558`)
// ============================================================================

// [EN] Global CEP Environment singleton (`cep::Env::Instance()` @ 0x243a8, 248 B):
//      +0x08: `RWLock lock_`
//      +0x30: `supported_exp_engines_` (`std::unordered_set<std::string>`, 40 B)
//      +0x58: `version_` (`std::string` = `"1.5.0"`, `mov w8, #0x2e31; movk w8, #0x2e35, lsl #16` @ 0x24444..0x24450)
//      +0x70: `global_enable_` (`bool` = `true`), +0x71: `enable_fallback_` (`bool` = `false`)
//      +0x78: `disabled_rules_` (`std::unordered_set<std::string>`)
//      +0xa0: `max_queuing_events_count_` (`long long` = `100` = `0x64`)
//      +0xa8: `max_matches_count_` (`long long` = `100` = `0x64`)
//      +0xb0: `max_matched_events_length_` (`long long` = `100` = `0x64`)
//      +0xc0: `statistic_report_time_window_ms_` (`long long` = `300000` = `0x493e0`)
//      +0xd0: `monitor_report_time_window_ms_` (`long long` = `300000` = `0x493e0`)
//      +0xd8: `max_statistic_report_cnt_in_window_` (`long long` = `5`)
//      +0xe8: `fixed_queue_size_` (`long long` = `4`)
// [VN] Singleton môi trường CEP toàn cục (`cep::Env::Instance()` @ 0x243a8, 248 B):
class Env {
public:
    static Env* Instance();                                                         // @ 0x243a8 (248 B)

    void Init(const std::shared_ptr<DataInterface>& config_data);                   // @ 0x24560
    std::unordered_set<std::string> AllSupportedExpEngine();                        // @ 0x24670 (116 B)
    void AddSupportedExpEngine(const std::string& name);

    const std::string& version() const { return version_; }
    bool global_enable() const { return global_enable_; }
    bool enable_fallback() const { return enable_fallback_; }
    long long max_queuing_events_count() const { return max_queuing_events_count_; }
    long long max_matches_count() const { return max_matches_count_; }
    long long max_matched_events_length() const { return max_matched_events_length_; }
    long long statistic_report_time_window_ms() const { return statistic_report_time_window_ms_; }
    long long monitor_report_time_window_ms() const { return monitor_report_time_window_ms_; }
    long long max_statistic_report_cnt_in_window() const { return max_statistic_report_cnt_in_window_; }
    long long fixed_queue_size() const { return fixed_queue_size_; }
    bool use_fixed_queue() const { return use_fixed_queue_; }
    bool enable_proactive_engine_clean() const { return enable_proactive_engine_clean_; }
    bool IsRuleDisabled(const std::string& rule_name) const;

private:
    Env();
    ~Env() = default;

    mutable RWLock lock_;                                   // +0x08
    std::unordered_set<std::string> supported_exp_engines_; // +0x30
    std::string version_ = "1.5.0";                         // +0x58
    bool global_enable_ = true;                             // +0x70
    bool enable_fallback_ = false;                          // +0x71
    std::unordered_set<std::string> disabled_rules_;        // +0x78
    long long max_queuing_events_count_ = 100;              // +0xa0
    long long max_matches_count_ = 100;                     // +0xa8
    long long max_matched_events_length_ = 100;             // +0xb0
    double statistic_sampling_rate_ = 0.0;                  // +0xb8
    long long statistic_report_time_window_ms_ = 300000;    // +0xc0 (0x493e0)
    double monitor_sampling_rate_ = 0.0;                    // +0xc8
    long long monitor_report_time_window_ms_ = 300000;      // +0xd0 (0x493e0)
    long long max_statistic_report_cnt_in_window_ = 5;      // +0xd8
    bool use_fixed_queue_ = false;                          // +0xe0
    long long fixed_queue_size_ = 4;                        // +0xe8
    bool enable_proactive_engine_clean_ = false;            // +0xf0
};

// ============================================================================
// 3. ENGINE MANAGER INNER (`cep::EngineManagerInner` @ 0x16608..0x1b59f)
// ============================================================================

using CepBizFunction = std::function<std::shared_ptr<DataInterface>(
    std::shared_ptr<Context>,
    std::vector<std::shared_ptr<DataInterface>>)>;

using CepEngineResultCallback = std::function<void(const std::shared_ptr<EngineResult>&)>;
using CepResultCallback       = std::function<void(const std::shared_ptr<Result>&)>;
using CepSettingsCallback     = std::function<std::shared_ptr<DataInterface>(std::string)>;

struct ExpEngineDescriptor {
    int type = 0;
    std::string name;
    std::function<std::shared_ptr<ExprEvaluator>()> create_evaluator;
    std::function<void*(void*)> retain_event;
    std::function<void(void*)> release_event;
    std::function<void*()> create_list;
    std::function<void(void*)> release_list;
    std::function<void*(void*)> copy_list;
    std::function<void(void*, void*)> append_list;
};

struct RegisteredRuleEntry {
    std::string biz_name;
    std::string rule_name;
    std::shared_ptr<DataInterface> rule_data;
    std::shared_ptr<EngineConfig> config;
    std::shared_ptr<Nfa> nfa;
    std::shared_ptr<NfaState> nfa_state;
    bool enabled = true;
    bool debug = false;
    long long last_success_timestamp = -1;
};

// [EN] Internal singleton engine registry (`cep::EngineManagerInner` @ 0x16608..0x1b59f,
//      `.bss 0x5c038`, guard `.bss 0x5c540`).
//      Initializes 7 hash maps + RWLock pairs in `Instance()` @ 0x16608 (280 B).
// [VN] Bảng đăng ký engine nội bộ singleton (`cep::EngineManagerInner` @ 0x16608..0x1b59f):
class EngineManagerInner {
public:
    static EngineManagerInner* Instance();                                          // @ 0x16608 (280 B)

    std::shared_ptr<RegisteredRuleEntry> GetEngine(const std::string& biz_name,
                                                   const std::string& rule_name);   // @ 0x1878c (268 B)
    bool IsDebug(const std::string& biz_name,
                 const std::string& rule_name);                                     // @ 0x189a8 (144 B)
    void RegisterExprEvaluator(
        int type,
        std::string name,
        std::function<std::shared_ptr<ExprEvaluator>()> create_evaluator,
        std::function<void*(void*)> retain_event,
        std::function<void(void*)> release_event,
        std::function<void*()> create_list,
        std::function<void(void*)> release_list,
        std::function<void*(void*)> copy_list,
        std::function<void(void*, void*)> append_list);                             // @ 0x195dc (628 B)
    void RegisterSettingsCallback(const std::string& biz_name,
                                  const CepSettingsCallback& callback);             // @ 0x19850 (648 B)
    CepBizFunction GetFunction(const std::string& biz_name,
                               const std::string& func_name);                       // @ 0x1ac7c (372 B)
    std::shared_ptr<ExpEngineDescriptor> GetExpEngine(ExpressionType type);         // @ 0x1ae88 (312 B)
    CepSettingsCallback GetSettingsCallback(const std::string& biz_name);           // @ 0x1afc0 (256 B)
    std::string CollectCrashInfo();                                                 // @ 0x1b0c0 (796 B)
    long long GetLastSuccessTimestamp(const std::string& biz_name,
                                      const std::string& rule_name);                // @ 0x1b3dc (132 B)
    long long GetLastSuccessTimestampUnsafe(const std::string& biz_name,
                                            const std::string& rule_name);          // @ 0x1b460 (132 B)
    std::shared_ptr<DataInterface> GetConstVariableUnsafe(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& var_name);                                               // @ 0x1b4e4 (188 B)

    // Internal operations invoked by EngineCore and EngineManager
    bool RegisterRuleInternal(const std::shared_ptr<Context>& ctx,
                              const std::string& biz_name,
                              const std::string& rule_name,
                              const std::shared_ptr<DataInterface>& rule_data,
                              const std::shared_ptr<EngineConfig>& config,
                              std::string& out_error);
    bool RegisterRulesInternal(const std::shared_ptr<Context>& ctx,
                               const std::string& biz_name,
                               const std::shared_ptr<DataInterface>& rules_data,
                               const std::shared_ptr<EngineConfig>& config,
                               std::string& out_error);
    std::vector<std::string> GetRuleNamesInternal(const std::string& biz_name);
    void UnregisterRuleInternal(const std::string& biz_name, const std::string& rule_name);
    void DisableRuleInternal(const std::string& biz_name,
                             const std::string& rule_name,
                             DisableStrategy strategy);
    void EnableRuleInternal(const std::string& biz_name, const std::string& rule_name);
    void EnableDebugInternal(const std::string& biz_name, const std::string& rule_name);
    void DisableDebugInternal(const std::string& biz_name, const std::string& rule_name);
    void ResetProcessModeInternal(const std::string& biz_name,
                                  const std::string& rule_name,
                                  ProcessMode mode);
    void RegisterFunctionInternal(const std::string& biz_name,
                                  const std::string& func_name,
                                  const CepBizFunction& fn);
    void UnregisterFunctionInternal(const std::string& biz_name, const std::string& func_name);
    void RegisterEngineCallbackInternal(const std::string& biz_name,
                                        const std::string& rule_name,
                                        const CepEngineResultCallback& cb);
    void UnregisterEngineCallbackInternal(const std::string& biz_name,
                                          const std::string& rule_name);
    void RegisterRuleCallbackInternal(const std::string& biz_name,
                                      const std::string& rule_name,
                                      const CepResultCallback& cb);
    void UnregisterRuleCallbackInternal(const std::string& biz_name,
                                        const std::string& rule_name);
    void RegisterBizCallbackInternal(const std::string& biz_name,
                                     const CepResultCallback& cb);
    void UnregisterBizCallbackInternal(const std::string& biz_name);
    void CleanInternal(const std::string& biz_name, const std::string& rule_name);
    void CleanRulesInternal(const std::string& biz_name,
                            const std::vector<std::string>& rule_names);
    std::vector<std::shared_ptr<EngineResult>> ProcessEventInternal(
        const std::shared_ptr<Context>& ctx,
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        const std::shared_ptr<DataInterface>& event_data,
        void* raw_data,
        long long timestamp_ms,
        void* extra);

private:
    EngineManagerInner();
    ~EngineManagerInner() = default;

    static std::string MakeKey(const std::string& biz, const std::string& name) {
        return biz + "#" + name;
    }

    mutable RWLock rules_lock_;
    std::unordered_map<std::string, std::shared_ptr<RegisteredRuleEntry>> rules_;

    mutable RWLock funcs_lock_;
    std::unordered_map<std::string, CepBizFunction> functions_;

    mutable RWLock callbacks_lock_;
    std::unordered_map<std::string, CepEngineResultCallback> engine_callbacks_;
    std::unordered_map<std::string, CepResultCallback> rule_callbacks_;
    std::unordered_map<std::string, CepResultCallback> biz_callbacks_;

    mutable RWLock settings_lock_;
    std::unordered_map<std::string, CepSettingsCallback> settings_callbacks_;

    mutable RWLock exp_lock_;
    std::unordered_map<int, std::shared_ptr<ExpEngineDescriptor>> exp_engines_;

    mutable RWLock crash_lock_;
    std::unordered_set<std::string> executing_rules_;
    std::unordered_set<std::string> registering_rules_;
};

// ============================================================================
// 4. ENGINE CORE (`cep::EngineCore` @ 0x15564..0x15eb7)
// ============================================================================

class EngineCore {
public:
    static bool RegisterRule(const std::string& biz_name,
                             const std::string& rule_name,
                             const std::shared_ptr<DataInterface>& rule_data,
                             const std::shared_ptr<EngineConfig>& config,
                             std::string& error_msg);                               // @ 0x15564 (220 B)
    static bool RegisterRules(const std::string& biz_name,
                              const std::shared_ptr<DataInterface>& rules_data,
                              const std::shared_ptr<EngineConfig>& config,
                              std::string& error_msg);                              // @ 0x15640 (204 B)
    static std::vector<std::string> GetRuleNames(const std::string& biz_name);      // @ 0x1570c (44 B)
    static void UnregisterRule(const std::string& biz_name,
                               const std::string& rule_name);                       // @ 0x15738 (44 B)
    static void DisableRule(const std::string& biz_name,
                            const std::string& rule_name,
                            DisableStrategy strategy);                              // @ 0x15764 (60 B)
    static void EnableRule(const std::string& biz_name,
                           const std::string& rule_name);                           // @ 0x157a0 (44 B)
    static void DisableDebug(const std::string& biz_name,
                             const std::string& rule_name);                         // @ 0x157cc (44 B)
    static void EnableDebug(const std::string& biz_name,
                            const std::string& rule_name);                          // @ 0x157f8 (44 B)
    static void RegisterFunction(const std::string& biz_name,
                                 const std::string& func_name,
                                 const CepBizFunction& fn);                         // @ 0x15824 (60 B)
    static void UnregisterFunction(const std::string& biz_name,
                                   const std::string& func_name);                   // @ 0x15860 (44 B)
    static void RegisterCallback(const std::string& biz_name,
                                 const std::string& rule_name,
                                 const CepEngineResultCallback& cb);                // @ 0x1588c (532 B)
    static void UnregisterCallback(const std::string& biz_name,
                                   const std::string& rule_name);                   // @ 0x15aa0 (44 B)
    static void AsyncClean(const std::string& biz_name,
                           const std::string& rule_name);                           // @ 0x15acc (44 B)
    static void SyncClean(const std::string& biz_name,
                          const std::string& rule_name);                            // @ 0x15af8 (44 B)
    static void RegisterSettingsCallback(const std::string& biz_name,
                                         const CepSettingsCallback& cb);            // @ 0x15b24 (44 B)
    static void AsyncProcess(const std::string& biz_name,
                             const std::string& rule_name,
                             const std::string& event_name,
                             const std::shared_ptr<DataInterface>& event_data,
                             long long timestamp_ms);                               // @ 0x15b50 (216 B)
    static std::vector<std::shared_ptr<EngineResult>> SyncProcess(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        const std::shared_ptr<DataInterface>& event_data,
        long long timestamp_ms);                                                    // @ 0x15c28 (328 B)
    static std::vector<std::shared_ptr<EngineResult>> ProcessInCurrentThread(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        const std::shared_ptr<DataInterface>& event_data,
        long long timestamp_ms);                                                    // @ 0x15d70 (328 B)
};

// ============================================================================
// 5. ENGINE MANAGER (`cep::EngineManager` @ 0x21d90..0x23e5b, `.bss 0x5c548`)
// ============================================================================

// [EN] Public facade `cep::EngineManager` (@ 0x21d90..0x23e5b):
//      Holds a single pointer `EngineManagerInner* inner_` at `+0x00`
//      (`ldr x0, [x0]; b #0x184a0` @ 0x22fe4).
// [VN] Facade công khai `cep::EngineManager` (@ 0x21d90..0x23e5b):
class EngineManager {
public:
    static EngineManager* Instance();                                               // @ 0x21d90 (84 B)

    std::shared_ptr<Result> RegisterRule(const std::string& biz_name,
                                         const std::string& rule_name,
                                         const std::string& rule_json,
                                         bool real_time_process,
                                         void* extra = nullptr,
                                         bool overwrite = true);                    // @ 0x21de4 (872 B)
    std::shared_ptr<Result> RegisterRules(const std::string& biz_name,
                                          const std::string& rules_json,
                                          bool real_time_process,
                                          void* extra = nullptr,
                                          bool overwrite = true);                   // @ 0x2214c (864 B)
    std::shared_ptr<Result> RegisterRule(const std::string& biz_name,
                                         const std::string& rule_name,
                                         const std::shared_ptr<DataInterface>& rule_data,
                                         bool real_time_process,
                                         void* extra = nullptr,
                                         bool overwrite = true);                    // @ 0x224ac (700 B)
    std::shared_ptr<Result> RegisterRules(const std::string& biz_name,
                                          const std::shared_ptr<DataInterface>& rules_data,
                                          bool real_time_process,
                                          void* extra = nullptr,
                                          bool overwrite = true);                   // @ 0x22768 (700 B)
    bool RegisterRule(const std::shared_ptr<Context>& ctx,
                      const std::string& biz_name,
                      const std::string& rule_name,
                      const std::shared_ptr<DataInterface>& rule_data,
                      const std::shared_ptr<EngineConfig>& config,
                      std::string& error_msg);                                      // @ 0x22a24 (740 B)
    bool RegisterRules(const std::shared_ptr<Context>& ctx,
                       const std::string& biz_name,
                       const std::shared_ptr<DataInterface>& rules_data,
                       const std::shared_ptr<EngineConfig>& config,
                       std::string& error_msg);                                     // @ 0x22d08 (732 B)

    void UnregisterRule(const std::string& biz_name,
                        const std::string& rule_name);                              // @ 0x22fe4 (8 B)
    void DisableRule(const std::string& biz_name,
                     const std::string& rule_name,
                     bool clean);                                                   // @ 0x22fec (20 B)
    void DisableRule(const std::string& biz_name,
                     const std::string& rule_name,
                     DisableStrategy strategy);                                     // @ 0x23000 (8 B)
    void EnableRule(const std::string& biz_name,
                    const std::string& rule_name);                                  // @ 0x23008 (8 B)
    void EnableDebug(const std::string& biz_name,
                     const std::string& rule_name);                                 // @ 0x23010 (8 B)
    void DisableDebug(const std::string& biz_name,
                      const std::string& rule_name);                                // @ 0x23018 (8 B)
    void ResetProcessMode(const std::string& biz_name,
                          const std::string& rule_name,
                          ProcessMode mode);                                        // @ 0x23020 (8 B)
    void RegisterBizFunction(const std::string& biz_name,
                             const std::string& func_name,
                             const CepBizFunction& fn);                             // @ 0x23028 (8 B)
    void UnregisterBizFunction(const std::string& biz_name,
                               const std::string& func_name);                       // @ 0x23030 (8 B)
    void RegisterRuleCallback(const std::string& biz_name,
                              const std::string& rule_name,
                              const CepResultCallback& cb);                         // @ 0x23038 (8 B)
    void UnregisterRuleCallback(const std::string& biz_name,
                                const std::string& rule_name);                      // @ 0x23040 (8 B)
    void RegisterBizCallback(const std::string& biz_name,
                             const CepResultCallback& cb);                          // @ 0x23048 (8 B)
    void UnregisterBizCallback(const std::string& biz_name);                        // @ 0x23050 (8 B)
    void Clean(const std::string& biz_name,
               const std::string& rule_name);                                       // @ 0x23058 (8 B)
    void SyncClean(const std::string& biz_name,
                   const std::string& rule_name);                                   // @ 0x23060 (8 B)
    void CleanRules(const std::string& biz_name,
                    const std::vector<std::string>& rule_names);                    // @ 0x23068 (8 B)
    void SyncCleanRules(const std::string& biz_name,
                        const std::vector<std::string>& rule_names);                // @ 0x23070 (8 B)
    void AsyncClean(const std::string& biz_name,
                    const std::string& rule_name);                                  // @ 0x23078 (8 B)
    void AsyncCleanRules(const std::string& biz_name,
                         const std::vector<std::string>& rule_names);               // @ 0x23080 (8 B)

    void RegisterExprEvaluator(
        int type,
        std::function<std::shared_ptr<ExprEvaluator>()> create_evaluator,
        std::function<void*(void*)> retain_event,
        std::function<void(void*)> release_event,
        std::function<void*()> create_list,
        std::function<void(void*)> release_list,
        std::function<void*(void*)> copy_list,
        std::function<void(void*, void*)> append_list);                             // @ 0x23088 (984 B)

    void RegisterSettingsCallback(const std::string& biz_name,
                                  const CepSettingsCallback& cb);                   // @ 0x23460 (8 B)

    std::vector<std::shared_ptr<Result>> SyncProcess(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x23468 (232 B)
    void AsyncProcess(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x23550 (216 B)
    std::vector<std::shared_ptr<Result>> ProcessInCurrentThread(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x23628 (232 B)
    std::vector<std::shared_ptr<Result>> ProcessRules(
        const std::string& biz_name,
        const std::vector<std::string>& rule_names,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x23710 (216 B)
    std::vector<std::shared_ptr<Result>> SyncProcess(
        const std::shared_ptr<Context>& ctx,
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x237e8 (440 B)
    void AsyncProcess(
        const std::shared_ptr<Context>& ctx,
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x239a0 (432 B)
    std::vector<std::shared_ptr<Result>> ProcessInCurrentThread(
        const std::shared_ptr<Context>& ctx,
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x23b50 (440 B)

    void Init(const std::shared_ptr<DataInterface>& config_data);                   // @ 0x23d08 (36 B)
    std::unordered_set<std::string> AllSupportedExpression();                       // @ 0x23d2c (36 B)
    std::string CollectCrashInfo();                                                 // @ 0x23d50 (8 B)
    std::vector<std::string> GetRuleNames(const std::string& biz_name);             // @ 0x23d58 (8 B)
    long long GetLastSuccessTimestamp(const std::string& biz_name,
                                      const std::string& rule_name);                // @ 0x23d60 (8 B)
    std::vector<std::shared_ptr<Result>> ProcessInCurrentThread(
        const std::string& biz_name,
        const std::string& event_name,
        void* event_data,
        long long timestamp_ms,
        void* extra = nullptr);                                                     // @ 0x23d68 (244 B)

private:
    explicit EngineManager(EngineManagerInner* inner) : inner_(inner) {}
    EngineManagerInner* inner_ = nullptr;                   // +0x00 (`ldr x0, [x0]` @ 0x22fe4)
};

} // namespace cep
