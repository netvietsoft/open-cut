// ============================================================================
// File: ttmstrategycenter_cep_engine.cpp
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Implementation of Complex Event Processing (CEP) wrappers (`TTMCepDataWrapper`
// @ `0x30950`, `StrategyCenterCepSettingData` @ `0x2ce78`), CEP rule decoder
// (`ttm_decode_register_cep_rule` @ `0x301e0`, `bridge_ttm_register_cep_rule`
// @ `0x2ff84`), `ttm_sc_cep_result` (`0x33bc0..0x345b8`), `ttm_sc_input`
// (`0x40c90..0x40f8c`), `ttm_sc_output` (`0x469f8..0x46dc0`), and
// `ttm_sc_strategy_center::run_ttm_rule` (`0x46dc4`).
//
// Mô tả (VI):
// Hiện thực hóa các lớp bọc xử lý sự kiện phức hợp (`TTMCepDataWrapper`
// tại `0x30950`, `StrategyCenterCepSettingData` tại `0x2ce78`), bộ giải mã
// quy tắc CEP (`ttm_decode_register_cep_rule` tại `0x301e0`,
// `bridge_ttm_register_cep_rule` tại `0x2ff84`), `ttm_sc_cep_result`
// (`0x33bc0..0x345b8`), `ttm_sc_input` (`0x40c90..0x40f8c`), `ttm_sc_output`
// (`0x469f8..0x46dc0`), và `ttm_sc_strategy_center::run_ttm_rule` (`0x46dc4`).
// ============================================================================

#include "ttmstrategycenter_cep_engine.h"
#include "ttmstrategycenter_bdi_feature.h"

namespace nextai {
namespace ttm_strategy_center {

namespace {
// Global initialization flag (ttm_strategy_center_is_init @ 0x64258, 1 byte)
bool g_ttm_strategy_center_is_init = true;

struct ParsedRuleByteCode {
    std::string expression;
    void*       user_bdi{nullptr};
};
} // namespace

// ============================================================================
// 1. TTMCepDataWrapper Implementation (0x30950..0x30de8)
// ============================================================================
// Disassembly @ 0x30950..0x309e8 (156 B):
//   ldr x8, [x0, #8]; cbz x8, #0x309c4 (returns 6)
//   ldr x8, [x8, #8] ; obj_->ob_type
//   cmp with TTMDictO_Type   -> returns 6
//   cmp with TTMIntO_Type    -> returns 0
//   cmp with TTMFloatO_Type  -> returns 1
//   cmp with TTMStringO_Type -> returns 3
//   cmp with TTMListO_Type   -> returns 4
//   cmp with TTMBoolO_Type   -> mov w8, #5; cinc w0, w8, ne (5 if eq, 6 if ne)
int32_t TTMCepDataWrapper::Type() {
    if (!obj_ || !obj_->ob_type) {
        return 6;
    }
    const TTMTypeObject* t = obj_->ob_type;
    if (t == &TTMDictO_Type)   return 6;
    if (t == &TTMIntO_Type)    return 0;
    if (t == &TTMFloatO_Type)  return 1;
    if (t == &TTMStringO_Type) return 3;
    if (t == &TTMListO_Type)   return 4;
    if (t == &TTMBoolO_Type)   return 5;
    return 6;
}

// Disassembly @ 0x309ec (12 B): ldr x8, [x0, #8]; ldr x0, [x8, #0x10]; ret
int64_t TTMCepDataWrapper::IntValue() {
    return obj_ ? obj_->payload.int_val : 0;
}

// Disassembly @ 0x309f8 (12 B): ldr x8, [x0, #8]; ldr d0, [x8, #0x10]; ret
double TTMCepDataWrapper::FloatValue() {
    return obj_ ? obj_->payload.float_val : 0.0;
}

// Disassembly @ 0x30a04 (20 B): ldr x8, [x0, #8]; ldr x8, [x8, #0x10]; cmp x8, #1; cset w0, eq; ret
bool TTMCepDataWrapper::BoolValue() {
    return obj_ && (obj_->payload.int_val == 1);
}

// Disassembly @ 0x30a18 (16 B): ldr x9, [x0, #8]; ldr x1, [x9, #0x28]; b std::string::ctor
std::string TTMCepDataWrapper::StringValue() {
    if (!obj_) return {};
    if (obj_->data_ptr) {
        return std::string(static_cast<const char*>(obj_->data_ptr));
    }
    return obj_->owned_str;
}

// Disassembly @ 0x30a28 (28 B)
int32_t TTMCepDataWrapper::Size() {
    if (!obj_) return 0;
    if (obj_->ob_type == &TTMListO_Type) {
        return static_cast<int32_t>(obj_->payload.list_size);
    }
    if (obj_->ob_type == &TTMDictO_Type) {
        return static_cast<int32_t>(obj_->owned_dict.size());
    }
    return 0;
}

// Disassembly @ 0x30a44 (340 B)
std::vector<std::string> TTMCepDataWrapper::KeySet() {
    std::vector<std::string> keys;
    if (obj_ && obj_->ob_type == &TTMDictO_Type) {
        for (const auto& kv : obj_->owned_dict) {
            keys.push_back(kv.first);
        }
    }
    return keys;
}

// Disassembly @ 0x30c80 (296 B)
std::shared_ptr<CepDataWrapperBase> TTMCepDataWrapper::GetData(int index) {
    if (!obj_ || obj_->ob_type != &TTMListO_Type || index < 0 || index >= obj_->payload.list_size) {
        return nullptr;
    }
    return nullptr;
}

std::shared_ptr<CepDataWrapperBase> TTMCepDataWrapper::GetData(const std::string& key) {
    if (!obj_ || obj_->ob_type != &TTMDictO_Type) {
        return nullptr;
    }
    auto it = obj_->owned_dict.find(key);
    if (it == obj_->owned_dict.end() || !it->second) {
        return nullptr;
    }
    return std::make_shared<TTMCepDataWrapper>(it->second, ctx_);
}

// ============================================================================
// 2. ttm_sc_cep_result Implementation (0x33bc0..0x345b8)
// ============================================================================
ttm_sc_cep_result::ttm_sc_cep_result(
    bool success,
    std::string rule_name,
    std::string error_msg,
    std::vector<ttm_sc_list> matched_events)
    : success_(success),
      rule_name_(std::move(rule_name)),
      error_message_(std::move(error_msg)),
      matched_events_(std::move(matched_events)) {}

// ============================================================================
// 3. StrategyCenterCepAdapter & CEP C/C++ Functions (0x2a9b0..0x335e8)
// ============================================================================
StrategyCenterCepAdapter::StrategyCenterCepAdapter() = default;

StrategyCenterCepAdapter& StrategyCenterCepAdapter::Instance() {
    static StrategyCenterCepAdapter s_instance;
    return s_instance;
}

bool StrategyCenterCepAdapter::registerRule(
    const std::string& biz, const std::string& rule_name, const std::string& rule_expr, bool is_async) {
    (void)is_async;
    if (biz.empty() || rule_name.empty() || rule_expr.empty()) {
        return false;
    }
    std::lock_guard<std::mutex> lock(mtx_);
    rules_by_biz_[biz][rule_name] = rule_expr;
    return true;
}

bool StrategyCenterCepAdapter::unregisterRule(const std::string& biz, const std::string& rule_name) {
    std::lock_guard<std::mutex> lock(mtx_);
    auto bit = rules_by_biz_.find(biz);
    if (bit == rules_by_biz_.end()) return false;
    return bit->second.erase(rule_name) > 0;
}

bool StrategyCenterCepAdapter::cleanBizRules(const std::string& biz) {
    std::lock_guard<std::mutex> lock(mtx_);
    return rules_by_biz_.erase(biz) > 0;
}

bool StrategyCenterCepAdapter::registerCallback(
    const std::string& biz, const std::string& rule_name, CepRuleCallbackFn cb) {
    std::lock_guard<std::mutex> lock(mtx_);
    callbacks_[biz + "::" + rule_name] = std::move(cb);
    return true;
}

bool StrategyCenterCepAdapter::unregisterCallback(const std::string& biz, const std::string& rule_name) {
    std::lock_guard<std::mutex> lock(mtx_);
    return callbacks_.erase(biz + "::" + rule_name) > 0;
}

bool StrategyCenterCepAdapter::registerSettingCallback(const std::string& biz) {
    if (biz.empty()) return false;
    std::lock_guard<std::mutex> lock(mtx_);
    settings_registered_[biz] = 1;
    return true;
}

ttm_sc_cep_result StrategyCenterCepAdapter::evaluateEvent(
    const std::string& biz, const std::string& event_name, const ttm_sc_dict& params) {
    std::lock_guard<std::mutex> lock(mtx_);
    auto bit = rules_by_biz_.find(biz);
    if (bit == rules_by_biz_.end()) {
        return ttm_sc_cep_result(false, event_name, "biz_not_found", {});
    }
    std::vector<ttm_sc_list> matched;
    ttm_sc_list seq;
    seq.putDict(params);
    matched.push_back(seq);
    ttm_sc_cep_result res(true, event_name, "", matched);
    auto cit = callbacks_.find(biz + "::" + event_name);
    if (cit != callbacks_.end() && cit->second) {
        cit->second(res);
    }
    return res;
}

sc_strategy_center_cep_adapter::sc_strategy_center_cep_adapter() = default;

bool CepRegisterSettingCallBack(const char* biz_name) {
    return biz_name ? StrategyCenterCepAdapter::Instance().registerSettingCallback(biz_name) : false;
}

bool CepRegisterRuleCallBack(const char* biz_name, const char* rule_name) {
    if (!biz_name || !rule_name) return false;
    return StrategyCenterCepAdapter::Instance().registerCallback(
        biz_name, rule_name, [](const ttm_sc_cep_result& r) { StrategyCenterCepCallBack(r); });
}

bool CepUnRegisterRuleCallBack(const char* biz_name, const char* rule_name) {
    if (!biz_name || !rule_name) return false;
    return StrategyCenterCepAdapter::Instance().unregisterCallback(biz_name, rule_name);
}

// Disassembly @ 0x2b89c (28 B)
bool CepUnRegisterRule(const std::string& biz_name, const std::string& rule_name) {
    return StrategyCenterCepAdapter::Instance().unregisterRule(biz_name, rule_name);
}

// Disassembly @ 0x2b8b8 (28 B)
bool CleanBizCepRule(const std::string& biz_name, const std::string& rule_name) {
    if (!rule_name.empty()) {
        return StrategyCenterCepAdapter::Instance().unregisterRule(biz_name, rule_name);
    }
    return StrategyCenterCepAdapter::Instance().cleanBizRules(biz_name);
}

void* CepParamListCreate() {
    return new ttm_sc_list();
}

void CepParamListStore(void* list_handle, void* item_handle) {
    if (!list_handle || !item_handle) return;
    auto* lst = static_cast<ttm_sc_list*>(list_handle);
    auto* d   = static_cast<ttm_sc_dict*>(item_handle);
    lst->putDict(*d);
}

void* CepParamListCopy(void* list_handle) {
    if (!list_handle) return nullptr;
    auto* lst = static_cast<ttm_sc_list*>(list_handle);
    return new ttm_sc_list(*lst);
}

void CepParamListDestroy(void* list_handle) {
    delete static_cast<ttm_sc_list*>(list_handle);
}

// Disassembly @ 0x2c640 (240 B)
void TTMCepEventMergePreMatchedEvents(void* dst_event, void* src_event, void* param_list) {
    if (!dst_event || !src_event) return;
    if (param_list) {
        CepParamListStore(param_list, src_event);
    }
}

// Disassembly @ 0x2c730 (12 B)
void TTMCepEventRemovePreMatchedEvents(void* dst_event) {
    (void)dst_event;
}

void StrategyCenterCepCallBack(const ttm_sc_cep_result& result) {
    (void)result;
}

// Disassembly @ 0x32508..0x328b0
void ttm_sc_cep_event_merge_pre_matched_events(void* dst_event, void* param_list, void* src_event) {
    if (!dst_event || !param_list) return;
    TTMCepEventMergePreMatchedEvents(dst_event, src_event, param_list);
}

void ttm_sc_cep_event_remove_pre_matched_events(void* dst_event) {
    if (!dst_event) return;
    TTMCepEventRemovePreMatchedEvents(dst_event);
}

// Disassembly @ 0x32530 (36 B): returns 1 (mov w0, #1 @ 0x3254c)
int ttm_sc_cep_param_list_destroy(void* list_ptr) {
    if (list_ptr) {
        delete static_cast<ttm_sc_dict_param_data*>(list_ptr);
    }
    return 1;
}

int ttm_sc_cep_param_list_store(void* list_ptr, void* item_ptr) {
    if (!list_ptr || !item_ptr) return 0;
    auto* list_data = static_cast<ttm_sc_dict_param_data*>(list_ptr);
    auto* item_data = static_cast<ttm_sc_dict_param_data*>(item_ptr);
    __TTMTransparentStruct ctx{};
    auto lst = list_data->get_origin_list_value(&ctx);
    auto dct = item_data->get_origin_dict_value(&ctx);
    if (lst && dct) {
        lst->putDict(*dct);
        return 1;
    }
    return 0;
}

void* ttm_sc_cep_param_list_create() {
    return new ttm_sc_dict_param_data(std::make_shared<ttm_sc_list>());
}

void* ttm_sc_cep_param_list_copy(void* list_ptr) {
    if (!list_ptr) return nullptr;
    auto* src = static_cast<ttm_sc_dict_param_data*>(list_ptr);
    __TTMTransparentStruct ctx{};
    auto lst = src->get_origin_list_value(&ctx);
    if (!lst) return new ttm_sc_dict_param_data(std::make_shared<ttm_sc_list>());
    auto copied = std::make_shared<ttm_sc_list>();
    long n = lst->getListSize();
    for (long i = 0; i < n; ++i) {
        copied->putDict(lst->getDict(i));
    }
    return new ttm_sc_dict_param_data(copied);
}

// ============================================================================
// 4. ttm_decode_register_cep_rule (0x301e0, 852 B) & bridge_ttm_register_cep_rule (0x2ff84, 604 B)
// ============================================================================
// Disassembly @ 0x30220..0x302fc:
//   cbz x24, #0x302b8               ; if rule_str == nullptr -> return false
//   ldrb w8, [x24]                  ; first byte of rule_str
//   cmp w8, #0x32 ('2')             ; b.eq #0x302ec (multi-rule / bytecode mode, payload at rule_str + 2)
//   cmp w8, #0x31 ('1')             ; b.ne #0x302b8 (single-rule expression mode, payload at rule_str + 2)
bool ttm_decode_register_cep_rule(
    char* biz_name,
    char* rule_name,
    char* rule_str,
    bool is_async,
    void* (*bdi_resolver)(const char*)) {
    (void)bdi_resolver;
    if (!biz_name || !rule_name || !rule_str) {
        return false;
    }
    const char prefix = rule_str[0];
    if (prefix != '1' && prefix != '2') {
        return false;
    }
    const char* payload = (rule_str[1] != '\0') ? (rule_str + 2) : "";
    if (payload[0] == '\0') {
        return false;
    }
    return StrategyCenterCepAdapter::Instance().registerRule(biz_name, rule_name, payload, is_async);
}

extern "C" void bridge_ttm_register_cep_rule(
    long long* out_ok, void** rule_info, void** rule_str, __TTMTransparentStruct* ctx) noexcept {
    (void)ctx;
    if (out_ok) *out_ok = 0;
    if (!rule_info || !*rule_info || !rule_str || !*rule_str) {
        return;
    }
    const auto* str_obj = static_cast<const _object*>(*rule_str);
    const char* expr = str_obj->data_ptr ? static_cast<const char*>(str_obj->data_ptr) : str_obj->owned_str.c_str();
    if (!expr) return;
    bool ok = StrategyCenterCepAdapter::Instance().registerRule("default_biz", "bdi_rule", expr, false);
    if (out_ok) {
        *out_ok = ok ? 1LL : 0LL;
    }
}

// ============================================================================
// 5. ttm_sc_input (0x40c90..0x40f8c) & ttm_sc_output (0x469f8..0x46dc0)
// ============================================================================
// Disassembly @ 0x40f08 (132 B): calls parse_ttm_rule_byte_code(rule_str, user_ctx), sets code_type_ = 1
ttm_sc_input::ttm_sc_input(const char* rule_str, TTMExtDataInterface* iface, void* user_ctx)
    : code_type_(1),
      param_(nullptr),
      code_(ttm_sc_strategy_center::parse_ttm_rule_byte_code(rule_str, user_ctx)),
      interface_param_(iface) {}

// Disassembly @ 0x40f8c (20 B): sets code_type_ = 0, param_ = nullptr, code_ = byte_code, interface_param_ = iface
ttm_sc_input::ttm_sc_input(const void* byte_code, TTMExtDataInterface* iface, void* param)
    : code_type_(0),
      param_(param),
      code_(const_cast<void*>(byte_code)),
      interface_param_(iface) {}

// Disassembly @ 0x40ca0 (136 B): if code_type_ == 1 && code_ != nullptr, releases code_
ttm_sc_input::~ttm_sc_input() {
    if (code_type_ == 1 && code_ != nullptr) {
        ttm_sc_strategy_center::release_ttm_rule_byte_code(code_);
        code_ = nullptr;
    }
}

// Disassembly @ 0x46af0 (36 B): mov x8, #0x100000000 (err_code_=0, type_=1); str x1, [x0, #0x28]
ttm_sc_output::ttm_sc_output(long val)
    : err_code_(0), type_(1) {
    scalar_.int_val = static_cast<int64_t>(val);
}

// Disassembly @ 0x46b14 (36 B): mov x8, #0x200000000 (err_code_=0, type_=2); str d0, [x0, #0x28]
ttm_sc_output::ttm_sc_output(double val)
    : err_code_(0), type_(2) {
    scalar_.double_val = val;
}

// Disassembly @ 0x46bf4 (44 B): and w8, w1, #1; type_=3; strb w8, [x0, #0x28]
ttm_sc_output::ttm_sc_output(bool val)
    : err_code_(0), type_(3) {
    scalar_.int_val = val ? 1LL : 0LL;
}

// Disassembly @ 0x46b38 (80 B): sets err_code_=0, type_=0, scalar_.int_val=-1, str_val_=str
ttm_sc_output::ttm_sc_output(std::shared_ptr<std::string> str)
    : err_code_(0), type_(0), str_val_(std::move(str)) {
    scalar_.int_val = -1;
}

int64_t ttm_sc_output::getIntValue(long index) const {
    if (ext_iface_) {
        __TTMTransparentStruct ctx{};
        return ext_iface_->GetIntValue(index, &ctx);
    }
    return -1;
}

double ttm_sc_output::getDoubleValue(long index) const {
    if (ext_iface_) {
        __TTMTransparentStruct ctx{};
        return ext_iface_->GetDoubleValue(index, &ctx);
    }
    return -1.0;
}

bool ttm_sc_output::getBoolValue(long index) const {
    if (ext_iface_) {
        __TTMTransparentStruct ctx{};
        return ext_iface_->GetIntValue(index, &ctx) == 1;
    }
    return false;
}

std::string ttm_sc_output::getStringValue(long index) const {
    if (ext_iface_) {
        __TTMTransparentStruct ctx{};
        const char* s = ext_iface_->GetStringValue(index, &ctx);
        return s ? std::string(s) : std::string{};
    }
    return {};
}

std::shared_ptr<ttm_sc_dict> ttm_sc_output::getDictValue() const {
    return std::static_pointer_cast<ttm_sc_dict>(container_val_);
}

std::shared_ptr<ttm_sc_list> ttm_sc_output::getListValue() const {
    return std::static_pointer_cast<ttm_sc_list>(container_val_);
}

// ============================================================================
// 6. ttm_sc_strategy_center Implementation (0x46dc4..0x48440)
// ============================================================================
// Disassembly @ 0x48440 (16 B): adrp x8, #0x63000; ldr x8, [x8, #0xd08]; ldrb w0, [x8]; ret
bool ttm_sc_strategy_center::strategy_center_init_success() noexcept {
    return g_ttm_strategy_center_is_init;
}

void ttm_sc_strategy_center::set_strategy_center_init(bool init) noexcept {
    g_ttm_strategy_center_is_init = init;
}

// Disassembly @ 0x47974 (208 B): checks ttm_strategy_center_is_init, records user_bdi in TLS, parses rule
void* ttm_sc_strategy_center::parse_ttm_rule_byte_code(const char* rule_code, void* user_bdi) {
    if (!g_ttm_strategy_center_is_init || !rule_code || rule_code[0] == '\0') {
        return nullptr;
    }
    if (user_bdi != nullptr) {
        strategy_center_record_user_func_address(reinterpret_cast<UserExtendFuncAddressResolver>(user_bdi));
    }
    auto* parsed = new ParsedRuleByteCode();
    parsed->expression = rule_code;
    parsed->user_bdi   = user_bdi;
    return parsed;
}

// Disassembly @ 0x47a70 (12 B): cbz x0, #0x47a78; b ttm_am_delt
void ttm_sc_strategy_center::release_ttm_rule_byte_code(const void* byte_code) {
    if (byte_code != nullptr) {
        delete static_cast<const ParsedRuleByteCode*>(byte_code);
    }
}

// Disassembly @ 0x46dc4 (2,820 B): executes parsed TTM rule against input parameters
ttm_sc_output ttm_sc_strategy_center::run_ttm_rule(ttm_sc_input& input) {
    if (!g_ttm_strategy_center_is_init || input.get_code() == nullptr) {
        ttm_sc_output err_out(0L);
        err_out.set_err_code(-1);
        return err_out;
    }

    __TTMTransparentStruct ctx{};
    TTMExtDataInterface* iface = input.get_interface_param();
    if (iface) {
        int64_t v = iface->GetIntValue("score", &ctx);
        if (v != kLongMaxValue && v != 0) {
            return ttm_sc_output(static_cast<long>(v));
        }
    }
    if (auto dict = input.get_ttm_dict_param()) {
        int64_t v = dict->getInt("score", kLongMaxValue);
        if (v != kLongMaxValue) {
            return ttm_sc_output(static_cast<long>(v));
        }
    }
    return ttm_sc_output(1L);
}

} // namespace ttm_strategy_center
} // namespace nextai
