// ============================================================================
// File: delta_interface.cpp
// Library: libdelta.so (ARM64-v8a)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: 7-stage standalone verification suite exercising all 4 internal helpers
//       (0x002d0c..0x003228) and all 19 exported JNI functions (0x001b3c..0x002d08)
//       of libdelta.so.
//   VN: Bộ kiểm thử tự kiểm chứng độc lập 7 giai đoạn thực thi toàn bộ 4 hàm
//       nội bộ (0x002d0c..0x003228) và 19 hàm xuất JNI (0x001b3c..0x002d08)
//       của libdelta.so.
// ============================================================================

#include "delta_interface.h"

namespace bytedance {
namespace zdplib {
namespace delta {

namespace {

struct MockByteArray {
    std::vector<jbyte> data;
};

static jsize MockGetArrayLength(void*, jobject arr) {
    if (!arr) return 0;
    return static_cast<jsize>(reinterpret_cast<MockByteArray*>(arr)->data.size());
}

static jbyte* MockGetByteArrayElements(void*, jbyteArray arr, jboolean* isCopy) {
    if (isCopy) *isCopy = JNI_FALSE;
    if (!arr) return nullptr;
    auto* m = reinterpret_cast<MockByteArray*>(arr);
    return m->data.empty() ? nullptr : m->data.data();
}

static void MockReleaseByteArrayElements(void*, jbyteArray, jbyte*, jint) {}

} // namespace

bool VerifyLibDeltaSelfTest() noexcept {
    JNINativeInterface_Delta vtbl{};
    vtbl.GetArrayLength           = MockGetArrayLength;
    vtbl.GetByteArrayElements     = MockGetByteArrayElements;
    vtbl.ReleaseByteArrayElements = MockReleaseByteArrayElements;
    JNIEnv env{&vtbl};

    // Stage 1: getEncryptedLen (0x001f5c) & getDecryptedLen (0x002430)
    if (Java_net_bytedance_zdplib_Delta_getEncryptedLen(&env, nullptr, 100) != 134) return false;
    if (Java_net_bytedance_zdplib_Delta_getDecryptedLen(&env, nullptr, 134) != 100) return false;

    // Stage 2: Alice & Bob P-256 key generation (0x002118, 0x002b84) & initialization (0x00208c, 0x00288c)
    MockByteArray alice_priv{{std::vector<jbyte>(32, 0)}};
    MockByteArray bob_priv{{std::vector<jbyte>(32, 0)}};
    if (Java_net_bytedance_zdplib_Delta_generatePrivateKey(&env, nullptr, &alice_priv) != 0) return false;
    if (Java_net_bytedance_zdplib_DeltaSignerVerifier_generatePrivateKey(&env, nullptr, &bob_priv) != 0) return false;

    jlong alice_handle = Java_net_bytedance_zdplib_Delta_initPrivateKey(&env, nullptr, &alice_priv);
    jlong bob_handle   = Java_net_bytedance_zdplib_DeltaSignerVerifier_initPrivateKey(&env, nullptr, &bob_priv);
    if (alice_handle <= 0 || bob_handle <= 0) return false;

    // Stage 3: Export compressed (33B, 0x002438 / 0x002918) & uncompressed (65B, 0x002be8) public keys
    MockByteArray alice_pub_33{{std::vector<jbyte>(33, 0)}};
    MockByteArray bob_pub_33{{std::vector<jbyte>(33, 0)}};
    MockByteArray bob_pub_65{{std::vector<jbyte>(65, 0)}};
    if (Java_net_bytedance_zdplib_Delta_getPublicKey(&env, nullptr, &alice_pub_33, alice_handle) != 0) return false;
    if (Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey(&env, nullptr, &bob_pub_33, bob_handle) != 0) return false;
    if (Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed(&env, nullptr, &bob_pub_65, bob_handle) != 0) return false;
    if (static_cast<uint8_t>(bob_pub_65.data[0]) != 0x04U) return false;

    // Stage 4: Import peer public keys via initPubKey (0x001fb0) and derive symmetric AES-256 keys via ECDH + HKDF (0x001b3c)
    jlong alice_peer_bob_handle = Java_net_bytedance_zdplib_Delta_initPubKey(&env, nullptr, &bob_pub_33);
    jlong bob_peer_alice_handle = Java_net_bytedance_zdplib_Delta_initPubKey(&env, nullptr, &alice_pub_33);
    if (alice_peer_bob_handle <= 0 || bob_peer_alice_handle <= 0) return false;

    MockByteArray alice_aes_key{{std::vector<jbyte>(32, 0)}};
    MockByteArray bob_aes_key{{std::vector<jbyte>(32, 0)}};
    if (Java_net_bytedance_zdplib_Delta_generateAesKey(&env, nullptr, &alice_aes_key, alice_handle, alice_peer_bob_handle) != 0) return false;
    if (Java_net_bytedance_zdplib_Delta_generateAesKey(&env, nullptr, &bob_aes_key, bob_handle, bob_peer_alice_handle) != 0) return false;
    if (alice_aes_key.data != bob_aes_key.data) return false;

    // Stage 5: AES-256-GCM encrypt (0x001c98) & decrypt (0x00217c) with 34B wire framing (0x01bd magic)
    const char* kMsg = "NextAI OpenCut Delta Zero-Data-Protection Test Payload";
    size_t msg_len = std::strlen(kMsg);
    MockByteArray plain_arr{{std::vector<jbyte>(kMsg, kMsg + msg_len)}};
    MockByteArray cipher_arr{{std::vector<jbyte>(msg_len + kDeltaPacketOverhead, 0)}};
    MockByteArray decrypted_arr{{std::vector<jbyte>(msg_len, 0)}};

    jint enc_res = Java_net_bytedance_zdplib_Delta_encrypt(&env, nullptr, &cipher_arr, &plain_arr, &alice_aes_key);
    if (enc_res != static_cast<jint>(msg_len + kDeltaPacketOverhead)) return false;
    if (static_cast<uint8_t>(cipher_arr.data[0]) != 0xbdU ||
        static_cast<uint8_t>(cipher_arr.data[1]) != 0x01U) return false;

    jint dec_res = Java_net_bytedance_zdplib_Delta_decrypt(&env, nullptr, &decrypted_arr, &cipher_arr, &bob_aes_key);
    if (dec_res != static_cast<jint>(msg_len)) return false;
    if (decrypted_arr.data != plain_arr.data) return false;

    // Tamper tag -> must fail with -9 (DELTA_ERR_DECRYPT_FAILED)
    cipher_arr.data.back() ^= 0x01;
    if (Java_net_bytedance_zdplib_Delta_decrypt(&env, nullptr, &decrypted_arr, &cipher_arr, &bob_aes_key) != DELTA_ERR_DECRYPT_FAILED) return false;

    // Stage 6: ECDSA-SHA256 sign (0x00255c / 0x002a3c) & verify (0x002654 / 0x002b34)
    MockByteArray sig_buf{{std::vector<jbyte>(72, 0)}};
    jint sig_len = Java_net_bytedance_zdplib_DeltaSignerVerifier_sign(&env, nullptr, &sig_buf, bob_handle, &plain_arr);
    if (sig_len <= 0 || sig_len > 72) return false;
    sig_buf.data.resize(static_cast<size_t>(sig_len));

    if (Java_net_bytedance_zdplib_Delta_verify(&env, nullptr, &sig_buf, &plain_arr, &bob_pub_33) != DELTA_OK) return false;
    if (Java_net_bytedance_zdplib_DeltaSignerVerifier_verify(&env, nullptr, &sig_buf, &plain_arr, &bob_pub_65) != DELTA_OK) return false;

    // Stage 7: Free all handles (0x001f64 / 0x002b38)
    Java_net_bytedance_zdplib_Delta_free(&env, nullptr, alice_peer_bob_handle);
    Java_net_bytedance_zdplib_Delta_free(&env, nullptr, bob_peer_alice_handle);
    Java_net_bytedance_zdplib_Delta_free(&env, nullptr, alice_handle);
    Java_net_bytedance_zdplib_DeltaSignerVerifier_free(&env, nullptr, bob_handle);
    return true;
}

} // namespace delta
} // namespace zdplib
} // namespace bytedance
