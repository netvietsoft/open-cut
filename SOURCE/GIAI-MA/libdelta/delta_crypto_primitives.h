// ============================================================================
// File: delta_crypto_primitives.h
// Library: libdelta.so (ARM64-v8a)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: Declarations for the 36 BoringSSL/OpenSSL & Android logging functions
//       imported via .plt (0x001850..0x001af0) in libdelta.so:
//         - SHA-256 & HKDF-SHA256 (0x001880, 0x001910, 0x001a10, 0x001a50, 0x001ab0)
//         - AES-256-GCM EVP Cipher Suite (0x001850, 0x001940, 0x001980, 0x0019a0,
//           0x0019b0, 0x0019c0, 0x0019e0, 0x001a00, 0x001a20, 0x001a70)
//         - NIST P-256 (NID_X9_62_prime256v1 = 0x19f) BIGNUM, EC_GROUP, EC_POINT,
//           EC_KEY, ECDH & ECDSA (0x001860, 0x001870, 0x0018a0, 0x0018b0, 0x0018c0,
//           0x0018d0, 0x0018f0, 0x001900, 0x001920, 0x001930, 0x001950, 0x001970,
//           0x001990, 0x0019d0, 0x001a40, 0x001a80, 0x001aa0, 0x001ac0, 0x001ad0,
//           0x001ae0, 0x001af0)
//   VN: Khai báo 36 hàm mật mã BoringSSL/OpenSSL & ghi log Android được nhập
//       qua .plt (0x001850..0x001af0) trong libdelta.so.
// ============================================================================

#pragma once

#include "delta_types.h"

