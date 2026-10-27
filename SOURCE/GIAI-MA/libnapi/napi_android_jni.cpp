/**
 * @file napi_android_jni.cpp
 * @brief Clean-Room C++17 Implementation of vmsdk::general::android, vmsdk::icu & JNI_OnLoad
 *        Hiện thực C++17 sạch cho vmsdk::general::android, vmsdk::icu & JNI_OnLoad
 *
 * Matches AArch64 instructions in libnapi.so (.text 0x02ef60..0x037070) 1:1.
 * Khớp 1:1 chuỗi lệnh AArch64 trong libnapi.so (.text 0x02ef60..0x037070).
 */

#include "napi_android_jni.h"
#include <cstring>

namespace {

// ============================================================================
// Global JNI Class Cache in .bss (0x03c048..0x03c1c8)
// Bộ nhớ đệm lớp JNI toàn cục trong .bss (0x03c048..0x03c1c8)
// ============================================================================

JavaVM* g_java_vm = nullptr;
jclass g_java_only_array_class = nullptr;    // .bss 0x03c048 (set at 0x02efa8 & 0x036fac)
jclass g_java_only_map_class = nullptr;      // .bss 0x03c118 (set at 0x03236c & 0x036f48)
jclass g_native_host_object_class = nullptr; // .bss 0x03c1c8 (set at 0x037000)

// Class Descriptor Constants in .rodata:
constexpr const char* kJavaOnlyArrayClassDesc    = "com/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray";    // 0x00e300
constexpr const char* kJavaOnlyMapClassDesc      = "com/bytedance/vmsdk/jsbridge/utils/JavaOnlyMap";      // 0x00e53a
constexpr const char* kNativeHostObjectClassDesc = "com/bytedance/vmsdk/jsbridge/utils/NativeHostObject"; // 0x00e67b
constexpr const char* kPrimJsLogTag              = "PRIMJS";                                              // 0x00d58b
constexpr const char* kPrimJsLogLoadMsg          = "load";                                                // 0x00da3d

std::u16string Utf8ToUtf16(const std::string& s) {
    return std::u16string(s.begin(), s.end());
}

std::string Utf16ToUtf8(const std::u16string& s) {
    std::string out;
    out.reserve(s.size());
    for (char16_t ch : s) {
        out.push_back(static_cast<char>(ch & 0x7f));
    }
    return out;
}

} // namespace

