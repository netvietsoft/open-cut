// ============================================================================
// File: delta_jni_engine.cpp
// Library: libdelta.so (ARM64-v8a)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: 100% genuine algorithmic reconstruction of the 4 internal helpers
//       (0x002d0c..0x003228) and all 19 exported JNI methods
//       (0x001b3c..0x002d08) of net.bytedance.zdplib.Delta and
//       net.bytedance.zdplib.DeltaSignerVerifier, with exact AArch64
//       opcode citations.
//   VN: Tái dựng 100% thuật toán thực chất cho 4 hàm nội bộ
//       (0x002d0c..0x003228) và toàn bộ 19 phương thức xuất JNI
//       (0x001b3c..0x002d08) của net.bytedance.zdplib.Delta và
//       net.bytedance.zdplib.DeltaSignerVerifier, kèm đối chiếu mã máy AArch64.
// ============================================================================

#include "delta_jni_engine.h"

namespace bytedance {
namespace zdplib {
namespace delta {

// ============================================================================
// EN: Internal Helper 1 — create_EC_KEY_from_private_key_bin (0x002d0c, 500 bytes)
//     Exact AArch64 disassembly sequence (0x002d0c..0x002efc):
//       0x002d20: mov w0, #0x19f                 ; NID_X9_62_prime256v1 (415)
//       0x002d24: bl  EC_KEY_new_by_curve_name   ; 0x001af0
//       0x002d28: cbz x0, #0x2dd8                ; assert("ec_key != NULL", line 0x150 = 336)
//       0x002d30: bl  EC_KEY_generate_key        ; 0x001930
//       0x002d34: cbz w0, #0x2e00                ; assert("r != 0", line 0x152 = 338)
//       0x002d38: mov w1, #0x20                  ; len = 32
//       0x002d3c: mov x0, x20                    ; priv_key_bin
//       0x002d40: mov x2, xzr
//       0x002d44: bl  BN_bin2bn                  ; 0x0018d0 (inlined bin_to_private_key)
//       0x002d48: cbz x0, #0x2e2c                ; assert("priv_key != NULL", line 0x54 = 84)
//       0x002d58: bl  EC_KEY_set_private_key     ; 0x001950
//       0x002d5c: cbz w0, #0x2e54                ; assert("r != 0", line 0x155 = 341)
//       0x002d60: mov w1, #2                     ; POINT_CONVERSION_COMPRESSED = 2
//       0x002d68: bl  EC_KEY_set_conv_form       ; 0x001aa0
//       0x002d70: bl  EC_KEY_get0_group          ; 0x001990
//       0x002d74: bl  EC_POINT_new               ; 0x001ad0
//       0x002d78: cbz x0, #0x2e80                ; assert("pub_key != NULL", line 0x159 = 345)
//       0x002d84: bl  EC_KEY_get0_group          ; 0x001990
//       0x002d9c: bl  EC_POINT_mul(group, pub_key, priv_bn, NULL, NULL, NULL) ; 0x0018b0
//       0x002da0: cbz w0, #0x2ea8                ; assert("r != 0", line 0x15b = 347)
//       0x002dac: bl  EC_KEY_set_public_key      ; 0x001870
//       0x002db0: cbz w0, #0x2ed4                ; assert("r != 0", line 0x15d = 349)
//       0x002db8: bl  EC_POINT_free              ; 0x001ac0
//       0x002dc0: bl  BN_free                    ; 0x001920
//       0x002dc4: mov x0, x19                    ; return ec_key
// VN: Hàm nội bộ 1 — create_EC_KEY_from_private_key_bin (0x002d0c, 500 byte)
// ============================================================================
EC_KEY* create_EC_KEY_from_private_key_bin(const uint8_t* priv_key_bin) noexcept {
    EC_KEY* ec_key = EC_KEY_new_by_curve_name(kNidPrime256v1); // 0x002d20..0x002d24
    if (!ec_key) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_private_key_bin", 0x150, "ec_key != NULL");
        return nullptr;
    }
    int r = EC_KEY_generate_key(ec_key); // 0x002d30
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_private_key_bin", 0x152, "r != 0");
        EC_KEY_free(ec_key);
        return nullptr;
    }

    // Inlined bin_to_private_key (0x002d38..0x002d48, line 0x54 = 84)
    BIGNUM* priv_bn = BN_bin2bn(priv_key_bin, kPrivateKeyLength, nullptr);
    if (!priv_bn) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "bin_to_private_key", 0x54, "priv_key != NULL");
        EC_KEY_free(ec_key);
        return nullptr;
    }

    r = EC_KEY_set_private_key(ec_key, priv_bn); // 0x002d58
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_private_key_bin", 0x155, "r != 0");
        BN_free(priv_bn);
        EC_KEY_free(ec_key);
        return nullptr;
    }

    EC_KEY_set_conv_form(ec_key, kPointConvCompressed); // 0x002d60..0x002d68 (form = 2)

    const EC_GROUP* group = EC_KEY_get0_group(ec_key); // 0x002d70
    EC_POINT* pub_key = EC_POINT_new(group);           // 0x002d74
    if (!pub_key) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_private_key_bin", 0x159, "pub_key != NULL");
        BN_free(priv_bn);
        EC_KEY_free(ec_key);
        return nullptr;
    }

    group = EC_KEY_get0_group(ec_key); // 0x002d84
    r = EC_POINT_mul(group, pub_key, priv_bn, nullptr, nullptr, nullptr); // 0x002d9c
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_private_key_bin", 0x15b, "r != 0");
        EC_POINT_free(pub_key);
        BN_free(priv_bn);
        EC_KEY_free(ec_key);
        return nullptr;
    }

    r = EC_KEY_set_public_key(ec_key, pub_key); // 0x002dac
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_private_key_bin", 0x15d, "r != 0");
        EC_POINT_free(pub_key);
        BN_free(priv_bn);
        EC_KEY_free(ec_key);
        return nullptr;
    }

    EC_POINT_free(pub_key); // 0x002db8
    BN_free(priv_bn);       // 0x002dc0
    return ec_key;          // 0x002dc4
}

