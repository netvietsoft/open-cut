// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_chacha_poly1305.cpp
// Description: Full Cleanroom C++ Implementation of RFC 8439 ChaCha20, HChaCha20,
//              Poly1305 over Z/(2^130 - 5)Z, and AEAD-ChaCha20-Poly1305.
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_chacha_poly1305.h"
#include <string.h>

static inline uint32_t rotl32(uint32_t x, uint32_t n) {
    return (x << n) | (x >> (32u - n));
}

static inline uint32_t load_le32(const uint8_t* p) {
    return ((uint32_t)p[0])       |
           ((uint32_t)p[1] << 8)  |
           ((uint32_t)p[2] << 16) |
           ((uint32_t)p[3] << 24);
}

static inline void store_le32(uint8_t* p, uint32_t v) {
    p[0] = (uint8_t)(v);
    p[1] = (uint8_t)(v >> 8);
    p[2] = (uint8_t)(v >> 16);
    p[3] = (uint8_t)(v >> 24);
}

static inline void store_le64(uint8_t* p, uint64_t v) {
    for (int i = 0; i < 8; ++i) {
        p[i] = (uint8_t)(v >> (8 * i));
    }
}

#define CHACHA_QUARTERROUND(a, b, c, d) \
    do {                                \
        a += b; d ^= a; d = rotl32(d, 16); \
        c += d; b ^= c; b = rotl32(b, 12); \
        a += b; d ^= a; d = rotl32(d, 8);  \
        c += d; b ^= c; b = rotl32(b, 7);  \
    } while (0)

// Hằng số ma thuật "expand 32-byte k" theo chuẩn RFC 8439
static const uint32_t kSigma[4] = {
    0x61707865u, 0x3320646eu, 0x79622d32u, 0x6b206574u
};

// ===================================================================================
// 1. CHACHA20 & HCHACHA20 STREAM CIPHER (AArch64 @ 0x058d88)
// Bộ mã dòng ChaCha20 20 vòng lặp (10 vòng kép cột + đường chéo)
// ===================================================================================

static void chacha20_core_block(uint8_t out_block[64], const uint32_t input[16]) {
    uint32_t x[16];
    for (int i = 0; i < 16; ++i) {
        x[i] = input[i];
    }

    for (int r = 0; r < 10; ++r) {
        // Column round
        CHACHA_QUARTERROUND(x[0], x[4], x[8],  x[12]);
        CHACHA_QUARTERROUND(x[1], x[5], x[9],  x[13]);
        CHACHA_QUARTERROUND(x[2], x[6], x[10], x[14]);
        CHACHA_QUARTERROUND(x[3], x[7], x[11], x[15]);
        // Diagonal round
        CHACHA_QUARTERROUND(x[0], x[5], x[10], x[15]);
        CHACHA_QUARTERROUND(x[1], x[6], x[11], x[12]);
        CHACHA_QUARTERROUND(x[2], x[7], x[8],  x[13]);
        CHACHA_QUARTERROUND(x[3], x[4], x[9],  x[14]);
    }

    for (int i = 0; i < 16; ++i) {
        store_le32(out_block + 4 * i, x[i] + input[i]);
    }
}

/**
 * @brief Encrypts/decrypts in[0..in_len-1] using ChaCha20 with 96-bit nonce and 32-bit counter (0x058d88).
 * Khởi tạo ma trận 4x4 (16 từ 32-bit) gồm hằng số kSigma, khóa 256-bit, bộ đếm 32-bit và nonce 96-bit.
 */
