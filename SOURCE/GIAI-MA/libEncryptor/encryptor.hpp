// ============================================================================
// File: encryptor.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libEncryptor.so (83,896 bytes)
// SHA-256: 6ffd80242ce93782454b9e76521f81526debe01d60f27a88c68da4f114c15dcb
// Task ID: TASK-193-RECONSTRUCTION-LIBENCRYPTOR (TASK_SO_137_libEncryptor)
// Architecture: AArch64 (ARM64-v8a) — 41 FDEs (.eh_frame_hdr @ 0x106e8), 7,268 .text insns
// Clean-Room C++17 Header: ByteDance Applog Telemetry White-Box AES-128 & SHA-512
// Encryptor (com/bytedance/frameworks/encryptor/EncryptorUtil.ttEncrypt([BI)[B)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, white-box AES
// lookup table geometry (.rodata @ 0x7c50, 35,480 bytes), SHA-512 state, and JNI_OnLoad.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI, hình học
// bảng tra cứu AES hộp trắng (.rodata @ 0x7c50, 35.480 byte), trạng thái SHA-512 và JNI_OnLoad.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace encryptor {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 83896ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x08a0ULL;
constexpr std::uint64_t kPltSectionSize      = 0x00c0ULL; // 192 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x0960ULL;
constexpr std::uint64_t kTextSectionSize     = 0x7190ULL; // 29,072 bytes (7,268 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x7c50ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x8a98ULL; // 35,480 bytes (White-Box AES T-Boxes & SHA-512 K)
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x106e8ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x0154ULL; // 340 bytes (41 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x10840ULL;
constexpr std::uint64_t kEhFrameSize         = 0x0518ULL; // 1,304 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x17d00ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x0078ULL; // 120 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x18000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x0020ULL; // 32 bytes (JNINativeMethod table)
constexpr std::uint64_t kBssSectionVaddr     = 0x18020ULL;
constexpr std::uint64_t kBssSectionSize      = 0x0038ULL; // 56 bytes

constexpr std::uint64_t kJniOnLoadVaddr      = 0x099cULL;
constexpr std::uint16_t kTtEncryptMagicHeader = 0x0172U; // 0x72, 0x01 ("r\x01" Applog v1.2 header)

// ============================================================================
// [EN] 2. Applog ttEncrypt Packet Header & White-Box AES-128 CBC Context ABI
// [VN] 2. Cấu trúc ABI Tiêu Đề Gói Tin ttEncrypt & Ngữ Cảnh AES-128 CBC Hộp Trắng
// ============================================================================
struct TtEncryptPacketHeader {
    std::uint8_t magic[2];        // +0x00: { 0x72, 0x01 } magic tag
    std::uint8_t random_seed[16]; // +0x02: 16-byte PRNG salt used for SHA-512 KDF
    std::uint8_t iv[16];          // +0x12: 16-byte CBC initialization vector
};

struct Sha512StateAbi {
    std::uint64_t h[8];           // +0x00: 512-bit chaining state
    std::uint64_t total_len[2];   // +0x40: 128-bit bit-length counter
    std::uint8_t  block[128];     // +0x50: 1024-bit message block buffer
    std::uint32_t block_used;     // +0xd0: Bytes buffered in current block
    std::uint32_t reserved;       // +0xd4: 8-byte alignment padding
};
static_assert(sizeof(Sha512StateAbi) == 0xd8, "Sha512StateAbi size must be 216 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[41];
extern const std::uint32_t kTextInstructions[7268];
extern const std::uint8_t kElfImageBytes[83896];

// ============================================================================
// [EN] 3. Core Clean-Room Cryptographic & JNI Function Declarations
// [VN] 3. Khai báo các hàm mật mã & JNI C++17 phòng sạch cốt lõi
// ============================================================================
void WhiteBoxAes128EncryptBlock(const std::uint8_t in_block[16],
                                const std::uint8_t round_salt[16],
                                std::uint8_t out_block[16]) noexcept;
std::size_t TtEncryptPayloadCbcPkcs7(const std::uint8_t* plaintext, std::size_t plain_len,
                                     const std::uint8_t seed_32[32],
                                     std::uint8_t* out_packet, std::size_t max_out_len) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace encryptor
} // namespace bytedance

extern "C" {
int JNI_OnLoad(void* vm, void* reserved);
}
