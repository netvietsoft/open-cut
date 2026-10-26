// ============================================================================
// File: delta_jni_engine.h
// Library: libdelta.so (ARM64-v8a)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: Declarations for the 4 internal cryptographic helper functions
//       (0x002d0c..0x003228) and all 19 exported JNI functions
//       (0x001b3c..0x002d08) of net.bytedance.zdplib.Delta and
//       net.bytedance.zdplib.DeltaSignerVerifier.
//   VN: Khai báo 4 hàm hỗ trợ mật mã nội bộ (0x002d0c..0x003228) và toàn bộ
//       19 hàm xuất JNI (0x001b3c..0x002d08) của net.bytedance.zdplib.Delta
//       và net.bytedance.zdplib.DeltaSignerVerifier.
// ============================================================================

#pragma once

#include "delta_crypto_primitives.h"

namespace bytedance {
namespace zdplib {
namespace delta {

// ============================================================================
// EN: 4 Internal Helper Functions in .text (0x002d0c..0x003228)
//     Identified from .rodata function-name strings passed to __android_log_assert:
//       - 0x002d0c (500 bytes): create_EC_KEY_from_private_key_bin (.rodata 0x0033a9)
//       - 0x002f00 (380 bytes): create_EC_KEY_from_public_key_bin  (.rodata 0x0033eb)
//       - 0x00307c (216 bytes): generate_keypair                   (.rodata 0x00340d)
//       - 0x003154 (216 bytes): sign                               (.rodata 0x00341e)
// VN: 4 hàm hỗ trợ nội bộ trong .text (0x002d0c..0x003228)
// ============================================================================
EC_KEY* create_EC_KEY_from_private_key_bin(const uint8_t* priv_key_bin) noexcept; // 0x002d0c
EC_KEY* create_EC_KEY_from_public_key_bin(const uint8_t* pub_key_bin, int32_t key_length) noexcept; // 0x002f00
void generate_keypair(uint8_t* out_priv_key_bin) noexcept;                        // 0x00307c
int32_t sign_ecdsa_sha256(
    uint8_t* sig_out,
    EC_KEY* ec_key,
    const uint8_t* msg,
    int32_t msg_len) noexcept;                                                    // 0x003154

} // namespace delta
} // namespace zdplib
} // namespace bytedance

// ============================================================================
// EN: All 19 Exported JNI Symbols in .dynsym ([055]..[073])
// VN: Toàn bộ 19 ký hiệu xuất JNI trong .dynsym ([055]..[073])
// ============================================================================
extern "C" {

// [065] 0x001b3c (348 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_generateAesKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray aes_key_arr,
    jlong local_ec_key_handle,
    jlong peer_pub_ec_key_handle);

// [058] 0x001c98 (708 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_encrypt(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_encrypted_arr,
    jbyteArray in_plaintext_arr,
    jbyteArray aes_key_arr);

// [068] 0x001f5c (8 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_getEncryptedLen(
    JNIEnv* env,
    jobject thiz,
    jint plaintext_len);

// [069] 0x001f64 (76 bytes)
JNIEXPORT void JNICALL Java_net_bytedance_zdplib_Delta_free(
    JNIEnv* env,
    jobject thiz,
    jlong ec_key_handle);

// [055] 0x001fb0 (220 bytes)
JNIEXPORT jlong JNICALL Java_net_bytedance_zdplib_Delta_initPubKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray pub_key_arr);

// [064] 0x00208c (140 bytes)
JNIEXPORT jlong JNICALL Java_net_bytedance_zdplib_Delta_initPrivateKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray priv_key_arr);

// [066] 0x002118 (100 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_generatePrivateKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_priv_key_arr);

// [070] 0x00217c (692 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_decrypt(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_decrypted_arr,
    jbyteArray in_encrypted_arr,
    jbyteArray aes_key_arr);

// [060] 0x002430 (8 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_getDecryptedLen(
    JNIEnv* env,
    jobject thiz,
    jint encrypted_len);

// [056] 0x002438 (292 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_getPublicKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_pub_key_arr,
    jlong ec_key_handle);

// [071] 0x00255c (248 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_sign(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_sig_arr,
    jlong ec_key_handle,
    jbyteArray msg_arr);

// [072] 0x002654 (568 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_verify(
    JNIEnv* env,
    jobject thiz,
    jbyteArray sig_arr,
    jbyteArray msg_arr,
    jbyteArray pub_key_arr);

// [073] 0x00288c (140 bytes)
JNIEXPORT jlong JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_initPrivateKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray priv_key_arr);

// [059] 0x002918 (292 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_pub_key_arr,
    jlong ec_key_handle);

// [067] 0x002a3c (248 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_sign(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_sig_arr,
    jlong ec_key_handle,
    jbyteArray msg_arr);

// [061] 0x002b34 (4 bytes: tail-call to Java_net_bytedance_zdplib_Delta_verify)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_verify(
    JNIEnv* env,
    jobject thiz,
    jbyteArray sig_arr,
    jbyteArray msg_arr,
    jbyteArray pub_key_arr);

// [063] 0x002b38 (76 bytes)
JNIEXPORT void JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_free(
    JNIEnv* env,
    jobject thiz,
    jlong ec_key_handle);

// [057] 0x002b84 (100 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_generatePrivateKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_priv_key_arr);

// [062] 0x002be8 (292 bytes)
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_pub_key_arr,
    jlong ec_key_handle);

} // extern "C"
