/**
 * @file napi_cpp_wrapper.h
 * @brief Clean-Room C++17 Napi::* Object Model Declarations (0x027604..0x02db6c)
 *        Khai báo mô hình đối tượng C++17 Napi::* (0x027604..0x02db6c)
 *
 * Reconstructs all 217 exported C++ methods in namespace Napi from libnapi.so.
 * Khôi phục toàn bộ 217 phương thức C++ xuất khẩu trong không gian tên Napi từ libnapi.so.
 */

#pragma once

#include "napi_types.h"

namespace Napi {

class Env;
class Value;
class Boolean;
class Number;
class Name;
class String;
class Symbol;
class Object;
class Array;
class ArrayBuffer;
class DataView;
class TypedArray;
class Function;
class CallbackInfo;
class PropertyDescriptor;
class Class;

/**
 * @brief Low-level NAPI static helper class (0x027604..0x027b73)
 *        Lớp trợ giúp tĩnh NAPI mức thấp (0x027604..0x027b73)
 */
class NAPI {
public:
    static void ToValueEmpty();
    static void FromJustIsNothing();
    static napi_ref CreateReference(napi_env env, napi_value value, uint32_t initial_refcount);
    static void DeleteReference(napi_env env, napi_ref ref);
    static napi_value GetReferenceValue(napi_env env, napi_ref ref);
    static uint32_t ReferenceRef(napi_env env, napi_ref ref);
    static uint32_t ReferenceUnRef(napi_env env, napi_ref ref);
    static void* Unwrap(napi_env env, napi_value js_object);
    static napi_ref Wrap(
        napi_env env,
        napi_value js_object,
        void* native_object,
        napi_finalize finalize_cb,
        void* finalize_hint);
    static void DefineClass(
        napi_env env,
        const char* utf8name,
        napi_callback ctor,
        size_t property_count,
        const napi_property_descriptor* descriptors,
        void* data,
        napi_class* result);
};

/**
 * @brief Napi::Env wrapper around napi_env__ (0x027b74..0x02811f)
 *        Lớp bọc Napi::Env quanh napi_env__ (0x027b74..0x02811f)
 */
class Env {
public:
    napi_env _env = nullptr;

    Env() = default;
    Env(napi_env env) noexcept : _env(env) {}
    operator napi_env() const noexcept { return _env; }

    Object Global() const;
    Value Undefined() const;
    Value Null() const;
    Value Loader() const;
    bool IsExceptionPending() const;
    Value GetAndClearPendingException();
    Value GetUnhandledRecjectionException(); // Exact symbol spelling in .dynsym @ 0x027dfc
    void InitCodeCache(int32_t capacity, const std::string& path, std::function<void(bool)> cb);
    void OutputCodeCache();
    Value RunScriptCache(const char* script, size_t length, const char* filename);
    Value RunScript(const char* script, size_t length, const char* filename);
    void* GetInstanceData(uint64_t key);
    void SetInstanceData(uint64_t key, void* data, napi_finalize finalize_cb, void* hint);
    void AddCleanupHook(void (*fn)(void*), void* arg);
    void RemoveCleanupHook(void (*fn)(void*), void* arg);
    void DumpCacheStatus(std::vector<std::pair<std::string, int>>* out);
};

/**
 * @brief Napi::Value (sizeof = 0x10 = 16 bytes: {_env, _value}, 0x028120..0x028fdb)
 *        Lớp Napi::Value (sizeof = 0x10 = 16 bytes: {_env, _value}, 0x028120..0x028fdb)
 */
class Value {
public:
    napi_env _env = nullptr;     // +0x00
    napi_value _value = nullptr; // +0x08

    Value() = default;
    Value(napi_env env, napi_value val) noexcept : _env(env), _value(val) {}
    operator napi_value() const noexcept { return _value; }
    napi_env Env() const noexcept { return _env; }
    bool IsEmpty() const noexcept { return _value == nullptr; }

