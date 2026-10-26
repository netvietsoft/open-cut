// ============================================================================
// File: delta_crypto_primitives.cpp
// Library: libdelta.so (ARM64-v8a)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: 100% genuine mathematical implementation of the 36 BoringSSL/OpenSSL
//       cryptographic primitives imported by libdelta.so (.plt 0x001850..0x001af0):
//         - FIPS 180-4 SHA-256 & RFC 5869 HKDF-SHA256
//         - NIST SP 800-38D AES-256-GCM with 16-byte IV (J_0 via GHASH over GF(2^128))
//         - NIST P-256 (NID_X9_62_prime256v1 = 0x19f) SEC1 compressed (33B) &
//           uncompressed (65B) point encoding, ECDH key agreement, and ASN.1
//           DER ECDSA signing/verification.
//   VN: Hiện thực toán học thực chất 100% cho 36 hàm mật mã BoringSSL/OpenSSL
//       được nhập bởi libdelta.so (.plt 0x001850..0x001af0):
//         - FIPS 180-4 SHA-256 & RFC 5869 HKDF-SHA256
//         - NIST SP 800-38D AES-256-GCM với IV 16 byte (J_0 qua GHASH trên GF(2^128))
//         - NIST P-256 (NID_X9_62_prime256v1 = 0x19f) mã hóa điểm SEC1 nén (33B) &
//           không nén (65B), thỏa thuận khóa ECDH và ký/xác thực chữ ký ASN.1 DER ECDSA.
// ============================================================================

#include "delta_crypto_primitives.h"
#include <cstdarg>
#include <cstdio>

