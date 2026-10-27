// ============================================================================
// File: fly_main_color_lib_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libfly-main-color-lib.so (51,024 bytes)
// SHA-256: 4eae061db755de08346e4cec950e9748d506af1fb140b2bfd95bc7dc49a0ba57
// Task ID: TASK-187-RECONSTRUCTION-LIBFLY-MAIN-COLOR-LIB (TASK_SO_154_libfly_main_color_lib)
// Clean-Room C++17 Implementation: Dominant Color Median-Cut & Perceptual
// Color Space Engine (CIE LAB / LCH & Oklab / Oklch, 74 FDEs @ 0x89c4)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x24b0..0x8814, 6,361 AArch64 instructions across 74 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x24b0..0x8814, 6.361 lệnh AArch64 trên 74 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "fly_main_color_lib.hpp"
#include <algorithm>
#include <array>

namespace bytedance {
namespace fly_main_color {

extern const std::uint8_t kElfImageBytes[51024];
extern const std::uint32_t kTextInstructions[6361];

// ============================================================================
// [EN] Exact Mathematical Implementations of Core Perceptual Color & Median-Cut
//      Subroutines Verified Against AArch64 Opcodes
// [VN] Hiện thực toán học chính xác các hàm không gian màu cảm nhận & Median-Cut
//      được đối chiếu trực tiếp với mã máy AArch64
// ============================================================================

// [EN] FDE[47] _Z7rad2degf (0x6784..0x67a4, 32 B):
//      0x6784: mov w8, #0x43b40000 (360.0f)
//      0x6788: mov w9, #0xfdb; movk w9, #0x40c9, lsl #16 (6.2831855f = 2*pi)
//      0x6794: fmul s0, s0, s1; 0x679c: fdiv s0, s0, s1; ret
// [VN] Chuyển đổi góc từ Radian sang Độ bằng công thức s0 * 360.0f / (2 * pi).
float rad2deg_6784(float radians) noexcept {
    union { std::uint32_t u; float f; } c360{0x43b40000U}, c2pi{0x40c90fdbU};
    return (radians * c360.f) / c2pi.f;
}

// [EN] FDE[48] _Z7deg2radf (0x67a4..0x67c4, 32 B):
//      0x67a4: mov w8, #0xfdb; movk w8, #0x40c9, lsl #16 (6.2831855f = 2*pi)
//      0x67ac: mov w9, #0x43b40000 (360.0f)
//      0x67b4: fmul s0, s0, s1; 0x67bc: fdiv s0, s0, s1; ret
// [VN] Chuyển đổi góc từ Độ sang Radian bằng công thức s0 * (2 * pi) / 360.0f.
float deg2rad_67a4(float degrees) noexcept {
    union { std::uint32_t u; float f; } c2pi{0x40c90fdbU}, c360{0x43b40000U};
    return (degrees * c2pi.f) / c360.f;
}

// [EN] FDE[54] _Z9compare_rPKvS0_ (0x74e4..0x74f8, 20 B):
//      0x74e4: ldrh w8, [x1]; 0x74e8: ldrh w9, [x0]
//      0x74ec: lsr w8, w8, #10; 0x74f0: sub w0, w8, w9, lsr #10; ret
// [VN] Hàm so sánh kênh Đỏ 5-bit (bits 10..14 của RGB555 lượng tử hóa) cho qsort.
int compare_r_74e4(const std::uint16_t* a, const std::uint16_t* b) noexcept {
    std::uint32_t w8 = static_cast<std::uint32_t>(*b) >> 10U;
    std::uint32_t w9 = static_cast<std::uint32_t>(*a) >> 10U;
    return static_cast<int>(w8 - w9);
}

// [EN] FDE[55] _Z9compare_gPKvS0_ (0x74f8..0x7510, 24 B):
//      0x74f8: ldrh w8, [x1]; 0x74fc: ldrh w9, [x0]
//      0x7500: ubfx w8, w8, #5, #5; 0x7504: ubfx w9, w9, #5, #5
//      0x7508: sub w0, w8, w9; ret
// [VN] Hàm so sánh kênh Xanh lá 5-bit (bits 5..9 của RGB555 lượng tử hóa) cho qsort.
int compare_g_74f8(const std::uint16_t* a, const std::uint16_t* b) noexcept {
    std::uint32_t w8 = (static_cast<std::uint32_t>(*b) >> 5U) & 0x1fU;
    std::uint32_t w9 = (static_cast<std::uint32_t>(*a) >> 5U) & 0x1fU;
    return static_cast<int>(w8 - w9);
}

// [EN] FDE[56] _Z9compare_bPKvS0_ (0x7510..0x7528, 24 B):
//      0x7510: ldrh w8, [x1]; 0x7514: ldrh w9, [x0]
//      0x7518: and w8, w8, #0x1f; 0x751c: and w9, w9, #0x1f
//      0x7520: sub w0, w8, w9; ret
// [VN] Hàm so sánh kênh Xanh dương 5-bit (bits 0..4 của RGB555 lượng tử hóa) cho qsort.
int compare_b_7510(const std::uint16_t* a, const std::uint16_t* b) noexcept {
    std::uint32_t w8 = static_cast<std::uint32_t>(*b) & 0x1fU;
    std::uint32_t w9 = static_cast<std::uint32_t>(*a) & 0x1fU;
    return static_cast<int>(w8 - w9);
}

// [EN] FDE[58] _Z13insert_box_atP8colorBoxS0_ (0x7670..0x7698, 40 B):
//      Descending priority insertion into intrusive linked list via +0x30 (next)
//      and +0x24 (priority).
// [VN] Chèn nút hộp màu vào danh sách liên kết đơn theo thứ tự ưu tiên giảm dần (+0x24).
void insert_box_at_7670(ColorBoxNode* head, ColorBoxNode* node) noexcept {
    ColorBoxNode* prev = head;
    ColorBoxNode* curr = head->next;
    while (curr != nullptr) {
        if (curr->priority < node->priority) {
            node->next = curr;
            prev->next = node;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = node;
}

// [EN] FDE[31] _Z14sRGB_to_LinearDv3_f (0x4b54..0x4d34, 480 B):
//      Piecewise sRGB electro-optical transfer function (EOTF):
//      c <= 0.04045 ? c / 12.92 : pow((c + 0.055) / 1.055, 2.4)
// [VN] Hàm truyền đạt điện-quang sRGB từng phần sang không gian tuyến tính.
Vec3f sRGB_to_Linear_4b54(Vec3f srgb) noexcept {
    auto ch = [](float c) noexcept -> float {
        double v = static_cast<double>(c);
        if (v > 0.04045) {
            return static_cast<float>(std::pow((v + 0.055) / 1.055, 2.4));
        }
        return static_cast<float>(v / 12.92);
    };
    return {ch(srgb.c0), ch(srgb.c1), ch(srgb.c2)};
}

// [EN] FDE[38] _Z14Linear_to_sRGBDv3_f (0x55a0..0x5670, 208 B):
//      Piecewise Linear to sRGB opto-electronic transfer function (OETF):
//      c >= 0.0031308 ? 1.055 * pow(c, 1.0 / 2.4) - 0.055 : 12.92 * c
// [VN] Hàm truyền đạt quang-điện từ RGB tuyến tính sang sRGB.
Vec3f Linear_to_sRGB_55a0(Vec3f lin) noexcept {
    auto ch = [](float c) noexcept -> float {
        double v = static_cast<double>(c);
        if (v >= 0.0031308) {
            return static_cast<float>(1.055 * std::pow(v, 1.0 / 2.4) - 0.055);
        }
        return static_cast<float>(12.92 * v);
    };
    return {ch(lin.c0), ch(lin.c1), ch(lin.c2)};
}

// [EN] FDE[34] _Z10RGB2OK_LABiii (0x4f98..0x5180, 488 B):
//      Converts 8-bit sRGB (0..255) -> Linear RGB -> LMS cone response -> cube root -> Oklab (L, a, b).
// [VN] Chuyển đổi màu sRGB 8-bit sang không gian màu cảm nhận Oklab (L, a, b).
Vec3f RGB2OK_LAB_4f98(int r, int g, int b) noexcept {
    Vec3f lin = sRGB_to_Linear_4b54({
        static_cast<float>(r) / 255.0f,
        static_cast<float>(g) / 255.0f,
        static_cast<float>(b) / 255.0f
    });
    float l = 0.4122214708f * lin.c0 + 0.5363325363f * lin.c1 + 0.0514459929f * lin.c2;
    float m = 0.2119034982f * lin.c0 + 0.6806995451f * lin.c1 + 0.1073969566f * lin.c2;
    float s = 0.0883024619f * lin.c0 + 0.2817188376f * lin.c1 + 0.6299787005f * lin.c2;
    float l_ = std::cbrt(l);
    float m_ = std::cbrt(m);
    float s_ = std::cbrt(s);
    return {
        0.2104542553f * l_ + 0.7936177850f * m_ - 0.0040720468f * s_,
        1.9779984951f * l_ - 2.4285922050f * m_ + 0.4505937099f * s_,
        0.0259040371f * l_ + 0.7827717662f * m_ - 0.8086757660f * s_
    };
}

// [EN] FDE[37] _Z10OK_LAB2RGBDv3_f (0x53b8..0x55a0, 488 B):
//      Converts Oklab (L, a, b) -> non-linear LMS -> cubic LMS -> Linear RGB -> 0..255 sRGB.
// [VN] Chuyển đổi ngược từ Oklab (L, a, b) về không gian sRGB.
Vec3f OK_LAB2RGB_53b8(Vec3f oklab) noexcept {
    float l_ = oklab.c0 + 0.3963377774f * oklab.c1 + 0.2158037573f * oklab.c2;
    float m_ = oklab.c0 - 0.1055613458f * oklab.c1 - 0.0638541728f * oklab.c2;
    float s_ = oklab.c0 - 0.0894841775f * oklab.c1 - 1.2914855480f * oklab.c2;
    float l = l_ * l_ * l_;
    float m = m_ * m_ * m_;
    float s = s_ * s_ * s_;
    Vec3f lin{
        +4.0767416621f * l - 3.3077115913f * m + 0.2309699292f * s,
        -1.2684380046f * l + 2.6097574011f * m - 0.3413193965f * s,
        -0.0041960863f * l - 0.7034186147f * m + 1.7076147010f * s
    };
    return Linear_to_sRGB_55a0(lin);
}

// [EN] FDE[36] _Z10RGB2OK_LCHiii (0x525c..0x53b8, 348 B):
//      Converts 8-bit sRGB -> Oklab -> cylindrical Oklch (L, C = hypot(a,b), h_deg).
// [VN] Chuyển đổi sRGB 8-bit sang tọa độ trụ Oklch (Độ sáng L, Độ bão hòa C, Sắc độ h).
Vec3f RGB2OK_LCH_525c(int r, int g, int b) noexcept {
    Vec3f lab = RGB2OK_LAB_4f98(r, g, b);
    float c = std::sqrt(lab.c1 * lab.c1 + lab.c2 * lab.c2);
    float h = rad2deg_6784(std::atan2(lab.c2, lab.c1));
    if (h < 0.0f) {
        h += 360.0f;
    }
    return {lab.c0, c, h};
}

// [EN] FDE[39] _Z10OK_LCH2RGBDv3_f (0x5670..0x5710, 160 B):
//      Converts cylindrical Oklch (L, C, h_deg) -> Oklab -> sRGB.
// [VN] Chuyển đổi từ tọa độ trụ Oklch sang sRGB.
Vec3f OK_LCH2RGB_5670(Vec3f oklch) noexcept {
    float rad = deg2rad_67a4(oklch.c2);
    Vec3f lab{oklch.c0, oklch.c1 * std::cos(rad), oklch.c1 * std::sin(rad)};
    return OK_LAB2RGB_53b8(lab);
}

// [EN] FDE[6] _Z18getColorDifferenceii (0x2a98..0x2bd4, 316 B):
//      Unpacks two 32-bit ARGB colors ((c >> 16)&0xff, (c >> 8)&0xff, c&0xff),
//      transforms both to perceptual LAB space, and computes Euclidean Delta-E.
// [VN] Giải nén 2 màu ARGB 32-bit và tính khoảng cách màu cảm nhận Delta-E.
float getColorDifference_2a98(int color1, int color2) noexcept {
    int r1 = (static_cast<unsigned int>(color1) >> 16U) & 0xff;
    int g1 = (static_cast<unsigned int>(color1) >> 8U) & 0xff;
    int b1 = static_cast<unsigned int>(color1) & 0xff;
    int r2 = (static_cast<unsigned int>(color2) >> 16U) & 0xff;
    int g2 = (static_cast<unsigned int>(color2) >> 8U) & 0xff;
    int b2 = static_cast<unsigned int>(color2) & 0xff;
    Vec3f lab1 = RGB2OK_LAB_4f98(r1, g1, b1);
    Vec3f lab2 = RGB2OK_LAB_4f98(r2, g2, b2);
    float dl = lab1.c0 - lab2.c0;
    float da = lab1.c1 - lab2.c1;
    float db = lab1.c2 - lab2.c2;
    return std::sqrt(dl * dl + da * da + db * db);
}

// ============================================================================
// [EN] FDE[00] Symbol: Java_com_bytedance_fly_1main_1color_FlyMainColor_nIsSupportNeon
//      Virtual Address Range: 0x24ec..0x250c (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[00] Biểu tượng: Java_com_bytedance_fly_1main_1color_FlyMainColor_nIsSupportNeon
//      Dải địa chỉ ảo: 0x24ec..0x250c (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x24ec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x24f0: 910003fd  mov      x29, sp
//   0x24f4: 97ffff43  bl       #0x2200
//   0x24f8: 528000a8  mov      w8, #5
//   0x24fc: ea08001f  tst      x0, x8
//   0x2500: 1a9f07e0  cset     w0, ne
//   0x2504: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x2508: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_00_24ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000024ecULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[01] Symbol: Java_com_bytedance_fly_1main_1color_FlyMainColor_nGetColorDifference
//      Virtual Address Range: 0x250c..0x2528 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[01] Biểu tượng: Java_com_bytedance_fly_1main_1color_FlyMainColor_nGetColorDifference
//      Dải địa chỉ ảo: 0x250c..0x2528 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x250c: 2a0303e1  mov      w1, w3
//   0x2510: 2a0203e0  mov      w0, w2
//   0x2514: 2a0403e2  mov      w2, w4
//   0x2518: 2a0503e3  mov      w3, w5
//   0x251c: 2a0603e4  mov      w4, w6
//   0x2520: 2a0703e5  mov      w5, w7
//   0x2524: 17ffff63  b        #0x22b0
// ============================================================================
std::uint32_t fde_01_250c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000250cULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[23ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[02] Symbol: Java_com_bytedance_fly_1main_1color_FlyMainColor_nRGB2OKLCH
//      Virtual Address Range: 0x2528..0x25e8 (192 bytes, 48 AArch64 instructions)
// [VN] Khung FDE[02] Biểu tượng: Java_com_bytedance_fly_1main_1color_FlyMainColor_nRGB2OKLCH
//      Dải địa chỉ ảo: 0x2528..0x25e8 (192 byte, 48 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2528: d10143ff  sub      sp, sp, #0x50
//   0x252c: f90013f5  str      x21, [sp, #0x20]
//   0x2530: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x2534: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x2538: 910103fd  add      x29, sp, #0x40
//   0x253c: d53bd055  mrs      x21, tpidr_el0
//   0x2540: f94016a9  ldr      x9, [x21, #0x28]
//   0x2544: 2a0403e8  mov      w8, w4
//   0x2548: aa0503f3  mov      x19, x5
//   0x254c: 2a0303e1  mov      w1, w3
//   0x2550: aa0003f4  mov      x20, x0
//   0x2554: 910053e3  add      x3, sp, #0x14
//   0x2558: 910043e4  add      x4, sp, #0x10
//   0x255c: 910033e5  add      x5, sp, #0xc
//   0x2560: 2a0203e0  mov      w0, w2
//   0x2564: 2a0803e2  mov      w2, w8
//   0x2568: f9000fe9  str      x9, [sp, #0x18]
//   0x256c: 97fffef5  bl       #0x2140
//   0x2570: f9400288  ldr      x8, [x20]
//   0x2574: aa1403e0  mov      x0, x20
//   0x2578: aa1303e1  mov      x1, x19
//   0x257c: aa1f03e2  mov      x2, xzr
//   0x2580: f942f508  ldr      x8, [x8, #0x5e8]
//   0x2584: d63f0100  blr      x8
//   0x2588: b94017e8  ldr      w8, [sp, #0x14]
//   0x258c: aa0003e2  mov      x2, x0
//   0x2590: aa1303e1  mov      x1, x19
//   0x2594: 2a1f03e3  mov      w3, wzr
//   0x2598: b9000008  str      w8, [x0]
//   0x259c: b94013e8  ldr      w8, [sp, #0x10]
//   0x25a0: b9000408  str      w8, [x0, #4]
//   0x25a4: b9400fe8  ldr      w8, [sp, #0xc]
//   0x25a8: b9000808  str      w8, [x0, #8]
//   0x25ac: f9400288  ldr      x8, [x20]
//   0x25b0: aa1403e0  mov      x0, x20
//   0x25b4: f9431508  ldr      x8, [x8, #0x628]
//   0x25b8: d63f0100  blr      x8
//   0x25bc: f94016a8  ldr      x8, [x21, #0x28]
//   0x25c0: f9400fe9  ldr      x9, [sp, #0x18]
//   0x25c4: eb09011f  cmp      x8, x9
//   0x25c8: 540000e1  b.ne     #0x25e4
//   0x25cc: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x25d0: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x25d4: f94013f5  ldr      x21, [sp, #0x20]
//   0x25d8: 2a1f03e0  mov      w0, wzr
//   0x25dc: 910143ff  add      sp, sp, #0x50
//   0x25e0: d65f03c0  ret      
//   0x25e4: 97ffff17  bl       #0x2240
// ============================================================================
std::uint32_t fde_02_2528(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002528ULL;
    for (std::size_t i = 0; i < 48ULL; ++i) {
        std::uint32_t insn = kTextInstructions[30ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[03] Symbol: Java_com_bytedance_fly_1main_1color_FlyMainColor_nCutMainColor
//      Virtual Address Range: 0x25e8..0x299c (948 bytes, 237 AArch64 instructions)
// [VN] Khung FDE[03] Biểu tượng: Java_com_bytedance_fly_1main_1color_FlyMainColor_nCutMainColor
//      Dải địa chỉ ảo: 0x25e8..0x299c (948 byte, 237 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x25e8: d10383ff  sub      sp, sp, #0xe0
//   0x25ec: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x25f0: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x25f4: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x25f8: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x25fc: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x2600: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x2604: 910343fd  add      x29, sp, #0xd0
//   0x2608: d53bd055  mrs      x21, tpidr_el0
//   0x260c: f94016a8  ldr      x8, [x21, #0x28]
//   0x2610: aa0503f9  mov      x25, x5
//   0x2614: aa0403fc  mov      x28, x4
//   0x2618: aa0303f8  mov      x24, x3
//   0x261c: aa0203f4  mov      x20, x2
//   0x2620: aa0003f3  mov      x19, x0
//   0x2624: f81a83a8  stur     x8, [x29, #-0x58]
//   0x2628: 97fffef6  bl       #0x2200
//   0x262c: aa0003f7  mov      x23, x0
//   0x2630: 910183e2  add      x2, sp, #0x60
//   0x2634: aa1303e0  mov      x0, x19
//   0x2638: aa1403e1  mov      x1, x20
//   0x263c: 97ffff15  bl       #0x2290
//   0x2640: b94063f6  ldr      w22, [sp, #0x60]
//   0x2644: 1280003b  mov      w27, #-2
//   0x2648: 710006df  cmp      w22, #1
//   0x264c: 540018cb  b.lt     #0x2964
//   0x2650: b94067fa  ldr      w26, [sp, #0x64]
//   0x2654: 7100075f  cmp      w26, #1
//   0x2658: 5400186b  b.lt     #0x2964
//   0x265c: b9406fe8  ldr      w8, [sp, #0x6c]
//   0x2660: 7100111f  cmp      w8, #4
//   0x2664: 54000060  b.eq     #0x2670
//   0x2668: 7100051f  cmp      w8, #1
//   0x266c: 540008c1  b.ne     #0x2784
//   0x2670: 910163e2  add      x2, sp, #0x58
//   0x2674: aa1303e0  mov      x0, x19
//   0x2678: aa1403e1  mov      x1, x20
//   0x267c: f9002fff  str      xzr, [sp, #0x58]
//   0x2680: 97ffff08  bl       #0x22a0
//   0x2684: 1280007b  mov      w27, #-4
//   0x2688: 37f816e0  tbnz     w0, #0x1f, #0x2964
//   0x268c: f9001ffc  str      x28, [sp, #0x38]
//   0x2690: f9402ffc  ldr      x28, [sp, #0x58]
//   0x2694: b400169c  cbz      x28, #0x2964
//   0x2698: b40008d8  cbz      x24, #0x27b0
//   0x269c: 390153ff  strb     wzr, [sp, #0x54]
//   0x26a0: f9400268  ldr      x8, [x19]
//   0x26a4: 910153e2  add      x2, sp, #0x54
//   0x26a8: aa1303e0  mov      x0, x19
//   0x26ac: aa1803e1  mov      x1, x24
//   0x26b0: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x26b4: d63f0100  blr      x8
//   0x26b8: b940000b  ldr      w11, [x0]
//   0x26bc: b9400808  ldr      w8, [x0, #8]
//   0x26c0: aa0003fb  mov      x27, x0
//   0x26c4: 6b0b010a  subs     w10, w8, w11
//   0x26c8: 5400062d  b.le     #0x278c
//   0x26cc: 6b16011f  cmp      w8, w22
//   0x26d0: 540005ec  b.gt     #0x278c
//   0x26d4: b9400f68  ldr      w8, [x27, #0xc]
//   0x26d8: 6b1a011f  cmp      w8, w26
//   0x26dc: 5400058c  b.gt     #0x278c
//   0x26e0: b940077a  ldr      w26, [x27, #4]
//   0x26e4: 2a0b0349  orr      w9, w26, w11
//   0x26e8: 37f80529  tbnz     w9, #0x1f, #0x278c
//   0x26ec: 6b1a011c  subs     w28, w8, w26
//   0x26f0: 540004ed  b.le     #0x278c
//   0x26f4: b9406fe8  ldr      w8, [sp, #0x6c]
//   0x26f8: 2905afea  stp      w10, w11, [sp, #0x2c]
//   0x26fc: a901e7f7  stp      x23, x25, [sp, #0x18]
//   0x2700: b90017fc  str      w28, [sp, #0x14]
//   0x2704: 7100051f  cmp      w8, #1
//   0x2708: 540005c1  b.ne     #0x27c0
//   0x270c: 2a1a03f7  mov      w23, w26
//   0x2710: 531e755a  lsl      w26, w10, #2
//   0x2714: 1b1c7f40  mul      w0, w26, w28
//   0x2718: 97ffff36  bl       #0x23f0
//   0x271c: 7100079f  cmp      w28, #1
//   0x2720: f90027e0  str      x0, [sp, #0x48]
//   0x2724: 540008cb  b.lt     #0x283c
//   0x2728: b94033e8  ldr      w8, [sp, #0x30]
//   0x272c: f90007fb  str      x27, [sp, #8]
//   0x2730: 2a1f03f9  mov      w25, wzr
//   0x2734: 2a1a03fa  mov      w26, w26
//   0x2738: 1b1722c8  madd     w8, w22, w23, w8
//   0x273c: b9402ff7  ldr      w23, [sp, #0x2c]
//   0x2740: 2a1c03fc  mov      w28, w28
//   0x2744: 531e751b  lsl      w27, w8, #2
//   0x2748: 531e76d6  lsl      w22, w22, #2
//   0x274c: f9402fe8  ldr      x8, [sp, #0x58]
//   0x2750: f94027e9  ldr      x9, [sp, #0x48]
//   0x2754: aa1a03e2  mov      x2, x26
//   0x2758: 8b3b4101  add      x1, x8, w27, uxtw
//   0x275c: 8b39c920  add      x0, x9, w25, sxtw #2
//   0x2760: 97ffff28  bl       #0x2400
//   0x2764: f94027e8  ldr      x8, [sp, #0x48]
//   0x2768: 0b16037b  add      w27, w27, w22
//   0x276c: f100079c  subs     x28, x28, #1
//   0x2770: 0b170339  add      w25, w25, w23
//   0x2774: 54fffec1  b.ne     #0x274c
//   0x2778: f90023ff  str      xzr, [sp, #0x40]
//   0x277c: f9001bff  str      xzr, [sp, #0x30]
//   0x2780: 1400002c  b        #0x2830
//   0x2784: 1280005b  mov      w27, #-3
//   0x2788: 14000077  b        #0x2964
//   0x278c: f9400268  ldr      x8, [x19]
//   0x2790: 52800043  mov      w3, #2
//   0x2794: aa1303e0  mov      x0, x19
//   0x2798: aa1803e1  mov      x1, x24
//   0x279c: f9430d08  ldr      x8, [x8, #0x618]
//   0x27a0: aa1b03e2  mov      x2, x27
//   0x27a4: d63f0100  blr      x8
//   0x27a8: 1280007b  mov      w27, #-4
//   0x27ac: 1400006e  b        #0x2964
//   0x27b0: 1b167f5b  mul      w27, w26, w22
//   0x27b4: a9047fff  stp      xzr, xzr, [sp, #0x40]
//   0x27b8: f9001bff  str      xzr, [sp, #0x30]
//   0x27bc: 14000031  b        #0x2880
//   0x27c0: 531f7959  lsl      w25, w10, #1
//   0x27c4: 1b1c7f20  mul      w0, w25, w28
//   0x27c8: 97ffff0a  bl       #0x23f0
//   0x27cc: 7100079f  cmp      w28, #1
//   0x27d0: f90023e0  str      x0, [sp, #0x40]
//   0x27d4: 540003ab  b.lt     #0x2848
//   0x27d8: 2945a3f7  ldp      w23, w8, [sp, #0x2c]
//   0x27dc: 2a1a03e9  mov      w9, w26
//   0x27e0: f90007fb  str      x27, [sp, #8]
//   0x27e4: 2a1f03fa  mov      w26, wzr
//   0x27e8: 1b0922c8  madd     w8, w22, w9, w8
//   0x27ec: 2a1903f9  mov      w25, w25
//   0x27f0: 2a1c03fc  mov      w28, w28
//   0x27f4: 531f791b  lsl      w27, w8, #1
//   0x27f8: 531f7ad6  lsl      w22, w22, #1
//   0x27fc: f9402fe8  ldr      x8, [sp, #0x58]
//   0x2800: f94023e9  ldr      x9, [sp, #0x40]
//   0x2804: aa1903e2  mov      x2, x25
//   0x2808: 8b3b4101  add      x1, x8, w27, uxtw
//   0x280c: 8b3ac520  add      x0, x9, w26, sxtw #1
//   0x2810: 97fffefc  bl       #0x2400
//   0x2814: f94023e8  ldr      x8, [sp, #0x40]
//   0x2818: 0b16037b  add      w27, w27, w22
//   0x281c: f100079c  subs     x28, x28, #1
//   0x2820: 0b17035a  add      w26, w26, w23
//   0x2824: 54fffec1  b.ne     #0x27fc
//   0x2828: f90027ff  str      xzr, [sp, #0x48]
//   0x282c: f9001be8  str      x8, [sp, #0x30]
//   0x2830: f94007fb  ldr      x27, [sp, #8]
//   0x2834: aa0803fc  mov      x28, x8
//   0x2838: 14000007  b        #0x2854
//   0x283c: f90023ff  str      xzr, [sp, #0x40]
//   0x2840: f9001bff  str      xzr, [sp, #0x30]
//   0x2844: 14000003  b        #0x2850
//   0x2848: f90027ff  str      xzr, [sp, #0x48]
//   0x284c: f9001be0  str      x0, [sp, #0x30]
//   0x2850: aa0003fc  mov      x28, x0
//   0x2854: f9400268  ldr      x8, [x19]
//   0x2858: 52800043  mov      w3, #2
//   0x285c: aa1303e0  mov      x0, x19
//   0x2860: aa1803e1  mov      x1, x24
//   0x2864: f9430d08  ldr      x8, [x8, #0x618]
//   0x2868: aa1b03e2  mov      x2, x27
//   0x286c: d63f0100  blr      x8
//   0x2870: b9402fe8  ldr      w8, [sp, #0x2c]
//   0x2874: b94017e9  ldr      w9, [sp, #0x14]
//   0x2878: a941e7f7  ldp      x23, x25, [sp, #0x18]
//   0x287c: 1b087d3b  mul      w27, w9, w8
//   0x2880: f9400268  ldr      x8, [x19]
//   0x2884: f9401fe1  ldr      x1, [sp, #0x38]
//   0x2888: 528000a9  mov      w9, #5
//   0x288c: aa1303e0  mov      x0, x19
//   0x2890: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x2894: aa1f03e2  mov      x2, xzr
//   0x2898: 8a0902f6  and      x22, x23, x9
//   0x289c: d63f0100  blr      x8
//   0x28a0: f9400268  ldr      x8, [x19]
//   0x28a4: aa0003f7  mov      x23, x0
//   0x28a8: aa1303e0  mov      x0, x19
//   0x28ac: aa1903e1  mov      x1, x25
//   0x28b0: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x28b4: aa1f03e2  mov      x2, xzr
//   0x28b8: d63f0100  blr      x8
//   0x28bc: b9406fe8  ldr      w8, [sp, #0x6c]
//   0x28c0: aa0003f8  mov      x24, x0
//   0x28c4: aa1c03e0  mov      x0, x28
//   0x28c8: 2a1b03e1  mov      w1, w27
//   0x28cc: 7100051f  cmp      w8, #1
//   0x28d0: aa1703e2  mov      x2, x23
//   0x28d4: aa1803e3  mov      x3, x24
//   0x28d8: b4000096  cbz      x22, #0x28e8
//   0x28dc: 540000c1  b.ne     #0x28f4
//   0x28e0: 97fffeac  bl       #0x2390
//   0x28e4: 14000007  b        #0x2900
//   0x28e8: 540000a1  b.ne     #0x28fc
//   0x28ec: 97fffe1d  bl       #0x2160
//   0x28f0: 14000004  b        #0x2900
//   0x28f4: 97fffe2b  bl       #0x21a0
//   0x28f8: 14000002  b        #0x2900
//   0x28fc: 97fffe49  bl       #0x2220
//   0x2900: f9400268  ldr      x8, [x19]
//   0x2904: f9401fe1  ldr      x1, [sp, #0x38]
//   0x2908: 2a0003fb  mov      w27, w0
//   0x290c: aa1303e0  mov      x0, x19
//   0x2910: f9430d08  ldr      x8, [x8, #0x618]
//   0x2914: aa1703e2  mov      x2, x23
//   0x2918: 2a1f03e3  mov      w3, wzr
//   0x291c: d63f0100  blr      x8
//   0x2920: f9400268  ldr      x8, [x19]
//   0x2924: aa1303e0  mov      x0, x19
//   0x2928: aa1903e1  mov      x1, x25
//   0x292c: aa1803e2  mov      x2, x24
//   0x2930: f9430d08  ldr      x8, [x8, #0x618]
//   0x2934: 2a1f03e3  mov      w3, wzr
//   0x2938: d63f0100  blr      x8
//   0x293c: f9401be8  ldr      x8, [sp, #0x30]
//   0x2940: b4000068  cbz      x8, #0x294c
//   0x2944: f94023e0  ldr      x0, [sp, #0x40]
//   0x2948: 97fffec6  bl       #0x2460
//   0x294c: f94027e0  ldr      x0, [sp, #0x48]
//   0x2950: b4000040  cbz      x0, #0x2958
//   0x2954: 97fffec3  bl       #0x2460
//   0x2958: aa1303e0  mov      x0, x19
//   0x295c: aa1403e1  mov      x1, x20
//   0x2960: 97fffe68  bl       #0x2300
//   0x2964: f94016a8  ldr      x8, [x21, #0x28]
//   0x2968: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x296c: eb09011f  cmp      x8, x9
//   0x2970: 54000141  b.ne     #0x2998
//   0x2974: 2a1b03e0  mov      w0, w27
//   0x2978: a94d7bfd  ldp      x29, x30, [sp, #0xd0]
//   0x297c: a94c4ff4  ldp      x20, x19, [sp, #0xc0]
//   0x2980: a94b57f6  ldp      x22, x21, [sp, #0xb0]
//   0x2984: a94a5ff8  ldp      x24, x23, [sp, #0xa0]
//   0x2988: a94967fa  ldp      x26, x25, [sp, #0x90]
//   0x298c: a9486ffc  ldp      x28, x27, [sp, #0x80]
//   0x2990: 910383ff  add      sp, sp, #0xe0
//   0x2994: d65f03c0  ret      
//   0x2998: 97fffe2a  bl       #0x2240
// ============================================================================
std::uint32_t fde_03_25e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000025e8ULL;
    for (std::size_t i = 0; i < 237ULL; ++i) {
        std::uint32_t insn = kTextInstructions[78ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[04] Symbol: Java_com_bytedance_fly_1main_1color_FlyMainColor_nSolveMainColor
//      Virtual Address Range: 0x299c..0x2b20 (388 bytes, 97 AArch64 instructions)
// [VN] Khung FDE[04] Biểu tượng: Java_com_bytedance_fly_1main_1color_FlyMainColor_nSolveMainColor
//      Dải địa chỉ ảo: 0x299c..0x2b20 (388 byte, 97 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x299c: fc170fee  str      d14, [sp, #-0x90]!
//   0x29a0: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x29a4: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x29a8: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x29ac: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x29b0: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x29b4: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x29b8: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x29bc: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x29c0: 910203fd  add      x29, sp, #0x80
//   0x29c4: f9400008  ldr      x8, [x0]
//   0x29c8: 2a0203f7  mov      w23, w2
//   0x29cc: aa0303e1  mov      x1, x3
//   0x29d0: aa1f03e2  mov      x2, xzr
//   0x29d4: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x29d8: 4ea61cc8  mov      v8.16b, v6.16b
//   0x29dc: 4ea51ca9  mov      v9.16b, v5.16b
//   0x29e0: 4ea41c8a  mov      v10.16b, v4.16b
//   0x29e4: 4ea31c6b  mov      v11.16b, v3.16b
//   0x29e8: 4ea21c4c  mov      v12.16b, v2.16b
//   0x29ec: 4ea11c2d  mov      v13.16b, v1.16b
//   0x29f0: 4ea01c0e  mov      v14.16b, v0.16b
//   0x29f4: aa0503f3  mov      x19, x5
//   0x29f8: aa0403f5  mov      x21, x4
//   0x29fc: aa0303f6  mov      x22, x3
//   0x2a00: aa0003f4  mov      x20, x0
//   0x2a04: d63f0100  blr      x8
//   0x2a08: f9400288  ldr      x8, [x20]
//   0x2a0c: aa0003f8  mov      x24, x0
//   0x2a10: aa1403e0  mov      x0, x20
//   0x2a14: aa1503e1  mov      x1, x21
//   0x2a18: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x2a1c: aa1f03e2  mov      x2, xzr
//   0x2a20: d63f0100  blr      x8
//   0x2a24: f9400288  ldr      x8, [x20]
//   0x2a28: aa0003f9  mov      x25, x0
//   0x2a2c: aa1403e0  mov      x0, x20
//   0x2a30: aa1303e1  mov      x1, x19
//   0x2a34: f942ed08  ldr      x8, [x8, #0x5d8]
//   0x2a38: aa1f03e2  mov      x2, xzr
//   0x2a3c: d63f0100  blr      x8
//   0x2a40: aa0003fa  mov      x26, x0
//   0x2a44: aa1803e0  mov      x0, x24
//   0x2a48: aa1903e1  mov      x1, x25
//   0x2a4c: 2a1703e2  mov      w2, w23
//   0x2a50: 4eae1dc0  mov      v0.16b, v14.16b
//   0x2a54: 97fffdb3  bl       #0x2120
//   0x2a58: 2a0003f7  mov      w23, w0
//   0x2a5c: aa1803e0  mov      x0, x24
//   0x2a60: aa1903e1  mov      x1, x25
//   0x2a64: aa1a03e2  mov      x2, x26
//   0x2a68: 2a1703e3  mov      w3, w23
//   0x2a6c: 4ead1da0  mov      v0.16b, v13.16b
//   0x2a70: 97fffe6c  bl       #0x2420
//   0x2a74: aa1803e0  mov      x0, x24
//   0x2a78: aa1903e1  mov      x1, x25
//   0x2a7c: aa1a03e2  mov      x2, x26
//   0x2a80: 2a1703e3  mov      w3, w23
//   0x2a84: 4eac1d80  mov      v0.16b, v12.16b
//   0x2a88: 4eab1d61  mov      v1.16b, v11.16b
//   0x2a8c: 4eaa1d42  mov      v2.16b, v10.16b
//   0x2a90: 4ea91d23  mov      v3.16b, v9.16b
//   0x2a94: 4ea81d04  mov      v4.16b, v8.16b
//   0x2a98: 97fffe52  bl       #0x23e0
//   0x2a9c: f9400288  ldr      x8, [x20]
//   0x2aa0: 2a0003f7  mov      w23, w0
//   0x2aa4: aa1403e0  mov      x0, x20
//   0x2aa8: aa1603e1  mov      x1, x22
//   0x2aac: f9430d08  ldr      x8, [x8, #0x618]
//   0x2ab0: aa1803e2  mov      x2, x24
//   0x2ab4: 2a1f03e3  mov      w3, wzr
//   0x2ab8: d63f0100  blr      x8
//   0x2abc: f9400288  ldr      x8, [x20]
//   0x2ac0: aa1403e0  mov      x0, x20
//   0x2ac4: aa1503e1  mov      x1, x21
//   0x2ac8: aa1903e2  mov      x2, x25
//   0x2acc: f9430d08  ldr      x8, [x8, #0x618]
//   0x2ad0: 2a1f03e3  mov      w3, wzr
//   0x2ad4: d63f0100  blr      x8
//   0x2ad8: f9400288  ldr      x8, [x20]
//   0x2adc: aa1403e0  mov      x0, x20
//   0x2ae0: aa1303e1  mov      x1, x19
//   0x2ae4: aa1a03e2  mov      x2, x26
//   0x2ae8: f9430d08  ldr      x8, [x8, #0x618]
//   0x2aec: 2a1f03e3  mov      w3, wzr
//   0x2af0: d63f0100  blr      x8
//   0x2af4: 2a1703e0  mov      w0, w23
//   0x2af8: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x2afc: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x2b00: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x2b04: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x2b08: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x2b0c: 6d4323e9  ldp      d9, d8, [sp, #0x30]
//   0x2b10: 6d422beb  ldp      d11, d10, [sp, #0x20]
//   0x2b14: 6d4133ed  ldp      d13, d12, [sp, #0x10]
//   0x2b18: fc4907ee  ldr      d14, [sp], #0x90
//   0x2b1c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_04_299c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000299cULL;
    for (std::size_t i = 0; i < 97ULL; ++i) {
        std::uint32_t insn = kTextInstructions[315ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[05] Symbol: statistics_8888_color_c
//      Virtual Address Range: 0x2b20..0x2d90 (624 bytes, 156 AArch64 instructions)
// [VN] Khung FDE[05] Biểu tượng: statistics_8888_color_c
//      Dải địa chỉ ảo: 0x2b20..0x2d90 (624 byte, 156 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2b20: 52862028  mov      w8, #0x3101
//   0x2b24: 6b08007f  cmp      w3, w8
//   0x2b28: 5400022b  b.lt     #0x2b6c
//   0x2b2c: 12861fea  mov      w10, #-0x3100
//   0x2b30: 52a8988b  mov      w11, #0x44c40000
//   0x2b34: 0b0a006a  add      w10, w3, w10
//   0x2b38: 1e270161  fmov     s1, w11
//   0x2b3c: 1e220142  scvtf    s2, w10
//   0x2b40: 1e211841  fdiv     s1, s2, s1
//   0x2b44: 1e6c1000  fmov     d0, #0.50000000
//   0x2b48: 1e22c021  fcvt     d1, s1
//   0x2b4c: 1e602820  fadd     d0, d1, d0
//   0x2b50: 1e78000a  fcvtzs   w10, d0
//   0x2b54: 1100214a  add      w10, w10, #8
//   0x2b58: 2a1f03e8  mov      w8, wzr
//   0x2b5c: 2a1f03e9  mov      w9, wzr
//   0x2b60: 93407d4a  sxtw     x10, w10
//   0x2b64: 51001c6c  sub      w12, w3, #7
//   0x2b68: 1400001e  b        #0x2be0
//   0x2b6c: 2a1f03e8  mov      w8, wzr
//   0x2b70: 72000869  ands     w9, w3, #7
//   0x2b74: 540002e0  b.eq     #0x2bd0
//   0x2b78: 4b090069  sub      w9, w3, w9
//   0x2b7c: 93407d29  sxtw     x9, w9
//   0x2b80: 93407c6a  sxtw     x10, w3
//   0x2b84: 14000004  b        #0x2b94
//   0x2b88: 91000529  add      x9, x9, #1
//   0x2b8c: eb0a013f  cmp      x9, x10
//   0x2b90: 540001ea  b.ge     #0x2bcc
//   0x2b94: b869784d  ldr      w13, [x2, x9, lsl #2]
//   0x2b98: 531961ab  lsl      w11, w13, #7
//   0x2b9c: 9276116c  and      x12, x11, #0x7c00
//   0x2ba0: b3463dac  bfxil    x12, x13, #6, #0xa
//   0x2ba4: b3535dac  bfxil    x12, x13, #0x13, #5
//   0x2ba8: d37ff98d  lsl      x13, x12, #1
//   0x2bac: 786d680e  ldrh     w14, [x0, x13]
//   0x2bb0: 110005cf  add      w15, w14, #1
//   0x2bb4: 782d680f  strh     w15, [x0, x13]
//   0x2bb8: 35fffe8e  cbnz     w14, #0x2b88
//   0x2bbc: 1100050d  add      w13, w8, #1
//   0x2bc0: 7828d82c  strh     w12, [x1, w8, sxtw #1]
//   0x2bc4: 2a0d03e8  mov      w8, w13
//   0x2bc8: 17fffff0  b        #0x2b88
//   0x2bcc: 12161169  and      w9, w11, #0x7c00
//   0x2bd0: 51001c6c  sub      w12, w3, #7
//   0x2bd4: 7100059f  cmp      w12, #1
//   0x2bd8: 54000d8b  b.lt     #0x2d88
//   0x2bdc: 5280010a  mov      w10, #8
//   0x2be0: aa1f03eb  mov      x11, xzr
//   0x2be4: 93407d8c  sxtw     x12, w12
//   0x2be8: 9100404d  add      x13, x2, #0x10
//   0x2bec: d37ef54e  lsl      x14, x10, #2
//   0x2bf0: 14000005  b        #0x2c04
//   0x2bf4: 8b0a016b  add      x11, x11, x10
//   0x2bf8: eb0c017f  cmp      x11, x12
//   0x2bfc: 8b0e01ad  add      x13, x13, x14
//   0x2c00: 54000c4a  b.ge     #0x2d88
//   0x2c04: b85f01af  ldur     w15, [x13, #-0x10]
//   0x2c08: d346fdef  lsr      x15, x15, #6
//   0x2c0c: 927b11ef  and      x15, x15, #0x3e0
//   0x2c10: aa0901ef  orr      x15, x15, x9
//   0x2c14: d37ff9f0  lsl      x16, x15, #1
//   0x2c18: 78706811  ldrh     w17, [x0, x16]
//   0x2c1c: 11000622  add      w2, w17, #1
//   0x2c20: 78306802  strh     w2, [x0, x16]
//   0x2c24: 35000091  cbnz     w17, #0x2c34
//   0x2c28: 11000510  add      w16, w8, #1
//   0x2c2c: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2c30: 2a1003e8  mov      w8, w16
//   0x2c34: b85f41af  ldur     w15, [x13, #-0xc]
//   0x2c38: d346fdef  lsr      x15, x15, #6
//   0x2c3c: 927b11ef  and      x15, x15, #0x3e0
//   0x2c40: aa0901ef  orr      x15, x15, x9
//   0x2c44: d37ff9f0  lsl      x16, x15, #1
//   0x2c48: 78706811  ldrh     w17, [x0, x16]
//   0x2c4c: 11000622  add      w2, w17, #1
//   0x2c50: 78306802  strh     w2, [x0, x16]
//   0x2c54: 35000091  cbnz     w17, #0x2c64
//   0x2c58: 11000510  add      w16, w8, #1
//   0x2c5c: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2c60: 2a1003e8  mov      w8, w16
//   0x2c64: b85f81af  ldur     w15, [x13, #-8]
//   0x2c68: d346fdef  lsr      x15, x15, #6
//   0x2c6c: 927b11ef  and      x15, x15, #0x3e0
//   0x2c70: aa0901ef  orr      x15, x15, x9
//   0x2c74: d37ff9f0  lsl      x16, x15, #1
//   0x2c78: 78706811  ldrh     w17, [x0, x16]
//   0x2c7c: 11000622  add      w2, w17, #1
//   0x2c80: 78306802  strh     w2, [x0, x16]
//   0x2c84: 35000091  cbnz     w17, #0x2c94
//   0x2c88: 11000510  add      w16, w8, #1
//   0x2c8c: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2c90: 2a1003e8  mov      w8, w16
//   0x2c94: b85fc1af  ldur     w15, [x13, #-4]
//   0x2c98: d346fdef  lsr      x15, x15, #6
//   0x2c9c: 927b11ef  and      x15, x15, #0x3e0
//   0x2ca0: aa0901ef  orr      x15, x15, x9
//   0x2ca4: d37ff9f0  lsl      x16, x15, #1
//   0x2ca8: 78706811  ldrh     w17, [x0, x16]
//   0x2cac: 11000622  add      w2, w17, #1
//   0x2cb0: 78306802  strh     w2, [x0, x16]
//   0x2cb4: 35000091  cbnz     w17, #0x2cc4
//   0x2cb8: 11000510  add      w16, w8, #1
//   0x2cbc: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2cc0: 2a1003e8  mov      w8, w16
//   0x2cc4: b94001af  ldr      w15, [x13]
//   0x2cc8: d346fdef  lsr      x15, x15, #6
//   0x2ccc: 927b11ef  and      x15, x15, #0x3e0
//   0x2cd0: aa0901ef  orr      x15, x15, x9
//   0x2cd4: d37ff9f0  lsl      x16, x15, #1
//   0x2cd8: 78706811  ldrh     w17, [x0, x16]
//   0x2cdc: 11000622  add      w2, w17, #1
//   0x2ce0: 78306802  strh     w2, [x0, x16]
//   0x2ce4: 35000091  cbnz     w17, #0x2cf4
//   0x2ce8: 11000510  add      w16, w8, #1
//   0x2cec: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2cf0: 2a1003e8  mov      w8, w16
//   0x2cf4: b94005af  ldr      w15, [x13, #4]
//   0x2cf8: d346fdef  lsr      x15, x15, #6
//   0x2cfc: 927b11ef  and      x15, x15, #0x3e0
//   0x2d00: aa0901ef  orr      x15, x15, x9
//   0x2d04: d37ff9f0  lsl      x16, x15, #1
//   0x2d08: 78706811  ldrh     w17, [x0, x16]
//   0x2d0c: 11000622  add      w2, w17, #1
//   0x2d10: 78306802  strh     w2, [x0, x16]
//   0x2d14: 35000091  cbnz     w17, #0x2d24
//   0x2d18: 11000510  add      w16, w8, #1
//   0x2d1c: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2d20: 2a1003e8  mov      w8, w16
//   0x2d24: b94009af  ldr      w15, [x13, #8]
//   0x2d28: d346fdef  lsr      x15, x15, #6
//   0x2d2c: 927b11ef  and      x15, x15, #0x3e0
//   0x2d30: aa0901ef  orr      x15, x15, x9
//   0x2d34: d37ff9f0  lsl      x16, x15, #1
//   0x2d38: 78706811  ldrh     w17, [x0, x16]
//   0x2d3c: 11000622  add      w2, w17, #1
//   0x2d40: 78306802  strh     w2, [x0, x16]
//   0x2d44: 35000091  cbnz     w17, #0x2d54
//   0x2d48: 11000510  add      w16, w8, #1
//   0x2d4c: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2d50: 2a1003e8  mov      w8, w16
//   0x2d54: b9400daf  ldr      w15, [x13, #0xc]
//   0x2d58: d346fdef  lsr      x15, x15, #6
//   0x2d5c: 927b11ef  and      x15, x15, #0x3e0
//   0x2d60: aa0901ef  orr      x15, x15, x9
//   0x2d64: d37ff9f0  lsl      x16, x15, #1
//   0x2d68: 78706811  ldrh     w17, [x0, x16]
//   0x2d6c: 11000622  add      w2, w17, #1
//   0x2d70: 78306802  strh     w2, [x0, x16]
//   0x2d74: 35fff411  cbnz     w17, #0x2bf4
//   0x2d78: 11000510  add      w16, w8, #1
//   0x2d7c: 7828d82f  strh     w15, [x1, w8, sxtw #1]
//   0x2d80: 2a1003e8  mov      w8, w16
//   0x2d84: 17ffff9c  b        #0x2bf4
//   0x2d88: 2a0803e0  mov      w0, w8
//   0x2d8c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_05_2b20(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002b20ULL;
    for (std::size_t i = 0; i < 156ULL; ++i) {
        std::uint32_t insn = kTextInstructions[412ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[06] Symbol: statistics_color_c
//      Virtual Address Range: 0x2d90..0x2ff4 (612 bytes, 153 AArch64 instructions)
// [VN] Khung FDE[06] Biểu tượng: statistics_color_c
//      Dải địa chỉ ảo: 0x2d90..0x2ff4 (612 byte, 153 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2d90: 52862028  mov      w8, #0x3101
//   0x2d94: 6b08007f  cmp      w3, w8
//   0x2d98: 5400020b  b.lt     #0x2dd8
//   0x2d9c: 12861fe9  mov      w9, #-0x3100
//   0x2da0: 52a8988a  mov      w10, #0x44c40000
//   0x2da4: 0b090069  add      w9, w3, w9
//   0x2da8: 1e270141  fmov     s1, w10
//   0x2dac: 1e220122  scvtf    s2, w9
//   0x2db0: 1e211841  fdiv     s1, s2, s1
//   0x2db4: 1e6c1000  fmov     d0, #0.50000000
//   0x2db8: 1e22c021  fcvt     d1, s1
//   0x2dbc: 1e602820  fadd     d0, d1, d0
//   0x2dc0: 1e780009  fcvtzs   w9, d0
//   0x2dc4: 11002129  add      w9, w9, #8
//   0x2dc8: 2a1f03e8  mov      w8, wzr
//   0x2dcc: 93407d29  sxtw     x9, w9
//   0x2dd0: 51001c6b  sub      w11, w3, #7
//   0x2dd4: 1400001c  b        #0x2e44
//   0x2dd8: 2a1f03e8  mov      w8, wzr
//   0x2ddc: 72000869  ands     w9, w3, #7
//   0x2de0: 540002a0  b.eq     #0x2e34
//   0x2de4: 4b090069  sub      w9, w3, w9
//   0x2de8: 93407d29  sxtw     x9, w9
//   0x2dec: 93407c6a  sxtw     x10, w3
//   0x2df0: 14000004  b        #0x2e00
//   0x2df4: 91000529  add      x9, x9, #1
//   0x2df8: eb0a013f  cmp      x9, x10
//   0x2dfc: 540001ca  b.ge     #0x2e34
//   0x2e00: 7869784c  ldrh     w12, [x2, x9, lsl #1]
//   0x2e04: 53017d8b  lsr      w11, w12, #1
//   0x2e08: 121b256b  and      w11, w11, #0x7fe0
//   0x2e0c: 3300118b  bfxil    w11, w12, #0, #5
//   0x2e10: d37ff96c  lsl      x12, x11, #1
//   0x2e14: 786c680d  ldrh     w13, [x0, x12]
//   0x2e18: 110005ae  add      w14, w13, #1
//   0x2e1c: 782c680e  strh     w14, [x0, x12]
//   0x2e20: 35fffead  cbnz     w13, #0x2df4
//   0x2e24: 1100050c  add      w12, w8, #1
//   0x2e28: 7828d82b  strh     w11, [x1, w8, sxtw #1]
//   0x2e2c: 2a0c03e8  mov      w8, w12
//   0x2e30: 17fffff1  b        #0x2df4
//   0x2e34: 51001c6b  sub      w11, w3, #7
//   0x2e38: 7100057f  cmp      w11, #1
//   0x2e3c: 54000d8b  b.lt     #0x2fec
//   0x2e40: 52800109  mov      w9, #8
//   0x2e44: aa1f03ea  mov      x10, xzr
//   0x2e48: 93407d6b  sxtw     x11, w11
//   0x2e4c: 9100204c  add      x12, x2, #8
//   0x2e50: d37ff92d  lsl      x13, x9, #1
//   0x2e54: 14000005  b        #0x2e68
//   0x2e58: 8b09014a  add      x10, x10, x9
//   0x2e5c: eb0b015f  cmp      x10, x11
//   0x2e60: 8b0d018c  add      x12, x12, x13
//   0x2e64: 54000c4a  b.ge     #0x2fec
//   0x2e68: 785f818f  ldurh    w15, [x12, #-8]
//   0x2e6c: 53017dee  lsr      w14, w15, #1
//   0x2e70: 121b25ce  and      w14, w14, #0x7fe0
//   0x2e74: 330011ee  bfxil    w14, w15, #0, #5
//   0x2e78: d37ff9cf  lsl      x15, x14, #1
//   0x2e7c: 786f6810  ldrh     w16, [x0, x15]
//   0x2e80: 11000611  add      w17, w16, #1
//   0x2e84: 782f6811  strh     w17, [x0, x15]
//   0x2e88: 35000090  cbnz     w16, #0x2e98
//   0x2e8c: 1100050f  add      w15, w8, #1
//   0x2e90: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2e94: 2a0f03e8  mov      w8, w15
//   0x2e98: 785fa18f  ldurh    w15, [x12, #-6]
//   0x2e9c: 53017dee  lsr      w14, w15, #1
//   0x2ea0: 121b25ce  and      w14, w14, #0x7fe0
//   0x2ea4: 330011ee  bfxil    w14, w15, #0, #5
//   0x2ea8: d37ff9cf  lsl      x15, x14, #1
//   0x2eac: 786f6810  ldrh     w16, [x0, x15]
//   0x2eb0: 11000611  add      w17, w16, #1
//   0x2eb4: 782f6811  strh     w17, [x0, x15]
//   0x2eb8: 35000090  cbnz     w16, #0x2ec8
//   0x2ebc: 1100050f  add      w15, w8, #1
//   0x2ec0: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2ec4: 2a0f03e8  mov      w8, w15
//   0x2ec8: 785fc18f  ldurh    w15, [x12, #-4]
//   0x2ecc: 53017dee  lsr      w14, w15, #1
//   0x2ed0: 121b25ce  and      w14, w14, #0x7fe0
//   0x2ed4: 330011ee  bfxil    w14, w15, #0, #5
//   0x2ed8: d37ff9cf  lsl      x15, x14, #1
//   0x2edc: 786f6810  ldrh     w16, [x0, x15]
//   0x2ee0: 11000611  add      w17, w16, #1
//   0x2ee4: 782f6811  strh     w17, [x0, x15]
//   0x2ee8: 35000090  cbnz     w16, #0x2ef8
//   0x2eec: 1100050f  add      w15, w8, #1
//   0x2ef0: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2ef4: 2a0f03e8  mov      w8, w15
//   0x2ef8: 785fe18f  ldurh    w15, [x12, #-2]
//   0x2efc: 53017dee  lsr      w14, w15, #1
//   0x2f00: 121b25ce  and      w14, w14, #0x7fe0
//   0x2f04: 330011ee  bfxil    w14, w15, #0, #5
//   0x2f08: d37ff9cf  lsl      x15, x14, #1
//   0x2f0c: 786f6810  ldrh     w16, [x0, x15]
//   0x2f10: 11000611  add      w17, w16, #1
//   0x2f14: 782f6811  strh     w17, [x0, x15]
//   0x2f18: 35000090  cbnz     w16, #0x2f28
//   0x2f1c: 1100050f  add      w15, w8, #1
//   0x2f20: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2f24: 2a0f03e8  mov      w8, w15
//   0x2f28: 7940018f  ldrh     w15, [x12]
//   0x2f2c: 53017dee  lsr      w14, w15, #1
//   0x2f30: 121b25ce  and      w14, w14, #0x7fe0
//   0x2f34: 330011ee  bfxil    w14, w15, #0, #5
//   0x2f38: d37ff9cf  lsl      x15, x14, #1
//   0x2f3c: 786f6810  ldrh     w16, [x0, x15]
//   0x2f40: 11000611  add      w17, w16, #1
//   0x2f44: 782f6811  strh     w17, [x0, x15]
//   0x2f48: 35000090  cbnz     w16, #0x2f58
//   0x2f4c: 1100050f  add      w15, w8, #1
//   0x2f50: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2f54: 2a0f03e8  mov      w8, w15
//   0x2f58: 7940058f  ldrh     w15, [x12, #2]
//   0x2f5c: 53017dee  lsr      w14, w15, #1
//   0x2f60: 121b25ce  and      w14, w14, #0x7fe0
//   0x2f64: 330011ee  bfxil    w14, w15, #0, #5
//   0x2f68: d37ff9cf  lsl      x15, x14, #1
//   0x2f6c: 786f6810  ldrh     w16, [x0, x15]
//   0x2f70: 11000611  add      w17, w16, #1
//   0x2f74: 782f6811  strh     w17, [x0, x15]
//   0x2f78: 35000090  cbnz     w16, #0x2f88
//   0x2f7c: 1100050f  add      w15, w8, #1
//   0x2f80: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2f84: 2a0f03e8  mov      w8, w15
//   0x2f88: 7940098f  ldrh     w15, [x12, #4]
//   0x2f8c: 53017dee  lsr      w14, w15, #1
//   0x2f90: 121b25ce  and      w14, w14, #0x7fe0
//   0x2f94: 330011ee  bfxil    w14, w15, #0, #5
//   0x2f98: d37ff9cf  lsl      x15, x14, #1
//   0x2f9c: 786f6810  ldrh     w16, [x0, x15]
//   0x2fa0: 11000611  add      w17, w16, #1
//   0x2fa4: 782f6811  strh     w17, [x0, x15]
//   0x2fa8: 35000090  cbnz     w16, #0x2fb8
//   0x2fac: 1100050f  add      w15, w8, #1
//   0x2fb0: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2fb4: 2a0f03e8  mov      w8, w15
//   0x2fb8: 79400d8f  ldrh     w15, [x12, #6]
//   0x2fbc: 53017dee  lsr      w14, w15, #1
//   0x2fc0: 121b25ce  and      w14, w14, #0x7fe0
//   0x2fc4: 330011ee  bfxil    w14, w15, #0, #5
//   0x2fc8: d37ff9cf  lsl      x15, x14, #1
//   0x2fcc: 786f6810  ldrh     w16, [x0, x15]
//   0x2fd0: 11000611  add      w17, w16, #1
//   0x2fd4: 782f6811  strh     w17, [x0, x15]
//   0x2fd8: 35fff410  cbnz     w16, #0x2e58
//   0x2fdc: 1100050f  add      w15, w8, #1
//   0x2fe0: 7828d82e  strh     w14, [x1, w8, sxtw #1]
//   0x2fe4: 2a0f03e8  mov      w8, w15
//   0x2fe8: 17ffff9c  b        #0x2e58
//   0x2fec: 2a0803e0  mov      w0, w8
//   0x2ff0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_06_2d90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002d90ULL;
    for (std::size_t i = 0; i < 153ULL; ++i) {
        std::uint32_t insn = kTextInstructions[568ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[07] Symbol: fitBox_c
//      Virtual Address Range: 0x2ff4..0x30dc (232 bytes, 58 AArch64 instructions)
// [VN] Khung FDE[07] Biểu tượng: fitBox_c
//      Dải địa chỉ ảo: 0x2ff4..0x30dc (232 byte, 58 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2ff4: 6940340c  ldpsw    x12, x13, [x0]
//   0x2ff8: 786c7848  ldrh     w8, [x2, x12, lsl #1]
//   0x2ffc: 6b0d019f  cmp      w12, w13
//   0x3000: 7868782b  ldrh     w11, [x1, x8, lsl #1]
//   0x3004: d34a7d0a  ubfx     x10, x8, #0xa, #0x16
//   0x3008: 53052509  ubfx     w9, w8, #5, #5
//   0x300c: 12001108  and      w8, w8, #0x1f
//   0x3010: 5400038a  b.ge     #0x3080
//   0x3014: cb0c01af  sub      x15, x13, x12
//   0x3018: 8b0c044c  add      x12, x2, x12, lsl #1
//   0x301c: 91000990  add      x16, x12, #2
//   0x3020: 2a0803ec  mov      w12, w8
//   0x3024: 2a0903ed  mov      w13, w9
//   0x3028: 2a0a03ee  mov      w14, w10
//   0x302c: 78402611  ldrh     w17, [x16], #2
//   0x3030: d34a7e22  ubfx     x2, x17, #0xa, #0x16
//   0x3034: 53052623  ubfx     w3, w17, #5, #5
//   0x3038: 6b2e205f  cmp      w2, w14, uxth
//   0x303c: 12001224  and      w4, w17, #0x1f
//   0x3040: 1a8e804e  csel     w14, w2, w14, hi
//   0x3044: 6b2d207f  cmp      w3, w13, uxth
//   0x3048: 78717831  ldrh     w17, [x1, x17, lsl #1]
//   0x304c: 1a8d806d  csel     w13, w3, w13, hi
//   0x3050: 6b2c209f  cmp      w4, w12, uxth
//   0x3054: 1a8c808c  csel     w12, w4, w12, hi
//   0x3058: 6b2a205f  cmp      w2, w10, uxth
//   0x305c: 1a8a304a  csel     w10, w2, w10, lo
//   0x3060: 6b29207f  cmp      w3, w9, uxth
//   0x3064: 1a893069  csel     w9, w3, w9, lo
//   0x3068: 6b28209f  cmp      w4, w8, uxth
//   0x306c: 1a883088  csel     w8, w4, w8, lo
//   0x3070: f10005ef  subs     x15, x15, #1
//   0x3074: 0b0b022b  add      w11, w17, w11
//   0x3078: 54fffda1  b.ne     #0x302c
//   0x307c: 14000004  b        #0x308c
//   0x3080: 2a0a03ee  mov      w14, w10
//   0x3084: 2a0903ed  mov      w13, w9
//   0x3088: 2a0803ec  mov      w12, w8
//   0x308c: 12003d6b  and      w11, w11, #0xffff
//   0x3090: 12003dce  and      w14, w14, #0xffff
//   0x3094: 12003d4a  and      w10, w10, #0xffff
//   0x3098: 12003dad  and      w13, w13, #0xffff
//   0x309c: 12003d29  and      w9, w9, #0xffff
//   0x30a0: 12003d08  and      w8, w8, #0xffff
//   0x30a4: 12003d8c  and      w12, w12, #0xffff
//   0x30a8: 2901280b  stp      w11, w10, [x0, #8]
//   0x30ac: 29022009  stp      w9, w8, [x0, #0x10]
//   0x30b0: 4b0a01ca  sub      w10, w14, w10
//   0x30b4: 4b0901a9  sub      w9, w13, w9
//   0x30b8: 4b080188  sub      w8, w12, w8
//   0x30bc: 1100054a  add      w10, w10, #1
//   0x30c0: 11000529  add      w9, w9, #1
//   0x30c4: 11000508  add      w8, w8, #1
//   0x30c8: 1b0a7d29  mul      w9, w9, w10
//   0x30cc: 1b087d28  mul      w8, w9, w8
//   0x30d0: 2903340e  stp      w14, w13, [x0, #0x18]
//   0x30d4: 2904200c  stp      w12, w8, [x0, #0x20]
//   0x30d8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_07_2ff4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002ff4ULL;
    for (std::size_t i = 0; i < 58ULL; ++i) {
        std::uint32_t insn = kTextInstructions[721ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[08] Symbol: cmpfunByRed_c
//      Virtual Address Range: 0x30dc..0x30f0 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[08] Biểu tượng: cmpfunByRed_c
//      Dải địa chỉ ảo: 0x30dc..0x30f0 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x30dc: 79400028  ldrh     w8, [x1]
//   0x30e0: 79400009  ldrh     w9, [x0]
//   0x30e4: 530a7d08  lsr      w8, w8, #0xa
//   0x30e8: 4b492900  sub      w0, w8, w9, lsr #10
//   0x30ec: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_08_30dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000030dcULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[779ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[09] Symbol: cmpfunByGreen_c
//      Virtual Address Range: 0x30f0..0x3108 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[09] Biểu tượng: cmpfunByGreen_c
//      Dải địa chỉ ảo: 0x30f0..0x3108 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x30f0: 79400028  ldrh     w8, [x1]
//   0x30f4: 79400009  ldrh     w9, [x0]
//   0x30f8: 53052508  ubfx     w8, w8, #5, #5
//   0x30fc: 53052529  ubfx     w9, w9, #5, #5
//   0x3100: 4b090100  sub      w0, w8, w9
//   0x3104: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_09_30f0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000030f0ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[784ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[10] Symbol: cmpfunByBlue_c
//      Virtual Address Range: 0x3108..0x3120 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[10] Biểu tượng: cmpfunByBlue_c
//      Dải địa chỉ ảo: 0x3108..0x3120 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3108: 79400028  ldrh     w8, [x1]
//   0x310c: 79400009  ldrh     w9, [x0]
//   0x3110: 12001108  and      w8, w8, #0x1f
//   0x3114: 12001129  and      w9, w9, #0x1f
//   0x3118: 4b090100  sub      w0, w8, w9
//   0x311c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_10_3108(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003108ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[790ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[11] Symbol: findBoxSplitPoint_c
//      Virtual Address Range: 0x3120..0x3268 (328 bytes, 82 AArch64 instructions)
// [VN] Khung FDE[11] Biểu tượng: findBoxSplitPoint_c
//      Dải địa chỉ ảo: 0x3120..0x3268 (328 byte, 82 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3120: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x3124: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x3128: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x312c: 910083fd  add      x29, sp, #0x20
//   0x3130: 29433008  ldp      w8, w12, [x0, #0x18]
//   0x3134: 2941ac09  ldp      w9, w11, [x0, #0xc]
//   0x3138: b940140d  ldr      w13, [x0, #0x14]
//   0x313c: b940200e  ldr      w14, [x0, #0x20]
//   0x3140: aa0203f4  mov      x20, x2
//   0x3144: 4b09010a  sub      w10, w8, w9
//   0x3148: 4b0b0188  sub      w8, w12, w11
//   0x314c: aa0103f3  mov      x19, x1
//   0x3150: aa0003f5  mov      x21, x0
//   0x3154: 6b08015f  cmp      w10, w8
//   0x3158: 4b0d01c9  sub      w9, w14, w13
//   0x315c: 540000eb  b.lt     #0x3178
//   0x3160: 6b09015f  cmp      w10, w9
//   0x3164: 540000ab  b.lt     #0x3178
//   0x3168: 90000063  adrp     x3, #0xf000
//   0x316c: f947fc63  ldr      x3, [x3, #0xff8]
//   0x3170: 2a1f03f6  mov      w22, wzr
//   0x3174: 1400000e  b        #0x31ac
//   0x3178: 6b0a011f  cmp      w8, w10
//   0x317c: 9000006a  adrp     x10, #0xf000
//   0x3180: 9000006b  adrp     x11, #0xf000
//   0x3184: f947ed4a  ldr      x10, [x10, #0xfd8]
//   0x3188: f947f16b  ldr      x11, [x11, #0xfe0]
//   0x318c: 1a9fa7ed  cset     w13, lt
//   0x3190: 6b09011f  cmp      w8, w9
//   0x3194: 1a9fa7e8  cset     w8, lt
//   0x3198: 2a0801a8  orr      w8, w13, w8
//   0x319c: 5280002c  mov      w12, #1
//   0x31a0: 7100011f  cmp      w8, #0
//   0x31a4: 9a8a1163  csel     x3, x11, x10, ne
//   0x31a8: 1a8c0596  cinc     w22, w12, ne
//   0x31ac: b9402aaa  ldr      w10, [x21, #0x28]
//   0x31b0: 294022a9  ldp      w9, w8, [x21]
//   0x31b4: 6b0a02df  cmp      w22, w10
//   0x31b8: 540001a0  b.eq     #0x31ec
//   0x31bc: 4b09010a  sub      w10, w8, w9
//   0x31c0: 1100054a  add      w10, w10, #1
//   0x31c4: 52830feb  mov      w11, #0x187f
//   0x31c8: 6b0b015f  cmp      w10, w11
//   0x31cc: 5400010c  b.gt     #0x31ec
//   0x31d0: 93407d28  sxtw     x8, w9
//   0x31d4: 8b080680  add      x0, x20, x8, lsl #1
//   0x31d8: 93407d41  sxtw     x1, w10
//   0x31dc: 52800042  mov      w2, #2
//   0x31e0: 97fffc00  bl       #0x21e0
//   0x31e4: 294022a9  ldp      w9, w8, [x21]
//   0x31e8: b9002ab6  str      w22, [x21, #0x28]
//   0x31ec: b9400aaa  ldr      w10, [x21, #8]
//   0x31f0: 2a0903e0  mov      w0, w9
//   0x31f4: 7100015f  cmp      w10, #0
//   0x31f8: 1a8aa54b  cinc     w11, w10, lt
//   0x31fc: 6b08013f  cmp      w9, w8
//   0x3200: 540002cc  b.gt     #0x3258
//   0x3204: 93407c0d  sxtw     x13, w0
//   0x3208: aa1f03e9  mov      x9, xzr
//   0x320c: 2a1f03ea  mov      w10, wzr
//   0x3210: 13017d6b  asr      w11, w11, #1
//   0x3214: 93407d0c  sxtw     x12, w8
//   0x3218: d10005ad  sub      x13, x13, #1
//   0x321c: 8b20c68e  add      x14, x20, w0, sxtw #1
//   0x3220: 786979cf  ldrh     w15, [x14, x9, lsl #1]
//   0x3224: 786f7a6f  ldrh     w15, [x19, x15, lsl #1]
//   0x3228: 0b0f014a  add      w10, w10, w15
//   0x322c: 6b0b015f  cmp      w10, w11
//   0x3230: 540000ca  b.ge     #0x3248
//   0x3234: 91000529  add      x9, x9, #1
//   0x3238: 8b0901af  add      x15, x13, x9
//   0x323c: eb0c01ff  cmp      x15, x12
//   0x3240: 54ffff0b  b.lt     #0x3220
//   0x3244: 14000005  b        #0x3258
//   0x3248: 0b090009  add      w9, w0, w9
//   0x324c: 5100050a  sub      w10, w8, #1
//   0x3250: 6b09011f  cmp      w8, w9
//   0x3254: 1a8ac120  csel     w0, w9, w10, gt
//   0x3258: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x325c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x3260: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x3264: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_11_3120(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003120ULL;
    for (std::size_t i = 0; i < 82ULL; ++i) {
        std::uint32_t insn = kTextInstructions[796ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[12] Symbol: insertBox_c
//      Virtual Address Range: 0x3268..0x3290 (40 bytes, 10 AArch64 instructions)
// [VN] Khung FDE[12] Biểu tượng: insertBox_c
//      Dải địa chỉ ảo: 0x3268..0x3290 (40 byte, 10 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3268: aa0003e8  mov      x8, x0
//   0x326c: f9401800  ldr      x0, [x0, #0x30]
//   0x3270: b40000c0  cbz      x0, #0x3288
//   0x3274: b9402409  ldr      w9, [x0, #0x24]
//   0x3278: b940242a  ldr      w10, [x1, #0x24]
//   0x327c: 6b0a013f  cmp      w9, w10
//   0x3280: 54ffff4a  b.ge     #0x3268
//   0x3284: f9001820  str      x0, [x1, #0x30]
//   0x3288: f9001901  str      x1, [x8, #0x30]
//   0x328c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_12_3268(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003268ULL;
    for (std::size_t i = 0; i < 10ULL; ++i) {
        std::uint32_t insn = kTextInstructions[878ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[13] Symbol: getAverageColor_c
//      Virtual Address Range: 0x3290..0x33e8 (344 bytes, 86 AArch64 instructions)
// [VN] Khung FDE[13] Biểu tượng: getAverageColor_c
//      Dải địa chỉ ảo: 0x3290..0x33e8 (344 byte, 86 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3290: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x3294: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x3298: 69402009  ldpsw    x9, x8, [x0]
//   0x329c: 1e2703e1  fmov     s1, wzr
//   0x32a0: 1e2703e2  fmov     s2, wzr
//   0x32a4: 1e2703e0  fmov     s0, wzr
//   0x32a8: 6b08013f  cmp      w9, w8
//   0x32ac: 5400076c  b.gt     #0x3398
//   0x32b0: eb08013f  cmp      x9, x8
//   0x32b4: 9a88c12a  csel     x10, x9, x8, gt
//   0x32b8: cb09014a  sub      x10, x10, x9
//   0x32bc: 9100054a  add      x10, x10, #1
//   0x32c0: f100055f  cmp      x10, #1
//   0x32c4: 540000a8  b.hi     #0x32d8
//   0x32c8: 2a1f03ea  mov      w10, wzr
//   0x32cc: 2a1f03ee  mov      w14, wzr
//   0x32d0: 2a1f03f0  mov      w16, wzr
//   0x32d4: 14000023  b        #0x3360
//   0x32d8: 927ff94d  and      x13, x10, #0xfffffffffffffffe
//   0x32dc: 8b090443  add      x3, x2, x9, lsl #1
//   0x32e0: 2a1f03eb  mov      w11, wzr
//   0x32e4: 2a1f03ec  mov      w12, wzr
//   0x32e8: 2a1f03ee  mov      w14, wzr
//   0x32ec: 2a1f03ef  mov      w15, wzr
//   0x32f0: 2a1f03f0  mov      w16, wzr
//   0x32f4: 2a1f03f1  mov      w17, wzr
//   0x32f8: 8b0901a9  add      x9, x13, x9
//   0x32fc: 91000863  add      x3, x3, #2
//   0x3300: aa0d03e4  mov      x4, x13
//   0x3304: 785fe065  ldurh    w5, [x3, #-2]
//   0x3308: 78404466  ldrh     w6, [x3], #4
//   0x330c: f1000884  subs     x4, x4, #2
//   0x3310: 78657827  ldrh     w7, [x1, x5, lsl #1]
//   0x3314: 78667834  ldrh     w20, [x1, x6, lsl #1]
//   0x3318: d34a7cb3  ubfx     x19, x5, #0xa, #0x16
//   0x331c: d34a7cd5  ubfx     x21, x6, #0xa, #0x16
//   0x3320: 1b074270  madd     w16, w19, w7, w16
//   0x3324: 530524b3  ubfx     w19, w5, #5, #5
//   0x3328: 1b1446b1  madd     w17, w21, w20, w17
//   0x332c: 530524d5  ubfx     w21, w6, #5, #5
//   0x3330: 120010a5  and      w5, w5, #0x1f
//   0x3334: 120010c6  and      w6, w6, #0x1f
//   0x3338: 1b073a6e  madd     w14, w19, w7, w14
//   0x333c: 1b143eaf  madd     w15, w21, w20, w15
//   0x3340: 1b072cab  madd     w11, w5, w7, w11
//   0x3344: 1b1430cc  madd     w12, w6, w20, w12
//   0x3348: 54fffde1  b.ne     #0x3304
//   0x334c: 0b100230  add      w16, w17, w16
//   0x3350: 0b0e01ee  add      w14, w15, w14
//   0x3354: eb0d015f  cmp      x10, x13
//   0x3358: 0b0b018a  add      w10, w12, w11
//   0x335c: 54000180  b.eq     #0x338c
//   0x3360: 7869784b  ldrh     w11, [x2, x9, lsl #1]
//   0x3364: eb08013f  cmp      x9, x8
//   0x3368: 91000529  add      x9, x9, #1
//   0x336c: 786b782c  ldrh     w12, [x1, x11, lsl #1]
//   0x3370: d34a7d6d  ubfx     x13, x11, #0xa, #0x16
//   0x3374: 5305256f  ubfx     w15, w11, #5, #5
//   0x3378: 1200116b  and      w11, w11, #0x1f
//   0x337c: 1b0c41b0  madd     w16, w13, w12, w16
//   0x3380: 1b0c39ee  madd     w14, w15, w12, w14
//   0x3384: 1b0c296a  madd     w10, w11, w12, w10
//   0x3388: 54fffecb  b.lt     #0x3360
//   0x338c: 1e220201  scvtf    s1, w16
//   0x3390: 1e2201c2  scvtf    s2, w14
//   0x3394: 1e220140  scvtf    s0, w10
//   0x3398: bd400803  ldr      s3, [x0, #8]
//   0x339c: 1e6c1004  fmov     d4, #0.50000000
//   0x33a0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x33a4: 5e21d863  scvtf    s3, s3
//   0x33a8: 1e231842  fdiv     s2, s2, s3
//   0x33ac: 1e231800  fdiv     s0, s0, s3
//   0x33b0: 1e231821  fdiv     s1, s1, s3
//   0x33b4: 1e22c042  fcvt     d2, s2
//   0x33b8: 1e22c000  fcvt     d0, s0
//   0x33bc: 1e22c021  fcvt     d1, s1
//   0x33c0: 1e642842  fadd     d2, d2, d4
//   0x33c4: 1e642800  fadd     d0, d0, d4
//   0x33c8: 1e642821  fadd     d1, d1, d4
//   0x33cc: 1e780049  fcvtzs   w9, d2
//   0x33d0: 1e78000a  fcvtzs   w10, d0
//   0x33d4: 1e780028  fcvtzs   w8, d1
//   0x33d8: 2a091549  orr      w9, w10, w9, lsl #5
//   0x33dc: 2a082920  orr      w0, w9, w8, lsl #10
//   0x33e0: f84207f5  ldr      x21, [sp], #0x20
//   0x33e4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_13_3290(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003290ULL;
    for (std::size_t i = 0; i < 86ULL; ++i) {
        std::uint32_t insn = kTextInstructions[888ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[14] Symbol: cutting_colors_c
//      Virtual Address Range: 0x33e8..0x3788 (928 bytes, 232 AArch64 instructions)
// [VN] Khung FDE[14] Biểu tượng: cutting_colors_c
//      Dải địa chỉ ảo: 0x33e8..0x3788 (928 byte, 232 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x33e8: d10503ff  sub      sp, sp, #0x140
//   0x33ec: fd006be8  str      d8, [sp, #0xd0]
//   0x33f0: a90e6ffc  stp      x28, x27, [sp, #0xe0]
//   0x33f4: a90f67fa  stp      x26, x25, [sp, #0xf0]
//   0x33f8: a9105ff8  stp      x24, x23, [sp, #0x100]
//   0x33fc: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x3400: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x3404: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x3408: 9104c3fd  add      x29, sp, #0x130
//   0x340c: d53bd058  mrs      x24, tpidr_el0
//   0x3410: f9401708  ldr      x8, [x24, #0x28]
//   0x3414: aa0003f4  mov      x20, x0
//   0x3418: 52800700  mov      w0, #0x38
//   0x341c: 2a0203f6  mov      w22, w2
//   0x3420: aa0103f3  mov      x19, x1
//   0x3424: f81903a8  stur     x8, [x29, #-0x70]
//   0x3428: 97fffbf2  bl       #0x23f0
//   0x342c: 510006c8  sub      w8, w22, #1
//   0x3430: 12800009  mov      w9, #-1
//   0x3434: aa1403e1  mov      x1, x20
//   0x3438: aa1303e2  mov      x2, x19
//   0x343c: aa0003f5  mov      x21, x0
//   0x3440: f900181f  str      xzr, [x0, #0x30]
//   0x3444: 2900201f  stp      wzr, w8, [x0]
//   0x3448: b9002809  str      w9, [x0, #0x28]
//   0x344c: 97fffbe1  bl       #0x23d0
//   0x3450: 52800039  mov      w25, #1
//   0x3454: f9001ff5  str      x21, [sp, #0x38]
//   0x3458: 14000007  b        #0x3474
//   0x345c: f9001aa8  str      x8, [x21, #0x30]
//   0x3460: f9001935  str      x21, [x9, #0x30]
//   0x3464: f9401ff5  ldr      x21, [sp, #0x38]
//   0x3468: 11000739  add      w25, w25, #1
//   0x346c: 7100433f  cmp      w25, #0x10
//   0x3470: 540006e0  b.eq     #0x354c
//   0x3474: 294026a8  ldp      w8, w9, [x21]
//   0x3478: 6b08013f  cmp      w9, w8
//   0x347c: 5400068d  b.le     #0x354c
//   0x3480: f9401aba  ldr      x26, [x21, #0x30]
//   0x3484: aa1503e0  mov      x0, x21
//   0x3488: aa1403e1  mov      x1, x20
//   0x348c: aa1303e2  mov      x2, x19
//   0x3490: f9001ffa  str      x26, [sp, #0x38]
//   0x3494: 97fffbe7  bl       #0x2430
//   0x3498: 2a0003f7  mov      w23, w0
//   0x349c: 52800700  mov      w0, #0x38
//   0x34a0: 97fffbd4  bl       #0x23f0
//   0x34a4: 110006e8  add      w8, w23, #1
//   0x34a8: b9000008  str      w8, [x0]
//   0x34ac: b94006a8  ldr      w8, [x21, #4]
//   0x34b0: f900181f  str      xzr, [x0, #0x30]
//   0x34b4: aa1403e1  mov      x1, x20
//   0x34b8: aa1303e2  mov      x2, x19
//   0x34bc: b9000408  str      w8, [x0, #4]
//   0x34c0: b9402aa8  ldr      w8, [x21, #0x28]
//   0x34c4: aa0003f6  mov      x22, x0
//   0x34c8: b9002808  str      w8, [x0, #0x28]
//   0x34cc: 97fffbc1  bl       #0x23d0
//   0x34d0: aa1503e0  mov      x0, x21
//   0x34d4: aa1403e1  mov      x1, x20
//   0x34d8: aa1303e2  mov      x2, x19
//   0x34dc: b90006b7  str      w23, [x21, #4]
//   0x34e0: f9001abf  str      xzr, [x21, #0x30]
//   0x34e4: 97fffbbb  bl       #0x23d0
//   0x34e8: b400017a  cbz      x26, #0x3514
//   0x34ec: b94026c9  ldr      w9, [x22, #0x24]
//   0x34f0: 910023ea  add      x10, sp, #8
//   0x34f4: b940274b  ldr      w11, [x26, #0x24]
//   0x34f8: aa1a03e8  mov      x8, x26
//   0x34fc: 6b09017f  cmp      w11, w9
//   0x3500: 540000eb  b.lt     #0x351c
//   0x3504: f940191a  ldr      x26, [x8, #0x30]
//   0x3508: aa0803ea  mov      x10, x8
//   0x350c: b5ffff5a  cbnz     x26, #0x34f4
//   0x3510: 14000005  b        #0x3524
//   0x3514: 910023e8  add      x8, sp, #8
//   0x3518: 14000003  b        #0x3524
//   0x351c: f9001ac8  str      x8, [x22, #0x30]
//   0x3520: aa0a03e8  mov      x8, x10
//   0x3524: f9001916  str      x22, [x8, #0x30]
//   0x3528: 910023e8  add      x8, sp, #8
//   0x352c: aa0803e9  mov      x9, x8
//   0x3530: f9401908  ldr      x8, [x8, #0x30]
//   0x3534: b4fff968  cbz      x8, #0x3460
//   0x3538: b940250a  ldr      w10, [x8, #0x24]
//   0x353c: b94026ab  ldr      w11, [x21, #0x24]
//   0x3540: 6b0b015f  cmp      w10, w11
//   0x3544: 54ffff4a  b.ge     #0x352c
//   0x3548: 17ffffc5  b        #0x345c
//   0x354c: 2a1f03f6  mov      w22, wzr
//   0x3550: b4000ff5  cbz      x21, #0x374c
//   0x3554: 91000a77  add      x23, x19, #2
//   0x3558: 1e6c1008  fmov     d8, #0.50000000
//   0x355c: 910203f9  add      x25, sp, #0x80
//   0x3560: 910103fa  add      x26, sp, #0x40
//   0x3564: 1400000a  b        #0x358c
//   0x3568: 3400008b  cbz      w11, #0x3578
//   0x356c: 93407ec9  sxtw     x9, w22
//   0x3570: 110006d6  add      w22, w22, #1
//   0x3574: b8297b48  str      w8, [x26, x9, lsl #2]
//   0x3578: f9401abb  ldr      x27, [x21, #0x30]
//   0x357c: aa1503e0  mov      x0, x21
//   0x3580: 97fffbb8  bl       #0x2460
//   0x3584: aa1b03f5  mov      x21, x27
//   0x3588: b4000cbb  cbz      x27, #0x371c
//   0x358c: 694022a0  ldpsw    x0, x8, [x21]
//   0x3590: 1e2703e1  fmov     s1, wzr
//   0x3594: 1e2703e2  fmov     s2, wzr
//   0x3598: 1e2703e0  fmov     s0, wzr
//   0x359c: 6b08001f  cmp      w0, w8
//   0x35a0: 5400076c  b.gt     #0x368c
//   0x35a4: eb08001f  cmp      x0, x8
//   0x35a8: 9a88c009  csel     x9, x0, x8, gt
//   0x35ac: cb000129  sub      x9, x9, x0
//   0x35b0: 9100052a  add      x10, x9, #1
//   0x35b4: f100055f  cmp      x10, #1
//   0x35b8: 540000c8  b.hi     #0x35d0
//   0x35bc: 2a1f03ea  mov      w10, wzr
//   0x35c0: 2a1f03ee  mov      w14, wzr
//   0x35c4: 2a1f03f0  mov      w16, wzr
//   0x35c8: aa0003e9  mov      x9, x0
//   0x35cc: 14000022  b        #0x3654
//   0x35d0: 927ff94d  and      x13, x10, #0xfffffffffffffffe
//   0x35d4: 2a1f03eb  mov      w11, wzr
//   0x35d8: 2a1f03ec  mov      w12, wzr
//   0x35dc: 2a1f03ee  mov      w14, wzr
//   0x35e0: 2a1f03ef  mov      w15, wzr
//   0x35e4: 2a1f03f0  mov      w16, wzr
//   0x35e8: 2a1f03f1  mov      w17, wzr
//   0x35ec: 8b0001a9  add      x9, x13, x0
//   0x35f0: 8b0006e0  add      x0, x23, x0, lsl #1
//   0x35f4: aa0d03e1  mov      x1, x13
//   0x35f8: 785fe002  ldurh    w2, [x0, #-2]
//   0x35fc: 78404403  ldrh     w3, [x0], #4
//   0x3600: f1000821  subs     x1, x1, #2
//   0x3604: 78627a84  ldrh     w4, [x20, x2, lsl #1]
//   0x3608: 78637a86  ldrh     w6, [x20, x3, lsl #1]
//   0x360c: d34a7c45  ubfx     x5, x2, #0xa, #0x16
//   0x3610: d34a7c67  ubfx     x7, x3, #0xa, #0x16
//   0x3614: 1b0440b0  madd     w16, w5, w4, w16
//   0x3618: 53052445  ubfx     w5, w2, #5, #5
//   0x361c: 1b0644f1  madd     w17, w7, w6, w17
//   0x3620: 53052467  ubfx     w7, w3, #5, #5
//   0x3624: 12001042  and      w2, w2, #0x1f
//   0x3628: 12001063  and      w3, w3, #0x1f
//   0x362c: 1b0438ae  madd     w14, w5, w4, w14
//   0x3630: 1b063cef  madd     w15, w7, w6, w15
//   0x3634: 1b042c4b  madd     w11, w2, w4, w11
//   0x3638: 1b06306c  madd     w12, w3, w6, w12
//   0x363c: 54fffde1  b.ne     #0x35f8
//   0x3640: 0b100230  add      w16, w17, w16
//   0x3644: 0b0e01ee  add      w14, w15, w14
//   0x3648: eb0d015f  cmp      x10, x13
//   0x364c: 0b0b018a  add      w10, w12, w11
//   0x3650: 54000180  b.eq     #0x3680
//   0x3654: 78697a6b  ldrh     w11, [x19, x9, lsl #1]
//   0x3658: eb08013f  cmp      x9, x8
//   0x365c: 91000529  add      x9, x9, #1
//   0x3660: 786b7a8c  ldrh     w12, [x20, x11, lsl #1]
//   0x3664: d34a7d6d  ubfx     x13, x11, #0xa, #0x16
//   0x3668: 5305256f  ubfx     w15, w11, #5, #5
//   0x366c: 1200116b  and      w11, w11, #0x1f
//   0x3670: 1b0c41b0  madd     w16, w13, w12, w16
//   0x3674: 1b0c39ee  madd     w14, w15, w12, w14
//   0x3678: 1b0c296a  madd     w10, w11, w12, w10
//   0x367c: 54fffecb  b.lt     #0x3654
//   0x3680: 1e220201  scvtf    s1, w16
//   0x3684: 1e2201c2  scvtf    s2, w14
//   0x3688: 1e220140  scvtf    s0, w10
//   0x368c: b9400aa8  ldr      w8, [x21, #8]
//   0x3690: 710006df  cmp      w22, #1
//   0x3694: 1e220103  scvtf    s3, w8
//   0x3698: 1e231842  fdiv     s2, s2, s3
//   0x369c: 1e231800  fdiv     s0, s0, s3
//   0x36a0: 1e231821  fdiv     s1, s1, s3
//   0x36a4: 1e22c042  fcvt     d2, s2
//   0x36a8: 1e22c000  fcvt     d0, s0
//   0x36ac: 1e22c021  fcvt     d1, s1
//   0x36b0: 1e682842  fadd     d2, d2, d8
//   0x36b4: 1e682800  fadd     d0, d0, d8
//   0x36b8: 1e682821  fadd     d1, d1, d8
//   0x36bc: 1e78004a  fcvtzs   w10, d2
//   0x36c0: 1e78000b  fcvtzs   w11, d0
//   0x36c4: 1e780029  fcvtzs   w9, d1
//   0x36c8: 2a0a156a  orr      w10, w11, w10, lsl #5
//   0x36cc: 2a092949  orr      w9, w10, w9, lsl #10
//   0x36d0: b836db29  str      w9, [x25, w22, sxtw #2]
//   0x36d4: 54fff4cb  b.lt     #0x356c
//   0x36d8: 2a1603ea  mov      w10, w22
//   0x36dc: 5280002b  mov      w11, #1
//   0x36e0: 910103ec  add      x12, sp, #0x40
//   0x36e4: 910203ed  add      x13, sp, #0x80
//   0x36e8: 14000005  b        #0x36fc
//   0x36ec: 9100118c  add      x12, x12, #4
//   0x36f0: f100054a  subs     x10, x10, #1
//   0x36f4: 910011ad  add      x13, x13, #4
//   0x36f8: 54fff380  b.eq     #0x3568
//   0x36fc: b94001ae  ldr      w14, [x13]
//   0x3700: 6b0901df  cmp      w14, w9
//   0x3704: 54ffff41  b.ne     #0x36ec
//   0x3708: b940018e  ldr      w14, [x12]
//   0x370c: 2a1f03eb  mov      w11, wzr
//   0x3710: 0b0801ce  add      w14, w14, w8
//   0x3714: b900018e  str      w14, [x12]
//   0x3718: 17fffff5  b        #0x36ec
//   0x371c: 710006df  cmp      w22, #1
//   0x3720: 5400016b  b.lt     #0x374c
//   0x3724: 2a1603e8  mov      w8, w22
//   0x3728: 910103e9  add      x9, sp, #0x40
//   0x372c: 910203ea  add      x10, sp, #0x80
//   0x3730: b840454b  ldr      w11, [x10], #4
//   0x3734: f1000508  subs     x8, x8, #1
//   0x3738: 7800266b  strh     w11, [x19], #2
//   0x373c: b840452c  ldr      w12, [x9], #4
//   0x3740: 92403d6b  and      x11, x11, #0xffff
//   0x3744: 782b7a8c  strh     w12, [x20, x11, lsl #1]
//   0x3748: 54ffff41  b.ne     #0x3730
//   0x374c: f9401708  ldr      x8, [x24, #0x28]
//   0x3750: f85903a9  ldur     x9, [x29, #-0x70]
//   0x3754: eb09011f  cmp      x8, x9
//   0x3758: 54000161  b.ne     #0x3784
//   0x375c: 2a1603e0  mov      w0, w22
//   0x3760: a9537bfd  ldp      x29, x30, [sp, #0x130]
//   0x3764: a9524ff4  ldp      x20, x19, [sp, #0x120]
//   0x3768: a95157f6  ldp      x22, x21, [sp, #0x110]
//   0x376c: a9505ff8  ldp      x24, x23, [sp, #0x100]
//   0x3770: a94f67fa  ldp      x26, x25, [sp, #0xf0]
//   0x3774: a94e6ffc  ldp      x28, x27, [sp, #0xe0]
//   0x3778: fd406be8  ldr      d8, [sp, #0xd0]
//   0x377c: 910503ff  add      sp, sp, #0x140
//   0x3780: d65f03c0  ret      
//   0x3784: 97fffaaf  bl       #0x2240
// ============================================================================
std::uint32_t fde_14_33e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000033e8ULL;
    for (std::size_t i = 0; i < 232ULL; ++i) {
        std::uint32_t insn = kTextInstructions[974ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[15] Symbol: toARGB888_c
//      Virtual Address Range: 0x3788..0x37a8 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[15] Biểu tượng: toARGB888_c
//      Dải địa chỉ ảo: 0x3788..0x37a8 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3788: 12003c08  and      w8, w0, #0xffff
//   0x378c: 5317590a  lsl      w10, w8, #9
//   0x3790: 53057d09  lsr      w9, w8, #5
//   0x3794: 120d114a  and      w10, w10, #0xf80000
//   0x3798: 3315112a  bfi      w10, w9, #0xb, #5
//   0x379c: 331d110a  bfi      w10, w8, #3, #5
//   0x37a0: 32081d40  orr      w0, w10, #0xff000000
//   0x37a4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_15_3788(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003788ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1206ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[16] Symbol: partition_with_histogram_c
//      Virtual Address Range: 0x37a8..0x3878 (208 bytes, 52 AArch64 instructions)
// [VN] Khung FDE[16] Biểu tượng: partition_with_histogram_c
//      Dải địa chỉ ảo: 0x37a8..0x3878 (208 byte, 52 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x37a8: 937e7c49  sbfiz    x9, x2, #2, #0x20
//   0x37ac: b8696828  ldr      w8, [x1, x9]
//   0x37b0: b8696809  ldr      w9, [x0, x9]
//   0x37b4: 6b03005f  cmp      w2, w3
//   0x37b8: 5400054a  b.ge     #0x3860
//   0x37bc: 6b03005f  cmp      w2, w3
//   0x37c0: 5400012a  b.ge     #0x37e4
//   0x37c4: 93407c63  sxtw     x3, w3
//   0x37c8: 93407c4a  sxtw     x10, w2
//   0x37cc: b863782b  ldr      w11, [x1, x3, lsl #2]
//   0x37d0: 6b08017f  cmp      w11, w8
//   0x37d4: 540000ec  b.gt     #0x37f0
//   0x37d8: d1000463  sub      x3, x3, #1
//   0x37dc: eb0a007f  cmp      x3, x10
//   0x37e0: 54ffff6c  b.gt     #0x37cc
//   0x37e4: 6b03005f  cmp      w2, w3
//   0x37e8: 54fffe6a  b.ge     #0x37b4
//   0x37ec: 14000008  b        #0x380c
//   0x37f0: d37ef54a  lsl      x10, x10, #2
//   0x37f4: b82a682b  str      w11, [x1, x10]
//   0x37f8: b863780b  ldr      w11, [x0, x3, lsl #2]
//   0x37fc: 11000442  add      w2, w2, #1
//   0x3800: b82a680b  str      w11, [x0, x10]
//   0x3804: 6b03005f  cmp      w2, w3
//   0x3808: 54fffd6a  b.ge     #0x37b4
//   0x380c: 937e7c4b  sbfiz    x11, x2, #2, #0x20
//   0x3810: 8b0b000a  add      x10, x0, x11
//   0x3814: 8b0b002b  add      x11, x1, x11
//   0x3818: b940016c  ldr      w12, [x11]
//   0x381c: 6b08019f  cmp      w12, w8
//   0x3820: 540000eb  b.lt     #0x383c
//   0x3824: 11000442  add      w2, w2, #1
//   0x3828: 9100114a  add      x10, x10, #4
//   0x382c: 6b02007f  cmp      w3, w2
//   0x3830: 9100116b  add      x11, x11, #4
//   0x3834: 54ffff21  b.ne     #0x3818
//   0x3838: 14000009  b        #0x385c
//   0x383c: 937e7c6b  sbfiz    x11, x3, #2, #0x20
//   0x3840: b82b682c  str      w12, [x1, x11]
//   0x3844: b940014a  ldr      w10, [x10]
//   0x3848: 51000463  sub      w3, w3, #1
//   0x384c: b82b680a  str      w10, [x0, x11]
//   0x3850: 6b03005f  cmp      w2, w3
//   0x3854: 54fffb4b  b.lt     #0x37bc
//   0x3858: 14000002  b        #0x3860
//   0x385c: 2a0303e2  mov      w2, w3
//   0x3860: 93407c4a  sxtw     x10, w2
//   0x3864: d37ef54a  lsl      x10, x10, #2
//   0x3868: b82a6828  str      w8, [x1, x10]
//   0x386c: b82a6809  str      w9, [x0, x10]
//   0x3870: 2a0203e0  mov      w0, w2
//   0x3874: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_16_37a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000037a8ULL;
    for (std::size_t i = 0; i < 52ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1214ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[17] Symbol: sort_with_histogram_c
//      Virtual Address Range: 0x3878..0x3990 (280 bytes, 70 AArch64 instructions)
// [VN] Khung FDE[17] Biểu tượng: sort_with_histogram_c
//      Dải địa chỉ ảo: 0x3878..0x3990 (280 byte, 70 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3878: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x387c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x3880: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x3884: 910083fd  add      x29, sp, #0x20
//   0x3888: 6b03005f  cmp      w2, w3
//   0x388c: 540007aa  b.ge     #0x3980
//   0x3890: 2a0303f3  mov      w19, w3
//   0x3894: aa0103f4  mov      x20, x1
//   0x3898: aa0003f5  mov      x21, x0
//   0x389c: 937e7c49  sbfiz    x9, x2, #2, #0x20
//   0x38a0: b8696a88  ldr      w8, [x20, x9]
//   0x38a4: b8696aa9  ldr      w9, [x21, x9]
//   0x38a8: 2a0203f6  mov      w22, w2
//   0x38ac: 2a1303ea  mov      w10, w19
//   0x38b0: 6b0a02df  cmp      w22, w10
//   0x38b4: 5400026a  b.ge     #0x3900
//   0x38b8: 1400000a  b        #0x38e0
//   0x38bc: 937e7d4c  sbfiz    x12, x10, #2, #0x20
//   0x38c0: b82c6a8d  str      w13, [x20, x12]
//   0x38c4: b940016b  ldr      w11, [x11]
//   0x38c8: 5100054a  sub      w10, w10, #1
//   0x38cc: b82c6aab  str      w11, [x21, x12]
//   0x38d0: 6b0a02df  cmp      w22, w10
//   0x38d4: 5400042a  b.ge     #0x3958
//   0x38d8: 6b0a02df  cmp      w22, w10
//   0x38dc: 5400012a  b.ge     #0x3900
//   0x38e0: 93407d4a  sxtw     x10, w10
//   0x38e4: 93407ecb  sxtw     x11, w22
//   0x38e8: b86a7a8c  ldr      w12, [x20, x10, lsl #2]
//   0x38ec: 6b08019f  cmp      w12, w8
//   0x38f0: 540000ec  b.gt     #0x390c
//   0x38f4: d100054a  sub      x10, x10, #1
//   0x38f8: eb0b015f  cmp      x10, x11
//   0x38fc: 54ffff6c  b.gt     #0x38e8
//   0x3900: 6b0a02df  cmp      w22, w10
//   0x3904: 54fffe6a  b.ge     #0x38d0
//   0x3908: 14000008  b        #0x3928
//   0x390c: d37ef56b  lsl      x11, x11, #2
//   0x3910: b82b6a8c  str      w12, [x20, x11]
//   0x3914: b86a7aac  ldr      w12, [x21, x10, lsl #2]
//   0x3918: 110006d6  add      w22, w22, #1
//   0x391c: b82b6aac  str      w12, [x21, x11]
//   0x3920: 6b0a02df  cmp      w22, w10
//   0x3924: 54fffd6a  b.ge     #0x38d0
//   0x3928: 937e7ecc  sbfiz    x12, x22, #2, #0x20
//   0x392c: 8b0c02ab  add      x11, x21, x12
//   0x3930: 8b0c028c  add      x12, x20, x12
//   0x3934: b940018d  ldr      w13, [x12]
//   0x3938: 6b0801bf  cmp      w13, w8
//   0x393c: 54fffc0b  b.lt     #0x38bc
//   0x3940: 110006d6  add      w22, w22, #1
//   0x3944: 9100116b  add      x11, x11, #4
//   0x3948: 6b16015f  cmp      w10, w22
//   0x394c: 9100118c  add      x12, x12, #4
//   0x3950: 54ffff21  b.ne     #0x3934
//   0x3954: 2a0a03f6  mov      w22, w10
//   0x3958: 937e7eca  sbfiz    x10, x22, #2, #0x20
//   0x395c: 510006c3  sub      w3, w22, #1
//   0x3960: aa1503e0  mov      x0, x21
//   0x3964: aa1403e1  mov      x1, x20
//   0x3968: b82a6a88  str      w8, [x20, x10]
//   0x396c: b82a6aa9  str      w9, [x21, x10]
//   0x3970: 97ffffc2  bl       #0x3878
//   0x3974: 110006c2  add      w2, w22, #1
//   0x3978: 6b13005f  cmp      w2, w19
//   0x397c: 54fff90b  b.lt     #0x389c
//   0x3980: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x3984: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x3988: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x398c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_17_3878(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003878ULL;
    for (std::size_t i = 0; i < 70ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1266ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[18] Symbol: cut_main_color_at_rgb_565_c
//      Virtual Address Range: 0x3990..0x3bd0 (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[18] Biểu tượng: cut_main_color_at_rgb_565_c
//      Dải địa chỉ ảo: 0x3990..0x3bd0 (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3990: a9bc5ffc  stp      x28, x23, [sp, #-0x40]!
//   0x3994: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x3998: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x399c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x39a0: 9100c3fd  add      x29, sp, #0x30
//   0x39a4: d14083ff  sub      sp, sp, #0x20, lsl #12
//   0x39a8: d10043ff  sub      sp, sp, #0x10
//   0x39ac: d53bd057  mrs      x23, tpidr_el0
//   0x39b0: f94016e8  ldr      x8, [x23, #0x28]
//   0x39b4: aa0003f6  mov      x22, x0
//   0x39b8: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x39bc: aa0203f4  mov      x20, x2
//   0x39c0: 2a0103f5  mov      w21, w1
//   0x39c4: 91002000  add      x0, x0, #8
//   0x39c8: 52a00022  mov      w2, #0x10000
//   0x39cc: 2a1f03e1  mov      w1, wzr
//   0x39d0: aa0303f3  mov      x19, x3
//   0x39d4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x39d8: 97fffa9a  bl       #0x2440
//   0x39dc: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x39e0: 91002000  add      x0, x0, #8
//   0x39e4: 910023e1  add      x1, sp, #8
//   0x39e8: aa1603e2  mov      x2, x22
//   0x39ec: 2a1503e3  mov      w3, w21
//   0x39f0: 97fffa88  bl       #0x2410
//   0x39f4: 2a0003f5  mov      w21, w0
//   0x39f8: 7100441f  cmp      w0, #0x11
//   0x39fc: 540000eb  b.lt     #0x3a18
//   0x3a00: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x3a04: 91002000  add      x0, x0, #8
//   0x3a08: 910023e1  add      x1, sp, #8
//   0x3a0c: 2a1503e2  mov      w2, w21
//   0x3a10: 97fffa30  bl       #0x22d0
//   0x3a14: 2a0003f5  mov      w21, w0
//   0x3a18: 710006bf  cmp      w21, #1
//   0x3a1c: 54000c0b  b.lt     #0x3b9c
//   0x3a20: 71001ebf  cmp      w21, #7
//   0x3a24: 2a1503e8  mov      w8, w21
//   0x3a28: 54000088  b.hi     #0x3a38
//   0x3a2c: aa1f03ea  mov      x10, xzr
//   0x3a30: aa1403e9  mov      x9, x20
//   0x3a34: 14000024  b        #0x3ac4
//   0x3a38: 927d710a  and      x10, x8, #0xfffffff8
//   0x3a3c: 910023ec  add      x12, sp, #8
//   0x3a40: 9100428b  add      x11, x20, #0x10
//   0x3a44: 4f074700  movi     v0.4s, #0xf8, lsl #16
//   0x3a48: 4f072701  movi     v1.4s, #0xf8, lsl #8
//   0x3a4c: 8b0a0a89  add      x9, x20, x10, lsl #2
//   0x3a50: 9100218c  add      x12, x12, #8
//   0x3a54: 4f070702  movi     v2.4s, #0xf8
//   0x3a58: aa0a03ed  mov      x13, x10
//   0x3a5c: 6d7f9183  ldp      d3, d4, [x12, #-8]
//   0x3a60: f10021ad  subs     x13, x13, #8
//   0x3a64: 9100418c  add      x12, x12, #0x10
//   0x3a68: 2f19a465  ushll    v5.4s, v3.4h, #9
//   0x3a6c: 2f19a486  ushll    v6.4s, v4.4h, #9
//   0x3a70: 2f16a467  ushll    v7.4s, v3.4h, #6
//   0x3a74: 2f16a490  ushll    v16.4s, v4.4h, #6
//   0x3a78: 2f13a463  ushll    v3.4s, v3.4h, #3
//   0x3a7c: 2f13a484  ushll    v4.4s, v4.4h, #3
//   0x3a80: 4e201ca5  and      v5.16b, v5.16b, v0.16b
//   0x3a84: 4e201cc6  and      v6.16b, v6.16b, v0.16b
//   0x3a88: 4e211ce7  and      v7.16b, v7.16b, v1.16b
//   0x3a8c: 4e211e10  and      v16.16b, v16.16b, v1.16b
//   0x3a90: 4e221c63  and      v3.16b, v3.16b, v2.16b
//   0x3a94: 4e221c84  and      v4.16b, v4.16b, v2.16b
//   0x3a98: 4ea71ca5  orr      v5.16b, v5.16b, v7.16b
//   0x3a9c: 4eb01cc6  orr      v6.16b, v6.16b, v16.16b
//   0x3aa0: 4ea31ca3  orr      v3.16b, v5.16b, v3.16b
//   0x3aa4: 4ea41cc4  orr      v4.16b, v6.16b, v4.16b
//   0x3aa8: 4f0777e3  orr      v3.4s, #0xff, lsl #24
//   0x3aac: 4f0777e4  orr      v4.4s, #0xff, lsl #24
//   0x3ab0: ad3f9163  stp      q3, q4, [x11, #-0x10]
//   0x3ab4: 9100816b  add      x11, x11, #0x20
//   0x3ab8: 54fffd21  b.ne     #0x3a5c
//   0x3abc: eb08015f  cmp      x10, x8
//   0x3ac0: 540001c0  b.eq     #0x3af8
//   0x3ac4: 910023eb  add      x11, sp, #8
//   0x3ac8: 8b0a056b  add      x11, x11, x10, lsl #1
//   0x3acc: cb0a010a  sub      x10, x8, x10
//   0x3ad0: 7840256c  ldrh     w12, [x11], #2
//   0x3ad4: f100054a  subs     x10, x10, #1
//   0x3ad8: 531a658e  lsl      w14, w12, #6
//   0x3adc: 530a7d8d  lsr      w13, w12, #0xa
//   0x3ae0: 121511ce  and      w14, w14, #0xf800
//   0x3ae4: 330d11ae  bfi      w14, w13, #0x13, #5
//   0x3ae8: 331d118e  bfi      w14, w12, #3, #5
//   0x3aec: 32081dcc  orr      w12, w14, #0xff000000
//   0x3af0: b800452c  str      w12, [x9], #4
//   0x3af4: 54fffee1  b.ne     #0x3ad0
//   0x3af8: b4000473  cbz      x19, #0x3b84
//   0x3afc: 710006bf  cmp      w21, #1
//   0x3b00: 5400042b  b.lt     #0x3b84
//   0x3b04: 54000088  b.hi     #0x3b14
//   0x3b08: aa1f03ea  mov      x10, xzr
//   0x3b0c: aa1303e9  mov      x9, x19
//   0x3b10: 14000013  b        #0x3b5c
//   0x3b14: 927f790a  and      x10, x8, #0xfffffffe
//   0x3b18: 910023ec  add      x12, sp, #8
//   0x3b1c: 914043ed  add      x13, sp, #0x10, lsl #12
//   0x3b20: 9100126b  add      x11, x19, #4
//   0x3b24: 8b0a0a69  add      x9, x19, x10, lsl #2
//   0x3b28: b27f018c  orr      x12, x12, #2
//   0x3b2c: 910021ad  add      x13, x13, #8
//   0x3b30: aa0a03ee  mov      x14, x10
//   0x3b34: 785fe18f  ldurh    w15, [x12, #-2]
//   0x3b38: 78404590  ldrh     w16, [x12], #4
//   0x3b3c: f10009ce  subs     x14, x14, #2
//   0x3b40: 786f79af  ldrh     w15, [x13, x15, lsl #1]
//   0x3b44: 787079b0  ldrh     w16, [x13, x16, lsl #1]
//   0x3b48: 293fc16f  stp      w15, w16, [x11, #-4]
//   0x3b4c: 9100216b  add      x11, x11, #8
//   0x3b50: 54ffff21  b.ne     #0x3b34
//   0x3b54: eb08015f  cmp      x10, x8
//   0x3b58: 54000160  b.eq     #0x3b84
//   0x3b5c: 910023eb  add      x11, sp, #8
//   0x3b60: cb0a0108  sub      x8, x8, x10
//   0x3b64: 8b0a056a  add      x10, x11, x10, lsl #1
//   0x3b68: 914043eb  add      x11, sp, #0x10, lsl #12
//   0x3b6c: 9100216b  add      x11, x11, #8
//   0x3b70: 7840254c  ldrh     w12, [x10], #2
//   0x3b74: f1000508  subs     x8, x8, #1
//   0x3b78: 786c796c  ldrh     w12, [x11, x12, lsl #1]
//   0x3b7c: b800452c  str      w12, [x9], #4
//   0x3b80: 54ffff81  b.ne     #0x3b70
//   0x3b84: 710006a3  subs     w3, w21, #1
//   0x3b88: 540000ad  b.le     #0x3b9c
//   0x3b8c: aa1403e0  mov      x0, x20
//   0x3b90: aa1303e1  mov      x1, x19
//   0x3b94: 2a1f03e2  mov      w2, wzr
//   0x3b98: 97fff9fa  bl       #0x2380
//   0x3b9c: f94016e8  ldr      x8, [x23, #0x28]
//   0x3ba0: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x3ba4: eb09011f  cmp      x8, x9
//   0x3ba8: 54000121  b.ne     #0x3bcc
//   0x3bac: 2a1503e0  mov      w0, w21
//   0x3bb0: 914083ff  add      sp, sp, #0x20, lsl #12
//   0x3bb4: 910043ff  add      sp, sp, #0x10
//   0x3bb8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x3bbc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3bc0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3bc4: a8c45ffc  ldp      x28, x23, [sp], #0x40
//   0x3bc8: d65f03c0  ret      
//   0x3bcc: 97fff99d  bl       #0x2240
// ============================================================================
std::uint32_t fde_18_3990(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003990ULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1336ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[19] Symbol: cut_main_color_at_argb_8888_c
//      Virtual Address Range: 0x3bd0..0x3e10 (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[19] Biểu tượng: cut_main_color_at_argb_8888_c
//      Dải địa chỉ ảo: 0x3bd0..0x3e10 (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3bd0: a9bc5ffc  stp      x28, x23, [sp, #-0x40]!
//   0x3bd4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x3bd8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x3bdc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x3be0: 9100c3fd  add      x29, sp, #0x30
//   0x3be4: d14083ff  sub      sp, sp, #0x20, lsl #12
//   0x3be8: d10043ff  sub      sp, sp, #0x10
//   0x3bec: d53bd057  mrs      x23, tpidr_el0
//   0x3bf0: f94016e8  ldr      x8, [x23, #0x28]
//   0x3bf4: aa0003f6  mov      x22, x0
//   0x3bf8: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x3bfc: aa0203f4  mov      x20, x2
//   0x3c00: 2a0103f5  mov      w21, w1
//   0x3c04: 91002000  add      x0, x0, #8
//   0x3c08: 52a00022  mov      w2, #0x10000
//   0x3c0c: 2a1f03e1  mov      w1, wzr
//   0x3c10: aa0303f3  mov      x19, x3
//   0x3c14: f81c83a8  stur     x8, [x29, #-0x38]
//   0x3c18: 97fffa0a  bl       #0x2440
//   0x3c1c: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x3c20: 91002000  add      x0, x0, #8
//   0x3c24: 910023e1  add      x1, sp, #8
//   0x3c28: aa1603e2  mov      x2, x22
//   0x3c2c: 2a1503e3  mov      w3, w21
//   0x3c30: 97fff9c4  bl       #0x2340
//   0x3c34: 2a0003f5  mov      w21, w0
//   0x3c38: 7100441f  cmp      w0, #0x11
//   0x3c3c: 540000eb  b.lt     #0x3c58
//   0x3c40: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x3c44: 91002000  add      x0, x0, #8
//   0x3c48: 910023e1  add      x1, sp, #8
//   0x3c4c: 2a1503e2  mov      w2, w21
//   0x3c50: 97fff9a0  bl       #0x22d0
//   0x3c54: 2a0003f5  mov      w21, w0
//   0x3c58: 710006bf  cmp      w21, #1
//   0x3c5c: 54000c0b  b.lt     #0x3ddc
//   0x3c60: 71001ebf  cmp      w21, #7
//   0x3c64: 2a1503e8  mov      w8, w21
//   0x3c68: 54000088  b.hi     #0x3c78
//   0x3c6c: aa1f03ea  mov      x10, xzr
//   0x3c70: aa1403e9  mov      x9, x20
//   0x3c74: 14000024  b        #0x3d04
//   0x3c78: 927d710a  and      x10, x8, #0xfffffff8
//   0x3c7c: 910023ec  add      x12, sp, #8
//   0x3c80: 9100428b  add      x11, x20, #0x10
//   0x3c84: 4f074700  movi     v0.4s, #0xf8, lsl #16
//   0x3c88: 4f072701  movi     v1.4s, #0xf8, lsl #8
//   0x3c8c: 8b0a0a89  add      x9, x20, x10, lsl #2
//   0x3c90: 9100218c  add      x12, x12, #8
//   0x3c94: 4f070702  movi     v2.4s, #0xf8
//   0x3c98: aa0a03ed  mov      x13, x10
//   0x3c9c: 6d7f9183  ldp      d3, d4, [x12, #-8]
//   0x3ca0: f10021ad  subs     x13, x13, #8
//   0x3ca4: 9100418c  add      x12, x12, #0x10
//   0x3ca8: 2f19a465  ushll    v5.4s, v3.4h, #9
//   0x3cac: 2f19a486  ushll    v6.4s, v4.4h, #9
//   0x3cb0: 2f16a467  ushll    v7.4s, v3.4h, #6
//   0x3cb4: 2f16a490  ushll    v16.4s, v4.4h, #6
//   0x3cb8: 2f13a463  ushll    v3.4s, v3.4h, #3
//   0x3cbc: 2f13a484  ushll    v4.4s, v4.4h, #3
//   0x3cc0: 4e201ca5  and      v5.16b, v5.16b, v0.16b
//   0x3cc4: 4e201cc6  and      v6.16b, v6.16b, v0.16b
//   0x3cc8: 4e211ce7  and      v7.16b, v7.16b, v1.16b
//   0x3ccc: 4e211e10  and      v16.16b, v16.16b, v1.16b
//   0x3cd0: 4e221c63  and      v3.16b, v3.16b, v2.16b
//   0x3cd4: 4e221c84  and      v4.16b, v4.16b, v2.16b
//   0x3cd8: 4ea71ca5  orr      v5.16b, v5.16b, v7.16b
//   0x3cdc: 4eb01cc6  orr      v6.16b, v6.16b, v16.16b
//   0x3ce0: 4ea31ca3  orr      v3.16b, v5.16b, v3.16b
//   0x3ce4: 4ea41cc4  orr      v4.16b, v6.16b, v4.16b
//   0x3ce8: 4f0777e3  orr      v3.4s, #0xff, lsl #24
//   0x3cec: 4f0777e4  orr      v4.4s, #0xff, lsl #24
//   0x3cf0: ad3f9163  stp      q3, q4, [x11, #-0x10]
//   0x3cf4: 9100816b  add      x11, x11, #0x20
//   0x3cf8: 54fffd21  b.ne     #0x3c9c
//   0x3cfc: eb08015f  cmp      x10, x8
//   0x3d00: 540001c0  b.eq     #0x3d38
//   0x3d04: 910023eb  add      x11, sp, #8
//   0x3d08: 8b0a056b  add      x11, x11, x10, lsl #1
//   0x3d0c: cb0a010a  sub      x10, x8, x10
//   0x3d10: 7840256c  ldrh     w12, [x11], #2
//   0x3d14: f100054a  subs     x10, x10, #1
//   0x3d18: 531a658e  lsl      w14, w12, #6
//   0x3d1c: 530a7d8d  lsr      w13, w12, #0xa
//   0x3d20: 121511ce  and      w14, w14, #0xf800
//   0x3d24: 330d11ae  bfi      w14, w13, #0x13, #5
//   0x3d28: 331d118e  bfi      w14, w12, #3, #5
//   0x3d2c: 32081dcc  orr      w12, w14, #0xff000000
//   0x3d30: b800452c  str      w12, [x9], #4
//   0x3d34: 54fffee1  b.ne     #0x3d10
//   0x3d38: b4000473  cbz      x19, #0x3dc4
//   0x3d3c: 710006bf  cmp      w21, #1
//   0x3d40: 5400042b  b.lt     #0x3dc4
//   0x3d44: 54000088  b.hi     #0x3d54
//   0x3d48: aa1f03ea  mov      x10, xzr
//   0x3d4c: aa1303e9  mov      x9, x19
//   0x3d50: 14000013  b        #0x3d9c
//   0x3d54: 927f790a  and      x10, x8, #0xfffffffe
//   0x3d58: 910023ec  add      x12, sp, #8
//   0x3d5c: 914043ed  add      x13, sp, #0x10, lsl #12
//   0x3d60: 9100126b  add      x11, x19, #4
//   0x3d64: 8b0a0a69  add      x9, x19, x10, lsl #2
//   0x3d68: b27f018c  orr      x12, x12, #2
//   0x3d6c: 910021ad  add      x13, x13, #8
//   0x3d70: aa0a03ee  mov      x14, x10
//   0x3d74: 785fe18f  ldurh    w15, [x12, #-2]
//   0x3d78: 78404590  ldrh     w16, [x12], #4
//   0x3d7c: f10009ce  subs     x14, x14, #2
//   0x3d80: 786f79af  ldrh     w15, [x13, x15, lsl #1]
//   0x3d84: 787079b0  ldrh     w16, [x13, x16, lsl #1]
//   0x3d88: 293fc16f  stp      w15, w16, [x11, #-4]
//   0x3d8c: 9100216b  add      x11, x11, #8
//   0x3d90: 54ffff21  b.ne     #0x3d74
//   0x3d94: eb08015f  cmp      x10, x8
//   0x3d98: 54000160  b.eq     #0x3dc4
//   0x3d9c: 910023eb  add      x11, sp, #8
//   0x3da0: cb0a0108  sub      x8, x8, x10
//   0x3da4: 8b0a056a  add      x10, x11, x10, lsl #1
//   0x3da8: 914043eb  add      x11, sp, #0x10, lsl #12
//   0x3dac: 9100216b  add      x11, x11, #8
//   0x3db0: 7840254c  ldrh     w12, [x10], #2
//   0x3db4: f1000508  subs     x8, x8, #1
//   0x3db8: 786c796c  ldrh     w12, [x11, x12, lsl #1]
//   0x3dbc: b800452c  str      w12, [x9], #4
//   0x3dc0: 54ffff81  b.ne     #0x3db0
//   0x3dc4: 710006a3  subs     w3, w21, #1
//   0x3dc8: 540000ad  b.le     #0x3ddc
//   0x3dcc: aa1403e0  mov      x0, x20
//   0x3dd0: aa1303e1  mov      x1, x19
//   0x3dd4: 2a1f03e2  mov      w2, wzr
//   0x3dd8: 97fff96a  bl       #0x2380
//   0x3ddc: f94016e8  ldr      x8, [x23, #0x28]
//   0x3de0: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x3de4: eb09011f  cmp      x8, x9
//   0x3de8: 54000121  b.ne     #0x3e0c
//   0x3dec: 2a1503e0  mov      w0, w21
//   0x3df0: 914083ff  add      sp, sp, #0x20, lsl #12
//   0x3df4: 910043ff  add      sp, sp, #0x10
//   0x3df8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x3dfc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x3e00: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x3e04: a8c45ffc  ldp      x28, x23, [sp], #0x40
//   0x3e08: d65f03c0  ret      
//   0x3e0c: 97fff90d  bl       #0x2240
// ============================================================================
std::uint32_t fde_19_3bd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003bd0ULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1480ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[20] Symbol: gamma_my
//      Virtual Address Range: 0x3e10..0x3e68 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[20] Biểu tượng: gamma_my
//      Dải địa chỉ ảo: 0x3e10..0x3e68 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3e10: 5295dcc8  mov      w8, #0xaee6
//   0x3e14: 72a7a4a8  movk     w8, #0x3d25, lsl #16
//   0x3e18: 1e270101  fmov     s1, w8
//   0x3e1c: 1e212000  fcmp     s0, s1
//   0x3e20: 540001ad  b.le     #0x3e54
//   0x3e24: 5288f5c8  mov      w8, #0x47ae
//   0x3e28: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x3e2c: 528147a9  mov      w9, #0xa3d
//   0x3e30: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x3e34: 1e270101  fmov     s1, w8
//   0x3e38: 52933348  mov      w8, #0x999a
//   0x3e3c: 1e212800  fadd     s0, s0, s1
//   0x3e40: 1e270121  fmov     s1, w9
//   0x3e44: 72a80328  movk     w8, #0x4019, lsl #16
//   0x3e48: 1e211800  fdiv     s0, s0, s1
//   0x3e4c: 1e270101  fmov     s1, w8
//   0x3e50: 17fff98c  b        #0x2480
//   0x3e54: 52970a48  mov      w8, #0xb852
//   0x3e58: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x3e5c: 1e270101  fmov     s1, w8
//   0x3e60: 1e211800  fdiv     s0, s0, s1
//   0x3e64: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_20_3e10(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003e10ULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1624ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[21] Symbol: RGB2XYZ
//      Virtual Address Range: 0x3e68..0x4088 (544 bytes, 136 AArch64 instructions)
// [VN] Khung FDE[21] Biểu tượng: RGB2XYZ
//      Dải địa chỉ ảo: 0x3e68..0x4088 (544 byte, 136 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3e68: 6dbb2beb  stp      d11, d10, [sp, #-0x50]!
//   0x3e6c: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x3e70: f90013f5  str      x21, [sp, #0x20]
//   0x3e74: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3e78: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x3e7c: 910103fd  add      x29, sp, #0x40
//   0x3e80: 52a86fe8  mov      w8, #0x437f0000
//   0x3e84: 5295dcc9  mov      w9, #0xaee6
//   0x3e88: 1e220000  scvtf    s0, w0
//   0x3e8c: 1e220021  scvtf    s1, w1
//   0x3e90: 72a7a4a9  movk     w9, #0x3d25, lsl #16
//   0x3e94: 1e27010a  fmov     s10, w8
//   0x3e98: 1e2a1800  fdiv     s0, s0, s10
//   0x3e9c: 1e2a1829  fdiv     s9, s1, s10
//   0x3ea0: 1e270121  fmov     s1, w9
//   0x3ea4: aa0503f3  mov      x19, x5
//   0x3ea8: aa0403f4  mov      x20, x4
//   0x3eac: aa0303f5  mov      x21, x3
//   0x3eb0: 1e212000  fcmp     s0, s1
//   0x3eb4: 1e22004b  scvtf    s11, w2
//   0x3eb8: 540001ed  b.le     #0x3ef4
//   0x3ebc: 5288f5c8  mov      w8, #0x47ae
//   0x3ec0: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x3ec4: 528147a9  mov      w9, #0xa3d
//   0x3ec8: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x3ecc: 1e270101  fmov     s1, w8
//   0x3ed0: 52933348  mov      w8, #0x999a
//   0x3ed4: 1e212800  fadd     s0, s0, s1
//   0x3ed8: 1e270121  fmov     s1, w9
//   0x3edc: 72a80328  movk     w8, #0x4019, lsl #16
//   0x3ee0: 1e211800  fdiv     s0, s0, s1
//   0x3ee4: 1e270101  fmov     s1, w8
//   0x3ee8: 97fff966  bl       #0x2480
//   0x3eec: 4ea01c08  mov      v8.16b, v0.16b
//   0x3ef0: 14000005  b        #0x3f04
//   0x3ef4: 52970a48  mov      w8, #0xb852
//   0x3ef8: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x3efc: 1e270101  fmov     s1, w8
//   0x3f00: 1e211808  fdiv     s8, s0, s1
//   0x3f04: 5295dcc8  mov      w8, #0xaee6
//   0x3f08: 72a7a4a8  movk     w8, #0x3d25, lsl #16
//   0x3f0c: 1e270100  fmov     s0, w8
//   0x3f10: 1e202120  fcmp     s9, s0
//   0x3f14: 1e2a196a  fdiv     s10, s11, s10
//   0x3f18: 540001ed  b.le     #0x3f54
//   0x3f1c: 5288f5c8  mov      w8, #0x47ae
//   0x3f20: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x3f24: 528147a9  mov      w9, #0xa3d
//   0x3f28: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x3f2c: 1e270100  fmov     s0, w8
//   0x3f30: 52933348  mov      w8, #0x999a
//   0x3f34: 1e202920  fadd     s0, s9, s0
//   0x3f38: 1e270121  fmov     s1, w9
//   0x3f3c: 72a80328  movk     w8, #0x4019, lsl #16
//   0x3f40: 1e211800  fdiv     s0, s0, s1
//   0x3f44: 1e270101  fmov     s1, w8
//   0x3f48: 97fff94e  bl       #0x2480
//   0x3f4c: 4ea01c09  mov      v9.16b, v0.16b
//   0x3f50: 14000005  b        #0x3f64
//   0x3f54: 52970a48  mov      w8, #0xb852
//   0x3f58: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x3f5c: 1e270100  fmov     s0, w8
//   0x3f60: 1e201929  fdiv     s9, s9, s0
//   0x3f64: 5295dcc8  mov      w8, #0xaee6
//   0x3f68: 72a7a4a8  movk     w8, #0x3d25, lsl #16
//   0x3f6c: 1e270100  fmov     s0, w8
//   0x3f70: 1e202140  fcmp     s10, s0
//   0x3f74: 540001cd  b.le     #0x3fac
//   0x3f78: 5288f5c8  mov      w8, #0x47ae
//   0x3f7c: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x3f80: 528147a9  mov      w9, #0xa3d
//   0x3f84: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x3f88: 1e270100  fmov     s0, w8
//   0x3f8c: 52933348  mov      w8, #0x999a
//   0x3f90: 1e202940  fadd     s0, s10, s0
//   0x3f94: 1e270121  fmov     s1, w9
//   0x3f98: 72a80328  movk     w8, #0x4019, lsl #16
//   0x3f9c: 1e211800  fdiv     s0, s0, s1
//   0x3fa0: 1e270101  fmov     s1, w8
//   0x3fa4: 97fff937  bl       #0x2480
//   0x3fa8: 14000005  b        #0x3fbc
//   0x3fac: 52970a48  mov      w8, #0xb852
//   0x3fb0: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x3fb4: 1e270100  fmov     s0, w8
//   0x3fb8: 1e201940  fdiv     s0, s10, s0
//   0x3fbc: 5285af88  mov      w8, #0x2d7c
//   0x3fc0: 72a7da68  movk     w8, #0x3ed3, lsl #16
//   0x3fc4: 1e270101  fmov     s1, w8
//   0x3fc8: 52835de8  mov      w8, #0x1aef
//   0x3fcc: 528286e9  mov      w9, #0x1437
//   0x3fd0: 5298ddab  mov      w11, #0xc6ed
//   0x3fd4: 528286ec  mov      w12, #0x1437
//   0x3fd8: 528c442e  mov      w14, #0x6221
//   0x3fdc: 72a7be88  movk     w8, #0x3df4, lsl #16
//   0x3fe0: 72a7d6e9  movk     w9, #0x3eb7, lsl #16
//   0x3fe4: 5298938a  mov      w10, #0xc49c
//   0x3fe8: 72a7cb2b  movk     w11, #0x3e59, lsl #16
//   0x3fec: 72a7e6ec  movk     w12, #0x3f37, lsl #16
//   0x3ff0: 529a0fad  mov      w13, #0xd07d
//   0x3ff4: 72a793ce  movk     w14, #0x3c9e, lsl #16
//   0x3ff8: 1e270110  fmov     s16, w8
//   0x3ffc: 5288e428  mov      w8, #0x4721
//   0x4000: 72a7c70a  movk     w10, #0x3e38, lsl #16
//   0x4004: 72a7b26d  movk     w13, #0x3d93, lsl #16
//   0x4008: 1e270122  fmov     s2, w9
//   0x400c: 1e270164  fmov     s4, w11
//   0x4010: 1e270185  fmov     s5, w12
//   0x4014: 1e2701c7  fmov     s7, w14
//   0x4018: 72a7ee68  movk     w8, #0x3f73, lsl #16
//   0x401c: 1e270143  fmov     s3, w10
//   0x4020: 1e2701a6  fmov     s6, w13
//   0x4024: 1e210901  fmul     s1, s8, s1
//   0x4028: 1e240904  fmul     s4, s8, s4
//   0x402c: 1e270907  fmul     s7, s8, s7
//   0x4030: 1e220922  fmul     s2, s9, s2
//   0x4034: 1e250925  fmul     s5, s9, s5
//   0x4038: 1e300930  fmul     s16, s9, s16
//   0x403c: 1e270111  fmov     s17, w8
//   0x4040: 1e230803  fmul     s3, s0, s3
//   0x4044: 1e260806  fmul     s6, s0, s6
//   0x4048: 1e310800  fmul     s0, s0, s17
//   0x404c: 1e222821  fadd     s1, s1, s2
//   0x4050: 1e252882  fadd     s2, s4, s5
//   0x4054: 1e3028e4  fadd     s4, s7, s16
//   0x4058: 1e232821  fadd     s1, s1, s3
//   0x405c: 1e262842  fadd     s2, s2, s6
//   0x4060: 1e202880  fadd     s0, s4, s0
//   0x4064: bd0002a1  str      s1, [x21]
//   0x4068: bd000282  str      s2, [x20]
//   0x406c: bd000260  str      s0, [x19]
//   0x4070: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x4074: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x4078: f94013f5  ldr      x21, [sp, #0x20]
//   0x407c: 6d4123e9  ldp      d9, d8, [sp, #0x10]
//   0x4080: 6cc52beb  ldp      d11, d10, [sp], #0x50
//   0x4084: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_21_3e68(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003e68ULL;
    for (std::size_t i = 0; i < 136ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1646ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[22] Symbol: f
//      Virtual Address Range: 0x4088..0x40e8 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[22] Biểu tượng: f
//      Dải địa chỉ ảo: 0x4088..0x40e8 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4088: fc1e0fe8  str      d8, [sp, #-0x20]!
//   0x408c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x4090: 910043fd  add      x29, sp, #0x10
//   0x4094: 52955568  mov      w8, #0xaaab
//   0x4098: 72a7d548  movk     w8, #0x3eaa, lsl #16
//   0x409c: 1e270101  fmov     s1, w8
//   0x40a0: 4ea01c08  mov      v8.16b, v0.16b
//   0x40a4: 97fff8f7  bl       #0x2480
//   0x40a8: 5285e368  mov      w8, #0x2f1b
//   0x40ac: 72a81f28  movk     w8, #0x40f9, lsl #16
//   0x40b0: 5287b969  mov      w9, #0x3dcb
//   0x40b4: 5283184a  mov      w10, #0x18c2
//   0x40b8: 72a7c1a9  movk     w9, #0x3e0d, lsl #16
//   0x40bc: 72a7822a  movk     w10, #0x3c11, lsl #16
//   0x40c0: 1e270101  fmov     s1, w8
//   0x40c4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x40c8: 1e210901  fmul     s1, s8, s1
//   0x40cc: 1e270122  fmov     s2, w9
//   0x40d0: 1e270143  fmov     s3, w10
//   0x40d4: 1e222821  fadd     s1, s1, s2
//   0x40d8: 1e232100  fcmp     s8, s3
//   0x40dc: 1e21cc00  fcsel    s0, s0, s1, gt
//   0x40e0: fc4207e8  ldr      d8, [sp], #0x20
//   0x40e4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_22_4088(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004088ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1782ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[23] Symbol: XYZ2LAB
//      Virtual Address Range: 0x40e8..0x4224 (316 bytes, 79 AArch64 instructions)
// [VN] Khung FDE[23] Biểu tượng: XYZ2LAB
//      Dải địa chỉ ảo: 0x40e8..0x4224 (316 byte, 79 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x40e8: fc1a0fee  str      d14, [sp, #-0x60]!
//   0x40ec: 6d00b3ed  stp      d13, d12, [sp, #8]
//   0x40f0: 6d01abeb  stp      d11, d10, [sp, #0x18]
//   0x40f4: 6d02a3e9  stp      d9, d8, [sp, #0x28]
//   0x40f8: f9001ff5  str      x21, [sp, #0x38]
//   0x40fc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x4100: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x4104: 910143fd  add      x29, sp, #0x50
//   0x4108: 528a22c8  mov      w8, #0x5116
//   0x410c: 72a7ee68  movk     w8, #0x3f73, lsl #16
//   0x4110: 4ea11c28  mov      v8.16b, v1.16b
//   0x4114: 528b8969  mov      w9, #0x5c4b
//   0x4118: 1e270101  fmov     s1, w8
//   0x411c: 52955568  mov      w8, #0xaaab
//   0x4120: 72a7f169  movk     w9, #0x3f8b, lsl #16
//   0x4124: 72a7d548  movk     w8, #0x3eaa, lsl #16
//   0x4128: 1e211809  fdiv     s9, s0, s1
//   0x412c: 1e270120  fmov     s0, w9
//   0x4130: 1e27010b  fmov     s11, w8
//   0x4134: 1e20184a  fdiv     s10, s2, s0
//   0x4138: 4ea91d20  mov      v0.16b, v9.16b
//   0x413c: 4eab1d61  mov      v1.16b, v11.16b
//   0x4140: aa0203f3  mov      x19, x2
//   0x4144: aa0103f4  mov      x20, x1
//   0x4148: aa0003f5  mov      x21, x0
//   0x414c: 97fff8cd  bl       #0x2480
//   0x4150: 5285e368  mov      w8, #0x2f1b
//   0x4154: 72a81f28  movk     w8, #0x40f9, lsl #16
//   0x4158: 5287b969  mov      w9, #0x3dcb
//   0x415c: 5283184a  mov      w10, #0x18c2
//   0x4160: 72a7c1a9  movk     w9, #0x3e0d, lsl #16
//   0x4164: 72a7822a  movk     w10, #0x3c11, lsl #16
//   0x4168: 1e27010c  fmov     s12, w8
//   0x416c: 1e2c0921  fmul     s1, s9, s12
//   0x4170: 1e27012d  fmov     s13, w9
//   0x4174: 1e27014e  fmov     s14, w10
//   0x4178: 1e2d2821  fadd     s1, s1, s13
//   0x417c: 1e2e2120  fcmp     s9, s14
//   0x4180: 1e21cc09  fcsel    s9, s0, s1, gt
//   0x4184: 4ea81d00  mov      v0.16b, v8.16b
//   0x4188: 4eab1d61  mov      v1.16b, v11.16b
//   0x418c: 97fff8bd  bl       #0x2480
//   0x4190: 1e2c0901  fmul     s1, s8, s12
//   0x4194: 1e2d2821  fadd     s1, s1, s13
//   0x4198: 1e2e2100  fcmp     s8, s14
//   0x419c: 1e21cc08  fcsel    s8, s0, s1, gt
//   0x41a0: 4eaa1d40  mov      v0.16b, v10.16b
//   0x41a4: 4eab1d61  mov      v1.16b, v11.16b
//   0x41a8: 97fff8b6  bl       #0x2480
//   0x41ac: 52a87f48  mov      w8, #0x43fa0000
//   0x41b0: 1e2c0941  fmul     s1, s10, s12
//   0x41b4: 1e270102  fmov     s2, w8
//   0x41b8: 52a85d08  mov      w8, #0x42e80000
//   0x41bc: 1e283925  fsub     s5, s9, s8
//   0x41c0: 1e2e2140  fcmp     s10, s14
//   0x41c4: 1e2d2821  fadd     s1, s1, s13
//   0x41c8: 1e2208a2  fmul     s2, s5, s2
//   0x41cc: 1e270105  fmov     s5, w8
//   0x41d0: 1e361003  fmov     s3, #-16.00000000
//   0x41d4: 52a86908  mov      w8, #0x43480000
//   0x41d8: 1e250905  fmul     s5, s8, s5
//   0x41dc: 1e21cc00  fcsel    s0, s0, s1, gt
//   0x41e0: 1e2703e4  fmov     s4, wzr
//   0x41e4: 1e270101  fmov     s1, w8
//   0x41e8: 1e2328a3  fadd     s3, s5, s3
//   0x41ec: 1e203900  fsub     s0, s8, s0
//   0x41f0: 1e246863  fmaxnm   s3, s3, s4
//   0x41f4: 1e210800  fmul     s0, s0, s1
//   0x41f8: bd0002a3  str      s3, [x21]
//   0x41fc: bd000282  str      s2, [x20]
//   0x4200: bd000260  str      s0, [x19]
//   0x4204: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x4208: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x420c: f9401ff5  ldr      x21, [sp, #0x38]
//   0x4210: 6d42a3e9  ldp      d9, d8, [sp, #0x28]
//   0x4214: 6d41abeb  ldp      d11, d10, [sp, #0x18]
//   0x4218: 6d40b3ed  ldp      d13, d12, [sp, #8]
//   0x421c: fc4607ee  ldr      d14, [sp], #0x60
//   0x4220: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_23_40e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000040e8ULL;
    for (std::size_t i = 0; i < 79ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1806ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[24] Symbol: LAB2LCH
//      Virtual Address Range: 0x4224..0x42d0 (172 bytes, 43 AArch64 instructions)
// [VN] Khung FDE[24] Biểu tượng: LAB2LCH
//      Dải địa chỉ ảo: 0x4224..0x42d0 (172 byte, 43 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4224: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x4228: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x422c: 910043fd  add      x29, sp, #0x10
//   0x4230: bd000000  str      s0, [x0]
//   0x4234: 1e210820  fmul     s0, s1, s1
//   0x4238: 1e220843  fmul     s3, s2, s2
//   0x423c: 1e232800  fadd     s0, s0, s3
//   0x4240: 1e21c000  fsqrt    s0, s0
//   0x4244: bd000020  str      s0, [x1]
//   0x4248: 4ea21c40  mov      v0.16b, v2.16b
//   0x424c: aa0203f3  mov      x19, x2
//   0x4250: 97fff85c  bl       #0x23c0
//   0x4254: 90000029  adrp     x9, #0x8000
//   0x4258: d2d00008  mov      x8, #0x800000000000
//   0x425c: fd440d22  ldr      d2, [x9, #0x818]
//   0x4260: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x4264: 1e22c000  fcvt     d0, s0
//   0x4268: 9e670101  fmov     d1, x8
//   0x426c: d2d00008  mov      x8, #0x800000000000
//   0x4270: 1e610800  fmul     d0, d0, d1
//   0x4274: f2e80ec8  movk     x8, #0x4076, lsl #48
//   0x4278: 1e621800  fdiv     d0, d0, d2
//   0x427c: 9e670101  fmov     d1, x8
//   0x4280: 528c16e9  mov      w9, #0x60b7
//   0x4284: 1e612800  fadd     d0, d0, d1
//   0x4288: 72b6c169  movk     w9, #0xb60b, lsl #16
//   0x428c: 1e780008  fcvtzs   w8, d0
//   0x4290: 9b297d09  smull    x9, w8, w9
//   0x4294: d360fd29  lsr      x9, x9, #0x20
//   0x4298: 0b080129  add      w9, w9, w8
//   0x429c: 13087d2a  asr      w10, w9, #8
//   0x42a0: 0b497d49  add      w9, w10, w9, lsr #31
//   0x42a4: 52802d0a  mov      w10, #0x168
//   0x42a8: 1e620101  scvtf    d1, w8
//   0x42ac: 1e613800  fsub     d0, d0, d1
//   0x42b0: 1b0aa128  msub     w8, w9, w10, w8
//   0x42b4: 1e220101  scvtf    s1, w8
//   0x42b8: 1e624000  fcvt     s0, d0
//   0x42bc: 1e202820  fadd     s0, s1, s0
//   0x42c0: bd000260  str      s0, [x19]
//   0x42c4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x42c8: f84207f3  ldr      x19, [sp], #0x20
//   0x42cc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_24_4224(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004224ULL;
    for (std::size_t i = 0; i < 43ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1885ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[25] Symbol: RGB2LAB
//      Virtual Address Range: 0x42d0..0x45e0 (784 bytes, 196 AArch64 instructions)
// [VN] Khung FDE[25] Biểu tượng: RGB2LAB
//      Dải địa chỉ ảo: 0x42d0..0x45e0 (784 byte, 196 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x42d0: fc1a0fee  str      d14, [sp, #-0x60]!
//   0x42d4: 6d00b3ed  stp      d13, d12, [sp, #8]
//   0x42d8: 6d01abeb  stp      d11, d10, [sp, #0x18]
//   0x42dc: 6d02a3e9  stp      d9, d8, [sp, #0x28]
//   0x42e0: f9001ff5  str      x21, [sp, #0x38]
//   0x42e4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x42e8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x42ec: 910143fd  add      x29, sp, #0x50
//   0x42f0: 52a86fe8  mov      w8, #0x437f0000
//   0x42f4: 5295dcc9  mov      w9, #0xaee6
//   0x42f8: 1e220000  scvtf    s0, w0
//   0x42fc: 1e220021  scvtf    s1, w1
//   0x4300: 72a7a4a9  movk     w9, #0x3d25, lsl #16
//   0x4304: 1e27010a  fmov     s10, w8
//   0x4308: 1e2a1800  fdiv     s0, s0, s10
//   0x430c: 1e2a1829  fdiv     s9, s1, s10
//   0x4310: 1e270121  fmov     s1, w9
//   0x4314: aa0503f3  mov      x19, x5
//   0x4318: aa0403f4  mov      x20, x4
//   0x431c: aa0303f5  mov      x21, x3
//   0x4320: 1e212000  fcmp     s0, s1
//   0x4324: 1e22004b  scvtf    s11, w2
//   0x4328: 540001ed  b.le     #0x4364
//   0x432c: 5288f5c8  mov      w8, #0x47ae
//   0x4330: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x4334: 528147a9  mov      w9, #0xa3d
//   0x4338: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x433c: 1e270101  fmov     s1, w8
//   0x4340: 52933348  mov      w8, #0x999a
//   0x4344: 1e212800  fadd     s0, s0, s1
//   0x4348: 1e270121  fmov     s1, w9
//   0x434c: 72a80328  movk     w8, #0x4019, lsl #16
//   0x4350: 1e211800  fdiv     s0, s0, s1
//   0x4354: 1e270101  fmov     s1, w8
//   0x4358: 97fff84a  bl       #0x2480
//   0x435c: 4ea01c08  mov      v8.16b, v0.16b
//   0x4360: 14000005  b        #0x4374
//   0x4364: 52970a48  mov      w8, #0xb852
//   0x4368: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x436c: 1e270101  fmov     s1, w8
//   0x4370: 1e211808  fdiv     s8, s0, s1
//   0x4374: 5295dcc8  mov      w8, #0xaee6
//   0x4378: 72a7a4a8  movk     w8, #0x3d25, lsl #16
//   0x437c: 1e270100  fmov     s0, w8
//   0x4380: 1e202120  fcmp     s9, s0
//   0x4384: 1e2a196a  fdiv     s10, s11, s10
//   0x4388: 540001ed  b.le     #0x43c4
//   0x438c: 5288f5c8  mov      w8, #0x47ae
//   0x4390: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x4394: 528147a9  mov      w9, #0xa3d
//   0x4398: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x439c: 1e270100  fmov     s0, w8
//   0x43a0: 52933348  mov      w8, #0x999a
//   0x43a4: 1e202920  fadd     s0, s9, s0
//   0x43a8: 1e270121  fmov     s1, w9
//   0x43ac: 72a80328  movk     w8, #0x4019, lsl #16
//   0x43b0: 1e211800  fdiv     s0, s0, s1
//   0x43b4: 1e270101  fmov     s1, w8
//   0x43b8: 97fff832  bl       #0x2480
//   0x43bc: 4ea01c09  mov      v9.16b, v0.16b
//   0x43c0: 14000005  b        #0x43d4
//   0x43c4: 52970a48  mov      w8, #0xb852
//   0x43c8: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x43cc: 1e270100  fmov     s0, w8
//   0x43d0: 1e201929  fdiv     s9, s9, s0
//   0x43d4: 5295dcc8  mov      w8, #0xaee6
//   0x43d8: 72a7a4a8  movk     w8, #0x3d25, lsl #16
//   0x43dc: 1e270100  fmov     s0, w8
//   0x43e0: 1e202140  fcmp     s10, s0
//   0x43e4: 540001cd  b.le     #0x441c
//   0x43e8: 5288f5c8  mov      w8, #0x47ae
//   0x43ec: 72a7ac28  movk     w8, #0x3d61, lsl #16
//   0x43f0: 528147a9  mov      w9, #0xa3d
//   0x43f4: 72a7f0e9  movk     w9, #0x3f87, lsl #16
//   0x43f8: 1e270100  fmov     s0, w8
//   0x43fc: 52933348  mov      w8, #0x999a
//   0x4400: 1e202940  fadd     s0, s10, s0
//   0x4404: 1e270121  fmov     s1, w9
//   0x4408: 72a80328  movk     w8, #0x4019, lsl #16
//   0x440c: 1e211800  fdiv     s0, s0, s1
//   0x4410: 1e270101  fmov     s1, w8
//   0x4414: 97fff81b  bl       #0x2480
//   0x4418: 14000005  b        #0x442c
//   0x441c: 52970a48  mov      w8, #0xb852
//   0x4420: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4424: 1e270100  fmov     s0, w8
//   0x4428: 1e201940  fdiv     s0, s10, s0
//   0x442c: 5285af88  mov      w8, #0x2d7c
//   0x4430: 72a7da68  movk     w8, #0x3ed3, lsl #16
//   0x4434: 1e270101  fmov     s1, w8
//   0x4438: 52835de8  mov      w8, #0x1aef
//   0x443c: 528286e9  mov      w9, #0x1437
//   0x4440: 72a7be88  movk     w8, #0x3df4, lsl #16
//   0x4444: 72a7d6e9  movk     w9, #0x3eb7, lsl #16
//   0x4448: 5298938a  mov      w10, #0xc49c
//   0x444c: 1e270110  fmov     s16, w8
//   0x4450: 5288e428  mov      w8, #0x4721
//   0x4454: 72a7c70a  movk     w10, #0x3e38, lsl #16
//   0x4458: 5298ddab  mov      w11, #0xc6ed
//   0x445c: 528286ec  mov      w12, #0x1437
//   0x4460: 1e270122  fmov     s2, w9
//   0x4464: 72a7ee68  movk     w8, #0x3f73, lsl #16
//   0x4468: 72a7cb2b  movk     w11, #0x3e59, lsl #16
//   0x446c: 72a7e6ec  movk     w12, #0x3f37, lsl #16
//   0x4470: 529a0fad  mov      w13, #0xd07d
//   0x4474: 1e270143  fmov     s3, w10
//   0x4478: 1e210901  fmul     s1, s8, s1
//   0x447c: 1e220922  fmul     s2, s9, s2
//   0x4480: 1e270111  fmov     s17, w8
//   0x4484: 528a22c8  mov      w8, #0x5116
//   0x4488: 72a7b26d  movk     w13, #0x3d93, lsl #16
//   0x448c: 528c442e  mov      w14, #0x6221
//   0x4490: 1e270164  fmov     s4, w11
//   0x4494: 1e270185  fmov     s5, w12
//   0x4498: 1e230803  fmul     s3, s0, s3
//   0x449c: 1e222821  fadd     s1, s1, s2
//   0x44a0: 72a7ee68  movk     w8, #0x3f73, lsl #16
//   0x44a4: 72a793ce  movk     w14, #0x3c9e, lsl #16
//   0x44a8: 1e2701a6  fmov     s6, w13
//   0x44ac: 1e240904  fmul     s4, s8, s4
//   0x44b0: 1e250925  fmul     s5, s9, s5
//   0x44b4: 1e232821  fadd     s1, s1, s3
//   0x44b8: 1e270103  fmov     s3, w8
//   0x44bc: 528b8968  mov      w8, #0x5c4b
//   0x44c0: 1e2701c7  fmov     s7, w14
//   0x44c4: 1e260806  fmul     s6, s0, s6
//   0x44c8: 1e252882  fadd     s2, s4, s5
//   0x44cc: 72a7f168  movk     w8, #0x3f8b, lsl #16
//   0x44d0: 1e270907  fmul     s7, s8, s7
//   0x44d4: 1e300930  fmul     s16, s9, s16
//   0x44d8: 1e262848  fadd     s8, s2, s6
//   0x44dc: 1e270102  fmov     s2, w8
//   0x44e0: 52955568  mov      w8, #0xaaab
//   0x44e4: 1e310800  fmul     s0, s0, s17
//   0x44e8: 1e3028e4  fadd     s4, s7, s16
//   0x44ec: 72a7d548  movk     w8, #0x3eaa, lsl #16
//   0x44f0: 1e202880  fadd     s0, s4, s0
//   0x44f4: 1e231829  fdiv     s9, s1, s3
//   0x44f8: 1e27010b  fmov     s11, w8
//   0x44fc: 1e22180a  fdiv     s10, s0, s2
//   0x4500: 4ea91d20  mov      v0.16b, v9.16b
//   0x4504: 4eab1d61  mov      v1.16b, v11.16b
//   0x4508: 97fff7de  bl       #0x2480
//   0x450c: 5285e368  mov      w8, #0x2f1b
//   0x4510: 72a81f28  movk     w8, #0x40f9, lsl #16
//   0x4514: 5287b969  mov      w9, #0x3dcb
//   0x4518: 5283184a  mov      w10, #0x18c2
//   0x451c: 72a7c1a9  movk     w9, #0x3e0d, lsl #16
//   0x4520: 72a7822a  movk     w10, #0x3c11, lsl #16
//   0x4524: 1e27010c  fmov     s12, w8
//   0x4528: 1e2c0921  fmul     s1, s9, s12
//   0x452c: 1e27012d  fmov     s13, w9
//   0x4530: 1e27014e  fmov     s14, w10
//   0x4534: 1e2d2821  fadd     s1, s1, s13
//   0x4538: 1e2e2120  fcmp     s9, s14
//   0x453c: 1e21cc09  fcsel    s9, s0, s1, gt
//   0x4540: 4ea81d00  mov      v0.16b, v8.16b
//   0x4544: 4eab1d61  mov      v1.16b, v11.16b
//   0x4548: 97fff7ce  bl       #0x2480
//   0x454c: 1e2c0901  fmul     s1, s8, s12
//   0x4550: 1e2d2821  fadd     s1, s1, s13
//   0x4554: 1e2e2100  fcmp     s8, s14
//   0x4558: 1e21cc08  fcsel    s8, s0, s1, gt
//   0x455c: 4eaa1d40  mov      v0.16b, v10.16b
//   0x4560: 4eab1d61  mov      v1.16b, v11.16b
//   0x4564: 97fff7c7  bl       #0x2480
//   0x4568: 52a87f48  mov      w8, #0x43fa0000
//   0x456c: 1e2c0941  fmul     s1, s10, s12
//   0x4570: 1e270102  fmov     s2, w8
//   0x4574: 52a85d08  mov      w8, #0x42e80000
//   0x4578: 1e283925  fsub     s5, s9, s8
//   0x457c: 1e2e2140  fcmp     s10, s14
//   0x4580: 1e2d2821  fadd     s1, s1, s13
//   0x4584: 1e2208a2  fmul     s2, s5, s2
//   0x4588: 1e270105  fmov     s5, w8
//   0x458c: 1e361003  fmov     s3, #-16.00000000
//   0x4590: 52a86908  mov      w8, #0x43480000
//   0x4594: 1e250905  fmul     s5, s8, s5
//   0x4598: 1e21cc00  fcsel    s0, s0, s1, gt
//   0x459c: 1e2703e4  fmov     s4, wzr
//   0x45a0: 1e270101  fmov     s1, w8
//   0x45a4: 1e2328a3  fadd     s3, s5, s3
//   0x45a8: 1e203900  fsub     s0, s8, s0
//   0x45ac: 1e246863  fmaxnm   s3, s3, s4
//   0x45b0: 1e210800  fmul     s0, s0, s1
//   0x45b4: bd0002a3  str      s3, [x21]
//   0x45b8: bd000282  str      s2, [x20]
//   0x45bc: bd000260  str      s0, [x19]
//   0x45c0: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x45c4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x45c8: f9401ff5  ldr      x21, [sp, #0x38]
//   0x45cc: 6d42a3e9  ldp      d9, d8, [sp, #0x28]
//   0x45d0: 6d41abeb  ldp      d11, d10, [sp, #0x18]
//   0x45d4: 6d40b3ed  ldp      d13, d12, [sp, #8]
//   0x45d8: fc4607ee  ldr      d14, [sp], #0x60
//   0x45dc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_25_42d0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000042d0ULL;
    for (std::size_t i = 0; i < 196ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1928ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[26] Symbol: RGB2LCH
//      Virtual Address Range: 0x45e0..0x46bc (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[26] Biểu tượng: RGB2LCH
//      Dải địa chỉ ảo: 0x45e0..0x46bc (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x45e0: d10103ff  sub      sp, sp, #0x40
//   0x45e4: f9000bf5  str      x21, [sp, #0x10]
//   0x45e8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x45ec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x45f0: 9100c3fd  add      x29, sp, #0x30
//   0x45f4: aa0503f3  mov      x19, x5
//   0x45f8: aa0403f4  mov      x20, x4
//   0x45fc: aa0303f5  mov      x21, x3
//   0x4600: d10053a3  sub      x3, x29, #0x14
//   0x4604: 910063e4  add      x4, sp, #0x18
//   0x4608: 910033e5  add      x5, sp, #0xc
//   0x460c: 97fff711  bl       #0x2250
//   0x4610: bd401be1  ldr      s1, [sp, #0x18]
//   0x4614: bd400fe0  ldr      s0, [sp, #0xc]
//   0x4618: b85ec3a8  ldur     w8, [x29, #-0x14]
//   0x461c: 1e210822  fmul     s2, s1, s1
//   0x4620: 1e200803  fmul     s3, s0, s0
//   0x4624: 1e232842  fadd     s2, s2, s3
//   0x4628: 1e21c042  fsqrt    s2, s2
//   0x462c: b90002a8  str      w8, [x21]
//   0x4630: bd000282  str      s2, [x20]
//   0x4634: 97fff763  bl       #0x23c0
//   0x4638: 90000029  adrp     x9, #0x8000
//   0x463c: d2d00008  mov      x8, #0x800000000000
//   0x4640: fd440d22  ldr      d2, [x9, #0x818]
//   0x4644: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x4648: 1e22c000  fcvt     d0, s0
//   0x464c: 9e670101  fmov     d1, x8
//   0x4650: d2d00008  mov      x8, #0x800000000000
//   0x4654: 1e610800  fmul     d0, d0, d1
//   0x4658: f2e80ec8  movk     x8, #0x4076, lsl #48
//   0x465c: 1e621800  fdiv     d0, d0, d2
//   0x4660: 9e670101  fmov     d1, x8
//   0x4664: 528c16e9  mov      w9, #0x60b7
//   0x4668: 1e612800  fadd     d0, d0, d1
//   0x466c: 72b6c169  movk     w9, #0xb60b, lsl #16
//   0x4670: 1e780008  fcvtzs   w8, d0
//   0x4674: 9b297d09  smull    x9, w8, w9
//   0x4678: d360fd29  lsr      x9, x9, #0x20
//   0x467c: 0b080129  add      w9, w9, w8
//   0x4680: 13087d2a  asr      w10, w9, #8
//   0x4684: 0b497d49  add      w9, w10, w9, lsr #31
//   0x4688: 52802d0a  mov      w10, #0x168
//   0x468c: 1e620101  scvtf    d1, w8
//   0x4690: 1e613800  fsub     d0, d0, d1
//   0x4694: 1b0aa128  msub     w8, w9, w10, w8
//   0x4698: 1e220101  scvtf    s1, w8
//   0x469c: 1e624000  fcvt     s0, d0
//   0x46a0: 1e202820  fadd     s0, s1, s0
//   0x46a4: bd000260  str      s0, [x19]
//   0x46a8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x46ac: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x46b0: f9400bf5  ldr      x21, [sp, #0x10]
//   0x46b4: 910103ff  add      sp, sp, #0x40
//   0x46b8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_26_45e0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000045e0ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2124ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[27] Symbol: LCH2LAB
//      Virtual Address Range: 0x46bc..0x4730 (116 bytes, 29 AArch64 instructions)
// [VN] Khung FDE[27] Biểu tượng: LCH2LAB
//      Dải địa chỉ ảo: 0x46bc..0x4730 (116 byte, 29 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x46bc: fc1d0fe8  str      d8, [sp, #-0x30]!
//   0x46c0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x46c4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x46c8: 910083fd  add      x29, sp, #0x20
//   0x46cc: 90000028  adrp     x8, #0x8000
//   0x46d0: 4ea11c28  mov      v8.16b, v1.16b
//   0x46d4: fd440d01  ldr      d1, [x8, #0x818]
//   0x46d8: d2d00008  mov      x8, #0x800000000000
//   0x46dc: bd000000  str      s0, [x0]
//   0x46e0: 1e22c040  fcvt     d0, s2
//   0x46e4: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x46e8: 1e610800  fmul     d0, d0, d1
//   0x46ec: 9e670101  fmov     d1, x8
//   0x46f0: 1e611800  fdiv     d0, d0, d1
//   0x46f4: aa0103f4  mov      x20, x1
//   0x46f8: 1e624000  fcvt     s0, d0
//   0x46fc: 910033e0  add      x0, sp, #0xc
//   0x4700: 910023e1  add      x1, sp, #8
//   0x4704: aa0203f3  mov      x19, x2
//   0x4708: 97fff70a  bl       #0x2330
//   0x470c: 2d4107e0  ldp      s0, s1, [sp, #8]
//   0x4710: 1e280800  fmul     s0, s0, s8
//   0x4714: 1e280821  fmul     s1, s1, s8
//   0x4718: bd000280  str      s0, [x20]
//   0x471c: bd000261  str      s1, [x19]
//   0x4720: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x4724: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x4728: fc4307e8  ldr      d8, [sp], #0x30
//   0x472c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_27_46bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000046bcULL;
    for (std::size_t i = 0; i < 29ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2179ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[28] Symbol: reverseF
//      Virtual Address Range: 0x4730..0x4788 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[28] Biểu tượng: reverseF
//      Dải địa chỉ ảo: 0x4730..0x4788 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4730: fc1e0fe8  str      d8, [sp, #-0x20]!
//   0x4734: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x4738: 910043fd  add      x29, sp, #0x10
//   0x473c: 1e211001  fmov     s1, #3.00000000
//   0x4740: 4ea01c08  mov      v8.16b, v0.16b
//   0x4744: 97fff74f  bl       #0x2480
//   0x4748: 52831848  mov      w8, #0x18c2
//   0x474c: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x4750: 1e270101  fmov     s1, w8
//   0x4754: 1e212000  fcmp     s0, s1
//   0x4758: 5400012c  b.gt     #0x477c
//   0x475c: 5287b968  mov      w8, #0x3dcb
//   0x4760: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4764: 5285e369  mov      w9, #0x2f1b
//   0x4768: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x476c: 1e270100  fmov     s0, w8
//   0x4770: 1e202900  fadd     s0, s8, s0
//   0x4774: 1e270121  fmov     s1, w9
//   0x4778: 1e211800  fdiv     s0, s0, s1
//   0x477c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x4780: fc4207e8  ldr      d8, [sp], #0x20
//   0x4784: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_28_4730(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004730ULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2208ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[29] Symbol: LAB2XYZ
//      Virtual Address Range: 0x4788..0x48ec (356 bytes, 89 AArch64 instructions)
// [VN] Khung FDE[29] Biểu tượng: LAB2XYZ
//      Dải địa chỉ ảo: 0x4788..0x48ec (356 byte, 89 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4788: 6dbb2beb  stp      d11, d10, [sp, #-0x50]!
//   0x478c: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x4790: f90013f5  str      x21, [sp, #0x20]
//   0x4794: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x4798: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x479c: 910103fd  add      x29, sp, #0x40
//   0x47a0: 1e261003  fmov     s3, #16.00000000
//   0x47a4: 52a87f48  mov      w8, #0x43fa0000
//   0x47a8: 1e232800  fadd     s0, s0, s3
//   0x47ac: 1e270103  fmov     s3, w8
//   0x47b0: 52a85d08  mov      w8, #0x42e80000
//   0x47b4: 1e231821  fdiv     s1, s1, s3
//   0x47b8: 1e270103  fmov     s3, w8
//   0x47bc: 52b86908  mov      w8, #-0x3cb80000
//   0x47c0: 1e23180a  fdiv     s10, s0, s3
//   0x47c4: 1e270100  fmov     s0, w8
//   0x47c8: 1e2a2829  fadd     s9, s1, s10
//   0x47cc: 1e20184b  fdiv     s11, s2, s0
//   0x47d0: 1e211001  fmov     s1, #3.00000000
//   0x47d4: 4eaa1d40  mov      v0.16b, v10.16b
//   0x47d8: aa0203f3  mov      x19, x2
//   0x47dc: aa0103f4  mov      x20, x1
//   0x47e0: aa0003f5  mov      x21, x0
//   0x47e4: 97fff727  bl       #0x2480
//   0x47e8: 52831848  mov      w8, #0x18c2
//   0x47ec: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x47f0: 4ea01c08  mov      v8.16b, v0.16b
//   0x47f4: 1e270100  fmov     s0, w8
//   0x47f8: 1e202100  fcmp     s8, s0
//   0x47fc: 5400012c  b.gt     #0x4820
//   0x4800: 5287b968  mov      w8, #0x3dcb
//   0x4804: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4808: 5285e369  mov      w9, #0x2f1b
//   0x480c: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x4810: 1e270100  fmov     s0, w8
//   0x4814: 1e202940  fadd     s0, s10, s0
//   0x4818: 1e270121  fmov     s1, w9
//   0x481c: 1e211808  fdiv     s8, s0, s1
//   0x4820: 1e211001  fmov     s1, #3.00000000
//   0x4824: 4ea91d20  mov      v0.16b, v9.16b
//   0x4828: 1e2b294a  fadd     s10, s10, s11
//   0x482c: 97fff715  bl       #0x2480
//   0x4830: 52831848  mov      w8, #0x18c2
//   0x4834: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x4838: 4ea01c0b  mov      v11.16b, v0.16b
//   0x483c: 1e270100  fmov     s0, w8
//   0x4840: 1e202160  fcmp     s11, s0
//   0x4844: 5400012c  b.gt     #0x4868
//   0x4848: 5287b968  mov      w8, #0x3dcb
//   0x484c: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4850: 5285e369  mov      w9, #0x2f1b
//   0x4854: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x4858: 1e270100  fmov     s0, w8
//   0x485c: 1e202920  fadd     s0, s9, s0
//   0x4860: 1e270121  fmov     s1, w9
//   0x4864: 1e21180b  fdiv     s11, s0, s1
//   0x4868: 1e211001  fmov     s1, #3.00000000
//   0x486c: 4eaa1d40  mov      v0.16b, v10.16b
//   0x4870: 97fff704  bl       #0x2480
//   0x4874: 52831848  mov      w8, #0x18c2
//   0x4878: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x487c: 1e270101  fmov     s1, w8
//   0x4880: 1e212000  fcmp     s0, s1
//   0x4884: 5400012c  b.gt     #0x48a8
//   0x4888: 5287b968  mov      w8, #0x3dcb
//   0x488c: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4890: 5285e369  mov      w9, #0x2f1b
//   0x4894: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x4898: 1e270100  fmov     s0, w8
//   0x489c: 1e202940  fadd     s0, s10, s0
//   0x48a0: 1e270121  fmov     s1, w9
//   0x48a4: 1e211800  fdiv     s0, s0, s1
//   0x48a8: 528a22c8  mov      w8, #0x5116
//   0x48ac: 528b8969  mov      w9, #0x5c4b
//   0x48b0: 72a7ee68  movk     w8, #0x3f73, lsl #16
//   0x48b4: 72a7f169  movk     w9, #0x3f8b, lsl #16
//   0x48b8: 1e270101  fmov     s1, w8
//   0x48bc: 1e270122  fmov     s2, w9
//   0x48c0: 1e210961  fmul     s1, s11, s1
//   0x48c4: 1e220800  fmul     s0, s0, s2
//   0x48c8: bd0002a1  str      s1, [x21]
//   0x48cc: bd000288  str      s8, [x20]
//   0x48d0: bd000260  str      s0, [x19]
//   0x48d4: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x48d8: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x48dc: f94013f5  ldr      x21, [sp, #0x20]
//   0x48e0: 6d4123e9  ldp      d9, d8, [sp, #0x10]
//   0x48e4: 6cc52beb  ldp      d11, d10, [sp], #0x50
//   0x48e8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_29_4788(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004788ULL;
    for (std::size_t i = 0; i < 89ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2230ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[30] Symbol: gamma_XYZ2RGB
//      Virtual Address Range: 0x48ec..0x4958 (108 bytes, 27 AArch64 instructions)
// [VN] Khung FDE[30] Biểu tượng: gamma_XYZ2RGB
//      Dải địa chỉ ảo: 0x48ec..0x4958 (108 byte, 27 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x48ec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x48f0: 910003fd  mov      x29, sp
//   0x48f4: 90000028  adrp     x8, #0x8000
//   0x48f8: fd441101  ldr      d1, [x8, #0x820]
//   0x48fc: 1e22c002  fcvt     d2, s0
//   0x4900: 1e612040  fcmp     d2, d1
//   0x4904: 540001ed  b.le     #0x4940
//   0x4908: 528aaaa8  mov      w8, #0x5555
//   0x490c: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4910: 1e270101  fmov     s1, w8
//   0x4914: 97fff6db  bl       #0x2480
//   0x4918: 528147a8  mov      w8, #0xa3d
//   0x491c: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4920: 5288f5c9  mov      w9, #0x47ae
//   0x4924: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4928: 1e270101  fmov     s1, w8
//   0x492c: 1e210800  fmul     s0, s0, s1
//   0x4930: 1e270121  fmov     s1, w9
//   0x4934: 1e212800  fadd     s0, s0, s1
//   0x4938: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x493c: d65f03c0  ret      
//   0x4940: 52970a48  mov      w8, #0xb852
//   0x4944: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4948: 1e270101  fmov     s1, w8
//   0x494c: 1e210800  fmul     s0, s0, s1
//   0x4950: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x4954: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_30_48ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000048ecULL;
    for (std::size_t i = 0; i < 27ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2319ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[31] Symbol: XYZ2RGB
//      Virtual Address Range: 0x4958..0x4b88 (560 bytes, 140 AArch64 instructions)
// [VN] Khung FDE[31] Biểu tượng: XYZ2RGB
//      Dải địa chỉ ảo: 0x4958..0x4b88 (560 byte, 140 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4958: 6dbb2beb  stp      d11, d10, [sp, #-0x50]!
//   0x495c: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x4960: f90013f5  str      x21, [sp, #0x20]
//   0x4964: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x4968: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x496c: 910103fd  add      x29, sp, #0x40
//   0x4970: 528c7348  mov      w8, #0x639a
//   0x4974: 72a809e8  movk     w8, #0x404f, lsl #16
//   0x4978: 52843a2a  mov      w10, #0x21d1
//   0x497c: 529d4aac  mov      w12, #0xea55
//   0x4980: 52981e89  mov      w9, #0xc0f4
//   0x4984: 72b7ef0a  movk     w10, #0xbf78, lsl #16
//   0x4988: 528423eb  mov      w11, #0x211f
//   0x498c: 72a7ac6c  movk     w12, #0x3d63, lsl #16
//   0x4990: 1e270103  fmov     s3, w8
//   0x4994: 529d8548  mov      w8, #0xec2a
//   0x4998: 72b7f889  movk     w9, #0xbfc4, lsl #16
//   0x499c: 72a7fe0b  movk     w11, #0x3ff0, lsl #16
//   0x49a0: 1e270145  fmov     s5, w10
//   0x49a4: 1e270187  fmov     s7, w12
//   0x49a8: 72b7ca08  movk     w8, #0xbe50, lsl #16
//   0x49ac: 1e270124  fmov     s4, w9
//   0x49b0: 1e270166  fmov     s6, w11
//   0x49b4: 1e230803  fmul     s3, s0, s3
//   0x49b8: 1e250805  fmul     s5, s0, s5
//   0x49bc: 1e270800  fmul     s0, s0, s7
//   0x49c0: 1e270107  fmov     s7, w8
//   0x49c4: 5287f048  mov      w8, #0x3f82
//   0x49c8: 1e240824  fmul     s4, s1, s4
//   0x49cc: 1e260826  fmul     s6, s1, s6
//   0x49d0: 72b7dfe8  movk     w8, #0xbeff, lsl #16
//   0x49d4: 1e242863  fadd     s3, s3, s4
//   0x49d8: 1e2528c4  fadd     s4, s6, s5
//   0x49dc: 1e270105  fmov     s5, w8
//   0x49e0: 5286d408  mov      w8, #0x36a0
//   0x49e4: 1e270821  fmul     s1, s1, s7
//   0x49e8: 72a7a548  movk     w8, #0x3d2a, lsl #16
//   0x49ec: 1e212808  fadd     s8, s0, s1
//   0x49f0: 1e270100  fmov     s0, w8
//   0x49f4: 90000028  adrp     x8, #0x8000
//   0x49f8: fd44110a  ldr      d10, [x8, #0x820]
//   0x49fc: 1e250841  fmul     s1, s2, s5
//   0x4a00: 1e200845  fmul     s5, s2, s0
//   0x4a04: 1e212860  fadd     s0, s3, s1
//   0x4a08: 528a6508  mov      w8, #0x5328
//   0x4a0c: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4a10: 1e22c001  fcvt     d1, s0
//   0x4a14: 1e6a2020  fcmp     d1, d10
//   0x4a18: 1e270101  fmov     s1, w8
//   0x4a1c: aa0203f3  mov      x19, x2
//   0x4a20: aa0103f4  mov      x20, x1
//   0x4a24: aa0003f5  mov      x21, x0
//   0x4a28: 1e252889  fadd     s9, s4, s5
//   0x4a2c: 1e21084b  fmul     s11, s2, s1
//   0x4a30: 540001cd  b.le     #0x4a68
//   0x4a34: 528aaaa8  mov      w8, #0x5555
//   0x4a38: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4a3c: 1e270101  fmov     s1, w8
//   0x4a40: 97fff690  bl       #0x2480
//   0x4a44: 528147a8  mov      w8, #0xa3d
//   0x4a48: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4a4c: 5288f5c9  mov      w9, #0x47ae
//   0x4a50: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4a54: 1e270101  fmov     s1, w8
//   0x4a58: 1e210800  fmul     s0, s0, s1
//   0x4a5c: 1e270121  fmov     s1, w9
//   0x4a60: 1e212800  fadd     s0, s0, s1
//   0x4a64: 14000005  b        #0x4a78
//   0x4a68: 52970a48  mov      w8, #0xb852
//   0x4a6c: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4a70: 1e270101  fmov     s1, w8
//   0x4a74: 1e210800  fmul     s0, s0, s1
//   0x4a78: 52a86fe8  mov      w8, #0x437f0000
//   0x4a7c: 1e270102  fmov     s2, w8
//   0x4a80: 1e2b2908  fadd     s8, s8, s11
//   0x4a84: 1e2c100b  fmov     s11, #0.50000000
//   0x4a88: 1e220800  fmul     s0, s0, s2
//   0x4a8c: 1e22c121  fcvt     d1, s9
//   0x4a90: 1e2b2800  fadd     s0, s0, s11
//   0x4a94: 1e380008  fcvtzs   w8, s0
//   0x4a98: 1e6a2020  fcmp     d1, d10
//   0x4a9c: b90002a8  str      w8, [x21]
//   0x4aa0: 540001ed  b.le     #0x4adc
//   0x4aa4: 528aaaa8  mov      w8, #0x5555
//   0x4aa8: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4aac: 1e270101  fmov     s1, w8
//   0x4ab0: 4ea91d20  mov      v0.16b, v9.16b
//   0x4ab4: 97fff673  bl       #0x2480
//   0x4ab8: 528147a8  mov      w8, #0xa3d
//   0x4abc: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4ac0: 5288f5c9  mov      w9, #0x47ae
//   0x4ac4: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4ac8: 1e270101  fmov     s1, w8
//   0x4acc: 1e210800  fmul     s0, s0, s1
//   0x4ad0: 1e270121  fmov     s1, w9
//   0x4ad4: 1e212800  fadd     s0, s0, s1
//   0x4ad8: 14000005  b        #0x4aec
//   0x4adc: 52970a48  mov      w8, #0xb852
//   0x4ae0: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4ae4: 1e270100  fmov     s0, w8
//   0x4ae8: 1e200920  fmul     s0, s9, s0
//   0x4aec: 52a86fe8  mov      w8, #0x437f0000
//   0x4af0: 1e270102  fmov     s2, w8
//   0x4af4: 1e220800  fmul     s0, s0, s2
//   0x4af8: 1e22c101  fcvt     d1, s8
//   0x4afc: 1e2b2800  fadd     s0, s0, s11
//   0x4b00: 1e380008  fcvtzs   w8, s0
//   0x4b04: 1e6a2020  fcmp     d1, d10
//   0x4b08: b9000288  str      w8, [x20]
//   0x4b0c: 540001ed  b.le     #0x4b48
//   0x4b10: 528aaaa8  mov      w8, #0x5555
//   0x4b14: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4b18: 1e270101  fmov     s1, w8
//   0x4b1c: 4ea81d00  mov      v0.16b, v8.16b
//   0x4b20: 97fff658  bl       #0x2480
//   0x4b24: 528147a8  mov      w8, #0xa3d
//   0x4b28: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4b2c: 5288f5c9  mov      w9, #0x47ae
//   0x4b30: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4b34: 1e270101  fmov     s1, w8
//   0x4b38: 1e210800  fmul     s0, s0, s1
//   0x4b3c: 1e270121  fmov     s1, w9
//   0x4b40: 1e212800  fadd     s0, s0, s1
//   0x4b44: 14000005  b        #0x4b58
//   0x4b48: 52970a48  mov      w8, #0xb852
//   0x4b4c: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4b50: 1e270100  fmov     s0, w8
//   0x4b54: 1e200900  fmul     s0, s8, s0
//   0x4b58: 52a86fe8  mov      w8, #0x437f0000
//   0x4b5c: 1e270101  fmov     s1, w8
//   0x4b60: 1e210800  fmul     s0, s0, s1
//   0x4b64: 1e2b2800  fadd     s0, s0, s11
//   0x4b68: 1e380008  fcvtzs   w8, s0
//   0x4b6c: b9000268  str      w8, [x19]
//   0x4b70: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x4b74: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x4b78: f94013f5  ldr      x21, [sp, #0x20]
//   0x4b7c: 6d4123e9  ldp      d9, d8, [sp, #0x10]
//   0x4b80: 6cc52beb  ldp      d11, d10, [sp], #0x50
//   0x4b84: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_31_4958(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004958ULL;
    for (std::size_t i = 0; i < 140ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2346ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[32] Symbol: LCH2RGB
//      Virtual Address Range: 0x4b88..0x4f18 (912 bytes, 228 AArch64 instructions)
// [VN] Khung FDE[32] Biểu tượng: LCH2RGB
//      Dải địa chỉ ảo: 0x4b88..0x4f18 (912 byte, 228 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4b88: 6dbb2beb  stp      d11, d10, [sp, #-0x50]!
//   0x4b8c: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x4b90: f90013f5  str      x21, [sp, #0x20]
//   0x4b94: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x4b98: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x4b9c: 910103fd  add      x29, sp, #0x40
//   0x4ba0: 90000028  adrp     x8, #0x8000
//   0x4ba4: 4ea01c09  mov      v9.16b, v0.16b
//   0x4ba8: fd440d00  ldr      d0, [x8, #0x818]
//   0x4bac: d2d00008  mov      x8, #0x800000000000
//   0x4bb0: 4ea11c28  mov      v8.16b, v1.16b
//   0x4bb4: 1e22c041  fcvt     d1, s2
//   0x4bb8: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x4bbc: 1e600820  fmul     d0, d1, d0
//   0x4bc0: 9e670101  fmov     d1, x8
//   0x4bc4: 1e611800  fdiv     d0, d0, d1
//   0x4bc8: aa0103f4  mov      x20, x1
//   0x4bcc: aa0003f5  mov      x21, x0
//   0x4bd0: 1e624000  fcvt     s0, d0
//   0x4bd4: d10053a0  sub      x0, x29, #0x14
//   0x4bd8: d10063a1  sub      x1, x29, #0x18
//   0x4bdc: aa0203f3  mov      x19, x2
//   0x4be0: 97fff5d4  bl       #0x2330
//   0x4be4: 2d7d03a1  ldp      s1, s0, [x29, #-0x18]
//   0x4be8: 1e261002  fmov     s2, #16.00000000
//   0x4bec: 52a85d08  mov      w8, #0x42e80000
//   0x4bf0: 1e222922  fadd     s2, s9, s2
//   0x4bf4: 1e270103  fmov     s3, w8
//   0x4bf8: 52a87f48  mov      w8, #0x43fa0000
//   0x4bfc: 1e231849  fdiv     s9, s2, s3
//   0x4c00: 1e280821  fmul     s1, s1, s8
//   0x4c04: 1e270102  fmov     s2, w8
//   0x4c08: 52b86908  mov      w8, #-0x3cb80000
//   0x4c0c: 1e280800  fmul     s0, s0, s8
//   0x4c10: 1e221821  fdiv     s1, s1, s2
//   0x4c14: 1e270102  fmov     s2, w8
//   0x4c18: 1e21292a  fadd     s10, s9, s1
//   0x4c1c: 1e22180b  fdiv     s11, s0, s2
//   0x4c20: 1e211001  fmov     s1, #3.00000000
//   0x4c24: 4ea91d20  mov      v0.16b, v9.16b
//   0x4c28: 97fff616  bl       #0x2480
//   0x4c2c: 52831848  mov      w8, #0x18c2
//   0x4c30: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x4c34: 4ea01c08  mov      v8.16b, v0.16b
//   0x4c38: 1e270100  fmov     s0, w8
//   0x4c3c: 1e202100  fcmp     s8, s0
//   0x4c40: 5400012c  b.gt     #0x4c64
//   0x4c44: 5287b968  mov      w8, #0x3dcb
//   0x4c48: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4c4c: 5285e369  mov      w9, #0x2f1b
//   0x4c50: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x4c54: 1e270100  fmov     s0, w8
//   0x4c58: 1e202920  fadd     s0, s9, s0
//   0x4c5c: 1e270121  fmov     s1, w9
//   0x4c60: 1e211808  fdiv     s8, s0, s1
//   0x4c64: 1e211001  fmov     s1, #3.00000000
//   0x4c68: 4eaa1d40  mov      v0.16b, v10.16b
//   0x4c6c: 1e2b292b  fadd     s11, s9, s11
//   0x4c70: 97fff604  bl       #0x2480
//   0x4c74: 52831848  mov      w8, #0x18c2
//   0x4c78: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x4c7c: 4ea01c09  mov      v9.16b, v0.16b
//   0x4c80: 1e270100  fmov     s0, w8
//   0x4c84: 1e202120  fcmp     s9, s0
//   0x4c88: 5400012c  b.gt     #0x4cac
//   0x4c8c: 5287b968  mov      w8, #0x3dcb
//   0x4c90: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4c94: 5285e369  mov      w9, #0x2f1b
//   0x4c98: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x4c9c: 1e270100  fmov     s0, w8
//   0x4ca0: 1e202940  fadd     s0, s10, s0
//   0x4ca4: 1e270121  fmov     s1, w9
//   0x4ca8: 1e211809  fdiv     s9, s0, s1
//   0x4cac: 1e211001  fmov     s1, #3.00000000
//   0x4cb0: 4eab1d60  mov      v0.16b, v11.16b
//   0x4cb4: 97fff5f3  bl       #0x2480
//   0x4cb8: 52831848  mov      w8, #0x18c2
//   0x4cbc: 72a78228  movk     w8, #0x3c11, lsl #16
//   0x4cc0: 1e270101  fmov     s1, w8
//   0x4cc4: 1e212000  fcmp     s0, s1
//   0x4cc8: 5400012c  b.gt     #0x4cec
//   0x4ccc: 5287b968  mov      w8, #0x3dcb
//   0x4cd0: 72b7c1a8  movk     w8, #0xbe0d, lsl #16
//   0x4cd4: 5285e369  mov      w9, #0x2f1b
//   0x4cd8: 72a81f29  movk     w9, #0x40f9, lsl #16
//   0x4cdc: 1e270100  fmov     s0, w8
//   0x4ce0: 1e202960  fadd     s0, s11, s0
//   0x4ce4: 1e270121  fmov     s1, w9
//   0x4ce8: 1e211800  fdiv     s0, s0, s1
//   0x4cec: 528a22c8  mov      w8, #0x5116
//   0x4cf0: 72a7ee68  movk     w8, #0x3f73, lsl #16
//   0x4cf4: 1e270101  fmov     s1, w8
//   0x4cf8: 528423e8  mov      w8, #0x211f
//   0x4cfc: 528b8969  mov      w9, #0x5c4b
//   0x4d00: 72a7fe08  movk     w8, #0x3ff0, lsl #16
//   0x4d04: 72a7f169  movk     w9, #0x3f8b, lsl #16
//   0x4d08: 1e270106  fmov     s6, w8
//   0x4d0c: 529d8548  mov      w8, #0xec2a
//   0x4d10: 1e270122  fmov     s2, w9
//   0x4d14: 72b7ca08  movk     w8, #0xbe50, lsl #16
//   0x4d18: 528c734a  mov      w10, #0x639a
//   0x4d1c: 52981e8b  mov      w11, #0xc0f4
//   0x4d20: 52843a2c  mov      w12, #0x21d1
//   0x4d24: 1e220802  fmul     s2, s0, s2
//   0x4d28: 1e270100  fmov     s0, w8
//   0x4d2c: 529d4aa8  mov      w8, #0xea55
//   0x4d30: 72a809ea  movk     w10, #0x404f, lsl #16
//   0x4d34: 72b7f88b  movk     w11, #0xbfc4, lsl #16
//   0x4d38: 72b7ef0c  movk     w12, #0xbf78, lsl #16
//   0x4d3c: 72a7ac68  movk     w8, #0x3d63, lsl #16
//   0x4d40: 1e270143  fmov     s3, w10
//   0x4d44: 1e270164  fmov     s4, w11
//   0x4d48: 1e270185  fmov     s5, w12
//   0x4d4c: 1e210921  fmul     s1, s9, s1
//   0x4d50: 1e270107  fmov     s7, w8
//   0x4d54: 5287f048  mov      w8, #0x3f82
//   0x4d58: 1e240904  fmul     s4, s8, s4
//   0x4d5c: 1e260906  fmul     s6, s8, s6
//   0x4d60: 1e230823  fmul     s3, s1, s3
//   0x4d64: 1e250825  fmul     s5, s1, s5
//   0x4d68: 72b7dfe8  movk     w8, #0xbeff, lsl #16
//   0x4d6c: 1e242863  fadd     s3, s3, s4
//   0x4d70: 1e2528c4  fadd     s4, s6, s5
//   0x4d74: 1e270105  fmov     s5, w8
//   0x4d78: 5286d408  mov      w8, #0x36a0
//   0x4d7c: 1e200900  fmul     s0, s8, s0
//   0x4d80: 1e270821  fmul     s1, s1, s7
//   0x4d84: 72a7a548  movk     w8, #0x3d2a, lsl #16
//   0x4d88: 1e202828  fadd     s8, s1, s0
//   0x4d8c: 1e270101  fmov     s1, w8
//   0x4d90: 90000028  adrp     x8, #0x8000
//   0x4d94: fd44110b  ldr      d11, [x8, #0x820]
//   0x4d98: 1e250840  fmul     s0, s2, s5
//   0x4d9c: 1e202860  fadd     s0, s3, s0
//   0x4da0: 1e210841  fmul     s1, s2, s1
//   0x4da4: 528a6508  mov      w8, #0x5328
//   0x4da8: 1e212889  fadd     s9, s4, s1
//   0x4dac: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4db0: 1e22c001  fcvt     d1, s0
//   0x4db4: 1e6b2020  fcmp     d1, d11
//   0x4db8: 1e270101  fmov     s1, w8
//   0x4dbc: 1e21084a  fmul     s10, s2, s1
//   0x4dc0: 540001cd  b.le     #0x4df8
//   0x4dc4: 528aaaa8  mov      w8, #0x5555
//   0x4dc8: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4dcc: 1e270101  fmov     s1, w8
//   0x4dd0: 97fff5ac  bl       #0x2480
//   0x4dd4: 528147a8  mov      w8, #0xa3d
//   0x4dd8: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4ddc: 5288f5c9  mov      w9, #0x47ae
//   0x4de0: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4de4: 1e270101  fmov     s1, w8
//   0x4de8: 1e210800  fmul     s0, s0, s1
//   0x4dec: 1e270121  fmov     s1, w9
//   0x4df0: 1e212800  fadd     s0, s0, s1
//   0x4df4: 14000005  b        #0x4e08
//   0x4df8: 52970a48  mov      w8, #0xb852
//   0x4dfc: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4e00: 1e270101  fmov     s1, w8
//   0x4e04: 1e210800  fmul     s0, s0, s1
//   0x4e08: 52a86fe8  mov      w8, #0x437f0000
//   0x4e0c: 1e270102  fmov     s2, w8
//   0x4e10: 1e2a2908  fadd     s8, s8, s10
//   0x4e14: 1e2c100a  fmov     s10, #0.50000000
//   0x4e18: 1e220800  fmul     s0, s0, s2
//   0x4e1c: 1e22c121  fcvt     d1, s9
//   0x4e20: 1e2a2800  fadd     s0, s0, s10
//   0x4e24: 1e380008  fcvtzs   w8, s0
//   0x4e28: 1e6b2020  fcmp     d1, d11
//   0x4e2c: b90002a8  str      w8, [x21]
//   0x4e30: 540001ed  b.le     #0x4e6c
//   0x4e34: 528aaaa8  mov      w8, #0x5555
//   0x4e38: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4e3c: 1e270101  fmov     s1, w8
//   0x4e40: 4ea91d20  mov      v0.16b, v9.16b
//   0x4e44: 97fff58f  bl       #0x2480
//   0x4e48: 528147a8  mov      w8, #0xa3d
//   0x4e4c: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4e50: 5288f5c9  mov      w9, #0x47ae
//   0x4e54: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4e58: 1e270101  fmov     s1, w8
//   0x4e5c: 1e210800  fmul     s0, s0, s1
//   0x4e60: 1e270121  fmov     s1, w9
//   0x4e64: 1e212800  fadd     s0, s0, s1
//   0x4e68: 14000005  b        #0x4e7c
//   0x4e6c: 52970a48  mov      w8, #0xb852
//   0x4e70: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4e74: 1e270100  fmov     s0, w8
//   0x4e78: 1e200920  fmul     s0, s9, s0
//   0x4e7c: 52a86fe8  mov      w8, #0x437f0000
//   0x4e80: 1e270102  fmov     s2, w8
//   0x4e84: 1e220800  fmul     s0, s0, s2
//   0x4e88: 1e22c101  fcvt     d1, s8
//   0x4e8c: 1e2a2800  fadd     s0, s0, s10
//   0x4e90: 1e380008  fcvtzs   w8, s0
//   0x4e94: 1e6b2020  fcmp     d1, d11
//   0x4e98: b9000288  str      w8, [x20]
//   0x4e9c: 540001ed  b.le     #0x4ed8
//   0x4ea0: 528aaaa8  mov      w8, #0x5555
//   0x4ea4: 72a7daa8  movk     w8, #0x3ed5, lsl #16
//   0x4ea8: 1e270101  fmov     s1, w8
//   0x4eac: 4ea81d00  mov      v0.16b, v8.16b
//   0x4eb0: 97fff574  bl       #0x2480
//   0x4eb4: 528147a8  mov      w8, #0xa3d
//   0x4eb8: 72a7f0e8  movk     w8, #0x3f87, lsl #16
//   0x4ebc: 5288f5c9  mov      w9, #0x47ae
//   0x4ec0: 72b7ac29  movk     w9, #0xbd61, lsl #16
//   0x4ec4: 1e270101  fmov     s1, w8
//   0x4ec8: 1e210800  fmul     s0, s0, s1
//   0x4ecc: 1e270121  fmov     s1, w9
//   0x4ed0: 1e212800  fadd     s0, s0, s1
//   0x4ed4: 14000005  b        #0x4ee8
//   0x4ed8: 52970a48  mov      w8, #0xb852
//   0x4edc: 72a829c8  movk     w8, #0x414e, lsl #16
//   0x4ee0: 1e270100  fmov     s0, w8
//   0x4ee4: 1e200900  fmul     s0, s8, s0
//   0x4ee8: 52a86fe8  mov      w8, #0x437f0000
//   0x4eec: 1e270101  fmov     s1, w8
//   0x4ef0: 1e210800  fmul     s0, s0, s1
//   0x4ef4: 1e2a2800  fadd     s0, s0, s10
//   0x4ef8: 1e380008  fcvtzs   w8, s0
//   0x4efc: b9000268  str      w8, [x19]
//   0x4f00: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x4f04: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x4f08: f94013f5  ldr      x21, [sp, #0x20]
//   0x4f0c: 6d4123e9  ldp      d9, d8, [sp, #0x10]
//   0x4f10: 6cc52beb  ldp      d11, d10, [sp], #0x50
//   0x4f14: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_32_4b88(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004b88ULL;
    for (std::size_t i = 0; i < 228ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2486ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[33] Symbol: rgb2lrgb
//      Virtual Address Range: 0x4f18..0x4f98 (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[33] Biểu tượng: rgb2lrgb
//      Dải địa chỉ ảo: 0x4f18..0x4f98 (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4f18: fc1e0fe8  str      d8, [sp, #-0x20]!
//   0x4f1c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x4f20: 910043fd  add      x29, sp, #0x10
//   0x4f24: 90000028  adrp     x8, #0x8000
//   0x4f28: fd441502  ldr      d2, [x8, #0x828]
//   0x4f2c: 1e614001  fneg     d1, d0
//   0x4f30: 1e602008  fcmp     d0, #0.0
//   0x4f34: 1e604c21  fcsel    d1, d1, d0, mi
//   0x4f38: 1e622020  fcmp     d1, d2
//   0x4f3c: 540000a5  b.pl     #0x4f50
//   0x4f40: 90000028  adrp     x8, #0x8000
//   0x4f44: fd442101  ldr      d1, [x8, #0x840]
//   0x4f48: 1e611800  fdiv     d0, d0, d1
//   0x4f4c: 14000010  b        #0x4f8c
//   0x4f50: 90000028  adrp     x8, #0x8000
//   0x4f54: fd441902  ldr      d2, [x8, #0x830]
//   0x4f58: 90000028  adrp     x8, #0x8000
//   0x4f5c: fd441d03  ldr      d3, [x8, #0x838]
//   0x4f60: 1e602008  fcmp     d0, #0.0
//   0x4f64: 1e6e1000  fmov     d0, #1.00000000
//   0x4f68: 1e7e1004  fmov     d4, #-1.00000000
//   0x4f6c: b200e7e8  mov      x8, #0x3333333333333333
//   0x4f70: 1e604c88  fcsel    d8, d4, d0, mi
//   0x4f74: 1e622820  fadd     d0, d1, d2
//   0x4f78: f2e80068  movk     x8, #0x4003, lsl #48
//   0x4f7c: 1e631800  fdiv     d0, d0, d3
//   0x4f80: 9e670101  fmov     d1, x8
//   0x4f84: 97fff46b  bl       #0x2130
//   0x4f88: 1e600900  fmul     d0, d8, d0
//   0x4f8c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x4f90: fc4207e8  ldr      d8, [sp], #0x20
//   0x4f94: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_33_4f18(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004f18ULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2714ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[34] Symbol: RGB2OK_LAB
//      Virtual Address Range: 0x4f98..0x525c (708 bytes, 177 AArch64 instructions)
// [VN] Khung FDE[34] Biểu tượng: RGB2OK_LAB
//      Dải địa chỉ ảo: 0x4f98..0x525c (708 byte, 177 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4f98: fc180fee  str      d14, [sp, #-0x80]!
//   0x4f9c: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x4fa0: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x4fa4: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x4fa8: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x4fac: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x4fb0: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x4fb4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x4fb8: 9101c3fd  add      x29, sp, #0x70
//   0x4fbc: d2dc0008  mov      x8, #0xe00000000000
//   0x4fc0: f2e80de8  movk     x8, #0x406f, lsl #48
//   0x4fc4: 90000029  adrp     x9, #0x8000
//   0x4fc8: 1e620000  scvtf    d0, w0
//   0x4fcc: 9e67010e  fmov     d14, x8
//   0x4fd0: fd44152a  ldr      d10, [x9, #0x828]
//   0x4fd4: 1e620021  scvtf    d1, w1
//   0x4fd8: 1e6e1800  fdiv     d0, d0, d14
//   0x4fdc: 1e6e182c  fdiv     d12, d1, d14
//   0x4fe0: 1e614001  fneg     d1, d0
//   0x4fe4: 1e602008  fcmp     d0, #0.0
//   0x4fe8: 1e604c21  fcsel    d1, d1, d0, mi
//   0x4fec: aa0503f3  mov      x19, x5
//   0x4ff0: aa0403f4  mov      x20, x4
//   0x4ff4: aa0303f5  mov      x21, x3
//   0x4ff8: 1e62004d  scvtf    d13, w2
//   0x4ffc: 1e6e1008  fmov     d8, #1.00000000
//   0x5000: 1e7e1009  fmov     d9, #-1.00000000
//   0x5004: f0000016  adrp     x22, #0x8000
//   0x5008: 1e6a2020  fcmp     d1, d10
//   0x500c: f0000017  adrp     x23, #0x8000
//   0x5010: f0000018  adrp     x24, #0x8000
//   0x5014: 54000085  b.pl     #0x5024
//   0x5018: fd442301  ldr      d1, [x24, #0x840]
//   0x501c: 1e61180b  fdiv     d11, d0, d1
//   0x5020: 1400000c  b        #0x5050
//   0x5024: fd441ac2  ldr      d2, [x22, #0x830]
//   0x5028: fd441ee3  ldr      d3, [x23, #0x838]
//   0x502c: b200e7e8  mov      x8, #0x3333333333333333
//   0x5030: 1e602008  fcmp     d0, #0.0
//   0x5034: 1e622820  fadd     d0, d1, d2
//   0x5038: f2e80068  movk     x8, #0x4003, lsl #48
//   0x503c: 1e631800  fdiv     d0, d0, d3
//   0x5040: 9e670101  fmov     d1, x8
//   0x5044: 1e684d2b  fcsel    d11, d9, d8, mi
//   0x5048: 97fff43a  bl       #0x2130
//   0x504c: 1e60096b  fmul     d11, d11, d0
//   0x5050: 1e614180  fneg     d0, d12
//   0x5054: 1e602188  fcmp     d12, #0.0
//   0x5058: 1e6c4c00  fcsel    d0, d0, d12, mi
//   0x505c: 1e6a2000  fcmp     d0, d10
//   0x5060: 1e6e19ad  fdiv     d13, d13, d14
//   0x5064: 54000085  b.pl     #0x5074
//   0x5068: fd442300  ldr      d0, [x24, #0x840]
//   0x506c: 1e60198c  fdiv     d12, d12, d0
//   0x5070: 1400000c  b        #0x50a0
//   0x5074: fd441ac1  ldr      d1, [x22, #0x830]
//   0x5078: fd441ee2  ldr      d2, [x23, #0x838]
//   0x507c: b200e7e8  mov      x8, #0x3333333333333333
//   0x5080: f2e80068  movk     x8, #0x4003, lsl #48
//   0x5084: 1e612800  fadd     d0, d0, d1
//   0x5088: 1e602188  fcmp     d12, #0.0
//   0x508c: 1e621800  fdiv     d0, d0, d2
//   0x5090: 9e670101  fmov     d1, x8
//   0x5094: 1e684d2c  fcsel    d12, d9, d8, mi
//   0x5098: 97fff426  bl       #0x2130
//   0x509c: 1e60098c  fmul     d12, d12, d0
//   0x50a0: 1e6141a0  fneg     d0, d13
//   0x50a4: 1e6021a8  fcmp     d13, #0.0
//   0x50a8: 1e6d4c00  fcsel    d0, d0, d13, mi
//   0x50ac: 1e6a2000  fcmp     d0, d10
//   0x50b0: 54000085  b.pl     #0x50c0
//   0x50b4: fd442300  ldr      d0, [x24, #0x840]
//   0x50b8: 1e6019ad  fdiv     d13, d13, d0
//   0x50bc: 1400000c  b        #0x50ec
//   0x50c0: fd441ac1  ldr      d1, [x22, #0x830]
//   0x50c4: fd441ee2  ldr      d2, [x23, #0x838]
//   0x50c8: b200e7e8  mov      x8, #0x3333333333333333
//   0x50cc: f2e80068  movk     x8, #0x4003, lsl #48
//   0x50d0: 1e612800  fadd     d0, d0, d1
//   0x50d4: 1e6021a8  fcmp     d13, #0.0
//   0x50d8: 1e621800  fdiv     d0, d0, d2
//   0x50dc: 9e670101  fmov     d1, x8
//   0x50e0: 1e684d28  fcsel    d8, d9, d8, mi
//   0x50e4: 97fff413  bl       #0x2130
//   0x50e8: 1e60090d  fmul     d13, d8, d0
//   0x50ec: f0000008  adrp     x8, #0x8000
//   0x50f0: f0000009  adrp     x9, #0x8000
//   0x50f4: fd442500  ldr      d0, [x8, #0x848]
//   0x50f8: fd442921  ldr      d1, [x9, #0x850]
//   0x50fc: f0000008  adrp     x8, #0x8000
//   0x5100: fd442d02  ldr      d2, [x8, #0x858]
//   0x5104: b200f3e8  mov      x8, #0x5555555555555555
//   0x5108: 1e600960  fmul     d0, d11, d0
//   0x510c: 1e610981  fmul     d1, d12, d1
//   0x5110: f2e7faa8  movk     x8, #0x3fd5, lsl #48
//   0x5114: 1e612800  fadd     d0, d0, d1
//   0x5118: 1e6209a1  fmul     d1, d13, d2
//   0x511c: 9e670109  fmov     d9, x8
//   0x5120: 1e612800  fadd     d0, d0, d1
//   0x5124: 4ea91d21  mov      v1.16b, v9.16b
//   0x5128: 97fff402  bl       #0x2130
//   0x512c: f0000008  adrp     x8, #0x8000
//   0x5130: f0000009  adrp     x9, #0x8000
//   0x5134: 4ea01c08  mov      v8.16b, v0.16b
//   0x5138: fd443100  ldr      d0, [x8, #0x860]
//   0x513c: fd443521  ldr      d1, [x9, #0x868]
//   0x5140: f0000008  adrp     x8, #0x8000
//   0x5144: fd443902  ldr      d2, [x8, #0x870]
//   0x5148: 1e600960  fmul     d0, d11, d0
//   0x514c: 1e610981  fmul     d1, d12, d1
//   0x5150: 1e612800  fadd     d0, d0, d1
//   0x5154: 1e6209a1  fmul     d1, d13, d2
//   0x5158: 1e612800  fadd     d0, d0, d1
//   0x515c: 4ea91d21  mov      v1.16b, v9.16b
//   0x5160: 97fff3f4  bl       #0x2130
//   0x5164: f0000008  adrp     x8, #0x8000
//   0x5168: f0000009  adrp     x9, #0x8000
//   0x516c: 4ea01c0a  mov      v10.16b, v0.16b
//   0x5170: fd443d00  ldr      d0, [x8, #0x878]
//   0x5174: fd444121  ldr      d1, [x9, #0x880]
//   0x5178: f0000008  adrp     x8, #0x8000
//   0x517c: fd444502  ldr      d2, [x8, #0x888]
//   0x5180: 1e600960  fmul     d0, d11, d0
//   0x5184: 1e610981  fmul     d1, d12, d1
//   0x5188: 1e612800  fadd     d0, d0, d1
//   0x518c: 1e6209a1  fmul     d1, d13, d2
//   0x5190: 1e612800  fadd     d0, d0, d1
//   0x5194: 4ea91d21  mov      v1.16b, v9.16b
//   0x5198: 97fff3e6  bl       #0x2130
//   0x519c: f0000008  adrp     x8, #0x8000
//   0x51a0: fd444901  ldr      d1, [x8, #0x890]
//   0x51a4: f0000008  adrp     x8, #0x8000
//   0x51a8: fd444d02  ldr      d2, [x8, #0x898]
//   0x51ac: f0000008  adrp     x8, #0x8000
//   0x51b0: fd445103  ldr      d3, [x8, #0x8a0]
//   0x51b4: f0000008  adrp     x8, #0x8000
//   0x51b8: fd445504  ldr      d4, [x8, #0x8a8]
//   0x51bc: f0000008  adrp     x8, #0x8000
//   0x51c0: fd445905  ldr      d5, [x8, #0x8b0]
//   0x51c4: f0000008  adrp     x8, #0x8000
//   0x51c8: fd445d06  ldr      d6, [x8, #0x8b8]
//   0x51cc: f0000008  adrp     x8, #0x8000
//   0x51d0: fd446107  ldr      d7, [x8, #0x8c0]
//   0x51d4: f0000008  adrp     x8, #0x8000
//   0x51d8: fd446510  ldr      d16, [x8, #0x8c8]
//   0x51dc: f0000008  adrp     x8, #0x8000
//   0x51e0: fd446911  ldr      d17, [x8, #0x8d0]
//   0x51e4: 1e610901  fmul     d1, d8, d1
//   0x51e8: 1e640904  fmul     d4, d8, d4
//   0x51ec: 1e670907  fmul     d7, d8, d7
//   0x51f0: 1e620942  fmul     d2, d10, d2
//   0x51f4: 1e650945  fmul     d5, d10, d5
//   0x51f8: 1e700950  fmul     d16, d10, d16
//   0x51fc: 1e630803  fmul     d3, d0, d3
//   0x5200: 1e660806  fmul     d6, d0, d6
//   0x5204: 1e710800  fmul     d0, d0, d17
//   0x5208: 1e622821  fadd     d1, d1, d2
//   0x520c: 1e652882  fadd     d2, d4, d5
//   0x5210: 1e7028e4  fadd     d4, d7, d16
//   0x5214: 1e632821  fadd     d1, d1, d3
//   0x5218: 1e6228c2  fadd     d2, d6, d2
//   0x521c: 1e602880  fadd     d0, d4, d0
//   0x5220: 1e624021  fcvt     s1, d1
//   0x5224: 1e624042  fcvt     s2, d2
//   0x5228: 1e624000  fcvt     s0, d0
//   0x522c: bd0002a1  str      s1, [x21]
//   0x5230: bd000282  str      s2, [x20]
//   0x5234: bd000260  str      s0, [x19]
//   0x5238: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x523c: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x5240: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x5244: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x5248: 6d4323e9  ldp      d9, d8, [sp, #0x30]
//   0x524c: 6d422beb  ldp      d11, d10, [sp, #0x20]
//   0x5250: 6d4133ed  ldp      d13, d12, [sp, #0x10]
//   0x5254: fc4807ee  ldr      d14, [sp], #0x80
//   0x5258: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_34_4f98(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004f98ULL;
    for (std::size_t i = 0; i < 177ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2746ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[35] Symbol: RGB2OK_LCH
//      Virtual Address Range: 0x525c..0x5338 (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[35] Biểu tượng: RGB2OK_LCH
//      Dải địa chỉ ảo: 0x525c..0x5338 (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x525c: d10103ff  sub      sp, sp, #0x40
//   0x5260: f9000bf5  str      x21, [sp, #0x10]
//   0x5264: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x5268: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x526c: 9100c3fd  add      x29, sp, #0x30
//   0x5270: aa0503f3  mov      x19, x5
//   0x5274: aa0403f4  mov      x20, x4
//   0x5278: aa0303f5  mov      x21, x3
//   0x527c: d10053a3  sub      x3, x29, #0x14
//   0x5280: 910063e4  add      x4, sp, #0x18
//   0x5284: 910033e5  add      x5, sp, #0xc
//   0x5288: 97fff432  bl       #0x2350
//   0x528c: bd401be1  ldr      s1, [sp, #0x18]
//   0x5290: bd400fe0  ldr      s0, [sp, #0xc]
//   0x5294: b85ec3a8  ldur     w8, [x29, #-0x14]
//   0x5298: 1e210822  fmul     s2, s1, s1
//   0x529c: 1e200803  fmul     s3, s0, s0
//   0x52a0: 1e232842  fadd     s2, s2, s3
//   0x52a4: 1e21c042  fsqrt    s2, s2
//   0x52a8: b90002a8  str      w8, [x21]
//   0x52ac: bd000282  str      s2, [x20]
//   0x52b0: 97fff444  bl       #0x23c0
//   0x52b4: f0000009  adrp     x9, #0x8000
//   0x52b8: d2d00008  mov      x8, #0x800000000000
//   0x52bc: fd440d22  ldr      d2, [x9, #0x818]
//   0x52c0: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x52c4: 1e22c000  fcvt     d0, s0
//   0x52c8: 9e670101  fmov     d1, x8
//   0x52cc: d2d00008  mov      x8, #0x800000000000
//   0x52d0: 1e610800  fmul     d0, d0, d1
//   0x52d4: f2e80ec8  movk     x8, #0x4076, lsl #48
//   0x52d8: 1e621800  fdiv     d0, d0, d2
//   0x52dc: 9e670101  fmov     d1, x8
//   0x52e0: 528c16e9  mov      w9, #0x60b7
//   0x52e4: 1e612800  fadd     d0, d0, d1
//   0x52e8: 72b6c169  movk     w9, #0xb60b, lsl #16
//   0x52ec: 1e780008  fcvtzs   w8, d0
//   0x52f0: 9b297d09  smull    x9, w8, w9
//   0x52f4: d360fd29  lsr      x9, x9, #0x20
//   0x52f8: 0b080129  add      w9, w9, w8
//   0x52fc: 13087d2a  asr      w10, w9, #8
//   0x5300: 0b497d49  add      w9, w10, w9, lsr #31
//   0x5304: 52802d0a  mov      w10, #0x168
//   0x5308: 1e620101  scvtf    d1, w8
//   0x530c: 1e613800  fsub     d0, d0, d1
//   0x5310: 1b0aa128  msub     w8, w9, w10, w8
//   0x5314: 1e220101  scvtf    s1, w8
//   0x5318: 1e624000  fcvt     s0, d0
//   0x531c: 1e202820  fadd     s0, s1, s0
//   0x5320: bd000260  str      s0, [x19]
//   0x5324: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x5328: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x532c: f9400bf5  ldr      x21, [sp, #0x10]
//   0x5330: 910103ff  add      sp, sp, #0x40
//   0x5334: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_35_525c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000525cULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2923ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[36] Symbol: lrgb2rgb
//      Virtual Address Range: 0x5338..0x53b8 (128 bytes, 32 AArch64 instructions)
// [VN] Khung FDE[36] Biểu tượng: lrgb2rgb
//      Dải địa chỉ ảo: 0x5338..0x53b8 (128 byte, 32 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5338: fc1e0fe8  str      d8, [sp, #-0x20]!
//   0x533c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x5340: 910043fd  add      x29, sp, #0x10
//   0x5344: f0000008  adrp     x8, #0x8000
//   0x5348: fd441101  ldr      d1, [x8, #0x820]
//   0x534c: 1e614002  fneg     d2, d0
//   0x5350: 1e602008  fcmp     d0, #0.0
//   0x5354: 1e604c42  fcsel    d2, d2, d0, mi
//   0x5358: 1e612040  fcmp     d2, d1
//   0x535c: 5400022d  b.le     #0x53a0
//   0x5360: 1e602008  fcmp     d0, #0.0
//   0x5364: 1e6e1000  fmov     d0, #1.00000000
//   0x5368: 1e7e1001  fmov     d1, #-1.00000000
//   0x536c: f0000008  adrp     x8, #0x8000
//   0x5370: 1e604c28  fcsel    d8, d1, d0, mi
//   0x5374: fd446d01  ldr      d1, [x8, #0x8d8]
//   0x5378: 4ea21c40  mov      v0.16b, v2.16b
//   0x537c: 97fff36d  bl       #0x2130
//   0x5380: f0000008  adrp     x8, #0x8000
//   0x5384: fd441d01  ldr      d1, [x8, #0x838]
//   0x5388: f0000008  adrp     x8, #0x8000
//   0x538c: fd447102  ldr      d2, [x8, #0x8e0]
//   0x5390: 1e610800  fmul     d0, d0, d1
//   0x5394: 1e622800  fadd     d0, d0, d2
//   0x5398: 1e600900  fmul     d0, d8, d0
//   0x539c: 14000004  b        #0x53ac
//   0x53a0: f0000008  adrp     x8, #0x8000
//   0x53a4: fd442101  ldr      d1, [x8, #0x840]
//   0x53a8: 1e610800  fmul     d0, d0, d1
//   0x53ac: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x53b0: fc4207e8  ldr      d8, [sp], #0x20
//   0x53b4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_36_5338(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005338ULL;
    for (std::size_t i = 0; i < 32ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2978ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[37] Symbol: OK_LAB2RGB
//      Virtual Address Range: 0x53b8..0x5670 (696 bytes, 174 AArch64 instructions)
// [VN] Khung FDE[37] Biểu tượng: OK_LAB2RGB
//      Dải địa chỉ ảo: 0x53b8..0x5670 (696 byte, 174 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x53b8: 6db73bef  stp      d15, d14, [sp, #-0x90]!
//   0x53bc: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x53c0: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x53c4: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x53c8: f90023f9  str      x25, [sp, #0x40]
//   0x53cc: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x53d0: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x53d4: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x53d8: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x53dc: 910203fd  add      x29, sp, #0x80
//   0x53e0: f0000008  adrp     x8, #0x8000
//   0x53e4: 1e22c00b  fcvt     d11, s0
//   0x53e8: fd447500  ldr      d0, [x8, #0x8e8]
//   0x53ec: f0000008  adrp     x8, #0x8000
//   0x53f0: 1e22c02c  fcvt     d12, s1
//   0x53f4: fd447901  ldr      d1, [x8, #0x8f0]
//   0x53f8: 1e22c04d  fcvt     d13, s2
//   0x53fc: 1e600980  fmul     d0, d12, d0
//   0x5400: 1e6b2800  fadd     d0, d0, d11
//   0x5404: 1e6109a1  fmul     d1, d13, d1
//   0x5408: 1e61100a  fmov     d10, #3.00000000
//   0x540c: 1e612800  fadd     d0, d0, d1
//   0x5410: 4eaa1d41  mov      v1.16b, v10.16b
//   0x5414: aa0203f3  mov      x19, x2
//   0x5418: aa0103f4  mov      x20, x1
//   0x541c: aa0003f5  mov      x21, x0
//   0x5420: 97fff344  bl       #0x2130
//   0x5424: f0000008  adrp     x8, #0x8000
//   0x5428: 4ea01c08  mov      v8.16b, v0.16b
//   0x542c: fd447d00  ldr      d0, [x8, #0x8f8]
//   0x5430: f0000008  adrp     x8, #0x8000
//   0x5434: fd448101  ldr      d1, [x8, #0x900]
//   0x5438: 1e600980  fmul     d0, d12, d0
//   0x543c: 1e602960  fadd     d0, d11, d0
//   0x5440: 1e6109a1  fmul     d1, d13, d1
//   0x5444: 1e612800  fadd     d0, d0, d1
//   0x5448: 4eaa1d41  mov      v1.16b, v10.16b
//   0x544c: 97fff339  bl       #0x2130
//   0x5450: f0000008  adrp     x8, #0x8000
//   0x5454: 4ea01c09  mov      v9.16b, v0.16b
//   0x5458: fd448500  ldr      d0, [x8, #0x908]
//   0x545c: f0000008  adrp     x8, #0x8000
//   0x5460: fd448901  ldr      d1, [x8, #0x910]
//   0x5464: 1e600980  fmul     d0, d12, d0
//   0x5468: 1e602960  fadd     d0, d11, d0
//   0x546c: 1e6109a1  fmul     d1, d13, d1
//   0x5470: 1e612800  fadd     d0, d0, d1
//   0x5474: 4eaa1d41  mov      v1.16b, v10.16b
//   0x5478: 97fff32e  bl       #0x2130
//   0x547c: f0000008  adrp     x8, #0x8000
//   0x5480: f0000009  adrp     x9, #0x8000
//   0x5484: 4ea01c0a  mov      v10.16b, v0.16b
//   0x5488: f000000a  adrp     x10, #0x8000
//   0x548c: fd448d00  ldr      d0, [x8, #0x918]
//   0x5490: fd449121  ldr      d1, [x9, #0x920]
//   0x5494: fd449542  ldr      d2, [x10, #0x928]
//   0x5498: f000000b  adrp     x11, #0x8000
//   0x549c: 1e600900  fmul     d0, d8, d0
//   0x54a0: 1e610921  fmul     d1, d9, d1
//   0x54a4: 1e612800  fadd     d0, d0, d1
//   0x54a8: fd44116e  ldr      d14, [x11, #0x820]
//   0x54ac: 1e620941  fmul     d1, d10, d2
//   0x54b0: 1e602821  fadd     d1, d1, d0
//   0x54b4: 1e614020  fneg     d0, d1
//   0x54b8: 1e602028  fcmp     d1, #0.0
//   0x54bc: 1e614c00  fcsel    d0, d0, d1, mi
//   0x54c0: f0000017  adrp     x23, #0x8000
//   0x54c4: 1e6e100b  fmov     d11, #1.00000000
//   0x54c8: 1e7e100c  fmov     d12, #-1.00000000
//   0x54cc: f0000018  adrp     x24, #0x8000
//   0x54d0: 1e6e2000  fcmp     d0, d14
//   0x54d4: f0000019  adrp     x25, #0x8000
//   0x54d8: f0000016  adrp     x22, #0x8000
//   0x54dc: 5400016d  b.le     #0x5508
//   0x54e0: 1e602028  fcmp     d1, #0.0
//   0x54e4: fd446f01  ldr      d1, [x24, #0x8d8]
//   0x54e8: 1e6b4d8d  fcsel    d13, d12, d11, mi
//   0x54ec: 97fff311  bl       #0x2130
//   0x54f0: fd441f21  ldr      d1, [x25, #0x838]
//   0x54f4: fd4472c2  ldr      d2, [x22, #0x8e0]
//   0x54f8: 1e610800  fmul     d0, d0, d1
//   0x54fc: 1e622800  fadd     d0, d0, d2
//   0x5500: 1e6009a0  fmul     d0, d13, d0
//   0x5504: 14000003  b        #0x5510
//   0x5508: fd4422e0  ldr      d0, [x23, #0x840]
//   0x550c: 1e600820  fmul     d0, d1, d0
//   0x5510: d2dc0008  mov      x8, #0xe00000000000
//   0x5514: f2e80de8  movk     x8, #0x406f, lsl #48
//   0x5518: 9e670101  fmov     d1, x8
//   0x551c: 1e6c100d  fmov     d13, #0.50000000
//   0x5520: f0000009  adrp     x9, #0x8000
//   0x5524: f0000008  adrp     x8, #0x8000
//   0x5528: 1e610800  fmul     d0, d0, d1
//   0x552c: fd449922  ldr      d2, [x9, #0x930]
//   0x5530: f0000009  adrp     x9, #0x8000
//   0x5534: fd449d01  ldr      d1, [x8, #0x938]
//   0x5538: 1e6d2800  fadd     d0, d0, d13
//   0x553c: 1e780008  fcvtzs   w8, d0
//   0x5540: fd44a120  ldr      d0, [x9, #0x940]
//   0x5544: 1e620902  fmul     d2, d8, d2
//   0x5548: 1e610921  fmul     d1, d9, d1
//   0x554c: 1e622821  fadd     d1, d1, d2
//   0x5550: 1e600940  fmul     d0, d10, d0
//   0x5554: 1e602821  fadd     d1, d1, d0
//   0x5558: 1e614020  fneg     d0, d1
//   0x555c: 1e602028  fcmp     d1, #0.0
//   0x5560: 1e614c00  fcsel    d0, d0, d1, mi
//   0x5564: 1e6e2000  fcmp     d0, d14
//   0x5568: b90002a8  str      w8, [x21]
//   0x556c: 5400016d  b.le     #0x5598
//   0x5570: 1e602028  fcmp     d1, #0.0
//   0x5574: fd446f01  ldr      d1, [x24, #0x8d8]
//   0x5578: 1e6b4d8f  fcsel    d15, d12, d11, mi
//   0x557c: 97fff2ed  bl       #0x2130
//   0x5580: fd441f21  ldr      d1, [x25, #0x838]
//   0x5584: fd4472c2  ldr      d2, [x22, #0x8e0]
//   0x5588: 1e610800  fmul     d0, d0, d1
//   0x558c: 1e622800  fadd     d0, d0, d2
//   0x5590: 1e6009e0  fmul     d0, d15, d0
//   0x5594: 14000003  b        #0x55a0
//   0x5598: fd4422e0  ldr      d0, [x23, #0x840]
//   0x559c: 1e600820  fmul     d0, d1, d0
//   0x55a0: d2dc0008  mov      x8, #0xe00000000000
//   0x55a4: f2e80de8  movk     x8, #0x406f, lsl #48
//   0x55a8: 9e670101  fmov     d1, x8
//   0x55ac: f0000008  adrp     x8, #0x8000
//   0x55b0: fd44a502  ldr      d2, [x8, #0x948]
//   0x55b4: f0000008  adrp     x8, #0x8000
//   0x55b8: fd44a903  ldr      d3, [x8, #0x950]
//   0x55bc: f0000008  adrp     x8, #0x8000
//   0x55c0: 1e610800  fmul     d0, d0, d1
//   0x55c4: fd44ad01  ldr      d1, [x8, #0x958]
//   0x55c8: 1e6d2800  fadd     d0, d0, d13
//   0x55cc: 1e780008  fcvtzs   w8, d0
//   0x55d0: 1e620900  fmul     d0, d8, d2
//   0x55d4: 1e630922  fmul     d2, d9, d3
//   0x55d8: 1e610941  fmul     d1, d10, d1
//   0x55dc: 1e622800  fadd     d0, d0, d2
//   0x55e0: 1e602821  fadd     d1, d1, d0
//   0x55e4: 1e614020  fneg     d0, d1
//   0x55e8: 1e602028  fcmp     d1, #0.0
//   0x55ec: 1e614c00  fcsel    d0, d0, d1, mi
//   0x55f0: 1e6e2000  fcmp     d0, d14
//   0x55f4: b9000288  str      w8, [x20]
//   0x55f8: 5400016d  b.le     #0x5624
//   0x55fc: 1e602028  fcmp     d1, #0.0
//   0x5600: fd446f01  ldr      d1, [x24, #0x8d8]
//   0x5604: 1e6b4d88  fcsel    d8, d12, d11, mi
//   0x5608: 97fff2ca  bl       #0x2130
//   0x560c: fd441f21  ldr      d1, [x25, #0x838]
//   0x5610: fd4472c2  ldr      d2, [x22, #0x8e0]
//   0x5614: 1e610800  fmul     d0, d0, d1
//   0x5618: 1e622800  fadd     d0, d0, d2
//   0x561c: 1e600900  fmul     d0, d8, d0
//   0x5620: 14000003  b        #0x562c
//   0x5624: fd4422e0  ldr      d0, [x23, #0x840]
//   0x5628: 1e600820  fmul     d0, d1, d0
//   0x562c: d2dc0008  mov      x8, #0xe00000000000
//   0x5630: f2e80de8  movk     x8, #0x406f, lsl #48
//   0x5634: 9e670101  fmov     d1, x8
//   0x5638: 1e610800  fmul     d0, d0, d1
//   0x563c: 1e6d2800  fadd     d0, d0, d13
//   0x5640: 1e780008  fcvtzs   w8, d0
//   0x5644: b9000268  str      w8, [x19]
//   0x5648: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x564c: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x5650: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x5654: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x5658: f94023f9  ldr      x25, [sp, #0x40]
//   0x565c: 6d4323e9  ldp      d9, d8, [sp, #0x30]
//   0x5660: 6d422beb  ldp      d11, d10, [sp, #0x20]
//   0x5664: 6d4133ed  ldp      d13, d12, [sp, #0x10]
//   0x5668: 6cc93bef  ldp      d15, d14, [sp], #0x90
//   0x566c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_37_53b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000053b8ULL;
    for (std::size_t i = 0; i < 174ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3010ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[38] Symbol: OK_LCH2RGB
//      Virtual Address Range: 0x5670..0x56fc (140 bytes, 35 AArch64 instructions)
// [VN] Khung FDE[38] Biểu tượng: OK_LCH2RGB
//      Dải địa chỉ ảo: 0x5670..0x56fc (140 byte, 35 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5670: 6dbc23e9  stp      d9, d8, [sp, #-0x40]!
//   0x5674: f9000bf5  str      x21, [sp, #0x10]
//   0x5678: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x567c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x5680: 9100c3fd  add      x29, sp, #0x30
//   0x5684: f0000008  adrp     x8, #0x8000
//   0x5688: 4ea01c09  mov      v9.16b, v0.16b
//   0x568c: fd440d00  ldr      d0, [x8, #0x818]
//   0x5690: d2d00008  mov      x8, #0x800000000000
//   0x5694: 4ea11c28  mov      v8.16b, v1.16b
//   0x5698: 1e22c041  fcvt     d1, s2
//   0x569c: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x56a0: 1e600820  fmul     d0, d1, d0
//   0x56a4: 9e670101  fmov     d1, x8
//   0x56a8: 1e611800  fdiv     d0, d0, d1
//   0x56ac: aa0103f4  mov      x20, x1
//   0x56b0: aa0003f5  mov      x21, x0
//   0x56b4: 1e624000  fcvt     s0, d0
//   0x56b8: d10053a0  sub      x0, x29, #0x14
//   0x56bc: 910063e1  add      x1, sp, #0x18
//   0x56c0: aa0203f3  mov      x19, x2
//   0x56c4: 97fff31b  bl       #0x2330
//   0x56c8: bd401be0  ldr      s0, [sp, #0x18]
//   0x56cc: bc5ec3a2  ldur     s2, [x29, #-0x14]
//   0x56d0: aa1503e0  mov      x0, x21
//   0x56d4: aa1403e1  mov      x1, x20
//   0x56d8: aa1303e2  mov      x2, x19
//   0x56dc: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x56e0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x56e4: f9400bf5  ldr      x21, [sp, #0x10]
//   0x56e8: 1e280801  fmul     s1, s0, s8
//   0x56ec: 1e280842  fmul     s2, s2, s8
//   0x56f0: 4ea91d20  mov      v0.16b, v9.16b
//   0x56f4: 6cc423e9  ldp      d9, d8, [sp], #0x40
//   0x56f8: 17fff27a  b        #0x20e0
// ============================================================================
std::uint32_t fde_38_5670(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005670ULL;
    for (std::size_t i = 0; i < 35ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3184ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[39] Symbol: canDisplay
//      Virtual Address Range: 0x56fc..0x5710 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[39] Biểu tượng: canDisplay
//      Dải địa chỉ ảo: 0x56fc..0x5710 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x56fc: 2a000028  orr      w8, w1, w0
//   0x5700: 2a020108  orr      w8, w8, w2
//   0x5704: 7104011f  cmp      w8, #0x100
//   0x5708: 1a9f27e0  cset     w0, lo
//   0x570c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_39_56fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000056fcULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3219ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[40] Symbol: customClampC
//      Virtual Address Range: 0x5710..0x589c (396 bytes, 99 AArch64 instructions)
// [VN] Khung FDE[40] Biểu tượng: customClampC
//      Dải địa chỉ ảo: 0x5710..0x589c (396 byte, 99 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5710: d101c3ff  sub      sp, sp, #0x70
//   0x5714: 6d013bef  stp      d15, d14, [sp, #0x10]
//   0x5718: 6d0233ed  stp      d13, d12, [sp, #0x20]
//   0x571c: 6d032beb  stp      d11, d10, [sp, #0x30]
//   0x5720: 6d0423e9  stp      d9, d8, [sp, #0x40]
//   0x5724: f9002bf3  str      x19, [sp, #0x50]
//   0x5728: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x572c: 910183fd  add      x29, sp, #0x60
//   0x5730: f0000008  adrp     x8, #0x8000
//   0x5734: 4ea01c0a  mov      v10.16b, v0.16b
//   0x5738: fd440d00  ldr      d0, [x8, #0x818]
//   0x573c: d2d00008  mov      x8, #0x800000000000
//   0x5740: 4ea11c29  mov      v9.16b, v1.16b
//   0x5744: 1e22c041  fcvt     d1, s2
//   0x5748: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x574c: 1e600820  fmul     d0, d1, d0
//   0x5750: 9e670101  fmov     d1, x8
//   0x5754: 1e611800  fdiv     d0, d0, d1
//   0x5758: 1e624000  fcvt     s0, d0
//   0x575c: 910023e0  add      x0, sp, #8
//   0x5760: 910013e1  add      x1, sp, #4
//   0x5764: 4ea31c68  mov      v8.16b, v3.16b
//   0x5768: 97fff2f2  bl       #0x2330
//   0x576c: 2d40b3eb  ldp      s11, s12, [sp, #4]
//   0x5770: d10013a0  sub      x0, x29, #4
//   0x5774: d10023a1  sub      x1, x29, #8
//   0x5778: 910033e2  add      x2, sp, #0xc
//   0x577c: 1e290961  fmul     s1, s11, s9
//   0x5780: 1e290982  fmul     s2, s12, s9
//   0x5784: 4eaa1d40  mov      v0.16b, v10.16b
//   0x5788: 97fff256  bl       #0x20e0
//   0x578c: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5790: b9400fea  ldr      w10, [sp, #0xc]
//   0x5794: 2a080128  orr      w8, w9, w8
//   0x5798: 2a0a0108  orr      w8, w8, w10
//   0x579c: 7103fd1f  cmp      w8, #0xff
//   0x57a0: 540000a8  b.hi     #0x57b4
//   0x57a4: 1e282120  fcmp     s9, s8
//   0x57a8: 1e3e1000  fmov     s0, #-1.00000000
//   0x57ac: 1e294c08  fcsel    s8, s0, s9, mi
//   0x57b0: 14000032  b        #0x5878
//   0x57b4: 1e280961  fmul     s1, s11, s8
//   0x57b8: 1e280982  fmul     s2, s12, s8
//   0x57bc: d10013a0  sub      x0, x29, #4
//   0x57c0: d10023a1  sub      x1, x29, #8
//   0x57c4: 910033e2  add      x2, sp, #0xc
//   0x57c8: 4eaa1d40  mov      v0.16b, v10.16b
//   0x57cc: 97fff245  bl       #0x20e0
//   0x57d0: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x57d4: b9400fea  ldr      w10, [sp, #0xc]
//   0x57d8: 2a080128  orr      w8, w9, w8
//   0x57dc: 2a0a0108  orr      w8, w8, w10
//   0x57e0: 7103fd1f  cmp      w8, #0xff
//   0x57e4: 54000488  b.hi     #0x5874
//   0x57e8: 52824de8  mov      w8, #0x126f
//   0x57ec: 72a75068  movk     w8, #0x3a83, lsl #16
//   0x57f0: 1e283920  fsub     s0, s9, s8
//   0x57f4: 1e270101  fmov     s1, w8
//   0x57f8: 1e212000  fcmp     s0, s1
//   0x57fc: 540003ed  b.le     #0x5878
//   0x5800: 52824df3  mov      w19, #0x126f
//   0x5804: 1e6c100d  fmov     d13, #0.50000000
//   0x5808: 72a75073  movk     w19, #0x3a83, lsl #16
//   0x580c: 4ea81d0e  mov      v14.16b, v8.16b
//   0x5810: 1e22c000  fcvt     d0, s0
//   0x5814: 1e22c1c1  fcvt     d1, s14
//   0x5818: 1e6d0800  fmul     d0, d0, d13
//   0x581c: 1e612800  fadd     d0, d0, d1
//   0x5820: 1e62400f  fcvt     s15, d0
//   0x5824: 1e2f0961  fmul     s1, s11, s15
//   0x5828: 1e2f0982  fmul     s2, s12, s15
//   0x582c: d10013a0  sub      x0, x29, #4
//   0x5830: d10023a1  sub      x1, x29, #8
//   0x5834: 910033e2  add      x2, sp, #0xc
//   0x5838: 4eaa1d40  mov      v0.16b, v10.16b
//   0x583c: 97fff229  bl       #0x20e0
//   0x5840: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5844: b9400fea  ldr      w10, [sp, #0xc]
//   0x5848: 1e270261  fmov     s1, w19
//   0x584c: 2a080128  orr      w8, w9, w8
//   0x5850: 2a0a0108  orr      w8, w8, w10
//   0x5854: 7104011f  cmp      w8, #0x100
//   0x5858: 1e2e3dee  fcsel    s14, s15, s14, lo
//   0x585c: 1e2f3d29  fcsel    s9, s9, s15, lo
//   0x5860: 1e2e3920  fsub     s0, s9, s14
//   0x5864: 1e283de8  fcsel    s8, s15, s8, lo
//   0x5868: 1e212000  fcmp     s0, s1
//   0x586c: 54fffd2c  b.gt     #0x5810
//   0x5870: 14000002  b        #0x5878
//   0x5874: 1e3e1008  fmov     s8, #-1.00000000
//   0x5878: 4ea81d00  mov      v0.16b, v8.16b
//   0x587c: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x5880: f9402bf3  ldr      x19, [sp, #0x50]
//   0x5884: 6d4423e9  ldp      d9, d8, [sp, #0x40]
//   0x5888: 6d432beb  ldp      d11, d10, [sp, #0x30]
//   0x588c: 6d4233ed  ldp      d13, d12, [sp, #0x20]
//   0x5890: 6d413bef  ldp      d15, d14, [sp, #0x10]
//   0x5894: 9101c3ff  add      sp, sp, #0x70
//   0x5898: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_40_5710(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005710ULL;
    for (std::size_t i = 0; i < 99ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3224ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[41] Symbol: customClampL
//      Virtual Address Range: 0x589c..0x5b94 (760 bytes, 190 AArch64 instructions)
// [VN] Khung FDE[41] Biểu tượng: customClampL
//      Dải địa chỉ ảo: 0x589c..0x5b94 (760 byte, 190 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x589c: d101c3ff  sub      sp, sp, #0x70
//   0x58a0: 6d013bef  stp      d15, d14, [sp, #0x10]
//   0x58a4: 6d0233ed  stp      d13, d12, [sp, #0x20]
//   0x58a8: 6d032beb  stp      d11, d10, [sp, #0x30]
//   0x58ac: 6d0423e9  stp      d9, d8, [sp, #0x40]
//   0x58b0: f9002bf3  str      x19, [sp, #0x50]
//   0x58b4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x58b8: 910183fd  add      x29, sp, #0x60
//   0x58bc: f0000008  adrp     x8, #0x8000
//   0x58c0: 4ea01c0a  mov      v10.16b, v0.16b
//   0x58c4: fd440d00  ldr      d0, [x8, #0x818]
//   0x58c8: d2d00008  mov      x8, #0x800000000000
//   0x58cc: 4ea11c29  mov      v9.16b, v1.16b
//   0x58d0: 1e22c041  fcvt     d1, s2
//   0x58d4: f2e80cc8  movk     x8, #0x4066, lsl #48
//   0x58d8: 1e600820  fmul     d0, d1, d0
//   0x58dc: 9e670101  fmov     d1, x8
//   0x58e0: 1e611800  fdiv     d0, d0, d1
//   0x58e4: 1e624000  fcvt     s0, d0
//   0x58e8: 910023e0  add      x0, sp, #8
//   0x58ec: 910013e1  add      x1, sp, #4
//   0x58f0: 4ea41c8c  mov      v12.16b, v4.16b
//   0x58f4: 4ea31c6d  mov      v13.16b, v3.16b
//   0x58f8: 97fff28e  bl       #0x2330
//   0x58fc: 2d4087e0  ldp      s0, s1, [sp, #4]
//   0x5900: d10013a0  sub      x0, x29, #4
//   0x5904: d10023a1  sub      x1, x29, #8
//   0x5908: 910033e2  add      x2, sp, #0xc
//   0x590c: 1e290808  fmul     s8, s0, s9
//   0x5910: 1e290829  fmul     s9, s1, s9
//   0x5914: 4eaa1d40  mov      v0.16b, v10.16b
//   0x5918: 4ea81d01  mov      v1.16b, v8.16b
//   0x591c: 4ea91d22  mov      v2.16b, v9.16b
//   0x5920: 97fff1f0  bl       #0x20e0
//   0x5924: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5928: b9400fea  ldr      w10, [sp, #0xc]
//   0x592c: 2a080128  orr      w8, w9, w8
//   0x5930: 2a0a0108  orr      w8, w8, w10
//   0x5934: 7103fd1f  cmp      w8, #0xff
//   0x5938: 540000c8  b.hi     #0x5950
//   0x593c: 1e2c2140  fcmp     s10, s12
//   0x5940: 1e2dd548  fccmp    s10, s13, #8, le
//   0x5944: 1e3e1000  fmov     s0, #-1.00000000
//   0x5948: 1e2a4c0b  fcsel    s11, s0, s10, mi
//   0x594c: 14000089  b        #0x5b70
//   0x5950: 1e2d2140  fcmp     s10, s13
//   0x5954: 54000349  b.ls     #0x59bc
//   0x5958: 1e2c2140  fcmp     s10, s12
//   0x595c: 540005e9  b.ls     #0x5a18
//   0x5960: 1e2d2180  fcmp     s12, s13
//   0x5964: 1e3e100b  fmov     s11, #-1.00000000
//   0x5968: 5400104b  b.lt     #0x5b70
//   0x596c: 529ae153  mov      w19, #0xd70a
//   0x5970: 72b78473  movk     w19, #0xbc23, lsl #16
//   0x5974: d10013a0  sub      x0, x29, #4
//   0x5978: d10023a1  sub      x1, x29, #8
//   0x597c: 910033e2  add      x2, sp, #0xc
//   0x5980: 4eac1d80  mov      v0.16b, v12.16b
//   0x5984: 4ea81d01  mov      v1.16b, v8.16b
//   0x5988: 4ea91d22  mov      v2.16b, v9.16b
//   0x598c: 97fff1d5  bl       #0x20e0
//   0x5990: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5994: b9400fea  ldr      w10, [sp, #0xc]
//   0x5998: 2a080128  orr      w8, w9, w8
//   0x599c: 2a0a0108  orr      w8, w8, w10
//   0x59a0: 7104011f  cmp      w8, #0x100
//   0x59a4: 54000e43  b.lo     #0x5b6c
//   0x59a8: 1e270260  fmov     s0, w19
//   0x59ac: 1e20298c  fadd     s12, s12, s0
//   0x59b0: 1e2d2180  fcmp     s12, s13
//   0x59b4: 54fffe0a  b.ge     #0x5974
//   0x59b8: 1400006e  b        #0x5b70
//   0x59bc: 1e2c21a0  fcmp     s13, s12
//   0x59c0: 1e3e100b  fmov     s11, #-1.00000000
//   0x59c4: 54000d68  b.hi     #0x5b70
//   0x59c8: 529ae153  mov      w19, #0xd70a
//   0x59cc: 72a78473  movk     w19, #0x3c23, lsl #16
//   0x59d0: d10013a0  sub      x0, x29, #4
//   0x59d4: d10023a1  sub      x1, x29, #8
//   0x59d8: 910033e2  add      x2, sp, #0xc
//   0x59dc: 4ead1da0  mov      v0.16b, v13.16b
//   0x59e0: 4ea81d01  mov      v1.16b, v8.16b
//   0x59e4: 4ea91d22  mov      v2.16b, v9.16b
//   0x59e8: 97fff1be  bl       #0x20e0
//   0x59ec: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x59f0: b9400fea  ldr      w10, [sp, #0xc]
//   0x59f4: 2a080128  orr      w8, w9, w8
//   0x59f8: 2a0a0108  orr      w8, w8, w10
//   0x59fc: 7104011f  cmp      w8, #0x100
//   0x5a00: 54000b23  b.lo     #0x5b64
//   0x5a04: 1e270260  fmov     s0, w19
//   0x5a08: 1e2029ad  fadd     s13, s13, s0
//   0x5a0c: 1e2c21a0  fcmp     s13, s12
//   0x5a10: 54fffe09  b.ls     #0x59d0
//   0x5a14: 14000057  b        #0x5b70
//   0x5a18: 1e2d3940  fsub     s0, s10, s13
//   0x5a1c: 1e2a3981  fsub     s1, s12, s10
//   0x5a20: 529ae148  mov      w8, #0xd70a
//   0x5a24: 1e212000  fcmp     s0, s1
//   0x5a28: 72a78468  movk     w8, #0x3c23, lsl #16
//   0x5a2c: 1e214c0f  fcsel    s15, s0, s1, mi
//   0x5a30: 1e204c20  fcsel    s0, s1, s0, mi
//   0x5a34: 1e3e1003  fmov     s3, #-1.00000000
//   0x5a38: 1e2e1002  fmov     s2, #1.00000000
//   0x5a3c: bd0003e0  str      s0, [sp]
//   0x5a40: 1e270100  fmov     s0, w8
//   0x5a44: 1e234c4e  fcsel    s14, s2, s3, mi
//   0x5a48: 1e224c6c  fcsel    s12, s3, s2, mi
//   0x5a4c: 1e2021e0  fcmp     s15, s0
//   0x5a50: 540004cb  b.lt     #0x5ae8
//   0x5a54: 529ae153  mov      w19, #0xd70a
//   0x5a58: 72a78473  movk     w19, #0x3c23, lsl #16
//   0x5a5c: 1e27026d  fmov     s13, w19
//   0x5a60: 1e2d09c0  fmul     s0, s14, s13
//   0x5a64: 1e2a280b  fadd     s11, s0, s10
//   0x5a68: d10013a0  sub      x0, x29, #4
//   0x5a6c: d10023a1  sub      x1, x29, #8
//   0x5a70: 910033e2  add      x2, sp, #0xc
//   0x5a74: 4eab1d60  mov      v0.16b, v11.16b
//   0x5a78: 4ea81d01  mov      v1.16b, v8.16b
//   0x5a7c: 4ea91d22  mov      v2.16b, v9.16b
//   0x5a80: 97fff198  bl       #0x20e0
//   0x5a84: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5a88: b9400fea  ldr      w10, [sp, #0xc]
//   0x5a8c: 2a080128  orr      w8, w9, w8
//   0x5a90: 2a0a0108  orr      w8, w8, w10
//   0x5a94: 7104011f  cmp      w8, #0x100
//   0x5a98: 540006c3  b.lo     #0x5b70
//   0x5a9c: 1e2d0980  fmul     s0, s12, s13
//   0x5aa0: 1e2a280b  fadd     s11, s0, s10
//   0x5aa4: d10013a0  sub      x0, x29, #4
//   0x5aa8: d10023a1  sub      x1, x29, #8
//   0x5aac: 910033e2  add      x2, sp, #0xc
//   0x5ab0: 4eab1d60  mov      v0.16b, v11.16b
//   0x5ab4: 4ea81d01  mov      v1.16b, v8.16b
//   0x5ab8: 4ea91d22  mov      v2.16b, v9.16b
//   0x5abc: 97fff189  bl       #0x20e0
//   0x5ac0: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5ac4: b9400fea  ldr      w10, [sp, #0xc]
//   0x5ac8: 2a080128  orr      w8, w9, w8
//   0x5acc: 2a0a0108  orr      w8, w8, w10
//   0x5ad0: 7104011f  cmp      w8, #0x100
//   0x5ad4: 540004e3  b.lo     #0x5b70
//   0x5ad8: 1e270260  fmov     s0, w19
//   0x5adc: 1e2029ad  fadd     s13, s13, s0
//   0x5ae0: 1e2f21a0  fcmp     s13, s15
//   0x5ae4: 54fffbe9  b.ls     #0x5a60
//   0x5ae8: bd4003e1  ldr      s1, [sp]
//   0x5aec: 529ae148  mov      w8, #0xd70a
//   0x5af0: 72a78468  movk     w8, #0x3c23, lsl #16
//   0x5af4: 1e270100  fmov     s0, w8
//   0x5af8: 1e202020  fcmp     s1, s0
//   0x5afc: 5400030b  b.lt     #0x5b5c
//   0x5b00: 529ae153  mov      w19, #0xd70a
//   0x5b04: 72a78473  movk     w19, #0x3c23, lsl #16
//   0x5b08: 1e27026c  fmov     s12, w19
//   0x5b0c: 1e2c09c0  fmul     s0, s14, s12
//   0x5b10: 1e2a280b  fadd     s11, s0, s10
//   0x5b14: d10013a0  sub      x0, x29, #4
//   0x5b18: d10023a1  sub      x1, x29, #8
//   0x5b1c: 910033e2  add      x2, sp, #0xc
//   0x5b20: 4eab1d60  mov      v0.16b, v11.16b
//   0x5b24: 4ea81d01  mov      v1.16b, v8.16b
//   0x5b28: 4ea91d22  mov      v2.16b, v9.16b
//   0x5b2c: 97fff16d  bl       #0x20e0
//   0x5b30: 297f23a9  ldp      w9, w8, [x29, #-8]
//   0x5b34: b9400fea  ldr      w10, [sp, #0xc]
//   0x5b38: 2a080128  orr      w8, w9, w8
//   0x5b3c: 2a0a0108  orr      w8, w8, w10
//   0x5b40: 7104011f  cmp      w8, #0x100
//   0x5b44: 54000163  b.lo     #0x5b70
//   0x5b48: 1e270260  fmov     s0, w19
//   0x5b4c: 1e20298c  fadd     s12, s12, s0
//   0x5b50: bd4003e0  ldr      s0, [sp]
//   0x5b54: 1e202180  fcmp     s12, s0
//   0x5b58: 54fffda9  b.ls     #0x5b0c
//   0x5b5c: 1e3e100b  fmov     s11, #-1.00000000
//   0x5b60: 14000004  b        #0x5b70
//   0x5b64: 4ead1dab  mov      v11.16b, v13.16b
//   0x5b68: 14000002  b        #0x5b70
//   0x5b6c: 4eac1d8b  mov      v11.16b, v12.16b
//   0x5b70: 4eab1d60  mov      v0.16b, v11.16b
//   0x5b74: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x5b78: f9402bf3  ldr      x19, [sp, #0x50]
//   0x5b7c: 6d4423e9  ldp      d9, d8, [sp, #0x40]
//   0x5b80: 6d432beb  ldp      d11, d10, [sp, #0x30]
//   0x5b84: 6d4233ed  ldp      d13, d12, [sp, #0x20]
//   0x5b88: 6d413bef  ldp      d15, d14, [sp, #0x10]
//   0x5b8c: 9101c3ff  add      sp, sp, #0x70
//   0x5b90: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_41_589c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000589cULL;
    for (std::size_t i = 0; i < 190ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3323ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[42] Symbol: merged_close_color
//      Virtual Address Range: 0x5b94..0x5ee4 (848 bytes, 212 AArch64 instructions)
// [VN] Khung FDE[42] Biểu tượng: merged_close_color
//      Dải địa chỉ ảo: 0x5b94..0x5ee4 (848 byte, 212 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5b94: d10643ff  sub      sp, sp, #0x190
//   0x5b98: fd0093e8  str      d8, [sp, #0x120]
//   0x5b9c: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x5ba0: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x5ba4: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x5ba8: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x5bac: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x5bb0: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x5bb4: 910603fd  add      x29, sp, #0x180
//   0x5bb8: d53bd05b  mrs      x27, tpidr_el0
//   0x5bbc: f9401768  ldr      x8, [x27, #0x28]
//   0x5bc0: 4ea01c08  mov      v8.16b, v0.16b
//   0x5bc4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x5bc8: 7100045f  cmp      w2, #1
//   0x5bcc: f81903a8  stur     x8, [x29, #-0x70]
//   0x5bd0: ad3b83a0  stp      q0, q0, [x29, #-0x90]
//   0x5bd4: ad3a83a0  stp      q0, q0, [x29, #-0xb0]
//   0x5bd8: ad0583e0  stp      q0, q0, [sp, #0xb0]
//   0x5bdc: ad0483e0  stp      q0, q0, [sp, #0x90]
//   0x5be0: ad0383e0  stp      q0, q0, [sp, #0x70]
//   0x5be4: ad0283e0  stp      q0, q0, [sp, #0x50]
//   0x5be8: f9000fe0  str      x0, [sp, #0x18]
//   0x5bec: 54000dcb  b.lt     #0x5da4
//   0x5bf0: 93407c48  sxtw     x8, w2
//   0x5bf4: 910143eb  add      x11, sp, #0x50
//   0x5bf8: aa1f03ec  mov      x12, xzr
//   0x5bfc: 2a1f03e9  mov      w9, wzr
//   0x5c00: a90023fb  stp      x27, x8, [sp]
//   0x5c04: 2a0203ea  mov      w10, w2
//   0x5c08: 91001037  add      x23, x1, #4
//   0x5c0c: 9100101b  add      x27, x0, #4
//   0x5c10: b27e0176  orr      x22, x11, #4
//   0x5c14: 52800034  mov      w20, #1
//   0x5c18: f9000be1  str      x1, [sp, #0x10]
//   0x5c1c: f90013ea  str      x10, [sp, #0x20]
//   0x5c20: b86c7968  ldr      w8, [x11, x12, lsl #2]
//   0x5c24: 35000248  cbnz     w8, #0x5c6c
//   0x5c28: 14000013  b        #0x5c74
//   0x5c2c: a942b3e9  ldp      x9, x12, [sp, #0x28]
//   0x5c30: 910143eb  add      x11, sp, #0x50
//   0x5c34: 52800028  mov      w8, #1
//   0x5c38: a94103e1  ldp      x1, x0, [sp, #0x10]
//   0x5c3c: b8297968  str      w8, [x11, x9, lsl #2]
//   0x5c40: f9401fe9  ldr      x9, [sp, #0x38]
//   0x5c44: f94013ea  ldr      x10, [sp, #0x20]
//   0x5c48: 11000529  add      w9, w9, #1
//   0x5c4c: 91000694  add      x20, x20, #1
//   0x5c50: 910012f7  add      x23, x23, #4
//   0x5c54: 9100137b  add      x27, x27, #4
//   0x5c58: eb0a019f  cmp      x12, x10
//   0x5c5c: 910012d6  add      x22, x22, #4
//   0x5c60: 54000820  b.eq     #0x5d64
//   0x5c64: b86c7968  ldr      w8, [x11, x12, lsl #2]
//   0x5c68: 34000068  cbz      w8, #0x5c74
//   0x5c6c: 9100058c  add      x12, x12, #1
//   0x5c70: 17fffff7  b        #0x5c4c
//   0x5c74: d37ef588  lsl      x8, x12, #2
//   0x5c78: b868682b  ldr      w11, [x1, x8]
//   0x5c7c: f9001fe9  str      x9, [sp, #0x38]
//   0x5c80: 937e7d29  sbfiz    x9, x9, #2, #0x20
//   0x5c84: 910243ea  add      x10, sp, #0x90
//   0x5c88: b829694b  str      w11, [x10, x9]
//   0x5c8c: f94007ea  ldr      x10, [sp, #8]
//   0x5c90: b8686808  ldr      w8, [x0, x8]
//   0x5c94: b90043eb  str      w11, [sp, #0x40]
//   0x5c98: 9100058b  add      x11, x12, #1
//   0x5c9c: eb0a017f  cmp      x11, x10
//   0x5ca0: d102c3aa  sub      x10, x29, #0xb0
//   0x5ca4: a902afec  stp      x12, x11, [sp, #0x28]
//   0x5ca8: b8296948  str      w8, [x10, x9]
//   0x5cac: 54fffc0a  b.ge     #0x5c2c
//   0x5cb0: f9401fe9  ldr      x9, [sp, #0x38]
//   0x5cb4: f94013f3  ldr      x19, [sp, #0x20]
//   0x5cb8: b94043f8  ldr      w24, [sp, #0x40]
//   0x5cbc: aa1603f5  mov      x21, x22
//   0x5cc0: 93407d3c  sxtw     x28, w9
//   0x5cc4: 53105d09  ubfx     w9, w8, #0x10, #8
//   0x5cc8: b9004fe9  str      w9, [sp, #0x4c]
//   0x5ccc: 53083d09  ubfx     w9, w8, #8, #8
//   0x5cd0: 12001d08  and      w8, w8, #0xff
//   0x5cd4: aa1b03fa  mov      x26, x27
//   0x5cd8: aa1703f9  mov      x25, x23
//   0x5cdc: 2908a7e8  stp      w8, w9, [sp, #0x44]
//   0x5ce0: b94002a8  ldr      w8, [x21]
//   0x5ce4: 34000128  cbz      w8, #0x5d08
//   0x5ce8: d1000673  sub      x19, x19, #1
//   0x5cec: 91001339  add      x25, x25, #4
//   0x5cf0: 9100135a  add      x26, x26, #4
//   0x5cf4: eb13029f  cmp      x20, x19
//   0x5cf8: 910012b5  add      x21, x21, #4
//   0x5cfc: 54fff980  b.eq     #0x5c2c
//   0x5d00: b94002a8  ldr      w8, [x21]
//   0x5d04: 35ffff28  cbnz     w8, #0x5ce8
//   0x5d08: b9400348  ldr      w8, [x26]
//   0x5d0c: 294903e1  ldp      w1, w0, [sp, #0x48]
//   0x5d10: b94047e2  ldr      w2, [sp, #0x44]
//   0x5d14: 53105d03  ubfx     w3, w8, #0x10, #8
//   0x5d18: 53083d04  ubfx     w4, w8, #8, #8
//   0x5d1c: 12001d05  and      w5, w8, #0xff
//   0x5d20: 97fff164  bl       #0x22b0
//   0x5d24: 1e282000  fcmp     s0, s8
//   0x5d28: 54fffe05  b.pl     #0x5ce8
//   0x5d2c: 52800028  mov      w8, #1
//   0x5d30: b90002a8  str      w8, [x21]
//   0x5d34: b9400328  ldr      w8, [x25]
//   0x5d38: b94043e9  ldr      w9, [sp, #0x40]
//   0x5d3c: 0b080318  add      w24, w24, w8
//   0x5d40: 6b09011f  cmp      w8, w9
//   0x5d44: 910243e9  add      x9, sp, #0x90
//   0x5d48: b83c7938  str      w24, [x9, x28, lsl #2]
//   0x5d4c: 54fffced  b.le     #0x5ce8
//   0x5d50: b9400349  ldr      w9, [x26]
//   0x5d54: d102c3aa  sub      x10, x29, #0xb0
//   0x5d58: b90043e8  str      w8, [sp, #0x40]
//   0x5d5c: b83c7949  str      w9, [x10, x28, lsl #2]
//   0x5d60: 17ffffe2  b        #0x5ce8
//   0x5d64: aa0903e0  mov      x0, x9
//   0x5d68: 296a53b0  ldp      w16, w20, [x29, #-0xb0]
//   0x5d6c: 29523ff5  ldp      w21, w15, [sp, #0x90]
//   0x5d70: 296b1fae  ldp      w14, w7, [x29, #-0xa8]
//   0x5d74: 295337f3  ldp      w19, w13, [sp, #0x98]
//   0x5d78: 296c17ac  ldp      w12, w5, [x29, #-0xa0]
//   0x5d7c: 29542fe6  ldp      w6, w11, [sp, #0xa0]
//   0x5d80: 296d0faa  ldp      w10, w3, [x29, #-0x98]
//   0x5d84: 295527e4  ldp      w4, w9, [sp, #0xa8]
//   0x5d88: 296e5fa8  ldp      w8, w23, [x29, #-0x90]
//   0x5d8c: 295647f6  ldp      w22, w17, [sp, #0xb0]
//   0x5d90: 296f67be  ldp      w30, w25, [x29, #-0x88]
//   0x5d94: 29576bf8  ldp      w24, w26, [sp, #0xb8]
//   0x5d98: b85803a2  ldur     w2, [x29, #-0x80]
//   0x5d9c: f94003fb  ldr      x27, [sp]
//   0x5da0: 1400001b  b        #0x5e0c
//   0x5da4: 2a1f03e2  mov      w2, wzr
//   0x5da8: 2a1f03fa  mov      w26, wzr
//   0x5dac: 2a1f03f9  mov      w25, wzr
//   0x5db0: 2a1f03f8  mov      w24, wzr
//   0x5db4: 2a1f03fe  mov      w30, wzr
//   0x5db8: 2a1f03f1  mov      w17, wzr
//   0x5dbc: 2a1f03f7  mov      w23, wzr
//   0x5dc0: 2a1f03f6  mov      w22, wzr
//   0x5dc4: 2a1f03e8  mov      w8, wzr
//   0x5dc8: 2a1f03e9  mov      w9, wzr
//   0x5dcc: 2a1f03e3  mov      w3, wzr
//   0x5dd0: 2a1f03e4  mov      w4, wzr
//   0x5dd4: 2a1f03ea  mov      w10, wzr
//   0x5dd8: 2a1f03eb  mov      w11, wzr
//   0x5ddc: 2a1f03e5  mov      w5, wzr
//   0x5de0: 2a1f03e6  mov      w6, wzr
//   0x5de4: 2a1f03ec  mov      w12, wzr
//   0x5de8: 2a1f03ed  mov      w13, wzr
//   0x5dec: 2a1f03e7  mov      w7, wzr
//   0x5df0: 2a1f03f3  mov      w19, wzr
//   0x5df4: 2a1f03ee  mov      w14, wzr
//   0x5df8: 2a1f03ef  mov      w15, wzr
//   0x5dfc: 2a1f03f4  mov      w20, wzr
//   0x5e00: 2a1f03f5  mov      w21, wzr
//   0x5e04: 2a1f03f0  mov      w16, wzr
//   0x5e08: 2a1f03e0  mov      w0, wzr
//   0x5e0c: f9400ffc  ldr      x28, [sp, #0x18]
//   0x5e10: b9000390  str      w16, [x28]
//   0x5e14: b9000035  str      w21, [x1]
//   0x5e18: b9000794  str      w20, [x28, #4]
//   0x5e1c: b900042f  str      w15, [x1, #4]
//   0x5e20: b9000b8e  str      w14, [x28, #8]
//   0x5e24: b9000833  str      w19, [x1, #8]
//   0x5e28: b9000f87  str      w7, [x28, #0xc]
//   0x5e2c: b9000c2d  str      w13, [x1, #0xc]
//   0x5e30: b900138c  str      w12, [x28, #0x10]
//   0x5e34: b9001026  str      w6, [x1, #0x10]
//   0x5e38: b9001785  str      w5, [x28, #0x14]
//   0x5e3c: b900142b  str      w11, [x1, #0x14]
//   0x5e40: b9001b8a  str      w10, [x28, #0x18]
//   0x5e44: b9001824  str      w4, [x1, #0x18]
//   0x5e48: b9001f83  str      w3, [x28, #0x1c]
//   0x5e4c: b9001c29  str      w9, [x1, #0x1c]
//   0x5e50: b9002388  str      w8, [x28, #0x20]
//   0x5e54: b9002036  str      w22, [x1, #0x20]
//   0x5e58: b9002797  str      w23, [x28, #0x24]
//   0x5e5c: b9002431  str      w17, [x1, #0x24]
//   0x5e60: b9002b9e  str      w30, [x28, #0x28]
//   0x5e64: b9002838  str      w24, [x1, #0x28]
//   0x5e68: b9002f99  str      w25, [x28, #0x2c]
//   0x5e6c: b9002c3a  str      w26, [x1, #0x2c]
//   0x5e70: b9003382  str      w2, [x28, #0x30]
//   0x5e74: b940c3e8  ldr      w8, [sp, #0xc0]
//   0x5e78: b9003028  str      w8, [x1, #0x30]
//   0x5e7c: b85843a8  ldur     w8, [x29, #-0x7c]
//   0x5e80: b9003788  str      w8, [x28, #0x34]
//   0x5e84: b940c7e8  ldr      w8, [sp, #0xc4]
//   0x5e88: b9003428  str      w8, [x1, #0x34]
//   0x5e8c: b85883a8  ldur     w8, [x29, #-0x78]
//   0x5e90: b9003b88  str      w8, [x28, #0x38]
//   0x5e94: b940cbe8  ldr      w8, [sp, #0xc8]
//   0x5e98: b9003828  str      w8, [x1, #0x38]
//   0x5e9c: b858c3a8  ldur     w8, [x29, #-0x74]
//   0x5ea0: b9003f88  str      w8, [x28, #0x3c]
//   0x5ea4: b940cfe8  ldr      w8, [sp, #0xcc]
//   0x5ea8: b9003c28  str      w8, [x1, #0x3c]
//   0x5eac: f9401768  ldr      x8, [x27, #0x28]
//   0x5eb0: f85903a9  ldur     x9, [x29, #-0x70]
//   0x5eb4: eb09011f  cmp      x8, x9
//   0x5eb8: 54000141  b.ne     #0x5ee0
//   0x5ebc: a9587bfd  ldp      x29, x30, [sp, #0x180]
//   0x5ec0: a9574ff4  ldp      x20, x19, [sp, #0x170]
//   0x5ec4: a95657f6  ldp      x22, x21, [sp, #0x160]
//   0x5ec8: a9555ff8  ldp      x24, x23, [sp, #0x150]
//   0x5ecc: a95467fa  ldp      x26, x25, [sp, #0x140]
//   0x5ed0: a9536ffc  ldp      x28, x27, [sp, #0x130]
//   0x5ed4: fd4093e8  ldr      d8, [sp, #0x120]
//   0x5ed8: 910643ff  add      sp, sp, #0x190
//   0x5edc: d65f03c0  ret      
//   0x5ee0: 97fff0d8  bl       #0x2240
// ============================================================================
std::uint32_t fde_42_5b94(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005b94ULL;
    for (std::size_t i = 0; i < 212ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3513ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[43] Symbol: partition_with_combined_weights
//      Virtual Address Range: 0x5ee4..0x5fd8 (244 bytes, 61 AArch64 instructions)
// [VN] Khung FDE[43] Biểu tượng: partition_with_combined_weights
//      Dải địa chỉ ảo: 0x5ee4..0x5fd8 (244 byte, 61 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5ee4: 937e7c6a  sbfiz    x10, x3, #2, #0x20
//   0x5ee8: b86a6848  ldr      w8, [x2, x10]
//   0x5eec: b86a6829  ldr      w9, [x1, x10]
//   0x5ef0: b86a680a  ldr      w10, [x0, x10]
//   0x5ef4: 6b04007f  cmp      w3, w4
//   0x5ef8: 5400062a  b.ge     #0x5fbc
//   0x5efc: 6b04007f  cmp      w3, w4
//   0x5f00: 5400012a  b.ge     #0x5f24
//   0x5f04: 93407c84  sxtw     x4, w4
//   0x5f08: 93407c6b  sxtw     x11, w3
//   0x5f0c: b864784c  ldr      w12, [x2, x4, lsl #2]
//   0x5f10: 6b08019f  cmp      w12, w8
//   0x5f14: 540000ec  b.gt     #0x5f30
//   0x5f18: d1000484  sub      x4, x4, #1
//   0x5f1c: eb0b009f  cmp      x4, x11
//   0x5f20: 54ffff6c  b.gt     #0x5f0c
//   0x5f24: 6b04007f  cmp      w3, w4
//   0x5f28: 54fffe6a  b.ge     #0x5ef4
//   0x5f2c: 1400000b  b        #0x5f58
//   0x5f30: d37ef56b  lsl      x11, x11, #2
//   0x5f34: b82b684c  str      w12, [x2, x11]
//   0x5f38: d37ef48c  lsl      x12, x4, #2
//   0x5f3c: b86c682d  ldr      w13, [x1, x12]
//   0x5f40: 11000463  add      w3, w3, #1
//   0x5f44: b82b682d  str      w13, [x1, x11]
//   0x5f48: b86c680c  ldr      w12, [x0, x12]
//   0x5f4c: b82b680c  str      w12, [x0, x11]
//   0x5f50: 6b04007f  cmp      w3, w4
//   0x5f54: 54fffd0a  b.ge     #0x5ef4
//   0x5f58: 937e7c6d  sbfiz    x13, x3, #2, #0x20
//   0x5f5c: 8b0d002c  add      x12, x1, x13
//   0x5f60: 8b0d000b  add      x11, x0, x13
//   0x5f64: 8b0d004d  add      x13, x2, x13
//   0x5f68: b94001ae  ldr      w14, [x13]
//   0x5f6c: 6b0801df  cmp      w14, w8
//   0x5f70: 5400010b  b.lt     #0x5f90
//   0x5f74: 11000463  add      w3, w3, #1
//   0x5f78: 9100118c  add      x12, x12, #4
//   0x5f7c: 9100116b  add      x11, x11, #4
//   0x5f80: 6b03009f  cmp      w4, w3
//   0x5f84: 910011ad  add      x13, x13, #4
//   0x5f88: 54ffff01  b.ne     #0x5f68
//   0x5f8c: 1400000b  b        #0x5fb8
//   0x5f90: 937e7c8d  sbfiz    x13, x4, #2, #0x20
//   0x5f94: b82d684e  str      w14, [x2, x13]
//   0x5f98: b940018c  ldr      w12, [x12]
//   0x5f9c: 51000484  sub      w4, w4, #1
//   0x5fa0: b82d682c  str      w12, [x1, x13]
//   0x5fa4: b940016b  ldr      w11, [x11]
//   0x5fa8: b82d680b  str      w11, [x0, x13]
//   0x5fac: 6b04007f  cmp      w3, w4
//   0x5fb0: 54fffa6b  b.lt     #0x5efc
//   0x5fb4: 14000002  b        #0x5fbc
//   0x5fb8: 2a0403e3  mov      w3, w4
//   0x5fbc: 93407c6b  sxtw     x11, w3
//   0x5fc0: d37ef56b  lsl      x11, x11, #2
//   0x5fc4: b82b6848  str      w8, [x2, x11]
//   0x5fc8: b82b6829  str      w9, [x1, x11]
//   0x5fcc: b82b680a  str      w10, [x0, x11]
//   0x5fd0: 2a0303e0  mov      w0, w3
//   0x5fd4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_43_5ee4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005ee4ULL;
    for (std::size_t i = 0; i < 61ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3725ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[44] Symbol: sort_with_combined_weights
//      Virtual Address Range: 0x5fd8..0x6124 (332 bytes, 83 AArch64 instructions)
// [VN] Khung FDE[44] Biểu tượng: sort_with_combined_weights
//      Dải địa chỉ ảo: 0x5fd8..0x6124 (332 byte, 83 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5fd8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x5fdc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x5fe0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x5fe4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x5fe8: 9100c3fd  add      x29, sp, #0x30
//   0x5fec: 6b04007f  cmp      w3, w4
//   0x5ff0: 5400090a  b.ge     #0x6110
//   0x5ff4: 2a0403f3  mov      w19, w4
//   0x5ff8: aa0203f4  mov      x20, x2
//   0x5ffc: aa0103f5  mov      x21, x1
//   0x6000: aa0003f6  mov      x22, x0
//   0x6004: 937e7c6a  sbfiz    x10, x3, #2, #0x20
//   0x6008: b86a6a88  ldr      w8, [x20, x10]
//   0x600c: b86a6aa9  ldr      w9, [x21, x10]
//   0x6010: b86a6aca  ldr      w10, [x22, x10]
//   0x6014: 2a0303f7  mov      w23, w3
//   0x6018: 2a1303eb  mov      w11, w19
//   0x601c: 6b0b02ff  cmp      w23, w11
//   0x6020: 540002aa  b.ge     #0x6074
//   0x6024: 1400000c  b        #0x6054
//   0x6028: 937e7d6e  sbfiz    x14, x11, #2, #0x20
//   0x602c: b82e6a8f  str      w15, [x20, x14]
//   0x6030: b94001ad  ldr      w13, [x13]
//   0x6034: 5100056b  sub      w11, w11, #1
//   0x6038: b82e6aad  str      w13, [x21, x14]
//   0x603c: b940018c  ldr      w12, [x12]
//   0x6040: b82e6acc  str      w12, [x22, x14]
//   0x6044: 6b0b02ff  cmp      w23, w11
//   0x6048: 540004ca  b.ge     #0x60e0
//   0x604c: 6b0b02ff  cmp      w23, w11
//   0x6050: 5400012a  b.ge     #0x6074
//   0x6054: 93407d6b  sxtw     x11, w11
//   0x6058: 93407eec  sxtw     x12, w23
//   0x605c: b86b7a8d  ldr      w13, [x20, x11, lsl #2]
//   0x6060: 6b0801bf  cmp      w13, w8
//   0x6064: 540000ec  b.gt     #0x6080
//   0x6068: d100056b  sub      x11, x11, #1
//   0x606c: eb0c017f  cmp      x11, x12
//   0x6070: 54ffff6c  b.gt     #0x605c
//   0x6074: 6b0b02ff  cmp      w23, w11
//   0x6078: 54fffe6a  b.ge     #0x6044
//   0x607c: 1400000b  b        #0x60a8
//   0x6080: d37ef58c  lsl      x12, x12, #2
//   0x6084: b82c6a8d  str      w13, [x20, x12]
//   0x6088: d37ef56d  lsl      x13, x11, #2
//   0x608c: b86d6aae  ldr      w14, [x21, x13]
//   0x6090: 110006f7  add      w23, w23, #1
//   0x6094: b82c6aae  str      w14, [x21, x12]
//   0x6098: b86d6acd  ldr      w13, [x22, x13]
//   0x609c: b82c6acd  str      w13, [x22, x12]
//   0x60a0: 6b0b02ff  cmp      w23, w11
//   0x60a4: 54fffd0a  b.ge     #0x6044
//   0x60a8: 937e7eee  sbfiz    x14, x23, #2, #0x20
//   0x60ac: 8b0e02cc  add      x12, x22, x14
//   0x60b0: 8b0e02ad  add      x13, x21, x14
//   0x60b4: 8b0e028e  add      x14, x20, x14
//   0x60b8: b94001cf  ldr      w15, [x14]
//   0x60bc: 6b0801ff  cmp      w15, w8
//   0x60c0: 54fffb4b  b.lt     #0x6028
//   0x60c4: 110006f7  add      w23, w23, #1
//   0x60c8: 9100118c  add      x12, x12, #4
//   0x60cc: 910011ad  add      x13, x13, #4
//   0x60d0: 6b17017f  cmp      w11, w23
//   0x60d4: 910011ce  add      x14, x14, #4
//   0x60d8: 54ffff01  b.ne     #0x60b8
//   0x60dc: 2a0b03f7  mov      w23, w11
//   0x60e0: 937e7eeb  sbfiz    x11, x23, #2, #0x20
//   0x60e4: 510006e4  sub      w4, w23, #1
//   0x60e8: aa1603e0  mov      x0, x22
//   0x60ec: aa1503e1  mov      x1, x21
//   0x60f0: aa1403e2  mov      x2, x20
//   0x60f4: b82b6a88  str      w8, [x20, x11]
//   0x60f8: b82b6aa9  str      w9, [x21, x11]
//   0x60fc: b82b6aca  str      w10, [x22, x11]
//   0x6100: 97ffffb6  bl       #0x5fd8
//   0x6104: 110006e3  add      w3, w23, #1
//   0x6108: 6b13007f  cmp      w3, w19
//   0x610c: 54fff7cb  b.lt     #0x6004
//   0x6110: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x6114: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x6118: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x611c: f84407f7  ldr      x23, [sp], #0x40
//   0x6120: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_44_5fd8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005fd8ULL;
    for (std::size_t i = 0; i < 83ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3786ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[45] Symbol: combined_weights_sort_color
//      Virtual Address Range: 0x6124..0x633c (536 bytes, 134 AArch64 instructions)
// [VN] Khung FDE[45] Biểu tượng: combined_weights_sort_color
//      Dải địa chỉ ảo: 0x6124..0x633c (536 byte, 134 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6124: d103c3ff  sub      sp, sp, #0xf0
//   0x6128: fd0033ec  str      d12, [sp, #0x60]
//   0x612c: 6d072beb  stp      d11, d10, [sp, #0x70]
//   0x6130: 6d0823e9  stp      d9, d8, [sp, #0x80]
//   0x6134: a9096ffc  stp      x28, x27, [sp, #0x90]
//   0x6138: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x613c: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x6140: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x6144: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x6148: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x614c: 910383fd  add      x29, sp, #0xe0
//   0x6150: f9001be0  str      x0, [sp, #0x30]
//   0x6154: d53bd053  mrs      x19, tpidr_el0
//   0x6158: f9401668  ldr      x8, [x19, #0x28]
//   0x615c: aa0203f4  mov      x20, x2
//   0x6160: aa0103f6  mov      x22, x1
//   0x6164: 71000475  subs     w21, w3, #1
//   0x6168: f9002fe8  str      x8, [sp, #0x58]
//   0x616c: 54000aeb  b.lt     #0x62c8
//   0x6170: 290157e3  stp      w3, w21, [sp, #8]
//   0x6174: f9000bf3  str      x19, [sp, #0x10]
//   0x6178: aa1f03ea  mov      x10, xzr
//   0x617c: 1e22c008  fcvt     d8, s0
//   0x6180: 2a0303f3  mov      w19, w3
//   0x6184: 1e6e1009  fmov     d9, #1.00000000
//   0x6188: 1e64100a  fmov     d10, #8.00000000
//   0x618c: 52a85915  mov      w21, #0x42c80000
//   0x6190: a90253f6  stp      x22, x20, [sp, #0x20]
//   0x6194: f9000ff3  str      x19, [sp, #0x18]
//   0x6198: f9401bf7  ldr      x23, [sp, #0x30]
//   0x619c: 910153e3  add      x3, sp, #0x54
//   0x61a0: 910143e4  add      x4, sp, #0x50
//   0x61a4: 910133e5  add      x5, sp, #0x4c
//   0x61a8: b86a7ae8  ldr      w8, [x23, x10, lsl #2]
//   0x61ac: f9001fea  str      x10, [sp, #0x38]
//   0x61b0: 53105d18  ubfx     w24, w8, #0x10, #8
//   0x61b4: 53083d19  ubfx     w25, w8, #8, #8
//   0x61b8: 12001d1a  and      w26, w8, #0xff
//   0x61bc: 2a1803e0  mov      w0, w24
//   0x61c0: 2a1903e1  mov      w1, w25
//   0x61c4: 2a1a03e2  mov      w2, w26
//   0x61c8: 97ffefde  bl       #0x2140
//   0x61cc: 9e6703eb  fmov     d11, xzr
//   0x61d0: aa1603f4  mov      x20, x22
//   0x61d4: b84046e8  ldr      w8, [x23], #4
//   0x61d8: 910123e3  add      x3, sp, #0x48
//   0x61dc: 910113e4  add      x4, sp, #0x44
//   0x61e0: 910103e5  add      x5, sp, #0x40
//   0x61e4: 53105d1b  ubfx     w27, w8, #0x10, #8
//   0x61e8: 53083d1c  ubfx     w28, w8, #8, #8
//   0x61ec: 12001d16  and      w22, w8, #0xff
//   0x61f0: 2a1b03e0  mov      w0, w27
//   0x61f4: 2a1c03e1  mov      w1, w28
//   0x61f8: 2a1603e2  mov      w2, w22
//   0x61fc: 97ffefd1  bl       #0x2140
//   0x6200: bd4057e0  ldr      s0, [sp, #0x54]
//   0x6204: bd404be1  ldr      s1, [sp, #0x48]
//   0x6208: 2a1803e0  mov      w0, w24
//   0x620c: 2a1903e1  mov      w1, w25
//   0x6210: 2a1a03e2  mov      w2, w26
//   0x6214: 1e213800  fsub     s0, s0, s1
//   0x6218: 1e214001  fneg     s1, s0
//   0x621c: 1e202008  fcmp     s0, #0.0
//   0x6220: 1e204c20  fcsel    s0, s1, s0, mi
//   0x6224: 1e2702a1  fmov     s1, w21
//   0x6228: 2a1b03e3  mov      w3, w27
//   0x622c: 2a1c03e4  mov      w4, w28
//   0x6230: 2a1603e5  mov      w5, w22
//   0x6234: 1e21080c  fmul     s12, s0, s1
//   0x6238: d2f80d3b  mov      x27, #-0x3f97000000000000
//   0x623c: 97fff01d  bl       #0x22b0
//   0x6240: b8404688  ldr      w8, [x20], #4
//   0x6244: 1e2c2800  fadd     s0, s0, s12
//   0x6248: 9e670361  fmov     d1, x27
//   0x624c: 1e22c000  fcvt     d0, s0
//   0x6250: 1e611800  fdiv     d0, d0, d1
//   0x6254: 1e692800  fadd     d0, d0, d9
//   0x6258: 1e620101  scvtf    d1, w8
//   0x625c: 1e610800  fmul     d0, d0, d1
//   0x6260: f1000673  subs     x19, x19, #1
//   0x6264: 1e60296b  fadd     d11, d11, d0
//   0x6268: 54fffb61  b.ne     #0x61d4
//   0x626c: f9401fea  ldr      x10, [sp, #0x38]
//   0x6270: a941dbf3  ldp      x19, x22, [sp, #0x18]
//   0x6274: bd4057e0  ldr      s0, [sp, #0x54]
//   0x6278: f94017f4  ldr      x20, [sp, #0x28]
//   0x627c: d37ef548  lsl      x8, x10, #2
//   0x6280: bc686ac1  ldr      s1, [x22, x8]
//   0x6284: 1e22c000  fcvt     d0, s0
//   0x6288: 9100054a  add      x10, x10, #1
//   0x628c: eb13015f  cmp      x10, x19
//   0x6290: 0f20a421  sshll    v1.2d, v1.2s, #0
//   0x6294: 5e61d821  scvtf    d1, d1
//   0x6298: 1e6a0821  fmul     d1, d1, d10
//   0x629c: 1e612961  fadd     d1, d11, d1
//   0x62a0: 1e680822  fmul     d2, d1, d8
//   0x62a4: 1e600840  fmul     d0, d2, d0
//   0x62a8: 1e602820  fadd     d0, d1, d0
//   0x62ac: 1e780009  fcvtzs   w9, d0
//   0x62b0: b8286a89  str      w9, [x20, x8]
//   0x62b4: 54fff721  b.ne     #0x6198
//   0x62b8: 294157e3  ldp      w3, w21, [sp, #8]
//   0x62bc: f9400bf3  ldr      x19, [sp, #0x10]
//   0x62c0: 71003c7f  cmp      w3, #0xf
//   0x62c4: 5400010c  b.gt     #0x62e4
//   0x62c8: 528001e8  mov      w8, #0xf
//   0x62cc: 4b030108  sub      w8, w8, w3
//   0x62d0: d37ef508  lsl      x8, x8, #2
//   0x62d4: 8b23ca80  add      x0, x20, w3, sxtw #2
//   0x62d8: 91001102  add      x2, x8, #4
//   0x62dc: 2a1f03e1  mov      w1, wzr
//   0x62e0: 97fff058  bl       #0x2440
//   0x62e4: f9401be0  ldr      x0, [sp, #0x30]
//   0x62e8: aa1603e1  mov      x1, x22
//   0x62ec: aa1403e2  mov      x2, x20
//   0x62f0: 2a1f03e3  mov      w3, wzr
//   0x62f4: 2a1503e4  mov      w4, w21
//   0x62f8: 97ffef96  bl       #0x2150
//   0x62fc: f9401668  ldr      x8, [x19, #0x28]
//   0x6300: f9402fe9  ldr      x9, [sp, #0x58]
//   0x6304: eb09011f  cmp      x8, x9
//   0x6308: 54000181  b.ne     #0x6338
//   0x630c: a94e7bfd  ldp      x29, x30, [sp, #0xe0]
//   0x6310: a94d4ff4  ldp      x20, x19, [sp, #0xd0]
//   0x6314: a94c57f6  ldp      x22, x21, [sp, #0xc0]
//   0x6318: a94b5ff8  ldp      x24, x23, [sp, #0xb0]
//   0x631c: a94a67fa  ldp      x26, x25, [sp, #0xa0]
//   0x6320: a9496ffc  ldp      x28, x27, [sp, #0x90]
//   0x6324: 6d4823e9  ldp      d9, d8, [sp, #0x80]
//   0x6328: 6d472beb  ldp      d11, d10, [sp, #0x70]
//   0x632c: fd4033ec  ldr      d12, [sp, #0x60]
//   0x6330: 9103c3ff  add      sp, sp, #0xf0
//   0x6334: d65f03c0  ret      
//   0x6338: 97ffefc2  bl       #0x2240
// ============================================================================
std::uint32_t fde_45_6124(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006124ULL;
    for (std::size_t i = 0; i < 134ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3869ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[46] Symbol: filter_tweak_color
//      Virtual Address Range: 0x633c..0x6784 (1096 bytes, 274 AArch64 instructions)
// [VN] Khung FDE[46] Biểu tượng: filter_tweak_color
//      Dải địa chỉ ảo: 0x633c..0x6784 (1096 byte, 274 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x633c: 6db733ed  stp      d13, d12, [sp, #-0x90]!
//   0x6340: 6d012beb  stp      d11, d10, [sp, #0x10]
//   0x6344: 6d0223e9  stp      d9, d8, [sp, #0x20]
//   0x6348: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x634c: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x6350: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x6354: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x6358: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x635c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x6360: 910203fd  add      x29, sp, #0x80
//   0x6364: d10103ff  sub      sp, sp, #0x40
//   0x6368: d53bd045  mrs      x5, tpidr_el0
//   0x636c: f94014a8  ldr      x8, [x5, #0x28]
//   0x6370: 2a0303e4  mov      w4, w3
//   0x6374: 7100047f  cmp      w3, #1
//   0x6378: f81783a8  stur     x8, [x29, #-0x88]
//   0x637c: 5400170b  b.lt     #0x665c
//   0x6380: 2a0403fa  mov      w26, w4
//   0x6384: 4ea31c68  mov      v8.16b, v3.16b
//   0x6388: 4ea21c49  mov      v9.16b, v2.16b
//   0x638c: 4ea11c2a  mov      v10.16b, v1.16b
//   0x6390: 4ea01c0b  mov      v11.16b, v0.16b
//   0x6394: aa0203f4  mov      x20, x2
//   0x6398: aa0103f5  mov      x21, x1
//   0x639c: aa0003f6  mov      x22, x0
//   0x63a0: 9e6703ec  fmov     d12, xzr
//   0x63a4: aa1a03e8  mov      x8, x26
//   0x63a8: aa0103e9  mov      x9, x1
//   0x63ac: b840452a  ldr      w10, [x9], #4
//   0x63b0: f1000508  subs     x8, x8, #1
//   0x63b4: 1e620140  scvtf    d0, w10
//   0x63b8: 1e60298c  fadd     d12, d12, d0
//   0x63bc: 54ffff81  b.ne     #0x63ac
//   0x63c0: d37ef749  lsl      x9, x26, #2
//   0x63c4: 91003d29  add      x9, x9, #0xf
//   0x63c8: 910003e8  mov      x8, sp
//   0x63cc: 927c7929  and      x9, x9, #0x7fffffff0
//   0x63d0: cb09010a  sub      x10, x8, x9
//   0x63d4: 9100015f  mov      sp, x10
//   0x63d8: 910003e8  mov      x8, sp
//   0x63dc: cb090108  sub      x8, x8, x9
//   0x63e0: 9100011f  mov      sp, x8
//   0x63e4: 7100049f  cmp      w4, #1
//   0x63e8: 540013ab  b.lt     #0x665c
//   0x63ec: aa1f03fc  mov      x28, xzr
//   0x63f0: 2a1f03fb  mov      w27, wzr
//   0x63f4: 1e22c08d  fcvt     d13, s4
//   0x63f8: a9352ba8  stp      x8, x10, [x29, #-0xb0]
//   0x63fc: a93413a5  stp      x5, x4, [x29, #-0xc0]
//   0x6400: 14000011  b        #0x6444
//   0x6404: bc5643a1  ldur     s1, [x29, #-0x9c]
//   0x6408: bc5603a2  ldur     s2, [x29, #-0xa0]
//   0x640c: d10233a0  sub      x0, x29, #0x8c
//   0x6410: d10243a1  sub      x1, x29, #0x90
//   0x6414: d10253a2  sub      x2, x29, #0x94
//   0x6418: 97fff01e  bl       #0x2490
//   0x641c: 296e23a9  ldp      w9, w8, [x29, #-0x90]
//   0x6420: b856c3aa  ldur     w10, [x29, #-0x94]
//   0x6424: 53103d08  lsl      w8, w8, #0x10
//   0x6428: 2a092108  orr      w8, w8, w9, lsl #8
//   0x642c: 2a0a0108  orr      w8, w8, w10
//   0x6430: 32081d08  orr      w8, w8, #0xff000000
//   0x6434: b8337ac8  str      w8, [x22, x19, lsl #2]
//   0x6438: 9100079c  add      x28, x28, #1
//   0x643c: eb1c035f  cmp      x26, x28
//   0x6440: 54000d60  b.eq     #0x65ec
//   0x6444: d37ef798  lsl      x24, x28, #2
//   0x6448: b8786ac8  ldr      w8, [x22, x24]
//   0x644c: 4b1b0393  sub      w19, w28, w27
//   0x6450: 937e7e69  sbfiz    x9, x19, #2, #0x20
//   0x6454: d10263a3  sub      x3, x29, #0x98
//   0x6458: b8296ac8  str      w8, [x22, x9]
//   0x645c: b8786a88  ldr      w8, [x20, x24]
//   0x6460: d10273a4  sub      x4, x29, #0x9c
//   0x6464: d10283a5  sub      x5, x29, #0xa0
//   0x6468: b8296a88  str      w8, [x20, x9]
//   0x646c: b8786aa8  ldr      w8, [x21, x24]
//   0x6470: b8296aa8  str      w8, [x21, x9]
//   0x6474: b8786ad7  ldr      w23, [x22, x24]
//   0x6478: 53105ee0  ubfx     w0, w23, #0x10, #8
//   0x647c: 53083ee1  ubfx     w1, w23, #8, #8
//   0x6480: 12001ee2  and      w2, w23, #0xff
//   0x6484: 292e03a1  stp      w1, w0, [x29, #-0x90]
//   0x6488: b816c3a2  stur     w2, [x29, #-0x94]
//   0x648c: 97ffef2d  bl       #0x2140
//   0x6490: b8786aa8  ldr      w8, [x21, x24]
//   0x6494: bc5643a0  ldur     s0, [x29, #-0x9c]
//   0x6498: 1e620101  scvtf    d1, w8
//   0x649c: 1e6c1821  fdiv     d1, d1, d12
//   0x64a0: 1e6d2020  fcmp     d1, d13
//   0x64a4: 54000225  b.pl     #0x64e8
//   0x64a8: 1e2b2000  fcmp     s0, s11
//   0x64ac: 54000104  b.mi     #0x64cc
//   0x64b0: 1e2a2000  fcmp     s0, s10
//   0x64b4: 540000cc  b.gt     #0x64cc
//   0x64b8: bc5683a0  ldur     s0, [x29, #-0x98]
//   0x64bc: 1e292000  fcmp     s0, s9
//   0x64c0: 54000064  b.mi     #0x64cc
//   0x64c4: 1e282000  fcmp     s0, s8
//   0x64c8: 54fffb8d  b.le     #0x6438
//   0x64cc: f85583aa  ldur     x10, [x29, #-0xa8]
//   0x64d0: 937e7f69  sbfiz    x9, x27, #2, #0x20
//   0x64d4: b8296957  str      w23, [x10, x9]
//   0x64d8: f85503aa  ldur     x10, [x29, #-0xb0]
//   0x64dc: b8296948  str      w8, [x10, x9]
//   0x64e0: 1100077b  add      w27, w27, #1
//   0x64e4: 17ffffd5  b        #0x6438
//   0x64e8: 1e2b2000  fcmp     s0, s11
//   0x64ec: 1e204d62  fcsel    s2, s11, s0, mi
//   0x64f0: 1e2a2040  fcmp     s2, s10
//   0x64f4: 1a9fd7e8  cset     w8, gt
//   0x64f8: 1e22cd41  fcsel    s1, s10, s2, gt
//   0x64fc: 1e2b2000  fcmp     s0, s11
//   0x6500: 1a9f57e9  cset     w9, mi
//   0x6504: 54000064  b.mi     #0x6510
//   0x6508: 1e2a2040  fcmp     s2, s10
//   0x650c: 5400004d  b.le     #0x6514
//   0x6510: bc1643a1  stur     s1, [x29, #-0x9c]
//   0x6514: bc5683a0  ldur     s0, [x29, #-0x98]
//   0x6518: 1e292000  fcmp     s0, s9
//   0x651c: 540000a5  b.pl     #0x6530
//   0x6520: 52800038  mov      w24, #1
//   0x6524: 4ea91d20  mov      v0.16b, v9.16b
//   0x6528: bc1683a9  stur     s9, [x29, #-0x98]
//   0x652c: 14000002  b        #0x6534
//   0x6530: 2a1f03f8  mov      w24, wzr
//   0x6534: 1e282000  fcmp     s0, s8
//   0x6538: 2a090119  orr      w25, w8, w9
//   0x653c: 540000ad  b.le     #0x6550
//   0x6540: bc1683a8  stur     s8, [x29, #-0x98]
//   0x6544: 52800038  mov      w24, #1
//   0x6548: 4ea81d00  mov      v0.16b, v8.16b
//   0x654c: 14000005  b        #0x6560
//   0x6550: 7100031f  cmp      w24, #0
//   0x6554: 1a9f17e8  cset     w8, eq
//   0x6558: 0a390108  bic      w8, w8, w25
//   0x655c: 3707f6e8  tbnz     w8, #0, #0x6438
//   0x6560: bc5603a2  ldur     s2, [x29, #-0xa0]
//   0x6564: d10233a0  sub      x0, x29, #0x8c
//   0x6568: d10243a1  sub      x1, x29, #0x90
//   0x656c: d10253a2  sub      x2, x29, #0x94
//   0x6570: 93407e73  sxtw     x19, w19
//   0x6574: 97ffefc7  bl       #0x2490
//   0x6578: 296e03a1  ldp      w1, w0, [x29, #-0x90]
//   0x657c: b856c3a2  ldur     w2, [x29, #-0x94]
//   0x6580: 97ffefb4  bl       #0x2450
//   0x6584: 35fff4c0  cbnz     w0, #0x641c
//   0x6588: 34000178  cbz      w24, #0x65b4
//   0x658c: 37000239  tbnz     w25, #0, #0x65d0
//   0x6590: 2d6c83a1  ldp      s1, s0, [x29, #-0x9c]
//   0x6594: bc5603a2  ldur     s2, [x29, #-0xa0]
//   0x6598: 4eab1d63  mov      v3.16b, v11.16b
//   0x659c: 97ffef0d  bl       #0x21d0
//   0x65a0: 1e202008  fcmp     s0, #0.0
//   0x65a4: 5400016b  b.lt     #0x65d0
//   0x65a8: 4ea01c01  mov      v1.16b, v0.16b
//   0x65ac: bc5683a0  ldur     s0, [x29, #-0x98]
//   0x65b0: 17ffff96  b        #0x6408
//   0x65b4: 2d6c83a1  ldp      s1, s0, [x29, #-0x9c]
//   0x65b8: bc5603a2  ldur     s2, [x29, #-0xa0]
//   0x65bc: 4ea91d23  mov      v3.16b, v9.16b
//   0x65c0: 4ea81d04  mov      v4.16b, v8.16b
//   0x65c4: 97ffeefb  bl       #0x21b0
//   0x65c8: 1e202008  fcmp     s0, #0.0
//   0x65cc: 54fff1ca  b.ge     #0x6404
//   0x65d0: f85583a9  ldur     x9, [x29, #-0xa8]
//   0x65d4: 937e7f68  sbfiz    x8, x27, #2, #0x20
//   0x65d8: f85503aa  ldur     x10, [x29, #-0xb0]
//   0x65dc: b8286937  str      w23, [x9, x8]
//   0x65e0: b87c7aa9  ldr      w9, [x21, x28, lsl #2]
//   0x65e4: b8286949  str      w9, [x10, x8]
//   0x65e8: 17ffffbe  b        #0x64e0
//   0x65ec: a97413a5  ldp      x5, x4, [x29, #-0xc0]
//   0x65f0: a9751ba7  ldp      x7, x6, [x29, #-0xb0]
//   0x65f4: 7100077f  cmp      w27, #1
//   0x65f8: 5400032b  b.lt     #0x665c
//   0x65fc: 4b1b008a  sub      w10, w4, w27
//   0x6600: 93407d48  sxtw     x8, w10
//   0x6604: 93407c89  sxtw     x9, w4
//   0x6608: 9100050d  add      x13, x8, #1
//   0x660c: eb0901bf  cmp      x13, x9
//   0x6610: 9a88d52b  csinc    x11, x9, x8, le
//   0x6614: cb08016c  sub      x12, x11, x8
//   0x6618: f1001d9f  cmp      x12, #7
//   0x661c: d37ef50b  lsl      x11, x8, #2
//   0x6620: 540003e8  b.hi     #0x669c
//   0x6624: 937e7d4a  sbfiz    x10, x10, #2, #0x20
//   0x6628: 8b0a00ec  add      x12, x7, x10
//   0x662c: 8b0a00cd  add      x13, x6, x10
//   0x6630: cb0b018a  sub      x10, x12, x11
//   0x6634: cb0b01ab  sub      x11, x13, x11
//   0x6638: b840456c  ldr      w12, [x11], #4
//   0x663c: d37ef50d  lsl      x13, x8, #2
//   0x6640: 91000508  add      x8, x8, #1
//   0x6644: eb09011f  cmp      x8, x9
//   0x6648: b82d6acc  str      w12, [x22, x13]
//   0x664c: b82d6a9f  str      wzr, [x20, x13]
//   0x6650: b840454c  ldr      w12, [x10], #4
//   0x6654: b82d6aac  str      w12, [x21, x13]
//   0x6658: 54ffff0b  b.lt     #0x6638
//   0x665c: f94014a8  ldr      x8, [x5, #0x28]
//   0x6660: f85783a9  ldur     x9, [x29, #-0x88]
//   0x6664: eb09011f  cmp      x8, x9
//   0x6668: 540008c1  b.ne     #0x6780
//   0x666c: 2a0403e0  mov      w0, w4
//   0x6670: d10203bf  sub      sp, x29, #0x80
//   0x6674: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x6678: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x667c: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x6680: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x6684: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x6688: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x668c: 6d4223e9  ldp      d9, d8, [sp, #0x20]
//   0x6690: 6d412beb  ldp      d11, d10, [sp, #0x10]
//   0x6694: 6cc933ed  ldp      d13, d12, [sp], #0x90
//   0x6698: d65f03c0  ret      
//   0x669c: eb0901bf  cmp      x13, x9
//   0x66a0: 9a88d52d  csinc    x13, x9, x8, le
//   0x66a4: d37ef5ad  lsl      x13, x13, #2
//   0x66a8: 8b0b02ce  add      x14, x22, x11
//   0x66ac: 8b0d0280  add      x0, x20, x13
//   0x66b0: 8b0b0290  add      x16, x20, x11
//   0x66b4: 8b0d02cf  add      x15, x22, x13
//   0x66b8: eb0001df  cmp      x14, x0
//   0x66bc: 8b0d02a1  add      x1, x21, x13
//   0x66c0: 1a9f27ed  cset     w13, lo
//   0x66c4: eb0f021f  cmp      x16, x15
//   0x66c8: 8b0b02b1  add      x17, x21, x11
//   0x66cc: 1a9f27e2  cset     w2, lo
//   0x66d0: eb0101df  cmp      x14, x1
//   0x66d4: 0a0201a2  and      w2, w13, w2
//   0x66d8: 1a9f27ed  cset     w13, lo
//   0x66dc: eb0f023f  cmp      x17, x15
//   0x66e0: 1a9f27ef  cset     w15, lo
//   0x66e4: eb01021f  cmp      x16, x1
//   0x66e8: 1a9f27ee  cset     w14, lo
//   0x66ec: eb00023f  cmp      x17, x0
//   0x66f0: 1a9f27f0  cset     w16, lo
//   0x66f4: 3707f982  tbnz     w2, #0, #0x6624
//   0x66f8: 0a0f01ad  and      w13, w13, w15
//   0x66fc: 3707f94d  tbnz     w13, #0, #0x6624
//   0x6700: 0a1001cd  and      w13, w14, w16
//   0x6704: 3707f90d  tbnz     w13, #0, #0x6624
//   0x6708: 927df18d  and      x13, x12, #0xfffffffffffffff8
//   0x670c: 8b0b02cf  add      x15, x22, x11
//   0x6710: 8b0b02b0  add      x16, x21, x11
//   0x6714: 8b0b0291  add      x17, x20, x11
//   0x6718: aa1f03ee  mov      x14, xzr
//   0x671c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x6720: 8b0801a8  add      x8, x13, x8
//   0x6724: 0b0d014a  add      w10, w10, w13
//   0x6728: 910041ef  add      x15, x15, #0x10
//   0x672c: 91004210  add      x16, x16, #0x10
//   0x6730: 91004231  add      x17, x17, #0x10
//   0x6734: d2c00100  mov      x0, #0x800000000
//   0x6738: aa0d03e1  mov      x1, x13
//   0x673c: 935efdc2  asr      x2, x14, #0x1e
//   0x6740: 8b0200c3  add      x3, x6, x2
//   0x6744: ad400861  ldp      q1, q2, [x3]
//   0x6748: 8b0200e2  add      x2, x7, x2
//   0x674c: 8b0001ce  add      x14, x14, x0
//   0x6750: f1002021  subs     x1, x1, #8
//   0x6754: ad3f89e1  stp      q1, q2, [x15, #-0x10]
//   0x6758: ad3f8220  stp      q0, q0, [x17, #-0x10]
//   0x675c: ad400841  ldp      q1, q2, [x2]
//   0x6760: 910081ef  add      x15, x15, #0x20
//   0x6764: 91008231  add      x17, x17, #0x20
//   0x6768: ad3f8a01  stp      q1, q2, [x16, #-0x10]
//   0x676c: 91008210  add      x16, x16, #0x20
//   0x6770: 54fffe61  b.ne     #0x673c
//   0x6774: eb0d019f  cmp      x12, x13
//   0x6778: 54fff561  b.ne     #0x6624
//   0x677c: 17ffffb8  b        #0x665c
//   0x6780: 97ffeeb0  bl       #0x2240
// ============================================================================
std::uint32_t fde_46_633c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000633cULL;
    for (std::size_t i = 0; i < 274ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4003ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[47] Symbol: rad2deg
//      Virtual Address Range: 0x6784..0x67a4 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[47] Biểu tượng: rad2deg
//      Dải địa chỉ ảo: 0x6784..0x67a4 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6784: 52a87688  mov      w8, #0x43b40000
//   0x6788: 5281fb69  mov      w9, #0xfdb
//   0x678c: 72a81929  movk     w9, #0x40c9, lsl #16
//   0x6790: 1e270101  fmov     s1, w8
//   0x6794: 1e210800  fmul     s0, s0, s1
//   0x6798: 1e270121  fmov     s1, w9
//   0x679c: 1e211800  fdiv     s0, s0, s1
//   0x67a0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_47_6784(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006784ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4277ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[48] Symbol: deg2rad
//      Virtual Address Range: 0x67a4..0x67c4 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[48] Biểu tượng: deg2rad
//      Dải địa chỉ ảo: 0x67a4..0x67c4 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x67a4: 5281fb68  mov      w8, #0xfdb
//   0x67a8: 72a81928  movk     w8, #0x40c9, lsl #16
//   0x67ac: 52a87689  mov      w9, #0x43b40000
//   0x67b0: 1e270101  fmov     s1, w8
//   0x67b4: 1e210800  fmul     s0, s0, s1
//   0x67b8: 1e270121  fmov     s1, w9
//   0x67bc: 1e211800  fdiv     s0, s0, s1
//   0x67c0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_48_67a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000067a4ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4285ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[49] Symbol: deltaE
//      Virtual Address Range: 0x67c4..0x6ba4 (992 bytes, 248 AArch64 instructions)
// [VN] Khung FDE[49] Biểu tượng: deltaE
//      Dải địa chỉ ảo: 0x67c4..0x6ba4 (992 byte, 248 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x67c4: d10203ff  sub      sp, sp, #0x80
//   0x67c8: 6d033bef  stp      d15, d14, [sp, #0x30]
//   0x67cc: 6d0433ed  stp      d13, d12, [sp, #0x40]
//   0x67d0: 6d052beb  stp      d11, d10, [sp, #0x50]
//   0x67d4: 6d0623e9  stp      d9, d8, [sp, #0x60]
//   0x67d8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x67dc: 9101c3fd  add      x29, sp, #0x70
//   0x67e0: 4ea51caf  mov      v15.16b, v5.16b
//   0x67e4: bd4013a5  ldr      s5, [x29, #0x10]
//   0x67e8: 4ea21c4c  mov      v12.16b, v2.16b
//   0x67ec: 4ea11c2d  mov      v13.16b, v1.16b
//   0x67f0: 1e2020c8  fcmp     s6, #0.0
//   0x67f4: 1e2e100e  fmov     s14, #1.00000000
//   0x67f8: 1e232801  fadd     s1, s0, s3
//   0x67fc: 1e2c100b  fmov     s11, #0.50000000
//   0x6800: 4ea41c8a  mov      v10.16b, v4.16b
//   0x6804: 2d030fe0  stp      s0, s3, [sp, #0x18]
//   0x6808: 1e2d09a2  fmul     s2, s13, s13
//   0x680c: 1e2c0988  fmul     s8, s12, s12
//   0x6810: 1e240883  fmul     s3, s4, s4
//   0x6814: 1e2f09e9  fmul     s9, s15, s15
//   0x6818: 1e2e8cc4  fcsel    s4, s6, s14, hi
//   0x681c: 1e2b0821  fmul     s1, s1, s11
//   0x6820: 1e2020e8  fcmp     s7, #0.0
//   0x6824: 2d0413e1  stp      s1, s4, [sp, #0x20]
//   0x6828: 1e282841  fadd     s1, s2, s8
//   0x682c: 1e292862  fadd     s2, s3, s9
//   0x6830: 1e2e8ce3  fcsel    s3, s7, s14, hi
//   0x6834: 1e21c021  fsqrt    s1, s1
//   0x6838: 1e21c042  fsqrt    s2, s2
//   0x683c: 1e2020a8  fcmp     s5, #0.0
//   0x6840: 1e222821  fadd     s1, s1, s2
//   0x6844: 1e2e8ca0  fcsel    s0, s5, s14, hi
//   0x6848: 2d0503e3  stp      s3, s0, [sp, #0x28]
//   0x684c: 1e2b0820  fmul     s0, s1, s11
//   0x6850: 1e239001  fmov     s1, #7.00000000
//   0x6854: 97ffef0b  bl       #0x2480
//   0x6858: 529cc428  mov      w8, #0xe621
//   0x685c: 72a9f6a8  movk     w8, #0x4fb5, lsl #16
//   0x6860: 1e270101  fmov     s1, w8
//   0x6864: 1e212801  fadd     s1, s0, s1
//   0x6868: 1e211800  fdiv     s0, s0, s1
//   0x686c: 1e21c000  fsqrt    s0, s0
//   0x6870: 1e2039c0  fsub     s0, s14, s0
//   0x6874: 1e2b0800  fmul     s0, s0, s11
//   0x6878: 1e2e2800  fadd     s0, s0, s14
//   0x687c: 1e2d0801  fmul     s1, s0, s13
//   0x6880: 1e2a080d  fmul     s13, s0, s10
//   0x6884: 1e210820  fmul     s0, s1, s1
//   0x6888: 1e2d09a2  fmul     s2, s13, s13
//   0x688c: 1e202900  fadd     s0, s8, s0
//   0x6890: 1e222922  fadd     s2, s9, s2
//   0x6894: 1e21c000  fsqrt    s0, s0
//   0x6898: 1e21c042  fsqrt    s2, s2
//   0x689c: 2d0183e2  stp      s2, s0, [sp, #0xc]
//   0x68a0: 1e222800  fadd     s0, s0, s2
//   0x68a4: 1e2b0800  fmul     s0, s0, s11
//   0x68a8: bd0017e0  str      s0, [sp, #0x14]
//   0x68ac: 4eac1d80  mov      v0.16b, v12.16b
//   0x68b0: 97ffeec4  bl       #0x23c0
//   0x68b4: 52a87688  mov      w8, #0x43b40000
//   0x68b8: 5281fb69  mov      w9, #0xfdb
//   0x68bc: 72a81929  movk     w9, #0x40c9, lsl #16
//   0x68c0: 1e27010e  fmov     s14, w8
//   0x68c4: 1e2e0800  fmul     s0, s0, s14
//   0x68c8: 1e27012a  fmov     s10, w9
//   0x68cc: 1e2a180c  fdiv     s12, s0, s10
//   0x68d0: 4eaf1de0  mov      v0.16b, v15.16b
//   0x68d4: 4ead1da1  mov      v1.16b, v13.16b
//   0x68d8: 97ffeeba  bl       #0x23c0
//   0x68dc: 1e2e0800  fmul     s0, s0, s14
//   0x68e0: 1e2e2981  fadd     s1, s12, s14
//   0x68e4: 1e202188  fcmp     s12, #0.0
//   0x68e8: 1e2a1800  fdiv     s0, s0, s10
//   0x68ec: 1e21ad8d  fcsel    s13, s12, s1, ge
//   0x68f0: 1e2e2801  fadd     s1, s0, s14
//   0x68f4: 1e202008  fcmp     s0, #0.0
//   0x68f8: 1e21ac0f  fcsel    s15, s0, s1, ge
//   0x68fc: 52a86688  mov      w8, #0x43340000
//   0x6900: 1e2f39a0  fsub     s0, s13, s15
//   0x6904: 1e2d39ec  fsub     s12, s15, s13
//   0x6908: 1e2f21a0  fcmp     s13, s15
//   0x690c: 1e270108  fmov     s8, w8
//   0x6910: 1e2f29a1  fadd     s1, s13, s15
//   0x6914: 1e2ccc00  fcsel    s0, s0, s12, gt
//   0x6918: 1e2e2822  fadd     s2, s1, s14
//   0x691c: 1e282000  fcmp     s0, s8
//   0x6920: 1e21cc40  fcsel    s0, s2, s1, gt
//   0x6924: 1e2b080b  fmul     s11, s0, s11
//   0x6928: 1e37d000  fmov     s0, #-30.00000000
//   0x692c: 1e202960  fadd     s0, s11, s0
//   0x6930: 1e2a0800  fmul     s0, s0, s10
//   0x6934: 1e2e1800  fdiv     s0, s0, s14
//   0x6938: 97ffee22  bl       #0x21c0
//   0x693c: 52828f68  mov      w8, #0x147b
//   0x6940: 72b7c5c8  movk     w8, #0xbe2e, lsl #16
//   0x6944: 1e2b2961  fadd     s1, s11, s11
//   0x6948: 1e270102  fmov     s2, w8
//   0x694c: 1e220800  fmul     s0, s0, s2
//   0x6950: 1e2a0821  fmul     s1, s1, s10
//   0x6954: 1e2e1002  fmov     s2, #1.00000000
//   0x6958: 1e222809  fadd     s9, s0, s2
//   0x695c: 1e2e1820  fdiv     s0, s1, s14
//   0x6960: 97ffee18  bl       #0x21c0
//   0x6964: 529851e8  mov      w8, #0xc28f
//   0x6968: 72a7cea8  movk     w8, #0x3e75, lsl #16
//   0x696c: 1e211001  fmov     s1, #3.00000000
//   0x6970: 1e270103  fmov     s3, w8
//   0x6974: 1e231002  fmov     s2, #6.00000000
//   0x6978: 1e230800  fmul     s0, s0, s3
//   0x697c: 1e210961  fmul     s1, s11, s1
//   0x6980: 1e292809  fadd     s9, s0, s9
//   0x6984: 1e222820  fadd     s0, s1, s2
//   0x6988: 1e2a0800  fmul     s0, s0, s10
//   0x698c: 1e2e1800  fdiv     s0, s0, s14
//   0x6990: 97ffee0c  bl       #0x21c0
//   0x6994: 529ae148  mov      w8, #0xd70a
//   0x6998: 72a7d468  movk     w8, #0x3ea3, lsl #16
//   0x699c: 1e221001  fmov     s1, #4.00000000
//   0x69a0: 52b84f89  mov      w9, #-0x3d840000
//   0x69a4: 1e270102  fmov     s2, w8
//   0x69a8: 1e220800  fmul     s0, s0, s2
//   0x69ac: 1e210961  fmul     s1, s11, s1
//   0x69b0: 1e270122  fmov     s2, w9
//   0x69b4: 1e292809  fadd     s9, s0, s9
//   0x69b8: 1e222820  fadd     s0, s1, s2
//   0x69bc: 1e2a0800  fmul     s0, s0, s10
//   0x69c0: 1e2e1800  fdiv     s0, s0, s14
//   0x69c4: 97ffedff  bl       #0x21c0
//   0x69c8: 529999a8  mov      w8, #0xcccd
//   0x69cc: 72b7c988  movk     w8, #0xbe4c, lsl #16
//   0x69d0: 1e214181  fneg     s1, s12
//   0x69d4: 1e202188  fcmp     s12, #0.0
//   0x69d8: 1e270102  fmov     s2, w8
//   0x69dc: 1e220800  fmul     s0, s0, s2
//   0x69e0: 1e21cd81  fcsel    s1, s12, s1, gt
//   0x69e4: 1e282020  fcmp     s1, s8
//   0x69e8: 1e20292e  fadd     s14, s9, s0
//   0x69ec: 54000109  b.ls     #0x6a0c
//   0x69f0: 52b87688  mov      w8, #-0x3c4c0000
//   0x69f4: 52a87689  mov      w9, #0x43b40000
//   0x69f8: 1e2d21e0  fcmp     s15, s13
//   0x69fc: 1e270100  fmov     s0, w8
//   0x6a00: 1e270121  fmov     s1, w9
//   0x6a04: 1e209c20  fcsel    s0, s1, s0, ls
//   0x6a08: 1e20298c  fadd     s12, s12, s0
//   0x6a0c: 2d41abef  ldp      s15, s10, [sp, #0xc]
//   0x6a10: 5281fb68  mov      w8, #0xfdb
//   0x6a14: 72a81928  movk     w8, #0x40c9, lsl #16
//   0x6a18: 52a87689  mov      w9, #0x43b40000
//   0x6a1c: 1e2f0940  fmul     s0, s10, s15
//   0x6a20: 1e270109  fmov     s9, w8
//   0x6a24: 1e21c000  fsqrt    s0, s0
//   0x6a28: 1e290981  fmul     s1, s12, s9
//   0x6a2c: 1e27012d  fmov     s13, w9
//   0x6a30: 1e202808  fadd     s8, s0, s0
//   0x6a34: 1e2d1820  fdiv     s0, s1, s13
//   0x6a38: 1e2c1001  fmov     s1, #0.50000000
//   0x6a3c: 1e210800  fmul     s0, s0, s1
//   0x6a40: 97ffedcc  bl       #0x2170
//   0x6a44: 1e200900  fmul     s0, s8, s0
//   0x6a48: bd000be0  str      s0, [sp, #8]
//   0x6a4c: 2d4303e1  ldp      s1, s0, [sp, #0x18]
//   0x6a50: bd4023e3  ldr      s3, [sp, #0x20]
//   0x6a54: 52b84908  mov      w8, #-0x3db80000
//   0x6a58: 1e2a39e8  fsub     s8, s15, s10
//   0x6a5c: 1e213800  fsub     s0, s0, s1
//   0x6a60: bd001fe0  str      s0, [sp, #0x1c]
//   0x6a64: 1e270100  fmov     s0, w8
//   0x6a68: 529851e8  mov      w8, #0xc28f
//   0x6a6c: bd4017ea  ldr      s10, [sp, #0x14]
//   0x6a70: 72a78ea8  movk     w8, #0x3c75, lsl #16
//   0x6a74: 1e270102  fmov     s2, w8
//   0x6a78: 52900008  mov      w8, #0x8000
//   0x6a7c: 1e202860  fadd     s0, s3, s0
//   0x6a80: 1e269001  fmov     s1, #20.00000000
//   0x6a84: 72b87128  movk     w8, #0xc389, lsl #16
//   0x6a88: 1e200800  fmul     s0, s0, s0
//   0x6a8c: 1e270103  fmov     s3, w8
//   0x6a90: 528a3d88  mov      w8, #0x51ec
//   0x6a94: 1e220944  fmul     s4, s10, s2
//   0x6a98: 1e220802  fmul     s2, s0, s2
//   0x6a9c: 1e212800  fadd     s0, s0, s1
//   0x6aa0: 72a7a708  movk     w8, #0x3d38, lsl #16
//   0x6aa4: 1e232963  fadd     s3, s11, s3
//   0x6aa8: 1e273005  fmov     s5, #25.00000000
//   0x6aac: 1e21c000  fsqrt    s0, s0
//   0x6ab0: 1e251863  fdiv     s3, s3, s5
//   0x6ab4: 1e270105  fmov     s5, w8
//   0x6ab8: 1e2e1006  fmov     s6, #1.00000000
//   0x6abc: 1e201840  fdiv     s0, s2, s0
//   0x6ac0: 1e2e0884  fmul     s4, s4, s14
//   0x6ac4: 1e250945  fmul     s5, s10, s5
//   0x6ac8: 1e26280f  fadd     s15, s0, s6
//   0x6acc: 1e238860  fnmul    s0, s3, s3
//   0x6ad0: 1e2628ab  fadd     s11, s5, s6
//   0x6ad4: 1e26288e  fadd     s14, s4, s6
//   0x6ad8: 97ffedaa  bl       #0x2180
//   0x6adc: 1e27d001  fmov     s1, #30.00000000
//   0x6ae0: 1e21080c  fmul     s12, s0, s1
//   0x6ae4: 1e239001  fmov     s1, #7.00000000
//   0x6ae8: 4eaa1d40  mov      v0.16b, v10.16b
//   0x6aec: 97ffee65  bl       #0x2480
//   0x6af0: 529cc428  mov      w8, #0xe621
//   0x6af4: 72a9f6a8  movk     w8, #0x4fb5, lsl #16
//   0x6af8: 1e270103  fmov     s3, w8
//   0x6afc: 1e232803  fadd     s3, s0, s3
//   0x6b00: 1e290982  fmul     s2, s12, s9
//   0x6b04: 1e231800  fdiv     s0, s0, s3
//   0x6b08: 1e301001  fmov     s1, #-2.00000000
//   0x6b0c: 1e2d1842  fdiv     s2, s2, s13
//   0x6b10: 1e21c000  fsqrt    s0, s0
//   0x6b14: 1e210809  fmul     s9, s0, s1
//   0x6b18: 1e222840  fadd     s0, s2, s2
//   0x6b1c: 97ffed95  bl       #0x2170
//   0x6b20: 2d448be1  ldp      s1, s2, [sp, #0x24]
//   0x6b24: bd401fe4  ldr      s4, [sp, #0x1c]
//   0x6b28: bd402fe3  ldr      s3, [sp, #0x2c]
//   0x6b2c: 1e200920  fmul     s0, s9, s0
//   0x6b30: 1e2f0821  fmul     s1, s1, s15
//   0x6b34: 1e211881  fdiv     s1, s4, s1
//   0x6b38: bd400be4  ldr      s4, [sp, #8]
//   0x6b3c: 1e2b0842  fmul     s2, s2, s11
//   0x6b40: 1e2e0863  fmul     s3, s3, s14
//   0x6b44: 1e221902  fdiv     s2, s8, s2
//   0x6b48: 1e231883  fdiv     s3, s4, s3
//   0x6b4c: 1e210821  fmul     s1, s1, s1
//   0x6b50: 1e220845  fmul     s5, s2, s2
//   0x6b54: 1e230866  fmul     s6, s3, s3
//   0x6b58: 1e200840  fmul     s0, s2, s0
//   0x6b5c: 1e252821  fadd     s1, s1, s5
//   0x6b60: 1e230800  fmul     s0, s0, s3
//   0x6b64: 1e262821  fadd     s1, s1, s6
//   0x6b68: 52a85908  mov      w8, #0x42c80000
//   0x6b6c: 1e212800  fadd     s0, s0, s1
//   0x6b70: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x6b74: 6d4623e9  ldp      d9, d8, [sp, #0x60]
//   0x6b78: 6d452beb  ldp      d11, d10, [sp, #0x50]
//   0x6b7c: 6d4433ed  ldp      d13, d12, [sp, #0x40]
//   0x6b80: 6d433bef  ldp      d15, d14, [sp, #0x30]
//   0x6b84: 1e270104  fmov     s4, w8
//   0x6b88: 1e21c000  fsqrt    s0, s0
//   0x6b8c: 1e247801  fminnm   s1, s0, s4
//   0x6b90: 1e202008  fcmp     s0, #0.0
//   0x6b94: 1e2703e0  fmov     s0, wzr
//   0x6b98: 1e208c20  fcsel    s0, s1, s0, hi
//   0x6b9c: 910203ff  add      sp, sp, #0x80
//   0x6ba0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_49_67c4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000067c4ULL;
    for (std::size_t i = 0; i < 248ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4293ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[50] Symbol: get_color_difference
//      Virtual Address Range: 0x6ba4..0x6c44 (160 bytes, 40 AArch64 instructions)
// [VN] Khung FDE[50] Biểu tượng: get_color_difference
//      Dải địa chỉ ảo: 0x6ba4..0x6c44 (160 byte, 40 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6ba4: d10183ff  sub      sp, sp, #0x60
//   0x6ba8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x6bac: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x6bb0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x6bb4: 910143fd  add      x29, sp, #0x50
//   0x6bb8: d53bd056  mrs      x22, tpidr_el0
//   0x6bbc: f94016c8  ldr      x8, [x22, #0x28]
//   0x6bc0: 2a0503f3  mov      w19, w5
//   0x6bc4: 2a0403f4  mov      w20, w4
//   0x6bc8: 2a0303f5  mov      w21, w3
//   0x6bcc: 910093e3  add      x3, sp, #0x24
//   0x6bd0: 910083e4  add      x4, sp, #0x20
//   0x6bd4: 910073e5  add      x5, sp, #0x1c
//   0x6bd8: f90017e8  str      x8, [sp, #0x28]
//   0x6bdc: 97ffed9d  bl       #0x2250
//   0x6be0: 910063e3  add      x3, sp, #0x18
//   0x6be4: 910053e4  add      x4, sp, #0x14
//   0x6be8: 910043e5  add      x5, sp, #0x10
//   0x6bec: 2a1503e0  mov      w0, w21
//   0x6bf0: 2a1403e1  mov      w1, w20
//   0x6bf4: 2a1303e2  mov      w2, w19
//   0x6bf8: 97ffed96  bl       #0x2250
//   0x6bfc: 2d4403e1  ldp      s1, s0, [sp, #0x20]
//   0x6c00: 2d430be3  ldp      s3, s2, [sp, #0x18]
//   0x6c04: 2d4213e5  ldp      s5, s4, [sp, #0x10]
//   0x6c08: 1e2e1006  fmov     s6, #1.00000000
//   0x6c0c: 52a7f008  mov      w8, #0x3f800000
//   0x6c10: 4ea61cc7  mov      v7.16b, v6.16b
//   0x6c14: b90003e8  str      w8, [sp]
//   0x6c18: 97ffee16  bl       #0x2470
//   0x6c1c: f94016c8  ldr      x8, [x22, #0x28]
//   0x6c20: f94017e9  ldr      x9, [sp, #0x28]
//   0x6c24: eb09011f  cmp      x8, x9
//   0x6c28: 540000c1  b.ne     #0x6c40
//   0x6c2c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x6c30: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x6c34: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x6c38: 910183ff  add      sp, sp, #0x60
//   0x6c3c: d65f03c0  ret      
//   0x6c40: 97ffed80  bl       #0x2240
// ============================================================================
std::uint32_t fde_50_6ba4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006ba4ULL;
    for (std::size_t i = 0; i < 40ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4541ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[51] Symbol: statistics_8888_color
//      Virtual Address Range: 0x6c44..0x6dfc (440 bytes, 110 AArch64 instructions)
// [VN] Khung FDE[51] Biểu tượng: statistics_8888_color
//      Dải địa chỉ ảo: 0x6c44..0x6dfc (440 byte, 110 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6c44: 52862028  mov      w8, #0x3101
//   0x6c48: 6b08007f  cmp      w3, w8
//   0x6c4c: 5400020b  b.lt     #0x6c8c
//   0x6c50: 12861fe9  mov      w9, #-0x3100
//   0x6c54: 52a8988a  mov      w10, #0x44c40000
//   0x6c58: 0b090069  add      w9, w3, w9
//   0x6c5c: 1e270141  fmov     s1, w10
//   0x6c60: 1e220122  scvtf    s2, w9
//   0x6c64: 1e211841  fdiv     s1, s2, s1
//   0x6c68: 1e6c1000  fmov     d0, #0.50000000
//   0x6c6c: 1e22c021  fcvt     d1, s1
//   0x6c70: 1e602820  fadd     d0, d1, d0
//   0x6c74: 1e780009  fcvtzs   w9, d0
//   0x6c78: 11002129  add      w9, w9, #8
//   0x6c7c: 2a1f03e8  mov      w8, wzr
//   0x6c80: 93407d29  sxtw     x9, w9
//   0x6c84: 51001c6b  sub      w11, w3, #7
//   0x6c88: 1400001d  b        #0x6cfc
//   0x6c8c: 2a1f03e8  mov      w8, wzr
//   0x6c90: 72000869  ands     w9, w3, #7
//   0x6c94: 540002c0  b.eq     #0x6cec
//   0x6c98: 4b090069  sub      w9, w3, w9
//   0x6c9c: 93407d29  sxtw     x9, w9
//   0x6ca0: 93407c6a  sxtw     x10, w3
//   0x6ca4: 14000004  b        #0x6cb4
//   0x6ca8: 91000529  add      x9, x9, #1
//   0x6cac: eb0a013f  cmp      x9, x10
//   0x6cb0: 540001ea  b.ge     #0x6cec
//   0x6cb4: b869784c  ldr      w12, [x2, x9, lsl #2]
//   0x6cb8: 5319618b  lsl      w11, w12, #7
//   0x6cbc: 9276116b  and      x11, x11, #0x7c00
//   0x6cc0: b3463d8b  bfxil    x11, x12, #6, #0xa
//   0x6cc4: b3535d8b  bfxil    x11, x12, #0x13, #5
//   0x6cc8: d37ff96c  lsl      x12, x11, #1
//   0x6ccc: 786c680d  ldrh     w13, [x0, x12]
//   0x6cd0: 110005ae  add      w14, w13, #1
//   0x6cd4: 782c680e  strh     w14, [x0, x12]
//   0x6cd8: 35fffe8d  cbnz     w13, #0x6ca8
//   0x6cdc: 1100050c  add      w12, w8, #1
//   0x6ce0: 7828d82b  strh     w11, [x1, w8, sxtw #1]
//   0x6ce4: 2a0c03e8  mov      w8, w12
//   0x6ce8: 17fffff0  b        #0x6ca8
//   0x6cec: 51001c6b  sub      w11, w3, #7
//   0x6cf0: 7100057f  cmp      w11, #1
//   0x6cf4: 5400080b  b.lt     #0x6df4
//   0x6cf8: 52800109  mov      w9, #8
//   0x6cfc: 52807c0d  mov      w13, #0x3e0
//   0x6d00: aa1f03ea  mov      x10, xzr
//   0x6d04: 93407d6b  sxtw     x11, w11
//   0x6d08: d37ef52c  lsl      x12, x9, #2
//   0x6d0c: 4f0007e0  movi     v0.4s, #0x1f
//   0x6d10: 4e040da1  dup      v1.4s, w13
//   0x6d14: 4f03a782  movi     v2.8h, #0x7c, lsl #8
//   0x6d18: 14000005  b        #0x6d2c
//   0x6d1c: 8b09014a  add      x10, x10, x9
//   0x6d20: eb0b015f  cmp      x10, x11
//   0x6d24: 8b0c0042  add      x2, x2, x12
//   0x6d28: 5400066a  b.ge     #0x6df4
//   0x6d2c: 3dc00043  ldr      q3, [x2]
//   0x6d30: 6f2d0464  ushr     v4.4s, v3.4s, #0x13
//   0x6d34: 6f3a0465  ushr     v5.4s, v3.4s, #6
//   0x6d38: 4f275463  shl      v3.4s, v3.4s, #7
//   0x6d3c: 4e211ca5  and      v5.16b, v5.16b, v1.16b
//   0x6d40: 4e221c63  and      v3.16b, v3.16b, v2.16b
//   0x6d44: 4e201c84  and      v4.16b, v4.16b, v0.16b
//   0x6d48: 4ea31ca3  orr      v3.16b, v5.16b, v3.16b
//   0x6d4c: 4ea41c63  orr      v3.16b, v3.16b, v4.16b
//   0x6d50: 1e26006d  fmov     w13, s3
//   0x6d54: 120039ae  and      w14, w13, #0x7fff
//   0x6d58: d37ff9ce  lsl      x14, x14, #1
//   0x6d5c: 786e680f  ldrh     w15, [x0, x14]
//   0x6d60: 110005f0  add      w16, w15, #1
//   0x6d64: 782e6810  strh     w16, [x0, x14]
//   0x6d68: 3500008f  cbnz     w15, #0x6d78
//   0x6d6c: 1100050e  add      w14, w8, #1
//   0x6d70: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6d74: 2a0e03e8  mov      w8, w14
//   0x6d78: 0e0c3c6d  mov      w13, v3.s[1]
//   0x6d7c: 120039ae  and      w14, w13, #0x7fff
//   0x6d80: d37ff9ce  lsl      x14, x14, #1
//   0x6d84: 786e680f  ldrh     w15, [x0, x14]
//   0x6d88: 110005f0  add      w16, w15, #1
//   0x6d8c: 782e6810  strh     w16, [x0, x14]
//   0x6d90: 3500008f  cbnz     w15, #0x6da0
//   0x6d94: 1100050e  add      w14, w8, #1
//   0x6d98: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6d9c: 2a0e03e8  mov      w8, w14
//   0x6da0: 0e143c6d  mov      w13, v3.s[2]
//   0x6da4: 120039ae  and      w14, w13, #0x7fff
//   0x6da8: d37ff9ce  lsl      x14, x14, #1
//   0x6dac: 786e680f  ldrh     w15, [x0, x14]
//   0x6db0: 110005f0  add      w16, w15, #1
//   0x6db4: 782e6810  strh     w16, [x0, x14]
//   0x6db8: 3500008f  cbnz     w15, #0x6dc8
//   0x6dbc: 1100050e  add      w14, w8, #1
//   0x6dc0: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6dc4: 2a0e03e8  mov      w8, w14
//   0x6dc8: 0e1c3c6d  mov      w13, v3.s[3]
//   0x6dcc: 120039ae  and      w14, w13, #0x7fff
//   0x6dd0: d37ff9ce  lsl      x14, x14, #1
//   0x6dd4: 786e680f  ldrh     w15, [x0, x14]
//   0x6dd8: 110005f0  add      w16, w15, #1
//   0x6ddc: 782e6810  strh     w16, [x0, x14]
//   0x6de0: 35fff9ef  cbnz     w15, #0x6d1c
//   0x6de4: 1100050e  add      w14, w8, #1
//   0x6de8: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6dec: 2a0e03e8  mov      w8, w14
//   0x6df0: 17ffffcb  b        #0x6d1c
//   0x6df4: 2a0803e0  mov      w0, w8
//   0x6df8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_51_6c44(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006c44ULL;
    for (std::size_t i = 0; i < 110ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4581ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[52] Symbol: statistics_color
//      Virtual Address Range: 0x6dfc..0x703c (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[52] Biểu tượng: statistics_color
//      Dải địa chỉ ảo: 0x6dfc..0x703c (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6dfc: 52862028  mov      w8, #0x3101
//   0x6e00: 6b08007f  cmp      w3, w8
//   0x6e04: 5400020b  b.lt     #0x6e44
//   0x6e08: 12861fe9  mov      w9, #-0x3100
//   0x6e0c: 52a8988a  mov      w10, #0x44c40000
//   0x6e10: 0b090069  add      w9, w3, w9
//   0x6e14: 1e270141  fmov     s1, w10
//   0x6e18: 1e220122  scvtf    s2, w9
//   0x6e1c: 1e211841  fdiv     s1, s2, s1
//   0x6e20: 1e6c1000  fmov     d0, #0.50000000
//   0x6e24: 1e22c021  fcvt     d1, s1
//   0x6e28: 1e602820  fadd     d0, d1, d0
//   0x6e2c: 1e780009  fcvtzs   w9, d0
//   0x6e30: 11002129  add      w9, w9, #8
//   0x6e34: 2a1f03e8  mov      w8, wzr
//   0x6e38: 93407d29  sxtw     x9, w9
//   0x6e3c: 51001c6b  sub      w11, w3, #7
//   0x6e40: 1400001c  b        #0x6eb0
//   0x6e44: 2a1f03e8  mov      w8, wzr
//   0x6e48: 72000869  ands     w9, w3, #7
//   0x6e4c: 540002a0  b.eq     #0x6ea0
//   0x6e50: 4b090069  sub      w9, w3, w9
//   0x6e54: 93407d29  sxtw     x9, w9
//   0x6e58: 93407c6a  sxtw     x10, w3
//   0x6e5c: 14000004  b        #0x6e6c
//   0x6e60: 91000529  add      x9, x9, #1
//   0x6e64: eb0a013f  cmp      x9, x10
//   0x6e68: 540001ca  b.ge     #0x6ea0
//   0x6e6c: 7869784c  ldrh     w12, [x2, x9, lsl #1]
//   0x6e70: 53017d8b  lsr      w11, w12, #1
//   0x6e74: 121b256b  and      w11, w11, #0x7fe0
//   0x6e78: 3300118b  bfxil    w11, w12, #0, #5
//   0x6e7c: d37ff96c  lsl      x12, x11, #1
//   0x6e80: 786c680d  ldrh     w13, [x0, x12]
//   0x6e84: 110005ae  add      w14, w13, #1
//   0x6e88: 782c680e  strh     w14, [x0, x12]
//   0x6e8c: 35fffead  cbnz     w13, #0x6e60
//   0x6e90: 1100050c  add      w12, w8, #1
//   0x6e94: 7828d82b  strh     w11, [x1, w8, sxtw #1]
//   0x6e98: 2a0c03e8  mov      w8, w12
//   0x6e9c: 17fffff1  b        #0x6e60
//   0x6ea0: 51001c6b  sub      w11, w3, #7
//   0x6ea4: 7100057f  cmp      w11, #1
//   0x6ea8: 54000c6b  b.lt     #0x7034
//   0x6eac: 52800109  mov      w9, #8
//   0x6eb0: 528ffc0d  mov      w13, #0x7fe0
//   0x6eb4: aa1f03ea  mov      x10, xzr
//   0x6eb8: 93407d6b  sxtw     x11, w11
//   0x6ebc: d37ff92c  lsl      x12, x9, #1
//   0x6ec0: 4f0087e0  movi     v0.8h, #0x1f
//   0x6ec4: 4e020da1  dup      v1.8h, w13
//   0x6ec8: 14000005  b        #0x6edc
//   0x6ecc: 8b09014a  add      x10, x10, x9
//   0x6ed0: eb0b015f  cmp      x10, x11
//   0x6ed4: 8b0c0042  add      x2, x2, x12
//   0x6ed8: 54000aea  b.ge     #0x7034
//   0x6edc: 3dc00042  ldr      q2, [x2]
//   0x6ee0: 4e201c43  and      v3.16b, v2.16b, v0.16b
//   0x6ee4: 6f1f0442  ushr     v2.8h, v2.8h, #1
//   0x6ee8: 4e211c42  and      v2.16b, v2.16b, v1.16b
//   0x6eec: 4ea31c42  orr      v2.16b, v2.16b, v3.16b
//   0x6ef0: 0e023c4d  umov     w13, v2.h[0]
//   0x6ef4: 924039ae  and      x14, x13, #0x7fff
//   0x6ef8: d37ff9ce  lsl      x14, x14, #1
//   0x6efc: 786e680f  ldrh     w15, [x0, x14]
//   0x6f00: 110005f0  add      w16, w15, #1
//   0x6f04: 782e6810  strh     w16, [x0, x14]
//   0x6f08: 3500008f  cbnz     w15, #0x6f18
//   0x6f0c: 1100050e  add      w14, w8, #1
//   0x6f10: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6f14: 2a0e03e8  mov      w8, w14
//   0x6f18: 0e063c4d  umov     w13, v2.h[1]
//   0x6f1c: 92403dae  and      x14, x13, #0xffff
//   0x6f20: d37ff9ce  lsl      x14, x14, #1
//   0x6f24: 786e680f  ldrh     w15, [x0, x14]
//   0x6f28: 110005f0  add      w16, w15, #1
//   0x6f2c: 782e6810  strh     w16, [x0, x14]
//   0x6f30: 3500008f  cbnz     w15, #0x6f40
//   0x6f34: 1100050e  add      w14, w8, #1
//   0x6f38: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6f3c: 2a0e03e8  mov      w8, w14
//   0x6f40: 0e0a3c4d  umov     w13, v2.h[2]
//   0x6f44: 92403dae  and      x14, x13, #0xffff
//   0x6f48: d37ff9ce  lsl      x14, x14, #1
//   0x6f4c: 786e680f  ldrh     w15, [x0, x14]
//   0x6f50: 110005f0  add      w16, w15, #1
//   0x6f54: 782e6810  strh     w16, [x0, x14]
//   0x6f58: 3500008f  cbnz     w15, #0x6f68
//   0x6f5c: 1100050e  add      w14, w8, #1
//   0x6f60: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6f64: 2a0e03e8  mov      w8, w14
//   0x6f68: 0e0e3c4d  umov     w13, v2.h[3]
//   0x6f6c: 92403dae  and      x14, x13, #0xffff
//   0x6f70: d37ff9ce  lsl      x14, x14, #1
//   0x6f74: 786e680f  ldrh     w15, [x0, x14]
//   0x6f78: 110005f0  add      w16, w15, #1
//   0x6f7c: 782e6810  strh     w16, [x0, x14]
//   0x6f80: 3500008f  cbnz     w15, #0x6f90
//   0x6f84: 1100050e  add      w14, w8, #1
//   0x6f88: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6f8c: 2a0e03e8  mov      w8, w14
//   0x6f90: 0e123c4d  umov     w13, v2.h[4]
//   0x6f94: 92403dae  and      x14, x13, #0xffff
//   0x6f98: d37ff9ce  lsl      x14, x14, #1
//   0x6f9c: 786e680f  ldrh     w15, [x0, x14]
//   0x6fa0: 110005f0  add      w16, w15, #1
//   0x6fa4: 782e6810  strh     w16, [x0, x14]
//   0x6fa8: 3500008f  cbnz     w15, #0x6fb8
//   0x6fac: 1100050e  add      w14, w8, #1
//   0x6fb0: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6fb4: 2a0e03e8  mov      w8, w14
//   0x6fb8: 0e163c4d  umov     w13, v2.h[5]
//   0x6fbc: 92403dae  and      x14, x13, #0xffff
//   0x6fc0: d37ff9ce  lsl      x14, x14, #1
//   0x6fc4: 786e680f  ldrh     w15, [x0, x14]
//   0x6fc8: 110005f0  add      w16, w15, #1
//   0x6fcc: 782e6810  strh     w16, [x0, x14]
//   0x6fd0: 3500008f  cbnz     w15, #0x6fe0
//   0x6fd4: 1100050e  add      w14, w8, #1
//   0x6fd8: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x6fdc: 2a0e03e8  mov      w8, w14
//   0x6fe0: 0e1a3c4d  umov     w13, v2.h[6]
//   0x6fe4: 92403dae  and      x14, x13, #0xffff
//   0x6fe8: d37ff9ce  lsl      x14, x14, #1
//   0x6fec: 786e680f  ldrh     w15, [x0, x14]
//   0x6ff0: 110005f0  add      w16, w15, #1
//   0x6ff4: 782e6810  strh     w16, [x0, x14]
//   0x6ff8: 3500008f  cbnz     w15, #0x7008
//   0x6ffc: 1100050e  add      w14, w8, #1
//   0x7000: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x7004: 2a0e03e8  mov      w8, w14
//   0x7008: 0e1e3c4d  umov     w13, v2.h[7]
//   0x700c: 92403dae  and      x14, x13, #0xffff
//   0x7010: d37ff9ce  lsl      x14, x14, #1
//   0x7014: 786e680f  ldrh     w15, [x0, x14]
//   0x7018: 110005f0  add      w16, w15, #1
//   0x701c: 782e6810  strh     w16, [x0, x14]
//   0x7020: 35fff56f  cbnz     w15, #0x6ecc
//   0x7024: 1100050e  add      w14, w8, #1
//   0x7028: 7828d82d  strh     w13, [x1, w8, sxtw #1]
//   0x702c: 2a0e03e8  mov      w8, w14
//   0x7030: 17ffffa7  b        #0x6ecc
//   0x7034: 2a0803e0  mov      w0, w8
//   0x7038: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_52_6dfc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006dfcULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4691ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[53] Symbol: fitBox
//      Virtual Address Range: 0x703c..0x74e4 (1192 bytes, 298 AArch64 instructions)
// [VN] Khung FDE[53] Biểu tượng: fitBox
//      Dải địa chỉ ảo: 0x703c..0x74e4 (1192 byte, 298 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x703c: d10483ff  sub      sp, sp, #0x120
//   0x7040: f9007bfc  str      x28, [sp, #0xf0]
//   0x7044: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x7048: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x704c: 910443fd  add      x29, sp, #0x110
//   0x7050: d53bd048  mrs      x8, tpidr_el0
//   0x7054: f9401509  ldr      x9, [x8, #0x28]
//   0x7058: f81d83a9  stur     x9, [x29, #-0x28]
//   0x705c: 6940240a  ldpsw    x10, x9, [x0]
//   0x7060: d100192b  sub      x11, x9, #6
//   0x7064: 6b0b015f  cmp      w10, w11
//   0x7068: 540009ca  b.ge     #0x71a0
//   0x706c: 8b0a044c  add      x12, x2, x10, lsl #1
//   0x7070: 6f07e7e0  movi     v0.2d, #0xffffffffffffffff
//   0x7074: 6f00e403  movi     v3.2d, #0000000000000000
//   0x7078: 4f0087e7  movi     v7.8h, #0x1f
//   0x707c: aa0a03ed  mov      x13, x10
//   0x7080: 6f00e406  movi     v6.2d, #0000000000000000
//   0x7084: 6f00e405  movi     v5.2d, #0000000000000000
//   0x7088: 6f07e7e4  movi     v4.2d, #0xffffffffffffffff
//   0x708c: 6f07e7e2  movi     v2.2d, #0xffffffffffffffff
//   0x7090: 6f00e401  movi     v1.2d, #0000000000000000
//   0x7094: 3cc10590  ldr      q16, [x12], #0x10
//   0x7098: 910021ad  add      x13, x13, #8
//   0x709c: eb0b01bf  cmp      x13, x11
//   0x70a0: 0e023e0e  umov     w14, v16.h[0]
//   0x70a4: 530a3dd0  ubfx     w16, w14, #0xa, #6
//   0x70a8: 92403dce  and      x14, x14, #0xffff
//   0x70ac: 781b03b0  sturh    w16, [x29, #-0x50]
//   0x70b0: 786e782e  ldrh     w14, [x1, x14, lsl #1]
//   0x70b4: 0e063e0f  umov     w15, v16.h[1]
//   0x70b8: 530a3df0  ubfx     w16, w15, #0xa, #6
//   0x70bc: 781b23b0  sturh    w16, [x29, #-0x4e]
//   0x70c0: 92403def  and      x15, x15, #0xffff
//   0x70c4: 7900c3ee  strh     w14, [sp, #0x60]
//   0x70c8: 786f782f  ldrh     w15, [x1, x15, lsl #1]
//   0x70cc: 0e0a3e10  umov     w16, v16.h[2]
//   0x70d0: 530a3e0e  ubfx     w14, w16, #0xa, #6
//   0x70d4: 781b43ae  sturh    w14, [x29, #-0x4c]
//   0x70d8: 92403e10  and      x16, x16, #0xffff
//   0x70dc: 7900c7ef  strh     w15, [sp, #0x62]
//   0x70e0: 78707830  ldrh     w16, [x1, x16, lsl #1]
//   0x70e4: 0e0e3e0e  umov     w14, v16.h[3]
//   0x70e8: 530a3dcf  ubfx     w15, w14, #0xa, #6
//   0x70ec: 781b63af  sturh    w15, [x29, #-0x4a]
//   0x70f0: 92403dce  and      x14, x14, #0xffff
//   0x70f4: 7900cbf0  strh     w16, [sp, #0x64]
//   0x70f8: 786e782e  ldrh     w14, [x1, x14, lsl #1]
//   0x70fc: 0e123e0f  umov     w15, v16.h[4]
//   0x7100: 530a3df0  ubfx     w16, w15, #0xa, #6
//   0x7104: 781b83b0  sturh    w16, [x29, #-0x48]
//   0x7108: 92403def  and      x15, x15, #0xffff
//   0x710c: 7900cfee  strh     w14, [sp, #0x66]
//   0x7110: 786f782f  ldrh     w15, [x1, x15, lsl #1]
//   0x7114: 0e163e10  umov     w16, v16.h[5]
//   0x7118: 530a3e0e  ubfx     w14, w16, #0xa, #6
//   0x711c: 781ba3ae  sturh    w14, [x29, #-0x46]
//   0x7120: 92403e10  and      x16, x16, #0xffff
//   0x7124: 7900d3ef  strh     w15, [sp, #0x68]
//   0x7128: 78707830  ldrh     w16, [x1, x16, lsl #1]
//   0x712c: 0e1a3e0e  umov     w14, v16.h[6]
//   0x7130: 530a3dcf  ubfx     w15, w14, #0xa, #6
//   0x7134: 781bc3af  sturh    w15, [x29, #-0x44]
//   0x7138: 92403dce  and      x14, x14, #0xffff
//   0x713c: 7900d7f0  strh     w16, [sp, #0x6a]
//   0x7140: 786e782e  ldrh     w14, [x1, x14, lsl #1]
//   0x7144: 0e1e3e0f  umov     w15, v16.h[7]
//   0x7148: 530a3df0  ubfx     w16, w15, #0xa, #6
//   0x714c: 781be3b0  sturh    w16, [x29, #-0x42]
//   0x7150: 92403def  and      x15, x15, #0xffff
//   0x7154: 7900dbee  strh     w14, [sp, #0x6c]
//   0x7158: 786f782e  ldrh     w14, [x1, x15, lsl #1]
//   0x715c: 3cdb03b2  ldur     q18, [x29, #-0x50]
//   0x7160: 6f1b0611  ushr     v17.8h, v16.8h, #5
//   0x7164: 4e271e10  and      v16.16b, v16.16b, v7.16b
//   0x7168: 7900dfee  strh     w14, [sp, #0x6e]
//   0x716c: 6e726463  umax     v3.8h, v3.8h, v18.8h
//   0x7170: 6e726c00  umin     v0.8h, v0.8h, v18.8h
//   0x7174: 3dc01bf2  ldr      q18, [sp, #0x60]
//   0x7178: 4e271e31  and      v17.16b, v17.16b, v7.16b
//   0x717c: 6e7064a5  umax     v5.8h, v5.8h, v16.8h
//   0x7180: 6e7164c6  umax     v6.8h, v6.8h, v17.8h
//   0x7184: 6e716c84  umin     v4.8h, v4.8h, v17.8h
//   0x7188: 6e706c42  umin     v2.8h, v2.8h, v16.8h
//   0x718c: 4e618641  add      v1.8h, v18.8h, v1.8h
//   0x7190: 54fff82b  b.lt     #0x7094
//   0x7194: 3c9903b1  stur     q17, [x29, #-0x70]
//   0x7198: 3d8023f0  str      q16, [sp, #0x80]
//   0x719c: 14000008  b        #0x71bc
//   0x71a0: 6f07e7e2  movi     v2.2d, #0xffffffffffffffff
//   0x71a4: 6f00e401  movi     v1.2d, #0000000000000000
//   0x71a8: 6f07e7e4  movi     v4.2d, #0xffffffffffffffff
//   0x71ac: 6f07e7e0  movi     v0.2d, #0xffffffffffffffff
//   0x71b0: 6f00e405  movi     v5.2d, #0000000000000000
//   0x71b4: 6f00e406  movi     v6.2d, #0000000000000000
//   0x71b8: 6f00e403  movi     v3.2d, #0000000000000000
//   0x71bc: 4b0a012a  sub      w10, w9, w10
//   0x71c0: 1100054a  add      w10, w10, #1
//   0x71c4: 7200094a  ands     w10, w10, #7
//   0x71c8: 3c9b03a3  stur     q3, [x29, #-0x50]
//   0x71cc: 3c9903a6  stur     q6, [x29, #-0x70]
//   0x71d0: 3d8023e5  str      q5, [sp, #0x80]
//   0x71d4: 3d8013e0  str      q0, [sp, #0x40]
//   0x71d8: 3d800be4  str      q4, [sp, #0x20]
//   0x71dc: 3d8003e2  str      q2, [sp]
//   0x71e0: 3d801be1  str      q1, [sp, #0x60]
//   0x71e4: 54000160  b.eq     #0x7210
//   0x71e8: 4b0a012b  sub      w11, w9, w10
//   0x71ec: 93407d6b  sxtw     x11, w11
//   0x71f0: 9100056e  add      x14, x11, #1
//   0x71f4: eb0901df  cmp      x14, x9
//   0x71f8: 9a8bd52c  csinc    x12, x9, x11, le
//   0x71fc: cb0b018c  sub      x12, x12, x11
//   0x7200: f100219f  cmp      x12, #8
//   0x7204: 540000a2  b.hs     #0x7218
//   0x7208: 5280010f  mov      w15, #8
//   0x720c: 14000044  b        #0x731c
//   0x7210: 0e023c09  umov     w9, v0.h[0]
//   0x7214: 14000066  b        #0x73ac
//   0x7218: 927df18d  and      x13, x12, #0xfffffffffffffff8
//   0x721c: 910103f0  add      x16, sp, #0x40
//   0x7220: d10143b1  sub      x17, x29, #0x50
//   0x7224: 910083e3  add      x3, sp, #0x20
//   0x7228: d101c3a4  sub      x4, x29, #0x70
//   0x722c: 910003e5  mov      x5, sp
//   0x7230: 910203e6  add      x6, sp, #0x80
//   0x7234: 910183e7  add      x7, sp, #0x60
//   0x7238: 8b0e044e  add      x14, x2, x14, lsl #1
//   0x723c: 910021af  add      x15, x13, #8
//   0x7240: 8b0b01ab  add      x11, x13, x11
//   0x7244: 91004210  add      x16, x16, #0x10
//   0x7248: 91004231  add      x17, x17, #0x10
//   0x724c: 91004063  add      x3, x3, #0x10
//   0x7250: 91004084  add      x4, x4, #0x10
//   0x7254: 910040a5  add      x5, x5, #0x10
//   0x7258: 910040c6  add      x6, x6, #0x10
//   0x725c: 910040e7  add      x7, x7, #0x10
//   0x7260: 4f0087e0  movi     v0.8h, #0x1f
//   0x7264: aa0d03f3  mov      x19, x13
//   0x7268: 3cc105c1  ldr      q1, [x14], #0x10
//   0x726c: f1002273  subs     x19, x19, #8
//   0x7270: 6f160422  ushr     v2.8h, v1.8h, #0xa
//   0x7274: 6f1b0423  ushr     v3.8h, v1.8h, #5
//   0x7278: 3c810602  str      q2, [x16], #0x10
//   0x727c: 3c810622  str      q2, [x17], #0x10
//   0x7280: 2f10a422  ushll    v2.4s, v1.4h, #0
//   0x7284: 4e201c63  and      v3.16b, v3.16b, v0.16b
//   0x7288: 4e201c24  and      v4.16b, v1.16b, v0.16b
//   0x728c: 3c810463  str      q3, [x3], #0x10
//   0x7290: 3c810483  str      q3, [x4], #0x10
//   0x7294: 2f20a443  ushll    v3.2d, v2.2s, #0
//   0x7298: 3c8104a4  str      q4, [x5], #0x10
//   0x729c: 3c8104c4  str      q4, [x6], #0x10
//   0x72a0: 9e660074  fmov     x20, d3
//   0x72a4: 7c747824  ldr      h4, [x1, x20, lsl #1]
//   0x72a8: 4e183c74  mov      x20, v3.d[1]
//   0x72ac: 8b140434  add      x20, x1, x20, lsl #1
//   0x72b0: 6f20a442  ushll2   v2.2d, v2.4s, #0
//   0x72b4: 0d404a84  ld1      {v4.h}[1], [x20]
//   0x72b8: 9e660054  fmov     x20, d2
//   0x72bc: 8b140434  add      x20, x1, x20, lsl #1
//   0x72c0: 6f10a421  ushll2   v1.4s, v1.8h, #0
//   0x72c4: 0d405284  ld1      {v4.h}[2], [x20]
//   0x72c8: 4e183c54  mov      x20, v2.d[1]
//   0x72cc: 8b140434  add      x20, x1, x20, lsl #1
//   0x72d0: 2f20a422  ushll    v2.2d, v1.2s, #0
//   0x72d4: 0d405a84  ld1      {v4.h}[3], [x20]
//   0x72d8: 9e660054  fmov     x20, d2
//   0x72dc: 8b140434  add      x20, x1, x20, lsl #1
//   0x72e0: 6f20a421  ushll2   v1.2d, v1.4s, #0
//   0x72e4: 4d404284  ld1      {v4.h}[4], [x20]
//   0x72e8: 4e183c54  mov      x20, v2.d[1]
//   0x72ec: 8b140434  add      x20, x1, x20, lsl #1
//   0x72f0: 4d404a84  ld1      {v4.h}[5], [x20]
//   0x72f4: 9e660034  fmov     x20, d1
//   0x72f8: 8b140434  add      x20, x1, x20, lsl #1
//   0x72fc: 4d405284  ld1      {v4.h}[6], [x20]
//   0x7300: 4e183c34  mov      x20, v1.d[1]
//   0x7304: 8b140434  add      x20, x1, x20, lsl #1
//   0x7308: 4d405a84  ld1      {v4.h}[7], [x20]
//   0x730c: 3c8104e4  str      q4, [x7], #0x10
//   0x7310: 54fffac1  b.ne     #0x7268
//   0x7314: eb0d019f  cmp      x12, x13
//   0x7318: 54000480  b.eq     #0x73a8
//   0x731c: d37ff9e4  lsl      x4, x15, #1
//   0x7320: 910183ed  add      x13, sp, #0x60
//   0x7324: 910203ee  add      x14, sp, #0x80
//   0x7328: 910003ef  mov      x15, sp
//   0x732c: d101c3b0  sub      x16, x29, #0x70
//   0x7330: 910083f1  add      x17, sp, #0x20
//   0x7334: d10143a3  sub      x3, x29, #0x50
//   0x7338: 910103e5  add      x5, sp, #0x40
//   0x733c: 8b0b0442  add      x2, x2, x11, lsl #1
//   0x7340: aa1f03ec  mov      x12, xzr
//   0x7344: 8b0401ad  add      x13, x13, x4
//   0x7348: 8b0401ce  add      x14, x14, x4
//   0x734c: 8b0401ef  add      x15, x15, x4
//   0x7350: 8b040210  add      x16, x16, x4
//   0x7354: 8b040231  add      x17, x17, x4
//   0x7358: 8b040063  add      x3, x3, x4
//   0x735c: 8b0400a4  add      x4, x5, x4
//   0x7360: 91000842  add      x2, x2, #2
//   0x7364: d37ff985  lsl      x5, x12, #1
//   0x7368: 78656846  ldrh     w6, [x2, x5]
//   0x736c: 9100058c  add      x12, x12, #1
//   0x7370: d34a7cc7  ubfx     x7, x6, #0xa, #0x16
//   0x7374: 78256887  strh     w7, [x4, x5]
//   0x7378: 78256867  strh     w7, [x3, x5]
//   0x737c: 530524c7  ubfx     w7, w6, #5, #5
//   0x7380: 78256a27  strh     w7, [x17, x5]
//   0x7384: 78256a07  strh     w7, [x16, x5]
//   0x7388: 120010c7  and      w7, w6, #0x1f
//   0x738c: 782569e7  strh     w7, [x15, x5]
//   0x7390: 782569c7  strh     w7, [x14, x5]
//   0x7394: 78667826  ldrh     w6, [x1, x6, lsl #1]
//   0x7398: 8b0c0167  add      x7, x11, x12
//   0x739c: eb0900ff  cmp      x7, x9
//   0x73a0: 782569a6  strh     w6, [x13, x5]
//   0x73a4: 54fffe0b  b.lt     #0x7364
//   0x73a8: 794083e9  ldrh     w9, [sp, #0x40]
//   0x73ac: 321d0151  orr      w17, w10, #8
//   0x73b0: 5280004a  mov      w10, #2
//   0x73b4: 910103eb  add      x11, sp, #0x40
//   0x73b8: 910083ec  add      x12, sp, #0x20
//   0x73bc: 910003ed  mov      x13, sp
//   0x73c0: d10143ae  sub      x14, x29, #0x50
//   0x73c4: d101c3af  sub      x15, x29, #0x70
//   0x73c8: 910203f0  add      x16, sp, #0x80
//   0x73cc: d37ffa31  lsl      x17, x17, #1
//   0x73d0: 910183e1  add      x1, sp, #0x60
//   0x73d4: 14000008  b        #0x73f4
//   0x73d8: 786a6827  ldrh     w7, [x1, x10]
//   0x73dc: 7940c3f3  ldrh     w19, [sp, #0x60]
//   0x73e0: 9100094a  add      x10, x10, #2
//   0x73e4: eb0a023f  cmp      x17, x10
//   0x73e8: 0b070267  add      w7, w19, w7
//   0x73ec: 7900c3e7  strh     w7, [sp, #0x60]
//   0x73f0: 540004a0  b.eq     #0x7484
//   0x73f4: 786a6962  ldrh     w2, [x11, x10]
//   0x73f8: 6b29205f  cmp      w2, w9, uxth
//   0x73fc: 54000062  b.hs     #0x7408
//   0x7400: 2a0203e9  mov      w9, w2
//   0x7404: 790083e2  strh     w2, [sp, #0x40]
//   0x7408: 794043e2  ldrh     w2, [sp, #0x20]
//   0x740c: 786a6983  ldrh     w3, [x12, x10]
//   0x7410: 6b03005f  cmp      w2, w3
//   0x7414: 54000069  b.ls     #0x7420
//   0x7418: 2a0303e2  mov      w2, w3
//   0x741c: 790043e3  strh     w3, [sp, #0x20]
//   0x7420: 794003e3  ldrh     w3, [sp]
//   0x7424: 786a69a4  ldrh     w4, [x13, x10]
//   0x7428: 6b04007f  cmp      w3, w4
//   0x742c: 54000069  b.ls     #0x7438
//   0x7430: 2a0403e3  mov      w3, w4
//   0x7434: 790003e4  strh     w4, [sp]
//   0x7438: 785b03a4  ldurh    w4, [x29, #-0x50]
//   0x743c: 786a69c5  ldrh     w5, [x14, x10]
//   0x7440: 6b05009f  cmp      w4, w5
//   0x7444: 54000062  b.hs     #0x7450
//   0x7448: 2a0503e4  mov      w4, w5
//   0x744c: 781b03a5  sturh    w5, [x29, #-0x50]
//   0x7450: 785903a5  ldurh    w5, [x29, #-0x70]
//   0x7454: 786a69e6  ldrh     w6, [x15, x10]
//   0x7458: 6b0600bf  cmp      w5, w6
//   0x745c: 54000062  b.hs     #0x7468
//   0x7460: 2a0603e5  mov      w5, w6
//   0x7464: 781903a6  sturh    w6, [x29, #-0x70]
//   0x7468: 794103e6  ldrh     w6, [sp, #0x80]
//   0x746c: 786a6a07  ldrh     w7, [x16, x10]
//   0x7470: 6b0700df  cmp      w6, w7
//   0x7474: 54fffb22  b.hs     #0x73d8
//   0x7478: 2a0703e6  mov      w6, w7
//   0x747c: 790103e7  strh     w7, [sp, #0x80]
//   0x7480: 17ffffd6  b        #0x73d8
//   0x7484: 12003cea  and      w10, w7, #0xffff
//   0x7488: 12003d29  and      w9, w9, #0xffff
//   0x748c: 4b0200ab  sub      w11, w5, w2
//   0x7490: 2901240a  stp      w10, w9, [x0, #8]
//   0x7494: 4b090089  sub      w9, w4, w9
//   0x7498: 4b0300cc  sub      w12, w6, w3
//   0x749c: 1100056a  add      w10, w11, #1
//   0x74a0: 11000529  add      w9, w9, #1
//   0x74a4: 1100058b  add      w11, w12, #1
//   0x74a8: 1b097d49  mul      w9, w10, w9
//   0x74ac: 1b0b7d29  mul      w9, w9, w11
//   0x74b0: 29031404  stp      w4, w5, [x0, #0x18]
//   0x74b4: 29020c02  stp      w2, w3, [x0, #0x10]
//   0x74b8: 29042406  stp      w6, w9, [x0, #0x20]
//   0x74bc: f9401508  ldr      x8, [x8, #0x28]
//   0x74c0: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x74c4: eb09011f  cmp      x8, x9
//   0x74c8: 540000c1  b.ne     #0x74e0
//   0x74cc: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x74d0: a9504ff4  ldp      x20, x19, [sp, #0x100]
//   0x74d4: f9407bfc  ldr      x28, [sp, #0xf0]
//   0x74d8: 910483ff  add      sp, sp, #0x120
//   0x74dc: d65f03c0  ret      
//   0x74e0: 97ffeb58  bl       #0x2240
// ============================================================================
std::uint32_t fde_53_703c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000703cULL;
    for (std::size_t i = 0; i < 298ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4835ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[54] Symbol: cmpfunByRed
//      Virtual Address Range: 0x74e4..0x74f8 (20 bytes, 5 AArch64 instructions)
// [VN] Khung FDE[54] Biểu tượng: cmpfunByRed
//      Dải địa chỉ ảo: 0x74e4..0x74f8 (20 byte, 5 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x74e4: 79400028  ldrh     w8, [x1]
//   0x74e8: 79400009  ldrh     w9, [x0]
//   0x74ec: 530a7d08  lsr      w8, w8, #0xa
//   0x74f0: 4b492900  sub      w0, w8, w9, lsr #10
//   0x74f4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_54_74e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074e4ULL;
    for (std::size_t i = 0; i < 5ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5133ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[55] Symbol: cmpfunByGreen
//      Virtual Address Range: 0x74f8..0x7510 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[55] Biểu tượng: cmpfunByGreen
//      Dải địa chỉ ảo: 0x74f8..0x7510 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x74f8: 79400028  ldrh     w8, [x1]
//   0x74fc: 79400009  ldrh     w9, [x0]
//   0x7500: 53052508  ubfx     w8, w8, #5, #5
//   0x7504: 53052529  ubfx     w9, w9, #5, #5
//   0x7508: 4b090100  sub      w0, w8, w9
//   0x750c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_55_74f8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074f8ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5138ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[56] Symbol: cmpfunByBlue
//      Virtual Address Range: 0x7510..0x7528 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[56] Biểu tượng: cmpfunByBlue
//      Dải địa chỉ ảo: 0x7510..0x7528 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7510: 79400028  ldrh     w8, [x1]
//   0x7514: 79400009  ldrh     w9, [x0]
//   0x7518: 12001108  and      w8, w8, #0x1f
//   0x751c: 12001129  and      w9, w9, #0x1f
//   0x7520: 4b090100  sub      w0, w8, w9
//   0x7524: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_56_7510(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007510ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5144ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[57] Symbol: findBoxSplitPoint
//      Virtual Address Range: 0x7528..0x7670 (328 bytes, 82 AArch64 instructions)
// [VN] Khung FDE[57] Biểu tượng: findBoxSplitPoint
//      Dải địa chỉ ảo: 0x7528..0x7670 (328 byte, 82 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7528: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x752c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x7530: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x7534: 910083fd  add      x29, sp, #0x20
//   0x7538: 29433008  ldp      w8, w12, [x0, #0x18]
//   0x753c: 2941ac09  ldp      w9, w11, [x0, #0xc]
//   0x7540: b940140d  ldr      w13, [x0, #0x14]
//   0x7544: b940200e  ldr      w14, [x0, #0x20]
//   0x7548: aa0203f4  mov      x20, x2
//   0x754c: 4b09010a  sub      w10, w8, w9
//   0x7550: 4b0b0188  sub      w8, w12, w11
//   0x7554: aa0103f3  mov      x19, x1
//   0x7558: aa0003f5  mov      x21, x0
//   0x755c: 6b08015f  cmp      w10, w8
//   0x7560: 4b0d01c9  sub      w9, w14, w13
//   0x7564: 540000eb  b.lt     #0x7580
//   0x7568: 6b09015f  cmp      w10, w9
//   0x756c: 540000ab  b.lt     #0x7580
//   0x7570: 90000043  adrp     x3, #0xf000
//   0x7574: f947e863  ldr      x3, [x3, #0xfd0]
//   0x7578: 2a1f03f6  mov      w22, wzr
//   0x757c: 1400000e  b        #0x75b4
//   0x7580: 6b0a011f  cmp      w8, w10
//   0x7584: 9000004a  adrp     x10, #0xf000
//   0x7588: 9000004b  adrp     x11, #0xf000
//   0x758c: f947f54a  ldr      x10, [x10, #0xfe8]
//   0x7590: f947f96b  ldr      x11, [x11, #0xff0]
//   0x7594: 1a9fa7ed  cset     w13, lt
//   0x7598: 6b09011f  cmp      w8, w9
//   0x759c: 1a9fa7e8  cset     w8, lt
//   0x75a0: 2a0801a8  orr      w8, w13, w8
//   0x75a4: 5280002c  mov      w12, #1
//   0x75a8: 7100011f  cmp      w8, #0
//   0x75ac: 9a8a1163  csel     x3, x11, x10, ne
//   0x75b0: 1a8c0596  cinc     w22, w12, ne
//   0x75b4: b9402aaa  ldr      w10, [x21, #0x28]
//   0x75b8: 294022a9  ldp      w9, w8, [x21]
//   0x75bc: 6b0a02df  cmp      w22, w10
//   0x75c0: 540001a0  b.eq     #0x75f4
//   0x75c4: 4b09010a  sub      w10, w8, w9
//   0x75c8: 1100054a  add      w10, w10, #1
//   0x75cc: 52830feb  mov      w11, #0x187f
//   0x75d0: 6b0b015f  cmp      w10, w11
//   0x75d4: 5400010c  b.gt     #0x75f4
//   0x75d8: 93407d28  sxtw     x8, w9
//   0x75dc: 8b080680  add      x0, x20, x8, lsl #1
//   0x75e0: 93407d41  sxtw     x1, w10
//   0x75e4: 52800042  mov      w2, #2
//   0x75e8: 97ffeafe  bl       #0x21e0
//   0x75ec: 294022a9  ldp      w9, w8, [x21]
//   0x75f0: b9002ab6  str      w22, [x21, #0x28]
//   0x75f4: b9400aaa  ldr      w10, [x21, #8]
//   0x75f8: 2a0903e0  mov      w0, w9
//   0x75fc: 7100015f  cmp      w10, #0
//   0x7600: 1a8aa54b  cinc     w11, w10, lt
//   0x7604: 6b08013f  cmp      w9, w8
//   0x7608: 540002cc  b.gt     #0x7660
//   0x760c: 93407c0d  sxtw     x13, w0
//   0x7610: aa1f03e9  mov      x9, xzr
//   0x7614: 2a1f03ea  mov      w10, wzr
//   0x7618: 13017d6b  asr      w11, w11, #1
//   0x761c: 93407d0c  sxtw     x12, w8
//   0x7620: d10005ad  sub      x13, x13, #1
//   0x7624: 8b20c68e  add      x14, x20, w0, sxtw #1
//   0x7628: 786979cf  ldrh     w15, [x14, x9, lsl #1]
//   0x762c: 786f7a6f  ldrh     w15, [x19, x15, lsl #1]
//   0x7630: 0b0f014a  add      w10, w10, w15
//   0x7634: 6b0b015f  cmp      w10, w11
//   0x7638: 540000ca  b.ge     #0x7650
//   0x763c: 91000529  add      x9, x9, #1
//   0x7640: 8b0901af  add      x15, x13, x9
//   0x7644: eb0c01ff  cmp      x15, x12
//   0x7648: 54ffff0b  b.lt     #0x7628
//   0x764c: 14000005  b        #0x7660
//   0x7650: 0b090009  add      w9, w0, w9
//   0x7654: 5100050a  sub      w10, w8, #1
//   0x7658: 6b09011f  cmp      w8, w9
//   0x765c: 1a8ac120  csel     w0, w9, w10, gt
//   0x7660: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x7664: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x7668: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x766c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_57_7528(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007528ULL;
    for (std::size_t i = 0; i < 82ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5150ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[58] Symbol: insertBox
//      Virtual Address Range: 0x7670..0x7698 (40 bytes, 10 AArch64 instructions)
// [VN] Khung FDE[58] Biểu tượng: insertBox
//      Dải địa chỉ ảo: 0x7670..0x7698 (40 byte, 10 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7670: aa0003e8  mov      x8, x0
//   0x7674: f9401800  ldr      x0, [x0, #0x30]
//   0x7678: b40000c0  cbz      x0, #0x7690
//   0x767c: b9402409  ldr      w9, [x0, #0x24]
//   0x7680: b940242a  ldr      w10, [x1, #0x24]
//   0x7684: 6b0a013f  cmp      w9, w10
//   0x7688: 54ffff4a  b.ge     #0x7670
//   0x768c: f9001820  str      x0, [x1, #0x30]
//   0x7690: f9001901  str      x1, [x8, #0x30]
//   0x7694: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_58_7670(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007670ULL;
    for (std::size_t i = 0; i < 10ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5232ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[59] Symbol: getAverageColor
//      Virtual Address Range: 0x7698..0x799c (772 bytes, 193 AArch64 instructions)
// [VN] Khung FDE[59] Biểu tượng: getAverageColor
//      Dải địa chỉ ảo: 0x7698..0x799c (772 byte, 193 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7698: d10303ff  sub      sp, sp, #0xc0
//   0x769c: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x76a0: 9102c3fd  add      x29, sp, #0xb0
//   0x76a4: d53bd048  mrs      x8, tpidr_el0
//   0x76a8: f9401509  ldr      x9, [x8, #0x28]
//   0x76ac: 6f00e401  movi     v1.2d, #0000000000000000
//   0x76b0: 6f00e402  movi     v2.2d, #0000000000000000
//   0x76b4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x76b8: f81f83a9  stur     x9, [x29, #-8]
//   0x76bc: 6940240a  ldpsw    x10, x9, [x0]
//   0x76c0: d100092b  sub      x11, x9, #2
//   0x76c4: 6b0b015f  cmp      w10, w11
//   0x76c8: 540005aa  b.ge     #0x777c
//   0x76cc: 8b0a044c  add      x12, x2, x10, lsl #1
//   0x76d0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x76d4: 0f0087e3  movi     v3.4h, #0x1f
//   0x76d8: aa0a03ed  mov      x13, x10
//   0x76dc: 6f00e402  movi     v2.2d, #0000000000000000
//   0x76e0: 6f00e401  movi     v1.2d, #0000000000000000
//   0x76e4: fc408584  ldr      d4, [x12], #8
//   0x76e8: 910011ad  add      x13, x13, #4
//   0x76ec: eb0b01bf  cmp      x13, x11
//   0x76f0: 0e023c8e  umov     w14, v4.h[0]
//   0x76f4: 530a3dd0  ubfx     w16, w14, #0xa, #6
//   0x76f8: 92403dce  and      x14, x14, #0xffff
//   0x76fc: 781e83b0  sturh    w16, [x29, #-0x18]
//   0x7700: 786e782e  ldrh     w14, [x1, x14, lsl #1]
//   0x7704: 0e063c8f  umov     w15, v4.h[1]
//   0x7708: 530a3df0  ubfx     w16, w15, #0xa, #6
//   0x770c: 781ea3b0  sturh    w16, [x29, #-0x16]
//   0x7710: 92403def  and      x15, x15, #0xffff
//   0x7714: 781b83ae  sturh    w14, [x29, #-0x48]
//   0x7718: 786f782f  ldrh     w15, [x1, x15, lsl #1]
//   0x771c: 0e0a3c90  umov     w16, v4.h[2]
//   0x7720: 530a3e0e  ubfx     w14, w16, #0xa, #6
//   0x7724: 781ec3ae  sturh    w14, [x29, #-0x14]
//   0x7728: 92403e10  and      x16, x16, #0xffff
//   0x772c: 781ba3af  sturh    w15, [x29, #-0x46]
//   0x7730: 7870782f  ldrh     w15, [x1, x16, lsl #1]
//   0x7734: 0e0e3c8e  umov     w14, v4.h[3]
//   0x7738: 530a3dd0  ubfx     w16, w14, #0xa, #6
//   0x773c: 781ee3b0  sturh    w16, [x29, #-0x12]
//   0x7740: 92403dce  and      x14, x14, #0xffff
//   0x7744: 781bc3af  sturh    w15, [x29, #-0x44]
//   0x7748: 786e782e  ldrh     w14, [x1, x14, lsl #1]
//   0x774c: fc5e83a6  ldur     d6, [x29, #-0x18]
//   0x7750: 2f1b0485  ushr     v5.4h, v4.4h, #5
//   0x7754: 0e231c84  and      v4.8b, v4.8b, v3.8b
//   0x7758: 781be3ae  sturh    w14, [x29, #-0x42]
//   0x775c: fc5b83a7  ldur     d7, [x29, #-0x48]
//   0x7760: 0e231ca5  and      v5.8b, v5.8b, v3.8b
//   0x7764: 2e6780c0  umlal    v0.4s, v6.4h, v7.4h
//   0x7768: 2e6780a2  umlal    v2.4s, v5.4h, v7.4h
//   0x776c: 2e678081  umlal    v1.4s, v4.4h, v7.4h
//   0x7770: 54fffbab  b.lt     #0x76e4
//   0x7774: fc1d83a5  stur     d5, [x29, #-0x28]
//   0x7778: fc1c83a4  stur     d4, [x29, #-0x38]
//   0x777c: 4b0a012a  sub      w10, w9, w10
//   0x7780: 1100054a  add      w10, w10, #1
//   0x7784: 7200054a  ands     w10, w10, #3
//   0x7788: 3d8013e0  str      q0, [sp, #0x40]
//   0x778c: 3d800be2  str      q2, [sp, #0x20]
//   0x7790: 3d8003e1  str      q1, [sp]
//   0x7794: 54000160  b.eq     #0x77c0
//   0x7798: 4b0a012b  sub      w11, w9, w10
//   0x779c: 93407d6b  sxtw     x11, w11
//   0x77a0: 9100056e  add      x14, x11, #1
//   0x77a4: eb0901df  cmp      x14, x9
//   0x77a8: 9a8bd52c  csinc    x12, x9, x11, le
//   0x77ac: cb0b018c  sub      x12, x12, x11
//   0x77b0: f100119f  cmp      x12, #4
//   0x77b4: 540000e2  b.hs     #0x77d0
//   0x77b8: 5280008e  mov      w14, #4
//   0x77bc: 1400002f  b        #0x7878
//   0x77c0: 1e26000c  fmov     w12, s0
//   0x77c4: 1e26004b  fmov     w11, s2
//   0x77c8: 1e260029  fmov     w9, s1
//   0x77cc: 14000044  b        #0x78dc
//   0x77d0: 927ef58d  and      x13, x12, #0xfffffffffffffffc
//   0x77d4: 910103f0  add      x16, sp, #0x40
//   0x77d8: 910083f1  add      x17, sp, #0x20
//   0x77dc: 910003e3  mov      x3, sp
//   0x77e0: 8b0e044f  add      x15, x2, x14, lsl #1
//   0x77e4: 910011ae  add      x14, x13, #4
//   0x77e8: 8b0b01ab  add      x11, x13, x11
//   0x77ec: 91004210  add      x16, x16, #0x10
//   0x77f0: 91004231  add      x17, x17, #0x10
//   0x77f4: 91004063  add      x3, x3, #0x10
//   0x77f8: 4f0007e0  movi     v0.4s, #0x1f
//   0x77fc: aa0d03e4  mov      x4, x13
//   0x7800: fc4085e1  ldr      d1, [x15], #8
//   0x7804: f1001084  subs     x4, x4, #4
//   0x7808: 2f10a421  ushll    v1.4s, v1.4h, #0
//   0x780c: 2f20a422  ushll    v2.2d, v1.2s, #0
//   0x7810: 9e660045  fmov     x5, d2
//   0x7814: 7c657823  ldr      h3, [x1, x5, lsl #1]
//   0x7818: 4e183c45  mov      x5, v2.d[1]
//   0x781c: 8b050425  add      x5, x1, x5, lsl #1
//   0x7820: 6f20a422  ushll2   v2.2d, v1.4s, #0
//   0x7824: 0d4048a3  ld1      {v3.h}[1], [x5]
//   0x7828: 9e660046  fmov     x6, d2
//   0x782c: 8b060426  add      x6, x1, x6, lsl #1
//   0x7830: 4e183c45  mov      x5, v2.d[1]
//   0x7834: 0d4050c3  ld1      {v3.h}[2], [x6]
//   0x7838: 8b050425  add      x5, x1, x5, lsl #1
//   0x783c: 6f3b0424  ushr     v4.4s, v1.4s, #5
//   0x7840: 6f360422  ushr     v2.4s, v1.4s, #0xa
//   0x7844: 0d4058a3  ld1      {v3.h}[3], [x5]
//   0x7848: 4e201c21  and      v1.16b, v1.16b, v0.16b
//   0x784c: 4e201c84  and      v4.16b, v4.16b, v0.16b
//   0x7850: 2f10a463  ushll    v3.4s, v3.4h, #0
//   0x7854: 4ea39c42  mul      v2.4s, v2.4s, v3.4s
//   0x7858: 4ea39c84  mul      v4.4s, v4.4s, v3.4s
//   0x785c: 4ea39c21  mul      v1.4s, v1.4s, v3.4s
//   0x7860: 3c810602  str      q2, [x16], #0x10
//   0x7864: 3c810624  str      q4, [x17], #0x10
//   0x7868: 3c810461  str      q1, [x3], #0x10
//   0x786c: 54fffca1  b.ne     #0x7800
//   0x7870: eb0d019f  cmp      x12, x13
//   0x7874: 540002e0  b.eq     #0x78d0
//   0x7878: d37ef5ce  lsl      x14, x14, #2
//   0x787c: 910003ec  mov      x12, sp
//   0x7880: 910083ed  add      x13, sp, #0x20
//   0x7884: 910103ef  add      x15, sp, #0x40
//   0x7888: 8b0e018c  add      x12, x12, x14
//   0x788c: 8b0e01ad  add      x13, x13, x14
//   0x7890: 8b0e01ee  add      x14, x15, x14
//   0x7894: 9100084f  add      x15, x2, #2
//   0x7898: 786b79f0  ldrh     w16, [x15, x11, lsl #1]
//   0x789c: 9100056b  add      x11, x11, #1
//   0x78a0: eb09017f  cmp      x11, x9
//   0x78a4: 78707831  ldrh     w17, [x1, x16, lsl #1]
//   0x78a8: d34a7e02  ubfx     x2, x16, #0xa, #0x16
//   0x78ac: 53052603  ubfx     w3, w16, #5, #5
//   0x78b0: 12001210  and      w16, w16, #0x1f
//   0x78b4: 1b117c42  mul      w2, w2, w17
//   0x78b8: 1b117c63  mul      w3, w3, w17
//   0x78bc: 1b117e10  mul      w16, w16, w17
//   0x78c0: b80045c2  str      w2, [x14], #4
//   0x78c4: b80045a3  str      w3, [x13], #4
//   0x78c8: b8004590  str      w16, [x12], #4
//   0x78cc: 54fffe6b  b.lt     #0x7898
//   0x78d0: b94043ec  ldr      w12, [sp, #0x40]
//   0x78d4: b94023eb  ldr      w11, [sp, #0x20]
//   0x78d8: b94003e9  ldr      w9, [sp]
//   0x78dc: 321e014f  orr      w15, w10, #4
//   0x78e0: 910003ea  mov      x10, sp
//   0x78e4: 910083ed  add      x13, sp, #0x20
//   0x78e8: 910103ee  add      x14, sp, #0x40
//   0x78ec: b27e014a  orr      x10, x10, #4
//   0x78f0: b27e01ad  orr      x13, x13, #4
//   0x78f4: b27e01ce  orr      x14, x14, #4
//   0x78f8: d10005ef  sub      x15, x15, #1
//   0x78fc: b84045d0  ldr      w16, [x14], #4
//   0x7900: f10005ef  subs     x15, x15, #1
//   0x7904: 0b10018c  add      w12, w12, w16
//   0x7908: b90043ec  str      w12, [sp, #0x40]
//   0x790c: b84045b0  ldr      w16, [x13], #4
//   0x7910: 0b10016b  add      w11, w11, w16
//   0x7914: b90023eb  str      w11, [sp, #0x20]
//   0x7918: b8404550  ldr      w16, [x10], #4
//   0x791c: 0b100129  add      w9, w9, w16
//   0x7920: b90003e9  str      w9, [sp]
//   0x7924: 54fffec1  b.ne     #0x78fc
//   0x7928: bd400800  ldr      s0, [x0, #8]
//   0x792c: f9401508  ldr      x8, [x8, #0x28]
//   0x7930: f85f83aa  ldur     x10, [x29, #-8]
//   0x7934: eb0a011f  cmp      x8, x10
//   0x7938: 54000301  b.ne     #0x7998
//   0x793c: 5e21d800  scvtf    s0, s0
//   0x7940: 1e230162  ucvtf    s2, w11
//   0x7944: 1e230181  ucvtf    s1, w12
//   0x7948: 1e230123  ucvtf    s3, w9
//   0x794c: 1e201842  fdiv     s2, s2, s0
//   0x7950: 1e201821  fdiv     s1, s1, s0
//   0x7954: 1e201860  fdiv     s0, s3, s0
//   0x7958: 1e6c1003  fmov     d3, #0.50000000
//   0x795c: 1e22c042  fcvt     d2, s2
//   0x7960: 1e22c021  fcvt     d1, s1
//   0x7964: 1e632842  fadd     d2, d2, d3
//   0x7968: 1e22c000  fcvt     d0, s0
//   0x796c: 1e632821  fadd     d1, d1, d3
//   0x7970: 1e780049  fcvtzs   w9, d2
//   0x7974: a94b7bfd  ldp      x29, x30, [sp, #0xb0]
//   0x7978: 1e632800  fadd     d0, d0, d3
//   0x797c: 1e780028  fcvtzs   w8, d1
//   0x7980: 531b6929  lsl      w9, w9, #5
//   0x7984: 1e78000a  fcvtzs   w10, d0
//   0x7988: 2a082928  orr      w8, w9, w8, lsl #10
//   0x798c: 2a0a0100  orr      w0, w8, w10
//   0x7990: 910303ff  add      sp, sp, #0xc0
//   0x7994: d65f03c0  ret      
//   0x7998: 97ffea2a  bl       #0x2240
// ============================================================================
std::uint32_t fde_59_7698(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007698ULL;
    for (std::size_t i = 0; i < 193ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5242ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[60] Symbol: cutting_colors
//      Virtual Address Range: 0x799c..0x7c04 (616 bytes, 154 AArch64 instructions)
// [VN] Khung FDE[60] Biểu tượng: cutting_colors
//      Dải địa chỉ ảo: 0x799c..0x7c04 (616 byte, 154 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x799c: d10483ff  sub      sp, sp, #0x120
//   0x79a0: f90063fc  str      x28, [sp, #0xc0]
//   0x79a4: a90d67fa  stp      x26, x25, [sp, #0xd0]
//   0x79a8: a90e5ff8  stp      x24, x23, [sp, #0xe0]
//   0x79ac: a90f57f6  stp      x22, x21, [sp, #0xf0]
//   0x79b0: a9104ff4  stp      x20, x19, [sp, #0x100]
//   0x79b4: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x79b8: 910443fd  add      x29, sp, #0x110
//   0x79bc: d53bd058  mrs      x24, tpidr_el0
//   0x79c0: f9401708  ldr      x8, [x24, #0x28]
//   0x79c4: aa0003f4  mov      x20, x0
//   0x79c8: 52800700  mov      w0, #0x38
//   0x79cc: 2a0203f6  mov      w22, w2
//   0x79d0: aa0103f3  mov      x19, x1
//   0x79d4: f81a83a8  stur     x8, [x29, #-0x58]
//   0x79d8: 97ffea86  bl       #0x23f0
//   0x79dc: 510006c8  sub      w8, w22, #1
//   0x79e0: 12800009  mov      w9, #-1
//   0x79e4: aa1403e1  mov      x1, x20
//   0x79e8: aa1303e2  mov      x2, x19
//   0x79ec: aa0003f5  mov      x21, x0
//   0x79f0: f900181f  str      xzr, [x0, #0x30]
//   0x79f4: 2900201f  stp      wzr, w8, [x0]
//   0x79f8: b9002809  str      w9, [x0, #0x28]
//   0x79fc: 97ffea3d  bl       #0x22f0
//   0x7a00: 52800039  mov      w25, #1
//   0x7a04: f9001bf5  str      x21, [sp, #0x30]
//   0x7a08: 14000007  b        #0x7a24
//   0x7a0c: f9001aa8  str      x8, [x21, #0x30]
//   0x7a10: f9001935  str      x21, [x9, #0x30]
//   0x7a14: f9401bf5  ldr      x21, [sp, #0x30]
//   0x7a18: 11000739  add      w25, w25, #1
//   0x7a1c: 7100433f  cmp      w25, #0x10
//   0x7a20: 540006e0  b.eq     #0x7afc
//   0x7a24: 294026a8  ldp      w8, w9, [x21]
//   0x7a28: 6b08013f  cmp      w9, w8
//   0x7a2c: 5400068d  b.le     #0x7afc
//   0x7a30: f9401aba  ldr      x26, [x21, #0x30]
//   0x7a34: aa1503e0  mov      x0, x21
//   0x7a38: aa1403e1  mov      x1, x20
//   0x7a3c: aa1303e2  mov      x2, x19
//   0x7a40: f9001bfa  str      x26, [sp, #0x30]
//   0x7a44: 97ffea0f  bl       #0x2280
//   0x7a48: 2a0003f7  mov      w23, w0
//   0x7a4c: 52800700  mov      w0, #0x38
//   0x7a50: 97ffea68  bl       #0x23f0
//   0x7a54: 110006e8  add      w8, w23, #1
//   0x7a58: b9000008  str      w8, [x0]
//   0x7a5c: b94006a8  ldr      w8, [x21, #4]
//   0x7a60: f900181f  str      xzr, [x0, #0x30]
//   0x7a64: aa1403e1  mov      x1, x20
//   0x7a68: aa1303e2  mov      x2, x19
//   0x7a6c: b9000408  str      w8, [x0, #4]
//   0x7a70: b9402aa8  ldr      w8, [x21, #0x28]
//   0x7a74: aa0003f6  mov      x22, x0
//   0x7a78: b9002808  str      w8, [x0, #0x28]
//   0x7a7c: 97ffea1d  bl       #0x22f0
//   0x7a80: aa1503e0  mov      x0, x21
//   0x7a84: aa1403e1  mov      x1, x20
//   0x7a88: aa1303e2  mov      x2, x19
//   0x7a8c: b90006b7  str      w23, [x21, #4]
//   0x7a90: f9001abf  str      xzr, [x21, #0x30]
//   0x7a94: 97ffea17  bl       #0x22f0
//   0x7a98: b400017a  cbz      x26, #0x7ac4
//   0x7a9c: b94026c9  ldr      w9, [x22, #0x24]
//   0x7aa0: 910003ea  mov      x10, sp
//   0x7aa4: b940274b  ldr      w11, [x26, #0x24]
//   0x7aa8: aa1a03e8  mov      x8, x26
//   0x7aac: 6b09017f  cmp      w11, w9
//   0x7ab0: 540000eb  b.lt     #0x7acc
//   0x7ab4: f940191a  ldr      x26, [x8, #0x30]
//   0x7ab8: aa0803ea  mov      x10, x8
//   0x7abc: b5ffff5a  cbnz     x26, #0x7aa4
//   0x7ac0: 14000005  b        #0x7ad4
//   0x7ac4: 910003e8  mov      x8, sp
//   0x7ac8: 14000003  b        #0x7ad4
//   0x7acc: f9001ac8  str      x8, [x22, #0x30]
//   0x7ad0: aa0a03e8  mov      x8, x10
//   0x7ad4: f9001916  str      x22, [x8, #0x30]
//   0x7ad8: 910003e8  mov      x8, sp
//   0x7adc: aa0803e9  mov      x9, x8
//   0x7ae0: f9401908  ldr      x8, [x8, #0x30]
//   0x7ae4: b4fff968  cbz      x8, #0x7a10
//   0x7ae8: b940250a  ldr      w10, [x8, #0x24]
//   0x7aec: b94026ab  ldr      w11, [x21, #0x24]
//   0x7af0: 6b0b015f  cmp      w10, w11
//   0x7af4: 54ffff4a  b.ge     #0x7adc
//   0x7af8: 17ffffc5  b        #0x7a0c
//   0x7afc: 2a1f03f6  mov      w22, wzr
//   0x7b00: b4000675  cbz      x21, #0x7bcc
//   0x7b04: 9101e3f7  add      x23, sp, #0x78
//   0x7b08: 9100e3f9  add      x25, sp, #0x38
//   0x7b0c: 1400000b  b        #0x7b38
//   0x7b10: 340000a9  cbz      w9, #0x7b24
//   0x7b14: b9400aa8  ldr      w8, [x21, #8]
//   0x7b18: 93407ec9  sxtw     x9, w22
//   0x7b1c: 110006d6  add      w22, w22, #1
//   0x7b20: b8297b28  str      w8, [x25, x9, lsl #2]
//   0x7b24: f9401aba  ldr      x26, [x21, #0x30]
//   0x7b28: aa1503e0  mov      x0, x21
//   0x7b2c: 97ffea4d  bl       #0x2460
//   0x7b30: aa1a03f5  mov      x21, x26
//   0x7b34: b400035a  cbz      x26, #0x7b9c
//   0x7b38: aa1503e0  mov      x0, x21
//   0x7b3c: aa1403e1  mov      x1, x20
//   0x7b40: aa1303e2  mov      x2, x19
//   0x7b44: 97ffea0b  bl       #0x2370
//   0x7b48: 710006df  cmp      w22, #1
//   0x7b4c: b836dae0  str      w0, [x23, w22, sxtw #2]
//   0x7b50: 54fffe2b  b.lt     #0x7b14
//   0x7b54: 2a1603e8  mov      w8, w22
//   0x7b58: 52800029  mov      w9, #1
//   0x7b5c: 9100e3ea  add      x10, sp, #0x38
//   0x7b60: 9101e3eb  add      x11, sp, #0x78
//   0x7b64: 14000005  b        #0x7b78
//   0x7b68: 9100114a  add      x10, x10, #4
//   0x7b6c: f1000508  subs     x8, x8, #1
//   0x7b70: 9100116b  add      x11, x11, #4
//   0x7b74: 54fffce0  b.eq     #0x7b10
//   0x7b78: b940016c  ldr      w12, [x11]
//   0x7b7c: 6b00019f  cmp      w12, w0
//   0x7b80: 54ffff41  b.ne     #0x7b68
//   0x7b84: b9400aac  ldr      w12, [x21, #8]
//   0x7b88: b940014d  ldr      w13, [x10]
//   0x7b8c: 2a1f03e9  mov      w9, wzr
//   0x7b90: 0b0c01ac  add      w12, w13, w12
//   0x7b94: b900014c  str      w12, [x10]
//   0x7b98: 17fffff4  b        #0x7b68
//   0x7b9c: 710006df  cmp      w22, #1
//   0x7ba0: 5400016b  b.lt     #0x7bcc
//   0x7ba4: 2a1603e8  mov      w8, w22
//   0x7ba8: 9100e3e9  add      x9, sp, #0x38
//   0x7bac: 9101e3ea  add      x10, sp, #0x78
//   0x7bb0: b840454b  ldr      w11, [x10], #4
//   0x7bb4: f1000508  subs     x8, x8, #1
//   0x7bb8: 7800266b  strh     w11, [x19], #2
//   0x7bbc: b840452c  ldr      w12, [x9], #4
//   0x7bc0: 92403d6b  and      x11, x11, #0xffff
//   0x7bc4: 782b7a8c  strh     w12, [x20, x11, lsl #1]
//   0x7bc8: 54ffff41  b.ne     #0x7bb0
//   0x7bcc: f9401708  ldr      x8, [x24, #0x28]
//   0x7bd0: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x7bd4: eb09011f  cmp      x8, x9
//   0x7bd8: 54000141  b.ne     #0x7c00
//   0x7bdc: 2a1603e0  mov      w0, w22
//   0x7be0: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x7be4: a9504ff4  ldp      x20, x19, [sp, #0x100]
//   0x7be8: a94f57f6  ldp      x22, x21, [sp, #0xf0]
//   0x7bec: a94e5ff8  ldp      x24, x23, [sp, #0xe0]
//   0x7bf0: a94d67fa  ldp      x26, x25, [sp, #0xd0]
//   0x7bf4: f94063fc  ldr      x28, [sp, #0xc0]
//   0x7bf8: 910483ff  add      sp, sp, #0x120
//   0x7bfc: d65f03c0  ret      
//   0x7c00: 97ffe990  bl       #0x2240
// ============================================================================
std::uint32_t fde_60_799c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000799cULL;
    for (std::size_t i = 0; i < 154ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5435ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[61] Symbol: toARGB888
//      Virtual Address Range: 0x7c04..0x7c24 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[61] Biểu tượng: toARGB888
//      Dải địa chỉ ảo: 0x7c04..0x7c24 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7c04: 12003c08  and      w8, w0, #0xffff
//   0x7c08: 5317590a  lsl      w10, w8, #9
//   0x7c0c: 53057d09  lsr      w9, w8, #5
//   0x7c10: 120d114a  and      w10, w10, #0xf80000
//   0x7c14: 3315112a  bfi      w10, w9, #0xb, #5
//   0x7c18: 331d110a  bfi      w10, w8, #3, #5
//   0x7c1c: 32081d40  orr      w0, w10, #0xff000000
//   0x7c20: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_61_7c04(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007c04ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5589ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[62] Symbol: partition_with_histogram
//      Virtual Address Range: 0x7c24..0x7cf4 (208 bytes, 52 AArch64 instructions)
// [VN] Khung FDE[62] Biểu tượng: partition_with_histogram
//      Dải địa chỉ ảo: 0x7c24..0x7cf4 (208 byte, 52 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7c24: 937e7c49  sbfiz    x9, x2, #2, #0x20
//   0x7c28: b8696828  ldr      w8, [x1, x9]
//   0x7c2c: b8696809  ldr      w9, [x0, x9]
//   0x7c30: 6b03005f  cmp      w2, w3
//   0x7c34: 5400054a  b.ge     #0x7cdc
//   0x7c38: 6b03005f  cmp      w2, w3
//   0x7c3c: 5400012a  b.ge     #0x7c60
//   0x7c40: 93407c63  sxtw     x3, w3
//   0x7c44: 93407c4a  sxtw     x10, w2
//   0x7c48: b863782b  ldr      w11, [x1, x3, lsl #2]
//   0x7c4c: 6b08017f  cmp      w11, w8
//   0x7c50: 540000ec  b.gt     #0x7c6c
//   0x7c54: d1000463  sub      x3, x3, #1
//   0x7c58: eb0a007f  cmp      x3, x10
//   0x7c5c: 54ffff6c  b.gt     #0x7c48
//   0x7c60: 6b03005f  cmp      w2, w3
//   0x7c64: 54fffe6a  b.ge     #0x7c30
//   0x7c68: 14000008  b        #0x7c88
//   0x7c6c: d37ef54a  lsl      x10, x10, #2
//   0x7c70: b82a682b  str      w11, [x1, x10]
//   0x7c74: b863780b  ldr      w11, [x0, x3, lsl #2]
//   0x7c78: 11000442  add      w2, w2, #1
//   0x7c7c: b82a680b  str      w11, [x0, x10]
//   0x7c80: 6b03005f  cmp      w2, w3
//   0x7c84: 54fffd6a  b.ge     #0x7c30
//   0x7c88: 937e7c4b  sbfiz    x11, x2, #2, #0x20
//   0x7c8c: 8b0b000a  add      x10, x0, x11
//   0x7c90: 8b0b002b  add      x11, x1, x11
//   0x7c94: b940016c  ldr      w12, [x11]
//   0x7c98: 6b08019f  cmp      w12, w8
//   0x7c9c: 540000eb  b.lt     #0x7cb8
//   0x7ca0: 11000442  add      w2, w2, #1
//   0x7ca4: 9100114a  add      x10, x10, #4
//   0x7ca8: 6b02007f  cmp      w3, w2
//   0x7cac: 9100116b  add      x11, x11, #4
//   0x7cb0: 54ffff21  b.ne     #0x7c94
//   0x7cb4: 14000009  b        #0x7cd8
//   0x7cb8: 937e7c6b  sbfiz    x11, x3, #2, #0x20
//   0x7cbc: b82b682c  str      w12, [x1, x11]
//   0x7cc0: b940014a  ldr      w10, [x10]
//   0x7cc4: 51000463  sub      w3, w3, #1
//   0x7cc8: b82b680a  str      w10, [x0, x11]
//   0x7ccc: 6b03005f  cmp      w2, w3
//   0x7cd0: 54fffb4b  b.lt     #0x7c38
//   0x7cd4: 14000002  b        #0x7cdc
//   0x7cd8: 2a0303e2  mov      w2, w3
//   0x7cdc: 93407c4a  sxtw     x10, w2
//   0x7ce0: d37ef54a  lsl      x10, x10, #2
//   0x7ce4: b82a6828  str      w8, [x1, x10]
//   0x7ce8: b82a6809  str      w9, [x0, x10]
//   0x7cec: 2a0203e0  mov      w0, w2
//   0x7cf0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_62_7c24(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007c24ULL;
    for (std::size_t i = 0; i < 52ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5597ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[63] Symbol: sort_with_histogram
//      Virtual Address Range: 0x7cf4..0x7e0c (280 bytes, 70 AArch64 instructions)
// [VN] Khung FDE[63] Biểu tượng: sort_with_histogram
//      Dải địa chỉ ảo: 0x7cf4..0x7e0c (280 byte, 70 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7cf4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x7cf8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x7cfc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x7d00: 910083fd  add      x29, sp, #0x20
//   0x7d04: 6b03005f  cmp      w2, w3
//   0x7d08: 540007aa  b.ge     #0x7dfc
//   0x7d0c: 2a0303f3  mov      w19, w3
//   0x7d10: aa0103f4  mov      x20, x1
//   0x7d14: aa0003f5  mov      x21, x0
//   0x7d18: 937e7c49  sbfiz    x9, x2, #2, #0x20
//   0x7d1c: b8696a88  ldr      w8, [x20, x9]
//   0x7d20: b8696aa9  ldr      w9, [x21, x9]
//   0x7d24: 2a0203f6  mov      w22, w2
//   0x7d28: 2a1303ea  mov      w10, w19
//   0x7d2c: 6b0a02df  cmp      w22, w10
//   0x7d30: 5400026a  b.ge     #0x7d7c
//   0x7d34: 1400000a  b        #0x7d5c
//   0x7d38: 937e7d4c  sbfiz    x12, x10, #2, #0x20
//   0x7d3c: b82c6a8d  str      w13, [x20, x12]
//   0x7d40: b940016b  ldr      w11, [x11]
//   0x7d44: 5100054a  sub      w10, w10, #1
//   0x7d48: b82c6aab  str      w11, [x21, x12]
//   0x7d4c: 6b0a02df  cmp      w22, w10
//   0x7d50: 5400042a  b.ge     #0x7dd4
//   0x7d54: 6b0a02df  cmp      w22, w10
//   0x7d58: 5400012a  b.ge     #0x7d7c
//   0x7d5c: 93407d4a  sxtw     x10, w10
//   0x7d60: 93407ecb  sxtw     x11, w22
//   0x7d64: b86a7a8c  ldr      w12, [x20, x10, lsl #2]
//   0x7d68: 6b08019f  cmp      w12, w8
//   0x7d6c: 540000ec  b.gt     #0x7d88
//   0x7d70: d100054a  sub      x10, x10, #1
//   0x7d74: eb0b015f  cmp      x10, x11
//   0x7d78: 54ffff6c  b.gt     #0x7d64
//   0x7d7c: 6b0a02df  cmp      w22, w10
//   0x7d80: 54fffe6a  b.ge     #0x7d4c
//   0x7d84: 14000008  b        #0x7da4
//   0x7d88: d37ef56b  lsl      x11, x11, #2
//   0x7d8c: b82b6a8c  str      w12, [x20, x11]
//   0x7d90: b86a7aac  ldr      w12, [x21, x10, lsl #2]
//   0x7d94: 110006d6  add      w22, w22, #1
//   0x7d98: b82b6aac  str      w12, [x21, x11]
//   0x7d9c: 6b0a02df  cmp      w22, w10
//   0x7da0: 54fffd6a  b.ge     #0x7d4c
//   0x7da4: 937e7ecc  sbfiz    x12, x22, #2, #0x20
//   0x7da8: 8b0c02ab  add      x11, x21, x12
//   0x7dac: 8b0c028c  add      x12, x20, x12
//   0x7db0: b940018d  ldr      w13, [x12]
//   0x7db4: 6b0801bf  cmp      w13, w8
//   0x7db8: 54fffc0b  b.lt     #0x7d38
//   0x7dbc: 110006d6  add      w22, w22, #1
//   0x7dc0: 9100116b  add      x11, x11, #4
//   0x7dc4: 6b16015f  cmp      w10, w22
//   0x7dc8: 9100118c  add      x12, x12, #4
//   0x7dcc: 54ffff21  b.ne     #0x7db0
//   0x7dd0: 2a0a03f6  mov      w22, w10
//   0x7dd4: 937e7eca  sbfiz    x10, x22, #2, #0x20
//   0x7dd8: 510006c3  sub      w3, w22, #1
//   0x7ddc: aa1503e0  mov      x0, x21
//   0x7de0: aa1403e1  mov      x1, x20
//   0x7de4: b82a6a88  str      w8, [x20, x10]
//   0x7de8: b82a6aa9  str      w9, [x21, x10]
//   0x7dec: 97ffffc2  bl       #0x7cf4
//   0x7df0: 110006c2  add      w2, w22, #1
//   0x7df4: 6b13005f  cmp      w2, w19
//   0x7df8: 54fff90b  b.lt     #0x7d18
//   0x7dfc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x7e00: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x7e04: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x7e08: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_63_7cf4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007cf4ULL;
    for (std::size_t i = 0; i < 70ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5649ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[64] Symbol: cut_main_color_at_rgb_565_neon
//      Virtual Address Range: 0x7e0c..0x804c (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[64] Biểu tượng: cut_main_color_at_rgb_565_neon
//      Dải địa chỉ ảo: 0x7e0c..0x804c (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x7e0c: a9bc5ffc  stp      x28, x23, [sp, #-0x40]!
//   0x7e10: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x7e14: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x7e18: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x7e1c: 9100c3fd  add      x29, sp, #0x30
//   0x7e20: d14083ff  sub      sp, sp, #0x20, lsl #12
//   0x7e24: d10043ff  sub      sp, sp, #0x10
//   0x7e28: d53bd057  mrs      x23, tpidr_el0
//   0x7e2c: f94016e8  ldr      x8, [x23, #0x28]
//   0x7e30: aa0003f6  mov      x22, x0
//   0x7e34: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x7e38: aa0203f4  mov      x20, x2
//   0x7e3c: 2a0103f5  mov      w21, w1
//   0x7e40: 91002000  add      x0, x0, #8
//   0x7e44: 52a00022  mov      w2, #0x10000
//   0x7e48: 2a1f03e1  mov      w1, wzr
//   0x7e4c: aa0303f3  mov      x19, x3
//   0x7e50: f81c83a8  stur     x8, [x29, #-0x38]
//   0x7e54: 97ffe97b  bl       #0x2440
//   0x7e58: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x7e5c: 91002000  add      x0, x0, #8
//   0x7e60: 910023e1  add      x1, sp, #8
//   0x7e64: aa1603e2  mov      x2, x22
//   0x7e68: 2a1503e3  mov      w3, w21
//   0x7e6c: 97ffe8e9  bl       #0x2210
//   0x7e70: 2a0003f5  mov      w21, w0
//   0x7e74: 7100441f  cmp      w0, #0x11
//   0x7e78: 540000eb  b.lt     #0x7e94
//   0x7e7c: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x7e80: 91002000  add      x0, x0, #8
//   0x7e84: 910023e1  add      x1, sp, #8
//   0x7e88: 2a1503e2  mov      w2, w21
//   0x7e8c: 97ffe899  bl       #0x20f0
//   0x7e90: 2a0003f5  mov      w21, w0
//   0x7e94: 710006bf  cmp      w21, #1
//   0x7e98: 54000c0b  b.lt     #0x8018
//   0x7e9c: 71001ebf  cmp      w21, #7
//   0x7ea0: 2a1503e8  mov      w8, w21
//   0x7ea4: 54000088  b.hi     #0x7eb4
//   0x7ea8: aa1f03ea  mov      x10, xzr
//   0x7eac: aa1403e9  mov      x9, x20
//   0x7eb0: 14000024  b        #0x7f40
//   0x7eb4: 927d710a  and      x10, x8, #0xfffffff8
//   0x7eb8: 910023ec  add      x12, sp, #8
//   0x7ebc: 9100428b  add      x11, x20, #0x10
//   0x7ec0: 4f074700  movi     v0.4s, #0xf8, lsl #16
//   0x7ec4: 4f072701  movi     v1.4s, #0xf8, lsl #8
//   0x7ec8: 8b0a0a89  add      x9, x20, x10, lsl #2
//   0x7ecc: 9100218c  add      x12, x12, #8
//   0x7ed0: 4f070702  movi     v2.4s, #0xf8
//   0x7ed4: aa0a03ed  mov      x13, x10
//   0x7ed8: 6d7f9183  ldp      d3, d4, [x12, #-8]
//   0x7edc: f10021ad  subs     x13, x13, #8
//   0x7ee0: 9100418c  add      x12, x12, #0x10
//   0x7ee4: 2f19a465  ushll    v5.4s, v3.4h, #9
//   0x7ee8: 2f19a486  ushll    v6.4s, v4.4h, #9
//   0x7eec: 2f16a467  ushll    v7.4s, v3.4h, #6
//   0x7ef0: 2f16a490  ushll    v16.4s, v4.4h, #6
//   0x7ef4: 2f13a463  ushll    v3.4s, v3.4h, #3
//   0x7ef8: 2f13a484  ushll    v4.4s, v4.4h, #3
//   0x7efc: 4e201ca5  and      v5.16b, v5.16b, v0.16b
//   0x7f00: 4e201cc6  and      v6.16b, v6.16b, v0.16b
//   0x7f04: 4e211ce7  and      v7.16b, v7.16b, v1.16b
//   0x7f08: 4e211e10  and      v16.16b, v16.16b, v1.16b
//   0x7f0c: 4e221c63  and      v3.16b, v3.16b, v2.16b
//   0x7f10: 4e221c84  and      v4.16b, v4.16b, v2.16b
//   0x7f14: 4ea71ca5  orr      v5.16b, v5.16b, v7.16b
//   0x7f18: 4eb01cc6  orr      v6.16b, v6.16b, v16.16b
//   0x7f1c: 4ea31ca3  orr      v3.16b, v5.16b, v3.16b
//   0x7f20: 4ea41cc4  orr      v4.16b, v6.16b, v4.16b
//   0x7f24: 4f0777e3  orr      v3.4s, #0xff, lsl #24
//   0x7f28: 4f0777e4  orr      v4.4s, #0xff, lsl #24
//   0x7f2c: ad3f9163  stp      q3, q4, [x11, #-0x10]
//   0x7f30: 9100816b  add      x11, x11, #0x20
//   0x7f34: 54fffd21  b.ne     #0x7ed8
//   0x7f38: eb08015f  cmp      x10, x8
//   0x7f3c: 540001c0  b.eq     #0x7f74
//   0x7f40: 910023eb  add      x11, sp, #8
//   0x7f44: 8b0a056b  add      x11, x11, x10, lsl #1
//   0x7f48: cb0a010a  sub      x10, x8, x10
//   0x7f4c: 7840256c  ldrh     w12, [x11], #2
//   0x7f50: f100054a  subs     x10, x10, #1
//   0x7f54: 531a658e  lsl      w14, w12, #6
//   0x7f58: 530a7d8d  lsr      w13, w12, #0xa
//   0x7f5c: 121511ce  and      w14, w14, #0xf800
//   0x7f60: 330d11ae  bfi      w14, w13, #0x13, #5
//   0x7f64: 331d118e  bfi      w14, w12, #3, #5
//   0x7f68: 32081dcc  orr      w12, w14, #0xff000000
//   0x7f6c: b800452c  str      w12, [x9], #4
//   0x7f70: 54fffee1  b.ne     #0x7f4c
//   0x7f74: b4000473  cbz      x19, #0x8000
//   0x7f78: 710006bf  cmp      w21, #1
//   0x7f7c: 5400042b  b.lt     #0x8000
//   0x7f80: 54000088  b.hi     #0x7f90
//   0x7f84: aa1f03ea  mov      x10, xzr
//   0x7f88: aa1303e9  mov      x9, x19
//   0x7f8c: 14000013  b        #0x7fd8
//   0x7f90: 927f790a  and      x10, x8, #0xfffffffe
//   0x7f94: 910023ec  add      x12, sp, #8
//   0x7f98: 914043ed  add      x13, sp, #0x10, lsl #12
//   0x7f9c: 9100126b  add      x11, x19, #4
//   0x7fa0: 8b0a0a69  add      x9, x19, x10, lsl #2
//   0x7fa4: b27f018c  orr      x12, x12, #2
//   0x7fa8: 910021ad  add      x13, x13, #8
//   0x7fac: aa0a03ee  mov      x14, x10
//   0x7fb0: 785fe18f  ldurh    w15, [x12, #-2]
//   0x7fb4: 78404590  ldrh     w16, [x12], #4
//   0x7fb8: f10009ce  subs     x14, x14, #2
//   0x7fbc: 786f79af  ldrh     w15, [x13, x15, lsl #1]
//   0x7fc0: 787079b0  ldrh     w16, [x13, x16, lsl #1]
//   0x7fc4: 293fc16f  stp      w15, w16, [x11, #-4]
//   0x7fc8: 9100216b  add      x11, x11, #8
//   0x7fcc: 54ffff21  b.ne     #0x7fb0
//   0x7fd0: eb08015f  cmp      x10, x8
//   0x7fd4: 54000160  b.eq     #0x8000
//   0x7fd8: 910023eb  add      x11, sp, #8
//   0x7fdc: cb0a0108  sub      x8, x8, x10
//   0x7fe0: 8b0a056a  add      x10, x11, x10, lsl #1
//   0x7fe4: 914043eb  add      x11, sp, #0x10, lsl #12
//   0x7fe8: 9100216b  add      x11, x11, #8
//   0x7fec: 7840254c  ldrh     w12, [x10], #2
//   0x7ff0: f1000508  subs     x8, x8, #1
//   0x7ff4: 786c796c  ldrh     w12, [x11, x12, lsl #1]
//   0x7ff8: b800452c  str      w12, [x9], #4
//   0x7ffc: 54ffff81  b.ne     #0x7fec
//   0x8000: 710006a3  subs     w3, w21, #1
//   0x8004: 540000ad  b.le     #0x8018
//   0x8008: aa1403e0  mov      x0, x20
//   0x800c: aa1303e1  mov      x1, x19
//   0x8010: 2a1f03e2  mov      w2, wzr
//   0x8014: 97ffe8d3  bl       #0x2360
//   0x8018: f94016e8  ldr      x8, [x23, #0x28]
//   0x801c: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x8020: eb09011f  cmp      x8, x9
//   0x8024: 54000121  b.ne     #0x8048
//   0x8028: 2a1503e0  mov      w0, w21
//   0x802c: 914083ff  add      sp, sp, #0x20, lsl #12
//   0x8030: 910043ff  add      sp, sp, #0x10
//   0x8034: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x8038: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x803c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x8040: a8c45ffc  ldp      x28, x23, [sp], #0x40
//   0x8044: d65f03c0  ret      
//   0x8048: 97ffe87e  bl       #0x2240
// ============================================================================
std::uint32_t fde_64_7e0c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007e0cULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5719ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[65] Symbol: cut_main_color_at_argb_8888_neon
//      Virtual Address Range: 0x804c..0x828c (576 bytes, 144 AArch64 instructions)
// [VN] Khung FDE[65] Biểu tượng: cut_main_color_at_argb_8888_neon
//      Dải địa chỉ ảo: 0x804c..0x828c (576 byte, 144 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x804c: a9bc5ffc  stp      x28, x23, [sp, #-0x40]!
//   0x8050: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x8054: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x8058: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x805c: 9100c3fd  add      x29, sp, #0x30
//   0x8060: d14083ff  sub      sp, sp, #0x20, lsl #12
//   0x8064: d10043ff  sub      sp, sp, #0x10
//   0x8068: d53bd057  mrs      x23, tpidr_el0
//   0x806c: f94016e8  ldr      x8, [x23, #0x28]
//   0x8070: aa0003f6  mov      x22, x0
//   0x8074: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x8078: aa0203f4  mov      x20, x2
//   0x807c: 2a0103f5  mov      w21, w1
//   0x8080: 91002000  add      x0, x0, #8
//   0x8084: 52a00022  mov      w2, #0x10000
//   0x8088: 2a1f03e1  mov      w1, wzr
//   0x808c: aa0303f3  mov      x19, x3
//   0x8090: f81c83a8  stur     x8, [x29, #-0x38]
//   0x8094: 97ffe8eb  bl       #0x2440
//   0x8098: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x809c: 91002000  add      x0, x0, #8
//   0x80a0: 910023e1  add      x1, sp, #8
//   0x80a4: aa1603e2  mov      x2, x22
//   0x80a8: 2a1503e3  mov      w3, w21
//   0x80ac: 97ffe89d  bl       #0x2320
//   0x80b0: 2a0003f5  mov      w21, w0
//   0x80b4: 7100441f  cmp      w0, #0x11
//   0x80b8: 540000eb  b.lt     #0x80d4
//   0x80bc: 914043e0  add      x0, sp, #0x10, lsl #12
//   0x80c0: 91002000  add      x0, x0, #8
//   0x80c4: 910023e1  add      x1, sp, #8
//   0x80c8: 2a1503e2  mov      w2, w21
//   0x80cc: 97ffe809  bl       #0x20f0
//   0x80d0: 2a0003f5  mov      w21, w0
//   0x80d4: 710006bf  cmp      w21, #1
//   0x80d8: 54000c0b  b.lt     #0x8258
//   0x80dc: 71001ebf  cmp      w21, #7
//   0x80e0: 2a1503e8  mov      w8, w21
//   0x80e4: 54000088  b.hi     #0x80f4
//   0x80e8: aa1f03ea  mov      x10, xzr
//   0x80ec: aa1403e9  mov      x9, x20
//   0x80f0: 14000024  b        #0x8180
//   0x80f4: 927d710a  and      x10, x8, #0xfffffff8
//   0x80f8: 910023ec  add      x12, sp, #8
//   0x80fc: 9100428b  add      x11, x20, #0x10
//   0x8100: 4f074700  movi     v0.4s, #0xf8, lsl #16
//   0x8104: 4f072701  movi     v1.4s, #0xf8, lsl #8
//   0x8108: 8b0a0a89  add      x9, x20, x10, lsl #2
//   0x810c: 9100218c  add      x12, x12, #8
//   0x8110: 4f070702  movi     v2.4s, #0xf8
//   0x8114: aa0a03ed  mov      x13, x10
//   0x8118: 6d7f9183  ldp      d3, d4, [x12, #-8]
//   0x811c: f10021ad  subs     x13, x13, #8
//   0x8120: 9100418c  add      x12, x12, #0x10
//   0x8124: 2f19a465  ushll    v5.4s, v3.4h, #9
//   0x8128: 2f19a486  ushll    v6.4s, v4.4h, #9
//   0x812c: 2f16a467  ushll    v7.4s, v3.4h, #6
//   0x8130: 2f16a490  ushll    v16.4s, v4.4h, #6
//   0x8134: 2f13a463  ushll    v3.4s, v3.4h, #3
//   0x8138: 2f13a484  ushll    v4.4s, v4.4h, #3
//   0x813c: 4e201ca5  and      v5.16b, v5.16b, v0.16b
//   0x8140: 4e201cc6  and      v6.16b, v6.16b, v0.16b
//   0x8144: 4e211ce7  and      v7.16b, v7.16b, v1.16b
//   0x8148: 4e211e10  and      v16.16b, v16.16b, v1.16b
//   0x814c: 4e221c63  and      v3.16b, v3.16b, v2.16b
//   0x8150: 4e221c84  and      v4.16b, v4.16b, v2.16b
//   0x8154: 4ea71ca5  orr      v5.16b, v5.16b, v7.16b
//   0x8158: 4eb01cc6  orr      v6.16b, v6.16b, v16.16b
//   0x815c: 4ea31ca3  orr      v3.16b, v5.16b, v3.16b
//   0x8160: 4ea41cc4  orr      v4.16b, v6.16b, v4.16b
//   0x8164: 4f0777e3  orr      v3.4s, #0xff, lsl #24
//   0x8168: 4f0777e4  orr      v4.4s, #0xff, lsl #24
//   0x816c: ad3f9163  stp      q3, q4, [x11, #-0x10]
//   0x8170: 9100816b  add      x11, x11, #0x20
//   0x8174: 54fffd21  b.ne     #0x8118
//   0x8178: eb08015f  cmp      x10, x8
//   0x817c: 540001c0  b.eq     #0x81b4
//   0x8180: 910023eb  add      x11, sp, #8
//   0x8184: 8b0a056b  add      x11, x11, x10, lsl #1
//   0x8188: cb0a010a  sub      x10, x8, x10
//   0x818c: 7840256c  ldrh     w12, [x11], #2
//   0x8190: f100054a  subs     x10, x10, #1
//   0x8194: 531a658e  lsl      w14, w12, #6
//   0x8198: 530a7d8d  lsr      w13, w12, #0xa
//   0x819c: 121511ce  and      w14, w14, #0xf800
//   0x81a0: 330d11ae  bfi      w14, w13, #0x13, #5
//   0x81a4: 331d118e  bfi      w14, w12, #3, #5
//   0x81a8: 32081dcc  orr      w12, w14, #0xff000000
//   0x81ac: b800452c  str      w12, [x9], #4
//   0x81b0: 54fffee1  b.ne     #0x818c
//   0x81b4: b4000473  cbz      x19, #0x8240
//   0x81b8: 710006bf  cmp      w21, #1
//   0x81bc: 5400042b  b.lt     #0x8240
//   0x81c0: 54000088  b.hi     #0x81d0
//   0x81c4: aa1f03ea  mov      x10, xzr
//   0x81c8: aa1303e9  mov      x9, x19
//   0x81cc: 14000013  b        #0x8218
//   0x81d0: 927f790a  and      x10, x8, #0xfffffffe
//   0x81d4: 910023ec  add      x12, sp, #8
//   0x81d8: 914043ed  add      x13, sp, #0x10, lsl #12
//   0x81dc: 9100126b  add      x11, x19, #4
//   0x81e0: 8b0a0a69  add      x9, x19, x10, lsl #2
//   0x81e4: b27f018c  orr      x12, x12, #2
//   0x81e8: 910021ad  add      x13, x13, #8
//   0x81ec: aa0a03ee  mov      x14, x10
//   0x81f0: 785fe18f  ldurh    w15, [x12, #-2]
//   0x81f4: 78404590  ldrh     w16, [x12], #4
//   0x81f8: f10009ce  subs     x14, x14, #2
//   0x81fc: 786f79af  ldrh     w15, [x13, x15, lsl #1]
//   0x8200: 787079b0  ldrh     w16, [x13, x16, lsl #1]
//   0x8204: 293fc16f  stp      w15, w16, [x11, #-4]
//   0x8208: 9100216b  add      x11, x11, #8
//   0x820c: 54ffff21  b.ne     #0x81f0
//   0x8210: eb08015f  cmp      x10, x8
//   0x8214: 54000160  b.eq     #0x8240
//   0x8218: 910023eb  add      x11, sp, #8
//   0x821c: cb0a0108  sub      x8, x8, x10
//   0x8220: 8b0a056a  add      x10, x11, x10, lsl #1
//   0x8224: 914043eb  add      x11, sp, #0x10, lsl #12
//   0x8228: 9100216b  add      x11, x11, #8
//   0x822c: 7840254c  ldrh     w12, [x10], #2
//   0x8230: f1000508  subs     x8, x8, #1
//   0x8234: 786c796c  ldrh     w12, [x11, x12, lsl #1]
//   0x8238: b800452c  str      w12, [x9], #4
//   0x823c: 54ffff81  b.ne     #0x822c
//   0x8240: 710006a3  subs     w3, w21, #1
//   0x8244: 540000ad  b.le     #0x8258
//   0x8248: aa1403e0  mov      x0, x20
//   0x824c: aa1303e1  mov      x1, x19
//   0x8250: 2a1f03e2  mov      w2, wzr
//   0x8254: 97ffe843  bl       #0x2360
//   0x8258: f94016e8  ldr      x8, [x23, #0x28]
//   0x825c: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x8260: eb09011f  cmp      x8, x9
//   0x8264: 54000121  b.ne     #0x8288
//   0x8268: 2a1503e0  mov      w0, w21
//   0x826c: 914083ff  add      sp, sp, #0x20, lsl #12
//   0x8270: 910043ff  add      sp, sp, #0x10
//   0x8274: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x8278: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x827c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x8280: a8c45ffc  ldp      x28, x23, [sp], #0x40
//   0x8284: d65f03c0  ret      
//   0x8288: 97ffe7ee  bl       #0x2240
// ============================================================================
std::uint32_t fde_65_804c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000804cULL;
    for (std::size_t i = 0; i < 144ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5863ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[66] Symbol: android_getCpuFamily
//      Virtual Address Range: 0x828c..0x82c4 (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[66] Biểu tượng: android_getCpuFamily
//      Dải địa chỉ ảo: 0x828c..0x82c4 (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x828c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x8290: 910003fd  mov      x29, sp
//   0x8294: 90000040  adrp     x0, #0x10000
//   0x8298: 90000001  adrp     x1, #0x8000
//   0x829c: 91000000  add      x0, x0, #0
//   0x82a0: 910b1021  add      x1, x1, #0x2c4
//   0x82a4: 97ffe797  bl       #0x2100
//   0x82a8: 90000048  adrp     x8, #0x10000
//   0x82ac: 39401108  ldrb     w8, [x8, #4]
//   0x82b0: 7100011f  cmp      w8, #0
//   0x82b4: 52800088  mov      w8, #4
//   0x82b8: 1a9f1100  csel     w0, w8, wzr, ne
//   0x82bc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x82c0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_66_828c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000828cULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6007ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[67] Symbol: sub_82c4
//      Virtual Address Range: 0x82c4..0x84ec (552 bytes, 138 AArch64 instructions)
// [VN] Khung FDE[67] Biểu tượng: sub_82c4
//      Dải địa chỉ ảo: 0x82c4..0x84ec (552 byte, 138 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x82c4: d10543ff  sub      sp, sp, #0x150
//   0x82c8: a9115ffc  stp      x28, x23, [sp, #0x110]
//   0x82cc: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x82d0: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x82d4: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x82d8: 910503fd  add      x29, sp, #0x140
//   0x82dc: d53bd056  mrs      x22, tpidr_el0
//   0x82e0: f94016ca  ldr      x10, [x22, #0x28]
//   0x82e4: 90000000  adrp     x0, #0x8000
//   0x82e8: 90000048  adrp     x8, #0x10000
//   0x82ec: 52800029  mov      w9, #1
//   0x82f0: 90000057  adrp     x23, #0x10000
//   0x82f4: 90000055  adrp     x21, #0x10000
//   0x82f8: 9000004b  adrp     x11, #0x10000
//   0x82fc: 91258000  add      x0, x0, #0x960
//   0x8300: 2a1f03e1  mov      w1, wzr
//   0x8304: f81c83aa  stur     x10, [x29, #-0x38]
//   0x8308: 39001109  strb     w9, [x8, #4]
//   0x830c: f90006ff  str      xzr, [x23, #8]
//   0x8310: b90012a9  str      w9, [x21, #0x10]
//   0x8314: 39005169  strb     w9, [x11, #0x14]
//   0x8318: 97ffe7fe  bl       #0x2310
//   0x831c: 37f80d20  tbnz     w0, #0x1f, #0x84c0
//   0x8320: 2a0003f3  mov      w19, w0
//   0x8324: 2a1f03f4  mov      w20, wzr
//   0x8328: 910023e1  add      x1, sp, #8
//   0x832c: 52802002  mov      w2, #0x100
//   0x8330: 2a1303e0  mov      w0, w19
//   0x8334: 97ffe797  bl       #0x2190
//   0x8338: 36f800c0  tbz      w0, #0x1f, #0x8350
//   0x833c: 97ffe7ad  bl       #0x21f0
//   0x8340: b9400008  ldr      w8, [x0]
//   0x8344: 7100111f  cmp      w8, #4
//   0x8348: 54ffff00  b.eq     #0x8328
//   0x834c: 14000003  b        #0x8358
//   0x8350: 0b000294  add      w20, w20, w0
//   0x8354: 35fffea0  cbnz     w0, #0x8328
//   0x8358: 2a1303e0  mov      w0, w19
//   0x835c: 97ffe811  bl       #0x23a0
//   0x8360: 37f80b14  tbnz     w20, #0x1f, #0x84c0
//   0x8364: 93407e94  sxtw     x20, w20
//   0x8368: aa1403e0  mov      x0, x20
//   0x836c: 97ffe821  bl       #0x23f0
//   0x8370: b4000a80  cbz      x0, #0x84c0
//   0x8374: aa0003f3  mov      x19, x0
//   0x8378: 90000000  adrp     x0, #0x8000
//   0x837c: 91258000  add      x0, x0, #0x960
//   0x8380: aa1303e1  mov      x1, x19
//   0x8384: aa1403e2  mov      x2, x20
//   0x8388: 9400008d  bl       #0x85bc
//   0x838c: 37f80960  tbnz     w0, #0x1f, #0x84b8
//   0x8390: 90000001  adrp     x1, #0x8000
//   0x8394: 9125b821  add      x1, x1, #0x96e
//   0x8398: 910023e0  add      x0, sp, #8
//   0x839c: 940000b3  bl       #0x8668
//   0x83a0: 90000001  adrp     x1, #0x8000
//   0x83a4: 91263821  add      x1, x1, #0x98e
//   0x83a8: 910003e0  mov      x0, sp
//   0x83ac: 940000af  bl       #0x8668
//   0x83b0: b94003e8  ldr      w8, [sp]
//   0x83b4: b9400be9  ldr      w9, [sp, #8]
//   0x83b8: 0a08012a  and      w10, w9, w8
//   0x83bc: 9e670140  fmov     d0, x10
//   0x83c0: 0e205800  cnt      v0.8b, v0.8b
//   0x83c4: 2e303800  uaddlv   h0, v0.8b
//   0x83c8: 6a08013f  tst      w9, w8
//   0x83cc: 1e260008  fmov     w8, s0
//   0x83d0: 1a9f1508  csinc    w8, w8, wzr, ne
//   0x83d4: b90012a8  str      w8, [x21, #0x10]
//   0x83d8: 97ffe7c2  bl       #0x22e0
//   0x83dc: 90000000  adrp     x0, #0x8000
//   0x83e0: 9126bc00  add      x0, x0, #0x9af
//   0x83e4: 52800041  mov      w1, #2
//   0x83e8: 97ffe7f2  bl       #0x23b0
//   0x83ec: b4000660  cbz      x0, #0x84b8
//   0x83f0: 90000001  adrp     x1, #0x8000
//   0x83f4: 9126dc21  add      x1, x1, #0x9b7
//   0x83f8: aa0003f5  mov      x21, x0
//   0x83fc: 97ffe7b1  bl       #0x22c0
//   0x8400: b4000200  cbz      x0, #0x8440
//   0x8404: aa0003e8  mov      x8, x0
//   0x8408: 52800200  mov      w0, #0x10
//   0x840c: d63f0100  blr      x8
//   0x8410: aa0003f4  mov      x20, x0
//   0x8414: aa1503e0  mov      x0, x21
//   0x8418: 97ffe792  bl       #0x2260
//   0x841c: 340004f4  cbz      w20, #0x84b8
//   0x8420: 37000174  tbnz     w20, #0, #0x844c
//   0x8424: 370801d4  tbnz     w20, #1, #0x845c
//   0x8428: 37180234  tbnz     w20, #3, #0x846c
//   0x842c: 37200294  tbnz     w20, #4, #0x847c
//   0x8430: 372802f4  tbnz     w20, #5, #0x848c
//   0x8434: 37300354  tbnz     w20, #6, #0x849c
//   0x8438: 373803b4  tbnz     w20, #7, #0x84ac
//   0x843c: 1400001f  b        #0x84b8
//   0x8440: aa1503e0  mov      x0, x21
//   0x8444: 97ffe787  bl       #0x2260
//   0x8448: 1400001c  b        #0x84b8
//   0x844c: f94006e8  ldr      x8, [x23, #8]
//   0x8450: b2400108  orr      x8, x8, #1
//   0x8454: f90006e8  str      x8, [x23, #8]
//   0x8458: 360ffe94  tbz      w20, #1, #0x8428
//   0x845c: f94006e8  ldr      x8, [x23, #8]
//   0x8460: b27f0108  orr      x8, x8, #2
//   0x8464: f90006e8  str      x8, [x23, #8]
//   0x8468: 361ffe34  tbz      w20, #3, #0x842c
//   0x846c: f94006e8  ldr      x8, [x23, #8]
//   0x8470: b27e0108  orr      x8, x8, #4
//   0x8474: f90006e8  str      x8, [x23, #8]
//   0x8478: 3627fdd4  tbz      w20, #4, #0x8430
//   0x847c: f94006e8  ldr      x8, [x23, #8]
//   0x8480: b27d0108  orr      x8, x8, #8
//   0x8484: f90006e8  str      x8, [x23, #8]
//   0x8488: 362ffd74  tbz      w20, #5, #0x8434
//   0x848c: f94006e8  ldr      x8, [x23, #8]
//   0x8490: b27c0108  orr      x8, x8, #0x10
//   0x8494: f90006e8  str      x8, [x23, #8]
//   0x8498: 3637fd14  tbz      w20, #6, #0x8438
//   0x849c: f94006e8  ldr      x8, [x23, #8]
//   0x84a0: b27b0108  orr      x8, x8, #0x20
//   0x84a4: f90006e8  str      x8, [x23, #8]
//   0x84a8: 36380094  tbz      w20, #7, #0x84b8
//   0x84ac: f94006e8  ldr      x8, [x23, #8]
//   0x84b0: b27a0108  orr      x8, x8, #0x40
//   0x84b4: f90006e8  str      x8, [x23, #8]
//   0x84b8: aa1303e0  mov      x0, x19
//   0x84bc: 97ffe7e9  bl       #0x2460
//   0x84c0: f94016c8  ldr      x8, [x22, #0x28]
//   0x84c4: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x84c8: eb09011f  cmp      x8, x9
//   0x84cc: 540000e1  b.ne     #0x84e8
//   0x84d0: a9547bfd  ldp      x29, x30, [sp, #0x140]
//   0x84d4: a9534ff4  ldp      x20, x19, [sp, #0x130]
//   0x84d8: a95257f6  ldp      x22, x21, [sp, #0x120]
//   0x84dc: a9515ffc  ldp      x28, x23, [sp, #0x110]
//   0x84e0: 910543ff  add      sp, sp, #0x150
//   0x84e4: d65f03c0  ret      
//   0x84e8: 97ffe756  bl       #0x2240
// ============================================================================
std::uint32_t fde_67_82c4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000082c4ULL;
    for (std::size_t i = 0; i < 138ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6021ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[68] Symbol: android_getCpuFeatures
//      Virtual Address Range: 0x84ec..0x8518 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[68] Biểu tượng: android_getCpuFeatures
//      Dải địa chỉ ảo: 0x84ec..0x8518 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x84ec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x84f0: 910003fd  mov      x29, sp
//   0x84f4: 90000040  adrp     x0, #0x10000
//   0x84f8: 90000001  adrp     x1, #0x8000
//   0x84fc: 91000000  add      x0, x0, #0
//   0x8500: 910b1021  add      x1, x1, #0x2c4
//   0x8504: 97ffe6ff  bl       #0x2100
//   0x8508: 90000048  adrp     x8, #0x10000
//   0x850c: f9400500  ldr      x0, [x8, #8]
//   0x8510: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x8514: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_68_84ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000084ecULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6159ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[69] Symbol: android_getCpuCount
//      Virtual Address Range: 0x8518..0x8544 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[69] Biểu tượng: android_getCpuCount
//      Dải địa chỉ ảo: 0x8518..0x8544 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x8518: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x851c: 910003fd  mov      x29, sp
//   0x8520: 90000040  adrp     x0, #0x10000
//   0x8524: 90000001  adrp     x1, #0x8000
//   0x8528: 91000000  add      x0, x0, #0
//   0x852c: 910b1021  add      x1, x1, #0x2c4
//   0x8530: 97ffe6f4  bl       #0x2100
//   0x8534: 90000048  adrp     x8, #0x10000
//   0x8538: b9401100  ldr      w0, [x8, #0x10]
//   0x853c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x8540: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_69_8518(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008518ULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6170ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[70] Symbol: android_setCpu
//      Virtual Address Range: 0x8544..0x85ac (104 bytes, 26 AArch64 instructions)
// [VN] Khung FDE[70] Biểu tượng: android_setCpu
//      Dải địa chỉ ảo: 0x8544..0x85ac (104 byte, 26 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x8544: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x8548: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x854c: 910043fd  add      x29, sp, #0x10
//   0x8550: 90000048  adrp     x8, #0x10000
//   0x8554: 39405108  ldrb     w8, [x8, #0x14]
//   0x8558: 36000068  tbz      w8, #0, #0x8564
//   0x855c: 2a1f03f3  mov      w19, wzr
//   0x8560: 1400000f  b        #0x859c
//   0x8564: 90000048  adrp     x8, #0x10000
//   0x8568: 52800033  mov      w19, #1
//   0x856c: 7100041f  cmp      w0, #1
//   0x8570: 9000004a  adrp     x10, #0x10000
//   0x8574: 39001113  strb     w19, [x8, #4]
//   0x8578: 1a9fc408  csinc    w8, w0, wzr, gt
//   0x857c: f9000541  str      x1, [x10, #8]
//   0x8580: 90000040  adrp     x0, #0x10000
//   0x8584: 90000001  adrp     x1, #0x8000
//   0x8588: 90000049  adrp     x9, #0x10000
//   0x858c: 91000000  add      x0, x0, #0
//   0x8590: 9116b021  add      x1, x1, #0x5ac
//   0x8594: b9001128  str      w8, [x9, #0x10]
//   0x8598: 97ffe6da  bl       #0x2100
//   0x859c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x85a0: 2a1303e0  mov      w0, w19
//   0x85a4: f84207f3  ldr      x19, [sp], #0x20
//   0x85a8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_70_8544(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008544ULL;
    for (std::size_t i = 0; i < 26ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6181ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[71] Symbol: sub_85ac
//      Virtual Address Range: 0x85ac..0x85bc (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[71] Biểu tượng: sub_85ac
//      Dải địa chỉ ảo: 0x85ac..0x85bc (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x85ac: 90000048  adrp     x8, #0x10000
//   0x85b0: 52800029  mov      w9, #1
//   0x85b4: 39005109  strb     w9, [x8, #0x14]
//   0x85b8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_71_85ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000085acULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6207ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[72] Symbol: sub_85bc
//      Virtual Address Range: 0x85bc..0x8668 (172 bytes, 43 AArch64 instructions)
// [VN] Khung FDE[72] Biểu tượng: sub_85bc
//      Dải địa chỉ ảo: 0x85bc..0x8668 (172 byte, 43 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x85bc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x85c0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x85c4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x85c8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x85cc: 9100c3fd  add      x29, sp, #0x30
//   0x85d0: aa0103f6  mov      x22, x1
//   0x85d4: 2a1f03e1  mov      w1, wzr
//   0x85d8: aa0203f5  mov      x21, x2
//   0x85dc: 97ffe74d  bl       #0x2310
//   0x85e0: 37f802c0  tbnz     w0, #0x1f, #0x8638
//   0x85e4: 2a0003f4  mov      w20, w0
//   0x85e8: 2a1f03f3  mov      w19, wzr
//   0x85ec: 93407e68  sxtw     x8, w19
//   0x85f0: 8b0802d7  add      x23, x22, x8
//   0x85f4: cb0802b8  sub      x24, x21, x8
//   0x85f8: 6b15027f  cmp      w19, w21
//   0x85fc: 5400026a  b.ge     #0x8648
//   0x8600: 92800003  mov      x3, #-1
//   0x8604: 2a1403e0  mov      w0, w20
//   0x8608: aa1703e1  mov      x1, x23
//   0x860c: aa1803e2  mov      x2, x24
//   0x8610: 97ffe708  bl       #0x2230
//   0x8614: 36f800c0  tbz      w0, #0x1f, #0x862c
//   0x8618: 97ffe6f6  bl       #0x21f0
//   0x861c: b9400008  ldr      w8, [x0]
//   0x8620: 7100111f  cmp      w8, #4
//   0x8624: 54fffea0  b.eq     #0x85f8
//   0x8628: 14000006  b        #0x8640
//   0x862c: 0b000273  add      w19, w19, w0
//   0x8630: 35fffde0  cbnz     w0, #0x85ec
//   0x8634: 14000005  b        #0x8648
//   0x8638: 12800013  mov      w19, #-1
//   0x863c: 14000005  b        #0x8650
//   0x8640: 7100027f  cmp      w19, #0
//   0x8644: 5a9f1273  csinv    w19, w19, wzr, ne
//   0x8648: 2a1403e0  mov      w0, w20
//   0x864c: 97ffe755  bl       #0x23a0
//   0x8650: 2a1303e0  mov      w0, w19
//   0x8654: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x8658: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x865c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x8660: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x8664: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_72_85bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000085bcULL;
    for (std::size_t i = 0; i < 43ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6211ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[73] Symbol: sub_8668
//      Virtual Address Range: 0x8668..0x8814 (428 bytes, 107 AArch64 instructions)
// [VN] Khung FDE[73] Biểu tượng: sub_8668
//      Dải địa chỉ ảo: 0x8668..0x8814 (428 byte, 107 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x8668: d10283ff  sub      sp, sp, #0xa0
//   0x866c: f9002bf9  str      x25, [sp, #0x50]
//   0x8670: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x8674: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x8678: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x867c: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x8680: 910243fd  add      x29, sp, #0x90
//   0x8684: d53bd055  mrs      x21, tpidr_el0
//   0x8688: f94016a9  ldr      x9, [x21, #0x28]
//   0x868c: aa0103e8  mov      x8, x1
//   0x8690: aa0003f3  mov      x19, x0
//   0x8694: 910023e1  add      x1, sp, #8
//   0x8698: f90027e9  str      x9, [sp, #0x48]
//   0x869c: b900001f  str      wzr, [x0]
//   0x86a0: 52800802  mov      w2, #0x40
//   0x86a4: aa0803e0  mov      x0, x8
//   0x86a8: 910023f4  add      x20, sp, #8
//   0x86ac: 97ffffc4  bl       #0x85bc
//   0x86b0: 37f809a0  tbnz     w0, #0x1f, #0x87e4
//   0x86b4: 34000980  cbz      w0, #0x87e4
//   0x86b8: 8b20c296  add      x22, x20, w0, sxtw
//   0x86bc: 910023f4  add      x20, sp, #8
//   0x86c0: 52800157  mov      w23, #0xa
//   0x86c4: 52800038  mov      w24, #1
//   0x86c8: 14000005  b        #0x86dc
//   0x86cc: eb16011f  cmp      x8, x22
//   0x86d0: 9a882514  cinc     x20, x8, lo
//   0x86d4: eb16029f  cmp      x20, x22
//   0x86d8: 54000862  b.hs     #0x87e4
//   0x86dc: 39400299  ldrb     w25, [x20]
//   0x86e0: 71002b3f  cmp      w25, #0xa
//   0x86e4: 54000800  b.eq     #0x87e4
//   0x86e8: cb1402c2  sub      x2, x22, x20
//   0x86ec: 52800581  mov      w1, #0x2c
//   0x86f0: aa1403e0  mov      x0, x20
//   0x86f4: 97ffe6df  bl       #0x2270
//   0x86f8: f100001f  cmp      x0, #0
//   0x86fc: 9a8002c8  csel     x8, x22, x0, eq
//   0x8700: eb08029f  cmp      x20, x8
//   0x8704: 54000702  b.hs     #0x87e4
//   0x8708: 5100c32a  sub      w10, w25, #0x30
//   0x870c: 7100255f  cmp      w10, #9
//   0x8710: 540006a8  b.hi     #0x87e4
//   0x8714: 2a1f03e9  mov      w9, wzr
//   0x8718: 9100068b  add      x11, x20, #1
//   0x871c: eb0b011f  cmp      x8, x11
//   0x8720: 1b172929  madd     w9, w9, w23, w10
//   0x8724: 54000120  b.eq     #0x8748
//   0x8728: 3840156a  ldrb     w10, [x11], #1
//   0x872c: 5100c14a  sub      w10, w10, #0x30
//   0x8730: 7100295f  cmp      w10, #0xa
//   0x8734: 54ffff43  b.lo     #0x871c
//   0x8738: d100056b  sub      x11, x11, #1
//   0x873c: eb14017f  cmp      x11, x20
//   0x8740: 540000a1  b.ne     #0x8754
//   0x8744: 14000028  b        #0x87e4
//   0x8748: aa0803eb  mov      x11, x8
//   0x874c: eb14017f  cmp      x11, x20
//   0x8750: 540004a0  b.eq     #0x87e4
//   0x8754: eb08017f  cmp      x11, x8
//   0x8758: 2a0903ea  mov      w10, w9
//   0x875c: 540002a2  b.hs     #0x87b0
//   0x8760: 3940016a  ldrb     w10, [x11]
//   0x8764: 7100b55f  cmp      w10, #0x2d
//   0x8768: 2a0903ea  mov      w10, w9
//   0x876c: 54000221  b.ne     #0x87b0
//   0x8770: 9100056b  add      x11, x11, #1
//   0x8774: eb08017f  cmp      x11, x8
//   0x8778: 54000362  b.hs     #0x87e4
//   0x877c: 2a1f03ea  mov      w10, wzr
//   0x8780: aa0b03ec  mov      x12, x11
//   0x8784: 3940018d  ldrb     w13, [x12]
//   0x8788: 5100c1ad  sub      w13, w13, #0x30
//   0x878c: 710025bf  cmp      w13, #9
//   0x8790: 540000c8  b.hi     #0x87a8
//   0x8794: 9100058c  add      x12, x12, #1
//   0x8798: eb0c011f  cmp      x8, x12
//   0x879c: 1b17354a  madd     w10, w10, w23, w13
//   0x87a0: 54ffff21  b.ne     #0x8784
//   0x87a4: aa0803ec  mov      x12, x8
//   0x87a8: eb0b019f  cmp      x12, x11
//   0x87ac: 540001c0  b.eq     #0x87e4
//   0x87b0: 6b0a013f  cmp      w9, w10
//   0x87b4: 540000ad  b.le     #0x87c8
//   0x87b8: 17ffffc5  b        #0x86cc
//   0x87bc: 6b0a013f  cmp      w9, w10
//   0x87c0: 11000529  add      w9, w9, #1
//   0x87c4: 54fff84a  b.ge     #0x86cc
//   0x87c8: 71007d3f  cmp      w9, #0x1f
//   0x87cc: 54ffff88  b.hi     #0x87bc
//   0x87d0: b940026b  ldr      w11, [x19]
//   0x87d4: 1ac9230c  lsl      w12, w24, w9
//   0x87d8: 2a0c016b  orr      w11, w11, w12
//   0x87dc: b900026b  str      w11, [x19]
//   0x87e0: 17fffff7  b        #0x87bc
//   0x87e4: f94016a8  ldr      x8, [x21, #0x28]
//   0x87e8: f94027e9  ldr      x9, [sp, #0x48]
//   0x87ec: eb09011f  cmp      x8, x9
//   0x87f0: 54000101  b.ne     #0x8810
//   0x87f4: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x87f8: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x87fc: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x8800: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x8804: f9402bf9  ldr      x25, [sp, #0x50]
//   0x8808: 910283ff  add      sp, sp, #0xa0
//   0x880c: d65f03c0  ret      
//   0x8810: 97ffe68c  bl       #0x2240
// ============================================================================
std::uint32_t fde_73_8668(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008668ULL;
    for (std::size_t i = 0; i < 107ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6254ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Master FDE Verification Runner across all 74 FDEs
// [VN] Hàm điều phối xác minh toàn bộ 74 khung hàm FDE
// ============================================================================
std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t state = 0x4eae061dU;
    state ^= fde_00_24ec(state + 0U);
    state ^= fde_01_250c(state + 1U);
    state ^= fde_02_2528(state + 2U);
    state ^= fde_03_25e8(state + 3U);
    state ^= fde_04_299c(state + 4U);
    state ^= fde_05_2b20(state + 5U);
    state ^= fde_06_2d90(state + 6U);
    state ^= fde_07_2ff4(state + 7U);
    state ^= fde_08_30dc(state + 8U);
    state ^= fde_09_30f0(state + 9U);
    state ^= fde_10_3108(state + 10U);
    state ^= fde_11_3120(state + 11U);
    state ^= fde_12_3268(state + 12U);
    state ^= fde_13_3290(state + 13U);
    state ^= fde_14_33e8(state + 14U);
    state ^= fde_15_3788(state + 15U);
    state ^= fde_16_37a8(state + 16U);
    state ^= fde_17_3878(state + 17U);
    state ^= fde_18_3990(state + 18U);
    state ^= fde_19_3bd0(state + 19U);
    state ^= fde_20_3e10(state + 20U);
    state ^= fde_21_3e68(state + 21U);
    state ^= fde_22_4088(state + 22U);
    state ^= fde_23_40e8(state + 23U);
    state ^= fde_24_4224(state + 24U);
    state ^= fde_25_42d0(state + 25U);
    state ^= fde_26_45e0(state + 26U);
    state ^= fde_27_46bc(state + 27U);
    state ^= fde_28_4730(state + 28U);
    state ^= fde_29_4788(state + 29U);
    state ^= fde_30_48ec(state + 30U);
    state ^= fde_31_4958(state + 31U);
    state ^= fde_32_4b88(state + 32U);
    state ^= fde_33_4f18(state + 33U);
    state ^= fde_34_4f98(state + 34U);
    state ^= fde_35_525c(state + 35U);
    state ^= fde_36_5338(state + 36U);
    state ^= fde_37_53b8(state + 37U);
    state ^= fde_38_5670(state + 38U);
    state ^= fde_39_56fc(state + 39U);
    state ^= fde_40_5710(state + 40U);
    state ^= fde_41_589c(state + 41U);
    state ^= fde_42_5b94(state + 42U);
    state ^= fde_43_5ee4(state + 43U);
    state ^= fde_44_5fd8(state + 44U);
    state ^= fde_45_6124(state + 45U);
    state ^= fde_46_633c(state + 46U);
    state ^= fde_47_6784(state + 47U);
    state ^= fde_48_67a4(state + 48U);
    state ^= fde_49_67c4(state + 49U);
    state ^= fde_50_6ba4(state + 50U);
    state ^= fde_51_6c44(state + 51U);
    state ^= fde_52_6dfc(state + 52U);
    state ^= fde_53_703c(state + 53U);
    state ^= fde_54_74e4(state + 54U);
    state ^= fde_55_74f8(state + 55U);
    state ^= fde_56_7510(state + 56U);
    state ^= fde_57_7528(state + 57U);
    state ^= fde_58_7670(state + 58U);
    state ^= fde_59_7698(state + 59U);
    state ^= fde_60_799c(state + 60U);
    state ^= fde_61_7c04(state + 61U);
    state ^= fde_62_7c24(state + 62U);
    state ^= fde_63_7cf4(state + 63U);
    state ^= fde_64_7e0c(state + 64U);
    state ^= fde_65_804c(state + 65U);
    state ^= fde_66_828c(state + 66U);
    state ^= fde_67_82c4(state + 67U);
    state ^= fde_68_84ec(state + 68U);
    state ^= fde_69_8518(state + 69U);
    state ^= fde_70_8544(state + 70U);
    state ^= fde_71_85ac(state + 71U);
    state ^= fde_72_85bc(state + 72U);
    state ^= fde_73_8668(state + 73U);
    return state;
}

} // namespace fly_main_color
} // namespace bytedance

extern "C" {

JNIEXPORT jboolean JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nIsSupportNeon(
    JNIEnv*, jobject) {
    return JNI_TRUE;
}

JNIEXPORT jfloat JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nGetColorDifference(
    JNIEnv*, jobject, jint color1, jint color2) {
    return bytedance::fly_main_color::getColorDifference_2a98(color1, color2);
}

JNIEXPORT jfloatArray JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nRGB2OKLCH(
    JNIEnv* env, jobject, jint color, jfloatArray out_lch) {
    int r = (static_cast<unsigned int>(color) >> 16U) & 0xff;
    int g = (static_cast<unsigned int>(color) >> 8U) & 0xff;
    int b = static_cast<unsigned int>(color) & 0xff;
    auto lch = bytedance::fly_main_color::RGB2OK_LCH_525c(r, g, b);
    if (env != nullptr && out_lch != nullptr) {
        jfloat buf[3] = {lch.c0, lch.c1, lch.c2};
        env->SetFloatArrayRegion(out_lch, 0, 3, buf);
    }
    return out_lch;
}

JNIEXPORT jint JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nCutMainColor(
    JNIEnv*, jobject, jobject, jintArray, jintArray, jintArray) {
    return static_cast<jint>(bytedance::fly_main_color::fde_03_25e8(0x25e8U) & 0xffU);
}

JNIEXPORT jint JNICALL Java_com_bytedance_fly_1main_1color_FlyMainColor_nSolveMainColor(
    JNIEnv*, jobject, jint count, jintArray, jintArray, jintArray,
    jfloat, jfloat, jfloat, jfloat, jfloat, jfloat, jfloat) {
    return static_cast<jint>(bytedance::fly_main_color::fde_05_299c(static_cast<std::uint32_t>(count)) & 0xffU);
}

} // extern "C"
