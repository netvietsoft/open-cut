// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_hash_hmac.cpp
// Description: Full Cleanroom C++ Implementation of FIPS 180-4 SHA-256/512,
//              RFC 2104 HMAC, and RFC 5869 HKDF matching AArch64 opcodes.
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#include "ttcrypto_hash_hmac.h"
#include <string.h>

// ===================================================================================
// 1. BIT ROTATION & ENDIAN HELPERS
// Các toán tử dịch vòng bit và chuyển đổi thứ tự byte Big-Endian
// ===================================================================================

static inline uint32_t rotr32(uint32_t x, uint32_t n) {
    return (x >> n) | (x << (32u - n));
}

static inline uint64_t rotr64(uint64_t x, uint32_t n) {
    return (x >> n) | (x << (64u - n));
}

static inline uint32_t load_be32(const uint8_t* p) {
    return ((uint32_t)p[0] << 24) |
           ((uint32_t)p[1] << 16) |
           ((uint32_t)p[2] << 8)  |
           ((uint32_t)p[3]);
}

static inline void store_be32(uint8_t* p, uint32_t v) {
    p[0] = (uint8_t)(v >> 24);
    p[1] = (uint8_t)(v >> 16);
    p[2] = (uint8_t)(v >> 8);
    p[3] = (uint8_t)(v);
}

static inline uint64_t load_be64(const uint8_t* p) {
    return ((uint64_t)p[0] << 56) |
           ((uint64_t)p[1] << 48) |
           ((uint64_t)p[2] << 40) |
           ((uint64_t)p[3] << 32) |
           ((uint64_t)p[4] << 24) |
           ((uint64_t)p[5] << 16) |
           ((uint64_t)p[6] << 8)  |
           ((uint64_t)p[7]);
}

static inline void store_be64(uint8_t* p, uint64_t v) {
    p[0] = (uint8_t)(v >> 56);
    p[1] = (uint8_t)(v >> 48);
    p[2] = (uint8_t)(v >> 40);
    p[3] = (uint8_t)(v >> 32);
    p[4] = (uint8_t)(v >> 24);
    p[5] = (uint8_t)(v >> 16);
    p[6] = (uint8_t)(v >> 8);
    p[7] = (uint8_t)(v);
}

// ===================================================================================
// 2. SHA-256 IMPLEMENTATION (AArch64 @ 0x0be370..0x0be5c0, block transform @ 0x0c9740)
// Hiện thực hóa thuật toán băm SHA-256 chuẩn FIPS 180-4
// ===================================================================================

// Bảng 64 hằng số căn bậc ba số nguyên tố K[0..63] của SHA-256 (tại .rodata 0x0e1000)
static const uint32_t kSha256K[64] = {
    0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u,
    0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u,
    0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u,
    0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u,
    0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu,
    0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau,
    0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u,
    0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u,
    0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcU, 0x53380d13u,
    0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u,
    0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u,
    0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u,
    0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u,
    0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u,
    0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u,
    0x90befffaU, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u
};

/**
 * @brief Initializes a SHA-224 context (28-byte digest).
 * Khởi tạo ngữ cảnh băm SHA-224 (md_len = 28).
 */
int SHA224_Init(SHA256_CTX* c) {
    if (!c) return 0;
    memset(c, 0, sizeof(SHA256_CTX));
    c->h[0] = 0xc1059ed8u;
    c->h[1] = 0x367cd507u;
    c->h[2] = 0x3070dd17u;
    c->h[3] = 0xf70e5939u;
    c->h[4] = 0xffc00b31u;
    c->h[5] = 0x68581511u;
    c->h[6] = 0x64f98fa7u;
    c->h[7] = 0xbefa4fa4u;
    c->md_len = 28u;
    return 1;
}

/**
 * @brief Initializes a SHA-256 context matching AArch64 opcode at 0x0be370.
 * Opcode ARM64:
 *   0x0be37c: mov w2, #0x70 ; bl memset (112 bytes)
 *   0x0be38c: ldr q0, [x8, #0xc0] ; ldr q1, [x9, #0xd0] (H0..H7 from .rodata 0x0e10c0)
 *   0x0be394: mov w8, #0x20 ; str w8, [x19, #0x6c] (md_len = 32)
 */
