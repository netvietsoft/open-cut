/**
 * @file napi_cpp_wrapper.cpp
 * @brief Clean-Room C++17 Implementation of Napi::* Object Model (0x027604..0x02db6c)
 *        Hiện thực C++17 sạch cho mô hình đối tượng Napi::* (0x027604..0x02db6c)
 */

#include "napi_cpp_wrapper.h"
#include "napi_env_runtime.h"
#include <cstdlib>
#include <cstring>

namespace Napi {

using primjs::napi::runtime::CheckNapiStatus;

// ============================================================================
// 1. Napi::NAPI Static Methods (0x027604..0x027b73)
//    Các phương thức tĩnh Napi::NAPI (0x027604..0x027b73)
// ============================================================================

void NAPI::ToValueEmpty() {
    // 0x027604: str x30, [sp, #-0x10]!; bl #0x19ce4 (abort)
    std::abort();
}

void NAPI::FromJustIsNothing() {
    // Aliased to 0x027604 in .dynsym
    std::abort();
}

napi_ref NAPI::CreateReference(napi_env env, napi_value value, uint32_t initial_refcount) {
    napi_ref ref = nullptr;
    napi_status st = env->napi_create_reference(env, value, initial_refcount, &ref);
    CheckNapiStatus(env, st, "failed to call napi_create_reference");
    return ref;
}

void NAPI::DeleteReference(napi_env env, napi_ref ref) {
    napi_status st = env->napi_delete_reference(env, ref);
    CheckNapiStatus(env, st, "failed to call napi_delete_reference");
}

napi_value NAPI::GetReferenceValue(napi_env env, napi_ref ref) {
    napi_value val = nullptr;
    napi_status st = env->napi_get_reference_value(env, ref, &val);
    CheckNapiStatus(env, st, "failed to call napi_get_reference_value");
    return val;
}

uint32_t NAPI::ReferenceRef(napi_env env, napi_ref ref) {
    uint32_t result = 0;
    napi_status st = env->napi_reference_ref(env, ref, &result);
    CheckNapiStatus(env, st, "failed to call napi_reference_ref");
    return result;
}

uint32_t NAPI::ReferenceUnRef(napi_env env, napi_ref ref) {
    uint32_t result = 0;
    napi_status st = env->napi_reference_unref(env, ref, &result);
    CheckNapiStatus(env, st, "failed to call napi_reference_unref");
    return result;
}

void* NAPI::Unwrap(napi_env env, napi_value js_object) {
    void* result = nullptr;
    napi_status st = env->napi_unwrap(env, js_object, &result);
    CheckNapiStatus(env, st, "failed to call napi_unwrap");
    return result;
}

napi_ref NAPI::Wrap(
    napi_env env,
    napi_value js_object,
    void* native_object,
    napi_finalize finalize_cb,
    void* finalize_hint) {
    napi_ref ref = nullptr;
    napi_status st = env->napi_wrap(env, js_object, native_object, finalize_cb, finalize_hint, &ref);
    CheckNapiStatus(env, st, "failed to call napi_wrap");
    return ref;
}

void NAPI::DefineClass(
    napi_env env,
    const char* utf8name,
    napi_callback ctor,
    size_t property_count,
    const napi_property_descriptor* descriptors,
    void* data,
    napi_class* result) {
    napi_status st = env->napi_define_class(
        env, utf8name, static_cast<size_t>(-1), ctor, data, property_count, descriptors, result);
    CheckNapiStatus(env, st, "failed to call napi_define_class");
}

// ============================================================================
// 2. Napi::Env Methods (0x027b74..0x02811f)
//    Các phương thức Napi::Env (0x027b74..0x02811f)
// ============================================================================

Object Env::Global() const {
    napi_value val = nullptr;
    napi_status st = _env->napi_get_global(_env, &val);
    CheckNapiStatus(_env, st, "failed to call napi_get_global");
    return Object(_env, val);
}

Value Env::Undefined() const {
    napi_value val = nullptr;
    napi_status st = _env->napi_get_undefined(_env, &val);
    CheckNapiStatus(_env, st, "failed to call napi_get_undefined");
    return Value(_env, val);
}

Value Env::Null() const {
    napi_value val = nullptr;
    napi_status st = _env->napi_get_null(_env, &val);
    CheckNapiStatus(_env, st, "failed to call napi_get_null");
    return Value(_env, val);
}

Value Env::Loader() const {
    napi_value val = nullptr;
    napi_status st = _env->napi_get_loader(_env, &val);
    CheckNapiStatus(_env, st, "failed to call napi_get_loader");
    return Value(_env, val);
}

bool Env::IsExceptionPending() const {
    bool res = false;
    _env->napi_is_exception_pending(_env, &res);
    return res;
}

Value Env::GetAndClearPendingException() {
    napi_value val = nullptr;
    _env->napi_get_and_clear_last_exception(_env, &val);
    return Value(_env, val);
}

Value Env::GetUnhandledRecjectionException() {
    napi_value val = nullptr;
    _env->napi_get_unhandled_rejection_exception(_env, &val);
    return Value(_env, val);
}

void Env::InitCodeCache(int32_t capacity, const std::string& path, std::function<void(bool)> cb) {
    if (_env && _env->napi_init_code_cache) {
        _env->napi_init_code_cache(_env, capacity, path, std::move(cb));
    }
}

void Env::OutputCodeCache() {
    if (_env && _env->napi_output_code_cache) {
        _env->napi_output_code_cache(_env);
    }
}

Value Env::RunScriptCache(const char* script, size_t length, const char* filename) {
    napi_value val = nullptr;
    if (_env && _env->napi_run_script_cache) {
        _env->napi_run_script_cache(_env, script, length, filename, &val);
    }
    return Value(_env, val);
}

Value Env::RunScript(const char* script, size_t length, const char* filename) {
    napi_value val = nullptr;
    if (_env && _env->napi_run_script) {
        _env->napi_run_script(_env, script, length, filename, &val);
    }
    return Value(_env, val);
}

void* Env::GetInstanceData(uint64_t key) {
    void* data = nullptr;
    napi_status st = _env->napi_get_instance_data(_env, key, &data);
    CheckNapiStatus(_env, st, "failed to call napi_get_instance_data");
    return data;
}

void Env::SetInstanceData(uint64_t key, void* data, napi_finalize finalize_cb, void* hint) {
    napi_status st = _env->napi_set_instance_data(_env, key, data, finalize_cb, hint);
    CheckNapiStatus(_env, st, "failed to call napi_set_instance_data");
}

void Env::AddCleanupHook(void (*fn)(void*), void* arg) {
    napi_status st = _env->napi_add_env_cleanup_hook(_env, fn, arg);
    CheckNapiStatus(_env, st, "failed to call napi_add_env_cleanup_hook");
}

void Env::RemoveCleanupHook(void (*fn)(void*), void* arg) {
    napi_status st = _env->napi_remove_env_cleanup_hook(_env, fn, arg);
    CheckNapiStatus(_env, st, "failed to call napi_remove_env_cleanup_hook");
}

void Env::DumpCacheStatus(std::vector<std::pair<std::string, int>>* /*out*/) {
    // 0x01b26c: ret (4-byte no-op in libnapi.so)
}

// ============================================================================
// 3. Napi::Value Methods (0x028120..0x028fdb)
//    Các phương thức Napi::Value (0x028120..0x028fdb)
// ============================================================================

bool Value::StrictEquals(const Value& other) const {
    bool res = false;
    napi_status st = _env->napi_strict_equals(_env, _value, other._value, &res);
    CheckNapiStatus(_env, st, "failed to call napi_strict_equals");
    return res;
}

bool Value::Equals(const Value& other) const {
    bool res = false;
    _env->napi_equals(_env, _value, other._value, &res);
    return res;
}

napi_valuetype Value::Type() const {
    if (IsEmpty()) return napi_undefined;
    napi_valuetype t = napi_undefined;
    napi_status st = _env->napi_typeof(_env, _value, &t);
    CheckNapiStatus(_env, st, "failed to call napi_typeof");
    return t;
}

bool Value::IsUndefined() const { return Type() == napi_undefined; }
bool Value::IsNull() const      { return Type() == napi_null; }
bool Value::IsBoolean() const   { return Type() == napi_boolean; }
bool Value::IsNumber() const    { return Type() == napi_number; }
bool Value::IsString() const    { return Type() == napi_string; }
bool Value::IsSymbol() const    { return Type() == napi_symbol; }
bool Value::IsFunction() const  { return Type() == napi_function; }
bool Value::IsExternal() const  { return Type() == napi_external; }

bool Value::IsObject() const {
    napi_valuetype t = Type();
    return t == napi_object || t == napi_function;
}

bool Value::IsArray() const {
    if (IsEmpty()) return false;
    bool res = false;
    napi_status st = _env->napi_is_array(_env, _value, &res);
    CheckNapiStatus(_env, st, "failed to call napi_is_array");
    return res;
}

bool Value::IsArrayBuffer() const {
    if (IsEmpty()) return false;
    bool res = false;
    napi_status st = _env->napi_is_arraybuffer(_env, _value, &res);
    CheckNapiStatus(_env, st, "failed to call napi_is_arraybuffer");
    return res;
}

bool Value::IsTypedArray() const {
    if (IsEmpty()) return false;
    bool res = false;
    napi_status st = _env->napi_is_typedarray(_env, _value, &res);
    CheckNapiStatus(_env, st, "failed to call napi_is_typedarray");
    return res;
}

namespace {
bool CheckIsTypedArrayOf(napi_env env, napi_value val, napi_typedarray_type type) {
    if (!val) return false;
    bool res = false;
    napi_status st = env->napi_is_typedarray_of(env, val, type, &res);
    CheckNapiStatus(env, st, "failed to call napi_is_typedarray_of");
    return res;
}
} // namespace

bool Value::IsInt8Array() const         { return CheckIsTypedArrayOf(_env, _value, napi_int8_array); }
bool Value::IsUint8Array() const        { return CheckIsTypedArrayOf(_env, _value, napi_uint8_array); }
bool Value::IsUint8ClampedArray() const { return CheckIsTypedArrayOf(_env, _value, napi_uint8_clamped_array); }
bool Value::IsInt16Array() const        { return CheckIsTypedArrayOf(_env, _value, napi_int16_array); }
bool Value::IsUint16Array() const       { return CheckIsTypedArrayOf(_env, _value, napi_uint16_array); }
bool Value::IsInt32Array() const        { return CheckIsTypedArrayOf(_env, _value, napi_int32_array); }
bool Value::IsUint32Array() const       { return CheckIsTypedArrayOf(_env, _value, napi_uint32_array); }
bool Value::IsFloat32Array() const      { return CheckIsTypedArrayOf(_env, _value, napi_float32_array); }
bool Value::IsFloat64Array() const      { return CheckIsTypedArrayOf(_env, _value, napi_float64_array); }

bool Value::IsPromise() const {
    if (IsEmpty()) return false;
    bool res = false;
    napi_status st = _env->napi_is_promise(_env, _value, &res);
    CheckNapiStatus(_env, st, "failed to call napi_is_promise");
    return res;
}

bool Value::IsDataView() const {
    if (IsEmpty()) return false;
    bool res = false;
    napi_status st = _env->napi_is_dataview(_env, _value, &res);
    CheckNapiStatus(_env, st, "failed to call napi_is_dataview");
    return res;
}

Boolean Value::ToBoolean() const {
    napi_value val = nullptr;
    napi_status st = _env->napi_coerce_to_bool(_env, _value, &val);
    CheckNapiStatus(_env, st, "failed to call napi_coerce_to_bool");
    return Boolean(_env, val);
}

Number Value::ToNumber() const {
    napi_value val = nullptr;
    _env->napi_coerce_to_number(_env, _value, &val);
    return Number(_env, val);
}

String Value::ToString() const {
    napi_value val = nullptr;
    _env->napi_coerce_to_string(_env, _value, &val);
    return String(_env, val);
}

Object Value::ToObject() const {
    napi_value val = nullptr;
    _env->napi_coerce_to_object(_env, _value, &val);
    return Object(_env, val);
}

// ============================================================================
// 4. Boolean, Number, String, Symbol (0x028fdc..0x02a003)
// ============================================================================

Boolean Boolean::New(napi_env env, bool val) {
    napi_value v = nullptr;
    napi_status st = env->napi_get_boolean(env, val, &v);
    CheckNapiStatus(env, st, "failed to call napi_get_boolean");
    return Boolean(env, v);
}

bool Boolean::Value() const {
    bool b = false;
    napi_status st = _env->napi_get_value_bool(_env, _value, &b);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_bool");
    return b;
}

Number Number::New(napi_env env, double val) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_double(env, val, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_double");
    return Number(env, v);
}

int32_t Number::Int32Value() const {
    int32_t r = 0;
    napi_status st = _env->napi_get_value_int32(_env, _value, &r);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_int32");
    return r;
}

uint32_t Number::Uint32Value() const {
    uint32_t r = 0;
    napi_status st = _env->napi_get_value_uint32(_env, _value, &r);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_uint32");
    return r;
}

int64_t Number::Int64Value() const {
    int64_t r = 0;
    napi_status st = _env->napi_get_value_int64(_env, _value, &r);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_int64");
    return r;
}

float Number::FloatValue() const {
    return static_cast<float>(DoubleValue());
}

double Number::DoubleValue() const {
    double r = 0.0;
    napi_status st = _env->napi_get_value_double(_env, _value, &r);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_double");
    return r;
}

String String::New(napi_env env, const char* val) {
    return New(env, val, val ? std::strlen(val) : 0);
}

String String::New(napi_env env, const char16_t* val) {
    size_t len = 0;
    while (val && val[len] != 0) ++len;
    return New(env, val, len);
}

String String::New(napi_env env, const char* val, size_t length) {
    napi_value v = nullptr;
    _env_Unused:
    (void)sizeof(_env_Unused);
    env->napi_create_string_utf8(env, val, length, &v);
    return String(env, v);
}

String String::New(napi_env env, const char16_t* val, size_t length) {
    napi_value v = nullptr;
    env->napi_create_string_utf16(env, val, length, &v);
    return String(env, v);
}

std::string String::Utf8Value() const {
    size_t length = 0;
    napi_status st = _env->napi_get_value_string_utf8(_env, _value, nullptr, 0, &length);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_string_utf8");
    std::string out(length + 1, '\0');
    st = _env->napi_get_value_string_utf8(_env, _value, &out[0], out.size(), &length);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_string_utf8");
    out.resize(length);
    return out;
}

std::u16string String::Utf16Value() const {
    size_t length = 0;
    napi_status st = _env->napi_get_value_string_utf16(_env, _value, nullptr, 0, &length);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_string_utf16");
    std::u16string out(length + 1, u'\0');
    st = _env->napi_get_value_string_utf16(_env, _value, &out[0], out.size(), &length);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_string_utf16");
    out.resize(length);
    return out;
}

Symbol Symbol::New(napi_env env, const char* description) {
    napi_value desc = nullptr;
    if (description) {
        env->napi_create_string_utf8(env, description, std::strlen(description), &desc);
    }
    return New(env, desc);
}

Symbol Symbol::New(napi_env env, napi_value description) {
    napi_value sym = nullptr;
    napi_status st = env->napi_create_symbol(env, description, &sym);
    CheckNapiStatus(env, st, "failed to call napi_create_symbol");
    return Symbol(env, sym);
}

Symbol Symbol::New(napi_env env, String description) {
    return New(env, static_cast<napi_value>(description));
}

Symbol Symbol::WellKnown(napi_env env, const char* name) {
    return Env(env).Global().Get("Symbol").ToObject().Get(name).operator napi_value()
        ? Symbol(env, Env(env).Global().Get("Symbol").ToObject().Get(name))
        : New(env, name);
}

// ============================================================================
// 5. Object, Array, ArrayBuffer, DataView, TypedArray (0x02a004..0x02c657)
// ============================================================================

Object Object::New(napi_env env) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_object(env, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_object");
    return Object(env, v);
}

Value Object::GetOwnPropertyDescriptor(napi_env env, Value obj, Value prop) {
    napi_value v = nullptr;
    napi_status st = env->napi_get_own_property_descriptor(env, obj._value, prop._value, &v);
    CheckNapiStatus(env, st, "failed to call napi_get_own_property_descriptor");
    return Value(env, v);
}

Value Object::Get(const char* utf8name) const {
    napi_value v = nullptr;
    _env->napi_get_named_property(_env, _value, utf8name, &v);
    return Value(_env, v);
}

Value Object::Get(napi_value key) const {
    napi_value v = nullptr;
    _env->napi_get_property(_env, _value, key, &v);
    return Value(_env, v);
}

Value Object::Get(uint32_t index) const {
    napi_value v = nullptr;
    _env->napi_get_element(_env, _value, index, &v);
    return Value(_env, v);
}

bool Object::Has(napi_value key) const {
    bool r = false;
    _env->napi_has_property(_env, _value, key, &r);
    return r;
}

bool Object::Has(const char* utf8name) const {
    bool r = false;
    _env->napi_has_named_property(_env, _value, utf8name, &r);
    return r;
}

bool Object::Has(uint32_t index) const {
    bool r = false;
    _env->napi_has_element(_env, _value, index, &r);
    return r;
}

bool Object::HasOwnProperty(napi_value key) const {
    bool r = false;
    _env->napi_has_own_property(_env, _value, key, &r);
    return r;
}

bool Object::HasOwnProperty(const char* utf8name) const {
    napi_value k = nullptr;
    _env->napi_create_string_utf8(_env, utf8name, std::strlen(utf8name), &k);
    return HasOwnProperty(k);
}

void Object::Set(const char* utf8name, napi_value value) {
    _env->napi_set_named_property(_env, _value, utf8name, value);
}

void Object::Set(napi_value key, napi_value value) {
    _env->napi_set_property(_env, _value, key, value);
}

void Object::Set(uint32_t index, napi_value value) {
    _env->napi_set_element(_env, _value, index, value);
}

bool Object::Delete(napi_value key) {
    bool r = false;
    _env->napi_delete_property(_env, _value, key, &r);
    return r;
}

bool Object::Delete(const char* utf8name) {
    napi_value k = nullptr;
    _env->napi_create_string_utf8(_env, utf8name, std::strlen(utf8name), &k);
    return Delete(k);
}

bool Object::Delete(uint32_t index) {
    bool r = false;
    _env->napi_delete_element(_env, _value, index, &r);
    return r;
}

Array Object::GetPropertyNames() const {
    napi_value v = nullptr;
    _env->napi_get_property_names(_env, _value, &v);
    return Array(_env, v);
}

void Object::DefineProperty(const PropertyDescriptor& property) {
    _env->napi_define_properties(_env, _value, 1, &property._desc);
}

void Object::DefineProperties(const std::initializer_list<PropertyDescriptor>& properties) {
    _env->napi_define_properties(
        _env,
        _value,
        properties.size(),
        reinterpret_cast<const napi_property_descriptor*>(properties.begin()));
}

void Object::DefineProperties(const std::vector<PropertyDescriptor>& properties) {
    _env->napi_define_properties(
        _env,
        _value,
        properties.size(),
        reinterpret_cast<const napi_property_descriptor*>(properties.data()));
}

bool Object::InstanceOf(const Function& constructor) const {
    bool r = false;
    _env->napi_instanceof(_env, _value, constructor._value, &r);
    return r;
}

void Object::AddFinalizer(void* native_object, napi_finalize finalize_cb, void* hint) {
    napi_status st = _env->napi_AddFinalizer(_env, _value, native_object, finalize_cb, hint, nullptr);
    CheckNapiStatus(_env, st, "failed to call napi_add_finalizer");
}

Array Array::New(napi_env env) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_array(env, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_array");
    return Array(env, v);
}

Array Array::New(napi_env env, size_t length) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_array_with_length(env, length, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_array_with_length");
    return Array(env, v);
}

uint32_t Array::Length() const {
    uint32_t len = 0;
    napi_status st = _env->napi_get_array_length(_env, _value, &len);
    CheckNapiStatus(_env, st, "failed to call napi_get_array_length");
    return len;
}

ArrayBuffer ArrayBuffer::New(napi_env env, size_t byteLength) {
    napi_value v = nullptr;
    void* data = nullptr;
    napi_status st = env->napi_create_arraybuffer(env, byteLength, &data, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_arraybuffer");
    ArrayBuffer ab(env, v);
    ab._data = data;
    ab._length = byteLength;
    return ab;
}

ArrayBuffer ArrayBuffer::New(napi_env env, void* externalData, size_t byteLength) {
    return New(env, externalData, byteLength, nullptr, nullptr);
}

ArrayBuffer ArrayBuffer::New(
    napi_env env,
    void* externalData,
    size_t byteLength,
    napi_finalize finalizeCallback,
    void* finalizeHint) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_external_arraybuffer(
        env, externalData, byteLength, finalizeCallback, finalizeHint, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_external_arraybuffer");
    ArrayBuffer ab(env, v);
    ab._data = externalData;
    ab._length = byteLength;
    return ab;
}

void* ArrayBuffer::Data() {
    if (!_data && _value) {
        napi_status st = _env->napi_get_arraybuffer_info(_env, _value, &_data, &_length);
        CheckNapiStatus(_env, st, "failed to call napi_get_arraybuffer_info");
    }
    return _data;
}

size_t ArrayBuffer::ByteLength() {
    if (!_data && _value) {
        napi_status st = _env->napi_get_arraybuffer_info(_env, _value, &_data, &_length);
        CheckNapiStatus(_env, st, "failed to call napi_get_arraybuffer_info");
    }
    return _length;
}

DataView::DataView(napi_env env, napi_value val) : Object(env, val) {
    napi_status st = _env->napi_get_dataview_info(_env, _value, &_length, &_data, nullptr, nullptr);
    CheckNapiStatus(_env, st, "failed to call napi_get_dataview_info");
}

DataView DataView::New(napi_env env, Napi::ArrayBuffer arrayBuffer) {
    return New(env, arrayBuffer, 0, arrayBuffer.ByteLength());
}

DataView DataView::New(napi_env env, Napi::ArrayBuffer arrayBuffer, size_t byteOffset) {
    return New(env, arrayBuffer, byteOffset, arrayBuffer.ByteLength() - byteOffset);
}

DataView DataView::New(
    napi_env env,
    Napi::ArrayBuffer arrayBuffer,
    size_t byteOffset,
    size_t byteLength) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_dataview(env, byteLength, arrayBuffer._value, byteOffset, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_dataview");
    return DataView(env, v);
}

Napi::ArrayBuffer DataView::ArrayBuffer() const {
    napi_value buf = nullptr;
    napi_status st = _env->napi_get_dataview_info(_env, _value, nullptr, nullptr, &buf, nullptr);
    CheckNapiStatus(_env, st, "failed to call napi_get_dataview_info");
    return Napi::ArrayBuffer(_env, buf);
}

size_t DataView::ByteOffset() const {
    size_t offset = 0;
    napi_status st = _env->napi_get_dataview_info(_env, _value, nullptr, nullptr, nullptr, &offset);
    CheckNapiStatus(_env, st, "failed to call napi_get_dataview_info");
    return offset;
}

napi_typedarray_type TypedArray::TypedArrayType() const {
    if (_type == static_cast<napi_typedarray_type>(-1)) {
        auto* self = const_cast<TypedArray*>(this);
        napi_status st = _env->napi_get_typedarray_info(
            _env, _value, &self->_type, &self->_length, nullptr, nullptr, nullptr);
        CheckNapiStatus(_env, st, "failed to call napi_get_typedarray_info");
    }
    return _type;
}

/**
 * @brief Returns TypedArray element size in bytes (0x02afd0..0x02b07c, 172 bytes)
 *        Trả về kích thước phần tử TypedArray tính bằng byte (0x02afd0..0x02b07c, 172 bytes)
 *
 * Exact jump table displacement at .rodata 0x00c81b:
 *   [10, 10, 10, 6, 6, 0, 0, 0, 3, 3, 3]
 *   - disp 10 -> 1 byte  (types 0..2: Int8, Uint8, Uint8Clamped)
 *   - disp  6 -> 2 bytes (types 3..4: Int16, Uint16)
 *   - disp  0 -> 4 bytes (types 5..7: Int32, Uint32, Float32)
 *   - disp  3 -> 8 bytes (types 8..10: Float64, BigInt64, BigUint64)
 */
uint8_t TypedArray::ElementSize() const {
    static constexpr uint8_t kDisplacementTable[11] = {10, 10, 10, 6, 6, 0, 0, 0, 3, 3, 3};
    napi_typedarray_type t = TypedArrayType();
    if (static_cast<uint32_t>(t) > 10U) {
        return 0;
    }
    switch (kDisplacementTable[static_cast<uint32_t>(t)]) {
        case 0:  return 4;
        case 3:  return 8;
        case 6:  return 2;
        case 10: return 1;
        default: return 0;
    }
}

size_t TypedArray::ElementLength() const {
    if (_type == static_cast<napi_typedarray_type>(-1)) {
        (void)TypedArrayType();
    }
    return _length;
}

size_t TypedArray::ByteOffset() const {
    size_t offset = 0;
    napi_status st = _env->napi_get_typedarray_info(
        _env, _value, nullptr, nullptr, nullptr, nullptr, &offset);
    CheckNapiStatus(_env, st, "failed to call napi_get_typedarray_info");
    return offset;
}

size_t TypedArray::ByteLength() const {
    return ElementLength() * static_cast<size_t>(ElementSize());
}

Napi::ArrayBuffer TypedArray::ArrayBuffer() const {
    napi_value buf = nullptr;
    napi_status st = _env->napi_get_typedarray_info(
        _env, _value, nullptr, nullptr, nullptr, &buf, nullptr);
    CheckNapiStatus(_env, st, "failed to call napi_get_typedarray_info");
    return Napi::ArrayBuffer(_env, buf);
}

#define IMPLEMENT_NAPI_TYPED_ARRAY(ClassName, EnumType, ElemSize)                        \
    ClassName::ClassName(napi_env env, napi_value val)                                   \
        : TypedArray(env, val, EnumType, 0) {                                            \
        napi_status st = _env->napi_get_typedarray_info(                                 \
            _env, _value, &_type, &_length, nullptr, nullptr, nullptr);                  \
        CheckNapiStatus(_env, st, "failed to call napi_get_typedarray_info");            \
    }                                                                                    \
    ClassName ClassName::New(napi_env env, size_t elementLength) {                       \
        Napi::ArrayBuffer ab = Napi::ArrayBuffer::New(env, elementLength * (ElemSize));  \
        return New(env, elementLength, ab, 0);                                           \
    }                                                                                    \
    ClassName ClassName::New(                                                            \
        napi_env env,                                                                    \
        size_t elementLength,                                                            \
        Napi::ArrayBuffer arrayBuffer,                                                   \
        size_t bufferOffset) {                                                           \
        napi_value v = nullptr;                                                          \
        napi_status st = env->napi_create_typedarray(                                    \
            env, EnumType, elementLength, arrayBuffer._value, bufferOffset, &v);         \
        CheckNapiStatus(env, st, "failed to call napi_create_typedarray");               \
        return ClassName(env, v);                                                        \
    }

IMPLEMENT_NAPI_TYPED_ARRAY(Int8Array,         napi_int8_array,          1)
IMPLEMENT_NAPI_TYPED_ARRAY(Int16Array,        napi_int16_array,         2)
IMPLEMENT_NAPI_TYPED_ARRAY(Int32Array,        napi_int32_array,         4)
IMPLEMENT_NAPI_TYPED_ARRAY(Uint8ClampedArray, napi_uint8_clamped_array, 1)
IMPLEMENT_NAPI_TYPED_ARRAY(Uint8Array,        napi_uint8_array,         1)
IMPLEMENT_NAPI_TYPED_ARRAY(Uint16Array,       napi_uint16_array,        2)
IMPLEMENT_NAPI_TYPED_ARRAY(Uint32Array,       napi_uint32_array,        4)
IMPLEMENT_NAPI_TYPED_ARRAY(Float32Array,      napi_float32_array,       4)
IMPLEMENT_NAPI_TYPED_ARRAY(Float64Array,      napi_float64_array,       8)

#undef IMPLEMENT_NAPI_TYPED_ARRAY

// ============================================================================
// 6. Function, CallbackInfo, Promise, External, Errors, Scopes, AsyncWorker
// ============================================================================

namespace {
struct FunctionCallbackHolder {
    Function::Callback cb;
    void* user_data;
};

napi_value FunctionTrampoline(napi_env env, napi_callback_info info) {
    void* raw_data = nullptr;
    env->napi_get_cb_info(env, info, nullptr, nullptr, nullptr, &raw_data);
    auto* holder = static_cast<FunctionCallbackHolder*>(raw_data);
    if (!holder || !holder->cb) return nullptr;
    CallbackInfo cb_info(env, info);
    cb_info._data = holder->user_data;
    Value ret = holder->cb(cb_info);
    return static_cast<napi_value>(ret);
}
} // namespace

Function Function::New(napi_env env, Callback cb, const char* utf8name, void* data) {
    auto* holder = new FunctionCallbackHolder{cb, data};
    napi_value fn = nullptr;
    napi_status st = env->napi_create_function(
        env,
        utf8name ? utf8name : "",
        utf8name ? std::strlen(utf8name) : 0,
        &FunctionTrampoline,
        holder,
        &fn);
    CheckNapiStatus(env, st, "failed to call napi_create_function");
    return Function(env, fn);
}

Value Function::Call(size_t argc, const napi_value* argv) const {
    return Call(Env(_env).Undefined(), argc, argv);
}

Value Function::Call(napi_value recv, size_t argc, const napi_value* argv) const {
    napi_value result = nullptr;
    _env->napi_call_function(_env, recv, _value, argc, argv, &result);
    return Value(_env, result);
}

Object Function::New(size_t argc, const napi_value* argv) const {
    napi_value result = nullptr;
    _env->napi_new_instance(_env, _value, argc, argv, &result);
    return Object(_env, result);
}

CallbackInfo::CallbackInfo(napi_env env, napi_callback_info info)
    : _env(env), _info(info), _argc(6), _argv(_staticArgv) {
    napi_status st = _env->napi_get_cb_info(_env, info, &_argc, _argv, &_this, &_data);
    CheckNapiStatus(_env, st, "failed to call napi_get_cb_info");
    if (_argc > 6) {
        _argv = new napi_value[_argc];
        st = _env->napi_get_cb_info(_env, info, &_argc, _argv, &_this, &_data);
        CheckNapiStatus(_env, st, "failed to call napi_get_cb_info");
    }
}

CallbackInfo::~CallbackInfo() {
    if (_argv && _argv != _staticArgv) {
        delete[] _argv;
    }
}

Value CallbackInfo::NewTarget() const {
    napi_value target = nullptr;
    napi_status st = _env->napi_get_new_target(_env, _info, &target);
    CheckNapiStatus(_env, st, "failed to call napi_get_new_target");
    return Value(_env, target);
}

bool CallbackInfo::IsConstructCall() const {
    return !NewTarget().IsEmpty();
}

Promise::Deferred Promise::Deferred::New(napi_env env) {
    return Deferred(env);
}

Promise::Deferred::Deferred(napi_env env) : _env(env) {
    _env->napi_create_promise(_env, &_deferred, &_promise);
}

Promise::Deferred::~Deferred() {
    if (_deferred && _env && _env->napi_release_deferred) {
        _env->napi_release_deferred(_env, _deferred, nullptr, 2);
        _deferred = nullptr;
    }
}

void Promise::Deferred::Resolve(napi_value value) {
    if (_deferred && _env) {
        _env->napi_release_deferred(_env, _deferred, value, 0);
        _deferred = nullptr;
    }
}

void Promise::Deferred::Reject(napi_value value) {
    if (_deferred && _env) {
        _env->napi_release_deferred(_env, _deferred, value, 1);
        _deferred = nullptr;
    }
}

External External::New(napi_env env, void* data, napi_finalize finalize_cb, void* hint) {
    napi_value v = nullptr;
    napi_status st = env->napi_create_external(env, data, finalize_cb, hint, &v);
    CheckNapiStatus(env, st, "failed to call napi_create_external");
    return External(env, v);
}

void* External::Data() const {
    void* data = nullptr;
    napi_status st = _env->napi_get_value_external(_env, _value, &data);
    CheckNapiStatus(_env, st, "failed to call napi_get_value_external");
    return data;
}

Error Error::New(napi_env env) {
    napi_value err = nullptr;
    if (env->napi_is_exception_pending) {
        bool pending = false;
        env->napi_is_exception_pending(env, &pending);
        if (pending) {
            env->napi_get_and_clear_last_exception(env, &err);
        }
    }
    return Error(env, err);
}

Error Error::New(napi_env env, const char* message) {
    napi_value err = Create(env, message, message ? std::strlen(message) : 0, env->napi_create_error);
    return Error(env, err);
}

napi_value Error::Create(
    napi_env env,
    const char* message,
    size_t length,
    napi_status (*create_fn)(napi_env, napi_value, napi_value, napi_value*)) {
    napi_value str = nullptr;
    env->napi_create_string_utf8(env, message, length, &str);
    napi_value err = nullptr;
    if (create_fn) {
        create_fn(env, nullptr, str, &err);
    }
    return err;
}

void Error::ThrowAsJavaScriptException() const {
    if (_env && _value) {
        _env->napi_throw(_env, _value);
    }
}

TypeError TypeError::New(napi_env env, const char* message) {
    napi_value err = Create(env, message, message ? std::strlen(message) : 0, env->napi_create_type_error);
    TypeError te;
    te._env = env;
    te._value = err;
    return te;
}

RangeError RangeError::New(napi_env env, const char* message) {
    napi_value err = Create(env, message, message ? std::strlen(message) : 0, env->napi_create_range_error);
    RangeError re;
    re._env = env;
    re._value = err;
    return re;
}

PropertyDescriptor PropertyDescriptor::Accessor(
    Napi::Env /*env*/,
    Napi::Object /*object*/,
    const char* utf8name,
    Function::Callback /*getter*/,
    void (*/*setter*/)(const CallbackInfo&, const Value&),
    napi_property_attributes attributes,
    void* data) {
    return PropertyDescriptor(napi_property_descriptor{
        utf8name, nullptr, nullptr, nullptr, nullptr, nullptr, attributes, data
    });
}

PropertyDescriptor PropertyDescriptor::Accessor(
    Napi::Env /*env*/,
    Napi::Object /*object*/,
    Napi::Name name,
    Function::Callback /*getter*/,
    void (*/*setter*/)(const CallbackInfo&, const Value&),
    napi_property_attributes attributes,
    void* data) {
    return PropertyDescriptor(napi_property_descriptor{
        nullptr, name._value, nullptr, nullptr, nullptr, nullptr, attributes, data
    });
}

PropertyDescriptor PropertyDescriptor::Function(
    Napi::Env env,
    Napi::Object /*object*/,
    const char* utf8name,
    Function::Callback cb,
    napi_property_attributes attributes,
    void* data) {
    Napi::Function fn = Napi::Function::New(env, cb, utf8name, data);
    return PropertyDescriptor(napi_property_descriptor{
        utf8name, nullptr, nullptr, nullptr, nullptr, fn._value, attributes, data
    });
}

PropertyDescriptor PropertyDescriptor::Function(
    Napi::Env env,
    Napi::Object /*object*/,
    Napi::Name name,
    Function::Callback cb,
    napi_property_attributes attributes,
    void* data) {
    Napi::Function fn = Napi::Function::New(env, cb, nullptr, data);
    return PropertyDescriptor(napi_property_descriptor{
        nullptr, name._value, nullptr, nullptr, nullptr, fn._value, attributes, data
    });
}

PropertyDescriptor PropertyDescriptor::Value(
    const char* utf8name,
    napi_value value,
    napi_property_attributes attributes) {
    return PropertyDescriptor(napi_property_descriptor{
        utf8name, nullptr, nullptr, nullptr, nullptr, value, attributes, nullptr
    });
}

PropertyDescriptor PropertyDescriptor::Value(
    napi_value name,
    napi_value value,
    napi_property_attributes attributes) {
    return PropertyDescriptor(napi_property_descriptor{
        nullptr, name, nullptr, nullptr, nullptr, value, attributes, nullptr
    });
}

Class::~Class() {
    if (_env && _class && _env->napi_release_class) {
        _env->napi_release_class(_env, _class);
        _class = nullptr;
    }
}

Function Class::Get(napi_env env) {
    napi_value fn = nullptr;
    napi_status st = env->napi_class_get_function(env, _class, &fn);
    CheckNapiStatus(env, st, "failed to call napi_class_get_function");
    return Function(env, fn);
}

ScriptWrappable::ScriptWrappable() = default;

ScriptWrappable::~ScriptWrappable() {
    if (_env && _wrapper) {
        NAPI::DeleteReference(_env, _wrapper);
        _wrapper = nullptr;
    }
}

HandleScope::HandleScope(Napi::Env env) : _env(env._env) {
    napi_status st = _env->napi_open_handle_scope(_env, &_scope);
    CheckNapiStatus(_env, st, "failed to call napi_open_handle_scope");
}

HandleScope::~HandleScope() {
    napi_status st = _env->napi_close_handle_scope(_env, _scope);
    CheckNapiStatus(_env, st, "failed to call napi_close_handle_scope");
}

ContextScope::ContextScope(Napi::Env env) : _env(env._env) {
    napi_status st = _env->napi_open_context_scope(_env, &_scope);
    CheckNapiStatus(_env, st, "failed to call napi_open_context_scope");
}

ContextScope::~ContextScope() {
    napi_status st = _env->napi_close_context_scope(_env, _scope);
    CheckNapiStatus(_env, st, "failed to call napi_close_context_scope");
}

EscapableHandleScope::EscapableHandleScope(Napi::Env env) : _env(env._env) {
    napi_status st = _env->napi_open_escapable_handle_scope(_env, &_scope);
    CheckNapiStatus(_env, st, "failed to call napi_open_escapable_handle_scope");
}

EscapableHandleScope::~EscapableHandleScope() {
    napi_status st = _env->napi_close_escapable_handle_scope(_env, _scope);
    CheckNapiStatus(_env, st, "failed to call napi_close_escapable_handle_scope");
}

Value EscapableHandleScope::Escape(napi_value escapee) {
    napi_value result = nullptr;
    napi_status st = _env->napi_escape_handle(_env, _scope, escapee, &result);
    CheckNapiStatus(_env, st, "failed to call napi_escape_handle");
    return Value(_env, result);
}

ErrorScope::ErrorScope(Napi::Env env) : _env(env._env) {
    napi_status st = _env->napi_open_error_scope(_env, &_scope);
    CheckNapiStatus(_env, st, "failed to call napi_open_error_scope");
}

ErrorScope::~ErrorScope() {
    napi_status st = _env->napi_close_error_scope(_env, _scope);
    CheckNapiStatus(_env, st, "failed to call napi_close_error_scope");
}

AsyncWorker::AsyncWorker(Napi::Env env) : _env(env._env) {
    auto exec_cb = [](napi_env /*e*/, void* data) {
        static_cast<AsyncWorker*>(data)->Execute();
    };
    auto comp_cb = [](napi_env e, napi_status status, void* data) {
        static_cast<AsyncWorker*>(data)->OnWorkComplete(Napi::Env(e), status);
    };
    napi_status st = _env->napi_create_async_work(
        _env, nullptr, nullptr, exec_cb, comp_cb, this, &_work);
    CheckNapiStatus(_env, st, "failed to call napi_create_async_work");
}

AsyncWorker::~AsyncWorker() {
    if (_env && _work && _env->napi_delete_async_work) {
        _env->napi_delete_async_work(_env, _work);
        _work = nullptr;
    }
}

void AsyncWorker::OnWorkComplete(Napi::Env /*env*/, napi_status status) {
    if (status == napi_ok) {
        OnOK();
    } else {
        OnError(Error::New(_env, "AsyncWorker error"));
    }
    Destroy();
}

void AsyncWorker::Queue() {
    napi_status st = _env->napi_queue_async_work(_env, _work);
    CheckNapiStatus(_env, st, "failed to call napi_queue_async_work");
}

void AsyncWorker::Cancel() {
    napi_status st = _env->napi_cancel_async_work(_env, _work);
    CheckNapiStatus(_env, st, "failed to call napi_cancel_async_work");
}

int64_t MemoryManagement::AdjustExternalMemory(Napi::Env env, int64_t change_in_bytes) {
    int64_t result = 0;
    napi_status st = env._env->napi_adjust_external_memory(env._env, change_in_bytes, &result);
    CheckNapiStatus(env._env, st, "failed to call napi_adjust_external_memory");
    return result;
}

} // namespace Napi
