// ============================================================================
// File: ttmstrategycenter_bdi_feature.cpp
// Target: libTTMStrategyCenter.so (AArch64)
//
// Description (EN):
// Implementation of Universal BDI function loader (`AnTTMPlatformUniversalBdiFunLoader`
// @ `0x2324c`), BDI address resolvers (`TTMPlatformGetUniversalBdiAddress` @ `0x25a34`,
// `strategy_center_get_bdi_address` @ `0x2cf14`), and Feature Center bridge
// (`bridge_ttm_feature_center_get_value` @ `0x26e78` & 10 `bridge_ttm_feature_center_get_*`
// functions @ `0x271f8..0x27e00`).
//
// Mô tả (VI):
// Hiện thực hóa bộ nạp hàm BDI vạn năng (`AnTTMPlatformUniversalBdiFunLoader`
// tại `0x2324c`), hàm phân giải địa chỉ BDI (`TTMPlatformGetUniversalBdiAddress` tại `0x25a34`,
// `strategy_center_get_bdi_address` tại `0x2cf14`), và cầu nối Feature Center
// (`bridge_ttm_feature_center_get_value` tại `0x26e78` & 10 hàm `bridge_ttm_feature_center_get_*`
// tại `0x271f8..0x27e00`).
// ============================================================================

#include "ttmstrategycenter_bdi_feature.h"

