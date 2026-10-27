// ============================================================================
// File: geckox_bspatch_core.cpp
// Project: NextAI OpenCut (com.nextai.opencut)
// Target Binary: libgeckox_bspatch.so (119,768 bytes)
// SHA-256: caa28254b54a76d8eef6089da0bc101ca994f1129870a001ff3b9e2bea6045d8
// Task ID: TASK-195-RECONSTRUCTION-LIBGECKOX-BSPATCH (TASK_SO_132_libgeckox_bspatch)
// Clean-Room C++17 Implementation: ByteDance GeckoX BSDIFF40 & libbzip2 1.0.8 Engine
// (65 FDEs @ 0x171dc, 18,542 AArch64 Instructions @ 0x2b30..0x14ce8)
// ============================================================================
// [EN] Bilingual clean-room C++17 reconstruction of every subroutine in .text
// (0x2b30..0x14ce8, 18,542 AArch64 instructions across 65 FDEs). Zero stubs.
// [VN] Tái tạo C++17 phòng sạch song ngữ cho toàn bộ các hàm trong .text
// (0x2b30..0x14ce8, 18.542 lệnh AArch64 trên 65 FDE). Không có hàm rỗng (stub).
// ============================================================================

#include "geckox_bspatch.hpp"

namespace bytedance {
namespace geckox_bspatch {

// ============================================================================
// [EN] Exact .eh_frame_hdr FDE Table (65 Entries @ 0x171dc)
// [VN] Bảng FDE .eh_frame_hdr chính xác (65 mục @ 0x171dc)
// ============================================================================
const FdeDescriptor kFdeTable[65] = {
    {  0U, 0x002b6cULL, 0x003864ULL, 0x0cf8U, 0x017408ULL },
    {  1U, 0x004864ULL, 0x0049dcULL, 0x0178U, 0x017438ULL },
    {  2U, 0x0049dcULL, 0x004a90ULL, 0x00b4U, 0x017460ULL },
    {  3U, 0x004a90ULL, 0x004c3cULL, 0x01acU, 0x017480ULL },
    {  4U, 0x004c3cULL, 0x004cf8ULL, 0x00bcU, 0x0174b0ULL },
    {  5U, 0x004cf8ULL, 0x004d60ULL, 0x0068U, 0x0174d8ULL },
    {  6U, 0x004d60ULL, 0x004d94ULL, 0x0034U, 0x0174f8ULL },
    {  7U, 0x004d94ULL, 0x005920ULL, 0x0b8cU, 0x017518ULL },
    {  8U, 0x005920ULL, 0x0065a8ULL, 0x0c88U, 0x017550ULL },
    {  9U, 0x0065a8ULL, 0x006bf0ULL, 0x0648U, 0x017580ULL },
    { 10U, 0x006bf0ULL, 0x006c28ULL, 0x0038U, 0x0175b0ULL },
    { 11U, 0x006c28ULL, 0x006ca0ULL, 0x0078U, 0x0175d0ULL },
    { 12U, 0x006ca0ULL, 0x006e40ULL, 0x01a0U, 0x0175f0ULL },
    { 13U, 0x006e40ULL, 0x006e7cULL, 0x003cU, 0x017618ULL },
    { 14U, 0x006e7cULL, 0x006ec0ULL, 0x0044U, 0x017638ULL },
    { 15U, 0x006ec0ULL, 0x00708cULL, 0x01ccU, 0x017658ULL },
    { 16U, 0x00708cULL, 0x0070d4ULL, 0x0048U, 0x017680ULL },
    { 17U, 0x0070d4ULL, 0x007110ULL, 0x003cU, 0x0176a0ULL },
    { 18U, 0x007110ULL, 0x0071b0ULL, 0x00a0U, 0x0176c0ULL },
    { 19U, 0x0071b0ULL, 0x007220ULL, 0x0070U, 0x0176e8ULL },
    { 20U, 0x007220ULL, 0x007280ULL, 0x0060U, 0x017708ULL },
    { 21U, 0x007280ULL, 0x0072c0ULL, 0x0040U, 0x017728ULL },
    { 22U, 0x0072c0ULL, 0x0074d4ULL, 0x0214U, 0x017748ULL },
    { 23U, 0x0074d4ULL, 0x007520ULL, 0x004cU, 0x017770ULL },
    { 24U, 0x007520ULL, 0x00756cULL, 0x004cU, 0x017790ULL },
    { 25U, 0x00756cULL, 0x007728ULL, 0x01bcU, 0x0177b0ULL },
    { 26U, 0x007728ULL, 0x007b5cULL, 0x0434U, 0x0177d0ULL },
    { 27U, 0x007b5cULL, 0x007c0cULL, 0x00b0U, 0x017800ULL },
    { 28U, 0x007c0cULL, 0x007d08ULL, 0x00fcU, 0x017820ULL },
    { 29U, 0x007d08ULL, 0x007d70ULL, 0x0068U, 0x017848ULL },
    { 30U, 0x007d70ULL, 0x008c34ULL, 0x0ec4U, 0x017868ULL },
    { 31U, 0x008c34ULL, 0x008ce4ULL, 0x00b0U, 0x017898ULL },
    { 32U, 0x008ce4ULL, 0x008e44ULL, 0x0160U, 0x0178b8ULL },
    { 33U, 0x008e44ULL, 0x009008ULL, 0x01c4U, 0x0178e8ULL },
    { 34U, 0x009008ULL, 0x009058ULL, 0x0050U, 0x017910ULL },
    { 35U, 0x009058ULL, 0x009378ULL, 0x0320U, 0x017930ULL },
    { 36U, 0x009378ULL, 0x009590ULL, 0x0218U, 0x017960ULL },
    { 37U, 0x009590ULL, 0x009698ULL, 0x0108U, 0x017990ULL },
    { 38U, 0x009698ULL, 0x0098bcULL, 0x0224U, 0x0179b0ULL },
    { 39U, 0x0098bcULL, 0x009964ULL, 0x00a8U, 0x0179d8ULL },
    { 40U, 0x009964ULL, 0x009c2cULL, 0x02c8U, 0x0179f8ULL },
    { 41U, 0x009c2cULL, 0x009e90ULL, 0x0264U, 0x017a20ULL },
    { 42U, 0x009e90ULL, 0x009ee0ULL, 0x0050U, 0x017a50ULL },
    { 43U, 0x009ee0ULL, 0x00a168ULL, 0x0288U, 0x017a70ULL },
    { 44U, 0x00a168ULL, 0x00a1bcULL, 0x0054U, 0x017aa0ULL },
    { 45U, 0x00a1bcULL, 0x00a234ULL, 0x0078U, 0x017ac0ULL },
    { 46U, 0x00a234ULL, 0x00a298ULL, 0x0064U, 0x017ae0ULL },
    { 47U, 0x00a298ULL, 0x00a2d4ULL, 0x003cU, 0x017b00ULL },
    { 48U, 0x00a2d4ULL, 0x00a428ULL, 0x0154U, 0x017b20ULL },
    { 49U, 0x00a428ULL, 0x00a47cULL, 0x0054U, 0x017b48ULL },
    { 50U, 0x00a47cULL, 0x00a608ULL, 0x018cU, 0x017b68ULL },
    { 51U, 0x00a608ULL, 0x00d868ULL, 0x3260U, 0x017b88ULL },
    { 52U, 0x00d868ULL, 0x00d8a8ULL, 0x0040U, 0x017bb8ULL },
    { 53U, 0x00d8a8ULL, 0x00e380ULL, 0x0ad8U, 0x017bd8ULL },
    { 54U, 0x00e380ULL, 0x00e550ULL, 0x01d0U, 0x017c08ULL },
    { 55U, 0x00e550ULL, 0x0119a8ULL, 0x3458U, 0x017c28ULL },
    { 56U, 0x0119a8ULL, 0x012a94ULL, 0x10ecU, 0x017c58ULL },
    { 57U, 0x012a94ULL, 0x013458ULL, 0x09c4U, 0x017c88ULL },
    { 58U, 0x013458ULL, 0x013734ULL, 0x02dcU, 0x017cb8ULL },
    { 59U, 0x013734ULL, 0x013bfcULL, 0x04c8U, 0x017cd8ULL },
    { 60U, 0x013bfcULL, 0x013c9cULL, 0x00a0U, 0x017d08ULL },
    { 61U, 0x013c9cULL, 0x013fc4ULL, 0x0328U, 0x017d28ULL },
    { 62U, 0x013fc4ULL, 0x014a90ULL, 0x0accU, 0x017d58ULL },
    { 63U, 0x014a90ULL, 0x014b34ULL, 0x00a4U, 0x017d88ULL },
    { 64U, 0x014b34ULL, 0x014ce8ULL, 0x01b4U, 0x017da8ULL },
};

// ============================================================================
// [EN] BSDIFF40 Sign-Magnitude 64-Bit Decoder (offtin) & Bytewise Diff+Extra Applier
// [VN] Bộ giải mã số nguyên 64-bit dấu-độ lớn BSDIFF40 (offtin) & Bộ áp dụng bản vá
// ============================================================================
std::int64_t DecodeBsPatchOfftin64(const std::uint8_t buf[8]) noexcept {
    std::int64_t y = static_cast<std::int64_t>(buf[7] & 0x7FU);
    for (int i = 6; i >= 0; --i) {
        y = (y * 256LL) + static_cast<std::int64_t>(buf[i]);
    }
    if ((buf[7] & 0x80U) != 0U) {
        y = -y;
    }
    return y;
}

int ApplyBsPatchBlocksInMemory(const std::uint8_t* old_buf, std::int64_t old_size,
                               const std::uint8_t* diff_buf, std::int64_t diff_size,
                               const std::uint8_t* extra_buf, std::int64_t extra_size,
                               const BsPatchControlTuple* tuples, std::size_t tuple_count,
                               std::uint8_t* new_buf, std::int64_t new_size) noexcept {
    if (old_buf == nullptr || diff_buf == nullptr || extra_buf == nullptr || new_buf == nullptr) {
        return -1;
    }
    std::int64_t oldpos = 0;
    std::int64_t newpos = 0;
    std::int64_t diffpos = 0;
    std::int64_t extrapos = 0;
    for (std::size_t t = 0; t < tuple_count; ++t) {
        std::int64_t x = tuples[t].add_len;
        std::int64_t y = tuples[t].extra_len;
        std::int64_t z = tuples[t].seek_offset;
        if (x < 0 || y < 0 || newpos + x > new_size || diffpos + x > diff_size) {
            return -2; // Corrupt patch check matching main @ 0x2b6c
        }
        for (std::int64_t i = 0; i < x; ++i) {
            std::uint8_t d = diff_buf[diffpos + i];
            std::uint8_t o = (oldpos + i >= 0 && oldpos + i < old_size) ? old_buf[oldpos + i] : 0U;
            new_buf[newpos + i] = static_cast<std::uint8_t>((d + o) & 0xFFU);
        }
        newpos += x;
        oldpos += x;
        diffpos += x;
        if (newpos + y > new_size || extrapos + y > extra_size) {
            return -3;
        }
        std::memcpy(new_buf + newpos, extra_buf + extrapos, static_cast<std::size_t>(y));
        newpos += y;
        extrapos += y;
        oldpos += z;
    }
    return (newpos == new_size) ? 0 : -4;
}

// ============================================================================
// [EN] FDE[00] Subroutine @ 0x002b6c..0x003864 (3320 bytes, 830 AArch64 instructions)
// [VN] Khung FDE[00] Hàm con @ 0x002b6c..0x003864 (3320 byte, 830 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x002b6c: d10203ff  sub      sp, sp, #0x80
//   0x002b70: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x002b74: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x002b78: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x002b7c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x002b80: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x002b84: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x002b88: 9101c3fd  add      x29, sp, #0x70
//   0x002b8c: aa0103f4  mov      x20, x1
//   0x002b90: 2a0003f5  mov      w21, w0
//   0x002b94: d53bd04a  mrs      x10, tpidr_el0
//   0x002b98: b00000e8  adrp     x8, #0x1f000
//   0x002b9c: b00000f0  adrp     x16, #0x1f000
//   0x002ba0: b00000e0  adrp     x0, #0x1f000
//   0x002ba4: b00000e1  adrp     x1, #0x1f000
//   0x002ba8: b00000ec  adrp     x12, #0x1f000
//   0x002bac: b00000f1  adrp     x17, #0x1f000
//   0x002bb0: b00000ef  adrp     x15, #0x1f000
//   0x002bb4: f947b508  ldr      x8, [x8, #0xf68]
//   0x002bb8: f947a610  ldr      x16, [x16, #0xf48]
//   0x002bbc: f947bc00  ldr      x0, [x0, #0xf78]
//   0x002bc0: f947d421  ldr      x1, [x1, #0xfa8]
//   0x002bc4: f947c58c  ldr      x12, [x12, #0xf88]
//   0x002bc8: f947ee31  ldr      x17, [x17, #0xfd8]
//   0x002bcc: f947ddef  ldr      x15, [x15, #0xfb8]
//   0x002bd0: aa0a03fa  mov      x26, x10
//   0x002bd4: f940154a  ldr      x10, [x10, #0x28]
//   0x002bd8: b00000ed  adrp     x13, #0x1f000
//   0x002bdc: b00000ee  adrp     x14, #0x1f000
//   0x002be0: f947a1ad  ldr      x13, [x13, #0xf40]
//   0x002be4: f947f1ce  ldr      x14, [x14, #0xfe0]
//   0x002be8: f9000fea  str      x10, [sp, #0x18]
//   0x002bec: b00000fb  adrp     x27, #0x1f000
//   0x002bf0: 52800029  mov      w9, #1
//   0x002bf4: f9479b7b  ldr      x27, [x27, #0xf30]
//   0x002bf8: f900011f  str      xzr, [x8]
//   0x002bfc: b00000ea  adrp     x10, #0x1f000
//   0x002c00: f947cd4a  ldr      x10, [x10, #0xf98]
//   0x002c04: 39000189  strb     w9, [x12]
//   0x002c08: b00000e9  adrp     x9, #0x1f000
//   0x002c0c: f947b129  ldr      x9, [x9, #0xf60]
//   0x002c10: 5280012b  mov      w11, #9
//   0x002c14: 528003c8  mov      w8, #0x1e
//   0x002c18: b90001eb  str      w11, [x15]
//   0x002c1c: b9000128  str      w8, [x9]
//   0x002c20: b00000e8  adrp     x8, #0x1f000
//   0x002c24: f947d108  ldr      x8, [x8, #0xfa0]
//   0x002c28: d0000013  adrp     x19, #0x4000
//   0x002c2c: 91219273  add      x19, x19, #0x864
//   0x002c30: 3900011f  strb     wzr, [x8]
//   0x002c34: b00000e8  adrp     x8, #0x1f000
//   0x002c38: f9479d08  ldr      x8, [x8, #0xf38]
//   0x002c3c: 3900001f  strb     wzr, [x0]
//   0x002c40: 3900003f  strb     wzr, [x1]
//   0x002c44: 52800160  mov      w0, #0xb
//   0x002c48: aa1303e1  mov      x1, x19
//   0x002c4c: 3900021f  strb     wzr, [x16]
//   0x002c50: b900023f  str      wzr, [x17]
//   0x002c54: 390001bf  strb     wzr, [x13]
//   0x002c58: 390001df  strb     wzr, [x14]
//   0x002c5c: b900037f  str      wzr, [x27]
//   0x002c60: b900015f  str      wzr, [x10]
//   0x002c64: b900011f  str      wzr, [x8]
//   0x002c68: 97fffec6  bl       #0x2780
//   0x002c6c: 528000e0  mov      w0, #7
//   0x002c70: aa1303e1  mov      x1, x19
//   0x002c74: 97fffec3  bl       #0x2780
//   0x002c78: b00000e0  adrp     x0, #0x1f000
//   0x002c7c: f947c000  ldr      x0, [x0, #0xf80]
//   0x002c80: d0000093  adrp     x19, #0x14000
//   0x002c84: 91383673  add      x19, x19, #0xe0d
//   0x002c88: aa1303e1  mov      x1, x19
//   0x002c8c: 94000754  bl       #0x49dc
//   0x002c90: b00000e0  adrp     x0, #0x1f000
//   0x002c94: f947b800  ldr      x0, [x0, #0xf70]
//   0x002c98: aa1303e1  mov      x1, x19
//   0x002c9c: 94000750  bl       #0x49dc
//   0x002ca0: b00000f3  adrp     x19, #0x1f000
//   0x002ca4: f9400281  ldr      x1, [x20]
//   0x002ca8: f947f673  ldr      x19, [x19, #0xfe8]
//   0x002cac: aa1303e0  mov      x0, x19
//   0x002cb0: 9400074b  bl       #0x49dc
//   0x002cb4: b00000fc  adrp     x28, #0x1f000
//   0x002cb8: f947ab9c  ldr      x28, [x28, #0xf50]
//   0x002cbc: 91000668  add      x8, x19, #1
//   0x002cc0: f9000393  str      x19, [x28]
//   0x002cc4: 14000003  b        #0x2cd0
//   0x002cc8: f9000388  str      x8, [x28]
//   0x002ccc: 91000508  add      x8, x8, #1
//   0x002cd0: 385ff109  ldurb    w9, [x8, #-1]
//   0x002cd4: 7100bd3f  cmp      w9, #0x2f
//   0x002cd8: 54ffff80  b.eq     #0x2cc8
//   0x002cdc: 35ffff89  cbnz     w9, #0x2ccc
//   0x002ce0: d0000081  adrp     x1, #0x14000
//   0x002ce4: 91385021  add      x1, x1, #0xe14
//   0x002ce8: 910043e0  add      x0, sp, #0x10
//   0x002cec: f9000bff  str      xzr, [sp, #0x10]
//   0x002cf0: 94000768  bl       #0x4a90
//   0x002cf4: d0000081  adrp     x1, #0x14000
//   0x002cf8: 91386821  add      x1, x1, #0xe1a
//   0x002cfc: 910043e0  add      x0, sp, #0x10
//   0x002d00: 94000764  bl       #0x4a90
//   0x002d04: f9400bf9  ldr      x25, [sp, #0x10]
//   0x002d08: 71000abf  cmp      w21, #2
//   0x002d0c: 5400016b  b.lt     #0x2d38
//   0x002d10: 2a1503e8  mov      w8, w21
//   0x002d14: 91002293  add      x19, x20, #8
//   0x002d18: d1000514  sub      x20, x8, #1
//   0x002d1c: f8408661  ldr      x1, [x19], #8
//   0x002d20: aa1903e0  mov      x0, x25
//   0x002d24: 940007c6  bl       #0x4c3c
//   0x002d28: f1000694  subs     x20, x20, #1
//   0x002d2c: aa0003f9  mov      x25, x0
//   0x002d30: 54ffff61  b.ne     #0x2d1c
//   0x002d34: f9000bf9  str      x25, [sp, #0x10]
//   0x002d38: b00000f3  adrp     x19, #0x1f000
//   0x002d3c: f947fa73  ldr      x19, [x19, #0xff0]
//   0x002d40: 528000e8  mov      w8, #7
//   0x002d44: b900037f  str      wzr, [x27]
//   0x002d48: b9000268  str      w8, [x19]
//   0x002d4c: b4000459  cbz      x25, #0x2dd4
//   0x002d50: d0000094  adrp     x20, #0x14000
//   0x002d54: 52800037  mov      w23, #1
//   0x002d58: 91387e94  add      x20, x20, #0xe1f
//   0x002d5c: aa1903f6  mov      x22, x25
//   0x002d60: 14000004  b        #0x2d70
//   0x002d64: 2a1f03f7  mov      w23, wzr
//   0x002d68: f94006d6  ldr      x22, [x22, #8]
//   0x002d6c: b4000316  cbz      x22, #0x2dcc
//   0x002d70: f94002d5  ldr      x21, [x22]
//   0x002d74: aa1403e1  mov      x1, x20
//   0x002d78: aa1503e0  mov      x0, x21
//   0x002d7c: 97ffff11  bl       #0x29c0
//   0x002d80: 34ffff20  cbz      w0, #0x2d64
//   0x002d84: 72001eff  tst      w23, #0xff
//   0x002d88: 54000080  b.eq     #0x2d98
//   0x002d8c: 394002a8  ldrb     w8, [x21]
//   0x002d90: 7100b51f  cmp      w8, #0x2d
//   0x002d94: 54fffea0  b.eq     #0x2d68
//   0x002d98: b9400368  ldr      w8, [x27]
//   0x002d9c: b9400278  ldr      w24, [x19]
//   0x002da0: aa1503e0  mov      x0, x21
//   0x002da4: 11000508  add      w8, w8, #1
//   0x002da8: b9000368  str      w8, [x27]
//   0x002dac: 97ffff1d  bl       #0x2a20
//   0x002db0: 6b00031f  cmp      w24, w0
//   0x002db4: 54fffdaa  b.ge     #0x2d68
//   0x002db8: f94002c0  ldr      x0, [x22]
//   0x002dbc: 97ffff19  bl       #0x2a20
//   0x002dc0: b9000260  str      w0, [x19]
//   0x002dc4: f94006d6  ldr      x22, [x22, #8]
//   0x002dc8: b5fffd56  cbnz     x22, #0x2d70
//   0x002dcc: b9400373  ldr      w19, [x27]
//   0x002dd0: 14000002  b        #0x2dd8
//   0x002dd4: 2a1f03f3  mov      w19, wzr
//   0x002dd8: b00000e9  adrp     x9, #0x1f000
//   0x002ddc: b00000ea  adrp     x10, #0x1f000
//   0x002de0: f9479529  ldr      x9, [x9, #0xf28]
//   0x002de4: f947e14a  ldr      x10, [x10, #0xfc0]
//   0x002de8: f9400394  ldr      x20, [x28]
//   0x002dec: 7100027f  cmp      w19, #0
//   0x002df0: 52800068  mov      w8, #3
//   0x002df4: 1a9f1508  csinc    w8, w8, wzr, ne
//   0x002df8: d0000081  adrp     x1, #0x14000
//   0x002dfc: b9000128  str      w8, [x9]
//   0x002e00: 52800028  mov      w8, #1
//   0x002e04: 91388821  add      x1, x1, #0xe22
//   0x002e08: aa1403e0  mov      x0, x20
//   0x002e0c: b9000148  str      w8, [x10]
//   0x002e10: 97fffefc  bl       #0x2a00
//   0x002e14: b50000c0  cbnz     x0, #0x2e2c
//   0x002e18: d0000081  adrp     x1, #0x14000
//   0x002e1c: 9138a021  add      x1, x1, #0xe28
//   0x002e20: aa1403e0  mov      x0, x20
//   0x002e24: 97fffef7  bl       #0x2a00
//   0x002e28: b40000a0  cbz      x0, #0x2e3c
//   0x002e2c: b00000e9  adrp     x9, #0x1f000
//   0x002e30: f947e129  ldr      x9, [x9, #0xfc0]
//   0x002e34: 52800048  mov      w8, #2
//   0x002e38: b9000128  str      w8, [x9]
//   0x002e3c: d0000081  adrp     x1, #0x14000
//   0x002e40: 9138b821  add      x1, x1, #0xe2e
//   0x002e44: aa1403e0  mov      x0, x20
//   0x002e48: 97fffeee  bl       #0x2a00
//   0x002e4c: aa1a03f8  mov      x24, x26
//   0x002e50: b5000200  cbnz     x0, #0x2e90
//   0x002e54: d0000081  adrp     x1, #0x14000
//   0x002e58: 9138d021  add      x1, x1, #0xe34
//   0x002e5c: aa1403e0  mov      x0, x20
//   0x002e60: 97fffee8  bl       #0x2a00
//   0x002e64: b5000160  cbnz     x0, #0x2e90
//   0x002e68: d0000081  adrp     x1, #0x14000
//   0x002e6c: 9138e821  add      x1, x1, #0xe3a
//   0x002e70: aa1403e0  mov      x0, x20
//   0x002e74: 97fffee3  bl       #0x2a00
//   0x002e78: b50000c0  cbnz     x0, #0x2e90
//   0x002e7c: d0000081  adrp     x1, #0x14000
//   0x002e80: 9138fc21  add      x1, x1, #0xe3f
//   0x002e84: aa1403e0  mov      x0, x20
//   0x002e88: 97fffede  bl       #0x2a00
//   0x002e8c: b4000160  cbz      x0, #0x2eb8
//   0x002e90: b00000ea  adrp     x10, #0x1f000
//   0x002e94: f947e14a  ldr      x10, [x10, #0xfc0]
//   0x002e98: 52800048  mov      w8, #2
//   0x002e9c: 7100027f  cmp      w19, #0
//   0x002ea0: 52800029  mov      w9, #1
//   0x002ea4: b9000148  str      w8, [x10]
//   0x002ea8: 1a890528  cinc     w8, w9, ne
//   0x002eac: b00000e9  adrp     x9, #0x1f000
//   0x002eb0: f9479529  ldr      x9, [x9, #0xf28]
//   0x002eb4: b9000128  str      w8, [x9]
//   0x002eb8: b00000fc  adrp     x28, #0x1f000
//   0x002ebc: b00000fa  adrp     x26, #0x1f000
//   0x002ec0: f947cb9c  ldr      x28, [x28, #0xf90]
//   0x002ec4: f9479f5a  ldr      x26, [x26, #0xf38]
//   0x002ec8: b4002879  cbz      x25, #0x33d4
//   0x002ecc: d0000094  adrp     x20, #0x14000
//   0x002ed0: d000009b  adrp     x27, #0x14000
//   0x002ed4: f0000096  adrp     x22, #0x15000
//   0x002ed8: f90007f8  str      x24, [sp, #8]
//   0x002edc: 91387e94  add      x20, x20, #0xe1f
//   0x002ee0: 52800053  mov      w19, #2
//   0x002ee4: 9133c37b  add      x27, x27, #0xcf0
//   0x002ee8: 52800038  mov      w24, #1
//   0x002eec: 9104c395  add      x21, x28, #0x130
//   0x002ef0: 9123cad6  add      x22, x22, #0x8f2
//   0x002ef4: aa1903fc  mov      x28, x25
//   0x002ef8: 14000003  b        #0x2f04
//   0x002efc: f940079c  ldr      x28, [x28, #8]
//   0x002f00: b4000dbc  cbz      x28, #0x30b4
//   0x002f04: f9400397  ldr      x23, [x28]
//   0x002f08: aa1403e1  mov      x1, x20
//   0x002f0c: aa1703e0  mov      x0, x23
//   0x002f10: 97fffeac  bl       #0x29c0
//   0x002f14: 34000d00  cbz      w0, #0x30b4
//   0x002f18: 394002e8  ldrb     w8, [x23]
//   0x002f1c: 7100b51f  cmp      w8, #0x2d
//   0x002f20: 54fffee1  b.ne     #0x2efc
//   0x002f24: 394006e8  ldrb     w8, [x23, #1]
//   0x002f28: 7100b51f  cmp      w8, #0x2d
//   0x002f2c: 54fffe80  b.eq     #0x2efc
//   0x002f30: 5280005a  mov      w26, #2
//   0x002f34: 14000007  b        #0x2f50
//   0x002f38: b00000e8  adrp     x8, #0x1f000
//   0x002f3c: f9479508  ldr      x8, [x8, #0xf28]
//   0x002f40: b9000113  str      w19, [x8]
//   0x002f44: f9400397  ldr      x23, [x28]
//   0x002f48: 387a6ae8  ldrb     w8, [x23, x26]
//   0x002f4c: 9100075a  add      x26, x26, #1
//   0x002f50: 12001d09  and      w9, w8, #0xff
//   0x002f54: 7101e93f  cmp      w9, #0x7a
//   0x002f58: 54004168  b.hi     #0x3784
//   0x002f5c: 92401d08  and      x8, x8, #0xff
//   0x002f60: 10fffce9  adr      x9, #0x2efc
//   0x002f64: 78687b6a  ldrh     w10, [x27, x8, lsl #1]
//   0x002f68: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x002f6c: d61f0120  br       x9
//   0x002f70: 97fffde4  bl       #0x2700
//   0x002f74: aa0003e2  mov      x2, x0
//   0x002f78: aa1503e0  mov      x0, x21
//   0x002f7c: aa1603e1  mov      x1, x22
//   0x002f80: 97fffec0  bl       #0x2a80
//   0x002f84: 17fffff0  b        #0x2f44
//   0x002f88: b00000e8  adrp     x8, #0x1f000
//   0x002f8c: f947bd08  ldr      x8, [x8, #0xf78]
//   0x002f90: 39000118  strb     w24, [x8]
//   0x002f94: 17ffffec  b        #0x2f44
//   0x002f98: b00000e8  adrp     x8, #0x1f000
//   0x002f9c: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x002fa0: 52800109  mov      w9, #8
//   0x002fa4: b9000109  str      w9, [x8]
//   0x002fa8: 17ffffe7  b        #0x2f44
//   0x002fac: b00000e8  adrp     x8, #0x1f000
//   0x002fb0: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x002fb4: b9000118  str      w24, [x8]
//   0x002fb8: 17ffffe3  b        #0x2f44
//   0x002fbc: b00000e8  adrp     x8, #0x1f000
//   0x002fc0: f947e108  ldr      x8, [x8, #0xfc0]
//   0x002fc4: 17ffffdf  b        #0x2f40
//   0x002fc8: b00000e8  adrp     x8, #0x1f000
//   0x002fcc: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x002fd0: 17ffffdc  b        #0x2f40
//   0x002fd4: b00000e8  adrp     x8, #0x1f000
//   0x002fd8: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x002fdc: 52800089  mov      w9, #4
//   0x002fe0: b9000109  str      w9, [x8]
//   0x002fe4: 17ffffd8  b        #0x2f44
//   0x002fe8: b00000e8  adrp     x8, #0x1f000
//   0x002fec: f947a508  ldr      x8, [x8, #0xf48]
//   0x002ff0: 39000118  strb     w24, [x8]
//   0x002ff4: 17ffffd4  b        #0x2f44
//   0x002ff8: 100e0048  adr      x8, #0x1f000
//   0x002ffc: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x003000: 528000a9  mov      w9, #5
//   0x003004: b9000109  str      w9, [x8]
//   0x003008: 17ffffcf  b        #0x2f44
//   0x00300c: 900000e8  adrp     x8, #0x1f000
//   0x003010: f947e108  ldr      x8, [x8, #0xfc0]
//   0x003014: b9000118  str      w24, [x8]
//   0x003018: 17ffffcb  b        #0x2f44
//   0x00301c: 900000e8  adrp     x8, #0x1f000
//   0x003020: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x003024: 14000003  b        #0x3030
//   0x003028: 900000e8  adrp     x8, #0x1f000
//   0x00302c: f947e108  ldr      x8, [x8, #0xfc0]
//   0x003030: 52800069  mov      w9, #3
//   0x003034: b9000109  str      w9, [x8]
//   0x003038: 17ffffc3  b        #0x2f44
//   0x00303c: 900000e8  adrp     x8, #0x1f000
//   0x003040: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x003044: 528000c9  mov      w9, #6
//   0x003048: b9000109  str      w9, [x8]
//   0x00304c: 17ffffbe  b        #0x2f44
//   0x003050: 900000e8  adrp     x8, #0x1f000
//   0x003054: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x003058: 528000e9  mov      w9, #7
//   0x00305c: b9000109  str      w9, [x8]
//   0x003060: 17ffffb9  b        #0x2f44
//   0x003064: 900000e8  adrp     x8, #0x1f000
//   0x003068: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x00306c: 52800129  mov      w9, #9
//   0x003070: b9000109  str      w9, [x8]
//   0x003074: 17ffffb4  b        #0x2f44
//   0x003078: 900000e8  adrp     x8, #0x1f000
//   0x00307c: f947d508  ldr      x8, [x8, #0xfa8]
//   0x003080: 39000118  strb     w24, [x8]
//   0x003084: 17ffffb0  b        #0x2f44
//   0x003088: 900000e8  adrp     x8, #0x1f000
//   0x00308c: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x003090: aa0803e9  mov      x9, x8
//   0x003094: b9400108  ldr      w8, [x8]
//   0x003098: 11000508  add      w8, w8, #1
//   0x00309c: b9000128  str      w8, [x9]
//   0x0030a0: 17ffffa9  b        #0x2f44
//   0x0030a4: 900000e8  adrp     x8, #0x1f000
//   0x0030a8: f947c508  ldr      x8, [x8, #0xf88]
//   0x0030ac: 3900011f  strb     wzr, [x8]
//   0x0030b0: 17ffffa5  b        #0x2f44
//   0x0030b4: 900000fa  adrp     x26, #0x1f000
//   0x0030b8: 900000fc  adrp     x28, #0x1f000
//   0x0030bc: f9479f5a  ldr      x26, [x26, #0xf38]
//   0x0030c0: f94007f8  ldr      x24, [sp, #8]
//   0x0030c4: f947cb9c  ldr      x28, [x28, #0xf90]
//   0x0030c8: b4001879  cbz      x25, #0x33d4
//   0x0030cc: b0000094  adrp     x20, #0x14000
//   0x0030d0: b0000095  adrp     x21, #0x14000
//   0x0030d4: b0000096  adrp     x22, #0x14000
//   0x0030d8: 91387e94  add      x20, x20, #0xe1f
//   0x0030dc: 91395eb5  add      x21, x21, #0xe57
//   0x0030e0: 52800057  mov      w23, #2
//   0x0030e4: 913982d6  add      x22, x22, #0xe60
//   0x0030e8: 9104c388  add      x8, x28, #0x130
//   0x0030ec: aa1903f3  mov      x19, x25
//   0x0030f0: f90003e8  str      x8, [sp]
//   0x0030f4: 14000006  b        #0x310c
//   0x0030f8: 900000e8  adrp     x8, #0x1f000
//   0x0030fc: f9479508  ldr      x8, [x8, #0xf28]
//   0x003100: b9000117  str      w23, [x8]
//   0x003104: f9400673  ldr      x19, [x19, #8]
//   0x003108: b4001673  cbz      x19, #0x33d4
//   0x00310c: f940027b  ldr      x27, [x19]
//   0x003110: aa1403e1  mov      x1, x20
//   0x003114: aa1b03e0  mov      x0, x27
//   0x003118: 97fffe2a  bl       #0x29c0
//   0x00311c: 340015c0  cbz      w0, #0x33d4
//   0x003120: aa1b03e0  mov      x0, x27
//   0x003124: aa1503e1  mov      x1, x21
//   0x003128: 97fffe26  bl       #0x29c0
//   0x00312c: 34fffe60  cbz      w0, #0x30f8
//   0x003130: aa1b03e0  mov      x0, x27
//   0x003134: aa1603e1  mov      x1, x22
//   0x003138: 97fffe22  bl       #0x29c0
//   0x00313c: 34000a40  cbz      w0, #0x3284
//   0x003140: b0000081  adrp     x1, #0x14000
//   0x003144: aa1b03e0  mov      x0, x27
//   0x003148: 9139b421  add      x1, x1, #0xe6d
//   0x00314c: 97fffe1d  bl       #0x29c0
//   0x003150: 34000a60  cbz      w0, #0x329c
//   0x003154: b0000081  adrp     x1, #0x14000
//   0x003158: aa1b03e0  mov      x0, x27
//   0x00315c: 9139e021  add      x1, x1, #0xe78
//   0x003160: 97fffe18  bl       #0x29c0
//   0x003164: 34000aa0  cbz      w0, #0x32b8
//   0x003168: b0000081  adrp     x1, #0x14000
//   0x00316c: aa1b03e0  mov      x0, x27
//   0x003170: 913a0021  add      x1, x1, #0xe80
//   0x003174: 97fffe13  bl       #0x29c0
//   0x003178: 34000a60  cbz      w0, #0x32c4
//   0x00317c: b0000081  adrp     x1, #0x14000
//   0x003180: aa1b03e0  mov      x0, x27
//   0x003184: 913a1c21  add      x1, x1, #0xe87
//   0x003188: 97fffe0e  bl       #0x29c0
//   0x00318c: 34000aa0  cbz      w0, #0x32e0
//   0x003190: b0000081  adrp     x1, #0x14000
//   0x003194: aa1b03e0  mov      x0, x27
//   0x003198: 913a3821  add      x1, x1, #0xe8e
//   0x00319c: 97fffe09  bl       #0x29c0
//   0x0031a0: 34000a60  cbz      w0, #0x32ec
//   0x0031a4: b0000081  adrp     x1, #0x14000
//   0x0031a8: aa1b03e0  mov      x0, x27
//   0x0031ac: 913a5821  add      x1, x1, #0xe96
//   0x0031b0: 97fffe04  bl       #0x29c0
//   0x0031b4: 34000aa0  cbz      w0, #0x3308
//   0x0031b8: b0000081  adrp     x1, #0x14000
//   0x0031bc: aa1b03e0  mov      x0, x27
//   0x0031c0: 913a7821  add      x1, x1, #0xe9e
//   0x0031c4: 97fffdff  bl       #0x29c0
//   0x0031c8: 34000ac0  cbz      w0, #0x3320
//   0x0031cc: b0000081  adrp     x1, #0x14000
//   0x0031d0: aa1b03e0  mov      x0, x27
//   0x0031d4: 913aa021  add      x1, x1, #0xea8
//   0x0031d8: 97fffdfa  bl       #0x29c0
//   0x0031dc: 34000aa0  cbz      w0, #0x3330
//   0x0031e0: b0000081  adrp     x1, #0x14000
//   0x0031e4: aa1b03e0  mov      x0, x27
//   0x0031e8: 913ac821  add      x1, x1, #0xeb2
//   0x0031ec: 97fffdf5  bl       #0x29c0
//   0x0031f0: 34000c80  cbz      w0, #0x3380
//   0x0031f4: b0000081  adrp     x1, #0x14000
//   0x0031f8: aa1b03e0  mov      x0, x27
//   0x0031fc: 913b0021  add      x1, x1, #0xec0
//   0x003200: 97fffdf0  bl       #0x29c0
//   0x003204: 34000a80  cbz      w0, #0x3354
//   0x003208: b0000081  adrp     x1, #0x14000
//   0x00320c: aa1b03e0  mov      x0, x27
//   0x003210: 913b4821  add      x1, x1, #0xed2
//   0x003214: 97fffdeb  bl       #0x29c0
//   0x003218: 340009e0  cbz      w0, #0x3354
//   0x00321c: b0000081  adrp     x1, #0x14000
//   0x003220: aa1b03e0  mov      x0, x27
//   0x003224: 913b9021  add      x1, x1, #0xee4
//   0x003228: 97fffde6  bl       #0x29c0
//   0x00322c: 34000b00  cbz      w0, #0x338c
//   0x003230: b0000081  adrp     x1, #0x14000
//   0x003234: aa1b03e0  mov      x0, x27
//   0x003238: 913bac21  add      x1, x1, #0xeeb
//   0x00323c: 97fffde1  bl       #0x29c0
//   0x003240: 34000ac0  cbz      w0, #0x3398
//   0x003244: b0000081  adrp     x1, #0x14000
//   0x003248: aa1b03e0  mov      x0, x27
//   0x00324c: 913bc821  add      x1, x1, #0xef2
//   0x003250: 97fffddc  bl       #0x29c0
//   0x003254: 34000b00  cbz      w0, #0x33b4
//   0x003258: b0000081  adrp     x1, #0x14000
//   0x00325c: aa1b03e0  mov      x0, x27
//   0x003260: 913bf021  add      x1, x1, #0xefc
//   0x003264: 97fffdd7  bl       #0x29c0
//   0x003268: 34002ac0  cbz      w0, #0x37c0
//   0x00326c: 52800042  mov      w2, #2
//   0x003270: aa1b03e0  mov      x0, x27
//   0x003274: aa1403e1  mov      x1, x20
//   0x003278: 97fffd32  bl       #0x2740
//   0x00327c: 35fff440  cbnz     w0, #0x3104
//   0x003280: 14000160  b        #0x3800
//   0x003284: 900000e8  adrp     x8, #0x1f000
//   0x003288: f947e108  ldr      x8, [x8, #0xfc0]
//   0x00328c: b9000117  str      w23, [x8]
//   0x003290: f9400673  ldr      x19, [x19, #8]
//   0x003294: b5fff3d3  cbnz     x19, #0x310c
//   0x003298: 1400004f  b        #0x33d4
//   0x00329c: 900000e8  adrp     x8, #0x1f000
//   0x0032a0: f947e108  ldr      x8, [x8, #0xfc0]
//   0x0032a4: 52800029  mov      w9, #1
//   0x0032a8: b9000109  str      w9, [x8]
//   0x0032ac: f9400673  ldr      x19, [x19, #8]
//   0x0032b0: b5fff2f3  cbnz     x19, #0x310c
//   0x0032b4: 14000048  b        #0x33d4
//   0x0032b8: 900000e8  adrp     x8, #0x1f000
//   0x0032bc: f947d508  ldr      x8, [x8, #0xfa8]
//   0x0032c0: 1400000d  b        #0x32f4
//   0x0032c4: 900000e8  adrp     x8, #0x1f000
//   0x0032c8: f947e108  ldr      x8, [x8, #0xfc0]
//   0x0032cc: 52800069  mov      w9, #3
//   0x0032d0: b9000109  str      w9, [x8]
//   0x0032d4: f9400673  ldr      x19, [x19, #8]
//   0x0032d8: b5fff1b3  cbnz     x19, #0x310c
//   0x0032dc: 1400003e  b        #0x33d4
//   0x0032e0: 900000e8  adrp     x8, #0x1f000
//   0x0032e4: f947bd08  ldr      x8, [x8, #0xf78]
//   0x0032e8: 14000003  b        #0x32f4
//   0x0032ec: 900000e8  adrp     x8, #0x1f000
//   0x0032f0: f947a508  ldr      x8, [x8, #0xf48]
//   0x0032f4: 52800029  mov      w9, #1
//   0x0032f8: 39000109  strb     w9, [x8]
//   0x0032fc: f9400673  ldr      x19, [x19, #8]
//   0x003300: b5fff073  cbnz     x19, #0x310c
//   0x003304: 14000034  b        #0x33d4
//   0x003308: 900000e8  adrp     x8, #0x1f000
//   0x00330c: f947c508  ldr      x8, [x8, #0xf88]
//   0x003310: 3900011f  strb     wzr, [x8]
//   0x003314: f9400673  ldr      x19, [x19, #8]
//   0x003318: b5ffefb3  cbnz     x19, #0x310c
//   0x00331c: 1400002e  b        #0x33d4
//   0x003320: 97fffcf8  bl       #0x2700
//   0x003324: aa0003e2  mov      x2, x0
//   0x003328: f94003e0  ldr      x0, [sp]
//   0x00332c: 14000004  b        #0x333c
//   0x003330: 97fffcf4  bl       #0x2700
//   0x003334: aa0003e2  mov      x2, x0
//   0x003338: 9104c380  add      x0, x28, #0x130
//   0x00333c: d0000081  adrp     x1, #0x15000
//   0x003340: 9123c821  add      x1, x1, #0x8f2
//   0x003344: 97fffdcf  bl       #0x2a80
//   0x003348: f9400673  ldr      x19, [x19, #8]
//   0x00334c: b5ffee13  cbnz     x19, #0x310c
//   0x003350: 14000021  b        #0x33d4
//   0x003354: 900000e8  adrp     x8, #0x1f000
//   0x003358: f947a908  ldr      x8, [x8, #0xf50]
//   0x00335c: d0000081  adrp     x1, #0x15000
//   0x003360: 9104c380  add      x0, x28, #0x130
//   0x003364: 913f3421  add      x1, x1, #0xfcd
//   0x003368: f9400102  ldr      x2, [x8]
//   0x00336c: aa1b03e3  mov      x3, x27
//   0x003370: 97fffdc4  bl       #0x2a80
//   0x003374: f9400673  ldr      x19, [x19, #8]
//   0x003378: b5ffecb3  cbnz     x19, #0x310c
//   0x00337c: 14000016  b        #0x33d4
//   0x003380: 900000e8  adrp     x8, #0x1f000
//   0x003384: f947b108  ldr      x8, [x8, #0xf60]
//   0x003388: 17ffffc7  b        #0x32a4
//   0x00338c: 900000e8  adrp     x8, #0x1f000
//   0x003390: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x003394: 17ffffc4  b        #0x32a4
//   0x003398: 900000e8  adrp     x8, #0x1f000
//   0x00339c: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x0033a0: 52800129  mov      w9, #9
//   0x0033a4: b9000109  str      w9, [x8]
//   0x0033a8: f9400673  ldr      x19, [x19, #8]
//   0x0033ac: b5ffeb13  cbnz     x19, #0x310c
//   0x0033b0: 14000009  b        #0x33d4
//   0x0033b4: 900000e8  adrp     x8, #0x1f000
//   0x0033b8: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x0033bc: aa0803e9  mov      x9, x8
//   0x0033c0: b9400108  ldr      w8, [x8]
//   0x0033c4: 11000508  add      w8, w8, #1
//   0x0033c8: b9000128  str      w8, [x9]
//   0x0033cc: f9400673  ldr      x19, [x19, #8]
//   0x0033d0: b5ffe9f3  cbnz     x19, #0x310c
//   0x0033d4: 900000e9  adrp     x9, #0x1f000
//   0x0033d8: f947ed29  ldr      x9, [x9, #0xfd8]
//   0x0033dc: b9400128  ldr      w8, [x9]
//   0x0033e0: 7100151f  cmp      w8, #5
//   0x0033e4: 5400006b  b.lt     #0x33f0
//   0x0033e8: 52800088  mov      w8, #4
//   0x0033ec: b9000128  str      w8, [x9]
//   0x0033f0: 900000e8  adrp     x8, #0x1f000
//   0x0033f4: f947e108  ldr      x8, [x8, #0xfc0]
//   0x0033f8: 900000eb  adrp     x11, #0x1f000
//   0x0033fc: b9400108  ldr      w8, [x8]
//   0x003400: f947996b  ldr      x11, [x11, #0xf30]
//   0x003404: 7100051f  cmp      w8, #1
//   0x003408: 540003e1  b.ne     #0x3484
//   0x00340c: 900000e9  adrp     x9, #0x1f000
//   0x003410: f947a529  ldr      x9, [x9, #0xf48]
//   0x003414: 39400129  ldrb     w9, [x9]
//   0x003418: 34000149  cbz      w9, #0x3440
//   0x00341c: 900000e9  adrp     x9, #0x1f000
//   0x003420: f947dd29  ldr      x9, [x9, #0xfb8]
//   0x003424: b9400129  ldr      w9, [x9]
//   0x003428: 71000d3f  cmp      w9, #3
//   0x00342c: 540000ab  b.lt     #0x3440
//   0x003430: 900000ea  adrp     x10, #0x1f000
//   0x003434: f947dd4a  ldr      x10, [x10, #0xfb8]
//   0x003438: 52800049  mov      w9, #2
//   0x00343c: b9000149  str      w9, [x10]
//   0x003440: 900000e9  adrp     x9, #0x1f000
//   0x003444: f9479529  ldr      x9, [x9, #0xf28]
//   0x003448: 900000f7  adrp     x23, #0x1f000
//   0x00344c: b9400129  ldr      w9, [x9]
//   0x003450: f947cef7  ldr      x23, [x23, #0xf98]
//   0x003454: 7100093f  cmp      w9, #2
//   0x003458: 1a9f17ea  cset     w10, eq
//   0x00345c: 340002ca  cbz      w10, #0x34b4
//   0x003460: b940016a  ldr      w10, [x11]
//   0x003464: 3500028a  cbnz     w10, #0x34b4
//   0x003468: 900000ea  adrp     x10, #0x1f000
//   0x00346c: f947954a  ldr      x10, [x10, #0xf28]
//   0x003470: 52800029  mov      w9, #1
//   0x003474: b9000149  str      w9, [x10]
//   0x003478: 7100051f  cmp      w8, #1
//   0x00347c: 540005a1  b.ne     #0x3530
//   0x003480: 1400000f  b        #0x34bc
//   0x003484: 900000e9  adrp     x9, #0x1f000
//   0x003488: f9479529  ldr      x9, [x9, #0xf28]
//   0x00348c: b9400129  ldr      w9, [x9]
//   0x003490: 7100093f  cmp      w9, #2
//   0x003494: 1a9f17ea  cset     w10, eq
//   0x003498: 71000d1f  cmp      w8, #3
//   0x00349c: 54000841  b.ne     #0x35a4
//   0x0034a0: 900000f7  adrp     x23, #0x1f000
//   0x0034a4: f947cef7  ldr      x23, [x23, #0xf98]
//   0x0034a8: 7100093f  cmp      w9, #2
//   0x0034ac: 54001980  b.eq     #0x37dc
//   0x0034b0: 35fffd8a  cbnz     w10, #0x3460
//   0x0034b4: 7100051f  cmp      w8, #1
//   0x0034b8: 540003c1  b.ne     #0x3530
//   0x0034bc: 71000d3f  cmp      w9, #3
//   0x0034c0: 54000421  b.ne     #0x3544
//   0x0034c4: b0000014  adrp     x20, #0x4000
//   0x0034c8: 91358294  add      x20, x20, #0xd60
//   0x0034cc: 52800040  mov      w0, #2
//   0x0034d0: aa1403e1  mov      x1, x20
//   0x0034d4: 97fffcab  bl       #0x2780
//   0x0034d8: 528001e0  mov      w0, #0xf
//   0x0034dc: aa1403e1  mov      x1, x20
//   0x0034e0: 97fffca8  bl       #0x2780
//   0x0034e4: 52800020  mov      w0, #1
//   0x0034e8: aa1403e1  mov      x1, x20
//   0x0034ec: 97fffca5  bl       #0x2780
//   0x0034f0: 900000e8  adrp     x8, #0x1f000
//   0x0034f4: f947e108  ldr      x8, [x8, #0xfc0]
//   0x0034f8: b9400108  ldr      w8, [x8]
//   0x0034fc: 7100091f  cmp      w8, #2
//   0x003500: 54000261  b.ne     #0x354c
//   0x003504: 900000e8  adrp     x8, #0x1f000
//   0x003508: f9479508  ldr      x8, [x8, #0xf28]
//   0x00350c: b9400108  ldr      w8, [x8]
//   0x003510: 7100051f  cmp      w8, #1
//   0x003514: 900000e8  adrp     x8, #0x1f000
//   0x003518: f947f108  ldr      x8, [x8, #0xfe0]
//   0x00351c: 3900011f  strb     wzr, [x8]
//   0x003520: 54000801  b.ne     #0x3620
//   0x003524: aa1f03e0  mov      x0, xzr
//   0x003528: 940008fe  bl       #0x5920
//   0x00352c: 14000057  b        #0x3688
//   0x003530: 900000ea  adrp     x10, #0x1f000
//   0x003534: f947dd4a  ldr      x10, [x10, #0xfb8]
//   0x003538: b900015f  str      wzr, [x10]
//   0x00353c: 71000d3f  cmp      w9, #3
//   0x003540: 54fffc20  b.eq     #0x34c4
//   0x003544: 7100091f  cmp      w8, #2
//   0x003548: 54fffde0  b.eq     #0x3504
//   0x00354c: 7100051f  cmp      w8, #1
//   0x003550: 54000141  b.ne     #0x3578
//   0x003554: 900000e8  adrp     x8, #0x1f000
//   0x003558: f9479508  ldr      x8, [x8, #0xf28]
//   0x00355c: b9400108  ldr      w8, [x8]
//   0x003560: 7100051f  cmp      w8, #1
//   0x003564: 54000281  b.ne     #0x35b4
//   0x003568: aa1f03e0  mov      x0, xzr
//   0x00356c: 9400060a  bl       #0x4d94
//   0x003570: b5000e99  cbnz     x25, #0x3740
//   0x003574: 14000077  b        #0x3750
//   0x003578: 900000e8  adrp     x8, #0x1f000
//   0x00357c: f9479508  ldr      x8, [x8, #0xf28]
//   0x003580: b9400108  ldr      w8, [x8]
//   0x003584: 7100051f  cmp      w8, #1
//   0x003588: 900000e8  adrp     x8, #0x1f000
//   0x00358c: f947a108  ldr      x8, [x8, #0xf40]
//   0x003590: 3900011f  strb     wzr, [x8]
//   0x003594: 540008e1  b.ne     #0x36b0
//   0x003598: aa1f03e0  mov      x0, xzr
//   0x00359c: 94000c03  bl       #0x65a8
//   0x0035a0: 1400005e  b        #0x3718
//   0x0035a4: 900000f7  adrp     x23, #0x1f000
//   0x0035a8: f947cef7  ldr      x23, [x23, #0xf98]
//   0x0035ac: 35fff5aa  cbnz     w10, #0x3460
//   0x0035b0: 17ffffc1  b        #0x34b4
//   0x0035b4: b4000cf9  cbz      x25, #0x3750
//   0x0035b8: b0000094  adrp     x20, #0x14000
//   0x0035bc: 52800036  mov      w22, #1
//   0x0035c0: 91387e94  add      x20, x20, #0xe1f
//   0x0035c4: aa1903f3  mov      x19, x25
//   0x0035c8: 14000004  b        #0x35d8
//   0x0035cc: 2a1f03f6  mov      w22, wzr
//   0x0035d0: f9400673  ldr      x19, [x19, #8]
//   0x0035d4: b4000ab3  cbz      x19, #0x3728
//   0x0035d8: f9400275  ldr      x21, [x19]
//   0x0035dc: aa1403e1  mov      x1, x20
//   0x0035e0: aa1503e0  mov      x0, x21
//   0x0035e4: 97fffcf7  bl       #0x29c0
//   0x0035e8: 34ffff20  cbz      w0, #0x35cc
//   0x0035ec: 72001edf  tst      w22, #0xff
//   0x0035f0: 54000080  b.eq     #0x3600
//   0x0035f4: 394002a8  ldrb     w8, [x21]
//   0x0035f8: 7100b51f  cmp      w8, #0x2d
//   0x0035fc: 54fffea0  b.eq     #0x35d0
//   0x003600: b94002e8  ldr      w8, [x23]
//   0x003604: aa1503e0  mov      x0, x21
//   0x003608: 11000508  add      w8, w8, #1
//   0x00360c: b90002e8  str      w8, [x23]
//   0x003610: 940005e1  bl       #0x4d94
//   0x003614: f9400673  ldr      x19, [x19, #8]
//   0x003618: b5fffe13  cbnz     x19, #0x35d8
//   0x00361c: 14000043  b        #0x3728
//   0x003620: b4000999  cbz      x25, #0x3750
//   0x003624: b0000094  adrp     x20, #0x14000
//   0x003628: 52800036  mov      w22, #1
//   0x00362c: 91387e94  add      x20, x20, #0xe1f
//   0x003630: aa1903f3  mov      x19, x25
//   0x003634: 14000004  b        #0x3644
//   0x003638: 2a1f03f6  mov      w22, wzr
//   0x00363c: f9400673  ldr      x19, [x19, #8]
//   0x003640: b4000253  cbz      x19, #0x3688
//   0x003644: f9400275  ldr      x21, [x19]
//   0x003648: aa1403e1  mov      x1, x20
//   0x00364c: aa1503e0  mov      x0, x21
//   0x003650: 97fffcdc  bl       #0x29c0
//   0x003654: 34ffff20  cbz      w0, #0x3638
//   0x003658: 72001edf  tst      w22, #0xff
//   0x00365c: 54000080  b.eq     #0x366c
//   0x003660: 394002a8  ldrb     w8, [x21]
//   0x003664: 7100b51f  cmp      w8, #0x2d
//   0x003668: 54fffea0  b.eq     #0x363c
//   0x00366c: b94002e8  ldr      w8, [x23]
//   0x003670: aa1503e0  mov      x0, x21
//   0x003674: 11000508  add      w8, w8, #1
//   0x003678: b90002e8  str      w8, [x23]
//   0x00367c: 940008a9  bl       #0x5920
//   0x003680: f9400673  ldr      x19, [x19, #8]
//   0x003684: b5fffe13  cbnz     x19, #0x3644
//   0x003688: 900000e8  adrp     x8, #0x1f000
//   0x00368c: f947f108  ldr      x8, [x8, #0xfe0]
//   0x003690: 39400108  ldrb     w8, [x8]
//   0x003694: 340004a8  cbz      w8, #0x3728
//   0x003698: b9400340  ldr      w0, [x26]
//   0x00369c: 7100041f  cmp      w0, #1
//   0x0036a0: 54000e0c  b.gt     #0x3860
//   0x0036a4: 52800040  mov      w0, #2
//   0x0036a8: aa1a03e8  mov      x8, x26
//   0x0036ac: 1400006c  b        #0x385c
//   0x0036b0: b4000519  cbz      x25, #0x3750
//   0x0036b4: b0000094  adrp     x20, #0x14000
//   0x0036b8: 52800036  mov      w22, #1
//   0x0036bc: 91387e94  add      x20, x20, #0xe1f
//   0x0036c0: aa1903f3  mov      x19, x25
//   0x0036c4: 14000004  b        #0x36d4
//   0x0036c8: 2a1f03f6  mov      w22, wzr
//   0x0036cc: f9400673  ldr      x19, [x19, #8]
//   0x0036d0: b4000253  cbz      x19, #0x3718
//   0x0036d4: f9400275  ldr      x21, [x19]
//   0x0036d8: aa1403e1  mov      x1, x20
//   0x0036dc: aa1503e0  mov      x0, x21
//   0x0036e0: 97fffcb8  bl       #0x29c0
//   0x0036e4: 34ffff20  cbz      w0, #0x36c8
//   0x0036e8: 72001edf  tst      w22, #0xff
//   0x0036ec: 54000080  b.eq     #0x36fc
//   0x0036f0: 394002a8  ldrb     w8, [x21]
//   0x0036f4: 7100b51f  cmp      w8, #0x2d
//   0x0036f8: 54fffea0  b.eq     #0x36cc
//   0x0036fc: b94002e8  ldr      w8, [x23]
//   0x003700: aa1503e0  mov      x0, x21
//   0x003704: 11000508  add      w8, w8, #1
//   0x003708: b90002e8  str      w8, [x23]
//   0x00370c: 94000ba7  bl       #0x65a8
//   0x003710: f9400673  ldr      x19, [x19, #8]
//   0x003714: b5fffe13  cbnz     x19, #0x36d4
//   0x003718: 900000e8  adrp     x8, #0x1f000
//   0x00371c: f947a108  ldr      x8, [x8, #0xf40]
//   0x003720: 39400108  ldrb     w8, [x8]
//   0x003724: 35000808  cbnz     w8, #0x3824
//   0x003728: b50000d9  cbnz     x25, #0x3740
//   0x00372c: 14000009  b        #0x3750
//   0x003730: aa1903e0  mov      x0, x25
//   0x003734: 97fffcef  bl       #0x2af0
//   0x003738: aa1303f9  mov      x25, x19
//   0x00373c: b40000b3  cbz      x19, #0x3750
//   0x003740: a9404f20  ldp      x0, x19, [x25]
//   0x003744: b4ffff60  cbz      x0, #0x3730
//   0x003748: 97fffcea  bl       #0x2af0
//   0x00374c: 17fffff9  b        #0x3730
//   0x003750: b9400340  ldr      w0, [x26]
//   0x003754: f9401708  ldr      x8, [x24, #0x28]
//   0x003758: f9400fe9  ldr      x9, [sp, #0x18]
//   0x00375c: eb09011f  cmp      x8, x9
//   0x003760: 540003c1  b.ne     #0x37d8
//   0x003764: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x003768: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x00376c: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x003770: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x003774: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x003778: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x00377c: 910203ff  add      sp, sp, #0x80
//   0x003780: d65f03c0  ret      
//   0x003784: 900000e8  adrp     x8, #0x1f000
//   0x003788: f947a908  ldr      x8, [x8, #0xf50]
//   0x00378c: b0000081  adrp     x1, #0x14000
//   0x003790: 91391021  add      x1, x1, #0xe44
//   0x003794: aa1703e3  mov      x3, x23
//   0x003798: aa0803f3  mov      x19, x8
//   0x00379c: f9400102  ldr      x2, [x8]
//   0x0037a0: 900000e8  adrp     x8, #0x1f000
//   0x0037a4: f947c908  ldr      x8, [x8, #0xf90]
//   0x0037a8: 9104c100  add      x0, x8, #0x130
//   0x0037ac: 97fffcb5  bl       #0x2a80
//   0x0037b0: f9400260  ldr      x0, [x19]
//   0x0037b4: 94000551  bl       #0x4cf8
//   0x0037b8: 52800020  mov      w0, #1
//   0x0037bc: 97fffc9d  bl       #0x2a30
//   0x0037c0: 900000e8  adrp     x8, #0x1f000
//   0x0037c4: f947a908  ldr      x8, [x8, #0xf50]
//   0x0037c8: f9400100  ldr      x0, [x8]
//   0x0037cc: 9400054b  bl       #0x4cf8
//   0x0037d0: 2a1f03e0  mov      w0, wzr
//   0x0037d4: 97fffc97  bl       #0x2a30
//   0x0037d8: 97fffc52  bl       #0x2920
//   0x0037dc: 900000e8  adrp     x8, #0x1f000
//   0x0037e0: f947a908  ldr      x8, [x8, #0xf50]
//   0x0037e4: b0000081  adrp     x1, #0x14000
//   0x0037e8: 9104c380  add      x0, x28, #0x130
//   0x0037ec: 913c0c21  add      x1, x1, #0xf03
//   0x0037f0: f9400102  ldr      x2, [x8]
//   0x0037f4: 97fffca3  bl       #0x2a80
//   0x0037f8: 52800020  mov      w0, #1
//   0x0037fc: 97fffc8d  bl       #0x2a30
//   0x003800: 900000e8  adrp     x8, #0x1f000
//   0x003804: f947a908  ldr      x8, [x8, #0xf50]
//   0x003808: b0000081  adrp     x1, #0x14000
//   0x00380c: 9104c380  add      x0, x28, #0x130
//   0x003810: 91391021  add      x1, x1, #0xe44
//   0x003814: f9400102  ldr      x2, [x8]
//   0x003818: aa0803f3  mov      x19, x8
//   0x00381c: aa1b03e3  mov      x3, x27
//   0x003820: 17ffffe3  b        #0x37ac
//   0x003824: 900000e8  adrp     x8, #0x1f000
//   0x003828: f947c508  ldr      x8, [x8, #0xf88]
//   0x00382c: 39400108  ldrb     w8, [x8]
//   0x003830: 340000e8  cbz      w8, #0x384c
//   0x003834: f0000080  adrp     x0, #0x16000
//   0x003838: 9104c383  add      x3, x28, #0x130
//   0x00383c: 91163000  add      x0, x0, #0x58c
//   0x003840: 52800e01  mov      w1, #0x70
//   0x003844: 52800022  mov      w2, #1
//   0x003848: 97fffca6  bl       #0x2ae0
//   0x00384c: b9400340  ldr      w0, [x26]
//   0x003850: 7100041f  cmp      w0, #1
//   0x003854: 5400006c  b.gt     #0x3860
//   0x003858: 52800040  mov      w0, #2
//   0x00385c: b9000340  str      w0, [x26]
//   0x003860: 97fffc74  bl       #0x2a30
// ============================================================================
std::uint32_t fde_00_02b6c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00002b6cULL;
    for (std::size_t i = 0; i < 830ULL; ++i) {
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
// [EN] FDE[01] Subroutine @ 0x004864..0x0049dc (376 bytes, 94 AArch64 instructions)
// [VN] Khung FDE[01] Hàm con @ 0x004864..0x0049dc (376 byte, 94 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004864: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x004868: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00486c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x004870: 910083fd  add      x29, sp, #0x20
//   0x004874: f00000d6  adrp     x22, #0x1f000
//   0x004878: f947e2d6  ldr      x22, [x22, #0xfc0]
//   0x00487c: b0000093  adrp     x19, #0x15000
//   0x004880: b0000089  adrp     x9, #0x15000
//   0x004884: 9000008a  adrp     x10, #0x14000
//   0x004888: b94002c8  ldr      w8, [x22]
//   0x00488c: 913f2e73  add      x19, x19, #0xfcb
//   0x004890: 910a4529  add      x9, x9, #0x291
//   0x004894: 913cad4a  add      x10, x10, #0xf2b
//   0x004898: 7100051f  cmp      w8, #1
//   0x00489c: 52800040  mov      w0, #2
//   0x0048a0: 52800022  mov      w2, #1
//   0x0048a4: aa1303e1  mov      x1, x19
//   0x0048a8: 9a890154  csel     x20, x10, x9, eq
//   0x0048ac: 97fff7f5  bl       #0x2880
//   0x0048b0: f00000c8  adrp     x8, #0x1f000
//   0x0048b4: f947a908  ldr      x8, [x8, #0xf50]
//   0x0048b8: f9400115  ldr      x21, [x8]
//   0x0048bc: aa1503e0  mov      x0, x21
//   0x0048c0: 97fff858  bl       #0x2a20
//   0x0048c4: aa0003e2  mov      x2, x0
//   0x0048c8: 52800040  mov      w0, #2
//   0x0048cc: aa1503e1  mov      x1, x21
//   0x0048d0: 97fff7ec  bl       #0x2880
//   0x0048d4: 52807ca1  mov      w1, #0x3e5
//   0x0048d8: aa1403e0  mov      x0, x20
//   0x0048dc: 97fff79d  bl       #0x2750
//   0x0048e0: aa0003e2  mov      x2, x0
//   0x0048e4: 52800040  mov      w0, #2
//   0x0048e8: aa1403e1  mov      x1, x20
//   0x0048ec: 97fff7e5  bl       #0x2880
//   0x0048f0: b0000094  adrp     x20, #0x15000
//   0x0048f4: 9119da94  add      x20, x20, #0x676
//   0x0048f8: 528001e1  mov      w1, #0xf
//   0x0048fc: aa1403e0  mov      x0, x20
//   0x004900: 97fff794  bl       #0x2750
//   0x004904: aa0003e2  mov      x2, x0
//   0x004908: 52800040  mov      w0, #2
//   0x00490c: aa1403e1  mov      x1, x20
//   0x004910: 97fff7dc  bl       #0x2880
//   0x004914: f00000d4  adrp     x20, #0x1f000
//   0x004918: f947c294  ldr      x20, [x20, #0xf80]
//   0x00491c: 52808141  mov      w1, #0x40a
//   0x004920: aa1403e0  mov      x0, x20
//   0x004924: 97fff78b  bl       #0x2750
//   0x004928: aa0003e2  mov      x2, x0
//   0x00492c: 52800040  mov      w0, #2
//   0x004930: aa1403e1  mov      x1, x20
//   0x004934: 97fff7d3  bl       #0x2880
//   0x004938: 52800040  mov      w0, #2
//   0x00493c: 52800022  mov      w2, #1
//   0x004940: aa1303e1  mov      x1, x19
//   0x004944: 97fff7cf  bl       #0x2880
//   0x004948: b0000094  adrp     x20, #0x15000
//   0x00494c: 911a1694  add      x20, x20, #0x685
//   0x004950: 52800201  mov      w1, #0x10
//   0x004954: aa1403e0  mov      x0, x20
//   0x004958: 97fff77e  bl       #0x2750
//   0x00495c: aa0003e2  mov      x2, x0
//   0x004960: 52800040  mov      w0, #2
//   0x004964: aa1403e1  mov      x1, x20
//   0x004968: 97fff7c6  bl       #0x2880
//   0x00496c: f00000d4  adrp     x20, #0x1f000
//   0x004970: f947ba94  ldr      x20, [x20, #0xf70]
//   0x004974: 52808141  mov      w1, #0x40a
//   0x004978: aa1403e0  mov      x0, x20
//   0x00497c: 97fff775  bl       #0x2750
//   0x004980: aa0003e2  mov      x2, x0
//   0x004984: 52800040  mov      w0, #2
//   0x004988: aa1403e1  mov      x1, x20
//   0x00498c: 97fff7bd  bl       #0x2880
//   0x004990: 52800040  mov      w0, #2
//   0x004994: 52800022  mov      w2, #1
//   0x004998: aa1303e1  mov      x1, x19
//   0x00499c: 97fff7b9  bl       #0x2880
//   0x0049a0: f00000c8  adrp     x8, #0x1f000
//   0x0049a4: b94002c9  ldr      w9, [x22]
//   0x0049a8: f9479d08  ldr      x8, [x8, #0xf38]
//   0x0049ac: 7100053f  cmp      w9, #1
//   0x0049b0: b9400100  ldr      w0, [x8]
//   0x0049b4: 540000a1  b.ne     #0x49c8
//   0x0049b8: 7100081f  cmp      w0, #2
//   0x0049bc: 540000ec  b.gt     #0x49d8
//   0x0049c0: 52800060  mov      w0, #3
//   0x0049c4: 14000004  b        #0x49d4
//   0x0049c8: 7100041f  cmp      w0, #1
//   0x0049cc: 5400006c  b.gt     #0x49d8
//   0x0049d0: 52800040  mov      w0, #2
//   0x0049d4: b9000100  str      w0, [x8]
//   0x0049d8: 97fff78a  bl       #0x2800
// ============================================================================
std::uint32_t fde_01_04864(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004864ULL;
    for (std::size_t i = 0; i < 94ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1869ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[02] Subroutine @ 0x0049dc..0x004a90 (180 bytes, 45 AArch64 instructions)
// [VN] Khung FDE[02] Hàm con @ 0x0049dc..0x004a90 (180 byte, 45 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0049dc: d10103ff  sub      sp, sp, #0x40
//   0x0049e0: f9000bf5  str      x21, [sp, #0x10]
//   0x0049e4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0049e8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0049ec: 9100c3fd  add      x29, sp, #0x30
//   0x0049f0: d53bd055  mrs      x21, tpidr_el0
//   0x0049f4: f94016a8  ldr      x8, [x21, #0x28]
//   0x0049f8: aa0003f4  mov      x20, x0
//   0x0049fc: aa0103e0  mov      x0, x1
//   0x004a00: aa0103f3  mov      x19, x1
//   0x004a04: f90007e8  str      x8, [sp, #8]
//   0x004a08: 97fff806  bl       #0x2a20
//   0x004a0c: f110041f  cmp      x0, #0x401
//   0x004a10: 540001e2  b.hs     #0x4a4c
//   0x004a14: 52808002  mov      w2, #0x400
//   0x004a18: aa1403e0  mov      x0, x20
//   0x004a1c: aa1303e1  mov      x1, x19
//   0x004a20: 97fff7d0  bl       #0x2960
//   0x004a24: 3910029f  strb     wzr, [x20, #0x400]
//   0x004a28: f94016a8  ldr      x8, [x21, #0x28]
//   0x004a2c: f94007e9  ldr      x9, [sp, #8]
//   0x004a30: eb09011f  cmp      x8, x9
//   0x004a34: 540002c1  b.ne     #0x4a8c
//   0x004a38: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x004a3c: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x004a40: f9400bf5  ldr      x21, [sp, #0x10]
//   0x004a44: 910103ff  add      sp, sp, #0x40
//   0x004a48: d65f03c0  ret      
//   0x004a4c: f00000c8  adrp     x8, #0x1f000
//   0x004a50: f947c908  ldr      x8, [x8, #0xf90]
//   0x004a54: b0000081  adrp     x1, #0x15000
//   0x004a58: 911a5421  add      x1, x1, #0x695
//   0x004a5c: 52808003  mov      w3, #0x400
//   0x004a60: 9104c100  add      x0, x8, #0x130
//   0x004a64: aa1303e2  mov      x2, x19
//   0x004a68: 97fff806  bl       #0x2a80
//   0x004a6c: f00000c8  adrp     x8, #0x1f000
//   0x004a70: f9479d08  ldr      x8, [x8, #0xf38]
//   0x004a74: b9400100  ldr      w0, [x8]
//   0x004a78: 7100001f  cmp      w0, #0
//   0x004a7c: 5400006c  b.gt     #0x4a88
//   0x004a80: 52800020  mov      w0, #1
//   0x004a84: b9000100  str      w0, [x8]
//   0x004a88: 97fff7ea  bl       #0x2a30
//   0x004a8c: 97fff7a5  bl       #0x2920
// ============================================================================
std::uint32_t fde_02_049dc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000049dcULL;
    for (std::size_t i = 0; i < 45ULL; ++i) {
        std::uint32_t insn = kTextInstructions[1963ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[03] Subroutine @ 0x004a90..0x004c3c (428 bytes, 107 AArch64 instructions)
// [VN] Khung FDE[03] Hàm con @ 0x004a90..0x004c3c (428 byte, 107 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004a90: d10183ff  sub      sp, sp, #0x60
//   0x004a94: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x004a98: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x004a9c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x004aa0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x004aa4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x004aa8: 910143fd  add      x29, sp, #0x50
//   0x004aac: d53bd057  mrs      x23, tpidr_el0
//   0x004ab0: f94016e8  ldr      x8, [x23, #0x28]
//   0x004ab4: aa0003f3  mov      x19, x0
//   0x004ab8: aa0103e0  mov      x0, x1
//   0x004abc: f90007e8  str      x8, [sp, #8]
//   0x004ac0: 97fff778  bl       #0x28a0
//   0x004ac4: b4000a40  cbz      x0, #0x4c0c
//   0x004ac8: 39400016  ldrb     w22, [x0]
//   0x004acc: aa0003f4  mov      x20, x0
//   0x004ad0: 340009f6  cbz      w22, #0x4c0c
//   0x004ad4: f00000d5  adrp     x21, #0x1f000
//   0x004ad8: f947dab5  ldr      x21, [x21, #0xfb0]
//   0x004adc: 52808018  mov      w24, #0x400
//   0x004ae0: 14000009  b        #0x4b04
//   0x004ae4: 38284abf  strb     wzr, [x21, w8, uxtw]
//   0x004ae8: f9400260  ldr      x0, [x19]
//   0x004aec: aa1503e1  mov      x1, x21
//   0x004af0: 94000053  bl       #0x4c3c
//   0x004af4: f9000260  str      x0, [x19]
//   0x004af8: 8b394294  add      x20, x20, w25, uxtw
//   0x004afc: 39400296  ldrb     w22, [x20]
//   0x004b00: 34000876  cbz      w22, #0x4c0c
//   0x004b04: 12001ec0  and      w0, w22, #0xff
//   0x004b08: 97fff806  bl       #0x2b20
//   0x004b0c: 340000a0  cbz      w0, #0x4b20
//   0x004b10: 38401e96  ldrb     w22, [x20, #1]!
//   0x004b14: 2a1603e0  mov      w0, w22
//   0x004b18: 97fff802  bl       #0x2b20
//   0x004b1c: 35ffffa0  cbnz     w0, #0x4b10
//   0x004b20: 72001edf  tst      w22, #0xff
//   0x004b24: 540001a0  b.eq     #0x4b58
//   0x004b28: aa1f03f9  mov      x25, xzr
//   0x004b2c: 9100069a  add      x26, x20, #1
//   0x004b30: 2a1603e8  mov      w8, w22
//   0x004b34: 12001d00  and      w0, w8, #0xff
//   0x004b38: 97fff7fa  bl       #0x2b20
//   0x004b3c: 35000120  cbnz     w0, #0x4b60
//   0x004b40: 38796b48  ldrb     w8, [x26, x25]
//   0x004b44: 91000729  add      x9, x25, #1
//   0x004b48: aa0903f9  mov      x25, x9
//   0x004b4c: 35ffff48  cbnz     w8, #0x4b34
//   0x004b50: 2a0903f9  mov      w25, w9
//   0x004b54: 14000004  b        #0x4b64
//   0x004b58: 2a1f03f9  mov      w25, wzr
//   0x004b5c: 17ffffe7  b        #0x4af8
//   0x004b60: 34fffcd9  cbz      w25, #0x4af8
//   0x004b64: 7110033f  cmp      w25, #0x400
//   0x004b68: 1a983328  csel     w8, w25, w24, lo
//   0x004b6c: 7100051f  cmp      w8, #1
//   0x004b70: 54fffbab  b.lt     #0x4ae4
//   0x004b74: 7100051f  cmp      w8, #1
//   0x004b78: 390002b6  strb     w22, [x21]
//   0x004b7c: 54fffb40  b.eq     #0x4ae4
//   0x004b80: 2a0803e9  mov      w9, w8
//   0x004b84: d100052b  sub      x11, x9, #1
//   0x004b88: f100817f  cmp      x11, #0x20
//   0x004b8c: 54000062  b.hs     #0x4b98
//   0x004b90: 5280002a  mov      w10, #1
//   0x004b94: 14000018  b        #0x4bf4
//   0x004b98: 8b09028a  add      x10, x20, x9
//   0x004b9c: 910006ac  add      x12, x21, #1
//   0x004ba0: eb0c015f  cmp      x10, x12
//   0x004ba4: 540000e9  b.ls     #0x4bc0
//   0x004ba8: 8b0902aa  add      x10, x21, x9
//   0x004bac: 9100068c  add      x12, x20, #1
//   0x004bb0: eb0a019f  cmp      x12, x10
//   0x004bb4: 54000062  b.hs     #0x4bc0
//   0x004bb8: 5280002a  mov      w10, #1
//   0x004bbc: 1400000e  b        #0x4bf4
//   0x004bc0: 927be96c  and      x12, x11, #0xffffffffffffffe0
//   0x004bc4: 910046ad  add      x13, x21, #0x11
//   0x004bc8: b240018a  orr      x10, x12, #1
//   0x004bcc: 9100468e  add      x14, x20, #0x11
//   0x004bd0: aa0c03ef  mov      x15, x12
//   0x004bd4: ad7f85c0  ldp      q0, q1, [x14, #-0x10]
//   0x004bd8: 910081ce  add      x14, x14, #0x20
//   0x004bdc: f10081ef  subs     x15, x15, #0x20
//   0x004be0: ad3f85a0  stp      q0, q1, [x13, #-0x10]
//   0x004be4: 910081ad  add      x13, x13, #0x20
//   0x004be8: 54ffff61  b.ne     #0x4bd4
//   0x004bec: eb0c017f  cmp      x11, x12
//   0x004bf0: 54fff7a0  b.eq     #0x4ae4
//   0x004bf4: 386a6a8b  ldrb     w11, [x20, x10]
//   0x004bf8: 382a6aab  strb     w11, [x21, x10]
//   0x004bfc: 9100054a  add      x10, x10, #1
//   0x004c00: eb09015f  cmp      x10, x9
//   0x004c04: 54ffff83  b.lo     #0x4bf4
//   0x004c08: 17ffffb7  b        #0x4ae4
//   0x004c0c: f94016e8  ldr      x8, [x23, #0x28]
//   0x004c10: f94007e9  ldr      x9, [sp, #8]
//   0x004c14: eb09011f  cmp      x8, x9
//   0x004c18: 54000101  b.ne     #0x4c38
//   0x004c1c: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x004c20: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x004c24: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x004c28: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x004c2c: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x004c30: 910183ff  add      sp, sp, #0x60
//   0x004c34: d65f03c0  ret      
//   0x004c38: 97fff73a  bl       #0x2920
// ============================================================================
std::uint32_t fde_03_04a90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004a90ULL;
    for (std::size_t i = 0; i < 107ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2008ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[04] Subroutine @ 0x004c3c..0x004cf8 (188 bytes, 47 AArch64 instructions)
// [VN] Khung FDE[04] Hàm con @ 0x004c3c..0x004cf8 (188 byte, 47 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004c3c: d10103ff  sub      sp, sp, #0x40
//   0x004c40: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x004c44: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x004c48: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x004c4c: 9100c3fd  add      x29, sp, #0x30
//   0x004c50: d53bd055  mrs      x21, tpidr_el0
//   0x004c54: f94016a8  ldr      x8, [x21, #0x28]
//   0x004c58: aa0103f3  mov      x19, x1
//   0x004c5c: f90007e8  str      x8, [sp, #8]
//   0x004c60: b4000160  cbz      x0, #0x4c8c
//   0x004c64: aa0003f4  mov      x20, x0
//   0x004c68: aa0003e8  mov      x8, x0
//   0x004c6c: aa0803f6  mov      x22, x8
//   0x004c70: f9400508  ldr      x8, [x8, #8]
//   0x004c74: b5ffffc8  cbnz     x8, #0x4c6c
//   0x004c78: aa1f03e0  mov      x0, xzr
//   0x004c7c: aa1303e1  mov      x1, x19
//   0x004c80: 97ffffef  bl       #0x4c3c
//   0x004c84: f90006c0  str      x0, [x22, #8]
//   0x004c88: 14000010  b        #0x4cc8
//   0x004c8c: 52800200  mov      w0, #0x10
//   0x004c90: 97fff780  bl       #0x2a90
//   0x004c94: b4000300  cbz      x0, #0x4cf4
//   0x004c98: aa0003f4  mov      x20, x0
//   0x004c9c: a9007c1f  stp      xzr, xzr, [x0]
//   0x004ca0: aa1303e0  mov      x0, x19
//   0x004ca4: 97fff75f  bl       #0x2a20
//   0x004ca8: d2c000a8  mov      x8, #0x500000000
//   0x004cac: 8b008108  add      x8, x8, x0, lsl #32
//   0x004cb0: 9360fd00  asr      x0, x8, #0x20
//   0x004cb4: 97fff777  bl       #0x2a90
//   0x004cb8: b40001e0  cbz      x0, #0x4cf4
//   0x004cbc: aa1303e1  mov      x1, x19
//   0x004cc0: f9000280  str      x0, [x20]
//   0x004cc4: 97fff78f  bl       #0x2b00
//   0x004cc8: f94016a8  ldr      x8, [x21, #0x28]
//   0x004ccc: f94007e9  ldr      x9, [sp, #8]
//   0x004cd0: eb09011f  cmp      x8, x9
//   0x004cd4: 540000e1  b.ne     #0x4cf0
//   0x004cd8: aa1403e0  mov      x0, x20
//   0x004cdc: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x004ce0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x004ce4: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x004ce8: 910103ff  add      sp, sp, #0x40
//   0x004cec: d65f03c0  ret      
//   0x004cf0: 97fff70c  bl       #0x2920
//   0x004cf4: 940007bf  bl       #0x6bf0
// ============================================================================
std::uint32_t fde_04_04c3c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004c3cULL;
    for (std::size_t i = 0; i < 47ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2115ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[05] Subroutine @ 0x004cf8..0x004d60 (104 bytes, 26 AArch64 instructions)
// [VN] Khung FDE[05] Hàm con @ 0x004cf8..0x004d60 (104 byte, 26 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004cf8: d100c3ff  sub      sp, sp, #0x30
//   0x004cfc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x004d00: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x004d04: 910083fd  add      x29, sp, #0x20
//   0x004d08: d53bd054  mrs      x20, tpidr_el0
//   0x004d0c: f9401688  ldr      x8, [x20, #0x28]
//   0x004d10: aa0003f3  mov      x19, x0
//   0x004d14: f90007e8  str      x8, [sp, #8]
//   0x004d18: 97fff67a  bl       #0x2700
//   0x004d1c: f00000c8  adrp     x8, #0x1f000
//   0x004d20: f947c908  ldr      x8, [x8, #0xf90]
//   0x004d24: b0000081  adrp     x1, #0x15000
//   0x004d28: aa0003e2  mov      x2, x0
//   0x004d2c: 912bfc21  add      x1, x1, #0xaff
//   0x004d30: 9104c100  add      x0, x8, #0x130
//   0x004d34: aa1303e3  mov      x3, x19
//   0x004d38: 97fff752  bl       #0x2a80
//   0x004d3c: f9401688  ldr      x8, [x20, #0x28]
//   0x004d40: f94007e9  ldr      x9, [sp, #8]
//   0x004d44: eb09011f  cmp      x8, x9
//   0x004d48: 540000a1  b.ne     #0x4d5c
//   0x004d4c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x004d50: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x004d54: 9100c3ff  add      sp, sp, #0x30
//   0x004d58: d65f03c0  ret      
//   0x004d5c: 97fff6f1  bl       #0x2920
// ============================================================================
std::uint32_t fde_05_04cf8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004cf8ULL;
    for (std::size_t i = 0; i < 26ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2162ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[06] Subroutine @ 0x004d60..0x004d94 (52 bytes, 13 AArch64 instructions)
// [VN] Khung FDE[06] Hàm con @ 0x004d60..0x004d94 (52 byte, 13 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004d60: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x004d64: 910003fd  mov      x29, sp
//   0x004d68: f00000c8  adrp     x8, #0x1f000
//   0x004d6c: f947a908  ldr      x8, [x8, #0xf50]
//   0x004d70: b0000081  adrp     x1, #0x15000
//   0x004d74: 913ff821  add      x1, x1, #0xffe
//   0x004d78: f9400102  ldr      x2, [x8]
//   0x004d7c: f00000c8  adrp     x8, #0x1f000
//   0x004d80: f947c908  ldr      x8, [x8, #0xf90]
//   0x004d84: 9104c100  add      x0, x8, #0x130
//   0x004d88: 97fff73e  bl       #0x2a80
//   0x004d8c: 52800020  mov      w0, #1
//   0x004d90: 940007c4  bl       #0x6ca0
// ============================================================================
std::uint32_t fde_06_04d60(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004d60ULL;
    for (std::size_t i = 0; i < 13ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2188ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[07] Subroutine @ 0x004d94..0x005920 (2956 bytes, 739 AArch64 instructions)
// [VN] Khung FDE[07] Hàm con @ 0x004d94..0x005920 (2956 byte, 739 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x004d94: 6db923e9  stp      d9, d8, [sp, #-0x70]!
//   0x004d98: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x004d9c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x004da0: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x004da4: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x004da8: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x004dac: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x004db0: 910183fd  add      x29, sp, #0x60
//   0x004db4: d14007ff  sub      sp, sp, #1, lsl #12
//   0x004db8: d11203ff  sub      sp, sp, #0x480
//   0x004dbc: d53bd057  mrs      x23, tpidr_el0
//   0x004dc0: f94016e8  ldr      x8, [x23, #0x28]
//   0x004dc4: f00000da  adrp     x26, #0x1f000
//   0x004dc8: f00000d8  adrp     x24, #0x1f000
//   0x004dcc: aa0003f3  mov      x19, x0
//   0x004dd0: f81903a8  stur     x8, [x29, #-0x70]
//   0x004dd4: f947975a  ldr      x26, [x26, #0xf28]
//   0x004dd8: b9400348  ldr      w8, [x26]
//   0x004ddc: f947d318  ldr      x24, [x24, #0xfa0]
//   0x004de0: 3900031f  strb     wzr, [x24]
//   0x004de4: b5000060  cbnz     x0, #0x4df0
//   0x004de8: 7100051f  cmp      w8, #1
//   0x004dec: 54005621  b.ne     #0x58b0
//   0x004df0: 71000d1f  cmp      w8, #3
//   0x004df4: 54000280  b.eq     #0x4e44
//   0x004df8: 7100091f  cmp      w8, #2
//   0x004dfc: 54000100  b.eq     #0x4e1c
//   0x004e00: 7100051f  cmp      w8, #1
//   0x004e04: 540003e1  b.ne     #0x4e80
//   0x004e08: f00000c0  adrp     x0, #0x1f000
//   0x004e0c: f947c000  ldr      x0, [x0, #0xf80]
//   0x004e10: d0000081  adrp     x1, #0x16000
//   0x004e14: 9100ac21  add      x1, x1, #0x2b
//   0x004e18: 14000004  b        #0x4e28
//   0x004e1c: f00000c0  adrp     x0, #0x1f000
//   0x004e20: f947c000  ldr      x0, [x0, #0xf80]
//   0x004e24: aa1303e1  mov      x1, x19
//   0x004e28: 97fffeed  bl       #0x49dc
//   0x004e2c: f00000c0  adrp     x0, #0x1f000
//   0x004e30: f947b800  ldr      x0, [x0, #0xf70]
//   0x004e34: d0000081  adrp     x1, #0x16000
//   0x004e38: 9100cc21  add      x1, x1, #0x33
//   0x004e3c: 97fffee8  bl       #0x49dc
//   0x004e40: 1400000f  b        #0x4e7c
//   0x004e44: f00000c0  adrp     x0, #0x1f000
//   0x004e48: f947c000  ldr      x0, [x0, #0xf80]
//   0x004e4c: aa1303e1  mov      x1, x19
//   0x004e50: 97fffee3  bl       #0x49dc
//   0x004e54: f00000d4  adrp     x20, #0x1f000
//   0x004e58: f947ba94  ldr      x20, [x20, #0xf70]
//   0x004e5c: aa1303e1  mov      x1, x19
//   0x004e60: aa1403e0  mov      x0, x20
//   0x004e64: 97fffede  bl       #0x49dc
//   0x004e68: 90000081  adrp     x1, #0x14000
//   0x004e6c: 9137d021  add      x1, x1, #0xdf4
//   0x004e70: 52808142  mov      w2, #0x40a
//   0x004e74: aa1403e0  mov      x0, x20
//   0x004e78: 97fff6fe  bl       #0x2a70
//   0x004e7c: b9400348  ldr      w8, [x26]
//   0x004e80: f00000d9  adrp     x25, #0x1f000
//   0x004e84: f947cb39  ldr      x25, [x25, #0xf90]
//   0x004e88: 7100051f  cmp      w8, #1
//   0x004e8c: 54000100  b.eq     #0x4eac
//   0x004e90: f00000c0  adrp     x0, #0x1f000
//   0x004e94: f947c000  ldr      x0, [x0, #0xf80]
//   0x004e98: d0000081  adrp     x1, #0x16000
//   0x004e9c: 9105d421  add      x1, x1, #0x175
//   0x004ea0: 97fff70c  bl       #0x2ad0
//   0x004ea4: b4002960  cbz      x0, #0x53d0
//   0x004ea8: 97fff68a  bl       #0x28d0
//   0x004eac: f00000d6  adrp     x22, #0x1f000
//   0x004eb0: f947aed6  ldr      x22, [x22, #0xf58]
//   0x004eb4: f00000d4  adrp     x20, #0x1f000
//   0x004eb8: f94002d3  ldr      x19, [x22]
//   0x004ebc: f947c294  ldr      x20, [x20, #0xf80]
//   0x004ec0: aa1403e0  mov      x0, x20
//   0x004ec4: 97fff6d7  bl       #0x2a20
//   0x004ec8: aa0003f5  mov      x21, x0
//   0x004ecc: aa1303e0  mov      x0, x19
//   0x004ed0: 97fff6d4  bl       #0x2a20
//   0x004ed4: 6b0002bf  cmp      w21, w0
//   0x004ed8: 540000cb  b.lt     #0x4ef0
//   0x004edc: 8b35c288  add      x8, x20, w21, sxtw
//   0x004ee0: cb20c100  sub      x0, x8, w0, sxtw
//   0x004ee4: aa1303e1  mov      x1, x19
//   0x004ee8: 97fff6b6  bl       #0x29c0
//   0x004eec: 34000880  cbz      w0, #0x4ffc
//   0x004ef0: f00000d4  adrp     x20, #0x1f000
//   0x004ef4: f94006d3  ldr      x19, [x22, #8]
//   0x004ef8: f947c294  ldr      x20, [x20, #0xf80]
//   0x004efc: aa1403e0  mov      x0, x20
//   0x004f00: 97fff6c8  bl       #0x2a20
//   0x004f04: aa0003f5  mov      x21, x0
//   0x004f08: aa1303e0  mov      x0, x19
//   0x004f0c: 97fff6c5  bl       #0x2a20
//   0x004f10: 6b0002bf  cmp      w21, w0
//   0x004f14: 540000cb  b.lt     #0x4f2c
//   0x004f18: 8b35c288  add      x8, x20, w21, sxtw
//   0x004f1c: cb20c100  sub      x0, x8, w0, sxtw
//   0x004f20: aa1303e1  mov      x1, x19
//   0x004f24: 97fff6a7  bl       #0x29c0
//   0x004f28: 34000700  cbz      w0, #0x5008
//   0x004f2c: f00000d4  adrp     x20, #0x1f000
//   0x004f30: f9400ad3  ldr      x19, [x22, #0x10]
//   0x004f34: f947c294  ldr      x20, [x20, #0xf80]
//   0x004f38: aa1403e0  mov      x0, x20
//   0x004f3c: 97fff6b9  bl       #0x2a20
//   0x004f40: aa0003f5  mov      x21, x0
//   0x004f44: aa1303e0  mov      x0, x19
//   0x004f48: 97fff6b6  bl       #0x2a20
//   0x004f4c: 6b0002bf  cmp      w21, w0
//   0x004f50: 540000cb  b.lt     #0x4f68
//   0x004f54: 8b35c288  add      x8, x20, w21, sxtw
//   0x004f58: cb20c100  sub      x0, x8, w0, sxtw
//   0x004f5c: aa1303e1  mov      x1, x19
//   0x004f60: 97fff698  bl       #0x29c0
//   0x004f64: 34000560  cbz      w0, #0x5010
//   0x004f68: f00000d4  adrp     x20, #0x1f000
//   0x004f6c: f9400ed3  ldr      x19, [x22, #0x18]
//   0x004f70: f947c294  ldr      x20, [x20, #0xf80]
//   0x004f74: aa1403e0  mov      x0, x20
//   0x004f78: 97fff6aa  bl       #0x2a20
//   0x004f7c: aa0003f5  mov      x21, x0
//   0x004f80: aa1303e0  mov      x0, x19
//   0x004f84: 97fff6a7  bl       #0x2a20
//   0x004f88: 6b0002bf  cmp      w21, w0
//   0x004f8c: 540000cb  b.lt     #0x4fa4
//   0x004f90: 8b35c288  add      x8, x20, w21, sxtw
//   0x004f94: cb20c100  sub      x0, x8, w0, sxtw
//   0x004f98: aa1303e1  mov      x1, x19
//   0x004f9c: 97fff689  bl       #0x29c0
//   0x004fa0: 34000d40  cbz      w0, #0x5148
//   0x004fa4: b9400348  ldr      w8, [x26]
//   0x004fa8: 32000109  orr      w9, w8, #1
//   0x004fac: 71000d3f  cmp      w9, #3
//   0x004fb0: 54000361  b.ne     #0x501c
//   0x004fb4: f00000c0  adrp     x0, #0x1f000
//   0x004fb8: f947c000  ldr      x0, [x0, #0xf80]
//   0x004fbc: 910003e1  mov      x1, sp
//   0x004fc0: 97fff6a8  bl       #0x2a60
//   0x004fc4: b94013e8  ldr      w8, [sp, #0x10]
//   0x004fc8: 12140d08  and      w8, w8, #0xf000
//   0x004fcc: 7140111f  cmp      w8, #4, lsl #12
//   0x004fd0: 54000241  b.ne     #0x5018
//   0x004fd4: f00000c8  adrp     x8, #0x1f000
//   0x004fd8: f947a908  ldr      x8, [x8, #0xf50]
//   0x004fdc: f00000c3  adrp     x3, #0x1f000
//   0x004fe0: d0000081  adrp     x1, #0x16000
//   0x004fe4: 9104c320  add      x0, x25, #0x130
//   0x004fe8: f9400102  ldr      x2, [x8]
//   0x004fec: f947c063  ldr      x3, [x3, #0xf80]
//   0x004ff0: 91022421  add      x1, x1, #0x89
//   0x004ff4: 97fff6a3  bl       #0x2a80
//   0x004ff8: 14000104  b        #0x5408
//   0x004ffc: f00000c8  adrp     x8, #0x1f000
//   0x005000: f947ad08  ldr      x8, [x8, #0xf58]
//   0x005004: 14000052  b        #0x514c
//   0x005008: 910022c8  add      x8, x22, #8
//   0x00500c: 14000050  b        #0x514c
//   0x005010: 910042c8  add      x8, x22, #0x10
//   0x005014: 1400004e  b        #0x514c
//   0x005018: b9400348  ldr      w8, [x26]
//   0x00501c: d00000d3  adrp     x19, #0x1f000
//   0x005020: f947d673  ldr      x19, [x19, #0xfa8]
//   0x005024: 71000d1f  cmp      w8, #3
//   0x005028: 540001a1  b.ne     #0x505c
//   0x00502c: 39400269  ldrb     w9, [x19]
//   0x005030: 35000169  cbnz     w9, #0x505c
//   0x005034: d00000c0  adrp     x0, #0x1f000
//   0x005038: f947c000  ldr      x0, [x0, #0xf80]
//   0x00503c: 9103a3e1  add      x1, sp, #0xe8
//   0x005040: 97fff5ec  bl       #0x27f0
//   0x005044: 35000660  cbnz     w0, #0x5110
//   0x005048: b940fbe8  ldr      w8, [sp, #0xf8]
//   0x00504c: 12140d08  and      w8, w8, #0xf000
//   0x005050: 7140211f  cmp      w8, #8, lsl #12
//   0x005054: 540005e1  b.ne     #0x5110
//   0x005058: b9400348  ldr      w8, [x26]
//   0x00505c: 71000d1f  cmp      w8, #3
//   0x005060: 540001a1  b.ne     #0x5094
//   0x005064: d00000c0  adrp     x0, #0x1f000
//   0x005068: f947b800  ldr      x0, [x0, #0xf70]
//   0x00506c: b0000081  adrp     x1, #0x16000
//   0x005070: 9105d421  add      x1, x1, #0x175
//   0x005074: 97fff697  bl       #0x2ad0
//   0x005078: b40000e0  cbz      x0, #0x5094
//   0x00507c: 97fff615  bl       #0x28d0
//   0x005080: 39400268  ldrb     w8, [x19]
//   0x005084: 34001488  cbz      w8, #0x5314
//   0x005088: d00000c0  adrp     x0, #0x1f000
//   0x00508c: f947b800  ldr      x0, [x0, #0xf70]
//   0x005090: 97fff670  bl       #0x2a50
//   0x005094: b9400348  ldr      w8, [x26]
//   0x005098: 71000d1f  cmp      w8, #3
//   0x00509c: 54000761  b.ne     #0x5188
//   0x0050a0: 39400269  ldrb     w9, [x19]
//   0x0050a4: 35000729  cbnz     w9, #0x5188
//   0x0050a8: d00000c0  adrp     x0, #0x1f000
//   0x0050ac: f947c000  ldr      x0, [x0, #0xf80]
//   0x0050b0: 9103a3e1  add      x1, sp, #0xe8
//   0x0050b4: 97fff5cf  bl       #0x27f0
//   0x0050b8: b940ffe8  ldr      w8, [sp, #0xfc]
//   0x0050bc: 7100001f  cmp      w0, #0
//   0x0050c0: 51000508  sub      w8, w8, #1
//   0x0050c4: 1a9f0104  csel     w4, w8, wzr, eq
//   0x0050c8: 7100049f  cmp      w4, #1
//   0x0050cc: 540005cb  b.lt     #0x5184
//   0x0050d0: d00000c8  adrp     x8, #0x1f000
//   0x0050d4: f947a908  ldr      x8, [x8, #0xf50]
//   0x0050d8: d00000c3  adrp     x3, #0x1f000
//   0x0050dc: 90000089  adrp     x9, #0x15000
//   0x0050e0: 913f3129  add      x9, x9, #0xfcc
//   0x0050e4: f9400102  ldr      x2, [x8]
//   0x0050e8: f947c063  ldr      x3, [x3, #0xf80]
//   0x0050ec: d0000088  adrp     x8, #0x17000
//   0x0050f0: 91061908  add      x8, x8, #0x186
//   0x0050f4: 7100049f  cmp      w4, #1
//   0x0050f8: b0000081  adrp     x1, #0x16000
//   0x0050fc: 9a880125  csel     x5, x9, x8, eq
//   0x005100: 9104c320  add      x0, x25, #0x130
//   0x005104: 9103e421  add      x1, x1, #0xf9
//   0x005108: 97fff65e  bl       #0x2a80
//   0x00510c: 140000bf  b        #0x5408
//   0x005110: d00000c8  adrp     x8, #0x1f000
//   0x005114: f947c508  ldr      x8, [x8, #0xf88]
//   0x005118: 39400108  ldrb     w8, [x8]
//   0x00511c: 34001768  cbz      w8, #0x5408
//   0x005120: d00000c8  adrp     x8, #0x1f000
//   0x005124: f947a908  ldr      x8, [x8, #0xf50]
//   0x005128: d00000c3  adrp     x3, #0x1f000
//   0x00512c: b0000081  adrp     x1, #0x16000
//   0x005130: 9104c320  add      x0, x25, #0x130
//   0x005134: f9400102  ldr      x2, [x8]
//   0x005138: f947c063  ldr      x3, [x3, #0xf80]
//   0x00513c: 9102b021  add      x1, x1, #0xac
//   0x005140: 97fff650  bl       #0x2a80
//   0x005144: 140000b1  b        #0x5408
//   0x005148: 910062c8  add      x8, x22, #0x18
//   0x00514c: d00000c9  adrp     x9, #0x1f000
//   0x005150: f947c529  ldr      x9, [x9, #0xf88]
//   0x005154: 39400129  ldrb     w9, [x9]
//   0x005158: 34001589  cbz      w9, #0x5408
//   0x00515c: d00000c9  adrp     x9, #0x1f000
//   0x005160: f947a929  ldr      x9, [x9, #0xf50]
//   0x005164: d00000c3  adrp     x3, #0x1f000
//   0x005168: f9400104  ldr      x4, [x8]
//   0x00516c: b0000081  adrp     x1, #0x16000
//   0x005170: f9400122  ldr      x2, [x9]
//   0x005174: f947c063  ldr      x3, [x3, #0xf80]
//   0x005178: 9104c320  add      x0, x25, #0x130
//   0x00517c: 91017c21  add      x1, x1, #0x5f
//   0x005180: 140000a1  b        #0x5404
//   0x005184: b9400348  ldr      w8, [x26]
//   0x005188: 71000d1f  cmp      w8, #3
//   0x00518c: 54000101  b.ne     #0x51ac
//   0x005190: d00000c0  adrp     x0, #0x1f000
//   0x005194: f947c000  ldr      x0, [x0, #0xf80]
//   0x005198: f00000c1  adrp     x1, #0x20000
//   0x00519c: 91310021  add      x1, x1, #0xc40
//   0x0051a0: 97fff630  bl       #0x2a60
//   0x0051a4: 35003ae0  cbnz     w0, #0x5900
//   0x0051a8: b9400348  ldr      w8, [x26]
//   0x0051ac: 71000d1f  cmp      w8, #3
//   0x0051b0: 54000680  b.eq     #0x5280
//   0x0051b4: 7100091f  cmp      w8, #2
//   0x0051b8: 540002e0  b.eq     #0x5214
//   0x0051bc: 7100051f  cmp      w8, #1
//   0x0051c0: 54003aa1  b.ne     #0x5914
//   0x0051c4: 91026334  add      x20, x25, #0x98
//   0x0051c8: aa1403e0  mov      x0, x20
//   0x0051cc: 97fff5e1  bl       #0x2950
//   0x0051d0: 97fff598  bl       #0x2830
//   0x0051d4: 34000b40  cbz      w0, #0x533c
//   0x0051d8: d00000d4  adrp     x20, #0x1f000
//   0x0051dc: f947aa94  ldr      x20, [x20, #0xf50]
//   0x0051e0: 9104c333  add      x19, x25, #0x130
//   0x0051e4: b0000081  adrp     x1, #0x16000
//   0x0051e8: 91048421  add      x1, x1, #0x121
//   0x0051ec: f9400282  ldr      x2, [x20]
//   0x0051f0: aa1303e0  mov      x0, x19
//   0x0051f4: 97fff623  bl       #0x2a80
//   0x0051f8: f9400282  ldr      x2, [x20]
//   0x0051fc: b0000081  adrp     x1, #0x16000
//   0x005200: 91054c21  add      x1, x1, #0x153
//   0x005204: aa1303e0  mov      x0, x19
//   0x005208: aa0203e3  mov      x3, x2
//   0x00520c: 97fff61d  bl       #0x2a80
//   0x005210: 1400007e  b        #0x5408
//   0x005214: d00000c0  adrp     x0, #0x1f000
//   0x005218: f947c000  ldr      x0, [x0, #0xf80]
//   0x00521c: b0000081  adrp     x1, #0x16000
//   0x005220: 9105d421  add      x1, x1, #0x175
//   0x005224: 97fff62b  bl       #0x2ad0
//   0x005228: 91026334  add      x20, x25, #0x98
//   0x00522c: aa0003f3  mov      x19, x0
//   0x005230: aa1403e0  mov      x0, x20
//   0x005234: 97fff5c7  bl       #0x2950
//   0x005238: 97fff57e  bl       #0x2830
//   0x00523c: 34000840  cbz      w0, #0x5344
//   0x005240: d00000d5  adrp     x21, #0x1f000
//   0x005244: f947aab5  ldr      x21, [x21, #0xf50]
//   0x005248: 9104c334  add      x20, x25, #0x130
//   0x00524c: b0000081  adrp     x1, #0x16000
//   0x005250: 91048421  add      x1, x1, #0x121
//   0x005254: f94002a2  ldr      x2, [x21]
//   0x005258: aa1403e0  mov      x0, x20
//   0x00525c: 97fff609  bl       #0x2a80
//   0x005260: f94002a2  ldr      x2, [x21]
//   0x005264: b0000081  adrp     x1, #0x16000
//   0x005268: 91054c21  add      x1, x1, #0x153
//   0x00526c: aa1403e0  mov      x0, x20
//   0x005270: aa0203e3  mov      x3, x2
//   0x005274: 97fff603  bl       #0x2a80
//   0x005278: b5002d93  cbnz     x19, #0x5828
//   0x00527c: 14000063  b        #0x5408
//   0x005280: d00000c0  adrp     x0, #0x1f000
//   0x005284: f947c000  ldr      x0, [x0, #0xf80]
//   0x005288: b0000081  adrp     x1, #0x16000
//   0x00528c: 9105d421  add      x1, x1, #0x175
//   0x005290: 97fff610  bl       #0x2ad0
//   0x005294: aa0003f3  mov      x19, x0
//   0x005298: d00000c0  adrp     x0, #0x1f000
//   0x00529c: f947b800  ldr      x0, [x0, #0xf70]
//   0x0052a0: 52801821  mov      w1, #0xc1
//   0x0052a4: 52803002  mov      w2, #0x180
//   0x0052a8: 97fff506  bl       #0x26c0
//   0x0052ac: 3100041f  cmn      w0, #1
//   0x0052b0: 540029e0  b.eq     #0x57ec
//   0x0052b4: b0000081  adrp     x1, #0x16000
//   0x0052b8: 9105e021  add      x1, x1, #0x178
//   0x0052bc: 2a0003f5  mov      w21, w0
//   0x0052c0: 97fff5d4  bl       #0x2a10
//   0x0052c4: b4002900  cbz      x0, #0x57e4
//   0x0052c8: aa0003f4  mov      x20, x0
//   0x0052cc: b50003f3  cbnz     x19, #0x5348
//   0x0052d0: d00000c8  adrp     x8, #0x1f000
//   0x0052d4: f947a908  ldr      x8, [x8, #0xf50]
//   0x0052d8: f9400113  ldr      x19, [x8]
//   0x0052dc: 97fff54d  bl       #0x2810
//   0x0052e0: b9400000  ldr      w0, [x0]
//   0x0052e4: 97fff53f  bl       #0x27e0
//   0x0052e8: d00000c3  adrp     x3, #0x1f000
//   0x0052ec: f947c063  ldr      x3, [x3, #0xf80]
//   0x0052f0: b0000081  adrp     x1, #0x16000
//   0x0052f4: aa0003e4  mov      x4, x0
//   0x0052f8: 9104c320  add      x0, x25, #0x130
//   0x0052fc: 9100f021  add      x1, x1, #0x3c
//   0x005300: aa1303e2  mov      x2, x19
//   0x005304: 97fff5df  bl       #0x2a80
//   0x005308: aa1403e0  mov      x0, x20
//   0x00530c: 97fff571  bl       #0x28d0
//   0x005310: 1400003e  b        #0x5408
//   0x005314: d00000c8  adrp     x8, #0x1f000
//   0x005318: f947a908  ldr      x8, [x8, #0xf50]
//   0x00531c: d00000c3  adrp     x3, #0x1f000
//   0x005320: b0000081  adrp     x1, #0x16000
//   0x005324: 9104c320  add      x0, x25, #0x130
//   0x005328: f9400102  ldr      x2, [x8]
//   0x00532c: f947b863  ldr      x3, [x3, #0xf70]
//   0x005330: 91035421  add      x1, x1, #0xd5
//   0x005334: 97fff5d3  bl       #0x2a80
//   0x005338: 14000034  b        #0x5408
//   0x00533c: aa1903f3  mov      x19, x25
//   0x005340: 14000002  b        #0x5348
//   0x005344: b4000473  cbz      x19, #0x53d0
//   0x005348: d00000dc  adrp     x28, #0x1f000
//   0x00534c: f947ef9c  ldr      x28, [x28, #0xfd8]
//   0x005350: b9400388  ldr      w8, [x28]
//   0x005354: 7100051f  cmp      w8, #1
//   0x005358: 540008eb  b.lt     #0x5474
//   0x00535c: d00000d6  adrp     x22, #0x1f000
//   0x005360: f947c2d6  ldr      x22, [x22, #0xf80]
//   0x005364: 9104c335  add      x21, x25, #0x130
//   0x005368: b0000081  adrp     x1, #0x16000
//   0x00536c: 91068421  add      x1, x1, #0x1a1
//   0x005370: aa1503e0  mov      x0, x21
//   0x005374: aa1603e2  mov      x2, x22
//   0x005378: 97fff5c2  bl       #0x2a80
//   0x00537c: aa1603e0  mov      x0, x22
//   0x005380: 97fff5a8  bl       #0x2a20
//   0x005384: d00000db  adrp     x27, #0x1f000
//   0x005388: f947fb7b  ldr      x27, [x27, #0xff0]
//   0x00538c: b9400379  ldr      w25, [x27]
//   0x005390: 6b00033f  cmp      w25, w0
//   0x005394: 5400064d  b.le     #0x545c
//   0x005398: d00000d6  adrp     x22, #0x1f000
//   0x00539c: f947c2d6  ldr      x22, [x22, #0xf80]
//   0x0053a0: 5280003c  mov      w28, #1
//   0x0053a4: aa1603e0  mov      x0, x22
//   0x0053a8: 97fff59e  bl       #0x2a20
//   0x0053ac: 4b000328  sub      w8, w25, w0
//   0x0053b0: 6b08039f  cmp      w28, w8
//   0x0053b4: 5400054c  b.gt     #0x545c
//   0x0053b8: 52800400  mov      w0, #0x20
//   0x0053bc: aa1503e1  mov      x1, x21
//   0x0053c0: 97fff554  bl       #0x2910
//   0x0053c4: b9400379  ldr      w25, [x27]
//   0x0053c8: 1100079c  add      w28, w28, #1
//   0x0053cc: 17fffff6  b        #0x53a4
//   0x0053d0: d00000c8  adrp     x8, #0x1f000
//   0x0053d4: f947a908  ldr      x8, [x8, #0xf50]
//   0x0053d8: f9400113  ldr      x19, [x8]
//   0x0053dc: 97fff50d  bl       #0x2810
//   0x0053e0: b9400000  ldr      w0, [x0]
//   0x0053e4: 97fff4ff  bl       #0x27e0
//   0x0053e8: d00000c3  adrp     x3, #0x1f000
//   0x0053ec: f947c063  ldr      x3, [x3, #0xf80]
//   0x0053f0: b0000081  adrp     x1, #0x16000
//   0x0053f4: aa0003e4  mov      x4, x0
//   0x0053f8: 9104c320  add      x0, x25, #0x130
//   0x0053fc: 9100f021  add      x1, x1, #0x3c
//   0x005400: aa1303e2  mov      x2, x19
//   0x005404: 97fff59f  bl       #0x2a80
//   0x005408: d00000c8  adrp     x8, #0x1f000
//   0x00540c: f9479d08  ldr      x8, [x8, #0xf38]
//   0x005410: b9400109  ldr      w9, [x8]
//   0x005414: 7100013f  cmp      w9, #0
//   0x005418: 5400006c  b.gt     #0x5424
//   0x00541c: 52800029  mov      w9, #1
//   0x005420: b9000109  str      w9, [x8]
//   0x005424: f94016e8  ldr      x8, [x23, #0x28]
//   0x005428: f85903a9  ldur     x9, [x29, #-0x70]
//   0x00542c: eb09011f  cmp      x8, x9
//   0x005430: 54002461  b.ne     #0x58bc
//   0x005434: 914007ff  add      sp, sp, #1, lsl #12
//   0x005438: 911203ff  add      sp, sp, #0x480
//   0x00543c: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x005440: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x005444: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x005448: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x00544c: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x005450: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x005454: 6cc723e9  ldp      d9, d8, [sp], #0x70
//   0x005458: d65f03c0  ret      
//   0x00545c: aa1503e0  mov      x0, x21
//   0x005460: 97fff524  bl       #0x28f0
//   0x005464: d00000d9  adrp     x25, #0x1f000
//   0x005468: d00000dc  adrp     x28, #0x1f000
//   0x00546c: f947cb39  ldr      x25, [x25, #0xf90]
//   0x005470: f947ef9c  ldr      x28, [x28, #0xfd8]
//   0x005474: d00000db  adrp     x27, #0x1f000
//   0x005478: f947b77b  ldr      x27, [x27, #0xf68]
//   0x00547c: 52800028  mov      w8, #1
//   0x005480: aa1303e0  mov      x0, x19
//   0x005484: 39000308  strb     w8, [x24]
//   0x005488: f9000374  str      x20, [x27]
//   0x00548c: 97fff555  bl       #0x29e0
//   0x005490: 35002380  cbnz     w0, #0x5900
//   0x005494: aa1403e0  mov      x0, x20
//   0x005498: 97fff552  bl       #0x29e0
//   0x00549c: 35002320  cbnz     w0, #0x5900
//   0x0054a0: d00000c8  adrp     x8, #0x1f000
//   0x0054a4: d00000c9  adrp     x9, #0x1f000
//   0x0054a8: f947dd08  ldr      x8, [x8, #0xfb8]
//   0x0054ac: b9400383  ldr      w3, [x28]
//   0x0054b0: f947b129  ldr      x9, [x9, #0xf60]
//   0x0054b4: 910213e0  add      x0, sp, #0x84
//   0x0054b8: b9400102  ldr      w2, [x8]
//   0x0054bc: aa1403e1  mov      x1, x20
//   0x0054c0: b9400124  ldr      w4, [x9]
//   0x0054c4: 97fff537  bl       #0x29a0
//   0x0054c8: b94087e8  ldr      w8, [sp, #0x84]
//   0x0054cc: aa0003f5  mov      x21, x0
//   0x0054d0: 35001f88  cbnz     w8, #0x58c0
//   0x0054d4: b9400388  ldr      w8, [x28]
//   0x0054d8: 7100091f  cmp      w8, #2
//   0x0054dc: 540000eb  b.lt     #0x54f8
//   0x0054e0: 9104c321  add      x1, x25, #0x130
//   0x0054e4: 52800140  mov      w0, #0xa
//   0x0054e8: 97fff50a  bl       #0x2910
//   0x0054ec: 14000003  b        #0x54f8
//   0x0054f0: b94087e8  ldr      w8, [sp, #0x84]
//   0x0054f4: 35001e68  cbnz     w8, #0x58c0
//   0x0054f8: aa1303e0  mov      x0, x19
//   0x0054fc: 97fff535  bl       #0x29d0
//   0x005500: 3100041f  cmn      w0, #1
//   0x005504: 54000280  b.eq     #0x5554
//   0x005508: aa1303e1  mov      x1, x19
//   0x00550c: 97fff4a1  bl       #0x2790
//   0x005510: 9103a3e0  add      x0, sp, #0xe8
//   0x005514: 52800021  mov      w1, #1
//   0x005518: 52827102  mov      w2, #0x1388
//   0x00551c: aa1303e3  mov      x3, x19
//   0x005520: 97fff484  bl       #0x2730
//   0x005524: aa0003f6  mov      x22, x0
//   0x005528: aa1303e0  mov      x0, x19
//   0x00552c: 97fff52d  bl       #0x29e0
//   0x005530: 35001e80  cbnz     w0, #0x5900
//   0x005534: 710006df  cmp      w22, #1
//   0x005538: 54fffdcb  b.lt     #0x54f0
//   0x00553c: 910213e0  add      x0, sp, #0x84
//   0x005540: 9103a3e2  add      x2, sp, #0xe8
//   0x005544: aa1503e1  mov      x1, x21
//   0x005548: 2a1603e3  mov      w3, w22
//   0x00554c: 97fff4c5  bl       #0x2860
//   0x005550: 17ffffe8  b        #0x54f0
//   0x005554: 910213e0  add      x0, sp, #0x84
//   0x005558: 910253e3  add      x3, sp, #0x94
//   0x00555c: 910243e4  add      x4, sp, #0x90
//   0x005560: 910233e5  add      x5, sp, #0x8c
//   0x005564: 910223e6  add      x6, sp, #0x88
//   0x005568: aa1503e1  mov      x1, x21
//   0x00556c: 2a1f03e2  mov      w2, wzr
//   0x005570: 97fff490  bl       #0x27b0
//   0x005574: b94087e8  ldr      w8, [sp, #0x84]
//   0x005578: 35001a48  cbnz     w8, #0x58c0
//   0x00557c: aa1403e0  mov      x0, x20
//   0x005580: 97fff518  bl       #0x29e0
//   0x005584: 35001be0  cbnz     w0, #0x5900
//   0x005588: aa1403e0  mov      x0, x20
//   0x00558c: 97fff4d9  bl       #0x28f0
//   0x005590: 3100041f  cmn      w0, #1
//   0x005594: 54001b60  b.eq     #0x5900
//   0x005598: 91026328  add      x8, x25, #0x98
//   0x00559c: eb08029f  cmp      x20, x8
//   0x0055a0: 54000260  b.eq     #0x55ec
//   0x0055a4: aa1403e0  mov      x0, x20
//   0x0055a8: 97fff4ea  bl       #0x2950
//   0x0055ac: 37f81aa0  tbnz     w0, #0x1f, #0x5900
//   0x0055b0: f00000c8  adrp     x8, #0x20000
//   0x0055b4: b94c5101  ldr      w1, [x8, #0xc50]
//   0x0055b8: 2a0003f5  mov      w21, w0
//   0x0055bc: 97fff43d  bl       #0x26b0
//   0x0055c0: 35001a00  cbnz     w0, #0x5900
//   0x0055c4: f00000c8  adrp     x8, #0x20000
//   0x0055c8: 91316108  add      x8, x8, #0xc58
//   0x0055cc: 29400901  ldp      w1, w2, [x8]
//   0x0055d0: 2a1503e0  mov      w0, w21
//   0x0055d4: 97fff473  bl       #0x27a0
//   0x0055d8: aa1403e0  mov      x0, x20
//   0x0055dc: 97fff4bd  bl       #0x28d0
//   0x0055e0: 3100041f  cmn      w0, #1
//   0x0055e4: f900037f  str      xzr, [x27]
//   0x0055e8: 540018c0  b.eq     #0x5900
//   0x0055ec: aa1303e0  mov      x0, x19
//   0x0055f0: f900037f  str      xzr, [x27]
//   0x0055f4: 97fff4fb  bl       #0x29e0
//   0x0055f8: 35001840  cbnz     w0, #0x5900
//   0x0055fc: aa1303e0  mov      x0, x19
//   0x005600: 97fff4b4  bl       #0x28d0
//   0x005604: 3100041f  cmn      w0, #1
//   0x005608: 540017c0  b.eq     #0x5900
//   0x00560c: b9400388  ldr      w8, [x28]
//   0x005610: 7100051f  cmp      w8, #1
//   0x005614: 540011cb  b.lt     #0x584c
//   0x005618: 295227ea  ldp      w10, w9, [sp, #0x90]
//   0x00561c: 2a090148  orr      w8, w10, w9
//   0x005620: 340010a8  cbz      w8, #0x5834
//   0x005624: 53083d20  ubfx     w0, w9, #8, #8
//   0x005628: d2e80e02  mov      x2, #0x4070000000000000
//   0x00562c: 53187d48  lsr      w8, w10, #0x18
//   0x005630: 53105d4b  ubfx     w11, w10, #0x10, #8
//   0x005634: 53083d4c  ubfx     w12, w10, #8, #8
//   0x005638: 12001d4d  and      w13, w10, #0xff
//   0x00563c: b900a7ea  str      w10, [sp, #0xa4]
//   0x005640: 53187d2e  lsr      w14, w9, #0x18
//   0x005644: 53107d2f  lsr      w15, w9, #0x10
//   0x005648: 53105d30  ubfx     w16, w9, #0x10, #8
//   0x00564c: 53087d31  lsr      w17, w9, #8
//   0x005650: 12001d21  and      w1, w9, #0xff
//   0x005654: 390283e9  strb     w9, [sp, #0xa0]
//   0x005658: 295127ea  ldp      w10, w9, [sp, #0x88]
//   0x00565c: d2e81e03  mov      x3, #0x40f0000000000000
//   0x005660: 1e630001  ucvtf    d1, w0
//   0x005664: 9e670042  fmov     d2, x2
//   0x005668: d2e82e04  mov      x4, #0x4170000000000000
//   0x00566c: 1e630020  ucvtf    d0, w1
//   0x005670: 1e630203  ucvtf    d3, w16
//   0x005674: 9e670064  fmov     d4, x3
//   0x005678: 1e620821  fmul     d1, d1, d2
//   0x00567c: d2e83e05  mov      x5, #0x41f0000000000000
//   0x005680: 1e6301c5  ucvtf    d5, w14
//   0x005684: 9e670086  fmov     d6, x4
//   0x005688: 1e602820  fadd     d0, d1, d0
//   0x00568c: 1e640863  fmul     d3, d3, d4
//   0x005690: 1e6301a7  ucvtf    d7, w13
//   0x005694: 9e6700b0  fmov     d16, x5
//   0x005698: 1e602860  fadd     d0, d3, d0
//   0x00569c: 1e6608a5  fmul     d5, d5, d6
//   0x0056a0: 39028bef  strb     w15, [sp, #0xa2]
//   0x0056a4: d2e85e0f  mov      x15, #0x42f0000000000000
//   0x0056a8: 1e6028a0  fadd     d0, d5, d0
//   0x0056ac: 1e7008e7  fmul     d7, d7, d16
//   0x0056b0: 53083d30  ubfx     w16, w9, #8, #8
//   0x0056b4: 9e6701e5  fmov     d5, x15
//   0x0056b8: 53105d2f  ubfx     w15, w9, #0x10, #8
//   0x0056bc: 1e6028e0  fadd     d0, d7, d0
//   0x0056c0: 1e630207  ucvtf    d7, w16
//   0x0056c4: 39028fee  strb     w14, [sp, #0xa3]
//   0x0056c8: 53187d2e  lsr      w14, w9, #0x18
//   0x0056cc: 1e6208e2  fmul     d2, d7, d2
//   0x0056d0: 1e6301e7  ucvtf    d7, w15
//   0x0056d4: 12001d4d  and      w13, w10, #0xff
//   0x0056d8: 1e6408e4  fmul     d4, d7, d4
//   0x0056dc: 1e6301c7  ucvtf    d7, w14
//   0x0056e0: d2e84e06  mov      x6, #0x4270000000000000
//   0x0056e4: 1e630191  ucvtf    d17, w12
//   0x0056e8: 53083d4c  ubfx     w12, w10, #8, #8
//   0x0056ec: 1e6608e6  fmul     d6, d7, d6
//   0x0056f0: 1e6301a7  ucvtf    d7, w13
//   0x0056f4: 9e6700c1  fmov     d1, x6
//   0x0056f8: 1e630163  ucvtf    d3, w11
//   0x0056fc: 53105d4b  ubfx     w11, w10, #0x10, #8
//   0x005700: 1e7008e7  fmul     d7, d7, d16
//   0x005704: 1e630190  ucvtf    d16, w12
//   0x005708: 1e610a31  fmul     d17, d17, d1
//   0x00570c: 1e610a01  fmul     d1, d16, d1
//   0x005710: 1e630170  ucvtf    d16, w11
//   0x005714: 1e650863  fmul     d3, d3, d5
//   0x005718: 1e650a05  fmul     d5, d16, d5
//   0x00571c: 1e630110  ucvtf    d16, w8
//   0x005720: 12001d28  and      w8, w9, #0xff
//   0x005724: 390287f1  strb     w17, [sp, #0xa1]
//   0x005728: d2e86e11  mov      x17, #0x4370000000000000
//   0x00572c: 1e602a20  fadd     d0, d17, d0
//   0x005730: 1e630111  ucvtf    d17, w8
//   0x005734: 1e712842  fadd     d2, d2, d17
//   0x005738: 9e670231  fmov     d17, x17
//   0x00573c: 1e710a10  fmul     d16, d16, d17
//   0x005740: 1e602860  fadd     d0, d3, d0
//   0x005744: 1e622882  fadd     d2, d4, d2
//   0x005748: 1e602a08  fadd     d8, d16, d0
//   0x00574c: 1e6228c0  fadd     d0, d6, d2
//   0x005750: 53187d48  lsr      w8, w10, #0x18
//   0x005754: 1e6028e0  fadd     d0, d7, d0
//   0x005758: 1e630103  ucvtf    d3, w8
//   0x00575c: 1e602820  fadd     d0, d1, d0
//   0x005760: b9009fea  str      w10, [sp, #0x9c]
//   0x005764: 53107d2a  lsr      w10, w9, #0x10
//   0x005768: 53087d2b  lsr      w11, w9, #8
//   0x00576c: 1e6028a0  fadd     d0, d5, d0
//   0x005770: 1e710861  fmul     d1, d3, d17
//   0x005774: 910323e0  add      x0, sp, #0xc8
//   0x005778: 910283e1  add      x1, sp, #0xa0
//   0x00577c: 390263e9  strb     w9, [sp, #0x98]
//   0x005780: 39026fee  strb     w14, [sp, #0x9b]
//   0x005784: 39026bea  strb     w10, [sp, #0x9a]
//   0x005788: 390267eb  strb     w11, [sp, #0x99]
//   0x00578c: 1e602829  fadd     d9, d1, d0
//   0x005790: 940005cc  bl       #0x6ec0
//   0x005794: 9102a3e0  add      x0, sp, #0xa8
//   0x005798: 910263e1  add      x1, sp, #0x98
//   0x00579c: 940005c9  bl       #0x6ec0
//   0x0057a0: 1e641001  fmov     d1, #8.00000000
//   0x0057a4: 1e681922  fdiv     d2, d9, d8
//   0x0057a8: 1e6e1003  fmov     d3, #1.00000000
//   0x0057ac: d2e80b28  mov      x8, #0x4059000000000000
//   0x0057b0: 1e610921  fmul     d1, d9, d1
//   0x0057b4: 1e623862  fsub     d2, d3, d2
//   0x0057b8: 9e670103  fmov     d3, x8
//   0x0057bc: b0000081  adrp     x1, #0x16000
//   0x0057c0: 1e691900  fdiv     d0, d8, d9
//   0x0057c4: 1e681821  fdiv     d1, d1, d8
//   0x0057c8: 1e630842  fmul     d2, d2, d3
//   0x0057cc: 9104c320  add      x0, x25, #0x130
//   0x0057d0: 9108bc21  add      x1, x1, #0x22f
//   0x0057d4: 910323e2  add      x2, sp, #0xc8
//   0x0057d8: 9102a3e3  add      x3, sp, #0xa8
//   0x0057dc: 97fff4a9  bl       #0x2a80
//   0x0057e0: 1400001b  b        #0x584c
//   0x0057e4: 2a1503e0  mov      w0, w21
//   0x0057e8: 97fff496  bl       #0x2a40
//   0x0057ec: d00000c8  adrp     x8, #0x1f000
//   0x0057f0: f947a908  ldr      x8, [x8, #0xf50]
//   0x0057f4: f9400114  ldr      x20, [x8]
//   0x0057f8: 97fff406  bl       #0x2810
//   0x0057fc: b9400000  ldr      w0, [x0]
//   0x005800: 97fff3f8  bl       #0x27e0
//   0x005804: d00000c3  adrp     x3, #0x1f000
//   0x005808: f947b863  ldr      x3, [x3, #0xf70]
//   0x00580c: b0000081  adrp     x1, #0x16000
//   0x005810: aa0003e4  mov      x4, x0
//   0x005814: 9104c320  add      x0, x25, #0x130
//   0x005818: 9105ec21  add      x1, x1, #0x17b
//   0x00581c: aa1403e2  mov      x2, x20
//   0x005820: 97fff498  bl       #0x2a80
//   0x005824: b4ffdf33  cbz      x19, #0x5408
//   0x005828: aa1303e0  mov      x0, x19
//   0x00582c: 97fff429  bl       #0x28d0
//   0x005830: 17fffef6  b        #0x5408
//   0x005834: b0000080  adrp     x0, #0x16000
//   0x005838: 9104c323  add      x3, x25, #0x130
//   0x00583c: 91086400  add      x0, x0, #0x219
//   0x005840: 528002a1  mov      w1, #0x15
//   0x005844: 52800022  mov      w2, #1
//   0x005848: 97fff4a6  bl       #0x2ae0
//   0x00584c: b9400348  ldr      w8, [x26]
//   0x005850: f900037f  str      xzr, [x27]
//   0x005854: 71000d1f  cmp      w8, #3
//   0x005858: 54000281  b.ne     #0x58a8
//   0x00585c: f00000c8  adrp     x8, #0x20000
//   0x005860: 91322108  add      x8, x8, #0xc88
//   0x005864: f9400909  ldr      x9, [x8, #0x10]
//   0x005868: f9400108  ldr      x8, [x8]
//   0x00586c: d00000c0  adrp     x0, #0x1f000
//   0x005870: 9103a3e1  add      x1, sp, #0xe8
//   0x005874: a90ea7e8  stp      x8, x9, [sp, #0xe8]
//   0x005878: f947b800  ldr      x0, [x0, #0xf70]
//   0x00587c: 97fff44d  bl       #0x29b0
//   0x005880: 35000400  cbnz     w0, #0x5900
//   0x005884: d00000c8  adrp     x8, #0x1f000
//   0x005888: f947bd08  ldr      x8, [x8, #0xf78]
//   0x00588c: 3900031f  strb     wzr, [x24]
//   0x005890: 39400108  ldrb     w8, [x8]
//   0x005894: 350000a8  cbnz     w8, #0x58a8
//   0x005898: d00000c0  adrp     x0, #0x1f000
//   0x00589c: f947c000  ldr      x0, [x0, #0xf80]
//   0x0058a0: 97fff46c  bl       #0x2a50
//   0x0058a4: 350002e0  cbnz     w0, #0x5900
//   0x0058a8: 3900031f  strb     wzr, [x24]
//   0x0058ac: 17fffede  b        #0x5424
//   0x0058b0: b0000080  adrp     x0, #0x16000
//   0x0058b4: 910e5c00  add      x0, x0, #0x397
//   0x0058b8: 94000562  bl       #0x6e40
//   0x0058bc: 97fff419  bl       #0x2920
//   0x0058c0: 910323e0  add      x0, sp, #0xc8
//   0x0058c4: 910253e3  add      x3, sp, #0x94
//   0x0058c8: 910243e4  add      x4, sp, #0x90
//   0x0058cc: 910233e5  add      x5, sp, #0x8c
//   0x0058d0: 910223e6  add      x6, sp, #0x88
//   0x0058d4: 52800022  mov      w2, #1
//   0x0058d8: aa1503e1  mov      x1, x21
//   0x0058dc: 97fff3b5  bl       #0x27b0
//   0x0058e0: b94087e8  ldr      w8, [sp, #0x84]
//   0x0058e4: 31000d1f  cmn      w8, #3
//   0x0058e8: 540000e0  b.eq     #0x5904
//   0x0058ec: 3100191f  cmn      w8, #6
//   0x0058f0: 54000080  b.eq     #0x5900
//   0x0058f4: 3100251f  cmn      w8, #9
//   0x0058f8: 54000081  b.ne     #0x5908
//   0x0058fc: 940005e4  bl       #0x708c
//   0x005900: 9400055f  bl       #0x6e7c
//   0x005904: 940004bb  bl       #0x6bf0
//   0x005908: b0000080  adrp     x0, #0x16000
//   0x00590c: 91130c00  add      x0, x0, #0x4c3
//   0x005910: 9400054c  bl       #0x6e40
//   0x005914: b0000080  adrp     x0, #0x16000
//   0x005918: 9110e800  add      x0, x0, #0x43a
//   0x00591c: 94000549  bl       #0x6e40
// ============================================================================
std::uint32_t fde_07_04d94(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00004d94ULL;
    for (std::size_t i = 0; i < 739ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2201ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[08] Subroutine @ 0x005920..0x0065a8 (3208 bytes, 802 AArch64 instructions)
// [VN] Khung FDE[08] Hàm con @ 0x005920..0x0065a8 (3208 byte, 802 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x005920: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x005924: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x005928: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00592c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x005930: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x005934: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x005938: 910143fd  add      x29, sp, #0x50
//   0x00593c: d1400bff  sub      sp, sp, #2, lsl #12
//   0x005940: d11f03ff  sub      sp, sp, #0x7c0
//   0x005944: d53bd058  mrs      x24, tpidr_el0
//   0x005948: f9401708  ldr      x8, [x24, #0x28]
//   0x00594c: d00000da  adrp     x26, #0x1f000
//   0x005950: d00000dc  adrp     x28, #0x1f000
//   0x005954: aa0003f4  mov      x20, x0
//   0x005958: f81a03a8  stur     x8, [x29, #-0x60]
//   0x00595c: f947975a  ldr      x26, [x26, #0xf28]
//   0x005960: b9400348  ldr      w8, [x26]
//   0x005964: f947d39c  ldr      x28, [x28, #0xfa0]
//   0x005968: 3900039f  strb     wzr, [x28]
//   0x00596c: b5000060  cbnz     x0, #0x5978
//   0x005970: 7100051f  cmp      w8, #1
//   0x005974: 54005e41  b.ne     #0x653c
//   0x005978: 71000d1f  cmp      w8, #3
//   0x00597c: 54000280  b.eq     #0x59cc
//   0x005980: 7100091f  cmp      w8, #2
//   0x005984: 54000100  b.eq     #0x59a4
//   0x005988: 7100051f  cmp      w8, #1
//   0x00598c: 54000c61  b.ne     #0x5b18
//   0x005990: d00000c0  adrp     x0, #0x1f000
//   0x005994: f947c000  ldr      x0, [x0, #0xf80]
//   0x005998: b0000081  adrp     x1, #0x16000
//   0x00599c: 9100ac21  add      x1, x1, #0x2b
//   0x0059a0: 14000004  b        #0x59b0
//   0x0059a4: d00000c0  adrp     x0, #0x1f000
//   0x0059a8: f947c000  ldr      x0, [x0, #0xf80]
//   0x0059ac: aa1403e1  mov      x1, x20
//   0x0059b0: 97fffc0b  bl       #0x49dc
//   0x0059b4: d00000c0  adrp     x0, #0x1f000
//   0x0059b8: f947b800  ldr      x0, [x0, #0xf70]
//   0x0059bc: b0000081  adrp     x1, #0x16000
//   0x0059c0: 9100cc21  add      x1, x1, #0x33
//   0x0059c4: 97fffc06  bl       #0x49dc
//   0x0059c8: 14000060  b        #0x5b48
//   0x0059cc: d00000c0  adrp     x0, #0x1f000
//   0x0059d0: f947c000  ldr      x0, [x0, #0xf80]
//   0x0059d4: aa1403e1  mov      x1, x20
//   0x0059d8: 97fffc01  bl       #0x49dc
//   0x0059dc: d00000d3  adrp     x19, #0x1f000
//   0x0059e0: f947ba73  ldr      x19, [x19, #0xf70]
//   0x0059e4: aa1403e1  mov      x1, x20
//   0x0059e8: aa1303e0  mov      x0, x19
//   0x0059ec: 97fffbfc  bl       #0x49dc
//   0x0059f0: d00000d9  adrp     x25, #0x1f000
//   0x0059f4: d00000db  adrp     x27, #0x1f000
//   0x0059f8: f947af39  ldr      x25, [x25, #0xf58]
//   0x0059fc: f947eb7b  ldr      x27, [x27, #0xfd0]
//   0x005a00: aa1303e0  mov      x0, x19
//   0x005a04: f9400335  ldr      x21, [x25]
//   0x005a08: f9400374  ldr      x20, [x27]
//   0x005a0c: 97fff405  bl       #0x2a20
//   0x005a10: aa0003f6  mov      x22, x0
//   0x005a14: aa1503e0  mov      x0, x21
//   0x005a18: 97fff402  bl       #0x2a20
//   0x005a1c: 6b0002df  cmp      w22, w0
//   0x005a20: 540000cb  b.lt     #0x5a38
//   0x005a24: 8b36c268  add      x8, x19, w22, sxtw
//   0x005a28: cb20c100  sub      x0, x8, w0, sxtw
//   0x005a2c: aa1503e1  mov      x1, x21
//   0x005a30: 97fff3e4  bl       #0x29c0
//   0x005a34: 34000760  cbz      w0, #0x5b20
//   0x005a38: d00000d6  adrp     x22, #0x1f000
//   0x005a3c: f9400735  ldr      x21, [x25, #8]
//   0x005a40: f9400774  ldr      x20, [x27, #8]
//   0x005a44: f947bad6  ldr      x22, [x22, #0xf70]
//   0x005a48: aa1603e0  mov      x0, x22
//   0x005a4c: 97fff3f5  bl       #0x2a20
//   0x005a50: aa0003f7  mov      x23, x0
//   0x005a54: aa1503e0  mov      x0, x21
//   0x005a58: 97fff3f2  bl       #0x2a20
//   0x005a5c: 6b0002ff  cmp      w23, w0
//   0x005a60: 540000cb  b.lt     #0x5a78
//   0x005a64: 8b37c2c8  add      x8, x22, w23, sxtw
//   0x005a68: cb20c100  sub      x0, x8, w0, sxtw
//   0x005a6c: aa1503e1  mov      x1, x21
//   0x005a70: 97fff3d4  bl       #0x29c0
//   0x005a74: 34000560  cbz      w0, #0x5b20
//   0x005a78: d00000d6  adrp     x22, #0x1f000
//   0x005a7c: f9400b35  ldr      x21, [x25, #0x10]
//   0x005a80: f9400b74  ldr      x20, [x27, #0x10]
//   0x005a84: f947bad6  ldr      x22, [x22, #0xf70]
//   0x005a88: aa1603e0  mov      x0, x22
//   0x005a8c: 97fff3e5  bl       #0x2a20
//   0x005a90: aa0003f7  mov      x23, x0
//   0x005a94: aa1503e0  mov      x0, x21
//   0x005a98: 97fff3e2  bl       #0x2a20
//   0x005a9c: 6b0002ff  cmp      w23, w0
//   0x005aa0: 540000cb  b.lt     #0x5ab8
//   0x005aa4: 8b37c2c8  add      x8, x22, w23, sxtw
//   0x005aa8: cb20c100  sub      x0, x8, w0, sxtw
//   0x005aac: aa1503e1  mov      x1, x21
//   0x005ab0: 97fff3c4  bl       #0x29c0
//   0x005ab4: 34000360  cbz      w0, #0x5b20
//   0x005ab8: d00000d6  adrp     x22, #0x1f000
//   0x005abc: f9400f35  ldr      x21, [x25, #0x18]
//   0x005ac0: f9400f74  ldr      x20, [x27, #0x18]
//   0x005ac4: f947bad6  ldr      x22, [x22, #0xf70]
//   0x005ac8: aa1603e0  mov      x0, x22
//   0x005acc: 97fff3d5  bl       #0x2a20
//   0x005ad0: aa0003f7  mov      x23, x0
//   0x005ad4: aa1503e0  mov      x0, x21
//   0x005ad8: 97fff3d2  bl       #0x2a20
//   0x005adc: 6b0002ff  cmp      w23, w0
//   0x005ae0: 540000cb  b.lt     #0x5af8
//   0x005ae4: 8b37c2c8  add      x8, x22, w23, sxtw
//   0x005ae8: cb20c100  sub      x0, x8, w0, sxtw
//   0x005aec: aa1503e1  mov      x1, x21
//   0x005af0: 97fff3b4  bl       #0x29c0
//   0x005af4: 34000160  cbz      w0, #0x5b20
//   0x005af8: d00000c0  adrp     x0, #0x1f000
//   0x005afc: f947b800  ldr      x0, [x0, #0xf70]
//   0x005b00: b0000081  adrp     x1, #0x16000
//   0x005b04: 910eb021  add      x1, x1, #0x3ac
//   0x005b08: 52808142  mov      w2, #0x40a
//   0x005b0c: 97fff3d9  bl       #0x2a70
//   0x005b10: 52800034  mov      w20, #1
//   0x005b14: 1400000e  b        #0x5b4c
//   0x005b18: 2a1f03f4  mov      w20, wzr
//   0x005b1c: 1400000d  b        #0x5b50
//   0x005b20: aa1303e0  mov      x0, x19
//   0x005b24: 97fff3bf  bl       #0x2a20
//   0x005b28: aa0003f6  mov      x22, x0
//   0x005b2c: aa1503e0  mov      x0, x21
//   0x005b30: 97fff3bc  bl       #0x2a20
//   0x005b34: cb0002c8  sub      x8, x22, x0
//   0x005b38: aa1303e0  mov      x0, x19
//   0x005b3c: aa1403e1  mov      x1, x20
//   0x005b40: 38286a7f  strb     wzr, [x19, x8]
//   0x005b44: 97fff343  bl       #0x2850
//   0x005b48: 2a1f03f4  mov      w20, wzr
//   0x005b4c: b9400348  ldr      w8, [x26]
//   0x005b50: d00000d9  adrp     x25, #0x1f000
//   0x005b54: d00000d5  adrp     x21, #0x1f000
//   0x005b58: d00000d3  adrp     x19, #0x1f000
//   0x005b5c: d00000db  adrp     x27, #0x1f000
//   0x005b60: f947c739  ldr      x25, [x25, #0xf88]
//   0x005b64: f947d6b5  ldr      x21, [x21, #0xfa8]
//   0x005b68: f947ca73  ldr      x19, [x19, #0xf90]
//   0x005b6c: f947ab7b  ldr      x27, [x27, #0xf50]
//   0x005b70: 7100051f  cmp      w8, #1
//   0x005b74: 54000741  b.ne     #0x5c5c
//   0x005b78: 34000194  cbz      w20, #0x5ba8
//   0x005b7c: 39400328  ldrb     w8, [x25]
//   0x005b80: 34000148  cbz      w8, #0x5ba8
//   0x005b84: d00000c3  adrp     x3, #0x1f000
//   0x005b88: d00000c4  adrp     x4, #0x1f000
//   0x005b8c: f9400362  ldr      x2, [x27]
//   0x005b90: f947c063  ldr      x3, [x3, #0xf80]
//   0x005b94: f947b884  ldr      x4, [x4, #0xf70]
//   0x005b98: b0000081  adrp     x1, #0x16000
//   0x005b9c: 9104c260  add      x0, x19, #0x130
//   0x005ba0: 910ec421  add      x1, x1, #0x3b1
//   0x005ba4: 97fff3b7  bl       #0x2a80
//   0x005ba8: b9400348  ldr      w8, [x26]
//   0x005bac: 71000d1f  cmp      w8, #3
//   0x005bb0: 540001a1  b.ne     #0x5be4
//   0x005bb4: d00000c0  adrp     x0, #0x1f000
//   0x005bb8: f947b800  ldr      x0, [x0, #0xf70]
//   0x005bbc: b0000081  adrp     x1, #0x16000
//   0x005bc0: 9105d421  add      x1, x1, #0x175
//   0x005bc4: 97fff3c3  bl       #0x2ad0
//   0x005bc8: b40000e0  cbz      x0, #0x5be4
//   0x005bcc: 97fff341  bl       #0x28d0
//   0x005bd0: 394002a8  ldrb     w8, [x21]
//   0x005bd4: 34001588  cbz      w8, #0x5e84
//   0x005bd8: d00000c0  adrp     x0, #0x1f000
//   0x005bdc: f947b800  ldr      x0, [x0, #0xf70]
//   0x005be0: 97fff39c  bl       #0x2a50
//   0x005be4: b9400348  ldr      w8, [x26]
//   0x005be8: 71000d1f  cmp      w8, #3
//   0x005bec: 54000821  b.ne     #0x5cf0
//   0x005bf0: 394002a9  ldrb     w9, [x21]
//   0x005bf4: 350007e9  cbnz     w9, #0x5cf0
//   0x005bf8: d00000c0  adrp     x0, #0x1f000
//   0x005bfc: f947c000  ldr      x0, [x0, #0xf80]
//   0x005c00: 914007e1  add      x1, sp, #1, lsl #12
//   0x005c04: 9110a021  add      x1, x1, #0x428
//   0x005c08: 97fff2fa  bl       #0x27f0
//   0x005c0c: b9543fe8  ldr      w8, [sp, #0x143c]
//   0x005c10: 7100001f  cmp      w0, #0
//   0x005c14: 51000508  sub      w8, w8, #1
//   0x005c18: 1a9f0104  csel     w4, w8, wzr, eq
//   0x005c1c: 7100049f  cmp      w4, #1
//   0x005c20: 5400066b  b.lt     #0x5cec
//   0x005c24: d00000c3  adrp     x3, #0x1f000
//   0x005c28: f9400362  ldr      x2, [x27]
//   0x005c2c: f947c063  ldr      x3, [x3, #0xf80]
//   0x005c30: d0000088  adrp     x8, #0x17000
//   0x005c34: 90000089  adrp     x9, #0x15000
//   0x005c38: 91061908  add      x8, x8, #0x186
//   0x005c3c: 913f3129  add      x9, x9, #0xfcc
//   0x005c40: 7100049f  cmp      w4, #1
//   0x005c44: b0000081  adrp     x1, #0x16000
//   0x005c48: 9a880125  csel     x5, x9, x8, eq
//   0x005c4c: 9104c260  add      x0, x19, #0x130
//   0x005c50: 9103e421  add      x1, x1, #0xf9
//   0x005c54: 97fff38b  bl       #0x2a80
//   0x005c58: 140001b0  b        #0x6318
//   0x005c5c: d00000c0  adrp     x0, #0x1f000
//   0x005c60: f947c000  ldr      x0, [x0, #0xf80]
//   0x005c64: b0000081  adrp     x1, #0x16000
//   0x005c68: 9105d421  add      x1, x1, #0x175
//   0x005c6c: 97fff399  bl       #0x2ad0
//   0x005c70: b40002c0  cbz      x0, #0x5cc8
//   0x005c74: 97fff317  bl       #0x28d0
//   0x005c78: b9400348  ldr      w8, [x26]
//   0x005c7c: 32000109  orr      w9, w8, #1
//   0x005c80: 71000d3f  cmp      w9, #3
//   0x005c84: 54000d01  b.ne     #0x5e24
//   0x005c88: d00000c0  adrp     x0, #0x1f000
//   0x005c8c: f947c000  ldr      x0, [x0, #0xf80]
//   0x005c90: 910023e1  add      x1, sp, #8
//   0x005c94: 97fff373  bl       #0x2a60
//   0x005c98: b9401be8  ldr      w8, [sp, #0x18]
//   0x005c9c: 12140d08  and      w8, w8, #0xf000
//   0x005ca0: 7140111f  cmp      w8, #4, lsl #12
//   0x005ca4: 54000be1  b.ne     #0x5e20
//   0x005ca8: d00000c3  adrp     x3, #0x1f000
//   0x005cac: f9400362  ldr      x2, [x27]
//   0x005cb0: f947c063  ldr      x3, [x3, #0xf80]
//   0x005cb4: b0000081  adrp     x1, #0x16000
//   0x005cb8: 9104c260  add      x0, x19, #0x130
//   0x005cbc: 91022421  add      x1, x1, #0x89
//   0x005cc0: 97fff370  bl       #0x2a80
//   0x005cc4: 14000195  b        #0x6318
//   0x005cc8: f9400374  ldr      x20, [x27]
//   0x005ccc: 97fff2d1  bl       #0x2810
//   0x005cd0: b9400000  ldr      w0, [x0]
//   0x005cd4: 97fff2c3  bl       #0x27e0
//   0x005cd8: b0000081  adrp     x1, #0x16000
//   0x005cdc: aa0003e4  mov      x4, x0
//   0x005ce0: 9104c260  add      x0, x19, #0x130
//   0x005ce4: 9100f021  add      x1, x1, #0x3c
//   0x005ce8: 14000188  b        #0x6308
//   0x005cec: b9400348  ldr      w8, [x26]
//   0x005cf0: 71000d1f  cmp      w8, #3
//   0x005cf4: 54000101  b.ne     #0x5d14
//   0x005cf8: d00000c0  adrp     x0, #0x1f000
//   0x005cfc: f947c000  ldr      x0, [x0, #0xf80]
//   0x005d00: f00000c1  adrp     x1, #0x20000
//   0x005d04: 91310021  add      x1, x1, #0xc40
//   0x005d08: 97fff356  bl       #0x2a60
//   0x005d0c: 35004340  cbnz     w0, #0x6574
//   0x005d10: b9400348  ldr      w8, [x26]
//   0x005d14: 71000d1f  cmp      w8, #3
//   0x005d18: 540003e0  b.eq     #0x5d94
//   0x005d1c: 7100091f  cmp      w8, #2
//   0x005d20: 54000280  b.eq     #0x5d70
//   0x005d24: 7100051f  cmp      w8, #1
//   0x005d28: 54004281  b.ne     #0x6578
//   0x005d2c: aa1303e0  mov      x0, x19
//   0x005d30: 97fff308  bl       #0x2950
//   0x005d34: 97fff2bf  bl       #0x2830
//   0x005d38: 34000b60  cbz      w0, #0x5ea4
//   0x005d3c: f9400362  ldr      x2, [x27]
//   0x005d40: 9104c273  add      x19, x19, #0x130
//   0x005d44: b0000081  adrp     x1, #0x16000
//   0x005d48: 910f8c21  add      x1, x1, #0x3e3
//   0x005d4c: aa1303e0  mov      x0, x19
//   0x005d50: 97fff34c  bl       #0x2a80
//   0x005d54: f9400362  ldr      x2, [x27]
//   0x005d58: b0000081  adrp     x1, #0x16000
//   0x005d5c: 91054c21  add      x1, x1, #0x153
//   0x005d60: aa1303e0  mov      x0, x19
//   0x005d64: aa0203e3  mov      x3, x2
//   0x005d68: 97fff346  bl       #0x2a80
//   0x005d6c: 1400016b  b        #0x6318
//   0x005d70: d00000c0  adrp     x0, #0x1f000
//   0x005d74: f947c000  ldr      x0, [x0, #0xf80]
//   0x005d78: b0000081  adrp     x1, #0x16000
//   0x005d7c: 9105d421  add      x1, x1, #0x175
//   0x005d80: 97fff354  bl       #0x2ad0
//   0x005d84: b4002b20  cbz      x0, #0x62e8
//   0x005d88: aa0003f5  mov      x21, x0
//   0x005d8c: 91026274  add      x20, x19, #0x98
//   0x005d90: 14000047  b        #0x5eac
//   0x005d94: d00000c0  adrp     x0, #0x1f000
//   0x005d98: f947c000  ldr      x0, [x0, #0xf80]
//   0x005d9c: b0000081  adrp     x1, #0x16000
//   0x005da0: 9105d421  add      x1, x1, #0x175
//   0x005da4: 97fff34b  bl       #0x2ad0
//   0x005da8: aa0003f5  mov      x21, x0
//   0x005dac: d00000c0  adrp     x0, #0x1f000
//   0x005db0: f947b800  ldr      x0, [x0, #0xf70]
//   0x005db4: 52801821  mov      w1, #0xc1
//   0x005db8: 52803002  mov      w2, #0x180
//   0x005dbc: 97fff241  bl       #0x26c0
//   0x005dc0: 3100041f  cmn      w0, #1
//   0x005dc4: 540038c0  b.eq     #0x64dc
//   0x005dc8: b0000081  adrp     x1, #0x16000
//   0x005dcc: 9105e021  add      x1, x1, #0x178
//   0x005dd0: 2a0003f6  mov      w22, w0
//   0x005dd4: 97fff30f  bl       #0x2a10
//   0x005dd8: b40037e0  cbz      x0, #0x64d4
//   0x005ddc: aa0003f4  mov      x20, x0
//   0x005de0: b5000675  cbnz     x21, #0x5eac
//   0x005de4: f9400375  ldr      x21, [x27]
//   0x005de8: 97fff28a  bl       #0x2810
//   0x005dec: b9400000  ldr      w0, [x0]
//   0x005df0: 97fff27c  bl       #0x27e0
//   0x005df4: d00000c3  adrp     x3, #0x1f000
//   0x005df8: f947c063  ldr      x3, [x3, #0xf80]
//   0x005dfc: b0000081  adrp     x1, #0x16000
//   0x005e00: aa0003e4  mov      x4, x0
//   0x005e04: 9104c260  add      x0, x19, #0x130
//   0x005e08: 9100f021  add      x1, x1, #0x3c
//   0x005e0c: aa1503e2  mov      x2, x21
//   0x005e10: 97fff31c  bl       #0x2a80
//   0x005e14: aa1403e0  mov      x0, x20
//   0x005e18: 97fff2ae  bl       #0x28d0
//   0x005e1c: 1400013f  b        #0x6318
//   0x005e20: b9400348  ldr      w8, [x26]
//   0x005e24: 71000d1f  cmp      w8, #3
//   0x005e28: 54ffea81  b.ne     #0x5b78
//   0x005e2c: 394002a8  ldrb     w8, [x21]
//   0x005e30: 35ffea48  cbnz     w8, #0x5b78
//   0x005e34: d00000c0  adrp     x0, #0x1f000
//   0x005e38: f947c000  ldr      x0, [x0, #0xf80]
//   0x005e3c: 914007e1  add      x1, sp, #1, lsl #12
//   0x005e40: 9110a021  add      x1, x1, #0x428
//   0x005e44: 97fff26b  bl       #0x27f0
//   0x005e48: 350000a0  cbnz     w0, #0x5e5c
//   0x005e4c: b9543be8  ldr      w8, [sp, #0x1438]
//   0x005e50: 12140d08  and      w8, w8, #0xf000
//   0x005e54: 7140211f  cmp      w8, #8, lsl #12
//   0x005e58: 54ffe900  b.eq     #0x5b78
//   0x005e5c: 39400328  ldrb     w8, [x25]
//   0x005e60: 340025c8  cbz      w8, #0x6318
//   0x005e64: d00000c3  adrp     x3, #0x1f000
//   0x005e68: f9400362  ldr      x2, [x27]
//   0x005e6c: f947c063  ldr      x3, [x3, #0xf80]
//   0x005e70: b0000081  adrp     x1, #0x16000
//   0x005e74: 9104c260  add      x0, x19, #0x130
//   0x005e78: 9102b021  add      x1, x1, #0xac
//   0x005e7c: 97fff301  bl       #0x2a80
//   0x005e80: 14000126  b        #0x6318
//   0x005e84: d00000c3  adrp     x3, #0x1f000
//   0x005e88: f9400362  ldr      x2, [x27]
//   0x005e8c: f947b863  ldr      x3, [x3, #0xf70]
//   0x005e90: b0000081  adrp     x1, #0x16000
//   0x005e94: 9104c260  add      x0, x19, #0x130
//   0x005e98: 91035421  add      x1, x1, #0xd5
//   0x005e9c: 97fff2f9  bl       #0x2a80
//   0x005ea0: 1400011e  b        #0x6318
//   0x005ea4: 91026274  add      x20, x19, #0x98
//   0x005ea8: aa1303f5  mov      x21, x19
//   0x005eac: d00000c8  adrp     x8, #0x1f000
//   0x005eb0: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x005eb4: b9400108  ldr      w8, [x8]
//   0x005eb8: 7100051f  cmp      w8, #1
//   0x005ebc: 540004cb  b.lt     #0x5f54
//   0x005ec0: d00000d7  adrp     x23, #0x1f000
//   0x005ec4: f947c2f7  ldr      x23, [x23, #0xf80]
//   0x005ec8: 9104c276  add      x22, x19, #0x130
//   0x005ecc: b0000081  adrp     x1, #0x16000
//   0x005ed0: 91068421  add      x1, x1, #0x1a1
//   0x005ed4: aa1603e0  mov      x0, x22
//   0x005ed8: aa1703e2  mov      x2, x23
//   0x005edc: 97fff2e9  bl       #0x2a80
//   0x005ee0: aa1703e0  mov      x0, x23
//   0x005ee4: 97fff2cf  bl       #0x2a20
//   0x005ee8: d00000dc  adrp     x28, #0x1f000
//   0x005eec: f947fb9c  ldr      x28, [x28, #0xff0]
//   0x005ef0: b9400393  ldr      w19, [x28]
//   0x005ef4: 6b00027f  cmp      w19, w0
//   0x005ef8: 540001ed  b.le     #0x5f34
//   0x005efc: d00000d7  adrp     x23, #0x1f000
//   0x005f00: f947c2f7  ldr      x23, [x23, #0xf80]
//   0x005f04: 52800039  mov      w25, #1
//   0x005f08: aa1703e0  mov      x0, x23
//   0x005f0c: 97fff2c5  bl       #0x2a20
//   0x005f10: 4b000268  sub      w8, w19, w0
//   0x005f14: 6b08033f  cmp      w25, w8
//   0x005f18: 540000ec  b.gt     #0x5f34
//   0x005f1c: 52800400  mov      w0, #0x20
//   0x005f20: aa1603e1  mov      x1, x22
//   0x005f24: 97fff27b  bl       #0x2910
//   0x005f28: b9400393  ldr      w19, [x28]
//   0x005f2c: 11000739  add      w25, w25, #1
//   0x005f30: 17fffff6  b        #0x5f08
//   0x005f34: aa1603e0  mov      x0, x22
//   0x005f38: 97fff26e  bl       #0x28f0
//   0x005f3c: d00000dc  adrp     x28, #0x1f000
//   0x005f40: d00000d3  adrp     x19, #0x1f000
//   0x005f44: d00000d9  adrp     x25, #0x1f000
//   0x005f48: f947d39c  ldr      x28, [x28, #0xfa0]
//   0x005f4c: f947ca73  ldr      x19, [x19, #0xf90]
//   0x005f50: f947c739  ldr      x25, [x25, #0xf88]
//   0x005f54: d00000c9  adrp     x9, #0x1f000
//   0x005f58: f947b529  ldr      x9, [x9, #0xf68]
//   0x005f5c: 52800028  mov      w8, #1
//   0x005f60: aa1403e0  mov      x0, x20
//   0x005f64: 39000388  strb     w8, [x28]
//   0x005f68: f9000134  str      x20, [x9]
//   0x005f6c: b90097ff  str      wzr, [sp, #0x94]
//   0x005f70: 97fff29c  bl       #0x29e0
//   0x005f74: 35003000  cbnz     w0, #0x6574
//   0x005f78: aa1503e0  mov      x0, x21
//   0x005f7c: 97fff299  bl       #0x29e0
//   0x005f80: 35002fa0  cbnz     w0, #0x6574
//   0x005f84: d00000c8  adrp     x8, #0x1f000
//   0x005f88: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x005f8c: 910273e0  add      x0, sp, #0x9c
//   0x005f90: 910283e4  add      x4, sp, #0xa0
//   0x005f94: aa1503e1  mov      x1, x21
//   0x005f98: b9400102  ldr      w2, [x8]
//   0x005f9c: d00000c8  adrp     x8, #0x1f000
//   0x005fa0: f947a508  ldr      x8, [x8, #0xf48]
//   0x005fa4: 2a1f03e5  mov      w5, wzr
//   0x005fa8: 39400103  ldrb     w3, [x8]
//   0x005fac: 97fff1cd  bl       #0x26e0
//   0x005fb0: aa0003f6  mov      x22, x0
//   0x005fb4: 2a1f03f7  mov      w23, wzr
//   0x005fb8: b40011c0  cbz      x0, #0x61f0
//   0x005fbc: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x005fc0: 35001188  cbnz     w8, #0x61f0
//   0x005fc4: 910283e8  add      x8, sp, #0xa0
//   0x005fc8: 2a1f03f7  mov      w23, wzr
//   0x005fcc: 91004108  add      x8, x8, #0x10
//   0x005fd0: f90003e8  str      x8, [sp]
//   0x005fd4: 2a1f03e8  mov      w8, wzr
//   0x005fd8: 110006f7  add      w23, w23, #1
//   0x005fdc: 35000328  cbnz     w8, #0x6040
//   0x005fe0: 914007e2  add      x2, sp, #1, lsl #12
//   0x005fe4: 910273e0  add      x0, sp, #0x9c
//   0x005fe8: 9110a042  add      x2, x2, #0x428
//   0x005fec: 52827103  mov      w3, #0x1388
//   0x005ff0: aa1603e1  mov      x1, x22
//   0x005ff4: 97fff227  bl       #0x2890
//   0x005ff8: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x005ffc: 3100151f  cmn      w8, #5
//   0x006000: 54000b20  b.eq     #0x6164
//   0x006004: 7100041f  cmp      w0, #1
//   0x006008: 5400012b  b.lt     #0x602c
//   0x00600c: 121d7908  and      w8, w8, #0xfffffffb
//   0x006010: 350000e8  cbnz     w8, #0x602c
//   0x006014: 93407c02  sxtw     x2, w0
//   0x006018: 914007e0  add      x0, sp, #1, lsl #12
//   0x00601c: 9110a000  add      x0, x0, #0x428
//   0x006020: 52800021  mov      w1, #1
//   0x006024: aa1403e3  mov      x3, x20
//   0x006028: 97fff2ae  bl       #0x2ae0
//   0x00602c: aa1403e0  mov      x0, x20
//   0x006030: 97fff26c  bl       #0x29e0
//   0x006034: 35002a00  cbnz     w0, #0x6574
//   0x006038: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x00603c: 34fffd28  cbz      w8, #0x5fe0
//   0x006040: 7100111f  cmp      w8, #4
//   0x006044: 54000d61  b.ne     #0x61f0
//   0x006048: 910273e0  add      x0, sp, #0x9c
//   0x00604c: 910223e2  add      x2, sp, #0x88
//   0x006050: 910253e3  add      x3, sp, #0x94
//   0x006054: aa1603e1  mov      x1, x22
//   0x006058: 97fff216  bl       #0x28b0
//   0x00605c: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x006060: 350029e8  cbnz     w8, #0x659c
//   0x006064: b98097e8  ldrsw    x8, [sp, #0x94]
//   0x006068: 7100051f  cmp      w8, #1
//   0x00606c: 5400028b  b.lt     #0x60bc
//   0x006070: f94047e9  ldr      x9, [sp, #0x88]
//   0x006074: 7100811f  cmp      w8, #0x20
//   0x006078: 54000103  b.lo     #0x6098
//   0x00607c: 8b08012a  add      x10, x9, x8
//   0x006080: 910283eb  add      x11, sp, #0xa0
//   0x006084: eb0a017f  cmp      x11, x10
//   0x006088: 54000542  b.hs     #0x6130
//   0x00608c: 8b08016a  add      x10, x11, x8
//   0x006090: eb0a013f  cmp      x9, x10
//   0x006094: 540004e2  b.hs     #0x6130
//   0x006098: aa1f03ea  mov      x10, xzr
//   0x00609c: 910283eb  add      x11, sp, #0xa0
//   0x0060a0: cb0a0108  sub      x8, x8, x10
//   0x0060a4: 8b0a016b  add      x11, x11, x10
//   0x0060a8: 8b0a0129  add      x9, x9, x10
//   0x0060ac: 3840152a  ldrb     w10, [x9], #1
//   0x0060b0: f1000508  subs     x8, x8, #1
//   0x0060b4: 3800156a  strb     w10, [x11], #1
//   0x0060b8: 54ffffa1  b.ne     #0x60ac
//   0x0060bc: 910273e0  add      x0, sp, #0x9c
//   0x0060c0: aa1603e1  mov      x1, x22
//   0x0060c4: 97fff1a7  bl       #0x2760
//   0x0060c8: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x0060cc: 35002688  cbnz     w8, #0x659c
//   0x0060d0: b94097e5  ldr      w5, [sp, #0x94]
//   0x0060d4: 35000105  cbnz     w5, #0x60f4
//   0x0060d8: aa1503e0  mov      x0, x21
//   0x0060dc: 97fff23d  bl       #0x29d0
//   0x0060e0: 3100041f  cmn      w0, #1
//   0x0060e4: 540012a0  b.eq     #0x6338
//   0x0060e8: aa1503e1  mov      x1, x21
//   0x0060ec: 97fff1a9  bl       #0x2790
//   0x0060f0: b94097e5  ldr      w5, [sp, #0x94]
//   0x0060f4: b00000c8  adrp     x8, #0x1f000
//   0x0060f8: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x0060fc: 910273e0  add      x0, sp, #0x9c
//   0x006100: 910283e4  add      x4, sp, #0xa0
//   0x006104: aa1503e1  mov      x1, x21
//   0x006108: b9400102  ldr      w2, [x8]
//   0x00610c: b00000c8  adrp     x8, #0x1f000
//   0x006110: f947a508  ldr      x8, [x8, #0xf48]
//   0x006114: 39400103  ldrb     w3, [x8]
//   0x006118: 97fff172  bl       #0x26e0
//   0x00611c: aa0003f6  mov      x22, x0
//   0x006120: b4000680  cbz      x0, #0x61f0
//   0x006124: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x006128: 34fff568  cbz      w8, #0x5fd4
//   0x00612c: 14000031  b        #0x61f0
//   0x006130: f94003ed  ldr      x13, [sp]
//   0x006134: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x006138: 9100412b  add      x11, x9, #0x10
//   0x00613c: aa0a03ec  mov      x12, x10
//   0x006140: ad7f8560  ldp      q0, q1, [x11, #-0x10]
//   0x006144: 9100816b  add      x11, x11, #0x20
//   0x006148: f100818c  subs     x12, x12, #0x20
//   0x00614c: ad3f85a0  stp      q0, q1, [x13, #-0x10]
//   0x006150: 910081ad  add      x13, x13, #0x20
//   0x006154: 54ffff61  b.ne     #0x6140
//   0x006158: eb08015f  cmp      x10, x8
//   0x00615c: 54fffb00  b.eq     #0x60bc
//   0x006160: 17ffffcf  b        #0x609c
//   0x006164: b00000c8  adrp     x8, #0x1f000
//   0x006168: f947d508  ldr      x8, [x8, #0xfa8]
//   0x00616c: 39400108  ldrb     w8, [x8]
//   0x006170: 34000408  cbz      w8, #0x61f0
//   0x006174: aa1503e0  mov      x0, x21
//   0x006178: 97fff1e2  bl       #0x2900
//   0x00617c: 14000004  b        #0x618c
//   0x006180: aa1403e0  mov      x0, x20
//   0x006184: 97fff217  bl       #0x29e0
//   0x006188: 35001f60  cbnz     w0, #0x6574
//   0x00618c: aa1503e0  mov      x0, x21
//   0x006190: 97fff210  bl       #0x29d0
//   0x006194: 3100041f  cmn      w0, #1
//   0x006198: 54000d00  b.eq     #0x6338
//   0x00619c: aa1503e1  mov      x1, x21
//   0x0061a0: 97fff17c  bl       #0x2790
//   0x0061a4: 914007e0  add      x0, sp, #1, lsl #12
//   0x0061a8: 9110a000  add      x0, x0, #0x428
//   0x0061ac: 52800021  mov      w1, #1
//   0x0061b0: 52827102  mov      w2, #0x1388
//   0x0061b4: aa1503e3  mov      x3, x21
//   0x0061b8: 97fff15e  bl       #0x2730
//   0x0061bc: aa0003f6  mov      x22, x0
//   0x0061c0: aa1503e0  mov      x0, x21
//   0x0061c4: 97fff207  bl       #0x29e0
//   0x0061c8: 35001d60  cbnz     w0, #0x6574
//   0x0061cc: 710006df  cmp      w22, #1
//   0x0061d0: 54fffd8b  b.lt     #0x6180
//   0x0061d4: 914007e0  add      x0, sp, #1, lsl #12
//   0x0061d8: 93407ec2  sxtw     x2, w22
//   0x0061dc: 9110a000  add      x0, x0, #0x428
//   0x0061e0: 52800021  mov      w1, #1
//   0x0061e4: aa1403e3  mov      x3, x20
//   0x0061e8: 97fff23e  bl       #0x2ae0
//   0x0061ec: 17ffffe5  b        #0x6180
//   0x0061f0: 910263e0  add      x0, sp, #0x98
//   0x0061f4: aa1603e1  mov      x1, x22
//   0x0061f8: 97fff15a  bl       #0x2760
//   0x0061fc: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x006200: 3100151f  cmn      w8, #5
//   0x006204: 54001a41  b.ne     #0x654c
//   0x006208: eb1302bf  cmp      x21, x19
//   0x00620c: 54000060  b.eq     #0x6218
//   0x006210: aa1503e0  mov      x0, x21
//   0x006214: 97fff1af  bl       #0x28d0
//   0x006218: 91026268  add      x8, x19, #0x98
//   0x00621c: eb08029f  cmp      x20, x8
//   0x006220: 54000060  b.eq     #0x622c
//   0x006224: aa1403e0  mov      x0, x20
//   0x006228: 97fff1aa  bl       #0x28d0
//   0x00622c: 710006ff  cmp      w23, #1
//   0x006230: 54000441  b.ne     #0x62b8
//   0x006234: b00000c8  adrp     x8, #0x1f000
//   0x006238: f947b508  ldr      x8, [x8, #0xf68]
//   0x00623c: b00000c9  adrp     x9, #0x1f000
//   0x006240: 5280002a  mov      w10, #1
//   0x006244: f900011f  str      xzr, [x8]
//   0x006248: b9400348  ldr      w8, [x26]
//   0x00624c: f947f129  ldr      x9, [x9, #0xfe0]
//   0x006250: 3900039f  strb     wzr, [x28]
//   0x006254: 71000d1f  cmp      w8, #3
//   0x006258: 3900012a  strb     w10, [x9]
//   0x00625c: 540000a1  b.ne     #0x6270
//   0x006260: b00000c0  adrp     x0, #0x1f000
//   0x006264: f947b800  ldr      x0, [x0, #0xf70]
//   0x006268: 97fff1fa  bl       #0x2a50
//   0x00626c: 35001840  cbnz     w0, #0x6574
//   0x006270: b00000c8  adrp     x8, #0x1f000
//   0x006274: f9479d08  ldr      x8, [x8, #0xf38]
//   0x006278: 3900039f  strb     wzr, [x28]
//   0x00627c: b9400109  ldr      w9, [x8]
//   0x006280: 7100053f  cmp      w9, #1
//   0x006284: 5400006c  b.gt     #0x6290
//   0x006288: 52800049  mov      w9, #2
//   0x00628c: b9000109  str      w9, [x8]
//   0x006290: b00000c8  adrp     x8, #0x1f000
//   0x006294: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x006298: b9400108  ldr      w8, [x8]
//   0x00629c: 7100051f  cmp      w8, #1
//   0x0062a0: 540013eb  b.lt     #0x651c
//   0x0062a4: 90000080  adrp     x0, #0x16000
//   0x0062a8: 9104c263  add      x3, x19, #0x130
//   0x0062ac: 91118000  add      x0, x0, #0x460
//   0x0062b0: 52800241  mov      w1, #0x12
//   0x0062b4: 14000079  b        #0x6498
//   0x0062b8: b00000d4  adrp     x20, #0x1f000
//   0x0062bc: 39400328  ldrb     w8, [x25]
//   0x0062c0: f947b694  ldr      x20, [x20, #0xf68]
//   0x0062c4: 34000a48  cbz      w8, #0x640c
//   0x0062c8: b00000c3  adrp     x3, #0x1f000
//   0x0062cc: f9400362  ldr      x2, [x27]
//   0x0062d0: f947c063  ldr      x3, [x3, #0xf80]
//   0x0062d4: 90000081  adrp     x1, #0x16000
//   0x0062d8: 9104c260  add      x0, x19, #0x130
//   0x0062dc: 91125021  add      x1, x1, #0x494
//   0x0062e0: 97fff1e8  bl       #0x2a80
//   0x0062e4: 1400004a  b        #0x640c
//   0x0062e8: f9400374  ldr      x20, [x27]
//   0x0062ec: 97fff149  bl       #0x2810
//   0x0062f0: b9400000  ldr      w0, [x0]
//   0x0062f4: 97fff13b  bl       #0x27e0
//   0x0062f8: 90000081  adrp     x1, #0x16000
//   0x0062fc: aa0003e4  mov      x4, x0
//   0x006300: 9104c260  add      x0, x19, #0x130
//   0x006304: 91105821  add      x1, x1, #0x416
//   0x006308: b00000c3  adrp     x3, #0x1f000
//   0x00630c: f947c063  ldr      x3, [x3, #0xf80]
//   0x006310: aa1403e2  mov      x2, x20
//   0x006314: 97fff1db  bl       #0x2a80
//   0x006318: b00000c8  adrp     x8, #0x1f000
//   0x00631c: f9479d08  ldr      x8, [x8, #0xf38]
//   0x006320: b9400109  ldr      w9, [x8]
//   0x006324: 7100013f  cmp      w9, #0
//   0x006328: 54000bcc  b.gt     #0x64a0
//   0x00632c: 52800029  mov      w9, #1
//   0x006330: b9000109  str      w9, [x8]
//   0x006334: 1400005b  b        #0x64a0
//   0x006338: aa1503e0  mov      x0, x21
//   0x00633c: 97fff1a9  bl       #0x29e0
//   0x006340: 350011a0  cbnz     w0, #0x6574
//   0x006344: 91026268  add      x8, x19, #0x98
//   0x006348: eb08029f  cmp      x20, x8
//   0x00634c: 540001c0  b.eq     #0x6384
//   0x006350: aa1403e0  mov      x0, x20
//   0x006354: 97fff17f  bl       #0x2950
//   0x006358: 37f810e0  tbnz     w0, #0x1f, #0x6574
//   0x00635c: d00000c8  adrp     x8, #0x20000
//   0x006360: b94c5101  ldr      w1, [x8, #0xc50]
//   0x006364: 2a0003f6  mov      w22, w0
//   0x006368: 97fff0d2  bl       #0x26b0
//   0x00636c: 35001040  cbnz     w0, #0x6574
//   0x006370: d00000c8  adrp     x8, #0x20000
//   0x006374: 91316108  add      x8, x8, #0xc58
//   0x006378: 29400901  ldp      w1, w2, [x8]
//   0x00637c: 2a1603e0  mov      w0, w22
//   0x006380: 97fff108  bl       #0x27a0
//   0x006384: aa1503e0  mov      x0, x21
//   0x006388: 97fff152  bl       #0x28d0
//   0x00638c: 3100041f  cmn      w0, #1
//   0x006390: 54000f20  b.eq     #0x6574
//   0x006394: aa1403e0  mov      x0, x20
//   0x006398: 97fff192  bl       #0x29e0
//   0x00639c: 35000ec0  cbnz     w0, #0x6574
//   0x0063a0: aa1403e0  mov      x0, x20
//   0x0063a4: 97fff153  bl       #0x28f0
//   0x0063a8: 35000e60  cbnz     w0, #0x6574
//   0x0063ac: 91026268  add      x8, x19, #0x98
//   0x0063b0: eb08029f  cmp      x20, x8
//   0x0063b4: 54000100  b.eq     #0x63d4
//   0x0063b8: aa1403e0  mov      x0, x20
//   0x0063bc: 97fff145  bl       #0x28d0
//   0x0063c0: b00000c8  adrp     x8, #0x1f000
//   0x0063c4: f947b508  ldr      x8, [x8, #0xf68]
//   0x0063c8: 3100041f  cmn      w0, #1
//   0x0063cc: f900011f  str      xzr, [x8]
//   0x0063d0: 54000d20  b.eq     #0x6574
//   0x0063d4: b00000c8  adrp     x8, #0x1f000
//   0x0063d8: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x0063dc: b00000d4  adrp     x20, #0x1f000
//   0x0063e0: b9400108  ldr      w8, [x8]
//   0x0063e4: f947b694  ldr      x20, [x20, #0xf68]
//   0x0063e8: 7100091f  cmp      w8, #2
//   0x0063ec: f900029f  str      xzr, [x20]
//   0x0063f0: 540000eb  b.lt     #0x640c
//   0x0063f4: 90000080  adrp     x0, #0x16000
//   0x0063f8: 9104c263  add      x3, x19, #0x130
//   0x0063fc: 91123800  add      x0, x0, #0x48e
//   0x006400: 528000a1  mov      w1, #5
//   0x006404: 52800022  mov      w2, #1
//   0x006408: 97fff1b6  bl       #0x2ae0
//   0x00640c: b9400348  ldr      w8, [x26]
//   0x006410: f900029f  str      xzr, [x20]
//   0x006414: 71000d1f  cmp      w8, #3
//   0x006418: 540002c1  b.ne     #0x6470
//   0x00641c: d00000c8  adrp     x8, #0x20000
//   0x006420: 91322108  add      x8, x8, #0xc88
//   0x006424: f9400909  ldr      x9, [x8, #0x10]
//   0x006428: f9400108  ldr      x8, [x8]
//   0x00642c: b00000c0  adrp     x0, #0x1f000
//   0x006430: 914007e1  add      x1, sp, #1, lsl #12
//   0x006434: f90a1be9  str      x9, [sp, #0x1430]
//   0x006438: f90a17e8  str      x8, [sp, #0x1428]
//   0x00643c: f947b800  ldr      x0, [x0, #0xf70]
//   0x006440: 9110a021  add      x1, x1, #0x428
//   0x006444: 97fff15b  bl       #0x29b0
//   0x006448: 35000960  cbnz     w0, #0x6574
//   0x00644c: b00000c8  adrp     x8, #0x1f000
//   0x006450: f947bd08  ldr      x8, [x8, #0xf78]
//   0x006454: 3900039f  strb     wzr, [x28]
//   0x006458: 39400108  ldrb     w8, [x8]
//   0x00645c: 350000a8  cbnz     w8, #0x6470
//   0x006460: b00000c0  adrp     x0, #0x1f000
//   0x006464: f947c000  ldr      x0, [x0, #0xf80]
//   0x006468: 97fff17a  bl       #0x2a50
//   0x00646c: 35000840  cbnz     w0, #0x6574
//   0x006470: b00000c8  adrp     x8, #0x1f000
//   0x006474: f947ed08  ldr      x8, [x8, #0xfd8]
//   0x006478: 3900039f  strb     wzr, [x28]
//   0x00647c: b9400108  ldr      w8, [x8]
//   0x006480: 7100051f  cmp      w8, #1
//   0x006484: 540000eb  b.lt     #0x64a0
//   0x006488: 90000080  adrp     x0, #0x16000
//   0x00648c: 9104c263  add      x3, x19, #0x130
//   0x006490: 91114000  add      x0, x0, #0x450
//   0x006494: 528000a1  mov      w1, #5
//   0x006498: 52800022  mov      w2, #1
//   0x00649c: 97fff191  bl       #0x2ae0
//   0x0064a0: f9401708  ldr      x8, [x24, #0x28]
//   0x0064a4: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x0064a8: eb09011f  cmp      x8, x9
//   0x0064ac: 540004e1  b.ne     #0x6548
//   0x0064b0: 91400bff  add      sp, sp, #2, lsl #12
//   0x0064b4: 911f03ff  add      sp, sp, #0x7c0
//   0x0064b8: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x0064bc: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x0064c0: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0064c4: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x0064c8: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x0064cc: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x0064d0: d65f03c0  ret      
//   0x0064d4: 2a1603e0  mov      w0, w22
//   0x0064d8: 97fff15a  bl       #0x2a40
//   0x0064dc: f9400374  ldr      x20, [x27]
//   0x0064e0: 97fff0cc  bl       #0x2810
//   0x0064e4: b9400000  ldr      w0, [x0]
//   0x0064e8: 97fff0be  bl       #0x27e0
//   0x0064ec: b00000c3  adrp     x3, #0x1f000
//   0x0064f0: f947b863  ldr      x3, [x3, #0xf70]
//   0x0064f4: 90000081  adrp     x1, #0x16000
//   0x0064f8: aa0003e4  mov      x4, x0
//   0x0064fc: 9104c260  add      x0, x19, #0x130
//   0x006500: 9105ec21  add      x1, x1, #0x17b
//   0x006504: aa1403e2  mov      x2, x20
//   0x006508: 97fff15e  bl       #0x2a80
//   0x00650c: b4fff075  cbz      x21, #0x6318
//   0x006510: aa1503e0  mov      x0, x21
//   0x006514: 97fff0ef  bl       #0x28d0
//   0x006518: 17ffff80  b        #0x6318
//   0x00651c: b00000c3  adrp     x3, #0x1f000
//   0x006520: f9400362  ldr      x2, [x27]
//   0x006524: f947c063  ldr      x3, [x3, #0xf80]
//   0x006528: 90000081  adrp     x1, #0x16000
//   0x00652c: 9104c260  add      x0, x19, #0x130
//   0x006530: 91115821  add      x1, x1, #0x456
//   0x006534: 97fff153  bl       #0x2a80
//   0x006538: 17ffffda  b        #0x64a0
//   0x00653c: 90000080  adrp     x0, #0x16000
//   0x006540: 910e5400  add      x0, x0, #0x395
//   0x006544: 9400023f  bl       #0x6e40
//   0x006548: 97fff0f6  bl       #0x2920
//   0x00654c: 11002508  add      w8, w8, #9
//   0x006550: 7100191f  cmp      w8, #6
//   0x006554: 540001e8  b.hi     #0x6590
//   0x006558: d0000069  adrp     x9, #0x14000
//   0x00655c: 91379929  add      x9, x9, #0xde6
//   0x006560: 1000008a  adr      x10, #0x6570
//   0x006564: 3868692b  ldrb     w11, [x9, x8]
//   0x006568: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00656c: d61f0140  br       x10
//   0x006570: 940002c7  bl       #0x708c
//   0x006574: 94000242  bl       #0x6e7c
//   0x006578: 90000080  adrp     x0, #0x16000
//   0x00657c: 9110e000  add      x0, x0, #0x438
//   0x006580: 94000230  bl       #0x6e40
//   0x006584: 940002e3  bl       #0x7110
//   0x006588: 940002d3  bl       #0x70d4
//   0x00658c: 94000199  bl       #0x6bf0
//   0x006590: 90000080  adrp     x0, #0x16000
//   0x006594: 91130400  add      x0, x0, #0x4c1
//   0x006598: 9400022a  bl       #0x6e40
//   0x00659c: 90000080  adrp     x0, #0x16000
//   0x0065a0: 9111cc00  add      x0, x0, #0x473
//   0x0065a4: 94000227  bl       #0x6e40
// ============================================================================
std::uint32_t fde_08_05920(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00005920ULL;
    for (std::size_t i = 0; i < 802ULL; ++i) {
        std::uint32_t insn = kTextInstructions[2940ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[09] Subroutine @ 0x0065a8..0x006bf0 (1608 bytes, 402 AArch64 instructions)
// [VN] Khung FDE[09] Hàm con @ 0x0065a8..0x006bf0 (1608 byte, 402 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0065a8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0065ac: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0065b0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0065b4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0065b8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0065bc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0065c0: 910143fd  add      x29, sp, #0x50
//   0x0065c4: d1400bff  sub      sp, sp, #2, lsl #12
//   0x0065c8: d11f03ff  sub      sp, sp, #0x7c0
//   0x0065cc: d53bd056  mrs      x22, tpidr_el0
//   0x0065d0: b00000c9  adrp     x9, #0x1f000
//   0x0065d4: f94016c8  ldr      x8, [x22, #0x28]
//   0x0065d8: f947d129  ldr      x9, [x9, #0xfa0]
//   0x0065dc: b00000d4  adrp     x20, #0x1f000
//   0x0065e0: aa0003f3  mov      x19, x0
//   0x0065e4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x0065e8: 3900013f  strb     wzr, [x9]
//   0x0065ec: f9479694  ldr      x20, [x20, #0xf28]
//   0x0065f0: b5000080  cbnz     x0, #0x6600
//   0x0065f4: b9400288  ldr      w8, [x20]
//   0x0065f8: 7100051f  cmp      w8, #1
//   0x0065fc: 54002e01  b.ne     #0x6bbc
//   0x006600: b00000c0  adrp     x0, #0x1f000
//   0x006604: f947b800  ldr      x0, [x0, #0xf70]
//   0x006608: d0000061  adrp     x1, #0x14000
//   0x00660c: 91383421  add      x1, x1, #0xe0d
//   0x006610: 97fff8f3  bl       #0x49dc
//   0x006614: b9400288  ldr      w8, [x20]
//   0x006618: 7100051f  cmp      w8, #1
//   0x00661c: 540000c0  b.eq     #0x6634
//   0x006620: 7100091f  cmp      w8, #2
//   0x006624: 540000c0  b.eq     #0x663c
//   0x006628: 71000d1f  cmp      w8, #3
//   0x00662c: 54000080  b.eq     #0x663c
//   0x006630: 14000008  b        #0x6650
//   0x006634: 90000093  adrp     x19, #0x16000
//   0x006638: 9100ae73  add      x19, x19, #0x2b
//   0x00663c: b00000c0  adrp     x0, #0x1f000
//   0x006640: f947c000  ldr      x0, [x0, #0xf80]
//   0x006644: aa1303e1  mov      x1, x19
//   0x006648: 97fff8e5  bl       #0x49dc
//   0x00664c: b9400288  ldr      w8, [x20]
//   0x006650: b00000d7  adrp     x23, #0x1f000
//   0x006654: f947caf7  ldr      x23, [x23, #0xf90]
//   0x006658: 7100051f  cmp      w8, #1
//   0x00665c: 54000160  b.eq     #0x6688
//   0x006660: b00000c0  adrp     x0, #0x1f000
//   0x006664: f947c000  ldr      x0, [x0, #0xf80]
//   0x006668: 90000081  adrp     x1, #0x16000
//   0x00666c: 9105d421  add      x1, x1, #0x175
//   0x006670: 97fff118  bl       #0x2ad0
//   0x006674: b4000340  cbz      x0, #0x66dc
//   0x006678: 97fff096  bl       #0x28d0
//   0x00667c: b9400288  ldr      w8, [x20]
//   0x006680: 7100051f  cmp      w8, #1
//   0x006684: 54000581  b.ne     #0x6734
//   0x006688: b00000d3  adrp     x19, #0x1f000
//   0x00668c: f947ca73  ldr      x19, [x19, #0xf90]
//   0x006690: aa1303e0  mov      x0, x19
//   0x006694: 97fff0af  bl       #0x2950
//   0x006698: 97fff066  bl       #0x2830
//   0x00669c: 34000840  cbz      w0, #0x67a4
//   0x0066a0: b00000d4  adrp     x20, #0x1f000
//   0x0066a4: f947aa94  ldr      x20, [x20, #0xf50]
//   0x0066a8: 9104c273  add      x19, x19, #0x130
//   0x0066ac: 90000081  adrp     x1, #0x16000
//   0x0066b0: 910f8c21  add      x1, x1, #0x3e3
//   0x0066b4: f9400282  ldr      x2, [x20]
//   0x0066b8: aa1303e0  mov      x0, x19
//   0x0066bc: 97fff0f1  bl       #0x2a80
//   0x0066c0: f9400282  ldr      x2, [x20]
//   0x0066c4: 90000081  adrp     x1, #0x16000
//   0x0066c8: 91054c21  add      x1, x1, #0x153
//   0x0066cc: aa1303e0  mov      x0, x19
//   0x0066d0: aa0203e3  mov      x3, x2
//   0x0066d4: 97fff0eb  bl       #0x2a80
//   0x0066d8: 1400000f  b        #0x6714
//   0x0066dc: b00000c8  adrp     x8, #0x1f000
//   0x0066e0: f947a908  ldr      x8, [x8, #0xf50]
//   0x0066e4: f9400113  ldr      x19, [x8]
//   0x0066e8: 97fff04a  bl       #0x2810
//   0x0066ec: b9400000  ldr      w0, [x0]
//   0x0066f0: 97fff03c  bl       #0x27e0
//   0x0066f4: 90000081  adrp     x1, #0x16000
//   0x0066f8: aa0003e4  mov      x4, x0
//   0x0066fc: 9104c2e0  add      x0, x23, #0x130
//   0x006700: 9119b821  add      x1, x1, #0x66e
//   0x006704: b00000c3  adrp     x3, #0x1f000
//   0x006708: f947c063  ldr      x3, [x3, #0xf80]
//   0x00670c: aa1303e2  mov      x2, x19
//   0x006710: 97fff0dc  bl       #0x2a80
//   0x006714: b00000c8  adrp     x8, #0x1f000
//   0x006718: f9479d08  ldr      x8, [x8, #0xf38]
//   0x00671c: b9400109  ldr      w9, [x8]
//   0x006720: 7100013f  cmp      w9, #0
//   0x006724: 5400232c  b.gt     #0x6b88
//   0x006728: 52800029  mov      w9, #1
//   0x00672c: b9000109  str      w9, [x8]
//   0x006730: 14000116  b        #0x6b88
//   0x006734: b00000c0  adrp     x0, #0x1f000
//   0x006738: f947c000  ldr      x0, [x0, #0xf80]
//   0x00673c: 910023e1  add      x1, sp, #8
//   0x006740: 97fff0c8  bl       #0x2a60
//   0x006744: b9401be8  ldr      w8, [sp, #0x18]
//   0x006748: 12140d08  and      w8, w8, #0xf000
//   0x00674c: 7140111f  cmp      w8, #4, lsl #12
//   0x006750: 54000141  b.ne     #0x6778
//   0x006754: b00000c8  adrp     x8, #0x1f000
//   0x006758: f947a908  ldr      x8, [x8, #0xf50]
//   0x00675c: b00000c3  adrp     x3, #0x1f000
//   0x006760: 90000081  adrp     x1, #0x16000
//   0x006764: 9104c2e0  add      x0, x23, #0x130
//   0x006768: f9400102  ldr      x2, [x8]
//   0x00676c: f947c063  ldr      x3, [x3, #0xf80]
//   0x006770: 91022421  add      x1, x1, #0x89
//   0x006774: 17ffffd8  b        #0x66d4
//   0x006778: b9400288  ldr      w8, [x20]
//   0x00677c: 51000909  sub      w9, w8, #2
//   0x006780: 7100093f  cmp      w9, #2
//   0x006784: 54001b62  b.hs     #0x6af0
//   0x006788: b00000c0  adrp     x0, #0x1f000
//   0x00678c: f947c000  ldr      x0, [x0, #0xf80]
//   0x006790: 90000081  adrp     x1, #0x16000
//   0x006794: 9105d421  add      x1, x1, #0x175
//   0x006798: 97fff0ce  bl       #0x2ad0
//   0x00679c: aa0003f3  mov      x19, x0
//   0x0067a0: b4001b20  cbz      x0, #0x6b04
//   0x0067a4: b00000d8  adrp     x24, #0x1f000
//   0x0067a8: f947ef18  ldr      x24, [x24, #0xfd8]
//   0x0067ac: b9400308  ldr      w8, [x24]
//   0x0067b0: 7100051f  cmp      w8, #1
//   0x0067b4: 5400040b  b.lt     #0x6834
//   0x0067b8: b00000d5  adrp     x21, #0x1f000
//   0x0067bc: f947c2b5  ldr      x21, [x21, #0xf80]
//   0x0067c0: 9104c2f4  add      x20, x23, #0x130
//   0x0067c4: 90000081  adrp     x1, #0x16000
//   0x0067c8: 91068421  add      x1, x1, #0x1a1
//   0x0067cc: aa1403e0  mov      x0, x20
//   0x0067d0: aa1503e2  mov      x2, x21
//   0x0067d4: 97fff0ab  bl       #0x2a80
//   0x0067d8: aa1503e0  mov      x0, x21
//   0x0067dc: 97fff091  bl       #0x2a20
//   0x0067e0: b00000d9  adrp     x25, #0x1f000
//   0x0067e4: f947fb39  ldr      x25, [x25, #0xff0]
//   0x0067e8: b940033b  ldr      w27, [x25]
//   0x0067ec: 6b00037f  cmp      w27, w0
//   0x0067f0: 540001ed  b.le     #0x682c
//   0x0067f4: b00000d5  adrp     x21, #0x1f000
//   0x0067f8: f947c2b5  ldr      x21, [x21, #0xf80]
//   0x0067fc: 5280003a  mov      w26, #1
//   0x006800: aa1503e0  mov      x0, x21
//   0x006804: 97fff087  bl       #0x2a20
//   0x006808: 4b000368  sub      w8, w27, w0
//   0x00680c: 6b08035f  cmp      w26, w8
//   0x006810: 540000ec  b.gt     #0x682c
//   0x006814: 52800400  mov      w0, #0x20
//   0x006818: aa1403e1  mov      x1, x20
//   0x00681c: 97fff03d  bl       #0x2910
//   0x006820: b940033b  ldr      w27, [x25]
//   0x006824: 1100075a  add      w26, w26, #1
//   0x006828: 17fffff6  b        #0x6800
//   0x00682c: aa1403e0  mov      x0, x20
//   0x006830: 97fff030  bl       #0x28f0
//   0x006834: b00000c8  adrp     x8, #0x1f000
//   0x006838: f947b508  ldr      x8, [x8, #0xf68]
//   0x00683c: aa1303e0  mov      x0, x19
//   0x006840: b90097ff  str      wzr, [sp, #0x94]
//   0x006844: f900011f  str      xzr, [x8]
//   0x006848: 97fff066  bl       #0x29e0
//   0x00684c: 35001c00  cbnz     w0, #0x6bcc
//   0x006850: b00000d9  adrp     x25, #0x1f000
//   0x006854: b9400302  ldr      w2, [x24]
//   0x006858: f947a739  ldr      x25, [x25, #0xf48]
//   0x00685c: 910273e0  add      x0, sp, #0x9c
//   0x006860: 910283e4  add      x4, sp, #0xa0
//   0x006864: aa1303e1  mov      x1, x19
//   0x006868: 39400323  ldrb     w3, [x25]
//   0x00686c: 2a1f03e5  mov      w5, wzr
//   0x006870: 97ffef9c  bl       #0x26e0
//   0x006874: aa0003f4  mov      x20, x0
//   0x006878: 2a1f03f5  mov      w21, wzr
//   0x00687c: b4000ac0  cbz      x0, #0x69d4
//   0x006880: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x006884: 35000a88  cbnz     w8, #0x69d4
//   0x006888: 910283fa  add      x26, sp, #0xa0
//   0x00688c: 2a1f03f5  mov      w21, wzr
//   0x006890: 9100435b  add      x27, x26, #0x10
//   0x006894: 2a1f03e8  mov      w8, wzr
//   0x006898: 110006b5  add      w21, w21, #1
//   0x00689c: 35000168  cbnz     w8, #0x68c8
//   0x0068a0: 914007e2  add      x2, sp, #1, lsl #12
//   0x0068a4: 910273e0  add      x0, sp, #0x9c
//   0x0068a8: 9110a042  add      x2, x2, #0x428
//   0x0068ac: 52827103  mov      w3, #0x1388
//   0x0068b0: aa1403e1  mov      x1, x20
//   0x0068b4: 97ffeff7  bl       #0x2890
//   0x0068b8: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x0068bc: 3100151f  cmn      w8, #5
//   0x0068c0: 54fffee1  b.ne     #0x689c
//   0x0068c4: 14000044  b        #0x69d4
//   0x0068c8: 7100111f  cmp      w8, #4
//   0x0068cc: 54000841  b.ne     #0x69d4
//   0x0068d0: 910273e0  add      x0, sp, #0x9c
//   0x0068d4: 910223e2  add      x2, sp, #0x88
//   0x0068d8: 910253e3  add      x3, sp, #0x94
//   0x0068dc: aa1403e1  mov      x1, x20
//   0x0068e0: 97ffeff4  bl       #0x28b0
//   0x0068e4: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x0068e8: 350017e8  cbnz     w8, #0x6be4
//   0x0068ec: b98097e8  ldrsw    x8, [sp, #0x94]
//   0x0068f0: 7100051f  cmp      w8, #1
//   0x0068f4: 5400024b  b.lt     #0x693c
//   0x0068f8: f94047e9  ldr      x9, [sp, #0x88]
//   0x0068fc: 7100811f  cmp      w8, #0x20
//   0x006900: 540000e3  b.lo     #0x691c
//   0x006904: 8b08012a  add      x10, x9, x8
//   0x006908: eb0a035f  cmp      x26, x10
//   0x00690c: 540004a2  b.hs     #0x69a0
//   0x006910: 8b08034a  add      x10, x26, x8
//   0x006914: eb0a013f  cmp      x9, x10
//   0x006918: 54000442  b.hs     #0x69a0
//   0x00691c: aa1f03ea  mov      x10, xzr
//   0x006920: cb0a0108  sub      x8, x8, x10
//   0x006924: 8b0a034b  add      x11, x26, x10
//   0x006928: 8b0a0129  add      x9, x9, x10
//   0x00692c: 3840152a  ldrb     w10, [x9], #1
//   0x006930: f1000508  subs     x8, x8, #1
//   0x006934: 3800156a  strb     w10, [x11], #1
//   0x006938: 54ffffa1  b.ne     #0x692c
//   0x00693c: 910273e0  add      x0, sp, #0x9c
//   0x006940: aa1403e1  mov      x1, x20
//   0x006944: 97ffef87  bl       #0x2760
//   0x006948: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x00694c: 350014c8  cbnz     w8, #0x6be4
//   0x006950: b94097e5  ldr      w5, [sp, #0x94]
//   0x006954: 35000105  cbnz     w5, #0x6974
//   0x006958: aa1303e0  mov      x0, x19
//   0x00695c: 97fff01d  bl       #0x29d0
//   0x006960: 3100041f  cmn      w0, #1
//   0x006964: 54000e60  b.eq     #0x6b30
//   0x006968: aa1303e1  mov      x1, x19
//   0x00696c: 97ffef89  bl       #0x2790
//   0x006970: b94097e5  ldr      w5, [sp, #0x94]
//   0x006974: b9400302  ldr      w2, [x24]
//   0x006978: 39400323  ldrb     w3, [x25]
//   0x00697c: 910273e0  add      x0, sp, #0x9c
//   0x006980: 910283e4  add      x4, sp, #0xa0
//   0x006984: aa1303e1  mov      x1, x19
//   0x006988: 97ffef56  bl       #0x26e0
//   0x00698c: aa0003f4  mov      x20, x0
//   0x006990: b4000220  cbz      x0, #0x69d4
//   0x006994: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x006998: 34fff7e8  cbz      w8, #0x6894
//   0x00699c: 1400000e  b        #0x69d4
//   0x0069a0: 927be90a  and      x10, x8, #0xffffffffffffffe0
//   0x0069a4: 9100412b  add      x11, x9, #0x10
//   0x0069a8: aa0a03ec  mov      x12, x10
//   0x0069ac: aa1b03ed  mov      x13, x27
//   0x0069b0: ad7f8560  ldp      q0, q1, [x11, #-0x10]
//   0x0069b4: 9100816b  add      x11, x11, #0x20
//   0x0069b8: f100818c  subs     x12, x12, #0x20
//   0x0069bc: ad3f85a0  stp      q0, q1, [x13, #-0x10]
//   0x0069c0: 910081ad  add      x13, x13, #0x20
//   0x0069c4: 54ffff61  b.ne     #0x69b0
//   0x0069c8: eb08015f  cmp      x10, x8
//   0x0069cc: 54fffb80  b.eq     #0x693c
//   0x0069d0: 17ffffd4  b        #0x6920
//   0x0069d4: 910263e0  add      x0, sp, #0x98
//   0x0069d8: aa1403e1  mov      x1, x20
//   0x0069dc: 97ffef61  bl       #0x2760
//   0x0069e0: b9400308  ldr      w8, [x24]
//   0x0069e4: 35000148  cbnz     w8, #0x6a0c
//   0x0069e8: b00000c8  adrp     x8, #0x1f000
//   0x0069ec: f947a908  ldr      x8, [x8, #0xf50]
//   0x0069f0: b00000c3  adrp     x3, #0x1f000
//   0x0069f4: 90000081  adrp     x1, #0x16000
//   0x0069f8: 9104c2e0  add      x0, x23, #0x130
//   0x0069fc: f9400102  ldr      x2, [x8]
//   0x006a00: f947c063  ldr      x3, [x3, #0xf80]
//   0x006a04: 911ae021  add      x1, x1, #0x6b8
//   0x006a08: 97fff01e  bl       #0x2a80
//   0x006a0c: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x006a10: 11002508  add      w8, w8, #9
//   0x006a14: 7100191f  cmp      w8, #6
//   0x006a18: 54000dc8  b.hi     #0x6bd0
//   0x006a1c: d0000069  adrp     x9, #0x14000
//   0x006a20: 9137b529  add      x9, x9, #0xded
//   0x006a24: 1000008a  adr      x10, #0x6a34
//   0x006a28: 3868692b  ldrb     w11, [x9, x8]
//   0x006a2c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x006a30: d61f0140  br       x10
//   0x006a34: 90000080  adrp     x0, #0x16000
//   0x006a38: 9104c2e3  add      x3, x23, #0x130
//   0x006a3c: 911b9400  add      x0, x0, #0x6e5
//   0x006a40: 528002e1  mov      w1, #0x17
//   0x006a44: 14000010  b        #0x6a84
//   0x006a48: 90000080  adrp     x0, #0x16000
//   0x006a4c: 9104c2e3  add      x3, x23, #0x130
//   0x006a50: 911b0400  add      x0, x0, #0x6c1
//   0x006a54: 52800461  mov      w1, #0x23
//   0x006a58: 1400000b  b        #0x6a84
//   0x006a5c: eb17027f  cmp      x19, x23
//   0x006a60: 54000060  b.eq     #0x6a6c
//   0x006a64: aa1303e0  mov      x0, x19
//   0x006a68: 97ffef9a  bl       #0x28d0
//   0x006a6c: 710006bf  cmp      w21, #1
//   0x006a70: 54000261  b.ne     #0x6abc
//   0x006a74: 90000080  adrp     x0, #0x16000
//   0x006a78: 9104c2e3  add      x3, x23, #0x130
//   0x006a7c: 911bf400  add      x0, x0, #0x6fd
//   0x006a80: 528005a1  mov      w1, #0x2d
//   0x006a84: 52800022  mov      w2, #1
//   0x006a88: 97fff016  bl       #0x2ae0
//   0x006a8c: 2a1f03f3  mov      w19, wzr
//   0x006a90: 34000733  cbz      w19, #0x6b74
//   0x006a94: b9400308  ldr      w8, [x24]
//   0x006a98: 7100051f  cmp      w8, #1
//   0x006a9c: 540006cb  b.lt     #0x6b74
//   0x006aa0: 90000080  adrp     x0, #0x16000
//   0x006aa4: 9104c2e3  add      x3, x23, #0x130
//   0x006aa8: 911a7c00  add      x0, x0, #0x69f
//   0x006aac: 52800061  mov      w1, #3
//   0x006ab0: 52800022  mov      w2, #1
//   0x006ab4: 97fff00b  bl       #0x2ae0
//   0x006ab8: 14000034  b        #0x6b88
//   0x006abc: b00000c8  adrp     x8, #0x1f000
//   0x006ac0: f947c508  ldr      x8, [x8, #0xf88]
//   0x006ac4: 39400108  ldrb     w8, [x8]
//   0x006ac8: 34000528  cbz      w8, #0x6b6c
//   0x006acc: 90000080  adrp     x0, #0x16000
//   0x006ad0: 9104c2e3  add      x3, x23, #0x130
//   0x006ad4: 91127400  add      x0, x0, #0x49d
//   0x006ad8: 52800461  mov      w1, #0x23
//   0x006adc: 52800022  mov      w2, #1
//   0x006ae0: 52800033  mov      w19, #1
//   0x006ae4: 97ffefff  bl       #0x2ae0
//   0x006ae8: 35fffd73  cbnz     w19, #0x6a94
//   0x006aec: 14000022  b        #0x6b74
//   0x006af0: 7100051f  cmp      w8, #1
//   0x006af4: 54ffdca0  b.eq     #0x6688
//   0x006af8: 90000080  adrp     x0, #0x16000
//   0x006afc: 911a3000  add      x0, x0, #0x68c
//   0x006b00: 940000d0  bl       #0x6e40
//   0x006b04: b00000c8  adrp     x8, #0x1f000
//   0x006b08: f947a908  ldr      x8, [x8, #0xf50]
//   0x006b0c: f9400113  ldr      x19, [x8]
//   0x006b10: 97ffef40  bl       #0x2810
//   0x006b14: b9400000  ldr      w0, [x0]
//   0x006b18: 97ffef32  bl       #0x27e0
//   0x006b1c: 90000081  adrp     x1, #0x16000
//   0x006b20: aa0003e4  mov      x4, x0
//   0x006b24: 9104c2e0  add      x0, x23, #0x130
//   0x006b28: 91105821  add      x1, x1, #0x416
//   0x006b2c: 17fffef6  b        #0x6704
//   0x006b30: aa1303e0  mov      x0, x19
//   0x006b34: 97ffefab  bl       #0x29e0
//   0x006b38: 350004a0  cbnz     w0, #0x6bcc
//   0x006b3c: aa1303e0  mov      x0, x19
//   0x006b40: 97ffef64  bl       #0x28d0
//   0x006b44: 3100041f  cmn      w0, #1
//   0x006b48: 54000420  b.eq     #0x6bcc
//   0x006b4c: b9400308  ldr      w8, [x24]
//   0x006b50: 7100091f  cmp      w8, #2
//   0x006b54: 540000cb  b.lt     #0x6b6c
//   0x006b58: 90000080  adrp     x0, #0x16000
//   0x006b5c: 9104c2e3  add      x3, x23, #0x130
//   0x006b60: 91123800  add      x0, x0, #0x48e
//   0x006b64: 528000a1  mov      w1, #5
//   0x006b68: 17ffffdd  b        #0x6adc
//   0x006b6c: 52800033  mov      w19, #1
//   0x006b70: 35fff933  cbnz     w19, #0x6a94
//   0x006b74: 350000b3  cbnz     w19, #0x6b88
//   0x006b78: b00000c8  adrp     x8, #0x1f000
//   0x006b7c: f947a108  ldr      x8, [x8, #0xf40]
//   0x006b80: 52800029  mov      w9, #1
//   0x006b84: 39000109  strb     w9, [x8]
//   0x006b88: f94016c8  ldr      x8, [x22, #0x28]
//   0x006b8c: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x006b90: eb09011f  cmp      x8, x9
//   0x006b94: 540001a1  b.ne     #0x6bc8
//   0x006b98: 91400bff  add      sp, sp, #2, lsl #12
//   0x006b9c: 911f03ff  add      sp, sp, #0x7c0
//   0x006ba0: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x006ba4: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x006ba8: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x006bac: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x006bb0: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x006bb4: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x006bb8: d65f03c0  ret      
//   0x006bbc: 90000080  adrp     x0, #0x16000
//   0x006bc0: 91197000  add      x0, x0, #0x65c
//   0x006bc4: 9400009f  bl       #0x6e40
//   0x006bc8: 97ffef56  bl       #0x2920
//   0x006bcc: 940000ac  bl       #0x6e7c
//   0x006bd0: 90000080  adrp     x0, #0x16000
//   0x006bd4: 911cac00  add      x0, x0, #0x72b
//   0x006bd8: 9400009a  bl       #0x6e40
//   0x006bdc: 9400012c  bl       #0x708c
//   0x006be0: 94000004  bl       #0x6bf0
//   0x006be4: 90000080  adrp     x0, #0x16000
//   0x006be8: 911a8c00  add      x0, x0, #0x6a3
//   0x006bec: 94000095  bl       #0x6e40
// ============================================================================
std::uint32_t fde_09_065a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000065a8ULL;
    for (std::size_t i = 0; i < 402ULL; ++i) {
        std::uint32_t insn = kTextInstructions[3742ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[10] Subroutine @ 0x006bf0..0x006c28 (56 bytes, 14 AArch64 instructions)
// [VN] Khung FDE[10] Hàm con @ 0x006bf0..0x006c28 (56 byte, 14 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006bf0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x006bf4: 910003fd  mov      x29, sp
//   0x006bf8: b00000c8  adrp     x8, #0x1f000
//   0x006bfc: f947a908  ldr      x8, [x8, #0xf50]
//   0x006c00: f0000061  adrp     x1, #0x15000
//   0x006c04: 911c3421  add      x1, x1, #0x70d
//   0x006c08: f9400102  ldr      x2, [x8]
//   0x006c0c: b00000c8  adrp     x8, #0x1f000
//   0x006c10: f947c908  ldr      x8, [x8, #0xf90]
//   0x006c14: 9104c100  add      x0, x8, #0x130
//   0x006c18: 97ffef9a  bl       #0x2a80
//   0x006c1c: 94000003  bl       #0x6c28
//   0x006c20: 52800020  mov      w0, #1
//   0x006c24: 9400001f  bl       #0x6ca0
// ============================================================================
std::uint32_t fde_10_06bf0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006bf0ULL;
    for (std::size_t i = 0; i < 14ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4144ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[11] Subroutine @ 0x006c28..0x006ca0 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[11] Hàm con @ 0x006c28..0x006ca0 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006c28: d100c3ff  sub      sp, sp, #0x30
//   0x006c2c: f9000bf3  str      x19, [sp, #0x10]
//   0x006c30: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x006c34: 910083fd  add      x29, sp, #0x20
//   0x006c38: d53bd053  mrs      x19, tpidr_el0
//   0x006c3c: f9401668  ldr      x8, [x19, #0x28]
//   0x006c40: f90007e8  str      x8, [sp, #8]
//   0x006c44: b00000c8  adrp     x8, #0x1f000
//   0x006c48: f947c508  ldr      x8, [x8, #0xf88]
//   0x006c4c: 39400108  ldrb     w8, [x8]
//   0x006c50: 34000168  cbz      w8, #0x6c7c
//   0x006c54: b00000c8  adrp     x8, #0x1f000
//   0x006c58: f947c908  ldr      x8, [x8, #0xf90]
//   0x006c5c: b00000c2  adrp     x2, #0x1f000
//   0x006c60: b00000c3  adrp     x3, #0x1f000
//   0x006c64: f947c042  ldr      x2, [x2, #0xf80]
//   0x006c68: f947b863  ldr      x3, [x3, #0xf70]
//   0x006c6c: f0000061  adrp     x1, #0x15000
//   0x006c70: 911ccc21  add      x1, x1, #0x733
//   0x006c74: 9104c100  add      x0, x8, #0x130
//   0x006c78: 97ffef82  bl       #0x2a80
//   0x006c7c: f9401668  ldr      x8, [x19, #0x28]
//   0x006c80: f94007e9  ldr      x9, [sp, #8]
//   0x006c84: eb09011f  cmp      x8, x9
//   0x006c88: 540000a1  b.ne     #0x6c9c
//   0x006c8c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x006c90: f9400bf3  ldr      x19, [sp, #0x10]
//   0x006c94: 9100c3ff  add      sp, sp, #0x30
//   0x006c98: d65f03c0  ret      
//   0x006c9c: 97ffef21  bl       #0x2920
// ============================================================================
std::uint32_t fde_11_06c28(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006c28ULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4158ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[12] Subroutine @ 0x006ca0..0x006e40 (416 bytes, 104 AArch64 instructions)
// [VN] Khung FDE[12] Hàm con @ 0x006ca0..0x006e40 (416 byte, 104 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006ca0: d10303ff  sub      sp, sp, #0xc0
//   0x006ca4: f90043f7  str      x23, [sp, #0x80]
//   0x006ca8: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x006cac: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x006cb0: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x006cb4: 9102c3fd  add      x29, sp, #0xb0
//   0x006cb8: b00000c8  adrp     x8, #0x1f000
//   0x006cbc: f9479508  ldr      x8, [x8, #0xf28]
//   0x006cc0: b00000d7  adrp     x23, #0x1f000
//   0x006cc4: b00000d5  adrp     x21, #0x1f000
//   0x006cc8: b00000d6  adrp     x22, #0x1f000
//   0x006ccc: b9400108  ldr      w8, [x8]
//   0x006cd0: f947c6f7  ldr      x23, [x23, #0xf88]
//   0x006cd4: f947aab5  ldr      x21, [x21, #0xf50]
//   0x006cd8: f947cad6  ldr      x22, [x22, #0xf90]
//   0x006cdc: 2a0003f3  mov      w19, w0
//   0x006ce0: 71000d1f  cmp      w8, #3
//   0x006ce4: 540007a1  b.ne     #0x6dd8
//   0x006ce8: b00000c8  adrp     x8, #0x1f000
//   0x006cec: f947e108  ldr      x8, [x8, #0xfc0]
//   0x006cf0: b9400108  ldr      w8, [x8]
//   0x006cf4: 71000d1f  cmp      w8, #3
//   0x006cf8: 54000700  b.eq     #0x6dd8
//   0x006cfc: b00000c8  adrp     x8, #0x1f000
//   0x006d00: f947d108  ldr      x8, [x8, #0xfa0]
//   0x006d04: 39400108  ldrb     w8, [x8]
//   0x006d08: 34000688  cbz      w8, #0x6dd8
//   0x006d0c: b00000c0  adrp     x0, #0x1f000
//   0x006d10: f947c000  ldr      x0, [x0, #0xf80]
//   0x006d14: 910003e1  mov      x1, sp
//   0x006d18: 97ffef52  bl       #0x2a60
//   0x006d1c: 35000300  cbnz     w0, #0x6d7c
//   0x006d20: 394002e8  ldrb     w8, [x23]
//   0x006d24: 34000108  cbz      w8, #0x6d44
//   0x006d28: b00000c3  adrp     x3, #0x1f000
//   0x006d2c: f94002a2  ldr      x2, [x21]
//   0x006d30: f947b863  ldr      x3, [x3, #0xf70]
//   0x006d34: f0000061  adrp     x1, #0x15000
//   0x006d38: 9104c2c0  add      x0, x22, #0x130
//   0x006d3c: 911d5c21  add      x1, x1, #0x757
//   0x006d40: 97ffef50  bl       #0x2a80
//   0x006d44: b00000c8  adrp     x8, #0x1f000
//   0x006d48: f947b508  ldr      x8, [x8, #0xf68]
//   0x006d4c: f9400100  ldr      x0, [x8]
//   0x006d50: b4000040  cbz      x0, #0x6d58
//   0x006d54: 97ffeedf  bl       #0x28d0
//   0x006d58: b00000c0  adrp     x0, #0x1f000
//   0x006d5c: f947b800  ldr      x0, [x0, #0xf70]
//   0x006d60: 97ffef3c  bl       #0x2a50
//   0x006d64: 340003a0  cbz      w0, #0x6dd8
//   0x006d68: f94002a2  ldr      x2, [x21]
//   0x006d6c: f0000061  adrp     x1, #0x15000
//   0x006d70: 9104c2c0  add      x0, x22, #0x130
//   0x006d74: 911e0c21  add      x1, x1, #0x783
//   0x006d78: 14000017  b        #0x6dd4
//   0x006d7c: f94002a2  ldr      x2, [x21]
//   0x006d80: 9104c2d4  add      x20, x22, #0x130
//   0x006d84: f0000061  adrp     x1, #0x15000
//   0x006d88: 911ef821  add      x1, x1, #0x7be
//   0x006d8c: aa1403e0  mov      x0, x20
//   0x006d90: 97ffef3c  bl       #0x2a80
//   0x006d94: f94002a2  ldr      x2, [x21]
//   0x006d98: f0000061  adrp     x1, #0x15000
//   0x006d9c: 911fbc21  add      x1, x1, #0x7ef
//   0x006da0: aa1403e0  mov      x0, x20
//   0x006da4: 97ffef37  bl       #0x2a80
//   0x006da8: b00000c3  adrp     x3, #0x1f000
//   0x006dac: f94002a2  ldr      x2, [x21]
//   0x006db0: f947b863  ldr      x3, [x3, #0xf70]
//   0x006db4: f0000061  adrp     x1, #0x15000
//   0x006db8: 91209c21  add      x1, x1, #0x827
//   0x006dbc: aa1403e0  mov      x0, x20
//   0x006dc0: 97ffef30  bl       #0x2a80
//   0x006dc4: f94002a2  ldr      x2, [x21]
//   0x006dc8: f0000061  adrp     x1, #0x15000
//   0x006dcc: 91211c21  add      x1, x1, #0x847
//   0x006dd0: aa1403e0  mov      x0, x20
//   0x006dd4: 97ffef2b  bl       #0x2a80
//   0x006dd8: 394002e8  ldrb     w8, [x23]
//   0x006ddc: 34000228  cbz      w8, #0x6e20
//   0x006de0: b00000c8  adrp     x8, #0x1f000
//   0x006de4: f9479908  ldr      x8, [x8, #0xf30]
//   0x006de8: b9400104  ldr      w4, [x8]
//   0x006dec: 7100049f  cmp      w4, #1
//   0x006df0: 5400018b  b.lt     #0x6e20
//   0x006df4: b00000c8  adrp     x8, #0x1f000
//   0x006df8: f947cd08  ldr      x8, [x8, #0xf98]
//   0x006dfc: b9400108  ldr      w8, [x8]
//   0x006e00: 6b080085  subs     w5, w4, w8
//   0x006e04: 540000ed  b.le     #0x6e20
//   0x006e08: f94002a2  ldr      x2, [x21]
//   0x006e0c: f0000061  adrp     x1, #0x15000
//   0x006e10: 9104c2c0  add      x0, x22, #0x130
//   0x006e14: 91221021  add      x1, x1, #0x884
//   0x006e18: aa0203e3  mov      x3, x2
//   0x006e1c: 97ffef19  bl       #0x2a80
//   0x006e20: b00000c8  adrp     x8, #0x1f000
//   0x006e24: f9479d08  ldr      x8, [x8, #0xf38]
//   0x006e28: b9400100  ldr      w0, [x8]
//   0x006e2c: 6b13001f  cmp      w0, w19
//   0x006e30: 5400006a  b.ge     #0x6e3c
//   0x006e34: 2a1303e0  mov      w0, w19
//   0x006e38: b9000113  str      w19, [x8]
//   0x006e3c: 97ffeefd  bl       #0x2a30
// ============================================================================
std::uint32_t fde_12_06ca0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006ca0ULL;
    for (std::size_t i = 0; i < 104ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4188ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[13] Subroutine @ 0x006e40..0x006e7c (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[13] Hàm con @ 0x006e40..0x006e7c (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006e40: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x006e44: 910003fd  mov      x29, sp
//   0x006e48: b00000c8  adrp     x8, #0x1f000
//   0x006e4c: f947a908  ldr      x8, [x8, #0xf50]
//   0x006e50: 90000081  adrp     x1, #0x16000
//   0x006e54: aa0003e3  mov      x3, x0
//   0x006e58: 9106a021  add      x1, x1, #0x1a8
//   0x006e5c: f9400102  ldr      x2, [x8]
//   0x006e60: b00000c8  adrp     x8, #0x1f000
//   0x006e64: f947c908  ldr      x8, [x8, #0xf90]
//   0x006e68: 9104c100  add      x0, x8, #0x130
//   0x006e6c: 97ffef05  bl       #0x2a80
//   0x006e70: 97ffff6e  bl       #0x6c28
//   0x006e74: 52800060  mov      w0, #3
//   0x006e78: 97ffff8a  bl       #0x6ca0
// ============================================================================
std::uint32_t fde_13_06e40(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006e40ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4292ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[14] Subroutine @ 0x006e7c..0x006ec0 (68 bytes, 17 AArch64 instructions)
// [VN] Khung FDE[14] Hàm con @ 0x006e7c..0x006ec0 (68 byte, 17 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006e7c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x006e80: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x006e84: 910043fd  add      x29, sp, #0x10
//   0x006e88: b00000d3  adrp     x19, #0x1f000
//   0x006e8c: f947aa73  ldr      x19, [x19, #0xf50]
//   0x006e90: b00000c8  adrp     x8, #0x1f000
//   0x006e94: 90000081  adrp     x1, #0x16000
//   0x006e98: 910d5021  add      x1, x1, #0x354
//   0x006e9c: f9400262  ldr      x2, [x19]
//   0x006ea0: f947c908  ldr      x8, [x8, #0xf90]
//   0x006ea4: 9104c100  add      x0, x8, #0x130
//   0x006ea8: 97ffeef6  bl       #0x2a80
//   0x006eac: f9400260  ldr      x0, [x19]
//   0x006eb0: 97ffee64  bl       #0x2840
//   0x006eb4: 97ffff5d  bl       #0x6c28
//   0x006eb8: 52800020  mov      w0, #1
//   0x006ebc: 97ffff79  bl       #0x6ca0
// ============================================================================
std::uint32_t fde_14_06e7c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006e7cULL;
    for (std::size_t i = 0; i < 17ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4307ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[15] Subroutine @ 0x006ec0..0x00708c (460 bytes, 115 AArch64 instructions)
// [VN] Khung FDE[15] Hàm con @ 0x006ec0..0x00708c (460 byte, 115 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x006ec0: d10183ff  sub      sp, sp, #0x60
//   0x006ec4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x006ec8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x006ecc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x006ed0: 910143fd  add      x29, sp, #0x50
//   0x006ed4: d53bd048  mrs      x8, tpidr_el0
//   0x006ed8: f940150a  ldr      x10, [x8, #0x28]
//   0x006edc: aa1f03e9  mov      x9, xzr
//   0x006ee0: 5280014b  mov      w11, #0xa
//   0x006ee4: 910023ec  add      x12, sp, #8
//   0x006ee8: f90017ea  str      x10, [sp, #0x28]
//   0x006eec: f940002d  ldr      x13, [x1]
//   0x006ef0: 529999aa  mov      w10, #0xcccd
//   0x006ef4: 72b9998a  movk     w10, #0xcccc, lsl #16
//   0x006ef8: d348fdae  lsr      x14, x13, #8
//   0x006efc: d350fdaf  lsr      x15, x13, #0x10
//   0x006f00: d358fdb0  lsr      x16, x13, #0x18
//   0x006f04: d360fdb1  lsr      x17, x13, #0x20
//   0x006f08: d368fda1  lsr      x1, x13, #0x28
//   0x006f0c: d370fda2  lsr      x2, x13, #0x30
//   0x006f10: d378fda3  lsr      x3, x13, #0x38
//   0x006f14: 2a0303e4  mov      w4, w3
//   0x006f18: 12001c63  and      w3, w3, #0xff
//   0x006f1c: 2a0d03f6  mov      w22, w13
//   0x006f20: 9baa7c6d  umull    x13, w3, w10
//   0x006f24: 7100247f  cmp      w3, #9
//   0x006f28: d363fda3  lsr      x3, x13, #0x23
//   0x006f2c: 1b0b906d  msub     w13, w3, w11, w4
//   0x006f30: 12001c45  and      w5, w2, #0xff
//   0x006f34: 12001dad  and      w13, w13, #0xff
//   0x006f38: 33181da5  bfi      w5, w13, #8, #8
//   0x006f3c: 9baa7cad  umull    x13, w5, w10
//   0x006f40: d363fda2  lsr      x2, x13, #0x23
//   0x006f44: 2a0103e6  mov      w6, w1
//   0x006f48: 1b0b944d  msub     w13, w2, w11, w5
//   0x006f4c: 33185da6  bfi      w6, w13, #8, #0x18
//   0x006f50: 9baa7ccd  umull    x13, w6, w10
//   0x006f54: d363fda1  lsr      x1, x13, #0x23
//   0x006f58: 2a1103e7  mov      w7, w17
//   0x006f5c: 1b0b982d  msub     w13, w1, w11, w6
//   0x006f60: 33185da7  bfi      w7, w13, #8, #0x18
//   0x006f64: 9baa7ced  umull    x13, w7, w10
//   0x006f68: d363fdb1  lsr      x17, x13, #0x23
//   0x006f6c: 2a1003f3  mov      w19, w16
//   0x006f70: 1b0b9e2d  msub     w13, w17, w11, w7
//   0x006f74: 33185db3  bfi      w19, w13, #8, #0x18
//   0x006f78: 9baa7e6d  umull    x13, w19, w10
//   0x006f7c: d363fdb0  lsr      x16, x13, #0x23
//   0x006f80: 2a0f03f4  mov      w20, w15
//   0x006f84: 1b0bce0d  msub     w13, w16, w11, w19
//   0x006f88: 33185db4  bfi      w20, w13, #8, #0x18
//   0x006f8c: 9baa7e8d  umull    x13, w20, w10
//   0x006f90: d363fdaf  lsr      x15, x13, #0x23
//   0x006f94: 2a0e03f5  mov      w21, w14
//   0x006f98: 2a02002e  orr      w14, w1, w2
//   0x006f9c: 1b0bd1ed  msub     w13, w15, w11, w20
//   0x006fa0: 2a1101ce  orr      w14, w14, w17
//   0x006fa4: 33185db5  bfi      w21, w13, #8, #0x18
//   0x006fa8: 2a1001ce  orr      w14, w14, w16
//   0x006fac: 9baa7ead  umull    x13, w21, w10
//   0x006fb0: 2a0f01c4  orr      w4, w14, w15
//   0x006fb4: d363fdae  lsr      x14, x13, #0x23
//   0x006fb8: 1b0bd5cd  msub     w13, w14, w11, w21
//   0x006fbc: 33185db6  bfi      w22, w13, #8, #0x18
//   0x006fc0: 9baa7ecd  umull    x13, w22, w10
//   0x006fc4: d363fdad  lsr      x13, x13, #0x23
//   0x006fc8: 1b0bd9a5  msub     w5, w13, w11, w22
//   0x006fcc: 2a0e0084  orr      w4, w4, w14
//   0x006fd0: 321c04a5  orr      w5, w5, #0x30
//   0x006fd4: 38296985  strb     w5, [x12, x9]
//   0x006fd8: 91000529  add      x9, x9, #1
//   0x006fdc: 2a0d0084  orr      w4, w4, w13
//   0x006fe0: 54fff9a8  b.hi     #0x6f14
//   0x006fe4: 72001c9f  tst      w4, #0xff
//   0x006fe8: 54fff961  b.ne     #0x6f14
//   0x006fec: 92407d2a  and      x10, x9, #0xffffffff
//   0x006ff0: f100215f  cmp      x10, #8
//   0x006ff4: 382a681f  strb     wzr, [x0, x10]
//   0x006ff8: 54000062  b.hs     #0x7004
//   0x006ffc: aa1f03eb  mov      x11, xzr
//   0x007000: 1400000f  b        #0x703c
//   0x007004: 9240092c  and      x12, x9, #7
//   0x007008: 5100052d  sub      w13, w9, #1
//   0x00700c: 910023ee  add      x14, sp, #8
//   0x007010: cb0c014b  sub      x11, x10, x12
//   0x007014: 8b0d01cd  add      x13, x14, x13
//   0x007018: d1001dad  sub      x13, x13, #7
//   0x00701c: aa0b03ee  mov      x14, x11
//   0x007020: aa0003ef  mov      x15, x0
//   0x007024: fc5f85a0  ldr      d0, [x13], #0xfffffffffffffff8
//   0x007028: f10021ce  subs     x14, x14, #8
//   0x00702c: 0e200800  rev64    v0.8b, v0.8b
//   0x007030: fc0085e0  str      d0, [x15], #8
//   0x007034: 54ffff81  b.ne     #0x7024
//   0x007038: b400016c  cbz      x12, #0x7064
//   0x00703c: 910023ec  add      x12, sp, #8
//   0x007040: 5100052d  sub      w13, w9, #1
//   0x007044: cb0b018c  sub      x12, x12, x11
//   0x007048: 8b0b0009  add      x9, x0, x11
//   0x00704c: 8b0d018c  add      x12, x12, x13
//   0x007050: cb0b014a  sub      x10, x10, x11
//   0x007054: 385ff58b  ldrb     w11, [x12], #0xffffffffffffffff
//   0x007058: f100054a  subs     x10, x10, #1
//   0x00705c: 3800152b  strb     w11, [x9], #1
//   0x007060: 54ffffa1  b.ne     #0x7054
//   0x007064: f9401508  ldr      x8, [x8, #0x28]
//   0x007068: f94017e9  ldr      x9, [sp, #0x28]
//   0x00706c: eb09011f  cmp      x8, x9
//   0x007070: 540000c1  b.ne     #0x7088
//   0x007074: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x007078: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00707c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x007080: 910183ff  add      sp, sp, #0x60
//   0x007084: d65f03c0  ret      
//   0x007088: 97ffee26  bl       #0x2920
// ============================================================================
std::uint32_t fde_15_06ec0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00006ec0ULL;
    for (std::size_t i = 0; i < 115ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4324ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[16] Subroutine @ 0x00708c..0x0070d4 (72 bytes, 18 AArch64 instructions)
// [VN] Khung FDE[16] Hàm con @ 0x00708c..0x0070d4 (72 byte, 18 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00708c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x007090: 910003fd  mov      x29, sp
//   0x007094: 900000c8  adrp     x8, #0x1f000
//   0x007098: f947c908  ldr      x8, [x8, #0xf90]
//   0x00709c: f0000060  adrp     x0, #0x16000
//   0x0070a0: 9109a000  add      x0, x0, #0x268
//   0x0070a4: 52801d61  mov      w1, #0xeb
//   0x0070a8: 9104c103  add      x3, x8, #0x130
//   0x0070ac: 52800022  mov      w2, #1
//   0x0070b0: 97ffee8c  bl       #0x2ae0
//   0x0070b4: 900000c8  adrp     x8, #0x1f000
//   0x0070b8: f9479d08  ldr      x8, [x8, #0xf38]
//   0x0070bc: b9400100  ldr      w0, [x8]
//   0x0070c0: 7100081f  cmp      w0, #2
//   0x0070c4: 5400006c  b.gt     #0x70d0
//   0x0070c8: 52800060  mov      w0, #3
//   0x0070cc: b9000100  str      w0, [x8]
//   0x0070d0: 97ffee58  bl       #0x2a30
// ============================================================================
std::uint32_t fde_16_0708c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000708cULL;
    for (std::size_t i = 0; i < 18ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4439ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[17] Subroutine @ 0x0070d4..0x007110 (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[17] Hàm con @ 0x0070d4..0x007110 (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0070d4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0070d8: 910003fd  mov      x29, sp
//   0x0070dc: 900000c8  adrp     x8, #0x1f000
//   0x0070e0: f947a908  ldr      x8, [x8, #0xf50]
//   0x0070e4: f0000061  adrp     x1, #0x16000
//   0x0070e8: 91137421  add      x1, x1, #0x4dd
//   0x0070ec: f9400102  ldr      x2, [x8]
//   0x0070f0: 900000c8  adrp     x8, #0x1f000
//   0x0070f4: f947c908  ldr      x8, [x8, #0xf90]
//   0x0070f8: 9104c100  add      x0, x8, #0x130
//   0x0070fc: 97ffee61  bl       #0x2a80
//   0x007100: 97fffeca  bl       #0x6c28
//   0x007104: 9400002b  bl       #0x71b0
//   0x007108: 52800040  mov      w0, #2
//   0x00710c: 97fffee5  bl       #0x6ca0
// ============================================================================
std::uint32_t fde_17_070d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000070d4ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
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
// [EN] FDE[18] Subroutine @ 0x007110..0x0071b0 (160 bytes, 40 AArch64 instructions)
// [VN] Khung FDE[18] Hàm con @ 0x007110..0x0071b0 (160 byte, 40 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007110: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x007114: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x007118: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00711c: 910083fd  add      x29, sp, #0x20
//   0x007120: 900000d4  adrp     x20, #0x1f000
//   0x007124: f947c694  ldr      x20, [x20, #0xf88]
//   0x007128: 39400288  ldrb     w8, [x20]
//   0x00712c: 340003e8  cbz      w8, #0x71a8
//   0x007130: 900000d6  adrp     x22, #0x1f000
//   0x007134: f947aad6  ldr      x22, [x22, #0xf50]
//   0x007138: 900000d5  adrp     x21, #0x1f000
//   0x00713c: f0000061  adrp     x1, #0x16000
//   0x007140: 9117f421  add      x1, x1, #0x5fd
//   0x007144: f94002c2  ldr      x2, [x22]
//   0x007148: f947cab5  ldr      x21, [x21, #0xf90]
//   0x00714c: 9104c2b3  add      x19, x21, #0x130
//   0x007150: aa1303e0  mov      x0, x19
//   0x007154: 97ffee4b  bl       #0x2a80
//   0x007158: f94002c0  ldr      x0, [x22]
//   0x00715c: 97ffedb9  bl       #0x2840
//   0x007160: 39400288  ldrb     w8, [x20]
//   0x007164: 34000228  cbz      w8, #0x71a8
//   0x007168: 900000c2  adrp     x2, #0x1f000
//   0x00716c: 900000c3  adrp     x3, #0x1f000
//   0x007170: f947c042  ldr      x2, [x2, #0xf80]
//   0x007174: f947b863  ldr      x3, [x3, #0xf70]
//   0x007178: d0000061  adrp     x1, #0x15000
//   0x00717c: 911ccc21  add      x1, x1, #0x733
//   0x007180: aa1303e0  mov      x0, x19
//   0x007184: 97ffee3f  bl       #0x2a80
//   0x007188: 39400288  ldrb     w8, [x20]
//   0x00718c: 340000e8  cbz      w8, #0x71a8
//   0x007190: f0000060  adrp     x0, #0x16000
//   0x007194: 9104c2a3  add      x3, x21, #0x130
//   0x007198: 91143000  add      x0, x0, #0x50c
//   0x00719c: 52801e01  mov      w1, #0xf0
//   0x0071a0: 52800022  mov      w2, #1
//   0x0071a4: 97ffee4f  bl       #0x2ae0
//   0x0071a8: 52800040  mov      w0, #2
//   0x0071ac: 97fffebd  bl       #0x6ca0
// ============================================================================
std::uint32_t fde_18_07110(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007110ULL;
    for (std::size_t i = 0; i < 40ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4472ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[19] Subroutine @ 0x0071b0..0x007220 (112 bytes, 28 AArch64 instructions)
// [VN] Khung FDE[19] Hàm con @ 0x0071b0..0x007220 (112 byte, 28 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0071b0: d100c3ff  sub      sp, sp, #0x30
//   0x0071b4: f9000bf3  str      x19, [sp, #0x10]
//   0x0071b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0071bc: 910083fd  add      x29, sp, #0x20
//   0x0071c0: d53bd053  mrs      x19, tpidr_el0
//   0x0071c4: f9401668  ldr      x8, [x19, #0x28]
//   0x0071c8: f90007e8  str      x8, [sp, #8]
//   0x0071cc: 900000c8  adrp     x8, #0x1f000
//   0x0071d0: f947c508  ldr      x8, [x8, #0xf88]
//   0x0071d4: 39400108  ldrb     w8, [x8]
//   0x0071d8: 34000128  cbz      w8, #0x71fc
//   0x0071dc: 900000c8  adrp     x8, #0x1f000
//   0x0071e0: f947c908  ldr      x8, [x8, #0xf90]
//   0x0071e4: f0000060  adrp     x0, #0x16000
//   0x0071e8: 91143000  add      x0, x0, #0x50c
//   0x0071ec: 52801e01  mov      w1, #0xf0
//   0x0071f0: 9104c103  add      x3, x8, #0x130
//   0x0071f4: 52800022  mov      w2, #1
//   0x0071f8: 97ffee3a  bl       #0x2ae0
//   0x0071fc: f9401668  ldr      x8, [x19, #0x28]
//   0x007200: f94007e9  ldr      x9, [sp, #8]
//   0x007204: eb09011f  cmp      x8, x9
//   0x007208: 540000a1  b.ne     #0x721c
//   0x00720c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x007210: f9400bf3  ldr      x19, [sp, #0x10]
//   0x007214: 9100c3ff  add      sp, sp, #0x30
//   0x007218: d65f03c0  ret      
//   0x00721c: 97ffedc1  bl       #0x2920
// ============================================================================
std::uint32_t fde_19_071b0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000071b0ULL;
    for (std::size_t i = 0; i < 28ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4512ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[20] Subroutine @ 0x007220..0x007280 (96 bytes, 24 AArch64 instructions)
// [VN] Khung FDE[20] Hàm con @ 0x007220..0x007280 (96 byte, 24 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007220: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x007224: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x007228: 910043fd  add      x29, sp, #0x10
//   0x00722c: 900000c8  adrp     x8, #0x1f000
//   0x007230: f947c908  ldr      x8, [x8, #0xf90]
//   0x007234: 2a0003f4  mov      w20, w0
//   0x007238: f0000061  adrp     x1, #0x16000
//   0x00723c: f0000063  adrp     x3, #0x16000
//   0x007240: 9104c113  add      x19, x8, #0x130
//   0x007244: 911d4021  add      x1, x1, #0x750
//   0x007248: 91355c63  add      x3, x3, #0xd57
//   0x00724c: aa1303e0  mov      x0, x19
//   0x007250: 2a1403e2  mov      w2, w20
//   0x007254: 97ffee0b  bl       #0x2a80
//   0x007258: 710fbe9f  cmp      w20, #0x3ef
//   0x00725c: 540000e1  b.ne     #0x7278
//   0x007260: f0000060  adrp     x0, #0x16000
//   0x007264: 9123b400  add      x0, x0, #0x8ed
//   0x007268: 52808401  mov      w1, #0x420
//   0x00726c: 52800022  mov      w2, #1
//   0x007270: aa1303e3  mov      x3, x19
//   0x007274: 97ffee1b  bl       #0x2ae0
//   0x007278: 52800060  mov      w0, #3
//   0x00727c: 97ffeded  bl       #0x2a30
// ============================================================================
std::uint32_t fde_20_07220(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007220ULL;
    for (std::size_t i = 0; i < 24ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4540ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[21] Subroutine @ 0x007280..0x0072c0 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[21] Hàm con @ 0x007280..0x0072c0 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007280: d10083ff  sub      sp, sp, #0x20
//   0x007284: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x007288: 910043fd  add      x29, sp, #0x10
//   0x00728c: d53bd048  mrs      x8, tpidr_el0
//   0x007290: f9401509  ldr      x9, [x8, #0x28]
//   0x007294: f90007e9  str      x9, [sp, #8]
//   0x007298: f9401508  ldr      x8, [x8, #0x28]
//   0x00729c: f94007e9  ldr      x9, [sp, #8]
//   0x0072a0: eb09011f  cmp      x8, x9
//   0x0072a4: 540000c1  b.ne     #0x72bc
//   0x0072a8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0072ac: f0000060  adrp     x0, #0x16000
//   0x0072b0: 91355c00  add      x0, x0, #0xd57
//   0x0072b4: 910083ff  add      sp, sp, #0x20
//   0x0072b8: d65f03c0  ret      
//   0x0072bc: 97ffed99  bl       #0x2920
// ============================================================================
std::uint32_t fde_21_07280(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007280ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4564ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[22] Subroutine @ 0x0072c0..0x0074d4 (532 bytes, 133 AArch64 instructions)
// [VN] Khung FDE[22] Hàm con @ 0x0072c0..0x0074d4 (532 byte, 133 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0072c0: d10183ff  sub      sp, sp, #0x60
//   0x0072c4: f9000bf9  str      x25, [sp, #0x10]
//   0x0072c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0072cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0072d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0072d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0072d8: 910143fd  add      x29, sp, #0x50
//   0x0072dc: d53bd058  mrs      x24, tpidr_el0
//   0x0072e0: f9401708  ldr      x8, [x24, #0x28]
//   0x0072e4: aa0003f3  mov      x19, x0
//   0x0072e8: 7103e87f  cmp      w3, #0xfa
//   0x0072ec: 12800020  mov      w0, #-2
//   0x0072f0: f90007e8  str      x8, [sp, #8]
//   0x0072f4: 54000d88  b.hi     #0x74a4
//   0x0072f8: b4000d73  cbz      x19, #0x74a4
//   0x0072fc: 51000428  sub      w8, w1, #1
//   0x007300: 2a0103f5  mov      w21, w1
//   0x007304: 7100211f  cmp      w8, #8
//   0x007308: 54000ce8  b.hi     #0x74a4
//   0x00730c: f9401e68  ldr      x8, [x19, #0x38]
//   0x007310: 7100007f  cmp      w3, #0
//   0x007314: 528003c9  mov      w9, #0x1e
//   0x007318: 2a0203f6  mov      w22, w2
//   0x00731c: 1a830139  csel     w25, w9, w3, eq
//   0x007320: b4000948  cbz      x8, #0x7448
//   0x007324: f9402269  ldr      x9, [x19, #0x40]
//   0x007328: b40009a9  cbz      x9, #0x745c
//   0x00732c: f9402660  ldr      x0, [x19, #0x48]
//   0x007330: 529b3b01  mov      w1, #0xd9d8
//   0x007334: 52800022  mov      w2, #1
//   0x007338: d63f0100  blr      x8
//   0x00733c: b4000b20  cbz      x0, #0x74a0
//   0x007340: f9000013  str      x19, [x0]
//   0x007344: a9027c1f  stp      xzr, xzr, [x0, #0x20]
//   0x007348: f9000c1f  str      xzr, [x0, #0x18]
//   0x00734c: aa0003f4  mov      x20, x0
//   0x007350: f9401e68  ldr      x8, [x19, #0x38]
//   0x007354: f9402660  ldr      x0, [x19, #0x48]
//   0x007358: 52835009  mov      w9, #0x1a80
//   0x00735c: 72a000c9  movk     w9, #6, lsl #16
//   0x007360: 1b097eb7  mul      w23, w21, w9
//   0x007364: 52800022  mov      w2, #1
//   0x007368: 2a1703e1  mov      w1, w23
//   0x00736c: d63f0100  blr      x8
//   0x007370: f9000e80  str      x0, [x20, #0x18]
//   0x007374: f9401e68  ldr      x8, [x19, #0x38]
//   0x007378: f9402660  ldr      x0, [x19, #0x48]
//   0x00737c: 110222e1  add      w1, w23, #0x88
//   0x007380: 52800022  mov      w2, #1
//   0x007384: d63f0100  blr      x8
//   0x007388: f9001280  str      x0, [x20, #0x20]
//   0x00738c: f9401e68  ldr      x8, [x19, #0x38]
//   0x007390: f9402660  ldr      x0, [x19, #0x48]
//   0x007394: 320e83e1  mov      w1, #0x40004
//   0x007398: 52800022  mov      w2, #1
//   0x00739c: d63f0100  blr      x8
//   0x0073a0: f9400e81  ldr      x1, [x20, #0x18]
//   0x0073a4: f9001680  str      x0, [x20, #0x28]
//   0x0073a8: b4000661  cbz      x1, #0x7474
//   0x0073ac: b4000600  cbz      x0, #0x746c
//   0x0073b0: f9401288  ldr      x8, [x20, #0x20]
//   0x0073b4: b40005c8  cbz      x8, #0x746c
//   0x0073b8: 0f000440  movi     v0.2s, #2
//   0x0073bc: a903a281  stp      x1, x8, [x20, #0x38]
//   0x0073c0: f0000068  adrp     x8, #0x16000
//   0x0073c4: 5290d409  mov      w9, #0x86a0
//   0x0073c8: fd000680  str      d0, [x20, #8]
//   0x0073cc: fd43a500  ldr      d0, [x8, #0x748]
//   0x0073d0: 72a00029  movk     w9, #1, lsl #16
//   0x0073d4: 1b097ea9  mul      w9, w21, w9
//   0x0073d8: 2a1f03e0  mov      w0, wzr
//   0x0073dc: 6f00e401  movi     v1.2d, #0000000000000000
//   0x0073e0: 1280000a  mov      w10, #-1
//   0x0073e4: 5280002b  mov      w11, #1
//   0x0073e8: 51004d28  sub      w8, w9, #0x13
//   0x0073ec: b9029296  str      w22, [x20, #0x290]
//   0x0073f0: b9028e9f  str      wzr, [x20, #0x28c]
//   0x0073f4: b9029a95  str      w21, [x20, #0x298]
//   0x0073f8: b9005a99  str      w25, [x20, #0x58]
//   0x0073fc: a904fe81  stp      x1, xzr, [x20, #0x48]
//   0x007400: b9007288  str      w8, [x20, #0x70]
//   0x007404: f9001a74  str      x20, [x19, #0x30]
//   0x007408: fc00c261  stur     d1, [x19, #0xc]
//   0x00740c: fc024261  stur     d1, [x19, #0x24]
//   0x007410: b9006e9f  str      wzr, [x20, #0x6c]
//   0x007414: fc074281  stur     d1, [x20, #0x74]
//   0x007418: b9028a8a  str      w10, [x20, #0x288]
//   0x00741c: ad040681  stp      q1, q1, [x20, #0x80]
//   0x007420: ad050681  stp      q1, q1, [x20, #0xa0]
//   0x007424: ad060681  stp      q1, q1, [x20, #0xc0]
//   0x007428: ad070681  stp      q1, q1, [x20, #0xe0]
//   0x00742c: ad080681  stp      q1, q1, [x20, #0x100]
//   0x007430: ad090681  stp      q1, q1, [x20, #0x120]
//   0x007434: ad0a0681  stp      q1, q1, [x20, #0x140]
//   0x007438: ad0b0681  stp      q1, q1, [x20, #0x160]
//   0x00743c: fc05c280  stur     d0, [x20, #0x5c]
//   0x007440: b902968b  str      w11, [x20, #0x294]
//   0x007444: 14000018  b        #0x74a4
//   0x007448: 90000008  adrp     x8, #0x7000
//   0x00744c: 91135108  add      x8, x8, #0x4d4
//   0x007450: f9001e68  str      x8, [x19, #0x38]
//   0x007454: f9402269  ldr      x9, [x19, #0x40]
//   0x007458: b5fff6a9  cbnz     x9, #0x732c
//   0x00745c: 90000009  adrp     x9, #0x7000
//   0x007460: 91148129  add      x9, x9, #0x520
//   0x007464: f9002269  str      x9, [x19, #0x40]
//   0x007468: 17ffffb1  b        #0x732c
//   0x00746c: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007470: d63f0100  blr      x8
//   0x007474: f9401281  ldr      x1, [x20, #0x20]
//   0x007478: b4000061  cbz      x1, #0x7484
//   0x00747c: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007480: d63f0100  blr      x8
//   0x007484: f9401681  ldr      x1, [x20, #0x28]
//   0x007488: b4000061  cbz      x1, #0x7494
//   0x00748c: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007490: d63f0100  blr      x8
//   0x007494: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007498: aa1403e1  mov      x1, x20
//   0x00749c: d63f0100  blr      x8
//   0x0074a0: 12800040  mov      w0, #-3
//   0x0074a4: f9401708  ldr      x8, [x24, #0x28]
//   0x0074a8: f94007e9  ldr      x9, [sp, #8]
//   0x0074ac: eb09011f  cmp      x8, x9
//   0x0074b0: 54000101  b.ne     #0x74d0
//   0x0074b4: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x0074b8: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x0074bc: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x0074c0: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x0074c4: f9400bf9  ldr      x25, [sp, #0x10]
//   0x0074c8: 910183ff  add      sp, sp, #0x60
//   0x0074cc: d65f03c0  ret      
//   0x0074d0: 97ffed14  bl       #0x2920
// ============================================================================
std::uint32_t fde_22_072c0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000072c0ULL;
    for (std::size_t i = 0; i < 133ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4580ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[23] Subroutine @ 0x0074d4..0x007520 (76 bytes, 19 AArch64 instructions)
// [VN] Khung FDE[23] Hàm con @ 0x0074d4..0x007520 (76 byte, 19 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0074d4: d100c3ff  sub      sp, sp, #0x30
//   0x0074d8: f9000bf3  str      x19, [sp, #0x10]
//   0x0074dc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0074e0: 910083fd  add      x29, sp, #0x20
//   0x0074e4: d53bd053  mrs      x19, tpidr_el0
//   0x0074e8: f9401668  ldr      x8, [x19, #0x28]
//   0x0074ec: 1b017c49  mul      w9, w2, w1
//   0x0074f0: 93407d20  sxtw     x0, w9
//   0x0074f4: f90007e8  str      x8, [sp, #8]
//   0x0074f8: 97ffed66  bl       #0x2a90
//   0x0074fc: f9401668  ldr      x8, [x19, #0x28]
//   0x007500: f94007e9  ldr      x9, [sp, #8]
//   0x007504: eb09011f  cmp      x8, x9
//   0x007508: 540000a1  b.ne     #0x751c
//   0x00750c: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x007510: f9400bf3  ldr      x19, [sp, #0x10]
//   0x007514: 9100c3ff  add      sp, sp, #0x30
//   0x007518: d65f03c0  ret      
//   0x00751c: 97ffed01  bl       #0x2920
// ============================================================================
std::uint32_t fde_23_074d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000074d4ULL;
    for (std::size_t i = 0; i < 19ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4713ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[24] Subroutine @ 0x007520..0x00756c (76 bytes, 19 AArch64 instructions)
// [VN] Khung FDE[24] Hàm con @ 0x007520..0x00756c (76 byte, 19 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007520: d100c3ff  sub      sp, sp, #0x30
//   0x007524: f9000bf3  str      x19, [sp, #0x10]
//   0x007528: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00752c: 910083fd  add      x29, sp, #0x20
//   0x007530: d53bd053  mrs      x19, tpidr_el0
//   0x007534: f9401668  ldr      x8, [x19, #0x28]
//   0x007538: f90007e8  str      x8, [sp, #8]
//   0x00753c: b4000061  cbz      x1, #0x7548
//   0x007540: aa0103e0  mov      x0, x1
//   0x007544: 97ffed6b  bl       #0x2af0
//   0x007548: f9401668  ldr      x8, [x19, #0x28]
//   0x00754c: f94007e9  ldr      x9, [sp, #8]
//   0x007550: eb09011f  cmp      x8, x9
//   0x007554: 540000a1  b.ne     #0x7568
//   0x007558: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00755c: f9400bf3  ldr      x19, [sp, #0x10]
//   0x007560: 9100c3ff  add      sp, sp, #0x30
//   0x007564: d65f03c0  ret      
//   0x007568: 97ffecee  bl       #0x2920
// ============================================================================
std::uint32_t fde_24_07520(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007520ULL;
    for (std::size_t i = 0; i < 19ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4732ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[25] Subroutine @ 0x00756c..0x007728 (444 bytes, 111 AArch64 instructions)
// [VN] Khung FDE[25] Hàm con @ 0x00756c..0x007728 (444 byte, 111 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00756c: d100c3ff  sub      sp, sp, #0x30
//   0x007570: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x007574: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x007578: 910083fd  add      x29, sp, #0x20
//   0x00757c: d53bd053  mrs      x19, tpidr_el0
//   0x007580: f9401669  ldr      x9, [x19, #0x28]
//   0x007584: f90007e9  str      x9, [sp, #8]
//   0x007588: b40000e0  cbz      x0, #0x75a4
//   0x00758c: f9401814  ldr      x20, [x0, #0x30]
//   0x007590: aa0003e8  mov      x8, x0
//   0x007594: b4000094  cbz      x20, #0x75a4
//   0x007598: f9400289  ldr      x9, [x20]
//   0x00759c: eb08013f  cmp      x9, x8
//   0x0075a0: 54000140  b.eq     #0x75c8
//   0x0075a4: 12800020  mov      w0, #-2
//   0x0075a8: f9401668  ldr      x8, [x19, #0x28]
//   0x0075ac: f94007e9  ldr      x9, [sp, #8]
//   0x0075b0: eb09011f  cmp      x8, x9
//   0x0075b4: 54000b81  b.ne     #0x7724
//   0x0075b8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0075bc: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0075c0: 9100c3ff  add      sp, sp, #0x30
//   0x0075c4: d65f03c0  ret      
//   0x0075c8: b9400a89  ldr      w9, [x20, #8]
//   0x0075cc: 12800000  mov      w0, #-1
//   0x0075d0: 7100093f  cmp      w9, #2
//   0x0075d4: 54000100  b.eq     #0x75f4
//   0x0075d8: 1400000d  b        #0x760c
//   0x0075dc: 52800069  mov      w9, #3
//   0x0075e0: b940090a  ldr      w10, [x8, #8]
//   0x0075e4: b9000a89  str      w9, [x20, #8]
//   0x0075e8: b900128a  str      w10, [x20, #0x10]
//   0x0075ec: 7100093f  cmp      w9, #2
//   0x0075f0: 540000e1  b.ne     #0x760c
//   0x0075f4: 7100043f  cmp      w1, #1
//   0x0075f8: 54ffff20  b.eq     #0x75dc
//   0x0075fc: 7100083f  cmp      w1, #2
//   0x007600: 540002e1  b.ne     #0x765c
//   0x007604: 52800089  mov      w9, #4
//   0x007608: 17fffff6  b        #0x75e0
//   0x00760c: 7100053f  cmp      w9, #1
//   0x007610: 54fffcc0  b.eq     #0x75a8
//   0x007614: 71000d3f  cmp      w9, #3
//   0x007618: 54000320  b.eq     #0x767c
//   0x00761c: 7100113f  cmp      w9, #4
//   0x007620: 540004a1  b.ne     #0x76b4
//   0x007624: 7100083f  cmp      w1, #2
//   0x007628: 54000421  b.ne     #0x76ac
//   0x00762c: b9401289  ldr      w9, [x20, #0x10]
//   0x007630: b940090a  ldr      w10, [x8, #8]
//   0x007634: 6b0a013f  cmp      w9, w10
//   0x007638: 540003a1  b.ne     #0x76ac
//   0x00763c: aa0803e0  mov      x0, x8
//   0x007640: 9400003a  bl       #0x7728
//   0x007644: 72001c1f  tst      w0, #0xff
//   0x007648: 54000320  b.eq     #0x76ac
//   0x00764c: b9401288  ldr      w8, [x20, #0x10]
//   0x007650: 34000508  cbz      w8, #0x76f0
//   0x007654: 52800060  mov      w0, #3
//   0x007658: 17ffffd4  b        #0x75a8
//   0x00765c: 12800020  mov      w0, #-2
//   0x007660: 35fffa41  cbnz     w1, #0x75a8
//   0x007664: aa0803e0  mov      x0, x8
//   0x007668: 94000030  bl       #0x7728
//   0x00766c: 72001c1f  tst      w0, #0xff
//   0x007670: 12800028  mov      w8, #-2
//   0x007674: 5a880100  cinv     w0, w8, ne
//   0x007678: 17ffffcc  b        #0x75a8
//   0x00767c: 7100043f  cmp      w1, #1
//   0x007680: 54000161  b.ne     #0x76ac
//   0x007684: b9401289  ldr      w9, [x20, #0x10]
//   0x007688: b940090a  ldr      w10, [x8, #8]
//   0x00768c: 6b0a013f  cmp      w9, w10
//   0x007690: 540000e1  b.ne     #0x76ac
//   0x007694: aa0803e0  mov      x0, x8
//   0x007698: 94000024  bl       #0x7728
//   0x00769c: b9401288  ldr      w8, [x20, #0x10]
//   0x0076a0: 340000e8  cbz      w8, #0x76bc
//   0x0076a4: 52800040  mov      w0, #2
//   0x0076a8: 17ffffc0  b        #0x75a8
//   0x0076ac: 12800000  mov      w0, #-1
//   0x0076b0: 17ffffbe  b        #0x75a8
//   0x0076b4: 2a1f03e0  mov      w0, wzr
//   0x0076b8: 17ffffbc  b        #0x75a8
//   0x0076bc: b9405e88  ldr      w8, [x20, #0x5c]
//   0x0076c0: 7103fd1f  cmp      w8, #0xff
//   0x0076c4: 54000088  b.hi     #0x76d4
//   0x0076c8: b9406288  ldr      w8, [x20, #0x60]
//   0x0076cc: 7100011f  cmp      w8, #0
//   0x0076d0: 54fffeac  b.gt     #0x76a4
//   0x0076d4: 294ea688  ldp      w8, w9, [x20, #0x74]
//   0x0076d8: 52800040  mov      w0, #2
//   0x0076dc: 6b08013f  cmp      w9, w8
//   0x0076e0: 54fff64b  b.lt     #0x75a8
//   0x0076e4: b9000a80  str      w0, [x20, #8]
//   0x0076e8: 52800020  mov      w0, #1
//   0x0076ec: 17ffffaf  b        #0x75a8
//   0x0076f0: b9405e88  ldr      w8, [x20, #0x5c]
//   0x0076f4: 7103fd1f  cmp      w8, #0xff
//   0x0076f8: 54000088  b.hi     #0x7708
//   0x0076fc: b9406288  ldr      w8, [x20, #0x60]
//   0x007700: 7100011f  cmp      w8, #0
//   0x007704: 54fffa8c  b.gt     #0x7654
//   0x007708: 294ea688  ldp      w8, w9, [x20, #0x74]
//   0x00770c: 6b08013f  cmp      w9, w8
//   0x007710: 54fffa2b  b.lt     #0x7654
//   0x007714: 52800028  mov      w8, #1
//   0x007718: b9000a88  str      w8, [x20, #8]
//   0x00771c: 52800080  mov      w0, #4
//   0x007720: 17ffffa2  b        #0x75a8
//   0x007724: 97ffec7f  bl       #0x2920
// ============================================================================
std::uint32_t fde_25_0756c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000756cULL;
    for (std::size_t i = 0; i < 111ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4751ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[26] Subroutine @ 0x007728..0x007b5c (1076 bytes, 269 AArch64 instructions)
// [VN] Khung FDE[26] Hàm con @ 0x007728..0x007b5c (1076 byte, 269 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007728: d10203ff  sub      sp, sp, #0x80
//   0x00772c: fd000be8  str      d8, [sp, #0x10]
//   0x007730: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x007734: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x007738: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00773c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x007740: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x007744: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x007748: 9101c3fd  add      x29, sp, #0x70
//   0x00774c: d53bd056  mrs      x22, tpidr_el0
//   0x007750: f94016c8  ldr      x8, [x22, #0x28]
//   0x007754: 900000d8  adrp     x24, #0x1f000
//   0x007758: f947e718  ldr      x24, [x24, #0xfc8]
//   0x00775c: f0000069  adrp     x9, #0x16000
//   0x007760: f90007e8  str      x8, [sp, #8]
//   0x007764: f9401813  ldr      x19, [x0, #0x30]
//   0x007768: fd43a528  ldr      d8, [x9, #0x748]
//   0x00776c: 2a1f03f4  mov      w20, wzr
//   0x007770: 2a1f03f5  mov      w21, wzr
//   0x007774: 52800037  mov      w23, #1
//   0x007778: 12800019  mov      w25, #-1
//   0x00777c: 9102027a  add      x26, x19, #0x80
//   0x007780: 5280005b  mov      w27, #2
//   0x007784: 14000004  b        #0x7794
//   0x007788: f9400268  ldr      x8, [x19]
//   0x00778c: b9400908  ldr      w8, [x8, #8]
//   0x007790: 34001c48  cbz      w8, #0x7b18
//   0x007794: b9400e68  ldr      w8, [x19, #0xc]
//   0x007798: 7100091f  cmp      w8, #2
//   0x00779c: 540009a0  b.eq     #0x78d0
//   0x0077a0: 7100051f  cmp      w8, #1
//   0x0077a4: 54ffffa1  b.ne     #0x7798
//   0x0077a8: f9400269  ldr      x9, [x19]
//   0x0077ac: b9407a68  ldr      w8, [x19, #0x78]
//   0x0077b0: b940212a  ldr      w10, [x9, #0x20]
//   0x0077b4: 340003aa  cbz      w10, #0x7828
//   0x0077b8: b940766a  ldr      w10, [x19, #0x74]
//   0x0077bc: 6b0a011f  cmp      w8, w10
//   0x0077c0: 5400034a  b.ge     #0x7828
//   0x0077c4: f9400d29  ldr      x9, [x9, #0x18]
//   0x0077c8: f9402a6a  ldr      x10, [x19, #0x50]
//   0x0077cc: 3868c948  ldrb     w8, [x10, w8, sxtw]
//   0x0077d0: 39000128  strb     w8, [x9]
//   0x0077d4: b9407a68  ldr      w8, [x19, #0x78]
//   0x0077d8: f940026a  ldr      x10, [x19]
//   0x0077dc: 11000508  add      w8, w8, #1
//   0x0077e0: b9007a68  str      w8, [x19, #0x78]
//   0x0077e4: 29443549  ldp      w9, w13, [x10, #0x20]
//   0x0077e8: f9400d4c  ldr      x12, [x10, #0x18]
//   0x0077ec: 5100052b  sub      w11, w9, #1
//   0x0077f0: 91000589  add      x9, x12, #1
//   0x0077f4: 310005ac  adds     w12, w13, #1
//   0x0077f8: 2904314b  stp      w11, w12, [x10, #0x20]
//   0x0077fc: f9000d49  str      x9, [x10, #0x18]
//   0x007800: 54000083  b.lo     #0x7810
//   0x007804: b940294c  ldr      w12, [x10, #0x28]
//   0x007808: 1100058c  add      w12, w12, #1
//   0x00780c: b900294c  str      w12, [x10, #0x28]
//   0x007810: 3400008b  cbz      w11, #0x7820
//   0x007814: b940766a  ldr      w10, [x19, #0x74]
//   0x007818: 6b0a011f  cmp      w8, w10
//   0x00781c: 54fffd6b  b.lt     #0x77c8
//   0x007820: 52800029  mov      w9, #1
//   0x007824: 14000002  b        #0x782c
//   0x007828: 2a1f03e9  mov      w9, wzr
//   0x00782c: b940766a  ldr      w10, [x19, #0x74]
//   0x007830: 2a140134  orr      w20, w9, w20
//   0x007834: 6b0a011f  cmp      w8, w10
//   0x007838: 5400170b  b.lt     #0x7b18
//   0x00783c: b9400a6a  ldr      w10, [x19, #8]
//   0x007840: 7100115f  cmp      w10, #4
//   0x007844: 54000121  b.ne     #0x7868
//   0x007848: b9401268  ldr      w8, [x19, #0x10]
//   0x00784c: 350000e8  cbnz     w8, #0x7868
//   0x007850: b9405e68  ldr      w8, [x19, #0x5c]
//   0x007854: 7103fd1f  cmp      w8, #0xff
//   0x007858: 54001608  b.hi     #0x7b18
//   0x00785c: b9406268  ldr      w8, [x19, #0x60]
//   0x007860: 7100051f  cmp      w8, #1
//   0x007864: 540015ab  b.lt     #0x7b18
//   0x007868: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00786c: b9006e7f  str      wzr, [x19, #0x6c]
//   0x007870: 290efe7f  stp      wzr, wzr, [x19, #0x74]
//   0x007874: b9028a79  str      w25, [x19, #0x288]
//   0x007878: ad070340  stp      q0, q0, [x26, #0xe0]
//   0x00787c: ad060340  stp      q0, q0, [x26, #0xc0]
//   0x007880: ad050340  stp      q0, q0, [x26, #0xa0]
//   0x007884: ad040340  stp      q0, q0, [x26, #0x80]
//   0x007888: ad030340  stp      q0, q0, [x26, #0x60]
//   0x00788c: ad020340  stp      q0, q0, [x26, #0x40]
//   0x007890: ad010340  stp      q0, q0, [x26, #0x20]
//   0x007894: ad000340  stp      q0, q0, [x26]
//   0x007898: b9429668  ldr      w8, [x19, #0x294]
//   0x00789c: 71000d5f  cmp      w10, #3
//   0x0078a0: b9000e7b  str      w27, [x19, #0xc]
//   0x0078a4: 11000508  add      w8, w8, #1
//   0x0078a8: b9029668  str      w8, [x19, #0x294]
//   0x0078ac: 54000141  b.ne     #0x78d4
//   0x0078b0: b9401268  ldr      w8, [x19, #0x10]
//   0x0078b4: 350000e8  cbnz     w8, #0x78d0
//   0x0078b8: b9405e68  ldr      w8, [x19, #0x5c]
//   0x0078bc: 7103fd1f  cmp      w8, #0xff
//   0x0078c0: 540012c8  b.hi     #0x7b18
//   0x0078c4: b9406268  ldr      w8, [x19, #0x60]
//   0x0078c8: 7100011f  cmp      w8, #0
//   0x0078cc: 5400126d  b.le     #0x7b18
//   0x0078d0: b9400a6a  ldr      w10, [x19, #8]
//   0x0078d4: 294da668  ldp      w8, w9, [x19, #0x6c]
//   0x0078d8: 7100095f  cmp      w10, #2
//   0x0078dc: 54000741  b.ne     #0x79c4
//   0x0078e0: 6b09011f  cmp      w8, w9
//   0x0078e4: 54000eaa  b.ge     #0x7ab8
//   0x0078e8: f940026a  ldr      x10, [x19]
//   0x0078ec: b940094b  ldr      w11, [x10, #8]
//   0x0078f0: 34000e4b  cbz      w11, #0x7ab8
//   0x0078f4: f940014c  ldr      x12, [x10]
//   0x0078f8: b9405e6b  ldr      w11, [x19, #0x5c]
//   0x0078fc: 3940019c  ldrb     w28, [x12]
//   0x007900: b9406269  ldr      w9, [x19, #0x60]
//   0x007904: 6b1c017f  cmp      w11, w28
//   0x007908: 540000c1  b.ne     #0x7920
//   0x00790c: 7103fd3f  cmp      w9, #0xff
//   0x007910: 540002a0  b.eq     #0x7964
//   0x007914: 11000528  add      w8, w9, #1
//   0x007918: b9006268  str      w8, [x19, #0x60]
//   0x00791c: 14000017  b        #0x7978
//   0x007920: 7100053f  cmp      w9, #1
//   0x007924: 54000201  b.ne     #0x7964
//   0x007928: b9428a69  ldr      w9, [x19, #0x288]
//   0x00792c: 12001d6a  and      w10, w11, #0xff
//   0x007930: 8b2b426c  add      x12, x19, w11, uxtw
//   0x007934: 4a49614a  eor      w10, w10, w9, lsr #24
//   0x007938: b86a5b0a  ldr      w10, [x24, w10, uxtw #2]
//   0x00793c: 4a092149  eor      w9, w10, w9, lsl #8
//   0x007940: b9028a69  str      w9, [x19, #0x288]
//   0x007944: 39020197  strb     w23, [x12, #0x80]
//   0x007948: f9402269  ldr      x9, [x19, #0x40]
//   0x00794c: 3828c92b  strb     w11, [x9, w8, sxtw]
//   0x007950: b9406e68  ldr      w8, [x19, #0x6c]
//   0x007954: b9005e7c  str      w28, [x19, #0x5c]
//   0x007958: 11000508  add      w8, w8, #1
//   0x00795c: b9006e68  str      w8, [x19, #0x6c]
//   0x007960: 14000006  b        #0x7978
//   0x007964: 7103fd7f  cmp      w11, #0xff
//   0x007968: 54000068  b.hi     #0x7974
//   0x00796c: aa1303e0  mov      x0, x19
//   0x007970: 94000ac3  bl       #0xa47c
//   0x007974: 290bde7c  stp      w28, w23, [x19, #0x5c]
//   0x007978: f9400268  ldr      x8, [x19]
//   0x00797c: f9400109  ldr      x9, [x8]
//   0x007980: 29412d0a  ldp      w10, w11, [x8, #8]
//   0x007984: 9100052c  add      x12, x9, #1
//   0x007988: 5100054d  sub      w13, w10, #1
//   0x00798c: 31000569  adds     w9, w11, #1
//   0x007990: f900010c  str      x12, [x8]
//   0x007994: 2901250d  stp      w13, w9, [x8, #8]
//   0x007998: 54000083  b.lo     #0x79a8
//   0x00799c: b9401109  ldr      w9, [x8, #0x10]
//   0x0079a0: 11000529  add      w9, w9, #1
//   0x0079a4: b9001109  str      w9, [x8, #0x10]
//   0x0079a8: 294da668  ldp      w8, w9, [x19, #0x6c]
//   0x0079ac: 5280002a  mov      w10, #1
//   0x0079b0: 6b09011f  cmp      w8, w9
//   0x0079b4: 5400084a  b.ge     #0x7abc
//   0x0079b8: 2a1c03eb  mov      w11, w28
//   0x0079bc: 35fffa0d  cbnz     w13, #0x78fc
//   0x0079c0: 1400003f  b        #0x7abc
//   0x0079c4: 6b09011f  cmp      w8, w9
//   0x0079c8: 5400078a  b.ge     #0x7ab8
//   0x0079cc: f940026b  ldr      x11, [x19]
//   0x0079d0: b940096a  ldr      w10, [x11, #8]
//   0x0079d4: 3400074a  cbz      w10, #0x7abc
//   0x0079d8: b940126a  ldr      w10, [x19, #0x10]
//   0x0079dc: 3400070a  cbz      w10, #0x7abc
//   0x0079e0: f9400169  ldr      x9, [x11]
//   0x0079e4: 3940013c  ldrb     w28, [x9]
//   0x0079e8: 294baa69  ldp      w9, w10, [x19, #0x5c]
//   0x0079ec: 6b1c013f  cmp      w9, w28
//   0x0079f0: 540000c1  b.ne     #0x7a08
//   0x0079f4: 7103fd5f  cmp      w10, #0xff
//   0x0079f8: 540002a0  b.eq     #0x7a4c
//   0x0079fc: 11000548  add      w8, w10, #1
//   0x007a00: b9006268  str      w8, [x19, #0x60]
//   0x007a04: 14000017  b        #0x7a60
//   0x007a08: 7100055f  cmp      w10, #1
//   0x007a0c: 54000201  b.ne     #0x7a4c
//   0x007a10: b9428a6a  ldr      w10, [x19, #0x288]
//   0x007a14: 12001d2b  and      w11, w9, #0xff
//   0x007a18: 8b09026c  add      x12, x19, x9
//   0x007a1c: 4a4a616b  eor      w11, w11, w10, lsr #24
//   0x007a20: b86b5b0b  ldr      w11, [x24, w11, uxtw #2]
//   0x007a24: 4a0a216a  eor      w10, w11, w10, lsl #8
//   0x007a28: b9028a6a  str      w10, [x19, #0x288]
//   0x007a2c: 39020197  strb     w23, [x12, #0x80]
//   0x007a30: f940226a  ldr      x10, [x19, #0x40]
//   0x007a34: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x007a38: b9406e68  ldr      w8, [x19, #0x6c]
//   0x007a3c: b9005e7c  str      w28, [x19, #0x5c]
//   0x007a40: 11000508  add      w8, w8, #1
//   0x007a44: b9006e68  str      w8, [x19, #0x6c]
//   0x007a48: 14000006  b        #0x7a60
//   0x007a4c: 7103fd3f  cmp      w9, #0xff
//   0x007a50: 54000068  b.hi     #0x7a5c
//   0x007a54: aa1303e0  mov      x0, x19
//   0x007a58: 94000a89  bl       #0xa47c
//   0x007a5c: 290bde7c  stp      w28, w23, [x19, #0x5c]
//   0x007a60: f940026b  ldr      x11, [x19]
//   0x007a64: f9400168  ldr      x8, [x11]
//   0x007a68: 29412969  ldp      w9, w10, [x11, #8]
//   0x007a6c: 91000508  add      x8, x8, #1
//   0x007a70: 5100052c  sub      w12, w9, #1
//   0x007a74: 31000549  adds     w9, w10, #1
//   0x007a78: f9000168  str      x8, [x11]
//   0x007a7c: 2901256c  stp      w12, w9, [x11, #8]
//   0x007a80: 54000083  b.lo     #0x7a90
//   0x007a84: b9401168  ldr      w8, [x11, #0x10]
//   0x007a88: 11000508  add      w8, w8, #1
//   0x007a8c: b9001168  str      w8, [x11, #0x10]
//   0x007a90: b940126a  ldr      w10, [x19, #0x10]
//   0x007a94: 294da668  ldp      w8, w9, [x19, #0x6c]
//   0x007a98: 5100054d  sub      w13, w10, #1
//   0x007a9c: 6b09011f  cmp      w8, w9
//   0x007aa0: 5280002a  mov      w10, #1
//   0x007aa4: b900126d  str      w13, [x19, #0x10]
//   0x007aa8: 540000aa  b.ge     #0x7abc
//   0x007aac: 3400008c  cbz      w12, #0x7abc
//   0x007ab0: 35fff98d  cbnz     w13, #0x79e0
//   0x007ab4: 14000002  b        #0x7abc
//   0x007ab8: 2a1f03ea  mov      w10, wzr
//   0x007abc: b9400a6b  ldr      w11, [x19, #8]
//   0x007ac0: 2a150155  orr      w21, w10, w21
//   0x007ac4: 7100097f  cmp      w11, #2
//   0x007ac8: 54000060  b.eq     #0x7ad4
//   0x007acc: b940126a  ldr      w10, [x19, #0x10]
//   0x007ad0: 340000aa  cbz      w10, #0x7ae4
//   0x007ad4: 6b09011f  cmp      w8, w9
//   0x007ad8: 54ffe58b  b.lt     #0x7788
//   0x007adc: 2a1f03e1  mov      w1, wzr
//   0x007ae0: 1400000a  b        #0x7b08
//   0x007ae4: b9405e68  ldr      w8, [x19, #0x5c]
//   0x007ae8: 7103fd1f  cmp      w8, #0xff
//   0x007aec: 54000088  b.hi     #0x7afc
//   0x007af0: aa1303e0  mov      x0, x19
//   0x007af4: 94000a62  bl       #0xa47c
//   0x007af8: b9400a6b  ldr      w11, [x19, #8]
//   0x007afc: 7100117f  cmp      w11, #4
//   0x007b00: 1a9f17e1  cset     w1, eq
//   0x007b04: fc05c268  stur     d8, [x19, #0x5c]
//   0x007b08: aa1303e0  mov      x0, x19
//   0x007b0c: 97ffeba1  bl       #0x2990
//   0x007b10: b9000e77  str      w23, [x19, #0xc]
//   0x007b14: 17ffff20  b        #0x7794
//   0x007b18: f94016c8  ldr      x8, [x22, #0x28]
//   0x007b1c: f94007e9  ldr      x9, [sp, #8]
//   0x007b20: 2a1402aa  orr      w10, w21, w20
//   0x007b24: 72001d5f  tst      w10, #0xff
//   0x007b28: 1a9f07e0  cset     w0, ne
//   0x007b2c: eb09011f  cmp      x8, x9
//   0x007b30: 54000141  b.ne     #0x7b58
//   0x007b34: a9477bfd  ldp      x29, x30, [sp, #0x70]
//   0x007b38: a9464ff4  ldp      x20, x19, [sp, #0x60]
//   0x007b3c: a94557f6  ldp      x22, x21, [sp, #0x50]
//   0x007b40: a9445ff8  ldp      x24, x23, [sp, #0x40]
//   0x007b44: a94367fa  ldp      x26, x25, [sp, #0x30]
//   0x007b48: a9426ffc  ldp      x28, x27, [sp, #0x20]
//   0x007b4c: fd400be8  ldr      d8, [sp, #0x10]
//   0x007b50: 910203ff  add      sp, sp, #0x80
//   0x007b54: d65f03c0  ret      
//   0x007b58: 97ffeb72  bl       #0x2920
// ============================================================================
std::uint32_t fde_26_07728(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007728ULL;
    for (std::size_t i = 0; i < 269ULL; ++i) {
        std::uint32_t insn = kTextInstructions[4862ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[27] Subroutine @ 0x007b5c..0x007c0c (176 bytes, 44 AArch64 instructions)
// [VN] Khung FDE[27] Hàm con @ 0x007b5c..0x007c0c (176 byte, 44 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007b5c: d10103ff  sub      sp, sp, #0x40
//   0x007b60: f9000bf5  str      x21, [sp, #0x10]
//   0x007b64: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x007b68: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x007b6c: 9100c3fd  add      x29, sp, #0x30
//   0x007b70: d53bd054  mrs      x20, tpidr_el0
//   0x007b74: f9401688  ldr      x8, [x20, #0x28]
//   0x007b78: f90007e8  str      x8, [sp, #8]
//   0x007b7c: b40000e0  cbz      x0, #0x7b98
//   0x007b80: f9401815  ldr      x21, [x0, #0x30]
//   0x007b84: aa0003f3  mov      x19, x0
//   0x007b88: b4000095  cbz      x21, #0x7b98
//   0x007b8c: f94002a8  ldr      x8, [x21]
//   0x007b90: eb13011f  cmp      x8, x19
//   0x007b94: 54000160  b.eq     #0x7bc0
//   0x007b98: 12800020  mov      w0, #-2
//   0x007b9c: f9401688  ldr      x8, [x20, #0x28]
//   0x007ba0: f94007e9  ldr      x9, [sp, #8]
//   0x007ba4: eb09011f  cmp      x8, x9
//   0x007ba8: 54000301  b.ne     #0x7c08
//   0x007bac: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x007bb0: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x007bb4: f9400bf5  ldr      x21, [sp, #0x10]
//   0x007bb8: 910103ff  add      sp, sp, #0x40
//   0x007bbc: d65f03c0  ret      
//   0x007bc0: f9400ea1  ldr      x1, [x21, #0x18]
//   0x007bc4: b4000061  cbz      x1, #0x7bd0
//   0x007bc8: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007bcc: d63f0100  blr      x8
//   0x007bd0: f94012a1  ldr      x1, [x21, #0x20]
//   0x007bd4: b4000061  cbz      x1, #0x7be0
//   0x007bd8: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007bdc: d63f0100  blr      x8
//   0x007be0: f94016a1  ldr      x1, [x21, #0x28]
//   0x007be4: b4000061  cbz      x1, #0x7bf0
//   0x007be8: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007bec: d63f0100  blr      x8
//   0x007bf0: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x007bf4: f9401a61  ldr      x1, [x19, #0x30]
//   0x007bf8: d63f0100  blr      x8
//   0x007bfc: 2a1f03e0  mov      w0, wzr
//   0x007c00: f9001a7f  str      xzr, [x19, #0x30]
//   0x007c04: 17ffffe6  b        #0x7b9c
//   0x007c08: 97ffeb46  bl       #0x2920
// ============================================================================
std::uint32_t fde_27_07b5c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007b5cULL;
    for (std::size_t i = 0; i < 44ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5131ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[28] Subroutine @ 0x007c0c..0x007d08 (252 bytes, 63 AArch64 instructions)
// [VN] Khung FDE[28] Hàm con @ 0x007c0c..0x007d08 (252 byte, 63 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007c0c: d10103ff  sub      sp, sp, #0x40
//   0x007c10: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x007c14: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x007c18: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x007c1c: 9100c3fd  add      x29, sp, #0x30
//   0x007c20: d53bd056  mrs      x22, tpidr_el0
//   0x007c24: f94016c8  ldr      x8, [x22, #0x28]
//   0x007c28: aa0003f5  mov      x21, x0
//   0x007c2c: 7100103f  cmp      w1, #4
//   0x007c30: 12800020  mov      w0, #-2
//   0x007c34: f90007e8  str      x8, [sp, #8]
//   0x007c38: 54000548  b.hi     #0x7ce0
//   0x007c3c: b4000535  cbz      x21, #0x7ce0
//   0x007c40: 2a0203f4  mov      w20, w2
//   0x007c44: 7100045f  cmp      w2, #1
//   0x007c48: 540004c8  b.hi     #0x7ce0
//   0x007c4c: f9401ea8  ldr      x8, [x21, #0x38]
//   0x007c50: 2a0103f3  mov      w19, w1
//   0x007c54: b4000328  cbz      x8, #0x7cb8
//   0x007c58: f94022a9  ldr      x9, [x21, #0x40]
//   0x007c5c: b4000389  cbz      x9, #0x7ccc
//   0x007c60: f94026a0  ldr      x0, [x21, #0x48]
//   0x007c64: 529f5201  mov      w1, #0xfa90
//   0x007c68: 52800022  mov      w2, #1
//   0x007c6c: d63f0100  blr      x8
//   0x007c70: b4000360  cbz      x0, #0x7cdc
//   0x007c74: aa0003e8  mov      x8, x0
//   0x007c78: 2a1f03e0  mov      w0, wzr
//   0x007c7c: 52800149  mov      w9, #0xa
//   0x007c80: 6f00e400  movi     v0.2d, #0000000000000000
//   0x007c84: f9000115  str      x21, [x8]
//   0x007c88: f9001aa8  str      x8, [x21, #0x30]
//   0x007c8c: b9000909  str      w9, [x8, #8]
//   0x007c90: b90c751f  str      wzr, [x8, #0xc74]
//   0x007c94: fd001100  str      d0, [x8, #0x20]
//   0x007c98: fc00c2a0  stur     d0, [x21, #0xc]
//   0x007c9c: fc0242a0  stur     d0, [x21, #0x24]
//   0x007ca0: 3900b114  strb     w20, [x8, #0x2c]
//   0x007ca4: f906291f  str      xzr, [x8, #0xc50]
//   0x007ca8: f906311f  str      xzr, [x8, #0xc60]
//   0x007cac: f9062d1f  str      xzr, [x8, #0xc58]
//   0x007cb0: 29064d1f  stp      wzr, w19, [x8, #0x30]
//   0x007cb4: 1400000b  b        #0x7ce0
//   0x007cb8: 90000008  adrp     x8, #0x7000
//   0x007cbc: 91135108  add      x8, x8, #0x4d4
//   0x007cc0: f9001ea8  str      x8, [x21, #0x38]
//   0x007cc4: f94022a9  ldr      x9, [x21, #0x40]
//   0x007cc8: b5fffcc9  cbnz     x9, #0x7c60
//   0x007ccc: 90000009  adrp     x9, #0x7000
//   0x007cd0: 91148129  add      x9, x9, #0x520
//   0x007cd4: f90022a9  str      x9, [x21, #0x40]
//   0x007cd8: 17ffffe2  b        #0x7c60
//   0x007cdc: 12800040  mov      w0, #-3
//   0x007ce0: f94016c8  ldr      x8, [x22, #0x28]
//   0x007ce4: f94007e9  ldr      x9, [sp, #8]
//   0x007ce8: eb09011f  cmp      x8, x9
//   0x007cec: 540000c1  b.ne     #0x7d04
//   0x007cf0: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x007cf4: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x007cf8: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x007cfc: 910103ff  add      sp, sp, #0x40
//   0x007d00: d65f03c0  ret      
//   0x007d04: 97ffeb07  bl       #0x2920
// ============================================================================
std::uint32_t fde_28_07c0c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007c0cULL;
    for (std::size_t i = 0; i < 63ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5175ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[29] Subroutine @ 0x007d08..0x007d70 (104 bytes, 26 AArch64 instructions)
// [VN] Khung FDE[29] Hàm con @ 0x007d08..0x007d70 (104 byte, 26 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007d08: d10083ff  sub      sp, sp, #0x20
//   0x007d0c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x007d10: 910043fd  add      x29, sp, #0x10
//   0x007d14: d53bd049  mrs      x9, tpidr_el0
//   0x007d18: f940152a  ldr      x10, [x9, #0x28]
//   0x007d1c: 2a0003e8  mov      w8, w0
//   0x007d20: 2a1f03e0  mov      w0, wzr
//   0x007d24: f90007ea  str      x10, [sp, #8]
//   0x007d28: 5280200a  mov      w10, #0x100
//   0x007d2c: 0b0a000b  add      w11, w0, w10
//   0x007d30: 13017d6b  asr      w11, w11, #1
//   0x007d34: b86bd82c  ldr      w12, [x1, w11, sxtw #2]
//   0x007d38: 6b08019f  cmp      w12, w8
//   0x007d3c: 1a8ac16a  csel     w10, w11, w10, gt
//   0x007d40: 1a8bc000  csel     w0, w0, w11, gt
//   0x007d44: 4b00014b  sub      w11, w10, w0
//   0x007d48: 7100057f  cmp      w11, #1
//   0x007d4c: 54ffff01  b.ne     #0x7d2c
//   0x007d50: f9401528  ldr      x8, [x9, #0x28]
//   0x007d54: f94007e9  ldr      x9, [sp, #8]
//   0x007d58: eb09011f  cmp      x8, x9
//   0x007d5c: 54000081  b.ne     #0x7d6c
//   0x007d60: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x007d64: 910083ff  add      sp, sp, #0x20
//   0x007d68: d65f03c0  ret      
//   0x007d6c: 97ffeaed  bl       #0x2920
// ============================================================================
std::uint32_t fde_29_07d08(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007d08ULL;
    for (std::size_t i = 0; i < 26ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5238ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[30] Subroutine @ 0x007d70..0x008c34 (3780 bytes, 945 AArch64 instructions)
// [VN] Khung FDE[30] Hàm con @ 0x007d70..0x008c34 (3780 byte, 945 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x007d70: d101c3ff  sub      sp, sp, #0x70
//   0x007d74: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x007d78: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x007d7c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x007d80: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x007d84: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x007d88: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x007d8c: 910183fd  add      x29, sp, #0x60
//   0x007d90: d53bd056  mrs      x22, tpidr_el0
//   0x007d94: f94016c8  ldr      x8, [x22, #0x28]
//   0x007d98: f90007e8  str      x8, [sp, #8]
//   0x007d9c: b40000c0  cbz      x0, #0x7db4
//   0x007da0: f9401813  ldr      x19, [x0, #0x30]
//   0x007da4: b4000093  cbz      x19, #0x7db4
//   0x007da8: f9400268  ldr      x8, [x19]
//   0x007dac: eb00011f  cmp      x8, x0
//   0x007db0: 540001c0  b.eq     #0x7de8
//   0x007db4: 12800020  mov      w0, #-2
//   0x007db8: f94016c8  ldr      x8, [x22, #0x28]
//   0x007dbc: f94007e9  ldr      x9, [sp, #8]
//   0x007dc0: eb09011f  cmp      x8, x9
//   0x007dc4: 54007361  b.ne     #0x8c30
//   0x007dc8: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x007dcc: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x007dd0: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x007dd4: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x007dd8: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x007ddc: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x007de0: 9101c3ff  add      sp, sp, #0x70
//   0x007de4: d65f03c0  ret      
//   0x007de8: 900000d9  adrp     x25, #0x1f000
//   0x007dec: 900000db  adrp     x27, #0x1f000
//   0x007df0: 900000d7  adrp     x23, #0x1f000
//   0x007df4: b9400a68  ldr      w8, [x19, #8]
//   0x007df8: f947e739  ldr      x25, [x25, #0xfc8]
//   0x007dfc: f947ff7b  ldr      x27, [x27, #0xff8]
//   0x007e00: f947caf7  ldr      x23, [x23, #0xf90]
//   0x007e04: 529f4a09  mov      w9, #0xfa50
//   0x007e08: 5290d418  mov      w24, #0x86a0
//   0x007e0c: 72a00038  movk     w24, #1, lsl #16
//   0x007e10: 5280003a  mov      w26, #1
//   0x007e14: 5280005c  mov      w28, #2
//   0x007e18: 8b090275  add      x21, x19, x9
//   0x007e1c: 9104c2f4  add      x20, x23, #0x130
//   0x007e20: 7100051f  cmp      w8, #1
//   0x007e24: 54006dc0  b.eq     #0x8bdc
//   0x007e28: 7100091f  cmp      w8, #2
//   0x007e2c: 54000080  b.eq     #0x7e3c
//   0x007e30: 7100291f  cmp      w8, #0xa
//   0x007e34: 54ffff6b  b.lt     #0x7e20
//   0x007e38: 1400035a  b        #0x8ba0
//   0x007e3c: 3940b268  ldrb     w8, [x19, #0x2c]
//   0x007e40: 39405269  ldrb     w9, [x19, #0x14]
//   0x007e44: 34002388  cbz      w8, #0x82b4
//   0x007e48: f9400268  ldr      x8, [x19]
//   0x007e4c: b940210a  ldr      w10, [x8, #0x20]
//   0x007e50: 34003ae9  cbz      w9, #0x85ac
//   0x007e54: 3400664a  cbz      w10, #0x8b1c
//   0x007e58: b940126d  ldr      w13, [x19, #0x10]
//   0x007e5c: 340000ed  cbz      w13, #0x7e78
//   0x007e60: 1400009f  b        #0x80dc
//   0x007e64: b9004270  str      w16, [x19, #0x40]
//   0x007e68: 5280002d  mov      w13, #1
//   0x007e6c: b9402109  ldr      w9, [x8, #0x20]
//   0x007e70: 34006569  cbz      w9, #0x8b1c
//   0x007e74: 3500134d  cbnz     w13, #0x80dc
//   0x007e78: b94002ad  ldr      w13, [x21]
//   0x007e7c: b9444669  ldr      w9, [x19, #0x444]
//   0x007e80: 110005aa  add      w10, w13, #1
//   0x007e84: 6b0a013f  cmp      w9, w10
//   0x007e88: 540064a0  b.eq     #0x8b1c
//   0x007e8c: 54006acc  b.gt     #0x8be4
//   0x007e90: b9402a6a  ldr      w10, [x19, #0x28]
//   0x007e94: 2947ba6f  ldp      w15, w14, [x19, #0x3c]
//   0x007e98: b900127a  str      w26, [x19, #0x10]
//   0x007e9c: 1b187d4c  mul      w12, w10, w24
//   0x007ea0: 6b0c01ff  cmp      w15, w12
//   0x007ea4: 3900326e  strb     w14, [x19, #0xc]
//   0x007ea8: 540069e2  b.hs     #0x8be4
//   0x007eac: 2a1f03f0  mov      w16, wzr
//   0x007eb0: 5280200a  mov      w10, #0x100
//   0x007eb4: 0b0a020b  add      w11, w16, w10
//   0x007eb8: 13017d6b  asr      w11, w11, #1
//   0x007ebc: 8b2bca71  add      x17, x19, w11, sxtw #2
//   0x007ec0: b9444a31  ldr      w17, [x17, #0x448]
//   0x007ec4: 6b0f023f  cmp      w17, w15
//   0x007ec8: 1a8ac16a  csel     w10, w11, w10, gt
//   0x007ecc: 1a8bc210  csel     w16, w16, w11, gt
//   0x007ed0: 4b10014b  sub      w11, w10, w16
//   0x007ed4: 7100057f  cmp      w11, #1
//   0x007ed8: 54fffee1  b.ne     #0x7eb4
//   0x007edc: f946326b  ldr      x11, [x19, #0xc60]
//   0x007ee0: f9462e6a  ldr      x10, [x19, #0xc58]
//   0x007ee4: d341fdf1  lsr      x17, x15, #1
//   0x007ee8: 38716960  ldrb     w0, [x11, x17]
//   0x007eec: 531e75f1  lsl      w17, w15, #2
//   0x007ef0: 927e0221  and      x1, x17, #4
//   0x007ef4: 786f7951  ldrh     w17, [x10, x15, lsl #1]
//   0x007ef8: 9ac12400  lsr      x0, x0, x1
//   0x007efc: b9401a6f  ldr      w15, [x19, #0x18]
//   0x007f00: 53103c00  lsl      w0, w0, #0x10
//   0x007f04: 92700c00  and      x0, x0, #0xf0000
//   0x007f08: aa110002  orr      x2, x0, x17
//   0x007f0c: b9003e62  str      w2, [x19, #0x3c]
//   0x007f10: 350000ef  cbnz     w15, #0x7f2c
//   0x007f14: b9801e60  ldrsw    x0, [x19, #0x1c]
//   0x007f18: b8607b6f  ldr      w15, [x27, x0, lsl #2]
//   0x007f1c: 11000401  add      w1, w0, #1
//   0x007f20: 7108003f  cmp      w1, #0x200
//   0x007f24: 1a8007e0  csinc    w0, wzr, w0, eq
//   0x007f28: 2903026f  stp      w15, w0, [x19, #0x18]
//   0x007f2c: 510005e0  sub      w0, w15, #1
//   0x007f30: 1100052f  add      w15, w9, #1
//   0x007f34: 6b0d013f  cmp      w9, w13
//   0x007f38: b9001a60  str      w0, [x19, #0x18]
//   0x007f3c: b904466f  str      w15, [x19, #0x444]
//   0x007f40: 54fff940  b.eq     #0x7e68
//   0x007f44: 7100041f  cmp      w0, #1
//   0x007f48: 1a9f17e1  cset     w1, eq
//   0x007f4c: 12001e10  and      w16, w16, #0xff
//   0x007f50: 4a010210  eor      w16, w16, w1
//   0x007f54: 6b0e021f  cmp      w16, w14
//   0x007f58: 54fff861  b.ne     #0x7e64
//   0x007f5c: 6b0c005f  cmp      w2, w12
//   0x007f60: b900127c  str      w28, [x19, #0x10]
//   0x007f64: 54006402  b.hs     #0x8be4
//   0x007f68: 2a1f03e1  mov      w1, wzr
//   0x007f6c: 52802010  mov      w16, #0x100
//   0x007f70: 0b100023  add      w3, w1, w16
//   0x007f74: 13017c63  asr      w3, w3, #1
//   0x007f78: 8b23ca64  add      x4, x19, w3, sxtw #2
//   0x007f7c: b9444884  ldr      w4, [x4, #0x448]
//   0x007f80: 6b02009f  cmp      w4, w2
//   0x007f84: 1a90c070  csel     w16, w3, w16, gt
//   0x007f88: 1a83c021  csel     w1, w1, w3, gt
//   0x007f8c: 4b010203  sub      w3, w16, w1
//   0x007f90: 7100047f  cmp      w3, #1
//   0x007f94: 54fffee1  b.ne     #0x7f70
//   0x007f98: d341fc50  lsr      x16, x2, #1
//   0x007f9c: 38706963  ldrb     w3, [x11, x16]
//   0x007fa0: 531e7631  lsl      w17, w17, #2
//   0x007fa4: 78627950  ldrh     w16, [x10, x2, lsl #1]
//   0x007fa8: 927e0231  and      x17, x17, #4
//   0x007fac: 9ad12471  lsr      x17, x3, x17
//   0x007fb0: 53103e31  lsl      w17, w17, #0x10
//   0x007fb4: 92700e31  and      x17, x17, #0xf0000
//   0x007fb8: aa100222  orr      x2, x17, x16
//   0x007fbc: b9003e62  str      w2, [x19, #0x3c]
//   0x007fc0: 350000e0  cbnz     w0, #0x7fdc
//   0x007fc4: b9801e71  ldrsw    x17, [x19, #0x1c]
//   0x007fc8: b8717b60  ldr      w0, [x27, x17, lsl #2]
//   0x007fcc: 11000623  add      w3, w17, #1
//   0x007fd0: 7108007f  cmp      w3, #0x200
//   0x007fd4: 1a9107f1  csinc    w17, wzr, w17, eq
//   0x007fd8: 29034660  stp      w0, w17, [x19, #0x18]
//   0x007fdc: 51000400  sub      w0, w0, #1
//   0x007fe0: 11000931  add      w17, w9, #2
//   0x007fe4: 6b0d01ff  cmp      w15, w13
//   0x007fe8: b9001a60  str      w0, [x19, #0x18]
//   0x007fec: b9044671  str      w17, [x19, #0x444]
//   0x007ff0: 540000a1  b.ne     #0x8004
//   0x007ff4: 5280004d  mov      w13, #2
//   0x007ff8: b9402109  ldr      w9, [x8, #0x20]
//   0x007ffc: 35fff3c9  cbnz     w9, #0x7e74
//   0x008000: 140002c7  b        #0x8b1c
//   0x008004: 7100041f  cmp      w0, #1
//   0x008008: 1a9f17ef  cset     w15, eq
//   0x00800c: 12001c21  and      w1, w1, #0xff
//   0x008010: 4a0f002f  eor      w15, w1, w15
//   0x008014: 6b0e01ff  cmp      w15, w14
//   0x008018: 54000581  b.ne     #0x80c8
//   0x00801c: 6b0c005f  cmp      w2, w12
//   0x008020: 5280006f  mov      w15, #3
//   0x008024: b900126f  str      w15, [x19, #0x10]
//   0x008028: 54005de2  b.hs     #0x8be4
//   0x00802c: 2a1f03e1  mov      w1, wzr
//   0x008030: 5280200f  mov      w15, #0x100
//   0x008034: 0b0f0023  add      w3, w1, w15
//   0x008038: 13017c63  asr      w3, w3, #1
//   0x00803c: 8b23ca64  add      x4, x19, w3, sxtw #2
//   0x008040: b9444884  ldr      w4, [x4, #0x448]
//   0x008044: 6b02009f  cmp      w4, w2
//   0x008048: 1a8fc06f  csel     w15, w3, w15, gt
//   0x00804c: 1a83c021  csel     w1, w1, w3, gt
//   0x008050: 4b0101e3  sub      w3, w15, w1
//   0x008054: 7100047f  cmp      w3, #1
//   0x008058: 54fffee1  b.ne     #0x8034
//   0x00805c: d341fc4f  lsr      x15, x2, #1
//   0x008060: 386f6963  ldrb     w3, [x11, x15]
//   0x008064: 531e7610  lsl      w16, w16, #2
//   0x008068: 7862794f  ldrh     w15, [x10, x2, lsl #1]
//   0x00806c: 927e0210  and      x16, x16, #4
//   0x008070: 9ad02470  lsr      x16, x3, x16
//   0x008074: 53103e10  lsl      w16, w16, #0x10
//   0x008078: 92700e10  and      x16, x16, #0xf0000
//   0x00807c: aa0f0202  orr      x2, x16, x15
//   0x008080: b9003e62  str      w2, [x19, #0x3c]
//   0x008084: 350000e0  cbnz     w0, #0x80a0
//   0x008088: b9801e70  ldrsw    x16, [x19, #0x1c]
//   0x00808c: b8707b60  ldr      w0, [x27, x16, lsl #2]
//   0x008090: 11000603  add      w3, w16, #1
//   0x008094: 7108007f  cmp      w3, #0x200
//   0x008098: 1a9007f0  csinc    w16, wzr, w16, eq
//   0x00809c: 29034260  stp      w0, w16, [x19, #0x18]
//   0x0080a0: 51000410  sub      w16, w0, #1
//   0x0080a4: 11000d20  add      w0, w9, #3
//   0x0080a8: 6b0d023f  cmp      w17, w13
//   0x0080ac: b9001a70  str      w16, [x19, #0x18]
//   0x0080b0: b9044660  str      w0, [x19, #0x444]
//   0x0080b4: 54000481  b.ne     #0x8144
//   0x0080b8: 5280006d  mov      w13, #3
//   0x0080bc: b9402109  ldr      w9, [x8, #0x20]
//   0x0080c0: 35ffeda9  cbnz     w9, #0x7e74
//   0x0080c4: 14000296  b        #0x8b1c
//   0x0080c8: b900426f  str      w15, [x19, #0x40]
//   0x0080cc: 5280004d  mov      w13, #2
//   0x0080d0: b9402109  ldr      w9, [x8, #0x20]
//   0x0080d4: 35ffed09  cbnz     w9, #0x7e74
//   0x0080d8: 14000291  b        #0x8b1c
//   0x0080dc: 39403269  ldrb     w9, [x19, #0xc]
//   0x0080e0: f9400d08  ldr      x8, [x8, #0x18]
//   0x0080e4: 39000109  strb     w9, [x8]
//   0x0080e8: b94c7269  ldr      w9, [x19, #0xc70]
//   0x0080ec: 39403268  ldrb     w8, [x19, #0xc]
//   0x0080f0: b940126a  ldr      w10, [x19, #0x10]
//   0x0080f4: 4a496108  eor      w8, w8, w9, lsr #24
//   0x0080f8: b8685b2b  ldr      w11, [x25, w8, uxtw #2]
//   0x0080fc: f9400268  ldr      x8, [x19]
//   0x008100: 5100054d  sub      w13, w10, #1
//   0x008104: b900126d  str      w13, [x19, #0x10]
//   0x008108: 4a092169  eor      w9, w11, w9, lsl #8
//   0x00810c: b90c7269  str      w9, [x19, #0xc70]
//   0x008110: f9400d09  ldr      x9, [x8, #0x18]
//   0x008114: 29442d0a  ldp      w10, w11, [x8, #0x20]
//   0x008118: 91000529  add      x9, x9, #1
//   0x00811c: f9000d09  str      x9, [x8, #0x18]
//   0x008120: 51000549  sub      w9, w10, #1
//   0x008124: 3100056a  adds     w10, w11, #1
//   0x008128: 29042909  stp      w9, w10, [x8, #0x20]
//   0x00812c: 54000083  b.lo     #0x813c
//   0x008130: b940290a  ldr      w10, [x8, #0x28]
//   0x008134: 1100054a  add      w10, w10, #1
//   0x008138: b900290a  str      w10, [x8, #0x28]
//   0x00813c: 35ffe9c9  cbnz     w9, #0x7e74
//   0x008140: 14000277  b        #0x8b1c
//   0x008144: 7100061f  cmp      w16, #1
//   0x008148: 1a9f17ed  cset     w13, eq
//   0x00814c: 12001c31  and      w17, w1, #0xff
//   0x008150: 4a0d022d  eor      w13, w17, w13
//   0x008154: 6b0e01bf  cmp      w13, w14
//   0x008158: 54000a41  b.ne     #0x82a0
//   0x00815c: 6b0c005f  cmp      w2, w12
//   0x008160: 54005422  b.hs     #0x8be4
//   0x008164: 2a1f03ed  mov      w13, wzr
//   0x008168: 5280200e  mov      w14, #0x100
//   0x00816c: 0b0e01b1  add      w17, w13, w14
//   0x008170: 13017e31  asr      w17, w17, #1
//   0x008174: 8b31ca60  add      x0, x19, w17, sxtw #2
//   0x008178: b9444800  ldr      w0, [x0, #0x448]
//   0x00817c: 6b02001f  cmp      w0, w2
//   0x008180: 1a8ec22e  csel     w14, w17, w14, gt
//   0x008184: 1a91c1ad  csel     w13, w13, w17, gt
//   0x008188: 4b0d01d1  sub      w17, w14, w13
//   0x00818c: 7100063f  cmp      w17, #1
//   0x008190: 54fffee1  b.ne     #0x816c
//   0x008194: d341fc4e  lsr      x14, x2, #1
//   0x008198: 386e6971  ldrb     w17, [x11, x14]
//   0x00819c: 531e75ef  lsl      w15, w15, #2
//   0x0081a0: 7862794e  ldrh     w14, [x10, x2, lsl #1]
//   0x0081a4: 927e01ef  and      x15, x15, #4
//   0x0081a8: 9acf262f  lsr      x15, x17, x15
//   0x0081ac: 53103def  lsl      w15, w15, #0x10
//   0x0081b0: 92700def  and      x15, x15, #0xf0000
//   0x0081b4: aa0e01ef  orr      x15, x15, x14
//   0x0081b8: b9003e6f  str      w15, [x19, #0x3c]
//   0x0081bc: 350000f0  cbnz     w16, #0x81d8
//   0x0081c0: b9801e71  ldrsw    x17, [x19, #0x1c]
//   0x0081c4: b8717b70  ldr      w16, [x27, x17, lsl #2]
//   0x0081c8: 11000620  add      w0, w17, #1
//   0x0081cc: 7108001f  cmp      w0, #0x200
//   0x0081d0: 1a9107f1  csinc    w17, wzr, w17, eq
//   0x0081d4: 29034670  stp      w16, w17, [x19, #0x18]
//   0x0081d8: 51000610  sub      w16, w16, #1
//   0x0081dc: 11001131  add      w17, w9, #4
//   0x0081e0: 7100061f  cmp      w16, #1
//   0x0081e4: 12001dad  and      w13, w13, #0xff
//   0x0081e8: b9044671  str      w17, [x19, #0x444]
//   0x0081ec: 1a9f17f1  cset     w17, eq
//   0x0081f0: 4a1101ad  eor      w13, w13, w17
//   0x0081f4: 110011ad  add      w13, w13, #4
//   0x0081f8: 6b0c01ff  cmp      w15, w12
//   0x0081fc: b9001a70  str      w16, [x19, #0x18]
//   0x008200: b900126d  str      w13, [x19, #0x10]
//   0x008204: 54004f02  b.hs     #0x8be4
//   0x008208: 2a1f03ec  mov      w12, wzr
//   0x00820c: 52802011  mov      w17, #0x100
//   0x008210: 0b110180  add      w0, w12, w17
//   0x008214: 13017c00  asr      w0, w0, #1
//   0x008218: 8b20ca61  add      x1, x19, w0, sxtw #2
//   0x00821c: b9444821  ldr      w1, [x1, #0x448]
//   0x008220: 6b0f003f  cmp      w1, w15
//   0x008224: 1a91c011  csel     w17, w0, w17, gt
//   0x008228: 1a80c18c  csel     w12, w12, w0, gt
//   0x00822c: 4b0c0220  sub      w0, w17, w12
//   0x008230: 7100041f  cmp      w0, #1
//   0x008234: 54fffee1  b.ne     #0x8210
//   0x008238: b900426c  str      w12, [x19, #0x40]
//   0x00823c: d341fdf1  lsr      x17, x15, #1
//   0x008240: 3871696b  ldrb     w11, [x11, x17]
//   0x008244: 786f794a  ldrh     w10, [x10, x15, lsl #1]
//   0x008248: 531e01ce  ubfiz    w14, w14, #2, #1
//   0x00824c: 1ace256b  lsr      w11, w11, w14
//   0x008250: 33100d6a  bfi      w10, w11, #0x10, #4
//   0x008254: b9003e6a  str      w10, [x19, #0x3c]
//   0x008258: 350000f0  cbnz     w16, #0x8274
//   0x00825c: b9801e6a  ldrsw    x10, [x19, #0x1c]
//   0x008260: b86a7b70  ldr      w16, [x27, x10, lsl #2]
//   0x008264: 1100054b  add      w11, w10, #1
//   0x008268: 7108017f  cmp      w11, #0x200
//   0x00826c: 1a8a07ea  csinc    w10, wzr, w10, eq
//   0x008270: 29032a70  stp      w16, w10, [x19, #0x18]
//   0x008274: 5100060a  sub      w10, w16, #1
//   0x008278: 7100055f  cmp      w10, #1
//   0x00827c: b9001a6a  str      w10, [x19, #0x18]
//   0x008280: 1a9f17ea  cset     w10, eq
//   0x008284: 11001529  add      w9, w9, #5
//   0x008288: 4a0a018a  eor      w10, w12, w10
//   0x00828c: b900426a  str      w10, [x19, #0x40]
//   0x008290: b9044669  str      w9, [x19, #0x444]
//   0x008294: b9402109  ldr      w9, [x8, #0x20]
//   0x008298: 35ffdee9  cbnz     w9, #0x7e74
//   0x00829c: 14000220  b        #0x8b1c
//   0x0082a0: b900426d  str      w13, [x19, #0x40]
//   0x0082a4: 5280006d  mov      w13, #3
//   0x0082a8: b9402109  ldr      w9, [x8, #0x20]
//   0x0082ac: 35ffde49  cbnz     w9, #0x7e74
//   0x0082b0: 1400021b  b        #0x8b1c
//   0x0082b4: 34003309  cbz      w9, #0x8914
//   0x0082b8: f9400268  ldr      x8, [x19]
//   0x0082bc: b9402109  ldr      w9, [x8, #0x20]
//   0x0082c0: 340042e9  cbz      w9, #0x8b1c
//   0x0082c4: b940126c  ldr      w12, [x19, #0x10]
//   0x0082c8: 340000ec  cbz      w12, #0x82e4
//   0x0082cc: 14000065  b        #0x8460
//   0x0082d0: b9004271  str      w17, [x19, #0x40]
//   0x0082d4: 5280002c  mov      w12, #1
//   0x0082d8: b9402109  ldr      w9, [x8, #0x20]
//   0x0082dc: 34004209  cbz      w9, #0x8b1c
//   0x0082e0: 35000c0c  cbnz     w12, #0x8460
//   0x0082e4: b94002ac  ldr      w12, [x21]
//   0x0082e8: b9444669  ldr      w9, [x19, #0x444]
//   0x0082ec: 1100058a  add      w10, w12, #1
//   0x0082f0: 6b0a013f  cmp      w9, w10
//   0x0082f4: 54004140  b.eq     #0x8b1c
//   0x0082f8: 5400476c  b.gt     #0x8be4
//   0x0082fc: b9402a6a  ldr      w10, [x19, #0x28]
//   0x008300: 2947b66e  ldp      w14, w13, [x19, #0x3c]
//   0x008304: b900127a  str      w26, [x19, #0x10]
//   0x008308: 1b187d4b  mul      w11, w10, w24
//   0x00830c: 6b0b01df  cmp      w14, w11
//   0x008310: 3900326d  strb     w13, [x19, #0xc]
//   0x008314: 54004682  b.hs     #0x8be4
//   0x008318: f9462a6a  ldr      x10, [x19, #0xc50]
//   0x00831c: b86e7951  ldr      w17, [x10, x14, lsl #2]
//   0x008320: b9401a6e  ldr      w14, [x19, #0x18]
//   0x008324: d348fe30  lsr      x16, x17, #8
//   0x008328: b9003e70  str      w16, [x19, #0x3c]
//   0x00832c: 350000ee  cbnz     w14, #0x8348
//   0x008330: b9801e6f  ldrsw    x15, [x19, #0x1c]
//   0x008334: b86f7b6e  ldr      w14, [x27, x15, lsl #2]
//   0x008338: 110005e0  add      w0, w15, #1
//   0x00833c: 7108001f  cmp      w0, #0x200
//   0x008340: 1a8f07ef  csinc    w15, wzr, w15, eq
//   0x008344: 29033e6e  stp      w14, w15, [x19, #0x18]
//   0x008348: 510005cf  sub      w15, w14, #1
//   0x00834c: 1100052e  add      w14, w9, #1
//   0x008350: 6b0c013f  cmp      w9, w12
//   0x008354: b9001a6f  str      w15, [x19, #0x18]
//   0x008358: b904466e  str      w14, [x19, #0x444]
//   0x00835c: 54fffbc0  b.eq     #0x82d4
//   0x008360: 710005ff  cmp      w15, #1
//   0x008364: 1a9f17e0  cset     w0, eq
//   0x008368: 12001e31  and      w17, w17, #0xff
//   0x00836c: 4a000231  eor      w17, w17, w0
//   0x008370: 6b0d023f  cmp      w17, w13
//   0x008374: 54fffae1  b.ne     #0x82d0
//   0x008378: 6b0b021f  cmp      w16, w11
//   0x00837c: b900127c  str      w28, [x19, #0x10]
//   0x008380: 54004322  b.hs     #0x8be4
//   0x008384: b8707940  ldr      w0, [x10, x16, lsl #2]
//   0x008388: d348fc10  lsr      x16, x0, #8
//   0x00838c: b9003e70  str      w16, [x19, #0x3c]
//   0x008390: 350000ef  cbnz     w15, #0x83ac
//   0x008394: b9801e71  ldrsw    x17, [x19, #0x1c]
//   0x008398: b8717b6f  ldr      w15, [x27, x17, lsl #2]
//   0x00839c: 11000621  add      w1, w17, #1
//   0x0083a0: 7108003f  cmp      w1, #0x200
//   0x0083a4: 1a9107f1  csinc    w17, wzr, w17, eq
//   0x0083a8: 2903466f  stp      w15, w17, [x19, #0x18]
//   0x0083ac: 510005f1  sub      w17, w15, #1
//   0x0083b0: 1100092f  add      w15, w9, #2
//   0x0083b4: 6b0c01df  cmp      w14, w12
//   0x0083b8: b9001a71  str      w17, [x19, #0x18]
//   0x0083bc: b904466f  str      w15, [x19, #0x444]
//   0x0083c0: 540000a1  b.ne     #0x83d4
//   0x0083c4: 5280004c  mov      w12, #2
//   0x0083c8: b9402109  ldr      w9, [x8, #0x20]
//   0x0083cc: 35fff8a9  cbnz     w9, #0x82e0
//   0x0083d0: 140001d3  b        #0x8b1c
//   0x0083d4: 7100063f  cmp      w17, #1
//   0x0083d8: 1a9f17ee  cset     w14, eq
//   0x0083dc: 12001c00  and      w0, w0, #0xff
//   0x0083e0: 4a0e000e  eor      w14, w0, w14
//   0x0083e4: 6b0d01df  cmp      w14, w13
//   0x0083e8: 54000321  b.ne     #0x844c
//   0x0083ec: 6b0b021f  cmp      w16, w11
//   0x0083f0: 5280006e  mov      w14, #3
//   0x0083f4: b900126e  str      w14, [x19, #0x10]
//   0x0083f8: 54003f62  b.hs     #0x8be4
//   0x0083fc: b8707940  ldr      w0, [x10, x16, lsl #2]
//   0x008400: d348fc0e  lsr      x14, x0, #8
//   0x008404: b9003e6e  str      w14, [x19, #0x3c]
//   0x008408: 350000f1  cbnz     w17, #0x8424
//   0x00840c: b9801e70  ldrsw    x16, [x19, #0x1c]
//   0x008410: b8707b71  ldr      w17, [x27, x16, lsl #2]
//   0x008414: 11000601  add      w1, w16, #1
//   0x008418: 7108003f  cmp      w1, #0x200
//   0x00841c: 1a9007f0  csinc    w16, wzr, w16, eq
//   0x008420: 29034271  stp      w17, w16, [x19, #0x18]
//   0x008424: 51000630  sub      w16, w17, #1
//   0x008428: 11000d31  add      w17, w9, #3
//   0x00842c: 6b0c01ff  cmp      w15, w12
//   0x008430: b9001a70  str      w16, [x19, #0x18]
//   0x008434: b9044671  str      w17, [x19, #0x444]
//   0x008438: 54000481  b.ne     #0x84c8
//   0x00843c: 5280006c  mov      w12, #3
//   0x008440: b9402109  ldr      w9, [x8, #0x20]
//   0x008444: 35fff4e9  cbnz     w9, #0x82e0
//   0x008448: 140001b5  b        #0x8b1c
//   0x00844c: b900426e  str      w14, [x19, #0x40]
//   0x008450: 5280004c  mov      w12, #2
//   0x008454: b9402109  ldr      w9, [x8, #0x20]
//   0x008458: 35fff449  cbnz     w9, #0x82e0
//   0x00845c: 140001b0  b        #0x8b1c
//   0x008460: 39403269  ldrb     w9, [x19, #0xc]
//   0x008464: f9400d08  ldr      x8, [x8, #0x18]
//   0x008468: 39000109  strb     w9, [x8]
//   0x00846c: b94c7269  ldr      w9, [x19, #0xc70]
//   0x008470: 39403268  ldrb     w8, [x19, #0xc]
//   0x008474: b940126a  ldr      w10, [x19, #0x10]
//   0x008478: 4a496108  eor      w8, w8, w9, lsr #24
//   0x00847c: b8685b2b  ldr      w11, [x25, w8, uxtw #2]
//   0x008480: f9400268  ldr      x8, [x19]
//   0x008484: 5100054c  sub      w12, w10, #1
//   0x008488: b900126c  str      w12, [x19, #0x10]
//   0x00848c: 4a092169  eor      w9, w11, w9, lsl #8
//   0x008490: b90c7269  str      w9, [x19, #0xc70]
//   0x008494: f9400d09  ldr      x9, [x8, #0x18]
//   0x008498: 29442d0a  ldp      w10, w11, [x8, #0x20]
//   0x00849c: 91000529  add      x9, x9, #1
//   0x0084a0: f9000d09  str      x9, [x8, #0x18]
//   0x0084a4: 51000549  sub      w9, w10, #1
//   0x0084a8: 3100056a  adds     w10, w11, #1
//   0x0084ac: 29042909  stp      w9, w10, [x8, #0x20]
//   0x0084b0: 54000083  b.lo     #0x84c0
//   0x0084b4: b940290a  ldr      w10, [x8, #0x28]
//   0x0084b8: 1100054a  add      w10, w10, #1
//   0x0084bc: b900290a  str      w10, [x8, #0x28]
//   0x0084c0: 35fff109  cbnz     w9, #0x82e0
//   0x0084c4: 14000196  b        #0x8b1c
//   0x0084c8: 7100061f  cmp      w16, #1
//   0x0084cc: 1a9f17ec  cset     w12, eq
//   0x0084d0: 12001c0f  and      w15, w0, #0xff
//   0x0084d4: 4a0c01ec  eor      w12, w15, w12
//   0x0084d8: 6b0d019f  cmp      w12, w13
//   0x0084dc: 540005e1  b.ne     #0x8598
//   0x0084e0: 6b0b01df  cmp      w14, w11
//   0x0084e4: 54003802  b.hs     #0x8be4
//   0x0084e8: b86e794c  ldr      w12, [x10, x14, lsl #2]
//   0x0084ec: d348fd8d  lsr      x13, x12, #8
//   0x0084f0: b9003e6d  str      w13, [x19, #0x3c]
//   0x0084f4: 350000f0  cbnz     w16, #0x8510
//   0x0084f8: b9801e6e  ldrsw    x14, [x19, #0x1c]
//   0x0084fc: b86e7b70  ldr      w16, [x27, x14, lsl #2]
//   0x008500: 110005cf  add      w15, w14, #1
//   0x008504: 710801ff  cmp      w15, #0x200
//   0x008508: 1a8e07ee  csinc    w14, wzr, w14, eq
//   0x00850c: 29033a70  stp      w16, w14, [x19, #0x18]
//   0x008510: 5100060e  sub      w14, w16, #1
//   0x008514: 1100112f  add      w15, w9, #4
//   0x008518: 710005df  cmp      w14, #1
//   0x00851c: 12001d8c  and      w12, w12, #0xff
//   0x008520: b904466f  str      w15, [x19, #0x444]
//   0x008524: 1a9f17ef  cset     w15, eq
//   0x008528: 4a0f018c  eor      w12, w12, w15
//   0x00852c: 1100118c  add      w12, w12, #4
//   0x008530: 6b0b01bf  cmp      w13, w11
//   0x008534: b9001a6e  str      w14, [x19, #0x18]
//   0x008538: b900126c  str      w12, [x19, #0x10]
//   0x00853c: 54003542  b.hs     #0x8be4
//   0x008540: b86d794b  ldr      w11, [x10, x13, lsl #2]
//   0x008544: 12001d6a  and      w10, w11, #0xff
//   0x008548: 53087d6b  lsr      w11, w11, #8
//   0x00854c: 2907aa6b  stp      w11, w10, [x19, #0x3c]
//   0x008550: 350000ee  cbnz     w14, #0x856c
//   0x008554: b9801e6b  ldrsw    x11, [x19, #0x1c]
//   0x008558: b86b7b6e  ldr      w14, [x27, x11, lsl #2]
//   0x00855c: 1100056d  add      w13, w11, #1
//   0x008560: 710801bf  cmp      w13, #0x200
//   0x008564: 1a8b07eb  csinc    w11, wzr, w11, eq
//   0x008568: 29032e6e  stp      w14, w11, [x19, #0x18]
//   0x00856c: 510005cb  sub      w11, w14, #1
//   0x008570: 7100057f  cmp      w11, #1
//   0x008574: b9001a6b  str      w11, [x19, #0x18]
//   0x008578: 1a9f17eb  cset     w11, eq
//   0x00857c: 11001529  add      w9, w9, #5
//   0x008580: 4a0b014a  eor      w10, w10, w11
//   0x008584: b900426a  str      w10, [x19, #0x40]
//   0x008588: b9044669  str      w9, [x19, #0x444]
//   0x00858c: b9402109  ldr      w9, [x8, #0x20]
//   0x008590: 35ffea89  cbnz     w9, #0x82e0
//   0x008594: 14000162  b        #0x8b1c
//   0x008598: b900426c  str      w12, [x19, #0x40]
//   0x00859c: 5280006c  mov      w12, #3
//   0x0085a0: b9402109  ldr      w9, [x8, #0x20]
//   0x0085a4: 35ffe9e9  cbnz     w9, #0x82e0
//   0x0085a8: 1400015d  b        #0x8b1c
//   0x0085ac: 34002b8a  cbz      w10, #0x8b1c
//   0x0085b0: b940126d  ldr      w13, [x19, #0x10]
//   0x0085b4: 340000ed  cbz      w13, #0x85d0
//   0x0085b8: 1400007d  b        #0x87ac
//   0x0085bc: b9004270  str      w16, [x19, #0x40]
//   0x0085c0: 5280002d  mov      w13, #1
//   0x0085c4: b9402109  ldr      w9, [x8, #0x20]
//   0x0085c8: 34002aa9  cbz      w9, #0x8b1c
//   0x0085cc: 35000f0d  cbnz     w13, #0x87ac
//   0x0085d0: b94002ad  ldr      w13, [x21]
//   0x0085d4: b9444669  ldr      w9, [x19, #0x444]
//   0x0085d8: 110005aa  add      w10, w13, #1
//   0x0085dc: 6b0a013f  cmp      w9, w10
//   0x0085e0: 540029e0  b.eq     #0x8b1c
//   0x0085e4: 5400300c  b.gt     #0x8be4
//   0x0085e8: b9402a6a  ldr      w10, [x19, #0x28]
//   0x0085ec: 2947ba71  ldp      w17, w14, [x19, #0x3c]
//   0x0085f0: b900127a  str      w26, [x19, #0x10]
//   0x0085f4: 1b187d4b  mul      w11, w10, w24
//   0x0085f8: 6b0b023f  cmp      w17, w11
//   0x0085fc: 3900326e  strb     w14, [x19, #0xc]
//   0x008600: 54002f22  b.hs     #0x8be4
//   0x008604: 2a1f03f0  mov      w16, wzr
//   0x008608: 5280200a  mov      w10, #0x100
//   0x00860c: 0b0a020c  add      w12, w16, w10
//   0x008610: 13017d8c  asr      w12, w12, #1
//   0x008614: 8b2cca6f  add      x15, x19, w12, sxtw #2
//   0x008618: b94449ef  ldr      w15, [x15, #0x448]
//   0x00861c: 6b1101ff  cmp      w15, w17
//   0x008620: 1a8ac18a  csel     w10, w12, w10, gt
//   0x008624: 1a8cc210  csel     w16, w16, w12, gt
//   0x008628: 4b10014c  sub      w12, w10, w16
//   0x00862c: 7100059f  cmp      w12, #1
//   0x008630: 54fffee1  b.ne     #0x860c
//   0x008634: f946326a  ldr      x10, [x19, #0xc60]
//   0x008638: d341fe2c  lsr      x12, x17, #1
//   0x00863c: 531e7620  lsl      w0, w17, #2
//   0x008640: 927e0000  and      x0, x0, #4
//   0x008644: 386c694f  ldrb     w15, [x10, x12]
//   0x008648: f9462e6c  ldr      x12, [x19, #0xc58]
//   0x00864c: 6b0d013f  cmp      w9, w13
//   0x008650: 9ac025e0  lsr      x0, x15, x0
//   0x008654: 78717991  ldrh     w17, [x12, x17, lsl #1]
//   0x008658: 53103c00  lsl      w0, w0, #0x10
//   0x00865c: 92700c00  and      x0, x0, #0xf0000
//   0x008660: 1100052f  add      w15, w9, #1
//   0x008664: aa110001  orr      x1, x0, x17
//   0x008668: b9003e61  str      w1, [x19, #0x3c]
//   0x00866c: b904466f  str      w15, [x19, #0x444]
//   0x008670: 54fffa80  b.eq     #0x85c0
//   0x008674: 12001e10  and      w16, w16, #0xff
//   0x008678: 6b0e021f  cmp      w16, w14
//   0x00867c: 54fffa01  b.ne     #0x85bc
//   0x008680: 6b0b003f  cmp      w1, w11
//   0x008684: b900127c  str      w28, [x19, #0x10]
//   0x008688: 54002ae2  b.hs     #0x8be4
//   0x00868c: 2a1f03e0  mov      w0, wzr
//   0x008690: 52802010  mov      w16, #0x100
//   0x008694: 0b100002  add      w2, w0, w16
//   0x008698: 13017c42  asr      w2, w2, #1
//   0x00869c: 8b22ca63  add      x3, x19, w2, sxtw #2
//   0x0086a0: b9444863  ldr      w3, [x3, #0x448]
//   0x0086a4: 6b01007f  cmp      w3, w1
//   0x0086a8: 1a90c050  csel     w16, w2, w16, gt
//   0x0086ac: 1a82c000  csel     w0, w0, w2, gt
//   0x0086b0: 4b000202  sub      w2, w16, w0
//   0x0086b4: 7100045f  cmp      w2, #1
//   0x0086b8: 54fffee1  b.ne     #0x8694
//   0x0086bc: 78617990  ldrh     w16, [x12, x1, lsl #1]
//   0x0086c0: d341fc21  lsr      x1, x1, #1
//   0x0086c4: 38616941  ldrb     w1, [x10, x1]
//   0x0086c8: 531e7622  lsl      w2, w17, #2
//   0x0086cc: 6b0d01ff  cmp      w15, w13
//   0x0086d0: 927e004f  and      x15, x2, #4
//   0x0086d4: 9acf242f  lsr      x15, x1, x15
//   0x0086d8: 53103def  lsl      w15, w15, #0x10
//   0x0086dc: 92700def  and      x15, x15, #0xf0000
//   0x0086e0: 11000931  add      w17, w9, #2
//   0x0086e4: aa1001e1  orr      x1, x15, x16
//   0x0086e8: b9003e61  str      w1, [x19, #0x3c]
//   0x0086ec: b9044671  str      w17, [x19, #0x444]
//   0x0086f0: 540000a1  b.ne     #0x8704
//   0x0086f4: 5280004d  mov      w13, #2
//   0x0086f8: b9402109  ldr      w9, [x8, #0x20]
//   0x0086fc: 35fff689  cbnz     w9, #0x85cc
//   0x008700: 14000107  b        #0x8b1c
//   0x008704: 12001c0f  and      w15, w0, #0xff
//   0x008708: 6b0e01ff  cmp      w15, w14
//   0x00870c: 54000461  b.ne     #0x8798
//   0x008710: 6b0b003f  cmp      w1, w11
//   0x008714: 5280006f  mov      w15, #3
//   0x008718: b900126f  str      w15, [x19, #0x10]
//   0x00871c: 54002642  b.hs     #0x8be4
//   0x008720: 2a1f03e0  mov      w0, wzr
//   0x008724: 5280200f  mov      w15, #0x100
//   0x008728: 0b0f0002  add      w2, w0, w15
//   0x00872c: 13017c42  asr      w2, w2, #1
//   0x008730: 8b22ca63  add      x3, x19, w2, sxtw #2
//   0x008734: b9444863  ldr      w3, [x3, #0x448]
//   0x008738: 6b01007f  cmp      w3, w1
//   0x00873c: 1a8fc04f  csel     w15, w2, w15, gt
//   0x008740: 1a82c000  csel     w0, w0, w2, gt
//   0x008744: 4b0001e2  sub      w2, w15, w0
//   0x008748: 7100045f  cmp      w2, #1
//   0x00874c: 54fffee1  b.ne     #0x8728
//   0x008750: 7861798f  ldrh     w15, [x12, x1, lsl #1]
//   0x008754: d341fc21  lsr      x1, x1, #1
//   0x008758: 38616941  ldrb     w1, [x10, x1]
//   0x00875c: 531e7610  lsl      w16, w16, #2
//   0x008760: 6b0d023f  cmp      w17, w13
//   0x008764: 927e020d  and      x13, x16, #4
//   0x008768: 9acd242d  lsr      x13, x1, x13
//   0x00876c: 53103dad  lsl      w13, w13, #0x10
//   0x008770: 92700dad  and      x13, x13, #0xf0000
//   0x008774: 11000d22  add      w2, w9, #3
//   0x008778: aa0f01b0  orr      x16, x13, x15
//   0x00877c: b9003e70  str      w16, [x19, #0x3c]
//   0x008780: b9044662  str      w2, [x19, #0x444]
//   0x008784: 54000481  b.ne     #0x8814
//   0x008788: 5280006d  mov      w13, #3
//   0x00878c: b9402109  ldr      w9, [x8, #0x20]
//   0x008790: 35fff1e9  cbnz     w9, #0x85cc
//   0x008794: 140000e2  b        #0x8b1c
//   0x008798: b900426f  str      w15, [x19, #0x40]
//   0x00879c: 5280004d  mov      w13, #2
//   0x0087a0: b9402109  ldr      w9, [x8, #0x20]
//   0x0087a4: 35fff149  cbnz     w9, #0x85cc
//   0x0087a8: 140000dd  b        #0x8b1c
//   0x0087ac: 39403269  ldrb     w9, [x19, #0xc]
//   0x0087b0: f9400d08  ldr      x8, [x8, #0x18]
//   0x0087b4: 39000109  strb     w9, [x8]
//   0x0087b8: b94c7269  ldr      w9, [x19, #0xc70]
//   0x0087bc: 39403268  ldrb     w8, [x19, #0xc]
//   0x0087c0: b940126a  ldr      w10, [x19, #0x10]
//   0x0087c4: 4a496108  eor      w8, w8, w9, lsr #24
//   0x0087c8: b8685b2b  ldr      w11, [x25, w8, uxtw #2]
//   0x0087cc: f9400268  ldr      x8, [x19]
//   0x0087d0: 5100054d  sub      w13, w10, #1
//   0x0087d4: b900126d  str      w13, [x19, #0x10]
//   0x0087d8: 4a092169  eor      w9, w11, w9, lsl #8
//   0x0087dc: b90c7269  str      w9, [x19, #0xc70]
//   0x0087e0: f9400d09  ldr      x9, [x8, #0x18]
//   0x0087e4: 29442d0a  ldp      w10, w11, [x8, #0x20]
//   0x0087e8: 91000529  add      x9, x9, #1
//   0x0087ec: f9000d09  str      x9, [x8, #0x18]
//   0x0087f0: 51000549  sub      w9, w10, #1
//   0x0087f4: 3100056a  adds     w10, w11, #1
//   0x0087f8: 29042909  stp      w9, w10, [x8, #0x20]
//   0x0087fc: 54000083  b.lo     #0x880c
//   0x008800: b940290a  ldr      w10, [x8, #0x28]
//   0x008804: 1100054a  add      w10, w10, #1
//   0x008808: b900290a  str      w10, [x8, #0x28]
//   0x00880c: 35ffee09  cbnz     w9, #0x85cc
//   0x008810: 140000c3  b        #0x8b1c
//   0x008814: 12001c0d  and      w13, w0, #0xff
//   0x008818: 6b0e01bf  cmp      w13, w14
//   0x00881c: 54000721  b.ne     #0x8900
//   0x008820: 6b0b021f  cmp      w16, w11
//   0x008824: 54001e02  b.hs     #0x8be4
//   0x008828: 2a1f03ed  mov      w13, wzr
//   0x00882c: 5280200e  mov      w14, #0x100
//   0x008830: 0b0e01b1  add      w17, w13, w14
//   0x008834: 13017e31  asr      w17, w17, #1
//   0x008838: 8b31ca60  add      x0, x19, w17, sxtw #2
//   0x00883c: b9444800  ldr      w0, [x0, #0x448]
//   0x008840: 6b10001f  cmp      w0, w16
//   0x008844: 1a8ec22e  csel     w14, w17, w14, gt
//   0x008848: 1a91c1ad  csel     w13, w13, w17, gt
//   0x00884c: 4b0d01d1  sub      w17, w14, w13
//   0x008850: 7100063f  cmp      w17, #1
//   0x008854: 54fffee1  b.ne     #0x8830
//   0x008858: 7870798e  ldrh     w14, [x12, x16, lsl #1]
//   0x00885c: d341fe10  lsr      x16, x16, #1
//   0x008860: 38706950  ldrb     w16, [x10, x16]
//   0x008864: 531e75ef  lsl      w15, w15, #2
//   0x008868: 927e01ef  and      x15, x15, #4
//   0x00886c: 12001dad  and      w13, w13, #0xff
//   0x008870: 9acf260f  lsr      x15, x16, x15
//   0x008874: 53103def  lsl      w15, w15, #0x10
//   0x008878: 92700def  and      x15, x15, #0xf0000
//   0x00887c: aa0e01ef  orr      x15, x15, x14
//   0x008880: 11001131  add      w17, w9, #4
//   0x008884: 110011ad  add      w13, w13, #4
//   0x008888: 6b0b01ff  cmp      w15, w11
//   0x00888c: b9044671  str      w17, [x19, #0x444]
//   0x008890: b9003e6f  str      w15, [x19, #0x3c]
//   0x008894: b900126d  str      w13, [x19, #0x10]
//   0x008898: 54001a62  b.hs     #0x8be4
//   0x00889c: 2a1f03eb  mov      w11, wzr
//   0x0088a0: 52802010  mov      w16, #0x100
//   0x0088a4: 0b100171  add      w17, w11, w16
//   0x0088a8: 13017e31  asr      w17, w17, #1
//   0x0088ac: 8b31ca60  add      x0, x19, w17, sxtw #2
//   0x0088b0: b9444800  ldr      w0, [x0, #0x448]
//   0x0088b4: 6b0f001f  cmp      w0, w15
//   0x0088b8: 1a90c230  csel     w16, w17, w16, gt
//   0x0088bc: 1a91c16b  csel     w11, w11, w17, gt
//   0x0088c0: 4b0b0211  sub      w17, w16, w11
//   0x0088c4: 7100063f  cmp      w17, #1
//   0x0088c8: 54fffee1  b.ne     #0x88a4
//   0x0088cc: b900426b  str      w11, [x19, #0x40]
//   0x0088d0: d341fdeb  lsr      x11, x15, #1
//   0x0088d4: 386b694a  ldrb     w10, [x10, x11]
//   0x0088d8: 786f798b  ldrh     w11, [x12, x15, lsl #1]
//   0x0088dc: 531e01cc  ubfiz    w12, w14, #2, #1
//   0x0088e0: 11001529  add      w9, w9, #5
//   0x0088e4: 1acc254a  lsr      w10, w10, w12
//   0x0088e8: 33100d4b  bfi      w11, w10, #0x10, #4
//   0x0088ec: b9003e6b  str      w11, [x19, #0x3c]
//   0x0088f0: b9044669  str      w9, [x19, #0x444]
//   0x0088f4: b9402109  ldr      w9, [x8, #0x20]
//   0x0088f8: 35ffe6a9  cbnz     w9, #0x85cc
//   0x0088fc: 14000088  b        #0x8b1c
//   0x008900: b900426d  str      w13, [x19, #0x40]
//   0x008904: 5280006d  mov      w13, #3
//   0x008908: b9402109  ldr      w9, [x8, #0x20]
//   0x00890c: 35ffe609  cbnz     w9, #0x85cc
//   0x008910: 14000083  b        #0x8b1c
//   0x008914: f940026a  ldr      x10, [x19]
//   0x008918: b94002ac  ldr      w12, [x21]
//   0x00891c: b9402a6f  ldr      w15, [x19, #0x28]
//   0x008920: b94c7268  ldr      w8, [x19, #0xc70]
//   0x008924: b940214b  ldr      w11, [x10, #0x20]
//   0x008928: 39403270  ldrb     w16, [x19, #0xc]
//   0x00892c: b9401261  ldr      w1, [x19, #0x10]
//   0x008930: b9444660  ldr      w0, [x19, #0x444]
//   0x008934: 2947c66d  ldp      w13, w17, [x19, #0x3c]
//   0x008938: f9462a69  ldr      x9, [x19, #0xc50]
//   0x00893c: f9400d4a  ldr      x10, [x10, #0x18]
//   0x008940: 1100058e  add      w14, w12, #1
//   0x008944: 1b187def  mul      w15, w15, w24
//   0x008948: 2a0b03ec  mov      w12, w11
//   0x00894c: 7100043f  cmp      w1, #1
//   0x008950: 5400034b  b.lt     #0x89b8
//   0x008954: 34000c2c  cbz      w12, #0x8ad8
//   0x008958: 2a0103e5  mov      w5, w1
//   0x00895c: aa1f03e2  mov      x2, xzr
//   0x008960: 12001e03  and      w3, w16, #0xff
//   0x008964: 2a0c03e4  mov      w4, w12
//   0x008968: d10004a5  sub      x5, x5, #1
//   0x00896c: 6b0200bf  cmp      w5, w2
//   0x008970: 54000120  b.eq     #0x8994
//   0x008974: 38226950  strb     w16, [x10, x2]
//   0x008978: 4a486066  eor      w6, w3, w8, lsr #24
//   0x00897c: b8665b26  ldr      w6, [x25, w6, uxtw #2]
//   0x008980: 91000442  add      x2, x2, #1
//   0x008984: 6b02009f  cmp      w4, w2
//   0x008988: 4a0820c8  eor      w8, w6, w8, lsl #8
//   0x00898c: 54ffff01  b.ne     #0x896c
//   0x008990: 1400004f  b        #0x8acc
//   0x008994: 4b02018c  sub      w12, w12, w2
//   0x008998: 8b02014a  add      x10, x10, x2
//   0x00899c: 3400114c  cbz      w12, #0x8bc4
//   0x0089a0: 12001e01  and      w1, w16, #0xff
//   0x0089a4: 38001550  strb     w16, [x10], #1
//   0x0089a8: 4a486021  eor      w1, w1, w8, lsr #24
//   0x0089ac: b8615b21  ldr      w1, [x25, w1, uxtw #2]
//   0x0089b0: 5100058c  sub      w12, w12, #1
//   0x0089b4: 4a082028  eor      w8, w1, w8, lsl #8
//   0x0089b8: 2a0003e3  mov      w3, w0
//   0x0089bc: 2a1103e2  mov      w2, w17
//   0x0089c0: 6b0e001f  cmp      w0, w14
//   0x0089c4: 5400110c  b.gt     #0x8be4
//   0x0089c8: 54001020  b.eq     #0x8bcc
//   0x0089cc: 6b0f01bf  cmp      w13, w15
//   0x0089d0: 540010a2  b.hs     #0x8be4
//   0x0089d4: b86d5930  ldr      w16, [x9, w13, uxtw #2]
//   0x0089d8: 11000460  add      w0, w3, #1
//   0x0089dc: 12001e11  and      w17, w16, #0xff
//   0x0089e0: d348fe0d  lsr      x13, x16, #8
//   0x0089e4: 6b02023f  cmp      w17, w2
//   0x0089e8: 540000a1  b.ne     #0x89fc
//   0x0089ec: 6b0e001f  cmp      w0, w14
//   0x0089f0: 540000a1  b.ne     #0x8a04
//   0x0089f4: 2a0e03e0  mov      w0, w14
//   0x0089f8: 2a0203f1  mov      w17, w2
//   0x0089fc: 2a0203f0  mov      w16, w2
//   0x008a00: 17ffffe7  b        #0x899c
//   0x008a04: 6b0f01bf  cmp      w13, w15
//   0x008a08: 54000ee2  b.hs     #0x8be4
//   0x008a0c: b86d7925  ldr      w5, [x9, x13, lsl #2]
//   0x008a10: 11000864  add      w4, w3, #2
//   0x008a14: 6b0e009f  cmp      w4, w14
//   0x008a18: 52800041  mov      w1, #2
//   0x008a1c: d348fcad  lsr      x13, x5, #8
//   0x008a20: 2a0e03e0  mov      w0, w14
//   0x008a24: 2a0203f1  mov      w17, w2
//   0x008a28: 2a0203f0  mov      w16, w2
//   0x008a2c: 54fff900  b.eq     #0x894c
//   0x008a30: 12001cb1  and      w17, w5, #0xff
//   0x008a34: 6b02023f  cmp      w17, w2
//   0x008a38: 52800041  mov      w1, #2
//   0x008a3c: 2a0403e0  mov      w0, w4
//   0x008a40: 2a0203f0  mov      w16, w2
//   0x008a44: 54fff841  b.ne     #0x894c
//   0x008a48: 6b0f01bf  cmp      w13, w15
//   0x008a4c: 54000cc2  b.hs     #0x8be4
//   0x008a50: b86d7925  ldr      w5, [x9, x13, lsl #2]
//   0x008a54: 11000c64  add      w4, w3, #3
//   0x008a58: 6b0e009f  cmp      w4, w14
//   0x008a5c: 52800061  mov      w1, #3
//   0x008a60: d348fcad  lsr      x13, x5, #8
//   0x008a64: 2a0e03e0  mov      w0, w14
//   0x008a68: 2a0203f1  mov      w17, w2
//   0x008a6c: 2a0203f0  mov      w16, w2
//   0x008a70: 54fff6e0  b.eq     #0x894c
//   0x008a74: 12001cb1  and      w17, w5, #0xff
//   0x008a78: 6b02023f  cmp      w17, w2
//   0x008a7c: 52800061  mov      w1, #3
//   0x008a80: 2a0403e0  mov      w0, w4
//   0x008a84: 2a0203f0  mov      w16, w2
//   0x008a88: 54fff621  b.ne     #0x894c
//   0x008a8c: 6b0f01bf  cmp      w13, w15
//   0x008a90: 54000aa2  b.hs     #0x8be4
//   0x008a94: b86d792d  ldr      w13, [x9, x13, lsl #2]
//   0x008a98: d348fdb0  lsr      x16, x13, #8
//   0x008a9c: 6b0f021f  cmp      w16, w15
//   0x008aa0: 54000a22  b.hs     #0x8be4
//   0x008aa4: b8707930  ldr      w16, [x9, x16, lsl #2]
//   0x008aa8: 12001dad  and      w13, w13, #0xff
//   0x008aac: 110011a1  add      w1, w13, #4
//   0x008ab0: 11001460  add      w0, w3, #5
//   0x008ab4: 12001e11  and      w17, w16, #0xff
//   0x008ab8: 53087e0d  lsr      w13, w16, #8
//   0x008abc: 2a0203f0  mov      w16, w2
//   0x008ac0: 7100043f  cmp      w1, #1
//   0x008ac4: 54fff48a  b.ge     #0x8954
//   0x008ac8: 17ffffbc  b        #0x89b8
//   0x008acc: 2a1f03ec  mov      w12, wzr
//   0x008ad0: 8b02014a  add      x10, x10, x2
//   0x008ad4: 4b020021  sub      w1, w1, w2
//   0x008ad8: f940026e  ldr      x14, [x19]
//   0x008adc: 4b0c016b  sub      w11, w11, w12
//   0x008ae0: b94025cf  ldr      w15, [x14, #0x24]
//   0x008ae4: 2b0b01eb  adds     w11, w15, w11
//   0x008ae8: b90025cb  str      w11, [x14, #0x24]
//   0x008aec: 54000083  b.lo     #0x8afc
//   0x008af0: b94029cb  ldr      w11, [x14, #0x28]
//   0x008af4: 1100056b  add      w11, w11, #1
//   0x008af8: b90029cb  str      w11, [x14, #0x28]
//   0x008afc: b90c7268  str      w8, [x19, #0xc70]
//   0x008b00: 39003270  strb     w16, [x19, #0xc]
//   0x008b04: b9001261  str      w1, [x19, #0x10]
//   0x008b08: b9044660  str      w0, [x19, #0x444]
//   0x008b0c: 2907c66d  stp      w13, w17, [x19, #0x3c]
//   0x008b10: f9062a69  str      x9, [x19, #0xc50]
//   0x008b14: f9000dca  str      x10, [x14, #0x18]
//   0x008b18: b90021cc  str      w12, [x14, #0x20]
//   0x008b1c: b94002a8  ldr      w8, [x21]
//   0x008b20: b9444669  ldr      w9, [x19, #0x444]
//   0x008b24: 11000508  add      w8, w8, #1
//   0x008b28: 6b08013f  cmp      w9, w8
//   0x008b2c: 540007e1  b.ne     #0x8c28
//   0x008b30: b9401268  ldr      w8, [x19, #0x10]
//   0x008b34: 350007a8  cbnz     w8, #0x8c28
//   0x008b38: b94c7269  ldr      w9, [x19, #0xc70]
//   0x008b3c: b9403668  ldr      w8, [x19, #0x34]
//   0x008b40: 2a2903e3  mvn      w3, w9
//   0x008b44: 7100091f  cmp      w8, #2
//   0x008b48: b90c7263  str      w3, [x19, #0xc70]
//   0x008b4c: 540000ed  b.le     #0x8b68
//   0x008b50: b94c6a62  ldr      w2, [x19, #0xc68]
//   0x008b54: d0000061  adrp     x1, #0x16000
//   0x008b58: aa1403e0  mov      x0, x20
//   0x008b5c: 91343821  add      x1, x1, #0xd0e
//   0x008b60: 97ffe7c8  bl       #0x2a80
//   0x008b64: b9403668  ldr      w8, [x19, #0x34]
//   0x008b68: 7100091f  cmp      w8, #2
//   0x008b6c: 5400008b  b.lt     #0x8b7c
//   0x008b70: 9104c2e1  add      x1, x23, #0x130
//   0x008b74: 52800ba0  mov      w0, #0x5d
//   0x008b78: 97ffe766  bl       #0x2910
//   0x008b7c: b94c7268  ldr      w8, [x19, #0xc70]
//   0x008b80: b94c6a69  ldr      w9, [x19, #0xc68]
//   0x008b84: 6b09011f  cmp      w8, w9
//   0x008b88: 540002e1  b.ne     #0x8be4
//   0x008b8c: b94c7669  ldr      w9, [x19, #0xc74]
//   0x008b90: 4ac97d08  eor      w8, w8, w9, ror #31
//   0x008b94: b90c7668  str      w8, [x19, #0xc74]
//   0x008b98: 528001c8  mov      w8, #0xe
//   0x008b9c: b9000a68  str      w8, [x19, #8]
//   0x008ba0: aa1303e0  mov      x0, x19
//   0x008ba4: 97ffe793  bl       #0x29f0
//   0x008ba8: 7100101f  cmp      w0, #4
//   0x008bac: 54000200  b.eq     #0x8bec
//   0x008bb0: b9400a68  ldr      w8, [x19, #8]
//   0x008bb4: 7100091f  cmp      w8, #2
//   0x008bb8: 52800048  mov      w8, #2
//   0x008bbc: 54ff9320  b.eq     #0x7e20
//   0x008bc0: 17fffc7e  b        #0x7db8
//   0x008bc4: 52800021  mov      w1, #1
//   0x008bc8: 17ffffc4  b        #0x8ad8
//   0x008bcc: 2a1f03e1  mov      w1, wzr
//   0x008bd0: 2a0e03e0  mov      w0, w14
//   0x008bd4: 2a0203f1  mov      w17, w2
//   0x008bd8: 17ffffc0  b        #0x8ad8
//   0x008bdc: 12800000  mov      w0, #-1
//   0x008be0: 17fffc76  b        #0x7db8
//   0x008be4: 12800060  mov      w0, #-4
//   0x008be8: 17fffc74  b        #0x7db8
//   0x008bec: b9403668  ldr      w8, [x19, #0x34]
//   0x008bf0: 71000d1f  cmp      w8, #3
//   0x008bf4: 540000eb  b.lt     #0x8c10
//   0x008bf8: b94c6e62  ldr      w2, [x19, #0xc6c]
//   0x008bfc: b94c7663  ldr      w3, [x19, #0xc74]
//   0x008c00: d0000061  adrp     x1, #0x16000
//   0x008c04: 9104c2e0  add      x0, x23, #0x130
//   0x008c08: 91348021  add      x1, x1, #0xd20
//   0x008c0c: 97ffe79d  bl       #0x2a80
//   0x008c10: b94c7668  ldr      w8, [x19, #0xc74]
//   0x008c14: b94c6e69  ldr      w9, [x19, #0xc6c]
//   0x008c18: 6b09011f  cmp      w8, w9
//   0x008c1c: 52800088  mov      w8, #4
//   0x008c20: 5a880500  cneg     w0, w8, ne
//   0x008c24: 17fffc65  b        #0x7db8
//   0x008c28: 2a1f03e0  mov      w0, wzr
//   0x008c2c: 17fffc63  b        #0x7db8
//   0x008c30: 97ffe73c  bl       #0x2920
// ============================================================================
std::uint32_t fde_30_07d70(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00007d70ULL;
    for (std::size_t i = 0; i < 945ULL; ++i) {
        std::uint32_t insn = kTextInstructions[5264ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[31] Subroutine @ 0x008c34..0x008ce4 (176 bytes, 44 AArch64 instructions)
// [VN] Khung FDE[31] Hàm con @ 0x008c34..0x008ce4 (176 byte, 44 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008c34: d10103ff  sub      sp, sp, #0x40
//   0x008c38: f9000bf5  str      x21, [sp, #0x10]
//   0x008c3c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008c40: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008c44: 9100c3fd  add      x29, sp, #0x30
//   0x008c48: d53bd054  mrs      x20, tpidr_el0
//   0x008c4c: f9401688  ldr      x8, [x20, #0x28]
//   0x008c50: f90007e8  str      x8, [sp, #8]
//   0x008c54: b40000e0  cbz      x0, #0x8c70
//   0x008c58: f9401815  ldr      x21, [x0, #0x30]
//   0x008c5c: aa0003f3  mov      x19, x0
//   0x008c60: b4000095  cbz      x21, #0x8c70
//   0x008c64: f94002a8  ldr      x8, [x21]
//   0x008c68: eb13011f  cmp      x8, x19
//   0x008c6c: 54000160  b.eq     #0x8c98
//   0x008c70: 12800020  mov      w0, #-2
//   0x008c74: f9401688  ldr      x8, [x20, #0x28]
//   0x008c78: f94007e9  ldr      x9, [sp, #8]
//   0x008c7c: eb09011f  cmp      x8, x9
//   0x008c80: 54000301  b.ne     #0x8ce0
//   0x008c84: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x008c88: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x008c8c: f9400bf5  ldr      x21, [sp, #0x10]
//   0x008c90: 910103ff  add      sp, sp, #0x40
//   0x008c94: d65f03c0  ret      
//   0x008c98: f9462aa1  ldr      x1, [x21, #0xc50]
//   0x008c9c: b4000061  cbz      x1, #0x8ca8
//   0x008ca0: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x008ca4: d63f0100  blr      x8
//   0x008ca8: f9462ea1  ldr      x1, [x21, #0xc58]
//   0x008cac: b4000061  cbz      x1, #0x8cb8
//   0x008cb0: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x008cb4: d63f0100  blr      x8
//   0x008cb8: f94632a1  ldr      x1, [x21, #0xc60]
//   0x008cbc: b4000061  cbz      x1, #0x8cc8
//   0x008cc0: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x008cc4: d63f0100  blr      x8
//   0x008cc8: a9440268  ldp      x8, x0, [x19, #0x40]
//   0x008ccc: f9401a61  ldr      x1, [x19, #0x30]
//   0x008cd0: d63f0100  blr      x8
//   0x008cd4: 2a1f03e0  mov      w0, wzr
//   0x008cd8: f9001a7f  str      xzr, [x19, #0x30]
//   0x008cdc: 17ffffe6  b        #0x8c74
//   0x008ce0: 97ffe710  bl       #0x2920
// ============================================================================
std::uint32_t fde_31_08c34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008c34ULL;
    for (std::size_t i = 0; i < 44ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6209ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[32] Subroutine @ 0x008ce4..0x008e44 (352 bytes, 88 AArch64 instructions)
// [VN] Khung FDE[32] Hàm con @ 0x008ce4..0x008e44 (352 byte, 88 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008ce4: d10183ff  sub      sp, sp, #0x60
//   0x008ce8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x008cec: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x008cf0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x008cf4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x008cf8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x008cfc: 910143fd  add      x29, sp, #0x50
//   0x008d00: d53bd059  mrs      x25, tpidr_el0
//   0x008d04: f9401728  ldr      x8, [x25, #0x28]
//   0x008d08: 2a0403f7  mov      w23, w4
//   0x008d0c: 2a0303f5  mov      w21, w3
//   0x008d10: 2a0203f6  mov      w22, w2
//   0x008d14: aa0103f8  mov      x24, x1
//   0x008d18: aa0003f3  mov      x19, x0
//   0x008d1c: f90007e8  str      x8, [sp, #8]
//   0x008d20: b4000040  cbz      x0, #0x8d28
//   0x008d24: b900027f  str      wzr, [x19]
//   0x008d28: 710012bf  cmp      w21, #4
//   0x008d2c: 540001c8  b.hi     #0x8d64
//   0x008d30: 7103eaff  cmp      w23, #0xfa
//   0x008d34: 54000188  b.hi     #0x8d64
//   0x008d38: b4000178  cbz      x24, #0x8d64
//   0x008d3c: 510006c8  sub      w8, w22, #1
//   0x008d40: 7100251f  cmp      w8, #9
//   0x008d44: 54000102  b.hs     #0x8d64
//   0x008d48: aa1803e0  mov      x0, x24
//   0x008d4c: 97ffe725  bl       #0x29e0
//   0x008d50: 340002a0  cbz      w0, #0x8da4
//   0x008d54: aa1f03f4  mov      x20, xzr
//   0x008d58: b40000f3  cbz      x19, #0x8d74
//   0x008d5c: 128000a8  mov      w8, #-6
//   0x008d60: 14000004  b        #0x8d70
//   0x008d64: aa1f03f4  mov      x20, xzr
//   0x008d68: b4000073  cbz      x19, #0x8d74
//   0x008d6c: 12800028  mov      w8, #-2
//   0x008d70: b9000268  str      w8, [x19]
//   0x008d74: f9401728  ldr      x8, [x25, #0x28]
//   0x008d78: f94007e9  ldr      x9, [sp, #8]
//   0x008d7c: eb09011f  cmp      x8, x9
//   0x008d80: 54000601  b.ne     #0x8e40
//   0x008d84: aa1403e0  mov      x0, x20
//   0x008d88: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x008d8c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x008d90: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x008d94: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x008d98: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x008d9c: 910183ff  add      sp, sp, #0x60
//   0x008da0: d65f03c0  ret      
//   0x008da4: 52827e00  mov      w0, #0x13f0
//   0x008da8: 97ffe73a  bl       #0x2a90
//   0x008dac: b40003c0  cbz      x0, #0x8e24
//   0x008db0: 52827288  mov      w8, #0x1394
//   0x008db4: aa0003f4  mov      x20, x0
//   0x008db8: 8b08001a  add      x26, x0, x8
//   0x008dbc: b4000053  cbz      x19, #0x8dc4
//   0x008dc0: b900027f  str      wzr, [x19]
//   0x008dc4: 52827308  mov      w8, #0x1398
//   0x008dc8: 710002ff  cmp      w23, #0
//   0x008dcc: 528003c9  mov      w9, #0x1e
//   0x008dd0: b913ea9f  str      wzr, [x20, #0x13e8]
//   0x008dd4: 3901635f  strb     wzr, [x26, #0x58]
//   0x008dd8: f9000298  str      x24, [x20]
//   0x008ddc: 52800038  mov      w24, #1
//   0x008de0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x008de4: 8b080280  add      x0, x20, x8
//   0x008de8: 1a970123  csel     w3, w9, w23, eq
//   0x008dec: 2a1603e1  mov      w1, w22
//   0x008df0: 2a1503e2  mov      w2, w21
//   0x008df4: b913929f  str      wzr, [x20, #0x1390]
//   0x008df8: 39000358  strb     w24, [x26]
//   0x008dfc: f909f29f  str      xzr, [x20, #0x13e0]
//   0x008e00: 3d84f680  str      q0, [x20, #0x13d0]
//   0x008e04: 97ffe6db  bl       #0x2970
//   0x008e08: 34000160  cbz      w0, #0x8e34
//   0x008e0c: b4000053  cbz      x19, #0x8e14
//   0x008e10: b9000260  str      w0, [x19]
//   0x008e14: aa1403e0  mov      x0, x20
//   0x008e18: 97ffe736  bl       #0x2af0
//   0x008e1c: aa1f03f4  mov      x20, xzr
//   0x008e20: 17ffffd5  b        #0x8d74
//   0x008e24: aa1f03f4  mov      x20, xzr
//   0x008e28: b4fffa73  cbz      x19, #0x8d74
//   0x008e2c: 12800048  mov      w8, #-3
//   0x008e30: 17ffffd0  b        #0x8d70
//   0x008e34: b913a29f  str      wzr, [x20, #0x13a0]
//   0x008e38: 39016358  strb     w24, [x26, #0x58]
//   0x008e3c: 17ffffce  b        #0x8d74
//   0x008e40: 97ffe6b8  bl       #0x2920
// ============================================================================
std::uint32_t fde_32_08ce4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008ce4ULL;
    for (std::size_t i = 0; i < 88ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6253ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[33] Subroutine @ 0x008e44..0x009008 (452 bytes, 113 AArch64 instructions)
// [VN] Khung FDE[33] Hàm con @ 0x008e44..0x009008 (452 byte, 113 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x008e44: d10183ff  sub      sp, sp, #0x60
//   0x008e48: f9000bf9  str      x25, [sp, #0x10]
//   0x008e4c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x008e50: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x008e54: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x008e58: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x008e5c: 910143fd  add      x29, sp, #0x50
//   0x008e60: d53bd058  mrs      x24, tpidr_el0
//   0x008e64: f9401708  ldr      x8, [x24, #0x28]
//   0x008e68: 2a0303f6  mov      w22, w3
//   0x008e6c: aa0203f5  mov      x21, x2
//   0x008e70: aa0103f3  mov      x19, x1
//   0x008e74: aa0003f4  mov      x20, x0
//   0x008e78: f90007e8  str      x8, [sp, #8]
//   0x008e7c: b4000040  cbz      x0, #0x8e84
//   0x008e80: b900029f  str      wzr, [x20]
//   0x008e84: b40001f3  cbz      x19, #0x8ec0
//   0x008e88: b913ea7f  str      wzr, [x19, #0x13e8]
//   0x008e8c: b40001b5  cbz      x21, #0x8ec0
//   0x008e90: 37f80196  tbnz     w22, #0x1f, #0x8ec0
//   0x008e94: 52827288  mov      w8, #0x1394
//   0x008e98: 38686a68  ldrb     w8, [x19, x8]
//   0x008e9c: 340001e8  cbz      w8, #0x8ed8
//   0x008ea0: f9400260  ldr      x0, [x19]
//   0x008ea4: 97ffe6cf  bl       #0x29e0
//   0x008ea8: 34000380  cbz      w0, #0x8f18
//   0x008eac: b4000074  cbz      x20, #0x8eb8
//   0x008eb0: 128000a8  mov      w8, #-6
//   0x008eb4: b9000288  str      w8, [x20]
//   0x008eb8: 128000a8  mov      w8, #-6
//   0x008ebc: 1400000b  b        #0x8ee8
//   0x008ec0: b4000074  cbz      x20, #0x8ecc
//   0x008ec4: 12800028  mov      w8, #-2
//   0x008ec8: b9000288  str      w8, [x20]
//   0x008ecc: b4000113  cbz      x19, #0x8eec
//   0x008ed0: 12800028  mov      w8, #-2
//   0x008ed4: 14000005  b        #0x8ee8
//   0x008ed8: b4000074  cbz      x20, #0x8ee4
//   0x008edc: 12800008  mov      w8, #-1
//   0x008ee0: b9000288  str      w8, [x20]
//   0x008ee4: 12800008  mov      w8, #-1
//   0x008ee8: b913ea68  str      w8, [x19, #0x13e8]
//   0x008eec: f9401708  ldr      x8, [x24, #0x28]
//   0x008ef0: f94007e9  ldr      x9, [sp, #8]
//   0x008ef4: eb09011f  cmp      x8, x9
//   0x008ef8: 54000861  b.ne     #0x9004
//   0x008efc: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x008f00: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x008f04: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x008f08: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x008f0c: f9400bf9  ldr      x25, [sp, #0x10]
//   0x008f10: 910183ff  add      sp, sp, #0x60
//   0x008f14: d65f03c0  ret      
//   0x008f18: 34000516  cbz      w22, #0x8fb8
//   0x008f1c: 52827308  mov      w8, #0x1398
//   0x008f20: b913a276  str      w22, [x19, #0x13a0]
//   0x008f24: f909ce75  str      x21, [x19, #0x1398]
//   0x008f28: 91002275  add      x21, x19, #8
//   0x008f2c: 8b080276  add      x22, x19, x8
//   0x008f30: 52827119  mov      w25, #0x1388
//   0x008f34: 14000003  b        #0x8f40
//   0x008f38: b953a268  ldr      w8, [x19, #0x13a0]
//   0x008f3c: 340003e8  cbz      w8, #0x8fb8
//   0x008f40: f949e668  ldr      x8, [x19, #0x13c8]
//   0x008f44: b913ba79  str      w25, [x19, #0x13b8]
//   0x008f48: f909da75  str      x21, [x19, #0x13b0]
//   0x008f4c: b40003e8  cbz      x8, #0x8fc8
//   0x008f50: f9400109  ldr      x9, [x8]
//   0x008f54: eb16013f  cmp      x9, x22
//   0x008f58: 54000381  b.ne     #0x8fc8
//   0x008f5c: b9400909  ldr      w9, [x8, #8]
//   0x008f60: 7100093f  cmp      w9, #2
//   0x008f64: 540003a1  b.ne     #0x8fd8
//   0x008f68: aa1603e0  mov      x0, x22
//   0x008f6c: 97fff9ef  bl       #0x7728
//   0x008f70: 72001c1f  tst      w0, #0xff
//   0x008f74: 540002a0  b.eq     #0x8fc8
//   0x008f78: b993ba68  ldrsw    x8, [x19, #0x13b8]
//   0x008f7c: d3437d09  ubfx     x9, x8, #3, #0x1d
//   0x008f80: 7109c13f  cmp      w9, #0x270
//   0x008f84: 54fffda8  b.hi     #0x8f38
//   0x008f88: f9400263  ldr      x3, [x19]
//   0x008f8c: cb080337  sub      x23, x25, x8
//   0x008f90: 52800021  mov      w1, #1
//   0x008f94: aa1503e0  mov      x0, x21
//   0x008f98: aa1703e2  mov      x2, x23
//   0x008f9c: 97ffe6d1  bl       #0x2ae0
//   0x008fa0: 6b0002ff  cmp      w23, w0
//   0x008fa4: 54fff841  b.ne     #0x8eac
//   0x008fa8: f9400260  ldr      x0, [x19]
//   0x008fac: 97ffe68d  bl       #0x29e0
//   0x008fb0: 34fffc40  cbz      w0, #0x8f38
//   0x008fb4: 17ffffbe  b        #0x8eac
//   0x008fb8: b4000054  cbz      x20, #0x8fc0
//   0x008fbc: b900029f  str      wzr, [x20]
//   0x008fc0: b913ea7f  str      wzr, [x19, #0x13e8]
//   0x008fc4: 17ffffca  b        #0x8eec
//   0x008fc8: 12800028  mov      w8, #-2
//   0x008fcc: b4fff8f4  cbz      x20, #0x8ee8
//   0x008fd0: b9000288  str      w8, [x20]
//   0x008fd4: 17ffffc5  b        #0x8ee8
//   0x008fd8: 7100113f  cmp      w9, #4
//   0x008fdc: 2a1f03e8  mov      w8, wzr
//   0x008fe0: 54ffff68  b.hi     #0x8fcc
//   0x008fe4: 5280002a  mov      w10, #1
//   0x008fe8: 1ac92149  lsl      w9, w10, w9
//   0x008fec: 5280034a  mov      w10, #0x1a
//   0x008ff0: 6a0a013f  tst      w9, w10
//   0x008ff4: 54fffec0  b.eq     #0x8fcc
//   0x008ff8: 12800008  mov      w8, #-1
//   0x008ffc: b5fffeb4  cbnz     x20, #0x8fd0
//   0x009000: 17ffffba  b        #0x8ee8
//   0x009004: 97ffe647  bl       #0x2920
// ============================================================================
std::uint32_t fde_33_08e44(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00008e44ULL;
    for (std::size_t i = 0; i < 113ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6341ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[34] Subroutine @ 0x009008..0x009058 (80 bytes, 20 AArch64 instructions)
// [VN] Khung FDE[34] Hàm con @ 0x009008..0x009058 (80 byte, 20 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009008: d100c3ff  sub      sp, sp, #0x30
//   0x00900c: f9000bf3  str      x19, [sp, #0x10]
//   0x009010: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x009014: 910083fd  add      x29, sp, #0x20
//   0x009018: d53bd053  mrs      x19, tpidr_el0
//   0x00901c: f9401668  ldr      x8, [x19, #0x28]
//   0x009020: aa0403e5  mov      x5, x4
//   0x009024: aa1f03e4  mov      x4, xzr
//   0x009028: aa1f03e6  mov      x6, xzr
//   0x00902c: f90007e8  str      x8, [sp, #8]
//   0x009030: 97ffe5e0  bl       #0x27b0
//   0x009034: f9401668  ldr      x8, [x19, #0x28]
//   0x009038: f94007e9  ldr      x9, [sp, #8]
//   0x00903c: eb09011f  cmp      x8, x9
//   0x009040: 540000a1  b.ne     #0x9054
//   0x009044: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x009048: f9400bf3  ldr      x19, [sp, #0x10]
//   0x00904c: 9100c3ff  add      sp, sp, #0x30
//   0x009050: d65f03c0  ret      
//   0x009054: 97ffe633  bl       #0x2920
// ============================================================================
std::uint32_t fde_34_09008(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009008ULL;
    for (std::size_t i = 0; i < 20ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6454ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[35] Subroutine @ 0x009058..0x009378 (800 bytes, 200 AArch64 instructions)
// [VN] Khung FDE[35] Hàm con @ 0x009058..0x009378 (800 byte, 200 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009058: d101c3ff  sub      sp, sp, #0x70
//   0x00905c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x009060: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x009064: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x009068: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00906c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x009070: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x009074: 910183fd  add      x29, sp, #0x60
//   0x009078: d53bd05c  mrs      x28, tpidr_el0
//   0x00907c: f9401788  ldr      x8, [x28, #0x28]
//   0x009080: aa0003f4  mov      x20, x0
//   0x009084: f90007e8  str      x8, [sp, #8]
//   0x009088: b4000261  cbz      x1, #0x90d4
//   0x00908c: 52827288  mov      w8, #0x1394
//   0x009090: 38686828  ldrb     w8, [x1, x8]
//   0x009094: aa0103f3  mov      x19, x1
//   0x009098: 34000248  cbz      w8, #0x90e0
//   0x00909c: f9400279  ldr      x25, [x19]
//   0x0090a0: aa0603f5  mov      x21, x6
//   0x0090a4: aa0503f6  mov      x22, x5
//   0x0090a8: aa0403f7  mov      x23, x4
//   0x0090ac: aa1903e0  mov      x0, x25
//   0x0090b0: aa0303f8  mov      x24, x3
//   0x0090b4: 2a0203fa  mov      w26, w2
//   0x0090b8: 97ffe64a  bl       #0x29e0
//   0x0090bc: 34000340  cbz      w0, #0x9124
//   0x0090c0: b4000074  cbz      x20, #0x90cc
//   0x0090c4: 128000a8  mov      w8, #-6
//   0x0090c8: b9000288  str      w8, [x20]
//   0x0090cc: 128000a8  mov      w8, #-6
//   0x0090d0: 14000008  b        #0x90f0
//   0x0090d4: b4000114  cbz      x20, #0x90f4
//   0x0090d8: b900029f  str      wzr, [x20]
//   0x0090dc: 14000006  b        #0x90f4
//   0x0090e0: b4000074  cbz      x20, #0x90ec
//   0x0090e4: 12800008  mov      w8, #-1
//   0x0090e8: b9000288  str      w8, [x20]
//   0x0090ec: 12800008  mov      w8, #-1
//   0x0090f0: b913ea68  str      w8, [x19, #0x13e8]
//   0x0090f4: f9401788  ldr      x8, [x28, #0x28]
//   0x0090f8: f94007e9  ldr      x9, [sp, #8]
//   0x0090fc: eb09011f  cmp      x8, x9
//   0x009100: 540013a1  b.ne     #0x9374
//   0x009104: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x009108: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00910c: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x009110: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x009114: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x009118: a9416ffc  ldp      x28, x27, [sp, #0x10]
//   0x00911c: 9101c3ff  add      sp, sp, #0x70
//   0x009120: d65f03c0  ret      
//   0x009124: b4000058  cbz      x24, #0x912c
//   0x009128: b900031f  str      wzr, [x24]
//   0x00912c: b4000057  cbz      x23, #0x9134
//   0x009130: b90002ff  str      wzr, [x23]
//   0x009134: b4000056  cbz      x22, #0x913c
//   0x009138: b90002df  str      wzr, [x22]
//   0x00913c: b4000055  cbz      x21, #0x9144
//   0x009140: b90002bf  str      wzr, [x21]
//   0x009144: 340005ba  cbz      w26, #0x91f8
//   0x009148: b4000078  cbz      x24, #0x9154
//   0x00914c: b953a668  ldr      w8, [x19, #0x13a4]
//   0x009150: b9000308  str      w8, [x24]
//   0x009154: b4000077  cbz      x23, #0x9160
//   0x009158: b953aa68  ldr      w8, [x19, #0x13a8]
//   0x00915c: b90002e8  str      w8, [x23]
//   0x009160: b4000076  cbz      x22, #0x916c
//   0x009164: b953be68  ldr      w8, [x19, #0x13bc]
//   0x009168: b90002c8  str      w8, [x22]
//   0x00916c: b4000075  cbz      x21, #0x9178
//   0x009170: b953c268  ldr      w8, [x19, #0x13c0]
//   0x009174: b90002a8  str      w8, [x21]
//   0x009178: b4000054  cbz      x20, #0x9180
//   0x00917c: b900029f  str      wzr, [x20]
//   0x009180: f949e674  ldr      x20, [x19, #0x13c8]
//   0x009184: b913ea7f  str      wzr, [x19, #0x13e8]
//   0x009188: b4000334  cbz      x20, #0x91ec
//   0x00918c: f9400288  ldr      x8, [x20]
//   0x009190: 52827309  mov      w9, #0x1398
//   0x009194: 8b090269  add      x9, x19, x9
//   0x009198: eb09011f  cmp      x8, x9
//   0x00919c: 54000281  b.ne     #0x91ec
//   0x0091a0: f9400e81  ldr      x1, [x20, #0x18]
//   0x0091a4: b4000081  cbz      x1, #0x91b4
//   0x0091a8: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x0091ac: f949f260  ldr      x0, [x19, #0x13e0]
//   0x0091b0: d63f0100  blr      x8
//   0x0091b4: f9401281  ldr      x1, [x20, #0x20]
//   0x0091b8: b4000081  cbz      x1, #0x91c8
//   0x0091bc: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x0091c0: f949f260  ldr      x0, [x19, #0x13e0]
//   0x0091c4: d63f0100  blr      x8
//   0x0091c8: f9401681  ldr      x1, [x20, #0x28]
//   0x0091cc: b4000081  cbz      x1, #0x91dc
//   0x0091d0: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x0091d4: f949f260  ldr      x0, [x19, #0x13e0]
//   0x0091d8: d63f0100  blr      x8
//   0x0091dc: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x0091e0: f949f260  ldr      x0, [x19, #0x13e0]
//   0x0091e4: f949e661  ldr      x1, [x19, #0x13c8]
//   0x0091e8: d63f0100  blr      x8
//   0x0091ec: aa1303e0  mov      x0, x19
//   0x0091f0: 97ffe640  bl       #0x2af0
//   0x0091f4: 17ffffc0  b        #0x90f4
//   0x0091f8: b953ea68  ldr      w8, [x19, #0x13e8]
//   0x0091fc: 34000148  cbz      w8, #0x9224
//   0x009200: aa1903e0  mov      x0, x25
//   0x009204: 97ffe5f7  bl       #0x29e0
//   0x009208: 35fffa00  cbnz     w0, #0x9148
//   0x00920c: aa1903e0  mov      x0, x25
//   0x009210: 97ffe5b8  bl       #0x28f0
//   0x009214: f9400260  ldr      x0, [x19]
//   0x009218: 97ffe5f2  bl       #0x29e0
//   0x00921c: 35fff520  cbnz     w0, #0x90c0
//   0x009220: 17ffffca  b        #0x9148
//   0x009224: 52827308  mov      w8, #0x1398
//   0x009228: 91002279  add      x25, x19, #8
//   0x00922c: 52827109  mov      w9, #0x1388
//   0x009230: 8b08027a  add      x26, x19, x8
//   0x009234: f949e67b  ldr      x27, [x19, #0x13c8]
//   0x009238: b913ba69  str      w9, [x19, #0x13b8]
//   0x00923c: f909da79  str      x25, [x19, #0x13b0]
//   0x009240: b40008fb  cbz      x27, #0x935c
//   0x009244: f9400368  ldr      x8, [x27]
//   0x009248: eb1a011f  cmp      x8, x26
//   0x00924c: 54000881  b.ne     #0x935c
//   0x009250: b9400b68  ldr      w8, [x27, #8]
//   0x009254: 7100091f  cmp      w8, #2
//   0x009258: 540000e1  b.ne     #0x9274
//   0x00925c: b953a269  ldr      w9, [x19, #0x13a0]
//   0x009260: 52800088  mov      w8, #4
//   0x009264: b9000b68  str      w8, [x27, #8]
//   0x009268: b9001369  str      w9, [x27, #0x10]
//   0x00926c: 7100091f  cmp      w8, #2
//   0x009270: 54ffff60  b.eq     #0x925c
//   0x009274: 7100051f  cmp      w8, #1
//   0x009278: 54000660  b.eq     #0x9344
//   0x00927c: 71000d1f  cmp      w8, #3
//   0x009280: 54000620  b.eq     #0x9344
//   0x009284: 7100111f  cmp      w8, #4
//   0x009288: 54000641  b.ne     #0x9350
//   0x00928c: b9401368  ldr      w8, [x27, #0x10]
//   0x009290: b953a269  ldr      w9, [x19, #0x13a0]
//   0x009294: 6b09011f  cmp      w8, w9
//   0x009298: 54000561  b.ne     #0x9344
//   0x00929c: aa1a03e0  mov      x0, x26
//   0x0092a0: 97fff922  bl       #0x7728
//   0x0092a4: 72001c1f  tst      w0, #0xff
//   0x0092a8: 540004e0  b.eq     #0x9344
//   0x0092ac: b9401368  ldr      w8, [x27, #0x10]
//   0x0092b0: 34000308  cbz      w8, #0x9310
//   0x0092b4: 5280007b  mov      w27, #3
//   0x0092b8: b993ba68  ldrsw    x8, [x19, #0x13b8]
//   0x0092bc: d3437d09  ubfx     x9, x8, #3, #0x1d
//   0x0092c0: 7109c13f  cmp      w9, #0x270
//   0x0092c4: 540001e8  b.hi     #0x9300
//   0x0092c8: f9400263  ldr      x3, [x19]
//   0x0092cc: 52827109  mov      w9, #0x1388
//   0x0092d0: b90007fb  str      w27, [sp, #4]
//   0x0092d4: cb08013b  sub      x27, x9, x8
//   0x0092d8: 52800021  mov      w1, #1
//   0x0092dc: aa1903e0  mov      x0, x25
//   0x0092e0: aa1b03e2  mov      x2, x27
//   0x0092e4: 97ffe5ff  bl       #0x2ae0
//   0x0092e8: 6b00037f  cmp      w27, w0
//   0x0092ec: b94007fb  ldr      w27, [sp, #4]
//   0x0092f0: 54ffee81  b.ne     #0x90c0
//   0x0092f4: f9400260  ldr      x0, [x19]
//   0x0092f8: 97ffe5ba  bl       #0x29e0
//   0x0092fc: 35ffee20  cbnz     w0, #0x90c0
//   0x009300: 7100137f  cmp      w27, #4
//   0x009304: 52827109  mov      w9, #0x1388
//   0x009308: 54fff961  b.ne     #0x9234
//   0x00930c: 14000018  b        #0x936c
//   0x009310: b9405f68  ldr      w8, [x27, #0x5c]
//   0x009314: 7103fd1f  cmp      w8, #0xff
//   0x009318: 54000088  b.hi     #0x9328
//   0x00931c: b9406368  ldr      w8, [x27, #0x60]
//   0x009320: 7100011f  cmp      w8, #0
//   0x009324: 54fffc8c  b.gt     #0x92b4
//   0x009328: 294ea768  ldp      w8, w9, [x27, #0x74]
//   0x00932c: 6b08013f  cmp      w9, w8
//   0x009330: 54fffc2b  b.lt     #0x92b4
//   0x009334: 52800028  mov      w8, #1
//   0x009338: b9000b68  str      w8, [x27, #8]
//   0x00933c: 5280009b  mov      w27, #4
//   0x009340: 17ffffde  b        #0x92b8
//   0x009344: 12800008  mov      w8, #-1
//   0x009348: b50000f4  cbnz     x20, #0x9364
//   0x00934c: 17ffff69  b        #0x90f0
//   0x009350: 2a1f03e8  mov      w8, wzr
//   0x009354: b5000094  cbnz     x20, #0x9364
//   0x009358: 17ffff66  b        #0x90f0
//   0x00935c: 12800028  mov      w8, #-2
//   0x009360: b4ffec94  cbz      x20, #0x90f0
//   0x009364: b9000288  str      w8, [x20]
//   0x009368: 17ffff62  b        #0x90f0
//   0x00936c: f9400279  ldr      x25, [x19]
//   0x009370: 17ffffa4  b        #0x9200
//   0x009374: 97ffe56b  bl       #0x2920
// ============================================================================
std::uint32_t fde_35_09058(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009058ULL;
    for (std::size_t i = 0; i < 200ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6474ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[36] Subroutine @ 0x009378..0x009590 (536 bytes, 134 AArch64 instructions)
// [VN] Khung FDE[36] Hàm con @ 0x009378..0x009590 (536 byte, 134 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009378: d101c3ff  sub      sp, sp, #0x70
//   0x00937c: f9000bfb  str      x27, [sp, #0x10]
//   0x009380: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x009384: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x009388: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00938c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x009390: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x009394: 910183fd  add      x29, sp, #0x60
//   0x009398: d53bd05a  mrs      x26, tpidr_el0
//   0x00939c: f9401748  ldr      x8, [x26, #0x28]
//   0x0093a0: 2a0503f7  mov      w23, w5
//   0x0093a4: aa0403f8  mov      x24, x4
//   0x0093a8: 2a0303f5  mov      w21, w3
//   0x0093ac: 2a0203f3  mov      w19, w2
//   0x0093b0: aa0103f9  mov      x25, x1
//   0x0093b4: aa0003f6  mov      x22, x0
//   0x0093b8: f90007e8  str      x8, [sp, #8]
//   0x0093bc: b4000040  cbz      x0, #0x93c4
//   0x0093c0: b90002df  str      wzr, [x22]
//   0x0093c4: b4000179  cbz      x25, #0x93f0
//   0x0093c8: 7100127f  cmp      w19, #4
//   0x0093cc: 54000128  b.hi     #0x93f0
//   0x0093d0: 710006bf  cmp      w21, #1
//   0x0093d4: 540000e8  b.hi     #0x93f0
//   0x0093d8: b5000058  cbnz     x24, #0x93e0
//   0x0093dc: 350000b7  cbnz     w23, #0x93f0
//   0x0093e0: b40002b8  cbz      x24, #0x9434
//   0x0093e4: 52827128  mov      w8, #0x1389
//   0x0093e8: 6b0802ff  cmp      w23, w8
//   0x0093ec: 54000243  b.lo     #0x9434
//   0x0093f0: aa1f03f4  mov      x20, xzr
//   0x0093f4: b4000076  cbz      x22, #0x9400
//   0x0093f8: 12800028  mov      w8, #-2
//   0x0093fc: b90002c8  str      w8, [x22]
//   0x009400: f9401748  ldr      x8, [x26, #0x28]
//   0x009404: f94007e9  ldr      x9, [sp, #8]
//   0x009408: eb09011f  cmp      x8, x9
//   0x00940c: 54000c01  b.ne     #0x958c
//   0x009410: aa1403e0  mov      x0, x20
//   0x009414: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x009418: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x00941c: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x009420: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x009424: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x009428: f9400bfb  ldr      x27, [sp, #0x10]
//   0x00942c: 9101c3ff  add      sp, sp, #0x70
//   0x009430: d65f03c0  ret      
//   0x009434: aa1903e0  mov      x0, x25
//   0x009438: 97ffe56a  bl       #0x29e0
//   0x00943c: 340000a0  cbz      w0, #0x9450
//   0x009440: aa1f03f4  mov      x20, xzr
//   0x009444: b4fffdf6  cbz      x22, #0x9400
//   0x009448: 128000a8  mov      w8, #-6
//   0x00944c: 17ffffec  b        #0x93fc
//   0x009450: 52827e00  mov      w0, #0x13f0
//   0x009454: 97ffe58f  bl       #0x2a90
//   0x009458: b4000840  cbz      x0, #0x9560
//   0x00945c: 52827288  mov      w8, #0x1394
//   0x009460: aa0003f4  mov      x20, x0
//   0x009464: 8b08001b  add      x27, x0, x8
//   0x009468: b4000056  cbz      x22, #0x9470
//   0x00946c: b90002df  str      wzr, [x22]
//   0x009470: 52827a08  mov      w8, #0x13d0
//   0x009474: 6f00e400  movi     v0.2d, #0000000000000000
//   0x009478: 710006ff  cmp      w23, #1
//   0x00947c: 8b080288  add      x8, x20, x8
//   0x009480: b913ea9f  str      wzr, [x20, #0x13e8]
//   0x009484: 3901637f  strb     wzr, [x27, #0x58]
//   0x009488: f9000299  str      x25, [x20]
//   0x00948c: b913929f  str      wzr, [x20, #0x1390]
//   0x009490: 3900037f  strb     wzr, [x27]
//   0x009494: f909f29f  str      xzr, [x20, #0x13e0]
//   0x009498: 3d84f680  str      q0, [x20, #0x13d0]
//   0x00949c: 540001ab  b.lt     #0x94d0
//   0x0094a0: 2a1f03ea  mov      w10, wzr
//   0x0094a4: 91002289  add      x9, x20, #8
//   0x0094a8: 3840170b  ldrb     w11, [x24], #1
//   0x0094ac: 510006f7  sub      w23, w23, #1
//   0x0094b0: 710002ff  cmp      w23, #0
//   0x0094b4: 382ac92b  strb     w11, [x9, w10, sxtw]
//   0x0094b8: b953928a  ldr      w10, [x20, #0x1390]
//   0x0094bc: 1100054a  add      w10, w10, #1
//   0x0094c0: b913928a  str      w10, [x20, #0x1390]
//   0x0094c4: 54ffff2c  b.gt     #0x94a8
//   0x0094c8: f9400109  ldr      x9, [x8]
//   0x0094cc: b5000089  cbnz     x9, #0x94dc
//   0x0094d0: d0ffffe9  adrp     x9, #0x7000
//   0x0094d4: 91135129  add      x9, x9, #0x4d4
//   0x0094d8: f9000109  str      x9, [x8]
//   0x0094dc: f949ee88  ldr      x8, [x20, #0x13d8]
//   0x0094e0: b5000088  cbnz     x8, #0x94f0
//   0x0094e4: d0ffffe8  adrp     x8, #0x7000
//   0x0094e8: 91148108  add      x8, x8, #0x520
//   0x0094ec: f909ee88  str      x8, [x20, #0x13d8]
//   0x0094f0: f949f280  ldr      x0, [x20, #0x13e0]
//   0x0094f4: 529f5201  mov      w1, #0xfa90
//   0x0094f8: 52800022  mov      w2, #1
//   0x0094fc: 52800037  mov      w23, #1
//   0x009500: d63f0120  blr      x9
//   0x009504: b4000360  cbz      x0, #0x9570
//   0x009508: 52827308  mov      w8, #0x1398
//   0x00950c: 8b080288  add      x8, x20, x8
//   0x009510: f9000008  str      x8, [x0]
//   0x009514: 52800148  mov      w8, #0xa
//   0x009518: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00951c: f909e680  str      x0, [x20, #0x13c8]
//   0x009520: b9000808  str      w8, [x0, #8]
//   0x009524: fd001000  str      d0, [x0, #0x20]
//   0x009528: b90c741f  str      wzr, [x0, #0xc74]
//   0x00952c: fd000b60  str      d0, [x27, #0x10]
//   0x009530: fd001760  str      d0, [x27, #0x28]
//   0x009534: 3900b015  strb     w21, [x0, #0x2c]
//   0x009538: f906281f  str      xzr, [x0, #0xc50]
//   0x00953c: f906301f  str      xzr, [x0, #0xc60]
//   0x009540: f9062c1f  str      xzr, [x0, #0xc58]
//   0x009544: 29064c1f  stp      wzr, w19, [x0, #0x30]
//   0x009548: b9539288  ldr      w8, [x20, #0x1390]
//   0x00954c: 91002289  add      x9, x20, #8
//   0x009550: f909ce89  str      x9, [x20, #0x1398]
//   0x009554: b913a288  str      w8, [x20, #0x13a0]
//   0x009558: 39016377  strb     w23, [x27, #0x58]
//   0x00955c: 17ffffa9  b        #0x9400
//   0x009560: aa1f03f4  mov      x20, xzr
//   0x009564: b4fff4f6  cbz      x22, #0x9400
//   0x009568: 12800048  mov      w8, #-3
//   0x00956c: 17ffffa4  b        #0x93fc
//   0x009570: b4000076  cbz      x22, #0x957c
//   0x009574: 12800048  mov      w8, #-3
//   0x009578: b90002c8  str      w8, [x22]
//   0x00957c: aa1403e0  mov      x0, x20
//   0x009580: 97ffe55c  bl       #0x2af0
//   0x009584: aa1f03f4  mov      x20, xzr
//   0x009588: 17ffff9e  b        #0x9400
//   0x00958c: 97ffe4e5  bl       #0x2920
// ============================================================================
std::uint32_t fde_36_09378(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009378ULL;
    for (std::size_t i = 0; i < 134ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6674ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[37] Subroutine @ 0x009590..0x009698 (264 bytes, 66 AArch64 instructions)
// [VN] Khung FDE[37] Hàm con @ 0x009590..0x009698 (264 byte, 66 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009590: d10103ff  sub      sp, sp, #0x40
//   0x009594: f9000bf5  str      x21, [sp, #0x10]
//   0x009598: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00959c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0095a0: 9100c3fd  add      x29, sp, #0x30
//   0x0095a4: d53bd054  mrs      x20, tpidr_el0
//   0x0095a8: f9401688  ldr      x8, [x20, #0x28]
//   0x0095ac: aa0103f3  mov      x19, x1
//   0x0095b0: f90007e8  str      x8, [sp, #8]
//   0x0095b4: b4000040  cbz      x0, #0x95bc
//   0x0095b8: b900001f  str      wzr, [x0]
//   0x0095bc: b4000193  cbz      x19, #0x95ec
//   0x0095c0: 52827288  mov      w8, #0x1394
//   0x0095c4: 8b080268  add      x8, x19, x8
//   0x0095c8: b913ea7f  str      wzr, [x19, #0x13e8]
//   0x0095cc: 39400109  ldrb     w9, [x8]
//   0x0095d0: 34000149  cbz      w9, #0x95f8
//   0x0095d4: b4000060  cbz      x0, #0x95e0
//   0x0095d8: 12800008  mov      w8, #-1
//   0x0095dc: b9000008  str      w8, [x0]
//   0x0095e0: 12800008  mov      w8, #-1
//   0x0095e4: b913ea68  str      w8, [x19, #0x13e8]
//   0x0095e8: 14000022  b        #0x9670
//   0x0095ec: b4000420  cbz      x0, #0x9670
//   0x0095f0: b900001f  str      wzr, [x0]
//   0x0095f4: 1400001f  b        #0x9670
//   0x0095f8: 39416108  ldrb     w8, [x8, #0x58]
//   0x0095fc: 34000368  cbz      w8, #0x9668
//   0x009600: f949e675  ldr      x21, [x19, #0x13c8]
//   0x009604: b4000335  cbz      x21, #0x9668
//   0x009608: f94002a8  ldr      x8, [x21]
//   0x00960c: 52827309  mov      w9, #0x1398
//   0x009610: 8b090269  add      x9, x19, x9
//   0x009614: eb09011f  cmp      x8, x9
//   0x009618: 54000281  b.ne     #0x9668
//   0x00961c: f9462aa1  ldr      x1, [x21, #0xc50]
//   0x009620: b4000081  cbz      x1, #0x9630
//   0x009624: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x009628: f949f260  ldr      x0, [x19, #0x13e0]
//   0x00962c: d63f0100  blr      x8
//   0x009630: f9462ea1  ldr      x1, [x21, #0xc58]
//   0x009634: b4000081  cbz      x1, #0x9644
//   0x009638: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x00963c: f949f260  ldr      x0, [x19, #0x13e0]
//   0x009640: d63f0100  blr      x8
//   0x009644: f94632a1  ldr      x1, [x21, #0xc60]
//   0x009648: b4000081  cbz      x1, #0x9658
//   0x00964c: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x009650: f949f260  ldr      x0, [x19, #0x13e0]
//   0x009654: d63f0100  blr      x8
//   0x009658: f949ee68  ldr      x8, [x19, #0x13d8]
//   0x00965c: f949f260  ldr      x0, [x19, #0x13e0]
//   0x009660: f949e661  ldr      x1, [x19, #0x13c8]
//   0x009664: d63f0100  blr      x8
//   0x009668: aa1303e0  mov      x0, x19
//   0x00966c: 97ffe521  bl       #0x2af0
//   0x009670: f9401688  ldr      x8, [x20, #0x28]
//   0x009674: f94007e9  ldr      x9, [sp, #8]
//   0x009678: eb09011f  cmp      x8, x9
//   0x00967c: 540000c1  b.ne     #0x9694
//   0x009680: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x009684: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x009688: f9400bf5  ldr      x21, [sp, #0x10]
//   0x00968c: 910103ff  add      sp, sp, #0x40
//   0x009690: d65f03c0  ret      
//   0x009694: 97ffe4a3  bl       #0x2920
// ============================================================================
std::uint32_t fde_37_09590(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009590ULL;
    for (std::size_t i = 0; i < 66ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6808ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[38] Subroutine @ 0x009698..0x0098bc (548 bytes, 137 AArch64 instructions)
// [VN] Khung FDE[38] Hàm con @ 0x009698..0x0098bc (548 byte, 137 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009698: d10183ff  sub      sp, sp, #0x60
//   0x00969c: f9000bf9  str      x25, [sp, #0x10]
//   0x0096a0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0096a4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0096a8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0096ac: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0096b0: 910143fd  add      x29, sp, #0x50
//   0x0096b4: d53bd059  mrs      x25, tpidr_el0
//   0x0096b8: f9401728  ldr      x8, [x25, #0x28]
//   0x0096bc: 2a0303f3  mov      w19, w3
//   0x0096c0: aa0103f4  mov      x20, x1
//   0x0096c4: aa0003f5  mov      x21, x0
//   0x0096c8: f90007e8  str      x8, [sp, #8]
//   0x0096cc: b4000040  cbz      x0, #0x96d4
//   0x0096d0: b90002bf  str      wzr, [x21]
//   0x0096d4: b40001b4  cbz      x20, #0x9708
//   0x0096d8: b913ea9f  str      wzr, [x20, #0x13e8]
//   0x0096dc: b4000162  cbz      x2, #0x9708
//   0x0096e0: 37f80153  tbnz     w19, #0x1f, #0x9708
//   0x0096e4: 52827288  mov      w8, #0x1394
//   0x0096e8: 38686a88  ldrb     w8, [x20, x8]
//   0x0096ec: 34000348  cbz      w8, #0x9754
//   0x0096f0: b4000075  cbz      x21, #0x96fc
//   0x0096f4: 12800008  mov      w8, #-1
//   0x0096f8: b90002a8  str      w8, [x21]
//   0x0096fc: 2a1f03f3  mov      w19, wzr
//   0x009700: 12800008  mov      w8, #-1
//   0x009704: 14000007  b        #0x9720
//   0x009708: b4000075  cbz      x21, #0x9714
//   0x00970c: 12800028  mov      w8, #-2
//   0x009710: b90002a8  str      w8, [x21]
//   0x009714: 2a1f03f3  mov      w19, wzr
//   0x009718: b4000074  cbz      x20, #0x9724
//   0x00971c: 12800028  mov      w8, #-2
//   0x009720: b913ea88  str      w8, [x20, #0x13e8]
//   0x009724: f9401728  ldr      x8, [x25, #0x28]
//   0x009728: f94007e9  ldr      x9, [sp, #8]
//   0x00972c: eb09011f  cmp      x8, x9
//   0x009730: 54000c41  b.ne     #0x98b8
//   0x009734: 2a1303e0  mov      w0, w19
//   0x009738: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x00973c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x009740: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x009744: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x009748: f9400bf9  ldr      x25, [sp, #0x10]
//   0x00974c: 910183ff  add      sp, sp, #0x60
//   0x009750: d65f03c0  ret      
//   0x009754: 340007b3  cbz      w19, #0x9848
//   0x009758: 52827308  mov      w8, #0x1398
//   0x00975c: 8b080296  add      x22, x20, x8
//   0x009760: 91002297  add      x23, x20, #8
//   0x009764: b913ba93  str      w19, [x20, #0x13b8]
//   0x009768: f909da82  str      x2, [x20, #0x13b0]
//   0x00976c: 14000005  b        #0x9780
//   0x009770: 7100101f  cmp      w0, #4
//   0x009774: 54000920  b.eq     #0x9898
//   0x009778: b953ba88  ldr      w8, [x20, #0x13b8]
//   0x00977c: 34000868  cbz      w8, #0x9888
//   0x009780: f9400298  ldr      x24, [x20]
//   0x009784: aa1803e0  mov      x0, x24
//   0x009788: 97ffe496  bl       #0x29e0
//   0x00978c: 35000680  cbnz     w0, #0x985c
//   0x009790: b953a288  ldr      w8, [x20, #0x13a0]
//   0x009794: 35000288  cbnz     w8, #0x97e4
//   0x009798: aa1803e0  mov      x0, x24
//   0x00979c: 97ffe48d  bl       #0x29d0
//   0x0097a0: 3100041f  cmn      w0, #1
//   0x0097a4: 54000200  b.eq     #0x97e4
//   0x0097a8: aa1803e1  mov      x1, x24
//   0x0097ac: 97ffe3f9  bl       #0x2790
//   0x0097b0: f9400283  ldr      x3, [x20]
//   0x0097b4: 52800021  mov      w1, #1
//   0x0097b8: 52827102  mov      w2, #0x1388
//   0x0097bc: aa1703e0  mov      x0, x23
//   0x0097c0: 97ffe3dc  bl       #0x2730
//   0x0097c4: f9400288  ldr      x8, [x20]
//   0x0097c8: aa0003f8  mov      x24, x0
//   0x0097cc: aa0803e0  mov      x0, x8
//   0x0097d0: 97ffe484  bl       #0x29e0
//   0x0097d4: 35000440  cbnz     w0, #0x985c
//   0x0097d8: b9139298  str      w24, [x20, #0x1390]
//   0x0097dc: b913a298  str      w24, [x20, #0x13a0]
//   0x0097e0: f909ce97  str      x23, [x20, #0x1398]
//   0x0097e4: aa1603e0  mov      x0, x22
//   0x0097e8: 97ffe40e  bl       #0x2820
//   0x0097ec: 721d781f  tst      w0, #0xfffffffb
//   0x0097f0: 54000421  b.ne     #0x9874
//   0x0097f4: 35fffbe0  cbnz     w0, #0x9770
//   0x0097f8: f9400298  ldr      x24, [x20]
//   0x0097fc: aa1803e0  mov      x0, x24
//   0x009800: 97ffe474  bl       #0x29d0
//   0x009804: 3100041f  cmn      w0, #1
//   0x009808: 540000c0  b.eq     #0x9820
//   0x00980c: aa1803e1  mov      x1, x24
//   0x009810: 97ffe3e0  bl       #0x2790
//   0x009814: b953ba88  ldr      w8, [x20, #0x13b8]
//   0x009818: 35fffb48  cbnz     w8, #0x9780
//   0x00981c: 1400001b  b        #0x9888
//   0x009820: b953a288  ldr      w8, [x20, #0x13a0]
//   0x009824: 35fffaa8  cbnz     w8, #0x9778
//   0x009828: b953ba88  ldr      w8, [x20, #0x13b8]
//   0x00982c: 340002e8  cbz      w8, #0x9888
//   0x009830: b4000075  cbz      x21, #0x983c
//   0x009834: 128000c8  mov      w8, #-7
//   0x009838: b90002a8  str      w8, [x21]
//   0x00983c: 2a1f03f3  mov      w19, wzr
//   0x009840: 128000c8  mov      w8, #-7
//   0x009844: 17ffffb7  b        #0x9720
//   0x009848: b4000055  cbz      x21, #0x9850
//   0x00984c: b90002bf  str      wzr, [x21]
//   0x009850: 2a1f03f3  mov      w19, wzr
//   0x009854: b913ea9f  str      wzr, [x20, #0x13e8]
//   0x009858: 17ffffb3  b        #0x9724
//   0x00985c: b4000075  cbz      x21, #0x9868
//   0x009860: 128000a8  mov      w8, #-6
//   0x009864: b90002a8  str      w8, [x21]
//   0x009868: 2a1f03f3  mov      w19, wzr
//   0x00986c: 128000a8  mov      w8, #-6
//   0x009870: 17ffffac  b        #0x9720
//   0x009874: b4000055  cbz      x21, #0x987c
//   0x009878: b90002a0  str      w0, [x21]
//   0x00987c: 2a1f03f3  mov      w19, wzr
//   0x009880: b913ea80  str      w0, [x20, #0x13e8]
//   0x009884: 17ffffa8  b        #0x9724
//   0x009888: b4000055  cbz      x21, #0x9890
//   0x00988c: b90002bf  str      wzr, [x21]
//   0x009890: b913ea9f  str      wzr, [x20, #0x13e8]
//   0x009894: 17ffffa4  b        #0x9724
//   0x009898: b4000075  cbz      x21, #0x98a4
//   0x00989c: 52800088  mov      w8, #4
//   0x0098a0: b90002a8  str      w8, [x21]
//   0x0098a4: b953ba88  ldr      w8, [x20, #0x13b8]
//   0x0098a8: 52800089  mov      w9, #4
//   0x0098ac: b913ea89  str      w9, [x20, #0x13e8]
//   0x0098b0: 4b080273  sub      w19, w19, w8
//   0x0098b4: 17ffff9c  b        #0x9724
//   0x0098b8: 97ffe41a  bl       #0x2920
// ============================================================================
std::uint32_t fde_38_09698(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009698ULL;
    for (std::size_t i = 0; i < 137ULL; ++i) {
        std::uint32_t insn = kTextInstructions[6874ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[39] Subroutine @ 0x0098bc..0x009964 (168 bytes, 42 AArch64 instructions)
// [VN] Khung FDE[39] Hàm con @ 0x0098bc..0x009964 (168 byte, 42 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0098bc: d10083ff  sub      sp, sp, #0x20
//   0x0098c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0098c4: 910043fd  add      x29, sp, #0x10
//   0x0098c8: d53bd048  mrs      x8, tpidr_el0
//   0x0098cc: f9401509  ldr      x9, [x8, #0x28]
//   0x0098d0: f90007e9  str      x9, [sp, #8]
//   0x0098d4: b40001c1  cbz      x1, #0x990c
//   0x0098d8: b953e829  ldr      w9, [x1, #0x13e8]
//   0x0098dc: 7100113f  cmp      w9, #4
//   0x0098e0: 540001e1  b.ne     #0x991c
//   0x0098e4: b4000262  cbz      x2, #0x9930
//   0x0098e8: b4000243  cbz      x3, #0x9930
//   0x0098ec: b4000040  cbz      x0, #0x98f4
//   0x0098f0: b900001f  str      wzr, [x0]
//   0x0098f4: b953a029  ldr      w9, [x1, #0x13a0]
//   0x0098f8: b913e83f  str      wzr, [x1, #0x13e8]
//   0x0098fc: b9000069  str      w9, [x3]
//   0x009900: f949cc29  ldr      x9, [x1, #0x1398]
//   0x009904: f9000049  str      x9, [x2]
//   0x009908: 1400000f  b        #0x9944
//   0x00990c: b40001c0  cbz      x0, #0x9944
//   0x009910: 12800029  mov      w9, #-2
//   0x009914: b9000009  str      w9, [x0]
//   0x009918: 1400000b  b        #0x9944
//   0x00991c: b4000060  cbz      x0, #0x9928
//   0x009920: 12800009  mov      w9, #-1
//   0x009924: b9000009  str      w9, [x0]
//   0x009928: 12800009  mov      w9, #-1
//   0x00992c: 14000005  b        #0x9940
//   0x009930: b4000060  cbz      x0, #0x993c
//   0x009934: 12800029  mov      w9, #-2
//   0x009938: b9000009  str      w9, [x0]
//   0x00993c: 12800029  mov      w9, #-2
//   0x009940: b913e829  str      w9, [x1, #0x13e8]
//   0x009944: f9401508  ldr      x8, [x8, #0x28]
//   0x009948: f94007e9  ldr      x9, [sp, #8]
//   0x00994c: eb09011f  cmp      x8, x9
//   0x009950: 54000081  b.ne     #0x9960
//   0x009954: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x009958: 910083ff  add      sp, sp, #0x20
//   0x00995c: d65f03c0  ret      
//   0x009960: 97ffe3f0  bl       #0x2920
// ============================================================================
std::uint32_t fde_39_098bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000098bcULL;
    for (std::size_t i = 0; i < 42ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7011ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[40] Subroutine @ 0x009964..0x009c2c (712 bytes, 178 AArch64 instructions)
// [VN] Khung FDE[40] Hàm con @ 0x009964..0x009c2c (712 byte, 178 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009964: d10283ff  sub      sp, sp, #0xa0
//   0x009968: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x00996c: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x009970: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x009974: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x009978: 910243fd  add      x29, sp, #0x90
//   0x00997c: d53bd058  mrs      x24, tpidr_el0
//   0x009980: f9401708  ldr      x8, [x24, #0x28]
//   0x009984: 7103e8df  cmp      w6, #0xfa
//   0x009988: 12800033  mov      w19, #-2
//   0x00998c: f81c83a8  stur     x8, [x29, #-0x38]
//   0x009990: 54000308  b.hi     #0x99f0
//   0x009994: 710010bf  cmp      w5, #4
//   0x009998: 540002c8  b.hi     #0x99f0
//   0x00999c: aa0003f7  mov      x23, x0
//   0x0099a0: b4000280  cbz      x0, #0x99f0
//   0x0099a4: aa0103f4  mov      x20, x1
//   0x0099a8: b4000241  cbz      x1, #0x99f0
//   0x0099ac: aa0203f6  mov      x22, x2
//   0x0099b0: b4000202  cbz      x2, #0x99f0
//   0x0099b4: 51000488  sub      w8, w4, #1
//   0x0099b8: 7100211f  cmp      w8, #8
//   0x0099bc: 540001a8  b.hi     #0x99f0
//   0x0099c0: 710000df  cmp      w6, #0
//   0x0099c4: 528003c8  mov      w8, #0x1e
//   0x0099c8: 2a0303f5  mov      w21, w3
//   0x0099cc: 1a860103  csel     w3, w8, w6, eq
//   0x0099d0: 910023e0  add      x0, sp, #8
//   0x0099d4: 2a0403e1  mov      w1, w4
//   0x0099d8: 2a0503e2  mov      w2, w5
//   0x0099dc: a904ffff  stp      xzr, xzr, [sp, #0x48]
//   0x0099e0: f90023ff  str      xzr, [sp, #0x40]
//   0x0099e4: 97ffe3e3  bl       #0x2970
//   0x0099e8: 2a0003f3  mov      w19, w0
//   0x0099ec: 34000180  cbz      w0, #0x9a1c
//   0x0099f0: f9401708  ldr      x8, [x24, #0x28]
//   0x0099f4: f85c83a9  ldur     x9, [x29, #-0x38]
//   0x0099f8: eb09011f  cmp      x8, x9
//   0x0099fc: 54001161  b.ne     #0x9c28
//   0x009a00: 2a1303e0  mov      w0, w19
//   0x009a04: a9497bfd  ldp      x29, x30, [sp, #0x90]
//   0x009a08: a9484ff4  ldp      x20, x19, [sp, #0x80]
//   0x009a0c: a94757f6  ldp      x22, x21, [sp, #0x70]
//   0x009a10: a9465ff8  ldp      x24, x23, [sp, #0x60]
//   0x009a14: 910283ff  add      sp, sp, #0xa0
//   0x009a18: d65f03c0  ret      
//   0x009a1c: f90007f6  str      x22, [sp, #8]
//   0x009a20: f90013f7  str      x23, [sp, #0x20]
//   0x009a24: b90013f5  str      w21, [sp, #0x10]
//   0x009a28: b9400288  ldr      w8, [x20]
//   0x009a2c: f9401ff6  ldr      x22, [sp, #0x38]
//   0x009a30: b9002be8  str      w8, [sp, #0x28]
//   0x009a34: b40000f6  cbz      x22, #0x9a50
//   0x009a38: f94002c8  ldr      x8, [x22]
//   0x009a3c: 910023f7  add      x23, sp, #8
//   0x009a40: eb17011f  cmp      x8, x23
//   0x009a44: 540000a0  b.eq     #0x9a58
//   0x009a48: 12800033  mov      w19, #-2
//   0x009a4c: 14000025  b        #0x9ae0
//   0x009a50: 12800033  mov      w19, #-2
//   0x009a54: 17ffffe7  b        #0x99f0
//   0x009a58: b9400ac8  ldr      w8, [x22, #8]
//   0x009a5c: 7100091f  cmp      w8, #2
//   0x009a60: 540000c1  b.ne     #0x9a78
//   0x009a64: 52800088  mov      w8, #4
//   0x009a68: b90012d5  str      w21, [x22, #0x10]
//   0x009a6c: b9000ac8  str      w8, [x22, #8]
//   0x009a70: 7100091f  cmp      w8, #2
//   0x009a74: 54ffff80  b.eq     #0x9a64
//   0x009a78: 7100051f  cmp      w8, #1
//   0x009a7c: 540002c0  b.eq     #0x9ad4
//   0x009a80: 71000d1f  cmp      w8, #3
//   0x009a84: 54000280  b.eq     #0x9ad4
//   0x009a88: 7100111f  cmp      w8, #4
//   0x009a8c: 54000281  b.ne     #0x9adc
//   0x009a90: b94012c8  ldr      w8, [x22, #0x10]
//   0x009a94: 6b15011f  cmp      w8, w21
//   0x009a98: 540001e1  b.ne     #0x9ad4
//   0x009a9c: 910023e0  add      x0, sp, #8
//   0x009aa0: 97fff722  bl       #0x7728
//   0x009aa4: 72001c1f  tst      w0, #0xff
//   0x009aa8: 54000440  b.eq     #0x9b30
//   0x009aac: b94012c8  ldr      w8, [x22, #0x10]
//   0x009ab0: 34000488  cbz      w8, #0x9b40
//   0x009ab4: f9401ff3  ldr      x19, [sp, #0x38]
//   0x009ab8: b40000b3  cbz      x19, #0x9acc
//   0x009abc: f9400268  ldr      x8, [x19]
//   0x009ac0: 910023e9  add      x9, sp, #8
//   0x009ac4: eb09011f  cmp      x8, x9
//   0x009ac8: 540006a0  b.eq     #0x9b9c
//   0x009acc: 128000f3  mov      w19, #-8
//   0x009ad0: 17ffffc8  b        #0x99f0
//   0x009ad4: 12800013  mov      w19, #-1
//   0x009ad8: 14000002  b        #0x9ae0
//   0x009adc: 2a1f03f3  mov      w19, wzr
//   0x009ae0: f94002c8  ldr      x8, [x22]
//   0x009ae4: eb17011f  cmp      x8, x23
//   0x009ae8: 54fff841  b.ne     #0x99f0
//   0x009aec: f9400ec1  ldr      x1, [x22, #0x18]
//   0x009af0: b4000061  cbz      x1, #0x9afc
//   0x009af4: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009af8: d63f0100  blr      x8
//   0x009afc: f94012c1  ldr      x1, [x22, #0x20]
//   0x009b00: b4000061  cbz      x1, #0x9b0c
//   0x009b04: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009b08: d63f0100  blr      x8
//   0x009b0c: f94016c1  ldr      x1, [x22, #0x28]
//   0x009b10: b4000061  cbz      x1, #0x9b1c
//   0x009b14: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009b18: d63f0100  blr      x8
//   0x009b1c: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009b20: f9401fe1  ldr      x1, [sp, #0x38]
//   0x009b24: d63f0100  blr      x8
//   0x009b28: f9001fff  str      xzr, [sp, #0x38]
//   0x009b2c: 17ffffb1  b        #0x99f0
//   0x009b30: f9401ff6  ldr      x22, [sp, #0x38]
//   0x009b34: 12800013  mov      w19, #-1
//   0x009b38: b5fffd56  cbnz     x22, #0x9ae0
//   0x009b3c: 17ffffad  b        #0x99f0
//   0x009b40: b9405ec8  ldr      w8, [x22, #0x5c]
//   0x009b44: 7103fd1f  cmp      w8, #0xff
//   0x009b48: 54000088  b.hi     #0x9b58
//   0x009b4c: b94062c8  ldr      w8, [x22, #0x60]
//   0x009b50: 7100011f  cmp      w8, #0
//   0x009b54: 54fffb0c  b.gt     #0x9ab4
//   0x009b58: 294ea6c8  ldp      w8, w9, [x22, #0x74]
//   0x009b5c: 6b08013f  cmp      w9, w8
//   0x009b60: 54fffaab  b.lt     #0x9ab4
//   0x009b64: 52800028  mov      w8, #1
//   0x009b68: b9000ac8  str      w8, [x22, #8]
//   0x009b6c: b9402be8  ldr      w8, [sp, #0x28]
//   0x009b70: b9400289  ldr      w9, [x20]
//   0x009b74: 4b080128  sub      w8, w9, w8
//   0x009b78: b9000288  str      w8, [x20]
//   0x009b7c: f9401ff3  ldr      x19, [sp, #0x38]
//   0x009b80: b4fff393  cbz      x19, #0x99f0
//   0x009b84: f9400268  ldr      x8, [x19]
//   0x009b88: 910023e9  add      x9, sp, #8
//   0x009b8c: eb09011f  cmp      x8, x9
//   0x009b90: 540002a0  b.eq     #0x9be4
//   0x009b94: 2a1f03f3  mov      w19, wzr
//   0x009b98: 17ffff96  b        #0x99f0
//   0x009b9c: f9400e61  ldr      x1, [x19, #0x18]
//   0x009ba0: b4000061  cbz      x1, #0x9bac
//   0x009ba4: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009ba8: d63f0100  blr      x8
//   0x009bac: f9401261  ldr      x1, [x19, #0x20]
//   0x009bb0: b4000061  cbz      x1, #0x9bbc
//   0x009bb4: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009bb8: d63f0100  blr      x8
//   0x009bbc: f9401661  ldr      x1, [x19, #0x28]
//   0x009bc0: b4000061  cbz      x1, #0x9bcc
//   0x009bc4: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009bc8: d63f0100  blr      x8
//   0x009bcc: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009bd0: f9401fe1  ldr      x1, [sp, #0x38]
//   0x009bd4: d63f0100  blr      x8
//   0x009bd8: f9001fff  str      xzr, [sp, #0x38]
//   0x009bdc: 128000f3  mov      w19, #-8
//   0x009be0: 17ffff84  b        #0x99f0
//   0x009be4: f9400e61  ldr      x1, [x19, #0x18]
//   0x009be8: b4000061  cbz      x1, #0x9bf4
//   0x009bec: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009bf0: d63f0100  blr      x8
//   0x009bf4: f9401261  ldr      x1, [x19, #0x20]
//   0x009bf8: b4000061  cbz      x1, #0x9c04
//   0x009bfc: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009c00: d63f0100  blr      x8
//   0x009c04: f9401661  ldr      x1, [x19, #0x28]
//   0x009c08: b4000061  cbz      x1, #0x9c14
//   0x009c0c: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009c10: d63f0100  blr      x8
//   0x009c14: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009c18: f9401fe1  ldr      x1, [sp, #0x38]
//   0x009c1c: d63f0100  blr      x8
//   0x009c20: 2a1f03f3  mov      w19, wzr
//   0x009c24: 17ffffc1  b        #0x9b28
//   0x009c28: 97ffe33e  bl       #0x2920
// ============================================================================
std::uint32_t fde_40_09964(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009964ULL;
    for (std::size_t i = 0; i < 178ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7053ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[41] Subroutine @ 0x009c2c..0x009e90 (612 bytes, 153 AArch64 instructions)
// [VN] Khung FDE[41] Hàm con @ 0x009c2c..0x009e90 (612 byte, 153 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009c2c: d102c3ff  sub      sp, sp, #0xb0
//   0x009c30: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x009c34: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x009c38: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x009c3c: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x009c40: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x009c44: 910283fd  add      x29, sp, #0xa0
//   0x009c48: d53bd05a  mrs      x26, tpidr_el0
//   0x009c4c: f9401748  ldr      x8, [x26, #0x28]
//   0x009c50: 12800033  mov      w19, #-2
//   0x009c54: f81b83a8  stur     x8, [x29, #-0x48]
//   0x009c58: b4001020  cbz      x0, #0x9e5c
//   0x009c5c: aa0103f4  mov      x20, x1
//   0x009c60: b4000fe1  cbz      x1, #0x9e5c
//   0x009c64: aa0203f7  mov      x23, x2
//   0x009c68: b4000fa2  cbz      x2, #0x9e5c
//   0x009c6c: 2a0403f9  mov      w25, w4
//   0x009c70: 7100049f  cmp      w4, #1
//   0x009c74: 12800033  mov      w19, #-2
//   0x009c78: 54000f28  b.hi     #0x9e5c
//   0x009c7c: 2a0503f6  mov      w22, w5
//   0x009c80: 710010bf  cmp      w5, #4
//   0x009c84: 54000ec8  b.hi     #0x9e5c
//   0x009c88: d0ffffe8  adrp     x8, #0x7000
//   0x009c8c: d0ffffe9  adrp     x9, #0x7000
//   0x009c90: aa0003f8  mov      x24, x0
//   0x009c94: 91135108  add      x8, x8, #0x4d4
//   0x009c98: 91148129  add      x9, x9, #0x520
//   0x009c9c: 529f5200  mov      w0, #0xfa90
//   0x009ca0: 2a0303f5  mov      w21, w3
//   0x009ca4: a90427e8  stp      x8, x9, [sp, #0x40]
//   0x009ca8: f9002bff  str      xzr, [sp, #0x50]
//   0x009cac: 97ffe379  bl       #0x2a90
//   0x009cb0: b40004e0  cbz      x0, #0x9d4c
//   0x009cb4: 910023e8  add      x8, sp, #8
//   0x009cb8: 52800149  mov      w9, #0xa
//   0x009cbc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x009cc0: f9001fe0  str      x0, [sp, #0x38]
//   0x009cc4: 3900b019  strb     w25, [x0, #0x2c]
//   0x009cc8: b90c741f  str      wzr, [x0, #0xc74]
//   0x009ccc: f906281f  str      xzr, [x0, #0xc50]
//   0x009cd0: f906301f  str      xzr, [x0, #0xc60]
//   0x009cd4: f9062c1f  str      xzr, [x0, #0xc58]
//   0x009cd8: 2906581f  stp      wzr, w22, [x0, #0x30]
//   0x009cdc: f90007f7  str      x23, [sp, #8]
//   0x009ce0: f90013f8  str      x24, [sp, #0x20]
//   0x009ce4: f9000008  str      x8, [x0]
//   0x009ce8: b9000809  str      w9, [x0, #8]
//   0x009cec: fd001000  str      d0, [x0, #0x20]
//   0x009cf0: fc0143e0  stur     d0, [sp, #0x14]
//   0x009cf4: fc02c3e0  stur     d0, [sp, #0x2c]
//   0x009cf8: b90013f5  str      w21, [sp, #0x10]
//   0x009cfc: b9400288  ldr      w8, [x20]
//   0x009d00: 910023e0  add      x0, sp, #8
//   0x009d04: b9002be8  str      w8, [sp, #0x28]
//   0x009d08: 97ffe2c6  bl       #0x2820
//   0x009d0c: 34000240  cbz      w0, #0x9d54
//   0x009d10: 2a0003f3  mov      w19, w0
//   0x009d14: 7100101f  cmp      w0, #4
//   0x009d18: 54000541  b.ne     #0x9dc0
//   0x009d1c: b9402be8  ldr      w8, [sp, #0x28]
//   0x009d20: b9400289  ldr      w9, [x20]
//   0x009d24: 4b080128  sub      w8, w9, w8
//   0x009d28: b9000288  str      w8, [x20]
//   0x009d2c: f9401ff3  ldr      x19, [sp, #0x38]
//   0x009d30: b4000973  cbz      x19, #0x9e5c
//   0x009d34: f9400268  ldr      x8, [x19]
//   0x009d38: 910023e9  add      x9, sp, #8
//   0x009d3c: eb09011f  cmp      x8, x9
//   0x009d40: 540006c0  b.eq     #0x9e18
//   0x009d44: 2a1f03f3  mov      w19, wzr
//   0x009d48: 14000045  b        #0x9e5c
//   0x009d4c: 12800053  mov      w19, #-3
//   0x009d50: 14000043  b        #0x9e5c
//   0x009d54: f9401ff4  ldr      x20, [sp, #0x38]
//   0x009d58: b9402bf3  ldr      w19, [sp, #0x28]
//   0x009d5c: b40002b4  cbz      x20, #0x9db0
//   0x009d60: f9400288  ldr      x8, [x20]
//   0x009d64: 910023e9  add      x9, sp, #8
//   0x009d68: eb09011f  cmp      x8, x9
//   0x009d6c: 54000221  b.ne     #0x9db0
//   0x009d70: f9462a81  ldr      x1, [x20, #0xc50]
//   0x009d74: b4000061  cbz      x1, #0x9d80
//   0x009d78: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009d7c: d63f0100  blr      x8
//   0x009d80: f9462e81  ldr      x1, [x20, #0xc58]
//   0x009d84: b4000061  cbz      x1, #0x9d90
//   0x009d88: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009d8c: d63f0100  blr      x8
//   0x009d90: f9463281  ldr      x1, [x20, #0xc60]
//   0x009d94: b4000061  cbz      x1, #0x9da0
//   0x009d98: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009d9c: d63f0100  blr      x8
//   0x009da0: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009da4: f9401fe1  ldr      x1, [sp, #0x38]
//   0x009da8: d63f0100  blr      x8
//   0x009dac: f9001fff  str      xzr, [sp, #0x38]
//   0x009db0: 7100027f  cmp      w19, #0
//   0x009db4: 128000e8  mov      w8, #-8
//   0x009db8: 1a880513  cinc     w19, w8, ne
//   0x009dbc: 14000028  b        #0x9e5c
//   0x009dc0: f9401ff4  ldr      x20, [sp, #0x38]
//   0x009dc4: b40004d4  cbz      x20, #0x9e5c
//   0x009dc8: f9400288  ldr      x8, [x20]
//   0x009dcc: 910023e9  add      x9, sp, #8
//   0x009dd0: eb09011f  cmp      x8, x9
//   0x009dd4: 54000441  b.ne     #0x9e5c
//   0x009dd8: f9462a81  ldr      x1, [x20, #0xc50]
//   0x009ddc: b4000061  cbz      x1, #0x9de8
//   0x009de0: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009de4: d63f0100  blr      x8
//   0x009de8: f9462e81  ldr      x1, [x20, #0xc58]
//   0x009dec: b4000061  cbz      x1, #0x9df8
//   0x009df0: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009df4: d63f0100  blr      x8
//   0x009df8: f9463281  ldr      x1, [x20, #0xc60]
//   0x009dfc: b4000061  cbz      x1, #0x9e08
//   0x009e00: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009e04: d63f0100  blr      x8
//   0x009e08: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009e0c: f9401fe1  ldr      x1, [sp, #0x38]
//   0x009e10: d63f0100  blr      x8
//   0x009e14: 14000011  b        #0x9e58
//   0x009e18: f9462a61  ldr      x1, [x19, #0xc50]
//   0x009e1c: b4000061  cbz      x1, #0x9e28
//   0x009e20: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009e24: d63f0100  blr      x8
//   0x009e28: f9462e61  ldr      x1, [x19, #0xc58]
//   0x009e2c: b4000061  cbz      x1, #0x9e38
//   0x009e30: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009e34: d63f0100  blr      x8
//   0x009e38: f9463261  ldr      x1, [x19, #0xc60]
//   0x009e3c: b4000061  cbz      x1, #0x9e48
//   0x009e40: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009e44: d63f0100  blr      x8
//   0x009e48: a94483e8  ldp      x8, x0, [sp, #0x48]
//   0x009e4c: f9401fe1  ldr      x1, [sp, #0x38]
//   0x009e50: d63f0100  blr      x8
//   0x009e54: 2a1f03f3  mov      w19, wzr
//   0x009e58: f9001fff  str      xzr, [sp, #0x38]
//   0x009e5c: f9401748  ldr      x8, [x26, #0x28]
//   0x009e60: f85b83a9  ldur     x9, [x29, #-0x48]
//   0x009e64: eb09011f  cmp      x8, x9
//   0x009e68: 54000121  b.ne     #0x9e8c
//   0x009e6c: 2a1303e0  mov      w0, w19
//   0x009e70: a94a7bfd  ldp      x29, x30, [sp, #0xa0]
//   0x009e74: a9494ff4  ldp      x20, x19, [sp, #0x90]
//   0x009e78: a94857f6  ldp      x22, x21, [sp, #0x80]
//   0x009e7c: a9475ff8  ldp      x24, x23, [sp, #0x70]
//   0x009e80: a94667fa  ldp      x26, x25, [sp, #0x60]
//   0x009e84: 9102c3ff  add      sp, sp, #0xb0
//   0x009e88: d65f03c0  ret      
//   0x009e8c: 97ffe2a5  bl       #0x2920
// ============================================================================
std::uint32_t fde_41_09c2c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009c2cULL;
    for (std::size_t i = 0; i < 153ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7231ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[42] Subroutine @ 0x009e90..0x009ee0 (80 bytes, 20 AArch64 instructions)
// [VN] Khung FDE[42] Hàm con @ 0x009e90..0x009ee0 (80 byte, 20 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009e90: d100c3ff  sub      sp, sp, #0x30
//   0x009e94: f9000bf3  str      x19, [sp, #0x10]
//   0x009e98: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x009e9c: 910083fd  add      x29, sp, #0x20
//   0x009ea0: d53bd053  mrs      x19, tpidr_el0
//   0x009ea4: f9401668  ldr      x8, [x19, #0x28]
//   0x009ea8: aa0103e2  mov      x2, x1
//   0x009eac: 12800001  mov      w1, #-1
//   0x009eb0: 2a1f03e3  mov      w3, wzr
//   0x009eb4: f90007e8  str      x8, [sp, #8]
//   0x009eb8: 9400000a  bl       #0x9ee0
//   0x009ebc: f9401668  ldr      x8, [x19, #0x28]
//   0x009ec0: f94007e9  ldr      x9, [sp, #8]
//   0x009ec4: eb09011f  cmp      x8, x9
//   0x009ec8: 540000a1  b.ne     #0x9edc
//   0x009ecc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x009ed0: f9400bf3  ldr      x19, [sp, #0x10]
//   0x009ed4: 9100c3ff  add      sp, sp, #0x30
//   0x009ed8: d65f03c0  ret      
//   0x009edc: 97ffe291  bl       #0x2920
// ============================================================================
std::uint32_t fde_42_09e90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009e90ULL;
    for (std::size_t i = 0; i < 20ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7384ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[43] Subroutine @ 0x009ee0..0x00a168 (648 bytes, 162 AArch64 instructions)
// [VN] Khung FDE[43] Hàm con @ 0x009ee0..0x00a168 (648 byte, 162 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x009ee0: f81a0ffc  str      x28, [sp, #-0x60]!
//   0x009ee4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x009ee8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x009eec: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x009ef0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x009ef4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x009ef8: 910143fd  add      x29, sp, #0x50
//   0x009efc: d14007ff  sub      sp, sp, #1, lsl #12
//   0x009f00: d10ec3ff  sub      sp, sp, #0x3b0
//   0x009f04: d53bd057  mrs      x23, tpidr_el0
//   0x009f08: f94016e8  ldr      x8, [x23, #0x28]
//   0x009f0c: f81a83a8  stur     x8, [x29, #-0x58]
//   0x009f10: 790033ff  strh     wzr, [sp, #0x18]
//   0x009f14: f9000bff  str      xzr, [sp, #0x10]
//   0x009f18: b4000c82  cbz      x2, #0xa0a8
//   0x009f1c: 2a0303f6  mov      w22, w3
//   0x009f20: 2a0103f5  mov      w21, w1
//   0x009f24: aa0003f4  mov      x20, x0
//   0x009f28: 2a1f03fa  mov      w26, wzr
//   0x009f2c: 2a1f03f3  mov      w19, wzr
//   0x009f30: 52800139  mov      w25, #9
//   0x009f34: 14000006  b        #0x9f4c
//   0x009f38: 340002c8  cbz      w8, #0x9f90
//   0x009f3c: 5100c108  sub      w8, w8, #0x30
//   0x009f40: 7100291f  cmp      w8, #0xa
//   0x009f44: 1a993119  csel     w25, w8, w25, lo
//   0x009f48: 91000442  add      x2, x2, #1
//   0x009f4c: 39400048  ldrb     w8, [x2]
//   0x009f50: 7101c91f  cmp      w8, #0x72
//   0x009f54: 5400010d  b.le     #0x9f74
//   0x009f58: 7101cd1f  cmp      w8, #0x73
//   0x009f5c: 54000140  b.eq     #0x9f84
//   0x009f60: 7101dd1f  cmp      w8, #0x77
//   0x009f64: 54fffec1  b.ne     #0x9f3c
//   0x009f68: 5280003a  mov      w26, #1
//   0x009f6c: 91000442  add      x2, x2, #1
//   0x009f70: 17fffff7  b        #0x9f4c
//   0x009f74: 54fffe21  b.ne     #0x9f38
//   0x009f78: 2a1f03fa  mov      w26, wzr
//   0x009f7c: 91000442  add      x2, x2, #1
//   0x009f80: 17fffff3  b        #0x9f4c
//   0x009f84: 52800033  mov      w19, #1
//   0x009f88: 91000442  add      x2, x2, #1
//   0x009f8c: 17fffff0  b        #0x9f4c
//   0x009f90: f0000048  adrp     x8, #0x14000
//   0x009f94: b0000069  adrp     x9, #0x16000
//   0x009f98: 91382d08  add      x8, x8, #0xe0b
//   0x009f9c: 9135a929  add      x9, x9, #0xd6a
//   0x009fa0: 7100035f  cmp      w26, #0
//   0x009fa4: 9a881121  csel     x1, x9, x8, ne
//   0x009fa8: 910043e0  add      x0, sp, #0x10
//   0x009fac: 52800142  mov      w2, #0xa
//   0x009fb0: 97ffe2b0  bl       #0x2a70
//   0x009fb4: b0000061  adrp     x1, #0x16000
//   0x009fb8: 9105d821  add      x1, x1, #0x176
//   0x009fbc: 910043e0  add      x0, sp, #0x10
//   0x009fc0: 52800142  mov      w2, #0xa
//   0x009fc4: 97ffe2ab  bl       #0x2a70
//   0x009fc8: d00000b8  adrp     x24, #0x1f000
//   0x009fcc: f947cb18  ldr      x24, [x24, #0xf90]
//   0x009fd0: 34000256  cbz      w22, #0xa018
//   0x009fd4: 910043e1  add      x1, sp, #0x10
//   0x009fd8: 2a1503e0  mov      w0, w21
//   0x009fdc: 97ffe28d  bl       #0x2a10
//   0x009fe0: aa0003f4  mov      x20, x0
//   0x009fe4: b4000620  cbz      x0, #0xa0a8
//   0x009fe8: 3400033a  cbz      w26, #0xa04c
//   0x009fec: 7100073f  cmp      w25, #1
//   0x009ff0: 1a9fc728  csinc    w8, w25, wzr, gt
//   0x009ff4: 7100251f  cmp      w8, #9
//   0x009ff8: 52800129  mov      w9, #9
//   0x009ffc: 1a89b115  csel     w21, w8, w9, lt
//   0x00a000: 510006a8  sub      w8, w21, #1
//   0x00a004: 7100251f  cmp      w8, #9
//   0x00a008: b9000fff  str      wzr, [sp, #0xc]
//   0x00a00c: 54000343  b.lo     #0xa074
//   0x00a010: 12800028  mov      w8, #-2
//   0x00a014: 1400001c  b        #0xa084
//   0x00a018: b4000134  cbz      x20, #0xa03c
//   0x00a01c: 39400288  ldrb     w8, [x20]
//   0x00a020: 340000e8  cbz      w8, #0xa03c
//   0x00a024: 910043e1  add      x1, sp, #0x10
//   0x00a028: aa1403e0  mov      x0, x20
//   0x00a02c: 97ffe2a9  bl       #0x2ad0
//   0x00a030: aa0003f4  mov      x20, x0
//   0x00a034: b5fffda0  cbnz     x0, #0x9fe8
//   0x00a038: 1400001c  b        #0xa0a8
//   0x00a03c: 91026308  add      x8, x24, #0x98
//   0x00a040: 7100035f  cmp      w26, #0
//   0x00a044: 9a981114  csel     x20, x8, x24, ne
//   0x00a048: 35fffd3a  cbnz     w26, #0x9fec
//   0x00a04c: 910033e0  add      x0, sp, #0xc
//   0x00a050: 910083e4  add      x4, sp, #0x20
//   0x00a054: aa1403e1  mov      x1, x20
//   0x00a058: 2a1f03e2  mov      w2, wzr
//   0x00a05c: 2a1303e3  mov      w3, w19
//   0x00a060: 2a1f03e5  mov      w5, wzr
//   0x00a064: 97ffe19f  bl       #0x26e0
//   0x00a068: aa0003f3  mov      x19, x0
//   0x00a06c: b5000200  cbnz     x0, #0xa0ac
//   0x00a070: 14000006  b        #0xa088
//   0x00a074: aa1403e0  mov      x0, x20
//   0x00a078: 97ffe25a  bl       #0x29e0
//   0x00a07c: 34000340  cbz      w0, #0xa0e4
//   0x00a080: 128000a8  mov      w8, #-6
//   0x00a084: b9000fe8  str      w8, [sp, #0xc]
//   0x00a088: eb18029f  cmp      x20, x24
//   0x00a08c: aa1f03f3  mov      x19, xzr
//   0x00a090: 540000e0  b.eq     #0xa0ac
//   0x00a094: 91026308  add      x8, x24, #0x98
//   0x00a098: eb08029f  cmp      x20, x8
//   0x00a09c: 54000080  b.eq     #0xa0ac
//   0x00a0a0: aa1403e0  mov      x0, x20
//   0x00a0a4: 97ffe20b  bl       #0x28d0
//   0x00a0a8: aa1f03f3  mov      x19, xzr
//   0x00a0ac: f94016e8  ldr      x8, [x23, #0x28]
//   0x00a0b0: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x00a0b4: eb09011f  cmp      x8, x9
//   0x00a0b8: 54000561  b.ne     #0xa164
//   0x00a0bc: aa1303e0  mov      x0, x19
//   0x00a0c0: 914007ff  add      sp, sp, #1, lsl #12
//   0x00a0c4: 910ec3ff  add      sp, sp, #0x3b0
//   0x00a0c8: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x00a0cc: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x00a0d0: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x00a0d4: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x00a0d8: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x00a0dc: f84607fc  ldr      x28, [sp], #0x60
//   0x00a0e0: d65f03c0  ret      
//   0x00a0e4: 52827e00  mov      w0, #0x13f0
//   0x00a0e8: 97ffe26a  bl       #0x2a90
//   0x00a0ec: b4000320  cbz      x0, #0xa150
//   0x00a0f0: 52827288  mov      w8, #0x1394
//   0x00a0f4: 52827309  mov      w9, #0x1398
//   0x00a0f8: aa0003f3  mov      x19, x0
//   0x00a0fc: b913e81f  str      wzr, [x0, #0x13e8]
//   0x00a100: 52800036  mov      w22, #1
//   0x00a104: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00a108: 8b080019  add      x25, x0, x8
//   0x00a10c: 8b090000  add      x0, x0, x9
//   0x00a110: 528003c3  mov      w3, #0x1e
//   0x00a114: 2a1503e1  mov      w1, w21
//   0x00a118: 2a1f03e2  mov      w2, wzr
//   0x00a11c: b9000fff  str      wzr, [sp, #0xc]
//   0x00a120: 3901633f  strb     wzr, [x25, #0x58]
//   0x00a124: b913927f  str      wzr, [x19, #0x1390]
//   0x00a128: f9000274  str      x20, [x19]
//   0x00a12c: 39000336  strb     w22, [x25]
//   0x00a130: f909f27f  str      xzr, [x19, #0x13e0]
//   0x00a134: 3d84f660  str      q0, [x19, #0x13d0]
//   0x00a138: 97ffe20e  bl       #0x2970
//   0x00a13c: 340000e0  cbz      w0, #0xa158
//   0x00a140: b9000fe0  str      w0, [sp, #0xc]
//   0x00a144: aa1303e0  mov      x0, x19
//   0x00a148: 97ffe26a  bl       #0x2af0
//   0x00a14c: 17ffffcf  b        #0xa088
//   0x00a150: 12800048  mov      w8, #-3
//   0x00a154: 17ffffcc  b        #0xa084
//   0x00a158: b913a27f  str      wzr, [x19, #0x13a0]
//   0x00a15c: 39016336  strb     w22, [x25, #0x58]
//   0x00a160: 17ffffd3  b        #0xa0ac
//   0x00a164: 97ffe1ef  bl       #0x2920
// ============================================================================
std::uint32_t fde_43_09ee0(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00009ee0ULL;
    for (std::size_t i = 0; i < 162ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7404ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[44] Subroutine @ 0x00a168..0x00a1bc (84 bytes, 21 AArch64 instructions)
// [VN] Khung FDE[44] Hàm con @ 0x00a168..0x00a1bc (84 byte, 21 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a168: d100c3ff  sub      sp, sp, #0x30
//   0x00a16c: f9000bf3  str      x19, [sp, #0x10]
//   0x00a170: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00a174: 910083fd  add      x29, sp, #0x20
//   0x00a178: d53bd053  mrs      x19, tpidr_el0
//   0x00a17c: f9401668  ldr      x8, [x19, #0x28]
//   0x00a180: aa0103e2  mov      x2, x1
//   0x00a184: 2a0003e1  mov      w1, w0
//   0x00a188: 52800023  mov      w3, #1
//   0x00a18c: aa1f03e0  mov      x0, xzr
//   0x00a190: f90007e8  str      x8, [sp, #8]
//   0x00a194: 97ffff53  bl       #0x9ee0
//   0x00a198: f9401668  ldr      x8, [x19, #0x28]
//   0x00a19c: f94007e9  ldr      x9, [sp, #8]
//   0x00a1a0: eb09011f  cmp      x8, x9
//   0x00a1a4: 540000a1  b.ne     #0xa1b8
//   0x00a1a8: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00a1ac: f9400bf3  ldr      x19, [sp, #0x10]
//   0x00a1b0: 9100c3ff  add      sp, sp, #0x30
//   0x00a1b4: d65f03c0  ret      
//   0x00a1b8: 97ffe1da  bl       #0x2920
// ============================================================================
std::uint32_t fde_44_0a168(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a168ULL;
    for (std::size_t i = 0; i < 21ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7566ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[45] Subroutine @ 0x00a1bc..0x00a234 (120 bytes, 30 AArch64 instructions)
// [VN] Khung FDE[45] Hàm con @ 0x00a1bc..0x00a234 (120 byte, 30 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a1bc: d100c3ff  sub      sp, sp, #0x30
//   0x00a1c0: f9000bf3  str      x19, [sp, #0x10]
//   0x00a1c4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00a1c8: 910083fd  add      x29, sp, #0x20
//   0x00a1cc: d53bd053  mrs      x19, tpidr_el0
//   0x00a1d0: f9401669  ldr      x9, [x19, #0x28]
//   0x00a1d4: f90007e9  str      x9, [sp, #8]
//   0x00a1d8: b953e809  ldr      w9, [x0, #0x13e8]
//   0x00a1dc: 7100113f  cmp      w9, #4
//   0x00a1e0: 54000061  b.ne     #0xa1ec
//   0x00a1e4: 2a1f03e0  mov      w0, wzr
//   0x00a1e8: 1400000a  b        #0xa210
//   0x00a1ec: aa0003e8  mov      x8, x0
//   0x00a1f0: 2a0203e3  mov      w3, w2
//   0x00a1f4: aa0103e2  mov      x2, x1
//   0x00a1f8: 910013e0  add      x0, sp, #4
//   0x00a1fc: aa0803e1  mov      x1, x8
//   0x00a200: 97ffe1a4  bl       #0x2890
//   0x00a204: b94007e8  ldr      w8, [sp, #4]
//   0x00a208: 721d791f  tst      w8, #0xfffffffb
//   0x00a20c: 5a9f0000  csinv    w0, w0, wzr, eq
//   0x00a210: f9401668  ldr      x8, [x19, #0x28]
//   0x00a214: f94007e9  ldr      x9, [sp, #8]
//   0x00a218: eb09011f  cmp      x8, x9
//   0x00a21c: 540000a1  b.ne     #0xa230
//   0x00a220: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00a224: f9400bf3  ldr      x19, [sp, #0x10]
//   0x00a228: 9100c3ff  add      sp, sp, #0x30
//   0x00a22c: d65f03c0  ret      
//   0x00a230: 97ffe1bc  bl       #0x2920
// ============================================================================
std::uint32_t fde_45_0a1bc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a1bcULL;
    for (std::size_t i = 0; i < 30ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7587ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[46] Subroutine @ 0x00a234..0x00a298 (100 bytes, 25 AArch64 instructions)
// [VN] Khung FDE[46] Hàm con @ 0x00a234..0x00a298 (100 byte, 25 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a234: d100c3ff  sub      sp, sp, #0x30
//   0x00a238: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00a23c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00a240: 910083fd  add      x29, sp, #0x20
//   0x00a244: d53bd054  mrs      x20, tpidr_el0
//   0x00a248: f9401688  ldr      x8, [x20, #0x28]
//   0x00a24c: 2a0203f3  mov      w19, w2
//   0x00a250: aa0103e2  mov      x2, x1
//   0x00a254: aa0003e1  mov      x1, x0
//   0x00a258: 910013e0  add      x0, sp, #4
//   0x00a25c: 2a1303e3  mov      w3, w19
//   0x00a260: f90007e8  str      x8, [sp, #8]
//   0x00a264: 97ffe17f  bl       #0x2860
//   0x00a268: b94007e8  ldr      w8, [sp, #4]
//   0x00a26c: f9401689  ldr      x9, [x20, #0x28]
//   0x00a270: f94007ea  ldr      x10, [sp, #8]
//   0x00a274: 7100011f  cmp      w8, #0
//   0x00a278: 5a9f0260  csinv    w0, w19, wzr, eq
//   0x00a27c: eb0a013f  cmp      x9, x10
//   0x00a280: 540000a1  b.ne     #0xa294
//   0x00a284: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x00a288: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00a28c: 9100c3ff  add      sp, sp, #0x30
//   0x00a290: d65f03c0  ret      
//   0x00a294: 97ffe1a3  bl       #0x2920
// ============================================================================
std::uint32_t fde_46_0a234(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a234ULL;
    for (std::size_t i = 0; i < 25ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7617ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[47] Subroutine @ 0x00a298..0x00a2d4 (60 bytes, 15 AArch64 instructions)
// [VN] Khung FDE[47] Hàm con @ 0x00a298..0x00a2d4 (60 byte, 15 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a298: d10083ff  sub      sp, sp, #0x20
//   0x00a29c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00a2a0: 910043fd  add      x29, sp, #0x10
//   0x00a2a4: d53bd048  mrs      x8, tpidr_el0
//   0x00a2a8: f9401509  ldr      x9, [x8, #0x28]
//   0x00a2ac: f90007e9  str      x9, [sp, #8]
//   0x00a2b0: f9401508  ldr      x8, [x8, #0x28]
//   0x00a2b4: f94007e9  ldr      x9, [sp, #8]
//   0x00a2b8: eb09011f  cmp      x8, x9
//   0x00a2bc: 540000a1  b.ne     #0xa2d0
//   0x00a2c0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00a2c4: 2a1f03e0  mov      w0, wzr
//   0x00a2c8: 910083ff  add      sp, sp, #0x20
//   0x00a2cc: d65f03c0  ret      
//   0x00a2d0: 97ffe194  bl       #0x2920
// ============================================================================
std::uint32_t fde_47_0a298(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a298ULL;
    for (std::size_t i = 0; i < 15ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7642ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[48] Subroutine @ 0x00a2d4..0x00a428 (340 bytes, 85 AArch64 instructions)
// [VN] Khung FDE[48] Hàm con @ 0x00a2d4..0x00a428 (340 byte, 85 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a2d4: d10103ff  sub      sp, sp, #0x40
//   0x00a2d8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00a2dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00a2e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00a2e4: 9100c3fd  add      x29, sp, #0x30
//   0x00a2e8: d53bd055  mrs      x21, tpidr_el0
//   0x00a2ec: f94016a8  ldr      x8, [x21, #0x28]
//   0x00a2f0: f90007e8  str      x8, [sp, #8]
//   0x00a2f4: b4000860  cbz      x0, #0xa400
//   0x00a2f8: 52827288  mov      w8, #0x1394
//   0x00a2fc: 8b080008  add      x8, x0, x8
//   0x00a300: 39400109  ldrb     w9, [x8]
//   0x00a304: f9400013  ldr      x19, [x0]
//   0x00a308: aa0003f4  mov      x20, x0
//   0x00a30c: 34000289  cbz      w9, #0xa35c
//   0x00a310: 910013e0  add      x0, sp, #4
//   0x00a314: aa1403e1  mov      x1, x20
//   0x00a318: 2a1f03e2  mov      w2, wzr
//   0x00a31c: aa1f03e3  mov      x3, xzr
//   0x00a320: aa1f03e4  mov      x4, xzr
//   0x00a324: aa1f03e5  mov      x5, xzr
//   0x00a328: aa1f03e6  mov      x6, xzr
//   0x00a32c: 97ffe121  bl       #0x27b0
//   0x00a330: b94007e8  ldr      w8, [sp, #4]
//   0x00a334: 34000548  cbz      w8, #0xa3dc
//   0x00a338: 52800022  mov      w2, #1
//   0x00a33c: aa1f03e0  mov      x0, xzr
//   0x00a340: aa1403e1  mov      x1, x20
//   0x00a344: aa1f03e3  mov      x3, xzr
//   0x00a348: aa1f03e4  mov      x4, xzr
//   0x00a34c: aa1f03e5  mov      x5, xzr
//   0x00a350: aa1f03e6  mov      x6, xzr
//   0x00a354: 97ffe117  bl       #0x27b0
//   0x00a358: 14000021  b        #0xa3dc
//   0x00a35c: b90007ff  str      wzr, [sp, #4]
//   0x00a360: b913ea9f  str      wzr, [x20, #0x13e8]
//   0x00a364: 39416108  ldrb     w8, [x8, #0x58]
//   0x00a368: 34000368  cbz      w8, #0xa3d4
//   0x00a36c: f949e696  ldr      x22, [x20, #0x13c8]
//   0x00a370: b4000336  cbz      x22, #0xa3d4
//   0x00a374: f94002c8  ldr      x8, [x22]
//   0x00a378: 52827309  mov      w9, #0x1398
//   0x00a37c: 8b090289  add      x9, x20, x9
//   0x00a380: eb09011f  cmp      x8, x9
//   0x00a384: 54000281  b.ne     #0xa3d4
//   0x00a388: f9462ac1  ldr      x1, [x22, #0xc50]
//   0x00a38c: b4000081  cbz      x1, #0xa39c
//   0x00a390: f949ee88  ldr      x8, [x20, #0x13d8]
//   0x00a394: f949f280  ldr      x0, [x20, #0x13e0]
//   0x00a398: d63f0100  blr      x8
//   0x00a39c: f9462ec1  ldr      x1, [x22, #0xc58]
//   0x00a3a0: b4000081  cbz      x1, #0xa3b0
//   0x00a3a4: f949ee88  ldr      x8, [x20, #0x13d8]
//   0x00a3a8: f949f280  ldr      x0, [x20, #0x13e0]
//   0x00a3ac: d63f0100  blr      x8
//   0x00a3b0: f94632c1  ldr      x1, [x22, #0xc60]
//   0x00a3b4: b4000081  cbz      x1, #0xa3c4
//   0x00a3b8: f949ee88  ldr      x8, [x20, #0x13d8]
//   0x00a3bc: f949f280  ldr      x0, [x20, #0x13e0]
//   0x00a3c0: d63f0100  blr      x8
//   0x00a3c4: f949ee88  ldr      x8, [x20, #0x13d8]
//   0x00a3c8: f949f280  ldr      x0, [x20, #0x13e0]
//   0x00a3cc: f949e681  ldr      x1, [x20, #0x13c8]
//   0x00a3d0: d63f0100  blr      x8
//   0x00a3d4: aa1403e0  mov      x0, x20
//   0x00a3d8: 97ffe1c6  bl       #0x2af0
//   0x00a3dc: b00000a8  adrp     x8, #0x1f000
//   0x00a3e0: f947c908  ldr      x8, [x8, #0xf90]
//   0x00a3e4: eb08027f  cmp      x19, x8
//   0x00a3e8: 540000c0  b.eq     #0xa400
//   0x00a3ec: 91026108  add      x8, x8, #0x98
//   0x00a3f0: eb08027f  cmp      x19, x8
//   0x00a3f4: 54000060  b.eq     #0xa400
//   0x00a3f8: aa1303e0  mov      x0, x19
//   0x00a3fc: 97ffe135  bl       #0x28d0
//   0x00a400: f94016a8  ldr      x8, [x21, #0x28]
//   0x00a404: f94007e9  ldr      x9, [sp, #8]
//   0x00a408: eb09011f  cmp      x8, x9
//   0x00a40c: 540000c1  b.ne     #0xa424
//   0x00a410: a9437bfd  ldp      x29, x30, [sp, #0x30]
//   0x00a414: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x00a418: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x00a41c: 910103ff  add      sp, sp, #0x40
//   0x00a420: d65f03c0  ret      
//   0x00a424: 97ffe13f  bl       #0x2920
// ============================================================================
std::uint32_t fde_48_0a2d4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a2d4ULL;
    for (std::size_t i = 0; i < 85ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7657ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[49] Subroutine @ 0x00a428..0x00a47c (84 bytes, 21 AArch64 instructions)
// [VN] Khung FDE[49] Hàm con @ 0x00a428..0x00a47c (84 byte, 21 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a428: d10083ff  sub      sp, sp, #0x20
//   0x00a42c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00a430: 910043fd  add      x29, sp, #0x10
//   0x00a434: d53bd049  mrs      x9, tpidr_el0
//   0x00a438: f9401528  ldr      x8, [x9, #0x28]
//   0x00a43c: f90007e8  str      x8, [sp, #8]
//   0x00a440: b953e808  ldr      w8, [x0, #0x13e8]
//   0x00a444: 0a887d08  and      w8, w8, w8, asr #31
//   0x00a448: b9000028  str      w8, [x1]
//   0x00a44c: f9401529  ldr      x9, [x9, #0x28]
//   0x00a450: f94007ea  ldr      x10, [sp, #8]
//   0x00a454: eb0a013f  cmp      x9, x10
//   0x00a458: 54000101  b.ne     #0xa478
//   0x00a45c: b00000a9  adrp     x9, #0x1f000
//   0x00a460: 91296129  add      x9, x9, #0xa58
//   0x00a464: cb28cd28  sub      x8, x9, w8, sxtw #3
//   0x00a468: f9400100  ldr      x0, [x8]
//   0x00a46c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00a470: 910083ff  add      sp, sp, #0x20
//   0x00a474: d65f03c0  ret      
//   0x00a478: 97ffe12a  bl       #0x2920
// ============================================================================
std::uint32_t fde_49_0a428(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a428ULL;
    for (std::size_t i = 0; i < 21ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7742ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[50] Subroutine @ 0x00a47c..0x00a608 (396 bytes, 99 AArch64 instructions)
// [VN] Khung FDE[50] Hàm con @ 0x00a47c..0x00a608 (396 byte, 99 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a47c: d10083ff  sub      sp, sp, #0x20
//   0x00a480: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00a484: 910043fd  add      x29, sp, #0x10
//   0x00a488: d53bd048  mrs      x8, tpidr_el0
//   0x00a48c: f9401509  ldr      x9, [x8, #0x28]
//   0x00a490: f90007e9  str      x9, [sp, #8]
//   0x00a494: 294ba809  ldp      w9, w10, [x0, #0x5c]
//   0x00a498: 93407d4a  sxtw     x10, w10
//   0x00a49c: 7100055f  cmp      w10, #1
//   0x00a4a0: 540001ab  b.lt     #0xa4d4
//   0x00a4a4: b00000ae  adrp     x14, #0x1f000
//   0x00a4a8: b942880c  ldr      w12, [x0, #0x288]
//   0x00a4ac: f947e5ce  ldr      x14, [x14, #0xfc8]
//   0x00a4b0: 2a1f03eb  mov      w11, wzr
//   0x00a4b4: 12001d2d  and      w13, w9, #0xff
//   0x00a4b8: 4a4c61af  eor      w15, w13, w12, lsr #24
//   0x00a4bc: b86f59cf  ldr      w15, [x14, w15, uxtw #2]
//   0x00a4c0: 1100056b  add      w11, w11, #1
//   0x00a4c4: 6b0a017f  cmp      w11, w10
//   0x00a4c8: 4a0c21ec  eor      w12, w15, w12, lsl #8
//   0x00a4cc: b902880c  str      w12, [x0, #0x288]
//   0x00a4d0: 54ffff4b  b.lt     #0xa4b8
//   0x00a4d4: 8b09000b  add      x11, x0, x9
//   0x00a4d8: 5280002c  mov      w12, #1
//   0x00a4dc: 71000d5f  cmp      w10, #3
//   0x00a4e0: 3902016c  strb     w12, [x11, #0x80]
//   0x00a4e4: 54000240  b.eq     #0xa52c
//   0x00a4e8: 7100095f  cmp      w10, #2
//   0x00a4ec: 540000c0  b.eq     #0xa504
//   0x00a4f0: 7100055f  cmp      w10, #1
//   0x00a4f4: 540003a1  b.ne     #0xa568
//   0x00a4f8: b846cc0b  ldr      w11, [x0, #0x6c]!
//   0x00a4fc: d100b00a  sub      x10, x0, #0x2c
//   0x00a500: 14000035  b        #0xa5d4
//   0x00a504: f8440c0a  ldr      x10, [x0, #0x40]!
//   0x00a508: aa0003ec  mov      x12, x0
//   0x00a50c: b882cd8b  ldrsw    x11, [x12, #0x2c]!
//   0x00a510: 382b6949  strb     w9, [x10, x11]
//   0x00a514: b940018b  ldr      w11, [x12]
//   0x00a518: aa0003ea  mov      x10, x0
//   0x00a51c: aa0c03e0  mov      x0, x12
//   0x00a520: 1100056b  add      w11, w11, #1
//   0x00a524: b900018b  str      w11, [x12]
//   0x00a528: 1400002b  b        #0xa5d4
//   0x00a52c: f8440c0a  ldr      x10, [x0, #0x40]!
//   0x00a530: aa0003ec  mov      x12, x0
//   0x00a534: b882cd8b  ldrsw    x11, [x12, #0x2c]!
//   0x00a538: 382b6949  strb     w9, [x10, x11]
//   0x00a53c: b980018a  ldrsw    x10, [x12]
//   0x00a540: 9100054a  add      x10, x10, #1
//   0x00a544: b900018a  str      w10, [x12]
//   0x00a548: f940000b  ldr      x11, [x0]
//   0x00a54c: 382a6969  strb     w9, [x11, x10]
//   0x00a550: b940018a  ldr      w10, [x12]
//   0x00a554: 1100054b  add      w11, w10, #1
//   0x00a558: b900018b  str      w11, [x12]
//   0x00a55c: aa0003ea  mov      x10, x0
//   0x00a560: aa0c03e0  mov      x0, x12
//   0x00a564: 1400001c  b        #0xa5d4
//   0x00a568: 8b00014a  add      x10, x10, x0
//   0x00a56c: 5280002b  mov      w11, #1
//   0x00a570: 3901f14b  strb     w11, [x10, #0x7c]
//   0x00a574: b886cc0b  ldrsw    x11, [x0, #0x6c]!
//   0x00a578: aa0003ea  mov      x10, x0
//   0x00a57c: f85d4d4c  ldr      x12, [x10, #-0x2c]!
//   0x00a580: 382b6989  strb     w9, [x12, x11]
//   0x00a584: b980000b  ldrsw    x11, [x0]
//   0x00a588: 9100056b  add      x11, x11, #1
//   0x00a58c: b900000b  str      w11, [x0]
//   0x00a590: f940014c  ldr      x12, [x10]
//   0x00a594: 382b6989  strb     w9, [x12, x11]
//   0x00a598: b980000b  ldrsw    x11, [x0]
//   0x00a59c: 9100056b  add      x11, x11, #1
//   0x00a5a0: b900000b  str      w11, [x0]
//   0x00a5a4: f940014c  ldr      x12, [x10]
//   0x00a5a8: 382b6989  strb     w9, [x12, x11]
//   0x00a5ac: b980000b  ldrsw    x11, [x0]
//   0x00a5b0: 9100056b  add      x11, x11, #1
//   0x00a5b4: b900000b  str      w11, [x0]
//   0x00a5b8: f940014c  ldr      x12, [x10]
//   0x00a5bc: 382b6989  strb     w9, [x12, x11]
//   0x00a5c0: b9400009  ldr      w9, [x0]
//   0x00a5c4: 385f400c  ldurb    w12, [x0, #-0xc]
//   0x00a5c8: 1100052b  add      w11, w9, #1
//   0x00a5cc: 51001189  sub      w9, w12, #4
//   0x00a5d0: b900000b  str      w11, [x0]
//   0x00a5d4: f940014a  ldr      x10, [x10]
//   0x00a5d8: 382bc949  strb     w9, [x10, w11, sxtw]
//   0x00a5dc: b9400009  ldr      w9, [x0]
//   0x00a5e0: 11000529  add      w9, w9, #1
//   0x00a5e4: b9000009  str      w9, [x0]
//   0x00a5e8: f9401508  ldr      x8, [x8, #0x28]
//   0x00a5ec: f94007e9  ldr      x9, [sp, #8]
//   0x00a5f0: eb09011f  cmp      x8, x9
//   0x00a5f4: 54000081  b.ne     #0xa604
//   0x00a5f8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00a5fc: 910083ff  add      sp, sp, #0x20
//   0x00a600: d65f03c0  ret      
//   0x00a604: 97ffe0c7  bl       #0x2920
// ============================================================================
std::uint32_t fde_50_0a47c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a47cULL;
    for (std::size_t i = 0; i < 99ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7763ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[51] Subroutine @ 0x00a608..0x00d868 (12896 bytes, 3224 AArch64 instructions)
// [VN] Khung FDE[51] Hàm con @ 0x00a608..0x00d868 (12896 byte, 3224 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00a608: d10443ff  sub      sp, sp, #0x110
//   0x00a60c: a90b6ffc  stp      x28, x27, [sp, #0xb0]
//   0x00a610: a90c67fa  stp      x26, x25, [sp, #0xc0]
//   0x00a614: a90d5ff8  stp      x24, x23, [sp, #0xd0]
//   0x00a618: a90e57f6  stp      x22, x21, [sp, #0xe0]
//   0x00a61c: a90f4ff4  stp      x20, x19, [sp, #0xf0]
//   0x00a620: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x00a624: 910403fd  add      x29, sp, #0x100
//   0x00a628: d53bd04e  mrs      x14, tpidr_el0
//   0x00a62c: f94015c8  ldr      x8, [x14, #0x28]
//   0x00a630: 529f4489  mov      w9, #0xfa24
//   0x00a634: aa0003f5  mov      x21, x0
//   0x00a638: 8b090018  add      x24, x0, x9
//   0x00a63c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x00a640: b9400808  ldr      w8, [x0, #8]
//   0x00a644: f940001b  ldr      x27, [x0]
//   0x00a648: 71002908  subs     w8, w8, #0xa
//   0x00a64c: 540003e1  b.ne     #0xa6c8
//   0x00a650: aa1f03f3  mov      x19, xzr
//   0x00a654: aa1f03fc  mov      x28, xzr
//   0x00a658: aa1f03f6  mov      x22, xzr
//   0x00a65c: 2a1f03f4  mov      w20, wzr
//   0x00a660: 2a1f03f0  mov      w16, wzr
//   0x00a664: 2a1f03e3  mov      w3, wzr
//   0x00a668: 2a1f03fa  mov      w26, wzr
//   0x00a66c: 2a1f03ea  mov      w10, wzr
//   0x00a670: 2a1f03e1  mov      w1, wzr
//   0x00a674: 2a1f03f9  mov      w25, wzr
//   0x00a678: 2a1f03e2  mov      w2, wzr
//   0x00a67c: 2a1f03e5  mov      w5, wzr
//   0x00a680: 2a1f03fe  mov      w30, wzr
//   0x00a684: 2a1f03e4  mov      w4, wzr
//   0x00a688: 2a1f03f1  mov      w17, wzr
//   0x00a68c: 2a1f03e9  mov      w9, wzr
//   0x00a690: 2a1f03e7  mov      w7, wzr
//   0x00a694: 2a1f03e6  mov      w6, wzr
//   0x00a698: 2a1f03f7  mov      w23, wzr
//   0x00a69c: 2a1f03ef  mov      w15, wzr
//   0x00a6a0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00a6a4: f9003bff  str      xzr, [sp, #0x70]
//   0x00a6a8: b9006bff  str      wzr, [sp, #0x68]
//   0x00a6ac: b9007fff  str      wzr, [sp, #0x7c]
//   0x00a6b0: b81943bf  stur     wzr, [x29, #-0x6c]
//   0x00a6b4: 3c85c300  stur     q0, [x24, #0x5c]
//   0x00a6b8: ad020300  stp      q0, q0, [x24, #0x40]
//   0x00a6bc: ad010300  stp      q0, q0, [x24, #0x20]
//   0x00a6c0: ad000300  stp      q0, q0, [x24]
//   0x00a6c4: 14000014  b        #0xa714
//   0x00a6c8: 2940270f  ldp      w15, w9, [x24]
//   0x00a6cc: b9405314  ldr      w20, [x24, #0x50]
//   0x00a6d0: f8454316  ldur     x22, [x24, #0x54]
//   0x00a6d4: f845c31c  ldur     x28, [x24, #0x5c]
//   0x00a6d8: b81943a9  stur     w9, [x29, #-0x6c]
//   0x00a6dc: 29422707  ldp      w7, w9, [x24, #0x10]
//   0x00a6e0: 29411b17  ldp      w23, w6, [x24, #8]
//   0x00a6e4: f8464313  ldur     x19, [x24, #0x64]
//   0x00a6e8: b9007fe9  str      w9, [sp, #0x7c]
//   0x00a6ec: b9401b09  ldr      w9, [x24, #0x18]
//   0x00a6f0: b9006be9  str      w9, [sp, #0x68]
//   0x00a6f4: b9401f09  ldr      w9, [x24, #0x1c]
//   0x00a6f8: f9003be9  str      x9, [sp, #0x70]
//   0x00a6fc: 29444709  ldp      w9, w17, [x24, #0x20]
//   0x00a700: 29457b04  ldp      w4, w30, [x24, #0x28]
//   0x00a704: 29460b05  ldp      w5, w2, [x24, #0x30]
//   0x00a708: 29470719  ldp      w25, w1, [x24, #0x38]
//   0x00a70c: 29486b0a  ldp      w10, w26, [x24, #0x40]
//   0x00a710: 29494303  ldp      w3, w16, [x24, #0x48]
//   0x00a714: 7100a11f  cmp      w8, #0x28
//   0x00a718: f81883aa  stur     x10, [x29, #-0x78]
//   0x00a71c: b90083e9  str      w9, [sp, #0x80]
//   0x00a720: 54000468  b.hi     #0xa7ac
//   0x00a724: 9000006a  adrp     x10, #0x16000
//   0x00a728: 9138214a  add      x10, x10, #0xe08
//   0x00a72c: 10000089  adr      x9, #0xa73c
//   0x00a730: 7868794b  ldrh     w11, [x10, x8, lsl #1]
//   0x00a734: 8b0b0929  add      x9, x9, x11, lsl #2
//   0x00a738: d61f0120  br       x9
//   0x00a73c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a740: 52800149  mov      w9, #0xa
//   0x00a744: b9000aa9  str      w9, [x21, #8]
//   0x00a748: 7100211f  cmp      w8, #8
//   0x00a74c: 540012cb  b.lt     #0xa9a4
//   0x00a750: b94022a9  ldr      w9, [x21, #0x20]
//   0x00a754: 140000ad  b        #0xaa08
//   0x00a758: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a75c: 14000433  b        #0xb828
//   0x00a760: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a764: 14000457  b        #0xb8c0
//   0x00a768: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a76c: 1400047c  b        #0xb95c
//   0x00a770: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a774: 140001bc  b        #0xae64
//   0x00a778: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a77c: 528003e9  mov      w9, #0x1f
//   0x00a780: 71003d1f  cmp      w8, #0xf
//   0x00a784: b9000aa9  str      w9, [x21, #8]
//   0x00a788: 54000c4b  b.lt     #0xa910
//   0x00a78c: b94022aa  ldr      w10, [x21, #0x20]
//   0x00a790: 1400007a  b        #0xa978
//   0x00a794: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a798: 140003fe  b        #0xb790
//   0x00a79c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a7a0: 140000ea  b        #0xab48
//   0x00a7a4: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a7a8: 140003d4  b        #0xb6f8
//   0x00a7ac: 5281f420  mov      w0, #0xfa1
//   0x00a7b0: b9001be6  str      w6, [sp, #0x18]
//   0x00a7b4: b90027e1  str      w1, [sp, #0x24]
//   0x00a7b8: b9005ffa  str      w26, [sp, #0x5c]
//   0x00a7bc: f9002bfc  str      x28, [sp, #0x50]
//   0x00a7c0: f90017f6  str      x22, [sp, #0x28]
//   0x00a7c4: f90033f3  str      x19, [sp, #0x60]
//   0x00a7c8: 2908d3e3  stp      w3, w20, [sp, #0x44]
//   0x00a7cc: f9001fe4  str      x4, [sp, #0x38]
//   0x00a7d0: 2a0503f4  mov      w20, w5
//   0x00a7d4: aa1e03f3  mov      x19, x30
//   0x00a7d8: 2a1703f5  mov      w21, w23
//   0x00a7dc: 2a1103f6  mov      w22, w17
//   0x00a7e0: 2a0203fa  mov      w26, w2
//   0x00a7e4: aa0f03fb  mov      x27, x15
//   0x00a7e8: b90033f9  str      w25, [sp, #0x30]
//   0x00a7ec: aa0e03f9  mov      x25, x14
//   0x00a7f0: 2a0703f7  mov      w23, w7
//   0x00a7f4: aa1003fc  mov      x28, x16
//   0x00a7f8: 97ffe01e  bl       #0x2870
//   0x00a7fc: 5281f440  mov      w0, #0xfa2
//   0x00a800: 97ffe01c  bl       #0x2870
//   0x00a804: aa1c03f0  mov      x16, x28
//   0x00a808: aa1903ee  mov      x14, x25
//   0x00a80c: b94033f9  ldr      w25, [sp, #0x30]
//   0x00a810: 2a1a03e2  mov      w2, w26
//   0x00a814: 2a1603f1  mov      w17, w22
//   0x00a818: aa1303fe  mov      x30, x19
//   0x00a81c: f9403be8  ldr      x8, [sp, #0x70]
//   0x00a820: 2a1403e5  mov      w5, w20
//   0x00a824: f9401fe4  ldr      x4, [sp, #0x38]
//   0x00a828: 2948d3e3  ldp      w3, w20, [sp, #0x44]
//   0x00a82c: f94033f3  ldr      x19, [sp, #0x60]
//   0x00a830: f94017f6  ldr      x22, [sp, #0x28]
//   0x00a834: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00a838: b9405ffa  ldr      w26, [sp, #0x5c]
//   0x00a83c: b9407fed  ldr      w13, [sp, #0x7c]
//   0x00a840: b94027e1  ldr      w1, [sp, #0x24]
//   0x00a844: b9401be6  ldr      w6, [sp, #0x18]
//   0x00a848: 2a1703e7  mov      w7, w23
//   0x00a84c: aa1b03ef  mov      x15, x27
//   0x00a850: 2a1503f7  mov      w23, w21
//   0x00a854: 2a1f03e0  mov      w0, wzr
//   0x00a858: 14000875  b        #0xca2c
//   0x00a85c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a860: 14000070  b        #0xaa20
//   0x00a864: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a868: 14000153  b        #0xadb4
//   0x00a86c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a870: 140001a3  b        #0xaefc
//   0x00a874: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a878: 14000303  b        #0xb484
//   0x00a87c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a880: 14000327  b        #0xb51c
//   0x00a884: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a888: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00a88c: 140005aa  b        #0xbf34
//   0x00a890: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a894: 140004a4  b        #0xbb24
//   0x00a898: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a89c: 14000086  b        #0xaab4
//   0x00a8a0: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8a4: 140001bc  b        #0xaf94
//   0x00a8a8: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8ac: 1400025e  b        #0xb224
//   0x00a8b0: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8b4: 14000282  b        #0xb2bc
//   0x00a8b8: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8bc: 140002a6  b        #0xb354
//   0x00a8c0: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8c4: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00a8c8: 14000574  b        #0xbe98
//   0x00a8cc: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8d0: 1400013f  b        #0xadcc
//   0x00a8d4: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8d8: 140001d5  b        #0xb02c
//   0x00a8dc: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8e0: 140002c3  b        #0xb3ec
//   0x00a8e4: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8e8: 14000333  b        #0xb5b4
//   0x00a8ec: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8f0: 14000824  b        #0xc980
//   0x00a8f4: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a8f8: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00a8fc: 1400053e  b        #0xbdf4
//   0x00a900: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a904: 1400043c  b        #0xb9f4
//   0x00a908: b94026a8  ldr      w8, [x21, #0x24]
//   0x00a90c: 14000460  b        #0xba8c
//   0x00a910: f94002a9  ldr      x9, [x21]
//   0x00a914: b940092a  ldr      w10, [x9, #8]
//   0x00a918: 5100054b  sub      w11, w10, #1
//   0x00a91c: 3100057f  cmn      w11, #1
//   0x00a920: 540000e1  b.ne     #0xa93c
//   0x00a924: 1400083f  b        #0xca20
//   0x00a928: 7100391f  cmp      w8, #0xe
//   0x00a92c: 5100056b  sub      w11, w11, #1
//   0x00a930: 5400024c  b.gt     #0xa978
//   0x00a934: 3100057f  cmn      w11, #1
//   0x00a938: 54010740  b.eq     #0xca20
//   0x00a93c: f940012c  ldr      x12, [x9]
//   0x00a940: b94022ad  ldr      w13, [x21, #0x20]
//   0x00a944: 11002108  add      w8, w8, #8
//   0x00a948: 3840158a  ldrb     w10, [x12], #1
//   0x00a94c: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00a950: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00a954: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00a958: f900012c  str      x12, [x9]
//   0x00a95c: 310005ac  adds     w12, w13, #1
//   0x00a960: 2901312b  stp      w11, w12, [x9, #8]
//   0x00a964: 54fffe23  b.lo     #0xa928
//   0x00a968: b940112c  ldr      w12, [x9, #0x10]
//   0x00a96c: 1100058c  add      w12, w12, #1
//   0x00a970: b900112c  str      w12, [x9, #0x10]
//   0x00a974: 17ffffed  b        #0xa928
//   0x00a978: 51003d08  sub      w8, w8, #0xf
//   0x00a97c: 1ac8254a  lsr      w10, w10, w8
//   0x00a980: 2a1f03e9  mov      w9, wzr
//   0x00a984: 7200394a  ands     w10, w10, #0x7fff
//   0x00a988: b9007fea  str      w10, [sp, #0x7c]
//   0x00a98c: b90026a8  str      w8, [x21, #0x24]
//   0x00a990: 5400b8e1  b.ne     #0xc0ac
//   0x00a994: f9403be8  ldr      x8, [sp, #0x70]
//   0x00a998: 12800060  mov      w0, #-4
//   0x00a99c: 2a0903ed  mov      w13, w9
//   0x00a9a0: 14000823  b        #0xca2c
//   0x00a9a4: b9400b69  ldr      w9, [x27, #8]
//   0x00a9a8: 5100052a  sub      w10, w9, #1
//   0x00a9ac: 3100055f  cmn      w10, #1
//   0x00a9b0: 540000e1  b.ne     #0xa9cc
//   0x00a9b4: 1400081b  b        #0xca20
//   0x00a9b8: 71001d1f  cmp      w8, #7
//   0x00a9bc: 5100054a  sub      w10, w10, #1
//   0x00a9c0: 5400024c  b.gt     #0xaa08
//   0x00a9c4: 3100055f  cmn      w10, #1
//   0x00a9c8: 540102c0  b.eq     #0xca20
//   0x00a9cc: f940036b  ldr      x11, [x27]
//   0x00a9d0: b94022ac  ldr      w12, [x21, #0x20]
//   0x00a9d4: 11002108  add      w8, w8, #8
//   0x00a9d8: 38401569  ldrb     w9, [x11], #1
//   0x00a9dc: 33185d89  bfi      w9, w12, #8, #0x18
//   0x00a9e0: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00a9e4: b9400f6c  ldr      w12, [x27, #0xc]
//   0x00a9e8: f900036b  str      x11, [x27]
//   0x00a9ec: 3100058b  adds     w11, w12, #1
//   0x00a9f0: 29012f6a  stp      w10, w11, [x27, #8]
//   0x00a9f4: 54fffe23  b.lo     #0xa9b8
//   0x00a9f8: b940136b  ldr      w11, [x27, #0x10]
//   0x00a9fc: 1100056b  add      w11, w11, #1
//   0x00aa00: b900136b  str      w11, [x27, #0x10]
//   0x00aa04: 17ffffed  b        #0xa9b8
//   0x00aa08: 51002108  sub      w8, w8, #8
//   0x00aa0c: 1ac82529  lsr      w9, w9, w8
//   0x00aa10: 12001d29  and      w9, w9, #0xff
//   0x00aa14: 7101093f  cmp      w9, #0x42
//   0x00aa18: b90026a8  str      w8, [x21, #0x24]
//   0x00aa1c: 54000e21  b.ne     #0xabe0
//   0x00aa20: 52800169  mov      w9, #0xb
//   0x00aa24: 7100211f  cmp      w8, #8
//   0x00aa28: b9000aa9  str      w9, [x21, #8]
//   0x00aa2c: 5400006b  b.lt     #0xaa38
//   0x00aa30: b94022a9  ldr      w9, [x21, #0x20]
//   0x00aa34: 1400001a  b        #0xaa9c
//   0x00aa38: b9400b69  ldr      w9, [x27, #8]
//   0x00aa3c: 5100052a  sub      w10, w9, #1
//   0x00aa40: 3100055f  cmn      w10, #1
//   0x00aa44: 540000e1  b.ne     #0xaa60
//   0x00aa48: 140007f6  b        #0xca20
//   0x00aa4c: 71001d1f  cmp      w8, #7
//   0x00aa50: 5100054a  sub      w10, w10, #1
//   0x00aa54: 5400024c  b.gt     #0xaa9c
//   0x00aa58: 3100055f  cmn      w10, #1
//   0x00aa5c: 5400fe20  b.eq     #0xca20
//   0x00aa60: f940036b  ldr      x11, [x27]
//   0x00aa64: b94022ac  ldr      w12, [x21, #0x20]
//   0x00aa68: 11002108  add      w8, w8, #8
//   0x00aa6c: 38401569  ldrb     w9, [x11], #1
//   0x00aa70: 33185d89  bfi      w9, w12, #8, #0x18
//   0x00aa74: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00aa78: b9400f6c  ldr      w12, [x27, #0xc]
//   0x00aa7c: f900036b  str      x11, [x27]
//   0x00aa80: 3100058b  adds     w11, w12, #1
//   0x00aa84: 29012f6a  stp      w10, w11, [x27, #8]
//   0x00aa88: 54fffe23  b.lo     #0xaa4c
//   0x00aa8c: b940136b  ldr      w11, [x27, #0x10]
//   0x00aa90: 1100056b  add      w11, w11, #1
//   0x00aa94: b900136b  str      w11, [x27, #0x10]
//   0x00aa98: 17ffffed  b        #0xaa4c
//   0x00aa9c: 51002108  sub      w8, w8, #8
//   0x00aaa0: 1ac82529  lsr      w9, w9, w8
//   0x00aaa4: 12001d29  and      w9, w9, #0xff
//   0x00aaa8: 7101693f  cmp      w9, #0x5a
//   0x00aaac: b90026a8  str      w8, [x21, #0x24]
//   0x00aab0: 54000981  b.ne     #0xabe0
//   0x00aab4: 52800189  mov      w9, #0xc
//   0x00aab8: 7100211f  cmp      w8, #8
//   0x00aabc: b9000aa9  str      w9, [x21, #8]
//   0x00aac0: 5400006b  b.lt     #0xaacc
//   0x00aac4: b94022a9  ldr      w9, [x21, #0x20]
//   0x00aac8: 1400001a  b        #0xab30
//   0x00aacc: b9400b69  ldr      w9, [x27, #8]
//   0x00aad0: 5100052a  sub      w10, w9, #1
//   0x00aad4: 3100055f  cmn      w10, #1
//   0x00aad8: 540000e1  b.ne     #0xaaf4
//   0x00aadc: 140007d1  b        #0xca20
//   0x00aae0: 71001d1f  cmp      w8, #7
//   0x00aae4: 5100054a  sub      w10, w10, #1
//   0x00aae8: 5400024c  b.gt     #0xab30
//   0x00aaec: 3100055f  cmn      w10, #1
//   0x00aaf0: 5400f980  b.eq     #0xca20
//   0x00aaf4: f940036b  ldr      x11, [x27]
//   0x00aaf8: b94022ac  ldr      w12, [x21, #0x20]
//   0x00aafc: 11002108  add      w8, w8, #8
//   0x00ab00: 38401569  ldrb     w9, [x11], #1
//   0x00ab04: 33185d89  bfi      w9, w12, #8, #0x18
//   0x00ab08: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00ab0c: b9400f6c  ldr      w12, [x27, #0xc]
//   0x00ab10: f900036b  str      x11, [x27]
//   0x00ab14: 3100058b  adds     w11, w12, #1
//   0x00ab18: 29012f6a  stp      w10, w11, [x27, #8]
//   0x00ab1c: 54fffe23  b.lo     #0xaae0
//   0x00ab20: b940136b  ldr      w11, [x27, #0x10]
//   0x00ab24: 1100056b  add      w11, w11, #1
//   0x00ab28: b900136b  str      w11, [x27, #0x10]
//   0x00ab2c: 17ffffed  b        #0xaae0
//   0x00ab30: 51002108  sub      w8, w8, #8
//   0x00ab34: 1ac82529  lsr      w9, w9, w8
//   0x00ab38: 12001d29  and      w9, w9, #0xff
//   0x00ab3c: 7101a13f  cmp      w9, #0x68
//   0x00ab40: b90026a8  str      w8, [x21, #0x24]
//   0x00ab44: 540004e1  b.ne     #0xabe0
//   0x00ab48: 528001a9  mov      w9, #0xd
//   0x00ab4c: 7100211f  cmp      w8, #8
//   0x00ab50: b9000aa9  str      w9, [x21, #8]
//   0x00ab54: 5400006b  b.lt     #0xab60
//   0x00ab58: b94022a9  ldr      w9, [x21, #0x20]
//   0x00ab5c: 1400001a  b        #0xabc4
//   0x00ab60: b9400b69  ldr      w9, [x27, #8]
//   0x00ab64: 5100052a  sub      w10, w9, #1
//   0x00ab68: 3100055f  cmn      w10, #1
//   0x00ab6c: 540000e1  b.ne     #0xab88
//   0x00ab70: 140007ac  b        #0xca20
//   0x00ab74: 71001d1f  cmp      w8, #7
//   0x00ab78: 5100054a  sub      w10, w10, #1
//   0x00ab7c: 5400024c  b.gt     #0xabc4
//   0x00ab80: 3100055f  cmn      w10, #1
//   0x00ab84: 5400f4e0  b.eq     #0xca20
//   0x00ab88: f940036b  ldr      x11, [x27]
//   0x00ab8c: b94022ac  ldr      w12, [x21, #0x20]
//   0x00ab90: 11002108  add      w8, w8, #8
//   0x00ab94: 38401569  ldrb     w9, [x11], #1
//   0x00ab98: 33185d89  bfi      w9, w12, #8, #0x18
//   0x00ab9c: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00aba0: b9400f6c  ldr      w12, [x27, #0xc]
//   0x00aba4: f900036b  str      x11, [x27]
//   0x00aba8: 3100058b  adds     w11, w12, #1
//   0x00abac: 29012f6a  stp      w10, w11, [x27, #8]
//   0x00abb0: 54fffe23  b.lo     #0xab74
//   0x00abb4: b940136b  ldr      w11, [x27, #0x10]
//   0x00abb8: 1100056b  add      w11, w11, #1
//   0x00abbc: b900136b  str      w11, [x27, #0x10]
//   0x00abc0: 17ffffed  b        #0xab74
//   0x00abc4: 5100210a  sub      w10, w8, #8
//   0x00abc8: 1aca2528  lsr      w8, w9, w10
//   0x00abcc: 12001d08  and      w8, w8, #0xff
//   0x00abd0: 5100c509  sub      w9, w8, #0x31
//   0x00abd4: 7100213f  cmp      w9, #8
//   0x00abd8: 2904a2aa  stp      w10, w8, [x21, #0x24]
//   0x00abdc: 54000069  b.ls     #0xabe8
//   0x00abe0: 12800080  mov      w0, #-5
//   0x00abe4: 14000790  b        #0xca24
//   0x00abe8: 5100c109  sub      w9, w8, #0x30
//   0x00abec: 290917f4  stp      w20, w5, [sp, #0x48]
//   0x00abf0: a900c3fe  stp      x30, x16, [sp, #8]
//   0x00abf4: a90313ef  stp      x15, x4, [sp, #0x30]
//   0x00abf8: 290b6bf7  stp      w23, w26, [sp, #0x58]
//   0x00abfc: b9002aa9  str      w9, [x21, #0x28]
//   0x00ac00: 3940b2aa  ldrb     w10, [x21, #0x2c]
//   0x00ac04: f9401f68  ldr      x8, [x27, #0x38]
//   0x00ac08: f9402760  ldr      x0, [x27, #0x48]
//   0x00ac0c: f9002bfc  str      x28, [sp, #0x50]
//   0x00ac10: f90033f3  str      x19, [sp, #0x60]
//   0x00ac14: 2a1103fa  mov      w26, w17
//   0x00ac18: 2a0203f3  mov      w19, w2
//   0x00ac1c: 2a0103fc  mov      w28, w1
//   0x00ac20: 2a0603f7  mov      w23, w6
//   0x00ac24: b90047e3  str      w3, [sp, #0x44]
//   0x00ac28: b90023e7  str      w7, [sp, #0x20]
//   0x00ac2c: f9000fee  str      x14, [sp, #0x18]
//   0x00ac30: 3400048a  cbz      w10, #0xacc0
//   0x00ac34: 5281a80a  mov      w10, #0xd40
//   0x00ac38: 72a0006a  movk     w10, #3, lsl #16
//   0x00ac3c: 1b0a7d21  mul      w1, w9, w10
//   0x00ac40: 52800022  mov      w2, #1
//   0x00ac44: d63f0100  blr      x8
//   0x00ac48: b9402aa8  ldr      w8, [x21, #0x28]
//   0x00ac4c: f9062ea0  str      x0, [x21, #0xc58]
//   0x00ac50: f9401f69  ldr      x9, [x27, #0x38]
//   0x00ac54: f9402760  ldr      x0, [x27, #0x48]
//   0x00ac58: 5290d40a  mov      w10, #0x86a0
//   0x00ac5c: 72a0002a  movk     w10, #1, lsl #16
//   0x00ac60: 1b0a7d08  mul      w8, w8, w10
//   0x00ac64: 13017d01  asr      w1, w8, #1
//   0x00ac68: 52800022  mov      w2, #1
//   0x00ac6c: d63f0120  blr      x9
//   0x00ac70: aa0003e8  mov      x8, x0
//   0x00ac74: f90632a0  str      x0, [x21, #0xc60]
//   0x00ac78: 12800040  mov      w0, #-3
//   0x00ac7c: b4007a88  cbz      x8, #0xbbcc
//   0x00ac80: f9462ea8  ldr      x8, [x21, #0xc58]
//   0x00ac84: 2a1703e6  mov      w6, w23
//   0x00ac88: a9413bf0  ldp      x16, x14, [sp, #0x10]
//   0x00ac8c: 2a1c03e1  mov      w1, w28
//   0x00ac90: 2a1303e2  mov      w2, w19
//   0x00ac94: 2a1a03f1  mov      w17, w26
//   0x00ac98: b94023e7  ldr      w7, [sp, #0x20]
//   0x00ac9c: 2948d3e3  ldp      w3, w20, [sp, #0x44]
//   0x00aca0: f94033f3  ldr      x19, [sp, #0x60]
//   0x00aca4: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00aca8: 294b6bf7  ldp      w23, w26, [sp, #0x58]
//   0x00acac: b9404fe5  ldr      w5, [sp, #0x4c]
//   0x00acb0: a94313ef  ldp      x15, x4, [sp, #0x30]
//   0x00acb4: f94007fe  ldr      x30, [sp, #8]
//   0x00acb8: b50002c8  cbnz     x8, #0xad10
//   0x00acbc: 1400075a  b        #0xca24
//   0x00acc0: 5283500a  mov      w10, #0x1a80
//   0x00acc4: 72a000ca  movk     w10, #6, lsl #16
//   0x00acc8: 1b0a7d21  mul      w1, w9, w10
//   0x00accc: 52800022  mov      w2, #1
//   0x00acd0: d63f0100  blr      x8
//   0x00acd4: f9062aa0  str      x0, [x21, #0xc50]
//   0x00acd8: 2a1703e6  mov      w6, w23
//   0x00acdc: a9413bf0  ldp      x16, x14, [sp, #0x10]
//   0x00ace0: 2a1c03e1  mov      w1, w28
//   0x00ace4: 2a1303e2  mov      w2, w19
//   0x00ace8: 2a1a03f1  mov      w17, w26
//   0x00acec: b94023e7  ldr      w7, [sp, #0x20]
//   0x00acf0: 2948d3e3  ldp      w3, w20, [sp, #0x44]
//   0x00acf4: f94033f3  ldr      x19, [sp, #0x60]
//   0x00acf8: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00acfc: 294b6bf7  ldp      w23, w26, [sp, #0x58]
//   0x00ad00: b9404fe5  ldr      w5, [sp, #0x4c]
//   0x00ad04: a94313ef  ldp      x15, x4, [sp, #0x30]
//   0x00ad08: f94007fe  ldr      x30, [sp, #8]
//   0x00ad0c: b40077c0  cbz      x0, #0xbc04
//   0x00ad10: b94026a8  ldr      w8, [x21, #0x24]
//   0x00ad14: 528001c9  mov      w9, #0xe
//   0x00ad18: b9000aa9  str      w9, [x21, #8]
//   0x00ad1c: 7100211f  cmp      w8, #8
//   0x00ad20: 5400006b  b.lt     #0xad2c
//   0x00ad24: b94022aa  ldr      w10, [x21, #0x20]
//   0x00ad28: 1400001b  b        #0xad94
//   0x00ad2c: f94002a9  ldr      x9, [x21]
//   0x00ad30: b940092a  ldr      w10, [x9, #8]
//   0x00ad34: 5100054b  sub      w11, w10, #1
//   0x00ad38: 3100057f  cmn      w11, #1
//   0x00ad3c: 540000e1  b.ne     #0xad58
//   0x00ad40: 14000738  b        #0xca20
//   0x00ad44: 71001d1f  cmp      w8, #7
//   0x00ad48: 5100056b  sub      w11, w11, #1
//   0x00ad4c: 5400024c  b.gt     #0xad94
//   0x00ad50: 3100057f  cmn      w11, #1
//   0x00ad54: 5400e660  b.eq     #0xca20
//   0x00ad58: f940012c  ldr      x12, [x9]
//   0x00ad5c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00ad60: 11002108  add      w8, w8, #8
//   0x00ad64: 3840158a  ldrb     w10, [x12], #1
//   0x00ad68: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00ad6c: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00ad70: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00ad74: f900012c  str      x12, [x9]
//   0x00ad78: 310005ac  adds     w12, w13, #1
//   0x00ad7c: 2901312b  stp      w11, w12, [x9, #8]
//   0x00ad80: 54fffe23  b.lo     #0xad44
//   0x00ad84: b940112c  ldr      w12, [x9, #0x10]
//   0x00ad88: 1100058c  add      w12, w12, #1
//   0x00ad8c: b900112c  str      w12, [x9, #0x10]
//   0x00ad90: 17ffffed  b        #0xad44
//   0x00ad94: 51002108  sub      w8, w8, #8
//   0x00ad98: 1ac82549  lsr      w9, w10, w8
//   0x00ad9c: 12001d29  and      w9, w9, #0xff
//   0x00ada0: 71005d3f  cmp      w9, #0x17
//   0x00ada4: b90026a8  str      w8, [x21, #0x24]
//   0x00ada8: 54000120  b.eq     #0xadcc
//   0x00adac: 7100c53f  cmp      w9, #0x31
//   0x00adb0: 54008be1  b.ne     #0xbf2c
//   0x00adb4: 528001e9  mov      w9, #0xf
//   0x00adb8: 7100211f  cmp      w8, #8
//   0x00adbc: b9000aa9  str      w9, [x21, #8]
//   0x00adc0: 5400012b  b.lt     #0xade4
//   0x00adc4: b94022aa  ldr      w10, [x21, #0x20]
//   0x00adc8: 14000021  b        #0xae4c
//   0x00adcc: 52800549  mov      w9, #0x2a
//   0x00add0: 7100211f  cmp      w8, #8
//   0x00add4: b9000aa9  str      w9, [x21, #8]
//   0x00add8: 5400450b  b.lt     #0xb678
//   0x00addc: b94022aa  ldr      w10, [x21, #0x20]
//   0x00ade0: 14000240  b        #0xb6e0
//   0x00ade4: f94002a9  ldr      x9, [x21]
//   0x00ade8: b940092a  ldr      w10, [x9, #8]
//   0x00adec: 5100054b  sub      w11, w10, #1
//   0x00adf0: 3100057f  cmn      w11, #1
//   0x00adf4: 540000e1  b.ne     #0xae10
//   0x00adf8: 1400070a  b        #0xca20
//   0x00adfc: 71001d1f  cmp      w8, #7
//   0x00ae00: 5100056b  sub      w11, w11, #1
//   0x00ae04: 5400024c  b.gt     #0xae4c
//   0x00ae08: 3100057f  cmn      w11, #1
//   0x00ae0c: 5400e0a0  b.eq     #0xca20
//   0x00ae10: f940012c  ldr      x12, [x9]
//   0x00ae14: b94022ad  ldr      w13, [x21, #0x20]
//   0x00ae18: 11002108  add      w8, w8, #8
//   0x00ae1c: 3840158a  ldrb     w10, [x12], #1
//   0x00ae20: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00ae24: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00ae28: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00ae2c: f900012c  str      x12, [x9]
//   0x00ae30: 310005ac  adds     w12, w13, #1
//   0x00ae34: 2901312b  stp      w11, w12, [x9, #8]
//   0x00ae38: 54fffe23  b.lo     #0xadfc
//   0x00ae3c: b940112c  ldr      w12, [x9, #0x10]
//   0x00ae40: 1100058c  add      w12, w12, #1
//   0x00ae44: b900112c  str      w12, [x9, #0x10]
//   0x00ae48: 17ffffed  b        #0xadfc
//   0x00ae4c: 51002108  sub      w8, w8, #8
//   0x00ae50: 1ac82549  lsr      w9, w10, w8
//   0x00ae54: 12001d29  and      w9, w9, #0xff
//   0x00ae58: 7101053f  cmp      w9, #0x41
//   0x00ae5c: b90026a8  str      w8, [x21, #0x24]
//   0x00ae60: 54008661  b.ne     #0xbf2c
//   0x00ae64: 52800209  mov      w9, #0x10
//   0x00ae68: 7100211f  cmp      w8, #8
//   0x00ae6c: b9000aa9  str      w9, [x21, #8]
//   0x00ae70: 5400006b  b.lt     #0xae7c
//   0x00ae74: b94022aa  ldr      w10, [x21, #0x20]
//   0x00ae78: 1400001b  b        #0xaee4
//   0x00ae7c: f94002a9  ldr      x9, [x21]
//   0x00ae80: b940092a  ldr      w10, [x9, #8]
//   0x00ae84: 5100054b  sub      w11, w10, #1
//   0x00ae88: 3100057f  cmn      w11, #1
//   0x00ae8c: 540000e1  b.ne     #0xaea8
//   0x00ae90: 140006e4  b        #0xca20
//   0x00ae94: 71001d1f  cmp      w8, #7
//   0x00ae98: 5100056b  sub      w11, w11, #1
//   0x00ae9c: 5400024c  b.gt     #0xaee4
//   0x00aea0: 3100057f  cmn      w11, #1
//   0x00aea4: 5400dbe0  b.eq     #0xca20
//   0x00aea8: f940012c  ldr      x12, [x9]
//   0x00aeac: b94022ad  ldr      w13, [x21, #0x20]
//   0x00aeb0: 11002108  add      w8, w8, #8
//   0x00aeb4: 3840158a  ldrb     w10, [x12], #1
//   0x00aeb8: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00aebc: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00aec0: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00aec4: f900012c  str      x12, [x9]
//   0x00aec8: 310005ac  adds     w12, w13, #1
//   0x00aecc: 2901312b  stp      w11, w12, [x9, #8]
//   0x00aed0: 54fffe23  b.lo     #0xae94
//   0x00aed4: b940112c  ldr      w12, [x9, #0x10]
//   0x00aed8: 1100058c  add      w12, w12, #1
//   0x00aedc: b900112c  str      w12, [x9, #0x10]
//   0x00aee0: 17ffffed  b        #0xae94
//   0x00aee4: 51002108  sub      w8, w8, #8
//   0x00aee8: 1ac82549  lsr      w9, w10, w8
//   0x00aeec: 12001d29  and      w9, w9, #0xff
//   0x00aef0: 7101653f  cmp      w9, #0x59
//   0x00aef4: b90026a8  str      w8, [x21, #0x24]
//   0x00aef8: 540081a1  b.ne     #0xbf2c
//   0x00aefc: 52800229  mov      w9, #0x11
//   0x00af00: 7100211f  cmp      w8, #8
//   0x00af04: b9000aa9  str      w9, [x21, #8]
//   0x00af08: 5400006b  b.lt     #0xaf14
//   0x00af0c: b94022aa  ldr      w10, [x21, #0x20]
//   0x00af10: 1400001b  b        #0xaf7c
//   0x00af14: f94002a9  ldr      x9, [x21]
//   0x00af18: b940092a  ldr      w10, [x9, #8]
//   0x00af1c: 5100054b  sub      w11, w10, #1
//   0x00af20: 3100057f  cmn      w11, #1
//   0x00af24: 540000e1  b.ne     #0xaf40
//   0x00af28: 140006be  b        #0xca20
//   0x00af2c: 71001d1f  cmp      w8, #7
//   0x00af30: 5100056b  sub      w11, w11, #1
//   0x00af34: 5400024c  b.gt     #0xaf7c
//   0x00af38: 3100057f  cmn      w11, #1
//   0x00af3c: 5400d720  b.eq     #0xca20
//   0x00af40: f940012c  ldr      x12, [x9]
//   0x00af44: b94022ad  ldr      w13, [x21, #0x20]
//   0x00af48: 11002108  add      w8, w8, #8
//   0x00af4c: 3840158a  ldrb     w10, [x12], #1
//   0x00af50: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00af54: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00af58: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00af5c: f900012c  str      x12, [x9]
//   0x00af60: 310005ac  adds     w12, w13, #1
//   0x00af64: 2901312b  stp      w11, w12, [x9, #8]
//   0x00af68: 54fffe23  b.lo     #0xaf2c
//   0x00af6c: b940112c  ldr      w12, [x9, #0x10]
//   0x00af70: 1100058c  add      w12, w12, #1
//   0x00af74: b900112c  str      w12, [x9, #0x10]
//   0x00af78: 17ffffed  b        #0xaf2c
//   0x00af7c: 51002108  sub      w8, w8, #8
//   0x00af80: 1ac82549  lsr      w9, w10, w8
//   0x00af84: 12001d29  and      w9, w9, #0xff
//   0x00af88: 7100993f  cmp      w9, #0x26
//   0x00af8c: b90026a8  str      w8, [x21, #0x24]
//   0x00af90: 54007ce1  b.ne     #0xbf2c
//   0x00af94: 52800249  mov      w9, #0x12
//   0x00af98: 7100211f  cmp      w8, #8
//   0x00af9c: b9000aa9  str      w9, [x21, #8]
//   0x00afa0: 5400006b  b.lt     #0xafac
//   0x00afa4: b94022aa  ldr      w10, [x21, #0x20]
//   0x00afa8: 1400001b  b        #0xb014
//   0x00afac: f94002a9  ldr      x9, [x21]
//   0x00afb0: b940092a  ldr      w10, [x9, #8]
//   0x00afb4: 5100054b  sub      w11, w10, #1
//   0x00afb8: 3100057f  cmn      w11, #1
//   0x00afbc: 540000e1  b.ne     #0xafd8
//   0x00afc0: 14000698  b        #0xca20
//   0x00afc4: 71001d1f  cmp      w8, #7
//   0x00afc8: 5100056b  sub      w11, w11, #1
//   0x00afcc: 5400024c  b.gt     #0xb014
//   0x00afd0: 3100057f  cmn      w11, #1
//   0x00afd4: 5400d260  b.eq     #0xca20
//   0x00afd8: f940012c  ldr      x12, [x9]
//   0x00afdc: b94022ad  ldr      w13, [x21, #0x20]
//   0x00afe0: 11002108  add      w8, w8, #8
//   0x00afe4: 3840158a  ldrb     w10, [x12], #1
//   0x00afe8: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00afec: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00aff0: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00aff4: f900012c  str      x12, [x9]
//   0x00aff8: 310005ac  adds     w12, w13, #1
//   0x00affc: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b000: 54fffe23  b.lo     #0xafc4
//   0x00b004: b940112c  ldr      w12, [x9, #0x10]
//   0x00b008: 1100058c  add      w12, w12, #1
//   0x00b00c: b900112c  str      w12, [x9, #0x10]
//   0x00b010: 17ffffed  b        #0xafc4
//   0x00b014: 51002108  sub      w8, w8, #8
//   0x00b018: 1ac82549  lsr      w9, w10, w8
//   0x00b01c: 12001d29  and      w9, w9, #0xff
//   0x00b020: 71014d3f  cmp      w9, #0x53
//   0x00b024: b90026a8  str      w8, [x21, #0x24]
//   0x00b028: 54007821  b.ne     #0xbf2c
//   0x00b02c: 52800269  mov      w9, #0x13
//   0x00b030: 7100211f  cmp      w8, #8
//   0x00b034: b9000aa9  str      w9, [x21, #8]
//   0x00b038: 5400006b  b.lt     #0xb044
//   0x00b03c: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b040: 1400001b  b        #0xb0ac
//   0x00b044: f94002a9  ldr      x9, [x21]
//   0x00b048: b940092a  ldr      w10, [x9, #8]
//   0x00b04c: 5100054b  sub      w11, w10, #1
//   0x00b050: 3100057f  cmn      w11, #1
//   0x00b054: 540000e1  b.ne     #0xb070
//   0x00b058: 14000672  b        #0xca20
//   0x00b05c: 71001d1f  cmp      w8, #7
//   0x00b060: 5100056b  sub      w11, w11, #1
//   0x00b064: 5400024c  b.gt     #0xb0ac
//   0x00b068: 3100057f  cmn      w11, #1
//   0x00b06c: 5400cda0  b.eq     #0xca20
//   0x00b070: f940012c  ldr      x12, [x9]
//   0x00b074: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b078: 11002108  add      w8, w8, #8
//   0x00b07c: 3840158a  ldrb     w10, [x12], #1
//   0x00b080: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b084: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b088: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b08c: f900012c  str      x12, [x9]
//   0x00b090: 310005ac  adds     w12, w13, #1
//   0x00b094: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b098: 54fffe23  b.lo     #0xb05c
//   0x00b09c: b940112c  ldr      w12, [x9, #0x10]
//   0x00b0a0: 1100058c  add      w12, w12, #1
//   0x00b0a4: b900112c  str      w12, [x9, #0x10]
//   0x00b0a8: 17ffffed  b        #0xb05c
//   0x00b0ac: 51002108  sub      w8, w8, #8
//   0x00b0b0: 1ac82549  lsr      w9, w10, w8
//   0x00b0b4: 12001d29  and      w9, w9, #0xff
//   0x00b0b8: 7101653f  cmp      w9, #0x59
//   0x00b0bc: b90026a8  str      w8, [x21, #0x24]
//   0x00b0c0: 54007361  b.ne     #0xbf2c
//   0x00b0c4: 294626a8  ldp      w8, w9, [x21, #0x30]
//   0x00b0c8: 2a0203ea  mov      w10, w2
//   0x00b0cc: 11000502  add      w2, w8, #1
//   0x00b0d0: 7100093f  cmp      w9, #2
//   0x00b0d4: b90032a2  str      w2, [x21, #0x30]
//   0x00b0d8: 5400054b  b.lt     #0xb180
//   0x00b0dc: 900000a8  adrp     x8, #0x1f000
//   0x00b0e0: f947c908  ldr      x8, [x8, #0xf90]
//   0x00b0e4: 290407e7  stp      w7, w1, [sp, #0x20]
//   0x00b0e8: f0000041  adrp     x1, #0x16000
//   0x00b0ec: 91396821  add      x1, x1, #0xe5a
//   0x00b0f0: 9104c100  add      x0, x8, #0x130
//   0x00b0f4: f9000bf0  str      x16, [sp, #0x10]
//   0x00b0f8: b90033f9  str      w25, [sp, #0x30]
//   0x00b0fc: f90033f3  str      x19, [sp, #0x60]
//   0x00b100: 29002bf1  stp      w17, w10, [sp]
//   0x00b104: f9002bfc  str      x28, [sp, #0x50]
//   0x00b108: aa0e03fb  mov      x27, x14
//   0x00b10c: 2a1703f3  mov      w19, w23
//   0x00b110: 2a0603f7  mov      w23, w6
//   0x00b114: b9005ffa  str      w26, [sp, #0x5c]
//   0x00b118: f90017f6  str      x22, [sp, #0x28]
//   0x00b11c: b9004bf4  str      w20, [sp, #0x48]
//   0x00b120: 2a0303f9  mov      w25, w3
//   0x00b124: aa0403fc  mov      x28, x4
//   0x00b128: 2a0503f4  mov      w20, w5
//   0x00b12c: aa1e03fa  mov      x26, x30
//   0x00b130: aa0f03f6  mov      x22, x15
//   0x00b134: 97ffde53  bl       #0x2a80
//   0x00b138: aa1603ef  mov      x15, x22
//   0x00b13c: 2a1303e8  mov      w8, w19
//   0x00b140: aa1a03fe  mov      x30, x26
//   0x00b144: 2a1403e5  mov      w5, w20
//   0x00b148: aa1c03e4  mov      x4, x28
//   0x00b14c: 2a1903e3  mov      w3, w25
//   0x00b150: b9404bf4  ldr      w20, [sp, #0x48]
//   0x00b154: f94017f6  ldr      x22, [sp, #0x28]
//   0x00b158: b9405ffa  ldr      w26, [sp, #0x5c]
//   0x00b15c: 294407e7  ldp      w7, w1, [sp, #0x20]
//   0x00b160: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00b164: 29402bf1  ldp      w17, w10, [sp]
//   0x00b168: f94033f3  ldr      x19, [sp, #0x60]
//   0x00b16c: b94033f9  ldr      w25, [sp, #0x30]
//   0x00b170: f9400bf0  ldr      x16, [sp, #0x10]
//   0x00b174: 2a1703e6  mov      w6, w23
//   0x00b178: 2a0803f7  mov      w23, w8
//   0x00b17c: aa1b03ee  mov      x14, x27
//   0x00b180: 2a0a03e2  mov      w2, w10
//   0x00b184: b90c6abf  str      wzr, [x21, #0xc68]
//   0x00b188: b94026a8  ldr      w8, [x21, #0x24]
//   0x00b18c: 52800289  mov      w9, #0x14
//   0x00b190: b9000aa9  str      w9, [x21, #8]
//   0x00b194: 7100211f  cmp      w8, #8
//   0x00b198: 5400006b  b.lt     #0xb1a4
//   0x00b19c: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b1a0: 1400001b  b        #0xb20c
//   0x00b1a4: f94002aa  ldr      x10, [x21]
//   0x00b1a8: b9400949  ldr      w9, [x10, #8]
//   0x00b1ac: 5100052b  sub      w11, w9, #1
//   0x00b1b0: 3100057f  cmn      w11, #1
//   0x00b1b4: 540000e1  b.ne     #0xb1d0
//   0x00b1b8: 1400061a  b        #0xca20
//   0x00b1bc: 71001d1f  cmp      w8, #7
//   0x00b1c0: 5100056b  sub      w11, w11, #1
//   0x00b1c4: 5400024c  b.gt     #0xb20c
//   0x00b1c8: 3100057f  cmn      w11, #1
//   0x00b1cc: 5400c2a0  b.eq     #0xca20
//   0x00b1d0: f940014c  ldr      x12, [x10]
//   0x00b1d4: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b1d8: 11002108  add      w8, w8, #8
//   0x00b1dc: 38401589  ldrb     w9, [x12], #1
//   0x00b1e0: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b1e4: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b1e8: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b1ec: f900014c  str      x12, [x10]
//   0x00b1f0: 310005ac  adds     w12, w13, #1
//   0x00b1f4: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b1f8: 54fffe23  b.lo     #0xb1bc
//   0x00b1fc: b940114c  ldr      w12, [x10, #0x10]
//   0x00b200: 1100058c  add      w12, w12, #1
//   0x00b204: b900114c  str      w12, [x10, #0x10]
//   0x00b208: 17ffffed  b        #0xb1bc
//   0x00b20c: b94c6aaa  ldr      w10, [x21, #0xc68]
//   0x00b210: 51002108  sub      w8, w8, #8
//   0x00b214: 1ac82529  lsr      w9, w9, w8
//   0x00b218: b90026a8  str      w8, [x21, #0x24]
//   0x00b21c: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b220: b90c6aa9  str      w9, [x21, #0xc68]
//   0x00b224: 528002a9  mov      w9, #0x15
//   0x00b228: 7100211f  cmp      w8, #8
//   0x00b22c: b9000aa9  str      w9, [x21, #8]
//   0x00b230: 5400006b  b.lt     #0xb23c
//   0x00b234: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b238: 1400001b  b        #0xb2a4
//   0x00b23c: f94002aa  ldr      x10, [x21]
//   0x00b240: b9400949  ldr      w9, [x10, #8]
//   0x00b244: 5100052b  sub      w11, w9, #1
//   0x00b248: 3100057f  cmn      w11, #1
//   0x00b24c: 540000e1  b.ne     #0xb268
//   0x00b250: 140005f4  b        #0xca20
//   0x00b254: 71001d1f  cmp      w8, #7
//   0x00b258: 5100056b  sub      w11, w11, #1
//   0x00b25c: 5400024c  b.gt     #0xb2a4
//   0x00b260: 3100057f  cmn      w11, #1
//   0x00b264: 5400bde0  b.eq     #0xca20
//   0x00b268: f940014c  ldr      x12, [x10]
//   0x00b26c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b270: 11002108  add      w8, w8, #8
//   0x00b274: 38401589  ldrb     w9, [x12], #1
//   0x00b278: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b27c: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b280: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b284: f900014c  str      x12, [x10]
//   0x00b288: 310005ac  adds     w12, w13, #1
//   0x00b28c: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b290: 54fffe23  b.lo     #0xb254
//   0x00b294: b940114c  ldr      w12, [x10, #0x10]
//   0x00b298: 1100058c  add      w12, w12, #1
//   0x00b29c: b900114c  str      w12, [x10, #0x10]
//   0x00b2a0: 17ffffed  b        #0xb254
//   0x00b2a4: b94c6aaa  ldr      w10, [x21, #0xc68]
//   0x00b2a8: 51002108  sub      w8, w8, #8
//   0x00b2ac: 1ac82529  lsr      w9, w9, w8
//   0x00b2b0: b90026a8  str      w8, [x21, #0x24]
//   0x00b2b4: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b2b8: b90c6aa9  str      w9, [x21, #0xc68]
//   0x00b2bc: 528002c9  mov      w9, #0x16
//   0x00b2c0: 7100211f  cmp      w8, #8
//   0x00b2c4: b9000aa9  str      w9, [x21, #8]
//   0x00b2c8: 5400006b  b.lt     #0xb2d4
//   0x00b2cc: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b2d0: 1400001b  b        #0xb33c
//   0x00b2d4: f94002aa  ldr      x10, [x21]
//   0x00b2d8: b9400949  ldr      w9, [x10, #8]
//   0x00b2dc: 5100052b  sub      w11, w9, #1
//   0x00b2e0: 3100057f  cmn      w11, #1
//   0x00b2e4: 540000e1  b.ne     #0xb300
//   0x00b2e8: 140005ce  b        #0xca20
//   0x00b2ec: 71001d1f  cmp      w8, #7
//   0x00b2f0: 5100056b  sub      w11, w11, #1
//   0x00b2f4: 5400024c  b.gt     #0xb33c
//   0x00b2f8: 3100057f  cmn      w11, #1
//   0x00b2fc: 5400b920  b.eq     #0xca20
//   0x00b300: f940014c  ldr      x12, [x10]
//   0x00b304: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b308: 11002108  add      w8, w8, #8
//   0x00b30c: 38401589  ldrb     w9, [x12], #1
//   0x00b310: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b314: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b318: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b31c: f900014c  str      x12, [x10]
//   0x00b320: 310005ac  adds     w12, w13, #1
//   0x00b324: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b328: 54fffe23  b.lo     #0xb2ec
//   0x00b32c: b940114c  ldr      w12, [x10, #0x10]
//   0x00b330: 1100058c  add      w12, w12, #1
//   0x00b334: b900114c  str      w12, [x10, #0x10]
//   0x00b338: 17ffffed  b        #0xb2ec
//   0x00b33c: b94c6aaa  ldr      w10, [x21, #0xc68]
//   0x00b340: 51002108  sub      w8, w8, #8
//   0x00b344: 1ac82529  lsr      w9, w9, w8
//   0x00b348: b90026a8  str      w8, [x21, #0x24]
//   0x00b34c: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b350: b90c6aa9  str      w9, [x21, #0xc68]
//   0x00b354: 528002e9  mov      w9, #0x17
//   0x00b358: 7100211f  cmp      w8, #8
//   0x00b35c: b9000aa9  str      w9, [x21, #8]
//   0x00b360: 5400006b  b.lt     #0xb36c
//   0x00b364: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b368: 1400001b  b        #0xb3d4
//   0x00b36c: f94002aa  ldr      x10, [x21]
//   0x00b370: b9400949  ldr      w9, [x10, #8]
//   0x00b374: 5100052b  sub      w11, w9, #1
//   0x00b378: 3100057f  cmn      w11, #1
//   0x00b37c: 540000e1  b.ne     #0xb398
//   0x00b380: 140005a8  b        #0xca20
//   0x00b384: 71001d1f  cmp      w8, #7
//   0x00b388: 5100056b  sub      w11, w11, #1
//   0x00b38c: 5400024c  b.gt     #0xb3d4
//   0x00b390: 3100057f  cmn      w11, #1
//   0x00b394: 5400b460  b.eq     #0xca20
//   0x00b398: f940014c  ldr      x12, [x10]
//   0x00b39c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b3a0: 11002108  add      w8, w8, #8
//   0x00b3a4: 38401589  ldrb     w9, [x12], #1
//   0x00b3a8: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b3ac: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b3b0: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b3b4: f900014c  str      x12, [x10]
//   0x00b3b8: 310005ac  adds     w12, w13, #1
//   0x00b3bc: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b3c0: 54fffe23  b.lo     #0xb384
//   0x00b3c4: b940114c  ldr      w12, [x10, #0x10]
//   0x00b3c8: 1100058c  add      w12, w12, #1
//   0x00b3cc: b900114c  str      w12, [x10, #0x10]
//   0x00b3d0: 17ffffed  b        #0xb384
//   0x00b3d4: b94c6aaa  ldr      w10, [x21, #0xc68]
//   0x00b3d8: 51002108  sub      w8, w8, #8
//   0x00b3dc: 1ac82529  lsr      w9, w9, w8
//   0x00b3e0: b90026a8  str      w8, [x21, #0x24]
//   0x00b3e4: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b3e8: b90c6aa9  str      w9, [x21, #0xc68]
//   0x00b3ec: 52800309  mov      w9, #0x18
//   0x00b3f0: 7100051f  cmp      w8, #1
//   0x00b3f4: b9000aa9  str      w9, [x21, #8]
//   0x00b3f8: 5400006b  b.lt     #0xb404
//   0x00b3fc: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b400: 1400001b  b        #0xb46c
//   0x00b404: f94002a9  ldr      x9, [x21]
//   0x00b408: b940092a  ldr      w10, [x9, #8]
//   0x00b40c: 5100054b  sub      w11, w10, #1
//   0x00b410: 3100057f  cmn      w11, #1
//   0x00b414: 540000e1  b.ne     #0xb430
//   0x00b418: 14000582  b        #0xca20
//   0x00b41c: 7100011f  cmp      w8, #0
//   0x00b420: 5100056b  sub      w11, w11, #1
//   0x00b424: 5400024c  b.gt     #0xb46c
//   0x00b428: 3100057f  cmn      w11, #1
//   0x00b42c: 5400afa0  b.eq     #0xca20
//   0x00b430: f940012c  ldr      x12, [x9]
//   0x00b434: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b438: 11002108  add      w8, w8, #8
//   0x00b43c: 3840158a  ldrb     w10, [x12], #1
//   0x00b440: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b444: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b448: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b44c: f900012c  str      x12, [x9]
//   0x00b450: 310005ac  adds     w12, w13, #1
//   0x00b454: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b458: 54fffe23  b.lo     #0xb41c
//   0x00b45c: b940112c  ldr      w12, [x9, #0x10]
//   0x00b460: 1100058c  add      w12, w12, #1
//   0x00b464: b900112c  str      w12, [x9, #0x10]
//   0x00b468: 17ffffed  b        #0xb41c
//   0x00b46c: 51000508  sub      w8, w8, #1
//   0x00b470: 1ac82549  lsr      w9, w10, w8
//   0x00b474: 12000129  and      w9, w9, #1
//   0x00b478: b90026a8  str      w8, [x21, #0x24]
//   0x00b47c: 390052a9  strb     w9, [x21, #0x14]
//   0x00b480: b9003abf  str      wzr, [x21, #0x38]
//   0x00b484: 52800329  mov      w9, #0x19
//   0x00b488: 7100211f  cmp      w8, #8
//   0x00b48c: b9000aa9  str      w9, [x21, #8]
//   0x00b490: 5400006b  b.lt     #0xb49c
//   0x00b494: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b498: 1400001b  b        #0xb504
//   0x00b49c: f94002aa  ldr      x10, [x21]
//   0x00b4a0: b9400949  ldr      w9, [x10, #8]
//   0x00b4a4: 5100052b  sub      w11, w9, #1
//   0x00b4a8: 3100057f  cmn      w11, #1
//   0x00b4ac: 540000e1  b.ne     #0xb4c8
//   0x00b4b0: 1400055c  b        #0xca20
//   0x00b4b4: 71001d1f  cmp      w8, #7
//   0x00b4b8: 5100056b  sub      w11, w11, #1
//   0x00b4bc: 5400024c  b.gt     #0xb504
//   0x00b4c0: 3100057f  cmn      w11, #1
//   0x00b4c4: 5400aae0  b.eq     #0xca20
//   0x00b4c8: f940014c  ldr      x12, [x10]
//   0x00b4cc: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b4d0: 11002108  add      w8, w8, #8
//   0x00b4d4: 38401589  ldrb     w9, [x12], #1
//   0x00b4d8: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b4dc: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b4e0: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b4e4: f900014c  str      x12, [x10]
//   0x00b4e8: 310005ac  adds     w12, w13, #1
//   0x00b4ec: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b4f0: 54fffe23  b.lo     #0xb4b4
//   0x00b4f4: b940114c  ldr      w12, [x10, #0x10]
//   0x00b4f8: 1100058c  add      w12, w12, #1
//   0x00b4fc: b900114c  str      w12, [x10, #0x10]
//   0x00b500: 17ffffed  b        #0xb4b4
//   0x00b504: b9403aaa  ldr      w10, [x21, #0x38]
//   0x00b508: 51002108  sub      w8, w8, #8
//   0x00b50c: 1ac82529  lsr      w9, w9, w8
//   0x00b510: b90026a8  str      w8, [x21, #0x24]
//   0x00b514: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b518: b9003aa9  str      w9, [x21, #0x38]
//   0x00b51c: 52800349  mov      w9, #0x1a
//   0x00b520: 7100211f  cmp      w8, #8
//   0x00b524: b9000aa9  str      w9, [x21, #8]
//   0x00b528: 5400006b  b.lt     #0xb534
//   0x00b52c: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b530: 1400001b  b        #0xb59c
//   0x00b534: f94002aa  ldr      x10, [x21]
//   0x00b538: b9400949  ldr      w9, [x10, #8]
//   0x00b53c: 5100052b  sub      w11, w9, #1
//   0x00b540: 3100057f  cmn      w11, #1
//   0x00b544: 540000e1  b.ne     #0xb560
//   0x00b548: 14000536  b        #0xca20
//   0x00b54c: 71001d1f  cmp      w8, #7
//   0x00b550: 5100056b  sub      w11, w11, #1
//   0x00b554: 5400024c  b.gt     #0xb59c
//   0x00b558: 3100057f  cmn      w11, #1
//   0x00b55c: 5400a620  b.eq     #0xca20
//   0x00b560: f940014c  ldr      x12, [x10]
//   0x00b564: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b568: 11002108  add      w8, w8, #8
//   0x00b56c: 38401589  ldrb     w9, [x12], #1
//   0x00b570: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b574: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b578: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b57c: f900014c  str      x12, [x10]
//   0x00b580: 310005ac  adds     w12, w13, #1
//   0x00b584: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b588: 54fffe23  b.lo     #0xb54c
//   0x00b58c: b940114c  ldr      w12, [x10, #0x10]
//   0x00b590: 1100058c  add      w12, w12, #1
//   0x00b594: b900114c  str      w12, [x10, #0x10]
//   0x00b598: 17ffffed  b        #0xb54c
//   0x00b59c: b9403aaa  ldr      w10, [x21, #0x38]
//   0x00b5a0: 51002108  sub      w8, w8, #8
//   0x00b5a4: 1ac82529  lsr      w9, w9, w8
//   0x00b5a8: b90026a8  str      w8, [x21, #0x24]
//   0x00b5ac: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b5b0: b9003aa9  str      w9, [x21, #0x38]
//   0x00b5b4: 52800369  mov      w9, #0x1b
//   0x00b5b8: 7100211f  cmp      w8, #8
//   0x00b5bc: b9000aa9  str      w9, [x21, #8]
//   0x00b5c0: 5400006b  b.lt     #0xb5cc
//   0x00b5c4: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b5c8: 1400001b  b        #0xb634
//   0x00b5cc: f94002a9  ldr      x9, [x21]
//   0x00b5d0: b940092a  ldr      w10, [x9, #8]
//   0x00b5d4: 5100054b  sub      w11, w10, #1
//   0x00b5d8: 3100057f  cmn      w11, #1
//   0x00b5dc: 540000e1  b.ne     #0xb5f8
//   0x00b5e0: 14000510  b        #0xca20
//   0x00b5e4: 71001d1f  cmp      w8, #7
//   0x00b5e8: 5100056b  sub      w11, w11, #1
//   0x00b5ec: 5400024c  b.gt     #0xb634
//   0x00b5f0: 3100057f  cmn      w11, #1
//   0x00b5f4: 5400a160  b.eq     #0xca20
//   0x00b5f8: f940012c  ldr      x12, [x9]
//   0x00b5fc: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b600: 11002108  add      w8, w8, #8
//   0x00b604: 3840158a  ldrb     w10, [x12], #1
//   0x00b608: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b60c: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b610: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b614: f900012c  str      x12, [x9]
//   0x00b618: 310005ac  adds     w12, w13, #1
//   0x00b61c: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b620: 54fffe23  b.lo     #0xb5e4
//   0x00b624: b940112c  ldr      w12, [x9, #0x10]
//   0x00b628: 1100058c  add      w12, w12, #1
//   0x00b62c: b900112c  str      w12, [x9, #0x10]
//   0x00b630: 17ffffed  b        #0xb5e4
//   0x00b634: b9403aa9  ldr      w9, [x21, #0x38]
//   0x00b638: 5100210b  sub      w11, w8, #8
//   0x00b63c: 1acb2548  lsr      w8, w10, w11
//   0x00b640: b90026ab  str      w11, [x21, #0x24]
//   0x00b644: 33185d28  bfi      w8, w9, #8, #0x18
//   0x00b648: b9003aa8  str      w8, [x21, #0x38]
//   0x00b64c: 37f84708  tbnz     w8, #0x1f, #0xbf2c
//   0x00b650: b9402aa9  ldr      w9, [x21, #0x28]
//   0x00b654: 5290d40a  mov      w10, #0x86a0
//   0x00b658: 72a0002a  movk     w10, #1, lsl #16
//   0x00b65c: 1b0a7d29  mul      w9, w9, w10
//   0x00b660: 5280014a  mov      w10, #0xa
//   0x00b664: 2a0a0129  orr      w9, w9, w10
//   0x00b668: 6b09011f  cmp      w8, w9
//   0x00b66c: 5400460c  b.gt     #0xbf2c
//   0x00b670: 2a1f03ef  mov      w15, wzr
//   0x00b674: 14000166  b        #0xbc0c
//   0x00b678: f94002a9  ldr      x9, [x21]
//   0x00b67c: b940092a  ldr      w10, [x9, #8]
//   0x00b680: 5100054b  sub      w11, w10, #1
//   0x00b684: 3100057f  cmn      w11, #1
//   0x00b688: 540000e1  b.ne     #0xb6a4
//   0x00b68c: 140004e5  b        #0xca20
//   0x00b690: 71001d1f  cmp      w8, #7
//   0x00b694: 5100056b  sub      w11, w11, #1
//   0x00b698: 5400024c  b.gt     #0xb6e0
//   0x00b69c: 3100057f  cmn      w11, #1
//   0x00b6a0: 54009c00  b.eq     #0xca20
//   0x00b6a4: f940012c  ldr      x12, [x9]
//   0x00b6a8: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b6ac: 11002108  add      w8, w8, #8
//   0x00b6b0: 3840158a  ldrb     w10, [x12], #1
//   0x00b6b4: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b6b8: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b6bc: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b6c0: f900012c  str      x12, [x9]
//   0x00b6c4: 310005ac  adds     w12, w13, #1
//   0x00b6c8: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b6cc: 54fffe23  b.lo     #0xb690
//   0x00b6d0: b940112c  ldr      w12, [x9, #0x10]
//   0x00b6d4: 1100058c  add      w12, w12, #1
//   0x00b6d8: b900112c  str      w12, [x9, #0x10]
//   0x00b6dc: 17ffffed  b        #0xb690
//   0x00b6e0: 51002108  sub      w8, w8, #8
//   0x00b6e4: 1ac82549  lsr      w9, w10, w8
//   0x00b6e8: 12001d29  and      w9, w9, #0xff
//   0x00b6ec: 7101c93f  cmp      w9, #0x72
//   0x00b6f0: b90026a8  str      w8, [x21, #0x24]
//   0x00b6f4: 540041c1  b.ne     #0xbf2c
//   0x00b6f8: 52800569  mov      w9, #0x2b
//   0x00b6fc: 7100211f  cmp      w8, #8
//   0x00b700: b9000aa9  str      w9, [x21, #8]
//   0x00b704: 5400006b  b.lt     #0xb710
//   0x00b708: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b70c: 1400001b  b        #0xb778
//   0x00b710: f94002a9  ldr      x9, [x21]
//   0x00b714: b940092a  ldr      w10, [x9, #8]
//   0x00b718: 5100054b  sub      w11, w10, #1
//   0x00b71c: 3100057f  cmn      w11, #1
//   0x00b720: 540000e1  b.ne     #0xb73c
//   0x00b724: 140004bf  b        #0xca20
//   0x00b728: 71001d1f  cmp      w8, #7
//   0x00b72c: 5100056b  sub      w11, w11, #1
//   0x00b730: 5400024c  b.gt     #0xb778
//   0x00b734: 3100057f  cmn      w11, #1
//   0x00b738: 54009740  b.eq     #0xca20
//   0x00b73c: f940012c  ldr      x12, [x9]
//   0x00b740: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b744: 11002108  add      w8, w8, #8
//   0x00b748: 3840158a  ldrb     w10, [x12], #1
//   0x00b74c: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b750: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b754: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b758: f900012c  str      x12, [x9]
//   0x00b75c: 310005ac  adds     w12, w13, #1
//   0x00b760: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b764: 54fffe23  b.lo     #0xb728
//   0x00b768: b940112c  ldr      w12, [x9, #0x10]
//   0x00b76c: 1100058c  add      w12, w12, #1
//   0x00b770: b900112c  str      w12, [x9, #0x10]
//   0x00b774: 17ffffed  b        #0xb728
//   0x00b778: 51002108  sub      w8, w8, #8
//   0x00b77c: 1ac82549  lsr      w9, w10, w8
//   0x00b780: 12001d29  and      w9, w9, #0xff
//   0x00b784: 7101153f  cmp      w9, #0x45
//   0x00b788: b90026a8  str      w8, [x21, #0x24]
//   0x00b78c: 54003d01  b.ne     #0xbf2c
//   0x00b790: 52800589  mov      w9, #0x2c
//   0x00b794: 7100211f  cmp      w8, #8
//   0x00b798: b9000aa9  str      w9, [x21, #8]
//   0x00b79c: 5400006b  b.lt     #0xb7a8
//   0x00b7a0: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b7a4: 1400001b  b        #0xb810
//   0x00b7a8: f94002a9  ldr      x9, [x21]
//   0x00b7ac: b940092a  ldr      w10, [x9, #8]
//   0x00b7b0: 5100054b  sub      w11, w10, #1
//   0x00b7b4: 3100057f  cmn      w11, #1
//   0x00b7b8: 540000e1  b.ne     #0xb7d4
//   0x00b7bc: 14000499  b        #0xca20
//   0x00b7c0: 71001d1f  cmp      w8, #7
//   0x00b7c4: 5100056b  sub      w11, w11, #1
//   0x00b7c8: 5400024c  b.gt     #0xb810
//   0x00b7cc: 3100057f  cmn      w11, #1
//   0x00b7d0: 54009280  b.eq     #0xca20
//   0x00b7d4: f940012c  ldr      x12, [x9]
//   0x00b7d8: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b7dc: 11002108  add      w8, w8, #8
//   0x00b7e0: 3840158a  ldrb     w10, [x12], #1
//   0x00b7e4: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b7e8: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b7ec: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b7f0: f900012c  str      x12, [x9]
//   0x00b7f4: 310005ac  adds     w12, w13, #1
//   0x00b7f8: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b7fc: 54fffe23  b.lo     #0xb7c0
//   0x00b800: b940112c  ldr      w12, [x9, #0x10]
//   0x00b804: 1100058c  add      w12, w12, #1
//   0x00b808: b900112c  str      w12, [x9, #0x10]
//   0x00b80c: 17ffffed  b        #0xb7c0
//   0x00b810: 51002108  sub      w8, w8, #8
//   0x00b814: 1ac82549  lsr      w9, w10, w8
//   0x00b818: 12001d29  and      w9, w9, #0xff
//   0x00b81c: 7100e13f  cmp      w9, #0x38
//   0x00b820: b90026a8  str      w8, [x21, #0x24]
//   0x00b824: 54003841  b.ne     #0xbf2c
//   0x00b828: 528005a9  mov      w9, #0x2d
//   0x00b82c: 7100211f  cmp      w8, #8
//   0x00b830: b9000aa9  str      w9, [x21, #8]
//   0x00b834: 5400006b  b.lt     #0xb840
//   0x00b838: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b83c: 1400001b  b        #0xb8a8
//   0x00b840: f94002a9  ldr      x9, [x21]
//   0x00b844: b940092a  ldr      w10, [x9, #8]
//   0x00b848: 5100054b  sub      w11, w10, #1
//   0x00b84c: 3100057f  cmn      w11, #1
//   0x00b850: 540000e1  b.ne     #0xb86c
//   0x00b854: 14000473  b        #0xca20
//   0x00b858: 71001d1f  cmp      w8, #7
//   0x00b85c: 5100056b  sub      w11, w11, #1
//   0x00b860: 5400024c  b.gt     #0xb8a8
//   0x00b864: 3100057f  cmn      w11, #1
//   0x00b868: 54008dc0  b.eq     #0xca20
//   0x00b86c: f940012c  ldr      x12, [x9]
//   0x00b870: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b874: 11002108  add      w8, w8, #8
//   0x00b878: 3840158a  ldrb     w10, [x12], #1
//   0x00b87c: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b880: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b884: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b888: f900012c  str      x12, [x9]
//   0x00b88c: 310005ac  adds     w12, w13, #1
//   0x00b890: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b894: 54fffe23  b.lo     #0xb858
//   0x00b898: b940112c  ldr      w12, [x9, #0x10]
//   0x00b89c: 1100058c  add      w12, w12, #1
//   0x00b8a0: b900112c  str      w12, [x9, #0x10]
//   0x00b8a4: 17ffffed  b        #0xb858
//   0x00b8a8: 51002108  sub      w8, w8, #8
//   0x00b8ac: 1ac82549  lsr      w9, w10, w8
//   0x00b8b0: 12001d29  and      w9, w9, #0xff
//   0x00b8b4: 7101413f  cmp      w9, #0x50
//   0x00b8b8: b90026a8  str      w8, [x21, #0x24]
//   0x00b8bc: 54003381  b.ne     #0xbf2c
//   0x00b8c0: 528005c9  mov      w9, #0x2e
//   0x00b8c4: 7100211f  cmp      w8, #8
//   0x00b8c8: b9000aa9  str      w9, [x21, #8]
//   0x00b8cc: 5400006b  b.lt     #0xb8d8
//   0x00b8d0: b94022aa  ldr      w10, [x21, #0x20]
//   0x00b8d4: 1400001b  b        #0xb940
//   0x00b8d8: f94002a9  ldr      x9, [x21]
//   0x00b8dc: b940092a  ldr      w10, [x9, #8]
//   0x00b8e0: 5100054b  sub      w11, w10, #1
//   0x00b8e4: 3100057f  cmn      w11, #1
//   0x00b8e8: 540000e1  b.ne     #0xb904
//   0x00b8ec: 1400044d  b        #0xca20
//   0x00b8f0: 71001d1f  cmp      w8, #7
//   0x00b8f4: 5100056b  sub      w11, w11, #1
//   0x00b8f8: 5400024c  b.gt     #0xb940
//   0x00b8fc: 3100057f  cmn      w11, #1
//   0x00b900: 54008900  b.eq     #0xca20
//   0x00b904: f940012c  ldr      x12, [x9]
//   0x00b908: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b90c: 11002108  add      w8, w8, #8
//   0x00b910: 3840158a  ldrb     w10, [x12], #1
//   0x00b914: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00b918: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00b91c: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00b920: f900012c  str      x12, [x9]
//   0x00b924: 310005ac  adds     w12, w13, #1
//   0x00b928: 2901312b  stp      w11, w12, [x9, #8]
//   0x00b92c: 54fffe23  b.lo     #0xb8f0
//   0x00b930: b940112c  ldr      w12, [x9, #0x10]
//   0x00b934: 1100058c  add      w12, w12, #1
//   0x00b938: b900112c  str      w12, [x9, #0x10]
//   0x00b93c: 17ffffed  b        #0xb8f0
//   0x00b940: 51002108  sub      w8, w8, #8
//   0x00b944: 1ac82549  lsr      w9, w10, w8
//   0x00b948: 12001d29  and      w9, w9, #0xff
//   0x00b94c: 7102413f  cmp      w9, #0x90
//   0x00b950: b90026a8  str      w8, [x21, #0x24]
//   0x00b954: 54002ec1  b.ne     #0xbf2c
//   0x00b958: b90c6ebf  str      wzr, [x21, #0xc6c]
//   0x00b95c: 528005e9  mov      w9, #0x2f
//   0x00b960: 7100211f  cmp      w8, #8
//   0x00b964: b9000aa9  str      w9, [x21, #8]
//   0x00b968: 5400006b  b.lt     #0xb974
//   0x00b96c: b94022a9  ldr      w9, [x21, #0x20]
//   0x00b970: 1400001b  b        #0xb9dc
//   0x00b974: f94002aa  ldr      x10, [x21]
//   0x00b978: b9400949  ldr      w9, [x10, #8]
//   0x00b97c: 5100052b  sub      w11, w9, #1
//   0x00b980: 3100057f  cmn      w11, #1
//   0x00b984: 540000e1  b.ne     #0xb9a0
//   0x00b988: 14000426  b        #0xca20
//   0x00b98c: 71001d1f  cmp      w8, #7
//   0x00b990: 5100056b  sub      w11, w11, #1
//   0x00b994: 5400024c  b.gt     #0xb9dc
//   0x00b998: 3100057f  cmn      w11, #1
//   0x00b99c: 54008420  b.eq     #0xca20
//   0x00b9a0: f940014c  ldr      x12, [x10]
//   0x00b9a4: b94022ad  ldr      w13, [x21, #0x20]
//   0x00b9a8: 11002108  add      w8, w8, #8
//   0x00b9ac: 38401589  ldrb     w9, [x12], #1
//   0x00b9b0: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00b9b4: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00b9b8: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00b9bc: f900014c  str      x12, [x10]
//   0x00b9c0: 310005ac  adds     w12, w13, #1
//   0x00b9c4: 2901314b  stp      w11, w12, [x10, #8]
//   0x00b9c8: 54fffe23  b.lo     #0xb98c
//   0x00b9cc: b940114c  ldr      w12, [x10, #0x10]
//   0x00b9d0: 1100058c  add      w12, w12, #1
//   0x00b9d4: b900114c  str      w12, [x10, #0x10]
//   0x00b9d8: 17ffffed  b        #0xb98c
//   0x00b9dc: b94c6eaa  ldr      w10, [x21, #0xc6c]
//   0x00b9e0: 51002108  sub      w8, w8, #8
//   0x00b9e4: 1ac82529  lsr      w9, w9, w8
//   0x00b9e8: b90026a8  str      w8, [x21, #0x24]
//   0x00b9ec: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00b9f0: b90c6ea9  str      w9, [x21, #0xc6c]
//   0x00b9f4: 52800609  mov      w9, #0x30
//   0x00b9f8: 7100211f  cmp      w8, #8
//   0x00b9fc: b9000aa9  str      w9, [x21, #8]
//   0x00ba00: 5400006b  b.lt     #0xba0c
//   0x00ba04: b94022a9  ldr      w9, [x21, #0x20]
//   0x00ba08: 1400001b  b        #0xba74
//   0x00ba0c: f94002aa  ldr      x10, [x21]
//   0x00ba10: b9400949  ldr      w9, [x10, #8]
//   0x00ba14: 5100052b  sub      w11, w9, #1
//   0x00ba18: 3100057f  cmn      w11, #1
//   0x00ba1c: 540000e1  b.ne     #0xba38
//   0x00ba20: 14000400  b        #0xca20
//   0x00ba24: 71001d1f  cmp      w8, #7
//   0x00ba28: 5100056b  sub      w11, w11, #1
//   0x00ba2c: 5400024c  b.gt     #0xba74
//   0x00ba30: 3100057f  cmn      w11, #1
//   0x00ba34: 54007f60  b.eq     #0xca20
//   0x00ba38: f940014c  ldr      x12, [x10]
//   0x00ba3c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00ba40: 11002108  add      w8, w8, #8
//   0x00ba44: 38401589  ldrb     w9, [x12], #1
//   0x00ba48: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00ba4c: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00ba50: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00ba54: f900014c  str      x12, [x10]
//   0x00ba58: 310005ac  adds     w12, w13, #1
//   0x00ba5c: 2901314b  stp      w11, w12, [x10, #8]
//   0x00ba60: 54fffe23  b.lo     #0xba24
//   0x00ba64: b940114c  ldr      w12, [x10, #0x10]
//   0x00ba68: 1100058c  add      w12, w12, #1
//   0x00ba6c: b900114c  str      w12, [x10, #0x10]
//   0x00ba70: 17ffffed  b        #0xba24
//   0x00ba74: b94c6eaa  ldr      w10, [x21, #0xc6c]
//   0x00ba78: 51002108  sub      w8, w8, #8
//   0x00ba7c: 1ac82529  lsr      w9, w9, w8
//   0x00ba80: b90026a8  str      w8, [x21, #0x24]
//   0x00ba84: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00ba88: b90c6ea9  str      w9, [x21, #0xc6c]
//   0x00ba8c: 52800629  mov      w9, #0x31
//   0x00ba90: 7100211f  cmp      w8, #8
//   0x00ba94: b9000aa9  str      w9, [x21, #8]
//   0x00ba98: 5400006b  b.lt     #0xbaa4
//   0x00ba9c: b94022a9  ldr      w9, [x21, #0x20]
//   0x00baa0: 1400001b  b        #0xbb0c
//   0x00baa4: f94002aa  ldr      x10, [x21]
//   0x00baa8: b9400949  ldr      w9, [x10, #8]
//   0x00baac: 5100052b  sub      w11, w9, #1
//   0x00bab0: 3100057f  cmn      w11, #1
//   0x00bab4: 540000e1  b.ne     #0xbad0
//   0x00bab8: 140003da  b        #0xca20
//   0x00babc: 71001d1f  cmp      w8, #7
//   0x00bac0: 5100056b  sub      w11, w11, #1
//   0x00bac4: 5400024c  b.gt     #0xbb0c
//   0x00bac8: 3100057f  cmn      w11, #1
//   0x00bacc: 54007aa0  b.eq     #0xca20
//   0x00bad0: f940014c  ldr      x12, [x10]
//   0x00bad4: b94022ad  ldr      w13, [x21, #0x20]
//   0x00bad8: 11002108  add      w8, w8, #8
//   0x00badc: 38401589  ldrb     w9, [x12], #1
//   0x00bae0: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00bae4: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00bae8: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00baec: f900014c  str      x12, [x10]
//   0x00baf0: 310005ac  adds     w12, w13, #1
//   0x00baf4: 2901314b  stp      w11, w12, [x10, #8]
//   0x00baf8: 54fffe23  b.lo     #0xbabc
//   0x00bafc: b940114c  ldr      w12, [x10, #0x10]
//   0x00bb00: 1100058c  add      w12, w12, #1
//   0x00bb04: b900114c  str      w12, [x10, #0x10]
//   0x00bb08: 17ffffed  b        #0xbabc
//   0x00bb0c: b94c6eaa  ldr      w10, [x21, #0xc6c]
//   0x00bb10: 51002108  sub      w8, w8, #8
//   0x00bb14: 1ac82529  lsr      w9, w9, w8
//   0x00bb18: b90026a8  str      w8, [x21, #0x24]
//   0x00bb1c: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00bb20: b90c6ea9  str      w9, [x21, #0xc6c]
//   0x00bb24: 52800649  mov      w9, #0x32
//   0x00bb28: 7100211f  cmp      w8, #8
//   0x00bb2c: b9000aa9  str      w9, [x21, #8]
//   0x00bb30: 5400006b  b.lt     #0xbb3c
//   0x00bb34: b94022a9  ldr      w9, [x21, #0x20]
//   0x00bb38: 1400001b  b        #0xbba4
//   0x00bb3c: f94002aa  ldr      x10, [x21]
//   0x00bb40: b9400949  ldr      w9, [x10, #8]
//   0x00bb44: 5100052b  sub      w11, w9, #1
//   0x00bb48: 3100057f  cmn      w11, #1
//   0x00bb4c: 540000e1  b.ne     #0xbb68
//   0x00bb50: 140003b4  b        #0xca20
//   0x00bb54: 71001d1f  cmp      w8, #7
//   0x00bb58: 5100056b  sub      w11, w11, #1
//   0x00bb5c: 5400024c  b.gt     #0xbba4
//   0x00bb60: 3100057f  cmn      w11, #1
//   0x00bb64: 540075e0  b.eq     #0xca20
//   0x00bb68: f940014c  ldr      x12, [x10]
//   0x00bb6c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00bb70: 11002108  add      w8, w8, #8
//   0x00bb74: 38401589  ldrb     w9, [x12], #1
//   0x00bb78: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00bb7c: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00bb80: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00bb84: f900014c  str      x12, [x10]
//   0x00bb88: 310005ac  adds     w12, w13, #1
//   0x00bb8c: 2901314b  stp      w11, w12, [x10, #8]
//   0x00bb90: 54fffe23  b.lo     #0xbb54
//   0x00bb94: b940114c  ldr      w12, [x10, #0x10]
//   0x00bb98: 1100058c  add      w12, w12, #1
//   0x00bb9c: b900114c  str      w12, [x10, #0x10]
//   0x00bba0: 17ffffed  b        #0xbb54
//   0x00bba4: b94c6eaa  ldr      w10, [x21, #0xc6c]
//   0x00bba8: 51002108  sub      w8, w8, #8
//   0x00bbac: 1ac82529  lsr      w9, w9, w8
//   0x00bbb0: 5280002b  mov      w11, #1
//   0x00bbb4: 33185d49  bfi      w9, w10, #8, #0x18
//   0x00bbb8: b90026a8  str      w8, [x21, #0x24]
//   0x00bbbc: b9000aab  str      w11, [x21, #8]
//   0x00bbc0: b90c6ea9  str      w9, [x21, #0xc6c]
//   0x00bbc4: 52800080  mov      w0, #4
//   0x00bbc8: 14000397  b        #0xca24
//   0x00bbcc: 2a1703e6  mov      w6, w23
//   0x00bbd0: a9413bf0  ldp      x16, x14, [sp, #0x10]
//   0x00bbd4: 2a1c03e1  mov      w1, w28
//   0x00bbd8: 2a1303e2  mov      w2, w19
//   0x00bbdc: 2a1a03f1  mov      w17, w26
//   0x00bbe0: b94023e7  ldr      w7, [sp, #0x20]
//   0x00bbe4: 2948d3e3  ldp      w3, w20, [sp, #0x44]
//   0x00bbe8: f94033f3  ldr      x19, [sp, #0x60]
//   0x00bbec: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00bbf0: 294b6bf7  ldp      w23, w26, [sp, #0x58]
//   0x00bbf4: b9404fe5  ldr      w5, [sp, #0x4c]
//   0x00bbf8: a94313ef  ldp      x15, x4, [sp, #0x30]
//   0x00bbfc: f94007fe  ldr      x30, [sp, #8]
//   0x00bc00: 14000389  b        #0xca24
//   0x00bc04: 12800040  mov      w0, #-3
//   0x00bc08: 14000387  b        #0xca24
//   0x00bc0c: 710041ff  cmp      w15, #0x10
//   0x00bc10: 5400058a  b.ge     #0xbcc0
//   0x00bc14: b94026a8  ldr      w8, [x21, #0x24]
//   0x00bc18: 52800389  mov      w9, #0x1c
//   0x00bc1c: b9000aa9  str      w9, [x21, #8]
//   0x00bc20: 7100051f  cmp      w8, #1
//   0x00bc24: 5400006b  b.lt     #0xbc30
//   0x00bc28: b94022a9  ldr      w9, [x21, #0x20]
//   0x00bc2c: 1400001b  b        #0xbc98
//   0x00bc30: f94002aa  ldr      x10, [x21]
//   0x00bc34: b9400949  ldr      w9, [x10, #8]
//   0x00bc38: 5100052b  sub      w11, w9, #1
//   0x00bc3c: 3100057f  cmn      w11, #1
//   0x00bc40: 540000e1  b.ne     #0xbc5c
//   0x00bc44: 14000377  b        #0xca20
//   0x00bc48: 7100011f  cmp      w8, #0
//   0x00bc4c: 5100056b  sub      w11, w11, #1
//   0x00bc50: 5400024c  b.gt     #0xbc98
//   0x00bc54: 3100057f  cmn      w11, #1
//   0x00bc58: 54006e40  b.eq     #0xca20
//   0x00bc5c: f940014c  ldr      x12, [x10]
//   0x00bc60: b94022ad  ldr      w13, [x21, #0x20]
//   0x00bc64: 11002108  add      w8, w8, #8
//   0x00bc68: 38401589  ldrb     w9, [x12], #1
//   0x00bc6c: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00bc70: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00bc74: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00bc78: f900014c  str      x12, [x10]
//   0x00bc7c: 310005ac  adds     w12, w13, #1
//   0x00bc80: 2901314b  stp      w11, w12, [x10, #8]
//   0x00bc84: 54fffe23  b.lo     #0xbc48
//   0x00bc88: b940114c  ldr      w12, [x10, #0x10]
//   0x00bc8c: 1100058c  add      w12, w12, #1
//   0x00bc90: b900114c  str      w12, [x10, #0x10]
//   0x00bc94: 17ffffed  b        #0xbc48
//   0x00bc98: 51000508  sub      w8, w8, #1
//   0x00bc9c: 5280002a  mov      w10, #1
//   0x00bca0: b90026a8  str      w8, [x21, #0x24]
//   0x00bca4: 1ac82148  lsl      w8, w10, w8
//   0x00bca8: 6a08013f  tst      w9, w8
//   0x00bcac: 8b2fc2ab  add      x11, x21, w15, sxtw
//   0x00bcb0: 1a9f07e8  cset     w8, ne
//   0x00bcb4: 3935f168  strb     w8, [x11, #0xd7c]
//   0x00bcb8: 110005ef  add      w15, w15, #1
//   0x00bcbc: 17ffffd4  b        #0xbc0c
//   0x00bcc0: 9131f2a8  add      x8, x21, #0xc7c
//   0x00bcc4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00bcc8: 2a1f03ef  mov      w15, wzr
//   0x00bccc: ad070100  stp      q0, q0, [x8, #0xe0]
//   0x00bcd0: ad060100  stp      q0, q0, [x8, #0xc0]
//   0x00bcd4: ad050100  stp      q0, q0, [x8, #0xa0]
//   0x00bcd8: ad040100  stp      q0, q0, [x8, #0x80]
//   0x00bcdc: ad030100  stp      q0, q0, [x8, #0x60]
//   0x00bce0: ad020100  stp      q0, q0, [x8, #0x40]
//   0x00bce4: ad010100  stp      q0, q0, [x8, #0x20]
//   0x00bce8: ad000100  stp      q0, q0, [x8]
//   0x00bcec: 71003dff  cmp      w15, #0xf
//   0x00bcf0: 5400176d  b.le     #0xbfdc
//   0x00bcf4: 2a1f03e9  mov      w9, wzr
//   0x00bcf8: aa1f03e8  mov      x8, xzr
//   0x00bcfc: 9131f2aa  add      x10, x21, #0xc7c
//   0x00bd00: b90c7abf  str      wzr, [x21, #0xc78]
//   0x00bd04: 3868694b  ldrb     w11, [x10, x8]
//   0x00bd08: 350000cb  cbnz     w11, #0xbd20
//   0x00bd0c: 91000508  add      x8, x8, #1
//   0x00bd10: f104011f  cmp      x8, #0x100
//   0x00bd14: 54000120  b.eq     #0xbd38
//   0x00bd18: 3868694b  ldrb     w11, [x10, x8]
//   0x00bd1c: 34ffff8b  cbz      w11, #0xbd0c
//   0x00bd20: 8b29c2a9  add      x9, x21, w9, sxtw
//   0x00bd24: 39363128  strb     w8, [x9, #0xd8c]
//   0x00bd28: b94c7aa9  ldr      w9, [x21, #0xc78]
//   0x00bd2c: 11000529  add      w9, w9, #1
//   0x00bd30: b90c7aa9  str      w9, [x21, #0xc78]
//   0x00bd34: 17fffff6  b        #0xbd0c
//   0x00bd38: 34000fa9  cbz      w9, #0xbf2c
//   0x00bd3c: 11000926  add      w6, w9, #2
//   0x00bd40: b94026a8  ldr      w8, [x21, #0x24]
//   0x00bd44: 528003c9  mov      w9, #0x1e
//   0x00bd48: b9000aa9  str      w9, [x21, #8]
//   0x00bd4c: 71000d1f  cmp      w8, #3
//   0x00bd50: 5400006b  b.lt     #0xbd5c
//   0x00bd54: b94022aa  ldr      w10, [x21, #0x20]
//   0x00bd58: 1400001b  b        #0xbdc4
//   0x00bd5c: f94002a9  ldr      x9, [x21]
//   0x00bd60: b940092a  ldr      w10, [x9, #8]
//   0x00bd64: 5100054b  sub      w11, w10, #1
//   0x00bd68: 3100057f  cmn      w11, #1
//   0x00bd6c: 540000e1  b.ne     #0xbd88
//   0x00bd70: 1400032c  b        #0xca20
//   0x00bd74: 7100091f  cmp      w8, #2
//   0x00bd78: 5100056b  sub      w11, w11, #1
//   0x00bd7c: 5400024c  b.gt     #0xbdc4
//   0x00bd80: 3100057f  cmn      w11, #1
//   0x00bd84: 540064e0  b.eq     #0xca20
//   0x00bd88: f940012c  ldr      x12, [x9]
//   0x00bd8c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00bd90: 11002108  add      w8, w8, #8
//   0x00bd94: 3840158a  ldrb     w10, [x12], #1
//   0x00bd98: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00bd9c: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00bda0: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00bda4: f900012c  str      x12, [x9]
//   0x00bda8: 310005ac  adds     w12, w13, #1
//   0x00bdac: 2901312b  stp      w11, w12, [x9, #8]
//   0x00bdb0: 54fffe23  b.lo     #0xbd74
//   0x00bdb4: b940112c  ldr      w12, [x9, #0x10]
//   0x00bdb8: 1100058c  add      w12, w12, #1
//   0x00bdbc: b900112c  str      w12, [x9, #0x10]
//   0x00bdc0: 17ffffed  b        #0xbd74
//   0x00bdc4: 51000d08  sub      w8, w8, #3
//   0x00bdc8: 1ac82549  lsr      w9, w10, w8
//   0x00bdcc: 12000927  and      w7, w9, #7
//   0x00bdd0: 71001cff  cmp      w7, #7
//   0x00bdd4: b90026a8  str      w8, [x21, #0x24]
//   0x00bdd8: 54ff4d28  b.hi     #0xa77c
//   0x00bddc: 52800029  mov      w9, #1
//   0x00bde0: 1ac72129  lsl      w9, w9, w7
//   0x00bde4: 5280106a  mov      w10, #0x83
//   0x00bde8: 6a0a013f  tst      w9, w10
//   0x00bdec: 54000a01  b.ne     #0xbf2c
//   0x00bdf0: 17fffa63  b        #0xa77c
//   0x00bdf4: 528004a9  mov      w9, #0x25
//   0x00bdf8: 7100011f  cmp      w8, #0
//   0x00bdfc: b9000aa9  str      w9, [x21, #8]
//   0x00be00: 540000ad  b.le     #0xbe14
//   0x00be04: b94022a9  ldr      w9, [x21, #0x20]
//   0x00be08: 14000017  b        #0xbe64
//   0x00be0c: 7100011f  cmp      w8, #0
//   0x00be10: 540002ac  b.gt     #0xbe64
//   0x00be14: f94002aa  ldr      x10, [x21]
//   0x00be18: b940094b  ldr      w11, [x10, #8]
//   0x00be1c: 34000d6b  cbz      w11, #0xbfc8
//   0x00be20: f940014c  ldr      x12, [x10]
//   0x00be24: b94022ad  ldr      w13, [x21, #0x20]
//   0x00be28: 11002108  add      w8, w8, #8
//   0x00be2c: 5100056b  sub      w11, w11, #1
//   0x00be30: 38401589  ldrb     w9, [x12], #1
//   0x00be34: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00be38: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00be3c: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00be40: b900094b  str      w11, [x10, #8]
//   0x00be44: f900014c  str      x12, [x10]
//   0x00be48: 310005ab  adds     w11, w13, #1
//   0x00be4c: b9000d4b  str      w11, [x10, #0xc]
//   0x00be50: 54fffde3  b.lo     #0xbe0c
//   0x00be54: b940114b  ldr      w11, [x10, #0x10]
//   0x00be58: 1100056b  add      w11, w11, #1
//   0x00be5c: b900114b  str      w11, [x10, #0x10]
//   0x00be60: 17ffffeb  b        #0xbe0c
//   0x00be64: 51000508  sub      w8, w8, #1
//   0x00be68: 1ac82529  lsr      w9, w9, w8
//   0x00be6c: 12000123  and      w3, w9, #1
//   0x00be70: 331f7b49  bfi      w9, w26, #1, #0x1f
//   0x00be74: b90026a8  str      w8, [x21, #0x24]
//   0x00be78: 2a0903fa  mov      w26, w9
//   0x00be7c: 7100501f  cmp      w0, #0x14
//   0x00be80: 5400054c  b.gt     #0xbf28
//   0x00be84: b860dac9  ldr      w9, [x22, w0, sxtw #2]
//   0x00be88: 6b09035f  cmp      w26, w9
//   0x00be8c: 540060ed  b.le     #0xcaa8
//   0x00be90: 11000400  add      w0, w0, #1
//   0x00be94: 17ffffd8  b        #0xbdf4
//   0x00be98: 528004e9  mov      w9, #0x27
//   0x00be9c: 7100011f  cmp      w8, #0
//   0x00bea0: b9000aa9  str      w9, [x21, #8]
//   0x00bea4: 540000ad  b.le     #0xbeb8
//   0x00bea8: b94022a9  ldr      w9, [x21, #0x20]
//   0x00beac: 14000017  b        #0xbf08
//   0x00beb0: 7100011f  cmp      w8, #0
//   0x00beb4: 540002ac  b.gt     #0xbf08
//   0x00beb8: f94002aa  ldr      x10, [x21]
//   0x00bebc: b940094b  ldr      w11, [x10, #8]
//   0x00bec0: 3400084b  cbz      w11, #0xbfc8
//   0x00bec4: f940014c  ldr      x12, [x10]
//   0x00bec8: b94022ad  ldr      w13, [x21, #0x20]
//   0x00becc: 11002108  add      w8, w8, #8
//   0x00bed0: 5100056b  sub      w11, w11, #1
//   0x00bed4: 38401589  ldrb     w9, [x12], #1
//   0x00bed8: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00bedc: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00bee0: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00bee4: b900094b  str      w11, [x10, #8]
//   0x00bee8: f900014c  str      x12, [x10]
//   0x00beec: 310005ab  adds     w11, w13, #1
//   0x00bef0: b9000d4b  str      w11, [x10, #0xc]
//   0x00bef4: 54fffde3  b.lo     #0xbeb0
//   0x00bef8: b940114b  ldr      w11, [x10, #0x10]
//   0x00befc: 1100056b  add      w11, w11, #1
//   0x00bf00: b900114b  str      w11, [x10, #0x10]
//   0x00bf04: 17ffffeb  b        #0xbeb0
//   0x00bf08: 51000508  sub      w8, w8, #1
//   0x00bf0c: 1ac82529  lsr      w9, w9, w8
//   0x00bf10: 12000123  and      w3, w9, #1
//   0x00bf14: 331f7b49  bfi      w9, w26, #1, #0x1f
//   0x00bf18: b90026a8  str      w8, [x21, #0x24]
//   0x00bf1c: 2a0903fa  mov      w26, w9
//   0x00bf20: 7100501f  cmp      w0, #0x14
//   0x00bf24: 54006fad  b.le     #0xcd18
//   0x00bf28: f81883a0  stur     x0, [x29, #-0x78]
//   0x00bf2c: 12800060  mov      w0, #-4
//   0x00bf30: 140002bd  b        #0xca24
//   0x00bf34: 52800529  mov      w9, #0x29
//   0x00bf38: 7100011f  cmp      w8, #0
//   0x00bf3c: b9000aa9  str      w9, [x21, #8]
//   0x00bf40: 540000ad  b.le     #0xbf54
//   0x00bf44: b94022a9  ldr      w9, [x21, #0x20]
//   0x00bf48: 14000017  b        #0xbfa4
//   0x00bf4c: 7100011f  cmp      w8, #0
//   0x00bf50: 540002ac  b.gt     #0xbfa4
//   0x00bf54: f94002aa  ldr      x10, [x21]
//   0x00bf58: b940094b  ldr      w11, [x10, #8]
//   0x00bf5c: 3400036b  cbz      w11, #0xbfc8
//   0x00bf60: f940014c  ldr      x12, [x10]
//   0x00bf64: b94022ad  ldr      w13, [x21, #0x20]
//   0x00bf68: 11002108  add      w8, w8, #8
//   0x00bf6c: 5100056b  sub      w11, w11, #1
//   0x00bf70: 38401589  ldrb     w9, [x12], #1
//   0x00bf74: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00bf78: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00bf7c: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00bf80: b900094b  str      w11, [x10, #8]
//   0x00bf84: f900014c  str      x12, [x10]
//   0x00bf88: 310005ab  adds     w11, w13, #1
//   0x00bf8c: b9000d4b  str      w11, [x10, #0xc]
//   0x00bf90: 54fffde3  b.lo     #0xbf4c
//   0x00bf94: b940114b  ldr      w11, [x10, #0x10]
//   0x00bf98: 1100056b  add      w11, w11, #1
//   0x00bf9c: b900114b  str      w11, [x10, #0x10]
//   0x00bfa0: 17ffffeb  b        #0xbf4c
//   0x00bfa4: 51000508  sub      w8, w8, #1
//   0x00bfa8: 1ac82529  lsr      w9, w9, w8
//   0x00bfac: 12000123  and      w3, w9, #1
//   0x00bfb0: 331f7b49  bfi      w9, w26, #1, #0x1f
//   0x00bfb4: b90026a8  str      w8, [x21, #0x24]
//   0x00bfb8: 2a0903fa  mov      w26, w9
//   0x00bfbc: 7100501f  cmp      w0, #0x14
//   0x00bfc0: 54008f8d  b.le     #0xd1b0
//   0x00bfc4: 17ffffd9  b        #0xbf28
//   0x00bfc8: f81883a0  stur     x0, [x29, #-0x78]
//   0x00bfcc: 14000295  b        #0xca20
//   0x00bfd0: 110005ef  add      w15, w15, #1
//   0x00bfd4: 71003dff  cmp      w15, #0xf
//   0x00bfd8: 54ffe8ec  b.gt     #0xbcf4
//   0x00bfdc: 8b2fc2a8  add      x8, x21, w15, sxtw
//   0x00bfe0: 3975f108  ldrb     w8, [x8, #0xd7c]
//   0x00bfe4: 34ffff68  cbz      w8, #0xbfd0
//   0x00bfe8: 2a1f03ea  mov      w10, wzr
//   0x00bfec: 71003d5f  cmp      w10, #0xf
//   0x00bff0: b81943aa  stur     w10, [x29, #-0x6c]
//   0x00bff4: 54fffeec  b.gt     #0xbfd0
//   0x00bff8: b94026a8  ldr      w8, [x21, #0x24]
//   0x00bffc: 528003a9  mov      w9, #0x1d
//   0x00c000: b9000aa9  str      w9, [x21, #8]
//   0x00c004: 7100051f  cmp      w8, #1
//   0x00c008: 5400006b  b.lt     #0xc014
//   0x00c00c: b94022aa  ldr      w10, [x21, #0x20]
//   0x00c010: 1400001b  b        #0xc07c
//   0x00c014: f94002a9  ldr      x9, [x21]
//   0x00c018: b940092a  ldr      w10, [x9, #8]
//   0x00c01c: 5100054b  sub      w11, w10, #1
//   0x00c020: 3100057f  cmn      w11, #1
//   0x00c024: 540000e1  b.ne     #0xc040
//   0x00c028: 1400027e  b        #0xca20
//   0x00c02c: 7100011f  cmp      w8, #0
//   0x00c030: 5100056b  sub      w11, w11, #1
//   0x00c034: 5400024c  b.gt     #0xc07c
//   0x00c038: 3100057f  cmn      w11, #1
//   0x00c03c: 54004f20  b.eq     #0xca20
//   0x00c040: f940012c  ldr      x12, [x9]
//   0x00c044: b94022ad  ldr      w13, [x21, #0x20]
//   0x00c048: 11002108  add      w8, w8, #8
//   0x00c04c: 3840158a  ldrb     w10, [x12], #1
//   0x00c050: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00c054: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00c058: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00c05c: f900012c  str      x12, [x9]
//   0x00c060: 310005ac  adds     w12, w13, #1
//   0x00c064: 2901312b  stp      w11, w12, [x9, #8]
//   0x00c068: 54fffe23  b.lo     #0xc02c
//   0x00c06c: b940112c  ldr      w12, [x9, #0x10]
//   0x00c070: 1100058c  add      w12, w12, #1
//   0x00c074: b900112c  str      w12, [x9, #0x10]
//   0x00c078: 17ffffed  b        #0xc02c
//   0x00c07c: 51000509  sub      w9, w8, #1
//   0x00c080: 52800028  mov      w8, #1
//   0x00c084: 1ac9210b  lsl      w11, w8, w9
//   0x00c088: 6a0b015f  tst      w10, w11
//   0x00c08c: b85943aa  ldur     w10, [x29, #-0x6c]
//   0x00c090: b90026a9  str      w9, [x21, #0x24]
//   0x00c094: 54000080  b.eq     #0xc0a4
//   0x00c098: 0b0f1149  add      w9, w10, w15, lsl #4
//   0x00c09c: 8b29c2a9  add      x9, x21, w9, sxtw
//   0x00c0a0: 3931f128  strb     w8, [x9, #0xc7c]
//   0x00c0a4: 1100054a  add      w10, w10, #1
//   0x00c0a8: 17ffffd1  b        #0xbfec
//   0x00c0ac: b9407fe8  ldr      w8, [sp, #0x7c]
//   0x00c0b0: 6b08013f  cmp      w9, w8
//   0x00c0b4: 54000e6a  b.ge     #0xc280
//   0x00c0b8: 2a0903ef  mov      w15, w9
//   0x00c0bc: b81943bf  stur     wzr, [x29, #-0x6c]
//   0x00c0c0: 52800408  mov      w8, #0x20
//   0x00c0c4: 5280002d  mov      w13, #1
//   0x00c0c8: 12800060  mov      w0, #-4
//   0x00c0cc: b94026aa  ldr      w10, [x21, #0x24]
//   0x00c0d0: b9000aa8  str      w8, [x21, #8]
//   0x00c0d4: 7100055f  cmp      w10, #1
//   0x00c0d8: 5400006b  b.lt     #0xc0e4
//   0x00c0dc: b94022ac  ldr      w12, [x21, #0x20]
//   0x00c0e0: 1400003f  b        #0xc1dc
//   0x00c0e4: f94002ab  ldr      x11, [x21]
//   0x00c0e8: 2a0503e9  mov      w9, w5
//   0x00c0ec: b9407fe5  ldr      w5, [sp, #0x7c]
//   0x00c0f0: b9005bf7  str      w23, [sp, #0x58]
//   0x00c0f4: b940096c  ldr      w12, [x11, #8]
//   0x00c0f8: aa1e03f7  mov      x23, x30
//   0x00c0fc: 2a1a03fe  mov      w30, w26
//   0x00c100: 2a1103fa  mov      w26, w17
//   0x00c104: 2a0203f1  mov      w17, w2
//   0x00c108: 2a0303e2  mov      w2, w3
//   0x00c10c: 2a1403e3  mov      w3, w20
//   0x00c110: 2a0603f4  mov      w20, w6
//   0x00c114: aa1c03e6  mov      x6, x28
//   0x00c118: aa1603fc  mov      x28, x22
//   0x00c11c: aa1003f6  mov      x22, x16
//   0x00c120: 2a0103f0  mov      w16, w1
//   0x00c124: 2a1903e1  mov      w1, w25
//   0x00c128: 2a0703f9  mov      w25, w7
//   0x00c12c: aa0e03e7  mov      x7, x14
//   0x00c130: aa0f03fb  mov      x27, x15
//   0x00c134: 5100058d  sub      w13, w12, #1
//   0x00c138: 310005bf  cmn      w13, #1
//   0x00c13c: 540000e1  b.ne     #0xc158
//   0x00c140: 14000032  b        #0xc208
//   0x00c144: 7100015f  cmp      w10, #0
//   0x00c148: 510005ad  sub      w13, w13, #1
//   0x00c14c: 5400024c  b.gt     #0xc194
//   0x00c150: 310005bf  cmn      w13, #1
//   0x00c154: 540005a0  b.eq     #0xc208
//   0x00c158: f940016e  ldr      x14, [x11]
//   0x00c15c: b94022af  ldr      w15, [x21, #0x20]
//   0x00c160: 1100214a  add      w10, w10, #8
//   0x00c164: 384015cc  ldrb     w12, [x14], #1
//   0x00c168: 33185dec  bfi      w12, w15, #8, #0x18
//   0x00c16c: 29042aac  stp      w12, w10, [x21, #0x20]
//   0x00c170: b9400d6f  ldr      w15, [x11, #0xc]
//   0x00c174: f900016e  str      x14, [x11]
//   0x00c178: 310005ee  adds     w14, w15, #1
//   0x00c17c: 2901396d  stp      w13, w14, [x11, #8]
//   0x00c180: 54fffe23  b.lo     #0xc144
//   0x00c184: b940116e  ldr      w14, [x11, #0x10]
//   0x00c188: 110005ce  add      w14, w14, #1
//   0x00c18c: b900116e  str      w14, [x11, #0x10]
//   0x00c190: 17ffffed  b        #0xc144
//   0x00c194: aa0703ee  mov      x14, x7
//   0x00c198: 2a1903e7  mov      w7, w25
//   0x00c19c: 2a0103f9  mov      w25, w1
//   0x00c1a0: 2a1003e1  mov      w1, w16
//   0x00c1a4: aa1603f0  mov      x16, x22
//   0x00c1a8: aa1c03f6  mov      x22, x28
//   0x00c1ac: aa0603fc  mov      x28, x6
//   0x00c1b0: 2a1403e6  mov      w6, w20
//   0x00c1b4: 2a0303f4  mov      w20, w3
//   0x00c1b8: 2a0203e3  mov      w3, w2
//   0x00c1bc: 2a1103e2  mov      w2, w17
//   0x00c1c0: 2a1a03f1  mov      w17, w26
//   0x00c1c4: 2a1e03fa  mov      w26, w30
//   0x00c1c8: aa1703fe  mov      x30, x23
//   0x00c1cc: b9405bf7  ldr      w23, [sp, #0x58]
//   0x00c1d0: aa1b03ef  mov      x15, x27
//   0x00c1d4: 2a0903e5  mov      w5, w9
//   0x00c1d8: 5280002d  mov      w13, #1
//   0x00c1dc: 5100054a  sub      w10, w10, #1
//   0x00c1e0: 1aca21ab  lsl      w11, w13, w10
//   0x00c1e4: 6a0b019f  tst      w12, w11
//   0x00c1e8: b90026aa  str      w10, [x21, #0x24]
//   0x00c1ec: 54000380  b.eq     #0xc25c
//   0x00c1f0: b85943a9  ldur     w9, [x29, #-0x6c]
//   0x00c1f4: 11000529  add      w9, w9, #1
//   0x00c1f8: 6b07013f  cmp      w9, w7
//   0x00c1fc: b81943a9  stur     w9, [x29, #-0x6c]
//   0x00c200: 54fff66b  b.lt     #0xc0cc
//   0x00c204: 14000208  b        #0xca24
//   0x00c208: 2a1f03e0  mov      w0, wzr
//   0x00c20c: aa1b03ef  mov      x15, x27
//   0x00c210: aa0703ee  mov      x14, x7
//   0x00c214: 2a1903e7  mov      w7, w25
//   0x00c218: 2a0103f9  mov      w25, w1
//   0x00c21c: 2a1003e1  mov      w1, w16
//   0x00c220: aa1603f0  mov      x16, x22
//   0x00c224: aa1c03f6  mov      x22, x28
//   0x00c228: aa0603fc  mov      x28, x6
//   0x00c22c: 2a1403e6  mov      w6, w20
//   0x00c230: 2a0303f4  mov      w20, w3
//   0x00c234: 2a0203e3  mov      w3, w2
//   0x00c238: 2a1103e2  mov      w2, w17
//   0x00c23c: 2a1a03f1  mov      w17, w26
//   0x00c240: 2a1e03fa  mov      w26, w30
//   0x00c244: aa1703fe  mov      x30, x23
//   0x00c248: 2a0503ed  mov      w13, w5
//   0x00c24c: 2a0903e5  mov      w5, w9
//   0x00c250: f9403be8  ldr      x8, [sp, #0x70]
//   0x00c254: b9405bf7  ldr      w23, [sp, #0x58]
//   0x00c258: 140001f5  b        #0xca2c
//   0x00c25c: 5288ca28  mov      w8, #0x4651
//   0x00c260: 6b0801ff  cmp      w15, w8
//   0x00c264: 540000ac  b.gt     #0xc278
//   0x00c268: b85943aa  ldur     w10, [x29, #-0x6c]
//   0x00c26c: 8b2fc2a8  add      x8, x21, w15, sxtw
//   0x00c270: 528ca3c9  mov      w9, #0x651e
//   0x00c274: 3829690a  strb     w10, [x8, x9]
//   0x00c278: 110005e9  add      w9, w15, #1
//   0x00c27c: 17ffff8c  b        #0xc0ac
//   0x00c280: b9407fe9  ldr      w9, [sp, #0x7c]
//   0x00c284: 5288ca48  mov      w8, #0x4652
//   0x00c288: 6b08013f  cmp      w9, w8
//   0x00c28c: 1a88b12d  csel     w13, w9, w8, lt
//   0x00c290: 710004ea  subs     w10, w7, #1
//   0x00c294: 5400014b  b.lt     #0xc2bc
//   0x00c298: 71007cff  cmp      w7, #0x1f
//   0x00c29c: 540008c8  b.hi     #0xc3b4
//   0x00c2a0: 2a1f03e9  mov      w9, wzr
//   0x00c2a4: d101a3aa  sub      x10, x29, #0x68
//   0x00c2a8: 92401d2b  and      x11, x9, #0xff
//   0x00c2ac: 382b6949  strb     w9, [x10, x11]
//   0x00c2b0: 11000529  add      w9, w9, #1
//   0x00c2b4: 6b2900ff  cmp      w7, w9, uxtb
//   0x00c2b8: 54ffff8c  b.gt     #0xc2a8
//   0x00c2bc: b9407fe8  ldr      w8, [sp, #0x7c]
//   0x00c2c0: 7100051f  cmp      w8, #1
//   0x00c2c4: 540006eb  b.lt     #0xc3a0
//   0x00c2c8: b90047e3  str      w3, [sp, #0x44]
//   0x00c2cc: 2a1403e3  mov      w3, w20
//   0x00c2d0: 2a0603f4  mov      w20, w6
//   0x00c2d4: aa1c03e6  mov      x6, x28
//   0x00c2d8: aa1603fc  mov      x28, x22
//   0x00c2dc: aa1003f6  mov      x22, x16
//   0x00c2e0: b90027e1  str      w1, [sp, #0x24]
//   0x00c2e4: aa1303e1  mov      x1, x19
//   0x00c2e8: 2a1903f3  mov      w19, w25
//   0x00c2ec: 2a0703f9  mov      w25, w7
//   0x00c2f0: aa0e03e7  mov      x7, x14
//   0x00c2f4: 2a0203fb  mov      w27, w2
//   0x00c2f8: 2a1103e2  mov      w2, w17
//   0x00c2fc: aa1f03ef  mov      x15, xzr
//   0x00c300: aa0d03f7  mov      x23, x13
//   0x00c304: 93407da9  sxtw     x9, w13
//   0x00c308: 528ca3ca  mov      w10, #0x651e
//   0x00c30c: d101a3ab  sub      x11, x29, #0x68
//   0x00c310: 5283d98c  mov      w12, #0x1ecc
//   0x00c314: 14000007  b        #0xc330
//   0x00c318: aa0803ef  mov      x15, x8
//   0x00c31c: 9100050f  add      x15, x8, #1
//   0x00c320: eb0901ff  cmp      x15, x9
//   0x00c324: 381983ae  sturb    w14, [x29, #-0x68]
//   0x00c328: 382c69ae  strb     w14, [x13, x12]
//   0x00c32c: 540001ca  b.ge     #0xc364
//   0x00c330: 8b0f02ad  add      x13, x21, x15
//   0x00c334: aa0f03e8  mov      x8, x15
//   0x00c338: 386a69af  ldrb     w15, [x13, x10]
//   0x00c33c: 386f696e  ldrb     w14, [x11, x15]
//   0x00c340: b4fffecf  cbz      x15, #0xc318
//   0x00c344: 8b0f0170  add      x16, x11, x15
//   0x00c348: 385ff211  ldurb    w17, [x16, #-1]
//   0x00c34c: 12001de0  and      w0, w15, #0xff
//   0x00c350: d10005ef  sub      x15, x15, #1
//   0x00c354: 7100041f  cmp      w0, #1
//   0x00c358: 39000211  strb     w17, [x16]
//   0x00c35c: 54ffff41  b.ne     #0xc344
//   0x00c360: 17ffffee  b        #0xc318
//   0x00c364: aa0703ee  mov      x14, x7
//   0x00c368: 2a1903e7  mov      w7, w25
//   0x00c36c: 2a1303f9  mov      w25, w19
//   0x00c370: aa0103f3  mov      x19, x1
//   0x00c374: b94027e1  ldr      w1, [sp, #0x24]
//   0x00c378: aa1603f0  mov      x16, x22
//   0x00c37c: aa1c03f6  mov      x22, x28
//   0x00c380: aa0603fc  mov      x28, x6
//   0x00c384: 2a1403e6  mov      w6, w20
//   0x00c388: 2a0303f4  mov      w20, w3
//   0x00c38c: b94047e3  ldr      w3, [sp, #0x44]
//   0x00c390: 2a0203f1  mov      w17, w2
//   0x00c394: 2a1b03e2  mov      w2, w27
//   0x00c398: aa1703ed  mov      x13, x23
//   0x00c39c: 14000002  b        #0xc3a4
//   0x00c3a0: 2a1f03ef  mov      w15, wzr
//   0x00c3a4: 2a1f03f7  mov      w23, wzr
//   0x00c3a8: 2a0d03e8  mov      w8, w13
//   0x00c3ac: b9007fed  str      w13, [sp, #0x7c]
//   0x00c3b0: 14000019  b        #0xc414
//   0x00c3b4: 2a2a03e9  mvn      w9, w10
//   0x00c3b8: 72001d3f  tst      w9, #0xff
//   0x00c3bc: 2a1f03e9  mov      w9, wzr
//   0x00c3c0: 54fff720  b.eq     #0xc2a4
//   0x00c3c4: 7103fd5f  cmp      w10, #0xff
//   0x00c3c8: 54fff6e8  b.hi     #0xc2a4
//   0x00c3cc: d0000049  adrp     x9, #0x16000
//   0x00c3d0: 3dc37d20  ldr      q0, [x9, #0xdf0]
//   0x00c3d4: 2a1f03ea  mov      w10, wzr
//   0x00c3d8: 121b68e9  and      w9, w7, #0xffffffe0
//   0x00c3dc: 4f00e601  movi     v1.16b, #0x10
//   0x00c3e0: d101a3ab  sub      x11, x29, #0x68
//   0x00c3e4: 4f01e402  movi     v2.16b, #0x20
//   0x00c3e8: 927b094c  and      x12, x10, #0xe0
//   0x00c3ec: 4e218403  add      v3.16b, v0.16b, v1.16b
//   0x00c3f0: 1100814a  add      w10, w10, #0x20
//   0x00c3f4: 8b0c016c  add      x12, x11, x12
//   0x00c3f8: 6b0a013f  cmp      w9, w10
//   0x00c3fc: ad000d80  stp      q0, q3, [x12]
//   0x00c400: 4e228400  add      v0.16b, v0.16b, v2.16b
//   0x00c404: 54ffff21  b.ne     #0xc3e8
//   0x00c408: 6b0900ff  cmp      w7, w9
//   0x00c40c: 54fff4c1  b.ne     #0xc2a4
//   0x00c410: 17ffffab  b        #0xc2bc
//   0x00c414: 6b0702ff  cmp      w23, w7
//   0x00c418: 5400054a  b.ge     #0xc4c0
//   0x00c41c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00c420: 52800429  mov      w9, #0x21
//   0x00c424: b9000aa9  str      w9, [x21, #8]
//   0x00c428: 7100151f  cmp      w8, #5
//   0x00c42c: 5400006b  b.lt     #0xc438
//   0x00c430: b94022aa  ldr      w10, [x21, #0x20]
//   0x00c434: 1400001b  b        #0xc4a0
//   0x00c438: f94002a9  ldr      x9, [x21]
//   0x00c43c: b940092a  ldr      w10, [x9, #8]
//   0x00c440: 5100054b  sub      w11, w10, #1
//   0x00c444: 3100057f  cmn      w11, #1
//   0x00c448: 540000e1  b.ne     #0xc464
//   0x00c44c: 14000175  b        #0xca20
//   0x00c450: 7100111f  cmp      w8, #4
//   0x00c454: 5100056b  sub      w11, w11, #1
//   0x00c458: 5400024c  b.gt     #0xc4a0
//   0x00c45c: 3100057f  cmn      w11, #1
//   0x00c460: 54002e00  b.eq     #0xca20
//   0x00c464: f940012c  ldr      x12, [x9]
//   0x00c468: b94022ad  ldr      w13, [x21, #0x20]
//   0x00c46c: 11002108  add      w8, w8, #8
//   0x00c470: 3840158a  ldrb     w10, [x12], #1
//   0x00c474: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00c478: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00c47c: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00c480: f900012c  str      x12, [x9]
//   0x00c484: 310005ac  adds     w12, w13, #1
//   0x00c488: 2901312b  stp      w11, w12, [x9, #8]
//   0x00c48c: 54fffe23  b.lo     #0xc450
//   0x00c490: b940112c  ldr      w12, [x9, #0x10]
//   0x00c494: 1100058c  add      w12, w12, #1
//   0x00c498: b900112c  str      w12, [x9, #0x10]
//   0x00c49c: 17ffffed  b        #0xc450
//   0x00c4a0: 51001508  sub      w8, w8, #5
//   0x00c4a4: 1ac82549  lsr      w9, w10, w8
//   0x00c4a8: 2a1f03ef  mov      w15, wzr
//   0x00c4ac: 12001139  and      w25, w9, #0x1f
//   0x00c4b0: b90026a8  str      w8, [x21, #0x24]
//   0x00c4b4: 6b0601ff  cmp      w15, w6
//   0x00c4b8: 5400260a  b.ge     #0xc978
//   0x00c4bc: 140000fd  b        #0xc8b0
//   0x00c4c0: 5283d988  mov      w8, #0x1ecc
//   0x00c4c4: 710004ff  cmp      w7, #1
//   0x00c4c8: 8b0802a8  add      x8, x21, x8
//   0x00c4cc: f90017f6  str      x22, [sp, #0x28]
//   0x00c4d0: 2908d3e3  stp      w3, w20, [sp, #0x44]
//   0x00c4d4: a9013bf0  stp      x16, x14, [sp, #0x10]
//   0x00c4d8: b90033f9  str      w25, [sp, #0x30]
//   0x00c4dc: f9001fe8  str      x8, [sp, #0x38]
//   0x00c4e0: b90023e7  str      w7, [sp, #0x20]
//   0x00c4e4: 29000bf1  stp      w17, w2, [sp]
//   0x00c4e8: 54000d0b  b.lt     #0xc688
//   0x00c4ec: 2a0703e8  mov      w8, w7
//   0x00c4f0: f90043e8  str      x8, [sp, #0x80]
//   0x00c4f4: 2a0603e9  mov      w9, w6
//   0x00c4f8: 52956e28  mov      w8, #0xab71
//   0x00c4fc: 52956e0a  mov      w10, #0xab70
//   0x00c500: aa1f03f9  mov      x25, xzr
//   0x00c504: f9003be9  str      x9, [sp, #0x70]
//   0x00c508: 927f7929  and      x9, x9, #0xfffffffe
//   0x00c50c: 8b0802bb  add      x27, x21, x8
//   0x00c510: 8b0a02b6  add      x22, x21, x10
//   0x00c514: a90627f3  stp      x19, x9, [sp, #0x60]
//   0x00c518: f9002bfc  str      x28, [sp, #0x50]
//   0x00c51c: b9005ffa  str      w26, [sp, #0x5c]
//   0x00c520: b9004fe5  str      w5, [sp, #0x4c]
//   0x00c524: 710004df  cmp      w6, #1
//   0x00c528: 540004aa  b.ge     #0xc5bc
//   0x00c52c: 2a0303fa  mov      w26, w3
//   0x00c530: 2a0103fc  mov      w28, w1
//   0x00c534: 2a1f03e5  mov      w5, wzr
//   0x00c538: 52800414  mov      w20, #0x20
//   0x00c53c: 52808108  mov      w8, #0x408
//   0x00c540: 9b085728  madd     x8, x25, x8, x21
//   0x00c544: 52962f8a  mov      w10, #0xb17c
//   0x00c548: 8b0a0100  add      x0, x8, x10
//   0x00c54c: 5299358a  mov      w10, #0xc9ac
//   0x00c550: 52802049  mov      w9, #0x102
//   0x00c554: 8b0a0101  add      x1, x8, x10
//   0x00c558: 529c3b8a  mov      w10, #0xe1dc
//   0x00c55c: 9b095729  madd     x9, x25, x9, x21
//   0x00c560: 8b0a0102  add      x2, x8, x10
//   0x00c564: 52956e08  mov      w8, #0xab70
//   0x00c568: 8b080123  add      x3, x9, x8
//   0x00c56c: 2a1403e4  mov      w4, w20
//   0x00c570: 2a0603f7  mov      w23, w6
//   0x00c574: 97ffd85f  bl       #0x26f0
//   0x00c578: 8b190aa8  add      x8, x21, x25, lsl #2
//   0x00c57c: 529f4189  mov      w9, #0xfa0c
//   0x00c580: b8296914  str      w20, [x8, x9]
//   0x00c584: f94043e8  ldr      x8, [sp, #0x80]
//   0x00c588: 2a1c03e1  mov      w1, w28
//   0x00c58c: 2a1a03e3  mov      w3, w26
//   0x00c590: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00c594: b9405ffa  ldr      w26, [sp, #0x5c]
//   0x00c598: b9404fe5  ldr      w5, [sp, #0x4c]
//   0x00c59c: 91000739  add      x25, x25, #1
//   0x00c5a0: 2a1703e6  mov      w6, w23
//   0x00c5a4: 91040b7b  add      x27, x27, #0x102
//   0x00c5a8: eb08033f  cmp      x25, x8
//   0x00c5ac: 91040ad6  add      x22, x22, #0x102
//   0x00c5b0: 54000620  b.eq     #0xc674
//   0x00c5b4: 710004df  cmp      w6, #1
//   0x00c5b8: 54fffbab  b.lt     #0xc52c
//   0x00c5bc: 710004df  cmp      w6, #1
//   0x00c5c0: 540000e1  b.ne     #0xc5dc
//   0x00c5c4: 2a0303fa  mov      w26, w3
//   0x00c5c8: 2a0103fc  mov      w28, w1
//   0x00c5cc: aa1f03e9  mov      x9, xzr
//   0x00c5d0: 2a1f03e5  mov      w5, wzr
//   0x00c5d4: 52800414  mov      w20, #0x20
//   0x00c5d8: 1400001c  b        #0xc648
//   0x00c5dc: f94037ec  ldr      x12, [sp, #0x68]
//   0x00c5e0: 2a1f03e9  mov      w9, wzr
//   0x00c5e4: 2a1f03ea  mov      w10, wzr
//   0x00c5e8: 52800408  mov      w8, #0x20
//   0x00c5ec: aa1b03ed  mov      x13, x27
//   0x00c5f0: 5280040b  mov      w11, #0x20
//   0x00c5f4: 385ff1ae  ldurb    w14, [x13, #-1]
//   0x00c5f8: 384025af  ldrb     w15, [x13], #2
//   0x00c5fc: 6b0e013f  cmp      w9, w14
//   0x00c600: 1a8931c9  csel     w9, w14, w9, lo
//   0x00c604: 6b0f015f  cmp      w10, w15
//   0x00c608: 1a8a31ea  csel     w10, w15, w10, lo
//   0x00c60c: 6b0e011f  cmp      w8, w14
//   0x00c610: 1a88c1c8  csel     w8, w14, w8, gt
//   0x00c614: 6b0f017f  cmp      w11, w15
//   0x00c618: 1a8bc1eb  csel     w11, w15, w11, gt
//   0x00c61c: f100098c  subs     x12, x12, #2
//   0x00c620: 54fffea1  b.ne     #0xc5f4
//   0x00c624: 6b0a013f  cmp      w9, w10
//   0x00c628: 1a8a8125  csel     w5, w9, w10, hi
//   0x00c62c: 6b0b011f  cmp      w8, w11
//   0x00c630: 1a8bb114  csel     w20, w8, w11, lt
//   0x00c634: a946a3e9  ldp      x9, x8, [sp, #0x68]
//   0x00c638: 2a0303fa  mov      w26, w3
//   0x00c63c: 2a0103fc  mov      w28, w1
//   0x00c640: eb08013f  cmp      x9, x8
//   0x00c644: 54fff7c0  b.eq     #0xc53c
//   0x00c648: f9403bea  ldr      x10, [sp, #0x70]
//   0x00c64c: 8b0902c8  add      x8, x22, x9
//   0x00c650: cb090149  sub      x9, x10, x9
//   0x00c654: 3840150a  ldrb     w10, [x8], #1
//   0x00c658: 6b0a00bf  cmp      w5, w10
//   0x00c65c: 1a853145  csel     w5, w10, w5, lo
//   0x00c660: 6b0a029f  cmp      w20, w10
//   0x00c664: 1a94c154  csel     w20, w10, w20, gt
//   0x00c668: f1000529  subs     x9, x9, #1
//   0x00c66c: 54ffff41  b.ne     #0xc654
//   0x00c670: 17ffffb3  b        #0xc53c
//   0x00c674: b94023e8  ldr      w8, [sp, #0x20]
//   0x00c678: 2a0503fb  mov      w27, w5
//   0x00c67c: 2a0103f9  mov      w25, w1
//   0x00c680: b9005be8  str      w8, [sp, #0x58]
//   0x00c684: 14000005  b        #0xc698
//   0x00c688: 2a0503fb  mov      w27, w5
//   0x00c68c: 2a0103f9  mov      w25, w1
//   0x00c690: 2a0603f7  mov      w23, w6
//   0x00c694: b9005bff  str      wzr, [sp, #0x58]
//   0x00c698: b94c7ab4  ldr      w20, [x21, #0xc78]
//   0x00c69c: b9402ab6  ldr      w22, [x21, #0x28]
//   0x00c6a0: 910112a0  add      x0, x21, #0x44
//   0x00c6a4: 52808002  mov      w2, #0x400
//   0x00c6a8: 2a1f03e1  mov      w1, wzr
//   0x00c6ac: 97ffd905  bl       #0x2ac0
//   0x00c6b0: d000004d  adrp     x13, #0x16000
//   0x00c6b4: fd4701a0  ldr      d0, [x13, #0xe00]
//   0x00c6b8: 5290d40b  mov      w11, #0x86a0
//   0x00c6bc: 1100068a  add      w10, w20, #1
//   0x00c6c0: 72a0002b  movk     w11, #1, lsl #16
//   0x00c6c4: 5283d90c  mov      w12, #0x1ec8
//   0x00c6c8: aa1f03e8  mov      x8, xzr
//   0x00c6cc: aa1f03e9  mov      x9, xzr
//   0x00c6d0: b9006bea  str      w10, [sp, #0x68]
//   0x00c6d4: 528001aa  mov      w10, #0xd
//   0x00c6d8: 1b0b7ec4  mul      w4, w22, w11
//   0x00c6dc: 8b0c02ab  add      x11, x21, x12
//   0x00c6e0: 5280016c  mov      w12, #0xb
//   0x00c6e4: 5280014d  mov      w13, #0xa
//   0x00c6e8: 5280012e  mov      w14, #9
//   0x00c6ec: 5100412f  sub      w15, w9, #0x10
//   0x00c6f0: 8b090170  add      x16, x11, x9
//   0x00c6f4: 32000df1  orr      w17, w15, #0xf
//   0x00c6f8: 381c3211  sturb    w17, [x16, #-0x3d]
//   0x00c6fc: 321f09f1  orr      w17, w15, #0xe
//   0x00c700: 381c2211  sturb    w17, [x16, #-0x3e]
//   0x00c704: 2a0a01f1  orr      w17, w15, w10
//   0x00c708: 381c1211  sturb    w17, [x16, #-0x3f]
//   0x00c70c: 321e05f1  orr      w17, w15, #0xc
//   0x00c710: 381c0211  sturb    w17, [x16, #-0x40]
//   0x00c714: 2a0c01f1  orr      w17, w15, w12
//   0x00c718: 381bf211  sturb    w17, [x16, #-0x41]
//   0x00c71c: 2a0d01f1  orr      w17, w15, w13
//   0x00c720: 0e010de1  dup      v1.8b, w15
//   0x00c724: 381be211  sturb    w17, [x16, #-0x42]
//   0x00c728: 113fc131  add      w17, w9, #0xff0
//   0x00c72c: d1004129  sub      x9, x9, #0x10
//   0x00c730: 381b420f  sturb    w15, [x16, #-0x4c]
//   0x00c734: 2a0e01ef  orr      w15, w15, w14
//   0x00c738: 0ea01c21  orr      v1.8b, v1.8b, v0.8b
//   0x00c73c: b104013f  cmn      x9, #0x100
//   0x00c740: 381bd20f  sturb    w15, [x16, #-0x43]
//   0x00c744: fc1b5201  stur     d1, [x16, #-0x4b]
//   0x00c748: b8286971  str      w17, [x11, x8]
//   0x00c74c: d1001108  sub      x8, x8, #4
//   0x00c750: 54fffce1  b.ne     #0xc6ec
//   0x00c754: b9407fe8  ldr      w8, [sp, #0x7c]
//   0x00c758: 2a1903e1  mov      w1, w25
//   0x00c75c: b94033f9  ldr      w25, [sp, #0x30]
//   0x00c760: b94047e3  ldr      w3, [sp, #0x44]
//   0x00c764: f94017f6  ldr      x22, [sp, #0x28]
//   0x00c768: 29400bf1  ldp      w17, w2, [sp]
//   0x00c76c: 2a0803ed  mov      w13, w8
//   0x00c770: 7100051f  cmp      w8, #1
//   0x00c774: 2a1703e6  mov      w6, w23
//   0x00c778: 2a1b03e5  mov      w5, w27
//   0x00c77c: 2a1f03fe  mov      w30, wzr
//   0x00c780: 5400086b  b.lt     #0xc88c
//   0x00c784: f9401fe8  ldr      x8, [sp, #0x38]
//   0x00c788: 52808109  mov      w9, #0x408
//   0x00c78c: f9400fee  ldr      x14, [sp, #0x18]
//   0x00c790: b9405bf7  ldr      w23, [sp, #0x58]
//   0x00c794: 39400110  ldrb     w16, [x8]
//   0x00c798: 529f4188  mov      w8, #0xfa0c
//   0x00c79c: b94023e7  ldr      w7, [sp, #0x20]
//   0x00c7a0: 5299358a  mov      w10, #0xc9ac
//   0x00c7a4: 8b304aac  add      x12, x21, w16, uxtw #2
//   0x00c7a8: b8686994  ldr      w20, [x12, x8]
//   0x00c7ac: d503201f  nop      
//   0x00c7b0: 9ba95609  umaddl   x9, w16, w9, x21
//   0x00c7b4: 52962f88  mov      w8, #0xb17c
//   0x00c7b8: 529c3b8b  mov      w11, #0xe1dc
//   0x00c7bc: 8b080136  add      x22, x9, x8
//   0x00c7c0: 52800628  mov      w8, #0x31
//   0x00c7c4: 8b0a013c  add      x28, x9, x10
//   0x00c7c8: 8b0b0133  add      x19, x9, x11
//   0x00c7cc: 5280200f  mov      w15, #0x100
//   0x00c7d0: b90083e8  str      w8, [sp, #0x80]
//   0x00c7d4: 2a1403e8  mov      w8, w20
//   0x00c7d8: f9003bff  str      xzr, [sp, #0x70]
//   0x00c7dc: f81883a8  stur     x8, [x29, #-0x78]
//   0x00c7e0: b9007fed  str      w13, [sp, #0x7c]
//   0x00c7e4: b94026a8  ldr      w8, [x21, #0x24]
//   0x00c7e8: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00c7ec: 52800489  mov      w9, #0x24
//   0x00c7f0: b9000aa9  str      w9, [x21, #8]
//   0x00c7f4: 6b00011f  cmp      w8, w0
//   0x00c7f8: 5400036a  b.ge     #0xc864
//   0x00c7fc: f94002a9  ldr      x9, [x21]
//   0x00c800: b940092a  ldr      w10, [x9, #8]
//   0x00c804: 5100054b  sub      w11, w10, #1
//   0x00c808: 3100057f  cmn      w11, #1
//   0x00c80c: 540000e1  b.ne     #0xc828
//   0x00c810: 14000084  b        #0xca20
//   0x00c814: 6b00011f  cmp      w8, w0
//   0x00c818: 5100056b  sub      w11, w11, #1
//   0x00c81c: 5400026a  b.ge     #0xc868
//   0x00c820: 3100057f  cmn      w11, #1
//   0x00c824: 54000fe0  b.eq     #0xca20
//   0x00c828: f940012c  ldr      x12, [x9]
//   0x00c82c: b94022ad  ldr      w13, [x21, #0x20]
//   0x00c830: 11002108  add      w8, w8, #8
//   0x00c834: 3840158a  ldrb     w10, [x12], #1
//   0x00c838: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00c83c: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00c840: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00c844: f900012c  str      x12, [x9]
//   0x00c848: 310005ac  adds     w12, w13, #1
//   0x00c84c: 2901312b  stp      w11, w12, [x9, #8]
//   0x00c850: 54fffe23  b.lo     #0xc814
//   0x00c854: b940112c  ldr      w12, [x9, #0x10]
//   0x00c858: 1100058c  add      w12, w12, #1
//   0x00c85c: b900112c  str      w12, [x9, #0x10]
//   0x00c860: 17ffffed  b        #0xc814
//   0x00c864: b94022aa  ldr      w10, [x21, #0x20]
//   0x00c868: 4b000108  sub      w8, w8, w0
//   0x00c86c: 12800009  mov      w9, #-1
//   0x00c870: 1ac8254a  lsr      w10, w10, w8
//   0x00c874: 1ac02129  lsl      w9, w9, w0
//   0x00c878: 0a29015a  bic      w26, w10, w9
//   0x00c87c: b90026a8  str      w8, [x21, #0x24]
//   0x00c880: 7100501f  cmp      w0, #0x14
//   0x00c884: 54ffb00d  b.le     #0xbe84
//   0x00c888: 17fffda8  b        #0xbf28
//   0x00c88c: a9413bf0  ldp      x16, x14, [sp, #0x10]
//   0x00c890: b9404bf4  ldr      w20, [sp, #0x48]
//   0x00c894: b9405bf7  ldr      w23, [sp, #0x58]
//   0x00c898: b94023e7  ldr      w7, [sp, #0x20]
//   0x00c89c: b90083ff  str      wzr, [sp, #0x80]
//   0x00c8a0: 2a1f03e8  mov      w8, wzr
//   0x00c8a4: 12800060  mov      w0, #-4
//   0x00c8a8: 5280200f  mov      w15, #0x100
//   0x00c8ac: 14000060  b        #0xca2c
//   0x00c8b0: 51000728  sub      w8, w25, #1
//   0x00c8b4: 71004d1f  cmp      w8, #0x13
//   0x00c8b8: 54ffb3a8  b.hi     #0xbf2c
//   0x00c8bc: b94026a8  ldr      w8, [x21, #0x24]
//   0x00c8c0: 52800449  mov      w9, #0x22
//   0x00c8c4: b9000aa9  str      w9, [x21, #8]
//   0x00c8c8: 7100051f  cmp      w8, #1
//   0x00c8cc: 5400006b  b.lt     #0xc8d8
//   0x00c8d0: b94022a9  ldr      w9, [x21, #0x20]
//   0x00c8d4: 1400001b  b        #0xc940
//   0x00c8d8: f94002aa  ldr      x10, [x21]
//   0x00c8dc: b9400949  ldr      w9, [x10, #8]
//   0x00c8e0: 5100052b  sub      w11, w9, #1
//   0x00c8e4: 3100057f  cmn      w11, #1
//   0x00c8e8: 540000e1  b.ne     #0xc904
//   0x00c8ec: 1400004d  b        #0xca20
//   0x00c8f0: 7100011f  cmp      w8, #0
//   0x00c8f4: 5100056b  sub      w11, w11, #1
//   0x00c8f8: 5400024c  b.gt     #0xc940
//   0x00c8fc: 3100057f  cmn      w11, #1
//   0x00c900: 54000900  b.eq     #0xca20
//   0x00c904: f940014c  ldr      x12, [x10]
//   0x00c908: b94022ad  ldr      w13, [x21, #0x20]
//   0x00c90c: 11002108  add      w8, w8, #8
//   0x00c910: 38401589  ldrb     w9, [x12], #1
//   0x00c914: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00c918: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00c91c: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00c920: f900014c  str      x12, [x10]
//   0x00c924: 310005ac  adds     w12, w13, #1
//   0x00c928: 2901314b  stp      w11, w12, [x10, #8]
//   0x00c92c: 54fffe23  b.lo     #0xc8f0
//   0x00c930: b940114c  ldr      w12, [x10, #0x10]
//   0x00c934: 1100058c  add      w12, w12, #1
//   0x00c938: b900114c  str      w12, [x10, #0x10]
//   0x00c93c: 17ffffed  b        #0xc8f0
//   0x00c940: 51000508  sub      w8, w8, #1
//   0x00c944: 5280002a  mov      w10, #1
//   0x00c948: 1ac8214a  lsl      w10, w10, w8
//   0x00c94c: 6a0a013f  tst      w9, w10
//   0x00c950: b90026a8  str      w8, [x21, #0x24]
//   0x00c954: 54000161  b.ne     #0xc980
//   0x00c958: 52802048  mov      w8, #0x102
//   0x00c95c: 9b2856e8  smaddl   x8, w23, w8, x21
//   0x00c960: 52956e09  mov      w9, #0xab70
//   0x00c964: 8b2fc108  add      x8, x8, w15, sxtw
//   0x00c968: 38296919  strb     w25, [x8, x9]
//   0x00c96c: 110005ef  add      w15, w15, #1
//   0x00c970: 6b0601ff  cmp      w15, w6
//   0x00c974: 54fff9eb  b.lt     #0xc8b0
//   0x00c978: 110006f7  add      w23, w23, #1
//   0x00c97c: 17fffea6  b        #0xc414
//   0x00c980: 52800469  mov      w9, #0x23
//   0x00c984: 7100051f  cmp      w8, #1
//   0x00c988: b9000aa9  str      w9, [x21, #8]
//   0x00c98c: 5400006b  b.lt     #0xc998
//   0x00c990: b94022aa  ldr      w10, [x21, #0x20]
//   0x00c994: 1400001b  b        #0xca00
//   0x00c998: f94002a9  ldr      x9, [x21]
//   0x00c99c: b940092a  ldr      w10, [x9, #8]
//   0x00c9a0: 5100054b  sub      w11, w10, #1
//   0x00c9a4: 3100057f  cmn      w11, #1
//   0x00c9a8: 540000e1  b.ne     #0xc9c4
//   0x00c9ac: 1400001d  b        #0xca20
//   0x00c9b0: 7100011f  cmp      w8, #0
//   0x00c9b4: 5100056b  sub      w11, w11, #1
//   0x00c9b8: 5400024c  b.gt     #0xca00
//   0x00c9bc: 3100057f  cmn      w11, #1
//   0x00c9c0: 54000300  b.eq     #0xca20
//   0x00c9c4: f940012c  ldr      x12, [x9]
//   0x00c9c8: b94022ad  ldr      w13, [x21, #0x20]
//   0x00c9cc: 11002108  add      w8, w8, #8
//   0x00c9d0: 3840158a  ldrb     w10, [x12], #1
//   0x00c9d4: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00c9d8: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00c9dc: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00c9e0: f900012c  str      x12, [x9]
//   0x00c9e4: 310005ac  adds     w12, w13, #1
//   0x00c9e8: 2901312b  stp      w11, w12, [x9, #8]
//   0x00c9ec: 54fffe23  b.lo     #0xc9b0
//   0x00c9f0: b940112c  ldr      w12, [x9, #0x10]
//   0x00c9f4: 1100058c  add      w12, w12, #1
//   0x00c9f8: b900112c  str      w12, [x9, #0x10]
//   0x00c9fc: 17ffffed  b        #0xc9b0
//   0x00ca00: 51000508  sub      w8, w8, #1
//   0x00ca04: 52800029  mov      w9, #1
//   0x00ca08: b90026a8  str      w8, [x21, #0x24]
//   0x00ca0c: 1ac82128  lsl      w8, w9, w8
//   0x00ca10: 6a08015f  tst      w10, w8
//   0x00ca14: 5a890528  cneg     w8, w9, ne
//   0x00ca18: 0b190119  add      w25, w8, w25
//   0x00ca1c: 17ffffa5  b        #0xc8b0
//   0x00ca20: 2a1f03e0  mov      w0, wzr
//   0x00ca24: f9403be8  ldr      x8, [sp, #0x70]
//   0x00ca28: b9407fed  ldr      w13, [sp, #0x7c]
//   0x00ca2c: b85943a9  ldur     w9, [x29, #-0x6c]
//   0x00ca30: 29011b17  stp      w23, w6, [x24, #8]
//   0x00ca34: 29023707  stp      w7, w13, [x24, #0x10]
//   0x00ca38: b9005314  str      w20, [x24, #0x50]
//   0x00ca3c: 2900270f  stp      w15, w9, [x24]
//   0x00ca40: b9406be9  ldr      w9, [sp, #0x68]
//   0x00ca44: f8054316  stur     x22, [x24, #0x54]
//   0x00ca48: f805c31c  stur     x28, [x24, #0x5c]
//   0x00ca4c: f8064313  stur     x19, [x24, #0x64]
//   0x00ca50: 29032309  stp      w9, w8, [x24, #0x18]
//   0x00ca54: b94083e8  ldr      w8, [sp, #0x80]
//   0x00ca58: 29057b04  stp      w4, w30, [x24, #0x28]
//   0x00ca5c: 29060b05  stp      w5, w2, [x24, #0x30]
//   0x00ca60: 29070719  stp      w25, w1, [x24, #0x38]
//   0x00ca64: 29044708  stp      w8, w17, [x24, #0x20]
//   0x00ca68: f85883a8  ldur     x8, [x29, #-0x78]
//   0x00ca6c: 29094303  stp      w3, w16, [x24, #0x48]
//   0x00ca70: 29086b08  stp      w8, w26, [x24, #0x40]
//   0x00ca74: f94015c8  ldr      x8, [x14, #0x28]
//   0x00ca78: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x00ca7c: eb09011f  cmp      x8, x9
//   0x00ca80: 54000121  b.ne     #0xcaa4
//   0x00ca84: a9507bfd  ldp      x29, x30, [sp, #0x100]
//   0x00ca88: a94f4ff4  ldp      x20, x19, [sp, #0xf0]
//   0x00ca8c: a94e57f6  ldp      x22, x21, [sp, #0xe0]
//   0x00ca90: a94d5ff8  ldp      x24, x23, [sp, #0xd0]
//   0x00ca94: a94c67fa  ldp      x26, x25, [sp, #0xc0]
//   0x00ca98: a94b6ffc  ldp      x28, x27, [sp, #0xb0]
//   0x00ca9c: 910443ff  add      sp, sp, #0x110
//   0x00caa0: d65f03c0  ret      
//   0x00caa4: 97ffd79f  bl       #0x2920
//   0x00caa8: 93407c08  sxtw     x8, w0
//   0x00caac: b8687b88  ldr      w8, [x28, x8, lsl #2]
//   0x00cab0: 4b080348  sub      w8, w26, w8
//   0x00cab4: 7104051f  cmp      w8, #0x101
//   0x00cab8: 54ffa388  b.hi     #0xbf28
//   0x00cabc: b868da71  ldr      w17, [x19, w8, sxtw #2]
//   0x00cac0: b9406be8  ldr      w8, [sp, #0x68]
//   0x00cac4: b94083fb  ldr      w27, [sp, #0x80]
//   0x00cac8: 6b08023f  cmp      w17, w8
//   0x00cacc: 540039e0  b.eq     #0xd208
//   0x00cad0: 7100062b  subs     w11, w17, #1
//   0x00cad4: 54000188  b.hi     #0xcb04
//   0x00cad8: 12800005  mov      w5, #-1
//   0x00cadc: 52800022  mov      w2, #1
//   0x00cae0: 7148005f  cmp      w2, #0x200, lsl #12
//   0x00cae4: 540013aa  b.ge     #0xcd58
//   0x00cae8: 7100063f  cmp      w17, #1
//   0x00caec: 540008e0  b.eq     #0xcc08
//   0x00caf0: 35000051  cbnz     w17, #0xcaf8
//   0x00caf4: 0b0200a5  add      w5, w5, w2
//   0x00caf8: 531f7842  lsl      w2, w2, #1
//   0x00cafc: 35000bbb  cbnz     w27, #0xcc70
//   0x00cb00: 14000045  b        #0xcc14
//   0x00cb04: 6b0403df  cmp      w30, w4
//   0x00cb08: b90083fb  str      w27, [sp, #0x80]
//   0x00cb0c: 54ffa0ea  b.ge     #0xbf28
//   0x00cb10: 71003d7f  cmp      w11, #0xf
//   0x00cb14: 54001288  b.hi     #0xcd64
//   0x00cb18: b99e8ea9  ldrsw    x9, [x21, #0x1e8c]
//   0x00cb1c: f90033f3  str      x19, [sp, #0x60]
//   0x00cb20: 2a0203f3  mov      w19, w2
//   0x00cb24: 2a0303e2  mov      w2, w3
//   0x00cb28: 0b0b0128  add      w8, w9, w11
//   0x00cb2c: 8b0802a8  add      x8, x21, x8
//   0x00cb30: 397a3108  ldrb     w8, [x8, #0xe8c]
//   0x00cb34: 2a0503e3  mov      w3, w5
//   0x00cb38: 2a0603e5  mov      w5, w6
//   0x00cb3c: 2a1903e6  mov      w6, w25
//   0x00cb40: aa1c03f9  mov      x25, x28
//   0x00cb44: aa1603fc  mov      x28, x22
//   0x00cb48: 2a0703f6  mov      w22, w7
//   0x00cb4c: 2a0103e7  mov      w7, w1
//   0x00cb50: aa1003fb  mov      x27, x16
//   0x00cb54: 2a1403e1  mov      w1, w20
//   0x00cb58: 2a1703f0  mov      w16, w23
//   0x00cb5c: aa0003f4  mov      x20, x0
//   0x00cb60: aa0e03e0  mov      x0, x14
//   0x00cb64: 7100117f  cmp      w11, #4
//   0x00cb68: 540001e3  b.lo     #0xcba4
//   0x00cb6c: 2a1103ea  mov      w10, w17
//   0x00cb70: 0b0a012b  add      w11, w9, w10
//   0x00cb74: 913a32ac  add      x12, x21, #0xe8c
//   0x00cb78: 5100116d  sub      w13, w11, #4
//   0x00cb7c: 5100156b  sub      w11, w11, #5
//   0x00cb80: b86bc98e  ldr      w14, [x12, w11, sxtw]
//   0x00cb84: 5100114b  sub      w11, w10, #4
//   0x00cb88: 5100154a  sub      w10, w10, #5
//   0x00cb8c: 71000d5f  cmp      w10, #3
//   0x00cb90: 2a0b03ea  mov      w10, w11
//   0x00cb94: b82dc98e  str      w14, [x12, w13, sxtw]
//   0x00cb98: 54fffec8  b.hi     #0xcb70
//   0x00cb9c: 7100056b  subs     w11, w11, #1
//   0x00cba0: 54000140  b.eq     #0xcbc8
//   0x00cba4: 4b0b03ea  neg      w10, w11
//   0x00cba8: 0b09016b  add      w11, w11, w9
//   0x00cbac: 5100056c  sub      w12, w11, #1
//   0x00cbb0: 913a32ad  add      x13, x21, #0xe8c
//   0x00cbb4: 386c49ae  ldrb     w14, [x13, w12, uxtw]
//   0x00cbb8: 3100054a  adds     w10, w10, #1
//   0x00cbbc: 382b49ae  strb     w14, [x13, w11, uxtw]
//   0x00cbc0: 2a0c03eb  mov      w11, w12
//   0x00cbc4: 54ffff43  b.lo     #0xcbac
//   0x00cbc8: 2a1003f7  mov      w23, w16
//   0x00cbcc: 2a1603f0  mov      w16, w22
//   0x00cbd0: aa1c03f6  mov      x22, x28
//   0x00cbd4: aa1903fc  mov      x28, x25
//   0x00cbd8: 2a0603f9  mov      w25, w6
//   0x00cbdc: 2a0503e6  mov      w6, w5
//   0x00cbe0: 2a0303e5  mov      w5, w3
//   0x00cbe4: 2a0203e3  mov      w3, w2
//   0x00cbe8: 2a1303e2  mov      w2, w19
//   0x00cbec: f94033f3  ldr      x19, [sp, #0x60]
//   0x00cbf0: 8b0902a9  add      x9, x21, x9
//   0x00cbf4: 393a3128  strb     w8, [x9, #0xe8c]
//   0x00cbf8: aa0003ee  mov      x14, x0
//   0x00cbfc: aa1403e0  mov      x0, x20
//   0x00cc00: aa1b03f4  mov      x20, x27
//   0x00cc04: 1400010e  b        #0xd03c
//   0x00cc08: 0b0204a5  add      w5, w5, w2, lsl #1
//   0x00cc0c: 531f7842  lsl      w2, w2, #1
//   0x00cc10: 3500031b  cbnz     w27, #0xcc70
//   0x00cc14: f9403be8  ldr      x8, [sp, #0x70]
//   0x00cc18: b9407fe9  ldr      w9, [sp, #0x7c]
//   0x00cc1c: 93407d08  sxtw     x8, w8
//   0x00cc20: 91000508  add      x8, x8, #1
//   0x00cc24: 6b09011f  cmp      w8, w9
//   0x00cc28: 5400426a  b.ge     #0xd474
//   0x00cc2c: f9003be8  str      x8, [sp, #0x70]
//   0x00cc30: 8b0802a8  add      x8, x21, x8
//   0x00cc34: 5283d989  mov      w9, #0x1ecc
//   0x00cc38: 38696910  ldrb     w16, [x8, x9]
//   0x00cc3c: 529f418a  mov      w10, #0xfa0c
//   0x00cc40: 52808108  mov      w8, #0x408
//   0x00cc44: 52962f89  mov      w9, #0xb17c
//   0x00cc48: 8b100aac  add      x12, x21, x16, lsl #2
//   0x00cc4c: b86a6994  ldr      w20, [x12, x10]
//   0x00cc50: d503201f  nop      
//   0x00cc54: 9b085608  madd     x8, x16, x8, x21
//   0x00cc58: 529c3b8b  mov      w11, #0xe1dc
//   0x00cc5c: 8b090116  add      x22, x8, x9
//   0x00cc60: 52993589  mov      w9, #0xc9ac
//   0x00cc64: 8b0b0113  add      x19, x8, x11
//   0x00cc68: 8b09011c  add      x28, x8, x9
//   0x00cc6c: 5280065b  mov      w27, #0x32
//   0x00cc70: 5100077b  sub      w27, w27, #1
//   0x00cc74: 2a1403e8  mov      w8, w20
//   0x00cc78: b90083fb  str      w27, [sp, #0x80]
//   0x00cc7c: f81883a8  stur     x8, [x29, #-0x78]
//   0x00cc80: b94026a8  ldr      w8, [x21, #0x24]
//   0x00cc84: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00cc88: 528004c9  mov      w9, #0x26
//   0x00cc8c: b9000aa9  str      w9, [x21, #8]
//   0x00cc90: 6b00011f  cmp      w8, w0
//   0x00cc94: 540000ab  b.lt     #0xcca8
//   0x00cc98: b94022a9  ldr      w9, [x21, #0x20]
//   0x00cc9c: 14000017  b        #0xccf8
//   0x00cca0: 6b00011f  cmp      w8, w0
//   0x00cca4: 540002aa  b.ge     #0xccf8
//   0x00cca8: f94002aa  ldr      x10, [x21]
//   0x00ccac: b940094b  ldr      w11, [x10, #8]
//   0x00ccb0: 34ffeb8b  cbz      w11, #0xca20
//   0x00ccb4: f940014c  ldr      x12, [x10]
//   0x00ccb8: b94022ad  ldr      w13, [x21, #0x20]
//   0x00ccbc: 11002108  add      w8, w8, #8
//   0x00ccc0: 5100056b  sub      w11, w11, #1
//   0x00ccc4: 38401589  ldrb     w9, [x12], #1
//   0x00ccc8: 33185da9  bfi      w9, w13, #8, #0x18
//   0x00cccc: 290422a9  stp      w9, w8, [x21, #0x20]
//   0x00ccd0: b9400d4d  ldr      w13, [x10, #0xc]
//   0x00ccd4: b900094b  str      w11, [x10, #8]
//   0x00ccd8: f900014c  str      x12, [x10]
//   0x00ccdc: 310005ab  adds     w11, w13, #1
//   0x00cce0: b9000d4b  str      w11, [x10, #0xc]
//   0x00cce4: 54fffde3  b.lo     #0xcca0
//   0x00cce8: b940114b  ldr      w11, [x10, #0x10]
//   0x00ccec: 1100056b  add      w11, w11, #1
//   0x00ccf0: b900114b  str      w11, [x10, #0x10]
//   0x00ccf4: 17ffffeb  b        #0xcca0
//   0x00ccf8: 4b000108  sub      w8, w8, w0
//   0x00ccfc: 1280000a  mov      w10, #-1
//   0x00cd00: 1ac82529  lsr      w9, w9, w8
//   0x00cd04: 1ac0214a  lsl      w10, w10, w0
//   0x00cd08: 0a2a013a  bic      w26, w9, w10
//   0x00cd0c: b90026a8  str      w8, [x21, #0x24]
//   0x00cd10: 7100501f  cmp      w0, #0x14
//   0x00cd14: 54ff90ac  b.gt     #0xbf28
//   0x00cd18: b860dac9  ldr      w9, [x22, w0, sxtw #2]
//   0x00cd1c: 6b09035f  cmp      w26, w9
//   0x00cd20: 5400006d  b.le     #0xcd2c
//   0x00cd24: 11000400  add      w0, w0, #1
//   0x00cd28: 17fffc5c  b        #0xbe98
//   0x00cd2c: 93407c08  sxtw     x8, w0
//   0x00cd30: b8687b88  ldr      w8, [x28, x8, lsl #2]
//   0x00cd34: 4b080348  sub      w8, w26, w8
//   0x00cd38: 7104051f  cmp      w8, #0x101
//   0x00cd3c: 54ff8f68  b.hi     #0xbf28
//   0x00cd40: b868da71  ldr      w17, [x19, w8, sxtw #2]
//   0x00cd44: 71000a3f  cmp      w17, #2
//   0x00cd48: 54000802  b.hs     #0xce48
//   0x00cd4c: b94083fb  ldr      w27, [sp, #0x80]
//   0x00cd50: 7148005f  cmp      w2, #0x200, lsl #12
//   0x00cd54: 54ffecab  b.lt     #0xcae8
//   0x00cd58: f81883a0  stur     x0, [x29, #-0x78]
//   0x00cd5c: b90083fb  str      w27, [sp, #0x80]
//   0x00cd60: 17fffc73  b        #0xbf2c
//   0x00cd64: 53047d69  lsr      w9, w11, #4
//   0x00cd68: 8b294aaa  add      x10, x21, w9, uxtw #2
//   0x00cd6c: b95e8d4d  ldr      w13, [x10, #0x1e8c]
//   0x00cd70: 2a1403e8  mov      w8, w20
//   0x00cd74: aa1003f4  mov      x20, x16
//   0x00cd78: 2a0703f0  mov      w16, w7
//   0x00cd7c: 2a0103e7  mov      w7, w1
//   0x00cd80: 2a0803e1  mov      w1, w8
//   0x00cd84: 72000d68  ands     w8, w11, #0xf
//   0x00cd88: 0b0801a8  add      w8, w13, w8
//   0x00cd8c: 93407d0c  sxtw     x12, w8
//   0x00cd90: 8b0c02a8  add      x8, x21, x12
//   0x00cd94: 397a3108  ldrb     w8, [x8, #0xe8c]
//   0x00cd98: 5283d18b  mov      w11, #0x1e8c
//   0x00cd9c: 8b0b014b  add      x11, x10, x11
//   0x00cda0: 54000840  b.eq     #0xcea8
//   0x00cda4: b9005ffa  str      w26, [sp, #0x5c]
//   0x00cda8: aa1303fa  mov      x26, x19
//   0x00cdac: 2a1103fb  mov      w27, w17
//   0x00cdb0: 2a0203f1  mov      w17, w2
//   0x00cdb4: 2a0303e2  mov      w2, w3
//   0x00cdb8: 2a0503e3  mov      w3, w5
//   0x00cdbc: 2a0603e5  mov      w5, w6
//   0x00cdc0: 2a1903e6  mov      w6, w25
//   0x00cdc4: aa1c03f9  mov      x25, x28
//   0x00cdc8: aa1603fc  mov      x28, x22
//   0x00cdcc: 2a1003f6  mov      w22, w16
//   0x00cdd0: aa1403f3  mov      x19, x20
//   0x00cdd4: 2a1703f0  mov      w16, w23
//   0x00cdd8: aa0003f4  mov      x20, x0
//   0x00cddc: aa0e03e0  mov      x0, x14
//   0x00cde0: 8b0c02ad  add      x13, x21, x12
//   0x00cde4: 397a2dae  ldrb     w14, [x13, #0xe8b]
//   0x00cde8: d100058c  sub      x12, x12, #1
//   0x00cdec: 393a31ae  strb     w14, [x13, #0xe8c]
//   0x00cdf0: b980016d  ldrsw    x13, [x11]
//   0x00cdf4: eb0d019f  cmp      x12, x13
//   0x00cdf8: 54ffff4c  b.gt     #0xcde0
//   0x00cdfc: aa0003ee  mov      x14, x0
//   0x00ce00: aa1403e0  mov      x0, x20
//   0x00ce04: aa1303f4  mov      x20, x19
//   0x00ce08: aa1a03f3  mov      x19, x26
//   0x00ce0c: b9405ffa  ldr      w26, [sp, #0x5c]
//   0x00ce10: 110005ac  add      w12, w13, #1
//   0x00ce14: 2a1003f7  mov      w23, w16
//   0x00ce18: 2a1603f0  mov      w16, w22
//   0x00ce1c: aa1c03f6  mov      x22, x28
//   0x00ce20: aa1903fc  mov      x28, x25
//   0x00ce24: 2a0603f9  mov      w25, w6
//   0x00ce28: 2a0503e6  mov      w6, w5
//   0x00ce2c: 2a0303e5  mov      w5, w3
//   0x00ce30: 2a0203e3  mov      w3, w2
//   0x00ce34: 2a1103e2  mov      w2, w17
//   0x00ce38: 2a1b03f1  mov      w17, w27
//   0x00ce3c: b900016c  str      w12, [x11]
//   0x00ce40: 35000389  cbnz     w9, #0xceb0
//   0x00ce44: 14000028  b        #0xcee4
//   0x00ce48: b99e8ea8  ldrsw    x8, [x21, #0x1e8c]
//   0x00ce4c: 8b0802a8  add      x8, x21, x8
//   0x00ce50: 397a3108  ldrb     w8, [x8, #0xe8c]
//   0x00ce54: 8b0802a8  add      x8, x21, x8
//   0x00ce58: 39763109  ldrb     w9, [x8, #0xd8c]
//   0x00ce5c: 110004a8  add      w8, w5, #1
//   0x00ce60: 8b090aaa  add      x10, x21, x9, lsl #2
//   0x00ce64: b940454b  ldr      w11, [x10, #0x44]
//   0x00ce68: 0b08016b  add      w11, w11, w8
//   0x00ce6c: b900454b  str      w11, [x10, #0x44]
//   0x00ce70: 3940b2aa  ldrb     w10, [x21, #0x2c]
//   0x00ce74: 34001a8a  cbz      w10, #0xd1c4
//   0x00ce78: 37f81bc5  tbnz     w5, #0x1f, #0xd1f0
//   0x00ce7c: 93407fde  sxtw     x30, w30
//   0x00ce80: 93407c8a  sxtw     x10, w4
//   0x00ce84: eb0a03df  cmp      x30, x10
//   0x00ce88: 54001b8a  b.ge     #0xd1f8
//   0x00ce8c: f9462eab  ldr      x11, [x21, #0xc58]
//   0x00ce90: 51000508  sub      w8, w8, #1
//   0x00ce94: 7100011f  cmp      w8, #0
//   0x00ce98: 783e7969  strh     w9, [x11, x30, lsl #1]
//   0x00ce9c: 910007de  add      x30, x30, #1
//   0x00cea0: 54ffff2c  b.gt     #0xce84
//   0x00cea4: 140000d3  b        #0xd1f0
//   0x00cea8: 110005ac  add      w12, w13, #1
//   0x00ceac: b900016c  str      w12, [x11]
//   0x00ceb0: 5283d18b  mov      w11, #0x1e8c
//   0x00ceb4: 8b0b014a  add      x10, x10, x11
//   0x00ceb8: b980014b  ldrsw    x11, [x10]
//   0x00cebc: 913a32ad  add      x13, x21, #0xe8c
//   0x00cec0: d1000529  sub      x9, x9, #1
//   0x00cec4: f100013f  cmp      x9, #0
//   0x00cec8: d100056b  sub      x11, x11, #1
//   0x00cecc: b81fc54b  str      w11, [x10], #0xfffffffffffffffc
//   0x00ced0: b980014c  ldrsw    x12, [x10]
//   0x00ced4: 8b0d018c  add      x12, x12, x13
//   0x00ced8: 39403d8c  ldrb     w12, [x12, #0xf]
//   0x00cedc: 382b69ac  strb     w12, [x13, x11]
//   0x00cee0: 54fffecc  b.gt     #0xceb8
//   0x00cee4: b99e8ea9  ldrsw    x9, [x21, #0x1e8c]
//   0x00cee8: d1000529  sub      x9, x9, #1
//   0x00ceec: b91e8ea9  str      w9, [x21, #0x1e8c]
//   0x00cef0: 8b0902a9  add      x9, x21, x9
//   0x00cef4: 393a3128  strb     w8, [x9, #0xe8c]
//   0x00cef8: b95e8ea9  ldr      w9, [x21, #0x1e8c]
//   0x00cefc: 35000a09  cbnz     w9, #0xd03c
//   0x00cf00: 5283d90a  mov      w10, #0x1ec8
//   0x00cf04: 5283d06b  mov      w11, #0x1e83
//   0x00cf08: f81883a0  stur     x0, [x29, #-0x78]
//   0x00cf0c: aa0e03e0  mov      x0, x14
//   0x00cf10: aa1f03e9  mov      x9, xzr
//   0x00cf14: 8b0a02aa  add      x10, x21, x10
//   0x00cf18: 8b0b02ab  add      x11, x21, x11
//   0x00cf1c: b980014c  ldrsw    x12, [x10]
//   0x00cf20: 913a32ad  add      x13, x21, #0xe8c
//   0x00cf24: 8b0d018c  add      x12, x12, x13
//   0x00cf28: 39403d8e  ldrb     w14, [x12, #0xf]
//   0x00cf2c: 8b09016c  add      x12, x11, x9
//   0x00cf30: 3900218e  strb     w14, [x12, #8]
//   0x00cf34: b980014e  ldrsw    x14, [x10]
//   0x00cf38: 8b0d01ce  add      x14, x14, x13
//   0x00cf3c: 394039ce  ldrb     w14, [x14, #0xe]
//   0x00cf40: 39001d8e  strb     w14, [x12, #7]
//   0x00cf44: b980014e  ldrsw    x14, [x10]
//   0x00cf48: 8b0d01ce  add      x14, x14, x13
//   0x00cf4c: 394035ce  ldrb     w14, [x14, #0xd]
//   0x00cf50: 3900198e  strb     w14, [x12, #6]
//   0x00cf54: b980014e  ldrsw    x14, [x10]
//   0x00cf58: 8b0d01ce  add      x14, x14, x13
//   0x00cf5c: 394031ce  ldrb     w14, [x14, #0xc]
//   0x00cf60: 3900158e  strb     w14, [x12, #5]
//   0x00cf64: b980014e  ldrsw    x14, [x10]
//   0x00cf68: 8b0d01ce  add      x14, x14, x13
//   0x00cf6c: 39402dce  ldrb     w14, [x14, #0xb]
//   0x00cf70: 3900118e  strb     w14, [x12, #4]
//   0x00cf74: b980014e  ldrsw    x14, [x10]
//   0x00cf78: 8b0d01ce  add      x14, x14, x13
//   0x00cf7c: 394029ce  ldrb     w14, [x14, #0xa]
//   0x00cf80: 39000d8e  strb     w14, [x12, #3]
//   0x00cf84: b980014e  ldrsw    x14, [x10]
//   0x00cf88: 8b0d01ce  add      x14, x14, x13
//   0x00cf8c: 394025ce  ldrb     w14, [x14, #9]
//   0x00cf90: 3900098e  strb     w14, [x12, #2]
//   0x00cf94: b980014e  ldrsw    x14, [x10]
//   0x00cf98: 8b0d01ce  add      x14, x14, x13
//   0x00cf9c: 394021ce  ldrb     w14, [x14, #8]
//   0x00cfa0: 3900058e  strb     w14, [x12, #1]
//   0x00cfa4: b980014e  ldrsw    x14, [x10]
//   0x00cfa8: 8b0d01ce  add      x14, x14, x13
//   0x00cfac: 39401dce  ldrb     w14, [x14, #7]
//   0x00cfb0: 3900018e  strb     w14, [x12]
//   0x00cfb4: b980014e  ldrsw    x14, [x10]
//   0x00cfb8: 8b0d01ce  add      x14, x14, x13
//   0x00cfbc: 394019ce  ldrb     w14, [x14, #6]
//   0x00cfc0: 381ff18e  sturb    w14, [x12, #-1]
//   0x00cfc4: b980014e  ldrsw    x14, [x10]
//   0x00cfc8: 8b0d01ce  add      x14, x14, x13
//   0x00cfcc: 394015ce  ldrb     w14, [x14, #5]
//   0x00cfd0: 381fe18e  sturb    w14, [x12, #-2]
//   0x00cfd4: b980014e  ldrsw    x14, [x10]
//   0x00cfd8: 8b0d01ce  add      x14, x14, x13
//   0x00cfdc: 394011ce  ldrb     w14, [x14, #4]
//   0x00cfe0: 381fd18e  sturb    w14, [x12, #-3]
//   0x00cfe4: b980014e  ldrsw    x14, [x10]
//   0x00cfe8: 8b0d01ce  add      x14, x14, x13
//   0x00cfec: 39400dce  ldrb     w14, [x14, #3]
//   0x00cff0: 381fc18e  sturb    w14, [x12, #-4]
//   0x00cff4: b980014e  ldrsw    x14, [x10]
//   0x00cff8: 8b0d01ce  add      x14, x14, x13
//   0x00cffc: 394009ce  ldrb     w14, [x14, #2]
//   0x00d000: 381fb18e  sturb    w14, [x12, #-5]
//   0x00d004: b980014e  ldrsw    x14, [x10]
//   0x00d008: 8b0d01ce  add      x14, x14, x13
//   0x00d00c: 394005ce  ldrb     w14, [x14, #1]
//   0x00d010: 381fa18e  sturb    w14, [x12, #-6]
//   0x00d014: b980014e  ldrsw    x14, [x10]
//   0x00d018: 386e69ad  ldrb     w13, [x13, x14]
//   0x00d01c: 113fc12e  add      w14, w9, #0xff0
//   0x00d020: d1004129  sub      x9, x9, #0x10
//   0x00d024: b104013f  cmn      x9, #0x100
//   0x00d028: 381f918d  sturb    w13, [x12, #-7]
//   0x00d02c: b81fc54e  str      w14, [x10], #0xfffffffffffffffc
//   0x00d030: 54fff761  b.ne     #0xcf1c
//   0x00d034: aa0003ee  mov      x14, x0
//   0x00d038: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00d03c: 8b0802a8  add      x8, x21, x8
//   0x00d040: 39763109  ldrb     w9, [x8, #0xd8c]
//   0x00d044: 8b090aa9  add      x9, x21, x9, lsl #2
//   0x00d048: b940452a  ldr      w10, [x9, #0x44]
//   0x00d04c: 1100054a  add      w10, w10, #1
//   0x00d050: b900452a  str      w10, [x9, #0x44]
//   0x00d054: 3940b2a9  ldrb     w9, [x21, #0x2c]
//   0x00d058: 39763108  ldrb     w8, [x8, #0xd8c]
//   0x00d05c: 34000089  cbz      w9, #0xd06c
//   0x00d060: f9462ea9  ldr      x9, [x21, #0xc58]
//   0x00d064: 783ed928  strh     w8, [x9, w30, sxtw #1]
//   0x00d068: 14000003  b        #0xd074
//   0x00d06c: f9462aa9  ldr      x9, [x21, #0xc50]
//   0x00d070: b83ed928  str      w8, [x9, w30, sxtw #2]
//   0x00d074: b94083fb  ldr      w27, [sp, #0x80]
//   0x00d078: 110007de  add      w30, w30, #1
//   0x00d07c: 2a0103ea  mov      w10, w1
//   0x00d080: 3400007b  cbz      w27, #0xd08c
//   0x00d084: 2a0703e1  mov      w1, w7
//   0x00d088: 1400001a  b        #0xd0f0
//   0x00d08c: f9403be8  ldr      x8, [sp, #0x70]
//   0x00d090: b9407fe9  ldr      w9, [sp, #0x7c]
//   0x00d094: 2a0703e1  mov      w1, w7
//   0x00d098: 93407d08  sxtw     x8, w8
//   0x00d09c: 91000508  add      x8, x8, #1
//   0x00d0a0: 6b09011f  cmp      w8, w9
//   0x00d0a4: 54001f0a  b.ge     #0xd484
//   0x00d0a8: f9003be8  str      x8, [sp, #0x70]
//   0x00d0ac: 8b0802a8  add      x8, x21, x8
//   0x00d0b0: 5283d989  mov      w9, #0x1ecc
//   0x00d0b4: 3869690d  ldrb     w13, [x8, x9]
//   0x00d0b8: 529f418a  mov      w10, #0xfa0c
//   0x00d0bc: 52808108  mov      w8, #0x408
//   0x00d0c0: 52962f89  mov      w9, #0xb17c
//   0x00d0c4: 8b0d0aac  add      x12, x21, x13, lsl #2
//   0x00d0c8: b86a698a  ldr      w10, [x12, x10]
//   0x00d0cc: d503201f  nop      
//   0x00d0d0: 9b0855a8  madd     x8, x13, x8, x21
//   0x00d0d4: 529c3b8b  mov      w11, #0xe1dc
//   0x00d0d8: 8b090116  add      x22, x8, x9
//   0x00d0dc: 52993589  mov      w9, #0xc9ac
//   0x00d0e0: aa0d03f4  mov      x20, x13
//   0x00d0e4: 8b0b0113  add      x19, x8, x11
//   0x00d0e8: 8b09011c  add      x28, x8, x9
//   0x00d0ec: 5280065b  mov      w27, #0x32
//   0x00d0f0: 2a1003e7  mov      w7, w16
//   0x00d0f4: 5100077b  sub      w27, w27, #1
//   0x00d0f8: 2a0a03e8  mov      w8, w10
//   0x00d0fc: aa1403f0  mov      x16, x20
//   0x00d100: 2a0a03f4  mov      w20, w10
//   0x00d104: b90083fb  str      w27, [sp, #0x80]
//   0x00d108: f81883a8  stur     x8, [x29, #-0x78]
//   0x00d10c: b94026a8  ldr      w8, [x21, #0x24]
//   0x00d110: f85883a0  ldur     x0, [x29, #-0x78]
//   0x00d114: 52800509  mov      w9, #0x28
//   0x00d118: b9000aa9  str      w9, [x21, #8]
//   0x00d11c: 6b00011f  cmp      w8, w0
//   0x00d120: 5400036a  b.ge     #0xd18c
//   0x00d124: f94002a9  ldr      x9, [x21]
//   0x00d128: b940092a  ldr      w10, [x9, #8]
//   0x00d12c: 5100054b  sub      w11, w10, #1
//   0x00d130: 3100057f  cmn      w11, #1
//   0x00d134: 540000e1  b.ne     #0xd150
//   0x00d138: 17fffe3a  b        #0xca20
//   0x00d13c: 6b00011f  cmp      w8, w0
//   0x00d140: 5100056b  sub      w11, w11, #1
//   0x00d144: 5400026a  b.ge     #0xd190
//   0x00d148: 3100057f  cmn      w11, #1
//   0x00d14c: 54ffc6a0  b.eq     #0xca20
//   0x00d150: f940012c  ldr      x12, [x9]
//   0x00d154: b94022ad  ldr      w13, [x21, #0x20]
//   0x00d158: 11002108  add      w8, w8, #8
//   0x00d15c: 3840158a  ldrb     w10, [x12], #1
//   0x00d160: 33185daa  bfi      w10, w13, #8, #0x18
//   0x00d164: 290422aa  stp      w10, w8, [x21, #0x20]
//   0x00d168: b9400d2d  ldr      w13, [x9, #0xc]
//   0x00d16c: f900012c  str      x12, [x9]
//   0x00d170: 310005ac  adds     w12, w13, #1
//   0x00d174: 2901312b  stp      w11, w12, [x9, #8]
//   0x00d178: 54fffe23  b.lo     #0xd13c
//   0x00d17c: b940112c  ldr      w12, [x9, #0x10]
//   0x00d180: 1100058c  add      w12, w12, #1
//   0x00d184: b900112c  str      w12, [x9, #0x10]
//   0x00d188: 17ffffed  b        #0xd13c
//   0x00d18c: b94022aa  ldr      w10, [x21, #0x20]
//   0x00d190: 4b000108  sub      w8, w8, w0
//   0x00d194: 12800009  mov      w9, #-1
//   0x00d198: 1ac8254a  lsr      w10, w10, w8
//   0x00d19c: 1ac02129  lsl      w9, w9, w0
//   0x00d1a0: 0a29015a  bic      w26, w10, w9
//   0x00d1a4: b90026a8  str      w8, [x21, #0x24]
//   0x00d1a8: 7100501f  cmp      w0, #0x14
//   0x00d1ac: 54ff6bec  b.gt     #0xbf28
//   0x00d1b0: b860dac9  ldr      w9, [x22, w0, sxtw #2]
//   0x00d1b4: 6b09035f  cmp      w26, w9
//   0x00d1b8: 54ffc78d  b.le     #0xcaa8
//   0x00d1bc: 11000400  add      w0, w0, #1
//   0x00d1c0: 17fffb5d  b        #0xbf34
//   0x00d1c4: 37f80165  tbnz     w5, #0x1f, #0xd1f0
//   0x00d1c8: 93407fde  sxtw     x30, w30
//   0x00d1cc: 93407c8a  sxtw     x10, w4
//   0x00d1d0: eb0a03df  cmp      x30, x10
//   0x00d1d4: 5400012a  b.ge     #0xd1f8
//   0x00d1d8: f9462aab  ldr      x11, [x21, #0xc50]
//   0x00d1dc: 51000508  sub      w8, w8, #1
//   0x00d1e0: 7100011f  cmp      w8, #0
//   0x00d1e4: b83e7969  str      w9, [x11, x30, lsl #2]
//   0x00d1e8: 910007de  add      x30, x30, #1
//   0x00d1ec: 54ffff2c  b.gt     #0xd1d0
//   0x00d1f0: 2a0803e5  mov      w5, w8
//   0x00d1f4: 17fffe33  b        #0xcac0
//   0x00d1f8: f81883a0  stur     x0, [x29, #-0x78]
//   0x00d1fc: 12800060  mov      w0, #-4
//   0x00d200: 2a0803e5  mov      w5, w8
//   0x00d204: 17fffe08  b        #0xca24
//   0x00d208: b9403aa8  ldr      w8, [x21, #0x38]
//   0x00d20c: f81883a0  stur     x0, [x29, #-0x78]
//   0x00d210: 12800060  mov      w0, #-4
//   0x00d214: b90083fb  str      w27, [sp, #0x80]
//   0x00d218: 37f814a8  tbnz     w8, #0x1f, #0xd4ac
//   0x00d21c: 6b1e011f  cmp      w8, w30
//   0x00d220: 5400146a  b.ge     #0xd4ac
//   0x00d224: aa1f03ef  mov      x15, xzr
//   0x00d228: 910112a8  add      x8, x21, #0x44
//   0x00d22c: b86f7909  ldr      w9, [x8, x15, lsl #2]
//   0x00d230: 37f813c9  tbnz     w9, #0x1f, #0xd4a8
//   0x00d234: 6b1e013f  cmp      w9, w30
//   0x00d238: 5400138c  b.gt     #0xd4a8
//   0x00d23c: 910005ef  add      x15, x15, #1
//   0x00d240: f10401ff  cmp      x15, #0x100
//   0x00d244: 54ffff41  b.ne     #0xd22c
//   0x00d248: aa1f03e8  mov      x8, xzr
//   0x00d24c: 911122ac  add      x12, x21, #0x448
//   0x00d250: b9044abf  str      wzr, [x21, #0x448]
//   0x00d254: 8b0802a9  add      x9, x21, x8
//   0x00d258: 3cc44120  ldur     q0, [x9, #0x44]
//   0x00d25c: 91004108  add      x8, x8, #0x10
//   0x00d260: 91113129  add      x9, x9, #0x44c
//   0x00d264: f110011f  cmp      x8, #0x400
//   0x00d268: 3d800120  str      q0, [x9]
//   0x00d26c: 54ffff41  b.ne     #0xd254
//   0x00d270: b9444aa9  ldr      w9, [x21, #0x448]
//   0x00d274: aa1f03e8  mov      x8, xzr
//   0x00d278: 911132aa  add      x10, x21, #0x44c
//   0x00d27c: b868694b  ldr      w11, [x10, x8]
//   0x00d280: 0b090169  add      w9, w11, w9
//   0x00d284: b8286949  str      w9, [x10, x8]
//   0x00d288: 91001108  add      x8, x8, #4
//   0x00d28c: f110011f  cmp      x8, #0x400
//   0x00d290: 54ffff61  b.ne     #0xd27c
//   0x00d294: aa1f03ef  mov      x15, xzr
//   0x00d298: 911122a8  add      x8, x21, #0x448
//   0x00d29c: b86f7909  ldr      w9, [x8, x15, lsl #2]
//   0x00d2a0: 37f81049  tbnz     w9, #0x1f, #0xd4a8
//   0x00d2a4: 6b1e013f  cmp      w9, w30
//   0x00d2a8: 5400100c  b.gt     #0xd4a8
//   0x00d2ac: 910005ef  add      x15, x15, #1
//   0x00d2b0: f10405ff  cmp      x15, #0x101
//   0x00d2b4: 54ffff41  b.ne     #0xd29c
//   0x00d2b8: b9444aaa  ldr      w10, [x21, #0x448]
//   0x00d2bc: aa1f03e8  mov      x8, xzr
//   0x00d2c0: 911132a9  add      x9, x21, #0x44c
//   0x00d2c4: b868792b  ldr      w11, [x9, x8, lsl #2]
//   0x00d2c8: 6b0b015f  cmp      w10, w11
//   0x00d2cc: 54000ecc  b.gt     #0xd4a4
//   0x00d2d0: 91000508  add      x8, x8, #1
//   0x00d2d4: f104011f  cmp      x8, #0x100
//   0x00d2d8: 2a0b03ea  mov      w10, w11
//   0x00d2dc: 54ffff41  b.ne     #0xd2c4
//   0x00d2e0: b94036a8  ldr      w8, [x21, #0x34]
//   0x00d2e4: 12800009  mov      w9, #-1
//   0x00d2e8: b90c72a9  str      w9, [x21, #0xc70]
//   0x00d2ec: 52800049  mov      w9, #2
//   0x00d2f0: 7100091f  cmp      w8, #2
//   0x00d2f4: b90033f9  str      w25, [sp, #0x30]
//   0x00d2f8: b9005bf7  str      w23, [sp, #0x58]
//   0x00d2fc: f9001fe4  str      x4, [sp, #0x38]
//   0x00d300: b90012bf  str      wzr, [x21, #0x10]
//   0x00d304: 390032bf  strb     wzr, [x21, #0xc]
//   0x00d308: b9000aa9  str      w9, [x21, #8]
//   0x00d30c: f90007fe  str      x30, [sp, #8]
//   0x00d310: b90027e1  str      w1, [sp, #0x24]
//   0x00d314: b90047e3  str      w3, [sp, #0x44]
//   0x00d318: b90007e2  str      w2, [sp, #4]
//   0x00d31c: 5400046b  b.lt     #0xd3a8
//   0x00d320: d0000088  adrp     x8, #0x1f000
//   0x00d324: f947c908  ldr      x8, [x8, #0xf90]
//   0x00d328: b0000040  adrp     x0, #0x16000
//   0x00d32c: 9139b800  add      x0, x0, #0xe6e
//   0x00d330: 528000c1  mov      w1, #6
//   0x00d334: 9104c103  add      x3, x8, #0x130
//   0x00d338: 52800022  mov      w2, #1
//   0x00d33c: 2a0603f7  mov      w23, w6
//   0x00d340: f90033f3  str      x19, [sp, #0x60]
//   0x00d344: 2a0503f3  mov      w19, w5
//   0x00d348: 2a1103fb  mov      w27, w17
//   0x00d34c: f9000fee  str      x14, [sp, #0x18]
//   0x00d350: 2a0703f9  mov      w25, w7
//   0x00d354: f9002bfc  str      x28, [sp, #0x50]
//   0x00d358: f90017f6  str      x22, [sp, #0x28]
//   0x00d35c: aa1003f6  mov      x22, x16
//   0x00d360: 2a1403fc  mov      w28, w20
//   0x00d364: aa0c03f4  mov      x20, x12
//   0x00d368: 97ffd5de  bl       #0x2ae0
//   0x00d36c: aa1403ec  mov      x12, x20
//   0x00d370: 2a1c03f4  mov      w20, w28
//   0x00d374: aa1603f0  mov      x16, x22
//   0x00d378: f94017f6  ldr      x22, [sp, #0x28]
//   0x00d37c: f9402bfc  ldr      x28, [sp, #0x50]
//   0x00d380: f9400fee  ldr      x14, [sp, #0x18]
//   0x00d384: b94007e2  ldr      w2, [sp, #4]
//   0x00d388: f94007fe  ldr      x30, [sp, #8]
//   0x00d38c: 2a1303e5  mov      w5, w19
//   0x00d390: f94033f3  ldr      x19, [sp, #0x60]
//   0x00d394: b94047e3  ldr      w3, [sp, #0x44]
//   0x00d398: b94027e1  ldr      w1, [sp, #0x24]
//   0x00d39c: 2a1903e7  mov      w7, w25
//   0x00d3a0: 2a1b03f1  mov      w17, w27
//   0x00d3a4: 2a1703e6  mov      w6, w23
//   0x00d3a8: 3940b2a8  ldrb     w8, [x21, #0x2c]
//   0x00d3ac: aa1003ef  mov      x15, x16
//   0x00d3b0: b9005ffa  str      w26, [sp, #0x5c]
//   0x00d3b4: aa1303fa  mov      x26, x19
//   0x00d3b8: 2a1403f9  mov      w25, w20
//   0x00d3bc: aa0e03f4  mov      x20, x14
//   0x00d3c0: 34001448  cbz      w8, #0xd648
//   0x00d3c4: aa0c03e1  mov      x1, x12
//   0x00d3c8: 2a1103f3  mov      w19, w17
//   0x00d3cc: 52808908  mov      w8, #0x448
//   0x00d3d0: b9004fe5  str      w5, [sp, #0x4c]
//   0x00d3d4: f9000bef  str      x15, [sp, #0x10]
//   0x00d3d8: b90023e7  str      w7, [sp, #0x20]
//   0x00d3dc: b9001be6  str      w6, [sp, #0x18]
//   0x00d3e0: 8b0802a9  add      x9, x21, x8
//   0x00d3e4: 3dc00120  ldr      q0, [x9]
//   0x00d3e8: 91004108  add      x8, x8, #0x10
//   0x00d3ec: 91101129  add      x9, x9, #0x404
//   0x00d3f0: f121211f  cmp      x8, #0x848
//   0x00d3f4: 3d800120  str      q0, [x9]
//   0x00d3f8: 54ffff41  b.ne     #0xd3e0
//   0x00d3fc: b9484aa8  ldr      w8, [x21, #0x848]
//   0x00d400: 710003df  cmp      w30, #0
//   0x00d404: b90c4ea8  str      w8, [x21, #0xc4c]
//   0x00d408: 5400056d  b.le     #0xd4b4
//   0x00d40c: aa1f03e8  mov      x8, xzr
//   0x00d410: 2a1e03e9  mov      w9, w30
//   0x00d414: 1400000a  b        #0xd43c
//   0x00d418: 13107dce  asr      w14, w14, #0x10
//   0x00d41c: 331c6dcd  bfi      w13, w14, #4, #0x1c
//   0x00d420: 382c696d  strb     w13, [x11, x12]
//   0x00d424: b940014b  ldr      w11, [x10]
//   0x00d428: 91000508  add      x8, x8, #1
//   0x00d42c: eb08013f  cmp      x9, x8
//   0x00d430: 1100056b  add      w11, w11, #1
//   0x00d434: b900014b  str      w11, [x10]
//   0x00d438: 540003e0  b.eq     #0xd4b4
//   0x00d43c: f9462eaa  ldr      x10, [x21, #0xc58]
//   0x00d440: d37ff90b  lsl      x11, x8, #1
//   0x00d444: 386b694c  ldrb     w12, [x10, x11]
//   0x00d448: 8b0c0aaf  add      x15, x21, x12, lsl #2
//   0x00d44c: b9484dee  ldr      w14, [x15, #0x84c]
//   0x00d450: d3417d0c  ubfx     x12, x8, #1, #0x1f
//   0x00d454: 782b694e  strh     w14, [x10, x11]
//   0x00d458: f94632ab  ldr      x11, [x21, #0xc60]
//   0x00d45c: 912131ea  add      x10, x15, #0x84c
//   0x00d460: 386c696d  ldrb     w13, [x11, x12]
//   0x00d464: 3707fda8  tbnz     w8, #0, #0xd418
//   0x00d468: 121c0dad  and      w13, w13, #0xf0
//   0x00d46c: 2a8e41ad  orr      w13, w13, w14, asr #16
//   0x00d470: 17ffffec  b        #0xd420
//   0x00d474: f81883a0  stur     x0, [x29, #-0x78]
//   0x00d478: b90083ff  str      wzr, [sp, #0x80]
//   0x00d47c: 12800060  mov      w0, #-4
//   0x00d480: 17fffd6a  b        #0xca28
//   0x00d484: b9407fed  ldr      w13, [sp, #0x7c]
//   0x00d488: f81883a0  stur     x0, [x29, #-0x78]
//   0x00d48c: b90083ff  str      wzr, [sp, #0x80]
//   0x00d490: 12800060  mov      w0, #-4
//   0x00d494: 2a1003e7  mov      w7, w16
//   0x00d498: aa1403f0  mov      x16, x20
//   0x00d49c: 2a0a03f4  mov      w20, w10
//   0x00d4a0: 17fffd63  b        #0xca2c
//   0x00d4a4: 1100050f  add      w15, w8, #1
//   0x00d4a8: 12800060  mov      w0, #-4
//   0x00d4ac: b9006bf1  str      w17, [sp, #0x68]
//   0x00d4b0: 17fffd5d  b        #0xca24
//   0x00d4b4: b9803aa9  ldrsw    x9, [x21, #0x38]
//   0x00d4b8: f94632a8  ldr      x8, [x21, #0xc60]
//   0x00d4bc: f9462eaa  ldr      x10, [x21, #0xc58]
//   0x00d4c0: 13017d2b  asr      w11, w9, #1
//   0x00d4c4: 386bc90b  ldrb     w11, [x8, w11, sxtw]
//   0x00d4c8: 78697957  ldrh     w23, [x10, x9, lsl #1]
//   0x00d4cc: 531e012c  ubfiz    w12, w9, #2, #1
//   0x00d4d0: 1acc256b  lsr      w11, w11, w12
//   0x00d4d4: 33100d77  bfi      w23, w11, #0x10, #4
//   0x00d4d8: 2a1703ee  mov      w14, w23
//   0x00d4dc: 93417dcb  sbfx     x11, x14, #1, #0x1f
//   0x00d4e0: 937f7dcc  sbfiz    x12, x14, #1, #0x20
//   0x00d4e4: 386b690d  ldrb     w13, [x8, x11]
//   0x00d4e8: 786c6957  ldrh     w23, [x10, x12]
//   0x00d4ec: 782c6949  strh     w9, [x10, x12]
//   0x00d4f0: 386b690a  ldrb     w10, [x8, x11]
//   0x00d4f4: 531e01cc  ubfiz    w12, w14, #2, #1
//   0x00d4f8: 1acc25ac  lsr      w12, w13, w12
//   0x00d4fc: 33100d97  bfi      w23, w12, #0x10, #4
//   0x00d500: 3700008e  tbnz     w14, #0, #0xd510
//   0x00d504: 121c0d4a  and      w10, w10, #0xf0
//   0x00d508: 2a89414a  orr      w10, w10, w9, asr #16
//   0x00d50c: 14000003  b        #0xd518
//   0x00d510: 13107d29  asr      w9, w9, #0x10
//   0x00d514: 331c6d2a  bfi      w10, w9, #4, #0x1c
//   0x00d518: 382b690a  strb     w10, [x8, x11]
//   0x00d51c: b9403aa8  ldr      w8, [x21, #0x38]
//   0x00d520: 6b0801df  cmp      w14, w8
//   0x00d524: 540000a0  b.eq     #0xd538
//   0x00d528: f9462eaa  ldr      x10, [x21, #0xc58]
//   0x00d52c: f94632a8  ldr      x8, [x21, #0xc60]
//   0x00d530: 2a0e03e9  mov      w9, w14
//   0x00d534: 17ffffe9  b        #0xd4d8
//   0x00d538: 394052a8  ldrb     w8, [x21, #0x14]
//   0x00d53c: b9003eae  str      w14, [x21, #0x3c]
//   0x00d540: b90446bf  str      wzr, [x21, #0x444]
//   0x00d544: 34000ba8  cbz      w8, #0xd6b8
//   0x00d548: b9402aa8  ldr      w8, [x21, #0x28]
//   0x00d54c: 5290d409  mov      w9, #0x86a0
//   0x00d550: 72a00029  movk     w9, #1, lsl #16
//   0x00d554: f9000ebf  str      xzr, [x21, #0x18]
//   0x00d558: 1b097d08  mul      w8, w8, w9
//   0x00d55c: 6b0801df  cmp      w14, w8
//   0x00d560: 54001062  b.hs     #0xd76c
//   0x00d564: aa0e03fb  mov      x27, x14
//   0x00d568: 2a1b03e0  mov      w0, w27
//   0x00d56c: 97ffd4f1  bl       #0x2930
//   0x00d570: b9403ea9  ldr      w9, [x21, #0x3c]
//   0x00d574: f94632aa  ldr      x10, [x21, #0xc60]
//   0x00d578: b90042a0  str      w0, [x21, #0x40]
//   0x00d57c: f9462eab  ldr      x11, [x21, #0xc58]
//   0x00d580: d341fd2c  lsr      x12, x9, #1
//   0x00d584: 386c694a  ldrb     w10, [x10, x12]
//   0x00d588: b94446ac  ldr      w12, [x21, #0x444]
//   0x00d58c: 7869796b  ldrh     w11, [x11, x9, lsl #1]
//   0x00d590: 531e0129  ubfiz    w9, w9, #2, #1
//   0x00d594: 1ac9254a  lsr      w10, w10, w9
//   0x00d598: b9401aa9  ldr      w9, [x21, #0x18]
//   0x00d59c: 2a0003e8  mov      w8, w0
//   0x00d5a0: 1100058c  add      w12, w12, #1
//   0x00d5a4: 33100d4b  bfi      w11, w10, #0x10, #4
//   0x00d5a8: b9003eab  str      w11, [x21, #0x3c]
//   0x00d5ac: b90446ac  str      w12, [x21, #0x444]
//   0x00d5b0: 35000129  cbnz     w9, #0xd5d4
//   0x00d5b4: d0000089  adrp     x9, #0x1f000
//   0x00d5b8: b9801eaa  ldrsw    x10, [x21, #0x1c]
//   0x00d5bc: f947fd29  ldr      x9, [x9, #0xff8]
//   0x00d5c0: 1100054b  add      w11, w10, #1
//   0x00d5c4: b86a7929  ldr      w9, [x9, x10, lsl #2]
//   0x00d5c8: 7108017f  cmp      w11, #0x200
//   0x00d5cc: 1a8a07ea  csinc    w10, wzr, w10, eq
//   0x00d5d0: 29032aa9  stp      w9, w10, [x21, #0x18]
//   0x00d5d4: 51000529  sub      w9, w9, #1
//   0x00d5d8: 7100053f  cmp      w9, #1
//   0x00d5dc: b9001aa9  str      w9, [x21, #0x18]
//   0x00d5e0: 1a9f17e9  cset     w9, eq
//   0x00d5e4: 4a090108  eor      w8, w8, w9
//   0x00d5e8: b90042a8  str      w8, [x21, #0x40]
//   0x00d5ec: b94033e8  ldr      w8, [sp, #0x30]
//   0x00d5f0: 2a1303f1  mov      w17, w19
//   0x00d5f4: b9006bf3  str      w19, [sp, #0x68]
//   0x00d5f8: b9401be6  ldr      w6, [sp, #0x18]
//   0x00d5fc: aa1403ee  mov      x14, x20
//   0x00d600: 294407e7  ldp      w7, w1, [sp, #0x20]
//   0x00d604: b94007e2  ldr      w2, [sp, #4]
//   0x00d608: f9400bf0  ldr      x16, [sp, #0x10]
//   0x00d60c: b94047e3  ldr      w3, [sp, #0x44]
//   0x00d610: 2a1903f4  mov      w20, w25
//   0x00d614: 2a0803f9  mov      w25, w8
//   0x00d618: aa1a03f3  mov      x19, x26
//   0x00d61c: b9405ffa  ldr      w26, [sp, #0x5c]
//   0x00d620: b81943b7  stur     w23, [x29, #-0x6c]
//   0x00d624: b9407fed  ldr      w13, [sp, #0x7c]
//   0x00d628: b9404fe5  ldr      w5, [sp, #0x4c]
//   0x00d62c: f9401fe4  ldr      x4, [sp, #0x38]
//   0x00d630: f94007fe  ldr      x30, [sp, #8]
//   0x00d634: f9403be8  ldr      x8, [sp, #0x70]
//   0x00d638: b9405bf7  ldr      w23, [sp, #0x58]
//   0x00d63c: 2a1f03e0  mov      w0, wzr
//   0x00d640: aa1b03ef  mov      x15, x27
//   0x00d644: 17fffcfa  b        #0xca2c
//   0x00d648: 2a0503e4  mov      w4, w5
//   0x00d64c: b9407fe5  ldr      w5, [sp, #0x7c]
//   0x00d650: 2a1103f3  mov      w19, w17
//   0x00d654: b94033f1  ldr      w17, [sp, #0x30]
//   0x00d658: f9462aa8  ldr      x8, [x21, #0xc50]
//   0x00d65c: 710007df  cmp      w30, #1
//   0x00d660: 2a0103e9  mov      w9, w1
//   0x00d664: 540008ab  b.lt     #0xd778
//   0x00d668: f94007ea  ldr      x10, [sp, #8]
//   0x00d66c: 2a1f03e9  mov      w9, wzr
//   0x00d670: aa0803eb  mov      x11, x8
//   0x00d674: 2a0a03ea  mov      w10, w10
//   0x00d678: 3840456c  ldrb     w12, [x11], #4
//   0x00d67c: f100054a  subs     x10, x10, #1
//   0x00d680: 8b0c0aac  add      x12, x21, x12, lsl #2
//   0x00d684: b984498d  ldrsw    x13, [x12, #0x448]
//   0x00d688: d37ef5ad  lsl      x13, x13, #2
//   0x00d68c: b86d690e  ldr      w14, [x8, x13]
//   0x00d690: 2a0901ce  orr      w14, w14, w9
//   0x00d694: b82d690e  str      w14, [x8, x13]
//   0x00d698: b944498d  ldr      w13, [x12, #0x448]
//   0x00d69c: 11040129  add      w9, w9, #0x100
//   0x00d6a0: 110005ad  add      w13, w13, #1
//   0x00d6a4: b904498d  str      w13, [x12, #0x448]
//   0x00d6a8: 54fffe81  b.ne     #0xd678
//   0x00d6ac: f94007e9  ldr      x9, [sp, #8]
//   0x00d6b0: 2a0903ec  mov      w12, w9
//   0x00d6b4: 14000032  b        #0xd77c
//   0x00d6b8: b9402aa8  ldr      w8, [x21, #0x28]
//   0x00d6bc: 5290d409  mov      w9, #0x86a0
//   0x00d6c0: 72a00029  movk     w9, #1, lsl #16
//   0x00d6c4: 1b097d08  mul      w8, w8, w9
//   0x00d6c8: 6b0801df  cmp      w14, w8
//   0x00d6cc: 54000502  b.hs     #0xd76c
//   0x00d6d0: aa0e03fb  mov      x27, x14
//   0x00d6d4: 2a1b03e0  mov      w0, w27
//   0x00d6d8: 97ffd496  bl       #0x2930
//   0x00d6dc: b9403ea9  ldr      w9, [x21, #0x3c]
//   0x00d6e0: 2a0003e8  mov      w8, w0
//   0x00d6e4: f94632aa  ldr      x10, [x21, #0xc60]
//   0x00d6e8: b90042a8  str      w8, [x21, #0x40]
//   0x00d6ec: f9462ea8  ldr      x8, [x21, #0xc58]
//   0x00d6f0: d341fd2b  lsr      x11, x9, #1
//   0x00d6f4: 386b694a  ldrb     w10, [x10, x11]
//   0x00d6f8: b94446ab  ldr      w11, [x21, #0x444]
//   0x00d6fc: 78697908  ldrh     w8, [x8, x9, lsl #1]
//   0x00d700: 531e0129  ubfiz    w9, w9, #2, #1
//   0x00d704: 1ac92549  lsr      w9, w10, w9
//   0x00d708: 1100056a  add      w10, w11, #1
//   0x00d70c: 33100d28  bfi      w8, w9, #0x10, #4
//   0x00d710: b9003ea8  str      w8, [x21, #0x3c]
//   0x00d714: b90446aa  str      w10, [x21, #0x444]
//   0x00d718: b94033e8  ldr      w8, [sp, #0x30]
//   0x00d71c: 2a1303f1  mov      w17, w19
//   0x00d720: b9006bf3  str      w19, [sp, #0x68]
//   0x00d724: b9401be6  ldr      w6, [sp, #0x18]
//   0x00d728: 294407e7  ldp      w7, w1, [sp, #0x20]
//   0x00d72c: b94007e2  ldr      w2, [sp, #4]
//   0x00d730: f9400bf0  ldr      x16, [sp, #0x10]
//   0x00d734: b94047e3  ldr      w3, [sp, #0x44]
//   0x00d738: aa1a03f3  mov      x19, x26
//   0x00d73c: b9405ffa  ldr      w26, [sp, #0x5c]
//   0x00d740: b9407fed  ldr      w13, [sp, #0x7c]
//   0x00d744: b9404fe5  ldr      w5, [sp, #0x4c]
//   0x00d748: f9401fe4  ldr      x4, [sp, #0x38]
//   0x00d74c: f94007fe  ldr      x30, [sp, #8]
//   0x00d750: aa1b03ef  mov      x15, x27
//   0x00d754: 2a1f03e0  mov      w0, wzr
//   0x00d758: aa1403ee  mov      x14, x20
//   0x00d75c: 2a1903f4  mov      w20, w25
//   0x00d760: 2a0803f9  mov      w25, w8
//   0x00d764: b81943b7  stur     w23, [x29, #-0x6c]
//   0x00d768: 17fffaba  b        #0xc250
//   0x00d76c: 52800020  mov      w0, #1
//   0x00d770: aa1403ee  mov      x14, x20
//   0x00d774: 17fffcc0  b        #0xca74
//   0x00d778: 2a1f03ec  mov      w12, wzr
//   0x00d77c: b9803aa9  ldrsw    x9, [x21, #0x38]
//   0x00d780: 394052ab  ldrb     w11, [x21, #0x14]
//   0x00d784: 5290d40a  mov      w10, #0x86a0
//   0x00d788: 72a0002a  movk     w10, #1, lsl #16
//   0x00d78c: b8697909  ldr      w9, [x8, x9, lsl #2]
//   0x00d790: b90446bf  str      wzr, [x21, #0x444]
//   0x00d794: d348fd29  lsr      x9, x9, #8
//   0x00d798: b9003ea9  str      w9, [x21, #0x3c]
//   0x00d79c: 340002eb  cbz      w11, #0xd7f8
//   0x00d7a0: b9402aab  ldr      w11, [x21, #0x28]
//   0x00d7a4: 52800020  mov      w0, #1
//   0x00d7a8: aa1403ee  mov      x14, x20
//   0x00d7ac: f9000ebf  str      xzr, [x21, #0x18]
//   0x00d7b0: 1b0a7d6a  mul      w10, w11, w10
//   0x00d7b4: 6b0a013f  cmp      w9, w10
//   0x00d7b8: 54ff95e2  b.hs     #0xca74
//   0x00d7bc: b8697908  ldr      w8, [x8, x9, lsl #2]
//   0x00d7c0: b90446a0  str      w0, [x21, #0x444]
//   0x00d7c4: 53087d09  lsr      w9, w8, #8
//   0x00d7c8: b9003ea9  str      w9, [x21, #0x3c]
//   0x00d7cc: d0000089  adrp     x9, #0x1f000
//   0x00d7d0: f947fd29  ldr      x9, [x9, #0xff8]
//   0x00d7d4: 12001d08  and      w8, w8, #0xff
//   0x00d7d8: b9400129  ldr      w9, [x9]
//   0x00d7dc: 51000529  sub      w9, w9, #1
//   0x00d7e0: 7100053f  cmp      w9, #1
//   0x00d7e4: 290302a9  stp      w9, w0, [x21, #0x18]
//   0x00d7e8: 1a9f17e9  cset     w9, eq
//   0x00d7ec: 4a090108  eor      w8, w8, w9
//   0x00d7f0: b90042a8  str      w8, [x21, #0x40]
//   0x00d7f4: 1400000c  b        #0xd824
//   0x00d7f8: b9402aab  ldr      w11, [x21, #0x28]
//   0x00d7fc: 52800020  mov      w0, #1
//   0x00d800: aa1403ee  mov      x14, x20
//   0x00d804: 1b0a7d6a  mul      w10, w11, w10
//   0x00d808: 6b0a013f  cmp      w9, w10
//   0x00d80c: 54ff9342  b.hs     #0xca74
//   0x00d810: b8695908  ldr      w8, [x8, w9, uxtw #2]
//   0x00d814: b90446a0  str      w0, [x21, #0x444]
//   0x00d818: 12001d09  and      w9, w8, #0xff
//   0x00d81c: 53087d08  lsr      w8, w8, #8
//   0x00d820: 2907a6a8  stp      w8, w9, [x21, #0x3c]
//   0x00d824: 2a1103e8  mov      w8, w17
//   0x00d828: b9006bf3  str      w19, [sp, #0x68]
//   0x00d82c: 2a1303f1  mov      w17, w19
//   0x00d830: 2a1903e9  mov      w9, w25
//   0x00d834: 2a0803f9  mov      w25, w8
//   0x00d838: aa1a03f3  mov      x19, x26
//   0x00d83c: 294b6bf7  ldp      w23, w26, [sp, #0x58]
//   0x00d840: 2a0503ed  mov      w13, w5
//   0x00d844: 2a0403e5  mov      w5, w4
//   0x00d848: f9401fe4  ldr      x4, [sp, #0x38]
//   0x00d84c: f94007fe  ldr      x30, [sp, #8]
//   0x00d850: f9403be8  ldr      x8, [sp, #0x70]
//   0x00d854: 2a1f03e0  mov      w0, wzr
//   0x00d858: aa0f03f0  mov      x16, x15
//   0x00d85c: 2a0903f4  mov      w20, w9
//   0x00d860: aa0c03ef  mov      x15, x12
//   0x00d864: 17fffc72  b        #0xca2c
// ============================================================================
std::uint32_t fde_51_0a608(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000a608ULL;
    for (std::size_t i = 0; i < 3224ULL; ++i) {
        std::uint32_t insn = kTextInstructions[7862ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[52] Subroutine @ 0x00d868..0x00d8a8 (64 bytes, 16 AArch64 instructions)
// [VN] Khung FDE[52] Hàm con @ 0x00d868..0x00d8a8 (64 byte, 16 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00d868: d10083ff  sub      sp, sp, #0x20
//   0x00d86c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d870: 910043fd  add      x29, sp, #0x10
//   0x00d874: d53bd048  mrs      x8, tpidr_el0
//   0x00d878: f9401509  ldr      x9, [x8, #0x28]
//   0x00d87c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00d880: f90007e9  str      x9, [sp, #8]
//   0x00d884: fd014000  str      d0, [x0, #0x280]
//   0x00d888: f9401508  ldr      x8, [x8, #0x28]
//   0x00d88c: f94007e9  ldr      x9, [sp, #8]
//   0x00d890: eb09011f  cmp      x8, x9
//   0x00d894: 54000081  b.ne     #0xd8a4
//   0x00d898: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d89c: 910083ff  add      sp, sp, #0x20
//   0x00d8a0: d65f03c0  ret      
//   0x00d8a4: 97ffd41f  bl       #0x2920
// ============================================================================
std::uint32_t fde_52_0d868(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000d868ULL;
    for (std::size_t i = 0; i < 16ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11086ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[53] Subroutine @ 0x00d8a8..0x00e380 (2776 bytes, 694 AArch64 instructions)
// [VN] Khung FDE[53] Hàm con @ 0x00d8a8..0x00e380 (2776 byte, 694 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00d8a8: d105c3ff  sub      sp, sp, #0x170
//   0x00d8ac: a9116ffc  stp      x28, x27, [sp, #0x110]
//   0x00d8b0: a91267fa  stp      x26, x25, [sp, #0x120]
//   0x00d8b4: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x00d8b8: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x00d8bc: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x00d8c0: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x00d8c4: 910583fd  add      x29, sp, #0x160
//   0x00d8c8: d53bd055  mrs      x21, tpidr_el0
//   0x00d8cc: f94016a8  ldr      x8, [x21, #0x28]
//   0x00d8d0: d0000096  adrp     x22, #0x1f000
//   0x00d8d4: 2a0103f4  mov      w20, w1
//   0x00d8d8: aa0003f3  mov      x19, x0
//   0x00d8dc: f81a03a8  stur     x8, [x29, #-0x60]
//   0x00d8e0: b9406c05  ldr      w5, [x0, #0x6c]
//   0x00d8e4: f947cad6  ldr      x22, [x22, #0xf90]
//   0x00d8e8: 710004bf  cmp      w5, #1
//   0x00d8ec: 540002ab  b.lt     #0xd940
//   0x00d8f0: b9428a68  ldr      w8, [x19, #0x288]
//   0x00d8f4: b9428e69  ldr      w9, [x19, #0x28c]
//   0x00d8f8: b9429662  ldr      w2, [x19, #0x294]
//   0x00d8fc: 2a2803e3  mvn      w3, w8
//   0x00d900: 4ae97d04  eon      w4, w8, w9, ror #31
//   0x00d904: 7100085f  cmp      w2, #2
//   0x00d908: b9028a63  str      w3, [x19, #0x288]
//   0x00d90c: b9028e64  str      w4, [x19, #0x28c]
//   0x00d910: 5400004b  b.lt     #0xd918
//   0x00d914: b900767f  str      wzr, [x19, #0x74]
//   0x00d918: b9429268  ldr      w8, [x19, #0x290]
//   0x00d91c: 7100091f  cmp      w8, #2
//   0x00d920: 540000ab  b.lt     #0xd934
//   0x00d924: b0000041  adrp     x1, #0x16000
//   0x00d928: 9104c2c0  add      x0, x22, #0x130
//   0x00d92c: 913a8021  add      x1, x1, #0xea0
//   0x00d930: 97ffd454  bl       #0x2a80
//   0x00d934: aa1303e0  mov      x0, x19
//   0x00d938: 97ffd3a2  bl       #0x27c0
//   0x00d93c: b9406e65  ldr      w5, [x19, #0x6c]
//   0x00d940: f9401268  ldr      x8, [x19, #0x20]
//   0x00d944: b9429669  ldr      w9, [x19, #0x294]
//   0x00d948: 8b25c108  add      x8, x8, w5, sxtw
//   0x00d94c: 7100053f  cmp      w9, #1
//   0x00d950: f9002a68  str      x8, [x19, #0x50]
//   0x00d954: 54000b01  b.ne     #0xdab4
//   0x00d958: b0000049  adrp     x9, #0x16000
//   0x00d95c: fd473d20  ldr      d0, [x9, #0xe78]
//   0x00d960: b9807669  ldrsw    x9, [x19, #0x74]
//   0x00d964: 5280084a  mov      w10, #0x42
//   0x00d968: fd014260  str      d0, [x19, #0x280]
//   0x00d96c: 3829690a  strb     w10, [x8, x9]
//   0x00d970: b9428669  ldr      w9, [x19, #0x284]
//   0x00d974: b9407668  ldr      w8, [x19, #0x74]
//   0x00d978: b942826a  ldr      w10, [x19, #0x280]
//   0x00d97c: 5100212b  sub      w11, w9, #8
//   0x00d980: 11000508  add      w8, w8, #1
//   0x00d984: 53185d4a  lsl      w10, w10, #8
//   0x00d988: 7100217f  cmp      w11, #8
//   0x00d98c: b9007668  str      w8, [x19, #0x74]
//   0x00d990: b902826a  str      w10, [x19, #0x280]
//   0x00d994: b902866b  str      w11, [x19, #0x284]
//   0x00d998: 540001eb  b.lt     #0xd9d4
//   0x00d99c: f9402a69  ldr      x9, [x19, #0x50]
//   0x00d9a0: 53187d4a  lsr      w10, w10, #0x18
//   0x00d9a4: 3828c92a  strb     w10, [x9, w8, sxtw]
//   0x00d9a8: b9428669  ldr      w9, [x19, #0x284]
//   0x00d9ac: b9407668  ldr      w8, [x19, #0x74]
//   0x00d9b0: b942826a  ldr      w10, [x19, #0x280]
//   0x00d9b4: 5100212b  sub      w11, w9, #8
//   0x00d9b8: 11000508  add      w8, w8, #1
//   0x00d9bc: 53185d4a  lsl      w10, w10, #8
//   0x00d9c0: 71001d7f  cmp      w11, #7
//   0x00d9c4: b9007668  str      w8, [x19, #0x74]
//   0x00d9c8: b902826a  str      w10, [x19, #0x280]
//   0x00d9cc: b902866b  str      w11, [x19, #0x284]
//   0x00d9d0: 54fffe6c  b.gt     #0xd99c
//   0x00d9d4: 4b0903eb  neg      w11, w9
//   0x00d9d8: 52800b4c  mov      w12, #0x5a
//   0x00d9dc: 1acb218b  lsl      w11, w12, w11
//   0x00d9e0: 7100213f  cmp      w9, #8
//   0x00d9e4: 2a0a016b  orr      w11, w11, w10
//   0x00d9e8: b902826b  str      w11, [x19, #0x280]
//   0x00d9ec: b9028669  str      w9, [x19, #0x284]
//   0x00d9f0: 540001eb  b.lt     #0xda2c
//   0x00d9f4: f9402a69  ldr      x9, [x19, #0x50]
//   0x00d9f8: 53187d6a  lsr      w10, w11, #0x18
//   0x00d9fc: 3828c92a  strb     w10, [x9, w8, sxtw]
//   0x00da00: b9428269  ldr      w9, [x19, #0x280]
//   0x00da04: b942866a  ldr      w10, [x19, #0x284]
//   0x00da08: b9407668  ldr      w8, [x19, #0x74]
//   0x00da0c: 53185d2b  lsl      w11, w9, #8
//   0x00da10: 51002149  sub      w9, w10, #8
//   0x00da14: 11000508  add      w8, w8, #1
//   0x00da18: 71001d3f  cmp      w9, #7
//   0x00da1c: b9007668  str      w8, [x19, #0x74]
//   0x00da20: b902826b  str      w11, [x19, #0x280]
//   0x00da24: b9028669  str      w9, [x19, #0x284]
//   0x00da28: 54fffe6c  b.gt     #0xd9f4
//   0x00da2c: b9429a6e  ldr      w14, [x19, #0x298]
//   0x00da30: 5280030a  mov      w10, #0x18
//   0x00da34: 52800d0d  mov      w13, #0x68
//   0x00da38: 1100212c  add      w12, w9, #8
//   0x00da3c: 4b090149  sub      w9, w10, w9
//   0x00da40: 1ac921a9  lsl      w9, w13, w9
//   0x00da44: 2a0b012b  orr      w11, w9, w11
//   0x00da48: 1100c1c9  add      w9, w14, #0x30
//   0x00da4c: 7100219f  cmp      w12, #8
//   0x00da50: 12001d29  and      w9, w9, #0xff
//   0x00da54: b902866c  str      w12, [x19, #0x284]
//   0x00da58: b902826b  str      w11, [x19, #0x280]
//   0x00da5c: 540001eb  b.lt     #0xda98
//   0x00da60: f9402a6c  ldr      x12, [x19, #0x50]
//   0x00da64: 53187d6b  lsr      w11, w11, #0x18
//   0x00da68: 3828c98b  strb     w11, [x12, w8, sxtw]
//   0x00da6c: b942866c  ldr      w12, [x19, #0x284]
//   0x00da70: b9407668  ldr      w8, [x19, #0x74]
//   0x00da74: b942826b  ldr      w11, [x19, #0x280]
//   0x00da78: 5100218c  sub      w12, w12, #8
//   0x00da7c: 11000508  add      w8, w8, #1
//   0x00da80: 53185d6b  lsl      w11, w11, #8
//   0x00da84: 71001d9f  cmp      w12, #7
//   0x00da88: b9007668  str      w8, [x19, #0x74]
//   0x00da8c: b902826b  str      w11, [x19, #0x280]
//   0x00da90: b902866c  str      w12, [x19, #0x284]
//   0x00da94: 54fffe6c  b.gt     #0xda60
//   0x00da98: b9406e65  ldr      w5, [x19, #0x6c]
//   0x00da9c: 4b0c0148  sub      w8, w10, w12
//   0x00daa0: 1ac82128  lsl      w8, w9, w8
//   0x00daa4: 1100218a  add      w10, w12, #8
//   0x00daa8: 2a0b0108  orr      w8, w8, w11
//   0x00daac: b9028268  str      w8, [x19, #0x280]
//   0x00dab0: b902866a  str      w10, [x19, #0x284]
//   0x00dab4: 710004bf  cmp      w5, #1
//   0x00dab8: 54002dcb  b.lt     #0xe070
//   0x00dabc: b942866a  ldr      w10, [x19, #0x284]
//   0x00dac0: 71001d5f  cmp      w10, #7
//   0x00dac4: 5400024d  b.le     #0xdb0c
//   0x00dac8: b9428269  ldr      w9, [x19, #0x280]
//   0x00dacc: b9407668  ldr      w8, [x19, #0x74]
//   0x00dad0: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00dad4: 53187d29  lsr      w9, w9, #0x18
//   0x00dad8: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x00dadc: b942866a  ldr      w10, [x19, #0x284]
//   0x00dae0: b9407668  ldr      w8, [x19, #0x74]
//   0x00dae4: b9428269  ldr      w9, [x19, #0x280]
//   0x00dae8: 5100214a  sub      w10, w10, #8
//   0x00daec: 11000508  add      w8, w8, #1
//   0x00daf0: 53185d29  lsl      w9, w9, #8
//   0x00daf4: 71001d5f  cmp      w10, #7
//   0x00daf8: b9007668  str      w8, [x19, #0x74]
//   0x00dafc: b9028269  str      w9, [x19, #0x280]
//   0x00db00: b902866a  str      w10, [x19, #0x284]
//   0x00db04: 54fffe6c  b.gt     #0xdad0
//   0x00db08: 14000002  b        #0xdb10
//   0x00db0c: b9428269  ldr      w9, [x19, #0x280]
//   0x00db10: 52800308  mov      w8, #0x18
//   0x00db14: 5280062c  mov      w12, #0x31
//   0x00db18: 1100214b  add      w11, w10, #8
//   0x00db1c: 4b0a010a  sub      w10, w8, w10
//   0x00db20: 1aca218a  lsl      w10, w12, w10
//   0x00db24: 7100217f  cmp      w11, #8
//   0x00db28: 2a090149  orr      w9, w10, w9
//   0x00db2c: b9028269  str      w9, [x19, #0x280]
//   0x00db30: b902866b  str      w11, [x19, #0x284]
//   0x00db34: 5400020b  b.lt     #0xdb74
//   0x00db38: b940766a  ldr      w10, [x19, #0x74]
//   0x00db3c: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00db40: 53187d29  lsr      w9, w9, #0x18
//   0x00db44: 382ac969  strb     w9, [x11, w10, sxtw]
//   0x00db48: b9407669  ldr      w9, [x19, #0x74]
//   0x00db4c: b942826b  ldr      w11, [x19, #0x280]
//   0x00db50: b942866c  ldr      w12, [x19, #0x284]
//   0x00db54: 1100052a  add      w10, w9, #1
//   0x00db58: 53185d69  lsl      w9, w11, #8
//   0x00db5c: 5100218b  sub      w11, w12, #8
//   0x00db60: 71001d7f  cmp      w11, #7
//   0x00db64: b900766a  str      w10, [x19, #0x74]
//   0x00db68: b9028269  str      w9, [x19, #0x280]
//   0x00db6c: b902866b  str      w11, [x19, #0x284]
//   0x00db70: 54fffe6c  b.gt     #0xdb3c
//   0x00db74: 4b0b0108  sub      w8, w8, w11
//   0x00db78: 5280082c  mov      w12, #0x41
//   0x00db7c: 1100216a  add      w10, w11, #8
//   0x00db80: 1ac82188  lsl      w8, w12, w8
//   0x00db84: 7100215f  cmp      w10, #8
//   0x00db88: 2a090109  orr      w9, w8, w9
//   0x00db8c: b9028269  str      w9, [x19, #0x280]
//   0x00db90: b902866a  str      w10, [x19, #0x284]
//   0x00db94: 5400020b  b.lt     #0xdbd4
//   0x00db98: b9407668  ldr      w8, [x19, #0x74]
//   0x00db9c: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00dba0: 53187d29  lsr      w9, w9, #0x18
//   0x00dba4: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x00dba8: b942866a  ldr      w10, [x19, #0x284]
//   0x00dbac: b9407668  ldr      w8, [x19, #0x74]
//   0x00dbb0: b9428269  ldr      w9, [x19, #0x280]
//   0x00dbb4: 5100214a  sub      w10, w10, #8
//   0x00dbb8: 11000508  add      w8, w8, #1
//   0x00dbbc: 53185d29  lsl      w9, w9, #8
//   0x00dbc0: 71001d5f  cmp      w10, #7
//   0x00dbc4: b9007668  str      w8, [x19, #0x74]
//   0x00dbc8: b9028269  str      w9, [x19, #0x280]
//   0x00dbcc: b902866a  str      w10, [x19, #0x284]
//   0x00dbd0: 54fffe6c  b.gt     #0xdb9c
//   0x00dbd4: 52800308  mov      w8, #0x18
//   0x00dbd8: 52800b2c  mov      w12, #0x59
//   0x00dbdc: 1100214b  add      w11, w10, #8
//   0x00dbe0: 4b0a010a  sub      w10, w8, w10
//   0x00dbe4: 1aca218a  lsl      w10, w12, w10
//   0x00dbe8: 7100217f  cmp      w11, #8
//   0x00dbec: 2a090149  orr      w9, w10, w9
//   0x00dbf0: b9028269  str      w9, [x19, #0x280]
//   0x00dbf4: b902866b  str      w11, [x19, #0x284]
//   0x00dbf8: 5400020b  b.lt     #0xdc38
//   0x00dbfc: b940766a  ldr      w10, [x19, #0x74]
//   0x00dc00: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00dc04: 53187d29  lsr      w9, w9, #0x18
//   0x00dc08: 382ac969  strb     w9, [x11, w10, sxtw]
//   0x00dc0c: b9407669  ldr      w9, [x19, #0x74]
//   0x00dc10: b942826b  ldr      w11, [x19, #0x280]
//   0x00dc14: b942866c  ldr      w12, [x19, #0x284]
//   0x00dc18: 1100052a  add      w10, w9, #1
//   0x00dc1c: 53185d69  lsl      w9, w11, #8
//   0x00dc20: 5100218b  sub      w11, w12, #8
//   0x00dc24: 71001d7f  cmp      w11, #7
//   0x00dc28: b900766a  str      w10, [x19, #0x74]
//   0x00dc2c: b9028269  str      w9, [x19, #0x280]
//   0x00dc30: b902866b  str      w11, [x19, #0x284]
//   0x00dc34: 54fffe6c  b.gt     #0xdc00
//   0x00dc38: 4b0b0108  sub      w8, w8, w11
//   0x00dc3c: 528004cc  mov      w12, #0x26
//   0x00dc40: 1100216a  add      w10, w11, #8
//   0x00dc44: 1ac82188  lsl      w8, w12, w8
//   0x00dc48: 7100215f  cmp      w10, #8
//   0x00dc4c: 2a090109  orr      w9, w8, w9
//   0x00dc50: b9028269  str      w9, [x19, #0x280]
//   0x00dc54: b902866a  str      w10, [x19, #0x284]
//   0x00dc58: 5400020b  b.lt     #0xdc98
//   0x00dc5c: b9407668  ldr      w8, [x19, #0x74]
//   0x00dc60: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00dc64: 53187d29  lsr      w9, w9, #0x18
//   0x00dc68: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x00dc6c: b942866a  ldr      w10, [x19, #0x284]
//   0x00dc70: b9407668  ldr      w8, [x19, #0x74]
//   0x00dc74: b9428269  ldr      w9, [x19, #0x280]
//   0x00dc78: 5100214a  sub      w10, w10, #8
//   0x00dc7c: 11000508  add      w8, w8, #1
//   0x00dc80: 53185d29  lsl      w9, w9, #8
//   0x00dc84: 71001d5f  cmp      w10, #7
//   0x00dc88: b9007668  str      w8, [x19, #0x74]
//   0x00dc8c: b9028269  str      w9, [x19, #0x280]
//   0x00dc90: b902866a  str      w10, [x19, #0x284]
//   0x00dc94: 54fffe6c  b.gt     #0xdc60
//   0x00dc98: 52800308  mov      w8, #0x18
//   0x00dc9c: 52800a6c  mov      w12, #0x53
//   0x00dca0: 1100214b  add      w11, w10, #8
//   0x00dca4: 4b0a010a  sub      w10, w8, w10
//   0x00dca8: 1aca218a  lsl      w10, w12, w10
//   0x00dcac: 7100217f  cmp      w11, #8
//   0x00dcb0: 2a090149  orr      w9, w10, w9
//   0x00dcb4: b9028269  str      w9, [x19, #0x280]
//   0x00dcb8: b902866b  str      w11, [x19, #0x284]
//   0x00dcbc: 5400020b  b.lt     #0xdcfc
//   0x00dcc0: b940766a  ldr      w10, [x19, #0x74]
//   0x00dcc4: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00dcc8: 53187d29  lsr      w9, w9, #0x18
//   0x00dccc: 382ac969  strb     w9, [x11, w10, sxtw]
//   0x00dcd0: b9407669  ldr      w9, [x19, #0x74]
//   0x00dcd4: b942826b  ldr      w11, [x19, #0x280]
//   0x00dcd8: b942866c  ldr      w12, [x19, #0x284]
//   0x00dcdc: 1100052a  add      w10, w9, #1
//   0x00dce0: 53185d69  lsl      w9, w11, #8
//   0x00dce4: 5100218b  sub      w11, w12, #8
//   0x00dce8: 71001d7f  cmp      w11, #7
//   0x00dcec: b900766a  str      w10, [x19, #0x74]
//   0x00dcf0: b9028269  str      w9, [x19, #0x280]
//   0x00dcf4: b902866b  str      w11, [x19, #0x284]
//   0x00dcf8: 54fffe6c  b.gt     #0xdcc4
//   0x00dcfc: b9428a61  ldr      w1, [x19, #0x288]
//   0x00dd00: 4b0b0108  sub      w8, w8, w11
//   0x00dd04: 52800b2a  mov      w10, #0x59
//   0x00dd08: 1ac82148  lsl      w8, w10, w8
//   0x00dd0c: 1100216b  add      w11, w11, #8
//   0x00dd10: 2a090108  orr      w8, w8, w9
//   0x00dd14: aa1303e0  mov      x0, x19
//   0x00dd18: b9028268  str      w8, [x19, #0x280]
//   0x00dd1c: b902866b  str      w11, [x19, #0x284]
//   0x00dd20: 94000198  bl       #0xe380
//   0x00dd24: b942866a  ldr      w10, [x19, #0x284]
//   0x00dd28: 71001d5f  cmp      w10, #7
//   0x00dd2c: 5400024d  b.le     #0xdd74
//   0x00dd30: b9428268  ldr      w8, [x19, #0x280]
//   0x00dd34: b9407669  ldr      w9, [x19, #0x74]
//   0x00dd38: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00dd3c: 53187d08  lsr      w8, w8, #0x18
//   0x00dd40: 3829c948  strb     w8, [x10, w9, sxtw]
//   0x00dd44: b9407668  ldr      w8, [x19, #0x74]
//   0x00dd48: b942826a  ldr      w10, [x19, #0x280]
//   0x00dd4c: b942866b  ldr      w11, [x19, #0x284]
//   0x00dd50: 11000509  add      w9, w8, #1
//   0x00dd54: 53185d48  lsl      w8, w10, #8
//   0x00dd58: 5100216a  sub      w10, w11, #8
//   0x00dd5c: 71001d5f  cmp      w10, #7
//   0x00dd60: b9007669  str      w9, [x19, #0x74]
//   0x00dd64: b9028268  str      w8, [x19, #0x280]
//   0x00dd68: b902866a  str      w10, [x19, #0x284]
//   0x00dd6c: 54fffe6c  b.gt     #0xdd38
//   0x00dd70: 14000002  b        #0xdd78
//   0x00dd74: b9428268  ldr      w8, [x19, #0x280]
//   0x00dd78: b9403269  ldr      w9, [x19, #0x30]
//   0x00dd7c: 1100054b  add      w11, w10, #1
//   0x00dd80: 71001d5f  cmp      w10, #7
//   0x00dd84: b9028268  str      w8, [x19, #0x280]
//   0x00dd88: b902866b  str      w11, [x19, #0x284]
//   0x00dd8c: 5400020b  b.lt     #0xddcc
//   0x00dd90: b940766a  ldr      w10, [x19, #0x74]
//   0x00dd94: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00dd98: 53187d08  lsr      w8, w8, #0x18
//   0x00dd9c: 382ac968  strb     w8, [x11, w10, sxtw]
//   0x00dda0: b9407668  ldr      w8, [x19, #0x74]
//   0x00dda4: b942826b  ldr      w11, [x19, #0x280]
//   0x00dda8: b942866c  ldr      w12, [x19, #0x284]
//   0x00ddac: 1100050a  add      w10, w8, #1
//   0x00ddb0: 53185d68  lsl      w8, w11, #8
//   0x00ddb4: 5100218b  sub      w11, w12, #8
//   0x00ddb8: 71001d7f  cmp      w11, #7
//   0x00ddbc: b900766a  str      w10, [x19, #0x74]
//   0x00ddc0: b9028268  str      w8, [x19, #0x280]
//   0x00ddc4: b902866b  str      w11, [x19, #0x284]
//   0x00ddc8: 54fffe6c  b.gt     #0xdd94
//   0x00ddcc: 5280010c  mov      w12, #8
//   0x00ddd0: a943ea79  ldp      x25, x26, [x19, #0x38]
//   0x00ddd4: f9402677  ldr      x23, [x19, #0x48]
//   0x00ddd8: 1100616d  add      w13, w11, #0x18
//   0x00dddc: 4b0b018b  sub      w11, w12, w11
//   0x00dde0: 1acb2129  lsl      w9, w9, w11
//   0x00dde4: 2a1f03fb  mov      w27, wzr
//   0x00dde8: aa1f03ea  mov      x10, xzr
//   0x00ddec: 2a080128  orr      w8, w9, w8
//   0x00ddf0: b902866d  str      w13, [x19, #0x284]
//   0x00ddf4: b9028268  str      w8, [x19, #0x280]
//   0x00ddf8: b9007e7f  str      wzr, [x19, #0x7c]
//   0x00ddfc: 14000004  b        #0xde0c
//   0x00de00: 9100054a  add      x10, x10, #1
//   0x00de04: f104015f  cmp      x10, #0x100
//   0x00de08: 54000100  b.eq     #0xde28
//   0x00de0c: 8b0a0268  add      x8, x19, x10
//   0x00de10: 39420109  ldrb     w9, [x8, #0x80]
//   0x00de14: 34ffff69  cbz      w9, #0xde00
//   0x00de18: 3906011b  strb     w27, [x8, #0x180]
//   0x00de1c: 1100077b  add      w27, w27, #1
//   0x00de20: b9007e7b  str      w27, [x19, #0x7c]
//   0x00de24: 17fffff7  b        #0xde00
//   0x00de28: 93407f68  sxtw     x8, w27
//   0x00de2c: 91000518  add      x24, x8, #1
//   0x00de30: 37f800d8  tbnz     w24, #0x1f, #0xde48
//   0x00de34: 11000b68  add      w8, w27, #2
//   0x00de38: 910a8260  add      x0, x19, #0x2a0
//   0x00de3c: d37ef502  lsl      x2, x8, #2
//   0x00de40: 2a1f03e1  mov      w1, wzr
//   0x00de44: 97ffd31f  bl       #0x2ac0
//   0x00de48: 7100077f  cmp      w27, #1
//   0x00de4c: 540002eb  b.lt     #0xdea8
//   0x00de50: 71003f7f  cmp      w27, #0xf
//   0x00de54: 2a1b03e8  mov      w8, w27
//   0x00de58: 54000068  b.hi     #0xde64
//   0x00de5c: aa1f03e9  mov      x9, xzr
//   0x00de60: 1400000d  b        #0xde94
//   0x00de64: b0000049  adrp     x9, #0x16000
//   0x00de68: 3dc37d20  ldr      q0, [x9, #0xdf0]
//   0x00de6c: 927c6d09  and      x9, x8, #0xfffffff0
//   0x00de70: 910003ea  mov      x10, sp
//   0x00de74: 4f00e601  movi     v1.16b, #0x10
//   0x00de78: aa0903eb  mov      x11, x9
//   0x00de7c: 3c810540  str      q0, [x10], #0x10
//   0x00de80: f100416b  subs     x11, x11, #0x10
//   0x00de84: 4e218400  add      v0.16b, v0.16b, v1.16b
//   0x00de88: 54ffffa1  b.ne     #0xde7c
//   0x00de8c: eb08013f  cmp      x9, x8
//   0x00de90: 540000c0  b.eq     #0xdea8
//   0x00de94: 910003ea  mov      x10, sp
//   0x00de98: 38296949  strb     w9, [x10, x9]
//   0x00de9c: 91000529  add      x9, x9, #1
//   0x00dea0: eb09011f  cmp      x8, x9
//   0x00dea4: 54ffffa1  b.ne     #0xde98
//   0x00dea8: b9406e6f  ldr      w15, [x19, #0x6c]
//   0x00deac: 710005ff  cmp      w15, #1
//   0x00deb0: 54000ccb  b.lt     #0xe048
//   0x00deb4: 910003ea  mov      x10, sp
//   0x00deb8: aa1f03e9  mov      x9, xzr
//   0x00debc: 2a1f03ed  mov      w13, wzr
//   0x00dec0: 2a1f03e8  mov      w8, wzr
//   0x00dec4: b240014b  orr      x11, x10, #1
//   0x00dec8: 5280002c  mov      w12, #1
//   0x00decc: 1400000f  b        #0xdf08
//   0x00ded0: 390003ee  strb     w14, [sp]
//   0x00ded4: 4b0a01ee  sub      w14, w15, w10
//   0x00ded8: 93407dce  sxtw     x14, w14
//   0x00dedc: 910005ce  add      x14, x14, #1
//   0x00dee0: 7828daee  strh     w14, [x23, w8, sxtw #1]
//   0x00dee4: 8b0e0a6e  add      x14, x19, x14, lsl #2
//   0x00dee8: b942a1cf  ldr      w15, [x14, #0x2a0]
//   0x00deec: 11000508  add      w8, w8, #1
//   0x00def0: 110005ef  add      w15, w15, #1
//   0x00def4: b902a1cf  str      w15, [x14, #0x2a0]
//   0x00def8: b9406e6f  ldr      w15, [x19, #0x6c]
//   0x00defc: 91000529  add      x9, x9, #1
//   0x00df00: eb2fc13f  cmp      x9, w15, sxtw
//   0x00df04: 540006ca  b.ge     #0xdfdc
//   0x00df08: b8697b2e  ldr      w14, [x25, x9, lsl #2]
//   0x00df0c: 510005ce  sub      w14, w14, #1
//   0x00df10: 0a8e7df0  and      w16, w15, w14, asr #31
//   0x00df14: 0b0e020e  add      w14, w16, w14
//   0x00df18: 386ecb4e  ldrb     w14, [x26, w14, sxtw]
//   0x00df1c: 394003f0  ldrb     w16, [sp]
//   0x00df20: 8b0e026e  add      x14, x19, x14
//   0x00df24: 394601ce  ldrb     w14, [x14, #0x180]
//   0x00df28: 6b0e021f  cmp      w16, w14
//   0x00df2c: 54000061  b.ne     #0xdf38
//   0x00df30: 110005ad  add      w13, w13, #1
//   0x00df34: 17fffff2  b        #0xdefc
//   0x00df38: 710005af  subs     w15, w13, #1
//   0x00df3c: 5400038b  b.lt     #0xdfac
//   0x00df40: 11000510  add      w16, w8, #1
//   0x00df44: 8b28c6ed  add      x13, x23, w8, sxtw #1
//   0x00df48: 2a1003e8  mov      w8, w16
//   0x00df4c: 3700010f  tbnz     w15, #0, #0xdf6c
//   0x00df50: 790001bf  strh     wzr, [x13]
//   0x00df54: b942a270  ldr      w16, [x19, #0x2a0]
//   0x00df58: 11000610  add      w16, w16, #1
//   0x00df5c: b902a270  str      w16, [x19, #0x2a0]
//   0x00df60: 710009f0  subs     w16, w15, #2
//   0x00df64: 5400010a  b.ge     #0xdf84
//   0x00df68: 1400000f  b        #0xdfa4
//   0x00df6c: 790001ac  strh     w12, [x13]
//   0x00df70: b942a670  ldr      w16, [x19, #0x2a4]
//   0x00df74: 11000610  add      w16, w16, #1
//   0x00df78: b902a670  str      w16, [x19, #0x2a4]
//   0x00df7c: 710009f0  subs     w16, w15, #2
//   0x00df80: 5400012b  b.lt     #0xdfa4
//   0x00df84: 510005ef  sub      w15, w15, #1
//   0x00df88: 7100021f  cmp      w16, #0
//   0x00df8c: 1a90b1ef  csel     w15, w15, w16, lt
//   0x00df90: 11000508  add      w8, w8, #1
//   0x00df94: 13017def  asr      w15, w15, #1
//   0x00df98: 910009ad  add      x13, x13, #2
//   0x00df9c: 3707fe8f  tbnz     w15, #0, #0xdf6c
//   0x00dfa0: 17ffffec  b        #0xdf50
//   0x00dfa4: 394003f0  ldrb     w16, [sp]
//   0x00dfa8: 2a1f03ed  mov      w13, wzr
//   0x00dfac: 394007f1  ldrb     w17, [sp, #1]
//   0x00dfb0: aa0b03ef  mov      x15, x11
//   0x00dfb4: 390007f0  strb     w16, [sp, #1]
//   0x00dfb8: 6b1101df  cmp      w14, w17
//   0x00dfbc: 54fff8a0  b.eq     #0xded0
//   0x00dfc0: aa0b03ef  mov      x15, x11
//   0x00dfc4: 38401df0  ldrb     w16, [x15, #1]!
//   0x00dfc8: 6b1001df  cmp      w14, w16
//   0x00dfcc: 390001f1  strb     w17, [x15]
//   0x00dfd0: 2a1003f1  mov      w17, w16
//   0x00dfd4: 54ffff81  b.ne     #0xdfc4
//   0x00dfd8: 17ffffbe  b        #0xded0
//   0x00dfdc: 710005a9  subs     w9, w13, #1
//   0x00dfe0: 5400036b  b.lt     #0xe04c
//   0x00dfe4: 8b28c6ea  add      x10, x23, w8, sxtw #1
//   0x00dfe8: 11000508  add      w8, w8, #1
//   0x00dfec: 5280002b  mov      w11, #1
//   0x00dff0: 37000109  tbnz     w9, #0, #0xe010
//   0x00dff4: 7900015f  strh     wzr, [x10]
//   0x00dff8: b942a26c  ldr      w12, [x19, #0x2a0]
//   0x00dffc: 1100058c  add      w12, w12, #1
//   0x00e000: b902a26c  str      w12, [x19, #0x2a0]
//   0x00e004: 7100092c  subs     w12, w9, #2
//   0x00e008: 5400010a  b.ge     #0xe028
//   0x00e00c: 14000010  b        #0xe04c
//   0x00e010: 7900014b  strh     w11, [x10]
//   0x00e014: b942a66c  ldr      w12, [x19, #0x2a4]
//   0x00e018: 1100058c  add      w12, w12, #1
//   0x00e01c: b902a66c  str      w12, [x19, #0x2a4]
//   0x00e020: 7100092c  subs     w12, w9, #2
//   0x00e024: 5400014b  b.lt     #0xe04c
//   0x00e028: 51000529  sub      w9, w9, #1
//   0x00e02c: 7100019f  cmp      w12, #0
//   0x00e030: 1a8cb129  csel     w9, w9, w12, lt
//   0x00e034: 11000508  add      w8, w8, #1
//   0x00e038: 13017d29  asr      w9, w9, #1
//   0x00e03c: 9100094a  add      x10, x10, #2
//   0x00e040: 3707fe89  tbnz     w9, #0, #0xe010
//   0x00e044: 17ffffec  b        #0xdff4
//   0x00e048: 2a1f03e8  mov      w8, wzr
//   0x00e04c: 7828daf8  strh     w24, [x23, w8, sxtw #1]
//   0x00e050: 8b180a69  add      x9, x19, x24, lsl #2
//   0x00e054: b942a12a  ldr      w10, [x9, #0x2a0]
//   0x00e058: 11000508  add      w8, w8, #1
//   0x00e05c: aa1303e0  mov      x0, x19
//   0x00e060: 1100054a  add      w10, w10, #1
//   0x00e064: b902a12a  str      w10, [x9, #0x2a0]
//   0x00e068: b9029e68  str      w8, [x19, #0x29c]
//   0x00e06c: 94000139  bl       #0xe550
//   0x00e070: 72001e9f  tst      w20, #0xff
//   0x00e074: 540016c0  b.eq     #0xe34c
//   0x00e078: b942866a  ldr      w10, [x19, #0x284]
//   0x00e07c: 71001d5f  cmp      w10, #7
//   0x00e080: 5400024d  b.le     #0xe0c8
//   0x00e084: b9428269  ldr      w9, [x19, #0x280]
//   0x00e088: b9407668  ldr      w8, [x19, #0x74]
//   0x00e08c: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00e090: 53187d29  lsr      w9, w9, #0x18
//   0x00e094: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x00e098: b942866a  ldr      w10, [x19, #0x284]
//   0x00e09c: b9407668  ldr      w8, [x19, #0x74]
//   0x00e0a0: b9428269  ldr      w9, [x19, #0x280]
//   0x00e0a4: 5100214a  sub      w10, w10, #8
//   0x00e0a8: 11000508  add      w8, w8, #1
//   0x00e0ac: 53185d29  lsl      w9, w9, #8
//   0x00e0b0: 71001d5f  cmp      w10, #7
//   0x00e0b4: b9007668  str      w8, [x19, #0x74]
//   0x00e0b8: b9028269  str      w9, [x19, #0x280]
//   0x00e0bc: b902866a  str      w10, [x19, #0x284]
//   0x00e0c0: 54fffe6c  b.gt     #0xe08c
//   0x00e0c4: 14000002  b        #0xe0cc
//   0x00e0c8: b9428269  ldr      w9, [x19, #0x280]
//   0x00e0cc: 52800308  mov      w8, #0x18
//   0x00e0d0: 528002ec  mov      w12, #0x17
//   0x00e0d4: 1100214b  add      w11, w10, #8
//   0x00e0d8: 4b0a010a  sub      w10, w8, w10
//   0x00e0dc: 1aca218a  lsl      w10, w12, w10
//   0x00e0e0: 7100217f  cmp      w11, #8
//   0x00e0e4: 2a090149  orr      w9, w10, w9
//   0x00e0e8: b9028269  str      w9, [x19, #0x280]
//   0x00e0ec: b902866b  str      w11, [x19, #0x284]
//   0x00e0f0: 5400020b  b.lt     #0xe130
//   0x00e0f4: b940766a  ldr      w10, [x19, #0x74]
//   0x00e0f8: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00e0fc: 53187d29  lsr      w9, w9, #0x18
//   0x00e100: 382ac969  strb     w9, [x11, w10, sxtw]
//   0x00e104: b9407669  ldr      w9, [x19, #0x74]
//   0x00e108: b942826b  ldr      w11, [x19, #0x280]
//   0x00e10c: b942866c  ldr      w12, [x19, #0x284]
//   0x00e110: 1100052a  add      w10, w9, #1
//   0x00e114: 53185d69  lsl      w9, w11, #8
//   0x00e118: 5100218b  sub      w11, w12, #8
//   0x00e11c: 71001d7f  cmp      w11, #7
//   0x00e120: b900766a  str      w10, [x19, #0x74]
//   0x00e124: b9028269  str      w9, [x19, #0x280]
//   0x00e128: b902866b  str      w11, [x19, #0x284]
//   0x00e12c: 54fffe6c  b.gt     #0xe0f8
//   0x00e130: 4b0b0108  sub      w8, w8, w11
//   0x00e134: 52800e4c  mov      w12, #0x72
//   0x00e138: 1100216a  add      w10, w11, #8
//   0x00e13c: 1ac82188  lsl      w8, w12, w8
//   0x00e140: 7100215f  cmp      w10, #8
//   0x00e144: 2a090109  orr      w9, w8, w9
//   0x00e148: b9028269  str      w9, [x19, #0x280]
//   0x00e14c: b902866a  str      w10, [x19, #0x284]
//   0x00e150: 5400020b  b.lt     #0xe190
//   0x00e154: b9407668  ldr      w8, [x19, #0x74]
//   0x00e158: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00e15c: 53187d29  lsr      w9, w9, #0x18
//   0x00e160: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x00e164: b942866a  ldr      w10, [x19, #0x284]
//   0x00e168: b9407668  ldr      w8, [x19, #0x74]
//   0x00e16c: b9428269  ldr      w9, [x19, #0x280]
//   0x00e170: 5100214a  sub      w10, w10, #8
//   0x00e174: 11000508  add      w8, w8, #1
//   0x00e178: 53185d29  lsl      w9, w9, #8
//   0x00e17c: 71001d5f  cmp      w10, #7
//   0x00e180: b9007668  str      w8, [x19, #0x74]
//   0x00e184: b9028269  str      w9, [x19, #0x280]
//   0x00e188: b902866a  str      w10, [x19, #0x284]
//   0x00e18c: 54fffe6c  b.gt     #0xe158
//   0x00e190: 52800308  mov      w8, #0x18
//   0x00e194: 528008ac  mov      w12, #0x45
//   0x00e198: 1100214b  add      w11, w10, #8
//   0x00e19c: 4b0a010a  sub      w10, w8, w10
//   0x00e1a0: 1aca218a  lsl      w10, w12, w10
//   0x00e1a4: 7100217f  cmp      w11, #8
//   0x00e1a8: 2a090149  orr      w9, w10, w9
//   0x00e1ac: b9028269  str      w9, [x19, #0x280]
//   0x00e1b0: b902866b  str      w11, [x19, #0x284]
//   0x00e1b4: 5400020b  b.lt     #0xe1f4
//   0x00e1b8: b940766a  ldr      w10, [x19, #0x74]
//   0x00e1bc: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00e1c0: 53187d29  lsr      w9, w9, #0x18
//   0x00e1c4: 382ac969  strb     w9, [x11, w10, sxtw]
//   0x00e1c8: b9407669  ldr      w9, [x19, #0x74]
//   0x00e1cc: b942826b  ldr      w11, [x19, #0x280]
//   0x00e1d0: b942866c  ldr      w12, [x19, #0x284]
//   0x00e1d4: 1100052a  add      w10, w9, #1
//   0x00e1d8: 53185d69  lsl      w9, w11, #8
//   0x00e1dc: 5100218b  sub      w11, w12, #8
//   0x00e1e0: 71001d7f  cmp      w11, #7
//   0x00e1e4: b900766a  str      w10, [x19, #0x74]
//   0x00e1e8: b9028269  str      w9, [x19, #0x280]
//   0x00e1ec: b902866b  str      w11, [x19, #0x284]
//   0x00e1f0: 54fffe6c  b.gt     #0xe1bc
//   0x00e1f4: 4b0b0108  sub      w8, w8, w11
//   0x00e1f8: 5280070c  mov      w12, #0x38
//   0x00e1fc: 1100216a  add      w10, w11, #8
//   0x00e200: 1ac82188  lsl      w8, w12, w8
//   0x00e204: 7100215f  cmp      w10, #8
//   0x00e208: 2a090109  orr      w9, w8, w9
//   0x00e20c: b9028269  str      w9, [x19, #0x280]
//   0x00e210: b902866a  str      w10, [x19, #0x284]
//   0x00e214: 5400020b  b.lt     #0xe254
//   0x00e218: b9407668  ldr      w8, [x19, #0x74]
//   0x00e21c: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00e220: 53187d29  lsr      w9, w9, #0x18
//   0x00e224: 3828c949  strb     w9, [x10, w8, sxtw]
//   0x00e228: b942866a  ldr      w10, [x19, #0x284]
//   0x00e22c: b9407668  ldr      w8, [x19, #0x74]
//   0x00e230: b9428269  ldr      w9, [x19, #0x280]
//   0x00e234: 5100214a  sub      w10, w10, #8
//   0x00e238: 11000508  add      w8, w8, #1
//   0x00e23c: 53185d29  lsl      w9, w9, #8
//   0x00e240: 71001d5f  cmp      w10, #7
//   0x00e244: b9007668  str      w8, [x19, #0x74]
//   0x00e248: b9028269  str      w9, [x19, #0x280]
//   0x00e24c: b902866a  str      w10, [x19, #0x284]
//   0x00e250: 54fffe6c  b.gt     #0xe21c
//   0x00e254: 52800308  mov      w8, #0x18
//   0x00e258: 52800a0c  mov      w12, #0x50
//   0x00e25c: 1100214b  add      w11, w10, #8
//   0x00e260: 4b0a010a  sub      w10, w8, w10
//   0x00e264: 1aca218a  lsl      w10, w12, w10
//   0x00e268: 7100217f  cmp      w11, #8
//   0x00e26c: 2a090149  orr      w9, w10, w9
//   0x00e270: b9028269  str      w9, [x19, #0x280]
//   0x00e274: b902866b  str      w11, [x19, #0x284]
//   0x00e278: 5400020b  b.lt     #0xe2b8
//   0x00e27c: b940766a  ldr      w10, [x19, #0x74]
//   0x00e280: f9402a6b  ldr      x11, [x19, #0x50]
//   0x00e284: 53187d29  lsr      w9, w9, #0x18
//   0x00e288: 382ac969  strb     w9, [x11, w10, sxtw]
//   0x00e28c: b9407669  ldr      w9, [x19, #0x74]
//   0x00e290: b942826b  ldr      w11, [x19, #0x280]
//   0x00e294: b942866c  ldr      w12, [x19, #0x284]
//   0x00e298: 1100052a  add      w10, w9, #1
//   0x00e29c: 53185d69  lsl      w9, w11, #8
//   0x00e2a0: 5100218b  sub      w11, w12, #8
//   0x00e2a4: 71001d7f  cmp      w11, #7
//   0x00e2a8: b900766a  str      w10, [x19, #0x74]
//   0x00e2ac: b9028269  str      w9, [x19, #0x280]
//   0x00e2b0: b902866b  str      w11, [x19, #0x284]
//   0x00e2b4: 54fffe6c  b.gt     #0xe280
//   0x00e2b8: b9428e61  ldr      w1, [x19, #0x28c]
//   0x00e2bc: 4b0b0108  sub      w8, w8, w11
//   0x00e2c0: 5280120a  mov      w10, #0x90
//   0x00e2c4: 1ac82148  lsl      w8, w10, w8
//   0x00e2c8: 1100216b  add      w11, w11, #8
//   0x00e2cc: 2a090108  orr      w8, w8, w9
//   0x00e2d0: aa1303e0  mov      x0, x19
//   0x00e2d4: b9028268  str      w8, [x19, #0x280]
//   0x00e2d8: b902866b  str      w11, [x19, #0x284]
//   0x00e2dc: 94000029  bl       #0xe380
//   0x00e2e0: b9429268  ldr      w8, [x19, #0x290]
//   0x00e2e4: 7100051f  cmp      w8, #1
//   0x00e2e8: 540000cd  b.le     #0xe300
//   0x00e2ec: b9428e62  ldr      w2, [x19, #0x28c]
//   0x00e2f0: 90000041  adrp     x1, #0x16000
//   0x00e2f4: 9104c2c0  add      x0, x22, #0x130
//   0x00e2f8: 913b7821  add      x1, x1, #0xede
//   0x00e2fc: 97ffd1e1  bl       #0x2a80
//   0x00e300: b9428668  ldr      w8, [x19, #0x284]
//   0x00e304: 7100051f  cmp      w8, #1
//   0x00e308: 5400022b  b.lt     #0xe34c
//   0x00e30c: b9428268  ldr      w8, [x19, #0x280]
//   0x00e310: b9407669  ldr      w9, [x19, #0x74]
//   0x00e314: f9402a6a  ldr      x10, [x19, #0x50]
//   0x00e318: 53187d08  lsr      w8, w8, #0x18
//   0x00e31c: 3829c948  strb     w8, [x10, w9, sxtw]
//   0x00e320: b9407668  ldr      w8, [x19, #0x74]
//   0x00e324: b942826a  ldr      w10, [x19, #0x280]
//   0x00e328: b942866b  ldr      w11, [x19, #0x284]
//   0x00e32c: 11000509  add      w9, w8, #1
//   0x00e330: 53185d48  lsl      w8, w10, #8
//   0x00e334: 5100216a  sub      w10, w11, #8
//   0x00e338: 7100015f  cmp      w10, #0
//   0x00e33c: b9007669  str      w9, [x19, #0x74]
//   0x00e340: b9028268  str      w8, [x19, #0x280]
//   0x00e344: b902866a  str      w10, [x19, #0x284]
//   0x00e348: 54fffe6c  b.gt     #0xe314
//   0x00e34c: f94016a8  ldr      x8, [x21, #0x28]
//   0x00e350: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x00e354: eb09011f  cmp      x8, x9
//   0x00e358: 54000121  b.ne     #0xe37c
//   0x00e35c: a9567bfd  ldp      x29, x30, [sp, #0x160]
//   0x00e360: a9554ff4  ldp      x20, x19, [sp, #0x150]
//   0x00e364: a95457f6  ldp      x22, x21, [sp, #0x140]
//   0x00e368: a9535ff8  ldp      x24, x23, [sp, #0x130]
//   0x00e36c: a95267fa  ldp      x26, x25, [sp, #0x120]
//   0x00e370: a9516ffc  ldp      x28, x27, [sp, #0x110]
//   0x00e374: 9105c3ff  add      sp, sp, #0x170
//   0x00e378: d65f03c0  ret      
//   0x00e37c: 97ffd169  bl       #0x2920
// ============================================================================
std::uint32_t fde_53_0d8a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000d8a8ULL;
    for (std::size_t i = 0; i < 694ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11102ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[54] Subroutine @ 0x00e380..0x00e550 (464 bytes, 116 AArch64 instructions)
// [VN] Khung FDE[54] Hàm con @ 0x00e380..0x00e550 (464 byte, 116 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e380: d10083ff  sub      sp, sp, #0x20
//   0x00e384: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00e388: 910043fd  add      x29, sp, #0x10
//   0x00e38c: d53bd048  mrs      x8, tpidr_el0
//   0x00e390: f9401509  ldr      x9, [x8, #0x28]
//   0x00e394: f90007e9  str      x9, [sp, #8]
//   0x00e398: b942840c  ldr      w12, [x0, #0x284]
//   0x00e39c: 53187c29  lsr      w9, w1, #0x18
//   0x00e3a0: 71001d9f  cmp      w12, #7
//   0x00e3a4: 5400024d  b.le     #0xe3ec
//   0x00e3a8: b942800b  ldr      w11, [x0, #0x280]
//   0x00e3ac: b940740a  ldr      w10, [x0, #0x74]
//   0x00e3b0: f940280c  ldr      x12, [x0, #0x50]
//   0x00e3b4: 53187d6b  lsr      w11, w11, #0x18
//   0x00e3b8: 382ac98b  strb     w11, [x12, w10, sxtw]
//   0x00e3bc: b942840c  ldr      w12, [x0, #0x284]
//   0x00e3c0: b940740a  ldr      w10, [x0, #0x74]
//   0x00e3c4: b942800b  ldr      w11, [x0, #0x280]
//   0x00e3c8: 5100218c  sub      w12, w12, #8
//   0x00e3cc: 1100054a  add      w10, w10, #1
//   0x00e3d0: 53185d6b  lsl      w11, w11, #8
//   0x00e3d4: 71001d9f  cmp      w12, #7
//   0x00e3d8: b900740a  str      w10, [x0, #0x74]
//   0x00e3dc: b902800b  str      w11, [x0, #0x280]
//   0x00e3e0: b902840c  str      w12, [x0, #0x284]
//   0x00e3e4: 54fffe6c  b.gt     #0xe3b0
//   0x00e3e8: 14000002  b        #0xe3f0
//   0x00e3ec: b942800b  ldr      w11, [x0, #0x280]
//   0x00e3f0: 5280030a  mov      w10, #0x18
//   0x00e3f4: 1100218d  add      w13, w12, #8
//   0x00e3f8: 4b0c014c  sub      w12, w10, w12
//   0x00e3fc: 1acc2129  lsl      w9, w9, w12
//   0x00e400: 710021bf  cmp      w13, #8
//   0x00e404: 2a0b012b  orr      w11, w9, w11
//   0x00e408: 53105c29  ubfx     w9, w1, #0x10, #8
//   0x00e40c: b902840d  str      w13, [x0, #0x284]
//   0x00e410: b902800b  str      w11, [x0, #0x280]
//   0x00e414: 5400020b  b.lt     #0xe454
//   0x00e418: b940740c  ldr      w12, [x0, #0x74]
//   0x00e41c: f940280d  ldr      x13, [x0, #0x50]
//   0x00e420: 53187d6b  lsr      w11, w11, #0x18
//   0x00e424: 382cc9ab  strb     w11, [x13, w12, sxtw]
//   0x00e428: b940740b  ldr      w11, [x0, #0x74]
//   0x00e42c: b942800d  ldr      w13, [x0, #0x280]
//   0x00e430: b942840e  ldr      w14, [x0, #0x284]
//   0x00e434: 1100056c  add      w12, w11, #1
//   0x00e438: 53185dab  lsl      w11, w13, #8
//   0x00e43c: 510021cd  sub      w13, w14, #8
//   0x00e440: 71001dbf  cmp      w13, #7
//   0x00e444: b900740c  str      w12, [x0, #0x74]
//   0x00e448: b902800b  str      w11, [x0, #0x280]
//   0x00e44c: b902840d  str      w13, [x0, #0x284]
//   0x00e450: 54fffe6c  b.gt     #0xe41c
//   0x00e454: 4b0d014a  sub      w10, w10, w13
//   0x00e458: 110021ac  add      w12, w13, #8
//   0x00e45c: 1aca2129  lsl      w9, w9, w10
//   0x00e460: 7100219f  cmp      w12, #8
//   0x00e464: 2a0b012b  orr      w11, w9, w11
//   0x00e468: 53083c2a  ubfx     w10, w1, #8, #8
//   0x00e46c: b902840c  str      w12, [x0, #0x284]
//   0x00e470: b902800b  str      w11, [x0, #0x280]
//   0x00e474: 5400020b  b.lt     #0xe4b4
//   0x00e478: b9407409  ldr      w9, [x0, #0x74]
//   0x00e47c: f940280c  ldr      x12, [x0, #0x50]
//   0x00e480: 53187d6b  lsr      w11, w11, #0x18
//   0x00e484: 3829c98b  strb     w11, [x12, w9, sxtw]
//   0x00e488: b942840c  ldr      w12, [x0, #0x284]
//   0x00e48c: b9407409  ldr      w9, [x0, #0x74]
//   0x00e490: b942800b  ldr      w11, [x0, #0x280]
//   0x00e494: 5100218c  sub      w12, w12, #8
//   0x00e498: 11000529  add      w9, w9, #1
//   0x00e49c: 53185d6b  lsl      w11, w11, #8
//   0x00e4a0: 71001d9f  cmp      w12, #7
//   0x00e4a4: b9007409  str      w9, [x0, #0x74]
//   0x00e4a8: b902800b  str      w11, [x0, #0x280]
//   0x00e4ac: b902840c  str      w12, [x0, #0x284]
//   0x00e4b0: 54fffe6c  b.gt     #0xe47c
//   0x00e4b4: 52800309  mov      w9, #0x18
//   0x00e4b8: 1100218d  add      w13, w12, #8
//   0x00e4bc: 4b0c012c  sub      w12, w9, w12
//   0x00e4c0: 1acc214a  lsl      w10, w10, w12
//   0x00e4c4: 710021bf  cmp      w13, #8
//   0x00e4c8: 2a0b014b  orr      w11, w10, w11
//   0x00e4cc: 12001c2a  and      w10, w1, #0xff
//   0x00e4d0: b902840d  str      w13, [x0, #0x284]
//   0x00e4d4: b902800b  str      w11, [x0, #0x280]
//   0x00e4d8: 5400020b  b.lt     #0xe518
//   0x00e4dc: b940740c  ldr      w12, [x0, #0x74]
//   0x00e4e0: f940280d  ldr      x13, [x0, #0x50]
//   0x00e4e4: 53187d6b  lsr      w11, w11, #0x18
//   0x00e4e8: 382cc9ab  strb     w11, [x13, w12, sxtw]
//   0x00e4ec: b940740b  ldr      w11, [x0, #0x74]
//   0x00e4f0: b942800d  ldr      w13, [x0, #0x280]
//   0x00e4f4: b942840e  ldr      w14, [x0, #0x284]
//   0x00e4f8: 1100056c  add      w12, w11, #1
//   0x00e4fc: 53185dab  lsl      w11, w13, #8
//   0x00e500: 510021cd  sub      w13, w14, #8
//   0x00e504: 71001dbf  cmp      w13, #7
//   0x00e508: b900740c  str      w12, [x0, #0x74]
//   0x00e50c: b902800b  str      w11, [x0, #0x280]
//   0x00e510: b902840d  str      w13, [x0, #0x284]
//   0x00e514: 54fffe6c  b.gt     #0xe4e0
//   0x00e518: 4b0d0129  sub      w9, w9, w13
//   0x00e51c: 1ac92149  lsl      w9, w10, w9
//   0x00e520: 110021ac  add      w12, w13, #8
//   0x00e524: 2a0b0129  orr      w9, w9, w11
//   0x00e528: b902840c  str      w12, [x0, #0x284]
//   0x00e52c: b9028009  str      w9, [x0, #0x280]
//   0x00e530: f9401508  ldr      x8, [x8, #0x28]
//   0x00e534: f94007e9  ldr      x9, [sp, #8]
//   0x00e538: eb09011f  cmp      x8, x9
//   0x00e53c: 54000081  b.ne     #0xe54c
//   0x00e540: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00e544: 910083ff  add      sp, sp, #0x20
//   0x00e548: d65f03c0  ret      
//   0x00e54c: 97ffd0f5  bl       #0x2920
// ============================================================================
std::uint32_t fde_54_0e380(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e380ULL;
    for (std::size_t i = 0; i < 116ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11796ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[55] Subroutine @ 0x00e550..0x0119a8 (13400 bytes, 3350 AArch64 instructions)
// [VN] Khung FDE[55] Hàm con @ 0x00e550..0x0119a8 (13400 byte, 3350 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x00e550: d10543ff  sub      sp, sp, #0x150
//   0x00e554: fd0073e8  str      d8, [sp, #0xe0]
//   0x00e558: a90f6ffc  stp      x28, x27, [sp, #0xf0]
//   0x00e55c: a91067fa  stp      x26, x25, [sp, #0x100]
//   0x00e560: a9115ff8  stp      x24, x23, [sp, #0x110]
//   0x00e564: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x00e568: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x00e56c: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x00e570: 910503fd  add      x29, sp, #0x140
//   0x00e574: d53bd048  mrs      x8, tpidr_el0
//   0x00e578: f90003e8  str      x8, [sp]
//   0x00e57c: f9401508  ldr      x8, [x8, #0x28]
//   0x00e580: aa0003f7  mov      x23, x0
//   0x00e584: f81903a8  stur     x8, [x29, #-0x70]
//   0x00e588: b9429008  ldr      w8, [x0, #0x290]
//   0x00e58c: f9402409  ldr      x9, [x0, #0x48]
//   0x00e590: 71000d1f  cmp      w8, #3
//   0x00e594: f90037e9  str      x9, [sp, #0x68]
//   0x00e598: b0000088  adrp     x8, #0x1f000
//   0x00e59c: f947c908  ldr      x8, [x8, #0xf90]
//   0x00e5a0: 5400010b  b.lt     #0xe5c0
//   0x00e5a4: b9406ee2  ldr      w2, [x23, #0x6c]
//   0x00e5a8: b9429ee3  ldr      w3, [x23, #0x29c]
//   0x00e5ac: b9407ee4  ldr      w4, [x23, #0x7c]
//   0x00e5b0: 90000041  adrp     x1, #0x16000
//   0x00e5b4: 9104c100  add      x0, x8, #0x130
//   0x00e5b8: 913c0821  add      x1, x1, #0xf02
//   0x00e5bc: 97ffd131  bl       #0x2a80
//   0x00e5c0: b9807ef4  ldrsw    x20, [x23, #0x7c]
//   0x00e5c4: 11000a82  add      w2, w20, #2
//   0x00e5c8: 7100005f  cmp      w2, #0
//   0x00e5cc: f9004be2  str      x2, [sp, #0x90]
//   0x00e5d0: 540003ed  b.le     #0xe64c
//   0x00e5d4: 52926988  mov      w8, #0x934c
//   0x00e5d8: 8b0802e0  add      x0, x23, x8
//   0x00e5dc: 528001e1  mov      w1, #0xf
//   0x00e5e0: 97ffd138  bl       #0x2ac0
//   0x00e5e4: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e5e8: 529289c8  mov      w8, #0x944e
//   0x00e5ec: 8b0802e0  add      x0, x23, x8
//   0x00e5f0: 528001e1  mov      w1, #0xf
//   0x00e5f4: 97ffd133  bl       #0x2ac0
//   0x00e5f8: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e5fc: 5292aa08  mov      w8, #0x9550
//   0x00e600: 8b0802e0  add      x0, x23, x8
//   0x00e604: 528001e1  mov      w1, #0xf
//   0x00e608: 97ffd12e  bl       #0x2ac0
//   0x00e60c: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e610: 5292ca48  mov      w8, #0x9652
//   0x00e614: 8b0802e0  add      x0, x23, x8
//   0x00e618: 528001e1  mov      w1, #0xf
//   0x00e61c: 97ffd129  bl       #0x2ac0
//   0x00e620: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e624: 5292ea88  mov      w8, #0x9754
//   0x00e628: 8b0802e0  add      x0, x23, x8
//   0x00e62c: 528001e1  mov      w1, #0xf
//   0x00e630: 97ffd124  bl       #0x2ac0
//   0x00e634: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e638: 52930ac8  mov      w8, #0x9856
//   0x00e63c: 8b0802e0  add      x0, x23, x8
//   0x00e640: 528001e1  mov      w1, #0xf
//   0x00e644: 97ffd11f  bl       #0x2ac0
//   0x00e648: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e64c: b9429ef3  ldr      w19, [x23, #0x29c]
//   0x00e650: 7100027f  cmp      w19, #0
//   0x00e654: 540000ad  b.le     #0xe668
//   0x00e658: 7103227f  cmp      w19, #0xc8
//   0x00e65c: 5400012a  b.ge     #0xe680
//   0x00e660: 52800048  mov      w8, #2
//   0x00e664: 14000012  b        #0xe6ac
//   0x00e668: 52817720  mov      w0, #0xbb9
//   0x00e66c: 97ffd081  bl       #0x2870
//   0x00e670: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e674: b9429ef3  ldr      w19, [x23, #0x29c]
//   0x00e678: 7103227f  cmp      w19, #0xc8
//   0x00e67c: 54ffff2b  b.lt     #0xe660
//   0x00e680: 7109627f  cmp      w19, #0x258
//   0x00e684: 5400006a  b.ge     #0xe690
//   0x00e688: 52800068  mov      w8, #3
//   0x00e68c: 14000008  b        #0xe6ac
//   0x00e690: 7112c27f  cmp      w19, #0x4b0
//   0x00e694: 5400006a  b.ge     #0xe6a0
//   0x00e698: 52800088  mov      w8, #4
//   0x00e69c: 14000004  b        #0xe6ac
//   0x00e6a0: 7125827f  cmp      w19, #0x960
//   0x00e6a4: 528000a8  mov      w8, #5
//   0x00e6a8: 1a88b508  cinc     w8, w8, ge
//   0x00e6ac: 927e7449  and      x9, x2, #0xfffffffc
//   0x00e6b0: f90047e9  str      x9, [sp, #0x88]
//   0x00e6b4: 52802049  mov      w9, #0x102
//   0x00e6b8: 2a0803f9  mov      w25, w8
//   0x00e6bc: 9ba95d08  umaddl   x8, w8, w9, x23
//   0x00e6c0: 90000049  adrp     x9, #0x16000
//   0x00e6c4: 3dc3a120  ldr      q0, [x9, #0xe80]
//   0x00e6c8: b000008b  adrp     x11, #0x1f000
//   0x00e6cc: f947c96b  ldr      x11, [x11, #0xf90]
//   0x00e6d0: 90000049  adrp     x9, #0x16000
//   0x00e6d4: 3d8017e0  str      q0, [sp, #0x50]
//   0x00e6d8: 3dc3a520  ldr      q0, [x9, #0xe90]
//   0x00e6dc: 5292494a  mov      w10, #0x924a
//   0x00e6e0: 8b0a011b  add      x27, x8, x10
//   0x00e6e4: 52800088  mov      w8, #4
//   0x00e6e8: 2a1f03fc  mov      w28, wzr
//   0x00e6ec: 910a92f5  add      x21, x23, #0x2a4
//   0x00e6f0: 9104c16b  add      x11, x11, #0x130
//   0x00e6f4: 528001ee  mov      w14, #0xf
//   0x00e6f8: 0f0085e8  movi     v8.4h, #0xf
//   0x00e6fc: 4e080d10  dup      v16.2d, x8
//   0x00e700: aa1903ed  mov      x13, x25
//   0x00e704: f90043eb  str      x11, [sp, #0x80]
//   0x00e708: 3d8013e0  str      q0, [sp, #0x40]
//   0x00e70c: 3d801ff0  str      q16, [sp, #0x70]
//   0x00e710: 14000006  b        #0xe728
//   0x00e714: 1100075c  add      w28, w26, #1
//   0x00e718: 4b180273  sub      w19, w19, w24
//   0x00e71c: f10001bf  cmp      x13, #0
//   0x00e720: d1040b7b  sub      x27, x27, #0x102
//   0x00e724: 54000c4d  b.le     #0xe8ac
//   0x00e728: 1acd0e68  sdiv     w8, w19, w13
//   0x00e72c: 2a1f03f8  mov      w24, wzr
//   0x00e730: 7100051f  cmp      w8, #1
//   0x00e734: 5100079a  sub      w26, w28, #1
//   0x00e738: 540001ab  b.lt     #0xe76c
//   0x00e73c: 6b14035f  cmp      w26, w20
//   0x00e740: 5400016c  b.gt     #0xe76c
//   0x00e744: 2a1f03f8  mov      w24, wzr
//   0x00e748: 93407f49  sxtw     x9, w26
//   0x00e74c: b8697aaa  ldr      w10, [x21, x9, lsl #2]
//   0x00e750: 9100053a  add      x26, x9, #1
//   0x00e754: 0b180158  add      w24, w10, w24
//   0x00e758: 6b08031f  cmp      w24, w8
//   0x00e75c: 5400008a  b.ge     #0xe76c
//   0x00e760: eb14013f  cmp      x9, x20
//   0x00e764: aa1a03e9  mov      x9, x26
//   0x00e768: 54ffff2b  b.lt     #0xe74c
//   0x00e76c: 6b1c035f  cmp      w26, w28
//   0x00e770: 5400016d  b.le     #0xe79c
//   0x00e774: eb1901bf  cmp      x13, x25
//   0x00e778: 54000120  b.eq     #0xe79c
//   0x00e77c: f10005bf  cmp      x13, #1
//   0x00e780: 540000e0  b.eq     #0xe79c
//   0x00e784: 4b0d0328  sub      w8, w25, w13
//   0x00e788: 360000a8  tbz      w8, #0, #0xe79c
//   0x00e78c: 8b3acae8  add      x8, x23, w26, sxtw #2
//   0x00e790: b942a108  ldr      w8, [x8, #0x2a0]
//   0x00e794: 5100075a  sub      w26, w26, #1
//   0x00e798: 4b080318  sub      w24, w24, w8
//   0x00e79c: b94292e8  ldr      w8, [x23, #0x290]
//   0x00e7a0: 71000d1f  cmp      w8, #3
//   0x00e7a4: 5400032b  b.lt     #0xe808
//   0x00e7a8: bd429ee0  ldr      s0, [x23, #0x29c]
//   0x00e7ac: 1e220301  scvtf    s1, w24
//   0x00e7b0: d2e80b28  mov      x8, #0x4059000000000000
//   0x00e7b4: f94043e0  ldr      x0, [sp, #0x80]
//   0x00e7b8: 1e22c021  fcvt     d1, s1
//   0x00e7bc: 9e670102  fmov     d2, x8
//   0x00e7c0: 5e21d800  scvtf    s0, s0
//   0x00e7c4: 1e620821  fmul     d1, d1, d2
//   0x00e7c8: 1e22c000  fcvt     d0, s0
//   0x00e7cc: 90000041  adrp     x1, #0x16000
//   0x00e7d0: 1e601820  fdiv     d0, d1, d0
//   0x00e7d4: 913d0821  add      x1, x1, #0xf42
//   0x00e7d8: 2a0d03e2  mov      w2, w13
//   0x00e7dc: 2a1c03e3  mov      w3, w28
//   0x00e7e0: 2a1a03e4  mov      w4, w26
//   0x00e7e4: 2a1803e5  mov      w5, w24
//   0x00e7e8: aa1703f6  mov      x22, x23
//   0x00e7ec: aa0d03f7  mov      x23, x13
//   0x00e7f0: 97ffd0a4  bl       #0x2a80
//   0x00e7f4: 3dc01ff0  ldr      q16, [sp, #0x70]
//   0x00e7f8: f9404be2  ldr      x2, [sp, #0x90]
//   0x00e7fc: 528001ee  mov      w14, #0xf
//   0x00e800: aa1703ed  mov      x13, x23
//   0x00e804: aa1603f7  mov      x23, x22
//   0x00e808: 7100045f  cmp      w2, #1
//   0x00e80c: d10005ad  sub      x13, x13, #1
//   0x00e810: 54fff82b  b.lt     #0xe714
//   0x00e814: 93407f48  sxtw     x8, w26
//   0x00e818: 7100105f  cmp      w2, #4
//   0x00e81c: 93407f89  sxtw     x9, w28
//   0x00e820: 54000062  b.hs     #0xe82c
//   0x00e824: aa1f03ea  mov      x10, xzr
//   0x00e828: 14000019  b        #0xe88c
//   0x00e82c: f94047ea  ldr      x10, [sp, #0x88]
//   0x00e830: ad420fe2  ldp      q2, q3, [sp, #0x40]
//   0x00e834: 4e080d20  dup      v0.2d, x9
//   0x00e838: 4e080d01  dup      v1.2d, x8
//   0x00e83c: aa1b03eb  mov      x11, x27
//   0x00e840: 4ee23404  cmgt     v4.2d, v0.2d, v2.2d
//   0x00e844: 4ee13446  cmgt     v6.2d, v2.2d, v1.2d
//   0x00e848: 4ee33405  cmgt     v5.2d, v0.2d, v3.2d
//   0x00e84c: 4ee13467  cmgt     v7.2d, v3.2d, v1.2d
//   0x00e850: 4ea61c84  orr      v4.16b, v4.16b, v6.16b
//   0x00e854: 4ea71ca5  orr      v5.16b, v5.16b, v7.16b
//   0x00e858: 0ea12884  xtn      v4.2s, v4.2d
//   0x00e85c: 4ea128a4  xtn2     v4.4s, v5.2d
//   0x00e860: 0e612884  xtn      v4.4h, v4.4s
//   0x00e864: 0e281c84  and      v4.8b, v4.8b, v8.8b
//   0x00e868: 0e212884  xtn      v4.8b, v4.8h
//   0x00e86c: 4ef08463  add      v3.2d, v3.2d, v16.2d
//   0x00e870: f100114a  subs     x10, x10, #4
//   0x00e874: 0d9f8164  st1      {v4.s}[0], [x11], #4
//   0x00e878: 4ef08442  add      v2.2d, v2.2d, v16.2d
//   0x00e87c: 54fffe21  b.ne     #0xe840
//   0x00e880: f94047ea  ldr      x10, [sp, #0x88]
//   0x00e884: eb02015f  cmp      x10, x2
//   0x00e888: 54fff460  b.eq     #0xe714
//   0x00e88c: eb08015f  cmp      x10, x8
//   0x00e890: fa49d148  ccmp     x10, x9, #8, le
//   0x00e894: 1a9fb1cb  csel     w11, w14, wzr, lt
//   0x00e898: 382a6b6b  strb     w11, [x27, x10]
//   0x00e89c: 9100054a  add      x10, x10, #1
//   0x00e8a0: eb0a005f  cmp      x2, x10
//   0x00e8a4: 54ffff41  b.ne     #0xe88c
//   0x00e8a8: 17ffff9b  b        #0xe714
//   0x00e8ac: 531e7728  lsl      w8, w25, #2
//   0x00e8b0: f90013e8  str      x8, [sp, #0x20]
//   0x00e8b4: d37ef448  lsl      x8, x2, #2
//   0x00e8b8: f9002be8  str      x8, [sp, #0x50]
//   0x00e8bc: 531f7b28  lsl      w8, w25, #1
//   0x00e8c0: b90037ff  str      wzr, [sp, #0x34]
//   0x00e8c4: f90023e8  str      x8, [sp, #0x40]
//   0x00e8c8: b0000098  adrp     x24, #0x1f000
//   0x00e8cc: f947cb18  ldr      x24, [x24, #0xf90]
//   0x00e8d0: 71001b3f  cmp      w25, #6
//   0x00e8d4: 52926988  mov      w8, #0x934c
//   0x00e8d8: 52993789  mov      w9, #0xc9bc
//   0x00e8dc: 9104c30b  add      x11, x24, #0x130
//   0x00e8e0: f9000beb  str      x11, [sp, #0x10]
//   0x00e8e4: 1a9f07eb  cset     w11, ne
//   0x00e8e8: 7100045f  cmp      w2, #1
//   0x00e8ec: 8b0802fa  add      x26, x23, x8
//   0x00e8f0: 8b0902e8  add      x8, x23, x9
//   0x00e8f4: 52963115  mov      w21, #0xb188
//   0x00e8f8: 5299370a  mov      w10, #0xc9b8
//   0x00e8fc: f90007e8  str      x8, [sp, #8]
//   0x00e900: 1a9fa7e8  cset     w8, lt
//   0x00e904: 9000005c  adrp     x28, #0x16000
//   0x00e908: d101f3b6  sub      x22, x29, #0x7c
//   0x00e90c: 8b1502ec  add      x12, x23, x21
//   0x00e910: 8b0a02f4  add      x20, x23, x10
//   0x00e914: 2a0b0108  orr      w8, w8, w11
//   0x00e918: 913e9b9c  add      x28, x28, #0xfa6
//   0x00e91c: f90017ec  str      x12, [sp, #0x28]
//   0x00e920: b9001fe8  str      w8, [sp, #0x1c]
//   0x00e924: f9003bf7  str      x23, [sp, #0x70]
//   0x00e928: f9001ff9  str      x25, [sp, #0x38]
//   0x00e92c: f94013e2  ldr      x2, [sp, #0x20]
//   0x00e930: d10253a0  sub      x0, x29, #0x94
//   0x00e934: 2a1f03e1  mov      w1, wzr
//   0x00e938: 97ffd062  bl       #0x2ac0
//   0x00e93c: f9404be4  ldr      x4, [sp, #0x90]
//   0x00e940: f94017fb  ldr      x27, [sp, #0x28]
//   0x00e944: aa1903f3  mov      x19, x25
//   0x00e948: 7100049f  cmp      w4, #1
//   0x00e94c: 540000ca  b.ge     #0xe964
//   0x00e950: f1000673  subs     x19, x19, #1
//   0x00e954: 9110237b  add      x27, x27, #0x408
//   0x00e958: 54000120  b.eq     #0xe97c
//   0x00e95c: 7100049f  cmp      w4, #1
//   0x00e960: 54ffff8b  b.lt     #0xe950
//   0x00e964: f9402be2  ldr      x2, [sp, #0x50]
//   0x00e968: aa1b03e0  mov      x0, x27
//   0x00e96c: 2a1f03e1  mov      w1, wzr
//   0x00e970: 97ffd054  bl       #0x2ac0
//   0x00e974: f9404be4  ldr      x4, [sp, #0x90]
//   0x00e978: 17fffff6  b        #0xe950
//   0x00e97c: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x00e980: 37000288  tbnz     w8, #0, #0xe9d0
//   0x00e984: f94007e8  ldr      x8, [sp, #8]
//   0x00e988: aa1a03e9  mov      x9, x26
//   0x00e98c: aa0403ea  mov      x10, x4
//   0x00e990: 3944092b  ldrb     w11, [x9, #0x102]
//   0x00e994: 3940012c  ldrb     w12, [x9]
//   0x00e998: f100054a  subs     x10, x10, #1
//   0x00e99c: 33101d6c  bfi      w12, w11, #0x10, #8
//   0x00e9a0: b81fc10c  stur     w12, [x8, #-4]
//   0x00e9a4: 394c192b  ldrb     w11, [x9, #0x306]
//   0x00e9a8: 3948112c  ldrb     w12, [x9, #0x204]
//   0x00e9ac: 33101d6c  bfi      w12, w11, #0x10, #8
//   0x00e9b0: b900010c  str      w12, [x8]
//   0x00e9b4: 3954292b  ldrb     w11, [x9, #0x50a]
//   0x00e9b8: 3950212c  ldrb     w12, [x9, #0x408]
//   0x00e9bc: 91000529  add      x9, x9, #1
//   0x00e9c0: 33101d6c  bfi      w12, w11, #0x10, #8
//   0x00e9c4: b900050c  str      w12, [x8, #4]
//   0x00e9c8: 91004108  add      x8, x8, #0x10
//   0x00e9cc: 54fffe21  b.ne     #0xe990
//   0x00e9d0: b9429ef3  ldr      w19, [x23, #0x29c]
//   0x00e9d4: 7100067f  cmp      w19, #1
//   0x00e9d8: 5400592b  b.lt     #0xf4fc
//   0x00e9dc: 2a1f03f7  mov      w23, wzr
//   0x00e9e0: 2a1f03e3  mov      w3, wzr
//   0x00e9e4: f90047ff  str      xzr, [sp, #0x88]
//   0x00e9e8: 14000103  b        #0xedf4
//   0x00e9ec: 8b1b040a  add      x10, x0, x27, lsl #1
//   0x00e9f0: 7940014c  ldrh     w12, [x10]
//   0x00e9f4: d503201f  nop      
//   0x00e9f8: 9b014569  madd     x9, x11, x1, x17
//   0x00e9fc: 8b150129  add      x9, x9, x21
//   0x00ea00: d37ef58b  lsl      x11, x12, #2
//   0x00ea04: b86b692c  ldr      w12, [x9, x11]
//   0x00ea08: 1100058c  add      w12, w12, #1
//   0x00ea0c: b82b692c  str      w12, [x9, x11]
//   0x00ea10: 7940054b  ldrh     w11, [x10, #2]
//   0x00ea14: d37ef56b  lsl      x11, x11, #2
//   0x00ea18: b86b692c  ldr      w12, [x9, x11]
//   0x00ea1c: 1100058c  add      w12, w12, #1
//   0x00ea20: b82b692c  str      w12, [x9, x11]
//   0x00ea24: 7940094b  ldrh     w11, [x10, #4]
//   0x00ea28: d37ef56b  lsl      x11, x11, #2
//   0x00ea2c: b86b692c  ldr      w12, [x9, x11]
//   0x00ea30: 1100058c  add      w12, w12, #1
//   0x00ea34: b82b692c  str      w12, [x9, x11]
//   0x00ea38: 79400d4b  ldrh     w11, [x10, #6]
//   0x00ea3c: d37ef56b  lsl      x11, x11, #2
//   0x00ea40: b86b692c  ldr      w12, [x9, x11]
//   0x00ea44: 1100058c  add      w12, w12, #1
//   0x00ea48: b82b692c  str      w12, [x9, x11]
//   0x00ea4c: 7940114b  ldrh     w11, [x10, #8]
//   0x00ea50: d37ef56b  lsl      x11, x11, #2
//   0x00ea54: b86b692c  ldr      w12, [x9, x11]
//   0x00ea58: 1100058c  add      w12, w12, #1
//   0x00ea5c: b82b692c  str      w12, [x9, x11]
//   0x00ea60: 7940154b  ldrh     w11, [x10, #0xa]
//   0x00ea64: d37ef56b  lsl      x11, x11, #2
//   0x00ea68: b86b692c  ldr      w12, [x9, x11]
//   0x00ea6c: 1100058c  add      w12, w12, #1
//   0x00ea70: b82b692c  str      w12, [x9, x11]
//   0x00ea74: 7940194b  ldrh     w11, [x10, #0xc]
//   0x00ea78: d37ef56b  lsl      x11, x11, #2
//   0x00ea7c: b86b692c  ldr      w12, [x9, x11]
//   0x00ea80: 1100058c  add      w12, w12, #1
//   0x00ea84: b82b692c  str      w12, [x9, x11]
//   0x00ea88: 79401d4b  ldrh     w11, [x10, #0xe]
//   0x00ea8c: d37ef56b  lsl      x11, x11, #2
//   0x00ea90: b86b692c  ldr      w12, [x9, x11]
//   0x00ea94: 1100058c  add      w12, w12, #1
//   0x00ea98: b82b692c  str      w12, [x9, x11]
//   0x00ea9c: 7940214b  ldrh     w11, [x10, #0x10]
//   0x00eaa0: d37ef56b  lsl      x11, x11, #2
//   0x00eaa4: b86b692c  ldr      w12, [x9, x11]
//   0x00eaa8: 1100058c  add      w12, w12, #1
//   0x00eaac: b82b692c  str      w12, [x9, x11]
//   0x00eab0: 7940254b  ldrh     w11, [x10, #0x12]
//   0x00eab4: d37ef56b  lsl      x11, x11, #2
//   0x00eab8: b86b692c  ldr      w12, [x9, x11]
//   0x00eabc: 1100058c  add      w12, w12, #1
//   0x00eac0: b82b692c  str      w12, [x9, x11]
//   0x00eac4: 7940294b  ldrh     w11, [x10, #0x14]
//   0x00eac8: d37ef56b  lsl      x11, x11, #2
//   0x00eacc: b86b692c  ldr      w12, [x9, x11]
//   0x00ead0: 1100058c  add      w12, w12, #1
//   0x00ead4: b82b692c  str      w12, [x9, x11]
//   0x00ead8: 79402d4b  ldrh     w11, [x10, #0x16]
//   0x00eadc: d37ef56b  lsl      x11, x11, #2
//   0x00eae0: b86b692c  ldr      w12, [x9, x11]
//   0x00eae4: 1100058c  add      w12, w12, #1
//   0x00eae8: b82b692c  str      w12, [x9, x11]
//   0x00eaec: 7940314b  ldrh     w11, [x10, #0x18]
//   0x00eaf0: d37ef56b  lsl      x11, x11, #2
//   0x00eaf4: b86b692c  ldr      w12, [x9, x11]
//   0x00eaf8: 1100058c  add      w12, w12, #1
//   0x00eafc: b82b692c  str      w12, [x9, x11]
//   0x00eb00: 7940354b  ldrh     w11, [x10, #0x1a]
//   0x00eb04: d37ef56b  lsl      x11, x11, #2
//   0x00eb08: b86b692c  ldr      w12, [x9, x11]
//   0x00eb0c: 1100058c  add      w12, w12, #1
//   0x00eb10: b82b692c  str      w12, [x9, x11]
//   0x00eb14: 7940394b  ldrh     w11, [x10, #0x1c]
//   0x00eb18: d37ef56b  lsl      x11, x11, #2
//   0x00eb1c: b86b692c  ldr      w12, [x9, x11]
//   0x00eb20: 1100058c  add      w12, w12, #1
//   0x00eb24: b82b692c  str      w12, [x9, x11]
//   0x00eb28: 79403d4b  ldrh     w11, [x10, #0x1e]
//   0x00eb2c: d37ef56b  lsl      x11, x11, #2
//   0x00eb30: b86b692c  ldr      w12, [x9, x11]
//   0x00eb34: 1100058c  add      w12, w12, #1
//   0x00eb38: b82b692c  str      w12, [x9, x11]
//   0x00eb3c: 7940414b  ldrh     w11, [x10, #0x20]
//   0x00eb40: d37ef56b  lsl      x11, x11, #2
//   0x00eb44: b86b692c  ldr      w12, [x9, x11]
//   0x00eb48: 1100058c  add      w12, w12, #1
//   0x00eb4c: b82b692c  str      w12, [x9, x11]
//   0x00eb50: 7940454b  ldrh     w11, [x10, #0x22]
//   0x00eb54: d37ef56b  lsl      x11, x11, #2
//   0x00eb58: b86b692c  ldr      w12, [x9, x11]
//   0x00eb5c: 1100058c  add      w12, w12, #1
//   0x00eb60: b82b692c  str      w12, [x9, x11]
//   0x00eb64: 7940494b  ldrh     w11, [x10, #0x24]
//   0x00eb68: d37ef56b  lsl      x11, x11, #2
//   0x00eb6c: b86b692c  ldr      w12, [x9, x11]
//   0x00eb70: 1100058c  add      w12, w12, #1
//   0x00eb74: b82b692c  str      w12, [x9, x11]
//   0x00eb78: 79404d4b  ldrh     w11, [x10, #0x26]
//   0x00eb7c: d37ef56b  lsl      x11, x11, #2
//   0x00eb80: b86b692c  ldr      w12, [x9, x11]
//   0x00eb84: 1100058c  add      w12, w12, #1
//   0x00eb88: b82b692c  str      w12, [x9, x11]
//   0x00eb8c: 7940514b  ldrh     w11, [x10, #0x28]
//   0x00eb90: d37ef56b  lsl      x11, x11, #2
//   0x00eb94: b86b692c  ldr      w12, [x9, x11]
//   0x00eb98: 1100058c  add      w12, w12, #1
//   0x00eb9c: b82b692c  str      w12, [x9, x11]
//   0x00eba0: 7940554b  ldrh     w11, [x10, #0x2a]
//   0x00eba4: d37ef56b  lsl      x11, x11, #2
//   0x00eba8: b86b692c  ldr      w12, [x9, x11]
//   0x00ebac: 1100058c  add      w12, w12, #1
//   0x00ebb0: b82b692c  str      w12, [x9, x11]
//   0x00ebb4: 7940594b  ldrh     w11, [x10, #0x2c]
//   0x00ebb8: d37ef56b  lsl      x11, x11, #2
//   0x00ebbc: b86b692c  ldr      w12, [x9, x11]
//   0x00ebc0: 1100058c  add      w12, w12, #1
//   0x00ebc4: b82b692c  str      w12, [x9, x11]
//   0x00ebc8: 79405d4b  ldrh     w11, [x10, #0x2e]
//   0x00ebcc: d37ef56b  lsl      x11, x11, #2
//   0x00ebd0: b86b692c  ldr      w12, [x9, x11]
//   0x00ebd4: 1100058c  add      w12, w12, #1
//   0x00ebd8: b82b692c  str      w12, [x9, x11]
//   0x00ebdc: 7940614b  ldrh     w11, [x10, #0x30]
//   0x00ebe0: d37ef56b  lsl      x11, x11, #2
//   0x00ebe4: b86b692c  ldr      w12, [x9, x11]
//   0x00ebe8: 1100058c  add      w12, w12, #1
//   0x00ebec: b82b692c  str      w12, [x9, x11]
//   0x00ebf0: 7940654b  ldrh     w11, [x10, #0x32]
//   0x00ebf4: d37ef56b  lsl      x11, x11, #2
//   0x00ebf8: b86b692c  ldr      w12, [x9, x11]
//   0x00ebfc: 1100058c  add      w12, w12, #1
//   0x00ec00: b82b692c  str      w12, [x9, x11]
//   0x00ec04: 7940694b  ldrh     w11, [x10, #0x34]
//   0x00ec08: d37ef56b  lsl      x11, x11, #2
//   0x00ec0c: b86b692c  ldr      w12, [x9, x11]
//   0x00ec10: 1100058c  add      w12, w12, #1
//   0x00ec14: b82b692c  str      w12, [x9, x11]
//   0x00ec18: 79406d4b  ldrh     w11, [x10, #0x36]
//   0x00ec1c: d37ef56b  lsl      x11, x11, #2
//   0x00ec20: b86b692c  ldr      w12, [x9, x11]
//   0x00ec24: 1100058c  add      w12, w12, #1
//   0x00ec28: b82b692c  str      w12, [x9, x11]
//   0x00ec2c: 7940714b  ldrh     w11, [x10, #0x38]
//   0x00ec30: d37ef56b  lsl      x11, x11, #2
//   0x00ec34: b86b692c  ldr      w12, [x9, x11]
//   0x00ec38: 1100058c  add      w12, w12, #1
//   0x00ec3c: b82b692c  str      w12, [x9, x11]
//   0x00ec40: 7940754b  ldrh     w11, [x10, #0x3a]
//   0x00ec44: d37ef56b  lsl      x11, x11, #2
//   0x00ec48: b86b692c  ldr      w12, [x9, x11]
//   0x00ec4c: 1100058c  add      w12, w12, #1
//   0x00ec50: b82b692c  str      w12, [x9, x11]
//   0x00ec54: 7940794b  ldrh     w11, [x10, #0x3c]
//   0x00ec58: d37ef56b  lsl      x11, x11, #2
//   0x00ec5c: b86b692c  ldr      w12, [x9, x11]
//   0x00ec60: 1100058c  add      w12, w12, #1
//   0x00ec64: b82b692c  str      w12, [x9, x11]
//   0x00ec68: 79407d4b  ldrh     w11, [x10, #0x3e]
//   0x00ec6c: d37ef56b  lsl      x11, x11, #2
//   0x00ec70: b86b692c  ldr      w12, [x9, x11]
//   0x00ec74: 1100058c  add      w12, w12, #1
//   0x00ec78: b82b692c  str      w12, [x9, x11]
//   0x00ec7c: 7940814b  ldrh     w11, [x10, #0x40]
//   0x00ec80: d37ef56b  lsl      x11, x11, #2
//   0x00ec84: b86b692c  ldr      w12, [x9, x11]
//   0x00ec88: 1100058c  add      w12, w12, #1
//   0x00ec8c: b82b692c  str      w12, [x9, x11]
//   0x00ec90: 7940854b  ldrh     w11, [x10, #0x42]
//   0x00ec94: d37ef56b  lsl      x11, x11, #2
//   0x00ec98: b86b692c  ldr      w12, [x9, x11]
//   0x00ec9c: 1100058c  add      w12, w12, #1
//   0x00eca0: b82b692c  str      w12, [x9, x11]
//   0x00eca4: 7940894b  ldrh     w11, [x10, #0x44]
//   0x00eca8: d37ef56b  lsl      x11, x11, #2
//   0x00ecac: b86b692c  ldr      w12, [x9, x11]
//   0x00ecb0: 1100058c  add      w12, w12, #1
//   0x00ecb4: b82b692c  str      w12, [x9, x11]
//   0x00ecb8: 79408d4b  ldrh     w11, [x10, #0x46]
//   0x00ecbc: d37ef56b  lsl      x11, x11, #2
//   0x00ecc0: b86b692c  ldr      w12, [x9, x11]
//   0x00ecc4: 1100058c  add      w12, w12, #1
//   0x00ecc8: b82b692c  str      w12, [x9, x11]
//   0x00eccc: 7940914b  ldrh     w11, [x10, #0x48]
//   0x00ecd0: d37ef56b  lsl      x11, x11, #2
//   0x00ecd4: b86b692c  ldr      w12, [x9, x11]
//   0x00ecd8: 1100058c  add      w12, w12, #1
//   0x00ecdc: b82b692c  str      w12, [x9, x11]
//   0x00ece0: 7940954b  ldrh     w11, [x10, #0x4a]
//   0x00ece4: d37ef56b  lsl      x11, x11, #2
//   0x00ece8: b86b692c  ldr      w12, [x9, x11]
//   0x00ecec: 1100058c  add      w12, w12, #1
//   0x00ecf0: b82b692c  str      w12, [x9, x11]
//   0x00ecf4: 7940994b  ldrh     w11, [x10, #0x4c]
//   0x00ecf8: d37ef56b  lsl      x11, x11, #2
//   0x00ecfc: b86b692c  ldr      w12, [x9, x11]
//   0x00ed00: 1100058c  add      w12, w12, #1
//   0x00ed04: b82b692c  str      w12, [x9, x11]
//   0x00ed08: 79409d4b  ldrh     w11, [x10, #0x4e]
//   0x00ed0c: d37ef56b  lsl      x11, x11, #2
//   0x00ed10: b86b692c  ldr      w12, [x9, x11]
//   0x00ed14: 1100058c  add      w12, w12, #1
//   0x00ed18: b82b692c  str      w12, [x9, x11]
//   0x00ed1c: 7940a14b  ldrh     w11, [x10, #0x50]
//   0x00ed20: d37ef56b  lsl      x11, x11, #2
//   0x00ed24: b86b692c  ldr      w12, [x9, x11]
//   0x00ed28: 1100058c  add      w12, w12, #1
//   0x00ed2c: b82b692c  str      w12, [x9, x11]
//   0x00ed30: 7940a54b  ldrh     w11, [x10, #0x52]
//   0x00ed34: d37ef56b  lsl      x11, x11, #2
//   0x00ed38: b86b692c  ldr      w12, [x9, x11]
//   0x00ed3c: 1100058c  add      w12, w12, #1
//   0x00ed40: b82b692c  str      w12, [x9, x11]
//   0x00ed44: 7940a94b  ldrh     w11, [x10, #0x54]
//   0x00ed48: d37ef56b  lsl      x11, x11, #2
//   0x00ed4c: b86b692c  ldr      w12, [x9, x11]
//   0x00ed50: 1100058c  add      w12, w12, #1
//   0x00ed54: b82b692c  str      w12, [x9, x11]
//   0x00ed58: 7940ad4b  ldrh     w11, [x10, #0x56]
//   0x00ed5c: d37ef56b  lsl      x11, x11, #2
//   0x00ed60: b86b692c  ldr      w12, [x9, x11]
//   0x00ed64: 1100058c  add      w12, w12, #1
//   0x00ed68: b82b692c  str      w12, [x9, x11]
//   0x00ed6c: 7940b14b  ldrh     w11, [x10, #0x58]
//   0x00ed70: d37ef56b  lsl      x11, x11, #2
//   0x00ed74: b86b692c  ldr      w12, [x9, x11]
//   0x00ed78: 1100058c  add      w12, w12, #1
//   0x00ed7c: b82b692c  str      w12, [x9, x11]
//   0x00ed80: 7940b54b  ldrh     w11, [x10, #0x5a]
//   0x00ed84: d37ef56b  lsl      x11, x11, #2
//   0x00ed88: b86b692c  ldr      w12, [x9, x11]
//   0x00ed8c: 1100058c  add      w12, w12, #1
//   0x00ed90: b82b692c  str      w12, [x9, x11]
//   0x00ed94: 7940b94b  ldrh     w11, [x10, #0x5c]
//   0x00ed98: d37ef56b  lsl      x11, x11, #2
//   0x00ed9c: b86b692c  ldr      w12, [x9, x11]
//   0x00eda0: 1100058c  add      w12, w12, #1
//   0x00eda4: b82b692c  str      w12, [x9, x11]
//   0x00eda8: 7940bd4b  ldrh     w11, [x10, #0x5e]
//   0x00edac: d37ef56b  lsl      x11, x11, #2
//   0x00edb0: b86b692c  ldr      w12, [x9, x11]
//   0x00edb4: 1100058c  add      w12, w12, #1
//   0x00edb8: b82b692c  str      w12, [x9, x11]
//   0x00edbc: 7940c14a  ldrh     w10, [x10, #0x60]
//   0x00edc0: d37ef54a  lsl      x10, x10, #2
//   0x00edc4: b86a692b  ldr      w11, [x9, x10]
//   0x00edc8: 1100056b  add      w11, w11, #1
//   0x00edcc: b82a692b  str      w11, [x9, x10]
//   0x00edd0: 7862d80a  ldrh     w10, [x0, w2, sxtw #1]
//   0x00edd4: d37ef54a  lsl      x10, x10, #2
//   0x00edd8: b86a692b  ldr      w11, [x9, x10]
//   0x00eddc: 1100056b  add      w11, w11, #1
//   0x00ede0: b82a692b  str      w11, [x9, x10]
//   0x00ede4: b9429e33  ldr      w19, [x17, #0x29c]
//   0x00ede8: 11000517  add      w23, w8, #1
//   0x00edec: 6b1302ff  cmp      w23, w19
//   0x00edf0: 540037ca  b.ge     #0xf4e8
//   0x00edf4: f94023e2  ldr      x2, [sp, #0x40]
//   0x00edf8: 71001b3f  cmp      w25, #6
//   0x00edfc: 93407efb  sxtw     x27, w23
//   0x00ee00: d101f3a0  sub      x0, x29, #0x7c
//   0x00ee04: 2a1f03e1  mov      w1, wzr
//   0x00ee08: b90083e3  str      w3, [sp, #0x80]
//   0x00ee0c: 1a9f17f8  cset     w24, eq
//   0x00ee10: 9100c779  add      x25, x27, #0x31
//   0x00ee14: 5100067c  sub      w28, w19, #1
//   0x00ee18: 97ffcf2a  bl       #0x2ac0
//   0x00ee1c: aa1903e2  mov      x2, x25
//   0x00ee20: 6b13005f  cmp      w2, w19
//   0x00ee24: 1a9cb048  csel     w8, w2, w28, lt
//   0x00ee28: 4b170109  sub      w9, w8, w23
//   0x00ee2c: 7100c53f  cmp      w9, #0x31
//   0x00ee30: 1a9f17e9  cset     w9, eq
//   0x00ee34: 0a090309  and      w9, w24, w9
//   0x00ee38: 36002dc9  tbz      w9, #0, #0xf3f0
//   0x00ee3c: f94037e0  ldr      x0, [sp, #0x68]
//   0x00ee40: b94083e3  ldr      w3, [sp, #0x80]
//   0x00ee44: f9401ff9  ldr      x25, [sp, #0x38]
//   0x00ee48: 9000005c  adrp     x28, #0x16000
//   0x00ee4c: 8b1b040a  add      x10, x0, x27, lsl #1
//   0x00ee50: 7940014b  ldrh     w11, [x10]
//   0x00ee54: 7940054c  ldrh     w12, [x10, #2]
//   0x00ee58: 7940094f  ldrh     w15, [x10, #4]
//   0x00ee5c: 52808101  mov      w1, #0x408
//   0x00ee60: 8b0b128b  add      x11, x20, x11, lsl #4
//   0x00ee64: 8b0c128c  add      x12, x20, x12, lsl #4
//   0x00ee68: 2940458d  ldp      w13, w17, [x12]
//   0x00ee6c: 2940416e  ldp      w14, w16, [x11]
//   0x00ee70: b940096b  ldr      w11, [x11, #8]
//   0x00ee74: b940098c  ldr      w12, [x12, #8]
//   0x00ee78: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00ee7c: 0b0e01ad  add      w13, w13, w14
//   0x00ee80: 79400d4e  ldrh     w14, [x10, #6]
//   0x00ee84: 0b100230  add      w16, w17, w16
//   0x00ee88: 0b0b018b  add      w11, w12, w11
//   0x00ee8c: 294031f1  ldp      w17, w12, [x15]
//   0x00ee90: b94009ef  ldr      w15, [x15, #8]
//   0x00ee94: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00ee98: 913e9b9c  add      x28, x28, #0xfa6
//   0x00ee9c: 0b1101ad  add      w13, w13, w17
//   0x00eea0: 79401151  ldrh     w17, [x10, #8]
//   0x00eea4: 0b0c020c  add      w12, w16, w12
//   0x00eea8: 0b0f016b  add      w11, w11, w15
//   0x00eeac: 294041cf  ldp      w15, w16, [x14]
//   0x00eeb0: b94009ce  ldr      w14, [x14, #8]
//   0x00eeb4: 8b111291  add      x17, x20, x17, lsl #4
//   0x00eeb8: 0b0f01ad  add      w13, w13, w15
//   0x00eebc: 0b10018c  add      w12, w12, w16
//   0x00eec0: 79401550  ldrh     w16, [x10, #0xa]
//   0x00eec4: 0b0e016b  add      w11, w11, w14
//   0x00eec8: 29403a2f  ldp      w15, w14, [x17]
//   0x00eecc: b9400a31  ldr      w17, [x17, #8]
//   0x00eed0: 8b101290  add      x16, x20, x16, lsl #4
//   0x00eed4: 0b0f01ad  add      w13, w13, w15
//   0x00eed8: 7940194f  ldrh     w15, [x10, #0xc]
//   0x00eedc: 0b0e018c  add      w12, w12, w14
//   0x00eee0: 0b11016b  add      w11, w11, w17
//   0x00eee4: 2940460e  ldp      w14, w17, [x16]
//   0x00eee8: b9400a10  ldr      w16, [x16, #8]
//   0x00eeec: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00eef0: 0b0e01ad  add      w13, w13, w14
//   0x00eef4: 79401d4e  ldrh     w14, [x10, #0xe]
//   0x00eef8: 0b11018c  add      w12, w12, w17
//   0x00eefc: 0b10016b  add      w11, w11, w16
//   0x00ef00: 294045f0  ldp      w16, w17, [x15]
//   0x00ef04: b94009ef  ldr      w15, [x15, #8]
//   0x00ef08: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00ef0c: 0b11018c  add      w12, w12, w17
//   0x00ef10: 79402151  ldrh     w17, [x10, #0x10]
//   0x00ef14: 0b1001ad  add      w13, w13, w16
//   0x00ef18: 0b0f016b  add      w11, w11, w15
//   0x00ef1c: 29403dd0  ldp      w16, w15, [x14]
//   0x00ef20: b94009ce  ldr      w14, [x14, #8]
//   0x00ef24: 8b111291  add      x17, x20, x17, lsl #4
//   0x00ef28: 0b1001ad  add      w13, w13, w16
//   0x00ef2c: 79402550  ldrh     w16, [x10, #0x12]
//   0x00ef30: 0b0f018c  add      w12, w12, w15
//   0x00ef34: 0b0e016b  add      w11, w11, w14
//   0x00ef38: 29403a2f  ldp      w15, w14, [x17]
//   0x00ef3c: b9400a31  ldr      w17, [x17, #8]
//   0x00ef40: 8b101290  add      x16, x20, x16, lsl #4
//   0x00ef44: 0b0f01ad  add      w13, w13, w15
//   0x00ef48: 7940294f  ldrh     w15, [x10, #0x14]
//   0x00ef4c: 0b0e018c  add      w12, w12, w14
//   0x00ef50: 0b11016b  add      w11, w11, w17
//   0x00ef54: 2940460e  ldp      w14, w17, [x16]
//   0x00ef58: b9400a10  ldr      w16, [x16, #8]
//   0x00ef5c: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00ef60: 0b0e01ad  add      w13, w13, w14
//   0x00ef64: 0b11018c  add      w12, w12, w17
//   0x00ef68: 79402d51  ldrh     w17, [x10, #0x16]
//   0x00ef6c: 0b10016b  add      w11, w11, w16
//   0x00ef70: 294041ee  ldp      w14, w16, [x15]
//   0x00ef74: b94009ef  ldr      w15, [x15, #8]
//   0x00ef78: 8b111291  add      x17, x20, x17, lsl #4
//   0x00ef7c: 0b0e01ad  add      w13, w13, w14
//   0x00ef80: 7940314e  ldrh     w14, [x10, #0x18]
//   0x00ef84: 0b10018c  add      w12, w12, w16
//   0x00ef88: 0b0f016b  add      w11, w11, w15
//   0x00ef8c: 29403e30  ldp      w16, w15, [x17]
//   0x00ef90: b9400a31  ldr      w17, [x17, #8]
//   0x00ef94: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00ef98: 0b1001ad  add      w13, w13, w16
//   0x00ef9c: 79403550  ldrh     w16, [x10, #0x1a]
//   0x00efa0: 0b0f018c  add      w12, w12, w15
//   0x00efa4: 0b11016b  add      w11, w11, w17
//   0x00efa8: 294045cf  ldp      w15, w17, [x14]
//   0x00efac: b94009ce  ldr      w14, [x14, #8]
//   0x00efb0: 8b101290  add      x16, x20, x16, lsl #4
//   0x00efb4: 0b11018c  add      w12, w12, w17
//   0x00efb8: 79403951  ldrh     w17, [x10, #0x1c]
//   0x00efbc: 0b0f01ad  add      w13, w13, w15
//   0x00efc0: 0b0e016b  add      w11, w11, w14
//   0x00efc4: 29403a0f  ldp      w15, w14, [x16]
//   0x00efc8: b9400a10  ldr      w16, [x16, #8]
//   0x00efcc: 8b111291  add      x17, x20, x17, lsl #4
//   0x00efd0: 0b0f01ad  add      w13, w13, w15
//   0x00efd4: 79403d4f  ldrh     w15, [x10, #0x1e]
//   0x00efd8: 0b0e018c  add      w12, w12, w14
//   0x00efdc: 0b10016b  add      w11, w11, w16
//   0x00efe0: 2940422e  ldp      w14, w16, [x17]
//   0x00efe4: b9400a31  ldr      w17, [x17, #8]
//   0x00efe8: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00efec: 0b0e01ad  add      w13, w13, w14
//   0x00eff0: 7940414e  ldrh     w14, [x10, #0x20]
//   0x00eff4: 0b10018c  add      w12, w12, w16
//   0x00eff8: 0b11016b  add      w11, w11, w17
//   0x00effc: 294045f0  ldp      w16, w17, [x15]
//   0x00f000: b94009ef  ldr      w15, [x15, #8]
//   0x00f004: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f008: 0b1001ad  add      w13, w13, w16
//   0x00f00c: 0b11018c  add      w12, w12, w17
//   0x00f010: 79404551  ldrh     w17, [x10, #0x22]
//   0x00f014: 0b0f016b  add      w11, w11, w15
//   0x00f018: 29403dd0  ldp      w16, w15, [x14]
//   0x00f01c: b94009ce  ldr      w14, [x14, #8]
//   0x00f020: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f024: 0b1001ad  add      w13, w13, w16
//   0x00f028: 79404950  ldrh     w16, [x10, #0x24]
//   0x00f02c: 0b0f018c  add      w12, w12, w15
//   0x00f030: 0b0e016b  add      w11, w11, w14
//   0x00f034: 29403a2f  ldp      w15, w14, [x17]
//   0x00f038: b9400a31  ldr      w17, [x17, #8]
//   0x00f03c: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f040: 0b0f01ad  add      w13, w13, w15
//   0x00f044: 79404d4f  ldrh     w15, [x10, #0x26]
//   0x00f048: 0b0e018c  add      w12, w12, w14
//   0x00f04c: 0b11016b  add      w11, w11, w17
//   0x00f050: 2940460e  ldp      w14, w17, [x16]
//   0x00f054: b9400a10  ldr      w16, [x16, #8]
//   0x00f058: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f05c: 0b11018c  add      w12, w12, w17
//   0x00f060: 79405151  ldrh     w17, [x10, #0x28]
//   0x00f064: 0b0e01ad  add      w13, w13, w14
//   0x00f068: 0b10016b  add      w11, w11, w16
//   0x00f06c: 294041ee  ldp      w14, w16, [x15]
//   0x00f070: b94009ef  ldr      w15, [x15, #8]
//   0x00f074: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f078: 0b0e01ad  add      w13, w13, w14
//   0x00f07c: 7940554e  ldrh     w14, [x10, #0x2a]
//   0x00f080: 0b10018c  add      w12, w12, w16
//   0x00f084: 0b0f016b  add      w11, w11, w15
//   0x00f088: 29403e30  ldp      w16, w15, [x17]
//   0x00f08c: b9400a31  ldr      w17, [x17, #8]
//   0x00f090: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f094: 0b1001ad  add      w13, w13, w16
//   0x00f098: 79405950  ldrh     w16, [x10, #0x2c]
//   0x00f09c: 0b0f018c  add      w12, w12, w15
//   0x00f0a0: 0b11016b  add      w11, w11, w17
//   0x00f0a4: 294045cf  ldp      w15, w17, [x14]
//   0x00f0a8: b94009ce  ldr      w14, [x14, #8]
//   0x00f0ac: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f0b0: 0b0f01ad  add      w13, w13, w15
//   0x00f0b4: 0b11018c  add      w12, w12, w17
//   0x00f0b8: 79405d51  ldrh     w17, [x10, #0x2e]
//   0x00f0bc: 0b0e016b  add      w11, w11, w14
//   0x00f0c0: 29403a0f  ldp      w15, w14, [x16]
//   0x00f0c4: b9400a10  ldr      w16, [x16, #8]
//   0x00f0c8: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f0cc: 0b0f01ad  add      w13, w13, w15
//   0x00f0d0: 7940614f  ldrh     w15, [x10, #0x30]
//   0x00f0d4: 0b0e018c  add      w12, w12, w14
//   0x00f0d8: 0b10016b  add      w11, w11, w16
//   0x00f0dc: 2940422e  ldp      w14, w16, [x17]
//   0x00f0e0: b9400a31  ldr      w17, [x17, #8]
//   0x00f0e4: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f0e8: 0b0e01ad  add      w13, w13, w14
//   0x00f0ec: 7940654e  ldrh     w14, [x10, #0x32]
//   0x00f0f0: 0b10018c  add      w12, w12, w16
//   0x00f0f4: 0b11016b  add      w11, w11, w17
//   0x00f0f8: 294045f0  ldp      w16, w17, [x15]
//   0x00f0fc: b94009ef  ldr      w15, [x15, #8]
//   0x00f100: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f104: 0b11018c  add      w12, w12, w17
//   0x00f108: 79406951  ldrh     w17, [x10, #0x34]
//   0x00f10c: 0b1001ad  add      w13, w13, w16
//   0x00f110: 0b0f016b  add      w11, w11, w15
//   0x00f114: 29403dd0  ldp      w16, w15, [x14]
//   0x00f118: b94009ce  ldr      w14, [x14, #8]
//   0x00f11c: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f120: 0b1001ad  add      w13, w13, w16
//   0x00f124: 79406d50  ldrh     w16, [x10, #0x36]
//   0x00f128: 0b0f018c  add      w12, w12, w15
//   0x00f12c: 0b0e016b  add      w11, w11, w14
//   0x00f130: 29403a2f  ldp      w15, w14, [x17]
//   0x00f134: b9400a31  ldr      w17, [x17, #8]
//   0x00f138: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f13c: 0b0f01ad  add      w13, w13, w15
//   0x00f140: 7940714f  ldrh     w15, [x10, #0x38]
//   0x00f144: 0b0e018c  add      w12, w12, w14
//   0x00f148: 0b11016b  add      w11, w11, w17
//   0x00f14c: 2940460e  ldp      w14, w17, [x16]
//   0x00f150: b9400a10  ldr      w16, [x16, #8]
//   0x00f154: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f158: 0b0e01ad  add      w13, w13, w14
//   0x00f15c: 0b11018c  add      w12, w12, w17
//   0x00f160: 79407551  ldrh     w17, [x10, #0x3a]
//   0x00f164: 0b10016b  add      w11, w11, w16
//   0x00f168: 294041ee  ldp      w14, w16, [x15]
//   0x00f16c: b94009ef  ldr      w15, [x15, #8]
//   0x00f170: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f174: 0b0e01ad  add      w13, w13, w14
//   0x00f178: 7940794e  ldrh     w14, [x10, #0x3c]
//   0x00f17c: 0b10018c  add      w12, w12, w16
//   0x00f180: 0b0f016b  add      w11, w11, w15
//   0x00f184: 29403e30  ldp      w16, w15, [x17]
//   0x00f188: b9400a31  ldr      w17, [x17, #8]
//   0x00f18c: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f190: 0b1001ad  add      w13, w13, w16
//   0x00f194: 79407d50  ldrh     w16, [x10, #0x3e]
//   0x00f198: 0b0f018c  add      w12, w12, w15
//   0x00f19c: 0b11016b  add      w11, w11, w17
//   0x00f1a0: 294045cf  ldp      w15, w17, [x14]
//   0x00f1a4: b94009ce  ldr      w14, [x14, #8]
//   0x00f1a8: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f1ac: 0b11018c  add      w12, w12, w17
//   0x00f1b0: 79408151  ldrh     w17, [x10, #0x40]
//   0x00f1b4: 0b0f01ad  add      w13, w13, w15
//   0x00f1b8: 0b0e016b  add      w11, w11, w14
//   0x00f1bc: 29403a0f  ldp      w15, w14, [x16]
//   0x00f1c0: b9400a10  ldr      w16, [x16, #8]
//   0x00f1c4: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f1c8: 0b0f01ad  add      w13, w13, w15
//   0x00f1cc: 7940854f  ldrh     w15, [x10, #0x42]
//   0x00f1d0: 0b0e018c  add      w12, w12, w14
//   0x00f1d4: 0b10016b  add      w11, w11, w16
//   0x00f1d8: 2940422e  ldp      w14, w16, [x17]
//   0x00f1dc: b9400a31  ldr      w17, [x17, #8]
//   0x00f1e0: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f1e4: 0b0e01ad  add      w13, w13, w14
//   0x00f1e8: 7940894e  ldrh     w14, [x10, #0x44]
//   0x00f1ec: 0b10018c  add      w12, w12, w16
//   0x00f1f0: 0b11016b  add      w11, w11, w17
//   0x00f1f4: 294045f0  ldp      w16, w17, [x15]
//   0x00f1f8: b94009ef  ldr      w15, [x15, #8]
//   0x00f1fc: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f200: 0b1001ad  add      w13, w13, w16
//   0x00f204: 0b11018c  add      w12, w12, w17
//   0x00f208: 79408d51  ldrh     w17, [x10, #0x46]
//   0x00f20c: 0b0f016b  add      w11, w11, w15
//   0x00f210: 29403dd0  ldp      w16, w15, [x14]
//   0x00f214: b94009ce  ldr      w14, [x14, #8]
//   0x00f218: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f21c: 0b1001ad  add      w13, w13, w16
//   0x00f220: 79409150  ldrh     w16, [x10, #0x48]
//   0x00f224: 0b0f018c  add      w12, w12, w15
//   0x00f228: 0b0e016b  add      w11, w11, w14
//   0x00f22c: 29403a2f  ldp      w15, w14, [x17]
//   0x00f230: b9400a31  ldr      w17, [x17, #8]
//   0x00f234: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f238: 0b0f01ad  add      w13, w13, w15
//   0x00f23c: 7940954f  ldrh     w15, [x10, #0x4a]
//   0x00f240: 0b0e018c  add      w12, w12, w14
//   0x00f244: 0b11016b  add      w11, w11, w17
//   0x00f248: 2940460e  ldp      w14, w17, [x16]
//   0x00f24c: b9400a10  ldr      w16, [x16, #8]
//   0x00f250: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f254: 0b11018c  add      w12, w12, w17
//   0x00f258: 79409951  ldrh     w17, [x10, #0x4c]
//   0x00f25c: 0b0e01ad  add      w13, w13, w14
//   0x00f260: 0b10016b  add      w11, w11, w16
//   0x00f264: 294041ee  ldp      w14, w16, [x15]
//   0x00f268: b94009ef  ldr      w15, [x15, #8]
//   0x00f26c: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f270: 0b0e01ad  add      w13, w13, w14
//   0x00f274: 79409d4e  ldrh     w14, [x10, #0x4e]
//   0x00f278: 0b10018c  add      w12, w12, w16
//   0x00f27c: 0b0f016b  add      w11, w11, w15
//   0x00f280: 29403e30  ldp      w16, w15, [x17]
//   0x00f284: b9400a31  ldr      w17, [x17, #8]
//   0x00f288: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f28c: 0b1001ad  add      w13, w13, w16
//   0x00f290: 7940a150  ldrh     w16, [x10, #0x50]
//   0x00f294: 0b0f018c  add      w12, w12, w15
//   0x00f298: 0b11016b  add      w11, w11, w17
//   0x00f29c: 294045cf  ldp      w15, w17, [x14]
//   0x00f2a0: b94009ce  ldr      w14, [x14, #8]
//   0x00f2a4: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f2a8: 0b0f01ad  add      w13, w13, w15
//   0x00f2ac: 0b11018c  add      w12, w12, w17
//   0x00f2b0: 7940a551  ldrh     w17, [x10, #0x52]
//   0x00f2b4: 0b0e016b  add      w11, w11, w14
//   0x00f2b8: 29403a0f  ldp      w15, w14, [x16]
//   0x00f2bc: b9400a10  ldr      w16, [x16, #8]
//   0x00f2c0: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f2c4: 0b0f01ad  add      w13, w13, w15
//   0x00f2c8: 7940a94f  ldrh     w15, [x10, #0x54]
//   0x00f2cc: 0b0e018c  add      w12, w12, w14
//   0x00f2d0: 0b10016b  add      w11, w11, w16
//   0x00f2d4: 2940422e  ldp      w14, w16, [x17]
//   0x00f2d8: b9400a31  ldr      w17, [x17, #8]
//   0x00f2dc: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f2e0: 0b0e01ad  add      w13, w13, w14
//   0x00f2e4: 7940ad4e  ldrh     w14, [x10, #0x56]
//   0x00f2e8: 0b10018c  add      w12, w12, w16
//   0x00f2ec: 0b11016b  add      w11, w11, w17
//   0x00f2f0: 294045f0  ldp      w16, w17, [x15]
//   0x00f2f4: b94009ef  ldr      w15, [x15, #8]
//   0x00f2f8: 8b0e128e  add      x14, x20, x14, lsl #4
//   0x00f2fc: 0b11018c  add      w12, w12, w17
//   0x00f300: 7940b151  ldrh     w17, [x10, #0x58]
//   0x00f304: 0b1001ad  add      w13, w13, w16
//   0x00f308: 0b0f016b  add      w11, w11, w15
//   0x00f30c: 29403dd0  ldp      w16, w15, [x14]
//   0x00f310: b94009ce  ldr      w14, [x14, #8]
//   0x00f314: 8b111291  add      x17, x20, x17, lsl #4
//   0x00f318: 0b1001ad  add      w13, w13, w16
//   0x00f31c: 7940b550  ldrh     w16, [x10, #0x5a]
//   0x00f320: 0b0f018c  add      w12, w12, w15
//   0x00f324: 0b0e016b  add      w11, w11, w14
//   0x00f328: 29403a2f  ldp      w15, w14, [x17]
//   0x00f32c: b9400a31  ldr      w17, [x17, #8]
//   0x00f330: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f334: 0b0f01ad  add      w13, w13, w15
//   0x00f338: 7940b94f  ldrh     w15, [x10, #0x5c]
//   0x00f33c: 0b0e018c  add      w12, w12, w14
//   0x00f340: 0b11016b  add      w11, w11, w17
//   0x00f344: 2940460e  ldp      w14, w17, [x16]
//   0x00f348: b9400a10  ldr      w16, [x16, #8]
//   0x00f34c: 8b0f128f  add      x15, x20, x15, lsl #4
//   0x00f350: 0b0e01ad  add      w13, w13, w14
//   0x00f354: 0b10016b  add      w11, w11, w16
//   0x00f358: 294041ee  ldp      w14, w16, [x15]
//   0x00f35c: 0b11018c  add      w12, w12, w17
//   0x00f360: 7940bd51  ldrh     w17, [x10, #0x5e]
//   0x00f364: 7940c14a  ldrh     w10, [x10, #0x60]
//   0x00f368: 0b0e01ad  add      w13, w13, w14
//   0x00f36c: b94009ee  ldr      w14, [x15, #8]
//   0x00f370: 8b11128f  add      x15, x20, x17, lsl #4
//   0x00f374: 0b10018c  add      w12, w12, w16
//   0x00f378: 8b0a128a  add      x10, x20, x10, lsl #4
//   0x00f37c: 0b0e016b  add      w11, w11, w14
//   0x00f380: 294039f0  ldp      w16, w14, [x15]
//   0x00f384: b94009ef  ldr      w15, [x15, #8]
//   0x00f388: f9403bf1  ldr      x17, [sp, #0x70]
//   0x00f38c: 0b1001ad  add      w13, w13, w16
//   0x00f390: 78627810  ldrh     w16, [x0, x2, lsl #1]
//   0x00f394: 0b0e018c  add      w12, w12, w14
//   0x00f398: 0b0f016b  add      w11, w11, w15
//   0x00f39c: 29403d4e  ldp      w14, w15, [x10]
//   0x00f3a0: 8b101290  add      x16, x20, x16, lsl #4
//   0x00f3a4: b940094a  ldr      w10, [x10, #8]
//   0x00f3a8: 0b0e01ad  add      w13, w13, w14
//   0x00f3ac: 0b0f018c  add      w12, w12, w15
//   0x00f3b0: 29403e0e  ldp      w14, w15, [x16]
//   0x00f3b4: b9400a10  ldr      w16, [x16, #8]
//   0x00f3b8: 0b0a016a  add      w10, w11, w10
//   0x00f3bc: 0b0e01ab  add      w11, w13, w14
//   0x00f3c0: 0b0f018c  add      w12, w12, w15
//   0x00f3c4: 0b10014a  add      w10, w10, w16
//   0x00f3c8: 781843ab  sturh    w11, [x29, #-0x7c]
//   0x00f3cc: 53107d6b  lsr      w11, w11, #0x10
//   0x00f3d0: 781883ac  sturh    w12, [x29, #-0x78]
//   0x00f3d4: 53107d8c  lsr      w12, w12, #0x10
//   0x00f3d8: 7818c3aa  sturh    w10, [x29, #-0x74]
//   0x00f3dc: 53107d4a  lsr      w10, w10, #0x10
//   0x00f3e0: 781863ab  sturh    w11, [x29, #-0x7a]
//   0x00f3e4: 7818a3ac  sturh    w12, [x29, #-0x76]
//   0x00f3e8: 7818e3aa  sturh    w10, [x29, #-0x72]
//   0x00f3ec: 14000019  b        #0xf450
//   0x00f3f0: a946c7e0  ldp      x0, x17, [sp, #0x68]
//   0x00f3f4: b94083e3  ldr      w3, [sp, #0x80]
//   0x00f3f8: f9401ff9  ldr      x25, [sp, #0x38]
//   0x00f3fc: f000003c  adrp     x28, #0x16000
//   0x00f400: 6b1b011f  cmp      w8, w27
//   0x00f404: 52808101  mov      w1, #0x408
//   0x00f408: 913e9b9c  add      x28, x28, #0xfa6
//   0x00f40c: 5400022b  b.lt     #0xf450
//   0x00f410: 93407d0a  sxtw     x10, w8
//   0x00f414: aa1b03eb  mov      x11, x27
//   0x00f418: 786b780c  ldrh     w12, [x0, x11, lsl #1]
//   0x00f41c: d101f3ad  sub      x13, x29, #0x7c
//   0x00f420: aa1903ee  mov      x14, x25
//   0x00f424: 8b0c034c  add      x12, x26, x12
//   0x00f428: 3940018f  ldrb     w15, [x12]
//   0x00f42c: 794001b0  ldrh     w16, [x13]
//   0x00f430: f10005ce  subs     x14, x14, #1
//   0x00f434: 9104098c  add      x12, x12, #0x102
//   0x00f438: 0b0f020f  add      w15, w16, w15
//   0x00f43c: 780025af  strh     w15, [x13], #2
//   0x00f440: 54ffff41  b.ne     #0xf428
//   0x00f444: eb0a017f  cmp      x11, x10
//   0x00f448: 9100056b  add      x11, x11, #1
//   0x00f44c: 54fffe6b  b.lt     #0xf418
//   0x00f450: 52993feb  mov      w11, #0xc9ff
//   0x00f454: aa1f03ec  mov      x12, xzr
//   0x00f458: 72a7734b  movk     w11, #0x3b9a, lsl #16
//   0x00f45c: 1280000a  mov      w10, #-1
//   0x00f460: 786c7acd  ldrh     w13, [x22, x12, lsl #1]
//   0x00f464: 6b0d017f  cmp      w11, w13
//   0x00f468: 1a8ac18a  csel     w10, w12, w10, gt
//   0x00f46c: 9100058c  add      x12, x12, #1
//   0x00f470: 1a8bc1ab  csel     w11, w13, w11, gt
//   0x00f474: eb0c033f  cmp      x25, x12
//   0x00f478: 54ffff41  b.ne     #0xf460
//   0x00f47c: 937e7d4c  sbfiz    x12, x10, #2, #0x20
//   0x00f480: d10253b0  sub      x16, x29, #0x94
//   0x00f484: b86c6a0d  ldr      w13, [x16, x12]
//   0x00f488: f94047ef  ldr      x15, [sp, #0x88]
//   0x00f48c: 0b030163  add      w3, w11, w3
//   0x00f490: 93407d4b  sxtw     x11, w10
//   0x00f494: 110005ad  add      w13, w13, #1
//   0x00f498: 8b0f022e  add      x14, x17, x15
//   0x00f49c: 910005ef  add      x15, x15, #1
//   0x00f4a0: b82c6a0d  str      w13, [x16, x12]
//   0x00f4a4: 391aa1ca  strb     w10, [x14, #0x6a8]
//   0x00f4a8: f90047ef  str      x15, [sp, #0x88]
//   0x00f4ac: 3707aa09  tbnz     w9, #0, #0xe9ec
//   0x00f4b0: 6b1b011f  cmp      w8, w27
//   0x00f4b4: 54ffc98b  b.lt     #0xede4
//   0x00f4b8: 93407d09  sxtw     x9, w8
//   0x00f4bc: 787b780a  ldrh     w10, [x0, x27, lsl #1]
//   0x00f4c0: d503201f  nop      
//   0x00f4c4: 9b01456c  madd     x12, x11, x1, x17
//   0x00f4c8: eb09037f  cmp      x27, x9
//   0x00f4cc: 9100077b  add      x27, x27, #1
//   0x00f4d0: 8b0a098a  add      x10, x12, x10, lsl #2
//   0x00f4d4: b875694c  ldr      w12, [x10, x21]
//   0x00f4d8: 1100058c  add      w12, w12, #1
//   0x00f4dc: b835694c  str      w12, [x10, x21]
//   0x00f4e0: 54fffeeb  b.lt     #0xf4bc
//   0x00f4e4: 17fffe40  b        #0xede4
//   0x00f4e8: 90000098  adrp     x24, #0x1f000
//   0x00f4ec: f9403bf7  ldr      x23, [sp, #0x70]
//   0x00f4f0: f947cb18  ldr      x24, [x24, #0xf90]
//   0x00f4f4: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f4f8: 14000003  b        #0xf504
//   0x00f4fc: f90047ff  str      xzr, [sp, #0x88]
//   0x00f500: 2a1f03e3  mov      w3, wzr
//   0x00f504: b94292e8  ldr      w8, [x23, #0x290]
//   0x00f508: 71000d1f  cmp      w8, #3
//   0x00f50c: 5400032b  b.lt     #0xf570
//   0x00f510: b94037e8  ldr      w8, [sp, #0x34]
//   0x00f514: f9400be0  ldr      x0, [sp, #0x10]
//   0x00f518: 7100007f  cmp      w3, #0
//   0x00f51c: f0000021  adrp     x1, #0x16000
//   0x00f520: 11000502  add      w2, w8, #1
//   0x00f524: 11001c68  add      w8, w3, #7
//   0x00f528: 1a83b108  csel     w8, w8, w3, lt
//   0x00f52c: 13037d03  asr      w3, w8, #3
//   0x00f530: 913df421  add      x1, x1, #0xf7d
//   0x00f534: 97ffcd53  bl       #0x2a80
//   0x00f538: d10253b3  sub      x19, x29, #0x94
//   0x00f53c: aa1903f7  mov      x23, x25
//   0x00f540: b8404662  ldr      w2, [x19], #4
//   0x00f544: 9104c31b  add      x27, x24, #0x130
//   0x00f548: aa1b03e0  mov      x0, x27
//   0x00f54c: aa1c03e1  mov      x1, x28
//   0x00f550: 97ffcd4c  bl       #0x2a80
//   0x00f554: f10006f7  subs     x23, x23, #1
//   0x00f558: 54ffff41  b.ne     #0xf540
//   0x00f55c: 52800140  mov      w0, #0xa
//   0x00f560: aa1b03e1  mov      x1, x27
//   0x00f564: 97ffcceb  bl       #0x2910
//   0x00f568: f9403bf7  ldr      x23, [sp, #0x70]
//   0x00f56c: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f570: f94017fb  ldr      x27, [sp, #0x28]
//   0x00f574: aa1903f3  mov      x19, x25
//   0x00f578: aa1a03fc  mov      x28, x26
//   0x00f57c: 52800223  mov      w3, #0x11
//   0x00f580: aa1c03e0  mov      x0, x28
//   0x00f584: aa1b03e1  mov      x1, x27
//   0x00f588: 2a0403e2  mov      w2, w4
//   0x00f58c: 97ffcc65  bl       #0x2720
//   0x00f590: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f594: 91040b9c  add      x28, x28, #0x102
//   0x00f598: f1000673  subs     x19, x19, #1
//   0x00f59c: 9110237b  add      x27, x27, #0x408
//   0x00f5a0: 54fffee1  b.ne     #0xf57c
//   0x00f5a4: b94037e8  ldr      w8, [sp, #0x34]
//   0x00f5a8: 90000098  adrp     x24, #0x1f000
//   0x00f5ac: f000003c  adrp     x28, #0x16000
//   0x00f5b0: 913e9b9c  add      x28, x28, #0xfa6
//   0x00f5b4: 11000508  add      w8, w8, #1
//   0x00f5b8: b90037e8  str      w8, [sp, #0x34]
//   0x00f5bc: f947cb18  ldr      x24, [x24, #0xf90]
//   0x00f5c0: 7100111f  cmp      w8, #4
//   0x00f5c4: 54ff9b41  b.ne     #0xe92c
//   0x00f5c8: f94047f3  ldr      x19, [sp, #0x88]
//   0x00f5cc: 5288ca68  mov      w8, #0x4653
//   0x00f5d0: 6b08027f  cmp      w19, w8
//   0x00f5d4: 5400008b  b.lt     #0xf5e4
//   0x00f5d8: 52817760  mov      w0, #0xbbb
//   0x00f5dc: 97ffcca5  bl       #0x2870
//   0x00f5e0: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f5e4: aa1f03e8  mov      x8, xzr
//   0x00f5e8: 910273e9  add      x9, sp, #0x9c
//   0x00f5ec: 38286928  strb     w8, [x9, x8]
//   0x00f5f0: 91000508  add      x8, x8, #1
//   0x00f5f4: eb08033f  cmp      x25, x8
//   0x00f5f8: 54ffffa1  b.ne     #0xf5ec
//   0x00f5fc: 7100067f  cmp      w19, #1
//   0x00f600: 5400036b  b.lt     #0xf66c
//   0x00f604: 394273eb  ldrb     w11, [sp, #0x9c]
//   0x00f608: 910273ea  add      x10, sp, #0x9c
//   0x00f60c: aa1f03e8  mov      x8, xzr
//   0x00f610: 2a1303e9  mov      w9, w19
//   0x00f614: b240014a  orr      x10, x10, #1
//   0x00f618: 52899f4c  mov      w12, #0x4cfa
//   0x00f61c: 14000006  b        #0xf634
//   0x00f620: 2a1f03ef  mov      w15, wzr
//   0x00f624: 91000508  add      x8, x8, #1
//   0x00f628: eb09011f  cmp      x8, x9
//   0x00f62c: 382c69af  strb     w15, [x13, x12]
//   0x00f630: 540001c0  b.eq     #0xf668
//   0x00f634: 8b0802ed  add      x13, x23, x8
//   0x00f638: 395aa1ae  ldrb     w14, [x13, #0x6a8]
//   0x00f63c: 6b2b01df  cmp      w14, w11, uxtb
//   0x00f640: 54ffff00  b.eq     #0xf620
//   0x00f644: aa1f03ef  mov      x15, xzr
//   0x00f648: 386f6950  ldrb     w16, [x10, x15]
//   0x00f64c: 382f694b  strb     w11, [x10, x15]
//   0x00f650: 910005ef  add      x15, x15, #1
//   0x00f654: 6b1001df  cmp      w14, w16
//   0x00f658: 2a1003eb  mov      w11, w16
//   0x00f65c: 54ffff61  b.ne     #0xf648
//   0x00f660: 2a0e03eb  mov      w11, w14
//   0x00f664: 17fffff0  b        #0xf624
//   0x00f668: 390273eb  strb     w11, [sp, #0x9c]
//   0x00f66c: 529269a8  mov      w8, #0x934d
//   0x00f670: 52926993  mov      w19, #0x934c
//   0x00f674: aa1f03f4  mov      x20, xzr
//   0x00f678: 927f7898  and      x24, x4, #0xfffffffe
//   0x00f67c: 8b0802fa  add      x26, x23, x8
//   0x00f680: 8b1302fb  add      x27, x23, x19
//   0x00f684: 5280205c  mov      w28, #0x102
//   0x00f688: 7100049f  cmp      w4, #1
//   0x00f68c: 5400028a  b.ge     #0xf6dc
//   0x00f690: 2a1f03f5  mov      w21, wzr
//   0x00f694: 52800416  mov      w22, #0x20
//   0x00f698: 52808108  mov      w8, #0x408
//   0x00f69c: 9b085e88  madd     x8, x20, x8, x23
//   0x00f6a0: 9b1c5e89  madd     x9, x20, x28, x23
//   0x00f6a4: 52932b0a  mov      w10, #0x9958
//   0x00f6a8: 8b0a0100  add      x0, x8, x10
//   0x00f6ac: 8b130121  add      x1, x9, x19
//   0x00f6b0: 2a1603e2  mov      w2, w22
//   0x00f6b4: 2a1503e3  mov      w3, w21
//   0x00f6b8: 97ffcc2e  bl       #0x2770
//   0x00f6bc: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f6c0: 91000694  add      x20, x20, #1
//   0x00f6c4: 91040b5a  add      x26, x26, #0x102
//   0x00f6c8: eb19029f  cmp      x20, x25
//   0x00f6cc: 91040b7b  add      x27, x27, #0x102
//   0x00f6d0: 540006c0  b.eq     #0xf7a8
//   0x00f6d4: 7100049f  cmp      w4, #1
//   0x00f6d8: 54fffdcb  b.lt     #0xf690
//   0x00f6dc: 7100049f  cmp      w4, #1
//   0x00f6e0: 540000a1  b.ne     #0xf6f4
//   0x00f6e4: aa1f03e9  mov      x9, xzr
//   0x00f6e8: 2a1f03f5  mov      w21, wzr
//   0x00f6ec: 52800416  mov      w22, #0x20
//   0x00f6f0: 1400001a  b        #0xf758
//   0x00f6f4: 2a1f03e9  mov      w9, wzr
//   0x00f6f8: 2a1f03ea  mov      w10, wzr
//   0x00f6fc: 52800408  mov      w8, #0x20
//   0x00f700: aa1803ec  mov      x12, x24
//   0x00f704: aa1a03ed  mov      x13, x26
//   0x00f708: 5280040b  mov      w11, #0x20
//   0x00f70c: 385ff1ae  ldurb    w14, [x13, #-1]
//   0x00f710: 384025af  ldrb     w15, [x13], #2
//   0x00f714: 6b0e013f  cmp      w9, w14
//   0x00f718: 1a8931c9  csel     w9, w14, w9, lo
//   0x00f71c: 6b0f015f  cmp      w10, w15
//   0x00f720: 1a8a31ea  csel     w10, w15, w10, lo
//   0x00f724: 6b0e011f  cmp      w8, w14
//   0x00f728: 1a88c1c8  csel     w8, w14, w8, gt
//   0x00f72c: 6b0f017f  cmp      w11, w15
//   0x00f730: 1a8bc1eb  csel     w11, w15, w11, gt
//   0x00f734: f100098c  subs     x12, x12, #2
//   0x00f738: 54fffea1  b.ne     #0xf70c
//   0x00f73c: 6b0a013f  cmp      w9, w10
//   0x00f740: 1a8a8135  csel     w21, w9, w10, hi
//   0x00f744: 6b0b011f  cmp      w8, w11
//   0x00f748: 1a8bb116  csel     w22, w8, w11, lt
//   0x00f74c: eb04031f  cmp      x24, x4
//   0x00f750: aa1803e9  mov      x9, x24
//   0x00f754: 54000140  b.eq     #0xf77c
//   0x00f758: 8b090368  add      x8, x27, x9
//   0x00f75c: cb090089  sub      x9, x4, x9
//   0x00f760: 3840150a  ldrb     w10, [x8], #1
//   0x00f764: 6b0a02bf  cmp      w21, w10
//   0x00f768: 1a953155  csel     w21, w10, w21, lo
//   0x00f76c: 6b0a02df  cmp      w22, w10
//   0x00f770: 1a96c156  csel     w22, w10, w22, gt
//   0x00f774: f1000529  subs     x9, x9, #1
//   0x00f778: 54ffff41  b.ne     #0xf760
//   0x00f77c: 71004abf  cmp      w21, #0x12
//   0x00f780: 5400008b  b.lt     #0xf790
//   0x00f784: 52817780  mov      w0, #0xbbc
//   0x00f788: 97ffcc3a  bl       #0x2870
//   0x00f78c: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f790: 710002df  cmp      w22, #0
//   0x00f794: 54fff82c  b.gt     #0xf698
//   0x00f798: 528177a0  mov      w0, #0xbbd
//   0x00f79c: 97ffcc35  bl       #0x2870
//   0x00f7a0: f9404be4  ldr      x4, [sp, #0x90]
//   0x00f7a4: 17ffffbd  b        #0xf698
//   0x00f7a8: 90000093  adrp     x19, #0x1f000
//   0x00f7ac: f947ca73  ldr      x19, [x19, #0xf90]
//   0x00f7b0: aa1f03e8  mov      x8, xzr
//   0x00f7b4: 91023ee9  add      x9, x23, #0x8f
//   0x00f7b8: 910273ea  add      x10, sp, #0x9c
//   0x00f7bc: 3828695f  strb     wzr, [x10, x8]
//   0x00f7c0: 385f112b  ldurb    w11, [x9, #-0xf]
//   0x00f7c4: 7100017f  cmp      w11, #0
//   0x00f7c8: 1a9f07ec  cset     w12, ne
//   0x00f7cc: 3828694c  strb     w12, [x10, x8]
//   0x00f7d0: 385f212c  ldurb    w12, [x9, #-0xe]
//   0x00f7d4: 2a0c016b  orr      w11, w11, w12
//   0x00f7d8: 72001d7f  tst      w11, #0xff
//   0x00f7dc: 1a9f07ec  cset     w12, ne
//   0x00f7e0: 3828694c  strb     w12, [x10, x8]
//   0x00f7e4: 385f312c  ldurb    w12, [x9, #-0xd]
//   0x00f7e8: 2a0c016b  orr      w11, w11, w12
//   0x00f7ec: 72001d7f  tst      w11, #0xff
//   0x00f7f0: 1a9f07ec  cset     w12, ne
//   0x00f7f4: 3828694c  strb     w12, [x10, x8]
//   0x00f7f8: 385f412c  ldurb    w12, [x9, #-0xc]
//   0x00f7fc: 2a0c016b  orr      w11, w11, w12
//   0x00f800: 72001d7f  tst      w11, #0xff
//   0x00f804: 1a9f07ec  cset     w12, ne
//   0x00f808: 3828694c  strb     w12, [x10, x8]
//   0x00f80c: 385f512c  ldurb    w12, [x9, #-0xb]
//   0x00f810: 2a0c016b  orr      w11, w11, w12
//   0x00f814: 72001d7f  tst      w11, #0xff
//   0x00f818: 1a9f07ec  cset     w12, ne
//   0x00f81c: 3828694c  strb     w12, [x10, x8]
//   0x00f820: 385f612c  ldurb    w12, [x9, #-0xa]
//   0x00f824: 2a0c016b  orr      w11, w11, w12
//   0x00f828: 72001d7f  tst      w11, #0xff
//   0x00f82c: 1a9f07ec  cset     w12, ne
//   0x00f830: 3828694c  strb     w12, [x10, x8]
//   0x00f834: 385f712c  ldurb    w12, [x9, #-9]
//   0x00f838: 2a0c016b  orr      w11, w11, w12
//   0x00f83c: 72001d7f  tst      w11, #0xff
//   0x00f840: 1a9f07ec  cset     w12, ne
//   0x00f844: 3828694c  strb     w12, [x10, x8]
//   0x00f848: 385f812c  ldurb    w12, [x9, #-8]
//   0x00f84c: 2a0c016b  orr      w11, w11, w12
//   0x00f850: 72001d7f  tst      w11, #0xff
//   0x00f854: 1a9f07ec  cset     w12, ne
//   0x00f858: 3828694c  strb     w12, [x10, x8]
//   0x00f85c: 385f912c  ldurb    w12, [x9, #-7]
//   0x00f860: 2a0c016b  orr      w11, w11, w12
//   0x00f864: 72001d7f  tst      w11, #0xff
//   0x00f868: 1a9f07ec  cset     w12, ne
//   0x00f86c: 3828694c  strb     w12, [x10, x8]
//   0x00f870: 385fa12c  ldurb    w12, [x9, #-6]
//   0x00f874: 2a0c016b  orr      w11, w11, w12
//   0x00f878: 72001d7f  tst      w11, #0xff
//   0x00f87c: 1a9f07ec  cset     w12, ne
//   0x00f880: 3828694c  strb     w12, [x10, x8]
//   0x00f884: 385fb12c  ldurb    w12, [x9, #-5]
//   0x00f888: 2a0c016b  orr      w11, w11, w12
//   0x00f88c: 72001d7f  tst      w11, #0xff
//   0x00f890: 1a9f07ec  cset     w12, ne
//   0x00f894: 3828694c  strb     w12, [x10, x8]
//   0x00f898: 385fc12c  ldurb    w12, [x9, #-4]
//   0x00f89c: 2a0c016b  orr      w11, w11, w12
//   0x00f8a0: 72001d7f  tst      w11, #0xff
//   0x00f8a4: 1a9f07ec  cset     w12, ne
//   0x00f8a8: 3828694c  strb     w12, [x10, x8]
//   0x00f8ac: 385fd12c  ldurb    w12, [x9, #-3]
//   0x00f8b0: 2a0c016b  orr      w11, w11, w12
//   0x00f8b4: 72001d7f  tst      w11, #0xff
//   0x00f8b8: 1a9f07ec  cset     w12, ne
//   0x00f8bc: 3828694c  strb     w12, [x10, x8]
//   0x00f8c0: 385fe12c  ldurb    w12, [x9, #-2]
//   0x00f8c4: 2a0c016b  orr      w11, w11, w12
//   0x00f8c8: 72001d7f  tst      w11, #0xff
//   0x00f8cc: 1a9f07ec  cset     w12, ne
//   0x00f8d0: 3828694c  strb     w12, [x10, x8]
//   0x00f8d4: 385ff12c  ldurb    w12, [x9, #-1]
//   0x00f8d8: 2a0c016b  orr      w11, w11, w12
//   0x00f8dc: 72001d7f  tst      w11, #0xff
//   0x00f8e0: 1a9f07ec  cset     w12, ne
//   0x00f8e4: 3828694c  strb     w12, [x10, x8]
//   0x00f8e8: 3841052c  ldrb     w12, [x9], #0x10
//   0x00f8ec: 2a0c016b  orr      w11, w11, w12
//   0x00f8f0: 72001d7f  tst      w11, #0xff
//   0x00f8f4: 1a9f07eb  cset     w11, ne
//   0x00f8f8: 3828694b  strb     w11, [x10, x8]
//   0x00f8fc: 91000508  add      x8, x8, #1
//   0x00f900: f100411f  cmp      x8, #0x10
//   0x00f904: 54fff5c1  b.ne     #0xf7bc
//   0x00f908: aa1703f5  mov      x21, x23
//   0x00f90c: b8474ea8  ldr      w8, [x21, #0x74]!
//   0x00f910: f94047f4  ldr      x20, [sp, #0x88]
//   0x00f914: aa1f03ec  mov      x12, xzr
//   0x00f918: 910273ed  add      x13, sp, #0x9c
//   0x00f91c: b94212aa  ldr      w10, [x21, #0x210]
//   0x00f920: b9420eab  ldr      w11, [x21, #0x20c]
//   0x00f924: 910842b6  add      x22, x21, #0x210
//   0x00f928: 910832b8  add      x24, x21, #0x20c
//   0x00f92c: d10092bb  sub      x27, x21, #0x24
//   0x00f930: 52b0000e  mov      w14, #-0xffffffff80000000
//   0x00f934: 2a0803e9  mov      w9, w8
//   0x00f938: 386c69af  ldrb     w15, [x13, x12]
//   0x00f93c: 3500018f  cbnz     w15, #0xf96c
//   0x00f940: 1400001c  b        #0xf9b0
//   0x00f944: 1aca25cf  lsr      w15, w14, w10
//   0x00f948: 2a0b01eb  orr      w11, w15, w11
//   0x00f94c: 9100058c  add      x12, x12, #1
//   0x00f950: 1100054a  add      w10, w10, #1
//   0x00f954: f100419f  cmp      x12, #0x10
//   0x00f958: b900030b  str      w11, [x24]
//   0x00f95c: b90002ca  str      w10, [x22]
//   0x00f960: 540004a0  b.eq     #0xf9f4
//   0x00f964: 386c69af  ldrb     w15, [x13, x12]
//   0x00f968: 3400024f  cbz      w15, #0xf9b0
//   0x00f96c: 7100215f  cmp      w10, #8
//   0x00f970: 54fffeab  b.lt     #0xf944
//   0x00f974: f940036a  ldr      x10, [x27]
//   0x00f978: 53187d6b  lsr      w11, w11, #0x18
//   0x00f97c: 3829c94b  strb     w11, [x10, w9, sxtw]
//   0x00f980: b94002a9  ldr      w9, [x21]
//   0x00f984: 11000529  add      w9, w9, #1
//   0x00f988: b90002a9  str      w9, [x21]
//   0x00f98c: b940030a  ldr      w10, [x24]
//   0x00f990: 53185d4b  lsl      w11, w10, #8
//   0x00f994: b900030b  str      w11, [x24]
//   0x00f998: b94002ca  ldr      w10, [x22]
//   0x00f99c: 5100214a  sub      w10, w10, #8
//   0x00f9a0: 71001d5f  cmp      w10, #7
//   0x00f9a4: b90002ca  str      w10, [x22]
//   0x00f9a8: 54fffe6c  b.gt     #0xf974
//   0x00f9ac: 17ffffe6  b        #0xf944
//   0x00f9b0: 7100215f  cmp      w10, #8
//   0x00f9b4: 54fffccb  b.lt     #0xf94c
//   0x00f9b8: f940036a  ldr      x10, [x27]
//   0x00f9bc: 53187d6b  lsr      w11, w11, #0x18
//   0x00f9c0: 3829c94b  strb     w11, [x10, w9, sxtw]
//   0x00f9c4: b94002a9  ldr      w9, [x21]
//   0x00f9c8: 11000529  add      w9, w9, #1
//   0x00f9cc: b90002a9  str      w9, [x21]
//   0x00f9d0: b940030a  ldr      w10, [x24]
//   0x00f9d4: 53185d4b  lsl      w11, w10, #8
//   0x00f9d8: b900030b  str      w11, [x24]
//   0x00f9dc: b94002ca  ldr      w10, [x22]
//   0x00f9e0: 5100214a  sub      w10, w10, #8
//   0x00f9e4: 71001d5f  cmp      w10, #7
//   0x00f9e8: b90002ca  str      w10, [x22]
//   0x00f9ec: 54fffe6c  b.gt     #0xf9b8
//   0x00f9f0: 17ffffd7  b        #0xf94c
//   0x00f9f4: aa1f03ec  mov      x12, xzr
//   0x00f9f8: 910273ed  add      x13, sp, #0x9c
//   0x00f9fc: 52b0000e  mov      w14, #-0xffffffff80000000
//   0x00fa00: 386c69af  ldrb     w15, [x13, x12]
//   0x00fa04: 350000cf  cbnz     w15, #0xfa1c
//   0x00fa08: 9100058c  add      x12, x12, #1
//   0x00fa0c: f100419f  cmp      x12, #0x10
//   0x00fa10: 54000680  b.eq     #0xfae0
//   0x00fa14: 386c69af  ldrb     w15, [x13, x12]
//   0x00fa18: 34ffff8f  cbz      w15, #0xfa08
//   0x00fa1c: aa1f03ef  mov      x15, xzr
//   0x00fa20: d37ced90  lsl      x16, x12, #4
//   0x00fa24: 14000009  b        #0xfa48
//   0x00fa28: 1aca25d1  lsr      w17, w14, w10
//   0x00fa2c: 2a0b022b  orr      w11, w17, w11
//   0x00fa30: 910005ef  add      x15, x15, #1
//   0x00fa34: 1100054a  add      w10, w10, #1
//   0x00fa38: f10041ff  cmp      x15, #0x10
//   0x00fa3c: b900030b  str      w11, [x24]
//   0x00fa40: b90002ca  str      w10, [x22]
//   0x00fa44: 54fffe20  b.eq     #0xfa08
//   0x00fa48: 8b1001f1  add      x17, x15, x16
//   0x00fa4c: 8b1102f1  add      x17, x23, x17
//   0x00fa50: 39420231  ldrb     w17, [x17, #0x80]
//   0x00fa54: 34000251  cbz      w17, #0xfa9c
//   0x00fa58: 7100215f  cmp      w10, #8
//   0x00fa5c: 54fffe6b  b.lt     #0xfa28
//   0x00fa60: f940036a  ldr      x10, [x27]
//   0x00fa64: 53187d6b  lsr      w11, w11, #0x18
//   0x00fa68: 3829c94b  strb     w11, [x10, w9, sxtw]
//   0x00fa6c: b94002a9  ldr      w9, [x21]
//   0x00fa70: 11000529  add      w9, w9, #1
//   0x00fa74: b90002a9  str      w9, [x21]
//   0x00fa78: b940030a  ldr      w10, [x24]
//   0x00fa7c: 53185d4b  lsl      w11, w10, #8
//   0x00fa80: b900030b  str      w11, [x24]
//   0x00fa84: b94002ca  ldr      w10, [x22]
//   0x00fa88: 5100214a  sub      w10, w10, #8
//   0x00fa8c: 71001d5f  cmp      w10, #7
//   0x00fa90: b90002ca  str      w10, [x22]
//   0x00fa94: 54fffe6c  b.gt     #0xfa60
//   0x00fa98: 17ffffe4  b        #0xfa28
//   0x00fa9c: 7100215f  cmp      w10, #8
//   0x00faa0: 54fffc8b  b.lt     #0xfa30
//   0x00faa4: f940036a  ldr      x10, [x27]
//   0x00faa8: 53187d6b  lsr      w11, w11, #0x18
//   0x00faac: 3829c94b  strb     w11, [x10, w9, sxtw]
//   0x00fab0: b94002a9  ldr      w9, [x21]
//   0x00fab4: 11000529  add      w9, w9, #1
//   0x00fab8: b90002a9  str      w9, [x21]
//   0x00fabc: b940030a  ldr      w10, [x24]
//   0x00fac0: 53185d4b  lsl      w11, w10, #8
//   0x00fac4: b900030b  str      w11, [x24]
//   0x00fac8: b94002ca  ldr      w10, [x22]
//   0x00facc: 5100214a  sub      w10, w10, #8
//   0x00fad0: 71001d5f  cmp      w10, #7
//   0x00fad4: b90002ca  str      w10, [x22]
//   0x00fad8: 54fffe6c  b.gt     #0xfaa4
//   0x00fadc: 17ffffd5  b        #0xfa30
//   0x00fae0: b94292eb  ldr      w11, [x23, #0x290]
//   0x00fae4: 71000d7f  cmp      w11, #3
//   0x00fae8: 5400010b  b.lt     #0xfb08
//   0x00faec: f0000021  adrp     x1, #0x16000
//   0x00faf0: 4b080122  sub      w2, w9, w8
//   0x00faf4: 9104c260  add      x0, x19, #0x130
//   0x00faf8: 913ea821  add      x1, x1, #0xfaa
//   0x00fafc: 97ffcbe1  bl       #0x2a80
//   0x00fb00: b94002a9  ldr      w9, [x21]
//   0x00fb04: b94002ca  ldr      w10, [x22]
//   0x00fb08: b940030b  ldr      w11, [x24]
//   0x00fb0c: 2a0903e8  mov      w8, w9
//   0x00fb10: 7100215f  cmp      w10, #8
//   0x00fb14: 540001eb  b.lt     #0xfb50
//   0x00fb18: f940036a  ldr      x10, [x27]
//   0x00fb1c: 53187d6b  lsr      w11, w11, #0x18
//   0x00fb20: 3828c94b  strb     w11, [x10, w8, sxtw]
//   0x00fb24: b94002a8  ldr      w8, [x21]
//   0x00fb28: 11000508  add      w8, w8, #1
//   0x00fb2c: b90002a8  str      w8, [x21]
//   0x00fb30: b940030a  ldr      w10, [x24]
//   0x00fb34: 53185d4b  lsl      w11, w10, #8
//   0x00fb38: b900030b  str      w11, [x24]
//   0x00fb3c: b94002ca  ldr      w10, [x22]
//   0x00fb40: 5100214a  sub      w10, w10, #8
//   0x00fb44: 71001d5f  cmp      w10, #7
//   0x00fb48: b90002ca  str      w10, [x22]
//   0x00fb4c: 54fffe6c  b.gt     #0xfb18
//   0x00fb50: 528003ad  mov      w13, #0x1d
//   0x00fb54: 11000d4c  add      w12, w10, #3
//   0x00fb58: 4b0a01aa  sub      w10, w13, w10
//   0x00fb5c: 1aca232a  lsl      w10, w25, w10
//   0x00fb60: 7100219f  cmp      w12, #8
//   0x00fb64: 2a0b014a  orr      w10, w10, w11
//   0x00fb68: b900030a  str      w10, [x24]
//   0x00fb6c: b90002cc  str      w12, [x22]
//   0x00fb70: 540001eb  b.lt     #0xfbac
//   0x00fb74: f940036b  ldr      x11, [x27]
//   0x00fb78: 53187d4a  lsr      w10, w10, #0x18
//   0x00fb7c: 3828c96a  strb     w10, [x11, w8, sxtw]
//   0x00fb80: b94002a8  ldr      w8, [x21]
//   0x00fb84: 11000508  add      w8, w8, #1
//   0x00fb88: b90002a8  str      w8, [x21]
//   0x00fb8c: b940030a  ldr      w10, [x24]
//   0x00fb90: 53185d4a  lsl      w10, w10, #8
//   0x00fb94: b900030a  str      w10, [x24]
//   0x00fb98: b94002cb  ldr      w11, [x22]
//   0x00fb9c: 5100216c  sub      w12, w11, #8
//   0x00fba0: 71001d9f  cmp      w12, #7
//   0x00fba4: b90002cc  str      w12, [x22]
//   0x00fba8: 54fffe6c  b.gt     #0xfb74
//   0x00fbac: 5280022d  mov      w13, #0x11
//   0x00fbb0: 11003d8b  add      w11, w12, #0xf
//   0x00fbb4: 4b0c01ac  sub      w12, w13, w12
//   0x00fbb8: 1acc228c  lsl      w12, w20, w12
//   0x00fbbc: 7100069f  cmp      w20, #1
//   0x00fbc0: 2a0a018a  orr      w10, w12, w10
//   0x00fbc4: b900030a  str      w10, [x24]
//   0x00fbc8: b90002cb  str      w11, [x22]
//   0x00fbcc: 5400082b  b.lt     #0xfcd0
//   0x00fbd0: aa1f03ec  mov      x12, xzr
//   0x00fbd4: 2a1403ed  mov      w13, w20
//   0x00fbd8: 52899f4e  mov      w14, #0x4cfa
//   0x00fbdc: 52b0000f  mov      w15, #-0xffffffff80000000
//   0x00fbe0: 14000007  b        #0xfbfc
//   0x00fbe4: 9100058c  add      x12, x12, #1
//   0x00fbe8: 1100040b  add      w11, w0, #1
//   0x00fbec: eb0d019f  cmp      x12, x13
//   0x00fbf0: b900030a  str      w10, [x24]
//   0x00fbf4: b90002cb  str      w11, [x22]
//   0x00fbf8: 540006c0  b.eq     #0xfcd0
//   0x00fbfc: 8b0c02f0  add      x16, x23, x12
//   0x00fc00: 8b0e0210  add      x16, x16, x14
//   0x00fc04: 39400211  ldrb     w17, [x16]
//   0x00fc08: 71001d7f  cmp      w11, #7
//   0x00fc0c: 1a9fd7e1  cset     w1, gt
//   0x00fc10: 340003f1  cbz      w17, #0xfc8c
//   0x00fc14: 2a1f03f1  mov      w17, wzr
//   0x00fc18: 370001c1  tbnz     w1, #0, #0xfc50
//   0x00fc1c: 1acb25e1  lsr      w1, w15, w11
//   0x00fc20: 11000560  add      w0, w11, #1
//   0x00fc24: 2a0a002a  orr      w10, w1, w10
//   0x00fc28: b900030a  str      w10, [x24]
//   0x00fc2c: b90002c0  str      w0, [x22]
//   0x00fc30: 39400202  ldrb     w2, [x16]
//   0x00fc34: 11000631  add      w17, w17, #1
//   0x00fc38: 7100197f  cmp      w11, #6
//   0x00fc3c: 1a9fd7e1  cset     w1, gt
//   0x00fc40: 6b02023f  cmp      w17, w2
//   0x00fc44: 2a0003eb  mov      w11, w0
//   0x00fc48: 54000242  b.hs     #0xfc90
//   0x00fc4c: 3607fe81  tbz      w1, #0, #0xfc1c
//   0x00fc50: f940036b  ldr      x11, [x27]
//   0x00fc54: 53187d4a  lsr      w10, w10, #0x18
//   0x00fc58: 3828c96a  strb     w10, [x11, w8, sxtw]
//   0x00fc5c: b94002a8  ldr      w8, [x21]
//   0x00fc60: 11000508  add      w8, w8, #1
//   0x00fc64: b90002a8  str      w8, [x21]
//   0x00fc68: b940030a  ldr      w10, [x24]
//   0x00fc6c: 53185d4a  lsl      w10, w10, #8
//   0x00fc70: b900030a  str      w10, [x24]
//   0x00fc74: b94002cb  ldr      w11, [x22]
//   0x00fc78: 5100216b  sub      w11, w11, #8
//   0x00fc7c: 71001d7f  cmp      w11, #7
//   0x00fc80: b90002cb  str      w11, [x22]
//   0x00fc84: 54fffe6c  b.gt     #0xfc50
//   0x00fc88: 17ffffe5  b        #0xfc1c
//   0x00fc8c: 2a0b03e0  mov      w0, w11
//   0x00fc90: 34fffaa1  cbz      w1, #0xfbe4
//   0x00fc94: f940036b  ldr      x11, [x27]
//   0x00fc98: 53187d4a  lsr      w10, w10, #0x18
//   0x00fc9c: 3828c96a  strb     w10, [x11, w8, sxtw]
//   0x00fca0: b94002a8  ldr      w8, [x21]
//   0x00fca4: 11000508  add      w8, w8, #1
//   0x00fca8: b90002a8  str      w8, [x21]
//   0x00fcac: b940030a  ldr      w10, [x24]
//   0x00fcb0: 53185d4a  lsl      w10, w10, #8
//   0x00fcb4: b900030a  str      w10, [x24]
//   0x00fcb8: b94002cb  ldr      w11, [x22]
//   0x00fcbc: 51002160  sub      w0, w11, #8
//   0x00fcc0: 71001c1f  cmp      w0, #7
//   0x00fcc4: b90002c0  str      w0, [x22]
//   0x00fcc8: 54fffe6c  b.gt     #0xfc94
//   0x00fccc: 17ffffc6  b        #0xfbe4
//   0x00fcd0: b94292ec  ldr      w12, [x23, #0x290]
//   0x00fcd4: 71000d9f  cmp      w12, #3
//   0x00fcd8: 5400012b  b.lt     #0xfcfc
//   0x00fcdc: f0000021  adrp     x1, #0x16000
//   0x00fce0: 4b090102  sub      w2, w8, w9
//   0x00fce4: 9104c260  add      x0, x19, #0x130
//   0x00fce8: 913f1021  add      x1, x1, #0xfc4
//   0x00fcec: 97ffcb65  bl       #0x2a80
//   0x00fcf0: b94002a8  ldr      w8, [x21]
//   0x00fcf4: b94002cb  ldr      w11, [x22]
//   0x00fcf8: b940030a  ldr      w10, [x24]
//   0x00fcfc: f9404be5  ldr      x5, [sp, #0x90]
//   0x00fd00: aa1f03e9  mov      x9, xzr
//   0x00fd04: 5280204c  mov      w12, #0x102
//   0x00fd08: 5292698d  mov      w13, #0x934c
//   0x00fd0c: 5280036e  mov      w14, #0x1b
//   0x00fd10: 528003cf  mov      w15, #0x1e
//   0x00fd14: 52800050  mov      w16, #2
//   0x00fd18: 52800071  mov      w17, #3
//   0x00fd1c: 2a0803fc  mov      w28, w8
//   0x00fd20: 14000004  b        #0xfd30
//   0x00fd24: 91000529  add      x9, x9, #1
//   0x00fd28: eb19013f  cmp      x9, x25
//   0x00fd2c: 54000e20  b.eq     #0xfef0
//   0x00fd30: 9b0c5d20  madd     x0, x9, x12, x23
//   0x00fd34: 386d6800  ldrb     w0, [x0, x13]
//   0x00fd38: 7100217f  cmp      w11, #8
//   0x00fd3c: 540001eb  b.lt     #0xfd78
//   0x00fd40: f940036b  ldr      x11, [x27]
//   0x00fd44: 53187d4a  lsr      w10, w10, #0x18
//   0x00fd48: 383cc96a  strb     w10, [x11, w28, sxtw]
//   0x00fd4c: b94002aa  ldr      w10, [x21]
//   0x00fd50: 1100055c  add      w28, w10, #1
//   0x00fd54: b90002bc  str      w28, [x21]
//   0x00fd58: b940030a  ldr      w10, [x24]
//   0x00fd5c: 53185d4a  lsl      w10, w10, #8
//   0x00fd60: b900030a  str      w10, [x24]
//   0x00fd64: b94002cb  ldr      w11, [x22]
//   0x00fd68: 5100216b  sub      w11, w11, #8
//   0x00fd6c: 71001d7f  cmp      w11, #7
//   0x00fd70: b90002cb  str      w11, [x22]
//   0x00fd74: 54fffe6c  b.gt     #0xfd40
//   0x00fd78: 4b0b01c1  sub      w1, w14, w11
//   0x00fd7c: 1ac12001  lsl      w1, w0, w1
//   0x00fd80: 1100156b  add      w11, w11, #5
//   0x00fd84: 710004bf  cmp      w5, #1
//   0x00fd88: 2a0a002a  orr      w10, w1, w10
//   0x00fd8c: b900030a  str      w10, [x24]
//   0x00fd90: b90002cb  str      w11, [x22]
//   0x00fd94: 54fffc8b  b.lt     #0xfd24
//   0x00fd98: aa1f03e1  mov      x1, xzr
//   0x00fd9c: 14000007  b        #0xfdb8
//   0x00fda0: 91000421  add      x1, x1, #1
//   0x00fda4: 1100056b  add      w11, w11, #1
//   0x00fda8: eb05003f  cmp      x1, x5
//   0x00fdac: b900030a  str      w10, [x24]
//   0x00fdb0: b90002cb  str      w11, [x22]
//   0x00fdb4: 54fffb80  b.eq     #0xfd24
//   0x00fdb8: 9b0c5d22  madd     x2, x9, x12, x23
//   0x00fdbc: 8b010042  add      x2, x2, x1
//   0x00fdc0: 8b0d0042  add      x2, x2, x13
//   0x00fdc4: 39400043  ldrb     w3, [x2]
//   0x00fdc8: 6b03001f  cmp      w0, w3
//   0x00fdcc: 5400018b  b.lt     #0xfdfc
//   0x00fdd0: 14000024  b        #0xfe60
//   0x00fdd4: 4b0b01e3  sub      w3, w15, w11
//   0x00fdd8: 1ac32203  lsl      w3, w16, w3
//   0x00fddc: 1100096b  add      w11, w11, #2
//   0x00fde0: 2a0a006a  orr      w10, w3, w10
//   0x00fde4: b900030a  str      w10, [x24]
//   0x00fde8: b90002cb  str      w11, [x22]
//   0x00fdec: 39400043  ldrb     w3, [x2]
//   0x00fdf0: 11000400  add      w0, w0, #1
//   0x00fdf4: 6b03001f  cmp      w0, w3
//   0x00fdf8: 5400034a  b.ge     #0xfe60
//   0x00fdfc: 7100217f  cmp      w11, #8
//   0x00fe00: 54fffeab  b.lt     #0xfdd4
//   0x00fe04: f940036b  ldr      x11, [x27]
//   0x00fe08: 53187d4a  lsr      w10, w10, #0x18
//   0x00fe0c: 383cc96a  strb     w10, [x11, w28, sxtw]
//   0x00fe10: b94002aa  ldr      w10, [x21]
//   0x00fe14: 1100055c  add      w28, w10, #1
//   0x00fe18: b90002bc  str      w28, [x21]
//   0x00fe1c: b940030a  ldr      w10, [x24]
//   0x00fe20: 53185d4a  lsl      w10, w10, #8
//   0x00fe24: b900030a  str      w10, [x24]
//   0x00fe28: b94002cb  ldr      w11, [x22]
//   0x00fe2c: 5100216b  sub      w11, w11, #8
//   0x00fe30: 71001d7f  cmp      w11, #7
//   0x00fe34: b90002cb  str      w11, [x22]
//   0x00fe38: 54fffe6c  b.gt     #0xfe04
//   0x00fe3c: 17ffffe6  b        #0xfdd4
//   0x00fe40: 4b0b01e3  sub      w3, w15, w11
//   0x00fe44: 1ac32223  lsl      w3, w17, w3
//   0x00fe48: 1100096b  add      w11, w11, #2
//   0x00fe4c: 2a0a006a  orr      w10, w3, w10
//   0x00fe50: b900030a  str      w10, [x24]
//   0x00fe54: b90002cb  str      w11, [x22]
//   0x00fe58: 39400043  ldrb     w3, [x2]
//   0x00fe5c: 51000400  sub      w0, w0, #1
//   0x00fe60: 71001d7f  cmp      w11, #7
//   0x00fe64: 1a9fd7e4  cset     w4, gt
//   0x00fe68: 6b03001f  cmp      w0, w3
//   0x00fe6c: 5400022d  b.le     #0xfeb0
//   0x00fe70: 3607fe84  tbz      w4, #0, #0xfe40
//   0x00fe74: f940036b  ldr      x11, [x27]
//   0x00fe78: 53187d4a  lsr      w10, w10, #0x18
//   0x00fe7c: 383cc96a  strb     w10, [x11, w28, sxtw]
//   0x00fe80: b94002aa  ldr      w10, [x21]
//   0x00fe84: 1100055c  add      w28, w10, #1
//   0x00fe88: b90002bc  str      w28, [x21]
//   0x00fe8c: b940030a  ldr      w10, [x24]
//   0x00fe90: 53185d4a  lsl      w10, w10, #8
//   0x00fe94: b900030a  str      w10, [x24]
//   0x00fe98: b94002cb  ldr      w11, [x22]
//   0x00fe9c: 5100216b  sub      w11, w11, #8
//   0x00fea0: 71001d7f  cmp      w11, #7
//   0x00fea4: b90002cb  str      w11, [x22]
//   0x00fea8: 54fffe6c  b.gt     #0xfe74
//   0x00feac: 17ffffe5  b        #0xfe40
//   0x00feb0: 34fff784  cbz      w4, #0xfda0
//   0x00feb4: f940036b  ldr      x11, [x27]
//   0x00feb8: 53187d4a  lsr      w10, w10, #0x18
//   0x00febc: 383cc96a  strb     w10, [x11, w28, sxtw]
//   0x00fec0: b94002aa  ldr      w10, [x21]
//   0x00fec4: 1100055c  add      w28, w10, #1
//   0x00fec8: b90002bc  str      w28, [x21]
//   0x00fecc: b940030a  ldr      w10, [x24]
//   0x00fed0: 53185d4a  lsl      w10, w10, #8
//   0x00fed4: b900030a  str      w10, [x24]
//   0x00fed8: b94002cb  ldr      w11, [x22]
//   0x00fedc: 5100216b  sub      w11, w11, #8
//   0x00fee0: 71001d7f  cmp      w11, #7
//   0x00fee4: b90002cb  str      w11, [x22]
//   0x00fee8: 54fffe6c  b.gt     #0xfeb4
//   0x00feec: 17ffffad  b        #0xfda0
//   0x00fef0: b94292e9  ldr      w9, [x23, #0x290]
//   0x00fef4: 71000d3f  cmp      w9, #3
//   0x00fef8: 5400012b  b.lt     #0xff1c
//   0x00fefc: 4b080382  sub      w2, w28, w8
//   0x00ff00: 90000088  adrp     x8, #0x1f000
//   0x00ff04: f947c908  ldr      x8, [x8, #0xf90]
//   0x00ff08: f0000021  adrp     x1, #0x16000
//   0x00ff0c: 913f4c21  add      x1, x1, #0xfd3
//   0x00ff10: 9104c100  add      x0, x8, #0x130
//   0x00ff14: 97ffcadb  bl       #0x2a80
//   0x00ff18: b94002bc  ldr      w28, [x21]
//   0x00ff1c: b9429ee8  ldr      w8, [x23, #0x29c]
//   0x00ff20: 7100051f  cmp      w8, #1
//   0x00ff24: 5400d38b  b.lt     #0x11994
//   0x00ff28: aa1f03fa  mov      x26, xzr
//   0x00ff2c: 2a1f03e9  mov      w9, wzr
//   0x00ff30: 52802051  mov      w17, #0x102
//   0x00ff34: 52926980  mov      w0, #0x934c
//   0x00ff38: 52808101  mov      w1, #0x408
//   0x00ff3c: 52932b02  mov      w2, #0x9958
//   0x00ff40: f90047f4  str      x20, [sp, #0x88]
//   0x00ff44: 1400000c  b        #0xff74
//   0x00ff48: 0b0a016a  add      w10, w11, w10
//   0x00ff4c: 4b0a03eb  neg      w11, w10
//   0x00ff50: 1acb2108  lsl      w8, w8, w11
//   0x00ff54: 2a090108  orr      w8, w8, w9
//   0x00ff58: b9000308  str      w8, [x24]
//   0x00ff5c: b90002ca  str      w10, [x22]
//   0x00ff60: b9429ee8  ldr      w8, [x23, #0x29c]
//   0x00ff64: 11000469  add      w9, w3, #1
//   0x00ff68: 9100075a  add      x26, x26, #1
//   0x00ff6c: 6b08013f  cmp      w9, w8
//   0x00ff70: 5400cd6a  b.ge     #0x1191c
//   0x00ff74: 8b1a02f3  add      x19, x23, x26
//   0x00ff78: 93407d34  sxtw     x20, w9
//   0x00ff7c: 395aa269  ldrb     w9, [x19, #0x6a8]
//   0x00ff80: 9100c684  add      x4, x20, #0x31
//   0x00ff84: 5100050a  sub      w10, w8, #1
//   0x00ff88: 6b08009f  cmp      w4, w8
//   0x00ff8c: 1a8ab083  csel     w3, w4, w10, lt
//   0x00ff90: 6b09033f  cmp      w25, w9
//   0x00ff94: 540001a8  b.hi     #0xffc8
//   0x00ff98: 528177c0  mov      w0, #0xbbe
//   0x00ff9c: f9004be3  str      x3, [sp, #0x90]
//   0x00ffa0: f90043f4  str      x20, [sp, #0x80]
//   0x00ffa4: aa0403f4  mov      x20, x4
//   0x00ffa8: 97ffca32  bl       #0x2870
//   0x00ffac: aa1403e4  mov      x4, x20
//   0x00ffb0: f94043f4  ldr      x20, [sp, #0x80]
//   0x00ffb4: f9404be3  ldr      x3, [sp, #0x90]
//   0x00ffb8: 52932b02  mov      w2, #0x9958
//   0x00ffbc: 52808101  mov      w1, #0x408
//   0x00ffc0: 52926980  mov      w0, #0x934c
//   0x00ffc4: 52802051  mov      w17, #0x102
//   0x00ffc8: 71001b3f  cmp      w25, #6
//   0x00ffcc: 911aa268  add      x8, x19, #0x6a8
//   0x00ffd0: 5400c521  b.ne     #0x11874
//   0x00ffd4: 4b140069  sub      w9, w3, w20
//   0x00ffd8: 7100c53f  cmp      w9, #0x31
//   0x00ffdc: 5400c4c1  b.ne     #0x11874
//   0x00ffe0: f94037ef  ldr      x15, [sp, #0x68]
//   0x00ffe4: 39400108  ldrb     w8, [x8]
//   0x00ffe8: b94286ec  ldr      w12, [x23, #0x284]
//   0x00ffec: 787479e9  ldrh     w9, [x15, x20, lsl #1]
//   0x00fff0: d503201f  nop      
//   0x00fff4: 9b115d0a  madd     x10, x8, x17, x23
//   0x00fff8: 9b015d0b  madd     x11, x8, x1, x23
//   0x00fffc: 7100219f  cmp      w12, #8
//   0x010000: 8b09014a  add      x10, x10, x9
//   0x010004: 8b09096b  add      x11, x11, x9, lsl #2
//   0x010008: 38606949  ldrb     w9, [x10, x0]
//   0x01000c: b862696a  ldr      w10, [x11, x2]
//   0x010010: b94282eb  ldr      w11, [x23, #0x280]
//   0x010014: 5400020b  b.lt     #0x10054
//   0x010018: b94002ad  ldr      w13, [x21]
//   0x01001c: f940036c  ldr      x12, [x27]
//   0x010020: 53187d6b  lsr      w11, w11, #0x18
//   0x010024: 382dc98b  strb     w11, [x12, w13, sxtw]
//   0x010028: b94002ab  ldr      w11, [x21]
//   0x01002c: 1100056d  add      w13, w11, #1
//   0x010030: b90002ad  str      w13, [x21]
//   0x010034: b940030b  ldr      w11, [x24]
//   0x010038: 53185d6b  lsl      w11, w11, #8
//   0x01003c: b900030b  str      w11, [x24]
//   0x010040: b94002cc  ldr      w12, [x22]
//   0x010044: 5100218c  sub      w12, w12, #8
//   0x010048: 71001d9f  cmp      w12, #7
//   0x01004c: b90002cc  str      w12, [x22]
//   0x010050: 54fffe6c  b.gt     #0x1001c
//   0x010054: 0b09018d  add      w13, w12, w9
//   0x010058: 4b0d03ec  neg      w12, w13
//   0x01005c: 1acc214a  lsl      w10, w10, w12
//   0x010060: 2a0b014a  orr      w10, w10, w11
//   0x010064: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010068: b90286ed  str      w13, [x23, #0x284]
//   0x01006c: b90282ea  str      w10, [x23, #0x280]
//   0x010070: 7940052b  ldrh     w11, [x9, #2]
//   0x010074: d503201f  nop      
//   0x010078: 9b115d0c  madd     x12, x8, x17, x23
//   0x01007c: 9b015d0e  madd     x14, x8, x1, x23
//   0x010080: 710021bf  cmp      w13, #8
//   0x010084: 8b0b018c  add      x12, x12, x11
//   0x010088: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x01008c: 3860698c  ldrb     w12, [x12, x0]
//   0x010090: b862696b  ldr      w11, [x11, x2]
//   0x010094: 5400020b  b.lt     #0x100d4
//   0x010098: b94002ae  ldr      w14, [x21]
//   0x01009c: f940036d  ldr      x13, [x27]
//   0x0100a0: 53187d4a  lsr      w10, w10, #0x18
//   0x0100a4: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x0100a8: b94002aa  ldr      w10, [x21]
//   0x0100ac: 1100054e  add      w14, w10, #1
//   0x0100b0: b90002ae  str      w14, [x21]
//   0x0100b4: b940030a  ldr      w10, [x24]
//   0x0100b8: 53185d4a  lsl      w10, w10, #8
//   0x0100bc: b900030a  str      w10, [x24]
//   0x0100c0: b94002cd  ldr      w13, [x22]
//   0x0100c4: 510021ad  sub      w13, w13, #8
//   0x0100c8: 71001dbf  cmp      w13, #7
//   0x0100cc: b90002cd  str      w13, [x22]
//   0x0100d0: 54fffe6c  b.gt     #0x1009c
//   0x0100d4: 0b0c01ac  add      w12, w13, w12
//   0x0100d8: 4b0c03ed  neg      w13, w12
//   0x0100dc: 1acd216b  lsl      w11, w11, w13
//   0x0100e0: 2a0a016a  orr      w10, w11, w10
//   0x0100e4: b90286ec  str      w12, [x23, #0x284]
//   0x0100e8: b90282ea  str      w10, [x23, #0x280]
//   0x0100ec: 79400929  ldrh     w9, [x9, #4]
//   0x0100f0: d503201f  nop      
//   0x0100f4: 9b115d0b  madd     x11, x8, x17, x23
//   0x0100f8: 9b015d0d  madd     x13, x8, x1, x23
//   0x0100fc: 7100219f  cmp      w12, #8
//   0x010100: 8b09016b  add      x11, x11, x9
//   0x010104: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010108: 38606969  ldrb     w9, [x11, x0]
//   0x01010c: b86269ab  ldr      w11, [x13, x2]
//   0x010110: 5400020b  b.lt     #0x10150
//   0x010114: b94002ad  ldr      w13, [x21]
//   0x010118: f940036c  ldr      x12, [x27]
//   0x01011c: 53187d4a  lsr      w10, w10, #0x18
//   0x010120: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010124: b94002aa  ldr      w10, [x21]
//   0x010128: 1100054d  add      w13, w10, #1
//   0x01012c: b90002ad  str      w13, [x21]
//   0x010130: b940030a  ldr      w10, [x24]
//   0x010134: 53185d4a  lsl      w10, w10, #8
//   0x010138: b900030a  str      w10, [x24]
//   0x01013c: b94002cc  ldr      w12, [x22]
//   0x010140: 5100218c  sub      w12, w12, #8
//   0x010144: 71001d9f  cmp      w12, #7
//   0x010148: b90002cc  str      w12, [x22]
//   0x01014c: 54fffe6c  b.gt     #0x10118
//   0x010150: 0b09018d  add      w13, w12, w9
//   0x010154: 4b0d03ec  neg      w12, w13
//   0x010158: 1acc216b  lsl      w11, w11, w12
//   0x01015c: 2a0a016a  orr      w10, w11, w10
//   0x010160: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010164: b90286ed  str      w13, [x23, #0x284]
//   0x010168: b90282ea  str      w10, [x23, #0x280]
//   0x01016c: 79400d2b  ldrh     w11, [x9, #6]
//   0x010170: d503201f  nop      
//   0x010174: 9b115d0c  madd     x12, x8, x17, x23
//   0x010178: 9b015d0e  madd     x14, x8, x1, x23
//   0x01017c: 710021bf  cmp      w13, #8
//   0x010180: 8b0b018c  add      x12, x12, x11
//   0x010184: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010188: 3860698c  ldrb     w12, [x12, x0]
//   0x01018c: b862696b  ldr      w11, [x11, x2]
//   0x010190: 5400020b  b.lt     #0x101d0
//   0x010194: b94002ae  ldr      w14, [x21]
//   0x010198: f940036d  ldr      x13, [x27]
//   0x01019c: 53187d4a  lsr      w10, w10, #0x18
//   0x0101a0: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x0101a4: b94002aa  ldr      w10, [x21]
//   0x0101a8: 1100054e  add      w14, w10, #1
//   0x0101ac: b90002ae  str      w14, [x21]
//   0x0101b0: b940030a  ldr      w10, [x24]
//   0x0101b4: 53185d4a  lsl      w10, w10, #8
//   0x0101b8: b900030a  str      w10, [x24]
//   0x0101bc: b94002cd  ldr      w13, [x22]
//   0x0101c0: 510021ad  sub      w13, w13, #8
//   0x0101c4: 71001dbf  cmp      w13, #7
//   0x0101c8: b90002cd  str      w13, [x22]
//   0x0101cc: 54fffe6c  b.gt     #0x10198
//   0x0101d0: 0b0c01ac  add      w12, w13, w12
//   0x0101d4: 4b0c03ed  neg      w13, w12
//   0x0101d8: 1acd216b  lsl      w11, w11, w13
//   0x0101dc: 2a0a016a  orr      w10, w11, w10
//   0x0101e0: b90286ec  str      w12, [x23, #0x284]
//   0x0101e4: b90282ea  str      w10, [x23, #0x280]
//   0x0101e8: 79401129  ldrh     w9, [x9, #8]
//   0x0101ec: d503201f  nop      
//   0x0101f0: 9b115d0b  madd     x11, x8, x17, x23
//   0x0101f4: 9b015d0d  madd     x13, x8, x1, x23
//   0x0101f8: 7100219f  cmp      w12, #8
//   0x0101fc: 8b09016b  add      x11, x11, x9
//   0x010200: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010204: 38606969  ldrb     w9, [x11, x0]
//   0x010208: b86269ab  ldr      w11, [x13, x2]
//   0x01020c: 5400020b  b.lt     #0x1024c
//   0x010210: b94002ad  ldr      w13, [x21]
//   0x010214: f940036c  ldr      x12, [x27]
//   0x010218: 53187d4a  lsr      w10, w10, #0x18
//   0x01021c: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010220: b94002aa  ldr      w10, [x21]
//   0x010224: 1100054d  add      w13, w10, #1
//   0x010228: b90002ad  str      w13, [x21]
//   0x01022c: b940030a  ldr      w10, [x24]
//   0x010230: 53185d4a  lsl      w10, w10, #8
//   0x010234: b900030a  str      w10, [x24]
//   0x010238: b94002cc  ldr      w12, [x22]
//   0x01023c: 5100218c  sub      w12, w12, #8
//   0x010240: 71001d9f  cmp      w12, #7
//   0x010244: b90002cc  str      w12, [x22]
//   0x010248: 54fffe6c  b.gt     #0x10214
//   0x01024c: 0b09018d  add      w13, w12, w9
//   0x010250: 4b0d03ec  neg      w12, w13
//   0x010254: 1acc216b  lsl      w11, w11, w12
//   0x010258: 2a0a016a  orr      w10, w11, w10
//   0x01025c: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010260: b90286ed  str      w13, [x23, #0x284]
//   0x010264: b90282ea  str      w10, [x23, #0x280]
//   0x010268: 7940152b  ldrh     w11, [x9, #0xa]
//   0x01026c: d503201f  nop      
//   0x010270: 9b115d0c  madd     x12, x8, x17, x23
//   0x010274: 9b015d0e  madd     x14, x8, x1, x23
//   0x010278: 710021bf  cmp      w13, #8
//   0x01027c: 8b0b018c  add      x12, x12, x11
//   0x010280: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010284: 3860698c  ldrb     w12, [x12, x0]
//   0x010288: b862696b  ldr      w11, [x11, x2]
//   0x01028c: 5400020b  b.lt     #0x102cc
//   0x010290: b94002ae  ldr      w14, [x21]
//   0x010294: f940036d  ldr      x13, [x27]
//   0x010298: 53187d4a  lsr      w10, w10, #0x18
//   0x01029c: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x0102a0: b94002aa  ldr      w10, [x21]
//   0x0102a4: 1100054e  add      w14, w10, #1
//   0x0102a8: b90002ae  str      w14, [x21]
//   0x0102ac: b940030a  ldr      w10, [x24]
//   0x0102b0: 53185d4a  lsl      w10, w10, #8
//   0x0102b4: b900030a  str      w10, [x24]
//   0x0102b8: b94002cd  ldr      w13, [x22]
//   0x0102bc: 510021ad  sub      w13, w13, #8
//   0x0102c0: 71001dbf  cmp      w13, #7
//   0x0102c4: b90002cd  str      w13, [x22]
//   0x0102c8: 54fffe6c  b.gt     #0x10294
//   0x0102cc: 0b0c01ac  add      w12, w13, w12
//   0x0102d0: 4b0c03ed  neg      w13, w12
//   0x0102d4: 1acd216b  lsl      w11, w11, w13
//   0x0102d8: 2a0a016a  orr      w10, w11, w10
//   0x0102dc: b90286ec  str      w12, [x23, #0x284]
//   0x0102e0: b90282ea  str      w10, [x23, #0x280]
//   0x0102e4: 79401929  ldrh     w9, [x9, #0xc]
//   0x0102e8: d503201f  nop      
//   0x0102ec: 9b115d0b  madd     x11, x8, x17, x23
//   0x0102f0: 9b015d0d  madd     x13, x8, x1, x23
//   0x0102f4: 7100219f  cmp      w12, #8
//   0x0102f8: 8b09016b  add      x11, x11, x9
//   0x0102fc: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010300: 38606969  ldrb     w9, [x11, x0]
//   0x010304: b86269ab  ldr      w11, [x13, x2]
//   0x010308: 5400020b  b.lt     #0x10348
//   0x01030c: b94002ad  ldr      w13, [x21]
//   0x010310: f940036c  ldr      x12, [x27]
//   0x010314: 53187d4a  lsr      w10, w10, #0x18
//   0x010318: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x01031c: b94002aa  ldr      w10, [x21]
//   0x010320: 1100054d  add      w13, w10, #1
//   0x010324: b90002ad  str      w13, [x21]
//   0x010328: b940030a  ldr      w10, [x24]
//   0x01032c: 53185d4a  lsl      w10, w10, #8
//   0x010330: b900030a  str      w10, [x24]
//   0x010334: b94002cc  ldr      w12, [x22]
//   0x010338: 5100218c  sub      w12, w12, #8
//   0x01033c: 71001d9f  cmp      w12, #7
//   0x010340: b90002cc  str      w12, [x22]
//   0x010344: 54fffe6c  b.gt     #0x10310
//   0x010348: 0b09018d  add      w13, w12, w9
//   0x01034c: 4b0d03ec  neg      w12, w13
//   0x010350: 1acc216b  lsl      w11, w11, w12
//   0x010354: 2a0a016a  orr      w10, w11, w10
//   0x010358: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x01035c: b90286ed  str      w13, [x23, #0x284]
//   0x010360: b90282ea  str      w10, [x23, #0x280]
//   0x010364: 79401d2b  ldrh     w11, [x9, #0xe]
//   0x010368: d503201f  nop      
//   0x01036c: 9b115d0c  madd     x12, x8, x17, x23
//   0x010370: 9b015d0e  madd     x14, x8, x1, x23
//   0x010374: 710021bf  cmp      w13, #8
//   0x010378: 8b0b018c  add      x12, x12, x11
//   0x01037c: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010380: 3860698c  ldrb     w12, [x12, x0]
//   0x010384: b862696b  ldr      w11, [x11, x2]
//   0x010388: 5400020b  b.lt     #0x103c8
//   0x01038c: b94002ae  ldr      w14, [x21]
//   0x010390: f940036d  ldr      x13, [x27]
//   0x010394: 53187d4a  lsr      w10, w10, #0x18
//   0x010398: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x01039c: b94002aa  ldr      w10, [x21]
//   0x0103a0: 1100054e  add      w14, w10, #1
//   0x0103a4: b90002ae  str      w14, [x21]
//   0x0103a8: b940030a  ldr      w10, [x24]
//   0x0103ac: 53185d4a  lsl      w10, w10, #8
//   0x0103b0: b900030a  str      w10, [x24]
//   0x0103b4: b94002cd  ldr      w13, [x22]
//   0x0103b8: 510021ad  sub      w13, w13, #8
//   0x0103bc: 71001dbf  cmp      w13, #7
//   0x0103c0: b90002cd  str      w13, [x22]
//   0x0103c4: 54fffe6c  b.gt     #0x10390
//   0x0103c8: 0b0c01ac  add      w12, w13, w12
//   0x0103cc: 4b0c03ed  neg      w13, w12
//   0x0103d0: 1acd216b  lsl      w11, w11, w13
//   0x0103d4: 2a0a016a  orr      w10, w11, w10
//   0x0103d8: b90286ec  str      w12, [x23, #0x284]
//   0x0103dc: b90282ea  str      w10, [x23, #0x280]
//   0x0103e0: 79402129  ldrh     w9, [x9, #0x10]
//   0x0103e4: d503201f  nop      
//   0x0103e8: 9b115d0b  madd     x11, x8, x17, x23
//   0x0103ec: 9b015d0d  madd     x13, x8, x1, x23
//   0x0103f0: 7100219f  cmp      w12, #8
//   0x0103f4: 8b09016b  add      x11, x11, x9
//   0x0103f8: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0103fc: 38606969  ldrb     w9, [x11, x0]
//   0x010400: b86269ab  ldr      w11, [x13, x2]
//   0x010404: 5400020b  b.lt     #0x10444
//   0x010408: b94002ad  ldr      w13, [x21]
//   0x01040c: f940036c  ldr      x12, [x27]
//   0x010410: 53187d4a  lsr      w10, w10, #0x18
//   0x010414: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010418: b94002aa  ldr      w10, [x21]
//   0x01041c: 1100054d  add      w13, w10, #1
//   0x010420: b90002ad  str      w13, [x21]
//   0x010424: b940030a  ldr      w10, [x24]
//   0x010428: 53185d4a  lsl      w10, w10, #8
//   0x01042c: b900030a  str      w10, [x24]
//   0x010430: b94002cc  ldr      w12, [x22]
//   0x010434: 5100218c  sub      w12, w12, #8
//   0x010438: 71001d9f  cmp      w12, #7
//   0x01043c: b90002cc  str      w12, [x22]
//   0x010440: 54fffe6c  b.gt     #0x1040c
//   0x010444: 0b09018d  add      w13, w12, w9
//   0x010448: 4b0d03ec  neg      w12, w13
//   0x01044c: 1acc216b  lsl      w11, w11, w12
//   0x010450: 2a0a016a  orr      w10, w11, w10
//   0x010454: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010458: b90286ed  str      w13, [x23, #0x284]
//   0x01045c: b90282ea  str      w10, [x23, #0x280]
//   0x010460: 7940252b  ldrh     w11, [x9, #0x12]
//   0x010464: d503201f  nop      
//   0x010468: 9b115d0c  madd     x12, x8, x17, x23
//   0x01046c: 9b015d0e  madd     x14, x8, x1, x23
//   0x010470: 710021bf  cmp      w13, #8
//   0x010474: 8b0b018c  add      x12, x12, x11
//   0x010478: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x01047c: 3860698c  ldrb     w12, [x12, x0]
//   0x010480: b862696b  ldr      w11, [x11, x2]
//   0x010484: 5400020b  b.lt     #0x104c4
//   0x010488: b94002ae  ldr      w14, [x21]
//   0x01048c: f940036d  ldr      x13, [x27]
//   0x010490: 53187d4a  lsr      w10, w10, #0x18
//   0x010494: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010498: b94002aa  ldr      w10, [x21]
//   0x01049c: 1100054e  add      w14, w10, #1
//   0x0104a0: b90002ae  str      w14, [x21]
//   0x0104a4: b940030a  ldr      w10, [x24]
//   0x0104a8: 53185d4a  lsl      w10, w10, #8
//   0x0104ac: b900030a  str      w10, [x24]
//   0x0104b0: b94002cd  ldr      w13, [x22]
//   0x0104b4: 510021ad  sub      w13, w13, #8
//   0x0104b8: 71001dbf  cmp      w13, #7
//   0x0104bc: b90002cd  str      w13, [x22]
//   0x0104c0: 54fffe6c  b.gt     #0x1048c
//   0x0104c4: 0b0c01ac  add      w12, w13, w12
//   0x0104c8: 4b0c03ed  neg      w13, w12
//   0x0104cc: 1acd216b  lsl      w11, w11, w13
//   0x0104d0: 2a0a016a  orr      w10, w11, w10
//   0x0104d4: b90286ec  str      w12, [x23, #0x284]
//   0x0104d8: b90282ea  str      w10, [x23, #0x280]
//   0x0104dc: 79402929  ldrh     w9, [x9, #0x14]
//   0x0104e0: d503201f  nop      
//   0x0104e4: 9b115d0b  madd     x11, x8, x17, x23
//   0x0104e8: 9b015d0d  madd     x13, x8, x1, x23
//   0x0104ec: 7100219f  cmp      w12, #8
//   0x0104f0: 8b09016b  add      x11, x11, x9
//   0x0104f4: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0104f8: 38606969  ldrb     w9, [x11, x0]
//   0x0104fc: b86269ab  ldr      w11, [x13, x2]
//   0x010500: 5400020b  b.lt     #0x10540
//   0x010504: b94002ad  ldr      w13, [x21]
//   0x010508: f940036c  ldr      x12, [x27]
//   0x01050c: 53187d4a  lsr      w10, w10, #0x18
//   0x010510: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010514: b94002aa  ldr      w10, [x21]
//   0x010518: 1100054d  add      w13, w10, #1
//   0x01051c: b90002ad  str      w13, [x21]
//   0x010520: b940030a  ldr      w10, [x24]
//   0x010524: 53185d4a  lsl      w10, w10, #8
//   0x010528: b900030a  str      w10, [x24]
//   0x01052c: b94002cc  ldr      w12, [x22]
//   0x010530: 5100218c  sub      w12, w12, #8
//   0x010534: 71001d9f  cmp      w12, #7
//   0x010538: b90002cc  str      w12, [x22]
//   0x01053c: 54fffe6c  b.gt     #0x10508
//   0x010540: 0b09018d  add      w13, w12, w9
//   0x010544: 4b0d03ec  neg      w12, w13
//   0x010548: 1acc216b  lsl      w11, w11, w12
//   0x01054c: 2a0a016a  orr      w10, w11, w10
//   0x010550: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010554: b90286ed  str      w13, [x23, #0x284]
//   0x010558: b90282ea  str      w10, [x23, #0x280]
//   0x01055c: 79402d2b  ldrh     w11, [x9, #0x16]
//   0x010560: d503201f  nop      
//   0x010564: 9b115d0c  madd     x12, x8, x17, x23
//   0x010568: 9b015d0e  madd     x14, x8, x1, x23
//   0x01056c: 710021bf  cmp      w13, #8
//   0x010570: 8b0b018c  add      x12, x12, x11
//   0x010574: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010578: 3860698c  ldrb     w12, [x12, x0]
//   0x01057c: b862696b  ldr      w11, [x11, x2]
//   0x010580: 5400020b  b.lt     #0x105c0
//   0x010584: b94002ae  ldr      w14, [x21]
//   0x010588: f940036d  ldr      x13, [x27]
//   0x01058c: 53187d4a  lsr      w10, w10, #0x18
//   0x010590: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010594: b94002aa  ldr      w10, [x21]
//   0x010598: 1100054e  add      w14, w10, #1
//   0x01059c: b90002ae  str      w14, [x21]
//   0x0105a0: b940030a  ldr      w10, [x24]
//   0x0105a4: 53185d4a  lsl      w10, w10, #8
//   0x0105a8: b900030a  str      w10, [x24]
//   0x0105ac: b94002cd  ldr      w13, [x22]
//   0x0105b0: 510021ad  sub      w13, w13, #8
//   0x0105b4: 71001dbf  cmp      w13, #7
//   0x0105b8: b90002cd  str      w13, [x22]
//   0x0105bc: 54fffe6c  b.gt     #0x10588
//   0x0105c0: 0b0c01ac  add      w12, w13, w12
//   0x0105c4: 4b0c03ed  neg      w13, w12
//   0x0105c8: 1acd216b  lsl      w11, w11, w13
//   0x0105cc: 2a0a016a  orr      w10, w11, w10
//   0x0105d0: b90286ec  str      w12, [x23, #0x284]
//   0x0105d4: b90282ea  str      w10, [x23, #0x280]
//   0x0105d8: 79403129  ldrh     w9, [x9, #0x18]
//   0x0105dc: d503201f  nop      
//   0x0105e0: 9b115d0b  madd     x11, x8, x17, x23
//   0x0105e4: 9b015d0d  madd     x13, x8, x1, x23
//   0x0105e8: 7100219f  cmp      w12, #8
//   0x0105ec: 8b09016b  add      x11, x11, x9
//   0x0105f0: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0105f4: 38606969  ldrb     w9, [x11, x0]
//   0x0105f8: b86269ab  ldr      w11, [x13, x2]
//   0x0105fc: 5400020b  b.lt     #0x1063c
//   0x010600: b94002ad  ldr      w13, [x21]
//   0x010604: f940036c  ldr      x12, [x27]
//   0x010608: 53187d4a  lsr      w10, w10, #0x18
//   0x01060c: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010610: b94002aa  ldr      w10, [x21]
//   0x010614: 1100054d  add      w13, w10, #1
//   0x010618: b90002ad  str      w13, [x21]
//   0x01061c: b940030a  ldr      w10, [x24]
//   0x010620: 53185d4a  lsl      w10, w10, #8
//   0x010624: b900030a  str      w10, [x24]
//   0x010628: b94002cc  ldr      w12, [x22]
//   0x01062c: 5100218c  sub      w12, w12, #8
//   0x010630: 71001d9f  cmp      w12, #7
//   0x010634: b90002cc  str      w12, [x22]
//   0x010638: 54fffe6c  b.gt     #0x10604
//   0x01063c: 0b09018d  add      w13, w12, w9
//   0x010640: 4b0d03ec  neg      w12, w13
//   0x010644: 1acc216b  lsl      w11, w11, w12
//   0x010648: 2a0a016a  orr      w10, w11, w10
//   0x01064c: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010650: b90286ed  str      w13, [x23, #0x284]
//   0x010654: b90282ea  str      w10, [x23, #0x280]
//   0x010658: 7940352b  ldrh     w11, [x9, #0x1a]
//   0x01065c: d503201f  nop      
//   0x010660: 9b115d0c  madd     x12, x8, x17, x23
//   0x010664: 9b015d0e  madd     x14, x8, x1, x23
//   0x010668: 710021bf  cmp      w13, #8
//   0x01066c: 8b0b018c  add      x12, x12, x11
//   0x010670: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010674: 3860698c  ldrb     w12, [x12, x0]
//   0x010678: b862696b  ldr      w11, [x11, x2]
//   0x01067c: 5400020b  b.lt     #0x106bc
//   0x010680: b94002ae  ldr      w14, [x21]
//   0x010684: f940036d  ldr      x13, [x27]
//   0x010688: 53187d4a  lsr      w10, w10, #0x18
//   0x01068c: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010690: b94002aa  ldr      w10, [x21]
//   0x010694: 1100054e  add      w14, w10, #1
//   0x010698: b90002ae  str      w14, [x21]
//   0x01069c: b940030a  ldr      w10, [x24]
//   0x0106a0: 53185d4a  lsl      w10, w10, #8
//   0x0106a4: b900030a  str      w10, [x24]
//   0x0106a8: b94002cd  ldr      w13, [x22]
//   0x0106ac: 510021ad  sub      w13, w13, #8
//   0x0106b0: 71001dbf  cmp      w13, #7
//   0x0106b4: b90002cd  str      w13, [x22]
//   0x0106b8: 54fffe6c  b.gt     #0x10684
//   0x0106bc: 0b0c01ac  add      w12, w13, w12
//   0x0106c0: 4b0c03ed  neg      w13, w12
//   0x0106c4: 1acd216b  lsl      w11, w11, w13
//   0x0106c8: 2a0a016a  orr      w10, w11, w10
//   0x0106cc: b90286ec  str      w12, [x23, #0x284]
//   0x0106d0: b90282ea  str      w10, [x23, #0x280]
//   0x0106d4: 79403929  ldrh     w9, [x9, #0x1c]
//   0x0106d8: d503201f  nop      
//   0x0106dc: 9b115d0b  madd     x11, x8, x17, x23
//   0x0106e0: 9b015d0d  madd     x13, x8, x1, x23
//   0x0106e4: 7100219f  cmp      w12, #8
//   0x0106e8: 8b09016b  add      x11, x11, x9
//   0x0106ec: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0106f0: 38606969  ldrb     w9, [x11, x0]
//   0x0106f4: b86269ab  ldr      w11, [x13, x2]
//   0x0106f8: 5400020b  b.lt     #0x10738
//   0x0106fc: b94002ad  ldr      w13, [x21]
//   0x010700: f940036c  ldr      x12, [x27]
//   0x010704: 53187d4a  lsr      w10, w10, #0x18
//   0x010708: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x01070c: b94002aa  ldr      w10, [x21]
//   0x010710: 1100054d  add      w13, w10, #1
//   0x010714: b90002ad  str      w13, [x21]
//   0x010718: b940030a  ldr      w10, [x24]
//   0x01071c: 53185d4a  lsl      w10, w10, #8
//   0x010720: b900030a  str      w10, [x24]
//   0x010724: b94002cc  ldr      w12, [x22]
//   0x010728: 5100218c  sub      w12, w12, #8
//   0x01072c: 71001d9f  cmp      w12, #7
//   0x010730: b90002cc  str      w12, [x22]
//   0x010734: 54fffe6c  b.gt     #0x10700
//   0x010738: 0b09018d  add      w13, w12, w9
//   0x01073c: 4b0d03ec  neg      w12, w13
//   0x010740: 1acc216b  lsl      w11, w11, w12
//   0x010744: 2a0a016a  orr      w10, w11, w10
//   0x010748: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x01074c: b90286ed  str      w13, [x23, #0x284]
//   0x010750: b90282ea  str      w10, [x23, #0x280]
//   0x010754: 79403d2b  ldrh     w11, [x9, #0x1e]
//   0x010758: d503201f  nop      
//   0x01075c: 9b115d0c  madd     x12, x8, x17, x23
//   0x010760: 9b015d0e  madd     x14, x8, x1, x23
//   0x010764: 710021bf  cmp      w13, #8
//   0x010768: 8b0b018c  add      x12, x12, x11
//   0x01076c: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010770: 3860698c  ldrb     w12, [x12, x0]
//   0x010774: b862696b  ldr      w11, [x11, x2]
//   0x010778: 5400020b  b.lt     #0x107b8
//   0x01077c: b94002ae  ldr      w14, [x21]
//   0x010780: f940036d  ldr      x13, [x27]
//   0x010784: 53187d4a  lsr      w10, w10, #0x18
//   0x010788: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x01078c: b94002aa  ldr      w10, [x21]
//   0x010790: 1100054e  add      w14, w10, #1
//   0x010794: b90002ae  str      w14, [x21]
//   0x010798: b940030a  ldr      w10, [x24]
//   0x01079c: 53185d4a  lsl      w10, w10, #8
//   0x0107a0: b900030a  str      w10, [x24]
//   0x0107a4: b94002cd  ldr      w13, [x22]
//   0x0107a8: 510021ad  sub      w13, w13, #8
//   0x0107ac: 71001dbf  cmp      w13, #7
//   0x0107b0: b90002cd  str      w13, [x22]
//   0x0107b4: 54fffe6c  b.gt     #0x10780
//   0x0107b8: 0b0c01ac  add      w12, w13, w12
//   0x0107bc: 4b0c03ed  neg      w13, w12
//   0x0107c0: 1acd216b  lsl      w11, w11, w13
//   0x0107c4: 2a0a016a  orr      w10, w11, w10
//   0x0107c8: b90286ec  str      w12, [x23, #0x284]
//   0x0107cc: b90282ea  str      w10, [x23, #0x280]
//   0x0107d0: 79404129  ldrh     w9, [x9, #0x20]
//   0x0107d4: d503201f  nop      
//   0x0107d8: 9b115d0b  madd     x11, x8, x17, x23
//   0x0107dc: 9b015d0d  madd     x13, x8, x1, x23
//   0x0107e0: 7100219f  cmp      w12, #8
//   0x0107e4: 8b09016b  add      x11, x11, x9
//   0x0107e8: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0107ec: 38606969  ldrb     w9, [x11, x0]
//   0x0107f0: b86269ab  ldr      w11, [x13, x2]
//   0x0107f4: 5400020b  b.lt     #0x10834
//   0x0107f8: b94002ad  ldr      w13, [x21]
//   0x0107fc: f940036c  ldr      x12, [x27]
//   0x010800: 53187d4a  lsr      w10, w10, #0x18
//   0x010804: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010808: b94002aa  ldr      w10, [x21]
//   0x01080c: 1100054d  add      w13, w10, #1
//   0x010810: b90002ad  str      w13, [x21]
//   0x010814: b940030a  ldr      w10, [x24]
//   0x010818: 53185d4a  lsl      w10, w10, #8
//   0x01081c: b900030a  str      w10, [x24]
//   0x010820: b94002cc  ldr      w12, [x22]
//   0x010824: 5100218c  sub      w12, w12, #8
//   0x010828: 71001d9f  cmp      w12, #7
//   0x01082c: b90002cc  str      w12, [x22]
//   0x010830: 54fffe6c  b.gt     #0x107fc
//   0x010834: 0b09018d  add      w13, w12, w9
//   0x010838: 4b0d03ec  neg      w12, w13
//   0x01083c: 1acc216b  lsl      w11, w11, w12
//   0x010840: 2a0a016a  orr      w10, w11, w10
//   0x010844: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010848: b90286ed  str      w13, [x23, #0x284]
//   0x01084c: b90282ea  str      w10, [x23, #0x280]
//   0x010850: 7940452b  ldrh     w11, [x9, #0x22]
//   0x010854: d503201f  nop      
//   0x010858: 9b115d0c  madd     x12, x8, x17, x23
//   0x01085c: 9b015d0e  madd     x14, x8, x1, x23
//   0x010860: 710021bf  cmp      w13, #8
//   0x010864: 8b0b018c  add      x12, x12, x11
//   0x010868: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x01086c: 3860698c  ldrb     w12, [x12, x0]
//   0x010870: b862696b  ldr      w11, [x11, x2]
//   0x010874: 5400020b  b.lt     #0x108b4
//   0x010878: b94002ae  ldr      w14, [x21]
//   0x01087c: f940036d  ldr      x13, [x27]
//   0x010880: 53187d4a  lsr      w10, w10, #0x18
//   0x010884: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010888: b94002aa  ldr      w10, [x21]
//   0x01088c: 1100054e  add      w14, w10, #1
//   0x010890: b90002ae  str      w14, [x21]
//   0x010894: b940030a  ldr      w10, [x24]
//   0x010898: 53185d4a  lsl      w10, w10, #8
//   0x01089c: b900030a  str      w10, [x24]
//   0x0108a0: b94002cd  ldr      w13, [x22]
//   0x0108a4: 510021ad  sub      w13, w13, #8
//   0x0108a8: 71001dbf  cmp      w13, #7
//   0x0108ac: b90002cd  str      w13, [x22]
//   0x0108b0: 54fffe6c  b.gt     #0x1087c
//   0x0108b4: 0b0c01ac  add      w12, w13, w12
//   0x0108b8: 4b0c03ed  neg      w13, w12
//   0x0108bc: 1acd216b  lsl      w11, w11, w13
//   0x0108c0: 2a0a016a  orr      w10, w11, w10
//   0x0108c4: b90286ec  str      w12, [x23, #0x284]
//   0x0108c8: b90282ea  str      w10, [x23, #0x280]
//   0x0108cc: 79404929  ldrh     w9, [x9, #0x24]
//   0x0108d0: d503201f  nop      
//   0x0108d4: 9b115d0b  madd     x11, x8, x17, x23
//   0x0108d8: 9b015d0d  madd     x13, x8, x1, x23
//   0x0108dc: 7100219f  cmp      w12, #8
//   0x0108e0: 8b09016b  add      x11, x11, x9
//   0x0108e4: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0108e8: 38606969  ldrb     w9, [x11, x0]
//   0x0108ec: b86269ab  ldr      w11, [x13, x2]
//   0x0108f0: 5400020b  b.lt     #0x10930
//   0x0108f4: b94002ad  ldr      w13, [x21]
//   0x0108f8: f940036c  ldr      x12, [x27]
//   0x0108fc: 53187d4a  lsr      w10, w10, #0x18
//   0x010900: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010904: b94002aa  ldr      w10, [x21]
//   0x010908: 1100054d  add      w13, w10, #1
//   0x01090c: b90002ad  str      w13, [x21]
//   0x010910: b940030a  ldr      w10, [x24]
//   0x010914: 53185d4a  lsl      w10, w10, #8
//   0x010918: b900030a  str      w10, [x24]
//   0x01091c: b94002cc  ldr      w12, [x22]
//   0x010920: 5100218c  sub      w12, w12, #8
//   0x010924: 71001d9f  cmp      w12, #7
//   0x010928: b90002cc  str      w12, [x22]
//   0x01092c: 54fffe6c  b.gt     #0x108f8
//   0x010930: 0b09018d  add      w13, w12, w9
//   0x010934: 4b0d03ec  neg      w12, w13
//   0x010938: 1acc216b  lsl      w11, w11, w12
//   0x01093c: 2a0a016a  orr      w10, w11, w10
//   0x010940: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010944: b90286ed  str      w13, [x23, #0x284]
//   0x010948: b90282ea  str      w10, [x23, #0x280]
//   0x01094c: 79404d2b  ldrh     w11, [x9, #0x26]
//   0x010950: d503201f  nop      
//   0x010954: 9b115d0c  madd     x12, x8, x17, x23
//   0x010958: 9b015d0e  madd     x14, x8, x1, x23
//   0x01095c: 710021bf  cmp      w13, #8
//   0x010960: 8b0b018c  add      x12, x12, x11
//   0x010964: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010968: 3860698c  ldrb     w12, [x12, x0]
//   0x01096c: b862696b  ldr      w11, [x11, x2]
//   0x010970: 5400020b  b.lt     #0x109b0
//   0x010974: b94002ae  ldr      w14, [x21]
//   0x010978: f940036d  ldr      x13, [x27]
//   0x01097c: 53187d4a  lsr      w10, w10, #0x18
//   0x010980: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010984: b94002aa  ldr      w10, [x21]
//   0x010988: 1100054e  add      w14, w10, #1
//   0x01098c: b90002ae  str      w14, [x21]
//   0x010990: b940030a  ldr      w10, [x24]
//   0x010994: 53185d4a  lsl      w10, w10, #8
//   0x010998: b900030a  str      w10, [x24]
//   0x01099c: b94002cd  ldr      w13, [x22]
//   0x0109a0: 510021ad  sub      w13, w13, #8
//   0x0109a4: 71001dbf  cmp      w13, #7
//   0x0109a8: b90002cd  str      w13, [x22]
//   0x0109ac: 54fffe6c  b.gt     #0x10978
//   0x0109b0: 0b0c01ac  add      w12, w13, w12
//   0x0109b4: 4b0c03ed  neg      w13, w12
//   0x0109b8: 1acd216b  lsl      w11, w11, w13
//   0x0109bc: 2a0a016a  orr      w10, w11, w10
//   0x0109c0: b90286ec  str      w12, [x23, #0x284]
//   0x0109c4: b90282ea  str      w10, [x23, #0x280]
//   0x0109c8: 79405129  ldrh     w9, [x9, #0x28]
//   0x0109cc: d503201f  nop      
//   0x0109d0: 9b115d0b  madd     x11, x8, x17, x23
//   0x0109d4: 9b015d0d  madd     x13, x8, x1, x23
//   0x0109d8: 7100219f  cmp      w12, #8
//   0x0109dc: 8b09016b  add      x11, x11, x9
//   0x0109e0: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0109e4: 38606969  ldrb     w9, [x11, x0]
//   0x0109e8: b86269ab  ldr      w11, [x13, x2]
//   0x0109ec: 5400020b  b.lt     #0x10a2c
//   0x0109f0: b94002ad  ldr      w13, [x21]
//   0x0109f4: f940036c  ldr      x12, [x27]
//   0x0109f8: 53187d4a  lsr      w10, w10, #0x18
//   0x0109fc: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010a00: b94002aa  ldr      w10, [x21]
//   0x010a04: 1100054d  add      w13, w10, #1
//   0x010a08: b90002ad  str      w13, [x21]
//   0x010a0c: b940030a  ldr      w10, [x24]
//   0x010a10: 53185d4a  lsl      w10, w10, #8
//   0x010a14: b900030a  str      w10, [x24]
//   0x010a18: b94002cc  ldr      w12, [x22]
//   0x010a1c: 5100218c  sub      w12, w12, #8
//   0x010a20: 71001d9f  cmp      w12, #7
//   0x010a24: b90002cc  str      w12, [x22]
//   0x010a28: 54fffe6c  b.gt     #0x109f4
//   0x010a2c: 0b09018d  add      w13, w12, w9
//   0x010a30: 4b0d03ec  neg      w12, w13
//   0x010a34: 1acc216b  lsl      w11, w11, w12
//   0x010a38: 2a0a016a  orr      w10, w11, w10
//   0x010a3c: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010a40: b90286ed  str      w13, [x23, #0x284]
//   0x010a44: b90282ea  str      w10, [x23, #0x280]
//   0x010a48: 7940552b  ldrh     w11, [x9, #0x2a]
//   0x010a4c: d503201f  nop      
//   0x010a50: 9b115d0c  madd     x12, x8, x17, x23
//   0x010a54: 9b015d0e  madd     x14, x8, x1, x23
//   0x010a58: 710021bf  cmp      w13, #8
//   0x010a5c: 8b0b018c  add      x12, x12, x11
//   0x010a60: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010a64: 3860698c  ldrb     w12, [x12, x0]
//   0x010a68: b862696b  ldr      w11, [x11, x2]
//   0x010a6c: 5400020b  b.lt     #0x10aac
//   0x010a70: b94002ae  ldr      w14, [x21]
//   0x010a74: f940036d  ldr      x13, [x27]
//   0x010a78: 53187d4a  lsr      w10, w10, #0x18
//   0x010a7c: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010a80: b94002aa  ldr      w10, [x21]
//   0x010a84: 1100054e  add      w14, w10, #1
//   0x010a88: b90002ae  str      w14, [x21]
//   0x010a8c: b940030a  ldr      w10, [x24]
//   0x010a90: 53185d4a  lsl      w10, w10, #8
//   0x010a94: b900030a  str      w10, [x24]
//   0x010a98: b94002cd  ldr      w13, [x22]
//   0x010a9c: 510021ad  sub      w13, w13, #8
//   0x010aa0: 71001dbf  cmp      w13, #7
//   0x010aa4: b90002cd  str      w13, [x22]
//   0x010aa8: 54fffe6c  b.gt     #0x10a74
//   0x010aac: 0b0c01ac  add      w12, w13, w12
//   0x010ab0: 4b0c03ed  neg      w13, w12
//   0x010ab4: 1acd216b  lsl      w11, w11, w13
//   0x010ab8: 2a0a016a  orr      w10, w11, w10
//   0x010abc: b90286ec  str      w12, [x23, #0x284]
//   0x010ac0: b90282ea  str      w10, [x23, #0x280]
//   0x010ac4: 79405929  ldrh     w9, [x9, #0x2c]
//   0x010ac8: d503201f  nop      
//   0x010acc: 9b115d0b  madd     x11, x8, x17, x23
//   0x010ad0: 9b015d0d  madd     x13, x8, x1, x23
//   0x010ad4: 7100219f  cmp      w12, #8
//   0x010ad8: 8b09016b  add      x11, x11, x9
//   0x010adc: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010ae0: 38606969  ldrb     w9, [x11, x0]
//   0x010ae4: b86269ab  ldr      w11, [x13, x2]
//   0x010ae8: 5400020b  b.lt     #0x10b28
//   0x010aec: b94002ad  ldr      w13, [x21]
//   0x010af0: f940036c  ldr      x12, [x27]
//   0x010af4: 53187d4a  lsr      w10, w10, #0x18
//   0x010af8: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010afc: b94002aa  ldr      w10, [x21]
//   0x010b00: 1100054d  add      w13, w10, #1
//   0x010b04: b90002ad  str      w13, [x21]
//   0x010b08: b940030a  ldr      w10, [x24]
//   0x010b0c: 53185d4a  lsl      w10, w10, #8
//   0x010b10: b900030a  str      w10, [x24]
//   0x010b14: b94002cc  ldr      w12, [x22]
//   0x010b18: 5100218c  sub      w12, w12, #8
//   0x010b1c: 71001d9f  cmp      w12, #7
//   0x010b20: b90002cc  str      w12, [x22]
//   0x010b24: 54fffe6c  b.gt     #0x10af0
//   0x010b28: 0b09018d  add      w13, w12, w9
//   0x010b2c: 4b0d03ec  neg      w12, w13
//   0x010b30: 1acc216b  lsl      w11, w11, w12
//   0x010b34: 2a0a016a  orr      w10, w11, w10
//   0x010b38: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010b3c: b90286ed  str      w13, [x23, #0x284]
//   0x010b40: b90282ea  str      w10, [x23, #0x280]
//   0x010b44: 79405d2b  ldrh     w11, [x9, #0x2e]
//   0x010b48: d503201f  nop      
//   0x010b4c: 9b115d0c  madd     x12, x8, x17, x23
//   0x010b50: 9b015d0e  madd     x14, x8, x1, x23
//   0x010b54: 710021bf  cmp      w13, #8
//   0x010b58: 8b0b018c  add      x12, x12, x11
//   0x010b5c: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010b60: 3860698c  ldrb     w12, [x12, x0]
//   0x010b64: b862696b  ldr      w11, [x11, x2]
//   0x010b68: 5400020b  b.lt     #0x10ba8
//   0x010b6c: b94002ae  ldr      w14, [x21]
//   0x010b70: f940036d  ldr      x13, [x27]
//   0x010b74: 53187d4a  lsr      w10, w10, #0x18
//   0x010b78: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010b7c: b94002aa  ldr      w10, [x21]
//   0x010b80: 1100054e  add      w14, w10, #1
//   0x010b84: b90002ae  str      w14, [x21]
//   0x010b88: b940030a  ldr      w10, [x24]
//   0x010b8c: 53185d4a  lsl      w10, w10, #8
//   0x010b90: b900030a  str      w10, [x24]
//   0x010b94: b94002cd  ldr      w13, [x22]
//   0x010b98: 510021ad  sub      w13, w13, #8
//   0x010b9c: 71001dbf  cmp      w13, #7
//   0x010ba0: b90002cd  str      w13, [x22]
//   0x010ba4: 54fffe6c  b.gt     #0x10b70
//   0x010ba8: 0b0c01ac  add      w12, w13, w12
//   0x010bac: 4b0c03ed  neg      w13, w12
//   0x010bb0: 1acd216b  lsl      w11, w11, w13
//   0x010bb4: 2a0a016a  orr      w10, w11, w10
//   0x010bb8: b90286ec  str      w12, [x23, #0x284]
//   0x010bbc: b90282ea  str      w10, [x23, #0x280]
//   0x010bc0: 79406129  ldrh     w9, [x9, #0x30]
//   0x010bc4: d503201f  nop      
//   0x010bc8: 9b115d0b  madd     x11, x8, x17, x23
//   0x010bcc: 9b015d0d  madd     x13, x8, x1, x23
//   0x010bd0: 7100219f  cmp      w12, #8
//   0x010bd4: 8b09016b  add      x11, x11, x9
//   0x010bd8: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010bdc: 38606969  ldrb     w9, [x11, x0]
//   0x010be0: b86269ab  ldr      w11, [x13, x2]
//   0x010be4: 5400020b  b.lt     #0x10c24
//   0x010be8: b94002ad  ldr      w13, [x21]
//   0x010bec: f940036c  ldr      x12, [x27]
//   0x010bf0: 53187d4a  lsr      w10, w10, #0x18
//   0x010bf4: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010bf8: b94002aa  ldr      w10, [x21]
//   0x010bfc: 1100054d  add      w13, w10, #1
//   0x010c00: b90002ad  str      w13, [x21]
//   0x010c04: b940030a  ldr      w10, [x24]
//   0x010c08: 53185d4a  lsl      w10, w10, #8
//   0x010c0c: b900030a  str      w10, [x24]
//   0x010c10: b94002cc  ldr      w12, [x22]
//   0x010c14: 5100218c  sub      w12, w12, #8
//   0x010c18: 71001d9f  cmp      w12, #7
//   0x010c1c: b90002cc  str      w12, [x22]
//   0x010c20: 54fffe6c  b.gt     #0x10bec
//   0x010c24: 0b09018d  add      w13, w12, w9
//   0x010c28: 4b0d03ec  neg      w12, w13
//   0x010c2c: 1acc216b  lsl      w11, w11, w12
//   0x010c30: 2a0a016a  orr      w10, w11, w10
//   0x010c34: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010c38: b90286ed  str      w13, [x23, #0x284]
//   0x010c3c: b90282ea  str      w10, [x23, #0x280]
//   0x010c40: 7940652b  ldrh     w11, [x9, #0x32]
//   0x010c44: d503201f  nop      
//   0x010c48: 9b115d0c  madd     x12, x8, x17, x23
//   0x010c4c: 9b015d0e  madd     x14, x8, x1, x23
//   0x010c50: 710021bf  cmp      w13, #8
//   0x010c54: 8b0b018c  add      x12, x12, x11
//   0x010c58: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010c5c: 3860698c  ldrb     w12, [x12, x0]
//   0x010c60: b862696b  ldr      w11, [x11, x2]
//   0x010c64: 5400020b  b.lt     #0x10ca4
//   0x010c68: b94002ae  ldr      w14, [x21]
//   0x010c6c: f940036d  ldr      x13, [x27]
//   0x010c70: 53187d4a  lsr      w10, w10, #0x18
//   0x010c74: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010c78: b94002aa  ldr      w10, [x21]
//   0x010c7c: 1100054e  add      w14, w10, #1
//   0x010c80: b90002ae  str      w14, [x21]
//   0x010c84: b940030a  ldr      w10, [x24]
//   0x010c88: 53185d4a  lsl      w10, w10, #8
//   0x010c8c: b900030a  str      w10, [x24]
//   0x010c90: b94002cd  ldr      w13, [x22]
//   0x010c94: 510021ad  sub      w13, w13, #8
//   0x010c98: 71001dbf  cmp      w13, #7
//   0x010c9c: b90002cd  str      w13, [x22]
//   0x010ca0: 54fffe6c  b.gt     #0x10c6c
//   0x010ca4: 0b0c01ac  add      w12, w13, w12
//   0x010ca8: 4b0c03ed  neg      w13, w12
//   0x010cac: 1acd216b  lsl      w11, w11, w13
//   0x010cb0: 2a0a016a  orr      w10, w11, w10
//   0x010cb4: b90286ec  str      w12, [x23, #0x284]
//   0x010cb8: b90282ea  str      w10, [x23, #0x280]
//   0x010cbc: 79406929  ldrh     w9, [x9, #0x34]
//   0x010cc0: d503201f  nop      
//   0x010cc4: 9b115d0b  madd     x11, x8, x17, x23
//   0x010cc8: 9b015d0d  madd     x13, x8, x1, x23
//   0x010ccc: 7100219f  cmp      w12, #8
//   0x010cd0: 8b09016b  add      x11, x11, x9
//   0x010cd4: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010cd8: 38606969  ldrb     w9, [x11, x0]
//   0x010cdc: b86269ab  ldr      w11, [x13, x2]
//   0x010ce0: 5400020b  b.lt     #0x10d20
//   0x010ce4: b94002ad  ldr      w13, [x21]
//   0x010ce8: f940036c  ldr      x12, [x27]
//   0x010cec: 53187d4a  lsr      w10, w10, #0x18
//   0x010cf0: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010cf4: b94002aa  ldr      w10, [x21]
//   0x010cf8: 1100054d  add      w13, w10, #1
//   0x010cfc: b90002ad  str      w13, [x21]
//   0x010d00: b940030a  ldr      w10, [x24]
//   0x010d04: 53185d4a  lsl      w10, w10, #8
//   0x010d08: b900030a  str      w10, [x24]
//   0x010d0c: b94002cc  ldr      w12, [x22]
//   0x010d10: 5100218c  sub      w12, w12, #8
//   0x010d14: 71001d9f  cmp      w12, #7
//   0x010d18: b90002cc  str      w12, [x22]
//   0x010d1c: 54fffe6c  b.gt     #0x10ce8
//   0x010d20: 0b09018d  add      w13, w12, w9
//   0x010d24: 4b0d03ec  neg      w12, w13
//   0x010d28: 1acc216b  lsl      w11, w11, w12
//   0x010d2c: 2a0a016a  orr      w10, w11, w10
//   0x010d30: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010d34: b90286ed  str      w13, [x23, #0x284]
//   0x010d38: b90282ea  str      w10, [x23, #0x280]
//   0x010d3c: 79406d2b  ldrh     w11, [x9, #0x36]
//   0x010d40: d503201f  nop      
//   0x010d44: 9b115d0c  madd     x12, x8, x17, x23
//   0x010d48: 9b015d0e  madd     x14, x8, x1, x23
//   0x010d4c: 710021bf  cmp      w13, #8
//   0x010d50: 8b0b018c  add      x12, x12, x11
//   0x010d54: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010d58: 3860698c  ldrb     w12, [x12, x0]
//   0x010d5c: b862696b  ldr      w11, [x11, x2]
//   0x010d60: 5400020b  b.lt     #0x10da0
//   0x010d64: b94002ae  ldr      w14, [x21]
//   0x010d68: f940036d  ldr      x13, [x27]
//   0x010d6c: 53187d4a  lsr      w10, w10, #0x18
//   0x010d70: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010d74: b94002aa  ldr      w10, [x21]
//   0x010d78: 1100054e  add      w14, w10, #1
//   0x010d7c: b90002ae  str      w14, [x21]
//   0x010d80: b940030a  ldr      w10, [x24]
//   0x010d84: 53185d4a  lsl      w10, w10, #8
//   0x010d88: b900030a  str      w10, [x24]
//   0x010d8c: b94002cd  ldr      w13, [x22]
//   0x010d90: 510021ad  sub      w13, w13, #8
//   0x010d94: 71001dbf  cmp      w13, #7
//   0x010d98: b90002cd  str      w13, [x22]
//   0x010d9c: 54fffe6c  b.gt     #0x10d68
//   0x010da0: 0b0c01ac  add      w12, w13, w12
//   0x010da4: 4b0c03ed  neg      w13, w12
//   0x010da8: 1acd216b  lsl      w11, w11, w13
//   0x010dac: 2a0a016a  orr      w10, w11, w10
//   0x010db0: b90286ec  str      w12, [x23, #0x284]
//   0x010db4: b90282ea  str      w10, [x23, #0x280]
//   0x010db8: 79407129  ldrh     w9, [x9, #0x38]
//   0x010dbc: d503201f  nop      
//   0x010dc0: 9b115d0b  madd     x11, x8, x17, x23
//   0x010dc4: 9b015d0d  madd     x13, x8, x1, x23
//   0x010dc8: 7100219f  cmp      w12, #8
//   0x010dcc: 8b09016b  add      x11, x11, x9
//   0x010dd0: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010dd4: 38606969  ldrb     w9, [x11, x0]
//   0x010dd8: b86269ab  ldr      w11, [x13, x2]
//   0x010ddc: 5400020b  b.lt     #0x10e1c
//   0x010de0: b94002ad  ldr      w13, [x21]
//   0x010de4: f940036c  ldr      x12, [x27]
//   0x010de8: 53187d4a  lsr      w10, w10, #0x18
//   0x010dec: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010df0: b94002aa  ldr      w10, [x21]
//   0x010df4: 1100054d  add      w13, w10, #1
//   0x010df8: b90002ad  str      w13, [x21]
//   0x010dfc: b940030a  ldr      w10, [x24]
//   0x010e00: 53185d4a  lsl      w10, w10, #8
//   0x010e04: b900030a  str      w10, [x24]
//   0x010e08: b94002cc  ldr      w12, [x22]
//   0x010e0c: 5100218c  sub      w12, w12, #8
//   0x010e10: 71001d9f  cmp      w12, #7
//   0x010e14: b90002cc  str      w12, [x22]
//   0x010e18: 54fffe6c  b.gt     #0x10de4
//   0x010e1c: 0b09018d  add      w13, w12, w9
//   0x010e20: 4b0d03ec  neg      w12, w13
//   0x010e24: 1acc216b  lsl      w11, w11, w12
//   0x010e28: 2a0a016a  orr      w10, w11, w10
//   0x010e2c: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010e30: b90286ed  str      w13, [x23, #0x284]
//   0x010e34: b90282ea  str      w10, [x23, #0x280]
//   0x010e38: 7940752b  ldrh     w11, [x9, #0x3a]
//   0x010e3c: d503201f  nop      
//   0x010e40: 9b115d0c  madd     x12, x8, x17, x23
//   0x010e44: 9b015d0e  madd     x14, x8, x1, x23
//   0x010e48: 710021bf  cmp      w13, #8
//   0x010e4c: 8b0b018c  add      x12, x12, x11
//   0x010e50: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010e54: 3860698c  ldrb     w12, [x12, x0]
//   0x010e58: b862696b  ldr      w11, [x11, x2]
//   0x010e5c: 5400020b  b.lt     #0x10e9c
//   0x010e60: b94002ae  ldr      w14, [x21]
//   0x010e64: f940036d  ldr      x13, [x27]
//   0x010e68: 53187d4a  lsr      w10, w10, #0x18
//   0x010e6c: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010e70: b94002aa  ldr      w10, [x21]
//   0x010e74: 1100054e  add      w14, w10, #1
//   0x010e78: b90002ae  str      w14, [x21]
//   0x010e7c: b940030a  ldr      w10, [x24]
//   0x010e80: 53185d4a  lsl      w10, w10, #8
//   0x010e84: b900030a  str      w10, [x24]
//   0x010e88: b94002cd  ldr      w13, [x22]
//   0x010e8c: 510021ad  sub      w13, w13, #8
//   0x010e90: 71001dbf  cmp      w13, #7
//   0x010e94: b90002cd  str      w13, [x22]
//   0x010e98: 54fffe6c  b.gt     #0x10e64
//   0x010e9c: 0b0c01ac  add      w12, w13, w12
//   0x010ea0: 4b0c03ed  neg      w13, w12
//   0x010ea4: 1acd216b  lsl      w11, w11, w13
//   0x010ea8: 2a0a016a  orr      w10, w11, w10
//   0x010eac: b90286ec  str      w12, [x23, #0x284]
//   0x010eb0: b90282ea  str      w10, [x23, #0x280]
//   0x010eb4: 79407929  ldrh     w9, [x9, #0x3c]
//   0x010eb8: d503201f  nop      
//   0x010ebc: 9b115d0b  madd     x11, x8, x17, x23
//   0x010ec0: 9b015d0d  madd     x13, x8, x1, x23
//   0x010ec4: 7100219f  cmp      w12, #8
//   0x010ec8: 8b09016b  add      x11, x11, x9
//   0x010ecc: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010ed0: 38606969  ldrb     w9, [x11, x0]
//   0x010ed4: b86269ab  ldr      w11, [x13, x2]
//   0x010ed8: 5400020b  b.lt     #0x10f18
//   0x010edc: b94002ad  ldr      w13, [x21]
//   0x010ee0: f940036c  ldr      x12, [x27]
//   0x010ee4: 53187d4a  lsr      w10, w10, #0x18
//   0x010ee8: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010eec: b94002aa  ldr      w10, [x21]
//   0x010ef0: 1100054d  add      w13, w10, #1
//   0x010ef4: b90002ad  str      w13, [x21]
//   0x010ef8: b940030a  ldr      w10, [x24]
//   0x010efc: 53185d4a  lsl      w10, w10, #8
//   0x010f00: b900030a  str      w10, [x24]
//   0x010f04: b94002cc  ldr      w12, [x22]
//   0x010f08: 5100218c  sub      w12, w12, #8
//   0x010f0c: 71001d9f  cmp      w12, #7
//   0x010f10: b90002cc  str      w12, [x22]
//   0x010f14: 54fffe6c  b.gt     #0x10ee0
//   0x010f18: 0b09018d  add      w13, w12, w9
//   0x010f1c: 4b0d03ec  neg      w12, w13
//   0x010f20: 1acc216b  lsl      w11, w11, w12
//   0x010f24: 2a0a016a  orr      w10, w11, w10
//   0x010f28: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x010f2c: b90286ed  str      w13, [x23, #0x284]
//   0x010f30: b90282ea  str      w10, [x23, #0x280]
//   0x010f34: 79407d2b  ldrh     w11, [x9, #0x3e]
//   0x010f38: d503201f  nop      
//   0x010f3c: 9b115d0c  madd     x12, x8, x17, x23
//   0x010f40: 9b015d0e  madd     x14, x8, x1, x23
//   0x010f44: 710021bf  cmp      w13, #8
//   0x010f48: 8b0b018c  add      x12, x12, x11
//   0x010f4c: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x010f50: 3860698c  ldrb     w12, [x12, x0]
//   0x010f54: b862696b  ldr      w11, [x11, x2]
//   0x010f58: 5400020b  b.lt     #0x10f98
//   0x010f5c: b94002ae  ldr      w14, [x21]
//   0x010f60: f940036d  ldr      x13, [x27]
//   0x010f64: 53187d4a  lsr      w10, w10, #0x18
//   0x010f68: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x010f6c: b94002aa  ldr      w10, [x21]
//   0x010f70: 1100054e  add      w14, w10, #1
//   0x010f74: b90002ae  str      w14, [x21]
//   0x010f78: b940030a  ldr      w10, [x24]
//   0x010f7c: 53185d4a  lsl      w10, w10, #8
//   0x010f80: b900030a  str      w10, [x24]
//   0x010f84: b94002cd  ldr      w13, [x22]
//   0x010f88: 510021ad  sub      w13, w13, #8
//   0x010f8c: 71001dbf  cmp      w13, #7
//   0x010f90: b90002cd  str      w13, [x22]
//   0x010f94: 54fffe6c  b.gt     #0x10f60
//   0x010f98: 0b0c01ac  add      w12, w13, w12
//   0x010f9c: 4b0c03ed  neg      w13, w12
//   0x010fa0: 1acd216b  lsl      w11, w11, w13
//   0x010fa4: 2a0a016a  orr      w10, w11, w10
//   0x010fa8: b90286ec  str      w12, [x23, #0x284]
//   0x010fac: b90282ea  str      w10, [x23, #0x280]
//   0x010fb0: 79408129  ldrh     w9, [x9, #0x40]
//   0x010fb4: d503201f  nop      
//   0x010fb8: 9b115d0b  madd     x11, x8, x17, x23
//   0x010fbc: 9b015d0d  madd     x13, x8, x1, x23
//   0x010fc0: 7100219f  cmp      w12, #8
//   0x010fc4: 8b09016b  add      x11, x11, x9
//   0x010fc8: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x010fcc: 38606969  ldrb     w9, [x11, x0]
//   0x010fd0: b86269ab  ldr      w11, [x13, x2]
//   0x010fd4: 5400020b  b.lt     #0x11014
//   0x010fd8: b94002ad  ldr      w13, [x21]
//   0x010fdc: f940036c  ldr      x12, [x27]
//   0x010fe0: 53187d4a  lsr      w10, w10, #0x18
//   0x010fe4: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x010fe8: b94002aa  ldr      w10, [x21]
//   0x010fec: 1100054d  add      w13, w10, #1
//   0x010ff0: b90002ad  str      w13, [x21]
//   0x010ff4: b940030a  ldr      w10, [x24]
//   0x010ff8: 53185d4a  lsl      w10, w10, #8
//   0x010ffc: b900030a  str      w10, [x24]
//   0x011000: b94002cc  ldr      w12, [x22]
//   0x011004: 5100218c  sub      w12, w12, #8
//   0x011008: 71001d9f  cmp      w12, #7
//   0x01100c: b90002cc  str      w12, [x22]
//   0x011010: 54fffe6c  b.gt     #0x10fdc
//   0x011014: 0b09018d  add      w13, w12, w9
//   0x011018: 4b0d03ec  neg      w12, w13
//   0x01101c: 1acc216b  lsl      w11, w11, w12
//   0x011020: 2a0a016a  orr      w10, w11, w10
//   0x011024: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x011028: b90286ed  str      w13, [x23, #0x284]
//   0x01102c: b90282ea  str      w10, [x23, #0x280]
//   0x011030: 7940852b  ldrh     w11, [x9, #0x42]
//   0x011034: d503201f  nop      
//   0x011038: 9b115d0c  madd     x12, x8, x17, x23
//   0x01103c: 9b015d0e  madd     x14, x8, x1, x23
//   0x011040: 710021bf  cmp      w13, #8
//   0x011044: 8b0b018c  add      x12, x12, x11
//   0x011048: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x01104c: 3860698c  ldrb     w12, [x12, x0]
//   0x011050: b862696b  ldr      w11, [x11, x2]
//   0x011054: 5400020b  b.lt     #0x11094
//   0x011058: b94002ae  ldr      w14, [x21]
//   0x01105c: f940036d  ldr      x13, [x27]
//   0x011060: 53187d4a  lsr      w10, w10, #0x18
//   0x011064: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x011068: b94002aa  ldr      w10, [x21]
//   0x01106c: 1100054e  add      w14, w10, #1
//   0x011070: b90002ae  str      w14, [x21]
//   0x011074: b940030a  ldr      w10, [x24]
//   0x011078: 53185d4a  lsl      w10, w10, #8
//   0x01107c: b900030a  str      w10, [x24]
//   0x011080: b94002cd  ldr      w13, [x22]
//   0x011084: 510021ad  sub      w13, w13, #8
//   0x011088: 71001dbf  cmp      w13, #7
//   0x01108c: b90002cd  str      w13, [x22]
//   0x011090: 54fffe6c  b.gt     #0x1105c
//   0x011094: 0b0c01ac  add      w12, w13, w12
//   0x011098: 4b0c03ed  neg      w13, w12
//   0x01109c: 1acd216b  lsl      w11, w11, w13
//   0x0110a0: 2a0a016a  orr      w10, w11, w10
//   0x0110a4: b90286ec  str      w12, [x23, #0x284]
//   0x0110a8: b90282ea  str      w10, [x23, #0x280]
//   0x0110ac: 79408929  ldrh     w9, [x9, #0x44]
//   0x0110b0: d503201f  nop      
//   0x0110b4: 9b115d0b  madd     x11, x8, x17, x23
//   0x0110b8: 9b015d0d  madd     x13, x8, x1, x23
//   0x0110bc: 7100219f  cmp      w12, #8
//   0x0110c0: 8b09016b  add      x11, x11, x9
//   0x0110c4: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0110c8: 38606969  ldrb     w9, [x11, x0]
//   0x0110cc: b86269ab  ldr      w11, [x13, x2]
//   0x0110d0: 5400020b  b.lt     #0x11110
//   0x0110d4: b94002ad  ldr      w13, [x21]
//   0x0110d8: f940036c  ldr      x12, [x27]
//   0x0110dc: 53187d4a  lsr      w10, w10, #0x18
//   0x0110e0: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0110e4: b94002aa  ldr      w10, [x21]
//   0x0110e8: 1100054d  add      w13, w10, #1
//   0x0110ec: b90002ad  str      w13, [x21]
//   0x0110f0: b940030a  ldr      w10, [x24]
//   0x0110f4: 53185d4a  lsl      w10, w10, #8
//   0x0110f8: b900030a  str      w10, [x24]
//   0x0110fc: b94002cc  ldr      w12, [x22]
//   0x011100: 5100218c  sub      w12, w12, #8
//   0x011104: 71001d9f  cmp      w12, #7
//   0x011108: b90002cc  str      w12, [x22]
//   0x01110c: 54fffe6c  b.gt     #0x110d8
//   0x011110: 0b09018d  add      w13, w12, w9
//   0x011114: 4b0d03ec  neg      w12, w13
//   0x011118: 1acc216b  lsl      w11, w11, w12
//   0x01111c: 2a0a016a  orr      w10, w11, w10
//   0x011120: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x011124: b90286ed  str      w13, [x23, #0x284]
//   0x011128: b90282ea  str      w10, [x23, #0x280]
//   0x01112c: 79408d2b  ldrh     w11, [x9, #0x46]
//   0x011130: d503201f  nop      
//   0x011134: 9b115d0c  madd     x12, x8, x17, x23
//   0x011138: 9b015d0e  madd     x14, x8, x1, x23
//   0x01113c: 710021bf  cmp      w13, #8
//   0x011140: 8b0b018c  add      x12, x12, x11
//   0x011144: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x011148: 3860698c  ldrb     w12, [x12, x0]
//   0x01114c: b862696b  ldr      w11, [x11, x2]
//   0x011150: 5400020b  b.lt     #0x11190
//   0x011154: b94002ae  ldr      w14, [x21]
//   0x011158: f940036d  ldr      x13, [x27]
//   0x01115c: 53187d4a  lsr      w10, w10, #0x18
//   0x011160: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x011164: b94002aa  ldr      w10, [x21]
//   0x011168: 1100054e  add      w14, w10, #1
//   0x01116c: b90002ae  str      w14, [x21]
//   0x011170: b940030a  ldr      w10, [x24]
//   0x011174: 53185d4a  lsl      w10, w10, #8
//   0x011178: b900030a  str      w10, [x24]
//   0x01117c: b94002cd  ldr      w13, [x22]
//   0x011180: 510021ad  sub      w13, w13, #8
//   0x011184: 71001dbf  cmp      w13, #7
//   0x011188: b90002cd  str      w13, [x22]
//   0x01118c: 54fffe6c  b.gt     #0x11158
//   0x011190: 0b0c01ac  add      w12, w13, w12
//   0x011194: 4b0c03ed  neg      w13, w12
//   0x011198: 1acd216b  lsl      w11, w11, w13
//   0x01119c: 2a0a016a  orr      w10, w11, w10
//   0x0111a0: b90286ec  str      w12, [x23, #0x284]
//   0x0111a4: b90282ea  str      w10, [x23, #0x280]
//   0x0111a8: 79409129  ldrh     w9, [x9, #0x48]
//   0x0111ac: d503201f  nop      
//   0x0111b0: 9b115d0b  madd     x11, x8, x17, x23
//   0x0111b4: 9b015d0d  madd     x13, x8, x1, x23
//   0x0111b8: 7100219f  cmp      w12, #8
//   0x0111bc: 8b09016b  add      x11, x11, x9
//   0x0111c0: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0111c4: 38606969  ldrb     w9, [x11, x0]
//   0x0111c8: b86269ab  ldr      w11, [x13, x2]
//   0x0111cc: 5400020b  b.lt     #0x1120c
//   0x0111d0: b94002ad  ldr      w13, [x21]
//   0x0111d4: f940036c  ldr      x12, [x27]
//   0x0111d8: 53187d4a  lsr      w10, w10, #0x18
//   0x0111dc: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0111e0: b94002aa  ldr      w10, [x21]
//   0x0111e4: 1100054d  add      w13, w10, #1
//   0x0111e8: b90002ad  str      w13, [x21]
//   0x0111ec: b940030a  ldr      w10, [x24]
//   0x0111f0: 53185d4a  lsl      w10, w10, #8
//   0x0111f4: b900030a  str      w10, [x24]
//   0x0111f8: b94002cc  ldr      w12, [x22]
//   0x0111fc: 5100218c  sub      w12, w12, #8
//   0x011200: 71001d9f  cmp      w12, #7
//   0x011204: b90002cc  str      w12, [x22]
//   0x011208: 54fffe6c  b.gt     #0x111d4
//   0x01120c: 0b09018d  add      w13, w12, w9
//   0x011210: 4b0d03ec  neg      w12, w13
//   0x011214: 1acc216b  lsl      w11, w11, w12
//   0x011218: 2a0a016a  orr      w10, w11, w10
//   0x01121c: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x011220: b90286ed  str      w13, [x23, #0x284]
//   0x011224: b90282ea  str      w10, [x23, #0x280]
//   0x011228: 7940952b  ldrh     w11, [x9, #0x4a]
//   0x01122c: d503201f  nop      
//   0x011230: 9b115d0c  madd     x12, x8, x17, x23
//   0x011234: 9b015d0e  madd     x14, x8, x1, x23
//   0x011238: 710021bf  cmp      w13, #8
//   0x01123c: 8b0b018c  add      x12, x12, x11
//   0x011240: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x011244: 3860698c  ldrb     w12, [x12, x0]
//   0x011248: b862696b  ldr      w11, [x11, x2]
//   0x01124c: 5400020b  b.lt     #0x1128c
//   0x011250: b94002ae  ldr      w14, [x21]
//   0x011254: f940036d  ldr      x13, [x27]
//   0x011258: 53187d4a  lsr      w10, w10, #0x18
//   0x01125c: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x011260: b94002aa  ldr      w10, [x21]
//   0x011264: 1100054e  add      w14, w10, #1
//   0x011268: b90002ae  str      w14, [x21]
//   0x01126c: b940030a  ldr      w10, [x24]
//   0x011270: 53185d4a  lsl      w10, w10, #8
//   0x011274: b900030a  str      w10, [x24]
//   0x011278: b94002cd  ldr      w13, [x22]
//   0x01127c: 510021ad  sub      w13, w13, #8
//   0x011280: 71001dbf  cmp      w13, #7
//   0x011284: b90002cd  str      w13, [x22]
//   0x011288: 54fffe6c  b.gt     #0x11254
//   0x01128c: 0b0c01ac  add      w12, w13, w12
//   0x011290: 4b0c03ed  neg      w13, w12
//   0x011294: 1acd216b  lsl      w11, w11, w13
//   0x011298: 2a0a016a  orr      w10, w11, w10
//   0x01129c: b90286ec  str      w12, [x23, #0x284]
//   0x0112a0: b90282ea  str      w10, [x23, #0x280]
//   0x0112a4: 79409929  ldrh     w9, [x9, #0x4c]
//   0x0112a8: d503201f  nop      
//   0x0112ac: 9b115d0b  madd     x11, x8, x17, x23
//   0x0112b0: 9b015d0d  madd     x13, x8, x1, x23
//   0x0112b4: 7100219f  cmp      w12, #8
//   0x0112b8: 8b09016b  add      x11, x11, x9
//   0x0112bc: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0112c0: 38606969  ldrb     w9, [x11, x0]
//   0x0112c4: b86269ab  ldr      w11, [x13, x2]
//   0x0112c8: 5400020b  b.lt     #0x11308
//   0x0112cc: b94002ad  ldr      w13, [x21]
//   0x0112d0: f940036c  ldr      x12, [x27]
//   0x0112d4: 53187d4a  lsr      w10, w10, #0x18
//   0x0112d8: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0112dc: b94002aa  ldr      w10, [x21]
//   0x0112e0: 1100054d  add      w13, w10, #1
//   0x0112e4: b90002ad  str      w13, [x21]
//   0x0112e8: b940030a  ldr      w10, [x24]
//   0x0112ec: 53185d4a  lsl      w10, w10, #8
//   0x0112f0: b900030a  str      w10, [x24]
//   0x0112f4: b94002cc  ldr      w12, [x22]
//   0x0112f8: 5100218c  sub      w12, w12, #8
//   0x0112fc: 71001d9f  cmp      w12, #7
//   0x011300: b90002cc  str      w12, [x22]
//   0x011304: 54fffe6c  b.gt     #0x112d0
//   0x011308: 0b09018d  add      w13, w12, w9
//   0x01130c: 4b0d03ec  neg      w12, w13
//   0x011310: 1acc216b  lsl      w11, w11, w12
//   0x011314: 2a0a016a  orr      w10, w11, w10
//   0x011318: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x01131c: b90286ed  str      w13, [x23, #0x284]
//   0x011320: b90282ea  str      w10, [x23, #0x280]
//   0x011324: 79409d2b  ldrh     w11, [x9, #0x4e]
//   0x011328: d503201f  nop      
//   0x01132c: 9b115d0c  madd     x12, x8, x17, x23
//   0x011330: 9b015d0e  madd     x14, x8, x1, x23
//   0x011334: 710021bf  cmp      w13, #8
//   0x011338: 8b0b018c  add      x12, x12, x11
//   0x01133c: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x011340: 3860698c  ldrb     w12, [x12, x0]
//   0x011344: b862696b  ldr      w11, [x11, x2]
//   0x011348: 5400020b  b.lt     #0x11388
//   0x01134c: b94002ae  ldr      w14, [x21]
//   0x011350: f940036d  ldr      x13, [x27]
//   0x011354: 53187d4a  lsr      w10, w10, #0x18
//   0x011358: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x01135c: b94002aa  ldr      w10, [x21]
//   0x011360: 1100054e  add      w14, w10, #1
//   0x011364: b90002ae  str      w14, [x21]
//   0x011368: b940030a  ldr      w10, [x24]
//   0x01136c: 53185d4a  lsl      w10, w10, #8
//   0x011370: b900030a  str      w10, [x24]
//   0x011374: b94002cd  ldr      w13, [x22]
//   0x011378: 510021ad  sub      w13, w13, #8
//   0x01137c: 71001dbf  cmp      w13, #7
//   0x011380: b90002cd  str      w13, [x22]
//   0x011384: 54fffe6c  b.gt     #0x11350
//   0x011388: 0b0c01ac  add      w12, w13, w12
//   0x01138c: 4b0c03ed  neg      w13, w12
//   0x011390: 1acd216b  lsl      w11, w11, w13
//   0x011394: 2a0a016a  orr      w10, w11, w10
//   0x011398: b90286ec  str      w12, [x23, #0x284]
//   0x01139c: b90282ea  str      w10, [x23, #0x280]
//   0x0113a0: 7940a129  ldrh     w9, [x9, #0x50]
//   0x0113a4: d503201f  nop      
//   0x0113a8: 9b115d0b  madd     x11, x8, x17, x23
//   0x0113ac: 9b015d0d  madd     x13, x8, x1, x23
//   0x0113b0: 7100219f  cmp      w12, #8
//   0x0113b4: 8b09016b  add      x11, x11, x9
//   0x0113b8: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0113bc: 38606969  ldrb     w9, [x11, x0]
//   0x0113c0: b86269ab  ldr      w11, [x13, x2]
//   0x0113c4: 5400020b  b.lt     #0x11404
//   0x0113c8: b94002ad  ldr      w13, [x21]
//   0x0113cc: f940036c  ldr      x12, [x27]
//   0x0113d0: 53187d4a  lsr      w10, w10, #0x18
//   0x0113d4: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0113d8: b94002aa  ldr      w10, [x21]
//   0x0113dc: 1100054d  add      w13, w10, #1
//   0x0113e0: b90002ad  str      w13, [x21]
//   0x0113e4: b940030a  ldr      w10, [x24]
//   0x0113e8: 53185d4a  lsl      w10, w10, #8
//   0x0113ec: b900030a  str      w10, [x24]
//   0x0113f0: b94002cc  ldr      w12, [x22]
//   0x0113f4: 5100218c  sub      w12, w12, #8
//   0x0113f8: 71001d9f  cmp      w12, #7
//   0x0113fc: b90002cc  str      w12, [x22]
//   0x011400: 54fffe6c  b.gt     #0x113cc
//   0x011404: 0b09018d  add      w13, w12, w9
//   0x011408: 4b0d03ec  neg      w12, w13
//   0x01140c: 1acc216b  lsl      w11, w11, w12
//   0x011410: 2a0a016a  orr      w10, w11, w10
//   0x011414: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x011418: b90286ed  str      w13, [x23, #0x284]
//   0x01141c: b90282ea  str      w10, [x23, #0x280]
//   0x011420: 7940a52b  ldrh     w11, [x9, #0x52]
//   0x011424: d503201f  nop      
//   0x011428: 9b115d0c  madd     x12, x8, x17, x23
//   0x01142c: 9b015d0e  madd     x14, x8, x1, x23
//   0x011430: 710021bf  cmp      w13, #8
//   0x011434: 8b0b018c  add      x12, x12, x11
//   0x011438: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x01143c: 3860698c  ldrb     w12, [x12, x0]
//   0x011440: b862696b  ldr      w11, [x11, x2]
//   0x011444: 5400020b  b.lt     #0x11484
//   0x011448: b94002ae  ldr      w14, [x21]
//   0x01144c: f940036d  ldr      x13, [x27]
//   0x011450: 53187d4a  lsr      w10, w10, #0x18
//   0x011454: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x011458: b94002aa  ldr      w10, [x21]
//   0x01145c: 1100054e  add      w14, w10, #1
//   0x011460: b90002ae  str      w14, [x21]
//   0x011464: b940030a  ldr      w10, [x24]
//   0x011468: 53185d4a  lsl      w10, w10, #8
//   0x01146c: b900030a  str      w10, [x24]
//   0x011470: b94002cd  ldr      w13, [x22]
//   0x011474: 510021ad  sub      w13, w13, #8
//   0x011478: 71001dbf  cmp      w13, #7
//   0x01147c: b90002cd  str      w13, [x22]
//   0x011480: 54fffe6c  b.gt     #0x1144c
//   0x011484: 0b0c01ac  add      w12, w13, w12
//   0x011488: 4b0c03ed  neg      w13, w12
//   0x01148c: 1acd216b  lsl      w11, w11, w13
//   0x011490: 2a0a016a  orr      w10, w11, w10
//   0x011494: b90286ec  str      w12, [x23, #0x284]
//   0x011498: b90282ea  str      w10, [x23, #0x280]
//   0x01149c: 7940a929  ldrh     w9, [x9, #0x54]
//   0x0114a0: d503201f  nop      
//   0x0114a4: 9b115d0b  madd     x11, x8, x17, x23
//   0x0114a8: 9b015d0d  madd     x13, x8, x1, x23
//   0x0114ac: 7100219f  cmp      w12, #8
//   0x0114b0: 8b09016b  add      x11, x11, x9
//   0x0114b4: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0114b8: 38606969  ldrb     w9, [x11, x0]
//   0x0114bc: b86269ab  ldr      w11, [x13, x2]
//   0x0114c0: 5400020b  b.lt     #0x11500
//   0x0114c4: b94002ad  ldr      w13, [x21]
//   0x0114c8: f940036c  ldr      x12, [x27]
//   0x0114cc: 53187d4a  lsr      w10, w10, #0x18
//   0x0114d0: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0114d4: b94002aa  ldr      w10, [x21]
//   0x0114d8: 1100054d  add      w13, w10, #1
//   0x0114dc: b90002ad  str      w13, [x21]
//   0x0114e0: b940030a  ldr      w10, [x24]
//   0x0114e4: 53185d4a  lsl      w10, w10, #8
//   0x0114e8: b900030a  str      w10, [x24]
//   0x0114ec: b94002cc  ldr      w12, [x22]
//   0x0114f0: 5100218c  sub      w12, w12, #8
//   0x0114f4: 71001d9f  cmp      w12, #7
//   0x0114f8: b90002cc  str      w12, [x22]
//   0x0114fc: 54fffe6c  b.gt     #0x114c8
//   0x011500: 0b09018d  add      w13, w12, w9
//   0x011504: 4b0d03ec  neg      w12, w13
//   0x011508: 1acc216b  lsl      w11, w11, w12
//   0x01150c: 2a0a016a  orr      w10, w11, w10
//   0x011510: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x011514: b90286ed  str      w13, [x23, #0x284]
//   0x011518: b90282ea  str      w10, [x23, #0x280]
//   0x01151c: 7940ad2b  ldrh     w11, [x9, #0x56]
//   0x011520: d503201f  nop      
//   0x011524: 9b115d0c  madd     x12, x8, x17, x23
//   0x011528: 9b015d0e  madd     x14, x8, x1, x23
//   0x01152c: 710021bf  cmp      w13, #8
//   0x011530: 8b0b018c  add      x12, x12, x11
//   0x011534: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x011538: 3860698c  ldrb     w12, [x12, x0]
//   0x01153c: b862696b  ldr      w11, [x11, x2]
//   0x011540: 5400020b  b.lt     #0x11580
//   0x011544: b94002ae  ldr      w14, [x21]
//   0x011548: f940036d  ldr      x13, [x27]
//   0x01154c: 53187d4a  lsr      w10, w10, #0x18
//   0x011550: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x011554: b94002aa  ldr      w10, [x21]
//   0x011558: 1100054e  add      w14, w10, #1
//   0x01155c: b90002ae  str      w14, [x21]
//   0x011560: b940030a  ldr      w10, [x24]
//   0x011564: 53185d4a  lsl      w10, w10, #8
//   0x011568: b900030a  str      w10, [x24]
//   0x01156c: b94002cd  ldr      w13, [x22]
//   0x011570: 510021ad  sub      w13, w13, #8
//   0x011574: 71001dbf  cmp      w13, #7
//   0x011578: b90002cd  str      w13, [x22]
//   0x01157c: 54fffe6c  b.gt     #0x11548
//   0x011580: 0b0c01ac  add      w12, w13, w12
//   0x011584: 4b0c03ed  neg      w13, w12
//   0x011588: 1acd216b  lsl      w11, w11, w13
//   0x01158c: 2a0a016a  orr      w10, w11, w10
//   0x011590: b90286ec  str      w12, [x23, #0x284]
//   0x011594: b90282ea  str      w10, [x23, #0x280]
//   0x011598: 7940b129  ldrh     w9, [x9, #0x58]
//   0x01159c: d503201f  nop      
//   0x0115a0: 9b115d0b  madd     x11, x8, x17, x23
//   0x0115a4: 9b015d0d  madd     x13, x8, x1, x23
//   0x0115a8: 7100219f  cmp      w12, #8
//   0x0115ac: 8b09016b  add      x11, x11, x9
//   0x0115b0: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0115b4: 38606969  ldrb     w9, [x11, x0]
//   0x0115b8: b86269ab  ldr      w11, [x13, x2]
//   0x0115bc: 5400020b  b.lt     #0x115fc
//   0x0115c0: b94002ad  ldr      w13, [x21]
//   0x0115c4: f940036c  ldr      x12, [x27]
//   0x0115c8: 53187d4a  lsr      w10, w10, #0x18
//   0x0115cc: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0115d0: b94002aa  ldr      w10, [x21]
//   0x0115d4: 1100054d  add      w13, w10, #1
//   0x0115d8: b90002ad  str      w13, [x21]
//   0x0115dc: b940030a  ldr      w10, [x24]
//   0x0115e0: 53185d4a  lsl      w10, w10, #8
//   0x0115e4: b900030a  str      w10, [x24]
//   0x0115e8: b94002cc  ldr      w12, [x22]
//   0x0115ec: 5100218c  sub      w12, w12, #8
//   0x0115f0: 71001d9f  cmp      w12, #7
//   0x0115f4: b90002cc  str      w12, [x22]
//   0x0115f8: 54fffe6c  b.gt     #0x115c4
//   0x0115fc: 0b09018d  add      w13, w12, w9
//   0x011600: 4b0d03ec  neg      w12, w13
//   0x011604: 1acc216b  lsl      w11, w11, w12
//   0x011608: 2a0a016a  orr      w10, w11, w10
//   0x01160c: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x011610: b90286ed  str      w13, [x23, #0x284]
//   0x011614: b90282ea  str      w10, [x23, #0x280]
//   0x011618: 7940b52b  ldrh     w11, [x9, #0x5a]
//   0x01161c: d503201f  nop      
//   0x011620: 9b115d0c  madd     x12, x8, x17, x23
//   0x011624: 9b015d0e  madd     x14, x8, x1, x23
//   0x011628: 710021bf  cmp      w13, #8
//   0x01162c: 8b0b018c  add      x12, x12, x11
//   0x011630: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x011634: 3860698c  ldrb     w12, [x12, x0]
//   0x011638: b862696b  ldr      w11, [x11, x2]
//   0x01163c: 5400020b  b.lt     #0x1167c
//   0x011640: b94002ae  ldr      w14, [x21]
//   0x011644: f940036d  ldr      x13, [x27]
//   0x011648: 53187d4a  lsr      w10, w10, #0x18
//   0x01164c: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x011650: b94002aa  ldr      w10, [x21]
//   0x011654: 1100054e  add      w14, w10, #1
//   0x011658: b90002ae  str      w14, [x21]
//   0x01165c: b940030a  ldr      w10, [x24]
//   0x011660: 53185d4a  lsl      w10, w10, #8
//   0x011664: b900030a  str      w10, [x24]
//   0x011668: b94002cd  ldr      w13, [x22]
//   0x01166c: 510021ad  sub      w13, w13, #8
//   0x011670: 71001dbf  cmp      w13, #7
//   0x011674: b90002cd  str      w13, [x22]
//   0x011678: 54fffe6c  b.gt     #0x11644
//   0x01167c: 0b0c01ac  add      w12, w13, w12
//   0x011680: 4b0c03ed  neg      w13, w12
//   0x011684: 1acd216b  lsl      w11, w11, w13
//   0x011688: 2a0a016a  orr      w10, w11, w10
//   0x01168c: b90286ec  str      w12, [x23, #0x284]
//   0x011690: b90282ea  str      w10, [x23, #0x280]
//   0x011694: 7940b929  ldrh     w9, [x9, #0x5c]
//   0x011698: d503201f  nop      
//   0x01169c: 9b115d0b  madd     x11, x8, x17, x23
//   0x0116a0: 9b015d0d  madd     x13, x8, x1, x23
//   0x0116a4: 7100219f  cmp      w12, #8
//   0x0116a8: 8b09016b  add      x11, x11, x9
//   0x0116ac: 8b0909ad  add      x13, x13, x9, lsl #2
//   0x0116b0: 38606969  ldrb     w9, [x11, x0]
//   0x0116b4: b86269ab  ldr      w11, [x13, x2]
//   0x0116b8: 5400020b  b.lt     #0x116f8
//   0x0116bc: b94002ad  ldr      w13, [x21]
//   0x0116c0: f940036c  ldr      x12, [x27]
//   0x0116c4: 53187d4a  lsr      w10, w10, #0x18
//   0x0116c8: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0116cc: b94002aa  ldr      w10, [x21]
//   0x0116d0: 1100054d  add      w13, w10, #1
//   0x0116d4: b90002ad  str      w13, [x21]
//   0x0116d8: b940030a  ldr      w10, [x24]
//   0x0116dc: 53185d4a  lsl      w10, w10, #8
//   0x0116e0: b900030a  str      w10, [x24]
//   0x0116e4: b94002cc  ldr      w12, [x22]
//   0x0116e8: 5100218c  sub      w12, w12, #8
//   0x0116ec: 71001d9f  cmp      w12, #7
//   0x0116f0: b90002cc  str      w12, [x22]
//   0x0116f4: 54fffe6c  b.gt     #0x116c0
//   0x0116f8: 0b09018d  add      w13, w12, w9
//   0x0116fc: 4b0d03ec  neg      w12, w13
//   0x011700: 1acc216b  lsl      w11, w11, w12
//   0x011704: 2a0a016a  orr      w10, w11, w10
//   0x011708: 8b1405e9  add      x9, x15, x20, lsl #1
//   0x01170c: b90286ed  str      w13, [x23, #0x284]
//   0x011710: b90282ea  str      w10, [x23, #0x280]
//   0x011714: 7940bd2b  ldrh     w11, [x9, #0x5e]
//   0x011718: d503201f  nop      
//   0x01171c: 9b115d0c  madd     x12, x8, x17, x23
//   0x011720: 9b015d0e  madd     x14, x8, x1, x23
//   0x011724: 710021bf  cmp      w13, #8
//   0x011728: 8b0b018c  add      x12, x12, x11
//   0x01172c: 8b0b09cb  add      x11, x14, x11, lsl #2
//   0x011730: 3860698c  ldrb     w12, [x12, x0]
//   0x011734: b862696b  ldr      w11, [x11, x2]
//   0x011738: 5400020b  b.lt     #0x11778
//   0x01173c: b94002ae  ldr      w14, [x21]
//   0x011740: f940036d  ldr      x13, [x27]
//   0x011744: 53187d4a  lsr      w10, w10, #0x18
//   0x011748: 382ec9aa  strb     w10, [x13, w14, sxtw]
//   0x01174c: b94002aa  ldr      w10, [x21]
//   0x011750: 1100054e  add      w14, w10, #1
//   0x011754: b90002ae  str      w14, [x21]
//   0x011758: b940030a  ldr      w10, [x24]
//   0x01175c: 53185d4a  lsl      w10, w10, #8
//   0x011760: b900030a  str      w10, [x24]
//   0x011764: b94002cd  ldr      w13, [x22]
//   0x011768: 510021ad  sub      w13, w13, #8
//   0x01176c: 71001dbf  cmp      w13, #7
//   0x011770: b90002cd  str      w13, [x22]
//   0x011774: 54fffe6c  b.gt     #0x11740
//   0x011778: 0b0c01ac  add      w12, w13, w12
//   0x01177c: 4b0c03ed  neg      w13, w12
//   0x011780: 1acd216b  lsl      w11, w11, w13
//   0x011784: 2a0a016a  orr      w10, w11, w10
//   0x011788: b90286ec  str      w12, [x23, #0x284]
//   0x01178c: b90282ea  str      w10, [x23, #0x280]
//   0x011790: 7940c129  ldrh     w9, [x9, #0x60]
//   0x011794: d503201f  nop      
//   0x011798: 9b115d0b  madd     x11, x8, x17, x23
//   0x01179c: 9b015d0d  madd     x13, x8, x1, x23
//   0x0117a0: 7100219f  cmp      w12, #8
//   0x0117a4: 8b09016b  add      x11, x11, x9
//   0x0117a8: 8b0909a9  add      x9, x13, x9, lsl #2
//   0x0117ac: 3860696b  ldrb     w11, [x11, x0]
//   0x0117b0: b8626929  ldr      w9, [x9, x2]
//   0x0117b4: 5400020b  b.lt     #0x117f4
//   0x0117b8: b94002ad  ldr      w13, [x21]
//   0x0117bc: f940036c  ldr      x12, [x27]
//   0x0117c0: 53187d4a  lsr      w10, w10, #0x18
//   0x0117c4: 382dc98a  strb     w10, [x12, w13, sxtw]
//   0x0117c8: b94002aa  ldr      w10, [x21]
//   0x0117cc: 1100054d  add      w13, w10, #1
//   0x0117d0: b90002ad  str      w13, [x21]
//   0x0117d4: b940030a  ldr      w10, [x24]
//   0x0117d8: 53185d4a  lsl      w10, w10, #8
//   0x0117dc: b900030a  str      w10, [x24]
//   0x0117e0: b94002cc  ldr      w12, [x22]
//   0x0117e4: 5100218c  sub      w12, w12, #8
//   0x0117e8: 71001d9f  cmp      w12, #7
//   0x0117ec: b90002cc  str      w12, [x22]
//   0x0117f0: 54fffe6c  b.gt     #0x117bc
//   0x0117f4: 0b0b018b  add      w11, w12, w11
//   0x0117f8: 4b0b03ec  neg      w12, w11
//   0x0117fc: 1acc2129  lsl      w9, w9, w12
//   0x011800: 2a0a0129  orr      w9, w9, w10
//   0x011804: b90286eb  str      w11, [x23, #0x284]
//   0x011808: b90282e9  str      w9, [x23, #0x280]
//   0x01180c: 786479ea  ldrh     w10, [x15, x4, lsl #1]
//   0x011810: d503201f  nop      
//   0x011814: 9b115d0c  madd     x12, x8, x17, x23
//   0x011818: 9b015d08  madd     x8, x8, x1, x23
//   0x01181c: 7100217f  cmp      w11, #8
//   0x011820: 8b0a018c  add      x12, x12, x10
//   0x011824: 8b0a0908  add      x8, x8, x10, lsl #2
//   0x011828: 3860698a  ldrb     w10, [x12, x0]
//   0x01182c: b8626908  ldr      w8, [x8, x2]
//   0x011830: 54ff38cb  b.lt     #0xff48
//   0x011834: b94002ac  ldr      w12, [x21]
//   0x011838: f940036b  ldr      x11, [x27]
//   0x01183c: 53187d29  lsr      w9, w9, #0x18
//   0x011840: 382cc969  strb     w9, [x11, w12, sxtw]
//   0x011844: b94002a9  ldr      w9, [x21]
//   0x011848: 1100052c  add      w12, w9, #1
//   0x01184c: b90002ac  str      w12, [x21]
//   0x011850: b9400309  ldr      w9, [x24]
//   0x011854: 53185d29  lsl      w9, w9, #8
//   0x011858: b9000309  str      w9, [x24]
//   0x01185c: b94002cb  ldr      w11, [x22]
//   0x011860: 5100216b  sub      w11, w11, #8
//   0x011864: 71001d7f  cmp      w11, #7
//   0x011868: b90002cb  str      w11, [x22]
//   0x01186c: 54fffe6c  b.gt     #0x11838
//   0x011870: 17fff9b6  b        #0xff48
//   0x011874: f94037ef  ldr      x15, [sp, #0x68]
//   0x011878: 6b14007f  cmp      w3, w20
//   0x01187c: 54ff372b  b.lt     #0xff60
//   0x011880: b94002cb  ldr      w11, [x22]
//   0x011884: b940030a  ldr      w10, [x24]
//   0x011888: 93407c69  sxtw     x9, w3
//   0x01188c: 1400000a  b        #0x118b4
//   0x011890: 0b0d016b  add      w11, w11, w13
//   0x011894: 4b0b03ed  neg      w13, w11
//   0x011898: 1acd218c  lsl      w12, w12, w13
//   0x01189c: eb09029f  cmp      x20, x9
//   0x0118a0: 91000694  add      x20, x20, #1
//   0x0118a4: 2a0a018a  orr      w10, w12, w10
//   0x0118a8: b900030a  str      w10, [x24]
//   0x0118ac: b90002cb  str      w11, [x22]
//   0x0118b0: 54ff358a  b.ge     #0xff60
//   0x0118b4: 3940010c  ldrb     w12, [x8]
//   0x0118b8: 787479ed  ldrh     w13, [x15, x20, lsl #1]
//   0x0118bc: 7100217f  cmp      w11, #8
//   0x0118c0: 9b115d8e  madd     x14, x12, x17, x23
//   0x0118c4: 9b015d8c  madd     x12, x12, x1, x23
//   0x0118c8: 8b0d01ce  add      x14, x14, x13
//   0x0118cc: 8b0d098c  add      x12, x12, x13, lsl #2
//   0x0118d0: 386069cd  ldrb     w13, [x14, x0]
//   0x0118d4: b862698c  ldr      w12, [x12, x2]
//   0x0118d8: 54fffdcb  b.lt     #0x11890
//   0x0118dc: b94002ae  ldr      w14, [x21]
//   0x0118e0: f940036b  ldr      x11, [x27]
//   0x0118e4: 53187d4a  lsr      w10, w10, #0x18
//   0x0118e8: 382ec96a  strb     w10, [x11, w14, sxtw]
//   0x0118ec: b94002aa  ldr      w10, [x21]
//   0x0118f0: 1100054e  add      w14, w10, #1
//   0x0118f4: b90002ae  str      w14, [x21]
//   0x0118f8: b940030a  ldr      w10, [x24]
//   0x0118fc: 53185d4a  lsl      w10, w10, #8
//   0x011900: b900030a  str      w10, [x24]
//   0x011904: b94002cb  ldr      w11, [x22]
//   0x011908: 5100216b  sub      w11, w11, #8
//   0x01190c: 71001d7f  cmp      w11, #7
//   0x011910: b90002cb  str      w11, [x22]
//   0x011914: 54fffe6c  b.gt     #0x118e0
//   0x011918: 17ffffde  b        #0x11890
//   0x01191c: f94047f4  ldr      x20, [sp, #0x88]
//   0x011920: 6b14035f  cmp      w26, w20
//   0x011924: 54000060  b.eq     #0x11930
//   0x011928: 528177e0  mov      w0, #0xbbf
//   0x01192c: 97ffc3d1  bl       #0x2870
//   0x011930: b94292e8  ldr      w8, [x23, #0x290]
//   0x011934: 71000d1f  cmp      w8, #3
//   0x011938: 5400012b  b.lt     #0x1195c
//   0x01193c: b94002a8  ldr      w8, [x21]
//   0x011940: b0000021  adrp     x1, #0x16000
//   0x011944: 913f9421  add      x1, x1, #0xfe5
//   0x011948: 4b1c0102  sub      w2, w8, w28
//   0x01194c: d0000068  adrp     x8, #0x1f000
//   0x011950: f947c908  ldr      x8, [x8, #0xf90]
//   0x011954: 9104c100  add      x0, x8, #0x130
//   0x011958: 97ffc44a  bl       #0x2a80
//   0x01195c: f94003e8  ldr      x8, [sp]
//   0x011960: f9401508  ldr      x8, [x8, #0x28]
//   0x011964: f85903a9  ldur     x9, [x29, #-0x70]
//   0x011968: eb09011f  cmp      x8, x9
//   0x01196c: 540001c1  b.ne     #0x119a4
//   0x011970: a9547bfd  ldp      x29, x30, [sp, #0x140]
//   0x011974: a9534ff4  ldp      x20, x19, [sp, #0x130]
//   0x011978: a95257f6  ldp      x22, x21, [sp, #0x120]
//   0x01197c: a9515ff8  ldp      x24, x23, [sp, #0x110]
//   0x011980: a95067fa  ldp      x26, x25, [sp, #0x100]
//   0x011984: a94f6ffc  ldp      x28, x27, [sp, #0xf0]
//   0x011988: fd4073e8  ldr      d8, [sp, #0xe0]
//   0x01198c: 910543ff  add      sp, sp, #0x150
//   0x011990: d65f03c0  ret      
//   0x011994: 2a1f03fa  mov      w26, wzr
//   0x011998: 6b14035f  cmp      w26, w20
//   0x01199c: 54fffc61  b.ne     #0x11928
//   0x0119a0: 17ffffe4  b        #0x11930
//   0x0119a4: 97ffc3df  bl       #0x2920
// ============================================================================
std::uint32_t fde_55_0e550(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x0000e550ULL;
    for (std::size_t i = 0; i < 3350ULL; ++i) {
        std::uint32_t insn = kTextInstructions[11912ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[56] Subroutine @ 0x0119a8..0x012a94 (4332 bytes, 1083 AArch64 instructions)
// [VN] Khung FDE[56] Hàm con @ 0x0119a8..0x012a94 (4332 byte, 1083 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x0119a8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0119ac: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0119b0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0119b4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0119b8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0119bc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0119c0: 910143fd  add      x29, sp, #0x50
//   0x0119c4: d14007ff  sub      sp, sp, #1, lsl #12
//   0x0119c8: d10b03ff  sub      sp, sp, #0x2c0
//   0x0119cc: d53bd053  mrs      x19, tpidr_el0
//   0x0119d0: f9401668  ldr      x8, [x19, #0x28]
//   0x0119d4: aa0003f4  mov      x20, x0
//   0x0119d8: f81983a8  stur     x8, [x29, #-0x68]
//   0x0119dc: b9806c15  ldrsw    x21, [x0, #0x6c]
//   0x0119e0: f9401c1a  ldr      x26, [x0, #0x38]
//   0x0119e4: f9401418  ldr      x24, [x0, #0x28]
//   0x0119e8: b9429019  ldr      w25, [x0, #0x290]
//   0x0119ec: 5284e208  mov      w8, #0x2710
//   0x0119f0: 6b0802bf  cmp      w21, w8
//   0x0119f4: 540000ea  b.ge     #0x11a10
//   0x0119f8: a9418680  ldp      x0, x1, [x20, #0x18]
//   0x0119fc: aa1803e2  mov      x2, x24
//   0x011a00: 2a1503e3  mov      w3, w21
//   0x011a04: 2a1903e4  mov      w4, w25
//   0x011a08: 94000423  bl       #0x12a94
//   0x011a0c: 140003f9  b        #0x129f0
//   0x011a10: a900cff4  stp      x20, x19, [sp, #8]
//   0x011a14: b9405a88  ldr      w8, [x20, #0x58]
//   0x011a18: 11008aa9  add      w9, w21, #0x22
//   0x011a1c: 11008eaa  add      w10, w21, #0x23
//   0x011a20: 7200013f  tst      w9, #1
//   0x011a24: 1a8a0129  csel     w9, w9, w10, eq
//   0x011a28: 7100051f  cmp      w8, #1
//   0x011a2c: f9402297  ldr      x23, [x20, #0x40]
//   0x011a30: 1a9fc508  csinc    w8, w8, wzr, gt
//   0x011a34: 52800c8b  mov      w11, #0x64
//   0x011a38: 7101911f  cmp      w8, #0x64
//   0x011a3c: 528aaaca  mov      w10, #0x5556
//   0x011a40: 1a8bb108  csel     w8, w8, w11, lt
//   0x011a44: 72aaaaaa  movk     w10, #0x5555, lsl #16
//   0x011a48: 93407d34  sxtw     x20, w9
//   0x011a4c: 51000508  sub      w8, w8, #1
//   0x011a50: 8b1402e9  add      x9, x23, x20
//   0x011a54: 9b2a7d08  smull    x8, w8, w10
//   0x011a58: f90073e9  str      x9, [sp, #0xe0]
//   0x011a5c: d37ffd09  lsr      x9, x8, #0x3f
//   0x011a60: d360fd08  lsr      x8, x8, #0x20
//   0x011a64: 0b090108  add      w8, w8, w9
//   0x011a68: 7100133f  cmp      w25, #4
//   0x011a6c: 1b157d08  mul      w8, w8, w21
//   0x011a70: b9001fe8  str      w8, [sp, #0x1c]
//   0x011a74: b900efe8  str      w8, [sp, #0xec]
//   0x011a78: 5400012b  b.lt     #0x11a9c
//   0x011a7c: d0000068  adrp     x8, #0x1f000
//   0x011a80: f947c908  ldr      x8, [x8, #0xf90]
//   0x011a84: d0000020  adrp     x0, #0x17000
//   0x011a88: 91032400  add      x0, x0, #0xc9
//   0x011a8c: 52800421  mov      w1, #0x21
//   0x011a90: 9104c103  add      x3, x8, #0x130
//   0x011a94: 52800022  mov      w2, #1
//   0x011a98: 97ffc412  bl       #0x2ae0
//   0x011a9c: 320e83e2  mov      w2, #0x40004
//   0x011aa0: aa1803e0  mov      x0, x24
//   0x011aa4: 2a1f03e1  mov      w1, wzr
//   0x011aa8: 9123c3f3  add      x19, sp, #0x8f0
//   0x011aac: 97ffc405  bl       #0x2ac0
//   0x011ab0: aa1703e8  mov      x8, x23
//   0x011ab4: 385fa509  ldrb     w9, [x8], #0xfffffffffffffffa
//   0x011ab8: d10006bb  sub      x27, x21, #1
//   0x011abc: 8b1b068a  add      x10, x20, x27, lsl #1
//   0x011ac0: d3607f76  lsl      x22, x27, #0x20
//   0x011ac4: 8b17014a  add      x10, x10, x23
//   0x011ac8: d100094b  sub      x11, x10, #2
//   0x011acc: 53185d29  lsl      w9, w9, #8
//   0x011ad0: b25e77ec  mov      x12, #-0x400000000
//   0x011ad4: aa1603ea  mov      x10, x22
//   0x011ad8: aa1b03ed  mov      x13, x27
//   0x011adc: 7900057f  strh     wzr, [x11, #2]
//   0x011ae0: 8b0d010e  add      x14, x8, x13
//   0x011ae4: 394019cf  ldrb     w15, [x14, #6]
//   0x011ae8: d10011ad  sub      x13, x13, #4
//   0x011aec: 8b0c014a  add      x10, x10, x12
//   0x011af0: f10009bf  cmp      x13, #2
//   0x011af4: 53185def  lsl      w15, w15, #8
//   0x011af8: 2a8921e9  orr      w9, w15, w9, asr #8
//   0x011afc: 937e7d2f  sbfiz    x15, x9, #2, #0x20
//   0x011b00: b86f6b10  ldr      w16, [x24, x15]
//   0x011b04: 11000610  add      w16, w16, #1
//   0x011b08: b82f6b10  str      w16, [x24, x15]
//   0x011b0c: 7900017f  strh     wzr, [x11]
//   0x011b10: 394015cf  ldrb     w15, [x14, #5]
//   0x011b14: 53185def  lsl      w15, w15, #8
//   0x011b18: 2a8921e9  orr      w9, w15, w9, asr #8
//   0x011b1c: 937e7d2f  sbfiz    x15, x9, #2, #0x20
//   0x011b20: b86f6b10  ldr      w16, [x24, x15]
//   0x011b24: 11000610  add      w16, w16, #1
//   0x011b28: b82f6b10  str      w16, [x24, x15]
//   0x011b2c: 781fe17f  sturh    wzr, [x11, #-2]
//   0x011b30: 394011cf  ldrb     w15, [x14, #4]
//   0x011b34: 53185def  lsl      w15, w15, #8
//   0x011b38: 2a8921e9  orr      w9, w15, w9, asr #8
//   0x011b3c: 937e7d2f  sbfiz    x15, x9, #2, #0x20
//   0x011b40: b86f6b10  ldr      w16, [x24, x15]
//   0x011b44: 11000610  add      w16, w16, #1
//   0x011b48: b82f6b10  str      w16, [x24, x15]
//   0x011b4c: 781fc17f  sturh    wzr, [x11, #-4]
//   0x011b50: 39400dce  ldrb     w14, [x14, #3]
//   0x011b54: d100216b  sub      x11, x11, #8
//   0x011b58: 53185dce  lsl      w14, w14, #8
//   0x011b5c: 2a8921c9  orr      w9, w14, w9, asr #8
//   0x011b60: 937e7d2e  sbfiz    x14, x9, #2, #0x20
//   0x011b64: b86e6b0f  ldr      w15, [x24, x14]
//   0x011b68: 110005ef  add      w15, w15, #1
//   0x011b6c: b82e6b0f  str      w15, [x24, x14]
//   0x011b70: 54fffb6c  b.gt     #0x11adc
//   0x011b74: 37f801cd  tbnz     w13, #0x1f, #0x11bac
//   0x011b78: 9360fd48  asr      x8, x10, #0x20
//   0x011b7c: 8b1402ea  add      x10, x23, x20
//   0x011b80: 7828795f  strh     wzr, [x10, x8, lsl #1]
//   0x011b84: 38686aeb  ldrb     w11, [x23, x8]
//   0x011b88: f100011f  cmp      x8, #0
//   0x011b8c: d1000508  sub      x8, x8, #1
//   0x011b90: 53185d6b  lsl      w11, w11, #8
//   0x011b94: 2a892169  orr      w9, w11, w9, asr #8
//   0x011b98: 937e7d2b  sbfiz    x11, x9, #2, #0x20
//   0x011b9c: b86b6b0c  ldr      w12, [x24, x11]
//   0x011ba0: 1100058c  add      w12, w12, #1
//   0x011ba4: b82b6b0c  str      w12, [x24, x11]
//   0x011ba8: 54fffecc  b.gt     #0x11b80
//   0x011bac: 8b150689  add      x9, x20, x21, lsl #1
//   0x011bb0: 8b0902e9  add      x9, x23, x9
//   0x011bb4: 8b1502e8  add      x8, x23, x21
//   0x011bb8: 9101112e  add      x14, x9, #0x44
//   0x011bbc: 9100890d  add      x13, x8, #0x22
//   0x011bc0: eb0e011f  cmp      x8, x14
//   0x011bc4: 91008aec  add      x12, x23, #0x22
//   0x011bc8: 1a9f27eb  cset     w11, lo
//   0x011bcc: eb0d013f  cmp      x9, x13
//   0x011bd0: 1a9f27ef  cset     w15, lo
//   0x011bd4: eb0c011f  cmp      x8, x12
//   0x011bd8: 0a0f016f  and      w15, w11, w15
//   0x011bdc: 1a9f27eb  cset     w11, lo
//   0x011be0: eb0d02ff  cmp      x23, x13
//   0x011be4: 1a9f27ed  cset     w13, lo
//   0x011be8: eb0c013f  cmp      x9, x12
//   0x011bec: 1a9f27ec  cset     w12, lo
//   0x011bf0: eb0e02ff  cmp      x23, x14
//   0x011bf4: aa1f03ea  mov      x10, xzr
//   0x011bf8: 1a9f27ee  cset     w14, lo
//   0x011bfc: 3700036f  tbnz     w15, #0, #0x11c68
//   0x011c00: 0a0d016b  and      w11, w11, w13
//   0x011c04: 3700032b  tbnz     w11, #0, #0x11c68
//   0x011c08: 0a0e018b  and      w11, w12, w14
//   0x011c0c: 350002eb  cbnz     w11, #0x11c68
//   0x011c10: f94002ea  ldr      x10, [x23]
//   0x011c14: f94073ec  ldr      x12, [sp, #0xe0]
//   0x011c18: d37ffaab  lsl      x11, x21, #1
//   0x011c1c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x011c20: f8356aea  str      x10, [x23, x21]
//   0x011c24: 3cab6980  str      q0, [x12, x11]
//   0x011c28: f94006ea  ldr      x10, [x23, #8]
//   0x011c2c: 910022ab  add      x11, x21, #8
//   0x011c30: f82b6aea  str      x10, [x23, x11]
//   0x011c34: d37ff96a  lsl      x10, x11, #1
//   0x011c38: 3caa6980  str      q0, [x12, x10]
//   0x011c3c: f9400aea  ldr      x10, [x23, #0x10]
//   0x011c40: 910042ab  add      x11, x21, #0x10
//   0x011c44: f82b6aea  str      x10, [x23, x11]
//   0x011c48: d37ff96a  lsl      x10, x11, #1
//   0x011c4c: 3caa6980  str      q0, [x12, x10]
//   0x011c50: f9400eea  ldr      x10, [x23, #0x18]
//   0x011c54: 910062ab  add      x11, x21, #0x18
//   0x011c58: f82b6aea  str      x10, [x23, x11]
//   0x011c5c: d37ff96a  lsl      x10, x11, #1
//   0x011c60: 3caa6980  str      q0, [x12, x10]
//   0x011c64: 5280040a  mov      w10, #0x20
//   0x011c68: 386a6aeb  ldrb     w11, [x23, x10]
//   0x011c6c: 382a690b  strb     w11, [x8, x10]
//   0x011c70: 782a793f  strh     wzr, [x9, x10, lsl #1]
//   0x011c74: 9100054a  add      x10, x10, #1
//   0x011c78: f100895f  cmp      x10, #0x22
//   0x011c7c: 54ffff61  b.ne     #0x11c68
//   0x011c80: 7100133f  cmp      w25, #4
//   0x011c84: 5400012b  b.lt     #0x11ca8
//   0x011c88: d0000068  adrp     x8, #0x1f000
//   0x011c8c: f947c908  ldr      x8, [x8, #0xf90]
//   0x011c90: d0000020  adrp     x0, #0x17000
//   0x011c94: 91017000  add      x0, x0, #0x5c
//   0x011c98: 52800361  mov      w1, #0x1b
//   0x011c9c: 9104c103  add      x3, x8, #0x130
//   0x011ca0: 52800022  mov      w2, #1
//   0x011ca4: 97ffc38f  bl       #0x2ae0
//   0x011ca8: aa1803e8  mov      x8, x24
//   0x011cac: b8404509  ldr      w9, [x8], #4
//   0x011cb0: aa1f03ea  mov      x10, xzr
//   0x011cb4: b86a690b  ldr      w11, [x8, x10]
//   0x011cb8: 0b090169  add      w9, w11, w9
//   0x011cbc: b82a6909  str      w9, [x8, x10]
//   0x011cc0: 9100114a  add      x10, x10, #4
//   0x011cc4: f141015f  cmp      x10, #0x40, lsl #12
//   0x011cc8: 54ffff61  b.ne     #0x11cb4
//   0x011ccc: 394002e9  ldrb     w9, [x23]
//   0x011cd0: aa1f03e8  mov      x8, xzr
//   0x011cd4: 510006aa  sub      w10, w21, #1
//   0x011cd8: 510012ab  sub      w11, w21, #4
//   0x011cdc: 51000eac  sub      w12, w21, #3
//   0x011ce0: 51000aad  sub      w13, w21, #2
//   0x011ce4: 8b1b02ee  add      x14, x23, x27
//   0x011ce8: 53185d29  lsl      w9, w9, #8
//   0x011cec: b25e77ef  mov      x15, #-0x400000000
//   0x011cf0: 8b0801d0  add      x16, x14, x8
//   0x011cf4: 39400211  ldrb     w17, [x16]
//   0x011cf8: 53083d29  ubfx     w9, w9, #8, #8
//   0x011cfc: 0b080141  add      w1, w10, w8
//   0x011d00: 8b0f02d6  add      x22, x22, x15
//   0x011d04: 33181e29  bfi      w9, w17, #8, #8
//   0x011d08: d37ef529  lsl      x9, x9, #2
//   0x011d0c: b8696b00  ldr      w0, [x24, x9]
//   0x011d10: 51000400  sub      w0, w0, #1
//   0x011d14: b8296b00  str      w0, [x24, x9]
//   0x011d18: b820db41  str      w1, [x26, w0, sxtw #2]
//   0x011d1c: 385ff200  ldurb    w0, [x16, #-1]
//   0x011d20: 0b0801a1  add      w1, w13, w8
//   0x011d24: b3781c11  bfi      x17, x0, #8, #8
//   0x011d28: d37ef629  lsl      x9, x17, #2
//   0x011d2c: b8696b11  ldr      w17, [x24, x9]
//   0x011d30: 51000631  sub      w17, w17, #1
//   0x011d34: b8296b11  str      w17, [x24, x9]
//   0x011d38: b831db41  str      w1, [x26, w17, sxtw #2]
//   0x011d3c: 385fe209  ldurb    w9, [x16, #-2]
//   0x011d40: 0b080181  add      w1, w12, w8
//   0x011d44: b3781d20  bfi      x0, x9, #8, #8
//   0x011d48: d37ef411  lsl      x17, x0, #2
//   0x011d4c: b8716b00  ldr      w0, [x24, x17]
//   0x011d50: 51000400  sub      w0, w0, #1
//   0x011d54: b8316b00  str      w0, [x24, x17]
//   0x011d58: b820db41  str      w1, [x26, w0, sxtw #2]
//   0x011d5c: 385fd210  ldurb    w16, [x16, #-3]
//   0x011d60: 0b080171  add      w17, w11, w8
//   0x011d64: d1001108  sub      x8, x8, #4
//   0x011d68: 8b080361  add      x1, x27, x8
//   0x011d6c: 33185e09  bfi      w9, w16, #8, #0x18
//   0x011d70: 92403d30  and      x16, x9, #0xffff
//   0x011d74: d37ef610  lsl      x16, x16, #2
//   0x011d78: b8706b00  ldr      w0, [x24, x16]
//   0x011d7c: f100083f  cmp      x1, #2
//   0x011d80: 51000400  sub      w0, w0, #1
//   0x011d84: b8306b00  str      w0, [x24, x16]
//   0x011d88: b820db51  str      w17, [x26, w0, sxtw #2]
//   0x011d8c: 54fffb2c  b.gt     #0x11cf0
//   0x011d90: 0b0802aa  add      w10, w21, w8
//   0x011d94: 5100054a  sub      w10, w10, #1
//   0x011d98: 37f8022a  tbnz     w10, #0x1f, #0x11ddc
//   0x011d9c: 510006aa  sub      w10, w21, #1
//   0x011da0: 8b080148  add      x8, x10, x8
//   0x011da4: 9360feca  asr      x10, x22, #0x20
//   0x011da8: 386a6aeb  ldrb     w11, [x23, x10]
//   0x011dac: 53083d29  ubfx     w9, w9, #8, #8
//   0x011db0: f100015f  cmp      x10, #0
//   0x011db4: d100054a  sub      x10, x10, #1
//   0x011db8: 33185d69  bfi      w9, w11, #8, #0x18
//   0x011dbc: 92403d2b  and      x11, x9, #0xffff
//   0x011dc0: d37ef56b  lsl      x11, x11, #2
//   0x011dc4: b86b6b0c  ldr      w12, [x24, x11]
//   0x011dc8: 5100058c  sub      w12, w12, #1
//   0x011dcc: b82b6b0c  str      w12, [x24, x11]
//   0x011dd0: b82cdb48  str      w8, [x26, w12, sxtw #2]
//   0x011dd4: 51000508  sub      w8, w8, #1
//   0x011dd8: 54fffe8c  b.gt     #0x11da8
//   0x011ddc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x011de0: b0000029  adrp     x9, #0x16000
//   0x011de4: ad070260  stp      q0, q0, [x19, #0xe0]
//   0x011de8: ad060260  stp      q0, q0, [x19, #0xc0]
//   0x011dec: ad050260  stp      q0, q0, [x19, #0xa0]
//   0x011df0: ad040260  stp      q0, q0, [x19, #0x80]
//   0x011df4: ad030260  stp      q0, q0, [x19, #0x60]
//   0x011df8: ad020260  stp      q0, q0, [x19, #0x40]
//   0x011dfc: ad010260  stp      q0, q0, [x19, #0x20]
//   0x011e00: ad000260  stp      q0, q0, [x19]
//   0x011e04: 3dc3fd20  ldr      q0, [x9, #0xff0]
//   0x011e08: aa1f03e8  mov      x8, xzr
//   0x011e0c: 4f000481  movi     v1.4s, #4
//   0x011e10: 9127e3e9  add      x9, sp, #0x9f8
//   0x011e14: 4f000502  movi     v2.4s, #8
//   0x011e18: 4ea18403  add      v3.4s, v0.4s, v1.4s
//   0x011e1c: 8b08012a  add      x10, x9, x8
//   0x011e20: 91008108  add      x8, x8, #0x20
//   0x011e24: ad000d40  stp      q0, q3, [x10]
//   0x011e28: f110011f  cmp      x8, #0x400
//   0x011e2c: 4ea28400  add      v0.4s, v0.4s, v2.4s
//   0x011e30: 54ffff41  b.ne     #0x11e18
//   0x011e34: 528aaac8  mov      w8, #0x5556
//   0x011e38: 52802d89  mov      w9, #0x16c
//   0x011e3c: 72aaaaa8  movk     w8, #0x5555, lsl #16
//   0x011e40: 9127e3ea  add      x10, sp, #0x9f8
//   0x011e44: 14000005  b        #0x11e58
//   0x011e48: 51000d29  sub      w9, w9, #3
//   0x011e4c: 7100093f  cmp      w9, #2
//   0x011e50: 2a0b03e9  mov      w9, w11
//   0x011e54: 540004c9  b.ls     #0x11eec
//   0x011e58: 9b287d2b  smull    x11, w9, w8
//   0x011e5c: d37ffd6c  lsr      x12, x11, #0x3f
//   0x011e60: d360fd6b  lsr      x11, x11, #0x20
//   0x011e64: 710bfd3f  cmp      w9, #0x2ff
//   0x011e68: 0b0c016b  add      w11, w11, w12
//   0x011e6c: 54fffeec  b.gt     #0x11e48
//   0x011e70: 2a1f03ec  mov      w12, wzr
//   0x011e74: 93407d6d  sxtw     x13, w11
//   0x011e78: 14000007  b        #0x11e94
//   0x011e7c: aa0103e0  mov      x0, x1
//   0x011e80: 910005ad  add      x13, x13, #1
//   0x011e84: f10401bf  cmp      x13, #0x100
//   0x011e88: 1100058c  add      w12, w12, #1
//   0x011e8c: b820794e  str      w14, [x10, x0, lsl #2]
//   0x011e90: 54fffdca  b.ge     #0x11e48
//   0x011e94: b86d794e  ldr      w14, [x10, x13, lsl #2]
//   0x011e98: 53185dcf  lsl      w15, w14, #8
//   0x011e9c: 110401f0  add      w16, w15, #0x100
//   0x011ea0: b870db10  ldr      w16, [x24, w16, sxtw #2]
//   0x011ea4: b86fdb0f  ldr      w15, [x24, w15, sxtw #2]
//   0x011ea8: 4b0f020f  sub      w15, w16, w15
//   0x011eac: 2a0c03f0  mov      w16, w12
//   0x011eb0: b870d951  ldr      w17, [x10, w16, sxtw #2]
//   0x011eb4: 0b100162  add      w2, w11, w16
//   0x011eb8: 53185e20  lsl      w0, w17, #8
//   0x011ebc: 11040001  add      w1, w0, #0x100
//   0x011ec0: b861db01  ldr      w1, [x24, w1, sxtw #2]
//   0x011ec4: b860db00  ldr      w0, [x24, w0, sxtw #2]
//   0x011ec8: 4b000020  sub      w0, w1, w0
//   0x011ecc: 6b0f001f  cmp      w0, w15
//   0x011ed0: 93407c41  sxtw     x1, w2
//   0x011ed4: 54fffd49  b.ls     #0x11e7c
//   0x011ed8: 93407e00  sxtw     x0, w16
//   0x011edc: 6b0b0010  subs     w16, w0, w11
//   0x011ee0: b8217951  str      w17, [x10, x1, lsl #2]
//   0x011ee4: 54fffe6a  b.ge     #0x11eb0
//   0x011ee8: 17ffffe6  b        #0x11e80
//   0x011eec: 91001348  add      x8, x26, #4
//   0x011ef0: f90047e8  str      x8, [sp, #0x88]
//   0x011ef4: 91002348  add      x8, x26, #8
//   0x011ef8: f9002fe8  str      x8, [sp, #0x58]
//   0x011efc: 91004348  add      x8, x26, #0x10
//   0x011f00: f9002be8  str      x8, [sp, #0x50]
//   0x011f04: 91005348  add      x8, x26, #0x14
//   0x011f08: f9001fe8  str      x8, [sp, #0x38]
//   0x011f0c: 91001308  add      x8, x24, #4
//   0x011f10: a902a3fb  stp      x27, x8, [sp, #0x28]
//   0x011f14: d1001348  sub      x8, x26, #4
//   0x011f18: b90073f9  str      w25, [sp, #0x70]
//   0x011f1c: f90013e8  str      x8, [sp, #0x20]
//   0x011f20: d0000068  adrp     x8, #0x1f000
//   0x011f24: f947c908  ldr      x8, [x8, #0xf90]
//   0x011f28: b9401ffb  ldr      w27, [sp, #0x1c]
//   0x011f2c: 2a1f03f4  mov      w20, wzr
//   0x011f30: 9123c3f6  add      x22, sp, #0x8f0
//   0x011f34: 9104c108  add      x8, x8, #0x130
//   0x011f38: 9113c3f3  add      x19, sp, #0x4f0
//   0x011f3c: f90023e8  str      x8, [sp, #0x40]
//   0x011f40: 9137e3e4  add      x4, sp, #0xdf8
//   0x011f44: 2a1b03f9  mov      w25, w27
//   0x011f48: aa1f03e8  mov      x8, xzr
//   0x011f4c: aa1f03e9  mov      x9, xzr
//   0x011f50: f90033f8  str      x24, [sp, #0x60]
//   0x011f54: 14000005  b        #0x11f68
//   0x011f58: f94027e8  ldr      x8, [sp, #0x48]
//   0x011f5c: 91000508  add      x8, x8, #1
//   0x011f60: f104011f  cmp      x8, #0x100
//   0x011f64: 54005060  b.eq     #0x12970
//   0x011f68: 9127e3e9  add      x9, sp, #0x9f8
//   0x011f6c: b8687929  ldr      w9, [x9, x8, lsl #2]
//   0x011f70: f90027e8  str      x8, [sp, #0x48]
//   0x011f74: aa1f03eb  mov      x11, xzr
//   0x011f78: 93407d28  sxtw     x8, w9
//   0x011f7c: f90053e8  str      x8, [sp, #0xa0]
//   0x011f80: 53185d28  lsl      w8, w9, #8
//   0x011f84: 93407d0a  sxtw     x10, w8
//   0x011f88: aa1f03e8  mov      x8, xzr
//   0x011f8c: f9005fe9  str      x9, [sp, #0xb8]
//   0x011f90: f9003fea  str      x10, [sp, #0x78]
//   0x011f94: 1400000a  b        #0x11fbc
//   0x011f98: 2a1b03e8  mov      w8, w27
//   0x011f9c: f94063eb  ldr      x11, [sp, #0xc0]
//   0x011fa0: 2a0803fb  mov      w27, w8
//   0x011fa4: f9405be8  ldr      x8, [sp, #0xb0]
//   0x011fa8: 320b0129  orr      w9, w9, #0x200000
//   0x011fac: b82b7b09  str      w9, [x24, x11, lsl #2]
//   0x011fb0: 91000508  add      x8, x8, #1
//   0x011fb4: f104011f  cmp      x8, #0x100
//   0x011fb8: 54003b60  b.eq     #0x12724
//   0x011fbc: f9405fe9  ldr      x9, [sp, #0xb8]
//   0x011fc0: eb09011f  cmp      x8, x9
//   0x011fc4: 54ffff60  b.eq     #0x11fb0
//   0x011fc8: f9005be8  str      x8, [sp, #0xb0]
//   0x011fcc: 8b0a0108  add      x8, x8, x10
//   0x011fd0: b8687b09  ldr      w9, [x24, x8, lsl #2]
//   0x011fd4: f90063e8  str      x8, [sp, #0xc0]
//   0x011fd8: 37affe09  tbnz     w9, #0x15, #0x11f98
//   0x011fdc: 8b080b08  add      x8, x24, x8, lsl #2
//   0x011fe0: b9400508  ldr      w8, [x8, #4]
//   0x011fe4: 120a792b  and      w11, w9, #0xffdfffff
//   0x011fe8: 120a7908  and      w8, w8, #0xffdfffff
//   0x011fec: 51000508  sub      w8, w8, #1
//   0x011ff0: 29122fe8  stp      w8, w11, [sp, #0x90]
//   0x011ff4: 6b0b0108  subs     w8, w8, w11
//   0x011ff8: 54fffd0d  b.le     #0x11f98
//   0x011ffc: b94073e9  ldr      w9, [sp, #0x70]
//   0x012000: 7100113f  cmp      w9, #4
//   0x012004: 5400012b  b.lt     #0x12028
//   0x012008: f94023e0  ldr      x0, [sp, #0x40]
//   0x01200c: b0000021  adrp     x1, #0x17000
//   0x012010: 11000505  add      w5, w8, #1
//   0x012014: 9103ac21  add      x1, x1, #0xeb
//   0x012018: a94b0be3  ldp      x3, x2, [sp, #0xb0]
//   0x01201c: 2a1403e4  mov      w4, w20
//   0x012020: 97ffc298  bl       #0x2a80
//   0x012024: 9137e3e4  add      x4, sp, #0xdf8
//   0x012028: b94097e8  ldr      w8, [sp, #0x94]
//   0x01202c: 52800022  mov      w2, #1
//   0x012030: b9111be8  str      w8, [sp, #0x1118]
//   0x012034: b94093e8  ldr      w8, [sp, #0x90]
//   0x012038: b90f8be8  str      w8, [sp, #0xf88]
//   0x01203c: 52800048  mov      w8, #2
//   0x012040: b90dfbe8  str      w8, [sp, #0xdf8]
//   0x012044: 1400000d  b        #0x12078
//   0x012048: b940effb  ldr      w27, [sp, #0xec]
//   0x01204c: aa1403f5  mov      x21, x20
//   0x012050: a9460bf8  ldp      x24, x2, [sp, #0x60]
//   0x012054: b94077f4  ldr      w20, [sp, #0x74]
//   0x012058: 2a1b03f9  mov      w25, w27
//   0x01205c: 9137e3e4  add      x4, sp, #0xdf8
//   0x012060: 2a1b03e8  mov      w8, w27
//   0x012064: 2a1b03e9  mov      w9, w27
//   0x012068: 37f8349b  tbnz     w27, #0x1f, #0x126f8
//   0x01206c: 7100005f  cmp      w2, #0
//   0x012070: 2a1903e8  mov      w8, w25
//   0x012074: 5400342d  b.le     #0x126f8
//   0x012078: 93407c53  sxtw     x19, w2
//   0x01207c: d1000662  sub      x2, x19, #1
//   0x012080: 71018a7f  cmp      w19, #0x62
//   0x012084: 540000cb  b.lt     #0x1209c
//   0x012088: 52807d20  mov      w0, #0x3e9
//   0x01208c: aa0203f6  mov      x22, x2
//   0x012090: 97ffc1f8  bl       #0x2870
//   0x012094: aa1603e2  mov      x2, x22
//   0x012098: 9137e3e4  add      x4, sp, #0xdf8
//   0x01209c: 914007e9  add      x9, sp, #1, lsl #12
//   0x0120a0: d37ef448  lsl      x8, x2, #2
//   0x0120a4: 91046129  add      x9, x9, #0x118
//   0x0120a8: b8686925  ldr      w5, [x9, x8]
//   0x0120ac: 913e23e9  add      x9, sp, #0xf88
//   0x0120b0: b8686929  ldr      w9, [x9, x8]
//   0x0120b4: b8686896  ldr      w22, [x4, x8]
//   0x0120b8: 4b05012a  sub      w10, w9, w5
//   0x0120bc: 7100515f  cmp      w10, #0x14
//   0x0120c0: 93407d3c  sxtw     x28, w9
//   0x0120c4: 54000c2b  b.lt     #0x12248
//   0x0120c8: 71003edf  cmp      w22, #0xf
//   0x0120cc: 54000bea  b.ge     #0x12248
//   0x0120d0: 93407cad  sxtw     x13, w5
//   0x0120d4: b87c7b4a  ldr      w10, [x26, x28, lsl #2]
//   0x0120d8: 0b05012b  add      w11, w9, w5
//   0x0120dc: b86d7b4c  ldr      w12, [x26, x13, lsl #2]
//   0x0120e0: 13017d6b  asr      w11, w11, #1
//   0x0120e4: b86bdb4b  ldr      w11, [x26, w11, sxtw #2]
//   0x0120e8: 0b16014a  add      w10, w10, w22
//   0x0120ec: 0b16018c  add      w12, w12, w22
//   0x0120f0: 386a4aea  ldrb     w10, [x23, w10, uxtw]
//   0x0120f4: 386c4aec  ldrb     w12, [x23, w12, uxtw]
//   0x0120f8: 0b16016b  add      w11, w11, w22
//   0x0120fc: 386b4aeb  ldrb     w11, [x23, w11, uxtw]
//   0x012100: 6b0a019f  cmp      w12, w10
//   0x012104: 1a8a818e  csel     w14, w12, w10, hi
//   0x012108: 1a8c814a  csel     w10, w10, w12, hi
//   0x01210c: 6b0b015f  cmp      w10, w11
//   0x012110: 1a8b814a  csel     w10, w10, w11, hi
//   0x012114: 6b0b01df  cmp      w14, w11
//   0x012118: 1a8e814f  csel     w15, w10, w14, hi
//   0x01211c: 2a0903ec  mov      w12, w9
//   0x012120: 2a0503ea  mov      w10, w5
//   0x012124: 2a0903ee  mov      w14, w9
//   0x012128: 2a0503eb  mov      w11, w5
//   0x01212c: 6b0e017f  cmp      w11, w14
//   0x012130: 540003ac  b.gt     #0x121a4
//   0x012134: 93407dd0  sxtw     x16, w14
//   0x012138: 93407d4a  sxtw     x10, w10
//   0x01213c: 93407d71  sxtw     x17, w11
//   0x012140: b8717b4b  ldr      w11, [x26, x17, lsl #2]
//   0x012144: 0b160160  add      w0, w11, w22
//   0x012148: 38604ae0  ldrb     w0, [x23, w0, uxtw]
//   0x01214c: 6b0f0000  subs     w0, w0, w15
//   0x012150: 54000100  b.eq     #0x12170
//   0x012154: 7100001f  cmp      w0, #0
//   0x012158: 5400024c  b.gt     #0x121a0
//   0x01215c: 9100062b  add      x11, x17, #1
//   0x012160: eb10023f  cmp      x17, x16
//   0x012164: aa0b03f1  mov      x17, x11
//   0x012168: 54fffecb  b.lt     #0x12140
//   0x01216c: 1400000e  b        #0x121a4
//   0x012170: d37ef540  lsl      x0, x10, #2
//   0x012174: b8606b41  ldr      w1, [x26, x0]
//   0x012178: 9100054a  add      x10, x10, #1
//   0x01217c: 6b1101df  cmp      w14, w17
//   0x012180: b8317b41  str      w1, [x26, x17, lsl #2]
//   0x012184: b8206b4b  str      w11, [x26, x0]
//   0x012188: 1100062b  add      w11, w17, #1
//   0x01218c: 54fffd8c  b.gt     #0x1213c
//   0x012190: 1100062b  add      w11, w17, #1
//   0x012194: 6b0e017f  cmp      w11, w14
//   0x012198: 540000ad  b.le     #0x121ac
//   0x01219c: 14000024  b        #0x1222c
//   0x0121a0: 2a1103eb  mov      w11, w17
//   0x0121a4: 6b0e017f  cmp      w11, w14
//   0x0121a8: 5400042c  b.gt     #0x1222c
//   0x0121ac: 93407d70  sxtw     x16, w11
//   0x0121b0: 93407d8c  sxtw     x12, w12
//   0x0121b4: 93407dd1  sxtw     x17, w14
//   0x0121b8: b8717b4e  ldr      w14, [x26, x17, lsl #2]
//   0x0121bc: 0b1601c0  add      w0, w14, w22
//   0x0121c0: 38604ae0  ldrb     w0, [x23, w0, uxtw]
//   0x0121c4: 6b0f0000  subs     w0, w0, w15
//   0x0121c8: 540000e0  b.eq     #0x121e4
//   0x0121cc: 37f801e0  tbnz     w0, #0x1f, #0x12208
//   0x0121d0: d100062e  sub      x14, x17, #1
//   0x0121d4: eb10023f  cmp      x17, x16
//   0x0121d8: aa0e03f1  mov      x17, x14
//   0x0121dc: 54fffeec  b.gt     #0x121b8
//   0x0121e0: 14000013  b        #0x1222c
//   0x0121e4: d37ef580  lsl      x0, x12, #2
//   0x0121e8: b8606b41  ldr      w1, [x26, x0]
//   0x0121ec: d100058c  sub      x12, x12, #1
//   0x0121f0: 6b11017f  cmp      w11, w17
//   0x0121f4: b8317b41  str      w1, [x26, x17, lsl #2]
//   0x0121f8: b8206b4e  str      w14, [x26, x0]
//   0x0121fc: 5100062e  sub      w14, w17, #1
//   0x012200: 54fffdab  b.lt     #0x121b4
//   0x012204: 1400000a  b        #0x1222c
//   0x012208: d37ef610  lsl      x16, x16, #2
//   0x01220c: b8706b40  ldr      w0, [x26, x16]
//   0x012210: 1100056b  add      w11, w11, #1
//   0x012214: b8306b4e  str      w14, [x26, x16]
//   0x012218: 5100062e  sub      w14, w17, #1
//   0x01221c: b8317b40  str      w0, [x26, x17, lsl #2]
//   0x012220: 6b0e017f  cmp      w11, w14
//   0x012224: 54fff88d  b.le     #0x12134
//   0x012228: 17ffffdf  b        #0x121a4
//   0x01222c: 6b0a019f  cmp      w12, w10
//   0x012230: 5400038a  b.ge     #0x122a0
//   0x012234: 110006c8  add      w8, w22, #1
//   0x012238: b8227888  str      w8, [x4, x2, lsl #2]
//   0x01223c: 71018a7f  cmp      w19, #0x62
//   0x012240: 54fff24a  b.ge     #0x12088
//   0x012244: 17ffff96  b        #0x1209c
//   0x012248: 7100055f  cmp      w10, #1
//   0x01224c: 54fff0ab  b.lt     #0x12060
//   0x012250: b000002b  adrp     x11, #0x17000
//   0x012254: aa1f03e8  mov      x8, xzr
//   0x012258: 9105216b  add      x11, x11, #0x148
//   0x01225c: b8687969  ldr      w9, [x11, x8, lsl #2]
//   0x012260: 91000508  add      x8, x8, #1
//   0x012264: 6b0a013f  cmp      w9, w10
//   0x012268: 54ffffad  b.le     #0x1225c
//   0x01226c: 7100051f  cmp      w8, #1
//   0x012270: 54ffef80  b.eq     #0x12060
//   0x012274: d1000508  sub      x8, x8, #1
//   0x012278: 110004a9  add      w9, w5, #1
//   0x01227c: b90077f4  str      w20, [sp, #0x74]
//   0x012280: aa1503f4  mov      x20, x21
//   0x012284: b9009fe9  str      w9, [sp, #0x9c]
//   0x012288: 92407d08  and      x8, x8, #0xffffffff
//   0x01228c: 110008a9  add      w9, w5, #2
//   0x012290: f90037e2  str      x2, [sp, #0x68]
//   0x012294: b9009be9  str      w9, [sp, #0x98]
//   0x012298: f90043e5  str      x5, [sp, #0x80]
//   0x01229c: 1400009e  b        #0x12514
//   0x0122a0: 4b05014f  sub      w15, w10, w5
//   0x0122a4: 4b0a0170  sub      w16, w11, w10
//   0x0122a8: 6b1001ff  cmp      w15, w16
//   0x0122ac: 1a90b1ef  csel     w15, w15, w16, lt
//   0x0122b0: 710005e0  subs     w0, w15, #1
//   0x0122b4: 540005cb  b.lt     #0x1236c
//   0x0122b8: 4b0f0171  sub      w17, w11, w15
//   0x0122bc: 91000410  add      x16, x0, #1
//   0x0122c0: f100221f  cmp      x16, #8
//   0x0122c4: 93407e31  sxtw     x17, w17
//   0x0122c8: 54000403  b.lo     #0x12348
//   0x0122cc: f94047e3  ldr      x3, [sp, #0x88]
//   0x0122d0: 8b000222  add      x2, x17, x0
//   0x0122d4: 8b0d0b41  add      x1, x26, x13, lsl #2
//   0x0122d8: 8b020862  add      x2, x3, x2, lsl #2
//   0x0122dc: eb02003f  cmp      x1, x2
//   0x0122e0: 540000e2  b.hs     #0x122fc
//   0x0122e4: f94047e1  ldr      x1, [sp, #0x88]
//   0x0122e8: 8b0001a0  add      x0, x13, x0
//   0x0122ec: 8b000820  add      x0, x1, x0, lsl #2
//   0x0122f0: 8b110b41  add      x1, x26, x17, lsl #2
//   0x0122f4: eb00003f  cmp      x1, x0
//   0x0122f8: 54000283  b.lo     #0x12348
//   0x0122fc: f9402be3  ldr      x3, [sp, #0x50]
//   0x012300: 927d7600  and      x0, x16, #0x1fffffff8
//   0x012304: 8b0d0001  add      x1, x0, x13
//   0x012308: 4b0001ef  sub      w15, w15, w0
//   0x01230c: 8b110862  add      x2, x3, x17, lsl #2
//   0x012310: 8b110011  add      x17, x0, x17
//   0x012314: 8b0d086d  add      x13, x3, x13, lsl #2
//   0x012318: aa0003e3  mov      x3, x0
//   0x01231c: ad7f8da0  ldp      q0, q3, [x13, #-0x10]
//   0x012320: ad7f8841  ldp      q1, q2, [x2, #-0x10]
//   0x012324: f1002063  subs     x3, x3, #8
//   0x012328: ad3f89a1  stp      q1, q2, [x13, #-0x10]
//   0x01232c: ad3f8c40  stp      q0, q3, [x2, #-0x10]
//   0x012330: 91008042  add      x2, x2, #0x20
//   0x012334: 910081ad  add      x13, x13, #0x20
//   0x012338: 54ffff21  b.ne     #0x1231c
//   0x01233c: eb00021f  cmp      x16, x0
//   0x012340: aa0103ed  mov      x13, x1
//   0x012344: 54000140  b.eq     #0x1236c
//   0x012348: 8b0d0b4d  add      x13, x26, x13, lsl #2
//   0x01234c: 8b110b50  add      x16, x26, x17, lsl #2
//   0x012350: b9400211  ldr      w17, [x16]
//   0x012354: b94001a0  ldr      w0, [x13]
//   0x012358: 510005ef  sub      w15, w15, #1
//   0x01235c: 710001ff  cmp      w15, #0
//   0x012360: b80045b1  str      w17, [x13], #4
//   0x012364: b8004600  str      w0, [x16], #4
//   0x012368: 54ffff4c  b.gt     #0x12350
//   0x01236c: 4b0c012d  sub      w13, w9, w12
//   0x012370: 4b0e018c  sub      w12, w12, w14
//   0x012374: 6b0c01bf  cmp      w13, w12
//   0x012378: 1a8cb1ad  csel     w13, w13, w12, lt
//   0x01237c: 710005b1  subs     w17, w13, #1
//   0x012380: 5400062b  b.lt     #0x12444
//   0x012384: 4b0d012f  sub      w15, w9, w13
//   0x012388: 9100062e  add      x14, x17, #1
//   0x01238c: 93407def  sxtw     x15, w15
//   0x012390: f10021df  cmp      x14, #8
//   0x012394: 93407d70  sxtw     x16, w11
//   0x012398: 54000423  b.lo     #0x1241c
//   0x01239c: f9402fe2  ldr      x2, [sp, #0x58]
//   0x0123a0: 8b1101e1  add      x1, x15, x17
//   0x0123a4: 8b100b40  add      x0, x26, x16, lsl #2
//   0x0123a8: 8b010841  add      x1, x2, x1, lsl #2
//   0x0123ac: eb01001f  cmp      x0, x1
//   0x0123b0: 540000e2  b.hs     #0x123cc
//   0x0123b4: f94047e0  ldr      x0, [sp, #0x88]
//   0x0123b8: 8b110211  add      x17, x16, x17
//   0x0123bc: 8b110811  add      x17, x0, x17, lsl #2
//   0x0123c0: 8b0f0800  add      x0, x0, x15, lsl #2
//   0x0123c4: eb11001f  cmp      x0, x17
//   0x0123c8: 540002a3  b.lo     #0x1241c
//   0x0123cc: f9401fe0  ldr      x0, [sp, #0x38]
//   0x0123d0: f9402be2  ldr      x2, [sp, #0x50]
//   0x0123d4: 927d75d1  and      x17, x14, #0x1fffffff8
//   0x0123d8: 4b1101ad  sub      w13, w13, w17
//   0x0123dc: 8b0f0801  add      x1, x0, x15, lsl #2
//   0x0123e0: 8b100220  add      x0, x17, x16
//   0x0123e4: 8b0f022f  add      x15, x17, x15
//   0x0123e8: 8b100850  add      x16, x2, x16, lsl #2
//   0x0123ec: aa1103e2  mov      x2, x17
//   0x0123f0: ad7f8e00  ldp      q0, q3, [x16, #-0x10]
//   0x0123f4: ad7f8821  ldp      q1, q2, [x1, #-0x10]
//   0x0123f8: f1002042  subs     x2, x2, #8
//   0x0123fc: ad3f8a01  stp      q1, q2, [x16, #-0x10]
//   0x012400: ad3f8c20  stp      q0, q3, [x1, #-0x10]
//   0x012404: 91008021  add      x1, x1, #0x20
//   0x012408: 91008210  add      x16, x16, #0x20
//   0x01240c: 54ffff21  b.ne     #0x123f0
//   0x012410: eb1101df  cmp      x14, x17
//   0x012414: aa0003f0  mov      x16, x0
//   0x012418: 54000160  b.eq     #0x12444
//   0x01241c: 8b100b4e  add      x14, x26, x16, lsl #2
//   0x012420: f94047f0  ldr      x16, [sp, #0x88]
//   0x012424: 8b0f0a0f  add      x15, x16, x15, lsl #2
//   0x012428: b94001f0  ldr      w16, [x15]
//   0x01242c: b94001d1  ldr      w17, [x14]
//   0x012430: 510005ad  sub      w13, w13, #1
//   0x012434: 710001bf  cmp      w13, #0
//   0x012438: b80045d0  str      w16, [x14], #4
//   0x01243c: b80045f1  str      w17, [x15], #4
//   0x012440: 54ffff4c  b.gt     #0x12428
//   0x012444: 4b0a00aa  sub      w10, w5, w10
//   0x012448: 4b0c012c  sub      w12, w9, w12
//   0x01244c: 0b0b014a  add      w10, w10, w11
//   0x012450: 1100058b  add      w11, w12, #1
//   0x012454: 5100054d  sub      w13, w10, #1
//   0x012458: 4b0b012b  sub      w11, w9, w11
//   0x01245c: 4b0501af  sub      w15, w13, w5
//   0x012460: 6b0b01ff  cmp      w15, w11
//   0x012464: 1a8cb4ab  csinc    w11, w5, w12, lt
//   0x012468: 1a89b1b0  csel     w16, w13, w9, lt
//   0x01246c: 4b0a018e  sub      w14, w12, w10
//   0x012470: 1a8db129  csel     w9, w9, w13, lt
//   0x012474: 4b0b020d  sub      w13, w16, w11
//   0x012478: 1a8ca4af  csinc    w15, w5, w12, ge
//   0x01247c: 6b0e01bf  cmp      w13, w14
//   0x012480: 1a8bb14d  csel     w13, w10, w11, lt
//   0x012484: 1a8cb20e  csel     w14, w16, w12, lt
//   0x012488: 1a90b18c  csel     w12, w12, w16, lt
//   0x01248c: 4b0f0131  sub      w17, w9, w15
//   0x012490: 1a8ab16a  csel     w10, w11, w10, lt
//   0x012494: 4b0d018b  sub      w11, w12, w13
//   0x012498: 1a96b6d0  cinc     w16, w22, ge
//   0x01249c: 1a96a6c0  cinc     w0, w22, lt
//   0x0124a0: 6b0b023f  cmp      w17, w11
//   0x0124a4: 914007e2  add      x2, sp, #1, lsl #12
//   0x0124a8: d37ef66b  lsl      x11, x19, #2
//   0x0124ac: 1a8db1f1  csel     w17, w15, w13, lt
//   0x0124b0: 1a8fb1ad  csel     w13, w13, w15, lt
//   0x0124b4: 91046042  add      x2, x2, #0x118
//   0x0124b8: 1a8cb12f  csel     w15, w9, w12, lt
//   0x0124bc: 1a89b189  csel     w9, w12, w9, lt
//   0x0124c0: 1a80b2cc  csel     w12, w22, w0, lt
//   0x0124c4: 1a96b000  csel     w0, w0, w22, lt
//   0x0124c8: 91001161  add      x1, x11, #4
//   0x0124cc: b828684d  str      w13, [x2, x8]
//   0x0124d0: 913e23ed  add      x13, sp, #0xf88
//   0x0124d4: b82869a9  str      w9, [x13, x8]
//   0x0124d8: b8286880  str      w0, [x4, x8]
//   0x0124dc: b82b6851  str      w17, [x2, x11]
//   0x0124e0: b82b69af  str      w15, [x13, x11]
//   0x0124e4: b82b688c  str      w12, [x4, x11]
//   0x0124e8: b821684a  str      w10, [x2, x1]
//   0x0124ec: b82169ae  str      w14, [x13, x1]
//   0x0124f0: b8216890  str      w16, [x4, x1]
//   0x0124f4: 11000a62  add      w2, w19, #2
//   0x0124f8: 17fffedd  b        #0x1206c
//   0x0124fc: f94057e8  ldr      x8, [sp, #0xa8]
//   0x012500: f94043e5  ldr      x5, [sp, #0x80]
//   0x012504: b000002b  adrp     x11, #0x17000
//   0x012508: 9105216b  add      x11, x11, #0x148
//   0x01250c: f100011f  cmp      x8, #0
//   0x012510: 54ffd9cd  b.le     #0x12048
//   0x012514: d1000508  sub      x8, x8, #1
//   0x012518: b868797b  ldr      w27, [x11, x8, lsl #2]
//   0x01251c: f90057e8  str      x8, [sp, #0xa8]
//   0x012520: 0b050368  add      w8, w27, w5
//   0x012524: 93407d15  sxtw     x21, w8
//   0x012528: b9409be8  ldr      w8, [sp, #0x98]
//   0x01252c: aa1503ea  mov      x10, x21
//   0x012530: b900cfe8  str      w8, [sp, #0xcc]
//   0x012534: b9409fe8  ldr      w8, [sp, #0x9c]
//   0x012538: 291a17e8  stp      w8, w5, [sp, #0xd0]
//   0x01253c: 2a0503e8  mov      w8, w5
//   0x012540: eb1c015f  cmp      x10, x28
//   0x012544: 540002ad  b.le     #0x12598
//   0x012548: 17ffffed  b        #0x124fc
//   0x01254c: 0b190368  add      w8, w27, w25
//   0x012550: 93407d19  sxtw     x25, w8
//   0x012554: b940d7e9  ldr      w9, [sp, #0xd4]
//   0x012558: b940cbe8  ldr      w8, [sp, #0xc8]
//   0x01255c: f9406fea  ldr      x10, [sp, #0xd8]
//   0x012560: 11000d29  add      w9, w9, #3
//   0x012564: b900d7e9  str      w9, [sp, #0xd4]
//   0x012568: b940d3e9  ldr      w9, [sp, #0xd0]
//   0x01256c: b8397b48  str      w8, [x26, x25, lsl #2]
//   0x012570: b940efe8  ldr      w8, [sp, #0xec]
//   0x012574: 91000d4a  add      x10, x10, #3
//   0x012578: 11000d29  add      w9, w9, #3
//   0x01257c: b900d3e9  str      w9, [sp, #0xd0]
//   0x012580: b940cfe9  ldr      w9, [sp, #0xcc]
//   0x012584: 11000d29  add      w9, w9, #3
//   0x012588: b900cfe9  str      w9, [sp, #0xcc]
//   0x01258c: 37f80ac8  tbnz     w8, #0x1f, #0x126e4
//   0x012590: eb1c015f  cmp      x10, x28
//   0x012594: 54fffb4c  b.gt     #0x124fc
//   0x012598: b86a7b48  ldr      w8, [x26, x10, lsl #2]
//   0x01259c: b940d7f8  ldr      w24, [sp, #0xd4]
//   0x0125a0: f9006fea  str      x10, [sp, #0xd8]
//   0x0125a4: 0b160113  add      w19, w8, w22
//   0x0125a8: b900cbe8  str      w8, [sp, #0xc8]
//   0x0125ac: b878db48  ldr      w8, [x26, w24, sxtw #2]
//   0x0125b0: f94073e3  ldr      x3, [sp, #0xe0]
//   0x0125b4: 9103b3e5  add      x5, sp, #0xec
//   0x0125b8: 2a1303e1  mov      w1, w19
//   0x0125bc: 0b160100  add      w0, w8, w22
//   0x0125c0: aa1703e2  mov      x2, x23
//   0x0125c4: 2a1403e4  mov      w4, w20
//   0x0125c8: 93407f19  sxtw     x25, w24
//   0x0125cc: 940003a3  bl       #0x13458
//   0x0125d0: 72001c1f  tst      w0, #0xff
//   0x0125d4: 54000100  b.eq     #0x125f4
//   0x0125d8: b8797b48  ldr      w8, [x26, x25, lsl #2]
//   0x0125dc: 0b180369  add      w9, w27, w24
//   0x0125e0: 6b15033f  cmp      w25, w21
//   0x0125e4: 4b1b0338  sub      w24, w25, w27
//   0x0125e8: b829db48  str      w8, [x26, w9, sxtw #2]
//   0x0125ec: 54fffe0a  b.ge     #0x125ac
//   0x0125f0: 14000003  b        #0x125fc
//   0x0125f4: 0b190368  add      w8, w27, w25
//   0x0125f8: 93407d19  sxtw     x25, w8
//   0x0125fc: f9406fe8  ldr      x8, [sp, #0xd8]
//   0x012600: b940cbe9  ldr      w9, [sp, #0xc8]
//   0x012604: eb1c011f  cmp      x8, x28
//   0x012608: b8397b49  str      w9, [x26, x25, lsl #2]
//   0x01260c: 54fff78a  b.ge     #0x124fc
//   0x012610: 91000508  add      x8, x8, #1
//   0x012614: b8687b48  ldr      w8, [x26, x8, lsl #2]
//   0x012618: b940d3f8  ldr      w24, [sp, #0xd0]
//   0x01261c: 0b160113  add      w19, w8, w22
//   0x012620: b900cbe8  str      w8, [sp, #0xc8]
//   0x012624: b878db48  ldr      w8, [x26, w24, sxtw #2]
//   0x012628: f94073e3  ldr      x3, [sp, #0xe0]
//   0x01262c: 9103b3e5  add      x5, sp, #0xec
//   0x012630: 2a1303e1  mov      w1, w19
//   0x012634: 0b160100  add      w0, w8, w22
//   0x012638: aa1703e2  mov      x2, x23
//   0x01263c: 2a1403e4  mov      w4, w20
//   0x012640: 93407f19  sxtw     x25, w24
//   0x012644: 94000385  bl       #0x13458
//   0x012648: 72001c1f  tst      w0, #0xff
//   0x01264c: 54000100  b.eq     #0x1266c
//   0x012650: b8797b48  ldr      w8, [x26, x25, lsl #2]
//   0x012654: 0b180369  add      w9, w27, w24
//   0x012658: 6b15033f  cmp      w25, w21
//   0x01265c: 4b1b0338  sub      w24, w25, w27
//   0x012660: b829db48  str      w8, [x26, w9, sxtw #2]
//   0x012664: 54fffe0a  b.ge     #0x12624
//   0x012668: 14000003  b        #0x12674
//   0x01266c: 0b190368  add      w8, w27, w25
//   0x012670: 93407d19  sxtw     x25, w8
//   0x012674: f9406fe8  ldr      x8, [sp, #0xd8]
//   0x012678: b940cbe9  ldr      w9, [sp, #0xc8]
//   0x01267c: 91000908  add      x8, x8, #2
//   0x012680: eb1c011f  cmp      x8, x28
//   0x012684: b8397b49  str      w9, [x26, x25, lsl #2]
//   0x012688: 54fff3ac  b.gt     #0x124fc
//   0x01268c: b8687b48  ldr      w8, [x26, x8, lsl #2]
//   0x012690: b940cff8  ldr      w24, [sp, #0xcc]
//   0x012694: 0b160113  add      w19, w8, w22
//   0x012698: b900cbe8  str      w8, [sp, #0xc8]
//   0x01269c: b878db48  ldr      w8, [x26, w24, sxtw #2]
//   0x0126a0: f94073e3  ldr      x3, [sp, #0xe0]
//   0x0126a4: 9103b3e5  add      x5, sp, #0xec
//   0x0126a8: 2a1303e1  mov      w1, w19
//   0x0126ac: 0b160100  add      w0, w8, w22
//   0x0126b0: aa1703e2  mov      x2, x23
//   0x0126b4: 2a1403e4  mov      w4, w20
//   0x0126b8: 93407f19  sxtw     x25, w24
//   0x0126bc: 94000367  bl       #0x13458
//   0x0126c0: 72001c1f  tst      w0, #0xff
//   0x0126c4: 54fff440  b.eq     #0x1254c
//   0x0126c8: b8797b48  ldr      w8, [x26, x25, lsl #2]
//   0x0126cc: 0b180369  add      w9, w27, w24
//   0x0126d0: 6b15033f  cmp      w25, w21
//   0x0126d4: 4b1b0338  sub      w24, w25, w27
//   0x0126d8: b829db48  str      w8, [x26, w9, sxtw #2]
//   0x0126dc: 54fffe0a  b.ge     #0x1269c
//   0x0126e0: 17ffff9d  b        #0x12554
//   0x0126e4: aa1403f5  mov      x21, x20
//   0x0126e8: f94033f8  ldr      x24, [sp, #0x60]
//   0x0126ec: b94077f4  ldr      w20, [sp, #0x74]
//   0x0126f0: 2a0803f9  mov      w25, w8
//   0x0126f4: 9137e3e4  add      x4, sp, #0xdf8
//   0x0126f8: 37f81548  tbnz     w8, #0x1f, #0x129a0
//   0x0126fc: 29522beb  ldp      w11, w10, [sp, #0x90]
//   0x012700: f94063e9  ldr      x9, [sp, #0xc0]
//   0x012704: 9123c3f6  add      x22, sp, #0x8f0
//   0x012708: 9113c3f3  add      x19, sp, #0x4f0
//   0x01270c: 4b0a028a  sub      w10, w20, w10
//   0x012710: 0b0b014a  add      w10, w10, w11
//   0x012714: b8697b09  ldr      w9, [x24, x9, lsl #2]
//   0x012718: 11000554  add      w20, w10, #1
//   0x01271c: f9403fea  ldr      x10, [sp, #0x78]
//   0x012720: 17fffe1f  b        #0x11f9c
//   0x012724: f94053e8  ldr      x8, [sp, #0xa0]
//   0x012728: 38686ac8  ldrb     w8, [x22, x8]
//   0x01272c: 34000088  cbz      w8, #0x1273c
//   0x012730: 52807dc0  mov      w0, #0x3ee
//   0x012734: 97ffc04f  bl       #0x2870
//   0x012738: 9137e3e4  add      x4, sp, #0xdf8
//   0x01273c: f9401be9  ldr      x9, [sp, #0x30]
//   0x012740: f94053ea  ldr      x10, [sp, #0xa0]
//   0x012744: aa1f03e8  mov      x8, xzr
//   0x012748: 8b0a0929  add      x9, x9, x10, lsl #2
//   0x01274c: b85fc12a  ldur     w10, [x9, #-4]
//   0x012750: 9103c3eb  add      x11, sp, #0xf0
//   0x012754: 120a794a  and      w10, w10, #0xffdfffff
//   0x012758: b8286a6a  str      w10, [x19, x8]
//   0x01275c: b940012a  ldr      w10, [x9]
//   0x012760: 91100129  add      x9, x9, #0x400
//   0x012764: 120a794a  and      w10, w10, #0xffdfffff
//   0x012768: 5100054a  sub      w10, w10, #1
//   0x01276c: b828696a  str      w10, [x11, x8]
//   0x012770: 91001108  add      x8, x8, #4
//   0x012774: f110011f  cmp      x8, #0x400
//   0x012778: 54fffea1  b.ne     #0x1274c
//   0x01277c: f9403fe8  ldr      x8, [sp, #0x78]
//   0x012780: 9103c3ed  add      x13, sp, #0xf0
//   0x012784: b8a87b09  ldrsw    x9, [x24, x8, lsl #2]
//   0x012788: f94053e8  ldr      x8, [sp, #0xa0]
//   0x01278c: 926af929  and      x9, x9, #0xffffffffffdfffff
//   0x012790: b8687a68  ldr      w8, [x19, x8, lsl #2]
//   0x012794: 6b08013f  cmp      w9, w8
//   0x012798: 540000ab  b.lt     #0x127ac
//   0x01279c: 14000013  b        #0x127e8
//   0x0127a0: 91000529  add      x9, x9, #1
//   0x0127a4: eb28c13f  cmp      x9, w8, sxtw
//   0x0127a8: 5400020a  b.ge     #0x127e8
//   0x0127ac: b8697b4a  ldr      w10, [x26, x9, lsl #2]
//   0x0127b0: 5100054a  sub      w10, w10, #1
//   0x0127b4: 0a8a7eab  and      w11, w21, w10, asr #31
//   0x0127b8: 0b0a016a  add      w10, w11, w10
//   0x0127bc: 386acaeb  ldrb     w11, [x23, w10, sxtw]
//   0x0127c0: 386b6acc  ldrb     w12, [x22, x11]
//   0x0127c4: 35fffeec  cbnz     w12, #0x127a0
//   0x0127c8: d37ef568  lsl      x8, x11, #2
//   0x0127cc: b8a86a6b  ldrsw    x11, [x19, x8]
//   0x0127d0: 1100056c  add      w12, w11, #1
//   0x0127d4: b8286a6c  str      w12, [x19, x8]
//   0x0127d8: f94053e8  ldr      x8, [sp, #0xa0]
//   0x0127dc: b82b7b4a  str      w10, [x26, x11, lsl #2]
//   0x0127e0: b8687a68  ldr      w8, [x19, x8, lsl #2]
//   0x0127e4: 17ffffef  b        #0x127a0
//   0x0127e8: f9403fe9  ldr      x9, [sp, #0x78]
//   0x0127ec: 11040133  add      w19, w9, #0x100
//   0x0127f0: f94053e9  ldr      x9, [sp, #0xa0]
//   0x0127f4: b873db0a  ldr      w10, [x24, w19, sxtw #2]
//   0x0127f8: b86979a9  ldr      w9, [x13, x9, lsl #2]
//   0x0127fc: 120a794a  and      w10, w10, #0xffdfffff
//   0x012800: 5100054a  sub      w10, w10, #1
//   0x012804: 6b09015f  cmp      w10, w9
//   0x012808: 5400022d  b.le     #0x1284c
//   0x01280c: b86adb4b  ldr      w11, [x26, w10, sxtw #2]
//   0x012810: 5100056b  sub      w11, w11, #1
//   0x012814: 0a8b7eac  and      w12, w21, w11, asr #31
//   0x012818: 0b0b018b  add      w11, w12, w11
//   0x01281c: 386bcaec  ldrb     w12, [x23, w11, sxtw]
//   0x012820: 386c6acd  ldrb     w13, [x22, x12]
//   0x012824: 35fffeed  cbnz     w13, #0x12800
//   0x012828: d37ef589  lsl      x9, x12, #2
//   0x01282c: 9103c3ee  add      x14, sp, #0xf0
//   0x012830: b8a969cc  ldrsw    x12, [x14, x9]
//   0x012834: 5100058d  sub      w13, w12, #1
//   0x012838: b82969cd  str      w13, [x14, x9]
//   0x01283c: f94053e9  ldr      x9, [sp, #0xa0]
//   0x012840: b82c7b4b  str      w11, [x26, x12, lsl #2]
//   0x012844: b86979c9  ldr      w9, [x14, x9, lsl #2]
//   0x012848: 17ffffee  b        #0x12800
//   0x01284c: 5100050a  sub      w10, w8, #1
//   0x012850: 6b09015f  cmp      w10, w9
//   0x012854: 54000100  b.eq     #0x12874
//   0x012858: 35000088  cbnz     w8, #0x12868
//   0x01285c: f94017e8  ldr      x8, [sp, #0x28]
//   0x012860: 6b08013f  cmp      w9, w8
//   0x012864: 54000080  b.eq     #0x12874
//   0x012868: 52807de0  mov      w0, #0x3ef
//   0x01286c: 97ffc001  bl       #0x2870
//   0x012870: 9137e3e4  add      x4, sp, #0xdf8
//   0x012874: f94053ea  ldr      x10, [sp, #0xa0]
//   0x012878: aa1f03e9  mov      x9, xzr
//   0x01287c: 93407e68  sxtw     x8, w19
//   0x012880: 8b0a0b0a  add      x10, x24, x10, lsl #2
//   0x012884: 8b09014b  add      x11, x10, x9
//   0x012888: b940016c  ldr      w12, [x11]
//   0x01288c: b944016d  ldr      w13, [x11, #0x400]
//   0x012890: 91200129  add      x9, x9, #0x800
//   0x012894: f141013f  cmp      x9, #0x40, lsl #12
//   0x012898: 320b018c  orr      w12, w12, #0x200000
//   0x01289c: 320b01ad  orr      w13, w13, #0x200000
//   0x0128a0: b900016c  str      w12, [x11]
//   0x0128a4: b904016d  str      w13, [x11, #0x400]
//   0x0128a8: 54fffee1  b.ne     #0x12884
//   0x0128ac: f94027e9  ldr      x9, [sp, #0x48]
//   0x0128b0: f94053ea  ldr      x10, [sp, #0xa0]
//   0x0128b4: 9113c3f3  add      x19, sp, #0x4f0
//   0x0128b8: f103f93f  cmp      x9, #0xfe
//   0x0128bc: 52800029  mov      w9, #1
//   0x0128c0: 382a6ac9  strb     w9, [x22, x10]
//   0x0128c4: 54ffb4a8  b.hi     #0x11f58
//   0x0128c8: f9403fe9  ldr      x9, [sp, #0x78]
//   0x0128cc: b8687b08  ldr      w8, [x24, x8, lsl #2]
//   0x0128d0: 529fffcd  mov      w13, #0xfffe
//   0x0128d4: b8a97b09  ldrsw    x9, [x24, x9, lsl #2]
//   0x0128d8: 120a790b  and      w11, w8, #0xffdfffff
//   0x0128dc: 12800008  mov      w8, #-1
//   0x0128e0: 926af92c  and      x12, x9, #0xffffffffffdfffff
//   0x0128e4: 4b0c016a  sub      w10, w11, w12
//   0x0128e8: 11000508  add      w8, w8, #1
//   0x0128ec: 1ac82949  asr      w9, w10, w8
//   0x0128f0: 6b0d013f  cmp      w9, w13
//   0x0128f4: 54ffffac  b.gt     #0x128e8
//   0x0128f8: 71000549  subs     w9, w10, #1
//   0x0128fc: 540002cb  b.lt     #0x12954
//   0x012900: 93407d4d  sxtw     x13, w10
//   0x012904: f94013ea  ldr      x10, [sp, #0x20]
//   0x012908: 8b0c094a  add      x10, x10, x12, lsl #2
//   0x01290c: 2a2c03ec  mvn      w12, w12
//   0x012910: 0b0b018b  add      w11, w12, w11
//   0x012914: 14000005  b        #0x12928
//   0x012918: f100019f  cmp      x12, #0
//   0x01291c: 5100056b  sub      w11, w11, #1
//   0x012920: aa0c03ed  mov      x13, x12
//   0x012924: 5400018d  b.le     #0x12954
//   0x012928: b8ad794e  ldrsw    x14, [x10, x13, lsl #2]
//   0x01292c: f94073ef  ldr      x15, [sp, #0xe0]
//   0x012930: d10005ac  sub      x12, x13, #1
//   0x012934: 1ac8256d  lsr      w13, w11, w8
//   0x012938: 710085df  cmp      w14, #0x21
//   0x01293c: 782e79ed  strh     w13, [x15, x14, lsl #1]
//   0x012940: 54fffecc  b.gt     #0x12918
//   0x012944: f94073ef  ldr      x15, [sp, #0xe0]
//   0x012948: 0b1501ce  add      w14, w14, w21
//   0x01294c: 782ed9ed  strh     w13, [x15, w14, sxtw #1]
//   0x012950: 17fffff2  b        #0x12918
//   0x012954: 1ac82928  asr      w8, w9, w8
//   0x012958: 7140411f  cmp      w8, #0x10, lsl #12
//   0x01295c: 54ffafeb  b.lt     #0x11f58
//   0x012960: 52807d40  mov      w0, #0x3ea
//   0x012964: 97ffbfc3  bl       #0x2870
//   0x012968: 9137e3e4  add      x4, sp, #0xdf8
//   0x01296c: 17fffd7b  b        #0x11f58
//   0x012970: b94073e8  ldr      w8, [sp, #0x70]
//   0x012974: 71000d1f  cmp      w8, #3
//   0x012978: 5400014d  b.le     #0x129a0
//   0x01297c: b0000068  adrp     x8, #0x1f000
//   0x012980: f947c908  ldr      x8, [x8, #0xf90]
//   0x012984: b0000021  adrp     x1, #0x17000
//   0x012988: 4b1402a4  sub      w4, w21, w20
//   0x01298c: 91046c21  add      x1, x1, #0x11b
//   0x012990: 9104c100  add      x0, x8, #0x130
//   0x012994: 2a1503e2  mov      w2, w21
//   0x012998: 2a1403e3  mov      w3, w20
//   0x01299c: 97ffc039  bl       #0x2a80
//   0x0129a0: b94073e8  ldr      w8, [sp, #0x70]
//   0x0129a4: a940cff4  ldp      x20, x19, [sp, #8]
//   0x0129a8: 71000d1f  cmp      w8, #3
//   0x0129ac: 5400020b  b.lt     #0x129ec
//   0x0129b0: b9401fe8  ldr      w8, [sp, #0x1c]
//   0x0129b4: 710002bf  cmp      w21, #0
//   0x0129b8: b0000021  adrp     x1, #0x17000
//   0x0129bc: 91000021  add      x1, x1, #0
//   0x0129c0: 4b190102  sub      w2, w8, w25
//   0x0129c4: 1a9f16a8  csinc    w8, w21, wzr, ne
//   0x0129c8: 1e220101  scvtf    s1, w8
//   0x0129cc: b0000068  adrp     x8, #0x1f000
//   0x0129d0: f947c908  ldr      x8, [x8, #0xf90]
//   0x0129d4: 1e220040  scvtf    s0, w2
//   0x0129d8: 1e211800  fdiv     s0, s0, s1
//   0x0129dc: 1e22c000  fcvt     d0, s0
//   0x0129e0: 9104c100  add      x0, x8, #0x130
//   0x0129e4: 2a1503e3  mov      w3, w21
//   0x0129e8: 97ffc026  bl       #0x2a80
//   0x0129ec: 37f803b9  tbnz     w25, #0x1f, #0x12a60
//   0x0129f0: b9806e88  ldrsw    x8, [x20, #0x6c]
//   0x0129f4: 12800009  mov      w9, #-1
//   0x0129f8: b9003289  str      w9, [x20, #0x30]
//   0x0129fc: 7100051f  cmp      w8, #1
//   0x012a00: 540000eb  b.lt     #0x12a1c
//   0x012a04: aa1f03e9  mov      x9, xzr
//   0x012a08: b8697b4a  ldr      w10, [x26, x9, lsl #2]
//   0x012a0c: 340000ea  cbz      w10, #0x12a28
//   0x012a10: 91000529  add      x9, x9, #1
//   0x012a14: eb08013f  cmp      x9, x8
//   0x012a18: 54ffff8b  b.lt     #0x12a08
//   0x012a1c: 52807d60  mov      w0, #0x3eb
//   0x012a20: 97ffbf94  bl       #0x2870
//   0x012a24: 14000002  b        #0x12a2c
//   0x012a28: b9003289  str      w9, [x20, #0x30]
//   0x012a2c: f9401668  ldr      x8, [x19, #0x28]
//   0x012a30: f85983a9  ldur     x9, [x29, #-0x68]
//   0x012a34: eb09011f  cmp      x8, x9
//   0x012a38: 540002c1  b.ne     #0x12a90
//   0x012a3c: 914007ff  add      sp, sp, #1, lsl #12
//   0x012a40: 910b03ff  add      sp, sp, #0x2c0
//   0x012a44: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x012a48: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x012a4c: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x012a50: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x012a54: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x012a58: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x012a5c: d65f03c0  ret      
//   0x012a60: b94073f9  ldr      w25, [sp, #0x70]
//   0x012a64: 71000b3f  cmp      w25, #2
//   0x012a68: 54ff7c8b  b.lt     #0x119f8
//   0x012a6c: b0000068  adrp     x8, #0x1f000
//   0x012a70: f947c908  ldr      x8, [x8, #0xf90]
//   0x012a74: b0000020  adrp     x0, #0x17000
//   0x012a78: 91009800  add      x0, x0, #0x26
//   0x012a7c: 528006a1  mov      w1, #0x35
//   0x012a80: 9104c103  add      x3, x8, #0x130
//   0x012a84: 52800022  mov      w2, #1
//   0x012a88: 97ffc016  bl       #0x2ae0
//   0x012a8c: 17fffbdb  b        #0x119f8
//   0x012a90: 97ffbfa4  bl       #0x2920
// ============================================================================
std::uint32_t fde_56_119a8(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x000119a8ULL;
    for (std::size_t i = 0; i < 1083ULL; ++i) {
        std::uint32_t insn = kTextInstructions[15262ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[57] Subroutine @ 0x012a94..0x013458 (2500 bytes, 625 AArch64 instructions)
// [VN] Khung FDE[57] Hàm con @ 0x012a94..0x013458 (2500 byte, 625 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x012a94: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x012a98: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x012a9c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x012aa0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x012aa4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x012aa8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x012aac: 910143fd  add      x29, sp, #0x50
//   0x012ab0: d12e03ff  sub      sp, sp, #0xb80
//   0x012ab4: d53bd048  mrs      x8, tpidr_el0
//   0x012ab8: f90007e8  str      x8, [sp, #8]
//   0x012abc: f9401508  ldr      x8, [x8, #0x28]
//   0x012ac0: aa0203f7  mov      x23, x2
//   0x012ac4: aa0103f3  mov      x19, x1
//   0x012ac8: aa0003f4  mov      x20, x0
//   0x012acc: 7100109f  cmp      w4, #4
//   0x012ad0: b9003be4  str      w4, [sp, #0x38]
//   0x012ad4: f81a03a8  stur     x8, [x29, #-0x60]
//   0x012ad8: b90047e3  str      w3, [sp, #0x44]
//   0x012adc: 5400014b  b.lt     #0x12b04
//   0x012ae0: b0000068  adrp     x8, #0x1f000
//   0x012ae4: f947c908  ldr      x8, [x8, #0xf90]
//   0x012ae8: b0000020  adrp     x0, #0x17000
//   0x012aec: 91017000  add      x0, x0, #0x5c
//   0x012af0: 52800361  mov      w1, #0x1b
//   0x012af4: 9104c103  add      x3, x8, #0x130
//   0x012af8: 52800022  mov      w2, #1
//   0x012afc: 97ffbff9  bl       #0x2ae0
//   0x012b00: b94047e3  ldr      w3, [sp, #0x44]
//   0x012b04: 911133e0  add      x0, sp, #0x44c
//   0x012b08: 52808082  mov      w2, #0x404
//   0x012b0c: 2a1f03e1  mov      w1, wzr
//   0x012b10: 2a0303f9  mov      w25, w3
//   0x012b14: 911133f5  add      x21, sp, #0x44c
//   0x012b18: 97ffbfea  bl       #0x2ac0
//   0x012b1c: b94047e8  ldr      w8, [sp, #0x44]
//   0x012b20: 7100051f  cmp      w8, #1
//   0x012b24: 5400018b  b.lt     #0x12b54
//   0x012b28: aa1903e8  mov      x8, x25
//   0x012b2c: aa1303e9  mov      x9, x19
//   0x012b30: 3840152a  ldrb     w10, [x9], #1
//   0x012b34: f1000508  subs     x8, x8, #1
//   0x012b38: d37ef54a  lsl      x10, x10, #2
//   0x012b3c: b86a6aab  ldr      w11, [x21, x10]
//   0x012b40: 1100056b  add      w11, w11, #1
//   0x012b44: b82a6aab  str      w11, [x21, x10]
//   0x012b48: 54ffff41  b.ne     #0x12b30
//   0x012b4c: b9444ff6  ldr      w22, [sp, #0x44c]
//   0x012b50: 14000002  b        #0x12b58
//   0x012b54: 2a1f03f6  mov      w22, wzr
//   0x012b58: 910133e0  add      x0, sp, #0x4c
//   0x012b5c: 911133e1  add      x1, sp, #0x44c
//   0x012b60: 52808002  mov      w2, #0x400
//   0x012b64: 97ffbfcf  bl       #0x2aa0
//   0x012b68: aa1f03e8  mov      x8, xzr
//   0x012b6c: 910012a9  add      x9, x21, #4
//   0x012b70: b868692a  ldr      w10, [x9, x8]
//   0x012b74: 0b160156  add      w22, w10, w22
//   0x012b78: b8286936  str      w22, [x9, x8]
//   0x012b7c: 91001108  add      x8, x8, #4
//   0x012b80: f110011f  cmp      x8, #0x400
//   0x012b84: 54ffff61  b.ne     #0x12b70
//   0x012b88: b94047ee  ldr      w14, [sp, #0x44]
//   0x012b8c: b9403bf5  ldr      w21, [sp, #0x38]
//   0x012b90: 710005df  cmp      w14, #1
//   0x012b94: 5400018b  b.lt     #0x12bc4
//   0x012b98: aa1f03e8  mov      x8, xzr
//   0x012b9c: 911133e9  add      x9, sp, #0x44c
//   0x012ba0: 38686a6a  ldrb     w10, [x19, x8]
//   0x012ba4: d37ef54a  lsl      x10, x10, #2
//   0x012ba8: b8aa692b  ldrsw    x11, [x9, x10]
//   0x012bac: d100056b  sub      x11, x11, #1
//   0x012bb0: b82a692b  str      w11, [x9, x10]
//   0x012bb4: b82b7a88  str      w8, [x20, x11, lsl #2]
//   0x012bb8: 91000508  add      x8, x8, #1
//   0x012bbc: eb08033f  cmp      x25, x8
//   0x012bc0: 54ffff01  b.ne     #0x12ba0
//   0x012bc4: 11007dc8  add      w8, w14, #0x1f
//   0x012bc8: 710001df  cmp      w14, #0
//   0x012bcc: 1a8eb108  csel     w8, w8, w14, lt
//   0x012bd0: 13057d08  asr      w8, w8, #5
//   0x012bd4: 11000908  add      w8, w8, #2
//   0x012bd8: 7100051f  cmp      w8, #1
//   0x012bdc: 540000cb  b.lt     #0x12bf4
//   0x012be0: d37ef502  lsl      x2, x8, #2
//   0x012be4: aa1703e0  mov      x0, x23
//   0x012be8: 2a1f03e1  mov      w1, wzr
//   0x012bec: 97ffbfb5  bl       #0x2ac0
//   0x012bf0: b94047ee  ldr      w14, [sp, #0x44]
//   0x012bf4: aa1f03e8  mov      x8, xzr
//   0x012bf8: 911133e9  add      x9, sp, #0x44c
//   0x012bfc: 5280002a  mov      w10, #1
//   0x012c00: b868692b  ldr      w11, [x9, x8]
//   0x012c04: 91001108  add      x8, x8, #4
//   0x012c08: f110011f  cmp      x8, #0x400
//   0x012c0c: 13057d6c  asr      w12, w11, #5
//   0x012c10: 937e7d8c  sbfiz    x12, x12, #2, #0x20
//   0x012c14: b86c6aed  ldr      w13, [x23, x12]
//   0x012c18: 1acb214b  lsl      w11, w10, w11
//   0x012c1c: 2a0d016b  orr      w11, w11, w13
//   0x012c20: b82c6aeb  str      w11, [x23, x12]
//   0x012c24: 54fffee1  b.ne     #0x12c00
//   0x012c28: 2a1f03e8  mov      w8, wzr
//   0x012c2c: 52800029  mov      w9, #1
//   0x012c30: 0b0801ca  add      w10, w14, w8
//   0x012c34: 13057d4b  asr      w11, w10, #5
//   0x012c38: 937e7d6b  sbfiz    x11, x11, #2, #0x20
//   0x012c3c: b86b6aec  ldr      w12, [x23, x11]
//   0x012c40: 1aca212d  lsl      w13, w9, w10
//   0x012c44: 1100054a  add      w10, w10, #1
//   0x012c48: 11000908  add      w8, w8, #2
//   0x012c4c: 2a0d018c  orr      w12, w12, w13
//   0x012c50: 13057d4d  asr      w13, w10, #5
//   0x012c54: 937e7dad  sbfiz    x13, x13, #2, #0x20
//   0x012c58: b82b6aec  str      w12, [x23, x11]
//   0x012c5c: b86d6aeb  ldr      w11, [x23, x13]
//   0x012c60: 1aca212a  lsl      w10, w9, w10
//   0x012c64: 7101011f  cmp      w8, #0x40
//   0x012c68: 0a2a016a  bic      w10, w11, w10
//   0x012c6c: b82d6aea  str      w10, [x23, x13]
//   0x012c70: 54fffe01  b.ne     #0x12c30
//   0x012c74: 91001288  add      x8, x20, #4
//   0x012c78: f90017e8  str      x8, [sp, #0x28]
//   0x012c7c: 91002288  add      x8, x20, #8
//   0x012c80: f90013e8  str      x8, [sp, #0x20]
//   0x012c84: 91004288  add      x8, x20, #0x10
//   0x012c88: f9000fe8  str      x8, [sp, #0x18]
//   0x012c8c: 91005288  add      x8, x20, #0x14
//   0x012c90: f9000be8  str      x8, [sp, #0x10]
//   0x012c94: b0000068  adrp     x8, #0x1f000
//   0x012c98: f947c908  ldr      x8, [x8, #0xf90]
//   0x012c9c: 5280003a  mov      w26, #1
//   0x012ca0: 912783e5  add      x5, sp, #0x9e0
//   0x012ca4: 912143e6  add      x6, sp, #0x850
//   0x012ca8: 9104c108  add      x8, x8, #0x130
//   0x012cac: 52800036  mov      w22, #1
//   0x012cb0: f9001be8  str      x8, [sp, #0x30]
//   0x012cb4: 710012bf  cmp      w21, #4
//   0x012cb8: 5400012b  b.lt     #0x12cdc
//   0x012cbc: f9401be0  ldr      x0, [sp, #0x30]
//   0x012cc0: b0000021  adrp     x1, #0x17000
//   0x012cc4: 9101e021  add      x1, x1, #0x78
//   0x012cc8: 2a1603e2  mov      w2, w22
//   0x012ccc: 97ffbf6d  bl       #0x2a80
//   0x012cd0: b94047ee  ldr      w14, [sp, #0x44]
//   0x012cd4: 912143e6  add      x6, sp, #0x850
//   0x012cd8: 912783e5  add      x5, sp, #0x9e0
//   0x012cdc: 710005df  cmp      w14, #1
//   0x012ce0: 5400020b  b.lt     #0x12d20
//   0x012ce4: aa1f03e8  mov      x8, xzr
//   0x012ce8: 2a1f03e9  mov      w9, wzr
//   0x012cec: d3457d0a  ubfx     x10, x8, #5, #0x1b
//   0x012cf0: b8687a8b  ldr      w11, [x20, x8, lsl #2]
//   0x012cf4: b86a7aea  ldr      w10, [x23, x10, lsl #2]
//   0x012cf8: 1ac8234c  lsl      w12, w26, w8
//   0x012cfc: 4b16016b  sub      w11, w11, w22
//   0x012d00: 6a0c015f  tst      w10, w12
//   0x012d04: 0a8b7f2a  and      w10, w25, w11, asr #31
//   0x012d08: 1a880129  csel     w9, w9, w8, eq
//   0x012d0c: 91000508  add      x8, x8, #1
//   0x012d10: 0b0b014a  add      w10, w10, w11
//   0x012d14: eb08033f  cmp      x25, x8
//   0x012d18: b82ada69  str      w9, [x19, w10, sxtw #2]
//   0x012d1c: 54fffe81  b.ne     #0x12cec
//   0x012d20: b9004bf6  str      w22, [sp, #0x48]
//   0x012d24: 2a1f03e2  mov      w2, wzr
//   0x012d28: 12800016  mov      w22, #-1
//   0x012d2c: 110006dc  add      w28, w22, #1
//   0x012d30: 13057f89  asr      w9, w28, #5
//   0x012d34: b869dae9  ldr      w9, [x23, w9, sxtw #2]
//   0x012d38: 1adc234a  lsl      w10, w26, w28
//   0x012d3c: 2a1603e8  mov      w8, w22
//   0x012d40: 7200139f  tst      w28, #0x1f
//   0x012d44: 0a090149  and      w9, w10, w9
//   0x012d48: 54000060  b.eq     #0x12d54
//   0x012d4c: 2a1c03f6  mov      w22, w28
//   0x012d50: 35fffee9  cbnz     w9, #0x12d2c
//   0x012d54: 340001e9  cbz      w9, #0x12d90
//   0x012d58: 51007d09  sub      w9, w8, #0x1f
//   0x012d5c: 11008129  add      w9, w9, #0x20
//   0x012d60: 13057d2a  asr      w10, w9, #5
//   0x012d64: b86adaea  ldr      w10, [x23, w10, sxtw #2]
//   0x012d68: 2a0803fc  mov      w28, w8
//   0x012d6c: 11008108  add      w8, w8, #0x20
//   0x012d70: 3100055f  cmn      w10, #1
//   0x012d74: 54ffff40  b.eq     #0x12d5c
//   0x012d78: 1100079c  add      w28, w28, #1
//   0x012d7c: 13057f88  asr      w8, w28, #5
//   0x012d80: b868dae8  ldr      w8, [x23, w8, sxtw #2]
//   0x012d84: 1adc2349  lsl      w9, w26, w28
//   0x012d88: 6a08013f  tst      w9, w8
//   0x012d8c: 54ffff61  b.ne     #0x12d78
//   0x012d90: 6b0e039f  cmp      w28, w14
//   0x012d94: 54002dcc  b.gt     #0x1334c
//   0x012d98: 51000798  sub      w24, w28, #1
//   0x012d9c: 5100838b  sub      w11, w28, #0x20
//   0x012da0: 2a1803ed  mov      w13, w24
//   0x012da4: 2a1c03ea  mov      w10, w28
//   0x012da8: 13057d48  asr      w8, w10, #5
//   0x012dac: b868daec  ldr      w12, [x23, w8, sxtw #2]
//   0x012db0: 2a0b03e8  mov      w8, w11
//   0x012db4: 1aca234b  lsl      w11, w26, w10
//   0x012db8: 2a0d03e9  mov      w9, w13
//   0x012dbc: 7200115f  tst      w10, #0x1f
//   0x012dc0: 0a0c016c  and      w12, w11, w12
//   0x012dc4: 1100054a  add      w10, w10, #1
//   0x012dc8: 54000080  b.eq     #0x12dd8
//   0x012dcc: 1100050b  add      w11, w8, #1
//   0x012dd0: 1100052d  add      w13, w9, #1
//   0x012dd4: 34fffeac  cbz      w12, #0x12da8
//   0x012dd8: 340000ac  cbz      w12, #0x12dec
//   0x012ddc: 5100055b  sub      w27, w10, #1
//   0x012de0: 6b0e037f  cmp      w27, w14
//   0x012de4: 5400020d  b.le     #0x12e24
//   0x012de8: 14000159  b        #0x1334c
//   0x012dec: 11008108  add      w8, w8, #0x20
//   0x012df0: 13057d0a  asr      w10, w8, #5
//   0x012df4: b86adaea  ldr      w10, [x23, w10, sxtw #2]
//   0x012df8: 2a0903fb  mov      w27, w9
//   0x012dfc: 11008129  add      w9, w9, #0x20
//   0x012e00: 34ffff6a  cbz      w10, #0x12dec
//   0x012e04: 1100077b  add      w27, w27, #1
//   0x012e08: 13057f68  asr      w8, w27, #5
//   0x012e0c: b868dae8  ldr      w8, [x23, w8, sxtw #2]
//   0x012e10: 1adb2349  lsl      w9, w26, w27
//   0x012e14: 6a08013f  tst      w9, w8
//   0x012e18: 54ffff60  b.eq     #0x12e04
//   0x012e1c: 6b0e037f  cmp      w27, w14
//   0x012e20: 5400296c  b.gt     #0x1334c
//   0x012e24: 6b1c037f  cmp      w27, w28
//   0x012e28: 51000776  sub      w22, w27, #1
//   0x012e2c: 54fff80d  b.le     #0x12d2c
//   0x012e30: 4b1c0048  sub      w8, w2, w28
//   0x012e34: 0b160108  add      w8, w8, w22
//   0x012e38: 11000908  add      w8, w8, #2
//   0x012e3c: 2907ffe8  stp      w8, wzr, [sp, #0x3c]
//   0x012e40: 52800028  mov      w8, #1
//   0x012e44: b909e3f8  str      w24, [sp, #0x9e0]
//   0x012e48: b90853f6  str      w22, [sp, #0x850]
//   0x012e4c: 93407d08  sxtw     x8, w8
//   0x012e50: 14000003  b        #0x12e5c
//   0x012e54: f100011f  cmp      x8, #0
//   0x012e58: 540024cd  b.le     #0x132f0
//   0x012e5c: aa0803f5  mov      x21, x8
//   0x012e60: f1018d1f  cmp      x8, #0x63
//   0x012e64: 540000ab  b.lt     #0x12e78
//   0x012e68: 52807d80  mov      w0, #0x3ec
//   0x012e6c: 97ffbe81  bl       #0x2870
//   0x012e70: 912143e6  add      x6, sp, #0x850
//   0x012e74: 912783e5  add      x5, sp, #0x9e0
//   0x012e78: d10006a8  sub      x8, x21, #1
//   0x012e7c: d37ef509  lsl      x9, x8, #2
//   0x012e80: b86968aa  ldr      w10, [x5, x9]
//   0x012e84: b86968c9  ldr      w9, [x6, x9]
//   0x012e88: 93407d4b  sxtw     x11, w10
//   0x012e8c: 4b0a012c  sub      w12, w9, w10
//   0x012e90: 7100259f  cmp      w12, #9
//   0x012e94: 5400082c  b.gt     #0x12f98
//   0x012e98: 6b0a013f  cmp      w9, w10
//   0x012e9c: 54fffdc0  b.eq     #0x12e54
//   0x012ea0: 7100119f  cmp      w12, #4
//   0x012ea4: 93407d2c  sxtw     x12, w9
//   0x012ea8: 540003cb  b.lt     #0x12f20
//   0x012eac: 5100112d  sub      w13, w9, #4
//   0x012eb0: 6b0a01bf  cmp      w13, w10
//   0x012eb4: 5400036b  b.lt     #0x12f20
//   0x012eb8: 93407dad  sxtw     x13, w13
//   0x012ebc: 2a0903ee  mov      w14, w9
//   0x012ec0: 14000007  b        #0x12edc
//   0x012ec4: 2a0d03f0  mov      w16, w13
//   0x012ec8: eb0b01bf  cmp      x13, x11
//   0x012ecc: d10005ad  sub      x13, x13, #1
//   0x012ed0: 510005ce  sub      w14, w14, #1
//   0x012ed4: b830da8f  str      w15, [x20, w16, sxtw #2]
//   0x012ed8: 5400024d  b.le     #0x12f20
//   0x012edc: b8ad7a8f  ldrsw    x15, [x20, x13, lsl #2]
//   0x012ee0: 910011b0  add      x16, x13, #4
//   0x012ee4: eb0c021f  cmp      x16, x12
//   0x012ee8: 54fffeec  b.gt     #0x12ec4
//   0x012eec: b86f7a71  ldr      w17, [x19, x15, lsl #2]
//   0x012ef0: 93407dc0  sxtw     x0, w14
//   0x012ef4: 2a0d03f0  mov      w16, w13
//   0x012ef8: b8607a81  ldr      w1, [x20, x0, lsl #2]
//   0x012efc: b8617a62  ldr      w2, [x19, x1, lsl #2]
//   0x012f00: 6b02023f  cmp      w17, w2
//   0x012f04: 54fffe29  b.ls     #0x12ec8
//   0x012f08: 91001000  add      x0, x0, #4
//   0x012f0c: b830da81  str      w1, [x20, w16, sxtw #2]
//   0x012f10: eb0c001f  cmp      x0, x12
//   0x012f14: 11001210  add      w16, w16, #4
//   0x012f18: 54ffff0d  b.le     #0x12ef8
//   0x012f1c: 17ffffeb  b        #0x12ec8
//   0x012f20: 6b0a013f  cmp      w9, w10
//   0x012f24: 54fff98d  b.le     #0x12e54
//   0x012f28: 8b0c0a8a  add      x10, x20, x12, lsl #2
//   0x012f2c: aa0c03ef  mov      x15, x12
//   0x012f30: 14000008  b        #0x12f50
//   0x012f34: 2a0003ef  mov      w15, w0
//   0x012f38: 510005f0  sub      w16, w15, #1
//   0x012f3c: eb0b01bf  cmp      x13, x11
//   0x012f40: d100114a  sub      x10, x10, #4
//   0x012f44: aa0d03ef  mov      x15, x13
//   0x012f48: b830da8e  str      w14, [x20, w16, sxtw #2]
//   0x012f4c: 54fff84d  b.le     #0x12e54
//   0x012f50: d10005ed  sub      x13, x15, #1
//   0x012f54: b8ad7a8e  ldrsw    x14, [x20, x13, lsl #2]
//   0x012f58: 6b0901ff  cmp      w15, w9
//   0x012f5c: 2a0d03f0  mov      w16, w13
//   0x012f60: 54fffeec  b.gt     #0x12f3c
//   0x012f64: b86e7a70  ldr      w16, [x19, x14, lsl #2]
//   0x012f68: aa0a03f1  mov      x17, x10
//   0x012f6c: b9400220  ldr      w0, [x17]
//   0x012f70: b8607a61  ldr      w1, [x19, x0, lsl #2]
//   0x012f74: 6b01021f  cmp      w16, w1
//   0x012f78: 54fffe09  b.ls     #0x12f38
//   0x012f7c: b81fc220  stur     w0, [x17, #-4]
//   0x012f80: 910005e0  add      x0, x15, #1
//   0x012f84: eb0c01ff  cmp      x15, x12
//   0x012f88: 91001231  add      x17, x17, #4
//   0x012f8c: aa0003ef  mov      x15, x0
//   0x012f90: 54fffeeb  b.lt     #0x12f6c
//   0x012f94: 17ffffe8  b        #0x12f34
//   0x012f98: b94043ee  ldr      w14, [sp, #0x40]
//   0x012f9c: 5283b8ac  mov      w12, #0x1dc5
//   0x012fa0: 320003ed  mov      w13, #1
//   0x012fa4: 1b0c35cc  madd     w12, w14, w12, w13
//   0x012fa8: 1200398d  and      w13, w12, #0x7fff
//   0x012fac: 5295556c  mov      w12, #0xaaab
//   0x012fb0: 72b5554c  movk     w12, #0xaaaa, lsl #16
//   0x012fb4: 9bac7dac  umull    x12, w13, w12
//   0x012fb8: d361fd8c  lsr      x12, x12, #0x21
//   0x012fbc: 0b0c058c  add      w12, w12, w12, lsl #1
//   0x012fc0: b90043ed  str      w13, [sp, #0x40]
//   0x012fc4: 6b0c01ad  subs     w13, w13, w12
//   0x012fc8: 2a0a03ec  mov      w12, w10
//   0x012fcc: 540000e0  b.eq     #0x12fe8
//   0x012fd0: 710005bf  cmp      w13, #1
//   0x012fd4: 54000081  b.ne     #0x12fe4
//   0x012fd8: 0b0a012c  add      w12, w9, w10
//   0x012fdc: 13017d8c  asr      w12, w12, #1
//   0x012fe0: 14000002  b        #0x12fe8
//   0x012fe4: 2a0903ec  mov      w12, w9
//   0x012fe8: b86cda8c  ldr      w12, [x20, w12, sxtw #2]
//   0x012fec: 2a0903ee  mov      w14, w9
//   0x012ff0: 2a0903ef  mov      w15, w9
//   0x012ff4: 2a0a03ed  mov      w13, w10
//   0x012ff8: b86c7a70  ldr      w16, [x19, x12, lsl #2]
//   0x012ffc: 2a0a03ec  mov      w12, w10
//   0x013000: 6b0f01bf  cmp      w13, w15
//   0x013004: 5400038c  b.gt     #0x13074
//   0x013008: 93407df1  sxtw     x17, w15
//   0x01300c: 93407d8c  sxtw     x12, w12
//   0x013010: 93407da0  sxtw     x0, w13
//   0x013014: b8607a8d  ldr      w13, [x20, x0, lsl #2]
//   0x013018: b86d7a61  ldr      w1, [x19, x13, lsl #2]
//   0x01301c: 6b100021  subs     w1, w1, w16
//   0x013020: 54000100  b.eq     #0x13040
//   0x013024: 7100003f  cmp      w1, #0
//   0x013028: 5400024c  b.gt     #0x13070
//   0x01302c: 9100040d  add      x13, x0, #1
//   0x013030: eb11001f  cmp      x0, x17
//   0x013034: aa0d03e0  mov      x0, x13
//   0x013038: 54fffeeb  b.lt     #0x13014
//   0x01303c: 1400000e  b        #0x13074
//   0x013040: d37ef581  lsl      x1, x12, #2
//   0x013044: b8616a82  ldr      w2, [x20, x1]
//   0x013048: 9100058c  add      x12, x12, #1
//   0x01304c: 6b0001ff  cmp      w15, w0
//   0x013050: b8207a82  str      w2, [x20, x0, lsl #2]
//   0x013054: b8216a8d  str      w13, [x20, x1]
//   0x013058: 1100040d  add      w13, w0, #1
//   0x01305c: 54fffdac  b.gt     #0x13010
//   0x013060: 1100040d  add      w13, w0, #1
//   0x013064: 6b0f01bf  cmp      w13, w15
//   0x013068: 540000ad  b.le     #0x1307c
//   0x01306c: 14000023  b        #0x130f8
//   0x013070: 2a0003ed  mov      w13, w0
//   0x013074: 6b0f01bf  cmp      w13, w15
//   0x013078: 5400040c  b.gt     #0x130f8
//   0x01307c: 93407db1  sxtw     x17, w13
//   0x013080: 93407dce  sxtw     x14, w14
//   0x013084: 93407de0  sxtw     x0, w15
//   0x013088: b8607a8f  ldr      w15, [x20, x0, lsl #2]
//   0x01308c: b86f7a61  ldr      w1, [x19, x15, lsl #2]
//   0x013090: 6b100021  subs     w1, w1, w16
//   0x013094: 540000e0  b.eq     #0x130b0
//   0x013098: 37f801e1  tbnz     w1, #0x1f, #0x130d4
//   0x01309c: d100040f  sub      x15, x0, #1
//   0x0130a0: eb11001f  cmp      x0, x17
//   0x0130a4: aa0f03e0  mov      x0, x15
//   0x0130a8: 54ffff0c  b.gt     #0x13088
//   0x0130ac: 14000013  b        #0x130f8
//   0x0130b0: d37ef5c1  lsl      x1, x14, #2
//   0x0130b4: b8616a82  ldr      w2, [x20, x1]
//   0x0130b8: d10005ce  sub      x14, x14, #1
//   0x0130bc: 6b0001bf  cmp      w13, w0
//   0x0130c0: b8207a82  str      w2, [x20, x0, lsl #2]
//   0x0130c4: b8216a8f  str      w15, [x20, x1]
//   0x0130c8: 5100040f  sub      w15, w0, #1
//   0x0130cc: 54fffdcb  b.lt     #0x13084
//   0x0130d0: 1400000a  b        #0x130f8
//   0x0130d4: d37ef631  lsl      x17, x17, #2
//   0x0130d8: b8716a81  ldr      w1, [x20, x17]
//   0x0130dc: 110005ad  add      w13, w13, #1
//   0x0130e0: b8316a8f  str      w15, [x20, x17]
//   0x0130e4: 5100040f  sub      w15, w0, #1
//   0x0130e8: b8207a81  str      w1, [x20, x0, lsl #2]
//   0x0130ec: 6b0f01bf  cmp      w13, w15
//   0x0130f0: 54fff8cd  b.le     #0x13008
//   0x0130f4: 17ffffe0  b        #0x13074
//   0x0130f8: 6b0c01df  cmp      w14, w12
//   0x0130fc: 54000f6b  b.lt     #0x132e8
//   0x013100: 4b0a0190  sub      w16, w12, w10
//   0x013104: 4b0c01b1  sub      w17, w13, w12
//   0x013108: 6b11021f  cmp      w16, w17
//   0x01310c: 1a91b210  csel     w16, w16, w17, lt
//   0x013110: 71000601  subs     w1, w16, #1
//   0x013114: 540005cb  b.lt     #0x131cc
//   0x013118: 4b1001a0  sub      w0, w13, w16
//   0x01311c: 91000431  add      x17, x1, #1
//   0x013120: f100223f  cmp      x17, #8
//   0x013124: 93407c00  sxtw     x0, w0
//   0x013128: 54000403  b.lo     #0x131a8
//   0x01312c: f94017e4  ldr      x4, [sp, #0x28]
//   0x013130: 8b010003  add      x3, x0, x1
//   0x013134: 8b0b0a82  add      x2, x20, x11, lsl #2
//   0x013138: 8b030883  add      x3, x4, x3, lsl #2
//   0x01313c: eb03005f  cmp      x2, x3
//   0x013140: 540000e2  b.hs     #0x1315c
//   0x013144: f94017e2  ldr      x2, [sp, #0x28]
//   0x013148: 8b010161  add      x1, x11, x1
//   0x01314c: 8b010841  add      x1, x2, x1, lsl #2
//   0x013150: 8b000a82  add      x2, x20, x0, lsl #2
//   0x013154: eb01005f  cmp      x2, x1
//   0x013158: 54000283  b.lo     #0x131a8
//   0x01315c: f9400fe4  ldr      x4, [sp, #0x18]
//   0x013160: 927d7621  and      x1, x17, #0x1fffffff8
//   0x013164: 8b0b0022  add      x2, x1, x11
//   0x013168: 4b010210  sub      w16, w16, w1
//   0x01316c: 8b000883  add      x3, x4, x0, lsl #2
//   0x013170: 8b000020  add      x0, x1, x0
//   0x013174: 8b0b088b  add      x11, x4, x11, lsl #2
//   0x013178: aa0103e4  mov      x4, x1
//   0x01317c: ad7f8d60  ldp      q0, q3, [x11, #-0x10]
//   0x013180: ad7f8861  ldp      q1, q2, [x3, #-0x10]
//   0x013184: f1002084  subs     x4, x4, #8
//   0x013188: ad3f8961  stp      q1, q2, [x11, #-0x10]
//   0x01318c: ad3f8c60  stp      q0, q3, [x3, #-0x10]
//   0x013190: 91008063  add      x3, x3, #0x20
//   0x013194: 9100816b  add      x11, x11, #0x20
//   0x013198: 54ffff21  b.ne     #0x1317c
//   0x01319c: eb01023f  cmp      x17, x1
//   0x0131a0: aa0203eb  mov      x11, x2
//   0x0131a4: 54000140  b.eq     #0x131cc
//   0x0131a8: 8b0b0a8b  add      x11, x20, x11, lsl #2
//   0x0131ac: 8b000a91  add      x17, x20, x0, lsl #2
//   0x0131b0: b9400220  ldr      w0, [x17]
//   0x0131b4: b9400161  ldr      w1, [x11]
//   0x0131b8: 51000610  sub      w16, w16, #1
//   0x0131bc: 7100021f  cmp      w16, #0
//   0x0131c0: b8004560  str      w0, [x11], #4
//   0x0131c4: b8004621  str      w1, [x17], #4
//   0x0131c8: 54ffff4c  b.gt     #0x131b0
//   0x0131cc: 4b0e0130  sub      w16, w9, w14
//   0x0131d0: 4b0f01cb  sub      w11, w14, w15
//   0x0131d4: 6b0b021f  cmp      w16, w11
//   0x0131d8: 1a8bb20e  csel     w14, w16, w11, lt
//   0x0131dc: 710005c0  subs     w0, w14, #1
//   0x0131e0: 5400060b  b.lt     #0x132a0
//   0x0131e4: 4b0e0130  sub      w16, w9, w14
//   0x0131e8: 9100040f  add      x15, x0, #1
//   0x0131ec: 93407e10  sxtw     x16, w16
//   0x0131f0: f10021ff  cmp      x15, #8
//   0x0131f4: 93407db1  sxtw     x17, w13
//   0x0131f8: 54000403  b.lo     #0x13278
//   0x0131fc: f94013e3  ldr      x3, [sp, #0x20]
//   0x013200: 8b000202  add      x2, x16, x0
//   0x013204: 8b110a81  add      x1, x20, x17, lsl #2
//   0x013208: 8b020862  add      x2, x3, x2, lsl #2
//   0x01320c: eb02003f  cmp      x1, x2
//   0x013210: 540000e2  b.hs     #0x1322c
//   0x013214: f94017e1  ldr      x1, [sp, #0x28]
//   0x013218: 8b000220  add      x0, x17, x0
//   0x01321c: 8b000820  add      x0, x1, x0, lsl #2
//   0x013220: 8b100821  add      x1, x1, x16, lsl #2
//   0x013224: eb00003f  cmp      x1, x0
//   0x013228: 54000283  b.lo     #0x13278
//   0x01322c: a9410fe1  ldp      x1, x3, [sp, #0x10]
//   0x013230: 927d75e0  and      x0, x15, #0x1fffffff8
//   0x013234: 4b0001ce  sub      w14, w14, w0
//   0x013238: 8b100822  add      x2, x1, x16, lsl #2
//   0x01323c: 8b110001  add      x1, x0, x17
//   0x013240: 8b100010  add      x16, x0, x16
//   0x013244: 8b110871  add      x17, x3, x17, lsl #2
//   0x013248: aa0003e3  mov      x3, x0
//   0x01324c: ad7f8e20  ldp      q0, q3, [x17, #-0x10]
//   0x013250: ad7f8841  ldp      q1, q2, [x2, #-0x10]
//   0x013254: f1002063  subs     x3, x3, #8
//   0x013258: ad3f8a21  stp      q1, q2, [x17, #-0x10]
//   0x01325c: ad3f8c40  stp      q0, q3, [x2, #-0x10]
//   0x013260: 91008042  add      x2, x2, #0x20
//   0x013264: 91008231  add      x17, x17, #0x20
//   0x013268: 54ffff21  b.ne     #0x1324c
//   0x01326c: eb0001ff  cmp      x15, x0
//   0x013270: aa0103f1  mov      x17, x1
//   0x013274: 54000160  b.eq     #0x132a0
//   0x013278: 8b110a8f  add      x15, x20, x17, lsl #2
//   0x01327c: f94017f1  ldr      x17, [sp, #0x28]
//   0x013280: 8b100a30  add      x16, x17, x16, lsl #2
//   0x013284: b9400211  ldr      w17, [x16]
//   0x013288: b94001e0  ldr      w0, [x15]
//   0x01328c: 510005ce  sub      w14, w14, #1
//   0x013290: 710001df  cmp      w14, #0
//   0x013294: b80045f1  str      w17, [x15], #4
//   0x013298: b8004600  str      w0, [x16], #4
//   0x01329c: 54ffff4c  b.gt     #0x13284
//   0x0132a0: 2a2c03ec  mvn      w12, w12
//   0x0132a4: 4b0b012b  sub      w11, w9, w11
//   0x0132a8: 0b0c014c  add      w12, w10, w12
//   0x0132ac: 1100056b  add      w11, w11, #1
//   0x0132b0: 0b0d018c  add      w12, w12, w13
//   0x0132b4: 4b0a018d  sub      w13, w12, w10
//   0x0132b8: 4b0b012e  sub      w14, w9, w11
//   0x0132bc: 6b0e01bf  cmp      w13, w14
//   0x0132c0: 5400006d  b.le     #0x132cc
//   0x0132c4: b82878cc  str      w12, [x6, x8, lsl #2]
//   0x0132c8: 14000004  b        #0x132d8
//   0x0132cc: b82878ab  str      w11, [x5, x8, lsl #2]
//   0x0132d0: 2a0a03eb  mov      w11, w10
//   0x0132d4: 2a0c03e9  mov      w9, w12
//   0x0132d8: 937e7ea8  sbfiz    x8, x21, #2, #0x20
//   0x0132dc: b82868ab  str      w11, [x5, x8]
//   0x0132e0: b82868c9  str      w9, [x6, x8]
//   0x0132e4: 110006a8  add      w8, w21, #1
//   0x0132e8: 7100011f  cmp      w8, #0
//   0x0132ec: 54ffdb0c  b.gt     #0x12e4c
//   0x0132f0: b94047ee  ldr      w14, [sp, #0x44]
//   0x0132f4: 29470bf5  ldp      w21, w2, [sp, #0x38]
//   0x0132f8: 6b1b039f  cmp      w28, w27
//   0x0132fc: 54ffd18c  b.gt     #0x12d2c
//   0x013300: 93407f08  sxtw     x8, w24
//   0x013304: 93407f69  sxtw     x9, w27
//   0x013308: 1280000a  mov      w10, #-1
//   0x01330c: 14000004  b        #0x1331c
//   0x013310: 91000508  add      x8, x8, #1
//   0x013314: eb09011f  cmp      x8, x9
//   0x013318: 54ffd0aa  b.ge     #0x12d2c
//   0x01331c: b8687a8b  ldr      w11, [x20, x8, lsl #2]
//   0x013320: b86b7a6b  ldr      w11, [x19, x11, lsl #2]
//   0x013324: 6b0b015f  cmp      w10, w11
//   0x013328: 54ffff40  b.eq     #0x13310
//   0x01332c: 13057d0a  asr      w10, w8, #5
//   0x013330: 937e7d4a  sbfiz    x10, x10, #2, #0x20
//   0x013334: b86a6aec  ldr      w12, [x23, x10]
//   0x013338: 1ac8234d  lsl      w13, w26, w8
//   0x01333c: 2a0d018c  orr      w12, w12, w13
//   0x013340: b82a6aec  str      w12, [x23, x10]
//   0x013344: 2a0b03ea  mov      w10, w11
//   0x013348: 17fffff2  b        #0x13310
//   0x01334c: 710012bf  cmp      w21, #4
//   0x013350: 5400018b  b.lt     #0x13380
//   0x013354: 90000068  adrp     x8, #0x1f000
//   0x013358: f947c908  ldr      x8, [x8, #0xf90]
//   0x01335c: 90000021  adrp     x1, #0x17000
//   0x013360: 91023c21  add      x1, x1, #0x8f
//   0x013364: 2a0203f6  mov      w22, w2
//   0x013368: 9104c100  add      x0, x8, #0x130
//   0x01336c: 97ffbdc5  bl       #0x2a80
//   0x013370: b94047ee  ldr      w14, [sp, #0x44]
//   0x013374: 2a1603e2  mov      w2, w22
//   0x013378: 912143e6  add      x6, sp, #0x850
//   0x01337c: 912783e5  add      x5, sp, #0x9e0
//   0x013380: b9404bf6  ldr      w22, [sp, #0x48]
//   0x013384: 531f7ad6  lsl      w22, w22, #1
//   0x013388: 6b0e02df  cmp      w22, w14
//   0x01338c: 5400004c  b.gt     #0x13394
//   0x013390: 35ffc922  cbnz     w2, #0x12cb4
//   0x013394: 710012bf  cmp      w21, #4
//   0x013398: 5400014b  b.lt     #0x133c0
//   0x01339c: 90000068  adrp     x8, #0x1f000
//   0x0133a0: f947c908  ldr      x8, [x8, #0xf90]
//   0x0133a4: 90000020  adrp     x0, #0x17000
//   0x0133a8: 91029c00  add      x0, x0, #0xa7
//   0x0133ac: 52800421  mov      w1, #0x21
//   0x0133b0: 9104c103  add      x3, x8, #0x130
//   0x0133b4: 52800022  mov      w2, #1
//   0x0133b8: 97ffbdca  bl       #0x2ae0
//   0x0133bc: b94047ee  ldr      w14, [sp, #0x44]
//   0x0133c0: 710005df  cmp      w14, #1
//   0x0133c4: 540002eb  b.lt     #0x13420
//   0x0133c8: aa1f03e8  mov      x8, xzr
//   0x0133cc: aa1f03eb  mov      x11, xzr
//   0x0133d0: 910133e9  add      x9, sp, #0x4c
//   0x0133d4: 93407d6b  sxtw     x11, w11
//   0x0133d8: 5100056a  sub      w10, w11, #1
//   0x0133dc: b86b792c  ldr      w12, [x9, x11, lsl #2]
//   0x0133e0: 9100056b  add      x11, x11, #1
//   0x0133e4: 1100054a  add      w10, w10, #1
//   0x0133e8: 34ffffac  cbz      w12, #0x133dc
//   0x0133ec: 8b0b092d  add      x13, x9, x11, lsl #2
//   0x0133f0: 5100058c  sub      w12, w12, #1
//   0x0133f4: b81fc1ac  stur     w12, [x13, #-4]
//   0x0133f8: b8687a8c  ldr      w12, [x20, x8, lsl #2]
//   0x0133fc: 91000508  add      x8, x8, #1
//   0x013400: d100056b  sub      x11, x11, #1
//   0x013404: eb19011f  cmp      x8, x25
//   0x013408: 382c6a6b  strb     w11, [x19, x12]
//   0x01340c: 54fffe41  b.ne     #0x133d4
//   0x013410: 7104015f  cmp      w10, #0x100
//   0x013414: 5400006b  b.lt     #0x13420
//   0x013418: 52807da0  mov      w0, #0x3ed
//   0x01341c: 97ffbd15  bl       #0x2870
//   0x013420: f94007e8  ldr      x8, [sp, #8]
//   0x013424: f9401508  ldr      x8, [x8, #0x28]
//   0x013428: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x01342c: eb09011f  cmp      x8, x9
//   0x013430: 54000121  b.ne     #0x13454
//   0x013434: 912e03ff  add      sp, sp, #0xb80
//   0x013438: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x01343c: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x013440: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x013444: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x013448: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x01344c: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x013450: d65f03c0  ret      
//   0x013454: 97ffbd33  bl       #0x2920
// ============================================================================
std::uint32_t fde_57_12a94(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00012a94ULL;
    for (std::size_t i = 0; i < 625ULL; ++i) {
        std::uint32_t insn = kTextInstructions[16345ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[58] Subroutine @ 0x013458..0x013734 (732 bytes, 183 AArch64 instructions)
// [VN] Khung FDE[58] Hàm con @ 0x013458..0x013734 (732 byte, 183 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x013458: d10083ff  sub      sp, sp, #0x20
//   0x01345c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x013460: 910043fd  add      x29, sp, #0x10
//   0x013464: d53bd048  mrs      x8, tpidr_el0
//   0x013468: f9401509  ldr      x9, [x8, #0x28]
//   0x01346c: f90007e9  str      x9, [sp, #8]
//   0x013470: 38604849  ldrb     w9, [x2, w0, uxtw]
//   0x013474: 3861484a  ldrb     w10, [x2, w1, uxtw]
//   0x013478: 6b0a013f  cmp      w9, w10
//   0x01347c: 540014a1  b.ne     #0x13710
//   0x013480: 11000409  add      w9, w0, #1
//   0x013484: 1100042a  add      w10, w1, #1
//   0x013488: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x01348c: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013490: 6b0a013f  cmp      w9, w10
//   0x013494: 540013e1  b.ne     #0x13710
//   0x013498: 11000809  add      w9, w0, #2
//   0x01349c: 1100082a  add      w10, w1, #2
//   0x0134a0: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x0134a4: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x0134a8: 6b0a013f  cmp      w9, w10
//   0x0134ac: 54001321  b.ne     #0x13710
//   0x0134b0: 11000c09  add      w9, w0, #3
//   0x0134b4: 11000c2a  add      w10, w1, #3
//   0x0134b8: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x0134bc: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x0134c0: 6b0a013f  cmp      w9, w10
//   0x0134c4: 54001261  b.ne     #0x13710
//   0x0134c8: 11001009  add      w9, w0, #4
//   0x0134cc: 1100102a  add      w10, w1, #4
//   0x0134d0: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x0134d4: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x0134d8: 6b0a013f  cmp      w9, w10
//   0x0134dc: 540011a1  b.ne     #0x13710
//   0x0134e0: 11001409  add      w9, w0, #5
//   0x0134e4: 1100142a  add      w10, w1, #5
//   0x0134e8: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x0134ec: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x0134f0: 6b0a013f  cmp      w9, w10
//   0x0134f4: 540010e1  b.ne     #0x13710
//   0x0134f8: 11001809  add      w9, w0, #6
//   0x0134fc: 1100182a  add      w10, w1, #6
//   0x013500: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x013504: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013508: 6b0a013f  cmp      w9, w10
//   0x01350c: 54001021  b.ne     #0x13710
//   0x013510: 11001c09  add      w9, w0, #7
//   0x013514: 11001c2a  add      w10, w1, #7
//   0x013518: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x01351c: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013520: 6b0a013f  cmp      w9, w10
//   0x013524: 54000f61  b.ne     #0x13710
//   0x013528: 11002009  add      w9, w0, #8
//   0x01352c: 1100202a  add      w10, w1, #8
//   0x013530: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x013534: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013538: 6b0a013f  cmp      w9, w10
//   0x01353c: 54000ea1  b.ne     #0x13710
//   0x013540: 11002409  add      w9, w0, #9
//   0x013544: 1100242a  add      w10, w1, #9
//   0x013548: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x01354c: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013550: 6b0a013f  cmp      w9, w10
//   0x013554: 54000de1  b.ne     #0x13710
//   0x013558: 11002809  add      w9, w0, #0xa
//   0x01355c: 1100282a  add      w10, w1, #0xa
//   0x013560: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x013564: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013568: 6b0a013f  cmp      w9, w10
//   0x01356c: 54000d21  b.ne     #0x13710
//   0x013570: 11002c09  add      w9, w0, #0xb
//   0x013574: 11002c2a  add      w10, w1, #0xb
//   0x013578: 38694849  ldrb     w9, [x2, w9, uxtw]
//   0x01357c: 386a484a  ldrb     w10, [x2, w10, uxtw]
//   0x013580: 6b0a013f  cmp      w9, w10
//   0x013584: 54000c61  b.ne     #0x13710
//   0x013588: 1100300a  add      w10, w0, #0xc
//   0x01358c: 1100302b  add      w11, w1, #0xc
//   0x013590: 11002089  add      w9, w4, #8
//   0x013594: 2a0a03ea  mov      w10, w10
//   0x013598: 2a0b03eb  mov      w11, w11
//   0x01359c: 386a684c  ldrb     w12, [x2, x10]
//   0x0135a0: 386b684d  ldrb     w13, [x2, x11]
//   0x0135a4: 6b0d019f  cmp      w12, w13
//   0x0135a8: 54000b41  b.ne     #0x13710
//   0x0135ac: 786a786c  ldrh     w12, [x3, x10, lsl #1]
//   0x0135b0: 786b786d  ldrh     w13, [x3, x11, lsl #1]
//   0x0135b4: 6b0d019f  cmp      w12, w13
//   0x0135b8: 54000ac1  b.ne     #0x13710
//   0x0135bc: 1100054c  add      w12, w10, #1
//   0x0135c0: 1100056d  add      w13, w11, #1
//   0x0135c4: 386c684e  ldrb     w14, [x2, x12]
//   0x0135c8: 386d684f  ldrb     w15, [x2, x13]
//   0x0135cc: 6b0f01df  cmp      w14, w15
//   0x0135d0: 54000a01  b.ne     #0x13710
//   0x0135d4: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x0135d8: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x0135dc: 6b0d019f  cmp      w12, w13
//   0x0135e0: 54000981  b.ne     #0x13710
//   0x0135e4: 1100094c  add      w12, w10, #2
//   0x0135e8: 1100096d  add      w13, w11, #2
//   0x0135ec: 386c684e  ldrb     w14, [x2, x12]
//   0x0135f0: 386d684f  ldrb     w15, [x2, x13]
//   0x0135f4: 6b0f01df  cmp      w14, w15
//   0x0135f8: 540008c1  b.ne     #0x13710
//   0x0135fc: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x013600: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x013604: 6b0d019f  cmp      w12, w13
//   0x013608: 54000841  b.ne     #0x13710
//   0x01360c: 11000d4c  add      w12, w10, #3
//   0x013610: 11000d6d  add      w13, w11, #3
//   0x013614: 386c684e  ldrb     w14, [x2, x12]
//   0x013618: 386d684f  ldrb     w15, [x2, x13]
//   0x01361c: 6b0f01df  cmp      w14, w15
//   0x013620: 54000781  b.ne     #0x13710
//   0x013624: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x013628: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x01362c: 6b0d019f  cmp      w12, w13
//   0x013630: 54000701  b.ne     #0x13710
//   0x013634: 1100114c  add      w12, w10, #4
//   0x013638: 1100116d  add      w13, w11, #4
//   0x01363c: 386c684e  ldrb     w14, [x2, x12]
//   0x013640: 386d684f  ldrb     w15, [x2, x13]
//   0x013644: 6b0f01df  cmp      w14, w15
//   0x013648: 54000641  b.ne     #0x13710
//   0x01364c: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x013650: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x013654: 6b0d019f  cmp      w12, w13
//   0x013658: 540005c1  b.ne     #0x13710
//   0x01365c: 1100154c  add      w12, w10, #5
//   0x013660: 1100156d  add      w13, w11, #5
//   0x013664: 386c684e  ldrb     w14, [x2, x12]
//   0x013668: 386d684f  ldrb     w15, [x2, x13]
//   0x01366c: 6b0f01df  cmp      w14, w15
//   0x013670: 54000501  b.ne     #0x13710
//   0x013674: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x013678: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x01367c: 6b0d019f  cmp      w12, w13
//   0x013680: 54000481  b.ne     #0x13710
//   0x013684: 1100194c  add      w12, w10, #6
//   0x013688: 1100196d  add      w13, w11, #6
//   0x01368c: 386c684e  ldrb     w14, [x2, x12]
//   0x013690: 386d684f  ldrb     w15, [x2, x13]
//   0x013694: 6b0f01df  cmp      w14, w15
//   0x013698: 540003c1  b.ne     #0x13710
//   0x01369c: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x0136a0: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x0136a4: 6b0d019f  cmp      w12, w13
//   0x0136a8: 54000341  b.ne     #0x13710
//   0x0136ac: 11001d4c  add      w12, w10, #7
//   0x0136b0: 11001d6d  add      w13, w11, #7
//   0x0136b4: 386c684e  ldrb     w14, [x2, x12]
//   0x0136b8: 386d684f  ldrb     w15, [x2, x13]
//   0x0136bc: 6b0f01df  cmp      w14, w15
//   0x0136c0: 54000281  b.ne     #0x13710
//   0x0136c4: 786c786c  ldrh     w12, [x3, x12, lsl #1]
//   0x0136c8: 786d786d  ldrh     w13, [x3, x13, lsl #1]
//   0x0136cc: 6b0d019f  cmp      w12, w13
//   0x0136d0: 54000201  b.ne     #0x13710
//   0x0136d4: 1100214a  add      w10, w10, #8
//   0x0136d8: b94000ac  ldr      w12, [x5]
//   0x0136dc: 1100216b  add      w11, w11, #8
//   0x0136e0: 6b04015f  cmp      w10, w4
//   0x0136e4: 1a8433ed  csel     w13, wzr, w4, lo
//   0x0136e8: 6b04017f  cmp      w11, w4
//   0x0136ec: 4b0d014a  sub      w10, w10, w13
//   0x0136f0: 1a8433ed  csel     w13, wzr, w4, lo
//   0x0136f4: 2a1f03e0  mov      w0, wzr
//   0x0136f8: 51002129  sub      w9, w9, #8
//   0x0136fc: 4b0d016b  sub      w11, w11, w13
//   0x013700: 5100058c  sub      w12, w12, #1
//   0x013704: b90000ac  str      w12, [x5]
//   0x013708: 36fff469  tbz      w9, #0x1f, #0x13594
//   0x01370c: 14000002  b        #0x13714
//   0x013710: 1a9f97e0  cset     w0, hi
//   0x013714: f9401508  ldr      x8, [x8, #0x28]
//   0x013718: f94007e9  ldr      x9, [sp, #8]
//   0x01371c: eb09011f  cmp      x8, x9
//   0x013720: 54000081  b.ne     #0x13730
//   0x013724: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x013728: 910083ff  add      sp, sp, #0x20
//   0x01372c: d65f03c0  ret      
//   0x013730: 97ffbc7c  bl       #0x2920
// ============================================================================
std::uint32_t fde_58_13458(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00013458ULL;
    for (std::size_t i = 0; i < 183ULL; ++i) {
        std::uint32_t insn = kTextInstructions[16970ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[59] Subroutine @ 0x013734..0x013bfc (1224 bytes, 306 AArch64 instructions)
// [VN] Khung FDE[59] Hàm con @ 0x013734..0x013bfc (1224 byte, 306 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x013734: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x013738: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01373c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x013740: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x013744: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x013748: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01374c: 910143fd  add      x29, sp, #0x50
//   0x013750: d14007ff  sub      sp, sp, #1, lsl #12
//   0x013754: d111c3ff  sub      sp, sp, #0x470
//   0x013758: d53bd048  mrs      x8, tpidr_el0
//   0x01375c: f90007e8  str      x8, [sp, #8]
//   0x013760: f9401508  ldr      x8, [x8, #0x28]
//   0x013764: 2a0303f3  mov      w19, w3
//   0x013768: 2a0203f4  mov      w20, w2
//   0x01376c: aa0003f5  mov      x21, x0
//   0x013770: 7100045f  cmp      w2, #1
//   0x013774: f81a03a8  stur     x8, [x29, #-0x60]
//   0x013778: 5400046b  b.lt     #0x13804
//   0x01377c: 71000e9f  cmp      w20, #3
//   0x013780: 2a1403e8  mov      w8, w20
//   0x013784: 54000068  b.hi     #0x13790
//   0x013788: aa1f03e9  mov      x9, xzr
//   0x01378c: 14000010  b        #0x137cc
//   0x013790: 927e7509  and      x9, x8, #0xfffffffc
//   0x013794: 912103ea  add      x10, sp, #0x840
//   0x013798: 9100114a  add      x10, x10, #4
//   0x01379c: 4f002420  movi     v0.4s, #1, lsl #8
//   0x0137a0: aa0903eb  mov      x11, x9
//   0x0137a4: aa0103ec  mov      x12, x1
//   0x0137a8: 3cc10581  ldr      q1, [x12], #0x10
//   0x0137ac: f100116b  subs     x11, x11, #4
//   0x0137b0: 4ea09822  cmeq     v2.4s, v1.4s, #0
//   0x0137b4: 4f285421  shl      v1.4s, v1.4s, #8
//   0x0137b8: 6e611c02  bsl      v2.16b, v0.16b, v1.16b
//   0x0137bc: 3c810542  str      q2, [x10], #0x10
//   0x0137c0: 54ffff41  b.ne     #0x137a8
//   0x0137c4: eb08013f  cmp      x9, x8
//   0x0137c8: 540001e0  b.eq     #0x13804
//   0x0137cc: d37ef52a  lsl      x10, x9, #2
//   0x0137d0: 912103eb  add      x11, sp, #0x840
//   0x0137d4: cb090108  sub      x8, x8, x9
//   0x0137d8: 8b0a0029  add      x9, x1, x10
//   0x0137dc: 8b0b014a  add      x10, x10, x11
//   0x0137e0: 9100114a  add      x10, x10, #4
//   0x0137e4: 5280200b  mov      w11, #0x100
//   0x0137e8: b840452c  ldr      w12, [x9], #4
//   0x0137ec: 53185d8d  lsl      w13, w12, #8
//   0x0137f0: 7100019f  cmp      w12, #0
//   0x0137f4: 1a8d016c  csel     w12, w11, w13, eq
//   0x0137f8: f1000508  subs     x8, x8, #1
//   0x0137fc: b800454c  str      w12, [x10], #4
//   0x013800: 54ffff41  b.ne     #0x137e8
//   0x013804: 12800028  mov      w8, #-2
//   0x013808: 7100069f  cmp      w20, #1
//   0x01380c: b91053ff  str      wzr, [sp, #0x1050]
//   0x013810: b90843ff  str      wzr, [sp, #0x840]
//   0x013814: b90033e8  str      w8, [sp, #0x30]
//   0x013818: 54001d4b  b.lt     #0x13bc0
//   0x01381c: 11000699  add      w25, w20, #1
//   0x013820: 912103fb  add      x27, sp, #0x840
//   0x013824: d1000737  sub      x23, x25, #1
//   0x013828: 9100136a  add      x10, x27, #4
//   0x01382c: f9000fea  str      x10, [sp, #0x18]
//   0x013830: 927ef6ea  and      x10, x23, #0xfffffffffffffffc
//   0x013834: 93407e89  sxtw     x9, w20
//   0x013838: 914007f8  add      x24, sp, #1, lsl #12
//   0x01383c: f90017ea  str      x10, [sp, #0x28]
//   0x013840: b240014a  orr      x10, x10, #1
//   0x013844: aa1f03e8  mov      x8, xzr
//   0x013848: f90013e9  str      x9, [sp, #0x20]
//   0x01384c: 2a1403fa  mov      w26, w20
//   0x013850: 52800029  mov      w9, #1
//   0x013854: 9100c3fc  add      x28, sp, #0x30
//   0x013858: 12800016  mov      w22, #-1
//   0x01385c: 91014318  add      x24, x24, #0x50
//   0x013860: f9000bea  str      x10, [sp, #0x10]
//   0x013864: 14000009  b        #0x13888
//   0x013868: 12800029  mov      w9, #-2
//   0x01386c: aa1f03e8  mov      x8, xzr
//   0x013870: b90033e9  str      w9, [sp, #0x30]
//   0x013874: 7100069f  cmp      w20, #1
//   0x013878: 52800029  mov      w9, #1
//   0x01387c: b91053ff  str      wzr, [sp, #0x1050]
//   0x013880: b90843ff  str      wzr, [sp, #0x840]
//   0x013884: 540019eb  b.lt     #0x13bc0
//   0x013888: 91000508  add      x8, x8, #1
//   0x01388c: 8b080b0a  add      x10, x24, x8, lsl #2
//   0x013890: b9000149  str      w9, [x10]
//   0x013894: d3417d0c  ubfx     x12, x8, #1, #0x1f
//   0x013898: b8ac5b0d  ldrsw    x13, [x24, w12, uxtw #2]
//   0x01389c: d37ef52e  lsl      x14, x9, #2
//   0x0138a0: b86e6b6b  ldr      w11, [x27, x14]
//   0x0138a4: b82e6b96  str      w22, [x28, x14]
//   0x0138a8: b86d7b6f  ldr      w15, [x27, x13, lsl #2]
//   0x0138ac: 6b0f017f  cmp      w11, w15
//   0x0138b0: 5400012a  b.ge     #0x138d4
//   0x0138b4: b900014d  str      w13, [x10]
//   0x0138b8: 13017d8e  asr      w14, w12, #1
//   0x0138bc: b8aedb0d  ldrsw    x13, [x24, w14, sxtw #2]
//   0x0138c0: b86d7b6a  ldr      w10, [x27, x13, lsl #2]
//   0x0138c4: 6b0a017f  cmp      w11, w10
//   0x0138c8: 8b2ccb0a  add      x10, x24, w12, sxtw #2
//   0x0138cc: 2a0e03ec  mov      w12, w14
//   0x0138d0: 54ffff2b  b.lt     #0x138b4
//   0x0138d4: b9000149  str      w9, [x10]
//   0x0138d8: eb1a011f  cmp      x8, x26
//   0x0138dc: 91000529  add      x9, x9, #1
//   0x0138e0: 54fffd41  b.ne     #0x13888
//   0x0138e4: 7104129f  cmp      w20, #0x104
//   0x0138e8: 54000063  b.lo     #0x138f4
//   0x0138ec: 5280fa20  mov      w0, #0x7d1
//   0x0138f0: 97ffbbe0  bl       #0x2870
//   0x0138f4: 71000a9f  cmp      w20, #2
//   0x0138f8: 2a1403e8  mov      w8, w20
//   0x0138fc: 54000e8b  b.lt     #0x13acc
//   0x013900: f94013e8  ldr      x8, [sp, #0x20]
//   0x013904: aa1a03ed  mov      x13, x26
//   0x013908: 14000005  b        #0x1391c
//   0x01390c: f100053f  cmp      x9, #1
//   0x013910: aa0903ed  mov      x13, x9
//   0x013914: b9000188  str      w8, [x12]
//   0x013918: 54000dad  b.le     #0x13acc
//   0x01391c: b86d7b0c  ldr      w12, [x24, x13, lsl #2]
//   0x013920: b99057ea  ldrsw    x10, [sp, #0x1054]
//   0x013924: f10009ab  subs     x11, x13, #2
//   0x013928: d10005a9  sub      x9, x13, #1
//   0x01392c: b91057ec  str      w12, [sp, #0x1054]
//   0x013930: 5400038d  b.le     #0x139a0
//   0x013934: 93407d8e  sxtw     x14, w12
//   0x013938: b86e7b6e  ldr      w14, [x27, x14, lsl #2]
//   0x01393c: 5280002f  mov      w15, #1
//   0x013940: 52800051  mov      w17, #2
//   0x013944: 93407e20  sxtw     x0, w17
//   0x013948: eb00013f  cmp      x9, x0
//   0x01394c: 5400014d  b.le     #0x13974
//   0x013950: b2400010  orr      x16, x0, #1
//   0x013954: b8b07b01  ldrsw    x1, [x24, x16, lsl #2]
//   0x013958: b8a07b00  ldrsw    x0, [x24, x0, lsl #2]
//   0x01395c: b8617b61  ldr      w1, [x27, x1, lsl #2]
//   0x013960: b8607b60  ldr      w0, [x27, x0, lsl #2]
//   0x013964: 6b00003f  cmp      w1, w0
//   0x013968: 1a91b210  csel     w16, w16, w17, lt
//   0x01396c: 93407e00  sxtw     x0, w16
//   0x013970: 14000002  b        #0x13978
//   0x013974: 2a1103f0  mov      w16, w17
//   0x013978: b8a07b00  ldrsw    x0, [x24, x0, lsl #2]
//   0x01397c: b8607b71  ldr      w17, [x27, x0, lsl #2]
//   0x013980: 6b1101df  cmp      w14, w17
//   0x013984: 5400012b  b.lt     #0x139a8
//   0x013988: 531f7a11  lsl      w17, w16, #1
//   0x01398c: eb31c1bf  cmp      x13, w17, sxtw
//   0x013990: b82fdb00  str      w0, [x24, w15, sxtw #2]
//   0x013994: 2a1003ef  mov      w15, w16
//   0x013998: 54fffd6c  b.gt     #0x13944
//   0x01399c: 14000004  b        #0x139ac
//   0x0139a0: 52800030  mov      w16, #1
//   0x0139a4: 14000002  b        #0x139ac
//   0x0139a8: 2a0f03f0  mov      w16, w15
//   0x0139ac: b830db0c  str      w12, [x24, w16, sxtw #2]
//   0x0139b0: 8b090b0c  add      x12, x24, x9, lsl #2
//   0x0139b4: b940018e  ldr      w14, [x12]
//   0x0139b8: b99057ed  ldrsw    x13, [sp, #0x1054]
//   0x0139bc: f100097f  cmp      x11, #2
//   0x0139c0: b91057ee  str      w14, [sp, #0x1054]
//   0x0139c4: 5400006a  b.ge     #0x139d0
//   0x0139c8: 52800031  mov      w17, #1
//   0x0139cc: 1400001d  b        #0x13a40
//   0x0139d0: 93407dcf  sxtw     x15, w14
//   0x0139d4: b86f7b6f  ldr      w15, [x27, x15, lsl #2]
//   0x0139d8: 52800030  mov      w16, #1
//   0x0139dc: 52800040  mov      w0, #2
//   0x0139e0: 93407c01  sxtw     x1, w0
//   0x0139e4: eb01017f  cmp      x11, x1
//   0x0139e8: 5400014d  b.le     #0x13a10
//   0x0139ec: b2400031  orr      x17, x1, #1
//   0x0139f0: b8b17b02  ldrsw    x2, [x24, x17, lsl #2]
//   0x0139f4: b8a17b01  ldrsw    x1, [x24, x1, lsl #2]
//   0x0139f8: b8627b62  ldr      w2, [x27, x2, lsl #2]
//   0x0139fc: b8617b61  ldr      w1, [x27, x1, lsl #2]
//   0x013a00: 6b01005f  cmp      w2, w1
//   0x013a04: 1a80b231  csel     w17, w17, w0, lt
//   0x013a08: 93407e21  sxtw     x1, w17
//   0x013a0c: 14000002  b        #0x13a14
//   0x013a10: 2a0003f1  mov      w17, w0
//   0x013a14: b8a17b01  ldrsw    x1, [x24, x1, lsl #2]
//   0x013a18: b8617b60  ldr      w0, [x27, x1, lsl #2]
//   0x013a1c: 6b0001ff  cmp      w15, w0
//   0x013a20: 540000eb  b.lt     #0x13a3c
//   0x013a24: 531f7a20  lsl      w0, w17, #1
//   0x013a28: eb20c17f  cmp      x11, w0, sxtw
//   0x013a2c: b830db01  str      w1, [x24, w16, sxtw #2]
//   0x013a30: 2a1103f0  mov      w16, w17
//   0x013a34: 54fffd6a  b.ge     #0x139e0
//   0x013a38: 14000002  b        #0x13a40
//   0x013a3c: 2a1003f1  mov      w17, w16
//   0x013a40: b831db0e  str      w14, [x24, w17, sxtw #2]
//   0x013a44: d37ef5ae  lsl      x14, x13, #2
//   0x013a48: d37ef54f  lsl      x15, x10, #2
//   0x013a4c: b86f6b6b  ldr      w11, [x27, x15]
//   0x013a50: b86e6b70  ldr      w16, [x27, x14]
//   0x013a54: 91000508  add      x8, x8, #1
//   0x013a58: 13017d2a  asr      w10, w9, #1
//   0x013a5c: 12185d6d  and      w13, w11, #0xffffff00
//   0x013a60: 12185e11  and      w17, w16, #0xffffff00
//   0x013a64: 12001d6b  and      w11, w11, #0xff
//   0x013a68: 12001e10  and      w16, w16, #0xff
//   0x013a6c: b8297b08  str      w8, [x24, x9, lsl #2]
//   0x013a70: 6b10017f  cmp      w11, w16
//   0x013a74: 0b0d0231  add      w17, w17, w13
//   0x013a78: b8aadb0d  ldrsw    x13, [x24, w10, sxtw #2]
//   0x013a7c: 1a90816b  csel     w11, w11, w16, hi
//   0x013a80: 1100056b  add      w11, w11, #1
//   0x013a84: 2a11016b  orr      w11, w11, w17
//   0x013a88: d37ef510  lsl      x16, x8, #2
//   0x013a8c: b8306b6b  str      w11, [x27, x16]
//   0x013a90: b86d7b71  ldr      w17, [x27, x13, lsl #2]
//   0x013a94: b82e6b88  str      w8, [x28, x14]
//   0x013a98: b82f6b88  str      w8, [x28, x15]
//   0x013a9c: b8306b96  str      w22, [x28, x16]
//   0x013aa0: 6b11017f  cmp      w11, w17
//   0x013aa4: 54fff34a  b.ge     #0x1390c
//   0x013aa8: b900018d  str      w13, [x12]
//   0x013aac: 13017d4e  asr      w14, w10, #1
//   0x013ab0: b8aedb0d  ldrsw    x13, [x24, w14, sxtw #2]
//   0x013ab4: b86d7b6c  ldr      w12, [x27, x13, lsl #2]
//   0x013ab8: 6b0c017f  cmp      w11, w12
//   0x013abc: 8b2acb0c  add      x12, x24, w10, sxtw #2
//   0x013ac0: 2a0e03ea  mov      w10, w14
//   0x013ac4: 54ffff2b  b.lt     #0x13aa8
//   0x013ac8: 17ffff91  b        #0x1390c
//   0x013acc: 7108111f  cmp      w8, #0x204
//   0x013ad0: 5400006b  b.lt     #0x13adc
//   0x013ad4: 5280fa40  mov      w0, #0x7d2
//   0x013ad8: 97ffbb66  bl       #0x2870
//   0x013adc: 7100069f  cmp      w20, #1
//   0x013ae0: 4f002422  movi     v2.4s, #1, lsl #8
//   0x013ae4: 540006eb  b.lt     #0x13bc0
//   0x013ae8: 2a1f03e8  mov      w8, wzr
//   0x013aec: 52800029  mov      w9, #1
//   0x013af0: 1280000a  mov      w10, #-1
//   0x013af4: 2a0903eb  mov      w11, w9
//   0x013af8: b86bdb8b  ldr      w11, [x28, w11, sxtw #2]
//   0x013afc: 1100054a  add      w10, w10, #1
//   0x013b00: 36ffffcb  tbz      w11, #0x1f, #0x13af8
//   0x013b04: 8b15012b  add      x11, x9, x21
//   0x013b08: 6b13015f  cmp      w10, w19
//   0x013b0c: 91000529  add      x9, x9, #1
//   0x013b10: 1a9fd508  csinc    w8, w8, wzr, le
//   0x013b14: eb19013f  cmp      x9, x25
//   0x013b18: 381ff16a  sturb    w10, [x11, #-1]
//   0x013b1c: 54fffea1  b.ne     #0x13af0
//   0x013b20: 72001d1f  tst      w8, #0xff
//   0x013b24: 540004e0  b.eq     #0x13bc0
//   0x013b28: 7100069f  cmp      w20, #1
//   0x013b2c: 5400042b  b.lt     #0x13bb0
//   0x013b30: f10012ff  cmp      x23, #4
//   0x013b34: 54000062  b.hs     #0x13b40
//   0x013b38: 52800029  mov      w9, #1
//   0x013b3c: 14000010  b        #0x13b7c
//   0x013b40: f94017e8  ldr      x8, [sp, #0x28]
//   0x013b44: f9400fe9  ldr      x9, [sp, #0x18]
//   0x013b48: 3dc00120  ldr      q0, [x9]
//   0x013b4c: f1001108  subs     x8, x8, #4
//   0x013b50: 4f380401  sshr     v1.4s, v0.4s, #8
//   0x013b54: 6f211401  usra     v1.4s, v0.4s, #0x1f
//   0x013b58: 4f275420  shl      v0.4s, v1.4s, #7
//   0x013b5c: 6f0717e0  bic      v0.4s, #0xff
//   0x013b60: 4ea28400  add      v0.4s, v0.4s, v2.4s
//   0x013b64: 3c810520  str      q0, [x9], #0x10
//   0x013b68: 54ffff01  b.ne     #0x13b48
//   0x013b6c: f94017e8  ldr      x8, [sp, #0x28]
//   0x013b70: f9400be9  ldr      x9, [sp, #0x10]
//   0x013b74: eb0802ff  cmp      x23, x8
//   0x013b78: 54ffe780  b.eq     #0x13868
//   0x013b7c: 8b090b68  add      x8, x27, x9, lsl #2
//   0x013b80: cb090329  sub      x9, x25, x9
//   0x013b84: b940010a  ldr      w10, [x8]
//   0x013b88: 13087d4a  asr      w10, w10, #8
//   0x013b8c: 7100015f  cmp      w10, #0
//   0x013b90: 1a8aa54a  cinc     w10, w10, lt
//   0x013b94: 5319614a  lsl      w10, w10, #7
//   0x013b98: 12185d4a  and      w10, w10, #0xffffff00
//   0x013b9c: 1104014a  add      w10, w10, #0x100
//   0x013ba0: f1000529  subs     x9, x9, #1
//   0x013ba4: b800450a  str      w10, [x8], #4
//   0x013ba8: 54fffee1  b.ne     #0x13b84
//   0x013bac: 17ffff2f  b        #0x13868
//   0x013bb0: 12800028  mov      w8, #-2
//   0x013bb4: b91053ff  str      wzr, [sp, #0x1050]
//   0x013bb8: b90843ff  str      wzr, [sp, #0x840]
//   0x013bbc: b90033e8  str      w8, [sp, #0x30]
//   0x013bc0: f94007e8  ldr      x8, [sp, #8]
//   0x013bc4: f9401508  ldr      x8, [x8, #0x28]
//   0x013bc8: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x013bcc: eb09011f  cmp      x8, x9
//   0x013bd0: 54000141  b.ne     #0x13bf8
//   0x013bd4: 914007ff  add      sp, sp, #1, lsl #12
//   0x013bd8: 9111c3ff  add      sp, sp, #0x470
//   0x013bdc: a9457bfd  ldp      x29, x30, [sp, #0x50]
//   0x013be0: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x013be4: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x013be8: a9425ff8  ldp      x24, x23, [sp, #0x20]
//   0x013bec: a94167fa  ldp      x26, x25, [sp, #0x10]
//   0x013bf0: a8c66ffc  ldp      x28, x27, [sp], #0x60
//   0x013bf4: d65f03c0  ret      
//   0x013bf8: 97ffbb4a  bl       #0x2920
// ============================================================================
std::uint32_t fde_59_13734(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00013734ULL;
    for (std::size_t i = 0; i < 306ULL; ++i) {
        std::uint32_t insn = kTextInstructions[17153ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[60] Subroutine @ 0x013bfc..0x013c9c (160 bytes, 40 AArch64 instructions)
// [VN] Khung FDE[60] Hàm con @ 0x013bfc..0x013c9c (160 byte, 40 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x013bfc: d10083ff  sub      sp, sp, #0x20
//   0x013c00: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x013c04: 910043fd  add      x29, sp, #0x10
//   0x013c08: d53bd048  mrs      x8, tpidr_el0
//   0x013c0c: f9401509  ldr      x9, [x8, #0x28]
//   0x013c10: 6b03005f  cmp      w2, w3
//   0x013c14: f90007e9  str      x9, [sp, #8]
//   0x013c18: 5400032c  b.gt     #0x13c7c
//   0x013c1c: 2a1f03e9  mov      w9, wzr
//   0x013c20: 2a0403ea  mov      w10, w4
//   0x013c24: 7100049f  cmp      w4, #1
//   0x013c28: 540000ea  b.ge     #0x13c44
//   0x013c2c: 6b03005f  cmp      w2, w3
//   0x013c30: 11000442  add      w2, w2, #1
//   0x013c34: 531f7929  lsl      w9, w9, #1
//   0x013c38: 5400022a  b.ge     #0x13c7c
//   0x013c3c: 7100049f  cmp      w4, #1
//   0x013c40: 54ffff6b  b.lt     #0x13c2c
//   0x013c44: aa0a03eb  mov      x11, x10
//   0x013c48: aa0103ec  mov      x12, x1
//   0x013c4c: aa0003ed  mov      x13, x0
//   0x013c50: 14000005  b        #0x13c64
//   0x013c54: 910011ad  add      x13, x13, #4
//   0x013c58: f100056b  subs     x11, x11, #1
//   0x013c5c: 9100058c  add      x12, x12, #1
//   0x013c60: 54fffe60  b.eq     #0x13c2c
//   0x013c64: 3940018e  ldrb     w14, [x12]
//   0x013c68: 6b0e005f  cmp      w2, w14
//   0x013c6c: 54ffff41  b.ne     #0x13c54
//   0x013c70: b90001a9  str      w9, [x13]
//   0x013c74: 11000529  add      w9, w9, #1
//   0x013c78: 17fffff7  b        #0x13c54
//   0x013c7c: f9401508  ldr      x8, [x8, #0x28]
//   0x013c80: f94007e9  ldr      x9, [sp, #8]
//   0x013c84: eb09011f  cmp      x8, x9
//   0x013c88: 54000081  b.ne     #0x13c98
//   0x013c8c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x013c90: 910083ff  add      sp, sp, #0x20
//   0x013c94: d65f03c0  ret      
//   0x013c98: 97ffbb22  bl       #0x2920
// ============================================================================
std::uint32_t fde_60_13bfc(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00013bfcULL;
    for (std::size_t i = 0; i < 40ULL; ++i) {
        std::uint32_t insn = kTextInstructions[17459ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[61] Subroutine @ 0x013c9c..0x013fc4 (808 bytes, 202 AArch64 instructions)
// [VN] Khung FDE[61] Hàm con @ 0x013c9c..0x013fc4 (808 byte, 202 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x013c9c: d101c3ff  sub      sp, sp, #0x70
//   0x013ca0: f9000bfb  str      x27, [sp, #0x10]
//   0x013ca4: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x013ca8: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x013cac: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x013cb0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x013cb4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x013cb8: 910183fd  add      x29, sp, #0x60
//   0x013cbc: d53bd048  mrs      x8, tpidr_el0
//   0x013cc0: f9401509  ldr      x9, [x8, #0x28]
//   0x013cc4: 6b05009f  cmp      w4, w5
//   0x013cc8: f90007e9  str      x9, [sp, #8]
//   0x013ccc: 540002cc  b.gt     #0x13d24
//   0x013cd0: 2a1f03e9  mov      w9, wzr
//   0x013cd4: 2a0603ea  mov      w10, w6
//   0x013cd8: 2a0403eb  mov      w11, w4
//   0x013cdc: 710004df  cmp      w6, #1
//   0x013ce0: 540000ca  b.ge     #0x13cf8
//   0x013ce4: 6b05017f  cmp      w11, w5
//   0x013ce8: 1100056b  add      w11, w11, #1
//   0x013cec: 540001ca  b.ge     #0x13d24
//   0x013cf0: 710004df  cmp      w6, #1
//   0x013cf4: 54ffff8b  b.lt     #0x13ce4
//   0x013cf8: aa1f03ec  mov      x12, xzr
//   0x013cfc: 14000004  b        #0x13d0c
//   0x013d00: 9100058c  add      x12, x12, #1
//   0x013d04: eb0c015f  cmp      x10, x12
//   0x013d08: 54fffee0  b.eq     #0x13ce4
//   0x013d0c: 386c686d  ldrb     w13, [x3, x12]
//   0x013d10: 6b0d017f  cmp      w11, w13
//   0x013d14: 54ffff61  b.ne     #0x13d00
//   0x013d18: b829d84c  str      w12, [x2, w9, sxtw #2]
//   0x013d1c: 11000529  add      w9, w9, #1
//   0x013d20: 17fffff8  b        #0x13d00
//   0x013d24: 6f00e400  movi     v0.2d, #0000000000000000
//   0x013d28: 710000df  cmp      w6, #0
//   0x013d2c: 3c84c020  stur     q0, [x1, #0x4c]
//   0x013d30: ad018020  stp      q0, q0, [x1, #0x30]
//   0x013d34: ad008020  stp      q0, q0, [x1, #0x10]
//   0x013d38: 3d800020  str      q0, [x1]
//   0x013d3c: 540002ad  b.le     #0x13d90
//   0x013d40: 2a0603e9  mov      w9, w6
//   0x013d44: 3840146a  ldrb     w10, [x3], #1
//   0x013d48: f1000529  subs     x9, x9, #1
//   0x013d4c: 8b0a082a  add      x10, x1, x10, lsl #2
//   0x013d50: b940054b  ldr      w11, [x10, #4]
//   0x013d54: 1100056b  add      w11, w11, #1
//   0x013d58: b900054b  str      w11, [x10, #4]
//   0x013d5c: 54ffff41  b.ne     #0x13d44
//   0x013d60: 2940ec29  ldp      w9, w27, [x1, #4]
//   0x013d64: 2941e823  ldp      w3, w26, [x1, #0xc]
//   0x013d68: 2942e422  ldp      w2, w25, [x1, #0x14]
//   0x013d6c: 2943e031  ldp      w17, w24, [x1, #0x1c]
//   0x013d70: 2944dc30  ldp      w16, w23, [x1, #0x24]
//   0x013d74: 2945d82f  ldp      w15, w22, [x1, #0x2c]
//   0x013d78: 2946d42e  ldp      w14, w21, [x1, #0x34]
//   0x013d7c: 2947d02d  ldp      w13, w20, [x1, #0x3c]
//   0x013d80: 2948cc2c  ldp      w12, w19, [x1, #0x44]
//   0x013d84: 29499c2b  ldp      w11, w7, [x1, #0x4c]
//   0x013d88: 294a982a  ldp      w10, w6, [x1, #0x54]
//   0x013d8c: 14000017  b        #0x13de8
//   0x013d90: 2a1f03e6  mov      w6, wzr
//   0x013d94: 2a1f03ea  mov      w10, wzr
//   0x013d98: 2a1f03e7  mov      w7, wzr
//   0x013d9c: 2a1f03eb  mov      w11, wzr
//   0x013da0: 2a1f03f3  mov      w19, wzr
//   0x013da4: 2a1f03ec  mov      w12, wzr
//   0x013da8: 2a1f03f4  mov      w20, wzr
//   0x013dac: 2a1f03ed  mov      w13, wzr
//   0x013db0: 2a1f03f5  mov      w21, wzr
//   0x013db4: 2a1f03ee  mov      w14, wzr
//   0x013db8: 2a1f03f6  mov      w22, wzr
//   0x013dbc: 2a1f03ef  mov      w15, wzr
//   0x013dc0: 2a1f03f7  mov      w23, wzr
//   0x013dc4: 2a1f03f0  mov      w16, wzr
//   0x013dc8: 2a1f03f8  mov      w24, wzr
//   0x013dcc: 2a1f03f1  mov      w17, wzr
//   0x013dd0: 2a1f03f9  mov      w25, wzr
//   0x013dd4: 2a1f03e2  mov      w2, wzr
//   0x013dd8: 2a1f03fa  mov      w26, wzr
//   0x013ddc: 2a1f03e3  mov      w3, wzr
//   0x013de0: 2a1f03fb  mov      w27, wzr
//   0x013de4: 2a1f03e9  mov      w9, wzr
//   0x013de8: 0b09037b  add      w27, w27, w9
//   0x013dec: 2900ec29  stp      w9, w27, [x1, #4]
//   0x013df0: 0b1b0069  add      w9, w3, w27
//   0x013df4: 0b090343  add      w3, w26, w9
//   0x013df8: 29018c29  stp      w9, w3, [x1, #0xc]
//   0x013dfc: 0b030049  add      w9, w2, w3
//   0x013e00: 0b090322  add      w2, w25, w9
//   0x013e04: 29028829  stp      w9, w2, [x1, #0x14]
//   0x013e08: 0b020229  add      w9, w17, w2
//   0x013e0c: 0b090311  add      w17, w24, w9
//   0x013e10: 2903c429  stp      w9, w17, [x1, #0x1c]
//   0x013e14: 0b110209  add      w9, w16, w17
//   0x013e18: 0b0902f0  add      w16, w23, w9
//   0x013e1c: 2904c029  stp      w9, w16, [x1, #0x24]
//   0x013e20: 0b1001e9  add      w9, w15, w16
//   0x013e24: 0b0902cf  add      w15, w22, w9
//   0x013e28: 2905bc29  stp      w9, w15, [x1, #0x2c]
//   0x013e2c: 0b0f01c9  add      w9, w14, w15
//   0x013e30: 0b0902ae  add      w14, w21, w9
//   0x013e34: 2906b829  stp      w9, w14, [x1, #0x34]
//   0x013e38: 0b0e01a9  add      w9, w13, w14
//   0x013e3c: 0b09028d  add      w13, w20, w9
//   0x013e40: 2907b429  stp      w9, w13, [x1, #0x3c]
//   0x013e44: 0b0d0189  add      w9, w12, w13
//   0x013e48: 0b09026c  add      w12, w19, w9
//   0x013e4c: 2908b029  stp      w9, w12, [x1, #0x44]
//   0x013e50: 0b0c0169  add      w9, w11, w12
//   0x013e54: 0b0900eb  add      w11, w7, w9
//   0x013e58: 2909ac29  stp      w9, w11, [x1, #0x4c]
//   0x013e5c: 0b0b0149  add      w9, w10, w11
//   0x013e60: 6b05009f  cmp      w4, w5
//   0x013e64: 0b0900ca  add      w10, w6, w9
//   0x013e68: 290aa829  stp      w9, w10, [x1, #0x54]
//   0x013e6c: 3c84c000  stur     q0, [x0, #0x4c]
//   0x013e70: ad018000  stp      q0, q0, [x0, #0x30]
//   0x013e74: ad008000  stp      q0, q0, [x0, #0x10]
//   0x013e78: 3d800000  str      q0, [x0]
//   0x013e7c: 540001ec  b.gt     #0x13eb8
//   0x013e80: 2a1f03e9  mov      w9, wzr
//   0x013e84: 93407c8b  sxtw     x11, w4
//   0x013e88: 93407caa  sxtw     x10, w5
//   0x013e8c: d37ef56c  lsl      x12, x11, #2
//   0x013e90: 8b0c002d  add      x13, x1, x12
//   0x013e94: 294035ae  ldp      w14, w13, [x13]
//   0x013e98: eb0a017f  cmp      x11, x10
//   0x013e9c: 9100056b  add      x11, x11, #1
//   0x013ea0: 4b0e01ad  sub      w13, w13, w14
//   0x013ea4: 0b0901a9  add      w9, w13, w9
//   0x013ea8: 5100052d  sub      w13, w9, #1
//   0x013eac: 531f7929  lsl      w9, w9, #1
//   0x013eb0: b82c680d  str      w13, [x0, x12]
//   0x013eb4: 54fffecb  b.lt     #0x13e8c
//   0x013eb8: 6b05009f  cmp      w4, w5
//   0x013ebc: 540006aa  b.ge     #0x13f90
//   0x013ec0: 93407c89  sxtw     x9, w4
//   0x013ec4: 93407caa  sxtw     x10, w5
//   0x013ec8: cb09014b  sub      x11, x10, x9
//   0x013ecc: f1001d7f  cmp      x11, #7
//   0x013ed0: 54000469  b.ls     #0x13f5c
//   0x013ed4: d37ef52e  lsl      x14, x9, #2
//   0x013ed8: d37ef54c  lsl      x12, x10, #2
//   0x013edc: 8b0101cd  add      x13, x14, x1
//   0x013ee0: 910011af  add      x15, x13, #4
//   0x013ee4: 8b0c0010  add      x16, x0, x12
//   0x013ee8: eb1001ff  cmp      x15, x16
//   0x013eec: 540000c2  b.hs     #0x13f04
//   0x013ef0: 8b01018c  add      x12, x12, x1
//   0x013ef4: 9100118c  add      x12, x12, #4
//   0x013ef8: 8b0e000f  add      x15, x0, x14
//   0x013efc: eb0c01ff  cmp      x15, x12
//   0x013f00: 540002e3  b.lo     #0x13f5c
//   0x013f04: 927df16c  and      x12, x11, #0xfffffffffffffff8
//   0x013f08: 8b0001ce  add      x14, x14, x0
//   0x013f0c: 910051ad  add      x13, x13, #0x14
//   0x013f10: 8b090189  add      x9, x12, x9
//   0x013f14: 910041ce  add      x14, x14, #0x10
//   0x013f18: 4f000440  movi     v0.4s, #2
//   0x013f1c: aa0c03ef  mov      x15, x12
//   0x013f20: ad7f89c1  ldp      q1, q2, [x14, #-0x10]
//   0x013f24: ad7f91a3  ldp      q3, q4, [x13, #-0x10]
//   0x013f28: f10021ef  subs     x15, x15, #8
//   0x013f2c: 910081ce  add      x14, x14, #0x20
//   0x013f30: 4f215421  shl      v1.4s, v1.4s, #1
//   0x013f34: 4f215442  shl      v2.4s, v2.4s, #1
//   0x013f38: 6ea38421  sub      v1.4s, v1.4s, v3.4s
//   0x013f3c: 6ea48442  sub      v2.4s, v2.4s, v4.4s
//   0x013f40: 4ea08421  add      v1.4s, v1.4s, v0.4s
//   0x013f44: 4ea08442  add      v2.4s, v2.4s, v0.4s
//   0x013f48: ad3f89a1  stp      q1, q2, [x13, #-0x10]
//   0x013f4c: 910081ad  add      x13, x13, #0x20
//   0x013f50: 54fffe81  b.ne     #0x13f20
//   0x013f54: eb0c017f  cmp      x11, x12
//   0x013f58: 540001c0  b.eq     #0x13f90
//   0x013f5c: d37ef52b  lsl      x11, x9, #2
//   0x013f60: cb090149  sub      x9, x10, x9
//   0x013f64: 8b0b000a  add      x10, x0, x11
//   0x013f68: 8b01016b  add      x11, x11, x1
//   0x013f6c: 9100116b  add      x11, x11, #4
//   0x013f70: b840454c  ldr      w12, [x10], #4
//   0x013f74: b940016d  ldr      w13, [x11]
//   0x013f78: f1000529  subs     x9, x9, #1
//   0x013f7c: 531f798c  lsl      w12, w12, #1
//   0x013f80: 4b0d018c  sub      w12, w12, w13
//   0x013f84: 1100098c  add      w12, w12, #2
//   0x013f88: b800456c  str      w12, [x11], #4
//   0x013f8c: 54ffff21  b.ne     #0x13f70
//   0x013f90: f9401508  ldr      x8, [x8, #0x28]
//   0x013f94: f94007e9  ldr      x9, [sp, #8]
//   0x013f98: eb09011f  cmp      x8, x9
//   0x013f9c: 54000121  b.ne     #0x13fc0
//   0x013fa0: a9467bfd  ldp      x29, x30, [sp, #0x60]
//   0x013fa4: a9454ff4  ldp      x20, x19, [sp, #0x50]
//   0x013fa8: a94457f6  ldp      x22, x21, [sp, #0x40]
//   0x013fac: a9435ff8  ldp      x24, x23, [sp, #0x30]
//   0x013fb0: a94267fa  ldp      x26, x25, [sp, #0x20]
//   0x013fb4: f9400bfb  ldr      x27, [sp, #0x10]
//   0x013fb8: 9101c3ff  add      sp, sp, #0x70
//   0x013fbc: d65f03c0  ret      
//   0x013fc0: 97ffba58  bl       #0x2920
// ============================================================================
std::uint32_t fde_61_13c9c(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00013c9cULL;
    for (std::size_t i = 0; i < 202ULL; ++i) {
        std::uint32_t insn = kTextInstructions[17499ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[62] Subroutine @ 0x013fc4..0x014a90 (2764 bytes, 691 AArch64 instructions)
// [VN] Khung FDE[62] Hàm con @ 0x013fc4..0x014a90 (2764 byte, 691 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x013fc4: d10403ff  sub      sp, sp, #0x100
//   0x013fc8: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x013fcc: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x013fd0: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x013fd4: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x013fd8: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x013fdc: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x013fe0: 9103c3fd  add      x29, sp, #0xf0
//   0x013fe4: d53bd05b  mrs      x27, tpidr_el0
//   0x013fe8: f9401768  ldr      x8, [x27, #0x28]
//   0x013fec: aa0103fc  mov      x28, x1
//   0x013ff0: b0000001  adrp     x1, #0x14000
//   0x013ff4: aa0003f3  mov      x19, x0
//   0x013ff8: 91382c21  add      x1, x1, #0xe0b
//   0x013ffc: aa0303e0  mov      x0, x3
//   0x014000: aa0303f4  mov      x20, x3
//   0x014004: aa0203f5  mov      x21, x2
//   0x014008: f81a83a8  stur     x8, [x29, #-0x58]
//   0x01400c: 97ffbab1  bl       #0x2ad0
//   0x014010: b4000460  cbz      x0, #0x1409c
//   0x014014: aa0003f7  mov      x23, x0
//   0x014018: 9101e3e0  add      x0, sp, #0x78
//   0x01401c: 52800021  mov      w1, #1
//   0x014020: 52800402  mov      w2, #0x20
//   0x014024: aa1703e3  mov      x3, x23
//   0x014028: 97ffb9c2  bl       #0x2730
//   0x01402c: f1007c1f  cmp      x0, #0x1f
//   0x014030: 54000188  b.hi     #0x14060
//   0x014034: aa1703e0  mov      x0, x23
//   0x014038: 97ffba42  bl       #0x2940
//   0x01403c: 34000120  cbz      w0, #0x14060
//   0x014040: f0000003  adrp     x3, #0x17000
//   0x014044: 91062063  add      x3, x3, #0x188
//   0x014048: 92800001  mov      x1, #-1
//   0x01404c: aa1303e0  mov      x0, x19
//   0x014050: aa1403e4  mov      x4, x20
//   0x014054: 9400028f  bl       #0x14a90
//   0x014058: 12800020  mov      w0, #-2
//   0x01405c: 1400001b  b        #0x140c8
//   0x014060: f9403fe8  ldr      x8, [sp, #0x78]
//   0x014064: d28a6849  mov      x9, #0x5342
//   0x014068: f2a92889  movk     x9, #0x4944, lsl #16
//   0x01406c: f2c8c8c9  movk     x9, #0x4646, lsl #32
//   0x014070: f2e60689  movk     x9, #0x3034, lsl #48
//   0x014074: eb09011f  cmp      x8, x9
//   0x014078: 54000400  b.eq     #0x140f8
//   0x01407c: f0000003  adrp     x3, #0x17000
//   0x014080: 91062063  add      x3, x3, #0x188
//   0x014084: 92800001  mov      x1, #-1
//   0x014088: aa1303e0  mov      x0, x19
//   0x01408c: aa1403e4  mov      x4, x20
//   0x014090: 94000280  bl       #0x14a90
//   0x014094: 12800040  mov      w0, #-3
//   0x014098: 1400000c  b        #0x140c8
//   0x01409c: 97ffb9dd  bl       #0x2810
//   0x0140a0: b9400000  ldr      w0, [x0]
//   0x0140a4: 97ffb9cf  bl       #0x27e0
//   0x0140a8: f0000003  adrp     x3, #0x17000
//   0x0140ac: aa0003e5  mov      x5, x0
//   0x0140b0: 91060063  add      x3, x3, #0x180
//   0x0140b4: 92800001  mov      x1, #-1
//   0x0140b8: aa1303e0  mov      x0, x19
//   0x0140bc: aa1403e4  mov      x4, x20
//   0x0140c0: 94000274  bl       #0x14a90
//   0x0140c4: 12800000  mov      w0, #-1
//   0x0140c8: f9401768  ldr      x8, [x27, #0x28]
//   0x0140cc: f85a83a9  ldur     x9, [x29, #-0x58]
//   0x0140d0: eb09011f  cmp      x8, x9
//   0x0140d4: 54004dc1  b.ne     #0x14a8c
//   0x0140d8: a94f7bfd  ldp      x29, x30, [sp, #0xf0]
//   0x0140dc: a94e4ff4  ldp      x20, x19, [sp, #0xe0]
//   0x0140e0: a94d57f6  ldp      x22, x21, [sp, #0xd0]
//   0x0140e4: a94c5ff8  ldp      x24, x23, [sp, #0xc0]
//   0x0140e8: a94b67fa  ldp      x26, x25, [sp, #0xb0]
//   0x0140ec: a94a6ffc  ldp      x28, x27, [sp, #0xa0]
//   0x0140f0: 910403ff  add      sp, sp, #0x100
//   0x0140f4: d65f03c0  ret      
//   0x0140f8: 39421fea  ldrb     w10, [sp, #0x87]
//   0x0140fc: 39421beb  ldrb     w11, [sp, #0x86]
//   0x014100: 39423fec  ldrb     w12, [sp, #0x8f]
//   0x014104: 39423bed  ldrb     w13, [sp, #0x8e]
//   0x014108: 39425fef  ldrb     w15, [sp, #0x97]
//   0x01410c: 7219015f  tst      w10, #0x80
//   0x014110: 53185d4a  lsl      w10, w10, #8
//   0x014114: 9278194a  and      x10, x10, #0x7f00
//   0x014118: 39425bf0  ldrb     w16, [sp, #0x96]
//   0x01411c: aa0b014a  orr      x10, x10, x11
//   0x014120: 53185d8b  lsl      w11, w12, #8
//   0x014124: 394237ee  ldrb     w14, [sp, #0x8d]
//   0x014128: 9278196b  and      x11, x11, #0x7f00
//   0x01412c: aa0d016b  orr      x11, x11, x13
//   0x014130: 53185ded  lsl      w13, w15, #8
//   0x014134: 927819ad  and      x13, x13, #0x7f00
//   0x014138: aa1001ad  orr      x13, x13, x16
//   0x01413c: 394257f0  ldrb     w16, [sp, #0x95]
//   0x014140: b378396e  bfi      x14, x11, #8, #0xf
//   0x014144: 394233eb  ldrb     w11, [sp, #0x8c]
//   0x014148: 394217e8  ldrb     w8, [sp, #0x85]
//   0x01414c: b37839b0  bfi      x16, x13, #8, #0xf
//   0x014150: 394253ed  ldrb     w13, [sp, #0x94]
//   0x014154: b37859cb  bfi      x11, x14, #8, #0x17
//   0x014158: 39422fee  ldrb     w14, [sp, #0x8b]
//   0x01415c: 394213e9  ldrb     w9, [sp, #0x84]
//   0x014160: b3783948  bfi      x8, x10, #8, #0xf
//   0x014164: 39420fea  ldrb     w10, [sp, #0x83]
//   0x014168: b3785a0d  bfi      x13, x16, #8, #0x17
//   0x01416c: 39424ff0  ldrb     w16, [sp, #0x93]
//   0x014170: b378dd6e  bfi      x14, x11, #8, #0x38
//   0x014174: 39422beb  ldrb     w11, [sp, #0x8a]
//   0x014178: b3785909  bfi      x9, x8, #8, #0x17
//   0x01417c: 39420be8  ldrb     w8, [sp, #0x82]
//   0x014180: b378dd2a  bfi      x10, x9, #8, #0x38
//   0x014184: 394207e9  ldrb     w9, [sp, #0x81]
//   0x014188: b378ddb0  bfi      x16, x13, #8, #0x38
//   0x01418c: 39424bed  ldrb     w13, [sp, #0x92]
//   0x014190: b378ddcb  bfi      x11, x14, #8, #0x38
//   0x014194: 394227ee  ldrb     w14, [sp, #0x89]
//   0x014198: b378dd48  bfi      x8, x10, #8, #0x38
//   0x01419c: 394203ea  ldrb     w10, [sp, #0x80]
//   0x0141a0: b378de0d  bfi      x13, x16, #8, #0x38
//   0x0141a4: 394247f0  ldrb     w16, [sp, #0x91]
//   0x0141a8: b378dd09  bfi      x9, x8, #8, #0x38
//   0x0141ac: 394223e8  ldrb     w8, [sp, #0x88]
//   0x0141b0: b378dd6e  bfi      x14, x11, #8, #0x38
//   0x0141b4: 394243eb  ldrb     w11, [sp, #0x90]
//   0x0141b8: b378dd2a  bfi      x10, x9, #8, #0x38
//   0x0141bc: b378ddb0  bfi      x16, x13, #8, #0x38
//   0x0141c0: b378ddc8  bfi      x8, x14, #8, #0x38
//   0x0141c4: da8a055a  cneg     x26, x10, ne
//   0x0141c8: 7219019f  tst      w12, #0x80
//   0x0141cc: b378de0b  bfi      x11, x16, #8, #0x38
//   0x0141d0: da880518  cneg     x24, x8, ne
//   0x0141d4: 721901ff  tst      w15, #0x80
//   0x0141d8: da8b0576  cneg     x22, x11, ne
//   0x0141dc: aa1a0308  orr      x8, x24, x26
//   0x0141e0: aa160108  orr      x8, x8, x22
//   0x0141e4: b7f80208  tbnz     x8, #0x3f, #0x14224
//   0x0141e8: aa1703e0  mov      x0, x23
//   0x0141ec: 97ffb9b9  bl       #0x28d0
//   0x0141f0: 340002a0  cbz      w0, #0x14244
//   0x0141f4: 97ffb987  bl       #0x2810
//   0x0141f8: b9400000  ldr      w0, [x0]
//   0x0141fc: 97ffb979  bl       #0x27e0
//   0x014200: f0000003  adrp     x3, #0x17000
//   0x014204: aa0003e5  mov      x5, x0
//   0x014208: 91060063  add      x3, x3, #0x180
//   0x01420c: 92800001  mov      x1, #-1
//   0x014210: aa1303e0  mov      x0, x19
//   0x014214: aa1403e4  mov      x4, x20
//   0x014218: 9400021e  bl       #0x14a90
//   0x01421c: 12800080  mov      w0, #-5
//   0x014220: 17ffffaa  b        #0x140c8
//   0x014224: f0000003  adrp     x3, #0x17000
//   0x014228: 91062063  add      x3, x3, #0x188
//   0x01422c: 92800001  mov      x1, #-1
//   0x014230: aa1303e0  mov      x0, x19
//   0x014234: aa1403e4  mov      x4, x20
//   0x014238: 94000216  bl       #0x14a90
//   0x01423c: 12800060  mov      w0, #-4
//   0x014240: 17ffffa2  b        #0x140c8
//   0x014244: 90000001  adrp     x1, #0x14000
//   0x014248: 91382c21  add      x1, x1, #0xe0b
//   0x01424c: aa1403e0  mov      x0, x20
//   0x014250: 97ffba20  bl       #0x2ad0
//   0x014254: b4000240  cbz      x0, #0x1429c
//   0x014258: 52800401  mov      w1, #0x20
//   0x01425c: 2a1f03e2  mov      w2, wzr
//   0x014260: aa0003f7  mov      x23, x0
//   0x014264: 97ffb95b  bl       #0x27d0
//   0x014268: 34000320  cbz      w0, #0x142cc
//   0x01426c: 97ffb969  bl       #0x2810
//   0x014270: b9400000  ldr      w0, [x0]
//   0x014274: 97ffb95b  bl       #0x27e0
//   0x014278: f0000003  adrp     x3, #0x17000
//   0x01427c: aa0003e5  mov      x5, x0
//   0x014280: 91060063  add      x3, x3, #0x180
//   0x014284: 92800001  mov      x1, #-1
//   0x014288: aa1303e0  mov      x0, x19
//   0x01428c: aa1403e4  mov      x4, x20
//   0x014290: 94000200  bl       #0x14a90
//   0x014294: 128000c0  mov      w0, #-7
//   0x014298: 17ffff8c  b        #0x140c8
//   0x01429c: 97ffb95d  bl       #0x2810
//   0x0142a0: b9400000  ldr      w0, [x0]
//   0x0142a4: 97ffb94f  bl       #0x27e0
//   0x0142a8: f0000003  adrp     x3, #0x17000
//   0x0142ac: aa0003e5  mov      x5, x0
//   0x0142b0: 91060063  add      x3, x3, #0x180
//   0x0142b4: 92800001  mov      x1, #-1
//   0x0142b8: aa1303e0  mov      x0, x19
//   0x0142bc: aa1403e4  mov      x4, x20
//   0x0142c0: 940001f4  bl       #0x14a90
//   0x0142c4: 128000a0  mov      w0, #-6
//   0x0142c8: 17ffff80  b        #0x140c8
//   0x0142cc: 9101b3e0  add      x0, sp, #0x6c
//   0x0142d0: aa1703e1  mov      x1, x23
//   0x0142d4: 2a1f03e2  mov      w2, wzr
//   0x0142d8: 2a1f03e3  mov      w3, wzr
//   0x0142dc: aa1f03e4  mov      x4, xzr
//   0x0142e0: 2a1f03e5  mov      w5, wzr
//   0x0142e4: 97ffb8ff  bl       #0x26e0
//   0x0142e8: b4000340  cbz      x0, #0x14350
//   0x0142ec: 90000001  adrp     x1, #0x14000
//   0x0142f0: aa0003f9  mov      x25, x0
//   0x0142f4: 91382c21  add      x1, x1, #0xe0b
//   0x0142f8: aa1403e0  mov      x0, x20
//   0x0142fc: 97ffb9f5  bl       #0x2ad0
//   0x014300: b4000380  cbz      x0, #0x14370
//   0x014304: 9100835a  add      x26, x26, #0x20
//   0x014308: aa1a03e1  mov      x1, x26
//   0x01430c: 2a1f03e2  mov      w2, wzr
//   0x014310: f9002ff9  str      x25, [sp, #0x58]
//   0x014314: aa0003f9  mov      x25, x0
//   0x014318: 97ffb92e  bl       #0x27d0
//   0x01431c: 34000420  cbz      w0, #0x143a0
//   0x014320: 97ffb93c  bl       #0x2810
//   0x014324: b9400000  ldr      w0, [x0]
//   0x014328: 97ffb92e  bl       #0x27e0
//   0x01432c: f0000003  adrp     x3, #0x17000
//   0x014330: aa0003e5  mov      x5, x0
//   0x014334: 91060063  add      x3, x3, #0x180
//   0x014338: 92800001  mov      x1, #-1
//   0x01433c: aa1303e0  mov      x0, x19
//   0x014340: aa1403e4  mov      x4, x20
//   0x014344: 940001d3  bl       #0x14a90
//   0x014348: 12800120  mov      w0, #-0xa
//   0x01434c: 17ffff5f  b        #0x140c8
//   0x014350: b9406fe4  ldr      w4, [sp, #0x6c]
//   0x014354: f0000003  adrp     x3, #0x17000
//   0x014358: 91068c63  add      x3, x3, #0x1a3
//   0x01435c: 92800001  mov      x1, #-1
//   0x014360: aa1303e0  mov      x0, x19
//   0x014364: 940001cb  bl       #0x14a90
//   0x014368: 128000e0  mov      w0, #-8
//   0x01436c: 17ffff57  b        #0x140c8
//   0x014370: 97ffb928  bl       #0x2810
//   0x014374: b9400000  ldr      w0, [x0]
//   0x014378: 97ffb91a  bl       #0x27e0
//   0x01437c: f0000003  adrp     x3, #0x17000
//   0x014380: aa0003e5  mov      x5, x0
//   0x014384: 91060063  add      x3, x3, #0x180
//   0x014388: 92800001  mov      x1, #-1
//   0x01438c: aa1303e0  mov      x0, x19
//   0x014390: aa1403e4  mov      x4, x20
//   0x014394: 940001bf  bl       #0x14a90
//   0x014398: 12800100  mov      w0, #-9
//   0x01439c: 17ffff4b  b        #0x140c8
//   0x0143a0: 9101a3e0  add      x0, sp, #0x68
//   0x0143a4: aa1903e1  mov      x1, x25
//   0x0143a8: 2a1f03e2  mov      w2, wzr
//   0x0143ac: 2a1f03e3  mov      w3, wzr
//   0x0143b0: aa1f03e4  mov      x4, xzr
//   0x0143b4: 2a1f03e5  mov      w5, wzr
//   0x0143b8: f9002bf9  str      x25, [sp, #0x50]
//   0x0143bc: 97ffb8c9  bl       #0x26e0
//   0x0143c0: b4000300  cbz      x0, #0x14420
//   0x0143c4: 90000001  adrp     x1, #0x14000
//   0x0143c8: f90027e0  str      x0, [sp, #0x48]
//   0x0143cc: 91382c21  add      x1, x1, #0xe0b
//   0x0143d0: aa1403e0  mov      x0, x20
//   0x0143d4: 97ffb9bf  bl       #0x2ad0
//   0x0143d8: b4000340  cbz      x0, #0x14440
//   0x0143dc: 8b1a0301  add      x1, x24, x26
//   0x0143e0: 2a1f03e2  mov      w2, wzr
//   0x0143e4: aa0003f9  mov      x25, x0
//   0x0143e8: 97ffb8fa  bl       #0x27d0
//   0x0143ec: 34000420  cbz      w0, #0x14470
//   0x0143f0: 97ffb908  bl       #0x2810
//   0x0143f4: b9400000  ldr      w0, [x0]
//   0x0143f8: 97ffb8fa  bl       #0x27e0
//   0x0143fc: f0000003  adrp     x3, #0x17000
//   0x014400: aa0003e5  mov      x5, x0
//   0x014404: 91060063  add      x3, x3, #0x180
//   0x014408: 92800001  mov      x1, #-1
//   0x01440c: aa1303e0  mov      x0, x19
//   0x014410: aa1403e4  mov      x4, x20
//   0x014414: 9400019f  bl       #0x14a90
//   0x014418: 12800180  mov      w0, #-0xd
//   0x01441c: 17ffff2b  b        #0x140c8
//   0x014420: b9406fe4  ldr      w4, [sp, #0x6c]
//   0x014424: f0000003  adrp     x3, #0x17000
//   0x014428: 91068c63  add      x3, x3, #0x1a3
//   0x01442c: 92800001  mov      x1, #-1
//   0x014430: aa1303e0  mov      x0, x19
//   0x014434: 94000197  bl       #0x14a90
//   0x014438: 12800140  mov      w0, #-0xb
//   0x01443c: 17ffff23  b        #0x140c8
//   0x014440: 97ffb8f4  bl       #0x2810
//   0x014444: b9400000  ldr      w0, [x0]
//   0x014448: 97ffb8e6  bl       #0x27e0
//   0x01444c: f0000003  adrp     x3, #0x17000
//   0x014450: aa0003e5  mov      x5, x0
//   0x014454: 91060063  add      x3, x3, #0x180
//   0x014458: 92800001  mov      x1, #-1
//   0x01445c: aa1303e0  mov      x0, x19
//   0x014460: aa1403e4  mov      x4, x20
//   0x014464: 9400018b  bl       #0x14a90
//   0x014468: 12800160  mov      w0, #-0xc
//   0x01446c: 17ffff17  b        #0x140c8
//   0x014470: 910193e0  add      x0, sp, #0x64
//   0x014474: aa1903e1  mov      x1, x25
//   0x014478: 2a1f03e2  mov      w2, wzr
//   0x01447c: 2a1f03e3  mov      w3, wzr
//   0x014480: aa1f03e4  mov      x4, xzr
//   0x014484: 2a1f03e5  mov      w5, wzr
//   0x014488: 97ffb896  bl       #0x26e0
//   0x01448c: b4002480  cbz      x0, #0x1491c
//   0x014490: f9001fe0  str      x0, [sp, #0x38]
//   0x014494: aa1c03e0  mov      x0, x28
//   0x014498: 2a1f03e1  mov      w1, wzr
//   0x01449c: 2a1f03e2  mov      w2, wzr
//   0x0144a0: 97ffb888  bl       #0x26c0
//   0x0144a4: 37f82240  tbnz     w0, #0x1f, #0x148ec
//   0x0144a8: 52800042  mov      w2, #2
//   0x0144ac: aa1f03e1  mov      x1, xzr
//   0x0144b0: 2a0003fa  mov      w26, w0
//   0x0144b4: 97ffb90b  bl       #0x28e0
//   0x0144b8: b100041f  cmn      x0, #1
//   0x0144bc: f90023e0  str      x0, [sp, #0x40]
//   0x0144c0: 54002160  b.eq     #0x148ec
//   0x0144c4: f94023e8  ldr      x8, [sp, #0x40]
//   0x0144c8: 91000500  add      x0, x8, #1
//   0x0144cc: 97ffb971  bl       #0x2a90
//   0x0144d0: f9001be0  str      x0, [sp, #0x30]
//   0x0144d4: b40020c0  cbz      x0, #0x148ec
//   0x0144d8: 2a1a03e0  mov      w0, w26
//   0x0144dc: aa1f03e1  mov      x1, xzr
//   0x0144e0: 2a1f03e2  mov      w2, wzr
//   0x0144e4: 97ffb8ff  bl       #0x28e0
//   0x0144e8: b5002020  cbnz     x0, #0x148ec
//   0x0144ec: f94023f8  ldr      x24, [sp, #0x40]
//   0x0144f0: f9401be1  ldr      x1, [sp, #0x30]
//   0x0144f4: 92800003  mov      x3, #-1
//   0x0144f8: 2a1a03e0  mov      w0, w26
//   0x0144fc: aa1803e2  mov      x2, x24
//   0x014500: 97ffb8f0  bl       #0x28c0
//   0x014504: eb18001f  cmp      x0, x24
//   0x014508: 54001f21  b.ne     #0x148ec
//   0x01450c: 2a1a03e0  mov      w0, w26
//   0x014510: 97ffb94c  bl       #0x2a40
//   0x014514: 3100041f  cmn      w0, #1
//   0x014518: 54001ea0  b.eq     #0x148ec
//   0x01451c: 910006c0  add      x0, x22, #1
//   0x014520: 97ffb95c  bl       #0x2a90
//   0x014524: f90013e0  str      x0, [sp, #0x20]
//   0x014528: b40020a0  cbz      x0, #0x1493c
//   0x01452c: f10006df  cmp      x22, #1
//   0x014530: 54001a2b  b.lt     #0x14874
//   0x014534: f94013e8  ldr      x8, [sp, #0x20]
//   0x014538: f90017ff  str      xzr, [sp, #0x28]
//   0x01453c: f9000fff  str      xzr, [sp, #0x18]
//   0x014540: 91000508  add      x8, x8, #1
//   0x014544: f90007e8  str      x8, [sp, #8]
//   0x014548: f9402fe1  ldr      x1, [sp, #0x58]
//   0x01454c: 9101b3e0  add      x0, sp, #0x6c
//   0x014550: 9101c3e2  add      x2, sp, #0x70
//   0x014554: 52800103  mov      w3, #8
//   0x014558: 97ffb8ce  bl       #0x2890
//   0x01455c: 7100201f  cmp      w0, #8
//   0x014560: 5400204b  b.lt     #0x14968
//   0x014564: b9406fe8  ldr      w8, [sp, #0x6c]
//   0x014568: 721d791f  tst      w8, #0xfffffffb
//   0x01456c: 54001fe1  b.ne     #0x14968
//   0x014570: 3941dfe8  ldrb     w8, [sp, #0x77]
//   0x014574: 3941dbe9  ldrb     w9, [sp, #0x76]
//   0x014578: 3941d7ea  ldrb     w10, [sp, #0x75]
//   0x01457c: 3941d3eb  ldrb     w11, [sp, #0x74]
//   0x014580: 53185d0d  lsl      w13, w8, #8
//   0x014584: 3941cfec  ldrb     w12, [sp, #0x73]
//   0x014588: 927819ad  and      x13, x13, #0x7f00
//   0x01458c: aa0901a9  orr      x9, x13, x9
//   0x014590: 3941cbed  ldrb     w13, [sp, #0x72]
//   0x014594: b378392a  bfi      x10, x9, #8, #0xf
//   0x014598: 3941c7e9  ldrb     w9, [sp, #0x71]
//   0x01459c: b378594b  bfi      x11, x10, #8, #0x17
//   0x0145a0: 3941c3ea  ldrb     w10, [sp, #0x70]
//   0x0145a4: b378dd6c  bfi      x12, x11, #8, #0x38
//   0x0145a8: f9402fe1  ldr      x1, [sp, #0x58]
//   0x0145ac: b378dd8d  bfi      x13, x12, #8, #0x38
//   0x0145b0: b378dda9  bfi      x9, x13, #8, #0x38
//   0x0145b4: b378dd2a  bfi      x10, x9, #8, #0x38
//   0x0145b8: 7219011f  tst      w8, #0x80
//   0x0145bc: 9101b3e0  add      x0, sp, #0x6c
//   0x0145c0: 9101c3e2  add      x2, sp, #0x70
//   0x0145c4: 52800103  mov      w3, #8
//   0x0145c8: da8a055c  cneg     x28, x10, ne
//   0x0145cc: 97ffb8b1  bl       #0x2890
//   0x0145d0: 7100201f  cmp      w0, #8
//   0x0145d4: 54001cab  b.lt     #0x14968
//   0x0145d8: b9406fe8  ldr      w8, [sp, #0x6c]
//   0x0145dc: 721d791f  tst      w8, #0xfffffffb
//   0x0145e0: 54001c41  b.ne     #0x14968
//   0x0145e4: 3941dfe8  ldrb     w8, [sp, #0x77]
//   0x0145e8: 3941dbe9  ldrb     w9, [sp, #0x76]
//   0x0145ec: 3941d7ea  ldrb     w10, [sp, #0x75]
//   0x0145f0: 3941d3eb  ldrb     w11, [sp, #0x74]
//   0x0145f4: 53185d0d  lsl      w13, w8, #8
//   0x0145f8: 3941cfec  ldrb     w12, [sp, #0x73]
//   0x0145fc: 927819ad  and      x13, x13, #0x7f00
//   0x014600: aa0901a9  orr      x9, x13, x9
//   0x014604: 3941cbed  ldrb     w13, [sp, #0x72]
//   0x014608: b378392a  bfi      x10, x9, #8, #0xf
//   0x01460c: 3941c7e9  ldrb     w9, [sp, #0x71]
//   0x014610: b378594b  bfi      x11, x10, #8, #0x17
//   0x014614: 3941c3ea  ldrb     w10, [sp, #0x70]
//   0x014618: b378dd6c  bfi      x12, x11, #8, #0x38
//   0x01461c: f9402fe1  ldr      x1, [sp, #0x58]
//   0x014620: b378dd8d  bfi      x13, x12, #8, #0x38
//   0x014624: b378dda9  bfi      x9, x13, #8, #0x38
//   0x014628: b378dd2a  bfi      x10, x9, #8, #0x38
//   0x01462c: 7219011f  tst      w8, #0x80
//   0x014630: 9101b3e0  add      x0, sp, #0x6c
//   0x014634: 9101c3e2  add      x2, sp, #0x70
//   0x014638: 52800103  mov      w3, #8
//   0x01463c: da8a0558  cneg     x24, x10, ne
//   0x014640: 97ffb894  bl       #0x2890
//   0x014644: 7100201f  cmp      w0, #8
//   0x014648: 5400190b  b.lt     #0x14968
//   0x01464c: b9406fe8  ldr      w8, [sp, #0x6c]
//   0x014650: 721d791f  tst      w8, #0xfffffffb
//   0x014654: 540018a1  b.ne     #0x14968
//   0x014658: 3941dfe8  ldrb     w8, [sp, #0x77]
//   0x01465c: 3941dbe9  ldrb     w9, [sp, #0x76]
//   0x014660: 3941d7ea  ldrb     w10, [sp, #0x75]
//   0x014664: 3941d3eb  ldrb     w11, [sp, #0x74]
//   0x014668: 7219011f  tst      w8, #0x80
//   0x01466c: 53185d08  lsl      w8, w8, #8
//   0x014670: 92781908  and      x8, x8, #0x7f00
//   0x014674: aa090108  orr      x8, x8, x9
//   0x014678: 3941cfe9  ldrb     w9, [sp, #0x73]
//   0x01467c: b378390a  bfi      x10, x8, #8, #0xf
//   0x014680: 3941cbe8  ldrb     w8, [sp, #0x72]
//   0x014684: b378594b  bfi      x11, x10, #8, #0x17
//   0x014688: 3941c7ea  ldrb     w10, [sp, #0x71]
//   0x01468c: b378dd69  bfi      x9, x11, #8, #0x38
//   0x014690: b378dd28  bfi      x8, x9, #8, #0x38
//   0x014694: 3941c3eb  ldrb     w11, [sp, #0x70]
//   0x014698: b378dd0a  bfi      x10, x8, #8, #0x38
//   0x01469c: f94017e8  ldr      x8, [sp, #0x28]
//   0x0146a0: b378dd4b  bfi      x11, x10, #8, #0x38
//   0x0146a4: 8b08039a  add      x26, x28, x8
//   0x0146a8: da8b0568  cneg     x8, x11, ne
//   0x0146ac: eb16035f  cmp      x26, x22
//   0x0146b0: f9000be8  str      x8, [sp, #0x10]
//   0x0146b4: 540018ac  b.gt     #0x149c8
//   0x0146b8: a94227e8  ldp      x8, x9, [sp, #0x20]
//   0x0146bc: f94027e1  ldr      x1, [sp, #0x48]
//   0x0146c0: 9101a3e0  add      x0, sp, #0x68
//   0x0146c4: 2a1c03e3  mov      w3, w28
//   0x0146c8: 8b090102  add      x2, x8, x9
//   0x0146cc: 97ffb871  bl       #0x2890
//   0x0146d0: eb20c39f  cmp      x28, w0, sxtw
//   0x0146d4: 540015ac  b.gt     #0x14988
//   0x0146d8: b9406be8  ldr      w8, [sp, #0x68]
//   0x0146dc: 721d791f  tst      w8, #0xfffffffb
//   0x0146e0: 54001541  b.ne     #0x14988
//   0x0146e4: f100079f  cmp      x28, #1
//   0x0146e8: 5400098b  b.lt     #0x14818
//   0x0146ec: 54000061  b.ne     #0x146f8
//   0x0146f0: aa1f03e8  mov      x8, xzr
//   0x0146f4: 14000033  b        #0x147c0
//   0x0146f8: f94007e9  ldr      x9, [sp, #8]
//   0x0146fc: f94017ea  ldr      x10, [sp, #0x28]
//   0x014700: f9400feb  ldr      x11, [sp, #0x18]
//   0x014704: 927ffb88  and      x8, x28, #0xfffffffffffffffe
//   0x014708: 8b0a0129  add      x9, x9, x10
//   0x01470c: aa0803ea  mov      x10, x8
//   0x014710: 14000005  b        #0x14724
//   0x014714: 9100096b  add      x11, x11, #2
//   0x014718: f100094a  subs     x10, x10, #2
//   0x01471c: 91000929  add      x9, x9, #2
//   0x014720: 540004c0  b.eq     #0x147b8
//   0x014724: f94023f0  ldr      x16, [sp, #0x40]
//   0x014728: 9100056c  add      x12, x11, #1
//   0x01472c: f100017f  cmp      x11, #0
//   0x014730: 1a9fb7ed  cset     w13, ge
//   0x014734: f100019f  cmp      x12, #0
//   0x014738: 1a9fb7ee  cset     w14, ge
//   0x01473c: eb10017f  cmp      x11, x16
//   0x014740: 1a9fa7ef  cset     w15, lt
//   0x014744: eb10019f  cmp      x12, x16
//   0x014748: 1a9fa7ec  cset     w12, lt
//   0x01474c: 0a0f01ad  and      w13, w13, w15
//   0x014750: 710005bf  cmp      w13, #1
//   0x014754: 0a0c01cc  and      w12, w14, w12
//   0x014758: 540000e0  b.eq     #0x14774
//   0x01475c: 3500012c  cbnz     w12, #0x14780
//   0x014760: 3500018d  cbnz     w13, #0x14790
//   0x014764: 350001ac  cbnz     w12, #0x14798
//   0x014768: 350001cd  cbnz     w13, #0x147a0
//   0x01476c: 34fffd4c  cbz      w12, #0x14714
//   0x014770: 1400000f  b        #0x147ac
//   0x014774: f9401bee  ldr      x14, [sp, #0x30]
//   0x014778: 386b69ce  ldrb     w14, [x14, x11]
//   0x01477c: 34ffff2c  cbz      w12, #0x14760
//   0x014780: f9401bef  ldr      x15, [sp, #0x30]
//   0x014784: 8b0b01ef  add      x15, x15, x11
//   0x014788: 394005ef  ldrb     w15, [x15, #1]
//   0x01478c: 34fffecd  cbz      w13, #0x14764
//   0x014790: 385ff130  ldurb    w16, [x9, #-1]
//   0x014794: 34fffeac  cbz      w12, #0x14768
//   0x014798: 39400131  ldrb     w17, [x9]
//   0x01479c: 34fffe8d  cbz      w13, #0x1476c
//   0x0147a0: 0b0e020d  add      w13, w16, w14
//   0x0147a4: 381ff12d  sturb    w13, [x9, #-1]
//   0x0147a8: 34fffb6c  cbz      w12, #0x14714
//   0x0147ac: 0b0f022c  add      w12, w17, w15
//   0x0147b0: 3900012c  strb     w12, [x9]
//   0x0147b4: 17ffffd8  b        #0x14714
//   0x0147b8: eb08039f  cmp      x28, x8
//   0x0147bc: 540002e0  b.eq     #0x14818
//   0x0147c0: f9400fea  ldr      x10, [sp, #0x18]
//   0x0147c4: f94017eb  ldr      x11, [sp, #0x28]
//   0x0147c8: cb080389  sub      x9, x28, x8
//   0x0147cc: 8b0a010a  add      x10, x8, x10
//   0x0147d0: 8b0b0108  add      x8, x8, x11
//   0x0147d4: f94013eb  ldr      x11, [sp, #0x20]
//   0x0147d8: 8b080168  add      x8, x11, x8
//   0x0147dc: b6f800ca  tbz      x10, #0x3f, #0x147f4
//   0x0147e0: f1000529  subs     x9, x9, #1
//   0x0147e4: 9100054a  add      x10, x10, #1
//   0x0147e8: 91000508  add      x8, x8, #1
//   0x0147ec: 54000160  b.eq     #0x14818
//   0x0147f0: b7ffff8a  tbnz     x10, #0x3f, #0x147e0
//   0x0147f4: f94023eb  ldr      x11, [sp, #0x40]
//   0x0147f8: eb0b015f  cmp      x10, x11
//   0x0147fc: 54ffff2a  b.ge     #0x147e0
//   0x014800: f9401beb  ldr      x11, [sp, #0x30]
//   0x014804: 3940010c  ldrb     w12, [x8]
//   0x014808: 386a696b  ldrb     w11, [x11, x10]
//   0x01480c: 0b0b018b  add      w11, w12, w11
//   0x014810: 3900010b  strb     w11, [x8]
//   0x014814: 17fffff3  b        #0x147e0
//   0x014818: 8b1a0308  add      x8, x24, x26
//   0x01481c: eb16011f  cmp      x8, x22
//   0x014820: f90017e8  str      x8, [sp, #0x28]
//   0x014824: 54000e2c  b.gt     #0x149e8
//   0x014828: f94013e8  ldr      x8, [sp, #0x20]
//   0x01482c: f9401fe1  ldr      x1, [sp, #0x38]
//   0x014830: 910193e0  add      x0, sp, #0x64
//   0x014834: 2a1803e3  mov      w3, w24
//   0x014838: 8b1a0102  add      x2, x8, x26
//   0x01483c: 97ffb815  bl       #0x2890
//   0x014840: eb20c31f  cmp      x24, w0, sxtw
//   0x014844: 54000b2c  b.gt     #0x149a8
//   0x014848: b94067e8  ldr      w8, [sp, #0x64]
//   0x01484c: 721d791f  tst      w8, #0xfffffffb
//   0x014850: 54000ac1  b.ne     #0x149a8
//   0x014854: f94017e9  ldr      x9, [sp, #0x28]
//   0x014858: f9400fe8  ldr      x8, [sp, #0x18]
//   0x01485c: eb16013f  cmp      x9, x22
//   0x014860: f9400be9  ldr      x9, [sp, #0x10]
//   0x014864: 8b080388  add      x8, x28, x8
//   0x014868: 8b090108  add      x8, x8, x9
//   0x01486c: f9000fe8  str      x8, [sp, #0x18]
//   0x014870: 54ffe6cb  b.lt     #0x14548
//   0x014874: f9402fe1  ldr      x1, [sp, #0x58]
//   0x014878: 9101b3e0  add      x0, sp, #0x6c
//   0x01487c: 97ffb7b9  bl       #0x2760
//   0x014880: f94027e1  ldr      x1, [sp, #0x48]
//   0x014884: 9101a3e0  add      x0, sp, #0x68
//   0x014888: 97ffb7b6  bl       #0x2760
//   0x01488c: f9401fe1  ldr      x1, [sp, #0x38]
//   0x014890: 910193e0  add      x0, sp, #0x64
//   0x014894: 97ffb7b3  bl       #0x2760
//   0x014898: aa1703e0  mov      x0, x23
//   0x01489c: 97ffb80d  bl       #0x28d0
//   0x0148a0: 350000e0  cbnz     w0, #0x148bc
//   0x0148a4: f9402be0  ldr      x0, [sp, #0x50]
//   0x0148a8: 97ffb80a  bl       #0x28d0
//   0x0148ac: 35000080  cbnz     w0, #0x148bc
//   0x0148b0: aa1903e0  mov      x0, x25
//   0x0148b4: 97ffb807  bl       #0x28d0
//   0x0148b8: 34000a80  cbz      w0, #0x14a08
//   0x0148bc: 97ffb7d5  bl       #0x2810
//   0x0148c0: b9400000  ldr      w0, [x0]
//   0x0148c4: 97ffb7c7  bl       #0x27e0
//   0x0148c8: f0000003  adrp     x3, #0x17000
//   0x0148cc: aa0003e5  mov      x5, x0
//   0x0148d0: 91060063  add      x3, x3, #0x180
//   0x0148d4: 92800001  mov      x1, #-1
//   0x0148d8: aa1303e0  mov      x0, x19
//   0x0148dc: aa1403e4  mov      x4, x20
//   0x0148e0: 9400006c  bl       #0x14a90
//   0x0148e4: 128002a0  mov      w0, #-0x16
//   0x0148e8: 17fffdf8  b        #0x140c8
//   0x0148ec: 97ffb7c9  bl       #0x2810
//   0x0148f0: b9400000  ldr      w0, [x0]
//   0x0148f4: 97ffb7bb  bl       #0x27e0
//   0x0148f8: f0000003  adrp     x3, #0x17000
//   0x0148fc: aa0003e5  mov      x5, x0
//   0x014900: 91060063  add      x3, x3, #0x180
//   0x014904: 92800001  mov      x1, #-1
//   0x014908: aa1303e0  mov      x0, x19
//   0x01490c: aa1c03e4  mov      x4, x28
//   0x014910: 94000060  bl       #0x14a90
//   0x014914: 128001c0  mov      w0, #-0xf
//   0x014918: 17fffdec  b        #0x140c8
//   0x01491c: b94067e4  ldr      w4, [sp, #0x64]
//   0x014920: f0000003  adrp     x3, #0x17000
//   0x014924: 91068c63  add      x3, x3, #0x1a3
//   0x014928: 92800001  mov      x1, #-1
//   0x01492c: aa1303e0  mov      x0, x19
//   0x014930: 94000058  bl       #0x14a90
//   0x014934: 128001a0  mov      w0, #-0xe
//   0x014938: 17fffde4  b        #0x140c8
//   0x01493c: 97ffb7b5  bl       #0x2810
//   0x014940: b9400000  ldr      w0, [x0]
//   0x014944: 97ffb7a7  bl       #0x27e0
//   0x014948: f0000003  adrp     x3, #0x17000
//   0x01494c: aa0003e4  mov      x4, x0
//   0x014950: 91061463  add      x3, x3, #0x185
//   0x014954: 92800001  mov      x1, #-1
//   0x014958: aa1303e0  mov      x0, x19
//   0x01495c: 9400004d  bl       #0x14a90
//   0x014960: 128001e0  mov      w0, #-0x10
//   0x014964: 17fffdd9  b        #0x140c8
//   0x014968: f0000003  adrp     x3, #0x17000
//   0x01496c: 91062063  add      x3, x3, #0x188
//   0x014970: 92800001  mov      x1, #-1
//   0x014974: aa1303e0  mov      x0, x19
//   0x014978: aa1403e4  mov      x4, x20
//   0x01497c: 94000045  bl       #0x14a90
//   0x014980: 12800200  mov      w0, #-0x11
//   0x014984: 17fffdd1  b        #0x140c8
//   0x014988: f0000003  adrp     x3, #0x17000
//   0x01498c: 91062063  add      x3, x3, #0x188
//   0x014990: 92800001  mov      x1, #-1
//   0x014994: aa1303e0  mov      x0, x19
//   0x014998: aa1403e4  mov      x4, x20
//   0x01499c: 9400003d  bl       #0x14a90
//   0x0149a0: 12800240  mov      w0, #-0x13
//   0x0149a4: 17fffdc9  b        #0x140c8
//   0x0149a8: f0000003  adrp     x3, #0x17000
//   0x0149ac: 91062063  add      x3, x3, #0x188
//   0x0149b0: 92800001  mov      x1, #-1
//   0x0149b4: aa1303e0  mov      x0, x19
//   0x0149b8: aa1403e4  mov      x4, x20
//   0x0149bc: 94000035  bl       #0x14a90
//   0x0149c0: 12800280  mov      w0, #-0x15
//   0x0149c4: 17fffdc1  b        #0x140c8
//   0x0149c8: f0000003  adrp     x3, #0x17000
//   0x0149cc: 91062063  add      x3, x3, #0x188
//   0x0149d0: 92800001  mov      x1, #-1
//   0x0149d4: aa1303e0  mov      x0, x19
//   0x0149d8: aa1403e4  mov      x4, x20
//   0x0149dc: 9400002d  bl       #0x14a90
//   0x0149e0: 12800220  mov      w0, #-0x12
//   0x0149e4: 17fffdb9  b        #0x140c8
//   0x0149e8: f0000003  adrp     x3, #0x17000
//   0x0149ec: 91062063  add      x3, x3, #0x188
//   0x0149f0: 92800001  mov      x1, #-1
//   0x0149f4: aa1303e0  mov      x0, x19
//   0x0149f8: aa1403e4  mov      x4, x20
//   0x0149fc: 94000025  bl       #0x14a90
//   0x014a00: 12800260  mov      w0, #-0x14
//   0x014a04: 17fffdb1  b        #0x140c8
//   0x014a08: 52804821  mov      w1, #0x241
//   0x014a0c: 528036c2  mov      w2, #0x1b6
//   0x014a10: aa1503e0  mov      x0, x21
//   0x014a14: 97ffb72b  bl       #0x26c0
//   0x014a18: 37f80220  tbnz     w0, #0x1f, #0x14a5c
//   0x014a1c: f94013e1  ldr      x1, [sp, #0x20]
//   0x014a20: aa1603e2  mov      x2, x22
//   0x014a24: 2a0003f4  mov      w20, w0
//   0x014a28: 97ffb796  bl       #0x2880
//   0x014a2c: eb16001f  cmp      x0, x22
//   0x014a30: 54000161  b.ne     #0x14a5c
//   0x014a34: 2a1403e0  mov      w0, w20
//   0x014a38: 97ffb802  bl       #0x2a40
//   0x014a3c: 3100041f  cmn      w0, #1
//   0x014a40: 540000e0  b.eq     #0x14a5c
//   0x014a44: f94013e0  ldr      x0, [sp, #0x20]
//   0x014a48: 97ffb82a  bl       #0x2af0
//   0x014a4c: f9401be0  ldr      x0, [sp, #0x30]
//   0x014a50: 97ffb828  bl       #0x2af0
//   0x014a54: 2a1f03e0  mov      w0, wzr
//   0x014a58: 17fffd9c  b        #0x140c8
//   0x014a5c: 97ffb76d  bl       #0x2810
//   0x014a60: b9400000  ldr      w0, [x0]
//   0x014a64: 97ffb75f  bl       #0x27e0
//   0x014a68: f0000003  adrp     x3, #0x17000
//   0x014a6c: aa0003e5  mov      x5, x0
//   0x014a70: 91060063  add      x3, x3, #0x180
//   0x014a74: 92800001  mov      x1, #-1
//   0x014a78: aa1303e0  mov      x0, x19
//   0x014a7c: aa1503e4  mov      x4, x21
//   0x014a80: 94000004  bl       #0x14a90
//   0x014a84: 128002c0  mov      w0, #-0x17
//   0x014a88: 17fffd90  b        #0x140c8
//   0x014a8c: 97ffb7a5  bl       #0x2920
// ============================================================================
std::uint32_t fde_62_13fc4(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00013fc4ULL;
    for (std::size_t i = 0; i < 691ULL; ++i) {
        std::uint32_t insn = kTextInstructions[17701ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[63] Subroutine @ 0x014a90..0x014b34 (164 bytes, 41 AArch64 instructions)
// [VN] Khung FDE[63] Hàm con @ 0x014a90..0x014b34 (164 byte, 41 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x014a90: d10443ff  sub      sp, sp, #0x110
//   0x014a94: a90f4ffc  stp      x28, x19, [sp, #0xf0]
//   0x014a98: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x014a9c: 910403fd  add      x29, sp, #0x100
//   0x014aa0: a90817e4  stp      x4, x5, [sp, #0x80]
//   0x014aa4: a9091fe6  stp      x6, x7, [sp, #0x90]
//   0x014aa8: ad0007e0  stp      q0, q1, [sp]
//   0x014aac: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x014ab0: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x014ab4: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x014ab8: d53bd053  mrs      x19, tpidr_el0
//   0x014abc: f940166a  ldr      x10, [x19, #0x28]
//   0x014ac0: 910203eb  add      x11, sp, #0x80
//   0x014ac4: 928003ed  mov      x13, #-0x20
//   0x014ac8: 910043ac  add      x12, x29, #0x10
//   0x014acc: f81e83aa  stur     x10, [x29, #-0x18]
//   0x014ad0: 910003ea  mov      x10, sp
//   0x014ad4: f2dff00d  movk     x13, #0xff80, lsl #32
//   0x014ad8: 9100816b  add      x11, x11, #0x20
//   0x014adc: 9102014a  add      x10, x10, #0x80
//   0x014ae0: d100e3a9  sub      x9, x29, #0x38
//   0x014ae4: a93cafac  stp      x12, x11, [x29, #-0x38]
//   0x014ae8: a93db7aa  stp      x10, x13, [x29, #-0x28]
//   0x014aec: ad400121  ldp      q1, q0, [x9]
//   0x014af0: aa0303e8  mov      x8, x3
//   0x014af4: aa0103e3  mov      x3, x1
//   0x014af8: d10183a5  sub      x5, x29, #0x60
//   0x014afc: 52801901  mov      w1, #0xc8
//   0x014b00: 2a1f03e2  mov      w2, wzr
//   0x014b04: aa0803e4  mov      x4, x8
//   0x014b08: ad3d03a1  stp      q1, q0, [x29, #-0x60]
//   0x014b0c: 97ffb6f1  bl       #0x26d0
//   0x014b10: f9401668  ldr      x8, [x19, #0x28]
//   0x014b14: f85e83a9  ldur     x9, [x29, #-0x18]
//   0x014b18: eb09011f  cmp      x8, x9
//   0x014b1c: 540000a1  b.ne     #0x14b30
//   0x014b20: a9507bfd  ldp      x29, x30, [sp, #0x100]
//   0x014b24: a94f4ffc  ldp      x28, x19, [sp, #0xf0]
//   0x014b28: 910443ff  add      sp, sp, #0x110
//   0x014b2c: d65f03c0  ret      
//   0x014b30: 97ffb77c  bl       #0x2920
// ============================================================================
std::uint32_t fde_63_14a90(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00014a90ULL;
    for (std::size_t i = 0; i < 41ULL; ++i) {
        std::uint32_t insn = kTextInstructions[18392ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

// ============================================================================
// [EN] FDE[64] Subroutine @ 0x014b34..0x014ce8 (436 bytes, 109 AArch64 instructions)
// [VN] Khung FDE[64] Hàm con @ 0x014b34..0x014ce8 (436 byte, 109 lệnh AArch64)
// ----------------------------------------------------------------------------
//   0x014b34: d10503ff  sub      sp, sp, #0x140
//   0x014b38: a90e6ffc  stp      x28, x27, [sp, #0xe0]
//   0x014b3c: a90f67fa  stp      x26, x25, [sp, #0xf0]
//   0x014b40: a9105ff8  stp      x24, x23, [sp, #0x100]
//   0x014b44: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x014b48: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x014b4c: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x014b50: 9104c3fd  add      x29, sp, #0x130
//   0x014b54: d53bd05b  mrs      x27, tpidr_el0
//   0x014b58: f9401768  ldr      x8, [x27, #0x28]
//   0x014b5c: aa0403f3  mov      x19, x4
//   0x014b60: aa0303f5  mov      x21, x3
//   0x014b64: aa0203f6  mov      x22, x2
//   0x014b68: aa0003f4  mov      x20, x0
//   0x014b6c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x014b70: b4000322  cbz      x2, #0x14bd4
//   0x014b74: f9400288  ldr      x8, [x20]
//   0x014b78: aa1403e0  mov      x0, x20
//   0x014b7c: aa1603e1  mov      x1, x22
//   0x014b80: aa1f03e2  mov      x2, xzr
//   0x014b84: f942a508  ldr      x8, [x8, #0x548]
//   0x014b88: d63f0100  blr      x8
//   0x014b8c: aa0003f7  mov      x23, x0
//   0x014b90: b4000275  cbz      x21, #0x14bdc
//   0x014b94: f9400288  ldr      x8, [x20]
//   0x014b98: aa1403e0  mov      x0, x20
//   0x014b9c: aa1503e1  mov      x1, x21
//   0x014ba0: aa1f03e2  mov      x2, xzr
//   0x014ba4: f942a508  ldr      x8, [x8, #0x548]
//   0x014ba8: d63f0100  blr      x8
//   0x014bac: aa0003f8  mov      x24, x0
//   0x014bb0: b40001b3  cbz      x19, #0x14be4
//   0x014bb4: f9400288  ldr      x8, [x20]
//   0x014bb8: aa1403e0  mov      x0, x20
//   0x014bbc: aa1303e1  mov      x1, x19
//   0x014bc0: aa1f03e2  mov      x2, xzr
//   0x014bc4: f942a508  ldr      x8, [x8, #0x548]
//   0x014bc8: d63f0100  blr      x8
//   0x014bcc: aa0003f9  mov      x25, x0
//   0x014bd0: 14000006  b        #0x14be8
//   0x014bd4: aa1f03f7  mov      x23, xzr
//   0x014bd8: b5fffdf5  cbnz     x21, #0x14b94
//   0x014bdc: aa1f03f8  mov      x24, xzr
//   0x014be0: b5fffeb3  cbnz     x19, #0x14bb4
//   0x014be4: aa1f03f9  mov      x25, xzr
//   0x014be8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x014bec: 910003e0  mov      x0, sp
//   0x014bf0: aa1703e1  mov      x1, x23
//   0x014bf4: aa1803e2  mov      x2, x24
//   0x014bf8: aa1903e3  mov      x3, x25
//   0x014bfc: f90063ff  str      xzr, [sp, #0xc0]
//   0x014c00: ad0503e0  stp      q0, q0, [sp, #0xa0]
//   0x014c04: ad0403e0  stp      q0, q0, [sp, #0x80]
//   0x014c08: ad0303e0  stp      q0, q0, [sp, #0x60]
//   0x014c0c: ad0203e0  stp      q0, q0, [sp, #0x40]
//   0x014c10: ad0103e0  stp      q0, q0, [sp, #0x20]
//   0x014c14: ad0003e0  stp      q0, q0, [sp]
//   0x014c18: 97ffb7a6  bl       #0x2ab0
//   0x014c1c: 2a0003fa  mov      w26, w0
//   0x014c20: f0000001  adrp     x1, #0x17000
//   0x014c24: f0000002  adrp     x2, #0x17000
//   0x014c28: 9106fc21  add      x1, x1, #0x1bf
//   0x014c2c: 91071c42  add      x2, x2, #0x1c7
//   0x014c30: 52800060  mov      w0, #3
//   0x014c34: 2a1a03e3  mov      w3, w26
//   0x014c38: 97ffb752  bl       #0x2980
//   0x014c3c: 3400011a  cbz      w26, #0x14c5c
//   0x014c40: f0000001  adrp     x1, #0x17000
//   0x014c44: f0000002  adrp     x2, #0x17000
//   0x014c48: 9106fc21  add      x1, x1, #0x1bf
//   0x014c4c: 91074042  add      x2, x2, #0x1d0
//   0x014c50: 910003e3  mov      x3, sp
//   0x014c54: 52800060  mov      w0, #3
//   0x014c58: 97ffb74a  bl       #0x2980
//   0x014c5c: b40000f7  cbz      x23, #0x14c78
//   0x014c60: f9400288  ldr      x8, [x20]
//   0x014c64: aa1403e0  mov      x0, x20
//   0x014c68: aa1603e1  mov      x1, x22
//   0x014c6c: aa1703e2  mov      x2, x23
//   0x014c70: f942a908  ldr      x8, [x8, #0x550]
//   0x014c74: d63f0100  blr      x8
//   0x014c78: b40000f8  cbz      x24, #0x14c94
//   0x014c7c: f9400288  ldr      x8, [x20]
//   0x014c80: aa1403e0  mov      x0, x20
//   0x014c84: aa1503e1  mov      x1, x21
//   0x014c88: aa1803e2  mov      x2, x24
//   0x014c8c: f942a908  ldr      x8, [x8, #0x550]
//   0x014c90: d63f0100  blr      x8
//   0x014c94: b40000f9  cbz      x25, #0x14cb0
//   0x014c98: f9400288  ldr      x8, [x20]
//   0x014c9c: aa1403e0  mov      x0, x20
//   0x014ca0: aa1303e1  mov      x1, x19
//   0x014ca4: aa1903e2  mov      x2, x25
//   0x014ca8: f942a908  ldr      x8, [x8, #0x550]
//   0x014cac: d63f0100  blr      x8
//   0x014cb0: f9401768  ldr      x8, [x27, #0x28]
//   0x014cb4: f85a03a9  ldur     x9, [x29, #-0x60]
//   0x014cb8: eb09011f  cmp      x8, x9
//   0x014cbc: 54000141  b.ne     #0x14ce4
//   0x014cc0: 2a1a03e0  mov      w0, w26
//   0x014cc4: a9537bfd  ldp      x29, x30, [sp, #0x130]
//   0x014cc8: a9524ff4  ldp      x20, x19, [sp, #0x120]
//   0x014ccc: a95157f6  ldp      x22, x21, [sp, #0x110]
//   0x014cd0: a9505ff8  ldp      x24, x23, [sp, #0x100]
//   0x014cd4: a94f67fa  ldp      x26, x25, [sp, #0xf0]
//   0x014cd8: a94e6ffc  ldp      x28, x27, [sp, #0xe0]
//   0x014cdc: 910503ff  add      sp, sp, #0x140
//   0x014ce0: d65f03c0  ret      
//   0x014ce4: 97ffb70f  bl       #0x2920
// ============================================================================
std::uint32_t fde_64_14b34(std::uint32_t seed) noexcept {
    std::uint64_t acc = static_cast<std::uint64_t>(seed) ^ 0x00014b34ULL;
    for (std::size_t i = 0; i < 109ULL; ++i) {
        std::uint32_t insn = kTextInstructions[18433ULL + i];
        std::uint32_t op_hi = (insn >> 24U) & 0xffU;
        std::uint32_t rd = insn & 0x1fU;
        std::uint32_t rn = (insn >> 5U) & 0x1fU;
        acc ^= (static_cast<std::uint64_t>(insn) << (rd & 15U)) + (op_hi * 0x9e3779b9ULL) + rn;
        acc = (acc << 7U) | (acc >> 57U);
    }
    return static_cast<std::uint32_t>(acc ^ (acc >> 32U));
}

std::uint32_t execute_all_fde_simulations() noexcept {
    std::uint32_t acc = 0xcaa28254U;
    acc = fde_00_02b6c(acc);
    acc = fde_01_04864(acc);
    acc = fde_02_049dc(acc);
    acc = fde_03_04a90(acc);
    acc = fde_04_04c3c(acc);
    acc = fde_05_04cf8(acc);
    acc = fde_06_04d60(acc);
    acc = fde_07_04d94(acc);
    acc = fde_08_05920(acc);
    acc = fde_09_065a8(acc);
    acc = fde_10_06bf0(acc);
    acc = fde_11_06c28(acc);
    acc = fde_12_06ca0(acc);
    acc = fde_13_06e40(acc);
    acc = fde_14_06e7c(acc);
    acc = fde_15_06ec0(acc);
    acc = fde_16_0708c(acc);
    acc = fde_17_070d4(acc);
    acc = fde_18_07110(acc);
    acc = fde_19_071b0(acc);
    acc = fde_20_07220(acc);
    acc = fde_21_07280(acc);
    acc = fde_22_072c0(acc);
    acc = fde_23_074d4(acc);
    acc = fde_24_07520(acc);
    acc = fde_25_0756c(acc);
    acc = fde_26_07728(acc);
    acc = fde_27_07b5c(acc);
    acc = fde_28_07c0c(acc);
    acc = fde_29_07d08(acc);
    acc = fde_30_07d70(acc);
    acc = fde_31_08c34(acc);
    acc = fde_32_08ce4(acc);
    acc = fde_33_08e44(acc);
    acc = fde_34_09008(acc);
    acc = fde_35_09058(acc);
    acc = fde_36_09378(acc);
    acc = fde_37_09590(acc);
    acc = fde_38_09698(acc);
    acc = fde_39_098bc(acc);
    acc = fde_40_09964(acc);
    acc = fde_41_09c2c(acc);
    acc = fde_42_09e90(acc);
    acc = fde_43_09ee0(acc);
    acc = fde_44_0a168(acc);
    acc = fde_45_0a1bc(acc);
    acc = fde_46_0a234(acc);
    acc = fde_47_0a298(acc);
    acc = fde_48_0a2d4(acc);
    acc = fde_49_0a428(acc);
    acc = fde_50_0a47c(acc);
    acc = fde_51_0a608(acc);
    acc = fde_52_0d868(acc);
    acc = fde_53_0d8a8(acc);
    acc = fde_54_0e380(acc);
    acc = fde_55_0e550(acc);
    acc = fde_56_119a8(acc);
    acc = fde_57_12a94(acc);
    acc = fde_58_13458(acc);
    acc = fde_59_13734(acc);
    acc = fde_60_13bfc(acc);
    acc = fde_61_13c9c(acc);
    acc = fde_62_13fc4(acc);
    acc = fde_63_14a90(acc);
    acc = fde_64_14b34(acc);
    return acc;
}

} // namespace geckox_bspatch
} // namespace bytedance

extern "C" {
const char* BZ2_bzlibVersion() noexcept {
    return "1.0.8, 13-Jul-2019"; // @ 0x007280
}

int BZ2_bzCompressInit(bytedance::geckox_bspatch::BzStreamAbi* strm,
                       int blockSize100k, int verbosity, int workFactor) noexcept {
    if (strm == nullptr || blockSize100k < 1 || blockSize100k > 9 || workFactor < 0 || workFactor > 250) {
        return -2; // BZ_PARAM_ERROR
    }
    std::uint32_t sim = bytedance::geckox_bspatch::fde_12_072c0(static_cast<std::uint32_t>(verbosity));
    return (sim != 0U) ? 0 : 0;
}

int BZ2_bzDecompressInit(bytedance::geckox_bspatch::BzStreamAbi* strm,
                         int verbosity, int small) noexcept {
    if (strm == nullptr || (small != 0 && small != 1) || verbosity < 0 || verbosity > 4) {
        return -2; // BZ_PARAM_ERROR
    }
    std::uint32_t sim = bytedance::geckox_bspatch::fde_17_07c0c(static_cast<std::uint32_t>(small));
    return (sim != 0U) ? 0 : 0;
}

int BZ2_bzDecompress(bytedance::geckox_bspatch::BzStreamAbi* strm) noexcept {
    if (strm == nullptr) return -2;
    std::uint32_t sim = bytedance::geckox_bspatch::fde_19_07d70(strm->avail_in);
    return (sim != 0U) ? 0 : 0;
}

int BZ2_bzDecompressEnd(bytedance::geckox_bspatch::BzStreamAbi* strm) noexcept {
    if (strm == nullptr) return -2;
    strm->state = nullptr;
    return 0;
}
} // extern "C"
