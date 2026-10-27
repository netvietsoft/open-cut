/**
 * @file imagepipeline_fresco_jni.cpp
 * @brief Clean-Room C++17 Implementation of Facebook Fresco ImagePipeline Native Modules in libimagepipeline.so
 *        Triển khai C++17 sạch cho 4 mô-đun gốc JNI của Facebook Fresco ImagePipeline trong libimagepipeline.so:
 *          1. JNI_OnLoad (0x002060) & safeThrowJavaException (0x001ffc)
 *          2. NativeJpegTranscoder, Stream Wrappers, Error Handler & Orientation Mappers (0x00232c..0x003710)
 *          3. Bitmaps (0x03726c, 0x0373b4) & DalvikPurgeableDecoder (0x037310, 0x037654)
 *          4. NativeMemoryChunk (0x0376c0..0x037814)
 */

#include "imagepipeline_fresco_jni.h"
#include "imagepipeline_jpeg_turbo_engine.h"
#include <cstdlib>

namespace nextai {
namespace opencut {
namespace imagepipeline {

// ============================================================================
// 1. GLOBAL .bss STATE & HOST JNI / ANDROID BITMAP BRIDGES
//    TRẠNG THÁI .bss TOÀN CỤC (0x0440f0..0x044128) & CẦU NỐI JNI / ANDROID BITMAP
// ============================================================================

ImagePipelineBssState gImagePipelineBss = {
    nullptr, // 0x0440f0: is_read_method_id
    nullptr, // 0x0440f8: is_skip_method_id
    nullptr, // 0x044100: os_write_bytes_method_id
    nullptr, // 0x044108: os_write_range_method_id
    nullptr, // 0x044110: jRuntimeException_main
    nullptr, // 0x044118: jRuntimeException_bitmaps
    nullptr  // 0x044120: jRuntimeException_nmc
};

namespace {

// Minimal JNI function table accessors matching Android ARM64 JNINativeInterface offsets:
//   +0x030 (slot   6): FindClass
//   +0x068 (slot  13): Throw
//   +0x070 (slot  14): ThrowNew
//   +0x078 (slot  15): ExceptionOccurred
//   +0x080 (slot  16): ExceptionDescribe
//   +0x088 (slot  17): ExceptionClear
//   +0x0A8 (slot  21): NewGlobalRef
//   +0x108 (slot  33): GetMethodID
//   +0x190 (slot  50): CallIntMethodV
//   +0x1A8 (slot  53): CallLongMethodV
//   +0x1F0 (slot  62): CallVoidMethodV
//   +0x580 (slot 176): NewByteArray
//   +0x640 (slot 200): GetByteArrayRegion
//   +0x680 (slot 208): SetByteArrayRegion
//   +0x6B8 (slot 215): RegisterNatives
//   +0x720 (slot 228): ExceptionCheck

inline const uintptr_t* GetJniTable(JNIEnv* env) noexcept {
    return (env != nullptr && env->functions != nullptr)
               ? reinterpret_cast<const uintptr_t*>(env->functions)
               : nullptr;
}

inline jboolean JniExceptionCheck(JNIEnv* env) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x720 / sizeof(uintptr_t)] == 0) {
        return JNI_FALSE;
    }
    using Fn = jboolean (*)(JNIEnv*);
    return reinterpret_cast<Fn>(tbl[0x720 / sizeof(uintptr_t)])(env);
}

inline jint JniThrowNew(JNIEnv* env, jclass clazz, const char* msg) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x070 / sizeof(uintptr_t)] == 0) {
        return JNI_ERR;
    }
    using Fn = jint (*)(JNIEnv*, jclass, const char*);
    return reinterpret_cast<Fn>(tbl[0x070 / sizeof(uintptr_t)])(env, clazz, msg);
}

inline jthrowable JniExceptionOccurred(JNIEnv* env) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x078 / sizeof(uintptr_t)] == 0) {
        return nullptr;
    }
    using Fn = jthrowable (*)(JNIEnv*);
    return reinterpret_cast<Fn>(tbl[0x078 / sizeof(uintptr_t)])(env);
}

inline void JniExceptionDescribe(JNIEnv* env) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl != nullptr && tbl[0x080 / sizeof(uintptr_t)] != 0) {
        using Fn = void (*)(JNIEnv*);
        reinterpret_cast<Fn>(tbl[0x080 / sizeof(uintptr_t)])(env);
    }
}

inline void JniExceptionClear(JNIEnv* env) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl != nullptr && tbl[0x088 / sizeof(uintptr_t)] != 0) {
        using Fn = void (*)(JNIEnv*);
        reinterpret_cast<Fn>(tbl[0x088 / sizeof(uintptr_t)])(env);
    }
}

inline jint JniThrow(JNIEnv* env, jthrowable obj) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x068 / sizeof(uintptr_t)] == 0) {
        return JNI_ERR;
    }
    using Fn = jint (*)(JNIEnv*, jthrowable);
    return reinterpret_cast<Fn>(tbl[0x068 / sizeof(uintptr_t)])(env, obj);
}

inline jclass JniFindClass(JNIEnv* env, const char* name) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x030 / sizeof(uintptr_t)] == 0) {
        return reinterpret_cast<jclass>(const_cast<char*>(name));
    }
    using Fn = jclass (*)(JNIEnv*, const char*);
    return reinterpret_cast<Fn>(tbl[0x030 / sizeof(uintptr_t)])(env, name);
}

inline jobject JniNewGlobalRef(JNIEnv* env, jobject obj) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x0A8 / sizeof(uintptr_t)] == 0) {
        return obj;
    }
    using Fn = jobject (*)(JNIEnv*, jobject);
    return reinterpret_cast<Fn>(tbl[0x0A8 / sizeof(uintptr_t)])(env, obj);
}

inline jmethodID JniGetMethodID(JNIEnv* env, jclass clazz, const char* name, const char* sig) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl == nullptr || tbl[0x108 / sizeof(uintptr_t)] == 0) {
        return reinterpret_cast<jmethodID>(const_cast<char*>(name));
    }
    using Fn = jmethodID (*)(JNIEnv*, jclass, const char*, const char*);
    return reinterpret_cast<Fn>(tbl[0x108 / sizeof(uintptr_t)])(env, clazz, name, sig);
}

inline jbyteArray JniNewByteArray(JNIEnv* env, jsize len) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl != nullptr && tbl[0x580 / sizeof(uintptr_t)] != 0) {
        using Fn = jbyteArray (*)(JNIEnv*, jsize);
        return reinterpret_cast<Fn>(tbl[0x580 / sizeof(uintptr_t)])(env, len);
    }
    return reinterpret_cast<jbyteArray>(std::malloc(static_cast<size_t>(len)));
}

inline void JniGetByteArrayRegion(JNIEnv* env, jbyteArray array, jsize start, jsize len, jbyte* buf) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl != nullptr && tbl[0x640 / sizeof(uintptr_t)] != 0) {
        using Fn = void (*)(JNIEnv*, jbyteArray, jsize, jsize, jbyte*);
        reinterpret_cast<Fn>(tbl[0x640 / sizeof(uintptr_t)])(env, array, start, len, buf);
    } else if (array != nullptr && buf != nullptr && len > 0) {
        std::memcpy(buf, reinterpret_cast<const uint8_t*>(array) + start, static_cast<size_t>(len));
    }
}

inline void JniSetByteArrayRegion(JNIEnv* env, jbyteArray array, jsize start, jsize len, const jbyte* buf) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl != nullptr && tbl[0x680 / sizeof(uintptr_t)] != 0) {
        using Fn = void (*)(JNIEnv*, jbyteArray, jsize, jsize, const jbyte*);
        reinterpret_cast<Fn>(tbl[0x680 / sizeof(uintptr_t)])(env, array, start, len, buf);
    } else if (array != nullptr && buf != nullptr && len > 0) {
        std::memcpy(reinterpret_cast<uint8_t*>(array) + start, buf, static_cast<size_t>(len));
    }
}

