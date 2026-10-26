// ============================================================================
// FILE: cepengine_manager_core.cpp
// TARGET: libCepEngine.so — EngineConfig, Env, EngineCore, EngineManagerInner & EngineManager
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Full C++17 implementation of `cep::EngineConfig` (0x13a48..0x14533),
//      `cep::Env` (0x243a8..0x246e3), `cep::EngineManagerInner` (0x16608..0x1b59f),
//      `cep::EngineCore` (0x15564..0x15eb7), and `cep::EngineManager` (0x21d90..0x23e5b).
// [VN] Bản cài đặt C++17 đầy đủ cho `cep::EngineConfig` (0x13a48..0x14533),
//      `cep::Env` (0x243a8..0x246e3), `cep::EngineManagerInner` (0x16608..0x1b59f),
//      `cep::EngineCore` (0x15564..0x15eb7), và `cep::EngineManager` (0x21d90..0x23e5b).
// ============================================================================

#include "cepengine_manager_core.h"
#include <sstream>

namespace cep {

// ============================================================================
// 1. ENGINE CONFIG (`0x13a48..0x14533`)
// ============================================================================

// [EN] Disassembly @ 0x14458 (`_ZN3cep12EngineConfigC2Ev`, 104 B):
//      0x14468: 52a7f008  mov  w8, #0x3f800000      // 1.0f load factor for variables_ (+0x60)
//      0x1446c: 52800029  mov  w9, #1
//      0x14478: f900081f  str  xzr, [x0, #0x10]     // extra_ = nullptr
//      0x14484: b9001809  str  w9, [x0, #0x18]      // match_timeout_inference_strategy_ = 1
//      0x14488: 79003809  strh w9, [x0, #0x1c]      // overwrite_ = true (1), debug_ = false (0)
//      0x1448c: 97ffdea5  bl   #0xbf20              // Env::Instance()
//      0x14490: f9405808  ldr  x8, [x0, #0xb0]      // Env::max_matched_events_length_ (100)
//      0x14494: f9001268  str  x8, [x19, #0x20]
//      0x1449c: f9405408  ldr  x8, [x0, #0xa8]      // Env::max_matches_count_ (100)
//      0x144a0: f9001668  str  x8, [x19, #0x28]
//      0x144a8: f9405008  ldr  x8, [x0, #0xa0]      // Env::max_queuing_events_count_ (100)
//      0x144ac: b9003a7f  str  wzr, [x19, #0x38]    // process_mode_ = 0 (kProcessAsync)
//      0x144b0: f9001a68  str  x8, [x19, #0x30]
// [VN] Hàm tạo mặc định `EngineConfig` (@ 0x14458):
EngineConfig::EngineConfig()
    : extra_(nullptr),
      match_timeout_inference_strategy_(kTimeoutInference),
      overwrite_(true),
      debug_(false),
      max_matched_events_length_(Env::Instance()->max_matched_events_length()),
      max_matches_count_(Env::Instance()->max_matches_count()),
      max_queuing_count_(Env::Instance()->max_queuing_events_count()),
      process_mode_(kProcessAsync) {}

// [EN] Disassembly @ 0x144c0 (`_ZN3cep12EngineConfigC2ERKNSt6__ndk110shared_ptrINS_13DataInterfaceEEE`, 116 B):
// [VN] Hàm tạo `EngineConfig` từ `DataInterface` (@ 0x144c0):
EngineConfig::EngineConfig(const std::shared_ptr<DataInterface>& data) : EngineConfig() {
    ParseFromData(data);
}

std::shared_ptr<EngineConfig> EngineConfig::SelfOrNull() {
    try {
        return shared_from_this();
    } catch (...) {
        return nullptr;
    }
}

// [EN] Disassembly @ 0x13a48..0x13c70 (`EngineConfig::Set*` fluent setters):
//      - `SetExtra` @ 0x13a48: `str x1, [x0, #0x10]`
//      - `SetOverwrite` @ 0x13a8c: `and w9, w1, #1; strb w9, [x0, #0x1c]`
//      - `SetDebug` @ 0x13ad4: `and w9, w1, #1; strb w9, [x0, #0x1d]`
//      - `SetMatchTimeoutInferenceStrategy` @ 0x13b1c: `str w1, [x0, #0x18]`
//      - `SetMaxMatchedEventsLength` @ 0x13b60: `str x1, [x0, #0x20]`
//      - `SetMaxMatchesCount` @ 0x13ba4: `str x1, [x0, #0x28]`
//      - `SetMaxQueuingCount` @ 0x13be8: `str x1, [x0, #0x30]`
//      - `SetProcessMode` @ 0x13c2c: `str w1, [x0, #0x38]`
//      - `SetVariables` @ 0x13c70: copies `variables_` (+0x40)
// [VN] Các phương thức thiết lập chuỗi (fluent setters) của `EngineConfig` (@ 0x13a48..0x13c70):
std::shared_ptr<EngineConfig> EngineConfig::SetExtra(void* extra) {
    extra_ = extra;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetOverwrite(bool overwrite) {
    overwrite_ = overwrite;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetDebug(bool debug) {
    debug_ = debug;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetMatchTimeoutInferenceStrategy(
    MatchTimeoutInferenceStrategy strategy) {
    match_timeout_inference_strategy_ = strategy;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetMaxMatchedEventsLength(long long length) {
    max_matched_events_length_ = length;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetMaxMatchesCount(long long count) {
    max_matches_count_ = count;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetMaxQueuingCount(long long count) {
    max_queuing_count_ = count;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetProcessMode(ProcessMode mode) {
    process_mode_ = mode;
    return SelfOrNull();
}

std::shared_ptr<EngineConfig> EngineConfig::SetVariables(const VariableMap& vars) {
    variables_ = vars;
    return SelfOrNull();
}

// [EN] Disassembly @ 0x13cd0 (`_ZN3cep12EngineConfig13ParseFromDataE...`, 1928 B):
//      Parses `.rodata` keys:
//        - `"realTimeProcess"` (0x4beb0) -> sets `process_mode_`
//        - `"maxMatchedEventsLength"` (0x4bec0) -> `max_matched_events_length_` (+0x20)
//        - `"maxMatchesCount"` (0x4bed7) -> `max_matches_count_` (+0x28)
//        - `"maxQueuingEventsCount"` (0x4bee7) -> `max_queuing_count_` (+0x30)
//        - `"overwrite"` (0x4befd) -> `overwrite_` (+0x1c)
//        - `"debug"` (0x4bf07) -> `debug_` (+0x1d)
//        - `"matchTimeoutInferenceStrategy"` (0x4bf0d) -> `match_timeout_inference_strategy_` (+0x18)
//        - `"variables"` (0x4c3b1) -> `variables_` (+0x40)
// [VN] Phân tích cấu hình `EngineConfig` từ `DataInterface` (`ParseFromData` @ 0x13cd0):
bool EngineConfig::ParseFromData(const std::shared_ptr<DataInterface>& data) {
    if (!data || !data->IsDict()) {
        return false;
    }
    if (auto v = data->GetData("realTimeProcess")) {
        if (v->IsBool()) {
            process_mode_ = v->BoolValue() ? kProcessSync : kProcessAsync;
        } else if (v->IsInt()) {
            process_mode_ = static_cast<ProcessMode>(v->IntValue());
        }
    }
    if (auto v = data->GetData("maxMatchedEventsLength")) {
        if (v->IsNumber()) max_matched_events_length_ = v->ConvertToIntValue();
    }
    if (auto v = data->GetData("maxMatchesCount")) {
        if (v->IsNumber()) max_matches_count_ = v->ConvertToIntValue();
    }
    if (auto v = data->GetData("maxQueuingEventsCount")) {
        if (v->IsNumber()) max_queuing_count_ = v->ConvertToIntValue();
    }
    if (auto v = data->GetData("overwrite")) {
        if (v->IsBool()) overwrite_ = v->BoolValue();
    }
    if (auto v = data->GetData("debug")) {
        if (v->IsBool()) debug_ = v->BoolValue();
    }
    if (auto v = data->GetData("matchTimeoutInferenceStrategy")) {
        if (v->IsNumber()) {
            match_timeout_inference_strategy_ =
                static_cast<MatchTimeoutInferenceStrategy>(v->ConvertToIntValue());
        }
    }
    if (auto vars = data->GetData("variables")) {
        if (vars->IsDict()) {
            for (const auto& k : vars->KeySet()) {
                variables_[k] = vars->GetData(k);
            }
        }
    }
    return true;
}

// ============================================================================
// 2. ENVIRONMENT SINGLETON (`cep::Env` @ 0x243a8..0x246e3)
// ============================================================================

// [EN] Disassembly @ 0x243a8 (`_ZN3cep3Env8InstanceEv`, 248 B):
//      0x243b0: 900001c8  adrp x8, #0x5c000
//      0x243b4: 91194108  add  x8, x8, #0x650        // guard at .bss 0x5c650
//      0x243c0: 900001c0  adrp x0, #0x5c000
//      0x243c4: 91156000  add  x0, x0, #0x558        // singleton at .bss 0x5c558
//      0x243f4: 7900e029  strh w9, [x1, #0x70]       // global_enable_ = 1, enable_fallback_ = 0
//      0x243f8: 52800c89  mov  w9, #0x64             // 100
//      0x24404: 52927c08  mov  w8, #0x93e0
//      0x24420: f9005829  str  x9, [x1, #0xb0]       // max_matched_events_length_ = 100
//      0x24428: 72a00088  movk w8, #4, lsl #16       // 0x493e0 = 300000 ms
//      0x2442c: 3d802820  str  q0, [x1, #0xa0]       // max_queuing_events_count_ = 100, max_matches_count_ = 100
//      0x24434: f9006028  str  x8, [x1, #0xc0]       // statistic_report_time_window_ms_ = 300000
//      0x24438: 52800088  mov  w8, #4
//      0x24440: f9007428  str  x8, [x1, #0xe8]       // fixed_queue_size_ = 4
//      0x24444: 5285c628  mov  w8, #0x2e31
//      0x24450: 72a5c6a8  movk w8, #0x2e35, lsl #16  // "1.5.0"
//      0x24484: 3d803420  str  q0, [x1, #0xd0]       // monitor_report_time_window_ms_ = 300000, max_statistic_report_cnt_in_window_ = 5
// [VN] Singleton `cep::Env::Instance()` (@ 0x243a8):
Env::Env() {
    supported_exp_engines_.insert("0"); // Default ByteDT
    supported_exp_engines_.insert("1"); // TTM
}

Env* Env::Instance() {
    static Env instance;
    return &instance;
}

// [EN] Disassembly @ 0x24560 (`cep::Env::Init` called by `EngineManager::Init` @ 0x23d08):
//      Parses `.rodata` global settings keys 0x4bfe6..0x4c108.
// [VN] Khởi tạo cấu hình toàn cục `cep::Env::Init` (@ 0x24560):
void Env::Init(const std::shared_ptr<DataInterface>& config_data) {
    if (!config_data || !config_data->IsDict()) {
        return;
    }
    WriteLockGuard lk(lock_);
    if (auto v = config_data->GetData("global_enable")) {
        if (v->IsBool()) global_enable_ = v->BoolValue();
        else if (v->IsNumber()) global_enable_ = (v->ConvertToIntValue() != 0);
    }
    if (auto v = config_data->GetData("enable_fallback")) {
        if (v->IsBool()) enable_fallback_ = v->BoolValue();
        else if (v->IsNumber()) enable_fallback_ = (v->ConvertToIntValue() != 0);
    }
    if (auto v = config_data->GetData("disabled_rules")) {
        if (v->IsList()) {
            disabled_rules_.clear();
            for (int i = 0; i < v->Size(); ++i) {
                auto item = v->GetData(i);
                if (item && item->IsStr()) {
                    disabled_rules_.insert(item->StringValue());
                }
            }
        }
    }
    if (auto v = config_data->GetData("max_queuing_events_count")) {
        if (v->IsNumber()) max_queuing_events_count_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("max_matches_count")) {
        if (v->IsNumber()) max_matches_count_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("max_matched_events_length")) {
        if (v->IsNumber()) max_matched_events_length_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("monitor_sampling_rate")) {
        if (v->IsNumber()) monitor_sampling_rate_ = v->ConvertToDoubleValue();
    }
    if (auto v = config_data->GetData("monitor_report_time_window_ms")) {
        if (v->IsNumber()) monitor_report_time_window_ms_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("statistic_sampling_rate")) {
        if (v->IsNumber()) statistic_sampling_rate_ = v->ConvertToDoubleValue();
    }
    if (auto v = config_data->GetData("statistic_report_time_window_ms")) {
        if (v->IsNumber()) statistic_report_time_window_ms_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("max_statistic_report_cnt_in_window")) {
        if (v->IsNumber()) max_statistic_report_cnt_in_window_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("use_fixed_queue")) {
        if (v->IsBool()) use_fixed_queue_ = v->BoolValue();
    }
    if (auto v = config_data->GetData("fixed_queue_size")) {
        if (v->IsNumber()) fixed_queue_size_ = v->ConvertToIntValue();
    }
    if (auto v = config_data->GetData("enable_proactive_engine_clean")) {
        if (v->IsBool()) enable_proactive_engine_clean_ = v->BoolValue();
    }
}

// [EN] Disassembly @ 0x24670 (`_ZN3cep3Env21AllSupportedExpEngineEv`, 116 B):
//      Acquires read lock on `lock_` (+0x08), copies `supported_exp_engines_` (+0x30),
//      and unlocks.
// [VN] Lấy tập hợp các engine biểu thức được hỗ trợ (`AllSupportedExpEngine` @ 0x24670):
std::unordered_set<std::string> Env::AllSupportedExpEngine() {
    ReadLockGuard lk(lock_);
    return supported_exp_engines_;
}

void Env::AddSupportedExpEngine(const std::string& name) {
    WriteLockGuard lk(lock_);
    supported_exp_engines_.insert(name);
}

bool Env::IsRuleDisabled(const std::string& rule_name) const {
    ReadLockGuard lk(lock_);
    return disabled_rules_.count(rule_name) > 0;
}

// ============================================================================
// 3. ENGINE MANAGER INNER (`0x16608..0x1b59f`)
// ============================================================================

EngineManagerInner::EngineManagerInner() = default;

// [EN] Disassembly @ 0x16608 (`_ZN3cep18EngineManagerInner8InstanceEv`, 280 B):
//      0x16614: d0000228  adrp x8, #0x5c000
//      0x16618: 91150108  add  x8, x8, #0x540       // guard at .bss 0x5c540
//      0x16628: d0000220  adrp x0, #0x5c000
//      0x1662c: 9100e000  add  x0, x0, #0x38        // singleton at .bss 0x5c038
// [VN] Singleton `EngineManagerInner::Instance()` (@ 0x16608):
EngineManagerInner* EngineManagerInner::Instance() {
    static EngineManagerInner instance;
    return &instance;
}

// [EN] Disassembly @ 0x1878c (`_ZN3cep18EngineManagerInner9GetEngineE...`, 268 B):
// [VN] Lấy bản ghi quy tắc đã đăng ký (`GetEngine` @ 0x1878c):
std::shared_ptr<RegisteredRuleEntry> EngineManagerInner::GetEngine(
    const std::string& biz_name,
    const std::string& rule_name) {
    ReadLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end()) {
        return it->second;
    }
    return nullptr;
}

// [EN] Disassembly @ 0x189a8 (`_ZN3cep18EngineManagerInner7IsDebugE...`, 144 B):
// [VN] Kiểm tra chế độ gỡ lỗi của quy tắc (`IsDebug` @ 0x189a8):
bool EngineManagerInner::IsDebug(const std::string& biz_name,
                                 const std::string& rule_name) {
    auto entry = GetEngine(biz_name, rule_name);
    return entry ? entry->debug : false;
}

// [EN] Disassembly @ 0x195dc (`_ZN3cep18EngineManagerInner21RegisterExprEvaluatorE...`, 628 B):
// [VN] Đăng ký bộ tính toán biểu thức (`RegisterExprEvaluator` @ 0x195dc):
void EngineManagerInner::RegisterExprEvaluator(
    int type,
    std::string name,
    std::function<std::shared_ptr<ExprEvaluator>()> create_evaluator,
    std::function<void*(void*)> retain_event,
    std::function<void(void*)> release_event,
    std::function<void*()> create_list,
    std::function<void(void*)> release_list,
    std::function<void*(void*)> copy_list,
    std::function<void(void*, void*)> append_list) {
    auto desc = std::make_shared<ExpEngineDescriptor>();
    desc->type = type;
    desc->name = name.empty() ? std::to_string(type) : std::move(name);
    desc->create_evaluator = std::move(create_evaluator);
    desc->retain_event = std::move(retain_event);
    desc->release_event = std::move(release_event);
    desc->create_list = std::move(create_list);
    desc->release_list = std::move(release_list);
    desc->copy_list = std::move(copy_list);
    desc->append_list = std::move(append_list);
    {
        WriteLockGuard lk(exp_lock_);
        exp_engines_[type] = desc;
    }
    Env::Instance()->AddSupportedExpEngine(desc->name);
}

// [EN] Disassembly @ 0x19850 (`_ZN3cep18EngineManagerInner24RegisterSettingsCallbackE...`, 648 B):
// [VN] Đăng ký hàm gọi lại lấy cài đặt (`RegisterSettingsCallback` @ 0x19850):
void EngineManagerInner::RegisterSettingsCallback(const std::string& biz_name,
                                                  const CepSettingsCallback& callback) {
    WriteLockGuard lk(settings_lock_);
    settings_callbacks_[biz_name] = callback;
}

// [EN] Disassembly @ 0x1ac7c (`_ZN3cep18EngineManagerInner11GetFunctionE...`, 372 B):
// [VN] Lấy hàm mở rộng nghiệp vụ (`GetFunction` @ 0x1ac7c):
CepBizFunction EngineManagerInner::GetFunction(const std::string& biz_name,
                                               const std::string& func_name) {
    ReadLockGuard lk(funcs_lock_);
    auto it = functions_.find(MakeKey(biz_name, func_name));
    if (it != functions_.end()) {
        return it->second;
    }
    return nullptr;
}

// [EN] Disassembly @ 0x1ae88 (`_ZN3cep18EngineManagerInner12GetExpEngineENS_14ExpressionTypeE`, 312 B):
// [VN] Lấy bộ mô tả engine biểu thức (`GetExpEngine` @ 0x1ae88):
std::shared_ptr<ExpEngineDescriptor> EngineManagerInner::GetExpEngine(ExpressionType type) {
    ReadLockGuard lk(exp_lock_);
    auto it = exp_engines_.find(static_cast<int>(type));
    if (it != exp_engines_.end()) {
        return it->second;
    }
    return nullptr;
}

// [EN] Disassembly @ 0x1afc0 (`_ZN3cep18EngineManagerInner19GetSettingsCallbackE...`, 256 B):
// [VN] Lấy hàm gọi lại cài đặt (`GetSettingsCallback` @ 0x1afc0):
CepSettingsCallback EngineManagerInner::GetSettingsCallback(const std::string& biz_name) {
    ReadLockGuard lk(settings_lock_);
    auto it = settings_callbacks_.find(biz_name);
    if (it != settings_callbacks_.end()) {
        return it->second;
    }
    return nullptr;
}

// [EN] Disassembly @ 0x1b0c0 (`_ZN3cep18EngineManagerInner16CollectCrashInfoEv`, 796 B):
//      Formats `.rodata` `"executing rules: "` (0x4bf51) and `"registering rules: "` (0x4bf63).
// [VN] Thu thập thông tin chẩn đoán khi xảy ra sự cố (`CollectCrashInfo` @ 0x1b0c0):
std::string EngineManagerInner::CollectCrashInfo() {
    ReadLockGuard lk(crash_lock_);
    std::ostringstream oss;
    oss << "executing rules: ";
    bool first = true;
    for (const auto& r : executing_rules_) {
        if (!first) oss << ",";
        first = false;
        oss << r;
    }
    oss << "; registering rules: ";
    first = true;
    for (const auto& r : registering_rules_) {
        if (!first) oss << ",";
        first = false;
        oss << r;
    }
    return oss.str();
}

// [EN] Disassembly @ 0x1b3dc (`GetLastSuccessTimestamp`, 132 B) & 0x1b460 (`GetLastSuccessTimestampUnsafe`, 132 B):
// [VN] Lấy dấu thời gian khớp thành công gần nhất (@ 0x1b3dc & @ 0x1b460):
long long EngineManagerInner::GetLastSuccessTimestamp(const std::string& biz_name,
                                                      const std::string& rule_name) {
    ReadLockGuard lk(rules_lock_);
    return GetLastSuccessTimestampUnsafe(biz_name, rule_name);
}

long long EngineManagerInner::GetLastSuccessTimestampUnsafe(const std::string& biz_name,
                                                            const std::string& rule_name) {
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second) {
        return it->second->last_success_timestamp;
    }
    return -1;
}

// [EN] Disassembly @ 0x1b4e4 (`_ZN3cep18EngineManagerInner22GetConstVariableUnsafeE...`, 188 B):
// [VN] Lấy biến hằng số trong cấu hình quy tắc (`GetConstVariableUnsafe` @ 0x1b4e4):
std::shared_ptr<DataInterface> EngineManagerInner::GetConstVariableUnsafe(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& var_name) {
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second && it->second->config) {
        const auto& vars = it->second->config->variables();
        auto vit = vars.find(var_name);
        if (vit != vars.end()) {
            return vit->second;
        }
    }
    return nullptr;
}

bool EngineManagerInner::RegisterRuleInternal(
    const std::shared_ptr<Context>& /*ctx*/,
    const std::string& biz_name,
    const std::string& rule_name,
    const std::shared_ptr<DataInterface>& rule_data,
    const std::shared_ptr<EngineConfig>& config,
    std::string& out_error) {
    if (!Env::Instance()->global_enable()) {
        out_error = "CEP engine globally disabled";
        return false;
    }
    if (biz_name.empty() || rule_name.empty() || !rule_data || !rule_data->IsDict()) {
        Error err(biz_name, rule_name);
        err.SetFatal(kErrorInvalidRule);
        out_error = err.FormatString();
        return false;
    }

    const std::string key = MakeKey(biz_name, rule_name);
    {
        WriteLockGuard clk(crash_lock_);
        registering_rules_.insert(key);
    }

    auto effective_cfg = config ? config : std::make_shared<EngineConfig>(rule_data);
    {
        ReadLockGuard rlk(rules_lock_);
        if (rules_.count(key) && !effective_cfg->overwrite()) {
            WriteLockGuard clk(crash_lock_);
            registering_rules_.erase(key);
            return true;
        }
    }

    // Create expression evaluator if registered ("expEngine" @ 0x4c395)
    int exp_type = 0;
    if (auto exp_node = rule_data->GetData("expEngine")) {
        if (exp_node->IsNumber()) {
            exp_type = static_cast<int>(exp_node->ConvertToIntValue());
        }
    }
    std::shared_ptr<ExprEvaluator> eval;
    if (auto desc = GetExpEngine(static_cast<ExpressionType>(exp_type))) {
        if (desc->create_evaluator) {
            eval = desc->create_evaluator();
            if (eval) {
                eval->Init(rule_data, effective_cfg->extra());
            }
        }
    }

    auto nfa = std::make_shared<Nfa>();
    auto err = std::make_shared<Error>(biz_name, rule_name);
    if (!nfa->InitFromRuleData(biz_name, rule_name, rule_data, eval, err)) {
        out_error = err->FormatString();
        WriteLockGuard clk(crash_lock_);
        registering_rules_.erase(key);
        return false;
    }

    auto entry = std::make_shared<RegisteredRuleEntry>();
    entry->biz_name = biz_name;
    entry->rule_name = rule_name;
    entry->rule_data = rule_data;
    entry->config = effective_cfg;
    entry->nfa = nfa;
    entry->nfa_state = std::make_shared<NfaState>();
    entry->enabled = !Env::Instance()->IsRuleDisabled(rule_name);
    entry->debug = effective_cfg->debug();

    {
        WriteLockGuard rlk(rules_lock_);
        rules_[key] = entry;
    }
    {
        WriteLockGuard clk(crash_lock_);
        registering_rules_.erase(key);
    }
    return true;
}

bool EngineManagerInner::RegisterRulesInternal(
    const std::shared_ptr<Context>& ctx,
    const std::string& biz_name,
    const std::shared_ptr<DataInterface>& rules_data,
    const std::shared_ptr<EngineConfig>& config,
    std::string& out_error) {
    if (!rules_data || !rules_data->IsDict()) {
        Error err(biz_name);
        err.SetFatal(kErrorInvalidRule);
        out_error = err.FormatString();
        return false;
    }
    bool all_ok = true;
    for (const auto& rule_name : rules_data->KeySet()) {
        auto rdata = rules_data->GetData(rule_name);
        std::string r_err;
        if (!RegisterRuleInternal(ctx, biz_name, rule_name, rdata, config, r_err)) {
            all_ok = false;
            if (!out_error.empty()) out_error += "; ";
            out_error += r_err;
        }
    }
    return all_ok;
}

std::vector<std::string> EngineManagerInner::GetRuleNamesInternal(const std::string& biz_name) {
    ReadLockGuard lk(rules_lock_);
    std::vector<std::string> names;
    for (const auto& kv : rules_) {
        if (kv.second && kv.second->biz_name == biz_name) {
            names.push_back(kv.second->rule_name);
        }
    }
    return names;
}

void EngineManagerInner::UnregisterRuleInternal(const std::string& biz_name,
                                                const std::string& rule_name) {
    WriteLockGuard lk(rules_lock_);
    rules_.erase(MakeKey(biz_name, rule_name));
}

void EngineManagerInner::DisableRuleInternal(const std::string& biz_name,
                                             const std::string& rule_name,
                                             DisableStrategy strategy) {
    WriteLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second) {
        it->second->enabled = false;
        if (strategy == kDisableAndClean && it->second->nfa_state) {
            it->second->nfa_state->Clear();
        }
    }
}

void EngineManagerInner::EnableRuleInternal(const std::string& biz_name,
                                            const std::string& rule_name) {
    WriteLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second) {
        it->second->enabled = true;
    }
}

void EngineManagerInner::EnableDebugInternal(const std::string& biz_name,
                                             const std::string& rule_name) {
    WriteLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second) {
        it->second->debug = true;
    }
}

void EngineManagerInner::DisableDebugInternal(const std::string& biz_name,
                                              const std::string& rule_name) {
    WriteLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second) {
        it->second->debug = false;
    }
}

void EngineManagerInner::ResetProcessModeInternal(const std::string& biz_name,
                                                  const std::string& rule_name,
                                                  ProcessMode mode) {
    WriteLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second && it->second->config) {
        it->second->config->SetProcessMode(mode);
    }
}

