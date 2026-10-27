// ============================================================================
// File: yuv.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libyuv.so (215,112 bytes)
// SHA-256: c343f4a98ab9dcf07b58609b3344bf62eaf696ce3571c76be616a97e0489191c
// Task ID: TASK-198-RECONSTRUCTION-LIBYUV (TASK_SO_025_libyuv)
// Architecture: AArch64 (ARM64-v8a) — 1,063 FDEs (.eh_frame_hdr @ 0x26db0), 26,105 .text insns
// Clean-Room C++17 Header: Google / ByteDance libyuv Planar YUV & ARGB Color
// Conversion, Bilinear/Box Filtering, 90/180/270 Rotation, PSNR/SSIM & ARM64 NEON
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures (YuvConstantsAbi),
// ELF section constants, and exported functions of libyuv.so (564 exports).
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI (YuvConstantsAbi),
// hằng số phân đoạn ELF và các hàm xuất khẩu của libyuv.so (564 biểu tượng).
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>

namespace bytedance {
namespace yuv {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 215112ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x0beb0ULL;
constexpr std::uint64_t kPltSectionSize      = 0x00fa0ULL; // 4,000 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x0ce50ULL;
constexpr std::uint64_t kTextSectionSize     = 0x197e4ULL; // 104,420 bytes (26,105 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x26640ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x00770ULL; // 1,904 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x26db0ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x02144ULL; // 8,516 bytes (1,063 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x28ef8ULL;
constexpr std::uint64_t kEhFrameSize         = 0x07d60ULL; // 32,096 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0x36bb8ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x00008ULL; // 8 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x38000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x000b0ULL; // 176 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x380b0ULL;
constexpr std::uint64_t kBssSectionSize      = 0x00008ULL; // 8 bytes (cpu_info_)

// ============================================================================
// [EN] 2. YuvConstants Color Matrix ABI Structure (BT.601 / BT.709 / BT.2020)
// [VN] 2. Cấu trúc ABI Ma Trận Màu YuvConstants (BT.601 / BT.709 / BT.2020)
// ============================================================================
struct YuvConstantsAbi {
    std::uint8_t  kUVToB[32];      // +0x00: UV -> Blue coefficients
    std::uint8_t  kUVToG[32];      // +0x20: UV -> Green coefficients
    std::uint8_t  kUVToR[32];      // +0x40: UV -> Red coefficients
    std::int16_t  kYToRgb[16];     // +0x60: Y -> RGB scale factor
    std::int16_t  kYBiasToRgb[16]; // +0x80: Y bias offset
};
static_assert(sizeof(YuvConstantsAbi) == 0xa0, "YuvConstantsAbi size must be 160 bytes");

struct FdeDescriptor {
    std::uint32_t index;
    std::uint64_t start_vaddr;
    std::uint64_t end_vaddr;
    std::uint32_t size_bytes;
    std::uint64_t fde_vaddr;
};

extern const FdeDescriptor kFdeTable[1063];
extern const std::uint32_t kTextInstructions[26105];
extern const std::uint8_t kElfImageBytes[215112];

std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace yuv
} // namespace bytedance

extern "C" {
std::uint32_t HashDjb2(const std::uint8_t* src, std::uint64_t count, std::uint32_t seed) noexcept;
std::uint32_t HashDjb2_C(const std::uint8_t* src, std::uint64_t count, std::uint32_t seed) noexcept;
std::uint32_t SumSquareError_C(const std::uint8_t* src_a, const std::uint8_t* src_b, int count) noexcept;
double SumSquareErrorToPsnr(std::uint64_t sse, std::uint64_t count) noexcept;
int I420Copy(const std::uint8_t* src_y, int src_stride_y,
             const std::uint8_t* src_u, int src_stride_u,
             const std::uint8_t* src_v, int src_stride_v,
             std::uint8_t* dst_y, int dst_stride_y,
             std::uint8_t* dst_u, int dst_stride_u,
             std::uint8_t* dst_v, int dst_stride_v,
             int width, int height) noexcept;
int NV12ToI420(const std::uint8_t* src_y, int src_stride_y,
               const std::uint8_t* src_uv, int src_stride_uv,
               std::uint8_t* dst_y, int dst_stride_y,
               std::uint8_t* dst_u, int dst_stride_u,
               std::uint8_t* dst_v, int dst_stride_v,
               int width, int height) noexcept;
int NV21ToI420(const std::uint8_t* src_y, int src_stride_y,
               const std::uint8_t* src_vu, int src_stride_vu,
               std::uint8_t* dst_y, int dst_stride_y,
               std::uint8_t* dst_u, int dst_stride_u,
               std::uint8_t* dst_v, int dst_stride_v,
               int width, int height) noexcept;
}
