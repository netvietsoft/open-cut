// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_composition.h
// Description: Header for CapCut NLE Timeline Clip Replacement & Track Synchronization
// ===================================================================================

#pragma once

#include "middle_bridge_types.h"
#include <jni.h>

namespace vesdk {
namespace pub {

// --- Composition Replacement Service ---
bool ReplaceCompositionSegment(
    const std::string& seg_id,
    const std::string& new_media_path,
    const std::string& composition_json);

} // namespace pub
} // namespace vesdk

#ifdef __cplusplus
extern "C" {
#endif

// --- JNI SWIG Exported Functions for CompositionReplaceParam ---
JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_CompositionReplaceParamModuleJNI_new_1CompositionReplaceParam(JNIEnv *env, jclass cls);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_CompositionReplaceParamModuleJNI_delete_1CompositionReplaceParam(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_CompositionReplaceParamModuleJNI_CompositionReplaceParam_1seg_1id_1set(JNIEnv *env, jclass cls, jlong jarg1, jstring jarg2);
JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_CompositionReplaceParamModuleJNI_CompositionReplaceParam_1seg_1id_1get(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_CompositionReplaceParamModuleJNI_CompositionReplaceParam_1composition_1param_1set(JNIEnv *env, jclass cls, jlong jarg1, jstring jarg2);
JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_CompositionReplaceParamModuleJNI_CompositionReplaceParam_1composition_1param_1get(JNIEnv *env, jclass cls, jlong jarg1);

#ifdef __cplusplus
}
#endif