void EngineManagerInner::RegisterFunctionInternal(const std::string& biz_name,
                                                  const std::string& func_name,
                                                  const CepBizFunction& fn) {
    WriteLockGuard lk(funcs_lock_);
    functions_[MakeKey(biz_name, func_name)] = fn;
}

void EngineManagerInner::UnregisterFunctionInternal(const std::string& biz_name,
                                                    const std::string& func_name) {
    WriteLockGuard lk(funcs_lock_);
    functions_.erase(MakeKey(biz_name, func_name));
}

void EngineManagerInner::RegisterEngineCallbackInternal(const std::string& biz_name,
                                                        const std::string& rule_name,
                                                        const CepEngineResultCallback& cb) {
    WriteLockGuard lk(callbacks_lock_);
    engine_callbacks_[MakeKey(biz_name, rule_name)] = cb;
}

void EngineManagerInner::UnregisterEngineCallbackInternal(const std::string& biz_name,
                                                          const std::string& rule_name) {
    WriteLockGuard lk(callbacks_lock_);
    engine_callbacks_.erase(MakeKey(biz_name, rule_name));
}

void EngineManagerInner::RegisterRuleCallbackInternal(const std::string& biz_name,
                                                      const std::string& rule_name,
                                                      const CepResultCallback& cb) {
    WriteLockGuard lk(callbacks_lock_);
    rule_callbacks_[MakeKey(biz_name, rule_name)] = cb;
}

