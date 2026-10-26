// ============================================================================
// File: bdhm_native_interface.h
// Module: libbdhm_native.so — Public C/JNI Interface & Exported Symbol Table
//         (Giao diện C/JNI Công khai & Bảng 27 Biểu tượng Xuất khẩu .dynsym)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from apktool-res/lib/arm64-v8a/libbdhm_native.so
//               (27 exported STT_FUNC symbols in .dynsym [052]..[078])
// ============================================================================

#pragma once

#include <jni.h>
#include "bdhm_types.h"
#include "bdhm_expr_clause_engine.h"
#include "bdhm_spark_tracing_engine.h"

extern "C" {

// ============================================================================
// [EN] 1. JNI Lifecycle Entry Points (bdhm_native/src/api/glue.rs)
//      - JNI_OnLoad   (0x045e44, size: 2,892 B): caches JavaVM* and global
//        jclass/jmethodID/jfieldID references for SparkTracingNative & boxed types.
//      - JNI_OnUnload (0x046990, size: 648 B): releases global references.
// [VN] 1. Điểm vào Vòng đời JNI (bdhm_native/src/api/glue.rs)
// ============================================================================
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);
JNIEXPORT void JNICALL JNI_OnUnload(JavaVM* vm, void* reserved);

// ============================================================================
// [EN] 2. JNIReachabilityFence Methods (0x03e820..0x03e83c, 4 bytes each: ret)
//      Prevents Android ART GC from collecting Java wrapper objects while
//      native pointers are in active use on the current stack frame.
// [VN] 2. Các hàm Hàng rào Chống Thu gom Rác JNIReachabilityFence (0x03e820..0x03e83c)
// ============================================================================
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence1(
    JNIEnv* env, jclass clazz, jobject ref1);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence2(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence3(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2, jobject ref3);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence4(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2, jobject ref3, jobject ref4);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence5(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence6(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5, jobject ref6);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence7(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5, jobject ref6, jobject ref7);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_JNIReachabilityFence_reachabilityFence8(
    JNIEnv* env, jclass clazz, jobject ref1, jobject ref2, jobject ref3, jobject ref4, jobject ref5, jobject ref6, jobject ref7, jobject ref8);

// ============================================================================
// [EN] 3. SparkTracingNative Exported JNI Methods (17 functions, 0x03eae0..0x045d10)
// [VN] 3. 17 Phương thức JNI Xuất khẩu của SparkTracingNative (0x03eae0..0x045d10)
// ============================================================================
JNIEXPORT jlong JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_init(
    JNIEnv* env, jclass clazz, jobject config_obj, jobject client_obj);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_initLogger(
    JNIEnv* env, jclass clazz, jboolean enable_log);
JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1snapshot(
    JNIEnv* env, jclass clazz, jlong native_ptr);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setManifest(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring manifest_json);
JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1getProperties(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id);
JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1getProperty(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jstring key, jboolean recursive);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setProperty(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jstring key, jobject val_obj, jlong life_millis, jlong now_millis);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setProperties(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jstring props_json, jlong life_millis, jlong now_millis);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1newContextProps(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jlong life_millis, jboolean is_static, jboolean is_leaf);
JNIEXPORT jboolean JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1isContextPropsExists(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1setContextPropsAliveState(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jboolean is_alive);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1updateLink(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring child_id, jstring parent_id, jint op);
JNIEXPORT jobjectArray JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1getChildIds(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring parent_id);
JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1computeExpr(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jstring expr_str);
JNIEXPORT jstring JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1compute(
    JNIEnv* env, jclass clazz, jlong native_ptr, jstring context_id, jstring event_or_manifest_json);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1update(
    JNIEnv* env, jclass clazz, jlong native_ptr);
JNIEXPORT void JNICALL Java_com_bytedance_android_monitorV2_spark_1tracing_gen_SparkTracingNative_do_1delete(
    JNIEnv* env, jclass clazz, jlong native_ptr);

} // extern "C"