    bool StrictEquals(const Value& other) const;
    bool Equals(const Value& other) const;
    napi_valuetype Type() const;
    bool IsUndefined() const;
    bool IsNull() const;
    bool IsBoolean() const;
    bool IsNumber() const;
    bool IsString() const;
    bool IsSymbol() const;
    bool IsArray() const;
    bool IsArrayBuffer() const;
    bool IsTypedArray() const;
    bool IsInt8Array() const;
    bool IsUint8Array() const;
    bool IsUint8ClampedArray() const;
    bool IsInt16Array() const;
    bool IsUint16Array() const;
    bool IsInt32Array() const;
    bool IsUint32Array() const;
    bool IsFloat32Array() const;
    bool IsFloat64Array() const;
    bool IsObject() const;
    bool IsFunction() const;
    bool IsPromise() const;
    bool IsDataView() const;
    bool IsExternal() const;

    Boolean ToBoolean() const;
    Number ToNumber() const;
    String ToString() const;
    Object ToObject() const;
};

class Boolean : public Value {
public:
    Boolean() = default;
    Boolean(napi_env env, napi_value val) noexcept : Value(env, val) {}
    static Boolean New(napi_env env, bool val);
    bool Value() const;
};

class Number : public Value {
public:
    Number() = default;
    Number(napi_env env, napi_value val) noexcept : Value(env, val) {}
    static Number New(napi_env env, double val);
    int32_t Int32Value() const;
    uint32_t Uint32Value() const;
    int64_t Int64Value() const;
    float FloatValue() const;
    double DoubleValue() const;
};

class Name : public Value {
public:
    Name() = default;
    Name(napi_env env, napi_value val) noexcept : Value(env, val) {}
};

class String : public Name {
public:
    String() = default;
    String(napi_env env, napi_value val) noexcept : Name(env, val) {}
    static String New(napi_env env, const char* val);
    static String New(napi_env env, const char16_t* val);
    static String New(napi_env env, const char* val, size_t length);
    static String New(napi_env env, const char16_t* val, size_t length);
    std::string Utf8Value() const;
    std::u16string Utf16Value() const;
};

class Symbol : public Name {
public:
    Symbol() = default;
    Symbol(napi_env env, napi_value val) noexcept : Name(env, val) {}
    static Symbol New(napi_env env, const char* description);
    static Symbol New(napi_env env, napi_value description);
    static Symbol New(napi_env env, String description);
    static Symbol WellKnown(napi_env env, const char* name);
};

class Object : public Value {
public:
    Object() = default;
    Object(napi_env env, napi_value val) noexcept : Value(env, val) {}
    static Object New(napi_env env);
    static Value GetOwnPropertyDescriptor(napi_env env, Value obj, Value prop);

    Value Get(const char* utf8name) const;
    Value Get(napi_value key) const;
    Value Get(uint32_t index) const;
    bool Has(napi_value key) const;
    bool Has(const char* utf8name) const;
    bool Has(uint32_t index) const;
    bool HasOwnProperty(napi_value key) const;
    bool HasOwnProperty(const char* utf8name) const;
    void Set(const char* utf8name, napi_value value);
    void Set(napi_value key, napi_value value);
    void Set(uint32_t index, napi_value value);
    bool Delete(napi_value key);
    bool Delete(const char* utf8name);
    bool Delete(uint32_t index);
    Array GetPropertyNames() const;
    void DefineProperty(const PropertyDescriptor& property);
    void DefineProperties(const std::initializer_list<PropertyDescriptor>& properties);
    void DefineProperties(const std::vector<PropertyDescriptor>& properties);
    bool InstanceOf(const Function& constructor) const;
    void AddFinalizer(void* native_object, napi_finalize finalize_cb, void* hint);
};

class Array : public Object {
public:
    Array() = default;
    Array(napi_env env, napi_value val) noexcept : Object(env, val) {}
    static Array New(napi_env env);
    static Array New(napi_env env, size_t length);
    uint32_t Length() const;
};

class ArrayBuffer : public Object {
public:
    void* _data = nullptr;  // +0x10
    size_t _length = 0;     // +0x18

    ArrayBuffer() = default;
    ArrayBuffer(napi_env env, napi_value val) noexcept : Object(env, val) {}
    static ArrayBuffer New(napi_env env, size_t byteLength);
    static ArrayBuffer New(napi_env env, void* externalData, size_t byteLength);
    static ArrayBuffer New(
        napi_env env,
        void* externalData,
        size_t byteLength,
        napi_finalize finalizeCallback,
        void* finalizeHint);
    void* Data();
    size_t ByteLength();
};

class DataView : public Object {
public:
    void* _data = nullptr;  // +0x10
    size_t _length = 0;     // +0x18

