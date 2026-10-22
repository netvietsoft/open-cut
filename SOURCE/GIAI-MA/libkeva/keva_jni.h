/**
 * @file keva_jni.h
 * @brief ByteDance Keva Native JNI Header.
 *        Giao diện JNI native cho hệ thống lưu trữ Keva.
 */

#ifndef GECKOX_KEVA_JNI_H
#define GECKOX_KEVA_JNI_H

#include "keva_types.h"

#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM vm, void* reserved);

// 28 JNI Exported Functions
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_loadRepo(JNIEnv* env, jclass clazz, jstring name, jint mode, jboolean multiProcess);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_loadRepoWithPath(JNIEnv* env, jclass clazz, jstring name, jstring path, jint mode);
JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_initialize(JNIEnv* env, jclass clazz, jstring path);
JNIEXPORT jboolean JNICALL Java_com_bytedance_keva_KevaImpl_delete(JNIEnv* env, jclass clazz, jstring name);
JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_clear(JNIEnv* env, jclass clazz, jlong handle);
JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_dump(JNIEnv* env, jclass clazz, jlong handle);
JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_checkReportException(JNIEnv* env, jclass clazz, jlong handle);

JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeInt(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jint val);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeBoolean(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jboolean val);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeString(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jstring val);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeFloat(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jfloat val);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeLong(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jlong val);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeDouble(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jdouble val);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeBytes(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jbyteArray bytes, jint len);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_storeStringArray(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jobjectArray array, jint len);

JNIEXPORT jint JNICALL Java_com_bytedance_keva_KevaImpl_fetchInt(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jint defaultVal);
JNIEXPORT jboolean JNICALL Java_com_bytedance_keva_KevaImpl_fetchBoolean(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jboolean defaultVal);
JNIEXPORT jlong JNICALL Java_com_bytedance_keva_KevaImpl_fetchLong(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jlong defaultVal);
JNIEXPORT jfloat JNICALL Java_com_bytedance_keva_KevaImpl_fetchFloat(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jfloat defaultVal);
JNIEXPORT jdouble JNICALL Java_com_bytedance_keva_KevaImpl_fetchDouble(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jdouble defaultVal);
JNIEXPORT jstring JNICALL Java_com_bytedance_keva_KevaImpl_fetchString(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jstring defaultVal);
JNIEXPORT jbyteArray JNICALL Java_com_bytedance_keva_KevaImpl_fetchBytes(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jbyteArray defaultBytes, jint len);
JNIEXPORT jobjectArray JNICALL Java_com_bytedance_keva_KevaImpl_fetchStringArray(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset, jobjectArray defaultArray, jint len);

JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_erase(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset);
JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_rebuildValueMap(JNIEnv* env, jclass clazz, jlong handle);
JNIEXPORT jboolean JNICALL Java_com_bytedance_keva_KevaImpl_contains(JNIEnv* env, jclass clazz, jlong handle, jstring key, jlong expectedOffset);
JNIEXPORT void JNICALL Java_com_bytedance_keva_KevaImpl_eraseUnusedChunk(JNIEnv* env, jclass clazz, jlong handle, jlong offset);
JNIEXPORT jint JNICALL Java_com_bytedance_keva_KevaImpl_protectPortingInterProcess(JNIEnv* env, jclass clazz, jstring path, jboolean enable, jint flag);

#ifdef __cplusplus
}
#endif

#endif // GECKOX_KEVA_JNI_H
