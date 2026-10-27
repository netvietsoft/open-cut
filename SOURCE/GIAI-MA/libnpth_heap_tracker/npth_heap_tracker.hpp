// ============================================================================
// File: npth_heap_tracker.hpp
// Target: libnpth_heap_tracker.so (43,176 bytes, SHA-256: ec2e686f2d21c863ea039279b9251d87a1becac552bc860bec3a401f22b045f8)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance NPTH Native Heap Leak Tracker, Bionic MallocDispatch &
//         C++ Operator New Interceptor, Pagemap/Smaps Fork Dumper
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>

namespace nextai::opencut::npth_heap_tracker {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của libnpth_heap_tracker.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 43176U;
inline constexpr const char* kBinarySha256Hex          = "ec2e686f2d21c863ea039279b9251d87a1becac552bc860bec3a401f22b045f8";
inline constexpr std::uint64_t kRodataStartVa          = 0x000019D0ULL;
inline constexpr std::size_t kRodataSizeBytes          = 3392U;         // 0x19D0..0x2710
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x00002710ULL;
inline constexpr std::size_t kEhFrameFdeCount          = 81U;           // 81 FDEs @ 0x2710
inline constexpr std::uint64_t kTextStartVa            = 0x000037E0ULL;
inline constexpr std::uint64_t kTextEndVa              = 0x000096CCULL;
inline constexpr std::size_t kTextSizeBytes            = 24300U;        // 6,075 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 6075U;
inline constexpr std::uint64_t kDataStartVa            = 0x00012008ULL;
inline constexpr std::uint64_t kDataFileOffset         = 0x0000A008ULL;
inline constexpr std::size_t kDataSizeBytes            = 96U;
inline constexpr std::uint64_t kBssStartVa             = 0x00012068ULL;
inline constexpr std::size_t kBssSizeBytes             = 136U;

inline constexpr std::uint64_t kTbiPointerMask56Bit    = 0x00FFFFFFFFFFFFFFULL; // (@ 0x6a04)
inline constexpr std::uint64_t kHeapWarnBytes          = 0x029736E9ULL;         // (@ 0x40c0..0x40c4)
inline constexpr std::uint64_t kHeapDumpThresholdBytes = 0x03200001ULL;         // (@ 0x4608..0x460c)

// ============================================================================
// 2. Reconstructed ABI Structures (HeapTrackerInterface & Manager)
//    Cấu trúc bảng giao diện 64 byte (8 hàm) tại .data 0x12008
// ============================================================================
struct HeapTrackerNativeInterface {
    int         (*initialize)(const char* config_dir);
    int         (*control_cmd)(int cmd);
    std::size_t (*get_mallinfo_uordblks)();
    void        (*check_heap_size)();
    void        (*set_param_a0)(std::uint64_t val);
    void        (*set_param_a8)(std::uint64_t val);
    void        (*set_param_b0)(int val);
    int         (*trigger_wait_or_check)(int arg);
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
extern const std::array<std::uint8_t, kRodataSizeBytes> kRodataBytes_19d0;
extern const std::array<std::uint8_t, kDataSizeBytes> kDataBytes_12008;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

void HeapTrackerNeonAdd2x64_495c(std::uint64_t dst[2], const std::uint64_t src[2]) noexcept;
std::uintptr_t StripTbiAndPac_69dc(std::uintptr_t ptr) noexcept;

extern "C" {
extern HeapTrackerNativeInterface heap_tracker_native_interface_func;
}

} // namespace nextai::opencut::npth_heap_tracker