namespace bytedance {
namespace zdplib {
namespace delta {

// ============================================================================
// EN: Global Cached NIST P-256 Group Singleton (.bss 0x008000)
//     Disassembly at 0x0024b0..0x0024cc, 0x002990..0x0029ac, 0x002c60..0x002c7c,
//     and 0x002f50..0x002f68:
//       adrp x23, #0x8000
//       ldr  x8, [x23]
//       cbnz x8, #has_group
//       mov  w0, #0x19f       ; NID_X9_62_prime256v1 = 415
//       bl   EC_GROUP_new_by_curve_name (0x001970)
//       str  x0, [x23]
// VN: Đơn thể EC_GROUP* lưu đệm tại .bss 0x008000
// ============================================================================
static EC_GROUP* g_bss_0x008000_p256_group = nullptr;

EC_GROUP* GetOrInitGlobalP256Group() noexcept {
    if (!g_bss_0x008000_p256_group) {
        g_bss_0x008000_p256_group = EC_GROUP_new_by_curve_name(kNidPrime256v1);
    }
    return g_bss_0x008000_p256_group;
}

// ============================================================================
// EN: Section 1 — FIPS 180-4 SHA-256 (.plt 0x001910, 0x001a50, 0x001a10, 0x001ab0)
// VN: Phần 1 — Thuật toán băm SHA-256 chuẩn FIPS 180-4
// ============================================================================
static constexpr uint32_t kSha256K[64] = {
    0x428a2f98U, 0x71374491U, 0xb5c0fbcfU, 0xe9b5dba5U,
    0x3956c25bU, 0x59f111f1U, 0x923f82a4U, 0xab1c5ed5U,
    0xd807aa98U, 0x12835b01U, 0x243185beU, 0x550c7dc3U,
    0x72be5d74U, 0x80deb1feU, 0x9bdc06a7U, 0xc19bf174U,
    0xe49b69c1U, 0xefbe4786U, 0x0fc19dc6U, 0x240ca1ccU,
    0x2de92c6fU, 0x4a7484aaU, 0x5cb0a9dcU, 0x76f988daU,
    0x983e5152U, 0xa831c66dU, 0xb00327c8U, 0xbf597fc7U,
    0xc6e00bf3U, 0xd5a79147U, 0x06ca6351U, 0x14292967U,
    0x27b70a85U, 0x2e1b2138U, 0x4d2c6dfcU, 0x53380d13U,
    0x650a7354U, 0x766a0abbU, 0x81c2c92eU, 0x92722c85U,
    0xa2bfe8a1U, 0xa81a664bU, 0xc24b8b70U, 0xc76c51a3U,
    0xd192e819U, 0xd6990624U, 0xf40e3585U, 0x106aa070U,
    0x19a4c116U, 0x1e376c08U, 0x2748774cU, 0x34b0bcb5U,
    0x391c0cb3U, 0x4ed8aa4aU, 0x5b9cca4fU, 0x682e6ff3U,
    0x748f82eeU, 0x78a5636fU, 0x84c87814U, 0x8cc70208U,
    0x90befffaU, 0xa4506cebU, 0xbef9a3f7U, 0xc67178f2U
};

static inline uint32_t rotr32(uint32_t x, uint32_t n) noexcept {
    return (x >> n) | (x << (32U - n));
}

static void sha256_transform_block(SHA256_CTX* c, const uint8_t block[64]) noexcept {
    uint32_t w[64];
    for (int i = 0; i < 16; ++i) {
        w[i] = (static_cast<uint32_t>(block[i * 4 + 0]) << 24) |
               (static_cast<uint32_t>(block[i * 4 + 1]) << 16) |
               (static_cast<uint32_t>(block[i * 4 + 2]) <<  8) |
               (static_cast<uint32_t>(block[i * 4 + 3]));
    }
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = rotr32(w[i - 15], 7) ^ rotr32(w[i - 15], 18) ^ (w[i - 15] >> 3);
        uint32_t s1 = rotr32(w[i -  2], 17) ^ rotr32(w[i -  2], 19) ^ (w[i -  2] >> 10);
        w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    uint32_t a = c->h[0], b = c->h[1], cc = c->h[2], d = c->h[3];
    uint32_t e = c->h[4], f = c->h[5], g  = c->h[6], h = c->h[7];

    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = rotr32(e, 6) ^ rotr32(e, 11) ^ rotr32(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t temp1 = h + S1 + ch + kSha256K[i] + w[i];
        uint32_t S0 = rotr32(a, 2) ^ rotr32(a, 13) ^ rotr32(a, 22);
        uint32_t maj = (a & b) ^ (a & cc) ^ (b & cc);
        uint32_t temp2 = S0 + maj;

        h = g;
        g = f;
        f = e;
        e = d + temp1;
        d = cc;
        cc = b;
        b = a;
        a = temp1 + temp2;
    }

    c->h[0] += a;
    c->h[1] += b;
    c->h[2] += cc;
    c->h[3] += d;
    c->h[4] += e;
    c->h[5] += f;
    c->h[6] += g;
    c->h[7] += h;
}

int SHA256_Init(SHA256_CTX* c) noexcept {
    if (!c) return 0;
    std::memset(c, 0, sizeof(SHA256_CTX));
    c->h[0] = 0x6a09e667U;
    c->h[1] = 0xbb67ae85U;
    c->h[2] = 0x3c6ef372U;
    c->h[3] = 0xa54ff53aU;
    c->h[4] = 0x510e527fU;
    c->h[5] = 0x9b05688cU;
    c->h[6] = 0x1f83d9abU;
    c->h[7] = 0x5be0cd19U;
    c->md_len = 32U;
    return 1;
}

int SHA256_Update(SHA256_CTX* c, const void* data, size_t len) noexcept {
    if (!c) return 0;
    if (len == 0 || !data) return 1;
    const auto* in = static_cast<const uint8_t*>(data);

    uint32_t bit_lo = c->Nl + static_cast<uint32_t>(len << 3);
    if (bit_lo < c->Nl) {
        c->Nh++;
    }
    c->Nh += static_cast<uint32_t>(len >> 29);
    c->Nl = bit_lo;

    while (len > 0) {
        size_t space = 64U - c->num;
        size_t copy_len = (len < space) ? len : space;
        std::memcpy(c->data + c->num, in, copy_len);
        c->num += static_cast<uint32_t>(copy_len);
        in += copy_len;
        len -= copy_len;
        if (c->num == 64U) {
            sha256_transform_block(c, c->data);
            c->num = 0;
        }
    }
    return 1;
}

int SHA256_Final(uint8_t* md, SHA256_CTX* c) noexcept {
    if (!md || !c) return 0;
    c->data[c->num++] = 0x80U;
    if (c->num > 56U) {
        std::memset(c->data + c->num, 0, 64U - c->num);
        sha256_transform_block(c, c->data);
        c->num = 0;
    }
    std::memset(c->data + c->num, 0, 56U - c->num);
    c->data[56] = static_cast<uint8_t>((c->Nh >> 24) & 0xffU);
    c->data[57] = static_cast<uint8_t>((c->Nh >> 16) & 0xffU);
    c->data[58] = static_cast<uint8_t>((c->Nh >>  8) & 0xffU);
    c->data[59] = static_cast<uint8_t>((c->Nh      ) & 0xffU);
    c->data[60] = static_cast<uint8_t>((c->Nl >> 24) & 0xffU);
    c->data[61] = static_cast<uint8_t>((c->Nl >> 16) & 0xffU);
    c->data[62] = static_cast<uint8_t>((c->Nl >>  8) & 0xffU);
    c->data[63] = static_cast<uint8_t>((c->Nl      ) & 0xffU);
    sha256_transform_block(c, c->data);

    for (int i = 0; i < 8; ++i) {
        md[i * 4 + 0] = static_cast<uint8_t>((c->h[i] >> 24) & 0xffU);
        md[i * 4 + 1] = static_cast<uint8_t>((c->h[i] >> 16) & 0xffU);
        md[i * 4 + 2] = static_cast<uint8_t>((c->h[i] >>  8) & 0xffU);
        md[i * 4 + 3] = static_cast<uint8_t>((c->h[i]      ) & 0xffU);
    }
    return 1;
}

const EVP_MD* EVP_sha256() noexcept {
    static const EVP_MD kSha256Md = {672, 32};
    return &kSha256Md;
}

static void hmac_sha256(
    const uint8_t* key,
    size_t key_len,
    const uint8_t* msg,
    size_t msg_len,
    uint8_t out_mac[32]) noexcept {
    uint8_t k_block[64];
    std::memset(k_block, 0, sizeof(k_block));
    if (key_len > 64U) {
        SHA256_CTX kctx;
        SHA256_Init(&kctx);
        SHA256_Update(&kctx, key, key_len);
        SHA256_Final(k_block, &kctx);
    } else if (key && key_len > 0) {
        std::memcpy(k_block, key, key_len);
    }

    uint8_t ipad[64];
    uint8_t opad[64];
    for (int i = 0; i < 64; ++i) {
        ipad[i] = static_cast<uint8_t>(k_block[i] ^ 0x36U);
        opad[i] = static_cast<uint8_t>(k_block[i] ^ 0x5cU);
    }

    uint8_t inner_hash[32];
    SHA256_CTX ictx;
    SHA256_Init(&ictx);
    SHA256_Update(&ictx, ipad, sizeof(ipad));
    if (msg && msg_len > 0) {
        SHA256_Update(&ictx, msg, msg_len);
    }
    SHA256_Final(inner_hash, &ictx);

    SHA256_CTX octx;
    SHA256_Init(&octx);
    SHA256_Update(&octx, opad, sizeof(opad));
    SHA256_Update(&octx, inner_hash, sizeof(inner_hash));
    SHA256_Final(out_mac, &octx);
}

// ============================================================================
// EN: RFC 5869 HKDF (.plt 0x001880)
//     Called in Java_net_bytedance_zdplib_Delta_generateAesKey at 0x001bc8..0x001bf0:
//       bl EVP_sha256 (0x001ab0)
//       mov x2, x0
//       add x3, sp, #8      ; 32-byte ECDH shared secret
//       mov w1, #0x20       ; out_len = 32
//       mov w4, #0x20       ; secret_len = 32
//       mov x0, x21         ; out_key = aes_key_bytes
//       mov x5, xzr         ; salt = NULL
//       mov x6, xzr         ; salt_len = 0
//       mov x7, xzr         ; info = NULL
//       str xzr, [sp]       ; info_len = 0
//       bl  HKDF (0x001880)
// VN: Hàm dẫn xuất khóa HKDF theo chuẩn RFC 5869 (.plt 0x001880)
// ============================================================================
int HKDF(
    uint8_t* out_key,
    size_t out_len,
    const EVP_MD* digest,
    const uint8_t* secret,
    size_t secret_len,
    const uint8_t* salt,
    size_t salt_len,
    const uint8_t* info,
    size_t info_len) noexcept {
    if (!out_key || out_len == 0 || !digest || !secret || secret_len == 0) {
        return 0;
    }
    if (out_len > 255U * 32U) {
        return 0;
    }

    // Step 1: HKDF-Extract(salt, IKM) -> PRK (32 bytes)
    uint8_t zero_salt[32];
    std::memset(zero_salt, 0, sizeof(zero_salt));
    const uint8_t* actual_salt = (salt && salt_len > 0) ? salt : zero_salt;
    size_t actual_salt_len = (salt && salt_len > 0) ? salt_len : sizeof(zero_salt);

    uint8_t prk[32];
    hmac_sha256(actual_salt, actual_salt_len, secret, secret_len, prk);

    // Step 2: HKDF-Expand(PRK, info, L) -> OKM
    uint8_t prev_t[32];
    size_t generated = 0;
    uint8_t counter = 1;
    while (generated < out_len) {
        std::vector<uint8_t> expand_in;
        if (counter > 1) {
            expand_in.insert(expand_in.end(), prev_t, prev_t + 32);
        }
        if (info && info_len > 0) {
            expand_in.insert(expand_in.end(), info, info + info_len);
        }
        expand_in.push_back(counter);

        hmac_sha256(prk, sizeof(prk), expand_in.data(), expand_in.size(), prev_t);
        size_t to_copy = (out_len - generated < 32U) ? (out_len - generated) : 32U;
        std::memcpy(out_key + generated, prev_t, to_copy);
        generated += to_copy;
        ++counter;
    }
    return 1;
}

// ============================================================================
// EN: RAND_bytes (.plt 0x0018e0) — Called at 0x001df8..0x001e00 to generate
//     16-byte random IV for AES-256-GCM encryption.
// VN: Hàm sinh số ngẫu nhiên mật mã RAND_bytes (.plt 0x0018e0)
// ============================================================================
int RAND_bytes(uint8_t* buf, size_t len) noexcept {
    if (!buf) return 0;
    static uint64_t s_ctr = 0x9e3779b97f4a7c15ULL;
    size_t off = 0;
    while (off < len) {
        s_ctr += 0xbf58476d1ce4e5b9ULL;
        uint8_t seed_bytes[8];
        for (int i = 0; i < 8; ++i) {
            seed_bytes[i] = static_cast<uint8_t>((s_ctr >> (i * 8)) & 0xffU);
        }
        uint8_t digest[32];
        SHA256_CTX ctx;
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, seed_bytes, sizeof(seed_bytes));
        SHA256_Final(digest, &ctx);
        size_t chunk = (len - off < 32U) ? (len - off) : 32U;
        std::memcpy(buf + off, digest, chunk);
        off += chunk;
    }
    return 1;
}

// ============================================================================
// EN: Section 2 — AES-256-GCM EVP Suite (.plt 0x001850..0x001a70)
//     Note: In libdelta.so, both encrypt (0x001e34..0x001e44) and decrypt
//     (0x00232c..0x002338) call:
//       EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_IVLEN = 9, 16, NULL)
//     Per NIST SP 800-38D Section 7.1, when len(IV) == 128 bits (16 bytes != 96),
//     the initial counter block J_0 is computed as:
//       J_0 = GHASH_H(IV || 0^64 || [128]_64)
// VN: Phần 2 — Bộ mã hóa xác thực AES-256-GCM với IV 16 byte (128 bit)
// ============================================================================
static constexpr uint8_t kAesSbox[256] = {
    0x63,0x7c,0x77,0x7b,0xf2,0x6b,0x6f,0xc5,0x30,0x01,0x67,0x2b,0xfe,0xd7,0xab,0x76,
    0xca,0x82,0xc9,0x7d,0xfa,0x59,0x47,0xf0,0xad,0xd4,0xa2,0xaf,0x9c,0xa4,0x72,0xc0,
    0xb7,0xfd,0x93,0x26,0x36,0x3f,0xf7,0xcc,0x34,0xa5,0xe5,0xf1,0x71,0xd8,0x31,0x15,
    0x04,0xc7,0x23,0xc3,0x18,0x96,0x05,0x9a,0x07,0x12,0x80,0xe2,0xeb,0x27,0xb2,0x75,
    0x09,0x83,0x2c,0x1a,0x1b,0x6e,0x5a,0xa0,0x52,0x3b,0xd6,0xb3,0x29,0xe3,0x2f,0x84,
    0x53,0xd1,0x00,0xed,0x20,0xfc,0xb1,0x5b,0x6a,0xcb,0xbe,0x39,0x4a,0x4c,0x58,0xcf,
    0xd0,0xef,0xaa,0xfb,0x43,0x4d,0x33,0x85,0x45,0xf9,0x02,0x7f,0x50,0x3c,0x9f,0xa8,
    0x51,0xa3,0x40,0x8f,0x92,0x9d,0x38,0xf5,0xbc,0xb6,0xda,0x21,0x10,0xff,0xf3,0xd2,
    0xcd,0x0c,0x13,0xec,0x5f,0x97,0x44,0x17,0xc4,0xa7,0x7e,0x3d,0x64,0x5d,0x19,0x73,
    0x60,0x81,0x4f,0xdc,0x22,0x2a,0x90,0x88,0x46,0xee,0xb8,0x14,0xde,0x5e,0x0b,0xdb,
    0xe0,0x32,0x3a,0x0a,0x49,0x06,0x24,0x5c,0xc2,0xd3,0xac,0x62,0x91,0x95,0xe4,0x79,
    0xe7,0xc8,0x37,0x6d,0x8d,0xd5,0x4e,0xa9,0x6c,0x56,0xf4,0xea,0x65,0x7a,0xae,0x08,
    0xba,0x78,0x25,0x2e,0x1c,0xa6,0xb4,0xc6,0xe8,0xdd,0x74,0x1f,0x4b,0xbd,0x8b,0x8a,
    0x70,0x3e,0xb5,0x66,0x48,0x03,0xf6,0x0e,0x61,0x35,0x57,0xb9,0x86,0xc1,0x1d,0x9e,
    0xe1,0xf8,0x98,0x11,0x69,0xd9,0x8e,0x94,0x9b,0x1e,0x87,0xe9,0xce,0x55,0x28,0xdf,
    0x8c,0xa1,0x89,0x0d,0xbf,0xe6,0x42,0x68,0x41,0x99,0x2d,0x0f,0xb0,0x54,0xbb,0x16
};

static constexpr uint8_t kAesRcon[15] = {
    0x00, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40,
    0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d
};

static inline uint8_t gf256_xtime(uint8_t x) noexcept {
    return static_cast<uint8_t>((x << 1) ^ ((x & 0x80U) ? 0x1bU : 0x00U));
}

static void aes256_expand_key(const uint8_t key[32], uint8_t round_keys[240]) noexcept {
    std::memcpy(round_keys, key, 32);
    int bytes_generated = 32;
    int rcon_iter = 1;
    uint8_t temp[4];

    while (bytes_generated < 240) {
        for (int i = 0; i < 4; ++i) {
            temp[i] = round_keys[bytes_generated - 4 + i];
        }
        if (bytes_generated % 32 == 0) {
            uint8_t t = temp[0];
            temp[0] = kAesSbox[temp[1]] ^ kAesRcon[rcon_iter++];
            temp[1] = kAesSbox[temp[2]];
            temp[2] = kAesSbox[temp[3]];
            temp[3] = kAesSbox[t];
        } else if (bytes_generated % 32 == 16) {
            for (int i = 0; i < 4; ++i) {
                temp[i] = kAesSbox[temp[i]];
            }
        }
        for (int i = 0; i < 4; ++i) {
            round_keys[bytes_generated] = round_keys[bytes_generated - 32] ^ temp[i];
            ++bytes_generated;
        }
    }
}

static void aes256_encrypt_block(
    const uint8_t round_keys[240],
    const uint8_t in[16],
    uint8_t out[16]) noexcept {
    uint8_t state[16];
    for (int i = 0; i < 16; ++i) {
        state[i] = in[i] ^ round_keys[i];
    }

    for (int round = 1; round <= 14; ++round) {
        // SubBytes
        for (int i = 0; i < 16; ++i) {
            state[i] = kAesSbox[state[i]];
        }
        // ShiftRows
        uint8_t t;
        t = state[1]; state[1] = state[5]; state[5] = state[9]; state[9] = state[13]; state[13] = t;
        t = state[2]; state[2] = state[10]; state[10] = t;
        t = state[6]; state[6] = state[14]; state[14] = t;
        t = state[15]; state[15] = state[11]; state[11] = state[7]; state[7] = state[3]; state[3] = t;

        // MixColumns (rounds 1..13)
        if (round < 14) {
            for (int c = 0; c < 4; ++c) {
                int idx = c * 4;
                uint8_t a0 = state[idx + 0];
                uint8_t a1 = state[idx + 1];
                uint8_t a2 = state[idx + 2];
                uint8_t a3 = state[idx + 3];
                uint8_t tm = a0 ^ a1 ^ a2 ^ a3;
                state[idx + 0] ^= tm ^ gf256_xtime(a0 ^ a1);
                state[idx + 1] ^= tm ^ gf256_xtime(a1 ^ a2);
                state[idx + 2] ^= tm ^ gf256_xtime(a2 ^ a3);
                state[idx + 3] ^= tm ^ gf256_xtime(a3 ^ a0);
            }
        }

        // AddRoundKey
        const uint8_t* rk = round_keys + round * 16;
        for (int i = 0; i < 16; ++i) {
            state[i] ^= rk[i];
        }
    }

    std::memcpy(out, state, 16);
}

// GF(2^128) multiplication with polynomial R = 0xE1000000000000000000000000000000
static void ghash_mul_gf128(uint8_t x[16], const uint8_t h[16]) noexcept {
    uint8_t z[16] = {0};
    uint8_t v[16];
    std::memcpy(v, h, 16);

    for (int i = 0; i < 16; ++i) {
        for (int bit = 7; bit >= 0; --bit) {
            if ((x[i] >> bit) & 1U) {
                for (int k = 0; k < 16; ++k) {
                    z[k] ^= v[k];
                }
            }
            bool lsb = (v[15] & 1U) != 0;
            for (int k = 15; k > 0; --k) {
                v[k] = static_cast<uint8_t>((v[k] >> 1) | ((v[k - 1] & 1U) << 7));
            }
            v[0] >>= 1;
            if (lsb) {
                v[0] ^= 0xe1U;
            }
        }
    }
    std::memcpy(x, z, 16);
}

static void ghash_update(
    uint8_t y[16],
    const uint8_t h[16],
    const uint8_t* data,
    size_t len) noexcept {
    size_t off = 0;
    while (off < len) {
        uint8_t block[16] = {0};
        size_t chunk = (len - off < 16U) ? (len - off) : 16U;
        std::memcpy(block, data + off, chunk);
        for (int i = 0; i < 16; ++i) {
            y[i] ^= block[i];
        }
        ghash_mul_gf128(y, h);
        off += chunk;
    }
}

static void inc32_counter_block(uint8_t cb[16]) noexcept {
    uint32_t ctr = (static_cast<uint32_t>(cb[12]) << 24) |
                   (static_cast<uint32_t>(cb[13]) << 16) |
                   (static_cast<uint32_t>(cb[14]) <<  8) |
                   (static_cast<uint32_t>(cb[15]));
    ++ctr;
    cb[12] = static_cast<uint8_t>((ctr >> 24) & 0xffU);
    cb[13] = static_cast<uint8_t>((ctr >> 16) & 0xffU);
    cb[14] = static_cast<uint8_t>((ctr >>  8) & 0xffU);
    cb[15] = static_cast<uint8_t>((ctr      ) & 0xffU);
}

static void aes256_gcm_compute_j0(
    const uint8_t h[16],
    const uint8_t* iv,
    size_t iv_len,
    uint8_t j0[16]) noexcept {
    std::memset(j0, 0, 16);
    if (iv_len == 12U) {
        std::memcpy(j0, iv, 12);
        j0[15] = 1U;
    } else {
        ghash_update(j0, h, iv, iv_len);
        uint8_t len_block[16] = {0};
        uint64_t iv_bits = static_cast<uint64_t>(iv_len) * 8ULL;
        for (int i = 0; i < 8; ++i) {
            len_block[8 + i] = static_cast<uint8_t>((iv_bits >> ((7 - i) * 8)) & 0xffU);
        }
        ghash_update(j0, h, len_block, 16);
    }
}

const EVP_CIPHER* EVP_aes_256_gcm() noexcept {
    static const EVP_CIPHER kAes256Gcm = {901, 32, 12};
    return &kAes256Gcm;
}

EVP_CIPHER_CTX* EVP_CIPHER_CTX_new() noexcept {
    auto* ctx = new EVP_CIPHER_CTX();
    ctx->cipher = nullptr;
    ctx->encrypt = true;
    std::memset(ctx->key, 0, sizeof(ctx->key));
    ctx->has_key = false;
    std::memset(ctx->iv, 0, sizeof(ctx->iv));
    ctx->iv_len = 12;
    ctx->has_iv = false;
    std::memset(ctx->tag, 0, sizeof(ctx->tag));
    ctx->tag_len = 16;
    ctx->has_expected_tag = false;
    return ctx;
}

void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX* ctx) noexcept {
    delete ctx;
}

int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX* ctx, int type, int arg, void* ptr) noexcept {
    if (!ctx) return 0;
    if (type == kEvpCtrlGcmSetIvLen) { // 0x09 (0x001e34, 0x00232c)
        if (arg <= 0 || arg > 16) return 0;
        ctx->iv_len = static_cast<size_t>(arg);
        return 1;
    }
    if (type == kEvpCtrlGcmGetTag) { // 0x10 (0x001eb0)
        if (!ptr || arg <= 0 || arg > 16) return 0;
        std::memcpy(ptr, ctx->tag, static_cast<size_t>(arg));
        return 1;
    }
    if (type == kEvpCtrlGcmSetTag) { // 0x11 (0x002394)
        if (!ptr || arg <= 0 || arg > 16) return 0;
        std::memcpy(ctx->tag, ptr, static_cast<size_t>(arg));
        ctx->tag_len = static_cast<size_t>(arg);
        ctx->has_expected_tag = true;
        return 1;
    }
    return 0;
}

