// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_aes_gcm.h
// Description: Declarations for AES-128/192/256 (ECB, CBC, CTR) and GCM-128 AEAD
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_AES_GCM_H_
#define NEXTAI_OPENCUT_TTCRYPTO_AES_GCM_H_

#include "ttcrypto_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- AES Core Key Schedule & Block Operations (0x0a4850..0x0a4b20) ---
int AES_set_encrypt_key(const uint8_t* userKey, int bits, AES_KEY* key);
int AES_set_decrypt_key(const uint8_t* userKey, int bits, AES_KEY* key);
void AES_encrypt(const uint8_t* in, uint8_t* out, const AES_KEY* key);
void AES_decrypt(const uint8_t* in, uint8_t* out, const AES_KEY* key);
void AES_cbc_encrypt(const uint8_t* in, uint8_t* out, size_t len,
                     const AES_KEY* key, uint8_t* ivec, int enc);
void AES_ctr128_encrypt(const uint8_t* in, uint8_t* out, size_t len,
                        const AES_KEY* key, uint8_t ivec[16],
                        uint8_t ecount_buf[16], unsigned int* num);

// --- AES-GCM128 Authenticated Encryption (0x0b8c50..0x0b9658) ---
void CRYPTO_gcm128_init(GCM128_CONTEXT* ctx, const AES_KEY* key, const void* block_func);
void CRYPTO_gcm128_setiv(GCM128_CONTEXT* ctx, const AES_KEY* key, const uint8_t* iv, size_t len);
int CRYPTO_gcm128_aad(GCM128_CONTEXT* ctx, const uint8_t* aad, size_t len);
int CRYPTO_gcm128_encrypt(GCM128_CONTEXT* ctx, const AES_KEY* key,
                          const uint8_t* in, uint8_t* out, size_t len);
int CRYPTO_gcm128_decrypt(GCM128_CONTEXT* ctx, const AES_KEY* key,
                          const uint8_t* in, uint8_t* out, size_t len);
int CRYPTO_gcm128_finish(GCM128_CONTEXT* ctx, const uint8_t* tag, size_t len);
void CRYPTO_gcm128_tag(GCM128_CONTEXT* ctx, uint8_t* tag, size_t len);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_AES_GCM_H_