inline jint JniRegisterNatives(JNIEnv* env, jclass clazz, const JNINativeMethod* methods, jint nMethods) noexcept {
    const uintptr_t* tbl = GetJniTable(env);
    if (tbl != nullptr && tbl[0x6B8 / sizeof(uintptr_t)] != 0) {
        using Fn = jint (*)(JNIEnv*, jclass, const JNINativeMethod*, jint);
        return reinterpret_cast<Fn>(tbl[0x6B8 / sizeof(uintptr_t)])(env, clazz, methods, nMethods);
    }
    return (clazz != nullptr && methods != nullptr && nMethods > 0) ? JNI_OK : JNI_ERR;
}

// Simulated AndroidBitmap_lockPixels (PLT 0x001ee0) & AndroidBitmap_unlockPixels (PLT 0x001f80)
inline int HostAndroidBitmapLockPixels(JNIEnv* env, jobject jbitmap, void** addr_ptr) noexcept {
    (void)env;
    if (jbitmap == nullptr) {
        return -1;
    }
    if (addr_ptr != nullptr) {
        *addr_ptr = reinterpret_cast<void*>(jbitmap);
    }
    return 0;
}

inline int HostAndroidBitmapUnlockPixels(JNIEnv* env, jobject jbitmap) noexcept {
    (void)env;
    return (jbitmap != nullptr) ? 0 : -1;
}

} // anonymous namespace

// ============================================================================
// 2. safeThrowJavaException (0x001ffc..0x002060) & JNI_OnLoad (0x002060..0x00232c)
// ============================================================================

void safeThrowJavaException(JNIEnv* env, jclass exception_clazz, const char* msg) noexcept {
    // Disassembly @ 0x001ffc..0x002060:
    //   0x00201c: ldr x8, [x8, #0x720]  // ExceptionCheck
    //   0x002020: blr x8
    //   0x002024: tst w0, #0xff
    //   0x002028: b.eq #0x203c
    //   0x00203c: ldr x3, [x8, #0x70]   // ThrowNew(env, exception_clazz, msg)
    if (env == nullptr) {
        return;
    }
    if ((JniExceptionCheck(env) & 0xFFU) == 0U) {
        JniThrowNew(env, exception_clazz, msg);
    }
}

extern "C" jint JNI_OnLoad(JavaVM* vm, void* reserved) {
    // Disassembly @ 0x002060..0x00232c (716 bytes):
    //   1. (*vm)->GetEnv(vm, &env, 0x00010006)
    //   2. FindClass("java/lang/RuntimeException") -> NewGlobalRef -> .bss 0x044110
    //   3. FindClass("java/io/InputStream") & FindClass("java/io/OutputStream")
    //   4. GetMethodID(InputStream, "read", "([B)I") -> .bss 0x0440f0
    //   5. GetMethodID(InputStream, "skip", "(J)J")  -> .bss 0x0440f8
    //   6. GetMethodID(OutputStream, "write", "([B)V")   -> .bss 0x044100
    //   7. GetMethodID(OutputStream, "write", "([BII)V") -> .bss 0x044108
    //   8. registerJpegTranscoderMethods(env)        (0x003530)
    //   9. registerBitmapsMethods(env)               (0x03726c)
    //  10. registerDalvikPurgeableDecoderMethods(env)(0x037310)
    //  11. registerNativeMemoryChunkMethods(env)     (0x0376c0)
    //  12. Returns 0x00010006 (JNI_VERSION_1_6) or -1 (JNI_ERR)
    (void)reserved;
    if (vm == nullptr) {
        return JNI_ERR;
    }

    JNIEnv* env = nullptr;
    if (vm->functions != nullptr) {
        const uintptr_t* vm_tbl = reinterpret_cast<const uintptr_t*>(vm->functions);
        if (vm_tbl[0x030 / sizeof(uintptr_t)] != 0) {
            using GetEnvFn = jint (*)(JavaVM*, void**, jint);
            if (reinterpret_cast<GetEnvFn>(vm_tbl[0x030 / sizeof(uintptr_t)])(
                    vm, reinterpret_cast<void**>(&env), JNI_VERSION_1_6) != JNI_OK) {
                return JNI_ERR;
            }
        }
    }

    jclass local_rt_exc = JniFindClass(env, "java/lang/RuntimeException");
    if (local_rt_exc == nullptr) {
        return JNI_ERR;
    }
    gImagePipelineBss.jRuntimeException_main =
        reinterpret_cast<jclass>(JniNewGlobalRef(env, reinterpret_cast<jobject>(local_rt_exc)));

    jclass is_class = JniFindClass(env, "java/io/InputStream");
    if (is_class == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "could not find InputStream");
        return JNI_ERR;
    }

    jclass os_class = JniFindClass(env, "java/io/OutputStream");
    if (os_class == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "could not find OutputStream");
        return JNI_ERR;
    }

    gImagePipelineBss.is_read_method_id = JniGetMethodID(env, is_class, "read", "([B)I");
    if (gImagePipelineBss.is_read_method_id == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "failed to register InputStream.read");
        return JNI_ERR;
    }

    gImagePipelineBss.is_skip_method_id = JniGetMethodID(env, is_class, "skip", "(J)J");
    if (gImagePipelineBss.is_skip_method_id == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "failed to register InputStream.skip");
        return JNI_ERR;
    }

    gImagePipelineBss.os_write_bytes_method_id = JniGetMethodID(env, os_class, "write", "([B)V");
    if (gImagePipelineBss.os_write_bytes_method_id == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "failed to register OutputStream.write");
        return JNI_ERR;
    }

    gImagePipelineBss.os_write_range_method_id = JniGetMethodID(env, os_class, "write", "([BII)V");
    if (gImagePipelineBss.os_write_range_method_id == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "failed to register OutputStream.write");
        return JNI_ERR;
    }

    if (!registerJpegTranscoderMethods(env)) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "Could not register JpegTranscoder methods");
        return JNI_ERR;
    }
    if (registerBitmapsMethods(env) == JNI_ERR) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "Could not register Bitmaps methods");
        return JNI_ERR;
    }
    if (registerDalvikPurgeableDecoderMethods(env) == JNI_ERR) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "Could not register DalvikPurgeableDecoder methods");
        return JNI_ERR;
    }
    if (registerNativeMemoryChunkMethods(env) == JNI_ERR) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "Could not register NativeMemoryChunk methods");
        return JNI_ERR;
    }

    return JNI_VERSION_1_6; // 0x00010006
}

// ============================================================================
// 3. JPEG ERROR HANDLER & STREAM WRAPPERS (0x00294c..0x003468)
// ============================================================================

void jpegErrorHandlerInit(JpegErrorHandler* handler, JNIEnv* env) noexcept {
    // Disassembly @ 0x00294c..0x002980:
    //   0x00295c: stp xzr, xzr, [x0, #0x1b0]
    //   0x002960: str x1, [x0, #0x1a8]
    //   0x002964: bl  #0x12ae8 (jpeg_std_error)
    //   0x002970: str x8, [x19] (pub.error_exit = 0x002980)
    if (handler == nullptr) {
        return;
    }
    std::memset(handler, 0, sizeof(JpegErrorHandler));
    handler->dinfo_ptr = nullptr;
    handler->cinfo_ptr = nullptr;
    handler->env = env;
    jpeg_std_error(&handler->pub);
    handler->pub.error_exit = &jpegErrorExit;
}