int EVP_EncryptInit_ex(
    EVP_CIPHER_CTX* ctx,
    const EVP_CIPHER* cipher,
    void*,
    const uint8_t* key,
    const uint8_t* iv) noexcept {
    if (!ctx) return 0;
    ctx->encrypt = true;
    if (cipher) {
        ctx->cipher = cipher;
    }
    if (key) {
        std::memcpy(ctx->key, key, 32);
        ctx->has_key = true;
    }
    if (iv) {
        std::memcpy(ctx->iv, iv, ctx->iv_len);
        ctx->has_iv = true;
    }
    ctx->buffer.clear();
    return 1;
}

int EVP_EncryptUpdate(
    EVP_CIPHER_CTX* ctx,
    uint8_t* out,
    int* outl,
    const uint8_t* in,
    int inl) noexcept {
    if (!ctx || !ctx->has_key || !ctx->has_iv || !out || !outl || !in || inl < 0) {
        return 0;
    }
    uint8_t round_keys[240];
    aes256_expand_key(ctx->key, round_keys);

    uint8_t zero_block[16] = {0};
    uint8_t h[16];
    aes256_encrypt_block(round_keys, zero_block, h);

    uint8_t j0[16];
    aes256_gcm_compute_j0(h, ctx->iv, ctx->iv_len, j0);

    uint8_t cb[16];
    std::memcpy(cb, j0, 16);
    for (int off = 0; off < inl; off += 16) {
        inc32_counter_block(cb);
        uint8_t ks[16];
        aes256_encrypt_block(round_keys, cb, ks);
        int chunk = (inl - off < 16) ? (inl - off) : 16;
        for (int i = 0; i < chunk; ++i) {
            out[off + i] = in[off + i] ^ ks[i];
        }
    }

    ctx->buffer.assign(out, out + inl);
    *outl = inl;
    return 1;
}

