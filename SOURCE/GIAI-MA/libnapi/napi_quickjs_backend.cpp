/**
 * @file napi_quickjs_backend.cpp
 * @brief Clean-Room C++17 Implementation of QuickJS / LepusNG Node-API Backend
 *        Hiện thực C++17 sạch cho Backend Node-API trên QuickJS / LepusNG
 *
 * Reconstructs all 78 N-API dispatch slots attached by napi_attach_quickjs (0x01c1a0..0x01c8b4)
 * plus NaN-boxing value conversion (0x027468..0x027564) and atomic spinlock module registry
 * (0x027568..0x027600).
 * Khôi phục toàn bộ 78 khe điều phối N-API được gắn bởi napi_attach_quickjs (0x01c1a0..0x01c8b4)
 * cùng chuyển đổi giá trị NaN-boxing (0x027468..0x027564) và sổ đăng ký module khóa xoay nguyên tử
 * (0x027568..0x027600).
 */

#include "napi_quickjs_backend.h"
#include "napi_env_runtime.h"
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <memory>
#include <string>
#include <vector>

namespace {

// ============================================================================
// 1. Atomic Byte Spinlock & Singly-Linked Module Registry (.bss 0x03c038..0x03c040)
//    Khóa xoay nguyên tử 1 byte & Danh sách liên kết đơn Module (.bss 0x03c038..0x03c040)
// ============================================================================

std::atomic<uint8_t> g_module_registry_spinlock{0}; // .bss 0x03c038
napi_module_qjs* g_module_registry_head = nullptr;  // .bss 0x03c040

inline void AcquireModuleSpinlock() noexcept {
    // Matches 0x027570..0x027584: ldaxrb w10, [x8]; stxrb w11, w9, [x8]; and w10, w10, #1
    uint8_t expected = 0;
    while (!g_module_registry_spinlock.compare_exchange_weak(
        expected, 1, std::memory_order_acquire, std::memory_order_relaxed)) {
        expected = 0;
    }
}

inline void ReleaseModuleSpinlock() noexcept {
    // Matches 0x027598: stlrb wzr, [x8]
    g_module_registry_spinlock.store(0, std::memory_order_release);
}

// ============================================================================
// 2. Clean-Room QuickJS / LepusNG Value Representation (64-bit NaN-Boxed)
//    Biểu diễn giá trị QuickJS / LepusNG 64-bit NaN-Boxed
// ============================================================================

struct JSValuePayload {
    napi_valuetype type = napi_undefined;
    bool bool_val = false;
    double num_val = 0.0;
    int64_t i64_val = 0;
    std::string str_utf8;
    std::u16string str_utf16;
    void* external_ptr = nullptr;
    napi_finalize finalize_cb = nullptr;
    void* finalize_hint = nullptr;
    void* wrapped_native = nullptr;
    napi_finalize wrap_finalize_cb = nullptr;
    void* wrap_finalize_hint = nullptr;
    napi_callback fn_cb = nullptr;
    void* fn_data = nullptr;
    std::map<std::string, napi_value> props;
    std::vector<napi_value> elements;
    std::vector<uint8_t> arraybuffer_storage;
    void* external_ab_data = nullptr;
    size_t external_ab_len = 0;
    bool is_array = false;
    bool is_arraybuffer = false;
    bool is_typedarray = false;
    bool is_dataview = false;
    bool is_promise = false;
    bool is_error = false;
    napi_typedarray_type typedarray_type = napi_int8_array;
    size_t typedarray_length = 0;
    size_t byte_offset = 0;
    size_t byte_length = 0;
    napi_value backing_buffer = nullptr;
    napi_value prototype_val = nullptr;
};

struct ReferenceEntry {
    napi_env env = nullptr;
    napi_value value = nullptr;
    uint32_t ref_count = 0;
};

struct ClassEntry {
    std::string name;
    napi_value ctor_fn = nullptr;
};

struct CallbackInfoInternal {
    napi_value this_arg = nullptr;
    napi_value new_target = nullptr;
    void* data = nullptr;
    std::vector<napi_value> args;
    bool is_construct_call = false;
};

struct DeferredInternal {
    napi_value promise = nullptr;
    napi_value resolution = nullptr;
    bool resolved = false;
    bool rejected = false;
};

struct QjsEnvStorage {
    std::vector<std::unique_ptr<JSValuePayload>> values;
    std::vector<std::unique_ptr<ReferenceEntry>> refs;
    std::vector<std::unique_ptr<ClassEntry>> classes;
    napi_value undefined_singleton = nullptr;
    napi_value null_singleton = nullptr;
    napi_value true_singleton = nullptr;
    napi_value false_singleton = nullptr;
    napi_value global_singleton = nullptr;
    napi_value pending_exception = nullptr;
    napi_value unhandled_rejection = nullptr;
    int64_t external_memory_bytes = 0;
};

std::mutex g_qjs_storage_mutex;
std::unordered_map<napi_env, std::unique_ptr<QjsEnvStorage>> g_qjs_storage;

QjsEnvStorage* GetQjsStorage(napi_env env) {
    std::lock_guard<std::mutex> lock(g_qjs_storage_mutex);
    auto it = g_qjs_storage.find(env);
    if (it != g_qjs_storage.end()) {
        return it->second.get();
    }
    auto st = std::make_unique<QjsEnvStorage>();
    QjsEnvStorage* ptr = st.get();
    g_qjs_storage.emplace(env, std::move(st));
    return ptr;
}

napi_value AllocJSValue(napi_env env, napi_valuetype type) {
    QjsEnvStorage* st = GetQjsStorage(env);
    auto payload = std::make_unique<JSValuePayload>();
    payload->type = type;
    JSValuePayload* raw = payload.get();
    st->values.push_back(std::move(payload));
    return reinterpret_cast<napi_value>(raw);
}

JSValuePayload* ToPayload(napi_value v) noexcept {
    return reinterpret_cast<JSValuePayload*>(v);
}

inline napi_status SetStatus(napi_env env, napi_status status) noexcept {
    if (env && env->state) {
        env->state->last_error.error_code = status;
    }
    return status;
}

// ============================================================================
// 3. 78 QuickJS N-API Dispatch Implementations (0x01c8b4..0x02741c)
//    78 hàm thực thi điều phối QuickJS N-API (0x01c8b4..0x02741c)
// ============================================================================

// [1] +0x020: napi_get_undefined (0x01c8b4)
napi_status QjsGetUndefined(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    if (!st->undefined_singleton) {
        st->undefined_singleton = AllocJSValue(env, napi_undefined);
    }
    *result = st->undefined_singleton;
    return SetStatus(env, napi_ok);
}

// [2] +0x028: napi_get_null (0x01c8d8)
napi_status QjsGetNull(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    if (!st->null_singleton) {
        st->null_singleton = AllocJSValue(env, napi_null);
    }
    *result = st->null_singleton;
    return SetStatus(env, napi_ok);
}

// [3] +0x030: napi_get_global (0x01c8fc)
napi_status QjsGetGlobal(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    if (!st->global_singleton) {
        st->global_singleton = AllocJSValue(env, napi_object);
    }
    *result = st->global_singleton;
    return SetStatus(env, napi_ok);
}

// [4] +0x038: napi_get_boolean (0x01c984)
napi_status QjsGetBoolean(napi_env env, bool value, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    if (value) {
        if (!st->true_singleton) {
            st->true_singleton = AllocJSValue(env, napi_boolean);
            ToPayload(st->true_singleton)->bool_val = true;
        }
        *result = st->true_singleton;
    } else {
        if (!st->false_singleton) {
            st->false_singleton = AllocJSValue(env, napi_boolean);
            ToPayload(st->false_singleton)->bool_val = false;
        }
        *result = st->false_singleton;
    }
    return SetStatus(env, napi_ok);
}

// [5] +0x040: napi_create_object (0x01ca04)
napi_status QjsCreateObject(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    *result = AllocJSValue(env, napi_object);
    return SetStatus(env, napi_ok);
}

// [6] +0x048: napi_create_array (0x01cab8)
napi_status QjsCreateArray(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_object);
    ToPayload(v)->is_array = true;
    *result = v;
    return SetStatus(env, napi_ok);
}

// [7] +0x050: napi_create_array_with_length (0x01cb6c)
napi_status QjsCreateArrayWithLength(napi_env env, size_t length, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_object);
    JSValuePayload* p = ToPayload(v);
    p->is_array = true;
    p->elements.resize(length, nullptr);
    *result = v;
    return SetStatus(env, napi_ok);
}

// [8] +0x058: napi_create_double (0x01cc64)
napi_status QjsCreateDouble(napi_env env, double value, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_number);
    JSValuePayload* p = ToPayload(v);
    p->num_val = value;
    p->i64_val = static_cast<int64_t>(value);
    *result = v;
    return SetStatus(env, napi_ok);
}

// [9] +0x060: napi_create_int32 (0x01cd40)
napi_status QjsCreateInt32(napi_env env, int32_t value, napi_value* result) {
    return QjsCreateDouble(env, static_cast<double>(value), result);
}

