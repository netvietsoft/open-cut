// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_evp_x509.h
// Description: Declarations for EVP Cipher/AEAD, CBS/CBB ASN.1 DER, CRYPTO_memcmp, and RAND_bytes
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_EVP_X509_H_
#define NEXTAI_OPENCUT_TTCRYPTO_EVP_X509_H_

#include "ttcrypto_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- Constant-Time Memory Comparison & CSPRNG (0x0749cc & 0x0ad674) ---
int CRYPTO_memcmp(const void* in_a, const void* in_b, size_t len);
int RAND_bytes(uint8_t* buf, size_t len);

// --- EVP Cipher Descriptors & Stateful Encryption (0x0aec80..0x0af300) ---
const EVP_CIPHER* EVP_aes_128_cbc(void);
const EVP_CIPHER* EVP_aes_256_cbc(void);
const EVP_CIPHER* EVP_aes_128_ctr(void);
const EVP_CIPHER* EVP_aes_256_ctr(void);
const EVP_CIPHER* EVP_aes_128_gcm(void);
const EVP_CIPHER* EVP_aes_256_gcm(void);

void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX* ctx);
int EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX* ctx);
int EVP_CipherInit_ex(EVP_CIPHER_CTX* ctx, const EVP_CIPHER* cipher,
                      void* impl, const uint8_t* key, const uint8_t* iv, int enc);
int EVP_EncryptInit_ex(EVP_CIPHER_CTX* ctx, const EVP_CIPHER* cipher,
                       void* impl, const uint8_t* key, const uint8_t* iv);
int EVP_DecryptInit_ex(EVP_CIPHER_CTX* ctx, const EVP_CIPHER* cipher,
                       void* impl, const uint8_t* key, const uint8_t* iv);
int EVP_CipherUpdate(EVP_CIPHER_CTX* ctx, uint8_t* out, int* out_len,
                     const uint8_t* in, int in_len);
int EVP_CipherFinal_ex(EVP_CIPHER_CTX* ctx, uint8_t* out, int* out_len);

// --- EVP AEAD High-Speed Interface (0x0ae3c8..0x0ae900) ---
const EVP_AEAD* EVP_aead_aes_128_gcm(void);
const EVP_AEAD* EVP_aead_aes_256_gcm(void);
const EVP_AEAD* EVP_aead_chacha20_poly1305(void);

int EVP_AEAD_CTX_init(EVP_AEAD_CTX* ctx, const EVP_AEAD* aead,
                      const uint8_t* key, size_t key_len, size_t tag_len, void* engine);
void EVP_AEAD_CTX_cleanup(EVP_AEAD_CTX* ctx);
int EVP_AEAD_CTX_seal(const EVP_AEAD_CTX* ctx, uint8_t* out, size_t* out_len, size_t max_out_len,
                      const uint8_t* nonce, size_t nonce_len,
                      const uint8_t* in, size_t in_len,
                      const uint8_t* ad, size_t ad_len);
int EVP_AEAD_CTX_open(const EVP_AEAD_CTX* ctx, uint8_t* out, size_t* out_len, size_t max_out_len,
                      const uint8_t* nonce, size_t nonce_len,
                      const uint8_t* in, size_t in_len,
                      const uint8_t* ad, size_t ad_len);

// --- CBS & CBB ASN.1 DER Parser / Serializer ---
void CBS_init(CBS* cbs, const uint8_t* data, size_t len);
size_t CBS_len(const CBS* cbs);
const uint8_t* CBS_data(const CBS* cbs);
int CBS_get_u8(CBS* cbs, uint8_t* out);
int CBS_get_u16(CBS* cbs, uint16_t* out);
int CBS_get_u32(CBS* cbs, uint32_t* out);
int CBS_get_bytes(CBS* cbs, CBS* out, size_t len);
int CBS_get_asn1(CBS* cbs, CBS* out, unsigned int tag_value);
int CBS_peek_asn1_tag(const CBS* cbs, unsigned int tag_value);

int CBB_init(CBB* cbb, size_t initial_capacity);
void CBB_cleanup(CBB* cbb);
int CBB_add_u8(CBB* cbb, uint8_t value);
int CBB_add_bytes(CBB* cbb, const uint8_t* data, size_t len);
int CBB_add_asn1_element(CBB* cbb, unsigned int tag, const uint8_t* payload, size_t payload_len);
int CBB_finish(CBB* cbb, uint8_t** out_data, size_t* out_len);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_EVP_X509_H_