// ============================================================================
// EN: Internal Helper 2 — create_EC_KEY_from_public_key_bin (0x002f00, 380 bytes)
//     Exact AArch64 disassembly sequence (0x002f00..0x003078):
//       0x002f18: mov  w0, #0x19f                ; NID_X9_62_prime256v1 (415)
//       0x002f20: bl   EC_KEY_new_by_curve_name  ; 0x001af0
//       0x002f24: cbz  x0, #0x2fd0               ; assert("ec_key != NULL", line 0x167 = 359)
//       0x002f2c: bl   EC_KEY_generate_key       ; 0x001930
//       0x002f30: cbz  w0, #0x2ff8               ; assert("r != 0", line 0x169 = 361)
//       0x002f34: mov  w1, #2                    ; POINT_CONVERSION_COMPRESSED = 2
//       0x002f3c: bl   EC_KEY_set_conv_form      ; 0x001aa0
//       0x002f40: cmp  w21, #0x21                ; 33 bytes (compressed)
//       0x002f44: b.eq #0x2f50
//       0x002f48: cmp  w21, #0x41                ; 65 bytes (uncompressed)
//       0x002f4c: b.ne #0x3024                   ; assert in bin_to_public_key (line 0x39 = 57)
//       0x002f50: adrp x22, #0x8000              ; .bss 0x008000 cached EC_GROUP*
//       0x002f54: ldr  x23, [x22]
//       0x002f58: cbnz x23, #0x2f6c
//       0x002f5c: mov  w0, #0x19f
//       0x002f60: bl   EC_GROUP_new_by_curve_name
//       0x002f68: str  x0, [x22]
//       0x002f70: bl   EC_POINT_new(group)       ; 0x001ad0
//       0x002f8c: bl   EC_POINT_oct2point(group, pt, pub_key_bin, key_length, NULL) ; 0x001900
//       0x002f90: cbnz w0, #0x2fa0
//       0x002f98: bl   EC_POINT_free(pt)         ; if oct2point == 0, free pt and set pt = NULL
//       0x002f9c: mov  x22, xzr
//       0x002fa8: bl   EC_KEY_set_public_key(ec_key, pt) ; 0x001870
//       0x002fac: cbz  w0, #0x3050               ; assert("r != 0", line 0x16e = 366)
//       0x002fb4: bl   EC_POINT_free(pt)         ; 0x001ac0
//       0x002fb8: mov  x0, x19                   ; return ec_key
// VN: Hàm nội bộ 2 — create_EC_KEY_from_public_key_bin (0x002f00, 380 byte)
// ============================================================================
EC_KEY* create_EC_KEY_from_public_key_bin(const uint8_t* pub_key_bin, int32_t key_length) noexcept {
    EC_KEY* ec_key = EC_KEY_new_by_curve_name(kNidPrime256v1); // 0x002f18..0x002f20
    if (!ec_key) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_public_key_bin", 0x167, "ec_key != NULL");
        return nullptr;
    }
    int r = EC_KEY_generate_key(ec_key); // 0x002f2c
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_public_key_bin", 0x169, "r != 0");
        EC_KEY_free(ec_key);
        return nullptr;
    }
    EC_KEY_set_conv_form(ec_key, kPointConvCompressed); // 0x002f34..0x002f3c

    // Inlined bin_to_public_key (0x002f40..0x002fa0, line 0x39 = 57)
    if (key_length != kPublicKeyLength && key_length != kUncompressPublicKeyLength) {
        DeltaLogAssert(
            nullptr,
            "Delta",
            "%s(%d) >> %s ",
            "bin_to_public_key",
            0x39,
            "key_length == UncompressPublicKeyLength || key_length == PublicKeyLength");
        EC_KEY_free(ec_key);
        return nullptr;
    }

    EC_GROUP* group = GetOrInitGlobalP256Group(); // 0x002f50..0x002f68 (.bss 0x008000)
    EC_POINT* pt = EC_POINT_new(group);           // 0x002f70
    if (pt) {
        int ok = EC_POINT_oct2point(group, pt, pub_key_bin, static_cast<size_t>(key_length), nullptr); // 0x002f8c
        if (ok == 0) {
            EC_POINT_free(pt); // 0x002f98
            pt = nullptr;      // 0x002f9c
        }
    }

    r = EC_KEY_set_public_key(ec_key, pt); // 0x002fa8
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "create_EC_KEY_from_public_key_bin", 0x16e, "r != 0");
        EC_POINT_free(pt);
        EC_KEY_free(ec_key);
        return nullptr;
    }

    EC_POINT_free(pt); // 0x002fb4
    return ec_key;     // 0x002fb8
}

// ============================================================================
// EN: Internal Helper 3 — generate_keypair (0x00307c, 216 bytes)
//     Exact AArch64 disassembly sequence (0x00307c..0x003150):
//       0x00308c: mov w0, #0x19f                ; NID_X9_62_prime256v1 (415)
//       0x003090: bl  EC_KEY_new_by_curve_name  ; 0x001af0
//       0x003094: cbz x0, #0x30d4               ; assert("ec_key != NULL", line 0x176 = 374)
//       0x00309c: bl  EC_KEY_generate_key       ; 0x001930
//       0x0030a0: cbz w0, #0x30fc               ; assert("r != 0", line 0x178 = 376)
//       0x0030a8: bl  EC_KEY_get0_private_key   ; 0x0018f0
//       0x0030b0: mov w1, #0x20                 ; 32 bytes
//       0x0030b8: bl  BN_bn2bin_padded          ; 0x0018a0 (inlined private_key_to_bin)
//       0x0030bc: cmp w0, #1
//       0x0030c0: b.ne #0x3128                  ; assert("result == 1", line 0x5d = 93)
//       0x0030d0: b   EC_KEY_free               ; 0x001a40 (tail-call)
// VN: Hàm nội bộ 3 — generate_keypair (0x00307c, 216 byte)
// ============================================================================
void generate_keypair(uint8_t* out_priv_key_bin) noexcept {
    EC_KEY* ec_key = EC_KEY_new_by_curve_name(kNidPrime256v1); // 0x00308c..0x003090
    if (!ec_key) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "generate_keypair", 0x176, "ec_key != NULL");
        return;
    }
    int r = EC_KEY_generate_key(ec_key); // 0x00309c
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "generate_keypair", 0x178, "r != 0");
        EC_KEY_free(ec_key);
        return;
    }
    // Inlined private_key_to_bin (0x0030a4..0x0030c0, line 0x5d = 93)
    const BIGNUM* priv_bn = EC_KEY_get0_private_key(ec_key); // 0x0030a8
    int result = BN_bn2bin_padded(out_priv_key_bin, kPrivateKeyLength, priv_bn); // 0x0030b8
    if (result != 1) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "private_key_to_bin", 0x5d, "result == 1");
    }
    EC_KEY_free(ec_key); // 0x0030d0
}

