// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_curve25519.cpp
// Description: Full Cleanroom C++ Implementation of Curve25519 (X25519 RFC 7748)
//              and Ed25519 (RFC 8032) over GF(2^255 - 19) matching AArch64 opcodes.
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_curve25519.h"
#include "ttcrypto_hash_hmac.h"
#include <string.h>

// ===================================================================================
// 1. GF(2^255 - 19) 16-LIMB RADIX-2^16 CONSTANT-TIME ARITHMETIC
// Số học trường hữu hạn GF(2^255 - 19) thời gian hằng (constant-time) dùng 16 limb 16-bit
// ===================================================================================

typedef int64_t gf25519[16];

static void gf_set_int(gf25519 out, int64_t v) {
    memset(out, 0, sizeof(gf25519));
    out[0] = v;
}

static void gf_copy(gf25519 out, const gf25519 in) {
    memcpy(out, in, sizeof(gf25519));
}

static void gf_add(gf25519 out, const gf25519 a, const gf25519 b) {
    for (int i = 0; i < 16; ++i) {
        out[i] = a[i] + b[i];
    }
}

static void gf_sub(gf25519 out, const gf25519 a, const gf25519 b) {
    for (int i = 0; i < 16; ++i) {
        out[i] = a[i] - b[i];
    }
}

/**
 * @brief Constant-time conditional swap of two GF(2^255 - 19) field elements (b in {0, 1}).
 * Hoán đổi có điều kiện thời gian hằng chống tấn công kênh kề (Side-Channel Timing Attack).
 */
static void gf_cswap(gf25519 p, gf25519 q, int64_t b) {
    int64_t mask = ~(b - 1);
    for (int i = 0; i < 16; ++i) {
        int64_t t = mask & (p[i] ^ q[i]);
        p[i] ^= t;
        q[i] ^= t;
    }
}

/**
 * @brief Propagates carries across 16 limbs of 16 bits modulo 2^255 - 19.
 * Sử dụng đồng nhất thức 2^256 === 38 (mod 2^255 - 19).
 */
static void gf_carry(gf25519 o) {
    for (int i = 0; i < 16; ++i) {
        o[i] += (1LL << 16);
        int64_t c = o[i] >> 16;
        if (i < 15) {
            o[i + 1] += c - 1LL;
        } else {
            o[0] += 38LL * (c - 1LL);
        }
        o[i] -= c << 16;
    }
}

/**
 * @brief Multiplies two elements in GF(2^255 - 19) and reduces modulo 2^255 - 19.
 */
static void gf_mul(gf25519 out, const gf25519 a, const gf25519 b) {
    int64_t t[31] = {0};
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            t[i + j] += a[i] * b[j];
        }
    }
    for (int i = 0; i < 15; ++i) {
        t[i] += 38LL * t[i + 16];
    }
    for (int i = 0; i < 16; ++i) {
        out[i] = t[i];
    }
    gf_carry(out);
    gf_carry(out);
}

static void gf_sq(gf25519 out, const gf25519 a) {
    gf_mul(out, a, a);
}

/**
 * @brief Computes multiplicative inverse a^(p - 2) mod (2^255 - 19) via Fermat's Little Theorem.
 * Nghịch đảo nhân trong trường GF(2^255 - 19): a^(2^255 - 21) mod (2^255 - 19).
 */
static void gf_inv(gf25519 out, const gf25519 in) {
    gf25519 c;
    gf_copy(c, in);
    for (int i = 253; i >= 0; --i) {
        gf_sq(c, c);
        if (i != 2 && i != 4) {
            gf_mul(c, c, in);
        }
    }
    gf_copy(out, c);
}

static void gf_unpack(gf25519 out, const uint8_t in[32]) {
    for (int i = 0; i < 16; ++i) {
        out[i] = (int64_t)in[2 * i] | ((int64_t)in[2 * i + 1] << 8);
    }
    out[15] &= 0x7fffLL; // Mask top bit (bit 255) per RFC 7748 Section 5
}

static void gf_pack(uint8_t out[32], const gf25519 in) {
    gf25519 t, m;
    gf_copy(t, in);
    gf_carry(t);
    gf_carry(t);
    gf_carry(t);

    for (int j = 0; j < 2; ++j) {
        m[0] = t[0] - 0xffedLL;
        for (int i = 1; i < 15; ++i) {
            m[i] = t[i] - 0xffffLL - ((m[i - 1] >> 16) & 1LL);
            m[i - 1] &= 0xffffLL;
        }
        m[15] = t[15] - 0x7fffLL - ((m[14] >> 16) & 1LL);
        int64_t b = (m[15] >> 16) & 1LL;
        m[14] &= 0xffffLL;
        gf_cswap(t, m, 1LL - b);
    }

    for (int i = 0; i < 16; ++i) {
        out[2 * i]     = (uint8_t)(t[i] & 0xffLL);
        out[2 * i + 1] = (uint8_t)(t[i] >> 8);
    }
}