void CRYPTO_chacha_20(uint8_t* out, const uint8_t* in, size_t in_len,
                      const uint8_t key[32], const uint8_t nonce[12], uint32_t counter) {
    if ((!out && in_len > 0) || (!in && in_len > 0) || !key || !nonce) return;

    uint32_t state[16];
    state[0] = kSigma[0];
    state[1] = kSigma[1];
    state[2] = kSigma[2];
    state[3] = kSigma[3];
    for (int i = 0; i < 8; ++i) {
        state[4 + i] = load_le32(key + 4 * i);
    }
    state[12] = counter;
    state[13] = load_le32(nonce + 0);
    state[14] = load_le32(nonce + 4);
    state[15] = load_le32(nonce + 8);

    uint8_t block[64];
    while (in_len > 0) {
        chacha20_core_block(block, state);
        state[12]++; // Increment 32-bit block counter

        size_t todo = (in_len < 64u) ? in_len : 64u;
        for (size_t i = 0; i < todo; ++i) {
            out[i] = (uint8_t)(in[i] ^ block[i]);
        }
        in += todo;
        out += todo;
        in_len -= todo;
    }
    memset(block, 0, sizeof(block));
}

/**
 * @brief Derives a 256-bit subkey from a 256-bit key and 128-bit nonce for XChaCha20.
 * Dẫn xuất khóa con 32-byte từ hàng đầu (x[0..3]) và hàng cuối (x[12..15]) không cộng state gốc.
 */
void CRYPTO_hchacha20(uint8_t out[32], const uint8_t key[32], const uint8_t nonce[16]) {
    if (!out || !key || !nonce) return;

    uint32_t x[16];
    x[0] = kSigma[0];
    x[1] = kSigma[1];
    x[2] = kSigma[2];
    x[3] = kSigma[3];
    for (int i = 0; i < 8; ++i) {
        x[4 + i] = load_le32(key + 4 * i);
    }
    for (int i = 0; i < 4; ++i) {
        x[12 + i] = load_le32(nonce + 4 * i);
    }

    for (int r = 0; r < 10; ++r) {
        CHACHA_QUARTERROUND(x[0], x[4], x[8],  x[12]);
        CHACHA_QUARTERROUND(x[1], x[5], x[9],  x[13]);
        CHACHA_QUARTERROUND(x[2], x[6], x[10], x[14]);
        CHACHA_QUARTERROUND(x[3], x[7], x[11], x[15]);
        CHACHA_QUARTERROUND(x[0], x[5], x[10], x[15]);
        CHACHA_QUARTERROUND(x[1], x[6], x[11], x[12]);
        CHACHA_QUARTERROUND(x[2], x[7], x[8],  x[13]);
        CHACHA_QUARTERROUND(x[3], x[4], x[9],  x[14]);
    }

    for (int i = 0; i < 4; ++i) {
        store_le32(out + 4 * i, x[i]);
        store_le32(out + 16 + 4 * i, x[12 + i]);
    }
}

// ===================================================================================
// 2. POLY1305 ONE-TIME AUTHENTICATOR OVER GF(2^130 - 5) (RFC 8439 Section 2.5)
// Tính đa thức xác thực một lần bằng biểu diễn 5-limb cơ số 2^26 modulo (2^130 - 5)
// ===================================================================================