    DataView() = default;
    DataView(napi_env env, napi_value val);
    static DataView New(napi_env env, ArrayBuffer arrayBuffer);
    static DataView New(napi_env env, ArrayBuffer arrayBuffer, size_t byteOffset);
    static DataView New(napi_env env, ArrayBuffer arrayBuffer, size_t byteOffset, size_t byteLength);
    ArrayBuffer ArrayBuffer() const;
    size_t ByteOffset() const;
};

class TypedArray : public Object {
public:
    napi_typedarray_type _type = static_cast<napi_typedarray_type>(-1); // +0x10
    size_t _length = 0;                                                 // +0x18

    TypedArray() = default;
    TypedArray(napi_env env, napi_value val) noexcept : Object(env, val) {}
    TypedArray(napi_env env, napi_value val, napi_typedarray_type type, size_t length) noexcept
        : Object(env, val), _type(type), _length(length) {}

    napi_typedarray_type TypedArrayType() const;
    uint8_t ElementSize() const;
    size_t ElementLength() const;
    size_t ByteOffset() const;
    size_t ByteLength() const;
    Napi::ArrayBuffer ArrayBuffer() const;
};

#define DECLARE_NAPI_TYPED_ARRAY(ClassName)                                              \
    class ClassName : public TypedArray {                                                \
    public:                                                                              \
        ClassName() = default;                                                           \
        ClassName(napi_env env, napi_value val);                                         \
        static ClassName New(napi_env env, size_t elementLength);                        \
        static ClassName New(                                                            \
            napi_env env,                                                                \
            size_t elementLength,                                                        \
            Napi::ArrayBuffer arrayBuffer,                                               \
            size_t bufferOffset);                                                        \
    };

DECLARE_NAPI_TYPED_ARRAY(Int8Array)
DECLARE_NAPI_TYPED_ARRAY(Int16Array)
DECLARE_NAPI_TYPED_ARRAY(Int32Array)
DECLARE_NAPI_TYPED_ARRAY(Uint8ClampedArray)
DECLARE_NAPI_TYPED_ARRAY(Uint8Array)
DECLARE_NAPI_TYPED_ARRAY(Uint16Array)
DECLARE_NAPI_TYPED_ARRAY(Uint32Array)
DECLARE_NAPI_TYPED_ARRAY(Float32Array)
DECLARE_NAPI_TYPED_ARRAY(Float64Array)

#undef DECLARE_NAPI_TYPED_ARRAY

class CallbackInfo {
public:
    napi_env _env = nullptr;                  // +0x00
    napi_callback_info _info = nullptr;       // +0x08
    napi_value _this = nullptr;               // +0x10
    size_t _argc = 0;                         // +0x18
    napi_value* _argv = nullptr;              // +0x20
    napi_value _staticArgv[6] = {nullptr};    // +0x28..+0x57
    void* _data = nullptr;                    // +0x58

    CallbackInfo(napi_env env, napi_callback_info info);
    ~CallbackInfo();

    Value NewTarget() const;
    bool IsConstructCall() const;
    size_t Length() const noexcept { return _argc; }
    Value operator[](size_t i) const noexcept {
        return (i < _argc && _argv) ? Value(_env, _argv[i]) : Value(_env, nullptr);
    }
    Value This() const noexcept { return Value(_env, _this); }
    void* Data() const noexcept { return _data; }
};

class Function : public Object {
public:
    using Callback = Value (*)(const CallbackInfo&);

    Function() = default;
    Function(napi_env env, napi_value val) noexcept : Object(env, val) {}
    static Function New(napi_env env, Callback cb, const char* utf8name = nullptr, void* data = nullptr);
    Value Call(size_t argc, const napi_value* argv) const;
    Value Call(napi_value recv, size_t argc, const napi_value* argv) const;
    Object New(size_t argc, const napi_value* argv) const;
};

class Promise : public Object {
public:
    class Deferred {
    public:
        napi_env _env = nullptr;           // +0x00
        napi_deferred _deferred = nullptr; // +0x08
        napi_value _promise = nullptr;     // +0x10