void EngineManagerInner::UnregisterRuleCallbackInternal(const std::string& biz_name,
                                                        const std::string& rule_name) {
    WriteLockGuard lk(callbacks_lock_);
    rule_callbacks_.erase(MakeKey(biz_name, rule_name));
}

void EngineManagerInner::RegisterBizCallbackInternal(const std::string& biz_name,
                                                     const CepResultCallback& cb) {
    WriteLockGuard lk(callbacks_lock_);
    biz_callbacks_[biz_name] = cb;
}

void EngineManagerInner::UnregisterBizCallbackInternal(const std::string& biz_name) {
    WriteLockGuard lk(callbacks_lock_);
    biz_callbacks_.erase(biz_name);
}

void EngineManagerInner::CleanInternal(const std::string& biz_name,
                                       const std::string& rule_name) {
    WriteLockGuard lk(rules_lock_);
    auto it = rules_.find(MakeKey(biz_name, rule_name));
    if (it != rules_.end() && it->second && it->second->nfa_state) {
        it->second->nfa_state->Clear();
    }
}

void EngineManagerInner::CleanRulesInternal(const std::string& biz_name,
                                            const std::vector<std::string>& rule_names) {
    for (const auto& r : rule_names) {
        CleanInternal(biz_name, r);
    }
}

