// ============================================================================
// File: bdhm_native_interface.cpp
// Module: libbdhm_native.so — JNI Glue & 27 Exported Functions Implementation
//         (Triển khai Lớp Keo JNI & 27 Hàm Xuất khẩu .dynsym của libbdhm_native.so)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from bdhm_native/src/api/glue.rs (.text 0x03e820..0x046c18,
//               .rodata 0x00c360..0x00d515, .bss 0x09e0c0..0x09ead8)
// ============================================================================

#include "bdhm_native_interface.h"
#include <atomic>
#include <mutex>
#include <string>
#include <vector>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

// ============================================================================
// [EN] 1. Global JNI Reflection Cache in .bss (0x09e0c0..0x09ead8)
//      Initialized in JNI_OnLoad (0x045e44..0x04698c) and released in
//      JNI_OnUnload (0x046990..0x046c18).
//      Stores global references for:
//        - java/lang/Exception
//        - com/bytedance/android/monitorV2/spark_tracing/gen/SparkTracingNative
//          (static/instance field "mNativeObj" sig "J")
//        - java/lang/String
//        - java/lang/Long    (longValue()J, valueOf(J)Ljava/lang/Long;)
//        - java/lang/Byte    (byteValue()B, valueOf(B)Ljava/lang/Byte;)
//        - java/lang/Boolean (booleanValue()Z, valueOf(Z)Ljava/lang/Boolean;)
//        - java/lang/Double  (doubleValue()D, valueOf(D)Ljava/lang/Double;)
//        - java/lang/Float   (floatValue()F, valueOf(F)Ljava/lang/Float;)
//        - java/lang/Integer (intValue()I, valueOf(I)Ljava/lang/Integer;)
//        - java/lang/Short   (shortValue()S, valueOf(S)Ljava/lang/Short;)
// [VN] 1. Bộ đệm Phản chiếu JNI Toàn cục trong .bss (0x09e0c0..0x09ead8)
// ============================================================================
struct GlobalJniReflectionCache {
    JavaVM*   java_vm                = nullptr;
    jclass    cls_exception          = nullptr;
    jclass    cls_spark_tracing      = nullptr;
    jfieldID  fid_native_obj         = nullptr;
    jclass    cls_string             = nullptr;

    jclass    cls_long               = nullptr;
    jmethodID mid_long_val           = nullptr;
    jmethodID mid_long_value_of      = nullptr;

    jclass    cls_byte               = nullptr;
    jmethodID mid_byte_val           = nullptr;
    jmethodID mid_byte_value_of      = nullptr;

    jclass    cls_boolean            = nullptr;
    jmethodID mid_boolean_val        = nullptr;
    jmethodID mid_boolean_value_of   = nullptr;

    jclass    cls_double             = nullptr;
    jmethodID mid_double_val         = nullptr;
    jmethodID mid_double_value_of    = nullptr;

    jclass    cls_float              = nullptr;
    jmethodID mid_float_val          = nullptr;
    jmethodID mid_float_value_of     = nullptr;

    jclass    cls_integer            = nullptr;
    jmethodID mid_integer_val        = nullptr;
    jmethodID mid_integer_value_of   = nullptr;

    jclass    cls_short              = nullptr;
    jmethodID mid_short_val          = nullptr;
    jmethodID mid_short_value_of     = nullptr;
};

static GlobalJniReflectionCache g_jni_cache;
static std::mutex               g_jni_cache_mutex;

// ============================================================================
// [EN] 2. RAII JniEnvHolder (bdhm_native/src/api/glue.rs, .rodata 0x00c360)
//      Attaches current thread if needed and detaches on scope exit.
// [VN] 2. Bộ giữ JniEnvHolder theo cơ chế RAII (bdhm_native/src/api/glue.rs)
// ============================================================================
class JniEnvHolder {
public:
    explicit JniEnvHolder(JavaVM* vm) : vm_(vm), env_(nullptr), attached_(false) {
        if (!vm_) {
            return;
        }
        jint rc = vm_->GetEnv(reinterpret_cast<void**>(&env_), JNI_VERSION_1_6);
        if (rc == JNI_EDETACHED) {
            if (vm_->AttachCurrentThread(&env_, nullptr) == JNI_OK) {
                attached_ = true;
            }
        }
    }

