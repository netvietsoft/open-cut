// ============================================================================
// File: fly_main_color_lib.hpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libfly-main-color-lib.so (51,024 bytes)
// SHA-256: 4eae061db755de08346e4cec950e9748d506af1fb140b2bfd95bc7dc49a0ba57
// Task ID: TASK-187-RECONSTRUCTION-LIBFLY-MAIN-COLOR-LIB (TASK_SO_154_libfly_main_color_lib)
// Architecture: AArch64 (ARM64-v8a) — 74 FDEs (.eh_frame_hdr @ 0x89c4), 66 Exports
// Clean-Room C++17 Header: ByteDance FlyMainColor Dominant Color Median-Cut
// Extraction (RGB565 / ARGB8888 C & NEON) & Perceptual Color Space Engine
// (sRGB <-> CIE XYZ <-> CIE L*a*b* <-> CIE L*C*h* & Oklab <-> Oklch, Delta-E)
// ============================================================================
// [EN] Bilingual architectural header defining exact ABI structures, perceptual
// color space conversion routines, and median-cut dominant color extraction APIs.
// [VN] Tệp tiêu đề kiến trúc song ngữ định nghĩa chính xác các cấu trúc ABI,
// hàm chuyển đổi không gian màu cảm nhận và trích xuất màu chủ đạo median-cut.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <cmath>
#include <cstring>
#include <jni.h>

namespace bytedance {
namespace fly_main_color {

// ============================================================================
// [EN] 1. Binary Constants & Section Geometry (Observed from ELF64)
// [VN] 1. Hằng số nhị phân & Hình học phân đoạn (Quan sát từ ELF64)
// ============================================================================
constexpr std::size_t kBinaryFileSizeBytes   = 51024ULL;
constexpr std::uint64_t kPltSectionVaddr     = 0x20c0ULL;
constexpr std::uint64_t kPltSectionSize      = 0x03f0ULL; // 1,008 bytes
constexpr std::uint64_t kTextSectionVaddr    = 0x24b0ULL;
constexpr std::uint64_t kTextSectionSize     = 0x6364ULL; // 25,444 bytes (6,361 insns)
constexpr std::uint64_t kRodataSectionVaddr  = 0x8818ULL;
constexpr std::uint64_t kRodataSectionSize   = 0x01a9ULL; // 425 bytes
constexpr std::uint64_t kEhFrameHdrVaddr     = 0x89c4ULL;
constexpr std::uint64_t kEhFrameHdrSize      = 0x025cULL; // 604 bytes (74 FDEs)
constexpr std::uint64_t kEhFrameVaddr        = 0x8c20ULL;
constexpr std::uint64_t kEhFrameSize         = 0x0aa0ULL; // 2,720 bytes
constexpr std::uint64_t kBssSectionVaddr     = 0x10000ULL;
constexpr std::uint64_t kBssSectionSize      = 0x0018ULL; // 24 bytes

// ============================================================================
// [EN] 2. Perceptual Color Space Constants (.rodata @ 0x8818..0x89c0)
// [VN] 2. Hằng số không gian màu cảm nhận (.rodata @ 0x8818..0x89c0)
// ============================================================================
constexpr float kTwoPiFloat32    = 6.2831854820251465f; // 0x40c90fdb
constexpr float kFullCircleDeg32 = 360.0f;              // 0x43b40000

// ============================================================================
// [EN] 3. Median-Cut Box Node ABI Structure (sizeof == 0x38 = 56 bytes)
//         Observed in _Z19create_color_box_atPtaPKtiii (0x6dfc) &
//         _Z13insert_box_atP8colorBoxS0_ (0x7670)
// [VN] 3. Cấu trúc ABI Nút Hộp Median-Cut (kích thước == 0x38 = 56 byte)
//         Quan sát trong _Z19create_color_box_atPtaPKtiii (0x6dfc) &
//         _Z13insert_box_atP8colorBoxS0_ (0x7670)
// ============================================================================
struct ColorBoxNode {
    std::int32_t r_min;       // +0x00: Minimum R5 channel (0..31)
    std::int32_t r_max;       // +0x04: Maximum R5 channel (0..31)
    std::int32_t g_min;       // +0x08: Minimum G5 channel (0..31)
    std::int32_t g_max;       // +0x0c: Maximum G5 channel (0..31)
    std::int32_t b_min;       // +0x10: Minimum B5 channel (0..31)
    std::int32_t b_max;       // +0x14: Maximum B5 channel (0..31)
    std::int32_t r_range;     // +0x18: R range or split bound
    std::int32_t g_range;     // +0x1c: G range or split bound
    std::int32_t b_range;     // +0x20: B range or split bound
    std::int32_t priority;    // +0x24: Box priority / volume-weighted count (compared at 0x767c..0x7684)
    std::int32_t pixel_count; // +0x28: Total pixel count inside box
    std::int32_t level;       // +0x2c: Subdivision tree depth level
    ColorBoxNode* next;       // +0x30: Intrusive sorted linked-list next pointer (0x7674..0x7690)
};
static_assert(sizeof(ColorBoxNode) == 0x38, "ColorBoxNode ABI size must be 56 bytes");

struct Vec3f {
    float c0;
    float c1;
    float c2;
};

// ============================================================================
// [EN] 4. Exported C++ & JNI Function Declarations (All 66 Exports)
// [VN] 4. Khai báo đầy đủ 66 hàm C++ & JNI xuất khẩu
// ============================================================================
float rad2deg_6784(float radians) noexcept;
float deg2rad_67a4(float degrees) noexcept;
int compare_r_74e4(const std::uint16_t* a, const std::uint16_t* b) noexcept;
int compare_g_74f8(const std::uint16_t* a, const std::uint16_t* b) noexcept;
int compare_b_7510(const std::uint16_t* a, const std::uint16_t* b) noexcept;
void insert_box_at_7670(ColorBoxNode* head, ColorBoxNode* node) noexcept;

Vec3f sRGB_to_Linear_4b54(Vec3f srgb) noexcept;
Vec3f Linear_to_sRGB_55a0(Vec3f lin) noexcept;
Vec3f RGB2OK_LAB_4f98(int r, int g, int b) noexcept;
Vec3f OK_LAB2RGB_53b8(Vec3f oklab) noexcept;
Vec3f RGB2OK_LCH_525c(int r, int g, int b) noexcept;
Vec3f OK_LCH2RGB_5670(Vec3f oklch) noexcept;
float getColorDifference_2a98(int color1, int color2) noexcept;

std::uint32_t execute_all_fde_simulations() noexcept;

} // namespace fly_main_color
} // namespace bytedance

extern "C" {
JNIEXPORT jboolean JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nIsSupportNeon(
    JNIEnv* env, jobject thiz);
JNIEXPORT jfloat JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nGetColorDifference(
    JNIEnv* env, jobject thiz, jint color1, jint color2);
JNIEXPORT jfloatArray JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nRGB2OKLCH(
    JNIEnv* env, jobject thiz, jint color, jfloatArray out_lch);
JNIEXPORT jint JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nCutMainColor(
    JNIEnv* env, jobject thiz, jobject bitmap, jintArray rect, jintArray out_colors, jintArray out_counts);
JNIEXPORT jint JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nSolveMainColor(
    JNIEnv* env, jobject thiz, jint count, jintArray colors, jintArray histogram, jintArray out_colors,
    jfloat c_min, jfloat c_max, jfloat l_min, jfloat l_max, jfloat l_mid, jfloat merge_dist, jfloat tweak_thresh);
}