namespace nextai {
namespace ttm_strategy_center {

// ============================================================================
// 1. Global Type Objects & BDI Map (.data / .bss @ 0x64008..0x64250)
// Các đối tượng kiểu dữ liệu toàn cục & bảng ánh xạ BDI
// ============================================================================
TTMTypeObject TTMDictO_Type   = {"TTMDict",   32, 0};
TTMTypeObject TTMIntO_Type    = {"TTMInt",    24, 0};
TTMTypeObject TTMFloatO_Type  = {"TTMFloat",  24, 0};
TTMTypeObject TTMStringO_Type = {"TTMString", 48, 0};
TTMTypeObject TTMListO_Type   = {"TTMList",   48, 0};
TTMTypeObject TTMBoolO_Type   = {"TTMBool",   24, 0};
TTMTypeObject TTMByteDtO_Type = {"TTMByteDtType", 32, 0}; // @ 0x64070 (192 B descriptor)

namespace {

// Thread-local user extension function address (__emutls_v.strategy_center_user_func_address @ 0x64020)
thread_local UserExtendFuncAddressResolver g_tls_user_func_address = nullptr;

// Global BDI address map (an_ttm_platform_universal_bdi_address_map @ 0x64140)
std::unordered_map<std::string, void*>& getGlobalBdiMapMutable() {
    static std::unordered_map<std::string, void*> s_bdi_map;
    return s_bdi_map;
}

// Feature Center in-memory store (simulating IFeatureCenterDataManager JNI callbacks)
struct FeatureStore {
    std::mutex mtx;
    std::unordered_map<std::string, std::any> entries;
    bool manager_active{true};
};

FeatureStore& getFeatureStore() {
    static FeatureStore s_store;
    return s_store;
}

std::string makeFeatureKey(const char* group, const char* key, const char* extra) {
    std::string g = group ? group : "";
    std::string k = key ? key : "";
    std::string e = (extra && extra[0] != '\0') ? extra : "";
    return g + "::" + k + "::" + e;
}

const char* extractTtmCString(void** obj_slot) noexcept {
    if (!obj_slot || !*obj_slot) {
        return nullptr;
    }
    const auto* obj = static_cast<const _object*>(*obj_slot);
    if (obj->data_ptr) {
        return static_cast<const char*>(obj->data_ptr);
    }
    if (!obj->owned_str.empty()) {
        return obj->owned_str.c_str();
    }
    return nullptr;
}

void recordStateError(__TTMTransparentStruct* ctx, int32_t code, const char* func_name, int32_t line) noexcept {
    if (ctx && ctx->error) {
        ctx->error->code      = code;      // +0x00
        ctx->error->func_name = func_name; // +0x08
        ctx->error->line      = line;      // +0x10
    }
}

} // namespace

// ============================================================================
// 2. AnTTMPlatformUniversalBdiFunLoader (0x2324c..0x25a34, 10,216 B)
// Bộ nạp 17 hàm BDI vạn năng với tiền tố "universal."
// ============================================================================
// Disassembly @ 0x23270..0x24230:
//   Constructs 17 pairs of ("universal" + "." + <suffix>, reinterpret_cast<void*>(fn))
//   and calls __hash_table::__assign_unique (0x25d7c) into an_ttm_platform_universal_bdi_address_map (0x64140).
AnTTMPlatformUniversalBdiFunLoader::AnTTMPlatformUniversalBdiFunLoader() {
    const std::string prefix = std::string("universal") + ".";
    std::pair<const std::string, void*> init_list[17] = {
        {prefix + "ttm_feature_center_get_int_value",       reinterpret_cast<void*>(&bridge_ttm_feature_center_get_int_value)},
        {prefix + "ttm_feature_center_get_bool_value",      reinterpret_cast<void*>(&bridge_ttm_feature_center_get_bool_value)},
        {prefix + "ttm_feature_center_get_double_value",    reinterpret_cast<void*>(&bridge_ttm_feature_center_get_double_value)},
        {prefix + "ttm_feature_center_get_str_value",       reinterpret_cast<void*>(&bridge_ttm_feature_center_get_string_value)},
        {prefix + "ttm_feature_center_get_dict_value",      reinterpret_cast<void*>(&bridge_ttm_feature_center_get_dict_value)},
        {prefix + "ttm_feature_center_get_list_value",      reinterpret_cast<void*>(&bridge_ttm_feature_center_get_list_value)},
        {prefix + "ttm_register_cep_rule",                  reinterpret_cast<void*>(&bridge_ttm_register_cep_rule)},
        {prefix + "ttm_get_or_create_dt_engine",            reinterpret_cast<void*>(&bridge_ttm_get_or_create_dt_engine)},
        {prefix + "ttm_release_dt_engine",                  reinterpret_cast<void*>(&bridge_ttm_release_dt_engine)},
        {prefix + "ttm_dt_engine_load_model",               reinterpret_cast<void*>(&bridge_ttm_dt_engine_load_model)},
        {prefix + "ttm_get_dt_engine_model_info",           reinterpret_cast<void*>(&bridge_ttm_get_dt_engine_model_info)},
        {prefix + "ttm_dt_engine_predict",                  reinterpret_cast<void*>(&bridge_ttm_dt_engine_predict)},
        {prefix + "ttm_dt_engine_predict_raw",              reinterpret_cast<void*>(&bridge_ttm_dt_engine_predict_raw)},
        {prefix + "ttm_feature_center_get_ext_list",        reinterpret_cast<void*>(&bridge_ttm_feature_center_get_ext_list)},
        {prefix + "ttm_feature_center_get_ext_dict",        reinterpret_cast<void*>(&bridge_ttm_feature_center_get_ext_dict)},
        {prefix + "ttm_feature_center_get_extobj_by_index", reinterpret_cast<void*>(&bridge_ttm_feature_center_get_extobj_by_index)},
        {prefix + "ttm_feature_center_get_extobj_by_key",   reinterpret_cast<void*>(&bridge_ttm_feature_center_get_extobj_by_key)}
    };

    auto& map = getGlobalBdiMapMutable();
    map.clear();
    for (const auto& kv : init_list) {
        map.emplace(kv.first, kv.second);
    }
}

const std::unordered_map<std::string, void*>& AnTTMPlatformUniversalBdiFunLoader::getMap() noexcept {
    static AnTTMPlatformUniversalBdiFunLoader s_loader;
    (void)s_loader;
    return getGlobalBdiMapMutable();
}

// ============================================================================
// 3. TTMPlatformGetUniversalBdiAddress (0x25a34, 20 B) & strategy_center_get_bdi_address (0x2cf14, 76 B)
// ============================================================================
// Disassembly @ 0x25a34:
//   adrp x8, #0x63000; ldr x8, [x8, #0xe70]; mov x1, x0; mov x0, x8; b #0x22530
void* TTMPlatformGetUniversalBdiAddress(const char* name) noexcept {
    if (!name) {
        return nullptr;
    }
    const auto& map = AnTTMPlatformUniversalBdiFunLoader::getMap();
    auto it = map.find(name);
    if (it != map.end()) {
        return it->second;
    }
    return nullptr;
}

void strategy_center_record_user_func_address(UserExtendFuncAddressResolver cb) noexcept {
    g_tls_user_func_address = cb;
}

// Disassembly @ 0x2cf14..0x2cf5c:
//   mov x19, x0
//   adrp x0, #0x63000; ldr x0, [x0, #0xe30]; bl __emutls_get_address
//   ldr x8, [x0]; cbz x8, #0x2cf50
//   mov x0, x19; blr x8; cbz x0, #0x2cf50; ret
// 0x2cf50:
//   mov x0, x19; b TTMPlatformGetUniversalBdiAddress
void* strategy_center_get_bdi_address(const char* name) noexcept {
    if (g_tls_user_func_address != nullptr) {
        void* user_resolved = g_tls_user_func_address(name);
        if (user_resolved != nullptr) {
            return user_resolved;
        }
    }
    return TTMPlatformGetUniversalBdiAddress(name);
}

// ============================================================================
// 4. Feature Center Registration & bridge_ttm_feature_center_get_value (0x26e78, 428 B)
// ============================================================================
void registerFeatureCenterValue(
    const std::string& group,
    const std::string& key,
    const std::string& extra,
    const std::any& value) {
    auto& store = getFeatureStore();
    std::lock_guard<std::mutex> lock(store.mtx);
    store.entries[makeFeatureKey(group.c_str(), key.c_str(), extra.c_str())] = value;
}

// Disassembly @ 0x26e78..0x27020:
//   Checks jTTMGetFeatureCenterManagerObj (0x64230) != nullptr.
//   Extracts char* from [group_obj]+0x28, [key_obj]+0x28, [extra_obj]+0x28.
//   Checks value_type <= 6 (cmp w25, #6 @ 0x26f20), then uses 7-entry jump table @ 0x51212:
//     type 0, 1, 2 (String, Dict, List) -> CallObjectMethod -> stores jobject at *out_value
//     type 3, 4 (Bool, Int)             -> CallLongMethod   -> stores int64_t at *out_value
//     type 5 (Double)                   -> CallDoubleMethod -> stores double at *out_value
void bridge_ttm_feature_center_get_value(
    void* jni_env,
    void** group_obj,
    void** key_obj,
    void** extra_obj,
    int value_type,
    void* out_value,
    void* method_id,
    __TTMTransparentStruct* ctx) noexcept {
    (void)jni_env;
    (void)method_id;
    (void)ctx;
    if (!out_value || value_type < 0 || value_type > 6) {
        return;
    }

    const char* group_str = extractTtmCString(group_obj);
    const char* key_str   = extractTtmCString(key_obj);
    const char* extra_str = extractTtmCString(extra_obj);
    if (!group_str || !key_str) {
        return;
    }

    auto& store = getFeatureStore();
    std::lock_guard<std::mutex> lock(store.mtx);
    if (!store.manager_active) {
        return;
    }

    auto it = store.entries.find(makeFeatureKey(group_str, key_str, extra_str));
    if (it == store.entries.end()) {
        return;
    }

    switch (value_type) {
        case 0: // String
        case 1: // Dict
        case 2: // List
            if (it->second.type() == typeid(_object*)) {
                *static_cast<_object**>(out_value) = std::any_cast<_object*>(it->second);
            }
            break;
        case 3: // Bool (stored as int64_t: 0 or 1, sentinel kLongMaxValue)
        case 4: // Int (stored as int64_t, sentinel kLongMaxValue)
            if (it->second.type() == typeid(int64_t)) {
                *static_cast<int64_t*>(out_value) = std::any_cast<int64_t>(it->second);
            } else if (it->second.type() == typeid(bool)) {
                *static_cast<int64_t*>(out_value) = std::any_cast<bool>(it->second) ? 1LL : 0LL;
            }
            break;
        case 5: // Double (stored as double, sentinel kDoubleMaxValue)
            if (it->second.type() == typeid(double)) {
                *static_cast<double*>(out_value) = std::any_cast<double>(it->second);
            }
            break;
        default:
            break;
    }
}

// ============================================================================
// 5. 10 Exported Feature Center BDI Bridge Functions (0x271f8..0x27e00)
// 10 hàm cầu nối BDI truy xuất dữ liệu Feature Center
// ============================================================================

// Disassembly @ 0x271f8..0x27320 (300 B):
//   Initializes temp = LONG_MAX_VALUE (0x7fffffffffffffff @ 0x64008).
//   If ctx->jni_env == nullptr, sets error 0x13b (315) at line 0x3f (63).
//   Calls bridge_ttm_feature_center_get_value(..., type=4, &temp, ...).
//   If temp == LONG_MAX_VALUE, sets error 0x64 (100) at line 0x4b (75);
//   otherwise stores *out_val = temp and sets error 0 at line 0x48 (72).
void bridge_ttm_feature_center_get_int_value(
    long long* out_val, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_int_value";
    if (!ctx || !ctx->jni_env) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullFeatureCenterContext), kFunc, 0x3f);
        return;
    }
    int64_t temp = kLongMaxValue;
    bridge_ttm_feature_center_get_value(ctx->jni_env, group, key, extra, 4, &temp, nullptr, ctx);
    if (temp != kLongMaxValue) {
        if (out_val) {
            *out_val = static_cast<long long>(temp);
        }
        recordStateError(ctx, 0, kFunc, 0x48);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x4b);
    }
}