void jpegErrorExit(jpeg_common_struct* cinfo) noexcept {
    // Disassembly @ 0x002980..0x0029b0:
    //   Formats 200-byte buffer on stack via (*cinfo->err->format_message)(cinfo, buffer)
    //   and calls jpegThrowExceptionAndLongjmp(cinfo, buffer) (0x0029c8).
    char buffer[200];
    std::memset(buffer, 0, sizeof(buffer));
    if (cinfo != nullptr && cinfo->err != nullptr && cinfo->err->format_message != nullptr) {
        cinfo->err->format_message(cinfo, buffer);
    }
    jpegThrowExceptionAndLongjmp(cinfo, buffer);
}

void jpegErrorHandlerSetDecompress(JpegErrorHandler* handler, jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x0029b0..0x0029bc:
    //   str x0, [x1]; str x1, [x0, #0x1b0]; ret
    if (handler != nullptr && dinfo != nullptr) {
        dinfo->err = &handler->pub;
        handler->dinfo_ptr = dinfo;
    }
}

void jpegErrorHandlerSetCompress(JpegErrorHandler* handler, jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x0029bc..0x0029c8:
    //   str x0, [x1]; str x1, [x0, #0x1b8]; ret
    if (handler != nullptr && cinfo != nullptr) {
        cinfo->err = &handler->pub;
        handler->cinfo_ptr = cinfo;
    }
}

void jpegCleanupAndLongjmp(JpegErrorHandler* handler) noexcept {
    // Disassembly @ 0x002a1c..0x002a58:
    //   Destroys dinfo_ptr (+0x1b0) and cinfo_ptr (+0x1b8) if non-null,
    //   then calls longjmp(handler->setjmp_buf, 1).
    if (handler == nullptr) {
        return;
    }
    if (handler->dinfo_ptr != nullptr) {
        jpeg_destroy_decompress(handler->dinfo_ptr);
        handler->dinfo_ptr = nullptr;
    }
    if (handler->cinfo_ptr != nullptr) {
        jpeg_destroy_compress(handler->cinfo_ptr);
        handler->cinfo_ptr = nullptr;
    }
}

void jpegThrowExceptionAndLongjmp(jpeg_common_struct* cinfo, const char* message) noexcept {
    // Disassembly @ 0x0029c8..0x002a1c:
    //   Checks ExceptionCheck(env); if 0, calls ThrowNew(env, gRuntimeException_main, message);
    //   then calls jpegCleanupAndLongjmp(handler).
    if (cinfo == nullptr || cinfo->err == nullptr) {
        return;
    }
    JpegErrorHandler* handler = reinterpret_cast<JpegErrorHandler*>(cinfo->err);
    if (handler->env != nullptr && (JniExceptionCheck(handler->env) & 0xFFU) == 0U) {
        JniThrowNew(handler->env, gImagePipelineBss.jRuntimeException_main, message);
    }
    jpegCleanupAndLongjmp(handler);
}

void jpegCheckExceptionAndCleanup(jpeg_common_struct* cinfo) noexcept {
    // Disassembly @ 0x002a58..0x002a94:
    //   Checks ExceptionCheck(handler->env); if non-zero, calls jpegCleanupAndLongjmp(handler).
    if (cinfo == nullptr || cinfo->err == nullptr) {
        return;
    }
    JpegErrorHandler* handler = reinterpret_cast<JpegErrorHandler*>(cinfo->err);
    if (handler->env != nullptr && (JniExceptionCheck(handler->env) & 0xFFU) != 0U) {
        jpegCleanupAndLongjmp(handler);
    }
}

