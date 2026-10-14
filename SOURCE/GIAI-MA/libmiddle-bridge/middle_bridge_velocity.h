// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_velocity.h
// Description: Header for CapCut Velocity Algorithm & Bezier Speed Ramping
// ===================================================================================

#pragma once

#include "middle_bridge_types.h"
#include <jni.h>

namespace vesdk {
namespace pub {

// --- Core Velocity Calculation Engine ---
std::shared_ptr<RunVelocityAlgorithmRespStruct> ExecuteVelocityAlgorithm(
    const std::shared_ptr<RunVelocityAlgorithmReqStruct>& req);

// --- Bezier Curve Math Interpolation ---
double EvaluateCubicBezier(double t, double p0, double p1, double p2, double p3);
double EvaluateVelocityAtNormalizedTime(const std::vector<Point>& curve, double norm_t);
int64_t MapTimelineTimeToSourceTime(const std::vector<Point>& curve, int64_t timeline_us, int64_t total_duration_us);

} // namespace pub
} // namespace vesdk

#ifdef __cplusplus
extern "C" {
#endif

// --- JNI SWIG Exported Functions for RunVelocityAlgorithm ---
JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_new_1RunVelocityAlgorithmReqStruct(JNIEnv *env, jclass cls);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_delete_1RunVelocityAlgorithmReqStruct(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1path_1set(JNIEnv *env, jclass cls, jlong jarg1, jstring jarg2);
JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1path_1get(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1speed_1set(JNIEnv *env, jclass cls, jlong jarg1, jdouble jarg2);
JNIEXPORT jdouble JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1video_1speed_1get(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1mode_1set(JNIEnv *env, jclass cls, jlong jarg1, jint jarg2);
JNIEXPORT jint JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1mode_1get(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1phase_1set(JNIEnv *env, jclass cls, jlong jarg1, jint jarg2);
JNIEXPORT jint JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmReqStruct_1algo_1phase_1get(JNIEnv *env, jclass cls, jlong jarg1);

JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_new_1RunVelocityAlgorithmRespStruct(JNIEnv *env, jclass cls);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_delete_1RunVelocityAlgorithmRespStruct(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT jfloat JNICALL Java_com_vega_middlebridge_swig_RunVelocityAlgorithmModuleJNI_RunVelocityAlgorithmRespStruct_1progress_1get(JNIEnv *env, jclass cls, jlong jarg1);

#ifdef __cplusplus
}
#endif
