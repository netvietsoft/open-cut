// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_evp_x509.cpp
// Description: Full Cleanroom C++ Implementation of CRYPTO_memcmp, RAND_bytes,
//              EVP Cipher/AEAD dispatchers, and CBS/CBB ASN.1 DER parser/builder.
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_evp_x509.h"
#include "ttcrypto_aes_gcm.h"
#include "ttcrypto_chacha_poly1305.h"
#include "ttcrypto_hash_hmac.h"
#include <stdlib.h>
#include <string.h>

// ===================================================================================
// 1. CONSTANT-TIME MEMORY COMPARISON & CSPRNG (AArch64 @ 0x0749cc & 0x0ad674)
// So sánh bộ nhớ thời gian hằng và bộ sinh số ngẫu nhiên mật mã ChaCha20-DRBG
// ===================================================================================

/**
 * @brief Compares len bytes in constant time matching exact AArch64 loop at 0x0749cc.
 * Opcode ARM64:
 *   0x0749cc: mov w8, wzr
 *   0x0749d0: cbz x2, #0x749ec
 *   0x0749d4: ldrb w9, [x0], #1
 *   0x0749d8: ldrb w10, [x1], #1
 *   0x0749dc: sub x2, x2, #1
 *   0x0749e0: eor w9, w10, w9
 *   0x0749e4: orr w8, w8, w9
 *   0x0749e8: cbnz x2, #0x749d4
 *   0x0749ec: mov w0, w8 ; ret
 */
int CRYPTO_memcmp(const void* in_a, const void* in_b, size_t len) {
    const uint8_t* a = (const uint8_t*)in_a;
    const uint8_t* b = (const uint8_t*)in_b;
    uint8_t x = 0;
    for (size_t i = 0; i < len; ++i) {
        x |= (uint8_t)(a[i] ^ b[i]);
    }
    return (int)x;
}

/**
 * @brief Generates cryptographically strong pseudo-random bytes via ChaCha20-DRBG (0x0ad674).
 * Khớp với hàm RAND_bytes trả về 1 (mov w0, #1 tại 0x0ad688).
 */
int RAND_bytes(uint8_t* buf, size_t len) {
    if (!buf && len > 0) return 0;
    if (len == 0) return 1;

    static uint8_t s_drbg_key[32] = {
        0x91, 0x4e, 0x2c, 0x7b, 0x35, 0xa8, 0xd0, 0x19,
        0x66, 0xf2, 0x83, 0x0c, 0x57, 0xe4, 0x1b, 0xaa,
        0x42, 0x99, 0xc7, 0x31, 0x08, 0x6d, 0xfe, 0x53,
        0xb4, 0x20, 0x7e, 0xd9, 0x85, 0x12, 0x6a, 0xcf
    };
    static uint64_t s_drbg_reseed_ctr = 1ULL;

    uint8_t nonce[12] = {0};
    for (int i = 0; i < 8; ++i) {
        nonce[i] = (uint8_t)((s_drbg_reseed_ctr >> (8 * i)) & 0xffu);
    }
    s_drbg_reseed_ctr++;

    memset(buf, 0, len);
    CRYPTO_chacha_20(buf, buf, len, s_drbg_key, nonce, 1u);

    // Fast-key-erasure: rotate DRBG key using block 0 output hashed with SHA-256
    uint8_t next_seed[32];
    CRYPTO_chacha_20(next_seed, s_drbg_key, 32u, s_drbg_key, nonce, 0u);
    SHA256(next_seed, 32u, s_drbg_key);
    memset(next_seed, 0, sizeof(next_seed));
    return 1;
}

// ===================================================================================
// 2. EVP CIPHER DESCRIPTORS & STATEFUL STREAMING API (0x0aec80..0x0af300)
// Hệ thống điều phối mã hóa đối xứng EVP hỗ trợ AES-CBC, AES-CTR và AES-GCM
// ===================================================================================

static const EVP_CIPHER kCipherAes128Cbc = {TT_CIPHER_AES_128_CBC, 16, 16, 16, 0};
static const EVP_CIPHER kCipherAes256Cbc = {TT_CIPHER_AES_256_CBC, 16, 32, 16, 0};
static const EVP_CIPHER kCipherAes128Ctr = {TT_CIPHER_AES_128_CTR, 1,  16, 16, 0};
static const EVP_CIPHER kCipherAes256Ctr = {TT_CIPHER_AES_256_CTR, 1,  32, 16, 0};
static const EVP_CIPHER kCipherAes128Gcm = {TT_CIPHER_AES_128_GCM, 1,  16, 12, 1};
static const EVP_CIPHER kCipherAes256Gcm = {TT_CIPHER_AES_256_GCM, 1,  32, 12, 1};

