/**
 * @file sh_jni.h
 * @brief Dynamic JNI Registration and Java Native Interface Bridge for ShadowHook
 *        Đăng ký JNI động và cầu nối giao tiếp Java Native cho ShadowHook
 *
 * Implements JNI_OnLoad (0x9394) and 13 native methods for com/bytedance/shadowhook/ShadowHook.
 * Triển khai JNI_OnLoad (0x9394) và 13 hàm native cho com/bytedance/shadowhook/ShadowHook.
 */

#ifndef SH_JNI_H
#define SH_JNI_H

#include <jni.h>
#include "sh_types.h"

#ifdef __cplusplus
extern "C" {
#endif

#define SH_JNI_CLASS_NAME "com/bytedance/shadowhook/ShadowHook"

// Exported JNI Lifecycle Entrypoint / Điểm nhập vòng đời JNI xuất khẩu
jint JNI_OnLoad(JavaVM* vm, void* reserved);

// Native JNI Method Declarations / Khai báo các hàm JNI Native
jstring JNICALL sh_jni_nativeGetVersion(JNIEnv* env, jclass clazz);
jint JNICALL sh_jni_nativeInit(JNIEnv* env, jclass clazz, jint mode, jboolean debuggable);
jint JNICALL sh_jni_nativeGetInitErrno(JNIEnv* env, jclass clazz);
jint JNICALL sh_jni_nativeGetMode(JNIEnv* env, jclass clazz);
jboolean JNICALL sh_jni_nativeGetDebuggable(JNIEnv* env, jclass clazz);
void JNICALL sh_jni_nativeSetDebuggable(JNIEnv* env, jclass clazz, jboolean debuggable);
jboolean JNICALL sh_jni_nativeGetRecordable(JNIEnv* env, jclass clazz);
void JNICALL sh_jni_nativeSetRecordable(JNIEnv* env, jclass clazz, jboolean recordable);
jboolean JNICALL sh_jni_nativeGetDisable(JNIEnv* env, jclass clazz);
void JNICALL sh_jni_nativeSetDisable(JNIEnv* env, jclass clazz, jboolean disable);
jstring JNICALL sh_jni_nativeToErrmsg(JNIEnv* env, jclass clazz, jint error_number);
jstring JNICALL sh_jni_nativeGetRecords(JNIEnv* env, jclass clazz, jint flags);
jstring JNICALL sh_jni_nativeGetArch(JNIEnv* env, jclass clazz);

#ifdef __cplusplus
}
#endif

#endif // SH_JNI_H