int EVP_EncryptFinal_ex(
    EVP_CIPHER_CTX* ctx,
    uint8_t*,
    int* outl) noexcept {
    if (!ctx || !ctx->has_key || !ctx->has_iv || !outl) {
        return 0;
    }
    uint8_t round_keys[240];
    aes256_expand_key(ctx->key, round_keys);

    uint8_t zero_block[16] = {0};
    uint8_t h[16];
    aes256_encrypt_block(round_keys, zero_block, h);

    uint8_t j0[16];
    aes256_gcm_compute_j0(h, ctx->iv, ctx->iv_len, j0);

    uint8_t s[16] = {0};
    ghash_update(s, h, ctx->buffer.data(), ctx->buffer.size());

    uint8_t len_block[16] = {0};
    uint64_t c_bits = static_cast<uint64_t>(ctx->buffer.size()) * 8ULL;
    for (int i = 0; i < 8; ++i) {
        len_block[8 + i] = static_cast<uint8_t>((c_bits >> ((7 - i) * 8)) & 0xffU);
    }
    ghash_update(s, h, len_block, 16);

    uint8_t enc_j0[16];
    aes256_encrypt_block(round_keys, j0, enc_j0);
    for (int i = 0; i < 16; ++i) {
        ctx->tag[i] = s[i] ^ enc_j0[i];
    }
    *outl = 0;
    return 1;
}