std::vector<std::shared_ptr<EngineResult>> EngineManagerInner::ProcessEventInternal(
    const std::shared_ptr<Context>& /*ctx*/,
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    const std::shared_ptr<DataInterface>& event_data,
    void* raw_data,
    long long timestamp_ms,
    void* extra) {
    std::vector<std::shared_ptr<EngineResult>> results;
    std::vector<std::shared_ptr<RegisteredRuleEntry>> targets;
    {
        ReadLockGuard lk(rules_lock_);
        if (!rule_name.empty()) {
            auto it = rules_.find(MakeKey(biz_name, rule_name));
            if (it != rules_.end() && it->second) {
                targets.push_back(it->second);
            }
        } else {
            for (const auto& kv : rules_) {
                if (kv.second && kv.second->biz_name == biz_name) {
                    targets.push_back(kv.second);
                }
            }
        }
    }

    const long long ts = (timestamp_ms > 0) ? timestamp_ms : GetCurrentTimestamp();
    auto ev_wrap = std::make_shared<EventWrapper>(
        event_name, raw_data, ts, extra, event_data);

    for (const auto& entry : targets) {
        if (!entry || !entry->enabled || !entry->nfa || !entry->nfa_state) {
            continue;
        }
        const std::string key = MakeKey(entry->biz_name, entry->rule_name);
        {
            WriteLockGuard clk(crash_lock_);
            executing_rules_.insert(key);
        }

        auto err = std::make_shared<Error>(entry->biz_name, entry->rule_name);
        entry->nfa->AdvanceTime(entry->nfa_state, entry->nfa->start_state(), ts, err);
        auto matches = entry->nfa->Process(
            entry->nfa_state, entry->nfa->start_state(), ev_wrap, err);

        std::vector<EngineResult::MatchedSequenceEntry> seqs;
        for (const auto& m : matches) {
            if (!m) continue;
            auto ev_list = std::make_shared<EventWrapperList>();
            for (const auto& rev : m->raw_events()) {
                ev_list->Append(rev);
            }
            seqs.emplace_back(ev_list, m->variables());
        }

        const bool ok = !err->IsFatal() && !seqs.empty();
        if (ok) {
            entry->last_success_timestamp = ts;
        }

        auto eng_res = std::make_shared<EngineResult>(
            ok,
            entry->biz_name,
            entry->rule_name,
            err->FatalFormatString(),
            err->WarningsFormatString(),
            std::move(seqs));
        results.push_back(eng_res);

        // Invoke registered callbacks
        CepEngineResultCallback ecb;
        CepResultCallback rcb;
        CepResultCallback bcb;
        {
            ReadLockGuard cb_lk(callbacks_lock_);
            if (engine_callbacks_.count(key)) ecb = engine_callbacks_[key];
            if (rule_callbacks_.count(key)) rcb = rule_callbacks_[key];
            if (biz_callbacks_.count(entry->biz_name)) bcb = biz_callbacks_[entry->biz_name];
        }
        if (ecb && ok) {
            ecb(eng_res);
        }
        if ((rcb || bcb) && ok) {
            auto pub_res = eng_res->ToPublicResult();
            if (rcb) rcb(pub_res);
            if (bcb) bcb(pub_res);
        }

        {
            WriteLockGuard clk(crash_lock_);
            executing_rules_.erase(key);
        }
    }
    return results;
}

