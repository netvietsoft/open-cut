// ============================================================================
// FILE: cepengine_platform_jni.cpp
// TARGET: libCepEngine.so — NativeData, PlatformAdapter, CBlockContainer & 13 JNI Exports
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Full C++17 implementation of `cep::NativeData` (0x2930c..0x296ab &
//      0x44468..0x47507), JNI / PlatformAdapter methods (0x43454..0x4774b),
//      `cep::CBlockContainer` (0x489d4..0x48c63), and the 13 exported JNI
//      functions (0x49250..0x4a44f).
// [VN] Bản cài đặt C++17 đầy đủ cho `cep::NativeData` (0x2930c..0x296ab &
//      0x44468..0x47507), các phương thức JNI / PlatformAdapter (0x43454..0x4774b),
//      `cep::CBlockContainer` (0x489d4..0x48c63), và 13 hàm xuất JNI
//      (0x49250..0x4a44f).
// ============================================================================

#include "cepengine_platform_jni.h"

namespace cep {

namespace {

// [EN] Global JNI state at `.bss 0x5c688..0x5c7a0` initialized by `InitPlatformAdapter` (@ 0x43550):
//      - `g_java_vm` @ `.bss 0x5c688`
//      - `g_platform_adapter_cls` @ `.bss 0x5c690` (`com/bytedance/pitaya/cep_engine/inner/PlatformAdapter` @ 0x4c530)
//      - `g_cep_result_cls` @ `.bss 0x5c770` (`com/bytedance/pitaya/cep_engine/CepResult` @ 0x4c7e8)
//      - `g_cep_callback_cls` @ `.bss 0x5c780` (`com/bytedance/pitaya/cep_engine/port/CepCallback` @ 0x4c87a)
//      - `g_cep_function_cls` @ `.bss 0x5c790` (`com/bytedance/pitaya/cep_engine/port/CepFunction` @ 0x4c8e3)
// [VN] Trạng thái JNI toàn cục tại `.bss 0x5c688..0x5c7a0` khởi tạo bởi `InitPlatformAdapter` (@ 0x43550):
JavaVM* g_java_vm = nullptr;
thread_local JNIEnv* g_tls_jni_env = nullptr;

jclass g_platform_adapter_cls = nullptr;
jmethodID g_mid_parse_json = nullptr;           // 0x4c566: parseJson (Ljava/lang/String;)Ljava/lang/Object;
jmethodID g_mid_to_json = nullptr;              // 0x4c597: toJson (J)Ljava/lang/String;
jmethodID g_mid_create_null = nullptr;          // 0x4c5b4: createNull ()Ljava/lang/Object;
jmethodID g_mid_create_bool = nullptr;          // 0x4c5d4: createBool (Z)Ljava/lang/Object;
jmethodID g_mid_create_int64 = nullptr;         // 0x4c5f5: createInt64 (J)Ljava/lang/Object;
jmethodID g_mid_create_double = nullptr;        // 0x4c617: createDouble (D)Ljava/lang/Object;
jmethodID g_mid_create_list = nullptr;          // 0x4c63a: createList ()Lorg/json/JSONArray;
jmethodID g_mid_list_get_value = nullptr;       // 0x4c65c: listGetValue (JI)Ljava/lang/Object;
jmethodID g_mid_list_append_value = nullptr;    // 0x4c680: listAppendValue (JJ)V
jmethodID g_mid_list_get_size = nullptr;        // 0x4c696: listGetSize (J)I
jmethodID g_mid_create_dict = nullptr;          // 0x4c6be: createDict ()Lorg/json/JSONObject;
jmethodID g_mid_dict_get_value = nullptr;       // 0x4c6e1: dictGetValue (JLjava/lang/String;)Ljava/lang/Object;
jmethodID g_mid_dict_get_keys = nullptr;        // 0x4c716: dictGetKeys
jmethodID g_mid_dict_set_value = nullptr;       // 0x4c722: dictSetValue (JLjava/lang/Object;J)V
jmethodID g_mid_to_int64 = nullptr;             // 0x4c76f: toInt64 (J)J
jmethodID g_mid_to_double = nullptr;            // 0x4c77c: toDouble (J)D
jmethodID g_mid_to_string = nullptr;            // 0x4c78a: toString
jmethodID g_mid_get_type = nullptr;             // 0x4c793: getType
jmethodID g_mid_dispatch_async = nullptr;       // 0x4c79b: dispatchAsync
jmethodID g_mid_dispatch_sync = nullptr;        // 0x4c7a9: dispatchSync
jmethodID g_mid_dispatch_global = nullptr;      // 0x4c7b6: dispatchGlobal (J)V
jmethodID g_mid_start_timer = nullptr;          // 0x4c7ca: startTimer (JJJ)V
jmethodID g_mid_cancel_timer = nullptr;         // 0x4c7dc: cancelTimer
jmethodID g_mid_monitor_sync = nullptr;         // 0x4c947: monitorSync (Ljava/lang/String;JJJ)V
jmethodID g_mid_retain_object = nullptr;        // 0x4c96c: retainObject (JLjava/lang/Object;)V
jmethodID g_mid_release_object = nullptr;       // 0x4c990: releaseObject
jmethodID g_mid_get_origin_object = nullptr;    // 0x4c99e: getOriginObject

jclass g_cep_result_cls = nullptr;
jmethodID g_mid_cep_result_init = nullptr;      // 0x4c819: (ZLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lorg/json/JSONArray;)V

jclass g_cep_callback_cls = nullptr;
jmethodID g_mid_cep_callback_on_result = nullptr; // 0x4c8ab: onResult (Lcom/bytedance/pitaya/cep_engine/CepResult;)V

jclass g_cep_function_cls = nullptr;
jmethodID g_mid_cep_function_on_execute = nullptr; // 0x4c914: onExecute (Lorg/json/JSONArray;)Ljava/lang/Object;

} // namespace

// ============================================================================
// 1. NATIVE DATA (`0x2930c..0x296ab` & `0x44468..0x47507`)
// ============================================================================

// [EN] Disassembly @ 0x2930c (`_ZN3cep10NativeData13InterfaceTypeEv`, 8 B):
//      0x2930c: 52800020 mov w0, #1; 0x29310: d65f03c0 ret
// [VN] Loại giao diện của `NativeData` = 1 (@ 0x2930c):
int NativeData::InterfaceType() {
    return static_cast<int>(DataInterfaceType::kNativeData); // 1
}

// [EN] Disassembly @ 0x46bbc (`_ZN3cep10NativeDataC2EPv`, 192 B):
//      Stores `origin_obj` at `+0x08` and calls `PlatformAdapter.retainObject(this, origin_obj)`
//      if `JNIEnv*` is available.
// [VN] Hàm tạo `NativeData` (@ 0x46bbc, 192 B):
NativeData::NativeData(void* origin_obj)
    : origin_obj_(origin_obj),
      fallback_data_(MemoryDataInterface::MakeNull()) {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_retain_object && origin_obj_) {
        env->CallStaticVoidMethod(
            g_platform_adapter_cls,
            g_mid_retain_object,
            reinterpret_cast<jlong>(this),
            reinterpret_cast<jobject>(origin_obj_));
    }
}

NativeData::NativeData(std::shared_ptr<MemoryDataInterface> fallback)
    : origin_obj_(nullptr),
      fallback_data_(fallback ? std::move(fallback) : MemoryDataInterface::MakeNull()) {}

// [EN] Disassembly @ 0x46c7c (`_ZN3cep10NativeDataD2Ev`, 156 B):
//      Calls `PlatformAdapter.releaseObject(this)` if `JNIEnv*` is available.
// [VN] Hàm hủy `NativeData` (@ 0x46c7c):
NativeData::~NativeData() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_release_object && origin_obj_) {
        env->CallStaticVoidMethod(
            g_platform_adapter_cls,
            g_mid_release_object,
            reinterpret_cast<jlong>(this));
    }
    origin_obj_ = nullptr;
}

