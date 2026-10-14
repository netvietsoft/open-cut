// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libmiddle-bridge.so (ByteDance VE SDK Middle Bridge NLE Core)
// File: middle_bridge_mask.h
// Description: Header for CapCut Video & Overlay Masking Engine (Linear, Mirror, Circle, Rect)
// ===================================================================================

#pragma once

#include "middle_bridge_types.h"
#include <jni.h>

namespace vesdk {
namespace pub {

// --- Mask Rasterization & Sampling Kernel ---
float SampleMaskAlpha(const MaterialMask& mask, float norm_x, float norm_y);
void RenderMaskBuffer(const MaterialMask& mask, uint8_t* alpha_buffer, int width, int height);

} // namespace pub
} // namespace vesdk

#ifdef __cplusplus
extern "C" {
#endif

// --- JNI SWIG Exported Functions for MaterialMask ---
JNIEXPORT void JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_delete_1MaterialMask(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getResourceId(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getPath(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT jstring JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getNodeName(JNIEnv *env, jclass cls, jlong jarg1);
JNIEXPORT jlong JNICALL Java_com_vega_middlebridge_swig_MaterialMaskModuleJNI_MaterialMask_1getPositionInfo(JNIEnv *env, jclass cls, jlong jarg1);

#ifdef __cplusplus
}
#endif