// ============================================================================
// EN: Internal Helper 4 — sign (0x003154, 216 bytes)
//     Exact AArch64 disassembly sequence (0x003154..0x003228):
//       0x003178: add  x0, sp, #0x28            ; SHA256_CTX (112B) at sp + 0x28
//       0x00318c: str  wzr, [sp, #4]            ; sig_len = 0
//       0x003190: bl   SHA256_Init              ; 0x001910
//       0x003194: sxtw x2, w19                  ; msg_len
//       0x003198: add  x0, sp, #0x28
//       0x00319c: mov  x1, x20                  ; msg
//       0x0031a0: bl   SHA256_Update            ; 0x001a50
//       0x0031a4: add  x0, sp, #8               ; digest[32] at sp + 8
//       0x0031a8: add  x1, sp, #0x28
//       0x0031ac: bl   SHA256_Final             ; 0x001a10
//       0x0031b8: mov  w2, #0x20                ; dgstlen = 32
//       0x0031bc: mov  w0, wzr                  ; type = 0
//       0x0031c0: mov  x3, x22                  ; sig_out
//       0x0031c4: mov  x5, x21                  ; ec_key
//       0x0031c8: bl   ECDSA_sign               ; 0x001860
//       0x0031cc: cbz  w0, #0x31fc              ; assert("r != 0", line 0x19b = 411)
//       0x0031d0: ldr  w0, [sp, #4]             ; return sig_len
// VN: Hàm nội bộ 4 — sign (0x003154, 216 byte)
// ============================================================================
int32_t sign_ecdsa_sha256(
    uint8_t* sig_out,
    EC_KEY* ec_key,
    const uint8_t* msg,
    int32_t msg_len) noexcept {
    unsigned int sig_len = 0; // sp + 4 (0x00318c)
    SHA256_CTX sha_ctx;       // sp + 0x28 (0x003178)
    SHA256_Init(&sha_ctx);    // 0x003190
    SHA256_Update(&sha_ctx, msg, static_cast<size_t>(msg_len)); // 0x0031a0

    uint8_t digest[32];       // sp + 8 (0x0031a4)
    SHA256_Final(digest, &sha_ctx); // 0x0031ac

    int r = ECDSA_sign(0, digest, kSha256DigestLength, sig_out, &sig_len, ec_key); // 0x0031c8
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "sign", 0x19b, "r != 0");
        return 0;
    }
    return static_cast<int32_t>(sig_len); // 0x0031d0
}

} // namespace delta
} // namespace zdplib
} // namespace bytedance

// ============================================================================
// EN: Exported JNI Implementations (19 symbols at 0x001b3c..0x002d08)
// VN: Hiện thực 19 hàm xuất JNI tại 0x001b3c..0x002d08
// ============================================================================
using namespace bytedance::zdplib::delta;

extern "C" {

// ============================================================================
// [065] Java_net_bytedance_zdplib_Delta_generateAesKey (0x001b3c, 348 bytes)
// Disassembly (0x001b3c..0x001c94):
//   - Checks GetArrayLength(aes_key_arr) == 0x20 (32); else returns -5 (0x001c3c).
//   - Gets aes_key_bytes via GetByteArrayElements (0x001b98).
//   - Calls peer_pub_pt = EC_KEY_get0_public_key(peer_pub_ec_key_handle) (0x001ba8).
//   - Calls ECDH_compute_key(shared_secret_32b, 0x20, peer_pub_pt, local_ec_key, NULL) (0x001bc0);
//     if 0, asserts "r != 0" in encapsulates_aes_key (line 0x69 = 105, 0x001c6c).
//   - Calls HKDF(aes_key_bytes, 0x20, EVP_sha256(), shared_secret_32b, 0x20, NULL, 0, NULL, 0) (0x001bf0).
//   - If HKDF == 0, returns -2 (0x001bf8..0x001c04) without releasing; else calls
//     ReleaseByteArrayElements(..., 0) (0x001c20) and returns 0 (wzr).
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_generateAesKey(
    JNIEnv* env,
    jobject,
    jbyteArray aes_key_arr,
    jlong local_ec_key_handle,
    jlong peer_pub_ec_key_handle) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    if (env->GetArrayLength(aes_key_arr) != kAes256KeyLength) { // 0x001b80: cmp w0, #0x20
        return DELTA_ERR_INVALID_KEY_LEN;                       // 0x001c3c: mov w0, #-5
    }

    jbyte* out_aes_elems = env->GetByteArrayElements(aes_key_arr, nullptr); // 0x001b9c
    auto* local_key = reinterpret_cast<EC_KEY*>(local_ec_key_handle);
    auto* peer_key  = reinterpret_cast<EC_KEY*>(peer_pub_ec_key_handle);

    // Inlined encapsulates_aes_key (0x001ba4..0x001bf0, line 0x69 = 105)
    const EC_POINT* peer_pub_pt = EC_KEY_get0_public_key(peer_key); // 0x001ba8
    uint8_t shared_secret[32]; // sp + 8
    int r = ECDH_compute_key(shared_secret, kAes256KeyLength, peer_pub_pt, local_key, nullptr); // 0x001bc0
    if (r == 0) {
        DeltaLogAssert(nullptr, "Delta", "%s(%d) >> %s ", "encapsulates_aes_key", 0x69, "r != 0");
        env->ReleaseByteArrayElements(aes_key_arr, out_aes_elems, 0);
        return DELTA_ERR_HKDF_FAILED;
    }

    int hkdf_ok = HKDF(
        reinterpret_cast<uint8_t*>(out_aes_elems),
        kAes256KeyLength,
        EVP_sha256(),
        shared_secret,
        kAes256KeyLength,
        nullptr,
        0,
        nullptr,
        0); // 0x001bc8..0x001bf0
    if (hkdf_ok == 0) {
        return DELTA_ERR_HKDF_FAILED; // 0x001bf8: mov w9, #-2
    }

    env->ReleaseByteArrayElements(aes_key_arr, out_aes_elems, 0); // 0x001c20
    return DELTA_OK;                                              // 0x001c24: mov w0, wzr
}