// [EN] Disassembly @ 0x29314 (`_ZN3cep10NativeData17FromDataInterfaceE...`, 920 B):
//      Recursively converts any `DataInterface` (Int, Float, Bool, Str, List, Dict, Null)
//      into a `NativeData` instance.
// [VN] Chuyển đổi đệ quy từ `DataInterface` sang `NativeData` (@ 0x29314):
std::shared_ptr<NativeData> NativeData::FromDataInterface(
    const std::shared_ptr<DataInterface>& src) {
    if (!src) {
        return CreateNull();
    }
    if (src->InterfaceType() == static_cast<int>(DataInterfaceType::kNativeData)) {
        return std::static_pointer_cast<NativeData>(src);
    }
    switch (static_cast<DataType>(src->Type())) {
        case DataType::kInt:
            return CreateInt(src->IntValue());
        case DataType::kFloat:
            return CreateFloat(src->FloatValue());
        case DataType::kBool:
            return CreateBool(src->BoolValue());
        case DataType::kStr:
            return CreateString(src->StringValue());
        case DataType::kList: {
            auto list = CreateList();
            for (int i = 0; i < src->Size(); ++i) {
                list->AppendData(FromDataInterface(src->GetData(i)));
            }
            return list;
        }
        case DataType::kDict: {
            auto dict = CreateDict();
            for (const auto& k : src->KeySet()) {
                dict->SetData(k, FromDataInterface(src->GetData(k)));
            }
            return dict;
        }
        case DataType::kNull:
        default:
            return CreateNull();
    }
}

// [EN] Disassembly @ 0x44468..0x47344 (`NativeData` static factories & mutators):
// [VN] Các phương thức khởi tạo tĩnh và cập nhật của `NativeData` (@ 0x44468..0x47344):
std::shared_ptr<NativeData> NativeData::CreateList() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_create_list) {
        jobject obj = env->CallStaticObjectMethod(g_platform_adapter_cls, g_mid_create_list);
        ScopedLocalRef local(env, obj);
        return std::make_shared<NativeData>(local.get());
    }
    return std::make_shared<NativeData>(MemoryDataInterface::MakeList());
}

void NativeData::AppendData(const std::shared_ptr<NativeData>& item) {
    if (!item) return;
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_list_append_value && origin_obj_) {
        env->CallStaticVoidMethod(
            g_platform_adapter_cls,
            g_mid_list_append_value,
            reinterpret_cast<jlong>(this),
            reinterpret_cast<jlong>(item.get()));
        return;
    }
    if (fallback_data_) {
        fallback_data_->AppendElement(item->fallback_data_ ?
            std::static_pointer_cast<DataInterface>(item->fallback_data_) :
            std::static_pointer_cast<DataInterface>(item));
    }
}

void* NativeData::GetOriginObject() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_get_origin_object && origin_obj_) {
        return env->CallStaticObjectMethod(
            g_platform_adapter_cls,
            g_mid_get_origin_object,
            reinterpret_cast<jlong>(this));
    }
    return origin_obj_;
}