    ~JniEnvHolder() {
        if (attached_ && vm_) {
            vm_->DetachCurrentThread();
        }
    }

    JNIEnv* get() const { return env_; }

private:
    JavaVM* vm_;
    JNIEnv* env_;
    bool    attached_;
};

// ============================================================================
// [EN] 3. JNI String & Boxed Object Conversion Helpers (0x03e338 / 0x03e540)
// [VN] 3. Hàm Hỗ trợ Chuyển đổi Chuỗi JNI & Đối tượng Đóng hộp (0x03e338 / 0x03e540)
// ============================================================================
static std::string JStringToStdString(JNIEnv* env, jstring jstr) {
    if (!env || !jstr) {
        return "";
    }
    const char* chars = env->GetStringUTFChars(jstr, nullptr);
    if (!chars) {
        return "";
    }
    std::string result(chars);
    env->ReleaseStringUTFChars(jstr, chars);
    return result;
}

static PropValue JObjectToPropValue(JNIEnv* env, jobject obj) {
    // [EN] Reconstructed from 0x03e540..0x03e818 (inspects boxed Java types)
    // [VN] Tái dựng từ 0x03e540..0x03e818 (kiểm tra kiểu đóng hộp Java)
    if (!env || !obj) {
        return PropValue::MakeNull();
    }
    if (g_jni_cache.cls_string && env->IsInstanceOf(obj, g_jni_cache.cls_string)) {
        return PropValue::MakeString(JStringToStdString(env, static_cast<jstring>(obj)));
    }
    if (g_jni_cache.cls_boolean && g_jni_cache.mid_boolean_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_boolean)) {
        jboolean b = env->CallBooleanMethod(obj, g_jni_cache.mid_boolean_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeBool(b == JNI_TRUE);
    }
    if (g_jni_cache.cls_long && g_jni_cache.mid_long_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_long)) {
        jlong v = env->CallLongMethod(obj, g_jni_cache.mid_long_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeNumber(static_cast<double>(v));
    }
    if (g_jni_cache.cls_integer && g_jni_cache.mid_integer_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_integer)) {
        jint v = env->CallIntMethod(obj, g_jni_cache.mid_integer_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeNumber(static_cast<double>(v));
    }
    if (g_jni_cache.cls_double && g_jni_cache.mid_double_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_double)) {
        jdouble v = env->CallDoubleMethod(obj, g_jni_cache.mid_double_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeNumber(static_cast<double>(v));
    }
    if (g_jni_cache.cls_float && g_jni_cache.mid_float_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_float)) {
        jfloat v = env->CallFloatMethod(obj, g_jni_cache.mid_float_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeNumber(static_cast<double>(v));
    }
    if (g_jni_cache.cls_short && g_jni_cache.mid_short_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_short)) {
        jshort v = env->CallShortMethod(obj, g_jni_cache.mid_short_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeNumber(static_cast<double>(v));
    }
    if (g_jni_cache.cls_byte && g_jni_cache.mid_byte_val &&
        env->IsInstanceOf(obj, g_jni_cache.cls_byte)) {
        jbyte v = env->CallByteMethod(obj, g_jni_cache.mid_byte_val);
        if (env->ExceptionCheck()) env->ExceptionClear();
        return PropValue::MakeNumber(static_cast<double>(v));
    }
    return PropValue::MakeNull();
}

// ============================================================================
// [EN] 4. JavaCallback Client Bridge (bdhm_native/src/api/glue.rs, 0x00cbbe..0x00cc87)
//      Dispatches OnEvent("(ILjava/lang/String;Ljava/lang/String;)V") and
//      OnPropertyChanged("(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V")
//      to SparkTracingNativeClient.
// [VN] 4. Cầu nối JavaCallback Client (bdhm_native/src/api/glue.rs, 0x00cbbe..0x00cc87)
// ============================================================================
class JniSparkTracingClientBridge : public ISparkTracingNativeClient {
public:
    JniSparkTracingClientBridge(JavaVM* vm, jobject global_client, jmethodID mid_on_event, jmethodID mid_on_prop)
        : vm_(vm),
          global_client_(global_client),
          mid_on_event_(mid_on_event),
          mid_on_prop_(mid_on_prop) {}

    ~JniSparkTracingClientBridge() override {
        if (vm_ && global_client_) {
            JniEnvHolder holder(vm_);
            if (JNIEnv* env = holder.get()) {
                env->DeleteGlobalRef(global_client_);
            }
        }
    }

