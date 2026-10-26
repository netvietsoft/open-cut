// ============================================================================
// File: pl_droidsonroids_gif_interface.h
// Target: libpl_droidsonroids_gif.so (42,464 bytes, ELF64 AArch64, 97 .dynsym)
// Package: com.nextai.opencut (NextAI OpenCut Reconstruction)
// Task ID: TASK-096-RECONSTRUCTION-LIBPL_DROIDSONROIDS_GIF (TASK_SO_039)
// Evidence Classification: OBSERVED (Direct .dynsym [052]..[096] & Disassembly)
// Description (EN): Complete C ABI / JNI export header for all 45 exported
//                   functions in libpl_droidsonroids_gif.so (JNI_OnLoad,
//                   JNI_OnUnload, and 43 Java_pl_droidsonroids_gif_GifInfoHandle_*
//                   native methods).
// Mô tả (VN): Tệp tiêu đề xuất C ABI / JNI đầy đủ cho toàn bộ 45 hàm xuất
//             trong libpl_droidsonroids_gif.so (JNI_OnLoad, JNI_OnUnload và
//             43 phương thức native Java_pl_droidsonroids_gif_GifInfoHandle_*).
// ============================================================================

#pragma once

#include <cstdint>
#include "pl_droidsonroids_gif_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Portable JNI type aliases for standalone C++17 compilation & testing
// Định nghĩa kiểu JNI tương thích độc lập phục vụ biên dịch và kiểm thử C++17
using jboolean   = uint8_t;
using jbyte      = int8_t;
using jchar      = uint16_t;
using jshort     = int16_t;
using jint       = int32_t;
using jlong      = int64_t;
using jfloat     = float;
using jdouble    = double;
using jsize      = int32_t;
using jobject    = void*;
using jclass     = void*;
using jstring    = void*;
using jbyteArray = void*;
using jlongArray = void*;
using jobjectArray = void*;
using JNIEnv     = void;
using JavaVM     = void;

constexpr jboolean JNI_FALSE = 0U;
constexpr jboolean JNI_TRUE  = 1U;

// ============================================================================
// Exported .dynsym Functions ([052]..[096]) with Exact Virtual Addresses
// Danh sách 45 hàm xuất .dynsym ([052]..[096]) kèm địa chỉ ảo chính xác
// ============================================================================

// [053] 0x007d70 (size: 796 B) & [089] 0x00808c (size: 12 B)
// Khởi tạo và giải phóng thư viện JNI + bảng màu xám 256 mức mặc định
jint JNI_OnLoad(JavaVM* vm, void* reserved);
void JNI_OnUnload(JavaVM* vm, void* reserved);

// [094] 0x005a4c (372 B), [079] 0x005bc0 (340 B), [080] 0x005d90 (380 B),
// [087] 0x005f74 (708 B), [088] 0x006564 (288 B), [056] 0x006558 (12 B),
// [063] 0x006474 (228 B), [068] 0x004e50 (392 B)
// Nhóm hàm mở nguồn dữ liệu GIF (File, ByteArray, DirectByteBuffer, Stream, FD) và giải phóng
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openFile(JNIEnv* env, jclass clazz, jstring jfname);
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openByteArray(JNIEnv* env, jclass clazz, jbyteArray bytes);
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openDirectByteBuffer(JNIEnv* env, jclass clazz, jobject buffer);
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openStream(JNIEnv* env, jclass clazz, jobject stream);
jlong Java_pl_droidsonroids_gif_GifInfoHandle_openNativeFileDescriptor(JNIEnv* env, jclass clazz, jint fd, jlong offset);
jint  Java_pl_droidsonroids_gif_GifInfoHandle_createTempNativeFileDescriptor(JNIEnv* env, jclass clazz);
jint  Java_pl_droidsonroids_gif_GifInfoHandle_extractNativeFileDescriptor(JNIEnv* env, jclass clazz, jobject fileDescriptor, jboolean closeOriginalDescriptor);
void  Java_pl_droidsonroids_gif_GifInfoHandle_free(JNIEnv* env, jclass clazz, jlong gifInfo);

// [083] 0x0041f4 (396 B), [084] 0x0043c0 (76 B), [093] 0x00440c (12 B),
// [052] 0x0045b8 (336 B), [085] 0x004708 (204 B), [061] 0x0047d4 (96 B),
// [086] 0x004834 (112 B)
// Nhóm hàm kết xuất khung hình Bitmap, đặt tốc độ, tua thời gian/khung hình và lưu phần dư
jlong    Java_pl_droidsonroids_gif_GifInfoHandle_renderFrame(JNIEnv* env, jclass clazz, jlong gifInfo, jobject jbitmap);
jboolean Java_pl_droidsonroids_gif_GifInfoHandle_reset(JNIEnv* env, jclass clazz, jlong gifInfo);
void     Java_pl_droidsonroids_gif_GifInfoHandle_setSpeedFactor(JNIEnv* env, jclass clazz, jlong gifInfo, jfloat factor);
void     Java_pl_droidsonroids_gif_GifInfoHandle_seekToTime(JNIEnv* env, jclass clazz, jlong gifInfo, jint desiredPos, jobject jbitmap);
void     Java_pl_droidsonroids_gif_GifInfoHandle_seekToFrame(JNIEnv* env, jclass clazz, jlong gifInfo, jint desiredIndex, jobject jbitmap);
void     Java_pl_droidsonroids_gif_GifInfoHandle_saveRemainder(JNIEnv* env, jclass clazz, jlong gifInfo);
jlong    Java_pl_droidsonroids_gif_GifInfoHandle_restoreRemainder(JNIEnv* env, jclass clazz, jlong gifInfo);