        static Deferred New(napi_env env);
        Deferred(napi_env env);
        ~Deferred();
        void Resolve(napi_value value);
        void Reject(napi_value value);
    };
};

class External : public Value {
public:
    External() = default;
    External(napi_env env, napi_value val) noexcept : Value(env, val) {}
    static External New(napi_env env, void* data, napi_finalize finalize_cb = nullptr, void* hint = nullptr);
    void* Data() const;
};

class Error : public Object {
public:
    Error() = default;
    Error(napi_env env, napi_value val) noexcept : Object(env, val) {}
    static Error New(napi_env env);
    static Error New(napi_env env, const char* message);
    static napi_value Create(
        napi_env env,
        const char* message,
        size_t length,
        napi_status (*create_fn)(napi_env, napi_value, napi_value, napi_value*));
    void ThrowAsJavaScriptException() const;
};

class TypeError : public Error {
public:
    static TypeError New(napi_env env, const char* message);
};

class RangeError : public Error {
public:
    static RangeError New(napi_env env, const char* message);
};

class PropertyDescriptor {
public:
    napi_property_descriptor _desc{};

    PropertyDescriptor(const napi_property_descriptor& desc) noexcept : _desc(desc) {}
    operator const napi_property_descriptor&() const noexcept { return _desc; }

    static PropertyDescriptor Accessor(
        Napi::Env env,
        Napi::Object object,
        const char* utf8name,
        Function::Callback getter,
        void (*setter)(const CallbackInfo&, const Value&),
        napi_property_attributes attributes,
        void* data);
    static PropertyDescriptor Accessor(
        Napi::Env env,
        Napi::Object object,
        Napi::Name name,
        Function::Callback getter,
        void (*setter)(const CallbackInfo&, const Value&),
        napi_property_attributes attributes,
        void* data);
    static PropertyDescriptor Function(
        Napi::Env env,
        Napi::Object object,
        const char* utf8name,
        Function::Callback cb,
        napi_property_attributes attributes,
        void* data);
    static PropertyDescriptor Function(
        Napi::Env env,
        Napi::Object object,
        Napi::Name name,
        Function::Callback cb,
        napi_property_attributes attributes,
        void* data);
    static PropertyDescriptor Value(
        const char* utf8name,
        napi_value value,
        napi_property_attributes attributes);
    static PropertyDescriptor Value(
        napi_value name,
        napi_value value,
        napi_property_attributes attributes);
};

class Class {
public:
    napi_env _env = nullptr;     // +0x00
    napi_class _class = nullptr; // +0x08

    Class() = default;
    Class(napi_env env, napi_class clazz) noexcept : _env(env), _class(clazz) {}
    ~Class();
    Function Get(napi_env env);
};

class ScriptWrappable {
public:
    napi_env _env = nullptr;     // +0x08
    napi_ref _wrapper = nullptr; // +0x10

    ScriptWrappable();
    virtual ~ScriptWrappable();
};

class HandleScope {
public:
    napi_env _env = nullptr;              // +0x00
    napi_handle_scope _scope = nullptr;   // +0x08

    HandleScope(Napi::Env env);
    ~HandleScope();
};

class ContextScope {
public:
    napi_env _env = nullptr;              // +0x00
    napi_context_scope _scope = nullptr;  // +0x08

    ContextScope(Napi::Env env);
    ~ContextScope();
};

class EscapableHandleScope {
public:
    napi_env _env = nullptr;                        // +0x00
    napi_escapable_handle_scope _scope = nullptr;   // +0x08

    EscapableHandleScope(Napi::Env env);
    ~EscapableHandleScope();
    Value Escape(napi_value escapee);
};

class ErrorScope {
public:
    napi_env _env = nullptr;            // +0x00
    napi_error_scope _scope = nullptr;  // +0x08

    ErrorScope(Napi::Env env);
    ~ErrorScope();
};

class AsyncWorker {
public:
    napi_env _env = nullptr;          // +0x08
    napi_async_work _work = nullptr;  // +0x10

    AsyncWorker(Napi::Env env);
    virtual ~AsyncWorker();
    virtual void Execute() = 0;
    virtual void OnOK() {}
    virtual void OnError(const Error& /*e*/) {}
    virtual void Destroy() {}

    void OnWorkComplete(Napi::Env env, napi_status status);
    void Queue();
    void Cancel();
};

class MemoryManagement {
public:
    static int64_t AdjustExternalMemory(Napi::Env env, int64_t change_in_bytes);
};

} // namespace Napi