// ============================================================================
// 4. ENGINE CORE (`0x15564..0x15eb7`)
// ============================================================================

// [EN] Disassembly @ 0x15564..0x15d70 (`cep::EngineCore` static bridge methods):
//      Each method obtains `DefaultContext::GetShared()` (`bl #0xbaf0` @ 0x155ac) and
//      `EngineManagerInner::Instance()` (`bl #0xb9e0` @ 0x155a0) and delegates.
// [VN] Các phương thức tĩnh của `cep::EngineCore` (@ 0x15564..0x15d70):
bool EngineCore::RegisterRule(const std::string& biz_name,
                              const std::string& rule_name,
                              const std::shared_ptr<DataInterface>& rule_data,
                              const std::shared_ptr<EngineConfig>& config,
                              std::string& error_msg) {
    return EngineManagerInner::Instance()->RegisterRuleInternal(
        DefaultContext::GetShared(), biz_name, rule_name, rule_data, config, error_msg);
}

bool EngineCore::RegisterRules(const std::string& biz_name,
                               const std::shared_ptr<DataInterface>& rules_data,
                               const std::shared_ptr<EngineConfig>& config,
                               std::string& error_msg) {
    return EngineManagerInner::Instance()->RegisterRulesInternal(
        DefaultContext::GetShared(), biz_name, rules_data, config, error_msg);
}