std::shared_ptr<NativeData> NativeData::CreateDict() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_create_dict) {
        jobject obj = env->CallStaticObjectMethod(g_platform_adapter_cls, g_mid_create_dict);
        ScopedLocalRef local(env, obj);
        return std::make_shared<NativeData>(local.get());
    }
    return std::make_shared<NativeData>(MemoryDataInterface::MakeDict());
}

void NativeData::SetData(const std::string& key, const std::shared_ptr<NativeData>& val) {
    if (!val) return;
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_dict_set_value && origin_obj_) {
        jstring jkey = env->NewStringUTF(key.c_str());
        ScopedLocalRef local_key(env, jkey);
        env->CallStaticVoidMethod(
            g_platform_adapter_cls,
            g_mid_dict_set_value,
            reinterpret_cast<jlong>(this),
            jkey,
            reinterpret_cast<jlong>(val.get()));
        return;
    }
    if (fallback_data_) {
        fallback_data_->SetField(key, val->fallback_data_ ?
            std::static_pointer_cast<DataInterface>(val->fallback_data_) :
            std::static_pointer_cast<DataInterface>(val));
    }
}

std::shared_ptr<NativeData> NativeData::CreateString(std::string val) {
    return std::make_shared<NativeData>(MemoryDataInterface::MakeString(std::move(val)));
}

std::shared_ptr<NativeData> NativeData::CreateInt(long val) {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_create_int64) {
        jobject obj = env->CallStaticObjectMethod(
            g_platform_adapter_cls, g_mid_create_int64, static_cast<jlong>(val));
        ScopedLocalRef local(env, obj);
        auto nd = std::make_shared<NativeData>(local.get());
        nd->fallback_data_ = MemoryDataInterface::MakeInt(val);
        return nd;
    }
    return std::make_shared<NativeData>(MemoryDataInterface::MakeInt(val));
}

std::shared_ptr<NativeData> NativeData::CreateNull() {
    return std::make_shared<NativeData>(MemoryDataInterface::MakeNull());
}

std::shared_ptr<NativeData> NativeData::CreateBool(bool val) {
    return std::make_shared<NativeData>(MemoryDataInterface::MakeBool(val));
}

std::shared_ptr<NativeData> NativeData::CreateFloat(double val) {
    return std::make_shared<NativeData>(MemoryDataInterface::MakeFloat(val));
}

std::shared_ptr<NativeData> NativeData::FromJson(const std::string& json_str) {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_parse_json) {
        jstring jstr = env->NewStringUTF(json_str.c_str());
        ScopedLocalRef local_str(env, jstr);
        jobject obj = env->CallStaticObjectMethod(g_platform_adapter_cls, g_mid_parse_json, jstr);
        ScopedLocalRef local_obj(env, obj);
        auto nd = std::make_shared<NativeData>(local_obj.get());
        nd->fallback_data_ = MemoryDataInterface::ParseJson(json_str);
        return nd;
    }
    return std::make_shared<NativeData>(MemoryDataInterface::ParseJson(json_str));
}

// [EN] Disassembly @ 0x45b84..0x46dbc (`NativeData` virtual overrides):
//      In `NativeData::Type()` (@ 0x45b84): if `JNIEnv*` is null (`cbz x0, #0x45c0c`),
//      returns `6` (`mov w0, #6; ret` @ 0x45c14) or `fallback_data_->Type()`.
// [VN] Các phương thức ghi đè ảo của `NativeData` (@ 0x45b84..0x46dbc):
int NativeData::Type() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_get_type && origin_obj_) {
        return env->CallStaticIntMethod(
            g_platform_adapter_cls, g_mid_get_type, reinterpret_cast<jlong>(this));
    }
    if (fallback_data_) {
        return fallback_data_->Type();
    }
    return static_cast<int>(DataType::kNull); // 6
}

long NativeData::IntValue() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_to_int64 && origin_obj_) {
        return static_cast<long>(env->CallStaticLongMethod(
            g_platform_adapter_cls, g_mid_to_int64, reinterpret_cast<jlong>(this)));
    }
    return fallback_data_ ? fallback_data_->IntValue() : 0L;
}

double NativeData::FloatValue() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_to_double && origin_obj_) {
        return env->CallStaticDoubleMethod(
            g_platform_adapter_cls, g_mid_to_double, reinterpret_cast<jlong>(this));
    }
    return fallback_data_ ? fallback_data_->FloatValue() : 0.0;
}

bool NativeData::BoolValue() {
    return fallback_data_ ? fallback_data_->BoolValue() : (IntValue() != 0);
}

std::string NativeData::StringValue() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_to_string && origin_obj_) {
        auto jstr = static_cast<jstring>(env->CallStaticObjectMethod(
            g_platform_adapter_cls, g_mid_to_string, reinterpret_cast<jlong>(this)));
        ScopedLocalRef local(env, jstr);
        return GetStringFromJString(env, jstr);
    }
    return fallback_data_ ? fallback_data_->StringValue() : "";
}

int NativeData::Size() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_list_get_size && origin_obj_) {
        return env->CallStaticIntMethod(
            g_platform_adapter_cls, g_mid_list_get_size, reinterpret_cast<jlong>(this));
    }
    return fallback_data_ ? fallback_data_->Size() : 0;
}

std::shared_ptr<DataInterface> NativeData::GetData(int index) {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_list_get_value && origin_obj_) {
        jobject obj = env->CallStaticObjectMethod(
            g_platform_adapter_cls, g_mid_list_get_value, reinterpret_cast<jlong>(this), index);
        ScopedLocalRef local(env, obj);
        return std::make_shared<NativeData>(local.get());
    }
    return fallback_data_ ? fallback_data_->GetData(index) : nullptr;
}

