// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_chacha_poly1305.h
// Description: Declarations for ChaCha20, HChaCha20, Poly1305, and AEAD-ChaCha20-Poly1305
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_CHACHA_POLY1305_H_
#define NEXTAI_OPENCUT_TTCRYPTO_CHACHA_POLY1305_H_

#include "ttcrypto_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- ChaCha20 & HChaCha20 Stream Cipher (0x058d88..0x059100) ---
void CRYPTO_chacha_20(uint8_t* out, const uint8_t* in, size_t in_len,
                      const uint8_t key[32], const uint8_t nonce[12], uint32_t counter);
void CRYPTO_hchacha20(uint8_t out[32], const uint8_t key[32], const uint8_t nonce[16]);

// --- Poly1305 One-Time Authenticator over GF(2^130 - 5) ---
void CRYPTO_poly1305_init(poly1305_state* state, const uint8_t key[32]);
void CRYPTO_poly1305_update(poly1305_state* state, const uint8_t* in, size_t in_len);
void CRYPTO_poly1305_finish(poly1305_state* state, uint8_t mac[16]);

// --- Combined RFC 8439 AEAD ChaCha20-Poly1305 Seal & Open ---
int CRYPTO_chacha20_poly1305_seal(const uint8_t key[32],
                                  uint8_t* out_ciphertext,
                                  uint8_t out_tag[16],
                                  const uint8_t nonce[12],
                                  const uint8_t* ad, size_t ad_len,
                                  const uint8_t* plaintext, size_t plaintext_len);

int CRYPTO_chacha20_poly1305_open(const uint8_t key[32],
                                  uint8_t* out_plaintext,
                                  const uint8_t nonce[12],
                                  const uint8_t* ad, size_t ad_len,
                                  const uint8_t* ciphertext, size_t ciphertext_len,
                                  const uint8_t expected_tag[16]);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_CHACHA_POLY1305_H_