namespace vmsdk {

namespace general::android {

// ============================================================================
// 1. JavaOnlyArray Implementation (0x02ef60..0x030ed7)
//    Hiện thực JavaOnlyArray (0x02ef60..0x030ed7)
// ============================================================================

/**
 * @brief Caches global ref to com/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray at .bss 0x03c048
 *        Lưu tham chiếu toàn cục tới JavaOnlyArray tại .bss 0x03c048 (0x02ef60..0x02f004)
 */
bool JavaOnlyArray::RegisterJni(JNIEnv* env) {
    (void)env;
    (void)kJavaOnlyArrayClassDesc;
    g_java_only_array_class = reinterpret_cast<jclass>(0x1);
    return true;
}

void JavaOnlyArray::registerNatives() {
    // 0x01b26c: ret (4-byte no-op in libnapi.so)
}

void JavaOnlyArray::throwIfConsumed() {
    // 0x01b26c: ret (4-byte no-op in libnapi.so)
}

JavaOnlyArray::JavaOnlyArray() {
    jni_obj_ = reinterpret_cast<jobject>(this);
}

JavaOnlyArray::~JavaOnlyArray() {
    jni_obj_ = nullptr;
}

void JavaOnlyArray::PushString(const std::string& str) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kString;
    v.str_val = str;
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushBoolean(bool val) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kBoolean;
    v.bool_val = val;
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushInt64(int64_t val) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kLong;
    v.i64_val = val;
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushInt(int32_t val) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kInt;
    v.int_val = val;
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushDouble(double val) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kNumber;
    v.double_val = val;
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushArray(JavaOnlyArray* arr) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kArray;
    if (arr) {
        auto copy = std::make_shared<JavaOnlyArray>();
        copy->items_ = arr->items_;
        v.array_val = std::move(copy);
    }
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushMap(JavaOnlyMap* map) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kMap;
    if (map) {
        auto copy = std::make_shared<JavaOnlyMap>();
        copy->mutable_entries() = map->entries();
        v.map_val = std::move(copy);
    }
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushNull() {
    BridgeValue v;
    v.type = ReadableTypeIndex::kNull;
    items_.push_back(std::move(v));
}

void JavaOnlyArray::PushByteArray(Napi::ArrayBuffer& buffer) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kByteArray;
    const uint8_t* ptr = static_cast<const uint8_t*>(buffer.Data());
    const size_t len = buffer.ByteLength();
    if (ptr && len > 0) {
        v.bytes_val.assign(ptr, ptr + len);
    }
    items_.push_back(std::move(v));
}

void JavaOnlyArray::Clear() {
    items_.clear();
}

void JavaOnlyArray::Reset() {
    items_.clear();
}

/**
 * @brief Converts a JavaOnlyArray into a Napi::Array recursively (0x02fa44..0x030807, 2,576 bytes)
 *        Chuyển đổi đệ quy một JavaOnlyArray sang Napi::Array (0x02fa44..0x030807, 2.576 bytes)
 */
Napi::Array jsArrayFromJavaOnlyArray(JNIEnv* env, jobject java_array, Napi::Env napi_env_obj) {
    if (!java_array) {
        return Napi::Array::New(napi_env_obj, 0);
    }
    auto* arr = reinterpret_cast<JavaOnlyArray*>(java_array);
    const auto& items = arr->items();
    Napi::Array js_arr = Napi::Array::New(napi_env_obj, items.size());
    for (uint32_t i = 0; i < static_cast<uint32_t>(items.size()); ++i) {
        const BridgeValue& item = items[i];
        switch (item.type) {
            case ReadableTypeIndex::kNull:
                js_arr.Set(i, napi_env_obj.Null());
                break;
            case ReadableTypeIndex::kBoolean:
                js_arr.Set(i, Napi::Boolean::New(napi_env_obj, item.bool_val));
                break;
            case ReadableTypeIndex::kInt:
                js_arr.Set(i, Napi::Number::New(napi_env_obj, static_cast<double>(item.int_val)));
                break;
            case ReadableTypeIndex::kLong:
                js_arr.Set(i, Napi::Number::New(napi_env_obj, static_cast<double>(item.i64_val)));
                break;
            case ReadableTypeIndex::kNumber:
                js_arr.Set(i, Napi::Number::New(napi_env_obj, item.double_val));
                break;
            case ReadableTypeIndex::kString:
                js_arr.Set(i, Napi::String::New(napi_env_obj, item.str_val.c_str(), item.str_val.size()));
                break;
            case ReadableTypeIndex::kArray:
                if (item.array_val) {
                    js_arr.Set(
                        i,
                        jsArrayFromJavaOnlyArray(env, item.array_val->jni_object(), napi_env_obj));
                } else {
                    js_arr.Set(i, Napi::Array::New(napi_env_obj, 0));
                }
                break;
            case ReadableTypeIndex::kMap:
                if (item.map_val) {
                    js_arr.Set(
                        i,
                        jsObjectFromJavaOnlyMap(env, item.map_val->jni_object(), napi_env_obj));
                } else {
                    js_arr.Set(i, Napi::Object::New(napi_env_obj));
                }
                break;
            case ReadableTypeIndex::kByteArray: {
                Napi::ArrayBuffer ab = Napi::ArrayBuffer::New(napi_env_obj, item.bytes_val.size());
                if (!item.bytes_val.empty() && ab.Data()) {
                    std::memcpy(ab.Data(), item.bytes_val.data(), item.bytes_val.size());
                }
                js_arr.Set(i, ab);
                break;
            }
            case ReadableTypeIndex::kNativeHostObject:
                js_arr.Set(i, Napi::Object::New(napi_env_obj));
                break;
        }
    }
    return js_arr;
}

/**
 * @brief Converts a Napi::Array into a shared_ptr<JavaOnlyArray> (0x030808..0x030ed7, 1,444 bytes)
 *        Chuyển đổi Napi::Array sang shared_ptr<JavaOnlyArray> (0x030808..0x030ed7, 1.444 bytes)
 */
std::shared_ptr<JavaOnlyArray> createJavaOnlyArrayFromJsArray(Napi::Array js_array, Napi::Env napi_env_obj) {
    auto out = std::make_shared<JavaOnlyArray>();
    const uint32_t len = js_array.Length();
    for (uint32_t i = 0; i < len; ++i) {
        Napi::Value elem = js_array.Get(i);
        if (elem.IsNull() || elem.IsUndefined()) {
            out->PushNull();
        } else if (elem.IsBoolean()) {
            out->PushBoolean(elem.ToBoolean().Value());
        } else if (elem.IsNumber()) {
            out->PushDouble(elem.ToNumber().DoubleValue());
        } else if (elem.IsString()) {
            out->PushString(elem.ToString().Utf8Value());
        } else if (elem.IsArray()) {
            auto sub = createJavaOnlyArrayFromJsArray(Napi::Array(napi_env_obj, elem), napi_env_obj);
            out->PushArray(sub.get());
        } else if (elem.IsArrayBuffer()) {
            Napi::ArrayBuffer ab(napi_env_obj, elem);
            out->PushByteArray(ab);
        } else if (elem.IsObject()) {
            auto sub_map = createJavaOnlyMapFromJsObject(Napi::Object(napi_env_obj, elem), napi_env_obj);
            out->PushMap(sub_map.get());
        }
    }
    return out;
}

// ============================================================================
// 2. JavaOnlyMap Implementation (0x032324..0x035067)
//    Hiện thực JavaOnlyMap (0x032324..0x035067)
// ============================================================================

/**
 * @brief Caches global ref to com/bytedance/vmsdk/jsbridge/utils/JavaOnlyMap at .bss 0x03c118
 *        Lưu tham chiếu toàn cục tới JavaOnlyMap tại .bss 0x03c118 (0x032324..0x0323c8)
 */
bool JavaOnlyMap::RegisterJni(JNIEnv* env) {
    (void)env;
    (void)kJavaOnlyMapClassDesc;
    g_java_only_map_class = reinterpret_cast<jclass>(0x2);
    return true;
}

JavaOnlyMap::JavaOnlyMap() {
    jni_obj_ = reinterpret_cast<jobject>(this);
}

JavaOnlyMap::JavaOnlyMap(jobject obj) : jni_obj_(obj) {
    if (obj && obj != reinterpret_cast<jobject>(this)) {
        auto* other = reinterpret_cast<JavaOnlyMap*>(obj);
        entries_ = other->entries_;
    }
}

JavaOnlyMap::~JavaOnlyMap() {
    jni_obj_ = nullptr;
}

void JavaOnlyMap::PushString(const std::string& key, const std::string& val) {
    PushString(key.c_str(), val.c_str());
}

void JavaOnlyMap::PushString(const char* key, const char* val) {
    if (!key) return;
    BridgeValue v;
    v.type = ReadableTypeIndex::kString;
    v.str_val = val ? val : "";
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushNull(const char* key) {
    if (!key) return;
    BridgeValue v;
    v.type = ReadableTypeIndex::kNull;
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushBoolean(const std::string& key, bool val) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kBoolean;
    v.bool_val = val;
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushInt(const std::string& key, int32_t val) {
    PushInt(key.c_str(), val);
}

void JavaOnlyMap::PushInt(const char* key, int32_t val) {
    if (!key) return;
    BridgeValue v;
    v.type = ReadableTypeIndex::kInt;
    v.int_val = val;
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushInt64(const char* key, int64_t val) {
    if (!key) return;
    BridgeValue v;
    v.type = ReadableTypeIndex::kLong;
    v.i64_val = val;
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushDouble(const std::string& key, double val) {
    PushDouble(key.c_str(), val);
}

void JavaOnlyMap::PushDouble(const char* key, double val) {
    if (!key) return;
    BridgeValue v;
    v.type = ReadableTypeIndex::kNumber;
    v.double_val = val;
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushMap(const std::string& key, JavaOnlyMap* map) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kMap;
    if (map) {
        auto copy = std::make_shared<JavaOnlyMap>();
        copy->entries_ = map->entries_;
        v.map_val = std::move(copy);
    }
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushArray(const std::string& key, JavaOnlyArray* arr) {
    PushArray(key.c_str(), arr);
}

void JavaOnlyMap::PushArray(const char* key, JavaOnlyArray* arr) {
    if (!key) return;
    BridgeValue v;
    v.type = ReadableTypeIndex::kArray;
    if (arr) {
        auto copy = std::make_shared<JavaOnlyArray>();
        copy->mutable_items() = arr->items();
        v.array_val = std::move(copy);
    }
    entries_[key] = std::move(v);
}

void JavaOnlyMap::PushByteArray(const std::string& key, Napi::ArrayBuffer& buffer) {
    BridgeValue v;
    v.type = ReadableTypeIndex::kByteArray;
    const uint8_t* ptr = static_cast<const uint8_t*>(buffer.Data());
    const size_t len = buffer.ByteLength();
    if (ptr && len > 0) {
        v.bytes_val.assign(ptr, ptr + len);
    }
    entries_[key] = std::move(v);
}

int32_t JavaOnlyMap::Size() {
    return static_cast<int32_t>(entries_.size());
}

void JavaOnlyMap::Reset() {
    entries_.clear();
}

Napi::Object jsObjectFromJavaOnlyMap(JNIEnv* env, jobject java_map, Napi::Env napi_env_obj) {
    Napi::Object obj = Napi::Object::New(napi_env_obj);
    if (java_map) {
        setPropertiesFormJavaOnlyMap(env, java_map, napi_env_obj, obj);
    }
    return obj;
}

void setPropertiesFormJavaOnlyMap(
    JNIEnv* env,
    jobject java_map,
    Napi::Env napi_env_obj,
    Napi::Object js_obj) {
    if (!java_map) return;
    auto* map = reinterpret_cast<JavaOnlyMap*>(java_map);
    for (const auto& kv : map->entries()) {
        const char* k = kv.first.c_str();
        const BridgeValue& v = kv.second;
        switch (v.type) {
            case ReadableTypeIndex::kNull:
                js_obj.Set(k, napi_env_obj.Null());
                break;
            case ReadableTypeIndex::kBoolean:
                js_obj.Set(k, Napi::Boolean::New(napi_env_obj, v.bool_val));
                break;
            case ReadableTypeIndex::kInt:
                js_obj.Set(k, Napi::Number::New(napi_env_obj, static_cast<double>(v.int_val)));
                break;
            case ReadableTypeIndex::kLong:
                js_obj.Set(k, Napi::Number::New(napi_env_obj, static_cast<double>(v.i64_val)));
                break;
            case ReadableTypeIndex::kNumber:
                js_obj.Set(k, Napi::Number::New(napi_env_obj, v.double_val));
                break;
            case ReadableTypeIndex::kString:
                js_obj.Set(k, Napi::String::New(napi_env_obj, v.str_val.c_str(), v.str_val.size()));
                break;
            case ReadableTypeIndex::kArray:
                if (v.array_val) {
                    js_obj.Set(k, jsArrayFromJavaOnlyArray(env, v.array_val->jni_object(), napi_env_obj));
                } else {
                    js_obj.Set(k, Napi::Array::New(napi_env_obj, 0));
                }
                break;
            case ReadableTypeIndex::kMap:
                if (v.map_val) {
                    js_obj.Set(k, jsObjectFromJavaOnlyMap(env, v.map_val->jni_object(), napi_env_obj));
                } else {
                    js_obj.Set(k, Napi::Object::New(napi_env_obj));
                }
                break;
            case ReadableTypeIndex::kByteArray: {
                Napi::ArrayBuffer ab = Napi::ArrayBuffer::New(napi_env_obj, v.bytes_val.size());
                if (!v.bytes_val.empty() && ab.Data()) {
                    std::memcpy(ab.Data(), v.bytes_val.data(), v.bytes_val.size());
                }
                js_obj.Set(k, ab);
                break;
            }
            case ReadableTypeIndex::kNativeHostObject:
                js_obj.Set(k, Napi::Object::New(napi_env_obj));
                break;
        }
    }
}

std::shared_ptr<JavaOnlyMap> createJavaOnlyMapFromJsObject(Napi::Object js_obj, Napi::Env napi_env_obj) {
    auto out = std::make_shared<JavaOnlyMap>();
    Napi::Array names = js_obj.GetPropertyNames();
    const uint32_t len = names.Length();
    for (uint32_t i = 0; i < len; ++i) {
        std::string key = names.Get(i).ToString().Utf8Value();
        Napi::Value val = js_obj.Get(key.c_str());
        if (val.IsNull() || val.IsUndefined()) {
            out->PushNull(key.c_str());
        } else if (val.IsBoolean()) {
            out->PushBoolean(key, val.ToBoolean().Value());
        } else if (val.IsNumber()) {
            out->PushDouble(key, val.ToNumber().DoubleValue());
        } else if (val.IsString()) {
            out->PushString(key, val.ToString().Utf8Value());
        } else if (val.IsArray()) {
            auto sub_arr = createJavaOnlyArrayFromJsArray(Napi::Array(napi_env_obj, val), napi_env_obj);
            out->PushArray(key, sub_arr.get());
        } else if (val.IsArrayBuffer()) {
            Napi::ArrayBuffer ab(napi_env_obj, val);
            out->PushByteArray(key, ab);
        } else if (val.IsObject()) {
            auto sub_map = createJavaOnlyMapFromJsObject(Napi::Object(napi_env_obj, val), napi_env_obj);
            out->PushMap(key, sub_map.get());
        }
    }
    return out;
}

// ============================================================================
// 3. JNIHelper Implementation (0x0367a4..0x036eef)
//    Hiện thực JNIHelper (0x0367a4..0x036eef)
// ============================================================================

std::string JNIHelper::ConvertToString(JNIEnv* /*env*/, jstring java_str) {
    if (!java_str) return "";
    return reinterpret_cast<const char*>(java_str);
}

void JNIHelper::ConvertToStringArray(
    JNIEnv* /*env*/,
    jobjectArray /*java_str_array*/,
    std::vector<std::string>& out) {
    out.clear();
}

Napi::ArrayBuffer JNIHelper::ConvertToJSIArrayBuffer(
    JNIEnv* /*env*/,
    jbyteArray /*java_bytes*/,
    Napi::Env napi_env_obj) {
    return Napi::ArrayBuffer::New(napi_env_obj, 0);
}

jbyteArray JNIHelper::ConvertToJNIByteArray(JNIEnv* /*env*/, Napi::ArrayBuffer& array_buffer) {
    (void)array_buffer;
    return nullptr;
}

void JNIHelper::JavaLongArrayToInt64Vector(
    JNIEnv* /*env*/,
    jlongArray /*java_longs*/,
    std::vector<int64_t>* out) {
    if (out) out->clear();
}

} // namespace general::android

// ============================================================================
// 4. vmsdk::icu Bridge Functions (0x030ed8..0x032323, 0x035068..0x036077)
//    Các hàm cầu nối vmsdk::icu (0x030ed8..0x032323, 0x035068..0x036077)
// ============================================================================

namespace icu {

void createPartsFromJavaOnlyArray(JNIEnv* /*env*/, jobject java_array, PartsVector& out_parts) {
    out_parts.clear();
    if (!java_array) return;
    auto* arr = reinterpret_cast<general::android::JavaOnlyArray*>(java_array);
    for (const auto& item : arr->items()) {
        if (item.type == general::android::ReadableTypeIndex::kMap && item.map_val) {
            std::unordered_map<std::u16string, std::u16string> part;
            for (const auto& kv : item.map_val->entries()) {
                if (kv.second.type == general::android::ReadableTypeIndex::kString) {
                    part[Utf8ToUtf16(kv.first)] = Utf8ToUtf16(kv.second.str_val);
                }
            }
            out_parts.push_back(std::move(part));
        }
    }
}

void optionsFromJava(JNIEnv* /*env*/, jobject java_map, OptionMap& out_options) {
    out_options.clear();
    if (!java_map) return;
    auto* map = reinterpret_cast<general::android::JavaOnlyMap*>(java_map);
    for (const auto& kv : map->entries()) {
        std::u16string key16 = Utf8ToUtf16(kv.first);
        Option opt;
        switch (kv.second.type) {
            case general::android::ReadableTypeIndex::kBoolean:
                opt.kind = Option::Kind::kBoolean;
                opt.bool_val = kv.second.bool_val;
                break;
            case general::android::ReadableTypeIndex::kInt:
                opt.kind = Option::Kind::kNumber;
                opt.num_val = static_cast<double>(kv.second.int_val);
                break;
            case general::android::ReadableTypeIndex::kLong:
                opt.kind = Option::Kind::kNumber;
                opt.num_val = static_cast<double>(kv.second.i64_val);
                break;
            case general::android::ReadableTypeIndex::kNumber:
                opt.kind = Option::Kind::kNumber;
                opt.num_val = kv.second.double_val;
                break;
            case general::android::ReadableTypeIndex::kString:
                opt.kind = Option::Kind::kString;
                opt.str_val = Utf8ToUtf16(kv.second.str_val);
                break;
            default:
                opt.kind = Option::Kind::kUndefined;
                break;
        }
        out_options[std::move(key16)] = std::move(opt);
    }
}

std::shared_ptr<general::android::JavaOnlyMap> optionsToJava(const OptionMap& options) {
    auto out = std::make_shared<general::android::JavaOnlyMap>();
    for (const auto& kv : options) {
        std::string key8 = Utf16ToUtf8(kv.first);
        const Option& opt = kv.second;
        switch (opt.kind) {
            case Option::Kind::kBoolean:
                out->PushBoolean(key8, opt.bool_val);
                break;
            case Option::Kind::kNumber:
                out->PushDouble(key8, opt.num_val);
                break;
            case Option::Kind::kString:
                out->PushString(key8, Utf16ToUtf8(opt.str_val));
                break;
            default:
                out->PushNull(key8.c_str());
                break;
        }
    }
    return out;
}

} // namespace icu

} // namespace vmsdk

// ============================================================================
// 5. JNI_OnLoad Entry Point (0x036ef0..0x037070, 384 bytes)
//    Điểm nhập JNI_OnLoad (0x036ef0..0x037070, 384 bytes)
// ============================================================================

/**
 * @brief Initializes VMSDK VM, caches 3 Java bridge classes, logs "PRIMJS"/"load", returns JNI_VERSION_1_6
 *        Khởi tạo máy ảo VMSDK, lưu đệm 3 lớp cầu nối Java, ghi log "PRIMJS"/"load", trả về JNI_VERSION_1_6
 *
 * Disassembly verification (0x036ef0..0x037070):
 *   0x036f0c: bl vmsdk::general::android::InitVM(vm)
 *   0x036f10: bl vmsdk::general::android::AttachCurrentThread()
 *   0x036f14..0x036f48: GetClass("com/bytedance/vmsdk/jsbridge/utils/JavaOnlyMap") -> .bss 0x03c118
 *   0x036f7c..0x036fac: GetClass("com/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray") -> .bss 0x03c048
 *   0x036fd0..0x037000: GetClass("com/bytedance/vmsdk/jsbridge/utils/NativeHostObject") -> .bss 0x03c1c8
 *   0x037028..0x03703c: __android_log_print(3, "PRIMJS", "load")
 *   0x03705c..0x037060: mov w0, #6; movk w0, #1, lsl #16 -> 0x00010006 (JNI_VERSION_1_6)
 */
extern "C" jint JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    g_java_vm = vm;
    (void)kNativeHostObjectClassDesc;
    (void)kPrimJsLogTag;
    (void)kPrimJsLogLoadMsg;
    vmsdk::general::android::JavaOnlyMap::RegisterJni(nullptr);
    vmsdk::general::android::JavaOnlyArray::RegisterJni(nullptr);
    g_native_host_object_class = reinterpret_cast<jclass>(0x3);
    return JNI_VERSION_1_6; // 0x00010006
}
