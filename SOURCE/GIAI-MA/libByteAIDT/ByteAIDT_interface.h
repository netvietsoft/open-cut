// ======================================================================
// RECONSTRUCTED C++ INTERFACE: ByteAIDT_interface.h
// Library: libByteAIDT.so (ByteDance Pitaya ByteDT Decision Tree Bridge)
// Component: NextAI OpenCut AI & Decision Tree Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   C/C++ Interface and Android JNI Export Declarations for ByteAIDT.
//   Provides standard JNI entry points for Android JVM layer:
//   - nativeInitEngine
//   - nativeRecommendBitrate
//   - nativePredictAestheticScore
//   - nativeReleaseEngine
//
// Mô tả (Tiếng Việt):
//   Giao diện C/C++ và các khai báo hàm xuất khẩu Android JNI cho ByteAIDT.
//   Cung cấp các điểm nhập JNI tiêu chuẩn cho tầng máy ảo Android JVM:
//   - nativeInitEngine
//   - nativeRecommendBitrate
//   - nativePredictAestheticScore
//   - nativeReleaseEngine
// ======================================================================

#pragma once

#include <jni.h>
#include <cstdint>
#include <string>
#include <vector>
#include "pitaya_engine_bytedt.h"
#include "bytedt_adapter_bridge.h"

namespace NextAI::OpenCut::ByteAIDT {

extern "C" {

// C Exports
bool ByteAIDT_Initialize(const char* model_dir);
int32_t ByteAIDT_RecommendExportBitrate(int32_t width, int32_t height, float fps, float duration, float motion, float texture, int32_t tier);
float ByteAIDT_EvaluateAesthetic(const float* features, int32_t count);
void ByteAIDT_Release();

// Android JNI Exports
JNIEXPORT jboolean JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeInit(
    JNIEnv* env, jclass clazz, jstring model_dir);

JNIEXPORT jint JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeRecommendBitrate(
    JNIEnv* env, jclass clazz, jint width, jint height, jfloat fps, jfloat duration, jfloat motion, jfloat texture, jint tier);

JNIEXPORT jfloat JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeEvaluateAesthetic(
    JNIEnv* env, jclass clazz, jfloatArray features);

JNIEXPORT void JNICALL Java_com_nextai_opencut_ai_bytedt_ByteAIDTNative_nativeRelease(
    JNIEnv* env, jclass clazz);

} // extern "C"

} // namespace NextAI::OpenCut::ByteAIDT
