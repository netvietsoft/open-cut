/**
 * ============================================================================
 * NextAI OpenCut - Reconstructed Native Graphics Engine
 * File: texturerender_native_interface.h
 * Target Library: libtexturerender_native.so (ByteDance Texture Render Native Engine)
 * Module: com.ss.texturerender
 * 
 * Description (EN):
 * Completely reconstructed JNI interface for libtexturerender_native.so.
 * Fixes P1 Audit defect TASK-AUDIT-NATIVE-010: Restores exact 64-bit ARM AArch64 ABI
 * signatures, parameter types (Surface, AHardwareBuffer, EGL pool handles), and return types.
 *
 * Mô tả (VI):
 * Tệp tiêu đề JNI hoàn chỉnh cho libtexturerender_native.so.
 * Khắc phục triệt để lỗi P1 trong báo cáo kiểm toán TASK-AUDIT-NATIVE-010: Khôi phục chính xác
 * toàn bộ chữ ký hàm theo ABI AArch64, đúng tham số (Surface, AHardwareBuffer, EGL pool),
 * và đúng kiểu trả về (jlong handle, jint dimensions/textures).
 * ============================================================================
 */

#pragma once

#include <jni.h>
#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES2/gl2.h>
#include <GLES2/gl2ext.h>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// 1. NativeWindow JNI Methods (com.ss.texturerender.NativeWindow)
// ============================================================================

/**
 * Tạo NativeWindow từ android.view.Surface
 * ARM64 Disassembly at 0x24cc:
 *   x0: JNIEnv* env
 *   x1: jobject thiz
 *   x2: jobject surface
 *   Returns: jlong nativeWindowHandle (con trỏ ANativeWindow* gói trong struct)
 */
JNIEXPORT jlong JNICALL Java_com_ss_texturerender_NativeWindow_nativeSetSurface(
    JNIEnv *env,
    jobject thiz,
    jobject surface
);

/**
 * Hủy giải phóng ANativeWindow
 * ARM64 Disassembly at 0x251c:
 *   x2: jlong nativeWindowHandle
 *   Returns: jint 0 (thành công) hoặc -1 (thất bại)
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_NativeWindow_nativeReleaseSurface(
    JNIEnv *env,
    jobject thiz,
    jlong nativeWindowHandle
);

/**
 * Lấy chiều rộng (Width) của Surface hiện tại
 * ARM64 Disassembly at 0x2580:
 *   x2: jlong nativeWindowHandle
 *   Returns: jint width
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_NativeWindow_nativeGetWidth(
    JNIEnv *env,
    jobject thiz,
    jlong nativeWindowHandle
);

/**
 * Lấy chiều cao (Height) của Surface hiện tại
 * ARM64 Disassembly at 0x2590:
 *   x2: jlong nativeWindowHandle
 *   Returns: jint height
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_NativeWindow_nativeGetHeight(
    JNIEnv *env,
    jobject thiz,
    jlong nativeWindowHandle
);

/**
 * Lấy định dạng pixel (Format) của Surface
 * ARM64 Disassembly at 0x2570 & 0x2648:
 *   x2: jlong nativeWindowHandle
 *   Returns: jint pixelFormat (WINDOW_FORMAT_RGBA_8888, v.v.)
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_NativeWindow_nativeGetSurfaceFormat(
    JNIEnv *env,
    jobject thiz,
    jlong nativeWindowHandle
);

JNIEXPORT jint JNICALL Java_com_ss_texturerender_NativeWindow_nativeGetFormat(
    JNIEnv *env,
    jobject thiz,
    jlong nativeWindowHandle
);

/**
 * Thiết lập kích thước bộ đệm và format của ANativeWindow
 * ARM64 Disassembly at 0x2554:
 *   x2: jlong nativeWindowHandle
 *   w3: jint width
 *   w4: jint height
 *   w5: jint format
 *   Returns: jint status (0 thành công)
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_NativeWindow_nativeSetBuffersGeometry(
    JNIEnv *env,
    jobject thiz,
    jlong nativeWindowHandle,
    jint width,
    jint height,
    jint format
);

// ============================================================================
// 2. HardwareBuffer EGL Pool Methods (com.ss.texturerender.base.EGLExt)
// ============================================================================

/**
 * Khởi tạo Pool cấp phát Texture từ HardwareBuffer
 * ARM64 Disassembly at 0x85c8:
 *   w2: jint poolCapacity
 *   Returns: jlong poolHandle
 */
JNIEXPORT jlong JNICALL Java_com_ss_texturerender_base_EGLExt_nCreateHardwareBufferEglPool(
    JNIEnv *env,
    jobject thiz,
    jint poolCapacity
);

/**
 * Giải phóng Pool HardwareBuffer
 * ARM64 Disassembly at 0x8704:
 *   x2: jlong poolHandle
 */
JNIEXPORT void JNICALL Java_com_ss_texturerender_base_EGLExt_nDestroyHardwareBufferEglPool(
    JNIEnv *env,
    jobject thiz,
    jlong poolHandle
);

/**
 * Tạo hoặc lấy Texture OpenGL ES gắn với AHardwareBuffer (Zero-Copy)
 * ARM64 Disassembly at 0x8650:
 *   x2: jlong poolHandle
 *   x3: jobject hardwareBuffer
 *   w4: jint width
 *   w5: jint height
 *   w6: jint format
 *   Returns: jint glTextureId (-1 nếu lỗi)
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_base_EGLExt_nGetOrCreateTextureByHardwareBuffer(
    JNIEnv *env,
    jobject thiz,
    jlong poolHandle,
    jobject hardwareBuffer,
    jint width,
    jint height,
    jint format
);

/**
 * Gắn AHardwareBuffer vào một Texture OpenGL ES sẵn có
 * ARM64 Disassembly at 0x8554:
 *   x2: jlong poolHandle
 *   x3: jobject hardwareBuffer
 *   w4: jint target (GL_TEXTURE_2D hoặc GL_TEXTURE_EXTERNAL_OES)
 *   w5: jint textureId
 *   Returns: jint status (0 thành công, -1 lỗi)
 */
JNIEXPORT jint JNICALL Java_com_ss_texturerender_base_EGLExt_nBindHardwareBufferToTexture(
    JNIEnv *env,
    jobject thiz,
    jlong poolHandle,
    jobject hardwareBuffer,
    jint target,
    jint textureId
);

#ifdef __cplusplus
}
#endif
