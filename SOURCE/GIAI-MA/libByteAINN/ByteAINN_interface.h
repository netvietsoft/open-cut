// ======================================================================
// RECONSTRUCTED C++ INTERFACE: ByteAINN_interface.h
// Library: libByteAINN.so (ByteDance Pitaya ByteNN Neural Engine Bridge)
// Component: NextAI OpenCut AI & Computer Vision Core (CORE_02_AI_CV)
// Architecture: AArch64 (ARMv8-A / ARM64)
//
// Description (English):
//   C/C++ Interface and Android JNI Export Declarations for ByteAINN.
//   Provides standard JNI entry points for Android JVM layer:
//   - nativeInitEngine
//   - nativeLoadModel
//   - nativePredict
//   - nativeReleaseEngine
//
// Mô tả (Tiếng Việt):
//   Giao diện C/C++ và các khai báo hàm xuất khẩu Android JNI cho ByteAINN.
//   Cung cấp các điểm nhập JNI tiêu chuẩn cho tầng máy ảo Android JVM:
//   - nativeInitEngine
//   - nativeLoadModel
//   - nativePredict
//   - nativeReleaseEngine
// ======================================================================

#pragma once

#include <jni.h>
#include <cstdint>
#include <string>
#include <vector>
#include <memory>
#include "pitaya_engine_bytenn.h"
#include "bytenn_adapter_bridge.h"

namespace NextAI::OpenCut::ByteAINN {

// ----------------------------------------------------------------------
// C/C++ High Level Exported Functions
// ----------------------------------------------------------------------
extern "C" {

// Khởi tạo động cơ
bool ByteAINN_Initialize(const char* model_dir, int32_t forward_type);

// Suy luận tách nền video
bool ByteAINN_SegmentMatting(const uint8_t* rgba_frame, int32_t width, int32_t height,
                             uint8_t* out_alpha_mask, int64_t* out_time_us);

// Giải phóng tài nguyên
void ByteAINN_Release();

// ----------------------------------------------------------------------
// Android JNI Exported Functions
// Package: com.nextai.opencut.ai.bytenn.ByteAINNNative
// ----------------------------------------------------------------------
JNIEXPORT jboolean JNICALL Java_com_nextai_opencut_ai_bytenn_ByteAINNNative_nativeInit(
    JNIEnv* env, jclass clazz, jstring model_dir, jint forward_type);

JNIEXPORT jboolean JNICALL Java_com_nextai_opencut_ai_bytenn_ByteAINNNative_nativeSegmentMatting(
    JNIEnv* env, jclass clazz, jbyteArray rgba_frame, jint width, jint height, jbyteArray out_alpha_mask);

JNIEXPORT void JNICALL Java_com_nextai_opencut_ai_bytenn_ByteAINNNative_nativeRelease(
    JNIEnv* env, jclass clazz);

} // extern "C"

} // namespace NextAI::OpenCut::ByteAINN
