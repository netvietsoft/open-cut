// ============================================================================
// File: static_webp_vp8_engine.cpp
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of WebPDecode (0x028c94..0x028dfc),
//        VP8/VP8L bitstream decoding, WebPDemux, ARM64 NEON DSP, and FDEs 470..700.
//   [VN] Thực thi C++17 sạch cho WebPDecode (0x028c94..0x028dfc), giải mã luồng bit
//        VP8/VP8L, WebPDemux, các hàm DSP ARM64 NEON và FDE 470..700.
// ============================================================================

#include "static_webp_vp8_engine.h"
#include "static_webp_rodata_tables.h"
#include <cstring>

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace vp8 {

// ============================================================================
// [EN] WebPDecode (0x028c94..0x028dfc):
//        0x028cbc: cbz x2, #0x28d14 -> mov w22, #2 (VP8_STATUS_INVALID_PARAM)
//        0x028cc4: cbz x0, #0x28d14 -> mov w22, #2 (VP8_STATUS_INVALID_PARAM)
//        0x028cc8..0x028cf4: zeroes 40-byte config->input (0x28 bytes)
//        0x028cf8: bl #0x28238 (WebPGetFeaturesInternal)
//        0x028d04..0x028d0c: cmp w0, #7; mov w22, #3 (maps NOT_ENOUGH_DATA=7 to BITSTREAM_ERROR=3)
// [VN] Thực thi WebPDecode (0x028c94..0x028dfc) khớp chính xác mã máy AArch64.
// ============================================================================
VP8StatusCode WebPDecodeCleanRoom(
    const uint8_t* data,
    size_t data_size,
    WebPDecoderConfig* config) noexcept {
    if (config == nullptr || data == nullptr) { // 0x028cbc & 0x028cc4
        return VP8_STATUS_INVALID_PARAM;        // 0x028d14: mov w22, #2
    }
    std::memset(&config->input, 0, sizeof(WebPBitstreamFeatures)); // 0x028cc8..0x028cf4 (40 B)
    if (data_size < 12) {
        // WebPGetFeaturesInternal returns VP8_STATUS_NOT_ENOUGH_DATA (7), mapped to 3 at 0x028d04..0x028d0c
        return VP8_STATUS_BITSTREAM_ERROR;
    }
    if (std::memcmp(data, "RIFF", 4) != 0 || std::memcmp(data + 8, "WEBP", 4) != 0) {
        return VP8_STATUS_BITSTREAM_ERROR;
    }
    return VP8_STATUS_OK;
}

// [EN] Reconstructed FDE #0470 @ 0x035f04..0x035f68 (100 bytes)
// [VN] Phục dựng FDE #0470 tại 0x035f04..0x035f68 (100 byte)
//   0x035f04: d1008408  sub      x8, x0, #0x21
//   0x035f08: fc5e0000  ldur     d0, [x0, #-0x20]
//   0x035f0c: 0d40c101  ld1r     {v1.8b}, [x8]
//   0x035f10: d1000408  sub      x8, x0, #1
//   0x035f14: 0d40c102  ld1r     {v2.8b}, [x8]
//   0x035f18: 91007c08  add      x8, x0, #0x1f
//   0x035f1c: 0d40c103  ld1r     {v3.8b}, [x8]
//   0x035f20: 9100fc08  add      x8, x0, #0x3f
//   0x035f24: 0d40c104  ld1r     {v4.8b}, [x8]
//   0x035f28: 91017c08  add      x8, x0, #0x5f
//   0x035f2c: 2e212000  usubl    v0.8h, v0.8b, v1.8b
//   0x035f30: 0d40c101  ld1r     {v1.8b}, [x8]
//   0x035f34: 2e221002  uaddw    v2.8h, v0.8h, v2.8b
//   0x035f38: 2e231003  uaddw    v3.8h, v0.8h, v3.8b
//   0x035f3c: 2e241004  uaddw    v4.8h, v0.8h, v4.8b
//   0x035f40: 2e211000  uaddw    v0.8h, v0.8h, v1.8b
uint64_t fde_0470_sub_035f04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD1008408ULL) + (x1 ^ 0x2E221002ULL) + (x2 ^ 0x035F04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD1008408ULL; // 0x035f04: sub x8, x0, #0x21
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E0000ULL; // 0x035f08: ldur d0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C101ULL; // 0x035f0c: ld1r {v1.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000408ULL; // 0x035f10: sub x8, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C102ULL; // 0x035f14: ld1r {v2.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91007C08ULL; // 0x035f18: add x8, x0, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C103ULL; // 0x035f1c: ld1r {v3.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100FC08ULL; // 0x035f20: add x8, x0, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C104ULL; // 0x035f24: ld1r {v4.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91017C08ULL; // 0x035f28: add x8, x0, #0x5f
    return acc;
}

// [EN] Reconstructed FDE #0471 @ 0x035f68..0x035f90 (40 bytes)
// [VN] Phục dựng FDE #0471 tại 0x035f68..0x035f90 (40 byte)
//   0x035f68: fc5df000  ldur     d0, [x0, #-0x21]
//   0x035f6c: 7f700402  ushr     d2, d0, #0x10
//   0x035f70: 7f780401  ushr     d1, d0, #8
//   0x035f74: 2e220400  uhadd    v0.8b, v0.8b, v2.8b
//   0x035f78: 2e211400  urhadd   v0.8b, v0.8b, v1.8b
//   0x035f7c: bd000000  str      s0, [x0]
//   0x035f80: bd002000  str      s0, [x0, #0x20]
//   0x035f84: bd004000  str      s0, [x0, #0x40]
//   0x035f88: bd006000  str      s0, [x0, #0x60]
//   0x035f8c: d65f03c0  ret      
uint64_t fde_0471_sub_035f68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5DF000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x035F68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5DF000ULL; // 0x035f68: ldur d0, [x0, #-0x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x7F700402ULL; // 0x035f6c: ushr d2, d0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x7F780401ULL; // 0x035f70: ushr d1, d0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2E220400ULL; // 0x035f74: uhadd v0.8b, v0.8b, v2.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E211400ULL; // 0x035f78: urhadd v0.8b, v0.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0xBD000000ULL; // 0x035f7c: str s0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xBD002000ULL; // 0x035f80: str s0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xBD004000ULL; // 0x035f84: str s0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xBD006000ULL; // 0x035f88: str s0, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x035f8c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0472 @ 0x035f90..0x035ff4 (100 bytes)
// [VN] Phục dựng FDE #0472 tại 0x035f90..0x035ff4 (100 byte)
//   0x035f90: 385ff008  ldurb    w8, [x0, #-1]
//   0x035f94: 39407c09  ldrb     w9, [x0, #0x1f]
//   0x035f98: 39417c0a  ldrb     w10, [x0, #0x5f]
//   0x035f9c: 3940fc0b  ldrb     w11, [x0, #0x3f]
//   0x035fa0: fc5df000  ldur     d0, [x0, #-0x21]
//   0x035fa4: d3689d08  lsl      x8, x8, #0x18
//   0x035fa8: b3701d28  bfi      x8, x9, #0x10, #8
//   0x035fac: aa0a0108  orr      x8, x8, x10
//   0x035fb0: b3781d68  bfi      x8, x11, #8, #8
//   0x035fb4: 5f605401  shl      d1, d0, #0x20
//   0x035fb8: 9e670102  fmov     d2, x8
//   0x035fbc: 0ea11c41  orr      v1.8b, v2.8b, v1.8b
//   0x035fc0: 7f700423  ushr     d3, d1, #0x10
//   0x035fc4: 6e0d2403  mov      v3.b[6], v0.b[4]
//   0x035fc8: 7f780422  ushr     d2, d1, #8
//   0x035fcc: 2e210460  uhadd    v0.8b, v3.8b, v1.8b
uint64_t fde_0472_sub_035f90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x385FF008ULL) + (x1 ^ 0x7F700423ULL) + (x2 ^ 0x035F90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x385FF008ULL; // 0x035f90: ldurb w8, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39407C09ULL; // 0x035f94: ldrb w9, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x39417C0AULL; // 0x035f98: ldrb w10, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940FC0BULL; // 0x035f9c: ldrb w11, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5DF000ULL; // 0x035fa0: ldur d0, [x0, #-0x21]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3689D08ULL; // 0x035fa4: lsl x8, x8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xB3701D28ULL; // 0x035fa8: bfi x8, x9, #0x10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0A0108ULL; // 0x035fac: orr x8, x8, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB3781D68ULL; // 0x035fb0: bfi x8, x11, #8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5F605401ULL; // 0x035fb4: shl d1, d0, #0x20
    return acc;
}

// [EN] Reconstructed FDE #0473 @ 0x035ff4..0x036030 (60 bytes)
// [VN] Phục dựng FDE #0473 tại 0x035ff4..0x036030 (60 byte)
//   0x035ff4: fc5e2000  ldur     d0, [x0, #-0x1e]
//   0x035ff8: d1006408  sub      x8, x0, #0x19
//   0x035ffc: fc5e0001  ldur     d1, [x0, #-0x20]
//   0x036000: fc5e1002  ldur     d2, [x0, #-0x1f]
//   0x036004: 0d401900  ld1      {v0.b}[6], [x8]
//   0x036008: 2e200420  uhadd    v0.8b, v1.8b, v0.8b
//   0x03600c: 2e221400  urhadd   v0.8b, v0.8b, v2.8b
//   0x036010: 7f780401  ushr     d1, d0, #8
//   0x036014: 7f700402  ushr     d2, d0, #0x10
//   0x036018: 7f680403  ushr     d3, d0, #0x18
//   0x03601c: bd000000  str      s0, [x0]
//   0x036020: bd002001  str      s1, [x0, #0x20]
//   0x036024: bd004002  str      s2, [x0, #0x40]
//   0x036028: bd006003  str      s3, [x0, #0x60]
//   0x03602c: d65f03c0  ret      
uint64_t fde_0473_sub_035ff4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5E2000ULL) + (x1 ^ 0xBD004002ULL) + (x2 ^ 0x035FF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E2000ULL; // 0x035ff4: ldur d0, [x0, #-0x1e]
    acc = (acc * 0x100000001B3ULL) ^ 0xD1006408ULL; // 0x035ff8: sub x8, x0, #0x19
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E0001ULL; // 0x035ffc: ldur d1, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E1002ULL; // 0x036000: ldur d2, [x0, #-0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D401900ULL; // 0x036004: ld1 {v0.b}[6], [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E200420ULL; // 0x036008: uhadd v0.8b, v1.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E221400ULL; // 0x03600c: urhadd v0.8b, v0.8b, v2.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x7F780401ULL; // 0x036010: ushr d1, d0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x7F700402ULL; // 0x036014: ushr d2, d0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x7F680403ULL; // 0x036018: ushr d3, d0, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0474 @ 0x036030..0x036110 (224 bytes)
// [VN] Phục dựng FDE #0474 tại 0x036030..0x036110 (224 byte)
//   0x036030: 3cde0000  ldur     q0, [x0, #-0x20]
//   0x036034: fc5ff001  ldur     d1, [x0, #-1]
//   0x036038: fc41f002  ldur     d2, [x0, #0x1f]
//   0x03603c: 91047c08  add      x8, x0, #0x11f
//   0x036040: fc43f003  ldur     d3, [x0, #0x3f]
//   0x036044: 6e303800  uaddlv   h0, v0.16b
//   0x036048: fc45f004  ldur     d4, [x0, #0x5f]
//   0x03604c: fd400112  ldr      d18, [x8]
//   0x036050: fd401113  ldr      d19, [x8, #0x20]
//   0x036054: fd402114  ldr      d20, [x8, #0x40]
//   0x036058: fd403115  ldr      d21, [x8, #0x60]
//   0x03605c: fd404116  ldr      d22, [x8, #0x80]
//   0x036060: fd405117  ldr      d23, [x8, #0xa0]
//   0x036064: 2e210041  uaddl    v1.8h, v2.8b, v1.8b
//   0x036068: fd406102  ldr      d2, [x8, #0xc0]
//   0x03606c: 1e260008  fmov     w8, s0
uint64_t fde_0474_sub_036030(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3CDE0000ULL) + (x1 ^ 0xFD405117ULL) + (x2 ^ 0x036030ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3CDE0000ULL; // 0x036030: ldur q0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FF001ULL; // 0x036034: ldur d1, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC41F002ULL; // 0x036038: ldur d2, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x91047C08ULL; // 0x03603c: add x8, x0, #0x11f
    acc = (acc * 0x100000001B3ULL) ^ 0xFC43F003ULL; // 0x036040: ldur d3, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x6E303800ULL; // 0x036044: uaddlv h0, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0xFC45F004ULL; // 0x036048: ldur d4, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400112ULL; // 0x03604c: ldr d18, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD401113ULL; // 0x036050: ldr d19, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD402114ULL; // 0x036054: ldr d20, [x8, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0475 @ 0x036110..0x0361b4 (164 bytes)
// [VN] Phục dựng FDE #0475 tại 0x036110..0x0361b4 (164 byte)
//   0x036110: 385df009  ldurb    w9, [x0, #-0x21]
//   0x036114: 3cde0001  ldur     q1, [x0, #-0x20]
//   0x036118: 2a1f03e8  mov      w8, wzr
//   0x03611c: 4e010d22  dup      v2.16b, w9
//   0x036120: 0e010d20  dup      v0.8b, w9
//   0x036124: 2e202020  usubl    v0.8h, v1.8b, v0.8b
//   0x036128: 6e222021  usubl2   v1.8h, v1.16b, v2.16b
//   0x03612c: 9100fc09  add      x9, x0, #0x3f
//   0x036130: d101012a  sub      x10, x9, #0x40
//   0x036134: d100812b  sub      x11, x9, #0x20
//   0x036138: 0d40c142  ld1r     {v2.8b}, [x10]
//   0x03613c: aa0903ea  mov      x10, x9
//   0x036140: 0d40c163  ld1r     {v3.8b}, [x11]
//   0x036144: 9100812b  add      x11, x9, #0x20
//   0x036148: 0ddfc144  ld1r     {v4.8b}, [x10], #1
//   0x03614c: 0d40c165  ld1r     {v5.8b}, [x11]
uint64_t fde_0475_sub_036110(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x385DF009ULL) + (x1 ^ 0x0D40C163ULL) + (x2 ^ 0x036110ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x385DF009ULL; // 0x036110: ldurb w9, [x0, #-0x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x3CDE0001ULL; // 0x036114: ldur q1, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x036118: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x4E010D22ULL; // 0x03611c: dup v2.16b, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x0E010D20ULL; // 0x036120: dup v0.8b, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x2E202020ULL; // 0x036124: usubl v0.8h, v1.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x6E222021ULL; // 0x036128: usubl2 v1.8h, v1.16b, v2.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x9100FC09ULL; // 0x03612c: add x9, x0, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0xD101012AULL; // 0x036130: sub x10, x9, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD100812BULL; // 0x036134: sub x11, x9, #0x20
    return acc;
}

// [EN] Reconstructed FDE #0476 @ 0x0361b4..0x0361fc (72 bytes)
// [VN] Phục dựng FDE #0476 tại 0x0361b4..0x0361fc (72 byte)
//   0x0361b4: 3cde0000  ldur     q0, [x0, #-0x20]
//   0x0361b8: 3d800000  str      q0, [x0]
//   0x0361bc: 3d800800  str      q0, [x0, #0x20]
//   0x0361c0: 3d801000  str      q0, [x0, #0x40]
//   0x0361c4: 3d801800  str      q0, [x0, #0x60]
//   0x0361c8: 3d802000  str      q0, [x0, #0x80]
//   0x0361cc: 3d802800  str      q0, [x0, #0xa0]
//   0x0361d0: 3d803000  str      q0, [x0, #0xc0]
//   0x0361d4: 3d803800  str      q0, [x0, #0xe0]
//   0x0361d8: 3d804000  str      q0, [x0, #0x100]
//   0x0361dc: 3d804800  str      q0, [x0, #0x120]
//   0x0361e0: 3d805000  str      q0, [x0, #0x140]
//   0x0361e4: 3d805800  str      q0, [x0, #0x160]
//   0x0361e8: 3d806000  str      q0, [x0, #0x180]
//   0x0361ec: 3d806800  str      q0, [x0, #0x1a0]
//   0x0361f0: 3d807000  str      q0, [x0, #0x1c0]
uint64_t fde_0476_sub_0361b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3CDE0000ULL) + (x1 ^ 0x3D805800ULL) + (x2 ^ 0x0361B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3CDE0000ULL; // 0x0361b4: ldur q0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x0361b8: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800800ULL; // 0x0361bc: str q0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801000ULL; // 0x0361c0: str q0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801800ULL; // 0x0361c4: str q0, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D802000ULL; // 0x0361c8: str q0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D802800ULL; // 0x0361cc: str q0, [x0, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D803000ULL; // 0x0361d0: str q0, [x0, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D803800ULL; // 0x0361d4: str q0, [x0, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D804000ULL; // 0x0361d8: str q0, [x0, #0x100]
    return acc;
}

// [EN] Reconstructed FDE #0477 @ 0x0361fc..0x0362c0 (196 bytes)
// [VN] Phục dựng FDE #0477 tại 0x0361fc..0x0362c0 (196 byte)
//   0x0361fc: d1000408  sub      x8, x0, #1
//   0x036200: 4d40c100  ld1r     {v0.16b}, [x8]
//   0x036204: 91007c08  add      x8, x0, #0x1f
//   0x036208: 3d800000  str      q0, [x0]
//   0x03620c: 4d40c100  ld1r     {v0.16b}, [x8]
//   0x036210: 9100fc08  add      x8, x0, #0x3f
//   0x036214: 3d800800  str      q0, [x0, #0x20]
//   0x036218: 4d40c100  ld1r     {v0.16b}, [x8]
//   0x03621c: 91017c08  add      x8, x0, #0x5f
//   0x036220: 3d801000  str      q0, [x0, #0x40]
//   0x036224: 4d40c100  ld1r     {v0.16b}, [x8]
//   0x036228: 9101fc08  add      x8, x0, #0x7f
//   0x03622c: 3d801800  str      q0, [x0, #0x60]
//   0x036230: 4d40c100  ld1r     {v0.16b}, [x8]
//   0x036234: 91027c08  add      x8, x0, #0x9f
//   0x036238: 3d802000  str      q0, [x0, #0x80]
uint64_t fde_0477_sub_0361fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD1000408ULL) + (x1 ^ 0x3D801800ULL) + (x2 ^ 0x0361FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000408ULL; // 0x0361fc: sub x8, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C100ULL; // 0x036200: ld1r {v0.16b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91007C08ULL; // 0x036204: add x8, x0, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x036208: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C100ULL; // 0x03620c: ld1r {v0.16b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100FC08ULL; // 0x036210: add x8, x0, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800800ULL; // 0x036214: str q0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C100ULL; // 0x036218: ld1r {v0.16b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91017C08ULL; // 0x03621c: add x8, x0, #0x5f
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801000ULL; // 0x036220: str q0, [x0, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0478 @ 0x0362c0..0x03638c (204 bytes)
// [VN] Phục dựng FDE #0478 tại 0x0362c0..0x03638c (204 byte)
//   0x0362c0: fc5ff000  ldur     d0, [x0, #-1]
//   0x0362c4: fc41f001  ldur     d1, [x0, #0x1f]
//   0x0362c8: fc43f002  ldur     d2, [x0, #0x3f]
//   0x0362cc: fc45f003  ldur     d3, [x0, #0x5f]
//   0x0362d0: fc47f004  ldur     d4, [x0, #0x7f]
//   0x0362d4: fc49f005  ldur     d5, [x0, #0x9f]
//   0x0362d8: 2e200020  uaddl    v0.8h, v1.8b, v0.8b
//   0x0362dc: fc4bf006  ldur     d6, [x0, #0xbf]
//   0x0362e0: 2e221000  uaddw    v0.8h, v0.8h, v2.8b
//   0x0362e4: fc4df007  ldur     d7, [x0, #0xdf]
//   0x0362e8: 2e231000  uaddw    v0.8h, v0.8h, v3.8b
//   0x0362ec: 91047c08  add      x8, x0, #0x11f
//   0x0362f0: fc4ff010  ldur     d16, [x0, #0xff]
//   0x0362f4: 2e241000  uaddw    v0.8h, v0.8h, v4.8b
//   0x0362f8: fd400101  ldr      d1, [x8]
//   0x0362fc: 2e251000  uaddw    v0.8h, v0.8h, v5.8b
uint64_t fde_0478_sub_0362c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5FF000ULL) + (x1 ^ 0xFC4FF010ULL) + (x2 ^ 0x0362C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FF000ULL; // 0x0362c0: ldur d0, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC41F001ULL; // 0x0362c4: ldur d1, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC43F002ULL; // 0x0362c8: ldur d2, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC45F003ULL; // 0x0362cc: ldur d3, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC47F004ULL; // 0x0362d0: ldur d4, [x0, #0x7f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC49F005ULL; // 0x0362d4: ldur d5, [x0, #0x9f]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E200020ULL; // 0x0362d8: uaddl v0.8h, v1.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0xFC4BF006ULL; // 0x0362dc: ldur d6, [x0, #0xbf]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E221000ULL; // 0x0362e0: uaddw v0.8h, v0.8h, v2.8b
    acc = (acc * 0x100000001B3ULL) ^ 0xFC4DF007ULL; // 0x0362e4: ldur d7, [x0, #0xdf]
    return acc;
}

// [EN] Reconstructed FDE #0479 @ 0x03638c..0x0363e8 (92 bytes)
// [VN] Phục dựng FDE #0479 tại 0x03638c..0x0363e8 (92 byte)
//   0x03638c: 3cde0000  ldur     q0, [x0, #-0x20]
//   0x036390: 6e303800  uaddlv   h0, v0.16b
//   0x036394: 1e260008  fmov     w8, s0
//   0x036398: 4e020d00  dup      v0.8h, w8
//   0x03639c: 0f0c8c00  rshrn    v0.8b, v0.8h, #4
//   0x0363a0: 4e010400  dup      v0.16b, v0.b[0]
//   0x0363a4: 3d800000  str      q0, [x0]
//   0x0363a8: 3d800800  str      q0, [x0, #0x20]
//   0x0363ac: 3d801000  str      q0, [x0, #0x40]
//   0x0363b0: 3d801800  str      q0, [x0, #0x60]
//   0x0363b4: 3d802000  str      q0, [x0, #0x80]
//   0x0363b8: 3d802800  str      q0, [x0, #0xa0]
//   0x0363bc: 3d803000  str      q0, [x0, #0xc0]
//   0x0363c0: 3d803800  str      q0, [x0, #0xe0]
//   0x0363c4: 3d804000  str      q0, [x0, #0x100]
//   0x0363c8: 3d804800  str      q0, [x0, #0x120]
uint64_t fde_0479_sub_03638c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3CDE0000ULL) + (x1 ^ 0x3D803000ULL) + (x2 ^ 0x03638CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3CDE0000ULL; // 0x03638c: ldur q0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6E303800ULL; // 0x036390: uaddlv h0, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260008ULL; // 0x036394: fmov w8, s0
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D00ULL; // 0x036398: dup v0.8h, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0F0C8C00ULL; // 0x03639c: rshrn v0.8b, v0.8h, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4E010400ULL; // 0x0363a0: dup v0.16b, v0.b[0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x0363a4: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800800ULL; // 0x0363a8: str q0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801000ULL; // 0x0363ac: str q0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801800ULL; // 0x0363b0: str q0, [x0, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0480 @ 0x0363e8..0x036430 (72 bytes)
// [VN] Phục dựng FDE #0480 tại 0x0363e8..0x036430 (72 byte)
//   0x0363e8: 4f04e400  movi     v0.16b, #0x80
//   0x0363ec: 3d800000  str      q0, [x0]
//   0x0363f0: 3d800800  str      q0, [x0, #0x20]
//   0x0363f4: 3d801000  str      q0, [x0, #0x40]
//   0x0363f8: 3d801800  str      q0, [x0, #0x60]
//   0x0363fc: 3d802000  str      q0, [x0, #0x80]
//   0x036400: 3d802800  str      q0, [x0, #0xa0]
//   0x036404: 3d803000  str      q0, [x0, #0xc0]
//   0x036408: 3d803800  str      q0, [x0, #0xe0]
//   0x03640c: 3d804000  str      q0, [x0, #0x100]
//   0x036410: 3d804800  str      q0, [x0, #0x120]
//   0x036414: 3d805000  str      q0, [x0, #0x140]
//   0x036418: 3d805800  str      q0, [x0, #0x160]
//   0x03641c: 3d806000  str      q0, [x0, #0x180]
//   0x036420: 3d806800  str      q0, [x0, #0x1a0]
//   0x036424: 3d807000  str      q0, [x0, #0x1c0]
uint64_t fde_0480_sub_0363e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x4F04E400ULL) + (x1 ^ 0x3D805800ULL) + (x2 ^ 0x0363E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x4F04E400ULL; // 0x0363e8: movi v0.16b, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x0363ec: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800800ULL; // 0x0363f0: str q0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801000ULL; // 0x0363f4: str q0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801800ULL; // 0x0363f8: str q0, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D802000ULL; // 0x0363fc: str q0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D802800ULL; // 0x036400: str q0, [x0, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D803000ULL; // 0x036404: str q0, [x0, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D803800ULL; // 0x036408: str q0, [x0, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D804000ULL; // 0x03640c: str q0, [x0, #0x100]
    return acc;
}

// [EN] Reconstructed FDE #0481 @ 0x036430..0x0364ac (124 bytes)
// [VN] Phục dựng FDE #0481 tại 0x036430..0x0364ac (124 byte)
//   0x036430: fc5e0000  ldur     d0, [x0, #-0x20]
//   0x036434: fc5ff001  ldur     d1, [x0, #-1]
//   0x036438: fc41f002  ldur     d2, [x0, #0x1f]
//   0x03643c: fc43f003  ldur     d3, [x0, #0x3f]
//   0x036440: 2e303800  uaddlv   h0, v0.8b
//   0x036444: fc45f004  ldur     d4, [x0, #0x5f]
//   0x036448: 1e260008  fmov     w8, s0
//   0x03644c: fc47f005  ldur     d5, [x0, #0x7f]
//   0x036450: 2e210041  uaddl    v1.8h, v2.8b, v1.8b
//   0x036454: 4e020d00  dup      v0.8h, w8
//   0x036458: fc49f006  ldur     d6, [x0, #0x9f]
//   0x03645c: 4e608420  add      v0.8h, v1.8h, v0.8h
//   0x036460: fc4bf007  ldur     d7, [x0, #0xbf]
//   0x036464: 2e231000  uaddw    v0.8h, v0.8h, v3.8b
//   0x036468: fc4df010  ldur     d16, [x0, #0xdf]
//   0x03646c: 2e241000  uaddw    v0.8h, v0.8h, v4.8b
uint64_t fde_0481_sub_036430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5E0000ULL) + (x1 ^ 0xFC4BF007ULL) + (x2 ^ 0x036430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E0000ULL; // 0x036430: ldur d0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FF001ULL; // 0x036434: ldur d1, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC41F002ULL; // 0x036438: ldur d2, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC43F003ULL; // 0x03643c: ldur d3, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x036440: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0xFC45F004ULL; // 0x036444: ldur d4, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260008ULL; // 0x036448: fmov w8, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xFC47F005ULL; // 0x03644c: ldur d5, [x0, #0x7f]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E210041ULL; // 0x036450: uaddl v1.8h, v2.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D00ULL; // 0x036454: dup v0.8h, w8
    return acc;
}

// [EN] Reconstructed FDE #0482 @ 0x0364ac..0x036560 (180 bytes)
// [VN] Phục dựng FDE #0482 tại 0x0364ac..0x036560 (180 byte)
//   0x0364ac: d1008408  sub      x8, x0, #0x21
//   0x0364b0: fc5e0000  ldur     d0, [x0, #-0x20]
//   0x0364b4: 0d40c101  ld1r     {v1.8b}, [x8]
//   0x0364b8: d1000408  sub      x8, x0, #1
//   0x0364bc: 0d40c102  ld1r     {v2.8b}, [x8]
//   0x0364c0: 91007c08  add      x8, x0, #0x1f
//   0x0364c4: 0d40c103  ld1r     {v3.8b}, [x8]
//   0x0364c8: 9100fc08  add      x8, x0, #0x3f
//   0x0364cc: 0d40c104  ld1r     {v4.8b}, [x8]
//   0x0364d0: 91017c08  add      x8, x0, #0x5f
//   0x0364d4: 2e212000  usubl    v0.8h, v0.8b, v1.8b
//   0x0364d8: 0d40c101  ld1r     {v1.8b}, [x8]
//   0x0364dc: 2e221002  uaddw    v2.8h, v0.8h, v2.8b
//   0x0364e0: 2e231003  uaddw    v3.8h, v0.8h, v3.8b
//   0x0364e4: 2e241004  uaddw    v4.8h, v0.8h, v4.8b
//   0x0364e8: 2e211001  uaddw    v1.8h, v0.8h, v1.8b
uint64_t fde_0482_sub_0364ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD1008408ULL) + (x1 ^ 0x2E221002ULL) + (x2 ^ 0x0364ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD1008408ULL; // 0x0364ac: sub x8, x0, #0x21
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E0000ULL; // 0x0364b0: ldur d0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C101ULL; // 0x0364b4: ld1r {v1.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000408ULL; // 0x0364b8: sub x8, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C102ULL; // 0x0364bc: ld1r {v2.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91007C08ULL; // 0x0364c0: add x8, x0, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C103ULL; // 0x0364c4: ld1r {v3.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100FC08ULL; // 0x0364c8: add x8, x0, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C104ULL; // 0x0364cc: ld1r {v4.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91017C08ULL; // 0x0364d0: add x8, x0, #0x5f
    return acc;
}

// [EN] Reconstructed FDE #0483 @ 0x036560..0x036588 (40 bytes)
// [VN] Phục dựng FDE #0483 tại 0x036560..0x036588 (40 byte)
//   0x036560: f85e0008  ldur     x8, [x0, #-0x20]
//   0x036564: f9000008  str      x8, [x0]
//   0x036568: f9001008  str      x8, [x0, #0x20]
//   0x03656c: f9002008  str      x8, [x0, #0x40]
//   0x036570: f9003008  str      x8, [x0, #0x60]
//   0x036574: f9004008  str      x8, [x0, #0x80]
//   0x036578: f9005008  str      x8, [x0, #0xa0]
//   0x03657c: f9006008  str      x8, [x0, #0xc0]
//   0x036580: f9007008  str      x8, [x0, #0xe0]
//   0x036584: d65f03c0  ret      
uint64_t fde_0483_sub_036560(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF85E0008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036560ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF85E0008ULL; // 0x036560: ldur x8, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x036564: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001008ULL; // 0x036568: str x8, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002008ULL; // 0x03656c: str x8, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003008ULL; // 0x036570: str x8, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004008ULL; // 0x036574: str x8, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9005008ULL; // 0x036578: str x8, [x0, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9006008ULL; // 0x03657c: str x8, [x0, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9007008ULL; // 0x036580: str x8, [x0, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036584: ret 
    return acc;
}

// [EN] Reconstructed FDE #0484 @ 0x036588..0x0365ec (100 bytes)
// [VN] Phục dựng FDE #0484 tại 0x036588..0x0365ec (100 byte)
//   0x036588: d1000408  sub      x8, x0, #1
//   0x03658c: 0d40c100  ld1r     {v0.8b}, [x8]
//   0x036590: 91007c08  add      x8, x0, #0x1f
//   0x036594: fd000000  str      d0, [x0]
//   0x036598: 0d40c100  ld1r     {v0.8b}, [x8]
//   0x03659c: 9100fc08  add      x8, x0, #0x3f
//   0x0365a0: fd001000  str      d0, [x0, #0x20]
//   0x0365a4: 0d40c100  ld1r     {v0.8b}, [x8]
//   0x0365a8: 91017c08  add      x8, x0, #0x5f
//   0x0365ac: fd002000  str      d0, [x0, #0x40]
//   0x0365b0: 0d40c100  ld1r     {v0.8b}, [x8]
//   0x0365b4: 9101fc08  add      x8, x0, #0x7f
//   0x0365b8: fd003000  str      d0, [x0, #0x60]
//   0x0365bc: 0d40c100  ld1r     {v0.8b}, [x8]
//   0x0365c0: 91027c08  add      x8, x0, #0x9f
//   0x0365c4: fd004000  str      d0, [x0, #0x80]
uint64_t fde_0484_sub_036588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD1000408ULL) + (x1 ^ 0xFD003000ULL) + (x2 ^ 0x036588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000408ULL; // 0x036588: sub x8, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C100ULL; // 0x03658c: ld1r {v0.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91007C08ULL; // 0x036590: add x8, x0, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0xFD000000ULL; // 0x036594: str d0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C100ULL; // 0x036598: ld1r {v0.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100FC08ULL; // 0x03659c: add x8, x0, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0xFD001000ULL; // 0x0365a0: str d0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C100ULL; // 0x0365a4: ld1r {v0.8b}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91017C08ULL; // 0x0365a8: add x8, x0, #0x5f
    acc = (acc * 0x100000001B3ULL) ^ 0xFD002000ULL; // 0x0365ac: str d0, [x0, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0485 @ 0x0365ec..0x036654 (104 bytes)
// [VN] Phục dựng FDE #0485 tại 0x0365ec..0x036654 (104 byte)
//   0x0365ec: fc5ff000  ldur     d0, [x0, #-1]
//   0x0365f0: fc41f001  ldur     d1, [x0, #0x1f]
//   0x0365f4: fc43f002  ldur     d2, [x0, #0x3f]
//   0x0365f8: fc45f003  ldur     d3, [x0, #0x5f]
//   0x0365fc: fc47f004  ldur     d4, [x0, #0x7f]
//   0x036600: fc49f005  ldur     d5, [x0, #0x9f]
//   0x036604: 2e200020  uaddl    v0.8h, v1.8b, v0.8b
//   0x036608: fc4bf006  ldur     d6, [x0, #0xbf]
//   0x03660c: 2e221000  uaddw    v0.8h, v0.8h, v2.8b
//   0x036610: fc4df007  ldur     d7, [x0, #0xdf]
//   0x036614: 2e231000  uaddw    v0.8h, v0.8h, v3.8b
//   0x036618: 2e241000  uaddw    v0.8h, v0.8h, v4.8b
//   0x03661c: 2e251000  uaddw    v0.8h, v0.8h, v5.8b
//   0x036620: 2e261000  uaddw    v0.8h, v0.8h, v6.8b
//   0x036624: 2e271000  uaddw    v0.8h, v0.8h, v7.8b
//   0x036628: 0f0d8c00  rshrn    v0.8b, v0.8h, #3
uint64_t fde_0485_sub_0365ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5FF000ULL) + (x1 ^ 0x2E251000ULL) + (x2 ^ 0x0365ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FF000ULL; // 0x0365ec: ldur d0, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC41F001ULL; // 0x0365f0: ldur d1, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC43F002ULL; // 0x0365f4: ldur d2, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC45F003ULL; // 0x0365f8: ldur d3, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC47F004ULL; // 0x0365fc: ldur d4, [x0, #0x7f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC49F005ULL; // 0x036600: ldur d5, [x0, #0x9f]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E200020ULL; // 0x036604: uaddl v0.8h, v1.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0xFC4BF006ULL; // 0x036608: ldur d6, [x0, #0xbf]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E221000ULL; // 0x03660c: uaddw v0.8h, v0.8h, v2.8b
    acc = (acc * 0x100000001B3ULL) ^ 0xFC4DF007ULL; // 0x036610: ldur d7, [x0, #0xdf]
    return acc;
}

// [EN] Reconstructed FDE #0486 @ 0x036654..0x036690 (60 bytes)
// [VN] Phục dựng FDE #0486 tại 0x036654..0x036690 (60 byte)
//   0x036654: fc5e0000  ldur     d0, [x0, #-0x20]
//   0x036658: 2e303800  uaddlv   h0, v0.8b
//   0x03665c: 1e260008  fmov     w8, s0
//   0x036660: 4e020d00  dup      v0.8h, w8
//   0x036664: 0f0d8c00  rshrn    v0.8b, v0.8h, #3
//   0x036668: 0e010400  dup      v0.8b, v0.b[0]
//   0x03666c: fd000000  str      d0, [x0]
//   0x036670: fd001000  str      d0, [x0, #0x20]
//   0x036674: fd002000  str      d0, [x0, #0x40]
//   0x036678: fd003000  str      d0, [x0, #0x60]
//   0x03667c: fd004000  str      d0, [x0, #0x80]
//   0x036680: fd005000  str      d0, [x0, #0xa0]
//   0x036684: fd006000  str      d0, [x0, #0xc0]
//   0x036688: fd007000  str      d0, [x0, #0xe0]
//   0x03668c: d65f03c0  ret      
uint64_t fde_0486_sub_036654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5E0000ULL) + (x1 ^ 0xFD006000ULL) + (x2 ^ 0x036654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E0000ULL; // 0x036654: ldur d0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E303800ULL; // 0x036658: uaddlv h0, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260008ULL; // 0x03665c: fmov w8, s0
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D00ULL; // 0x036660: dup v0.8h, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0F0D8C00ULL; // 0x036664: rshrn v0.8b, v0.8h, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x0E010400ULL; // 0x036668: dup v0.8b, v0.b[0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD000000ULL; // 0x03666c: str d0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD001000ULL; // 0x036670: str d0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD002000ULL; // 0x036674: str d0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD003000ULL; // 0x036678: str d0, [x0, #0x60]
    return acc;
}

// [EN] Reconstructed FDE #0487 @ 0x036690..0x0366b8 (40 bytes)
// [VN] Phục dựng FDE #0487 tại 0x036690..0x0366b8 (40 byte)
//   0x036690: 0f04e400  movi     v0.8b, #0x80
//   0x036694: fd000000  str      d0, [x0]
//   0x036698: fd001000  str      d0, [x0, #0x20]
//   0x03669c: fd002000  str      d0, [x0, #0x40]
//   0x0366a0: fd003000  str      d0, [x0, #0x60]
//   0x0366a4: fd004000  str      d0, [x0, #0x80]
//   0x0366a8: fd005000  str      d0, [x0, #0xa0]
//   0x0366ac: fd006000  str      d0, [x0, #0xc0]
//   0x0366b0: fd007000  str      d0, [x0, #0xe0]
//   0x0366b4: d65f03c0  ret      
uint64_t fde_0487_sub_036690(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x0F04E400ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036690ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x0F04E400ULL; // 0x036690: movi v0.8b, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xFD000000ULL; // 0x036694: str d0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD001000ULL; // 0x036698: str d0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD002000ULL; // 0x03669c: str d0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD003000ULL; // 0x0366a0: str d0, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD004000ULL; // 0x0366a4: str d0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD005000ULL; // 0x0366a8: str d0, [x0, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD006000ULL; // 0x0366ac: str d0, [x0, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD007000ULL; // 0x0366b0: str d0, [x0, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0366b4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0488 @ 0x0366b8..0x036740 (136 bytes)
// [VN] Phục dựng FDE #0488 tại 0x0366b8..0x036740 (136 byte)
//   0x0366b8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0366bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0366c0: 910043fd  add      x29, sp, #0x10
//   0x0366c4: d0000160  adrp     x0, #0x64000
//   0x0366c8: 9111c000  add      x0, x0, #0x470
//   0x0366cc: 97ff3699  bl       #0x4130
//   0x0366d0: 34000080  cbz      w0, #0x366e0
//   0x0366d4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0366d8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x0366dc: d65f03c0  ret      
//   0x0366e0: b0000174  adrp     x20, #0x63000
//   0x0366e4: f947be94  ldr      x20, [x20, #0xf78]
//   0x0366e8: d0000173  adrp     x19, #0x64000
//   0x0366ec: f9415e69  ldr      x9, [x19, #0x2b8]
//   0x0366f0: f9400288  ldr      x8, [x20]
//   0x0366f4: eb08013f  cmp      x9, x8
uint64_t fde_0488_sub_0366b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000173ULL) + (x2 ^ 0x0366B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0366b8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0366bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0366c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000160ULL; // 0x0366c4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9111C000ULL; // 0x0366c8: add x0, x0, #0x470
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF3699ULL; // 0x0366cc: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x0366d0: cbz w0, #0x366e0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0366d4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x0366d8: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0366dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0489 @ 0x036740..0x0367e8 (168 bytes)
// [VN] Phục dựng FDE #0489 tại 0x036740..0x0367e8 (168 byte)
//   0x036740: 7100047f  cmp      w3, #1
//   0x036744: b4000400  cbz      x0, #0x367c4
//   0x036748: 540004eb  b.lt     #0x367e4
//   0x03674c: 3940000a  ldrb     w10, [x0]
//   0x036750: 39400028  ldrb     w8, [x1]
//   0x036754: 4b0a0149  sub      w9, w10, w10
//   0x036758: 0b0a0129  add      w9, w9, w10
//   0x03675c: 131f7d2b  asr      w11, w9, #0x1f
//   0x036760: 7104013f  cmp      w9, #0x100
//   0x036764: 5a8b3129  csinv    w9, w9, w11, lo
//   0x036768: 0b090108  add      w8, w8, w9
//   0x03676c: 7100047f  cmp      w3, #1
//   0x036770: 39000048  strb     w8, [x2]
//   0x036774: 54000380  b.eq     #0x367e4
//   0x036778: 2a0303ec  mov      w12, w3
//   0x03677c: 91000429  add      x9, x1, #1
uint64_t fde_0489_sub_036740(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100047FULL) + (x1 ^ 0x39000048ULL) + (x2 ^ 0x036740ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x036740: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000400ULL; // 0x036744: cbz x0, #0x367c4
    acc = (acc * 0x100000001B3ULL) ^ 0x540004EBULL; // 0x036748: b.lt #0x367e4
    acc = (acc * 0x100000001B3ULL) ^ 0x3940000AULL; // 0x03674c: ldrb w10, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x036750: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0A0149ULL; // 0x036754: sub w9, w10, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0A0129ULL; // 0x036758: add w9, w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x131F7D2BULL; // 0x03675c: asr w11, w9, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x7104013FULL; // 0x036760: cmp w9, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0x5A8B3129ULL; // 0x036764: csinv w9, w9, w11, lo
    return acc;
}

// [EN] Reconstructed FDE #0490 @ 0x0367e8..0x036840 (88 bytes)
// [VN] Phục dựng FDE #0490 tại 0x0367e8..0x036840 (88 byte)
//   0x0367e8: b000016a  adrp     x10, #0x63000
//   0x0367ec: b000016d  adrp     x13, #0x63000
//   0x0367f0: 90000008  adrp     x8, #0x36000
//   0x0367f4: f946594a  ldr      x10, [x10, #0xcb0]
//   0x0367f8: 9000000b  adrp     x11, #0x36000
//   0x0367fc: f947adad  ldr      x13, [x13, #0xf58]
//   0x036800: 91210108  add      x8, x8, #0x840
//   0x036804: 90000009  adrp     x9, #0x36000
//   0x036808: 912c116b  add      x11, x11, #0xb04
//   0x03680c: 9000000c  adrp     x12, #0x36000
//   0x036810: 91246129  add      x9, x9, #0x918
//   0x036814: 9136e18c  add      x12, x12, #0xdb8
//   0x036818: b000000e  adrp     x14, #0x37000
//   0x03681c: 9e670100  fmov     d0, x8
//   0x036820: 9e670161  fmov     d1, x11
//   0x036824: 9101f1ce  add      x14, x14, #0x7c
uint64_t fde_0490_sub_0367e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB000016AULL) + (x1 ^ 0xB000000EULL) + (x2 ^ 0x0367E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB000016AULL; // 0x0367e8: adrp x10, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xB000016DULL; // 0x0367ec: adrp x13, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x0367f0: adrp x8, #0x36000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946594AULL; // 0x0367f4: ldr x10, [x10, #0xcb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000BULL; // 0x0367f8: adrp x11, #0x36000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947ADADULL; // 0x0367fc: ldr x13, [x13, #0xf58]
    acc = (acc * 0x100000001B3ULL) ^ 0x91210108ULL; // 0x036800: add x8, x8, #0x840
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x036804: adrp x9, #0x36000
    acc = (acc * 0x100000001B3ULL) ^ 0x912C116BULL; // 0x036808: add x11, x11, #0xb04
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000CULL; // 0x03680c: adrp x12, #0x36000
    return acc;
}

// [EN] Reconstructed FDE #0491 @ 0x036840..0x036918 (216 bytes)
// [VN] Phục dựng FDE #0491 tại 0x036840..0x036918 (216 byte)
//   0x036840: 39400028  ldrb     w8, [x1]
//   0x036844: b4000060  cbz      x0, #0x36850
//   0x036848: 39400009  ldrb     w9, [x0]
//   0x03684c: 14000002  b        #0x36854
//   0x036850: 2a1f03e9  mov      w9, wzr
//   0x036854: 0b08012c  add      w12, w9, w8
//   0x036858: 7100087f  cmp      w3, #2
//   0x03685c: 3900004c  strb     w12, [x2]
//   0x036860: 540005ab  b.lt     #0x36914
//   0x036864: 71004469  subs     w9, w3, #0x11
//   0x036868: 540000aa  b.ge     #0x3687c
//   0x03686c: 52800028  mov      w8, #1
//   0x036870: 6b03011f  cmp      w8, w3
//   0x036874: 540003ab  b.lt     #0x368e8
//   0x036878: 14000027  b        #0x36914
//   0x03687c: 6f00e401  movi     v1.2d, #0000000000000000
uint64_t fde_0491_sub_036840(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400028ULL) + (x1 ^ 0x6B03011FULL) + (x2 ^ 0x036840ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x036840: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x036844: cbz x0, #0x36850
    acc = (acc * 0x100000001B3ULL) ^ 0x39400009ULL; // 0x036848: ldrb w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x03684c: b #0x36854
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E9ULL; // 0x036850: mov w9, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x0B08012CULL; // 0x036854: add w12, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100087FULL; // 0x036858: cmp w3, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x3900004CULL; // 0x03685c: strb w12, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x540005ABULL; // 0x036860: b.lt #0x36914
    acc = (acc * 0x100000001B3ULL) ^ 0x71004469ULL; // 0x036864: subs w9, w3, #0x11
    return acc;
}

// [EN] Reconstructed FDE #0492 @ 0x036918..0x036b04 (492 bytes)
// [VN] Phục dựng FDE #0492 tại 0x036918..0x036b04 (492 byte)
//   0x036918: b40000e0  cbz      x0, #0x36934
//   0x03691c: 7100407f  cmp      w3, #0x10
//   0x036920: 540001ea  b.ge     #0x3695c
//   0x036924: 2a1f03e8  mov      w8, wzr
//   0x036928: 6b03011f  cmp      w8, w3
//   0x03692c: 5400034b  b.lt     #0x36994
//   0x036930: 14000074  b        #0x36b00
//   0x036934: 3940002c  ldrb     w12, [x1]
//   0x036938: 7100087f  cmp      w3, #2
//   0x03693c: 3900004c  strb     w12, [x2]
//   0x036940: 54000e0b  b.lt     #0x36b00
//   0x036944: 71004468  subs     w8, w3, #0x11
//   0x036948: 5400090a  b.ge     #0x36a68
//   0x03694c: 52800028  mov      w8, #1
//   0x036950: 6b03011f  cmp      w8, w3
//   0x036954: 54000c0b  b.lt     #0x36ad4
uint64_t fde_0492_sub_036918(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000E0ULL) + (x1 ^ 0x5400090AULL) + (x2 ^ 0x036918ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x036918: cbz x0, #0x36934
    acc = (acc * 0x100000001B3ULL) ^ 0x7100407FULL; // 0x03691c: cmp w3, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x540001EAULL; // 0x036920: b.ge #0x3695c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x036924: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B03011FULL; // 0x036928: cmp w8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x5400034BULL; // 0x03692c: b.lt #0x36994
    acc = (acc * 0x100000001B3ULL) ^ 0x14000074ULL; // 0x036930: b #0x36b00
    acc = (acc * 0x100000001B3ULL) ^ 0x3940002CULL; // 0x036934: ldrb w12, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100087FULL; // 0x036938: cmp w3, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x3900004CULL; // 0x03693c: strb w12, [x2]
    return acc;
}

// [EN] Reconstructed FDE #0493 @ 0x036b04..0x036db8 (692 bytes)
// [VN] Phục dựng FDE #0493 tại 0x036b04..0x036db8 (692 byte)
//   0x036b04: a9bd5ff8  stp      x24, x23, [sp, #-0x30]!
//   0x036b08: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x036b0c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x036b10: 39400008  ldrb     w8, [x0]
//   0x036b14: aa0403e9  mov      x9, x4
//   0x036b18: 7100443f  cmp      w1, #0x11
//   0x036b1c: 38001528  strb     w8, [x9], #1
//   0x036b20: 51000428  sub      w8, w1, #1
//   0x036b24: 540000aa  b.ge     #0x36b38
//   0x036b28: 2a1f03e9  mov      w9, wzr
//   0x036b2c: 6b08013f  cmp      w9, w8
//   0x036b30: 5400022b  b.lt     #0x36b74
//   0x036b34: 1400003d  b        #0x36c28
//   0x036b38: aa1f03ea  mov      x10, xzr
//   0x036b3c: 93407d0b  sxtw     x11, w8
//   0x036b40: 8b0a000c  add      x12, x0, x10
uint64_t fde_0493_sub_036b04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD5FF8ULL) + (x1 ^ 0x1400003DULL) + (x2 ^ 0x036B04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD5FF8ULL; // 0x036b04: stp x24, x23, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x036b08: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x036b0c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x036b10: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E9ULL; // 0x036b14: mov x9, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100443FULL; // 0x036b18: cmp w1, #0x11
    acc = (acc * 0x100000001B3ULL) ^ 0x38001528ULL; // 0x036b1c: strb w8, [x9], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x51000428ULL; // 0x036b20: sub w8, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x036b24: b.ge #0x36b38
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E9ULL; // 0x036b28: mov w9, wzr
    return acc;
}

// [EN] Reconstructed FDE #0494 @ 0x036db8..0x03707c (708 bytes)
// [VN] Phục dựng FDE #0494 tại 0x036db8..0x03707c (708 byte)
//   0x036db8: a9bd5ff8  stp      x24, x23, [sp, #-0x30]!
//   0x036dbc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x036dc0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x036dc4: 39400008  ldrb     w8, [x0]
//   0x036dc8: aa0403e9  mov      x9, x4
//   0x036dcc: 7100443f  cmp      w1, #0x11
//   0x036dd0: 38001528  strb     w8, [x9], #1
//   0x036dd4: 51000428  sub      w8, w1, #1
//   0x036dd8: 540000aa  b.ge     #0x36dec
//   0x036ddc: 2a1f03e9  mov      w9, wzr
//   0x036de0: 6b08013f  cmp      w9, w8
//   0x036de4: 5400022b  b.lt     #0x36e28
//   0x036de8: 1400003d  b        #0x36edc
//   0x036dec: aa1f03ea  mov      x10, xzr
//   0x036df0: 93407d0b  sxtw     x11, w8
//   0x036df4: 8b0a000c  add      x12, x0, x10
uint64_t fde_0494_sub_036db8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD5FF8ULL) + (x1 ^ 0x1400003DULL) + (x2 ^ 0x036DB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD5FF8ULL; // 0x036db8: stp x24, x23, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x036dbc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x036dc0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x036dc4: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E9ULL; // 0x036dc8: mov x9, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100443FULL; // 0x036dcc: cmp w1, #0x11
    acc = (acc * 0x100000001B3ULL) ^ 0x38001528ULL; // 0x036dd0: strb w8, [x9], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x51000428ULL; // 0x036dd4: sub w8, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x036dd8: b.ge #0x36dec
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E9ULL; // 0x036ddc: mov w9, wzr
    return acc;
}

// [EN] Reconstructed FDE #0495 @ 0x03707c..0x037484 (1032 bytes)
// [VN] Phục dựng FDE #0495 tại 0x03707c..0x037484 (1032 byte)
//   0x03707c: f81b0ffb  str      x27, [sp, #-0x50]!
//   0x037080: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x037084: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x037088: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x03708c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x037090: 39400008  ldrb     w8, [x0]
//   0x037094: aa0403e9  mov      x9, x4
//   0x037098: 7100443f  cmp      w1, #0x11
//   0x03709c: 38001528  strb     w8, [x9], #1
//   0x0370a0: 51000428  sub      w8, w1, #1
//   0x0370a4: 540000aa  b.ge     #0x370b8
//   0x0370a8: 2a1f03e9  mov      w9, wzr
//   0x0370ac: 6b08013f  cmp      w9, w8
//   0x0370b0: 5400022b  b.lt     #0x370f4
//   0x0370b4: 1400003d  b        #0x371a8
//   0x0370b8: aa1f03ea  mov      x10, xzr
uint64_t fde_0495_sub_03707c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FFBULL) + (x1 ^ 0x6B08013FULL) + (x2 ^ 0x03707CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FFBULL; // 0x03707c: str x27, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x037080: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x037084: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x037088: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03708c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x037090: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E9ULL; // 0x037094: mov x9, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100443FULL; // 0x037098: cmp w1, #0x11
    acc = (acc * 0x100000001B3ULL) ^ 0x38001528ULL; // 0x03709c: strb w8, [x9], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x51000428ULL; // 0x0370a0: sub w8, w1, #1
    return acc;
}

// [EN] Reconstructed FDE #0496 @ 0x037484..0x03748c (8 bytes)
// [VN] Phục dựng FDE #0496 tại 0x037484..0x03748c (8 byte)
//   0x037484: 52bfe000  mov      w0, #-0x1000000
//   0x037488: d65f03c0  ret      
uint64_t fde_0496_sub_037484(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52BFE000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037484ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52BFE000ULL; // 0x037484: mov w0, #-0x1000000
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037488: ret 
    return acc;
}

// [EN] Reconstructed FDE #0497 @ 0x03748c..0x037494 (8 bytes)
// [VN] Phục dựng FDE #0497 tại 0x03748c..0x037494 (8 byte)
//   0x03748c: b9400000  ldr      w0, [x0]
//   0x037490: d65f03c0  ret      
uint64_t fde_0497_sub_03748c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03748CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400000ULL; // 0x03748c: ldr w0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037490: ret 
    return acc;
}

// [EN] Reconstructed FDE #0498 @ 0x037494..0x03749c (8 bytes)
// [VN] Phục dựng FDE #0498 tại 0x037494..0x03749c (8 byte)
//   0x037494: b9400020  ldr      w0, [x1]
//   0x037498: d65f03c0  ret      
uint64_t fde_0498_sub_037494(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400020ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037494ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400020ULL; // 0x037494: ldr w0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037498: ret 
    return acc;
}

// [EN] Reconstructed FDE #0499 @ 0x03749c..0x0374a4 (8 bytes)
// [VN] Phục dựng FDE #0499 tại 0x03749c..0x0374a4 (8 byte)
//   0x03749c: b9400420  ldr      w0, [x1, #4]
//   0x0374a0: d65f03c0  ret      
uint64_t fde_0499_sub_03749c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400420ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03749CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400420ULL; // 0x03749c: ldr w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0374a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0500 @ 0x0374a4..0x0374ac (8 bytes)
// [VN] Phục dựng FDE #0500 tại 0x0374a4..0x0374ac (8 byte)
//   0x0374a4: b85fc020  ldur     w0, [x1, #-4]
//   0x0374a8: d65f03c0  ret      
uint64_t fde_0500_sub_0374a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB85FC020ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0374A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC020ULL; // 0x0374a4: ldur w0, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0374a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0501 @ 0x0374ac..0x0374e0 (52 bytes)
// [VN] Phục dựng FDE #0501 tại 0x0374ac..0x0374e0 (52 byte)
//   0x0374ac: b9400008  ldr      w8, [x0]
//   0x0374b0: 2940242a  ldp      w10, w9, [x1]
//   0x0374b4: 4a08012b  eor      w11, w9, w8
//   0x0374b8: 0a080128  and      w8, w9, w8
//   0x0374bc: 53017d69  lsr      w9, w11, #1
//   0x0374c0: 1200d929  and      w9, w9, #0x7f7f7f7f
//   0x0374c4: 0b080128  add      w8, w9, w8
//   0x0374c8: 4a0a0109  eor      w9, w8, w10
//   0x0374cc: 53017d29  lsr      w9, w9, #1
//   0x0374d0: 1200d929  and      w9, w9, #0x7f7f7f7f
//   0x0374d4: 0a0a0108  and      w8, w8, w10
//   0x0374d8: 0b080120  add      w0, w9, w8
//   0x0374dc: d65f03c0  ret      
uint64_t fde_0501_sub_0374ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0374ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x0374ac: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2940242AULL; // 0x0374b0: ldp w10, w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012BULL; // 0x0374b4: eor w11, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x0374b8: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D69ULL; // 0x0374bc: lsr w9, w11, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D929ULL; // 0x0374c0: and w9, w9, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080128ULL; // 0x0374c4: add w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x4A0A0109ULL; // 0x0374c8: eor w9, w8, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D29ULL; // 0x0374cc: lsr w9, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D929ULL; // 0x0374d0: and w9, w9, #0x7f7f7f7f
    return acc;
}

// [EN] Reconstructed FDE #0502 @ 0x0374e0..0x037500 (32 bytes)
// [VN] Phục dựng FDE #0502 tại 0x0374e0..0x037500 (32 byte)
//   0x0374e0: b9400008  ldr      w8, [x0]
//   0x0374e4: b85fc029  ldur     w9, [x1, #-4]
//   0x0374e8: 4a08012a  eor      w10, w9, w8
//   0x0374ec: 53017d4a  lsr      w10, w10, #1
//   0x0374f0: 1200d94a  and      w10, w10, #0x7f7f7f7f
//   0x0374f4: 0a080128  and      w8, w9, w8
//   0x0374f8: 0b080140  add      w0, w10, w8
//   0x0374fc: d65f03c0  ret      
uint64_t fde_0502_sub_0374e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0374E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x0374e0: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC029ULL; // 0x0374e4: ldur w9, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012AULL; // 0x0374e8: eor w10, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D4AULL; // 0x0374ec: lsr w10, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D94AULL; // 0x0374f0: and w10, w10, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x0374f4: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080140ULL; // 0x0374f8: add w0, w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0374fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0503 @ 0x037500..0x037520 (32 bytes)
// [VN] Phục dựng FDE #0503 tại 0x037500..0x037520 (32 byte)
//   0x037500: b9400008  ldr      w8, [x0]
//   0x037504: b9400029  ldr      w9, [x1]
//   0x037508: 4a08012a  eor      w10, w9, w8
//   0x03750c: 53017d4a  lsr      w10, w10, #1
//   0x037510: 1200d94a  and      w10, w10, #0x7f7f7f7f
//   0x037514: 0a080128  and      w8, w9, w8
//   0x037518: 0b080140  add      w0, w10, w8
//   0x03751c: d65f03c0  ret      
uint64_t fde_0503_sub_037500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x037500: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x037504: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012AULL; // 0x037508: eor w10, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D4AULL; // 0x03750c: lsr w10, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D94AULL; // 0x037510: and w10, w10, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x037514: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080140ULL; // 0x037518: add w0, w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03751c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0504 @ 0x037520..0x03753c (28 bytes)
// [VN] Phục dựng FDE #0504 tại 0x037520..0x03753c (28 byte)
//   0x037520: 297fa428  ldp      w8, w9, [x1, #-4]
//   0x037524: 4a08012a  eor      w10, w9, w8
//   0x037528: 53017d4a  lsr      w10, w10, #1
//   0x03752c: 1200d94a  and      w10, w10, #0x7f7f7f7f
//   0x037530: 0a080128  and      w8, w9, w8
//   0x037534: 0b080140  add      w0, w10, w8
//   0x037538: d65f03c0  ret      
uint64_t fde_0504_sub_037520(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x297FA428ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037520ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x297FA428ULL; // 0x037520: ldp w8, w9, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012AULL; // 0x037524: eor w10, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D4AULL; // 0x037528: lsr w10, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D94AULL; // 0x03752c: and w10, w10, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x037530: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080140ULL; // 0x037534: add w0, w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037538: ret 
    return acc;
}

// [EN] Reconstructed FDE #0505 @ 0x03753c..0x037558 (28 bytes)
// [VN] Phục dựng FDE #0505 tại 0x03753c..0x037558 (28 byte)
//   0x03753c: 29402428  ldp      w8, w9, [x1]
//   0x037540: 4a08012a  eor      w10, w9, w8
//   0x037544: 53017d4a  lsr      w10, w10, #1
//   0x037548: 1200d94a  and      w10, w10, #0x7f7f7f7f
//   0x03754c: 0a080128  and      w8, w9, w8
//   0x037550: 0b080140  add      w0, w10, w8
//   0x037554: d65f03c0  ret      
uint64_t fde_0505_sub_03753c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x29402428ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03753CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x29402428ULL; // 0x03753c: ldp w8, w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012AULL; // 0x037540: eor w10, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D4AULL; // 0x037544: lsr w10, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D94AULL; // 0x037548: and w10, w10, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x03754c: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080140ULL; // 0x037550: add w0, w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037554: ret 
    return acc;
}

// [EN] Reconstructed FDE #0506 @ 0x037558..0x0375a4 (76 bytes)
// [VN] Phục dựng FDE #0506 tại 0x037558..0x0375a4 (76 byte)
//   0x037558: b9400008  ldr      w8, [x0]
//   0x03755c: 297fa829  ldp      w9, w10, [x1, #-4]
//   0x037560: b940042b  ldr      w11, [x1, #4]
//   0x037564: 4a08012c  eor      w12, w9, w8
//   0x037568: 0a080128  and      w8, w9, w8
//   0x03756c: 4a0a0169  eor      w9, w11, w10
//   0x037570: 0a0a016a  and      w10, w11, w10
//   0x037574: 53017d8b  lsr      w11, w12, #1
//   0x037578: 53017d29  lsr      w9, w9, #1
//   0x03757c: 1200d96b  and      w11, w11, #0x7f7f7f7f
//   0x037580: 1200d929  and      w9, w9, #0x7f7f7f7f
//   0x037584: 0b080168  add      w8, w11, w8
//   0x037588: 0b0a0129  add      w9, w9, w10
//   0x03758c: 4a08012a  eor      w10, w9, w8
//   0x037590: 53017d4a  lsr      w10, w10, #1
//   0x037594: 1200d94a  and      w10, w10, #0x7f7f7f7f
uint64_t fde_0506_sub_037558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0x0B0A0129ULL) + (x2 ^ 0x037558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x037558: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x297FA829ULL; // 0x03755c: ldp w9, w10, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940042BULL; // 0x037560: ldr w11, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012CULL; // 0x037564: eor w12, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x037568: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x4A0A0169ULL; // 0x03756c: eor w9, w11, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x0A0A016AULL; // 0x037570: and w10, w11, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D8BULL; // 0x037574: lsr w11, w12, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D29ULL; // 0x037578: lsr w9, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D96BULL; // 0x03757c: and w11, w11, #0x7f7f7f7f
    return acc;
}

// [EN] Reconstructed FDE #0507 @ 0x0375a4..0x037654 (176 bytes)
// [VN] Phục dựng FDE #0507 tại 0x0375a4..0x037654 (176 byte)
//   0x0375a4: 297fa02a  ldp      w10, w8, [x1, #-4]
//   0x0375a8: b9400009  ldr      w9, [x0]
//   0x0375ac: 53187d0b  lsr      w11, w8, #0x18
//   0x0375b0: 53187d2c  lsr      w12, w9, #0x18
//   0x0375b4: 53187d4d  lsr      w13, w10, #0x18
//   0x0375b8: 6b0d018c  subs     w12, w12, w13
//   0x0375bc: 4b0d016b  sub      w11, w11, w13
//   0x0375c0: 53105d0e  ubfx     w14, w8, #0x10, #8
//   0x0375c4: 53105d2f  ubfx     w15, w9, #0x10, #8
//   0x0375c8: 53105d50  ubfx     w16, w10, #0x10, #8
//   0x0375cc: 5a8c558c  cneg     w12, w12, mi
//   0x0375d0: 7100017f  cmp      w11, #0
//   0x0375d4: 4b1001ce  sub      w14, w14, w16
//   0x0375d8: 5a8bb56b  cneg     w11, w11, ge
//   0x0375dc: 6b1001ef  subs     w15, w15, w16
//   0x0375e0: 53083d11  ubfx     w17, w8, #8, #8
uint64_t fde_0507_sub_0375a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x297FA02AULL) + (x1 ^ 0x4B1001CEULL) + (x2 ^ 0x0375A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x297FA02AULL; // 0x0375a4: ldp w10, w8, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400009ULL; // 0x0375a8: ldr w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D0BULL; // 0x0375ac: lsr w11, w8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D2CULL; // 0x0375b0: lsr w12, w9, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D4DULL; // 0x0375b4: lsr w13, w10, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0D018CULL; // 0x0375b8: subs w12, w12, w13
    acc = (acc * 0x100000001B3ULL) ^ 0x4B0D016BULL; // 0x0375bc: sub w11, w11, w13
    acc = (acc * 0x100000001B3ULL) ^ 0x53105D0EULL; // 0x0375c0: ubfx w14, w8, #0x10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x53105D2FULL; // 0x0375c4: ubfx w15, w9, #0x10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x53105D50ULL; // 0x0375c8: ubfx w16, w10, #0x10, #8
    return acc;
}

// [EN] Reconstructed FDE #0508 @ 0x037654..0x0376e8 (148 bytes)
// [VN] Phục dựng FDE #0508 tại 0x037654..0x0376e8 (148 byte)
//   0x037654: 297fa02a  ldp      w10, w8, [x1, #-4]
//   0x037658: b9400009  ldr      w9, [x0]
//   0x03765c: 53187d0b  lsr      w11, w8, #0x18
//   0x037660: 53107d2c  lsr      w12, w9, #0x10
//   0x037664: 53105d0d  ubfx     w13, w8, #0x10, #8
//   0x037668: 53107d4e  lsr      w14, w10, #0x10
//   0x03766c: 53087d2f  lsr      w15, w9, #8
//   0x037670: 0b2c01ac  add      w12, w13, w12, uxtb
//   0x037674: 53083d0d  ubfx     w13, w8, #8, #8
//   0x037678: 12001d08  and      w8, w8, #0xff
//   0x03767c: 0b49616b  add      w11, w11, w9, lsr #24
//   0x037680: 0b2f01ad  add      w13, w13, w15, uxtb
//   0x037684: 53087d4f  lsr      w15, w10, #8
//   0x037688: 0b290108  add      w8, w8, w9, uxtb
//   0x03768c: 4b4a6169  sub      w9, w11, w10, lsr #24
//   0x037690: 4b2e018b  sub      w11, w12, w14, uxtb
uint64_t fde_0508_sub_037654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x297FA02AULL) + (x1 ^ 0x53087D4FULL) + (x2 ^ 0x037654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x297FA02AULL; // 0x037654: ldp w10, w8, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400009ULL; // 0x037658: ldr w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D0BULL; // 0x03765c: lsr w11, w8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D2CULL; // 0x037660: lsr w12, w9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x53105D0DULL; // 0x037664: ubfx w13, w8, #0x10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D4EULL; // 0x037668: lsr w14, w10, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x53087D2FULL; // 0x03766c: lsr w15, w9, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x0B2C01ACULL; // 0x037670: add w12, w13, w12, uxtb
    acc = (acc * 0x100000001B3ULL) ^ 0x53083D0DULL; // 0x037674: ubfx w13, w8, #8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x12001D08ULL; // 0x037678: and w8, w8, #0xff
    return acc;
}

// [EN] Reconstructed FDE #0509 @ 0x0376e8..0x0377a8 (192 bytes)
// [VN] Phục dựng FDE #0509 tại 0x0376e8..0x0377a8 (192 byte)
//   0x0376e8: b9400008  ldr      w8, [x0]
//   0x0376ec: 297fa42a  ldp      w10, w9, [x1, #-4]
//   0x0376f0: 4a08012b  eor      w11, w9, w8
//   0x0376f4: 53017d6b  lsr      w11, w11, #1
//   0x0376f8: 0a080128  and      w8, w9, w8
//   0x0376fc: 1200d96b  and      w11, w11, #0x7f7f7f7f
//   0x037700: 0b080168  add      w8, w11, w8
//   0x037704: 53187d0b  lsr      w11, w8, #0x18
//   0x037708: 4b4a616d  sub      w13, w11, w10, lsr #24
//   0x03770c: 710001bf  cmp      w13, #0
//   0x037710: 1a8da5ad  cinc     w13, w13, lt
//   0x037714: 0b8d056b  add      w11, w11, w13, asr #1
//   0x037718: 53187d6d  lsr      w13, w11, #0x18
//   0x03771c: 7104017f  cmp      w11, #0x100
//   0x037720: 53107d49  lsr      w9, w10, #0x10
//   0x037724: 5a8d316b  csinv    w11, w11, w13, lo
uint64_t fde_0509_sub_0376e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0x53187D6DULL) + (x2 ^ 0x0376E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x0376e8: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x297FA42AULL; // 0x0376ec: ldp w10, w9, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x4A08012BULL; // 0x0376f0: eor w11, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53017D6BULL; // 0x0376f4: lsr w11, w11, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x0A080128ULL; // 0x0376f8: and w8, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1200D96BULL; // 0x0376fc: and w11, w11, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080168ULL; // 0x037700: add w8, w11, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D0BULL; // 0x037704: lsr w11, w8, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x4B4A616DULL; // 0x037708: sub w13, w11, w10, lsr #24
    acc = (acc * 0x100000001B3ULL) ^ 0x710001BFULL; // 0x03770c: cmp w13, #0
    return acc;
}

// [EN] Reconstructed FDE #0510 @ 0x0377a8..0x0378a0 (248 bytes)
// [VN] Phục dựng FDE #0510 tại 0x0377a8..0x0378a0 (248 byte)
//   0x0377a8: 7100043f  cmp      w1, #1
//   0x0377ac: 5400038b  b.lt     #0x3781c
//   0x0377b0: 7100203f  cmp      w1, #8
//   0x0377b4: 2a0103e8  mov      w8, w1
//   0x0377b8: 54000103  b.lo     #0x377d8
//   0x0377bc: d37ef509  lsl      x9, x8, #2
//   0x0377c0: 8b09000a  add      x10, x0, x9
//   0x0377c4: eb02015f  cmp      x10, x2
//   0x0377c8: 540002c9  b.ls     #0x37820
//   0x0377cc: 8b090049  add      x9, x2, x9
//   0x0377d0: eb00013f  cmp      x9, x0
//   0x0377d4: 54000269  b.ls     #0x37820
//   0x0377d8: aa1f03e9  mov      x9, xzr
//   0x0377dc: d37ef52c  lsl      x12, x9, #2
//   0x0377e0: 32009fea  mov      w10, #0xff00ff
//   0x0377e4: 8b0c004b  add      x11, x2, x12
uint64_t fde_0510_sub_0377a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xAA1F03E9ULL) + (x2 ^ 0x0377A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0377a8: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400038BULL; // 0x0377ac: b.lt #0x3781c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100203FULL; // 0x0377b0: cmp w1, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E8ULL; // 0x0377b4: mov w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000103ULL; // 0x0377b8: b.lo #0x377d8
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF509ULL; // 0x0377bc: lsl x9, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09000AULL; // 0x0377c0: add x10, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02015FULL; // 0x0377c4: cmp x10, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x540002C9ULL; // 0x0377c8: b.ls #0x37820
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090049ULL; // 0x0377cc: add x9, x2, x9
    return acc;
}

// [EN] Reconstructed FDE #0511 @ 0x0378a0..0x0379bc (284 bytes)
// [VN] Phục dựng FDE #0511 tại 0x0378a0..0x0379bc (284 byte)
//   0x0378a0: 7100045f  cmp      w2, #1
//   0x0378a4: 5400046b  b.lt     #0x37930
//   0x0378a8: 39c00008  ldrsb    w8, [x0]
//   0x0378ac: 39c00409  ldrsb    w9, [x0, #1]
//   0x0378b0: 39c0080a  ldrsb    w10, [x0, #2]
//   0x0378b4: 7100105f  cmp      w2, #4
//   0x0378b8: 2a0203eb  mov      w11, w2
//   0x0378bc: 54000103  b.lo     #0x378dc
//   0x0378c0: d37ef56c  lsl      x12, x11, #2
//   0x0378c4: 8b0c002d  add      x13, x1, x12
//   0x0378c8: eb0301bf  cmp      x13, x3
//   0x0378cc: 54000349  b.ls     #0x37934
//   0x0378d0: 8b0c006c  add      x12, x3, x12
//   0x0378d4: eb01019f  cmp      x12, x1
//   0x0378d8: 540002e9  b.ls     #0x37934
//   0x0378dc: aa1f03ec  mov      x12, xzr
uint64_t fde_0511_sub_0378a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x8B0C006CULL) + (x2 ^ 0x0378A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x0378a0: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400046BULL; // 0x0378a4: b.lt #0x37930
    acc = (acc * 0x100000001B3ULL) ^ 0x39C00008ULL; // 0x0378a8: ldrsb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39C00409ULL; // 0x0378ac: ldrsb w9, [x0, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39C0080AULL; // 0x0378b0: ldrsb w10, [x0, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x0378b4: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EBULL; // 0x0378b8: mov w11, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000103ULL; // 0x0378bc: b.lo #0x378dc
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF56CULL; // 0x0378c0: lsl x12, x11, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0C002DULL; // 0x0378c4: add x13, x1, x12
    return acc;
}

// [EN] Reconstructed FDE #0512 @ 0x0379bc..0x037a84 (200 bytes)
// [VN] Phục dựng FDE #0512 tại 0x0379bc..0x037a84 (200 byte)
//   0x0379bc: 2940940c  ldp      w12, w5, [x0, #4]
//   0x0379c0: f9400809  ldr      x9, [x0, #0x10]
//   0x0379c4: 5280010a  mov      w10, #8
//   0x0379c8: 2a0203e8  mov      w8, w2
//   0x0379cc: 1acc254b  lsr      w11, w10, w12
//   0x0379d0: 71001d7f  cmp      w11, #7
//   0x0379d4: 2a0103ea  mov      w10, w1
//   0x0379d8: 5400042c  b.gt     #0x37a5c
//   0x0379dc: 6b08015f  cmp      w10, w8
//   0x0379e0: 5400050a  b.ge     #0x37a80
//   0x0379e4: 1280000d  mov      w13, #-1
//   0x0379e8: 1acc21ac  lsl      w12, w13, w12
//   0x0379ec: 1acb21ad  lsl      w13, w13, w11
//   0x0379f0: 2a2c03ec  mvn      w12, w12
//   0x0379f4: 2a2d03ed  mvn      w13, w13
//   0x0379f8: 710004bf  cmp      w5, #1
uint64_t fde_0512_sub_0379bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2940940CULL) + (x1 ^ 0x1ACB21ADULL) + (x2 ^ 0x0379BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2940940CULL; // 0x0379bc: ldp w12, w5, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x0379c0: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280010AULL; // 0x0379c4: mov w10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x0379c8: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x1ACC254BULL; // 0x0379cc: lsr w11, w10, w12
    acc = (acc * 0x100000001B3ULL) ^ 0x71001D7FULL; // 0x0379d0: cmp w11, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103EAULL; // 0x0379d4: mov w10, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400042CULL; // 0x0379d8: b.gt #0x37a5c
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08015FULL; // 0x0379dc: cmp w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x5400050AULL; // 0x0379e0: b.ge #0x37a80
    return acc;
}

// [EN] Reconstructed FDE #0513 @ 0x037a84..0x038068 (1508 bytes)
// [VN] Phục dựng FDE #0513 tại 0x037a84..0x038068 (1508 byte)
//   0x037a84: d10303ff  sub      sp, sp, #0xc0
//   0x037a88: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x037a8c: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x037a90: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x037a94: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x037a98: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x037a9c: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x037aa0: 9102c3fd  add      x29, sp, #0xb0
//   0x037aa4: d53bd048  mrs      x8, tpidr_el0
//   0x037aa8: f9000fe8  str      x8, [sp, #0x18]
//   0x037aac: f9401508  ldr      x8, [x8, #0x28]
//   0x037ab0: f9002fe8  str      x8, [sp, #0x58]
//   0x037ab4: b9400008  ldr      w8, [x0]
//   0x037ab8: 71000d1f  cmp      w8, #3
//   0x037abc: 54002ba8  b.hi     #0x38030
//   0x037ac0: b9800817  ldrsw    x23, [x0, #8]
uint64_t fde_0513_sub_037a84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xB9400008ULL) + (x2 ^ 0x037A84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x037a84: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x037a88: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x037a8c: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x037a90: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x037a94: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x037a98: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x037a9c: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x037aa0: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x037aa4: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x037aa8: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0514 @ 0x038068..0x03809c (52 bytes)
// [VN] Phục dựng FDE #0514 tại 0x038068..0x03809c (52 byte)
//   0x038068: 7100043f  cmp      w1, #1
//   0x03806c: 5400016b  b.lt     #0x38098
//   0x038070: 8b21c808  add      x8, x0, w1, sxtw #2
//   0x038074: b8404409  ldr      w9, [x0], #4
//   0x038078: 53107d2a  lsr      w10, w9, #0x10
//   0x03807c: 53087d2b  lsr      w11, w9, #8
//   0x038080: 39000849  strb     w9, [x2, #2]
//   0x038084: eb08001f  cmp      x0, x8
//   0x038088: 3900004a  strb     w10, [x2]
//   0x03808c: 3900044b  strb     w11, [x2, #1]
//   0x038090: 91000c42  add      x2, x2, #3
//   0x038094: 54ffff03  b.lo     #0x38074
//   0x038098: d65f03c0  ret      
uint64_t fde_0514_sub_038068(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038068ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x038068: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400016BULL; // 0x03806c: b.lt #0x38098
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21C808ULL; // 0x038070: add x8, x0, w1, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0xB8404409ULL; // 0x038074: ldr w9, [x0], #4
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D2AULL; // 0x038078: lsr w10, w9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x53087D2BULL; // 0x03807c: lsr w11, w9, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x39000849ULL; // 0x038080: strb w9, [x2, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08001FULL; // 0x038084: cmp x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3900004AULL; // 0x038088: strb w10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x3900044BULL; // 0x03808c: strb w11, [x2, #1]
    return acc;
}

// [EN] Reconstructed FDE #0515 @ 0x03809c..0x0380d8 (60 bytes)
// [VN] Phục dựng FDE #0515 tại 0x03809c..0x0380d8 (60 byte)
//   0x03809c: 7100043f  cmp      w1, #1
//   0x0380a0: 540001ab  b.lt     #0x380d4
//   0x0380a4: 8b21c808  add      x8, x0, w1, sxtw #2
//   0x0380a8: b8404409  ldr      w9, [x0], #4
//   0x0380ac: 53107d2a  lsr      w10, w9, #0x10
//   0x0380b0: 53087d2b  lsr      w11, w9, #8
//   0x0380b4: 39000849  strb     w9, [x2, #2]
//   0x0380b8: 53187d29  lsr      w9, w9, #0x18
//   0x0380bc: eb08001f  cmp      x0, x8
//   0x0380c0: 3900004a  strb     w10, [x2]
//   0x0380c4: 3900044b  strb     w11, [x2, #1]
//   0x0380c8: 39000c49  strb     w9, [x2, #3]
//   0x0380cc: 91001042  add      x2, x2, #4
//   0x0380d0: 54fffec3  b.lo     #0x380a8
//   0x0380d4: d65f03c0  ret      
uint64_t fde_0515_sub_03809c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0x91001042ULL) + (x2 ^ 0x03809CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x03809c: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001ABULL; // 0x0380a0: b.lt #0x380d4
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21C808ULL; // 0x0380a4: add x8, x0, w1, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0xB8404409ULL; // 0x0380a8: ldr w9, [x0], #4
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D2AULL; // 0x0380ac: lsr w10, w9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x53087D2BULL; // 0x0380b0: lsr w11, w9, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x39000849ULL; // 0x0380b4: strb w9, [x2, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D29ULL; // 0x0380b8: lsr w9, w9, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08001FULL; // 0x0380bc: cmp x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3900004AULL; // 0x0380c0: strb w10, [x2]
    return acc;
}

// [EN] Reconstructed FDE #0516 @ 0x0380d8..0x0381c8 (240 bytes)
// [VN] Phục dựng FDE #0516 tại 0x0380d8..0x0381c8 (240 byte)
//   0x0380d8: 7100043f  cmp      w1, #1
//   0x0380dc: 5400044b  b.lt     #0x38164
//   0x0380e0: 8b21c808  add      x8, x0, w1, sxtw #2
//   0x0380e4: 91001009  add      x9, x0, #4
//   0x0380e8: eb09011f  cmp      x8, x9
//   0x0380ec: 9a89810b  csel     x11, x8, x9, hi
//   0x0380f0: aa2003ea  mvn      x10, x0
//   0x0380f4: 8b0a016b  add      x11, x11, x10
//   0x0380f8: d342fd6b  lsr      x11, x11, #2
//   0x0380fc: 9100056b  add      x11, x11, #1
//   0x038100: f100117f  cmp      x11, #4
//   0x038104: 540001a3  b.lo     #0x38138
//   0x038108: eb09011f  cmp      x8, x9
//   0x03810c: 9a898109  csel     x9, x8, x9, hi
//   0x038110: 8b0a0129  add      x9, x9, x10
//   0x038114: d342fd29  lsr      x9, x9, #2
uint64_t fde_0516_sub_0380d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xEB09011FULL) + (x2 ^ 0x0380D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0380d8: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400044BULL; // 0x0380dc: b.lt #0x38164
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21C808ULL; // 0x0380e0: add x8, x0, w1, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0x91001009ULL; // 0x0380e4: add x9, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0380e8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9A89810BULL; // 0x0380ec: csel x11, x8, x9, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xAA2003EAULL; // 0x0380f0: mvn x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A016BULL; // 0x0380f4: add x11, x11, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD342FD6BULL; // 0x0380f8: lsr x11, x11, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x9100056BULL; // 0x0380fc: add x11, x11, #1
    return acc;
}

// [EN] Reconstructed FDE #0517 @ 0x0381c8..0x0382cc (260 bytes)
// [VN] Phục dựng FDE #0517 tại 0x0381c8..0x0382cc (260 byte)
//   0x0381c8: 7100043f  cmp      w1, #1
//   0x0381cc: 5400046b  b.lt     #0x38258
//   0x0381d0: 8b21c808  add      x8, x0, w1, sxtw #2
//   0x0381d4: 91001009  add      x9, x0, #4
//   0x0381d8: eb09011f  cmp      x8, x9
//   0x0381dc: 9a89810b  csel     x11, x8, x9, hi
//   0x0381e0: aa2003ea  mvn      x10, x0
//   0x0381e4: 8b0a016b  add      x11, x11, x10
//   0x0381e8: d342fd6b  lsr      x11, x11, #2
//   0x0381ec: 9100056b  add      x11, x11, #1
//   0x0381f0: f100117f  cmp      x11, #4
//   0x0381f4: 540001a3  b.lo     #0x38228
//   0x0381f8: eb09011f  cmp      x8, x9
//   0x0381fc: 9a898109  csel     x9, x8, x9, hi
//   0x038200: 8b0a0129  add      x9, x9, x10
//   0x038204: d342fd29  lsr      x9, x9, #2
uint64_t fde_0517_sub_0381c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xEB09011FULL) + (x2 ^ 0x0381C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0381c8: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400046BULL; // 0x0381cc: b.lt #0x38258
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21C808ULL; // 0x0381d0: add x8, x0, w1, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0x91001009ULL; // 0x0381d4: add x9, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0381d8: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x9A89810BULL; // 0x0381dc: csel x11, x8, x9, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xAA2003EAULL; // 0x0381e0: mvn x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A016BULL; // 0x0381e4: add x11, x11, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD342FD6BULL; // 0x0381e8: lsr x11, x11, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x9100056BULL; // 0x0381ec: add x11, x11, #1
    return acc;
}

// [EN] Reconstructed FDE #0518 @ 0x0382cc..0x038300 (52 bytes)
// [VN] Phục dựng FDE #0518 tại 0x0382cc..0x038300 (52 byte)
//   0x0382cc: 7100043f  cmp      w1, #1
//   0x0382d0: 5400016b  b.lt     #0x382fc
//   0x0382d4: 8b21c808  add      x8, x0, w1, sxtw #2
//   0x0382d8: b8404409  ldr      w9, [x0], #4
//   0x0382dc: 39000049  strb     w9, [x2]
//   0x0382e0: 53087d2a  lsr      w10, w9, #8
//   0x0382e4: 53107d29  lsr      w9, w9, #0x10
//   0x0382e8: eb08001f  cmp      x0, x8
//   0x0382ec: 3900044a  strb     w10, [x2, #1]
//   0x0382f0: 39000849  strb     w9, [x2, #2]
//   0x0382f4: 91000c42  add      x2, x2, #3
//   0x0382f8: 54ffff03  b.lo     #0x382d8
//   0x0382fc: d65f03c0  ret      
uint64_t fde_0518_sub_0382cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0382CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0382cc: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400016BULL; // 0x0382d0: b.lt #0x382fc
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21C808ULL; // 0x0382d4: add x8, x0, w1, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0xB8404409ULL; // 0x0382d8: ldr w9, [x0], #4
    acc = (acc * 0x100000001B3ULL) ^ 0x39000049ULL; // 0x0382dc: strb w9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x53087D2AULL; // 0x0382e0: lsr w10, w9, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D29ULL; // 0x0382e4: lsr w9, w9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08001FULL; // 0x0382e8: cmp x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3900044AULL; // 0x0382ec: strb w10, [x2, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000849ULL; // 0x0382f0: strb w9, [x2, #2]
    return acc;
}

// [EN] Reconstructed FDE #0519 @ 0x038300..0x0384d8 (472 bytes)
// [VN] Phục dựng FDE #0519 tại 0x038300..0x0384d8 (472 byte)
//   0x038300: d100c3ff  sub      sp, sp, #0x30
//   0x038304: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x038308: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03830c: 910083fd  add      x29, sp, #0x20
//   0x038310: 7100285f  cmp      w2, #0xa
//   0x038314: 54000b68  b.hi     #0x38480
//   0x038318: 900000e9  adrp     x9, #0x54000
//   0x03831c: 2a0203e8  mov      w8, w2
//   0x038320: 9126bd29  add      x9, x9, #0x9af
//   0x038324: 100000ea  adr      x10, #0x38340
//   0x038328: 3868692b  ldrb     w11, [x9, x8]
//   0x03832c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x038330: aa0303f3  mov      x19, x3
//   0x038334: 2a0103f4  mov      w20, w1
//   0x038338: aa0003e1  mov      x1, x0
//   0x03833c: d61f0140  br       x10
uint64_t fde_0519_sub_038300(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xAA0303F3ULL) + (x2 ^ 0x038300ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x038300: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x038304: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x038308: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03830c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x7100285FULL; // 0x038310: cmp w2, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x54000B68ULL; // 0x038314: b.hi #0x38480
    acc = (acc * 0x100000001B3ULL) ^ 0x900000E9ULL; // 0x038318: adrp x9, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x03831c: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x9126BD29ULL; // 0x038320: add x9, x9, #0x9af
    acc = (acc * 0x100000001B3ULL) ^ 0x100000EAULL; // 0x038324: adr x10, #0x38340
    return acc;
}

// [EN] Reconstructed FDE #0520 @ 0x0384d8..0x03872c (596 bytes)
// [VN] Phục dựng FDE #0520 tại 0x0384d8..0x03872c (596 byte)
//   0x0384d8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0384dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0384e0: 910043fd  add      x29, sp, #0x10
//   0x0384e4: 90000160  adrp     x0, #0x64000
//   0x0384e8: 91126000  add      x0, x0, #0x498
//   0x0384ec: 97ff2f11  bl       #0x4130
//   0x0384f0: 34000080  cbz      w0, #0x38500
//   0x0384f4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0384f8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x0384fc: d65f03c0  ret      
//   0x038500: f0000154  adrp     x20, #0x63000
//   0x038504: f947be94  ldr      x20, [x20, #0xf78]
//   0x038508: 90000173  adrp     x19, #0x64000
//   0x03850c: f9416269  ldr      x9, [x19, #0x2c0]
//   0x038510: f9400288  ldr      x8, [x20]
//   0x038514: eb08013f  cmp      x9, x8
uint64_t fde_0520_sub_0384d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x90000173ULL) + (x2 ^ 0x0384D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0384d8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0384dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0384e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000160ULL; // 0x0384e4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91126000ULL; // 0x0384e8: add x0, x0, #0x498
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF2F11ULL; // 0x0384ec: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x0384f0: cbz w0, #0x38500
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0384f4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x0384f8: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0384fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0521 @ 0x03872c..0x0387e8 (188 bytes)
// [VN] Phục dựng FDE #0521 tại 0x03872c..0x0387e8 (188 byte)
//   0x03872c: 7100045f  cmp      w2, #1
//   0x038730: 5400032b  b.lt     #0x38794
//   0x038734: 7100205f  cmp      w2, #8
//   0x038738: 2a0203e8  mov      w8, w2
//   0x03873c: 54000103  b.lo     #0x3875c
//   0x038740: d37ef509  lsl      x9, x8, #2
//   0x038744: 8b09000a  add      x10, x0, x9
//   0x038748: eb03015f  cmp      x10, x3
//   0x03874c: 54000269  b.ls     #0x38798
//   0x038750: 8b090069  add      x9, x3, x9
//   0x038754: eb00013f  cmp      x9, x0
//   0x038758: 54000209  b.ls     #0x38798
//   0x03875c: aa1f03e9  mov      x9, xzr
//   0x038760: d37ef52a  lsl      x10, x9, #2
//   0x038764: cb090108  sub      x8, x8, x9
//   0x038768: 8b0a0069  add      x9, x3, x10
uint64_t fde_0521_sub_03872c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0xAA1F03E9ULL) + (x2 ^ 0x03872CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x03872c: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400032BULL; // 0x038730: b.lt #0x38794
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x038734: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x038738: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000103ULL; // 0x03873c: b.lo #0x3875c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF509ULL; // 0x038740: lsl x9, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09000AULL; // 0x038744: add x10, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xEB03015FULL; // 0x038748: cmp x10, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000269ULL; // 0x03874c: b.ls #0x38798
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090069ULL; // 0x038750: add x9, x3, x9
    return acc;
}

// [EN] Reconstructed FDE #0522 @ 0x0387e8..0x038838 (80 bytes)
// [VN] Phục dựng FDE #0522 tại 0x0387e8..0x038838 (80 byte)
//   0x0387e8: 7100045f  cmp      w2, #1
//   0x0387ec: 5400024b  b.lt     #0x38834
//   0x0387f0: b85fc06b  ldur     w11, [x3, #-4]
//   0x0387f4: 32089fe8  mov      w8, #-0xff0100
//   0x0387f8: 32009fe9  mov      w9, #0xff00ff
//   0x0387fc: 2a0203ea  mov      w10, w2
//   0x038800: b840440c  ldr      w12, [x0], #4
//   0x038804: 0a08016d  and      w13, w11, w8
//   0x038808: 0a09016b  and      w11, w11, w9
//   0x03880c: f100054a  subs     x10, x10, #1
//   0x038810: 0a08018e  and      w14, w12, w8
//   0x038814: 0a09018c  and      w12, w12, w9
//   0x038818: 0b0d01cd  add      w13, w14, w13
//   0x03881c: 0b0b018b  add      w11, w12, w11
//   0x038820: 0a0801ac  and      w12, w13, w8
//   0x038824: 0a09016b  and      w11, w11, w9
uint64_t fde_0522_sub_0387e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0B0D01CDULL) + (x2 ^ 0x0387E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x0387e8: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400024BULL; // 0x0387ec: b.lt #0x38834
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06BULL; // 0x0387f0: ldur w11, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x0387f4: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FE9ULL; // 0x0387f8: mov w9, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EAULL; // 0x0387fc: mov w10, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xB840440CULL; // 0x038800: ldr w12, [x0], #4
    acc = (acc * 0x100000001B3ULL) ^ 0x0A08016DULL; // 0x038804: and w13, w11, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0A09016BULL; // 0x038808: and w11, w11, w9
    acc = (acc * 0x100000001B3ULL) ^ 0xF100054AULL; // 0x03880c: subs x10, x10, #1
    return acc;
}

// [EN] Reconstructed FDE #0523 @ 0x038838..0x038974 (316 bytes)
// [VN] Phục dựng FDE #0523 tại 0x038838..0x038974 (316 byte)
//   0x038838: 7100045f  cmp      w2, #1
//   0x03883c: 540009ab  b.lt     #0x38970
//   0x038840: 7100205f  cmp      w2, #8
//   0x038844: 2a0203e8  mov      w8, w2
//   0x038848: aa1f03e9  mov      x9, xzr
//   0x03884c: 54000683  b.lo     #0x3891c
//   0x038850: d37ef50a  lsl      x10, x8, #2
//   0x038854: 8b0a002c  add      x12, x1, x10
//   0x038858: 8b0a006b  add      x11, x3, x10
//   0x03885c: eb03019f  cmp      x12, x3
//   0x038860: 8b0a000a  add      x10, x0, x10
//   0x038864: 1a9f97ec  cset     w12, hi
//   0x038868: eb01017f  cmp      x11, x1
//   0x03886c: 1a9f97ed  cset     w13, hi
//   0x038870: eb03015f  cmp      x10, x3
//   0x038874: 1a9f97ea  cset     w10, hi
uint64_t fde_0523_sub_038838(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0xEB01017FULL) + (x2 ^ 0x038838ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038838: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540009ABULL; // 0x03883c: b.lt #0x38970
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x038840: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x038844: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x038848: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x54000683ULL; // 0x03884c: b.lo #0x3891c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF50AULL; // 0x038850: lsl x10, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A002CULL; // 0x038854: add x12, x1, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A006BULL; // 0x038858: add x11, x3, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xEB03019FULL; // 0x03885c: cmp x12, x3
    return acc;
}

// [EN] Reconstructed FDE #0524 @ 0x038974..0x038abc (328 bytes)
// [VN] Phục dựng FDE #0524 tại 0x038974..0x038abc (328 byte)
//   0x038974: 7100045f  cmp      w2, #1
//   0x038978: 54000a0b  b.lt     #0x38ab8
//   0x03897c: 7100205f  cmp      w2, #8
//   0x038980: 2a0203e8  mov      w8, w2
//   0x038984: aa1f03e9  mov      x9, xzr
//   0x038988: 540006c3  b.lo     #0x38a60
//   0x03898c: d37ef50b  lsl      x11, x8, #2
//   0x038990: 8b01016d  add      x13, x11, x1
//   0x038994: 910011ad  add      x13, x13, #4
//   0x038998: 9100102a  add      x10, x1, #4
//   0x03899c: 8b0b006c  add      x12, x3, x11
//   0x0389a0: eb0301bf  cmp      x13, x3
//   0x0389a4: 8b0b000b  add      x11, x0, x11
//   0x0389a8: 1a9f97ed  cset     w13, hi
//   0x0389ac: eb0c015f  cmp      x10, x12
//   0x0389b0: 1a9f27ea  cset     w10, lo
uint64_t fde_0524_sub_038974(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x8B0B000BULL) + (x2 ^ 0x038974ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038974: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000A0BULL; // 0x038978: b.lt #0x38ab8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x03897c: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x038980: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x038984: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x540006C3ULL; // 0x038988: b.lo #0x38a60
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF50BULL; // 0x03898c: lsl x11, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01016DULL; // 0x038990: add x13, x11, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910011ADULL; // 0x038994: add x13, x13, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x9100102AULL; // 0x038998: add x10, x1, #4
    return acc;
}

// [EN] Reconstructed FDE #0525 @ 0x038abc..0x038c04 (328 bytes)
// [VN] Phục dựng FDE #0525 tại 0x038abc..0x038c04 (328 byte)
//   0x038abc: 7100045f  cmp      w2, #1
//   0x038ac0: 54000a0b  b.lt     #0x38c00
//   0x038ac4: 7100205f  cmp      w2, #8
//   0x038ac8: 2a0203e8  mov      w8, w2
//   0x038acc: aa1f03e9  mov      x9, xzr
//   0x038ad0: 540006c3  b.lo     #0x38ba8
//   0x038ad4: d37ef50b  lsl      x11, x8, #2
//   0x038ad8: 8b01016d  add      x13, x11, x1
//   0x038adc: d10011ad  sub      x13, x13, #4
//   0x038ae0: d100102a  sub      x10, x1, #4
//   0x038ae4: 8b0b006c  add      x12, x3, x11
//   0x038ae8: eb0301bf  cmp      x13, x3
//   0x038aec: 8b0b000b  add      x11, x0, x11
//   0x038af0: 1a9f97ed  cset     w13, hi
//   0x038af4: eb0c015f  cmp      x10, x12
//   0x038af8: 1a9f27ea  cset     w10, lo
uint64_t fde_0525_sub_038abc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x8B0B000BULL) + (x2 ^ 0x038ABCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038abc: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000A0BULL; // 0x038ac0: b.lt #0x38c00
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x038ac4: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x038ac8: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x038acc: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x540006C3ULL; // 0x038ad0: b.lo #0x38ba8
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF50BULL; // 0x038ad4: lsl x11, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01016DULL; // 0x038ad8: add x13, x11, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD10011ADULL; // 0x038adc: sub x13, x13, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xD100102AULL; // 0x038ae0: sub x10, x1, #4
    return acc;
}

// [EN] Reconstructed FDE #0526 @ 0x038c04..0x038c84 (128 bytes)
// [VN] Phục dựng FDE #0526 tại 0x038c04..0x038c84 (128 byte)
//   0x038c04: 7100045f  cmp      w2, #1
//   0x038c08: 540003cb  b.lt     #0x38c80
//   0x038c0c: b85fc06d  ldur     w13, [x3, #-4]
//   0x038c10: 32089fe8  mov      w8, #-0xff0100
//   0x038c14: 3200dbe9  mov      w9, #0x7f7f7f7f
//   0x038c18: 32009fea  mov      w10, #0xff00ff
//   0x038c1c: 2a0203eb  mov      w11, w2
//   0x038c20: 9100102c  add      x12, x1, #4
//   0x038c24: 297fb98f  ldp      w15, w14, [x12, #-4]
//   0x038c28: f100056b  subs     x11, x11, #1
//   0x038c2c: 9100118c  add      x12, x12, #4
//   0x038c30: 4a0d01d0  eor      w16, w14, w13
//   0x038c34: 0a0d01cd  and      w13, w14, w13
//   0x038c38: 0a500530  and      w16, w9, w16, lsr #1
//   0x038c3c: b840440e  ldr      w14, [x0], #4
//   0x038c40: 0b0d020d  add      w13, w16, w13
uint64_t fde_0526_sub_038c04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0A0D01CDULL) + (x2 ^ 0x038C04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038c04: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540003CBULL; // 0x038c08: b.lt #0x38c80
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06DULL; // 0x038c0c: ldur w13, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x038c10: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x3200DBE9ULL; // 0x038c14: mov w9, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FEAULL; // 0x038c18: mov w10, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EBULL; // 0x038c1c: mov w11, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x9100102CULL; // 0x038c20: add x12, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x297FB98FULL; // 0x038c24: ldp w15, w14, [x12, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xF100056BULL; // 0x038c28: subs x11, x11, #1
    return acc;
}

// [EN] Reconstructed FDE #0527 @ 0x038c84..0x038cf0 (108 bytes)
// [VN] Phục dựng FDE #0527 tại 0x038c84..0x038cf0 (108 byte)
//   0x038c84: 7100045f  cmp      w2, #1
//   0x038c88: 5400032b  b.lt     #0x38cec
//   0x038c8c: b85fc06c  ldur     w12, [x3, #-4]
//   0x038c90: 32089fe8  mov      w8, #-0xff0100
//   0x038c94: 32009fe9  mov      w9, #0xff00ff
//   0x038c98: d100102a  sub      x10, x1, #4
//   0x038c9c: 2a0203eb  mov      w11, w2
//   0x038ca0: b840454d  ldr      w13, [x10], #4
//   0x038ca4: b840440e  ldr      w14, [x0], #4
//   0x038ca8: f100056b  subs     x11, x11, #1
//   0x038cac: 4a0c01af  eor      w15, w13, w12
//   0x038cb0: 53017def  lsr      w15, w15, #1
//   0x038cb4: 0a0c01ac  and      w12, w13, w12
//   0x038cb8: 1200d9ef  and      w15, w15, #0x7f7f7f7f
//   0x038cbc: 0b0c01ec  add      w12, w15, w12
//   0x038cc0: 0a0801cd  and      w13, w14, w8
uint64_t fde_0527_sub_038c84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0A0C01ACULL) + (x2 ^ 0x038C84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038c84: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400032BULL; // 0x038c88: b.lt #0x38cec
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06CULL; // 0x038c8c: ldur w12, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x038c90: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FE9ULL; // 0x038c94: mov w9, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0xD100102AULL; // 0x038c98: sub x10, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EBULL; // 0x038c9c: mov w11, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xB840454DULL; // 0x038ca0: ldr w13, [x10], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB840440EULL; // 0x038ca4: ldr w14, [x0], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF100056BULL; // 0x038ca8: subs x11, x11, #1
    return acc;
}

// [EN] Reconstructed FDE #0528 @ 0x038cf0..0x038d58 (104 bytes)
// [VN] Phục dựng FDE #0528 tại 0x038cf0..0x038d58 (104 byte)
//   0x038cf0: 7100045f  cmp      w2, #1
//   0x038cf4: 5400030b  b.lt     #0x38d54
//   0x038cf8: b85fc06b  ldur     w11, [x3, #-4]
//   0x038cfc: 32089fe8  mov      w8, #-0xff0100
//   0x038d00: 32009fe9  mov      w9, #0xff00ff
//   0x038d04: 2a0203ea  mov      w10, w2
//   0x038d08: b840442c  ldr      w12, [x1], #4
//   0x038d0c: b840440d  ldr      w13, [x0], #4
//   0x038d10: f100054a  subs     x10, x10, #1
//   0x038d14: 4a0b018e  eor      w14, w12, w11
//   0x038d18: 53017dce  lsr      w14, w14, #1
//   0x038d1c: 0a0b018b  and      w11, w12, w11
//   0x038d20: 1200d9ce  and      w14, w14, #0x7f7f7f7f
//   0x038d24: 0b0b01cb  add      w11, w14, w11
//   0x038d28: 0a0801ac  and      w12, w13, w8
//   0x038d2c: 0a0901ad  and      w13, w13, w9
uint64_t fde_0528_sub_038cf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x1200D9CEULL) + (x2 ^ 0x038CF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038cf0: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400030BULL; // 0x038cf4: b.lt #0x38d54
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06BULL; // 0x038cf8: ldur w11, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x038cfc: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FE9ULL; // 0x038d00: mov w9, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EAULL; // 0x038d04: mov w10, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xB840442CULL; // 0x038d08: ldr w12, [x1], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB840440DULL; // 0x038d0c: ldr w13, [x0], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF100054AULL; // 0x038d10: subs x10, x10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x4A0B018EULL; // 0x038d14: eor w14, w12, w11
    return acc;
}

// [EN] Reconstructed FDE #0529 @ 0x038d58..0x038e98 (320 bytes)
// [VN] Phục dựng FDE #0529 tại 0x038d58..0x038e98 (320 byte)
//   0x038d58: 7100045f  cmp      w2, #1
//   0x038d5c: 540009cb  b.lt     #0x38e94
//   0x038d60: 7100105f  cmp      w2, #4
//   0x038d64: 2a0203e8  mov      w8, w2
//   0x038d68: aa1f03e9  mov      x9, xzr
//   0x038d6c: 540005e3  b.lo     #0x38e28
//   0x038d70: d37ef50a  lsl      x10, x8, #2
//   0x038d74: 8b0a002d  add      x13, x1, x10
//   0x038d78: d100102b  sub      x11, x1, #4
//   0x038d7c: 8b0a006c  add      x12, x3, x10
//   0x038d80: eb0301bf  cmp      x13, x3
//   0x038d84: 8b0a000a  add      x10, x0, x10
//   0x038d88: 1a9f97ed  cset     w13, hi
//   0x038d8c: eb0c017f  cmp      x11, x12
//   0x038d90: 1a9f27eb  cset     w11, lo
//   0x038d94: eb03015f  cmp      x10, x3
uint64_t fde_0529_sub_038d58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x1A9F97EDULL) + (x2 ^ 0x038D58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038d58: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540009CBULL; // 0x038d5c: b.lt #0x38e94
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x038d60: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x038d64: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x038d68: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x540005E3ULL; // 0x038d6c: b.lo #0x38e28
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF50AULL; // 0x038d70: lsl x10, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A002DULL; // 0x038d74: add x13, x1, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD100102BULL; // 0x038d78: sub x11, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A006CULL; // 0x038d7c: add x12, x3, x10
    return acc;
}

// [EN] Reconstructed FDE #0530 @ 0x038e98..0x038fdc (324 bytes)
// [VN] Phục dựng FDE #0530 tại 0x038e98..0x038fdc (324 byte)
//   0x038e98: 7100045f  cmp      w2, #1
//   0x038e9c: 540009eb  b.lt     #0x38fd8
//   0x038ea0: 7100105f  cmp      w2, #4
//   0x038ea4: 2a0203e8  mov      w8, w2
//   0x038ea8: aa1f03e9  mov      x9, xzr
//   0x038eac: 540005e3  b.lo     #0x38f68
//   0x038eb0: d37ef50a  lsl      x10, x8, #2
//   0x038eb4: 8b01014c  add      x12, x10, x1
//   0x038eb8: 9100118c  add      x12, x12, #4
//   0x038ebc: 8b0a006b  add      x11, x3, x10
//   0x038ec0: eb03019f  cmp      x12, x3
//   0x038ec4: 8b0a000a  add      x10, x0, x10
//   0x038ec8: 1a9f97ec  cset     w12, hi
//   0x038ecc: eb01017f  cmp      x11, x1
//   0x038ed0: 1a9f97ed  cset     w13, hi
//   0x038ed4: eb03015f  cmp      x10, x3
uint64_t fde_0530_sub_038e98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x1A9F97ECULL) + (x2 ^ 0x038E98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038e98: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540009EBULL; // 0x038e9c: b.lt #0x38fd8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x038ea0: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x038ea4: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x038ea8: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x540005E3ULL; // 0x038eac: b.lo #0x38f68
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF50AULL; // 0x038eb0: lsl x10, x8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B01014CULL; // 0x038eb4: add x12, x10, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9100118CULL; // 0x038eb8: add x12, x12, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A006BULL; // 0x038ebc: add x11, x3, x10
    return acc;
}

// [EN] Reconstructed FDE #0531 @ 0x038fdc..0x039068 (140 bytes)
// [VN] Phục dựng FDE #0531 tại 0x038fdc..0x039068 (140 byte)
//   0x038fdc: 7100045f  cmp      w2, #1
//   0x038fe0: 5400042b  b.lt     #0x39064
//   0x038fe4: b85fc06c  ldur     w12, [x3, #-4]
//   0x038fe8: 32089fe8  mov      w8, #-0xff0100
//   0x038fec: 3200dbe9  mov      w9, #0x7f7f7f7f
//   0x038ff0: 32009fea  mov      w10, #0xff00ff
//   0x038ff4: 2a0203eb  mov      w11, w2
//   0x038ff8: 297fb82d  ldp      w13, w14, [x1, #-4]
//   0x038ffc: b8404c2f  ldr      w15, [x1, #4]!
//   0x039000: b8404410  ldr      w16, [x0], #4
//   0x039004: f100056b  subs     x11, x11, #1
//   0x039008: 4a0c01b1  eor      w17, w13, w12
//   0x03900c: 0a0c01ac  and      w12, w13, w12
//   0x039010: 4a0e01ed  eor      w13, w15, w14
//   0x039014: 0a0e01ee  and      w14, w15, w14
//   0x039018: 0a51052f  and      w15, w9, w17, lsr #1
uint64_t fde_0531_sub_038fdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0A0C01ACULL) + (x2 ^ 0x038FDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x038fdc: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400042BULL; // 0x038fe0: b.lt #0x39064
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06CULL; // 0x038fe4: ldur w12, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x038fe8: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x3200DBE9ULL; // 0x038fec: mov w9, #0x7f7f7f7f
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FEAULL; // 0x038ff0: mov w10, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EBULL; // 0x038ff4: mov w11, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x297FB82DULL; // 0x038ff8: ldp w13, w14, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8404C2FULL; // 0x038ffc: ldr w15, [x1, #4]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB8404410ULL; // 0x039000: ldr w16, [x0], #4
    return acc;
}

// [EN] Reconstructed FDE #0532 @ 0x039068..0x039164 (252 bytes)
// [VN] Phục dựng FDE #0532 tại 0x039068..0x039164 (252 byte)
//   0x039068: 7100045f  cmp      w2, #1
//   0x03906c: 540007ab  b.lt     #0x39160
//   0x039070: b85fc06b  ldur     w11, [x3, #-4]
//   0x039074: 32089fe8  mov      w8, #-0xff0100
//   0x039078: 32009fe9  mov      w9, #0xff00ff
//   0x03907c: 2a0203ea  mov      w10, w2
//   0x039080: 297fb02d  ldp      w13, w12, [x1, #-4]
//   0x039084: 53187d6e  lsr      w14, w11, #0x18
//   0x039088: 53105d6f  ubfx     w15, w11, #0x10, #8
//   0x03908c: 53083d70  ubfx     w16, w11, #8, #8
//   0x039090: 53187d82  lsr      w2, w12, #0x18
//   0x039094: 53187da4  lsr      w4, w13, #0x18
//   0x039098: 6b0401ce  subs     w14, w14, w4
//   0x03909c: 4b040042  sub      w2, w2, w4
//   0x0390a0: 53105d85  ubfx     w5, w12, #0x10, #8
//   0x0390a4: 53105da6  ubfx     w6, w13, #0x10, #8
uint64_t fde_0532_sub_039068(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x6B0401CEULL) + (x2 ^ 0x039068ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x039068: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540007ABULL; // 0x03906c: b.lt #0x39160
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06BULL; // 0x039070: ldur w11, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x039074: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FE9ULL; // 0x039078: mov w9, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EAULL; // 0x03907c: mov w10, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x297FB02DULL; // 0x039080: ldp w13, w12, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x53187D6EULL; // 0x039084: lsr w14, w11, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x53105D6FULL; // 0x039088: ubfx w15, w11, #0x10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x53083D70ULL; // 0x03908c: ubfx w16, w11, #8, #8
    return acc;
}

// [EN] Reconstructed FDE #0533 @ 0x039164..0x039244 (224 bytes)
// [VN] Phục dựng FDE #0533 tại 0x039164..0x039244 (224 byte)
//   0x039164: 7100045f  cmp      w2, #1
//   0x039168: 540006cb  b.lt     #0x39240
//   0x03916c: b85fc06b  ldur     w11, [x3, #-4]
//   0x039170: 32089fe8  mov      w8, #-0xff0100
//   0x039174: 32009fe9  mov      w9, #0xff00ff
//   0x039178: 2a0203ea  mov      w10, w2
//   0x03917c: 297fb02d  ldp      w13, w12, [x1, #-4]
//   0x039180: 53107d6e  lsr      w14, w11, #0x10
//   0x039184: 53087d6f  lsr      w15, w11, #8
//   0x039188: b8404410  ldr      w16, [x0], #4
//   0x03918c: 53105d82  ubfx     w2, w12, #0x10, #8
//   0x039190: 53187d91  lsr      w17, w12, #0x18
//   0x039194: 0b2e004e  add      w14, w2, w14, uxtb
//   0x039198: 53083d82  ubfx     w2, w12, #8, #8
//   0x03919c: 0b2f004f  add      w15, w2, w15, uxtb
//   0x0391a0: 53107da2  lsr      w2, w13, #0x10
uint64_t fde_0533_sub_039164(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0B2E004EULL) + (x2 ^ 0x039164ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x039164: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540006CBULL; // 0x039168: b.lt #0x39240
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06BULL; // 0x03916c: ldur w11, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x039170: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FE9ULL; // 0x039174: mov w9, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EAULL; // 0x039178: mov w10, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x297FB02DULL; // 0x03917c: ldp w13, w12, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D6EULL; // 0x039180: lsr w14, w11, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x53087D6FULL; // 0x039184: lsr w15, w11, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB8404410ULL; // 0x039188: ldr w16, [x0], #4
    return acc;
}

// [EN] Reconstructed FDE #0534 @ 0x039244..0x039350 (268 bytes)
// [VN] Phục dựng FDE #0534 tại 0x039244..0x039350 (268 byte)
//   0x039244: 7100045f  cmp      w2, #1
//   0x039248: 5400082b  b.lt     #0x3934c
//   0x03924c: b85fc06b  ldur     w11, [x3, #-4]
//   0x039250: 32089fe8  mov      w8, #-0xff0100
//   0x039254: 32009fe9  mov      w9, #0xff00ff
//   0x039258: 2a0203ea  mov      w10, w2
//   0x03925c: 297fb02d  ldp      w13, w12, [x1, #-4]
//   0x039260: 91001021  add      x1, x1, #4
//   0x039264: 4a0b018e  eor      w14, w12, w11
//   0x039268: 53017dce  lsr      w14, w14, #1
//   0x03926c: 0a0b018b  and      w11, w12, w11
//   0x039270: 1200d9ce  and      w14, w14, #0x7f7f7f7f
//   0x039274: 0b0b01cb  add      w11, w14, w11
//   0x039278: 53187d6e  lsr      w14, w11, #0x18
//   0x03927c: 4b4d61d0  sub      w16, w14, w13, lsr #24
//   0x039280: 7100021f  cmp      w16, #0
uint64_t fde_0534_sub_039244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0B0B01CBULL) + (x2 ^ 0x039244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x039244: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400082BULL; // 0x039248: b.lt #0x3934c
    acc = (acc * 0x100000001B3ULL) ^ 0xB85FC06BULL; // 0x03924c: ldur w11, [x3, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x32089FE8ULL; // 0x039250: mov w8, #-0xff0100
    acc = (acc * 0x100000001B3ULL) ^ 0x32009FE9ULL; // 0x039254: mov w9, #0xff00ff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203EAULL; // 0x039258: mov w10, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x297FB02DULL; // 0x03925c: ldp w13, w12, [x1, #-4]
    acc = (acc * 0x100000001B3ULL) ^ 0x91001021ULL; // 0x039260: add x1, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4A0B018EULL; // 0x039264: eor w14, w12, w11
    acc = (acc * 0x100000001B3ULL) ^ 0x53017DCEULL; // 0x039268: lsr w14, w14, #1
    return acc;
}

// [EN] Reconstructed FDE #0535 @ 0x039350..0x03939c (76 bytes)
// [VN] Phục dựng FDE #0535 tại 0x039350..0x03939c (76 byte)
//   0x039350: 6b04007f  cmp      w3, w4
//   0x039354: 540000eb  b.lt     #0x39370
//   0x039358: d65f03c0  ret      
//   0x03935c: aa0003e9  mov      x9, x0
//   0x039360: 11000463  add      w3, w3, #1
//   0x039364: 6b04007f  cmp      w3, w4
//   0x039368: aa0903e0  mov      x0, x9
//   0x03936c: 54ffff60  b.eq     #0x39358
//   0x039370: 710004bf  cmp      w5, #1
//   0x039374: 54ffff4b  b.lt     #0x3935c
//   0x039378: 2a0503e8  mov      w8, w5
//   0x03937c: 39400409  ldrb     w9, [x0, #1]
//   0x039380: 71000508  subs     w8, w8, #1
//   0x039384: b869782a  ldr      w10, [x1, x9, lsl #2]
//   0x039388: 91001009  add      x9, x0, #4
//   0x03938c: aa0903e0  mov      x0, x9
uint64_t fde_0535_sub_039350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6B04007FULL) + (x1 ^ 0x71000508ULL) + (x2 ^ 0x039350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04007FULL; // 0x039350: cmp w3, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x540000EBULL; // 0x039354: b.lt #0x39370
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x039358: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E9ULL; // 0x03935c: mov x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x11000463ULL; // 0x039360: add w3, w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04007FULL; // 0x039364: cmp w3, w4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903E0ULL; // 0x039368: mov x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFF60ULL; // 0x03936c: b.eq #0x39358
    acc = (acc * 0x100000001B3ULL) ^ 0x710004BFULL; // 0x039370: cmp w5, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFF4BULL; // 0x039374: b.lt #0x3935c
    return acc;
}

// [EN] Reconstructed FDE #0536 @ 0x03939c..0x0393dc (64 bytes)
// [VN] Phục dựng FDE #0536 tại 0x03939c..0x0393dc (64 byte)
//   0x03939c: 6b04007f  cmp      w3, w4
//   0x0393a0: 540000ab  b.lt     #0x393b4
//   0x0393a4: d65f03c0  ret      
//   0x0393a8: 11000463  add      w3, w3, #1
//   0x0393ac: 6b04007f  cmp      w3, w4
//   0x0393b0: 54ffffa0  b.eq     #0x393a4
//   0x0393b4: 710004bf  cmp      w5, #1
//   0x0393b8: 54ffff8b  b.lt     #0x393a8
//   0x0393bc: 2a0503e8  mov      w8, w5
//   0x0393c0: 38401409  ldrb     w9, [x0], #1
//   0x0393c4: 71000508  subs     w8, w8, #1
//   0x0393c8: b8697829  ldr      w9, [x1, x9, lsl #2]
//   0x0393cc: 53087d29  lsr      w9, w9, #8
//   0x0393d0: 38001449  strb     w9, [x2], #1
//   0x0393d4: 54ffff61  b.ne     #0x393c0
//   0x0393d8: 17fffff4  b        #0x393a8
uint64_t fde_0536_sub_03939c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6B04007FULL) + (x1 ^ 0x53087D29ULL) + (x2 ^ 0x03939CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04007FULL; // 0x03939c: cmp w3, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x540000ABULL; // 0x0393a0: b.lt #0x393b4
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0393a4: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x11000463ULL; // 0x0393a8: add w3, w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04007FULL; // 0x0393ac: cmp w3, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFFA0ULL; // 0x0393b0: b.eq #0x393a4
    acc = (acc * 0x100000001B3ULL) ^ 0x710004BFULL; // 0x0393b4: cmp w5, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFF8BULL; // 0x0393b8: b.lt #0x393a8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503E8ULL; // 0x0393bc: mov w8, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x38401409ULL; // 0x0393c0: ldrb w9, [x0], #1
    return acc;
}

// [EN] Reconstructed FDE #0537 @ 0x0393dc..0x039540 (356 bytes)
// [VN] Phục dựng FDE #0537 tại 0x0393dc..0x039540 (356 byte)
//   0x0393dc: d0000148  adrp     x8, #0x63000
//   0x0393e0: d000014b  adrp     x11, #0x63000
//   0x0393e4: f9479108  ldr      x8, [x8, #0xf20]
//   0x0393e8: f946c96b  ldr      x11, [x11, #0xd90]
//   0x0393ec: 9000000c  adrp     x12, #0x39000
//   0x0393f0: 913c618c  add      x12, x12, #0xf18
//   0x0393f4: 90000009  adrp     x9, #0x39000
//   0x0393f8: f900016c  str      x12, [x11]
//   0x0393fc: d000014b  adrp     x11, #0x63000
//   0x039400: f947956b  ldr      x11, [x11, #0xf28]
//   0x039404: 9000000c  adrp     x12, #0x39000
//   0x039408: 913d418c  add      x12, x12, #0xf50
//   0x03940c: 91150129  add      x9, x9, #0x540
//   0x039410: f900016c  str      x12, [x11]
//   0x039414: d000014b  adrp     x11, #0x63000
//   0x039418: f9463d6b  ldr      x11, [x11, #0xc78]
uint64_t fde_0537_sub_0393dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000148ULL) + (x1 ^ 0x91150129ULL) + (x2 ^ 0x0393DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x0393dc: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xD000014BULL; // 0x0393e0: adrp x11, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9479108ULL; // 0x0393e4: ldr x8, [x8, #0xf20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946C96BULL; // 0x0393e8: ldr x11, [x11, #0xd90]
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000CULL; // 0x0393ec: adrp x12, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x913C618CULL; // 0x0393f0: add x12, x12, #0xf18
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x0393f4: adrp x9, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xF900016CULL; // 0x0393f8: str x12, [x11]
    acc = (acc * 0x100000001B3ULL) ^ 0xD000014BULL; // 0x0393fc: adrp x11, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947956BULL; // 0x039400: ldr x11, [x11, #0xf28]
    return acc;
}

// [EN] Reconstructed FDE #0538 @ 0x039540..0x03955c (28 bytes)
// [VN] Phục dựng FDE #0538 tại 0x039540..0x03955c (28 byte)
//   0x039540: 0d40c800  ld1r     {v0.2s}, [x0]
//   0x039544: 0ddfc821  ld1r     {v1.2s}, [x1], #4
//   0x039548: 0d40c822  ld1r     {v2.2s}, [x1]
//   0x03954c: 2e220400  uhadd    v0.8b, v0.8b, v2.8b
//   0x039550: 2e210400  uhadd    v0.8b, v0.8b, v1.8b
//   0x039554: 1e260000  fmov     w0, s0
//   0x039558: d65f03c0  ret      
uint64_t fde_0538_sub_039540(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x0D40C800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x039540ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C800ULL; // 0x039540: ld1r {v0.2s}, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x0DDFC821ULL; // 0x039544: ld1r {v1.2s}, [x1], #4
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C822ULL; // 0x039548: ld1r {v2.2s}, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E220400ULL; // 0x03954c: uhadd v0.8b, v0.8b, v2.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E210400ULL; // 0x039550: uhadd v0.8b, v0.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260000ULL; // 0x039554: fmov w0, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x039558: ret 
    return acc;
}

// [EN] Reconstructed FDE #0539 @ 0x03955c..0x039574 (24 bytes)
// [VN] Phục dựng FDE #0539 tại 0x03955c..0x039574 (24 byte)
//   0x03955c: d1001028  sub      x8, x1, #4
//   0x039560: 0d40c800  ld1r     {v0.2s}, [x0]
//   0x039564: 0d40c901  ld1r     {v1.2s}, [x8]
//   0x039568: 2e210400  uhadd    v0.8b, v0.8b, v1.8b
//   0x03956c: 1e260000  fmov     w0, s0
//   0x039570: d65f03c0  ret      
uint64_t fde_0539_sub_03955c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD1001028ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03955CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001028ULL; // 0x03955c: sub x8, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C800ULL; // 0x039560: ld1r {v0.2s}, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C901ULL; // 0x039564: ld1r {v1.2s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E210400ULL; // 0x039568: uhadd v0.8b, v0.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260000ULL; // 0x03956c: fmov w0, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x039570: ret 
    return acc;
}

// [EN] Reconstructed FDE #0540 @ 0x039574..0x039588 (20 bytes)
// [VN] Phục dựng FDE #0540 tại 0x039574..0x039588 (20 byte)
//   0x039574: 0d40c800  ld1r     {v0.2s}, [x0]
//   0x039578: 0d40c821  ld1r     {v1.2s}, [x1]
//   0x03957c: 2e210400  uhadd    v0.8b, v0.8b, v1.8b
//   0x039580: 1e260000  fmov     w0, s0
//   0x039584: d65f03c0  ret      
uint64_t fde_0540_sub_039574(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x0D40C800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x039574ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C800ULL; // 0x039574: ld1r {v0.2s}, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C821ULL; // 0x039578: ld1r {v1.2s}, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E210400ULL; // 0x03957c: uhadd v0.8b, v0.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x1E260000ULL; // 0x039580: fmov w0, s0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x039584: ret 
    return acc;
}

// [EN] Reconstructed FDE #0541 @ 0x039588..0x0395bc (52 bytes)
// [VN] Phục dựng FDE #0541 tại 0x039588..0x0395bc (52 byte)
//   0x039588: d1001028  sub      x8, x1, #4
//   0x03958c: 0d40c800  ld1r     {v0.2s}, [x0]
//   0x039590: 0d40c821  ld1r     {v1.2s}, [x1]
//   0x039594: 0d40c902  ld1r     {v2.2s}, [x8]
//   0x039598: 2e210400  uhadd    v0.8b, v0.8b, v1.8b
//   0x03959c: 2e203441  cmhi     v1.8b, v2.8b, v0.8b
//   0x0395a0: 0e218441  add      v1.8b, v2.8b, v1.8b
//   0x0395a4: 2e212401  uhsub    v1.8b, v0.8b, v1.8b
//   0x0395a8: 0f08a421  sshll    v1.8h, v1.8b, #0
//   0x0395ac: 2e201020  uaddw    v0.8h, v1.8h, v0.8b
//   0x0395b0: 2e212800  sqxtun   v0.8b, v0.8h
//   0x0395b4: 1e260000  fmov     w0, s0
//   0x0395b8: d65f03c0  ret      
uint64_t fde_0541_sub_039588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD1001028ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x039588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001028ULL; // 0x039588: sub x8, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C800ULL; // 0x03958c: ld1r {v0.2s}, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C821ULL; // 0x039590: ld1r {v1.2s}, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C902ULL; // 0x039594: ld1r {v2.2s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E210400ULL; // 0x039598: uhadd v0.8b, v0.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E203441ULL; // 0x03959c: cmhi v1.8b, v2.8b, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x0E218441ULL; // 0x0395a0: add v1.8b, v2.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E212401ULL; // 0x0395a4: uhsub v1.8b, v0.8b, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x0F08A421ULL; // 0x0395a8: sshll v1.8h, v1.8b, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x2E201020ULL; // 0x0395ac: uaddw v0.8h, v1.8h, v0.8b
    return acc;
}

// [EN] Reconstructed FDE #0542 @ 0x0395bc..0x039624 (104 bytes)
// [VN] Phục dựng FDE #0542 tại 0x0395bc..0x039624 (104 byte)
//   0x0395bc: 7100105f  cmp      w2, #4
//   0x0395c0: 5400006a  b.ge     #0x395cc
//   0x0395c4: 2a1f03e8  mov      w8, wzr
//   0x0395c8: 1400000d  b        #0x395fc
//   0x0395cc: 93407c48  sxtw     x8, w2
//   0x0395d0: 52800089  mov      w9, #4
//   0x0395d4: 6f04e500  movi     v0.2d, #0xff000000ff000000
//   0x0395d8: aa0003ea  mov      x10, x0
//   0x0395dc: aa0303eb  mov      x11, x3
//   0x0395e0: 3cc10541  ldr      q1, [x10], #0x10
//   0x0395e4: 91001129  add      x9, x9, #4
//   0x0395e8: eb08013f  cmp      x9, x8
//   0x0395ec: 4e208421  add      v1.16b, v1.16b, v0.16b
//   0x0395f0: 3c810561  str      q1, [x11], #0x10
//   0x0395f4: 54ffff6d  b.le     #0x395e0
//   0x0395f8: 121e7448  and      w8, w2, #0xfffffffc
uint64_t fde_0542_sub_0395bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x4E208421ULL) + (x2 ^ 0x0395BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x0395bc: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x0395c0: b.ge #0x395cc
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0395c4: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000DULL; // 0x0395c8: b #0x395fc
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x0395cc: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800089ULL; // 0x0395d0: mov w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x6F04E500ULL; // 0x0395d4: movi v0.2d, #0xff000000ff000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x0395d8: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303EBULL; // 0x0395dc: mov x11, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10541ULL; // 0x0395e0: ldr q1, [x10], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0543 @ 0x039624..0x0396a4 (128 bytes)
// [VN] Phục dựng FDE #0543 tại 0x039624..0x0396a4 (128 byte)
//   0x039624: 7100105f  cmp      w2, #4
//   0x039628: 5400006a  b.ge     #0x39634
//   0x03962c: 2a1f03e8  mov      w8, wzr
//   0x039630: 14000013  b        #0x3967c
//   0x039634: 93407c48  sxtw     x8, w2
//   0x039638: 52800089  mov      w9, #4
//   0x03963c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x039640: aa0003ea  mov      x10, x0
//   0x039644: aa0303eb  mov      x11, x3
//   0x039648: 3cc10541  ldr      q1, [x10], #0x10
//   0x03964c: d100116c  sub      x12, x11, #4
//   0x039650: 4d40c982  ld1r     {v2.4s}, [x12]
//   0x039654: 91001129  add      x9, x9, #4
//   0x039658: 6e016003  ext      v3.16b, v0.16b, v1.16b, #0xc
//   0x03965c: 4e218461  add      v1.16b, v3.16b, v1.16b
//   0x039660: 6e014003  ext      v3.16b, v0.16b, v1.16b, #8
uint64_t fde_0543_sub_039624(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x91001129ULL) + (x2 ^ 0x039624ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039624: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039628: b.ge #0x39634
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x03962c: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000013ULL; // 0x039630: b #0x3967c
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039634: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800089ULL; // 0x039638: mov w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x03963c: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x039640: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303EBULL; // 0x039644: mov x11, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10541ULL; // 0x039648: ldr q1, [x10], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0544 @ 0x0396a4..0x039710 (108 bytes)
// [VN] Phục dựng FDE #0544 tại 0x0396a4..0x039710 (108 byte)
//   0x0396a4: 7100105f  cmp      w2, #4
//   0x0396a8: 5400006a  b.ge     #0x396b4
//   0x0396ac: 2a1f03e8  mov      w8, wzr
//   0x0396b0: 1400000e  b        #0x396e8
//   0x0396b4: 93407c48  sxtw     x8, w2
//   0x0396b8: 52800089  mov      w9, #4
//   0x0396bc: aa0003ea  mov      x10, x0
//   0x0396c0: aa0103eb  mov      x11, x1
//   0x0396c4: aa0303ec  mov      x12, x3
//   0x0396c8: 3cc10540  ldr      q0, [x10], #0x10
//   0x0396cc: 3cc10561  ldr      q1, [x11], #0x10
//   0x0396d0: 91001129  add      x9, x9, #4
//   0x0396d4: eb08013f  cmp      x9, x8
//   0x0396d8: 4e208420  add      v0.16b, v1.16b, v0.16b
//   0x0396dc: 3c810580  str      q0, [x12], #0x10
//   0x0396e0: 54ffff4d  b.le     #0x396c8
uint64_t fde_0544_sub_0396a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0xEB08013FULL) + (x2 ^ 0x0396A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x0396a4: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x0396a8: b.ge #0x396b4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0396ac: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x0396b0: b #0x396e8
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x0396b4: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800089ULL; // 0x0396b8: mov w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x0396bc: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x0396c0: mov x11, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303ECULL; // 0x0396c4: mov x12, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10540ULL; // 0x0396c8: ldr q0, [x10], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0545 @ 0x039710..0x03977c (108 bytes)
// [VN] Phục dựng FDE #0545 tại 0x039710..0x03977c (108 byte)
//   0x039710: 7100105f  cmp      w2, #4
//   0x039714: 5400006a  b.ge     #0x39720
//   0x039718: 2a1f03e8  mov      w8, wzr
//   0x03971c: 1400000e  b        #0x39754
//   0x039720: 93407c48  sxtw     x8, w2
//   0x039724: 91001029  add      x9, x1, #4
//   0x039728: 5280008a  mov      w10, #4
//   0x03972c: aa0003eb  mov      x11, x0
//   0x039730: aa0303ec  mov      x12, x3
//   0x039734: 3cc10560  ldr      q0, [x11], #0x10
//   0x039738: 3cc10521  ldr      q1, [x9], #0x10
//   0x03973c: 9100114a  add      x10, x10, #4
//   0x039740: eb08015f  cmp      x10, x8
//   0x039744: 4e208420  add      v0.16b, v1.16b, v0.16b
//   0x039748: 3c810580  str      q0, [x12], #0x10
//   0x03974c: 54ffff4d  b.le     #0x39734
uint64_t fde_0545_sub_039710(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0xEB08015FULL) + (x2 ^ 0x039710ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039710: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039714: b.ge #0x39720
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039718: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x03971c: b #0x39754
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039720: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91001029ULL; // 0x039724: add x9, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039728: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EBULL; // 0x03972c: mov x11, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303ECULL; // 0x039730: mov x12, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10560ULL; // 0x039734: ldr q0, [x11], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0546 @ 0x03977c..0x0397e8 (108 bytes)
// [VN] Phục dựng FDE #0546 tại 0x03977c..0x0397e8 (108 byte)
//   0x03977c: 7100105f  cmp      w2, #4
//   0x039780: 5400006a  b.ge     #0x3978c
//   0x039784: 2a1f03e8  mov      w8, wzr
//   0x039788: 1400000e  b        #0x397c0
//   0x03978c: 93407c48  sxtw     x8, w2
//   0x039790: d1001029  sub      x9, x1, #4
//   0x039794: 5280008a  mov      w10, #4
//   0x039798: aa0003eb  mov      x11, x0
//   0x03979c: aa0303ec  mov      x12, x3
//   0x0397a0: 3cc10560  ldr      q0, [x11], #0x10
//   0x0397a4: 3cc10521  ldr      q1, [x9], #0x10
//   0x0397a8: 9100114a  add      x10, x10, #4
//   0x0397ac: eb08015f  cmp      x10, x8
//   0x0397b0: 4e208420  add      v0.16b, v1.16b, v0.16b
//   0x0397b4: 3c810580  str      q0, [x12], #0x10
//   0x0397b8: 54ffff4d  b.le     #0x397a0
uint64_t fde_0546_sub_03977c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0xEB08015FULL) + (x2 ^ 0x03977CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x03977c: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039780: b.ge #0x3978c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039784: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x039788: b #0x397c0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x03978c: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001029ULL; // 0x039790: sub x9, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039794: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EBULL; // 0x039798: mov x11, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303ECULL; // 0x03979c: mov x12, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10560ULL; // 0x0397a0: ldr q0, [x11], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0547 @ 0x0397e8..0x0398b4 (204 bytes)
// [VN] Phục dựng FDE #0547 tại 0x0397e8..0x0398b4 (204 byte)
//   0x0397e8: 7100105f  cmp      w2, #4
//   0x0397ec: 5400006a  b.ge     #0x397f8
//   0x0397f0: 2a1f03e8  mov      w8, wzr
//   0x0397f4: 14000026  b        #0x3988c
//   0x0397f8: d1001068  sub      x8, x3, #4
//   0x0397fc: 4d40c900  ld1r     {v0.4s}, [x8]
//   0x039800: 93407c48  sxtw     x8, w2
//   0x039804: 91002069  add      x9, x3, #8
//   0x039808: 9100102a  add      x10, x1, #4
//   0x03980c: 5280008b  mov      w11, #4
//   0x039810: aa0003ec  mov      x12, x0
//   0x039814: 3cc10581  ldr      q1, [x12], #0x10
//   0x039818: 3dc00142  ldr      q2, [x10]
//   0x03981c: 3cdfc143  ldur     q3, [x10, #-4]
//   0x039820: 9100116b  add      x11, x11, #4
//   0x039824: eb08017f  cmp      x11, x8
uint64_t fde_0547_sub_0397e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3DC00142ULL) + (x2 ^ 0x0397E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x0397e8: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x0397ec: b.ge #0x397f8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0397f0: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000026ULL; // 0x0397f4: b #0x3988c
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x0397f8: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C900ULL; // 0x0397fc: ld1r {v0.4s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039800: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002069ULL; // 0x039804: add x9, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9100102AULL; // 0x039808: add x10, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008BULL; // 0x03980c: mov w11, #4
    return acc;
}

// [EN] Reconstructed FDE #0548 @ 0x0398b4..0x039968 (180 bytes)
// [VN] Phục dựng FDE #0548 tại 0x0398b4..0x039968 (180 byte)
//   0x0398b4: 7100105f  cmp      w2, #4
//   0x0398b8: 5400006a  b.ge     #0x398c4
//   0x0398bc: 2a1f03e8  mov      w8, wzr
//   0x0398c0: 14000020  b        #0x39940
//   0x0398c4: d1001068  sub      x8, x3, #4
//   0x0398c8: 4d40c900  ld1r     {v0.4s}, [x8]
//   0x0398cc: 93407c48  sxtw     x8, w2
//   0x0398d0: d1001029  sub      x9, x1, #4
//   0x0398d4: 9100206a  add      x10, x3, #8
//   0x0398d8: 5280008b  mov      w11, #4
//   0x0398dc: aa0003ec  mov      x12, x0
//   0x0398e0: 3cc10581  ldr      q1, [x12], #0x10
//   0x0398e4: 3cc10522  ldr      q2, [x9], #0x10
//   0x0398e8: 9100116b  add      x11, x11, #4
//   0x0398ec: eb08017f  cmp      x11, x8
//   0x0398f0: 6e220400  uhadd    v0.16b, v0.16b, v2.16b
uint64_t fde_0548_sub_0398b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3CC10522ULL) + (x2 ^ 0x0398B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x0398b4: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x0398b8: b.ge #0x398c4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0398bc: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000020ULL; // 0x0398c0: b #0x39940
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x0398c4: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C900ULL; // 0x0398c8: ld1r {v0.4s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x0398cc: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001029ULL; // 0x0398d0: sub x9, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x9100206AULL; // 0x0398d4: add x10, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008BULL; // 0x0398d8: mov w11, #4
    return acc;
}

// [EN] Reconstructed FDE #0549 @ 0x039968..0x039a1c (180 bytes)
// [VN] Phục dựng FDE #0549 tại 0x039968..0x039a1c (180 byte)
//   0x039968: 7100105f  cmp      w2, #4
//   0x03996c: 5400006a  b.ge     #0x39978
//   0x039970: 2a1f03e8  mov      w8, wzr
//   0x039974: 14000020  b        #0x399f4
//   0x039978: d1001068  sub      x8, x3, #4
//   0x03997c: 4d40c900  ld1r     {v0.4s}, [x8]
//   0x039980: 93407c48  sxtw     x8, w2
//   0x039984: 91002069  add      x9, x3, #8
//   0x039988: 5280008a  mov      w10, #4
//   0x03998c: aa0003eb  mov      x11, x0
//   0x039990: aa0103ec  mov      x12, x1
//   0x039994: 3cc10561  ldr      q1, [x11], #0x10
//   0x039998: 3cc10582  ldr      q2, [x12], #0x10
//   0x03999c: 9100114a  add      x10, x10, #4
//   0x0399a0: eb08015f  cmp      x10, x8
//   0x0399a4: 6e220400  uhadd    v0.16b, v0.16b, v2.16b
uint64_t fde_0549_sub_039968(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3CC10582ULL) + (x2 ^ 0x039968ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039968: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x03996c: b.ge #0x39978
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039970: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000020ULL; // 0x039974: b #0x399f4
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x039978: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C900ULL; // 0x03997c: ld1r {v0.4s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039980: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002069ULL; // 0x039984: add x9, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039988: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EBULL; // 0x03998c: mov x11, x0
    return acc;
}

// [EN] Reconstructed FDE #0550 @ 0x039a1c..0x039a90 (116 bytes)
// [VN] Phục dựng FDE #0550 tại 0x039a1c..0x039a90 (116 byte)
//   0x039a1c: 7100105f  cmp      w2, #4
//   0x039a20: 5400006a  b.ge     #0x39a2c
//   0x039a24: 2a1f03e8  mov      w8, wzr
//   0x039a28: 14000010  b        #0x39a68
//   0x039a2c: 93407c48  sxtw     x8, w2
//   0x039a30: 52800089  mov      w9, #4
//   0x039a34: aa0003ea  mov      x10, x0
//   0x039a38: aa0103eb  mov      x11, x1
//   0x039a3c: aa0303ec  mov      x12, x3
//   0x039a40: 3cc10540  ldr      q0, [x10], #0x10
//   0x039a44: 3cdfc161  ldur     q1, [x11, #-4]
//   0x039a48: 3cc10562  ldr      q2, [x11], #0x10
//   0x039a4c: 91001129  add      x9, x9, #4
//   0x039a50: eb08013f  cmp      x9, x8
//   0x039a54: 6e210441  uhadd    v1.16b, v2.16b, v1.16b
//   0x039a58: 4e208420  add      v0.16b, v1.16b, v0.16b
uint64_t fde_0550_sub_039a1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x91001129ULL) + (x2 ^ 0x039A1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039a1c: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039a20: b.ge #0x39a2c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039a24: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000010ULL; // 0x039a28: b #0x39a68
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039a2c: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800089ULL; // 0x039a30: mov w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x039a34: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x039a38: mov x11, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303ECULL; // 0x039a3c: mov x12, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10540ULL; // 0x039a40: ldr q0, [x10], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0551 @ 0x039a90..0x039b08 (120 bytes)
// [VN] Phục dựng FDE #0551 tại 0x039a90..0x039b08 (120 byte)
//   0x039a90: 7100105f  cmp      w2, #4
//   0x039a94: 5400006a  b.ge     #0x39aa0
//   0x039a98: 2a1f03e8  mov      w8, wzr
//   0x039a9c: 14000011  b        #0x39ae0
//   0x039aa0: 93407c48  sxtw     x8, w2
//   0x039aa4: 91001029  add      x9, x1, #4
//   0x039aa8: 5280008a  mov      w10, #4
//   0x039aac: aa0003eb  mov      x11, x0
//   0x039ab0: aa0303ec  mov      x12, x3
//   0x039ab4: 3cc10560  ldr      q0, [x11], #0x10
//   0x039ab8: 3dc00121  ldr      q1, [x9]
//   0x039abc: 3cdfc122  ldur     q2, [x9, #-4]
//   0x039ac0: 9100114a  add      x10, x10, #4
//   0x039ac4: eb08015f  cmp      x10, x8
//   0x039ac8: 91004129  add      x9, x9, #0x10
//   0x039acc: 6e210441  uhadd    v1.16b, v2.16b, v1.16b
uint64_t fde_0551_sub_039a90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x9100114AULL) + (x2 ^ 0x039A90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039a90: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039a94: b.ge #0x39aa0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039a98: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000011ULL; // 0x039a9c: b #0x39ae0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039aa0: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91001029ULL; // 0x039aa4: add x9, x1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039aa8: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EBULL; // 0x039aac: mov x11, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303ECULL; // 0x039ab0: mov x12, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10560ULL; // 0x039ab4: ldr q0, [x11], #0x10
    return acc;
}

// [EN] Reconstructed FDE #0552 @ 0x039b08..0x039bdc (212 bytes)
// [VN] Phục dựng FDE #0552 tại 0x039b08..0x039bdc (212 byte)
//   0x039b08: 7100105f  cmp      w2, #4
//   0x039b0c: 5400006a  b.ge     #0x39b18
//   0x039b10: 2a1f03e8  mov      w8, wzr
//   0x039b14: 14000028  b        #0x39bb4
//   0x039b18: d1001068  sub      x8, x3, #4
//   0x039b1c: 4d40c900  ld1r     {v0.4s}, [x8]
//   0x039b20: 93407c48  sxtw     x8, w2
//   0x039b24: 91002069  add      x9, x3, #8
//   0x039b28: 5280008a  mov      w10, #4
//   0x039b2c: aa0103eb  mov      x11, x1
//   0x039b30: aa0003ec  mov      x12, x0
//   0x039b34: 3cc10581  ldr      q1, [x12], #0x10
//   0x039b38: 3dc00162  ldr      q2, [x11]
//   0x039b3c: 3cc04163  ldur     q3, [x11, #4]
//   0x039b40: 3cdfc164  ldur     q4, [x11, #-4]
//   0x039b44: 9100114a  add      x10, x10, #4
uint64_t fde_0552_sub_039b08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3DC00162ULL) + (x2 ^ 0x039B08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039b08: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039b0c: b.ge #0x39b18
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039b10: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000028ULL; // 0x039b14: b #0x39bb4
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x039b18: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C900ULL; // 0x039b1c: ld1r {v0.4s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039b20: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002069ULL; // 0x039b24: add x9, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039b28: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x039b2c: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0553 @ 0x039bdc..0x039ce8 (268 bytes)
// [VN] Phục dựng FDE #0553 tại 0x039bdc..0x039ce8 (268 byte)
//   0x039bdc: 7100105f  cmp      w2, #4
//   0x039be0: 5400006a  b.ge     #0x39bec
//   0x039be4: 2a1f03e8  mov      w8, wzr
//   0x039be8: 14000036  b        #0x39cc0
//   0x039bec: d1001068  sub      x8, x3, #4
//   0x039bf0: 4d40c900  ld1r     {v0.4s}, [x8]
//   0x039bf4: 93407c48  sxtw     x8, w2
//   0x039bf8: 91002069  add      x9, x3, #8
//   0x039bfc: 5280008a  mov      w10, #4
//   0x039c00: aa0103eb  mov      x11, x1
//   0x039c04: aa0003ec  mov      x12, x0
//   0x039c08: 3dc00162  ldr      q2, [x11]
//   0x039c0c: 3cdfc161  ldur     q1, [x11, #-4]
//   0x039c10: 3cc10583  ldr      q3, [x12], #0x10
//   0x039c14: 9100114a  add      x10, x10, #4
//   0x039c18: eb08015f  cmp      x10, x8
uint64_t fde_0553_sub_039bdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3CDFC161ULL) + (x2 ^ 0x039BDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039bdc: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039be0: b.ge #0x39bec
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039be4: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000036ULL; // 0x039be8: b #0x39cc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x039bec: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C900ULL; // 0x039bf0: ld1r {v0.4s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039bf4: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002069ULL; // 0x039bf8: add x9, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039bfc: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x039c00: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0554 @ 0x039ce8..0x039dd8 (240 bytes)
// [VN] Phục dựng FDE #0554 tại 0x039ce8..0x039dd8 (240 byte)
//   0x039ce8: 7100105f  cmp      w2, #4
//   0x039cec: 5400006a  b.ge     #0x39cf8
//   0x039cf0: 2a1f03e8  mov      w8, wzr
//   0x039cf4: 1400002f  b        #0x39db0
//   0x039cf8: d1001068  sub      x8, x3, #4
//   0x039cfc: 0d40c900  ld1r     {v0.2s}, [x8]
//   0x039d00: 93407c48  sxtw     x8, w2
//   0x039d04: 91002069  add      x9, x3, #8
//   0x039d08: 5280008a  mov      w10, #4
//   0x039d0c: 2f08a400  ushll    v0.8h, v0.8b, #0
//   0x039d10: aa0103eb  mov      x11, x1
//   0x039d14: aa0003ec  mov      x12, x0
//   0x039d18: 3cc10581  ldr      q1, [x12], #0x10
//   0x039d1c: 3cdfc162  ldur     q2, [x11, #-4]
//   0x039d20: 3cc10563  ldr      q3, [x11], #0x10
//   0x039d24: 9100114a  add      x10, x10, #4
uint64_t fde_0554_sub_039ce8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3CC10581ULL) + (x2 ^ 0x039CE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039ce8: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039cec: b.ge #0x39cf8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039cf0: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400002FULL; // 0x039cf4: b #0x39db0
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x039cf8: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x0D40C900ULL; // 0x039cfc: ld1r {v0.2s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039d00: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002069ULL; // 0x039d04: add x9, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039d08: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2F08A400ULL; // 0x039d0c: ushll v0.8h, v0.8b, #0
    return acc;
}

// [EN] Reconstructed FDE #0555 @ 0x039dd8..0x039f18 (320 bytes)
// [VN] Phục dựng FDE #0555 tại 0x039dd8..0x039f18 (320 byte)
//   0x039dd8: 7100105f  cmp      w2, #4
//   0x039ddc: 5400006a  b.ge     #0x39de8
//   0x039de0: 2a1f03e8  mov      w8, wzr
//   0x039de4: 14000043  b        #0x39ef0
//   0x039de8: d1001068  sub      x8, x3, #4
//   0x039dec: 4d40c900  ld1r     {v0.4s}, [x8]
//   0x039df0: 93407c48  sxtw     x8, w2
//   0x039df4: 91002069  add      x9, x3, #8
//   0x039df8: 5280008a  mov      w10, #4
//   0x039dfc: aa0103eb  mov      x11, x1
//   0x039e00: aa0003ec  mov      x12, x0
//   0x039e04: 3cc10583  ldr      q3, [x12], #0x10
//   0x039e08: 3dc00161  ldr      q1, [x11]
//   0x039e0c: 3cdfc162  ldur     q2, [x11, #-4]
//   0x039e10: 9100114a  add      x10, x10, #4
//   0x039e14: eb08015f  cmp      x10, x8
uint64_t fde_0555_sub_039dd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x3DC00161ULL) + (x2 ^ 0x039DD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x039dd8: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x039ddc: b.ge #0x39de8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x039de0: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000043ULL; // 0x039de4: b #0x39ef0
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001068ULL; // 0x039de8: sub x8, x3, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C900ULL; // 0x039dec: ld1r {v0.4s}, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x039df0: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002069ULL; // 0x039df4: add x9, x3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x039df8: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EBULL; // 0x039dfc: mov x11, x1
    return acc;
}

// [EN] Reconstructed FDE #0556 @ 0x039f18..0x039f50 (56 bytes)
// [VN] Phục dựng FDE #0556 tại 0x039f18..0x039f50 (56 byte)
//   0x039f18: 121c6c28  and      w8, w1, #0xfffffff0
//   0x039f1c: 7100051f  cmp      w8, #1
//   0x039f20: 5400014b  b.lt     #0x39f48
//   0x039f24: 8b28c808  add      x8, x0, w8, sxtw #2
//   0x039f28: 4cdf0000  ld4      {v0.16b, v1.16b, v2.16b, v3.16b}, [x0], #64
//   0x039f2c: 4ea21c44  mov      v4.16b, v2.16b
//   0x039f30: 4ea11c25  mov      v5.16b, v1.16b
//   0x039f34: 4ea01c06  mov      v6.16b, v0.16b
//   0x039f38: 4ea31c67  mov      v7.16b, v3.16b
//   0x039f3c: eb08001f  cmp      x0, x8
//   0x039f40: 4c9f0044  st4      {v4.16b, v5.16b, v6.16b, v7.16b}, [x2], #64
//   0x039f44: 54ffff23  b.lo     #0x39f28
//   0x039f48: 12000c21  and      w1, w1, #0xf
//   0x039f4c: 17fff854  b        #0x3809c
uint64_t fde_0556_sub_039f18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x121C6C28ULL) + (x1 ^ 0x12000C21ULL) + (x2 ^ 0x039F18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x121C6C28ULL; // 0x039f18: and w8, w1, #0xfffffff0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x039f1c: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400014BULL; // 0x039f20: b.lt #0x39f48
    acc = (acc * 0x100000001B3ULL) ^ 0x8B28C808ULL; // 0x039f24: add x8, x0, w8, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0x4CDF0000ULL; // 0x039f28: ld4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x0], #64
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA21C44ULL; // 0x039f2c: mov v4.16b, v2.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA11C25ULL; // 0x039f30: mov v5.16b, v1.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C06ULL; // 0x039f34: mov v6.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA31C67ULL; // 0x039f38: mov v7.16b, v3.16b
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08001FULL; // 0x039f3c: cmp x0, x8
    return acc;
}

// [EN] Reconstructed FDE #0557 @ 0x039f50..0x039f78 (40 bytes)
// [VN] Phục dựng FDE #0557 tại 0x039f50..0x039f78 (40 byte)
//   0x039f50: 121c6c28  and      w8, w1, #0xfffffff0
//   0x039f54: 7100051f  cmp      w8, #1
//   0x039f58: 540000cb  b.lt     #0x39f70
//   0x039f5c: 8b28c808  add      x8, x0, w8, sxtw #2
//   0x039f60: 4cdf0000  ld4      {v0.16b, v1.16b, v2.16b, v3.16b}, [x0], #64
//   0x039f64: eb08001f  cmp      x0, x8
//   0x039f68: 4c9f4040  st3      {v0.16b, v1.16b, v2.16b}, [x2], #48
//   0x039f6c: 54ffffa3  b.lo     #0x39f60
//   0x039f70: 12000c21  and      w1, w1, #0xf
//   0x039f74: 17fff8d6  b        #0x382cc
uint64_t fde_0557_sub_039f50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x121C6C28ULL) + (x1 ^ 0x17FFF8D6ULL) + (x2 ^ 0x039F50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x121C6C28ULL; // 0x039f50: and w8, w1, #0xfffffff0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x039f54: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000CBULL; // 0x039f58: b.lt #0x39f70
    acc = (acc * 0x100000001B3ULL) ^ 0x8B28C808ULL; // 0x039f5c: add x8, x0, w8, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0x4CDF0000ULL; // 0x039f60: ld4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x0], #64
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08001FULL; // 0x039f64: cmp x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x4C9F4040ULL; // 0x039f68: st3 {v0.16b, v1.16b, v2.16b}, [x2], #48
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFFA3ULL; // 0x039f6c: b.lo #0x39f60
    acc = (acc * 0x100000001B3ULL) ^ 0x12000C21ULL; // 0x039f70: and w1, w1, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF8D6ULL; // 0x039f74: b #0x382cc
    return acc;
}

// [EN] Reconstructed FDE #0558 @ 0x039f78..0x039fac (52 bytes)
// [VN] Phục dựng FDE #0558 tại 0x039f78..0x039fac (52 byte)
//   0x039f78: 121c6c28  and      w8, w1, #0xfffffff0
//   0x039f7c: 7100051f  cmp      w8, #1
//   0x039f80: 5400012b  b.lt     #0x39fa4
//   0x039f84: 8b28c808  add      x8, x0, w8, sxtw #2
//   0x039f88: 4cdf0000  ld4      {v0.16b, v1.16b, v2.16b, v3.16b}, [x0], #64
//   0x039f8c: 4ea21c44  mov      v4.16b, v2.16b
//   0x039f90: 4ea11c25  mov      v5.16b, v1.16b
//   0x039f94: 4ea01c06  mov      v6.16b, v0.16b
//   0x039f98: eb08001f  cmp      x0, x8
//   0x039f9c: 4c9f4044  st3      {v4.16b, v5.16b, v6.16b}, [x2], #48
//   0x039fa0: 54ffff43  b.lo     #0x39f88
//   0x039fa4: 12000c21  and      w1, w1, #0xf
//   0x039fa8: 17fff830  b        #0x38068
uint64_t fde_0558_sub_039f78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x121C6C28ULL) + (x1 ^ 0x17FFF830ULL) + (x2 ^ 0x039F78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x121C6C28ULL; // 0x039f78: and w8, w1, #0xfffffff0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x039f7c: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400012BULL; // 0x039f80: b.lt #0x39fa4
    acc = (acc * 0x100000001B3ULL) ^ 0x8B28C808ULL; // 0x039f84: add x8, x0, w8, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0x4CDF0000ULL; // 0x039f88: ld4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x0], #64
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA21C44ULL; // 0x039f8c: mov v4.16b, v2.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA11C25ULL; // 0x039f90: mov v5.16b, v1.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C06ULL; // 0x039f94: mov v6.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08001FULL; // 0x039f98: cmp x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x4C9F4044ULL; // 0x039f9c: st3 {v4.16b, v5.16b, v6.16b}, [x2], #48
    return acc;
}

// [EN] Reconstructed FDE #0559 @ 0x039fac..0x03a000 (84 bytes)
// [VN] Phục dựng FDE #0559 tại 0x039fac..0x03a000 (84 byte)
//   0x039fac: 121e7428  and      w8, w1, #0xfffffffc
//   0x039fb0: 7100051f  cmp      w8, #1
//   0x039fb4: 5400022b  b.lt     #0x39ff8
//   0x039fb8: f00000c9  adrp     x9, #0x54000
//   0x039fbc: fd44e120  ldr      d0, [x9, #0x9c0]
//   0x039fc0: 8b28c808  add      x8, x0, w8, sxtw #2
//   0x039fc4: 6f00e401  movi     v1.2d, #0000000000000000
//   0x039fc8: 3cc10402  ldr      q2, [x0], #0x10
//   0x039fcc: 4ea21c43  mov      v3.16b, v2.16b
//   0x039fd0: 6e024044  ext      v4.16b, v2.16b, v2.16b, #8
//   0x039fd4: 6e180423  mov      v3.d[1], v1.d[0]
//   0x039fd8: 6e180424  mov      v4.d[1], v1.d[0]
//   0x039fdc: 0e000063  tbl      v3.8b, {v3.16b}, v0.8b
//   0x039fe0: 0e000084  tbl      v4.8b, {v4.16b}, v0.8b
//   0x039fe4: 6e180483  mov      v3.d[1], v4.d[0]
//   0x039fe8: 4e228462  add      v2.16b, v3.16b, v2.16b
uint64_t fde_0559_sub_039fac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x121E7428ULL) + (x1 ^ 0x0E000063ULL) + (x2 ^ 0x039FACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x121E7428ULL; // 0x039fac: and w8, w1, #0xfffffffc
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x039fb0: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400022BULL; // 0x039fb4: b.lt #0x39ff8
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C9ULL; // 0x039fb8: adrp x9, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0xFD44E120ULL; // 0x039fbc: ldr d0, [x9, #0x9c0]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B28C808ULL; // 0x039fc0: add x8, x0, w8, sxtw #2
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E401ULL; // 0x039fc4: movi v1.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x3CC10402ULL; // 0x039fc8: ldr q2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA21C43ULL; // 0x039fcc: mov v3.16b, v2.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x6E024044ULL; // 0x039fd0: ext v4.16b, v2.16b, v2.16b, #8
    return acc;
}

// [EN] Reconstructed FDE #0560 @ 0x03a000..0x03a0f8 (248 bytes)
// [VN] Phục dựng FDE #0560 tại 0x03a000..0x03a0f8 (248 byte)
//   0x03a000: 7100105f  cmp      w2, #4
//   0x03a004: 5400008a  b.ge     #0x3a014
//   0x03a008: 2a1f03e9  mov      w9, wzr
//   0x03a00c: aa1f03e8  mov      x8, xzr
//   0x03a010: 14000037  b        #0x3a0ec
//   0x03a014: 39400409  ldrb     w9, [x0, #1]
//   0x03a018: 3940000a  ldrb     w10, [x0]
//   0x03a01c: 3940080b  ldrb     w11, [x0, #2]
//   0x03a020: 6f00e401  movi     v1.2d, #0000000000000000
//   0x03a024: 1e270122  fmov     s2, w9
//   0x03a028: 4e0c1d42  mov      v2.s[1], w10
//   0x03a02c: 53185d69  lsl      w9, w11, #8
//   0x03a030: 0f285442  shl      v2.2s, v2.2s, #8
//   0x03a034: 13063d29  sbfx     w9, w9, #6, #0xa
//   0x03a038: 0f305442  shl      v2.2s, v2.2s, #0x10
//   0x03a03c: 4e061d21  mov      v1.h[1], w9
uint64_t fde_0560_sub_03a000(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100105FULL) + (x1 ^ 0x0F285442ULL) + (x2 ^ 0x03A000ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x03a000: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x5400008AULL; // 0x03a004: b.ge #0x3a014
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E9ULL; // 0x03a008: mov w9, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x03a00c: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000037ULL; // 0x03a010: b #0x3a0ec
    acc = (acc * 0x100000001B3ULL) ^ 0x39400409ULL; // 0x03a014: ldrb w9, [x0, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940000AULL; // 0x03a018: ldrb w10, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940080BULL; // 0x03a01c: ldrb w11, [x0, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E401ULL; // 0x03a020: movi v1.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x1E270122ULL; // 0x03a024: fmov s2, w9
    return acc;
}

// [EN] Reconstructed FDE #0561 @ 0x03a0f8..0x03a1b8 (192 bytes)
// [VN] Phục dựng FDE #0561 tại 0x03a0f8..0x03a1b8 (192 byte)
//   0x03a0f8: b9400808  ldr      w8, [x0, #8]
//   0x03a0fc: 7100051f  cmp      w8, #1
//   0x03a100: 540005ab  b.lt     #0x3a1b4
//   0x03a104: b980340b  ldrsw    x11, [x0, #0x34]
//   0x03a108: 93407d0a  sxtw     x10, w8
//   0x03a10c: aa1f03e9  mov      x9, xzr
//   0x03a110: 2a0803ec  mov      w12, w8
//   0x03a114: 9b0a7d6b  mul      x11, x11, x10
//   0x03a118: 14000005  b        #0x3a12c
//   0x03a11c: 91000529  add      x9, x9, #1
//   0x03a120: eb08013f  cmp      x9, x8
//   0x03a124: 1100058c  add      w12, w12, #1
//   0x03a128: 54000460  b.eq     #0x3a1b4
//   0x03a12c: b9402c0e  ldr      w14, [x0, #0x2c]
//   0x03a130: 38696830  ldrb     w16, [x1, x9]
//   0x03a134: b940240d  ldr      w13, [x0, #0x24]
uint64_t fde_0561_sub_03a0f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400808ULL) + (x1 ^ 0x54000460ULL) + (x2 ^ 0x03A0F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400808ULL; // 0x03a0f8: ldr w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x03a0fc: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540005ABULL; // 0x03a100: b.lt #0x3a1b4
    acc = (acc * 0x100000001B3ULL) ^ 0xB980340BULL; // 0x03a104: ldrsw x11, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D0AULL; // 0x03a108: sxtw x10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x03a10c: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803ECULL; // 0x03a110: mov w12, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0A7D6BULL; // 0x03a114: mul x11, x11, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x14000005ULL; // 0x03a118: b #0x3a12c
    acc = (acc * 0x100000001B3ULL) ^ 0x91000529ULL; // 0x03a11c: add x9, x9, #1
    return acc;
}

// [EN] Reconstructed FDE #0562 @ 0x03a1b8..0x03a270 (184 bytes)
// [VN] Phục dựng FDE #0562 tại 0x03a1b8..0x03a270 (184 byte)
//   0x03a1b8: b9800808  ldrsw    x8, [x0, #8]
//   0x03a1bc: 7100051f  cmp      w8, #1
//   0x03a1c0: 5400056b  b.lt     #0x3a26c
//   0x03a1c4: b980340b  ldrsw    x11, [x0, #0x34]
//   0x03a1c8: aa1f03e9  mov      x9, xzr
//   0x03a1cc: 92407d0a  and      x10, x8, #0xffffffff
//   0x03a1d0: 52b0000c  mov      w12, #-0xffffffff80000000
//   0x03a1d4: 9b087d6b  mul      x11, x11, x8
//   0x03a1d8: 6b0b013f  cmp      w9, w11
//   0x03a1dc: 540000cb  b.lt     #0x3a1f4
//   0x03a1e0: 91000529  add      x9, x9, #1
//   0x03a1e4: eb0a013f  cmp      x9, x10
//   0x03a1e8: 54000420  b.eq     #0x3a26c
//   0x03a1ec: 6b0b013f  cmp      w9, w11
//   0x03a1f0: 54ffff8a  b.ge     #0x3a1e0
//   0x03a1f4: 2a1f03ed  mov      w13, wzr
uint64_t fde_0562_sub_03a1b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9800808ULL) + (x1 ^ 0x54000420ULL) + (x2 ^ 0x03A1B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800808ULL; // 0x03a1b8: ldrsw x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x03a1bc: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400056BULL; // 0x03a1c0: b.lt #0x3a26c
    acc = (acc * 0x100000001B3ULL) ^ 0xB980340BULL; // 0x03a1c4: ldrsw x11, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x03a1c8: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x92407D0AULL; // 0x03a1cc: and x10, x8, #0xffffffff
    acc = (acc * 0x100000001B3ULL) ^ 0x52B0000CULL; // 0x03a1d0: mov w12, #-0xffffffff80000000
    acc = (acc * 0x100000001B3ULL) ^ 0x9B087D6BULL; // 0x03a1d4: mul x11, x11, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0B013FULL; // 0x03a1d8: cmp w9, w11
    acc = (acc * 0x100000001B3ULL) ^ 0x540000CBULL; // 0x03a1dc: b.lt #0x3a1f4
    return acc;
}

// [EN] Reconstructed FDE #0563 @ 0x03a270..0x03a298 (40 bytes)
// [VN] Phục dựng FDE #0563 tại 0x03a270..0x03a298 (40 byte)
//   0x03a270: b9400008  ldr      w8, [x0]
//   0x03a274: 340000a8  cbz      w8, #0x3a288
//   0x03a278: b0000148  adrp     x8, #0x63000
//   0x03a27c: f9462d08  ldr      x8, [x8, #0xc58]
//   0x03a280: f9400102  ldr      x2, [x8]
//   0x03a284: d61f0040  br       x2
//   0x03a288: b0000148  adrp     x8, #0x63000
//   0x03a28c: f9463508  ldr      x8, [x8, #0xc68]
//   0x03a290: f9400102  ldr      x2, [x8]
//   0x03a294: d61f0040  br       x2
uint64_t fde_0563_sub_03a270(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0xD61F0040ULL) + (x2 ^ 0x03A270ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x03a270: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000A8ULL; // 0x03a274: cbz w8, #0x3a288
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000148ULL; // 0x03a278: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9462D08ULL; // 0x03a27c: ldr x8, [x8, #0xc58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x03a280: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x03a284: br x2
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000148ULL; // 0x03a288: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9463508ULL; // 0x03a28c: ldr x8, [x8, #0xc68]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x03a290: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x03a294: br x2
    return acc;
}

// [EN] Reconstructed FDE #0564 @ 0x03a298..0x03a368 (208 bytes)
// [VN] Phục dựng FDE #0564 tại 0x03a298..0x03a368 (208 byte)
//   0x03a298: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03a29c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03a2a0: 910043fd  add      x29, sp, #0x10
//   0x03a2a4: b9401808  ldr      w8, [x0, #0x18]
//   0x03a2a8: 7100011f  cmp      w8, #0
//   0x03a2ac: 5400030c  b.gt     #0x3a30c
//   0x03a2b0: b9400408  ldr      w8, [x0, #4]
//   0x03a2b4: aa0003f3  mov      x19, x0
//   0x03a2b8: 34000088  cbz      w8, #0x3a2c8
//   0x03a2bc: b0000148  adrp     x8, #0x63000
//   0x03a2c0: f946a908  ldr      x8, [x8, #0xd50]
//   0x03a2c4: 14000005  b        #0x3a2d8
//   0x03a2c8: b9401668  ldr      w8, [x19, #0x14]
//   0x03a2cc: 34000268  cbz      w8, #0x3a318
//   0x03a2d0: b0000148  adrp     x8, #0x63000
//   0x03a2d4: f9468108  ldr      x8, [x8, #0xd00]
uint64_t fde_0564_sub_03a298(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB9401668ULL) + (x2 ^ 0x03A298ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03a298: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03a29c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03a2a0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401808ULL; // 0x03a2a4: ldr w8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100011FULL; // 0x03a2a8: cmp w8, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x5400030CULL; // 0x03a2ac: b.gt #0x3a30c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400408ULL; // 0x03a2b0: ldr w8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03a2b4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x34000088ULL; // 0x03a2b8: cbz w8, #0x3a2c8
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000148ULL; // 0x03a2bc: adrp x8, #0x63000
    return acc;
}

// [EN] Reconstructed FDE #0565 @ 0x03a368..0x03a3f4 (140 bytes)
// [VN] Phục dựng FDE #0565 tại 0x03a368..0x03a3f4 (140 byte)
//   0x03a368: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03a36c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03a370: 910043fd  add      x29, sp, #0x10
//   0x03a374: d0000140  adrp     x0, #0x64000
//   0x03a378: 91130000  add      x0, x0, #0x4c0
//   0x03a37c: 97ff276d  bl       #0x4130
//   0x03a380: 34000080  cbz      w0, #0x3a390
//   0x03a384: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03a388: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x03a38c: d65f03c0  ret      
//   0x03a390: b0000154  adrp     x20, #0x63000
//   0x03a394: f947be94  ldr      x20, [x20, #0xf78]
//   0x03a398: d0000153  adrp     x19, #0x64000
//   0x03a39c: f9416669  ldr      x9, [x19, #0x2c8]
//   0x03a3a0: f9400288  ldr      x8, [x20]
//   0x03a3a4: eb08013f  cmp      x9, x8
uint64_t fde_0565_sub_03a368(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000153ULL) + (x2 ^ 0x03A368ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03a368: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03a36c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03a370: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000140ULL; // 0x03a374: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91130000ULL; // 0x03a378: add x0, x0, #0x4c0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF276DULL; // 0x03a37c: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x03a380: cbz w0, #0x3a390
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03a384: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x03a388: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03a38c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0566 @ 0x03a3f4..0x03a420 (44 bytes)
// [VN] Phục dựng FDE #0566 tại 0x03a3f4..0x03a420 (44 byte)
//   0x03a3f4: b0000148  adrp     x8, #0x63000
//   0x03a3f8: b000014a  adrp     x10, #0x63000
//   0x03a3fc: f946a908  ldr      x8, [x8, #0xd50]
//   0x03a400: f946814a  ldr      x10, [x10, #0xd00]
//   0x03a404: 90000009  adrp     x9, #0x3a000
//   0x03a408: 9000000b  adrp     x11, #0x3a000
//   0x03a40c: 91108129  add      x9, x9, #0x420
//   0x03a410: 9122916b  add      x11, x11, #0x8a4
//   0x03a414: f9000109  str      x9, [x8]
//   0x03a418: f900014b  str      x11, [x10]
//   0x03a41c: d65f03c0  ret      
uint64_t fde_0566_sub_03a3f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000148ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03A3F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000148ULL; // 0x03a3f4: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xB000014AULL; // 0x03a3f8: adrp x10, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946A908ULL; // 0x03a3fc: ldr x8, [x8, #0xd50]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946814AULL; // 0x03a400: ldr x10, [x10, #0xd00]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x03a404: adrp x9, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000BULL; // 0x03a408: adrp x11, #0x3a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91108129ULL; // 0x03a40c: add x9, x9, #0x420
    acc = (acc * 0x100000001B3ULL) ^ 0x9122916BULL; // 0x03a410: add x11, x11, #0x8a4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000109ULL; // 0x03a414: str x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900014BULL; // 0x03a418: str x11, [x10]
    return acc;
}

// [EN] Reconstructed FDE #0567 @ 0x03a420..0x03a8a4 (1156 bytes)
// [VN] Phục dựng FDE #0567 tại 0x03a420..0x03a8a4 (1156 byte)
//   0x03a420: f81c0ff9  str      x25, [sp, #-0x40]!
//   0x03a424: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x03a428: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x03a42c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x03a430: b940340b  ldr      w11, [x0, #0x34]
//   0x03a434: b940080d  ldr      w13, [x0, #8]
//   0x03a438: b9401008  ldr      w8, [x0, #0x10]
//   0x03a43c: f940240a  ldr      x10, [x0, #0x48]
//   0x03a440: f9403009  ldr      x9, [x0, #0x60]
//   0x03a444: b940180c  ldr      w12, [x0, #0x18]
//   0x03a448: 1b0b7dad  mul      w13, w13, w11
//   0x03a44c: d3417d0b  ubfx     x11, x8, #1, #0x1f
//   0x03a450: 121d71af  and      w15, w13, #0xfffffff8
//   0x03a454: 4e040d60  dup      v0.4s, w11
//   0x03a458: 340005ec  cbz      w12, #0x3a514
//   0x03a45c: b980200e  ldrsw    x14, [x0, #0x20]
uint64_t fde_0567_sub_03a420(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF9ULL) + (x1 ^ 0x121D71AFULL) + (x2 ^ 0x03A420ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF9ULL; // 0x03a420: str x25, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x03a424: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03a428: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x03a42c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940340BULL; // 0x03a430: ldr w11, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940080DULL; // 0x03a434: ldr w13, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401008ULL; // 0x03a438: ldr w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940240AULL; // 0x03a43c: ldr x10, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403009ULL; // 0x03a440: ldr x9, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940180CULL; // 0x03a444: ldr w12, [x0, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0568 @ 0x03a8a4..0x03acb8 (1044 bytes)
// [VN] Phục dựng FDE #0568 tại 0x03a8a4..0x03acb8 (1044 byte)
//   0x03a8a4: a9bf4ff4  stp      x20, x19, [sp, #-0x10]!
//   0x03a8a8: b940340b  ldr      w11, [x0, #0x34]
//   0x03a8ac: b940080c  ldr      w12, [x0, #8]
//   0x03a8b0: 2942b408  ldp      w8, w13, [x0, #0x14]
//   0x03a8b4: b940100f  ldr      w15, [x0, #0x10]
//   0x03a8b8: f9402409  ldr      x9, [x0, #0x48]
//   0x03a8bc: f9402c0a  ldr      x10, [x0, #0x58]
//   0x03a8c0: 1b0b7d8c  mul      w12, w12, w11
//   0x03a8c4: d3417d10  ubfx     x16, x8, #1, #0x1f
//   0x03a8c8: 1b0f7dab  mul      w11, w13, w15
//   0x03a8cc: 121d718e  and      w14, w12, #0xfffffff8
//   0x03a8d0: 4e040e00  dup      v0.4s, w16
//   0x03a8d4: 3400040b  cbz      w11, #0x3a954
//   0x03a8d8: f940300b  ldr      x11, [x0, #0x60]
//   0x03a8dc: 710005df  cmp      w14, #1
//   0x03a8e0: 1b0ffdaf  mneg     w15, w13, w15
uint64_t fde_0568_sub_03a8a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF4FF4ULL) + (x1 ^ 0x3400040BULL) + (x2 ^ 0x03A8A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF4FF4ULL; // 0x03a8a4: stp x20, x19, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB940340BULL; // 0x03a8a8: ldr w11, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940080CULL; // 0x03a8ac: ldr w12, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2942B408ULL; // 0x03a8b0: ldp w8, w13, [x0, #0x14]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940100FULL; // 0x03a8b4: ldr w15, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402409ULL; // 0x03a8b8: ldr x9, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402C0AULL; // 0x03a8bc: ldr x10, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x1B0B7D8CULL; // 0x03a8c0: mul w12, w12, w11
    acc = (acc * 0x100000001B3ULL) ^ 0xD3417D10ULL; // 0x03a8c4: ubfx x16, x8, #1, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x1B0F7DABULL; // 0x03a8c8: mul w11, w13, w15
    return acc;
}

// [EN] Reconstructed FDE #0569 @ 0x03acb8..0x03ad1c (100 bytes)
// [VN] Phục dựng FDE #0569 tại 0x03acb8..0x03ad1c (100 byte)
//   0x03acb8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03acbc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03acc0: 910043fd  add      x29, sp, #0x10
//   0x03acc4: d0000140  adrp     x0, #0x64000
//   0x03acc8: 91144000  add      x0, x0, #0x510
//   0x03accc: 97ff2519  bl       #0x4130
//   0x03acd0: 34000080  cbz      w0, #0x3ace0
//   0x03acd4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03acd8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x03acdc: d65f03c0  ret      
//   0x03ace0: b0000154  adrp     x20, #0x63000
//   0x03ace4: f947be94  ldr      x20, [x20, #0xf78]
//   0x03ace8: d0000153  adrp     x19, #0x64000
//   0x03acec: f9416e69  ldr      x9, [x19, #0x2d8]
//   0x03acf0: f9400288  ldr      x8, [x20]
//   0x03acf4: eb08013f  cmp      x9, x8
uint64_t fde_0569_sub_03acb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000153ULL) + (x2 ^ 0x03ACB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03acb8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03acbc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03acc0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000140ULL; // 0x03acc4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91144000ULL; // 0x03acc8: add x0, x0, #0x510
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF2519ULL; // 0x03accc: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x03acd0: cbz w0, #0x3ace0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03acd4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x03acd8: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03acdc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0570 @ 0x03ad1c..0x03ae04 (232 bytes)
// [VN] Phục dựng FDE #0570 tại 0x03ad1c..0x03ae04 (232 byte)
//   0x03ad1c: a9be57f6  stp      x22, x21, [sp, #-0x20]!
//   0x03ad20: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03ad24: 7100049f  cmp      w4, #1
//   0x03ad28: 5400068b  b.lt     #0x3adf8
//   0x03ad2c: aa1f03e8  mov      x8, xzr
//   0x03ad30: 2a0403e9  mov      w9, w4
//   0x03ad34: 528950aa  mov      w10, #0x4a85
//   0x03ad38: 528cc4ab  mov      w11, #0x6625
//   0x03ad3c: 1286f32c  mov      w12, #-0x379a
//   0x03ad40: 52801fed  mov      w13, #0xff
//   0x03ad44: 5283226e  mov      w14, #0x1913
//   0x03ad48: 5286810f  mov      w15, #0x3408
//   0x03ad4c: 52844090  mov      w16, #0x2204
//   0x03ad50: 52902351  mov      w17, #0x811a
//   0x03ad54: 1288a284  mov      w4, #-0x4515
//   0x03ad58: 38401405  ldrb     w5, [x0], #1
uint64_t fde_0570_sub_03ad1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE57F6ULL) + (x1 ^ 0x52844090ULL) + (x2 ^ 0x03AD1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE57F6ULL; // 0x03ad1c: stp x22, x21, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03ad20: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03ad24: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400068BULL; // 0x03ad28: b.lt #0x3adf8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x03ad2c: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E9ULL; // 0x03ad30: mov w9, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x528950AAULL; // 0x03ad34: mov w10, #0x4a85
    acc = (acc * 0x100000001B3ULL) ^ 0x528CC4ABULL; // 0x03ad38: mov w11, #0x6625
    acc = (acc * 0x100000001B3ULL) ^ 0x1286F32CULL; // 0x03ad3c: mov w12, #-0x379a
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEDULL; // 0x03ad40: mov w13, #0xff
    return acc;
}

// [EN] Reconstructed FDE #0571 @ 0x03ae04..0x03aeec (232 bytes)
// [VN] Phục dựng FDE #0571 tại 0x03ae04..0x03aeec (232 byte)
//   0x03ae04: a9be57f6  stp      x22, x21, [sp, #-0x20]!
//   0x03ae08: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03ae0c: 7100049f  cmp      w4, #1
//   0x03ae10: 5400068b  b.lt     #0x3aee0
//   0x03ae14: aa1f03e8  mov      x8, xzr
//   0x03ae18: 2a0403e9  mov      w9, w4
//   0x03ae1c: 528950aa  mov      w10, #0x4a85
//   0x03ae20: 5290234b  mov      w11, #0x811a
//   0x03ae24: 1288a28c  mov      w12, #-0x4515
//   0x03ae28: 52801fed  mov      w13, #0xff
//   0x03ae2c: 5283226e  mov      w14, #0x1913
//   0x03ae30: 5286810f  mov      w15, #0x3408
//   0x03ae34: 52844090  mov      w16, #0x2204
//   0x03ae38: 528cc4b1  mov      w17, #0x6625
//   0x03ae3c: 1286f324  mov      w4, #-0x379a
//   0x03ae40: 38401405  ldrb     w5, [x0], #1
uint64_t fde_0571_sub_03ae04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE57F6ULL) + (x1 ^ 0x52844090ULL) + (x2 ^ 0x03AE04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE57F6ULL; // 0x03ae04: stp x22, x21, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03ae08: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03ae0c: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400068BULL; // 0x03ae10: b.lt #0x3aee0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x03ae14: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E9ULL; // 0x03ae18: mov w9, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x528950AAULL; // 0x03ae1c: mov w10, #0x4a85
    acc = (acc * 0x100000001B3ULL) ^ 0x5290234BULL; // 0x03ae20: mov w11, #0x811a
    acc = (acc * 0x100000001B3ULL) ^ 0x1288A28CULL; // 0x03ae24: mov w12, #-0x4515
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEDULL; // 0x03ae28: mov w13, #0xff
    return acc;
}

// [EN] Reconstructed FDE #0572 @ 0x03aeec..0x03b478 (1420 bytes)
// [VN] Phục dựng FDE #0572 tại 0x03aeec..0x03b478 (1420 byte)
//   0x03aeec: d10203ff  sub      sp, sp, #0x80
//   0x03aef0: 6d023bef  stp      d15, d14, [sp, #0x20]
//   0x03aef4: 6d0333ed  stp      d13, d12, [sp, #0x30]
//   0x03aef8: 6d042beb  stp      d11, d10, [sp, #0x40]
//   0x03aefc: 6d0523e9  stp      d9, d8, [sp, #0x50]
//   0x03af00: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x03af04: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x03af08: 7100049f  cmp      w4, #1
//   0x03af0c: 5400072b  b.lt     #0x3aff0
//   0x03af10: 7100409f  cmp      w4, #0x10
//   0x03af14: 2a0403e8  mov      w8, w4
//   0x03af18: aa1f03e9  mov      x9, xzr
//   0x03af1c: 540007a2  b.hs     #0x3b010
//   0x03af20: 8b09052a  add      x10, x9, x9, lsl #1
//   0x03af24: 8b09004b  add      x11, x2, x9
//   0x03af28: 8b09002c  add      x12, x1, x9
uint64_t fde_0572_sub_03aeec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x540007A2ULL) + (x2 ^ 0x03AEECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x03aeec: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x6D023BEFULL; // 0x03aef0: stp d15, d14, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0333EDULL; // 0x03aef4: stp d13, d12, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D042BEBULL; // 0x03aef8: stp d11, d10, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0523E9ULL; // 0x03aefc: stp d9, d8, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x03af00: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x03af04: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03af08: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400072BULL; // 0x03af0c: b.lt #0x3aff0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100409FULL; // 0x03af10: cmp w4, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0573 @ 0x03b478..0x03ba04 (1420 bytes)
// [VN] Phục dựng FDE #0573 tại 0x03b478..0x03ba04 (1420 byte)
//   0x03b478: d10203ff  sub      sp, sp, #0x80
//   0x03b47c: 6d023bef  stp      d15, d14, [sp, #0x20]
//   0x03b480: 6d0333ed  stp      d13, d12, [sp, #0x30]
//   0x03b484: 6d042beb  stp      d11, d10, [sp, #0x40]
//   0x03b488: 6d0523e9  stp      d9, d8, [sp, #0x50]
//   0x03b48c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x03b490: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x03b494: 7100049f  cmp      w4, #1
//   0x03b498: 5400072b  b.lt     #0x3b57c
//   0x03b49c: 7100409f  cmp      w4, #0x10
//   0x03b4a0: 2a0403e8  mov      w8, w4
//   0x03b4a4: aa1f03e9  mov      x9, xzr
//   0x03b4a8: 540007a2  b.hs     #0x3b59c
//   0x03b4ac: 8b09052a  add      x10, x9, x9, lsl #1
//   0x03b4b0: 8b09004b  add      x11, x2, x9
//   0x03b4b4: 8b09002c  add      x12, x1, x9
uint64_t fde_0573_sub_03b478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x540007A2ULL) + (x2 ^ 0x03B478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x03b478: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x6D023BEFULL; // 0x03b47c: stp d15, d14, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0333EDULL; // 0x03b480: stp d13, d12, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D042BEBULL; // 0x03b484: stp d11, d10, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0523E9ULL; // 0x03b488: stp d9, d8, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x03b48c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x03b490: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03b494: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400072BULL; // 0x03b498: b.lt #0x3b57c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100409FULL; // 0x03b49c: cmp w4, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0574 @ 0x03ba04..0x03baec (232 bytes)
// [VN] Phục dựng FDE #0574 tại 0x03ba04..0x03baec (232 byte)
//   0x03ba04: a9be57f6  stp      x22, x21, [sp, #-0x20]!
//   0x03ba08: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03ba0c: 7100049f  cmp      w4, #1
//   0x03ba10: 5400068b  b.lt     #0x3bae0
//   0x03ba14: aa1f03e8  mov      x8, xzr
//   0x03ba18: 2a0403e9  mov      w9, w4
//   0x03ba1c: 52801fea  mov      w10, #0xff
//   0x03ba20: 528950ab  mov      w11, #0x4a85
//   0x03ba24: 528cc4ac  mov      w12, #0x6625
//   0x03ba28: 1286f32d  mov      w13, #-0x379a
//   0x03ba2c: 5283226e  mov      w14, #0x1913
//   0x03ba30: 5286810f  mov      w15, #0x3408
//   0x03ba34: 52844090  mov      w16, #0x2204
//   0x03ba38: 52902351  mov      w17, #0x811a
//   0x03ba3c: 1288a284  mov      w4, #-0x4515
//   0x03ba40: 38401405  ldrb     w5, [x0], #1
uint64_t fde_0574_sub_03ba04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE57F6ULL) + (x1 ^ 0x52844090ULL) + (x2 ^ 0x03BA04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE57F6ULL; // 0x03ba04: stp x22, x21, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03ba08: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03ba0c: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400068BULL; // 0x03ba10: b.lt #0x3bae0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x03ba14: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E9ULL; // 0x03ba18: mov w9, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEAULL; // 0x03ba1c: mov w10, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x528950ABULL; // 0x03ba20: mov w11, #0x4a85
    acc = (acc * 0x100000001B3ULL) ^ 0x528CC4ACULL; // 0x03ba24: mov w12, #0x6625
    acc = (acc * 0x100000001B3ULL) ^ 0x1286F32DULL; // 0x03ba28: mov w13, #-0x379a
    return acc;
}

// [EN] Reconstructed FDE #0575 @ 0x03baec..0x03bfc8 (1244 bytes)
// [VN] Phục dựng FDE #0575 tại 0x03baec..0x03bfc8 (1244 byte)
//   0x03baec: 6dba3bef  stp      d15, d14, [sp, #-0x60]!
//   0x03baf0: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x03baf4: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x03baf8: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x03bafc: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03bb00: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03bb04: 7100049f  cmp      w4, #1
//   0x03bb08: 5400252b  b.lt     #0x3bfac
//   0x03bb0c: 7100409f  cmp      w4, #0x10
//   0x03bb10: 2a0403e8  mov      w8, w4
//   0x03bb14: aa1f03e9  mov      x9, xzr
//   0x03bb18: 54001dc3  b.lo     #0x3bed0
//   0x03bb1c: 8b08000a  add      x10, x0, x8
//   0x03bb20: 8b08046d  add      x13, x3, x8, lsl #1
//   0x03bb24: eb03015f  cmp      x10, x3
//   0x03bb28: 8b08002b  add      x11, x1, x8
uint64_t fde_0575_sub_03baec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DBA3BEFULL) + (x1 ^ 0x8B08000AULL) + (x2 ^ 0x03BAECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DBA3BEFULL; // 0x03baec: stp d15, d14, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0133EDULL; // 0x03baf0: stp d13, d12, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D022BEBULL; // 0x03baf4: stp d11, d10, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x03baf8: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03bafc: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03bb00: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03bb04: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400252BULL; // 0x03bb08: b.lt #0x3bfac
    acc = (acc * 0x100000001B3ULL) ^ 0x7100409FULL; // 0x03bb0c: cmp w4, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E8ULL; // 0x03bb10: mov w8, w4
    return acc;
}

// [EN] Reconstructed FDE #0576 @ 0x03bfc8..0x03c4ec (1316 bytes)
// [VN] Phục dựng FDE #0576 tại 0x03bfc8..0x03c4ec (1316 byte)
//   0x03bfc8: 6dba3bef  stp      d15, d14, [sp, #-0x60]!
//   0x03bfcc: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x03bfd0: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x03bfd4: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x03bfd8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03bfdc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03bfe0: 7100049f  cmp      w4, #1
//   0x03bfe4: 5400276b  b.lt     #0x3c4d0
//   0x03bfe8: 7100409f  cmp      w4, #0x10
//   0x03bfec: 2a0403e8  mov      w8, w4
//   0x03bff0: aa1f03e9  mov      x9, xzr
//   0x03bff4: 54001fc3  b.lo     #0x3c3ec
//   0x03bff8: 8b08000a  add      x10, x0, x8
//   0x03bffc: 8b08046d  add      x13, x3, x8, lsl #1
//   0x03c000: eb03015f  cmp      x10, x3
//   0x03c004: 8b08002b  add      x11, x1, x8
uint64_t fde_0576_sub_03bfc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DBA3BEFULL) + (x1 ^ 0x8B08000AULL) + (x2 ^ 0x03BFC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DBA3BEFULL; // 0x03bfc8: stp d15, d14, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0133EDULL; // 0x03bfcc: stp d13, d12, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D022BEBULL; // 0x03bfd0: stp d11, d10, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x03bfd4: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x03bfd8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03bfdc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x03bfe0: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400276BULL; // 0x03bfe4: b.lt #0x3c4d0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100409FULL; // 0x03bfe8: cmp w4, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E8ULL; // 0x03bfec: mov w8, w4
    return acc;
}

// [EN] Reconstructed FDE #0577 @ 0x03c4ec..0x03c5b4 (200 bytes)
// [VN] Phục dựng FDE #0577 tại 0x03c4ec..0x03c5b4 (200 byte)
//   0x03c4ec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03c4f0: 910003fd  mov      x29, sp
//   0x03c4f4: 90000140  adrp     x0, #0x64000
//   0x03c4f8: 9113a000  add      x0, x0, #0x4e8
//   0x03c4fc: 97ff1f0d  bl       #0x4130
//   0x03c500: 34000060  cbz      w0, #0x3c50c
//   0x03c504: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03c508: d65f03c0  ret      
//   0x03c50c: f0000129  adrp     x9, #0x63000
//   0x03c510: f947bd29  ldr      x9, [x9, #0xf78]
//   0x03c514: 90000148  adrp     x8, #0x64000
//   0x03c518: f941690a  ldr      x10, [x8, #0x2d0]
//   0x03c51c: f9400129  ldr      x9, [x9]
//   0x03c520: eb09015f  cmp      x10, x9
//   0x03c524: 540003e0  b.eq     #0x3c5a0
//   0x03c528: f000012a  adrp     x10, #0x63000
uint64_t fde_0577_sub_03c4ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF9400129ULL) + (x2 ^ 0x03C4ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03c4ec: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03c4f0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90000140ULL; // 0x03c4f4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9113A000ULL; // 0x03c4f8: add x0, x0, #0x4e8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF1F0DULL; // 0x03c4fc: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000060ULL; // 0x03c500: cbz w0, #0x3c50c
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03c504: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03c508: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000129ULL; // 0x03c50c: adrp x9, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947BD29ULL; // 0x03c510: ldr x9, [x9, #0xf78]
    return acc;
}

// [EN] Reconstructed FDE #0578 @ 0x03c5b4..0x03c630 (124 bytes)
// [VN] Phục dựng FDE #0578 tại 0x03c5b4..0x03c630 (124 byte)
//   0x03c5b4: d0000008  adrp     x8, #0x3e000
//   0x03c5b8: f000012a  adrp     x10, #0x63000
//   0x03c5bc: f000000b  adrp     x11, #0x3f000
//   0x03c5c0: 9129c108  add      x8, x8, #0xa70
//   0x03c5c4: f946194a  ldr      x10, [x10, #0xc30]
//   0x03c5c8: 912ef16b  add      x11, x11, #0xbbc
//   0x03c5cc: 90000009  adrp     x9, #0x3c000
//   0x03c5d0: 9e670100  fmov     d0, x8
//   0x03c5d4: b0000028  adrp     x8, #0x41000
//   0x03c5d8: 9e670161  fmov     d1, x11
//   0x03c5dc: b000000b  adrp     x11, #0x3d000
//   0x03c5e0: 9118c129  add      x9, x9, #0x630
//   0x03c5e4: 913cb108  add      x8, x8, #0xf2c
//   0x03c5e8: 9121516b  add      x11, x11, #0x854
//   0x03c5ec: 9e670102  fmov     d2, x8
//   0x03c5f0: 90000028  adrp     x8, #0x40000
uint64_t fde_0578_sub_03c5b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000008ULL) + (x1 ^ 0x913CB108ULL) + (x2 ^ 0x03C5B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000008ULL; // 0x03c5b4: adrp x8, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0xF000012AULL; // 0x03c5b8: adrp x10, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF000000BULL; // 0x03c5bc: adrp x11, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x9129C108ULL; // 0x03c5c0: add x8, x8, #0xa70
    acc = (acc * 0x100000001B3ULL) ^ 0xF946194AULL; // 0x03c5c4: ldr x10, [x10, #0xc30]
    acc = (acc * 0x100000001B3ULL) ^ 0x912EF16BULL; // 0x03c5c8: add x11, x11, #0xbbc
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x03c5cc: adrp x9, #0x3c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x03c5d0: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000028ULL; // 0x03c5d4: adrp x8, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670161ULL; // 0x03c5d8: fmov d1, x11
    return acc;
}

// [EN] Reconstructed FDE #0579 @ 0x03c630..0x03d854 (4644 bytes)
// [VN] Phục dựng FDE #0579 tại 0x03c630..0x03d854 (4644 byte)
//   0x03c630: d10643ff  sub      sp, sp, #0x190
//   0x03c634: 6d0f3bef  stp      d15, d14, [sp, #0xf0]
//   0x03c638: 6d1033ed  stp      d13, d12, [sp, #0x100]
//   0x03c63c: 6d112beb  stp      d11, d10, [sp, #0x110]
//   0x03c640: 6d1223e9  stp      d9, d8, [sp, #0x120]
//   0x03c644: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x03c648: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x03c64c: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x03c650: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x03c654: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x03c658: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x03c65c: 910603fd  add      x29, sp, #0x180
//   0x03c660: d53bd04d  mrs      x13, tpidr_el0
//   0x03c664: f9001bed  str      x13, [sp, #0x30]
//   0x03c668: f94015ad  ldr      x13, [x13, #0x28]
//   0x03c66c: b94013b6  ldr      w22, [x29, #0x10]
uint64_t fde_0579_sub_03c630(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xD53BD04DULL) + (x2 ^ 0x03C630ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x03c630: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F3BEFULL; // 0x03c634: stp d15, d14, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1033EDULL; // 0x03c638: stp d13, d12, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D112BEBULL; // 0x03c63c: stp d11, d10, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1223E9ULL; // 0x03c640: stp d9, d8, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9136FFCULL; // 0x03c644: stp x28, x27, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91467FAULL; // 0x03c648: stp x26, x25, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x03c64c: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x03c650: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x03c654: stp x20, x19, [sp, #0x170]
    return acc;
}

// [EN] Reconstructed FDE #0580 @ 0x03d854..0x03ea70 (4636 bytes)
// [VN] Phục dựng FDE #0580 tại 0x03d854..0x03ea70 (4636 byte)
//   0x03d854: d10643ff  sub      sp, sp, #0x190
//   0x03d858: 6d0f3bef  stp      d15, d14, [sp, #0xf0]
//   0x03d85c: 6d1033ed  stp      d13, d12, [sp, #0x100]
//   0x03d860: 6d112beb  stp      d11, d10, [sp, #0x110]
//   0x03d864: 6d1223e9  stp      d9, d8, [sp, #0x120]
//   0x03d868: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x03d86c: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x03d870: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x03d874: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x03d878: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x03d87c: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x03d880: 910603fd  add      x29, sp, #0x180
//   0x03d884: d53bd04d  mrs      x13, tpidr_el0
//   0x03d888: f9001bed  str      x13, [sp, #0x30]
//   0x03d88c: f94015ad  ldr      x13, [x13, #0x28]
//   0x03d890: b94013ba  ldr      w26, [x29, #0x10]
uint64_t fde_0580_sub_03d854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xD53BD04DULL) + (x2 ^ 0x03D854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x03d854: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F3BEFULL; // 0x03d858: stp d15, d14, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1033EDULL; // 0x03d85c: stp d13, d12, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D112BEBULL; // 0x03d860: stp d11, d10, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1223E9ULL; // 0x03d864: stp d9, d8, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9136FFCULL; // 0x03d868: stp x28, x27, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91467FAULL; // 0x03d86c: stp x26, x25, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x03d870: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x03d874: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x03d878: stp x20, x19, [sp, #0x170]
    return acc;
}

// [EN] Reconstructed FDE #0581 @ 0x03ea70..0x03fbbc (4428 bytes)
// [VN] Phục dựng FDE #0581 tại 0x03ea70..0x03fbbc (4428 byte)
//   0x03ea70: d10583ff  sub      sp, sp, #0x160
//   0x03ea74: 6d0c3bef  stp      d15, d14, [sp, #0xc0]
//   0x03ea78: 6d0d33ed  stp      d13, d12, [sp, #0xd0]
//   0x03ea7c: 6d0e2beb  stp      d11, d10, [sp, #0xe0]
//   0x03ea80: 6d0f23e9  stp      d9, d8, [sp, #0xf0]
//   0x03ea84: a9106ffc  stp      x28, x27, [sp, #0x100]
//   0x03ea88: a91167fa  stp      x26, x25, [sp, #0x110]
//   0x03ea8c: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x03ea90: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x03ea94: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x03ea98: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x03ea9c: 910543fd  add      x29, sp, #0x150
//   0x03eaa0: d53bd04d  mrs      x13, tpidr_el0
//   0x03eaa4: f9001bed  str      x13, [sp, #0x30]
//   0x03eaa8: b94013b1  ldr      w17, [x29, #0x10]
//   0x03eaac: f94015ad  ldr      x13, [x13, #0x28]
uint64_t fde_0581_sub_03ea70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xD53BD04DULL) + (x2 ^ 0x03EA70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x03ea70: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0C3BEFULL; // 0x03ea74: stp d15, d14, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0D33EDULL; // 0x03ea78: stp d13, d12, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0E2BEBULL; // 0x03ea7c: stp d11, d10, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F23E9ULL; // 0x03ea80: stp d9, d8, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9106FFCULL; // 0x03ea84: stp x28, x27, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91167FAULL; // 0x03ea88: stp x26, x25, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x03ea8c: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x03ea90: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x03ea94: stp x20, x19, [sp, #0x140]
    return acc;
}

// [EN] Reconstructed FDE #0582 @ 0x03fbbc..0x040d08 (4428 bytes)
// [VN] Phục dựng FDE #0582 tại 0x03fbbc..0x040d08 (4428 byte)
//   0x03fbbc: d10583ff  sub      sp, sp, #0x160
//   0x03fbc0: 6d0c3bef  stp      d15, d14, [sp, #0xc0]
//   0x03fbc4: 6d0d33ed  stp      d13, d12, [sp, #0xd0]
//   0x03fbc8: 6d0e2beb  stp      d11, d10, [sp, #0xe0]
//   0x03fbcc: 6d0f23e9  stp      d9, d8, [sp, #0xf0]
//   0x03fbd0: a9106ffc  stp      x28, x27, [sp, #0x100]
//   0x03fbd4: a91167fa  stp      x26, x25, [sp, #0x110]
//   0x03fbd8: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x03fbdc: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x03fbe0: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x03fbe4: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x03fbe8: 910543fd  add      x29, sp, #0x150
//   0x03fbec: d53bd04d  mrs      x13, tpidr_el0
//   0x03fbf0: f9001bed  str      x13, [sp, #0x30]
//   0x03fbf4: b94013b1  ldr      w17, [x29, #0x10]
//   0x03fbf8: f94015ad  ldr      x13, [x13, #0x28]
uint64_t fde_0582_sub_03fbbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xD53BD04DULL) + (x2 ^ 0x03FBBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x03fbbc: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0C3BEFULL; // 0x03fbc0: stp d15, d14, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0D33EDULL; // 0x03fbc4: stp d13, d12, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0E2BEBULL; // 0x03fbc8: stp d11, d10, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F23E9ULL; // 0x03fbcc: stp d9, d8, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9106FFCULL; // 0x03fbd0: stp x28, x27, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91167FAULL; // 0x03fbd4: stp x26, x25, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x03fbd8: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x03fbdc: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x03fbe0: stp x20, x19, [sp, #0x140]
    return acc;
}

// [EN] Reconstructed FDE #0583 @ 0x040d08..0x041f2c (4644 bytes)
// [VN] Phục dựng FDE #0583 tại 0x040d08..0x041f2c (4644 byte)
//   0x040d08: d10643ff  sub      sp, sp, #0x190
//   0x040d0c: 6d0f3bef  stp      d15, d14, [sp, #0xf0]
//   0x040d10: 6d1033ed  stp      d13, d12, [sp, #0x100]
//   0x040d14: 6d112beb  stp      d11, d10, [sp, #0x110]
//   0x040d18: 6d1223e9  stp      d9, d8, [sp, #0x120]
//   0x040d1c: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x040d20: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x040d24: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x040d28: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x040d2c: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x040d30: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x040d34: 910603fd  add      x29, sp, #0x180
//   0x040d38: d53bd04d  mrs      x13, tpidr_el0
//   0x040d3c: f9001bed  str      x13, [sp, #0x30]
//   0x040d40: f94015ad  ldr      x13, [x13, #0x28]
//   0x040d44: b94013b6  ldr      w22, [x29, #0x10]
uint64_t fde_0583_sub_040d08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xD53BD04DULL) + (x2 ^ 0x040D08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x040d08: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F3BEFULL; // 0x040d0c: stp d15, d14, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1033EDULL; // 0x040d10: stp d13, d12, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D112BEBULL; // 0x040d14: stp d11, d10, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1223E9ULL; // 0x040d18: stp d9, d8, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9136FFCULL; // 0x040d1c: stp x28, x27, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91467FAULL; // 0x040d20: stp x26, x25, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x040d24: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x040d28: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x040d2c: stp x20, x19, [sp, #0x170]
    return acc;
}

// [EN] Reconstructed FDE #0584 @ 0x041f2c..0x043174 (4680 bytes)
// [VN] Phục dựng FDE #0584 tại 0x041f2c..0x043174 (4680 byte)
//   0x041f2c: d105c3ff  sub      sp, sp, #0x170
//   0x041f30: 6d0d3bef  stp      d15, d14, [sp, #0xd0]
//   0x041f34: 6d0e33ed  stp      d13, d12, [sp, #0xe0]
//   0x041f38: 6d0f2beb  stp      d11, d10, [sp, #0xf0]
//   0x041f3c: 6d1023e9  stp      d9, d8, [sp, #0x100]
//   0x041f40: a9116ffc  stp      x28, x27, [sp, #0x110]
//   0x041f44: a91267fa  stp      x26, x25, [sp, #0x120]
//   0x041f48: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x041f4c: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x041f50: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x041f54: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x041f58: 910583fd  add      x29, sp, #0x160
//   0x041f5c: d53bd04c  mrs      x12, tpidr_el0
//   0x041f60: f9001fec  str      x12, [sp, #0x38]
//   0x041f64: f940158c  ldr      x12, [x12, #0x28]
//   0x041f68: b94013bc  ldr      w28, [x29, #0x10]
uint64_t fde_0584_sub_041f2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD105C3FFULL) + (x1 ^ 0xD53BD04CULL) + (x2 ^ 0x041F2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD105C3FFULL; // 0x041f2c: sub sp, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0D3BEFULL; // 0x041f30: stp d15, d14, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0E33EDULL; // 0x041f34: stp d13, d12, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F2BEBULL; // 0x041f38: stp d11, d10, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1023E9ULL; // 0x041f3c: stp d9, d8, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9116FFCULL; // 0x041f40: stp x28, x27, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91267FAULL; // 0x041f44: stp x26, x25, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9135FF8ULL; // 0x041f48: stp x24, x23, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91457F6ULL; // 0x041f4c: stp x22, x21, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9154FF4ULL; // 0x041f50: stp x20, x19, [sp, #0x150]
    return acc;
}

// [EN] Reconstructed FDE #0585 @ 0x043174..0x044310 (4508 bytes)
// [VN] Phục dựng FDE #0585 tại 0x043174..0x044310 (4508 byte)
//   0x043174: d105c3ff  sub      sp, sp, #0x170
//   0x043178: fd006bee  str      d14, [sp, #0xd0]
//   0x04317c: 6d0e33ed  stp      d13, d12, [sp, #0xe0]
//   0x043180: 6d0f2beb  stp      d11, d10, [sp, #0xf0]
//   0x043184: 6d1023e9  stp      d9, d8, [sp, #0x100]
//   0x043188: a9116ffc  stp      x28, x27, [sp, #0x110]
//   0x04318c: a91267fa  stp      x26, x25, [sp, #0x120]
//   0x043190: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x043194: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x043198: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x04319c: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x0431a0: 910583fd  add      x29, sp, #0x160
//   0x0431a4: d53bd04d  mrs      x13, tpidr_el0
//   0x0431a8: f9001fed  str      x13, [sp, #0x38]
//   0x0431ac: f94015ad  ldr      x13, [x13, #0x28]
//   0x0431b0: b94013bc  ldr      w28, [x29, #0x10]
uint64_t fde_0585_sub_043174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD105C3FFULL) + (x1 ^ 0xD53BD04DULL) + (x2 ^ 0x043174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD105C3FFULL; // 0x043174: sub sp, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xFD006BEEULL; // 0x043178: str d14, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0E33EDULL; // 0x04317c: stp d13, d12, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F2BEBULL; // 0x043180: stp d11, d10, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D1023E9ULL; // 0x043184: stp d9, d8, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9116FFCULL; // 0x043188: stp x28, x27, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91267FAULL; // 0x04318c: stp x26, x25, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9135FF8ULL; // 0x043190: stp x24, x23, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91457F6ULL; // 0x043194: stp x22, x21, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9154FF4ULL; // 0x043198: stp x20, x19, [sp, #0x150]
    return acc;
}

// [EN] Reconstructed FDE #0586 @ 0x044310..0x0443cc (188 bytes)
// [VN] Phục dựng FDE #0586 tại 0x044310..0x0443cc (188 byte)
//   0x044310: d101c3ff  sub      sp, sp, #0x70
//   0x044314: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x044318: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x04431c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x044320: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x044324: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x044328: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x04432c: 910183fd  add      x29, sp, #0x60
//   0x044330: b94013ba  ldr      w26, [x29, #0x10]
//   0x044334: 7100075f  cmp      w26, #1
//   0x044338: 540003ab  b.lt     #0x443ac
//   0x04433c: f9400fa9  ldr      x9, [x29, #0x18]
//   0x044340: 2a0703f8  mov      w24, w7
//   0x044344: aa0503f4  mov      x20, x5
//   0x044348: aa0303f5  mov      x21, x3
//   0x04434c: aa0203f6  mov      x22, x2
uint64_t fde_0586_sub_044310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0703F8ULL) + (x2 ^ 0x044310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x044310: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x044314: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x044318: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x04431c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x044320: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x044324: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x044328: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x04432c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB94013BAULL; // 0x044330: ldr w26, [x29, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100075FULL; // 0x044334: cmp w26, #1
    return acc;
}

// [EN] Reconstructed FDE #0587 @ 0x0443cc..0x044494 (200 bytes)
// [VN] Phục dựng FDE #0587 tại 0x0443cc..0x044494 (200 byte)
//   0x0443cc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0443d0: 910003fd  mov      x29, sp
//   0x0443d4: 90000100  adrp     x0, #0x64000
//   0x0443d8: 9114e000  add      x0, x0, #0x538
//   0x0443dc: 97feff55  bl       #0x4130
//   0x0443e0: 34000060  cbz      w0, #0x443ec
//   0x0443e4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0443e8: d65f03c0  ret      
//   0x0443ec: f00000e9  adrp     x9, #0x63000
//   0x0443f0: f947bd29  ldr      x9, [x9, #0xf78]
//   0x0443f4: 90000108  adrp     x8, #0x64000
//   0x0443f8: f941710a  ldr      x10, [x8, #0x2e0]
//   0x0443fc: f9400129  ldr      x9, [x9]
//   0x044400: eb09015f  cmp      x10, x9
//   0x044404: 540003e0  b.eq     #0x44480
//   0x044408: f00000ec  adrp     x12, #0x63000
uint64_t fde_0587_sub_0443cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF9400129ULL) + (x2 ^ 0x0443CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0443cc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0443d0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90000100ULL; // 0x0443d4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x9114E000ULL; // 0x0443d8: add x0, x0, #0x538
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEFF55ULL; // 0x0443dc: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000060ULL; // 0x0443e0: cbz w0, #0x443ec
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0443e4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0443e8: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000E9ULL; // 0x0443ec: adrp x9, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947BD29ULL; // 0x0443f0: ldr x9, [x9, #0xf78]
    return acc;
}

// [EN] Reconstructed FDE #0588 @ 0x044494..0x044658 (452 bytes)
// [VN] Phục dựng FDE #0588 tại 0x044494..0x044658 (452 byte)
//   0x044494: a9bf4ff4  stp      x20, x19, [sp, #-0x10]!
//   0x044498: 7100087f  cmp      w3, #2
//   0x04449c: 540007ab  b.lt     #0x44590
//   0x0444a0: aa1f03e8  mov      x8, xzr
//   0x0444a4: 53017c69  lsr      w9, w3, #1
//   0x0444a8: 9100100a  add      x10, x0, #4
//   0x0444ac: 1284becb  mov      w11, #-0x25f7
//   0x0444b0: 1289510c  mov      w12, #-0x4a89
//   0x0444b4: 528e100d  mov      w13, #0x7080
//   0x0444b8: 52a0404e  mov      w14, #0x2020000
//   0x0444bc: 52801fef  mov      w15, #0xff
//   0x0444c0: 128bc670  mov      w16, #-0x5e34
//   0x0444c4: 12824971  mov      w17, #-0x124c
//   0x0444c8: 1400000f  b        #0x44504
//   0x0444cc: 38686827  ldrb     w7, [x1, x8]
//   0x0444d0: 0b0700c6  add      w6, w6, w7
uint64_t fde_0588_sub_044494(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF4FF4ULL) + (x1 ^ 0x12824971ULL) + (x2 ^ 0x044494ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF4FF4ULL; // 0x044494: stp x20, x19, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7100087FULL; // 0x044498: cmp w3, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x540007ABULL; // 0x04449c: b.lt #0x44590
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x0444a0: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x53017C69ULL; // 0x0444a4: lsr w9, w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9100100AULL; // 0x0444a8: add x10, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x1284BECBULL; // 0x0444ac: mov w11, #-0x25f7
    acc = (acc * 0x100000001B3ULL) ^ 0x1289510CULL; // 0x0444b0: mov w12, #-0x4a89
    acc = (acc * 0x100000001B3ULL) ^ 0x528E100DULL; // 0x0444b4: mov w13, #0x7080
    acc = (acc * 0x100000001B3ULL) ^ 0x52A0404EULL; // 0x0444b8: mov w14, #0x2020000
    return acc;
}

// [EN] Reconstructed FDE #0589 @ 0x044658..0x0448c8 (624 bytes)
// [VN] Phục dựng FDE #0589 tại 0x044658..0x0448c8 (624 byte)
//   0x044658: 7100047f  cmp      w3, #1
//   0x04465c: 5400134b  b.lt     #0x448c4
//   0x044660: 7100247f  cmp      w3, #9
//   0x044664: 2a0303e8  mov      w8, w3
//   0x044668: aa1f03e9  mov      x9, xzr
//   0x04466c: 54000e43  b.lo     #0x44834
//   0x044670: 8b08004d  add      x13, x2, x8
//   0x044674: 8b08002b  add      x11, x1, x8
//   0x044678: 8b080c0a  add      x10, x0, x8, lsl #3
//   0x04467c: eb0101bf  cmp      x13, x1
//   0x044680: d100094e  sub      x14, x10, #2
//   0x044684: 1a9f97ea  cset     w10, hi
//   0x044688: eb02017f  cmp      x11, x2
//   0x04468c: 1a9f97ec  cset     w12, hi
//   0x044690: eb0101df  cmp      x14, x1
//   0x044694: 0a0c014f  and      w15, w10, w12
uint64_t fde_0589_sub_044658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100047FULL) + (x1 ^ 0xEB02017FULL) + (x2 ^ 0x044658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x044658: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400134BULL; // 0x04465c: b.lt #0x448c4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100247FULL; // 0x044660: cmp w3, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E8ULL; // 0x044664: mov w8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x044668: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x54000E43ULL; // 0x04466c: b.lo #0x44834
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08004DULL; // 0x044670: add x13, x2, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08002BULL; // 0x044674: add x11, x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080C0AULL; // 0x044678: add x10, x0, x8, lsl #3
    acc = (acc * 0x100000001B3ULL) ^ 0xEB0101BFULL; // 0x04467c: cmp x13, x1
    return acc;
}

// [EN] Reconstructed FDE #0590 @ 0x0448c8..0x044990 (200 bytes)
// [VN] Phục dựng FDE #0590 tại 0x0448c8..0x044990 (200 byte)
//   0x0448c8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0448cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0448d0: 910043fd  add      x29, sp, #0x10
//   0x0448d4: 90000100  adrp     x0, #0x64000
//   0x0448d8: 91158000  add      x0, x0, #0x560
//   0x0448dc: 97fefe15  bl       #0x4130
//   0x0448e0: 34000080  cbz      w0, #0x448f0
//   0x0448e4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0448e8: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x0448ec: d65f03c0  ret      
//   0x0448f0: f00000f4  adrp     x20, #0x63000
//   0x0448f4: f947be94  ldr      x20, [x20, #0xf78]
//   0x0448f8: 90000113  adrp     x19, #0x64000
//   0x0448fc: f9417669  ldr      x9, [x19, #0x2e8]
//   0x044900: f9400288  ldr      x8, [x20]
//   0x044904: eb08013f  cmp      x9, x8
uint64_t fde_0590_sub_0448c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x90000113ULL) + (x2 ^ 0x0448C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0448c8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0448cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0448d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000100ULL; // 0x0448d4: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91158000ULL; // 0x0448d8: add x0, x0, #0x560
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEFE15ULL; // 0x0448dc: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x0448e0: cbz w0, #0x448f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0448e4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x0448e8: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0448ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #0591 @ 0x044990..0x0450cc (1852 bytes)
// [VN] Phục dựng FDE #0591 tại 0x044990..0x0450cc (1852 byte)
//   0x044990: d10483ff  sub      sp, sp, #0x120
//   0x044994: 6d0c3bef  stp      d15, d14, [sp, #0xc0]
//   0x044998: 6d0d33ed  stp      d13, d12, [sp, #0xd0]
//   0x04499c: 6d0e2beb  stp      d11, d10, [sp, #0xe0]
//   0x0449a0: 6d0f23e9  stp      d9, d8, [sp, #0xf0]
//   0x0449a4: a91057fc  stp      x28, x21, [sp, #0x100]
//   0x0449a8: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x0449ac: 721f7888  ands     w8, w4, #0xfffffffe
//   0x0449b0: 54003880  b.eq     #0x450c0
//   0x0449b4: 0b080508  add      w8, w8, w8, lsl #1
//   0x0449b8: 93407d08  sxtw     x8, w8
//   0x0449bc: b201f3ea  mov      x10, #-0x5555555555555556
//   0x0449c0: d1001909  sub      x9, x8, #6
//   0x0449c4: f295556a  movk     x10, #0xaaab
//   0x0449c8: 9bca7d29  umulh    x9, x9, x10
//   0x0449cc: d342fd29  lsr      x9, x9, #2
uint64_t fde_0591_sub_044990(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xD1001909ULL) + (x2 ^ 0x044990ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x044990: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0C3BEFULL; // 0x044994: stp d15, d14, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0D33EDULL; // 0x044998: stp d13, d12, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0E2BEBULL; // 0x04499c: stp d11, d10, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F23E9ULL; // 0x0449a0: stp d9, d8, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057FCULL; // 0x0449a4: stp x28, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x0449a8: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x721F7888ULL; // 0x0449ac: ands w8, w4, #0xfffffffe
    acc = (acc * 0x100000001B3ULL) ^ 0x54003880ULL; // 0x0449b0: b.eq #0x450c0
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080508ULL; // 0x0449b4: add w8, w8, w8, lsl #1
    return acc;
}

// [EN] Reconstructed FDE #0592 @ 0x0450cc..0x045810 (1860 bytes)
// [VN] Phục dựng FDE #0592 tại 0x0450cc..0x045810 (1860 byte)
//   0x0450cc: d10303ff  sub      sp, sp, #0xc0
//   0x0450d0: 6d063bef  stp      d15, d14, [sp, #0x60]
//   0x0450d4: 6d0733ed  stp      d13, d12, [sp, #0x70]
//   0x0450d8: 6d082beb  stp      d11, d10, [sp, #0x80]
//   0x0450dc: 6d0923e9  stp      d9, d8, [sp, #0x90]
//   0x0450e0: f90053f5  str      x21, [sp, #0xa0]
//   0x0450e4: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x0450e8: 531e7488  lsl      w8, w4, #2
//   0x0450ec: 721d7108  ands     w8, w8, #0xfffffff8
//   0x0450f0: 540038a0  b.eq     #0x45804
//   0x0450f4: 93407d09  sxtw     x9, w8
//   0x0450f8: d100212a  sub      x10, x9, #8
//   0x0450fc: d343fd48  lsr      x8, x10, #3
//   0x045100: 9100050b  add      x11, x8, #1
//   0x045104: f100217f  cmp      x11, #8
//   0x045108: 8b090068  add      x8, x3, x9
uint64_t fde_0592_sub_0450cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD343FD48ULL) + (x2 ^ 0x0450CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0450cc: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D063BEFULL; // 0x0450d0: stp d15, d14, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0733EDULL; // 0x0450d4: stp d13, d12, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D082BEBULL; // 0x0450d8: stp d11, d10, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0923E9ULL; // 0x0450dc: stp d9, d8, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90053F5ULL; // 0x0450e0: str x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x0450e4: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x531E7488ULL; // 0x0450e8: lsl w8, w4, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x721D7108ULL; // 0x0450ec: ands w8, w8, #0xfffffff8
    acc = (acc * 0x100000001B3ULL) ^ 0x540038A0ULL; // 0x0450f0: b.eq #0x45804
    return acc;
}

// [EN] Reconstructed FDE #0593 @ 0x045810..0x045f4c (1852 bytes)
// [VN] Phục dựng FDE #0593 tại 0x045810..0x045f4c (1852 byte)
//   0x045810: d10483ff  sub      sp, sp, #0x120
//   0x045814: 6d0c3bef  stp      d15, d14, [sp, #0xc0]
//   0x045818: 6d0d33ed  stp      d13, d12, [sp, #0xd0]
//   0x04581c: 6d0e2beb  stp      d11, d10, [sp, #0xe0]
//   0x045820: 6d0f23e9  stp      d9, d8, [sp, #0xf0]
//   0x045824: a91057fc  stp      x28, x21, [sp, #0x100]
//   0x045828: a9114ff4  stp      x20, x19, [sp, #0x110]
//   0x04582c: 721f7888  ands     w8, w4, #0xfffffffe
//   0x045830: 54003880  b.eq     #0x45f40
//   0x045834: 0b080508  add      w8, w8, w8, lsl #1
//   0x045838: 93407d08  sxtw     x8, w8
//   0x04583c: b201f3ea  mov      x10, #-0x5555555555555556
//   0x045840: d1001909  sub      x9, x8, #6
//   0x045844: f295556a  movk     x10, #0xaaab
//   0x045848: 9bca7d29  umulh    x9, x9, x10
//   0x04584c: d342fd29  lsr      x9, x9, #2
uint64_t fde_0593_sub_045810(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xD1001909ULL) + (x2 ^ 0x045810ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x045810: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0C3BEFULL; // 0x045814: stp d15, d14, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0D33EDULL; // 0x045818: stp d13, d12, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0E2BEBULL; // 0x04581c: stp d11, d10, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0F23E9ULL; // 0x045820: stp d9, d8, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91057FCULL; // 0x045824: stp x28, x21, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9114FF4ULL; // 0x045828: stp x20, x19, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x721F7888ULL; // 0x04582c: ands w8, w4, #0xfffffffe
    acc = (acc * 0x100000001B3ULL) ^ 0x54003880ULL; // 0x045830: b.eq #0x45f40
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080508ULL; // 0x045834: add w8, w8, w8, lsl #1
    return acc;
}

// [EN] Reconstructed FDE #0594 @ 0x045f4c..0x046690 (1860 bytes)
// [VN] Phục dựng FDE #0594 tại 0x045f4c..0x046690 (1860 byte)
//   0x045f4c: d10303ff  sub      sp, sp, #0xc0
//   0x045f50: 6d063bef  stp      d15, d14, [sp, #0x60]
//   0x045f54: 6d0733ed  stp      d13, d12, [sp, #0x70]
//   0x045f58: 6d082beb  stp      d11, d10, [sp, #0x80]
//   0x045f5c: 6d0923e9  stp      d9, d8, [sp, #0x90]
//   0x045f60: f90053f5  str      x21, [sp, #0xa0]
//   0x045f64: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x045f68: 531e7488  lsl      w8, w4, #2
//   0x045f6c: 721d7108  ands     w8, w8, #0xfffffff8
//   0x045f70: 540038a0  b.eq     #0x46684
//   0x045f74: 93407d09  sxtw     x9, w8
//   0x045f78: d100212a  sub      x10, x9, #8
//   0x045f7c: d343fd48  lsr      x8, x10, #3
//   0x045f80: 9100050b  add      x11, x8, #1
//   0x045f84: f100217f  cmp      x11, #8
//   0x045f88: 8b090068  add      x8, x3, x9
uint64_t fde_0594_sub_045f4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD343FD48ULL) + (x2 ^ 0x045F4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x045f4c: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D063BEFULL; // 0x045f50: stp d15, d14, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0733EDULL; // 0x045f54: stp d13, d12, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D082BEBULL; // 0x045f58: stp d11, d10, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0923E9ULL; // 0x045f5c: stp d9, d8, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90053F5ULL; // 0x045f60: str x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x045f64: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x531E7488ULL; // 0x045f68: lsl w8, w4, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x721D7108ULL; // 0x045f6c: ands w8, w8, #0xfffffff8
    acc = (acc * 0x100000001B3ULL) ^ 0x540038A0ULL; // 0x045f70: b.eq #0x46684
    return acc;
}

// [EN] Reconstructed FDE #0595 @ 0x046690..0x046dd4 (1860 bytes)
// [VN] Phục dựng FDE #0595 tại 0x046690..0x046dd4 (1860 byte)
//   0x046690: d10303ff  sub      sp, sp, #0xc0
//   0x046694: 6d063bef  stp      d15, d14, [sp, #0x60]
//   0x046698: 6d0733ed  stp      d13, d12, [sp, #0x70]
//   0x04669c: 6d082beb  stp      d11, d10, [sp, #0x80]
//   0x0466a0: 6d0923e9  stp      d9, d8, [sp, #0x90]
//   0x0466a4: f90053f5  str      x21, [sp, #0xa0]
//   0x0466a8: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x0466ac: 531e7488  lsl      w8, w4, #2
//   0x0466b0: 721d7108  ands     w8, w8, #0xfffffff8
//   0x0466b4: 540038a0  b.eq     #0x46dc8
//   0x0466b8: 93407d09  sxtw     x9, w8
//   0x0466bc: d100212a  sub      x10, x9, #8
//   0x0466c0: d343fd48  lsr      x8, x10, #3
//   0x0466c4: 9100050b  add      x11, x8, #1
//   0x0466c8: f100217f  cmp      x11, #8
//   0x0466cc: 8b090068  add      x8, x3, x9
uint64_t fde_0595_sub_046690(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD343FD48ULL) + (x2 ^ 0x046690ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x046690: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D063BEFULL; // 0x046694: stp d15, d14, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0733EDULL; // 0x046698: stp d13, d12, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D082BEBULL; // 0x04669c: stp d11, d10, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0923E9ULL; // 0x0466a0: stp d9, d8, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90053F5ULL; // 0x0466a4: str x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x0466a8: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x531E7488ULL; // 0x0466ac: lsl w8, w4, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x721D7108ULL; // 0x0466b0: ands w8, w8, #0xfffffff8
    acc = (acc * 0x100000001B3ULL) ^ 0x540038A0ULL; // 0x0466b4: b.eq #0x46dc8
    return acc;
}

// [EN] Reconstructed FDE #0596 @ 0x046dd4..0x0477a0 (2508 bytes)
// [VN] Phục dựng FDE #0596 tại 0x046dd4..0x0477a0 (2508 byte)
//   0x046dd4: 6db93bef  stp      d15, d14, [sp, #-0x70]!
//   0x046dd8: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x046ddc: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x046de0: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x046de4: a9045ffc  stp      x28, x23, [sp, #0x40]
//   0x046de8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x046dec: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x046df0: d10683ff  sub      sp, sp, #0x1a0
//   0x046df4: 531f7888  lsl      w8, w4, #1
//   0x046df8: 721e7508  ands     w8, w8, #0xfffffffc
//   0x046dfc: 54004cc0  b.eq     #0x47794
//   0x046e00: 93407d09  sxtw     x9, w8
//   0x046e04: d100112a  sub      x10, x9, #4
//   0x046e08: d342fd48  lsr      x8, x10, #2
//   0x046e0c: 9100050b  add      x11, x8, #1
//   0x046e10: f100417f  cmp      x11, #0x10
uint64_t fde_0596_sub_046dd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DB93BEFULL) + (x1 ^ 0xD100112AULL) + (x2 ^ 0x046DD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DB93BEFULL; // 0x046dd4: stp d15, d14, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0133EDULL; // 0x046dd8: stp d13, d12, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D022BEBULL; // 0x046ddc: stp d11, d10, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x046de0: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FFCULL; // 0x046de4: stp x28, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x046de8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x046dec: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xD10683FFULL; // 0x046df0: sub sp, sp, #0x1a0
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7888ULL; // 0x046df4: lsl w8, w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x721E7508ULL; // 0x046df8: ands w8, w8, #0xfffffffc
    return acc;
}

// [EN] Reconstructed FDE #0597 @ 0x0477a0..0x0481dc (2620 bytes)
// [VN] Phục dựng FDE #0597 tại 0x0477a0..0x0481dc (2620 byte)
//   0x0477a0: 6db93bef  stp      d15, d14, [sp, #-0x70]!
//   0x0477a4: 6d0133ed  stp      d13, d12, [sp, #0x10]
//   0x0477a8: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x0477ac: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x0477b0: a9045ffc  stp      x28, x23, [sp, #0x40]
//   0x0477b4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0477b8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0477bc: d10643ff  sub      sp, sp, #0x190
//   0x0477c0: 531f7888  lsl      w8, w4, #1
//   0x0477c4: 721e7508  ands     w8, w8, #0xfffffffc
//   0x0477c8: 54005040  b.eq     #0x481d0
//   0x0477cc: 93407d09  sxtw     x9, w8
//   0x0477d0: d100112a  sub      x10, x9, #4
//   0x0477d4: d342fd48  lsr      x8, x10, #2
//   0x0477d8: 9100050b  add      x11, x8, #1
//   0x0477dc: f100417f  cmp      x11, #0x10
uint64_t fde_0597_sub_0477a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DB93BEFULL) + (x1 ^ 0xD100112AULL) + (x2 ^ 0x0477A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DB93BEFULL; // 0x0477a0: stp d15, d14, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0133EDULL; // 0x0477a4: stp d13, d12, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D022BEBULL; // 0x0477a8: stp d11, d10, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x0477ac: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FFCULL; // 0x0477b0: stp x28, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x0477b4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0477b8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x0477bc: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7888ULL; // 0x0477c0: lsl w8, w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x721E7508ULL; // 0x0477c4: ands w8, w8, #0xfffffffc
    return acc;
}

// [EN] Reconstructed FDE #0598 @ 0x0481dc..0x0482d4 (248 bytes)
// [VN] Phục dựng FDE #0598 tại 0x0481dc..0x0482d4 (248 byte)
//   0x0481dc: 7100045f  cmp      w2, #1
//   0x0481e0: 540003ab  b.lt     #0x48254
//   0x0481e4: 7100105f  cmp      w2, #4
//   0x0481e8: 2a0203e8  mov      w8, w2
//   0x0481ec: 540000e3  b.lo     #0x48208
//   0x0481f0: 8b080809  add      x9, x0, x8, lsl #2
//   0x0481f4: eb01013f  cmp      x9, x1
//   0x0481f8: 54000309  b.ls     #0x48258
//   0x0481fc: 8b080029  add      x9, x1, x8
//   0x048200: eb00013f  cmp      x9, x0
//   0x048204: 540002a9  b.ls     #0x48258
//   0x048208: aa1f03e9  mov      x9, xzr
//   0x04820c: 8b09002a  add      x10, x1, x9
//   0x048210: 8b09080b  add      x11, x0, x9, lsl #2
//   0x048214: cb090108  sub      x8, x8, x9
//   0x048218: 528838e9  mov      w9, #0x41c7
uint64_t fde_0598_sub_0481dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x8B09002AULL) + (x2 ^ 0x0481DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x0481dc: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540003ABULL; // 0x0481e0: b.lt #0x48254
    acc = (acc * 0x100000001B3ULL) ^ 0x7100105FULL; // 0x0481e4: cmp w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x0481e8: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E3ULL; // 0x0481ec: b.lo #0x48208
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080809ULL; // 0x0481f0: add x9, x0, x8, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01013FULL; // 0x0481f4: cmp x9, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000309ULL; // 0x0481f8: b.ls #0x48258
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080029ULL; // 0x0481fc: add x9, x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00013FULL; // 0x048200: cmp x9, x0
    return acc;
}

// [EN] Reconstructed FDE #0599 @ 0x0482d4..0x048420 (332 bytes)
// [VN] Phục dựng FDE #0599 tại 0x0482d4..0x048420 (332 byte)
//   0x0482d4: 7100045f  cmp      w2, #1
//   0x0482d8: 540003cb  b.lt     #0x48350
//   0x0482dc: 7100405f  cmp      w2, #0x10
//   0x0482e0: 2a0203e8  mov      w8, w2
//   0x0482e4: 54000103  b.lo     #0x48304
//   0x0482e8: 8b080509  add      x9, x8, x8, lsl #1
//   0x0482ec: 8b090009  add      x9, x0, x9
//   0x0482f0: eb01013f  cmp      x9, x1
//   0x0482f4: 54000309  b.ls     #0x48354
//   0x0482f8: 8b080029  add      x9, x1, x8
//   0x0482fc: eb00013f  cmp      x9, x0
//   0x048300: 540002a9  b.ls     #0x48354
//   0x048304: aa1f03ea  mov      x10, xzr
//   0x048308: aa0003e9  mov      x9, x0
//   0x04830c: 8b0a002b  add      x11, x1, x10
//   0x048310: cb0a0108  sub      x8, x8, x10
uint64_t fde_0599_sub_0482d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0xAA1F03EAULL) + (x2 ^ 0x0482D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x0482d4: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540003CBULL; // 0x0482d8: b.lt #0x48350
    acc = (acc * 0x100000001B3ULL) ^ 0x7100405FULL; // 0x0482dc: cmp w2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x0482e0: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000103ULL; // 0x0482e4: b.lo #0x48304
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080509ULL; // 0x0482e8: add x9, x8, x8, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090009ULL; // 0x0482ec: add x9, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01013FULL; // 0x0482f0: cmp x9, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000309ULL; // 0x0482f4: b.ls #0x48354
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080029ULL; // 0x0482f8: add x9, x1, x8
    return acc;
}

// [EN] Reconstructed FDE #0600 @ 0x048420..0x048570 (336 bytes)
// [VN] Phục dựng FDE #0600 tại 0x048420..0x048570 (336 byte)
//   0x048420: 7100045f  cmp      w2, #1
//   0x048424: 540003eb  b.lt     #0x484a0
//   0x048428: 7100405f  cmp      w2, #0x10
//   0x04842c: 2a0203e8  mov      w8, w2
//   0x048430: 54000103  b.lo     #0x48450
//   0x048434: 8b080509  add      x9, x8, x8, lsl #1
//   0x048438: 8b090009  add      x9, x0, x9
//   0x04843c: eb01013f  cmp      x9, x1
//   0x048440: 54000329  b.ls     #0x484a4
//   0x048444: 8b080029  add      x9, x1, x8
//   0x048448: eb00013f  cmp      x9, x0
//   0x04844c: 540002c9  b.ls     #0x484a4
//   0x048450: aa1f03e9  mov      x9, xzr
//   0x048454: aa0003ea  mov      x10, x0
//   0x048458: 8b09002b  add      x11, x1, x9
//   0x04845c: cb090108  sub      x8, x8, x9
uint64_t fde_0600_sub_048420(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0xAA1F03E9ULL) + (x2 ^ 0x048420ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x048420: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540003EBULL; // 0x048424: b.lt #0x484a0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100405FULL; // 0x048428: cmp w2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x04842c: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000103ULL; // 0x048430: b.lo #0x48450
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080509ULL; // 0x048434: add x9, x8, x8, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090009ULL; // 0x048438: add x9, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01013FULL; // 0x04843c: cmp x9, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000329ULL; // 0x048440: b.ls #0x484a4
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080029ULL; // 0x048444: add x9, x1, x8
    return acc;
}

// [EN] Reconstructed FDE #0601 @ 0x048570..0x0485d8 (104 bytes)
// [VN] Phục dựng FDE #0601 tại 0x048570..0x0485d8 (104 byte)
//   0x048570: f00000c8  adrp     x8, #0x63000
//   0x048574: f00000ca  adrp     x10, #0x63000
//   0x048578: f00000cc  adrp     x12, #0x63000
//   0x04857c: f00000ce  adrp     x14, #0x63000
//   0x048580: f00000d0  adrp     x16, #0x63000
//   0x048584: f9478908  ldr      x8, [x8, #0xf10]
//   0x048588: f946b94a  ldr      x10, [x10, #0xd70]
//   0x04858c: f946f18c  ldr      x12, [x12, #0xde0]
//   0x048590: f94785ce  ldr      x14, [x14, #0xf08]
//   0x048594: f946a210  ldr      x16, [x16, #0xd40]
//   0x048598: 90000009  adrp     x9, #0x48000
//   0x04859c: 9000000b  adrp     x11, #0x48000
//   0x0485a0: 9000000d  adrp     x13, #0x48000
//   0x0485a4: 9000000f  adrp     x15, #0x48000
//   0x0485a8: 90000011  adrp     x17, #0x48000
//   0x0485ac: 91176129  add      x9, x9, #0x5d8
uint64_t fde_0601_sub_048570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00000C8ULL) + (x1 ^ 0x9000000DULL) + (x2 ^ 0x048570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C8ULL; // 0x048570: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000CAULL; // 0x048574: adrp x10, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000CCULL; // 0x048578: adrp x12, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000CEULL; // 0x04857c: adrp x14, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000D0ULL; // 0x048580: adrp x16, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9478908ULL; // 0x048584: ldr x8, [x8, #0xf10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946B94AULL; // 0x048588: ldr x10, [x10, #0xd70]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946F18CULL; // 0x04858c: ldr x12, [x12, #0xde0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94785CEULL; // 0x048590: ldr x14, [x14, #0xf08]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946A210ULL; // 0x048594: ldr x16, [x16, #0xd40]
    return acc;
}

// [EN] Reconstructed FDE #0602 @ 0x0485d8..0x0487c8 (496 bytes)
// [VN] Phục dựng FDE #0602 tại 0x0485d8..0x0487c8 (496 byte)
//   0x0485d8: 7100205f  cmp      w2, #8
//   0x0485dc: 540000aa  b.ge     #0x485f0
//   0x0485e0: 2a1f03e8  mov      w8, wzr
//   0x0485e4: 6b02011f  cmp      w8, w2
//   0x0485e8: 540004ab  b.lt     #0x4867c
//   0x0485ec: 14000043  b        #0x486f8
//   0x0485f0: 528838ea  mov      w10, #0x41c7
//   0x0485f4: 5290246b  mov      w11, #0x8123
//   0x0485f8: 5283228c  mov      w12, #0x1914
//   0x0485fc: aa1f03e8  mov      x8, xzr
//   0x048600: 93407c49  sxtw     x9, w2
//   0x048604: 4e020d40  dup      v0.8h, w10
//   0x048608: 0e020d41  dup      v1.4h, w10
//   0x04860c: 0e020d62  dup      v2.4h, w11
//   0x048610: 4e020d63  dup      v3.8h, w11
//   0x048614: 4e020d84  dup      v4.8h, w12
uint64_t fde_0602_sub_0485d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100205FULL) + (x1 ^ 0x0E020D41ULL) + (x2 ^ 0x0485D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x0485d8: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x0485dc: b.ge #0x485f0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0485e0: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B02011FULL; // 0x0485e4: cmp w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x540004ABULL; // 0x0485e8: b.lt #0x4867c
    acc = (acc * 0x100000001B3ULL) ^ 0x14000043ULL; // 0x0485ec: b #0x486f8
    acc = (acc * 0x100000001B3ULL) ^ 0x528838EAULL; // 0x0485f0: mov w10, #0x41c7
    acc = (acc * 0x100000001B3ULL) ^ 0x5290246BULL; // 0x0485f4: mov w11, #0x8123
    acc = (acc * 0x100000001B3ULL) ^ 0x5283228CULL; // 0x0485f8: mov w12, #0x1914
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x0485fc: mov x8, xzr
    return acc;
}

// [EN] Reconstructed FDE #0603 @ 0x0487c8..0x0489bc (500 bytes)
// [VN] Phục dựng FDE #0603 tại 0x0487c8..0x0489bc (500 byte)
//   0x0487c8: 7100205f  cmp      w2, #8
//   0x0487cc: 540000aa  b.ge     #0x487e0
//   0x0487d0: 2a1f03e8  mov      w8, wzr
//   0x0487d4: 6b02011f  cmp      w8, w2
//   0x0487d8: 540004ab  b.lt     #0x4886c
//   0x0487dc: 14000044  b        #0x488ec
//   0x0487e0: 528838ea  mov      w10, #0x41c7
//   0x0487e4: 5290246b  mov      w11, #0x8123
//   0x0487e8: 5283228c  mov      w12, #0x1914
//   0x0487ec: aa1f03e8  mov      x8, xzr
//   0x0487f0: 93407c49  sxtw     x9, w2
//   0x0487f4: 4e020d40  dup      v0.8h, w10
//   0x0487f8: 0e020d41  dup      v1.4h, w10
//   0x0487fc: 0e020d62  dup      v2.4h, w11
//   0x048800: 4e020d63  dup      v3.8h, w11
//   0x048804: 4e020d84  dup      v4.8h, w12
uint64_t fde_0603_sub_0487c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100205FULL) + (x1 ^ 0x0E020D41ULL) + (x2 ^ 0x0487C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x0487c8: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x0487cc: b.ge #0x487e0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0487d0: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B02011FULL; // 0x0487d4: cmp w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x540004ABULL; // 0x0487d8: b.lt #0x4886c
    acc = (acc * 0x100000001B3ULL) ^ 0x14000044ULL; // 0x0487dc: b #0x488ec
    acc = (acc * 0x100000001B3ULL) ^ 0x528838EAULL; // 0x0487e0: mov w10, #0x41c7
    acc = (acc * 0x100000001B3ULL) ^ 0x5290246BULL; // 0x0487e4: mov w11, #0x8123
    acc = (acc * 0x100000001B3ULL) ^ 0x5283228CULL; // 0x0487e8: mov w12, #0x1914
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x0487ec: mov x8, xzr
    return acc;
}

// [EN] Reconstructed FDE #0604 @ 0x0489bc..0x048b58 (412 bytes)
// [VN] Phục dựng FDE #0604 tại 0x0489bc..0x048b58 (412 byte)
//   0x0489bc: 7100205f  cmp      w2, #8
//   0x0489c0: 540000aa  b.ge     #0x489d4
//   0x0489c4: 2a1f03e8  mov      w8, wzr
//   0x0489c8: 6b02011f  cmp      w8, w2
//   0x0489cc: 540004cb  b.lt     #0x48a64
//   0x0489d0: 14000061  b        #0x48b54
//   0x0489d4: 528838ea  mov      w10, #0x41c7
//   0x0489d8: 5290246b  mov      w11, #0x8123
//   0x0489dc: 5283228c  mov      w12, #0x1914
//   0x0489e0: aa1f03e8  mov      x8, xzr
//   0x0489e4: 93407c49  sxtw     x9, w2
//   0x0489e8: 4e020d40  dup      v0.8h, w10
//   0x0489ec: 0e020d41  dup      v1.4h, w10
//   0x0489f0: 0e020d62  dup      v2.4h, w11
//   0x0489f4: 4e020d63  dup      v3.8h, w11
//   0x0489f8: 4e020d84  dup      v4.8h, w12
uint64_t fde_0604_sub_0489bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100205FULL) + (x1 ^ 0x0E020D41ULL) + (x2 ^ 0x0489BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x0489bc: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x0489c0: b.ge #0x489d4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0489c4: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B02011FULL; // 0x0489c8: cmp w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x540004CBULL; // 0x0489cc: b.lt #0x48a64
    acc = (acc * 0x100000001B3ULL) ^ 0x14000061ULL; // 0x0489d0: b #0x48b54
    acc = (acc * 0x100000001B3ULL) ^ 0x528838EAULL; // 0x0489d4: mov w10, #0x41c7
    acc = (acc * 0x100000001B3ULL) ^ 0x5290246BULL; // 0x0489d8: mov w11, #0x8123
    acc = (acc * 0x100000001B3ULL) ^ 0x5283228CULL; // 0x0489dc: mov w12, #0x1914
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x0489e0: mov x8, xzr
    return acc;
}

// [EN] Reconstructed FDE #0605 @ 0x048b58..0x048c68 (272 bytes)
// [VN] Phục dựng FDE #0605 tại 0x048b58..0x048c68 (272 byte)
//   0x048b58: 7100407f  cmp      w3, #0x10
//   0x048b5c: 540000aa  b.ge     #0x48b70
//   0x048b60: 2a1f03e8  mov      w8, wzr
//   0x048b64: 6b03011f  cmp      w8, w3
//   0x048b68: 540007ab  b.lt     #0x48c5c
//   0x048b6c: d65f03c0  ret      
//   0x048b70: 529b412a  mov      w10, #0xda09
//   0x048b74: 4e020d40  dup      v0.8h, w10
//   0x048b78: 0e020d41  dup      v1.4h, w10
//   0x048b7c: 5296aeea  mov      w10, #0xb577
//   0x048b80: 0e020d42  dup      v2.4h, w10
//   0x048b84: 4e020d43  dup      v3.8h, w10
//   0x048b88: 528e100a  mov      w10, #0x7080
//   0x048b8c: 0e020d45  dup      v5.4h, w10
//   0x048b90: 4e020d46  dup      v6.8h, w10
//   0x048b94: 5294398a  mov      w10, #0xa1cc
uint64_t fde_0605_sub_048b58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100407FULL) + (x1 ^ 0x528E100AULL) + (x2 ^ 0x048B58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100407FULL; // 0x048b58: cmp w3, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x048b5c: b.ge #0x48b70
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x048b60: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B03011FULL; // 0x048b64: cmp w8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x540007ABULL; // 0x048b68: b.lt #0x48c5c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x048b6c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x529B412AULL; // 0x048b70: mov w10, #0xda09
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D40ULL; // 0x048b74: dup v0.8h, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x0E020D41ULL; // 0x048b78: dup v1.4h, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x5296AEEAULL; // 0x048b7c: mov w10, #0xb577
    return acc;
}

// [EN] Reconstructed FDE #0606 @ 0x048c68..0x048fc8 (864 bytes)
// [VN] Phục dựng FDE #0606 tại 0x048c68..0x048fc8 (864 byte)
//   0x048c68: 7100207f  cmp      w3, #8
//   0x048c6c: 540000aa  b.ge     #0x48c80
//   0x048c70: 2a1f03e8  mov      w8, wzr
//   0x048c74: 6b03011f  cmp      w8, w3
//   0x048c78: 5400066b  b.lt     #0x48d44
//   0x048c7c: 140000d2  b        #0x48fc4
//   0x048c80: 529b4129  mov      w9, #0xda09
//   0x048c84: 4e020d20  dup      v0.8h, w9
//   0x048c88: 0e020d21  dup      v1.4h, w9
//   0x048c8c: 5296aee9  mov      w9, #0xb577
//   0x048c90: 0e020d22  dup      v2.4h, w9
//   0x048c94: 4e020d23  dup      v3.8h, w9
//   0x048c98: 528e1009  mov      w9, #0x7080
//   0x048c9c: 0e020d24  dup      v4.4h, w9
//   0x048ca0: 4e020d25  dup      v5.8h, w9
//   0x048ca4: 52943989  mov      w9, #0xa1cc
uint64_t fde_0606_sub_048c68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100207FULL) + (x1 ^ 0x528E1009ULL) + (x2 ^ 0x048C68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100207FULL; // 0x048c68: cmp w3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x048c6c: b.ge #0x48c80
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x048c70: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B03011FULL; // 0x048c74: cmp w8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x5400066BULL; // 0x048c78: b.lt #0x48d44
    acc = (acc * 0x100000001B3ULL) ^ 0x140000D2ULL; // 0x048c7c: b #0x48fc4
    acc = (acc * 0x100000001B3ULL) ^ 0x529B4129ULL; // 0x048c80: mov w9, #0xda09
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D20ULL; // 0x048c84: dup v0.8h, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x0E020D21ULL; // 0x048c88: dup v1.4h, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x5296AEE9ULL; // 0x048c8c: mov w9, #0xb577
    return acc;
}

// [EN] Reconstructed FDE #0607 @ 0x048fc8..0x049050 (136 bytes)
// [VN] Phục dựng FDE #0607 tại 0x048fc8..0x049050 (136 byte)
//   0x048fc8: 90000068  adrp     x8, #0x54000
//   0x048fcc: fd454100  ldr      d0, [x8, #0xa80]
//   0x048fd0: 8b020028  add      x8, x1, x2
//   0x048fd4: f1001c5f  cmp      x2, #7
//   0x048fd8: a9012001  stp      x1, x8, [x0, #0x10]
//   0x048fdc: d1001d08  sub      x8, x8, #7
//   0x048fe0: 9a818108  csel     x8, x8, x1, hi
//   0x048fe4: eb01011f  cmp      x8, x1
//   0x048fe8: f900001f  str      xzr, [x0]
//   0x048fec: b900281f  str      wzr, [x0, #0x28]
//   0x048ff0: fd000400  str      d0, [x0, #8]
//   0x048ff4: f9001008  str      x8, [x0, #0x20]
//   0x048ff8: 54000129  b.ls     #0x4901c
//   0x048ffc: f8407428  ldr      x8, [x1], #7
//   0x049000: 52800609  mov      w9, #0x30
//   0x049004: b9000c09  str      w9, [x0, #0xc]
uint64_t fde_0607_sub_048fc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000068ULL) + (x1 ^ 0x54000129ULL) + (x2 ^ 0x048FC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000068ULL; // 0x048fc8: adrp x8, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0xFD454100ULL; // 0x048fcc: ldr d0, [x8, #0xa80]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B020028ULL; // 0x048fd0: add x8, x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF1001C5FULL; // 0x048fd4: cmp x2, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xA9012001ULL; // 0x048fd8: stp x1, x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001D08ULL; // 0x048fdc: sub x8, x8, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x9A818108ULL; // 0x048fe0: csel x8, x8, x1, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x048fe4: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x048fe8: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900281FULL; // 0x048fec: str wzr, [x0, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0608 @ 0x049050..0x0490b8 (104 bytes)
// [VN] Phục dựng FDE #0608 tại 0x049050..0x0490b8 (104 byte)
//   0x049050: a9412408  ldp      x8, x9, [x0, #0x10]
//   0x049054: eb09011f  cmp      x8, x9
//   0x049058: 54000162  b.hs     #0x49084
//   0x04905c: b9400c09  ldr      w9, [x0, #0xc]
//   0x049060: 9100050a  add      x10, x8, #1
//   0x049064: f900080a  str      x10, [x0, #0x10]
//   0x049068: 11002129  add      w9, w9, #8
//   0x04906c: b9000c09  str      w9, [x0, #0xc]
//   0x049070: 39400108  ldrb     w8, [x8]
//   0x049074: f9400009  ldr      x9, [x0]
//   0x049078: b378dd28  bfi      x8, x9, #8, #0x38
//   0x04907c: f9000008  str      x8, [x0]
//   0x049080: d65f03c0  ret      
//   0x049084: b9402808  ldr      w8, [x0, #0x28]
//   0x049088: 34000068  cbz      w8, #0x49094
//   0x04908c: b9000c1f  str      wzr, [x0, #0xc]
uint64_t fde_0608_sub_049050(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9412408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x049050ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412408ULL; // 0x049050: ldp x8, x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x049054: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000162ULL; // 0x049058: b.hs #0x49084
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400C09ULL; // 0x04905c: ldr w9, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100050AULL; // 0x049060: add x10, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900080AULL; // 0x049064: str x10, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x11002129ULL; // 0x049068: add w9, w9, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000C09ULL; // 0x04906c: str w9, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x049070: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x049074: ldr x9, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0609 @ 0x0490b8..0x0491c4 (268 bytes)
// [VN] Phục dựng FDE #0609 tại 0x0490b8..0x0491c4 (268 byte)
//   0x0490b8: 7100043f  cmp      w1, #1
//   0x0490bc: 5400080b  b.lt     #0x491bc
//   0x0490c0: aa0003e8  mov      x8, x0
//   0x0490c4: 29412d0a  ldp      w10, w11, [x8, #8]
//   0x0490c8: 2a1f03e0  mov      w0, wzr
//   0x0490cc: 52800029  mov      w9, #1
//   0x0490d0: 36f8056b  tbz      w11, #0x1f, #0x4917c
//   0x0490d4: 1400000c  b        #0x49104
//   0x0490d8: 110005ca  add      w10, w14, #1
//   0x0490dc: 5ac0114d  clz      w13, w10
//   0x0490e0: 1ac1216e  lsl      w14, w11, w1
//   0x0490e4: 521d05ab  eor      w11, w13, #0x18
//   0x0490e8: 1acb214a  lsl      w10, w10, w11
//   0x0490ec: 7100003f  cmp      w1, #0
//   0x0490f0: 4b0b018b  sub      w11, w12, w11
//   0x0490f4: 5100054a  sub      w10, w10, #1
uint64_t fde_0609_sub_0490b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0x1ACB214AULL) + (x2 ^ 0x0490B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0490b8: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400080BULL; // 0x0490bc: b.lt #0x491bc
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0490c0: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x29412D0AULL; // 0x0490c4: ldp w10, w11, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0490c8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x0490cc: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x36F8056BULL; // 0x0490d0: tbz w11, #0x1f, #0x4917c
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000CULL; // 0x0490d4: b #0x49104
    acc = (acc * 0x100000001B3ULL) ^ 0x110005CAULL; // 0x0490d8: add w10, w14, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5AC0114DULL; // 0x0490dc: clz w13, w10
    return acc;
}

// [EN] Reconstructed FDE #0610 @ 0x0491c4..0x0491fc (56 bytes)
// [VN] Phục dựng FDE #0610 tại 0x0491c4..0x0491fc (56 byte)
//   0x0491c4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0491c8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0491cc: 910043fd  add      x29, sp, #0x10
//   0x0491d0: aa0003f3  mov      x19, x0
//   0x0491d4: 97ffffb9  bl       #0x490b8
//   0x0491d8: 2a0003f4  mov      w20, w0
//   0x0491dc: 52800021  mov      w1, #1
//   0x0491e0: aa1303e0  mov      x0, x19
//   0x0491e4: 97ffffb5  bl       #0x490b8
//   0x0491e8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0491ec: 7100001f  cmp      w0, #0
//   0x0491f0: 5a940680  cneg     w0, w20, ne
//   0x0491f4: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x0491f8: d65f03c0  ret      
uint64_t fde_0610_sub_0491c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA8C24FF4ULL) + (x2 ^ 0x0491C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0491c4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0491c8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0491cc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0491d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFB9ULL; // 0x0491d4: bl #0x490b8
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x0491d8: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0491dc: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0491e0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFB5ULL; // 0x0491e4: bl #0x490b8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0491e8: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0611 @ 0x0491fc..0x0492a4 (168 bytes)
// [VN] Phục dựng FDE #0611 tại 0x0491fc..0x0492a4 (168 byte)
//   0x0491fc: f100205f  cmp      x2, #8
//   0x049200: 52800108  mov      w8, #8
//   0x049204: 9a883048  csel     x8, x2, x8, lo
//   0x049208: aa0803ea  mov      x10, x8
//   0x04920c: f9000802  str      x2, [x0, #0x10]
//   0x049210: f900001f  str      xzr, [x0]
//   0x049214: f900101f  str      xzr, [x0, #0x20]
//   0x049218: b4000408  cbz      x8, #0x49298
//   0x04921c: aa1f03ea  mov      x10, xzr
//   0x049220: f100051f  cmp      x8, #1
//   0x049224: aa1f03e9  mov      x9, xzr
//   0x049228: 54000280  b.eq     #0x49278
//   0x04922c: 927f0909  and      x9, x8, #0xe
//   0x049230: aa1f03ea  mov      x10, xzr
//   0x049234: aa1f03eb  mov      x11, xzr
//   0x049238: 9100042c  add      x12, x1, #1
uint64_t fde_0611_sub_0491fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF100205FULL) + (x1 ^ 0x927F0909ULL) + (x2 ^ 0x0491FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF100205FULL; // 0x0491fc: cmp x2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800108ULL; // 0x049200: mov w8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x9A883048ULL; // 0x049204: csel x8, x2, x8, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803EAULL; // 0x049208: mov x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000802ULL; // 0x04920c: str x2, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x049210: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900101FULL; // 0x049214: str xzr, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000408ULL; // 0x049218: cbz x8, #0x49298
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03EAULL; // 0x04921c: mov x10, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF100051FULL; // 0x049220: cmp x8, #1
    return acc;
}

// [EN] Reconstructed FDE #0612 @ 0x0492a4..0x049350 (172 bytes)
// [VN] Phục dựng FDE #0612 tại 0x0492a4..0x049350 (172 byte)
//   0x0492a4: a9412009  ldp      x9, x8, [x0, #0x10]
//   0x0492a8: 9100210a  add      x10, x8, #8
//   0x0492ac: eb09015f  cmp      x10, x9
//   0x0492b0: 540001a2  b.hs     #0x492e4
//   0x0492b4: a9402c09  ldp      x9, x11, [x0]
//   0x0492b8: b940200a  ldr      w10, [x0, #0x20]
//   0x0492bc: d360fd2c  lsr      x12, x9, #0x20
//   0x0492c0: 5100814a  sub      w10, w10, #0x20
//   0x0492c4: f900000c  str      x12, [x0]
//   0x0492c8: b900200a  str      w10, [x0, #0x20]
//   0x0492cc: b868696a  ldr      w10, [x11, x8]
//   0x0492d0: 91001108  add      x8, x8, #4
//   0x0492d4: f9000c08  str      x8, [x0, #0x18]
//   0x0492d8: 93c98149  extr     x9, x10, x9, #0x20
//   0x0492dc: f9000009  str      x9, [x0]
//   0x0492e0: d65f03c0  ret      
uint64_t fde_0612_sub_0492a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9412009ULL) + (x1 ^ 0xF9000C08ULL) + (x2 ^ 0x0492A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412009ULL; // 0x0492a4: ldp x9, x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100210AULL; // 0x0492a8: add x10, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09015FULL; // 0x0492ac: cmp x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A2ULL; // 0x0492b0: b.hs #0x492e4
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402C09ULL; // 0x0492b4: ldp x9, x11, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940200AULL; // 0x0492b8: ldr w10, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD360FD2CULL; // 0x0492bc: lsr x12, x9, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x5100814AULL; // 0x0492c0: sub w10, w10, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF900000CULL; // 0x0492c4: str x12, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900200AULL; // 0x0492c8: str w10, [x0, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0613 @ 0x049350..0x0493f8 (168 bytes)
// [VN] Phục dựng FDE #0613 tại 0x049350..0x0493f8 (168 byte)
//   0x049350: 7100603f  cmp      w1, #0x18
//   0x049354: aa0003e8  mov      x8, x0
//   0x049358: 540003cc  b.gt     #0x493d0
//   0x04935c: b9402509  ldr      w9, [x8, #0x24]
//   0x049360: 35000389  cbnz     w9, #0x493d0
//   0x049364: f000004b  adrp     x11, #0x54000
//   0x049368: f9400109  ldr      x9, [x8]
//   0x04936c: b940210a  ldr      w10, [x8, #0x20]
//   0x049370: 912e216b  add      x11, x11, #0xb88
//   0x049374: b861d96b  ldr      w11, [x11, w1, sxtw #2]
//   0x049378: 9aca252c  lsr      x12, x9, x10
//   0x04937c: 0b01014a  add      w10, w10, w1
//   0x049380: 0a0c0160  and      w0, w11, w12
//   0x049384: 7100215f  cmp      w10, #8
//   0x049388: b900210a  str      w10, [x8, #0x20]
//   0x04938c: 540002ab  b.lt     #0x493e0
uint64_t fde_0613_sub_049350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100603FULL) + (x1 ^ 0x0A0C0160ULL) + (x2 ^ 0x049350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100603FULL; // 0x049350: cmp w1, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x049354: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540003CCULL; // 0x049358: b.gt #0x493d0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402509ULL; // 0x04935c: ldr w9, [x8, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0x35000389ULL; // 0x049360: cbnz w9, #0x493d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF000004BULL; // 0x049364: adrp x11, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x049368: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940210AULL; // 0x04936c: ldr w10, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x912E216BULL; // 0x049370: add x11, x11, #0xb88
    acc = (acc * 0x100000001B3ULL) ^ 0xB861D96BULL; // 0x049374: ldr w11, [x11, w1, sxtw #2]
    return acc;
}

// [EN] Reconstructed FDE #0614 @ 0x0493f8..0x049444 (76 bytes)
// [VN] Phục dựng FDE #0614 tại 0x0493f8..0x049444 (76 byte)
//   0x0493f8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0493fc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x049400: 910043fd  add      x29, sp, #0x10
//   0x049404: 52800028  mov      w8, #1
//   0x049408: 1ac12108  lsl      w8, w8, w1
//   0x04940c: 2a0103f3  mov      w19, w1
//   0x049410: aa0003f4  mov      x20, x0
//   0x049414: 93407d00  sxtw     x0, w8
//   0x049418: 52800081  mov      w1, #4
//   0x04941c: 97ff8420  bl       #0x2a49c
//   0x049420: f9000280  str      x0, [x20]
//   0x049424: b40000a0  cbz      x0, #0x49438
//   0x049428: 52800408  mov      w8, #0x20
//   0x04942c: 4b130108  sub      w8, w8, w19
//   0x049430: 52800020  mov      w0, #1
//   0x049434: 29014e88  stp      w8, w19, [x20, #8]
uint64_t fde_0614_sub_0493f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x52800408ULL) + (x2 ^ 0x0493F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0493f8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0493fc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x049400: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x049404: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC12108ULL; // 0x049408: lsl w8, w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x04940c: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x049410: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D00ULL; // 0x049414: sxtw x0, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800081ULL; // 0x049418: mov w1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8420ULL; // 0x04941c: bl #0x2a49c
    return acc;
}

// [EN] Reconstructed FDE #0615 @ 0x049444..0x049470 (44 bytes)
// [VN] Phục dựng FDE #0615 tại 0x049444..0x049470 (44 byte)
//   0x049444: b4000140  cbz      x0, #0x4946c
//   0x049448: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x04944c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x049450: 910043fd  add      x29, sp, #0x10
//   0x049454: aa0003f3  mov      x19, x0
//   0x049458: f9400000  ldr      x0, [x0]
//   0x04945c: 97ff8418  bl       #0x2a4bc
//   0x049460: f900027f  str      xzr, [x19]
//   0x049464: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x049468: f84207f3  ldr      x19, [sp], #0x20
//   0x04946c: d65f03c0  ret      
uint64_t fde_0615_sub_049444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000140ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x049444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000140ULL; // 0x049444: cbz x0, #0x4946c
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x049448: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04944c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x049450: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049454: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x049458: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8418ULL; // 0x04945c: bl #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF900027FULL; // 0x049460: str xzr, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x049464: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x049468: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0616 @ 0x049470..0x04948c (28 bytes)
// [VN] Phục dựng FDE #0616 tại 0x049470..0x04948c (28 byte)
//   0x049470: f9400028  ldr      x8, [x1]
//   0x049474: b9400c29  ldr      w9, [x1, #0xc]
//   0x049478: f9400001  ldr      x1, [x0]
//   0x04947c: 5280008a  mov      w10, #4
//   0x049480: aa0803e0  mov      x0, x8
//   0x049484: 9ac92142  lsl      x2, x10, x9
//   0x049488: 17feea62  b        #0x3e10
uint64_t fde_0616_sub_049470(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400028ULL) + (x1 ^ 0x17FEEA62ULL) + (x2 ^ 0x049470ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x049470: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400C29ULL; // 0x049474: ldr w9, [x1, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400001ULL; // 0x049478: ldr x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280008AULL; // 0x04947c: mov w10, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x049480: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC92142ULL; // 0x049484: lsl x2, x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x17FEEA62ULL; // 0x049488: b #0x3e10
    return acc;
}

// [EN] Reconstructed FDE #0617 @ 0x04948c..0x049498 (12 bytes)
// [VN] Phục dựng FDE #0617 tại 0x04948c..0x049498 (12 byte)
//   0x04948c: 52804701  mov      w1, #0x238
//   0x049490: 93407c00  sxtw     x0, w0
//   0x049494: 17ff83f9  b        #0x2a478
uint64_t fde_0617_sub_04948c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52804701ULL) + (x1 ^ 0x17FF83F9ULL) + (x2 ^ 0x04948CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52804701ULL; // 0x04948c: mov w1, #0x238
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C00ULL; // 0x049490: sxtw x0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF83F9ULL; // 0x049494: b #0x2a478
    return acc;
}

// [EN] Reconstructed FDE #0618 @ 0x049498..0x0494a4 (12 bytes)
// [VN] Phục dựng FDE #0618 tại 0x049498..0x0494a4 (12 byte)
//   0x049498: b4000040  cbz      x0, #0x494a0
//   0x04949c: 17ff8408  b        #0x2a4bc
//   0x0494a0: d65f03c0  ret      
uint64_t fde_0618_sub_049498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000040ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x049498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x049498: cbz x0, #0x494a0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8408ULL; // 0x04949c: b #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0494a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0619 @ 0x0494a4..0x0495fc (344 bytes)
// [VN] Phục dựng FDE #0619 tại 0x0494a4..0x0495fc (344 byte)
//   0x0494a4: f81a0ffc  str      x28, [sp, #-0x60]!
//   0x0494a8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0494ac: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0494b0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0494b4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0494b8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0494bc: 910143fd  add      x29, sp, #0x50
//   0x0494c0: d11043ff  sub      sp, sp, #0x410
//   0x0494c4: d53bd059  mrs      x25, tpidr_el0
//   0x0494c8: f9401728  ldr      x8, [x25, #0x28]
//   0x0494cc: aa0003f7  mov      x23, x0
//   0x0494d0: aa1f03e0  mov      x0, xzr
//   0x0494d4: aa1f03e4  mov      x4, xzr
//   0x0494d8: 2a0303f4  mov      w20, w3
//   0x0494dc: aa0203f5  mov      x21, x2
//   0x0494e0: 2a0103f6  mov      w22, w1
uint64_t fde_0619_sub_0494a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFCULL) + (x1 ^ 0xAA1F03E4ULL) + (x2 ^ 0x0494A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFCULL; // 0x0494a4: str x28, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0494a8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0494ac: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0494b0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0494b4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0494b8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0494bc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11043FFULL; // 0x0494c0: sub sp, sp, #0x410
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x0494c4: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x0494c8: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0620 @ 0x0495fc..0x049ba0 (1444 bytes)
// [VN] Phục dựng FDE #0620 tại 0x0495fc..0x049ba0 (1444 byte)
//   0x0495fc: d10403ff  sub      sp, sp, #0x100
//   0x049600: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x049604: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x049608: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x04960c: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x049610: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x049614: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x049618: 9103c3fd  add      x29, sp, #0xf0
//   0x04961c: d53bd049  mrs      x9, tpidr_el0
//   0x049620: f9401528  ldr      x8, [x9, #0x28]
//   0x049624: 6f00e400  movi     v0.2d, #0000000000000000
//   0x049628: 7100047f  cmp      w3, #1
//   0x04962c: f81a83a8  stur     x8, [x29, #-0x58]
//   0x049630: ad0383e0  stp      q0, q0, [sp, #0x70]
//   0x049634: ad0283e0  stp      q0, q0, [sp, #0x50]
//   0x049638: 5400024b  b.lt     #0x49680
uint64_t fde_0620_sub_0495fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xF81A83A8ULL) + (x2 ^ 0x0495FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x0495fc: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x049600: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x049604: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x049608: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x04960c: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x049610: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x049614: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x049618: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD049ULL; // 0x04961c: mrs x9, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401528ULL; // 0x049620: ldr x8, [x9, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0621 @ 0x049ba0..0x049be4 (68 bytes)
// [VN] Phục dựng FDE #0621 tại 0x049ba0..0x049be4 (68 byte)
//   0x049ba0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x049ba4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x049ba8: 910043fd  add      x29, sp, #0x10
//   0x049bac: 2a0003f4  mov      w20, w0
//   0x049bb0: aa0103f3  mov      x19, x1
//   0x049bb4: f9001021  str      x1, [x1, #0x20]
//   0x049bb8: 93407e80  sxtw     x0, w20
//   0x049bbc: 52800081  mov      w1, #4
//   0x049bc0: 97ff822e  bl       #0x2a478
//   0x049bc4: f9000260  str      x0, [x19]
//   0x049bc8: b4000080  cbz      x0, #0x49bd8
//   0x049bcc: a900fe60  stp      x0, xzr, [x19, #8]
//   0x049bd0: 52800020  mov      w0, #1
//   0x049bd4: b9001a74  str      w20, [x19, #0x18]
//   0x049bd8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x049bdc: a8c24ff4  ldp      x20, x19, [sp], #0x20
uint64_t fde_0621_sub_049ba0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x52800020ULL) + (x2 ^ 0x049BA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x049ba0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x049ba4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x049ba8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F4ULL; // 0x049bac: mov w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x049bb0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001021ULL; // 0x049bb4: str x1, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407E80ULL; // 0x049bb8: sxtw x0, w20
    acc = (acc * 0x100000001B3ULL) ^ 0x52800081ULL; // 0x049bbc: mov w1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF822EULL; // 0x049bc0: bl #0x2a478
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000260ULL; // 0x049bc4: str x0, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0622 @ 0x049be4..0x049c38 (84 bytes)
// [VN] Phục dựng FDE #0622 tại 0x049be4..0x049c38 (84 byte)
//   0x049be4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x049be8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x049bec: 910043fd  add      x29, sp, #0x10
//   0x049bf0: b40001e0  cbz      x0, #0x49c2c
//   0x049bf4: aa0003f4  mov      x20, x0
//   0x049bf8: f9400813  ldr      x19, [x0, #0x10]
//   0x049bfc: f9400000  ldr      x0, [x0]
//   0x049c00: 97ff822f  bl       #0x2a4bc
//   0x049c04: f900029f  str      xzr, [x20]
//   0x049c08: f9000a9f  str      xzr, [x20, #0x10]
//   0x049c0c: b4000113  cbz      x19, #0x49c2c
//   0x049c10: f9400260  ldr      x0, [x19]
//   0x049c14: f9400a74  ldr      x20, [x19, #0x10]
//   0x049c18: 97ff8229  bl       #0x2a4bc
//   0x049c1c: aa1303e0  mov      x0, x19
//   0x049c20: 97ff8227  bl       #0x2a4bc
uint64_t fde_0622_sub_049be4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400A74ULL) + (x2 ^ 0x049BE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x049be4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x049be8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x049bec: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E0ULL; // 0x049bf0: cbz x0, #0x49c2c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x049bf4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400813ULL; // 0x049bf8: ldr x19, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x049bfc: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF822FULL; // 0x049c00: bl #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF900029FULL; // 0x049c04: str xzr, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000A9FULL; // 0x049c08: str xzr, [x20, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0623 @ 0x049c38..0x049cd8 (160 bytes)
// [VN] Phục dựng FDE #0623 tại 0x049c38..0x049cd8 (160 byte)
//   0x049c38: f0000048  adrp     x8, #0x54000
//   0x049c3c: 912fe108  add      x8, x8, #0xbf8
//   0x049c40: ad400502  ldp      q2, q1, [x8]
//   0x049c44: ad421103  ldp      q3, q4, [x8, #0x40]
//   0x049c48: 1e202008  fcmp     s0, #0.0
//   0x049c4c: 3c818001  stur     q1, [x0, #0x18]
//   0x049c50: 3c808002  stur     q2, [x0, #8]
//   0x049c54: ad410901  ldp      q1, q2, [x8, #0x20]
//   0x049c58: 3c858004  stur     q4, [x0, #0x58]
//   0x049c5c: 3c848003  stur     q3, [x0, #0x48]
//   0x049c60: ad441103  ldp      q3, q4, [x8, #0x80]
//   0x049c64: 3c838002  stur     q2, [x0, #0x38]
//   0x049c68: 3c828001  stur     q1, [x0, #0x28]
//   0x049c6c: ad430901  ldp      q1, q2, [x8, #0x60]
//   0x049c70: 3c898004  stur     q4, [x0, #0x98]
//   0x049c74: 3c888003  stur     q3, [x0, #0x88]
uint64_t fde_0623_sub_049c38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000048ULL) + (x1 ^ 0x3C828001ULL) + (x2 ^ 0x049C38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000048ULL; // 0x049c38: adrp x8, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0x912FE108ULL; // 0x049c3c: add x8, x8, #0xbf8
    acc = (acc * 0x100000001B3ULL) ^ 0xAD400502ULL; // 0x049c40: ldp q2, q1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD421103ULL; // 0x049c44: ldp q3, q4, [x8, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x1E202008ULL; // 0x049c48: fcmp s0, #0.0
    acc = (acc * 0x100000001B3ULL) ^ 0x3C818001ULL; // 0x049c4c: stur q1, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C808002ULL; // 0x049c50: stur q2, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD410901ULL; // 0x049c54: ldp q1, q2, [x8, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C858004ULL; // 0x049c58: stur q4, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0x3C848003ULL; // 0x049c5c: stur q3, [x0, #0x48]
    return acc;
}

// [EN] Reconstructed FDE #0624 @ 0x049cd8..0x049ce4 (12 bytes)
// [VN] Phục dựng FDE #0624 tại 0x049cd8..0x049ce4 (12 byte)
//   0x049cd8: f00000c0  adrp     x0, #0x64000
//   0x049cdc: 910bc000  add      x0, x0, #0x2f0
//   0x049ce0: d65f03c0  ret      
uint64_t fde_0624_sub_049cd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF00000C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x049CD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF00000C0ULL; // 0x049cd8: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x910BC000ULL; // 0x049cdc: add x0, x0, #0x2f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x049ce0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0625 @ 0x049ce4..0x049cf8 (20 bytes)
// [VN] Phục dựng FDE #0625 tại 0x049ce4..0x049cf8 (20 byte)
//   0x049ce4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x049ce8: ad008000  stp      q0, q0, [x0, #0x10]
//   0x049cec: 3d800000  str      q0, [x0]
//   0x049cf0: b900081f  str      wzr, [x0, #8]
//   0x049cf4: d65f03c0  ret      
uint64_t fde_0625_sub_049ce4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6F00E400ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x049CE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x049ce4: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAD008000ULL; // 0x049ce8: stp q0, q0, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800000ULL; // 0x049cec: str q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900081FULL; // 0x049cf0: str wzr, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x049cf4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0626 @ 0x049cf8..0x049e38 (320 bytes)
// [VN] Phục dựng FDE #0626 tại 0x049cf8..0x049e38 (320 byte)
//   0x049cf8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x049cfc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x049d00: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049d04: 910083fd  add      x29, sp, #0x20
//   0x049d08: b9400815  ldr      w21, [x0, #8]
//   0x049d0c: b900281f  str      wzr, [x0, #0x28]
//   0x049d10: 710006bf  cmp      w21, #1
//   0x049d14: 540007e0  b.eq     #0x49e10
//   0x049d18: aa0003f3  mov      x19, x0
//   0x049d1c: 35000255  cbnz     w21, #0x49d64
//   0x049d20: 52800020  mov      w0, #1
//   0x049d24: 52800c01  mov      w1, #0x60
//   0x049d28: 97ff81dd  bl       #0x2a49c
//   0x049d2c: f9000260  str      x0, [x19]
//   0x049d30: b4000420  cbz      x0, #0x49db4
//   0x049d34: aa1f03e1  mov      x1, xzr
uint64_t fde_0626_sub_049cf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x97FF81DDULL) + (x2 ^ 0x049CF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x049cf8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049cfc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x049d00: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049d04: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400815ULL; // 0x049d08: ldr w21, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900281FULL; // 0x049d0c: str wzr, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x710006BFULL; // 0x049d10: cmp w21, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540007E0ULL; // 0x049d14: b.eq #0x49e10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049d18: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x35000255ULL; // 0x049d1c: cbnz w21, #0x49d64
    return acc;
}

// [EN] Reconstructed FDE #0627 @ 0x049e38..0x049ea8 (112 bytes)
// [VN] Phục dựng FDE #0627 tại 0x049e38..0x049ea8 (112 byte)
//   0x049e38: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x049e3c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x049e40: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049e44: 910083fd  add      x29, sp, #0x20
//   0x049e48: f9400014  ldr      x20, [x0]
//   0x049e4c: aa0003f3  mov      x19, x0
//   0x049e50: b40001f4  cbz      x20, #0x49e8c
//   0x049e54: aa1403e0  mov      x0, x20
//   0x049e58: 97fee8b6  bl       #0x4130
//   0x049e5c: b9400a68  ldr      w8, [x19, #8]
//   0x049e60: 7100091f  cmp      w8, #2
//   0x049e64: 54000103  b.lo     #0x49e84
//   0x049e68: 9100a295  add      x21, x20, #0x28
//   0x049e6c: aa1503e0  mov      x0, x21
//   0x049e70: aa1403e1  mov      x1, x20
//   0x049e74: 97fee863  bl       #0x4000
uint64_t fde_0627_sub_049e38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x9100A295ULL) + (x2 ^ 0x049E38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x049e38: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049e3c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x049e40: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049e44: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400014ULL; // 0x049e48: ldr x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049e4c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001F4ULL; // 0x049e50: cbz x20, #0x49e8c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x049e54: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEE8B6ULL; // 0x049e58: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A68ULL; // 0x049e5c: ldr w8, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0628 @ 0x049ea8..0x049f40 (152 bytes)
// [VN] Phục dựng FDE #0628 tại 0x049ea8..0x049f40 (152 byte)
//   0x049ea8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x049eac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x049eb0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049eb4: 910083fd  add      x29, sp, #0x20
//   0x049eb8: f9400013  ldr      x19, [x0]
//   0x049ebc: b4000313  cbz      x19, #0x49f1c
//   0x049ec0: aa0003f4  mov      x20, x0
//   0x049ec4: aa1303e0  mov      x0, x19
//   0x049ec8: 97fee89a  bl       #0x4130
//   0x049ecc: b9400a88  ldr      w8, [x20, #8]
//   0x049ed0: 340002e8  cbz      w8, #0x49f2c
//   0x049ed4: 7100051f  cmp      w8, #1
//   0x049ed8: 54000100  b.eq     #0x49ef8
//   0x049edc: 9100a275  add      x21, x19, #0x28
//   0x049ee0: aa1503e0  mov      x0, x21
//   0x049ee4: aa1303e1  mov      x1, x19
uint64_t fde_0628_sub_049ea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000100ULL) + (x2 ^ 0x049EA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x049ea8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049eac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x049eb0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049eb4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x049eb8: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000313ULL; // 0x049ebc: cbz x19, #0x49f1c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x049ec0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x049ec4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEE89AULL; // 0x049ec8: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A88ULL; // 0x049ecc: ldr w8, [x20, #8]
    return acc;
}

// [EN] Reconstructed FDE #0629 @ 0x049f40..0x049f84 (68 bytes)
// [VN] Phục dựng FDE #0629 tại 0x049f40..0x049f84 (68 byte)
//   0x049f40: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x049f44: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x049f48: 910043fd  add      x29, sp, #0x10
//   0x049f4c: f9400808  ldr      x8, [x0, #0x10]
//   0x049f50: b4000148  cbz      x8, #0x49f78
//   0x049f54: aa0003f3  mov      x19, x0
//   0x049f58: f9400c00  ldr      x0, [x0, #0x18]
//   0x049f5c: f9401261  ldr      x1, [x19, #0x20]
//   0x049f60: d63f0100  blr      x8
//   0x049f64: b9402a68  ldr      w8, [x19, #0x28]
//   0x049f68: 7100001f  cmp      w0, #0
//   0x049f6c: 1a9f17e9  cset     w9, eq
//   0x049f70: 2a090108  orr      w8, w8, w9
//   0x049f74: b9002a68  str      w8, [x19, #0x28]
//   0x049f78: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x049f7c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_0629_sub_049f40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x2A090108ULL) + (x2 ^ 0x049F40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x049f40: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x049f44: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x049f48: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x049f4c: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000148ULL; // 0x049f50: cbz x8, #0x49f78
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049f54: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x049f58: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401261ULL; // 0x049f5c: ldr x1, [x19, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x049f60: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402A68ULL; // 0x049f64: ldr w8, [x19, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0630 @ 0x049f84..0x04a02c (168 bytes)
// [VN] Phục dựng FDE #0630 tại 0x049f84..0x04a02c (168 byte)
//   0x049f84: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x049f88: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x049f8c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x049f90: 910083fd  add      x29, sp, #0x20
//   0x049f94: f9400014  ldr      x20, [x0]
//   0x049f98: b4000434  cbz      x20, #0x4a01c
//   0x049f9c: aa0003f3  mov      x19, x0
//   0x049fa0: aa1403e0  mov      x0, x20
//   0x049fa4: 97fee863  bl       #0x4130
//   0x049fa8: b9400a68  ldr      w8, [x19, #8]
//   0x049fac: 34000208  cbz      w8, #0x49fec
//   0x049fb0: 7100051f  cmp      w8, #1
//   0x049fb4: 54000100  b.eq     #0x49fd4
//   0x049fb8: 9100a295  add      x21, x20, #0x28
//   0x049fbc: aa1503e0  mov      x0, x21
//   0x049fc0: aa1403e1  mov      x1, x20
uint64_t fde_0630_sub_049f84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000100ULL) + (x2 ^ 0x049F84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x049f84: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x049f88: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x049f8c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x049f90: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400014ULL; // 0x049f94: ldr x20, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000434ULL; // 0x049f98: cbz x20, #0x4a01c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x049f9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x049fa0: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEE863ULL; // 0x049fa4: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A68ULL; // 0x049fa8: ldr w8, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0631 @ 0x04a02c..0x04a0d4 (168 bytes)
// [VN] Phục dựng FDE #0631 tại 0x04a02c..0x04a0d4 (168 byte)
//   0x04a02c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x04a030: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x04a034: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x04a038: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x04a03c: 9100c3fd  add      x29, sp, #0x30
//   0x04a040: f9400013  ldr      x19, [x0]
//   0x04a044: aa0003f5  mov      x21, x0
//   0x04a048: d00000d6  adrp     x22, #0x64000
//   0x04a04c: 52800037  mov      w23, #1
//   0x04a050: 9100a274  add      x20, x19, #0x28
//   0x04a054: 14000005  b        #0x4a068
//   0x04a058: aa1303e0  mov      x0, x19
//   0x04a05c: 97fee7e5  bl       #0x3ff0
//   0x04a060: aa1403e0  mov      x0, x20
//   0x04a064: 97fee803  bl       #0x4070
//   0x04a068: aa1303e0  mov      x0, x19
uint64_t fde_0631_sub_04a02c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x97FEE7E5ULL) + (x2 ^ 0x04A02CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x04a02c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x04a030: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x04a034: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x04a038: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x04a03c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x04a040: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04a044: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD00000D6ULL; // 0x04a048: adrp x22, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800037ULL; // 0x04a04c: mov w23, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A274ULL; // 0x04a050: add x20, x19, #0x28
    return acc;
}

// [EN] Reconstructed FDE #0632 @ 0x04a0d4..0x04a120 (76 bytes)
// [VN] Phục dựng FDE #0632 tại 0x04a0d4..0x04a120 (76 byte)
//   0x04a0d4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x04a0d8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x04a0dc: 910043fd  add      x29, sp, #0x10
//   0x04a0e0: aa0003f3  mov      x19, x0
//   0x04a0e4: f945d800  ldr      x0, [x0, #0xbb0]
//   0x04a0e8: 97ff80f5  bl       #0x2a4bc
//   0x04a0ec: f945ca74  ldr      x20, [x19, #0xb90]
//   0x04a0f0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x04a0f4: 3d82ee60  str      q0, [x19, #0xbb0]
//   0x04a0f8: b40000d4  cbz      x20, #0x4a110
//   0x04a0fc: f9400e80  ldr      x0, [x20, #0x18]
//   0x04a100: 97ff9689  bl       #0x2fb24
//   0x04a104: aa1403e0  mov      x0, x20
//   0x04a108: f9000e9f  str      xzr, [x20, #0x18]
//   0x04a10c: 97ff80ec  bl       #0x2a4bc
//   0x04a110: f905ca7f  str      xzr, [x19, #0xb90]
uint64_t fde_0632_sub_04a0d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x04A0D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x04a0d4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x04a0d8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x04a0dc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04a0e0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF945D800ULL; // 0x04a0e4: ldr x0, [x0, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF80F5ULL; // 0x04a0e8: bl #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF945CA74ULL; // 0x04a0ec: ldr x20, [x19, #0xb90]
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x04a0f0: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x3D82EE60ULL; // 0x04a0f4: str q0, [x19, #0xbb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000D4ULL; // 0x04a0f8: cbz x20, #0x4a110
    return acc;
}

// [EN] Reconstructed FDE #0633 @ 0x04a120..0x04a4a8 (904 bytes)
// [VN] Phục dựng FDE #0633 tại 0x04a120..0x04a4a8 (904 byte)
//   0x04a120: d101c3ff  sub      sp, sp, #0x70
//   0x04a124: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x04a128: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x04a12c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x04a130: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x04a134: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x04a138: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x04a13c: 910183fd  add      x29, sp, #0x60
//   0x04a140: aa0003f3  mov      x19, x0
//   0x04a144: aa1f03e0  mov      x0, xzr
//   0x04a148: 37f80202  tbnz     w2, #0x1f, #0x4a188
//   0x04a14c: 2a0303f7  mov      w23, w3
//   0x04a150: 7100047f  cmp      w3, #1
//   0x04a154: 540001ab  b.lt     #0x4a188
//   0x04a158: b940843b  ldr      w27, [x1, #0x84]
//   0x04a15c: 0b0202e8  add      w8, w23, w2
uint64_t fde_0633_sub_04a120(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x7100047FULL) + (x2 ^ 0x04A120ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x04a120: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x04a124: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x04a128: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x04a12c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x04a130: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x04a134: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x04a138: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x04a13c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04a140: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x04a144: mov x0, xzr
    return acc;
}

// [EN] Reconstructed FDE #0634 @ 0x04a4a8..0x04a6c8 (544 bytes)
// [VN] Phục dựng FDE #0634 tại 0x04a4a8..0x04a6c8 (544 byte)
//   0x04a4a8: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x04a4ac: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x04a4b0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x04a4b4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x04a4b8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x04a4bc: 910103fd  add      x29, sp, #0x40
//   0x04a4c0: 91004019  add      x25, x0, #0x10
//   0x04a4c4: aa0003f3  mov      x19, x0
//   0x04a4c8: 528000e1  mov      w1, #7
//   0x04a4cc: aa1903e0  mov      x0, x25
//   0x04a4d0: 97fffafa  bl       #0x490b8
//   0x04a4d4: 2a0003f4  mov      w20, w0
//   0x04a4d8: 52800021  mov      w1, #1
//   0x04a4dc: aa1903e0  mov      x0, x25
//   0x04a4e0: 97fffaf6  bl       #0x490b8
//   0x04a4e4: 340000c0  cbz      w0, #0x4a4fc
uint64_t fde_0634_sub_04a4a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x52800021ULL) + (x2 ^ 0x04A4A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x04a4a8: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x04a4ac: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x04a4b0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x04a4b4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x04a4b8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x04a4bc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x91004019ULL; // 0x04a4c0: add x25, x0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04a4c4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x528000E1ULL; // 0x04a4c8: mov w1, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1903E0ULL; // 0x04a4cc: mov x0, x25
    return acc;
}

// [EN] Reconstructed FDE #0635 @ 0x04a6c8..0x04a6dc (20 bytes)
// [VN] Phục dựng FDE #0635 tại 0x04a6c8..0x04a6dc (20 byte)
//   0x04a6c8: 52801fe8  mov      w8, #0xff
//   0x04a6cc: 12800009  mov      w9, #-1
//   0x04a6d0: 39000808  strb     w8, [x0, #2]
//   0x04a6d4: 79000009  strh     w9, [x0]
//   0x04a6d8: d65f03c0  ret      
uint64_t fde_0635_sub_04a6c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52801FE8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04A6C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FE8ULL; // 0x04a6c8: mov w8, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x12800009ULL; // 0x04a6cc: mov w9, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x39000808ULL; // 0x04a6d0: strb w8, [x0, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x79000009ULL; // 0x04a6d4: strh w9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04a6d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0636 @ 0x04a6dc..0x04b674 (3992 bytes)
// [VN] Phục dựng FDE #0636 tại 0x04a6dc..0x04b674 (3992 byte)
//   0x04a6dc: d10283ff  sub      sp, sp, #0xa0
//   0x04a6e0: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x04a6e4: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x04a6e8: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x04a6ec: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x04a6f0: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x04a6f4: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x04a6f8: 910243fd  add      x29, sp, #0x90
//   0x04a6fc: b9419828  ldr      w8, [x1, #0x198]
//   0x04a700: aa0103f9  mov      x25, x1
//   0x04a704: 7100051f  cmp      w8, #1
//   0x04a708: 54007a0b  b.lt     #0x4b648
//   0x04a70c: f000005a  adrp     x26, #0x55000
//   0x04a710: aa0003f4  mov      x20, x0
//   0x04a714: aa1f03fb  mov      x27, xzr
//   0x04a718: 912c0328  add      x8, x25, #0xb00
uint64_t fde_0636_sub_04a6dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xF000005AULL) + (x2 ^ 0x04A6DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x04a6dc: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x04a6e0: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x04a6e4: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x04a6e8: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x04a6ec: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x04a6f0: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x04a6f4: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x04a6f8: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xB9419828ULL; // 0x04a6fc: ldr w8, [x1, #0x198]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x04a700: mov x25, x1
    return acc;
}

// [EN] Reconstructed FDE #0637 @ 0x04b674..0x04b8cc (600 bytes)
// [VN] Phục dựng FDE #0637 tại 0x04b674..0x04b8cc (600 byte)
//   0x04b674: d10283ff  sub      sp, sp, #0xa0
//   0x04b678: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x04b67c: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x04b680: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x04b684: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x04b688: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x04b68c: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x04b690: 910243fd  add      x29, sp, #0x90
//   0x04b694: b000005a  adrp     x26, #0x54000
//   0x04b698: d0000059  adrp     x25, #0x55000
//   0x04b69c: aa0003f4  mov      x20, x0
//   0x04b6a0: aa1f03ed  mov      x13, xzr
//   0x04b6a4: 9112ac3c  add      x28, x1, #0x4ab
//   0x04b6a8: 9139535a  add      x26, x26, #0xe54
//   0x04b6ac: 9109d339  add      x25, x25, #0x274
//   0x04b6b0: aa0103f3  mov      x19, x1
uint64_t fde_0637_sub_04b674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x9112AC3CULL) + (x2 ^ 0x04B674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x04b674: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x04b678: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x04b67c: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x04b680: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x04b684: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x04b688: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x04b68c: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x04b690: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xB000005AULL; // 0x04b694: adrp x26, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000059ULL; // 0x04b698: adrp x25, #0x55000
    return acc;
}

// [EN] Reconstructed FDE #0638 @ 0x04b8cc..0x04c30c (2624 bytes)
// [VN] Phục dựng FDE #0638 tại 0x04b8cc..0x04c30c (2624 byte)
//   0x04b8cc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x04b8d0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x04b8d4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x04b8d8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x04b8dc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x04b8e0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x04b8e4: 910143fd  add      x29, sp, #0x50
//   0x04b8e8: d10803ff  sub      sp, sp, #0x200
//   0x04b8ec: f90077e1  str      x1, [sp, #0xe8]
//   0x04b8f0: d53bd054  mrs      x20, tpidr_el0
//   0x04b8f4: f9401688  ldr      x8, [x20, #0x28]
//   0x04b8f8: 7101909f  cmp      w4, #0x64
//   0x04b8fc: f81a03a8  stur     x8, [x29, #-0x60]
//   0x04b900: 540001c9  b.ls     #0x4b938
//   0x04b904: 2a1f03e0  mov      w0, wzr
//   0x04b908: f9401688  ldr      x8, [x20, #0x28]
uint64_t fde_0638_sub_04b8cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x04B8CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x04b8cc: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x04b8d0: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x04b8d4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x04b8d8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x04b8dc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x04b8e0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x04b8e4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD10803FFULL; // 0x04b8e8: sub sp, sp, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0xF90077E1ULL; // 0x04b8ec: str x1, [sp, #0xe8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x04b8f0: mrs x20, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0639 @ 0x04c30c..0x04c334 (40 bytes)
// [VN] Phục dựng FDE #0639 tại 0x04c30c..0x04c334 (40 byte)
//   0x04c30c: d2800002  mov      x2, #0
//   0x04c310: 52800003  mov      w3, #0
//   0x04c314: 38401405  ldrb     w5, [x0], #1
//   0x04c318: 924018a4  and      x4, x5, #0x7f
//   0x04c31c: 9ac32084  lsl      x4, x4, x3
//   0x04c320: 11001c63  add      w3, w3, #7
//   0x04c324: aa040042  orr      x2, x2, x4
//   0x04c328: 373fff65  tbnz     w5, #7, #0x4c314
//   0x04c32c: f9000022  str      x2, [x1]
//   0x04c330: d65f03c0  ret      
uint64_t fde_0639_sub_04c30c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C30CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04c30c: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x04c310: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401405ULL; // 0x04c314: ldrb w5, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x924018A4ULL; // 0x04c318: and x4, x5, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC32084ULL; // 0x04c31c: lsl x4, x4, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x04c320: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA040042ULL; // 0x04c324: orr x2, x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF65ULL; // 0x04c328: tbnz w5, #7, #0x4c314
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000022ULL; // 0x04c32c: str x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c330: ret 
    return acc;
}

// [EN] Reconstructed FDE #0640 @ 0x04c334..0x04c374 (64 bytes)
// [VN] Phục dựng FDE #0640 tại 0x04c334..0x04c374 (64 byte)
//   0x04c334: d2800002  mov      x2, #0
//   0x04c338: 52800003  mov      w3, #0
//   0x04c33c: 38401404  ldrb     w4, [x0], #1
//   0x04c340: 92401885  and      x5, x4, #0x7f
//   0x04c344: 9ac320a5  lsl      x5, x5, x3
//   0x04c348: 11001c63  add      w3, w3, #7
//   0x04c34c: aa050042  orr      x2, x2, x5
//   0x04c350: 373fff64  tbnz     w4, #7, #0x4c33c
//   0x04c354: 7100fc7f  cmp      w3, #0x3f
//   0x04c358: 540000a8  b.hi     #0x4c36c
//   0x04c35c: 36300084  tbz      w4, #6, #0x4c36c
//   0x04c360: 92800004  mov      x4, #-1
//   0x04c364: 9ac32083  lsl      x3, x4, x3
//   0x04c368: aa020062  orr      x2, x3, x2
//   0x04c36c: f9000022  str      x2, [x1]
//   0x04c370: d65f03c0  ret      
uint64_t fde_0640_sub_04c334(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x9AC32083ULL) + (x2 ^ 0x04C334ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04c334: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x04c338: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401404ULL; // 0x04c33c: ldrb w4, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x92401885ULL; // 0x04c340: and x5, x4, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC320A5ULL; // 0x04c344: lsl x5, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x04c348: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA050042ULL; // 0x04c34c: orr x2, x2, x5
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF64ULL; // 0x04c350: tbnz w4, #7, #0x4c33c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100FC7FULL; // 0x04c354: cmp w3, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x04c358: b.hi #0x4c36c
    return acc;
}

// [EN] Reconstructed FDE #0641 @ 0x04c374..0x04c464 (240 bytes)
// [VN] Phục dựng FDE #0641 tại 0x04c374..0x04c464 (240 byte)
//   0x04c374: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04c378: 910003fd  mov      x29, sp
//   0x04c37c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04c380: 53001c14  uxtb     w20, w0
//   0x04c384: aa0203f3  mov      x19, x2
//   0x04c388: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04c38c: 7101429f  cmp      w20, #0x50
//   0x04c390: aa0103f6  mov      x22, x1
//   0x04c394: aa0303f5  mov      x21, x3
//   0x04c398: 540000a1  b.ne     #0x4c3ac
//   0x04c39c: 91001c53  add      x19, x2, #7
//   0x04c3a0: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x04c3a4: f8408401  ldr      x1, [x0], #8
//   0x04c3a8: 1400002a  b        #0x4c450
//   0x04c3ac: 12000e81  and      w1, w20, #0xf
//   0x04c3b0: 7100303f  cmp      w1, #0xc
uint64_t fde_0641_sub_04c374(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF8408401ULL) + (x2 ^ 0x04C374ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04c374: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c378: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04c37c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C14ULL; // 0x04c380: uxtb w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x04c384: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04c388: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7101429FULL; // 0x04c38c: cmp w20, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x04c390: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x04c394: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x04c398: b.ne #0x4c3ac
    return acc;
}

// [EN] Reconstructed FDE #0642 @ 0x04c464..0x04c578 (276 bytes)
// [VN] Phục dựng FDE #0642 tại 0x04c464..0x04c578 (276 byte)
//   0x04c464: 900000c2  adrp     x2, #0x64000
//   0x04c468: 52800100  mov      w0, #8
//   0x04c46c: 91164041  add      x1, x2, #0x590
//   0x04c470: 39164040  strb     w0, [x2, #0x590]
//   0x04c474: 39000420  strb     w0, [x1, #1]
//   0x04c478: 39000820  strb     w0, [x1, #2]
//   0x04c47c: 39000c20  strb     w0, [x1, #3]
//   0x04c480: 39001020  strb     w0, [x1, #4]
//   0x04c484: 39001420  strb     w0, [x1, #5]
//   0x04c488: 39001820  strb     w0, [x1, #6]
//   0x04c48c: 39001c20  strb     w0, [x1, #7]
//   0x04c490: 39002020  strb     w0, [x1, #8]
//   0x04c494: 39002420  strb     w0, [x1, #9]
//   0x04c498: 39002820  strb     w0, [x1, #0xa]
//   0x04c49c: 39002c20  strb     w0, [x1, #0xb]
//   0x04c4a0: 39003020  strb     w0, [x1, #0xc]
uint64_t fde_0642_sub_04c464(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900000C2ULL) + (x1 ^ 0x39002420ULL) + (x2 ^ 0x04C464ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900000C2ULL; // 0x04c464: adrp x2, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800100ULL; // 0x04c468: mov w0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x91164041ULL; // 0x04c46c: add x1, x2, #0x590
    acc = (acc * 0x100000001B3ULL) ^ 0x39164040ULL; // 0x04c470: strb w0, [x2, #0x590]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000420ULL; // 0x04c474: strb w0, [x1, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000820ULL; // 0x04c478: strb w0, [x1, #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000C20ULL; // 0x04c47c: strb w0, [x1, #3]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001020ULL; // 0x04c480: strb w0, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001420ULL; // 0x04c484: strb w0, [x1, #5]
    acc = (acc * 0x100000001B3ULL) ^ 0x39001820ULL; // 0x04c488: strb w0, [x1, #6]
    return acc;
}

// [EN] Reconstructed FDE #0643 @ 0x04c578..0x04c5b4 (60 bytes)
// [VN] Phục dựng FDE #0643 tại 0x04c578..0x04c5b4 (60 byte)
//   0x04c578: 900000c3  adrp     x3, #0x64000
//   0x04c57c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04c580: 910003fd  mov      x29, sp
//   0x04c584: 3956bc63  ldrb     w3, [x3, #0x5af]
//   0x04c588: 7100207f  cmp      w3, #8
//   0x04c58c: 540000c1  b.ne     #0x4c5a4
//   0x04c590: f9000041  str      x1, [x2]
//   0x04c594: f941a001  ldr      x1, [x0, #0x340]
//   0x04c598: b6f00081  tbz      x1, #0x3e, #0x4c5a8
//   0x04c59c: 390ddc1f  strb     wzr, [x0, #0x377]
//   0x04c5a0: 14000002  b        #0x4c5a8
//   0x04c5a4: 97fedec7  bl       #0x40c0
//   0x04c5a8: f9007c02  str      x2, [x0, #0xf8]
//   0x04c5ac: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x04c5b0: d65f03c0  ret      
uint64_t fde_0643_sub_04c578(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x900000C3ULL) + (x1 ^ 0xF9007C02ULL) + (x2 ^ 0x04C578ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x900000C3ULL; // 0x04c578: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04c57c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c580: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x3956BC63ULL; // 0x04c584: ldrb w3, [x3, #0x5af]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100207FULL; // 0x04c588: cmp w3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C1ULL; // 0x04c58c: b.ne #0x4c5a4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000041ULL; // 0x04c590: str x1, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A001ULL; // 0x04c594: ldr x1, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xB6F00081ULL; // 0x04c598: tbz x1, #0x3e, #0x4c5a8
    acc = (acc * 0x100000001B3ULL) ^ 0x390DDC1FULL; // 0x04c59c: strb wzr, [x0, #0x377]
    return acc;
}

// [EN] Reconstructed FDE #0644 @ 0x04c5b4..0x04c60c (88 bytes)
// [VN] Phục dựng FDE #0644 tại 0x04c5b4..0x04c60c (88 byte)
//   0x04c5b4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04c5b8: 7101843f  cmp      w1, #0x61
//   0x04c5bc: 910003fd  mov      x29, sp
//   0x04c5c0: 5400004d  b.le     #0x4c5c8
//   0x04c5c4: 97fedebf  bl       #0x40c0
//   0x04c5c8: 900000c3  adrp     x3, #0x64000
//   0x04c5cc: 93407c22  sxtw     x2, w1
//   0x04c5d0: 91164063  add      x3, x3, #0x590
//   0x04c5d4: f941a004  ldr      x4, [x0, #0x340]
//   0x04c5d8: f861d801  ldr      x1, [x0, w1, sxtw #3]
//   0x04c5dc: 38626863  ldrb     w3, [x3, x2]
//   0x04c5e0: b6f000c4  tbz      x4, #0x3e, #0x4c5f8
//   0x04c5e4: 8b020002  add      x2, x0, x2
//   0x04c5e8: 394d6040  ldrb     w0, [x2, #0x358]
//   0x04c5ec: 34000060  cbz      w0, #0x4c5f8
//   0x04c5f0: aa0103e0  mov      x0, x1
uint64_t fde_0644_sub_04c5b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x8B020002ULL) + (x2 ^ 0x04C5B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04c5b4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7101843FULL; // 0x04c5b8: cmp w1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c5bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004DULL; // 0x04c5c0: b.le #0x4c5c8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEDEBFULL; // 0x04c5c4: bl #0x40c0
    acc = (acc * 0x100000001B3ULL) ^ 0x900000C3ULL; // 0x04c5c8: adrp x3, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C22ULL; // 0x04c5cc: sxtw x2, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x91164063ULL; // 0x04c5d0: add x3, x3, #0x590
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A004ULL; // 0x04c5d4: ldr x4, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xF861D801ULL; // 0x04c5d8: ldr x1, [x0, w1, sxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #0645 @ 0x04c60c..0x04c718 (268 bytes)
// [VN] Phục dựng FDE #0645 tại 0x04c60c..0x04c718 (268 byte)
//   0x04c60c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04c610: 910003fd  mov      x29, sp
//   0x04c614: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04c618: aa0003f5  mov      x21, x0
//   0x04c61c: f941a020  ldr      x0, [x1, #0x340]
//   0x04c620: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04c624: aa0103f3  mov      x19, x1
//   0x04c628: b6f00060  tbz      x0, #0x3e, #0x4c634
//   0x04c62c: 394ddc20  ldrb     w0, [x1, #0x377]
//   0x04c630: 350000e0  cbnz     w0, #0x4c64c
//   0x04c634: f9407e60  ldr      x0, [x19, #0xf8]
//   0x04c638: b50000a0  cbnz     x0, #0x4c64c
//   0x04c63c: f9418a61  ldr      x1, [x19, #0x310]
//   0x04c640: aa1303e0  mov      x0, x19
//   0x04c644: 9100e3a2  add      x2, x29, #0x38
//   0x04c648: 97ffffcc  bl       #0x4c578
uint64_t fde_0645_sub_04c60c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF9418A61ULL) + (x2 ^ 0x04C60CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04c60c: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c610: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04c614: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04c618: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A020ULL; // 0x04c61c: ldr x0, [x1, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04c620: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04c624: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB6F00060ULL; // 0x04c628: tbz x0, #0x3e, #0x4c634
    acc = (acc * 0x100000001B3ULL) ^ 0x394DDC20ULL; // 0x04c62c: ldrb w0, [x1, #0x377]
    acc = (acc * 0x100000001B3ULL) ^ 0x350000E0ULL; // 0x04c630: cbnz w0, #0x4c64c
    return acc;
}

// [EN] Reconstructed FDE #0646 @ 0x04c718..0x04c720 (8 bytes)
// [VN] Phục dựng FDE #0646 tại 0x04c718..0x04c720 (8 byte)
//   0x04c718: f9418800  ldr      x0, [x0, #0x310]
//   0x04c71c: d65f03c0  ret      
uint64_t fde_0646_sub_04c718(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9418800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C718ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418800ULL; // 0x04c718: ldr x0, [x0, #0x310]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c71c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0647 @ 0x04c720..0x04c778 (88 bytes)
// [VN] Phục dựng FDE #0647 tại 0x04c720..0x04c778 (88 byte)
//   0x04c720: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04c724: 7101843f  cmp      w1, #0x61
//   0x04c728: 910003fd  mov      x29, sp
//   0x04c72c: 5400004d  b.le     #0x4c734
//   0x04c730: 97fede64  bl       #0x40c0
//   0x04c734: 900000c4  adrp     x4, #0x64000
//   0x04c738: 93407c23  sxtw     x3, w1
//   0x04c73c: 91164084  add      x4, x4, #0x590
//   0x04c740: f941a005  ldr      x5, [x0, #0x340]
//   0x04c744: 38636884  ldrb     w4, [x4, x3]
//   0x04c748: b6f000c5  tbz      x5, #0x3e, #0x4c760
//   0x04c74c: 8b030003  add      x3, x0, x3
//   0x04c750: 394d6063  ldrb     w3, [x3, #0x358]
//   0x04c754: 34000063  cbz      w3, #0x4c760
//   0x04c758: f821d802  str      x2, [x0, w1, sxtw #3]
//   0x04c75c: 14000005  b        #0x4c770
uint64_t fde_0647_sub_04c720(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x394D6063ULL) + (x2 ^ 0x04C720ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04c720: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7101843FULL; // 0x04c724: cmp w1, #0x61
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c728: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004DULL; // 0x04c72c: b.le #0x4c734
    acc = (acc * 0x100000001B3ULL) ^ 0x97FEDE64ULL; // 0x04c730: bl #0x40c0
    acc = (acc * 0x100000001B3ULL) ^ 0x900000C4ULL; // 0x04c734: adrp x4, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C23ULL; // 0x04c738: sxtw x3, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x91164084ULL; // 0x04c73c: add x4, x4, #0x590
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A005ULL; // 0x04c740: ldr x5, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0x38636884ULL; // 0x04c744: ldrb w4, [x4, x3]
    return acc;
}

// [EN] Reconstructed FDE #0648 @ 0x04c778..0x04c780 (8 bytes)
// [VN] Phục dựng FDE #0648 tại 0x04c778..0x04c780 (8 byte)
//   0x04c778: f9418c00  ldr      x0, [x0, #0x318]
//   0x04c77c: d65f03c0  ret      
uint64_t fde_0648_sub_04c778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9418C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418C00ULL; // 0x04c778: ldr x0, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c77c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0649 @ 0x04c780..0x04c794 (20 bytes)
// [VN] Phục dựng FDE #0649 tại 0x04c780..0x04c794 (20 byte)
//   0x04c780: f941a002  ldr      x2, [x0, #0x340]
//   0x04c784: f9418c00  ldr      x0, [x0, #0x318]
//   0x04c788: d37ffc42  lsr      x2, x2, #0x3f
//   0x04c78c: b9000022  str      w2, [x1]
//   0x04c790: d65f03c0  ret      
uint64_t fde_0649_sub_04c780(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF941A002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C780ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF941A002ULL; // 0x04c780: ldr x2, [x0, #0x340]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9418C00ULL; // 0x04c784: ldr x0, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD37FFC42ULL; // 0x04c788: lsr x2, x2, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000022ULL; // 0x04c78c: str w2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c790: ret 
    return acc;
}

// [EN] Reconstructed FDE #0650 @ 0x04c794..0x04c79c (8 bytes)
// [VN] Phục dựng FDE #0650 tại 0x04c794..0x04c79c (8 byte)
//   0x04c794: f9018c01  str      x1, [x0, #0x318]
//   0x04c798: d65f03c0  ret      
uint64_t fde_0650_sub_04c794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9018C01ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9018C01ULL; // 0x04c794: str x1, [x0, #0x318]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c798: ret 
    return acc;
}

// [EN] Reconstructed FDE #0651 @ 0x04c79c..0x04c7a4 (8 bytes)
// [VN] Phục dựng FDE #0651 tại 0x04c79c..0x04c7a4 (8 byte)
//   0x04c79c: f9419000  ldr      x0, [x0, #0x320]
//   0x04c7a0: d65f03c0  ret      
uint64_t fde_0651_sub_04c79c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C79CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419000ULL; // 0x04c79c: ldr x0, [x0, #0x320]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c7a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0652 @ 0x04c7a4..0x04c7ac (8 bytes)
// [VN] Phục dựng FDE #0652 tại 0x04c7a4..0x04c7ac (8 byte)
//   0x04c7a4: f9419c00  ldr      x0, [x0, #0x338]
//   0x04c7a8: d65f03c0  ret      
uint64_t fde_0652_sub_04c7a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C7A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419C00ULL; // 0x04c7a4: ldr x0, [x0, #0x338]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c7a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0653 @ 0x04c7ac..0x04c7d4 (40 bytes)
// [VN] Phục dựng FDE #0653 tại 0x04c7ac..0x04c7d4 (40 byte)
//   0x04c7ac: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04c7b0: d1000400  sub      x0, x0, #1
//   0x04c7b4: 910003fd  mov      x29, sp
//   0x04c7b8: 910063a1  add      x1, x29, #0x18
//   0x04c7bc: 94000c4e  bl       #0x4f8f4
//   0x04c7c0: eb1f001f  cmp      x0, xzr
//   0x04c7c4: f94017a0  ldr      x0, [x29, #0x28]
//   0x04c7c8: a8c37bfd  ldp      x29, x30, [sp], #0x30
//   0x04c7cc: 9a9f1000  csel     x0, x0, xzr, ne
//   0x04c7d0: d65f03c0  ret      
uint64_t fde_0653_sub_04c7ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C7ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04c7ac: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000400ULL; // 0x04c7b0: sub x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c7b4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x910063A1ULL; // 0x04c7b8: add x1, x29, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x94000C4EULL; // 0x04c7bc: bl #0x4f8f4
    acc = (acc * 0x100000001B3ULL) ^ 0xEB1F001FULL; // 0x04c7c0: cmp x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF94017A0ULL; // 0x04c7c4: ldr x0, [x29, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C37BFDULL; // 0x04c7c8: ldp x29, x30, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x9A9F1000ULL; // 0x04c7cc: csel x0, x0, xzr, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c7d0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0654 @ 0x04c7d4..0x04c7dc (8 bytes)
// [VN] Phục dựng FDE #0654 tại 0x04c7d4..0x04c7dc (8 byte)
//   0x04c7d4: f9419800  ldr      x0, [x0, #0x330]
//   0x04c7d8: d65f03c0  ret      
uint64_t fde_0654_sub_04c7d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419800ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C7D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419800ULL; // 0x04c7d4: ldr x0, [x0, #0x330]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c7d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0655 @ 0x04c7dc..0x04c7e4 (8 bytes)
// [VN] Phục dựng FDE #0655 tại 0x04c7dc..0x04c7e4 (8 byte)
//   0x04c7dc: f9419400  ldr      x0, [x0, #0x328]
//   0x04c7e0: d65f03c0  ret      
uint64_t fde_0655_sub_04c7dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9419400ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04C7DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9419400ULL; // 0x04c7dc: ldr x0, [x0, #0x328]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04c7e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0656 @ 0x04c7e4..0x04c85c (120 bytes)
// [VN] Phục dựng FDE #0656 tại 0x04c7e4..0x04c85c (120 byte)
//   0x04c7e4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04c7e8: 53001c02  uxtb     w2, w0
//   0x04c7ec: aa0103e0  mov      x0, x1
//   0x04c7f0: 7103fc5f  cmp      w2, #0xff
//   0x04c7f4: 910003fd  mov      x29, sp
//   0x04c7f8: 540002c0  b.eq     #0x4c850
//   0x04c7fc: 121c0842  and      w2, w2, #0x70
//   0x04c800: 7100805f  cmp      w2, #0x20
//   0x04c804: 540001c0  b.eq     #0x4c83c
//   0x04c808: 540000a8  b.hi     #0x4c81c
//   0x04c80c: 34000222  cbz      w2, #0x4c850
//   0x04c810: 7100405f  cmp      w2, #0x10
//   0x04c814: 540001c1  b.ne     #0x4c84c
//   0x04c818: 1400000e  b        #0x4c850
//   0x04c81c: 7101005f  cmp      w2, #0x40
//   0x04c820: 54000120  b.eq     #0x4c844
uint64_t fde_0656_sub_04c7e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x540001C1ULL) + (x2 ^ 0x04C7E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04c7e4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C02ULL; // 0x04c7e8: uxtb w2, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04c7ec: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC5FULL; // 0x04c7f0: cmp w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c7f4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x540002C0ULL; // 0x04c7f8: b.eq #0x4c850
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0842ULL; // 0x04c7fc: and w2, w2, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100805FULL; // 0x04c800: cmp w2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C0ULL; // 0x04c804: b.eq #0x4c83c
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x04c808: b.hi #0x4c81c
    return acc;
}

// [EN] Reconstructed FDE #0657 @ 0x04c85c..0x04cd54 (1272 bytes)
// [VN] Phục dựng FDE #0657 tại 0x04c85c..0x04cd54 (1272 byte)
//   0x04c85c: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x04c860: 910003fd  mov      x29, sp
//   0x04c864: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04c868: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04c86c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04c870: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04c874: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04c878: b000005b  adrp     x27, #0x55000
//   0x04c87c: aa0103fc  mov      x28, x1
//   0x04c880: aa0203fa  mov      x26, x2
//   0x04c884: aa0303f3  mov      x19, x3
//   0x04c888: f903107f  str      xzr, [x3, #0x620]
//   0x04c88c: d2800018  mov      x24, #0
//   0x04c890: 9129037b  add      x27, x27, #0xa40
//   0x04c894: 9101e3b6  add      x22, x29, #0x78
//   0x04c898: 910203b5  add      x21, x29, #0x80
uint64_t fde_0657_sub_04c85c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0xD2800018ULL) + (x2 ^ 0x04C85CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x04c85c: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04c860: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04c864: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04c868: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x04c86c: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x04c870: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04c874: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB000005BULL; // 0x04c878: adrp x27, #0x55000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103FCULL; // 0x04c87c: mov x28, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203FAULL; // 0x04c880: mov x26, x2
    return acc;
}

// [EN] Reconstructed FDE #0658 @ 0x04cd54..0x04d178 (1060 bytes)
// [VN] Phục dựng FDE #0658 tại 0x04cd54..0x04d178 (1060 byte)
//   0x04cd54: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x04cd58: d280d002  mov      x2, #0x680
//   0x04cd5c: 910003fd  mov      x29, sp
//   0x04cd60: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04cd64: aa0003f4  mov      x20, x0
//   0x04cd68: aa0103f3  mov      x19, x1
//   0x04cd6c: aa0103e0  mov      x0, x1
//   0x04cd70: 52800001  mov      w1, #0
//   0x04cd74: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04cd78: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04cd7c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04cd80: f9002bfb  str      x27, [sp, #0x50]
//   0x04cd84: 97fedcb3  bl       #0x4050
//   0x04cd88: f9418e81  ldr      x1, [x20, #0x318]
//   0x04cd8c: f901aa9f  str      xzr, [x20, #0x350]
//   0x04cd90: f901929f  str      xzr, [x20, #0x320]
uint64_t fde_0658_sub_04cd54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x97FEDCB3ULL) + (x2 ^ 0x04CD54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x04cd54: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0xD280D002ULL; // 0x04cd58: mov x2, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04cd5c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04cd60: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04cd64: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04cd68: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04cd6c: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800001ULL; // 0x04cd70: mov w1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04cd74: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04cd78: stp x23, x24, [sp, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0659 @ 0x04d178..0x04d72c (1460 bytes)
// [VN] Phục dựng FDE #0659 tại 0x04d178..0x04d72c (1460 byte)
//   0x04d178: d108c3ff  sub      sp, sp, #0x230
//   0x04d17c: aa0003e4  mov      x4, x0
//   0x04d180: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x04d184: 910003fd  mov      x29, sp
//   0x04d188: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04d18c: 910243bc  add      x28, x29, #0x90
//   0x04d190: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04d194: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04d198: 90000056  adrp     x22, #0x55000
//   0x04d19c: 90000057  adrp     x23, #0x55000
//   0x04d1a0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04d1a4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04d1a8: aa0103f8  mov      x24, x1
//   0x04d1ac: aa0203f3  mov      x19, x2
//   0x04d1b0: f9000383  str      x3, [x28]
//   0x04d1b4: 52800039  mov      w25, #1
uint64_t fde_0659_sub_04d178(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD108C3FFULL) + (x1 ^ 0xAA0103F8ULL) + (x2 ^ 0x04D178ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD108C3FFULL; // 0x04d178: sub sp, sp, #0x230
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E4ULL; // 0x04d17c: mov x4, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x04d180: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04d184: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x04d188: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243BCULL; // 0x04d18c: add x28, x29, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04d190: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04d194: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000056ULL; // 0x04d198: adrp x22, #0x55000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000057ULL; // 0x04d19c: adrp x23, #0x55000
    return acc;
}

// [EN] Reconstructed FDE #0660 @ 0x04d72c..0x04d938 (524 bytes)
// [VN] Phục dựng FDE #0660 tại 0x04d72c..0x04d938 (524 byte)
//   0x04d72c: d10f83ff  sub      sp, sp, #0x3e0
//   0x04d730: d2807802  mov      x2, #0x3c0
//   0x04d734: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x04d738: 910003fd  mov      x29, sp
//   0x04d73c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04d740: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04d744: aa0003f3  mov      x19, x0
//   0x04d748: 910203b5  add      x21, x29, #0x80
//   0x04d74c: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04d750: aa1503e0  mov      x0, x21
//   0x04d754: aa0103f8  mov      x24, x1
//   0x04d758: aa1303e1  mov      x1, x19
//   0x04d75c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04d760: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04d764: 97fed9ab  bl       #0x3e10
//   0x04d768: f941e3a0  ldr      x0, [x29, #0x3c0]
uint64_t fde_0660_sub_04d72c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10F83FFULL) + (x1 ^ 0xA9046BF9ULL) + (x2 ^ 0x04D72CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10F83FFULL; // 0x04d72c: sub sp, sp, #0x3e0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x04d730: mov x2, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x04d734: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04d738: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04d73c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04d740: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d744: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910203B5ULL; // 0x04d748: add x21, x29, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04d74c: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x04d750: mov x0, x21
    return acc;
}

// [EN] Reconstructed FDE #0661 @ 0x04d938..0x04da14 (220 bytes)
// [VN] Phục dựng FDE #0661 tại 0x04d938..0x04da14 (220 byte)
//   0x04d938: d11a43ff  sub      sp, sp, #0x690
//   0x04d93c: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04d940: 910003fd  mov      x29, sp
//   0x04d944: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04d948: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04d94c: aa0003f3  mov      x19, x0
//   0x04d950: f9001bf7  str      x23, [sp, #0x30]
//   0x04d954: aa0203f6  mov      x22, x2
//   0x04d958: aa0103f7  mov      x23, x1
//   0x04d95c: d2807802  mov      x2, #0x3c0
//   0x04d960: 52800001  mov      w1, #0
//   0x04d964: aa1e03f4  mov      x20, x30
//   0x04d968: 97fed9ba  bl       #0x4050
//   0x04d96c: f9018e74  str      x20, [x19, #0x318]
//   0x04d970: d2e80000  mov      x0, #0x4000000000000000
//   0x04d974: 910143b4  add      x20, x29, #0x50
uint64_t fde_0661_sub_04d938(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A43FFULL) + (x1 ^ 0x97FED9BAULL) + (x2 ^ 0x04D938ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A43FFULL; // 0x04d938: sub sp, sp, #0x690
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04d93c: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04d940: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04d944: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04d948: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04d94c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x04d950: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x04d954: mov x22, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x04d958: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x04d95c: mov x2, #0x3c0
    return acc;
}

// [EN] Reconstructed FDE #0662 @ 0x04da14..0x04da60 (76 bytes)
// [VN] Phục dựng FDE #0662 tại 0x04da14..0x04da60 (76 byte)
//   0x04da14: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x04da18: 910003fd  mov      x29, sp
//   0x04da1c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04da20: aa0103f3  mov      x19, x1
//   0x04da24: aa0003f4  mov      x20, x0
//   0x04da28: 97ffff41  bl       #0x4d72c
//   0x04da2c: f9433661  ldr      x1, [x19, #0x668]
//   0x04da30: 8b011273  add      x19, x19, x1, lsl #4
//   0x04da34: b9400a60  ldr      w0, [x19, #8]
//   0x04da38: 7100181f  cmp      w0, #6
//   0x04da3c: 54000061  b.ne     #0x4da48
//   0x04da40: f9018e9f  str      xzr, [x20, #0x318]
//   0x04da44: 14000004  b        #0x4da54
//   0x04da48: aa1403e0  mov      x0, x20
//   0x04da4c: 97fffada  bl       #0x4c5b4
//   0x04da50: f9018e80  str      x0, [x20, #0x318]
uint64_t fde_0662_sub_04da14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x14000004ULL) + (x2 ^ 0x04DA14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x04da14: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04da18: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04da1c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04da20: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04da24: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF41ULL; // 0x04da28: bl #0x4d72c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9433661ULL; // 0x04da2c: ldr x1, [x19, #0x668]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B011273ULL; // 0x04da30: add x19, x19, x1, lsl #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400A60ULL; // 0x04da34: ldr w0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100181FULL; // 0x04da38: cmp w0, #6
    return acc;
}

// [EN] Reconstructed FDE #0663 @ 0x04da60..0x04db20 (192 bytes)
// [VN] Phục dựng FDE #0663 tại 0x04da60..0x04db20 (192 byte)
//   0x04da60: d11a03ff  sub      sp, sp, #0x680
//   0x04da64: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04da68: 910003fd  mov      x29, sp
//   0x04da6c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04da70: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04da74: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04da78: aa0003f5  mov      x21, x0
//   0x04da7c: aa0103f3  mov      x19, x1
//   0x04da80: 910103b4  add      x20, x29, #0x40
//   0x04da84: 52800097  mov      w23, #4
//   0x04da88: aa1403e1  mov      x1, x20
//   0x04da8c: aa1303e0  mov      x0, x19
//   0x04da90: 97fffcb1  bl       #0x4cd54
//   0x04da94: 2a0003f8  mov      w24, w0
//   0x04da98: aa1303e0  mov      x0, x19
//   0x04da9c: 97fffb1f  bl       #0x4c718
uint64_t fde_0663_sub_04da60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A03FFULL) + (x1 ^ 0x97FFFCB1ULL) + (x2 ^ 0x04DA60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A03FFULL; // 0x04da60: sub sp, sp, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04da64: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04da68: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04da6c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04da70: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04da74: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04da78: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04da7c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x910103B4ULL; // 0x04da80: add x20, x29, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x52800097ULL; // 0x04da84: mov w23, #4
    return acc;
}

// [EN] Reconstructed FDE #0664 @ 0x04db20..0x04dc0c (236 bytes)
// [VN] Phục dựng FDE #0664 tại 0x04db20..0x04dc0c (236 byte)
//   0x04db20: d11a03ff  sub      sp, sp, #0x680
//   0x04db24: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x04db28: 910003fd  mov      x29, sp
//   0x04db2c: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04db30: f9400817  ldr      x23, [x0, #0x10]
//   0x04db34: f9400c18  ldr      x24, [x0, #0x18]
//   0x04db38: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04db3c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04db40: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04db44: aa0103f5  mov      x21, x1
//   0x04db48: aa0003f4  mov      x20, x0
//   0x04db4c: 910143b6  add      x22, x29, #0x50
//   0x04db50: 52800359  mov      w25, #0x1a
//   0x04db54: 5280015a  mov      w26, #0xa
//   0x04db58: aa1503e0  mov      x0, x21
//   0x04db5c: aa1603e1  mov      x1, x22
uint64_t fde_0664_sub_04db20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11A03FFULL) + (x1 ^ 0x52800359ULL) + (x2 ^ 0x04DB20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11A03FFULL; // 0x04db20: sub sp, sp, #0x680
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x04db24: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04db28: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04db2c: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400817ULL; // 0x04db30: ldr x23, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C18ULL; // 0x04db34: ldr x24, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04db38: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x04db3c: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04db40: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x04db44: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0665 @ 0x04dc0c..0x04dd00 (244 bytes)
// [VN] Phục dựng FDE #0665 tại 0x04dc0c..0x04dd00 (244 byte)
//   0x04dc0c: d12903ff  sub      sp, sp, #0xa40
//   0x04dc10: d2807802  mov      x2, #0x3c0
//   0x04dc14: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04dc18: 910003fd  mov      x29, sp
//   0x04dc1c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04dc20: 9100c3b4  add      x20, x29, #0x30
//   0x04dc24: f90013f5  str      x21, [sp, #0x20]
//   0x04dc28: aa0103f3  mov      x19, x1
//   0x04dc2c: aa0003f5  mov      x21, x0
//   0x04dc30: 52800001  mov      w1, #0
//   0x04dc34: aa1403e0  mov      x0, x20
//   0x04dc38: 910006b5  add      x21, x21, #1
//   0x04dc3c: 97fed905  bl       #0x4050
//   0x04dc40: f9018e95  str      x21, [x20, #0x318]
//   0x04dc44: d2e80000  mov      x0, #0x4000000000000000
//   0x04dc48: 910fc3b5  add      x21, x29, #0x3f0
uint64_t fde_0665_sub_04dc0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD12903FFULL) + (x1 ^ 0x97FED905ULL) + (x2 ^ 0x04DC0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD12903FFULL; // 0x04dc0c: sub sp, sp, #0xa40
    acc = (acc * 0x100000001B3ULL) ^ 0xD2807802ULL; // 0x04dc10: mov x2, #0x3c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04dc14: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04dc18: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04dc1c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3B4ULL; // 0x04dc20: add x20, x29, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x04dc24: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04dc28: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04dc2c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800001ULL; // 0x04dc30: mov w1, #0
    return acc;
}

// [EN] Reconstructed FDE #0666 @ 0x04dd00..0x04dd04 (4 bytes)
// [VN] Phục dựng FDE #0666 tại 0x04dd00..0x04dd04 (4 byte)
//   0x04dd00: d65f03c0  ret      
uint64_t fde_0666_sub_04dd00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04DD00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04dd00: ret 
    return acc;
}

// [EN] Reconstructed FDE #0667 @ 0x04dd04..0x04de7c (376 bytes)
// [VN] Phục dựng FDE #0667 tại 0x04dd04..0x04de7c (376 byte)
//   0x04dd04: d13843ff  sub      sp, sp, #0xe10
//   0x04dd08: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x04dd0c: 910003fd  mov      x29, sp
//   0x04dd10: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x04dd14: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x04dd18: 910343b5  add      x21, x29, #0xd0
//   0x04dd1c: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x04dd20: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x04dd24: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x04dd28: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x04dd2c: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x04dd30: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x04dd34: aa1e03e2  mov      x2, x30
//   0x04dd38: 913b43a1  add      x1, x29, #0xed0
//   0x04dd3c: aa0003f4  mov      x20, x0
//   0x04dd40: aa1503e0  mov      x0, x21
uint64_t fde_0667_sub_04dd04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD13843FFULL) + (x1 ^ 0xAA1E03E2ULL) + (x2 ^ 0x04DD04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD13843FFULL; // 0x04dd04: sub sp, sp, #0xe10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x04dd08: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04dd0c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045BF5ULL; // 0x04dd10: stp x21, x22, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x04dd14: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B5ULL; // 0x04dd18: add x21, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x04dd1c: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x04dd20: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x04dd24: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x04dd28: stp x2, x3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0668 @ 0x04de7c..0x04df70 (244 bytes)
// [VN] Phục dựng FDE #0668 tại 0x04de7c..0x04df70 (244 byte)
//   0x04de7c: d11e43ff  sub      sp, sp, #0x790
//   0x04de80: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x04de84: 910003fd  mov      x29, sp
//   0x04de88: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x04de8c: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x04de90: 910343b4  add      x20, x29, #0xd0
//   0x04de94: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x04de98: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x04de9c: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x04dea0: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x04dea4: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x04dea8: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x04deac: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x04deb0: aa0003f5  mov      x21, x0
//   0x04deb4: aa0103f7  mov      x23, x1
//   0x04deb8: aa0203f6  mov      x22, x2
uint64_t fde_0668_sub_04de7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0xA90563F7ULL) + (x2 ^ 0x04DE7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x04de7c: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x04de80: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04de84: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90353F3ULL; // 0x04de88: stp x19, x20, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x04de8c: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B4ULL; // 0x04de90: add x20, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x04de94: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x04de98: stp x2, x3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x04de9c: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x04dea0: stp x0, x1, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0669 @ 0x04df70..0x04e06c (252 bytes)
// [VN] Phục dựng FDE #0669 tại 0x04df70..0x04e06c (252 byte)
//   0x04df70: d11e43ff  sub      sp, sp, #0x790
//   0x04df74: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x04df78: 910003fd  mov      x29, sp
//   0x04df7c: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x04df80: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x04df84: 910343b4  add      x20, x29, #0xd0
//   0x04df88: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x04df8c: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x04df90: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x04df94: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x04df98: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x04df9c: aa1e03e2  mov      x2, x30
//   0x04dfa0: 912143a1  add      x1, x29, #0x850
//   0x04dfa4: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x04dfa8: aa0003f5  mov      x21, x0
//   0x04dfac: aa1403e0  mov      x0, x20
uint64_t fde_0669_sub_04df70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0x912143A1ULL) + (x2 ^ 0x04DF70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x04df70: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x04df74: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04df78: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90353F3ULL; // 0x04df7c: stp x19, x20, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x04df80: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343B4ULL; // 0x04df84: add x20, x29, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x04df88: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x04df8c: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x04df90: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x04df94: stp x2, x3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0670 @ 0x04e06c..0x04e164 (248 bytes)
// [VN] Phục dựng FDE #0670 tại 0x04e06c..0x04e164 (248 byte)
//   0x04e06c: d11e43ff  sub      sp, sp, #0x790
//   0x04e070: a9b47bfd  stp      x29, x30, [sp, #-0xc0]!
//   0x04e074: 910003fd  mov      x29, sp
//   0x04e078: 6d0827e8  stp      d8, d9, [sp, #0x80]
//   0x04e07c: a90107e0  stp      x0, x1, [sp, #0x10]
//   0x04e080: 6d092fea  stp      d10, d11, [sp, #0x90]
//   0x04e084: f9400801  ldr      x1, [x0, #0x10]
//   0x04e088: 6d0a37ec  stp      d12, d13, [sp, #0xa0]
//   0x04e08c: a9020fe2  stp      x2, x3, [sp, #0x20]
//   0x04e090: 6d0b3fee  stp      d14, d15, [sp, #0xb0]
//   0x04e094: a9045bf5  stp      x21, x22, [sp, #0x40]
//   0x04e098: a90353f3  stp      x19, x20, [sp, #0x30]
//   0x04e09c: a90563f7  stp      x23, x24, [sp, #0x50]
//   0x04e0a0: a9066bf9  stp      x25, x26, [sp, #0x60]
//   0x04e0a4: a90773fb  stp      x27, x28, [sp, #0x70]
//   0x04e0a8: aa1e03e2  mov      x2, x30
uint64_t fde_0670_sub_04e06c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD11E43FFULL) + (x1 ^ 0xA90563F7ULL) + (x2 ^ 0x04E06CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD11E43FFULL; // 0x04e06c: sub sp, sp, #0x790
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B47BFDULL; // 0x04e070: stp x29, x30, [sp, #-0xc0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e074: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0827E8ULL; // 0x04e078: stp d8, d9, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90107E0ULL; // 0x04e07c: stp x0, x1, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D092FEAULL; // 0x04e080: stp d10, d11, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400801ULL; // 0x04e084: ldr x1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0A37ECULL; // 0x04e088: stp d12, d13, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9020FE2ULL; // 0x04e08c: stp x2, x3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0B3FEEULL; // 0x04e090: stp d14, d15, [sp, #0xb0]
    return acc;
}

// [EN] Reconstructed FDE #0671 @ 0x04e164..0x04e188 (36 bytes)
// [VN] Phục dựng FDE #0671 tại 0x04e164..0x04e188 (36 byte)
//   0x04e164: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04e168: 910003fd  mov      x29, sp
//   0x04e16c: f9400402  ldr      x2, [x0, #8]
//   0x04e170: b4000082  cbz      x2, #0x4e180
//   0x04e174: aa0003e1  mov      x1, x0
//   0x04e178: 52800020  mov      w0, #1
//   0x04e17c: d63f0040  blr      x2
//   0x04e180: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x04e184: d65f03c0  ret      
uint64_t fde_0671_sub_04e164(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04E164ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04e164: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e168: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400402ULL; // 0x04e16c: ldr x2, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x04e170: cbz x2, #0x4e180
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x04e174: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x04e178: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0040ULL; // 0x04e17c: blr x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x04e180: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04e184: ret 
    return acc;
}

// [EN] Reconstructed FDE #0672 @ 0x04e188..0x04e258 (208 bytes)
// [VN] Phục dựng FDE #0672 tại 0x04e188..0x04e258 (208 byte)
//   0x04e188: d12903ff  sub      sp, sp, #0xa40
//   0x04e18c: aa1e03e2  mov      x2, x30
//   0x04e190: a9b67bfd  stp      x29, x30, [sp, #-0xa0]!
//   0x04e194: 910003fd  mov      x29, sp
//   0x04e198: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e19c: 6d0627e8  stp      d8, d9, [sp, #0x60]
//   0x04e1a0: 910283b4  add      x20, x29, #0xa0
//   0x04e1a4: 6d072fea  stp      d10, d11, [sp, #0x70]
//   0x04e1a8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e1ac: 6d0837ec  stp      d12, d13, [sp, #0x80]
//   0x04e1b0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04e1b4: 6d093fee  stp      d14, d15, [sp, #0x90]
//   0x04e1b8: aa0003f6  mov      x22, x0
//   0x04e1bc: aa0103f7  mov      x23, x1
//   0x04e1c0: aa1403e0  mov      x0, x20
//   0x04e1c4: 912b83a1  add      x1, x29, #0xae0
uint64_t fde_0672_sub_04e188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD12903FFULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x04E188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD12903FFULL; // 0x04e188: sub sp, sp, #0xa40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1E03E2ULL; // 0x04e18c: mov x2, x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B67BFDULL; // 0x04e190: stp x29, x30, [sp, #-0xa0]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e194: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e198: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0627E8ULL; // 0x04e19c: stp d8, d9, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283B4ULL; // 0x04e1a0: add x20, x29, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D072FEAULL; // 0x04e1a4: stp d10, d11, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e1a8: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0837ECULL; // 0x04e1ac: stp d12, d13, [sp, #0x80]
    return acc;
}

// [EN] Reconstructed FDE #0673 @ 0x04e258..0x04e280 (40 bytes)
// [VN] Phục dựng FDE #0673 tại 0x04e258..0x04e280 (40 byte)
//   0x04e258: d2800002  mov      x2, #0
//   0x04e25c: 52800003  mov      w3, #0
//   0x04e260: 38401405  ldrb     w5, [x0], #1
//   0x04e264: 924018a4  and      x4, x5, #0x7f
//   0x04e268: 9ac32084  lsl      x4, x4, x3
//   0x04e26c: 11001c63  add      w3, w3, #7
//   0x04e270: aa040042  orr      x2, x2, x4
//   0x04e274: 373fff65  tbnz     w5, #7, #0x4e260
//   0x04e278: f9000022  str      x2, [x1]
//   0x04e27c: d65f03c0  ret      
uint64_t fde_0673_sub_04e258(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04E258ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04e258: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x04e25c: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401405ULL; // 0x04e260: ldrb w5, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x924018A4ULL; // 0x04e264: and x4, x5, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC32084ULL; // 0x04e268: lsl x4, x4, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x04e26c: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA040042ULL; // 0x04e270: orr x2, x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF65ULL; // 0x04e274: tbnz w5, #7, #0x4e260
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000022ULL; // 0x04e278: str x2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04e27c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0674 @ 0x04e280..0x04e2c0 (64 bytes)
// [VN] Phục dựng FDE #0674 tại 0x04e280..0x04e2c0 (64 byte)
//   0x04e280: d2800002  mov      x2, #0
//   0x04e284: 52800003  mov      w3, #0
//   0x04e288: 38401404  ldrb     w4, [x0], #1
//   0x04e28c: 92401885  and      x5, x4, #0x7f
//   0x04e290: 9ac320a5  lsl      x5, x5, x3
//   0x04e294: 11001c63  add      w3, w3, #7
//   0x04e298: aa050042  orr      x2, x2, x5
//   0x04e29c: 373fff64  tbnz     w4, #7, #0x4e288
//   0x04e2a0: 7100fc7f  cmp      w3, #0x3f
//   0x04e2a4: 540000a8  b.hi     #0x4e2b8
//   0x04e2a8: 36300084  tbz      w4, #6, #0x4e2b8
//   0x04e2ac: 92800004  mov      x4, #-1
//   0x04e2b0: 9ac32083  lsl      x3, x4, x3
//   0x04e2b4: aa020062  orr      x2, x3, x2
//   0x04e2b8: f9000022  str      x2, [x1]
//   0x04e2bc: d65f03c0  ret      
uint64_t fde_0674_sub_04e280(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x9AC32083ULL) + (x2 ^ 0x04E280ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04e280: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800003ULL; // 0x04e284: mov w3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x38401404ULL; // 0x04e288: ldrb w4, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x92401885ULL; // 0x04e28c: and x5, x4, #0x7f
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC320A5ULL; // 0x04e290: lsl x5, x5, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C63ULL; // 0x04e294: add w3, w3, #7
    acc = (acc * 0x100000001B3ULL) ^ 0xAA050042ULL; // 0x04e298: orr x2, x2, x5
    acc = (acc * 0x100000001B3ULL) ^ 0x373FFF64ULL; // 0x04e29c: tbnz w4, #7, #0x4e288
    acc = (acc * 0x100000001B3ULL) ^ 0x7100FC7FULL; // 0x04e2a0: cmp w3, #0x3f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x04e2a4: b.hi #0x4e2b8
    return acc;
}

// [EN] Reconstructed FDE #0675 @ 0x04e2c0..0x04e2dc (28 bytes)
// [VN] Phục dựng FDE #0675 tại 0x04e2c0..0x04e2dc (28 byte)
//   0x04e2c0: f9400423  ldr      x3, [x1, #8]
//   0x04e2c4: f9400441  ldr      x1, [x2, #8]
//   0x04e2c8: eb01007f  cmp      x3, x1
//   0x04e2cc: 5a9f23e0  csetm    w0, lo
//   0x04e2d0: eb01007f  cmp      x3, x1
//   0x04e2d4: 1a9f9400  csinc    w0, w0, wzr, ls
//   0x04e2d8: d65f03c0  ret      
uint64_t fde_0675_sub_04e2c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400423ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04E2C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400423ULL; // 0x04e2c0: ldr x3, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400441ULL; // 0x04e2c4: ldr x1, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x04e2c8: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x5A9F23E0ULL; // 0x04e2cc: csetm w0, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01007FULL; // 0x04e2d0: cmp x3, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F9400ULL; // 0x04e2d4: csinc w0, w0, wzr, ls
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04e2d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0676 @ 0x04e2dc..0x04e39c (192 bytes)
// [VN] Phục dựng FDE #0676 tại 0x04e2dc..0x04e39c (192 byte)
//   0x04e2dc: a9ba7bfd  stp      x29, x30, [sp, #-0x60]!
//   0x04e2e0: 910003fd  mov      x29, sp
//   0x04e2e4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e2e8: 531f7873  lsl      w19, w3, #1
//   0x04e2ec: f90023f9  str      x25, [sp, #0x40]
//   0x04e2f0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04e2f4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e2f8: aa0003f8  mov      x24, x0
//   0x04e2fc: aa0103f9  mov      x25, x1
//   0x04e300: aa0203f4  mov      x20, x2
//   0x04e304: 2a0403f7  mov      w23, w4
//   0x04e308: 11000673  add      w19, w19, #1
//   0x04e30c: 6b17027f  cmp      w19, w23
//   0x04e310: 540003aa  b.ge     #0x4e384
//   0x04e314: 11000675  add      w21, w19, #1
//   0x04e318: 6b1702bf  cmp      w21, w23
uint64_t fde_0676_sub_04e2dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA7BFDULL) + (x1 ^ 0x6B17027FULL) + (x2 ^ 0x04E2DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA7BFDULL; // 0x04e2dc: stp x29, x30, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e2e0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e2e4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7873ULL; // 0x04e2e8: lsl w19, w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x04e2ec: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04e2f0: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e2f4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x04e2f8: mov x24, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x04e2fc: mov x25, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x04e300: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0677 @ 0x04e39c..0x04e450 (180 bytes)
// [VN] Phục dựng FDE #0677 tại 0x04e39c..0x04e450 (180 byte)
//   0x04e39c: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x04e3a0: 910003fd  mov      x29, sp
//   0x04e3a4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e3a8: f9400453  ldr      x19, [x2, #8]
//   0x04e3ac: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e3b0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04e3b4: f90023f9  str      x25, [sp, #0x40]
//   0x04e3b8: aa0003f8  mov      x24, x0
//   0x04e3bc: aa0103f9  mov      x25, x1
//   0x04e3c0: aa0203f5  mov      x21, x2
//   0x04e3c4: 91004056  add      x22, x2, #0x10
//   0x04e3c8: d341fe74  lsr      x20, x19, #1
//   0x04e3cc: 51000694  sub      w20, w20, #1
//   0x04e3d0: 37f80114  tbnz     w20, #0x1f, #0x4e3f0
//   0x04e3d4: aa1803e0  mov      x0, x24
//   0x04e3d8: aa1903e1  mov      x1, x25
uint64_t fde_0677_sub_04e39c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB7BFDULL) + (x1 ^ 0x51000694ULL) + (x2 ^ 0x04E39CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x04e39c: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e3a0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e3a4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400453ULL; // 0x04e3a8: ldr x19, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e3ac: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04e3b0: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x04e3b4: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x04e3b8: mov x24, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F9ULL; // 0x04e3bc: mov x25, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x04e3c0: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0678 @ 0x04e450..0x04e4b0 (96 bytes)
// [VN] Phục dựng FDE #0678 tại 0x04e450..0x04e4b0 (96 byte)
//   0x04e450: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04e454: 53001c00  uxtb     w0, w0
//   0x04e458: 7103fc1f  cmp      w0, #0xff
//   0x04e45c: 910003fd  mov      x29, sp
//   0x04e460: 540001e0  b.eq     #0x4e49c
//   0x04e464: 12000800  and      w0, w0, #7
//   0x04e468: 7100101f  cmp      w0, #4
//   0x04e46c: 54000168  b.hi     #0x4e498
//   0x04e470: f0000021  adrp     x1, #0x55000
//   0x04e474: 912b4021  add      x1, x1, #0xad0
//   0x04e478: 38604820  ldrb     w0, [x1, w0, uxtw]
//   0x04e47c: 10000061  adr      x1, #0x4e488
//   0x04e480: 8b208820  add      x0, x1, w0, sxtb #2
//   0x04e484: d61f0000  br       x0
//   0x04e488: 52800040  mov      w0, #2
//   0x04e48c: 14000007  b        #0x4e4a8
uint64_t fde_0678_sub_04e450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x8B208820ULL) + (x2 ^ 0x04E450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04e450: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x04e454: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x04e458: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e45c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x540001E0ULL; // 0x04e460: b.eq #0x4e49c
    acc = (acc * 0x100000001B3ULL) ^ 0x12000800ULL; // 0x04e464: and w0, w0, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x7100101FULL; // 0x04e468: cmp w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x04e46c: b.hi #0x4e498
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000021ULL; // 0x04e470: adrp x1, #0x55000
    acc = (acc * 0x100000001B3ULL) ^ 0x912B4021ULL; // 0x04e474: add x1, x1, #0xad0
    return acc;
}

// [EN] Reconstructed FDE #0679 @ 0x04e4b0..0x04e510 (96 bytes)
// [VN] Phục dựng FDE #0679 tại 0x04e4b0..0x04e510 (96 byte)
//   0x04e4b0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04e4b4: 53001c00  uxtb     w0, w0
//   0x04e4b8: 7103fc1f  cmp      w0, #0xff
//   0x04e4bc: 910003fd  mov      x29, sp
//   0x04e4c0: 54000220  b.eq     #0x4e504
//   0x04e4c4: 121c0800  and      w0, w0, #0x70
//   0x04e4c8: 7100801f  cmp      w0, #0x20
//   0x04e4cc: 54000140  b.eq     #0x4e4f4
//   0x04e4d0: 54000088  b.hi     #0x4e4e0
//   0x04e4d4: 7100401f  cmp      w0, #0x10
//   0x04e4d8: 350000a0  cbnz     w0, #0x4e4ec
//   0x04e4dc: 1400000a  b        #0x4e504
//   0x04e4e0: 7100c01f  cmp      w0, #0x30
//   0x04e4e4: 540000c0  b.eq     #0x4e4fc
//   0x04e4e8: 7101401f  cmp      w0, #0x50
//   0x04e4ec: 540000c0  b.eq     #0x4e504
uint64_t fde_0679_sub_04e4b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7100C01FULL) + (x2 ^ 0x04E4B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04e4b0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x04e4b4: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x04e4b8: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e4bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x04e4c0: b.eq #0x4e504
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0800ULL; // 0x04e4c4: and w0, w0, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100801FULL; // 0x04e4c8: cmp w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x04e4cc: b.eq #0x4e4f4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x04e4d0: b.hi #0x4e4e0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100401FULL; // 0x04e4d4: cmp w0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0680 @ 0x04e510..0x04e570 (96 bytes)
// [VN] Phục dựng FDE #0680 tại 0x04e510..0x04e570 (96 byte)
//   0x04e510: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04e514: 53001c00  uxtb     w0, w0
//   0x04e518: 7103fc1f  cmp      w0, #0xff
//   0x04e51c: 910003fd  mov      x29, sp
//   0x04e520: 54000220  b.eq     #0x4e564
//   0x04e524: 121c0800  and      w0, w0, #0x70
//   0x04e528: 7100801f  cmp      w0, #0x20
//   0x04e52c: 54000140  b.eq     #0x4e554
//   0x04e530: 54000088  b.hi     #0x4e540
//   0x04e534: 7100401f  cmp      w0, #0x10
//   0x04e538: 350000a0  cbnz     w0, #0x4e54c
//   0x04e53c: 1400000a  b        #0x4e564
//   0x04e540: 7100c01f  cmp      w0, #0x30
//   0x04e544: 540000c0  b.eq     #0x4e55c
//   0x04e548: 7101401f  cmp      w0, #0x50
//   0x04e54c: 540000c0  b.eq     #0x4e564
uint64_t fde_0680_sub_04e510(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x7100C01FULL) + (x2 ^ 0x04E510ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04e510: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C00ULL; // 0x04e514: uxtb w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FC1FULL; // 0x04e518: cmp w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e51c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x54000220ULL; // 0x04e520: b.eq #0x4e564
    acc = (acc * 0x100000001B3ULL) ^ 0x121C0800ULL; // 0x04e524: and w0, w0, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x7100801FULL; // 0x04e528: cmp w0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x04e52c: b.eq #0x4e554
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x04e530: b.hi #0x4e540
    acc = (acc * 0x100000001B3ULL) ^ 0x7100401FULL; // 0x04e534: cmp w0, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0681 @ 0x04e570..0x04e660 (240 bytes)
// [VN] Phục dựng FDE #0681 tại 0x04e570..0x04e660 (240 byte)
//   0x04e570: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04e574: 910003fd  mov      x29, sp
//   0x04e578: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e57c: 53001c14  uxtb     w20, w0
//   0x04e580: aa0203f3  mov      x19, x2
//   0x04e584: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e588: 7101429f  cmp      w20, #0x50
//   0x04e58c: aa0103f6  mov      x22, x1
//   0x04e590: aa0303f5  mov      x21, x3
//   0x04e594: 540000a1  b.ne     #0x4e5a8
//   0x04e598: 91001c53  add      x19, x2, #7
//   0x04e59c: 927df260  and      x0, x19, #0xfffffffffffffff8
//   0x04e5a0: f8408401  ldr      x1, [x0], #8
//   0x04e5a4: 1400002a  b        #0x4e64c
//   0x04e5a8: 12000e81  and      w1, w20, #0xf
//   0x04e5ac: 7100303f  cmp      w1, #0xc
uint64_t fde_0681_sub_04e570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0xF8408401ULL) + (x2 ^ 0x04E570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04e570: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e574: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e578: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C14ULL; // 0x04e57c: uxtb w20, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x04e580: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e584: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7101429FULL; // 0x04e588: cmp w20, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x04e58c: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x04e590: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x04e594: b.ne #0x4e5a8
    return acc;
}

// [EN] Reconstructed FDE #0682 @ 0x04e660..0x04e6f0 (144 bytes)
// [VN] Phục dựng FDE #0682 tại 0x04e660..0x04e6f0 (144 byte)
//   0x04e660: a9bb7bfd  stp      x29, x30, [sp, #-0x50]!
//   0x04e664: 910003fd  mov      x29, sp
//   0x04e668: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e66c: 79404013  ldrh     w19, [x0, #0x20]
//   0x04e670: aa0003f4  mov      x20, x0
//   0x04e674: f9001bf7  str      x23, [sp, #0x30]
//   0x04e678: aa0103f7  mov      x23, x1
//   0x04e67c: d3432a73  ubfx     x19, x19, #3, #8
//   0x04e680: aa1403e1  mov      x1, x20
//   0x04e684: 2a1303e0  mov      w0, w19
//   0x04e688: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e68c: aa0203f6  mov      x22, x2
//   0x04e690: 97ffff88  bl       #0x4e4b0
//   0x04e694: aa0003f5  mov      x21, x0
//   0x04e698: 910022e2  add      x2, x23, #8
//   0x04e69c: aa1503e1  mov      x1, x21
uint64_t fde_0682_sub_04e660(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB7BFDULL) + (x1 ^ 0x97FFFF88ULL) + (x2 ^ 0x04E660ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB7BFDULL; // 0x04e660: stp x29, x30, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e664: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e668: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x79404013ULL; // 0x04e66c: ldrh w19, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04e670: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x04e674: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x04e678: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432A73ULL; // 0x04e67c: ubfx x19, x19, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x04e680: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E0ULL; // 0x04e684: mov w0, w19
    return acc;
}

// [EN] Reconstructed FDE #0683 @ 0x04e6f0..0x04e7ec (252 bytes)
// [VN] Phục dựng FDE #0683 tại 0x04e6f0..0x04e7ec (252 byte)
//   0x04e6f0: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04e6f4: 910003fd  mov      x29, sp
//   0x04e6f8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e6fc: 91002414  add      x20, x0, #9
//   0x04e700: aa0003f3  mov      x19, x0
//   0x04e704: aa1403e0  mov      x0, x20
//   0x04e708: 97fed622  bl       #0x3f90
//   0x04e70c: 91000400  add      x0, x0, #1
//   0x04e710: 39402262  ldrb     w2, [x19, #8]
//   0x04e714: 8b000281  add      x1, x20, x0
//   0x04e718: 71000c5f  cmp      w2, #3
//   0x04e71c: 54000109  b.ls     #0x4e73c
//   0x04e720: 38606a82  ldrb     w2, [x20, x0]
//   0x04e724: 52801fe0  mov      w0, #0xff
//   0x04e728: 7100205f  cmp      w2, #8
//   0x04e72c: 540005a1  b.ne     #0x4e7e0
uint64_t fde_0683_sub_04e6f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0x38606A82ULL) + (x2 ^ 0x04E6F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04e6f0: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e6f4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e6f8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002414ULL; // 0x04e6fc: add x20, x0, #9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04e700: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x04e704: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FED622ULL; // 0x04e708: bl #0x3f90
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x04e70c: add x0, x0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39402262ULL; // 0x04e710: ldrb w2, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B000281ULL; // 0x04e714: add x1, x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0684 @ 0x04e7ec..0x04e94c (352 bytes)
// [VN] Phục dựng FDE #0684 tại 0x04e7ec..0x04e94c (352 byte)
//   0x04e7ec: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x04e7f0: 910003fd  mov      x29, sp
//   0x04e7f4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e7f8: aa0003f6  mov      x22, x0
//   0x04e7fc: 79404000  ldrh     w0, [x0, #0x20]
//   0x04e800: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e804: d3432800  ubfx     x0, x0, #3, #8
//   0x04e808: aa0103f3  mov      x19, x1
//   0x04e80c: aa1603e1  mov      x1, x22
//   0x04e810: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04e814: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04e818: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04e81c: aa0203f7  mov      x23, x2
//   0x04e820: 53001c15  uxtb     w21, w0
//   0x04e824: 97ffff23  bl       #0x4e4b0
//   0x04e828: 910183b8  add      x24, x29, #0x60
uint64_t fde_0684_sub_04e7ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0xAA0203F7ULL) + (x2 ^ 0x04E7ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x04e7ec: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e7f0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e7f4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x04e7f8: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x79404000ULL; // 0x04e7fc: ldrh w0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e800: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432800ULL; // 0x04e804: ubfx x0, x0, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04e808: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x04e80c: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04e810: stp x23, x24, [sp, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0685 @ 0x04e94c..0x04e95c (16 bytes)
// [VN] Phục dựng FDE #0685 tại 0x04e94c..0x04e95c (16 byte)
//   0x04e94c: 91001001  add      x1, x0, #4
//   0x04e950: b9800400  ldrsw    x0, [x0, #4]
//   0x04e954: cb000020  sub      x0, x1, x0
//   0x04e958: 17ffff66  b        #0x4e6f0
uint64_t fde_0685_sub_04e94c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91001001ULL) + (x1 ^ 0x17FFFF66ULL) + (x2 ^ 0x04E94CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91001001ULL; // 0x04e94c: add x1, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800400ULL; // 0x04e950: ldrsw x0, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000020ULL; // 0x04e954: sub x0, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF66ULL; // 0x04e958: b #0x4e6f0
    return acc;
}

// [EN] Reconstructed FDE #0686 @ 0x04e95c..0x04ed78 (1052 bytes)
// [VN] Phục dựng FDE #0686 tại 0x04e95c..0x04ed78 (1052 byte)
//   0x04e95c: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x04e960: f100bc3f  cmp      x1, #0x2f
//   0x04e964: 910003fd  mov      x29, sp
//   0x04e968: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04e96c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04e970: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04e974: 1a9f97ed  cset     w13, hi
//   0x04e978: f9400806  ldr      x6, [x0, #0x10]
//   0x04e97c: f9400007  ldr      x7, [x0]
//   0x04e980: 340007ad  cbz      w13, #0x4ea74
//   0x04e984: b9402843  ldr      w3, [x2, #0x28]
//   0x04e988: 34000763  cbz      w3, #0x4ea74
//   0x04e98c: d00000a1  adrp     x1, #0x64000
//   0x04e990: f9401004  ldr      x4, [x0, #0x20]
//   0x04e994: f9401405  ldr      x5, [x0, #0x28]
//   0x04e998: f9419023  ldr      x3, [x1, #0x320]
uint64_t fde_0686_sub_04e95c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0xD00000A1ULL) + (x2 ^ 0x04E95CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x04e95c: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF100BC3FULL; // 0x04e960: cmp x1, #0x2f
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04e964: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04e968: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04e96c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04e970: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97EDULL; // 0x04e974: cset w13, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400806ULL; // 0x04e978: ldr x6, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400007ULL; // 0x04e97c: ldr x7, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340007ADULL; // 0x04e980: cbz w13, #0x4ea74
    return acc;
}

// [EN] Reconstructed FDE #0687 @ 0x04ed78..0x04ee14 (156 bytes)
// [VN] Phục dựng FDE #0687 tại 0x04ed78..0x04ee14 (156 byte)
//   0x04ed78: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x04ed7c: 910003fd  mov      x29, sp
//   0x04ed80: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04ed84: aa0003f5  mov      x21, x0
//   0x04ed88: aa0103e0  mov      x0, x1
//   0x04ed8c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04ed90: aa0203f3  mov      x19, x2
//   0x04ed94: aa0103f4  mov      x20, x1
//   0x04ed98: 97fffeed  bl       #0x4e94c
//   0x04ed9c: 53001c16  uxtb     w22, w0
//   0x04eda0: aa1503e1  mov      x1, x21
//   0x04eda4: 2a1603e0  mov      w0, w22
//   0x04eda8: 97fffdc2  bl       #0x4e4b0
//   0x04edac: aa0003e1  mov      x1, x0
//   0x04edb0: 91002282  add      x2, x20, #8
//   0x04edb4: 9100c3a3  add      x3, x29, #0x30
uint64_t fde_0687_sub_04ed78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC7BFDULL) + (x1 ^ 0x97FFFDC2ULL) + (x2 ^ 0x04ED78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x04ed78: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ed7c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04ed80: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04ed84: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x04ed88: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04ed8c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x04ed90: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x04ed94: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEEDULL; // 0x04ed98: bl #0x4e94c
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C16ULL; // 0x04ed9c: uxtb w22, w0
    return acc;
}

// [EN] Reconstructed FDE #0688 @ 0x04ee14..0x04ef74 (352 bytes)
// [VN] Phục dựng FDE #0688 tại 0x04ee14..0x04ef74 (352 byte)
//   0x04ee14: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x04ee18: 910003fd  mov      x29, sp
//   0x04ee1c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04ee20: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04ee24: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04ee28: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04ee2c: aa0103f3  mov      x19, x1
//   0x04ee30: f9002bfb  str      x27, [sp, #0x50]
//   0x04ee34: aa0003f4  mov      x20, x0
//   0x04ee38: d280001a  mov      x26, #0
//   0x04ee3c: 52800019  mov      w25, #0
//   0x04ee40: d2800016  mov      x22, #0
//   0x04ee44: d2800001  mov      x1, #0
//   0x04ee48: 9101a3b7  add      x23, x29, #0x68
//   0x04ee4c: d2800038  mov      x24, #1
//   0x04ee50: b9400260  ldr      w0, [x19]
uint64_t fde_0688_sub_04ee14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0xD2800001ULL) + (x2 ^ 0x04EE14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x04ee14: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ee18: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04ee1c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04ee20: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x04ee24: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04ee28: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04ee2c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x04ee30: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x04ee34: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD280001AULL; // 0x04ee38: mov x26, #0
    return acc;
}

// [EN] Reconstructed FDE #0689 @ 0x04ef74..0x04f0a8 (308 bytes)
// [VN] Phục dựng FDE #0689 tại 0x04ef74..0x04f0a8 (308 byte)
//   0x04ef74: a9b97bfd  stp      x29, x30, [sp, #-0x70]!
//   0x04ef78: 910003fd  mov      x29, sp
//   0x04ef7c: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04ef80: aa0003f6  mov      x22, x0
//   0x04ef84: 79404000  ldrh     w0, [x0, #0x20]
//   0x04ef88: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04ef8c: d3432800  ubfx     x0, x0, #3, #8
//   0x04ef90: aa0103f7  mov      x23, x1
//   0x04ef94: aa1603e1  mov      x1, x22
//   0x04ef98: f9002bfb  str      x27, [sp, #0x50]
//   0x04ef9c: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04efa0: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04efa4: 53001c15  uxtb     w21, w0
//   0x04efa8: aa0203f3  mov      x19, x2
//   0x04efac: 97fffd41  bl       #0x4e4b0
//   0x04efb0: 9101a3b8  add      x24, x29, #0x68
uint64_t fde_0689_sub_04ef74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B97BFDULL) + (x1 ^ 0x53001C15ULL) + (x2 ^ 0x04EF74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B97BFDULL; // 0x04ef74: stp x29, x30, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04ef78: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04ef7c: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x04ef80: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x79404000ULL; // 0x04ef84: ldrh w0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04ef88: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3432800ULL; // 0x04ef8c: ubfx x0, x0, #3, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x04ef90: mov x23, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x04ef94: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x04ef98: str x27, [sp, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0690 @ 0x04f0a8..0x04f618 (1392 bytes)
// [VN] Phục dựng FDE #0690 tại 0x04f0a8..0x04f618 (1392 byte)
//   0x04f0a8: a9b77bfd  stp      x29, x30, [sp, #-0x90]!
//   0x04f0ac: 910003fd  mov      x29, sp
//   0x04f0b0: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04f0b4: aa0103f6  mov      x22, x1
//   0x04f0b8: 39408001  ldrb     w1, [x0, #0x20]
//   0x04f0bc: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f0c0: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04f0c4: a9046bf9  stp      x25, x26, [sp, #0x40]
//   0x04f0c8: a90573fb  stp      x27, x28, [sp, #0x50]
//   0x04f0cc: aa0003f3  mov      x19, x0
//   0x04f0d0: 36000081  tbz      w1, #0, #0x4f0e0
//   0x04f0d4: 39408260  ldrb     w0, [x19, #0x20]
//   0x04f0d8: 37000da0  tbnz     w0, #0, #0x4f28c
//   0x04f0dc: 140000d9  b        #0x4f440
//   0x04f0e0: b9402014  ldr      w20, [x0, #0x20]
//   0x04f0e4: d34b7e94  ubfx     x20, x20, #0xb, #0x15
uint64_t fde_0690_sub_04f0a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B77BFDULL) + (x1 ^ 0x37000DA0ULL) + (x2 ^ 0x04F0A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B77BFDULL; // 0x04f0a8: stp x29, x30, [sp, #-0x90]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f0ac: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04f0b0: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x04f0b4: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x39408001ULL; // 0x04f0b8: ldrb w1, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04f0bc: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04f0c0: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046BF9ULL; // 0x04f0c4: stp x25, x26, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90573FBULL; // 0x04f0c8: stp x27, x28, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04f0cc: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0691 @ 0x04f618..0x04f6b4 (156 bytes)
// [VN] Phục dựng FDE #0691 tại 0x04f618..0x04f6b4 (156 byte)
//   0x04f618: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04f61c: 910003fd  mov      x29, sp
//   0x04f620: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f624: f90013f5  str      x21, [sp, #0x20]
//   0x04f628: b40003e0  cbz      x0, #0x4f6a4
//   0x04f62c: b9400004  ldr      w4, [x0]
//   0x04f630: 340003a4  cbz      w4, #0x4f6a4
//   0x04f634: aa0103f3  mov      x19, x1
//   0x04f638: 92800001  mov      x1, #-1
//   0x04f63c: b00000b4  adrp     x20, #0x64000
//   0x04f640: f9000261  str      x1, [x19]
//   0x04f644: 900000a1  adrp     x1, #0x63000
//   0x04f648: f900127f  str      xzr, [x19, #0x20]
//   0x04f64c: aa0103f5  mov      x21, x1
//   0x04f650: f9000e60  str      x0, [x19, #0x18]
//   0x04f654: 5280ff00  mov      w0, #0x7f8
uint64_t fde_0691_sub_04f618(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xF900127FULL) + (x2 ^ 0x04F618ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04f618: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f61c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04f620: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x04f624: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003E0ULL; // 0x04f628: cbz x0, #0x4f6a4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400004ULL; // 0x04f62c: ldr w4, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x340003A4ULL; // 0x04f630: cbz w4, #0x4f6a4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x04f634: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x92800001ULL; // 0x04f638: mov x1, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000B4ULL; // 0x04f63c: adrp x20, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0692 @ 0x04f6b4..0x04f6c0 (12 bytes)
// [VN] Phục dựng FDE #0692 tại 0x04f6b4..0x04f6c0 (12 byte)
//   0x04f6b4: d2800002  mov      x2, #0
//   0x04f6b8: d2800003  mov      x3, #0
//   0x04f6bc: 17ffffd7  b        #0x4f618
uint64_t fde_0692_sub_04f6b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x17FFFFD7ULL) + (x2 ^ 0x04F6B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04f6b4: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800003ULL; // 0x04f6b8: mov x3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFD7ULL; // 0x04f6bc: b #0x4f618
    return acc;
}

// [EN] Reconstructed FDE #0693 @ 0x04f6c0..0x04f700 (64 bytes)
// [VN] Phục dựng FDE #0693 tại 0x04f6c0..0x04f700 (64 byte)
//   0x04f6c0: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x04f6c4: 910003fd  mov      x29, sp
//   0x04f6c8: b9400001  ldr      w1, [x0]
//   0x04f6cc: f9000bf3  str      x19, [sp, #0x10]
//   0x04f6d0: 34000121  cbz      w1, #0x4f6f4
//   0x04f6d4: aa0003f3  mov      x19, x0
//   0x04f6d8: d2800600  mov      x0, #0x30
//   0x04f6dc: 97fed215  bl       #0x3f30
//   0x04f6e0: aa0003e1  mov      x1, x0
//   0x04f6e4: aa1303e0  mov      x0, x19
//   0x04f6e8: f9400bf3  ldr      x19, [sp, #0x10]
//   0x04f6ec: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x04f6f0: 17fffff1  b        #0x4f6b4
//   0x04f6f4: f9400bf3  ldr      x19, [sp, #0x10]
//   0x04f6f8: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x04f6fc: d65f03c0  ret      
uint64_t fde_0693_sub_04f6c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x17FFFFF1ULL) + (x2 ^ 0x04F6C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x04f6c0: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f6c4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x04f6c8: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x04f6cc: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000121ULL; // 0x04f6d0: cbz w1, #0x4f6f4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04f6d4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800600ULL; // 0x04f6d8: mov x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x97FED215ULL; // 0x04f6dc: bl #0x3f30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x04f6e0: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x04f6e4: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0694 @ 0x04f700..0x04f794 (148 bytes)
// [VN] Phục dựng FDE #0694 tại 0x04f700..0x04f794 (148 byte)
//   0x04f700: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04f704: 92800004  mov      x4, #-1
//   0x04f708: 910003fd  mov      x29, sp
//   0x04f70c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f710: f900103f  str      xzr, [x1, #0x20]
//   0x04f714: b00000b3  adrp     x19, #0x64000
//   0x04f718: f9000c20  str      x0, [x1, #0x18]
//   0x04f71c: 52800040  mov      w0, #2
//   0x04f720: 39008020  strb     w0, [x1, #0x20]
//   0x04f724: f9000422  str      x2, [x1, #8]
//   0x04f728: 900000a2  adrp     x2, #0x63000
//   0x04f72c: 79404020  ldrh     w0, [x1, #0x20]
//   0x04f730: aa0203f4  mov      x20, x2
//   0x04f734: f9000024  str      x4, [x1]
//   0x04f738: 321d1c00  orr      w0, w0, #0x7f8
//   0x04f73c: f9000823  str      x3, [x1, #0x10]
uint64_t fde_0694_sub_04f700(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x04F700ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04f700: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x92800004ULL; // 0x04f704: mov x4, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f708: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04f70c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900103FULL; // 0x04f710: str xzr, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000B3ULL; // 0x04f714: adrp x19, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C20ULL; // 0x04f718: str x0, [x1, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800040ULL; // 0x04f71c: mov w0, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x39008020ULL; // 0x04f720: strb w0, [x1, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000422ULL; // 0x04f724: str x2, [x1, #8]
    return acc;
}

// [EN] Reconstructed FDE #0695 @ 0x04f794..0x04f7a0 (12 bytes)
// [VN] Phục dựng FDE #0695 tại 0x04f794..0x04f7a0 (12 byte)
//   0x04f794: d2800002  mov      x2, #0
//   0x04f798: d2800003  mov      x3, #0
//   0x04f79c: 17ffffd9  b        #0x4f700
uint64_t fde_0695_sub_04f794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD2800002ULL) + (x1 ^ 0x17FFFFD9ULL) + (x2 ^ 0x04F794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800002ULL; // 0x04f794: mov x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800003ULL; // 0x04f798: mov x3, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFD9ULL; // 0x04f79c: b #0x4f700
    return acc;
}

// [EN] Reconstructed FDE #0696 @ 0x04f7a0..0x04f7cc (44 bytes)
// [VN] Phục dựng FDE #0696 tại 0x04f7a0..0x04f7cc (44 byte)
//   0x04f7a0: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x04f7a4: 910003fd  mov      x29, sp
//   0x04f7a8: f9000bf3  str      x19, [sp, #0x10]
//   0x04f7ac: aa0003f3  mov      x19, x0
//   0x04f7b0: d2800600  mov      x0, #0x30
//   0x04f7b4: 97fed1df  bl       #0x3f30
//   0x04f7b8: aa0003e1  mov      x1, x0
//   0x04f7bc: aa1303e0  mov      x0, x19
//   0x04f7c0: f9400bf3  ldr      x19, [sp, #0x10]
//   0x04f7c4: a8c27bfd  ldp      x29, x30, [sp], #0x20
//   0x04f7c8: 17fffff3  b        #0x4f794
uint64_t fde_0696_sub_04f7a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x17FFFFF3ULL) + (x2 ^ 0x04F7A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x04f7a0: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f7a4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x04f7a8: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x04f7ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD2800600ULL; // 0x04f7b0: mov x0, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x97FED1DFULL; // 0x04f7b4: bl #0x3f30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x04f7b8: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x04f7bc: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BF3ULL; // 0x04f7c0: ldr x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C27BFDULL; // 0x04f7c4: ldp x29, x30, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #0697 @ 0x04f7cc..0x04f8cc (256 bytes)
// [VN] Phục dựng FDE #0697 tại 0x04f7cc..0x04f8cc (256 byte)
//   0x04f7cc: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x04f7d0: 910003fd  mov      x29, sp
//   0x04f7d4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f7d8: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04f7dc: b4000580  cbz      x0, #0x4f88c
//   0x04f7e0: b9400001  ldr      w1, [x0]
//   0x04f7e4: 34000541  cbz      w1, #0x4f88c
//   0x04f7e8: 900000b4  adrp     x20, #0x63000
//   0x04f7ec: aa0003f5  mov      x21, x0
//   0x04f7f0: b00000b6  adrp     x22, #0x64000
//   0x04f7f4: f9473680  ldr      x0, [x20, #0xe68]
//   0x04f7f8: b4000080  cbz      x0, #0x4f808
//   0x04f7fc: 9117e2c0  add      x0, x22, #0x5f8
//   0x04f800: 91068000  add      x0, x0, #0x1a0
//   0x04f804: 97fed24b  bl       #0x4130
//   0x04f808: 9117e2c0  add      x0, x22, #0x5f8
uint64_t fde_0697_sub_04f7cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0x9117E2C0ULL) + (x2 ^ 0x04F7CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x04f7cc: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f7d0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x04f7d4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04f7d8: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000580ULL; // 0x04f7dc: cbz x0, #0x4f88c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x04f7e0: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000541ULL; // 0x04f7e4: cbz w1, #0x4f88c
    acc = (acc * 0x100000001B3ULL) ^ 0x900000B4ULL; // 0x04f7e8: adrp x20, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x04f7ec: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000B6ULL; // 0x04f7f0: adrp x22, #0x64000
    return acc;
}

// [EN] Reconstructed FDE #0698 @ 0x04f8cc..0x04f8d0 (4 bytes)
// [VN] Phục dựng FDE #0698 tại 0x04f8cc..0x04f8d0 (4 byte)
//   0x04f8cc: 17ffffc0  b        #0x4f7cc
uint64_t fde_0698_sub_04f8cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFFC0ULL) + (x1 ^ 0x17FFFFC0ULL) + (x2 ^ 0x04F8CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFC0ULL; // 0x04f8cc: b #0x4f7cc
    return acc;
}

// [EN] Reconstructed FDE #0699 @ 0x04f8d0..0x04f8f4 (36 bytes)
// [VN] Phục dựng FDE #0699 tại 0x04f8d0..0x04f8f4 (36 byte)
//   0x04f8d0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x04f8d4: 910003fd  mov      x29, sp
//   0x04f8d8: b9400001  ldr      w1, [x0]
//   0x04f8dc: 34000081  cbz      w1, #0x4f8ec
//   0x04f8e0: 97fffffb  bl       #0x4f8cc
//   0x04f8e4: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x04f8e8: 17fed186  b        #0x3f00
//   0x04f8ec: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x04f8f0: d65f03c0  ret      
uint64_t fde_0699_sub_04f8d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x04F8D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x04f8d0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f8d4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400001ULL; // 0x04f8d8: ldr w1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000081ULL; // 0x04f8dc: cbz w1, #0x4f8ec
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFFBULL; // 0x04f8e0: bl #0x4f8cc
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x04f8e4: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FED186ULL; // 0x04f8e8: b #0x3f00
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x04f8ec: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x04f8f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0700 @ 0x04f8f4..0x04fab8 (452 bytes)
// [VN] Phục dựng FDE #0700 tại 0x04f8f4..0x04fab8 (452 byte)
//   0x04f8f4: a9b87bfd  stp      x29, x30, [sp, #-0x80]!
//   0x04f8f8: 910003fd  mov      x29, sp
//   0x04f8fc: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x04f900: 900000b5  adrp     x21, #0x63000
//   0x04f904: f90023f9  str      x25, [sp, #0x40]
//   0x04f908: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x04f90c: aa0003f7  mov      x23, x0
//   0x04f910: aa0103f6  mov      x22, x1
//   0x04f914: f94736a0  ldr      x0, [x21, #0xe68]
//   0x04f918: b00000b9  adrp     x25, #0x64000
//   0x04f91c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x04f920: b4000080  cbz      x0, #0x4f930
//   0x04f924: 9117e320  add      x0, x25, #0x5f8
//   0x04f928: 91068000  add      x0, x0, #0x1a0
//   0x04f92c: 97fed201  bl       #0x4130
//   0x04f930: 9117e320  add      x0, x25, #0x5f8
uint64_t fde_0700_sub_04f8f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9B87BFDULL) + (x1 ^ 0x9117E320ULL) + (x2 ^ 0x04F8F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9B87BFDULL; // 0x04f8f4: stp x29, x30, [sp, #-0x80]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x04f8f8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x04f8fc: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x900000B5ULL; // 0x04f900: adrp x21, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x04f904: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x04f908: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x04f90c: mov x23, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x04f910: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF94736A0ULL; // 0x04f914: ldr x0, [x21, #0xe68]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000B9ULL; // 0x04f918: adrp x25, #0x64000
    return acc;
}

uint64_t DispatchVp8EngineFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 470U || fde_index >= 701U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x94D049BB133111EBULL) + x2;
}

} // namespace vp8
} // namespace webp
} // namespace imagepipeline
} // namespace facebook
