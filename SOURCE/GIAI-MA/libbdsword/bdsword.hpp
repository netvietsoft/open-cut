// ============================================================================
// File: bdsword.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libbdsword.so (134,504 bytes)
// SHA-256: c9369ebdd087e79a30b8a9cf5baeb60bd7234b7b7bd80279e88268deddc0b868
// Task ID: TASK-196-RECONSTRUCTION-LIBBDSWORD (TASK_SO_130_libbdsword)
// Architecture: AArch64 (ARM64-v8a) — 166 FDEs (.eh_frame_hdr @ 0x1d4a4), 23,708 .text insns
// Clean-Room C++17 Header: ByteDance BD-Sword Security, Anti-Tamper & Environment
// Attestation Engine (JNI_OnLoad @ 0x3174, bdsword_command @ 0xbc38, 17,876-byte .rodata)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, BD-Sword command
// packet framing, white-box cipher context, and exported symbols JNI_OnLoad / bdsword_command.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI, gói tin lệnh
// BD-Sword, ngữ cảnh mã hóa hộp trắng và các biểu tượng xuất khẩu JNI_OnLoad / bdsword_command.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace bdsword {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 134504ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x01b80ULL;
constexpr std::uint64_t kPltSectionSize      = 0x000e0ULL; // 224 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x01c60ULL;
constexpr std::uint64_t kTextSectionSize     = 0x17270ULL; // 94,832 bytes (23,708 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x18ed0ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x045d4ULL; // 17,876 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x1d4a4ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x0053cULL; // 1,340 bytes (166 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x1d9e0ULL;
constexpr std::uint64_t kEhFrameSize         = 0x01338ULL; // 4,920 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x23790ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x005e8ULL; // 1,512 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x24000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x004c0ULL; // 1,216 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x244c0ULL;
constexpr std::uint64_t kBssSectionSize      = 0x00328ULL; // 808 bytes

constexpr std::uint64_t kJniOnLoadVaddr      = 0x03174ULL;
constexpr std::uint64_t kBdSwordCommandVaddr = 0x0bc38ULL;

// ============================================================================
// [EN] 2. BD-Sword Command Context & Attestation Token ABI Structures
// [VN] 2. Cấu trúc ABI Ngữ Cảnh Lệnh BD-Sword & Mã Thông Báo Chứng Thực
// ============================================================================
struct BdSwordCommandFrameAbi {
    std::uint32_t command_id;       // +0x00: Opcode selector dispatched by bdsword_command
    std::uint32_t flags;            // +0x04: Execution mode flags
    const std::uint8_t* input_ptr;  // +0x08: Input payload buffer
    std::size_t   input_len;        // +0x10: Input payload byte length
    std::uint8_t* output_ptr;       // +0x18: Output attestation buffer
    std::size_t   output_capacity;  // +0x20: Output capacity in bytes
    std::size_t   output_written;   // +0x28: Bytes written by command handler
};
static_assert(sizeof(BdSwordCommandFrameAbi) == 0x30, "BdSwordCommandFrameAbi size must be 48 bytes");

struct BdSwordRuntimeStateAbi {
    std::uint64_t init_magic;       // +0x00: Initialization guard
    std::uint64_t env_flags;        // +0x08: Environment integrity bitmask
    std::uint32_t command_counter;  // +0x10: Number of commands processed
    std::uint32_t last_error_code;  // +0x14: Last command status code
    std::uint8_t  session_key[32];  // +0x18: 256-bit white-box session key
};
static_assert(sizeof(BdSwordRuntimeStateAbi) == 0x38, "BdSwordRuntimeStateAbi size must be 56 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[166];
extern const std::uint32_t kTextInstructions[23708];
extern const std::uint8_t kElfImageBytes[134504];

void BdSwordXorDeobfuscateString(std::size_t rodata_off, std::size_t len,
                                 std::uint8_t key_seed, char* out_str) noexcept;
int BdSwordExecuteCommandInternal(BdSwordCommandFrameAbi* frame) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace bdsword
} // namespace bytedance

extern "C" {
int JNI_OnLoad(void* vm, void* reserved);
int bdsword_command(int cmd, const void* in_arg, void* out_arg);
}
