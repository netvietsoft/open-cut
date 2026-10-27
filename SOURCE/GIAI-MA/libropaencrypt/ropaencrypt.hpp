// ============================================================================
// File: ropaencrypt.hpp
// Target: libropaencrypt.so (34,904 bytes, SHA-256: 1906ed4f2bf0b3621e90a1b502fb1c562cb73a4068cc8f2f734f05992d0436b3)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance ROPA AES-128-GCM / AES-128-CBC & Sequence Envelope Encryption Engine
//         (com/bytedance/ropa/encrypt/RopaEncrypt & EncryptResult)
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>
#include <string>
#include <vector>

namespace nextai::opencut::ropaencrypt {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của libropaencrypt.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 34904U;
inline constexpr const char* kBinarySha256Hex          = "1906ed4f2bf0b3621e90a1b502fb1c562cb73a4068cc8f2f734f05992d0436b3";
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x00005F68ULL;
inline constexpr std::size_t kEhFrameFdeCount          = 36U;
inline constexpr std::uint64_t kPltStartVa             = 0x00001040ULL;
inline constexpr std::size_t kPltSizeBytes             = 0x00000220ULL; // 544 bytes (32 PLT slots)
inline constexpr std::uint64_t kTextStartVa            = 0x00001260ULL;
inline constexpr std::uint64_t kTextEndVa              = 0x00005CF4ULL;
inline constexpr std::size_t kTextSizeBytes            = 19092U;        // 4,773 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 4773U;
inline constexpr std::uint64_t kRodataStartVa          = 0x00005CF4ULL;
inline constexpr std::size_t kRodataSizeBytes          = 0x00000274ULL; // 628 bytes
inline constexpr std::uint64_t kDataStartVa            = 0x0000C000ULL;
inline constexpr std::size_t kDataSizeBytes            = 0x000000C0ULL; // 192 bytes (8 JNINativeMethods)
inline constexpr std::uint64_t kBssStartVa             = 0x0000C0C0ULL;
inline constexpr std::size_t kBssSizeBytes             = 0x00000010ULL; // 16 bytes (0xC0C0..0xC0D0)

// ============================================================================
// 2. ROPA Error Codes & Cipher Constants (Observed in FDE[15..35])
//    Mã lỗi ROPA và hằng số mật mã học quan sát trong nhị phân
// ============================================================================
inline constexpr std::uint32_t kJniVersion1_6          = 0x00010006U;
inline constexpr std::int32_t  kRopaSuccess            = 0;
inline constexpr std::int32_t  kRopaErrInvalidParam    = -101; // -0x65 (0x25a4, 0x3568, 0x3fa0, 0x5b18)
inline constexpr std::int32_t  kRopaErrFormatTooShort  = -102; // -0x66 (0x3fd0)
inline constexpr std::int32_t  kRopaErrBase64Decode    = -104; // -0x68 (0x24e8)
inline constexpr std::int32_t  kRopaErrBase64Encode    = -106; // -0x6A (0x2430)
inline constexpr std::int32_t  kRopaErrCipherFailed    = -201; // -0xC9 (0x54a4)

// Permutation & Obfuscation Constants at .rodata 0x5F46..0x5F4F
// Bảng hằng số hoán vị 6 byte tại .rodata 0x5F46: {0x00, 0x0B, 0x29, 0x07, 0x12, 0x00}
inline constexpr std::array<std::uint8_t, 6> kRopaPermutationTable_5f46 = {
    0x00U, 0x0BU, 0x29U, 0x07U, 0x12U, 0x00U
};
inline constexpr std::uint32_t kRopaDefaultKeyLen_5f4c = 16U; // 0x10000000 little-endian @ 0x5F4C

// ============================================================================
// 3. JNI Registration & Global State Structures (.data 0xC000 & .bss 0xC0C0)
//    Cấu trúc bảng đăng ký JNI (.data 0xC000) và biến toàn cục (.bss 0xC0C0)
// ============================================================================
struct RopaJniNativeMethodDesc {
    std::uint64_t name_va;
    const char*   name;
    std::uint64_t signature_va;
    const char*   signature;
    std::uint64_t fn_va;
};

struct RopaEncryptResultValue {
    std::int32_t code;
    std::string  data;
};

struct RopaGlobalState {
    void* encrypt_result_cls_c0c0;  // .bss 0xC0C0: jclass com/bytedance/ropa/encrypt/EncryptResult
    void* encrypt_result_ctor_c0c8; // .bss 0xC0C8: jmethodID <init>(ILjava/lang/String;)V
};

// ============================================================================
// 4. FunctionDescriptor — Entry in the 36-FDE .eh_frame_hdr Table (0x5F68)
//    Mô tả hàm trong bảng 36 FDE tại .eh_frame_hdr (0x5F68)
// ============================================================================
struct FunctionDescriptor {
    std::uint32_t fde_index;
    std::uint64_t start_va;
    std::uint64_t end_va;
    std::uint32_t size_bytes;
    std::uint64_t fde_va;
    const char*   symbol_name;
    const char*   description;
};

extern const std::array<RopaJniNativeMethodDesc, 8> kRopaJniMethods_c000;
extern const std::array<FunctionDescriptor, kEhFrameFdeCount> kFunctionTable;
extern const std::array<std::uint32_t, kTextInstructionCount> kTextInstructionWords;
extern const std::array<std::uint8_t, kRodataSizeBytes> kRodataBytes_5cf4;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

// ============================================================================
// 5. Clean-Room Reconstructed C/C++17 & JNI Functions
//    Khai báo các hàm C/C++17 và JNI được tái tạo phòng sạch
// ============================================================================
RopaGlobalState& GetGlobalState() noexcept;

// FDE[13] 0x231c..0x2378 (92 bytes): Random seed & integer generator
std::int32_t RopaGenerateRandomInt_231c() noexcept;

// FDE[14] 0x2378..0x23cc (84 bytes): 16-byte lowercase hex key derivation
void RopaDerive16ByteHexKey_2378(std::uint32_t seed, char out_key[17]) noexcept;

// FDE[15] 0x23cc..0x2488 (188 bytes): Base64 encode
int RopaBase64Encode_23cc(const std::vector<std::uint8_t>& input, std::vector<std::uint8_t>& output) noexcept;

// FDE[16] 0x2488..0x2548 (192 bytes): Base64 decode
int RopaBase64Decode_2488(const std::vector<std::uint8_t>& input, std::vector<std::uint8_t>& output) noexcept;

// FDE[17] 0x2548..0x257c (52 bytes): Base-31 polynomial rolling hash
std::int32_t RopaComputeHash31_2548(const char* data, std::uint32_t len) noexcept;

// FDE[21] 0x3f3c..0x3f78 (60 bytes): Base-10 unsigned decimal parser
std::uint32_t RopaParseDecimalUint_3f3c(const char* str, std::uint8_t len) noexcept;

// FDE[18] 0x257c..0x31b4 (3,128 bytes): V2 sequence envelope builder
int RopaBuildEncryptSeqV2_257c(
    const char* token,
    std::uint32_t token_len,
    int flag,
    const char* extra,
    std::uint32_t extra_len,
    std::vector<std::uint8_t>& out_seq) noexcept;

// FDE[20] 0x3540..0x3f3c (2,556 bytes): V1 sequence envelope builder
int RopaBuildEncryptSeqV1_3540(
    const char* token,
    std::uint32_t token_len,
    bool use_rand,
    std::vector<std::uint8_t>& out_seq) noexcept;

// FDE[22] 0x3f78..0x4898 (2,336 bytes): V0/V1 sequence envelope parser & decryptor
int RopaParseDecryptSeq_3f78(
    const char* seq,
    std::uint32_t seq_len,
    std::vector<std::uint8_t>& out_plain) noexcept;

// FDE[33] 0x547c..0x5a1c (1,440 bytes): EVP AES-128-GCM / AES-128-CBC core
int RopaEvpAesCipherCore_547c(
    std::vector<std::uint8_t>& out_buf,
    int encrypt_flag,
    const std::uint8_t* in_data,
    std::uint32_t in_len,
    const std::uint8_t* aad_data,
    std::uint32_t aad_len,
    const char* cipher_alg,
    int mode_flag,
    const std::uint8_t* key_data,
    std::uint32_t key_len,
    const std::uint8_t* iv_data,
    std::uint32_t iv_len) noexcept;

// FDE[34] 0x5a1c..0x5af0 (212 bytes): Encrypt + Base64 encode
int RopaCipherEncryptBase64_5a1c(
    const std::uint8_t* in_data,
    std::uint32_t in_len,
    const std::uint8_t* aad_data,
    std::uint32_t aad_len,
    const char* cipher_alg,
    int mode_flag,
    const std::uint8_t* key_data,
    std::uint32_t key_len,
    const std::uint8_t* iv_data,
    std::uint32_t iv_len,
    std::vector<std::uint8_t>& out_b64) noexcept;

// FDE[35] 0x5af0..0x5cf4 (516 bytes): Base64 decode + Decrypt
int RopaCipherDecryptBase64_5af0(
    const char* cipher_alg,
    int mode_flag,
    const std::uint8_t* key_data,
    std::uint32_t key_len,
    const std::uint8_t* b64_in,
    std::uint32_t b64_len,
    const std::uint8_t* iv_data,
    std::uint32_t iv_len,
    const std::uint8_t* aad_data,
    std::uint32_t aad_len,
    std::vector<std::uint8_t>& out_plain) noexcept;

extern "C" {

// FDE[12] 0x21fc..0x231c (288 bytes) — Exported JNI_OnLoad
int JNI_OnLoad(void* java_vm, void* reserved) noexcept;

} // extern "C"

} // namespace nextai::opencut::ropaencrypt