// ============================================================================
// [058] Java_net_bytedance_zdplib_Delta_encrypt (0x001c98, 708 bytes)
// Disassembly (0x001c98..0x001f58):
//   - Checks GetArrayLength(aes_key_arr) == 0x20 (32); else returns -5 (0x001d9c).
//   - Checks GetArrayLength(in_plaintext_arr) >= 1; else returns -7 (0x001dd4).
//   - Gets pointers for out_encrypted_arr (x23), in_plaintext_arr ([sp,#8]), aes_key_arr (x25).
//   - Checks plaintext_len + 0x22 <= GetArrayLength(out_encrypted_arr) (0x001d88..0x001d90);
//     else releases arrays and returns -4 (0x001d94).
//   - Writes 0x01bd ([0xbd, 0x01]) at out_encrypted[0..1] (0x001df0..0x001dfc).
//   - Generates 16B random IV via RAND_bytes(iv, 16) (0x001e00) and stores at
//     out_encrypted[2..17] (`ldur q0, [sp,#0x18]; stur q0, [x23,#2]` @ 0x001e04..0x001e08).
//   - Encrypts plaintext with AES-256-GCM (16B IV) into out_encrypted + 0x12 (0x001e6c..0x001ea8)
//     and writes 16B GCM tag to out_encrypted + 0x12 + plaintext_len (0x001eb0..0x001ec0).
//   - Releases all 3 byte arrays and returns plaintext_len + 0x22 (or -3 on cipher error).
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_encrypt(
    JNIEnv* env,
    jobject,
    jbyteArray out_encrypted_arr,
    jbyteArray in_plaintext_arr,
    jbyteArray aes_key_arr) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    if (env->GetArrayLength(aes_key_arr) != kAes256KeyLength) { // 0x001ce4: cmp w0, #0x20
        return DELTA_ERR_INVALID_KEY_LEN;                       // 0x001d9c: mov w26, #-5
    }
    if (env->GetArrayLength(in_plaintext_arr) < 1) {            // 0x001d00: cmp w0, #1
        return DELTA_ERR_INPUT_TOO_SHORT;                       // 0x001dd4: mov w26, #-7
    }

    jbyte* out_elems   = env->GetByteArrayElements(out_encrypted_arr, nullptr); // 0x001d1c
    jbyte* plain_elems = env->GetByteArrayElements(in_plaintext_arr, nullptr);  // 0x001d38
    jbyte* key_elems   = env->GetByteArrayElements(aes_key_arr, nullptr);       // 0x001d54

    jsize out_cap   = env->GetArrayLength(out_encrypted_arr); // 0x001d6c (w26)
    jsize plain_len = env->GetArrayLength(in_plaintext_arr);  // 0x001d84 (w0)
    jint total_len  = plain_len + kDeltaPacketOverhead;       // 0x001d88: add w24, w0, #0x22

    jint result = DELTA_ERR_BUFFER_TOO_SMALL; // -4 (0x001d94)
    if (total_len <= out_cap) {               // 0x001d8c..0x001d90: cmp w24, w26; b.le #0x1dec
        auto* out_u8   = reinterpret_cast<uint8_t*>(out_elems);
        auto* plain_u8 = reinterpret_cast<const uint8_t*>(plain_elems);
        auto* key_u8   = reinterpret_cast<const uint8_t*>(key_elems);

        // 0x001df0..0x001dfc: mov w8, #0x1bd; strh w8, [x23]
        out_u8[0] = kDeltaMagicByte0; // 0xbd
        out_u8[1] = kDeltaMagicByte1; // 0x01

        // 0x001df4..0x001e08: RAND_bytes(iv, 0x10); stur q0, [x23, #2]
        uint8_t iv[16];
        RAND_bytes(iv, kDeltaGcmIvSize);
        std::memcpy(out_u8 + kDeltaHeaderSize, iv, kDeltaGcmIvSize);

        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new(); // 0x001e0c
        int outl = 0;
        int final_outl = 0;
        bool ok = false;
        if (ctx &&
            EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 0 && // 0x001e2c
            EVP_CIPHER_CTX_ctrl(ctx, kEvpCtrlGcmSetIvLen, kDeltaGcmIvSize, nullptr) != 0 && // 0x001e44
            EVP_EncryptInit_ex(ctx, nullptr, nullptr, key_u8, iv) != 0 && // 0x001e60
            EVP_EncryptUpdate(ctx, out_u8 + kDeltaCiphertextOffset, &outl, plain_u8, plain_len) != 0 && // 0x001e80
            outl == plain_len && // 0x001e8c: cmp w8, w27
            EVP_EncryptFinal_ex(ctx, out_u8 + kDeltaCiphertextOffset + plain_len, &final_outl) != 0 && // 0x001ea8
            EVP_CIPHER_CTX_ctrl(ctx, kEvpCtrlGcmGetTag, kDeltaGcmTagSize, out_u8 + kDeltaCiphertextOffset + plain_len) != 0) { // 0x001ec0
            ok = true;
        }
        EVP_CIPHER_CTX_free(ctx); // 0x001ecc / 0x001ee4
        result = ok ? total_len : DELTA_ERR_ENCRYPT_FAILED; // 0x001ed4..0x001ef0
    }

    env->ReleaseByteArrayElements(out_encrypted_arr, out_elems, 0);   // 0x001f0c
    env->ReleaseByteArrayElements(in_plaintext_arr, plain_elems, 0);  // 0x001f28
    env->ReleaseByteArrayElements(aes_key_arr, key_elems, 0);         // 0x001f44
    return result;
}