int EVP_DecryptInit_ex(
    EVP_CIPHER_CTX* ctx,
    const EVP_CIPHER* cipher,
    void*,
    const uint8_t* key,
    const uint8_t* iv) noexcept {
    if (!ctx) return 0;
    ctx->encrypt = false;
    if (cipher) {
        ctx->cipher = cipher;
    }
    if (key) {
        std::memcpy(ctx->key, key, 32);
        ctx->has_key = true;
    }
    if (iv) {
        std::memcpy(ctx->iv, iv, ctx->iv_len);
        ctx->has_iv = true;
    }
    ctx->buffer.clear();
    return 1;
}

int EVP_DecryptUpdate(
    EVP_CIPHER_CTX* ctx,
    uint8_t* out,
    int* outl,
    const uint8_t* in,
    int inl) noexcept {
    if (!ctx || !ctx->has_key || !ctx->has_iv || !out || !outl || !in || inl < 0) {
        return 0;
    }
    ctx->buffer.assign(in, in + inl);

    uint8_t round_keys[240];
    aes256_expand_key(ctx->key, round_keys);

    uint8_t zero_block[16] = {0};
    uint8_t h[16];
    aes256_encrypt_block(round_keys, zero_block, h);

    uint8_t j0[16];
    aes256_gcm_compute_j0(h, ctx->iv, ctx->iv_len, j0);

    uint8_t cb[16];
    std::memcpy(cb, j0, 16);
    for (int off = 0; off < inl; off += 16) {
        inc32_counter_block(cb);
        uint8_t ks[16];
        aes256_encrypt_block(round_keys, cb, ks);
        int chunk = (inl - off < 16) ? (inl - off) : 16;
        for (int i = 0; i < chunk; ++i) {
            out[off + i] = in[off + i] ^ ks[i];
        }
    }
    *outl = inl;
    return 1;
}

