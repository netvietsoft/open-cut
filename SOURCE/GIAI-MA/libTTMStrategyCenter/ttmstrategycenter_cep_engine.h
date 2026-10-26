// ============================================================================
// File: ttmstrategycenter_cep_engine.h
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Complex Event Processing (CEP) adapter, rule decoder, expression evaluator,
// and Strategy Center rule execution engine (`0x2a9b0` .. `0x48440`).
//
// Mô tả (VI):
// Bộ điều hợp xử lý sự kiện phức hợp (CEP), bộ giải mã quy tắc, bộ định giá
// biểu thức, và động cơ thực thi quy tắc của Strategy Center (`0x2a9b0` .. `0x48440`).
// ============================================================================

#pragma once

#include "ttmstrategycenter_types.h"
#include "ttmstrategycenter_data_wrappers.h"

namespace nextai {
namespace ttm_strategy_center {

// ============================================================================
// 1. cep::DataWrapper Base Interface & StrategyCenterCepSettingData & TTMCepDataWrapper
// ============================================================================
class CepDataWrapperBase {
public:
    virtual ~CepDataWrapperBase() = default;
    virtual int32_t Type() = 0;
    virtual int64_t IntValue() = 0;
    virtual double FloatValue() = 0;
    virtual bool BoolValue() = 0;
    virtual std::string StringValue() = 0;
    virtual int32_t Size() = 0;
    virtual std::shared_ptr<CepDataWrapperBase> GetData(int index) = 0;
    virtual std::vector<std::string> KeySet() = 0;
    virtual std::shared_ptr<CepDataWrapperBase> GetData(const std::string& key) = 0;
    virtual std::string JSON() = 0;
};

// StrategyCenterCepSettingData (0x2ce78..0x2cf08, 16 bytes, vtable @ 0x61fd8)
// Verified at 0x2cec8: stores w1 at [x0, #8], IntValue() @ 0x2ce80: ldrsw x0, [x0, #8]
class StrategyCenterCepSettingData : public CepDataWrapperBase {
public:
    explicit StrategyCenterCepSettingData(int val) noexcept : value_(val) {} // @ 0x2cec8
    ~StrategyCenterCepSettingData() override = default;                      // @ 0x2cee0

    int32_t Type() override { return 0; }                                    // @ 0x2ce78: mov w0, wzr
    int64_t IntValue() override { return static_cast<int64_t>(value_); }     // @ 0x2ce80: ldrsw x0, [x0, #8]
    double FloatValue() override { return 0.0; }                             // @ 0x2ce88: fmov d0, xzr
    bool BoolValue() override { return false; }                              // @ 0x2ce90: mov w0, wzr
    std::string StringValue() override { return {}; }                        // @ 0x2ce98
    int32_t Size() override { return 0; }                                    // @ 0x2cea4: mov w0, wzr
    std::shared_ptr<CepDataWrapperBase> GetData(int) override { return nullptr; } // @ 0x2ceac
    std::vector<std::string> KeySet() override { return {}; }                // @ 0x2ceb4
    std::shared_ptr<CepDataWrapperBase> GetData(const std::string&) override { return nullptr; } // @ 0x2cec0
    std::string JSON() override { return {}; }                               // @ 0x2cf08

private:
    int32_t value_{0};   // +0x08
    int32_t padding_{0}; // +0x0c
};
static_assert(sizeof(StrategyCenterCepSettingData) == 16, "StrategyCenterCepSettingData must be 16 bytes");

// TTMCepDataWrapper (0x30950..0x30de8, 24 bytes, vtable @ 0x62300)
// Verified at 0x30da8: stores obj at [x0, #8] and ctx at [x0, #0x10]
class TTMCepDataWrapper : public CepDataWrapperBase {
public:
    TTMCepDataWrapper(_object* obj, void* ctx) noexcept : obj_(obj), ctx_(ctx) {} // @ 0x30da8
    ~TTMCepDataWrapper() override = default;                                      // @ 0x30dc0

    int32_t Type() override;                                                      // @ 0x30950
    int64_t IntValue() override;                                                  // @ 0x309ec
    double FloatValue() override;                                                 // @ 0x309f8
    bool BoolValue() override;                                                    // @ 0x30a04
    std::string StringValue() override;                                           // @ 0x30a18
    int32_t Size() override;                                                      // @ 0x30a28
    std::vector<std::string> KeySet() override;                                   // @ 0x30a44
    std::shared_ptr<CepDataWrapperBase> GetData(int index) override;              // @ 0x30c80
    std::shared_ptr<CepDataWrapperBase> GetData(const std::string& key) override;
    std::string JSON() override { return {}; }                                    // @ 0x30de8

private:
    _object* obj_{nullptr}; // +0x08
    void*    ctx_{nullptr}; // +0x10
};
static_assert(sizeof(TTMCepDataWrapper) == 24, "TTMCepDataWrapper must be 24 bytes");

// ============================================================================
// 2. ttm_sc_cep_result (0x33bc0..0x345b8)
// ============================================================================
struct CepMatchedEventSequence {
    std::string rule_name;
    std::vector<ttm_sc_dict> events;
};

class ttm_sc_cep_result {
public:
    ttm_sc_cep_result() = default;
    ttm_sc_cep_result(
        bool success,
        std::string rule_name,
        std::string error_msg,
        std::vector<ttm_sc_list> matched_events);
    ttm_sc_cep_result(const ttm_sc_cep_result& other) = default; // @ 0x345b8