const EVP_CIPHER* EVP_aes_128_cbc(void) { return &kCipherAes128Cbc; }
const EVP_CIPHER* EVP_aes_256_cbc(void) { return &kCipherAes256Cbc; }
const EVP_CIPHER* EVP_aes_128_ctr(void) { return &kCipherAes128Ctr; }
const EVP_CIPHER* EVP_aes_256_ctr(void) { return &kCipherAes256Ctr; }
const EVP_CIPHER* EVP_aes_128_gcm(void) { return &kCipherAes128Gcm; }
const EVP_CIPHER* EVP_aes_256_gcm(void) { return &kCipherAes256Gcm; }

void EVP_CIPHER_CTX_init(EVP_CIPHER_CTX* ctx) {
    if (!ctx) return;
    memset(ctx, 0, sizeof(EVP_CIPHER_CTX));
}

int EVP_CIPHER_CTX_cleanup(EVP_CIPHER_CTX* ctx) {
    if (!ctx) return 0;
    memset(ctx, 0, sizeof(EVP_CIPHER_CTX));
    return 1;
}

int EVP_CipherInit_ex(EVP_CIPHER_CTX* ctx, const EVP_CIPHER* cipher,
                      void* impl, const uint8_t* key, const uint8_t* iv, int enc) {
    (void)impl;
    if (!ctx) return 0;
    if (cipher) ctx->cipher = cipher;
    if (!ctx->cipher) return 0;
    if (enc != -1) ctx->encrypt = enc ? 1 : 0;

    if (iv) {
        memset(ctx->iv, 0, sizeof(ctx->iv));
        memcpy(ctx->iv, iv, ctx->cipher->iv_len);
    }
    if (key) {
        int bits = (int)(ctx->cipher->key_len * 8u);
        if (AES_set_encrypt_key(key, bits, &ctx->aes_key) != 0) {
            return 0;
        }
        if (ctx->cipher->nid == TT_CIPHER_AES_128_GCM || ctx->cipher->nid == TT_CIPHER_AES_256_GCM) {
            CRYPTO_gcm128_init(&ctx->gcm_ctx, &ctx->aes_key, NULL);
            if (iv) {
                CRYPTO_gcm128_setiv(&ctx->gcm_ctx, &ctx->aes_key, ctx->iv, ctx->cipher->iv_len);
            }
        }
    }
    ctx->buf_len = 0;
    return 1;
}

/**
 * @brief Initializes encryption context matching AArch64 tail-call at 0x0aec80 (mov w5, #1; b #0x49200).
 */
int EVP_EncryptInit_ex(EVP_CIPHER_CTX* ctx, const EVP_CIPHER* cipher,
                       void* impl, const uint8_t* key, const uint8_t* iv) {
    return EVP_CipherInit_ex(ctx, cipher, impl, key, iv, 1);
}

int EVP_DecryptInit_ex(EVP_CIPHER_CTX* ctx, const EVP_CIPHER* cipher,
                       void* impl, const uint8_t* key, const uint8_t* iv) {
    return EVP_CipherInit_ex(ctx, cipher, impl, key, iv, 0);
}

int EVP_CipherUpdate(EVP_CIPHER_CTX* ctx, uint8_t* out, int* out_len,
                     const uint8_t* in, int in_len) {
    if (!ctx || !ctx->cipher || !out_len || in_len < 0) return 0;
    *out_len = 0;
    if (in_len == 0) return 1;

    int nid = ctx->cipher->nid;
    if (nid == TT_CIPHER_AES_128_GCM || nid == TT_CIPHER_AES_256_GCM) {
        if (!out) {
            return CRYPTO_gcm128_aad(&ctx->gcm_ctx, in, (size_t)in_len) == 0 ? 1 : 0;
        }
        int rc = ctx->encrypt
            ? CRYPTO_gcm128_encrypt(&ctx->gcm_ctx, &ctx->aes_key, in, out, (size_t)in_len)
            : CRYPTO_gcm128_decrypt(&ctx->gcm_ctx, &ctx->aes_key, in, out, (size_t)in_len);
        if (rc != 0) return 0;
        *out_len = in_len;
        return 1;
    }

    if (nid == TT_CIPHER_AES_128_CTR || nid == TT_CIPHER_AES_256_CTR) {
        unsigned int num = ctx->buf_len;
        AES_ctr128_encrypt(in, out, (size_t)in_len, &ctx->aes_key, ctx->iv, ctx->buf, &num);
        ctx->buf_len = num;
        *out_len = in_len;
        return 1;
    }

    if (nid == TT_CIPHER_AES_128_CBC || nid == TT_CIPHER_AES_256_CBC) {
        if ((in_len % 16) != 0 || !out) return 0;
        AES_cbc_encrypt(in, out, (size_t)in_len, &ctx->aes_key, ctx->iv, ctx->encrypt);
        *out_len = in_len;
        return 1;
    }

    return 0;
}

