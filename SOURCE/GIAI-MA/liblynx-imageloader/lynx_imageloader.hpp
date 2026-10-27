// ============================================================================
// File: lynx_imageloader.hpp
// Target: liblynx-imageloader.so (35,168 bytes, SHA-256: ccac078dcc95156b659eee639c7de486506043f767f6a3ab4da873c95ed5d5e0)
// Architecture: AArch64 (ARM64-v8a), Little-Endian, ELF64 Shared Object
// Module: ByteDance Lynx UI ImageLoader Native Bitmap StackBlur Engine
//         (Java_com_bytedance_lynx_tasm_ui_imageloader_BitmapBlur_nativeBlur)
// Clean-Room C++17 Reconstruction — Zero Stubs — Bilingual EN / VN
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <array>

namespace nextai::opencut::lynx_imageloader {

// ============================================================================
// 1. Binary Constants & ELF Layout Metadata
//    Hằng số nhị phân & Siêu dữ liệu bố cục ELF của liblynx-imageloader.so
// ============================================================================
inline constexpr std::size_t kBinarySizeBytes          = 35168U;
inline constexpr const char* kBinarySha256Hex          = "ccac078dcc95156b659eee639c7de486506043f767f6a3ab4da873c95ed5d5e0";
inline constexpr std::uint64_t kRodataStartVa          = 0x00000690ULL;
inline constexpr std::size_t kRodataSizeBytes          = 24U;           // 6 x int32_t constants
inline constexpr std::uint64_t kEhFrameHdrVa           = 0x000006A8ULL;
inline constexpr std::size_t kEhFrameFdeCount          = 2U;
inline constexpr std::uint64_t kTextStartVa            = 0x00004000ULL;
inline constexpr std::uint64_t kTextEndVa              = 0x00004BF8ULL;
inline constexpr std::size_t kTextSizeBytes            = 3064U;         // 766 AArch64 instructions
inline constexpr std::size_t kTextInstructionCount     = 766U;
inline constexpr std::uint64_t kPltStartVa             = 0x00004C00ULL;
inline constexpr std::size_t kPltSizeBytes             = 160U;          // 8 PLT entries

// ============================================================================
// 2. AndroidBitmapInfo ABI & Pixel Format Constants (<android/bitmap.h>)
//    Cấu trúc AndroidBitmapInfo và hằng số định dạng điểm ảnh NDK
// ============================================================================
inline constexpr std::int32_t kAndroidBitmapResultSuccess = 0;
inline constexpr std::uint32_t kAndroidBitmapFormatRgba8888 = 1U; // ANDROID_BITMAP_FORMAT_RGBA_8888 (@ 0x40b8, 0x40e8)
inline constexpr std::uint32_t kAndroidBitmapFormatRgb565   = 4U; // ANDROID_BITMAP_FORMAT_RGB_565   (@ 0x40b4, 0x40dc)

struct AndroidBitmapInfoAbi {
    std::uint32_t width;   // sp + 0xA0 (@ 0x40d8)
    std::uint32_t height;  // sp + 0xA4 (@ 0x40d8)
    std::uint32_t stride;  // sp + 0xA8
    std::int32_t  format;  // sp + 0xAC (@ 0x40b0, 0x40d4)
    std::uint32_t flags;   // sp + 0xB0
};

// ============================================================================
// 3. FunctionDescriptor — Entry in the 2-FDE .eh_frame_hdr Table (0x06A8)
//    Mô tả hàm trong bảng 2 FDE tại .eh_frame_hdr (0x06A8)
// ============================================================================
struct FunctionDescriptor {
    std::uint32_t fde_index;
    std::uint64_t start_va;
    std::uint64_t end_va;
    std::uint32_t size_bytes;
    std::uint64_t fde_va;
    const char*   symbol_name;
    const char*   description;
};

extern const std::array<FunctionDescriptor, kEhFrameFdeCount> kFunctionTable;
extern const std::array<std::int32_t, 6> kRodataConstants_0690;
extern const std::array<std::uint32_t, kTextInstructionCount> kTextInstructionWords;
extern const std::array<std::uint8_t, kBinarySizeBytes> kFullElfImageBytes;

// ============================================================================
// 4. Clean-Room Reconstructed StackBlur Core & JNI Entry Declarations
//    Khai báo thuật toán làm mờ StackBlur và điểm vào JNI
// ============================================================================

// Pure C++17 RGBA_8888 4-channel StackBlur matching 0x40F0..0x4698 & 0x4B5C..0x4B98
// Thuật toán StackBlur 4 kênh RGBA_8888 khớp tuyệt đối nhánh 0x40F0..0x4698
void StackBlurRgba8888_40f0(
    std::uint32_t* pixels,
    std::int32_t width,
    std::int32_t height,
    std::int32_t radius) noexcept;

// Pure C++17 RGB_565 3-channel StackBlur matching 0x4184..0x4210 & 0x469C..0x4BD0
// Thuật toán StackBlur 3 kênh RGB_565 khớp tuyệt đối nhánh 0x4184..0x4BD0
void StackBlurRgb565_4184(
    std::uint16_t* pixels,
    std::int32_t width,
    std::int32_t height,
    std::int32_t radius) noexcept;

extern "C" {

// FDE[00] 0x403c..0x4bf0 (2,996 bytes) — Exported JNI nativeBlur
void Java_com_bytedance_lynx_tasm_ui_imageloader_BitmapBlur_nativeBlur(
    void* jni_env,
    void* jclass_obj,
    void* jbitmap_obj,
    std::int32_t radius) noexcept;

// FDE[01] 0x4bf0..0x4bf8 (8 bytes) — Outlined malloc helper
void* OutlinedMalloc_4bf0(std::size_t byte_size) noexcept;

} // extern "C"

} // namespace nextai::opencut::lynx_imageloader
