// ============================================================================
// File: npth.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libnpth.so (181,952 bytes)
// SHA-256: ba58fcc3cf3bc7dc02214be07e7f22cd193c6e3f73a9d703bdd2f67a86dc63d5
// Task ID: TASK-197-RECONSTRUCTION-LIBNPTH (TASK_SO_073_libnpth_unwind)
// Architecture: AArch64 (ARM64-v8a) — 423 FDEs (.eh_frame_hdr @ 0x0a898), 26,272 .text insns
// Clean-Room C++17 Header: ByteDance NPTH Core Native Crash Handler, Signal
// Interceptor (SIGSEGV/SIGABRT/SIGBUS/SIGFPE/SIGILL/SIGSYS), Tombstone Dumper
// (sighand.txt, pthreads.txt), ART VM Suspend Bridge & Unwind Engine
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, AArch64 signal
// ucontext/mcontext registers, crash dump descriptors, and JNI_OnLoad @ 0x10160.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI, thanh ghi
// ngữ cảnh tín hiệu ucontext/mcontext AArch64, bộ mô tả kết xuất sự cố và JNI_OnLoad @ 0x10160.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace npth {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 181952ULL;
constexpr std::uint64_t kRodataSectionVaddr  = 0x057f0ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x050a6ULL; // 20,646 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x0a898ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x00d44ULL; // 3,396 bytes (423 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x0b5e0ULL;
constexpr std::uint64_t kEhFrameSize         = 0x04b28ULL; // 19,240 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x10110ULL;
constexpr std::uint64_t kTextSectionSize     = 0x19a80ULL; // 105,088 bytes (26,272 insns)
constexpr std::uint64_t kPltSectionVaddr     = 0x29b90ULL;
constexpr std::uint64_t kPltSectionSize      = 0x00960ULL; // 2,400 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x2e4f0ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x00f90ULL; // 3,984 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x33ba8ULL;
constexpr std::uint64_t kDataSectionSize     = 0x002d4ULL; // 724 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x33e80ULL;
constexpr std::uint64_t kBssSectionSize      = 0x02bb8ULL; // 11,192 bytes

constexpr std::uint64_t kJniOnLoadVaddr      = 0x10160ULL;

// ============================================================================
// [EN] 2. AArch64 Crash Signal Context & Tombstone Dumper ABI Structures
// [VN] 2. Cấu trúc ABI Ngữ Cảnh Tín Hiệu Sự Cố AArch64 & Bộ Kết Xuất Tombstone
// ============================================================================
struct NpthAArch64RegStateAbi {
    std::uint64_t regs[31];       // +0x00: General purpose registers x0..x30 (LR)
    std::uint64_t sp;             // +0xf8: Stack pointer
    std::uint64_t pc;             // +0x100: Program counter at fault
    std::uint64_t pstate;         // +0x108: Processor state (CPSR)
    std::uint64_t fault_address;  // +0x110: FAR_EL1 fault address
};
static_assert(sizeof(NpthAArch64RegStateAbi) == 0x118, "NpthAArch64RegStateAbi size must be 280 bytes");

struct NpthSignalEventAbi {
    std::int32_t  signo;          // +0x00: Signal number (SIGSEGV=11, SIGABRT=6, SIGBUS=7, SIGFPE=8, SIGILL=4)
    std::int32_t  si_code;        // +0x04: Signal code (SEGV_MAPERR, SI_QUEUE, SI_TKILL, etc.)
    std::int32_t  tid;            // +0x08: Faulting thread ID
    std::int32_t  pid;            // +0x0c: Process ID
    std::uint64_t fault_pc;       // +0x10: Faulting instruction address
    std::uint64_t fault_addr;     // +0x18: Faulting memory address
    std::uint64_t signal_init_fn; // +0x20: Pointer to npth_signal_init
};
static_assert(sizeof(NpthSignalEventAbi) == 0x28, "NpthSignalEventAbi size must be 40 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[423];
extern const std::uint32_t kTextInstructions[26272];
extern const std::uint8_t kElfImageBytes[181952];

const char* NpthResolveSignalName(int signo) noexcept;
int NpthFormatSignalMonitorLog(const NpthSignalEventAbi* ev, char* out_buf, std::size_t cap) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace npth
} // namespace bytedance

extern "C" {
int JNI_OnLoad(void* vm, void* reserved);
}
