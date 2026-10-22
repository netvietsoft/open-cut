/**
 * @file alog_jni.h
 * @brief ByteDance ALog Native JNI Bridge Header.
 *        Giao diện JNI native đăng ký động cho hệ thống nhật ký ByteDance ALog.
 */

#ifndef BYTEDANCE_ALOG_JNI_H
#define BYTEDANCE_ALOG_JNI_H

#include <jni.h>
#include "alog_types.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);

// 18 JNI Exported Functions matching gAlogMethods table at VAddr 0x14008
JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeCreate(
    JNIEnv* env, jclass clazz,
    jint mode, jboolean enableSyslog, jstring logDir, jstring cacheDir,
    jint maxDirSizeMb, jint maxFileSizeMb, jint maxHistoryDays, jstring prefix,
    jint compressorType, jint compressLevel, jstring pubKey,
    jint encryptorType, jint bufferSize, jint asyncQueueSize, jint minLogLevel,
    jint flushIntervalSec, jint cacheSizeLimit, jstring processName,
    jlong subModuleMask, jboolean enableMemoryDump, jint reservedFlag);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeWrite(
    JNIEnv* env, jclass clazz, jlong handle, jint level, jstring tag, jstring msg);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeWriteAsyncMsg(
    JNIEnv* env, jclass clazz, jlong handle, jint level, jstring tag, jstring msg, jlong arg1, jlong arg2);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeAsyncFlush(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSyncFlush(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeTimedSyncFlush(
    JNIEnv* env, jclass clazz, jlong handle, jint timeoutMs);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetLevel(
    JNIEnv* env, jclass clazz, jlong handle, jint level);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetSyslog(
    JNIEnv* env, jclass clazz, jlong handle, jboolean enable);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeDestroy(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetLegacyWriteFuncAddr(
    JNIEnv* env, jclass clazz);

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetLegacyFlushFuncAddr(
    JNIEnv* env, jclass clazz);

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetLegacyGetLogFileDirFuncAddr(
    JNIEnv* env, jclass clazz);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetDefaultInstance(
    JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeUpdateAlogCacheSize(
    JNIEnv* env, jclass clazz, jint cacheSize);

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetNativeWriteFuncAddr(
    JNIEnv* env, jclass clazz);

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetNativeWriteAsyncFuncAddr(
    JNIEnv* env, jclass clazz);

JNIEXPORT jlong JNICALL Java_com_bytedance_android_alog_Alog_nativeGetNativeInitFuncAddr(
    JNIEnv* env, jclass clazz);

JNIEXPORT void JNICALL Java_com_bytedance_android_alog_Alog_nativeSetEnableWrite(
    JNIEnv* env, jclass clazz, jint enable);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_JNI_H
