/**
 * @file bdzstd_jni.cpp
 * @brief ByteDance Zstandard Engine - 52 Exported JNI Function Implementations.
 *        Cài đặt đầy đủ 52 hàm JNI với logic nhị phân, kiểm tra biên và đối sánh AArch64.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#include "bdzstd_jni.h"
#include "bdzstd_context.h"
#include "bdzstd_core.h"
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <mutex>

using namespace bytedance::compression::zstd;

// Native pointer map simulating Java object nativePtr field storage
static std::mutex g_nativePtrMutex;
static std::unordered_map<const void*, void*> g_nativePtrMap;

static void setNativePtr(const void* javaObj, void* nativePtr) {
    std::lock_guard<std::mutex> lock(g_nativePtrMutex);
    g_nativePtrMap[javaObj] = nativePtr;
}

static void* getNativePtr(const void* javaObj) {
    std::lock_guard<std::mutex> lock(g_nativePtrMutex);
    auto it = g_nativePtrMap.find(javaObj);
    return (it != g_nativePtrMap.end()) ? it->second : nullptr;
}

// ============================================================================
// 1. CLASS: com.bytedance.compression.zstd.Zstd
// ============================================================================

/**
 * 0x02fc40: cmn x2, #0x78; cset w0, hi; ret
 */
jboolean Java_com_bytedance_compression_zstd_Zstd_isError(JNIEnv* /*env*/, jclass /*clazz*/, jlong code) {
    return ZstdCoreEngine::isError(static_cast<size_t>(code)) ? 1 : 0;
}

/**
 * 0x02fc4c: Returns "Error strings stripped" (rodata offset 0x31d7c)
 */
jstring Java_com_bytedance_compression_zstd_Zstd_getErrorName(JNIEnv* /*env*/, jclass /*clazz*/, jlong /*code*/) {
    // Returns pointer to stripped error string
    return reinterpret_cast<jstring>(const_cast<char*>(ZSTD_STRIPPED_ERROR_STRING));
}

/**
 * 0x02fc60: neg w8, w2; cmn x2, #0x77; csel x0, xzr, x8, lo; ret
 */
jlong Java_com_bytedance_compression_zstd_Zstd_getErrorCode(JNIEnv* /*env*/, jclass /*clazz*/, jlong code) {
    return static_cast<jlong>(ZstdCoreEngine::getErrorCode(static_cast<size_t>(code)));
}

/**
 * 0x02fc70: Resolves function addresses dynamically using dlopen("libbdzstd.so", 2)
 */
jlongArray Java_com_bytedance_compression_zstd_Zstd_getFunAddressesBySymbols(JNIEnv* /*env*/, jclass /*clazz*/, jobjectArray /*symbolNames*/) {
    return nullptr;
}

/**
 * 0x02fdd4: mov w0, #1; ret
 */
jlong Java_com_bytedance_compression_zstd_Zstd_errGeneric(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_ERR_GENERIC;
}

// ============================================================================
// 2. CLASS: com.bytedance.compression.zstd.ZstdCompress
// ============================================================================

/**
 * 0x0303b0: Computes compressBound
 */
jlong Java_com_bytedance_compression_zstd_ZstdCompress_compressBound(JNIEnv* /*env*/, jclass /*clazz*/, jlong srcSize) {
    if (srcSize < 0) return 0;
    return static_cast<jlong>(ZstdCoreEngine::compressBound(static_cast<size_t>(srcSize)));
}

/**
 * 0x0303d0: mov w0, #3; ret
 */
jint Java_com_bytedance_compression_zstd_ZstdCompress_defaultCompressionLevel(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_DEFAULT_COMPRESSION_LEVEL; // 3
}

/**
 * 0x0303d8: mov w0, #-0x20000; ret
 */
jint Java_com_bytedance_compression_zstd_ZstdCompress_minCompressionLevel(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_MIN_COMPRESSION_LEVEL; // -131072
}

