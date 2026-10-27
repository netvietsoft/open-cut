// ============================================================================
// File: pglarmor.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libpglarmor.so (68,776 bytes)
// SHA-256: 69218eb7accd450feb707bfe9fa6533c390a2c0bf63b5c685c5548c18a0fe716
// Task ID: TASK-192-RECONSTRUCTION-LIBPGLARMOR (TASK_SO_061_libpglarmor)
// Architecture: AArch64 (ARM64-v8a) — 42 FDEs (.eh_frame_hdr @ 0x2c7c), 12,676 .text insns
// Clean-Room C++17 Header: ByteDance Pangle SDK Armor Cryptographic Engine
// (com.bytedance.sdk.component.pglcrypt.PglCryptUtils.bc, AES-GCM/CBC + GZIP/LZ4
//  Packet Framing, White-Box S-Box Tables @ .rodata 0x2070, Anti-Tamper Dispatch)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, Pangle armor
// packet headers, white-box AES state, and the JNI entry point PglCryptUtils_bc.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI,
// tiêu đề gói tin Pangle armor, trạng thái AES hộp trắng và điểm nhập JNI PglCryptUtils_bc.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace pglarmor {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 68776ULL;
constexpr std::uint64_t kRodataSectionVaddr  = 0x2070ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x0c0bULL; // 3,083 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x2c7cULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x015cULL; // 348 bytes (42 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x2dd8ULL;
constexpr std::uint64_t kEhFrameSize         = 0x050cULL; // 1,292 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x32e4ULL;
constexpr std::uint64_t kTextSectionSize     = 0xc610ULL; // 50,704 bytes (12,676 insns)
constexpr std::uint64_t kPltSectionVaddr     = 0xf900ULL;
constexpr std::uint64_t kPltSectionSize      = 0x00e0ULL; // 224 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x139e0ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x0700ULL; // 1,792 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x18330ULL;
constexpr std::uint64_t kDataSectionSize     = 0x0158ULL; // 344 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x18488ULL;
constexpr std::uint64_t kBssSectionSize      = 0x0014ULL; // 20 bytes

constexpr std::uint64_t kPglCryptUtilsBcVaddr = 0x3564ULL;

// ============================================================================
// [EN] 2. Pangle Armor Packet Header & White-Box AES-128/256 Context ABI
// [VN] 2. Cấu trúc ABI Tiêu Đề Gói Tin Pangle Armor & Ngữ Cảnh AES-128/256
// ============================================================================
struct PglArmorPacketHeader {
    std::uint32_t magic_version;      // +0x00: PGL armor version & cipher mode tag
    std::uint32_t uncompressed_size;  // +0x04: Original payload size in bytes
    std::uint32_t compressed_size;    // +0x08: Compressed/encrypted payload length
    std::uint32_t crc32_checksum;     // +0x0c: Integrity checksum over plaintext
    std::uint8_t  iv_nonce[16];       // +0x10: 128-bit IV / GCM nonce
};
static_assert(sizeof(PglArmorPacketHeader) == 0x20, "PglArmorPacketHeader ABI size must be 32 bytes");

struct PglArmorCipherContext {
    std::uint32_t round_keys[60];     // +0x00: Expanded AES round keys (up to 14 rounds)
    std::uint32_t nr_rounds;          // +0xf0: Number of rounds (10, 12, or 14)
    std::uint32_t command_mode;       // +0xf4: Command selector passed to PglCryptUtils_bc
    std::uint8_t  state_block[16];    // +0xf8: Current 128-bit cipher state block
    std::uint64_t total_processed;    // +0x108: Total bytes processed
};
static_assert(sizeof(PglArmorCipherContext) == 0x110, "PglArmorCipherContext ABI size must be 272 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[42];
extern const std::uint32_t kTextInstructions[12676];
extern const std::uint8_t kElfImageBytes[68776];

// ============================================================================
// [EN] 3. Core Clean-Room Cryptographic & Dispatch Function Declarations
// [VN] 3. Khai báo các hàm điều phối & mật mã C++17 phòng sạch cốt lõi
// ============================================================================
std::uint8_t GaloisMulGF256(std::uint8_t a, std::uint8_t b) noexcept;
void PglArmorMixColumns128(std::uint8_t state[16]) noexcept;
std::uint32_t PglArmorComputeCrc32(const std::uint8_t* data, std::size_t len) noexcept;
int PglCryptDispatchCommand_35a8(int cmd, const std::uint8_t* in_buf, std::size_t in_len,
                                 std::uint8_t* out_buf, std::size_t* out_len) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace pglarmor
} // namespace bytedance

extern "C" {
void* Java_com_bytedance_sdk_component_pglcrypt_PglCryptUtils_bc(
    void* env, void* clazz, int cmd, void* input_byte_array);
}