// ============================================================================
// [068] Java_net_bytedance_zdplib_Delta_getEncryptedLen (0x001f5c, 8 bytes)
//   0x001f5c: add w0, w2, #0x22
//   0x001f60: ret
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_getEncryptedLen(
    JNIEnv*,
    jobject,
    jint plaintext_len) {
    return plaintext_len + kDeltaPacketOverhead; // + 34 (0x22)
}

// ============================================================================
// [069] Java_net_bytedance_zdplib_Delta_free (0x001f64, 76 bytes)
//   0x001f74: cbz x2, #0x1f88
//   0x001f84: b   EC_KEY_free (0x001a40)
//   0x001f88..0x001f9c: __android_log_print(7, "Delta", "ephemeral_key is 0")
//   0x001fac: b   EC_KEY_free (0x001a40)
// ============================================================================
JNIEXPORT void JNICALL Java_net_bytedance_zdplib_Delta_free(
    JNIEnv*,
    jobject,
    jlong ec_key_handle) {
    if (ec_key_handle == 0) {
        DeltaLogPrint(7, "Delta", "ephemeral_key is 0"); // .rodata 0x00322c
    }
    EC_KEY_free(reinterpret_cast<EC_KEY*>(ec_key_handle));
}

// ============================================================================
// [055] Java_net_bytedance_zdplib_Delta_initPubKey (0x001fb0, 220 bytes)
// Disassembly (0x001fb0..0x002088):
//   - Checks GetArrayLength(pub_key_arr) == 0x21 (33) or 0x41 (65).
//   - If neither, logs error (prio 6, "Delta", "invalid pub_key" @ 0x00323f)
//     and returns -5 (0x002074).
//   - Otherwise calls create_EC_KEY_from_public_key_bin(elems, len) (0x002034),
//     releases byte array, and returns EC_KEY* handle as jlong.
// ============================================================================
JNIEXPORT jlong JNICALL Java_net_bytedance_zdplib_Delta_initPubKey(
    JNIEnv* env,
    jobject,
    jbyteArray pub_key_arr) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    jsize len = env->GetArrayLength(pub_key_arr); // 0x001fd4
    if (len != kPublicKeyLength && env->GetArrayLength(pub_key_arr) != kUncompressPublicKeyLength) {
        DeltaLogPrint(6, "Delta", "invalid pub_key"); // 0x002070 (.rodata 0x00323f)
        return DELTA_ERR_INVALID_KEY_LEN;             // 0x002074: mov x21, #-5
    }
    jbyte* pub_elems = env->GetByteArrayElements(pub_key_arr, nullptr); // 0x002010
    jsize key_len = env->GetArrayLength(pub_key_arr);                   // 0x002028
    EC_KEY* ec_key = create_EC_KEY_from_public_key_bin(
        reinterpret_cast<const uint8_t*>(pub_elems), key_len);          // 0x002034
    env->ReleaseByteArrayElements(pub_key_arr, pub_elems, 0);           // 0x002054
    return reinterpret_cast<jlong>(ec_key);
}

// ============================================================================
// [064] Java_net_bytedance_zdplib_Delta_initPrivateKey (0x00208c, 140 bytes)
// Disassembly (0x00208c..0x002114):
//   - Checks GetArrayLength(priv_key_arr) == 0x20 (32); else returns -5 (0x002100).
//   - Calls create_EC_KEY_from_private_key_bin(elems) (0x0020d8), releases byte array,
//     and returns EC_KEY* handle as jlong.
// ============================================================================
JNIEXPORT jlong JNICALL Java_net_bytedance_zdplib_Delta_initPrivateKey(
    JNIEnv* env,
    jobject,
    jbyteArray priv_key_arr) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    if (env->GetArrayLength(priv_key_arr) != kPrivateKeyLength) { // 0x0020b4: cmp w0, #0x20
        return DELTA_ERR_INVALID_KEY_LEN;                         // 0x002100: mov x21, #-5
    }
    jbyte* priv_elems = env->GetByteArrayElements(priv_key_arr, nullptr); // 0x0020d0
    EC_KEY* ec_key = create_EC_KEY_from_private_key_bin(
        reinterpret_cast<const uint8_t*>(priv_elems));                    // 0x0020d8
    env->ReleaseByteArrayElements(priv_key_arr, priv_elems, 0);           // 0x0020f8
    return reinterpret_cast<jlong>(ec_key);
}

// ============================================================================
// [066] Java_net_bytedance_zdplib_Delta_generatePrivateKey (0x002118, 100 bytes)
// Disassembly (0x002118..0x002178):
//   - Gets byte array elements (0x002140), calls generate_keypair (0x002148),
//     releases byte array (0x002164), and returns 0 (wzr).
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_generatePrivateKey(
    JNIEnv* env,
    jobject,
    jbyteArray out_priv_key_arr) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    jbyte* priv_elems = env->GetByteArrayElements(out_priv_key_arr, nullptr); // 0x002140
    generate_keypair(reinterpret_cast<uint8_t*>(priv_elems));                 // 0x002148
    env->ReleaseByteArrayElements(out_priv_key_arr, priv_elems, 0);           // 0x002164
    return DELTA_OK;                                                          // 0x002170: mov w0, wzr
}