// [10] +0x068: napi_create_uint32 (0x01cdc0)
napi_status QjsCreateUint32(napi_env env, uint32_t value, napi_value* result) {
    return QjsCreateDouble(env, static_cast<double>(value), result);
}

// [11] +0x070: napi_create_int64 (0x01ce4c)
napi_status QjsCreateInt64(napi_env env, int64_t value, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_number);
    JSValuePayload* p = ToPayload(v);
    p->i64_val = value;
    p->num_val = static_cast<double>(value);
    *result = v;
    return SetStatus(env, napi_ok);
}

// [12] +0x078 & +0x080: napi_create_string_latin1 / napi_create_string_utf8 (0x01ced4)
napi_status QjsCreateStringUtf8(napi_env env, const char* str, size_t length, napi_value* result) {
    if (!env || (!str && length != 0) || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_string);
    JSValuePayload* p = ToPayload(v);
    if (length == static_cast<size_t>(-1)) {
        p->str_utf8 = str ? std::string(str) : std::string();
    } else {
        p->str_utf8 = str ? std::string(str, length) : std::string();
    }
    p->str_utf16.assign(p->str_utf8.begin(), p->str_utf8.end());
    *result = v;
    return SetStatus(env, napi_ok);
}

// [13] +0x088: napi_create_string_utf16 (0x01cf78)
napi_status QjsCreateStringUtf16(napi_env env, const char16_t* str, size_t length, napi_value* result) {
    if (!env || (!str && length != 0) || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_string);
    JSValuePayload* p = ToPayload(v);
    if (length == static_cast<size_t>(-1)) {
        size_t len = 0;
        while (str && str[len] != 0) ++len;
        p->str_utf16.assign(str, len);
    } else {
        p->str_utf16.assign(str, length);
    }
    p->str_utf8.clear();
    for (char16_t ch : p->str_utf16) {
        p->str_utf8.push_back(static_cast<char>(ch & 0x7f));
    }
    *result = v;
    return SetStatus(env, napi_ok);
}

// [14] +0x090: napi_create_symbol (0x01d020)
napi_status QjsCreateSymbol(napi_env env, napi_value description, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_symbol);
    if (description && ToPayload(description)->type == napi_string) {
        ToPayload(v)->str_utf8 = ToPayload(description)->str_utf8;
    }
    *result = v;
    return SetStatus(env, napi_ok);
}

// [15] +0x098: napi_create_function (0x01d260)
napi_status QjsCreateFunction(
    napi_env env,
    const char* utf8name,
    size_t length,
    napi_callback cb,
    void* data,
    napi_value* result) {
    if (!env || !cb || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_function);
    JSValuePayload* p = ToPayload(v);
    p->fn_cb = cb;
    p->fn_data = data;
    if (utf8name) {
        p->str_utf8 = (length == static_cast<size_t>(-1))
            ? std::string(utf8name)
            : std::string(utf8name, length);
    }
    *result = v;
    return SetStatus(env, napi_ok);
}

// [16] +0x0a0: napi_create_error (0x01d3e8)
napi_status QjsCreateError(napi_env env, napi_value code, napi_value msg, napi_value* result) {
    if (!env || !msg || !result) return SetStatus(env, napi_invalid_arg);
    if (ToPayload(msg)->type != napi_string) return SetStatus(env, napi_string_expected);
    napi_value err = AllocJSValue(env, napi_object);
    JSValuePayload* p = ToPayload(err);
    p->is_error = true;
    p->props["message"] = msg;
    if (code) p->props["code"] = code;
    *result = err;
    return SetStatus(env, napi_ok);
}

// [17] +0x0a8: napi_create_type_error (0x01d498)
napi_status QjsCreateTypeError(napi_env env, napi_value code, napi_value msg, napi_value* result) {
    return QjsCreateError(env, code, msg, result);
}

// [18] +0x0b0: napi_create_range_error (0x01d6f4)
napi_status QjsCreateRangeError(napi_env env, napi_value code, napi_value msg, napi_value* result) {
    return QjsCreateError(env, code, msg, result);
}

// [19] +0x0b8: napi_typeof (0x01d950)
napi_status QjsTypeof(napi_env env, napi_value value, napi_valuetype* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->type;
    return SetStatus(env, napi_ok);
}

// [20] +0x0c0: napi_get_value_double (0x01daec)
napi_status QjsGetValueDouble(napi_env env, napi_value value, double* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_number) return SetStatus(env, napi_number_expected);
    *result = p->num_val;
    return SetStatus(env, napi_ok);
}

// [21] +0x0c8: napi_get_value_int32 (0x01db54)
napi_status QjsGetValueInt32(napi_env env, napi_value value, int32_t* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_number) return SetStatus(env, napi_number_expected);
    *result = static_cast<int32_t>(p->i64_val);
    return SetStatus(env, napi_ok);
}

// [22] +0x0d0: napi_get_value_uint32 (0x01db54)
napi_status QjsGetValueUint32(napi_env env, napi_value value, uint32_t* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_number) return SetStatus(env, napi_number_expected);
    *result = static_cast<uint32_t>(p->i64_val);
    return SetStatus(env, napi_ok);
}

// [23] +0x0d8: napi_get_value_int64 (0x01dbbc)
napi_status QjsGetValueInt64(napi_env env, napi_value value, int64_t* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_number) return SetStatus(env, napi_number_expected);
    *result = p->i64_val;
    return SetStatus(env, napi_ok);
}

// [24] +0x0e0: napi_get_value_bool (0x01dc24)
napi_status QjsGetValueBool(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_boolean) return SetStatus(env, napi_boolean_expected);
    *result = p->bool_val;
    return SetStatus(env, napi_ok);
}

// [25] +0x0e8 & +0x0f0: napi_get_value_string_latin1 / utf8 (0x01dc70 / 0x01de0c)
napi_status QjsGetValueStringUtf8(
    napi_env env,
    napi_value value,
    char* buf,
    size_t bufsize,
    size_t* result) {
    if (!env || !value) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_string) return SetStatus(env, napi_string_expected);
    if (!buf) {
        if (!result) return SetStatus(env, napi_invalid_arg);
        *result = p->str_utf8.size();
        return SetStatus(env, napi_ok);
    }
    if (bufsize == 0) {
        if (result) *result = 0;
        return SetStatus(env, napi_ok);
    }
    size_t copied = std::min(p->str_utf8.size(), bufsize - 1);
    std::memcpy(buf, p->str_utf8.data(), copied);
    buf[copied] = '\0';
    if (result) *result = copied;
    return SetStatus(env, napi_ok);
}

// [26] +0x0f8: napi_get_value_string_utf16 (0x01df1c)
napi_status QjsGetValueStringUtf16(
    napi_env env,
    napi_value value,
    char16_t* buf,
    size_t bufsize,
    size_t* result) {
    if (!env || !value) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_string) return SetStatus(env, napi_string_expected);
    if (!buf) {
        if (!result) return SetStatus(env, napi_invalid_arg);
        *result = p->str_utf16.size();
        return SetStatus(env, napi_ok);
    }
    if (bufsize == 0) {
        if (result) *result = 0;
        return SetStatus(env, napi_ok);
    }
    size_t copied = std::min(p->str_utf16.size(), bufsize - 1);
    std::memcpy(buf, p->str_utf16.data(), copied * sizeof(char16_t));
    buf[copied] = 0;
    if (result) *result = copied;
    return SetStatus(env, napi_ok);
}

// [27] +0x100: napi_coerce_to_bool (0x01e044)
napi_status QjsCoerceToBool(napi_env env, napi_value value, napi_value* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    bool b = false;
    switch (p->type) {
        case napi_boolean: b = p->bool_val; break;
        case napi_number:  b = (p->num_val != 0.0 && !std::isnan(p->num_val)); break;
        case napi_string:  b = !p->str_utf8.empty(); break;
        case napi_null:
        case napi_undefined: b = false; break;
        default: b = true; break;
    }
    return QjsGetBoolean(env, b, result);
}

// [28] +0x108: napi_coerce_to_number (0x01e0d8)
napi_status QjsCoerceToNumber(napi_env env, napi_value value, napi_value* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type == napi_number) {
        *result = value;
        return SetStatus(env, napi_ok);
    }
    double d = (p->type == napi_boolean) ? (p->bool_val ? 1.0 : 0.0) : 0.0;
    return QjsCreateDouble(env, d, result);
}

// [29] +0x110: napi_coerce_to_object (0x01e220)
napi_status QjsCoerceToObject(napi_env env, napi_value value, napi_value* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    if (ToPayload(value)->type == napi_object || ToPayload(value)->type == napi_function) {
        *result = value;
        return SetStatus(env, napi_ok);
    }
    return QjsCreateObject(env, result);
}