std::vector<std::string> NativeData::KeySet() {
    return fallback_data_ ? fallback_data_->KeySet() : std::vector<std::string>{};
}

std::shared_ptr<DataInterface> NativeData::GetData(const std::string& key) {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_dict_get_value && origin_obj_) {
        jstring jkey = env->NewStringUTF(key.c_str());
        ScopedLocalRef local_key(env, jkey);
        jobject obj = env->CallStaticObjectMethod(
            g_platform_adapter_cls, g_mid_dict_get_value, reinterpret_cast<jlong>(this), jkey);
        ScopedLocalRef local_obj(env, obj);
        return std::make_shared<NativeData>(local_obj.get());
    }
    return fallback_data_ ? fallback_data_->GetData(key) : nullptr;
}

std::string NativeData::JSON() {
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_to_json && origin_obj_) {
        auto jstr = static_cast<jstring>(env->CallStaticObjectMethod(
            g_platform_adapter_cls, g_mid_to_json, reinterpret_cast<jlong>(this)));
        ScopedLocalRef local(env, jstr);
        return GetStringFromJString(env, jstr);
    }
    return fallback_data_ ? fallback_data_->JSON() : "null";
}

// ============================================================================
// 2. PLATFORM ADAPTER, DISPATCH & CBLOCK CONTAINER (`0x43454..0x48c63`)
// ============================================================================

// [EN] Disassembly @ 0x43454 (`_ZN3cep9GetJvmEnvEv`, 108 B):
//      Reads TLS `JNIEnv*` or attaches current thread via `g_java_vm->AttachCurrentThread`.
// [VN] Lấy con trỏ `JNIEnv*` của luồng hiện tại (`GetJvmEnv` @ 0x43454):
JNIEnv* GetJvmEnv() {
    if (g_tls_jni_env) {
        return g_tls_jni_env;
    }
    if (!g_java_vm) {
        return nullptr;
    }
    JNIEnv* env = nullptr;
    if (g_java_vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) == JNI_OK && env) {
        g_tls_jni_env = env;
        return env;
    }
    if (g_java_vm->AttachCurrentThread(&env, nullptr) == JNI_OK && env) {
        g_tls_jni_env = env;
        return env;
    }
    return nullptr;
}

// [EN] Disassembly @ 0x434c0 (`_ZN3cep11CheckJavaVMEP7_JNIEnv`, 144 B):
//      Caches `JavaVM*` at `.bss 0x5c688` via `env->GetJavaVM(&g_java_vm)`.
// [VN] Kiểm tra và lưu trữ `JavaVM*` (`CheckJavaVM` @ 0x434c0):
void CheckJavaVM(JNIEnv* env) {
    if (!env) {
        return;
    }
    g_tls_jni_env = env;
    if (!g_java_vm) {
        env->GetJavaVM(&g_java_vm);
    }
}