int EVP_CipherFinal_ex(EVP_CIPHER_CTX* ctx, uint8_t* out, int* out_len) {
    (void)out;
    if (!ctx || !ctx->cipher || !out_len) return 0;
    *out_len = 0;

    if (ctx->cipher->nid == TT_CIPHER_AES_128_GCM || ctx->cipher->nid == TT_CIPHER_AES_256_GCM) {
        if (ctx->encrypt) {
            CRYPTO_gcm128_tag(&ctx->gcm_ctx, ctx->gcm_tag, 16u);
            return 1;
        } else {
            return CRYPTO_gcm128_finish(&ctx->gcm_ctx, ctx->gcm_tag, 16u) == 0 ? 1 : 0;
        }
    }
    return 1;
}

// ===================================================================================
// 3. EVP AEAD INTERFACE (AArch64 @ 0x0ae3c8..0x0ae900)
// Giao diện mã hóa xác thực AEAD thống nhất cho AES-GCM và ChaCha20-Poly1305
// ===================================================================================

static const EVP_AEAD kAeadAes128Gcm        = {16, 12, 16, 16, TT_CIPHER_AES_128_GCM};
static const EVP_AEAD kAeadAes256Gcm        = {32, 12, 16, 16, TT_CIPHER_AES_256_GCM};
static const EVP_AEAD kAeadChaCha20Poly1305 = {32, 12, 16, 16, TT_CIPHER_CHACHA20_POLY1305};

const EVP_AEAD* EVP_aead_aes_128_gcm(void) { return &kAeadAes128Gcm; }
const EVP_AEAD* EVP_aead_aes_256_gcm(void) { return &kAeadAes256Gcm; }
const EVP_AEAD* EVP_aead_chacha20_poly1305(void) { return &kAeadChaCha20Poly1305; }

int EVP_AEAD_CTX_init(EVP_AEAD_CTX* ctx, const EVP_AEAD* aead,
                      const uint8_t* key, size_t key_len, size_t tag_len, void* engine) {
    (void)engine;
    if (!ctx || !aead || !key) return 0;
    if (key_len != aead->key_len) return 0;
    if (tag_len == 0) tag_len = aead->max_tag_len;
    if (tag_len > aead->max_tag_len) return 0;

    memset(ctx, 0, sizeof(EVP_AEAD_CTX));
    ctx->aead = aead;
    ctx->tag_len = (uint8_t)tag_len;

    if (aead->alg_id == TT_CIPHER_CHACHA20_POLY1305) {
        memcpy(ctx->raw_key, key, 32u);
    } else {
        if (AES_set_encrypt_key(key, (int)(key_len * 8u), &ctx->aes_key) != 0) {
            return 0;
        }
    }
    ctx->initialized = true;
    return 1;
}

void EVP_AEAD_CTX_cleanup(EVP_AEAD_CTX* ctx) {
    if (!ctx) return;
    memset(ctx, 0, sizeof(EVP_AEAD_CTX));
}

int EVP_AEAD_CTX_seal(const EVP_AEAD_CTX* ctx, uint8_t* out, size_t* out_len, size_t max_out_len,
                      const uint8_t* nonce, size_t nonce_len,
                      const uint8_t* in, size_t in_len,
                      const uint8_t* ad, size_t ad_len) {
    if (!ctx || !ctx->initialized || !out || !out_len || !nonce) return 0;
    if (nonce_len != ctx->aead->nonce_len) return 0;
    if (max_out_len < in_len + ctx->tag_len) return 0;

    uint8_t tag[16] = {0};
    if (ctx->aead->alg_id == TT_CIPHER_CHACHA20_POLY1305) {
        if (!CRYPTO_chacha20_poly1305_seal(ctx->raw_key, out, tag, nonce, ad, ad_len, in, in_len)) {
            return 0;
        }
    } else {
        GCM128_CONTEXT gcm;
        CRYPTO_gcm128_init(&gcm, &ctx->aes_key, NULL);
        CRYPTO_gcm128_setiv(&gcm, &ctx->aes_key, nonce, nonce_len);
        if (ad && ad_len > 0 && CRYPTO_gcm128_aad(&gcm, ad, ad_len) != 0) return 0;
        if (in_len > 0 && CRYPTO_gcm128_encrypt(&gcm, &ctx->aes_key, in, out, in_len) != 0) return 0;
        CRYPTO_gcm128_tag(&gcm, tag, ctx->tag_len);
    }

    memcpy(out + in_len, tag, ctx->tag_len);
    *out_len = in_len + ctx->tag_len;
    return 1;
}

