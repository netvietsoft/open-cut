// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libttcrypto.so (ByteDance TTNet / BoringSSL Cryptographic Core Engine)
// File: ttcrypto_types.h
// Description: Core AArch64 ABI data structures for SHA-256/512, AES-GCM,
//              ChaCha20-Poly1305, X25519/Ed25519, HMAC/HKDF, EVP/AEAD, and CBS/CBB ASN.1.
// Bilingual Annotations: English + Vietnamese (Rule 12 AGENTS.md)
// ===================================================================================

#ifndef NEXTAI_OPENCUT_TTCRYPTO_TYPES_H_
#define NEXTAI_OPENCUT_TTCRYPTO_TYPES_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

// ===================================================================================
// 1. SHA-256 & SHA-512 HASH CONTEXT STRUCTURES (FIPS 180-4)
// Cấu trúc ngữ cảnh băm mật mã SHA-256 (0x70 bytes) và SHA-512 (0xd8 bytes)
// ===================================================================================

/**
 * @brief SHA256_CTX structure matching AArch64 opcode at SHA256_Init (0x0be370).
 * Kích thước: 0x70 (112 bytes), md_len = 0x20 tại offset +0x6c (str w8, [x19, #0x6c]).
 */
typedef struct SHA256_CTX {
    uint32_t h[8];                // 0x00..0x1f: 8 thanh ghi trạng thái H0..H7 (256-bit state)
    uint32_t Nl;                  // 0x20: Tổng số bit đã xử lý (32-bit thấp) / Low bit count
    uint32_t Nh;                  // 0x24: Tổng số bit đã xử lý (32-bit cao) / High bit count
    uint8_t  data[64];            // 0x28..0x67: Bộ đệm khối 64-byte (512-bit message block)
    uint32_t num;                 // 0x68: Số byte hiện có trong bộ đệm data[]
    uint32_t md_len;              // 0x6c: Độ dài digest đầu ra (32 cho SHA-256, 28 cho SHA-224)
} SHA256_CTX;

/**
 * @brief SHA512_CTX structure for 64-bit word SHA-384 / SHA-512 hashing.
 * Kích thước: 0xd8 (216 bytes), md_len tại offset +0xd4.
 */
typedef struct SHA512_CTX {
    uint64_t h[8];                // 0x00..0x3f: 8 thanh ghi trạng thái 64-bit H0..H7
    uint64_t Nl;                  // 0x40: Tổng số bit thấp (64-bit)
    uint64_t Nh;                  // 0x48: Tổng số bit cao (64-bit)
    uint8_t  data[128];           // 0x50..0xcf: Bộ đệm khối 128-byte (1024-bit message block)
    uint32_t num;                 // 0xd0: Số byte hiện có trong bộ đệm
    uint32_t md_len;              // 0xd4: Độ dài digest (64 cho SHA-512, 48 cho SHA-384)
} SHA512_CTX;

// ===================================================================================
// 2. HMAC & HKDF KEY DERIVATION STRUCTURES (RFC 2104 & RFC 5869)
// Cấu trúc ngữ cảnh xác thực thông điệp HMAC và dẫn xuất khóa HKDF
// ===================================================================================

/**
 * @brief HMAC_CTX structure for RFC 2104 keyed-hash message authentication.
 * Khớp với HMAC_Init_ex tại 0x0b7084.
 */
typedef struct HMAC_CTX {
    SHA256_CTX md_ctx;            // 0x000..0x06f: Ngữ cảnh băm đang hoạt động
    SHA256_CTX i_ctx;             // 0x070..0x0df: Ngữ cảnh băm đã nạp khóa XOR ipad (0x36)
    SHA256_CTX o_ctx;             // 0x0e0..0x14f: Ngữ cảnh băm đã nạp khóa XOR opad (0x5c)
    uint32_t   key_len;           // 0x150: Độ dài khóa đã chuẩn hóa
    bool       initialized;       // 0x154: Cờ khởi tạo hợp lệ
} HMAC_CTX;