namespace bytedance {
namespace zdplib {
namespace delta {

// ============================================================================
// EN: Global Cached NIST P-256 Group Singleton at .bss 0x008000
//     Referenced at:
//       - 0x0024b0..0x0024cc (Java_net_bytedance_zdplib_Delta_getPublicKey)
//       - 0x002990..0x0029ac (Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey)
//       - 0x002c60..0x002c7c (Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed)
//       - 0x002f50..0x002f68 (create_EC_KEY_from_public_key_bin)
// VN: Con trỏ đơn thể nhóm đường cong NIST P-256 lưu đệm toàn cục tại .bss 0x008000
// ============================================================================
EC_GROUP* GetOrInitGlobalP256Group() noexcept;

// ============================================================================
// EN: SHA-256 & HKDF-SHA256 Primitives (.plt 0x001880, 0x001910, 0x001a10, 0x001a50, 0x001ab0)
// VN: Các hàm nguyên thủy SHA-256 & HKDF-SHA256
// ============================================================================
int SHA256_Init(SHA256_CTX* c) noexcept;                                         // 0x001910
int SHA256_Update(SHA256_CTX* c, const void* data, size_t len) noexcept;         // 0x001a50
int SHA256_Final(uint8_t* md, SHA256_CTX* c) noexcept;                           // 0x001a10
const EVP_MD* EVP_sha256() noexcept;                                             // 0x001ab0

// 0x001880: HKDF(out_key, out_len, digest, secret, secret_len, salt, salt_len, info, info_len)
int HKDF(
    uint8_t* out_key,
    size_t out_len,
    const EVP_MD* digest,
    const uint8_t* secret,
    size_t secret_len,
    const uint8_t* salt,
    size_t salt_len,
    const uint8_t* info,
    size_t info_len) noexcept;

// 0x0018e0: RAND_bytes(buf, len)
int RAND_bytes(uint8_t* buf, size_t len) noexcept;

// ============================================================================
// EN: AES-256-GCM EVP Primitives (.plt 0x001850, 0x001940, 0x001980, 0x0019a0,
//     0x0019b0, 0x0019c0, 0x0019e0, 0x001a00, 0x001a20, 0x001a70)
// VN: Các hàm nguyên thủy AES-256-GCM EVP
// ============================================================================
const EVP_CIPHER* EVP_aes_256_gcm() noexcept;                                    // 0x001a00
EVP_CIPHER_CTX* EVP_CIPHER_CTX_new() noexcept;                                   // 0x001a20
void EVP_CIPHER_CTX_free(EVP_CIPHER_CTX* ctx) noexcept;                          // 0x001940
int EVP_CIPHER_CTX_ctrl(EVP_CIPHER_CTX* ctx, int type, int arg, void* ptr) noexcept; // 0x0019e0

int EVP_EncryptInit_ex(
    EVP_CIPHER_CTX* ctx,
    const EVP_CIPHER* cipher,
    void* impl,
    const uint8_t* key,
    const uint8_t* iv) noexcept;                                                 // 0x0019c0

int EVP_EncryptUpdate(
    EVP_CIPHER_CTX* ctx,
    uint8_t* out,
    int* outl,
    const uint8_t* in,
    int inl) noexcept;                                                           // 0x001980

int EVP_EncryptFinal_ex(
    EVP_CIPHER_CTX* ctx,
    uint8_t* out,
    int* outl) noexcept;                                                         // 0x0019b0

int EVP_DecryptInit_ex(
    EVP_CIPHER_CTX* ctx,
    const EVP_CIPHER* cipher,
    void* impl,
    const uint8_t* key,
    const uint8_t* iv) noexcept;                                                 // 0x0019a0

int EVP_DecryptUpdate(
    EVP_CIPHER_CTX* ctx,
    uint8_t* out,
    int* outl,
    const uint8_t* in,
    int inl) noexcept;                                                           // 0x001a70

int EVP_DecryptFinal_ex(
    EVP_CIPHER_CTX* ctx,
    uint8_t* outm,
    int* outl) noexcept;                                                         // 0x001850

// ============================================================================
// EN: NIST P-256 BIGNUM, EC_GROUP, EC_POINT, EC_KEY, ECDH & ECDSA Primitives
// VN: Các hàm nguyên thủy đường cong elliptic NIST P-256, ECDH & ECDSA
// ============================================================================
BIGNUM* BN_bin2bn(const uint8_t* s, size_t len, BIGNUM* ret) noexcept;           // 0x0018d0
int BN_bn2bin_padded(uint8_t* out, size_t len, const BIGNUM* in) noexcept;       // 0x0018a0
void BN_free(BIGNUM* bn) noexcept;                                               // 0x001920

EC_GROUP* EC_GROUP_new_by_curve_name(int nid) noexcept;                          // 0x001970
EC_POINT* EC_POINT_new(const EC_GROUP* group) noexcept;                          // 0x001ad0
void EC_POINT_free(EC_POINT* point) noexcept;                                    // 0x001ac0

int EC_POINT_mul(
    const EC_GROUP* group,
    EC_POINT* r,
    const BIGNUM* n,
    const EC_POINT* q,
    const BIGNUM* m,
    void* ctx) noexcept;                                                         // 0x0018b0

size_t EC_POINT_point2oct(
    const EC_GROUP* group,
    const EC_POINT* p,
    int form,
    uint8_t* buf,
    size_t len,
    void* ctx) noexcept;                                                         // 0x0019d0

int EC_POINT_oct2point(
    const EC_GROUP* group,
    EC_POINT* p,
    const uint8_t* buf,
    size_t len,
    void* ctx) noexcept;                                                         // 0x001900

EC_KEY* EC_KEY_new_by_curve_name(int nid) noexcept;                              // 0x001af0
void EC_KEY_free(EC_KEY* key) noexcept;                                          // 0x001a40
int EC_KEY_generate_key(EC_KEY* key) noexcept;                                   // 0x001930
const EC_GROUP* EC_KEY_get0_group(const EC_KEY* key) noexcept;                   // 0x001990
const BIGNUM* EC_KEY_get0_private_key(const EC_KEY* key) noexcept;               // 0x0018f0
int EC_KEY_set_private_key(EC_KEY* key, const BIGNUM* prv) noexcept;             // 0x001950
const EC_POINT* EC_KEY_get0_public_key(const EC_KEY* key) noexcept;              // 0x0018c0
int EC_KEY_set_public_key(EC_KEY* key, const EC_POINT* pub) noexcept;            // 0x001870
void EC_KEY_set_conv_form(EC_KEY* key, int cform) noexcept;                      // 0x001aa0

int ECDH_compute_key(
    void* out,
    size_t outlen,
    const EC_POINT* pub_key,
    const EC_KEY* ecdh,
    void* (*KDF)(const void* in, size_t inlen, void* out, size_t* outlen)) noexcept; // 0x001ae0

int ECDSA_sign(
    int type,
    const uint8_t* dgst,
    size_t dgstlen,
    uint8_t* sig,
    unsigned int* siglen,
    EC_KEY* eckey) noexcept;                                                     // 0x001860

int ECDSA_verify(
    int type,
    const uint8_t* dgst,
    size_t dgstlen,
    const uint8_t* sig,
    size_t siglen,
    EC_KEY* eckey) noexcept;                                                     // 0x001a80

// ============================================================================
// EN: Android Logging & Assertion Helpers (.plt 0x001960 & 0x001a30)
// VN: Hàm hỗ trợ ghi log & kiểm tra điều kiện Android (.plt 0x001960 & 0x001a30)
// ============================================================================
int DeltaLogPrint(int prio, const char* tag, const char* fmt, ...) noexcept;     // 0x001960
void DeltaLogAssert(
    const char* cond,
    const char* tag,
    const char* fmt,
    const char* func,
    int line,
    const char* expr) noexcept;                                                  // 0x001a30

} // namespace delta
} // namespace zdplib
} // namespace bytedance