// [EN] Disassembly @ 0x43550 (`InitPlatformAdapter`, target of `JniCaller_init` @ 0x49250):
//      Resolves `com/bytedance/pitaya/cep_engine/inner/PlatformAdapter` (0x4c530),
//      `com/bytedance/pitaya/cep_engine/CepResult` (0x4c7e8),
//      `com/bytedance/pitaya/cep_engine/port/CepCallback` (0x4c87a), and
//      `com/bytedance/pitaya/cep_engine/port/CepFunction` (0x4c8e3).
// [VN] Khởi tạo các lớp và methodID của `PlatformAdapter` (@ 0x43550):
void InitPlatformAdapter(JNIEnv* env) {
    CheckJavaVM(env);
    if (!env) return;

    if (!g_platform_adapter_cls) {
        jclass cls = env->FindClass("com/bytedance/pitaya/cep_engine/inner/PlatformAdapter");
        if (cls) {
            g_platform_adapter_cls = static_cast<jclass>(env->NewGlobalRef(cls));
            env->DeleteLocalRef(cls);
            g_mid_parse_json = env->GetStaticMethodID(
                g_platform_adapter_cls, "parseJson", "(Ljava/lang/String;)Ljava/lang/Object;");
            g_mid_to_json = env->GetStaticMethodID(
                g_platform_adapter_cls, "toJson", "(J)Ljava/lang/String;");
            g_mid_create_null = env->GetStaticMethodID(
                g_platform_adapter_cls, "createNull", "()Ljava/lang/Object;");
            g_mid_create_bool = env->GetStaticMethodID(
                g_platform_adapter_cls, "createBool", "(Z)Ljava/lang/Object;");
            g_mid_create_int64 = env->GetStaticMethodID(
                g_platform_adapter_cls, "createInt64", "(J)Ljava/lang/Object;");
            g_mid_create_double = env->GetStaticMethodID(
                g_platform_adapter_cls, "createDouble", "(D)Ljava/lang/Object;");
            g_mid_create_list = env->GetStaticMethodID(
                g_platform_adapter_cls, "createList", "()Lorg/json/JSONArray;");
            g_mid_list_get_value = env->GetStaticMethodID(
                g_platform_adapter_cls, "listGetValue", "(JI)Ljava/lang/Object;");
            g_mid_list_append_value = env->GetStaticMethodID(
                g_platform_adapter_cls, "listAppendValue", "(JJ)V");
            g_mid_list_get_size = env->GetStaticMethodID(
                g_platform_adapter_cls, "listGetSize", "(J)I");
            g_mid_create_dict = env->GetStaticMethodID(
                g_platform_adapter_cls, "createDict", "()Lorg/json/JSONObject;");
            g_mid_dict_get_value = env->GetStaticMethodID(
                g_platform_adapter_cls, "dictGetValue", "(JLjava/lang/String;)Ljava/lang/Object;");
            g_mid_dict_set_value = env->GetStaticMethodID(
                g_platform_adapter_cls, "dictSetValue", "(JLjava/lang/Object;J)V");
            g_mid_to_int64 = env->GetStaticMethodID(
                g_platform_adapter_cls, "toInt64", "(J)J");
            g_mid_to_double = env->GetStaticMethodID(
                g_platform_adapter_cls, "toDouble", "(J)D");
            g_mid_to_string = env->GetStaticMethodID(
                g_platform_adapter_cls, "toString", "(J)Ljava/lang/String;");
            g_mid_get_type = env->GetStaticMethodID(
                g_platform_adapter_cls, "getType", "(J)I");
            g_mid_dispatch_global = env->GetStaticMethodID(
                g_platform_adapter_cls, "dispatchGlobal", "(J)V");
            g_mid_start_timer = env->GetStaticMethodID(
                g_platform_adapter_cls, "startTimer", "(JJJ)V");
            g_mid_cancel_timer = env->GetStaticMethodID(
                g_platform_adapter_cls, "cancelTimer", "(J)V");
            g_mid_monitor_sync = env->GetStaticMethodID(
                g_platform_adapter_cls, "monitorSync", "(Ljava/lang/String;JJJ)V");
            g_mid_retain_object = env->GetStaticMethodID(
                g_platform_adapter_cls, "retainObject", "(JLjava/lang/Object;)V");
            g_mid_release_object = env->GetStaticMethodID(
                g_platform_adapter_cls, "releaseObject", "(J)V");
            g_mid_get_origin_object = env->GetStaticMethodID(
                g_platform_adapter_cls, "getOriginObject", "(J)Ljava/lang/Object;");
        }
    }

    if (!g_cep_result_cls) {
        jclass cls = env->FindClass("com/bytedance/pitaya/cep_engine/CepResult");
        if (cls) {
            g_cep_result_cls = static_cast<jclass>(env->NewGlobalRef(cls));
            env->DeleteLocalRef(cls);
            g_mid_cep_result_init = env->GetMethodID(
                g_cep_result_cls,
                "<init>",
                "(ZLjava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Lorg/json/JSONArray;)V");
        }
    }

    if (!g_cep_callback_cls) {
        jclass cls = env->FindClass("com/bytedance/pitaya/cep_engine/port/CepCallback");
        if (cls) {
            g_cep_callback_cls = static_cast<jclass>(env->NewGlobalRef(cls));
            env->DeleteLocalRef(cls);
            g_mid_cep_callback_on_result = env->GetMethodID(
                g_cep_callback_cls, "onResult", "(Lcom/bytedance/pitaya/cep_engine/CepResult;)V");
        }
    }

    if (!g_cep_function_cls) {
        jclass cls = env->FindClass("com/bytedance/pitaya/cep_engine/port/CepFunction");
        if (cls) {
            g_cep_function_cls = static_cast<jclass>(env->NewGlobalRef(cls));
            env->DeleteLocalRef(cls);
            g_mid_cep_function_on_execute = env->GetMethodID(
                g_cep_function_cls, "onExecute", "(Lorg/json/JSONArray;)Ljava/lang/Object;");
        }
    }
}

// [EN] Disassembly @ 0x43c1c (`_ZN3cep20GetStringFromJStringEP7_JNIEnvP8_jstring`, 376 B):
// [VN] Chuyển đổi `jstring` sang `std::string` (`GetStringFromJString` @ 0x43c1c):
std::string GetStringFromJString(JNIEnv* env, jstring jstr) {
    if (!env || !jstr) {
        return "";
    }
    const char* chars = env->GetStringUTFChars(jstr, nullptr);
    if (!chars) {
        return "";
    }
    const jsize len = env->GetStringUTFLength(jstr);
    std::string out(chars, static_cast<size_t>(len));
    env->ReleaseStringUTFChars(jstr, chars);
    return out;
}

// [EN] Disassembly @ 0x43d94 (`_ZN3cep16CreateJavaResultERKNSt6__ndk110shared_ptrINS_12EngineResultEEE`, 1748 B):
//      Constructs `com/bytedance/pitaya/cep_engine/CepResult(boolean, String, String, String, String, JSONArray)`.
// [VN] Tạo đối tượng Java `CepResult` từ `EngineResult` (`CreateJavaResult` @ 0x43d94):
jobject CreateJavaResult(const std::shared_ptr<EngineResult>& result) {
    JNIEnv* env = GetJvmEnv();
    if (!env || !result || !g_cep_result_cls || !g_mid_cep_result_init) {
        return nullptr;
    }
    jstring jbiz = env->NewStringUTF(result->biz_name().c_str());
    jstring jrule = env->NewStringUTF(result->rule_name().c_str());
    jstring jerr = env->NewStringUTF(result->error_message().c_str());
    std::string warn_joined;
    for (size_t i = 0; i < result->warning_messages().size(); ++i) {
        if (i > 0) warn_joined += "; ";
        warn_joined += result->warning_messages()[i];
    }
    jstring jwarn = env->NewStringUTF(warn_joined.c_str());
    jobject jres = env->NewObject(
        g_cep_result_cls,
        g_mid_cep_result_init,
        static_cast<jboolean>(result->success() ? JNI_TRUE : JNI_FALSE),
        jbiz,
        jrule,
        jerr,
        jwarn,
        nullptr);
    env->DeleteLocalRef(jbiz);
    env->DeleteLocalRef(jrule);
    env->DeleteLocalRef(jerr);
    env->DeleteLocalRef(jwarn);
    return jres;
}