// ===================================================================================
// 3. AES BLOCK CIPHER & GCM128 AEAD STRUCTURES (FIPS 197 & NIST SP 800-38D)
// Cấu trúc khóa vòng AES (244 bytes) và ngữ cảnh xác thực GCM 128-bit
// ===================================================================================

#define AES_MAXNR 14
#define AES_BLOCK_SIZE 16

/**
 * @brief AES_KEY structure matching AES_set_encrypt_key (0x0a48e0).
 * Kích thước: 0xf4 (244 bytes), rounds tại offset +0xf0.
 */
typedef struct AES_KEY {
    uint32_t rd_key[4 * (AES_MAXNR + 1)]; // 0x00..0xef: 60 từ khóa vòng 32-bit (Round keys)
    uint32_t rounds;                      // 0xf0: Số vòng lặp (10 = AES-128, 12 = AES-192, 14 = AES-256)
} AES_KEY;

/**
 * @brief 128-bit Galois Field element in GCM (GF(2^128)).
 */
typedef struct u128_pair {
    uint64_t hi;
    uint64_t lo;
} u128_pair;

/**
 * @brief GCM128_CONTEXT structure matching CRYPTO_gcm128_aad (0x0b8d7c) and CRYPTO_gcm128_encrypt (0x0b8e78).
 * Offset chuẩn AArch64:
 *   +0x00: Yi (Current counter block J0/J_i)
 *   +0x10: EKi (Encrypted initial counter E_K(J0))
 *   +0x20: EK0 (Current encrypted counter block)
 *   +0x30: len.u[0] (AAD byte length — ldr x8, [x0, #0x30] tại 0x0b8da0)
 *   +0x38: len.u[1] (Ciphertext byte length — ldr x8, [x0, #0x38] tại 0x0b8d90)
 *   +0x40: Xi (Current GHASH accumulator)
 *   +0x50: H (Hash subkey E_K(0^128))
 *   +0x60: Htable[16] (Precomputed 4-bit Shoup table in GF(2^128))
 *   +0x160: key_ptr (Pointer to AES_KEY — ldr x23, [x19, #0x160] tại 0x0b8ea0)
 *   +0x180: ares (Partial AAD byte count)
 *   +0x184: mres (Partial message byte count — ldr w9, [x19, #0x184] tại 0x0b8e9c)
 */
typedef struct GCM128_CONTEXT {
    union {
        uint64_t u[2];
        uint32_t d[4];
        uint8_t  c[16];
    } Yi, EKi, EK0, len, Xi, H;   // 0x00..0x5f: 6 khối 128-bit (len.u[0] @ 0x30, len.u[1] @ 0x38)
    u128_pair Htable[16];         // 0x60..0x15f: Bảng nhân nhanh GF(2^128) 16 phần tử
    const AES_KEY* key;           // 0x160: Con trỏ khóa AES_KEY
    void (*gmult_func)(uint64_t Xi[2], const u128_pair Htable[16]); // 0x168
    void (*ghash_func)(uint64_t Xi[2], const u128_pair Htable[16], const uint8_t* inp, size_t len); // 0x170
    const void* block_func;       // 0x178: Con trỏ hàm mã hóa khối AES_encrypt
    uint32_t ares;                // 0x180: Số byte AAD lẻ chưa đủ khối 16-byte
    uint32_t mres;                // 0x184: Số byte dữ liệu lẻ chưa đủ khối 16-byte
} GCM128_CONTEXT;

// ===================================================================================
// 4. CHACHA20 & POLY1305 AEAD STRUCTURES (RFC 8439)
// Cấu trúc bộ mã dòng ChaCha20 và mã xác thực thông điệp Poly1305 trên GF(2^130 - 5)
// ===================================================================================