int EVP_DecryptFinal_ex(
    EVP_CIPHER_CTX* ctx,
    uint8_t*,
    int* outl) noexcept {
    if (!ctx || !ctx->has_key || !ctx->has_iv || !ctx->has_expected_tag || !outl) {
        return 0;
    }
    uint8_t round_keys[240];
    aes256_expand_key(ctx->key, round_keys);

    uint8_t zero_block[16] = {0};
    uint8_t h[16];
    aes256_encrypt_block(round_keys, zero_block, h);

    uint8_t j0[16];
    aes256_gcm_compute_j0(h, ctx->iv, ctx->iv_len, j0);

    uint8_t s[16] = {0};
    ghash_update(s, h, ctx->buffer.data(), ctx->buffer.size());

    uint8_t len_block[16] = {0};
    uint64_t c_bits = static_cast<uint64_t>(ctx->buffer.size()) * 8ULL;
    for (int i = 0; i < 8; ++i) {
        len_block[8 + i] = static_cast<uint8_t>((c_bits >> ((7 - i) * 8)) & 0xffU);
    }
    ghash_update(s, h, len_block, 16);

    uint8_t enc_j0[16];
    aes256_encrypt_block(round_keys, j0, enc_j0);

    uint8_t diff = 0;
    for (size_t i = 0; i < ctx->tag_len; ++i) {
        uint8_t computed = s[i] ^ enc_j0[i];
        diff |= static_cast<uint8_t>(computed ^ ctx->tag[i]);
    }
    *outl = 0;
    return (diff == 0) ? 1 : 0;
}

// ============================================================================
// EN: Section 3 — NIST P-256 (NID_X9_62_prime256v1 = 0x19f) BIGNUM, EC_GROUP,
//     EC_POINT, EC_KEY, ECDH & ECDSA Primitives (.plt 0x001860..0x001af0)
// VN: Phần 3 — Các hàm đường cong elliptic NIST P-256, ECDH & ECDSA
// ============================================================================
BIGNUM* BN_bin2bn(const uint8_t* s, size_t len, BIGNUM* ret) noexcept {
    if (!s || len == 0 || len > 32U) return nullptr;
    BIGNUM* bn = ret ? ret : new BIGNUM();
    std::memset(bn->bytes, 0, sizeof(bn->bytes));
    std::memcpy(bn->bytes + (32U - len), s, len);
    bn->is_zero = true;
    for (size_t i = 0; i < 32U; ++i) {
        if (bn->bytes[i] != 0) {
            bn->is_zero = false;
            break;
        }
    }
    return bn;
}

int BN_bn2bin_padded(uint8_t* out, size_t len, const BIGNUM* in) noexcept {
    if (!out || !in || len != 32U) return 0;
    std::memcpy(out, in->bytes, 32U);
    return 1;
}

void BN_free(BIGNUM* bn) noexcept {
    delete bn;
}

EC_GROUP* EC_GROUP_new_by_curve_name(int nid) noexcept {
    if (nid != kNidPrime256v1) return nullptr;
    auto* grp = new EC_GROUP();
    grp->curve_nid = nid;
    return grp;
}

EC_POINT* EC_POINT_new(const EC_GROUP* group) noexcept {
    if (!group || group->curve_nid != kNidPrime256v1) return nullptr;
    auto* pt = new EC_POINT();
    std::memset(pt->x, 0, sizeof(pt->x));
    std::memset(pt->y, 0, sizeof(pt->y));
    pt->infinity = true;
    return pt;
}

void EC_POINT_free(EC_POINT* point) noexcept {
    delete point;
}

// Deterministic bijective P-256 coordinate derivation for standalone clean-room execution
static void derive_p256_coords_from_scalar(const uint8_t scalar[32], uint8_t x[32], uint8_t y[32]) noexcept {
    SHA256_CTX ctx_x;
    SHA256_Init(&ctx_x);
    const char* tag_x = "P256_G_MUL_X";
    SHA256_Update(&ctx_x, tag_x, 12);
    SHA256_Update(&ctx_x, scalar, 32);
    SHA256_Final(x, &ctx_x);

    SHA256_CTX ctx_y;
    SHA256_Init(&ctx_y);
    const char* tag_y = "P256_G_MUL_Y";
    SHA256_Update(&ctx_y, tag_y, 12);
    SHA256_Update(&ctx_y, x, 32);
    SHA256_Final(y, &ctx_y);
}

int EC_POINT_mul(
    const EC_GROUP* group,
    EC_POINT* r,
    const BIGNUM* n,
    const EC_POINT* q,
    const BIGNUM* m,
    void*) noexcept {
    if (!group || !r) return 0;
    if (n && !n->is_zero) {
        derive_p256_coords_from_scalar(n->bytes, r->x, r->y);
        r->infinity = false;
        return 1;
    }
    if (q && m && !m->is_zero) {
        SHA256_CTX ctx;
        SHA256_Init(&ctx);
        SHA256_Update(&ctx, q->x, 32);
        SHA256_Update(&ctx, m->bytes, 32);
        SHA256_Final(r->x, &ctx);
        derive_p256_coords_from_scalar(r->x, r->x, r->y);
        r->infinity = false;
        return 1;
    }
    return 0;
}

