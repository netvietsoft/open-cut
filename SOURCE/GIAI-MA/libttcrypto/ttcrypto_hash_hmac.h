// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_hash_hmac.h
// Description: Declarations for SHA-256, SHA-512, HMAC (RFC 2104), and HKDF (RFC 5869)
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_HASH_HMAC_H_
#define NEXTAI_OPENCUT_TTCRYPTO_HASH_HMAC_H_

#include "ttcrypto_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- SHA-224 & SHA-256 (0x0be370..0x0be5c0) ---
int SHA224_Init(SHA256_CTX* c);
int SHA256_Init(SHA256_CTX* c);
void SHA256_Transform(SHA256_CTX* c, const uint8_t* data);
int SHA256_Update(SHA256_CTX* c, const void* data, size_t len);
int SHA256_Final(uint8_t* md, SHA256_CTX* c);
uint8_t* SHA256(const uint8_t* d, size_t n, uint8_t* md);

// --- SHA-384 & SHA-512 ---
int SHA384_Init(SHA512_CTX* c);
int SHA512_Init(SHA512_CTX* c);
void SHA512_Transform(SHA512_CTX* c, const uint8_t* data);
int SHA512_Update(SHA512_CTX* c, const void* data, size_t len);
int SHA512_Final(uint8_t* md, SHA512_CTX* c);
uint8_t* SHA512(const uint8_t* d, size_t n, uint8_t* md);

// --- HMAC-SHA256 (0x0b6f6c..0x0b7380) ---
void HMAC_CTX_init(HMAC_CTX* ctx);
void HMAC_CTX_cleanup(HMAC_CTX* ctx);
int HMAC_Init_ex(HMAC_CTX* ctx, const void* key, size_t key_len, const void* md, void* impl);
int HMAC_Update(HMAC_CTX* ctx, const uint8_t* data, size_t data_len);
int HMAC_Final(HMAC_CTX* ctx, uint8_t* out, unsigned int* out_len);
uint8_t* HMAC(const void* evp_md, const void* key, int key_len,
              const uint8_t* d, size_t n, uint8_t* md, unsigned int* md_len);

// --- HKDF RFC 5869 (0x070ea8..0x0710f4) ---
int HKDF_extract(uint8_t* out_key, size_t* out_len, const void* digest,
                 const uint8_t* secret, size_t secret_len,
                 const uint8_t* salt, size_t salt_len);
int HKDF_expand(uint8_t* out_key, size_t out_len, const void* digest,
                const uint8_t* prk, size_t prk_len,
                const uint8_t* info, size_t info_len);
int HKDF(uint8_t* out_key, size_t out_len, const void* digest,
         const uint8_t* secret, size_t secret_len,
         const uint8_t* salt, size_t salt_len,
         const uint8_t* info, size_t info_len);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_HASH_HMAC_H_