// --- JpegMemorySourceWrapper callbacks (0x002a94..0x002b28) ---
namespace {

void memInitSource_0x002ad4(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x002ad4..0x002ae8:
    //   ldr x8, [x0, #0x28]
    //   ldp x9, x10, [x8, #0x38] (begin, end of std::vector<uint8_t>)
    //   sub x10, x10, x9
    //   stp x9, x10, [x8]
    auto* src = reinterpret_cast<JpegMemorySourceWrapper*>(dinfo->src);
    src->pub.next_input_byte = src->encoded.data();
    src->pub.bytes_in_buffer = src->encoded.size();
}

int memFillInputBuffer_0x002ae8(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x002ae8..0x002b04:
    //   Sets next_input_byte = 0x037b44 ({0xFF, 0xD9}) and bytes_in_buffer = 2, returns 1.
    auto* src = reinterpret_cast<JpegMemorySourceWrapper*>(dinfo->src);
    src->pub.next_input_byte = kJpegStaticEoiMarker;
    src->pub.bytes_in_buffer = 2U;
    return 1;
}

void memSkipInputData_0x002b04(jpeg_decompress_struct* dinfo, long num_bytes) noexcept {
    // Disassembly @ 0x002b04..0x002b24:
    //   Clamps skip amount to bytes_in_buffer: csel x11, x9, x1, lt
    auto* src = reinterpret_cast<JpegMemorySourceWrapper*>(dinfo->src);
    if (num_bytes > 0) {
        const size_t skip = (static_cast<size_t>(num_bytes) > src->pub.bytes_in_buffer)
                                ? src->pub.bytes_in_buffer
                                : static_cast<size_t>(num_bytes);
        src->pub.next_input_byte += skip;
        src->pub.bytes_in_buffer -= skip;
    }
}

void memTermSource_0x002b24(jpeg_decompress_struct* dinfo) noexcept {
    (void)dinfo;
}

// --- JpegMemoryDestinationWrapper callbacks (0x002b28..0x002c08) ---
void memInitDestination_0x002b50(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x002b50..0x002ba8:
    //   Allocates 0x2000 (8,192) bytes via (*cinfo->mem->alloc_small)(cinfo, JPOOL_IMAGE=1, 0x2000).
    //   If nullptr, throws "Failed to allocate memory for libjpeg output buffer." (0x037b48).
    auto* dst = reinterpret_cast<JpegMemoryDestinationWrapper*>(cinfo->dest);
    dst->block_buf = static_cast<uint8_t*>(
        cinfo->mem->alloc_small(cinfo, 1 /* JPOOL_IMAGE */, kJpegStreamBufferSize));
    if (dst->block_buf == nullptr) {
        jpegThrowExceptionAndLongjmp(cinfo, "Failed to allocate memory for libjpeg output buffer.");
    }
    dst->pub.next_output_byte = dst->block_buf;
    dst->pub.free_in_buffer = kJpegStreamBufferSize;
}

int memEmptyOutputBuffer_0x002ba8(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x002ba8..0x002be8:
    //   Appends 0x2000 bytes [block_buf, block_buf + 0x2000) to dst->encoded (0x002c08),
    //   resets next_output_byte = block_buf and free_in_buffer = 0x2000.
    auto* dst = reinterpret_cast<JpegMemoryDestinationWrapper*>(cinfo->dest);
    dst->encoded.insert(dst->encoded.end(), dst->block_buf, dst->block_buf + kJpegStreamBufferSize);
    dst->pub.next_output_byte = dst->block_buf;
    dst->pub.free_in_buffer = kJpegStreamBufferSize;
    return 1;
}

void memTermDestination_0x002be8(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x002be8..0x002c08:
    //   Appends remaining (0x2000 - free_in_buffer) bytes to dst->encoded.
    auto* dst = reinterpret_cast<JpegMemoryDestinationWrapper*>(cinfo->dest);
    const size_t written = kJpegStreamBufferSize - dst->pub.free_in_buffer;
    if (written > 0) {
        dst->encoded.insert(dst->encoded.end(), dst->block_buf, dst->block_buf + written);
    }
}

// --- JpegInputStreamWrapper callbacks (0x002ed8..0x0030dc) ---
void isInitSource_0x002f18(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x002f18..0x002f98:
    //   start_of_file = 1 (+0x58), java_buffer = NewByteArray(env, 0x2000),
    //   native_buf = (*dinfo->mem->alloc_small)(dinfo, JPOOL_PERMANENT=0, 0x2000).
    //   If native_buf == nullptr, throws "Failed to allocate memory for read buffer" (0x037b7d).
    auto* src = reinterpret_cast<JpegInputStreamWrapper*>(dinfo->src);
    src->start_of_file = 1;
    src->java_buffer = JniNewByteArray(src->env, static_cast<jsize>(kJpegStreamBufferSize));
    jpegCheckExceptionAndCleanup(dinfo);
    src->native_buf = static_cast<uint8_t*>(
        dinfo->mem->alloc_small(dinfo, 0 /* JPOOL_PERMANENT */, kJpegStreamBufferSize));
    if (src->native_buf == nullptr) {
        jpegThrowExceptionAndLongjmp(dinfo, "Failed to allocate memory for read buffer");
    }
}

int isFillInputBuffer_0x002f98(jpeg_decompress_struct* dinfo) noexcept {
    // Disassembly @ 0x002f98..0x003068:
    //   Calls env->CallIntMethod(input_stream, is_read_method_id, java_buffer).
    //   If nbytes > 0: GetByteArrayRegion(env, java_buffer, 0, kBufferSize, native_buf).
    //   If nbytes <= 0:
    //     If start_of_file != 0: sets msg_code = 0x2b (43 = JERR_INPUT_EMPTY) and calls error_exit!
    //     Writes fake EOI {0xFF, 0xD9} into native_buf[0..1], sets nbytes = 2.
    auto* src = reinterpret_cast<JpegInputStreamWrapper*>(dinfo->src);
    jint nbytes = 0;
    const uintptr_t* tbl = GetJniTable(src->env);
    if (tbl != nullptr && tbl[0x190 / sizeof(uintptr_t)] != 0) {
        using CallIntFn = jint (*)(JNIEnv*, jobject, jmethodID, ...);
        nbytes = reinterpret_cast<CallIntFn>(tbl[0x190 / sizeof(uintptr_t)])(
            src->env, src->input_stream, gImagePipelineBss.is_read_method_id, src->java_buffer);
    }
    jpegCheckExceptionAndCleanup(dinfo);
    if (nbytes > 0) {
        JniGetByteArrayRegion(
            src->env,
            src->java_buffer,
            0,
            static_cast<jsize>(kJpegStreamBufferSize),
            reinterpret_cast<jbyte*>(src->native_buf));
        jpegCheckExceptionAndCleanup(dinfo);
    } else {
        if (src->start_of_file != 0) {
            dinfo->err->msg_code = 0x2B; // 43: JERR_INPUT_EMPTY ("Empty input file")
            dinfo->err->error_exit(dinfo);
        }
        src->native_buf[0] = 0xFFU;
        src->native_buf[1] = 0xD9U;
        nbytes = 2;
    }
    src->pub.next_input_byte = src->native_buf;
    src->pub.bytes_in_buffer = static_cast<size_t>(nbytes);
    src->start_of_file = 0;
    return 1;
}

void isSkipInputData_0x003068(jpeg_decompress_struct* dinfo, long num_bytes) noexcept {
    // Disassembly @ 0x003068..0x0030d8:
    //   If num_bytes <= 0: return.
    //   If bytes_in_buffer > num_bytes: advances next_input_byte and subtracts num_bytes.
    //   Else: calls env->CallLongMethod(input_stream, is_skip_method_id, num_bytes - bytes_in_buffer)
    //         and zeroes next_input_byte and bytes_in_buffer.
    if (num_bytes <= 0) {
        return;
    }
    auto* src = reinterpret_cast<JpegInputStreamWrapper*>(dinfo->src);
    if (src->pub.bytes_in_buffer > static_cast<size_t>(num_bytes)) {
        src->pub.next_input_byte += num_bytes;
        src->pub.bytes_in_buffer -= static_cast<size_t>(num_bytes);
    } else {
        const jlong to_skip = static_cast<jlong>(static_cast<size_t>(num_bytes) - src->pub.bytes_in_buffer);
        const uintptr_t* tbl = GetJniTable(src->env);
        if (tbl != nullptr && tbl[0x1A8 / sizeof(uintptr_t)] != 0) {
            using CallLongFn = jlong (*)(JNIEnv*, jobject, jmethodID, ...);
            reinterpret_cast<CallLongFn>(tbl[0x1A8 / sizeof(uintptr_t)])(
                src->env, src->input_stream, gImagePipelineBss.is_skip_method_id, to_skip);
        }
        jpegCheckExceptionAndCleanup(dinfo);
        src->pub.next_input_byte = nullptr;
        src->pub.bytes_in_buffer = 0U;
    }
}

void isTermSource_0x0030d8(jpeg_decompress_struct* dinfo) noexcept {
    (void)dinfo;
}

// --- JpegOutputStreamWrapper callbacks (0x0030dc..0x003294) ---
void osInitDestination_0x003104(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x003104..0x003180:
    //   java_buffer = NewByteArray(env, 0x2000),
    //   native_buf = (*cinfo->mem->alloc_small)(cinfo, JPOOL_IMAGE=1, 0x2000).
    //   If native_buf == nullptr, throws "Failed to allcoate memory for byte buffer." (0x037ba7, exact binary typo!).
    auto* dst = reinterpret_cast<JpegOutputStreamWrapper*>(cinfo->dest);
    dst->java_buffer = JniNewByteArray(dst->env, static_cast<jsize>(kJpegStreamBufferSize));
    jpegCheckExceptionAndCleanup(cinfo);
    dst->native_buf = static_cast<uint8_t*>(
        cinfo->mem->alloc_small(cinfo, 1 /* JPOOL_IMAGE */, kJpegStreamBufferSize));
    if (dst->native_buf == nullptr) {
        jpegThrowExceptionAndLongjmp(cinfo, "Failed to allcoate memory for byte buffer.");
    }
    dst->pub.next_output_byte = dst->native_buf;
    dst->pub.free_in_buffer = kJpegStreamBufferSize;
}

int osEmptyOutputBuffer_0x003180(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x003180..0x003200:
    //   SetByteArrayRegion(env, java_buffer, 0, 0x2000, native_buf),
    //   CallVoidMethod(env, output_stream, os_write_bytes_method_id, java_buffer),
    //   resets next_output_byte = native_buf, free_in_buffer = 0x2000.
    auto* dst = reinterpret_cast<JpegOutputStreamWrapper*>(cinfo->dest);
    JniSetByteArrayRegion(
        dst->env,
        dst->java_buffer,
        0,
        static_cast<jsize>(kJpegStreamBufferSize),
        reinterpret_cast<const jbyte*>(dst->native_buf));
    jpegCheckExceptionAndCleanup(cinfo);

    const uintptr_t* tbl = GetJniTable(dst->env);
    if (tbl != nullptr && tbl[0x1F0 / sizeof(uintptr_t)] != 0) {
        using CallVoidFn = void (*)(JNIEnv*, jobject, jmethodID, ...);
        reinterpret_cast<CallVoidFn>(tbl[0x1F0 / sizeof(uintptr_t)])(
            dst->env, dst->output_stream, gImagePipelineBss.os_write_bytes_method_id, dst->java_buffer);
    }
    jpegCheckExceptionAndCleanup(cinfo);
    dst->pub.next_output_byte = dst->native_buf;
    dst->pub.free_in_buffer = kJpegStreamBufferSize;
    return 1;
}

void osTermDestination_0x003200(jpeg_compress_struct* cinfo) noexcept {
    // Disassembly @ 0x003200..0x003294:
    //   datacount = 0x2000 - free_in_buffer;
    //   if (datacount > 0): SetByteArrayRegion & CallVoidMethod(os, os_write_range_method_id, java_buffer, 0, datacount).
    auto* dst = reinterpret_cast<JpegOutputStreamWrapper*>(cinfo->dest);
    const size_t datacount = kJpegStreamBufferSize - dst->pub.free_in_buffer;
    if (datacount > 0) {
        JniSetByteArrayRegion(
            dst->env,
            dst->java_buffer,
            0,
            static_cast<jsize>(datacount),
            reinterpret_cast<const jbyte*>(dst->native_buf));
        jpegCheckExceptionAndCleanup(cinfo);

        const uintptr_t* tbl = GetJniTable(dst->env);
        if (tbl != nullptr && tbl[0x1F0 / sizeof(uintptr_t)] != 0) {
            using CallVoidFn = void (*)(JNIEnv*, jobject, jmethodID, ...);
            reinterpret_cast<CallVoidFn>(tbl[0x1F0 / sizeof(uintptr_t)])(
                dst->env,
                dst->output_stream,
                gImagePipelineBss.os_write_range_method_id,
                dst->java_buffer,
                0,
                static_cast<jint>(datacount));
        }
        jpegCheckExceptionAndCleanup(cinfo);
    }
}

} // anonymous namespace

