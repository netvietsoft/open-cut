// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_curve25519.h
// Description: Declarations for X25519 ECDH (RFC 7748) and Ed25519 Signatures (RFC 8032)
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_CURVE25519_H_
#define NEXTAI_OPENCUT_TTCRYPTO_CURVE25519_H_

#include "ttcrypto_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// --- Curve25519 / X25519 Diffie-Hellman (0x060410..0x0608ac) ---
int X25519(uint8_t out_shared_key[32], const uint8_t private_key[32], const uint8_t peer_public_value[32]);
void X25519_public_from_private(uint8_t out_public_value[32], const uint8_t private_key[32]);
void X25519_keypair(uint8_t out_public_value[32], uint8_t out_private_key[32]);

// --- Ed25519 Digital Signatures (0x05eec4..0x06040c) ---
void ED25519_keypair(uint8_t out_public_key[32], uint8_t out_private_key[64]);
int ED25519_sign(uint8_t out_sig[64], const uint8_t* message, size_t message_len, const uint8_t private_key[64]);
int ED25519_verify(const uint8_t* message, size_t message_len, const uint8_t signature[64], const uint8_t public_key[32]);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_CURVE25519_H_