static void poly1305_blocks(poly1305_state* st, const uint8_t* m, size_t bytes, uint32_t hibit) {
    uint32_t r0 = st->r[0], r1 = st->r[1], r2 = st->r[2], r3 = st->r[3], r4 = st->r[4];
    uint32_t s1 = r1 * 5u,  s2 = r2 * 5u,  s3 = r3 * 5u,  s4 = r4 * 5u;
    uint32_t h0 = st->h[0], h1 = st->h[1], h2 = st->h[2], h3 = st->h[3], h4 = st->h[4];

    while (bytes >= 16u) {
        // h += m[i] (chia khối 128-bit thành 5 limb 26-bit kèm bit thứ 128 = hibit)
        h0 += (load_le32(m +  0)     ) & 0x3ffffffu;
        h1 += (load_le32(m +  3) >> 2) & 0x3ffffffu;
        h2 += (load_le32(m +  6) >> 4) & 0x3ffffffu;
        h3 += (load_le32(m +  9) >> 6) & 0x3ffffffu;
        h4 += (load_le32(m + 12) >> 8) | (hibit << 24);

        // h *= r (mod 2^130 - 5) sử dụng đồng nhất thức 2^130 === 5 (mod 2^130 - 5)
        uint64_t d0 = (uint64_t)h0 * r0 + (uint64_t)h1 * s4 + (uint64_t)h2 * s3 + (uint64_t)h3 * s2 + (uint64_t)h4 * s1;
        uint64_t d1 = (uint64_t)h0 * r1 + (uint64_t)h1 * r0 + (uint64_t)h2 * s4 + (uint64_t)h3 * s3 + (uint64_t)h4 * s2;
        uint64_t d2 = (uint64_t)h0 * r2 + (uint64_t)h1 * r1 + (uint64_t)h2 * r0 + (uint64_t)h3 * s4 + (uint64_t)h4 * s3;
        uint64_t d3 = (uint64_t)h0 * r3 + (uint64_t)h1 * r2 + (uint64_t)h2 * r1 + (uint64_t)h3 * r0 + (uint64_t)h4 * s4;
        uint64_t d4 = (uint64_t)h0 * r4 + (uint64_t)h1 * r3 + (uint64_t)h2 * r2 + (uint64_t)h3 * r1 + (uint64_t)h4 * r0;

        // Lan truyền số nhớ (carry propagation)
        uint32_t c = (uint32_t)(d0 >> 26); h0 = (uint32_t)d0 & 0x3ffffffu; d1 += c;
                 c = (uint32_t)(d1 >> 26); h1 = (uint32_t)d1 & 0x3ffffffu; d2 += c;
                 c = (uint32_t)(d2 >> 26); h2 = (uint32_t)d2 & 0x3ffffffu; d3 += c;
                 c = (uint32_t)(d3 >> 26); h3 = (uint32_t)d3 & 0x3ffffffu; d4 += c;
                 c = (uint32_t)(d4 >> 26); h4 = (uint32_t)d4 & 0x3ffffffu; h0 += c * 5u;
                 c = h0 >> 26;             h0 &= 0x3ffffffu;               h1 += c;

        m += 16u;
        bytes -= 16u;
    }

    st->h[0] = h0; st->h[1] = h1; st->h[2] = h2; st->h[3] = h3; st->h[4] = h4;
}

/**
 * @brief Initializes Poly1305 state and clamps r with RFC 8439 mask 0x0ffffffc0ffffffc0ffffffc0fffffff.
 */
void CRYPTO_poly1305_init(poly1305_state* state, const uint8_t key[32]) {
    if (!state || !key) return;
    memset(state, 0, sizeof(poly1305_state));

    // Clamp r[0..15] and split into five 26-bit limbs
    state->r[0] = (load_le32(key +  0)     ) & 0x3ffffffu;
    state->r[1] = (load_le32(key +  3) >> 2) & 0x3ffff03u;
    state->r[2] = (load_le32(key +  6) >> 4) & 0x3ffc0ffu;
    state->r[3] = (load_le32(key +  9) >> 6) & 0x3f03fffu;
    state->r[4] = (load_le32(key + 12) >> 8) & 0x00fffffu;

    // Load one-time pad s[0..3] from key[16..31]
    state->pad[0] = load_le32(key + 16);
    state->pad[1] = load_le32(key + 20);
    state->pad[2] = load_le32(key + 24);
    state->pad[3] = load_le32(key + 28);
}

void CRYPTO_poly1305_update(poly1305_state* state, const uint8_t* in, size_t in_len) {
    if (!state || (!in && in_len > 0)) return;

    if (state->buf_used > 0) {
        size_t want = 16u - state->buf_used;
        if (want > in_len) want = in_len;
        memcpy(state->buf + state->buf_used, in, want);
        in += want;
        in_len -= want;
        state->buf_used += want;
        if (state->buf_used < 16u) return;
        poly1305_blocks(state, state->buf, 16u, 1u);
        state->buf_used = 0;
    }

    if (in_len >= 16u) {
        size_t want = in_len & ~(size_t)15u;
        poly1305_blocks(state, in, want, 1u);
        in += want;
        in_len -= want;
    }

    if (in_len > 0) {
        memcpy(state->buf, in, in_len);
        state->buf_used = in_len;
    }
}