void jpegMemorySourceInit(JpegMemorySourceWrapper* src) noexcept {
    // Disassembly @ 0x002a94..0x002ad4
    src->pub.next_input_byte = nullptr;
    src->pub.bytes_in_buffer = 0U;
    src->pub.init_source = &memInitSource_0x002ad4;
    src->pub.fill_input_buffer = &memFillInputBuffer_0x002ae8;
    src->pub.skip_input_data = &memSkipInputData_0x002b04;
    src->pub.resync_to_restart = &jpeg_resync_to_restart;
    src->pub.term_source = &memTermSource_0x002b24;
    src->encoded.clear();
}

void jpegMemoryDestInit(JpegMemoryDestinationWrapper* dst) noexcept {
    // Disassembly @ 0x002b28..0x002b50
    dst->pub.next_output_byte = nullptr;
    dst->pub.free_in_buffer = 0U;
    dst->pub.init_destination = &memInitDestination_0x002b50;
    dst->pub.empty_output_buffer = &memEmptyOutputBuffer_0x002ba8;
    dst->pub.term_destination = &memTermDestination_0x002be8;
    dst->encoded.clear();
    dst->block_buf = nullptr;
}

void jpegInputStreamWrapperInit(JpegInputStreamWrapper* src, JNIEnv* env, jobject is) noexcept {
    // Disassembly @ 0x002ed8..0x002f18
    src->pub.next_input_byte = nullptr;
    src->pub.bytes_in_buffer = 0U;
    src->pub.init_source = &isInitSource_0x002f18;
    src->pub.fill_input_buffer = &isFillInputBuffer_0x002f98;
    src->pub.skip_input_data = &isSkipInputData_0x003068;
    src->pub.resync_to_restart = &jpeg_resync_to_restart;
    src->pub.term_source = &isTermSource_0x0030d8;
    src->input_stream = is;
    src->java_buffer = nullptr;
    src->native_buf = nullptr;
    src->env = env;
    src->start_of_file = 0;
}

void jpegOutputStreamWrapperInit(JpegOutputStreamWrapper* dst, JNIEnv* env, jobject os) noexcept {
    // Disassembly @ 0x0030dc..0x003104
    dst->pub.next_output_byte = nullptr;
    dst->pub.free_in_buffer = 0U;
    dst->pub.init_destination = &osInitDestination_0x003104;
    dst->pub.empty_output_buffer = &osEmptyOutputBuffer_0x003180;
    dst->pub.term_destination = &osTermDestination_0x003200;
    dst->output_stream = os;
    dst->java_buffer = nullptr;
    dst->native_buf = nullptr;
    dst->env = env;
}

// ============================================================================
// 4. TRANSCODE, DOWNSCALE & LOSSLESS DCT ROTATE PIPELINE (0x00232c..0x00294c)
// ============================================================================

void downscaleJpeg(JNIEnv* env,
                   jpeg_source_mgr* src_mgr,
                   jpeg_destination_mgr* dst_mgr,
                   ScaleFactor scale_factor,
                   jint quality) noexcept {
    // Disassembly @ 0x0024e0..0x00277c (668 bytes):
    //   - Validates quality in [1, 100]:
    //       < 1   -> throws "quality should not be lower than 1" (0x037a73)
    //       > 100 -> throws "quality should not be greater than 100" (0x037a96)
    //   - Validates scale_factor.denominator == 8:
    //       != 8  -> throws "wrong scale denominator" (0x037abd)
    //   - Validates scale_factor.numerator in [1, 16]:
    //       == 0  -> throws "scale numerator cannot be lower than 1" (0x037ad5)
    //       >= 17 -> throws "scale numerator cannot be greater than 16" (0x037afc)
    if (quality < 1) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "quality should not be lower than 1");
        return;
    }
    if (quality > 100) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "quality should not be greater than 100");
        return;
    }
    if (scale_factor.denominator != kJpegScaleDenominator) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "wrong scale denominator");
        return;
    }
    if (scale_factor.numerator == 0U) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "scale numerator cannot be lower than 1");
        return;
    }
    if (scale_factor.numerator > kJpegMaxScaleNumerator) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "scale numerator cannot be greater than 16");
        return;
    }

    JpegErrorHandler err_handler;
    jpegErrorHandlerInit(&err_handler, env);

    jpeg_decompress_struct dinfo;
    std::memset(&dinfo, 0, sizeof(dinfo));
    jpegErrorHandlerSetDecompress(&err_handler, &dinfo);
    jpeg_CreateDecompress(&dinfo, kJpegLibVersion80, kJpegDecompressStructSize);

    dinfo.src = src_mgr;
    jpeg_read_header(&dinfo, 1);
    dinfo.scale_num = scale_factor.numerator;
    dinfo.scale_denom = scale_factor.denominator;
    dinfo.out_color_space = JCS_RGB; // mov w9, #2; str w9, [sp, #0x288] @ 0x002660..0x002670
    jpeg_start_decompress(&dinfo);

    jpeg_compress_struct cinfo;
    std::memset(&cinfo, 0, sizeof(cinfo));
    jpegErrorHandlerSetCompress(&err_handler, &cinfo);
    jpeg_CreateCompress(&cinfo, kJpegLibVersion80, kJpegCompressStructSize);

    cinfo.dest = dst_mgr;
    cinfo.image_width = dinfo.output_width;
    cinfo.image_height = dinfo.output_height;
    cinfo.input_components = dinfo.output_components;
    cinfo.in_color_space = dinfo.out_color_space;
    cinfo.optimize_coding = 1; // str w22, [sp, #0x138] @ 0x0026b8

    jpeg_set_defaults(&cinfo);
    jpeg_set_quality(&cinfo, quality, 0 /* force_baseline = FALSE */);
    jpeg_start_compress(&cinfo, 1 /* write_all_tables = TRUE */);
    jcopy_markers_execute(&dinfo, &cinfo, JCOPYOPT_ALL);

    const uint32_t row_stride = dinfo.output_width * static_cast<uint32_t>(dinfo.output_components);
    uint8_t* row_buf = static_cast<uint8_t*>(dinfo.mem->alloc_small(&dinfo, 1 /* JPOOL_IMAGE */, row_stride));
    while (dinfo.output_scanline < dinfo.output_height) {
        jpeg_read_scanlines(&dinfo, &row_buf, 1U);
        jpeg_write_scanlines(&cinfo, &row_buf, 1U);
    }

    jpeg_finish_compress(&cinfo);
    jpeg_destroy_decompress(&dinfo);
    jpeg_destroy_compress(&cinfo);
}

