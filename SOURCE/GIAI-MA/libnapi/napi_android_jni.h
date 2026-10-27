/**
 * @file napi_android_jni.h
 * @brief Clean-Room C++17 Declarations for vmsdk::general::android & vmsdk::icu + JNI_OnLoad
 *        Khai báo C++17 sạch cho vmsdk::general::android & vmsdk::icu + JNI_OnLoad
 *
 * Binary Source Path (.rodata 0x00cb32):
 *   "/ws/228/bytebus/repositories/64f55d36a1934e8a59474a720b2d591d/"
 *   "b01c65cec201ce6e47a1f549784d4463/basic/android/java_only_map.cc"
 *
 * Binary Addresses in libnapi.so (.text 0x02ef60..0x037070):
 *   - JavaOnlyArray::RegisterJni          : 0x02ef60 (168 bytes)
 *   - JavaOnlyArray::JavaOnlyArray        : 0x02f038 (268 bytes)
 *   - JavaOnlyArray::~JavaOnlyArray       : 0x02f1dc (92 bytes)
 *   - JavaOnlyArray::Push* / Clear / Reset: 0x02f238..0x02fa43
 *   - jsArrayFromJavaOnlyArray            : 0x02fa44 (2,576 bytes)
 *   - createJavaOnlyArrayFromJsArray      : 0x030808 (1,444 bytes)
 *   - icu::createPartsFromJavaOnlyArray   : 0x030ed8 (3,268 bytes)
 *   - JavaOnlyMap::RegisterJni            : 0x032324 (168 bytes)
 *   - JavaOnlyMap::JavaOnlyMap            : 0x0323cc (284 bytes) & 0x0324e8 (60 bytes)
 *   - JavaOnlyMap::~JavaOnlyMap           : 0x032524 (72 bytes)
 *   - JavaOnlyMap::Push* / Size / Reset   : 0x03256c..0x03321f
 *   - jsObjectFromJavaOnlyMap             : 0x033220 (376 bytes)
 *   - setPropertiesFormJavaOnlyMap        : 0x033398 (3,320 bytes)
 *   - createJavaOnlyMapFromJsObject       : 0x034090 (1,368 bytes)
 *   - icu::optionsFromJava                : 0x035068 (2,356 bytes)
 *   - icu::optionsToJava                  : 0x035df8 (640 bytes)
 *   - JNIHelper::ConvertTo*               : 0x0367a4..0x036eef
 *   - JNI_OnLoad                          : 0x036ef0 (384 bytes)
 */

#pragma once

#include "napi_cpp_wrapper.h"
#include <memory>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace vmsdk {

namespace general::android {

class JavaOnlyMap;

/**
 * @brief ReadableType index matching com.bytedance.vmsdk.jsbridge.utils.ReadableType
 *        Chỉ số kiểu ReadableType khớp com.bytedance.vmsdk.jsbridge.utils.ReadableType
 */
enum class ReadableTypeIndex : int32_t {
    kNull = 0,
    kBoolean = 1,
    kInt = 2,
    kNumber = 3,
    kString = 4,
    kMap = 5,
    kArray = 6,
    kLong = 7,
    kByteArray = 8,
    kNativeHostObject = 9,
};

struct BridgeValue {
    ReadableTypeIndex type = ReadableTypeIndex::kNull;
    bool bool_val = false;
    int32_t int_val = 0;
    int64_t i64_val = 0;
    double double_val = 0.0;
    std::string str_val;
    std::vector<uint8_t> bytes_val;
    std::shared_ptr<class JavaOnlyArray> array_val;
    std::shared_ptr<class JavaOnlyMap> map_val;
    int64_t host_object_ptr = 0;
};

/**
 * @brief C++ wrapper for com/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray (0x02ef60..0x02fa43)
 *        Lớp bọc C++ cho com/bytedance/vmsdk/jsbridge/utils/JavaOnlyArray (0x02ef60..0x02fa43)
 */
class JavaOnlyArray {
public:
    static bool RegisterJni(JNIEnv* env);
    static void registerNatives();
    void throwIfConsumed();

    JavaOnlyArray();
    ~JavaOnlyArray();

    void PushString(const std::string& str);
    void PushBoolean(bool val);
    void PushInt64(int64_t val);
    void PushInt(int32_t val);
    void PushDouble(double val);
    void PushArray(JavaOnlyArray* arr);
    void PushMap(JavaOnlyMap* map);
    void PushNull();
    void PushByteArray(Napi::ArrayBuffer& buffer);
    void Clear();
    void Reset();

