// ============================================================================
// File: cybertron_jni_bridge.cpp
// Target: libcybertron_base.so (509,816 bytes)
// Task ID: TASK-142-RECONSTRUCTION-LIBCYBERTRON-BASE / TASK_SO_105_libcybertron_base
// ============================================================================
// [EN] Clean-room C++17 reconstruction of JNI_OnLoad (0x05da68), JNI_OnUnLoad (0x05da84),
//      datacenter::loadRelativeClasses (0x05dafc), and all 22 exported Java_* JNI bridges
//      (0x05fa98..0x061ad0) for com.ttkmedia.datacenter.*.
// [VN] Tái tạo sạch C++17 của JNI_OnLoad (0x05da68), JNI_OnUnLoad (0x05da84),
//      datacenter::loadRelativeClasses (0x05dafc) và toàn bộ 22 cầu nối JNI Java_*
//      (0x05fa98..0x061ad0) cho com.ttkmedia.datacenter.*.
// ============================================================================

#include "cybertron_datacenter_core.h"

namespace datacenter {

namespace {
JavaVM* g_jvm_080318 = nullptr;       // .bss 0x080318
jclass g_json_object_class_080328 = nullptr; // .bss 0x080328 ("org/json/JSONObject" @ 0x06804c)
jmethodID g_json_init_mid_080330 = nullptr;  // .bss 0x080330 ("<init>", "(Ljava/lang/String;)V" @ 0x068060)
jmethodID g_json_opt_str_mid_080338 = nullptr; // .bss 0x080338 ("optString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;" @ 0x06807d)
} // namespace

// ----------------------------------------------------------------------------
// [EN] datacenter::getJVM() @ 0x05da88 (12 B):
//      0x05da88: F0000108 adrp x8, #0x80000
//      0x05da8c: F9418D00 ldr  x0, [x8, #0x318]
//      0x05da90: D65F03C0 ret
// [VN] datacenter::getJVM() @ 0x05da88 (12 B): đọc con trỏ JavaVM* tại .bss 0x080318.
// ----------------------------------------------------------------------------
JavaVM* getJVM() noexcept {
    return g_jvm_080318;
}

// ----------------------------------------------------------------------------
// [EN] datacenter::getEnv() @ 0x05da94 (104 B):
//      Calls g_jvm_080318->GetEnv(&env, 0x00010006) and returns env.
// [VN] datacenter::getEnv() @ 0x05da94 (104 B): gọi GetEnv(&env, 0x00010006).
// ----------------------------------------------------------------------------
JNIEnv* getEnv() noexcept {
    if (!g_jvm_080318) return nullptr;
    void* env = nullptr;
    if (g_jvm_080318->GetEnv(&env, static_cast<jint>(kCybertronJniVersion16)) != JNI_OK) {
        return nullptr;
    }
    return static_cast<JNIEnv*>(env);
}

// ----------------------------------------------------------------------------
// [EN] datacenter::loadRelativeClasses(JavaVM*) @ 0x05dafc (292 B):
//      Stores vm in .bss 0x080318, verifies GetEnv(0x00010006) == 0 (else returns -1),
//      caches org/json/JSONObject and its <init> & optString method IDs in .bss 0x080328..0x080338,
//      and returns 0x00010006 (JNI_VERSION_1_6).
// [VN] datacenter::loadRelativeClasses(JavaVM*) @ 0x05dafc (292 B).
// ----------------------------------------------------------------------------
jint loadRelativeClasses(JavaVM* vm) noexcept {
    g_jvm_080318 = vm;
    if (!vm) return -1;
    void* raw_env = nullptr;
    if (vm->GetEnv(&raw_env, static_cast<jint>(kCybertronJniVersion16)) != JNI_OK || !raw_env) {
        return -1;
    }
    JNIEnv* env = static_cast<JNIEnv*>(raw_env);
    jclass local_cls = env->FindClass("org/json/JSONObject");
    if (local_cls) {
        g_json_object_class_080328 = static_cast<jclass>(env->NewGlobalRef(local_cls));
        g_json_init_mid_080330 = env->GetMethodID(g_json_object_class_080328, "<init>", "(Ljava/lang/String;)V");
        g_json_opt_str_mid_080338 = env->GetMethodID(
            g_json_object_class_080328,
            "optString",
            "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;");
    }
    return static_cast<jint>(kCybertronJniVersion16);
}

// ----------------------------------------------------------------------------
// [EN] datacenter::jlongFromPointer(void*) @ 0x05ddc0 (4 B):
//      0x05ddc0: D65F03C0 ret
// [VN] datacenter::jlongFromPointer(void*) @ 0x05ddc0 (4 B).
// ----------------------------------------------------------------------------
jlong jlongFromPointer(void* ptr) noexcept {
    return reinterpret_cast<jlong>(ptr);
}

static std::string jstringToStdString(JNIEnv* env, jstring jstr) {
    if (!env || !jstr) return "";
    const char* utf = env->GetStringUTFChars(jstr, nullptr);
    if (!utf) return "";
    std::string out(utf);
    env->ReleaseStringUTFChars(jstr, utf);
    return out;
}

} // namespace datacenter

