// ============================================================================
// File: jazz_types.h
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (Legacy: TASK_SO_122_libjazz)
// Classification: CORE_07_SCRIPTING_VM (ByteDance AmazingEngine Jazz JS Runtime & NAPI Modules)
//
// Description (EN):
// Exact AArch64 ABI types, constants, GF(2)^8 affine involution S-Box
// (.rodata 0x28bf0..0x28cf0), embedded JavaScript bundles (bootstrap.js at
// .rodata 0x27037, makeRequire.js at .rodata 0x297d2), and NAPI C++ wrapper
// classes reconstructed from libjazz.so.
//
// Mô tả (VI):
// Định nghĩa kiểu dữ liệu chuẩn ABI AArch64, hằng số, hộp thế đối hợp affine
// GF(2)^8 (.rodata 0x28bf0..0x28cf0), mã nguồn JavaScript nhúng (bootstrap.js
// tại .rodata 0x27037, makeRequire.js tại .rodata 0x297d2) và các lớp bao NAPI
// phục hồi từ libjazz.so.
// ============================================================================

#pragma once

#include <array>
#include <atomic>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <functional>
#include <initializer_list>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <unordered_map>
#include <vector>

// ============================================================================
// 1. Forward Declarations for NAPI & QuickJS / LEPUS C Handles
// Khai báo chuyển tiếp các con trỏ câu lệnh NAPI và QuickJS / LEPUS.
// ============================================================================
struct napi_env__;
struct napi_value__;
struct napi_ref__;
struct napi_callback_info__;
struct napi_class__;
struct napi_property_descriptor;
struct napi_module;
struct LEPUSRuntime;
struct LEPUSContext;

namespace Napi {

class Env;
class Value;
class Boolean;
class Number;
class String;
class Object;
class Array;
class ArrayBuffer;
class Function;
class Error;
class TypeError;
class CallbackInfo;
class HandleScope;

// ============================================================================
// 2. Clean-Room NAPI C++ Wrapper Hierarchy Used by AmazingEngine (libjazz.so)
// Hệ thống phân cấp lớp bao C++ NAPI được AmazingEngine sử dụng trong libjazz.so.
// ============================================================================
class Value {
public:
    Value() noexcept = default;
    Value(napi_env__* env, napi_value__* val) noexcept : env_(env), val_(val) {}

    bool IsEmpty() const noexcept { return val_ == nullptr; }
    bool IsUndefined() const noexcept;
    bool IsBoolean() const noexcept;
    bool IsNumber() const noexcept;
    bool IsString() const noexcept;
    bool IsObject() const noexcept;
    bool IsArrayBuffer() const noexcept;
    bool IsFunction() const noexcept;

    Boolean ToBoolean() const noexcept;
    Number ToNumber() const noexcept;
    String ToString() const noexcept;
    Object ToObject() const noexcept;

