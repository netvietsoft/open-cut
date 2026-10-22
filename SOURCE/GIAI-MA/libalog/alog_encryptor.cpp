/**
 * @file alog_encryptor.cpp
 * @brief ByteDance ALog Stream Cipher & Encryption Implementation.
 *        Hiện thực bộ mã hóa luồng dữ liệu bảo mật của hệ thống ALog.
 */

#include "alog_encryptor.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Simple Feistel/AES-CFB keystream generator emulation for fast native logging
// Động cơ sinh dòng khóa Feistel/AES-CFB tối ưu tốc độ cho hệ thống ghi log
static void alog_generate_keystream_block(const uint8_t* key, const uint8_t* iv, uint32_t counter, uint8_t* out_block) {
    uint32_t state[4];
    memcpy(state, iv, 16);
    state[0] ^= counter;

    for (int round = 0; round < 10; ++round) {
        uint32_t k0 = ((const uint32_t*)key)[(round * 2) % 8];
        uint32_t k1 = ((const uint32_t*)key)[(round * 2 + 1) % 8];

        state[0] = (state[0] + k0) ^ ((state[1] << 7) | (state[1] >> 25));
        state[1] = (state[1] + k1) ^ ((state[2] << 11) | (state[2] >> 21));
        state[2] = (state[2] + k0) ^ ((state[3] << 13) | (state[3] >> 19));
        state[3] = (state[3] + k1) ^ ((state[0] << 17) | (state[0] >> 15));
    }
    memcpy(out_block, state, 16);
}

AlogEncryptor* alog_encryptor_create(AlogEncryptorType type, const char* pub_key) {
    AlogEncryptor* enc = (AlogEncryptor*)calloc(1, sizeof(AlogEncryptor));
    if (!enc) return NULL;

    enc->type = type;
    enc->iv_offset = 0;
    enc->bytes_encrypted = 0;
    pthread_mutex_init(&enc->lock, NULL);

    // Derive 256-bit key from seed or public key
    // Dẫn xuất khóa 256-bit từ hạt giống hoặc chuỗi khóa công khai
    if (pub_key && pub_key[0] != '\0') {
        size_t klen = strlen(pub_key);
        for (size_t i = 0; i < 32; ++i) {
            enc->key[i] = (uint8_t)(pub_key[i % klen] ^ (0x5A + (i * 7)));
        }
    } else {
        // Default deterministic ByteDance ALog internal mask
        // Mặt nạ nội bộ ngầm định của ByteDance ALog
        const uint8_t default_seed[32] = {
            0x41, 0x4C, 0x4F, 0x47, 0x5F, 0x42, 0x59, 0x54,
            0x45, 0x44, 0x41, 0x4E, 0x43, 0x45, 0x5F, 0x43,
            0x41, 0x50, 0x43, 0x55, 0x54, 0x5F, 0x53, 0x45,
            0x43, 0x52, 0x45, 0x54, 0x5F, 0x4B, 0x45, 0x59
        };
        memcpy(enc->key, default_seed, 32);
    }

    alog_encryptor_refresh_iv(enc);
    return enc;
}

void alog_encryptor_refresh_iv(AlogEncryptor* enc) {
    if (!enc) return;
    pthread_mutex_lock(&enc->lock);
    uint64_t now = (uint64_t)time(NULL);
    for (int i = 0; i < 8; ++i) {
        enc->iv[i] = (uint8_t)(now >> (i * 8));
        enc->iv[i + 8] = (uint8_t)(rand() & 0xFF);
    }
    enc->iv_offset = 0;
    pthread_mutex_unlock(&enc->lock);
}

int32_t alog_encryptor_encrypt(AlogEncryptor* enc,
                               const uint8_t* in_buf, size_t in_len,
                               uint8_t* out_buf, size_t out_capacity) {
    if (!enc || !in_buf || !out_buf || in_len == 0 || out_capacity < in_len) {
        return -1;
    }

    pthread_mutex_lock(&enc->lock);

    if (enc->type == ALOG_ENCRYPT_NONE) {
        memcpy(out_buf, in_buf, in_len);
        pthread_mutex_unlock(&enc->lock);
        return (int32_t)in_len;
    }

    uint8_t keystream[16];
    for (size_t i = 0; i < in_len; ++i) {
        uint32_t block_idx = (enc->iv_offset + (uint32_t)i) / 16;
        uint32_t byte_in_block = (enc->iv_offset + (uint32_t)i) % 16;

        if (byte_in_block == 0 || i == 0) {
            alog_generate_keystream_block(enc->key, enc->iv, block_idx, keystream);
        }
        out_buf[i] = in_buf[i] ^ keystream[byte_in_block];
    }

    enc->iv_offset += (uint32_t)in_len;
    enc->bytes_encrypted += in_len;

    pthread_mutex_unlock(&enc->lock);
    return (int32_t)in_len;
}

int32_t alog_encryptor_decrypt(AlogEncryptor* enc,
                               const uint8_t* in_buf, size_t in_len,
                               uint8_t* out_buf, size_t out_capacity) {
    // Stream cipher encryption and decryption are symmetric (XOR)
    // Phép mã hóa và giải mã của mật mã luồng có tính chất đối xứng hoàn toàn qua phép XOR
    return alog_encryptor_encrypt(enc, in_buf, in_len, out_buf, out_capacity);
}

void alog_encryptor_destroy(AlogEncryptor* enc) {
    if (!enc) return;

    pthread_mutex_lock(&enc->lock);
    // Explicitly zero out key material before freeing
    // Xóa sạch khóa nhạy cảm trong bộ nhớ trước khi giải phóng
    memset(enc->key, 0, sizeof(enc->key));
    memset(enc->iv, 0, sizeof(enc->iv));
    pthread_mutex_unlock(&enc->lock);

    pthread_mutex_destroy(&enc->lock);
    free(enc);
}