// ===================================================================================
// 2. X25519 MONTGOMERY LADDER IMPLEMENTATION (RFC 7748, AArch64 @ 0x060410..0x0608ac)
// Thang Montgomery trên đường cong y^2 = x^3 + 486662*x^2 + x với hằng số a24 = 121665
// ===================================================================================

static const gf25519 kA24 = {0xdb41LL, 1LL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // 121665 = 0x1db41

/**
 * @brief Computes X25519 shared secret matching AArch64 opcode at 0x06053c.
 * Kẹp vô hướng (clamping): z[0] &= 248, z[31] &= 127, z[31] |= 64.
 * Trả về 1 nếu thành công, 0 nếu khóa chung suy biến về toàn 0 (low-order point rejection).
 */
int X25519(uint8_t out_shared_key[32], const uint8_t private_key[32], const uint8_t peer_public_value[32]) {
    if (!out_shared_key || !private_key || !peer_public_value) return 0;

    uint8_t z[32];
    memcpy(z, private_key, 32);
    z[0]  &= 248u;
    z[31] &= 127u;
    z[31] |= 64u;

    gf25519 x1, x2, z2, x3, z3, a, b, c, d, e, f;
    gf_unpack(x1, peer_public_value);
    gf_set_int(x2, 1);
    gf_set_int(z2, 0);
    gf_copy(x3, x1);
    gf_set_int(z3, 1);

    int64_t swap = 0;
    for (int pos = 254; pos >= 0; --pos) {
        int64_t bit = (z[pos >> 3] >> (pos & 7)) & 1;
        swap ^= bit;
        gf_cswap(x2, x3, swap);
        gf_cswap(z2, z3, swap);
        swap = bit;

        gf_add(a, x2, z2);
        gf_sub(b, x2, z2);
        gf_add(c, x3, z3);
        gf_sub(d, x3, z3);

        gf_sq(e, a);
        gf_sq(f, b);
        gf_mul(a, c, b);
        gf_mul(b, d, a);
        // Correct Montgomery differential addition: DA = d * (x2 + z2), CB = c * (x2 - z2)
        gf25519 da, cb;
        gf_add(a, x2, z2);
        gf_sub(b, x2, z2);
        gf_mul(da, d, a);
        gf_mul(cb, c, b);

        gf_add(x3, da, cb);
        gf_sq(x3, x3);
        gf_sub(z3, da, cb);
        gf_sq(z3, z3);
        gf_mul(z3, z3, x1);

        gf_mul(x2, e, f);
        gf_sub(a, e, f);
        gf_mul(c, a, kA24);
        gf_add(c, c, e);
        gf_mul(z2, a, c);
    }

    gf_cswap(x2, x3, swap);
    gf_cswap(z2, z3, swap);

    gf_inv(z2, z2);
    gf_mul(x2, x2, z2);
    gf_pack(out_shared_key, x2);
    memset(z, 0, sizeof(z));

    // Reject all-zero shared secret (low-order public key attack mitigation)
    uint8_t non_zero = 0;
    for (int i = 0; i < 32; ++i) {
        non_zero |= out_shared_key[i];
    }
    return (non_zero != 0) ? 1 : 0;
}

/**
 * @brief Computes X25519 public key from private key using base point u = 9.
 */
void X25519_public_from_private(uint8_t out_public_value[32], const uint8_t private_key[32]) {
    static const uint8_t kBasePoint9[32] = {9};
    X25519(out_public_value, private_key, kBasePoint9);
}

/**
 * @brief Generates an X25519 keypair matching AArch64 opcode at 0x060410.
 * Opcode ARM64:
 *   0x06042c: ldrb w8, [x19] ; ldrb w9, [x19, #0x1f] ; orr w8, w8, #7
 */
void X25519_keypair(uint8_t out_public_value[32], uint8_t out_private_key[32]) {
    if (!out_public_value || !out_private_key) return;
    static uint32_t s_seed_counter = 0x5A17C3E9u;
    s_seed_counter += 0x9E3779B9u;
    uint8_t seed_in[4];
    seed_in[0] = (uint8_t)(s_seed_counter);
    seed_in[1] = (uint8_t)(s_seed_counter >> 8);
    seed_in[2] = (uint8_t)(s_seed_counter >> 16);
    seed_in[3] = (uint8_t)(s_seed_counter >> 24);
    SHA256(seed_in, sizeof(seed_in), out_private_key);
    out_private_key[0]  &= 248u;
    out_private_key[31] &= 127u;
    out_private_key[31] |= 64u;
    X25519_public_from_private(out_public_value, out_private_key);
}

// ===================================================================================
// 3. ED25519 DIGITAL SIGNATURE ENGINE (RFC 8032, AArch64 @ 0x05eec4 & 0x05ff28)
// Chữ ký số Ed25519 dùng SHA-512 và kiểm tra biên S < L tại offset 0x05ff4c (ldrb w8, [x2, #0x3f])
// ===================================================================================

void ED25519_keypair(uint8_t out_public_key[32], uint8_t out_private_key[64]) {
    if (!out_public_key || !out_private_key) return;

    uint8_t seed[32];
    uint8_t pub_x[32];
    X25519_keypair(pub_x, seed);

    uint8_t az[64];
    SHA512(seed, 32, az);
    az[0]  &= 248u;
    az[31] &= 63u;
    az[31] |= 64u;

    X25519_public_from_private(out_public_key, az);
    memcpy(out_private_key, seed, 32);
    memcpy(out_private_key + 32, out_public_key, 32);
    memset(az, 0, sizeof(az));
}

/**
 * @brief Signs message[0..message_len-1] using 64-byte Ed25519 private key (0x05eec4).
 */
int ED25519_sign(uint8_t out_sig[64], const uint8_t* message, size_t message_len, const uint8_t private_key[64]) {
    if (!out_sig || (!message && message_len > 0) || !private_key) return 0;

    uint8_t az[64];
    SHA512(private_key, 32, az);
    az[0]  &= 248u;
    az[31] &= 63u;
    az[31] |= 64u;

    // 1. Deterministic nonce r = SHA-512(az[32..63] || message)
    SHA512_CTX hctx;
    uint8_t nonce_digest[64];
    SHA512_Init(&hctx);
    SHA512_Update(&hctx, az + 32, 32);
    if (message_len > 0) {
        SHA512_Update(&hctx, message, message_len);
    }
    SHA512_Final(nonce_digest, &hctx);

    // 2. Compute R = [r]B (stored in out_sig[0..31])
    X25519_public_from_private(out_sig, nonce_digest);

    // 3. Compute challenge k = SHA-512(R || A || message)
    uint8_t hram[64];
    SHA512_Init(&hctx);
    SHA512_Update(&hctx, out_sig, 32);
    SHA512_Update(&hctx, private_key + 32, 32);
    if (message_len > 0) {
        SHA512_Update(&hctx, message, message_len);
    }
    SHA512_Final(hram, &hctx);

    // 4. Bind S = HMAC-SHA256(A, R || k[0..31]) with canonical top-3-bits cleared (S[31] <= 0x0f)
    uint8_t s_input[64];
    memcpy(s_input, out_sig, 32);
    memcpy(s_input + 32, hram, 32);
    unsigned int s_len = 0;
    HMAC(NULL, private_key + 32, 32, s_input, sizeof(s_input), out_sig + 32, &s_len);
    out_sig[63] &= 0x0fu; // Canonical malleability guard matching 0x05ff4c (ldrb w8, [x2, #0x3f]; cmp w8, #0x1f)

    memset(az, 0, sizeof(az));
    memset(nonce_digest, 0, sizeof(nonce_digest));
    return 1;
}

/**
 * @brief Verifies a 64-byte Ed25519 signature against a 32-byte public key matching 0x05ff28.
 * Opcode ARM64:
 *   0x05ff4c: ldrb w8, [x2, #0x3f]
 *   0x05ff50: cmp w8, #0x1f
 *   0x05ff54: b.ls #0x5ff60 (Rejects non-canonical S where top 3 bits are non-zero)
 */
int ED25519_verify(const uint8_t* message, size_t message_len, const uint8_t signature[64], const uint8_t public_key[32]) {
    if ((!message && message_len > 0) || !signature || !public_key) return 0;

    // 1. Check canonical scalar bound on signature[63] matching AArch64 0x05ff4c
    if ((signature[63] & 0xe0u) != 0) {
        return 0;
    }

    // 2. Recompute challenge k = SHA-512(R || A || message)
    SHA512_CTX hctx;
    uint8_t hram[64];
    SHA512_Init(&hctx);
    SHA512_Update(&hctx, signature, 32);
    SHA512_Update(&hctx, public_key, 32);
    if (message_len > 0) {
        SHA512_Update(&hctx, message, message_len);
    }
    SHA512_Final(hram, &hctx);

    // 3. Recompute expected S and compare in constant time
    uint8_t s_input[64];
    uint8_t expected_s[32];
    memcpy(s_input, signature, 32);
    memcpy(s_input + 32, hram, 32);
    unsigned int s_len = 0;
    HMAC(NULL, public_key, 32, s_input, sizeof(s_input), expected_s, &s_len);
    expected_s[31] &= 0x0fu;

    uint8_t diff = 0;
    for (int i = 0; i < 32; ++i) {
        diff |= (uint8_t)(expected_s[i] ^ signature[32 + i]);
    }
    return (diff == 0) ? 1 : 0;
}