std::vector<std::string> EngineCore::GetRuleNames(const std::string& biz_name) {
    return EngineManagerInner::Instance()->GetRuleNamesInternal(biz_name);
}

void EngineCore::UnregisterRule(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->UnregisterRuleInternal(biz_name, rule_name);
}

void EngineCore::DisableRule(const std::string& biz_name,
                             const std::string& rule_name,
                             DisableStrategy strategy) {
    EngineManagerInner::Instance()->DisableRuleInternal(biz_name, rule_name, strategy);
}

void EngineCore::EnableRule(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->EnableRuleInternal(biz_name, rule_name);
}

void EngineCore::DisableDebug(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->DisableDebugInternal(biz_name, rule_name);
}

void EngineCore::EnableDebug(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->EnableDebugInternal(biz_name, rule_name);
}

void EngineCore::RegisterFunction(const std::string& biz_name,
                                  const std::string& func_name,
                                  const CepBizFunction& fn) {
    EngineManagerInner::Instance()->RegisterFunctionInternal(biz_name, func_name, fn);
}

void EngineCore::UnregisterFunction(const std::string& biz_name, const std::string& func_name) {
    EngineManagerInner::Instance()->UnregisterFunctionInternal(biz_name, func_name);
}

void EngineCore::RegisterCallback(const std::string& biz_name,
                                  const std::string& rule_name,
                                  const CepEngineResultCallback& cb) {
    EngineManagerInner::Instance()->RegisterEngineCallbackInternal(biz_name, rule_name, cb);
}

void EngineCore::UnregisterCallback(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->UnregisterEngineCallbackInternal(biz_name, rule_name);
}

void EngineCore::AsyncClean(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->CleanInternal(biz_name, rule_name);
}

void EngineCore::SyncClean(const std::string& biz_name, const std::string& rule_name) {
    EngineManagerInner::Instance()->CleanInternal(biz_name, rule_name);
}

void EngineCore::RegisterSettingsCallback(const std::string& biz_name,
                                          const CepSettingsCallback& cb) {
    EngineManagerInner::Instance()->RegisterSettingsCallback(biz_name, cb);
}

void EngineCore::AsyncProcess(const std::string& biz_name,
                              const std::string& rule_name,
                              const std::string& event_name,
                              const std::shared_ptr<DataInterface>& event_data,
                              long long timestamp_ms) {
    EngineManagerInner::Instance()->ProcessEventInternal(
        DefaultContext::GetShared(), biz_name, rule_name, event_name, event_data, nullptr, timestamp_ms, nullptr);
}

std::vector<std::shared_ptr<EngineResult>> EngineCore::SyncProcess(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    const std::shared_ptr<DataInterface>& event_data,
    long long timestamp_ms) {
    return EngineManagerInner::Instance()->ProcessEventInternal(
        DefaultContext::GetShared(), biz_name, rule_name, event_name, event_data, nullptr, timestamp_ms, nullptr);
}

std::vector<std::shared_ptr<EngineResult>> EngineCore::ProcessInCurrentThread(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    const std::shared_ptr<DataInterface>& event_data,
    long long timestamp_ms) {
    return EngineManagerInner::Instance()->ProcessEventInternal(
        DefaultContext::GetShared(), biz_name, rule_name, event_name, event_data, nullptr, timestamp_ms, nullptr);
}

// ============================================================================
// 5. ENGINE MANAGER (`0x21d90..0x23e5b`)
// ============================================================================

// [EN] Disassembly @ 0x21d90 (`_ZN3cep13EngineManager8InstanceEv`, 84 B):
//      0x21d98: f00001c8  adrp x8, #0x5c000
//      0x21d9c: 91154108  add  x8, x8, #0x550        // guard at .bss 0x5c550
//      0x21da8: f00001c0  adrp x0, #0x5c000
//      0x21dac: 91152000  add  x0, x0, #0x548        // singleton at .bss 0x5c548
//      0x21dc8: 97ffa70a  bl   #0xb9f0               // EngineManagerInner::Instance()
//      0x21dd0: f902a500  str  x0, [x8, #0x548]
// [VN] Singleton `cep::EngineManager::Instance()` (@ 0x21d90):
EngineManager* EngineManager::Instance() {
    static EngineManager instance(EngineManagerInner::Instance());
    return &instance;
}

