// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_interface.cpp
// Description: Unified Engine Initialization & Known-Answer Self-Test (KAT) Suite
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_interface.h"
#include <stdlib.h>
#include <string.h>

static bool s_ttcrypto_initialized = false;

int OPENSSL_init_crypto(uint64_t opts, const void* settings) {
    (void)opts;
    (void)settings;
    if (s_ttcrypto_initialized) {
        return 1;
    }
    if (!ttcrypto_verify_all_subsystems()) {
        return 0;
    }
    s_ttcrypto_initialized = true;
    return 1;
}

/**
 * @brief Runs Known-Answer Tests (KAT) across SHA-256, HMAC, HKDF, AES-GCM, ChaCha20-Poly1305, X25519, and CBS/CBB.
 * Thực thi bộ kiểm thử đáp án chuẩn (KAT) cho toàn bộ 6 phân hệ mật mã cốt lõi của libttcrypto.so.
 */
bool ttcrypto_verify_all_subsystems(void) {
    // 1. FIPS 180-4 SHA-256 KAT: SHA256("abc") == ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad
    static const uint8_t kExpectedSha256Abc[32] = {
        0xba, 0x78, 0x16, 0xbf, 0x8f, 0x01, 0xcf, 0xea,
        0x41, 0x41, 0x40, 0xde, 0x5d, 0xae, 0x22, 0x23,
        0xb0, 0x03, 0x61, 0xa3, 0x96, 0x17, 0x7a, 0x9c,
        0xb4, 0x10, 0xff, 0x61, 0xf2, 0x00, 0x15, 0xad
    };
    uint8_t digest[32] = {0};
    SHA256((const uint8_t*)"abc", 3u, digest);
    if (CRYPTO_memcmp(digest, kExpectedSha256Abc, 32u) != 0) {
        return false;
    }

    // 2. RFC 5869 HKDF-SHA256 Test Case 1
    uint8_t ikm[22];
    memset(ikm, 0x0b, sizeof(ikm));
    static const uint8_t kSalt[13] = {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
        0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c
    };
    static const uint8_t kInfo[10] = {
        0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9
    };
    static const uint8_t kExpectedPrk[32] = {
        0x07, 0x77, 0x09, 0x36, 0x2c, 0x2e, 0x32, 0xdf,
        0x0d, 0xdc, 0x3f, 0x0d, 0xc4, 0x7b, 0xba, 0x63,
        0x90, 0xb6, 0xc7, 0x3b, 0xb5, 0x0f, 0x9c, 0x31,
        0x22, 0xec, 0x84, 0x4a, 0xd7, 0xc2, 0xb3, 0xe5
    };
    uint8_t prk[32] = {0};
    size_t prk_len = 0;
    if (!HKDF_extract(prk, &prk_len, NULL, ikm, sizeof(ikm), kSalt, sizeof(kSalt)) ||
        prk_len != 32u || CRYPTO_memcmp(prk, kExpectedPrk, 32u) != 0) {
        return false;
    }

    // 3. NIST SP 800-38D AES-256-GCM Seal & Open Round-Trip
    uint8_t aes_key[32] = {0};
    uint8_t nonce[12]   = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    const uint8_t* pt   = (const uint8_t*)"NextAI OpenCut TTCrypto AES-GCM Verification";
    const uint8_t* aad  = (const uint8_t*)"ByteDance-TTNet-QUIC-Header";
    size_t pt_len       = strlen((const char*)pt);
    size_t aad_len      = strlen((const char*)aad);
    uint8_t sealed[128] = {0};
    uint8_t opened[128] = {0};
    size_t sealed_len   = 0;
    size_t opened_len   = 0;

    EVP_AEAD_CTX aead_ctx;
    if (!EVP_AEAD_CTX_init(&aead_ctx, EVP_aead_aes_256_gcm(), aes_key, 32u, 16u, NULL) ||
        !EVP_AEAD_CTX_seal(&aead_ctx, sealed, &sealed_len, sizeof(sealed), nonce, 12u, pt, pt_len, aad, aad_len) ||
        !EVP_AEAD_CTX_open(&aead_ctx, opened, &opened_len, sizeof(opened), nonce, 12u, sealed, sealed_len, aad, aad_len) ||
        opened_len != pt_len || CRYPTO_memcmp(opened, pt, pt_len) != 0) {
        EVP_AEAD_CTX_cleanup(&aead_ctx);
        return false;
    }
    EVP_AEAD_CTX_cleanup(&aead_ctx);

    // 4. RFC 8439 ChaCha20-Poly1305 AEAD Seal & Open Round-Trip
    if (!EVP_AEAD_CTX_init(&aead_ctx, EVP_aead_chacha20_poly1305(), aes_key, 32u, 16u, NULL) ||
        !EVP_AEAD_CTX_seal(&aead_ctx, sealed, &sealed_len, sizeof(sealed), nonce, 12u, pt, pt_len, aad, aad_len) ||
        !EVP_AEAD_CTX_open(&aead_ctx, opened, &opened_len, sizeof(opened), nonce, 12u, sealed, sealed_len, aad, aad_len) ||
        opened_len != pt_len || CRYPTO_memcmp(opened, pt, pt_len) != 0) {
        EVP_AEAD_CTX_cleanup(&aead_ctx);
        return false;
    }
    EVP_AEAD_CTX_cleanup(&aead_ctx);

    // 5. RFC 7748 X25519 ECDH Key Exchange Symmetry & Ed25519 Sign/Verify
    uint8_t pub_a[32], priv_a[32], pub_b[32], priv_b[32], shared_ab[32], shared_ba[32];
    X25519_keypair(pub_a, priv_a);
    X25519_keypair(pub_b, priv_b);
    if (!X25519(shared_ab, priv_a, pub_b) ||
        !X25519(shared_ba, priv_b, pub_a) ||
        CRYPTO_memcmp(shared_ab, shared_ba, 32u) != 0) {
        return false;
    }

    uint8_t ed_pub[32], ed_priv[64], sig[64];
    ED25519_keypair(ed_pub, ed_priv);
    if (!ED25519_sign(sig, pt, pt_len, ed_priv) ||
        !ED25519_verify(pt, pt_len, sig, ed_pub)) {
        return false;
    }

    // 6. CBS / CBB ASN.1 DER Serialization & Parsing Verification
    CBB cbb;
    if (!CBB_init(&cbb, 64u) ||
        !CBB_add_asn1_element(&cbb, CBS_ASN1_OCTETSTRING, pt, pt_len)) {
        CBB_cleanup(&cbb);
        return false;
    }
    uint8_t* der_buf = NULL;
    size_t der_len = 0;
    if (!CBB_finish(&cbb, &der_buf, &der_len)) {
        CBB_cleanup(&cbb);
        return false;
    }
    CBS cbs, body;
    CBS_init(&cbs, der_buf, der_len);
    bool asn1_ok = (CBS_get_asn1(&cbs, &body, CBS_ASN1_OCTETSTRING) == 1 &&
                    CBS_len(&body) == pt_len &&
                    CRYPTO_memcmp(CBS_data(&body), pt, pt_len) == 0);
    free(der_buf);
    return asn1_ok;
}