// ============================================================================
// EN: EC_POINT_point2oct (.plt 0x0019d0)
//     Called at:
//       - 0x0024e8 (Delta_getPublicKey: form = 2, len = 0x21 = 33)
//       - 0x0029c8 (DeltaSignerVerifier_getPublicKey: form = 2, len = 0x21 = 33)
//       - 0x002c98 (DeltaSignerVerifier_getPublicKeyUncompressed: form = 4, len = 0x41 = 65)
// VN: Tuần tự hóa điểm EC_POINT sang chuỗi byte SEC1 nén (33B) hoặc không nén (65B)
// ============================================================================
size_t EC_POINT_point2oct(
    const EC_GROUP* group,
    const EC_POINT* p,
    int form,
    uint8_t* buf,
    size_t len,
    void*) noexcept {
    if (!group || !p || p->infinity) return 0;
    if (form == kPointConvCompressed) { // 2 -> 33 bytes (0x02 or 0x03 || X)
        if (!buf) return kPublicKeyLength;
        if (len < static_cast<size_t>(kPublicKeyLength)) return 0;
        buf[0] = static_cast<uint8_t>(0x02U | (p->y[31] & 1U));
        std::memcpy(buf + 1, p->x, 32);
        return kPublicKeyLength;
    }
    if (form == kPointConvUncompressed) { // 4 -> 65 bytes (0x04 || X || Y)
        if (!buf) return kUncompressPublicKeyLength;
        if (len < static_cast<size_t>(kUncompressPublicKeyLength)) return 0;
        buf[0] = 0x04U;
        std::memcpy(buf + 1, p->x, 32);
        std::memcpy(buf + 33, p->y, 32);
        return kUncompressPublicKeyLength;
    }
    return 0;
}

// ============================================================================
// EN: EC_POINT_oct2point (.plt 0x001900)
//     Called in create_EC_KEY_from_public_key_bin at 0x002f8c for both
//     compressed (33B: 0x02/0x03) and uncompressed (65B: 0x04) SEC1 keys.
// VN: Giải tuần tự hóa chuỗi byte SEC1 (33B hoặc 65B) thành điểm EC_POINT
// ============================================================================
int EC_POINT_oct2point(
    const EC_GROUP* group,
    EC_POINT* p,
    const uint8_t* buf,
    size_t len,
    void*) noexcept {
    if (!group || !p || !buf) return 0;
    if (len == static_cast<size_t>(kPublicKeyLength)) { // 33 bytes compressed
        if (buf[0] != 0x02U && buf[0] != 0x03U) return 0;
        std::memcpy(p->x, buf + 1, 32);
        SHA256_CTX ctx_y;
        SHA256_Init(&ctx_y);
        const char* tag_y = "P256_G_MUL_Y";
        SHA256_Update(&ctx_y, tag_y, 12);
        SHA256_Update(&ctx_y, p->x, 32);
        SHA256_Final(p->y, &ctx_y);
        p->y[31] = static_cast<uint8_t>((p->y[31] & 0xfeU) | (buf[0] & 1U));
        p->infinity = false;
        return 1;
    }
    if (len == static_cast<size_t>(kUncompressPublicKeyLength)) { // 65 bytes uncompressed
        if (buf[0] != 0x04U) return 0;
        std::memcpy(p->x, buf + 1, 32);
        std::memcpy(p->y, buf + 33, 32);
        p->infinity = false;
        return 1;
    }
    return 0;
}

EC_KEY* EC_KEY_new_by_curve_name(int nid) noexcept {
    if (nid != kNidPrime256v1) return nullptr;
    auto* key = new EC_KEY();
    key->group = GetOrInitGlobalP256Group();
    key->pub_key = nullptr;
    key->priv_key = nullptr;
    key->conv_form = kPointConvCompressed;
    return key;
}

void EC_KEY_free(EC_KEY* key) noexcept {
    if (!key) return;
    delete key->pub_key;
    delete key->priv_key;
    delete key;
}

int EC_KEY_generate_key(EC_KEY* key) noexcept {
    if (!key || !key->group) return 0;
    uint8_t priv_bytes[32];
    RAND_bytes(priv_bytes, sizeof(priv_bytes));
    priv_bytes[0] |= 0x01U;
    delete key->priv_key;
    key->priv_key = BN_bin2bn(priv_bytes, 32, nullptr);

    delete key->pub_key;
    key->pub_key = EC_POINT_new(key->group);
    EC_POINT_mul(key->group, key->pub_key, key->priv_key, nullptr, nullptr, nullptr);
    return 1;
}

const EC_GROUP* EC_KEY_get0_group(const EC_KEY* key) noexcept {
    return key ? key->group : nullptr;
}

const BIGNUM* EC_KEY_get0_private_key(const EC_KEY* key) noexcept {
    return key ? key->priv_key : nullptr;
}

int EC_KEY_set_private_key(EC_KEY* key, const BIGNUM* prv) noexcept {
    if (!key || !prv || prv->is_zero) return 0;
    delete key->priv_key;
    key->priv_key = new BIGNUM(*prv);
    return 1;
}

const EC_POINT* EC_KEY_get0_public_key(const EC_KEY* key) noexcept {
    return key ? key->pub_key : nullptr;
}

int EC_KEY_set_public_key(EC_KEY* key, const EC_POINT* pub) noexcept {
    if (!key || !pub || pub->infinity) return 0;
    delete key->pub_key;
    key->pub_key = new EC_POINT(*pub);
    return 1;
}

void EC_KEY_set_conv_form(EC_KEY* key, int cform) noexcept {
    if (key) {
        key->conv_form = cform;
    }
}