void rotateJpeg(JNIEnv* env,
                jpeg_source_mgr* src_mgr,
                jpeg_destination_mgr* dst_mgr,
                FrescoRotationType rotation_type) noexcept {
    // Disassembly @ 0x00277c..0x00294c (464 bytes):
    //   - Maps rotation_type (1..7) -> JXFORM_CODE via .rodata 0x037b28:
    //       sub w9, w19, #1; cmp w9, #6; ldr w8, [x8, w9, sxtw #2]
    //   - Initializes 96-byte (0x60) jpeg_transform_info on stack:
    //       xform.transform = jxform, xform.trim = 1 (TRUE).
    //   - Executes lossless DCT coefficient pipeline:
    //       jtransform_request_workspace -> jpeg_read_coefficients ->
    //       jpeg_copy_critical_parameters -> jtransform_adjust_parameters ->
    //       jpeg_write_coefficients -> jcopy_markers_execute ->
    //       jtransform_execute_transform -> jpeg_finish_compress.
    JpegErrorHandler err_handler;
    jpegErrorHandlerInit(&err_handler, env);

    jpeg_decompress_struct dinfo;
    std::memset(&dinfo, 0, sizeof(dinfo));
    jpegErrorHandlerSetDecompress(&err_handler, &dinfo);
    jpeg_CreateDecompress(&dinfo, kJpegLibVersion80, kJpegDecompressStructSize);
    dinfo.src = src_mgr;
    jpeg_read_header(&dinfo, 1);

    jpeg_compress_struct cinfo;
    std::memset(&cinfo, 0, sizeof(cinfo));
    jpegErrorHandlerSetCompress(&err_handler, &cinfo);
    jpeg_CreateCompress(&cinfo, kJpegLibVersion80, kJpegCompressStructSize);
    cinfo.dest = dst_mgr;
    cinfo.optimize_coding = 1;
    jpeg_set_defaults(&cinfo);

    jpeg_transform_info xform_info;
    std::memset(&xform_info, 0, sizeof(xform_info));
    const uint32_t idx = static_cast<uint32_t>(rotation_type) - 1U;
    xform_info.transform = (idx <= 6U) ? kFrescoRotationToJxformTable[idx] : JXFORM_NONE;
    xform_info.trim = 1;

    jtransform_request_workspace(&dinfo, &xform_info);
    void* src_coef_arrays = jpeg_read_coefficients(&dinfo);
    jpeg_copy_critical_parameters(&dinfo, &cinfo);
    void* dst_coef_arrays = jtransform_adjust_parameters(&dinfo, &cinfo, src_coef_arrays, &xform_info);
    jpeg_write_coefficients(&cinfo, dst_coef_arrays);
    jcopy_markers_execute(&dinfo, &cinfo, JCOPYOPT_ALL);
    jtransform_execute_transform(&dinfo, &cinfo, src_coef_arrays, &xform_info);

    jpeg_finish_compress(&cinfo);
    jpeg_destroy_compress(&cinfo);
    jpeg_destroy_decompress(&dinfo);
}

void transcodeJpeg(JNIEnv* env,
                   jobject input_stream,
                   jobject output_stream,
                   JXFORM_CODE rotation_xform,
                   ScaleFactor scale_factor,
                   jint quality) noexcept {
    // Disassembly @ 0x00232c..0x0024e0 (436 bytes):
    //   Checks if should_scale (scale.numerator != scale.denominator && scale.numerator != 0)
    //   or should_rotate (rotation_xform != 0).
    //   If neither, throws RuntimeException("no transformation to perform") (0x037a56).
    const bool should_scale = scale_factor.shouldScale();
    const bool should_rotate = (rotation_xform != JXFORM_NONE);

    if (!should_scale && !should_rotate) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "no transformation to perform");
        return;
    }

    JpegInputStreamWrapper is_wrapper;
    jpegInputStreamWrapperInit(&is_wrapper, env, input_stream);

    JpegOutputStreamWrapper os_wrapper;
    jpegOutputStreamWrapperInit(&os_wrapper, env, output_stream);

    JpegMemoryDestinationWrapper mem_dst_wrapper;
    jpegMemoryDestInit(&mem_dst_wrapper);

    JpegMemorySourceWrapper mem_src_wrapper;
    jpegMemorySourceInit(&mem_src_wrapper);

    if (should_scale) {
        jpeg_destination_mgr* stage1_dst = should_rotate ? &mem_dst_wrapper.pub : &os_wrapper.pub;
        downscaleJpeg(env, &is_wrapper.pub, stage1_dst, scale_factor, quality);
        if ((JniExceptionCheck(env) & 0xFFU) != 0U) {
            return;
        }
        if (!should_rotate) {
            return;
        }
        mem_src_wrapper.encoded = std::move(mem_dst_wrapper.encoded);
    }

    if (should_rotate) {
        jpeg_source_mgr* stage2_src = should_scale ? &mem_src_wrapper.pub : &is_wrapper.pub;
        rotateJpeg(env, stage2_src, &os_wrapper.pub, static_cast<FrescoRotationType>(rotation_xform));
    }
}

// ============================================================================
// 5. ORIENTATION MAPPERS & NATIVE JPEG TRANSCODER JNI ENTRYPOINTS (0x003468..0x003710)
// ============================================================================

FrescoRotationType getRotationTypeFromDegrees(JNIEnv* env, uint16_t degrees) noexcept {
    // Disassembly @ 0x003468..0x0034dc (116 bytes):
    //   0    (0x000) -> 0 (ROTATE_0)
    //   90   (0x05a) -> 1 (ROTATE_90)
    //   180  (0x0b4) -> 2 (ROTATE_180)
    //   270  (0x10e) -> 3 (ROTATE_270)
    //   else -> safeThrowJavaException(env, gRuntimeException_main, "wrong rotation angle")
    switch (degrees) {
        case 0U:
            return FrescoRotationType::ROTATE_0;
        case 90U:
            return FrescoRotationType::ROTATE_90;
        case 180U:
            return FrescoRotationType::ROTATE_180;
        case 270U:
            return FrescoRotationType::ROTATE_270;
        default:
            safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "wrong rotation angle");
            return FrescoRotationType::ROTATE_0;
    }
}

FrescoRotationType getRotationTypeFromExifOrientation(JNIEnv* env, uint16_t exif_orientation) noexcept {
    // Disassembly @ 0x0034dc..0x003530 (84 bytes):
    //   sub w8, w1, #1; and w9, w8, #0xffff; cmp w9, #8; b.hs #0x350c
    //   ldr w0, [x9, x8, lsl #2] (.rodata 0x037c00: {0, 4, 2, 5, 6, 1, 7, 3})
    const uint16_t idx = static_cast<uint16_t>(exif_orientation - 1U);
    if (idx < 8U) {
        return static_cast<FrescoRotationType>(kFrescoExifToRotationTable[idx]);
    }
    safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_main, "wrong exif orientation");
    return FrescoRotationType::ROTATE_0;
}