    bool isSuccess() const noexcept { return success_; }                     // @ 0x33bc0
    std::string getRuleName() const { return rule_name_; }                   // @ 0x33cf4
    std::string getErrorMessage() const { return error_message_; }           // @ 0x33e88
    std::vector<ttm_sc_list> getMatchEventList() const { return matched_events_; } // @ 0x3401c

private:
    bool                     success_{false};
    std::string              rule_name_{};
    std::string              error_message_{};
    std::vector<ttm_sc_list> matched_events_{};
};

// ============================================================================
// 3. CEP Adapter & Rule Registration Functions (0x2a9b0..0x335e8)
// ============================================================================
using CepRuleCallbackFn = std::function<void(const ttm_sc_cep_result&)>;

class StrategyCenterCepAdapter {
public:
    StrategyCenterCepAdapter(); // @ 0x2a9b0
    static StrategyCenterCepAdapter& Instance();

    bool registerRule(const std::string& biz, const std::string& rule_name, const std::string& rule_expr, bool is_async);
    bool unregisterRule(const std::string& biz, const std::string& rule_name);
    bool cleanBizRules(const std::string& biz);
    bool registerCallback(const std::string& biz, const std::string& rule_name, CepRuleCallbackFn cb);
    bool unregisterCallback(const std::string& biz, const std::string& rule_name);
    bool registerSettingCallback(const std::string& biz);
    ttm_sc_cep_result evaluateEvent(const std::string& biz, const std::string& event_name, const ttm_sc_dict& params);

private:
    mutable std::mutex mtx_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> rules_by_biz_;
    std::unordered_map<std::string, CepRuleCallbackFn> callbacks_;
    std::unordered_map<std::string, int> settings_registered_;
};

class sc_strategy_center_cep_adapter {
public:
    sc_strategy_center_cep_adapter(); // @ 0x32be0
};

// Exported C/C++ CEP functions
bool CepRegisterSettingCallBack(const char* biz_name);                                  // @ 0x2b0ac
bool CepRegisterRuleCallBack(const char* biz_name, const char* rule_name);              // @ 0x2b2d4
bool CepUnRegisterRuleCallBack(const char* biz_name, const char* rule_name);            // @ 0x2b7d4
bool CepUnRegisterRule(const std::string& biz_name, const std::string& rule_name);      // @ 0x2b89c
bool CleanBizCepRule(const std::string& biz_name, const std::string& rule_name);        // @ 0x2b8b8

void* CepParamListCreate();                                                             // @ 0x2c130
void  CepParamListStore(void* list_handle, void* item_handle);                          // @ 0x2c29c
void* CepParamListCopy(void* list_handle);                                              // @ 0x2c50c
void  CepParamListDestroy(void* list_handle);                                           // @ 0x2c5b8

void  TTMCepEventMergePreMatchedEvents(void* dst_event, void* src_event, void* param_list); // @ 0x2c640
void  TTMCepEventRemovePreMatchedEvents(void* dst_event);                               // @ 0x2c730
void  StrategyCenterCepCallBack(const ttm_sc_cep_result& result);                       // @ 0x2c73c

void  ttm_sc_cep_event_merge_pre_matched_events(void* dst_event, void* param_list, void* src_event); // @ 0x32508
void  ttm_sc_cep_event_remove_pre_matched_events(void* dst_event);                      // @ 0x32524
int   ttm_sc_cep_param_list_destroy(void* list_ptr);                                    // @ 0x32530
int   ttm_sc_cep_param_list_store(void* list_ptr, void* item_ptr);                      // @ 0x32554
void* ttm_sc_cep_param_list_create();                                                   // @ 0x32774
void* ttm_sc_cep_param_list_copy(void* list_ptr);                                       // @ 0x328b0

// Rule decoder (0x301e0, 852 B): checks rule_str[0] == '1' (0x31) or '2' (0x32)
bool ttm_decode_register_cep_rule(
    char* biz_name,
    char* rule_name,
    char* rule_str,
    bool is_async,
    void* (*bdi_resolver)(const char*));

// ============================================================================
// 4. ttm_sc_strategy_center Core Engine (0x46dc4..0x48440)
// ============================================================================
class ttm_sc_strategy_center {
public:
    static ttm_sc_output run_ttm_rule(ttm_sc_input& input);                         // @ 0x46dc4 (2,820 B)
    static void* parse_ttm_rule_byte_code(const char* rule_code, void* user_bdi);   // @ 0x47974 (208 B)
    static void  release_ttm_rule_byte_code(const void* byte_code);                 // @ 0x47a70 (12 B)
    static bool  strategy_center_init_success() noexcept;                           // @ 0x48440 (16 B)
    static void  set_strategy_center_init(bool init) noexcept;
};

} // namespace ttm_strategy_center
} // namespace nextai
