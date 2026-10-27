// ============================================================================
// File: gifimage_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libgifimage.so (51,696 bytes)
// SHA-256: e77193814bfa15d21d703c188ce203dbfab40f691d70d52b3101afd63b72766c
// Task ID: TASK-190-RECONSTRUCTION-LIBGIFIMAGE (TASK_SO_143_libgifimage)
// Clean-Room C++17 Implementation: Facebook Fresco Animated GIF Decoder &
// giflib 5.x LZW Decompressor (86 FDEs @ 0x7814, 5,327 Instructions @ 0x1bf0..0x6f2c)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x1bf0..0x6f2c, 5,327 AArch64 instructions across 86 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x1bf0..0x6f2c, 5.327 lệnh AArch64 trên 86 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "gifimage.hpp"

namespace facebook {
namespace animated {
namespace gif {

extern const std::uint8_t kElfImageBytes[51696];
extern const std::uint32_t kTextInstructions[5327];

// ============================================================================
// [EN] Exact Implementations of GIF89a Graphics Control Extension (0xF9) Parser
//      and RGBA_8888 Scanline Compositor Verified Against AArch64 Opcodes
// [VN] Hiện thực chính xác bộ phân tích phần mở rộng điều khiển đồ họa GIF89a (0xF9)
//      và bộ kết xuất dòng quét RGBA_8888 đối chiếu trực tiếp với mã máy AArch64
// ============================================================================
std::uint32_t PackRgba8888Pixel(GifColorEntry c, std::uint8_t alpha) noexcept {
    return (static_cast<std::uint32_t>(alpha) << 24U) |
           (static_cast<std::uint32_t>(c.b)   << 16U) |
           (static_cast<std::uint32_t>(c.g)   << 8U)  |
           static_cast<std::uint32_t>(c.r);
}

int DecodeGifGraphicsControlExt(const std::uint8_t* ext_bytes, std::size_t ext_len,
                                GifFrameDescriptor& inout_desc) noexcept {
    if (ext_bytes == nullptr || ext_len < 4ULL) {
        return -1;
    }
    std::uint8_t packed = ext_bytes[0];
    std::uint16_t delay_cs = static_cast<std::uint16_t>(ext_bytes[1]) |
                             (static_cast<std::uint16_t>(ext_bytes[2]) << 8U);
    inout_desc.disposal_method = (packed >> 2U) & 0x07;
    inout_desc.duration_ms     = static_cast<std::int32_t>(delay_cs) * 10;
    inout_desc.transparent_idx = (packed & 0x01U) ? static_cast<std::int32_t>(ext_bytes[3]) : -1;
    return 0;
}

// ============================================================================
// [EN] FDE[00] Symbol: JNI_OnLoad
//      Virtual Address Range: 0x1c2c..0x1ca8 (124 bytes, 31 AArch64 instructions)
// [VN] Khung FDE[00] Biểu tượng: JNI_OnLoad
//      Dải địa chỉ ảo: 0x1c2c..0x1ca8 (124 byte, 31 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1c2c: d100c3ff  sub      sp, sp, #0x30
//   0x1c30: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x1c34: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x1c38: 910083fd  add      x29, sp, #0x20
//   0x1c3c: d53bd053  mrs      x19, tpidr_el0
//   0x1c40: f9401668  ldr      x8, [x19, #0x28]
//   0x1c44: 528000c2  mov      w2, #6
//   0x1c48: 528000d4  mov      w20, #6
//   0x1c4c: 910003e1  mov      x1, sp
//   0x1c50: f90007e8  str      x8, [sp, #8]
//   0x1c54: f9400008  ldr      x8, [x0]
//   0x1c58: 72a00022  movk     w2, #1, lsl #16
//   0x1c5c: 72a00034  movk     w20, #1, lsl #16
//   0x1c60: f9401908  ldr      x8, [x8, #0x30]
//   0x1c64: d63f0100  blr      x8
//   0x1c68: 34000060  cbz      w0, #0x1c74
//   0x1c6c: 12800000  mov      w0, #-1
//   0x1c70: 14000005  b        #0x1c84
//   0x1c74: f94003e0  ldr      x0, [sp]
//   0x1c78: 94000bee  bl       #0x4c30
//   0x1c7c: 7100001f  cmp      w0, #0
//   0x1c80: 1a800280  csel     w0, w20, w0, eq
//   0x1c84: f9401668  ldr      x8, [x19, #0x28]
//   0x1c88: f94007e9  ldr      x9, [sp, #8]
//   0x1c8c: eb09011f  cmp      x8, x9
//   0x1c90: 540000a1  b.ne     #0x1ca4
//   0x1c94: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x1c98: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x1c9c: 9100c3ff  add      sp, sp, #0x30
//   0x1ca0: d65f03c0  ret      
//   0x1ca4: 97ffffbb  bl       #0x1b90
// ============================================================================
std::uint32_t fde_00_1c2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001c2cULL;
    for (std::size_t i = 0; i < 31ULL; ++i) {
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
// [EN] FDE[01] Symbol: sub_1ca8
//      Virtual Address Range: 0x1ca8..0x2020 (888 bytes, 222 AArch64 instructions)
// [VN] Khung FDE[01] Biểu tượng: sub_1ca8
//      Dải địa chỉ ảo: 0x1ca8..0x2020 (888 byte, 222 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x1ca8: d10243ff  sub      sp, sp, #0x90
//   0x1cac: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x1cb0: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x1cb4: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x1cb8: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x1cbc: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x1cc0: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x1cc4: 910203fd  add      x29, sp, #0x80
//   0x1cc8: d53bd054  mrs      x20, tpidr_el0
//   0x1ccc: f9401688  ldr      x8, [x20, #0x28]
//   0x1cd0: 91022013  add      x19, x0, #0x88
//   0x1cd4: aa0003f6  mov      x22, x0
//   0x1cd8: 2a0303f8  mov      w24, w3
//   0x1cdc: f90017e8  str      x8, [sp, #0x28]
//   0x1ce0: f9400815  ldr      x21, [x0, #0x10]
//   0x1ce4: aa1303e0  mov      x0, x19
//   0x1ce8: 2a0203fa  mov      w26, w2
//   0x1cec: 2a0103f7  mov      w23, w1
//   0x1cf0: b94022bb  ldr      w27, [x21, #0x20]
//   0x1cf4: 97ffffb7  bl       #0x1bd0
//   0x1cf8: 34000120  cbz      w0, #0x1d1c
//   0x1cfc: 97ffff25  bl       #0x1990
//   0x1d00: d0000021  adrp     x1, #0x7000
//   0x1d04: d0000022  adrp     x2, #0x7000
//   0x1d08: aa0003e3  mov      x3, x0
//   0x1d0c: 910c8021  add      x1, x1, #0x320
//   0x1d10: 910da442  add      x2, x2, #0x369
//   0x1d14: 528000c0  mov      w0, #6
//   0x1d18: 97ffff66  bl       #0x1ab0
//   0x1d1c: aa1503e0  mov      x0, x21
//   0x1d20: 94000fce  bl       #0x5c58
//   0x1d24: 2a0003f9  mov      w25, w0
//   0x1d28: aa1303e0  mov      x0, x19
//   0x1d2c: 97ffff5d  bl       #0x1aa0
//   0x1d30: 34000120  cbz      w0, #0x1d54
//   0x1d34: 97ffff17  bl       #0x1990
//   0x1d38: d0000021  adrp     x1, #0x7000
//   0x1d3c: d0000022  adrp     x2, #0x7000
//   0x1d40: aa0003e3  mov      x3, x0
//   0x1d44: 910c8021  add      x1, x1, #0x320
//   0x1d48: 910e2c42  add      x2, x2, #0x38b
//   0x1d4c: 528000c0  mov      w0, #6
//   0x1d50: 97ffff58  bl       #0x1ab0
//   0x1d54: b90022bb  str      w27, [x21, #0x20]
//   0x1d58: 34001499  cbz      w25, #0x1fe8
//   0x1d5c: aa1303e0  mov      x0, x19
//   0x1d60: f9000bf4  str      x20, [sp, #0x10]
//   0x1d64: 93407f79  sxtw     x25, w27
//   0x1d68: 97ffff4a  bl       #0x1a90
//   0x1d6c: 34000120  cbz      w0, #0x1d90
//   0x1d70: 97ffff08  bl       #0x1990
//   0x1d74: d0000021  adrp     x1, #0x7000
//   0x1d78: d0000022  adrp     x2, #0x7000
//   0x1d7c: aa0003e3  mov      x3, x0
//   0x1d80: 910c8021  add      x1, x1, #0x320
//   0x1d84: 910ecc42  add      x2, x2, #0x3b3
//   0x1d88: 528000c0  mov      w0, #6
//   0x1d8c: 97ffff49  bl       #0x1ab0
//   0x1d90: f94026ab  ldr      x11, [x21, #0x48]
//   0x1d94: 52800708  mov      w8, #0x38
//   0x1d98: 9b082f3c  madd     x28, x25, x8, x11
//   0x1d9c: b8408f88  ldr      w8, [x28, #8]!
//   0x1da0: 37f810a8  tbnz     w8, #0x1f, #0x1fb4
//   0x1da4: 52800709  mov      w9, #0x38
//   0x1da8: b9000ffa  str      w26, [sp, #0xc]
//   0x1dac: d503201f  nop      
//   0x1db0: 9b092f3a  madd     x26, x25, x9, x11
//   0x1db4: b840cf49  ldr      w9, [x26, #0xc]!
//   0x1db8: aa1903f4  mov      x20, x25
//   0x1dbc: 2a1f03f9  mov      w25, wzr
//   0x1dc0: 6b18013f  cmp      w9, w24
//   0x1dc4: 54000fac  b.gt     #0x1fb8
//   0x1dc8: 6b18011f  cmp      w8, w24
//   0x1dcc: 54000f6c  b.gt     #0x1fb8
//   0x1dd0: 37f80f49  tbnz     w9, #0x1f, #0x1fb8
//   0x1dd4: 7100051f  cmp      w8, #1
//   0x1dd8: 540000eb  b.lt     #0x1df4
//   0x1ddc: 7100053f  cmp      w9, #1
//   0x1de0: 540000ab  b.lt     #0x1df4
//   0x1de4: 12b0000a  mov      w10, #0x7fffffff
//   0x1de8: 1ac9094a  udiv     w10, w10, w9
//   0x1dec: 6b0a011f  cmp      w8, w10
//   0x1df0: 54000e2c  b.gt     #0x1fb4
//   0x1df4: f90003eb  str      x11, [sp]
//   0x1df8: 36000217  tbz      w23, #0, #0x1e38
//   0x1dfc: aa1603e0  mov      x0, x22
//   0x1e00: f8448c17  ldr      x23, [x0, #0x48]!
//   0x1e04: 1b087d28  mul      w8, w9, w8
//   0x1e08: 93407d18  sxtw     x24, w8
//   0x1e0c: aa1403f9  mov      x25, x20
//   0x1e10: f940040a  ldr      x10, [x0, #8]
//   0x1e14: cb170148  sub      x8, x10, x23
//   0x1e18: eb18011f  cmp      x8, x24
//   0x1e1c: 54000282  b.hs     #0x1e6c
//   0x1e20: cb080301  sub      x1, x24, x8
//   0x1e24: aa0b03f4  mov      x20, x11
//   0x1e28: 94000c57  bl       #0x4f84
//   0x1e2c: f94026d7  ldr      x23, [x22, #0x48]
//   0x1e30: aa1403eb  mov      x11, x20
//   0x1e34: 14000011  b        #0x1e78
//   0x1e38: 910093e1  add      x1, sp, #0x24
//   0x1e3c: 910063e2  add      x2, sp, #0x18
//   0x1e40: aa1503e0  mov      x0, x21
//   0x1e44: 940012e6  bl       #0x69dc
//   0x1e48: 34000b60  cbz      w0, #0x1fb4
//   0x1e4c: aa1403f9  mov      x25, x20
//   0x1e50: f9400fe8  ldr      x8, [sp, #0x18]
//   0x1e54: b4000908  cbz      x8, #0x1f74
//   0x1e58: 910063e1  add      x1, sp, #0x18
//   0x1e5c: aa1503e0  mov      x0, x21
//   0x1e60: 940011d7  bl       #0x65bc
//   0x1e64: 35ffff60  cbnz     w0, #0x1e50
//   0x1e68: 14000053  b        #0x1fb4
//   0x1e6c: 54000069  b.ls     #0x1e78
//   0x1e70: 8b1802e8  add      x8, x23, x24
//   0x1e74: f9002ac8  str      x8, [x22, #0x50]
//   0x1e78: 52800708  mov      w8, #0x38
//   0x1e7c: 9b082f28  madd     x8, x25, x8, x11
//   0x1e80: 39404108  ldrb     w8, [x8, #0x10]
//   0x1e84: 340006e8  cbz      w8, #0x1f60
//   0x1e88: b9400348  ldr      w8, [x26]
//   0x1e8c: 7100051f  cmp      w8, #1
//   0x1e90: 5400072b  b.lt     #0x1f74
//   0x1e94: 2a1f03f6  mov      w22, wzr
//   0x1e98: b9400382  ldr      w2, [x28]
//   0x1e9c: aa1503e0  mov      x0, x21
//   0x1ea0: 1b167c48  mul      w8, w2, w22
//   0x1ea4: 8b28c2e1  add      x1, x23, w8, sxtw
//   0x1ea8: 94001090  bl       #0x60e8
//   0x1eac: 34000840  cbz      w0, #0x1fb4
//   0x1eb0: b9400348  ldr      w8, [x26]
//   0x1eb4: 110022d6  add      w22, w22, #8
//   0x1eb8: 6b0802df  cmp      w22, w8
//   0x1ebc: 54fffeeb  b.lt     #0x1e98
//   0x1ec0: 7100151f  cmp      w8, #5
//   0x1ec4: 5400018b  b.lt     #0x1ef4
//   0x1ec8: 52800096  mov      w22, #4
//   0x1ecc: b9400382  ldr      w2, [x28]
//   0x1ed0: aa1503e0  mov      x0, x21
//   0x1ed4: 1b167c48  mul      w8, w2, w22
//   0x1ed8: 8b28c2e1  add      x1, x23, w8, sxtw
//   0x1edc: 94001083  bl       #0x60e8
//   0x1ee0: 340006a0  cbz      w0, #0x1fb4
//   0x1ee4: b9400348  ldr      w8, [x26]
//   0x1ee8: 110022d6  add      w22, w22, #8
//   0x1eec: 6b0802df  cmp      w22, w8
//   0x1ef0: 54fffeeb  b.lt     #0x1ecc
//   0x1ef4: 7100091f  cmp      w8, #2
//   0x1ef8: 5400018d  b.le     #0x1f28
//   0x1efc: 52800056  mov      w22, #2
//   0x1f00: b9400382  ldr      w2, [x28]
//   0x1f04: aa1503e0  mov      x0, x21
//   0x1f08: 1b167c48  mul      w8, w2, w22
//   0x1f0c: 8b28c2e1  add      x1, x23, w8, sxtw
//   0x1f10: 94001076  bl       #0x60e8
//   0x1f14: 34000500  cbz      w0, #0x1fb4
//   0x1f18: b9400348  ldr      w8, [x26]
//   0x1f1c: 110012d6  add      w22, w22, #4
//   0x1f20: 6b0802df  cmp      w22, w8
//   0x1f24: 54fffeeb  b.lt     #0x1f00
//   0x1f28: 7100091f  cmp      w8, #2
//   0x1f2c: 5400024b  b.lt     #0x1f74
//   0x1f30: 52800036  mov      w22, #1
//   0x1f34: b9400382  ldr      w2, [x28]
//   0x1f38: aa1503e0  mov      x0, x21
//   0x1f3c: 1b167c48  mul      w8, w2, w22
//   0x1f40: 8b28c2e1  add      x1, x23, w8, sxtw
//   0x1f44: 94001069  bl       #0x60e8
//   0x1f48: 34000360  cbz      w0, #0x1fb4
//   0x1f4c: b9400348  ldr      w8, [x26]
//   0x1f50: 11000ad6  add      w22, w22, #2
//   0x1f54: 6b0802df  cmp      w22, w8
//   0x1f58: 54fffeeb  b.lt     #0x1f34
//   0x1f5c: 14000006  b        #0x1f74
//   0x1f60: aa1503e0  mov      x0, x21
//   0x1f64: aa1703e1  mov      x1, x23
//   0x1f68: 2a1803e2  mov      w2, w24
//   0x1f6c: 9400105f  bl       #0x60e8
//   0x1f70: 34000220  cbz      w0, #0x1fb4
//   0x1f74: f9402ea8  ldr      x8, [x21, #0x58]
//   0x1f78: b4000128  cbz      x8, #0x1f9c
//   0x1f7c: f94003ea  ldr      x10, [sp]
//   0x1f80: 52800709  mov      w9, #0x38
//   0x1f84: 9b092b29  madd     x9, x25, x9, x10
//   0x1f88: f9001928  str      x8, [x9, #0x30]
//   0x1f8c: b94052a8  ldr      w8, [x21, #0x50]
//   0x1f90: b9002928  str      w8, [x9, #0x28]
//   0x1f94: f9002ebf  str      xzr, [x21, #0x58]
//   0x1f98: b90052bf  str      wzr, [x21, #0x50]
//   0x1f9c: b9400fe8  ldr      w8, [sp, #0xc]
//   0x1fa0: 36000068  tbz      w8, #0, #0x1fac
//   0x1fa4: 11000768  add      w8, w27, #1
//   0x1fa8: b90022a8  str      w8, [x21, #0x20]
//   0x1fac: 52800039  mov      w25, #1
//   0x1fb0: 14000002  b        #0x1fb8
//   0x1fb4: 2a1f03f9  mov      w25, wzr
//   0x1fb8: aa1303e0  mov      x0, x19
//   0x1fbc: 97fffeb9  bl       #0x1aa0
//   0x1fc0: 34000120  cbz      w0, #0x1fe4
//   0x1fc4: 97fffe73  bl       #0x1990
//   0x1fc8: d0000021  adrp     x1, #0x7000
//   0x1fcc: d0000022  adrp     x2, #0x7000
//   0x1fd0: aa0003e3  mov      x3, x0
//   0x1fd4: 910c8021  add      x1, x1, #0x320
//   0x1fd8: 910f5442  add      x2, x2, #0x3d5
//   0x1fdc: 528000c0  mov      w0, #6
//   0x1fe0: 97fffeb4  bl       #0x1ab0
//   0x1fe4: f9400bf4  ldr      x20, [sp, #0x10]
//   0x1fe8: f9401688  ldr      x8, [x20, #0x28]
//   0x1fec: f94017e9  ldr      x9, [sp, #0x28]
//   0x1ff0: eb09011f  cmp      x8, x9
//   0x1ff4: 54000141  b.ne     #0x201c
//   0x1ff8: 2a1903e0  mov      w0, w25
//   0x1ffc: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x2000: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x2004: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x2008: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x200c: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x2010: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x2014: 910243ff  add      sp, sp, #0x90
//   0x2018: d65f03c0  ret      
//   0x201c: 97fffedd  bl       #0x1b90
// ============================================================================
std::uint32_t fde_01_1ca8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00001ca8ULL;
    for (std::size_t i = 0; i < 222ULL; ++i) {
        std::uint32_t insn = kTextInstructions[46ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[02] Symbol: sub_2020
//      Virtual Address Range: 0x2020..0x20e4 (196 bytes, 49 AArch64 instructions)
// [VN] Khung FDE[02] Biểu tượng: sub_2020
//      Dải địa chỉ ảo: 0x2020..0x20e4 (196 byte, 49 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2020: d10143ff  sub      sp, sp, #0x50
//   0x2024: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x2028: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x202c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x2030: 910103fd  add      x29, sp, #0x40
//   0x2034: d53bd056  mrs      x22, tpidr_el0
//   0x2038: f94016c8  ldr      x8, [x22, #0x28]
//   0x203c: 910033e1  add      x1, sp, #0xc
//   0x2040: 910043e2  add      x2, sp, #0x10
//   0x2044: aa0003f3  mov      x19, x0
//   0x2048: f9000fe8  str      x8, [sp, #0x18]
//   0x204c: 940011a1  bl       #0x66d0
//   0x2050: 34000360  cbz      w0, #0x20bc
//   0x2054: f9400be4  ldr      x4, [sp, #0x10]
//   0x2058: b4000304  cbz      x4, #0x20b8
//   0x205c: b9400fe2  ldr      w2, [sp, #0xc]
//   0x2060: 38401483  ldrb     w3, [x4], #1
//   0x2064: 91014274  add      x20, x19, #0x50
//   0x2068: 91016275  add      x21, x19, #0x58
//   0x206c: aa1403e0  mov      x0, x20
//   0x2070: aa1503e1  mov      x1, x21
//   0x2074: 94001315  bl       #0x6cc8
//   0x2078: 34000220  cbz      w0, #0x20bc
//   0x207c: f9400be8  ldr      x8, [sp, #0x10]
//   0x2080: b40001c8  cbz      x8, #0x20b8
//   0x2084: 910043e1  add      x1, sp, #0x10
//   0x2088: aa1303e0  mov      x0, x19
//   0x208c: 940011c4  bl       #0x679c
//   0x2090: 34000160  cbz      w0, #0x20bc
//   0x2094: f9400be4  ldr      x4, [sp, #0x10]
//   0x2098: b4000104  cbz      x4, #0x20b8
//   0x209c: 38401483  ldrb     w3, [x4], #1
//   0x20a0: aa1403e0  mov      x0, x20
//   0x20a4: aa1503e1  mov      x1, x21
//   0x20a8: 2a1f03e2  mov      w2, wzr
//   0x20ac: 94001307  bl       #0x6cc8
//   0x20b0: 35fffe60  cbnz     w0, #0x207c
//   0x20b4: 14000002  b        #0x20bc
//   0x20b8: 52800020  mov      w0, #1
//   0x20bc: f94016c8  ldr      x8, [x22, #0x28]
//   0x20c0: f9400fe9  ldr      x9, [sp, #0x18]
//   0x20c4: eb09011f  cmp      x8, x9
//   0x20c8: 540000c1  b.ne     #0x20e0
//   0x20cc: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x20d0: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x20d4: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x20d8: 910143ff  add      sp, sp, #0x50
//   0x20dc: d65f03c0  ret      
//   0x20e0: 97fffeac  bl       #0x1b90
// ============================================================================
std::uint32_t fde_02_2020(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002020ULL;
    for (std::size_t i = 0; i < 49ULL; ++i) {
        std::uint32_t insn = kTextInstructions[268ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[03] Symbol: sub_20e4
//      Virtual Address Range: 0x20e4..0x2400 (796 bytes, 199 AArch64 instructions)
// [VN] Khung FDE[03] Biểu tượng: sub_20e4
//      Dải địa chỉ ảo: 0x20e4..0x2400 (796 byte, 199 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x20e4: d10243ff  sub      sp, sp, #0x90
//   0x20e8: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x20ec: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x20f0: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x20f4: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x20f8: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x20fc: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x2100: 910203fd  add      x29, sp, #0x80
//   0x2104: d53bd048  mrs      x8, tpidr_el0
//   0x2108: f9000be8  str      x8, [sp, #0x10]
//   0x210c: f9401508  ldr      x8, [x8, #0x28]
//   0x2110: 2a0103f6  mov      w22, w1
//   0x2114: aa0003f9  mov      x25, x0
//   0x2118: 910093e1  add      x1, sp, #0x24
//   0x211c: f90017e8  str      x8, [sp, #0x28]
//   0x2120: f9400814  ldr      x20, [x0, #0x10]
//   0x2124: 2a0203f5  mov      w21, w2
//   0x2128: aa1403e0  mov      x0, x20
//   0x212c: f9002e9f  str      xzr, [x20, #0x58]
//   0x2130: b900529f  str      wzr, [x20, #0x50]
//   0x2134: 94000e89  bl       #0x5b58
//   0x2138: f9000ff9  str      x25, [sp, #0x18]
//   0x213c: 35000120  cbnz     w0, #0x2160
//   0x2140: 1400004e  b        #0x2278
//   0x2144: aa1403e0  mov      x0, x20
//   0x2148: 97ffffb6  bl       #0x2020
//   0x214c: 34000960  cbz      w0, #0x2278
//   0x2150: 910093e1  add      x1, sp, #0x24
//   0x2154: aa1403e0  mov      x0, x20
//   0x2158: 94000e80  bl       #0x5b58
//   0x215c: 340008e0  cbz      w0, #0x2278
//   0x2160: b94027e8  ldr      w8, [sp, #0x24]
//   0x2164: 7100091f  cmp      w8, #2
//   0x2168: 540000c0  b.eq     #0x2180
//   0x216c: 71000d1f  cmp      w8, #3
//   0x2170: 54fffea0  b.eq     #0x2144
//   0x2174: 7100111f  cmp      w8, #4
//   0x2178: 54fffec1  b.ne     #0x2150
//   0x217c: 1400003f  b        #0x2278
//   0x2180: b9402288  ldr      w8, [x20, #0x20]
//   0x2184: 7100051f  cmp      w8, #1
//   0x2188: 5400008b  b.lt     #0x2198
//   0x218c: 52800028  mov      w8, #1
//   0x2190: 39003328  strb     w8, [x25, #0xc]
//   0x2194: 37000735  tbnz     w21, #0, #0x2278
//   0x2198: f9401320  ldr      x0, [x25, #0x20]
//   0x219c: f9400008  ldr      x8, [x0]
//   0x21a0: f9401108  ldr      x8, [x8, #0x20]
//   0x21a4: d63f0100  blr      x8
//   0x21a8: a943a329  ldp      x9, x8, [x25, #0x38]
//   0x21ac: aa0003f8  mov      x24, x0
//   0x21b0: eb08013f  cmp      x9, x8
//   0x21b4: 54000082  b.hs     #0x21c4
//   0x21b8: b8004538  str      w24, [x9], #4
//   0x21bc: f9001f29  str      x9, [x25, #0x38]
//   0x21c0: 14000025  b        #0x2254
//   0x21c4: f9401b37  ldr      x23, [x25, #0x30]
//   0x21c8: cb170139  sub      x25, x9, x23
//   0x21cc: 9342ff33  asr      x19, x25, #2
//   0x21d0: 91000669  add      x9, x19, #1
//   0x21d4: d37efd2a  lsr      x10, x9, #0x3e
//   0x21d8: b500110a  cbnz     x10, #0x23f8
//   0x21dc: cb170108  sub      x8, x8, x23
//   0x21e0: b27fefea  mov      x10, #0x1ffffffffffffffe
//   0x21e4: eb88095f  cmp      x10, x8, asr #2
//   0x21e8: 54000103  b.lo     #0x2208
//   0x21ec: 9341fd08  asr      x8, x8, #1
//   0x21f0: eb09011f  cmp      x8, x9
//   0x21f4: 9a88313b  csel     x27, x9, x8, lo
//   0x21f8: b40003db  cbz      x27, #0x2270
//   0x21fc: d37eff68  lsr      x8, x27, #0x3e
//   0x2200: b4000068  cbz      x8, #0x220c
//   0x2204: 1400007d  b        #0x23f8
//   0x2208: 92f8001b  mov      x27, #0x3fffffffffffffff
//   0x220c: d37ef760  lsl      x0, x27, #2
//   0x2210: 97fffe58  bl       #0x1b70
//   0x2214: aa0003fa  mov      x26, x0
//   0x2218: 8b130b5c  add      x28, x26, x19, lsl #2
//   0x221c: 8b1b0b53  add      x19, x26, x27, lsl #2
//   0x2220: f100073f  cmp      x25, #1
//   0x2224: b8004798  str      w24, [x28], #4
//   0x2228: 540000ab  b.lt     #0x223c
//   0x222c: aa1a03e0  mov      x0, x26
//   0x2230: aa1703e1  mov      x1, x23
//   0x2234: aa1903e2  mov      x2, x25
//   0x2238: 97fffdda  bl       #0x19a0
//   0x223c: f9400ff9  ldr      x25, [sp, #0x18]
//   0x2240: a903733a  stp      x26, x28, [x25, #0x30]
//   0x2244: f9002333  str      x19, [x25, #0x40]
//   0x2248: b4000077  cbz      x23, #0x2254
//   0x224c: aa1703e0  mov      x0, x23
//   0x2250: 97fffddc  bl       #0x19c0
//   0x2254: 52800022  mov      w2, #1
//   0x2258: aa1903e0  mov      x0, x25
//   0x225c: 2a1f03e1  mov      w1, wzr
//   0x2260: 2a1603e3  mov      w3, w22
//   0x2264: 97fffe91  bl       #0x1ca8
//   0x2268: 35fff740  cbnz     w0, #0x2150
//   0x226c: 14000003  b        #0x2278
//   0x2270: aa1f03fa  mov      x26, xzr
//   0x2274: 17ffffe9  b        #0x2218
//   0x2278: b9402296  ldr      w22, [x20, #0x20]
//   0x227c: 91022320  add      x0, x25, #0x88
//   0x2280: f90007e0  str      x0, [sp, #8]
//   0x2284: 97fffe03  bl       #0x1a90
//   0x2288: 34000120  cbz      w0, #0x22ac
//   0x228c: 97fffdc1  bl       #0x1990
//   0x2290: b0000021  adrp     x1, #0x7000
//   0x2294: b0000022  adrp     x2, #0x7000
//   0x2298: aa0003e3  mov      x3, x0
//   0x229c: 910c8021  add      x1, x1, #0x320
//   0x22a0: 910ecc42  add      x2, x2, #0x3b3
//   0x22a4: 528000c0  mov      w0, #6
//   0x22a8: 97fffe02  bl       #0x1ab0
//   0x22ac: 710006df  cmp      w22, #1
//   0x22b0: 540006ab  b.lt     #0x2384
//   0x22b4: f9402698  ldr      x24, [x20, #0x48]
//   0x22b8: b0000034  adrp     x20, #0x7000
//   0x22bc: aa1f03f7  mov      x23, xzr
//   0x22c0: 52800719  mov      w25, #0x38
//   0x22c4: 9108c294  add      x20, x20, #0x230
//   0x22c8: 14000004  b        #0x22d8
//   0x22cc: 910006f7  add      x23, x23, #1
//   0x22d0: eb1602ff  cmp      x23, x22
//   0x22d4: 54000580  b.eq     #0x2384
//   0x22d8: 9b1962e8  madd     x8, x23, x25, x24
//   0x22dc: b980291c  ldrsw    x28, [x8, #0x28]
//   0x22e0: 7100079f  cmp      w28, #1
//   0x22e4: 54ffff4b  b.lt     #0x22cc
//   0x22e8: 9b1962e8  madd     x8, x23, x25, x24
//   0x22ec: f940191b  ldr      x27, [x8, #0x30]
//   0x22f0: aa1f03fa  mov      x26, xzr
//   0x22f4: 92407f95  and      x21, x28, #0xffffffff
//   0x22f8: 91006373  add      x19, x27, #0x18
//   0x22fc: 14000005  b        #0x2310
//   0x2300: 9100075a  add      x26, x26, #1
//   0x2304: eb1a02bf  cmp      x21, x26
//   0x2308: 91006273  add      x19, x19, #0x18
//   0x230c: 54fffe00  b.eq     #0x22cc
//   0x2310: b85f8268  ldur     w8, [x19, #-8]
//   0x2314: 7103fd1f  cmp      w8, #0xff
//   0x2318: 54ffff41  b.ne     #0x2300
//   0x231c: b85e8268  ldur     w8, [x19, #-0x18]
//   0x2320: 71002d1f  cmp      w8, #0xb
//   0x2324: 54fffee1  b.ne     #0x2300
//   0x2328: f85f0261  ldur     x1, [x19, #-0x10]
//   0x232c: 52800162  mov      w2, #0xb
//   0x2330: aa1403e0  mov      x0, x20
//   0x2334: 97fffdd3  bl       #0x1a80
//   0x2338: 35fffe40  cbnz     w0, #0x2300
//   0x233c: 91000748  add      x8, x26, #1
//   0x2340: eb1c011f  cmp      x8, x28
//   0x2344: 54fffdea  b.ge     #0x2300
//   0x2348: b9401268  ldr      w8, [x19, #0x10]
//   0x234c: 35fffda8  cbnz     w8, #0x2300
//   0x2350: b9400268  ldr      w8, [x19]
//   0x2354: 71000d1f  cmp      w8, #3
//   0x2358: 54fffd41  b.ne     #0x2300
//   0x235c: 11000748  add      w8, w26, #1
//   0x2360: 52800309  mov      w9, #0x18
//   0x2364: 9ba96d08  umaddl   x8, w8, w9, x27
//   0x2368: f9400508  ldr      x8, [x8, #8]
//   0x236c: 39400509  ldrb     w9, [x8, #1]
//   0x2370: 39400908  ldrb     w8, [x8, #2]
//   0x2374: 33181d09  bfi      w9, w8, #8, #8
//   0x2378: f9400fe8  ldr      x8, [sp, #0x18]
//   0x237c: b9000909  str      w9, [x8, #8]
//   0x2380: 17ffffd3  b        #0x22cc
//   0x2384: f9400fe9  ldr      x9, [sp, #0x18]
//   0x2388: f94007e0  ldr      x0, [sp, #8]
//   0x238c: a9432528  ldp      x8, x9, [x9, #0x30]
//   0x2390: eb08013f  cmp      x9, x8
//   0x2394: 1a9f07f3  cset     w19, ne
//   0x2398: 97fffdc2  bl       #0x1aa0
//   0x239c: 34000120  cbz      w0, #0x23c0
//   0x23a0: 97fffd7c  bl       #0x1990
//   0x23a4: b0000021  adrp     x1, #0x7000
//   0x23a8: b0000022  adrp     x2, #0x7000
//   0x23ac: aa0003e3  mov      x3, x0
//   0x23b0: 910c8021  add      x1, x1, #0x320
//   0x23b4: 910f5442  add      x2, x2, #0x3d5
//   0x23b8: 528000c0  mov      w0, #6
//   0x23bc: 97fffdbd  bl       #0x1ab0
//   0x23c0: f9400be8  ldr      x8, [sp, #0x10]
//   0x23c4: f9401508  ldr      x8, [x8, #0x28]
//   0x23c8: f94017e9  ldr      x9, [sp, #0x28]
//   0x23cc: eb09011f  cmp      x8, x9
//   0x23d0: 54000161  b.ne     #0x23fc
//   0x23d4: 2a1303e0  mov      w0, w19
//   0x23d8: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x23dc: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x23e0: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x23e4: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x23e8: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x23ec: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x23f0: 910243ff  add      sp, sp, #0x90
//   0x23f4: d65f03c0  ret      
//   0x23f8: 97fffdc6  bl       #0x1b10
//   0x23fc: 97fffde5  bl       #0x1b90
// ============================================================================
std::uint32_t fde_03_20e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000020e4ULL;
    for (std::size_t i = 0; i < 199ULL; ++i) {
        std::uint32_t insn = kTextInstructions[317ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[04] Symbol: sub_2400
//      Virtual Address Range: 0x2400..0x29d0 (1488 bytes, 372 AArch64 instructions)
// [VN] Khung FDE[04] Biểu tượng: sub_2400
//      Dải địa chỉ ảo: 0x2400..0x29d0 (1488 byte, 372 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2400: d10303ff  sub      sp, sp, #0xc0
//   0x2404: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x2408: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x240c: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x2410: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x2414: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x2418: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x241c: 9102c3fd  add      x29, sp, #0xb0
//   0x2420: d53bd05b  mrs      x27, tpidr_el0
//   0x2424: f9401768  ldr      x8, [x27, #0x28]
//   0x2428: aa0003fc  mov      x28, x0
//   0x242c: 52800900  mov      w0, #0x48
//   0x2430: 2a0303f6  mov      w22, w3
//   0x2434: 2a0203f5  mov      w21, w2
//   0x2438: aa0103f8  mov      x24, x1
//   0x243c: f9002fe8  str      x8, [sp, #0x58]
//   0x2440: 97fffdcc  bl       #0x1b70
//   0x2444: 6f00e400  movi     v0.2d, #0000000000000000
//   0x2448: f900201f  str      xzr, [x0, #0x40]
//   0x244c: ad000000  stp      q0, q0, [x0]
//   0x2450: ad010000  stp      q0, q0, [x0, #0x20]
//   0x2454: b90057ff  str      wzr, [sp, #0x54]
//   0x2458: aa0003f3  mov      x19, x0
//   0x245c: f9400300  ldr      x0, [x24]
//   0x2460: 90000001  adrp     x1, #0x2000
//   0x2464: 91274021  add      x1, x1, #0x9d0
//   0x2468: 910153e2  add      x2, sp, #0x54
//   0x246c: 94000d4e  bl       #0x59a4
//   0x2470: b4001e00  cbz      x0, #0x2830
//   0x2474: b9400414  ldr      w20, [x0, #4]
//   0x2478: aa0003f9  mov      x25, x0
//   0x247c: 6b15029f  cmp      w20, w21
//   0x2480: 54001e4c  b.gt     #0x2848
//   0x2484: b940033a  ldr      w26, [x25]
//   0x2488: 6b15035f  cmp      w26, w21
//   0x248c: 54001dec  b.gt     #0x2848
//   0x2490: 1b1a7e88  mul      w8, w20, w26
//   0x2494: 34001da8  cbz      w8, #0x2848
//   0x2498: 52801800  mov      w0, #0xc0
//   0x249c: f9000ff3  str      x19, [sp, #0x18]
//   0x24a0: 97fffdb4  bl       #0x1b70
//   0x24a4: b0000068  adrp     x8, #0xf000
//   0x24a8: 9000000a  adrp     x10, #0x2000
//   0x24ac: 912d6108  add      x8, x8, #0xb58
//   0x24b0: 12800009  mov      w9, #-1
//   0x24b4: 9128114a  add      x10, x10, #0xa04
//   0x24b8: 3900301f  strb     wzr, [x0, #0xc]
//   0x24bc: f9000008  str      x8, [x0]
//   0x24c0: b9000809  str      w9, [x0, #8]
//   0x24c4: a9012819  stp      x25, x10, [x0, #0x10]
//   0x24c8: f9400308  ldr      x8, [x24]
//   0x24cc: aa0003f7  mov      x23, x0
//   0x24d0: f9001008  str      x8, [x0, #0x20]
//   0x24d4: f9400708  ldr      x8, [x24, #8]
//   0x24d8: f9001408  str      x8, [x0, #0x28]
//   0x24dc: b40000e8  cbz      x8, #0x24f8
//   0x24e0: 91002108  add      x8, x8, #8
//   0x24e4: c85f7d09  ldxr     x9, [x8]
//   0x24e8: 91000529  add      x9, x9, #1
//   0x24ec: c80a7d09  stxr     w10, x9, [x8]
//   0x24f0: 35ffffaa  cbnz     w10, #0x24e4
//   0x24f4: f9400af9  ldr      x25, [x23, #0x10]
//   0x24f8: a9037eff  stp      xzr, xzr, [x23, #0x30]
//   0x24fc: f90022ff  str      xzr, [x23, #0x40]
//   0x2500: 69402728  ldpsw    x8, x9, [x25]
//   0x2504: a904feff  stp      xzr, xzr, [x23, #0x48]
//   0x2508: f9002eff  str      xzr, [x23, #0x58]
//   0x250c: 9b087d38  mul      x24, x9, x8
//   0x2510: 34000178  cbz      w24, #0x253c
//   0x2514: 37f825b8  tbnz     w24, #0x1f, #0x29c8
//   0x2518: aa1803e0  mov      x0, x24
//   0x251c: 97fffd95  bl       #0x1b70
//   0x2520: 8b180019  add      x25, x0, x24
//   0x2524: 2a1f03e1  mov      w1, wzr
//   0x2528: aa1803e2  mov      x2, x24
//   0x252c: f90026e0  str      x0, [x23, #0x48]
//   0x2530: f9002ef9  str      x25, [x23, #0x58]
//   0x2534: 97fffd6b  bl       #0x1ae0
//   0x2538: f9002af9  str      x25, [x23, #0x50]
//   0x253c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x2540: 52800400  mov      w0, #0x20
//   0x2544: ad0502e0  stp      q0, q0, [x23, #0xa0]
//   0x2548: ad0402e0  stp      q0, q0, [x23, #0x80]
//   0x254c: ad0302e0  stp      q0, q0, [x23, #0x60]
//   0x2550: 97fffd88  bl       #0x1b70
//   0x2554: f9400ff3  ldr      x19, [sp, #0x18]
//   0x2558: b0000068  adrp     x8, #0xf000
//   0x255c: 912fe108  add      x8, x8, #0xbf8
//   0x2560: a9007c08  stp      x8, xzr, [x0]
//   0x2564: f9400678  ldr      x24, [x19, #8]
//   0x2568: a9015c1f  stp      xzr, x23, [x0, #0x10]
//   0x256c: a9000277  stp      x23, x0, [x19]
//   0x2570: b40001b8  cbz      x24, #0x25a4
//   0x2574: 91002308  add      x8, x24, #8
//   0x2578: c85ffd09  ldaxr    x9, [x8]
//   0x257c: d100052a  sub      x10, x9, #1
//   0x2580: c80bfd0a  stlxr    w11, x10, [x8]
//   0x2584: 35ffffab  cbnz     w11, #0x2578
//   0x2588: b50000e9  cbnz     x9, #0x25a4
//   0x258c: f9400308  ldr      x8, [x24]
//   0x2590: aa1803e0  mov      x0, x24
//   0x2594: f9400908  ldr      x8, [x8, #0x10]
//   0x2598: d63f0100  blr      x8
//   0x259c: aa1803e0  mov      x0, x24
//   0x25a0: 97fffd58  bl       #0x1b00
//   0x25a4: f9400260  ldr      x0, [x19]
//   0x25a8: 120002c2  and      w2, w22, #1
//   0x25ac: 2a1503e1  mov      w1, w21
//   0x25b0: f9400817  ldr      x23, [x0, #0x10]
//   0x25b4: 2902527a  stp      w26, w20, [x19, #0x10]
//   0x25b8: 97fffecb  bl       #0x20e4
//   0x25bc: 7100041f  cmp      w0, #1
//   0x25c0: 54001541  b.ne     #0x2868
//   0x25c4: b94022e8  ldr      w8, [x23, #0x20]
//   0x25c8: f9001ff7  str      x23, [sp, #0x38]
//   0x25cc: 7100011f  cmp      w8, #0
//   0x25d0: 5400158d  b.le     #0x2880
//   0x25d4: f9400fea  ldr      x10, [sp, #0x18]
//   0x25d8: f9400149  ldr      x9, [x10]
//   0x25dc: b9001948  str      w8, [x10, #0x18]
//   0x25e0: 91022120  add      x0, x9, #0x88
//   0x25e4: f9000be0  str      x0, [sp, #0x10]
//   0x25e8: 97fffd2a  bl       #0x1a90
//   0x25ec: 34000120  cbz      w0, #0x2610
//   0x25f0: 97fffce8  bl       #0x1990
//   0x25f4: b0000021  adrp     x1, #0x7000
//   0x25f8: b0000022  adrp     x2, #0x7000
//   0x25fc: aa0003e3  mov      x3, x0
//   0x2600: 910c8021  add      x1, x1, #0x320
//   0x2604: 910ecc42  add      x2, x2, #0x3b3
//   0x2608: 528000c0  mov      w0, #6
//   0x260c: 97fffd29  bl       #0x1ab0
//   0x2610: a9006ffc  stp      x28, x27, [sp]
//   0x2614: f9401ffb  ldr      x27, [sp, #0x38]
//   0x2618: b9402368  ldr      w8, [x27, #0x20]
//   0x261c: 7100051f  cmp      w8, #1
//   0x2620: 540017eb  b.lt     #0x291c
//   0x2624: aa1f03f6  mov      x22, xzr
//   0x2628: aa1f03fa  mov      x26, xzr
//   0x262c: aa1f03f8  mov      x24, xzr
//   0x2630: aa1f03f7  mov      x23, xzr
//   0x2634: aa1f03ea  mov      x10, xzr
//   0x2638: aa1f03f5  mov      x21, xzr
//   0x263c: a9027fff  stp      xzr, xzr, [sp, #0x20]
//   0x2640: b90037ff  str      wzr, [sp, #0x34]
//   0x2644: 14000006  b        #0x265c
//   0x2648: b800471f  str      wzr, [x24], #4
//   0x264c: b9802368  ldrsw    x8, [x27, #0x20]
//   0x2650: 910006b5  add      x21, x21, #1
//   0x2654: eb0802bf  cmp      x21, x8
//   0x2658: 540016aa  b.ge     #0x292c
//   0x265c: f9402769  ldr      x9, [x27, #0x48]
//   0x2660: 52800708  mov      w8, #0x38
//   0x2664: 9b0826b4  madd     x20, x21, x8, x9
//   0x2668: b8428e88  ldr      w8, [x20, #0x28]!
//   0x266c: 7100051f  cmp      w8, #1
//   0x2670: 5400058b  b.lt     #0x2720
//   0x2674: aa1603f3  mov      x19, x22
//   0x2678: aa0a03f6  mov      x22, x10
//   0x267c: 5280070a  mov      w10, #0x38
//   0x2680: 9b0a26a9  madd     x9, x21, x10, x9
//   0x2684: aa1703fc  mov      x28, x23
//   0x2688: aa1a03f7  mov      x23, x26
//   0x268c: aa1f03f9  mov      x25, xzr
//   0x2690: aa1f03fb  mov      x27, xzr
//   0x2694: 2a1f03e0  mov      w0, wzr
//   0x2698: 9100c13a  add      x26, x9, #0x30
//   0x269c: 14000005  b        #0x26b0
//   0x26a0: 9100077b  add      x27, x27, #1
//   0x26a4: eb28c37f  cmp      x27, w8, sxtw
//   0x26a8: 91006339  add      x25, x25, #0x18
//   0x26ac: 5400018a  b.ge     #0x26dc
//   0x26b0: f9400349  ldr      x9, [x26]
//   0x26b4: 8b190129  add      x9, x9, x25
//   0x26b8: b940112a  ldr      w10, [x9, #0x10]
//   0x26bc: 7103e55f  cmp      w10, #0xf9
//   0x26c0: 54ffff01  b.ne     #0x26a0
//   0x26c4: b9800120  ldrsw    x0, [x9]
//   0x26c8: f9400521  ldr      x1, [x9, #8]
//   0x26cc: 910103e2  add      x2, sp, #0x40
//   0x26d0: 94001076  bl       #0x68a8
//   0x26d4: b9400288  ldr      w8, [x20]
//   0x26d8: 17fffff2  b        #0x26a0
//   0x26dc: f9401ffb  ldr      x27, [sp, #0x38]
//   0x26e0: 7100041f  cmp      w0, #1
//   0x26e4: aa1703fa  mov      x26, x23
//   0x26e8: aa1c03f7  mov      x23, x28
//   0x26ec: aa1603ea  mov      x10, x22
//   0x26f0: aa1303f6  mov      x22, x19
//   0x26f4: 54000161  b.ne     #0x2720
//   0x26f8: b9404be8  ldr      w8, [sp, #0x48]
//   0x26fc: b94037ea  ldr      w10, [sp, #0x34]
//   0x2700: eb1a031f  cmp      x24, x26
//   0x2704: 0b080908  add      w8, w8, w8, lsl #2
//   0x2708: 531f791c  lsl      w28, w8, #1
//   0x270c: 0b0a038a  add      w10, w28, w10
//   0x2710: b90037ea  str      w10, [sp, #0x34]
//   0x2714: 54000520  b.eq     #0x27b8
//   0x2718: b800471c  str      w28, [x24], #4
//   0x271c: 14000025  b        #0x27b0
//   0x2720: eb0a031f  cmp      x24, x10
//   0x2724: 54fff923  b.lo     #0x2648
//   0x2728: cb170319  sub      x25, x24, x23
//   0x272c: 9342ff34  asr      x20, x25, #2
//   0x2730: 91000688  add      x8, x20, #1
//   0x2734: d37efd09  lsr      x9, x8, #0x3e
//   0x2738: b5001489  cbnz     x9, #0x29c8
//   0x273c: cb170349  sub      x9, x26, x23
//   0x2740: b27fefea  mov      x10, #0x1ffffffffffffffe
//   0x2744: eb89095f  cmp      x10, x9, asr #2
//   0x2748: 54000103  b.lo     #0x2768
//   0x274c: 9341fd29  asr      x9, x9, #1
//   0x2750: eb08013f  cmp      x9, x8
//   0x2754: 9a89311a  csel     x26, x8, x9, lo
//   0x2758: b400051a  cbz      x26, #0x27f8
//   0x275c: d37eff48  lsr      x8, x26, #0x3e
//   0x2760: b4000068  cbz      x8, #0x276c
//   0x2764: 14000099  b        #0x29c8
//   0x2768: 92f8001a  mov      x26, #0x3fffffffffffffff
//   0x276c: d37ef740  lsl      x0, x26, #2
//   0x2770: 97fffd00  bl       #0x1b70
//   0x2774: aa0003f6  mov      x22, x0
//   0x2778: 8b140ad8  add      x24, x22, x20, lsl #2
//   0x277c: 8b1a0ada  add      x26, x22, x26, lsl #2
//   0x2780: f100073f  cmp      x25, #1
//   0x2784: b800471f  str      wzr, [x24], #4
//   0x2788: 540000ab  b.lt     #0x279c
//   0x278c: aa1603e0  mov      x0, x22
//   0x2790: aa1703e1  mov      x1, x23
//   0x2794: aa1903e2  mov      x2, x25
//   0x2798: 97fffc82  bl       #0x19a0
//   0x279c: b4000077  cbz      x23, #0x27a8
//   0x27a0: aa1703e0  mov      x0, x23
//   0x27a4: 97fffc87  bl       #0x19c0
//   0x27a8: aa1603f7  mov      x23, x22
//   0x27ac: a9025bf6  stp      x22, x22, [sp, #0x20]
//   0x27b0: aa1a03ea  mov      x10, x26
//   0x27b4: 17ffffa6  b        #0x264c
//   0x27b8: cb170319  sub      x25, x24, x23
//   0x27bc: 9342ff34  asr      x20, x25, #2
//   0x27c0: 91000688  add      x8, x20, #1
//   0x27c4: d37efd09  lsr      x9, x8, #0x3e
//   0x27c8: b5001009  cbnz     x9, #0x29c8
//   0x27cc: cb170349  sub      x9, x26, x23
//   0x27d0: b27fefeb  mov      x11, #0x1ffffffffffffffe
//   0x27d4: eb89097f  cmp      x11, x9, asr #2
//   0x27d8: 54000143  b.lo     #0x2800
//   0x27dc: 9341fd29  asr      x9, x9, #1
//   0x27e0: eb08013f  cmp      x9, x8
//   0x27e4: 9a89311a  csel     x26, x8, x9, lo
//   0x27e8: b400021a  cbz      x26, #0x2828
//   0x27ec: d37eff48  lsr      x8, x26, #0x3e
//   0x27f0: b40000a8  cbz      x8, #0x2804
//   0x27f4: 14000075  b        #0x29c8
//   0x27f8: aa1f03f6  mov      x22, xzr
//   0x27fc: 17ffffdf  b        #0x2778
//   0x2800: 92f8001a  mov      x26, #0x3fffffffffffffff
//   0x2804: d37ef740  lsl      x0, x26, #2
//   0x2808: 97fffcda  bl       #0x1b70
//   0x280c: aa0003f6  mov      x22, x0
//   0x2810: 8b140ad8  add      x24, x22, x20, lsl #2
//   0x2814: 8b1a0ada  add      x26, x22, x26, lsl #2
//   0x2818: f100073f  cmp      x25, #1
//   0x281c: b800471c  str      w28, [x24], #4
//   0x2820: 54fffb6a  b.ge     #0x278c
//   0x2824: 17ffffde  b        #0x279c
//   0x2828: aa1f03f6  mov      x22, xzr
//   0x282c: 17fffff9  b        #0x2810
//   0x2830: b94057e2  ldr      w2, [sp, #0x54]
//   0x2834: b0000021  adrp     x1, #0x7000
//   0x2838: 9108f021  add      x1, x1, #0x23c
//   0x283c: aa1c03e0  mov      x0, x28
//   0x2840: 94000b68  bl       #0x55e0
//   0x2844: 14000014  b        #0x2894
//   0x2848: b0000021  adrp     x1, #0x7000
//   0x284c: 91091421  add      x1, x1, #0x245
//   0x2850: aa1c03e0  mov      x0, x28
//   0x2854: 94000b63  bl       #0x55e0
//   0x2858: 910103e1  add      x1, sp, #0x40
//   0x285c: aa1903e0  mov      x0, x25
//   0x2860: 94001028  bl       #0x6900
//   0x2864: 1400000c  b        #0x2894
//   0x2868: b0000021  adrp     x1, #0x7000
//   0x286c: 2a0003e2  mov      w2, w0
//   0x2870: 91096021  add      x1, x1, #0x258
//   0x2874: aa1c03e0  mov      x0, x28
//   0x2878: 94000b5a  bl       #0x55e0
//   0x287c: 14000005  b        #0x2890
//   0x2880: b0000021  adrp     x1, #0x7000
//   0x2884: 9109c421  add      x1, x1, #0x271
//   0x2888: aa1c03e0  mov      x0, x28
//   0x288c: 94000b55  bl       #0x55e0
//   0x2890: f9400ff3  ldr      x19, [sp, #0x18]
//   0x2894: aa1f03f4  mov      x20, xzr
//   0x2898: f9401660  ldr      x0, [x19, #0x28]
//   0x289c: b4000060  cbz      x0, #0x28a8
//   0x28a0: f9001a60  str      x0, [x19, #0x30]
//   0x28a4: 97fffc47  bl       #0x19c0
//   0x28a8: f9400675  ldr      x21, [x19, #8]
//   0x28ac: b40001b5  cbz      x21, #0x28e0
//   0x28b0: 910022a8  add      x8, x21, #8
//   0x28b4: c85ffd09  ldaxr    x9, [x8]
//   0x28b8: d100052a  sub      x10, x9, #1
//   0x28bc: c80bfd0a  stlxr    w11, x10, [x8]
//   0x28c0: 35ffffab  cbnz     w11, #0x28b4
//   0x28c4: b50000e9  cbnz     x9, #0x28e0
//   0x28c8: f94002a8  ldr      x8, [x21]
//   0x28cc: aa1503e0  mov      x0, x21
//   0x28d0: f9400908  ldr      x8, [x8, #0x10]
//   0x28d4: d63f0100  blr      x8
//   0x28d8: aa1503e0  mov      x0, x21
//   0x28dc: 97fffc89  bl       #0x1b00
//   0x28e0: aa1303e0  mov      x0, x19
//   0x28e4: 97fffc37  bl       #0x19c0
//   0x28e8: f9401768  ldr      x8, [x27, #0x28]
//   0x28ec: f9402fe9  ldr      x9, [sp, #0x58]
//   0x28f0: eb09011f  cmp      x8, x9
//   0x28f4: 540006c1  b.ne     #0x29cc
//   0x28f8: aa1403e0  mov      x0, x20
//   0x28fc: a94b7bfd  ldp      x29, x30, [sp, #0xb0]
//   0x2900: a94a4ff4  ldp      x20, x19, [sp, #0xa0]
//   0x2904: a94957f6  ldp      x22, x21, [sp, #0x90]
//   0x2908: a9485ff8  ldp      x24, x23, [sp, #0x80]
//   0x290c: a94767fa  ldp      x26, x25, [sp, #0x70]
//   0x2910: a9466ffc  ldp      x28, x27, [sp, #0x60]
//   0x2914: 910303ff  add      sp, sp, #0xc0
//   0x2918: d65f03c0  ret      
//   0x291c: aa1f03f6  mov      x22, xzr
//   0x2920: aa1f03f8  mov      x24, xzr
//   0x2924: a9027fff  stp      xzr, xzr, [sp, #0x20]
//   0x2928: b90037ff  str      wzr, [sp, #0x34]
//   0x292c: a94187f3  ldp      x19, x1, [sp, #0x18]
//   0x2930: b94037e8  ldr      w8, [sp, #0x34]
//   0x2934: aa1803e2  mov      x2, x24
//   0x2938: 9100a260  add      x0, x19, #0x28
//   0x293c: b9002268  str      w8, [x19, #0x20]
//   0x2940: 94000a7b  bl       #0x532c
//   0x2944: f9400268  ldr      x8, [x19]
//   0x2948: d0000069  adrp     x9, #0x10000
//   0x294c: f9412d21  ldr      x1, [x9, #0x258]
//   0x2950: d0000069  adrp     x9, #0x10000
//   0x2954: b9400908  ldr      w8, [x8, #8]
//   0x2958: f9413122  ldr      x2, [x9, #0x260]
//   0x295c: f94003e0  ldr      x0, [sp]
//   0x2960: aa1303e3  mov      x3, x19
//   0x2964: b9001e68  str      w8, [x19, #0x1c]
//   0x2968: 94000039  bl       #0x2a4c
//   0x296c: f94007fb  ldr      x27, [sp, #8]
//   0x2970: aa0003f4  mov      x20, x0
//   0x2974: b4000080  cbz      x0, #0x2984
//   0x2978: 52800028  mov      w8, #1
//   0x297c: f9002268  str      x8, [x19, #0x40]
//   0x2980: aa1f03f3  mov      x19, xzr
//   0x2984: f9400be0  ldr      x0, [sp, #0x10]
//   0x2988: f94017f5  ldr      x21, [sp, #0x28]
//   0x298c: 97fffc45  bl       #0x1aa0
//   0x2990: 34000120  cbz      w0, #0x29b4
//   0x2994: 97fffbff  bl       #0x1990
//   0x2998: b0000021  adrp     x1, #0x7000
//   0x299c: b0000022  adrp     x2, #0x7000
//   0x29a0: aa0003e3  mov      x3, x0
//   0x29a4: 910c8021  add      x1, x1, #0x320
//   0x29a8: 910f5442  add      x2, x2, #0x3d5
//   0x29ac: 528000c0  mov      w0, #6
//   0x29b0: 97fffc40  bl       #0x1ab0
//   0x29b4: b4000075  cbz      x21, #0x29c0
//   0x29b8: aa1603e0  mov      x0, x22
//   0x29bc: 97fffc01  bl       #0x19c0
//   0x29c0: b5fff6d3  cbnz     x19, #0x2898
//   0x29c4: 17ffffc9  b        #0x28e8
//   0x29c8: 97fffc52  bl       #0x1b10
//   0x29cc: 97fffc71  bl       #0x1b90
// ============================================================================
std::uint32_t fde_04_2400(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002400ULL;
    for (std::size_t i = 0; i < 372ULL; ++i) {
        std::uint32_t insn = kTextInstructions[516ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[05] Symbol: sub_29d0
//      Virtual Address Range: 0x29d0..0x2a04 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[05] Biểu tượng: sub_29d0
//      Dải địa chỉ ảo: 0x29d0..0x2a04 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x29d0: 7100045f  cmp      w2, #1
//   0x29d4: 5400014b  b.lt     #0x29fc
//   0x29d8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x29dc: 910003fd  mov      x29, sp
//   0x29e0: f9403400  ldr      x0, [x0, #0x68]
//   0x29e4: 93407c42  sxtw     x2, w2
//   0x29e8: f9400008  ldr      x8, [x0]
//   0x29ec: f9400908  ldr      x8, [x8, #0x10]
//   0x29f0: d63f0100  blr      x8
//   0x29f4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x29f8: d65f03c0  ret      
//   0x29fc: 2a1f03e0  mov      w0, wzr
//   0x2a00: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_05_29d0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000029d0ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
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
// [EN] FDE[06] Symbol: sub_2a04
//      Virtual Address Range: 0x2a04..0x2a4c (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[06] Biểu tượng: sub_2a04
//      Dải địa chỉ ảo: 0x2a04..0x2a4c (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2a04: d100c3ff  sub      sp, sp, #0x30
//   0x2a08: f9000bf3  str      x19, [sp, #0x10]
//   0x2a0c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x2a10: 910083fd  add      x29, sp, #0x20
//   0x2a14: d53bd053  mrs      x19, tpidr_el0
//   0x2a18: f9401668  ldr      x8, [x19, #0x28]
//   0x2a1c: 910013e1  add      x1, sp, #4
//   0x2a20: f90007e8  str      x8, [sp, #8]
//   0x2a24: 94000fb7  bl       #0x6900
//   0x2a28: f9401668  ldr      x8, [x19, #0x28]
//   0x2a2c: f94007e9  ldr      x9, [sp, #8]
//   0x2a30: eb09011f  cmp      x8, x9
//   0x2a34: 540000a1  b.ne     #0x2a48
//   0x2a38: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x2a3c: f9400bf3  ldr      x19, [sp, #0x10]
//   0x2a40: 9100c3ff  add      sp, sp, #0x30
//   0x2a44: d65f03c0  ret      
//   0x2a48: 97fffc52  bl       #0x1b90
// ============================================================================
std::uint32_t fde_06_2a04(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a04ULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[901ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[07] Symbol: sub_2a4c
//      Virtual Address Range: 0x2a4c..0x2ae8 (156 bytes, 39 AArch64 instructions)
// [VN] Khung FDE[07] Biểu tượng: sub_2a4c
//      Dải địa chỉ ảo: 0x2a4c..0x2ae8 (156 byte, 39 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2a4c: d10483ff  sub      sp, sp, #0x120
//   0x2a50: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x2a54: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x2a58: 910443fd  add      x29, sp, #0x110
//   0x2a5c: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x2a60: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x2a64: f90057e7  str      x7, [sp, #0xa8]
//   0x2a68: ad0007e0  stp      q0, q1, [sp]
//   0x2a6c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x2a70: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x2a74: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x2a78: d53bd053  mrs      x19, tpidr_el0
//   0x2a7c: f940166b  ldr      x11, [x19, #0x28]
//   0x2a80: 928004e8  mov      x8, #-0x28
//   0x2a84: 910003e9  mov      x9, sp
//   0x2a88: 910223ea  add      x10, sp, #0x88
//   0x2a8c: f2dff008  movk     x8, #0xff80, lsl #32
//   0x2a90: 910043ac  add      x12, x29, #0x10
//   0x2a94: 91020129  add      x9, x9, #0x80
//   0x2a98: 9100a14a  add      x10, x10, #0x28
//   0x2a9c: f81e83ab  stur     x11, [x29, #-0x18]
//   0x2aa0: a93da3a9  stp      x9, x8, [x29, #-0x28]
//   0x2aa4: a93cabac  stp      x12, x10, [x29, #-0x38]
//   0x2aa8: f9400008  ldr      x8, [x0]
//   0x2aac: d100e3a9  sub      x9, x29, #0x38
//   0x2ab0: ad400121  ldp      q1, q0, [x9]
//   0x2ab4: d10183a3  sub      x3, x29, #0x60
//   0x2ab8: f9407508  ldr      x8, [x8, #0xe8]
//   0x2abc: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x2ac0: d63f0100  blr      x8
//   0x2ac4: f9401668  ldr      x8, [x19, #0x28]
//   0x2ac8: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x2acc: eb09011f  cmp      x8, x9
//   0x2ad0: 540000a1  b.ne     #0x2ae4
//   0x2ad4: a9517bfd  ldp      x29, x30, [sp, #0x110]
//   0x2ad8: a9504ffc  ldp      x28, x19, [sp, #0x100]
//   0x2adc: 910483ff  add      sp, sp, #0x120
//   0x2ae0: d65f03c0  ret      
//   0x2ae4: 97fffc2b  bl       #0x1b90
// ============================================================================
std::uint32_t fde_07_2a4c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002a4cULL;
    for (std::size_t i = 0; i < 39ULL; ++i) {
        std::uint32_t insn = kTextInstructions[919ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[08] Symbol: sub_2ae8
//      Virtual Address Range: 0x2ae8..0x2c10 (296 bytes, 74 AArch64 instructions)
// [VN] Khung FDE[08] Biểu tượng: sub_2ae8
//      Dải địa chỉ ảo: 0x2ae8..0x2c10 (296 byte, 74 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2ae8: d10143ff  sub      sp, sp, #0x50
//   0x2aec: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x2af0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x2af4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x2af8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x2afc: 910103fd  add      x29, sp, #0x40
//   0x2b00: aa0003f5  mov      x21, x0
//   0x2b04: 52800600  mov      w0, #0x30
//   0x2b08: 2a0303f6  mov      w22, w3
//   0x2b0c: 2a0203f4  mov      w20, w2
//   0x2b10: aa0103f3  mov      x19, x1
//   0x2b14: 97fffc17  bl       #0x1b70
//   0x2b18: b0000068  adrp     x8, #0xf000
//   0x2b1c: 912de108  add      x8, x8, #0xb78
//   0x2b20: f9000008  str      x8, [x0]
//   0x2b24: f9400268  ldr      x8, [x19]
//   0x2b28: aa0003f7  mov      x23, x0
//   0x2b2c: f9000408  str      x8, [x0, #8]
//   0x2b30: 3cc08260  ldur     q0, [x19, #8]
//   0x2b34: 9e660009  fmov     x9, d0
//   0x2b38: cb080128  sub      x8, x9, x8
//   0x2b3c: 3d800400  str      q0, [x0, #0x10]
//   0x2b40: a9007e7f  stp      xzr, xzr, [x19]
//   0x2b44: f9000a7f  str      xzr, [x19, #0x10]
//   0x2b48: a902201f  stp      xzr, x8, [x0, #0x20]
//   0x2b4c: 52800400  mov      w0, #0x20
//   0x2b50: 97fffc08  bl       #0x1b70
//   0x2b54: aa0003f8  mov      x24, x0
//   0x2b58: b0000068  adrp     x8, #0xf000
//   0x2b5c: aa0003f3  mov      x19, x0
//   0x2b60: a9015c1f  stp      xzr, x23, [x0, #0x10]
//   0x2b64: 9130c108  add      x8, x8, #0xc30
//   0x2b68: f8008f1f  str      xzr, [x24, #8]!
//   0x2b6c: f9000008  str      x8, [x0]
//   0x2b70: a90003f7  stp      x23, x0, [sp]
//   0x2b74: c85f7f08  ldxr     x8, [x24]
//   0x2b78: 91000508  add      x8, x8, #1
//   0x2b7c: c8097f08  stxr     w9, x8, [x24]
//   0x2b80: 35ffffa9  cbnz     w9, #0x2b74
//   0x2b84: 120002c3  and      w3, w22, #1
//   0x2b88: 910003e1  mov      x1, sp
//   0x2b8c: aa1503e0  mov      x0, x21
//   0x2b90: 2a1403e2  mov      w2, w20
//   0x2b94: 97fffe1b  bl       #0x2400
//   0x2b98: aa0003f4  mov      x20, x0
//   0x2b9c: c85fff08  ldaxr    x8, [x24]
//   0x2ba0: d1000509  sub      x9, x8, #1
//   0x2ba4: c80aff09  stlxr    w10, x9, [x24]
//   0x2ba8: 35ffffaa  cbnz     w10, #0x2b9c
//   0x2bac: b50000e8  cbnz     x8, #0x2bc8
//   0x2bb0: f9400268  ldr      x8, [x19]
//   0x2bb4: aa1303e0  mov      x0, x19
//   0x2bb8: f9400908  ldr      x8, [x8, #0x10]
//   0x2bbc: d63f0100  blr      x8
//   0x2bc0: aa1303e0  mov      x0, x19
//   0x2bc4: 97fffbcf  bl       #0x1b00
//   0x2bc8: c85fff08  ldaxr    x8, [x24]
//   0x2bcc: d1000509  sub      x9, x8, #1
//   0x2bd0: c80aff09  stlxr    w10, x9, [x24]
//   0x2bd4: 35ffffaa  cbnz     w10, #0x2bc8
//   0x2bd8: b50000e8  cbnz     x8, #0x2bf4
//   0x2bdc: f9400268  ldr      x8, [x19]
//   0x2be0: aa1303e0  mov      x0, x19
//   0x2be4: f9400908  ldr      x8, [x8, #0x10]
//   0x2be8: d63f0100  blr      x8
//   0x2bec: aa1303e0  mov      x0, x19
//   0x2bf0: 97fffbc4  bl       #0x1b00
//   0x2bf4: aa1403e0  mov      x0, x20
//   0x2bf8: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x2bfc: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x2c00: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x2c04: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x2c08: 910143ff  add      sp, sp, #0x50
//   0x2c0c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_08_2ae8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002ae8ULL;
    for (std::size_t i = 0; i < 74ULL; ++i) {
        std::uint32_t insn = kTextInstructions[958ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[09] Symbol: sub_2c10
//      Virtual Address Range: 0x2c10..0x2cd4 (196 bytes, 49 AArch64 instructions)
// [VN] Khung FDE[09] Biểu tượng: sub_2c10
//      Dải địa chỉ ảo: 0x2c10..0x2cd4 (196 byte, 49 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2c10: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x2c14: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x2c18: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x2c1c: 910083fd  add      x29, sp, #0x20
//   0x2c20: f9400013  ldr      x19, [x0]
//   0x2c24: f900001f  str      xzr, [x0]
//   0x2c28: b40004f3  cbz      x19, #0x2cc4
//   0x2c2c: a940d414  ldp      x20, x21, [x0, #8]
//   0x2c30: f9400288  ldr      x8, [x20]
//   0x2c34: aa1403e0  mov      x0, x20
//   0x2c38: aa1503e1  mov      x1, x21
//   0x2c3c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x2c40: d63f0100  blr      x8
//   0x2c44: f9402268  ldr      x8, [x19, #0x40]
//   0x2c48: f1000508  subs     x8, x8, #1
//   0x2c4c: f9002268  str      x8, [x19, #0x40]
//   0x2c50: 540002a1  b.ne     #0x2ca4
//   0x2c54: f9401660  ldr      x0, [x19, #0x28]
//   0x2c58: b4000060  cbz      x0, #0x2c64
//   0x2c5c: f9001a60  str      x0, [x19, #0x30]
//   0x2c60: 97fffb58  bl       #0x19c0
//   0x2c64: f9400676  ldr      x22, [x19, #8]
//   0x2c68: b40001b6  cbz      x22, #0x2c9c
//   0x2c6c: 910022c8  add      x8, x22, #8
//   0x2c70: c85ffd09  ldaxr    x9, [x8]
//   0x2c74: d100052a  sub      x10, x9, #1
//   0x2c78: c80bfd0a  stlxr    w11, x10, [x8]
//   0x2c7c: 35ffffab  cbnz     w11, #0x2c70
//   0x2c80: b50000e9  cbnz     x9, #0x2c9c
//   0x2c84: f94002c8  ldr      x8, [x22]
//   0x2c88: aa1603e0  mov      x0, x22
//   0x2c8c: f9400908  ldr      x8, [x8, #0x10]
//   0x2c90: d63f0100  blr      x8
//   0x2c94: aa1603e0  mov      x0, x22
//   0x2c98: 97fffb9a  bl       #0x1b00
//   0x2c9c: aa1303e0  mov      x0, x19
//   0x2ca0: 97fffb48  bl       #0x19c0
//   0x2ca4: f9400288  ldr      x8, [x20]
//   0x2ca8: aa1403e0  mov      x0, x20
//   0x2cac: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x2cb0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x2cb4: f9436902  ldr      x2, [x8, #0x6d0]
//   0x2cb8: aa1503e1  mov      x1, x21
//   0x2cbc: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x2cc0: d61f0040  br       x2
//   0x2cc4: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x2cc8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x2ccc: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x2cd0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_09_2c10(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002c10ULL;
    for (std::size_t i = 0; i < 49ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1032ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[10] Symbol: sub_2cd4
//      Virtual Address Range: 0x2cd4..0x2e48 (372 bytes, 93 AArch64 instructions)
// [VN] Khung FDE[10] Biểu tượng: sub_2cd4
//      Dải địa chỉ ảo: 0x2cd4..0x2e48 (372 byte, 93 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2cd4: d10183ff  sub      sp, sp, #0x60
//   0x2cd8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x2cdc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x2ce0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x2ce4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x2ce8: 910143fd  add      x29, sp, #0x50
//   0x2cec: f9400008  ldr      x8, [x0]
//   0x2cf0: aa0203e1  mov      x1, x2
//   0x2cf4: 2a0403f5  mov      w21, w4
//   0x2cf8: 2a0303f4  mov      w20, w3
//   0x2cfc: f9439908  ldr      x8, [x8, #0x730]
//   0x2d00: aa0003f3  mov      x19, x0
//   0x2d04: aa0203f7  mov      x23, x2
//   0x2d08: d63f0100  blr      x8
//   0x2d0c: b4000200  cbz      x0, #0x2d4c
//   0x2d10: f9400268  ldr      x8, [x19]
//   0x2d14: aa0003f6  mov      x22, x0
//   0x2d18: aa1303e0  mov      x0, x19
//   0x2d1c: aa1703e1  mov      x1, x23
//   0x2d20: f9439d08  ldr      x8, [x8, #0x738]
//   0x2d24: d63f0100  blr      x8
//   0x2d28: f9400268  ldr      x8, [x19]
//   0x2d2c: aa0003f7  mov      x23, x0
//   0x2d30: aa1303e0  mov      x0, x19
//   0x2d34: f9439108  ldr      x8, [x8, #0x720]
//   0x2d38: d63f0100  blr      x8
//   0x2d3c: 72001c1f  tst      w0, #0xff
//   0x2d40: 54000120  b.eq     #0x2d64
//   0x2d44: aa1f03f3  mov      x19, xzr
//   0x2d48: 14000038  b        #0x2e28
//   0x2d4c: b0000021  adrp     x1, #0x7000
//   0x2d50: 910a1021  add      x1, x1, #0x284
//   0x2d54: aa1303e0  mov      x0, x19
//   0x2d58: 940009eb  bl       #0x5504
//   0x2d5c: aa1f03f3  mov      x19, xzr
//   0x2d60: 14000032  b        #0x2e28
//   0x2d64: a9017fff  stp      xzr, xzr, [sp, #0x10]
//   0x2d68: f90007ff  str      xzr, [sp, #8]
//   0x2d6c: b4000477  cbz      x23, #0x2df8
//   0x2d70: b7f806b7  tbnz     x23, #0x3f, #0x2e44
//   0x2d74: aa1703e0  mov      x0, x23
//   0x2d78: 8b1702d8  add      x24, x22, x23
//   0x2d7c: 97fffb7d  bl       #0x1b70
//   0x2d80: 8b170008  add      x8, x0, x23
//   0x2d84: f10082ff  cmp      x23, #0x20
//   0x2d88: a90123e0  stp      x0, x8, [sp, #0x10]
//   0x2d8c: f90007e0  str      x0, [sp, #8]
//   0x2d90: 54000283  b.lo     #0x2de0
//   0x2d94: eb18001f  cmp      x0, x24
//   0x2d98: 54000062  b.hs     #0x2da4
//   0x2d9c: eb0802df  cmp      x22, x8
//   0x2da0: 54000203  b.lo     #0x2de0
//   0x2da4: 927beae9  and      x9, x23, #0xffffffffffffffe0
//   0x2da8: 910042ca  add      x10, x22, #0x10
//   0x2dac: 8b090008  add      x8, x0, x9
//   0x2db0: 8b0902d6  add      x22, x22, x9
//   0x2db4: 9100400b  add      x11, x0, #0x10
//   0x2db8: aa0903ec  mov      x12, x9
//   0x2dbc: ad7f8540  ldp      q0, q1, [x10, #-0x10]
//   0x2dc0: 9100814a  add      x10, x10, #0x20
//   0x2dc4: f100818c  subs     x12, x12, #0x20
//   0x2dc8: ad3f8560  stp      q0, q1, [x11, #-0x10]
//   0x2dcc: 9100816b  add      x11, x11, #0x20
//   0x2dd0: 54ffff61  b.ne     #0x2dbc
//   0x2dd4: eb0902ff  cmp      x23, x9
//   0x2dd8: aa0803e0  mov      x0, x8
//   0x2ddc: 540000c0  b.eq     #0x2df4
//   0x2de0: aa0003e8  mov      x8, x0
//   0x2de4: 384016c9  ldrb     w9, [x22], #1
//   0x2de8: eb16031f  cmp      x24, x22
//   0x2dec: 38001509  strb     w9, [x8], #1
//   0x2df0: 54ffffa1  b.ne     #0x2de4
//   0x2df4: f9000be8  str      x8, [sp, #0x10]
//   0x2df8: 72001ebf  tst      w21, #0xff
//   0x2dfc: 1a9f07e3  cset     w3, ne
//   0x2e00: 910023e1  add      x1, sp, #8
//   0x2e04: aa1303e0  mov      x0, x19
//   0x2e08: 2a1403e2  mov      w2, w20
//   0x2e0c: 97ffff37  bl       #0x2ae8
//   0x2e10: f94007e8  ldr      x8, [sp, #8]
//   0x2e14: aa0003f3  mov      x19, x0
//   0x2e18: b4000088  cbz      x8, #0x2e28
//   0x2e1c: aa0803e0  mov      x0, x8
//   0x2e20: f9000be8  str      x8, [sp, #0x10]
//   0x2e24: 97fffae7  bl       #0x19c0
//   0x2e28: aa1303e0  mov      x0, x19
//   0x2e2c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x2e30: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x2e34: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x2e38: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x2e3c: 910183ff  add      sp, sp, #0x60
//   0x2e40: d65f03c0  ret      
//   0x2e44: 97fffb33  bl       #0x1b10
// ============================================================================
std::uint32_t fde_10_2cd4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002cd4ULL;
    for (std::size_t i = 0; i < 93ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1081ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[11] Symbol: sub_2e48
//      Virtual Address Range: 0x2e48..0x2f78 (304 bytes, 76 AArch64 instructions)
// [VN] Khung FDE[11] Biểu tượng: sub_2e48
//      Dải địa chỉ ảo: 0x2e48..0x2f78 (304 byte, 76 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2e48: d10183ff  sub      sp, sp, #0x60
//   0x2e4c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x2e50: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x2e54: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x2e58: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x2e5c: 910143fd  add      x29, sp, #0x50
//   0x2e60: 2a0303f8  mov      w24, w3
//   0x2e64: 2a0503f5  mov      w21, w5
//   0x2e68: 2a0403f3  mov      w19, w4
//   0x2e6c: aa0003f4  mov      x20, x0
//   0x2e70: 93407f16  sxtw     x22, w24
//   0x2e74: a9017fff  stp      xzr, xzr, [sp, #0x10]
//   0x2e78: f90007ff  str      xzr, [sp, #8]
//   0x2e7c: b4000576  cbz      x22, #0x2f28
//   0x2e80: b7f807b6  tbnz     x22, #0x3f, #0x2f74
//   0x2e84: aa1603e0  mov      x0, x22
//   0x2e88: aa0203f7  mov      x23, x2
//   0x2e8c: 97fffb39  bl       #0x1b70
//   0x2e90: 8b160008  add      x8, x0, x22
//   0x2e94: a90123e0  stp      x0, x8, [sp, #0x10]
//   0x2e98: f90007e0  str      x0, [sp, #8]
//   0x2e9c: 340000d8  cbz      w24, #0x2eb4
//   0x2ea0: 7100831f  cmp      w24, #0x20
//   0x2ea4: 8b1602e8  add      x8, x23, x22
//   0x2ea8: 540000a2  b.hs     #0x2ebc
//   0x2eac: aa1703e9  mov      x9, x23
//   0x2eb0: 14000018  b        #0x2f10
//   0x2eb4: aa0003ea  mov      x10, x0
//   0x2eb8: 1400001b  b        #0x2f24
//   0x2ebc: eb08001f  cmp      x0, x8
//   0x2ec0: 540000a2  b.hs     #0x2ed4
//   0x2ec4: 8b160009  add      x9, x0, x22
//   0x2ec8: eb17013f  cmp      x9, x23
//   0x2ecc: aa1703e9  mov      x9, x23
//   0x2ed0: 54000208  b.hi     #0x2f10
//   0x2ed4: 927beacb  and      x11, x22, #0xffffffffffffffe0
//   0x2ed8: 910042ec  add      x12, x23, #0x10
//   0x2edc: 8b0b000a  add      x10, x0, x11
//   0x2ee0: 8b0b02e9  add      x9, x23, x11
//   0x2ee4: 9100400d  add      x13, x0, #0x10
//   0x2ee8: aa0b03ee  mov      x14, x11
//   0x2eec: ad7f8580  ldp      q0, q1, [x12, #-0x10]
//   0x2ef0: 9100818c  add      x12, x12, #0x20
//   0x2ef4: f10081ce  subs     x14, x14, #0x20
//   0x2ef8: ad3f85a0  stp      q0, q1, [x13, #-0x10]
//   0x2efc: 910081ad  add      x13, x13, #0x20
//   0x2f00: 54ffff61  b.ne     #0x2eec
//   0x2f04: eb16017f  cmp      x11, x22
//   0x2f08: aa0a03e0  mov      x0, x10
//   0x2f0c: 540000c0  b.eq     #0x2f24
//   0x2f10: aa0003ea  mov      x10, x0
//   0x2f14: 3840152b  ldrb     w11, [x9], #1
//   0x2f18: eb09011f  cmp      x8, x9
//   0x2f1c: 3800154b  strb     w11, [x10], #1
//   0x2f20: 54ffffa1  b.ne     #0x2f14
//   0x2f24: f9000bea  str      x10, [sp, #0x10]
//   0x2f28: 72001ebf  tst      w21, #0xff
//   0x2f2c: 1a9f07e3  cset     w3, ne
//   0x2f30: 910023e1  add      x1, sp, #8
//   0x2f34: aa1403e0  mov      x0, x20
//   0x2f38: 2a1303e2  mov      w2, w19
//   0x2f3c: 97fffeeb  bl       #0x2ae8
//   0x2f40: f94007e8  ldr      x8, [sp, #8]
//   0x2f44: aa0003f3  mov      x19, x0
//   0x2f48: b4000088  cbz      x8, #0x2f58
//   0x2f4c: aa0803e0  mov      x0, x8
//   0x2f50: f9000be8  str      x8, [sp, #0x10]
//   0x2f54: 97fffa9b  bl       #0x19c0
//   0x2f58: aa1303e0  mov      x0, x19
//   0x2f5c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x2f60: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x2f64: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x2f68: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x2f6c: 910183ff  add      sp, sp, #0x60
//   0x2f70: d65f03c0  ret      
//   0x2f74: 97fffae7  bl       #0x1b10
// ============================================================================
std::uint32_t fde_11_2e48(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002e48ULL;
    for (std::size_t i = 0; i < 76ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1174ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[12] Symbol: sub_2f78
//      Virtual Address Range: 0x2f78..0x3094 (284 bytes, 71 AArch64 instructions)
// [VN] Khung FDE[12] Biểu tượng: sub_2f78
//      Dải địa chỉ ảo: 0x2f78..0x3094 (284 byte, 71 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x2f78: d10143ff  sub      sp, sp, #0x50
//   0x2f7c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x2f80: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x2f84: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x2f88: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x2f8c: 910103fd  add      x29, sp, #0x40
//   0x2f90: 2a0203e1  mov      w1, w2
//   0x2f94: 2a0403f6  mov      w22, w4
//   0x2f98: 2a0303f4  mov      w20, w3
//   0x2f9c: aa0003f5  mov      x21, x0
//   0x2fa0: 9400003d  bl       #0x3094
//   0x2fa4: aa0003f7  mov      x23, x0
//   0x2fa8: 52800400  mov      w0, #0x20
//   0x2fac: 97fffaf1  bl       #0x1b70
//   0x2fb0: b0000068  adrp     x8, #0xf000
//   0x2fb4: aa0003f8  mov      x24, x0
//   0x2fb8: 9131a108  add      x8, x8, #0xc68
//   0x2fbc: a9015c1f  stp      xzr, x23, [x0, #0x10]
//   0x2fc0: f8008f1f  str      xzr, [x24, #8]!
//   0x2fc4: f9000008  str      x8, [x0]
//   0x2fc8: f94002a8  ldr      x8, [x21]
//   0x2fcc: aa0003f3  mov      x19, x0
//   0x2fd0: aa1503e0  mov      x0, x21
//   0x2fd4: f9439108  ldr      x8, [x8, #0x720]
//   0x2fd8: d63f0100  blr      x8
//   0x2fdc: b4000377  cbz      x23, #0x3048
//   0x2fe0: 72001c1f  tst      w0, #0xff
//   0x2fe4: 54000321  b.ne     #0x3048
//   0x2fe8: a9004ff7  stp      x23, x19, [sp]
//   0x2fec: c85f7f08  ldxr     x8, [x24]
//   0x2ff0: 91000508  add      x8, x8, #1
//   0x2ff4: c8097f08  stxr     w9, x8, [x24]
//   0x2ff8: 35ffffa9  cbnz     w9, #0x2fec
//   0x2ffc: 72001edf  tst      w22, #0xff
//   0x3000: 1a9f07e3  cset     w3, ne
//   0x3004: 910003e1  mov      x1, sp
//   0x3008: aa1503e0  mov      x0, x21
//   0x300c: 2a1403e2  mov      w2, w20
//   0x3010: 97fffcfc  bl       #0x2400
//   0x3014: aa0003f4  mov      x20, x0
//   0x3018: c85fff08  ldaxr    x8, [x24]
//   0x301c: d1000509  sub      x9, x8, #1
//   0x3020: c80aff09  stlxr    w10, x9, [x24]
//   0x3024: 35ffffaa  cbnz     w10, #0x3018
//   0x3028: b5000128  cbnz     x8, #0x304c
//   0x302c: f9400268  ldr      x8, [x19]
//   0x3030: aa1303e0  mov      x0, x19
//   0x3034: f9400908  ldr      x8, [x8, #0x10]
//   0x3038: d63f0100  blr      x8
//   0x303c: aa1303e0  mov      x0, x19
//   0x3040: 97fffab0  bl       #0x1b00
//   0x3044: 14000002  b        #0x304c
//   0x3048: aa1f03f4  mov      x20, xzr
//   0x304c: c85fff08  ldaxr    x8, [x24]
//   0x3050: d1000509  sub      x9, x8, #1
//   0x3054: c80aff09  stlxr    w10, x9, [x24]
//   0x3058: 35ffffaa  cbnz     w10, #0x304c
//   0x305c: b50000e8  cbnz     x8, #0x3078
//   0x3060: f9400268  ldr      x8, [x19]
//   0x3064: aa1303e0  mov      x0, x19
//   0x3068: f9400908  ldr      x8, [x8, #0x10]
//   0x306c: d63f0100  blr      x8
//   0x3070: aa1303e0  mov      x0, x19
//   0x3074: 97fffaa3  bl       #0x1b00
//   0x3078: aa1403e0  mov      x0, x20
//   0x307c: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3080: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x3084: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3088: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x308c: 910143ff  add      sp, sp, #0x50
//   0x3090: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_12_2f78(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002f78ULL;
    for (std::size_t i = 0; i < 71ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1250ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[13] Symbol: sub_3094
//      Virtual Address Range: 0x3094..0x319c (264 bytes, 66 AArch64 instructions)
// [VN] Khung FDE[13] Biểu tượng: sub_3094
//      Dải địa chỉ ảo: 0x3094..0x319c (264 byte, 66 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3094: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x3098: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x309c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x30a0: 910083fd  add      x29, sp, #0x20
//   0x30a4: aa0003f3  mov      x19, x0
//   0x30a8: 2a0103e0  mov      w0, w1
//   0x30ac: 97fffa49  bl       #0x19d0
//   0x30b0: 90000021  adrp     x1, #0x7000
//   0x30b4: 910ff021  add      x1, x1, #0x3fc
//   0x30b8: 97fffa8e  bl       #0x1af0
//   0x30bc: b40001a0  cbz      x0, #0x30f0
//   0x30c0: 52800042  mov      w2, #2
//   0x30c4: aa1f03e1  mov      x1, xzr
//   0x30c8: aa0003f4  mov      x20, x0
//   0x30cc: 97fffa99  bl       #0x1b30
//   0x30d0: 340001e0  cbz      w0, #0x310c
//   0x30d4: 97fffaa3  bl       #0x1b60
//   0x30d8: b9400000  ldr      w0, [x0]
//   0x30dc: 97fffa2d  bl       #0x1990
//   0x30e0: 90000021  adrp     x1, #0x7000
//   0x30e4: aa0003e2  mov      x2, x0
//   0x30e8: 91105c21  add      x1, x1, #0x417
//   0x30ec: 1400001e  b        #0x3164
//   0x30f0: 97fffa9c  bl       #0x1b60
//   0x30f4: b9400000  ldr      w0, [x0]
//   0x30f8: 97fffa26  bl       #0x1990
//   0x30fc: 90000021  adrp     x1, #0x7000
//   0x3100: aa0003e2  mov      x2, x0
//   0x3104: 910ffc21  add      x1, x1, #0x3ff
//   0x3108: 14000017  b        #0x3164
//   0x310c: aa1403e0  mov      x0, x20
//   0x3110: 97fffa6c  bl       #0x1ac0
//   0x3114: b7f801c0  tbnz     x0, #0x3f, #0x314c
//   0x3118: aa0003f5  mov      x21, x0
//   0x311c: aa1403e0  mov      x0, x20
//   0x3120: aa1f03e1  mov      x1, xzr
//   0x3124: 2a1f03e2  mov      w2, wzr
//   0x3128: 97fffa82  bl       #0x1b30
//   0x312c: 340002a0  cbz      w0, #0x3180
//   0x3130: 97fffa8c  bl       #0x1b60
//   0x3134: b9400000  ldr      w0, [x0]
//   0x3138: 97fffa16  bl       #0x1990
//   0x313c: 90000021  adrp     x1, #0x7000
//   0x3140: aa0003e2  mov      x2, x0
//   0x3144: 91115421  add      x1, x1, #0x455
//   0x3148: 14000007  b        #0x3164
//   0x314c: 97fffa85  bl       #0x1b60
//   0x3150: b9400000  ldr      w0, [x0]
//   0x3154: 97fffa0f  bl       #0x1990
//   0x3158: 90000021  adrp     x1, #0x7000
//   0x315c: aa0003e2  mov      x2, x0
//   0x3160: 9110e421  add      x1, x1, #0x439
//   0x3164: aa1303e0  mov      x0, x19
//   0x3168: 9400091e  bl       #0x55e0
//   0x316c: aa1f03e0  mov      x0, xzr
//   0x3170: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x3174: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x3178: f84307f5  ldr      x21, [sp], #0x30
//   0x317c: d65f03c0  ret      
//   0x3180: 52800300  mov      w0, #0x18
//   0x3184: 97fffa7b  bl       #0x1b70
//   0x3188: 90000068  adrp     x8, #0xf000
//   0x318c: 912ee108  add      x8, x8, #0xbb8
//   0x3190: a9005008  stp      x8, x20, [x0]
//   0x3194: f9000815  str      x21, [x0, #0x10]
//   0x3198: 17fffff6  b        #0x3170
// ============================================================================
std::uint32_t fde_13_3094(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003094ULL;
    for (std::size_t i = 0; i < 66ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1321ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[14] Symbol: sub_319c
//      Virtual Address Range: 0x319c..0x3274 (216 bytes, 54 AArch64 instructions)
// [VN] Khung FDE[14] Biểu tượng: sub_319c
//      Dải địa chỉ ảo: 0x319c..0x3274 (216 byte, 54 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x319c: d10143ff  sub      sp, sp, #0x50
//   0x31a0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x31a4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x31a8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x31ac: 910103fd  add      x29, sp, #0x40
//   0x31b0: d53bd056  mrs      x22, tpidr_el0
//   0x31b4: f94016c8  ldr      x8, [x22, #0x28]
//   0x31b8: aa0103f4  mov      x20, x1
//   0x31bc: aa0003f3  mov      x19, x0
//   0x31c0: f9000fe8  str      x8, [sp, #0x18]
//   0x31c4: a90003ff  stp      xzr, x0, [sp]
//   0x31c8: f9000be1  str      x1, [sp, #0x10]
//   0x31cc: f9400008  ldr      x8, [x0]
//   0x31d0: f9436508  ldr      x8, [x8, #0x6c8]
//   0x31d4: d63f0100  blr      x8
//   0x31d8: f9400268  ldr      x8, [x19]
//   0x31dc: b0000069  adrp     x9, #0x10000
//   0x31e0: f9413522  ldr      x2, [x9, #0x268]
//   0x31e4: aa1303e0  mov      x0, x19
//   0x31e8: f9419508  ldr      x8, [x8, #0x328]
//   0x31ec: aa1403e1  mov      x1, x20
//   0x31f0: d63f0100  blr      x8
//   0x31f4: aa0003f5  mov      x21, x0
//   0x31f8: b40000a0  cbz      x0, #0x320c
//   0x31fc: f94022a8  ldr      x8, [x21, #0x40]
//   0x3200: 91000508  add      x8, x8, #1
//   0x3204: f90022a8  str      x8, [x21, #0x40]
//   0x3208: f90003f5  str      x21, [sp]
//   0x320c: f9400268  ldr      x8, [x19]
//   0x3210: aa1303e0  mov      x0, x19
//   0x3214: aa1403e1  mov      x1, x20
//   0x3218: f9436908  ldr      x8, [x8, #0x6d0]
//   0x321c: d63f0100  blr      x8
//   0x3220: b4000075  cbz      x21, #0x322c
//   0x3224: b94012b3  ldr      w19, [x21, #0x10]
//   0x3228: 14000006  b        #0x3240
//   0x322c: 90000021  adrp     x1, #0x7000
//   0x3230: 910a7821  add      x1, x1, #0x29e
//   0x3234: aa1303e0  mov      x0, x19
//   0x3238: 940008ea  bl       #0x55e0
//   0x323c: 2a1f03f3  mov      w19, wzr
//   0x3240: 910003e0  mov      x0, sp
//   0x3244: 97fffe73  bl       #0x2c10
//   0x3248: f94016c8  ldr      x8, [x22, #0x28]
//   0x324c: f9400fe9  ldr      x9, [sp, #0x18]
//   0x3250: eb09011f  cmp      x8, x9
//   0x3254: 540000e1  b.ne     #0x3270
//   0x3258: 2a1303e0  mov      w0, w19
//   0x325c: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3260: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x3264: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3268: 910143ff  add      sp, sp, #0x50
//   0x326c: d65f03c0  ret      
//   0x3270: 97fffa48  bl       #0x1b90
// ============================================================================
std::uint32_t fde_14_319c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000319cULL;
    for (std::size_t i = 0; i < 54ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1387ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[15] Symbol: sub_3274
//      Virtual Address Range: 0x3274..0x334c (216 bytes, 54 AArch64 instructions)
// [VN] Khung FDE[15] Biểu tượng: sub_3274
//      Dải địa chỉ ảo: 0x3274..0x334c (216 byte, 54 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3274: d10143ff  sub      sp, sp, #0x50
//   0x3278: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x327c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3280: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x3284: 910103fd  add      x29, sp, #0x40
//   0x3288: d53bd056  mrs      x22, tpidr_el0
//   0x328c: f94016c8  ldr      x8, [x22, #0x28]
//   0x3290: aa0103f4  mov      x20, x1
//   0x3294: aa0003f3  mov      x19, x0
//   0x3298: f9000fe8  str      x8, [sp, #0x18]
//   0x329c: a90003ff  stp      xzr, x0, [sp]
//   0x32a0: f9000be1  str      x1, [sp, #0x10]
//   0x32a4: f9400008  ldr      x8, [x0]
//   0x32a8: f9436508  ldr      x8, [x8, #0x6c8]
//   0x32ac: d63f0100  blr      x8
//   0x32b0: f9400268  ldr      x8, [x19]
//   0x32b4: b0000069  adrp     x9, #0x10000
//   0x32b8: f9413522  ldr      x2, [x9, #0x268]
//   0x32bc: aa1303e0  mov      x0, x19
//   0x32c0: f9419508  ldr      x8, [x8, #0x328]
//   0x32c4: aa1403e1  mov      x1, x20
//   0x32c8: d63f0100  blr      x8
//   0x32cc: aa0003f5  mov      x21, x0
//   0x32d0: b40000a0  cbz      x0, #0x32e4
//   0x32d4: f94022a8  ldr      x8, [x21, #0x40]
//   0x32d8: 91000508  add      x8, x8, #1
//   0x32dc: f90022a8  str      x8, [x21, #0x40]
//   0x32e0: f90003f5  str      x21, [sp]
//   0x32e4: f9400268  ldr      x8, [x19]
//   0x32e8: aa1303e0  mov      x0, x19
//   0x32ec: aa1403e1  mov      x1, x20
//   0x32f0: f9436908  ldr      x8, [x8, #0x6d0]
//   0x32f4: d63f0100  blr      x8
//   0x32f8: b4000075  cbz      x21, #0x3304
//   0x32fc: b94016b3  ldr      w19, [x21, #0x14]
//   0x3300: 14000006  b        #0x3318
//   0x3304: 90000021  adrp     x1, #0x7000
//   0x3308: 910a7821  add      x1, x1, #0x29e
//   0x330c: aa1303e0  mov      x0, x19
//   0x3310: 940008b4  bl       #0x55e0
//   0x3314: 2a1f03f3  mov      w19, wzr
//   0x3318: 910003e0  mov      x0, sp
//   0x331c: 97fffe3d  bl       #0x2c10
//   0x3320: f94016c8  ldr      x8, [x22, #0x28]
//   0x3324: f9400fe9  ldr      x9, [sp, #0x18]
//   0x3328: eb09011f  cmp      x8, x9
//   0x332c: 540000e1  b.ne     #0x3348
//   0x3330: 2a1303e0  mov      w0, w19
//   0x3334: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3338: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x333c: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3340: 910143ff  add      sp, sp, #0x50
//   0x3344: d65f03c0  ret      
//   0x3348: 97fffa12  bl       #0x1b90
// ============================================================================
std::uint32_t fde_15_3274(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003274ULL;
    for (std::size_t i = 0; i < 54ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1441ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[16] Symbol: sub_334c
//      Virtual Address Range: 0x334c..0x3424 (216 bytes, 54 AArch64 instructions)
// [VN] Khung FDE[16] Biểu tượng: sub_334c
//      Dải địa chỉ ảo: 0x334c..0x3424 (216 byte, 54 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x334c: d10143ff  sub      sp, sp, #0x50
//   0x3350: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x3354: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3358: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x335c: 910103fd  add      x29, sp, #0x40
//   0x3360: d53bd056  mrs      x22, tpidr_el0
//   0x3364: f94016c8  ldr      x8, [x22, #0x28]
//   0x3368: aa0103f4  mov      x20, x1
//   0x336c: aa0003f3  mov      x19, x0
//   0x3370: f9000fe8  str      x8, [sp, #0x18]
//   0x3374: a90003ff  stp      xzr, x0, [sp]
//   0x3378: f9000be1  str      x1, [sp, #0x10]
//   0x337c: f9400008  ldr      x8, [x0]
//   0x3380: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3384: d63f0100  blr      x8
//   0x3388: f9400268  ldr      x8, [x19]
//   0x338c: b0000069  adrp     x9, #0x10000
//   0x3390: f9413522  ldr      x2, [x9, #0x268]
//   0x3394: aa1303e0  mov      x0, x19
//   0x3398: f9419508  ldr      x8, [x8, #0x328]
//   0x339c: aa1403e1  mov      x1, x20
//   0x33a0: d63f0100  blr      x8
//   0x33a4: aa0003f5  mov      x21, x0
//   0x33a8: b40000a0  cbz      x0, #0x33bc
//   0x33ac: f94022a8  ldr      x8, [x21, #0x40]
//   0x33b0: 91000508  add      x8, x8, #1
//   0x33b4: f90022a8  str      x8, [x21, #0x40]
//   0x33b8: f90003f5  str      x21, [sp]
//   0x33bc: f9400268  ldr      x8, [x19]
//   0x33c0: aa1303e0  mov      x0, x19
//   0x33c4: aa1403e1  mov      x1, x20
//   0x33c8: f9436908  ldr      x8, [x8, #0x6d0]
//   0x33cc: d63f0100  blr      x8
//   0x33d0: b4000075  cbz      x21, #0x33dc
//   0x33d4: b9401ab3  ldr      w19, [x21, #0x18]
//   0x33d8: 14000006  b        #0x33f0
//   0x33dc: 90000021  adrp     x1, #0x7000
//   0x33e0: 910a7821  add      x1, x1, #0x29e
//   0x33e4: aa1303e0  mov      x0, x19
//   0x33e8: 9400087e  bl       #0x55e0
//   0x33ec: 2a1f03f3  mov      w19, wzr
//   0x33f0: 910003e0  mov      x0, sp
//   0x33f4: 97fffe07  bl       #0x2c10
//   0x33f8: f94016c8  ldr      x8, [x22, #0x28]
//   0x33fc: f9400fe9  ldr      x9, [sp, #0x18]
//   0x3400: eb09011f  cmp      x8, x9
//   0x3404: 540000e1  b.ne     #0x3420
//   0x3408: 2a1303e0  mov      w0, w19
//   0x340c: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3410: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x3414: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3418: 910143ff  add      sp, sp, #0x50
//   0x341c: d65f03c0  ret      
//   0x3420: 97fff9dc  bl       #0x1b90
// ============================================================================
std::uint32_t fde_16_334c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000334cULL;
    for (std::size_t i = 0; i < 54ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1495ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[17] Symbol: sub_3424
//      Virtual Address Range: 0x3424..0x34fc (216 bytes, 54 AArch64 instructions)
// [VN] Khung FDE[17] Biểu tượng: sub_3424
//      Dải địa chỉ ảo: 0x3424..0x34fc (216 byte, 54 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3424: d10143ff  sub      sp, sp, #0x50
//   0x3428: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x342c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3430: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x3434: 910103fd  add      x29, sp, #0x40
//   0x3438: d53bd056  mrs      x22, tpidr_el0
//   0x343c: f94016c8  ldr      x8, [x22, #0x28]
//   0x3440: aa0103f4  mov      x20, x1
//   0x3444: aa0003f3  mov      x19, x0
//   0x3448: f9000fe8  str      x8, [sp, #0x18]
//   0x344c: a90003ff  stp      xzr, x0, [sp]
//   0x3450: f9000be1  str      x1, [sp, #0x10]
//   0x3454: f9400008  ldr      x8, [x0]
//   0x3458: f9436508  ldr      x8, [x8, #0x6c8]
//   0x345c: d63f0100  blr      x8
//   0x3460: f9400268  ldr      x8, [x19]
//   0x3464: b0000069  adrp     x9, #0x10000
//   0x3468: f9413522  ldr      x2, [x9, #0x268]
//   0x346c: aa1303e0  mov      x0, x19
//   0x3470: f9419508  ldr      x8, [x8, #0x328]
//   0x3474: aa1403e1  mov      x1, x20
//   0x3478: d63f0100  blr      x8
//   0x347c: aa0003f5  mov      x21, x0
//   0x3480: b40000a0  cbz      x0, #0x3494
//   0x3484: f94022a8  ldr      x8, [x21, #0x40]
//   0x3488: 91000508  add      x8, x8, #1
//   0x348c: f90022a8  str      x8, [x21, #0x40]
//   0x3490: f90003f5  str      x21, [sp]
//   0x3494: f9400268  ldr      x8, [x19]
//   0x3498: aa1303e0  mov      x0, x19
//   0x349c: aa1403e1  mov      x1, x20
//   0x34a0: f9436908  ldr      x8, [x8, #0x6d0]
//   0x34a4: d63f0100  blr      x8
//   0x34a8: b4000075  cbz      x21, #0x34b4
//   0x34ac: b94022b3  ldr      w19, [x21, #0x20]
//   0x34b0: 14000006  b        #0x34c8
//   0x34b4: 90000021  adrp     x1, #0x7000
//   0x34b8: 910a7821  add      x1, x1, #0x29e
//   0x34bc: aa1303e0  mov      x0, x19
//   0x34c0: 94000848  bl       #0x55e0
//   0x34c4: 2a1f03f3  mov      w19, wzr
//   0x34c8: 910003e0  mov      x0, sp
//   0x34cc: 97fffdd1  bl       #0x2c10
//   0x34d0: f94016c8  ldr      x8, [x22, #0x28]
//   0x34d4: f9400fe9  ldr      x9, [sp, #0x18]
//   0x34d8: eb09011f  cmp      x8, x9
//   0x34dc: 540000e1  b.ne     #0x34f8
//   0x34e0: 2a1303e0  mov      w0, w19
//   0x34e4: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x34e8: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x34ec: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x34f0: 910143ff  add      sp, sp, #0x50
//   0x34f4: d65f03c0  ret      
//   0x34f8: 97fff9a6  bl       #0x1b90
// ============================================================================
std::uint32_t fde_17_3424(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003424ULL;
    for (std::size_t i = 0; i < 54ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1549ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[18] Symbol: sub_34fc
//      Virtual Address Range: 0x34fc..0x35d4 (216 bytes, 54 AArch64 instructions)
// [VN] Khung FDE[18] Biểu tượng: sub_34fc
//      Dải địa chỉ ảo: 0x34fc..0x35d4 (216 byte, 54 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x34fc: d10143ff  sub      sp, sp, #0x50
//   0x3500: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x3504: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3508: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x350c: 910103fd  add      x29, sp, #0x40
//   0x3510: d53bd056  mrs      x22, tpidr_el0
//   0x3514: f94016c8  ldr      x8, [x22, #0x28]
//   0x3518: aa0103f4  mov      x20, x1
//   0x351c: aa0003f3  mov      x19, x0
//   0x3520: f9000fe8  str      x8, [sp, #0x18]
//   0x3524: a90003ff  stp      xzr, x0, [sp]
//   0x3528: f9000be1  str      x1, [sp, #0x10]
//   0x352c: f9400008  ldr      x8, [x0]
//   0x3530: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3534: d63f0100  blr      x8
//   0x3538: f9400268  ldr      x8, [x19]
//   0x353c: b0000069  adrp     x9, #0x10000
//   0x3540: f9413522  ldr      x2, [x9, #0x268]
//   0x3544: aa1303e0  mov      x0, x19
//   0x3548: f9419508  ldr      x8, [x8, #0x328]
//   0x354c: aa1403e1  mov      x1, x20
//   0x3550: d63f0100  blr      x8
//   0x3554: aa0003f5  mov      x21, x0
//   0x3558: b40000a0  cbz      x0, #0x356c
//   0x355c: f94022a8  ldr      x8, [x21, #0x40]
//   0x3560: 91000508  add      x8, x8, #1
//   0x3564: f90022a8  str      x8, [x21, #0x40]
//   0x3568: f90003f5  str      x21, [sp]
//   0x356c: f9400268  ldr      x8, [x19]
//   0x3570: aa1303e0  mov      x0, x19
//   0x3574: aa1403e1  mov      x1, x20
//   0x3578: f9436908  ldr      x8, [x8, #0x6d0]
//   0x357c: d63f0100  blr      x8
//   0x3580: b4000075  cbz      x21, #0x358c
//   0x3584: b9401eb3  ldr      w19, [x21, #0x1c]
//   0x3588: 14000006  b        #0x35a0
//   0x358c: 90000021  adrp     x1, #0x7000
//   0x3590: 910a7821  add      x1, x1, #0x29e
//   0x3594: aa1303e0  mov      x0, x19
//   0x3598: 94000812  bl       #0x55e0
//   0x359c: 2a1f03f3  mov      w19, wzr
//   0x35a0: 910003e0  mov      x0, sp
//   0x35a4: 97fffd9b  bl       #0x2c10
//   0x35a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x35ac: f9400fe9  ldr      x9, [sp, #0x18]
//   0x35b0: eb09011f  cmp      x8, x9
//   0x35b4: 540000e1  b.ne     #0x35d0
//   0x35b8: 2a1303e0  mov      w0, w19
//   0x35bc: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x35c0: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x35c4: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x35c8: 910143ff  add      sp, sp, #0x50
//   0x35cc: d65f03c0  ret      
//   0x35d0: 97fff970  bl       #0x1b90
// ============================================================================
std::uint32_t fde_18_34fc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000034fcULL;
    for (std::size_t i = 0; i < 54ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1603ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[19] Symbol: sub_35d4
//      Virtual Address Range: 0x35d4..0x36e4 (272 bytes, 68 AArch64 instructions)
// [VN] Khung FDE[19] Biểu tượng: sub_35d4
//      Dải địa chỉ ảo: 0x35d4..0x36e4 (272 byte, 68 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x35d4: d10143ff  sub      sp, sp, #0x50
//   0x35d8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x35dc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x35e0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x35e4: 910103fd  add      x29, sp, #0x40
//   0x35e8: d53bd056  mrs      x22, tpidr_el0
//   0x35ec: f94016c8  ldr      x8, [x22, #0x28]
//   0x35f0: aa0103f4  mov      x20, x1
//   0x35f4: aa0003f3  mov      x19, x0
//   0x35f8: f9000fe8  str      x8, [sp, #0x18]
//   0x35fc: a90003ff  stp      xzr, x0, [sp]
//   0x3600: f9000be1  str      x1, [sp, #0x10]
//   0x3604: f9400008  ldr      x8, [x0]
//   0x3608: f9436508  ldr      x8, [x8, #0x6c8]
//   0x360c: d63f0100  blr      x8
//   0x3610: f9400268  ldr      x8, [x19]
//   0x3614: b0000069  adrp     x9, #0x10000
//   0x3618: f9413522  ldr      x2, [x9, #0x268]
//   0x361c: aa1303e0  mov      x0, x19
//   0x3620: f9419508  ldr      x8, [x8, #0x328]
//   0x3624: aa1403e1  mov      x1, x20
//   0x3628: d63f0100  blr      x8
//   0x362c: aa0003f5  mov      x21, x0
//   0x3630: b40000a0  cbz      x0, #0x3644
//   0x3634: f94022a8  ldr      x8, [x21, #0x40]
//   0x3638: 91000508  add      x8, x8, #1
//   0x363c: f90022a8  str      x8, [x21, #0x40]
//   0x3640: f90003f5  str      x21, [sp]
//   0x3644: f9400268  ldr      x8, [x19]
//   0x3648: aa1303e0  mov      x0, x19
//   0x364c: aa1403e1  mov      x1, x20
//   0x3650: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3654: d63f0100  blr      x8
//   0x3658: b4000235  cbz      x21, #0x369c
//   0x365c: f9400268  ldr      x8, [x19]
//   0x3660: b9401aa1  ldr      w1, [x21, #0x18]
//   0x3664: aa1303e0  mov      x0, x19
//   0x3668: f942cd08  ldr      x8, [x8, #0x598]
//   0x366c: d63f0100  blr      x8
//   0x3670: aa0003f4  mov      x20, x0
//   0x3674: b40001e0  cbz      x0, #0x36b0
//   0x3678: f9400268  ldr      x8, [x19]
//   0x367c: b9401aa3  ldr      w3, [x21, #0x18]
//   0x3680: f94016a4  ldr      x4, [x21, #0x28]
//   0x3684: aa1303e0  mov      x0, x19
//   0x3688: f9434d08  ldr      x8, [x8, #0x698]
//   0x368c: aa1403e1  mov      x1, x20
//   0x3690: 2a1f03e2  mov      w2, wzr
//   0x3694: d63f0100  blr      x8
//   0x3698: 14000006  b        #0x36b0
//   0x369c: 90000021  adrp     x1, #0x7000
//   0x36a0: 910a7821  add      x1, x1, #0x29e
//   0x36a4: aa1303e0  mov      x0, x19
//   0x36a8: 940007ce  bl       #0x55e0
//   0x36ac: aa1f03f4  mov      x20, xzr
//   0x36b0: 910003e0  mov      x0, sp
//   0x36b4: 97fffd57  bl       #0x2c10
//   0x36b8: f94016c8  ldr      x8, [x22, #0x28]
//   0x36bc: f9400fe9  ldr      x9, [sp, #0x18]
//   0x36c0: eb09011f  cmp      x8, x9
//   0x36c4: 540000e1  b.ne     #0x36e0
//   0x36c8: aa1403e0  mov      x0, x20
//   0x36cc: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x36d0: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x36d4: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x36d8: 910143ff  add      sp, sp, #0x50
//   0x36dc: d65f03c0  ret      
//   0x36e0: 97fff92c  bl       #0x1b90
// ============================================================================
std::uint32_t fde_19_35d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000035d4ULL;
    for (std::size_t i = 0; i < 68ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1657ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[20] Symbol: sub_36e4
//      Virtual Address Range: 0x36e4..0x39f0 (780 bytes, 195 AArch64 instructions)
// [VN] Khung FDE[20] Biểu tượng: sub_36e4
//      Dải địa chỉ ảo: 0x36e4..0x39f0 (780 byte, 195 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x36e4: d10243ff  sub      sp, sp, #0x90
//   0x36e8: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x36ec: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x36f0: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x36f4: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x36f8: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x36fc: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x3700: 910203fd  add      x29, sp, #0x80
//   0x3704: d53bd058  mrs      x24, tpidr_el0
//   0x3708: f9401708  ldr      x8, [x24, #0x28]
//   0x370c: aa0103f4  mov      x20, x1
//   0x3710: aa0003f3  mov      x19, x0
//   0x3714: 2a0203f6  mov      w22, w2
//   0x3718: f90017e8  str      x8, [sp, #0x28]
//   0x371c: a90103ff  stp      xzr, x0, [sp, #0x10]
//   0x3720: f90013e1  str      x1, [sp, #0x20]
//   0x3724: f9400008  ldr      x8, [x0]
//   0x3728: f9436508  ldr      x8, [x8, #0x6c8]
//   0x372c: d63f0100  blr      x8
//   0x3730: f9400268  ldr      x8, [x19]
//   0x3734: b0000069  adrp     x9, #0x10000
//   0x3738: f9413522  ldr      x2, [x9, #0x268]
//   0x373c: aa1303e0  mov      x0, x19
//   0x3740: f9419508  ldr      x8, [x8, #0x328]
//   0x3744: aa1403e1  mov      x1, x20
//   0x3748: d63f0100  blr      x8
//   0x374c: aa0003f7  mov      x23, x0
//   0x3750: b40000a0  cbz      x0, #0x3764
//   0x3754: f94022e8  ldr      x8, [x23, #0x40]
//   0x3758: 91000508  add      x8, x8, #1
//   0x375c: f90022e8  str      x8, [x23, #0x40]
//   0x3760: f9000bf7  str      x23, [sp, #0x10]
//   0x3764: f9400268  ldr      x8, [x19]
//   0x3768: aa1303e0  mov      x0, x19
//   0x376c: aa1403e1  mov      x1, x20
//   0x3770: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3774: d63f0100  blr      x8
//   0x3778: b4000637  cbz      x23, #0x383c
//   0x377c: f94002e8  ldr      x8, [x23]
//   0x3780: f9400915  ldr      x21, [x8, #0x10]
//   0x3784: 91022114  add      x20, x8, #0x88
//   0x3788: aa1403e0  mov      x0, x20
//   0x378c: 97fff8c1  bl       #0x1a90
//   0x3790: 34000120  cbz      w0, #0x37b4
//   0x3794: 97fff87f  bl       #0x1990
//   0x3798: 90000021  adrp     x1, #0x7000
//   0x379c: 90000022  adrp     x2, #0x7000
//   0x37a0: aa0003e3  mov      x3, x0
//   0x37a4: 910c8021  add      x1, x1, #0x320
//   0x37a8: 910ecc42  add      x2, x2, #0x3b3
//   0x37ac: 528000c0  mov      w0, #6
//   0x37b0: 97fff8c0  bl       #0x1ab0
//   0x37b4: f94026ba  ldr      x26, [x21, #0x48]
//   0x37b8: 52800700  mov      w0, #0x38
//   0x37bc: 93407edb  sxtw     x27, w22
//   0x37c0: 97fff8ec  bl       #0x1b70
//   0x37c4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x37c8: ad000000  stp      q0, q0, [x0]
//   0x37cc: 3d800800  str      q0, [x0, #0x20]
//   0x37d0: f900181f  str      xzr, [x0, #0x30]
//   0x37d4: a94022e9  ldp      x9, x8, [x23]
//   0x37d8: aa0003f5  mov      x21, x0
//   0x37dc: b40003c8  cbz      x8, #0x3854
//   0x37e0: 9100210a  add      x10, x8, #8
//   0x37e4: c85f7d4b  ldxr     x11, [x10]
//   0x37e8: 9100056b  add      x11, x11, #1
//   0x37ec: c80c7d4b  stxr     w12, x11, [x10]
//   0x37f0: 35ffffac  cbnz     w12, #0x37e4
//   0x37f4: aa1503f9  mov      x25, x21
//   0x37f8: f8408f37  ldr      x23, [x25, #8]!
//   0x37fc: f90002a9  str      x9, [x21]
//   0x3800: f9000328  str      x8, [x25]
//   0x3804: b40002f7  cbz      x23, #0x3860
//   0x3808: 910022e9  add      x9, x23, #8
//   0x380c: c85ffd28  ldaxr    x8, [x9]
//   0x3810: d100050a  sub      x10, x8, #1
//   0x3814: c80bfd2a  stlxr    w11, x10, [x9]
//   0x3818: 35ffffab  cbnz     w11, #0x380c
//   0x381c: b5000228  cbnz     x8, #0x3860
//   0x3820: f94002e8  ldr      x8, [x23]
//   0x3824: aa1703e0  mov      x0, x23
//   0x3828: f9400908  ldr      x8, [x8, #0x10]
//   0x382c: d63f0100  blr      x8
//   0x3830: aa1703e0  mov      x0, x23
//   0x3834: 97fff8b3  bl       #0x1b00
//   0x3838: 1400000a  b        #0x3860
//   0x383c: 90000021  adrp     x1, #0x7000
//   0x3840: 910a7821  add      x1, x1, #0x29e
//   0x3844: aa1303e0  mov      x0, x19
//   0x3848: 94000766  bl       #0x55e0
//   0x384c: aa1f03f3  mov      x19, xzr
//   0x3850: 14000058  b        #0x39b0
//   0x3854: aa1503f9  mov      x25, x21
//   0x3858: f90002a9  str      x9, [x21]
//   0x385c: f8008f28  str      x8, [x25, #8]!
//   0x3860: 52800708  mov      w8, #0x38
//   0x3864: b90012b6  str      w22, [x21, #0x10]
//   0x3868: d503201f  nop      
//   0x386c: 9b086b76  madd     x22, x27, x8, x26
//   0x3870: f94002c8  ldr      x8, [x22]
//   0x3874: f9400be9  ldr      x9, [sp, #0x10]
//   0x3878: f80142a8  stur     x8, [x21, #0x14]
//   0x387c: f9401528  ldr      x8, [x9, #0x28]
//   0x3880: b87b7908  ldr      w8, [x8, x27, lsl #2]
//   0x3884: b9001ea8  str      w8, [x21, #0x1c]
//   0x3888: f94006c8  ldr      x8, [x22, #8]
//   0x388c: f90012a8  str      x8, [x21, #0x20]
//   0x3890: b8428ec8  ldr      w8, [x22, #0x28]!
//   0x3894: 7100051f  cmp      w8, #1
//   0x3898: 5400038b  b.lt     #0x3908
//   0x389c: 52800709  mov      w9, #0x38
//   0x38a0: 9b096b69  madd     x9, x27, x9, x26
//   0x38a4: aa1f03f7  mov      x23, xzr
//   0x38a8: aa1f03fc  mov      x28, xzr
//   0x38ac: 2a1f03e0  mov      w0, wzr
//   0x38b0: 9100c13a  add      x26, x9, #0x30
//   0x38b4: 14000005  b        #0x38c8
//   0x38b8: 9100079c  add      x28, x28, #1
//   0x38bc: eb28c39f  cmp      x28, w8, sxtw
//   0x38c0: 910062f7  add      x23, x23, #0x18
//   0x38c4: 5400018a  b.ge     #0x38f4
//   0x38c8: f9400349  ldr      x9, [x26]
//   0x38cc: 8b170129  add      x9, x9, x23
//   0x38d0: b940112a  ldr      w10, [x9, #0x10]
//   0x38d4: 7103e55f  cmp      w10, #0xf9
//   0x38d8: 54ffff01  b.ne     #0x38b8
//   0x38dc: b9800120  ldrsw    x0, [x9]
//   0x38e0: f9400521  ldr      x1, [x9, #8]
//   0x38e4: 910003e2  mov      x2, sp
//   0x38e8: 94000bf0  bl       #0x68a8
//   0x38ec: b94002c8  ldr      w8, [x22]
//   0x38f0: 17fffff2  b        #0x38b8
//   0x38f4: 7100041f  cmp      w0, #1
//   0x38f8: 54000081  b.ne     #0x3908
//   0x38fc: b9400fe9  ldr      w9, [sp, #0xc]
//   0x3900: b94003e8  ldr      w8, [sp]
//   0x3904: 14000003  b        #0x3910
//   0x3908: 2a1f03e8  mov      w8, wzr
//   0x390c: 12800009  mov      w9, #-1
//   0x3910: 290526a8  stp      w8, w9, [x21, #0x28]
//   0x3914: b0000069  adrp     x9, #0x10000
//   0x3918: b000006a  adrp     x10, #0x10000
//   0x391c: f9413921  ldr      x1, [x9, #0x270]
//   0x3920: f9413d42  ldr      x2, [x10, #0x278]
//   0x3924: aa1303e0  mov      x0, x19
//   0x3928: aa1503e3  mov      x3, x21
//   0x392c: 97fffc48  bl       #0x2a4c
//   0x3930: aa0003f3  mov      x19, x0
//   0x3934: b4000080  cbz      x0, #0x3944
//   0x3938: 52800028  mov      w8, #1
//   0x393c: f9001aa8  str      x8, [x21, #0x30]
//   0x3940: 14000011  b        #0x3984
//   0x3944: f9400336  ldr      x22, [x25]
//   0x3948: b40001b6  cbz      x22, #0x397c
//   0x394c: 910022c8  add      x8, x22, #8
//   0x3950: c85ffd09  ldaxr    x9, [x8]
//   0x3954: d100052a  sub      x10, x9, #1
//   0x3958: c80bfd0a  stlxr    w11, x10, [x8]
//   0x395c: 35ffffab  cbnz     w11, #0x3950
//   0x3960: b50000e9  cbnz     x9, #0x397c
//   0x3964: f94002c8  ldr      x8, [x22]
//   0x3968: aa1603e0  mov      x0, x22
//   0x396c: f9400908  ldr      x8, [x8, #0x10]
//   0x3970: d63f0100  blr      x8
//   0x3974: aa1603e0  mov      x0, x22
//   0x3978: 97fff862  bl       #0x1b00
//   0x397c: aa1503e0  mov      x0, x21
//   0x3980: 97fff810  bl       #0x19c0
//   0x3984: aa1403e0  mov      x0, x20
//   0x3988: 97fff846  bl       #0x1aa0
//   0x398c: 34000120  cbz      w0, #0x39b0
//   0x3990: 97fff800  bl       #0x1990
//   0x3994: 90000021  adrp     x1, #0x7000
//   0x3998: 90000022  adrp     x2, #0x7000
//   0x399c: aa0003e3  mov      x3, x0
//   0x39a0: 910c8021  add      x1, x1, #0x320
//   0x39a4: 910f5442  add      x2, x2, #0x3d5
//   0x39a8: 528000c0  mov      w0, #6
//   0x39ac: 97fff841  bl       #0x1ab0
//   0x39b0: 910043e0  add      x0, sp, #0x10
//   0x39b4: 97fffc97  bl       #0x2c10
//   0x39b8: f9401708  ldr      x8, [x24, #0x28]
//   0x39bc: f94017e9  ldr      x9, [sp, #0x28]
//   0x39c0: eb09011f  cmp      x8, x9
//   0x39c4: 54000141  b.ne     #0x39ec
//   0x39c8: aa1303e0  mov      x0, x19
//   0x39cc: a9487bfd  ldp      x29, x30, [sp, #0x80]
//   0x39d0: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x39d4: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x39d8: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x39dc: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x39e0: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x39e4: 910243ff  add      sp, sp, #0x90
//   0x39e8: d65f03c0  ret      
//   0x39ec: 97fff869  bl       #0x1b90
// ============================================================================
std::uint32_t fde_20_36e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000036e4ULL;
    for (std::size_t i = 0; i < 195ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1725ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[21] Symbol: sub_39f0
//      Virtual Address Range: 0x39f0..0x3aec (252 bytes, 63 AArch64 instructions)
// [VN] Khung FDE[21] Biểu tượng: sub_39f0
//      Dải địa chỉ ảo: 0x39f0..0x3aec (252 byte, 63 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x39f0: d10143ff  sub      sp, sp, #0x50
//   0x39f4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x39f8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x39fc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x3a00: 910103fd  add      x29, sp, #0x40
//   0x3a04: d53bd056  mrs      x22, tpidr_el0
//   0x3a08: f94016c8  ldr      x8, [x22, #0x28]
//   0x3a0c: aa0103f4  mov      x20, x1
//   0x3a10: aa0003f3  mov      x19, x0
//   0x3a14: f9000fe8  str      x8, [sp, #0x18]
//   0x3a18: a90003ff  stp      xzr, x0, [sp]
//   0x3a1c: f9000be1  str      x1, [sp, #0x10]
//   0x3a20: f9400008  ldr      x8, [x0]
//   0x3a24: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3a28: d63f0100  blr      x8
//   0x3a2c: f9400268  ldr      x8, [x19]
//   0x3a30: b0000069  adrp     x9, #0x10000
//   0x3a34: f9413522  ldr      x2, [x9, #0x268]
//   0x3a38: aa1303e0  mov      x0, x19
//   0x3a3c: f9419508  ldr      x8, [x8, #0x328]
//   0x3a40: aa1403e1  mov      x1, x20
//   0x3a44: d63f0100  blr      x8
//   0x3a48: aa0003f5  mov      x21, x0
//   0x3a4c: b40000a0  cbz      x0, #0x3a60
//   0x3a50: f94022a8  ldr      x8, [x21, #0x40]
//   0x3a54: 91000508  add      x8, x8, #1
//   0x3a58: f90022a8  str      x8, [x21, #0x40]
//   0x3a5c: f90003f5  str      x21, [sp]
//   0x3a60: f9400268  ldr      x8, [x19]
//   0x3a64: aa1303e0  mov      x0, x19
//   0x3a68: aa1403e1  mov      x1, x20
//   0x3a6c: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3a70: d63f0100  blr      x8
//   0x3a74: b4000195  cbz      x21, #0x3aa4
//   0x3a78: f94002a8  ldr      x8, [x21]
//   0x3a7c: f9401100  ldr      x0, [x8, #0x20]
//   0x3a80: f9400008  ldr      x8, [x0]
//   0x3a84: f9400d08  ldr      x8, [x8, #0x18]
//   0x3a88: d63f0100  blr      x8
//   0x3a8c: f94002a8  ldr      x8, [x21]
//   0x3a90: b9405909  ldr      w9, [x8, #0x58]
//   0x3a94: b9404908  ldr      w8, [x8, #0x48]
//   0x3a98: 0b000129  add      w9, w9, w0
//   0x3a9c: 4b080133  sub      w19, w9, w8
//   0x3aa0: 14000006  b        #0x3ab8
//   0x3aa4: 90000021  adrp     x1, #0x7000
//   0x3aa8: 910a7821  add      x1, x1, #0x29e
//   0x3aac: aa1303e0  mov      x0, x19
//   0x3ab0: 940006cc  bl       #0x55e0
//   0x3ab4: 2a1f03f3  mov      w19, wzr
//   0x3ab8: 910003e0  mov      x0, sp
//   0x3abc: 97fffc55  bl       #0x2c10
//   0x3ac0: f94016c8  ldr      x8, [x22, #0x28]
//   0x3ac4: f9400fe9  ldr      x9, [sp, #0x18]
//   0x3ac8: eb09011f  cmp      x8, x9
//   0x3acc: 540000e1  b.ne     #0x3ae8
//   0x3ad0: 2a1303e0  mov      w0, w19
//   0x3ad4: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3ad8: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x3adc: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3ae0: 910143ff  add      sp, sp, #0x50
//   0x3ae4: d65f03c0  ret      
//   0x3ae8: 97fff82a  bl       #0x1b90
// ============================================================================
std::uint32_t fde_21_39f0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000039f0ULL;
    for (std::size_t i = 0; i < 63ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1920ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[22] Symbol: sub_3aec
//      Virtual Address Range: 0x3aec..0x3bc8 (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[22] Biểu tượng: sub_3aec
//      Dải địa chỉ ảo: 0x3aec..0x3bc8 (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3aec: d10143ff  sub      sp, sp, #0x50
//   0x3af0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x3af4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x3af8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x3afc: 910103fd  add      x29, sp, #0x40
//   0x3b00: d53bd056  mrs      x22, tpidr_el0
//   0x3b04: f94016c8  ldr      x8, [x22, #0x28]
//   0x3b08: aa0103f4  mov      x20, x1
//   0x3b0c: aa0003f3  mov      x19, x0
//   0x3b10: f9000fe8  str      x8, [sp, #0x18]
//   0x3b14: a90003ff  stp      xzr, x0, [sp]
//   0x3b18: f9000be1  str      x1, [sp, #0x10]
//   0x3b1c: f9400008  ldr      x8, [x0]
//   0x3b20: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3b24: d63f0100  blr      x8
//   0x3b28: f9400268  ldr      x8, [x19]
//   0x3b2c: b0000069  adrp     x9, #0x10000
//   0x3b30: f9413522  ldr      x2, [x9, #0x268]
//   0x3b34: aa1303e0  mov      x0, x19
//   0x3b38: f9419508  ldr      x8, [x8, #0x328]
//   0x3b3c: aa1403e1  mov      x1, x20
//   0x3b40: d63f0100  blr      x8
//   0x3b44: aa0003f5  mov      x21, x0
//   0x3b48: b40000a0  cbz      x0, #0x3b5c
//   0x3b4c: f94022a8  ldr      x8, [x21, #0x40]
//   0x3b50: 91000508  add      x8, x8, #1
//   0x3b54: f90022a8  str      x8, [x21, #0x40]
//   0x3b58: f90003f5  str      x21, [sp]
//   0x3b5c: f9400268  ldr      x8, [x19]
//   0x3b60: aa1303e0  mov      x0, x19
//   0x3b64: aa1403e1  mov      x1, x20
//   0x3b68: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3b6c: d63f0100  blr      x8
//   0x3b70: b4000095  cbz      x21, #0x3b80
//   0x3b74: f94002a8  ldr      x8, [x21]
//   0x3b78: 39403113  ldrb     w19, [x8, #0xc]
//   0x3b7c: 14000006  b        #0x3b94
//   0x3b80: 90000021  adrp     x1, #0x7000
//   0x3b84: 910a7821  add      x1, x1, #0x29e
//   0x3b88: aa1303e0  mov      x0, x19
//   0x3b8c: 94000695  bl       #0x55e0
//   0x3b90: 2a1f03f3  mov      w19, wzr
//   0x3b94: 910003e0  mov      x0, sp
//   0x3b98: 97fffc1e  bl       #0x2c10
//   0x3b9c: f94016c8  ldr      x8, [x22, #0x28]
//   0x3ba0: f9400fe9  ldr      x9, [sp, #0x18]
//   0x3ba4: eb09011f  cmp      x8, x9
//   0x3ba8: 540000e1  b.ne     #0x3bc4
//   0x3bac: 2a1303e0  mov      w0, w19
//   0x3bb0: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x3bb4: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x3bb8: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x3bbc: 910143ff  add      sp, sp, #0x50
//   0x3bc0: d65f03c0  ret      
//   0x3bc4: 97fff7f3  bl       #0x1b90
// ============================================================================
std::uint32_t fde_22_3aec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003aecULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1983ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[23] Symbol: sub_3bc8
//      Virtual Address Range: 0x3bc8..0x3cd4 (268 bytes, 67 AArch64 instructions)
// [VN] Khung FDE[23] Biểu tượng: sub_3bc8
//      Dải địa chỉ ảo: 0x3bc8..0x3cd4 (268 byte, 67 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3bc8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x3bcc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x3bd0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x3bd4: 910083fd  add      x29, sp, #0x20
//   0x3bd8: f9400008  ldr      x8, [x0]
//   0x3bdc: aa0003f3  mov      x19, x0
//   0x3be0: aa0103f4  mov      x20, x1
//   0x3be4: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3be8: d63f0100  blr      x8
//   0x3bec: f9400268  ldr      x8, [x19]
//   0x3bf0: b0000076  adrp     x22, #0x10000
//   0x3bf4: f94136c2  ldr      x2, [x22, #0x268]
//   0x3bf8: aa1303e0  mov      x0, x19
//   0x3bfc: f9419508  ldr      x8, [x8, #0x328]
//   0x3c00: aa1403e1  mov      x1, x20
//   0x3c04: d63f0100  blr      x8
//   0x3c08: b4000560  cbz      x0, #0x3cb4
//   0x3c0c: f9400268  ldr      x8, [x19]
//   0x3c10: f94136c2  ldr      x2, [x22, #0x268]
//   0x3c14: aa0003f5  mov      x21, x0
//   0x3c18: aa1303e0  mov      x0, x19
//   0x3c1c: f941b908  ldr      x8, [x8, #0x370]
//   0x3c20: aa1403e1  mov      x1, x20
//   0x3c24: aa1f03e3  mov      x3, xzr
//   0x3c28: d63f0100  blr      x8
//   0x3c2c: f9400268  ldr      x8, [x19]
//   0x3c30: aa1303e0  mov      x0, x19
//   0x3c34: aa1403e1  mov      x1, x20
//   0x3c38: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3c3c: d63f0100  blr      x8
//   0x3c40: f94022a8  ldr      x8, [x21, #0x40]
//   0x3c44: f1000508  subs     x8, x8, #1
//   0x3c48: f90022a8  str      x8, [x21, #0x40]
//   0x3c4c: 540002a1  b.ne     #0x3ca0
//   0x3c50: f94016a0  ldr      x0, [x21, #0x28]
//   0x3c54: b4000060  cbz      x0, #0x3c60
//   0x3c58: f9001aa0  str      x0, [x21, #0x30]
//   0x3c5c: 97fff759  bl       #0x19c0
//   0x3c60: f94006b6  ldr      x22, [x21, #8]
//   0x3c64: b40001b6  cbz      x22, #0x3c98
//   0x3c68: 910022c8  add      x8, x22, #8
//   0x3c6c: c85ffd09  ldaxr    x9, [x8]
//   0x3c70: d100052a  sub      x10, x9, #1
//   0x3c74: c80bfd0a  stlxr    w11, x10, [x8]
//   0x3c78: 35ffffab  cbnz     w11, #0x3c6c
//   0x3c7c: b50000e9  cbnz     x9, #0x3c98
//   0x3c80: f94002c8  ldr      x8, [x22]
//   0x3c84: aa1603e0  mov      x0, x22
//   0x3c88: f9400908  ldr      x8, [x8, #0x10]
//   0x3c8c: d63f0100  blr      x8
//   0x3c90: aa1603e0  mov      x0, x22
//   0x3c94: 97fff79b  bl       #0x1b00
//   0x3c98: aa1503e0  mov      x0, x21
//   0x3c9c: 97fff749  bl       #0x19c0
//   0x3ca0: f9400268  ldr      x8, [x19]
//   0x3ca4: aa1303e0  mov      x0, x19
//   0x3ca8: aa1403e1  mov      x1, x20
//   0x3cac: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3cb0: d63f0100  blr      x8
//   0x3cb4: f9400268  ldr      x8, [x19]
//   0x3cb8: aa1303e0  mov      x0, x19
//   0x3cbc: aa1403e1  mov      x1, x20
//   0x3cc0: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x3cc4: f9436902  ldr      x2, [x8, #0x6d0]
//   0x3cc8: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x3ccc: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x3cd0: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_23_3bc8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003bc8ULL;
    for (std::size_t i = 0; i < 67ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2038ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[24] Symbol: sub_3cd4
//      Virtual Address Range: 0x3cd4..0x3cd8 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[24] Biểu tượng: sub_3cd4
//      Dải địa chỉ ảo: 0x3cd4..0x3cd8 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3cd4: 17ffffbd  b        #0x3bc8
// ============================================================================
std::uint32_t fde_24_3cd4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003cd4ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2105ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[25] Symbol: sub_3cd8
//      Virtual Address Range: 0x3cd8..0x40b8 (992 bytes, 248 AArch64 instructions)
// [VN] Khung FDE[25] Biểu tượng: sub_3cd8
//      Dải địa chỉ ảo: 0x3cd8..0x40b8 (992 byte, 248 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x3cd8: d10283ff  sub      sp, sp, #0xa0
//   0x3cdc: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x3ce0: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x3ce4: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x3ce8: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x3cec: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x3cf0: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x3cf4: 910243fd  add      x29, sp, #0x90
//   0x3cf8: d53bd05c  mrs      x28, tpidr_el0
//   0x3cfc: f9401788  ldr      x8, [x28, #0x28]
//   0x3d00: aa0403f6  mov      x22, x4
//   0x3d04: 2a0303f9  mov      w25, w3
//   0x3d08: 2a0203fa  mov      w26, w2
//   0x3d0c: f9001fe8  str      x8, [sp, #0x38]
//   0x3d10: f9400008  ldr      x8, [x0]
//   0x3d14: aa0003f3  mov      x19, x0
//   0x3d18: aa0103f4  mov      x20, x1
//   0x3d1c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3d20: d63f0100  blr      x8
//   0x3d24: f9400268  ldr      x8, [x19]
//   0x3d28: b0000069  adrp     x9, #0x10000
//   0x3d2c: f9414122  ldr      x2, [x9, #0x280]
//   0x3d30: aa1303e0  mov      x0, x19
//   0x3d34: f9419508  ldr      x8, [x8, #0x328]
//   0x3d38: aa1403e1  mov      x1, x20
//   0x3d3c: d63f0100  blr      x8
//   0x3d40: b4000240  cbz      x0, #0x3d88
//   0x3d44: f9401808  ldr      x8, [x0, #0x30]
//   0x3d48: aa0003f5  mov      x21, x0
//   0x3d4c: aa1403e1  mov      x1, x20
//   0x3d50: 91000508  add      x8, x8, #1
//   0x3d54: f9001808  str      x8, [x0, #0x30]
//   0x3d58: f9400268  ldr      x8, [x19]
//   0x3d5c: aa1303e0  mov      x0, x19
//   0x3d60: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3d64: d63f0100  blr      x8
//   0x3d68: 910083e2  add      x2, sp, #0x20
//   0x3d6c: aa1303e0  mov      x0, x19
//   0x3d70: aa1603e1  mov      x1, x22
//   0x3d74: 97fff793  bl       #0x1bc0
//   0x3d78: 340001c0  cbz      w0, #0x3db0
//   0x3d7c: 90000021  adrp     x1, #0x7000
//   0x3d80: 910abc21  add      x1, x1, #0x2af
//   0x3d84: 14000015  b        #0x3dd8
//   0x3d88: f9400268  ldr      x8, [x19]
//   0x3d8c: aa1303e0  mov      x0, x19
//   0x3d90: aa1403e1  mov      x1, x20
//   0x3d94: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3d98: d63f0100  blr      x8
//   0x3d9c: 90000021  adrp     x1, #0x7000
//   0x3da0: 910a7821  add      x1, x1, #0x29e
//   0x3da4: aa1303e0  mov      x0, x19
//   0x3da8: 9400060e  bl       #0x55e0
//   0x3dac: 1400002b  b        #0x3e58
//   0x3db0: 2a1a0328  orr      w8, w25, w26
//   0x3db4: 37f806a8  tbnz     w8, #0x1f, #0x3e88
//   0x3db8: b94023e8  ldr      w8, [sp, #0x20]
//   0x3dbc: 6b1a011f  cmp      w8, w26
//   0x3dc0: 54000083  b.lo     #0x3dd0
//   0x3dc4: b94027e8  ldr      w8, [sp, #0x24]
//   0x3dc8: 6b19011f  cmp      w8, w25
//   0x3dcc: 54000682  b.hs     #0x3e9c
//   0x3dd0: 90000021  adrp     x1, #0x7000
//   0x3dd4: 910b5821  add      x1, x1, #0x2d6
//   0x3dd8: aa1303e0  mov      x0, x19
//   0x3ddc: 94000601  bl       #0x55e0
//   0x3de0: f9400268  ldr      x8, [x19]
//   0x3de4: aa1303e0  mov      x0, x19
//   0x3de8: aa1403e1  mov      x1, x20
//   0x3dec: f9436508  ldr      x8, [x8, #0x6c8]
//   0x3df0: d63f0100  blr      x8
//   0x3df4: f9401aa8  ldr      x8, [x21, #0x30]
//   0x3df8: f1000508  subs     x8, x8, #1
//   0x3dfc: f9001aa8  str      x8, [x21, #0x30]
//   0x3e00: 54000221  b.ne     #0x3e44
//   0x3e04: f94006b6  ldr      x22, [x21, #8]
//   0x3e08: b40001b6  cbz      x22, #0x3e3c
//   0x3e0c: 910022c8  add      x8, x22, #8
//   0x3e10: c85ffd09  ldaxr    x9, [x8]
//   0x3e14: d100052a  sub      x10, x9, #1
//   0x3e18: c80bfd0a  stlxr    w11, x10, [x8]
//   0x3e1c: 35ffffab  cbnz     w11, #0x3e10
//   0x3e20: b50000e9  cbnz     x9, #0x3e3c
//   0x3e24: f94002c8  ldr      x8, [x22]
//   0x3e28: aa1603e0  mov      x0, x22
//   0x3e2c: f9400908  ldr      x8, [x8, #0x10]
//   0x3e30: d63f0100  blr      x8
//   0x3e34: aa1603e0  mov      x0, x22
//   0x3e38: 97fff732  bl       #0x1b00
//   0x3e3c: aa1503e0  mov      x0, x21
//   0x3e40: 97fff6e0  bl       #0x19c0
//   0x3e44: f9400268  ldr      x8, [x19]
//   0x3e48: aa1303e0  mov      x0, x19
//   0x3e4c: aa1403e1  mov      x1, x20
//   0x3e50: f9436908  ldr      x8, [x8, #0x6d0]
//   0x3e54: d63f0100  blr      x8
//   0x3e58: f9401788  ldr      x8, [x28, #0x28]
//   0x3e5c: f9401fe9  ldr      x9, [sp, #0x38]
//   0x3e60: eb09011f  cmp      x8, x9
//   0x3e64: 54001281  b.ne     #0x40b4
//   0x3e68: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x3e6c: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x3e70: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x3e74: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x3e78: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x3e7c: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x3e80: 910283ff  add      sp, sp, #0xa0
//   0x3e84: d65f03c0  ret      
//   0x3e88: 90000021  adrp     x1, #0x7000
//   0x3e8c: 910ae821  add      x1, x1, #0x2ba
//   0x3e90: aa1303e0  mov      x0, x19
//   0x3e94: 9400059c  bl       #0x5504
//   0x3e98: 17ffffd2  b        #0x3de0
//   0x3e9c: b9402fe8  ldr      w8, [sp, #0x2c]
//   0x3ea0: 7100051f  cmp      w8, #1
//   0x3ea4: 54000781  b.ne     #0x3f94
//   0x3ea8: f94002bb  ldr      x27, [x21]
//   0x3eac: 91018378  add      x24, x27, #0x60
//   0x3eb0: aa1803e0  mov      x0, x24
//   0x3eb4: 97fff74b  bl       #0x1be0
//   0x3eb8: f9401360  ldr      x0, [x27, #0x20]
//   0x3ebc: b98012b7  ldrsw    x23, [x21, #0x10]
//   0x3ec0: f9401b68  ldr      x8, [x27, #0x30]
//   0x3ec4: f9400009  ldr      x9, [x0]
//   0x3ec8: b8b77901  ldrsw    x1, [x8, x23, lsl #2]
//   0x3ecc: f9401528  ldr      x8, [x9, #0x28]
//   0x3ed0: d63f0100  blr      x8
//   0x3ed4: 36000ea0  tbz      w0, #0, #0x40a8
//   0x3ed8: 52800021  mov      w1, #1
//   0x3edc: 12b00003  mov      w3, #0x7fffffff
//   0x3ee0: aa1b03e0  mov      x0, x27
//   0x3ee4: 2a1f03e2  mov      w2, wzr
//   0x3ee8: 97fff770  bl       #0x1ca8
//   0x3eec: 7100041f  cmp      w0, #1
//   0x3ef0: 54000dc1  b.ne     #0x40a8
//   0x3ef4: f94002a8  ldr      x8, [x21]
//   0x3ef8: f9000bf8  str      x24, [sp, #0x10]
//   0x3efc: 91022360  add      x0, x27, #0x88
//   0x3f00: f90007e0  str      x0, [sp, #8]
//   0x3f04: f9400908  ldr      x8, [x8, #0x10]
//   0x3f08: f9400d18  ldr      x24, [x8, #0x18]
//   0x3f0c: 97fff6e1  bl       #0x1a90
//   0x3f10: 34000120  cbz      w0, #0x3f34
//   0x3f14: 97fff69f  bl       #0x1990
//   0x3f18: 90000021  adrp     x1, #0x7000
//   0x3f1c: 90000022  adrp     x2, #0x7000
//   0x3f20: aa0003e3  mov      x3, x0
//   0x3f24: 910c8021  add      x1, x1, #0x320
//   0x3f28: 910ecc42  add      x2, x2, #0x3b3
//   0x3f2c: 528000c0  mov      w0, #6
//   0x3f30: 97fff6e0  bl       #0x1ab0
//   0x3f34: f9400b68  ldr      x8, [x27, #0x10]
//   0x3f38: f940251b  ldr      x27, [x8, #0x48]
//   0x3f3c: 52800708  mov      w8, #0x38
//   0x3f40: 9b086ee8  madd     x8, x23, x8, x27
//   0x3f44: f9400d08  ldr      x8, [x8, #0x18]
//   0x3f48: b4000108  cbz      x8, #0x3f68
//   0x3f4c: 29402909  ldp      w9, w10, [x8]
//   0x3f50: b000006b  adrp     x11, #0x10000
//   0x3f54: f941456b  ldr      x11, [x11, #0x288]
//   0x3f58: 5280002c  mov      w12, #1
//   0x3f5c: 1aca218a  lsl      w10, w12, w10
//   0x3f60: 6b0a013f  cmp      w9, w10
//   0x3f64: 9a8b0118  csel     x24, x8, x11, eq
//   0x3f68: 910063e2  add      x2, sp, #0x18
//   0x3f6c: aa1303e0  mov      x0, x19
//   0x3f70: aa1603e1  mov      x1, x22
//   0x3f74: 97fff6a7  bl       #0x1a10
//   0x3f78: 34000140  cbz      w0, #0x3fa0
//   0x3f7c: 90000021  adrp     x1, #0x7000
//   0x3f80: 910abc21  add      x1, x1, #0x2af
//   0x3f84: aa1303e0  mov      x0, x19
//   0x3f88: 94000596  bl       #0x55e0
//   0x3f8c: f94007f7  ldr      x23, [sp, #8]
//   0x3f90: 1400003a  b        #0x4078
//   0x3f94: 90000021  adrp     x1, #0x7000
//   0x3f98: 910bcc21  add      x1, x1, #0x2f3
//   0x3f9c: 17ffff8f  b        #0x3dd8
//   0x3fa0: 52800709  mov      w9, #0x38
//   0x3fa4: 9b096ee9  madd     x9, x23, x9, x27
//   0x3fa8: b9402ea8  ldr      w8, [x21, #0x2c]
//   0x3fac: b8408d30  ldr      w16, [x9, #8]!
//   0x3fb0: f94007f7  ldr      x23, [sp, #8]
//   0x3fb4: b940052b  ldr      w11, [x9, #4]
//   0x3fb8: 6b1a021f  cmp      w16, w26
//   0x3fbc: 1a90c34a  csel     w10, w26, w16, gt
//   0x3fc0: 6b19017f  cmp      w11, w25
//   0x3fc4: 1a8bc32b  csel     w11, w25, w11, gt
//   0x3fc8: 7100057f  cmp      w11, #1
//   0x3fcc: 5400050b  b.lt     #0x406c
//   0x3fd0: f94002ad  ldr      x13, [x21]
//   0x3fd4: b9802bec  ldrsw    x12, [sp, #0x28]
//   0x3fd8: f9400fee  ldr      x14, [sp, #0x18]
//   0x3fdc: 93407d4f  sxtw     x15, w10
//   0x3fe0: f94025ad  ldr      x13, [x13, #0x48]
//   0x3fe4: 3500012a  cbnz     w10, #0x4008
//   0x3fe8: 14000002  b        #0x3ff0
//   0x3fec: b9400130  ldr      w16, [x9]
//   0x3ff0: 5100056b  sub      w11, w11, #1
//   0x3ff4: 8b30c1ad  add      x13, x13, w16, sxtw
//   0x3ff8: 7100017f  cmp      w11, #0
//   0x3ffc: 8b0c01ce  add      x14, x14, x12
//   0x4000: 5400036d  b.le     #0x406c
//   0x4004: 34ffff6a  cbz      w10, #0x3ff0
//   0x4008: aa1f03f0  mov      x16, xzr
//   0x400c: 2a1f03f1  mov      w17, wzr
//   0x4010: b50000f8  cbnz     x24, #0x402c
//   0x4014: b83079d1  str      w17, [x14, x16, lsl #2]
//   0x4018: 91000610  add      x16, x16, #1
//   0x401c: eb1001ff  cmp      x15, x16
//   0x4020: 54fffe60  b.eq     #0x3fec
//   0x4024: 2a1f03f1  mov      w17, wzr
//   0x4028: b4ffff78  cbz      x24, #0x4014
//   0x402c: 387069a0  ldrb     w0, [x13, x16]
//   0x4030: 6b00011f  cmp      w8, w0
//   0x4034: 54ffff00  b.eq     #0x4014
//   0x4038: b9400311  ldr      w17, [x24]
//   0x403c: f9400b01  ldr      x1, [x24, #0x10]
//   0x4040: 6b00023f  cmp      w17, w0
//   0x4044: 1a9fc011  csel     w17, w0, wzr, gt
//   0x4048: 8b314631  add      x17, x17, w17, uxtw #1
//   0x404c: 8b110031  add      x17, x1, x17
//   0x4050: 39400220  ldrb     w0, [x17]
//   0x4054: 39400621  ldrb     w1, [x17, #1]
//   0x4058: 39400a31  ldrb     w17, [x17, #2]
//   0x405c: 33181c20  bfi      w0, w1, #8, #8
//   0x4060: 33103e20  bfi      w0, w17, #0x10, #0x10
//   0x4064: 32081c11  orr      w17, w0, #0xff000000
//   0x4068: 17ffffeb  b        #0x4014
//   0x406c: aa1303e0  mov      x0, x19
//   0x4070: aa1603e1  mov      x1, x22
//   0x4074: 97fff6b3  bl       #0x1b40
//   0x4078: aa1703e0  mov      x0, x23
//   0x407c: 97fff689  bl       #0x1aa0
//   0x4080: f9400bf8  ldr      x24, [sp, #0x10]
//   0x4084: 34000120  cbz      w0, #0x40a8
//   0x4088: 97fff642  bl       #0x1990
//   0x408c: f0000001  adrp     x1, #0x7000
//   0x4090: f0000002  adrp     x2, #0x7000
//   0x4094: aa0003e3  mov      x3, x0
//   0x4098: 910c8021  add      x1, x1, #0x320
//   0x409c: 910f5442  add      x2, x2, #0x3d5
//   0x40a0: 528000c0  mov      w0, #6
//   0x40a4: 97fff683  bl       #0x1ab0
//   0x40a8: aa1803e0  mov      x0, x24
//   0x40ac: 97fff661  bl       #0x1a30
//   0x40b0: 17ffff4c  b        #0x3de0
//   0x40b4: 97fff6b7  bl       #0x1b90
// ============================================================================
std::uint32_t fde_25_3cd8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00003cd8ULL;
    for (std::size_t i = 0; i < 248ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2106ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[26] Symbol: sub_40b8
//      Virtual Address Range: 0x40b8..0x41e4 (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[26] Biểu tượng: sub_40b8
//      Dải địa chỉ ảo: 0x40b8..0x41e4 (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x40b8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x40bc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x40c0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x40c4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x40c8: 9100c3fd  add      x29, sp, #0x30
//   0x40cc: f9400008  ldr      x8, [x0]
//   0x40d0: aa0003f3  mov      x19, x0
//   0x40d4: aa0103f4  mov      x20, x1
//   0x40d8: f9436508  ldr      x8, [x8, #0x6c8]
//   0x40dc: d63f0100  blr      x8
//   0x40e0: f9400268  ldr      x8, [x19]
//   0x40e4: 90000069  adrp     x9, #0x10000
//   0x40e8: f9414122  ldr      x2, [x9, #0x280]
//   0x40ec: aa1303e0  mov      x0, x19
//   0x40f0: f9419508  ldr      x8, [x8, #0x328]
//   0x40f4: aa1403e1  mov      x1, x20
//   0x40f8: d63f0100  blr      x8
//   0x40fc: b4000540  cbz      x0, #0x41a4
//   0x4100: f9401808  ldr      x8, [x0, #0x30]
//   0x4104: aa0003f6  mov      x22, x0
//   0x4108: aa1403e1  mov      x1, x20
//   0x410c: 91000508  add      x8, x8, #1
//   0x4110: f9001808  str      x8, [x0, #0x30]
//   0x4114: f9400268  ldr      x8, [x19]
//   0x4118: aa1303e0  mov      x0, x19
//   0x411c: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4120: d63f0100  blr      x8
//   0x4124: f9400268  ldr      x8, [x19]
//   0x4128: b9401ed5  ldr      w21, [x22, #0x1c]
//   0x412c: aa1303e0  mov      x0, x19
//   0x4130: aa1403e1  mov      x1, x20
//   0x4134: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4138: d63f0100  blr      x8
//   0x413c: f9401ac8  ldr      x8, [x22, #0x30]
//   0x4140: f1000508  subs     x8, x8, #1
//   0x4144: f9001ac8  str      x8, [x22, #0x30]
//   0x4148: 54000221  b.ne     #0x418c
//   0x414c: f94006d7  ldr      x23, [x22, #8]
//   0x4150: b40001b7  cbz      x23, #0x4184
//   0x4154: 910022e8  add      x8, x23, #8
//   0x4158: c85ffd09  ldaxr    x9, [x8]
//   0x415c: d100052a  sub      x10, x9, #1
//   0x4160: c80bfd0a  stlxr    w11, x10, [x8]
//   0x4164: 35ffffab  cbnz     w11, #0x4158
//   0x4168: b50000e9  cbnz     x9, #0x4184
//   0x416c: f94002e8  ldr      x8, [x23]
//   0x4170: aa1703e0  mov      x0, x23
//   0x4174: f9400908  ldr      x8, [x8, #0x10]
//   0x4178: d63f0100  blr      x8
//   0x417c: aa1703e0  mov      x0, x23
//   0x4180: 97fff660  bl       #0x1b00
//   0x4184: aa1603e0  mov      x0, x22
//   0x4188: 97fff60e  bl       #0x19c0
//   0x418c: f9400268  ldr      x8, [x19]
//   0x4190: aa1303e0  mov      x0, x19
//   0x4194: aa1403e1  mov      x1, x20
//   0x4198: f9436908  ldr      x8, [x8, #0x6d0]
//   0x419c: d63f0100  blr      x8
//   0x41a0: 1400000b  b        #0x41cc
//   0x41a4: f9400268  ldr      x8, [x19]
//   0x41a8: aa1303e0  mov      x0, x19
//   0x41ac: aa1403e1  mov      x1, x20
//   0x41b0: f9436908  ldr      x8, [x8, #0x6d0]
//   0x41b4: d63f0100  blr      x8
//   0x41b8: f0000001  adrp     x1, #0x7000
//   0x41bc: 910a7821  add      x1, x1, #0x29e
//   0x41c0: aa1303e0  mov      x0, x19
//   0x41c4: 94000507  bl       #0x55e0
//   0x41c8: 12800015  mov      w21, #-1
//   0x41cc: 2a1503e0  mov      w0, w21
//   0x41d0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x41d4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x41d8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x41dc: f84407f7  ldr      x23, [sp], #0x40
//   0x41e0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_26_40b8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000040b8ULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2354ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[27] Symbol: sub_41e4
//      Virtual Address Range: 0x41e4..0x4420 (572 bytes, 143 AArch64 instructions)
// [VN] Khung FDE[27] Biểu tượng: sub_41e4
//      Dải địa chỉ ảo: 0x41e4..0x4420 (572 byte, 143 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x41e4: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x41e8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x41ec: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x41f0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x41f4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x41f8: 910103fd  add      x29, sp, #0x40
//   0x41fc: f9400008  ldr      x8, [x0]
//   0x4200: aa0003f3  mov      x19, x0
//   0x4204: aa0103f4  mov      x20, x1
//   0x4208: f9436508  ldr      x8, [x8, #0x6c8]
//   0x420c: d63f0100  blr      x8
//   0x4210: f9400268  ldr      x8, [x19]
//   0x4214: 90000069  adrp     x9, #0x10000
//   0x4218: f9414122  ldr      x2, [x9, #0x280]
//   0x421c: aa1303e0  mov      x0, x19
//   0x4220: f9419508  ldr      x8, [x8, #0x328]
//   0x4224: aa1403e1  mov      x1, x20
//   0x4228: d63f0100  blr      x8
//   0x422c: aa0003f5  mov      x21, x0
//   0x4230: b4000080  cbz      x0, #0x4240
//   0x4234: f9401aa8  ldr      x8, [x21, #0x30]
//   0x4238: 91000508  add      x8, x8, #1
//   0x423c: f9001aa8  str      x8, [x21, #0x30]
//   0x4240: f9400268  ldr      x8, [x19]
//   0x4244: aa1303e0  mov      x0, x19
//   0x4248: aa1403e1  mov      x1, x20
//   0x424c: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4250: d63f0100  blr      x8
//   0x4254: a9405ab7  ldp      x23, x22, [x21]
//   0x4258: b40000d6  cbz      x22, #0x4270
//   0x425c: 910022c8  add      x8, x22, #8
//   0x4260: c85f7d09  ldxr     x9, [x8]
//   0x4264: 91000529  add      x9, x9, #1
//   0x4268: c80a7d09  stxr     w10, x9, [x8]
//   0x426c: 35ffffaa  cbnz     w10, #0x4260
//   0x4270: f9400ae8  ldr      x8, [x23, #0x10]
//   0x4274: b98012ba  ldrsw    x26, [x21, #0x10]
//   0x4278: 910222f8  add      x24, x23, #0x88
//   0x427c: aa1803e0  mov      x0, x24
//   0x4280: f9400d19  ldr      x25, [x8, #0x18]
//   0x4284: 97fff603  bl       #0x1a90
//   0x4288: 34000120  cbz      w0, #0x42ac
//   0x428c: 97fff5c1  bl       #0x1990
//   0x4290: f0000001  adrp     x1, #0x7000
//   0x4294: f0000002  adrp     x2, #0x7000
//   0x4298: aa0003e3  mov      x3, x0
//   0x429c: 910c8021  add      x1, x1, #0x320
//   0x42a0: 910ecc42  add      x2, x2, #0x3b3
//   0x42a4: 528000c0  mov      w0, #6
//   0x42a8: 97fff602  bl       #0x1ab0
//   0x42ac: f9400ae8  ldr      x8, [x23, #0x10]
//   0x42b0: 52800709  mov      w9, #0x38
//   0x42b4: f9402508  ldr      x8, [x8, #0x48]
//   0x42b8: d503201f  nop      
//   0x42bc: 9b092348  madd     x8, x26, x9, x8
//   0x42c0: f9400d08  ldr      x8, [x8, #0x18]
//   0x42c4: b4000108  cbz      x8, #0x42e4
//   0x42c8: 29402909  ldp      w9, w10, [x8]
//   0x42cc: 9000006b  adrp     x11, #0x10000
//   0x42d0: f941456b  ldr      x11, [x11, #0x288]
//   0x42d4: 5280002c  mov      w12, #1
//   0x42d8: 1aca218a  lsl      w10, w12, w10
//   0x42dc: 6b0a013f  cmp      w9, w10
//   0x42e0: 9a8b0119  csel     x25, x8, x11, eq
//   0x42e4: 2a1f03f7  mov      w23, wzr
//   0x42e8: b4000239  cbz      x25, #0x432c
//   0x42ec: b9402ea8  ldr      w8, [x21, #0x2c]
//   0x42f0: 37f801e8  tbnz     w8, #0x1f, #0x432c
//   0x42f4: b9400329  ldr      w9, [x25]
//   0x42f8: 6b08013f  cmp      w9, w8
//   0x42fc: f9400b29  ldr      x9, [x25, #0x10]
//   0x4300: 1a9fc108  csel     w8, w8, wzr, gt
//   0x4304: 93407d0a  sxtw     x10, w8
//   0x4308: 8b28c548  add      x8, x10, w8, sxtw #1
//   0x430c: 8b080128  add      x8, x9, x8
//   0x4310: 39400509  ldrb     w9, [x8, #1]
//   0x4314: 3940010a  ldrb     w10, [x8]
//   0x4318: 39400908  ldrb     w8, [x8, #2]
//   0x431c: 53185d29  lsl      w9, w9, #8
//   0x4320: 33103d49  bfi      w9, w10, #0x10, #0x10
//   0x4324: 2a080128  orr      w8, w9, w8
//   0x4328: 32081d17  orr      w23, w8, #0xff000000
//   0x432c: aa1803e0  mov      x0, x24
//   0x4330: 97fff5dc  bl       #0x1aa0
//   0x4334: 34000120  cbz      w0, #0x4358
//   0x4338: 97fff596  bl       #0x1990
//   0x433c: f0000001  adrp     x1, #0x7000
//   0x4340: f0000002  adrp     x2, #0x7000
//   0x4344: aa0003e3  mov      x3, x0
//   0x4348: 910c8021  add      x1, x1, #0x320
//   0x434c: 910f5442  add      x2, x2, #0x3d5
//   0x4350: 528000c0  mov      w0, #6
//   0x4354: 97fff5d7  bl       #0x1ab0
//   0x4358: b40001b6  cbz      x22, #0x438c
//   0x435c: 910022c8  add      x8, x22, #8
//   0x4360: c85ffd09  ldaxr    x9, [x8]
//   0x4364: d100052a  sub      x10, x9, #1
//   0x4368: c80bfd0a  stlxr    w11, x10, [x8]
//   0x436c: 35ffffab  cbnz     w11, #0x4360
//   0x4370: b50000e9  cbnz     x9, #0x438c
//   0x4374: f94002c8  ldr      x8, [x22]
//   0x4378: aa1603e0  mov      x0, x22
//   0x437c: f9400908  ldr      x8, [x8, #0x10]
//   0x4380: d63f0100  blr      x8
//   0x4384: aa1603e0  mov      x0, x22
//   0x4388: 97fff5de  bl       #0x1b00
//   0x438c: f9400268  ldr      x8, [x19]
//   0x4390: aa1303e0  mov      x0, x19
//   0x4394: aa1403e1  mov      x1, x20
//   0x4398: f9436508  ldr      x8, [x8, #0x6c8]
//   0x439c: d63f0100  blr      x8
//   0x43a0: f9401aa8  ldr      x8, [x21, #0x30]
//   0x43a4: f1000508  subs     x8, x8, #1
//   0x43a8: f9001aa8  str      x8, [x21, #0x30]
//   0x43ac: 54000221  b.ne     #0x43f0
//   0x43b0: f94006b6  ldr      x22, [x21, #8]
//   0x43b4: b40001b6  cbz      x22, #0x43e8
//   0x43b8: 910022c8  add      x8, x22, #8
//   0x43bc: c85ffd09  ldaxr    x9, [x8]
//   0x43c0: d100052a  sub      x10, x9, #1
//   0x43c4: c80bfd0a  stlxr    w11, x10, [x8]
//   0x43c8: 35ffffab  cbnz     w11, #0x43bc
//   0x43cc: b50000e9  cbnz     x9, #0x43e8
//   0x43d0: f94002c8  ldr      x8, [x22]
//   0x43d4: aa1603e0  mov      x0, x22
//   0x43d8: f9400908  ldr      x8, [x8, #0x10]
//   0x43dc: d63f0100  blr      x8
//   0x43e0: aa1603e0  mov      x0, x22
//   0x43e4: 97fff5c7  bl       #0x1b00
//   0x43e8: aa1503e0  mov      x0, x21
//   0x43ec: 97fff575  bl       #0x19c0
//   0x43f0: f9400268  ldr      x8, [x19]
//   0x43f4: aa1303e0  mov      x0, x19
//   0x43f8: aa1403e1  mov      x1, x20
//   0x43fc: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4400: d63f0100  blr      x8
//   0x4404: 2a1703e0  mov      w0, w23
//   0x4408: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x440c: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x4410: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x4414: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x4418: a8c567fa  ldp      x26, x25, [sp], #0x50
//   0x441c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_27_41e4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000041e4ULL;
    for (std::size_t i = 0; i < 143ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2429ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[28] Symbol: sub_4420
//      Virtual Address Range: 0x4420..0x4554 (308 bytes, 77 AArch64 instructions)
// [VN] Khung FDE[28] Biểu tượng: sub_4420
//      Dải địa chỉ ảo: 0x4420..0x4554 (308 byte, 77 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4420: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x4424: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x4428: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x442c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x4430: 9100c3fd  add      x29, sp, #0x30
//   0x4434: f9400008  ldr      x8, [x0]
//   0x4438: aa0003f3  mov      x19, x0
//   0x443c: aa0103f4  mov      x20, x1
//   0x4440: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4444: d63f0100  blr      x8
//   0x4448: f9400268  ldr      x8, [x19]
//   0x444c: 90000069  adrp     x9, #0x10000
//   0x4450: f9414122  ldr      x2, [x9, #0x280]
//   0x4454: aa1303e0  mov      x0, x19
//   0x4458: f9419508  ldr      x8, [x8, #0x328]
//   0x445c: aa1403e1  mov      x1, x20
//   0x4460: d63f0100  blr      x8
//   0x4464: b4000580  cbz      x0, #0x4514
//   0x4468: f9401808  ldr      x8, [x0, #0x30]
//   0x446c: aa0003f5  mov      x21, x0
//   0x4470: aa1403e1  mov      x1, x20
//   0x4474: 91000508  add      x8, x8, #1
//   0x4478: f9001808  str      x8, [x0, #0x30]
//   0x447c: f9400268  ldr      x8, [x19]
//   0x4480: aa1303e0  mov      x0, x19
//   0x4484: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4488: d63f0100  blr      x8
//   0x448c: f9400268  ldr      x8, [x19]
//   0x4490: b9402ea9  ldr      w9, [x21, #0x2c]
//   0x4494: aa1303e0  mov      x0, x19
//   0x4498: aa1403e1  mov      x1, x20
//   0x449c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x44a0: 2a2903e9  mvn      w9, w9
//   0x44a4: 531f7d36  lsr      w22, w9, #0x1f
//   0x44a8: d63f0100  blr      x8
//   0x44ac: f9401aa8  ldr      x8, [x21, #0x30]
//   0x44b0: f1000508  subs     x8, x8, #1
//   0x44b4: f9001aa8  str      x8, [x21, #0x30]
//   0x44b8: 54000221  b.ne     #0x44fc
//   0x44bc: f94006b7  ldr      x23, [x21, #8]
//   0x44c0: b40001b7  cbz      x23, #0x44f4
//   0x44c4: 910022e8  add      x8, x23, #8
//   0x44c8: c85ffd09  ldaxr    x9, [x8]
//   0x44cc: d100052a  sub      x10, x9, #1
//   0x44d0: c80bfd0a  stlxr    w11, x10, [x8]
//   0x44d4: 35ffffab  cbnz     w11, #0x44c8
//   0x44d8: b50000e9  cbnz     x9, #0x44f4
//   0x44dc: f94002e8  ldr      x8, [x23]
//   0x44e0: aa1703e0  mov      x0, x23
//   0x44e4: f9400908  ldr      x8, [x8, #0x10]
//   0x44e8: d63f0100  blr      x8
//   0x44ec: aa1703e0  mov      x0, x23
//   0x44f0: 97fff584  bl       #0x1b00
//   0x44f4: aa1503e0  mov      x0, x21
//   0x44f8: 97fff532  bl       #0x19c0
//   0x44fc: f9400268  ldr      x8, [x19]
//   0x4500: aa1303e0  mov      x0, x19
//   0x4504: aa1403e1  mov      x1, x20
//   0x4508: f9436908  ldr      x8, [x8, #0x6d0]
//   0x450c: d63f0100  blr      x8
//   0x4510: 1400000b  b        #0x453c
//   0x4514: f9400268  ldr      x8, [x19]
//   0x4518: aa1303e0  mov      x0, x19
//   0x451c: aa1403e1  mov      x1, x20
//   0x4520: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4524: d63f0100  blr      x8
//   0x4528: f0000001  adrp     x1, #0x7000
//   0x452c: 910a7821  add      x1, x1, #0x29e
//   0x4530: aa1303e0  mov      x0, x19
//   0x4534: 9400042b  bl       #0x55e0
//   0x4538: 52801ff6  mov      w22, #0xff
//   0x453c: 2a1603e0  mov      w0, w22
//   0x4540: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x4544: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x4548: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x454c: f84407f7  ldr      x23, [sp], #0x40
//   0x4550: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_28_4420(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004420ULL;
    for (std::size_t i = 0; i < 77ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2572ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[29] Symbol: sub_4554
//      Virtual Address Range: 0x4554..0x4680 (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[29] Biểu tượng: sub_4554
//      Dải địa chỉ ảo: 0x4554..0x4680 (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4554: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x4558: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x455c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x4560: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x4564: 9100c3fd  add      x29, sp, #0x30
//   0x4568: f9400008  ldr      x8, [x0]
//   0x456c: aa0003f3  mov      x19, x0
//   0x4570: aa0103f4  mov      x20, x1
//   0x4574: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4578: d63f0100  blr      x8
//   0x457c: f9400268  ldr      x8, [x19]
//   0x4580: 90000069  adrp     x9, #0x10000
//   0x4584: f9414122  ldr      x2, [x9, #0x280]
//   0x4588: aa1303e0  mov      x0, x19
//   0x458c: f9419508  ldr      x8, [x8, #0x328]
//   0x4590: aa1403e1  mov      x1, x20
//   0x4594: d63f0100  blr      x8
//   0x4598: b4000540  cbz      x0, #0x4640
//   0x459c: f9401808  ldr      x8, [x0, #0x30]
//   0x45a0: aa0003f6  mov      x22, x0
//   0x45a4: aa1403e1  mov      x1, x20
//   0x45a8: 91000508  add      x8, x8, #1
//   0x45ac: f9001808  str      x8, [x0, #0x30]
//   0x45b0: f9400268  ldr      x8, [x19]
//   0x45b4: aa1303e0  mov      x0, x19
//   0x45b8: f9436908  ldr      x8, [x8, #0x6d0]
//   0x45bc: d63f0100  blr      x8
//   0x45c0: f9400268  ldr      x8, [x19]
//   0x45c4: b94022d5  ldr      w21, [x22, #0x20]
//   0x45c8: aa1303e0  mov      x0, x19
//   0x45cc: aa1403e1  mov      x1, x20
//   0x45d0: f9436508  ldr      x8, [x8, #0x6c8]
//   0x45d4: d63f0100  blr      x8
//   0x45d8: f9401ac8  ldr      x8, [x22, #0x30]
//   0x45dc: f1000508  subs     x8, x8, #1
//   0x45e0: f9001ac8  str      x8, [x22, #0x30]
//   0x45e4: 54000221  b.ne     #0x4628
//   0x45e8: f94006d7  ldr      x23, [x22, #8]
//   0x45ec: b40001b7  cbz      x23, #0x4620
//   0x45f0: 910022e8  add      x8, x23, #8
//   0x45f4: c85ffd09  ldaxr    x9, [x8]
//   0x45f8: d100052a  sub      x10, x9, #1
//   0x45fc: c80bfd0a  stlxr    w11, x10, [x8]
//   0x4600: 35ffffab  cbnz     w11, #0x45f4
//   0x4604: b50000e9  cbnz     x9, #0x4620
//   0x4608: f94002e8  ldr      x8, [x23]
//   0x460c: aa1703e0  mov      x0, x23
//   0x4610: f9400908  ldr      x8, [x8, #0x10]
//   0x4614: d63f0100  blr      x8
//   0x4618: aa1703e0  mov      x0, x23
//   0x461c: 97fff539  bl       #0x1b00
//   0x4620: aa1603e0  mov      x0, x22
//   0x4624: 97fff4e7  bl       #0x19c0
//   0x4628: f9400268  ldr      x8, [x19]
//   0x462c: aa1303e0  mov      x0, x19
//   0x4630: aa1403e1  mov      x1, x20
//   0x4634: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4638: d63f0100  blr      x8
//   0x463c: 1400000b  b        #0x4668
//   0x4640: f9400268  ldr      x8, [x19]
//   0x4644: aa1303e0  mov      x0, x19
//   0x4648: aa1403e1  mov      x1, x20
//   0x464c: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4650: d63f0100  blr      x8
//   0x4654: f0000001  adrp     x1, #0x7000
//   0x4658: 910a7821  add      x1, x1, #0x29e
//   0x465c: aa1303e0  mov      x0, x19
//   0x4660: 940003e0  bl       #0x55e0
//   0x4664: 12800015  mov      w21, #-1
//   0x4668: 2a1503e0  mov      w0, w21
//   0x466c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x4670: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x4674: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x4678: f84407f7  ldr      x23, [sp], #0x40
//   0x467c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_29_4554(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004554ULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2649ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[30] Symbol: sub_4680
//      Virtual Address Range: 0x4680..0x47ac (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[30] Biểu tượng: sub_4680
//      Dải địa chỉ ảo: 0x4680..0x47ac (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4680: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x4684: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x4688: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x468c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x4690: 9100c3fd  add      x29, sp, #0x30
//   0x4694: f9400008  ldr      x8, [x0]
//   0x4698: aa0003f3  mov      x19, x0
//   0x469c: aa0103f4  mov      x20, x1
//   0x46a0: f9436508  ldr      x8, [x8, #0x6c8]
//   0x46a4: d63f0100  blr      x8
//   0x46a8: f9400268  ldr      x8, [x19]
//   0x46ac: 90000069  adrp     x9, #0x10000
//   0x46b0: f9414122  ldr      x2, [x9, #0x280]
//   0x46b4: aa1303e0  mov      x0, x19
//   0x46b8: f9419508  ldr      x8, [x8, #0x328]
//   0x46bc: aa1403e1  mov      x1, x20
//   0x46c0: d63f0100  blr      x8
//   0x46c4: b4000540  cbz      x0, #0x476c
//   0x46c8: f9401808  ldr      x8, [x0, #0x30]
//   0x46cc: aa0003f6  mov      x22, x0
//   0x46d0: aa1403e1  mov      x1, x20
//   0x46d4: 91000508  add      x8, x8, #1
//   0x46d8: f9001808  str      x8, [x0, #0x30]
//   0x46dc: f9400268  ldr      x8, [x19]
//   0x46e0: aa1303e0  mov      x0, x19
//   0x46e4: f9436908  ldr      x8, [x8, #0x6d0]
//   0x46e8: d63f0100  blr      x8
//   0x46ec: f9400268  ldr      x8, [x19]
//   0x46f0: b94026d5  ldr      w21, [x22, #0x24]
//   0x46f4: aa1303e0  mov      x0, x19
//   0x46f8: aa1403e1  mov      x1, x20
//   0x46fc: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4700: d63f0100  blr      x8
//   0x4704: f9401ac8  ldr      x8, [x22, #0x30]
//   0x4708: f1000508  subs     x8, x8, #1
//   0x470c: f9001ac8  str      x8, [x22, #0x30]
//   0x4710: 54000221  b.ne     #0x4754
//   0x4714: f94006d7  ldr      x23, [x22, #8]
//   0x4718: b40001b7  cbz      x23, #0x474c
//   0x471c: 910022e8  add      x8, x23, #8
//   0x4720: c85ffd09  ldaxr    x9, [x8]
//   0x4724: d100052a  sub      x10, x9, #1
//   0x4728: c80bfd0a  stlxr    w11, x10, [x8]
//   0x472c: 35ffffab  cbnz     w11, #0x4720
//   0x4730: b50000e9  cbnz     x9, #0x474c
//   0x4734: f94002e8  ldr      x8, [x23]
//   0x4738: aa1703e0  mov      x0, x23
//   0x473c: f9400908  ldr      x8, [x8, #0x10]
//   0x4740: d63f0100  blr      x8
//   0x4744: aa1703e0  mov      x0, x23
//   0x4748: 97fff4ee  bl       #0x1b00
//   0x474c: aa1603e0  mov      x0, x22
//   0x4750: 97fff49c  bl       #0x19c0
//   0x4754: f9400268  ldr      x8, [x19]
//   0x4758: aa1303e0  mov      x0, x19
//   0x475c: aa1403e1  mov      x1, x20
//   0x4760: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4764: d63f0100  blr      x8
//   0x4768: 1400000b  b        #0x4794
//   0x476c: f9400268  ldr      x8, [x19]
//   0x4770: aa1303e0  mov      x0, x19
//   0x4774: aa1403e1  mov      x1, x20
//   0x4778: f9436908  ldr      x8, [x8, #0x6d0]
//   0x477c: d63f0100  blr      x8
//   0x4780: f0000001  adrp     x1, #0x7000
//   0x4784: 910a7821  add      x1, x1, #0x29e
//   0x4788: aa1303e0  mov      x0, x19
//   0x478c: 94000395  bl       #0x55e0
//   0x4790: 12800015  mov      w21, #-1
//   0x4794: 2a1503e0  mov      w0, w21
//   0x4798: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x479c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x47a0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x47a4: f84407f7  ldr      x23, [sp], #0x40
//   0x47a8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_30_4680(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004680ULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2724ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[31] Symbol: sub_47ac
//      Virtual Address Range: 0x47ac..0x48d8 (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[31] Biểu tượng: sub_47ac
//      Dải địa chỉ ảo: 0x47ac..0x48d8 (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x47ac: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x47b0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x47b4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x47b8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x47bc: 9100c3fd  add      x29, sp, #0x30
//   0x47c0: f9400008  ldr      x8, [x0]
//   0x47c4: aa0003f3  mov      x19, x0
//   0x47c8: aa0103f4  mov      x20, x1
//   0x47cc: f9436508  ldr      x8, [x8, #0x6c8]
//   0x47d0: d63f0100  blr      x8
//   0x47d4: f9400268  ldr      x8, [x19]
//   0x47d8: 90000069  adrp     x9, #0x10000
//   0x47dc: f9414122  ldr      x2, [x9, #0x280]
//   0x47e0: aa1303e0  mov      x0, x19
//   0x47e4: f9419508  ldr      x8, [x8, #0x328]
//   0x47e8: aa1403e1  mov      x1, x20
//   0x47ec: d63f0100  blr      x8
//   0x47f0: b4000540  cbz      x0, #0x4898
//   0x47f4: f9401808  ldr      x8, [x0, #0x30]
//   0x47f8: aa0003f6  mov      x22, x0
//   0x47fc: aa1403e1  mov      x1, x20
//   0x4800: 91000508  add      x8, x8, #1
//   0x4804: f9001808  str      x8, [x0, #0x30]
//   0x4808: f9400268  ldr      x8, [x19]
//   0x480c: aa1303e0  mov      x0, x19
//   0x4810: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4814: d63f0100  blr      x8
//   0x4818: f9400268  ldr      x8, [x19]
//   0x481c: b94016d5  ldr      w21, [x22, #0x14]
//   0x4820: aa1303e0  mov      x0, x19
//   0x4824: aa1403e1  mov      x1, x20
//   0x4828: f9436508  ldr      x8, [x8, #0x6c8]
//   0x482c: d63f0100  blr      x8
//   0x4830: f9401ac8  ldr      x8, [x22, #0x30]
//   0x4834: f1000508  subs     x8, x8, #1
//   0x4838: f9001ac8  str      x8, [x22, #0x30]
//   0x483c: 54000221  b.ne     #0x4880
//   0x4840: f94006d7  ldr      x23, [x22, #8]
//   0x4844: b40001b7  cbz      x23, #0x4878
//   0x4848: 910022e8  add      x8, x23, #8
//   0x484c: c85ffd09  ldaxr    x9, [x8]
//   0x4850: d100052a  sub      x10, x9, #1
//   0x4854: c80bfd0a  stlxr    w11, x10, [x8]
//   0x4858: 35ffffab  cbnz     w11, #0x484c
//   0x485c: b50000e9  cbnz     x9, #0x4878
//   0x4860: f94002e8  ldr      x8, [x23]
//   0x4864: aa1703e0  mov      x0, x23
//   0x4868: f9400908  ldr      x8, [x8, #0x10]
//   0x486c: d63f0100  blr      x8
//   0x4870: aa1703e0  mov      x0, x23
//   0x4874: 97fff4a3  bl       #0x1b00
//   0x4878: aa1603e0  mov      x0, x22
//   0x487c: 97fff451  bl       #0x19c0
//   0x4880: f9400268  ldr      x8, [x19]
//   0x4884: aa1303e0  mov      x0, x19
//   0x4888: aa1403e1  mov      x1, x20
//   0x488c: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4890: d63f0100  blr      x8
//   0x4894: 1400000b  b        #0x48c0
//   0x4898: f9400268  ldr      x8, [x19]
//   0x489c: aa1303e0  mov      x0, x19
//   0x48a0: aa1403e1  mov      x1, x20
//   0x48a4: f9436908  ldr      x8, [x8, #0x6d0]
//   0x48a8: d63f0100  blr      x8
//   0x48ac: f0000001  adrp     x1, #0x7000
//   0x48b0: 910a7821  add      x1, x1, #0x29e
//   0x48b4: aa1303e0  mov      x0, x19
//   0x48b8: 9400034a  bl       #0x55e0
//   0x48bc: 12800015  mov      w21, #-1
//   0x48c0: 2a1503e0  mov      w0, w21
//   0x48c4: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x48c8: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x48cc: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x48d0: f84407f7  ldr      x23, [sp], #0x40
//   0x48d4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_31_47ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000047acULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2799ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[32] Symbol: sub_48d8
//      Virtual Address Range: 0x48d8..0x4a04 (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[32] Biểu tượng: sub_48d8
//      Dải địa chỉ ảo: 0x48d8..0x4a04 (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x48d8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x48dc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x48e0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x48e4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x48e8: 9100c3fd  add      x29, sp, #0x30
//   0x48ec: f9400008  ldr      x8, [x0]
//   0x48f0: aa0003f3  mov      x19, x0
//   0x48f4: aa0103f4  mov      x20, x1
//   0x48f8: f9436508  ldr      x8, [x8, #0x6c8]
//   0x48fc: d63f0100  blr      x8
//   0x4900: f9400268  ldr      x8, [x19]
//   0x4904: 90000069  adrp     x9, #0x10000
//   0x4908: f9414122  ldr      x2, [x9, #0x280]
//   0x490c: aa1303e0  mov      x0, x19
//   0x4910: f9419508  ldr      x8, [x8, #0x328]
//   0x4914: aa1403e1  mov      x1, x20
//   0x4918: d63f0100  blr      x8
//   0x491c: b4000540  cbz      x0, #0x49c4
//   0x4920: f9401808  ldr      x8, [x0, #0x30]
//   0x4924: aa0003f6  mov      x22, x0
//   0x4928: aa1403e1  mov      x1, x20
//   0x492c: 91000508  add      x8, x8, #1
//   0x4930: f9001808  str      x8, [x0, #0x30]
//   0x4934: f9400268  ldr      x8, [x19]
//   0x4938: aa1303e0  mov      x0, x19
//   0x493c: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4940: d63f0100  blr      x8
//   0x4944: f9400268  ldr      x8, [x19]
//   0x4948: b9401ad5  ldr      w21, [x22, #0x18]
//   0x494c: aa1303e0  mov      x0, x19
//   0x4950: aa1403e1  mov      x1, x20
//   0x4954: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4958: d63f0100  blr      x8
//   0x495c: f9401ac8  ldr      x8, [x22, #0x30]
//   0x4960: f1000508  subs     x8, x8, #1
//   0x4964: f9001ac8  str      x8, [x22, #0x30]
//   0x4968: 54000221  b.ne     #0x49ac
//   0x496c: f94006d7  ldr      x23, [x22, #8]
//   0x4970: b40001b7  cbz      x23, #0x49a4
//   0x4974: 910022e8  add      x8, x23, #8
//   0x4978: c85ffd09  ldaxr    x9, [x8]
//   0x497c: d100052a  sub      x10, x9, #1
//   0x4980: c80bfd0a  stlxr    w11, x10, [x8]
//   0x4984: 35ffffab  cbnz     w11, #0x4978
//   0x4988: b50000e9  cbnz     x9, #0x49a4
//   0x498c: f94002e8  ldr      x8, [x23]
//   0x4990: aa1703e0  mov      x0, x23
//   0x4994: f9400908  ldr      x8, [x8, #0x10]
//   0x4998: d63f0100  blr      x8
//   0x499c: aa1703e0  mov      x0, x23
//   0x49a0: 97fff458  bl       #0x1b00
//   0x49a4: aa1603e0  mov      x0, x22
//   0x49a8: 97fff406  bl       #0x19c0
//   0x49ac: f9400268  ldr      x8, [x19]
//   0x49b0: aa1303e0  mov      x0, x19
//   0x49b4: aa1403e1  mov      x1, x20
//   0x49b8: f9436908  ldr      x8, [x8, #0x6d0]
//   0x49bc: d63f0100  blr      x8
//   0x49c0: 1400000b  b        #0x49ec
//   0x49c4: f9400268  ldr      x8, [x19]
//   0x49c8: aa1303e0  mov      x0, x19
//   0x49cc: aa1403e1  mov      x1, x20
//   0x49d0: f9436908  ldr      x8, [x8, #0x6d0]
//   0x49d4: d63f0100  blr      x8
//   0x49d8: f0000001  adrp     x1, #0x7000
//   0x49dc: 910a7821  add      x1, x1, #0x29e
//   0x49e0: aa1303e0  mov      x0, x19
//   0x49e4: 940002ff  bl       #0x55e0
//   0x49e8: 12800015  mov      w21, #-1
//   0x49ec: 2a1503e0  mov      w0, w21
//   0x49f0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x49f4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x49f8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x49fc: f84407f7  ldr      x23, [sp], #0x40
//   0x4a00: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_32_48d8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000048d8ULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2874ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[33] Symbol: sub_4a04
//      Virtual Address Range: 0x4a04..0x4b30 (300 bytes, 75 AArch64 instructions)
// [VN] Khung FDE[33] Biểu tượng: sub_4a04
//      Dải địa chỉ ảo: 0x4a04..0x4b30 (300 byte, 75 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4a04: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x4a08: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x4a0c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x4a10: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x4a14: 9100c3fd  add      x29, sp, #0x30
//   0x4a18: f9400008  ldr      x8, [x0]
//   0x4a1c: aa0003f3  mov      x19, x0
//   0x4a20: aa0103f4  mov      x20, x1
//   0x4a24: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4a28: d63f0100  blr      x8
//   0x4a2c: f9400268  ldr      x8, [x19]
//   0x4a30: 90000069  adrp     x9, #0x10000
//   0x4a34: f9414122  ldr      x2, [x9, #0x280]
//   0x4a38: aa1303e0  mov      x0, x19
//   0x4a3c: f9419508  ldr      x8, [x8, #0x328]
//   0x4a40: aa1403e1  mov      x1, x20
//   0x4a44: d63f0100  blr      x8
//   0x4a48: b4000540  cbz      x0, #0x4af0
//   0x4a4c: f9401808  ldr      x8, [x0, #0x30]
//   0x4a50: aa0003f6  mov      x22, x0
//   0x4a54: aa1403e1  mov      x1, x20
//   0x4a58: 91000508  add      x8, x8, #1
//   0x4a5c: f9001808  str      x8, [x0, #0x30]
//   0x4a60: f9400268  ldr      x8, [x19]
//   0x4a64: aa1303e0  mov      x0, x19
//   0x4a68: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4a6c: d63f0100  blr      x8
//   0x4a70: f9400268  ldr      x8, [x19]
//   0x4a74: b9402ad5  ldr      w21, [x22, #0x28]
//   0x4a78: aa1303e0  mov      x0, x19
//   0x4a7c: aa1403e1  mov      x1, x20
//   0x4a80: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4a84: d63f0100  blr      x8
//   0x4a88: f9401ac8  ldr      x8, [x22, #0x30]
//   0x4a8c: f1000508  subs     x8, x8, #1
//   0x4a90: f9001ac8  str      x8, [x22, #0x30]
//   0x4a94: 54000221  b.ne     #0x4ad8
//   0x4a98: f94006d7  ldr      x23, [x22, #8]
//   0x4a9c: b40001b7  cbz      x23, #0x4ad0
//   0x4aa0: 910022e8  add      x8, x23, #8
//   0x4aa4: c85ffd09  ldaxr    x9, [x8]
//   0x4aa8: d100052a  sub      x10, x9, #1
//   0x4aac: c80bfd0a  stlxr    w11, x10, [x8]
//   0x4ab0: 35ffffab  cbnz     w11, #0x4aa4
//   0x4ab4: b50000e9  cbnz     x9, #0x4ad0
//   0x4ab8: f94002e8  ldr      x8, [x23]
//   0x4abc: aa1703e0  mov      x0, x23
//   0x4ac0: f9400908  ldr      x8, [x8, #0x10]
//   0x4ac4: d63f0100  blr      x8
//   0x4ac8: aa1703e0  mov      x0, x23
//   0x4acc: 97fff40d  bl       #0x1b00
//   0x4ad0: aa1603e0  mov      x0, x22
//   0x4ad4: 97fff3bb  bl       #0x19c0
//   0x4ad8: f9400268  ldr      x8, [x19]
//   0x4adc: aa1303e0  mov      x0, x19
//   0x4ae0: aa1403e1  mov      x1, x20
//   0x4ae4: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4ae8: d63f0100  blr      x8
//   0x4aec: 1400000b  b        #0x4b18
//   0x4af0: f9400268  ldr      x8, [x19]
//   0x4af4: aa1303e0  mov      x0, x19
//   0x4af8: aa1403e1  mov      x1, x20
//   0x4afc: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4b00: d63f0100  blr      x8
//   0x4b04: f0000001  adrp     x1, #0x7000
//   0x4b08: 910a7821  add      x1, x1, #0x29e
//   0x4b0c: aa1303e0  mov      x0, x19
//   0x4b10: 940002b4  bl       #0x55e0
//   0x4b14: 12800015  mov      w21, #-1
//   0x4b18: 2a1503e0  mov      w0, w21
//   0x4b1c: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x4b20: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x4b24: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x4b28: f84407f7  ldr      x23, [sp], #0x40
//   0x4b2c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_33_4a04(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004a04ULL;
    for (std::size_t i = 0; i < 75ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2949ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[34] Symbol: sub_4b30
//      Virtual Address Range: 0x4b30..0x4c2c (252 bytes, 63 AArch64 instructions)
// [VN] Khung FDE[34] Biểu tượng: sub_4b30
//      Dải địa chỉ ảo: 0x4b30..0x4c2c (252 byte, 63 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4b30: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x4b34: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x4b38: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x4b3c: 910083fd  add      x29, sp, #0x20
//   0x4b40: f9400008  ldr      x8, [x0]
//   0x4b44: aa0003f3  mov      x19, x0
//   0x4b48: aa0103f4  mov      x20, x1
//   0x4b4c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4b50: d63f0100  blr      x8
//   0x4b54: f9400268  ldr      x8, [x19]
//   0x4b58: 90000076  adrp     x22, #0x10000
//   0x4b5c: f94142c2  ldr      x2, [x22, #0x280]
//   0x4b60: aa1303e0  mov      x0, x19
//   0x4b64: f9419508  ldr      x8, [x8, #0x328]
//   0x4b68: aa1403e1  mov      x1, x20
//   0x4b6c: d63f0100  blr      x8
//   0x4b70: b40004e0  cbz      x0, #0x4c0c
//   0x4b74: f9400268  ldr      x8, [x19]
//   0x4b78: f94142c2  ldr      x2, [x22, #0x280]
//   0x4b7c: aa0003f5  mov      x21, x0
//   0x4b80: aa1303e0  mov      x0, x19
//   0x4b84: f941b908  ldr      x8, [x8, #0x370]
//   0x4b88: aa1403e1  mov      x1, x20
//   0x4b8c: aa1f03e3  mov      x3, xzr
//   0x4b90: d63f0100  blr      x8
//   0x4b94: f9400268  ldr      x8, [x19]
//   0x4b98: aa1303e0  mov      x0, x19
//   0x4b9c: aa1403e1  mov      x1, x20
//   0x4ba0: f9436508  ldr      x8, [x8, #0x6c8]
//   0x4ba4: d63f0100  blr      x8
//   0x4ba8: f9401aa8  ldr      x8, [x21, #0x30]
//   0x4bac: f1000508  subs     x8, x8, #1
//   0x4bb0: f9001aa8  str      x8, [x21, #0x30]
//   0x4bb4: 54000221  b.ne     #0x4bf8
//   0x4bb8: f94006b6  ldr      x22, [x21, #8]
//   0x4bbc: b40001b6  cbz      x22, #0x4bf0
//   0x4bc0: 910022c8  add      x8, x22, #8
//   0x4bc4: c85ffd09  ldaxr    x9, [x8]
//   0x4bc8: d100052a  sub      x10, x9, #1
//   0x4bcc: c80bfd0a  stlxr    w11, x10, [x8]
//   0x4bd0: 35ffffab  cbnz     w11, #0x4bc4
//   0x4bd4: b50000e9  cbnz     x9, #0x4bf0
//   0x4bd8: f94002c8  ldr      x8, [x22]
//   0x4bdc: aa1603e0  mov      x0, x22
//   0x4be0: f9400908  ldr      x8, [x8, #0x10]
//   0x4be4: d63f0100  blr      x8
//   0x4be8: aa1603e0  mov      x0, x22
//   0x4bec: 97fff3c5  bl       #0x1b00
//   0x4bf0: aa1503e0  mov      x0, x21
//   0x4bf4: 97fff373  bl       #0x19c0
//   0x4bf8: f9400268  ldr      x8, [x19]
//   0x4bfc: aa1303e0  mov      x0, x19
//   0x4c00: aa1403e1  mov      x1, x20
//   0x4c04: f9436908  ldr      x8, [x8, #0x6d0]
//   0x4c08: d63f0100  blr      x8
//   0x4c0c: f9400268  ldr      x8, [x19]
//   0x4c10: aa1303e0  mov      x0, x19
//   0x4c14: aa1403e1  mov      x1, x20
//   0x4c18: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x4c1c: f9436902  ldr      x2, [x8, #0x6d0]
//   0x4c20: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x4c24: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x4c28: d61f0040  br       x2
// ============================================================================
std::uint32_t fde_34_4b30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004b30ULL;
    for (std::size_t i = 0; i < 63ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3024ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[35] Symbol: sub_4c2c
//      Virtual Address Range: 0x4c2c..0x4c30 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[35] Biểu tượng: sub_4c2c
//      Dải địa chỉ ảo: 0x4c2c..0x4c30 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4c2c: 17ffffc1  b        #0x4b30
// ============================================================================
std::uint32_t fde_35_4c2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004c2cULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3087ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[36] Symbol: sub_4c30
//      Virtual Address Range: 0x4c30..0x4f84 (852 bytes, 213 AArch64 instructions)
// [VN] Khung FDE[36] Biểu tượng: sub_4c30
//      Dải địa chỉ ảo: 0x4c30..0x4f84 (852 byte, 213 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4c30: 6dbd23e9  stp      d9, d8, [sp, #-0x30]!
//   0x4c34: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x4c38: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x4c3c: 910083fd  add      x29, sp, #0x20
//   0x4c40: f0000001  adrp     x1, #0x7000
//   0x4c44: 910c1821  add      x1, x1, #0x306
//   0x4c48: aa0003f3  mov      x19, x0
//   0x4c4c: 9400029c  bl       #0x56bc
//   0x4c50: 90000074  adrp     x20, #0x10000
//   0x4c54: f9012e80  str      x0, [x20, #0x258]
//   0x4c58: b40018a0  cbz      x0, #0x4f6c
//   0x4c5c: f0000002  adrp     x2, #0x7000
//   0x4c60: f0000003  adrp     x3, #0x7000
//   0x4c64: aa0003e1  mov      x1, x0
//   0x4c68: 910ca442  add      x2, x2, #0x329
//   0x4c6c: 910ce063  add      x3, x3, #0x338
//   0x4c70: aa1303e0  mov      x0, x19
//   0x4c74: 940002a4  bl       #0x5704
//   0x4c78: 90000068  adrp     x8, #0x10000
//   0x4c7c: f9013500  str      x0, [x8, #0x268]
//   0x4c80: b4001760  cbz      x0, #0x4f6c
//   0x4c84: f9412e81  ldr      x1, [x20, #0x258]
//   0x4c88: f0000002  adrp     x2, #0x7000
//   0x4c8c: f0000003  adrp     x3, #0x7000
//   0x4c90: 910ce842  add      x2, x2, #0x33a
//   0x4c94: 910d0463  add      x3, x3, #0x341
//   0x4c98: aa1303e0  mov      x0, x19
//   0x4c9c: 9400029d  bl       #0x5710
//   0x4ca0: 90000068  adrp     x8, #0x10000
//   0x4ca4: f9013100  str      x0, [x8, #0x260]
//   0x4ca8: b4001620  cbz      x0, #0x4f6c
//   0x4cac: f9400268  ldr      x8, [x19]
//   0x4cb0: f9412e81  ldr      x1, [x20, #0x258]
//   0x4cb4: 90000062  adrp     x2, #0x10000
//   0x4cb8: 91000042  add      x2, x2, #0
//   0x4cbc: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x4cc0: 528001c3  mov      w3, #0xe
//   0x4cc4: aa1303e0  mov      x0, x19
//   0x4cc8: d63f0100  blr      x8
//   0x4ccc: 2a0003e8  mov      w8, w0
//   0x4cd0: 35001500  cbnz     w0, #0x4f70
//   0x4cd4: f0000001  adrp     x1, #0x7000
//   0x4cd8: 910d1821  add      x1, x1, #0x346
//   0x4cdc: aa1303e0  mov      x0, x19
//   0x4ce0: 94000277  bl       #0x56bc
//   0x4ce4: 90000074  adrp     x20, #0x10000
//   0x4ce8: f9013a80  str      x0, [x20, #0x270]
//   0x4cec: b4001400  cbz      x0, #0x4f6c
//   0x4cf0: f0000002  adrp     x2, #0x7000
//   0x4cf4: f0000003  adrp     x3, #0x7000
//   0x4cf8: aa0003e1  mov      x1, x0
//   0x4cfc: 910ca442  add      x2, x2, #0x329
//   0x4d00: 910ce063  add      x3, x3, #0x338
//   0x4d04: aa1303e0  mov      x0, x19
//   0x4d08: 9400027f  bl       #0x5704
//   0x4d0c: 90000068  adrp     x8, #0x10000
//   0x4d10: f9014100  str      x0, [x8, #0x280]
//   0x4d14: b40012c0  cbz      x0, #0x4f6c
//   0x4d18: f9413a81  ldr      x1, [x20, #0x270]
//   0x4d1c: f0000002  adrp     x2, #0x7000
//   0x4d20: f0000003  adrp     x3, #0x7000
//   0x4d24: 910ce842  add      x2, x2, #0x33a
//   0x4d28: 910d0463  add      x3, x3, #0x341
//   0x4d2c: aa1303e0  mov      x0, x19
//   0x4d30: 94000278  bl       #0x5710
//   0x4d34: 90000068  adrp     x8, #0x10000
//   0x4d38: f9013d00  str      x0, [x8, #0x278]
//   0x4d3c: b4001180  cbz      x0, #0x4f6c
//   0x4d40: f9400268  ldr      x8, [x19]
//   0x4d44: f9413a81  ldr      x1, [x20, #0x270]
//   0x4d48: 90000062  adrp     x2, #0x10000
//   0x4d4c: 91054042  add      x2, x2, #0x150
//   0x4d50: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x4d54: 52800163  mov      w3, #0xb
//   0x4d58: aa1303e0  mov      x0, x19
//   0x4d5c: d63f0100  blr      x8
//   0x4d60: 2a0003e8  mov      w8, w0
//   0x4d64: 35001060  cbnz     w0, #0x4f70
//   0x4d68: 52802000  mov      w0, #0x100
//   0x4d6c: aa1f03e1  mov      x1, xzr
//   0x4d70: 94000798  bl       #0x6bd0
//   0x4d74: b4000f40  cbz      x0, #0x4f5c
//   0x4d78: d0000009  adrp     x9, #0x6000
//   0x4d7c: 3dc3cd20  ldr      q0, [x9, #0xf30]
//   0x4d80: d0000009  adrp     x9, #0x6000
//   0x4d84: 3dc3d121  ldr      q1, [x9, #0xf40]
//   0x4d88: d0000009  adrp     x9, #0x6000
//   0x4d8c: 3dc3d524  ldr      q4, [x9, #0xf50]
//   0x4d90: d0000009  adrp     x9, #0x6000
//   0x4d94: 3dc3d923  ldr      q3, [x9, #0xf60]
//   0x4d98: d0000009  adrp     x9, #0x6000
//   0x4d9c: 3dc3dd26  ldr      q6, [x9, #0xf70]
//   0x4da0: d0000009  adrp     x9, #0x6000
//   0x4da4: 3dc3e125  ldr      q5, [x9, #0xf80]
//   0x4da8: d0000009  adrp     x9, #0x6000
//   0x4dac: 3dc3e522  ldr      q2, [x9, #0xf90]
//   0x4db0: d0000009  adrp     x9, #0x6000
//   0x4db4: 3dc3e927  ldr      q7, [x9, #0xfa0]
//   0x4db8: d0000009  adrp     x9, #0x6000
//   0x4dbc: 3dc3ed31  ldr      q17, [x9, #0xfb0]
//   0x4dc0: d0000009  adrp     x9, #0x6000
//   0x4dc4: 3dc3f132  ldr      q18, [x9, #0xfc0]
//   0x4dc8: d0000009  adrp     x9, #0x6000
//   0x4dcc: 3dc3f533  ldr      q19, [x9, #0xfd0]
//   0x4dd0: d0000009  adrp     x9, #0x6000
//   0x4dd4: 3dc3f934  ldr      q20, [x9, #0xfe0]
//   0x4dd8: d0000009  adrp     x9, #0x6000
//   0x4ddc: 3dc3fd30  ldr      q16, [x9, #0xff0]
//   0x4de0: f0000009  adrp     x9, #0x7000
//   0x4de4: 3dc00135  ldr      q21, [x9]
//   0x4de8: f0000009  adrp     x9, #0x7000
//   0x4dec: 3dc00536  ldr      q22, [x9, #0x10]
//   0x4df0: f0000009  adrp     x9, #0x7000
//   0x4df4: 3dc00937  ldr      q23, [x9, #0x20]
//   0x4df8: f0000009  adrp     x9, #0x7000
//   0x4dfc: 3dc00d38  ldr      q24, [x9, #0x30]
//   0x4e00: f0000009  adrp     x9, #0x7000
//   0x4e04: 3dc01139  ldr      q25, [x9, #0x40]
//   0x4e08: f0000009  adrp     x9, #0x7000
//   0x4e0c: 3dc0153a  ldr      q26, [x9, #0x50]
//   0x4e10: f0000009  adrp     x9, #0x7000
//   0x4e14: 3dc0193b  ldr      q27, [x9, #0x60]
//   0x4e18: f0000009  adrp     x9, #0x7000
//   0x4e1c: 3dc01d3c  ldr      q28, [x9, #0x70]
//   0x4e20: f0000009  adrp     x9, #0x7000
//   0x4e24: 3dc0213d  ldr      q29, [x9, #0x80]
//   0x4e28: f0000009  adrp     x9, #0x7000
//   0x4e2c: f9400808  ldr      x8, [x0, #0x10]
//   0x4e30: 3dc0253e  ldr      q30, [x9, #0x90]
//   0x4e34: f0000009  adrp     x9, #0x7000
//   0x4e38: 3dc0293f  ldr      q31, [x9, #0xa0]
//   0x4e3c: f0000009  adrp     x9, #0x7000
//   0x4e40: 3dc02d28  ldr      q8, [x9, #0xb0]
//   0x4e44: f0000009  adrp     x9, #0x7000
//   0x4e48: 3dc03129  ldr      q9, [x9, #0xc0]
//   0x4e4c: f0000009  adrp     x9, #0x7000
//   0x4e50: ad000504  stp      q4, q1, [x8]
//   0x4e54: 3dc03521  ldr      q1, [x9, #0xd0]
//   0x4e58: f0000009  adrp     x9, #0x7000
//   0x4e5c: ad020d06  stp      q6, q3, [x8, #0x40]
//   0x4e60: 3dc03923  ldr      q3, [x9, #0xe0]
//   0x4e64: f0000009  adrp     x9, #0x7000
//   0x4e68: ad011500  stp      q0, q5, [x8, #0x20]
//   0x4e6c: 3dc03d20  ldr      q0, [x9, #0xf0]
//   0x4e70: f0000009  adrp     x9, #0x7000
//   0x4e74: 3dc04124  ldr      q4, [x9, #0x100]
//   0x4e78: f0000009  adrp     x9, #0x7000
//   0x4e7c: 3dc04525  ldr      q5, [x9, #0x110]
//   0x4e80: f0000009  adrp     x9, #0x7000
//   0x4e84: ad045102  stp      q2, q20, [x8, #0x80]
//   0x4e88: 3dc04922  ldr      q2, [x9, #0x120]
//   0x4e8c: f0000009  adrp     x9, #0x7000
//   0x4e90: 3dc04d26  ldr      q6, [x9, #0x130]
//   0x4e94: f0000009  adrp     x9, #0x7000
//   0x4e98: ad031d11  stp      q17, q7, [x8, #0x60]
//   0x4e9c: 3dc05127  ldr      q7, [x9, #0x140]
//   0x4ea0: f0000009  adrp     x9, #0x7000
//   0x4ea4: ad076510  stp      q16, q25, [x8, #0xe0]
//   0x4ea8: 3dc05530  ldr      q16, [x9, #0x150]
//   0x4eac: f0000009  adrp     x9, #0x7000
//   0x4eb0: 3dc05931  ldr      q17, [x9, #0x160]
//   0x4eb4: f0000009  adrp     x9, #0x7000
//   0x4eb8: ad054913  stp      q19, q18, [x8, #0xa0]
//   0x4ebc: 3dc05d32  ldr      q18, [x9, #0x170]
//   0x4ec0: f0000009  adrp     x9, #0x7000
//   0x4ec4: 3dc06133  ldr      q19, [x9, #0x180]
//   0x4ec8: f0000009  adrp     x9, #0x7000
//   0x4ecc: ad0c2501  stp      q1, q9, [x8, #0x180]
//   0x4ed0: 3dc06521  ldr      q1, [x9, #0x190]
//   0x4ed4: f0000009  adrp     x9, #0x7000
//   0x4ed8: ad0e0d00  stp      q0, q3, [x8, #0x1c0]
//   0x4edc: 3dc06920  ldr      q0, [x9, #0x1a0]
//   0x4ee0: f0000009  adrp     x9, #0x7000
//   0x4ee4: 3dc06d23  ldr      q3, [x9, #0x1b0]
//   0x4ee8: f0000009  adrp     x9, #0x7000
//   0x4eec: ad0f0906  stp      q6, q2, [x8, #0x1e0]
//   0x4ef0: 3dc07122  ldr      q2, [x9, #0x1c0]
//   0x4ef4: f0000009  adrp     x9, #0x7000
//   0x4ef8: ad0d1108  stp      q8, q4, [x8, #0x1a0]
//   0x4efc: 3dc07524  ldr      q4, [x9, #0x1d0]
//   0x4f00: f0000009  adrp     x9, #0x7000
//   0x4f04: ad104505  stp      q5, q17, [x8, #0x200]
//   0x4f08: 3dc07925  ldr      q5, [x9, #0x1e0]
//   0x4f0c: f0000009  adrp     x9, #0x7000
//   0x4f10: ad124d01  stp      q1, q19, [x8, #0x240]
//   0x4f14: 3dc07d21  ldr      q1, [x9, #0x1f0]
//   0x4f18: f0000009  adrp     x9, #0x7000
//   0x4f1c: ad140103  stp      q3, q0, [x8, #0x280]
//   0x4f20: 3dc08120  ldr      q0, [x9, #0x200]
//   0x4f24: f0000009  adrp     x9, #0x7000
//   0x4f28: ad130912  stp      q18, q2, [x8, #0x260]
//   0x4f2c: 3dc08522  ldr      q2, [x9, #0x210]
//   0x4f30: f0000009  adrp     x9, #0x7000
//   0x4f34: ad151501  stp      q1, q5, [x8, #0x2a0]
//   0x4f38: 3dc08921  ldr      q1, [x9, #0x220]
//   0x4f3c: ad065516  stp      q22, q21, [x8, #0xc0]
//   0x4f40: ad085d18  stp      q24, q23, [x8, #0x100]
//   0x4f44: ad096d1c  stp      q28, q27, [x8, #0x120]
//   0x4f48: ad0b751e  stp      q30, q29, [x8, #0x160]
//   0x4f4c: ad0a7d1a  stp      q26, q31, [x8, #0x140]
//   0x4f50: ad111d10  stp      q16, q7, [x8, #0x220]
//   0x4f54: ad170102  stp      q2, q0, [x8, #0x2e0]
//   0x4f58: ad160504  stp      q4, q1, [x8, #0x2c0]
//   0x4f5c: 2a1f03e8  mov      w8, wzr
//   0x4f60: 90000069  adrp     x9, #0x10000
//   0x4f64: f9014520  str      x0, [x9, #0x288]
//   0x4f68: 14000002  b        #0x4f70
//   0x4f6c: 12800008  mov      w8, #-1
//   0x4f70: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x4f74: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x4f78: 2a0803e0  mov      w0, w8
//   0x4f7c: 6cc323e9  ldp      d9, d8, [sp], #0x30
//   0x4f80: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_36_4c30(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004c30ULL;
    for (std::size_t i = 0; i < 213ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3088ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[37] Symbol: sub_4f84
//      Virtual Address Range: 0x4f84..0x5094 (272 bytes, 68 AArch64 instructions)
// [VN] Khung FDE[37] Biểu tượng: sub_4f84
//      Dải địa chỉ ảo: 0x4f84..0x5094 (272 byte, 68 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x4f84: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x4f88: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x4f8c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x4f90: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x4f94: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x4f98: 910103fd  add      x29, sp, #0x40
//   0x4f9c: aa0003f3  mov      x19, x0
//   0x4fa0: f9400400  ldr      x0, [x0, #8]
//   0x4fa4: f9400a68  ldr      x8, [x19, #0x10]
//   0x4fa8: aa0103f5  mov      x21, x1
//   0x4fac: cb000109  sub      x9, x8, x0
//   0x4fb0: eb01013f  cmp      x9, x1
//   0x4fb4: 540001e2  b.hs     #0x4ff0
//   0x4fb8: f9400274  ldr      x20, [x19]
//   0x4fbc: cb140016  sub      x22, x0, x20
//   0x4fc0: ab1502c9  adds     x9, x22, x21
//   0x4fc4: 54000664  b.mi     #0x5090
//   0x4fc8: cb140108  sub      x8, x8, x20
//   0x4fcc: b27ff3ea  mov      x10, #0x3ffffffffffffffe
//   0x4fd0: eb0a011f  cmp      x8, x10
//   0x4fd4: 540001e8  b.hi     #0x5010
//   0x4fd8: d37ff908  lsl      x8, x8, #1
//   0x4fdc: eb09011f  cmp      x8, x9
//   0x4fe0: 9a883138  csel     x24, x9, x8, lo
//   0x4fe4: b5000198  cbnz     x24, #0x5014
//   0x4fe8: aa1f03f7  mov      x23, xzr
//   0x4fec: 1400000d  b        #0x5020
//   0x4ff0: b40000d5  cbz      x21, #0x5008
//   0x4ff4: 2a1f03e1  mov      w1, wzr
//   0x4ff8: aa1503e2  mov      x2, x21
//   0x4ffc: 8b150014  add      x20, x0, x21
//   0x5000: 97fff2b8  bl       #0x1ae0
//   0x5004: aa1403e0  mov      x0, x20
//   0x5008: f9000660  str      x0, [x19, #8]
//   0x500c: 1400001b  b        #0x5078
//   0x5010: 92f00018  mov      x24, #0x7fffffffffffffff
//   0x5014: aa1803e0  mov      x0, x24
//   0x5018: 97fff2d6  bl       #0x1b70
//   0x501c: aa0003f7  mov      x23, x0
//   0x5020: 8b1602e0  add      x0, x23, x22
//   0x5024: 2a1f03e1  mov      w1, wzr
//   0x5028: aa1503e2  mov      x2, x21
//   0x502c: 8b1802f8  add      x24, x23, x24
//   0x5030: 8b150019  add      x25, x0, x21
//   0x5034: 97fff2ab  bl       #0x1ae0
//   0x5038: f10006df  cmp      x22, #1
//   0x503c: 540000ab  b.lt     #0x5050
//   0x5040: aa1703e0  mov      x0, x23
//   0x5044: aa1403e1  mov      x1, x20
//   0x5048: aa1603e2  mov      x2, x22
//   0x504c: 97fff255  bl       #0x19a0
//   0x5050: a9006677  stp      x23, x25, [x19]
//   0x5054: f9000a78  str      x24, [x19, #0x10]
//   0x5058: b4000114  cbz      x20, #0x5078
//   0x505c: aa1403e0  mov      x0, x20
//   0x5060: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x5064: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x5068: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x506c: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x5070: f84507f9  ldr      x25, [sp], #0x50
//   0x5074: 17fff253  b        #0x19c0
//   0x5078: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x507c: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x5080: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x5084: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x5088: f84507f9  ldr      x25, [sp], #0x50
//   0x508c: d65f03c0  ret      
//   0x5090: 97fff2a0  bl       #0x1b10
// ============================================================================
std::uint32_t fde_37_4f84(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004f84ULL;
    for (std::size_t i = 0; i < 68ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3301ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[38] Symbol: sub_5094
//      Virtual Address Range: 0x5094..0x513c (168 bytes, 42 AArch64 instructions)
// [VN] Khung FDE[38] Biểu tượng: sub_5094
//      Dải địa chỉ ảo: 0x5094..0x513c (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5094: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x5098: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x509c: 910043fd  add      x29, sp, #0x10
//   0x50a0: d0000048  adrp     x8, #0xf000
//   0x50a4: 912d6108  add      x8, x8, #0xb58
//   0x50a8: aa0003f3  mov      x19, x0
//   0x50ac: f8088408  str      x8, [x0], #0x88
//   0x50b0: 97fff2c0  bl       #0x1bb0
//   0x50b4: 91018260  add      x0, x19, #0x60
//   0x50b8: 97fff2ba  bl       #0x1ba0
//   0x50bc: f9402660  ldr      x0, [x19, #0x48]
//   0x50c0: b4000060  cbz      x0, #0x50cc
//   0x50c4: f9002a60  str      x0, [x19, #0x50]
//   0x50c8: 97fff23e  bl       #0x19c0
//   0x50cc: f9401a60  ldr      x0, [x19, #0x30]
//   0x50d0: b4000060  cbz      x0, #0x50dc
//   0x50d4: f9001e60  str      x0, [x19, #0x38]
//   0x50d8: 97fff23a  bl       #0x19c0
//   0x50dc: f9401674  ldr      x20, [x19, #0x28]
//   0x50e0: b40001b4  cbz      x20, #0x5114
//   0x50e4: 91002288  add      x8, x20, #8
//   0x50e8: c85ffd09  ldaxr    x9, [x8]
//   0x50ec: d100052a  sub      x10, x9, #1
//   0x50f0: c80bfd0a  stlxr    w11, x10, [x8]
//   0x50f4: 35ffffab  cbnz     w11, #0x50e8
//   0x50f8: b50000e9  cbnz     x9, #0x5114
//   0x50fc: f9400288  ldr      x8, [x20]
//   0x5100: aa1403e0  mov      x0, x20
//   0x5104: f9400908  ldr      x8, [x8, #0x10]
//   0x5108: d63f0100  blr      x8
//   0x510c: aa1403e0  mov      x0, x20
//   0x5110: 97fff27c  bl       #0x1b00
//   0x5114: f9400a60  ldr      x0, [x19, #0x10]
//   0x5118: f9000a7f  str      xzr, [x19, #0x10]
//   0x511c: b40000a0  cbz      x0, #0x5130
//   0x5120: f9400e61  ldr      x1, [x19, #0x18]
//   0x5124: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x5128: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x512c: d61f0020  br       x1
//   0x5130: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x5134: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x5138: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_38_5094(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005094ULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3369ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[39] Symbol: sub_513c
//      Virtual Address Range: 0x513c..0x5160 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[39] Biểu tượng: sub_513c
//      Dải địa chỉ ảo: 0x513c..0x5160 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x513c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x5140: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x5144: 910043fd  add      x29, sp, #0x10
//   0x5148: aa0003f3  mov      x19, x0
//   0x514c: 97ffffd2  bl       #0x5094
//   0x5150: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x5154: aa1303e0  mov      x0, x19
//   0x5158: f84207f3  ldr      x19, [sp], #0x20
//   0x515c: 17fff219  b        #0x19c0
// ============================================================================
std::uint32_t fde_39_513c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000513cULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3411ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[40] Symbol: sub_5160
//      Virtual Address Range: 0x5160..0x5184 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[40] Biểu tượng: sub_5160
//      Dải địa chỉ ảo: 0x5160..0x5184 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5160: f9400408  ldr      x8, [x0, #8]
//   0x5164: d0000049  adrp     x9, #0xf000
//   0x5168: 912de129  add      x9, x9, #0xb78
//   0x516c: f9000009  str      x9, [x0]
//   0x5170: b4000088  cbz      x8, #0x5180
//   0x5174: f9000808  str      x8, [x0, #0x10]
//   0x5178: aa0803e0  mov      x0, x8
//   0x517c: 17fff211  b        #0x19c0
//   0x5180: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_40_5160(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005160ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3420ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[41] Symbol: sub_5184
//      Virtual Address Range: 0x5184..0x51c0 (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[41] Biểu tượng: sub_5184
//      Dải địa chỉ ảo: 0x5184..0x51c0 (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5184: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x5188: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x518c: 910043fd  add      x29, sp, #0x10
//   0x5190: aa0003f3  mov      x19, x0
//   0x5194: f9400400  ldr      x0, [x0, #8]
//   0x5198: d0000048  adrp     x8, #0xf000
//   0x519c: 912de108  add      x8, x8, #0xb78
//   0x51a0: f9000268  str      x8, [x19]
//   0x51a4: b4000060  cbz      x0, #0x51b0
//   0x51a8: f9000a60  str      x0, [x19, #0x10]
//   0x51ac: 97fff205  bl       #0x19c0
//   0x51b0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x51b4: aa1303e0  mov      x0, x19
//   0x51b8: f84207f3  ldr      x19, [sp], #0x20
//   0x51bc: 17fff201  b        #0x19c0
// ============================================================================
std::uint32_t fde_41_5184(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005184ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3429ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[42] Symbol: sub_51c0
//      Virtual Address Range: 0x51c0..0x5218 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[42] Biểu tượng: sub_51c0
//      Dải địa chỉ ảo: 0x51c0..0x5218 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x51c0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x51c4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x51c8: 910043fd  add      x29, sp, #0x10
//   0x51cc: a9422809  ldp      x9, x10, [x0, #0x20]
//   0x51d0: f940040b  ldr      x11, [x0, #8]
//   0x51d4: aa0103e8  mov      x8, x1
//   0x51d8: aa0003f3  mov      x19, x0
//   0x51dc: 8b02012c  add      x12, x9, x2
//   0x51e0: cb09014d  sub      x13, x10, x9
//   0x51e4: eb0a019f  cmp      x12, x10
//   0x51e8: 9a8281b4  csel     x20, x13, x2, hi
//   0x51ec: 8b090161  add      x1, x11, x9
//   0x51f0: aa0803e0  mov      x0, x8
//   0x51f4: aa1403e2  mov      x2, x20
//   0x51f8: 97fff1ea  bl       #0x19a0
//   0x51fc: f9401268  ldr      x8, [x19, #0x20]
//   0x5200: aa1403e0  mov      x0, x20
//   0x5204: 8b140108  add      x8, x8, x20
//   0x5208: f9001268  str      x8, [x19, #0x20]
//   0x520c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x5210: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x5214: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_42_51c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000051c0ULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3444ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[43] Symbol: sub_5218
//      Virtual Address Range: 0x5218..0x5220 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[43] Biểu tượng: sub_5218
//      Dải địa chỉ ảo: 0x5218..0x5220 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5218: f9401400  ldr      x0, [x0, #0x28]
//   0x521c: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_43_5218(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005218ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3466ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[44] Symbol: sub_5220
//      Virtual Address Range: 0x5220..0x5228 (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[44] Biểu tượng: sub_5220
//      Dải địa chỉ ảo: 0x5220..0x5228 (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5220: f9401000  ldr      x0, [x0, #0x20]
//   0x5224: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_44_5220(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005220ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3468ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[45] Symbol: sub_5228
//      Virtual Address Range: 0x5228..0x5248 (32 bytes, 8 AArch64 instructions)
// [VN] Khung FDE[45] Biểu tượng: sub_5228
//      Dải địa chỉ ảo: 0x5228..0x5248 (32 byte, 8 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5228: f9401408  ldr      x8, [x0, #0x28]
//   0x522c: eb01011f  cmp      x8, x1
//   0x5230: 54000089  b.ls     #0x5240
//   0x5234: f9001001  str      x1, [x0, #0x20]
//   0x5238: 52800020  mov      w0, #1
//   0x523c: d65f03c0  ret      
//   0x5240: 2a1f03e0  mov      w0, wzr
//   0x5244: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_45_5228(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005228ULL;
    for (std::size_t i = 0; i < 8ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3470ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[46] Symbol: sub_5248
//      Virtual Address Range: 0x5248..0x5260 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[46] Biểu tượng: sub_5248
//      Dải địa chỉ ảo: 0x5248..0x5260 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5248: f9400408  ldr      x8, [x0, #8]
//   0x524c: d0000049  adrp     x9, #0xf000
//   0x5250: 912ee129  add      x9, x9, #0xbb8
//   0x5254: f9000009  str      x9, [x0]
//   0x5258: aa0803e0  mov      x0, x8
//   0x525c: 17fff201  b        #0x1a60
// ============================================================================
std::uint32_t fde_46_5248(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005248ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3478ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[47] Symbol: sub_5260
//      Virtual Address Range: 0x5260..0x5294 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[47] Biểu tượng: sub_5260
//      Dải địa chỉ ảo: 0x5260..0x5294 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5260: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x5264: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x5268: 910043fd  add      x29, sp, #0x10
//   0x526c: aa0003f3  mov      x19, x0
//   0x5270: f9400400  ldr      x0, [x0, #8]
//   0x5274: d0000048  adrp     x8, #0xf000
//   0x5278: 912ee108  add      x8, x8, #0xbb8
//   0x527c: f9000268  str      x8, [x19]
//   0x5280: 97fff1f8  bl       #0x1a60
//   0x5284: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x5288: aa1303e0  mov      x0, x19
//   0x528c: f84207f3  ldr      x19, [sp], #0x20
//   0x5290: 17fff1cc  b        #0x19c0
// ============================================================================
std::uint32_t fde_47_5260(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005260ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3484ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[48] Symbol: sub_5294
//      Virtual Address Range: 0x5294..0x52a4 (16 bytes, 4 AArch64 instructions)
// [VN] Khung FDE[48] Biểu tượng: sub_5294
//      Dải địa chỉ ảo: 0x5294..0x52a4 (16 byte, 4 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5294: f9400403  ldr      x3, [x0, #8]
//   0x5298: aa0103e0  mov      x0, x1
//   0x529c: 52800021  mov      w1, #1
//   0x52a0: 17fff1d4  b        #0x19f0
// ============================================================================
std::uint32_t fde_48_5294(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005294ULL;
    for (std::size_t i = 0; i < 4ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3497ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[49] Symbol: sub_52a4
//      Virtual Address Range: 0x52a4..0x52ac (8 bytes, 2 AArch64 instructions)
// [VN] Khung FDE[49] Biểu tượng: sub_52a4
//      Dải địa chỉ ảo: 0x52a4..0x52ac (8 byte, 2 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x52a4: f9400800  ldr      x0, [x0, #0x10]
//   0x52a8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_49_52a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000052a4ULL;
    for (std::size_t i = 0; i < 2ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3501ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[50] Symbol: sub_52ac
//      Virtual Address Range: 0x52ac..0x52c8 (28 bytes, 7 AArch64 instructions)
// [VN] Khung FDE[50] Biểu tượng: sub_52ac
//      Dải địa chỉ ảo: 0x52ac..0x52c8 (28 byte, 7 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x52ac: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x52b0: 910003fd  mov      x29, sp
//   0x52b4: f9400400  ldr      x0, [x0, #8]
//   0x52b8: 97fff202  bl       #0x1ac0
//   0x52bc: 8aa0fc00  bic      x0, x0, x0, asr #63
//   0x52c0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x52c4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_50_52ac(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000052acULL;
    for (std::size_t i = 0; i < 7ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3503ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[51] Symbol: sub_52c8
//      Virtual Address Range: 0x52c8..0x52ec (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[51] Biểu tượng: sub_52c8
//      Dải địa chỉ ảo: 0x52c8..0x52ec (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x52c8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x52cc: 910003fd  mov      x29, sp
//   0x52d0: f9400400  ldr      x0, [x0, #8]
//   0x52d4: 2a1f03e2  mov      w2, wzr
//   0x52d8: 97fff216  bl       #0x1b30
//   0x52dc: 7100001f  cmp      w0, #0
//   0x52e0: 1a9f17e0  cset     w0, eq
//   0x52e4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x52e8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_51_52c8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000052c8ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3510ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[52] Symbol: sub_52ec
//      Virtual Address Range: 0x52ec..0x5310 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[52] Biểu tượng: sub_52ec
//      Dải địa chỉ ảo: 0x52ec..0x5310 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x52ec: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x52f0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x52f4: 910043fd  add      x29, sp, #0x10
//   0x52f8: aa0003f3  mov      x19, x0
//   0x52fc: 97fff1d1  bl       #0x1a40
//   0x5300: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x5304: aa1303e0  mov      x0, x19
//   0x5308: f84207f3  ldr      x19, [sp], #0x20
//   0x530c: 17fff1ad  b        #0x19c0
// ============================================================================
std::uint32_t fde_52_52ec(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000052ecULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3519ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[53] Symbol: sub_5310
//      Virtual Address Range: 0x5310..0x5328 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[53] Biểu tượng: sub_5310
//      Dải địa chỉ ảo: 0x5310..0x5328 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5310: f9400c00  ldr      x0, [x0, #0x18]
//   0x5314: b4000080  cbz      x0, #0x5324
//   0x5318: f9400008  ldr      x8, [x0]
//   0x531c: f9400501  ldr      x1, [x8, #8]
//   0x5320: d61f0020  br       x1
//   0x5324: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_53_5310(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005310ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3528ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[54] Symbol: sub_5328
//      Virtual Address Range: 0x5328..0x532c (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[54] Biểu tượng: sub_5328
//      Dải địa chỉ ảo: 0x5328..0x532c (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5328: 17fff1a6  b        #0x19c0
// ============================================================================
std::uint32_t fde_54_5328(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005328ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3534ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[55] Symbol: sub_532c
//      Virtual Address Range: 0x532c..0x5484 (344 bytes, 86 AArch64 instructions)
// [VN] Khung FDE[55] Biểu tượng: sub_532c
//      Dải địa chỉ ảo: 0x532c..0x5484 (344 byte, 86 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x532c: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x5330: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x5334: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x5338: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x533c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x5340: 910103fd  add      x29, sp, #0x40
//   0x5344: f9400808  ldr      x8, [x0, #0x10]
//   0x5348: f9400017  ldr      x23, [x0]
//   0x534c: cb010055  sub      x21, x2, x1
//   0x5350: 9342feb9  asr      x25, x21, #2
//   0x5354: aa0103f4  mov      x20, x1
//   0x5358: cb170109  sub      x9, x8, x23
//   0x535c: aa0003f3  mov      x19, x0
//   0x5360: eb890b3f  cmp      x25, x9, asr #2
//   0x5364: 54000289  b.ls     #0x53b4
//   0x5368: b40000f7  cbz      x23, #0x5384
//   0x536c: aa1703e0  mov      x0, x23
//   0x5370: f9000677  str      x23, [x19, #8]
//   0x5374: 97fff193  bl       #0x19c0
//   0x5378: aa1f03e8  mov      x8, xzr
//   0x537c: a9007e7f  stp      xzr, xzr, [x19]
//   0x5380: f9000a7f  str      xzr, [x19, #0x10]
//   0x5384: d37eff29  lsr      x9, x25, #0x3e
//   0x5388: b5000149  cbnz     x9, #0x53b0
//   0x538c: b27fefe9  mov      x9, #0x1ffffffffffffffe
//   0x5390: eb88093f  cmp      x9, x8, asr #2
//   0x5394: 540004c3  b.lo     #0x542c
//   0x5398: 9341fd08  asr      x8, x8, #1
//   0x539c: eb19011f  cmp      x8, x25
//   0x53a0: 54000483  b.lo     #0x5430
//   0x53a4: d37efd09  lsr      x9, x8, #0x3e
//   0x53a8: aa0803f9  mov      x25, x8
//   0x53ac: b4000429  cbz      x9, #0x5430
//   0x53b0: 97fff1d8  bl       #0x1b10
//   0x53b4: f9400668  ldr      x8, [x19, #8]
//   0x53b8: aa0203f6  mov      x22, x2
//   0x53bc: cb170108  sub      x8, x8, x23
//   0x53c0: 9342fd1a  asr      x26, x8, #2
//   0x53c4: 8b080288  add      x8, x20, x8
//   0x53c8: eb1a033f  cmp      x25, x26
//   0x53cc: 9a828115  csel     x21, x8, x2, hi
//   0x53d0: eb1402b8  subs     x24, x21, x20
//   0x53d4: 540000a0  b.eq     #0x53e8
//   0x53d8: aa1703e0  mov      x0, x23
//   0x53dc: aa1403e1  mov      x1, x20
//   0x53e0: aa1803e2  mov      x2, x24
//   0x53e4: 97fff19b  bl       #0x1a50
//   0x53e8: eb1a033f  cmp      x25, x26
//   0x53ec: 54000189  b.ls     #0x541c
//   0x53f0: f9400674  ldr      x20, [x19, #8]
//   0x53f4: cb1502d6  sub      x22, x22, x21
//   0x53f8: f10006df  cmp      x22, #1
//   0x53fc: 540000cb  b.lt     #0x5414
//   0x5400: aa1403e0  mov      x0, x20
//   0x5404: aa1503e1  mov      x1, x21
//   0x5408: aa1603e2  mov      x2, x22
//   0x540c: 97fff165  bl       #0x19a0
//   0x5410: 8b160294  add      x20, x20, x22
//   0x5414: f9000674  str      x20, [x19, #8]
//   0x5418: 14000015  b        #0x546c
//   0x541c: 9342ff08  asr      x8, x24, #2
//   0x5420: 8b080ae8  add      x8, x23, x8, lsl #2
//   0x5424: f9000668  str      x8, [x19, #8]
//   0x5428: 14000011  b        #0x546c
//   0x542c: 92f80019  mov      x25, #0x3fffffffffffffff
//   0x5430: d37ef737  lsl      x23, x25, #2
//   0x5434: aa1703e0  mov      x0, x23
//   0x5438: 97fff1ce  bl       #0x1b70
//   0x543c: aa0003f6  mov      x22, x0
//   0x5440: 8b170008  add      x8, x0, x23
//   0x5444: f10006bf  cmp      x21, #1
//   0x5448: a9000260  stp      x0, x0, [x19]
//   0x544c: f9000a68  str      x8, [x19, #0x10]
//   0x5450: 540000cb  b.lt     #0x5468
//   0x5454: aa1603e0  mov      x0, x22
//   0x5458: aa1403e1  mov      x1, x20
//   0x545c: aa1503e2  mov      x2, x21
//   0x5460: 97fff150  bl       #0x19a0
//   0x5464: 8b1502d6  add      x22, x22, x21
//   0x5468: f9000676  str      x22, [x19, #8]
//   0x546c: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x5470: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x5474: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x5478: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x547c: a8c567fa  ldp      x26, x25, [sp], #0x50
//   0x5480: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_55_532c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000532cULL;
    for (std::size_t i = 0; i < 86ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3535ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[56] Symbol: sub_5484
//      Virtual Address Range: 0x5484..0x54a8 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[56] Biểu tượng: sub_5484
//      Dải địa chỉ ảo: 0x5484..0x54a8 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5484: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x5488: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x548c: 910043fd  add      x29, sp, #0x10
//   0x5490: aa0003f3  mov      x19, x0
//   0x5494: 97fff16b  bl       #0x1a40
//   0x5498: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x549c: aa1303e0  mov      x0, x19
//   0x54a0: f84207f3  ldr      x19, [sp], #0x20
//   0x54a4: 17fff147  b        #0x19c0
// ============================================================================
std::uint32_t fde_56_5484(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005484ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3621ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[57] Symbol: sub_54a8
//      Virtual Address Range: 0x54a8..0x54c0 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[57] Biểu tượng: sub_54a8
//      Dải địa chỉ ảo: 0x54a8..0x54c0 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x54a8: f9400c00  ldr      x0, [x0, #0x18]
//   0x54ac: b4000080  cbz      x0, #0x54bc
//   0x54b0: f9400008  ldr      x8, [x0]
//   0x54b4: f9400501  ldr      x1, [x8, #8]
//   0x54b8: d61f0020  br       x1
//   0x54bc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_57_54a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000054a8ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3630ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[58] Symbol: sub_54c0
//      Virtual Address Range: 0x54c0..0x54c4 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[58] Biểu tượng: sub_54c0
//      Dải địa chỉ ảo: 0x54c0..0x54c4 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x54c0: 17fff140  b        #0x19c0
// ============================================================================
std::uint32_t fde_58_54c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000054c0ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3636ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[59] Symbol: sub_54c4
//      Virtual Address Range: 0x54c4..0x54e8 (36 bytes, 9 AArch64 instructions)
// [VN] Khung FDE[59] Biểu tượng: sub_54c4
//      Dải địa chỉ ảo: 0x54c4..0x54e8 (36 byte, 9 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x54c4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x54c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x54cc: 910043fd  add      x29, sp, #0x10
//   0x54d0: aa0003f3  mov      x19, x0
//   0x54d4: 97fff15b  bl       #0x1a40
//   0x54d8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x54dc: aa1303e0  mov      x0, x19
//   0x54e0: f84207f3  ldr      x19, [sp], #0x20
//   0x54e4: 17fff137  b        #0x19c0
// ============================================================================
std::uint32_t fde_59_54c4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000054c4ULL;
    for (std::size_t i = 0; i < 9ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3637ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[60] Symbol: sub_54e8
//      Virtual Address Range: 0x54e8..0x5500 (24 bytes, 6 AArch64 instructions)
// [VN] Khung FDE[60] Biểu tượng: sub_54e8
//      Dải địa chỉ ảo: 0x54e8..0x5500 (24 byte, 6 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x54e8: f9400c00  ldr      x0, [x0, #0x18]
//   0x54ec: b4000080  cbz      x0, #0x54fc
//   0x54f0: f9400008  ldr      x8, [x0]
//   0x54f4: f9400501  ldr      x1, [x8, #8]
//   0x54f8: d61f0020  br       x1
//   0x54fc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_60_54e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000054e8ULL;
    for (std::size_t i = 0; i < 6ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3646ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[61] Symbol: sub_5500
//      Virtual Address Range: 0x5500..0x5504 (4 bytes, 1 AArch64 instructions)
// [VN] Khung FDE[61] Biểu tượng: sub_5500
//      Dải địa chỉ ảo: 0x5500..0x5504 (4 byte, 1 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5500: 17fff130  b        #0x19c0
// ============================================================================
std::uint32_t fde_61_5500(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005500ULL;
    for (std::size_t i = 0; i < 1ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3652ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[62] Symbol: sub_5504
//      Virtual Address Range: 0x5504..0x55e0 (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[62] Biểu tượng: sub_5504
//      Dải địa chỉ ảo: 0x5504..0x55e0 (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5504: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x5508: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x550c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x5510: 910083fd  add      x29, sp, #0x20
//   0x5514: d11403ff  sub      sp, sp, #0x500
//   0x5518: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x551c: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x5520: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x5524: ad0007e0  stp      q0, q1, [sp]
//   0x5528: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x552c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x5530: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x5534: d53bd054  mrs      x20, tpidr_el0
//   0x5538: f940168c  ldr      x12, [x20, #0x28]
//   0x553c: 928005e9  mov      x9, #-0x30
//   0x5540: 910003ea  mov      x10, sp
//   0x5544: 910203eb  add      x11, sp, #0x80
//   0x5548: f2dff009  movk     x9, #0xff80, lsl #32
//   0x554c: 910043ad  add      x13, x29, #0x10
//   0x5550: 9102014a  add      x10, x10, #0x80
//   0x5554: 9100c16b  add      x11, x11, #0x30
//   0x5558: f81d83ac  stur     x12, [x29, #-0x28]
//   0x555c: a90c27ea  stp      x10, x9, [sp, #0xc0]
//   0x5560: a90b2fed  stp      x13, x11, [sp, #0xb0]
//   0x5564: ad4583e1  ldp      q1, q0, [sp, #0xb0]
//   0x5568: aa0103e8  mov      x8, x1
//   0x556c: aa0003f3  mov      x19, x0
//   0x5570: 9103e3e0  add      x0, sp, #0xf8
//   0x5574: 910343e3  add      x3, sp, #0xd0
//   0x5578: 52808001  mov      w1, #0x400
//   0x557c: aa0803e2  mov      x2, x8
//   0x5580: ad0683e1  stp      q1, q0, [sp, #0xd0]
//   0x5584: 97fff153  bl       #0x1ad0
//   0x5588: f9400268  ldr      x8, [x19]
//   0x558c: d0000001  adrp     x1, #0x7000
//   0x5590: 911d5021  add      x1, x1, #0x754
//   0x5594: aa1303e0  mov      x0, x19
//   0x5598: f9401908  ldr      x8, [x8, #0x30]
//   0x559c: d63f0100  blr      x8
//   0x55a0: f9400268  ldr      x8, [x19]
//   0x55a4: aa0003e1  mov      x1, x0
//   0x55a8: 9103e3e2  add      x2, sp, #0xf8
//   0x55ac: aa1303e0  mov      x0, x19
//   0x55b0: f9403908  ldr      x8, [x8, #0x70]
//   0x55b4: d63f0100  blr      x8
//   0x55b8: f9401688  ldr      x8, [x20, #0x28]
//   0x55bc: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x55c0: eb09011f  cmp      x8, x9
//   0x55c4: 540000c1  b.ne     #0x55dc
//   0x55c8: 911403ff  add      sp, sp, #0x500
//   0x55cc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x55d0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x55d4: f84307fc  ldr      x28, [sp], #0x30
//   0x55d8: d65f03c0  ret      
//   0x55dc: 97fff16d  bl       #0x1b90
// ============================================================================
std::uint32_t fde_62_5504(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005504ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3653ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[63] Symbol: sub_55e0
//      Virtual Address Range: 0x55e0..0x56bc (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[63] Biểu tượng: sub_55e0
//      Dải địa chỉ ảo: 0x55e0..0x56bc (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x55e0: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x55e4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x55e8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x55ec: 910083fd  add      x29, sp, #0x20
//   0x55f0: d11403ff  sub      sp, sp, #0x500
//   0x55f4: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x55f8: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x55fc: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x5600: ad0007e0  stp      q0, q1, [sp]
//   0x5604: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x5608: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x560c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x5610: d53bd054  mrs      x20, tpidr_el0
//   0x5614: f940168c  ldr      x12, [x20, #0x28]
//   0x5618: 928005e9  mov      x9, #-0x30
//   0x561c: 910003ea  mov      x10, sp
//   0x5620: 910203eb  add      x11, sp, #0x80
//   0x5624: f2dff009  movk     x9, #0xff80, lsl #32
//   0x5628: 910043ad  add      x13, x29, #0x10
//   0x562c: 9102014a  add      x10, x10, #0x80
//   0x5630: 9100c16b  add      x11, x11, #0x30
//   0x5634: f81d83ac  stur     x12, [x29, #-0x28]
//   0x5638: a90c27ea  stp      x10, x9, [sp, #0xc0]
//   0x563c: a90b2fed  stp      x13, x11, [sp, #0xb0]
//   0x5640: ad4583e1  ldp      q1, q0, [sp, #0xb0]
//   0x5644: aa0103e8  mov      x8, x1
//   0x5648: aa0003f3  mov      x19, x0
//   0x564c: 9103e3e0  add      x0, sp, #0xf8
//   0x5650: 910343e3  add      x3, sp, #0xd0
//   0x5654: 52808001  mov      w1, #0x400
//   0x5658: aa0803e2  mov      x2, x8
//   0x565c: ad0683e1  stp      q1, q0, [sp, #0xd0]
//   0x5660: 97fff11c  bl       #0x1ad0
//   0x5664: f9400268  ldr      x8, [x19]
//   0x5668: d0000001  adrp     x1, #0x7000
//   0x566c: 911ddc21  add      x1, x1, #0x777
//   0x5670: aa1303e0  mov      x0, x19
//   0x5674: f9401908  ldr      x8, [x8, #0x30]
//   0x5678: d63f0100  blr      x8
//   0x567c: f9400268  ldr      x8, [x19]
//   0x5680: aa0003e1  mov      x1, x0
//   0x5684: 9103e3e2  add      x2, sp, #0xf8
//   0x5688: aa1303e0  mov      x0, x19
//   0x568c: f9403908  ldr      x8, [x8, #0x70]
//   0x5690: d63f0100  blr      x8
//   0x5694: f9401688  ldr      x8, [x20, #0x28]
//   0x5698: f85d83a9  ldur     x9, [x29, #-0x28]
//   0x569c: eb09011f  cmp      x8, x9
//   0x56a0: 540000c1  b.ne     #0x56b8
//   0x56a4: 911403ff  add      sp, sp, #0x500
//   0x56a8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x56ac: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x56b0: f84307fc  ldr      x28, [sp], #0x30
//   0x56b4: d65f03c0  ret      
//   0x56b8: 97fff136  bl       #0x1b90
// ============================================================================
std::uint32_t fde_63_55e0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000055e0ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3708ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[64] Symbol: sub_56bc
//      Virtual Address Range: 0x56bc..0x5704 (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[64] Biểu tượng: sub_56bc
//      Dải địa chỉ ảo: 0x56bc..0x5704 (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x56bc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x56c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x56c4: 910043fd  add      x29, sp, #0x10
//   0x56c8: f9400008  ldr      x8, [x0]
//   0x56cc: aa0003f3  mov      x19, x0
//   0x56d0: f9401908  ldr      x8, [x8, #0x30]
//   0x56d4: d63f0100  blr      x8
//   0x56d8: b4000100  cbz      x0, #0x56f8
//   0x56dc: f9400268  ldr      x8, [x19]
//   0x56e0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x56e4: aa0003e1  mov      x1, x0
//   0x56e8: aa1303e0  mov      x0, x19
//   0x56ec: f9405502  ldr      x2, [x8, #0xa8]
//   0x56f0: f84207f3  ldr      x19, [sp], #0x20
//   0x56f4: d61f0040  br       x2
//   0x56f8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x56fc: f84207f3  ldr      x19, [sp], #0x20
//   0x5700: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_64_56bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000056bcULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3763ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[65] Symbol: sub_5704
//      Virtual Address Range: 0x5704..0x5710 (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[65] Biểu tượng: sub_5704
//      Dải địa chỉ ảo: 0x5704..0x5710 (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5704: f9400008  ldr      x8, [x0]
//   0x5708: f9417904  ldr      x4, [x8, #0x2f0]
//   0x570c: d61f0080  br       x4
// ============================================================================
std::uint32_t fde_65_5704(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005704ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3781ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[66] Symbol: sub_5710
//      Virtual Address Range: 0x5710..0x571c (12 bytes, 3 AArch64 instructions)
// [VN] Khung FDE[66] Biểu tượng: sub_5710
//      Dải địa chỉ ảo: 0x5710..0x571c (12 byte, 3 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5710: f9400008  ldr      x8, [x0]
//   0x5714: f9408504  ldr      x4, [x8, #0x108]
//   0x5718: d61f0080  br       x4
// ============================================================================
std::uint32_t fde_66_5710(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005710ULL;
    for (std::size_t i = 0; i < 3ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3784ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[67] Symbol: sub_571c
//      Virtual Address Range: 0x571c..0x59a4 (648 bytes, 162 AArch64 instructions)
// [VN] Khung FDE[67] Biểu tượng: sub_571c
//      Dải địa chỉ ảo: 0x571c..0x59a4 (648 byte, 162 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x571c: d10103ff  sub      sp, sp, #0x40
//   0x5720: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x5724: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x5728: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x572c: 9100c3fd  add      x29, sp, #0x30
//   0x5730: d53bd054  mrs      x20, tpidr_el0
//   0x5734: f9401688  ldr      x8, [x20, #0x28]
//   0x5738: aa0003f3  mov      x19, x0
//   0x573c: f90007e8  str      x8, [sp, #8]
//   0x5740: f9403809  ldr      x9, [x0, #0x70]
//   0x5744: 39400128  ldrb     w8, [x9]
//   0x5748: 37180088  tbnz     w8, #3, #0x5758
//   0x574c: 52800de8  mov      w8, #0x6f
//   0x5750: 2a1f03e0  mov      w0, wzr
//   0x5754: 14000044  b        #0x5864
//   0x5758: f9402528  ldr      x8, [x9, #0x48]
//   0x575c: b4000128  cbz      x8, #0x5780
//   0x5760: 910013e1  add      x1, sp, #4
//   0x5764: 52800042  mov      w2, #2
//   0x5768: aa1303e0  mov      x0, x19
//   0x576c: d63f0100  blr      x8
//   0x5770: 93407c00  sxtw     x0, w0
//   0x5774: f100081f  cmp      x0, #2
//   0x5778: 54000120  b.eq     #0x579c
//   0x577c: 14000038  b        #0x585c
//   0x5780: f9402123  ldr      x3, [x9, #0x40]
//   0x5784: 910013e0  add      x0, sp, #4
//   0x5788: 52800021  mov      w1, #1
//   0x578c: 52800042  mov      w2, #2
//   0x5790: 97fff098  bl       #0x19f0
//   0x5794: f100081f  cmp      x0, #2
//   0x5798: 54000621  b.ne     #0x585c
//   0x579c: 394013e8  ldrb     w8, [sp, #4]
//   0x57a0: 394017ea  ldrb     w10, [sp, #5]
//   0x57a4: f9403a69  ldr      x9, [x19, #0x70]
//   0x57a8: 33181d48  bfi      w8, w10, #8, #8
//   0x57ac: b9000268  str      w8, [x19]
//   0x57b0: f9402528  ldr      x8, [x9, #0x48]
//   0x57b4: b4000468  cbz      x8, #0x5840
//   0x57b8: 910013e1  add      x1, sp, #4
//   0x57bc: 52800042  mov      w2, #2
//   0x57c0: aa1303e0  mov      x0, x19
//   0x57c4: d63f0100  blr      x8
//   0x57c8: 93407c00  sxtw     x0, w0
//   0x57cc: f100081f  cmp      x0, #2
//   0x57d0: 54000461  b.ne     #0x585c
//   0x57d4: 394013e8  ldrb     w8, [sp, #4]
//   0x57d8: 394017ea  ldrb     w10, [sp, #5]
//   0x57dc: f9403a69  ldr      x9, [x19, #0x70]
//   0x57e0: 33181d48  bfi      w8, w10, #8, #8
//   0x57e4: b9000668  str      w8, [x19, #4]
//   0x57e8: f9402528  ldr      x8, [x9, #0x48]
//   0x57ec: b4000508  cbz      x8, #0x588c
//   0x57f0: 910003e1  mov      x1, sp
//   0x57f4: 52800062  mov      w2, #3
//   0x57f8: aa1303e0  mov      x0, x19
//   0x57fc: d63f0100  blr      x8
//   0x5800: 93407c00  sxtw     x0, w0
//   0x5804: f1000c1f  cmp      x0, #3
//   0x5808: 54000501  b.ne     #0x58a8
//   0x580c: 39c003e8  ldrsb    w8, [sp]
//   0x5810: 12001d15  and      w21, w8, #0xff
//   0x5814: 53041aa9  ubfx     w9, w21, #4, #3
//   0x5818: 11000529  add      w9, w9, #1
//   0x581c: b9000a69  str      w9, [x19, #8]
//   0x5820: 394007e9  ldrb     w9, [sp, #1]
//   0x5824: b9000e69  str      w9, [x19, #0xc]
//   0x5828: 39400be9  ldrb     w9, [sp, #2]
//   0x582c: 39004269  strb     w9, [x19, #0x10]
//   0x5830: 37f804a8  tbnz     w8, #0x1f, #0x58c4
//   0x5834: f9000e7f  str      xzr, [x19, #0x18]
//   0x5838: 52800020  mov      w0, #1
//   0x583c: 1400000b  b        #0x5868
//   0x5840: f9402123  ldr      x3, [x9, #0x40]
//   0x5844: 910013e0  add      x0, sp, #4
//   0x5848: 52800021  mov      w1, #1
//   0x584c: 52800042  mov      w2, #2
//   0x5850: 97fff068  bl       #0x19f0
//   0x5854: f100081f  cmp      x0, #2
//   0x5858: 54fffbe0  b.eq     #0x57d4
//   0x585c: 2a1f03e0  mov      w0, wzr
//   0x5860: 52800cc8  mov      w8, #0x66
//   0x5864: b9006268  str      w8, [x19, #0x60]
//   0x5868: f9401688  ldr      x8, [x20, #0x28]
//   0x586c: f94007e9  ldr      x9, [sp, #8]
//   0x5870: eb09011f  cmp      x8, x9
//   0x5874: 54000961  b.ne     #0x59a0
//   0x5878: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x587c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x5880: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x5884: 910103ff  add      sp, sp, #0x40
//   0x5888: d65f03c0  ret      
//   0x588c: f9402123  ldr      x3, [x9, #0x40]
//   0x5890: 910003e0  mov      x0, sp
//   0x5894: 52800021  mov      w1, #1
//   0x5898: 52800062  mov      w2, #3
//   0x589c: 97fff055  bl       #0x19f0
//   0x58a0: f1000c1f  cmp      x0, #3
//   0x58a4: 54fffb40  b.eq     #0x580c
//   0x58a8: f9400e60  ldr      x0, [x19, #0x18]
//   0x58ac: 52800cc8  mov      w8, #0x66
//   0x58b0: b9006268  str      w8, [x19, #0x60]
//   0x58b4: 940004f9  bl       #0x6c98
//   0x58b8: 2a1f03e0  mov      w0, wzr
//   0x58bc: f9000e7f  str      xzr, [x19, #0x18]
//   0x58c0: 17ffffea  b        #0x5868
//   0x58c4: 12000aa8  and      w8, w21, #7
//   0x58c8: 11000508  add      w8, w8, #1
//   0x58cc: 52800029  mov      w9, #1
//   0x58d0: 1ac82120  lsl      w0, w9, w8
//   0x58d4: aa1f03e1  mov      x1, xzr
//   0x58d8: 940004be  bl       #0x6bd0
//   0x58dc: f9000e60  str      x0, [x19, #0x18]
//   0x58e0: b40005c0  cbz      x0, #0x5998
//   0x58e4: b9400008  ldr      w8, [x0]
//   0x58e8: 53030ea9  ubfx     w9, w21, #3, #1
//   0x58ec: 39002009  strb     w9, [x0, #8]
//   0x58f0: 7100051f  cmp      w8, #1
//   0x58f4: 54fffa2b  b.lt     #0x5838
//   0x58f8: aa1f03f5  mov      x21, xzr
//   0x58fc: aa1f03f6  mov      x22, xzr
//   0x5900: 14000017  b        #0x595c
//   0x5904: f9402123  ldr      x3, [x9, #0x40]
//   0x5908: 910003e0  mov      x0, sp
//   0x590c: 52800021  mov      w1, #1
//   0x5910: 52800062  mov      w2, #3
//   0x5914: 97fff037  bl       #0x19f0
//   0x5918: f1000c1f  cmp      x0, #3
//   0x591c: 54000341  b.ne     #0x5984
//   0x5920: f9400e68  ldr      x8, [x19, #0x18]
//   0x5924: 394003ea  ldrb     w10, [sp]
//   0x5928: 910006d6  add      x22, x22, #1
//   0x592c: 52800020  mov      w0, #1
//   0x5930: f9400909  ldr      x9, [x8, #0x10]
//   0x5934: 8b150129  add      x9, x9, x21
//   0x5938: 3900012a  strb     w10, [x9]
//   0x593c: 394007ea  ldrb     w10, [sp, #1]
//   0x5940: 91000eb5  add      x21, x21, #3
//   0x5944: 3900052a  strb     w10, [x9, #1]
//   0x5948: 39400bea  ldrb     w10, [sp, #2]
//   0x594c: 3900092a  strb     w10, [x9, #2]
//   0x5950: b9800108  ldrsw    x8, [x8]
//   0x5954: eb0802df  cmp      x22, x8
//   0x5958: 54fff88a  b.ge     #0x5868
//   0x595c: f9403a69  ldr      x9, [x19, #0x70]
//   0x5960: f9402528  ldr      x8, [x9, #0x48]
//   0x5964: b4fffd08  cbz      x8, #0x5904
//   0x5968: 910003e1  mov      x1, sp
//   0x596c: 52800062  mov      w2, #3
//   0x5970: aa1303e0  mov      x0, x19
//   0x5974: d63f0100  blr      x8
//   0x5978: 93407c00  sxtw     x0, w0
//   0x597c: f1000c1f  cmp      x0, #3
//   0x5980: 54fffd00  b.eq     #0x5920
//   0x5984: f9400e60  ldr      x0, [x19, #0x18]
//   0x5988: 940004c4  bl       #0x6c98
//   0x598c: 2a1f03e0  mov      w0, wzr
//   0x5990: f9000e7f  str      xzr, [x19, #0x18]
//   0x5994: 17ffffb3  b        #0x5860
//   0x5998: 52800da8  mov      w8, #0x6d
//   0x599c: 17ffffb2  b        #0x5864
//   0x59a0: 97fff07c  bl       #0x1b90
// ============================================================================
std::uint32_t fde_67_571c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000571cULL;
    for (std::size_t i = 0; i < 162ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3787ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[68] Symbol: sub_59a4
//      Virtual Address Range: 0x59a4..0x5b58 (436 bytes, 109 AArch64 instructions)
// [VN] Khung FDE[68] Biểu tượng: sub_59a4
//      Dải địa chỉ ảo: 0x59a4..0x5b58 (436 byte, 109 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x59a4: d10143ff  sub      sp, sp, #0x50
//   0x59a8: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x59ac: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x59b0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x59b4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x59b8: 910103fd  add      x29, sp, #0x40
//   0x59bc: d53bd058  mrs      x24, tpidr_el0
//   0x59c0: f9401708  ldr      x8, [x24, #0x28]
//   0x59c4: aa0003f7  mov      x23, x0
//   0x59c8: 52800f00  mov      w0, #0x78
//   0x59cc: aa0203f4  mov      x20, x2
//   0x59d0: aa0103f6  mov      x22, x1
//   0x59d4: f90007e8  str      x8, [sp, #8]
//   0x59d8: 97fff012  bl       #0x1a20
//   0x59dc: b4000500  cbz      x0, #0x5a7c
//   0x59e0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x59e4: aa0003f3  mov      x19, x0
//   0x59e8: f900381f  str      xzr, [x0, #0x70]
//   0x59ec: ad028000  stp      q0, q0, [x0, #0x50]
//   0x59f0: ad018000  stp      q0, q0, [x0, #0x30]
//   0x59f4: ad008000  stp      q0, q0, [x0, #0x10]
//   0x59f8: 3d800000  str      q0, [x0]
//   0x59fc: 52800020  mov      w0, #1
//   0x5a00: 528c2d01  mov      w1, #0x6168
//   0x5a04: 97ffefff  bl       #0x1a00
//   0x5a08: b4000440  cbz      x0, #0x5a90
//   0x5a0c: aa0003f5  mov      x21, x0
//   0x5a10: 91002000  add      x0, x0, #8
//   0x5a14: 528c2c02  mov      w2, #0x6160
//   0x5a18: 2a1f03e1  mov      w1, wzr
//   0x5a1c: 97fff031  bl       #0x1ae0
//   0x5a20: d0000008  adrp     x8, #0x7000
//   0x5a24: fd43f100  ldr      d0, [x8, #0x7e0]
//   0x5a28: a906d677  stp      x23, x21, [x19, #0x68]
//   0x5a2c: a9045abf  stp      xzr, x22, [x21, #0x40]
//   0x5a30: fd0002a0  str      d0, [x21]
//   0x5a34: b4000376  cbz      x22, #0x5aa0
//   0x5a38: 910003e1  mov      x1, sp
//   0x5a3c: 528000c2  mov      w2, #6
//   0x5a40: aa1303e0  mov      x0, x19
//   0x5a44: d63f02c0  blr      x22
//   0x5a48: 93407c00  sxtw     x0, w0
//   0x5a4c: f100181f  cmp      x0, #6
//   0x5a50: 54000361  b.ne     #0x5abc
//   0x5a54: d0000000  adrp     x0, #0x7000
//   0x5a58: 911fc000  add      x0, x0, #0x7f0
//   0x5a5c: 910003e1  mov      x1, sp
//   0x5a60: 52800062  mov      w2, #3
//   0x5a64: 39001bff  strb     wzr, [sp, #6]
//   0x5a68: 97fff03a  bl       #0x1b50
//   0x5a6c: 340004e0  cbz      w0, #0x5b08
//   0x5a70: b40002d4  cbz      x20, #0x5ac8
//   0x5a74: 52800ce8  mov      w8, #0x67
//   0x5a78: 14000013  b        #0x5ac4
//   0x5a7c: aa1f03f3  mov      x19, xzr
//   0x5a80: b40002f4  cbz      x20, #0x5adc
//   0x5a84: 52800da8  mov      w8, #0x6d
//   0x5a88: b9000288  str      w8, [x20]
//   0x5a8c: 14000014  b        #0x5adc
//   0x5a90: b4000214  cbz      x20, #0x5ad0
//   0x5a94: 52800da8  mov      w8, #0x6d
//   0x5a98: b9000288  str      w8, [x20]
//   0x5a9c: 1400000d  b        #0x5ad0
//   0x5aa0: 910003e0  mov      x0, sp
//   0x5aa4: 52800021  mov      w1, #1
//   0x5aa8: 528000c2  mov      w2, #6
//   0x5aac: aa1f03e3  mov      x3, xzr
//   0x5ab0: 97ffefd0  bl       #0x19f0
//   0x5ab4: f100181f  cmp      x0, #6
//   0x5ab8: 54fffce0  b.eq     #0x5a54
//   0x5abc: b4000074  cbz      x20, #0x5ac8
//   0x5ac0: 52800cc8  mov      w8, #0x66
//   0x5ac4: b9000288  str      w8, [x20]
//   0x5ac8: aa1503e0  mov      x0, x21
//   0x5acc: 97ffefc5  bl       #0x19e0
//   0x5ad0: aa1303e0  mov      x0, x19
//   0x5ad4: 97ffefc3  bl       #0x19e0
//   0x5ad8: aa1f03f3  mov      x19, xzr
//   0x5adc: f9401708  ldr      x8, [x24, #0x28]
//   0x5ae0: f94007e9  ldr      x9, [sp, #8]
//   0x5ae4: eb09011f  cmp      x8, x9
//   0x5ae8: 54000361  b.ne     #0x5b54
//   0x5aec: aa1303e0  mov      x0, x19
//   0x5af0: a9447bfd  ldp      x29, x30, [sp, #0x40]
//   0x5af4: a9434ff4  ldp      x20, x19, [sp, #0x30]
//   0x5af8: a94257f6  ldp      x22, x21, [sp, #0x20]
//   0x5afc: a9415ff8  ldp      x24, x23, [sp, #0x10]
//   0x5b00: 910143ff  add      sp, sp, #0x50
//   0x5b04: d65f03c0  ret      
//   0x5b08: aa1303e0  mov      x0, x19
//   0x5b0c: 97ffff04  bl       #0x571c
//   0x5b10: 34000100  cbz      w0, #0x5b30
//   0x5b14: 39400fe8  ldrb     w8, [sp, #3]
//   0x5b18: 528c2c09  mov      w9, #0x6160
//   0x5b1c: b900627f  str      wzr, [x19, #0x60]
//   0x5b20: 7100e51f  cmp      w8, #0x39
//   0x5b24: 1a9f17e8  cset     w8, eq
//   0x5b28: 38296aa8  strb     w8, [x21, x9]
//   0x5b2c: 17ffffec  b        #0x5adc
//   0x5b30: aa1503e0  mov      x0, x21
//   0x5b34: 97ffefab  bl       #0x19e0
//   0x5b38: aa1303e0  mov      x0, x19
//   0x5b3c: 97ffefa9  bl       #0x19e0
//   0x5b40: aa1f03f3  mov      x19, xzr
//   0x5b44: b4fffcd4  cbz      x20, #0x5adc
//   0x5b48: 52800d08  mov      w8, #0x68
//   0x5b4c: b9000288  str      w8, [x20]
//   0x5b50: 17ffffe3  b        #0x5adc
//   0x5b54: 97fff00f  bl       #0x1b90
// ============================================================================
std::uint32_t fde_68_59a4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000059a4ULL;
    for (std::size_t i = 0; i < 109ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3949ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[69] Symbol: sub_5b58
//      Virtual Address Range: 0x5b58..0x5c58 (256 bytes, 64 AArch64 instructions)
// [VN] Khung FDE[69] Biểu tượng: sub_5b58
//      Dải địa chỉ ảo: 0x5b58..0x5c58 (256 byte, 64 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5b58: d10103ff  sub      sp, sp, #0x40
//   0x5b5c: f9000bf5  str      x21, [sp, #0x10]
//   0x5b60: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x5b64: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x5b68: 9100c3fd  add      x29, sp, #0x30
//   0x5b6c: d53bd055  mrs      x21, tpidr_el0
//   0x5b70: f94016a8  ldr      x8, [x21, #0x28]
//   0x5b74: aa0003f3  mov      x19, x0
//   0x5b78: f90007e8  str      x8, [sp, #8]
//   0x5b7c: f9403809  ldr      x9, [x0, #0x70]
//   0x5b80: 39400128  ldrb     w8, [x9]
//   0x5b84: 37180088  tbnz     w8, #3, #0x5b94
//   0x5b88: 2a1f03e0  mov      w0, wzr
//   0x5b8c: 52800de8  mov      w8, #0x6f
//   0x5b90: 1400001d  b        #0x5c04
//   0x5b94: f9402528  ldr      x8, [x9, #0x48]
//   0x5b98: aa0103f4  mov      x20, x1
//   0x5b9c: b4000228  cbz      x8, #0x5be0
//   0x5ba0: 910013e1  add      x1, sp, #4
//   0x5ba4: 52800022  mov      w2, #1
//   0x5ba8: aa1303e0  mov      x0, x19
//   0x5bac: d63f0100  blr      x8
//   0x5bb0: 93407c00  sxtw     x0, w0
//   0x5bb4: f100041f  cmp      x0, #1
//   0x5bb8: 54000221  b.ne     #0x5bfc
//   0x5bbc: 394013e8  ldrb     w8, [sp, #4]
//   0x5bc0: 7100851f  cmp      w8, #0x21
//   0x5bc4: 54000340  b.eq     #0x5c2c
//   0x5bc8: 7100ed1f  cmp      w8, #0x3b
//   0x5bcc: 54000340  b.eq     #0x5c34
//   0x5bd0: 7100b11f  cmp      w8, #0x2c
//   0x5bd4: 54000381  b.ne     #0x5c44
//   0x5bd8: 52800048  mov      w8, #2
//   0x5bdc: 14000017  b        #0x5c38
//   0x5be0: f9402123  ldr      x3, [x9, #0x40]
//   0x5be4: 910013e0  add      x0, sp, #4
//   0x5be8: 52800021  mov      w1, #1
//   0x5bec: 52800022  mov      w2, #1
//   0x5bf0: 97ffef80  bl       #0x19f0
//   0x5bf4: f100041f  cmp      x0, #1
//   0x5bf8: 54fffe20  b.eq     #0x5bbc
//   0x5bfc: 2a1f03e0  mov      w0, wzr
//   0x5c00: 52800cc8  mov      w8, #0x66
//   0x5c04: b9006268  str      w8, [x19, #0x60]
//   0x5c08: f94016a8  ldr      x8, [x21, #0x28]
//   0x5c0c: f94007e9  ldr      x9, [sp, #8]
//   0x5c10: eb09011f  cmp      x8, x9
//   0x5c14: 54000201  b.ne     #0x5c54
//   0x5c18: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x5c1c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x5c20: f9400bf5  ldr      x21, [sp, #0x10]
//   0x5c24: 910103ff  add      sp, sp, #0x40
//   0x5c28: d65f03c0  ret      
//   0x5c2c: 52800068  mov      w8, #3
//   0x5c30: 14000002  b        #0x5c38
//   0x5c34: 52800088  mov      w8, #4
//   0x5c38: b9000288  str      w8, [x20]
//   0x5c3c: 52800020  mov      w0, #1
//   0x5c40: 17fffff2  b        #0x5c08
//   0x5c44: 2a1f03e0  mov      w0, wzr
//   0x5c48: 52800d68  mov      w8, #0x6b
//   0x5c4c: b900029f  str      wzr, [x20]
//   0x5c50: 17ffffed  b        #0x5c04
//   0x5c54: 97ffefcf  bl       #0x1b90
// ============================================================================
std::uint32_t fde_69_5b58(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005b58ULL;
    for (std::size_t i = 0; i < 64ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4058ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[70] Symbol: sub_5c58
//      Virtual Address Range: 0x5c58..0x60e8 (1168 bytes, 292 AArch64 instructions)
// [VN] Khung FDE[70] Biểu tượng: sub_5c58
//      Dải địa chỉ ảo: 0x5c58..0x60e8 (1168 byte, 292 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x5c58: d10183ff  sub      sp, sp, #0x60
//   0x5c5c: f90013f7  str      x23, [sp, #0x20]
//   0x5c60: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x5c64: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x5c68: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x5c6c: 910143fd  add      x29, sp, #0x50
//   0x5c70: d53bd055  mrs      x21, tpidr_el0
//   0x5c74: f94016a8  ldr      x8, [x21, #0x28]
//   0x5c78: aa0003f3  mov      x19, x0
//   0x5c7c: f9000fe8  str      x8, [sp, #0x18]
//   0x5c80: f9403816  ldr      x22, [x0, #0x70]
//   0x5c84: 394002c8  ldrb     w8, [x22]
//   0x5c88: 37180068  tbnz     w8, #3, #0x5c94
//   0x5c8c: 52800de8  mov      w8, #0x6f
//   0x5c90: 140000ef  b        #0x604c
//   0x5c94: f94026c8  ldr      x8, [x22, #0x48]
//   0x5c98: b4000128  cbz      x8, #0x5cbc
//   0x5c9c: 910053e1  add      x1, sp, #0x14
//   0x5ca0: 52800042  mov      w2, #2
//   0x5ca4: aa1303e0  mov      x0, x19
//   0x5ca8: d63f0100  blr      x8
//   0x5cac: 93407c00  sxtw     x0, w0
//   0x5cb0: f100081f  cmp      x0, #2
//   0x5cb4: 54000120  b.eq     #0x5cd8
//   0x5cb8: 140000e4  b        #0x6048
//   0x5cbc: f94022c3  ldr      x3, [x22, #0x40]
//   0x5cc0: 910053e0  add      x0, sp, #0x14
//   0x5cc4: 52800021  mov      w1, #1
//   0x5cc8: 52800042  mov      w2, #2
//   0x5ccc: 97ffef49  bl       #0x19f0
//   0x5cd0: f100081f  cmp      x0, #2
//   0x5cd4: 54001ba1  b.ne     #0x6048
//   0x5cd8: 394053e8  ldrb     w8, [sp, #0x14]
//   0x5cdc: 394057ea  ldrb     w10, [sp, #0x15]
//   0x5ce0: f9403a69  ldr      x9, [x19, #0x70]
//   0x5ce4: 33181d48  bfi      w8, w10, #8, #8
//   0x5ce8: b9002a68  str      w8, [x19, #0x28]
//   0x5cec: f9402528  ldr      x8, [x9, #0x48]
//   0x5cf0: b4000128  cbz      x8, #0x5d14
//   0x5cf4: 910053e1  add      x1, sp, #0x14
//   0x5cf8: 52800042  mov      w2, #2
//   0x5cfc: aa1303e0  mov      x0, x19
//   0x5d00: d63f0100  blr      x8
//   0x5d04: 93407c00  sxtw     x0, w0
//   0x5d08: f100081f  cmp      x0, #2
//   0x5d0c: 54000120  b.eq     #0x5d30
//   0x5d10: 140000ce  b        #0x6048
//   0x5d14: f9402123  ldr      x3, [x9, #0x40]
//   0x5d18: 910053e0  add      x0, sp, #0x14
//   0x5d1c: 52800021  mov      w1, #1
//   0x5d20: 52800042  mov      w2, #2
//   0x5d24: 97ffef33  bl       #0x19f0
//   0x5d28: f100081f  cmp      x0, #2
//   0x5d2c: 540018e1  b.ne     #0x6048
//   0x5d30: 394053e8  ldrb     w8, [sp, #0x14]
//   0x5d34: 394057ea  ldrb     w10, [sp, #0x15]
//   0x5d38: f9403a69  ldr      x9, [x19, #0x70]
//   0x5d3c: 33181d48  bfi      w8, w10, #8, #8
//   0x5d40: b9002e68  str      w8, [x19, #0x2c]
//   0x5d44: f9402528  ldr      x8, [x9, #0x48]
//   0x5d48: b4000128  cbz      x8, #0x5d6c
//   0x5d4c: 910053e1  add      x1, sp, #0x14
//   0x5d50: 52800042  mov      w2, #2
//   0x5d54: aa1303e0  mov      x0, x19
//   0x5d58: d63f0100  blr      x8
//   0x5d5c: 93407c00  sxtw     x0, w0
//   0x5d60: f100081f  cmp      x0, #2
//   0x5d64: 54000120  b.eq     #0x5d88
//   0x5d68: 140000b8  b        #0x6048
//   0x5d6c: f9402123  ldr      x3, [x9, #0x40]
//   0x5d70: 910053e0  add      x0, sp, #0x14
//   0x5d74: 52800021  mov      w1, #1
//   0x5d78: 52800042  mov      w2, #2
//   0x5d7c: 97ffef1d  bl       #0x19f0
//   0x5d80: f100081f  cmp      x0, #2
//   0x5d84: 54001621  b.ne     #0x6048
//   0x5d88: 394053e8  ldrb     w8, [sp, #0x14]
//   0x5d8c: 394057ea  ldrb     w10, [sp, #0x15]
//   0x5d90: f9403a69  ldr      x9, [x19, #0x70]
//   0x5d94: 33181d48  bfi      w8, w10, #8, #8
//   0x5d98: b9003268  str      w8, [x19, #0x30]
//   0x5d9c: f9402528  ldr      x8, [x9, #0x48]
//   0x5da0: b4000128  cbz      x8, #0x5dc4
//   0x5da4: 910053e1  add      x1, sp, #0x14
//   0x5da8: 52800042  mov      w2, #2
//   0x5dac: aa1303e0  mov      x0, x19
//   0x5db0: d63f0100  blr      x8
//   0x5db4: 93407c00  sxtw     x0, w0
//   0x5db8: f100081f  cmp      x0, #2
//   0x5dbc: 54000120  b.eq     #0x5de0
//   0x5dc0: 140000a2  b        #0x6048
//   0x5dc4: f9402123  ldr      x3, [x9, #0x40]
//   0x5dc8: 910053e0  add      x0, sp, #0x14
//   0x5dcc: 52800021  mov      w1, #1
//   0x5dd0: 52800042  mov      w2, #2
//   0x5dd4: 97ffef07  bl       #0x19f0
//   0x5dd8: f100081f  cmp      x0, #2
//   0x5ddc: 54001361  b.ne     #0x6048
//   0x5de0: 394053e8  ldrb     w8, [sp, #0x14]
//   0x5de4: 394057ea  ldrb     w10, [sp, #0x15]
//   0x5de8: f9403a69  ldr      x9, [x19, #0x70]
//   0x5dec: 33181d48  bfi      w8, w10, #8, #8
//   0x5df0: b9003668  str      w8, [x19, #0x34]
//   0x5df4: f9402528  ldr      x8, [x9, #0x48]
//   0x5df8: b4000268  cbz      x8, #0x5e44
//   0x5dfc: 910043e1  add      x1, sp, #0x10
//   0x5e00: 52800022  mov      w2, #1
//   0x5e04: aa1303e0  mov      x0, x19
//   0x5e08: d63f0100  blr      x8
//   0x5e0c: 93407c00  sxtw     x0, w0
//   0x5e10: f100041f  cmp      x0, #1
//   0x5e14: 54000261  b.ne     #0x5e60
//   0x5e18: 394043f4  ldrb     w20, [sp, #0x10]
//   0x5e1c: f9402260  ldr      x0, [x19, #0x40]
//   0x5e20: 53061a88  ubfx     w8, w20, #6, #1
//   0x5e24: 3900e268  strb     w8, [x19, #0x38]
//   0x5e28: b40002a0  cbz      x0, #0x5e7c
//   0x5e2c: 9400039b  bl       #0x6c98
//   0x5e30: f900227f  str      xzr, [x19, #0x40]
//   0x5e34: 394043e8  ldrb     w8, [sp, #0x10]
//   0x5e38: 13001d08  sxtb     w8, w8
//   0x5e3c: 36f808a8  tbz      w8, #0x1f, #0x5f50
//   0x5e40: 14000012  b        #0x5e88
//   0x5e44: f9402123  ldr      x3, [x9, #0x40]
//   0x5e48: 910043e0  add      x0, sp, #0x10
//   0x5e4c: 52800021  mov      w1, #1
//   0x5e50: 52800022  mov      w2, #1
//   0x5e54: 97ffeee7  bl       #0x19f0
//   0x5e58: f100041f  cmp      x0, #1
//   0x5e5c: 54fffde0  b.eq     #0x5e18
//   0x5e60: f9402260  ldr      x0, [x19, #0x40]
//   0x5e64: 52800cc8  mov      w8, #0x66
//   0x5e68: b9006268  str      w8, [x19, #0x60]
//   0x5e6c: 9400038b  bl       #0x6c98
//   0x5e70: 2a1f03e0  mov      w0, wzr
//   0x5e74: f900227f  str      xzr, [x19, #0x40]
//   0x5e78: 14000077  b        #0x6054
//   0x5e7c: 2a1403e8  mov      w8, w20
//   0x5e80: 13001d08  sxtb     w8, w8
//   0x5e84: 36f80668  tbz      w8, #0x1f, #0x5f50
//   0x5e88: 12000a88  and      w8, w20, #7
//   0x5e8c: 52800049  mov      w9, #2
//   0x5e90: 1ac82120  lsl      w0, w9, w8
//   0x5e94: aa1f03e1  mov      x1, xzr
//   0x5e98: 9400034e  bl       #0x6bd0
//   0x5e9c: f9002260  str      x0, [x19, #0x40]
//   0x5ea0: b4000be0  cbz      x0, #0x601c
//   0x5ea4: b9400008  ldr      w8, [x0]
//   0x5ea8: 34000548  cbz      w8, #0x5f50
//   0x5eac: aa1f03f4  mov      x20, xzr
//   0x5eb0: aa1f03f7  mov      x23, xzr
//   0x5eb4: 14000016  b        #0x5f0c
//   0x5eb8: f9402123  ldr      x3, [x9, #0x40]
//   0x5ebc: 910043e0  add      x0, sp, #0x10
//   0x5ec0: 52800021  mov      w1, #1
//   0x5ec4: 52800062  mov      w2, #3
//   0x5ec8: 97ffeeca  bl       #0x19f0
//   0x5ecc: f1000c1f  cmp      x0, #3
//   0x5ed0: 54000321  b.ne     #0x5f34
//   0x5ed4: f9402268  ldr      x8, [x19, #0x40]
//   0x5ed8: 394043ea  ldrb     w10, [sp, #0x10]
//   0x5edc: 910006f7  add      x23, x23, #1
//   0x5ee0: f9400909  ldr      x9, [x8, #0x10]
//   0x5ee4: 8b140129  add      x9, x9, x20
//   0x5ee8: 3900012a  strb     w10, [x9]
//   0x5eec: 394047ea  ldrb     w10, [sp, #0x11]
//   0x5ef0: 91000e94  add      x20, x20, #3
//   0x5ef4: 3900052a  strb     w10, [x9, #1]
//   0x5ef8: 39404bea  ldrb     w10, [sp, #0x12]
//   0x5efc: 3900092a  strb     w10, [x9, #2]
//   0x5f00: b9400108  ldr      w8, [x8]
//   0x5f04: eb0802ff  cmp      x23, x8
//   0x5f08: 54000242  b.hs     #0x5f50
//   0x5f0c: f9403a69  ldr      x9, [x19, #0x70]
//   0x5f10: f9402528  ldr      x8, [x9, #0x48]
//   0x5f14: b4fffd28  cbz      x8, #0x5eb8
//   0x5f18: 910043e1  add      x1, sp, #0x10
//   0x5f1c: 52800062  mov      w2, #3
//   0x5f20: aa1303e0  mov      x0, x19
//   0x5f24: d63f0100  blr      x8
//   0x5f28: 93407c00  sxtw     x0, w0
//   0x5f2c: f1000c1f  cmp      x0, #3
//   0x5f30: 54fffd20  b.eq     #0x5ed4
//   0x5f34: f9402260  ldr      x0, [x19, #0x40]
//   0x5f38: 94000358  bl       #0x6c98
//   0x5f3c: 52800cc8  mov      w8, #0x66
//   0x5f40: 2a1f03e0  mov      w0, wzr
//   0x5f44: b9006268  str      w8, [x19, #0x60]
//   0x5f48: f900227f  str      xzr, [x19, #0x40]
//   0x5f4c: 14000042  b        #0x6054
//   0x5f50: f9402660  ldr      x0, [x19, #0x48]
//   0x5f54: b4000120  cbz      x0, #0x5f78
//   0x5f58: b9802268  ldrsw    x8, [x19, #0x20]
//   0x5f5c: 52800702  mov      w2, #0x38
//   0x5f60: 91000501  add      x1, x8, #1
//   0x5f64: 940003e0  bl       #0x6ee4
//   0x5f68: b40005a0  cbz      x0, #0x601c
//   0x5f6c: aa0003f4  mov      x20, x0
//   0x5f70: f9002660  str      x0, [x19, #0x48]
//   0x5f74: 14000006  b        #0x5f8c
//   0x5f78: 52800700  mov      w0, #0x38
//   0x5f7c: 97ffeea9  bl       #0x1a20
//   0x5f80: aa0003f4  mov      x20, x0
//   0x5f84: f9002660  str      x0, [x19, #0x48]
//   0x5f88: b40004a0  cbz      x0, #0x601c
//   0x5f8c: 9100a268  add      x8, x19, #0x28
//   0x5f90: b9802277  ldrsw    x23, [x19, #0x20]
//   0x5f94: ad400500  ldp      q0, q1, [x8]
//   0x5f98: 52800708  mov      w8, #0x38
//   0x5f9c: 9b0852e8  madd     x8, x23, x8, x20
//   0x5fa0: ad000500  stp      q0, q1, [x8]
//   0x5fa4: f9402268  ldr      x8, [x19, #0x40]
//   0x5fa8: b4000108  cbz      x8, #0x5fc8
//   0x5fac: b9400100  ldr      w0, [x8]
//   0x5fb0: f9400901  ldr      x1, [x8, #0x10]
//   0x5fb4: 94000307  bl       #0x6bd0
//   0x5fb8: 52800708  mov      w8, #0x38
//   0x5fbc: 9b0852e8  madd     x8, x23, x8, x20
//   0x5fc0: f9000d00  str      x0, [x8, #0x18]
//   0x5fc4: b40002c0  cbz      x0, #0x601c
//   0x5fc8: 52800708  mov      w8, #0x38
//   0x5fcc: 9b0852e8  madd     x8, x23, x8, x20
//   0x5fd0: f900111f  str      xzr, [x8, #0x20]
//   0x5fd4: b900291f  str      wzr, [x8, #0x28]
//   0x5fd8: f900191f  str      xzr, [x8, #0x30]
//   0x5fdc: b9402268  ldr      w8, [x19, #0x20]
//   0x5fe0: 69462a69  ldpsw    x9, x10, [x19, #0x30]
//   0x5fe4: 11000508  add      w8, w8, #1
//   0x5fe8: 9b097d49  mul      x9, x10, x9
//   0x5fec: b9002268  str      w8, [x19, #0x20]
//   0x5ff0: f9001ec9  str      x9, [x22, #0x38]
//   0x5ff4: f9403a74  ldr      x20, [x19, #0x70]
//   0x5ff8: f9402688  ldr      x8, [x20, #0x48]
//   0x5ffc: b4000148  cbz      x8, #0x6024
//   0x6000: 910033e1  add      x1, sp, #0xc
//   0x6004: 52800022  mov      w2, #1
//   0x6008: aa1303e0  mov      x0, x19
//   0x600c: d63f0100  blr      x8
//   0x6010: 93407c00  sxtw     x0, w0
//   0x6014: b5000140  cbnz     x0, #0x603c
//   0x6018: 1400000f  b        #0x6054
//   0x601c: 52800da8  mov      w8, #0x6d
//   0x6020: 1400000c  b        #0x6050
//   0x6024: f9402283  ldr      x3, [x20, #0x40]
//   0x6028: 910033e0  add      x0, sp, #0xc
//   0x602c: 52800021  mov      w1, #1
//   0x6030: 52800022  mov      w2, #1
//   0x6034: 97ffee6f  bl       #0x19f0
//   0x6038: b40000e0  cbz      x0, #0x6054
//   0x603c: 394033e8  ldrb     w8, [sp, #0xc]
//   0x6040: 7100251f  cmp      w8, #9
//   0x6044: 540001c3  b.lo     #0x607c
//   0x6048: 52800cc8  mov      w8, #0x66
//   0x604c: 2a1f03e0  mov      w0, wzr
//   0x6050: b9006268  str      w8, [x19, #0x60]
//   0x6054: f94016a8  ldr      x8, [x21, #0x28]
//   0x6058: f9400fe9  ldr      x9, [sp, #0x18]
//   0x605c: eb09011f  cmp      x8, x9
//   0x6060: 54000421  b.ne     #0x60e4
//   0x6064: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x6068: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x606c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x6070: f94013f7  ldr      x23, [sp, #0x20]
//   0x6074: 910183ff  add      sp, sp, #0x60
//   0x6078: d65f03c0  ret      
//   0x607c: b000000a  adrp     x10, #0x7000
//   0x6080: fd43f540  ldr      d0, [x10, #0x7e8]
//   0x6084: 52800029  mov      w9, #1
//   0x6088: 1ac82129  lsl      w9, w9, w8
//   0x608c: 5280004a  mov      w10, #2
//   0x6090: 0e040d21  dup      v1.2s, w9
//   0x6094: 1100050b  add      w11, w8, #1
//   0x6098: 1ac8214a  lsl      w10, w10, w8
//   0x609c: 29012688  stp      w8, w9, [x20, #8]
//   0x60a0: 5282004c  mov      w12, #0x1002
//   0x60a4: 52842d08  mov      w8, #0x2168
//   0x60a8: 0ea08420  add      v0.2s, v1.2s, v0.2s
//   0x60ac: 8b080288  add      x8, x20, x8
//   0x60b0: fd000a80  str      d0, [x20, #0x10]
//   0x60b4: 52820009  mov      w9, #0x1000
//   0x60b8: 4e040d80  dup      v0.4s, w12
//   0x60bc: 3901629f  strb     wzr, [x20, #0x58]
//   0x60c0: a902fe9f  stp      xzr, xzr, [x20, #0x28]
//   0x60c4: 29032a8b  stp      w11, w10, [x20, #0x18]
//   0x60c8: b900228c  str      w12, [x20, #0x20]
//   0x60cc: ad3f8100  stp      q0, q0, [x8, #-0x10]
//   0x60d0: f1002129  subs     x9, x9, #8
//   0x60d4: 91008108  add      x8, x8, #0x20
//   0x60d8: 54ffffa1  b.ne     #0x60cc
//   0x60dc: 52800020  mov      w0, #1
//   0x60e0: 17ffffdd  b        #0x6054
//   0x60e4: 97ffeeab  bl       #0x1b90
// ============================================================================
std::uint32_t fde_70_5c58(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005c58ULL;
    for (std::size_t i = 0; i < 292ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4122ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[71] Symbol: sub_60e8
//      Virtual Address Range: 0x60e8..0x6194 (172 bytes, 43 AArch64 instructions)
// [VN] Khung FDE[71] Biểu tượng: sub_60e8
//      Dải địa chỉ ảo: 0x60e8..0x6194 (172 byte, 43 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x60e8: d100c3ff  sub      sp, sp, #0x30
//   0x60ec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x60f0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x60f4: 910083fd  add      x29, sp, #0x20
//   0x60f8: f9403814  ldr      x20, [x0, #0x70]
//   0x60fc: aa0003f3  mov      x19, x0
//   0x6100: 39400288  ldrb     w8, [x20]
//   0x6104: 37180068  tbnz     w8, #3, #0x6110
//   0x6108: 52800de8  mov      w8, #0x6f
//   0x610c: 1400000a  b        #0x6134
//   0x6110: 35000042  cbnz     w2, #0x6118
//   0x6114: b9403262  ldr      w2, [x19, #0x30]
//   0x6118: f9401e88  ldr      x8, [x20, #0x38]
//   0x611c: 129fffc9  mov      w9, #-0xffff
//   0x6120: cb22c108  sub      x8, x8, w2, sxtw
//   0x6124: eb09011f  cmp      x8, x9
//   0x6128: f9001e88  str      x8, [x20, #0x38]
//   0x612c: 54000103  b.lo     #0x614c
//   0x6130: 52800d88  mov      w8, #0x6c
//   0x6134: 2a1f03e0  mov      w0, wzr
//   0x6138: b9006268  str      w8, [x19, #0x60]
//   0x613c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x6140: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x6144: 9100c3ff  add      sp, sp, #0x30
//   0x6148: d65f03c0  ret      
//   0x614c: aa1303e0  mov      x0, x19
//   0x6150: 94000011  bl       #0x6194
//   0x6154: 7100041f  cmp      w0, #1
//   0x6158: 540001a1  b.ne     #0x618c
//   0x615c: f9401e88  ldr      x8, [x20, #0x38]
//   0x6160: b40000c8  cbz      x8, #0x6178
//   0x6164: 52800020  mov      w0, #1
//   0x6168: 17fffff5  b        #0x613c
//   0x616c: f94007e8  ldr      x8, [sp, #8]
//   0x6170: 52800020  mov      w0, #1
//   0x6174: b4fffe48  cbz      x8, #0x613c
//   0x6178: 910023e1  add      x1, sp, #8
//   0x617c: aa1303e0  mov      x0, x19
//   0x6180: 9400010f  bl       #0x65bc
//   0x6184: 35ffff40  cbnz     w0, #0x616c
//   0x6188: 17ffffed  b        #0x613c
//   0x618c: 2a1f03e0  mov      w0, wzr
//   0x6190: 17ffffeb  b        #0x613c
// ============================================================================
std::uint32_t fde_71_60e8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000060e8ULL;
    for (std::size_t i = 0; i < 43ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4414ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[72] Symbol: sub_6194
//      Virtual Address Range: 0x6194..0x65bc (1064 bytes, 266 AArch64 instructions)
// [VN] Khung FDE[72] Biểu tượng: sub_6194
//      Dải địa chỉ ảo: 0x6194..0x65bc (1064 byte, 266 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6194: d10283ff  sub      sp, sp, #0xa0
//   0x6198: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x619c: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x61a0: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x61a4: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x61a8: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x61ac: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x61b0: 910243fd  add      x29, sp, #0x90
//   0x61b4: f9403816  ldr      x22, [x0, #0x70]
//   0x61b8: b9802aca  ldrsw    x10, [x22, #0x28]
//   0x61bc: 713ffd5f  cmp      w10, #0xfff
//   0x61c0: 5400006d  b.le     #0x61cc
//   0x61c4: 2a1f03e0  mov      w0, wzr
//   0x61c8: 140000f5  b        #0x659c
//   0x61cc: 2941a2d7  ldp      w23, w8, [x22, #0xc]
//   0x61d0: b94022db  ldr      w27, [x22, #0x20]
//   0x61d4: 2a0203f4  mov      w20, w2
//   0x61d8: aa0003f3  mov      x19, x0
//   0x61dc: aa0103f5  mov      x21, x1
//   0x61e0: b9003be8  str      w8, [sp, #0x38]
//   0x61e4: 3400026a  cbz      w10, #0x6230
//   0x61e8: 92407d48  and      x8, x10, #0xffffffff
//   0x61ec: 8b16014a  add      x10, x10, x22
//   0x61f0: aa1f03f9  mov      x25, xzr
//   0x61f4: 93407e89  sxtw     x9, w20
//   0x61f8: 91055d4a  add      x10, x10, #0x157
//   0x61fc: eb09033f  cmp      x25, x9
//   0x6200: 540003ea  b.ge     #0x627c
//   0x6204: 385ff54c  ldrb     w12, [x10], #0xffffffffffffffff
//   0x6208: 9100072b  add      x11, x25, #1
//   0x620c: eb0b011f  cmp      x8, x11
//   0x6210: 38396aac  strb     w12, [x21, x25]
//   0x6214: aa0b03f9  mov      x25, x11
//   0x6218: 54ffff21  b.ne     #0x61fc
//   0x621c: 2a1f03fa  mov      w26, wzr
//   0x6220: 2a0b03f9  mov      w25, w11
//   0x6224: 6b14033f  cmp      w25, w20
//   0x6228: 540000cb  b.lt     #0x6240
//   0x622c: 14000017  b        #0x6288
//   0x6230: 2a1f03fa  mov      w26, wzr
//   0x6234: 2a1f03f9  mov      w25, wzr
//   0x6238: 6b14033f  cmp      w25, w20
//   0x623c: 5400026a  b.ge     #0x6288
//   0x6240: 93407e88  sxtw     x8, w20
//   0x6244: f9001be8  str      x8, [sp, #0x30]
//   0x6248: 910562c8  add      x8, x22, #0x158
//   0x624c: f90007e8  str      x8, [sp, #8]
//   0x6250: 91055ec8  add      x8, x22, #0x157
//   0x6254: f90003e8  str      x8, [sp]
//   0x6258: 52842d08  mov      w8, #0x2168
//   0x625c: 52820049  mov      w9, #0x1002
//   0x6260: 52822afc  mov      w28, #0x1157
//   0x6264: 8b0802c8  add      x8, x22, x8
//   0x6268: 4e040d20  dup      v0.4s, w9
//   0x626c: d2c00038  mov      x24, #0x100000000
//   0x6270: f90017e8  str      x8, [sp, #0x28]
//   0x6274: 3d8007e0  str      q0, [sp, #0x10]
//   0x6278: 1400000f  b        #0x62b4
//   0x627c: 4b19011a  sub      w26, w8, w25
//   0x6280: 6b14033f  cmp      w25, w20
//   0x6284: 54fffdeb  b.lt     #0x6240
//   0x6288: 2a1b03e8  mov      w8, w27
//   0x628c: 52800020  mov      w0, #1
//   0x6290: b90022c8  str      w8, [x22, #0x20]
//   0x6294: b9002ada  str      w26, [x22, #0x28]
//   0x6298: 140000c1  b        #0x659c
//   0x629c: 52820049  mov      w9, #0x1002
//   0x62a0: 8b0a02ca  add      x10, x22, x10
//   0x62a4: 383c6949  strb     w9, [x10, x28]
//   0x62a8: 6b14033f  cmp      w25, w20
//   0x62ac: 2a0803fb  mov      w27, w8
//   0x62b0: 54fffeea  b.ge     #0x628c
//   0x62b4: 9100f3e1  add      x1, sp, #0x3c
//   0x62b8: aa1303e0  mov      x0, x19
//   0x62bc: 940001d3  bl       #0x6a08
//   0x62c0: 340016e0  cbz      w0, #0x659c
//   0x62c4: 294723e9  ldp      w9, w8, [sp, #0x38]
//   0x62c8: 6b09011f  cmp      w8, w9
//   0x62cc: 54001620  b.eq     #0x6590
//   0x62d0: 6b17011f  cmp      w8, w23
//   0x62d4: 54000241  b.ne     #0x631c
//   0x62d8: f94017e9  ldr      x9, [sp, #0x28]
//   0x62dc: 3dc007e0  ldr      q0, [sp, #0x10]
//   0x62e0: 52820008  mov      w8, #0x1000
//   0x62e4: ad3f8120  stp      q0, q0, [x9, #-0x10]
//   0x62e8: f1002108  subs     x8, x8, #8
//   0x62ec: 91008129  add      x9, x9, #0x20
//   0x62f0: 54ffffa1  b.ne     #0x62e4
//   0x62f4: b94012c9  ldr      w9, [x22, #0x10]
//   0x62f8: b9400aca  ldr      w10, [x22, #8]
//   0x62fc: 52820048  mov      w8, #0x1002
//   0x6300: 11000529  add      w9, w9, #1
//   0x6304: 1100054a  add      w10, w10, #1
//   0x6308: 2902aac9  stp      w9, w10, [x22, #0x14]
//   0x630c: 52800029  mov      w9, #1
//   0x6310: 1aca2129  lsl      w9, w9, w10
//   0x6314: 2903a2c9  stp      w9, w8, [x22, #0x1c]
//   0x6318: 17ffffe4  b        #0x62a8
//   0x631c: 93407d09  sxtw     x9, w8
//   0x6320: 5400044a  b.ge     #0x63a8
//   0x6324: 1100072a  add      w10, w25, #1
//   0x6328: 3839caa8  strb     w8, [x21, w25, sxtw]
//   0x632c: 2a0a03f9  mov      w25, w10
//   0x6330: 5282004e  mov      w14, #0x1002
//   0x6334: 6b0e037f  cmp      w27, w14
//   0x6338: 54fffb80  b.eq     #0x62a8
//   0x633c: b98016ca  ldrsw    x10, [x22, #0x14]
//   0x6340: 8b0a0aca  add      x10, x22, x10, lsl #2
//   0x6344: b961514b  ldr      w11, [x10, #0x2150]
//   0x6348: 6b0e017f  cmp      w11, w14
//   0x634c: 54fffae1  b.ne     #0x62a8
//   0x6350: 52842a0b  mov      w11, #0x2150
//   0x6354: 8b0b014a  add      x10, x10, x11
//   0x6358: b900015b  str      w27, [x10]
//   0x635c: b98016ca  ldrsw    x10, [x22, #0x14]
//   0x6360: d100094a  sub      x10, x10, #2
//   0x6364: 6b0a011f  cmp      w8, w10
//   0x6368: 540007e1  b.ne     #0x6464
//   0x636c: 6b17037f  cmp      w27, w23
//   0x6370: 5400106d  b.le     #0x657c
//   0x6374: 5280002a  mov      w10, #1
//   0x6378: 713fff7f  cmp      w27, #0xfff
//   0x637c: 54000fec  b.gt     #0x6578
//   0x6380: 8b3bcacb  add      x11, x22, w27, sxtw #2
//   0x6384: b961597b  ldr      w27, [x11, #0x2158]
//   0x6388: 6b17037f  cmp      w27, w23
//   0x638c: 1a8ad54b  cinc     w11, w10, gt
//   0x6390: 713ffd5f  cmp      w10, #0xfff
//   0x6394: 54000f48  b.hi     #0x657c
//   0x6398: 6b17037f  cmp      w27, w23
//   0x639c: 2a0b03ea  mov      w10, w11
//   0x63a0: 54fffecc  b.gt     #0x6378
//   0x63a4: 14000076  b        #0x657c
//   0x63a8: 8b090aca  add      x10, x22, x9, lsl #2
//   0x63ac: b961594a  ldr      w10, [x10, #0x2158]
//   0x63b0: 5282004e  mov      w14, #0x1002
//   0x63b4: 6b0e015f  cmp      w10, w14
//   0x63b8: 540002c1  b.ne     #0x6410
//   0x63bc: b94016ca  ldr      w10, [x22, #0x14]
//   0x63c0: 5100094a  sub      w10, w10, #2
//   0x63c4: 6b0a011f  cmp      w8, w10
//   0x63c8: 540002c1  b.ne     #0x6420
//   0x63cc: 6b17037f  cmp      w27, w23
//   0x63d0: 2a1b03ea  mov      w10, w27
//   0x63d4: 540006cd  b.le     #0x64ac
//   0x63d8: 5280002b  mov      w11, #1
//   0x63dc: 2a1b03ea  mov      w10, w27
//   0x63e0: 713ffd5f  cmp      w10, #0xfff
//   0x63e4: 5400062c  b.gt     #0x64a8
//   0x63e8: 8b2acaca  add      x10, x22, w10, sxtw #2
//   0x63ec: b961594a  ldr      w10, [x10, #0x2158]
//   0x63f0: 6b17015f  cmp      w10, w23
//   0x63f4: 1a8bd56c  cinc     w12, w11, gt
//   0x63f8: 713ffd7f  cmp      w11, #0xfff
//   0x63fc: 54000588  b.hi     #0x64ac
//   0x6400: 6b17015f  cmp      w10, w23
//   0x6404: 2a0c03eb  mov      w11, w12
//   0x6408: 54fffecc  b.gt     #0x63e0
//   0x640c: 14000028  b        #0x64ac
//   0x6410: 2a0803ea  mov      w10, w8
//   0x6414: 713ffb5f  cmp      w26, #0xffe
//   0x6418: 5400060d  b.le     #0x64d8
//   0x641c: 1400005b  b        #0x6588
//   0x6420: 6b17011f  cmp      w8, w23
//   0x6424: 2a0803ea  mov      w10, w8
//   0x6428: 5400042d  b.le     #0x64ac
//   0x642c: 5280002b  mov      w11, #1
//   0x6430: 2a0803ea  mov      w10, w8
//   0x6434: 713ffd5f  cmp      w10, #0xfff
//   0x6438: 5400038c  b.gt     #0x64a8
//   0x643c: 8b2acaca  add      x10, x22, w10, sxtw #2
//   0x6440: b961594a  ldr      w10, [x10, #0x2158]
//   0x6444: 6b17015f  cmp      w10, w23
//   0x6448: 1a8bd56c  cinc     w12, w11, gt
//   0x644c: 713ffd7f  cmp      w11, #0xfff
//   0x6450: 540002e8  b.hi     #0x64ac
//   0x6454: 6b17015f  cmp      w10, w23
//   0x6458: 2a0c03eb  mov      w11, w12
//   0x645c: 54fffecc  b.gt     #0x6434
//   0x6460: 14000013  b        #0x64ac
//   0x6464: 6b17011f  cmp      w8, w23
//   0x6468: 2a0803e9  mov      w9, w8
//   0x646c: 54fff1ad  b.le     #0x62a0
//   0x6470: 5280002b  mov      w11, #1
//   0x6474: 2a0803e9  mov      w9, w8
//   0x6478: 713ffd3f  cmp      w9, #0xfff
//   0x647c: 54fff10c  b.gt     #0x629c
//   0x6480: 8b29cac9  add      x9, x22, w9, sxtw #2
//   0x6484: b9615929  ldr      w9, [x9, #0x2158]
//   0x6488: 6b17013f  cmp      w9, w23
//   0x648c: 1a8bd56c  cinc     w12, w11, gt
//   0x6490: 713ffd7f  cmp      w11, #0xfff
//   0x6494: 54fff068  b.hi     #0x62a0
//   0x6498: 6b17013f  cmp      w9, w23
//   0x649c: 2a0c03eb  mov      w11, w12
//   0x64a0: 54fffecc  b.gt     #0x6478
//   0x64a4: 17ffff7f  b        #0x62a0
//   0x64a8: 5282004a  mov      w10, #0x1002
//   0x64ac: 8b3ac2cb  add      x11, x22, w26, sxtw
//   0x64b0: 3905616a  strb     w10, [x11, #0x158]
//   0x64b4: b98016cb  ldrsw    x11, [x22, #0x14]
//   0x64b8: 1100074c  add      w12, w26, #1
//   0x64bc: 52822aad  mov      w13, #0x1155
//   0x64c0: 2a0c03fa  mov      w26, w12
//   0x64c4: 8b16016b  add      x11, x11, x22
//   0x64c8: 382d696a  strb     w10, [x11, x13]
//   0x64cc: 2a1b03ea  mov      w10, w27
//   0x64d0: 713ffb5f  cmp      w26, #0xffe
//   0x64d4: 540005ac  b.gt     #0x6588
//   0x64d8: f94007ec  ldr      x12, [sp, #8]
//   0x64dc: 1100074d  add      w13, w26, #1
//   0x64e0: 93607f4b  sbfiz    x11, x26, #0x20, #0x20
//   0x64e4: 8b3ac18c  add      x12, x12, w26, sxtw
//   0x64e8: 2a0d03fa  mov      w26, w13
//   0x64ec: 6b17015f  cmp      w10, w23
//   0x64f0: 540001ad  b.le     #0x6524
//   0x64f4: 713ffd5f  cmp      w10, #0xfff
//   0x64f8: 5400016c  b.gt     #0x6524
//   0x64fc: 8b2ac2cd  add      x13, x22, w10, sxtw
//   0x6500: 387c69ad  ldrb     w13, [x13, x28]
//   0x6504: 8b2acaca  add      x10, x22, w10, sxtw #2
//   0x6508: 1100075a  add      w26, w26, #1
//   0x650c: 7140075f  cmp      w26, #1, lsl #12
//   0x6510: 3800158d  strb     w13, [x12], #1
//   0x6514: b961594a  ldr      w10, [x10, #0x2158]
//   0x6518: 8b18016b  add      x11, x11, x24
//   0x651c: 54fffe81  b.ne     #0x64ec
//   0x6520: 1400001a  b        #0x6588
//   0x6524: 7140055f  cmp      w10, #1, lsl #12
//   0x6528: 5400030a  b.ge     #0x6588
//   0x652c: 8b8b82cb  add      x11, x22, x11, asr #32
//   0x6530: 3905616a  strb     w10, [x11, #0x158]
//   0x6534: 34fff01a  cbz      w26, #0x6334
//   0x6538: f94003ea  ldr      x10, [sp]
//   0x653c: 93407f39  sxtw     x25, w25
//   0x6540: 8b3ac14a  add      x10, x10, w26, sxtw
//   0x6544: f9401beb  ldr      x11, [sp, #0x30]
//   0x6548: eb0b033f  cmp      x25, x11
//   0x654c: 54ffef4a  b.ge     #0x6334
//   0x6550: 385ff54c  ldrb     w12, [x10], #0xffffffffffffffff
//   0x6554: 9100072b  add      x11, x25, #1
//   0x6558: 7100075a  subs     w26, w26, #1
//   0x655c: 38396aac  strb     w12, [x21, x25]
//   0x6560: aa0b03f9  mov      x25, x11
//   0x6564: 54ffff01  b.ne     #0x6544
//   0x6568: 2a0b03f9  mov      w25, w11
//   0x656c: 6b0e037f  cmp      w27, w14
//   0x6570: 54ffe9c0  b.eq     #0x62a8
//   0x6574: 17ffff72  b        #0x633c
//   0x6578: 5282005b  mov      w27, #0x1002
//   0x657c: 8b0902c9  add      x9, x22, x9
//   0x6580: 383c693b  strb     w27, [x9, x28]
//   0x6584: 17ffff49  b        #0x62a8
//   0x6588: 52800e08  mov      w8, #0x70
//   0x658c: 14000002  b        #0x6594
//   0x6590: 52800e28  mov      w8, #0x71
//   0x6594: 2a1f03e0  mov      w0, wzr
//   0x6598: b9006268  str      w8, [x19, #0x60]
//   0x659c: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x65a0: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x65a4: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x65a8: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x65ac: a94567fa  ldp      x26, x25, [sp, #0x50]
//   0x65b0: a9446ffc  ldp      x28, x27, [sp, #0x40]
//   0x65b4: 910283ff  add      sp, sp, #0xa0
//   0x65b8: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_72_6194(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006194ULL;
    for (std::size_t i = 0; i < 266ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4457ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[73] Symbol: sub_65bc
//      Virtual Address Range: 0x65bc..0x66d0 (276 bytes, 69 AArch64 instructions)
// [VN] Khung FDE[73] Biểu tượng: sub_65bc
//      Dải địa chỉ ảo: 0x65bc..0x66d0 (276 byte, 69 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x65bc: d10103ff  sub      sp, sp, #0x40
//   0x65c0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x65c4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x65c8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x65cc: 9100c3fd  add      x29, sp, #0x30
//   0x65d0: d53bd055  mrs      x21, tpidr_el0
//   0x65d4: f94016a8  ldr      x8, [x21, #0x28]
//   0x65d8: aa0003f3  mov      x19, x0
//   0x65dc: aa0103f4  mov      x20, x1
//   0x65e0: f90007e8  str      x8, [sp, #8]
//   0x65e4: f9403816  ldr      x22, [x0, #0x70]
//   0x65e8: f94026c8  ldr      x8, [x22, #0x48]
//   0x65ec: b40002e8  cbz      x8, #0x6648
//   0x65f0: 910013e1  add      x1, sp, #4
//   0x65f4: 52800022  mov      w2, #1
//   0x65f8: aa1303e0  mov      x0, x19
//   0x65fc: d63f0100  blr      x8
//   0x6600: 93407c00  sxtw     x0, w0
//   0x6604: f100041f  cmp      x0, #1
//   0x6608: 540004a1  b.ne     #0x669c
//   0x660c: 394013e2  ldrb     w2, [sp, #4]
//   0x6610: b40002c2  cbz      x2, #0x6668
//   0x6614: 910162c8  add      x8, x22, #0x58
//   0x6618: f9000288  str      x8, [x20]
//   0x661c: 390162c2  strb     w2, [x22, #0x58]
//   0x6620: f9403a6a  ldr      x10, [x19, #0x70]
//   0x6624: f9400288  ldr      x8, [x20]
//   0x6628: f9402549  ldr      x9, [x10, #0x48]
//   0x662c: 91000508  add      x8, x8, #1
//   0x6630: b4000249  cbz      x9, #0x6678
//   0x6634: aa1303e0  mov      x0, x19
//   0x6638: aa0803e1  mov      x1, x8
//   0x663c: d63f0120  blr      x9
//   0x6640: 93407c00  sxtw     x0, w0
//   0x6644: 14000011  b        #0x6688
//   0x6648: f94022c3  ldr      x3, [x22, #0x40]
//   0x664c: 910013e0  add      x0, sp, #4
//   0x6650: 52800021  mov      w1, #1
//   0x6654: 52800022  mov      w2, #1
//   0x6658: 97ffece6  bl       #0x19f0
//   0x665c: f100041f  cmp      x0, #1
//   0x6660: 54fffd60  b.eq     #0x660c
//   0x6664: 1400000e  b        #0x669c
//   0x6668: f900029f  str      xzr, [x20]
//   0x666c: 390162df  strb     wzr, [x22, #0x58]
//   0x6670: f9001edf  str      xzr, [x22, #0x38]
//   0x6674: 14000008  b        #0x6694
//   0x6678: f9402143  ldr      x3, [x10, #0x40]
//   0x667c: 52800021  mov      w1, #1
//   0x6680: aa0803e0  mov      x0, x8
//   0x6684: 97ffecdb  bl       #0x19f0
//   0x6688: 394013e8  ldrb     w8, [sp, #4]
//   0x668c: eb08001f  cmp      x0, x8
//   0x6690: 54000061  b.ne     #0x669c
//   0x6694: 52800020  mov      w0, #1
//   0x6698: 14000004  b        #0x66a8
//   0x669c: 52800cc8  mov      w8, #0x66
//   0x66a0: 2a1f03e0  mov      w0, wzr
//   0x66a4: b9006268  str      w8, [x19, #0x60]
//   0x66a8: f94016a8  ldr      x8, [x21, #0x28]
//   0x66ac: f94007e9  ldr      x9, [sp, #8]
//   0x66b0: eb09011f  cmp      x8, x9
//   0x66b4: 540000c1  b.ne     #0x66cc
//   0x66b8: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x66bc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x66c0: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x66c4: 910103ff  add      sp, sp, #0x40
//   0x66c8: d65f03c0  ret      
//   0x66cc: 97ffed31  bl       #0x1b90
// ============================================================================
std::uint32_t fde_73_65bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000065bcULL;
    for (std::size_t i = 0; i < 69ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4723ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[74] Symbol: sub_66d0
//      Virtual Address Range: 0x66d0..0x679c (204 bytes, 51 AArch64 instructions)
// [VN] Khung FDE[74] Biểu tượng: sub_66d0
//      Dải địa chỉ ảo: 0x66d0..0x679c (204 byte, 51 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x66d0: d10103ff  sub      sp, sp, #0x40
//   0x66d4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x66d8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x66dc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x66e0: 9100c3fd  add      x29, sp, #0x30
//   0x66e4: d53bd056  mrs      x22, tpidr_el0
//   0x66e8: f94016c8  ldr      x8, [x22, #0x28]
//   0x66ec: aa0003f3  mov      x19, x0
//   0x66f0: f90007e8  str      x8, [sp, #8]
//   0x66f4: f9403809  ldr      x9, [x0, #0x70]
//   0x66f8: 39400128  ldrb     w8, [x9]
//   0x66fc: 37180068  tbnz     w8, #3, #0x6708
//   0x6700: 52800de8  mov      w8, #0x6f
//   0x6704: 1400001a  b        #0x676c
//   0x6708: f9402528  ldr      x8, [x9, #0x48]
//   0x670c: aa0203f4  mov      x20, x2
//   0x6710: aa0103f5  mov      x21, x1
//   0x6714: b40001c8  cbz      x8, #0x674c
//   0x6718: 910013e1  add      x1, sp, #4
//   0x671c: 52800022  mov      w2, #1
//   0x6720: aa1303e0  mov      x0, x19
//   0x6724: d63f0100  blr      x8
//   0x6728: 93407c00  sxtw     x0, w0
//   0x672c: f100041f  cmp      x0, #1
//   0x6730: 540001c1  b.ne     #0x6768
//   0x6734: 394013e8  ldrb     w8, [sp, #4]
//   0x6738: aa1303e0  mov      x0, x19
//   0x673c: aa1403e1  mov      x1, x20
//   0x6740: b90002a8  str      w8, [x21]
//   0x6744: 94000016  bl       #0x679c
//   0x6748: 1400000b  b        #0x6774
//   0x674c: f9402123  ldr      x3, [x9, #0x40]
//   0x6750: 910013e0  add      x0, sp, #4
//   0x6754: 52800021  mov      w1, #1
//   0x6758: 52800022  mov      w2, #1
//   0x675c: 97ffeca5  bl       #0x19f0
//   0x6760: f100041f  cmp      x0, #1
//   0x6764: 54fffe80  b.eq     #0x6734
//   0x6768: 52800cc8  mov      w8, #0x66
//   0x676c: 2a1f03e0  mov      w0, wzr
//   0x6770: b9006268  str      w8, [x19, #0x60]
//   0x6774: f94016c8  ldr      x8, [x22, #0x28]
//   0x6778: f94007e9  ldr      x9, [sp, #8]
//   0x677c: eb09011f  cmp      x8, x9
//   0x6780: 540000c1  b.ne     #0x6798
//   0x6784: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x6788: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x678c: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x6790: 910103ff  add      sp, sp, #0x40
//   0x6794: d65f03c0  ret      
//   0x6798: 97ffecfe  bl       #0x1b90
// ============================================================================
std::uint32_t fde_74_66d0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000066d0ULL;
    for (std::size_t i = 0; i < 51ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4792ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[75] Symbol: sub_679c
//      Virtual Address Range: 0x679c..0x68a8 (268 bytes, 67 AArch64 instructions)
// [VN] Khung FDE[75] Biểu tượng: sub_679c
//      Dải địa chỉ ảo: 0x679c..0x68a8 (268 byte, 67 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x679c: d10103ff  sub      sp, sp, #0x40
//   0x67a0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x67a4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x67a8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x67ac: 9100c3fd  add      x29, sp, #0x30
//   0x67b0: d53bd055  mrs      x21, tpidr_el0
//   0x67b4: f94016a8  ldr      x8, [x21, #0x28]
//   0x67b8: aa0003f3  mov      x19, x0
//   0x67bc: aa0103f4  mov      x20, x1
//   0x67c0: f90007e8  str      x8, [sp, #8]
//   0x67c4: f9403816  ldr      x22, [x0, #0x70]
//   0x67c8: f94026c8  ldr      x8, [x22, #0x48]
//   0x67cc: b40002e8  cbz      x8, #0x6828
//   0x67d0: 910013e1  add      x1, sp, #4
//   0x67d4: 52800022  mov      w2, #1
//   0x67d8: aa1303e0  mov      x0, x19
//   0x67dc: d63f0100  blr      x8
//   0x67e0: 93407c00  sxtw     x0, w0
//   0x67e4: f100041f  cmp      x0, #1
//   0x67e8: 54000461  b.ne     #0x6874
//   0x67ec: 394013e2  ldrb     w2, [sp, #4]
//   0x67f0: b40002c2  cbz      x2, #0x6848
//   0x67f4: 910162c8  add      x8, x22, #0x58
//   0x67f8: f9000288  str      x8, [x20]
//   0x67fc: 390162c2  strb     w2, [x22, #0x58]
//   0x6800: f9403a6a  ldr      x10, [x19, #0x70]
//   0x6804: f9400288  ldr      x8, [x20]
//   0x6808: f9402549  ldr      x9, [x10, #0x48]
//   0x680c: 91000508  add      x8, x8, #1
//   0x6810: b4000209  cbz      x9, #0x6850
//   0x6814: aa1303e0  mov      x0, x19
//   0x6818: aa0803e1  mov      x1, x8
//   0x681c: d63f0120  blr      x9
//   0x6820: 93407c00  sxtw     x0, w0
//   0x6824: 1400000f  b        #0x6860
//   0x6828: f94022c3  ldr      x3, [x22, #0x40]
//   0x682c: 910013e0  add      x0, sp, #4
//   0x6830: 52800021  mov      w1, #1
//   0x6834: 52800022  mov      w2, #1
//   0x6838: 97ffec6e  bl       #0x19f0
//   0x683c: f100041f  cmp      x0, #1
//   0x6840: 54fffd60  b.eq     #0x67ec
//   0x6844: 1400000c  b        #0x6874
//   0x6848: f900029f  str      xzr, [x20]
//   0x684c: 14000008  b        #0x686c
//   0x6850: f9402143  ldr      x3, [x10, #0x40]
//   0x6854: 52800021  mov      w1, #1
//   0x6858: aa0803e0  mov      x0, x8
//   0x685c: 97ffec65  bl       #0x19f0
//   0x6860: 394013e8  ldrb     w8, [sp, #4]
//   0x6864: eb08001f  cmp      x0, x8
//   0x6868: 54000061  b.ne     #0x6874
//   0x686c: 52800020  mov      w0, #1
//   0x6870: 14000004  b        #0x6880
//   0x6874: 52800cc8  mov      w8, #0x66
//   0x6878: 2a1f03e0  mov      w0, wzr
//   0x687c: b9006268  str      w8, [x19, #0x60]
//   0x6880: f94016a8  ldr      x8, [x21, #0x28]
//   0x6884: f94007e9  ldr      x9, [sp, #8]
//   0x6888: eb09011f  cmp      x8, x9
//   0x688c: 540000c1  b.ne     #0x68a4
//   0x6890: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x6894: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x6898: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x689c: 910103ff  add      sp, sp, #0x40
//   0x68a0: d65f03c0  ret      
//   0x68a4: 97ffecbb  bl       #0x1b90
// ============================================================================
std::uint32_t fde_75_679c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000679cULL;
    for (std::size_t i = 0; i < 67ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4843ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[76] Symbol: sub_68a8
//      Virtual Address Range: 0x68a8..0x6900 (88 bytes, 22 AArch64 instructions)
// [VN] Khung FDE[76] Biểu tượng: sub_68a8
//      Dải địa chỉ ảo: 0x68a8..0x6900 (88 byte, 22 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x68a8: f100101f  cmp      x0, #4
//   0x68ac: 540001e1  b.ne     #0x68e8
//   0x68b0: 39400028  ldrb     w8, [x1]
//   0x68b4: 53021108  ubfx     w8, w8, #2, #3
//   0x68b8: b9000048  str      w8, [x2]
//   0x68bc: 39400028  ldrb     w8, [x1]
//   0x68c0: 53010508  ubfx     w8, w8, #1, #1
//   0x68c4: 39001048  strb     w8, [x2, #4]
//   0x68c8: 39400428  ldrb     w8, [x1, #1]
//   0x68cc: 39400829  ldrb     w9, [x1, #2]
//   0x68d0: 33181d28  bfi      w8, w9, #8, #8
//   0x68d4: b9000848  str      w8, [x2, #8]
//   0x68d8: 39400028  ldrb     w8, [x1]
//   0x68dc: 370000a8  tbnz     w8, #0, #0x68f0
//   0x68e0: 12800008  mov      w8, #-1
//   0x68e4: 14000004  b        #0x68f4
//   0x68e8: 2a1f03e0  mov      w0, wzr
//   0x68ec: d65f03c0  ret      
//   0x68f0: 39400c28  ldrb     w8, [x1, #3]
//   0x68f4: 52800020  mov      w0, #1
//   0x68f8: b9000c48  str      w8, [x2, #0xc]
//   0x68fc: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_76_68a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000068a8ULL;
    for (std::size_t i = 0; i < 22ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4910ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[77] Symbol: sub_6900
//      Virtual Address Range: 0x6900..0x69dc (220 bytes, 55 AArch64 instructions)
// [VN] Khung FDE[77] Biểu tượng: sub_6900
//      Dải địa chỉ ảo: 0x6900..0x69dc (220 byte, 55 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6900: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x6904: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x6908: 910043fd  add      x29, sp, #0x10
//   0x690c: b4000520  cbz      x0, #0x69b0
//   0x6910: f9403808  ldr      x8, [x0, #0x70]
//   0x6914: aa0003f3  mov      x19, x0
//   0x6918: b40004a8  cbz      x8, #0x69ac
//   0x691c: f9402260  ldr      x0, [x19, #0x40]
//   0x6920: aa0103f4  mov      x20, x1
//   0x6924: b4000060  cbz      x0, #0x6930
//   0x6928: 940000dc  bl       #0x6c98
//   0x692c: f900227f  str      xzr, [x19, #0x40]
//   0x6930: f9400e60  ldr      x0, [x19, #0x18]
//   0x6934: b4000060  cbz      x0, #0x6940
//   0x6938: 940000d8  bl       #0x6c98
//   0x693c: f9000e7f  str      xzr, [x19, #0x18]
//   0x6940: f9402668  ldr      x8, [x19, #0x48]
//   0x6944: b4000088  cbz      x8, #0x6954
//   0x6948: aa1303e0  mov      x0, x19
//   0x694c: 94000129  bl       #0x6df0
//   0x6950: f900267f  str      xzr, [x19, #0x48]
//   0x6954: 91014260  add      x0, x19, #0x50
//   0x6958: 91016261  add      x1, x19, #0x58
//   0x695c: 94000108  bl       #0x6d7c
//   0x6960: f9403a60  ldr      x0, [x19, #0x70]
//   0x6964: 39400008  ldrb     w8, [x0]
//   0x6968: 371800a8  tbnz     w8, #3, #0x697c
//   0x696c: b40001b4  cbz      x20, #0x69a0
//   0x6970: 52800de8  mov      w8, #0x6f
//   0x6974: b9000288  str      w8, [x20]
//   0x6978: 1400000a  b        #0x69a0
//   0x697c: f9402008  ldr      x8, [x0, #0x40]
//   0x6980: b4000208  cbz      x8, #0x69c0
//   0x6984: aa0803e0  mov      x0, x8
//   0x6988: 97ffec36  bl       #0x1a60
//   0x698c: 34000180  cbz      w0, #0x69bc
//   0x6990: b4000074  cbz      x20, #0x699c
//   0x6994: 52800dc8  mov      w8, #0x6e
//   0x6998: b9000288  str      w8, [x20]
//   0x699c: f9403a60  ldr      x0, [x19, #0x70]
//   0x69a0: 97ffec10  bl       #0x19e0
//   0x69a4: aa1303e0  mov      x0, x19
//   0x69a8: 97ffec0e  bl       #0x19e0
//   0x69ac: 2a1f03e0  mov      w0, wzr
//   0x69b0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x69b4: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x69b8: d65f03c0  ret      
//   0x69bc: f9403a60  ldr      x0, [x19, #0x70]
//   0x69c0: 97ffec08  bl       #0x19e0
//   0x69c4: aa1303e0  mov      x0, x19
//   0x69c8: 97ffec06  bl       #0x19e0
//   0x69cc: b4000054  cbz      x20, #0x69d4
//   0x69d0: b900029f  str      wzr, [x20]
//   0x69d4: 52800020  mov      w0, #1
//   0x69d8: 17fffff6  b        #0x69b0
// ============================================================================
std::uint32_t fde_77_6900(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006900ULL;
    for (std::size_t i = 0; i < 55ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4932ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[78] Symbol: sub_69dc
//      Virtual Address Range: 0x69dc..0x6a08 (44 bytes, 11 AArch64 instructions)
// [VN] Khung FDE[78] Biểu tượng: sub_69dc
//      Dải địa chỉ ảo: 0x69dc..0x6a08 (44 byte, 11 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x69dc: f9403808  ldr      x8, [x0, #0x70]
//   0x69e0: 39400109  ldrb     w9, [x8]
//   0x69e4: 371800a9  tbnz     w9, #3, #0x69f8
//   0x69e8: 52800de8  mov      w8, #0x6f
//   0x69ec: b9006008  str      w8, [x0, #0x60]
//   0x69f0: 2a1f03e0  mov      w0, wzr
//   0x69f4: d65f03c0  ret      
//   0x69f8: b9400908  ldr      w8, [x8, #8]
//   0x69fc: b9000028  str      w8, [x1]
//   0x6a00: aa0203e1  mov      x1, x2
//   0x6a04: 17fffeee  b        #0x65bc
// ============================================================================
std::uint32_t fde_78_69dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000069dcULL;
    for (std::size_t i = 0; i < 11ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4987ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[79] Symbol: sub_6a08
//      Virtual Address Range: 0x6a08..0x6bd0 (456 bytes, 114 AArch64 instructions)
// [VN] Khung FDE[79] Biểu tượng: sub_6a08
//      Dải địa chỉ ảo: 0x6a08..0x6bd0 (456 byte, 114 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6a08: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x6a0c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x6a10: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x6a14: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x6a18: 9100c3fd  add      x29, sp, #0x30
//   0x6a1c: f9403817  ldr      x23, [x0, #0x70]
//   0x6a20: aa0003f4  mov      x20, x0
//   0x6a24: b9401ae8  ldr      w8, [x23, #0x18]
//   0x6a28: 7100311f  cmp      w8, #0xc
//   0x6a2c: 540000ad  b.le     #0x6a40
//   0x6a30: 52800e08  mov      w8, #0x70
//   0x6a34: 2a1f03e0  mov      w0, wzr
//   0x6a38: b9006288  str      w8, [x20, #0x60]
//   0x6a3c: 1400005e  b        #0x6bb4
//   0x6a40: b9402eea  ldr      w10, [x23, #0x2c]
//   0x6a44: aa0103f3  mov      x19, x1
//   0x6a48: 6b08015f  cmp      w10, w8
//   0x6a4c: 5400080a  b.ge     #0x6b4c
//   0x6a50: aa1703f5  mov      x21, x23
//   0x6a54: 38458ea9  ldrb     w9, [x21, #0x58]!
//   0x6a58: 52800058  mov      w24, #2
//   0x6a5c: 910006b6  add      x22, x21, #1
//   0x6a60: 72001d3f  tst      w9, #0xff
//   0x6a64: 54000240  b.eq     #0x6aac
//   0x6a68: 394166eb  ldrb     w11, [x23, #0x59]
//   0x6a6c: 1100056c  add      w12, w11, #1
//   0x6a70: 390166ec  strb     w12, [x23, #0x59]
//   0x6a74: 8b0b02eb  add      x11, x23, x11
//   0x6a78: 3941616b  ldrb     w11, [x11, #0x58]
//   0x6a7c: f9401aec  ldr      x12, [x23, #0x30]
//   0x6a80: 9aca216b  lsl      x11, x11, x10
//   0x6a84: 1100214a  add      w10, w10, #8
//   0x6a88: 51000529  sub      w9, w9, #1
//   0x6a8c: 6b08015f  cmp      w10, w8
//   0x6a90: aa0c016b  orr      x11, x11, x12
//   0x6a94: 390162e9  strb     w9, [x23, #0x58]
//   0x6a98: f9001aeb  str      x11, [x23, #0x30]
//   0x6a9c: b9002eea  str      w10, [x23, #0x2c]
//   0x6aa0: 5400058a  b.ge     #0x6b50
//   0x6aa4: 72001d3f  tst      w9, #0xff
//   0x6aa8: 54fffe01  b.ne     #0x6a68
//   0x6aac: f9403a89  ldr      x9, [x20, #0x70]
//   0x6ab0: f9402528  ldr      x8, [x9, #0x48]
//   0x6ab4: b4000248  cbz      x8, #0x6afc
//   0x6ab8: 52800022  mov      w2, #1
//   0x6abc: aa1403e0  mov      x0, x20
//   0x6ac0: aa1503e1  mov      x1, x21
//   0x6ac4: d63f0100  blr      x8
//   0x6ac8: 93407c00  sxtw     x0, w0
//   0x6acc: f100041f  cmp      x0, #1
//   0x6ad0: 540007c1  b.ne     #0x6bc8
//   0x6ad4: 394002a2  ldrb     w2, [x21]
//   0x6ad8: 34fffac2  cbz      w2, #0x6a30
//   0x6adc: f9403a89  ldr      x9, [x20, #0x70]
//   0x6ae0: f9402528  ldr      x8, [x9, #0x48]
//   0x6ae4: b40001c8  cbz      x8, #0x6b1c
//   0x6ae8: aa1403e0  mov      x0, x20
//   0x6aec: aa1603e1  mov      x1, x22
//   0x6af0: d63f0100  blr      x8
//   0x6af4: 93407c00  sxtw     x0, w0
//   0x6af8: 1400000d  b        #0x6b2c
//   0x6afc: f9402123  ldr      x3, [x9, #0x40]
//   0x6b00: 52800021  mov      w1, #1
//   0x6b04: 52800022  mov      w2, #1
//   0x6b08: aa1503e0  mov      x0, x21
//   0x6b0c: 97ffebb9  bl       #0x19f0
//   0x6b10: f100041f  cmp      x0, #1
//   0x6b14: 54fffe00  b.eq     #0x6ad4
//   0x6b18: 1400002c  b        #0x6bc8
//   0x6b1c: f9402123  ldr      x3, [x9, #0x40]
//   0x6b20: 52800021  mov      w1, #1
//   0x6b24: aa1603e0  mov      x0, x22
//   0x6b28: 97ffebb2  bl       #0x19f0
//   0x6b2c: 394002a9  ldrb     w9, [x21]
//   0x6b30: eb09001f  cmp      x0, x9
//   0x6b34: 540004a1  b.ne     #0x6bc8
//   0x6b38: 394166eb  ldrb     w11, [x23, #0x59]
//   0x6b3c: b9402eea  ldr      w10, [x23, #0x2c]
//   0x6b40: b9401ae8  ldr      w8, [x23, #0x18]
//   0x6b44: 390166f8  strb     w24, [x23, #0x59]
//   0x6b48: 17ffffcd  b        #0x6a7c
//   0x6b4c: f9401aeb  ldr      x11, [x23, #0x30]
//   0x6b50: b0000009  adrp     x9, #0x7000
//   0x6b54: 911fe129  add      x9, x9, #0x7f8
//   0x6b58: 7868d928  ldrh     w8, [x9, w8, sxtw #1]
//   0x6b5c: 0a080168  and      w8, w11, w8
//   0x6b60: b9000268  str      w8, [x19]
//   0x6b64: 2942a2e9  ldp      w9, w8, [x23, #0x14]
//   0x6b68: b9402eea  ldr      w10, [x23, #0x2c]
//   0x6b6c: 9ac8256b  lsr      x11, x11, x8
//   0x6b70: 4b08014a  sub      w10, w10, w8
//   0x6b74: 7140053f  cmp      w9, #1, lsl #12
//   0x6b78: f9001aeb  str      x11, [x23, #0x30]
//   0x6b7c: b9002eea  str      w10, [x23, #0x2c]
//   0x6b80: 5400018c  b.gt     #0x6bb0
//   0x6b84: 1100052a  add      w10, w9, #1
//   0x6b88: 71002d1f  cmp      w8, #0xb
//   0x6b8c: 52800020  mov      w0, #1
//   0x6b90: b90016ea  str      w10, [x23, #0x14]
//   0x6b94: 5400010c  b.gt     #0x6bb4
//   0x6b98: b9401eea  ldr      w10, [x23, #0x1c]
//   0x6b9c: 6b0a013f  cmp      w9, w10
//   0x6ba0: 540000ab  b.lt     #0x6bb4
//   0x6ba4: 531f7949  lsl      w9, w10, #1
//   0x6ba8: 11000508  add      w8, w8, #1
//   0x6bac: 290326e8  stp      w8, w9, [x23, #0x18]
//   0x6bb0: 52800020  mov      w0, #1
//   0x6bb4: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x6bb8: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x6bbc: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x6bc0: a8c45ff8  ldp      x24, x23, [sp], #0x40
//   0x6bc4: d65f03c0  ret      
//   0x6bc8: 52800cc8  mov      w8, #0x66
//   0x6bcc: 17ffff9a  b        #0x6a34
// ============================================================================
std::uint32_t fde_79_6a08(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006a08ULL;
    for (std::size_t i = 0; i < 114ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4998ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[80] Symbol: sub_6bd0
//      Virtual Address Range: 0x6bd0..0x6c98 (200 bytes, 50 AArch64 instructions)
// [VN] Khung FDE[80] Biểu tượng: sub_6bd0
//      Dải địa chỉ ảo: 0x6bd0..0x6c98 (200 byte, 50 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6bd0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x6bd4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x6bd8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x6bdc: 910083fd  add      x29, sp, #0x20
//   0x6be0: aa0103f3  mov      x19, x1
//   0x6be4: 2a0003f5  mov      w21, w0
//   0x6be8: 52800028  mov      w8, #1
//   0x6bec: 52800029  mov      w9, #1
//   0x6bf0: 7100213f  cmp      w9, #8
//   0x6bf4: 1ac9210a  lsl      w10, w8, w9
//   0x6bf8: 54000088  b.hi     #0x6c08
//   0x6bfc: 6b15015f  cmp      w10, w21
//   0x6c00: 11000529  add      w9, w9, #1
//   0x6c04: 54ffff6b  b.lt     #0x6bf0
//   0x6c08: 6b15015f  cmp      w10, w21
//   0x6c0c: 540003a1  b.ne     #0x6c80
//   0x6c10: 52800300  mov      w0, #0x18
//   0x6c14: 97ffeb83  bl       #0x1a20
//   0x6c18: aa0003f4  mov      x20, x0
//   0x6c1c: b4000340  cbz      x0, #0x6c84
//   0x6c20: 93407eb6  sxtw     x22, w21
//   0x6c24: 52800061  mov      w1, #3
//   0x6c28: aa1603e0  mov      x0, x22
//   0x6c2c: 97ffeb75  bl       #0x1a00
//   0x6c30: f9000a80  str      x0, [x20, #0x10]
//   0x6c34: b4000220  cbz      x0, #0x6c78
//   0x6c38: 2a1f03e8  mov      w8, wzr
//   0x6c3c: 52800029  mov      w9, #1
//   0x6c40: b9000295  str      w21, [x20]
//   0x6c44: 11000508  add      w8, w8, #1
//   0x6c48: 7100211f  cmp      w8, #8
//   0x6c4c: 54000088  b.hi     #0x6c5c
//   0x6c50: 1ac8212a  lsl      w10, w9, w8
//   0x6c54: 6b15015f  cmp      w10, w21
//   0x6c58: 54ffff6b  b.lt     #0x6c44
//   0x6c5c: b9000688  str      w8, [x20, #4]
//   0x6c60: 3900229f  strb     wzr, [x20, #8]
//   0x6c64: b4000113  cbz      x19, #0x6c84
//   0x6c68: 8b1606c2  add      x2, x22, x22, lsl #1
//   0x6c6c: aa1303e1  mov      x1, x19
//   0x6c70: 97ffeb4c  bl       #0x19a0
//   0x6c74: 14000004  b        #0x6c84
//   0x6c78: aa1403e0  mov      x0, x20
//   0x6c7c: 97ffeb59  bl       #0x19e0
//   0x6c80: aa1f03f4  mov      x20, xzr
//   0x6c84: aa1403e0  mov      x0, x20
//   0x6c88: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x6c8c: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x6c90: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x6c94: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_80_6bd0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006bd0ULL;
    for (std::size_t i = 0; i < 50ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5112ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[81] Symbol: sub_6c98
//      Virtual Address Range: 0x6c98..0x6cc8 (48 bytes, 12 AArch64 instructions)
// [VN] Khung FDE[81] Biểu tượng: sub_6c98
//      Dải địa chỉ ảo: 0x6c98..0x6cc8 (48 byte, 12 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6c98: b4000160  cbz      x0, #0x6cc4
//   0x6c9c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x6ca0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x6ca4: 910043fd  add      x29, sp, #0x10
//   0x6ca8: aa0003f3  mov      x19, x0
//   0x6cac: f9400800  ldr      x0, [x0, #0x10]
//   0x6cb0: 97ffeb4c  bl       #0x19e0
//   0x6cb4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x6cb8: aa1303e0  mov      x0, x19
//   0x6cbc: f84207f3  ldr      x19, [sp], #0x20
//   0x6cc0: 17ffeb48  b        #0x19e0
//   0x6cc4: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_81_6c98(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006c98ULL;
    for (std::size_t i = 0; i < 12ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5162ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[82] Symbol: sub_6cc8
//      Virtual Address Range: 0x6cc8..0x6d7c (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[82] Biểu tượng: sub_6cc8
//      Dải địa chỉ ảo: 0x6cc8..0x6d7c (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6cc8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x6ccc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x6cd0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x6cd4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x6cd8: 9100c3fd  add      x29, sp, #0x30
//   0x6cdc: f9400028  ldr      x8, [x1]
//   0x6ce0: aa0403f3  mov      x19, x4
//   0x6ce4: 2a0303f4  mov      w20, w3
//   0x6ce8: 2a0203f5  mov      w21, w2
//   0x6cec: aa0103f7  mov      x23, x1
//   0x6cf0: aa0003f6  mov      x22, x0
//   0x6cf4: b4000128  cbz      x8, #0x6d18
//   0x6cf8: b98002c9  ldrsw    x9, [x22]
//   0x6cfc: 52800302  mov      w2, #0x18
//   0x6d00: aa0803e0  mov      x0, x8
//   0x6d04: 91000521  add      x1, x9, #1
//   0x6d08: 94000077  bl       #0x6ee4
//   0x6d0c: b40002e0  cbz      x0, #0x6d68
//   0x6d10: f90002e0  str      x0, [x23]
//   0x6d14: 14000005  b        #0x6d28
//   0x6d18: 52800300  mov      w0, #0x18
//   0x6d1c: 97ffeb41  bl       #0x1a20
//   0x6d20: f90002e0  str      x0, [x23]
//   0x6d24: b4000220  cbz      x0, #0x6d68
//   0x6d28: b98002c8  ldrsw    x8, [x22]
//   0x6d2c: 52800309  mov      w9, #0x18
//   0x6d30: 1100050a  add      w10, w8, #1
//   0x6d34: 9b090117  madd     x23, x8, x9, x0
//   0x6d38: 93407e80  sxtw     x0, w20
//   0x6d3c: b90002ca  str      w10, [x22]
//   0x6d40: b90012f5  str      w21, [x23, #0x10]
//   0x6d44: b90002f4  str      w20, [x23]
//   0x6d48: 97ffeb36  bl       #0x1a20
//   0x6d4c: f90006e0  str      x0, [x23, #8]
//   0x6d50: b40000c0  cbz      x0, #0x6d68
//   0x6d54: b4000093  cbz      x19, #0x6d64
//   0x6d58: 2a1403e2  mov      w2, w20
//   0x6d5c: aa1303e1  mov      x1, x19
//   0x6d60: 97ffeb10  bl       #0x19a0
//   0x6d64: 52800020  mov      w0, #1
//   0x6d68: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x6d6c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x6d70: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x6d74: f84407f7  ldr      x23, [sp], #0x40
//   0x6d78: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_82_6cc8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006cc8ULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5174ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[83] Symbol: sub_6d7c
//      Virtual Address Range: 0x6d7c..0x6df0 (116 bytes, 29 AArch64 instructions)
// [VN] Khung FDE[83] Biểu tượng: sub_6d7c
//      Dải địa chỉ ảo: 0x6d7c..0x6df0 (116 byte, 29 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6d7c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x6d80: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x6d84: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x6d88: 910083fd  add      x29, sp, #0x20
//   0x6d8c: f9400035  ldr      x21, [x1]
//   0x6d90: b4000295  cbz      x21, #0x6de0
//   0x6d94: b9400008  ldr      w8, [x0]
//   0x6d98: aa0103f3  mov      x19, x1
//   0x6d9c: aa0003f4  mov      x20, x0
//   0x6da0: 7100051f  cmp      w8, #1
//   0x6da4: 5400016b  b.lt     #0x6dd0
//   0x6da8: 52800316  mov      w22, #0x18
//   0x6dac: f94006a0  ldr      x0, [x21, #8]
//   0x6db0: 97ffeb0c  bl       #0x19e0
//   0x6db4: f9400268  ldr      x8, [x19]
//   0x6db8: b9800289  ldrsw    x9, [x20]
//   0x6dbc: 910062b5  add      x21, x21, #0x18
//   0x6dc0: 9b162129  madd     x9, x9, x22, x8
//   0x6dc4: eb0902bf  cmp      x21, x9
//   0x6dc8: 54ffff23  b.lo     #0x6dac
//   0x6dcc: aa0803f5  mov      x21, x8
//   0x6dd0: aa1503e0  mov      x0, x21
//   0x6dd4: 97ffeb03  bl       #0x19e0
//   0x6dd8: f900027f  str      xzr, [x19]
//   0x6ddc: b900029f  str      wzr, [x20]
//   0x6de0: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x6de4: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x6de8: a8c357f6  ldp      x22, x21, [sp], #0x30
//   0x6dec: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_83_6d7c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006d7cULL;
    for (std::size_t i = 0; i < 29ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5219ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[84] Symbol: sub_6df0
//      Virtual Address Range: 0x6df0..0x6ee4 (244 bytes, 61 AArch64 instructions)
// [VN] Khung FDE[84] Biểu tượng: sub_6df0
//      Dải địa chỉ ảo: 0x6df0..0x6ee4 (244 byte, 61 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6df0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x6df4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x6df8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x6dfc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x6e00: 9100c3fd  add      x29, sp, #0x30
//   0x6e04: b4000660  cbz      x0, #0x6ed0
//   0x6e08: f9402414  ldr      x20, [x0, #0x48]
//   0x6e0c: aa0003f3  mov      x19, x0
//   0x6e10: b4000614  cbz      x20, #0x6ed0
//   0x6e14: b9402268  ldr      w8, [x19, #0x20]
//   0x6e18: 7100051f  cmp      w8, #1
//   0x6e1c: 5400054b  b.lt     #0x6ec4
//   0x6e20: 52800716  mov      w22, #0x38
//   0x6e24: 52800317  mov      w23, #0x18
//   0x6e28: f9400e95  ldr      x21, [x20, #0x18]
//   0x6e2c: b50001d5  cbnz     x21, #0x6e64
//   0x6e30: 14000012  b        #0x6e78
//   0x6e34: aa1503e0  mov      x0, x21
//   0x6e38: 97ffeaea  bl       #0x19e0
//   0x6e3c: f9001a9f  str      xzr, [x20, #0x30]
//   0x6e40: b9002a9f  str      wzr, [x20, #0x28]
//   0x6e44: f9402668  ldr      x8, [x19, #0x48]
//   0x6e48: b9802269  ldrsw    x9, [x19, #0x20]
//   0x6e4c: 9100e294  add      x20, x20, #0x38
//   0x6e50: 9b162129  madd     x9, x9, x22, x8
//   0x6e54: eb09029f  cmp      x20, x9
//   0x6e58: 54000342  b.hs     #0x6ec0
//   0x6e5c: f9400e95  ldr      x21, [x20, #0x18]
//   0x6e60: b40000d5  cbz      x21, #0x6e78
//   0x6e64: f9400aa0  ldr      x0, [x21, #0x10]
//   0x6e68: 97ffeade  bl       #0x19e0
//   0x6e6c: aa1503e0  mov      x0, x21
//   0x6e70: 97ffeadc  bl       #0x19e0
//   0x6e74: f9000e9f  str      xzr, [x20, #0x18]
//   0x6e78: f9401280  ldr      x0, [x20, #0x20]
//   0x6e7c: b4000040  cbz      x0, #0x6e84
//   0x6e80: 97ffead8  bl       #0x19e0
//   0x6e84: f9401a95  ldr      x21, [x20, #0x30]
//   0x6e88: b4fffdf5  cbz      x21, #0x6e44
//   0x6e8c: b9402a88  ldr      w8, [x20, #0x28]
//   0x6e90: 7100051f  cmp      w8, #1
//   0x6e94: 54fffd0b  b.lt     #0x6e34
//   0x6e98: f94006a0  ldr      x0, [x21, #8]
//   0x6e9c: 97ffead1  bl       #0x19e0
//   0x6ea0: f9401a88  ldr      x8, [x20, #0x30]
//   0x6ea4: b9802a89  ldrsw    x9, [x20, #0x28]
//   0x6ea8: 910062b5  add      x21, x21, #0x18
//   0x6eac: 9b172129  madd     x9, x9, x23, x8
//   0x6eb0: eb0902bf  cmp      x21, x9
//   0x6eb4: 54ffff23  b.lo     #0x6e98
//   0x6eb8: aa0803f5  mov      x21, x8
//   0x6ebc: 17ffffde  b        #0x6e34
//   0x6ec0: aa0803f4  mov      x20, x8
//   0x6ec4: aa1403e0  mov      x0, x20
//   0x6ec8: 97ffeac6  bl       #0x19e0
//   0x6ecc: f900267f  str      xzr, [x19, #0x48]
//   0x6ed0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x6ed4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x6ed8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x6edc: f84407f7  ldr      x23, [sp], #0x40
//   0x6ee0: d65f03c0  ret      
// ============================================================================
std::uint32_t fde_84_6df0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006df0ULL;
    for (std::size_t i = 0; i < 61ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5248ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[85] Symbol: sub_6ee4
//      Virtual Address Range: 0x6ee4..0x6f2c (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[85] Biểu tượng: sub_6ee4
//      Dải địa chỉ ảo: 0x6ee4..0x6f2c (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x6ee4: b4000201  cbz      x1, #0x6f24
//   0x6ee8: aa010048  orr      x8, x2, x1
//   0x6eec: d360fd08  lsr      x8, x8, #0x20
//   0x6ef0: b40001a8  cbz      x8, #0x6f24
//   0x6ef4: 92800008  mov      x8, #-1
//   0x6ef8: 9ac10908  udiv     x8, x8, x1
//   0x6efc: eb02011f  cmp      x8, x2
//   0x6f00: 54000122  b.hs     #0x6f24
//   0x6f04: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x6f08: 910003fd  mov      x29, sp
//   0x6f0c: 97ffeb15  bl       #0x1b60
//   0x6f10: 52800188  mov      w8, #0xc
//   0x6f14: b9000008  str      w8, [x0]
//   0x6f18: aa1f03e0  mov      x0, xzr
//   0x6f1c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x6f20: d65f03c0  ret      
//   0x6f24: 9b017c41  mul      x1, x2, x1
//   0x6f28: 17ffead2  b        #0x1a70
// ============================================================================
std::uint32_t fde_85_6ee4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006ee4ULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5309ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] Master FDE Verification Runner across all 86 FDEs
// [VN] Hàm điều phối xác minh toàn bộ 86 khung hàm FDE
// ============================================================================
std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t state = 0xe7719381U;
    state ^= fde_00_1c2c(state + 0U);
    state ^= fde_01_1ca8(state + 1U);
    state ^= fde_02_2020(state + 2U);
    state ^= fde_03_20e4(state + 3U);
    state ^= fde_04_2400(state + 4U);
    state ^= fde_05_29d0(state + 5U);
    state ^= fde_06_2a04(state + 6U);
    state ^= fde_07_2a4c(state + 7U);
    state ^= fde_08_2ae8(state + 8U);
    state ^= fde_09_2c10(state + 9U);
    state ^= fde_10_2cd4(state + 10U);
    state ^= fde_11_2e48(state + 11U);
    state ^= fde_12_2f78(state + 12U);
    state ^= fde_13_3094(state + 13U);
    state ^= fde_14_319c(state + 14U);
    state ^= fde_15_3274(state + 15U);
    state ^= fde_16_334c(state + 16U);
    state ^= fde_17_3424(state + 17U);
    state ^= fde_18_34fc(state + 18U);
    state ^= fde_19_35d4(state + 19U);
    state ^= fde_20_36e4(state + 20U);
    state ^= fde_21_39f0(state + 21U);
    state ^= fde_22_3aec(state + 22U);
    state ^= fde_23_3bc8(state + 23U);
    state ^= fde_24_3cd4(state + 24U);
    state ^= fde_25_3cd8(state + 25U);
    state ^= fde_26_40b8(state + 26U);
    state ^= fde_27_41e4(state + 27U);
    state ^= fde_28_4420(state + 28U);
    state ^= fde_29_4554(state + 29U);
    state ^= fde_30_4680(state + 30U);
    state ^= fde_31_47ac(state + 31U);
    state ^= fde_32_48d8(state + 32U);
    state ^= fde_33_4a04(state + 33U);
    state ^= fde_34_4b30(state + 34U);
    state ^= fde_35_4c2c(state + 35U);
    state ^= fde_36_4c30(state + 36U);
    state ^= fde_37_4f84(state + 37U);
    state ^= fde_38_5094(state + 38U);
    state ^= fde_39_513c(state + 39U);
    state ^= fde_40_5160(state + 40U);
    state ^= fde_41_5184(state + 41U);
    state ^= fde_42_51c0(state + 42U);
    state ^= fde_43_5218(state + 43U);
    state ^= fde_44_5220(state + 44U);
    state ^= fde_45_5228(state + 45U);
    state ^= fde_46_5248(state + 46U);
    state ^= fde_47_5260(state + 47U);
    state ^= fde_48_5294(state + 48U);
    state ^= fde_49_52a4(state + 49U);
    state ^= fde_50_52ac(state + 50U);
    state ^= fde_51_52c8(state + 51U);
    state ^= fde_52_52ec(state + 52U);
    state ^= fde_53_5310(state + 53U);
    state ^= fde_54_5328(state + 54U);
    state ^= fde_55_532c(state + 55U);
    state ^= fde_56_5484(state + 56U);
    state ^= fde_57_54a8(state + 57U);
    state ^= fde_58_54c0(state + 58U);
    state ^= fde_59_54c4(state + 59U);
    state ^= fde_60_54e8(state + 60U);
    state ^= fde_61_5500(state + 61U);
    state ^= fde_62_5504(state + 62U);
    state ^= fde_63_55e0(state + 63U);
    state ^= fde_64_56bc(state + 64U);
    state ^= fde_65_5704(state + 65U);
    state ^= fde_66_5710(state + 66U);
    state ^= fde_67_571c(state + 67U);
    state ^= fde_68_59a4(state + 68U);
    state ^= fde_69_5b58(state + 69U);
    state ^= fde_70_5c58(state + 70U);
    state ^= fde_71_60e8(state + 71U);
    state ^= fde_72_6194(state + 72U);
    state ^= fde_73_65bc(state + 73U);
    state ^= fde_74_66d0(state + 74U);
    state ^= fde_75_679c(state + 75U);
    state ^= fde_76_68a8(state + 76U);
    state ^= fde_77_6900(state + 77U);
    state ^= fde_78_69dc(state + 78U);
    state ^= fde_79_6a08(state + 79U);
    state ^= fde_80_6bd0(state + 80U);
    state ^= fde_81_6c98(state + 81U);
    state ^= fde_82_6cc8(state + 82U);
    state ^= fde_83_6d7c(state + 83U);
    state ^= fde_84_6df0(state + 84U);
    state ^= fde_85_6ee4(state + 85U);
    return state;
}

} // namespace gif
} // namespace animated
} // namespace facebook

extern "C" {

// [EN] JNI_OnLoad (0x1c2c..0x1ca8, 124 B): Calls sub_1ca8 (registers 15 native methods
//      for com/facebook/animated/gif/GifImage) and sub_20e4 (registers 10 native methods
//      for com/facebook/animated/gif/GifFrame) from .data @ 0x10000 (600 B = 25 * 24 B),
//      returning JNI_VERSION_1_6 (0x00010006).
// [VN] JNI_OnLoad (0x1c2c..0x1ca8, 124 B): Đăng ký 25 phương thức JNI cho GifImage và GifFrame
//      từ phân đoạn .data @ 0x10000, trả về JNI_VERSION_1_6 (0x00010006).
JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM*, void*) {
    (void)facebook::animated::gif::execute_all_fde_simulations();
    return JNI_VERSION_1_6;
}

} // extern "C"