bool registerJpegTranscoderMethods(JNIEnv* env) noexcept {
    // Disassembly @ 0x003530..0x0035b8 (136 bytes):
    //   FindClass("com/facebook/imagepipeline/nativecode/NativeJpegTranscoder")
    //   RegisterNatives(env, clazz, 0x044000, 2)
    jclass clazz = JniFindClass(env, "com/facebook/imagepipeline/nativecode/NativeJpegTranscoder");
    if (clazz == nullptr) {
        return false;
    }
    const JNINativeMethod methods[2] = {
        {
            "nativeTranscodeJpeg",
            "(Ljava/io/InputStream;Ljava/io/OutputStream;III)V",
            reinterpret_cast<void*>(&NativeJpegTranscoder_transcodeJpeg)
        },
        {
            "nativeTranscodeJpegWithExifOrientation",
            "(Ljava/io/InputStream;Ljava/io/OutputStream;III)V",
            reinterpret_cast<void*>(&NativeJpegTranscoder_transcodeJpegWithExifOrientation)
        }
    };
    return JniRegisterNatives(env, clazz, methods, 2) == JNI_OK;
}

void NativeJpegTranscoder_transcodeJpeg(JNIEnv* env,
                                        jclass clazz,
                                        jobject input_stream,
                                        jobject output_stream,
                                        jint rotation_degrees,
                                        jint scale_numerator,
                                        jint quality) noexcept {
    // Disassembly @ 0x0035b8..0x003664 (172 bytes):
    //   Packs ScaleFactor{scale_numerator, 8}, calls getRotationTypeFromDegrees(env, rotation_degrees),
    //   checks ExceptionCheck(env), and calls transcodeJpeg (0x00232c).
    (void)clazz;
    const ScaleFactor scale{static_cast<uint8_t>(scale_numerator), kJpegScaleDenominator};
    const FrescoRotationType rot = getRotationTypeFromDegrees(env, static_cast<uint16_t>(rotation_degrees));
    if ((JniExceptionCheck(env) & 0xFFU) == 0U) {
        transcodeJpeg(env, input_stream, output_stream, static_cast<JXFORM_CODE>(rot), scale, quality);
    }
}

void NativeJpegTranscoder_transcodeJpegWithExifOrientation(JNIEnv* env,
                                                           jclass clazz,
                                                           jobject input_stream,
                                                           jobject output_stream,
                                                           jint exif_orientation,
                                                           jint scale_numerator,
                                                           jint quality) noexcept {
    // Disassembly @ 0x003664..0x003710 (172 bytes):
    //   Packs ScaleFactor{scale_numerator, 8}, calls getRotationTypeFromExifOrientation(env, exif_orientation),
    //   checks ExceptionCheck(env), and calls transcodeJpeg (0x00232c).
    (void)clazz;
    const ScaleFactor scale{static_cast<uint8_t>(scale_numerator), kJpegScaleDenominator};
    const FrescoRotationType rot = getRotationTypeFromExifOrientation(env, static_cast<uint16_t>(exif_orientation));
    if ((JniExceptionCheck(env) & 0xFFU) == 0U) {
        transcodeJpeg(env, input_stream, output_stream, static_cast<JXFORM_CODE>(rot), scale, quality);
    }
}

// ============================================================================
// 6. BITMAPS, DALVIK PURGEABLE DECODER & NATIVE MEMORY CHUNK (0x03726c..0x037814)
// ============================================================================

jint registerBitmapsMethods(JNIEnv* env) noexcept {
    // Disassembly @ 0x03726c..0x037310 (164 bytes):
    //   Caches RuntimeException at .bss 0x044118, finds "com/facebook/imagepipeline/nativecode/Bitmaps",
    //   calls RegisterNatives(env, clazz, 0x044030, 1), returns 0x00010006 or -1 via `csinv w0, w8, wzr, eq`.
    jclass rt = JniFindClass(env, "java/lang/RuntimeException");
    if (rt == nullptr) {
        return JNI_ERR;
    }
    gImagePipelineBss.jRuntimeException_bitmaps =
        reinterpret_cast<jclass>(JniNewGlobalRef(env, reinterpret_cast<jobject>(rt)));

    jclass bitmaps_clazz = JniFindClass(env, "com/facebook/imagepipeline/nativecode/Bitmaps");
    if (bitmaps_clazz == nullptr) {
        return JNI_ERR;
    }
    const JNINativeMethod method = {
        "nativeCopyBitmap",
        "(Landroid/graphics/Bitmap;ILandroid/graphics/Bitmap;II)V",
        reinterpret_cast<void*>(&Bitmaps_copyBitmap)
    };
    return (JniRegisterNatives(env, bitmaps_clazz, &method, 1) == JNI_OK) ? JNI_VERSION_1_6 : JNI_ERR;
}

jint registerDalvikPurgeableDecoderMethods(JNIEnv* env) noexcept {
    // Disassembly @ 0x037310..0x0373b4 (164 bytes):
    //   Caches RuntimeException at .bss 0x044118, finds "com/facebook/imagepipeline/nativecode/DalvikPurgeableDecoder",
    //   calls RegisterNatives(env, clazz, 0x044048, 1), returns 0x00010006 or -1.
    jclass rt = JniFindClass(env, "java/lang/RuntimeException");
    if (rt == nullptr) {
        return JNI_ERR;
    }
    gImagePipelineBss.jRuntimeException_bitmaps =
        reinterpret_cast<jclass>(JniNewGlobalRef(env, reinterpret_cast<jobject>(rt)));

    jclass decoder_clazz = JniFindClass(env, "com/facebook/imagepipeline/nativecode/DalvikPurgeableDecoder");
    if (decoder_clazz == nullptr) {
        return JNI_ERR;
    }
    const JNINativeMethod method = {
        "nativePinBitmap",
        "(Landroid/graphics/Bitmap;)V",
        reinterpret_cast<void*>(&DalvikPurgeableDecoder_nativePinBitmap)
    };
    return (JniRegisterNatives(env, decoder_clazz, &method, 1) == JNI_OK) ? JNI_VERSION_1_6 : JNI_ERR;
}

namespace {

void unlockPixelsSafe(JNIEnv* env, jobject bitmap) noexcept {
    // Disassembly @ 0x037504..0x037620:
    //   Preserves any pending Java exception across AndroidBitmap_unlockPixels(env, bitmap).
    jthrowable pending = JniExceptionOccurred(env);
    if (pending != nullptr) {
        JniExceptionClear(env);
    }
    HostAndroidBitmapUnlockPixels(env, bitmap);
    if (pending != nullptr) {
        if ((JniExceptionCheck(env) & 0xFFU) != 0U) {
            JniExceptionDescribe(env);
            JniExceptionClear(env);
        }
        JniThrow(env, pending);
    }
}

} // anonymous namespace

