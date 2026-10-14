// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttffmpeg.so (ByteDance Customized FFmpeg Core)
// File: tt_drm_crypto.h
// Description: Header for ByteDance DRM Decryption & GF(2^8) Stream Cipher
// ===================================================================================

#pragma once

#include "ttffmpeg_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- Custom DRM Registration ---
void tt_register_drm(void* init_fn, void* decrypt_fn, void* free_fn);
int32_t tt_drm_decrypt_packet(void* ctx, uint8_t* data, int32_t data_len);

// --- Deprecated Ctx Cipher (Rijndael GF(2^8) stream decryptor) ---
TTDeprecatedCtx* tt_deprecated_ctx_alloc(void);
void tt_deprecated_ctx_free(TTDeprecatedCtx* ctx);
int32_t tt_deprecated_ctx_init(TTDeprecatedCtx* ctx, const uint8_t* key, int32_t key_len, int32_t mode);
int32_t tt_deprecated_ctx_process(TTDeprecatedCtx* ctx, uint8_t* dst, const uint8_t* src, int32_t len);

#ifdef __cplusplus
}
#endif
