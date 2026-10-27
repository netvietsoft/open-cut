// ============================================================================
// File: gifimage.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libgifimage.so (51,696 bytes)
// SHA-256: e77193814bfa15d21d703c188ce203dbfab40f691d70d52b3101afd63b72766c
// Task ID: TASK-190-RECONSTRUCTION-LIBGIFIMAGE (TASK_SO_143_libgifimage)
// Architecture: AArch64 (ARM64-v8a) — 86 FDEs (.eh_frame_hdr @ 0x7814), JNI_OnLoad @ 0x1c2c
// Clean-Room C++17 Header: Facebook Fresco Animated GIF Native Decoder
// (com.facebook.animated.gif.GifImage & GifFrame, giflib 5.x LZW Decoder)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, giflib
// LZW dictionary state, and GifImage/GifFrame JNI native context layouts.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI,
// trạng thái từ điển LZW giflib và bố cục ngữ cảnh gốc JNI GifImage/GifFrame.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <jni.h>

namespace facebook {
namespace animated {
namespace gif {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 51696ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x1970ULL;
constexpr std::uint64_t kPltSectionSize      = 0x0280ULL; // 640 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x1bf0ULL;
constexpr std::uint64_t kTextSectionSize     = 0x533cULL; // 21,308 bytes (5,327 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x6f30ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x08e2ULL; // 2,274 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x7814ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x02bcULL; // 700 bytes (86 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x7ad0ULL;
constexpr std::uint64_t kEhFrameSize         = 0x0be0ULL; // 3,040 bytes
constexpr std::uint64_t kDataRelRoVaddr      = 0xfb40ULL;
constexpr std::uint64_t kDataRelRoSize       = 0x0150ULL; // 336 bytes
constexpr std::uint64_t kDataSectionVaddr    = 0x10000ULL;
constexpr std::uint64_t kDataSectionSize     = 0x0258ULL; // 600 bytes (25 JNINativeMethods)
constexpr std::uint64_t kBssSectionVaddr     = 0x10258ULL;
constexpr std::uint64_t kBssSectionSize      = 0x0038ULL; // 56 bytes

constexpr std::uint32_t kLzMaxCode           = 4095U;     // 12-bit LZW maximum code

// ============================================================================
// [EN] 2. GifColorType, GifFrameMetadata & LZW Decoder ABI Structures
// [VN] 2. Cấu trúc ABI Bảng Màu GIF, Siêu Dữ Liệu Khung & Bộ Giải Mã LZW
// ============================================================================
struct GifColorEntry {
    std::uint8_t r;
    std::uint8_t g;
    std::uint8_t b;
};
static_assert(sizeof(GifColorEntry) == 3, "GifColorEntry must be 3 bytes");

struct GifFrameDescriptor {
    std::int32_t left;             // +0x00: Frame X offset
    std::int32_t top;              // +0x04: Frame Y offset
    std::int32_t width;            // +0x08: Frame width in pixels
    std::int32_t height;           // +0x0c: Frame height in pixels
    std::int32_t duration_ms;      // +0x10: Frame delay in milliseconds (GCE delay * 10)
    std::int32_t disposal_method;  // +0x14: Disposal method (0..3)
    std::int32_t transparent_idx;  // +0x18: Transparent palette index (-1 if none)
    std::int32_t interlace_flag;   // +0x1c: Interlaced scanline order flag
};
static_assert(sizeof(GifFrameDescriptor) == 0x20, "GifFrameDescriptor ABI size must be 32 bytes");

// ============================================================================
// [EN] 3. Core Clean-Room Function Declarations
// [VN] 3. Khai báo các hàm C++17 phòng sạch cốt lõi
// ============================================================================
std::uint32_t PackRgba8888Pixel(GifColorEntry c, std::uint8_t alpha) noexcept;
int DecodeGifGraphicsControlExt(const std::uint8_t* ext_bytes, std::size_t ext_len,
                                GifFrameDescriptor& inout_desc) noexcept;
std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace gif
} // namespace animated
} // namespace facebook

extern "C" {
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM* vm, void* reserved);
}