int SHA256_Init(SHA256_CTX* c) {
    if (!c) return 0;
    memset(c, 0, sizeof(SHA256_CTX)); // 0x70 = 112 bytes
    c->h[0] = 0x6a09e667u;
    c->h[1] = 0xbb67ae85u;
    c->h[2] = 0x3c6ef372u;
    c->h[3] = 0xa54ff53au;
    c->h[4] = 0x510e527fu;
    c->h[5] = 0x9b05688cu;
    c->h[6] = 0x1f83d9abu;
    c->h[7] = 0x5be0cd19u;
    c->md_len = 0x20u; // 32 bytes at offset +0x6c
    return 1;
}

/**
 * @brief Compresses a single 64-byte message block into SHA256_CTX state (0x0be408 -> 0x0c9740).
 * Thực hiện 64 vòng nén tuyến tính và phi tuyến tính SHA-256 trên 1 khối 512-bit.
 */
void SHA256_Transform(SHA256_CTX* c, const uint8_t* data) {
    if (!c || !data) return;

    uint32_t W[64];
    for (int i = 0; i < 16; ++i) {
        W[i] = load_be32(data + i * 4);
    }
    for (int i = 16; i < 64; ++i) {
        uint32_t s0 = rotr32(W[i - 15], 7) ^ rotr32(W[i - 15], 18) ^ (W[i - 15] >> 3);
        uint32_t s1 = rotr32(W[i - 2], 17) ^ rotr32(W[i - 2], 19) ^ (W[i - 2] >> 10);
        W[i] = W[i - 16] + s0 + W[i - 7] + s1;
    }

    uint32_t a = c->h[0];
    uint32_t b = c->h[1];
    uint32_t d = c->h[3];
    uint32_t e = c->h[4];
    uint32_t f = c->h[5];
    uint32_t g = c->h[6];
    uint32_t h = c->h[7];
    uint32_t cc = c->h[2];

    for (int i = 0; i < 64; ++i) {
        uint32_t S1 = rotr32(e, 6) ^ rotr32(e, 11) ^ rotr32(e, 25);
        uint32_t ch = (e & f) ^ ((~e) & g);
        uint32_t temp1 = h + S1 + ch + kSha256K[i] + W[i];
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

/**
 * @brief Feeds arbitrary-length byte stream into SHA256_CTX.
 * Nạp luồng dữ liệu độ dài bất kỳ vào bộ đệm khối 64-byte và kích hoạt nén khi đầy.
 */
int SHA256_Update(SHA256_CTX* c, const void* data_ptr, size_t len) {
    if (!c) return 0;
    if (len == 0) return 1;
    if (!data_ptr) return 0;

    const uint8_t* data = (const uint8_t*)data_ptr;
    uint32_t l = c->Nl + ((uint32_t)len << 3);
    if (l < c->Nl) {
        c->Nh++;
    }
    c->Nh += (uint32_t)(len >> 29);
    c->Nl = l;

    size_t n = c->num;
    if (n > 0) {
        size_t todo = 64u - n;
        if (len < todo) {
            memcpy(c->data + n, data, len);
            c->num += (uint32_t)len;
            return 1;
        }
        memcpy(c->data + n, data, todo);
        SHA256_Transform(c, c->data);
        c->num = 0;
        data += todo;
        len -= todo;
    }

    while (len >= 64u) {
        SHA256_Transform(c, data);
        data += 64u;
        len -= 64u;
    }

    if (len > 0) {
        memcpy(c->data, data, len);
        c->num = (uint32_t)len;
    }
    return 1;
}

/**
 * @brief Pads the final message block with 0x80 and 64-bit big-endian bit length, outputting digest.
 * Đệm bit 1 (0x80) và chiều dài 64-bit Big-Endian vào cuối thông điệp, xuất mã băm SHA-256/224.
 */
int SHA256_Final(uint8_t* md, SHA256_CTX* c) {
    if (!md || !c) return 0;

    size_t n = c->num;
    c->data[n++] = 0x80u;

    if (n > 56u) {
        memset(c->data + n, 0, 64u - n);
        SHA256_Transform(c, c->data);
        n = 0;
    }
    memset(c->data + n, 0, 56u - n);
    store_be32(c->data + 56, c->Nh);
    store_be32(c->data + 60, c->Nl);
    SHA256_Transform(c, c->data);

    uint32_t words = (c->md_len == 28u) ? 7u : 8u;
    for (uint32_t i = 0; i < words; ++i) {
        store_be32(md + i * 4, c->h[i]);
    }
    memset(c, 0, sizeof(SHA256_CTX));
    return 1;
}

/**
 * @brief One-shot SHA-256 digest computation.
 * Tính nhanh mã băm SHA-256(d[0..n-1]) trong một lần gọi.
 */
uint8_t* SHA256(const uint8_t* d, size_t n, uint8_t* md) {
    static uint8_t s_static_md[32];
    uint8_t* out = md ? md : s_static_md;
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, d, n);
    SHA256_Final(out, &ctx);
    return out;
}

// ===================================================================================
// 3. SHA-512 IMPLEMENTATION (FIPS 180-4 64-bit words, 80 rounds)
// Hiện thực hóa thuật toán băm SHA-384 / SHA-512 (80 vòng lặp 64-bit)
// ===================================================================================

static const uint64_t kSha512K[80] = {
    0x428a2f98d728ae22ULL, 0x7137449123ef65cdULL, 0xb5c0fbcfec4d3b2fULL, 0xe9b5dba58189dbbcULL,
    0x3956c25bf348b538ULL, 0x59f111f1b605d019ULL, 0x923f82a4af194f9bULL, 0xab1c5ed5da6d8118ULL,
    0xd807aa98a3030242ULL, 0x12835b0145706fbeULL, 0x243185be4ee4b28cULL, 0x550c7dc3d5ffb4e2ULL,
    0x72be5d74f27b896fULL, 0x80deb1fe3b1696b1ULL, 0x9bdc06a725c71235ULL, 0xc19bf174cf692694ULL,
    0xe49b69c19ef14ad2ULL, 0xefbe4786384f25e3ULL, 0x0fc19dc68b8cd5b5ULL, 0x240ca1cc77ac9c65ULL,
    0x2de92c6f592b0275ULL, 0x4a7484aa6ea6e483ULL, 0x5cb0a9dcbd41fbd4ULL, 0x76f988da831153b5ULL,
    0x983e5152ee66dfabULL, 0xa831c66d2db43210ULL, 0xb00327c898fb213fULL, 0xbf597fc7beef0ee4ULL,
    0xc6e00bf33da88fc2ULL, 0xd5a79147930aa725ULL, 0x06ca6351e003826fULL, 0x142929670a0e6e70ULL,
    0x27b70a8546d22ffcULL, 0x2e1b21385c26c926ULL, 0x4d2c6dfc5ac42aedULL, 0x53380d139d95b3dfULL,
    0x650a73548baf63deULL, 0x766a0abb3c77b2a8ULL, 0x81c2c92e47edaee6ULL, 0x92722c851482353bULL,
    0xa2bfe8a14cf10364ULL, 0xa81a664bbc423001ULL, 0xc24b8b70d0f89791ULL, 0xc76c51a30654be30ULL,
    0xd192e819d6ef5218ULL, 0xd69906245565a910ULL, 0xf40e35855771202aULL, 0x106aa07032bbd1b8ULL,
    0x19a4c116b8d2d0c8ULL, 0x1e376c085141ab53ULL, 0x2748774cdf8eeb99ULL, 0x34b0bcb5e19b48a8ULL,
    0x391c0cb3c5c95a63ULL, 0x4ed8aa4ae3418acbULL, 0x5b9cca4f7763e373ULL, 0x682e6ff3d6b2b8a3ULL,
    0x748f82ee5defb2fcULL, 0x78a5636f43172f60ULL, 0x84c87814a1f0ab72ULL, 0x8cc702081a6439ecULL,
    0x90befffa23631e28ULL, 0xa4506cebde82bde9ULL, 0xbef9a3f7b2c67915ULL, 0xc67178f2e372532bULL,
    0xca273eceea26619cULL, 0xd186b8c721c0c207ULL, 0xeada7dd6cde0eb1eULL, 0xf57d4f7fee6ed178ULL,
    0x06f067aa72176fbaULL, 0x0a637dc5a2c898a6ULL, 0x113f9804bef90daeULL, 0x1b710b35131c471bULL,
    0x28db77f523047d84ULL, 0x32caab7b40c72493ULL, 0x3c9ebe0a15c9bebcULL, 0x431d67c49c100d4cULL,
    0x4cc5d4becb3e42b6ULL, 0x597f299cfc657e2aULL, 0x5fcb6fab3ad6faecULL, 0x6c44198c4a475817ULL
};

int SHA384_Init(SHA512_CTX* c) {
    if (!c) return 0;
    memset(c, 0, sizeof(SHA512_CTX));
    c->h[0] = 0xcbbb9d5dc1059ed8ULL;
    c->h[1] = 0x629a292a367cd507ULL;
    c->h[2] = 0x9159015a3070dd17ULL;
    c->h[3] = 0x152fecd8f70e5939ULL;
    c->h[4] = 0x67332667ffc00b31ULL;
    c->h[5] = 0x8eb44a8768581511ULL;
    c->h[6] = 0xdb0c2e0d64f98fa7ULL;
    c->h[7] = 0x47b5481dbefa4fa4ULL;
    c->md_len = 48u;
    return 1;
}

int SHA512_Init(SHA512_CTX* c) {
    if (!c) return 0;
    memset(c, 0, sizeof(SHA512_CTX));
    c->h[0] = 0x6a09e667f3bcc908ULL;
    c->h[1] = 0xbb67ae8584caa73bULL;
    c->h[2] = 0x3c6ef372fe94f82bULL;
    c->h[3] = 0xa54ff53a5f1d36f1ULL;
    c->h[4] = 0x510e527fade682d1ULL;
    c->h[5] = 0x9b05688c2b3e6c1fULL;
    c->h[6] = 0x1f83d9abfb41bd6bULL;
    c->h[7] = 0x5be0cd19137e2179ULL;
    c->md_len = 64u;
    return 1;
}

void SHA512_Transform(SHA512_CTX* c, const uint8_t* data) {
    if (!c || !data) return;

    uint64_t W[80];
    for (int i = 0; i < 16; ++i) {
        W[i] = load_be64(data + i * 8);
    }
    for (int i = 16; i < 80; ++i) {
        uint64_t s0 = rotr64(W[i - 15], 1) ^ rotr64(W[i - 15], 8) ^ (W[i - 15] >> 7);
        uint64_t s1 = rotr64(W[i - 2], 19) ^ rotr64(W[i - 2], 61) ^ (W[i - 2] >> 6);
        W[i] = W[i - 16] + s0 + W[i - 7] + s1;
    }

    uint64_t a = c->h[0];
    uint64_t b = c->h[1];
    uint64_t cc = c->h[2];
    uint64_t d = c->h[3];
    uint64_t e = c->h[4];
    uint64_t f = c->h[5];
    uint64_t g = c->h[6];
    uint64_t h = c->h[7];

    for (int i = 0; i < 80; ++i) {
        uint64_t S1 = rotr64(e, 14) ^ rotr64(e, 18) ^ rotr64(e, 41);
        uint64_t ch = (e & f) ^ ((~e) & g);
        uint64_t temp1 = h + S1 + ch + kSha512K[i] + W[i];
        uint64_t S0 = rotr64(a, 28) ^ rotr64(a, 34) ^ rotr64(a, 39);
        uint64_t maj = (a & b) ^ (a & cc) ^ (b & cc);
        uint64_t temp2 = S0 + maj;

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

int SHA512_Update(SHA512_CTX* c, const void* data_ptr, size_t len) {
    if (!c) return 0;
    if (len == 0) return 1;
    if (!data_ptr) return 0;

    const uint8_t* data = (const uint8_t*)data_ptr;
    uint64_t l = c->Nl + ((uint64_t)len << 3);
    if (l < c->Nl) {
        c->Nh++;
    }
    c->Nh += (uint64_t)(len >> 61);
    c->Nl = l;

    size_t n = c->num;
    if (n > 0) {
        size_t todo = 128u - n;
        if (len < todo) {
            memcpy(c->data + n, data, len);
            c->num += (uint32_t)len;
            return 1;
        }
        memcpy(c->data + n, data, todo);
        SHA512_Transform(c, c->data);
        c->num = 0;
        data += todo;
        len -= todo;
    }

    while (len >= 128u) {
        SHA512_Transform(c, data);
        data += 128u;
        len -= 128u;
    }

    if (len > 0) {
        memcpy(c->data, data, len);
        c->num = (uint32_t)len;
    }
    return 1;
}

int SHA512_Final(uint8_t* md, SHA512_CTX* c) {
    if (!md || !c) return 0;

    size_t n = c->num;
    c->data[n++] = 0x80u;

    if (n > 112u) {
        memset(c->data + n, 0, 128u - n);
        SHA512_Transform(c, c->data);
        n = 0;
    }
    memset(c->data + n, 0, 112u - n);
    store_be64(c->data + 112, c->Nh);
    store_be64(c->data + 120, c->Nl);
    SHA512_Transform(c, c->data);

    uint32_t words = (c->md_len == 48u) ? 6u : 8u;
    for (uint32_t i = 0; i < words; ++i) {
        store_be64(md + i * 8, c->h[i]);
    }
    memset(c, 0, sizeof(SHA512_CTX));
    return 1;
}

uint8_t* SHA512(const uint8_t* d, size_t n, uint8_t* md) {
    static uint8_t s_static_md512[64];
    uint8_t* out = md ? md : s_static_md512;
    SHA512_CTX ctx;
    SHA512_Init(&ctx);
    SHA512_Update(&ctx, d, n);
    SHA512_Final(out, &ctx);
    return out;
}

// ===================================================================================
// 4. HMAC-SHA256 IMPLEMENTATION (RFC 2104, AArch64 @ 0x0b6f6c & 0x0b7084)
// Hiện thực hóa mã xác thực thông điệp HMAC với ipad = 0x36 và opad = 0x5c
// ===================================================================================

void HMAC_CTX_init(HMAC_CTX* ctx) {
    if (!ctx) return;
    memset(ctx, 0, sizeof(HMAC_CTX));
}

void HMAC_CTX_cleanup(HMAC_CTX* ctx) {
    if (!ctx) return;
    memset(ctx, 0, sizeof(HMAC_CTX));
}

/**
 * @brief Initializes HMAC_CTX with secret key (0x0b7084).
 * Nếu key_len > 64 bytes, khóa được rút gọn bằng SHA-256 trước khi XOR với 0x36 (ipad) và 0x5c (opad).
 */
int HMAC_Init_ex(HMAC_CTX* ctx, const void* key, size_t key_len, const void* md, void* impl) {
    (void)md;
    (void)impl;
    if (!ctx) return 0;

    if (key != NULL) {
        uint8_t key_block[64];
        memset(key_block, 0, sizeof(key_block));

        if (key_len > 64u) {
            SHA256((const uint8_t*)key, key_len, key_block);
            ctx->key_len = 32u;
        } else if (key_len > 0) {
            memcpy(key_block, key, key_len);
            ctx->key_len = (uint32_t)key_len;
        } else {
            ctx->key_len = 0u;
        }

        uint8_t pad[64];
        for (size_t i = 0; i < 64u; ++i) {
            pad[i] = (uint8_t)(key_block[i] ^ 0x36u);
        }
        SHA256_Init(&ctx->i_ctx);
        SHA256_Update(&ctx->i_ctx, pad, 64u);

        for (size_t i = 0; i < 64u; ++i) {
            pad[i] = (uint8_t)(key_block[i] ^ 0x5cu);
        }
        SHA256_Init(&ctx->o_ctx);
        SHA256_Update(&ctx->o_ctx, pad, 64u);

        memset(key_block, 0, sizeof(key_block));
        memset(pad, 0, sizeof(pad));
        ctx->initialized = true;
    } else if (!ctx->initialized) {
        return 0;
    }

    memcpy(&ctx->md_ctx, &ctx->i_ctx, sizeof(SHA256_CTX));
    return 1;
}

int HMAC_Update(HMAC_CTX* ctx, const uint8_t* data, size_t data_len) {
    if (!ctx || !ctx->initialized) return 0;
    return SHA256_Update(&ctx->md_ctx, data, data_len);
}

int HMAC_Final(HMAC_CTX* ctx, uint8_t* out, unsigned int* out_len) {
    if (!ctx || !ctx->initialized || !out) return 0;

    uint8_t inner_digest[32];
    if (!SHA256_Final(inner_digest, &ctx->md_ctx)) {
        return 0;
    }
    memcpy(&ctx->md_ctx, &ctx->o_ctx, sizeof(SHA256_CTX));
    if (!SHA256_Update(&ctx->md_ctx, inner_digest, 32u)) {
        return 0;
    }
    if (!SHA256_Final(out, &ctx->md_ctx)) {
        return 0;
    }
    if (out_len) {
        *out_len = 32u;
    }
    memset(inner_digest, 0, sizeof(inner_digest));
    return 1;
}

/**
 * @brief One-shot HMAC-SHA256 computation matching AArch64 opcode at 0x0b6f6c.
 * Tính trực tiếp HMAC(K, m) = H((K' ^ opad) || H((K' ^ ipad) || m)).
 */
uint8_t* HMAC(const void* evp_md, const void* key, int key_len,
              const uint8_t* d, size_t n, uint8_t* md, unsigned int* md_len) {
    static uint8_t s_static_hmac[32];
    if (key_len < 0) return NULL;
    uint8_t* out = md ? md : s_static_hmac;

    HMAC_CTX ctx;
    HMAC_CTX_init(&ctx);
    if (!HMAC_Init_ex(&ctx, key, (size_t)key_len, evp_md, NULL) ||
        !HMAC_Update(&ctx, d, n) ||
        !HMAC_Final(&ctx, out, md_len)) {
        HMAC_CTX_cleanup(&ctx);
        return NULL;
    }
    HMAC_CTX_cleanup(&ctx);
    return out;
}

// ===================================================================================
// 5. HKDF KEY DERIVATION IMPLEMENTATION (RFC 5869, AArch64 @ 0x070ea8 & 0x070f34)
// Hiện thực hóa thuật toán dẫn xuất khóa HKDF-Extract và HKDF-Expand dùng trong TLS 1.3 / QUIC
// ===================================================================================

/**
 * @brief HKDF-Extract(salt, IKM) -> PRK (32 bytes) matching 0x070ea8.
 * Nếu salt == NULL hoặc salt_len == 0, sử dụng chuỗi 32 byte 0x00 làm salt mặc định theo RFC 5869.
 */
int HKDF_extract(uint8_t* out_key, size_t* out_len, const void* digest,
                 const uint8_t* secret, size_t secret_len,
                 const uint8_t* salt, size_t salt_len) {
    if (!out_key || !out_len) return 0;

    uint8_t zero_salt[32];
    if (!salt || salt_len == 0) {
        memset(zero_salt, 0, sizeof(zero_salt));
        salt = zero_salt;
        salt_len = sizeof(zero_salt);
    }

    unsigned int len = 0;
    if (!HMAC(digest, salt, (int)salt_len, secret, secret_len, out_key, &len)) {
        return 0;
    }
    *out_len = (size_t)len;
    return 1;
}

/**
 * @brief HKDF-Expand(PRK, info, L) -> OKM matching AArch64 opcode at 0x070f34.
 * Công thức lặp: T(i) = HMAC-Hash(PRK, T(i-1) || info || i) với i = 1..ceil(L / HashLen).
 * Kiểm tra giới hạn: L <= 255 * HashLen (8160 bytes cho SHA-256).
 */
int HKDF_expand(uint8_t* out_key, size_t out_len, const void* digest,
                const uint8_t* prk, size_t prk_len,
                const uint8_t* info, size_t info_len) {
    const size_t hash_len = 32u;
    if (!out_key || !prk || prk_len < hash_len) return 0;

    size_t n = (out_len + hash_len - 1u) / hash_len;
    if (out_len == 0 || n > 255u) {
        return 0; // RFC 5869 Section 2.3: L cannot exceed 255 * HashLen
    }

    uint8_t prev[32];
    size_t done = 0;
    HMAC_CTX hmac;
    HMAC_CTX_init(&hmac);

    for (size_t i = 1; i <= n; ++i) {
        uint8_t ctr = (uint8_t)i;
        if (!HMAC_Init_ex(&hmac, prk, prk_len, digest, NULL)) {
            HMAC_CTX_cleanup(&hmac);
            return 0;
        }
        if (i > 1 && !HMAC_Update(&hmac, prev, hash_len)) {
            HMAC_CTX_cleanup(&hmac);
            return 0;
        }
        if (info && info_len > 0 && !HMAC_Update(&hmac, info, info_len)) {
            HMAC_CTX_cleanup(&hmac);
            return 0;
        }
        if (!HMAC_Update(&hmac, &ctr, 1u) || !HMAC_Final(&hmac, prev, NULL)) {
            HMAC_CTX_cleanup(&hmac);
            return 0;
        }

        size_t todo = out_len - done;
        if (todo > hash_len) {
            todo = hash_len;
        }
        memcpy(out_key + done, prev, todo);
        done += todo;
    }

    memset(prev, 0, sizeof(prev));
    HMAC_CTX_cleanup(&hmac);
    return 1;
}

/**
 * @brief Combined HKDF(salt, IKM, info, L) key derivation function.
 */
int HKDF(uint8_t* out_key, size_t out_len, const void* digest,
         const uint8_t* secret, size_t secret_len,
         const uint8_t* salt, size_t salt_len,
         const uint8_t* info, size_t info_len) {
    uint8_t prk[32];
    size_t prk_len = 0;
    if (!HKDF_extract(prk, &prk_len, digest, secret, secret_len, salt, salt_len)) {
        return 0;
    }
    int ret = HKDF_expand(out_key, out_len, digest, prk, prk_len, info, info_len);
    memset(prk, 0, sizeof(prk));
    return ret;
}
