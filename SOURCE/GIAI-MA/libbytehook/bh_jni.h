/**
 * @file bh_jni.h
 * @brief Dynamic JNI Bridge for ByteDance ByteHook (com.bytedance.android.bytehook.ByteHook)
 *        Cầu nối JNI động cho ByteDance ByteHook
 *
 * Implements JNI_OnLoad and the 10 native methods registered dynamically.
 * Thực thi JNI_OnLoad và 10 phương thức native đăng ký động.
 */

#ifndef BH_JNI_H
#define BH_JNI_H

#include "bh_types.h"
#include <jni.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BYTEHOOK_JNI_CLASS_NAME "com/bytedance/android/bytehook/ByteHook"

/**
 * @brief Dynamic JNI initialization entrypoint
 *        Điểm nhập khởi tạo JNI động
 *
 * Exported C API matching ARM64 symbol 'JNI_OnLoad' at VAddr 0x00009144.
 */
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);

// 10 Native JNI method handlers / 10 Hàm xử lý phương thức JNI native
JNIEXPORT jstring JNICALL ByteHook_nativeGetVersion(JNIEnv* env, jclass clazz);
JNIEXPORT jint JNICALL ByteHook_nativeInit(JNIEnv* env, jclass clazz, jint mode, jboolean debug);
JNIEXPORT jint JNICALL ByteHook_nativeAddIgnore(JNIEnv* env, jclass clazz, jstring caller_path_name);
JNIEXPORT jint JNICALL ByteHook_nativeGetMode(JNIEnv* env, jclass clazz);
JNIEXPORT jboolean JNICALL ByteHook_nativeGetDebug(JNIEnv* env, jclass clazz);
JNIEXPORT void JNICALL ByteHook_nativeSetDebug(JNIEnv* env, jclass clazz, jboolean debug);
JNIEXPORT jboolean JNICALL ByteHook_nativeGetRecordable(JNIEnv* env, jclass clazz);
JNIEXPORT void JNICALL ByteHook_nativeSetRecordable(JNIEnv* env, jclass clazz, jboolean recordable);
JNIEXPORT jstring JNICALL ByteHook_nativeGetRecords(JNIEnv* env, jclass clazz, jint item_flags);
JNIEXPORT jstring JNICALL ByteHook_nativeGetArch(JNIEnv* env, jclass clazz);

#ifdef __cplusplus
}
#endif

#endif // BH_JNI_H