    napi_env__* EnvPtr() const noexcept { return env_; }
    napi_value__* RawValue() const noexcept { return val_; }
    operator napi_value__*() const noexcept { return val_; }

protected:
    napi_env__* env_{nullptr};
    napi_value__* val_{nullptr};
};

class Boolean : public Value {
public:
    using Value::Value;
    static Boolean New(napi_env__* env, bool val) noexcept;
    bool ValueOf() const noexcept { return bool_val_; }

private:
    bool bool_val_{false};
};

class Number : public Value {
public:
    using Value::Value;
    static Number New(napi_env__* env, double val) noexcept;
    int32_t Int32Value() const noexcept { return static_cast<int32_t>(num_val_); }
    uint32_t Uint32Value() const noexcept { return static_cast<uint32_t>(num_val_); }
    double DoubleValue() const noexcept { return num_val_; }

private:
    double num_val_{0.0};
};

class String : public Value {
public:
    using Value::Value;
    static String New(napi_env__* env, const char* str) noexcept;
    std::string Utf8Value() const;

private:
    std::string str_val_;
};

class Object : public Value {
public:
    using Value::Value;
    static Object New(napi_env__* env) noexcept;
    bool Has(const char* key) const noexcept;
    Value Get(const char* key) const noexcept;
    void Set(const char* key, napi_value__* val) noexcept;
    void AddFinalizer(void* data, void (*cb)(napi_env__*, void*, void*), void* hint) noexcept;
};

class Array : public Object {
public:
    using Object::Object;
    uint32_t Length() const noexcept { return static_cast<uint32_t>(elements_.size()); }
    Value Get(uint32_t idx) const noexcept {
        return idx < elements_.size() ? elements_[idx] : Value();
    }
    void AddElement(const Value& v) { elements_.push_back(v); }

private:
    std::vector<Value> elements_;
};

class ArrayBuffer : public Object {
public:
    using Object::Object;
    static ArrayBuffer New(napi_env__* env,
                           void* external_data,
                           size_t byte_length,
                           void (*finalize_cb)(napi_env__*, void*, void*) = nullptr,
                           void* finalize_hint = nullptr) noexcept;
    void* Data() const noexcept { return data_; }
    size_t ByteLength() const noexcept { return byte_length_; }

private:
    void* data_{nullptr};
    size_t byte_length_{0};
};

class Function : public Object {
public:
    using CallbackFn = Value (*)(const CallbackInfo&);
    using Object::Object;

    static Function New(napi_env__* env,
                        CallbackFn cb,
                        const char* name = nullptr,
                        void* data = nullptr) noexcept;

    Value Call(size_t argc, const napi_value__* const* argv) const;
    Value Call(napi_value__* recv, size_t argc, const napi_value__* const* argv) const;
    Object NewInstance(size_t argc, const napi_value__* const* argv) const;
};

class Error : public Object {
public:
    using Object::Object;
    explicit Error(const char* msg = "") : message_(msg ? msg : ""), stack_("at JazzRuntime:1:1") {}
    const std::string& Message() const noexcept { return message_; }
    const std::string& Stack() const noexcept { return stack_; }
    void ThrowAsJavaScriptException() const noexcept {}

private:
    std::string message_;
    std::string stack_;
};

class TypeError : public Error {
public:
    using Error::Error;
    static TypeError New(napi_env__* env, const char* msg) noexcept {
        (void)env;
        return TypeError(msg);
    }
};

class Env {
public:
    explicit Env(napi_env__* env = nullptr) noexcept : env_(env) {}

    napi_env__* Raw() const noexcept { return env_; }
    operator napi_env__*() const noexcept { return env_; }

    Object Global() const noexcept { return Object::New(env_); }
    Object Loader() const noexcept { return Object::New(env_); }
    Value Undefined() const noexcept { return Value(env_, nullptr); }
    Value Null() const noexcept { return Value(env_, nullptr); }

    bool IsExceptionPending() const noexcept { return exception_pending_; }
    Error GetAndClearPendingException() noexcept {
        exception_pending_ = false;
        return Error("Cleared Pending Exception");
    }

    Value RunScript(const char* script, size_t len, const char* filename);
    void* GetInstanceData(uint64_t key) const noexcept;
    void SetInstanceData(uint64_t key,
                         void* data,
                         void (*finalize_cb)(napi_env__*, void*, void*) = nullptr,
                         void* hint = nullptr) noexcept;
    void AddCleanupHook(void (*cb)(void*), void* arg) noexcept;

private:
    napi_env__* env_{nullptr};
    bool exception_pending_{false};
};

class CallbackInfo {
public:
    CallbackInfo(napi_env__* env, napi_callback_info__* info) noexcept;
    explicit CallbackInfo(Env env, std::vector<Value> args = {}, void* data = nullptr) noexcept;
    ~CallbackInfo() noexcept;

