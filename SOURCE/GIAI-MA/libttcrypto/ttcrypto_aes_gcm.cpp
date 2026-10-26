// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_aes_gcm.cpp
// Description: Full Cleanroom C++ Implementation of FIPS 197 AES-128/192/256 and
//              NIST SP 800-38D GCM128 over GF(2^128) matching AArch64 opcodes.
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_aes_gcm.h"
#include <string.h>

// ===================================================================================
// 1. AES S-BOX, INVERSE S-BOX & RCON TABLES (FIPS 197)
// Bảng thế phi tuyến Rijndael S-Box trên trường hữu hạn GF(2^8) / (x^8 + x^4 + x^3 + x + 1)
// ===================================================================================

static const uint8_t kAesSbox[256] = {
    0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5, 0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
    0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0, 0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
    0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc, 0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
    0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a, 0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
    0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0, 0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
    0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b, 0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
    0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85, 0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
    0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5, 0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
    0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17, 0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
    0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88, 0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
    0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c, 0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
    0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9, 0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
    0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6, 0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
    0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e, 0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
    0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94, 0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
    0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68, 0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

static const uint8_t kAesInvSbox[256] = {
    0x52, 0x09, 0x6a, 0xd5, 0x30, 0x36, 0xa5, 0x38, 0xbf, 0x40, 0xa3, 0x9e, 0x81, 0xf3, 0xd7, 0xfb,
    0x7c, 0xe3, 0x39, 0x82, 0x9b, 0x2f, 0xff, 0x87, 0x34, 0x8e, 0x43, 0x44, 0xc4, 0xde, 0xe9, 0xcb,
    0x54, 0x7b, 0x94, 0x32, 0xa6, 0xc2, 0x23, 0x3d, 0xee, 0x4c, 0x95, 0x0b, 0x42, 0xfa, 0xc3, 0x4e,
    0x08, 0x2e, 0xa1, 0x66, 0x28, 0xd9, 0x24, 0xb2, 0x76, 0x5b, 0xa2, 0x49, 0x6d, 0x8b, 0xd1, 0x25,
    0x72, 0xf8, 0xf6, 0x64, 0x86, 0x68, 0x98, 0x16, 0xd4, 0xa4, 0x5c, 0xcc, 0x5d, 0x65, 0xb6, 0x92,
    0x6c, 0x70, 0x48, 0x50, 0xfd, 0xed, 0xb9, 0xda, 0x5e, 0x15, 0x46, 0x57, 0xa7, 0x8d, 0x9d, 0x84,
    0x90, 0xd8, 0xab, 0x00, 0x8c, 0xbc, 0xd3, 0x0a, 0xf7, 0xe4, 0x58, 0x05, 0xb8, 0xb3, 0x45, 0x06,
    0xd0, 0x2c, 0x1e, 0x8f, 0xca, 0x3f, 0x0f, 0x02, 0xc1, 0xaf, 0xbd, 0x03, 0x01, 0x13, 0x8a, 0x6b,
    0x3a, 0x91, 0x11, 0x41, 0x4f, 0x67, 0xdc, 0xea, 0x97, 0xf2, 0xcf, 0xce, 0xf0, 0xb4, 0xe6, 0x73,
    0x96, 0xac, 0x74, 0x22, 0xe7, 0xad, 0x35, 0x85, 0xe2, 0xf9, 0x37, 0xe8, 0x1c, 0x75, 0xdf, 0x6e,
    0x47, 0xf1, 0x1a, 0x71, 0x1d, 0x29, 0xc5, 0x89, 0x6f, 0xb7, 0x62, 0x0e, 0xaa, 0x18, 0xbe, 0x1b,
    0xfc, 0x56, 0x3e, 0x4b, 0xc6, 0xd2, 0x79, 0x20, 0x9a, 0xdb, 0xc0, 0xfe, 0x78, 0xcd, 0x5a, 0xf4,
    0x1f, 0xdd, 0xa8, 0x33, 0x88, 0x07, 0xc7, 0x31, 0xb1, 0x12, 0x10, 0x59, 0x27, 0x80, 0xec, 0x5f,
    0x60, 0x51, 0x7f, 0xa9, 0x19, 0xb5, 0x4a, 0x0d, 0x2d, 0xe5, 0x7a, 0x9f, 0x93, 0xc9, 0x9c, 0xef,
    0xa0, 0xe0, 0x3b, 0x4d, 0xae, 0x2a, 0xf5, 0xb0, 0xc8, 0xeb, 0xbb, 0x3c, 0x83, 0x53, 0x99, 0x61,
    0x17, 0x2b, 0x04, 0x7e, 0xba, 0x77, 0xd6, 0x26, 0xe1, 0x69, 0x14, 0x63, 0x55, 0x21, 0x0c, 0x7d
};

static const uint32_t kAesRcon[10] = {
    0x01000000u, 0x02000000u, 0x04000000u, 0x08000000u, 0x10000000u,
    0x20000000u, 0x40000000u, 0x80000000u, 0x1b000000u, 0x36000000u
};

static inline uint32_t sub_word(uint32_t w) {
    return ((uint32_t)kAesSbox[(w >> 24) & 0xff] << 24) |
           ((uint32_t)kAesSbox[(w >> 16) & 0xff] << 16) |
           ((uint32_t)kAesSbox[(w >> 8)  & 0xff] << 8)  |
           ((uint32_t)kAesSbox[w         & 0xff]);
}

static inline uint32_t rot_word(uint32_t w) {
    return (w << 8) | (w >> 24);
}

static inline uint8_t gf28_xtime(uint8_t x) {
    return (uint8_t)((x << 1) ^ ((x & 0x80u) ? 0x1bu : 0x00u));
}

static inline uint8_t gf28_mul(uint8_t x, uint8_t y) {
    uint8_t r = 0;
    for (int i = 0; i < 8; ++i) {
        if (y & 1u) r ^= x;
        x = gf28_xtime(x);
        y >>= 1;
    }
    return r;
}

// ===================================================================================
// 2. AES KEY EXPANSION & BLOCK CIPHER (AArch64 @ 0x0a4850..0x0a4950)
// Mở rộng khóa vòng AES-128/192/256 và mã hóa/giải mã khối 128-bit
// ===================================================================================

/**
 * @brief Expands a 128/192/256-bit key into AES_KEY round schedule matching 0x0a48e0.
 * Opcode ARM64:
 *   0x0a48f8: cmp w20, #0x100 ; b.eq #0xa4908
 *   0x0a4900: cmp w20, #0xc0  ; b.ne #0xa4940
 */
int AES_set_encrypt_key(const uint8_t* userKey, int bits, AES_KEY* key) {
    if (!userKey || !key) return -1;
    if (bits != 128 && bits != 192 && bits != 256) return -2;

    int Nk = bits / 32;
    int Nr = Nk + 6; // 10, 12, or 14 rounds
    key->rounds = (uint32_t)Nr;

    uint32_t* rk = key->rd_key;
    for (int i = 0; i < Nk; ++i) {
        rk[i] = ((uint32_t)userKey[4 * i]     << 24) |
                ((uint32_t)userKey[4 * i + 1] << 16) |
                ((uint32_t)userKey[4 * i + 2] << 8)  |
                ((uint32_t)userKey[4 * i + 3]);
    }

    int total_words = 4 * (Nr + 1);
    for (int i = Nk; i < total_words; ++i) {
        uint32_t temp = rk[i - 1];
        if (i % Nk == 0) {
            temp = sub_word(rot_word(temp)) ^ kAesRcon[(i / Nk) - 1];
        } else if (Nk > 6 && (i % Nk == 4)) {
            temp = sub_word(temp);
        }
        rk[i] = rk[i - Nk] ^ temp;
    }
    return 0;
}

int AES_set_decrypt_key(const uint8_t* userKey, int bits, AES_KEY* key) {
    return AES_set_encrypt_key(userKey, bits, key);
}

static void add_round_key(uint8_t state[16], const uint32_t* rk) {
    for (int c = 0; c < 4; ++c) {
        uint32_t w = rk[c];
        state[4 * c + 0] ^= (uint8_t)(w >> 24);
        state[4 * c + 1] ^= (uint8_t)(w >> 16);
        state[4 * c + 2] ^= (uint8_t)(w >> 8);
        state[4 * c + 3] ^= (uint8_t)(w);
    }
}

/**
 * @brief Encrypts a single 16-byte block using AES_KEY (matching 0x0a4850).
 */
void AES_encrypt(const uint8_t* in, uint8_t* out, const AES_KEY* key) {
    if (!in || !out || !key) return;

    uint8_t s[16];
    memcpy(s, in, 16);
    add_round_key(s, key->rd_key);

    for (uint32_t r = 1; r < key->rounds; ++r) {
        // SubBytes
        for (int i = 0; i < 16; ++i) s[i] = kAesSbox[s[i]];

        // ShiftRows
        uint8_t t = s[1]; s[1] = s[5]; s[5] = s[9]; s[9] = s[13]; s[13] = t;
        t = s[2]; s[2] = s[10]; s[10] = t; t = s[6]; s[6] = s[14]; s[14] = t;
        t = s[15]; s[15] = s[11]; s[11] = s[7]; s[7] = s[3]; s[3] = t;

        // MixColumns over GF(2^8)
        for (int c = 0; c < 4; ++c) {
            uint8_t* col = s + 4 * c;
            uint8_t a0 = col[0], a1 = col[1], a2 = col[2], a3 = col[3];
            uint8_t x = a0 ^ a1 ^ a2 ^ a3;
            col[0] ^= x ^ gf28_xtime(a0 ^ a1);
            col[1] ^= x ^ gf28_xtime(a1 ^ a2);
            col[2] ^= x ^ gf28_xtime(a2 ^ a3);
            col[3] ^= x ^ gf28_xtime(a3 ^ a0);
        }

        add_round_key(s, key->rd_key + 4 * r);
    }

    // Final round (SubBytes + ShiftRows + AddRoundKey, no MixColumns)
    for (int i = 0; i < 16; ++i) s[i] = kAesSbox[s[i]];
    uint8_t t = s[1]; s[1] = s[5]; s[5] = s[9]; s[9] = s[13]; s[13] = t;
    t = s[2]; s[2] = s[10]; s[10] = t; t = s[6]; s[6] = s[14]; s[14] = t;
    t = s[15]; s[15] = s[11]; s[11] = s[7]; s[7] = s[3]; s[3] = t;
    add_round_key(s, key->rd_key + 4 * key->rounds);

    memcpy(out, s, 16);
}

/**
 * @brief Decrypts a single 16-byte block using AES_KEY.
 */
void AES_decrypt(const uint8_t* in, uint8_t* out, const AES_KEY* key) {
    if (!in || !out || !key) return;

    uint8_t s[16];
    memcpy(s, in, 16);
    add_round_key(s, key->rd_key + 4 * key->rounds);

    for (uint32_t r = key->rounds - 1; r >= 1; --r) {
        // InvShiftRows
        uint8_t t = s[13]; s[13] = s[9]; s[9] = s[5]; s[5] = s[1]; s[1] = t;
        t = s[2]; s[2] = s[10]; s[10] = t; t = s[6]; s[6] = s[14]; s[14] = t;
        t = s[3]; s[3] = s[7]; s[7] = s[11]; s[11] = s[15]; s[15] = t;

        // InvSubBytes
        for (int i = 0; i < 16; ++i) s[i] = kAesInvSbox[s[i]];

        add_round_key(s, key->rd_key + 4 * r);

        // InvMixColumns
        for (int c = 0; c < 4; ++c) {
            uint8_t* col = s + 4 * c;
            uint8_t a0 = col[0], a1 = col[1], a2 = col[2], a3 = col[3];
            col[0] = gf28_mul(a0, 0x0e) ^ gf28_mul(a1, 0x0b) ^ gf28_mul(a2, 0x0d) ^ gf28_mul(a3, 0x09);
            col[1] = gf28_mul(a0, 0x09) ^ gf28_mul(a1, 0x0e) ^ gf28_mul(a2, 0x0b) ^ gf28_mul(a3, 0x0d);
            col[2] = gf28_mul(a0, 0x0d) ^ gf28_mul(a1, 0x09) ^ gf28_mul(a2, 0x0e) ^ gf28_mul(a3, 0x0b);
            col[3] = gf28_mul(a0, 0x0b) ^ gf28_mul(a1, 0x0d) ^ gf28_mul(a2, 0x09) ^ gf28_mul(a3, 0x0e);
        }
    }

    // Final inverse round
    uint8_t t = s[13]; s[13] = s[9]; s[9] = s[5]; s[5] = s[1]; s[1] = t;
    t = s[2]; s[2] = s[10]; s[10] = t; t = s[6]; s[6] = s[14]; s[14] = t;
    t = s[3]; s[3] = s[7]; s[7] = s[11]; s[11] = s[15]; s[15] = t;
    for (int i = 0; i < 16; ++i) s[i] = kAesInvSbox[s[i]];
    add_round_key(s, key->rd_key);

    memcpy(out, s, 16);
}

void AES_cbc_encrypt(const uint8_t* in, uint8_t* out, size_t len,
                     const AES_KEY* key, uint8_t* ivec, int enc) {
    if (!in || !out || !key || !ivec) return;

    if (enc) {
        while (len >= 16u) {
            uint8_t block[16];
            for (int i = 0; i < 16; ++i) block[i] = in[i] ^ ivec[i];
            AES_encrypt(block, out, key);
            memcpy(ivec, out, 16);
            in += 16;
            out += 16;
            len -= 16;
        }
    } else {
        while (len >= 16u) {
            uint8_t next_iv[16];
            uint8_t block[16];
            memcpy(next_iv, in, 16);
            AES_decrypt(in, block, key);
            for (int i = 0; i < 16; ++i) out[i] = block[i] ^ ivec[i];
            memcpy(ivec, next_iv, 16);
            in += 16;
            out += 16;
            len -= 16;
        }
    }
}

static void ctr128_inc32(uint8_t counter[16]) {
    uint32_t c = ((uint32_t)counter[12] << 24) |
                 ((uint32_t)counter[13] << 16) |
                 ((uint32_t)counter[14] << 8)  |
                 ((uint32_t)counter[15]);
    c++;
    counter[12] = (uint8_t)(c >> 24);
    counter[13] = (uint8_t)(c >> 16);
    counter[14] = (uint8_t)(c >> 8);
    counter[15] = (uint8_t)(c);
}

void AES_ctr128_encrypt(const uint8_t* in, uint8_t* out, size_t len,
                        const AES_KEY* key, uint8_t ivec[16],
                        uint8_t ecount_buf[16], unsigned int* num) {
    if (!in || !out || !key || !ivec || !ecount_buf || !num) return;

    unsigned int n = *num;
    for (size_t i = 0; i < len; ++i) {
        if (n == 0) {
            AES_encrypt(ivec, ecount_buf, key);
            ctr128_inc32(ivec);
        }
        out[i] = in[i] ^ ecount_buf[n];
        n = (n + 1u) & 0x0fu;
    }
    *num = n;
}

// ===================================================================================
// 3. AES-GCM128 OVER GF(2^128) (NIST SP 800-38D, AArch64 @ 0x0b8d7c..0x0b9658)
// Nhân trường hữu hạn GF(2^128) với đa thức tối giản x^128 + x^7 + x^2 + x + 1 (0xE1<<120)
// ===================================================================================

static inline uint64_t gcm_load_be64(const uint8_t* p) {
    return ((uint64_t)p[0] << 56) | ((uint64_t)p[1] << 48) |
           ((uint64_t)p[2] << 40) | ((uint64_t)p[3] << 32) |
           ((uint64_t)p[4] << 24) | ((uint64_t)p[5] << 16) |
           ((uint64_t)p[6] << 8)  | ((uint64_t)p[7]);
}

static inline void gcm_store_be64(uint8_t* p, uint64_t v) {
    p[0] = (uint8_t)(v >> 56); p[1] = (uint8_t)(v >> 48);
    p[2] = (uint8_t)(v >> 40); p[3] = (uint8_t)(v >> 32);
    p[4] = (uint8_t)(v >> 24); p[5] = (uint8_t)(v >> 16);
    p[6] = (uint8_t)(v >> 8);  p[7] = (uint8_t)(v);
}

/**
 * @brief Multiplies 128-bit accumulator Xi by hash subkey H in GF(2^128).
 * Đa thức rút gọn NIST SP 800-38D: R = 0xE100000000000000ULL.
 */
static void gcm_gf128_mul(uint8_t Xi[16], const uint8_t H[16]) {
    uint64_t X_hi = gcm_load_be64(Xi);
    uint64_t X_lo = gcm_load_be64(Xi + 8);
    uint64_t V_hi = gcm_load_be64(H);
    uint64_t V_lo = gcm_load_be64(H + 8);
    uint64_t Z_hi = 0;
    uint64_t Z_lo = 0;

    for (int i = 0; i < 64; ++i) {
        if ((X_hi >> (63 - i)) & 1ULL) {
            Z_hi ^= V_hi;
            Z_lo ^= V_lo;
        }
        uint64_t lsb = V_lo & 1ULL;
        V_lo = (V_lo >> 1) | (V_hi << 63);
        V_hi = (V_hi >> 1) ^ (lsb ? 0xE100000000000000ULL : 0ULL);
    }
    for (int i = 0; i < 64; ++i) {
        if ((X_lo >> (63 - i)) & 1ULL) {
            Z_hi ^= V_hi;
            Z_lo ^= V_lo;
        }
        uint64_t lsb = V_lo & 1ULL;
        V_lo = (V_lo >> 1) | (V_hi << 63);
        V_hi = (V_hi >> 1) ^ (lsb ? 0xE100000000000000ULL : 0ULL);
    }

    gcm_store_be64(Xi, Z_hi);
    gcm_store_be64(Xi + 8, Z_lo);
}

/**
 * @brief Initializes GCM128_CONTEXT and computes H = AES_K(0^128).
 */
void CRYPTO_gcm128_init(GCM128_CONTEXT* ctx, const AES_KEY* key, const void* block_func) {
    if (!ctx || !key) return;
    memset(ctx, 0, sizeof(GCM128_CONTEXT));
    ctx->key = key;
    ctx->block_func = block_func ? block_func : (const void*)AES_encrypt;

    uint8_t zero[16] = {0};
    AES_encrypt(zero, ctx->H.c, key);
    ctx->Htable[1].hi = gcm_load_be64(ctx->H.c);
    ctx->Htable[1].lo = gcm_load_be64(ctx->H.c + 8);
}

/**
 * @brief Configures GCM IV (96-bit fast path J0 = IV || 0x00000001, or GHASH(IV) for non-12-byte IV).
 */
void CRYPTO_gcm128_setiv(GCM128_CONTEXT* ctx, const AES_KEY* key, const uint8_t* iv, size_t len) {
    if (!ctx || !iv || len == 0) return;
    if (key) ctx->key = key;

    memset(ctx->Yi.c, 0, 16);
    memset(ctx->Xi.c, 0, 16);
    ctx->len.u[0] = 0;
    ctx->len.u[1] = 0;
    ctx->ares = 0;
    ctx->mres = 0;

    if (len == 12u) {
        memcpy(ctx->Yi.c, iv, 12u);
        ctx->Yi.c[15] = 1u;
    } else {
        size_t rem = len;
        const uint8_t* p = iv;
        while (rem >= 16u) {
            for (int i = 0; i < 16; ++i) ctx->Yi.c[i] ^= p[i];
            gcm_gf128_mul(ctx->Yi.c, ctx->H.c);
            p += 16u;
            rem -= 16u;
        }
        if (rem > 0) {
            for (size_t i = 0; i < rem; ++i) ctx->Yi.c[i] ^= p[i];
            gcm_gf128_mul(ctx->Yi.c, ctx->H.c);
        }
        uint8_t len_block[16] = {0};
        gcm_store_be64(len_block + 8, (uint64_t)len * 8ULL);
        for (int i = 0; i < 16; ++i) ctx->Yi.c[i] ^= len_block[i];
        gcm_gf128_mul(ctx->Yi.c, ctx->H.c);
    }

    AES_encrypt(ctx->Yi.c, ctx->EK0.c, ctx->key);
}

/**
 * @brief Feeds Additional Authenticated Data (AAD) into GHASH matching AArch64 opcode at 0x0b8d7c.
 * Opcode ARM64:
 *   0x0b8d90: ldr x8, [x0, #0x38] ; cbz x8, #0xb8da0 (Rejects AAD if ciphertext len.u[1] != 0)
 *   0x0b8da0: ldr x8, [x0, #0x30] ; mov x9, #0x2000000000000000 (Enforces 2^61 byte AAD limit)
 */
int CRYPTO_gcm128_aad(GCM128_CONTEXT* ctx, const uint8_t* aad, size_t len) {
    if (!ctx) return -1;
    if (ctx->len.u[1] != 0) {
        return -2; // AAD cannot be added after encryption/decryption has started (0x0b8d90)
    }

    uint64_t alen = ctx->len.u[0] + len;
    if (alen > 0x2000000000000000ULL || alen < len) {
        return -1; // Exceeds 2^61 byte NIST SP 800-38D limit (0x0b8da4)
    }
    ctx->len.u[0] = alen;

    uint32_t n = ctx->ares;
    if (n > 0) {
        while (n < 16u && len > 0) {
            ctx->Xi.c[n] ^= *(aad++);
            --len;
            n = (n + 1u) & 0x0fu;
        }
        if (n == 0) {
            gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        } else {
            ctx->ares = n;
            return 0;
        }
    }

    while (len >= 16u) {
        for (int i = 0; i < 16; ++i) ctx->Xi.c[i] ^= aad[i];
        gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        aad += 16u;
        len -= 16u;
    }

    if (len > 0) {
        n = (uint32_t)len;
        for (size_t i = 0; i < len; ++i) ctx->Xi.c[i] ^= aad[i];
    }
    ctx->ares = n;
    return 0;
}

/**
 * @brief Encrypts plaintext and updates GHASH state matching AArch64 opcode at 0x0b8e78.
 */
int CRYPTO_gcm128_encrypt(GCM128_CONTEXT* ctx, const AES_KEY* key,
                          const uint8_t* in, uint8_t* out, size_t len) {
    if (!ctx || (!in && len > 0) || (!out && len > 0)) return -1;
    if (key) ctx->key = key;

    uint64_t mlen = ctx->len.u[1] + len;
    if (mlen > 0xFFFFFFFE0ULL || mlen < len) {
        return -1; // Exceeds 2^39 - 256 bits NIST SP 800-38D limit
    }
    ctx->len.u[1] = mlen;

    if (ctx->ares > 0) {
        gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        ctx->ares = 0;
    }

    uint32_t n = ctx->mres;
    for (size_t i = 0; i < len; ++i) {
        if (n == 0) {
            ctr128_inc32(ctx->Yi.c);
            AES_encrypt(ctx->Yi.c, ctx->EKi.c, ctx->key);
        }
        uint8_t c = (uint8_t)(in[i] ^ ctx->EKi.c[n]);
        out[i] = c;
        ctx->Xi.c[n] ^= c;
        n = (n + 1u) & 0x0fu;
        if (n == 0) {
            gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        }
    }
    ctx->mres = n;
    return 0;
}

/**
 * @brief Decrypts ciphertext and updates GHASH state before decrypting each byte.
 */
int CRYPTO_gcm128_decrypt(GCM128_CONTEXT* ctx, const AES_KEY* key,
                          const uint8_t* in, uint8_t* out, size_t len) {
    if (!ctx || (!in && len > 0) || (!out && len > 0)) return -1;
    if (key) ctx->key = key;

    uint64_t mlen = ctx->len.u[1] + len;
    if (mlen > 0xFFFFFFFE0ULL || mlen < len) {
        return -1;
    }
    ctx->len.u[1] = mlen;

    if (ctx->ares > 0) {
        gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        ctx->ares = 0;
    }

    uint32_t n = ctx->mres;
    for (size_t i = 0; i < len; ++i) {
        if (n == 0) {
            ctr128_inc32(ctx->Yi.c);
            AES_encrypt(ctx->Yi.c, ctx->EKi.c, ctx->key);
        }
        uint8_t c = in[i];
        ctx->Xi.c[n] ^= c;
        out[i] = (uint8_t)(c ^ ctx->EKi.c[n]);
        n = (n + 1u) & 0x0fu;
        if (n == 0) {
            gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        }
    }
    ctx->mres = n;
    return 0;
}

/**
 * @brief Finalizes GHASH with 64-bit AAD/ciphertext bit lengths and XORs with EK0.
 */
int CRYPTO_gcm128_finish(GCM128_CONTEXT* ctx, const uint8_t* tag, size_t len) {
    if (!ctx) return -1;

    if (ctx->ares > 0 || ctx->mres > 0) {
        gcm_gf128_mul(ctx->Xi.c, ctx->H.c);
        ctx->ares = 0;
        ctx->mres = 0;
    }

    uint8_t len_block[16];
    gcm_store_be64(len_block, ctx->len.u[0] << 3);
    gcm_store_be64(len_block + 8, ctx->len.u[1] << 3);

    for (int i = 0; i < 16; ++i) {
        ctx->Xi.c[i] ^= len_block[i];
    }
    gcm_gf128_mul(ctx->Xi.c, ctx->H.c);

    for (int i = 0; i < 16; ++i) {
        ctx->Xi.c[i] ^= ctx->EK0.c[i];
    }

    if (tag && len > 0) {
        size_t check_len = (len > 16u) ? 16u : len;
        uint8_t diff = 0;
        for (size_t i = 0; i < check_len; ++i) {
            diff |= (uint8_t)(ctx->Xi.c[i] ^ tag[i]);
        }
        return (int)diff;
    }
    return 0;
}

/**
 * @brief Extracts up to 16 bytes of the authentication tag matching AArch64 opcode at 0x0b9610.
 * Opcode ARM64:
 *   0x0b9634: cmp x19, #0x10 ; mov w8, #0x10 ; csel x2, x19, x8, lo
 */
void CRYPTO_gcm128_tag(GCM128_CONTEXT* ctx, uint8_t* tag, size_t len) {
    if (!ctx || !tag) return;
    CRYPTO_gcm128_finish(ctx, NULL, 0);
    size_t copy_len = (len < 16u) ? len : 16u;
    memcpy(tag, ctx->Xi.c, copy_len);
}