// [069] 0x007c4c (164 B), [070] 0x0080a4 (28 B), [072] 0x0080c0 (40 B),
// [057] 0x0080e8 (20 B), [062] 0x0080fc (16 B), [054] 0x00810c (204 B),
// [081] 0x0081d8 (20 B), [076] 0x0081ec (288 B), [073] 0x00830c (76 B),
// [064] 0x008358 (204 B), [082] 0x008424 (24 B), [058] 0x00843c (20 B),
// [065] 0x008450 (20 B), [077] 0x008464 (204 B), [059] 0x0086b0 (164 B),
// [096] 0x008754 (32 B), [066] 0x008774 (28 B), [067] 0x008790 (24 B),
// [078] 0x0087a8 (24 B), [074] 0x0087c0 (24 B)
// Nhóm hàm truy vấn siêu dữ liệu, kích thước, thời lượng, bộ nhớ và trạng thái lưu
void       Java_pl_droidsonroids_gif_GifInfoHandle_setOptions(JNIEnv* env, jclass clazz, jlong gifInfo, jchar sampleSize, jboolean isOpaque);
jstring    Java_pl_droidsonroids_gif_GifInfoHandle_getComment(JNIEnv* env, jclass clazz, jlong gifInfo);
jboolean   Java_pl_droidsonroids_gif_GifInfoHandle_isAnimationCompleted(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getLoopCount(JNIEnv* env, jclass clazz, jlong gifInfo);
void       Java_pl_droidsonroids_gif_GifInfoHandle_setLoopCount(JNIEnv* env, jclass clazz, jlong gifInfo, jchar loopCount);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getDuration(JNIEnv* env, jclass clazz, jlong gifInfo);
jlong      Java_pl_droidsonroids_gif_GifInfoHandle_getSourceLength(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentPosition(JNIEnv* env, jclass clazz, jlong gifInfo);
jlong      Java_pl_droidsonroids_gif_GifInfoHandle_getMetadataByteCount(JNIEnv* env, jclass clazz, jlong gifInfo);
jlong      Java_pl_droidsonroids_gif_GifInfoHandle_getAllocationByteCount(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getNativeErrorCode(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentLoop(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getCurrentFrameIndex(JNIEnv* env, jclass clazz, jlong gifInfo);
jlongArray Java_pl_droidsonroids_gif_GifInfoHandle_getSavedState(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_restoreSavedState(JNIEnv* env, jclass clazz, jlong gifInfo, jlongArray savedState, jobject jbitmap);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getFrameDuration(JNIEnv* env, jclass clazz, jlong gifInfo, jint index);
jboolean   Java_pl_droidsonroids_gif_GifInfoHandle_isOpaque(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getWidth(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getHeight(JNIEnv* env, jclass clazz, jlong gifInfo);
jint       Java_pl_droidsonroids_gif_GifInfoHandle_getNumberOfFrames(JNIEnv* env, jclass clazz, jlong gifInfo);

// [060] 0x0087d8 (164 B), [090] 0x00887c (164 B), [091] 0x008920 (192 B),
// [095] 0x0089e0 (200 B), [092] 0x008c0c (20 B), [071] 0x008cbc (32 B),
// [055] 0x008cdc (1560 B), [075] 0x0094c0 (136 B)
// Nhóm hàm kết cấu OpenGL ES 2.0 (glTexImage2D / glTexSubImage2D) và bề mặt ANativeWindow
void Java_pl_droidsonroids_gif_GifInfoHandle_glTexImage2D(JNIEnv* env, jclass clazz, jlong gifInfo, jint target, jint level);
void Java_pl_droidsonroids_gif_GifInfoHandle_glTexSubImage2D(JNIEnv* env, jclass clazz, jlong gifInfo, jint target, jint level);
void Java_pl_droidsonroids_gif_GifInfoHandle_initTexImageDescriptor(JNIEnv* env, jclass clazz, jlong gifInfo);
void Java_pl_droidsonroids_gif_GifInfoHandle_startDecoderThread(JNIEnv* env, jclass clazz, jlong gifInfo);
void Java_pl_droidsonroids_gif_GifInfoHandle_stopDecoderThread(JNIEnv* env, jclass clazz, jlong gifInfo);
void Java_pl_droidsonroids_gif_GifInfoHandle_seekToFrameGL(JNIEnv* env, jclass clazz, jlong gifInfo, jint desiredIndex);
void Java_pl_droidsonroids_gif_GifInfoHandle_bindSurface(JNIEnv* env, jclass clazz, jlong gifInfo, jobject jsurface, jlongArray savedState);
void Java_pl_droidsonroids_gif_GifInfoHandle_postUnbindSurface(JNIEnv* env, jclass clazz, jlong gifInfo);

#ifdef __cplusplus
} // extern "C"
#endif
