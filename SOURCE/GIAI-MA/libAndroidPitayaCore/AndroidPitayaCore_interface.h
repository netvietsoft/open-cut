// ======================================================================
// RECONSTRUCTED C++ INTERFACE: AndroidPitayaCore_interface.h
// Library: libAndroidPitayaCore.so (ByteDance Pitaya On-Device AI Core)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   Unified public interface and JNI declarations for ByteDance Pitaya
//   On-Device AI, Feature Engineering, and Task Execution Core.
//
// Mô tả (Tiếng Việt):
//   Giao diện công khai hợp nhất và khai báo JNI cho lõi AI trên thiết bị,
//   kỹ nghệ đặc trưng và lập lịch tác vụ ByteDance Pitaya.
// ======================================================================

#pragma once

#include <jni.h>
#include "pitaya_types.h"
#include "pitaya_objects.h"
#include "pitaya_kv_store.h"
#include "pitaya_feature_store.h"
#include "pitaya_task_executor.h"
#include "pitaya_core.h"

namespace NextAI::OpenCut::pitaya {

// ----------------------------------------------------------------------
// C-API Export Declarations for JNI Bridge & Integration
// ----------------------------------------------------------------------
extern "C" {

    // --- PitayaNativeInstance JNI APIs ---
    JNIEXPORT jboolean JNICALL Java_com_bytedance_pitaya_jniwrapper_PitayaNativeInstance_nativeIsReady(JNIEnv *env, jobject thiz);
    JNIEXPORT jboolean JNICALL Java_com_bytedance_pitaya_jniwrapper_PitayaNativeInstance_nativeIsPreloadReady(JNIEnv *env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_jniwrapper_PitayaNativeInstance_nativePreDownloadAllPackage(JNIEnv *env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_jniwrapper_PitayaNativeInstance_nativeCleanStorage(JNIEnv *env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_jniwrapper_PitayaNativeInstance_nativeReleaseAllEngines(JNIEnv *env, jobject thiz);

    // --- PTYKVStore JNI APIs ---
    JNIEXPORT jboolean JNICALL Java_com_bytedance_pitaya_feature_PTYKVStore_nativeContain(JNIEnv *env, jobject thiz, jstring jkey, jstring jdomain);
    JNIEXPORT jboolean JNICALL Java_com_bytedance_pitaya_feature_PTYKVStore_nativeSetKVData(JNIEnv *env, jobject thiz, jstring jkey, jlong jval_handle, jstring jdomain);
    JNIEXPORT jlong JNICALL Java_com_bytedance_pitaya_feature_PTYKVStore_nativeGetKVData(JNIEnv *env, jobject thiz, jstring jkey, jstring jdomain);
    JNIEXPORT jlong JNICALL Java_com_bytedance_pitaya_feature_PTYKVStore_nativeGetCacheWithTryLock(JNIEnv *env, jobject thiz, jstring jkey, jstring jdomain);
    JNIEXPORT jboolean JNICALL Java_com_bytedance_pitaya_feature_PTYKVStore_nativeAppend(JNIEnv *env, jobject thiz, jstring jkey, jdouble jdelta, jstring jdomain);

    // --- PTYNativeDict JNI APIs ---
    JNIEXPORT jlong JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeDict_nativeCreateDict(JNIEnv *env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeDict_nativeReleaseDict(JNIEnv *env, jobject thiz, jlong handle);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeDict_nativeSetStr(JNIEnv *env, jobject thiz, jlong handle, jstring jkey, jstring jval);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeDict_nativeSetDouble(JNIEnv *env, jobject thiz, jlong handle, jstring jkey, jdouble jval);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeDict_nativeSetBool(JNIEnv *env, jobject thiz, jlong handle, jstring jkey, jboolean jval);
    JNIEXPORT jstring JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeDict_nativeToString(JNIEnv *env, jobject thiz, jlong handle);

    // --- PTYNativeArray JNI APIs ---
    JNIEXPORT jlong JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeArray_nativeCreateArray(JNIEnv *env, jobject thiz);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeArray_nativeReleaseArray(JNIEnv *env, jobject thiz, jlong handle);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeArray_nativeAppendStr(JNIEnv *env, jobject thiz, jlong handle, jstring jval);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_api_bean_nativeobj_pty_PTYNativeArray_nativeAppendDouble(JNIEnv *env, jobject thiz, jlong handle, jdouble jval);

    // --- PTYNativeTrace JNI APIs ---
    JNIEXPORT jlong JNICALL Java_com_bytedance_pitaya_jniwrapper_PTYNativeTrace_nativeCreateTrace(JNIEnv *env, jobject thiz, jstring jname);
    JNIEXPORT jdouble JNICALL Java_com_bytedance_pitaya_jniwrapper_PTYNativeTrace_nativeDuration(JNIEnv *env, jobject thiz, jlong trace_handle);
    JNIEXPORT void JNICALL Java_com_bytedance_pitaya_jniwrapper_PTYNativeTrace_nativeReleaseTrace(JNIEnv *env, jobject thiz, jlong trace_handle);

    // --- 10-Point Verification Self Test ---
    int32_t pitaya_run_verification_self_test();
}

} // namespace NextAI::OpenCut::pitaya
