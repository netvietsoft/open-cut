/**
 * @file bdzstd_context.h
 * @brief ByteDance Zstandard Engine - 16 Exported C API Functions.
 *        Triển khai 16 hàm C-Export chuẩn của Zstandard trong libbdzstd.so.
 *
 * Rules: AGENTS.md Rule 12 (Bilingual EN/VN), Rule 14 & 20 (Zero stubs, exact binary parity).
 */

#ifndef BDZSTD_CONTEXT_H
#define BDZSTD_CONTEXT_H

#include "bdzstd_types.h"
#include "bdzstd_core.h"
#include <cstddef>
#include <cstdint>

#ifdef __cplusplus
extern "C" {
#endif

// ============================================================================
// 16 EXPORTED C FUNCTIONS (ABI IDENTICAL TO ORIGINAL LIBBDZSTD.SO)
// 16 hàm C được export trực tiếp qua dynamic symbol table (.dynsym)
// ============================================================================

/** @brief 0x0040f8: Check if status code represents an error */
unsigned ZSTD_isError(size_t code);

/** @brief 0x006750: Maximum compressed bound for given source size */
size_t ZSTD_compressBound(size_t srcSize);

/** @brief 0x006770: Create compression context */
bytedance::compression::zstd::ZstdCompressCtxNative* ZSTD_createCCtx(void);

/** @brief 0x006930: Free compression context */
size_t ZSTD_freeCCtx(bytedance::compression::zstd::ZstdCompressCtxNative* cctx);

/** @brief 0x006b38: Set compression parameter on CCtx */
size_t ZSTD_CCtx_setParameter(bytedance::compression::zstd::ZstdCompressCtxNative* cctx,
                              int32_t param, int32_t value);

/** @brief 0x007000: Set pledged uncompressed source size */
size_t ZSTD_CCtx_setPledgedSrcSize(bytedance::compression::zstd::ZstdCompressCtxNative* cctx,
                                   uint64_t pledgedSrcSize);

/** @brief 0x007024: Load compression dictionary into context */
size_t ZSTD_CCtx_loadDictionary(bytedance::compression::zstd::ZstdCompressCtxNative* cctx,
                                const void* dict, size_t dictSize);

/** @brief 0x008c54: Advanced streaming compression function */
size_t ZSTD_compressStream2(bytedance::compression::zstd::ZstdCompressCtxNative* cctx,
                            bytedance::compression::zstd::ZSTD_outBuffer* output,
                            bytedance::compression::zstd::ZSTD_inBuffer* input,
                            int32_t endOp);

/** @brief 0x02a694: Create decompression dictionary */
bytedance::compression::zstd::ZstdDictDecompressNative* ZSTD_createDDict(const void* dict, size_t dictSize);

/** @brief 0x02a624: Free decompression dictionary */
size_t ZSTD_freeDDict(bytedance::compression::zstd::ZstdDictDecompressNative* ddict);

/** @brief 0x02a6bc: Create decompression context */
bytedance::compression::zstd::ZstdDecompressCtxNative* ZSTD_createDCtx(void);

/** @brief 0x02a74c: Free decompression context */
size_t ZSTD_freeDCtx(bytedance::compression::zstd::ZstdDecompressCtxNative* dctx);

/** @brief 0x02c200: Load decompression dictionary into DCtx */
size_t ZSTD_DCtx_loadDictionary(bytedance::compression::zstd::ZstdDecompressCtxNative* dctx,
                                const void* dict, size_t dictSize);

/** @brief 0x02c324: Reset decompression context state */
size_t ZSTD_DCtx_reset(bytedance::compression::zstd::ZstdDecompressCtxNative* dctx, uint32_t resetDirective);

/** @brief 0x02c40c: Reference pre-parsed DDict into DCtx */
size_t ZSTD_DCtx_refDDict(bytedance::compression::zstd::ZstdDecompressCtxNative* dctx,
                          const bytedance::compression::zstd::ZstdDictDecompressNative* ddict);

/** @brief 0x02c8d4: Streaming decompression function */
size_t ZSTD_decompressStream(bytedance::compression::zstd::ZstdDecompressCtxNative* dctx,
                             bytedance::compression::zstd::ZSTD_outBuffer* output,
                             bytedance::compression::zstd::ZSTD_inBuffer* input);

#ifdef __cplusplus
}
#endif

#endif // BDZSTD_CONTEXT_H