/**
 * @brief Poly1305 internal state using radix-2^26 limbs modulo 2^130 - 5.
 * Khớp với Poly1305_Init / Update / Final trong BoringSSL arm64.
 */
typedef struct poly1305_state_st {
    uint32_t h[5];                // 0x00..0x13: Bộ tích lũy 130-bit chia thành 5 limb 26-bit
    uint32_t r[5];                // 0x14..0x27: Khóa nhân r đã kẹp bit (clamped r)
    uint32_t pad[4];              // 0x28..0x37: Khóa cộng một lần s (128-bit pad)
    uint8_t  buf[16];             // 0x38..0x47: Bộ đệm khối 16-byte chưa hoàn tất
    size_t   buf_used;            // 0x48: Số byte đang lưu trong buf[]
} poly1305_state;

/**
 * @brief AEAD ChaCha20-Poly1305 context storing 256-bit key and tag length.
 */
typedef struct CHACHA20_POLY1305_CTX {
    uint8_t key[32];              // 0x00..0x1f: Khóa đối xứng 256-bit
    uint8_t tag_len;              // 0x20: Độ dài thẻ xác thực (mặc định 16 bytes)
    bool    initialized;          // 0x21: Cờ khởi tạo
} CHACHA20_POLY1305_CTX;

// ===================================================================================
// 5. CURVE25519 (X25519 & ED25519) FIELD ELEMENT & KEY STRUCTURES
// Cấu trúc phần tử trường hữu hạn GF(2^255 - 19) dạng 10-limb radix-2^25.5
// ===================================================================================

#define X25519_PRIVATE_KEY_LEN 32
#define X25519_PUBLIC_VALUE_LEN 32
#define X25519_SHARED_KEY_LEN 32
#define ED25519_PRIVATE_KEY_LEN 64
#define ED25519_PUBLIC_KEY_LEN 32
#define ED25519_SIGNATURE_LEN 64

/**
 * @brief 10-limb representation of an element in GF(2^255 - 19).
 * Các limb chẵn (0, 2, 4, 6, 8) chứa 26 bit; các limb lẻ (1, 3, 5, 7, 9) chứa 25 bit.
 * Tổng số bit: 5 * 26 + 5 * 25 = 255 bits.
 */
typedef struct fe25519 {
    int64_t v[10];
} fe25519;

// ===================================================================================
// 6. EVP CIPHER, AEAD & CBS/CBB ASN.1 DER PARSER STRUCTURES
// Cấu trúc giao diện mật mã cấp cao EVP và bộ phân tích ASN.1 CBS/CBB của BoringSSL
// ===================================================================================

typedef enum TTCryptoCipherAlg {
    TT_CIPHER_AES_128_CBC        = 1,
    TT_CIPHER_AES_256_CBC        = 2,
    TT_CIPHER_AES_128_CTR        = 3,
    TT_CIPHER_AES_256_CTR        = 4,
    TT_CIPHER_AES_128_GCM        = 5,
    TT_CIPHER_AES_256_GCM        = 6,
    TT_CIPHER_CHACHA20_POLY1305  = 7
} TTCryptoCipherAlg;

/**
 * @brief EVP_CIPHER descriptor table.
 */
typedef struct EVP_CIPHER {
    int32_t  nid;                 // Định danh thuật toán (TTCryptoCipherAlg)
    uint32_t block_size;          // Kích thước khối (1 hoặc 16 bytes)
    uint32_t key_len;             // Độ dài khóa (16 hoặc 32 bytes)
    uint32_t iv_len;              // Độ dài IV (12 hoặc 16 bytes)
    uint32_t flags;               // Cờ thuộc tính AEAD / CTR / CBC
} EVP_CIPHER;

/**
 * @brief EVP_CIPHER_CTX runtime cipher state matching EVP_EncryptInit_ex (0x0aec80).
 */