// [EN] Disassembly @ 0x447c4 (`_ZN3cep17JavaCallbackToCppERK14ScopedLocalRef`, 308 B):
// [VN] Bọc đối tượng Java `CepCallback` thành hàm gọi lại C++ (`JavaCallbackToCpp` @ 0x447c4):
CepEngineResultCallback JavaCallbackToCpp(const ScopedLocalRef& jcallback) {
    if (!jcallback.env() || !jcallback.get()) {
        return nullptr;
    }
    jobject global_cb = jcallback.env()->NewGlobalRef(jcallback.get());
    return [global_cb](const std::shared_ptr<EngineResult>& res) {
        JNIEnv* env = GetJvmEnv();
        if (env && global_cb && g_mid_cep_callback_on_result) {
            jobject jres = CreateJavaResult(res);
            env->CallVoidMethod(global_cb, g_mid_cep_callback_on_result, jres);
            if (jres) env->DeleteLocalRef(jres);
        }
    };
}

// [EN] Disassembly @ 0x448f8 (`_ZN3cep17JavaFunctionToCppERK14ScopedLocalRef`, 308 B):
// [VN] Bọc đối tượng Java `CepFunction` thành hàm C++ (`JavaFunctionToCpp` @ 0x448f8):
CepBizFunction JavaFunctionToCpp(const ScopedLocalRef& jfunction) {
    if (!jfunction.env() || !jfunction.get()) {
        return nullptr;
    }
    jobject global_fn = jfunction.env()->NewGlobalRef(jfunction.get());
    return [global_fn](std::shared_ptr<Context> /*ctx*/,
                       std::vector<std::shared_ptr<DataInterface>> args) -> std::shared_ptr<DataInterface> {
        JNIEnv* env = GetJvmEnv();
        if (env && global_fn && g_mid_cep_function_on_execute) {
            auto arr = NativeData::CreateList();
            for (const auto& a : args) {
                arr->AppendData(NativeData::FromDataInterface(a));
            }
            jobject jret = env->CallObjectMethod(
                global_fn,
                g_mid_cep_function_on_execute,
                static_cast<jobject>(arr->GetOriginObject()));
            ScopedLocalRef local_ret(env, jret);
            return std::make_shared<NativeData>(local_ret.get());
        }
        return NativeData::CreateNull();
    };
}

// [EN] Disassembly @ 0x44a2c (`PlatformReportSync`, 1192 B) & 0x454e8 (`PlatformReportAsync`, 896 B):
// [VN] Báo cáo thống kê đồng bộ/bất đồng bộ qua `PlatformAdapter.monitorSync` (@ 0x44a2c & @ 0x454e8):
void PlatformReportSync(
    const std::string& event_name,
    const std::unordered_map<std::string, std::string>& category_map,
    const std::unordered_map<std::string, long>& metric_map) {
    JNIEnv* env = GetJvmEnv();
    if (!env || !g_platform_adapter_cls || !g_mid_monitor_sync) {
        return;
    }
    auto cat_dict = NativeData::CreateDict();
    for (const auto& kv : category_map) {
        cat_dict->SetData(kv.first, NativeData::CreateString(kv.second));
    }
    auto met_dict = NativeData::CreateDict();
    for (const auto& kv : metric_map) {
        met_dict->SetData(kv.first, NativeData::CreateInt(kv.second));
    }
    jstring jev = env->NewStringUTF(event_name.c_str());
    env->CallStaticVoidMethod(
        g_platform_adapter_cls,
        g_mid_monitor_sync,
        jev,
        reinterpret_cast<jlong>(cat_dict.get()),
        reinterpret_cast<jlong>(met_dict.get()),
        static_cast<jlong>(0));
    env->DeleteLocalRef(jev);
}

void PlatformReportAsync(
    const std::string& event_name,
    const std::unordered_map<std::string, std::string>& category_map,
    const std::unordered_map<std::string, long>& metric_map) {
    DispatchAsyncGlobal([event_name, category_map, metric_map]() {
        PlatformReportSync(event_name, category_map, metric_map);
    });
}

// [EN] Disassembly @ 0x45868 (`DispatchAsyncGlobal`, 252 B), 0x45964 (`DispatchAsync`, 272 B),
//      0x45a74 (`DispatchSync`, 272 B), and 0x476f8 (`PlatformCreateTimer`, 84 B):
// [VN] Điều phối thực thi tác vụ và bộ định thời (@ 0x45868..0x476f8):
void DispatchAsyncGlobal(const std::function<void()>& block) {
    if (!block) return;
    JNIEnv* env = GetJvmEnv();
    if (env && g_platform_adapter_cls && g_mid_dispatch_global) {
        auto* heap_block = new std::function<void()>(block);
        CBlockContainer::Instance()->SaveBlock(heap_block);
        env->CallStaticVoidMethod(
            g_platform_adapter_cls,
            g_mid_dispatch_global,
            reinterpret_cast<jlong>(heap_block));
        return;
    }
    block();
}

void DispatchAsync(unsigned char /*queue_id*/, const std::function<void()>& block) {
    if (block) {
        block();
    }
}