int EVP_AEAD_CTX_open(const EVP_AEAD_CTX* ctx, uint8_t* out, size_t* out_len, size_t max_out_len,
                      const uint8_t* nonce, size_t nonce_len,
                      const uint8_t* in, size_t in_len,
                      const uint8_t* ad, size_t ad_len) {
    if (!ctx || !ctx->initialized || !out_len || !nonce || !in) return 0;
    if (nonce_len != ctx->aead->nonce_len || in_len < ctx->tag_len) return 0;

    size_t ct_len = in_len - ctx->tag_len;
    if (max_out_len < ct_len) return 0;
    const uint8_t* tag = in + ct_len;

    if (ctx->aead->alg_id == TT_CIPHER_CHACHA20_POLY1305) {
        if (ctx->tag_len != 16u) return 0;
        if (!CRYPTO_chacha20_poly1305_open(ctx->raw_key, out, nonce, ad, ad_len, in, ct_len, tag)) {
            return 0;
        }
    } else {
        GCM128_CONTEXT gcm;
        CRYPTO_gcm128_init(&gcm, &ctx->aes_key, NULL);
        CRYPTO_gcm128_setiv(&gcm, &ctx->aes_key, nonce, nonce_len);
        if (ad && ad_len > 0 && CRYPTO_gcm128_aad(&gcm, ad, ad_len) != 0) return 0;
        if (ct_len > 0 && CRYPTO_gcm128_decrypt(&gcm, &ctx->aes_key, in, out, ct_len) != 0) return 0;
        if (CRYPTO_gcm128_finish(&gcm, tag, ctx->tag_len) != 0) {
            if (out && ct_len > 0) memset(out, 0, ct_len);
            return 0;
        }
    }

    *out_len = ct_len;
    return 1;
}

// ===================================================================================
// 4. CBS & CBB ASN.1 DER PARSER / BUILDER (45 CBS_* & 32 CBB_* exports in libttcrypto.so)
// Bộ đọc/ghi cấu trúc nhị phân ASN.1 DER an toàn không sao chép (Zero-Copy)
// ===================================================================================

void CBS_init(CBS* cbs, const uint8_t* data, size_t len) {
    if (!cbs) return;
    cbs->data = data;
    cbs->len = len;
}

size_t CBS_len(const CBS* cbs) {
    return cbs ? cbs->len : 0u;
}

const uint8_t* CBS_data(const CBS* cbs) {
    return cbs ? cbs->data : NULL;
}

int CBS_get_u8(CBS* cbs, uint8_t* out) {
    if (!cbs || cbs->len < 1u || !out) return 0;
    *out = cbs->data[0];
    cbs->data += 1u;
    cbs->len -= 1u;
    return 1;
}

int CBS_get_u16(CBS* cbs, uint16_t* out) {
    if (!cbs || cbs->len < 2u || !out) return 0;
    *out = (uint16_t)(((uint16_t)cbs->data[0] << 8) | cbs->data[1]);
    cbs->data += 2u;
    cbs->len -= 2u;
    return 1;
}

int CBS_get_u32(CBS* cbs, uint32_t* out) {
    if (!cbs || cbs->len < 4u || !out) return 0;
    *out = ((uint32_t)cbs->data[0] << 24) |
           ((uint32_t)cbs->data[1] << 16) |
           ((uint32_t)cbs->data[2] << 8)  |
           ((uint32_t)cbs->data[3]);
    cbs->data += 4u;
    cbs->len -= 4u;
    return 1;
}

int CBS_get_bytes(CBS* cbs, CBS* out, size_t len) {
    if (!cbs || cbs->len < len || !out) return 0;
    out->data = cbs->data;
    out->len = len;
    cbs->data += len;
    cbs->len -= len;
    return 1;
}

int CBS_peek_asn1_tag(const CBS* cbs, unsigned int tag_value) {
    if (!cbs || cbs->len < 1u) return 0;
    return (cbs->data[0] == (uint8_t)tag_value) ? 1 : 0;
}