    void OnEvent(int32_t level, const std::string& event_name, const std::string& payload_json) override {
        if (!vm_ || !global_client_ || !mid_on_event_) {
            return;
        }
        JniEnvHolder holder(vm_);
        JNIEnv* env = holder.get();
        if (!env) {
            return;
        }
        jstring j_event   = env->NewStringUTF(event_name.c_str());
        jstring j_payload = env->NewStringUTF(payload_json.c_str());
        env->CallVoidMethod(global_client_, mid_on_event_, static_cast<jint>(level), j_event, j_payload);
        if (env->ExceptionCheck()) {
            env->ExceptionClear(); // .rodata 0x00c534: "on_event: java throw exception"
        }
        if (j_event)   env->DeleteLocalRef(j_event);
        if (j_payload) env->DeleteLocalRef(j_payload);
    }

    void OnPropertyChanged(const std::string& context_id, const std::string& key, const std::string& val) override {
        if (!vm_ || !global_client_ || !mid_on_prop_) {
            return;
        }
        JniEnvHolder holder(vm_);
        JNIEnv* env = holder.get();
        if (!env) {
            return;
        }
        jstring j_id  = env->NewStringUTF(context_id.c_str());
        jstring j_key = env->NewStringUTF(key.c_str());
        jstring j_val = env->NewStringUTF(val.c_str());
        env->CallVoidMethod(global_client_, mid_on_prop_, j_id, j_key, j_val);
        if (env->ExceptionCheck()) {
            env->ExceptionClear(); // .rodata 0x00c553: "on_property_changed: java throw exception"
        }
        if (j_id)  env->DeleteLocalRef(j_id);
        if (j_key) env->DeleteLocalRef(j_key);
        if (j_val) env->DeleteLocalRef(j_val);
    }

private:
    JavaVM*   vm_;
    jobject   global_client_;
    jmethodID mid_on_event_;
    jmethodID mid_on_prop_;
};

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI

using namespace NextAI::OpenCut::BdhmNative;

