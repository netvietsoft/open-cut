/**
 * @file sh_jni.cpp
 * @brief Dynamic JNI Registration and Java Native Interface Implementation
 *        Triển khai đăng ký JNI động và cầu nối giao tiếp Java Native
 *
 * Cleanroom implementation reconstructed from ByteDance libshadowhook.so (AArch64).
 * Tái cấu trúc phòng sạch từ libshadowhook.so (AArch64) của ByteDance.
 */

#include "sh_jni.h"
#include "sh_core.h"
#include <string.h>
#include <stdlib.h>

// JNI Registration Table / Bảng đăng ký phương thức native cho JNI
static const JNINativeMethod g_sh_jni_methods[] = {
    {"nativeGetVersion", "()Ljava/lang/String;", (void*)sh_jni_nativeGetVersion},
    {"nativeInit", "(IZ)I", (void*)sh_jni_nativeInit},
    {"nativeGetInitErrno", "()I", (void*)sh_jni_nativeGetInitErrno},
    {"nativeGetMode", "()I", (void*)sh_jni_nativeGetMode},
    {"nativeGetDebuggable", "()Z", (void*)sh_jni_nativeGetDebuggable},
    {"nativeSetDebuggable", "(Z)V", (void*)sh_jni_nativeSetDebuggable},
    {"nativeGetRecordable", "()Z", (void*)sh_jni_nativeGetRecordable},
    {"nativeSetRecordable", "(Z)V", (void*)sh_jni_nativeSetRecordable},
    {"nativeGetDisable", "()Z", (void*)sh_jni_nativeGetDisable},
    {"nativeSetDisable", "(Z)V", (void*)sh_jni_nativeSetDisable},
    {"nativeToErrmsg", "(I)Ljava/lang/String;", (void*)sh_jni_nativeToErrmsg},
    {"nativeGetRecords", "(I)Ljava/lang/String;", (void*)sh_jni_nativeGetRecords},
    {"nativeGetArch", "()Ljava/lang/String;", (void*)sh_jni_nativeGetArch}
};

jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    (void)reserved;
    JNIEnv* env = NULL;
    if (vm->GetEnv((void**)&env, JNI_VERSION_1_6) != JNI_OK) {
        return JNI_ERR;
    }

    jclass clazz = env->FindClass(SH_JNI_CLASS_NAME);
    if (!clazz) {
        return JNI_ERR;
    }

    size_t method_count = sizeof(g_sh_jni_methods) / sizeof(g_sh_jni_methods[0]);
    if (env->RegisterNatives(clazz, g_sh_jni_methods, (jint)method_count) < 0) {
        return JNI_ERR;
    }

    return JNI_VERSION_1_6;
}

jstring JNICALL sh_jni_nativeGetVersion(JNIEnv* env, jclass clazz) {
    (void)clazz;
    return env->NewStringUTF(shadowhook_get_version());
}

jint JNICALL sh_jni_nativeInit(JNIEnv* env, jclass clazz, jint mode, jboolean debuggable) {
    (void)env;
    (void)clazz;
    return shadowhook_init(mode, debuggable);
}

jint JNICALL sh_jni_nativeGetInitErrno(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return shadowhook_get_errno();
}

jint JNICALL sh_jni_nativeGetMode(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return shadowhook_get_mode();
}

jboolean JNICALL sh_jni_nativeGetDebuggable(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return shadowhook_get_debuggable();
}

void JNICALL sh_jni_nativeSetDebuggable(JNIEnv* env, jclass clazz, jboolean debuggable) {
    (void)env;
    (void)clazz;
    shadowhook_set_debuggable(debuggable);
}

jboolean JNICALL sh_jni_nativeGetRecordable(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return shadowhook_get_recordable();
}

void JNICALL sh_jni_nativeSetRecordable(JNIEnv* env, jclass clazz, jboolean recordable) {
    (void)env;
    (void)clazz;
    shadowhook_set_recordable(recordable);
}

jboolean JNICALL sh_jni_nativeGetDisable(JNIEnv* env, jclass clazz) {
    (void)env;
    (void)clazz;
    return shadowhook_get_disable();
}

void JNICALL sh_jni_nativeSetDisable(JNIEnv* env, jclass clazz, jboolean disable) {
    (void)env;
    (void)clazz;
    shadowhook_set_disable(disable);
}

jstring JNICALL sh_jni_nativeToErrmsg(JNIEnv* env, jclass clazz, jint error_number) {
    (void)clazz;
    return env->NewStringUTF(shadowhook_to_errmsg(error_number));
}

jstring JNICALL sh_jni_nativeGetRecords(JNIEnv* env, jclass clazz, jint flags) {
    (void)clazz;
    char* records = shadowhook_get_records(flags);
    jstring res = env->NewStringUTF(records ? records : "");
    if (records) free(records);
    return res;
}

jstring JNICALL sh_jni_nativeGetArch(JNIEnv* env, jclass clazz) {
    (void)clazz;
#if defined(__aarch64__)
    return env->NewStringUTF("arm64-v8a");
#elif defined(__arm__)
    return env->NewStringUTF("armeabi-v7a");
#elif defined(__x86_64__)
    return env->NewStringUTF("x86_64");
#elif defined(__i386__)
    return env->NewStringUTF("x86");
#else
    return env->NewStringUTF("arm64-v8a");
#endif
}
