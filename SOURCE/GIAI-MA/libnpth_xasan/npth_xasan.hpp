// ============================================================================
// File: npth_xasan.hpp
// Target: libnpth_xasan.so (40,480 bytes, SHA-256: 98ea19aaef712fed55b86c103322cb2b3a25c1b763bb99b152c73bf9086afd5a)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance NPTH XASan — GWP-ASan Guarded Pool Allocator & Bionic
//         __libc_malloc_dispatch Memory Error Detector
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>

namespace gwp_asan {

enum class Error : int {
    UNKNOWN          = 0,
    USE_AFTER_FREE   = 1,
    DOUBLE_FREE      = 2,
    INVALID_FREE     = 3,
    BUFFER_OVERFLOW  = 4,
    BUFFER_UNDERFLOW = 5,
};

class GuardedPoolAllocator {
public:
    // Export [84] 0x8730..0x8744 (20 bytes)
    // _ZN8gwp_asan20GuardedPoolAllocator13trapOnAddressEm5Error
    void trapOnAddress(std::uintptr_t addr, Error err) noexcept;
};

} // namespace gwp_asan

namespace nextai::opencut::npth_xasan {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của libnpth_xasan.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 40480U;
inline constexpr const char* kBinarySha256Hex          = "98ea19aaef712fed55b86c103322cb2b3a25c1b763bb99b152c73bf9086afd5a";
inline constexpr std::uint64_t kRodataStartVa          = 0x00001C60ULL;
inline constexpr std::size_t kRodataSizeBytes          = 3944U;         // 0x1C60..0x2BC8
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x00002BC8ULL;
inline constexpr std::size_t kEhFrameFdeCount          = 84U;           // 84 FDEs @ 0x2BC8
inline constexpr std::uint64_t kTextStartVa            = 0x00003C48ULL;
inline constexpr std::uint64_t kTextEndVa              = 0x00008BD8ULL;
inline constexpr std::size_t kTextSizeBytes            = 20368U;        // 5,092 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 5092U;
inline constexpr std::uint64_t kDataStartVa            = 0x00011608ULL;
inline constexpr std::uint64_t kDataFileOffset         = 0x00009608ULL;
inline constexpr std::size_t kDataSizeBytes            = 32U;
inline constexpr std::uint64_t kBssStartVa             = 0x00011628ULL;
inline constexpr std::size_t kBssSizeBytes             = 16712U;

inline constexpr std::uint32_t kSignalStackSizeBytes   = 0x00020000U;   // 128 KB (@ 0x5800: mov w1, #0x20000)
inline constexpr std::uint32_t kFastDiv10Magic         = 0x66666667U;   // (@ 0x7708..0x7710)

// ============================================================================
// 2. Reconstructed ABI Structures (BionicMallocDispatch & GwpAsanState)
//    Cấu trúc ABI Bionic MallocDispatch và trạng thái GWP-ASan
// ============================================================================
struct BionicMallocDispatch {
    void* (*malloc_fn)(std::size_t);               // +0x00 (@ 0x460c)
    void  (*free_fn)(void*);                       // +0x08 (@ 0x45ec)
    void* (*calloc_fn)(std::size_t, std::size_t);  // +0x10 / +0x20 (@ 0x466c)
    void* (*realloc_fn)(void*, std::size_t);       // +0x18 (@ 0x45d0)
    void* (*calloc_slot_20)(std::size_t, std::size_t); // +0x20 (@ 0x466c)
    void* (*memalign_fn)(std::size_t, std::size_t);// +0x28 (@ 0x464c)
    void* reserved_30;                             // +0x30
    std::size_t (*malloc_usable_size_fn)(const void*); // +0x38 (@ 0x462c)
};

struct GwpAsanPoolState {
    std::uint8_t  pad_00[0x10];
    std::size_t   max_simultaneous_allocs;         // +0x10 (@ 0x7d60)
    std::size_t   page_size;                       // +0x18 (@ 0x7d68)
    std::int32_t  fault_error_code;                // +0x20 (@ 0x7d94)
    std::int32_t  pad_24;
    std::uintptr_t guarded_page_pool;              // +0x28 (@ 0x7bc8)
    std::uintptr_t guarded_page_pool_end;          // +0x30 (@ 0x7bbc)
    std::uintptr_t metadata_addr;                  // +0x38
    std::int32_t  has_crashed;                     // +0x40 (@ 0x7ba4)
    std::int32_t  pad_44;
    std::uintptr_t crashing_address;               // +0x48 (@ 0x7bac, 0x7be0)
};

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_pc;
    std::uint64_t end_pc;
    std::uint32_t size_bytes;
    std::uint64_t fde_va;
    const char*   symbol_name;
    const char*   summary;
};

extern const std::array<FdeDescriptor, kEhFrameFdeCount> kFdeTable;
extern const std::array<std::uint32_t, kTextInstructionCount> kTextInstructionWords;
extern const std::array<std::uint8_t, kRodataSizeBytes> kRodataBytes_1c60;
extern const std::array<std::uint8_t, kDataSizeBytes> kDataBytes_11608;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

const char* GwpAsanErrorToString_7dc0(gwp_asan::Error err) noexcept;
char* XasanFastItoa10_76e4(std::int32_t value, char* out_buf) noexcept;
bool GwpAsanAddressIsMine_7ba4(const GwpAsanPoolState* state, std::uintptr_t addr) noexcept;

extern "C" {
extern void* xasan_native_interface_func;
}

} // namespace nextai::opencut::npth_xasan