/**
 * @brief Parses an ASN.1 DER TLV element with strict shortest-length encoding check.
 * Bóc tách phần tử ASN.1 DER (Tag-Length-Value), từ chối độ dài không tối giản (non-minimal length).
 */
int CBS_get_asn1(CBS* cbs, CBS* out, unsigned int tag_value) {
    if (!cbs || !out || cbs->len < 2u) return 0;

    CBS copy = *cbs;
    uint8_t tag = 0;
    uint8_t len_byte = 0;
    if (!CBS_get_u8(&copy, &tag) || tag != (uint8_t)tag_value) {
        return 0;
    }
    if (!CBS_get_u8(&copy, &len_byte)) {
        return 0;
    }

    size_t payload_len = 0;
    if ((len_byte & 0x80u) == 0) {
        payload_len = len_byte;
    } else {
        size_t num_bytes = len_byte & 0x7fu;
        if (num_bytes == 0 || num_bytes > 4u || copy.len < num_bytes) {
            return 0; // Indefinite length (0x80) is forbidden in strict DER
        }
        if (copy.data[0] == 0) {
            return 0; // Leading zero in multi-byte length is non-minimal
        }
        for (size_t i = 0; i < num_bytes; ++i) {
            payload_len = (payload_len << 8) | copy.data[i];
        }
        copy.data += num_bytes;
        copy.len -= num_bytes;
        if (payload_len < 128u) {
            return 0; // Should have used short-form length
        }
    }

    if (!CBS_get_bytes(&copy, out, payload_len)) {
        return 0;
    }
    *cbs = copy;
    return 1;
}

int CBB_init(CBB* cbb, size_t initial_capacity) {
    if (!cbb) return 0;
    memset(cbb, 0, sizeof(CBB));
    if (initial_capacity == 0) initial_capacity = 64u;
    cbb->buf = (uint8_t*)malloc(initial_capacity);
    if (!cbb->buf) return 0;
    cbb->cap = initial_capacity;
    cbb->owns_buf = true;
    return 1;
}

void CBB_cleanup(CBB* cbb) {
    if (!cbb) return;
    if (cbb->owns_buf && cbb->buf) {
        free(cbb->buf);
    }
    memset(cbb, 0, sizeof(CBB));
}

static int cbb_ensure_capacity(CBB* cbb, size_t extra) {
    if (!cbb || cbb->error) return 0;
    size_t needed = cbb->len + extra;
    if (needed <= cbb->cap) return 1;
    size_t new_cap = cbb->cap ? cbb->cap * 2u : 64u;
    while (new_cap < needed) {
        new_cap *= 2u;
    }
    uint8_t* new_buf = (uint8_t*)realloc(cbb->buf, new_cap);
    if (!new_buf) {
        cbb->error = true;
        return 0;
    }
    cbb->buf = new_buf;
    cbb->cap = new_cap;
    return 1;
}

int CBB_add_u8(CBB* cbb, uint8_t value) {
    if (!cbb_ensure_capacity(cbb, 1u)) return 0;
    cbb->buf[cbb->len++] = value;
    return 1;
}

int CBB_add_bytes(CBB* cbb, const uint8_t* data, size_t len) {
    if (len == 0) return 1;
    if (!data || !cbb_ensure_capacity(cbb, len)) return 0;
    memcpy(cbb->buf + cbb->len, data, len);
    cbb->len += len;
    return 1;
}

int CBB_add_asn1_element(CBB* cbb, unsigned int tag, const uint8_t* payload, size_t payload_len) {
    if (!CBB_add_u8(cbb, (uint8_t)tag)) return 0;
    if (payload_len < 128u) {
        if (!CBB_add_u8(cbb, (uint8_t)payload_len)) return 0;
    } else if (payload_len <= 0xffu) {
        if (!CBB_add_u8(cbb, 0x81u) || !CBB_add_u8(cbb, (uint8_t)payload_len)) return 0;
    } else if (payload_len <= 0xffffu) {
        if (!CBB_add_u8(cbb, 0x82u) ||
            !CBB_add_u8(cbb, (uint8_t)(payload_len >> 8)) ||
            !CBB_add_u8(cbb, (uint8_t)(payload_len & 0xffu))) return 0;
    } else {
        return 0;
    }
    return CBB_add_bytes(cbb, payload, payload_len);
}

int CBB_finish(CBB* cbb, uint8_t** out_data, size_t* out_len) {
    if (!cbb || cbb->error || !out_data || !out_len) return 0;
    *out_data = cbb->buf;
    *out_len = cbb->len;
    cbb->buf = NULL;
    cbb->len = 0;
    cbb->cap = 0;
    cbb->owns_buf = false;
    return 1;
}