void CRYPTO_poly1305_finish(poly1305_state* state, uint8_t mac[16]) {
    if (!state || !mac) return;

    if (state->buf_used > 0) {
        size_t used = state->buf_used;
        state->buf[used++] = 1u;
        while (used < 16u) {
            state->buf[used++] = 0u;
        }
        poly1305_blocks(state, state->buf, 16u, 0u);
    }

    // Complete modular reduction modulo 2^130 - 5
    uint32_t h0 = state->h[0], h1 = state->h[1], h2 = state->h[2], h3 = state->h[3], h4 = state->h[4];
    uint32_t c = h1 >> 26; h1 &= 0x3ffffffu; h2 += c;
             c = h2 >> 26; h2 &= 0x3ffffffu; h3 += c;
             c = h3 >> 26; h3 &= 0x3ffffffu; h4 += c;
             c = h4 >> 26; h4 &= 0x3ffffffu; h0 += c * 5u;
             c = h0 >> 26; h0 &= 0x3ffffffu; h1 += c;

    // Compute g = h + 5 - 2^130
    uint32_t g0 = h0 + 5u; c = g0 >> 26; g0 &= 0x3ffffffu;
    uint32_t g1 = h1 + c;  c = g1 >> 26; g1 &= 0x3ffffffu;
    uint32_t g2 = h2 + c;  c = g2 >> 26; g2 &= 0x3ffffffu;
    uint32_t g3 = h3 + c;  c = g3 >> 26; g3 &= 0x3ffffffu;
    uint32_t g4 = h4 + c - (1u << 26);

    // Select h if g4 < 0 (mask = 0xffffffff), else g (mask = 0)
    uint32_t mask = (g4 >> 31) - 1u;
    g0 &= mask; g1 &= mask; g2 &= mask; g3 &= mask; g4 &= mask;
    mask = ~mask;
    h0 = (h0 & mask) | g0;
    h1 = (h1 & mask) | g1;
    h2 = (h2 & mask) | g2;
    h3 = (h3 & mask) | g3;
    h4 = (h4 & mask) | g4;

    // Reassemble 5 limbs of 26 bits into four 32-bit words and add pad s (mod 2^128)
    uint64_t f0 = ((h0      ) | (h1 << 26)) & 0xffffffffULL;
    uint64_t f1 = ((h1 >>  6) | (h2 << 20)) & 0xffffffffULL;
    uint64_t f2 = ((h2 >> 12) | (h3 << 14)) & 0xffffffffULL;
    uint64_t f3 = ((h3 >> 18) | (h4 <<  8)) & 0xffffffffULL;

    f0 += state->pad[0];
    f1 += state->pad[1] + (f0 >> 32);
    f2 += state->pad[2] + (f1 >> 32);
    f3 += state->pad[3] + (f2 >> 32);

    store_le32(mac +  0, (uint32_t)f0);
    store_le32(mac +  4, (uint32_t)f1);
    store_le32(mac +  8, (uint32_t)f2);
    store_le32(mac + 12, (uint32_t)f3);
    memset(state, 0, sizeof(poly1305_state));
}

// ===================================================================================
// 3. AEAD CHACHA20-POLY1305 SEAL & OPEN (RFC 8439 Section 2.8)
// Mã hóa và xác thực AEAD ChaCha20-Poly1305 dùng trong TLS 1.3 & QUIC của TTNet
// ===================================================================================

static void poly1305_pad16(poly1305_state* st, size_t len) {
    static const uint8_t kZeros[16] = {0};
    size_t rem = len & 15u;
    if (rem != 0) {
        CRYPTO_poly1305_update(st, kZeros, 16u - rem);
    }
}

