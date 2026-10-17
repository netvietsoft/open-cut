/**
 * @file bdzstd_jni.h
 * @brief ByteDance Zstandard Engine - 52 Exported JNI Function Signatures.
 *        Khai báo nguyên mẫu 52 hàm JNI thuộc package com.bytedance.compression.zstd.*.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDZSTD_JNI_H
#define BDZSTD_JNI_H

#include "bdzstd_types.h"
#include <cstdint>
#include <cstddef>

// Standard JNI Types Emulation for pure cleanroom compilation without JDK dependency
using jint = int32_t;
using jlong = int64_t;
using jbyte = int8_t;
using jboolean = uint8_t;
using jsize = int32_t;

struct _jobject {};
using jobject = _jobject*;
using jclass = _jobject*;
using jstring = _jobject*;
using jarray = _jobject*;
using jbyteArray = _jobject*;
using jlongArray = _jobject*;
using jobjectArray = _jobject*;

struct JNIEnv;

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// 1. CLASS: com.bytedance.compression.zstd.Zstd
// ============================================================================
jboolean Java_com_bytedance_compression_zstd_Zstd_isError(JNIEnv* env, jclass clazz, jlong code);
jstring  Java_com_bytedance_compression_zstd_Zstd_getErrorName(JNIEnv* env, jclass clazz, jlong code);
jlong    Java_com_bytedance_compression_zstd_Zstd_getErrorCode(JNIEnv* env, jclass clazz, jlong code);
jlongArray Java_com_bytedance_compression_zstd_Zstd_getFunAddressesBySymbols(JNIEnv* env, jclass clazz, jobjectArray symbolNames);
jlong    Java_com_bytedance_compression_zstd_Zstd_errGeneric(JNIEnv* env, jclass clazz);

// ============================================================================
// 2. CLASS: com.bytedance.compression.zstd.ZstdCompress
// ============================================================================
jlong    Java_com_bytedance_compression_zstd_ZstdCompress_compressBound(JNIEnv* env, jclass clazz, jlong srcSize);
jint     Java_com_bytedance_compression_zstd_ZstdCompress_defaultCompressionLevel(JNIEnv* env, jclass clazz);
jint     Java_com_bytedance_compression_zstd_ZstdCompress_minCompressionLevel(JNIEnv* env, jclass clazz);
jint     Java_com_bytedance_compression_zstd_ZstdCompress_maxCompressionLevel(JNIEnv* env, jclass clazz);
void     Java_com_bytedance_compression_zstd_ZstdCompress_loadDictCompress(JNIEnv* env, jclass clazz, jlong cctxPtr, jbyteArray dict, jint dictSize);
void     Java_com_bytedance_compression_zstd_ZstdCompress_loadFastDictCompress(JNIEnv* env, jclass clazz, jlong cctxPtr, jlong dictPtr);
void     Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionChecksums(JNIEnv* env, jclass clazz, jlong cctxPtr, jboolean checksum);
void     Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionLevel(JNIEnv* env, jclass clazz, jlong cctxPtr, jint level);
void     Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionLong(JNIEnv* env, jclass clazz, jlong cctxPtr, jint windowLog);
void     Java_com_bytedance_compression_zstd_ZstdCompress_setCompressionWorkers(JNIEnv* env, jclass clazz, jlong cctxPtr, jint workers);

// ============================================================================
// 3. CLASS: com.bytedance.compression.zstd.ZstdCompressCtx
// ============================================================================
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_init(JNIEnv* env, jobject thiz);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_free(JNIEnv* env, jobject thiz);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_setLevel0(JNIEnv* env, jobject thiz, jint level);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_setChecksum0(JNIEnv* env, jobject thiz, jboolean checksum);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_setContentSize0(JNIEnv* env, jobject thiz, jboolean contentSize);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_setDictID0(JNIEnv* env, jobject thiz, jboolean dictID);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_loadCDictFast0(JNIEnv* env, jobject thiz, jlong cdictPtr);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_loadCDict0(JNIEnv* env, jobject thiz, jbyteArray dict, jint dictSize);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_reset0(JNIEnv* env, jobject thiz);
void     Java_com_bytedance_compression_zstd_ZstdCompressCtx_setPledgedSrcSize0(JNIEnv* env, jobject thiz, jlong pledgedSrcSize);
jlong    Java_com_bytedance_compression_zstd_ZstdCompressCtx_compressByteArray0(JNIEnv* env, jobject thiz,
                                                                               jbyteArray dst, jint dstOffset, jint dstSize,
                                                                               jbyteArray src, jint srcOffset, jint srcSize);

// ============================================================================
// 4. CLASS: com.bytedance.compression.zstd.ZstdDecompress
// ============================================================================
jlong    Java_com_bytedance_compression_zstd_ZstdDecompress_decompressedSize0(JNIEnv* env, jclass clazz, jbyteArray src, jint srcOffset, jint srcSize);
void     Java_com_bytedance_compression_zstd_ZstdDecompress_loadDictDecompress(JNIEnv* env, jclass clazz, jlong dctxPtr, jbyteArray dict, jint dictSize);
void     Java_com_bytedance_compression_zstd_ZstdDecompress_loadFastDictDecompress(JNIEnv* env, jclass clazz, jlong dctxPtr, jlong ddictPtr);

// ============================================================================
// 5. CLASS: com.bytedance.compression.zstd.ZstdDecompressCtx
// ============================================================================
void     Java_com_bytedance_compression_zstd_ZstdDecompressCtx_init(JNIEnv* env, jobject thiz);
void     Java_com_bytedance_compression_zstd_ZstdDecompressCtx_free(JNIEnv* env, jobject thiz);
void     Java_com_bytedance_compression_zstd_ZstdDecompressCtx_loadDDictFast0(JNIEnv* env, jobject thiz, jlong ddictPtr);
void     Java_com_bytedance_compression_zstd_ZstdDecompressCtx_loadDDict0(JNIEnv* env, jobject thiz, jbyteArray dict, jint dictSize);
void     Java_com_bytedance_compression_zstd_ZstdDecompressCtx_reset0(JNIEnv* env, jobject thiz);
jlong    Java_com_bytedance_compression_zstd_ZstdDecompressCtx_decompressByteArray0(JNIEnv* env, jobject thiz,
                                                                                   jbyteArray dst, jint dstOffset, jint dstSize,
                                                                                   jbyteArray src, jint srcOffset, jint srcSize);

// ============================================================================
// 6. CLASS: com.bytedance.compression.zstd.ZstdDictCompress
// ============================================================================
void     Java_com_bytedance_compression_zstd_ZstdDictCompress_init(JNIEnv* env, jobject thiz, jbyteArray dict, jint dictOffset, jint dictSize, jint level);
void     Java_com_bytedance_compression_zstd_ZstdDictCompress_free(JNIEnv* env, jobject thiz);

// ============================================================================
// 7. CLASS: com.bytedance.compression.zstd.ZstdDictDecompress
// ============================================================================
void     Java_com_bytedance_compression_zstd_ZstdDictDecompress_init(JNIEnv* env, jobject thiz, jbyteArray dict, jint dictOffset, jint dictSize);
void     Java_com_bytedance_compression_zstd_ZstdDictDecompress_free(JNIEnv* env, jobject thiz);

// ============================================================================
// 8. CLASS: com.bytedance.compression.zstd.ZstdInputStreamNoFinalizer
// ============================================================================
jlong    Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_recommendedDInSize(JNIEnv* env, jclass clazz);
jlong    Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_recommendedDOutSize(JNIEnv* env, jclass clazz);
jlong    Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_createDStream(JNIEnv* env, jclass clazz);
jint     Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_freeDStream(JNIEnv* env, jclass clazz, jlong streamPtr);
jint     Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_initDStream(JNIEnv* env, jclass clazz, jlong streamPtr);
jlong    Java_com_bytedance_compression_zstd_ZstdInputStreamNoFinalizer_decompressStream(JNIEnv* env, jclass clazz, jlong streamPtr,
                                                                                        jbyteArray dst, jint dstOffset, jint dstSize,
                                                                                        jbyteArray src, jint srcOffset, jint srcSize);

// ============================================================================
// 9. CLASS: com.bytedance.compression.zstd.ZstdOutputStreamNoFinalizer
// ============================================================================
jlong    Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_recommendedCOutSize(JNIEnv* env, jclass clazz);
jlong    Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_createCStream(JNIEnv* env, jclass clazz);
jint     Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_freeCStream(JNIEnv* env, jclass clazz, jlong streamPtr);
jint     Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_resetCStream(JNIEnv* env, jclass clazz, jlong streamPtr);
jlong    Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_compressStream(JNIEnv* env, jclass clazz, jlong streamPtr,
                                                                                        jbyteArray dst, jint dstOffset, jint dstSize,
                                                                                        jbyteArray src, jint srcOffset, jint srcSize);
jlong    Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_flushStream(JNIEnv* env, jclass clazz, jlong streamPtr,
                                                                                     jbyteArray dst, jint dstOffset, jint dstSize);
jlong    Java_com_bytedance_compression_zstd_ZstdOutputStreamNoFinalizer_endStream(JNIEnv* env, jclass clazz, jlong streamPtr,
                                                                                   jbyteArray dst, jint dstOffset, jint dstSize);

#ifdef __cplusplus
}
#endif

#endif // BDZSTD_JNI_H