    Env GetEnv() const noexcept { return env_; }
    size_t Length() const noexcept { return args_.size(); }
    Value operator[](size_t idx) const noexcept {
        return idx < args_.size() ? args_[idx] : env_.Undefined();
    }
    Value This() const noexcept { return this_val_; }
    void* Data() const noexcept { return data_; }
    bool IsConstructCall() const noexcept { return is_construct_call_; }

private:
    Env env_;
    std::vector<Value> args_;
    Value this_val_;
    void* data_{nullptr};
    bool is_construct_call_{false};
};

class HandleScope {
public:
    explicit HandleScope(Env env) noexcept : env_(env) {}
    ~HandleScope() noexcept = default;
    Env GetEnv() const noexcept { return env_; }

private:
    Env env_;
};

class ScriptWrappable {
public:
    ScriptWrappable() noexcept = default;
    virtual ~ScriptWrappable() noexcept = default;
};

template <typename T>
class ObjectWrap : public ScriptWrappable {
public:
    explicit ObjectWrap(const CallbackInfo& info) noexcept : env_(info.GetEnv()) {}
    ~ObjectWrap() noexcept override = default;
    Env GetEnv() const noexcept { return env_; }

private:
    Env env_;
};

} // namespace Napi

namespace AmazingEngine {

// ============================================================================
// 3. AmazingEngine Core Enums & Handles
// Verified from disassembly:
//   - JSEngineType: VM::CreateVM (0x01a46c) checks `cmp w0, #2` -> QUICKJS = 2
//   - Platform::CreateRuntime (0x014fcc) logs "__EngineType" = "QUICKJS" / "UNKNOWN"
//   - BEFBaseRunner::GetNext (0x00cbc4) loads 1000.0 from .rodata 0x25b80
// Các kiểu liệt kê cốt lõi của AmazingEngine đối chiếu từ hợp ngữ AArch64.
// ============================================================================
enum class JSEngineType : int32_t {
    UNKNOWN = 0,
    V8      = 1,
    QUICKJS = 2  // Verified at 0x01a488: cmp w0, #2 (0x7100081f)
};

enum class RuntimeMode : int32_t {
    SINGLE_CONTEXT = 0,
    MULTI_CONTEXT  = 1
};

enum class TaskRunnerMode : int32_t {
    IMMEDIATE_MODE = 0,
    DEDICATED_THREAD_MODE = 1
};

struct CtxHandler {
    napi_env__* env = nullptr;
    void* opaque = nullptr;
};

constexpr double kJazzMillisecondsPerSecond = 1000.0; // .rodata 0x25b80 (0x408f400000000000ULL)
constexpr uint32_t kJazzHashMaxLoadFactorBits = 0x3F800000U; // 1.0f at 0x018fec & 0x021644
constexpr size_t kJazzBootstrapEncodedOffset   = 0x27037U;   // 0x178c4: adrp x1, #0x27000; add x1, x1, #0x37
constexpr size_t kJazzBootstrapEncodedSize     = 0x1BB9U;    // 7,097 bytes (0x178d0: mov w2, #0x1bb9)
constexpr size_t kJazzMakeRequireEncodedOffset = 0x297D2U;   // 0x216b0: adrp x1, #0x29000; add x1, x1, #0x7d2
constexpr size_t kJazzMakeRequireEncodedSize   = 0x0246U;    // 582 bytes (0x216bc: mov w2, #0x246)
constexpr size_t kJazzSBoxRodataOffset         = 0x28BF0U;   // 0x17a0c: adrp x9, #0x28000; add x9, x9, #0xbf0

// ============================================================================
// 4. Exact 256-Byte GF(2)^8 Affine Involution S-Box at .rodata 0x28bf0..0x28cf0
// Proven closed-form algebraic formula:
//   SBox[x] = x ^ 0xF0 ^ ((x & 1) * 0x54) ^ (((x >> 1) & 1) * 0xA8)
//           = x ^ 0xF0 ^ ((x & 3) * 0x54)
// Self-inverse property: SBox[SBox[x]] == x for all x in [0, 255].
// Bảng thế 256-byte đối hợp affine GF(2)^8 tại .rodata 0x28bf0..0x28cf0.
// ============================================================================
constexpr uint8_t computeJazzSBoxByte(uint8_t x) noexcept {
    return static_cast<uint8_t>(x ^ 0xF0U ^ ((x & 0x03U) * 0x54U));
}

constexpr std::array<uint8_t, 256> kJazzSBox256 = {
    0xf0,0xa5,0x5a,0x0f,0xf4,0xa1,0x5e,0x0b,0xf8,0xad,0x52,0x07,0xfc,0xa9,0x56,0x03,
    0xe0,0xb5,0x4a,0x1f,0xe4,0xb1,0x4e,0x1b,0xe8,0xbd,0x42,0x17,0xec,0xb9,0x46,0x13,
    0xd0,0x85,0x7a,0x2f,0xd4,0x81,0x7e,0x2b,0xd8,0x8d,0x72,0x27,0xdc,0x89,0x76,0x23,
    0xc0,0x95,0x6a,0x3f,0xc4,0x91,0x6e,0x3b,0xc8,0x9d,0x62,0x37,0xcc,0x99,0x66,0x33,
    0xb0,0xe5,0x1a,0x4f,0xb4,0xe1,0x1e,0x4b,0xb8,0xed,0x12,0x47,0xbc,0xe9,0x16,0x43,
    0xa0,0xf5,0x0a,0x5f,0xa4,0xf1,0x0e,0x5b,0xa8,0xfd,0x02,0x57,0xac,0xf9,0x06,0x53,
    0x90,0xc5,0x3a,0x6f,0x94,0xc1,0x3e,0x6b,0x98,0xcd,0x32,0x67,0x9c,0xc9,0x36,0x63,
    0x80,0xd5,0x2a,0x7f,0x84,0xd1,0x2e,0x7b,0x88,0xdd,0x22,0x77,0x8c,0xd9,0x26,0x73,
    0x70,0x25,0xda,0x8f,0x74,0x21,0xde,0x8b,0x78,0x2d,0xd2,0x87,0x7c,0x29,0xd6,0x83,
    0x60,0x35,0xca,0x9f,0x64,0x31,0xce,0x9b,0x68,0x3d,0xc2,0x97,0x6c,0x39,0xc6,0x93,
    0x50,0x05,0xfa,0xaf,0x54,0x01,0xfe,0xab,0x58,0x0d,0xf2,0xa7,0x5c,0x09,0xf6,0xa3,
    0x40,0x15,0xea,0xbf,0x44,0x11,0xee,0xbb,0x48,0x1d,0xe2,0xb7,0x4c,0x19,0xe6,0xb3,
    0x30,0x65,0x9a,0xcf,0x34,0x61,0x9e,0xcb,0x38,0x6d,0x92,0xc7,0x3c,0x69,0x96,0xc3,
    0x20,0x75,0x8a,0xdf,0x24,0x71,0x8e,0xdb,0x28,0x7d,0x82,0xd7,0x2c,0x79,0x86,0xd3,
    0x10,0x45,0xba,0xef,0x14,0x41,0xbe,0xeb,0x18,0x4d,0xb2,0xe7,0x1c,0x49,0xb6,0xe3,
    0x00,0x55,0xaa,0xff,0x04,0x51,0xae,0xfb,0x08,0x5d,0xa2,0xf7,0x0c,0x59,0xa6,0xf3
};

// Exact implementation of sub_17a08 (0x17a08..0x17a38):
//   for (size_t i = 0; i < total_len - 1; ++i) dst[i] = kJazzSBox256[src[i]];
//   dst[total_len - 1] = '\0';
void decodeJazzSBoxBuffer(char* dst, const uint8_t* src, size_t total_len) noexcept;

// Decoded embedded scripts from .rodata 0x297d2 (makeRequire.js) & 0x27037 (bootstrap.js)
const char* getDecodedMakeRequireJs() noexcept;
const char* getDecodedBootstrapJs() noexcept;

class AllowList {
public:
    AllowList() = default;
    void addAllowedPrefix(const std::string& prefix) { prefixes_.push_back(prefix); }
    bool isAllowed(const std::string& path) const;

private:
    std::vector<std::string> prefixes_;
};

} // namespace AmazingEngine
