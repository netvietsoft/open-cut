/**
 * ============================================================================
 * NextAI OpenCut - Reconstructed Native Graphics Engine
 * File: native_filters_interface.h
 * Target Library: libnative-filters.so (Facebook Fresco ImagePipeline Native Filters)
 * Package Name: com.facebook.imagepipeline.nativecode
 * 
 * Description (EN):
 * Reconstructed C++/JNI header for libnative-filters.so.
 * Provides high-performance software Bitmap manipulation:
 *   1. Iterative Box Blur (moving sum box filter multi-pass algorithm).
 *   2. Circular rounding mask with optional anti-aliasing and border ring.
 *
 * Mô tả (VI):
 * Tệp tiêu đề C++/JNI tái cấu trúc cho libnative-filters.so.
 * Cung cấp các bộ lọc xử lý Bitmap hiệu năng cao trên CPU/Bộ nhớ đệm:
 *   1. Làm mờ hộp nhiều vòng lặp (Iterative Box Blur sliding-window).
 *   2. Cắt tròn ảnh (Circular rounding) kèm khử răng cưa và viền viền (Border ring).
 * ============================================================================
 */

#pragma once

#include <jni.h>
#include <android/bitmap.h>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// 1. NativeBlurFilter (com.facebook.imagepipeline.nativecode.NativeBlurFilter)
// ============================================================================

/**
 * Làm mờ hộp lặp (Iterative Box Blur) trên Android Bitmap
 * Chữ ký Java: nativeIterativeBoxBlur(Landroid/graphics/Bitmap;II)V
 * 
 * @param env JNI Environment
 * @param clazz Lớp Java gọi
 * @param bitmap Đối tượng Bitmap Android (định dạng ARGB_8888)
 * @param iterations Số vòng lặp làm mờ (iterations > 0)
 * @param blurRadius Bán kính làm mờ (radius > 0)
 */
JNIEXPORT void JNICALL Java_com_facebook_imagepipeline_nativecode_NativeBlurFilter_nativeIterativeBoxBlur(
    JNIEnv *env,
    jclass clazz,
    jobject bitmap,
    jint iterations,
    jint blurRadius
);

// ============================================================================
// 2. NativeRoundingFilter (com.facebook.imagepipeline.nativecode.NativeRoundingFilter)
// ============================================================================

/**
 * Cắt tròn Bitmap thành Avatar tròn (Circle Mask)
 * Chữ ký Java: nativeToCircleFilter(Landroid/graphics/Bitmap;Z)V
 * 
 * @param env JNI Environment
 * @param clazz Lớp Java gọi
 * @param bitmap Đối tượng Bitmap Android (định dạng ARGB_8888)
 * @param antiAliased Bật/tắt khử răng cưa sub-pixel ở đường biên
 */
JNIEXPORT void JNICALL Java_com_facebook_imagepipeline_nativecode_NativeRoundingFilter_nativeToCircleFilter(
    JNIEnv *env,
    jclass clazz,
    jobject bitmap,
    jboolean antiAliased
);

/**
 * Cắt tròn Bitmap kèm viền màu sắc (Circle with Border)
 * Chữ ký Java: nativeToCircleWithBorderFilter(Landroid/graphics/Bitmap;IIZ)V
 * 
 * @param env JNI Environment
 * @param clazz Lớp Java gọi
 * @param bitmap Đối tượng Bitmap Android (định dạng ARGB_8888)
 * @param colorARGB Màu viền định dạng 32-bit ARGB (ví dụ 0xFFFFFFFF)
 * @param borderWidth Độ dày đường viền (tính bằng pixel)
 * @param antiAliased Bật/tắt khử răng cưa biên
 */
JNIEXPORT void JNICALL Java_com_facebook_imagepipeline_nativecode_NativeRoundingFilter_nativeToCircleWithBorderFilter(
    JNIEnv *env,
    jclass clazz,
    jobject bitmap,
    jint colorARGB,
    jint borderWidth,
    jboolean antiAliased
);

#ifdef __cplusplus
}
#endif

namespace NextAI::OpenCut::Filters {

// Core C++ processing algorithms
void iterativeBoxBlur(void* pixels, int width, int height, int stride, int iterations, int radius);
void toCircleFilter(void* pixels, int width, int height, int stride, bool antiAliased);
void toCircleWithBorderFilter(void* pixels, int width, int height, int stride, uint32_t colorARGB, int borderWidth, bool antiAliased);

} // namespace NextAI::OpenCut::Filters
