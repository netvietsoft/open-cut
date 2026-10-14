// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_drm_crypto.cpp
// Description: Full implementation of ByteDance DRM Decryption & GF(2^8) Stream Cipher
// Bilingual Comments: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "tt_drm_crypto.h"
#include <stdlib.h>
#include <string.h>

// ===================================================================================
// 1. GLOBAL DRM CALLBACKS STORAGE
// Bộ lưu trữ con trỏ hàm DRM toàn cục tại offset 0x7c57d0
// ===================================================================================

static TTDRMCallbacks g_drm_callbacks = { NULL, NULL, NULL };

/**
 * @brief Registers custom DRM decryption callbacks into global table.
 * Đăng ký 3 con trỏ hàm giải mã DRM (init, decrypt, free) vào bảng toàn cục 0x7c57d0.
 * Opcode ARM64: 0x364974..0x364988
 */
void tt_register_drm(void* init_fn, void* decrypt_fn, void* free_fn) {
    g_drm_callbacks.drm_init = (int (*)(void*, const uint8_t*, int))init_fn;
    g_drm_callbacks.drm_decrypt = (int (*)(void*, uint8_t*, int))decrypt_fn;
    g_drm_callbacks.drm_free = (void (*)(void*))free_fn;
}

/**
 * @brief Invokes active DRM decryptor callback on encrypted media payload.
 * Gọi callback giải mã gói tin đa phương tiện được bảo vệ bởi bản quyền DRM.
 */
int32_t tt_drm_decrypt_packet(void* ctx, uint8_t* data, int32_t data_len) {
    if (g_drm_callbacks.drm_decrypt) {
        return g_drm_callbacks.drm_decrypt(ctx, data, data_len);
    }
    return 0; // Passthrough if no DRM registered
}


// ===================================================================================
// 2. GALOIS FIELD GF(2^8) STREAM CIPHER (DEPRECATED CTX)
// Động cơ Mã hóa Luồng Trường Hữu hạn GF(2^8)
// ===================================================================================

/**
 * @brief Allocates a new TTDeprecatedCtx cipher context.
 * Cấp phát ngữ cảnh mã hóa kích thước 0x130 (304 bytes).
 * Opcode ARM64: 0x3636bc..0x3636dc
 */
TTDeprecatedCtx* tt_deprecated_ctx_alloc(void) {
    TTDeprecatedCtx* ctx = (TTDeprecatedCtx*)calloc(1, sizeof(TTDeprecatedCtx));
    if (ctx) {
        ctx->processed_bytes = 0; // offset 0x128
    }
    return ctx;
}

/**
 * @brief Frees a TTDeprecatedCtx structure.
 * Giải phóng ngữ cảnh mã hóa.
 */
void tt_deprecated_ctx_free(TTDeprecatedCtx* ctx) {
    if (ctx) {
        free(ctx);
    }
}

/**
 * @brief Multiplies two elements in GF(2^8) with irreducible polynomial 0x11b.
 * Nhân hai phần tử trên trường hữu hạn GF(2^8) với đa thức tối giản x^8 + x^4 + x^3 + x + 1 (0x11b).
 * Khớp opcode ARM64: 0x36373c (mov w3, #0x11b)
 */
static inline uint8_t gf_mult_11b(uint8_t a, uint8_t b) {
    uint8_t p = 0;
    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            p ^= a;
        }
        uint8_t hi_bit_set = (a & 0x80);
        a <<= 1;
        if (hi_bit_set) {
            a ^= 0x1b; // 0x11b modulo x^8
        }
        b >>= 1;
    }
    return p;
}

/**
 * @brief Initializes the GF(2^8) S-box and key schedule.
 * Khởi tạo bảng S-box và lịch khóa vòng dựa trên trường hữu hạn GF(2^8).
 * Opcode ARM64: 0x3636e0..0x363a34 (856 bytes)
 */
int32_t tt_deprecated_ctx_init(TTDeprecatedCtx* ctx, const uint8_t* key, int32_t key_len, int32_t mode) {
    if (!ctx || !key || key_len <= 0) {
        return -1;
    }

    (void)mode;
    ctx->processed_bytes = 0;

    // Generate GF(2^8) generator table using polynomial 0x11b
    uint8_t exp_table[256];
    uint8_t log_table[256];
    uint8_t val = 1;

    for (int i = 0; i < 255; i++) {
        exp_table[i] = val;
        log_table[val] = (uint8_t)i;
        val = gf_mult_11b(val, 0x03); // Generator element 3
    }
    exp_table[255] = exp_table[0];
    log_table[0] = 0;

    // Generate affine transformation S-box
    for (int i = 0; i < 256; i++) {
        uint8_t inv = 0;
        if (i != 0) {
            inv = exp_table[255 - log_table[i]];
        }
        // Affine transformation: s = inv ^ (inv <<< 1) ^ (inv <<< 2) ^ (inv <<< 3) ^ (inv <<< 4) ^ 0x63
        uint8_t s = inv;
        s ^= (uint8_t)((inv << 1) | (inv >> 7));
        s ^= (uint8_t)((inv << 2) | (inv >> 6));
        s ^= (uint8_t)((inv << 3) | (inv >> 5));
        s ^= (uint8_t)((inv << 4) | (inv >> 4));
        s ^= 0x63;

        ctx->sbox[i] = s;
        ctx->inv_sbox[s] = (uint8_t)i;
    }

    // Expand key into key_schedule
    for (int i = 0; i < 60; i++) {
        uint32_t k = 0;
        for (int b = 0; b < 4; b++) {
            k = (k << 8) | key[(i * 4 + b) % key_len];
        }
        ctx->key_schedule[i] = k;
    }

    return 0;
}

/**
 * @brief Processes stream decryption on media chunks using GF(2^8) S-box.
 * Giải mã luồng dữ liệu đa phương tiện sử dụng bảng thế S-box GF(2^8) và XOR khóa vòng.
 * Opcode ARM64: 0x363a38..0x363b90 (344 bytes)
 */
int32_t tt_deprecated_ctx_process(TTDeprecatedCtx* ctx, uint8_t* dst, const uint8_t* src, int32_t len) {
    if (!ctx || !dst || !src || len <= 0) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        uint64_t pos = ctx->processed_bytes + i;
        uint32_t k = ctx->key_schedule[(pos >> 4) % 60];
        uint8_t key_byte = (uint8_t)(k >> ((pos & 3) * 8));

        // Decrypt byte through inverted affine S-box and key XOR
        uint8_t in_byte = src[i];
        uint8_t dec_byte = ctx->inv_sbox[in_byte] ^ key_byte;
        dst[i] = dec_byte;
    }

    ctx->processed_bytes += len;
    return len;
}
