/**
 * @file imagepipeline_fresco_jni.h
 * @brief Clean-Room C++17 Declarations for Facebook Fresco ImagePipeline Native Modules in libimagepipeline.so
 *        Khai báo C++17 cho 4 mô-đun gốc JNI của Facebook Fresco ImagePipeline trong libimagepipeline.so:
 *          1. JNI_OnLoad & Exception Helper (0x001ffc..0x00232c)
 *          2. NativeJpegTranscoder, Stream Wrappers & Orientation Mappers (0x00232c..0x003710)
 *          3. Bitmaps & DalvikPurgeableDecoder (0x03726c..0x0376c0)
 *          4. NativeMemoryChunk (0x0376c0..0x037814)
 */

#ifndef NEXTAI_OPENCUT_IMAGEPIPELINE_FRESCO_JNI_H_
#define NEXTAI_OPENCUT_IMAGEPIPELINE_FRESCO_JNI_H_

#include "imagepipeline_types.h"
#include "imagepipeline_rodata_tables.h"

namespace nextai {
namespace opencut {
namespace imagepipeline {

// ============================================================================
// 1. GLOBAL .bss STATE (vaddr 0x0440f0..0x044128, 56 bytes)
//    TRẠNG THÁI TOÀN CỤC TRONG PHÂN ĐOẠN .bss (0x0440f0..0x044128)
// ============================================================================

struct ImagePipelineBssState {
    jmethodID is_read_method_id;        ///< 0x0440f0: InputStream.read([B)I
    jmethodID is_skip_method_id;        ///< 0x0440f8: InputStream.skip(J)J
    jmethodID os_write_bytes_method_id; ///< 0x044100: OutputStream.write([B)V
    jmethodID os_write_range_method_id; ///< 0x044108: OutputStream.write([BII)V
    jclass    jRuntimeException_main;   ///< 0x044110: GlobalRef java/lang/RuntimeException (JNI_OnLoad & JpegTranscoder)
    jclass    jRuntimeException_bitmaps;///< 0x044118: GlobalRef java/lang/RuntimeException (Bitmaps & DalvikPurgeableDecoder)
    jclass    jRuntimeException_nmc;    ///< 0x044120: GlobalRef java/lang/RuntimeException (NativeMemoryChunk)
};

extern ImagePipelineBssState gImagePipelineBss;

// ============================================================================
// 2. EXPORTED ENTRYPOINT & EXCEPTION HELPERS (0x001ffc..0x00232c)
//    ĐIỂM VÀO XUẤT KHẨU JNI_OnLoad & HÀM NÉM NGOẠI LỆ AN TOÀN (0x001ffc..0x00232c)
// ============================================================================

extern "C" {
    /**
     * @brief Standard Android JNI_OnLoad entrypoint (.text 0x002060..0x00232c, 716 bytes).
     *        Điểm vào chuẩn JNI_OnLoad (.text 0x002060..0x00232c, 716 byte).
     */
    jint JNI_OnLoad(JavaVM* vm, void* reserved);
}

/**
 * @brief Safely throws a Java exception if no exception is currently pending (`0x001ffc..0x002060`).
 *        Ném ngoại lệ Java an toàn nếu luồng hiện tại chưa có ngoại lệ chờ xử lý (`0x001ffc..0x002060`).
 */
void safeThrowJavaException(JNIEnv* env, jclass exception_clazz, const char* msg) noexcept;

// ============================================================================
// 3. NATIVE JPEG TRANSCODER & STREAM WRAPPERS (0x00232c..0x003710)
//    BỘ CHUYỂN MÃ JPEG GỐC & CÁC LỚP BAO LUỒNG DỮ LIỆU (0x00232c..0x003710)
// ============================================================================

/**
 * @brief Top-level JPEG transcoding pipeline combining optional DCT downscaling and lossless DCT rotation (`0x00232c..0x0024e0`).
 *        Đường ống chuyển mã JPEG kết hợp thu phóng DCT và xoay khối DCT không suy hao (`0x00232c..0x0024e0`).
 */
void transcodeJpeg(JNIEnv* env,
                   jobject input_stream,
                   jobject output_stream,
                   JXFORM_CODE rotation_xform,
                   ScaleFactor scale_factor,
                   jint quality) noexcept;

/**
 * @brief Downscales a JPEG stream using libjpeg IDCT scaling (`numerator / 8`) and re-encodes at `quality` (`0x0024e0..0x00277c`).
 *        Thu phóng luồng JPEG bằng IDCT tỷ lệ (`numerator / 8`) và mã hóa lại với chất lượng `quality` (`0x0024e0..0x00277c`).
 */
void downscaleJpeg(JNIEnv* env,
                   jpeg_source_mgr* src_mgr,
                   jpeg_destination_mgr* dst_mgr,
                   ScaleFactor scale_factor,
                   jint quality) noexcept;

/**
 * @brief Losslessly rotates/flips a JPEG stream in the DCT frequency domain via `jtransform_*` (`0x00277c..0x00294c`).
 *        Xoay/lật không suy hao luồng JPEG trong miền tần số DCT qua `jtransform_*` (`0x00277c..0x00294c`).
 */
void rotateJpeg(JNIEnv* env,
                jpeg_source_mgr* src_mgr,
                jpeg_destination_mgr* dst_mgr,
                FrescoRotationType rotation_type) noexcept;

void jpegErrorHandlerInit(JpegErrorHandler* handler, JNIEnv* env) noexcept;
void jpegErrorExit(jpeg_common_struct* cinfo) noexcept;
void jpegErrorHandlerSetDecompress(JpegErrorHandler* handler, jpeg_decompress_struct* dinfo) noexcept;
void jpegErrorHandlerSetCompress(JpegErrorHandler* handler, jpeg_compress_struct* cinfo) noexcept;
void jpegThrowExceptionAndLongjmp(jpeg_common_struct* cinfo, const char* message) noexcept;
void jpegCleanupAndLongjmp(JpegErrorHandler* handler) noexcept;
void jpegCheckExceptionAndCleanup(jpeg_common_struct* cinfo) noexcept;

void jpegMemorySourceInit(JpegMemorySourceWrapper* src) noexcept;
void jpegMemoryDestInit(JpegMemoryDestinationWrapper* dst) noexcept;
void jpegInputStreamWrapperInit(JpegInputStreamWrapper* src, JNIEnv* env, jobject is) noexcept;
void jpegOutputStreamWrapperInit(JpegOutputStreamWrapper* dst, JNIEnv* env, jobject os) noexcept;

/**
 * @brief Maps clockwise degrees `{0, 90, 180, 270}` to `FrescoRotationType` (`0x003468..0x0034dc`).
 *        Ánh xạ góc xoay `{0, 90, 180, 270}` sang `FrescoRotationType` (`0x003468..0x0034dc`).
 */
FrescoRotationType getRotationTypeFromDegrees(JNIEnv* env, uint16_t degrees) noexcept;

/**
 * @brief Maps EXIF orientation tag `1..8` to `FrescoRotationType` via `.rodata 0x037c00` (`0x0034dc..0x003530`).
 *        Ánh xạ thẻ hướng EXIF `1..8` sang `FrescoRotationType` qua bảng `.rodata 0x037c00` (`0x0034dc..0x003530`).
 */
FrescoRotationType getRotationTypeFromExifOrientation(JNIEnv* env, uint16_t exif_orientation) noexcept;

/**
 * @brief Registers the 2 native methods of `NativeJpegTranscoder` (`0x003530..0x0035b8`).
 *        Đăng ký 2 phương thức gốc của lớp `NativeJpegTranscoder` (`0x003530..0x0035b8`).
 */
bool registerJpegTranscoderMethods(JNIEnv* env) noexcept;

void NativeJpegTranscoder_transcodeJpeg(JNIEnv* env,
                                        jclass clazz,
                                        jobject input_stream,
                                        jobject output_stream,
                                        jint rotation_degrees,
                                        jint scale_numerator,
                                        jint quality) noexcept;

void NativeJpegTranscoder_transcodeJpegWithExifOrientation(JNIEnv* env,
                                                           jclass clazz,
                                                           jobject input_stream,
                                                           jobject output_stream,
                                                           jint exif_orientation,
                                                           jint scale_numerator,
                                                           jint quality) noexcept;

// ============================================================================
// 4. BITMAPS, DALVIK PURGEABLE DECODER & NATIVE MEMORY CHUNK (0x03726c..0x037814)
//    SAO CHÉP BITMAP, GHIM ASHMEM BITMAP & KHỐI BỘ NHỚ GỐC (0x03726c..0x037814)
// ============================================================================

jint registerBitmapsMethods(JNIEnv* env) noexcept;
jint registerDalvikPurgeableDecoderMethods(JNIEnv* env) noexcept;
jint registerNativeMemoryChunkMethods(JNIEnv* env) noexcept;

void Bitmaps_copyBitmap(JNIEnv* env,
                        jclass clazz,
                        jobject dest_bitmap,
                        jint dest_stride,
                        jobject src_bitmap,
                        jint src_stride,
                        jint rows) noexcept;

void DalvikPurgeableDecoder_nativePinBitmap(JNIEnv* env,
                                            jclass clazz,
                                            jobject bitmap) noexcept;

jlong NativeMemoryChunk_nativeAllocate(JNIEnv* env, jclass clazz, jint size) noexcept;
void  NativeMemoryChunk_nativeFree(JNIEnv* env, jclass clazz, jlong lpointer) noexcept;
void  NativeMemoryChunk_nativeCopyToByteArray(JNIEnv* env, jclass clazz, jlong lpointer, jbyteArray byte_array, jint offset, jint count) noexcept;
void  NativeMemoryChunk_nativeCopyFromByteArray(JNIEnv* env, jclass clazz, jlong lpointer, jbyteArray byte_array, jint offset, jint count) noexcept;
void  NativeMemoryChunk_nativeMemcpy(JNIEnv* env, jclass clazz, jlong dst_ptr, jlong src_ptr, jint count) noexcept;
jbyte NativeMemoryChunk_nativeReadByte(JNIEnv* env, jclass clazz, jlong lpointer) noexcept;

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai

#endif // NEXTAI_OPENCUT_IMAGEPIPELINE_FRESCO_JNI_H_
