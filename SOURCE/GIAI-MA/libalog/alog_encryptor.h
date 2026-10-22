/**
 * @file alog_encryptor.h
 * @brief ByteDance ALog Stream Cipher & Encryption Management Interface.
 *        Giao diện bộ mã hóa luồng dữ liệu bảo mật của hệ thống ALog.
 */

#ifndef BYTEDANCE_ALOG_ENCRYPTOR_H
#define BYTEDANCE_ALOG_ENCRYPTOR_H

#include "alog_types.h"
#include <pthread.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct AlogEncryptor_t {
    AlogEncryptorType   type;           ///< Encryption mode (None / AES-CFB / ChaCha20)
    uint8_t             key[32];        ///< 256-bit symmetric session key
    uint8_t             iv[16];         ///< 128-bit initialization vector
    uint32_t            iv_offset;      ///< Current streaming cipher offset
    uint64_t            bytes_encrypted;///< Counter of encrypted bytes
    pthread_mutex_t     lock;           ///< Thread-safety lock
} AlogEncryptor;

/**
 * @brief Create and initialize an encryptor instance with public key / secret seed.
 *        Khởi tạo bộ mã hóa dữ liệu sử dụng khóa công khai hoặc hạt giống bí mật.
 */
AlogEncryptor* alog_encryptor_create(AlogEncryptorType type, const char* pub_key);

/**
 * @brief Encrypt data in-place or into separate output buffer.
 *        Mã hóa dữ liệu tại chỗ (in-place) hoặc ghi vào bộ đệm đầu ra.
 */
int32_t alog_encryptor_encrypt(AlogEncryptor* enc,
                               const uint8_t* in_buf, size_t in_len,
                               uint8_t* out_buf, size_t out_capacity);

/**
 * @brief Decrypt data for verification and log recovery.
 *        Giải mã dữ liệu để kiểm chứng tính toàn vẹn và phục hồi nhật ký.
 */
int32_t alog_encryptor_decrypt(AlogEncryptor* enc,
                               const uint8_t* in_buf, size_t in_len,
                               uint8_t* out_buf, size_t out_capacity);

/**
 * @brief Generate a fresh initialization vector (IV) for a new log file.
 *        Sinh vector khởi tạo (IV) ngẫu nhiên mới cho tệp nhật ký tiếp theo.
 */
void alog_encryptor_refresh_iv(AlogEncryptor* enc);

/**
 * @brief Destroy encryptor instance and wipe sensitive key material from RAM.
 *        Giải phóng bộ mã hóa và xóa sạch dấu vết khóa mật khỏi bộ nhớ RAM.
 */
void alog_encryptor_destroy(AlogEncryptor* enc);

#ifdef __cplusplus
}
#endif

#endif // BYTEDANCE_ALOG_ENCRYPTOR_H
