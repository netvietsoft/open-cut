// ============================================================================
// File: delta_types.h
// Library: libdelta.so (ARM64-v8a, 18,256 bytes, 71 dynamic symbols)
// Package: net.bytedance.zdplib (Zero-Data-Protection / Delta Crypto Engine)
// Task ID: TASK-090-RECONSTRUCTION-LIBDELTA (Target 51 / TASK_SO_159)
// Description:
//   EN: Exact ABI data structures, ELF64 memory map constants, BoringSSL/OpenSSL
//       P-256 & AES-256-GCM types, JNI vtable definitions, and wire packet
//       format constants reconstructed from libdelta.so.
//   VN: Các cấu trúc dữ liệu ABI chính xác, hằng số bản đồ bộ nhớ ELF64, kiểu
//       dữ liệu BoringSSL/OpenSSL P-256 & AES-256-GCM, định nghĩa bảng ảo JNI
//       và hằng số định dạng gói tin đường truyền tái tạo từ libdelta.so.
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <vector>

// ============================================================================
// EN: Minimal standalone JNI ABI declarations matching AArch64 Android NDK
//     offsets observed in libdelta.so:
//       - JNIEnv + 0x558 (index 171): GetArrayLength (0x001b78, 0x001cdc, ...)
//       - JNIEnv + 0x5c0 (index 184): GetByteArrayElements (0x001b98, 0x001d18, ...)
//       - JNIEnv + 0x600 (index 192): ReleaseByteArrayElements (0x001c18, 0x001f04, ...)
// VN: Khai báo ABI JNI độc lập khớp các độ lệch Android NDK AArch64 quan sát
//     được trong libdelta.so (+0x558, +0x5c0, +0x600).
// ============================================================================
#ifndef JNIEXPORT
#define JNIEXPORT __attribute__((visibility("default")))
#endif
#ifndef JNICALL
#define JNICALL
#endif

using jboolean = uint8_t;
using jbyte    = int8_t;
using jint     = int32_t;
using jsize    = jint;
using jlong    = int64_t;
using jobject  = void*;
using jclass   = void*;
using jbyteArray = void*;

constexpr jboolean JNI_FALSE = 0;
constexpr jboolean JNI_TRUE  = 1;

struct JNINativeInterface_Delta {
    void* reserved[171];
    // +0x558 (171 * 8)
    jsize (*GetArrayLength)(void* env, jobject array);
    void* pad_172_to_183[12];
    // +0x5c0 (184 * 8)
    jbyte* (*GetByteArrayElements)(void* env, jbyteArray array, jboolean* isCopy);
    void* pad_185_to_191[7];
    // +0x600 (192 * 8)
    void (*ReleaseByteArrayElements)(void* env, jbyteArray array, jbyte* elems, jint mode);
};

struct JNIEnv {
    const JNINativeInterface_Delta* functions;

    jsize GetArrayLength(jobject array) {
        return (functions && functions->GetArrayLength)
                   ? functions->GetArrayLength(this, array)
                   : 0;
    }
    jbyte* GetByteArrayElements(jbyteArray array, jboolean* isCopy) {
        return (functions && functions->GetByteArrayElements)
                   ? functions->GetByteArrayElements(this, array, isCopy)
                   : nullptr;
    }
    void ReleaseByteArrayElements(jbyteArray array, jbyte* elems, jint mode) {
        if (functions && functions->ReleaseByteArrayElements) {
            functions->ReleaseByteArrayElements(this, array, elems, mode);
        }
    }
};