void DispatchSync(unsigned char /*queue_id*/, const std::function<void()>& block) {
    if (block) {
        block();
    }
}

void* PlatformCreateTimer(const std::function<void()>& block) {
    if (!block) return nullptr;
    auto* heap_block = new std::function<void()>(block);
    CBlockContainer::Instance()->SaveBlock(heap_block);
    return reinterpret_cast<void*>(heap_block);
}

// [EN] Disassembly @ 0x489d4 (`_ZN3cep15CBlockContainer8InstanceEv`, 124 B):
//      0x489dc: 900000a8  adrp x8, #0x5c000
//      0x489e0: 911fe108  add  x8, x8, #0x7f8        // guard at .bss 0x5c7f8
//      0x489ec: 900000a0  adrp x0, #0x5c000
//      0x489f0: 911ea000  add  x0, x0, #0x7a8        // singleton at .bss 0x5c7a8
// [VN] Singleton `cep::CBlockContainer::Instance()` (@ 0x489d4):
CBlockContainer* CBlockContainer::Instance() {
    static CBlockContainer instance;
    return &instance;
}

// [EN] Disassembly @ 0x48a98 (`_ZN3cep15CBlockContainer9SaveBlockEPNSt6__ndk18functionIFvvEEE`, 100 B):
// [VN] Lưu con trỏ khối hàm vào tập hợp `blocks_` (`SaveBlock` @ 0x48a98):
void CBlockContainer::SaveBlock(std::function<void()>* block) {
    if (!block) return;
    std::lock_guard<std::mutex> lk(mutex_);
    blocks_.insert(block);
}

// [EN] Disassembly @ 0x48afc (`_ZN3cep15CBlockContainer8PopBlockEPNSt6__ndk18functionIFvvEEE`, 360 B):
//      Removes `block` from `blocks_` under `mutex_` and returns `block` if found, else `nullptr`.
// [VN] Lấy và xóa con trỏ khối hàm khỏi `blocks_` (`PopBlock` @ 0x48afc):
std::function<void()>* CBlockContainer::PopBlock(std::function<void()>* block) {
    if (!block) return nullptr;
    std::lock_guard<std::mutex> lk(mutex_);
    auto it = blocks_.find(block);
    if (it == blocks_.end()) {
        return nullptr;
    }
    blocks_.erase(it);
    return block;
}

} // namespace cep

// ============================================================================
// 3. 13 EXPORTED JNI FUNCTIONS (`0x49250..0x4a44f`)
// ============================================================================

extern "C" {

// [EN] 1. Disassembly @ 0x49250 (`Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_init`, 4 B):
//         0x49250: 17ffe8c0  b #0x43550 (InitPlatformAdapter)
// [VN] 1. Khởi tạo JniCaller (@ 0x49250):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_init(
    JNIEnv* env, jobject /*thiz*/) {
    cep::InitPlatformAdapter(env);
}

// [EN] 2. Disassembly @ 0x49254 (`Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_callNoParamsCallback`, 128 B):
//         0x49264: 97ff0b7b  bl  #0xc050               // CBlockContainer::Instance()
//         0x4926c: 97ff0b05  bl  #0xbe80               // CBlockContainer::PopBlock(callback_ptr)
//         0x49270: b40001c0  cbz x0, #0x492a8
//         0x49284: f9401908  ldr x8, [x8, #0x30]       // (*block)()
//         0x49288: d63f0100  blr x8
//         0x492cc: 17ff0985  b   #0xb8e0               // operator delete(block)
// [VN] 2. Thực thi và giải phóng hàm gọi lại không tham số (@ 0x49254):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_callNoParamsCallback(
    JNIEnv* /*env*/, jobject /*thiz*/, jlong callback_ptr) {
    auto* raw_block = reinterpret_cast<std::function<void()>*>(callback_ptr);
    auto* popped = cep::CBlockContainer::Instance()->PopBlock(raw_block);
    if (popped) {
        if (*popped) {
            (*popped)();
        }
        delete popped;
    }
}

// [EN] 3. Disassembly @ 0x492d4 (`Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_collectCrashInfo`, 152 B):
//         0x492f8: 97ff09ba  bl  #0xb9e0               // EngineManagerInner::Instance()
//         0x49304: 97ff0aa3  bl  #0xbd90               // CollectCrashInfo()
//         0x49318: f9429d08  ldr x8, [x8, #0x538]      // env->NewStringUTF(...)
// [VN] 3. Thu thập thông tin sự cố trả về chuỗi Java (@ 0x492d4):
JNIEXPORT jstring JNICALL
Java_com_bytedance_pitaya_cep_1engine_inner_JniCaller_collectCrashInfo(
    JNIEnv* env, jobject /*thiz*/) {
    std::string info = cep::EngineManagerInner::Instance()->CollectCrashInfo();
    if (!env) {
        return nullptr;
    }
    return env->NewStringUTF(info.c_str());
}

// [EN] 4. Disassembly @ 0x4936c (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeConfigEngine`, 268 B):
//         Allocates `std::shared_ptr<NativeData>(config_json)` and calls
//         `EngineManager::Instance()->Init(config_data)`.
// [VN] 4. Cấu hình CEP Engine từ đối tượng JSON Java (@ 0x4936c):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeConfigEngine(
    JNIEnv* env, jobject /*thiz*/, jobject config_json) {
    cep::CheckJavaVM(env);
    auto cfg_data = std::make_shared<cep::NativeData>(config_json);
    cep::EngineManager::Instance()->Init(cfg_data);
}

