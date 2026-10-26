// ==============================================================================
// FILE: ttmachinecore_bdi_bridges.cpp
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols)
// PURPOSE: Implementation of `TTMUniversalBdiFunLoader` (`0x2869c`),
//          `AnTTMUniversalBdiFunLoader` (`0x44208`), String/Math/List Bridges,
//          and Keva KV (`ttm_core_repo`) Storage Bridges (`0x4934c..0x4a2fc`)
//          (Hiện thực hóa Bộ nạp BDI vạn năng, các cầu nối Chuỗi/Toán/Danh sách
//          và các cầu nối lưu trữ Keva KV `ttm_core_repo`)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly & .bss `0x6db78`/`0x6dbc0`)
// ==============================================================================

#include "ttmachinecore_bdi_bridges.h"

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstring>
#include <sstream>

namespace NextAI::OpenCut::TTMachineCore {

namespace {

// `.bss` @ `0x6db78` (`ttm_universal_bdi_address_map`) & `0x6dbc0` (`an_ttm_universal_bdi_address_map`)
std::unordered_map<std::string, void*>& GetMutableCoreBdiMap() {
    static std::unordered_map<std::string, void*> s_map;
    return s_map;
}

std::unordered_map<std::string, void*>& GetMutableAnCoreBdiMap() {
    static std::unordered_map<std::string, void*> s_an_map;
    return s_an_map;
}

struct KevaCoreRepo {
    std::mutex mtx;
    std::unordered_map<std::string, std::any> store;
};

KevaCoreRepo& GetKevaCoreRepo() {
    static KevaCoreRepo s_repo;
    return s_repo;
}

} // namespace

// ==============================================================================
// 1. Universal BDI Function Loaders (`0x2869c` & `0x44208`)
// ==============================================================================
TTMUniversalBdiFunLoader::TTMUniversalBdiFunLoader() {
    auto& m = GetMutableCoreBdiMap();
    m["universal.str.contains"]         = reinterpret_cast<void*>(&bridge_str_contains_sub_str);
    m["universal.str.not_contains"]     = reinterpret_cast<void*>(&bridge_str_not_contains_sub_str);
    m["universal.str.lower"]            = reinterpret_cast<void*>(&bridge_str_lowercase);
    m["universal.str.upper"]            = reinterpret_cast<void*>(&bridge_str_uppercase);
    m["universal.str.length"]           = reinterpret_cast<void*>(&bridge_str_length);
    m["universal.str.format"]           = reinterpret_cast<void*>(&bridge_ttm_string_format);
    m["universal.str.join"]             = reinterpret_cast<void*>(&bridge_ttm_list_string_join);
    m["universal.str.replace"]          = reinterpret_cast<void*>(&bridge_ttm_str_replace);
    m["universal.str.endswith"]         = reinterpret_cast<void*>(&bridge_ttm_str_endswith);
    m["universal.str.startswith"]       = reinterpret_cast<void*>(&bridge_ttm_str_startswith);
    m["universal.str.substring"]        = reinterpret_cast<void*>(&bridge_ttm_str_substring);
    m["universal.str.concat"]           = reinterpret_cast<void*>(&bridge_ttm_str_concat);
    m["universal.str.index_of"]         = reinterpret_cast<void*>(&bridge_ttm_str_index_of);
    m["universal.str.last_index_of"]    = reinterpret_cast<void*>(&bridge_ttm_str_last_index_of);
    m["universal.str.isalpha"]          = reinterpret_cast<void*>(&bridge_ttm_str_isalpha);
    m["universal.str.isdigit"]          = reinterpret_cast<void*>(&bridge_ttm_str_isdigit);
    m["universal.str.islower"]          = reinterpret_cast<void*>(&bridge_ttm_str_islower);
    m["universal.str.isupper"]          = reinterpret_cast<void*>(&bridge_ttm_str_isupper);
    m["universal.math.exp"]             = reinterpret_cast<void*>(&bridge_ttm_exp);
    m["universal.math.fabs"]            = reinterpret_cast<void*>(&bridge_ttm_fabs);
    m["universal.math.log10"]           = reinterpret_cast<void*>(&bridge_ttm_log10);
    m["universal.math.sqrt"]            = reinterpret_cast<void*>(&bridge_ttm_sqrt);
    m["universal.math.round"]           = reinterpret_cast<void*>(&bridge_ttm_round);
    m["universal.list.avg"]             = reinterpret_cast<void*>(&bridge_ttm_list_avg);
    m["universal.list.sum"]             = reinterpret_cast<void*>(&bridge_ttm_list_sum);
    m["universal.list.variance"]        = reinterpret_cast<void*>(&bridge_ttm_list_variance);
    m["universal.list.std_dev"]         = reinterpret_cast<void*>(&bridge_ttm_list_standard_deviation);
    m["universal.list.sort"]            = reinterpret_cast<void*>(&bridge_ttm_list_sort);
    m["universal.list.percentile"]      = reinterpret_cast<void*>(&bridge_ttm_list_percentile);
    m["universal.list.range"]           = reinterpret_cast<void*>(&bridge_make_range_list);
}

AnTTMUniversalBdiFunLoader::AnTTMUniversalBdiFunLoader() {
    auto& m = GetMutableAnCoreBdiMap();
    m["universal.ttm_kv_store_bool_value"]  = reinterpret_cast<void*>(&bridge_ttm_kv_store_bool_value);
    m["universal.ttm_kv_store_int_value"]   = reinterpret_cast<void*>(&bridge_ttm_kv_store_int_value);
    m["universal.ttm_kv_store_float_value"] = reinterpret_cast<void*>(&bridge_ttm_kv_store_float_value);
    m["universal.ttm_kv_store_str_value"]   = reinterpret_cast<void*>(&bridge_ttm_kv_store_str_value);
    m["universal.ttm_kv_get_bool_value"]    = reinterpret_cast<void*>(&bridge_ttm_kv_get_bool_value);
    m["universal.ttm_kv_get_int_value"]     = reinterpret_cast<void*>(&bridge_ttm_kv_get_int_value);
    m["universal.ttm_kv_get_float_value"]   = reinterpret_cast<void*>(&bridge_ttm_kv_get_float_value);
    m["universal.ttm_kv_get_str_value"]     = reinterpret_cast<void*>(&bridge_ttm_kv_get_str_value);
    m["universal.ttm_kv_contains_key"]      = reinterpret_cast<void*>(&bridge_ttm_kv_contains_key);
    m["universal.ttm_kv_remove_key"]        = reinterpret_cast<void*>(&bridge_ttm_kv_remove_key);
    m["universal.ttm_send_applog"]          = reinterpret_cast<void*>(&bridge_ttm_send_applog);
}

void* TTMGetUniversalBdiAddress(const std::string& name) {
    const auto& m = GetMutableCoreBdiMap();
    auto it = m.find(name);
    if (it != m.end()) return it->second;
    return AnTTMGetUniversalBdiAddress(name);
}

void* AnTTMGetUniversalBdiAddress(const std::string& name) {
    const auto& m = GetMutableAnCoreBdiMap();
    auto it = m.find(name);
    return (it != m.end()) ? it->second : nullptr;
}

const std::unordered_map<std::string, void*>& GetCoreUniversalBdiMap() {
    return GetMutableCoreBdiMap();
}

// ==============================================================================
// 2. String Bridges (`0x181e4..0x28380`)
// ==============================================================================
void bridge_str_contains_sub_str(std::int64_t* out, TTMStrO** haystack, TTMStrO** needle, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    *out = (haystack && needle && TTMStr_is_contain(*haystack, *needle)) ? 1 : 0;
}

void bridge_str_not_contains_sub_str(std::int64_t* out, TTMStrO** haystack, TTMStrO** needle, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    *out = (haystack && needle && !TTMStr_is_contain(*haystack, *needle)) ? 1 : 0;
}

void bridge_str_lowercase(_object** out, TTMStrO** src, __TTMTransparentStruct* ctx) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::tolower(c)); });
    *out = TTMStrO_from_cstr(s.c_str(), ctx);
}

