/**
 * @file pns_ttmachine_rule_engine.h
 * @brief RuleEngine Singleton, Decision Tree Executor & RuleEngineService JNI Exports
 *        Đơn bản RuleEngine, Bộ thực thi cây quyết định & Các hàm xuất JNI RuleEngineService
 *
 * Disassembly Reference / Tham chiếu Disassembly:
 *   - 0x00d430..0x00d50c: JNI_OnLoad (registers 9 JNINativeMethods at 0x054000 on RuleEngineService)
 *   - 0x00d510..0x00db78: active (nativeActivate: parses JSON strategy config & builds InitStatistics)
 *   - 0x00e400..0x00e490: destroy (nativeDestroy: locks rwlock at 0x055680, resets shared_ptr at 0x055670)
 *   - 0x00e494..0x00e9c8: validate (nativeValidate: runs sync/async strategies & builds ExecuteResult)
 *   - 0x00f8ec..0x00fbe4: isInNameList (nativeIsInNameList: checks NameListManager & returns Boolean)
 *   - 0x00fc7c..0x00fc7f: update (nativeUpdateConfig: 4-byte ret)
 *   - 0x00fc80..0x00fc90: isActivated (nativeIsActivated: ldarb w8, [0x0541f8]; and w0, w8, #1)
 *   - 0x00fc94..0x00fd50: getStrategyVersion (nativeGetStrategyVersion: reads version at [x8, #0xc8])
 *   - 0x00fd54..0x00fd58: getGetConstPoolVersion (nativeGetConstPoolVersion: mov x0, #-1; ret)
 *   - 0x00fd5c..0x00fec0: loadConstPoolExtra (nativeLoadConstPoolExtra: iterates List<String> -> 0x0318a8)
 *   - 0x02b66c..0x02b7f4: RuleEngine::Instance() (allocates 0xd0 = 208 B at 0x02b6ac, vtable 0x0533b0)
 */

#ifndef NEXTAI_OPENCUT_PNS_TTMACHINE_RULE_ENGINE_H_
#define NEXTAI_OPENCUT_PNS_TTMACHINE_RULE_ENGINE_H_

#include "pns_ttmachine_types.h"
#include <pthread.h>

namespace pns {
namespace ttmachine {

/**
 * RuleEngine C++ Singleton (0xd0 = 208 bytes allocated at 0x02b6ac, vtable at 0x0533b0).
 * Đơn bản C++ RuleEngine (0xd0 = 208 byte cấp phát tại 0x02b6ac, vtable tại 0x0533b0).
 *
 * Verified memory layout at 0x02b6ac..0x02b760:
 *   +0x00: vtable pointer (0x0533b0)
 *   +0x08..+0x58: trigger_map_, strategy_list_map_, strategy_map_, condition_map_, action_map_
 *   +0x60..+0x68: shared_ptr<ConstPoolConfig> (0x40 = 64 B allocated at 0x02b6e8, vtable 0x0536f0)
 *   +0x70..+0x97: std::recursive_mutex (_ZNSt6__ndk115recursive_mutexC1Ev at 0x02b720)
 *   +0x98: bool is_initialized_
 *   +0xa0..+0xc0: async thread pool / task queue pointers (initialized at 0x03728c)
 *   +0xc8: int32_t strategy_version_ (read at 0x00fcf8: ldr w19, [x8, #0xc8])
 */
class RuleEngine {
public:
    static std::shared_ptr<RuleEngine> Instance();
    static void ResetInstance();

    RuleEngine();
    virtual ~RuleEngine();

    // Parses JSON config string and activates engine (called by active at 0x00d510..0x00d880)
    // Phân tích chuỗi cấu hình JSON và kích hoạt engine (được gọi bởi active tại 0x00d510..0x00d880)
    bool ActivateWithConfig(
        const std::string& config_json,
        const std::vector<std::string>& extra_strategy_jsons,
        const std::vector<std::string>& const_pool_jsons,
        bool enable_debug_log,
        int64_t const_pool_version,
        int32_t sample_rate_percent,
        InitStatisticsRecord* out_stats);

    // Validates a trigger with given parameter map (called by validate at 0x00e494..0x00e900)
    // Xác thực một trigger với bản đồ tham số đầu vào (được gọi bởi validate tại 0x00e494..0x00e900)
    ExecuteResultRecord ValidateTrigger(
        const std::string& trigger_id,
        const std::string& extra_source,
        const std::unordered_map<std::string, std::string>& params,
        std::function<void(const ExecuteResultRecord&)> async_callback = nullptr);

    // Executes a single strategy decision tree (0x02d400..0x02e500)
    // Thực thi một cây quyết định chiến lược đơn lẻ (0x02d400..0x02e500)
    StrategyExecutionRecord ExecuteStrategyTree(
        const std::string& trigger_id,
        const StrategyDefinition& strategy,
        std::unordered_map<std::string, std::string>& working_params,
        bool* out_stop_following) const;