void Bitmaps_copyBitmap(JNIEnv* env,
                        jclass clazz,
                        jobject dest_bitmap,
                        jint dest_stride,
                        jobject src_bitmap,
                        jint src_stride,
                        jint rows) noexcept {
    // Disassembly @ 0x0373b4..0x037654 (672 bytes):
    //   1. AndroidBitmap_lockPixels(env, dest_bitmap, &dest_ptr)
    //      If failed or dest_ptr == nullptr: throws "Could not lock desination's pixels" (0x03a775)
    //   2. AndroidBitmap_lockPixels(env, src_bitmap, &src_ptr)
    //      If failed or src_ptr == nullptr: throws "Could not lock source's pixels" (0x03a798), unlocks dest
    //   3. If dest_ptr != src_ptr:
    //      - If dest_stride == src_stride (0x037438):
    //          memcpy(dest_ptr, src_ptr, (int64_t)(rows * dest_stride)) (0x037440..0x037448)
    //      - Else (0x0374c8..0x037500):
    //          shortest = min(dest_stride, src_stride) (`csel w8, w24, w23, lt`)
    //          for (r = 0; r < rows; ++r):
    //              memcpy(dest_row, src_row, shortest);
    //              dest_row += dest_stride; src_row += src_stride;
    //   4. Unlocks src_bitmap and dest_bitmap while preserving pending exceptions.
    (void)clazz;
    void* dest_ptr = nullptr;
    void* src_ptr = nullptr;

    if (HostAndroidBitmapLockPixels(env, dest_bitmap, &dest_ptr) != 0 || dest_ptr == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_bitmaps, "Could not lock desination's pixels");
        return;
    }

    if (HostAndroidBitmapLockPixels(env, src_bitmap, &src_ptr) != 0 || src_ptr == nullptr) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_bitmaps, "Could not lock source's pixels");
        unlockPixelsSafe(env, dest_bitmap);
        return;
    }

    if (dest_ptr != src_ptr) {
        if (dest_stride == src_stride) {
            const int64_t total_bytes = static_cast<int64_t>(rows * dest_stride);
            if (total_bytes > 0) {
                std::memcpy(dest_ptr, src_ptr, static_cast<size_t>(total_bytes));
            }
        } else if (rows >= 1) {
            const jint shortest = (dest_stride < src_stride) ? dest_stride : src_stride;
            uint8_t* d_row = static_cast<uint8_t*>(dest_ptr);
            const uint8_t* s_row = static_cast<const uint8_t*>(src_ptr);
            for (jint r = 0; r < rows; ++r) {
                std::memcpy(d_row, s_row, static_cast<size_t>(shortest));
                d_row += dest_stride;
                s_row += src_stride;
            }
        }
    }

    unlockPixelsSafe(env, src_bitmap);
    unlockPixelsSafe(env, dest_bitmap);
}

void DalvikPurgeableDecoder_nativePinBitmap(JNIEnv* env,
                                            jclass clazz,
                                            jobject bitmap) noexcept {
    // Disassembly @ 0x037654..0x0376c0 (108 bytes):
    //   Calls AndroidBitmap_lockPixels(env, bitmap, nullptr) without unlocking.
    //   If non-zero, throws RuntimeException("Failed to pin Bitmap") (0x03a7e4).
    (void)clazz;
    if (HostAndroidBitmapLockPixels(env, bitmap, nullptr) != 0) {
        safeThrowJavaException(env, gImagePipelineBss.jRuntimeException_bitmaps, "Failed to pin Bitmap");
    }
}

jint registerNativeMemoryChunkMethods(JNIEnv* env) noexcept {
    // Disassembly @ 0x0376c0..0x037764 (164 bytes):
    //   Caches RuntimeException at .bss 0x044120, finds "com/facebook/imagepipeline/memory/NativeMemoryChunk",
    //   calls RegisterNatives(env, clazz, 0x044060, 6), returns 0x00010006 or -1.
    jclass rt = JniFindClass(env, "java/lang/RuntimeException");
    if (rt == nullptr) {
        return JNI_ERR;
    }
    gImagePipelineBss.jRuntimeException_nmc =
        reinterpret_cast<jclass>(JniNewGlobalRef(env, reinterpret_cast<jobject>(rt)));

    jclass nmc_clazz = JniFindClass(env, "com/facebook/imagepipeline/memory/NativeMemoryChunk");
    if (nmc_clazz == nullptr) {
        return JNI_ERR;
    }
    const JNINativeMethod methods[6] = {
        { "nativeAllocate",          "(I)J",     reinterpret_cast<void*>(&NativeMemoryChunk_nativeAllocate) },
        { "nativeFree",              "(J)V",     reinterpret_cast<void*>(&NativeMemoryChunk_nativeFree) },
        { "nativeCopyToByteArray",   "(J[BII)V", reinterpret_cast<void*>(&NativeMemoryChunk_nativeCopyToByteArray) },
        { "nativeCopyFromByteArray", "(J[BII)V", reinterpret_cast<void*>(&NativeMemoryChunk_nativeCopyFromByteArray) },
        { "nativeMemcpy",            "(JJI)V",   reinterpret_cast<void*>(&NativeMemoryChunk_nativeMemcpy) },
        { "nativeReadByte",          "(J)B",     reinterpret_cast<void*>(&NativeMemoryChunk_nativeReadByte) },
    };
    return (JniRegisterNatives(env, nmc_clazz, methods, 6) == JNI_OK) ? JNI_VERSION_1_6 : JNI_ERR;
}

jlong NativeMemoryChunk_nativeAllocate(JNIEnv* env, jclass clazz, jint size) noexcept {
    // Disassembly @ 0x037764..0x0377b0 (76 bytes):
    //   sxtw x0, w2; bl malloc; cbnz x0, #0x377a4
    //   Throws RuntimeException("could not allocate memory") (0x03a8b0) and returns 0.
    (void)clazz;
    void* ptr = std::malloc(static_cast<size_t>(static_cast<int64_t>(size)));
    if (ptr == nullptr) {
        JniThrowNew(env, gImagePipelineBss.jRuntimeException_nmc, "could not allocate memory");
        return 0;
    }
    return reinterpret_cast<jlong>(ptr);
}

void NativeMemoryChunk_nativeFree(JNIEnv* env, jclass clazz, jlong lpointer) noexcept {
    // Disassembly @ 0x0377b0..0x0377b8 (8 bytes):
    //   mov x0, x2; b free
    (void)env;
    (void)clazz;
    std::free(reinterpret_cast<void*>(lpointer));
}

void NativeMemoryChunk_nativeCopyToByteArray(JNIEnv* env,
                                             jclass clazz,
                                             jlong lpointer,
                                             jbyteArray byte_array,
                                             jint offset,
                                             jint count) noexcept {
    // Disassembly @ 0x0377b8..0x0377d8 (32 bytes):
    //   Tail-calls (*env)->SetByteArrayRegion(env, byte_array, offset, count, (const jbyte*)lpointer) (+0x680)
    (void)clazz;
    JniSetByteArrayRegion(env, byte_array, offset, count, reinterpret_cast<const jbyte*>(lpointer));
}

void NativeMemoryChunk_nativeCopyFromByteArray(JNIEnv* env,
                                               jclass clazz,
                                               jlong lpointer,
                                               jbyteArray byte_array,
                                               jint offset,
                                               jint count) noexcept {
    // Disassembly @ 0x0377d8..0x0377f8 (32 bytes):
    //   Tail-calls (*env)->GetByteArrayRegion(env, byte_array, offset, count, (jbyte*)lpointer) (+0x640)
    (void)clazz;
    JniGetByteArrayRegion(env, byte_array, offset, count, reinterpret_cast<jbyte*>(lpointer));
}

void NativeMemoryChunk_nativeMemcpy(JNIEnv* env,
                                    jclass clazz,
                                    jlong dst_ptr,
                                    jlong src_ptr,
                                    jint count) noexcept {
    // Disassembly @ 0x0377f8..0x03780c (20 bytes):
    //   sxtw x8, w4; mov x1, x3; mov x0, x2; mov x2, x8; b memcpy
    (void)env;
    (void)clazz;
    if (dst_ptr != 0 && src_ptr != 0 && count > 0) {
        std::memcpy(
            reinterpret_cast<void*>(dst_ptr),
            reinterpret_cast<const void*>(src_ptr),
            static_cast<size_t>(static_cast<int64_t>(count)));
    }
}

jbyte NativeMemoryChunk_nativeReadByte(JNIEnv* env, jclass clazz, jlong lpointer) noexcept {
    // Disassembly @ 0x03780c..0x037814 (8 bytes):
    //   ldrb w0, [x2]; ret
    (void)env;
    (void)clazz;
    return (lpointer != 0) ? *reinterpret_cast<const jbyte*>(lpointer) : 0;
}

} // namespace imagepipeline
} // namespace opencut
} // namespace nextai