void bridge_str_uppercase(_object** out, TTMStrO** src, __TTMTransparentStruct* ctx) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) { return static_cast<char>(std::toupper(c)); });
    *out = TTMStrO_from_cstr(s.c_str(), ctx);
}

void bridge_str_length(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    *out = (src && *src) ? (*src)->ob_size : 0;
}

void bridge_ttm_string_format(_object** out, TTMStrO** fmt, TTMListO** args, __TTMTransparentStruct* ctx) {
    if (!out) return;
    std::string f = (fmt && *fmt) ? ttm_ttmstro_to_cstr(*fmt) : "";
    if (!args || !*args) {
        *out = TTMStrO_from_cstr(f.c_str(), ctx);
        return;
    }
    std::ostringstream oss;
    std::size_t arg_idx = 0;
    for (std::size_t i = 0; i < f.size(); ++i) {
        if (f[i] == '{' && i + 1 < f.size() && f[i + 1] == '}' && arg_idx < (*args)->obj_items.size()) {
            _object* elem = (*args)->obj_items[arg_idx++];
            if (!elem || elem->ob_type == &TTMNoneO_Type) oss << "None";
            else if (elem->ob_type == &TTMIntO_Type) oss << static_cast<TTMIntO*>(elem)->ob_ival;
            else if (elem->ob_type == &TTMFloatO_Type) oss << static_cast<TTMFloatO*>(elem)->ob_fval;
            else if (elem->ob_type == &TTMStrO_Type) oss << ttm_ttmstro_to_cstr(static_cast<TTMStrO*>(elem));
            ++i;
        } else {
            oss << f[i];
        }
    }
    *out = TTMStrO_from_cstr(oss.str().c_str(), ctx);
}

