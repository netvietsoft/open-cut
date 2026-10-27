// ============================================================================
// File: envguard.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libenvguard.so (224,680 bytes)
// SHA-256: 1e54f59bf1e158d86d01c2b5ebd5938950f2cc03981b7d1286302fddcab2bce5
// Task ID: TASK-199-RECONSTRUCTION-LIBENVGUARD (TASK_SO_124_libenvguard)
// Architecture: AArch64 (ARM64-v8a) — 123 FDEs (.eh_frame_hdr @ 0x27ce4), 11,656 .text insns
// Clean-Room C++17 Header: ByteDance EnvGuard Runtime Environment Attestation,
// ELF64 Header/Section Integrity Verifier, & Bytecode VM Table Engine
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures (EnvGuardContextAbi,
// Elf64HeaderCheckView), 136,340-byte .rodata constants (@ 0x6850), and JNI_OnLoad (@ 0x28d3c).
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI (EnvGuardContextAbi,
// Elf64HeaderCheckView), vùng hằng số .rodata 136.340 byte (@ 0x6850) và JNI_OnLoad (@ 0x28d3c).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace envguard {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 224680ULL;
constexpr std::uint64_t kRodataSectionVaddr  = 0x06850ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x21494ULL; // 136,340 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x27ce4ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x003e4ULL; // 996 bytes (123 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x280c8ULL;
constexpr std::uint64_t kEhFrameSize         = 0x00c24ULL; // 3,108 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x28cecULL;
constexpr std::uint64_t kTextSectionSize     = 0x0b620ULL; // 46,624 bytes (11,656 insns)
constexpr std::uint64_t kPltSectionVaddr     = 0x34310ULL;
constexpr std::uint64_t kPltSectionSize      = 0x00050ULL; // 80 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x38360ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x01db0ULL; // 7,600 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x3e310ULL;
constexpr std::uint64_t kDataSectionSize     = 0x00238ULL; // 568 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x3e548ULL;
constexpr std::uint64_t kBssSectionSize      = 0x00db1ULL; // 3,505 bytes

constexpr std::uint64_t kJniOnLoadVaddr      = 0x28d3cULL;

// ============================================================================
// [EN] 2. EnvGuard Context & ELF64 Integrity Verification ABI Structures
// [VN] 2. Cấu trúc ABI Ngữ Cảnh EnvGuard & Kiểm Tra Toàn Vẹn ELF64
// ============================================================================
struct Elf64HeaderCheckView {
    std::uint8_t  e_ident[16];     // +0x00: "\x7fELF\x02\x01\x01..."
    std::uint16_t e_type;          // +0x10: ET_DYN (3)
    std::uint16_t e_machine;       // +0x12: EM_AARCH64 (183 = 0xb7)
    std::uint32_t e_version;       // +0x14: EV_CURRENT (1)
    std::uint64_t e_entry;         // +0x18: Entry point virtual address
    std::uint64_t e_phoff;         // +0x20: Program header table offset
    std::uint64_t e_shoff;         // +0x28: Section header table offset
};
static_assert(sizeof(Elf64HeaderCheckView) == 0x30, "Elf64HeaderCheckView size must be 48 bytes");

struct EnvGuardContextAbi {
    std::uint32_t status_flags;    // +0x00: Bitmask of environment probe results
    std::uint32_t probe_count;     // +0x04: Number of completed probes
    std::uint64_t rodata_crc64;    // +0x08: Integrity hash over .rodata bytecode tables
    std::uint64_t text_crc64;      // +0x10: Integrity hash over .text instructions
    char          tag_name[16];    // +0x18: "envguard" identifier tag
};
static_assert(sizeof(EnvGuardContextAbi) == 0x28, "EnvGuardContextAbi size must be 40 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[123];
extern const std::uint32_t kTextInstructions[11656];
extern const std::uint8_t kElfImageBytes[224680];

bool VerifyElf64MagicAndMachine(const Elf64HeaderCheckView* hdr) noexcept;
int EvaluateEnvGuardProbes(EnvGuardContextAbi* ctx) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace envguard
} // namespace bytedance

extern "C" {
int JNI_OnLoad(void* vm, void* reserved);
}