// Disassembly @ 0x27324..0x27454 (308 B):
//   Calls bridge_ttm_feature_center_get_value(..., type=3, &temp, ...).
//   Checks temp != LONG_MAX_VALUE -> *out_val = (temp == 1 ? 1 : 0).
void bridge_ttm_feature_center_get_bool_value(
    long long* out_val, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_bool_value";
    if (!ctx || !ctx->jni_env) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullFeatureCenterContext), kFunc, 0x56);
        return;
    }
    int64_t temp = kLongMaxValue;
    bridge_ttm_feature_center_get_value(ctx->jni_env, group, key, extra, 3, &temp, nullptr, ctx);
    if (temp != kLongMaxValue) {
        if (out_val) {
            *out_val = (temp == 1) ? 1LL : 0LL;
        }
        recordStateError(ctx, 0, kFunc, 0x5f);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x62);
    }
}

// Disassembly @ 0x27458..0x27580 (300 B):
//   Initializes temp = DOUBLE_MAX_VALUE (1.7976931348623157e+308 @ 0x64018).
//   Calls bridge_ttm_feature_center_get_value(..., type=5, &temp, ...).
void bridge_ttm_feature_center_get_double_value(
    double* out_val, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_double_value";
    if (!ctx || !ctx->jni_env) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullFeatureCenterContext), kFunc, 0x6d);
        return;
    }
    double temp = kDoubleMaxValue;
    bridge_ttm_feature_center_get_value(ctx->jni_env, group, key, extra, 5, &temp, nullptr, ctx);
    if (temp != kDoubleMaxValue) {
        if (out_val) {
            *out_val = temp;
        }
        recordStateError(ctx, 0, kFunc, 0x76);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x79);
    }
}

