/**
 * @file alog_compressor.cpp
 * @brief ByteDance ALog Dual-Engine Compressor Implementation.
 *        Hiện thực bộ nén dữ liệu kép (Zlib và Zstandard) của hệ thống ALog.
 */

#include "alog_compressor.h"
#include <stdlib.h>
#include <string.h>
#include <dlfcn.h>

AlogCompressor* alog_compressor_create(AlogCompressorType type, int level) {
    AlogCompressor* comp = (AlogCompressor*)calloc(1, sizeof(AlogCompressor));
    if (!comp) return NULL;

    comp->type = type;
    comp->level = (level <= 0) ? 6 : level;
    pthread_mutex_init(&comp->lock, NULL);

    if (type == ALOG_COMPRESS_ZLIB) {
        memset(&comp->zstream, 0, sizeof(comp->zstream));
        // deflateInit2_ with windowBits = -15 for raw deflate stream without zlib wrapper
        // Khởi tạo deflateInit2_ với windowBits = -15 cho luồng nén raw không có header zlib
        int ret = deflateInit2_(&comp->zstream, comp->level, Z_DEFLATED, -15, 8, Z_DEFAULT_STRATEGY,
                                ZLIB_VERSION, (int)sizeof(z_stream));
        if (ret == Z_OK) {
            comp->zlib_initialized = true;
        } else {
            pthread_mutex_destroy(&comp->lock);
            free(comp);
            return NULL;
        }
    } else if (type == ALOG_COMPRESS_ZSTD) {
        // Dynamically resolve ZSTD symbols if libzstd.so exists
        // Phân giải động các biểu tượng ZSTD nếu tồn tại libzstd.so
        comp->zstd_handle = dlopen("libzstd.so", RTLD_NOW);
        if (!comp->zstd_handle) {
            // Fallback to builtin / local lib
            comp->zstd_handle = dlopen("libzstd_capcut.so", RTLD_NOW);
        }

        if (comp->zstd_handle) {
            comp->fn_zstd_create = (FnZstdCreateCCtx)dlsym(comp->zstd_handle, "ZSTD_createCCtx");
            comp->fn_zstd_free = (FnZstdFreeCCtx)dlsym(comp->zstd_handle, "ZSTD_freeCCtx");
            comp->fn_zstd_compress = (FnZstdCompressCCtx)dlsym(comp->zstd_handle, "ZSTD_compressCCtx");

            if (comp->fn_zstd_create) {
                comp->zstd_cctx = comp->fn_zstd_create();
            }
        }

        // If Zstd fails to load, gracefully fallback to Zlib
        // Nếu không tải được Zstd, tự động chuyển về chế độ Zlib dự phòng
        if (!comp->zstd_cctx) {
            comp->type = ALOG_COMPRESS_ZLIB;
            memset(&comp->zstream, 0, sizeof(comp->zstream));
            deflateInit2_(&comp->zstream, comp->level, Z_DEFLATED, -15, 8, Z_DEFAULT_STRATEGY,
                          ZLIB_VERSION, (int)sizeof(z_stream));
            comp->zlib_initialized = true;
        }
    }

    return comp;
}

int32_t alog_compressor_compress(AlogCompressor* comp,
                                 const uint8_t* in_buf, size_t in_len,
                                 uint8_t* out_buf, size_t out_capacity,
                                 bool flush) {
    if (!comp || !in_buf || !out_buf || in_len == 0 || out_capacity == 0) {
        return -1;
    }

    pthread_mutex_lock(&comp->lock);

    if (comp->type == ALOG_COMPRESS_ZLIB && comp->zlib_initialized) {
        comp->zstream.next_in = (Bytef*)in_buf;
        comp->zstream.avail_in = (uInt)in_len;
        comp->zstream.next_out = (Bytef*)out_buf;
        comp->zstream.avail_out = (uInt)out_capacity;

        int flush_mode = flush ? Z_SYNC_FLUSH : Z_NO_FLUSH;
        int ret = deflate(&comp->zstream, flush_mode);
        if (ret != Z_OK && ret != Z_STREAM_END && ret != Z_BUF_ERROR) {
            pthread_mutex_unlock(&comp->lock);
            return -2;
        }

        int32_t compressed_len = (int32_t)(out_capacity - comp->zstream.avail_out);
        pthread_mutex_unlock(&comp->lock);
        return compressed_len;
    } else if (comp->type == ALOG_COMPRESS_ZSTD && comp->zstd_cctx && comp->fn_zstd_compress) {
        size_t c_size = comp->fn_zstd_compress(comp->zstd_cctx, out_buf, out_capacity,
                                               in_buf, in_len, comp->level);
        pthread_mutex_unlock(&comp->lock);
        return (int32_t)c_size;
    } else {
        // ALOG_COMPRESS_NONE: direct raw copy
        // Chế độ không nén: sao chép dữ liệu thô trực tiếp
        size_t copy_len = (in_len < out_capacity) ? in_len : out_capacity;
        memcpy(out_buf, in_buf, copy_len);
        pthread_mutex_unlock(&comp->lock);
        return (int32_t)copy_len;
    }
}

size_t alog_compressor_bound(AlogCompressor* comp, size_t in_len) {
    if (!comp) return in_len + 64;

    if (comp->type == ALOG_COMPRESS_ZLIB) {
        return (size_t)deflateBound((z_streamp)&comp->zstream, (uLong)in_len) + 16;
    } else if (comp->type == ALOG_COMPRESS_ZSTD) {
        // ZSTD bound formula approximation: srcSize + (srcSize >> 8) + 64
        return in_len + (in_len >> 8) + 64;
    }
    return in_len;
}

void alog_compressor_reset(AlogCompressor* comp) {
    if (!comp) return;
    pthread_mutex_lock(&comp->lock);
    if (comp->type == ALOG_COMPRESS_ZLIB && comp->zlib_initialized) {
        deflateReset(&comp->zstream);
    }
    pthread_mutex_unlock(&comp->lock);
}

void alog_compressor_destroy(AlogCompressor* comp) {
    if (!comp) return;

    pthread_mutex_lock(&comp->lock);
    if (comp->zlib_initialized) {
        deflateEnd(&comp->zstream);
        comp->zlib_initialized = false;
    }

    if (comp->zstd_cctx && comp->fn_zstd_free) {
        comp->fn_zstd_free(comp->zstd_cctx);
        comp->zstd_cctx = NULL;
    }

    if (comp->zstd_handle) {
        dlclose(comp->zstd_handle);
        comp->zstd_handle = NULL;
    }
    pthread_mutex_unlock(&comp->lock);

    pthread_mutex_destroy(&comp->lock);
    free(comp);
}