extern "C" {

// ============================================================================
// [EN] 5. JNI_OnLoad (0x045e44..0x04698c, size: 2,892 B) &
//         JNI_OnUnload (0x046990..0x046c18, size: 648 B)
// [VN] 5. Triển khai JNI_OnLoad (0x045e44) & JNI_OnUnload (0x046990)
// ============================================================================
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    if (!vm) {
        return JNI_ERR;
    }
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK || !env) {
        return JNI_ERR;
    }

    std::lock_guard<std::mutex> lock(g_jni_cache_mutex);
    g_jni_cache.java_vm = vm;

    auto cache_class = [env](const char* name) -> jclass {
        jclass local = env->FindClass(name);
        if (!local) {
            if (env->ExceptionCheck()) env->ExceptionClear();
            return nullptr;
        }
        jclass global = static_cast<jclass>(env->NewGlobalRef(local));
        env->DeleteLocalRef(local);
        return global;
    };

    g_jni_cache.cls_exception     = cache_class("java/lang/Exception");
    g_jni_cache.cls_spark_tracing = cache_class("com/bytedance/android/monitorV2/spark_tracing/gen/SparkTracingNative");
    if (g_jni_cache.cls_spark_tracing) {
        g_jni_cache.fid_native_obj = env->GetStaticFieldID(g_jni_cache.cls_spark_tracing, "mNativeObj", "J");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_string  = cache_class("java/lang/String");
    g_jni_cache.cls_long    = cache_class("java/lang/Long");
    if (g_jni_cache.cls_long) {
        g_jni_cache.mid_long_val      = env->GetMethodID(g_jni_cache.cls_long, "longValue", "()J");
        g_jni_cache.mid_long_value_of = env->GetStaticMethodID(g_jni_cache.cls_long, "valueOf", "(J)Ljava/lang/Long;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_byte    = cache_class("java/lang/Byte");
    if (g_jni_cache.cls_byte) {
        g_jni_cache.mid_byte_val      = env->GetMethodID(g_jni_cache.cls_byte, "byteValue", "()B");
        g_jni_cache.mid_byte_value_of = env->GetStaticMethodID(g_jni_cache.cls_byte, "valueOf", "(B)Ljava/lang/Byte;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_boolean = cache_class("java/lang/Boolean");
    if (g_jni_cache.cls_boolean) {
        g_jni_cache.mid_boolean_val      = env->GetMethodID(g_jni_cache.cls_boolean, "booleanValue", "()Z");
        g_jni_cache.mid_boolean_value_of = env->GetStaticMethodID(g_jni_cache.cls_boolean, "valueOf", "(Z)Ljava/lang/Boolean;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_double  = cache_class("java/lang/Double");
    if (g_jni_cache.cls_double) {
        g_jni_cache.mid_double_val      = env->GetMethodID(g_jni_cache.cls_double, "doubleValue", "()D");
        g_jni_cache.mid_double_value_of = env->GetStaticMethodID(g_jni_cache.cls_double, "valueOf", "(D)Ljava/lang/Double;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_float   = cache_class("java/lang/Float");
    if (g_jni_cache.cls_float) {
        g_jni_cache.mid_float_val      = env->GetMethodID(g_jni_cache.cls_float, "floatValue", "()F");
        g_jni_cache.mid_float_value_of = env->GetStaticMethodID(g_jni_cache.cls_float, "valueOf", "(F)Ljava/lang/Float;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_integer = cache_class("java/lang/Integer");
    if (g_jni_cache.cls_integer) {
        g_jni_cache.mid_integer_val      = env->GetMethodID(g_jni_cache.cls_integer, "intValue", "()I");
        g_jni_cache.mid_integer_value_of = env->GetStaticMethodID(g_jni_cache.cls_integer, "valueOf", "(I)Ljava/lang/Integer;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }
    g_jni_cache.cls_short   = cache_class("java/lang/Short");
    if (g_jni_cache.cls_short) {
        g_jni_cache.mid_short_val      = env->GetMethodID(g_jni_cache.cls_short, "shortValue", "()S");
        g_jni_cache.mid_short_value_of = env->GetStaticMethodID(g_jni_cache.cls_short, "valueOf", "(S)Ljava/lang/Short;");
        if (env->ExceptionCheck()) env->ExceptionClear();
    }

    return JNI_VERSION_1_6;
}

JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* /*reserved*/) {
    if (!vm) {
        return;
    }
    JNIEnv* env = nullptr;
    if (vm->GetEnv(reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK || !env) {
        return;
    }

    std::lock_guard<std::mutex> lock(g_jni_cache_mutex);
    auto release_cls = [env](jclass& cls) {
        if (cls) {
            env->DeleteGlobalRef(cls);
            cls = nullptr;
        }
    };
    release_cls(g_jni_cache.cls_exception);
    release_cls(g_jni_cache.cls_spark_tracing);
    release_cls(g_jni_cache.cls_string);
    release_cls(g_jni_cache.cls_long);
    release_cls(g_jni_cache.cls_byte);
    release_cls(g_jni_cache.cls_boolean);
    release_cls(g_jni_cache.cls_double);
    release_cls(g_jni_cache.cls_float);
    release_cls(g_jni_cache.cls_integer);
    release_cls(g_jni_cache.cls_short);
    g_jni_cache.java_vm = nullptr;
}

// ============================================================================
// [EN] 6. JNIReachabilityFence_reachabilityFence1..8 (0x03e820..0x03e83c)
//      Each function is a 4-byte `ret` (0xc0035fd6) in AArch64 .text.
// [VN] 6. Các hàm JNIReachabilityFence_reachabilityFence1..8 (0x03e820..0x03e83c)
// ============================================================================
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence1(
    JNIEnv*, jclass, jobject ref1) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence2(
    JNIEnv*, jclass, jobject ref1, jobject ref2) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence3(
    JNIEnv*, jclass, jobject ref1, jobject ref2, jobject ref3) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2; (void)ref3;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence4(
    JNIEnv*, jclass, jobject ref1, jobject ref2, jobject ref3, jobject ref4) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2; (void)ref3; (void)ref4;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence5(
    JNIEnv*, jclass, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2; (void)ref3; (void)ref4; (void)ref5;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence6(
    JNIEnv*, jclass, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5, jobject ref6) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2; (void)ref3; (void)ref4; (void)ref5; (void)ref6;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence7(
    JNIEnv*, jclass, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5, jobject ref6, jobject ref7) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2; (void)ref3; (void)ref4; (void)ref5; (void)ref6; (void)ref7;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence8(
    JNIEnv*, jclass, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5, jobject ref6, jobject ref7, jobject ref8) {
    std::atomic_signal_fence(std::memory_order_seq_cst);
    (void)ref1; (void)ref2; (void)ref3; (void)ref4; (void)ref5; (void)ref6; (void)ref7; (void)ref8;
}

// ============================================================================
// [EN] 7. SparkTracingNative Exported JNI Functions (0x03eae0..0x045d10)
// [VN] 7. 17 Hàm JNI Xuất khẩu của SparkTracingNative (0x03eae0..0x045d10)
// ============================================================================
JNIEXPORT jlong JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_init(
    JNIEnv* env, jclass /*clazz*/, jobject config_obj, jobject client_obj
) {
    // [EN] Reconstructed from 0x03eae0..0x04140c (10,544 bytes):
    //      Queries SparkTracingNativeConfig methods and constructs SparkTracingNativeEngine.
    // [VN] Tái dựng từ 0x03eae0..0x04140c (10.544 byte)
    SparkTracingConfigData cfg;
    if (env && config_obj) {
        jclass cfg_cls = env->GetObjectClass(config_obj);
        if (cfg_cls) {
            auto call_bool = [&](const char* name) -> bool {
                jmethodID mid = env->GetMethodID(cfg_cls, name, "()Z");
                if (!mid) { if (env->ExceptionCheck()) env->ExceptionClear(); return false; }
                jboolean b = env->CallBooleanMethod(config_obj, mid);
                if (env->ExceptionCheck()) { env->ExceptionClear(); return false; }
                return b == JNI_TRUE;
            };
            auto call_str = [&](const char* name) -> std::string {
                jmethodID mid = env->GetMethodID(cfg_cls, name, "()Ljava/lang/String;");
                if (!mid) { if (env->ExceptionCheck()) env->ExceptionClear(); return ""; }
                jstring s = static_cast<jstring>(env->CallObjectMethod(config_obj, mid));
                if (env->ExceptionCheck()) { env->ExceptionClear(); return ""; }
                std::string res = JStringToStdString(env, s);
                if (s) env->DeleteLocalRef(s);
                return res;
            };
            auto call_long = [&](const char* name, int64_t def_val) -> int64_t {
                jmethodID mid = env->GetMethodID(cfg_cls, name, "()J");
                if (!mid) { if (env->ExceptionCheck()) env->ExceptionClear(); return def_val; }
                jlong v = env->CallLongMethod(config_obj, mid);
                if (env->ExceptionCheck()) { env->ExceptionClear(); return def_val; }
                return static_cast<int64_t>(v);
            };

            cfg.is_log_enable                = call_bool("isLogEnable");
            cfg.is_record_used_property_only = call_bool("isRecordUsedPropertyOnly");
            cfg.is_reference_mapping_enabled = call_bool("isReferenceMappingEnabled");
            cfg.manifest_src                 = call_str("getManifestSrc");
            cfg.reference_map_src            = call_str("getReferenceMapSrc");
            cfg.repo_db_storage_path         = call_str("getRepoDbStoragePath");
            int64_t rsize = call_long("getRepoSize", static_cast<int64_t>(kDefaultMaxContextPropsCount));
            cfg.repo_size = (rsize > 0) ? static_cast<uint32_t>(rsize) : static_cast<uint32_t>(kDefaultMaxContextPropsCount);
            int64_t pulse = call_long("getPulseInterval", static_cast<int64_t>(kDefaultPulseIntervalMillis));
            cfg.pulse_interval_ms = (pulse > 0) ? static_cast<uint64_t>(pulse) : kDefaultPulseIntervalMillis;
            env->DeleteLocalRef(cfg_cls);
        }
    }

    std::shared_ptr<ISparkTracingNativeClient> client_bridge;
    if (env && client_obj && g_jni_cache.java_vm) {
        jclass cli_cls = env->GetObjectClass(client_obj);
        if (cli_cls) {
            jmethodID mid_event = env->GetMethodID(cli_cls, "onEvent", "(ILjava/lang/String;Ljava/lang/String;)V");
            if (env->ExceptionCheck()) env->ExceptionClear();
            jmethodID mid_prop  = env->GetMethodID(cli_cls, "onPropertyChanged", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;)V");
            if (env->ExceptionCheck()) env->ExceptionClear();
            jobject global_cli  = env->NewGlobalRef(client_obj);
            client_bridge = std::make_shared<JniSparkTracingClientBridge>(
                g_jni_cache.java_vm, global_cli, mid_event, mid_prop
            );
            env->DeleteLocalRef(cli_cls);
        }
    }

    auto* engine = new SparkTracingNativeEngine(cfg, std::move(client_bridge));
    jlong handle = reinterpret_cast<jlong>(engine);
    if (env && g_jni_cache.cls_spark_tracing && g_jni_cache.fid_native_obj) {
        env->SetStaticLongField(g_jni_cache.cls_spark_tracing, g_jni_cache.fid_native_obj, handle);
    }
    return handle;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_initLogger(
    JNIEnv* /*env*/, jclass /*clazz*/, jboolean enable_log
) {
    // [EN] 0x041410: tst w2, #0xff; cset w0, ne; b #0x4b550
    // [VN] 0x041410: khởi tạo android_logger
    SparkTracingNativeEngine::InitLogger(enable_log != JNI_FALSE);
}

JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1snapshot(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr
) {
    // [EN] 0x04141c: returns {"MANIFEST":...,"REPOSITORY":...}
    // [VN] 0x04141c: trả về chuỗi JSON chụp nhanh trạng thái
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!env || !engine) {
        return env ? env->NewStringUTF("{}") : nullptr;
    }
    std::string snap = engine->DoSnapshot();
    return env->NewStringUTF(snap.c_str());
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setManifest(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring manifest_json
) {
    // [EN] 0x0429a0: parses and updates active DeclaredManifest
    // [VN] 0x0429a0: phân tích và cập nhật DeclaredManifest
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    engine->DoSetManifest(JStringToStdString(env, manifest_json));
}

JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1getProperties(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id
) {
    // [EN] 0x042a40: returns merged context properties JSON
    // [VN] 0x042a40: trả về JSON thuộc tính hợp nhất của ngữ cảnh
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!env || !engine) {
        return env ? env->NewStringUTF("{}") : nullptr;
    }
    std::string res = engine->DoGetProperties(JStringToStdString(env, context_id));
    return env->NewStringUTF(res.c_str());
}

JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1getProperty(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jstring key, jboolean recursive
) {
    // [EN] 0x042bd4: looks up a single property key
    // [VN] 0x042bd4: truy vấn giá trị một thuộc tính theo khóa
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!env || !engine) {
        return nullptr;
    }
    std::string res = engine->DoGetProperty(
        JStringToStdString(env, context_id),
        JStringToStdString(env, key),
        recursive != JNI_FALSE
    );
    return res.empty() ? nullptr : env->NewStringUTF(res.c_str());
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setProperty(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jstring key, jobject val_obj, jlong life_millis, jlong now_millis
) {
    // [EN] 0x042cb4: unboxes val_obj and stores property in ContextPropsRepo
    // [VN] 0x042cb4: giải đóng hộp val_obj và lưu thuộc tính vào ContextPropsRepo
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    PropValue pv = JObjectToPropValue(env, val_obj);
    engine->DoSetProperty(
        JStringToStdString(env, context_id),
        JStringToStdString(env, key),
        pv,
        static_cast<int64_t>(life_millis),
        static_cast<int64_t>(now_millis)
    );
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setProperties(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jstring props_json, jlong life_millis, jlong now_millis
) {
    // [EN] 0x042df0: parses JSON batch of properties and stores in ContextPropsRepo
    // [VN] 0x042df0: phân tích lô thuộc tính JSON và lưu vào ContextPropsRepo
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    engine->DoSetProperties(
        JStringToStdString(env, context_id),
        JStringToStdString(env, props_json),
        static_cast<int64_t>(life_millis),
        static_cast<int64_t>(now_millis)
    );
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1newContextProps(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jlong life_millis, jboolean is_static, jboolean is_leaf
) {
    // [EN] 0x0430b0: creates new ContextInstance node
    // [VN] 0x0430b0: khởi tạo nút ContextInstance mới
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    engine->DoNewContextProps(
        JStringToStdString(env, context_id),
        life_millis > 0 ? static_cast<uint64_t>(life_millis) : kDefaultLifeMillis,
        is_static != JNI_FALSE,
        is_leaf != JNI_FALSE
    );
}

JNIEXPORT jboolean JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1isContextPropsExists(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id
) {
    // [EN] 0x043318: returns JNI_TRUE if context_id exists in repo
    // [VN] 0x043318: trả về JNI_TRUE nếu context_id tồn tại trong kho
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return JNI_FALSE;
    }
    bool exists = engine->DoIsContextPropsExists(JStringToStdString(env, context_id));
    return exists ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setContextPropsAliveState(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jboolean is_alive
) {
    // [EN] 0x04337c: sets alive flag on context_id
    // [VN] 0x04337c: đặt cờ trạng thái sống cho context_id
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    engine->DoSetContextPropsAliveState(JStringToStdString(env, context_id), is_alive != JNI_FALSE);
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1updateLink(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring child_id, jstring parent_id, jint op
) {
    // [EN] 0x0434a8: adds (op=0) or removes (op=1) parent link with cycle check
    // [VN] 0x0434a8: thêm (op=0) hoặc xóa (op=1) liên kết cha-con kèm kiểm tra chu trình
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    LinkUpdateOp link_op = (op == 1) ? LinkUpdateOp::kRemoveParent : LinkUpdateOp::kAddParent;
    engine->DoUpdateLink(
        JStringToStdString(env, child_id),
        JStringToStdString(env, parent_id),
        link_op
    );
}

JNIEXPORT jobjectArray JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1getChildIds(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring parent_id
) {
    // [EN] 0x043a6c: returns String[] of direct child context IDs
    // [VN] 0x043a6c: trả về mảng String[] chứa các ID ngữ cảnh con trực tiếp
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!env || !engine) {
        return nullptr;
    }
    std::vector<std::string> children = engine->DoGetChildIds(JStringToStdString(env, parent_id));
    jclass str_cls = g_jni_cache.cls_string ? g_jni_cache.cls_string : env->FindClass("java/lang/String");
    if (!str_cls) {
        return nullptr;
    }
    jobjectArray arr = env->NewObjectArray(static_cast<jsize>(children.size()), str_cls, nullptr);
    if (!arr) {
        return nullptr;
    }
    for (size_t i = 0; i < children.size(); ++i) {
        jstring j_child = env->NewStringUTF(children[i].c_str());
        env->SetObjectArrayElement(arr, static_cast<jsize>(i), j_child);
        if (j_child) env->DeleteLocalRef(j_child);
    }
    return arr;
}

JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1computeExpr(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jstring expr_str
) {
    // [EN] 0x043dd4: evaluates arithmetic/property clause expression in context_id
    // [VN] 0x043dd4: tính giá trị biểu thức toán học/thuộc tính trên ngữ cảnh context_id
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!env || !engine) {
        return nullptr;
    }
    std::string res = engine->DoComputeExpr(
        JStringToStdString(env, context_id),
        JStringToStdString(env, expr_str)
    );
    return env->NewStringUTF(res.c_str());
}

JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1compute(
    JNIEnv* env, jclass /*clazz*/, jlong native_ptr, jstring context_id, jstring event_or_manifest_json
) {
    // [EN] 0x043f78: computes event properties and triggers client callback
    // [VN] 0x043f78: tính toán thuộc tính sự kiện và kích hoạt callback
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!env || !engine) {
        return nullptr;
    }
    std::string res = engine->DoCompute(
        JStringToStdString(env, context_id),
        JStringToStdString(env, event_or_manifest_json)
    );
    return env->NewStringUTF(res.c_str());
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1update(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong native_ptr
) {
    // [EN] 0x044274: runs periodic event processing and TTL garbage collection
    // [VN] 0x044274: chạy xử lý sự kiện định kỳ và thu gom rác theo TTL
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    if (!engine) {
        return;
    }
    engine->DoUpdate();
}

JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1delete(
    JNIEnv* /*env*/, jclass /*clazz*/, jlong native_ptr
) {
    // [EN] 0x045d10: drops Box<SparkTracingNative> (client, manifest Arc, repo Arc)
    // [VN] 0x045d10: giải phóng đối tượng SparkTracingNative
    auto* engine = reinterpret_cast<SparkTracingNativeEngine*>(native_ptr);
    delete engine;
}

} // extern "C"