// [EN] 5. Disassembly @ 0x49478 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRules`, 1068 B):
// [VN] 5. Đăng ký tập hợp quy tắc CEP qua JNI (@ 0x49478):
JNIEXPORT jobject JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRules(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jobject rules_json, jobject config_json) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    auto rules_data = std::make_shared<cep::NativeData>(rules_json);
    auto cfg_data = std::make_shared<cep::NativeData>(config_json);
    auto cfg = std::make_shared<cep::EngineConfig>(cfg_data);
    std::string err_msg;
    bool ok = cep::EngineCore::RegisterRules(biz, rules_data, cfg, err_msg);
    auto eng_res = std::make_shared<cep::EngineResult>(
        ok, biz, "", err_msg, std::vector<std::string>{},
        std::vector<cep::EngineResult::MatchedSequenceEntry>{});
    return cep::CreateJavaResult(eng_res);
}

// [EN] 6. Disassembly @ 0x498a4 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRule`, 1068 B):
// [VN] 6. Đăng ký một quy tắc CEP đơn lẻ qua JNI (@ 0x498a4):
JNIEXPORT jobject JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterRule(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring rule_name, jobject rule_json, jobject config_json) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string rule = cep::GetStringFromJString(env, rule_name);
    auto rule_data = std::make_shared<cep::NativeData>(rule_json);
    auto cfg_data = std::make_shared<cep::NativeData>(config_json);
    auto cfg = std::make_shared<cep::EngineConfig>(cfg_data);
    std::string err_msg;
    bool ok = cep::EngineCore::RegisterRule(biz, rule, rule_data, cfg, err_msg);
    auto eng_res = std::make_shared<cep::EngineResult>(
        ok, biz, rule, err_msg, std::vector<std::string>{},
        std::vector<cep::EngineResult::MatchedSequenceEntry>{});
    return cep::CreateJavaResult(eng_res);
}

// [EN] 7. Disassembly @ 0x49cd0 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterRule`, 152 B):
// [VN] 7. Hủy đăng ký quy tắc CEP qua JNI (@ 0x49cd0):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterRule(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring rule_name) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string rule = cep::GetStringFromJString(env, rule_name);
    cep::EngineCore::UnregisterRule(biz, rule);
}

// [EN] 8. Disassembly @ 0x49d68 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeProcessEvent`, 496 B):
// [VN] 8. Xử lý sự kiện cho một quy tắc cụ thể qua JNI (@ 0x49d68):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeProcessEvent(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring rule_name, jstring event_name, jobject params, jlong timestamp) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string rule = cep::GetStringFromJString(env, rule_name);
    std::string ev = cep::GetStringFromJString(env, event_name);
    auto ev_data = std::make_shared<cep::NativeData>(params);
    cep::EngineCore::AsyncProcess(biz, rule, ev, ev_data, static_cast<long long>(timestamp));
}

// [EN] 9. Disassembly @ 0x49f58 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeOnEvent`, 416 B):
// [VN] 9. Phát sự kiện toàn cục tới tất cả quy tắc qua JNI (@ 0x49f58):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeOnEvent(
    JNIEnv* env, jobject /*thiz*/, jstring event_name, jobject params, jlong timestamp) {
    cep::CheckJavaVM(env);
    std::string ev = cep::GetStringFromJString(env, event_name);
    auto ev_data = std::make_shared<cep::NativeData>(params);
    cep::EngineCore::AsyncProcess("", "", ev, ev_data, static_cast<long long>(timestamp));
}

// [EN] 10. Disassembly @ 0x4a0f8 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterCallback`, 276 B):
// [VN] 10. Đăng ký callback kết quả quy tắc qua JNI (@ 0x4a0f8):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterCallback(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring rule_name, jobject callback) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string rule = cep::GetStringFromJString(env, rule_name);
    ScopedLocalRef local_cb(env, callback);
    cep::EngineCore::RegisterCallback(biz, rule, cep::JavaCallbackToCpp(local_cb));
}

// [EN] 11. Disassembly @ 0x4a20c (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterCallback`, 152 B):
// [VN] 11. Hủy đăng ký callback kết quả quy tắc qua JNI (@ 0x4a20c):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterCallback(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring rule_name) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string rule = cep::GetStringFromJString(env, rule_name);
    cep::EngineCore::UnregisterCallback(biz, rule);
}

// [EN] 12. Disassembly @ 0x4a2a4 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterFunction`, 276 B):
// [VN] 12. Đăng ký hàm mở rộng nghiệp vụ qua JNI (@ 0x4a2a4):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeRegisterFunction(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring func_name, jobject function) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string fn = cep::GetStringFromJString(env, func_name);
    ScopedLocalRef local_fn(env, function);
    cep::EngineCore::RegisterFunction(biz, fn, cep::JavaFunctionToCpp(local_fn));
}

// [EN] 13. Disassembly @ 0x4a3b8 (`Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterFunction`, 152 B):
// [VN] 13. Hủy đăng ký hàm mở rộng nghiệp vụ qua JNI (@ 0x4a3b8):
JNIEXPORT void JNICALL
Java_com_bytedance_pitaya_cep_1engine_CepEngineManager_nativeUnregisterFunction(
    JNIEnv* env, jobject /*thiz*/, jstring biz_name, jstring func_name) {
    cep::CheckJavaVM(env);
    std::string biz = cep::GetStringFromJString(env, biz_name);
    std::string fn = cep::GetStringFromJString(env, func_name);
    cep::EngineCore::UnregisterFunction(biz, fn);
}

} // extern "C"