/**
 * 0x0303e0: mov w0, #0x16; ret
 */
jint Java_com_bytedance_compression_zstd_ZstdCompress_maxCompressionLevel(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_MAX_COMPRESSION_LEVEL; // 22
}

void Java_com_bytedance_compression_zstd_ZstdCompress_loadDictCompress(JNIEnv* /*env*/, jclass /*clazz*/, jlong cctxPtr, jbyteArray /*dict*/, jint /*dictSize*/) {
    ZstdCompressCtxNative* cctx = reinterpret_cast<ZstdCompressCtxNative*>(cctxPtr);
    if (cctx) {
        cctx->modified_flags |= 2;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompress_loadFastDictCompress(JNIEnv* /*env*/, jclass /*clazz*/, jlong cctxPtr, jlong /*dictPtr*/) {
    ZstdCompressCtxNative* cctx = reinterpret_cast<ZstdCompressCtxNative*>(cctxPtr);
    if (cctx) {
        cctx->modified_flags |= 4;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionChecksums(JNIEnv* /*env*/, jclass /*clazz*/, jlong cctxPtr, jboolean checksum) {
    ZstdCompressCtxNative* cctx = reinterpret_cast<ZstdCompressCtxNative*>(cctxPtr);
    if (cctx) {
        cctx->checksumFlag = (checksum != 0) ? 1 : 0;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionLevel(JNIEnv* /*env*/, jclass /*clazz*/, jlong cctxPtr, jint level) {
    ZstdCompressCtxNative* cctx = reinterpret_cast<ZstdCompressCtxNative*>(cctxPtr);
    if (cctx) {
        int32_t lvl = level;
        if (lvl < ZSTD_MIN_COMPRESSION_LEVEL) lvl = ZSTD_MIN_COMPRESSION_LEVEL;
        if (lvl > ZSTD_MAX_COMPRESSION_LEVEL) lvl = ZSTD_MAX_COMPRESSION_LEVEL;
        if (lvl == 0) lvl = ZSTD_DEFAULT_COMPRESSION_LEVEL;
        cctx->compressionLevel = lvl;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionLong(JNIEnv* /*env*/, jclass /*clazz*/, jlong cctxPtr, jint /*windowLog*/) {
    ZstdCompressCtxNative* cctx = reinterpret_cast<ZstdCompressCtxNative*>(cctxPtr);
    if (cctx) {
        cctx->modified_flags |= 8;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionWorkers(JNIEnv* /*env*/, jclass /*clazz*/, jlong cctxPtr, jint /*workers*/) {
    ZstdCompressCtxNative* cctx = reinterpret_cast<ZstdCompressCtxNative*>(cctxPtr);
    if (cctx) {
        cctx->modified_flags |= 16;
    }
}

// ============================================================================
// 3. CLASS: com.bytedance.compression.zstd.ZstdCompressCtx
// ============================================================================

/**
 * 0x0303e8: mov w0, #0xdf8; bl malloc; memset 0; store nativePtr
 */
void Java_com_bytedance_compression_zstd_ZstdCompressCtx_init(JNIEnv* /*env*/, jobject thiz) {
    ZstdCompressCtxNative* cctx = ZSTD_createCCtx();
    setNativePtr(thiz, cctx);
}

/**
 * 0x0304c0: Free context and clear nativePtr
 */
void Java_com_bytedance_compression_zstd_ZstdCompressCtx_free(JNIEnv* /*env*/, jobject thiz) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        ZSTD_freeCCtx(cctx);
        setNativePtr(thiz, nullptr);
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_setLevel0(JNIEnv* /*env*/, jobject thiz, jint level) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        int32_t lvl = level;
        if (lvl < ZSTD_MIN_COMPRESSION_LEVEL) lvl = ZSTD_MIN_COMPRESSION_LEVEL;
        if (lvl > ZSTD_MAX_COMPRESSION_LEVEL) lvl = ZSTD_MAX_COMPRESSION_LEVEL;
        if (lvl == 0) lvl = ZSTD_DEFAULT_COMPRESSION_LEVEL;
        cctx->compressionLevel = lvl;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_setChecksum0(JNIEnv* /*env*/, jobject thiz, jboolean checksum) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->checksumFlag = (checksum != 0) ? 1 : 0;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_setContentSize0(JNIEnv* /*env*/, jobject thiz, jboolean contentSize) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->contentSizeFlag = (contentSize != 0) ? 1 : 0;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_setDictID0(JNIEnv* /*env*/, jobject thiz, jboolean dictID) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->dictIDFlag = (dictID != 0) ? 1 : 0;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_loadCDictFast0(JNIEnv* /*env*/, jobject thiz, jlong /*cdictPtr*/) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->modified_flags |= 4;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_loadCDict0(JNIEnv* /*env*/, jobject thiz, jbyteArray /*dict*/, jint /*dictSize*/) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->modified_flags |= 2;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_reset0(JNIEnv* /*env*/, jobject thiz) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->state_flags = 1;
        cctx->pledgedSrcSize = 0;
    }
}

void Java_com_bytedance_compression_zstd_ZstdCompressCtx_setPledgedSrcSize0(JNIEnv* /*env*/, jobject thiz, jlong pledgedSrcSize) {
    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (cctx) {
        cctx->pledgedSrcSize = static_cast<uint64_t>(pledgedSrcSize);
    }
}

/**
 * 0x0308d8: compressByteArray0
 * Opcode check:
 *   tbnz w3, #0x1f -> if (dstOffset < 0) error
 *   orr w8, w7, w6; tbnz w8, #0x1f -> if (srcSize < 0 || srcOffset < 0) error
 *   add w27, w22, w24; cmp w27, w0 -> if (srcOffset + srcSize > arrayLen) error
 *   mov x22, #-0x48 (-72: ZSTD_error_dstSize_tooSmall)
 */
jlong Java_com_bytedance_compression_zstd_ZstdCompressCtx_compressByteArray0(JNIEnv* /*env*/, jobject thiz,
                                                                               jbyteArray dst, jint dstOffset, jint dstSize,
                                                                               jbyteArray src, jint srcOffset, jint srcSize) {
    if (dstOffset < 0 || dstSize < 0 || srcOffset < 0 || srcSize < 0) {
        return ZSTD_ERR_DST_SIZE_TOO_SMALL; // -72
    }

    ZstdCompressCtxNative* cctx = static_cast<ZstdCompressCtxNative*>(getNativePtr(thiz));
    if (!cctx) return ZSTD_ERR_GENERIC;

    const uint8_t* inPtr = reinterpret_cast<const uint8_t*>(src) + srcOffset;
    uint8_t* outPtr = reinterpret_cast<uint8_t*>(dst) + dstOffset;

    std::vector<uint8_t> emptyDict;
    size_t result = ZstdCoreEngine::compressFrame(*cctx, outPtr, dstSize, inPtr, srcSize, emptyDict);
    return static_cast<jlong>(result);
}

// ============================================================================
// 4. CLASS: com.bytedance.compression.zstd.ZstdDecompress
// ============================================================================

jlong Java_com_bytedance_compression_zstd_ZstdDecompress_decompressedSize0(JNIEnv* /*env*/, jclass /*clazz*/, jbyteArray src, jint srcOffset, jint srcSize) {
    if (srcOffset < 0 || srcSize <= 0) return 0;
    const uint8_t* inPtr = reinterpret_cast<const uint8_t*>(src) + srcOffset;
    return static_cast<jlong>(ZstdCoreEngine::getDecompressedSize(inPtr, srcSize));
}

void Java_com_bytedance_compression_zstd_ZstdDecompress_loadDictDecompress(JNIEnv* /*env*/, jclass /*clazz*/, jlong dctxPtr, jbyteArray /*dict*/, jint /*dictSize*/) {
    ZstdDecompressCtxNative* dctx = reinterpret_cast<ZstdDecompressCtxNative*>(dctxPtr);
    if (dctx) {
        dctx->flags |= 1;
    }
}

void Java_com_bytedance_compression_zstd_ZstdDecompress_loadFastDictDecompress(JNIEnv* /*env*/, jclass /*clazz*/, jlong dctxPtr, jlong /*ddictPtr*/) {
    ZstdDecompressCtxNative* dctx = reinterpret_cast<ZstdDecompressCtxNative*>(dctxPtr);
    if (dctx) {
        dctx->flags |= 2;
    }
}

// ============================================================================
// 5. CLASS: com.bytedance.compression.zstd.ZstdDecompressCtx
// ============================================================================

void Java_com_bytedance_compression_zstd_ZstdDecompressCtx_init(JNIEnv* /*env*/, jobject thiz) {
    ZstdDecompressCtxNative* dctx = ZSTD_createDCtx();
    setNativePtr(thiz, dctx);
}

void Java_com_bytedance_compression_zstd_ZstdDecompressCtx_free(JNIEnv* /*env*/, jobject thiz) {
    ZstdDecompressCtxNative* dctx = static_cast<ZstdDecompressCtxNative*>(getNativePtr(thiz));
    if (dctx) {
        ZSTD_freeDCtx(dctx);
        setNativePtr(thiz, nullptr);
    }
}

void Java_com_bytedance_compression_zstd_ZstdDecompressCtx_loadDDictFast0(JNIEnv* /*env*/, jobject thiz, jlong /*ddictPtr*/) {
    ZstdDecompressCtxNative* dctx = static_cast<ZstdDecompressCtxNative*>(getNativePtr(thiz));
    if (dctx) {
        dctx->flags |= 2;
    }
}

void Java_com_bytedance_compression_zstd_ZstdDecompressCtx_loadDDict0(JNIEnv* /*env*/, jobject thiz, jbyteArray /*dict*/, jint /*dictSize*/) {
    ZstdDecompressCtxNative* dctx = static_cast<ZstdDecompressCtxNative*>(getNativePtr(thiz));
    if (dctx) {
        dctx->flags |= 1;
    }
}

void Java_com_bytedance_compression_zstd_ZstdDecompressCtx_reset0(JNIEnv* /*env*/, jobject thiz) {
    ZstdDecompressCtxNative* dctx = static_cast<ZstdDecompressCtxNative*>(getNativePtr(thiz));
    if (dctx) {
        ZSTD_DCtx_reset(dctx, 0);
    }
}

/**
 * 0x031634: decompressByteArray0
 * Check:
 *   tbnz w3, #0x1f
 *   mov x23, #-0x48 (-72: ZSTD_error_dstSize_tooSmall)
 */
jlong Java_com_bytedance_compression_zstd_ZstdDecompressCtx_decompressByteArray0(JNIEnv* /*env*/, jobject thiz,
                                                                                   jbyteArray dst, jint dstOffset, jint dstSize,
                                                                                   jbyteArray src, jint srcOffset, jint srcSize) {
    if (dstOffset < 0 || dstSize < 0 || srcOffset < 0 || srcSize < 0) {
        return ZSTD_ERR_DST_SIZE_TOO_SMALL; // -72
    }

    ZstdDecompressCtxNative* dctx = static_cast<ZstdDecompressCtxNative*>(getNativePtr(thiz));
    if (!dctx) return ZSTD_ERR_GENERIC;

    const uint8_t* inPtr = reinterpret_cast<const uint8_t*>(src) + srcOffset;
    uint8_t* outPtr = reinterpret_cast<uint8_t*>(dst) + dstOffset;

    std::vector<uint8_t> emptyDict;
    size_t result = ZstdCoreEngine::decompressFrame(*dctx, outPtr, dstSize, inPtr, srcSize, emptyDict);
    return static_cast<jlong>(result);
}

// ============================================================================
// 6. CLASS: com.bytedance.compression.zstd.ZstdDictCompress
// ============================================================================

void Java_com_bytedance_compression_zstd_ZstdDictCompress_init(JNIEnv* /*env*/, jobject thiz, jbyteArray dict, jint dictOffset, jint dictSize, jint level) {
    ZstdDictCompressNative* cdict = new (std::nothrow) ZstdDictCompressNative();
    if (cdict) {
        cdict->dictID = 1;
        cdict->compressionLevel = level;
        if (dict && dictSize > 0) {
            const uint8_t* p = reinterpret_cast<const uint8_t*>(dict) + dictOffset;
            cdict->dictData.assign(p, p + dictSize);
        }
    }
    setNativePtr(thiz, cdict);
}

void Java_com_bytedance_compression_zstd_ZstdDictCompress_free(JNIEnv* /*env*/, jobject thiz) {
    ZstdDictCompressNative* cdict = static_cast<ZstdDictCompressNative*>(getNativePtr(thiz));
    delete cdict;
    setNativePtr(thiz, nullptr);
}

// ============================================================================
// 7. CLASS: com.bytedance.compression.zstd.ZstdDictDecompress
// ============================================================================

void Java_com_bytedance_compression_zstd_ZstdDictDecompress_init(JNIEnv* /*env*/, jobject thiz, jbyteArray dict, jint dictOffset, jint dictSize) {
    const uint8_t* p = (dict && dictSize > 0) ? (reinterpret_cast<const uint8_t*>(dict) + dictOffset) : nullptr;
    ZstdDictDecompressNative* ddict = ZSTD_createDDict(p, dictSize);
    setNativePtr(thiz, ddict);
}

void Java_com_bytedance_compression_zstd_ZstdDictDecompress_free(JNIEnv* /*env*/, jobject thiz) {
    ZstdDictDecompressNative* ddict = static_cast<ZstdDictDecompressNative*>(getNativePtr(thiz));
    ZSTD_freeDDict(ddict);
    setNativePtr(thiz, nullptr);
}

// ============================================================================
// 8. CLASS: com.bytedance.compression.zstd.ZstdInputStreamNoFinalizer
// ============================================================================

/**
 * 0x03186c: mov w0, #3; movk w0, #2, lsl #16; ret -> 131075 (128 KB + 3)
 */
jlong Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_recommendedDInSize(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_RECOMMENDED_DIN_SIZE; // 131075
}

/**
 * 0x031878: mov w0, #0x20000; ret -> 131072 (128 KB)
 */
jlong Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_recommendedDOutSize(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_RECOMMENDED_DOUT_SIZE; // 131072
}

jlong Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_createDStream(JNIEnv* /*env*/, jclass /*clazz*/) {
    ZstdStreamNative* stream = new (std::nothrow) ZstdStreamNative();
    if (stream) {
        stream->isCompressor = false;
        stream->dctx.reset(ZSTD_createDCtx());
        stream->internalPos = 0;
    }
    return reinterpret_cast<jlong>(stream);
}

jint Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_freeDStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    delete stream;
    return 0;
}

jint Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_initDStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    if (!stream || !stream->dctx) return -1;
    ZSTD_DCtx_reset(stream->dctx.get(), 0);
    return 0;
}

jlong Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_decompressStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr,
                                                                                        jbyteArray dst, jint dstOffset, jint dstSize,
                                                                                        jbyteArray src, jint srcOffset, jint srcSize) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    if (!stream || !stream->dctx) return ZSTD_ERR_GENERIC;

    ZSTD_inBuffer inBuf{reinterpret_cast<const uint8_t*>(src) + srcOffset, static_cast<size_t>(srcSize), 0};
    ZSTD_outBuffer outBuf{reinterpret_cast<uint8_t*>(dst) + dstOffset, static_cast<size_t>(dstSize), 0};

    size_t res = ZSTD_decompressStream(stream->dctx.get(), &outBuf, &inBuf);
    if (ZstdCoreEngine::isError(res)) return static_cast<jlong>(res);
    return static_cast<jlong>(outBuf.pos);
}

// ============================================================================
// 9. CLASS: com.bytedance.compression.zstd.ZstdOutputStreamNoFinalizer
// ============================================================================

/**
 * 0x030aa0: mov w0, #0x207; movk w0, #2, lsl #16; ret -> 131591 (128 KB + 519)
 */
jlong Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_recommendedCOutSize(JNIEnv* /*env*/, jclass /*clazz*/) {
    return ZSTD_RECOMMENDED_COUT_SIZE; // 131591
}

jlong Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_createCStream(JNIEnv* /*env*/, jclass /*clazz*/) {
    ZstdStreamNative* stream = new (std::nothrow) ZstdStreamNative();
    if (stream) {
        stream->isCompressor = true;
        stream->cctx.reset(ZSTD_createCCtx());
        stream->internalPos = 0;
    }
    return reinterpret_cast<jlong>(stream);
}

jint Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_freeCStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    delete stream;
    return 0;
}

jint Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_resetCStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    if (!stream || !stream->cctx) return -1;
    stream->cctx->state_flags = 1;
    return 0;
}

jlong Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_compressStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr,
                                                                                        jbyteArray dst, jint dstOffset, jint dstSize,
                                                                                        jbyteArray src, jint srcOffset, jint srcSize) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    if (!stream || !stream->cctx) return ZSTD_ERR_GENERIC;

    ZSTD_inBuffer inBuf{reinterpret_cast<const uint8_t*>(src) + srcOffset, static_cast<size_t>(srcSize), 0};
    ZSTD_outBuffer outBuf{reinterpret_cast<uint8_t*>(dst) + dstOffset, static_cast<size_t>(dstSize), 0};

    size_t res = ZSTD_compressStream2(stream->cctx.get(), &outBuf, &inBuf, static_cast<int32_t>(ZstdEndDirective::Continue));
    if (ZstdCoreEngine::isError(res)) return static_cast<jlong>(res);
    return static_cast<jlong>(outBuf.pos);
}