void bridge_ttm_list_string_join(_object** out, TTMStrO** sep, TTMListO** list, __TTMTransparentStruct* ctx) {
    if (!out) return;
    std::string s_sep = (sep && *sep) ? ttm_ttmstro_to_cstr(*sep) : "";
    std::ostringstream oss;
    if (list && *list) {
        for (std::size_t i = 0; i < (*list)->obj_items.size(); ++i) {
            if (i > 0) oss << s_sep;
            _object* elem = (*list)->obj_items[i];
            if (elem && elem->ob_type == &TTMStrO_Type) {
                oss << ttm_ttmstro_to_cstr(static_cast<TTMStrO*>(elem));
            }
        }
    }
    *out = TTMStrO_from_cstr(oss.str().c_str(), ctx);
}

void bridge_ttm_str_replace(_object** out, TTMStrO** src, TTMStrO** old_sub, TTMStrO** new_sub, __TTMTransparentStruct* ctx) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::string from = (old_sub && *old_sub) ? ttm_ttmstro_to_cstr(*old_sub) : "";
    std::string to = (new_sub && *new_sub) ? ttm_ttmstro_to_cstr(*new_sub) : "";
    if (!from.empty()) {
        std::size_t pos = 0;
        while ((pos = s.find(from, pos)) != std::string::npos) {
            s.replace(pos, from.length(), to);
            pos += to.length();
        }
    }
    *out = TTMStrO_from_cstr(s.c_str(), ctx);
}

void bridge_ttm_str_endswith(std::int64_t* out, TTMStrO** src, TTMStrO** suffix, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::string suf = (suffix && *suffix) ? ttm_ttmstro_to_cstr(*suffix) : "";
    *out = (s.size() >= suf.size() && s.compare(s.size() - suf.size(), suf.size(), suf) == 0) ? 1 : 0;
}

void bridge_ttm_str_startswith(std::int64_t* out, TTMStrO** src, TTMStrO** prefix, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::string pre = (prefix && *prefix) ? ttm_ttmstro_to_cstr(*prefix) : "";
    *out = (s.size() >= pre.size() && s.compare(0, pre.size(), pre) == 0) ? 1 : 0;
}

void bridge_ttm_str_substring(_object** out, TTMStrO** src, std::int64_t* start, std::int64_t* end, __TTMTransparentStruct* ctx) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::int64_t st = start ? *start : 0;
    std::int64_t en = end ? *end : static_cast<std::int64_t>(s.size());
    if (st < 0) st = 0;
    if (en > static_cast<std::int64_t>(s.size())) en = static_cast<std::int64_t>(s.size());
    std::string sub = (st < en) ? s.substr(static_cast<std::size_t>(st), static_cast<std::size_t>(en - st)) : "";
    *out = TTMStrO_from_cstr(sub.c_str(), ctx);
}

void bridge_ttm_str_concat(_object** out, TTMStrO** lhs, TTMStrO** rhs, __TTMTransparentStruct* ctx) {
    if (!out) return;
    *out = TTMStrO_add(lhs ? *lhs : nullptr, rhs ? *rhs : nullptr, ctx);
}

void bridge_ttm_str_index_of(std::int64_t* out, TTMStrO** src, TTMStrO** sub, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::string needle = (sub && *sub) ? ttm_ttmstro_to_cstr(*sub) : "";
    auto pos = s.find(needle);
    *out = (pos == std::string::npos) ? -1 : static_cast<std::int64_t>(pos);
}

