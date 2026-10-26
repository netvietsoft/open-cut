// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_interface.h
// Description: Unified Public C/C++ API for ByteDance TTCrypto Engine
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_INTERFACE_H_
#define NEXTAI_OPENCUT_TTCRYPTO_INTERFACE_H_

#include "ttcrypto_types.h"
#include "ttcrypto_hash_hmac.h"
#include "ttcrypto_aes_gcm.h"
#include "ttcrypto_chacha_poly1305.h"
#include "ttcrypto_curve25519.h"
#include "ttcrypto_evp_x509.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the ByteDance TTCrypto runtime and runs FIPS/RFC self-tests.
 * Khởi tạo engine mật mã TTCrypto và chạy kiểm tra tự kiểm định KAT (Known-Answer Tests).
 * @return 1 on success, 0 on failure.
 */
int OPENSSL_init_crypto(uint64_t opts, const void* settings);

/**
 * @brief Executes comprehensive KAT self-verification across all 6 TTCrypto subsystems.
 * Chạy kiểm định toàn diện trên 6 phân hệ: SHA-256/512, HMAC/HKDF, AES-GCM, ChaCha20-Poly1305, X25519/Ed25519, CBS/CBB.
 */
bool ttcrypto_verify_all_subsystems(void);

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_INTERFACE_H_
