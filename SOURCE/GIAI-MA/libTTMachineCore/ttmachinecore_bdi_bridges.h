// ==============================================================================
// FILE: ttmachinecore_bdi_bridges.h
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols)
// PURPOSE: Universal BDI Loaders (`TTMUniversalBdiFunLoader` @ `0x2869c`,
//          `AnTTMUniversalBdiFunLoader` @ `0x44208`), String/Math/List/CEP
//          BDI Bridges (`0x17e00..0x28600`), and Keva KV Bridges (`0x4934c..0x4a2fc`)
//          (Bộ nạp hàm BDI vạn năng, các cầu nối BDI Chuỗi/Toán/Danh sách/CEP
//          và cầu nối lưu trữ Keva KV)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 .text `0x17e00..0x4a2fc`)
// ==============================================================================

#pragma once

#include "ttmachinecore_types.h"
#include "ttmachinecore_objects_hashmap.h"

namespace NextAI::OpenCut::TTMachineCore {

// ==============================================================================
// 1. Universal BDI Function Loaders (`0x2869c..0x37290` & `0x44208..0x4739c`)
// ==============================================================================
class TTMUniversalBdiFunLoader {
public:
    TTMUniversalBdiFunLoader();
};

class AnTTMUniversalBdiFunLoader {
public:
    AnTTMUniversalBdiFunLoader();
};

void* TTMGetUniversalBdiAddress(const std::string& name);
void* AnTTMGetUniversalBdiAddress(const std::string& name);
const std::unordered_map<std::string, void*>& GetCoreUniversalBdiMap();

// ==============================================================================
// 2. String, Math, List & CEP BDI Bridges (`0x17e00..0x28600`)
// ==============================================================================
void bridge_str_contains_sub_str(std::int64_t* out, TTMStrO** haystack, TTMStrO** needle, __TTMTransparentStruct* ctx);
void bridge_str_not_contains_sub_str(std::int64_t* out, TTMStrO** haystack, TTMStrO** needle, __TTMTransparentStruct* ctx);
void bridge_str_lowercase(_object** out, TTMStrO** src, __TTMTransparentStruct* ctx);
void bridge_str_uppercase(_object** out, TTMStrO** src, __TTMTransparentStruct* ctx);
void bridge_str_length(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* ctx);
void bridge_ttm_string_format(_object** out, TTMStrO** fmt, TTMListO** args, __TTMTransparentStruct* ctx);
void bridge_ttm_list_string_join(_object** out, TTMStrO** sep, TTMListO** list, __TTMTransparentStruct* ctx);
void bridge_ttm_str_replace(_object** out, TTMStrO** src, TTMStrO** old_sub, TTMStrO** new_sub, __TTMTransparentStruct* ctx);
void bridge_ttm_str_endswith(std::int64_t* out, TTMStrO** src, TTMStrO** suffix, __TTMTransparentStruct* ctx);
void bridge_ttm_str_startswith(std::int64_t* out, TTMStrO** src, TTMStrO** prefix, __TTMTransparentStruct* ctx);
void bridge_ttm_str_substring(_object** out, TTMStrO** src, std::int64_t* start, std::int64_t* end, __TTMTransparentStruct* ctx);
void bridge_ttm_str_concat(_object** out, TTMStrO** lhs, TTMStrO** rhs, __TTMTransparentStruct* ctx);
void bridge_ttm_str_index_of(std::int64_t* out, TTMStrO** src, TTMStrO** sub, __TTMTransparentStruct* ctx);
void bridge_ttm_str_last_index_of(std::int64_t* out, TTMStrO** src, TTMStrO** sub, __TTMTransparentStruct* ctx);
void bridge_ttm_str_isalpha(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* ctx);
void bridge_ttm_str_isdigit(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* ctx);
void bridge_ttm_str_islower(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* ctx);
void bridge_ttm_str_isupper(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* ctx);

void bridge_ttm_exp(double* out, double* val);
void bridge_ttm_fabs(double* out, double* val);
void bridge_ttm_log10(double* out, double* val);
void bridge_ttm_sqrt(double* out, double* val);
void bridge_ttm_round(std::int64_t* out, double* val);
void bridge_ttm_platform_os(std::int64_t* out);

void bridge_ttm_list_avg(double* out, TTMListO** list, __TTMTransparentStruct* ctx);
void bridge_ttm_list_sum(double* out, TTMListO** list, __TTMTransparentStruct* ctx);
void bridge_ttm_list_variance(double* out, TTMListO** list, __TTMTransparentStruct* ctx);
void bridge_ttm_list_standard_deviation(double* out, TTMListO** list, __TTMTransparentStruct* ctx);
void bridge_ttm_list_sort(TTMListO** list, std::int64_t* descending, __TTMTransparentStruct* ctx);
void bridge_ttm_list_percentile(double* out, TTMListO** list, double* q, __TTMTransparentStruct* ctx);
void bridge_make_range_list(_object** out, std::int64_t* start, std::int64_t* stop, std::int64_t* step, __TTMTransparentStruct* ctx);

// ==============================================================================
// 3. Keva KV Storage & AppLog Bridges (`0x4934c..0x4a2fc`)
// ==============================================================================
std::string make_ttm_kv_actual_key(TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_store_bool_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, std::int64_t* val, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_store_int_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, std::int64_t* val, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_store_float_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, double* val, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_store_str_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, TTMStrO** val, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_get_bool_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_get_int_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_get_float_value(double* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_get_str_value(_object** out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_contains_key(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_kv_remove_key(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx);
void bridge_ttm_send_applog(std::int64_t* out, TTMStrO** event_name, _dictobject** params, __TTMTransparentStruct* ctx);

} // namespace NextAI::OpenCut::TTMachineCore