namespace bytedance {
namespace zdplib {
namespace delta {

// ============================================================================
// EN: ELF64 Segment & Section Layout Constants of libdelta.so (18,256 bytes)
//     - PT_LOAD 0 (R+X): vaddr 0x000000..0x0038e8 -> file 0x000000..0x0038e8
//     - PT_LOAD 1 (R+W): vaddr 0x007c60..0x008008 -> file 0x003c60..0x004000
//       (file_offset = vaddr - 0x4000)
//     - .plt:            vaddr 0x001830..0x001b00 (size 0x0002d0 = 720 bytes)
//     - .text:           vaddr 0x001b00..0x00322c (size 0x00172c = 5,932 bytes)
//     - .rodata:         vaddr 0x00322c..0x003423 (size 0x0001f7 = 503 bytes)
//     - .fini_array:     vaddr 0x007c60..0x007c70 (size 0x000010 = 16 bytes)
//     - .data.rel.ro:    vaddr 0x007c70..0x007c78 (__dso_handle = 0x007c70)
//     - .got:            vaddr 0x007e88..0x008000 (size 0x000178 = 376 bytes)
//     - .bss:            vaddr 0x008000..0x008008 (8B cached EC_GROUP* pointer)
// VN: Các hằng số bố cục phân đoạn & section ELF64 của libdelta.so (18.256 byte)
// ============================================================================
constexpr uint64_t kLibDeltaFileSize        = 18256ULL;
constexpr uint64_t kLibDeltaPltVaddr        = 0x001830ULL;
constexpr uint64_t kLibDeltaTextVaddr       = 0x001b00ULL;
constexpr uint64_t kLibDeltaTextSize        = 0x00172cULL;
constexpr uint64_t kLibDeltaRodataVaddr     = 0x00322cULL;
constexpr uint64_t kLibDeltaRodataSize      = 0x0001f7ULL;
constexpr uint64_t kLibDeltaGotVaddr        = 0x007e88ULL;
constexpr uint64_t kLibDeltaBssGroupVaddr   = 0x008000ULL;

// ============================================================================
// EN: Cryptographic & Protocol Constants Verified in AArch64 Opcodes
//     - NID_X9_62_prime256v1 = 415 (0x19f):
//       `mov w0, #0x19f` at 0x0024c0, 0x0029a0, 0x002c70, 0x002d20, 0x002f18,
//       0x002f5c, 0x00308c
//     - POINT_CONVERSION_COMPRESSED = 2:
//       `mov w2, #2` at 0x0024d0, 0x0029b0; `mov w1, #2` at 0x002d60, 0x002f34
//     - POINT_CONVERSION_UNCOMPRESSED = 4:
//       `mov w2, #4` at 0x002c80
//     - PrivateKeyLength / AesKeyLength / Sha256DigestLength = 32 (0x20):
//       `cmp w0, #0x20` at 0x001b80, 0x001ce4, 0x0020b4, 0x0028b4
//     - PublicKeyLength (Compressed) = 33 (0x21):
//       `cmp w0, #0x21` at 0x001fd8, 0x002468, 0x0026a0, 0x002948, 0x002f40
//     - UncompressPublicKeyLength = 65 (0x41):
//       `cmp w0, #0x41` at 0x001ff4, 0x0024f4, 0x0026bc, 0x002c18, 0x002f48
//     - MaxSignatureLength = 72 (0x48):
//       `cmp w0, #0x48` at 0x002590, 0x002a70; `sub w8, w0, #1; cmp w8, #0x47` at 0x0026d8..0x0026dc
// VN: Các hằng số mật mã & giao thức được xác minh trực tiếp trong mã máy AArch64
// ============================================================================
constexpr int      kNidPrime256v1             = 0x19f; // 415 (NID_X9_62_prime256v1)
constexpr int      kPointConvCompressed       = 2;     // POINT_CONVERSION_COMPRESSED
constexpr int      kPointConvUncompressed     = 4;     // POINT_CONVERSION_UNCOMPRESSED

constexpr int32_t  kPrivateKeyLength          = 0x20;  // 32 bytes
constexpr int32_t  kAes256KeyLength           = 0x20;  // 32 bytes
constexpr int32_t  kSha256DigestLength        = 0x20;  // 32 bytes
constexpr int32_t  kPublicKeyLength           = 0x21;  // 33 bytes (compressed SEC1)
constexpr int32_t  kUncompressPublicKeyLength = 0x41;  // 65 bytes (uncompressed SEC1)
constexpr int32_t  kMaxEcdsaSignatureLength   = 0x48;  // 72 bytes (DER ECDSA signature)

// ============================================================================
// EN: Delta AES-256-GCM Wire Packet Format (34-byte = 0x22 overhead)
//     Verified from:
//       - getEncryptedLen (0x001f5c): `add w0, w2, #0x22`
//       - getDecryptedLen (0x002430): `sub w0, w2, #0x22`
//       - encrypt (0x001df0..0x001ec0):
//         * Offset +0x00..+0x01 (2B):  Magic Header = 0x01bd (LE: [0xbd, 0x01])
//           (`mov w8, #0x1bd; strh w8, [x23]` @ 0x001df0..0x001dfc)
//         * Offset +0x02..+0x11 (16B): Random 128-bit GCM IV
//           (`RAND_bytes(sp+0x18, 0x10); ldur q0, [sp,#0x18]; stur q0, [x23,#2]` @ 0x001df8..0x001e08)
//         * Offset +0x12..+0x12+N-1:   AES-256-GCM Ciphertext (N bytes)
//           (`add x1, x23, #0x12; bl EVP_EncryptUpdate` @ 0x001e6c..0x001e80)
//         * Offset +0x12+N..+0x22+N-1: 16-byte AES-256-GCM Authentication Tag
//           (`mov w1, #0x10; mov w2, #0x10; bl EVP_CIPHER_CTX_ctrl` @ 0x001eb0..0x001ec0)
//       - decrypt (0x002248..0x0023a4):
//         * Checks `cipher[0] == 0xbd` (`cmp w8, #0xbd` @ 0x00224c) and
//           `cipher[1] == 0x01` (`cmp w8, #1` @ 0x002258).
//         * Reads 16B IV from `cipher + 2` (`add x4, x24, #2` @ 0x002344),
//           ciphertext from `cipher + 0x12` (`add x3, x24, #0x12` @ 0x002364),
//           and 16B tag from `(cipher + 2) + (cipher_len - 0x12) = cipher + cipher_len - 16`
//           (`sub w8, w28, #0x12; add x3, x9, w8, sxtw` @ 0x002390..0x00239c).
// VN: Định dạng gói tin đường truyền AES-256-GCM của Delta (bù 34 byte = 0x22)
// ============================================================================
constexpr uint16_t kDeltaPacketMagicLE        = 0x01bdU; // [0xbd, 0x01]
constexpr uint8_t  kDeltaMagicByte0           = 0xbdU;   // 0x00224c: cmp w8, #0xbd
constexpr uint8_t  kDeltaMagicByte1           = 0x01U;   // 0x002258: cmp w8, #1
constexpr int32_t  kDeltaHeaderSize           = 2;       // 2-byte magic
constexpr int32_t  kDeltaGcmIvSize            = 0x10;    // 16-byte IV (offset +2..+17)
constexpr int32_t  kDeltaCiphertextOffset     = 0x12;    // offset +18
constexpr int32_t  kDeltaGcmTagSize           = 0x10;    // 16-byte GCM tag
constexpr int32_t  kDeltaPacketOverhead       = 0x22;    // 2 + 16 + 16 = 34 bytes

// EVP_CIPHER_CTX_ctrl commands verified at 0x001e34, 0x001eb0, 0x00232c, 0x002394
constexpr int      kEvpCtrlGcmSetIvLen        = 0x09;    // EVP_CTRL_GCM_SET_IVLEN
constexpr int      kEvpCtrlGcmGetTag          = 0x10;    // EVP_CTRL_GCM_GET_TAG
constexpr int      kEvpCtrlGcmSetTag          = 0x11;    // EVP_CTRL_GCM_SET_TAG

// ============================================================================
// EN: Exact Delta Error Return Codes Verified from AArch64 Instructions
//     -  0: Success (`mov w0, wzr`)
//     - -2: HKDF key derivation failure (`mov w9, #-2` @ 0x001bf8)
//     - -3: AES-256-GCM encryption failure (`mov w8, #-3` @ 0x001ed4, 0x001ee8)
//     - -4: Output buffer too small / invalid sig buf (`mov w26, #-4` @ 0x001d94,
//           `mov w27, #-4` @ 0x00226c, `mov w0, #-4` @ 0x00263c, 0x002b1c)
//     - -5: Invalid key length (`mov w0, #-5` @ 0x001c3c, `mov w26, #-5` @ 0x001d9c,
//           `mov x21, #-5` @ 0x002074, 0x002100, 0x002900, `mov w22, #-5` @ 0x002874)
//     - -7: Plaintext/Ciphertext too short (`mov w26, #-7` @ 0x001dd4,
//           `mov w27, #-7` @ 0x002240)
//     - -8: Invalid Delta packet magic header (`mov w27, #-8` @ 0x002274)
//     - -9: AES-256-GCM decryption / tag auth failure (`mov w8, #-9` @ 0x0023d4,
//           `mov w27, #-9` @ 0x00241c)
//     - -11 (-0xb): Invalid ECDSA signature length or verification failure
//           (`mov w22, #-0xb` @ 0x0026e0, `csel w22, w22, wzr, eq` @ 0x0027cc)
// VN: Bảng mã lỗi trả về chính xác của Delta xác minh từ tập lệnh AArch64
// ============================================================================
enum DeltaErrorCode : int32_t {
    DELTA_OK                     =  0,
    DELTA_ERR_HKDF_FAILED        = -2,   // 0x001bf8
    DELTA_ERR_ENCRYPT_FAILED     = -3,   // 0x001ed4, 0x001ee8
    DELTA_ERR_BUFFER_TOO_SMALL   = -4,   // 0x001d94, 0x00226c, 0x00263c, 0x002b1c
    DELTA_ERR_INVALID_KEY_LEN    = -5,   // 0x001c3c, 0x001d9c, 0x002074, 0x002100, 0x002874, 0x002900
    DELTA_ERR_INPUT_TOO_SHORT    = -7,   // 0x001dd4, 0x002240
    DELTA_ERR_INVALID_MAGIC      = -8,   // 0x002274
    DELTA_ERR_DECRYPT_FAILED     = -9,   // 0x0023d4, 0x00241c
    DELTA_ERR_VERIFY_FAILED      = -11   // 0x0026e0 (-0xb)
};

// ============================================================================
// EN: Exact .rodata String Table (vaddr 0x00322c..0x003422, 503 bytes)
// VN: Bảng hằng chuỗi .rodata chính xác (vaddr 0x00322c..0x003422, 503 byte)
// ============================================================================
struct DeltaRodataEntry {
    uint32_t    vaddr;
    const char* text;
};

static constexpr DeltaRodataEntry kDeltaRodataStrings[] = {
    {0x00322c, "ephemeral_key is 0"},
    {0x00323f, "invalid pub_key"},
    {0x00324f, "r!=decrypted_len r=%d,decrypted_len=%d"},
    {0x003276, "public_key_len=%d"},
    {0x003288, "Delta"},
    {0x00328e, "%s(%d) >> %s "},
    {0x00329c, "bin_to_public_key"},
    {0x0032ae, "key_length == UncompressPublicKeyLength || key_length == PublicKeyLength"},
    {0x0032f7, "public_key_to_bin"},
    {0x003309, "result == PublicKeyLength || result == UncompressPublicKeyLength"},
    {0x00334a, "bin_to_private_key"},
    {0x00335d, "priv_key != NULL"},
    {0x00336e, "private_key_to_bin"},
    {0x003381, "result == 1"},
    {0x00338d, "encapsulates_aes_key"},
    {0x0033a2, "r != 0"},
    {0x0033a9, "create_EC_KEY_from_private_key_bin"},
    {0x0033cc, "ec_key != NULL"},
    {0x0033db, "pub_key != NULL"},
    {0x0033eb, "create_EC_KEY_from_public_key_bin"},
    {0x00340d, "generate_keypair"},
    {0x00341e, "sign"}
};

// ============================================================================
// EN: BoringSSL / OpenSSL Compatible ABI Structures Used by libdelta.so
//     1. SHA256_CTX (112 bytes = 0x70, allocated on stack at sp+0x30 in
//        Delta_verify @ 0x002780 and sp+0x28 in sign @ 0x003178)
//     2. BIGNUM (256-bit big-endian integer representation for NIST P-256)
//     3. EC_GROUP (NIST P-256 group descriptor, singleton cached at .bss 0x008000)
//     4. EC_POINT (Affine point (x, y) on NIST P-256 curve)
//     5. EC_KEY (Keypair holding EC_GROUP*, public EC_POINT*, private BIGNUM*,
//        and conversion form)
//     6. EVP_CIPHER_CTX (AES-256-GCM state context)
// VN: Các cấu trúc ABI tương thích BoringSSL / OpenSSL được libdelta.so sử dụng
// ============================================================================
struct SHA256_CTX {
    uint32_t h[8];            // +0x00..+0x1f: 256-bit state
    uint32_t Nl;              // +0x20: low bit count
    uint32_t Nh;              // +0x24: high bit count
    uint8_t  data[64];        // +0x28..+0x67: 512-bit message block
    uint32_t num;             // +0x68: bytes in buffer
    uint32_t md_len;          // +0x6c: 32 (SHA256_DIGEST_LENGTH)
};
static_assert(sizeof(SHA256_CTX) == 0x70, "SHA256_CTX must be 112 bytes (0x70)");

struct BIGNUM {
    uint8_t bytes[32];        // 256-bit big-endian unsigned integer
    bool    is_zero;
};

struct EC_GROUP {
    int curve_nid;            // 0x19f = NID_X9_62_prime256v1
};

struct EC_POINT {
    uint8_t x[32];            // 256-bit big-endian X coordinate on P-256
    uint8_t y[32];            // 256-bit big-endian Y coordinate on P-256
    bool    infinity;
};

struct EC_KEY {
    EC_GROUP* group;          // Curve group (NID_X9_62_prime256v1)
    EC_POINT* pub_key;        // Public point Q = d * G
    BIGNUM*   priv_key;       // Private scalar d in [1, n-1]
    int       conv_form;      // POINT_CONVERSION_COMPRESSED (2) or UNCOMPRESSED (4)
};

struct EVP_CIPHER {
    int nid;                  // AES-256-GCM identifier
    int key_len;              // 32
    int iv_len;               // 12 or 16
};

struct EVP_MD {
    int type;                 // SHA-256 identifier
    int md_size;              // 32
};

struct EVP_CIPHER_CTX {
    const EVP_CIPHER* cipher;
    bool              encrypt;
    uint8_t           key[32];
    bool              has_key;
    uint8_t           iv[16];
    size_t            iv_len;
    bool              has_iv;
    uint8_t           tag[16];
    size_t            tag_len;
    bool              has_expected_tag;
    std::vector<uint8_t> buffer;
};

} // namespace delta
} // namespace zdplib
} // namespace bytedance