    jobject jni_object() const noexcept { return jni_obj_; }
    const std::vector<BridgeValue>& items() const noexcept { return items_; }
    std::vector<BridgeValue>& mutable_items() noexcept { return items_; }

private:
    jobject jni_obj_ = nullptr; // +0x08 (ScopedGlobalJavaRef<jobject>)
    std::vector<BridgeValue> items_;
};

/**
 * @brief C++ wrapper for com/bytedance/vmsdk/jsbridge/utils/JavaOnlyMap (0x032324..0x03321f)
 *        Lớp bọc C++ cho com/bytedance/vmsdk/jsbridge/utils/JavaOnlyMap (0x032324..0x03321f)
 */
class JavaOnlyMap {
public:
    static bool RegisterJni(JNIEnv* env);

    JavaOnlyMap();
    explicit JavaOnlyMap(jobject obj);
    ~JavaOnlyMap();

    void PushString(const std::string& key, const std::string& val);
    void PushString(const char* key, const char* val);
    void PushNull(const char* key);
    void PushBoolean(const std::string& key, bool val);
    void PushInt(const std::string& key, int32_t val);
    void PushInt(const char* key, int32_t val);
    void PushInt64(const char* key, int64_t val);
    void PushDouble(const std::string& key, double val);
    void PushDouble(const char* key, double val);
    void PushMap(const std::string& key, JavaOnlyMap* map);
    void PushArray(const std::string& key, JavaOnlyArray* arr);
    void PushArray(const char* key, JavaOnlyArray* arr);
    void PushByteArray(const std::string& key, Napi::ArrayBuffer& buffer);
    int32_t Size();
    void Reset();

    jobject jni_object() const noexcept { return jni_obj_; }
    const std::unordered_map<std::string, BridgeValue>& entries() const noexcept { return entries_; }
    std::unordered_map<std::string, BridgeValue>& mutable_entries() noexcept { return entries_; }

private:
    jobject jni_obj_ = nullptr; // +0x00 (ScopedGlobalJavaRef<jobject>)
    std::unordered_map<std::string, BridgeValue> entries_;
};

// Bridge Conversion Functions (0x02fa44..0x030ed7, 0x033220..0x035067)
Napi::Array jsArrayFromJavaOnlyArray(JNIEnv* env, jobject java_array, Napi::Env napi_env_obj);
std::shared_ptr<JavaOnlyArray> createJavaOnlyArrayFromJsArray(Napi::Array js_array, Napi::Env napi_env_obj);

Napi::Object jsObjectFromJavaOnlyMap(JNIEnv* env, jobject java_map, Napi::Env napi_env_obj);
void setPropertiesFormJavaOnlyMap(JNIEnv* env, jobject java_map, Napi::Env napi_env_obj, Napi::Object js_obj);
std::shared_ptr<JavaOnlyMap> createJavaOnlyMapFromJsObject(Napi::Object js_obj, Napi::Env napi_env_obj);

/**
 * @brief JNIHelper conversion utilities (0x0367a4..0x036eef)
 *        Các tiện ích chuyển đổi JNIHelper (0x0367a4..0x036eef)
 */
class JNIHelper {
public:
    static std::string ConvertToString(JNIEnv* env, jstring java_str);
    static void ConvertToStringArray(
        JNIEnv* env,
        jobjectArray java_str_array,
        std::vector<std::string>& out);
    static Napi::ArrayBuffer ConvertToJSIArrayBuffer(
        JNIEnv* env,
        jbyteArray java_bytes,
        Napi::Env napi_env_obj);
    static jbyteArray ConvertToJNIByteArray(JNIEnv* env, Napi::ArrayBuffer& array_buffer);
    static void JavaLongArrayToInt64Vector(
        JNIEnv* env,
        jlongArray java_longs,
        std::vector<int64_t>* out);
};

} // namespace general::android

namespace icu {

struct Option {
    enum class Kind : int32_t {
        kUndefined = 0,
        kBoolean = 1,
        kNumber = 2,
        kString = 3,
        kStringVector = 4,
    };
    Kind kind = Kind::kUndefined;
    bool bool_val = false;
    double num_val = 0.0;
    std::u16string str_val;
    std::vector<std::u16string> vec_val;
};

using OptionMap = std::unordered_map<std::u16string, Option>;
using PartsVector = std::vector<std::unordered_map<std::u16string, std::u16string>>;

void createPartsFromJavaOnlyArray(JNIEnv* env, jobject java_array, PartsVector& out_parts);
void optionsFromJava(JNIEnv* env, jobject java_map, OptionMap& out_options);
std::shared_ptr<general::android::JavaOnlyMap> optionsToJava(const OptionMap& options);

} // namespace icu

} // namespace vmsdk

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved);
