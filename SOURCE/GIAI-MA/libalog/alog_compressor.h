/**
 * @file alog_compressor.h
 * @brief ByteDance ALog Dual-Engine Compressor (Zlib / Zstandard) Interface.
 *        Giao diện bộ nén dữ liệu kép (Zlib và Zstandard) của hệ thống ALog.
 */

#ifndef BYTEDANCE_ALOG_COMPRESSOR_H
#define BYTEDANCE_ALOG_COMPRESSOR_H

#include "alog_types.h"
#include <zlib.h>

#ifdef __cplusplus
extern "C" {
#endif

// Function pointer signatures for dynamically loaded ZSTD functions
typedef void* (*FnZstdCreateCCtx)(void);
typedef size_t (*FnZstdFreeCCtx)(void* cctx);
typedef size_t (*FnZstdCompressCCtx)(void* cctx, void* dst, size_t dstCapacity,
                                     const void* src, size_t srcSize, int compressionLevel);

typedef struct AlogCompressor_t {
    AlogCompressorType  type;               ///< Compressor type (Zlib / Zstd / None)
    int32_t             level;              ///< Compression level
    z_stream            zstream;            ///< Zlib streaming context
    bool                zlib_initialized;   ///< Zlib context active flag
    void*               zstd_handle;        ///< Dynamic handle to libzstd.so via dlopen
    void*               zstd_cctx;          ///< Zstd compression context
    FnZstdCreateCCtx    fn_zstd_create;     ///< dlsym: ZSTD_createCCtx
    FnZstdFreeCCtx      fn_zstd_free;       ///< dlsym: ZSTD_freeCCtx
    FnZstdCompressCCtx  fn_zstd_compress;   ///< dlsym: ZSTD_compressCCtx
    pthread_mutex_t     lock;               ///< Compressor re-entrant lock
} AlogCompressor;

/**
 * @brief Create and configure compressor instance according to configuration.
 *        Khởi tạo và cấu hình bộ nén dựa trên tham số chỉ định.
 */
AlogCompressor* alog_compressor_create(AlogCompressorType type, int level);

/**
 * @brief Compress an input chunk of memory into output buffer.
 *        Nén khối dữ liệu đầu vào vào bộ đệm đầu ra.
 * @return Number of compressed bytes written to out_buf, or negative on failure.
 */
int32_t alog_compressor_compress(AlogCompressor* comp,
                                 const uint8_t* in_buf, size_t in_len,
                                 uint8_t* out_buf, size_t out_capacity,
                                 bool flush);

/**
 * @brief Calculate upper bound of output buffer size required for given input size.
 *        Tính cận trên kích thước bộ đệm đầu ra cần thiết cho kích thước đầu vào.
 */
size_t alog_compressor_bound(AlogCompressor* comp, size_t in_len);

/**
 * @brief Reset compression stream state.
 *        Đặt lại trạng thái luồng nén.
 */
void alog_compressor_reset(AlogCompressor* comp);

/**
 * @brief Destroy compressor and release underlying library contexts.
 *        Giải phóng bộ nén và dọn dẹp ngữ cảnh thư viện liên quan.
 */
void alog_compressor_destroy(AlogCompressor* comp);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_COMPRESSOR_H