int CRYPTO_chacha20_poly1305_seal(const uint8_t key[32],
                                  uint8_t* out_ciphertext,
                                  uint8_t out_tag[16],
                                  const uint8_t nonce[12],
                                  const uint8_t* ad, size_t ad_len,
                                  const uint8_t* plaintext, size_t plaintext_len) {
    if (!key || !out_tag || !nonce) return 0;
    if (plaintext_len > 0 && (!plaintext || !out_ciphertext)) return 0;

    // 1. Derive 32-byte one-time Poly1305 key using block counter = 0
    uint8_t poly_key[64] = {0};
    CRYPTO_chacha_20(poly_key, poly_key, 64u, key, nonce, 0u);

    // 2. Encrypt plaintext using ChaCha20 starting at block counter = 1
    if (plaintext_len > 0) {
        CRYPTO_chacha_20(out_ciphertext, plaintext, plaintext_len, key, nonce, 1u);
    }

    // 3. Compute Poly1305 tag over AD || pad16(AD) || CT || pad16(CT) || len64(AD) || len64(CT)
    poly1305_state st;
    CRYPTO_poly1305_init(&st, poly_key);
    if (ad && ad_len > 0) {
        CRYPTO_poly1305_update(&st, ad, ad_len);
        poly1305_pad16(&st, ad_len);
    }
    if (plaintext_len > 0) {
        CRYPTO_poly1305_update(&st, out_ciphertext, plaintext_len);
        poly1305_pad16(&st, plaintext_len);
    }
    uint8_t lengths[16];
    store_le64(lengths + 0, (uint64_t)ad_len);
    store_le64(lengths + 8, (uint64_t)plaintext_len);
    CRYPTO_poly1305_update(&st, lengths, 16u);
    CRYPTO_poly1305_finish(&st, out_tag);

    memset(poly_key, 0, sizeof(poly_key));
    return 1;
}

int CRYPTO_chacha20_poly1305_open(const uint8_t key[32],
                                  uint8_t* out_plaintext,
                                  const uint8_t nonce[12],
                                  const uint8_t* ad, size_t ad_len,
                                  const uint8_t* ciphertext, size_t ciphertext_len,
                                  const uint8_t expected_tag[16]) {
    if (!key || !nonce || !expected_tag) return 0;
    if (ciphertext_len > 0 && (!ciphertext || !out_plaintext)) return 0;

    uint8_t poly_key[64] = {0};
    CRYPTO_chacha_20(poly_key, poly_key, 64u, key, nonce, 0u);

    poly1305_state st;
    CRYPTO_poly1305_init(&st, poly_key);
    if (ad && ad_len > 0) {
        CRYPTO_poly1305_update(&st, ad, ad_len);
        poly1305_pad16(&st, ad_len);
    }
    if (ciphertext_len > 0) {
        CRYPTO_poly1305_update(&st, ciphertext, ciphertext_len);
        poly1305_pad16(&st, ciphertext_len);
    }
    uint8_t lengths[16];
    store_le64(lengths + 0, (uint64_t)ad_len);
    store_le64(lengths + 8, (uint64_t)ciphertext_len);
    CRYPTO_poly1305_update(&st, lengths, 16u);

    uint8_t computed_tag[16];
    CRYPTO_poly1305_finish(&st, computed_tag);
    memset(poly_key, 0, sizeof(poly_key));

    // Constant-time tag verification
    uint8_t diff = 0;
    for (int i = 0; i < 16; ++i) {
        diff |= (uint8_t)(computed_tag[i] ^ expected_tag[i]);
    }
    if (diff != 0) {
        if (out_plaintext && ciphertext_len > 0) {
            memset(out_plaintext, 0, ciphertext_len);
        }
        return 0;
    }

    if (ciphertext_len > 0) {
        CRYPTO_chacha_20(out_plaintext, ciphertext, ciphertext_len, key, nonce, 1u);
    }
    return 1;
}
