// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_pseudocode.cpp
// Description: Reconstructed AArch64 Entry Points & Disassembly-Matched Core Routines
//              for libttcrypto.so (1,231,952 bytes, 2,353 exported symbols).
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_interface.h"
#include <string.h>

namespace NextAI {
namespace OpenCut {
namespace TTCrypto {

/**
 * @brief Verifies SHA256_CTX AArch64 ABI layout at SHA256_Init (0x0be370).
 * Opcode ARM64:
 *   0x0be37c: mov w2, #0x70       ; sizeof(SHA256_CTX) == 112 bytes
 *   0x0be394: mov w8, #0x20       ; md_len == 32 bytes
 *   0x0be398: str w8, [x19, #0x6c]; offsetof(SHA256_CTX, md_len) == 0x6c (108)
 */
bool VerifySha256AbiLayout() {
    if (sizeof(SHA256_CTX) != 0x70u) {
        return false;
    }
    if (offsetof(SHA256_CTX, md_len) != 0x6cu) {
        return false;
    }
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    return (ctx.h[0] == 0x6a09e667u &&
            ctx.h[7] == 0x5be0cd19u &&
            ctx.md_len == 0x20u);
}

/**
 * @brief Verifies GCM128_CONTEXT AArch64 ABI layout at CRYPTO_gcm128_aad (0x0b8d7c) and CRYPTO_gcm128_encrypt (0x0b8e78).
 * Opcode ARM64:
 *   0x0b8d90: ldr x8, [x0, #0x38] ; offsetof(GCM128_CONTEXT, len.u[1]) == 0x38
 *   0x0b8da0: ldr x8, [x0, #0x30] ; offsetof(GCM128_CONTEXT, len.u[0]) == 0x30
 *   0x0b8e9c: ldr w9, [x19, #0x184] ; offsetof(GCM128_CONTEXT, mres) == 0x184
 *   0x0b8ea0: ldr x23, [x19, #0x160] ; offsetof(GCM128_CONTEXT, key) == 0x160
 */
bool VerifyGcm128AbiLayout() {
    if (offsetof(GCM128_CONTEXT, len) != 0x30u) {
        return false;
    }
    if (offsetof(GCM128_CONTEXT, Xi) != 0x40u) {
        return false;
    }
    if (offsetof(GCM128_CONTEXT, H) != 0x50u) {
        return false;
    }
    if (offsetof(GCM128_CONTEXT, Htable) != 0x60u) {
        return false;
    }
    if (offsetof(GCM128_CONTEXT, key) != 0x160u) {
        return false;
    }
    if (offsetof(GCM128_CONTEXT, ares) != 0x180u) {
        return false;
    }
    if (offsetof(GCM128_CONTEXT, mres) != 0x184u) {
        return false;
    }
    return true;
}

/**
 * @brief Verifies AES_KEY AArch64 ABI layout at AES_set_encrypt_key (0x0a48e0).
 * Kích thước AES_KEY = 244 bytes (0xf4), rounds tại offset +0xf0.
 */
bool VerifyAesKeyAbiLayout() {
    if (sizeof(AES_KEY) != 0xf4u || offsetof(AES_KEY, rounds) != 0xf0u) {
        return false;
    }
    uint8_t raw_key[32] = {0};
    AES_KEY k128, k192, k256;
    if (AES_set_encrypt_key(raw_key, 128, &k128) != 0 || k128.rounds != 10u) return false;
    if (AES_set_encrypt_key(raw_key, 192, &k192) != 0 || k192.rounds != 12u) return false;
    if (AES_set_encrypt_key(raw_key, 256, &k256) != 0 || k256.rounds != 14u) return false;
    return true;
}

/**
 * @brief Runs complete parity checks across ABI layouts and cryptographic KAT vectors.
 */
bool RunAllTTCryptoParityChecks() {
    return VerifySha256AbiLayout() &&
           VerifyGcm128AbiLayout() &&
           VerifyAesKeyAbiLayout() &&
           ttcrypto_verify_all_subsystems();
}

} // namespace TTCrypto
} // namespace OpenCut
} // namespace NextAI
