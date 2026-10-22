/**
 * @file bh_jni.cpp
 * @brief Dynamic JNI Bridge Implementation for ByteDance ByteHook
 *        Thực thi cầu nối JNI động cho ByteDance ByteHook
 *
 * Reconstructed based on ARM64 disassembly at VAddr 0x00009144 (JNI_OnLoad)
 * and table at VAddr 0x000117a8 (10 JNINativeMethod entries).
 */

#include "bh_jni.h"
#include "bh_core.h"
#include <string.h>

JNIEXPORT jstring JNICALL ByteHook_nativeGetVersion(JNIEnv* env, jclass clazz) {
    (void)clazz;
    return env->NewStringUTF(bytehook_get_version());
}

JNIEXPORT jint JNICALL ByteHook_nativeInit(JNIEnv* env, jclass clazz, jint mode, jboolean debug) {
    (void)env;
    (void)clazz;
    return bytehook_init(mode, debug ? true : false);
}

JNIEXPORT jint JNICALL ByteHook_nativeAddIgnore(JNIEnv* env, jclass clazz, jstring caller_path_name) {
    (void)clazz;
    if (!caller_path_name) return BYTEHOOK_STATUS_ERROR_PARAM;
    const char* path = env->GetStringUTFChars(caller_path_name, NULL);
    int res = bytehook_add_ignore(path);
    env->ReleaseStringUTFChars(caller_path_name, path);
    return res;
}

JNIEXPORT jint JNICALL ByteHook_nativeGetMode(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return bytehook_get_mode();
}

JNIEXPORT jboolean JNICALL ByteHook_nativeGetDebug(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return bytehook_get_debug() ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL ByteHook_nativeSetDebug(JNIEnv* env, jclass clazz, jboolean debug) {
    (void)env;
    (void)clazz;
    bytehook_set_debug(debug ? true : false);
}

JNIEXPORT jboolean JNICALL ByteHook_nativeGetRecordable(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return bytehook_get_recordable() ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT void JNICALL ByteHook_nativeSetRecordable(JNIEnv* env, jclass clazz, jboolean recordable) {
    (void)env;
    (void)clazz;
    bytehook_set_recordable(recordable ? true : false);
}

JNIEXPORT jstring JNICALL ByteHook_nativeGetRecords(JNIEnv* env, jclass clazz, jint item_flags) {
    (void)clazz;
    char* records = bytehook_get_records((uint32_t)item_flags);
    if (!records) {
        return env->NewStringUTF("");
    }
    jstring res = env->NewStringUTF(records);
    free(records);
    return res;
}

JNIEXPORT jstring JNICALL ByteHook_nativeGetArch(JNIEnv* env, jclass clazz) {
    (void)clazz;
#if defined(__aarch64__) || defined(_M_ARM64)
    return env->NewStringUTF("arm64-v8a");
#elif defined(__arm__) || defined(_M_ARM)
    return env->NewStringUTF("armeabi-v7a");
#elif defined(__x86_64__) || defined(_M_X64)
    return env->NewStringUTF("x86_64");
#else
    return env->NewStringUTF("arm64-v8a");
#endif
}

// Dynamic JNI Registration Table matching VAddr 0x000117a8
static const JNINativeMethod g_bytehook_jni_methods[] = {
    {(char*)"nativeGetVersion",    (char*)"()Ljava/lang/String;",      (void*)ByteHook_nativeGetVersion},
    {(char*)"nativeInit",          (char*)"(IZ)I",                     (void*)ByteHook_nativeInit},
    {(char*)"nativeAddIgnore",     (char*)"(Ljava/lang/String;)I",     (void*)ByteHook_nativeAddIgnore},
    {(char*)"nativeGetMode",       (char*)"()I",                       (void*)ByteHook_nativeGetMode},
    {(char*)"nativeGetDebug",      (char*)"()Z",                       (void*)ByteHook_nativeGetDebug},
    {(char*)"nativeSetDebug",      (char*)"(Z)V",                      (void*)ByteHook_nativeSetDebug},
    {(char*)"nativeGetRecordable", (char*)"()Z",                       (void*)ByteHook_nativeGetRecordable},
    {(char*)"nativeSetRecordable", (char*)"(Z)V",                      (void*)ByteHook_nativeSetRecordable},
    {(char*)"nativeGetRecords",    (char*)"(I)Ljava/lang/String;",     (void*)ByteHook_nativeGetRecords},
    {(char*)"nativeGetArch",       (char*)"()Ljava/lang/String;",      (void*)ByteHook_nativeGetArch}
};

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    if (!vm) {
        return JNI_ERR;
    }

    JNIEnv* env = NULL;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK || !env) {
        return JNI_ERR;
    }

    jclass clazz = env->FindClass(BYTEHOOK_JNI_CLASS_NAME);
    if (!clazz) {
        return JNI_ERR;
    }

    jint method_count = (jint)(sizeof(g_bytehook_jni_methods) / sizeof(g_bytehook_jni_methods[0]));
    if (env->RegisterNatives(clazz, g_bytehook_jni_methods, method_count) != 0) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}