// ============================================================================
// [070] Java_net_bytedance_zdplib_Delta_decrypt (0x00217c, 692 bytes)
// Disassembly (0x00217c..0x00242c):
//   - Gets elements and lengths for out_decrypted_arr, in_encrypted_arr, aes_key_arr.
//   - Computes decrypted_len = encrypted_len - 0x22 (`subs w27, w28, #0x22` @ 0x002234);
//     if < 0, returns -7 (0x002240).
//   - Checks encrypted[0] == 0xbd (0x00224c) and encrypted[1] == 0x01 (0x002258);
//     else returns -8 (0x002274).
//   - Checks decrypted_len <= out_decrypted_cap (0x002264); else returns -4 (0x00226c).
//   - Initializes AES-256-GCM decryption with 16B IV at encrypted + 2 (0x002344),
//     decrypts ciphertext at encrypted + 0x12 (0x002364), sets expected 16B GCM tag
//     at encrypted + encrypted_len - 16 (0x002390..0x0023a4), and calls
//     EVP_DecryptFinal_ex (0x0023bc).
//   - If authentication fails, returns -9 (0x0023d4 / 0x00241c); else returns decrypted_len.
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_decrypt(
    JNIEnv* env,
    jobject,
    jbyteArray out_decrypted_arr,
    jbyteArray in_encrypted_arr,
    jbyteArray aes_key_arr) {
    if (!env) return DELTA_ERR_DECRYPT_FAILED;

    jbyte* out_elems = env->GetByteArrayElements(out_decrypted_arr, nullptr); // 0x0021c8
    jsize  out_cap   = env->GetArrayLength(out_decrypted_arr);                // 0x0021e0
    jbyte* enc_elems = env->GetByteArrayElements(in_encrypted_arr, nullptr);  // 0x0021fc
    jsize  enc_len   = env->GetArrayLength(in_encrypted_arr);                 // 0x002214
    jbyte* key_elems = env->GetByteArrayElements(aes_key_arr, nullptr);       // 0x002230

    jint expected_plain_len = enc_len - kDeltaPacketOverhead; // 0x002234: subs w27, w28, #0x22
    jint result = expected_plain_len;

    const auto* enc_u8 = reinterpret_cast<const uint8_t*>(enc_elems);
    auto* out_u8       = reinterpret_cast<uint8_t*>(out_elems);
    const auto* key_u8 = reinterpret_cast<const uint8_t*>(key_elems);

    if (expected_plain_len < 0) {
        result = DELTA_ERR_INPUT_TOO_SHORT; // -7 (0x002240)
    } else if (enc_u8[0] != kDeltaMagicByte0 || enc_u8[1] != kDeltaMagicByte1) {
        // 0x002248..0x00225c: ldrb w8, [x24]; cmp w8, #0xbd; ldrb w8, [x24,#1]; cmp w8, #1
        result = DELTA_ERR_INVALID_MAGIC;   // -8 (0x002274)
    } else if (expected_plain_len > out_cap) {
        result = DELTA_ERR_BUFFER_TOO_SMALL; // -4 (0x00226c)
    } else {
        EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new(); // 0x002300
        int outl = 0;
        int final_outl = 0;
        const uint8_t* iv_ptr  = enc_u8 + kDeltaHeaderSize; // enc + 2 (0x002344)
        const uint8_t* ct_ptr  = enc_u8 + kDeltaCiphertextOffset; // enc + 0x12 (0x002364)
        const uint8_t* tag_ptr = iv_ptr + (enc_len - kDeltaCiphertextOffset); // enc + enc_len - 16 (0x002390..0x00239c)

        bool ok = false;
        if (ctx &&
            EVP_DecryptInit_ex(ctx, EVP_aes_256_gcm(), nullptr, nullptr, nullptr) != 0 && // 0x002320
            EVP_CIPHER_CTX_ctrl(ctx, kEvpCtrlGcmSetIvLen, kDeltaGcmIvSize, nullptr) != 0 && // 0x002338
            EVP_DecryptInit_ex(ctx, nullptr, nullptr, key_u8, iv_ptr) != 0 && // 0x002358
            EVP_DecryptUpdate(ctx, out_u8, &outl, ct_ptr, expected_plain_len) != 0 && // 0x002374
            outl == expected_plain_len && // 0x002384: cmp w8, w27
            EVP_CIPHER_CTX_ctrl(ctx, kEvpCtrlGcmSetTag, kDeltaGcmTagSize, const_cast<uint8_t*>(tag_ptr)) != 0 && // 0x0023a4
            EVP_DecryptFinal_ex(ctx, out_u8 + outl, &final_outl) != 0) { // 0x0023bc
            ok = true;
        }
        EVP_CIPHER_CTX_free(ctx); // 0x0023cc / 0x002418
        if (!ok) {
            result = DELTA_ERR_DECRYPT_FAILED; // -9 (0x0023d4 / 0x00241c)
        } else if (result >= 1 && result != out_cap) {
            // 0x0023f0..0x00240c: logs "r!=decrypted_len r=%d,decrypted_len=%d" (.rodata 0x00324f)
            DeltaLogPrint(7, "Delta", "r!=decrypted_len r=%d,decrypted_len=%d", result, out_cap);
        }
    }

    env->ReleaseByteArrayElements(out_decrypted_arr, out_elems, 0); // 0x002290
    env->ReleaseByteArrayElements(in_encrypted_arr, enc_elems, 0);  // 0x0022ac
    env->ReleaseByteArrayElements(aes_key_arr, key_elems, 0);       // 0x0022c8
    return result;
}

// ============================================================================
// [060] Java_net_bytedance_zdplib_Delta_getDecryptedLen (0x002430, 8 bytes)
//   0x002430: sub w0, w2, #0x22
//   0x002434: ret
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_getDecryptedLen(
    JNIEnv*,
    jobject,
    jint encrypted_len) {
    return encrypted_len - kDeltaPacketOverhead; // - 34 (0x22)
}

// ============================================================================
// [056] Java_net_bytedance_zdplib_Delta_getPublicKey (0x002438, 292 bytes)
// Disassembly (0x002438..0x002558):
//   - Checks GetArrayLength(out_pub_key_arr) == 0x21 (33); if not, logs
//     "public_key_len=%d" (.rodata 0x003276).
//   - Calls EC_KEY_get0_public_key(ec_key) (0x0024ac), gets/creates global
//     EC_GROUP* at .bss 0x008000 (0x0024b0..0x0024cc), and calls
//     EC_POINT_point2oct(group, pub_pt, POINT_CONVERSION_COMPRESSED = 2, out_buf, 0x21, NULL) (0x0024e8).
//   - Asserts result == 0x21 || result == 0x41 in public_key_to_bin (line 0x4c = 76).
//   - Releases byte array and returns 0 (wzr).
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_getPublicKey(
    JNIEnv* env,
    jobject,
    jbyteArray out_pub_key_arr,
    jlong ec_key_handle) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    jsize len = env->GetArrayLength(out_pub_key_arr); // 0x002464
    if (len != kPublicKeyLength) {                    // 0x002468: cmp w0, #0x21
        DeltaLogPrint(7, "Delta", "public_key_len=%d", len); // 0x002488 (.rodata 0x003276)
    }
    jbyte* out_elems = env->GetByteArrayElements(out_pub_key_arr, nullptr); // 0x0024a0
    auto* ec_key = reinterpret_cast<EC_KEY*>(ec_key_handle);
    const EC_POINT* pub_pt = EC_KEY_get0_public_key(ec_key); // 0x0024ac
    EC_GROUP* group = GetOrInitGlobalP256Group();            // 0x0024b0..0x0024cc (.bss 0x008000)

    size_t written = EC_POINT_point2oct(
        group,
        pub_pt,
        kPointConvCompressed,
        reinterpret_cast<uint8_t*>(out_elems),
        kPublicKeyLength,
        nullptr); // 0x0024d0..0x0024e8
    if (written != static_cast<size_t>(kPublicKeyLength) &&
        written != static_cast<size_t>(kUncompressPublicKeyLength)) {
        DeltaLogAssert(
            nullptr,
            "Delta",
            "%s(%d) >> %s ",
            "public_key_to_bin",
            0x4c,
            "result == PublicKeyLength || result == UncompressPublicKeyLength");
    }
    env->ReleaseByteArrayElements(out_pub_key_arr, out_elems, 0); // 0x002514
    return DELTA_OK;                                              // 0x002524: mov w0, wzr
}