extern "C" {

// ----------------------------------------------------------------------------
// [EN] JNI_OnLoad @ 0x05da68 (28 B):
//      0x05da68: A9BF7BFD stp   x29, x30, [sp, #-0x10]!
//      0x05da6c: 910003FD mov   x29, sp
//      0x05da70: 97FF7400 bl    #0x3aa70  ; datacenter::loadRelativeClasses(_JavaVM*)
//      0x05da74: 7100001F cmp   w0, #0
//      0x05da78: 5A9FA000 csinv w0, w0, wzr, ge
//      0x05da7c: A8C17BFD ldp   x29, x30, [sp], #0x10
//      0x05da80: D65F03C0 ret
// [VN] JNI_OnLoad @ 0x05da68 (28 B): gọi loadRelativeClasses và trả về status >= 0 ? status : -1.
// ----------------------------------------------------------------------------
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* /*reserved*/) {
    jint status = datacenter::loadRelativeClasses(vm);
    return status >= 0 ? status : ~0;
}

// ----------------------------------------------------------------------------
// [EN] JNI_OnUnLoad @ 0x05da84 (4 B):
//      0x05da84: D65F03C0 ret
// [VN] JNI_OnUnLoad @ 0x05da84 (4 B).
// ----------------------------------------------------------------------------
JNIEXPORT void JNICALL JNI_OnUnLoad(JavaVM* /*vm*/, void* /*reserved*/) {
    return;
}