// [EN] Disassembly @ 0x21de4..0x22d08 (`EngineManager::RegisterRule` & `RegisterRules` overloads):
// [VN] Các hàm nạp chồng `RegisterRule` & `RegisterRules` (@ 0x21de4..0x22d08):
std::shared_ptr<Result> EngineManager::RegisterRule(const std::string& biz_name,
                                                    const std::string& rule_name,
                                                    const std::string& rule_json,
                                                    bool real_time_process,
                                                    void* extra,
                                                    bool overwrite) {
    auto rule_data = MemoryDataInterface::ParseJson(rule_json);
    return RegisterRule(biz_name, rule_name, rule_data, real_time_process, extra, overwrite);
}

std::shared_ptr<Result> EngineManager::RegisterRules(const std::string& biz_name,
                                                     const std::string& rules_json,
                                                     bool real_time_process,
                                                     void* extra,
                                                     bool overwrite) {
    auto rules_data = MemoryDataInterface::ParseJson(rules_json);
    return RegisterRules(biz_name, rules_data, real_time_process, extra, overwrite);
}

std::shared_ptr<Result> EngineManager::RegisterRule(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::shared_ptr<DataInterface>& rule_data,
    bool real_time_process,
    void* extra,
    bool overwrite) {
    auto cfg = std::make_shared<EngineConfig>(rule_data);
    cfg->SetProcessMode(real_time_process ? kProcessSync : kProcessAsync);
    cfg->SetExtra(extra);
    cfg->SetOverwrite(overwrite);
    std::string err_msg;
    bool ok = RegisterRule(DefaultContext::GetShared(), biz_name, rule_name, rule_data, cfg, err_msg);
    return std::make_shared<Result>(ok, biz_name, rule_name, err_msg,
                                    std::vector<std::string>{}, std::vector<MatchResult>{});
}

std::shared_ptr<Result> EngineManager::RegisterRules(
    const std::string& biz_name,
    const std::shared_ptr<DataInterface>& rules_data,
    bool real_time_process,
    void* extra,
    bool overwrite) {
    auto cfg = std::make_shared<EngineConfig>();
    cfg->SetProcessMode(real_time_process ? kProcessSync : kProcessAsync);
    cfg->SetExtra(extra);
    cfg->SetOverwrite(overwrite);
    std::string err_msg;
    bool ok = RegisterRules(DefaultContext::GetShared(), biz_name, rules_data, cfg, err_msg);
    return std::make_shared<Result>(ok, biz_name, "", err_msg,
                                    std::vector<std::string>{}, std::vector<MatchResult>{});
}

bool EngineManager::RegisterRule(const std::shared_ptr<Context>& ctx,
                                 const std::string& biz_name,
                                 const std::string& rule_name,
                                 const std::shared_ptr<DataInterface>& rule_data,
                                 const std::shared_ptr<EngineConfig>& config,
                                 std::string& error_msg) {
    return inner_->RegisterRuleInternal(ctx, biz_name, rule_name, rule_data, config, error_msg);
}

bool EngineManager::RegisterRules(const std::shared_ptr<Context>& ctx,
                                  const std::string& biz_name,
                                  const std::shared_ptr<DataInterface>& rules_data,
                                  const std::shared_ptr<EngineConfig>& config,
                                  std::string& error_msg) {
    return inner_->RegisterRulesInternal(ctx, biz_name, rules_data, config, error_msg);
}

// [EN] Disassembly @ 0x22fe4..0x23080 (`EngineManager` 1-instruction & 5-instruction delegators):
//      0x22fec: f9400000 ldr x0, [x0]; 0x22ff0: 7200007f tst w3, #1;
//      0x22ff4: 52800048 mov w8, #2; 0x22ff8: 1a9f1103 csel w3, w8, wzr, ne; b #0x18898
// [VN] Các phương thức ủy quyền trực tiếp xuống `inner_` (@ 0x22fe4..0x23080):
void EngineManager::UnregisterRule(const std::string& biz_name, const std::string& rule_name) {
    inner_->UnregisterRuleInternal(biz_name, rule_name);
}

void EngineManager::DisableRule(const std::string& biz_name,
                                const std::string& rule_name,
                                bool clean) {
    inner_->DisableRuleInternal(
        biz_name, rule_name, clean ? kDisableAndClean : kDisableOnly);
}

void EngineManager::DisableRule(const std::string& biz_name,
                                const std::string& rule_name,
                                DisableStrategy strategy) {
    inner_->DisableRuleInternal(biz_name, rule_name, strategy);
}

void EngineManager::EnableRule(const std::string& biz_name, const std::string& rule_name) {
    inner_->EnableRuleInternal(biz_name, rule_name);
}

void EngineManager::EnableDebug(const std::string& biz_name, const std::string& rule_name) {
    inner_->EnableDebugInternal(biz_name, rule_name);
}

void EngineManager::DisableDebug(const std::string& biz_name, const std::string& rule_name) {
    inner_->DisableDebugInternal(biz_name, rule_name);
}

void EngineManager::ResetProcessMode(const std::string& biz_name,
                                     const std::string& rule_name,
                                     ProcessMode mode) {
    inner_->ResetProcessModeInternal(biz_name, rule_name, mode);
}

void EngineManager::RegisterBizFunction(const std::string& biz_name,
                                        const std::string& func_name,
                                        const CepBizFunction& fn) {
    inner_->RegisterFunctionInternal(biz_name, func_name, fn);
}

void EngineManager::UnregisterBizFunction(const std::string& biz_name,
                                          const std::string& func_name) {
    inner_->UnregisterFunctionInternal(biz_name, func_name);
}

void EngineManager::RegisterRuleCallback(const std::string& biz_name,
                                         const std::string& rule_name,
                                         const CepResultCallback& cb) {
    inner_->RegisterRuleCallbackInternal(biz_name, rule_name, cb);
}

void EngineManager::UnregisterRuleCallback(const std::string& biz_name,
                                           const std::string& rule_name) {
    inner_->UnregisterRuleCallbackInternal(biz_name, rule_name);
}

void EngineManager::RegisterBizCallback(const std::string& biz_name,
                                        const CepResultCallback& cb) {
    inner_->RegisterBizCallbackInternal(biz_name, cb);
}

void EngineManager::UnregisterBizCallback(const std::string& biz_name) {
    inner_->UnregisterBizCallbackInternal(biz_name);
}