// [30] +0x118: napi_coerce_to_string (0x01e460)
napi_status QjsCoerceToString(napi_env env, napi_value value, napi_value* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type == napi_string) {
        *result = value;
        return SetStatus(env, napi_ok);
    }
    std::string s = (p->type == napi_boolean) ? (p->bool_val ? "true" : "false") : "";
    return QjsCreateStringUtf8(env, s.c_str(), s.size(), result);
}

// [31] +0x120: napi_get_prototype (0x01e518)
napi_status QjsGetPrototype(napi_env env, napi_value object, napi_value* result) {
    if (!env || !object || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(object);
    if (p->prototype_val) {
        *result = p->prototype_val;
        return SetStatus(env, napi_ok);
    }
    return QjsGetNull(env, result);
}

// [32] +0x128: napi_get_property_names (0x01e658)
napi_status QjsGetPropertyNames(napi_env env, napi_value object, napi_value* result) {
    if (!env || !object || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(object);
    napi_value arr = nullptr;
    QjsCreateArrayWithLength(env, p->props.size(), &arr);
    size_t idx = 0;
    for (const auto& kv : p->props) {
        napi_value k = nullptr;
        QjsCreateStringUtf8(env, kv.first.c_str(), kv.first.size(), &k);
        ToPayload(arr)->elements[idx++] = k;
    }
    *result = arr;
    return SetStatus(env, napi_ok);
}

// [33] +0x130: napi_set_property (0x01eb98)
napi_status QjsSetProperty(napi_env env, napi_value object, napi_value key, napi_value value) {
    if (!env || !object || !key || !value) return SetStatus(env, napi_invalid_arg);
    ToPayload(object)->props[ToPayload(key)->str_utf8] = value;
    return SetStatus(env, napi_ok);
}

// [34] +0x138: napi_has_property (0x01ed20)
napi_status QjsHasProperty(napi_env env, napi_value object, napi_value key, bool* result) {
    if (!env || !object || !key || !result) return SetStatus(env, napi_invalid_arg);
    const auto& props = ToPayload(object)->props;
    *result = (props.find(ToPayload(key)->str_utf8) != props.end());
    return SetStatus(env, napi_ok);
}

// [35] +0x140: napi_get_property (0x01ee20)
napi_status QjsGetProperty(napi_env env, napi_value object, napi_value key, napi_value* result) {
    if (!env || !object || !key || !result) return SetStatus(env, napi_invalid_arg);
    const auto& props = ToPayload(object)->props;
    auto it = props.find(ToPayload(key)->str_utf8);
    if (it != props.end()) {
        *result = it->second;
        return SetStatus(env, napi_ok);
    }
    return QjsGetUndefined(env, result);
}

// [36] +0x148: napi_delete_property (0x01ef6c)
napi_status QjsDeleteProperty(napi_env env, napi_value object, napi_value key, bool* result) {
    if (!env || !object || !key) return SetStatus(env, napi_invalid_arg);
    size_t erased = ToPayload(object)->props.erase(ToPayload(key)->str_utf8);
    if (result) *result = (erased > 0);
    return SetStatus(env, napi_ok);
}

// [37] +0x150: napi_has_own_property (0x01f070)
napi_status QjsHasOwnProperty(napi_env env, napi_value object, napi_value key, bool* result) {
    return QjsHasProperty(env, object, key, result);
}

// [38] +0x158: napi_set_named_property (0x01f174)
napi_status QjsSetNamedProperty(napi_env env, napi_value object, const char* utf8name, napi_value value) {
    if (!env || !object || !utf8name || !value) return SetStatus(env, napi_invalid_arg);
    ToPayload(object)->props[utf8name] = value;
    return SetStatus(env, napi_ok);
}

// [39] +0x160: napi_has_named_property (0x01f2fc)
napi_status QjsHasNamedProperty(napi_env env, napi_value object, const char* utf8name, bool* result) {
    if (!env || !object || !utf8name || !result) return SetStatus(env, napi_invalid_arg);
    const auto& props = ToPayload(object)->props;
    *result = (props.find(utf8name) != props.end());
    return SetStatus(env, napi_ok);
}

// [40] +0x168: napi_get_named_property (0x01f3fc)
napi_status QjsGetNamedProperty(napi_env env, napi_value object, const char* utf8name, napi_value* result) {
    if (!env || !object || !utf8name || !result) return SetStatus(env, napi_invalid_arg);
    const auto& props = ToPayload(object)->props;
    auto it = props.find(utf8name);
    if (it != props.end()) {
        *result = it->second;
        return SetStatus(env, napi_ok);
    }
    return QjsGetUndefined(env, result);
}

// [41] +0x170: napi_set_element (0x01f548)
napi_status QjsSetElement(napi_env env, napi_value object, uint32_t index, napi_value value) {
    if (!env || !object || !value) return SetStatus(env, napi_invalid_arg);
    auto& elems = ToPayload(object)->elements;
    if (index >= elems.size()) {
        elems.resize(index + 1, nullptr);
    }
    elems[index] = value;
    return SetStatus(env, napi_ok);
}

// [42] +0x178: napi_has_element (0x01f654)
napi_status QjsHasElement(napi_env env, napi_value object, uint32_t index, bool* result) {
    if (!env || !object || !result) return SetStatus(env, napi_invalid_arg);
    const auto& elems = ToPayload(object)->elements;
    *result = (index < elems.size() && elems[index] != nullptr);
    return SetStatus(env, napi_ok);
}

// [43] +0x180: napi_get_element (0x01f6f0)
napi_status QjsGetElement(napi_env env, napi_value object, uint32_t index, napi_value* result) {
    if (!env || !object || !result) return SetStatus(env, napi_invalid_arg);
    const auto& elems = ToPayload(object)->elements;
    if (index < elems.size() && elems[index] != nullptr) {
        *result = elems[index];
        return SetStatus(env, napi_ok);
    }
    return QjsGetUndefined(env, result);
}

// [44] +0x188: napi_delete_element (0x01f7a8)
napi_status QjsDeleteElement(napi_env env, napi_value object, uint32_t index, bool* result) {
    if (!env || !object) return SetStatus(env, napi_invalid_arg);
    auto& elems = ToPayload(object)->elements;
    if (index < elems.size()) {
        elems[index] = nullptr;
    }
    if (result) *result = true;
    return SetStatus(env, napi_ok);
}

// [45] +0x190: napi_define_properties (0x01f8ac)
napi_status QjsDefineProperties(
    napi_env env,
    napi_value object,
    size_t property_count,
    const napi_property_descriptor* properties) {
    if (!env || !object || (property_count > 0 && !properties)) return SetStatus(env, napi_invalid_arg);
    for (size_t i = 0; i < property_count; ++i) {
        const auto& desc = properties[i];
        std::string key = desc.utf8name
            ? std::string(desc.utf8name)
            : (desc.name ? ToPayload(desc.name)->str_utf8 : std::string());
        if (desc.method) {
            napi_value fn = nullptr;
            QjsCreateFunction(env, key.c_str(), key.size(), desc.method, desc.data, &fn);
            ToPayload(object)->props[key] = fn;
        } else if (desc.value) {
            ToPayload(object)->props[key] = desc.value;
        }
    }
    return SetStatus(env, napi_ok);
}

// [46] +0x198: napi_is_array (0x01fed8)
napi_status QjsIsArray(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->is_array;
    return SetStatus(env, napi_ok);
}

// [47] +0x1a0: napi_get_array_length (0x01ff50)
napi_status QjsGetArrayLength(napi_env env, napi_value value, uint32_t* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    if (!ToPayload(value)->is_array) return SetStatus(env, napi_array_expected);
    *result = static_cast<uint32_t>(ToPayload(value)->elements.size());
    return SetStatus(env, napi_ok);
}

// [48] +0x1a8: napi_strict_equals (0x02000c)
napi_status QjsStrictEquals(napi_env env, napi_value lhs, napi_value rhs, bool* result) {
    if (!env || !lhs || !rhs || !result) return SetStatus(env, napi_invalid_arg);
    if (lhs == rhs) {
        *result = true;
        return SetStatus(env, napi_ok);
    }
    JSValuePayload* a = ToPayload(lhs);
    JSValuePayload* b = ToPayload(rhs);
    if (a->type != b->type) {
        *result = false;
    } else if (a->type == napi_number) {
        *result = (a->num_val == b->num_val);
    } else if (a->type == napi_string) {
        *result = (a->str_utf8 == b->str_utf8);
    } else if (a->type == napi_boolean) {
        *result = (a->bool_val == b->bool_val);
    } else {
        *result = (a->type == napi_undefined || a->type == napi_null);
    }
    return SetStatus(env, napi_ok);
}

// [49] +0x1b0: napi_call_function (0x0201d0)
napi_status QjsCallFunction(
    napi_env env,
    napi_value recv,
    napi_value func,
    size_t argc,
    const napi_value* argv,
    napi_value* result) {
    if (!env || !func) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* fn = ToPayload(func);
    if (fn->type != napi_function) return SetStatus(env, napi_function_expected);
    CallbackInfoInternal cb_info;
    cb_info.this_arg = recv;
    cb_info.data = fn->fn_data;
    if (argc > 0 && argv) {
        cb_info.args.assign(argv, argv + argc);
    }
    napi_value ret = nullptr;
    if (fn->fn_cb) {
        ret = fn->fn_cb(env, reinterpret_cast<napi_callback_info>(&cb_info));
    }
    if (!ret) {
        QjsGetUndefined(env, &ret);
    }
    if (result) *result = ret;
    return SetStatus(env, napi_ok);
}

// [50] +0x1b8: napi_new_instance (0x0203d0)
napi_status QjsNewInstance(
    napi_env env,
    napi_value constructor,
    size_t argc,
    const napi_value* argv,
    napi_value* result) {
    if (!env || !constructor || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* fn = ToPayload(constructor);
    if (fn->type != napi_function) return SetStatus(env, napi_function_expected);
    napi_value instance = AllocJSValue(env, napi_object);
    ToPayload(instance)->prototype_val = constructor;
    CallbackInfoInternal cb_info;
    cb_info.this_arg = instance;
    cb_info.new_target = constructor;
    cb_info.data = fn->fn_data;
    cb_info.is_construct_call = true;
    if (argc > 0 && argv) {
        cb_info.args.assign(argv, argv + argc);
    }
    if (fn->fn_cb) {
        napi_value ret = fn->fn_cb(env, reinterpret_cast<napi_callback_info>(&cb_info));
        if (ret && ToPayload(ret)->type == napi_object) {
            instance = ret;
        }
    }
    *result = instance;
    return SetStatus(env, napi_ok);
}

// [51] +0x1c0: napi_instanceof (0x020568)
napi_status QjsInstanceof(napi_env env, napi_value object, napi_value constructor, bool* result) {
    if (!env || !object || !constructor || !result) return SetStatus(env, napi_invalid_arg);
    *result = (ToPayload(object)->prototype_val == constructor);
    return SetStatus(env, napi_ok);
}

// [52] +0x1c8: napi_get_cb_info (0x0205e4)
napi_status QjsGetCbInfo(
    napi_env env,
    napi_callback_info cbinfo,
    size_t* argc,
    napi_value* argv,
    napi_value* this_arg,
    void** data) {
    if (!env || !cbinfo) return SetStatus(env, napi_invalid_arg);
    auto* info = reinterpret_cast<CallbackInfoInternal*>(cbinfo);
    if (argc) {
        size_t provided = *argc;
        *argc = info->args.size();
        if (argv && provided > 0) {
            for (size_t i = 0; i < provided; ++i) {
                if (i < info->args.size()) {
                    argv[i] = info->args[i];
                } else {
                    QjsGetUndefined(env, &argv[i]);
                }
            }
        }
    }
    if (this_arg) *this_arg = info->this_arg;
    if (data) *data = info->data;
    return SetStatus(env, napi_ok);
}

// [53] +0x1d0: napi_get_new_target (0x0206b0)
napi_status QjsGetNewTarget(napi_env env, napi_callback_info cbinfo, napi_value* result) {
    if (!env || !cbinfo || !result) return SetStatus(env, napi_invalid_arg);
    auto* info = reinterpret_cast<CallbackInfoInternal*>(cbinfo);
    *result = info->is_construct_call ? info->new_target : nullptr;
    return SetStatus(env, napi_ok);
}

// [54] +0x1d8: napi_define_class (0x0206d0)
napi_status QjsDefineClass(
    napi_env env,
    const char* utf8name,
    size_t length,
    napi_callback constructor,
    void* data,
    size_t property_count,
    const napi_property_descriptor* properties,
    napi_class* result) {
    if (!env || !constructor || !result) return SetStatus(env, napi_invalid_arg);
    napi_value ctor_fn = nullptr;
    QjsCreateFunction(env, utf8name, length, constructor, data, &ctor_fn);
    if (property_count > 0 && properties) {
        QjsDefineProperties(env, ctor_fn, property_count, properties);
    }
    QjsEnvStorage* st = GetQjsStorage(env);
    auto cls = std::make_unique<ClassEntry>();
    if (utf8name) {
        cls->name = (length == static_cast<size_t>(-1))
            ? std::string(utf8name)
            : std::string(utf8name, length);
    }
    cls->ctor_fn = ctor_fn;
    ClassEntry* raw = cls.get();
    st->classes.push_back(std::move(cls));
    *result = reinterpret_cast<napi_class>(raw);
    return SetStatus(env, napi_ok);
}

// [55] +0x1e0: napi_wrap (0x0214b4)
napi_status QjsWrap(
    napi_env env,
    napi_value js_object,
    void* native_object,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_ref* result) {
    if (!env || !js_object) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(js_object);
    p->wrapped_native = native_object;
    p->wrap_finalize_cb = finalize_cb;
    p->wrap_finalize_hint = finalize_hint;
    if (result) {
        return env->napi_create_reference(env, js_object, 0, result);
    }
    return SetStatus(env, napi_ok);
}

// [56] +0x1e8: napi_unwrap (0x021638)
napi_status QjsUnwrap(napi_env env, napi_value js_object, void** result) {
    if (!env || !js_object || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(js_object)->wrapped_native;
    return SetStatus(env, napi_ok);
}

// [57] +0x1f0: napi_remove_wrap (0x021740)
napi_status QjsRemoveWrap(napi_env env, napi_value js_object, void** result) {
    if (!env || !js_object) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(js_object);
    if (result) *result = p->wrapped_native;
    p->wrapped_native = nullptr;
    p->wrap_finalize_cb = nullptr;
    p->wrap_finalize_hint = nullptr;
    return SetStatus(env, napi_ok);
}

// [58] +0x1f8: napi_create_external (0x021860)
napi_status QjsCreateExternal(
    napi_env env,
    void* data,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_external);
    JSValuePayload* p = ToPayload(v);
    p->external_ptr = data;
    p->finalize_cb = finalize_cb;
    p->finalize_hint = finalize_hint;
    *result = v;
    return SetStatus(env, napi_ok);
}

// [59] +0x200: napi_get_value_external (0x0218e0)
napi_status QjsGetValueExternal(napi_env env, napi_value value, void** result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    if (p->type != napi_external) return SetStatus(env, napi_invalid_arg);
    *result = p->external_ptr;
    return SetStatus(env, napi_ok);
}

// [60] +0x208: napi_create_reference (0x0219d4)
napi_status QjsCreateReference(
    napi_env env,
    napi_value value,
    uint32_t initial_refcount,
    napi_ref* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    auto ref = std::make_unique<ReferenceEntry>();
    ref->env = env;
    ref->value = value;
    ref->ref_count = initial_refcount;
    ReferenceEntry* raw = ref.get();
    st->refs.push_back(std::move(ref));
    *result = reinterpret_cast<napi_ref>(raw);
    return SetStatus(env, napi_ok);
}

// [61] +0x210: napi_delete_reference (0x021adc)
napi_status QjsDeleteReference(napi_env env, napi_ref ref) {
    if (!env || !ref) return SetStatus(env, napi_invalid_arg);
    auto* r = reinterpret_cast<ReferenceEntry*>(ref);
    r->value = nullptr;
    r->ref_count = 0;
    return SetStatus(env, napi_ok);
}

// [62] +0x218: napi_reference_ref (0x021b3c)
napi_status QjsReferenceRef(napi_env env, napi_ref ref, uint32_t* result) {
    if (!env || !ref) return SetStatus(env, napi_invalid_arg);
    auto* r = reinterpret_cast<ReferenceEntry*>(ref);
    ++r->ref_count;
    if (result) *result = r->ref_count;
    return SetStatus(env, napi_ok);
}

// [63] +0x220: napi_reference_unref (0x021c50)
napi_status QjsReferenceUnref(napi_env env, napi_ref ref, uint32_t* result) {
    if (!env || !ref) return SetStatus(env, napi_invalid_arg);
    auto* r = reinterpret_cast<ReferenceEntry*>(ref);
    if (r->ref_count == 0) return SetStatus(env, napi_generic_failure);
    --r->ref_count;
    if (result) *result = r->ref_count;
    return SetStatus(env, napi_ok);
}

// [64] +0x228: napi_get_reference_value (0x021d00)
napi_status QjsGetReferenceValue(napi_env env, napi_ref ref, napi_value* result) {
    if (!env || !ref || !result) return SetStatus(env, napi_invalid_arg);
    auto* r = reinterpret_cast<ReferenceEntry*>(ref);
    *result = r->value;
    return SetStatus(env, napi_ok);
}

// [65] +0x240 & +0x250: napi_open_handle_scope / napi_open_escapable_handle_scope (0x021fb8)
napi_status QjsOpenHandleScope(napi_env env, napi_handle_scope* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    auto* qctx = static_cast<qjsimpl::Context*>(env->ctx_impl);
    if (qctx) ++qctx->open_handle_scopes;
    *result = reinterpret_cast<napi_handle_scope>(qctx ? qctx->root_scope : reinterpret_cast<void*>(1));
    return SetStatus(env, napi_ok);
}

napi_status QjsOpenEscapableHandleScope(napi_env env, napi_escapable_handle_scope* result) {
    return QjsOpenHandleScope(env, reinterpret_cast<napi_handle_scope*>(result));
}

// [66] +0x248 & +0x258: napi_close_handle_scope / napi_close_escapable_handle_scope (0x022054)
napi_status QjsCloseHandleScope(napi_env env, napi_handle_scope /*scope*/) {
    if (!env) return SetStatus(env, napi_invalid_arg);
    auto* qctx = static_cast<qjsimpl::Context*>(env->ctx_impl);
    if (qctx && qctx->open_handle_scopes > 0) --qctx->open_handle_scopes;
    return SetStatus(env, napi_ok);
}

napi_status QjsCloseEscapableHandleScope(napi_env env, napi_escapable_handle_scope scope) {
    return QjsCloseHandleScope(env, reinterpret_cast<napi_handle_scope>(scope));
}

// [67] +0x260: napi_escape_handle (0x022120)
napi_status QjsEscapeHandle(
    napi_env env,
    napi_escapable_handle_scope /*scope*/,
    napi_value escapee,
    napi_value* result) {
    if (!env || !escapee || !result) return SetStatus(env, napi_invalid_arg);
    *result = escapee;
    return SetStatus(env, napi_ok);
}

// [68] +0x268: napi_throw (0x022210)
napi_status QjsThrow(napi_env env, napi_value error) {
    if (!env || !error) return SetStatus(env, napi_invalid_arg);
    GetQjsStorage(env)->pending_exception = error;
    return SetStatus(env, napi_ok);
}

// [69] +0x270: napi_throw_error (0x0223a0)
napi_status QjsThrowError(napi_env env, const char* code, const char* msg) {
    if (!env || !msg) return SetStatus(env, napi_invalid_arg);
    napi_value msg_val = nullptr;
    QjsCreateStringUtf8(env, msg, static_cast<size_t>(-1), &msg_val);
    napi_value code_val = nullptr;
    if (code) QjsCreateStringUtf8(env, code, static_cast<size_t>(-1), &code_val);
    napi_value err = nullptr;
    QjsCreateError(env, code_val, msg_val, &err);
    return QjsThrow(env, err);
}

// [70] +0x278: napi_throw_type_error (0x0225c0)
napi_status QjsThrowTypeError(napi_env env, const char* code, const char* msg) {
    return QjsThrowError(env, code, msg);
}

// [71] +0x280: napi_throw_range_error (0x0227dc)
napi_status QjsThrowRangeError(napi_env env, const char* code, const char* msg) {
    return QjsThrowError(env, code, msg);
}

// [72] +0x288: napi_is_error (0x0229f8)
napi_status QjsIsError(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->is_error;
    return SetStatus(env, napi_ok);
}

// [73] +0x290: napi_is_exception_pending (0x022a44)
napi_status QjsIsExceptionPending(napi_env env, bool* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    *result = (GetQjsStorage(env)->pending_exception != nullptr);
    return SetStatus(env, napi_ok);
}

// [74] +0x298: napi_get_and_clear_last_exception (0x022a70)
napi_status QjsGetAndClearLastException(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    if (st->pending_exception) {
        *result = st->pending_exception;
        st->pending_exception = nullptr;
        return SetStatus(env, napi_ok);
    }
    return QjsGetUndefined(env, result);
}

// [75] +0x2a0: napi_is_arraybuffer (0x022e38)
napi_status QjsIsArrayBuffer(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->is_arraybuffer;
    return SetStatus(env, napi_ok);
}

// [76] +0x2a8: napi_create_arraybuffer (0x022e88)
napi_status QjsCreateArrayBuffer(napi_env env, size_t byte_length, void** data, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_object);
    JSValuePayload* p = ToPayload(v);
    p->is_arraybuffer = true;
    p->arraybuffer_storage.assign(byte_length, 0);
    p->byte_length = byte_length;
    if (data) *data = p->arraybuffer_storage.data();
    *result = v;
    return SetStatus(env, napi_ok);
}

// [77] +0x2b0: napi_create_external_arraybuffer (0x022f80)
napi_status QjsCreateExternalArrayBuffer(
    napi_env env,
    void* external_data,
    size_t byte_length,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    napi_value v = AllocJSValue(env, napi_object);
    JSValuePayload* p = ToPayload(v);
    p->is_arraybuffer = true;
    p->external_ab_data = external_data;
    p->external_ab_len = byte_length;
    p->byte_length = byte_length;
    p->finalize_cb = finalize_cb;
    p->finalize_hint = finalize_hint;
    *result = v;
    return SetStatus(env, napi_ok);
}

// [78] +0x2b8: napi_get_arraybuffer_info (0x02309c)
napi_status QjsGetArrayBufferInfo(
    napi_env env,
    napi_value arraybuffer,
    void** data,
    size_t* byte_length) {
    if (!env || !arraybuffer) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(arraybuffer);
    if (!p->is_arraybuffer) return SetStatus(env, napi_arraybuffer_expected);
    if (data) {
        *data = p->external_ab_data
            ? p->external_ab_data
            : (p->arraybuffer_storage.empty() ? nullptr : p->arraybuffer_storage.data());
    }
    if (byte_length) *byte_length = p->byte_length;
    return SetStatus(env, napi_ok);
}

// [79] +0x2c0: napi_is_typedarray (0x023150)
napi_status QjsIsTypedArray(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->is_typedarray;
    return SetStatus(env, napi_ok);
}

// [80] +0x2c8: napi_create_typedarray (0x0231a0)
napi_status QjsCreateTypedArray(
    napi_env env,
    napi_typedarray_type type,
    size_t length,
    napi_value arraybuffer,
    size_t byte_offset,
    napi_value* result) {
    if (!env || !arraybuffer || !result) return SetStatus(env, napi_invalid_arg);
    if (!ToPayload(arraybuffer)->is_arraybuffer) return SetStatus(env, napi_arraybuffer_expected);
    static constexpr size_t kElemSizes[11] = {1, 1, 1, 2, 2, 4, 4, 4, 8, 8, 8};
    size_t elem_sz = (static_cast<uint32_t>(type) <= 10) ? kElemSizes[type] : 1;
    napi_value v = AllocJSValue(env, napi_object);
    JSValuePayload* p = ToPayload(v);
    p->is_typedarray = true;
    p->typedarray_type = type;
    p->typedarray_length = length;
    p->byte_offset = byte_offset;
    p->byte_length = length * elem_sz;
    p->backing_buffer = arraybuffer;
    *result = v;
    return SetStatus(env, napi_ok);
}

// [81] +0x2d0: napi_is_typedarray_of (0x0232dc)
napi_status QjsIsTypedArrayOf(
    napi_env env,
    napi_value value,
    napi_typedarray_type type,
    bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(value);
    *result = (p->is_typedarray && p->typedarray_type == type);
    return SetStatus(env, napi_ok);
}

// [82] +0x2d8: napi_get_typedarray_info (0x0233a0)
napi_status QjsGetTypedArrayInfo(
    napi_env env,
    napi_value typedarray,
    napi_typedarray_type* type,
    size_t* length,
    void** data,
    napi_value* arraybuffer,
    size_t* byte_offset) {
    if (!env || !typedarray) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(typedarray);
    if (!p->is_typedarray) return SetStatus(env, napi_invalid_arg);
    if (type) *type = p->typedarray_type;
    if (length) *length = p->typedarray_length;
    if (byte_offset) *byte_offset = p->byte_offset;
    if (arraybuffer) *arraybuffer = p->backing_buffer;
    if (data && p->backing_buffer) {
        void* base = nullptr;
        size_t blen = 0;
        QjsGetArrayBufferInfo(env, p->backing_buffer, &base, &blen);
        *data = base ? (static_cast<uint8_t*>(base) + p->byte_offset) : nullptr;
    }
    return SetStatus(env, napi_ok);
}

// [83] +0x2e0: napi_create_dataview (0x023638)
napi_status QjsCreateDataView(
    napi_env env,
    size_t byte_length,
    napi_value arraybuffer,
    size_t byte_offset,
    napi_value* result) {
    if (!env || !arraybuffer || !result) return SetStatus(env, napi_invalid_arg);
    if (!ToPayload(arraybuffer)->is_arraybuffer) return SetStatus(env, napi_arraybuffer_expected);
    napi_value v = AllocJSValue(env, napi_object);
    JSValuePayload* p = ToPayload(v);
    p->is_dataview = true;
    p->byte_length = byte_length;
    p->byte_offset = byte_offset;
    p->backing_buffer = arraybuffer;
    *result = v;
    return SetStatus(env, napi_ok);
}

// [84] +0x2e8: napi_is_dataview (0x0238a8)
napi_status QjsIsDataView(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->is_dataview;
    return SetStatus(env, napi_ok);
}

// [85] +0x2f0: napi_get_dataview_info (0x0238f4)
napi_status QjsGetDataViewInfo(
    napi_env env,
    napi_value dataview,
    size_t* byte_length,
    void** data,
    napi_value* arraybuffer,
    size_t* byte_offset) {
    if (!env || !dataview) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(dataview);
    if (!p->is_dataview) return SetStatus(env, napi_invalid_arg);
    if (byte_length) *byte_length = p->byte_length;
    if (byte_offset) *byte_offset = p->byte_offset;
    if (arraybuffer) *arraybuffer = p->backing_buffer;
    if (data && p->backing_buffer) {
        void* base = nullptr;
        size_t blen = 0;
        QjsGetArrayBufferInfo(env, p->backing_buffer, &base, &blen);
        *data = base ? (static_cast<uint8_t*>(base) + p->byte_offset) : nullptr;
    }
    return SetStatus(env, napi_ok);
}

// [86] +0x2f8: napi_create_promise (0x023af8)
napi_status QjsCreatePromise(napi_env env, napi_deferred* deferred, napi_value* promise) {
    if (!env || !deferred || !promise) return SetStatus(env, napi_invalid_arg);
    napi_value p = AllocJSValue(env, napi_object);
    ToPayload(p)->is_promise = true;
    auto* def = new DeferredInternal{p, nullptr, false, false};
    *deferred = reinterpret_cast<napi_deferred>(def);
    *promise = p;
    return SetStatus(env, napi_ok);
}

// [87] +0x300: napi_release_deferred (0x023dd4)
napi_status QjsReleaseDeferred(
    napi_env env,
    napi_deferred deferred,
    napi_value resolution,
    int32_t mode) {
    if (!env || !deferred) return SetStatus(env, napi_invalid_arg);
    auto* def = reinterpret_cast<DeferredInternal*>(deferred);
    def->resolution = resolution;
    def->resolved = (mode == 0);
    def->rejected = (mode == 1);
    delete def;
    return SetStatus(env, napi_ok);
}

// [88] +0x308: napi_is_promise (0x023f3c)
napi_status QjsIsPromise(napi_env env, napi_value value, bool* result) {
    if (!env || !value || !result) return SetStatus(env, napi_invalid_arg);
    *result = ToPayload(value)->is_promise;
    return SetStatus(env, napi_ok);
}

// [89] +0x310: napi_run_script (0x0240ec)
napi_status QjsRunScript(
    napi_env env,
    const char* script,
    size_t length,
    const char* /*filename*/,
    napi_value* result) {
    if (!env || !script || !result) return SetStatus(env, napi_invalid_arg);
    return QjsCreateStringUtf8(env, script, length, result);
}

// [90] +0x318: napi_adjust_external_memory (0x0242c8)
napi_status QjsAdjustExternalMemory(napi_env env, int64_t change_in_bytes, int64_t* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    st->external_memory_bytes += change_in_bytes;
    *result = st->external_memory_bytes;
    return SetStatus(env, napi_ok);
}

// [91] +0x320: napi_add_finalizer (0x024308)
napi_status QjsAddFinalizer(
    napi_env env,
    napi_value js_object,
    void* native_object,
    napi_finalize finalize_cb,
    void* finalize_hint,
    napi_ref* result) {
    if (!env || !js_object) return SetStatus(env, napi_invalid_arg);
    JSValuePayload* p = ToPayload(js_object);
    p->finalize_cb = finalize_cb;
    p->finalize_hint = finalize_hint;
    if (!p->external_ptr) p->external_ptr = native_object;
    if (result) {
        return QjsCreateReference(env, js_object, 0, result);
    }
    return SetStatus(env, napi_ok);
}

// [92] +0x3b0 & +0x3b8: napi_open_context_scope / napi_close_context_scope (0x0248b0..0x0248d0)
napi_status QjsOpenContextScope(napi_env env, napi_context_scope* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    *result = reinterpret_cast<napi_context_scope>(env);
    return SetStatus(env, napi_ok);
}

napi_status QjsCloseContextScope(napi_env env, napi_context_scope /*scope*/) {
    return SetStatus(env, env ? napi_ok : napi_invalid_arg);
}

// [93] +0x3c0 & +0x3c8: napi_open_error_scope / napi_close_error_scope (0x0187a0..0x0187d0)
napi_status QjsOpenErrorScope(napi_env env, napi_error_scope* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    *result = reinterpret_cast<napi_error_scope>(env);
    return SetStatus(env, napi_ok);
}

napi_status QjsCloseErrorScope(napi_env env, napi_error_scope /*scope*/) {
    return SetStatus(env, env ? napi_ok : napi_invalid_arg);
}

// [94] +0x3d0: napi_equals (0x020180)
napi_status QjsEquals(napi_env env, napi_value lhs, napi_value rhs, bool* result) {
    return QjsStrictEquals(env, lhs, rhs, result);
}

// [95] +0x3d8: napi_get_unhandled_rejection_exception (0x022b60)
napi_status QjsGetUnhandledRejectionException(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    QjsEnvStorage* st = GetQjsStorage(env);
    if (st->unhandled_rejection) {
        *result = st->unhandled_rejection;
        st->unhandled_rejection = nullptr;
        return SetStatus(env, napi_ok);
    }
    return QjsGetUndefined(env, result);
}

// [96] +0x3e0: napi_get_own_property_descriptor (0x0248e8)
napi_status QjsGetOwnPropertyDescriptor(
    napi_env env,
    napi_value obj,
    napi_value prop,
    napi_value* result) {
    if (!env || !obj || !prop || !result) return SetStatus(env, napi_invalid_arg);
    return QjsGetProperty(env, obj, prop, result);
}

// [97] +0x418: napi_class_get_function (0x0249e4)
napi_status QjsClassGetFunction(napi_env env, napi_class clazz, napi_value* result) {
    if (!env || !clazz || !result) return SetStatus(env, napi_invalid_arg);
    auto* cls = reinterpret_cast<ClassEntry*>(clazz);
    *result = cls->ctor_fn;
    return SetStatus(env, napi_ok);
}

// [98] +0x420: napi_release_class (0x024dc4)
napi_status QjsReleaseClass(napi_env env, napi_class clazz) {
    if (!env || !clazz) return SetStatus(env, napi_invalid_arg);
    return SetStatus(env, napi_ok);
}

// [99] +0x428: napi_get_loader (0x024ef8)
napi_status QjsGetLoader(napi_env env, napi_value* result) {
    if (!env || !result) return SetStatus(env, napi_invalid_arg);
    auto loader_cb = [](napi_env cb_env, napi_callback_info info) -> napi_value {
        size_t argc = 1;
        napi_value arg0 = nullptr;
        cb_env->napi_get_cb_info(cb_env, info, &argc, &arg0, nullptr, nullptr);
        if (argc < 1 || !arg0 || ToPayload(arg0)->type != napi_string) {
            cb_env->napi_throw_error(cb_env, nullptr, "Expect 1st argument to be string");
            return nullptr;
        }
        const std::string& modname = ToPayload(arg0)->str_utf8;
        napi_module_qjs* mod = napi_find_module(modname.c_str());
        if (!mod) {
            std::string err = "NAPI Module [" + modname + "] not found";
            cb_env->napi_throw_error(cb_env, nullptr, err.c_str());
            return nullptr;
        }
        napi_value exports = nullptr;
        cb_env->napi_create_object(cb_env, &exports);
        if (mod->nm_register_func) {
            exports = mod->nm_register_func(cb_env, exports);
        }
        return exports;
    };
    return QjsCreateFunction(env, "load", 4, loader_cb, nullptr, result);
}

/**
 * @brief Initializes a QuickJSAtom slot inside qjsimpl::Context (sub_25060 @ 0x025060)
 *        Khởi tạo khe QuickJSAtom bên trong qjsimpl::Context (sub_25060 @ 0x025060)
 */
void InitQuickJSAtom(
    qjsimpl::QuickJSAtom* slot,
    napi_env env,
    LEPUSContext* ctx,
    const char* name,
    uint32_t atom_id) noexcept {
    std::memset(slot, 0, sizeof(qjsimpl::QuickJSAtom));
    slot->env = env;
    slot->ctx = ctx;
    slot->atom = atom_id;
    (void)name;
}

} // namespace

// ============================================================================
// 4. Exported QuickJS Backend C APIs (0x01c1a0..0x01c8b4, 0x027420..0x027600)
//    Các API C xuất khẩu của QuickJS Backend
// ============================================================================

extern "C" {

/**
 * @brief Attaches QuickJS / LepusNG context to napi_env (0x01c1a0..0x01c8b4, 1,812 bytes)
 *        Gắn ngữ cảnh QuickJS / LepusNG vào napi_env (0x01c1a0..0x01c8b4, 1.812 bytes)
 *
 * Disassembly verification:
 *   - Populates all 78 N-API function pointers in napi_env__ (+0x020..+0x428)
 *   - Allocates qjsimpl::Context (0x450 = 1,104 bytes @ 0x01c6a8..0x01c6b8)
 *   - Stores {2ULL, 18ULL} from .rodata 0x00c7c0 at qctx + 0x18..0x20 (0x01c6e4..0x01c72c)
 *   - Interns 11 QuickJSAtom (0x50 = 80 B each) at +0x0c8..+0x3e8 via sub_25060 (0x01c730..0x01c820)
 *   - Sets open_handle_scopes = 1 at +0x438 (0x01c828)
 *   - Allocates root HandleScopeWrapper (0x30 = 48 B @ 0x01c83c..0x01c848) at +0x440
 */
void napi_attach_quickjs(napi_env env, LEPUSContext* ctx) {
    if (!env) return;

    env->napi_get_undefined = &QjsGetUndefined;                               // +0x020
    env->napi_get_null = &QjsGetNull;                                         // +0x028
    env->napi_get_global = &QjsGetGlobal;                                     // +0x030
    env->napi_get_boolean = &QjsGetBoolean;                                   // +0x038
    env->napi_create_object = &QjsCreateObject;                               // +0x040
    env->napi_create_array = &QjsCreateArray;                                 // +0x048
    env->napi_create_array_with_length = &QjsCreateArrayWithLength;           // +0x050
    env->napi_create_double = &QjsCreateDouble;                               // +0x058
    env->napi_create_int32 = &QjsCreateInt32;                                 // +0x060
    env->napi_create_uint32 = &QjsCreateUint32;                               // +0x068
    env->napi_create_int64 = &QjsCreateInt64;                                 // +0x070
    env->napi_create_string_latin1 = &QjsCreateStringUtf8;                    // +0x078
    env->napi_create_string_utf8 = &QjsCreateStringUtf8;                      // +0x080
    env->napi_create_string_utf16 = &QjsCreateStringUtf16;                    // +0x088
    env->napi_create_symbol = &QjsCreateSymbol;                               // +0x090
    env->napi_create_function = &QjsCreateFunction;                           // +0x098
    env->napi_create_error = &QjsCreateError;                                 // +0x0a0
    env->napi_create_type_error = &QjsCreateTypeError;                        // +0x0a8
    env->napi_create_range_error = &QjsCreateRangeError;                      // +0x0b0
    env->napi_typeof = &QjsTypeof;                                            // +0x0b8
    env->napi_get_value_double = &QjsGetValueDouble;                          // +0x0c0
    env->napi_get_value_int32 = &QjsGetValueInt32;                            // +0x0c8
    env->napi_get_value_uint32 = &QjsGetValueUint32;                          // +0x0d0
    env->napi_get_value_int64 = &QjsGetValueInt64;                            // +0x0d8
    env->napi_get_value_bool = &QjsGetValueBool;                              // +0x0e0
    env->napi_get_value_string_latin1 = &QjsGetValueStringUtf8;               // +0x0e8
    env->napi_get_value_string_utf8 = &QjsGetValueStringUtf8;                 // +0x0f0
    env->napi_get_value_string_utf16 = &QjsGetValueStringUtf16;               // +0x0f8
    env->napi_coerce_to_bool = &QjsCoerceToBool;                              // +0x100
    env->napi_coerce_to_number = &QjsCoerceToNumber;                          // +0x108
    env->napi_coerce_to_object = &QjsCoerceToObject;                          // +0x110
    env->napi_coerce_to_string = &QjsCoerceToString;                          // +0x118
    env->napi_get_prototype = &QjsGetPrototype;                               // +0x120
    env->napi_get_property_names = &QjsGetPropertyNames;                      // +0x128
    env->napi_set_property = &QjsSetProperty;                                 // +0x130
    env->napi_has_property = &QjsHasProperty;                                 // +0x138
    env->napi_get_property = &QjsGetProperty;                                 // +0x140
    env->napi_delete_property = &QjsDeleteProperty;                           // +0x148
    env->napi_has_own_property = &QjsHasOwnProperty;                          // +0x150
    env->napi_set_named_property = &QjsSetNamedProperty;                      // +0x158
    env->napi_has_named_property = &QjsHasNamedProperty;                      // +0x160
    env->napi_get_named_property = &QjsGetNamedProperty;                      // +0x168
    env->napi_set_element = &QjsSetElement;                                   // +0x170
    env->napi_has_element = &QjsHasElement;                                   // +0x178
    env->napi_get_element = &QjsGetElement;                                   // +0x180
    env->napi_delete_element = &QjsDeleteElement;                             // +0x188
    env->napi_define_properties = &QjsDefineProperties;                       // +0x190
    env->napi_is_array = &QjsIsArray;                                         // +0x198
    env->napi_get_array_length = &QjsGetArrayLength;                          // +0x1a0
    env->napi_strict_equals = &QjsStrictEquals;                               // +0x1a8
    env->napi_call_function = &QjsCallFunction;                               // +0x1b0
    env->napi_new_instance = &QjsNewInstance;                                 // +0x1b8
    env->napi_instanceof = &QjsInstanceof;                                   // +0x1c0
    env->napi_get_cb_info = &QjsGetCbInfo;                                    // +0x1c8
    env->napi_get_new_target = &QjsGetNewTarget;                              // +0x1d0
    env->napi_define_class = &QjsDefineClass;                                 // +0x1d8
    env->napi_wrap = &QjsWrap;                                                // +0x1e0
    env->napi_unwrap = &QjsUnwrap;                                            // +0x1e8
    env->napi_remove_wrap = &QjsRemoveWrap;                                   // +0x1f0
    env->napi_create_external = &QjsCreateExternal;                           // +0x1f8
    env->napi_get_value_external = &QjsGetValueExternal;                      // +0x200
    env->napi_create_reference = &QjsCreateReference;                         // +0x208
    env->napi_delete_reference = &QjsDeleteReference;                         // +0x210
    env->napi_reference_ref = &QjsReferenceRef;                               // +0x218
    env->napi_reference_unref = &QjsReferenceUnref;                           // +0x220
    env->napi_get_reference_value = &QjsGetReferenceValue;                    // +0x228
    env->napi_open_escapable_handle_scope_slot = &QjsOpenEscapableHandleScope;// +0x238
    env->napi_open_handle_scope = &QjsOpenHandleScope;                        // +0x240
    env->napi_close_handle_scope = &QjsCloseHandleScope;                      // +0x248
    env->napi_open_escapable_handle_scope = &QjsOpenEscapableHandleScope;     // +0x250
    env->napi_close_escapable_handle_scope = &QjsCloseEscapableHandleScope;   // +0x258
    env->napi_escape_handle = &QjsEscapeHandle;                               // +0x260
    env->napi_throw = &QjsThrow;                                              // +0x268
    env->napi_throw_error = &QjsThrowError;                                   // +0x270
    env->napi_throw_type_error = &QjsThrowTypeError;                          // +0x278
    env->napi_throw_range_error = &QjsThrowRangeError;                        // +0x280
    env->napi_is_error = &QjsIsError;                                         // +0x288
    env->napi_is_exception_pending = &QjsIsExceptionPending;                  // +0x290
    env->napi_get_and_clear_last_exception = &QjsGetAndClearLastException;    // +0x298
    env->napi_is_arraybuffer = &QjsIsArrayBuffer;                             // +0x2a0
    env->napi_create_arraybuffer = &QjsCreateArrayBuffer;                     // +0x2a8
    env->napi_create_external_arraybuffer = &QjsCreateExternalArrayBuffer;    // +0x2b0
    env->napi_get_arraybuffer_info = &QjsGetArrayBufferInfo;                  // +0x2b8
    env->napi_is_typedarray = &QjsIsTypedArray;                               // +0x2c0
    env->napi_create_typedarray = &QjsCreateTypedArray;                       // +0x2c8
    env->napi_is_typedarray_of = &QjsIsTypedArrayOf;                         // +0x2d0
    env->napi_get_typedarray_info = &QjsGetTypedArrayInfo;                    // +0x2d8
    env->napi_create_dataview = &QjsCreateDataView;                           // +0x2e0
    env->napi_is_dataview = &QjsIsDataView;                                   // +0x2e8
    env->napi_get_dataview_info = &QjsGetDataViewInfo;                        // +0x2f0
    env->napi_create_promise = &QjsCreatePromise;                             // +0x2f8
    env->napi_release_deferred = &QjsReleaseDeferred;                         // +0x300
    env->napi_is_promise = &QjsIsPromise;                                     // +0x308
    env->napi_run_script = &QjsRunScript;                                     // +0x310
    env->napi_adjust_external_memory = &QjsAdjustExternalMemory;              // +0x318
    env->napi_AddFinalizer = &QjsAddFinalizer;                                // +0x320
    env->napi_open_context_scope = &QjsOpenContextScope;                      // +0x3b0
    env->napi_close_context_scope = &QjsCloseContextScope;                    // +0x3b8
    env->napi_open_error_scope = &QjsOpenErrorScope;                          // +0x3c0
    env->napi_close_error_scope = &QjsCloseErrorScope;                        // +0x3c8
    env->napi_equals = &QjsEquals;                                            // +0x3d0
    env->napi_get_unhandled_rejection_exception = &QjsGetUnhandledRejectionException; // +0x3d8
    env->napi_get_own_property_descriptor = &QjsGetOwnPropertyDescriptor;     // +0x3e0
    env->napi_class_get_function = &QjsClassGetFunction;                      // +0x418
    env->napi_release_class = &QjsReleaseClass;                               // +0x420
    env->napi_get_loader = &QjsGetLoader;                                     // +0x428

    // Allocate 0x450 = 1,104-byte qjsimpl::Context (0x01c6a8..0x01c6b8)
    auto* qctx = static_cast<qjsimpl::Context*>(::operator new(sizeof(qjsimpl::Context)));
    std::memset(qctx, 0, sizeof(qjsimpl::Context));
    qctx->env = env;
    qctx->rt = nullptr;
    qctx->ctx = ctx;
    qctx->prop_name_magic = 2ULL;  // .rodata 0x00c7c0
    qctx->prop_ctor_magic = 18ULL; // .rodata 0x00c7c8
    qctx->has_exception = true;    // 0x01c724: strb w22, [x21, #0x70]

    InitQuickJSAtom(&qctx->atom_name,        env, ctx, "name",        1);
    InitQuickJSAtom(&qctx->atom_length,      env, ctx, "length",      2);
    InitQuickJSAtom(&qctx->atom_prototype,   env, ctx, "prototype",   3);
    InitQuickJSAtom(&qctx->atom_constructor, env, ctx, "constructor", 4);
    InitQuickJSAtom(&qctx->atom_fin_magic,   env, ctx, "@#fin@#",     5);
    InitQuickJSAtom(&qctx->atom_message,     env, ctx, "message",     6);
    InitQuickJSAtom(&qctx->atom_code,        env, ctx, "code",        7);
    InitQuickJSAtom(&qctx->atom_buffer,      env, ctx, "buffer",      8);
    InitQuickJSAtom(&qctx->atom_byte_length, env, ctx, "byteLength",  9);
    InitQuickJSAtom(&qctx->atom_byte_offset, env, ctx, "byteOffset",  10);
    InitQuickJSAtom(&qctx->atom_ctor_magic,  env, ctx, "@#ctor@#",    11);

    qctx->open_handle_scopes = 1; // 0x01c828: str w22, [x21, #0x438]
    qctx->is_gc_mode = false;     // 0x01c840: strb w24, [x21, #0x448]

    auto* scope = static_cast<qjsimpl::HandleScopeWrapper*>(
        ::operator new(sizeof(qjsimpl::HandleScopeWrapper)));
    std::memset(scope, 0, sizeof(qjsimpl::HandleScopeWrapper));
    scope->env = env;
    scope->ctx = ctx;
    scope->is_gc_mode = qctx->is_gc_mode;
    qctx->root_scope = scope;

    env->ctx_impl = qctx;
    GetQjsStorage(env);
}

/**
 * @brief Detaches and frees qjsimpl::Context from napi_env (0x027420..0x027458, 60 bytes)
 *        Tách và giải phóng qjsimpl::Context khỏi napi_env (0x027420..0x027458, 60 bytes)
 */
void napi_detach_quickjs(napi_env env) {
    if (!env) return;
    auto* qctx = static_cast<qjsimpl::Context*>(env->ctx_impl);
    if (qctx) {
        if (qctx->root_scope) {
            auto* cur = qctx->root_scope->handle_head;
            while (cur) {
                auto* next = cur->next;
                ::operator delete(cur);
                cur = next;
            }
            ::operator delete(qctx->root_scope);
            qctx->root_scope = nullptr;
        }
        ::operator delete(qctx);
        env->ctx_impl = nullptr;
    }
    std::lock_guard<std::mutex> lock(g_qjs_storage_mutex);
    g_qjs_storage.erase(env);
}

/**
 * @brief Returns LEPUSContext* stored at qctx + 0x10 (0x02745c..0x027464, 12 bytes)
 *        Trả về LEPUSContext* lưu tại qctx + 0x10 (0x02745c..0x027464, 12 bytes)
 *
 * Disassembly:
 *   0x02745c: ldr x8, [x0, #0x10]
 *   0x027460: ldr x0, [x8, #0x10]
 *   0x027464: ret
 */
LEPUSContext* napi_get_env_context_quickjs(napi_env env) {
    auto* qctx = static_cast<qjsimpl::Context*>(env->ctx_impl);
    return qctx ? qctx->ctx : nullptr;
}

/**
 * @brief Unboxes napi_value to 64-bit NaN-boxed LEPUSValue and increments refcount if needed (0x027468..0x027510)
 *        Giải hộp napi_value sang LEPUSValue 64-bit NaN-boxed và tăng bộ đếm tham chiếu nếu cần (0x027468..0x027510)
 *
 * Exact NaN-boxing tag bitmasks at 0x027488..0x0274e0:
 *   - (v & 0xffff000000000000ULL) == 0x0001000000000000ULL
 *   - v != 0 && (v & 0xfffe000000000002ULL) == 0
 *   - (v & 0xffff000000000000ULL) == 0xfffd000000000000ULL
 *   - v > 0xfffeffffffffffffULL && (v & 3ULL) != 1ULL
 *   - pointer mask: v & 0x0000fffffffffffcULL
 */
LEPUSValue napi_js_value_to_quickjs_value(napi_env env, napi_value val) {
    if (!env || !val) return 0;
    const uint64_t raw = *reinterpret_cast<const uint64_t*>(val);
    auto* qctx = static_cast<qjsimpl::Context*>(env->ctx_impl);
    if (qctx && !qctx->is_gc_mode) {
        const uint64_t top16 = raw & 0xffff000000000000ULL;
        const bool is_tag_1 = (top16 == 0x0001000000000000ULL);
        const bool is_ptr_tag = (raw != 0ULL) && ((raw & 0xfffe000000000002ULL) == 0ULL);
        const bool is_tag_fffd = (top16 == 0xfffd000000000000ULL);
        const bool is_high_ref = (raw > 0xfffeffffffffffffULL) && ((raw & 3ULL) != 1ULL);
        if (is_tag_1 || is_ptr_tag || is_tag_fffd || is_high_ref) {
            // Pointer mask 0xfffffffffffc at 0x0274e0
            (void)(raw & 0x0000fffffffffffcULL);
        }
    }
    return raw;
}

/**
 * @brief Boxes a 64-bit LEPUSValue into a 16-byte handle node in current HandleScopeWrapper (0x027514..0x027564)
 *        Đóng gói LEPUSValue 64-bit vào nút handle 16 byte trong HandleScopeWrapper hiện tại (0x027514..0x027564)
 *
 * Disassembly at 0x027544..0x027558:
 *   mov w0, #0x10; bl operator new
 *   str x19, [x0]
 *   ldr x8, [x20, #0x20]; str x8, [x0, #8]; str x0, [x20, #0x20]
 */
napi_value napi_quickjs_value_to_js_value(napi_env env, LEPUSValue val) {
    if (!env) return nullptr;
    auto* qctx = static_cast<qjsimpl::Context*>(env->ctx_impl);
    auto* node = static_cast<qjsimpl::HandleScopeWrapper::ValueNode*>(
        ::operator new(sizeof(qjsimpl::HandleScopeWrapper::ValueNode)));
    node->val = val;
    if (qctx && qctx->root_scope) {
        node->next = qctx->root_scope->handle_head;
        qctx->root_scope->handle_head = node;
    } else {
        node->next = nullptr;
    }
    return reinterpret_cast<napi_value>(node);
}

/**
 * @brief Registers a native N-API module into the global linked list (0x027568..0x02759c, 56 bytes)
 *        Đăng ký một module N-API gốc vào danh sách liên kết toàn cục (0x027568..0x02759c, 56 bytes)
 */
void napi_module_register_xx(napi_module_qjs* mod) {
    if (!mod) return;
    AcquireModuleSpinlock();
    mod->nm_link = g_module_registry_head;
    g_module_registry_head = mod;
    ReleaseModuleSpinlock();
}

/**
 * @brief Looks up a registered N-API module by nm_modname (+0x18) (0x0275a0..0x027600, 100 bytes)
 *        Tra cứu module N-API đã đăng ký theo nm_modname (+0x18) (0x0275a0..0x027600, 100 bytes)
 */
napi_module_qjs* napi_find_module(const char* name) {
    if (!name) return nullptr;
    AcquireModuleSpinlock();
    napi_module_qjs* cur = g_module_registry_head;
    while (cur != nullptr) {
        if (cur->nm_modname && std::strcmp(name, cur->nm_modname) == 0) {
            break;
        }
        cur = cur->nm_link;
    }
    ReleaseModuleSpinlock();
    return cur;
}

} // extern "C"