    // Evaluates a single RuleCondition (TTM bytecode or CEP rule)
    // Đánh giá một điều kiện RuleCondition đơn lẻ (bytecode TTM hoặc tập luật CEP)
    bool EvaluateCondition(
        const RuleCondition& cond,
        const std::unordered_map<std::string, std::string>& params,
        int32_t* out_error_code) const;

    int32_t GetStrategyVersion() const noexcept;
    int64_t GetConstPoolVersion() const noexcept { return -1LL; } // 0x00fd54: mov x0, #-1; ret
    bool IsActivated() const noexcept;
    bool IsDebugLogEnabled() const noexcept { return debug_log_enabled_.load(std::memory_order_relaxed); }

    // Programmatic registration helpers for unit testing & native verification
    // Các hàm đăng ký lập trình phục vụ kiểm thử đơn vị & xác minh native
    void RegisterTriggerMapping(const std::string& trigger_id, const std::string& strategy_list_id);
    void RegisterStrategyList(const StrategyListConfig& slist);
    void RegisterStrategy(const StrategyDefinition& strategy);
    void RegisterCondition(const RuleCondition& cond);
    void RegisterAction(const DecisionAction& action);

private:
    mutable std::recursive_mutex mutex_;
    mutable pthread_rwlock_t state_rwlock_;
    std::atomic<bool> is_activated_{false};
    std::atomic<bool> debug_log_enabled_{false};
    std::atomic<int32_t> strategy_ready_state_{0}; // 0x055698 (1 = ready)
    int32_t strategy_version_ = -1;                // +0xc8 (read at 0x00fcf8)
    int32_t global_sample_rate_ = 100;             // 0x0540d8
    int32_t global_const_pool_ver_ = -1;           // 0x0540dc

    std::unordered_map<std::string, std::string> trigger_to_strategy_list_;
    std::unordered_map<std::string, StrategyListConfig> strategy_lists_;
    std::unordered_map<std::string, StrategyDefinition> strategies_;
    std::unordered_map<std::string, RuleCondition> conditions_;
    std::unordered_map<std::string, DecisionAction> actions_;
};

// Returns the 9-entry JNINativeMethod table at 0x054000..0x0540d8
// Trả về bảng 9 phương thức JNINativeMethod tại 0x054000..0x0540d8
struct RuleEngineJniMethodEntry {
    const char* name;
    const char* signature;
    void* fn_ptr;
};
const RuleEngineJniMethodEntry* GetRuleEngineJniMethodTable(size_t* out_count) noexcept;

} // namespace ttmachine
} // namespace pns

// ============================================================================
// Exported C / JNI Symbols for RuleEngineService (0x00d430..0x00fec0)
// Các ký hiệu C / JNI xuất ra cho RuleEngineService (0x00d430..0x00fec0)
// ============================================================================
extern "C" {

// 0x00d430 (224 B): JNI_OnLoad
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);

// 0x00d510 (1644 B): active -> nativeActivate
JNIEXPORT jobject JNICALL active(
    JNIEnv* env,
    jclass clazz,
    jobject config_provider,
    jstring strategy_config_json,
    jobject extra_strategies_list,
    jobject const_pool_list,
    jobject extra_const_pool_list,
    jboolean enable_debug,
    jlong const_pool_version,
    jint sample_rate);

// 0x00e400 (148 B): destroy -> nativeDestroy
JNIEXPORT void JNICALL destroy(JNIEnv* env, jclass clazz);

// 0x00e494 (1332 B): validate -> nativeValidate
JNIEXPORT jobject JNICALL validate(
    JNIEnv* env,
    jclass clazz,
    jstring trigger_id,
    jstring source,
    jobject param_provider,
    jobject async_callback);

// 0x00f8ec (764 B): isInNameList -> nativeIsInNameList
JNIEXPORT jobject JNICALL isInNameList(
    JNIEnv* env,
    jclass clazz,
    jstring param_value,
    jstring name_list_key,
    jboolean strict_ready);

// 0x00fc7c (4 B): update -> nativeUpdateConfig
JNIEXPORT void JNICALL update(JNIEnv* env, jclass clazz, jstring config_str);

// 0x00fc80 (20 B): isActivated -> nativeIsActivated
JNIEXPORT jboolean JNICALL isActivated(JNIEnv* env, jclass clazz);

// 0x00fc94 (192 B): getStrategyVersion -> nativeGetStrategyVersion
JNIEXPORT jint JNICALL getStrategyVersion(JNIEnv* env, jclass clazz);

// 0x00fd54 (8 B): getGetConstPoolVersion -> nativeGetConstPoolVersion
JNIEXPORT jlong JNICALL getGetConstPoolVersion(JNIEnv* env, jclass clazz);

// 0x00fd5c (360 B): loadConstPoolExtra -> nativeLoadConstPoolExtra
JNIEXPORT void JNICALL loadConstPoolExtra(JNIEnv* env, jclass clazz, jobject extra_json_list);

} // extern "C"

#endif // NEXTAI_OPENCUT_PNS_TTMACHINE_RULE_ENGINE_H_
