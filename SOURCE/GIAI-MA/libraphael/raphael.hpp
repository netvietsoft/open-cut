// ============================================================================
// File: raphael.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libraphael.so (51,336 bytes)
// SHA-256: 928e64ccde02fdf0a1e8d12a35148a360f0952c6dc9dbb7df328004e636b6d8a
// Task ID: TASK-189-RECONSTRUCTION-LIBRAPHAEL (TASK_SO_147_libraphael)
// Architecture: AArch64 (ARM64-v8a) — 106 FDEs (.eh_frame_hdr @ 0x7fb8), 10 Exports
// Clean-Room C++17 Header: ByteDance Raphael Native Memory Leak Profiler
// (ByteHook PLT/GOT Interceptors, AllocCache/DiffCache Hash Table, NPTH Unwind)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, ByteHook
// allocation interceptors, and Raphael JNI control entrypoints.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI,
// bộ chặn cấp phát ByteHook và các điểm vào điều khiển JNI của Raphael.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <jni.h>

namespace bytedance {
namespace raphael {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 51336ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x19a0ULL;
constexpr std::uint64_t kPltSectionSize      = 0x0460ULL; // 1,120 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x1e00ULL;
constexpr std::uint64_t kTextSectionSize     = 0x5d0cULL; // 23,820 bytes (5,955 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x7b0cULL;
constexpr std::uint64_t kRodataSectionSize   = 0x04a9ULL; // 1,193 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x7fb8ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x035cULL; // 860 bytes (106 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x8318ULL;
constexpr std::uint64_t kEhFrameSize         = 0x14d0ULL; // 5,328 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0xfb08ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x0050ULL; // 80 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x10000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x0030ULL; // 48 bytes (3 JNINativeMethod entries)
constexpr std::uint64_t kBssSectionVaddr     = 0x10030ULL;
constexpr std::uint64_t kBssSectionSize      = 0x0340ULL; // 832 bytes

// ============================================================================
// [EN] 2. Raphael Profiler Configuration & AllocNode ABI Structures
// [VN] 2. Cấu trúc ABI Cấu hình Raphael & Nút Cấp phát Bộ nhớ
// ============================================================================
struct RaphaelConfig {
    std::uint32_t config_flags;    // +0x00: Bitmask (MALLOC, MMAP, JAVA_STACK, CATCH_UNWIND_SIG)
    std::int32_t  limit_min;       // +0x04: Minimum tracked allocation size
    std::int32_t  limit_max;       // +0x08: Maximum tracked allocation size
    std::int32_t  max_depth;       // +0x0c: Maximum stack unwind depth
    const char*   space_path;      // +0x10: Output report directory path
    const char*   regex_pattern;   // +0x18: Library name filter regex
};
static_assert(sizeof(RaphaelConfig) == 0x20, "RaphaelConfig ABI size must be 32 bytes");

struct AllocCacheNode {
    std::uint64_t address;         // +0x00: Tracked heap/mmap pointer
    std::uint64_t size;            // +0x08: Allocation byte count
    std::uint64_t frames[16];      // +0x10..0x8f: Unwound backtrace PCs
    std::uint32_t depth;           // +0x90: Backtrace frame count
    std::uint32_t count;           // +0x94: Aggregated allocation count
    AllocCacheNode* next;          // +0x98: Intrusive hash bucket chain pointer
};
static_assert(sizeof(AllocCacheNode) == 0xa0, "AllocCacheNode ABI size must be 160 bytes");

// ============================================================================
// [EN] 3. Core Clean-Room Function Declarations
// [VN] 3. Khai báo các hàm C++17 phòng sạch cốt lõi
// ============================================================================
std::uint32_t HashAllocAddress(std::uint64_t addr, std::uint32_t bucket_mask) noexcept;
bool InsertAllocCacheNode(AllocCacheNode** buckets, std::uint32_t bucket_mask,
                          AllocCacheNode* node) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace raphael
} // namespace bytedance

extern "C" {
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);
JNIEXPORT void JNICALL Java_com_bytedance_raphael_TestTool_mallocLeak(JNIEnv* env, jclass clazz);
JNIEXPORT void JNICALL Java_com_bytedance_raphael_TestTool_print(JNIEnv* env, jclass clazz, jstring space, jstring regex);
}