// ============================================================================
// [071] Java_net_bytedance_zdplib_Delta_sign (0x00255c, 248 bytes)
// Disassembly (0x00255c..0x002650):
//   - Checks GetArrayLength(out_sig_arr) == 0x48 (72); else returns -4 (0x00263c).
//   - Gets elements for msg_arr and out_sig_arr, calls sign(sig_out, ec_key, msg, msg_len)
//     at 0x0025f4 (bl #0x3154), releases both arrays, and returns sig_len.
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_sign(
    JNIEnv* env,
    jobject,
    jbyteArray out_sig_arr,
    jlong ec_key_handle,
    jbyteArray msg_arr) {
    if (!env) return DELTA_ERR_BUFFER_TOO_SMALL;
    if (env->GetArrayLength(out_sig_arr) != kMaxEcdsaSignatureLength) { // 0x002590: cmp w0, #0x48
        return DELTA_ERR_BUFFER_TOO_SMALL;                              // 0x00263c: mov w0, #-4
    }
    jbyte* msg_elems = env->GetByteArrayElements(msg_arr, nullptr);     // 0x0025ac
    jbyte* sig_elems = env->GetByteArrayElements(out_sig_arr, nullptr); // 0x0025c8
    jsize  msg_len   = env->GetArrayLength(msg_arr);                    // 0x0025e0

    jint sig_len = sign_ecdsa_sha256(
        reinterpret_cast<uint8_t*>(sig_elems),
        reinterpret_cast<EC_KEY*>(ec_key_handle),
        reinterpret_cast<const uint8_t*>(msg_elems),
        msg_len); // 0x0025f4: bl #0x3154

    env->ReleaseByteArrayElements(msg_arr, msg_elems, 0);     // 0x002614
    env->ReleaseByteArrayElements(out_sig_arr, sig_elems, 0); // 0x002630
    return sig_len;                                           // 0x002634
}

// ============================================================================
// [072] Java_net_bytedance_zdplib_Delta_verify (0x002654, 568 bytes)
// Disassembly (0x002654..0x002888):
//   - Checks GetArrayLength(pub_key_arr) == 0x21 (33) or 0x41 (65);
//     if neither, logs "invalid pub_key" (.rodata 0x00323f) and returns -5 (0x002874).
//   - Checks 1 <= GetArrayLength(sig_arr) <= 0x48 (72) via:
//       0x0026d8: sub w8, w0, #1
//       0x0026dc: cmp w8, #0x47
//       0x0026e0: mov w22, #-0xb  (-11)
//       0x0026e4: b.hi #0x2828
//   - Calls create_EC_KEY_from_public_key_bin(pub_bytes, pub_len) (0x002778).
//   - Computes SHA-256(msg, msg_len) via SHA256_Init (0x002784), SHA256_Update (0x002794),
//     SHA256_Final (0x0027a0).
//   - Calls ECDSA_verify(0, digest, 0x20, sig_bytes, sig_len, ec_key) (0x0027c0).
//   - Selects return code: `cmp w0, #0; csel w22, w22 (-11), wzr (0), eq` (0x0027c4..0x0027cc).
//   - Frees ec_key (0x0027d0), releases all 3 byte arrays, and returns 0 or -11.
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_Delta_verify(
    JNIEnv* env,
    jobject,
    jbyteArray sig_arr,
    jbyteArray msg_arr,
    jbyteArray pub_key_arr) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    if (env->GetArrayLength(pub_key_arr) != kPublicKeyLength &&
        env->GetArrayLength(pub_key_arr) != kUncompressPublicKeyLength) { // 0x0026a0..0x0026c0
        DeltaLogPrint(6, "Delta", "invalid pub_key");                     // 0x002870
        return DELTA_ERR_INVALID_KEY_LEN;                                 // 0x002874: mov w22, #-5
    }

    jsize sig_len = env->GetArrayLength(sig_arr); // 0x0026d4
    // 0x0026d8..0x0026e4: sub w8, w0, #1; cmp w8, #0x47; mov w22, #-0xb; b.hi #0x2828
    if (static_cast<uint32_t>(sig_len - 1) > 0x47U) {
        return DELTA_ERR_VERIFY_FAILED; // -11 (-0xb)
    }

    jbyte* pub_elems = env->GetByteArrayElements(pub_key_arr, nullptr); // 0x002700
    jbyte* sig_elems = env->GetByteArrayElements(sig_arr, nullptr);     // 0x002720
    jbyte* msg_elems = env->GetByteArrayElements(msg_arr, nullptr);     // 0x00273c
    jsize  msg_len   = env->GetArrayLength(msg_arr);                    // 0x002754
    jsize  pub_len   = env->GetArrayLength(pub_key_arr);                // 0x00276c

    EC_KEY* ec_key = create_EC_KEY_from_public_key_bin(
        reinterpret_cast<const uint8_t*>(pub_elems), pub_len); // 0x002778

    SHA256_CTX sha_ctx; // sp + 0x30 (0x002780)
    SHA256_Init(&sha_ctx); // 0x002784
    SHA256_Update(&sha_ctx, msg_elems, static_cast<size_t>(msg_len)); // 0x002794

    uint8_t digest[32]; // sp + 0x10 (0x002798)
    SHA256_Final(digest, &sha_ctx); // 0x0027a0

    int verify_ok = ECDSA_verify(
        0,
        digest,
        kSha256DigestLength,
        reinterpret_cast<const uint8_t*>(sig_elems),
        static_cast<size_t>(sig_len),
        ec_key); // 0x0027c0

    // 0x0027c4..0x0027cc: cmp w0, #0; csel w22, w22 (-11), wzr (0), eq
    jint result = (verify_ok == 0) ? DELTA_ERR_VERIFY_FAILED : DELTA_OK;

    EC_KEY_free(ec_key); // 0x0027d0
    env->ReleaseByteArrayElements(sig_arr, sig_elems, 0);         // 0x0027ec
    env->ReleaseByteArrayElements(msg_arr, msg_elems, 0);         // 0x002808
    env->ReleaseByteArrayElements(pub_key_arr, pub_elems, 0);     // 0x002824
    return result;
}