typedef struct EVP_CIPHER_CTX {
    const EVP_CIPHER* cipher;     // 0x00: Con trỏ mô tả thuật toán
    AES_KEY           aes_key;    // 0x08: Khóa vòng AES đã mở rộng
    GCM128_CONTEXT    gcm_ctx;    // Khối ngữ cảnh GCM128 (khi ở chế độ AES-GCM)
    uint8_t           iv[16];     // Vector khởi tạo hiện hành
    uint8_t           buf[16];    // Bộ đệm khối lẻ
    uint32_t          buf_len;    // Số byte đang chờ trong buf[]
    int32_t           encrypt;    // 1 = Encrypt, 0 = Decrypt
    uint8_t           gcm_tag[16];// Thẻ xác thực GCM 128-bit
} EVP_CIPHER_CTX;

/**
 * @brief EVP_AEAD descriptor matching EVP_AEAD_CTX_init (0x0ae3c8).
 */
typedef struct EVP_AEAD {
    uint8_t key_len;              // Độ dài khóa (16 hoặc 32 bytes)
    uint8_t nonce_len;            // Độ dài nonce (12 bytes)
    uint8_t overhead;             // Độ dài tag tối đa (16 bytes)
    uint8_t max_tag_len;          // Độ dài tag mặc định (16 bytes)
    int32_t alg_id;               // TT_CIPHER_AES_128_GCM, TT_CIPHER_AES_256_GCM, TT_CIPHER_CHACHA20_POLY1305
} EVP_AEAD;

/**
 * @brief EVP_AEAD_CTX stateful AEAD context.
 */
typedef struct EVP_AEAD_CTX {
    const EVP_AEAD* aead;         // 0x00: Con trỏ thuật toán AEAD
    AES_KEY         aes_key;      // Khóa AES (cho AES-GCM)
    uint8_t         raw_key[32];  // Khóa 256-bit (cho ChaCha20-Poly1305)
    uint8_t         tag_len;      // Độ dài thẻ xác thực đã cấu hình
    bool            initialized;  // Cờ trạng thái
} EVP_AEAD_CTX;

/**
 * @brief CBS (Crypto ByteString) safe zero-copy ASN.1 / TLS binary reader.
 * Một trong các nhóm hàm xuất khẩu lớn nhất của libttcrypto.so (45 hàm CBS_*).
 */
typedef struct CBS {
    const uint8_t* data;          // 0x00: Con trỏ tới vùng đệm hiện tại
    size_t         len;           // 0x08: Số byte còn lại chưa đọc
} CBS;

/**
 * @brief CBB (Crypto ByteBuilder) safe growing ASN.1 DER serializer.
 * Gồm 32 hàm xuất khẩu CBB_* trong libttcrypto.so.
 */
typedef struct CBB {
    uint8_t* buf;                 // 0x00: Bộ đệm đầu ra được cấp phát động
    size_t   len;                 // 0x08: Số byte đã ghi
    size_t   cap;                 // 0x10: Dung lượng tối đa hiện tại
    bool     owns_buf;            // 0x18: Cờ sở hữu bộ nhớ
    bool     error;               // 0x19: Cờ tràn hoặc lỗi ghi
} CBB;

// ASN.1 Tag constants used by CBS/CBB and X.509 parser
#define CBS_ASN1_BOOLEAN          0x01u
#define CBS_ASN1_INTEGER          0x02u
#define CBS_ASN1_BITSTRING        0x03u
#define CBS_ASN1_OCTETSTRING      0x04u
#define CBS_ASN1_NULL             0x05u
#define CBS_ASN1_OBJECT           0x06u
#define CBS_ASN1_UTF8STRING       0x0cu
#define CBS_ASN1_SEQUENCE         0x30u
#define CBS_ASN1_SET              0x31u
#define CBS_ASN1_CONTEXT_SPECIFIC 0x80u
#define CBS_ASN1_CONSTRUCTED      0x20u

#ifdef __cplusplus
}
#endif

#endif // NEXTAI_OPENCUT_TTCRYPTO_TYPES_H_