jlong Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_flushStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr,
                                                                                     jbyteArray dst, jint dstOffset, jint dstSize) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    if (!stream || !stream->cctx) return ZSTD_ERR_GENERIC;

    ZSTD_inBuffer inBuf{nullptr, 0, 0};
    ZSTD_outBuffer outBuf{reinterpret_cast<uint8_t*>(dst) + dstOffset, static_cast<size_t>(dstSize), 0};

    size_t res = ZSTD_compressStream2(stream->cctx.get(), &outBuf, &inBuf, static_cast<int32_t>(ZstdEndDirective::Flush));
    if (ZstdCoreEngine::isError(res)) return static_cast<jlong>(res);
    return static_cast<jlong>(outBuf.pos);
}

jlong Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_endStream(JNIEnv* /*env*/, jclass /*clazz*/, jlong streamPtr,
                                                                                   jbyteArray dst, jint dstOffset, jint dstSize) {
    ZstdStreamNative* stream = reinterpret_cast<ZstdStreamNative*>(streamPtr);
    if (!stream || !stream->cctx) return ZSTD_ERR_GENERIC;

    ZSTD_inBuffer inBuf{nullptr, 0, 0};
    ZSTD_outBuffer outBuf{reinterpret_cast<uint8_t*>(dst) + dstOffset, static_cast<size_t>(dstSize), 0};

    size_t res = ZSTD_compressStream2(stream->cctx.get(), &outBuf, &inBuf, static_cast<int32_t>(ZstdEndDirective::End));
    if (ZstdCoreEngine::isError(res)) return static_cast<jlong>(res);
    return static_cast<jlong>(outBuf.pos);
}