// Disassembly @ 0x27584..0x276e8 (360 B)
void bridge_ttm_feature_center_get_string_value(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_string_value";
    if (!ctx || !ctx->jni_env) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullFeatureCenterContext), kFunc, 0x84);
        return;
    }
    _object* obj = nullptr;
    bridge_ttm_feature_center_get_value(ctx->jni_env, group, key, extra, 0, &obj, nullptr, ctx);
    if (obj != nullptr) {
        if (out_obj) {
            *out_obj = obj;
        }
        recordStateError(ctx, 0, kFunc, 0x90);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x93);
    }
}

// Disassembly @ 0x276ec..0x27834 (332 B)
void bridge_ttm_feature_center_get_dict_value(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_dict_value";
    if (!ctx || !ctx->jni_env) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullFeatureCenterContext), kFunc, 0x9e);
        return;
    }
    _object* obj = nullptr;
    bridge_ttm_feature_center_get_value(ctx->jni_env, group, key, extra, 1, &obj, nullptr, ctx);
    if (obj != nullptr) {
        if (out_obj) {
            *out_obj = obj;
        }
        recordStateError(ctx, 0, kFunc, 0xa8);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0xab);
    }
}

// Disassembly @ 0x27838..0x27980 (332 B)
void bridge_ttm_feature_center_get_list_value(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_list_value";
    if (!ctx || !ctx->jni_env) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullFeatureCenterContext), kFunc, 0xb6);
        return;
    }
    _object* obj = nullptr;
    bridge_ttm_feature_center_get_value(ctx->jni_env, group, key, extra, 2, &obj, nullptr, ctx);
    if (obj != nullptr) {
        if (out_obj) {
            *out_obj = obj;
        }
        recordStateError(ctx, 0, kFunc, 0xc0);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0xc3);
    }
}