void bridge_ttm_str_last_index_of(std::int64_t* out, TTMStrO** src, TTMStrO** sub, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    std::string needle = (sub && *sub) ? ttm_ttmstro_to_cstr(*sub) : "";
    auto pos = s.rfind(needle);
    *out = (pos == std::string::npos) ? -1 : static_cast<std::int64_t>(pos);
}

void bridge_ttm_str_isalpha(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    *out = (!s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isalpha(c) != 0; })) ? 1 : 0;
}

void bridge_ttm_str_isdigit(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    *out = (!s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isdigit(c) != 0; })) ? 1 : 0;
}

void bridge_ttm_str_islower(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    *out = (!s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::islower(c) != 0; })) ? 1 : 0;
}

void bridge_ttm_str_isupper(std::int64_t* out, TTMStrO** src, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    std::string s = (src && *src) ? ttm_ttmstro_to_cstr(*src) : "";
    *out = (!s.empty() && std::all_of(s.begin(), s.end(), [](unsigned char c) { return std::isupper(c) != 0; })) ? 1 : 0;
}

// ==============================================================================
// 3. Math & List Bridges (`0x19df4..0x27838`)
// ==============================================================================
void bridge_ttm_exp(double* out, double* val) {
    if (out) *out = val ? std::exp(*val) : 1.0;
}

void bridge_ttm_fabs(double* out, double* val) {
    if (out) *out = val ? std::fabs(*val) : 0.0;
}

void bridge_ttm_log10(double* out, double* val) {
    if (out) *out = (val && *val > 0.0) ? std::log10(*val) : 0.0;
}

void bridge_ttm_sqrt(double* out, double* val) {
    if (out) *out = (val && *val >= 0.0) ? std::sqrt(*val) : 0.0;
}

void bridge_ttm_round(std::int64_t* out, double* val) {
    if (out) *out = val ? static_cast<std::int64_t>(std::llround(*val)) : 0;
}

// Disassembly @ 0x1a10c: returns 1 (Android OS identifier)
void bridge_ttm_platform_os(std::int64_t* out) {
    if (out) *out = 1;
}

void bridge_ttm_list_avg(double* out, TTMListO** list, __TTMTransparentStruct* ctx) {
    if (out) *out = (list && *list) ? TTMListO_favg_value(*list, ctx) : 0.0;
}

void bridge_ttm_list_sum(double* out, TTMListO** list, __TTMTransparentStruct* ctx) {
    if (out) *out = (list && *list) ? TTMListO_sum_value(*list, ctx) : 0.0;
}

void bridge_ttm_list_variance(double* out, TTMListO** list, __TTMTransparentStruct* ctx) {
    if (out) *out = (list && *list) ? TTMListo_variance_value(*list, ctx) : 0.0;
}

void bridge_ttm_list_standard_deviation(double* out, TTMListO** list, __TTMTransparentStruct* ctx) {
    if (out) *out = (list && *list) ? TTMListo_std_deviation_value(*list, ctx) : 0.0;
}

void bridge_ttm_list_sort(TTMListO** list, std::int64_t* descending, __TTMTransparentStruct* /*ctx*/) {
    if (!list || !*list) return;
    const bool desc = (descending && *descending != 0);
    auto& ints = (*list)->int_items;
    auto& flts = (*list)->float_items;
    if (desc) {
        std::sort(ints.begin(), ints.end(), std::greater<std::int64_t>());
        std::sort(flts.begin(), flts.end(), std::greater<double>());
    } else {
        std::sort(ints.begin(), ints.end());
        std::sort(flts.begin(), flts.end());
    }
}

void bridge_ttm_list_percentile(double* out, TTMListO** list, double* q, __TTMTransparentStruct* /*ctx*/) {
    if (!out) return;
    if (!list || !*list || !q) {
        *out = 0.0;
        return;
    }
    std::vector<double> vals = (*list)->float_items;
    if (vals.empty()) {
        for (std::int64_t v : (*list)->int_items) vals.push_back(static_cast<double>(v));
    }
    if (vals.empty()) {
        *out = 0.0;
        return;
    }
    std::sort(vals.begin(), vals.end());
    const double clamped_q = std::clamp(*q, 0.0, 1.0);
    const double pos = clamped_q * static_cast<double>(vals.size() - 1);
    const auto lower = static_cast<std::size_t>( std::floor(pos));
    const auto upper = static_cast<std::size_t>(std::ceil(pos));
    const double weight = pos - static_cast<double>(lower);
    *out = vals[lower] * (1.0 - weight) + vals[upper] * weight;
}