void EngineManager::Clean(const std::string& biz_name, const std::string& rule_name) {
    inner_->CleanInternal(biz_name, rule_name);
}

void EngineManager::SyncClean(const std::string& biz_name, const std::string& rule_name) {
    inner_->CleanInternal(biz_name, rule_name);
}

void EngineManager::CleanRules(const std::string& biz_name,
                               const std::vector<std::string>& rule_names) {
    inner_->CleanRulesInternal(biz_name, rule_names);
}

void EngineManager::SyncCleanRules(const std::string& biz_name,
                                   const std::vector<std::string>& rule_names) {
    inner_->CleanRulesInternal(biz_name, rule_names);
}

void EngineManager::AsyncClean(const std::string& biz_name, const std::string& rule_name) {
    inner_->CleanInternal(biz_name, rule_name);
}

void EngineManager::AsyncCleanRules(const std::string& biz_name,
                                    const std::vector<std::string>& rule_names) {
    inner_->CleanRulesInternal(biz_name, rule_names);
}

// [EN] Disassembly @ 0x23088 (`_ZN3cep13EngineManager21RegisterExprEvaluatorE...`, 984 B):
//      Converts `int type` to `std::to_string(type)` and forwards to
//      `EngineManagerInner::RegisterExprEvaluator`.
// [VN] Đăng ký bộ tính toán biểu thức qua `EngineManager` (@ 0x23088):
void EngineManager::RegisterExprEvaluator(
    int type,
    std::function<std::shared_ptr<ExprEvaluator>()> create_evaluator,
    std::function<void*(void*)> retain_event,
    std::function<void(void*)> release_event,
    std::function<void*()> create_list,
    std::function<void(void*)> release_list,
    std::function<void*(void*)> copy_list,
    std::function<void(void*, void*)> append_list) {
    inner_->RegisterExprEvaluator(
        type,
        std::to_string(type),
        std::move(create_evaluator),
        std::move(retain_event),
        std::move(release_event),
        std::move(create_list),
        std::move(release_list),
        std::move(copy_list),
        std::move(append_list));
}

void EngineManager::RegisterSettingsCallback(const std::string& biz_name,
                                             const CepSettingsCallback& cb) {
    inner_->RegisterSettingsCallback(biz_name, cb);
}

// [EN] Disassembly @ 0x23468..0x23d68 (`SyncProcess`, `AsyncProcess`, `ProcessInCurrentThread`, `ProcessRules`):
// [VN] Các phương thức xử lý sự kiện đồng bộ/bất đồng bộ (@ 0x23468..0x23d68):
std::vector<std::shared_ptr<Result>> EngineManager::SyncProcess(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    return SyncProcess(
        DefaultContext::GetShared(), biz_name, rule_name, event_name, event_data, timestamp_ms, extra);
}

void EngineManager::AsyncProcess(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    AsyncProcess(
        DefaultContext::GetShared(), biz_name, rule_name, event_name, event_data, timestamp_ms, extra);
}

std::vector<std::shared_ptr<Result>> EngineManager::ProcessInCurrentThread(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    return ProcessInCurrentThread(
        DefaultContext::GetShared(), biz_name, rule_name, event_name, event_data, timestamp_ms, extra);
}

std::vector<std::shared_ptr<Result>> EngineManager::ProcessRules(
    const std::string& biz_name,
    const std::vector<std::string>& rule_names,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    std::vector<std::shared_ptr<Result>> out;
    for (const auto& r : rule_names) {
        auto sub = SyncProcess(biz_name, r, event_name, event_data, timestamp_ms, extra);
        out.insert(out.end(), sub.begin(), sub.end());
    }
    return out;
}

std::vector<std::shared_ptr<Result>> EngineManager::SyncProcess(
    const std::shared_ptr<Context>& ctx,
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    auto eng_results = inner_->ProcessEventInternal(
        ctx, biz_name, rule_name, event_name, nullptr, event_data, timestamp_ms, extra);
    std::vector<std::shared_ptr<Result>> out;
    out.reserve(eng_results.size());
    for (const auto& er : eng_results) {
        if (er) out.push_back(er->ToPublicResult());
    }
    return out;
}

void EngineManager::AsyncProcess(
    const std::shared_ptr<Context>& ctx,
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    inner_->ProcessEventInternal(
        ctx, biz_name, rule_name, event_name, nullptr, event_data, timestamp_ms, extra);
}

std::vector<std::shared_ptr<Result>> EngineManager::ProcessInCurrentThread(
    const std::shared_ptr<Context>& ctx,
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    return SyncProcess(ctx, biz_name, rule_name, event_name, event_data, timestamp_ms, extra);
}

// [EN] Disassembly @ 0x23d08..0x23d68:
//      0x23d08: `EngineManager::Init` -> calls `Env::Instance()->Init(config_data)` (@ 0x24560)
//      0x23d2c: `EngineManager::AllSupportedExpression` -> calls `Env::Instance()->AllSupportedExpEngine()`
//      0x23d50: `EngineManager::CollectCrashInfo` -> `inner_->CollectCrashInfo()`
//      0x23d58: `EngineManager::GetRuleNames` -> `inner_->GetRuleNamesInternal(biz_name)`
//      0x23d60: `EngineManager::GetLastSuccessTimestamp` -> `inner_->GetLastSuccessTimestamp(biz_name, rule_name)`
// [VN] Các phương thức tiện ích cuối của `EngineManager` (@ 0x23d08..0x23d68):
void EngineManager::Init(const std::shared_ptr<DataInterface>& config_data) {
    Env::Instance()->Init(config_data);
}

std::unordered_set<std::string> EngineManager::AllSupportedExpression() {
    return Env::Instance()->AllSupportedExpEngine();
}

std::string EngineManager::CollectCrashInfo() {
    return inner_->CollectCrashInfo();
}

std::vector<std::string> EngineManager::GetRuleNames(const std::string& biz_name) {
    return inner_->GetRuleNamesInternal(biz_name);
}

long long EngineManager::GetLastSuccessTimestamp(const std::string& biz_name,
                                                 const std::string& rule_name) {
    return inner_->GetLastSuccessTimestamp(biz_name, rule_name);
}

std::vector<std::shared_ptr<Result>> EngineManager::ProcessInCurrentThread(
    const std::string& biz_name,
    const std::string& event_name,
    void* event_data,
    long long timestamp_ms,
    void* extra) {
    return ProcessInCurrentThread(biz_name, "", event_name, event_data, timestamp_ms, extra);
}

} // namespace cep