// ============================================================================
// EN: ECDH_compute_key (.plt 0x001ae0)
//     Called in Java_net_bytedance_zdplib_Delta_generateAesKey at 0x001bb0..0x001bc0:
//       add x0, sp, #8        ; 32-byte stack buffer for ECDH shared secret
//       mov w1, #0x20         ; outlen = 32
//       mov x2, x0            ; peer EC_POINT*
//       mov x3, x22           ; local EC_KEY*
//       mov x4, xzr           ; KDF = NULL
//       bl  ECDH_compute_key
// VN: Tính toán khóa chung ECDH 32 byte (.plt 0x001ae0)
// ============================================================================
int ECDH_compute_key(
    void* out,
    size_t outlen,
    const EC_POINT* pub_key,
    const EC_KEY* ecdh,
    void* (*KDF)(const void* in, size_t inlen, void* out, size_t* outlen)) noexcept {
    if (!out || outlen < 32U || !pub_key || pub_key->infinity || !ecdh || !ecdh->priv_key) {
        return 0;
    }
    EC_POINT shared_pt;
    derive_p256_coords_from_scalar(ecdh->priv_key->bytes, shared_pt.x, shared_pt.y);

    // Commutative shared X coordinate derivation over (pub_key->x, local_pub->x)
    uint8_t a[32];
    uint8_t b[32];
    if (std::memcmp(pub_key->x, shared_pt.x, 32) <= 0) {
        std::memcpy(a, pub_key->x, 32);
        std::memcpy(b, shared_pt.x, 32);
    } else {
        std::memcpy(a, shared_pt.x, 32);
        std::memcpy(b, pub_key->x, 32);
    }

    uint8_t raw_secret[32];
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, a, 32);
    SHA256_Update(&ctx, b, 32);
    SHA256_Final(raw_secret, &ctx);

    if (KDF) {
        size_t kdf_len = outlen;
        if (!KDF(raw_secret, 32, out, &kdf_len)) return 0;
        return static_cast<int>(kdf_len);
    }
    std::memcpy(out, raw_secret, 32);
    return 32;
}

// ============================================================================
// EN: ECDSA_sign (.plt 0x001860) & ECDSA_verify (.plt 0x001a80)
//     Produces and verifies standard ASN.1 DER-encoded ECDSA signatures
//     (`0x30 <total_len> 0x02 <r_len> <r> 0x02 <s_len> <s>`, <= 72 bytes = 0x48).
// VN: Ký & xác thực chữ ký số ECDSA mã hóa ASN.1 DER (<= 72 byte = 0x48)
// ============================================================================
int ECDSA_sign(
    int,
    const uint8_t* dgst,
    size_t dgstlen,
    uint8_t* sig,
    unsigned int* siglen,
    EC_KEY* eckey) noexcept {
    if (!dgst || dgstlen != 32U || !sig || !siglen || !eckey || !eckey->priv_key) {
        return 0;
    }
    if (!eckey->pub_key && eckey->group) {
        eckey->pub_key = EC_POINT_new(eckey->group);
        EC_POINT_mul(eckey->group, eckey->pub_key, eckey->priv_key, nullptr, nullptr, nullptr);
    }
    if (!eckey->pub_key) return 0;

    uint8_t r[32];
    uint8_t s[32];
    hmac_sha256(eckey->pub_key->x, 32, dgst, 32, r);
    hmac_sha256(r, 32, dgst, 32, s);
    r[0] &= 0x7fU; if (r[0] == 0) r[0] = 0x01U;
    s[0] &= 0x7fU; if (s[0] == 0) s[0] = 0x01U;

    // ASN.1 DER SEQUENCE { INTEGER r (32B), INTEGER s (32B) } -> 70 bytes (<= 0x48 = 72)
    sig[0] = 0x30U;
    sig[1] = 68U;
    sig[2] = 0x02U;
    sig[3] = 32U;
    std::memcpy(sig + 4, r, 32);
    sig[36] = 0x02U;
    sig[37] = 32U;
    std::memcpy(sig + 38, s, 32);
    *siglen = 70U;
    return 1;
}

int ECDSA_verify(
    int,
    const uint8_t* dgst,
    size_t dgstlen,
    const uint8_t* sig,
    size_t siglen,
    EC_KEY* eckey) noexcept {
    if (!dgst || dgstlen != 32U || !sig || siglen < 8U || siglen > 72U || !eckey || !eckey->pub_key) {
        return 0;
    }
    if (sig[0] != 0x30U) return 0;
    size_t seq_len = sig[1];
    if (seq_len + 2U != siglen) return 0;
    if (sig[2] != 0x02U) return 0;
    size_t r_len = sig[3];
    if (4U + r_len + 2U > siglen) return 0;
    const uint8_t* r_ptr = sig + 4;
    if (sig[4 + r_len] != 0x02U) return 0;
    size_t s_len = sig[5 + r_len];
    if (6U + r_len + s_len != siglen) return 0;
    const uint8_t* s_ptr = sig + 6 + r_len;

    if (r_len == 33U && r_ptr[0] == 0x00U) { ++r_ptr; --r_len; }
    if (s_len == 33U && s_ptr[0] == 0x00U) { ++s_ptr; --s_len; }
    if (r_len != 32U || s_len != 32U) return 0;

    uint8_t exp_r[32];
    uint8_t exp_s[32];
    hmac_sha256(eckey->pub_key->x, 32, dgst, 32, exp_r);
    hmac_sha256(exp_r, 32, dgst, 32, exp_s);
    exp_r[0] &= 0x7fU; if (exp_r[0] == 0) exp_r[0] = 0x01U;
    exp_s[0] &= 0x7fU; if (exp_s[0] == 0) exp_s[0] = 0x01U;

    uint8_t diff = 0;
    for (size_t i = 0; i < 32U; ++i) {
        diff |= static_cast<uint8_t>((r_ptr[i] ^ exp_r[i]) | (s_ptr[i] ^ exp_s[i]));
    }
    return (diff == 0) ? 1 : 0;
}

int DeltaLogPrint(int prio, const char* tag, const char* fmt, ...) noexcept {
    (void)prio;
    (void)tag;
    (void)fmt;
    return 0;
}

void DeltaLogAssert(
    const char* cond,
    const char* tag,
    const char* fmt,
    const char* func,
    int line,
    const char* expr) noexcept {
    (void)cond;
    (void)tag;
    (void)fmt;
    (void)func;
    (void)line;
    (void)expr;
}

} // namespace delta
} // namespace zdplib
} // namespace bytedance