void bridge_make_range_list(_object** out, std::int64_t* start, std::int64_t* stop, std::int64_t* step, __TTMTransparentStruct* ctx) {
    if (!out) return;
    const std::int64_t st = start ? *start : 0;
    const std::int64_t sp = stop ? *stop : 0;
    const std::int64_t sc = (step && *step != 0) ? *step : 1;
    auto* list = TTMListO_create(0, TTMListElemKind::kIntElements, ctx);
    for (std::int64_t cur = st; (sc > 0) ? (cur < sp) : (cur > sp); cur += sc) {
        TTMListO_add_int_value(list, cur, ctx);
    }
    *out = list;
}

// ==============================================================================
// 4. Keva KV (`ttm_core_repo`) & AppLog Bridges (`0x4934c..0x4a2fc`)
// ==============================================================================
std::string make_ttm_kv_actual_key(TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* /*ctx*/) {
    std::string g = (group && *group) ? ttm_ttmstro_to_cstr(*group) : "default";
    std::string k = (key && *key) ? ttm_ttmstro_to_cstr(*key) : "";
    return g + "_" + k;
}

void bridge_ttm_kv_store_bool_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, std::int64_t* val, __TTMTransparentStruct* ctx) {
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    repo.store[make_ttm_kv_actual_key(group, key, ctx)] = static_cast<bool>(val && *val != 0);
    if (out) *out = 1;
}

void bridge_ttm_kv_store_int_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, std::int64_t* val, __TTMTransparentStruct* ctx) {
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    repo.store[make_ttm_kv_actual_key(group, key, ctx)] = static_cast<std::int64_t>(val ? *val : 0);
    if (out) *out = 1;
}

void bridge_ttm_kv_store_float_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, double* val, __TTMTransparentStruct* ctx) {
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    repo.store[make_ttm_kv_actual_key(group, key, ctx)] = static_cast<double>(val ? *val : 0.0);
    if (out) *out = 1;
}

void bridge_ttm_kv_store_str_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, TTMStrO** val, __TTMTransparentStruct* ctx) {
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    repo.store[make_ttm_kv_actual_key(group, key, ctx)] = std::string((val && *val) ? ttm_ttmstro_to_cstr(*val) : "");
    if (out) *out = 1;
}

void bridge_ttm_kv_get_bool_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx) {
    if (!out) return;
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    auto it = repo.store.find(make_ttm_kv_actual_key(group, key, ctx));
    *out = (it != repo.store.end() && it->second.type() == typeid(bool) && std::any_cast<bool>(it->second)) ? 1 : 0;
}

void bridge_ttm_kv_get_int_value(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx) {
    if (!out) return;
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    auto it = repo.store.find(make_ttm_kv_actual_key(group, key, ctx));
    *out = (it != repo.store.end() && it->second.type() == typeid(std::int64_t)) ? std::any_cast<std::int64_t>(it->second) : 0;
}

void bridge_ttm_kv_get_float_value(double* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx) {
    if (!out) return;
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    auto it = repo.store.find(make_ttm_kv_actual_key(group, key, ctx));
    *out = (it != repo.store.end() && it->second.type() == typeid(double)) ? std::any_cast<double>(it->second) : 0.0;
}

void bridge_ttm_kv_get_str_value(_object** out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx) {
    if (!out) return;
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    auto it = repo.store.find(make_ttm_kv_actual_key(group, key, ctx));
    std::string val = (it != repo.store.end() && it->second.type() == typeid(std::string)) ? std::any_cast<std::string>(it->second) : "";
    *out = TTMStrO_from_cstr(val.c_str(), ctx);
}

void bridge_ttm_kv_contains_key(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx) {
    if (!out) return;
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    *out = (repo.store.find(make_ttm_kv_actual_key(group, key, ctx)) != repo.store.end()) ? 1 : 0;
}

void bridge_ttm_kv_remove_key(std::int64_t* out, TTMStrO** group, TTMStrO** key, __TTMTransparentStruct* ctx) {
    auto& repo = GetKevaCoreRepo();
    std::lock_guard<std::mutex> lock(repo.mtx);
    repo.store.erase(make_ttm_kv_actual_key(group, key, ctx));
    if (out) *out = 1;
}

void bridge_ttm_send_applog(std::int64_t* out, TTMStrO** /*event_name*/, _dictobject** /*params*/, __TTMTransparentStruct* /*ctx*/) {
    if (out) *out = 1;
}

} // namespace NextAI::OpenCut::TTMachineCore