// Disassembly @ 0x27984..0x27af4 (372 B)
void bridge_ttm_feature_center_get_ext_list(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_ext_list";
    bridge_ttm_feature_center_get_list_value(out_obj, group, key, extra, ctx);
    if (ctx && ctx->error && ctx->error->code != 0) {
        recordStateError(ctx, ctx->error->code, kFunc, 0xd8);
    }
}

// Disassembly @ 0x27af8..0x27c68 (372 B)
void bridge_ttm_feature_center_get_ext_dict(
    void** out_obj, void** group, void** key, void** extra, __TTMTransparentStruct* ctx) noexcept {
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_ext_dict";
    bridge_ttm_feature_center_get_dict_value(out_obj, group, key, extra, ctx);
    if (ctx && ctx->error && ctx->error->code != 0) {
        recordStateError(ctx, ctx->error->code, kFunc, 0xf0);
    }
}

// Disassembly @ 0x27c6c..0x27dfc (404 B)
void bridge_ttm_feature_center_get_extobj_by_index(
    void** out_obj, void** ext_list, void** group, void** key, long long* index_ptr, __TTMTransparentStruct* ctx) noexcept {
    (void)group;
    (void)key;
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_extobj_by_index";
    if (!ext_list || !*ext_list || !index_ptr) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x105);
        return;
    }
    auto* iface = static_cast<TTMExtDataInterface*>(*ext_list);
    void* child = iface->GetExtObjectForIndex(static_cast<long>(*index_ptr), ctx);
    if (child != nullptr) {
        if (out_obj) {
            *out_obj = child;
        }
        recordStateError(ctx, 0, kFunc, 0x110);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x113);
    }
}

// Disassembly @ 0x27e00..0x27f94 (408 B)
void bridge_ttm_feature_center_get_extobj_by_key(
    void** out_obj, void** ext_dict, void** group, void** key, void** subkey, __TTMTransparentStruct* ctx) noexcept {
    (void)group;
    (void)key;
    constexpr const char* kFunc = "bridge_ttm_feature_center_get_extobj_by_key";
    const char* subkey_str = extractTtmCString(subkey);
    if (!ext_dict || !*ext_dict || !subkey_str) {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x120);
        return;
    }
    auto* iface = static_cast<TTMExtDataInterface*>(*ext_dict);
    void* child = iface->GetExtObjectForKey(subkey_str, ctx);
    if (child != nullptr) {
        if (out_obj) {
            *out_obj = child;
        }
        recordStateError(ctx, 0, kFunc, 0x12b);
    } else {
        recordStateError(ctx, static_cast<int32_t>(TTMStateErrorCode::kNullDataWrapper), kFunc, 0x12e);
    }
}

} // namespace ttm_strategy_center
} // namespace nextai
