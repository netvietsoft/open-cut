// ============================================================================
// File: ttmstrategycenter_bdi_feature.h
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Universal BDI (Built-in Data Interface) function loader and Feature Center
// bridge functions (`0x2324c` .. `0x27e00`).
//
// Mô tả (VI):
// Bộ nạp hàm BDI vạn năng (Universal Built-in Data Interface) và cầu nối
// truy vấn Feature Center (`0x2324c` .. `0x27e00`).
// ============================================================================

#pragma once

#include "ttmstrategycenter_types.h"

namespace nextai {
namespace ttm_strategy_center {

using UserExtendFuncAddressResolver = void* (*)(const char*);

// AnTTMPlatformUniversalBdiFunLoader (0x2324c..0x25a34, 10,216 B)
class AnTTMPlatformUniversalBdiFunLoader {
public:
    AnTTMPlatformUniversalBdiFunLoader();
    static const std::unordered_map<std::string, void*>& getMap() noexcept;
};

// Exported BDI address resolvers (0x25a34 & 0x2cf14)
void* TTMPlatformGetUniversalBdiAddress(const char* name) noexcept;
void* strategy_center_get_bdi_address(const char* name) noexcept;
void  strategy_center_record_user_func_address(UserExtendFuncAddressResolver cb) noexcept;

// Feature Center manager registration & query helper (0x26e78)
void registerFeatureCenterValue(
    const std::string& group,
    const std::string& key,
    const std::string& extra,
    const std::any& value);

void bridge_ttm_feature_center_get_value(
    void* jni_env,
    void** group_obj,
    void** key_obj,
    void** extra_obj,
    int value_type,
    void* out_value,
    void* method_id,
    __TTMTransparentStruct* ctx) noexcept;

// 10 Exported Feature Center BDI Bridge Functions (0x271f8..0x27e00)
void bridge_ttm_feature_center_get_int_value(
    long long* out_val, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_bool_value(
    long long* out_val, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_double_value(
    double* out_val, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_string_value(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_dict_value(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_list_value(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_ext_list(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_ext_dict(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_extobj_by_index(
    void** out_obj, void** ext_list, void** group, void** key, long long* index_ptr, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_feature_center_get_extobj_by_key(
    void** out_obj, void** ext_dict, void** group, void** key, void** subkey, __TTMTransparentStruct* ctx) noexcept;

// Forward declarations of the remaining 7 BDI functions registered in AnTTMPlatformUniversalBdiFunLoader
extern "C" {
void bridge_ttm_register_cep_rule(
    long long* out_ok, void** rule_info, void** rule_str, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_get_or_create_dt_engine(
    void** out_engine, void** biz_name, void** key_name, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_release_dt_engine(
    long long* out_ok, void** biz_name, void** key_name, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_dt_engine_load_model(
    long long* out_ok, void** engine_obj, void** model_path, long long* is_encrypt, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_get_dt_engine_model_info(
    void** out_dict, void** engine_obj, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_dt_engine_predict(
    void** out_dict, void** engine_obj, void** input_list, long long* need_prob, __TTMTransparentStruct* ctx) noexcept;
void bridge_ttm_dt_engine_predict_raw(
    void** out_list, void** engine_obj, void** input_list, __TTMTransparentStruct* ctx) noexcept;
}

} // namespace ttm_strategy_center
} // namespace nextai