// ----------------------------------------------------------------------------
// [EN] DataCenter JNI methods (0x060000..0x0605d4).
// [VN] Các phương thức JNI của DataCenter (0x060000..0x0605d4).
// ----------------------------------------------------------------------------
JNIEXPORT jlong JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1create(
    JNIEnv* /*env*/,
    jobject /*thiz*/) {
    // 0x060000: 17FF69C0 b #0x3a700 (datacenter::DataCenter::Create())
    return reinterpret_cast<jlong>(datacenter::DataCenter::Create());
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1setIntValue(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jint value) {
    // 0x060004..0x060020: if (handle != 0) reinterpret_cast<DataCenter*>(handle)->setIntValue(key, value)
    if (handle == 0) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->setIntValue(key, value);
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1setFloatValue(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jfloat value) {
    // 0x060024..0x06003c: vtable[+0x20]
    if (handle == 0) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->setFloatValue(key, value);
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1setLongValue(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jlong value) {
    // 0x060040..0x06005c: vtable[+0x18]
    if (handle == 0) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->setLongValue(key, value);
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1setAppInfo(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong /*handle*/,
    jstring /*app_info*/) {
    // 0x060060: D65F03C0 ret
    return;
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1setStrValue(
    JNIEnv* env,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jstring value) {
    // 0x060064..0x0600eb: vtable[+0x28]
    if (handle == 0 || !value) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->setStrValue(
        key, datacenter::jstringToStdString(env, value));
}

JNIEXPORT jint JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1getIntValue(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jint default_val) {
    // 0x0600ec..0x06010c: if (handle == 0) return default_val; else vtable[+0x30]
    if (handle == 0) return default_val;
    return reinterpret_cast<datacenter::DataCenter*>(handle)->getIntValue(key, default_val);
}

JNIEXPORT jfloat JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1getFloatValue(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jfloat default_val) {
    // 0x060110..0x060128: if (handle == 0) return default_val; else vtable[+0x48]
    if (handle == 0) return default_val;
    return reinterpret_cast<datacenter::DataCenter*>(handle)->getFloatValue(key, default_val);
}

JNIEXPORT jlong JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1getLongValue(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jlong default_val) {
    // 0x06012c..0x06014c: if (handle == 0) return default_val; else vtable[+0x38]
    if (handle == 0) return default_val;
    return reinterpret_cast<datacenter::DataCenter*>(handle)->getLongValue(key, default_val);
}

JNIEXPORT jstring JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1getStrValue(
    JNIEnv* env,
    jobject /*thiz*/,
    jlong handle,
    jint key,
    jstring default_val) {
    // 0x060150..0x060227
    if (handle == 0) return default_val;
    std::string def_str = datacenter::jstringToStdString(env, default_val);
    std::string res = reinterpret_cast<datacenter::DataCenter*>(handle)->getStrValue(key, def_str);
    return env ? env->NewStringUTF(res.c_str()) : nullptr;
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1businessEvent__JII(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint event_id,
    jint value) {
    // 0x060478..0x060494: vtable[+0x68]
    if (handle == 0) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->businessEvent(event_id, value);
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1businessEvent__JILjava_lang_String_2(
    JNIEnv* env,
    jobject /*thiz*/,
    jlong handle,
    jint event_id,
    jstring msg) {
    // 0x060498..0x06051f
    if (handle == 0 || !msg) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->businessEventStr(
        event_id, datacenter::jstringToStdString(env, msg));
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1businessEvent__JIII(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle,
    jint sub_type,
    jint event_id,
    jint value) {
    // 0x060520..0x060540: vtable[+0x80]
    if (handle == 0) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->businessEventSub(sub_type, event_id, value);
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_api_DataCenter__1businessEvent__JIILjava_lang_String_2(
    JNIEnv* env,
    jobject /*thiz*/,
    jlong handle,
    jint sub_type,
    jint event_id,
    jstring msg) {
    // 0x060544..0x0605d3
    if (handle == 0 || !msg) return;
    reinterpret_cast<datacenter::DataCenter*>(handle)->businessEventSubStr(
        sub_type, event_id, datacenter::jstringToStdString(env, msg));
}

JNIEXPORT jboolean JNICALL Java_com_ttkmedia_datacenter_algo_AlgTaskManager__1isReady(
    JNIEnv* /*env*/,
    jobject /*thiz*/) {
    // 0x0605d8..0x0605f0: calls AlgTaskRunnerImpl::instance().isReady() & 1
    return datacenter::clientai::AlgTaskRunnerImpl::instance().isReady() ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL Java_com_ttkmedia_datacenter_common_NativeObject_nativeRelease(
    JNIEnv* /*env*/,
    jobject /*thiz*/,
    jlong handle) {
    // 0x061ad0..0x061ae4:
    //   0x061ad0: B40000A2 cbz x2, #0x61ae4
    //   0x061ad4: F9400048 ldr x8, [x2]
    //   0x061ad8: AA0203E0 mov x0, x2
    //   0x061adc: F9400101 ldr x1, [x8]
    //   0x061ae0: D61F0020 br  x1
    //   0x061ae4: D65F03C0 ret
    if (handle == 0) return;
    delete reinterpret_cast<datacenter::DCObject*>(handle);
}

} // extern "C"
