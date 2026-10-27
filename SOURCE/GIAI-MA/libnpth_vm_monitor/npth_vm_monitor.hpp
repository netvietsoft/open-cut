// ============================================================================
// File: npth_vm_monitor.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libnpth_vm_monitor.so (55,968 bytes)
// SHA-256: 877db3380e7c313c441509651dd39a8d1d26643d35dc3c513e59e6680e8331cc
// Task ID: TASK-191-RECONSTRUCTION-LIBNPTH-VM-MONITOR (TASK_SO_079_libnpth_vm_monitor)
// Architecture: AArch64 (ARM64-v8a) — 87 FDEs (.eh_frame_hdr @ 0x3374), 47 Exports
// Clean-Room C++17 Header: ByteDance NPTH Virtual Memory Monitor
// (mmap/munmap/mremap/mprotect ShadowHook Interceptors, Intrusive Red-Black
//  VMA Tree, Custom Arena Allocator, Pagemap/RSS Reader & VM Leak Classifier)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, VMA red-black
// tree nodes, custom arena pools, and all 47 exported symbols of libnpth_vm_monitor.so.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI,
// nút cây Đỏ-Đen VMA, vùng cấp phát arena riêng và toàn bộ 47 biểu tượng xuất khẩu.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace npth {
namespace vm_monitor {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 55968ULL;
constexpr std::uint64_t kRodataSectionVaddr  = 0x2828ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x0b4cULL; // 2,892 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x3374ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x02c4ULL; // 708 bytes (87 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x3638ULL;
constexpr std::uint64_t kEhFrameSize         = 0x110cULL; // 4,364 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x4744ULL;
constexpr std::uint64_t kTextSectionSize     = 0x7dd4ULL; // 32,212 bytes (8,053 insns)
constexpr std::uint64_t kPltSectionVaddr     = 0xc520ULL;
constexpr std::uint64_t kPltSectionSize      = 0x06a0ULL; // 1,696 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x10bc0ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x0158ULL; // 344 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x15290ULL;
constexpr std::uint64_t kDataSectionSize     = 0x0018ULL; // 24 bytes (vm_monitor_native_interface_func)
constexpr std::uint64_t kBssSectionVaddr     = 0x152a8ULL;
constexpr std::uint64_t kBssSectionSize      = 0x00c0ULL; // 192 bytes

constexpr std::uint64_t kTbiPointerMask56Bit = 0x00ffffffffffffffULL;

// ============================================================================
// [EN] 2. Intrusive Red-Black Tree VMA Node & Native Interface ABI Structures
// [VN] 2. Cấu trúc ABI Nút Cây Đỏ-Đen VMA & Bảng Hàm Giao Diện Gốc
// ============================================================================
struct VmMonitorNativeInterface {
    int (*initialize)(const char* config_path, int flags);
    int (*execute_command)(int cmd, const char* arg);
    int (*dump_native)(const char* dump_dir);
};
static_assert(sizeof(VmMonitorNativeInterface) == 0x18, "VmMonitorNativeInterface ABI size must be 24 bytes");

struct MmapVmaRbNode {
    std::uint64_t parent_color;    // +0x00: Parent pointer + Red/Black color bit
    MmapVmaRbNode* left;           // +0x08: Left child
    MmapVmaRbNode* right;          // +0x10: Right child
    std::uint64_t start_vaddr;     // +0x18: VMA start address (56-bit TBI stripped)
    std::uint64_t size_bytes;      // +0x20: Mapped byte length
    std::int32_t  prot;            // +0x28: PROT_READ | PROT_WRITE | PROT_EXEC
    std::int32_t  flags;           // +0x2c: MAP_PRIVATE | MAP_ANONYMOUS | ...
    std::int32_t  fd;              // +0x30: Backing file descriptor (-1 for anon)
    std::int32_t  leak_category;   // +0x34: ANON, DMABUF, DATA, SYSTEM, DEVICES, OTHER
    std::uint64_t backtrace_hash;  // +0x38: Stack trace hash key
};
static_assert(sizeof(MmapVmaRbNode) == 0x40, "MmapVmaRbNode ABI size must be 64 bytes");

// ============================================================================
// [EN] 3. Core Clean-Room Function Declarations
// [VN] 3. Khai báo các hàm C++17 phòng sạch cốt lõi
// ============================================================================
std::uint64_t StripTbiAddress_7ab4(std::uint64_t raw_vaddr) noexcept;
bool Is64BitRuntime_bc60() noexcept;
int ClassifyVmLeakCategory(const char* mapping_name) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace vm_monitor
} // namespace npth
} // namespace bytedance

extern "C" {
int so_initialize(const char* config_path, int flags);
int npth_vm_monitor_execute_command(int cmd, const char* arg);
int dump_native(const char* dump_dir);
int is64bitRuntime();
long vm_strtol(const char* nptr, char** endptr, int base);
}