// ============================================================================
// [073] Java_net_bytedance_zdplib_DeltaSignerVerifier_initPrivateKey (0x00288c, 140 bytes)
// ============================================================================
JNIEXPORT jlong JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_initPrivateKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray priv_key_arr) {
    return Java_net_bytedance_zdplib_Delta_initPrivateKey(env, thiz, priv_key_arr);
}

// ============================================================================
// [059] Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey (0x002918, 292 bytes)
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_pub_key_arr,
    jlong ec_key_handle) {
    return Java_net_bytedance_zdplib_Delta_getPublicKey(env, thiz, out_pub_key_arr, ec_key_handle);
}

// ============================================================================
// [067] Java_net_bytedance_zdplib_DeltaSignerVerifier_sign (0x002a3c, 248 bytes)
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_sign(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_sig_arr,
    jlong ec_key_handle,
    jbyteArray msg_arr) {
    return Java_net_bytedance_zdplib_Delta_sign(env, thiz, out_sig_arr, ec_key_handle, msg_arr);
}

// ============================================================================
// [061] Java_net_bytedance_zdplib_DeltaSignerVerifier_verify (0x002b34, 4 bytes)
//   0x002b34: b #0x1890 (tail-calls Java_net_bytedance_zdplib_Delta_verify via PLT)
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_verify(
    JNIEnv* env,
    jobject thiz,
    jbyteArray sig_arr,
    jbyteArray msg_arr,
    jbyteArray pub_key_arr) {
    return Java_net_bytedance_zdplib_Delta_verify(env, thiz, sig_arr, msg_arr, pub_key_arr);
}

// ============================================================================
// [063] Java_net_bytedance_zdplib_DeltaSignerVerifier_free (0x002b38, 76 bytes)
// ============================================================================
JNIEXPORT void JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_free(
    JNIEnv* env,
    jobject thiz,
    jlong ec_key_handle) {
    Java_net_bytedance_zdplib_Delta_free(env, thiz, ec_key_handle);
}

// ============================================================================
// [057] Java_net_bytedance_zdplib_DeltaSignerVerifier_generatePrivateKey (0x002b84, 100 bytes)
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_generatePrivateKey(
    JNIEnv* env,
    jobject thiz,
    jbyteArray out_priv_key_arr) {
    return Java_net_bytedance_zdplib_Delta_generatePrivateKey(env, thiz, out_priv_key_arr);
}

// ============================================================================
// [062] Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed (0x002be8, 292 bytes)
// Disassembly (0x002be8..0x002d08):
//   - Checks GetArrayLength(out_pub_key_arr) == 0x41 (65); if not, logs
//     "public_key_len=%d" (.rodata 0x003276).
//   - Calls EC_KEY_get0_public_key(ec_key) (0x002c5c), gets/creates global
//     EC_GROUP* at .bss 0x008000 (0x002c60..0x002c7c), and calls
//     EC_POINT_point2oct(group, pub_pt, POINT_CONVERSION_UNCOMPRESSED = 4, out_buf, 0x41, NULL) (0x002c80..0x002c98).
//   - Asserts result == 0x21 || result == 0x41 in public_key_to_bin (line 0x4c = 76).
//   - Releases byte array and returns 0 (wzr).
// ============================================================================
JNIEXPORT jint JNICALL Java_net_bytedance_zdplib_DeltaSignerVerifier_getPublicKeyUncompressed(
    JNIEnv* env,
    jobject,
    jbyteArray out_pub_key_arr,
    jlong ec_key_handle) {
    if (!env) return DELTA_ERR_INVALID_KEY_LEN;
    jsize len = env->GetArrayLength(out_pub_key_arr); // 0x002c14
    if (len != kUncompressPublicKeyLength) {          // 0x002c18: cmp w0, #0x41
        DeltaLogPrint(7, "Delta", "public_key_len=%d", len); // 0x002c38
    }
    jbyte* out_elems = env->GetByteArrayElements(out_pub_key_arr, nullptr); // 0x002c50
    auto* ec_key = reinterpret_cast<EC_KEY*>(ec_key_handle);
    const EC_POINT* pub_pt = EC_KEY_get0_public_key(ec_key); // 0x002c5c
    EC_GROUP* group = GetOrInitGlobalP256Group();            // 0x002c60..0x002c7c (.bss 0x008000)

    size_t written = EC_POINT_point2oct(
        group,
        pub_pt,
        kPointConvUncompressed,
        reinterpret_cast<uint8_t*>(out_elems),
        kUncompressPublicKeyLength,
        nullptr); // 0x002c80..0x002c98 (form = 4, len = 0x41)
    if (written != static_cast<size_t>(kPublicKeyLength) &&
        written != static_cast<size_t>(kUncompressPublicKeyLength)) {
        DeltaLogAssert(
            nullptr,
            "Delta",
            "%s(%d) >> %s ",
            "public_key_to_bin",
            0x4c,
            "result == PublicKeyLength || result == UncompressPublicKeyLength");
    }
    env->ReleaseByteArrayElements(out_pub_key_arr, out_elems, 0); // 0x002cc4
    return DELTA_OK;                                              // 0x002cd4: mov w0, wzr
}

} // extern "C"
