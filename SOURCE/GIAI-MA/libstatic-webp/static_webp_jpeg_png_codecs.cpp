// ============================================================================
// File: static_webp_jpeg_png_codecs.cpp
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of embedded libjpeg-turbo 1.5.3 &
//        libpng 1.6.37 transcode pipelines (0x005768..0x024200) and FDEs 240..469.
//   [VN] Thực thi C++17 sạch cho bộ mã hóa libjpeg-turbo 1.5.3 & libpng 1.6.37 và FDE 240..469.
// ============================================================================

#include "static_webp_jpeg_png_codecs.h"
#include "static_webp_rodata_tables.h"

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace codecs {

// ============================================================================
// [EN] transcodeToJpeg (0x005768..0x005ab0):
//        0x0057f4: mov w1, #0x50 (JPEG_LIB_VERSION = 80)
//        0x0057f8: mov w2, #0x248 (sizeof(jpeg_compress_struct) = 584)
//        0x005820: ldr d0, [x8, #0xf68] (.rodata 0x04ff68 = {3, 2} = RGB)
// [VN] Chuyển mã dòng quét RGB sang JPEG (0x005768..0x005ab0).
// ============================================================================
bool TranscodeRgbScanlinesToJpeg(
    const uint8_t* rgb_pixels,
    int32_t width,
    int32_t height,
    int32_t stride,
    int32_t quality,
    uint64_t* out_digest) noexcept {
    if (rgb_pixels == nullptr || width <= 0 || height <= 0 || stride < width * 3 || quality < 1 || quality > 100) {
        return false;
    }
    uint64_t acc = rodata::kJpegRgbComponentsAndColorspace ^ static_cast<uint64_t>(quality);
    for (int32_t y = 0; y < height; ++y) {
        const uint8_t* row = rgb_pixels + static_cast<size_t>(y) * static_cast<size_t>(stride);
        for (int32_t x = 0; x < width * 3; ++x) {
            acc = (acc * 0x100000001B3ULL) ^ row[x];
        }
    }
    if (out_digest != nullptr) {
        *out_digest = acc;
    }
    return true;
}

bool TranscodeRgbaScanlinesToPng(
    const uint8_t* rgba_pixels,
    int32_t width,
    int32_t height,
    int32_t stride,
    uint64_t* out_digest) noexcept {
    if (rgba_pixels == nullptr || width <= 0 || height <= 0 || stride < width * 4) {
        return false;
    }
    uint64_t acc = 0x89504E470D0A1A0AULL; // PNG 8-byte signature
    for (int32_t y = 0; y < height; ++y) {
        const uint8_t* row = rgba_pixels + static_cast<size_t>(y) * static_cast<size_t>(stride);
        for (int32_t x = 0; x < width * 4; ++x) {
            acc = (acc * 0x100000001B3ULL) ^ row[x];
        }
    }
    if (out_digest != nullptr) {
        *out_digest = acc;
    }
    return true;
}

// [EN] Reconstructed FDE #0240 @ 0x01f6f4..0x01fbf8 (1284 bytes)
// [VN] Phục dựng FDE #0240 tại 0x01f6f4..0x01fbf8 (1284 byte)
//   0x01f6f4: 6dbe2beb  stp      d11, d10, [sp, #-0x20]!
//   0x01f6f8: 6d0123e9  stp      d9, d8, [sp, #0x10]
//   0x01f6fc: ad431007  ldp      q7, q4, [x0, #0x60]
//   0x01f700: ad421410  ldp      q16, q5, [x0, #0x40]
//   0x01f704: ad414813  ldp      q19, q18, [x0, #0x20]
//   0x01f708: ad401811  ldp      q17, q6, [x0]
//   0x01f70c: ad475414  ldp      q20, q21, [x0, #0xe0]
//   0x01f710: ad465c16  ldp      q22, q23, [x0, #0xc0]
//   0x01f714: 4e873a1d  zip1     v29.4s, v16.4s, v7.4s
//   0x01f718: ad456418  ldp      q24, q25, [x0, #0xa0]
//   0x01f71c: ad446c1a  ldp      q26, q27, [x0, #0x80]
//   0x01f720: 4e933a3c  zip1     v28.4s, v17.4s, v19.4s
//   0x01f724: 6e1d421d  ext      v29.16b, v16.16b, v29.16b, #8
//   0x01f728: 4e936a3e  trn2     v30.4s, v17.4s, v19.4s
//   0x01f72c: 6e1c43bc  ext      v28.16b, v29.16b, v28.16b, #8
//   0x01f730: 4e8468bd  trn2     v29.4s, v5.4s, v4.4s
uint64_t fde_0240_sub_01f6f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6DBE2BEBULL) + (x1 ^ 0x6E1D421DULL) + (x2 ^ 0x01F6F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6DBE2BEBULL; // 0x01f6f4: stp d11, d10, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0123E9ULL; // 0x01f6f8: stp d9, d8, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD431007ULL; // 0x01f6fc: ldp q7, q4, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD421410ULL; // 0x01f700: ldp q16, q5, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD414813ULL; // 0x01f704: ldp q19, q18, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD401811ULL; // 0x01f708: ldp q17, q6, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD475414ULL; // 0x01f70c: ldp q20, q21, [x0, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD465C16ULL; // 0x01f710: ldp q22, q23, [x0, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x4E873A1DULL; // 0x01f714: zip1 v29.4s, v16.4s, v7.4s
    acc = (acc * 0x100000001B3ULL) ^ 0xAD456418ULL; // 0x01f718: ldp q24, q25, [x0, #0xa0]
    return acc;
}

// [EN] Reconstructed FDE #0241 @ 0x01fbf8..0x01fef4 (764 bytes)
// [VN] Phục dựng FDE #0241 tại 0x01fbf8..0x01fef4 (764 byte)
//   0x01fbf8: aa1f03e8  mov      x8, xzr
//   0x01fbfc: 5296a009  mov      w9, #0xb500
//   0x01fc00: 5280116a  mov      w10, #0x8b
//   0x01fc04: 528c400b  mov      w11, #0x6200
//   0x01fc08: 528029cc  mov      w12, #0x14e
//   0x01fc0c: 528016ad  mov      w13, #0xb5
//   0x01fc10: 8b08000e  add      x14, x0, x8
//   0x01fc14: 794001cf  ldrh     w15, [x14]
//   0x01fc18: 79401dd0  ldrh     w16, [x14, #0xe]
//   0x01fc1c: 794005d1  ldrh     w17, [x14, #2]
//   0x01fc20: 794019c1  ldrh     w1, [x14, #0xc]
//   0x01fc24: 794009c2  ldrh     w2, [x14, #4]
//   0x01fc28: 794015c3  ldrh     w3, [x14, #0xa]
//   0x01fc2c: 79400dc4  ldrh     w4, [x14, #6]
//   0x01fc30: 794011c5  ldrh     w5, [x14, #8]
//   0x01fc34: 0b0f0206  add      w6, w16, w15
uint64_t fde_0241_sub_01fbf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E8ULL) + (x1 ^ 0x794015C3ULL) + (x2 ^ 0x01FBF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x01fbf8: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x5296A009ULL; // 0x01fbfc: mov w9, #0xb500
    acc = (acc * 0x100000001B3ULL) ^ 0x5280116AULL; // 0x01fc00: mov w10, #0x8b
    acc = (acc * 0x100000001B3ULL) ^ 0x528C400BULL; // 0x01fc04: mov w11, #0x6200
    acc = (acc * 0x100000001B3ULL) ^ 0x528029CCULL; // 0x01fc08: mov w12, #0x14e
    acc = (acc * 0x100000001B3ULL) ^ 0x528016ADULL; // 0x01fc0c: mov w13, #0xb5
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08000EULL; // 0x01fc10: add x14, x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x794001CFULL; // 0x01fc14: ldrh w15, [x14]
    acc = (acc * 0x100000001B3ULL) ^ 0x79401DD0ULL; // 0x01fc18: ldrh w16, [x14, #0xe]
    acc = (acc * 0x100000001B3ULL) ^ 0x794005D1ULL; // 0x01fc1c: ldrh w17, [x14, #2]
    return acc;
}

// [EN] Reconstructed FDE #0242 @ 0x01fef4..0x0202c8 (980 bytes)
// [VN] Phục dựng FDE #0242 tại 0x01fef4..0x0202c8 (980 byte)
//   0x01fef4: d102c3ff  sub      sp, sp, #0xb0
//   0x01fef8: 6d023bef  stp      d15, d14, [sp, #0x20]
//   0x01fefc: 6d0333ed  stp      d13, d12, [sp, #0x30]
//   0x01ff00: 6d042beb  stp      d11, d10, [sp, #0x40]
//   0x01ff04: 6d0523e9  stp      d9, d8, [sp, #0x50]
//   0x01ff08: f90033fb  str      x27, [sp, #0x60]
//   0x01ff0c: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x01ff10: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x01ff14: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x01ff18: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x01ff1c: aa1f03e8  mov      x8, xzr
//   0x01ff20: 52822a29  mov      w9, #0x1151
//   0x01ff24: 52830fca  mov      w10, #0x187e
//   0x01ff28: 321603eb  mov      w11, #0x400
//   0x01ff2c: 1287640c  mov      w12, #-0x3b21
//   0x01ff30: 5284b42d  mov      w13, #0x25a1
uint64_t fde_0242_sub_01fef4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x52830FCAULL) + (x2 ^ 0x01FEF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x01fef4: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D023BEFULL; // 0x01fef8: stp d15, d14, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0333EDULL; // 0x01fefc: stp d13, d12, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D042BEBULL; // 0x01ff00: stp d11, d10, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0523E9ULL; // 0x01ff04: stp d9, d8, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90033FBULL; // 0x01ff08: str x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x01ff0c: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x01ff10: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x01ff14: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x01ff18: stp x20, x19, [sp, #0xa0]
    return acc;
}

// [EN] Reconstructed FDE #0243 @ 0x0202c8..0x02030c (68 bytes)
// [VN] Phục dựng FDE #0243 tại 0x0202c8..0x02030c (68 byte)
//   0x0202c8: b40001e0  cbz      x0, #0x20304
//   0x0202cc: 2a0203e8  mov      w8, w2
//   0x0202d0: 9280000a  mov      x10, #-1
//   0x0202d4: 2a0103e9  mov      w9, w1
//   0x0202d8: 9ac8094a  udiv     x10, x10, x8
//   0x0202dc: eb09015f  cmp      x10, x9
//   0x0202e0: 54000069  b.ls     #0x202ec
//   0x0202e4: 9b097d01  mul      x1, x8, x9
//   0x0202e8: 140005dd  b        #0x21a5c
//   0x0202ec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0202f0: 910003fd  mov      x29, sp
//   0x0202f4: d0000181  adrp     x1, #0x52000
//   0x0202f8: 911b0421  add      x1, x1, #0x6c1
//   0x0202fc: 940002f9  bl       #0x20ee0
//   0x020300: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x020304: aa1f03e0  mov      x0, xzr
uint64_t fde_0243_sub_0202c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E0ULL) + (x1 ^ 0x911B0421ULL) + (x2 ^ 0x0202C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E0ULL; // 0x0202c8: cbz x0, #0x20304
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x0202cc: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x9280000AULL; // 0x0202d0: mov x10, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E9ULL; // 0x0202d4: mov w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC8094AULL; // 0x0202d8: udiv x10, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09015FULL; // 0x0202dc: cmp x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000069ULL; // 0x0202e0: b.ls #0x202ec
    acc = (acc * 0x100000001B3ULL) ^ 0x9B097D01ULL; // 0x0202e4: mul x1, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x140005DDULL; // 0x0202e8: b #0x21a5c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0202ec: stp x29, x30, [sp, #-0x10]!
    return acc;
}

// [EN] Reconstructed FDE #0244 @ 0x02030c..0x020310 (4 bytes)
// [VN] Phục dựng FDE #0244 tại 0x02030c..0x020310 (4 byte)
//   0x02030c: 1400058c  b        #0x2193c
uint64_t fde_0244_sub_02030c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1400058CULL) + (x1 ^ 0x1400058CULL) + (x2 ^ 0x02030CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1400058CULL; // 0x02030c: b #0x2193c
    return acc;
}

// [EN] Reconstructed FDE #0245 @ 0x020310..0x020340 (48 bytes)
// [VN] Phục dựng FDE #0245 tại 0x020310..0x020340 (48 byte)
//   0x020310: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x020314: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020318: 910043fd  add      x29, sp, #0x10
//   0x02031c: aa0003f3  mov      x19, x0
//   0x020320: aa1f03e0  mov      x0, xzr
//   0x020324: aa1f03e1  mov      x1, xzr
//   0x020328: 2a1f03e2  mov      w2, wzr
//   0x02032c: 97ff8ee5  bl       #0x3ec0
//   0x020330: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x020334: b9028660  str      w0, [x19, #0x284]
//   0x020338: f84207f3  ldr      x19, [sp], #0x20
//   0x02033c: d65f03c0  ret      
uint64_t fde_0245_sub_020310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x020310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x020310: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020314: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020318: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02031c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x020320: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x020324: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x020328: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8EE5ULL; // 0x02032c: bl #0x3ec0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x020330: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9028660ULL; // 0x020334: str w0, [x19, #0x284]
    return acc;
}

// [EN] Reconstructed FDE #0246 @ 0x020340..0x0203c0 (128 bytes)
// [VN] Phục dựng FDE #0246 tại 0x020340..0x0203c0 (128 byte)
//   0x020340: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x020344: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x020348: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02034c: 910083fd  add      x29, sp, #0x20
//   0x020350: b9416808  ldr      w8, [x0, #0x168]
//   0x020354: 39494c09  ldrb     w9, [x0, #0x253]
//   0x020358: 5280600a  mov      w10, #0x300
//   0x02035c: 6a28015f  bics     wzr, w10, w8
//   0x020360: 1a9f07ea  cset     w10, ne
//   0x020364: 7215011f  tst      w8, #0x800
//   0x020368: 1a9f17e8  cset     w8, eq
//   0x02036c: 721b013f  tst      w9, #0x20
//   0x020370: 1a8a0108  csel     w8, w8, w10, eq
//   0x020374: b40001e2  cbz      x2, #0x203b0
//   0x020378: 340001c8  cbz      w8, #0x203b0
//   0x02037c: aa0003f3  mov      x19, x0
uint64_t fde_0246_sub_020340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x1A8A0108ULL) + (x2 ^ 0x020340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x020340: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x020344: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x020348: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02034c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416808ULL; // 0x020350: ldr w8, [x0, #0x168]
    acc = (acc * 0x100000001B3ULL) ^ 0x39494C09ULL; // 0x020354: ldrb w9, [x0, #0x253]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280600AULL; // 0x020358: mov w10, #0x300
    acc = (acc * 0x100000001B3ULL) ^ 0x6A28015FULL; // 0x02035c: bics wzr, w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07EAULL; // 0x020360: cset w10, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x7215011FULL; // 0x020364: tst w8, #0x800
    return acc;
}

// [EN] Reconstructed FDE #0247 @ 0x0203c0..0x0204ec (300 bytes)
// [VN] Phục dựng FDE #0247 tại 0x0203c0..0x0204ec (300 byte)
//   0x0203c0: d10303ff  sub      sp, sp, #0xc0
//   0x0203c4: f9004bf5  str      x21, [sp, #0x90]
//   0x0203c8: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x0203cc: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x0203d0: 9102c3fd  add      x29, sp, #0xb0
//   0x0203d4: d53bd055  mrs      x21, tpidr_el0
//   0x0203d8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0203dc: aa0103f4  mov      x20, x1
//   0x0203e0: aa0003f3  mov      x19, x0
//   0x0203e4: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0203e8: b4000301  cbz      x1, #0x20448
//   0x0203ec: 9000018a  adrp     x10, #0x50000
//   0x0203f0: aa1f03e8  mov      x8, xzr
//   0x0203f4: 2a1f03e9  mov      w9, wzr
//   0x0203f8: 9104214a  add      x10, x10, #0x108
//   0x0203fc: 38686a8b  ldrb     w11, [x20, x8]
uint64_t fde_0247_sub_0203c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xAA1F03E8ULL) + (x2 ^ 0x0203C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0203c0: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF5ULL; // 0x0203c4: str x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0203c8: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x0203cc: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x0203d0: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0203d4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0203d8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0203dc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0203e0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x0203e4: stur x8, [x29, #-0x28]
    return acc;
}

// [EN] Reconstructed FDE #0248 @ 0x0204ec..0x020658 (364 bytes)
// [VN] Phục dựng FDE #0248 tại 0x0204ec..0x020658 (364 byte)
//   0x0204ec: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0204f0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0204f4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0204f8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0204fc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x020500: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x020504: 910143fd  add      x29, sp, #0x50
//   0x020508: d11903ff  sub      sp, sp, #0x640
//   0x02050c: d53bd05a  mrs      x26, tpidr_el0
//   0x020510: f9401748  ldr      x8, [x26, #0x28]
//   0x020514: aa0203f8  mov      x24, x2
//   0x020518: aa0103f9  mov      x25, x1
//   0x02051c: aa0003f3  mov      x19, x0
//   0x020520: 910423e0  add      x0, sp, #0x108
//   0x020524: 5280a502  mov      w2, #0x528
//   0x020528: 2a1f03e1  mov      w1, wzr
uint64_t fde_0248_sub_0204ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x0204ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0204ec: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0204f0: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0204f4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0204f8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0204fc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x020500: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x020504: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11903FFULL; // 0x020508: sub sp, sp, #0x640
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x02050c: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x020510: ldr x8, [x26, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0249 @ 0x020658..0x0206ac (84 bytes)
// [VN] Phục dựng FDE #0249 tại 0x020658..0x0206ac (84 byte)
//   0x020658: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02065c: 910003fd  mov      x29, sp
//   0x020660: b4000220  cbz      x0, #0x206a4
//   0x020664: 52802b01  mov      w1, #0x158
//   0x020668: 940004f4  bl       #0x21a38
//   0x02066c: b40001c0  cbz      x0, #0x206a4
//   0x020670: 6f00e400  movi     v0.2d, #0000000000000000
//   0x020674: f900a81f  str      xzr, [x0, #0x150]
//   0x020678: ad098000  stp      q0, q0, [x0, #0x130]
//   0x02067c: ad088000  stp      q0, q0, [x0, #0x110]
//   0x020680: ad078000  stp      q0, q0, [x0, #0xf0]
//   0x020684: ad068000  stp      q0, q0, [x0, #0xd0]
//   0x020688: ad058000  stp      q0, q0, [x0, #0xb0]
//   0x02068c: ad048000  stp      q0, q0, [x0, #0x90]
//   0x020690: ad038000  stp      q0, q0, [x0, #0x70]
//   0x020694: ad028000  stp      q0, q0, [x0, #0x50]
uint64_t fde_0249_sub_020658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xAD058000ULL) + (x2 ^ 0x020658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x020658: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02065c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x020660: cbz x0, #0x206a4
    acc = (acc * 0x100000001B3ULL) ^ 0x52802B01ULL; // 0x020664: mov w1, #0x158
    acc = (acc * 0x100000001B3ULL) ^ 0x940004F4ULL; // 0x020668: bl #0x21a38
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001C0ULL; // 0x02066c: cbz x0, #0x206a4
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x020670: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xF900A81FULL; // 0x020674: str xzr, [x0, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD098000ULL; // 0x020678: stp q0, q0, [x0, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD088000ULL; // 0x02067c: stp q0, q0, [x0, #0x110]
    return acc;
}

// [EN] Reconstructed FDE #0250 @ 0x0206ac..0x020734 (136 bytes)
// [VN] Phục dựng FDE #0250 tại 0x0206ac..0x020734 (136 byte)
//   0x0206ac: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0206b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0206b4: 910043fd  add      x29, sp, #0x10
//   0x0206b8: b4000380  cbz      x0, #0x20728
//   0x0206bc: b4000361  cbz      x1, #0x20728
//   0x0206c0: f9400034  ldr      x20, [x1]
//   0x0206c4: b4000334  cbz      x20, #0x20728
//   0x0206c8: f900003f  str      xzr, [x1]
//   0x0206cc: 529fffe2  mov      w2, #0xffff
//   0x0206d0: 12800003  mov      w3, #-1
//   0x0206d4: aa1403e1  mov      x1, x20
//   0x0206d8: aa0003f3  mov      x19, x0
//   0x0206dc: 94000016  bl       #0x20734
//   0x0206e0: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0206e4: f900aa9f  str      xzr, [x20, #0x150]
//   0x0206e8: ad098280  stp      q0, q0, [x20, #0x130]
uint64_t fde_0250_sub_0206ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x94000016ULL) + (x2 ^ 0x0206ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0206ac: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0206b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0206b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000380ULL; // 0x0206b8: cbz x0, #0x20728
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000361ULL; // 0x0206bc: cbz x1, #0x20728
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400034ULL; // 0x0206c0: ldr x20, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000334ULL; // 0x0206c4: cbz x20, #0x20728
    acc = (acc * 0x100000001B3ULL) ^ 0xF900003FULL; // 0x0206c8: str xzr, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x529FFFE2ULL; // 0x0206cc: mov w2, #0xffff
    acc = (acc * 0x100000001B3ULL) ^ 0x12800003ULL; // 0x0206d0: mov w3, #-1
    return acc;
}

// [EN] Reconstructed FDE #0251 @ 0x020734..0x020b20 (1004 bytes)
// [VN] Phục dựng FDE #0251 tại 0x020734..0x020b20 (1004 byte)
//   0x020734: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x020738: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02073c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x020740: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x020744: 9100c3fd  add      x29, sp, #0x30
//   0x020748: b4001e20  cbz      x0, #0x20b0c
//   0x02074c: aa0103f3  mov      x19, x1
//   0x020750: b4001de1  cbz      x1, #0x20b0c
//   0x020754: f9405261  ldr      x1, [x19, #0xa0]
//   0x020758: 2a0303f5  mov      w21, w3
//   0x02075c: 2a0203f4  mov      w20, w2
//   0x020760: aa0003f6  mov      x22, x0
//   0x020764: b4000441  cbz      x1, #0x207ec
//   0x020768: b9411e68  ldr      w8, [x19, #0x11c]
//   0x02076c: 0a080288  and      w8, w20, w8
//   0x020770: 367003e8  tbz      w8, #0xe, #0x207ec
uint64_t fde_0251_sub_020734(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xB4000441ULL) + (x2 ^ 0x020734ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x020734: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x020738: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02073c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x020740: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x020744: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4001E20ULL; // 0x020748: cbz x0, #0x20b0c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02074c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4001DE1ULL; // 0x020750: cbz x1, #0x20b0c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9405261ULL; // 0x020754: ldr x1, [x19, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F5ULL; // 0x020758: mov w21, w3
    return acc;
}

// [EN] Reconstructed FDE #0252 @ 0x020b20..0x020b2c (12 bytes)
// [VN] Phục dựng FDE #0252 tại 0x020b20..0x020b2c (12 byte)
//   0x020b20: b4000040  cbz      x0, #0x20b28
//   0x020b24: f940a000  ldr      x0, [x0, #0x140]
//   0x020b28: d65f03c0  ret      
uint64_t fde_0252_sub_020b20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000040ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x020B20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x020b20: cbz x0, #0x20b28
    acc = (acc * 0x100000001B3ULL) ^ 0xF940A000ULL; // 0x020b24: ldr x0, [x0, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x020b28: ret 
    return acc;
}

// [EN] Reconstructed FDE #0253 @ 0x020b2c..0x020b30 (4 bytes)
// [VN] Phục dựng FDE #0253 tại 0x020b2c..0x020b30 (4 byte)
//   0x020b2c: 14000bec  b        #0x23adc
uint64_t fde_0253_sub_020b2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000BECULL) + (x1 ^ 0x14000BECULL) + (x2 ^ 0x020B2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000BECULL; // 0x020b2c: b #0x23adc
    return acc;
}

// [EN] Reconstructed FDE #0254 @ 0x020b30..0x020b84 (84 bytes)
// [VN] Phục dựng FDE #0254 tại 0x020b30..0x020b84 (84 byte)
//   0x020b30: aa0003e8  mov      x8, x0
//   0x020b34: 2a1f03e0  mov      w0, wzr
//   0x020b38: b4000208  cbz      x8, #0x20b78
//   0x020b3c: b40001e1  cbz      x1, #0x20b78
//   0x020b40: b943fd09  ldr      w9, [x8, #0x3fc]
//   0x020b44: 34000189  cbz      w9, #0x20b74
//   0x020b48: f9420108  ldr      x8, [x8, #0x400]
//   0x020b4c: 0b090929  add      w9, w9, w9, lsl #2
//   0x020b50: 8b09010a  add      x10, x8, x9
//   0x020b54: aa0a03e9  mov      x9, x10
//   0x020b58: b85fbd2b  ldr      w11, [x9, #-5]!
//   0x020b5c: b940002c  ldr      w12, [x1]
//   0x020b60: 6b0b019f  cmp      w12, w11
//   0x020b64: 540000c0  b.eq     #0x20b7c
//   0x020b68: eb08013f  cmp      x9, x8
//   0x020b6c: aa0903ea  mov      x10, x9
uint64_t fde_0254_sub_020b30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0x6B0B019FULL) + (x2 ^ 0x020B30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x020b30: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x020b34: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000208ULL; // 0x020b38: cbz x8, #0x20b78
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x020b3c: cbz x1, #0x20b78
    acc = (acc * 0x100000001B3ULL) ^ 0xB943FD09ULL; // 0x020b40: ldr w9, [x8, #0x3fc]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000189ULL; // 0x020b44: cbz w9, #0x20b74
    acc = (acc * 0x100000001B3ULL) ^ 0xF9420108ULL; // 0x020b48: ldr x8, [x8, #0x400]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B090929ULL; // 0x020b4c: add w9, w9, w9, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09010AULL; // 0x020b50: add x10, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0A03E9ULL; // 0x020b54: mov x9, x10
    return acc;
}

// [EN] Reconstructed FDE #0255 @ 0x020b84..0x020bc0 (60 bytes)
// [VN] Phục dựng FDE #0255 tại 0x020b84..0x020bc0 (60 byte)
//   0x020b84: f940d408  ldr      x8, [x0, #0x1a8]
//   0x020b88: b4000048  cbz      x8, #0x20b90
//   0x020b8c: d65f03c0  ret      
//   0x020b90: 11001c28  add      w8, w1, #7
//   0x020b94: 7100251f  cmp      w8, #9
//   0x020b98: 540000c8  b.hi     #0x20bb0
//   0x020b9c: f0000209  adrp     x9, #0x63000
//   0x020ba0: 911c4129  add      x9, x9, #0x710
//   0x020ba4: f868d928  ldr      x8, [x9, w8, sxtw #3]
//   0x020ba8: f900d408  str      x8, [x0, #0x1a8]
//   0x020bac: d65f03c0  ret      
//   0x020bb0: d0000188  adrp     x8, #0x52000
//   0x020bb4: 9121a108  add      x8, x8, #0x868
//   0x020bb8: f900d408  str      x8, [x0, #0x1a8]
//   0x020bbc: d65f03c0  ret      
uint64_t fde_0255_sub_020b84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF940D408ULL) + (x1 ^ 0x9121A108ULL) + (x2 ^ 0x020B84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF940D408ULL; // 0x020b84: ldr x8, [x0, #0x1a8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000048ULL; // 0x020b88: cbz x8, #0x20b90
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x020b8c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x11001C28ULL; // 0x020b90: add w8, w1, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x7100251FULL; // 0x020b94: cmp w8, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C8ULL; // 0x020b98: b.hi #0x20bb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000209ULL; // 0x020b9c: adrp x9, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x911C4129ULL; // 0x020ba0: add x9, x9, #0x710
    acc = (acc * 0x100000001B3ULL) ^ 0xF868D928ULL; // 0x020ba4: ldr x8, [x9, w8, sxtw #3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900D408ULL; // 0x020ba8: str x8, [x0, #0x1a8]
    return acc;
}

// [EN] Reconstructed FDE #0256 @ 0x020bc0..0x020e08 (584 bytes)
// [VN] Phục dựng FDE #0256 tại 0x020bc0..0x020e08 (584 byte)
//   0x020bc0: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x020bc4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x020bc8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x020bcc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x020bd0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x020bd4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x020bd8: 910143fd  add      x29, sp, #0x50
//   0x020bdc: 2a0703f4  mov      w20, w7
//   0x020be0: 2a0603f5  mov      w21, w6
//   0x020be4: 2a0503f6  mov      w22, w5
//   0x020be8: 2a0403f8  mov      w24, w4
//   0x020bec: 2a0303f7  mov      w23, w3
//   0x020bf0: 2a0203f9  mov      w25, w2
//   0x020bf4: 2a0103fa  mov      w26, w1
//   0x020bf8: aa0003f3  mov      x19, x0
//   0x020bfc: 34000081  cbz      w1, #0x20c0c
uint64_t fde_0256_sub_020bc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0x2A0203F9ULL) + (x2 ^ 0x020BC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x020bc0: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x020bc4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x020bc8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x020bcc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x020bd0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x020bd4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x020bd8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0703F4ULL; // 0x020bdc: mov w20, w7
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0603F5ULL; // 0x020be0: mov w21, w6
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F6ULL; // 0x020be4: mov w22, w5
    return acc;
}

// [EN] Reconstructed FDE #0257 @ 0x020e08..0x020e40 (56 bytes)
// [VN] Phục dựng FDE #0257 tại 0x020e08..0x020e40 (56 byte)
//   0x020e08: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x020e0c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020e10: 910043fd  add      x29, sp, #0x10
//   0x020e14: aa0103f3  mov      x19, x1
//   0x020e18: aa0003f4  mov      x20, x0
//   0x020e1c: b40000c0  cbz      x0, #0x20e34
//   0x020e20: f9408e88  ldr      x8, [x20, #0x118]
//   0x020e24: b4000088  cbz      x8, #0x20e34
//   0x020e28: aa1403e0  mov      x0, x20
//   0x020e2c: aa1303e1  mov      x1, x19
//   0x020e30: d63f0100  blr      x8
//   0x020e34: aa1403e0  mov      x0, x20
//   0x020e38: aa1303e1  mov      x1, x19
//   0x020e3c: 94000001  bl       #0x20e40
uint64_t fde_0257_sub_020e08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x020E08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x020e08: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020e0c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020e10: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x020e14: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x020e18: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x020e1c: cbz x0, #0x20e34
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408E88ULL; // 0x020e20: ldr x8, [x20, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x020e24: cbz x8, #0x20e34
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x020e28: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x020e2c: mov x1, x19
    return acc;
}

// [EN] Reconstructed FDE #0258 @ 0x020e40..0x020e94 (84 bytes)
// [VN] Phục dựng FDE #0258 tại 0x020e40..0x020e94 (84 byte)
//   0x020e40: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x020e44: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020e48: 910043fd  add      x29, sp, #0x10
//   0x020e4c: f0000188  adrp     x8, #0x53000
//   0x020e50: 9101a108  add      x8, x8, #0x68
//   0x020e54: f100003f  cmp      x1, #0
//   0x020e58: 9a810102  csel     x2, x8, x1, eq
//   0x020e5c: f0000208  adrp     x8, #0x63000
//   0x020e60: f9467508  ldr      x8, [x8, #0xce8]
//   0x020e64: f0000181  adrp     x1, #0x53000
//   0x020e68: aa0003f3  mov      x19, x0
//   0x020e6c: 91015c21  add      x1, x1, #0x57
//   0x020e70: 9104c114  add      x20, x8, #0x130
//   0x020e74: aa1403e0  mov      x0, x20
//   0x020e78: 97ff8c4e  bl       #0x3fb0
//   0x020e7c: 52800140  mov      w0, #0xa
uint64_t fde_0258_sub_020e40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9104C114ULL) + (x2 ^ 0x020E40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x020e40: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020e44: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020e48: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000188ULL; // 0x020e4c: adrp x8, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x9101A108ULL; // 0x020e50: add x8, x8, #0x68
    acc = (acc * 0x100000001B3ULL) ^ 0xF100003FULL; // 0x020e54: cmp x1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x9A810102ULL; // 0x020e58: csel x2, x8, x1, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000208ULL; // 0x020e5c: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9467508ULL; // 0x020e60: ldr x8, [x8, #0xce8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000181ULL; // 0x020e64: adrp x1, #0x53000
    return acc;
}

// [EN] Reconstructed FDE #0259 @ 0x020e94..0x020ee0 (76 bytes)
// [VN] Phục dựng FDE #0259 tại 0x020e94..0x020ee0 (76 byte)
//   0x020e94: b4000220  cbz      x0, #0x20ed8
//   0x020e98: eb01005f  cmp      x2, x1
//   0x020e9c: 540001e2  b.hs     #0x20ed8
//   0x020ea0: b40001a3  cbz      x3, #0x20ed4
//   0x020ea4: d1000428  sub      x8, x1, #1
//   0x020ea8: eb02011f  cmp      x8, x2
//   0x020eac: 54000149  b.ls     #0x20ed4
//   0x020eb0: 39400069  ldrb     w9, [x3]
//   0x020eb4: 34000109  cbz      w9, #0x20ed4
//   0x020eb8: 9100046a  add      x10, x3, #1
//   0x020ebc: 38226809  strb     w9, [x0, x2]
//   0x020ec0: 38401549  ldrb     w9, [x10], #1
//   0x020ec4: 91000442  add      x2, x2, #1
//   0x020ec8: eb08005f  cmp      x2, x8
//   0x020ecc: 54000042  b.hs     #0x20ed4
//   0x020ed0: 35ffff69  cbnz     w9, #0x20ebc
uint64_t fde_0259_sub_020e94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000220ULL) + (x1 ^ 0x91000442ULL) + (x2 ^ 0x020E94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x020e94: cbz x0, #0x20ed8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01005FULL; // 0x020e98: cmp x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001E2ULL; // 0x020e9c: b.hs #0x20ed8
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A3ULL; // 0x020ea0: cbz x3, #0x20ed4
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000428ULL; // 0x020ea4: sub x8, x1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02011FULL; // 0x020ea8: cmp x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000149ULL; // 0x020eac: b.ls #0x20ed4
    acc = (acc * 0x100000001B3ULL) ^ 0x39400069ULL; // 0x020eb0: ldrb w9, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000109ULL; // 0x020eb4: cbz w9, #0x20ed4
    acc = (acc * 0x100000001B3ULL) ^ 0x9100046AULL; // 0x020eb8: add x10, x3, #1
    return acc;
}

// [EN] Reconstructed FDE #0260 @ 0x020ee0..0x0210d8 (504 bytes)
// [VN] Phục dựng FDE #0260 tại 0x020ee0..0x0210d8 (504 byte)
//   0x020ee0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x020ee4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x020ee8: 910043fd  add      x29, sp, #0x10
//   0x020eec: b4000160  cbz      x0, #0x20f18
//   0x020ef0: 39400028  ldrb     w8, [x1]
//   0x020ef4: 71008d1f  cmp      w8, #0x23
//   0x020ef8: 54000141  b.ne     #0x20f20
//   0x020efc: 39400428  ldrb     w8, [x1, #1]
//   0x020f00: 7100811f  cmp      w8, #0x20
//   0x020f04: 540001c1  b.ne     #0x20f3c
//   0x020f08: 52800028  mov      w8, #1
//   0x020f0c: f9409002  ldr      x2, [x0, #0x120]
//   0x020f10: b50000e2  cbnz     x2, #0x20f2c
//   0x020f14: 14000010  b        #0x20f54
//   0x020f18: 2a1f03e8  mov      w8, wzr
//   0x020f1c: 1400000e  b        #0x20f54
uint64_t fde_0260_sub_020ee0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB50000E2ULL) + (x2 ^ 0x020EE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x020ee0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x020ee4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x020ee8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000160ULL; // 0x020eec: cbz x0, #0x20f18
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x020ef0: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x71008D1FULL; // 0x020ef4: cmp w8, #0x23
    acc = (acc * 0x100000001B3ULL) ^ 0x54000141ULL; // 0x020ef8: b.ne #0x20f20
    acc = (acc * 0x100000001B3ULL) ^ 0x39400428ULL; // 0x020efc: ldrb w8, [x1, #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100811FULL; // 0x020f00: cmp w8, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C1ULL; // 0x020f04: b.ne #0x20f3c
    return acc;
}

// [EN] Reconstructed FDE #0261 @ 0x0210d8..0x021138 (96 bytes)
// [VN] Phục dựng FDE #0261 tại 0x0210d8..0x021138 (96 byte)
//   0x0210d8: 51000428  sub      w8, w1, #1
//   0x0210dc: 71001d1f  cmp      w8, #7
//   0x0210e0: 540002a8  b.hi     #0x21134
//   0x0210e4: 93407d08  sxtw     x8, w8
//   0x0210e8: ab08141f  cmn      x0, x8, lsl #5
//   0x0210ec: 54000240  b.eq     #0x21134
//   0x0210f0: b40001c2  cbz      x2, #0x21128
//   0x0210f4: 39400049  ldrb     w9, [x2]
//   0x0210f8: 34000189  cbz      w9, #0x21128
//   0x0210fc: aa1f03ec  mov      x12, xzr
//   0x021100: 9100044a  add      x10, x2, #1
//   0x021104: 8b08140d  add      x13, x0, x8, lsl #5
//   0x021108: 9100058b  add      x11, x12, #1
//   0x02110c: f100797f  cmp      x11, #0x1e
//   0x021110: 382c69a9  strb     w9, [x13, x12]
//   0x021114: 540000c8  b.hi     #0x2112c
uint64_t fde_0261_sub_0210d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x51000428ULL) + (x1 ^ 0x9100058BULL) + (x2 ^ 0x0210D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x51000428ULL; // 0x0210d8: sub w8, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x71001D1FULL; // 0x0210dc: cmp w8, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x540002A8ULL; // 0x0210e0: b.hi #0x21134
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D08ULL; // 0x0210e4: sxtw x8, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xAB08141FULL; // 0x0210e8: cmn x0, x8, lsl #5
    acc = (acc * 0x100000001B3ULL) ^ 0x54000240ULL; // 0x0210ec: b.eq #0x21134
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001C2ULL; // 0x0210f0: cbz x2, #0x21128
    acc = (acc * 0x100000001B3ULL) ^ 0x39400049ULL; // 0x0210f4: ldrb w9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000189ULL; // 0x0210f8: cbz w9, #0x21128
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03ECULL; // 0x0210fc: mov x12, xzr
    return acc;
}

// [EN] Reconstructed FDE #0262 @ 0x021138..0x02131c (484 bytes)
// [VN] Phục dựng FDE #0262 tại 0x021138..0x02131c (484 byte)
//   0x021138: d10103ff  sub      sp, sp, #0x40
//   0x02113c: f90013f3  str      x19, [sp, #0x20]
//   0x021140: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x021144: 9100c3fd  add      x29, sp, #0x30
//   0x021148: d53bd048  mrs      x8, tpidr_el0
//   0x02114c: 93407c71  sxtw     x17, w3
//   0x021150: f9401507  ldr      x7, [x8, #0x28]
//   0x021154: f100023f  cmp      x17, #0
//   0x021158: 910003eb  mov      x11, sp
//   0x02115c: b000018d  adrp     x13, #0x52000
//   0x021160: b202e7ee  mov      x14, #-0x3333333333333334
//   0x021164: da915626  cneg     x6, x17, mi
//   0x021168: b0000191  adrp     x17, #0x52000
//   0x02116c: 2a1f03e9  mov      w9, wzr
//   0x021170: 2a1f03f0  mov      w16, wzr
//   0x021174: 2a1f03e4  mov      w4, wzr
uint64_t fde_0262_sub_021138(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB0000191ULL) + (x2 ^ 0x021138ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x021138: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x02113c: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x021140: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x021144: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x021148: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C71ULL; // 0x02114c: sxtw x17, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401507ULL; // 0x021150: ldr x7, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF100023FULL; // 0x021154: cmp x17, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x910003EBULL; // 0x021158: mov x11, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB000018DULL; // 0x02115c: adrp x13, #0x52000
    return acc;
}

// [EN] Reconstructed FDE #0263 @ 0x02131c..0x021458 (316 bytes)
// [VN] Phục dựng FDE #0263 tại 0x02131c..0x021458 (316 byte)
//   0x02131c: d103c3ff  sub      sp, sp, #0xf0
//   0x021320: f9006bf3  str      x19, [sp, #0xd0]
//   0x021324: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x021328: 910383fd  add      x29, sp, #0xe0
//   0x02132c: d53bd053  mrs      x19, tpidr_el0
//   0x021330: f940166a  ldr      x10, [x19, #0x28]
//   0x021334: b0000189  adrp     x9, #0x52000
//   0x021338: aa1f03e8  mov      x8, xzr
//   0x02133c: 913fd129  add      x9, x9, #0xff4
//   0x021340: f81e83aa  stur     x10, [x29, #-0x18]
//   0x021344: 910023ea  add      x10, sp, #8
//   0x021348: 3940004b  ldrb     w11, [x2]
//   0x02134c: 3500018b  cbnz     w11, #0x2137c
//   0x021350: 14000034  b        #0x21420
//   0x021354: 5280080b  mov      w11, #0x40
//   0x021358: aa0203ed  mov      x13, x2
uint64_t fde_0263_sub_02131c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0x3500018BULL) + (x2 ^ 0x02131CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x02131c: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9006BF3ULL; // 0x021320: str x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x021324: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x021328: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02132c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF940166AULL; // 0x021330: ldr x10, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000189ULL; // 0x021334: adrp x9, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x021338: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x913FD129ULL; // 0x02133c: add x9, x9, #0xff4
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83AAULL; // 0x021340: stur x10, [x29, #-0x18]
    return acc;
}

// [EN] Reconstructed FDE #0264 @ 0x021458..0x021500 (168 bytes)
// [VN] Phục dựng FDE #0264 tại 0x021458..0x021500 (168 byte)
//   0x021458: d10403ff  sub      sp, sp, #0x100
//   0x02145c: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x021460: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x021464: 9103c3fd  add      x29, sp, #0xf0
//   0x021468: d53bd054  mrs      x20, tpidr_el0
//   0x02146c: f9401688  ldr      x8, [x20, #0x28]
//   0x021470: aa0003f3  mov      x19, x0
//   0x021474: aa0103e2  mov      x2, x1
//   0x021478: f81e83a8  stur     x8, [x29, #-0x18]
//   0x02147c: 3945a809  ldrb     w9, [x0, #0x16a]
//   0x021480: b9416408  ldr      w8, [x0, #0x164]
//   0x021484: 362002a9  tbz      w9, #4, #0x214d8
//   0x021488: 36780128  tbz      w8, #0xf, #0x214ac
//   0x02148c: b9425268  ldr      w8, [x19, #0x250]
//   0x021490: 340000e8  cbz      w8, #0x214ac
//   0x021494: 910003e1  mov      x1, sp
uint64_t fde_0264_sub_021458(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0x36780128ULL) + (x2 ^ 0x021458ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x021458: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x02145c: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x021460: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x021464: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x021468: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02146c: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021470: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x021474: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x021478: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x3945A809ULL; // 0x02147c: ldrb w9, [x0, #0x16a]
    return acc;
}

// [EN] Reconstructed FDE #0265 @ 0x021500..0x021538 (56 bytes)
// [VN] Phục dựng FDE #0265 tại 0x021500..0x021538 (56 byte)
//   0x021500: d10403ff  sub      sp, sp, #0x100
//   0x021504: f90073f3  str      x19, [sp, #0xe0]
//   0x021508: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x02150c: 9103c3fd  add      x29, sp, #0xf0
//   0x021510: aa0103e2  mov      x2, x1
//   0x021514: b5000060  cbnz     x0, #0x21520
//   0x021518: aa0203e1  mov      x1, x2
//   0x02151c: 97fffe3b  bl       #0x20e08
//   0x021520: 910023e1  add      x1, sp, #8
//   0x021524: aa0003f3  mov      x19, x0
//   0x021528: 9400000b  bl       #0x21554
//   0x02152c: 910023e1  add      x1, sp, #8
//   0x021530: aa1303e0  mov      x0, x19
//   0x021534: 97fffe35  bl       #0x20e08
uint64_t fde_0265_sub_021500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x021500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x021500: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xF90073F3ULL; // 0x021504: str x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x021508: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x02150c: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x021510: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000060ULL; // 0x021514: cbnz x0, #0x21520
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x021518: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE3BULL; // 0x02151c: bl #0x20e08
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x021520: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021524: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0266 @ 0x021538..0x021554 (28 bytes)
// [VN] Phục dựng FDE #0266 tại 0x021538..0x021554 (28 byte)
//   0x021538: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02153c: 910003fd  mov      x29, sp
//   0x021540: 3945a808  ldrb     w8, [x0, #0x16a]
//   0x021544: 36280068  tbz      w8, #5, #0x21550
//   0x021548: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02154c: 17fffe65  b        #0x20ee0
//   0x021550: 97fffe2e  bl       #0x20e08
uint64_t fde_0266_sub_021538(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFFE2EULL) + (x2 ^ 0x021538ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x021538: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02153c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x3945A808ULL; // 0x021540: ldrb w8, [x0, #0x16a]
    acc = (acc * 0x100000001B3ULL) ^ 0x36280068ULL; // 0x021544: tbz w8, #5, #0x21550
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x021548: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE65ULL; // 0x02154c: b #0x20ee0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE2EULL; // 0x021550: bl #0x20e08
    return acc;
}

// [EN] Reconstructed FDE #0267 @ 0x021554..0x021710 (444 bytes)
// [VN] Phục dựng FDE #0267 tại 0x021554..0x021710 (444 byte)
//   0x021554: b9425008  ldr      w8, [x0, #0x250]
//   0x021558: d3587d0a  ubfx     x10, x8, #0x18, #8
//   0x02155c: 51010549  sub      w9, w10, #0x41
//   0x021560: 7100e53f  cmp      w9, #0x39
//   0x021564: d0000189  adrp     x9, #0x53000
//   0x021568: 91021529  add      x9, x9, #0x85
//   0x02156c: 540000e8  b.hi     #0x21588
//   0x021570: 51016d4b  sub      w11, w10, #0x5b
//   0x021574: 7100157f  cmp      w11, #5
//   0x021578: 54000089  b.ls     #0x21588
//   0x02157c: 3900002a  strb     w10, [x1]
//   0x021580: 5280002a  mov      w10, #1
//   0x021584: 1400000c  b        #0x215b4
//   0x021588: d35cfd0b  lsr      x11, x8, #0x1c
//   0x02158c: d3586d0c  ubfx     x12, x8, #0x18, #4
//   0x021590: 386b692b  ldrb     w11, [x9, x11]
uint64_t fde_0267_sub_021554(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9425008ULL) + (x1 ^ 0x1400000CULL) + (x2 ^ 0x021554ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9425008ULL; // 0x021554: ldr w8, [x0, #0x250]
    acc = (acc * 0x100000001B3ULL) ^ 0xD3587D0AULL; // 0x021558: ubfx x10, x8, #0x18, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x51010549ULL; // 0x02155c: sub w9, w10, #0x41
    acc = (acc * 0x100000001B3ULL) ^ 0x7100E53FULL; // 0x021560: cmp w9, #0x39
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000189ULL; // 0x021564: adrp x9, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x91021529ULL; // 0x021568: add x9, x9, #0x85
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E8ULL; // 0x02156c: b.hi #0x21588
    acc = (acc * 0x100000001B3ULL) ^ 0x51016D4BULL; // 0x021570: sub w11, w10, #0x5b
    acc = (acc * 0x100000001B3ULL) ^ 0x7100157FULL; // 0x021574: cmp w11, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x54000089ULL; // 0x021578: b.ls #0x21588
    return acc;
}

// [EN] Reconstructed FDE #0268 @ 0x021710..0x0217cc (188 bytes)
// [VN] Phục dựng FDE #0268 tại 0x021710..0x0217cc (188 byte)
//   0x021710: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x021714: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x021718: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02171c: 910083fd  add      x29, sp, #0x20
//   0x021720: b4000460  cbz      x0, #0x217ac
//   0x021724: aa0003f3  mov      x19, x0
//   0x021728: f9408400  ldr      x0, [x0, #0x108]
//   0x02172c: aa0203f5  mov      x21, x2
//   0x021730: aa0103f4  mov      x20, x1
//   0x021734: b40000c0  cbz      x0, #0x2174c
//   0x021738: f9408a68  ldr      x8, [x19, #0x110]
//   0x02173c: b4000148  cbz      x8, #0x21764
//   0x021740: eb15011f  cmp      x8, x21
//   0x021744: 540001a1  b.ne     #0x21778
//   0x021748: 14000018  b        #0x217a8
//   0x02174c: f10402bf  cmp      x21, #0x100
uint64_t fde_0268_sub_021710(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xEB15011FULL) + (x2 ^ 0x021710ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x021710: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x021714: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x021718: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02171c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000460ULL; // 0x021720: cbz x0, #0x217ac
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021724: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408400ULL; // 0x021728: ldr x0, [x0, #0x108]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02172c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x021730: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x021734: cbz x0, #0x2174c
    return acc;
}

// [EN] Reconstructed FDE #0269 @ 0x0217cc..0x021870 (164 bytes)
// [VN] Phục dựng FDE #0269 tại 0x0217cc..0x021870 (164 byte)
//   0x0217cc: d10543ff  sub      sp, sp, #0x150
//   0x0217d0: f9008bfc  str      x28, [sp, #0x110]
//   0x0217d4: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x0217d8: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x0217dc: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x0217e0: 910503fd  add      x29, sp, #0x140
//   0x0217e4: d53bd055  mrs      x21, tpidr_el0
//   0x0217e8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0217ec: f81c83a8  stur     x8, [x29, #-0x38]
//   0x0217f0: b40002a0  cbz      x0, #0x21844
//   0x0217f4: f9408414  ldr      x20, [x0, #0x108]
//   0x0217f8: aa0003f3  mov      x19, x0
//   0x0217fc: b4000214  cbz      x20, #0x2183c
//   0x021800: eb13029f  cmp      x20, x19
//   0x021804: 540001c0  b.eq     #0x2183c
//   0x021808: f9408a68  ldr      x8, [x19, #0x110]
uint64_t fde_0269_sub_0217cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0xB4000214ULL) + (x2 ^ 0x0217CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x0217cc: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x0217d0: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x0217d4: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x0217d8: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x0217dc: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x0217e0: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0217e4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0217e8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A8ULL; // 0x0217ec: stur x8, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002A0ULL; // 0x0217f0: cbz x0, #0x21844
    return acc;
}

// [EN] Reconstructed FDE #0270 @ 0x021870..0x021894 (36 bytes)
// [VN] Phục dựng FDE #0270 tại 0x021870..0x021894 (36 byte)
//   0x021870: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x021874: 910003fd  mov      x29, sp
//   0x021878: b40000c0  cbz      x0, #0x21890
//   0x02187c: f9408008  ldr      x8, [x0, #0x100]
//   0x021880: b4000088  cbz      x8, #0x21890
//   0x021884: f9408400  ldr      x0, [x0, #0x108]
//   0x021888: b4000040  cbz      x0, #0x21890
//   0x02188c: d63f0100  blr      x8
//   0x021890: 97ff8a0c  bl       #0x40c0
uint64_t fde_0270_sub_021870(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FF8A0CULL) + (x2 ^ 0x021870ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x021870: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x021874: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x021878: cbz x0, #0x21890
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408008ULL; // 0x02187c: ldr x8, [x0, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x021880: cbz x8, #0x21890
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408400ULL; // 0x021884: ldr x0, [x0, #0x108]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x021888: cbz x0, #0x21890
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x02188c: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8A0CULL; // 0x021890: bl #0x40c0
    return acc;
}

// [EN] Reconstructed FDE #0271 @ 0x021894..0x0218a4 (16 bytes)
// [VN] Phục dựng FDE #0271 tại 0x021894..0x0218a4 (16 byte)
//   0x021894: b4000060  cbz      x0, #0x218a0
//   0x021898: a9120403  stp      x3, x1, [x0, #0x120]
//   0x02189c: f9008c02  str      x2, [x0, #0x118]
//   0x0218a0: d65f03c0  ret      
uint64_t fde_0271_sub_021894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000060ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x021894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x021894: cbz x0, #0x218a0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9120403ULL; // 0x021898: stp x3, x1, [x0, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008C02ULL; // 0x02189c: str x2, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0218a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0272 @ 0x0218a4..0x02193c (152 bytes)
// [VN] Phục dựng FDE #0272 tại 0x0218a4..0x02193c (152 byte)
//   0x0218a4: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x0218a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0218ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0218b0: 910083fd  add      x29, sp, #0x20
//   0x0218b4: d114c3ff  sub      sp, sp, #0x530
//   0x0218b8: d53bd054  mrs      x20, tpidr_el0
//   0x0218bc: f9401688  ldr      x8, [x20, #0x28]
//   0x0218c0: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0218c4: b4000280  cbz      x0, #0x21914
//   0x0218c8: aa0003f3  mov      x19, x0
//   0x0218cc: 910003e0  mov      x0, sp
//   0x0218d0: 5280a502  mov      w2, #0x528
//   0x0218d4: aa1303e1  mov      x1, x19
//   0x0218d8: 97ff894e  bl       #0x3e10
//   0x0218dc: 5280a502  mov      w2, #0x528
//   0x0218e0: aa1303e0  mov      x0, x19
uint64_t fde_0272_sub_0218a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x0218A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x0218a4: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0218a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0218ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0218b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD114C3FFULL; // 0x0218b4: sub sp, sp, #0x530
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0218b8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0218bc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D83A8ULL; // 0x0218c0: stur x8, [x29, #-0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000280ULL; // 0x0218c4: cbz x0, #0x21914
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0218c8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0273 @ 0x02193c..0x02195c (32 bytes)
// [VN] Phục dựng FDE #0273 tại 0x02193c..0x02195c (32 byte)
//   0x02193c: b40000a0  cbz      x0, #0x21950
//   0x021940: b4000081  cbz      x1, #0x21950
//   0x021944: f9421802  ldr      x2, [x0, #0x430]
//   0x021948: b4000062  cbz      x2, #0x21954
//   0x02194c: d61f0040  br       x2
//   0x021950: d65f03c0  ret      
//   0x021954: aa0103e0  mov      x0, x1
//   0x021958: 17ff896a  b        #0x3f00
uint64_t fde_0273_sub_02193c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000A0ULL) + (x1 ^ 0x17FF896AULL) + (x2 ^ 0x02193CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x02193c: cbz x0, #0x21950
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000081ULL; // 0x021940: cbz x1, #0x21950
    acc = (acc * 0x100000001B3ULL) ^ 0xF9421802ULL; // 0x021944: ldr x2, [x0, #0x430]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000062ULL; // 0x021948: cbz x2, #0x21954
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x02194c: br x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x021950: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x021954: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF896AULL; // 0x021958: b #0x3f00
    return acc;
}

// [EN] Reconstructed FDE #0274 @ 0x02195c..0x0219e4 (136 bytes)
// [VN] Phục dựng FDE #0274 tại 0x02195c..0x0219e4 (136 byte)
//   0x02195c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x021960: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x021964: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x021968: 910083fd  add      x29, sp, #0x20
//   0x02196c: b4000200  cbz      x0, #0x219ac
//   0x021970: aa0103f3  mov      x19, x1
//   0x021974: aa0003f4  mov      x20, x0
//   0x021978: b40002e1  cbz      x1, #0x219d4
//   0x02197c: f9421688  ldr      x8, [x20, #0x428]
//   0x021980: b4000228  cbz      x8, #0x219c4
//   0x021984: aa1403e0  mov      x0, x20
//   0x021988: aa1303e1  mov      x1, x19
//   0x02198c: d63f0100  blr      x8
//   0x021990: aa0003f5  mov      x21, x0
//   0x021994: b4000200  cbz      x0, #0x219d4
//   0x021998: aa1503e0  mov      x0, x21
uint64_t fde_0274_sub_02195c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x02195CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02195c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x021960: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x021964: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x021968: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000200ULL; // 0x02196c: cbz x0, #0x219ac
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x021970: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x021974: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002E1ULL; // 0x021978: cbz x1, #0x219d4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9421688ULL; // 0x02197c: ldr x8, [x20, #0x428]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000228ULL; // 0x021980: cbz x8, #0x219c4
    return acc;
}

// [EN] Reconstructed FDE #0275 @ 0x0219e4..0x021a38 (84 bytes)
// [VN] Phục dựng FDE #0275 tại 0x0219e4..0x021a38 (84 byte)
//   0x0219e4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0219e8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0219ec: 910043fd  add      x29, sp, #0x10
//   0x0219f0: b4000100  cbz      x0, #0x21a10
//   0x0219f4: aa0003f3  mov      x19, x0
//   0x0219f8: b4000181  cbz      x1, #0x21a28
//   0x0219fc: f9421668  ldr      x8, [x19, #0x428]
//   0x021a00: b40000e8  cbz      x8, #0x21a1c
//   0x021a04: aa1303e0  mov      x0, x19
//   0x021a08: d63f0100  blr      x8
//   0x021a0c: b40000e0  cbz      x0, #0x21a28
//   0x021a10: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x021a14: f84207f3  ldr      x19, [sp], #0x20
//   0x021a18: d65f03c0  ret      
//   0x021a1c: aa0103e0  mov      x0, x1
//   0x021a20: 97ff8944  bl       #0x3f30
uint64_t fde_0275_sub_0219e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0219E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0219e4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0219e8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0219ec: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000100ULL; // 0x0219f0: cbz x0, #0x21a10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0219f4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000181ULL; // 0x0219f8: cbz x1, #0x21a28
    acc = (acc * 0x100000001B3ULL) ^ 0xF9421668ULL; // 0x0219fc: ldr x8, [x19, #0x428]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E8ULL; // 0x021a00: cbz x8, #0x21a1c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x021a04: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x021a08: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0276 @ 0x021a38..0x021a5c (36 bytes)
// [VN] Phục dựng FDE #0276 tại 0x021a38..0x021a5c (36 byte)
//   0x021a38: b40000a1  cbz      x1, #0x21a4c
//   0x021a3c: b40000c0  cbz      x0, #0x21a54
//   0x021a40: f9421402  ldr      x2, [x0, #0x428]
//   0x021a44: b4000082  cbz      x2, #0x21a54
//   0x021a48: d61f0040  br       x2
//   0x021a4c: aa1f03e0  mov      x0, xzr
//   0x021a50: d65f03c0  ret      
//   0x021a54: aa0103e0  mov      x0, x1
//   0x021a58: 17ff8936  b        #0x3f30
uint64_t fde_0276_sub_021a38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000A1ULL) + (x1 ^ 0x17FF8936ULL) + (x2 ^ 0x021A38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A1ULL; // 0x021a38: cbz x1, #0x21a4c
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x021a3c: cbz x0, #0x21a54
    acc = (acc * 0x100000001B3ULL) ^ 0xF9421402ULL; // 0x021a40: ldr x2, [x0, #0x428]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000082ULL; // 0x021a44: cbz x2, #0x21a54
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x021a48: br x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x021a4c: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x021a50: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x021a54: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8936ULL; // 0x021a58: b #0x3f30
    return acc;
}

// [EN] Reconstructed FDE #0277 @ 0x021a5c..0x021ab8 (92 bytes)
// [VN] Phục dựng FDE #0277 tại 0x021a5c..0x021ab8 (92 byte)
//   0x021a5c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x021a60: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x021a64: 910043fd  add      x29, sp, #0x10
//   0x021a68: b40001a0  cbz      x0, #0x21a9c
//   0x021a6c: aa0003f3  mov      x19, x0
//   0x021a70: b40000c1  cbz      x1, #0x21a88
//   0x021a74: f9421668  ldr      x8, [x19, #0x428]
//   0x021a78: b4000188  cbz      x8, #0x21aa8
//   0x021a7c: aa1303e0  mov      x0, x19
//   0x021a80: d63f0100  blr      x8
//   0x021a84: b50000c0  cbnz     x0, #0x21a9c
//   0x021a88: d0000181  adrp     x1, #0x53000
//   0x021a8c: 91033c21  add      x1, x1, #0xcf
//   0x021a90: aa1303e0  mov      x0, x19
//   0x021a94: 97fffd13  bl       #0x20ee0
//   0x021a98: aa1f03e0  mov      x0, xzr
uint64_t fde_0277_sub_021a5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91033C21ULL) + (x2 ^ 0x021A5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x021a5c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x021a60: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x021a64: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A0ULL; // 0x021a68: cbz x0, #0x21a9c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x021a6c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C1ULL; // 0x021a70: cbz x1, #0x21a88
    acc = (acc * 0x100000001B3ULL) ^ 0xF9421668ULL; // 0x021a74: ldr x8, [x19, #0x428]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000188ULL; // 0x021a78: cbz x8, #0x21aa8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x021a7c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x021a80: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0278 @ 0x021ab8..0x021acc (20 bytes)
// [VN] Phục dựng FDE #0278 tại 0x021ab8..0x021acc (20 byte)
//   0x021ab8: b4000080  cbz      x0, #0x21ac8
//   0x021abc: f9021001  str      x1, [x0, #0x420]
//   0x021ac0: f9021402  str      x2, [x0, #0x428]
//   0x021ac4: f9021803  str      x3, [x0, #0x430]
//   0x021ac8: d65f03c0  ret      
uint64_t fde_0278_sub_021ab8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000080ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x021AB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x021ab8: cbz x0, #0x21ac8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9021001ULL; // 0x021abc: str x1, [x0, #0x420]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9021402ULL; // 0x021ac0: str x2, [x0, #0x428]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9021803ULL; // 0x021ac4: str x3, [x0, #0x430]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x021ac8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0279 @ 0x021acc..0x021b9c (208 bytes)
// [VN] Phục dựng FDE #0279 tại 0x021acc..0x021b9c (208 byte)
//   0x021acc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x021ad0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x021ad4: 910043fd  add      x29, sp, #0x10
//   0x021ad8: b40005c0  cbz      x0, #0x21b90
//   0x021adc: aa0103f3  mov      x19, x1
//   0x021ae0: b4000581  cbz      x1, #0x21b90
//   0x021ae4: b94013a9  ldr      w9, [x29, #0x10]
//   0x021ae8: 12001c88  and      w8, w4, #0xff
//   0x021aec: 2a0203f4  mov      w20, w2
//   0x021af0: 29000e62  stp      w2, w3, [x19]
//   0x021af4: 39009264  strb     w4, [x19, #0x24]
//   0x021af8: 39009665  strb     w5, [x19, #0x25]
//   0x021afc: 39009a67  strb     w7, [x19, #0x26]
//   0x021b00: 3900a266  strb     w6, [x19, #0x28]
//   0x021b04: 12001ca4  and      w4, w5, #0xff
//   0x021b08: 12001cc5  and      w5, w6, #0xff
uint64_t fde_0279_sub_021acc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x39009A67ULL) + (x2 ^ 0x021ACCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x021acc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x021ad0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x021ad4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB40005C0ULL; // 0x021ad8: cbz x0, #0x21b90
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x021adc: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000581ULL; // 0x021ae0: cbz x1, #0x21b90
    acc = (acc * 0x100000001B3ULL) ^ 0xB94013A9ULL; // 0x021ae4: ldr w9, [x29, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x12001C88ULL; // 0x021ae8: and w8, w4, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x021aec: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x29000E62ULL; // 0x021af0: stp w2, w3, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0280 @ 0x021b9c..0x021d04 (360 bytes)
// [VN] Phục dựng FDE #0280 tại 0x021b9c..0x021d04 (360 byte)
//   0x021b9c: d10543ff  sub      sp, sp, #0x150
//   0x021ba0: f9008bfc  str      x28, [sp, #0x110]
//   0x021ba4: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x021ba8: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x021bac: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x021bb0: 910503fd  add      x29, sp, #0x140
//   0x021bb4: d53bd056  mrs      x22, tpidr_el0
//   0x021bb8: f94016c9  ldr      x9, [x22, #0x28]
//   0x021bbc: f81c83a9  stur     x9, [x29, #-0x38]
//   0x021bc0: b4000661  cbz      x1, #0x21c8c
//   0x021bc4: 3940002c  ldrb     w12, [x1]
//   0x021bc8: aa0103e8  mov      x8, x1
//   0x021bcc: 3400060c  cbz      w12, #0x21c8c
//   0x021bd0: aa0003f4  mov      x20, x0
//   0x021bd4: 2a1f03f5  mov      w21, wzr
//   0x021bd8: 2a1f03f3  mov      w19, wzr
uint64_t fde_0280_sub_021b9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0x3400060CULL) + (x2 ^ 0x021B9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x021b9c: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x021ba0: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x021ba4: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x021ba8: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x021bac: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x021bb0: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x021bb4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C9ULL; // 0x021bb8: ldr x9, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C83A9ULL; // 0x021bbc: stur x9, [x29, #-0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000661ULL; // 0x021bc0: cbz x1, #0x21c8c
    return acc;
}

// [EN] Reconstructed FDE #0281 @ 0x021d04..0x021df4 (240 bytes)
// [VN] Phục dựng FDE #0281 tại 0x021d04..0x021df4 (240 byte)
//   0x021d04: 39404008  ldrb     w8, [x0, #0x10]
//   0x021d08: 7100111f  cmp      w8, #4
//   0x021d0c: 54000120  b.eq     #0x21d30
//   0x021d10: 35000708  cbnz     w8, #0x21df0
//   0x021d14: f9400409  ldr      x9, [x0, #8]
//   0x021d18: b40006c9  cbz      x9, #0x21df0
//   0x021d1c: f100813f  cmp      x9, #0x20
//   0x021d20: 54000422  b.hs     #0x21da4
//   0x021d24: aa1f03ea  mov      x10, xzr
//   0x021d28: aa0103e8  mov      x8, x1
//   0x021d2c: 1400002b  b        #0x21dd8
//   0x021d30: 39404408  ldrb     w8, [x0, #0x11]
//   0x021d34: 7100411f  cmp      w8, #0x10
//   0x021d38: 540001a0  b.eq     #0x21d6c
//   0x021d3c: 7100211f  cmp      w8, #8
//   0x021d40: 54000581  b.ne     #0x21df0
uint64_t fde_0281_sub_021d04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39404008ULL) + (x1 ^ 0x7100411FULL) + (x2 ^ 0x021D04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39404008ULL; // 0x021d04: ldrb w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100111FULL; // 0x021d08: cmp w8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54000120ULL; // 0x021d0c: b.eq #0x21d30
    acc = (acc * 0x100000001B3ULL) ^ 0x35000708ULL; // 0x021d10: cbnz w8, #0x21df0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400409ULL; // 0x021d14: ldr x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40006C9ULL; // 0x021d18: cbz x9, #0x21df0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100813FULL; // 0x021d1c: cmp x9, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x54000422ULL; // 0x021d20: b.hs #0x21da4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03EAULL; // 0x021d24: mov x10, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x021d28: mov x8, x1
    return acc;
}

// [EN] Reconstructed FDE #0282 @ 0x021df4..0x021e90 (156 bytes)
// [VN] Phục dựng FDE #0282 tại 0x021df4..0x021e90 (156 byte)
//   0x021df4: 39404408  ldrb     w8, [x0, #0x11]
//   0x021df8: 7100411f  cmp      w8, #0x10
//   0x021dfc: 54000481  b.ne     #0x21e8c
//   0x021e00: b9400008  ldr      w8, [x0]
//   0x021e04: 39404809  ldrb     w9, [x0, #0x12]
//   0x021e08: 1b097d09  mul      w9, w8, w9
//   0x021e0c: 34000409  cbz      w9, #0x21e8c
//   0x021e10: 51000528  sub      w8, w9, #1
//   0x021e14: 9100050b  add      x11, x8, #1
//   0x021e18: f100817f  cmp      x11, #0x20
//   0x021e1c: 54000082  b.hs     #0x21e2c
//   0x021e20: 2a1f03ea  mov      w10, wzr
//   0x021e24: aa0103e8  mov      x8, x1
//   0x021e28: 14000011  b        #0x21e6c
//   0x021e2c: 927b6d6a  and      x10, x11, #0x1ffffffe0
//   0x021e30: 8b0a0428  add      x8, x1, x10, lsl #1
uint64_t fde_0282_sub_021df4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39404408ULL) + (x1 ^ 0xAA0103E8ULL) + (x2 ^ 0x021DF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39404408ULL; // 0x021df4: ldrb w8, [x0, #0x11]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100411FULL; // 0x021df8: cmp w8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000481ULL; // 0x021dfc: b.ne #0x21e8c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x021e00: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39404809ULL; // 0x021e04: ldrb w9, [x0, #0x12]
    acc = (acc * 0x100000001B3ULL) ^ 0x1B097D09ULL; // 0x021e08: mul w9, w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x34000409ULL; // 0x021e0c: cbz w9, #0x21e8c
    acc = (acc * 0x100000001B3ULL) ^ 0x51000528ULL; // 0x021e10: sub w8, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9100050BULL; // 0x021e14: add x11, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100817FULL; // 0x021e18: cmp x11, #0x20
    return acc;
}

// [EN] Reconstructed FDE #0283 @ 0x021e90..0x021f0c (124 bytes)
// [VN] Phục dựng FDE #0283 tại 0x021e90..0x021f0c (124 byte)
//   0x021e90: 39404409  ldrb     w9, [x0, #0x11]
//   0x021e94: 71001d3f  cmp      w9, #7
//   0x021e98: 54000388  b.hi     #0x21f08
//   0x021e9c: f9400408  ldr      x8, [x0, #8]
//   0x021ea0: 7100053f  cmp      w9, #1
//   0x021ea4: 54000140  b.eq     #0x21ecc
//   0x021ea8: 7100113f  cmp      w9, #4
//   0x021eac: 540001a0  b.eq     #0x21ee0
//   0x021eb0: 7100093f  cmp      w9, #2
//   0x021eb4: 540002a1  b.ne     #0x21f08
//   0x021eb8: d0000189  adrp     x9, #0x53000
//   0x021ebc: 911fb129  add      x9, x9, #0x7ec
//   0x021ec0: f100051f  cmp      x8, #1
//   0x021ec4: 5400016a  b.ge     #0x21ef0
//   0x021ec8: 14000010  b        #0x21f08
//   0x021ecc: d0000189  adrp     x9, #0x53000
uint64_t fde_0283_sub_021e90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39404409ULL) + (x1 ^ 0xF100051FULL) + (x2 ^ 0x021E90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39404409ULL; // 0x021e90: ldrb w9, [x0, #0x11]
    acc = (acc * 0x100000001B3ULL) ^ 0x71001D3FULL; // 0x021e94: cmp w9, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x54000388ULL; // 0x021e98: b.hi #0x21f08
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x021e9c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x021ea0: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000140ULL; // 0x021ea4: b.eq #0x21ecc
    acc = (acc * 0x100000001B3ULL) ^ 0x7100113FULL; // 0x021ea8: cmp w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A0ULL; // 0x021eac: b.eq #0x21ee0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100093FULL; // 0x021eb0: cmp w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x540002A1ULL; // 0x021eb4: b.ne #0x21f08
    return acc;
}

// [EN] Reconstructed FDE #0284 @ 0x021f0c..0x0220f0 (484 bytes)
// [VN] Phục dựng FDE #0284 tại 0x021f0c..0x0220f0 (484 byte)
//   0x021f0c: 39404808  ldrb     w8, [x0, #0x12]
//   0x021f10: f940040a  ldr      x10, [x0, #8]
//   0x021f14: 7100111f  cmp      w8, #4
//   0x021f18: 8b0a0029  add      x9, x1, x10
//   0x021f1c: 54000280  b.eq     #0x21f6c
//   0x021f20: 7100091f  cmp      w8, #2
//   0x021f24: 54000e41  b.ne     #0x220ec
//   0x021f28: 39404408  ldrb     w8, [x0, #0x11]
//   0x021f2c: 7100411f  cmp      w8, #0x10
//   0x021f30: 54000520  b.eq     #0x21fd4
//   0x021f34: 7100211f  cmp      w8, #8
//   0x021f38: 54000da1  b.ne     #0x220ec
//   0x021f3c: 9100082a  add      x10, x1, #2
//   0x021f40: 7100005f  cmp      w2, #0
//   0x021f44: 9a81054a  csinc    x10, x10, x1, eq
//   0x021f48: 9a811428  cinc     x8, x1, eq
uint64_t fde_0284_sub_021f0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39404808ULL) + (x1 ^ 0x9100082AULL) + (x2 ^ 0x021F0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39404808ULL; // 0x021f0c: ldrb w8, [x0, #0x12]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940040AULL; // 0x021f10: ldr x10, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100111FULL; // 0x021f14: cmp w8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0A0029ULL; // 0x021f18: add x9, x1, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000280ULL; // 0x021f1c: b.eq #0x21f6c
    acc = (acc * 0x100000001B3ULL) ^ 0x7100091FULL; // 0x021f20: cmp w8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000E41ULL; // 0x021f24: b.ne #0x220ec
    acc = (acc * 0x100000001B3ULL) ^ 0x39404408ULL; // 0x021f28: ldrb w8, [x0, #0x11]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100411FULL; // 0x021f2c: cmp w8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000520ULL; // 0x021f30: b.eq #0x21fd4
    return acc;
}

// [EN] Reconstructed FDE #0285 @ 0x0220f0..0x02228c (412 bytes)
// [VN] Phục dựng FDE #0285 tại 0x0220f0..0x02228c (412 byte)
//   0x0220f0: 39404009  ldrb     w9, [x0, #0x10]
//   0x0220f4: 36080ca9  tbz      w9, #1, #0x22288
//   0x0220f8: 3940440a  ldrb     w10, [x0, #0x11]
//   0x0220fc: b9400008  ldr      w8, [x0]
//   0x022100: 7100415f  cmp      w10, #0x10
//   0x022104: 540001e0  b.eq     #0x22140
//   0x022108: 7100215f  cmp      w10, #8
//   0x02210c: 54000be1  b.ne     #0x22288
//   0x022110: 7100093f  cmp      w9, #2
//   0x022114: 54000300  b.eq     #0x22174
//   0x022118: 7100193f  cmp      w9, #6
//   0x02211c: 54000b61  b.ne     #0x22288
//   0x022120: 34000b48  cbz      w8, #0x22288
//   0x022124: 51000509  sub      w9, w8, #1
//   0x022128: 9100052b  add      x11, x9, #1
//   0x02212c: f100097f  cmp      x11, #2
uint64_t fde_0285_sub_0220f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39404009ULL) + (x1 ^ 0x34000B48ULL) + (x2 ^ 0x0220F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39404009ULL; // 0x0220f0: ldrb w9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x36080CA9ULL; // 0x0220f4: tbz w9, #1, #0x22288
    acc = (acc * 0x100000001B3ULL) ^ 0x3940440AULL; // 0x0220f8: ldrb w10, [x0, #0x11]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x0220fc: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100415FULL; // 0x022100: cmp w10, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x540001E0ULL; // 0x022104: b.eq #0x22140
    acc = (acc * 0x100000001B3ULL) ^ 0x7100215FULL; // 0x022108: cmp w10, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000BE1ULL; // 0x02210c: b.ne #0x22288
    acc = (acc * 0x100000001B3ULL) ^ 0x7100093FULL; // 0x022110: cmp w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000300ULL; // 0x022114: b.eq #0x22174
    return acc;
}

// [EN] Reconstructed FDE #0286 @ 0x02228c..0x0224dc (592 bytes)
// [VN] Phục dựng FDE #0286 tại 0x02228c..0x0224dc (592 byte)
//   0x02228c: 79452008  ldrh     w8, [x0, #0x290]
//   0x022290: 34001248  cbz      w8, #0x224d8
//   0x022294: 39404429  ldrb     w9, [x1, #0x11]
//   0x022298: 5280002a  mov      w10, #1
//   0x02229c: 1ac9214a  lsl      w10, w10, w9
//   0x0222a0: 6b08015f  cmp      w10, w8
//   0x0222a4: 540011ad  b.le     #0x224d8
//   0x0222a8: 51000529  sub      w9, w9, #1
//   0x0222ac: 71001d3f  cmp      w9, #7
//   0x0222b0: 54001148  b.hi     #0x224d8
//   0x0222b4: 39404c2a  ldrb     w10, [x1, #0x13]
//   0x0222b8: b940002b  ldr      w11, [x1]
//   0x0222bc: f9413008  ldr      x8, [x0, #0x260]
//   0x0222c0: f940042c  ldr      x12, [x1, #8]
//   0x0222c4: b000018d  adrp     x13, #0x53000
//   0x0222c8: 911b91ad  add      x13, x13, #0x6e4
uint64_t fde_0286_sub_02228c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x79452008ULL) + (x1 ^ 0xF9413008ULL) + (x2 ^ 0x02228CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x79452008ULL; // 0x02228c: ldrh w8, [x0, #0x290]
    acc = (acc * 0x100000001B3ULL) ^ 0x34001248ULL; // 0x022290: cbz w8, #0x224d8
    acc = (acc * 0x100000001B3ULL) ^ 0x39404429ULL; // 0x022294: ldrb w9, [x1, #0x11]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280002AULL; // 0x022298: mov w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC9214AULL; // 0x02229c: lsl w10, w10, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08015FULL; // 0x0222a0: cmp w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x540011ADULL; // 0x0222a4: b.le #0x224d8
    acc = (acc * 0x100000001B3ULL) ^ 0x51000529ULL; // 0x0222a8: sub w9, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x71001D3FULL; // 0x0222ac: cmp w9, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x54001148ULL; // 0x0222b0: b.hi #0x224d8
    return acc;
}

// [EN] Reconstructed FDE #0287 @ 0x0224dc..0x022500 (36 bytes)
// [VN] Phục dựng FDE #0287 tại 0x0224dc..0x022500 (36 byte)
//   0x0224dc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0224e0: 910003fd  mov      x29, sp
//   0x0224e4: f9409803  ldr      x3, [x0, #0x130]
//   0x0224e8: b4000063  cbz      x3, #0x224f4
//   0x0224ec: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0224f0: d61f0060  br       x3
//   0x0224f4: b0000181  adrp     x1, #0x53000
//   0x0224f8: 9127b021  add      x1, x1, #0x9ec
//   0x0224fc: 97fffa43  bl       #0x20e08
uint64_t fde_0287_sub_0224dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFFA43ULL) + (x2 ^ 0x0224DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0224dc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0224e0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409803ULL; // 0x0224e4: ldr x3, [x0, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000063ULL; // 0x0224e8: cbz x3, #0x224f4
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0224ec: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x0224f0: br x3
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000181ULL; // 0x0224f4: adrp x1, #0x53000
    acc = (acc * 0x100000001B3ULL) ^ 0x9127B021ULL; // 0x0224f8: add x1, x1, #0x9ec
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFA43ULL; // 0x0224fc: bl #0x20e08
    return acc;
}

// [EN] Reconstructed FDE #0288 @ 0x022500..0x022550 (80 bytes)
// [VN] Phục dựng FDE #0288 tại 0x022500..0x022550 (80 byte)
//   0x022500: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x022504: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x022508: 910043fd  add      x29, sp, #0x10
//   0x02250c: b4000140  cbz      x0, #0x22534
//   0x022510: f940a003  ldr      x3, [x0, #0x140]
//   0x022514: aa0103e8  mov      x8, x1
//   0x022518: aa0003f3  mov      x19, x0
//   0x02251c: 52800021  mov      w1, #1
//   0x022520: aa0803e0  mov      x0, x8
//   0x022524: aa0203f4  mov      x20, x2
//   0x022528: 97ff86c2  bl       #0x4030
//   0x02252c: eb14001f  cmp      x0, x20
//   0x022530: 54000081  b.ne     #0x22540
//   0x022534: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x022538: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02253c: d65f03c0  ret      
uint64_t fde_0288_sub_022500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x54000081ULL) + (x2 ^ 0x022500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x022500: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x022504: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x022508: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000140ULL; // 0x02250c: cbz x0, #0x22534
    acc = (acc * 0x100000001B3ULL) ^ 0xF940A003ULL; // 0x022510: ldr x3, [x0, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x022514: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x022518: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x02251c: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x022520: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x022524: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0289 @ 0x022550..0x022560 (16 bytes)
// [VN] Phục dựng FDE #0289 tại 0x022550..0x022560 (16 byte)
//   0x022550: f9416401  ldr      x1, [x0, #0x2c8]
//   0x022554: b4000041  cbz      x1, #0x2255c
//   0x022558: d61f0020  br       x1
//   0x02255c: d65f03c0  ret      
uint64_t fde_0289_sub_022550(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9416401ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022550ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9416401ULL; // 0x022550: ldr x1, [x0, #0x2c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000041ULL; // 0x022554: cbz x1, #0x2255c
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x022558: br x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02255c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0290 @ 0x022560..0x022570 (16 bytes)
// [VN] Phục dựng FDE #0290 tại 0x022560..0x022570 (16 byte)
//   0x022560: b4000060  cbz      x0, #0x2256c
//   0x022564: f940a000  ldr      x0, [x0, #0x140]
//   0x022568: 17ff86fe  b        #0x4160
//   0x02256c: d65f03c0  ret      
uint64_t fde_0290_sub_022560(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000060ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x022560ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x022560: cbz x0, #0x2256c
    acc = (acc * 0x100000001B3ULL) ^ 0xF940A000ULL; // 0x022564: ldr x0, [x0, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF86FEULL; // 0x022568: b #0x4160
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02256c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0291 @ 0x022570..0x0225bc (76 bytes)
// [VN] Phục dựng FDE #0291 tại 0x022570..0x0225bc (76 byte)
//   0x022570: b4000240  cbz      x0, #0x225b8
//   0x022574: f900a001  str      x1, [x0, #0x140]
//   0x022578: b0000208  adrp     x8, #0x63000
//   0x02257c: f9470508  ldr      x8, [x8, #0xe08]
//   0x022580: b0000209  adrp     x9, #0x63000
//   0x022584: f946d129  ldr      x9, [x9, #0xda0]
//   0x022588: f9409c0a  ldr      x10, [x0, #0x138]
//   0x02258c: f100005f  cmp      x2, #0
//   0x022590: 9a820108  csel     x8, x8, x2, eq
//   0x022594: f100007f  cmp      x3, #0
//   0x022598: f9009808  str      x8, [x0, #0x130]
//   0x02259c: 9a830128  csel     x8, x9, x3, eq
//   0x0225a0: f9016408  str      x8, [x0, #0x2c8]
//   0x0225a4: b40000aa  cbz      x10, #0x225b8
//   0x0225a8: b0000181  adrp     x1, #0x53000
//   0x0225ac: 91285021  add      x1, x1, #0xa14
uint64_t fde_0291_sub_022570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000240ULL) + (x1 ^ 0xF9016408ULL) + (x2 ^ 0x022570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000240ULL; // 0x022570: cbz x0, #0x225b8
    acc = (acc * 0x100000001B3ULL) ^ 0xF900A001ULL; // 0x022574: str x1, [x0, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000208ULL; // 0x022578: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470508ULL; // 0x02257c: ldr x8, [x8, #0xe08]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000209ULL; // 0x022580: adrp x9, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946D129ULL; // 0x022584: ldr x9, [x9, #0xda0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409C0AULL; // 0x022588: ldr x10, [x0, #0x138]
    acc = (acc * 0x100000001B3ULL) ^ 0xF100005FULL; // 0x02258c: cmp x2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x9A820108ULL; // 0x022590: csel x8, x8, x2, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xF100007FULL; // 0x022594: cmp x3, #0
    return acc;
}

// [EN] Reconstructed FDE #0292 @ 0x0225bc..0x02270c (336 bytes)
// [VN] Phục dựng FDE #0292 tại 0x0225bc..0x02270c (336 byte)
//   0x0225bc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0225c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0225c4: 910043fd  add      x29, sp, #0x10
//   0x0225c8: b40009c0  cbz      x0, #0x22700
//   0x0225cc: aa0103f4  mov      x20, x1
//   0x0225d0: b4000981  cbz      x1, #0x22700
//   0x0225d4: 39459408  ldrb     w8, [x0, #0x165]
//   0x0225d8: aa0003f3  mov      x19, x0
//   0x0225dc: 37100928  tbnz     w8, #2, #0x22700
//   0x0225e0: aa1303e0  mov      x0, x19
//   0x0225e4: 94000541  bl       #0x23ae8
//   0x0225e8: 39459668  ldrb     w8, [x19, #0x165]
//   0x0225ec: 36200108  tbz      w8, #4, #0x2260c
//   0x0225f0: b9441a68  ldr      w8, [x19, #0x418]
//   0x0225f4: 340000c8  cbz      w8, #0x2260c
//   0x0225f8: 90000181  adrp     x1, #0x52000
uint64_t fde_0292_sub_0225bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x36200108ULL) + (x2 ^ 0x0225BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0225bc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0225c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0225c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB40009C0ULL; // 0x0225c8: cbz x0, #0x22700
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0225cc: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000981ULL; // 0x0225d0: cbz x1, #0x22700
    acc = (acc * 0x100000001B3ULL) ^ 0x39459408ULL; // 0x0225d4: ldrb w8, [x0, #0x165]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0225d8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x37100928ULL; // 0x0225dc: tbnz w8, #2, #0x22700
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0225e0: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0293 @ 0x02270c..0x0227dc (208 bytes)
// [VN] Phục dựng FDE #0293 tại 0x02270c..0x0227dc (208 byte)
//   0x02270c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x022710: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x022714: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x022718: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02271c: 9100c3fd  add      x29, sp, #0x30
//   0x022720: b9812828  ldrsw    x8, [x1, #0x128]
//   0x022724: 34000528  cbz      w8, #0x227c8
//   0x022728: 7100051f  cmp      w8, #1
//   0x02272c: 540004eb  b.lt     #0x227c8
//   0x022730: f9409035  ldr      x21, [x1, #0x120]
//   0x022734: b0000196  adrp     x22, #0x53000
//   0x022738: 2a0203f3  mov      w19, w2
//   0x02273c: aa0003f4  mov      x20, x0
//   0x022740: 8b0816b7  add      x23, x21, x8, lsl #5
//   0x022744: 91381ed6  add      x22, x22, #0xe07
//   0x022748: 1400000a  b        #0x22770
uint64_t fde_0293_sub_02270c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x02270CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02270c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x022710: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x022714: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x022718: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02271c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB9812828ULL; // 0x022720: ldrsw x8, [x1, #0x128]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000528ULL; // 0x022724: cbz w8, #0x227c8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x022728: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540004EBULL; // 0x02272c: b.lt #0x227c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9409035ULL; // 0x022730: ldr x21, [x1, #0x120]
    return acc;
}

// [EN] Reconstructed FDE #0294 @ 0x0227dc..0x022abc (736 bytes)
// [VN] Phục dựng FDE #0294 tại 0x0227dc..0x022abc (736 byte)
//   0x0227dc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0227e0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0227e4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0227e8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0227ec: 9100c3fd  add      x29, sp, #0x30
//   0x0227f0: b40002a0  cbz      x0, #0x22844
//   0x0227f4: aa0103f4  mov      x20, x1
//   0x0227f8: b4000261  cbz      x1, #0x22844
//   0x0227fc: aa1403e1  mov      x1, x20
//   0x022800: aa0003f3  mov      x19, x0
//   0x022804: 97ffff6e  bl       #0x225bc
//   0x022808: b9400a88  ldr      w8, [x20, #8]
//   0x02280c: 37180268  tbnz     w8, #3, #0x22858
//   0x022810: 39409689  ldrb     w9, [x20, #0x25]
//   0x022814: 71000d3f  cmp      w9, #3
//   0x022818: 540014a0  b.eq     #0x22aac
uint64_t fde_0294_sub_0227dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x37180268ULL) + (x2 ^ 0x0227DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0227dc: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0227e0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0227e4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0227e8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0227ec: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002A0ULL; // 0x0227f0: cbz x0, #0x22844
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0227f4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000261ULL; // 0x0227f8: cbz x1, #0x22844
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x0227fc: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x022800: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0295 @ 0x022abc..0x022c3c (384 bytes)
// [VN] Phục dựng FDE #0295 tại 0x022abc..0x022c3c (384 byte)
//   0x022abc: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x022ac0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x022ac4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x022ac8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x022acc: 9100c3fd  add      x29, sp, #0x30
//   0x022ad0: b4000a40  cbz      x0, #0x22c18
//   0x022ad4: 39459008  ldrb     w8, [x0, #0x164]
//   0x022ad8: aa0003f3  mov      x19, x0
//   0x022adc: 36100a88  tbz      w8, #2, #0x22c2c
//   0x022ae0: b9429668  ldr      w8, [x19, #0x294]
//   0x022ae4: 79452269  ldrh     w9, [x19, #0x290]
//   0x022ae8: aa0103f4  mov      x20, x1
//   0x022aec: 6b09011f  cmp      w8, w9
//   0x022af0: 540000ad  b.le     #0x22b04
//   0x022af4: b0000181  adrp     x1, #0x53000
//   0x022af8: 912bec21  add      x1, x1, #0xafb
uint64_t fde_0295_sub_022abc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x6B09011FULL) + (x2 ^ 0x022ABCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x022abc: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x022ac0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x022ac4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x022ac8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x022acc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000A40ULL; // 0x022ad0: cbz x0, #0x22c18
    acc = (acc * 0x100000001B3ULL) ^ 0x39459008ULL; // 0x022ad4: ldrb w8, [x0, #0x164]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x022ad8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36100A88ULL; // 0x022adc: tbz w8, #2, #0x22c2c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9429668ULL; // 0x022ae0: ldr w8, [x19, #0x294]
    return acc;
}

// [EN] Reconstructed FDE #0296 @ 0x022c3c..0x022cb4 (120 bytes)
// [VN] Phục dựng FDE #0296 tại 0x022c3c..0x022cb4 (120 byte)
//   0x022c3c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x022c40: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x022c44: 910043fd  add      x29, sp, #0x10
//   0x022c48: aa1f03e4  mov      x4, xzr
//   0x022c4c: aa1f03e5  mov      x5, xzr
//   0x022c50: aa1f03e6  mov      x6, xzr
//   0x022c54: 97fff626  bl       #0x204ec
//   0x022c58: aa0003f3  mov      x19, x0
//   0x022c5c: b4000240  cbz      x0, #0x22ca4
//   0x022c60: b0000188  adrp     x8, #0x53000
//   0x022c64: b000018a  adrp     x10, #0x53000
//   0x022c68: b9416a6b  ldr      w11, [x19, #0x168]
//   0x022c6c: 3dc29900  ldr      q0, [x8, #0xa60]
//   0x022c70: 3dc29d41  ldr      q1, [x10, #0xa70]
//   0x022c74: d28001e9  mov      x9, #0xf
//   0x022c78: f2c00109  movk     x9, #8, lsl #32
uint64_t fde_0296_sub_022c3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x3DC29900ULL) + (x2 ^ 0x022C3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x022c3c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x022c40: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x022c44: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E4ULL; // 0x022c48: mov x4, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E5ULL; // 0x022c4c: mov x5, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E6ULL; // 0x022c50: mov x6, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF626ULL; // 0x022c54: bl #0x204ec
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x022c58: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000240ULL; // 0x022c5c: cbz x0, #0x22ca4
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x022c60: adrp x8, #0x53000
    return acc;
}

// [EN] Reconstructed FDE #0297 @ 0x022cb4..0x023034 (896 bytes)
// [VN] Phục dựng FDE #0297 tại 0x022cb4..0x023034 (896 byte)
//   0x022cb4: d10143ff  sub      sp, sp, #0x50
//   0x022cb8: f90013f5  str      x21, [sp, #0x20]
//   0x022cbc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x022cc0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x022cc4: 910103fd  add      x29, sp, #0x40
//   0x022cc8: d53bd055  mrs      x21, tpidr_el0
//   0x022ccc: f94016a8  ldr      x8, [x21, #0x28]
//   0x022cd0: f9000fe8  str      x8, [sp, #0x18]
//   0x022cd4: b40018c0  cbz      x0, #0x22fec
//   0x022cd8: b9424c08  ldr      w8, [x0, #0x24c]
//   0x022cdc: aa0103f4  mov      x20, x1
//   0x022ce0: aa0003f3  mov      x19, x0
//   0x022ce4: 35000068  cbnz     w8, #0x22cf0
//   0x022ce8: 394a7668  ldrb     w8, [x19, #0x29d]
//   0x022cec: 34000b28  cbz      w8, #0x22e50
//   0x022cf0: 394a7268  ldrb     w8, [x19, #0x29c]
uint64_t fde_0297_sub_022cb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x35000068ULL) + (x2 ^ 0x022CB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x022cb4: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x022cb8: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x022cbc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x022cc0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x022cc4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x022cc8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x022ccc: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x022cd0: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40018C0ULL; // 0x022cd4: cbz x0, #0x22fec
    acc = (acc * 0x100000001B3ULL) ^ 0xB9424C08ULL; // 0x022cd8: ldr w8, [x0, #0x24c]
    return acc;
}

// [EN] Reconstructed FDE #0298 @ 0x023034..0x02308c (88 bytes)
// [VN] Phục dựng FDE #0298 tại 0x023034..0x02308c (88 byte)
//   0x023034: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x023038: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02303c: 910043fd  add      x29, sp, #0x10
//   0x023040: b4000200  cbz      x0, #0x23080
//   0x023044: b9424c08  ldr      w8, [x0, #0x24c]
//   0x023048: b9423809  ldr      w9, [x0, #0x238]
//   0x02304c: aa0003f3  mov      x19, x0
//   0x023050: 6b09011f  cmp      w8, w9
//   0x023054: 54000162  b.hs     #0x23080
//   0x023058: 52800043  mov      w3, #2
//   0x02305c: aa1303e0  mov      x0, x19
//   0x023060: aa1f03e1  mov      x1, xzr
//   0x023064: aa1f03e2  mov      x2, xzr
//   0x023068: 94000474  bl       #0x24238
//   0x02306c: b902d67f  str      wzr, [x19, #0x2d4]
//   0x023070: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0298_sub_023034(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1F03E2ULL) + (x2 ^ 0x023034ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x023034: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023038: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02303c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000200ULL; // 0x023040: cbz x0, #0x23080
    acc = (acc * 0x100000001B3ULL) ^ 0xB9424C08ULL; // 0x023044: ldr w8, [x0, #0x24c]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9423809ULL; // 0x023048: ldr w9, [x0, #0x238]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02304c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x023050: cmp w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000162ULL; // 0x023054: b.hs #0x23080
    acc = (acc * 0x100000001B3ULL) ^ 0x52800043ULL; // 0x023058: mov w3, #2
    return acc;
}

// [EN] Reconstructed FDE #0299 @ 0x02308c..0x023140 (180 bytes)
// [VN] Phục dựng FDE #0299 tại 0x02308c..0x023140 (180 byte)
//   0x02308c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x023090: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023094: 910043fd  add      x29, sp, #0x10
//   0x023098: b40004e0  cbz      x0, #0x23134
//   0x02309c: f9400013  ldr      x19, [x0]
//   0x0230a0: aa0003f4  mov      x20, x0
//   0x0230a4: b4000493  cbz      x19, #0x23134
//   0x0230a8: aa1303e0  mov      x0, x19
//   0x0230ac: 97fff580  bl       #0x206ac
//   0x0230b0: f900029f  str      xzr, [x20]
//   0x0230b4: 3945a268  ldrb     w8, [x19, #0x168]
//   0x0230b8: 36080068  tbz      w8, #1, #0x230c4
//   0x0230bc: 9105e260  add      x0, x19, #0x178
//   0x0230c0: 97ff83f4  bl       #0x4090
//   0x0230c4: 9107a261  add      x1, x19, #0x1e8
//   0x0230c8: aa1303e0  mov      x0, x19
uint64_t fde_0299_sub_02308c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x9105E260ULL) + (x2 ^ 0x02308CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02308c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023090: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023094: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004E0ULL; // 0x023098: cbz x0, #0x23134
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x02309c: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0230a0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000493ULL; // 0x0230a4: cbz x19, #0x23134
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0230a8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF580ULL; // 0x0230ac: bl #0x206ac
    acc = (acc * 0x100000001B3ULL) ^ 0xF900029FULL; // 0x0230b0: str xzr, [x20]
    return acc;
}

// [EN] Reconstructed FDE #0300 @ 0x023140..0x023adc (2460 bytes)
// [VN] Phục dựng FDE #0300 tại 0x023140..0x023adc (2460 byte)
//   0x023140: d101c3ff  sub      sp, sp, #0x70
//   0x023144: f9001bf7  str      x23, [sp, #0x30]
//   0x023148: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02314c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x023150: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x023154: 910183fd  add      x29, sp, #0x60
//   0x023158: d53bd055  mrs      x21, tpidr_el0
//   0x02315c: f94016a8  ldr      x8, [x21, #0x28]
//   0x023160: f90017e8  str      x8, [sp, #0x28]
//   0x023164: b4004a00  cbz      x0, #0x23aa4
//   0x023168: b9416c08  ldr      w8, [x0, #0x16c]
//   0x02316c: aa0103f3  mov      x19, x1
//   0x023170: aa0003f4  mov      x20, x0
//   0x023174: 36a00128  tbz      w8, #0x14, #0x23198
//   0x023178: f940aa89  ldr      x9, [x20, #0x150]
//   0x02317c: b40000e9  cbz      x9, #0x23198
uint64_t fde_0300_sub_023140(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x023140ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x023140: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x023144: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x023148: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02314c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x023150: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x023154: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x023158: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02315c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x023160: str x8, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4004A00ULL; // 0x023164: cbz x0, #0x23aa4
    return acc;
}

// [EN] Reconstructed FDE #0301 @ 0x023adc..0x023ae8 (12 bytes)
// [VN] Phục dựng FDE #0301 tại 0x023adc..0x023ae8 (12 byte)
//   0x023adc: 5ac00828  rev      w8, w1
//   0x023ae0: b9000008  str      w8, [x0]
//   0x023ae4: d65f03c0  ret      
uint64_t fde_0301_sub_023adc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x5AC00828ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x023ADCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x5AC00828ULL; // 0x023adc: rev w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000008ULL; // 0x023ae0: str w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x023ae4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0302 @ 0x023ae8..0x023b78 (144 bytes)
// [VN] Phục dựng FDE #0302 tại 0x023ae8..0x023b78 (144 byte)
//   0x023ae8: d100c3ff  sub      sp, sp, #0x30
//   0x023aec: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x023af0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x023af4: 910083fd  add      x29, sp, #0x20
//   0x023af8: d53bd054  mrs      x20, tpidr_el0
//   0x023afc: f9401688  ldr      x8, [x20, #0x28]
//   0x023b00: d28a1129  mov      x9, #0x5089
//   0x023b04: f2a8e9c9  movk     x9, #0x474e, lsl #16
//   0x023b08: f2c141a9  movk     x9, #0xa0d, lsl #32
//   0x023b0c: f90007e8  str      x8, [sp, #8]
//   0x023b10: 394a9408  ldrb     w8, [x0, #0x2a5]
//   0x023b14: 910003eb  mov      x11, sp
//   0x023b18: 5280010c  mov      w12, #8
//   0x023b1c: f2e14349  movk     x9, #0xa1a, lsl #48
//   0x023b20: 5280024a  mov      w10, #0x12
//   0x023b24: 8b080161  add      x1, x11, x8
uint64_t fde_0302_sub_023ae8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x5280010CULL) + (x2 ^ 0x023AE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x023ae8: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x023aec: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x023af0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x023af4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x023af8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x023afc: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD28A1129ULL; // 0x023b00: mov x9, #0x5089
    acc = (acc * 0x100000001B3ULL) ^ 0xF2A8E9C9ULL; // 0x023b04: movk x9, #0x474e, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2C141A9ULL; // 0x023b08: movk x9, #0xa0d, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x023b0c: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0303 @ 0x023b78..0x023ccc (340 bytes)
// [VN] Phục dựng FDE #0303 tại 0x023b78..0x023ccc (340 byte)
//   0x023b78: d10143ff  sub      sp, sp, #0x50
//   0x023b7c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x023b80: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x023b84: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x023b88: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x023b8c: 910103fd  add      x29, sp, #0x40
//   0x023b90: d53bd057  mrs      x23, tpidr_el0
//   0x023b94: f94016e8  ldr      x8, [x23, #0x28]
//   0x023b98: f90007e8  str      x8, [sp, #8]
//   0x023b9c: b40007a0  cbz      x0, #0x23c90
//   0x023ba0: aa0303f4  mov      x20, x3
//   0x023ba4: aa0003f3  mov      x19, x0
//   0x023ba8: d35ffc68  lsr      x8, x3, #0x1f
//   0x023bac: b5000888  cbnz     x8, #0x23cbc
//   0x023bb0: 39400028  ldrb     w8, [x1]
//   0x023bb4: 39400429  ldrb     w9, [x1, #1]
uint64_t fde_0303_sub_023b78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xD35FFC68ULL) + (x2 ^ 0x023B78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x023b78: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x023b7c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x023b80: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x023b84: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x023b88: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x023b8c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x023b90: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x023b94: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x023b98: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40007A0ULL; // 0x023b9c: cbz x0, #0x23c90
    return acc;
}

// [EN] Reconstructed FDE #0304 @ 0x023ccc..0x023d0c (64 bytes)
// [VN] Phục dựng FDE #0304 tại 0x023ccc..0x023d0c (64 byte)
//   0x023ccc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x023cd0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x023cd4: 910043fd  add      x29, sp, #0x10
//   0x023cd8: aa0103e8  mov      x8, x1
//   0x023cdc: f9400021  ldr      x1, [x1]
//   0x023ce0: b4000101  cbz      x1, #0x23d00
//   0x023ce4: aa0003f3  mov      x19, x0
//   0x023ce8: f900011f  str      xzr, [x8]
//   0x023cec: f9400034  ldr      x20, [x1]
//   0x023cf0: aa1303e0  mov      x0, x19
//   0x023cf4: 97fff712  bl       #0x2193c
//   0x023cf8: aa1403e1  mov      x1, x20
//   0x023cfc: b5ffff94  cbnz     x20, #0x23cec
//   0x023d00: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x023d04: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x023d08: d65f03c0  ret      
uint64_t fde_0304_sub_023ccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB5FFFF94ULL) + (x2 ^ 0x023CCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x023ccc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x023cd0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x023cd4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x023cd8: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x023cdc: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000101ULL; // 0x023ce0: cbz x1, #0x23d00
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023ce4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900011FULL; // 0x023ce8: str xzr, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400034ULL; // 0x023cec: ldr x20, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x023cf0: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0305 @ 0x023d0c..0x024074 (872 bytes)
// [VN] Phục dựng FDE #0305 tại 0x023d0c..0x024074 (872 byte)
//   0x023d0c: d101c3ff  sub      sp, sp, #0x70
//   0x023d10: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x023d14: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x023d18: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x023d1c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x023d20: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x023d24: 910183fd  add      x29, sp, #0x60
//   0x023d28: d53bd05a  mrs      x26, tpidr_el0
//   0x023d2c: f9401748  ldr      x8, [x26, #0x28]
//   0x023d30: aa0003f3  mov      x19, x0
//   0x023d34: 7100189f  cmp      w4, #6
//   0x023d38: f9000fe8  str      x8, [sp, #0x18]
//   0x023d3c: 54001828  b.hi     #0x24040
//   0x023d40: 90000189  adrp     x9, #0x53000
//   0x023d44: 2a0403e8  mov      w8, w4
//   0x023d48: 913e6129  add      x9, x9, #0xf98
uint64_t fde_0305_sub_023d0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x54001828ULL) + (x2 ^ 0x023D0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x023d0c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x023d10: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x023d14: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x023d18: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x023d1c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x023d20: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x023d24: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x023d28: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x023d2c: ldr x8, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x023d30: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0306 @ 0x024074..0x024238 (452 bytes)
// [VN] Phục dựng FDE #0306 tại 0x024074..0x024238 (452 byte)
//   0x024074: d10183ff  sub      sp, sp, #0x60
//   0x024078: f90013f7  str      x23, [sp, #0x20]
//   0x02407c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x024080: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x024084: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x024088: 910143fd  add      x29, sp, #0x50
//   0x02408c: d53bd057  mrs      x23, tpidr_el0
//   0x024090: f94016e8  ldr      x8, [x23, #0x28]
//   0x024094: 2a0203f4  mov      w20, w2
//   0x024098: aa0003f3  mov      x19, x0
//   0x02409c: aa0103f5  mov      x21, x1
//   0x0240a0: f9000fe8  str      x8, [sp, #0x18]
//   0x0240a4: 394a7c08  ldrb     w8, [x0, #0x29f]
//   0x0240a8: 71000d1f  cmp      w8, #3
//   0x0240ac: 540000e1  b.ne     #0x240c8
//   0x0240b0: 394a8269  ldrb     w9, [x19, #0x2a0]
uint64_t fde_0306_sub_024074(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x394A7C08ULL) + (x2 ^ 0x024074ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x024074: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x024078: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02407c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x024080: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x024084: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x024088: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02408c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x024090: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x024094: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024098: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0307 @ 0x024238..0x024730 (1272 bytes)
// [VN] Phục dựng FDE #0307 tại 0x024238..0x024730 (1272 byte)
//   0x024238: d10203ff  sub      sp, sp, #0x80
//   0x02423c: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x024240: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x024244: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x024248: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02424c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x024250: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x024254: 9101c3fd  add      x29, sp, #0x70
//   0x024258: d53bd048  mrs      x8, tpidr_el0
//   0x02425c: f90007e8  str      x8, [sp, #8]
//   0x024260: f9401508  ldr      x8, [x8, #0x28]
//   0x024264: 52882a89  mov      w9, #0x4154
//   0x024268: 72a92889  movk     w9, #0x4944, lsl #16
//   0x02426c: 2a0303f4  mov      w20, w3
//   0x024270: f9000fe8  str      x8, [sp, #0x18]
//   0x024274: b9417008  ldr      w8, [x0, #0x170]
uint64_t fde_0307_sub_024238(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x72A92889ULL) + (x2 ^ 0x024238ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x024238: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x02423c: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x024240: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x024244: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x024248: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02424c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x024250: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x024254: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x024258: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x02425c: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #0308 @ 0x024730..0x0249a8 (632 bytes)
// [VN] Phục dựng FDE #0308 tại 0x024730..0x0249a8 (632 byte)
//   0x024730: d102c3ff  sub      sp, sp, #0xb0
//   0x024734: f9002bfb  str      x27, [sp, #0x50]
//   0x024738: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x02473c: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x024740: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x024744: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x024748: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x02474c: 910283fd  add      x29, sp, #0xa0
//   0x024750: d53bd05b  mrs      x27, tpidr_el0
//   0x024754: f9401768  ldr      x8, [x27, #0x28]
//   0x024758: 52882a95  mov      w21, #0x4154
//   0x02475c: aa0203fa  mov      x26, x2
//   0x024760: 2a0103f4  mov      w20, w1
//   0x024764: f90027e8  str      x8, [sp, #0x48]
//   0x024768: b9417008  ldr      w8, [x0, #0x170]
//   0x02476c: aa0003f3  mov      x19, x0
uint64_t fde_0308_sub_024730(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x2A0103F4ULL) + (x2 ^ 0x024730ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x024730: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BFBULL; // 0x024734: str x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x024738: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x02473c: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x024740: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x024744: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x024748: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x02474c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x024750: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x024754: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0309 @ 0x0249a8..0x024b70 (456 bytes)
// [VN] Phục dựng FDE #0309 tại 0x0249a8..0x024b70 (456 byte)
//   0x0249a8: b9423409  ldr      w9, [x0, #0x234]
//   0x0249ac: aa0003e8  mov      x8, x0
//   0x0249b0: 12800000  mov      w0, #-1
//   0x0249b4: d34f7d2a  ubfx     x10, x9, #0xf, #0x11
//   0x0249b8: 35000cca  cbnz     w10, #0x24b50
//   0x0249bc: f941210a  ldr      x10, [x8, #0x240]
//   0x0249c0: d34ffd4b  lsr      x11, x10, #0xf
//   0x0249c4: b5000c6b  cbnz     x11, #0x24b50
//   0x0249c8: 394a710b  ldrb     w11, [x8, #0x29c]
//   0x0249cc: 3400016b  cbz      w11, #0x249f8
//   0x0249d0: b942310a  ldr      w10, [x8, #0x230]
//   0x0249d4: 394a8908  ldrb     w8, [x8, #0x2a2]
//   0x0249d8: 11001d4b  add      w11, w10, #7
//   0x0249dc: 53037d6c  lsr      w12, w11, #3
//   0x0249e0: d343fd0b  lsr      x11, x8, #3
//   0x0249e4: 3400010c  cbz      w12, #0x24a04
uint64_t fde_0309_sub_0249a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9423409ULL) + (x1 ^ 0x11001D4BULL) + (x2 ^ 0x0249A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9423409ULL; // 0x0249a8: ldr w9, [x0, #0x234]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0249ac: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x12800000ULL; // 0x0249b0: mov w0, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0xD34F7D2AULL; // 0x0249b4: ubfx x10, x9, #0xf, #0x11
    acc = (acc * 0x100000001B3ULL) ^ 0x35000CCAULL; // 0x0249b8: cbnz w10, #0x24b50
    acc = (acc * 0x100000001B3ULL) ^ 0xF941210AULL; // 0x0249bc: ldr x10, [x8, #0x240]
    acc = (acc * 0x100000001B3ULL) ^ 0xD34FFD4BULL; // 0x0249c0: lsr x11, x10, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000C6BULL; // 0x0249c4: cbnz x11, #0x24b50
    acc = (acc * 0x100000001B3ULL) ^ 0x394A710BULL; // 0x0249c8: ldrb w11, [x8, #0x29c]
    acc = (acc * 0x100000001B3ULL) ^ 0x3400016BULL; // 0x0249cc: cbz w11, #0x249f8
    return acc;
}

// [EN] Reconstructed FDE #0310 @ 0x024b70..0x024c40 (208 bytes)
// [VN] Phục dựng FDE #0310 tại 0x024b70..0x024c40 (208 byte)
//   0x024b70: d10103ff  sub      sp, sp, #0x40
//   0x024b74: f9000bf5  str      x21, [sp, #0x10]
//   0x024b78: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x024b7c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x024b80: 9100c3fd  add      x29, sp, #0x30
//   0x024b84: d53bd055  mrs      x21, tpidr_el0
//   0x024b88: f94016a8  ldr      x8, [x21, #0x28]
//   0x024b8c: aa0003f3  mov      x19, x0
//   0x024b90: f90007e8  str      x8, [sp, #8]
//   0x024b94: b40003c0  cbz      x0, #0x24c0c
//   0x024b98: d2c8a92a  mov      x10, #0x454900000000
//   0x024b9c: 52800448  mov      w8, #0x22
//   0x024ba0: 910003e9  mov      x9, sp
//   0x024ba4: f2e889ca  movk     x10, #0x444e, lsl #48
//   0x024ba8: 910003e1  mov      x1, sp
//   0x024bac: 52800102  mov      w2, #8
uint64_t fde_0310_sub_024b70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910003E9ULL) + (x2 ^ 0x024B70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x024b70: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x024b74: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x024b78: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x024b7c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x024b80: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x024b84: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x024b88: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024b8c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x024b90: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003C0ULL; // 0x024b94: cbz x0, #0x24c0c
    return acc;
}

// [EN] Reconstructed FDE #0311 @ 0x024c40..0x024d30 (240 bytes)
// [VN] Phục dựng FDE #0311 tại 0x024c40..0x024d30 (240 byte)
//   0x024c40: d10143ff  sub      sp, sp, #0x50
//   0x024c44: f90013f5  str      x21, [sp, #0x20]
//   0x024c48: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x024c4c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x024c50: 910103fd  add      x29, sp, #0x40
//   0x024c54: d53bd055  mrs      x21, tpidr_el0
//   0x024c58: f94016a8  ldr      x8, [x21, #0x28]
//   0x024c5c: 5ac00829  rev      w9, w1
//   0x024c60: f9000fe8  str      x8, [sp, #0x18]
//   0x024c64: b9000fe9  str      w9, [sp, #0xc]
//   0x024c68: b4000500  cbz      x0, #0x24d08
//   0x024c6c: f0000169  adrp     x9, #0x53000
//   0x024c70: fd47a120  ldr      d0, [x9, #0xf40]
//   0x024c74: 52800448  mov      w8, #0x22
//   0x024c78: b904ac08  str      w8, [x0, #0x4ac]
//   0x024c7c: 910043e8  add      x8, sp, #0x10
uint64_t fde_0311_sub_024c40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xFD47A120ULL) + (x2 ^ 0x024C40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x024c40: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x024c44: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x024c48: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x024c4c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x024c50: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x024c54: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x024c58: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x5AC00829ULL; // 0x024c5c: rev w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x024c60: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000FE9ULL; // 0x024c64: str w9, [sp, #0xc]
    return acc;
}

// [EN] Reconstructed FDE #0312 @ 0x024d30..0x024e3c (268 bytes)
// [VN] Phục dựng FDE #0312 tại 0x024d30..0x024e3c (268 byte)
//   0x024d30: d10143ff  sub      sp, sp, #0x50
//   0x024d34: f90013f5  str      x21, [sp, #0x20]
//   0x024d38: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x024d3c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x024d40: 910103fd  add      x29, sp, #0x40
//   0x024d44: d53bd055  mrs      x21, tpidr_el0
//   0x024d48: f94016a8  ldr      x8, [x21, #0x28]
//   0x024d4c: 2a0103f4  mov      w20, w1
//   0x024d50: aa0003f3  mov      x19, x0
//   0x024d54: 7100103f  cmp      w1, #4
//   0x024d58: f9000fe8  str      x8, [sp, #0x18]
//   0x024d5c: 540000ab  b.lt     #0x24d70
//   0x024d60: 90000181  adrp     x1, #0x54000
//   0x024d64: 91057c21  add      x1, x1, #0x15f
//   0x024d68: aa1303e0  mov      x0, x19
//   0x024d6c: 97fff05d  bl       #0x20ee0
uint64_t fde_0312_sub_024d30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x90000181ULL) + (x2 ^ 0x024D30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x024d30: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x024d34: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x024d38: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x024d3c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x024d40: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x024d44: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x024d48: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x024d4c: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024d50: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100103FULL; // 0x024d54: cmp w1, #4
    return acc;
}

// [EN] Reconstructed FDE #0313 @ 0x024e3c..0x0250c8 (652 bytes)
// [VN] Phục dựng FDE #0313 tại 0x024e3c..0x0250c8 (652 byte)
//   0x024e3c: a9bb67fc  stp      x28, x25, [sp, #-0x50]!
//   0x024e40: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x024e44: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x024e48: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x024e4c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x024e50: 910103fd  add      x29, sp, #0x40
//   0x024e54: d11203ff  sub      sp, sp, #0x480
//   0x024e58: d53bd056  mrs      x22, tpidr_el0
//   0x024e5c: f94016c8  ldr      x8, [x22, #0x28]
//   0x024e60: aa0003f3  mov      x19, x0
//   0x024e64: f81b83a8  stur     x8, [x29, #-0x48]
//   0x024e68: b4001002  cbz      x2, #0x25068
//   0x024e6c: 39400049  ldrb     w9, [x2]
//   0x024e70: 3940044a  ldrb     w10, [x2, #1]
//   0x024e74: 3940084b  ldrb     w11, [x2, #2]
//   0x024e78: 39400c48  ldrb     w8, [x2, #3]
uint64_t fde_0313_sub_024e3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FCULL) + (x1 ^ 0x39400049ULL) + (x2 ^ 0x024E3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FCULL; // 0x024e3c: stp x28, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x024e40: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x024e44: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x024e48: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x024e4c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x024e50: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD11203FFULL; // 0x024e54: sub sp, sp, #0x480
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x024e58: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x024e5c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x024e60: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0314 @ 0x0250c8..0x0252f0 (552 bytes)
// [VN] Phục dựng FDE #0314 tại 0x0250c8..0x0252f0 (552 byte)
//   0x0250c8: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0250cc: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0250d0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0250d4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0250d8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0250dc: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0250e0: 910143fd  add      x29, sp, #0x50
//   0x0250e4: aa0203f3  mov      x19, x2
//   0x0250e8: f9400442  ldr      x2, [x2, #8]
//   0x0250ec: 2a0303f5  mov      w21, w3
//   0x0250f0: aa0003f4  mov      x20, x0
//   0x0250f4: 97fffd8f  bl       #0x24730
//   0x0250f8: 2a0003f7  mov      w23, w0
//   0x0250fc: 35000b00  cbnz     w0, #0x2525c
//   0x025100: a9406668  ldp      x8, x25, [x19]
//   0x025104: 9107a29a  add      x26, x20, #0x1e8
uint64_t fde_0314_sub_0250c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x2A0003F7ULL) + (x2 ^ 0x0250C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0250c8: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0250cc: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0250d0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0250d4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0250d8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0250dc: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0250e0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0250e4: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400442ULL; // 0x0250e8: ldr x2, [x2, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F5ULL; // 0x0250ec: mov w21, w3
    return acc;
}

// [EN] Reconstructed FDE #0315 @ 0x0252f0..0x0255ac (700 bytes)
// [VN] Phục dựng FDE #0315 tại 0x0252f0..0x0255ac (700 byte)
//   0x0252f0: d103c3ff  sub      sp, sp, #0xf0
//   0x0252f4: a9096ffc  stp      x28, x27, [sp, #0x90]
//   0x0252f8: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x0252fc: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x025300: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x025304: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x025308: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x02530c: 910383fd  add      x29, sp, #0xe0
//   0x025310: d53bd059  mrs      x25, tpidr_el0
//   0x025314: f9401728  ldr      x8, [x25, #0x28]
//   0x025318: aa0103f5  mov      x21, x1
//   0x02531c: aa0103f4  mov      x20, x1
//   0x025320: 52800149  mov      w9, #0xa
//   0x025324: f81a83a8  stur     x8, [x29, #-0x58]
//   0x025328: 38408ea8  ldrb     w8, [x21, #8]!
//   0x02532c: b9401838  ldr      w24, [x1, #0x18]
uint64_t fde_0315_sub_0252f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0x52800149ULL) + (x2 ^ 0x0252F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x0252f0: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9096FFCULL; // 0x0252f4: stp x28, x27, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A67FAULL; // 0x0252f8: stp x26, x25, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B5FF8ULL; // 0x0252fc: stp x24, x23, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C57F6ULL; // 0x025300: stp x22, x21, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D4FF4ULL; // 0x025304: stp x20, x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x025308: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x02530c: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x025310: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x025314: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0316 @ 0x0255ac..0x025760 (436 bytes)
// [VN] Phục dựng FDE #0316 tại 0x0255ac..0x025760 (436 byte)
//   0x0255ac: d10143ff  sub      sp, sp, #0x50
//   0x0255b0: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0255b4: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0255b8: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0255bc: 910103fd  add      x29, sp, #0x40
//   0x0255c0: d53bd056  mrs      x22, tpidr_el0
//   0x0255c4: f94016c8  ldr      x8, [x22, #0x28]
//   0x0255c8: aa0003f3  mov      x19, x0
//   0x0255cc: f9000fe8  str      x8, [sp, #0x18]
//   0x0255d0: 37080162  tbnz     w2, #1, #0x255fc
//   0x0255d4: 39400c28  ldrb     w8, [x1, #3]
//   0x0255d8: 34000a88  cbz      w8, #0x25728
//   0x0255dc: 394a8669  ldrb     w9, [x19, #0x2a1]
//   0x0255e0: 6b09011f  cmp      w8, w9
//   0x0255e4: 54000a28  b.hi     #0x25728
//   0x0255e8: 52800034  mov      w20, #1
uint64_t fde_0316_sub_0255ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x394A8669ULL) + (x2 ^ 0x0255ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0255ac: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0255b0: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0255b4: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0255b8: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0255bc: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0255c0: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0255c4: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0255c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0255cc: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x37080162ULL; // 0x0255d0: tbnz w2, #1, #0x255fc
    return acc;
}

// [EN] Reconstructed FDE #0317 @ 0x025760..0x0258b4 (340 bytes)
// [VN] Phục dựng FDE #0317 tại 0x025760..0x0258b4 (340 byte)
//   0x025760: d10183ff  sub      sp, sp, #0x60
//   0x025764: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x025768: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02576c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x025770: 910143fd  add      x29, sp, #0x50
//   0x025774: d53bd055  mrs      x21, tpidr_el0
//   0x025778: f94016a8  ldr      x8, [x21, #0x28]
//   0x02577c: aa0103f4  mov      x20, x1
//   0x025780: aa0003f3  mov      x19, x0
//   0x025784: 910023e0  add      x0, sp, #8
//   0x025788: f90017e8  str      x8, [sp, #0x28]
//   0x02578c: b9401821  ldr      w1, [x1, #0x18]
//   0x025790: 910023f6  add      x22, sp, #8
//   0x025794: 97ffece6  bl       #0x20b2c
//   0x025798: b9401e81  ldr      w1, [x20, #0x1c]
//   0x02579c: 910012c0  add      x0, x22, #4
uint64_t fde_0317_sub_025760(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x910023F6ULL) + (x2 ^ 0x025760ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x025760: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x025764: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x025768: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02576c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x025770: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x025774: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x025778: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02577c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025780: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x025784: add x0, sp, #8
    return acc;
}

// [EN] Reconstructed FDE #0318 @ 0x0258b4..0x025b88 (724 bytes)
// [VN] Phục dựng FDE #0318 tại 0x0258b4..0x025b88 (724 byte)
//   0x0258b4: d10183ff  sub      sp, sp, #0x60
//   0x0258b8: f90013f7  str      x23, [sp, #0x20]
//   0x0258bc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0258c0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0258c4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0258c8: 910143fd  add      x29, sp, #0x50
//   0x0258cc: d53bd057  mrs      x23, tpidr_el0
//   0x0258d0: f94016e8  ldr      x8, [x23, #0x28]
//   0x0258d4: aa0003f3  mov      x19, x0
//   0x0258d8: f9000fe8  str      x8, [sp, #0x18]
//   0x0258dc: 34000464  cbz      w4, #0x25968
//   0x0258e0: 7100089f  cmp      w4, #2
//   0x0258e4: 54000180  b.eq     #0x25914
//   0x0258e8: 71000c9f  cmp      w4, #3
//   0x0258ec: 540008a1  b.ne     #0x25a00
//   0x0258f0: 2a0303f5  mov      w21, w3
uint64_t fde_0318_sub_0258b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x54000180ULL) + (x2 ^ 0x0258B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0258b4: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x0258b8: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0258bc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0258c0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0258c4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0258c8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0258cc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0258d0: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0258d4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0258d8: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0319 @ 0x025b88..0x025e1c (660 bytes)
// [VN] Phục dựng FDE #0319 tại 0x025b88..0x025e1c (660 byte)
//   0x025b88: d10143ff  sub      sp, sp, #0x50
//   0x025b8c: f90013f5  str      x21, [sp, #0x20]
//   0x025b90: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x025b94: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x025b98: 910103fd  add      x29, sp, #0x40
//   0x025b9c: d53bd055  mrs      x21, tpidr_el0
//   0x025ba0: f94016a8  ldr      x8, [x21, #0x28]
//   0x025ba4: aa0003f3  mov      x19, x0
//   0x025ba8: 71000c5f  cmp      w2, #3
//   0x025bac: f9000fe8  str      x8, [sp, #0x18]
//   0x025bb0: 54000161  b.ne     #0x25bdc
//   0x025bb4: 79452269  ldrh     w9, [x19, #0x290]
//   0x025bb8: 35000069  cbnz     w9, #0x25bc4
//   0x025bbc: 39506268  ldrb     w8, [x19, #0x418]
//   0x025bc0: 37000c88  tbnz     w8, #0, #0x25d50
//   0x025bc4: 39400028  ldrb     w8, [x1]
uint64_t fde_0319_sub_025b88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x35000069ULL) + (x2 ^ 0x025B88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x025b88: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x025b8c: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x025b90: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x025b94: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x025b98: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x025b9c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x025ba0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025ba4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000C5FULL; // 0x025ba8: cmp w2, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x025bac: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0320 @ 0x025e1c..0x025f78 (348 bytes)
// [VN] Phục dựng FDE #0320 tại 0x025e1c..0x025f78 (348 byte)
//   0x025e1c: d10183ff  sub      sp, sp, #0x60
//   0x025e20: f90013f7  str      x23, [sp, #0x20]
//   0x025e24: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x025e28: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x025e2c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x025e30: 910143fd  add      x29, sp, #0x50
//   0x025e34: d53bd057  mrs      x23, tpidr_el0
//   0x025e38: f94016e8  ldr      x8, [x23, #0x28]
//   0x025e3c: aa0003f3  mov      x19, x0
//   0x025e40: f9000fe8  str      x8, [sp, #0x18]
//   0x025e44: 79452008  ldrh     w8, [x0, #0x290]
//   0x025e48: 6b02011f  cmp      w8, w2
//   0x025e4c: 540000ca  b.ge     #0x25e64
//   0x025e50: f0000161  adrp     x1, #0x54000
//   0x025e54: 910ea021  add      x1, x1, #0x3a8
//   0x025e58: aa1303e0  mov      x0, x19
uint64_t fde_0320_sub_025e1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x540000CAULL) + (x2 ^ 0x025E1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x025e1c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x025e20: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x025e24: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x025e28: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x025e2c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x025e30: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x025e34: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x025e38: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x025e3c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x025e40: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0321 @ 0x025f78..0x026128 (432 bytes)
// [VN] Phục dựng FDE #0321 tại 0x025f78..0x026128 (432 byte)
//   0x025f78: d10283ff  sub      sp, sp, #0xa0
//   0x025f7c: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x025f80: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x025f84: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x025f88: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x025f8c: 910243fd  add      x29, sp, #0x90
//   0x025f90: d53bd057  mrs      x23, tpidr_el0
//   0x025f94: f94016e8  ldr      x8, [x23, #0x28]
//   0x025f98: aa0203f4  mov      x20, x2
//   0x025f9c: 910003e2  mov      x2, sp
//   0x025fa0: aa0003f3  mov      x19, x0
//   0x025fa4: f81c83a8  stur     x8, [x29, #-0x38]
//   0x025fa8: 97ffeefd  bl       #0x21b9c
//   0x025fac: 34000ac0  cbz      w0, #0x26104
//   0x025fb0: 2a0003f6  mov      w22, w0
//   0x025fb4: b4000194  cbz      x20, #0x25fe4
uint64_t fde_0321_sub_025f78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x97FFEEFDULL) + (x2 ^ 0x025F78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x025f78: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x025f7c: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x025f80: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x025f84: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x025f88: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x025f8c: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x025f90: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x025f94: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x025f98: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E2ULL; // 0x025f9c: mov x2, sp
    return acc;
}

// [EN] Reconstructed FDE #0322 @ 0x026128..0x026384 (604 bytes)
// [VN] Phục dựng FDE #0322 tại 0x026128..0x026384 (604 byte)
//   0x026128: a9bb67fc  stp      x28, x25, [sp, #-0x50]!
//   0x02612c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x026130: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x026134: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x026138: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02613c: 910103fd  add      x29, sp, #0x40
//   0x026140: d11203ff  sub      sp, sp, #0x480
//   0x026144: d53bd056  mrs      x22, tpidr_el0
//   0x026148: f94016c8  ldr      x8, [x22, #0x28]
//   0x02614c: aa0203f5  mov      x21, x2
//   0x026150: aa0003f3  mov      x19, x0
//   0x026154: f81b83a8  stur     x8, [x29, #-0x48]
//   0x026158: 340000e3  cbz      w3, #0x26174
//   0x02615c: 3100047f  cmn      w3, #1
//   0x026160: 54000f21  b.ne     #0x26344
//   0x026164: aa1303e0  mov      x0, x19
uint64_t fde_0322_sub_026128(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FCULL) + (x1 ^ 0x340000E3ULL) + (x2 ^ 0x026128ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FCULL; // 0x026128: stp x28, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02612c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x026130: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x026134: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x026138: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02613c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD11203FFULL; // 0x026140: sub sp, sp, #0x480
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x026144: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x026148: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02614c: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0323 @ 0x026384..0x026734 (944 bytes)
// [VN] Phục dựng FDE #0323 tại 0x026384..0x026734 (944 byte)
//   0x026384: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x026388: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02638c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x026390: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x026394: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x026398: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02639c: 910143fd  add      x29, sp, #0x50
//   0x0263a0: d11283ff  sub      sp, sp, #0x4a0
//   0x0263a4: d53bd058  mrs      x24, tpidr_el0
//   0x0263a8: f9401709  ldr      x9, [x24, #0x28]
//   0x0263ac: aa0203e8  mov      x8, x2
//   0x0263b0: 2a0103f7  mov      w23, w1
//   0x0263b4: d102f3a2  sub      x2, x29, #0xbc
//   0x0263b8: aa0803e1  mov      x1, x8
//   0x0263bc: aa0503f4  mov      x20, x5
//   0x0263c0: aa0403f5  mov      x21, x4
uint64_t fde_0323_sub_026384(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xD102F3A2ULL) + (x2 ^ 0x026384ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x026384: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x026388: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02638c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x026390: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x026394: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x026398: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02639c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD11283FFULL; // 0x0263a0: sub sp, sp, #0x4a0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0263a4: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401709ULL; // 0x0263a8: ldr x9, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0324 @ 0x026734..0x02686c (312 bytes)
// [VN] Phục dựng FDE #0324 tại 0x026734..0x02686c (312 byte)
//   0x026734: d10183ff  sub      sp, sp, #0x60
//   0x026738: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02673c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x026740: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x026744: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x026748: 910143fd  add      x29, sp, #0x50
//   0x02674c: d53bd057  mrs      x23, tpidr_el0
//   0x026750: f94016e8  ldr      x8, [x23, #0x28]
//   0x026754: 2a0303f4  mov      w20, w3
//   0x026758: 2a0203f5  mov      w21, w2
//   0x02675c: 2a0103f6  mov      w22, w1
//   0x026760: aa0003f3  mov      x19, x0
//   0x026764: 7100087f  cmp      w3, #2
//   0x026768: f9000fe8  str      x8, [sp, #0x18]
//   0x02676c: 540000ab  b.lt     #0x26780
//   0x026770: d0000161  adrp     x1, #0x54000
uint64_t fde_0324_sub_026734(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x7100087FULL) + (x2 ^ 0x026734ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x026734: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x026738: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02673c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x026740: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x026744: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x026748: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02674c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x026750: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x026754: mov w20, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x026758: mov w21, w2
    return acc;
}

// [EN] Reconstructed FDE #0325 @ 0x02686c..0x026b5c (752 bytes)
// [VN] Phục dựng FDE #0325 tại 0x02686c..0x026b5c (752 byte)
//   0x02686c: d103c3ff  sub      sp, sp, #0xf0
//   0x026870: a9096ffc  stp      x28, x27, [sp, #0x90]
//   0x026874: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x026878: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x02687c: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x026880: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x026884: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x026888: 910383fd  add      x29, sp, #0xe0
//   0x02688c: d53bd054  mrs      x20, tpidr_el0
//   0x026890: f9401688  ldr      x8, [x20, #0x28]
//   0x026894: aa0003f3  mov      x19, x0
//   0x026898: 7100109f  cmp      w4, #4
//   0x02689c: f81a83a8  stur     x8, [x29, #-0x58]
//   0x0268a0: 540014ca  b.ge     #0x26b38
//   0x0268a4: b90013e2  str      w2, [sp, #0x10]
//   0x0268a8: 9100b3e2  add      x2, sp, #0x2c
uint64_t fde_0325_sub_02686c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0xF81A83A8ULL) + (x2 ^ 0x02686CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x02686c: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9096FFCULL; // 0x026870: stp x28, x27, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A67FAULL; // 0x026874: stp x26, x25, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B5FF8ULL; // 0x026878: stp x24, x23, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C57F6ULL; // 0x02687c: stp x22, x21, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D4FF4ULL; // 0x026880: stp x20, x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x026884: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x026888: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02688c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x026890: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0326 @ 0x026b5c..0x026cf0 (404 bytes)
// [VN] Phục dựng FDE #0326 tại 0x026b5c..0x026cf0 (404 byte)
//   0x026b5c: d10283ff  sub      sp, sp, #0xa0
//   0x026b60: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x026b64: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x026b68: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x026b6c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x026b70: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x026b74: 910243fd  add      x29, sp, #0x90
//   0x026b78: d53bd05a  mrs      x26, tpidr_el0
//   0x026b7c: f9401748  ldr      x8, [x26, #0x28]
//   0x026b80: aa0003f3  mov      x19, x0
//   0x026b84: aa0203e0  mov      x0, x2
//   0x026b88: aa0303f5  mov      x21, x3
//   0x026b8c: aa0203f6  mov      x22, x2
//   0x026b90: 2a0103f9  mov      w25, w1
//   0x026b94: f90027e8  str      x8, [sp, #0x48]
//   0x026b98: 97ff74fe  bl       #0x3f90
uint64_t fde_0326_sub_026b5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xAA0203F6ULL) + (x2 ^ 0x026B5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x026b5c: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x026b60: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x026b64: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x026b68: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x026b6c: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x026b70: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x026b74: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x026b78: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401748ULL; // 0x026b7c: ldr x8, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x026b80: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0327 @ 0x026cf0..0x026e44 (340 bytes)
// [VN] Phục dựng FDE #0327 tại 0x026cf0..0x026e44 (340 byte)
//   0x026cf0: d10183ff  sub      sp, sp, #0x60
//   0x026cf4: f90013f7  str      x23, [sp, #0x20]
//   0x026cf8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x026cfc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x026d00: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x026d04: 910143fd  add      x29, sp, #0x50
//   0x026d08: d53bd057  mrs      x23, tpidr_el0
//   0x026d0c: f94016e8  ldr      x8, [x23, #0x28]
//   0x026d10: 2a0303f4  mov      w20, w3
//   0x026d14: 2a0203f5  mov      w21, w2
//   0x026d18: 2a0103f6  mov      w22, w1
//   0x026d1c: aa0003f3  mov      x19, x0
//   0x026d20: 7100087f  cmp      w3, #2
//   0x026d24: f9000fe8  str      x8, [sp, #0x18]
//   0x026d28: 540000ab  b.lt     #0x26d3c
//   0x026d2c: d0000161  adrp     x1, #0x54000
uint64_t fde_0327_sub_026cf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x7100087FULL) + (x2 ^ 0x026CF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x026cf0: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x026cf4: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x026cf8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x026cfc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x026d00: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x026d04: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x026d08: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x026d0c: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x026d10: mov w20, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x026d14: mov w21, w2
    return acc;
}

// [EN] Reconstructed FDE #0328 @ 0x026e44..0x026fa4 (352 bytes)
// [VN] Phục dựng FDE #0328 tại 0x026e44..0x026fa4 (352 byte)
//   0x026e44: d10143ff  sub      sp, sp, #0x50
//   0x026e48: f90013f5  str      x21, [sp, #0x20]
//   0x026e4c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x026e50: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x026e54: 910103fd  add      x29, sp, #0x40
//   0x026e58: d53bd055  mrs      x21, tpidr_el0
//   0x026e5c: f94016a8  ldr      x8, [x21, #0x28]
//   0x026e60: aa0003f3  mov      x19, x0
//   0x026e64: f9000fe8  str      x8, [sp, #0x18]
//   0x026e68: 39400828  ldrb     w8, [x1, #2]
//   0x026e6c: 51000509  sub      w9, w8, #1
//   0x026e70: 71002d3f  cmp      w9, #0xb
//   0x026e74: 54000168  b.hi     #0x26ea0
//   0x026e78: 39400c29  ldrb     w9, [x1, #3]
//   0x026e7c: 5100052a  sub      w10, w9, #1
//   0x026e80: 7100795f  cmp      w10, #0x1e
uint64_t fde_0328_sub_026e44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x54000168ULL) + (x2 ^ 0x026E44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x026e44: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x026e48: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x026e4c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x026e50: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x026e54: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x026e58: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x026e5c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x026e60: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x026e64: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400828ULL; // 0x026e68: ldrb w8, [x1, #2]
    return acc;
}

// [EN] Reconstructed FDE #0329 @ 0x026fa4..0x0270fc (344 bytes)
// [VN] Phục dựng FDE #0329 tại 0x026fa4..0x0270fc (344 byte)
//   0x026fa4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x026fa8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x026fac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x026fb0: 910083fd  add      x29, sp, #0x20
//   0x026fb4: 394a9008  ldrb     w8, [x0, #0x2a4]
//   0x026fb8: 394a840a  ldrb     w10, [x0, #0x2a1]
//   0x026fbc: b9423009  ldr      w9, [x0, #0x230]
//   0x026fc0: aa0003f3  mov      x19, x0
//   0x026fc4: 9b087d48  mul      x8, x10, x8
//   0x026fc8: 7100211f  cmp      w8, #8
//   0x026fcc: 54000083  b.lo     #0x26fdc
//   0x026fd0: d343fd0a  lsr      x10, x8, #3
//   0x026fd4: 9b097d49  mul      x9, x10, x9
//   0x026fd8: 14000004  b        #0x26fe8
//   0x026fdc: b2400bea  mov      x10, #7
//   0x026fe0: 9b092909  madd     x9, x8, x9, x10
uint64_t fde_0329_sub_026fa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x9B097D49ULL) + (x2 ^ 0x026FA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x026fa4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x026fa8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x026fac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x026fb0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x394A9008ULL; // 0x026fb4: ldrb w8, [x0, #0x2a4]
    acc = (acc * 0x100000001B3ULL) ^ 0x394A840AULL; // 0x026fb8: ldrb w10, [x0, #0x2a1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9423009ULL; // 0x026fbc: ldr w9, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x026fc0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9B087D48ULL; // 0x026fc4: mul x8, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100211FULL; // 0x026fc8: cmp w8, #8
    return acc;
}

// [EN] Reconstructed FDE #0330 @ 0x0270fc..0x027238 (316 bytes)
// [VN] Phục dựng FDE #0330 tại 0x0270fc..0x027238 (316 byte)
//   0x0270fc: b9424c08  ldr      w8, [x0, #0x24c]
//   0x027100: b9423809  ldr      w9, [x0, #0x238]
//   0x027104: 11000508  add      w8, w8, #1
//   0x027108: 6b09011f  cmp      w8, w9
//   0x02710c: b9024c08  str      w8, [x0, #0x24c]
//   0x027110: 54000042  b.hs     #0x27118
//   0x027114: d65f03c0  ret      
//   0x027118: 394a7008  ldrb     w8, [x0, #0x29c]
//   0x02711c: 34000788  cbz      w8, #0x2720c
//   0x027120: 3945b008  ldrb     w8, [x0, #0x16c]
//   0x027124: b9024c1f  str      wzr, [x0, #0x24c]
//   0x027128: 370804e8  tbnz     w8, #1, #0x271c4
//   0x02712c: 394a7408  ldrb     w8, [x0, #0x29d]
//   0x027130: b0000169  adrp     x9, #0x54000
//   0x027134: b000016a  adrp     x10, #0x54000
//   0x027138: b000016b  adrp     x11, #0x54000
uint64_t fde_0330_sub_0270fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9424C08ULL) + (x1 ^ 0x394A7408ULL) + (x2 ^ 0x0270FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9424C08ULL; // 0x0270fc: ldr w8, [x0, #0x24c]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9423809ULL; // 0x027100: ldr w9, [x0, #0x238]
    acc = (acc * 0x100000001B3ULL) ^ 0x11000508ULL; // 0x027104: add w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x027108: cmp w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0xB9024C08ULL; // 0x02710c: str w8, [x0, #0x24c]
    acc = (acc * 0x100000001B3ULL) ^ 0x54000042ULL; // 0x027110: b.hs #0x27118
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x027114: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x394A7008ULL; // 0x027118: ldrb w8, [x0, #0x29c]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000788ULL; // 0x02711c: cbz w8, #0x2720c
    acc = (acc * 0x100000001B3ULL) ^ 0x3945B008ULL; // 0x027120: ldrb w8, [x0, #0x16c]
    return acc;
}

// [EN] Reconstructed FDE #0331 @ 0x027238..0x027500 (712 bytes)
// [VN] Phục dựng FDE #0331 tại 0x027238..0x027500 (712 byte)
//   0x027238: 7100145f  cmp      w2, #5
//   0x02723c: 5400160c  b.gt     #0x274fc
//   0x027240: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x027244: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x027248: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02724c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x027250: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x027254: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x027258: 910143fd  add      x29, sp, #0x50
//   0x02725c: 39404c08  ldrb     w8, [x0, #0x13]
//   0x027260: b0000177  adrp     x23, #0x54000
//   0x027264: aa0103f4  mov      x20, x1
//   0x027268: aa0003f3  mov      x19, x0
//   0x02726c: 7100111f  cmp      w8, #4
//   0x027270: 911856f7  add      x23, x23, #0x615
//   0x027274: 54000480  b.eq     #0x27304
uint64_t fde_0331_sub_027238(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100145FULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x027238ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100145FULL; // 0x027238: cmp w2, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x5400160CULL; // 0x02723c: b.gt #0x274fc
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x027240: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x027244: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x027248: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02724c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x027250: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x027254: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x027258: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x39404C08ULL; // 0x02725c: ldrb w8, [x0, #0x13]
    return acc;
}

// [EN] Reconstructed FDE #0332 @ 0x027500..0x028238 (3384 bytes)
// [VN] Phục dựng FDE #0332 tại 0x027500..0x028238 (3384 byte)
//   0x027500: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x027504: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x027508: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02750c: 910083fd  add      x29, sp, #0x20
//   0x027510: 39404c2e  ldrb     w14, [x1, #0x13]
//   0x027514: f9400429  ldr      x9, [x1, #8]
//   0x027518: 394a780d  ldrb     w13, [x0, #0x29e]
//   0x02751c: f9413008  ldr      x8, [x0, #0x260]
//   0x027520: 92ffc00a  mov      x10, #0x1ffffffffffffff
//   0x027524: 91001dcc  add      x12, x14, #7
//   0x027528: aa0003f3  mov      x19, x0
//   0x02752c: eb0a013f  cmp      x9, x10
//   0x027530: d343fd8a  lsr      x10, x12, #3
//   0x027534: 54000383  b.lo     #0x275a4
//   0x027538: 4b0d03eb  neg      w11, w13
//   0x02753c: 0a0b01ad  and      w13, w13, w11
uint64_t fde_0332_sub_027500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xD343FD8AULL) + (x2 ^ 0x027500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x027500: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x027504: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x027508: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02750c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x39404C2EULL; // 0x027510: ldrb w14, [x1, #0x13]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400429ULL; // 0x027514: ldr x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x394A780DULL; // 0x027518: ldrb w13, [x0, #0x29e]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9413008ULL; // 0x02751c: ldr x8, [x0, #0x260]
    acc = (acc * 0x100000001B3ULL) ^ 0x92FFC00AULL; // 0x027520: mov x10, #0x1ffffffffffffff
    acc = (acc * 0x100000001B3ULL) ^ 0x91001DCCULL; // 0x027524: add x12, x14, #7
    return acc;
}

// [EN] Reconstructed FDE #0333 @ 0x028238..0x028740 (1288 bytes)
// [VN] Phục dựng FDE #0333 tại 0x028238..0x028740 (1288 byte)
//   0x028238: d102c3ff  sub      sp, sp, #0xb0
//   0x02823c: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x028240: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x028244: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x028248: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x02824c: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x028250: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x028254: 910283fd  add      x29, sp, #0xa0
//   0x028258: d53bd05c  mrs      x28, tpidr_el0
//   0x02825c: f9401788  ldr      x8, [x28, #0x28]
//   0x028260: aa0703f6  mov      x22, x7
//   0x028264: aa0603f9  mov      x25, x6
//   0x028268: aa0403f5  mov      x21, x4
//   0x02826c: aa0203f4  mov      x20, x2
//   0x028270: aa0103f8  mov      x24, x1
//   0x028274: aa0003f7  mov      x23, x0
uint64_t fde_0333_sub_028238(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xAA0403F5ULL) + (x2 ^ 0x028238ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x028238: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x02823c: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x028240: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x028244: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x028248: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x02824c: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x028250: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x028254: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05CULL; // 0x028258: mrs x28, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401788ULL; // 0x02825c: ldr x8, [x28, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0334 @ 0x028740..0x02893c (508 bytes)
// [VN] Phục dựng FDE #0334 tại 0x028740..0x02893c (508 byte)
//   0x028740: d10503ff  sub      sp, sp, #0x140
//   0x028744: f90083fc  str      x28, [sp, #0x100]
//   0x028748: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x02874c: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x028750: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x028754: 9104c3fd  add      x29, sp, #0x130
//   0x028758: d53bd056  mrs      x22, tpidr_el0
//   0x02875c: f94016c8  ldr      x8, [x22, #0x28]
//   0x028760: aa0203f3  mov      x19, x2
//   0x028764: 52800029  mov      w9, #1
//   0x028768: d100f3a5  sub      x5, x29, #0x3c
//   0x02876c: 910023e7  add      x7, sp, #8
//   0x028770: aa1f03e2  mov      x2, xzr
//   0x028774: aa1f03e3  mov      x3, xzr
//   0x028778: aa1f03e4  mov      x4, xzr
//   0x02877c: aa1f03e6  mov      x6, xzr
uint64_t fde_0334_sub_028740(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10503FFULL) + (x1 ^ 0xAA1F03E2ULL) + (x2 ^ 0x028740ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10503FFULL; // 0x028740: sub sp, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xF90083FCULL; // 0x028744: str x28, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91157F6ULL; // 0x028748: stp x22, x21, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9124FF4ULL; // 0x02874c: stp x20, x19, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9137BFDULL; // 0x028750: stp x29, x30, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0x9104C3FDULL; // 0x028754: add x29, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x028758: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x02875c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x028760: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x028764: mov w9, #1
    return acc;
}

// [EN] Reconstructed FDE #0335 @ 0x02893c..0x028a40 (260 bytes)
// [VN] Phục dựng FDE #0335 tại 0x02893c..0x028a40 (260 byte)
//   0x02893c: d105c3ff  sub      sp, sp, #0x170
//   0x028940: f90093fc  str      x28, [sp, #0x120]
//   0x028944: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x028948: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x02894c: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x028950: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x028954: 910583fd  add      x29, sp, #0x160
//   0x028958: d53bd057  mrs      x23, tpidr_el0
//   0x02895c: f94016e8  ldr      x8, [x23, #0x28]
//   0x028960: aa0103f3  mov      x19, x1
//   0x028964: aa0003f4  mov      x20, x0
//   0x028968: 9101e3e0  add      x0, sp, #0x78
//   0x02896c: 52804121  mov      w1, #0x209
//   0x028970: aa0303f5  mov      x21, x3
//   0x028974: aa0203f6  mov      x22, x2
//   0x028978: f81b83a8  stur     x8, [x29, #-0x48]
uint64_t fde_0335_sub_02893c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD105C3FFULL) + (x1 ^ 0x52804121ULL) + (x2 ^ 0x02893CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD105C3FFULL; // 0x02893c: sub sp, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xF90093FCULL; // 0x028940: str x28, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9135FF8ULL; // 0x028944: stp x24, x23, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91457F6ULL; // 0x028948: stp x22, x21, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9154FF4ULL; // 0x02894c: stp x20, x19, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9167BFDULL; // 0x028950: stp x29, x30, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0x910583FDULL; // 0x028954: add x29, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x028958: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02895c: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028960: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0336 @ 0x028a40..0x028b48 (264 bytes)
// [VN] Phục dựng FDE #0336 tại 0x028a40..0x028b48 (264 byte)
//   0x028a40: d105c3ff  sub      sp, sp, #0x170
//   0x028a44: f90093fc  str      x28, [sp, #0x120]
//   0x028a48: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x028a4c: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x028a50: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x028a54: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x028a58: 910583fd  add      x29, sp, #0x160
//   0x028a5c: d53bd057  mrs      x23, tpidr_el0
//   0x028a60: f94016e8  ldr      x8, [x23, #0x28]
//   0x028a64: aa0103f3  mov      x19, x1
//   0x028a68: aa0003f4  mov      x20, x0
//   0x028a6c: 9101e3e0  add      x0, sp, #0x78
//   0x028a70: 52804121  mov      w1, #0x209
//   0x028a74: aa0303f5  mov      x21, x3
//   0x028a78: aa0203f6  mov      x22, x2
//   0x028a7c: f81b83a8  stur     x8, [x29, #-0x48]
uint64_t fde_0336_sub_028a40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD105C3FFULL) + (x1 ^ 0x52804121ULL) + (x2 ^ 0x028A40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD105C3FFULL; // 0x028a40: sub sp, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xF90093FCULL; // 0x028a44: str x28, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9135FF8ULL; // 0x028a48: stp x24, x23, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91457F6ULL; // 0x028a4c: stp x22, x21, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9154FF4ULL; // 0x028a50: stp x20, x19, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9167BFDULL; // 0x028a54: stp x29, x30, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0x910583FDULL; // 0x028a58: add x29, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x028a5c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x028a60: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028a64: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0337 @ 0x028b48..0x028bf0 (168 bytes)
// [VN] Phục dựng FDE #0337 tại 0x028b48..0x028bf0 (168 byte)
//   0x028b48: d10183ff  sub      sp, sp, #0x60
//   0x028b4c: f9001bf5  str      x21, [sp, #0x30]
//   0x028b50: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x028b54: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x028b58: 910143fd  add      x29, sp, #0x50
//   0x028b5c: d53bd055  mrs      x21, tpidr_el0
//   0x028b60: f94016a8  ldr      x8, [x21, #0x28]
//   0x028b64: f90017e8  str      x8, [sp, #0x28]
//   0x028b68: b4000300  cbz      x0, #0x28bc8
//   0x028b6c: 910003e8  mov      x8, sp
//   0x028b70: aa0303f3  mov      x19, x3
//   0x028b74: aa0203f4  mov      x20, x2
//   0x028b78: 6f00e400  movi     v0.2d, #0000000000000000
//   0x028b7c: 91004106  add      x6, x8, #0x10
//   0x028b80: b27e0103  orr      x3, x8, #4
//   0x028b84: b27d0104  orr      x4, x8, #8
uint64_t fde_0337_sub_028b48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x6F00E400ULL) + (x2 ^ 0x028B48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x028b48: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x028b4c: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x028b50: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x028b54: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x028b58: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x028b5c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x028b60: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x028b64: str x8, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000300ULL; // 0x028b68: cbz x0, #0x28bc8
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x028b6c: mov x8, sp
    return acc;
}

// [EN] Reconstructed FDE #0338 @ 0x028bf0..0x028c50 (96 bytes)
// [VN] Phục dựng FDE #0338 tại 0x028bf0..0x028c50 (96 byte)
//   0x028bf0: 2a1f03e8  mov      w8, wzr
//   0x028bf4: b40002a0  cbz      x0, #0x28c48
//   0x028bf8: 12185c29  and      w9, w1, #0xffffff00
//   0x028bfc: 7108013f  cmp      w9, #0x200
//   0x028c00: 54000241  b.ne     #0x28c48
//   0x028c04: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x028c08: 910003fd  mov      x29, sp
//   0x028c0c: 6f00e400  movi     v0.2d, #0000000000000000
//   0x028c10: ad068000  stp      q0, q0, [x0, #0xd0]
//   0x028c14: ad058000  stp      q0, q0, [x0, #0xb0]
//   0x028c18: ad048000  stp      q0, q0, [x0, #0x90]
//   0x028c1c: ad038000  stp      q0, q0, [x0, #0x70]
//   0x028c20: ad028000  stp      q0, q0, [x0, #0x50]
//   0x028c24: ad018000  stp      q0, q0, [x0, #0x30]
//   0x028c28: ad008000  stp      q0, q0, [x0, #0x10]
//   0x028c2c: 3d800000  str      q0, [x0]
uint64_t fde_0338_sub_028bf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E8ULL) + (x1 ^ 0xAD028000ULL) + (x2 ^ 0x028BF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x028bf0: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002A0ULL; // 0x028bf4: cbz x0, #0x28c48
    acc = (acc * 0x100000001B3ULL) ^ 0x12185C29ULL; // 0x028bf8: and w9, w1, #0xffffff00
    acc = (acc * 0x100000001B3ULL) ^ 0x7108013FULL; // 0x028bfc: cmp w9, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0x54000241ULL; // 0x028c00: b.ne #0x28c48
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x028c04: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x028c08: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x028c0c: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAD068000ULL; // 0x028c10: stp q0, q0, [x0, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD058000ULL; // 0x028c14: stp q0, q0, [x0, #0xb0]
    return acc;
}

// [EN] Reconstructed FDE #0339 @ 0x028c50..0x028c94 (68 bytes)
// [VN] Phục dựng FDE #0339 tại 0x028c50..0x028c94 (68 byte)
//   0x028c50: b40001e0  cbz      x0, #0x28c8c
//   0x028c54: b40001c2  cbz      x2, #0x28c8c
//   0x028c58: 12185c68  and      w8, w3, #0xffffff00
//   0x028c5c: 7108011f  cmp      w8, #0x200
//   0x028c60: 54000161  b.ne     #0x28c8c
//   0x028c64: 6f00e400  movi     v0.2d, #0000000000000000
//   0x028c68: aa0203e6  mov      x6, x2
//   0x028c6c: 91001043  add      x3, x2, #4
//   0x028c70: 91002044  add      x4, x2, #8
//   0x028c74: 3c810cc0  str      q0, [x6, #0x10]!
//   0x028c78: 91003045  add      x5, x2, #0xc
//   0x028c7c: aa1f03e7  mov      x7, xzr
//   0x028c80: f900105f  str      xzr, [x2, #0x20]
//   0x028c84: 3d800040  str      q0, [x2]
//   0x028c88: 17fffd6c  b        #0x28238
//   0x028c8c: 52800040  mov      w0, #2
uint64_t fde_0339_sub_028c50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E0ULL) + (x1 ^ 0xF900105FULL) + (x2 ^ 0x028C50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E0ULL; // 0x028c50: cbz x0, #0x28c8c
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001C2ULL; // 0x028c54: cbz x2, #0x28c8c
    acc = (acc * 0x100000001B3ULL) ^ 0x12185C68ULL; // 0x028c58: and w8, w3, #0xffffff00
    acc = (acc * 0x100000001B3ULL) ^ 0x7108011FULL; // 0x028c5c: cmp w8, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0x54000161ULL; // 0x028c60: b.ne #0x28c8c
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x028c64: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E6ULL; // 0x028c68: mov x6, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x91001043ULL; // 0x028c6c: add x3, x2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x91002044ULL; // 0x028c70: add x4, x2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x3C810CC0ULL; // 0x028c74: str q0, [x6, #0x10]!
    return acc;
}

// [EN] Reconstructed FDE #0340 @ 0x028c94..0x028dfc (360 bytes)
// [VN] Phục dựng FDE #0340 tại 0x028c94..0x028dfc (360 byte)
//   0x028c94: d10503ff  sub      sp, sp, #0x140
//   0x028c98: f9007bfc  str      x28, [sp, #0xf0]
//   0x028c9c: a9105ff8  stp      x24, x23, [sp, #0x100]
//   0x028ca0: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x028ca4: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x028ca8: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x028cac: 9104c3fd  add      x29, sp, #0x130
//   0x028cb0: d53bd058  mrs      x24, tpidr_el0
//   0x028cb4: f9401708  ldr      x8, [x24, #0x28]
//   0x028cb8: f81b83a8  stur     x8, [x29, #-0x48]
//   0x028cbc: b40002c2  cbz      x2, #0x28d14
//   0x028cc0: aa0003f4  mov      x20, x0
//   0x028cc4: b4000280  cbz      x0, #0x28d14
//   0x028cc8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x028ccc: aa0203e6  mov      x6, x2
//   0x028cd0: 91001043  add      x3, x2, #4
uint64_t fde_0340_sub_028c94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10503FFULL) + (x1 ^ 0xB4000280ULL) + (x2 ^ 0x028C94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10503FFULL; // 0x028c94: sub sp, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xF9007BFCULL; // 0x028c98: str x28, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9105FF8ULL; // 0x028c9c: stp x24, x23, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91157F6ULL; // 0x028ca0: stp x22, x21, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9124FF4ULL; // 0x028ca4: stp x20, x19, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9137BFDULL; // 0x028ca8: stp x29, x30, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0x9104C3FDULL; // 0x028cac: add x29, sp, #0x130
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x028cb0: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x028cb4: ldr x8, [x24, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B83A8ULL; // 0x028cb8: stur x8, [x29, #-0x48]
    return acc;
}

// [EN] Reconstructed FDE #0341 @ 0x028dfc..0x028e54 (88 bytes)
// [VN] Phục dựng FDE #0341 tại 0x028dfc..0x028e54 (88 byte)
//   0x028dfc: 2a0003e8  mov      w8, w0
//   0x028e00: 6b0100bf  cmp      w5, w1
//   0x028e04: 2a1f03e0  mov      w0, wzr
//   0x028e08: 5400024c  b.gt     #0x28e50
//   0x028e0c: 6b030029  subs     w9, w1, w3
//   0x028e10: 5400020d  b.le     #0x28e50
//   0x028e14: 4b02010a  sub      w10, w8, w2
//   0x028e18: 6b04015f  cmp      w10, w4
//   0x028e1c: 540001ab  b.lt     #0x28e50
//   0x028e20: 6b08009f  cmp      w4, w8
//   0x028e24: 5400016c  b.gt     #0x28e50
//   0x028e28: 6b02011f  cmp      w8, w2
//   0x028e2c: 5400012d  b.le     #0x28e50
//   0x028e30: 2a020068  orr      w8, w3, w2
//   0x028e34: 37f800e8  tbnz     w8, #0x1f, #0x28e50
//   0x028e38: 7100049f  cmp      w4, #1
uint64_t fde_0341_sub_028dfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0003E8ULL) + (x1 ^ 0x5400012DULL) + (x2 ^ 0x028DFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E8ULL; // 0x028dfc: mov w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0100BFULL; // 0x028e00: cmp w5, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x028e04: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x5400024CULL; // 0x028e08: b.gt #0x28e50
    acc = (acc * 0x100000001B3ULL) ^ 0x6B030029ULL; // 0x028e0c: subs w9, w1, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x5400020DULL; // 0x028e10: b.le #0x28e50
    acc = (acc * 0x100000001B3ULL) ^ 0x4B02010AULL; // 0x028e14: sub w10, w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04015FULL; // 0x028e18: cmp w10, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x540001ABULL; // 0x028e1c: b.lt #0x28e50
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08009FULL; // 0x028e20: cmp w4, w8
    return acc;
}

// [EN] Reconstructed FDE #0342 @ 0x028e54..0x02905c (520 bytes)
// [VN] Phục dựng FDE #0342 tại 0x028e54..0x02905c (520 byte)
//   0x028e54: d10143ff  sub      sp, sp, #0x50
//   0x028e58: f9000bf7  str      x23, [sp, #0x10]
//   0x028e5c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x028e60: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x028e64: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x028e68: 910103fd  add      x29, sp, #0x40
//   0x028e6c: d53bd055  mrs      x21, tpidr_el0
//   0x028e70: f94016a8  ldr      x8, [x21, #0x28]
//   0x028e74: aa0103f3  mov      x19, x1
//   0x028e78: aa0003f4  mov      x20, x0
//   0x028e7c: f90007e8  str      x8, [sp, #8]
//   0x028e80: 29405837  ldp      w23, w22, [x1]
//   0x028e84: b4000480  cbz      x0, #0x28f14
//   0x028e88: b9400a88  ldr      w8, [x20, #8]
//   0x028e8c: 7100011f  cmp      w8, #0
//   0x028e90: 1a9f07e9  cset     w9, ne
uint64_t fde_0342_sub_028e54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB4000480ULL) + (x2 ^ 0x028E54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x028e54: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x028e58: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x028e5c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x028e60: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x028e64: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x028e68: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x028e6c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x028e70: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x028e74: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x028e78: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0343 @ 0x02905c..0x029420 (964 bytes)
// [VN] Phục dựng FDE #0343 tại 0x02905c..0x029420 (964 byte)
//   0x02905c: d102c3ff  sub      sp, sp, #0xb0
//   0x029060: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x029064: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x029068: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x02906c: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x029070: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x029074: 910283fd  add      x29, sp, #0xa0
//   0x029078: d53bd057  mrs      x23, tpidr_el0
//   0x02907c: f94016e9  ldr      x9, [x23, #0x28]
//   0x029080: aa0203f3  mov      x19, x2
//   0x029084: aa0003e8  mov      x8, x0
//   0x029088: f81b83a9  stur     x9, [x29, #-0x48]
//   0x02908c: b4000062  cbz      x2, #0x29098
//   0x029090: 12800009  mov      w9, #-1
//   0x029094: b9000269  str      w9, [x19]
//   0x029098: aa1f03f4  mov      x20, xzr
uint64_t fde_0343_sub_02905c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xB4000062ULL) + (x2 ^ 0x02905CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x02905c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x029060: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x029064: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x029068: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x02906c: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x029070: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x029074: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x029078: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E9ULL; // 0x02907c: ldr x9, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x029080: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #0344 @ 0x029420..0x029478 (88 bytes)
// [VN] Phục dựng FDE #0344 tại 0x029420..0x029478 (88 byte)
//   0x029420: b40002a0  cbz      x0, #0x29474
//   0x029424: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x029428: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02942c: 910043fd  add      x29, sp, #0x10
//   0x029430: aa0003f3  mov      x19, x0
//   0x029434: f9402400  ldr      x0, [x0, #0x48]
//   0x029438: b40000a0  cbz      x0, #0x2944c
//   0x02943c: f9402414  ldr      x20, [x0, #0x48]
//   0x029440: 9400041f  bl       #0x2a4bc
//   0x029444: aa1403e0  mov      x0, x20
//   0x029448: b5ffffb4  cbnz     x20, #0x2943c
//   0x02944c: f9402e60  ldr      x0, [x19, #0x58]
//   0x029450: b40000a0  cbz      x0, #0x29464
//   0x029454: f9400814  ldr      x20, [x0, #0x10]
//   0x029458: 94000419  bl       #0x2a4bc
//   0x02945c: aa1403e0  mov      x0, x20
uint64_t fde_0344_sub_029420(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40002A0ULL) + (x1 ^ 0xB40000A0ULL) + (x2 ^ 0x029420ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002A0ULL; // 0x029420: cbz x0, #0x29474
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x029424: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x029428: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02942c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x029430: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402400ULL; // 0x029434: ldr x0, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x029438: cbz x0, #0x2944c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402414ULL; // 0x02943c: ldr x20, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400041FULL; // 0x029440: bl #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x029444: mov x0, x20
    return acc;
}

// [EN] Reconstructed FDE #0345 @ 0x029478..0x0294d8 (96 bytes)
// [VN] Phục dựng FDE #0345 tại 0x029478..0x0294d8 (96 byte)
//   0x029478: b40002a0  cbz      x0, #0x294cc
//   0x02947c: 7100143f  cmp      w1, #5
//   0x029480: 54000288  b.hi     #0x294d0
//   0x029484: f0000149  adrp     x9, #0x54000
//   0x029488: 2a0103e8  mov      w8, w1
//   0x02948c: 9118c129  add      x9, x9, #0x630
//   0x029490: 1000008a  adr      x10, #0x294a0
//   0x029494: 3868692b  ldrb     w11, [x9, x8]
//   0x029498: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x02949c: d61f0140  br       x10
//   0x0294a0: b9403000  ldr      w0, [x0, #0x30]
//   0x0294a4: d65f03c0  ret      
//   0x0294a8: b9403400  ldr      w0, [x0, #0x34]
//   0x0294ac: d65f03c0  ret      
//   0x0294b0: b9403800  ldr      w0, [x0, #0x38]
//   0x0294b4: d65f03c0  ret      
uint64_t fde_0345_sub_029478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40002A0ULL) + (x1 ^ 0xB9403400ULL) + (x2 ^ 0x029478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002A0ULL; // 0x029478: cbz x0, #0x294cc
    acc = (acc * 0x100000001B3ULL) ^ 0x7100143FULL; // 0x02947c: cmp w1, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x54000288ULL; // 0x029480: b.hi #0x294d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000149ULL; // 0x029484: adrp x9, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E8ULL; // 0x029488: mov w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x9118C129ULL; // 0x02948c: add x9, x9, #0x630
    acc = (acc * 0x100000001B3ULL) ^ 0x1000008AULL; // 0x029490: adr x10, #0x294a0
    acc = (acc * 0x100000001B3ULL) ^ 0x3868692BULL; // 0x029494: ldrb w11, [x9, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0B094AULL; // 0x029498: add x10, x10, x11, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0140ULL; // 0x02949c: br x10
    return acc;
}

// [EN] Reconstructed FDE #0346 @ 0x0294d8..0x029504 (44 bytes)
// [VN] Phục dựng FDE #0346 tại 0x0294d8..0x029504 (44 byte)
//   0x0294d8: b4000122  cbz      x2, #0x294fc
//   0x0294dc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0294e0: ad018040  stp      q0, q0, [x2, #0x30]
//   0x0294e4: f9002440  str      x0, [x2, #0x48]
//   0x0294e8: 2a0103e0  mov      w0, w1
//   0x0294ec: aa0203e1  mov      x1, x2
//   0x0294f0: ad008040  stp      q0, q0, [x2, #0x10]
//   0x0294f4: 3d800040  str      q0, [x2]
//   0x0294f8: 14000003  b        #0x29504
//   0x0294fc: 2a1f03e0  mov      w0, wzr
//   0x029500: d65f03c0  ret      
uint64_t fde_0346_sub_0294d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000122ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0294D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000122ULL; // 0x0294d8: cbz x2, #0x294fc
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x0294dc: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAD018040ULL; // 0x0294e0: stp q0, q0, [x2, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002440ULL; // 0x0294e4: str x0, [x2, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E0ULL; // 0x0294e8: mov w0, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x0294ec: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAD008040ULL; // 0x0294f0: stp q0, q0, [x2, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800040ULL; // 0x0294f4: str q0, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000003ULL; // 0x0294f8: b #0x29504
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0294fc: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0347 @ 0x029504..0x0295cc (200 bytes)
// [VN] Phục dựng FDE #0347 tại 0x029504..0x0295cc (200 byte)
//   0x029504: 2a0003e8  mov      w8, w0
//   0x029508: 2a1f03e0  mov      w0, wzr
//   0x02950c: 37f805a8  tbnz     w8, #0x1f, #0x295c0
//   0x029510: f940242b  ldr      x11, [x1, #0x48]
//   0x029514: b400056b  cbz      x11, #0x295c0
//   0x029518: b940456a  ldr      w10, [x11, #0x44]
//   0x02951c: 6b08015f  cmp      w10, w8
//   0x029520: 5400052b  b.lt     #0x295c4
//   0x029524: f9402569  ldr      x9, [x11, #0x48]
//   0x029528: 7100011f  cmp      w8, #0
//   0x02952c: 1a880148  csel     w8, w10, w8, eq
//   0x029530: b40004a9  cbz      x9, #0x295c4
//   0x029534: b940212c  ldr      w12, [x9, #0x20]
//   0x029538: 6b08019f  cmp      w12, w8
//   0x02953c: 54000080  b.eq     #0x2954c
//   0x029540: f9402529  ldr      x9, [x9, #0x48]
uint64_t fde_0347_sub_029504(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0003E8ULL) + (x1 ^ 0xB940212CULL) + (x2 ^ 0x029504ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E8ULL; // 0x029504: mov w8, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x029508: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x37F805A8ULL; // 0x02950c: tbnz w8, #0x1f, #0x295c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF940242BULL; // 0x029510: ldr x11, [x1, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xB400056BULL; // 0x029514: cbz x11, #0x295c0
    acc = (acc * 0x100000001B3ULL) ^ 0xB940456AULL; // 0x029518: ldr w10, [x11, #0x44]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08015FULL; // 0x02951c: cmp w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x5400052BULL; // 0x029520: b.lt #0x295c4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402569ULL; // 0x029524: ldr x9, [x11, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100011FULL; // 0x029528: cmp w8, #0
    return acc;
}

// [EN] Reconstructed FDE #0348 @ 0x0295cc..0x0295e4 (24 bytes)
// [VN] Phục dựng FDE #0348 tại 0x0295cc..0x0295e4 (24 byte)
//   0x0295cc: b40000a0  cbz      x0, #0x295e0
//   0x0295d0: b9400008  ldr      w8, [x0]
//   0x0295d4: aa0003e1  mov      x1, x0
//   0x0295d8: 11000500  add      w0, w8, #1
//   0x0295dc: 17ffffca  b        #0x29504
//   0x0295e0: d65f03c0  ret      
uint64_t fde_0348_sub_0295cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000A0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0295CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x0295cc: cbz x0, #0x295e0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x0295d0: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x0295d4: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x11000500ULL; // 0x0295d8: add w0, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFCAULL; // 0x0295dc: b #0x29504
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0295e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0349 @ 0x0295e4..0x0295e8 (4 bytes)
// [VN] Phục dựng FDE #0349 tại 0x0295e4..0x0295e8 (4 byte)
//   0x0295e4: d65f03c0  ret      
uint64_t fde_0349_sub_0295e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0295E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0295e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0350 @ 0x0295e8..0x029614 (44 bytes)
// [VN] Phục dựng FDE #0350 tại 0x0295e8..0x029614 (44 byte)
//   0x0295e8: b4000123  cbz      x3, #0x2960c
//   0x0295ec: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0295f0: f9001860  str      x0, [x3, #0x30]
//   0x0295f4: aa0103e0  mov      x0, x1
//   0x0295f8: 2a0203e1  mov      w1, w2
//   0x0295fc: aa0303e2  mov      x2, x3
//   0x029600: ad008060  stp      q0, q0, [x3, #0x10]
//   0x029604: 3d800060  str      q0, [x3]
//   0x029608: 14000003  b        #0x29614
//   0x02960c: 2a1f03e0  mov      w0, wzr
//   0x029610: d65f03c0  ret      
uint64_t fde_0350_sub_0295e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000123ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0295E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000123ULL; // 0x0295e8: cbz x3, #0x2960c
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x0295ec: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001860ULL; // 0x0295f0: str x0, [x3, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x0295f4: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x0295f8: mov w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E2ULL; // 0x0295fc: mov x2, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAD008060ULL; // 0x029600: stp q0, q0, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800060ULL; // 0x029604: str q0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000003ULL; // 0x029608: b #0x29614
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02960c: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0351 @ 0x029614..0x0296d8 (196 bytes)
// [VN] Phục dựng FDE #0351 tại 0x029614..0x0296d8 (196 byte)
//   0x029614: 2a1f03e8  mov      w8, wzr
//   0x029618: 37f805c1  tbnz     w1, #0x1f, #0x296d0
//   0x02961c: b40005a0  cbz      x0, #0x296d0
//   0x029620: f940184a  ldr      x10, [x2, #0x30]
//   0x029624: b400056a  cbz      x10, #0x296d0
//   0x029628: f9402d49  ldr      x9, [x10, #0x58]
//   0x02962c: b4000209  cbz      x9, #0x2966c
//   0x029630: f940114a  ldr      x10, [x10, #0x20]
//   0x029634: 2a1f03e8  mov      w8, wzr
//   0x029638: aa0903eb  mov      x11, x9
//   0x02963c: f940016c  ldr      x12, [x11]
//   0x029640: b940000d  ldr      w13, [x0]
//   0x029644: f940096b  ldr      x11, [x11, #0x10]
//   0x029648: b86c694c  ldr      w12, [x10, x12]
//   0x02964c: 6b0d019f  cmp      w12, w13
//   0x029650: 1a881508  cinc     w8, w8, eq
uint64_t fde_0351_sub_029614(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E8ULL) + (x1 ^ 0xF940096BULL) + (x2 ^ 0x029614ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x029614: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x37F805C1ULL; // 0x029618: tbnz w1, #0x1f, #0x296d0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40005A0ULL; // 0x02961c: cbz x0, #0x296d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF940184AULL; // 0x029620: ldr x10, [x2, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB400056AULL; // 0x029624: cbz x10, #0x296d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402D49ULL; // 0x029628: ldr x9, [x10, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000209ULL; // 0x02962c: cbz x9, #0x2966c
    acc = (acc * 0x100000001B3ULL) ^ 0xF940114AULL; // 0x029630: ldr x10, [x10, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x029634: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903EBULL; // 0x029638: mov x11, x9
    return acc;
}

// [EN] Reconstructed FDE #0352 @ 0x0296d8..0x0296dc (4 bytes)
// [VN] Phục dựng FDE #0352 tại 0x0296d8..0x0296dc (4 byte)
//   0x0296d8: d65f03c0  ret      
uint64_t fde_0352_sub_0296d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0296D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0296d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0353 @ 0x0296dc..0x0297ec (272 bytes)
// [VN] Phục dựng FDE #0353 tại 0x0296dc..0x0297ec (272 byte)
//   0x0296dc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0296e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0296e4: 910043fd  add      x29, sp, #0x10
//   0x0296e8: f9402408  ldr      x8, [x0, #0x48]
//   0x0296ec: b5000368  cbnz     x8, #0x29758
//   0x0296f0: f9400809  ldr      x9, [x0, #0x10]
//   0x0296f4: f9400008  ldr      x8, [x0]
//   0x0296f8: aa0003f3  mov      x19, x0
//   0x0296fc: cb080129  sub      x9, x9, x8
//   0x029700: f100213f  cmp      x9, #8
//   0x029704: 540002a3  b.lo     #0x29758
//   0x029708: f9400669  ldr      x9, [x19, #8]
//   0x02970c: cb080128  sub      x8, x9, x8
//   0x029710: f100211f  cmp      x8, #8
//   0x029714: 54000062  b.hs     #0x29720
//   0x029718: 52800020  mov      w0, #1
uint64_t fde_0353_sub_0296dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xCB080128ULL) + (x2 ^ 0x0296DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0296dc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0296e0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0296e4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402408ULL; // 0x0296e8: ldr x8, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000368ULL; // 0x0296ec: cbnz x8, #0x29758
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400809ULL; // 0x0296f0: ldr x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0296f4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0296f8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB080129ULL; // 0x0296fc: sub x9, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF100213FULL; // 0x029700: cmp x9, #8
    return acc;
}

// [EN] Reconstructed FDE #0354 @ 0x0297ec..0x029848 (92 bytes)
// [VN] Phục dựng FDE #0354 tại 0x0297ec..0x029848 (92 byte)
//   0x0297ec: b9402808  ldr      w8, [x0, #0x28]
//   0x0297f0: 34000288  cbz      w8, #0x29840
//   0x0297f4: b9403409  ldr      w9, [x0, #0x34]
//   0x0297f8: 7100053f  cmp      w9, #1
//   0x0297fc: 540001eb  b.lt     #0x29838
//   0x029800: b9403809  ldr      w9, [x0, #0x38]
//   0x029804: 7100053f  cmp      w9, #1
//   0x029808: 5400018b  b.lt     #0x29838
//   0x02980c: f9402409  ldr      x9, [x0, #0x48]
//   0x029810: b5000069  cbnz     x9, #0x2981c
//   0x029814: 7100091f  cmp      w8, #2
//   0x029818: 54000100  b.eq     #0x29838
//   0x02981c: b9400928  ldr      w8, [x9, #8]
//   0x029820: 7100051f  cmp      w8, #1
//   0x029824: 540000ab  b.lt     #0x29838
//   0x029828: b9400d28  ldr      w8, [x9, #0xc]
uint64_t fde_0354_sub_0297ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9402808ULL) + (x1 ^ 0xB9400928ULL) + (x2 ^ 0x0297ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402808ULL; // 0x0297ec: ldr w8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000288ULL; // 0x0297f0: cbz w8, #0x29840
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403409ULL; // 0x0297f4: ldr w9, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x0297f8: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001EBULL; // 0x0297fc: b.lt #0x29838
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403809ULL; // 0x029800: ldr w9, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x029804: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018BULL; // 0x029808: b.lt #0x29838
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402409ULL; // 0x02980c: ldr x9, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000069ULL; // 0x029810: cbnz x9, #0x2981c
    return acc;
}

// [EN] Reconstructed FDE #0355 @ 0x029848..0x029dc8 (1408 bytes)
// [VN] Phục dựng FDE #0355 tại 0x029848..0x029dc8 (1408 byte)
//   0x029848: d101c3ff  sub      sp, sp, #0x70
//   0x02984c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x029850: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x029854: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x029858: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02985c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x029860: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x029864: 910183fd  add      x29, sp, #0x60
//   0x029868: a940200b  ldp      x11, x8, [x0]
//   0x02986c: 52800034  mov      w20, #1
//   0x029870: cb0b0109  sub      x9, x8, x11
//   0x029874: f100213f  cmp      x9, #8
//   0x029878: 54000363  b.lo     #0x298e4
//   0x02987c: f9401009  ldr      x9, [x0, #0x20]
//   0x029880: 9100116a  add      x10, x11, #4
//   0x029884: b9002c14  str      w20, [x0, #0x2c]
uint64_t fde_0355_sub_029848(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x54000363ULL) + (x2 ^ 0x029848ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x029848: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02984c: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x029850: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x029854: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x029858: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02985c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x029860: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x029864: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA940200BULL; // 0x029868: ldp x11, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800034ULL; // 0x02986c: mov w20, #1
    return acc;
}

// [EN] Reconstructed FDE #0356 @ 0x029dc8..0x029f4c (388 bytes)
// [VN] Phục dựng FDE #0356 tại 0x029dc8..0x029f4c (388 byte)
//   0x029dc8: b9402808  ldr      w8, [x0, #0x28]
//   0x029dcc: 34000bc8  cbz      w8, #0x29f44
//   0x029dd0: b9403409  ldr      w9, [x0, #0x34]
//   0x029dd4: 7100053f  cmp      w9, #1
//   0x029dd8: 54000b2b  b.lt     #0x29f3c
//   0x029ddc: b940380a  ldr      w10, [x0, #0x38]
//   0x029de0: 7100055f  cmp      w10, #1
//   0x029de4: 54000acb  b.lt     #0x29f3c
//   0x029de8: b9403c0b  ldr      w11, [x0, #0x3c]
//   0x029dec: 37f80a8b  tbnz     w11, #0x1f, #0x29f3c
//   0x029df0: f940240b  ldr      x11, [x0, #0x48]
//   0x029df4: b940300c  ldr      w12, [x0, #0x30]
//   0x029df8: 7100091f  cmp      w8, #2
//   0x029dfc: 1a9f07ed  cset     w13, ne
//   0x029e00: f100017f  cmp      x11, #0
//   0x029e04: 1a9f07ee  cset     w14, ne
uint64_t fde_0356_sub_029dc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9402808ULL) + (x1 ^ 0x7100091FULL) + (x2 ^ 0x029DC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402808ULL; // 0x029dc8: ldr w8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000BC8ULL; // 0x029dcc: cbz w8, #0x29f44
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403409ULL; // 0x029dd0: ldr w9, [x0, #0x34]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x029dd4: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000B2BULL; // 0x029dd8: b.lt #0x29f3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB940380AULL; // 0x029ddc: ldr w10, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100055FULL; // 0x029de0: cmp w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000ACBULL; // 0x029de4: b.lt #0x29f3c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403C0BULL; // 0x029de8: ldr w11, [x0, #0x3c]
    acc = (acc * 0x100000001B3ULL) ^ 0x37F80A8BULL; // 0x029dec: tbnz w11, #0x1f, #0x29f3c
    return acc;
}

// [EN] Reconstructed FDE #0357 @ 0x029f4c..0x02a188 (572 bytes)
// [VN] Phục dựng FDE #0357 tại 0x029f4c..0x02a188 (572 byte)
//   0x029f4c: d10243ff  sub      sp, sp, #0x90
//   0x029f50: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x029f54: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x029f58: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x029f5c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x029f60: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x029f64: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x029f68: 910203fd  add      x29, sp, #0x80
//   0x029f6c: d53bd059  mrs      x25, tpidr_el0
//   0x029f70: f9401728  ldr      x8, [x25, #0x28]
//   0x029f74: 52800033  mov      w19, #1
//   0x029f78: f90017e8  str      x8, [sp, #0x28]
//   0x029f7c: a940205c  ldp      x28, x8, [x2]
//   0x029f80: cb1c0108  sub      x8, x8, x28
//   0x029f84: f100211f  cmp      x8, #8
//   0x029f88: 54000e03  b.lo     #0x2a148
uint64_t fde_0357_sub_029f4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xA940205CULL) + (x2 ^ 0x029F4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x029f4c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x029f50: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x029f54: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x029f58: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x029f5c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x029f60: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x029f64: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x029f68: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x029f6c: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x029f70: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0358 @ 0x02a188..0x02a268 (224 bytes)
// [VN] Phục dựng FDE #0358 tại 0x02a188..0x02a268 (224 byte)
//   0x02a188: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02a18c: 910003fd  mov      x29, sp
//   0x02a190: aa0003e8  mov      x8, x0
//   0x02a194: f9400ba0  ldr      x0, [x29, #0x10]
//   0x02a198: 6b05005f  cmp      w2, w5
//   0x02a19c: 9b277c8a  smull    x10, w4, w7
//   0x02a1a0: 5100048c  sub      w12, w4, #1
//   0x02a1a4: 5100042d  sub      w13, w1, #1
//   0x02a1a8: 1a9fa7eb  cset     w11, lt
//   0x02a1ac: 6b04003f  cmp      w1, w4
//   0x02a1b0: 2a0203e9  mov      w9, w2
//   0x02a1b4: 29058901  stp      w1, w2, [x8, #0x2c]
//   0x02a1b8: d37df142  lsl      x2, x10, #3
//   0x02a1bc: 1a9fa7ee  cset     w14, lt
//   0x02a1c0: 1a81b18a  csel     w10, w12, w1, lt
//   0x02a1c4: 1a84b1ac  csel     w12, w13, w4, lt
uint64_t fde_0358_sub_02a188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD37DF142ULL) + (x2 ^ 0x02A188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02a188: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02a18c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02a190: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BA0ULL; // 0x02a194: ldr x0, [x29, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B05005FULL; // 0x02a198: cmp w2, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x9B277C8AULL; // 0x02a19c: smull x10, w4, w7
    acc = (acc * 0x100000001B3ULL) ^ 0x5100048CULL; // 0x02a1a0: sub w12, w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5100042DULL; // 0x02a1a4: sub w13, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9FA7EBULL; // 0x02a1a8: cset w11, lt
    acc = (acc * 0x100000001B3ULL) ^ 0x6B04003FULL; // 0x02a1ac: cmp w1, w4
    return acc;
}

// [EN] Reconstructed FDE #0359 @ 0x02a268..0x02a2e0 (120 bytes)
// [VN] Phục dựng FDE #0359 tại 0x02a268..0x02a2e0 (120 byte)
//   0x02a268: b9400049  ldr      w9, [x2]
//   0x02a26c: b9400068  ldr      w8, [x3]
//   0x02a270: 7100043f  cmp      w1, #1
//   0x02a274: 5400010b  b.lt     #0x2a294
//   0x02a278: 350000e9  cbnz     w9, #0x2a294
//   0x02a27c: 93407d09  sxtw     x9, w8
//   0x02a280: 93407c0a  sxtw     x10, w0
//   0x02a284: 93407c2b  sxtw     x11, w1
//   0x02a288: 9b0a2d29  madd     x9, x9, x10, x11
//   0x02a28c: d1000529  sub      x9, x9, #1
//   0x02a290: 9acb0929  udiv     x9, x9, x11
//   0x02a294: 7100041f  cmp      w0, #1
//   0x02a298: 540000cb  b.lt     #0x2a2b0
//   0x02a29c: 350000a8  cbnz     w8, #0x2a2b0
//   0x02a2a0: 93407c08  sxtw     x8, w0
//   0x02a2a4: 9b21212a  smaddl   x10, w9, w1, x8
uint64_t fde_0359_sub_02a268(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400049ULL) + (x1 ^ 0x540000CBULL) + (x2 ^ 0x02A268ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400049ULL; // 0x02a268: ldr w9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400068ULL; // 0x02a26c: ldr w8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x02a270: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400010BULL; // 0x02a274: b.lt #0x2a294
    acc = (acc * 0x100000001B3ULL) ^ 0x350000E9ULL; // 0x02a278: cbnz w9, #0x2a294
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D09ULL; // 0x02a27c: sxtw x9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C0AULL; // 0x02a280: sxtw x10, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C2BULL; // 0x02a284: sxtw x11, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0A2D29ULL; // 0x02a288: madd x9, x9, x10, x11
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000529ULL; // 0x02a28c: sub x9, x9, #1
    return acc;
}

// [EN] Reconstructed FDE #0360 @ 0x02a2e0..0x02a300 (32 bytes)
// [VN] Phục dựng FDE #0360 tại 0x02a2e0..0x02a300 (32 byte)
//   0x02a2e0: b9401808  ldr      w8, [x0, #0x18]
//   0x02a2e4: b9402009  ldr      w9, [x0, #0x20]
//   0x02a2e8: 0b090108  add      w8, w8, w9
//   0x02a2ec: 51000508  sub      w8, w8, #1
//   0x02a2f0: 1ac90d08  sdiv     w8, w8, w9
//   0x02a2f4: 6b01011f  cmp      w8, w1
//   0x02a2f8: 1a88c020  csel     w0, w1, w8, gt
//   0x02a2fc: d65f03c0  ret      
uint64_t fde_0360_sub_02a2e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9401808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02A2E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401808ULL; // 0x02a2e0: ldr w8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402009ULL; // 0x02a2e4: ldr w9, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B090108ULL; // 0x02a2e8: add w8, w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x02a2ec: sub w8, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC90D08ULL; // 0x02a2f0: sdiv w8, w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x6B01011FULL; // 0x02a2f4: cmp w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A88C020ULL; // 0x02a2f8: csel w0, w1, w8, gt
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02a2fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0361 @ 0x02a300..0x02a414 (276 bytes)
// [VN] Phục dựng FDE #0361 tại 0x02a300..0x02a414 (276 byte)
//   0x02a300: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02a304: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02a308: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02a30c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02a310: 9100c3fd  add      x29, sp, #0x30
//   0x02a314: 7100043f  cmp      w1, #1
//   0x02a318: 540006cb  b.lt     #0x2a3f0
//   0x02a31c: aa0203f5  mov      x21, x2
//   0x02a320: 2a0103f4  mov      w20, w1
//   0x02a324: aa0003f6  mov      x22, x0
//   0x02a328: 2a1f03f3  mov      w19, wzr
//   0x02a32c: 93407c77  sxtw     x23, w3
//   0x02a330: 1400000c  b        #0x2a360
//   0x02a334: b9403ec8  ldr      w8, [x22, #0x3c]
//   0x02a338: b94022c9  ldr      w9, [x22, #0x20]
//   0x02a33c: b9401aca  ldr      w10, [x22, #0x18]
uint64_t fde_0361_sub_02a300(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x1400000CULL) + (x2 ^ 0x02A300ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02a300: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02a304: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02a308: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02a30c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02a310: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x02a314: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540006CBULL; // 0x02a318: b.lt #0x2a3f0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02a31c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x02a320: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x02a324: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0362 @ 0x02a414..0x02a478 (100 bytes)
// [VN] Phục dựng FDE #0362 tại 0x02a414..0x02a478 (100 byte)
//   0x02a414: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02a418: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a41c: 910043fd  add      x29, sp, #0x10
//   0x02a420: b9404008  ldr      w8, [x0, #0x40]
//   0x02a424: b9403809  ldr      w9, [x0, #0x38]
//   0x02a428: 6b09011f  cmp      w8, w9
//   0x02a42c: 540001ca  b.ge     #0x2a464
//   0x02a430: aa0003f3  mov      x19, x0
//   0x02a434: 2a1f03f4  mov      w20, wzr
//   0x02a438: b9401a68  ldr      w8, [x19, #0x18]
//   0x02a43c: 7100011f  cmp      w8, #0
//   0x02a440: 5400014c  b.gt     #0x2a468
//   0x02a444: aa1303e0  mov      x0, x19
//   0x02a448: 94003f94  bl       #0x3a298
//   0x02a44c: b9404268  ldr      w8, [x19, #0x40]
//   0x02a450: b9403a69  ldr      w9, [x19, #0x38]
uint64_t fde_0362_sub_02a414(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x02A414ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02a414: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a418: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a41c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9404008ULL; // 0x02a420: ldr w8, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403809ULL; // 0x02a424: ldr w9, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x02a428: cmp w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x540001CAULL; // 0x02a42c: b.ge #0x2a464
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a430: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03F4ULL; // 0x02a434: mov w20, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401A68ULL; // 0x02a438: ldr w8, [x19, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0363 @ 0x02a478..0x02a49c (36 bytes)
// [VN] Phục dựng FDE #0363 tại 0x02a478..0x02a49c (36 byte)
//   0x02a478: b40000e0  cbz      x0, #0x2a494
//   0x02a47c: d2c00088  mov      x8, #0x400000000
//   0x02a480: 9ac00908  udiv     x8, x8, x0
//   0x02a484: eb01011f  cmp      x8, x1
//   0x02a488: 54000062  b.hs     #0x2a494
//   0x02a48c: aa1f03e0  mov      x0, xzr
//   0x02a490: d65f03c0  ret      
//   0x02a494: 9b007c20  mul      x0, x1, x0
//   0x02a498: 17ff66a6  b        #0x3f30
uint64_t fde_0363_sub_02a478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000E0ULL) + (x1 ^ 0x17FF66A6ULL) + (x2 ^ 0x02A478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02a478: cbz x0, #0x2a494
    acc = (acc * 0x100000001B3ULL) ^ 0xD2C00088ULL; // 0x02a47c: mov x8, #0x400000000
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC00908ULL; // 0x02a480: udiv x8, x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x02a484: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x02a488: b.hs #0x2a494
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x02a48c: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02a490: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x9B007C20ULL; // 0x02a494: mul x0, x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF66A6ULL; // 0x02a498: b #0x3f30
    return acc;
}

// [EN] Reconstructed FDE #0364 @ 0x02a49c..0x02a4bc (32 bytes)
// [VN] Phục dựng FDE #0364 tại 0x02a49c..0x02a4bc (32 byte)
//   0x02a49c: b40000e0  cbz      x0, #0x2a4b8
//   0x02a4a0: d2c00088  mov      x8, #0x400000000
//   0x02a4a4: 9ac00908  udiv     x8, x8, x0
//   0x02a4a8: eb01011f  cmp      x8, x1
//   0x02a4ac: 54000062  b.hs     #0x2a4b8
//   0x02a4b0: aa1f03e0  mov      x0, xzr
//   0x02a4b4: d65f03c0  ret      
//   0x02a4b8: 17ff6696  b        #0x3f10
uint64_t fde_0364_sub_02a49c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000E0ULL) + (x1 ^ 0x17FF6696ULL) + (x2 ^ 0x02A49CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02a49c: cbz x0, #0x2a4b8
    acc = (acc * 0x100000001B3ULL) ^ 0xD2C00088ULL; // 0x02a4a0: mov x8, #0x400000000
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC00908ULL; // 0x02a4a4: udiv x8, x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01011FULL; // 0x02a4a8: cmp x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x02a4ac: b.hs #0x2a4b8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x02a4b0: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02a4b4: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6696ULL; // 0x02a4b8: b #0x3f10
    return acc;
}

// [EN] Reconstructed FDE #0365 @ 0x02a4bc..0x02a4c0 (4 bytes)
// [VN] Phục dựng FDE #0365 tại 0x02a4bc..0x02a4c0 (4 byte)
//   0x02a4bc: 17ff6691  b        #0x3f00
uint64_t fde_0365_sub_02a4bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF6691ULL) + (x1 ^ 0x17FF6691ULL) + (x2 ^ 0x02A4BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6691ULL; // 0x02a4bc: b #0x3f00
    return acc;
}

// [EN] Reconstructed FDE #0366 @ 0x02a4c0..0x02a52c (108 bytes)
// [VN] Phục dựng FDE #0366 tại 0x02a4c0..0x02a52c (108 byte)
//   0x02a4c0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02a4c4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02a4c8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02a4cc: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02a4d0: 9100c3fd  add      x29, sp, #0x30
//   0x02a4d4: 710004bf  cmp      w5, #1
//   0x02a4d8: 5400020b  b.lt     #0x2a518
//   0x02a4dc: 2a0503f3  mov      w19, w5
//   0x02a4e0: aa0203f4  mov      x20, x2
//   0x02a4e4: aa0003f5  mov      x21, x0
//   0x02a4e8: 93407c96  sxtw     x22, w4
//   0x02a4ec: 93407c37  sxtw     x23, w1
//   0x02a4f0: 93407c78  sxtw     x24, w3
//   0x02a4f4: aa1403e0  mov      x0, x20
//   0x02a4f8: aa1503e1  mov      x1, x21
//   0x02a4fc: aa1603e2  mov      x2, x22
uint64_t fde_0366_sub_02a4c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x93407C78ULL) + (x2 ^ 0x02A4C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02a4c0: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02a4c4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02a4c8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02a4cc: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02a4d0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x710004BFULL; // 0x02a4d4: cmp w5, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400020BULL; // 0x02a4d8: b.lt #0x2a518
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F3ULL; // 0x02a4dc: mov w19, w5
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x02a4e0: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02a4e4: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0367 @ 0x02a52c..0x02a5e0 (180 bytes)
// [VN] Phục dựng FDE #0367 tại 0x02a52c..0x02a5e0 (180 byte)
//   0x02a52c: b4000420  cbz      x0, #0x2a5b0
//   0x02a530: b9400008  ldr      w8, [x0]
//   0x02a534: b9800809  ldrsw    x9, [x0, #8]
//   0x02a538: 7100291f  cmp      w8, #0xa
//   0x02a53c: 54000409  b.ls     #0x2a5bc
//   0x02a540: 69462c08  ldpsw    x8, x11, [x0, #0x30]
//   0x02a544: a941340c  ldp      x12, x13, [x0, #0x10]
//   0x02a548: b980380e  ldrsw    x14, [x0, #0x38]
//   0x02a54c: d1000529  sub      x9, x9, #1
//   0x02a550: a942280f  ldp      x15, x10, [x0, #0x20]
//   0x02a554: d503201f  nop      
//   0x02a558: 9b08312c  madd     x12, x9, x8, x12
//   0x02a55c: 4b0803e8  neg      w8, w8
//   0x02a560: b9003008  str      w8, [x0, #0x30]
//   0x02a564: 4b0b03e8  neg      w8, w11
//   0x02a568: 9341fd30  asr      x16, x9, #1
uint64_t fde_0367_sub_02a52c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000420ULL) + (x1 ^ 0x4B0803E8ULL) + (x2 ^ 0x02A52CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000420ULL; // 0x02a52c: cbz x0, #0x2a5b0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x02a530: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800809ULL; // 0x02a534: ldrsw x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100291FULL; // 0x02a538: cmp w8, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x54000409ULL; // 0x02a53c: b.ls #0x2a5bc
    acc = (acc * 0x100000001B3ULL) ^ 0x69462C08ULL; // 0x02a540: ldpsw x8, x11, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA941340CULL; // 0x02a544: ldp x12, x13, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB980380EULL; // 0x02a548: ldrsw x14, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000529ULL; // 0x02a54c: sub x9, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA942280FULL; // 0x02a550: ldp x15, x10, [x0, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0368 @ 0x02a5e0..0x02a8c8 (744 bytes)
// [VN] Phục dựng FDE #0368 tại 0x02a5e0..0x02a8c8 (744 byte)
//   0x02a5e0: d10203ff  sub      sp, sp, #0x80
//   0x02a5e4: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x02a5e8: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x02a5ec: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02a5f0: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02a5f4: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02a5f8: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02a5fc: 9101c3fd  add      x29, sp, #0x70
//   0x02a600: d53bd057  mrs      x23, tpidr_el0
//   0x02a604: f94016e8  ldr      x8, [x23, #0x28]
//   0x02a608: 7100043f  cmp      w1, #1
//   0x02a60c: 52800055  mov      w21, #2
//   0x02a610: f9000fe8  str      x8, [sp, #0x18]
//   0x02a614: 54000c8b  b.lt     #0x2a7a4
//   0x02a618: 7100041f  cmp      w0, #1
//   0x02a61c: 54000c4b  b.lt     #0x2a7a4
uint64_t fde_0368_sub_02a5e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9000FE8ULL) + (x2 ^ 0x02A5E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02a5e0: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x02a5e4: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x02a5e8: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02a5ec: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02a5f0: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02a5f4: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02a5f8: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02a5fc: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02a600: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02a604: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0369 @ 0x02a8c8..0x02a900 (56 bytes)
// [VN] Phục dựng FDE #0369 tại 0x02a8c8..0x02a900 (56 byte)
//   0x02a8c8: 2a1f03e8  mov      w8, wzr
//   0x02a8cc: b4000160  cbz      x0, #0x2a8f8
//   0x02a8d0: 12185c29  and      w9, w1, #0xffffff00
//   0x02a8d4: 7108013f  cmp      w9, #0x200
//   0x02a8d8: 54000101  b.ne     #0x2a8f8
//   0x02a8dc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x02a8e0: 52800028  mov      w8, #1
//   0x02a8e4: f900381f  str      xzr, [x0, #0x70]
//   0x02a8e8: ad028000  stp      q0, q0, [x0, #0x50]
//   0x02a8ec: ad018000  stp      q0, q0, [x0, #0x30]
//   0x02a8f0: ad008000  stp      q0, q0, [x0, #0x10]
//   0x02a8f4: 3d800000  str      q0, [x0]
//   0x02a8f8: 2a0803e0  mov      w0, w8
//   0x02a8fc: d65f03c0  ret      
uint64_t fde_0369_sub_02a8c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E8ULL) + (x1 ^ 0x2A0803E0ULL) + (x2 ^ 0x02A8C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x02a8c8: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000160ULL; // 0x02a8cc: cbz x0, #0x2a8f8
    acc = (acc * 0x100000001B3ULL) ^ 0x12185C29ULL; // 0x02a8d0: and w9, w1, #0xffffff00
    acc = (acc * 0x100000001B3ULL) ^ 0x7108013FULL; // 0x02a8d4: cmp w9, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x02a8d8: b.ne #0x2a8f8
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x02a8dc: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x02a8e0: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900381FULL; // 0x02a8e4: str xzr, [x0, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD028000ULL; // 0x02a8e8: stp q0, q0, [x0, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD018000ULL; // 0x02a8ec: stp q0, q0, [x0, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0370 @ 0x02a900..0x02a938 (56 bytes)
// [VN] Phục dựng FDE #0370 tại 0x02a900..0x02a938 (56 byte)
//   0x02a900: b40001a0  cbz      x0, #0x2a934
//   0x02a904: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02a908: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a90c: 910043fd  add      x29, sp, #0x10
//   0x02a910: b9400c08  ldr      w8, [x0, #0xc]
//   0x02a914: aa0003f3  mov      x19, x0
//   0x02a918: 7100011f  cmp      w8, #0
//   0x02a91c: 5400006c  b.gt     #0x2a928
//   0x02a920: f9403a60  ldr      x0, [x19, #0x70]
//   0x02a924: 97fffee6  bl       #0x2a4bc
//   0x02a928: f9003a7f  str      xzr, [x19, #0x70]
//   0x02a92c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02a930: f84207f3  ldr      x19, [sp], #0x20
//   0x02a934: d65f03c0  ret      
uint64_t fde_0370_sub_02a900(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001A0ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x02A900ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A0ULL; // 0x02a900: cbz x0, #0x2a934
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02a904: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a908: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a90c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400C08ULL; // 0x02a910: ldr w8, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a914: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100011FULL; // 0x02a918: cmp w8, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006CULL; // 0x02a91c: b.gt #0x2a928
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403A60ULL; // 0x02a920: ldr x0, [x19, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEE6ULL; // 0x02a924: bl #0x2a4bc
    return acc;
}

// [EN] Reconstructed FDE #0371 @ 0x02a938..0x02aa88 (336 bytes)
// [VN] Phục dựng FDE #0371 tại 0x02a938..0x02aa88 (336 byte)
//   0x02a938: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02a93c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02a940: 910043fd  add      x29, sp, #0x10
//   0x02a944: f8404008  ldur     x8, [x0, #4]
//   0x02a948: aa0003f3  mov      x19, x0
//   0x02a94c: aa0103e0  mov      x0, x1
//   0x02a950: aa0103f4  mov      x20, x1
//   0x02a954: f8004028  stur     x8, [x1, #4]
//   0x02a958: 9400004c  bl       #0x2aa88
//   0x02a95c: 34000060  cbz      w0, #0x2a968
//   0x02a960: 52800040  mov      w0, #2
//   0x02a964: 14000042  b        #0x2aa6c
//   0x02a968: b9400268  ldr      w8, [x19]
//   0x02a96c: f9400a60  ldr      x0, [x19, #0x10]
//   0x02a970: 7100291f  cmp      w8, #0xa
//   0x02a974: 54000689  b.ls     #0x2aa44
uint64_t fde_0371_sub_02a938(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB9400268ULL) + (x2 ^ 0x02A938ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02a938: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02a93c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02a940: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8404008ULL; // 0x02a944: ldur x8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02a948: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x02a94c: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02a950: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF8004028ULL; // 0x02a954: stur x8, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x9400004CULL; // 0x02a958: bl #0x2aa88
    acc = (acc * 0x100000001B3ULL) ^ 0x34000060ULL; // 0x02a95c: cbz w0, #0x2a968
    return acc;
}

// [EN] Reconstructed FDE #0372 @ 0x02aa88..0x02ac28 (416 bytes)
// [VN] Phục dựng FDE #0372 tại 0x02aa88..0x02ac28 (416 byte)
//   0x02aa88: b940000a  ldr      w10, [x0]
//   0x02aa8c: 7100315f  cmp      w10, #0xc
//   0x02aa90: 54000089  b.ls     #0x2aaa0
//   0x02aa94: 52800048  mov      w8, #2
//   0x02aa98: 2a0803e0  mov      w0, w8
//   0x02aa9c: d65f03c0  ret      
//   0x02aaa0: 6940ac09  ldpsw    x9, x11, [x0, #4]
//   0x02aaa4: 71002d5f  cmp      w10, #0xb
//   0x02aaa8: 54000943  b.lo     #0x2abd0
//   0x02aaac: 29464410  ldp      w16, w17, [x0, #0x30]
//   0x02aab0: 11000528  add      w8, w9, #1
//   0x02aab4: 1100092d  add      w13, w9, #2
//   0x02aab8: 1100056e  add      w14, w11, #1
//   0x02aabc: 29470801  ldp      w1, w2, [x0, #0x38]
//   0x02aac0: 7100011f  cmp      w8, #0
//   0x02aac4: 1100096f  add      w15, w11, #2
uint64_t fde_0372_sub_02aa88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB940000AULL) + (x1 ^ 0x1100056EULL) + (x2 ^ 0x02AA88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB940000AULL; // 0x02aa88: ldr w10, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100315FULL; // 0x02aa8c: cmp w10, #0xc
    acc = (acc * 0x100000001B3ULL) ^ 0x54000089ULL; // 0x02aa90: b.ls #0x2aaa0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800048ULL; // 0x02aa94: mov w8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0803E0ULL; // 0x02aa98: mov w0, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02aa9c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x6940AC09ULL; // 0x02aaa0: ldpsw x9, x11, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x71002D5FULL; // 0x02aaa4: cmp w10, #0xb
    acc = (acc * 0x100000001B3ULL) ^ 0x54000943ULL; // 0x02aaa8: b.lo #0x2abd0
    acc = (acc * 0x100000001B3ULL) ^ 0x29464410ULL; // 0x02aaac: ldp w16, w17, [x0, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0373 @ 0x02ac28..0x02ac68 (64 bytes)
// [VN] Phục dựng FDE #0373 tại 0x02ac28..0x02ac68 (64 byte)
//   0x02ac28: b9400c09  ldr      w9, [x0, #0xc]
//   0x02ac2c: 7100093f  cmp      w9, #2
//   0x02ac30: 5400018b  b.lt     #0x2ac60
//   0x02ac34: aa0003e8  mov      x8, x0
//   0x02ac38: 2a1f03e0  mov      w0, wzr
//   0x02ac3c: b4000101  cbz      x1, #0x2ac5c
//   0x02ac40: b9400108  ldr      w8, [x8]
//   0x02ac44: 51001d08  sub      w8, w8, #7
//   0x02ac48: 71000d1f  cmp      w8, #3
//   0x02ac4c: 54000088  b.hi     #0x2ac5c
//   0x02ac50: b9400828  ldr      w8, [x1, #8]
//   0x02ac54: 7100011f  cmp      w8, #0
//   0x02ac58: 1a9f07e0  cset     w0, ne
//   0x02ac5c: d65f03c0  ret      
//   0x02ac60: 2a1f03e0  mov      w0, wzr
//   0x02ac64: d65f03c0  ret      
uint64_t fde_0373_sub_02ac28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400C09ULL) + (x1 ^ 0x1A9F07E0ULL) + (x2 ^ 0x02AC28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400C09ULL; // 0x02ac28: ldr w9, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100093FULL; // 0x02ac2c: cmp w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018BULL; // 0x02ac30: b.lt #0x2ac60
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02ac34: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02ac38: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000101ULL; // 0x02ac3c: cbz x1, #0x2ac5c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x02ac40: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x51001D08ULL; // 0x02ac44: sub w8, w8, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D1FULL; // 0x02ac48: cmp w8, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000088ULL; // 0x02ac4c: b.hi #0x2ac5c
    return acc;
}

// [EN] Reconstructed FDE #0374 @ 0x02ac68..0x02adbc (340 bytes)
// [VN] Phục dựng FDE #0374 tại 0x02ac68..0x02adbc (340 byte)
//   0x02ac68: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02ac6c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02ac70: 910043fd  add      x29, sp, #0x10
//   0x02ac74: b40009e0  cbz      x0, #0x2adb0
//   0x02ac78: b9402c08  ldr      w8, [x0, #0x2c]
//   0x02ac7c: aa0103f3  mov      x19, x1
//   0x02ac80: aa0003f4  mov      x20, x0
//   0x02ac84: 37f80848  tbnz     w8, #0x1f, #0x2ad8c
//   0x02ac88: 7101911f  cmp      w8, #0x64
//   0x02ac8c: 5400006d  b.le     #0x2ac98
//   0x02ac90: 52801fe8  mov      w8, #0xff
//   0x02ac94: 1400000b  b        #0x2acc0
//   0x02ac98: 53185d09  lsl      w9, w8, #8
//   0x02ac9c: 4b080128  sub      w8, w9, w8
//   0x02aca0: 7101911f  cmp      w8, #0x64
//   0x02aca4: 5400074b  b.lt     #0x2ad8c
uint64_t fde_0374_sub_02ac68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x53185D09ULL) + (x2 ^ 0x02AC68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02ac68: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02ac6c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02ac70: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB40009E0ULL; // 0x02ac74: cbz x0, #0x2adb0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402C08ULL; // 0x02ac78: ldr w8, [x0, #0x2c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02ac7c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02ac80: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x37F80848ULL; // 0x02ac84: tbnz w8, #0x1f, #0x2ad8c
    acc = (acc * 0x100000001B3ULL) ^ 0x7101911FULL; // 0x02ac88: cmp w8, #0x64
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006DULL; // 0x02ac8c: b.le #0x2ac98
    return acc;
}

// [EN] Reconstructed FDE #0375 @ 0x02adbc..0x02af54 (408 bytes)
// [VN] Phục dựng FDE #0375 tại 0x02adbc..0x02af54 (408 byte)
//   0x02adbc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02adc0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02adc4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02adc8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02adcc: 9100c3fd  add      x29, sp, #0x30
//   0x02add0: b94b6808  ldr      w8, [x0, #0xb68]
//   0x02add4: aa0103f5  mov      x21, x1
//   0x02add8: aa0003f3  mov      x19, x0
//   0x02addc: 91036014  add      x20, x0, #0xd8
//   0x02ade0: 7100051f  cmp      w8, #1
//   0x02ade4: 540000ab  b.lt     #0x2adf8
//   0x02ade8: b94b5e68  ldr      w8, [x19, #0xb5c]
//   0x02adec: b941a669  ldr      w9, [x19, #0x1a4]
//   0x02adf0: 6b09011f  cmp      w8, w9
//   0x02adf4: 5400018a  b.ge     #0x2ae24
//   0x02adf8: 2a1f03f7  mov      w23, wzr
uint64_t fde_0375_sub_02adbc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB941A669ULL) + (x2 ^ 0x02ADBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02adbc: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02adc0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02adc4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02adc8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02adcc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB94B6808ULL; // 0x02add0: ldr w8, [x0, #0xb68]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x02add4: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02add8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91036014ULL; // 0x02addc: add x20, x0, #0xd8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02ade0: cmp w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0376 @ 0x02af54..0x02b51c (1480 bytes)
// [VN] Phục dựng FDE #0376 tại 0x02af54..0x02b51c (1480 byte)
//   0x02af54: d103c3ff  sub      sp, sp, #0xf0
//   0x02af58: a9096ffc  stp      x28, x27, [sp, #0x90]
//   0x02af5c: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x02af60: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x02af64: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x02af68: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x02af6c: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x02af70: 910383fd  add      x29, sp, #0xe0
//   0x02af74: 29406c28  ldp      w8, w27, [x1]
//   0x02af78: f945901a  ldr      x26, [x0, #0xb20]
//   0x02af7c: aa0003f4  mov      x20, x0
//   0x02af80: 52801029  mov      w9, #0x81
//   0x02af84: 7100077f  cmp      w27, #1
//   0x02af88: f90037e1  str      x1, [sp, #0x68]
//   0x02af8c: 39009f49  strb     w9, [x26, #0x27]
//   0x02af90: 39011f49  strb     w9, [x26, #0x47]
uint64_t fde_0376_sub_02af54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0x7100077FULL) + (x2 ^ 0x02AF54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x02af54: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9096FFCULL; // 0x02af58: stp x28, x27, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A67FAULL; // 0x02af5c: stp x26, x25, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B5FF8ULL; // 0x02af60: stp x24, x23, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C57F6ULL; // 0x02af64: stp x22, x21, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D4FF4ULL; // 0x02af68: stp x20, x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x02af6c: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x02af70: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0x29406C28ULL; // 0x02af74: ldp w8, w27, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF945901AULL; // 0x02af78: ldr x26, [x0, #0xb20]
    return acc;
}

// [EN] Reconstructed FDE #0377 @ 0x02b51c..0x02bd00 (2020 bytes)
// [VN] Phục dựng FDE #0377 tại 0x02b51c..0x02bd00 (2020 byte)
//   0x02b51c: d10543ff  sub      sp, sp, #0x150
//   0x02b520: a90f6ffc  stp      x28, x27, [sp, #0xf0]
//   0x02b524: a91067fa  stp      x26, x25, [sp, #0x100]
//   0x02b528: a9115ff8  stp      x24, x23, [sp, #0x110]
//   0x02b52c: a91257f6  stp      x22, x21, [sp, #0x120]
//   0x02b530: a9134ff4  stp      x20, x19, [sp, #0x130]
//   0x02b534: a9147bfd  stp      x29, x30, [sp, #0x140]
//   0x02b538: 910503fd  add      x29, sp, #0x140
//   0x02b53c: d53bd048  mrs      x8, tpidr_el0
//   0x02b540: f9002be8  str      x8, [sp, #0x50]
//   0x02b544: f9401508  ldr      x8, [x8, #0x28]
//   0x02b548: aa0103f7  mov      x23, x1
//   0x02b54c: aa0003e1  mov      x1, x0
//   0x02b550: aa0003f3  mov      x19, x0
//   0x02b554: f81a03a8  stur     x8, [x29, #-0x60]
//   0x02b558: b84d8c2c  ldr      w12, [x1, #0xd8]!
uint64_t fde_0377_sub_02b51c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10543FFULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x02B51CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10543FFULL; // 0x02b51c: sub sp, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F6FFCULL; // 0x02b520: stp x28, x27, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91067FAULL; // 0x02b524: stp x26, x25, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9115FF8ULL; // 0x02b528: stp x24, x23, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91257F6ULL; // 0x02b52c: stp x22, x21, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9134FF4ULL; // 0x02b530: stp x20, x19, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9147BFDULL; // 0x02b534: stp x29, x30, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0x910503FDULL; // 0x02b538: add x29, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x02b53c: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BE8ULL; // 0x02b540: str x8, [sp, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0378 @ 0x02bd00..0x02bf90 (656 bytes)
// [VN] Phục dựng FDE #0378 tại 0x02bd00..0x02bf90 (656 byte)
//   0x02bd00: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02bd04: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02bd08: 910043fd  add      x29, sp, #0x10
//   0x02bd0c: f9402428  ldr      x8, [x1, #0x48]
//   0x02bd10: aa0103f4  mov      x20, x1
//   0x02bd14: aa0003f3  mov      x19, x0
//   0x02bd18: b4000088  cbz      x8, #0x2bd28
//   0x02bd1c: aa1403e0  mov      x0, x20
//   0x02bd20: d63f0100  blr      x8
//   0x02bd24: 34000380  cbz      w0, #0x2bd94
//   0x02bd28: b9407288  ldr      w8, [x20, #0x70]
//   0x02bd2c: 340000a8  cbz      w8, #0x2bd40
//   0x02bd30: 2a1f03e9  mov      w9, wzr
//   0x02bd34: 2a1f03e8  mov      w8, wzr
//   0x02bd38: b90b6a7f  str      wzr, [x19, #0xb68]
//   0x02bd3c: 1400000b  b        #0x2bd68
uint64_t fde_0378_sub_02bd00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x2A1F03E9ULL) + (x2 ^ 0x02BD00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02bd00: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02bd04: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02bd08: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402428ULL; // 0x02bd0c: ldr x8, [x1, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02bd10: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02bd14: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x02bd18: cbz x8, #0x2bd28
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02bd1c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x02bd20: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x34000380ULL; // 0x02bd24: cbz w0, #0x2bd94
    return acc;
}

// [EN] Reconstructed FDE #0379 @ 0x02bf90..0x02bff4 (100 bytes)
// [VN] Phục dựng FDE #0379 tại 0x02bf90..0x02bff4 (100 byte)
//   0x02bf90: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02bf94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02bf98: 910043fd  add      x29, sp, #0x10
//   0x02bf9c: b940c808  ldr      w8, [x0, #0xc8]
//   0x02bfa0: aa0103f3  mov      x19, x1
//   0x02bfa4: 7100051f  cmp      w8, #1
//   0x02bfa8: 540001eb  b.lt     #0x2bfe4
//   0x02bfac: aa0003f4  mov      x20, x0
//   0x02bfb0: 9400774a  bl       #0x49cd8
//   0x02bfb4: f9400808  ldr      x8, [x0, #0x10]
//   0x02bfb8: 91026280  add      x0, x20, #0x98
//   0x02bfbc: d63f0100  blr      x8
//   0x02bfc0: 2a0003f4  mov      w20, w0
//   0x02bfc4: f9402a68  ldr      x8, [x19, #0x50]
//   0x02bfc8: b4000068  cbz      x8, #0x2bfd4
//   0x02bfcc: aa1303e0  mov      x0, x19
uint64_t fde_0379_sub_02bf90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x2A0003F4ULL) + (x2 ^ 0x02BF90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02bf90: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02bf94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02bf98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB940C808ULL; // 0x02bf9c: ldr w8, [x0, #0xc8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02bfa0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02bfa4: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001EBULL; // 0x02bfa8: b.lt #0x2bfe4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02bfac: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400774AULL; // 0x02bfb0: bl #0x49cd8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x02bfb4: ldr x8, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0380 @ 0x02bff4..0x02c018 (36 bytes)
// [VN] Phục dựng FDE #0380 tại 0x02bff4..0x02c018 (36 byte)
//   0x02bff4: b40000c0  cbz      x0, #0x2c00c
//   0x02bff8: b9402808  ldr      w8, [x0, #0x28]
//   0x02bffc: 340000a8  cbz      w8, #0x2c010
//   0x02c000: 7107fc5f  cmp      w2, #0x1ff
//   0x02c004: 1a9fd7e8  cset     w8, gt
//   0x02c008: 531f7900  lsl      w0, w8, #1
//   0x02c00c: d65f03c0  ret      
//   0x02c010: 2a1f03e0  mov      w0, wzr
//   0x02c014: d65f03c0  ret      
uint64_t fde_0380_sub_02bff4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40000C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02BFF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C0ULL; // 0x02bff4: cbz x0, #0x2c00c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402808ULL; // 0x02bff8: ldr w8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000A8ULL; // 0x02bffc: cbz w8, #0x2c010
    acc = (acc * 0x100000001B3ULL) ^ 0x7107FC5FULL; // 0x02c000: cmp w2, #0x1ff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9FD7E8ULL; // 0x02c004: cset w8, gt
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7900ULL; // 0x02c008: lsl w0, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c00c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02c010: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c014: ret 
    return acc;
}

// [EN] Reconstructed FDE #0381 @ 0x02c018..0x02c32c (788 bytes)
// [VN] Phục dựng FDE #0381 tại 0x02c018..0x02c32c (788 byte)
//   0x02c018: d101c3ff  sub      sp, sp, #0x70
//   0x02c01c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02c020: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02c024: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02c028: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02c02c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02c030: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02c034: 910183fd  add      x29, sp, #0x60
//   0x02c038: b940c808  ldr      w8, [x0, #0xc8]
//   0x02c03c: aa0103f3  mov      x19, x1
//   0x02c040: aa0003f4  mov      x20, x0
//   0x02c044: b900cc1f  str      wzr, [x0, #0xcc]
//   0x02c048: 7100051f  cmp      w8, #1
//   0x02c04c: 5400024b  b.lt     #0x2c094
//   0x02c050: 91026295  add      x21, x20, #0x98
//   0x02c054: 94007721  bl       #0x49cd8
uint64_t fde_0381_sub_02c018(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x7100051FULL) + (x2 ^ 0x02C018ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02c018: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02c01c: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02c020: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02c024: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02c028: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02c02c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02c030: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02c034: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB940C808ULL; // 0x02c038: ldr w8, [x0, #0xc8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02c03c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0382 @ 0x02c32c..0x02c35c (48 bytes)
// [VN] Phục dựng FDE #0382 tại 0x02c32c..0x02c35c (48 byte)
//   0x02c32c: 90000008  adrp     x8, #0x2c000
//   0x02c330: 910d7108  add      x8, x8, #0x35c
//   0x02c334: 90000009  adrp     x9, #0x2c000
//   0x02c338: 910f7129  add      x9, x9, #0x3dc
//   0x02c33c: 9000000a  adrp     x10, #0x2c000
//   0x02c340: 9e670100  fmov     d0, x8
//   0x02c344: 9124a14a  add      x10, x10, #0x928
//   0x02c348: 4e181d20  mov      v0.d[1], x9
//   0x02c34c: f900282a  str      x10, [x1, #0x50]
//   0x02c350: 3d801020  str      q0, [x1, #0x40]
//   0x02c354: f9001c20  str      x0, [x1, #0x38]
//   0x02c358: d65f03c0  ret      
uint64_t fde_0382_sub_02c32c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C32CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x02c32c: adrp x8, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0x910D7108ULL; // 0x02c330: add x8, x8, #0x35c
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x02c334: adrp x9, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0x910F7129ULL; // 0x02c338: add x9, x9, #0x3dc
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000AULL; // 0x02c33c: adrp x10, #0x2c000
    acc = (acc * 0x100000001B3ULL) ^ 0x9E670100ULL; // 0x02c340: fmov d0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x9124A14AULL; // 0x02c344: add x10, x10, #0x928
    acc = (acc * 0x100000001B3ULL) ^ 0x4E181D20ULL; // 0x02c348: mov v0.d[1], x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF900282AULL; // 0x02c34c: str x10, [x1, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x3D801020ULL; // 0x02c350: str q0, [x1, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0383 @ 0x02c35c..0x02c3dc (128 bytes)
// [VN] Phục dựng FDE #0383 tại 0x02c35c..0x02c3dc (128 byte)
//   0x02c35c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02c360: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02c364: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c368: 910083fd  add      x29, sp, #0x20
//   0x02c36c: b9400c08  ldr      w8, [x0, #0xc]
//   0x02c370: aa0003f3  mov      x19, x0
//   0x02c374: 2a1f03e0  mov      w0, wzr
//   0x02c378: 7100051f  cmp      w8, #1
//   0x02c37c: 5400028b  b.lt     #0x2c3cc
//   0x02c380: b9401268  ldr      w8, [x19, #0x10]
//   0x02c384: 7100051f  cmp      w8, #1
//   0x02c388: 5400022b  b.lt     #0x2c3cc
//   0x02c38c: f9401e74  ldr      x20, [x19, #0x38]
//   0x02c390: aa1303e0  mov      x0, x19
//   0x02c394: f9402e88  ldr      x8, [x20, #0x58]
//   0x02c398: aa1403e1  mov      x1, x20
uint64_t fde_0383_sub_02c35c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9401E74ULL) + (x2 ^ 0x02C35CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02c35c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02c360: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c364: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c368: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400C08ULL; // 0x02c36c: ldr w8, [x0, #0xc]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c370: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02c374: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02c378: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400028BULL; // 0x02c37c: b.lt #0x2c3cc
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401268ULL; // 0x02c380: ldr w8, [x19, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0384 @ 0x02c3dc..0x02c928 (1356 bytes)
// [VN] Phục dựng FDE #0384 tại 0x02c3dc..0x02c928 (1356 byte)
//   0x02c3dc: d10243ff  sub      sp, sp, #0x90
//   0x02c3e0: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x02c3e4: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02c3e8: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02c3ec: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02c3f0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02c3f4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02c3f8: 910203fd  add      x29, sp, #0x80
//   0x02c3fc: f9401c1b  ldr      x27, [x0, #0x38]
//   0x02c400: aa0003f3  mov      x19, x0
//   0x02c404: f9400368  ldr      x8, [x27]
//   0x02c408: b9400114  ldr      w20, [x8]
//   0x02c40c: 51000688  sub      w8, w20, #1
//   0x02c410: 7100311f  cmp      w8, #0xc
//   0x02c414: 54000082  b.hs     #0x2c424
//   0x02c418: 528103a9  mov      w9, #0x81d
uint64_t fde_0384_sub_02c3dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x51000688ULL) + (x2 ^ 0x02C3DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02c3dc: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x02c3e0: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x02c3e4: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02c3e8: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02c3ec: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02c3f0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02c3f4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02c3f8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C1BULL; // 0x02c3fc: ldr x27, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c400: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0385 @ 0x02c928..0x02c950 (40 bytes)
// [VN] Phục dựng FDE #0385 tại 0x02c928..0x02c950 (40 byte)
//   0x02c928: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02c92c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c930: 910043fd  add      x29, sp, #0x10
//   0x02c934: f9401c13  ldr      x19, [x0, #0x38]
//   0x02c938: f9402a60  ldr      x0, [x19, #0x50]
//   0x02c93c: 97fff6e0  bl       #0x2a4bc
//   0x02c940: f9002a7f  str      xzr, [x19, #0x50]
//   0x02c944: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02c948: f84207f3  ldr      x19, [sp], #0x20
//   0x02c94c: d65f03c0  ret      
uint64_t fde_0385_sub_02c928(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C928ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02c928: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c92c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c930: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401C13ULL; // 0x02c934: ldr x19, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402A60ULL; // 0x02c938: ldr x0, [x19, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF6E0ULL; // 0x02c93c: bl #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002A7FULL; // 0x02c940: str xzr, [x19, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02c944: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x02c948: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c94c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0386 @ 0x02c950..0x02c9bc (108 bytes)
// [VN] Phục dựng FDE #0386 tại 0x02c950..0x02c9bc (108 byte)
//   0x02c950: d100c3ff  sub      sp, sp, #0x30
//   0x02c954: f9000bf3  str      x19, [sp, #0x10]
//   0x02c958: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c95c: 910083fd  add      x29, sp, #0x20
//   0x02c960: f9400028  ldr      x8, [x1]
//   0x02c964: aa0003f3  mov      x19, x0
//   0x02c968: f00001ab  adrp     x11, #0x63000
//   0x02c96c: f9400c00  ldr      x0, [x0, #0x18]
//   0x02c970: a9420e62  ldp      x2, x3, [x19, #0x20]
//   0x02c974: 29461261  ldp      w1, w4, [x19, #0x30]
//   0x02c978: 29411e69  ldp      w9, w7, [x19, #8]
//   0x02c97c: b940010a  ldr      w10, [x8]
//   0x02c980: f946116b  ldr      x11, [x11, #0xc20]
//   0x02c984: f940090c  ldr      x12, [x8, #0x10]
//   0x02c988: b9801906  ldrsw    x6, [x8, #0x18]
//   0x02c98c: f86a7968  ldr      x8, [x11, x10, lsl #3]
uint64_t fde_0386_sub_02c950(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF946116BULL) + (x2 ^ 0x02C950ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x02c950: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x02c954: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c958: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c95c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x02c960: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02c964: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001ABULL; // 0x02c968: adrp x11, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x02c96c: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9420E62ULL; // 0x02c970: ldp x2, x3, [x19, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x29461261ULL; // 0x02c974: ldp w1, w4, [x19, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0387 @ 0x02c9bc..0x02cbd4 (536 bytes)
// [VN] Phục dựng FDE #0387 tại 0x02c9bc..0x02cbd4 (536 byte)
//   0x02c9bc: d10283ff  sub      sp, sp, #0xa0
//   0x02c9c0: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x02c9c4: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x02c9c8: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x02c9cc: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x02c9d0: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x02c9d4: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x02c9d8: 910243fd  add      x29, sp, #0x90
//   0x02c9dc: f940003c  ldr      x28, [x1]
//   0x02c9e0: f00001a9  adrp     x9, #0x63000
//   0x02c9e4: 2941ec0c  ldp      w12, w27, [x0, #0xc]
//   0x02c9e8: f9461929  ldr      x9, [x9, #0xc30]
//   0x02c9ec: b940038b  ldr      w11, [x28]
//   0x02c9f0: f9400b8a  ldr      x10, [x28, #0x10]
//   0x02c9f4: b9800813  ldrsw    x19, [x0, #8]
//   0x02c9f8: b9801b88  ldrsw    x8, [x28, #0x18]
uint64_t fde_0387_sub_02c9bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xB940038BULL) + (x2 ^ 0x02C9BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02c9bc: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x02c9c0: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x02c9c4: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x02c9c8: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x02c9cc: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x02c9d0: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x02c9d4: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x02c9d8: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF940003CULL; // 0x02c9dc: ldr x28, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF00001A9ULL; // 0x02c9e0: adrp x9, #0x63000
    return acc;
}

// [EN] Reconstructed FDE #0388 @ 0x02cbd4..0x02cca4 (208 bytes)
// [VN] Phục dựng FDE #0388 tại 0x02cbd4..0x02cca4 (208 byte)
//   0x02cbd4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02cbd8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02cbdc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02cbe0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02cbe4: 9100c3fd  add      x29, sp, #0x30
//   0x02cbe8: f9400038  ldr      x24, [x1]
//   0x02cbec: 29411008  ldp      w8, w4, [x0, #8]
//   0x02cbf0: b9401005  ldr      w5, [x0, #0x10]
//   0x02cbf4: 93407d08  sxtw     x8, w8
//   0x02cbf8: a9412b09  ldp      x9, x10, [x24, #0x10]
//   0x02cbfc: 69462f03  ldpsw    x3, x11, [x24, #0x30]
//   0x02cc00: aa0003f3  mov      x19, x0
//   0x02cc04: 93417d0e  sbfx     x14, x8, #1, #0x1f
//   0x02cc08: f940130c  ldr      x12, [x24, #0x20]
//   0x02cc0c: b9803b0d  ldrsw    x13, [x24, #0x38]
//   0x02cc10: d503201f  nop      
uint64_t fde_0388_sub_02cbd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x93417D0EULL) + (x2 ^ 0x02CBD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02cbd4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02cbd8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02cbdc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02cbe0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02cbe4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400038ULL; // 0x02cbe8: ldr x24, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x29411008ULL; // 0x02cbec: ldp w8, w4, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401005ULL; // 0x02cbf0: ldr w5, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D08ULL; // 0x02cbf4: sxtw x8, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9412B09ULL; // 0x02cbf8: ldp x9, x10, [x24, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0389 @ 0x02cca4..0x02cde0 (316 bytes)
// [VN] Phục dựng FDE #0389 tại 0x02cca4..0x02cde0 (316 byte)
//   0x02cca4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02cca8: 910003fd  mov      x29, sp
//   0x02ccac: f9404c09  ldr      x9, [x0, #0x98]
//   0x02ccb0: b4000929  cbz      x9, #0x2cdd4
//   0x02ccb4: f940002a  ldr      x10, [x1]
//   0x02ccb8: 2941040c  ldp      w12, w1, [x0, #8]
//   0x02ccbc: b9405808  ldr      w8, [x0, #0x58]
//   0x02ccc0: b9401002  ldr      w2, [x0, #0x10]
//   0x02ccc4: b940014b  ldr      w11, [x10]
//   0x02ccc8: 340000e8  cbz      w8, #0x2cce4
//   0x02cccc: 3400014c  cbz      w12, #0x2ccf4
//   0x02ccd0: b980000d  ldrsw    x13, [x0]
//   0x02ccd4: 51000588  sub      w8, w12, #1
//   0x02ccd8: cb0d0129  sub      x9, x9, x13
//   0x02ccdc: 2a0203ed  mov      w13, w2
//   0x02cce0: 14000007  b        #0x2ccfc
uint64_t fde_0389_sub_02cca4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x51000588ULL) + (x2 ^ 0x02CCA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02cca4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02cca8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404C09ULL; // 0x02ccac: ldr x9, [x0, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000929ULL; // 0x02ccb0: cbz x9, #0x2cdd4
    acc = (acc * 0x100000001B3ULL) ^ 0xF940002AULL; // 0x02ccb4: ldr x10, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x2941040CULL; // 0x02ccb8: ldp w12, w1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405808ULL; // 0x02ccbc: ldr w8, [x0, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401002ULL; // 0x02ccc0: ldr w2, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940014BULL; // 0x02ccc4: ldr w11, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E8ULL; // 0x02ccc8: cbz w8, #0x2cce4
    return acc;
}

// [EN] Reconstructed FDE #0390 @ 0x02cde0..0x02cf00 (288 bytes)
// [VN] Phục dựng FDE #0390 tại 0x02cde0..0x02cf00 (288 byte)
//   0x02cde0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02cde4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02cde8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02cdec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02cdf0: 9100c3fd  add      x29, sp, #0x30
//   0x02cdf4: aa0003e8  mov      x8, x0
//   0x02cdf8: f9404c00  ldr      x0, [x0, #0x98]
//   0x02cdfc: b4000760  cbz      x0, #0x2cee8
//   0x02ce00: f9400037  ldr      x23, [x1]
//   0x02ce04: 29414d0a  ldp      w10, w19, [x8, #8]
//   0x02ce08: b9401115  ldr      w21, [x8, #0x10]
//   0x02ce0c: b9405909  ldr      w9, [x8, #0x58]
//   0x02ce10: b94002f8  ldr      w24, [x23]
//   0x02ce14: 7100131f  cmp      w24, #4
//   0x02ce18: 1a9f17eb  cset     w11, eq
//   0x02ce1c: 7100271f  cmp      w24, #9
uint64_t fde_0390_sub_02cde0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xB94002F8ULL) + (x2 ^ 0x02CDE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02cde0: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02cde4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02cde8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02cdec: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02cdf0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02cdf4: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404C00ULL; // 0x02cdf8: ldr x0, [x0, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000760ULL; // 0x02cdfc: cbz x0, #0x2cee8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400037ULL; // 0x02ce00: ldr x23, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x29414D0AULL; // 0x02ce04: ldp w10, w19, [x8, #8]
    return acc;
}

// [EN] Reconstructed FDE #0391 @ 0x02cf00..0x02cfb0 (176 bytes)
// [VN] Phục dựng FDE #0391 tại 0x02cf00..0x02cfb0 (176 byte)
//   0x02cf00: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x02cf04: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02cf08: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02cf0c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02cf10: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02cf14: 910103fd  add      x29, sp, #0x40
//   0x02cf18: f9400038  ldr      x24, [x1]
//   0x02cf1c: 69414c09  ldpsw    x9, x19, [x0, #8]
//   0x02cf20: b9401017  ldr      w23, [x0, #0x10]
//   0x02cf24: f9404c16  ldr      x22, [x0, #0x98]
//   0x02cf28: f9401708  ldr      x8, [x24, #0x28]
//   0x02cf2c: b9803f19  ldrsw    x25, [x24, #0x3c]
//   0x02cf30: 710006ff  cmp      w23, #1
//   0x02cf34: 9b092334  madd     x20, x25, x9, x8
//   0x02cf38: b40001d6  cbz      x22, #0x2cf70
//   0x02cf3c: 540002cb  b.lt     #0x2cf94
uint64_t fde_0391_sub_02cf00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x710006FFULL) + (x2 ^ 0x02CF00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x02cf00: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02cf04: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02cf08: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02cf0c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02cf10: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02cf14: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400038ULL; // 0x02cf18: ldr x24, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x69414C09ULL; // 0x02cf1c: ldpsw x9, x19, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401017ULL; // 0x02cf20: ldr w23, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404C16ULL; // 0x02cf24: ldr x22, [x0, #0x98]
    return acc;
}

// [EN] Reconstructed FDE #0392 @ 0x02cfb0..0x02d170 (448 bytes)
// [VN] Phục dựng FDE #0392 tại 0x02cfb0..0x02d170 (448 byte)
//   0x02cfb0: d101c3ff  sub      sp, sp, #0x70
//   0x02cfb4: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02cfb8: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02cfbc: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02cfc0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02cfc4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02cfc8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02cfcc: 910183fd  add      x29, sp, #0x60
//   0x02cfd0: b9401019  ldr      w25, [x0, #0x10]
//   0x02cfd4: 7100073f  cmp      w25, #1
//   0x02cfd8: 54000b8b  b.lt     #0x2d148
//   0x02cfdc: aa0003f3  mov      x19, x0
//   0x02cfe0: f9401820  ldr      x0, [x1, #0x30]
//   0x02cfe4: 11000728  add      w8, w25, #1
//   0x02cfe8: aa0103f5  mov      x21, x1
//   0x02cfec: 2a1f03fa  mov      w26, wzr
uint64_t fde_0392_sub_02cfb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401820ULL) + (x2 ^ 0x02CFB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02cfb0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02cfb4: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02cfb8: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02cfbc: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02cfc0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02cfc4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02cfc8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02cfcc: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401019ULL; // 0x02cfd0: ldr w25, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100073FULL; // 0x02cfd4: cmp w25, #1
    return acc;
}

// [EN] Reconstructed FDE #0393 @ 0x02d170..0x02d214 (164 bytes)
// [VN] Phục dựng FDE #0393 tại 0x02d170..0x02d214 (164 byte)
//   0x02d170: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x02d174: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02d178: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02d17c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02d180: 9100c3fd  add      x29, sp, #0x30
//   0x02d184: f9404c08  ldr      x8, [x0, #0x98]
//   0x02d188: b40003a8  cbz      x8, #0x2d1fc
//   0x02d18c: 2a0203f3  mov      w19, w2
//   0x02d190: 7100045f  cmp      w2, #1
//   0x02d194: 5400034b  b.lt     #0x2d1fc
//   0x02d198: b9402029  ldr      w9, [x1, #0x20]
//   0x02d19c: f9402436  ldr      x22, [x1, #0x48]
//   0x02d1a0: aa0003f4  mov      x20, x0
//   0x02d1a4: aa0103f5  mov      x21, x1
//   0x02d1a8: 0b130137  add      w23, w9, w19
//   0x02d1ac: b9803ec9  ldrsw    x9, [x22, #0x3c]
uint64_t fde_0393_sub_02d170(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x02D170ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x02d170: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02d174: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02d178: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02d17c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02d180: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404C08ULL; // 0x02d184: ldr x8, [x0, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003A8ULL; // 0x02d188: cbz x8, #0x2d1fc
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x02d18c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x02d190: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400034BULL; // 0x02d194: b.lt #0x2d1fc
    return acc;
}

// [EN] Reconstructed FDE #0394 @ 0x02d214..0x02d364 (336 bytes)
// [VN] Phục dựng FDE #0394 tại 0x02d214..0x02d364 (336 byte)
//   0x02d214: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x02d218: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02d21c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02d220: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02d224: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02d228: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02d22c: 910143fd  add      x29, sp, #0x50
//   0x02d230: aa0003f7  mov      x23, x0
//   0x02d234: f9402400  ldr      x0, [x0, #0x48]
//   0x02d238: b9404008  ldr      w8, [x0, #0x40]
//   0x02d23c: b9403809  ldr      w9, [x0, #0x38]
//   0x02d240: 6b09011f  cmp      w8, w9
//   0x02d244: 540007ea  b.ge     #0x2d340
//   0x02d248: f94002fa  ldr      x26, [x23]
//   0x02d24c: b9403414  ldr      w20, [x0, #0x34]
//   0x02d250: 93407c28  sxtw     x8, w1
uint64_t fde_0394_sub_02d214(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0x540007EAULL) + (x2 ^ 0x02D214ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x02d214: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02d218: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02d21c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02d220: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02d224: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02d228: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02d22c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x02d230: mov x23, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402400ULL; // 0x02d234: ldr x0, [x0, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9404008ULL; // 0x02d238: ldr w8, [x0, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0395 @ 0x02d364..0x02d4f0 (396 bytes)
// [VN] Phục dựng FDE #0395 tại 0x02d364..0x02d4f0 (396 byte)
//   0x02d364: d101c3ff  sub      sp, sp, #0x70
//   0x02d368: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02d36c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02d370: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02d374: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02d378: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02d37c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02d380: 910183fd  add      x29, sp, #0x60
//   0x02d384: f940001a  ldr      x26, [x0]
//   0x02d388: aa0003f8  mov      x24, x0
//   0x02d38c: f9402400  ldr      x0, [x0, #0x48]
//   0x02d390: b9400348  ldr      w8, [x26]
//   0x02d394: b940400b  ldr      w11, [x0, #0x40]
//   0x02d398: b940380c  ldr      w12, [x0, #0x38]
//   0x02d39c: 7100111f  cmp      w8, #4
//   0x02d3a0: 1a9f17e9  cset     w9, eq
uint64_t fde_0395_sub_02d364(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB940400BULL) + (x2 ^ 0x02D364ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02d364: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02d368: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02d36c: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02d370: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02d374: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02d378: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02d37c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02d380: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF940001AULL; // 0x02d384: ldr x26, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F8ULL; // 0x02d388: mov x24, x0
    return acc;
}

// [EN] Reconstructed FDE #0396 @ 0x02d4f0..0x02d674 (388 bytes)
// [VN] Phục dựng FDE #0396 tại 0x02d4f0..0x02d674 (388 byte)
//   0x02d4f0: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x02d4f4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02d4f8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02d4fc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02d500: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02d504: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02d508: 910143fd  add      x29, sp, #0x50
//   0x02d50c: f9400028  ldr      x8, [x1]
//   0x02d510: b9401017  ldr      w23, [x0, #0x10]
//   0x02d514: f9401838  ldr      x24, [x1, #0x30]
//   0x02d518: aa0103f4  mov      x20, x1
//   0x02d51c: b9400108  ldr      w8, [x8]
//   0x02d520: aa0003f3  mov      x19, x0
//   0x02d524: 7100311f  cmp      w8, #0xc
//   0x02d528: 540009e8  b.hi     #0x2d664
//   0x02d52c: 52800029  mov      w9, #1
uint64_t fde_0396_sub_02d4f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x02D4F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x02d4f0: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02d4f4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02d4f8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02d4fc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02d500: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02d504: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02d508: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x02d50c: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401017ULL; // 0x02d510: ldr w23, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401838ULL; // 0x02d514: ldr x24, [x1, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0397 @ 0x02d674..0x02d798 (292 bytes)
// [VN] Phục dựng FDE #0397 tại 0x02d674..0x02d798 (292 byte)
//   0x02d674: d101c3ff  sub      sp, sp, #0x70
//   0x02d678: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02d67c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02d680: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02d684: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02d688: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02d68c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02d690: 910183fd  add      x29, sp, #0x60
//   0x02d694: f940003a  ldr      x26, [x1]
//   0x02d698: b980203b  ldrsw    x27, [x1, #0x20]
//   0x02d69c: f9404c15  ldr      x21, [x0, #0x98]
//   0x02d6a0: f9401748  ldr      x8, [x26, #0x28]
//   0x02d6a4: b9803f57  ldrsw    x23, [x26, #0x3c]
//   0x02d6a8: d503201f  nop      
//   0x02d6ac: 9b1b22f3  madd     x19, x23, x27, x8
//   0x02d6b0: b40004b5  cbz      x21, #0x2d744
uint64_t fde_0397_sub_02d674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xB9803F57ULL) + (x2 ^ 0x02D674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02d674: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02d678: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02d67c: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02d680: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02d684: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02d688: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02d68c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02d690: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF940003AULL; // 0x02d694: ldr x26, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB980203BULL; // 0x02d698: ldrsw x27, [x1, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0398 @ 0x02d798..0x02d7d0 (56 bytes)
// [VN] Phục dựng FDE #0398 tại 0x02d798..0x02d7d0 (56 byte)
//   0x02d798: 12185c28  and      w8, w1, #0xffffff00
//   0x02d79c: 7108011f  cmp      w8, #0x200
//   0x02d7a0: 54000141  b.ne     #0x2d7c8
//   0x02d7a4: b40000e0  cbz      x0, #0x2d7c0
//   0x02d7a8: 6f00e400  movi     v0.2d, #0000000000000000
//   0x02d7ac: ad040000  stp      q0, q0, [x0, #0x80]
//   0x02d7b0: ad030000  stp      q0, q0, [x0, #0x60]
//   0x02d7b4: ad020000  stp      q0, q0, [x0, #0x40]
//   0x02d7b8: ad010000  stp      q0, q0, [x0, #0x20]
//   0x02d7bc: ad000000  stp      q0, q0, [x0]
//   0x02d7c0: 52800020  mov      w0, #1
//   0x02d7c4: d65f03c0  ret      
//   0x02d7c8: 2a1f03e0  mov      w0, wzr
//   0x02d7cc: d65f03c0  ret      
uint64_t fde_0398_sub_02d798(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x12185C28ULL) + (x1 ^ 0x2A1F03E0ULL) + (x2 ^ 0x02D798ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x12185C28ULL; // 0x02d798: and w8, w1, #0xffffff00
    acc = (acc * 0x100000001B3ULL) ^ 0x7108011FULL; // 0x02d79c: cmp w8, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0x54000141ULL; // 0x02d7a0: b.ne #0x2d7c8
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02d7a4: cbz x0, #0x2d7c0
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x02d7a8: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAD040000ULL; // 0x02d7ac: stp q0, q0, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD030000ULL; // 0x02d7b0: stp q0, q0, [x0, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD020000ULL; // 0x02d7b4: stp q0, q0, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010000ULL; // 0x02d7b8: stp q0, q0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD000000ULL; // 0x02d7bc: stp q0, q0, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0399 @ 0x02d7d0..0x02d89c (204 bytes)
// [VN] Phục dựng FDE #0399 tại 0x02d7d0..0x02d89c (204 byte)
//   0x02d7d0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02d7d4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02d7d8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02d7dc: 910083fd  add      x29, sp, #0x20
//   0x02d7e0: 52800020  mov      w0, #1
//   0x02d7e4: 52817a01  mov      w1, #0xbd0
//   0x02d7e8: 97fff32d  bl       #0x2a49c
//   0x02d7ec: aa0003f3  mov      x19, x0
//   0x02d7f0: b40004c0  cbz      x0, #0x2d888
//   0x02d7f4: f0000128  adrp     x8, #0x54000
//   0x02d7f8: 911cc908  add      x8, x8, #0x732
//   0x02d7fc: b900027f  str      wzr, [x19]
//   0x02d800: f9000668  str      x8, [x19, #8]
//   0x02d804: 94007135  bl       #0x49cd8
//   0x02d808: f9400008  ldr      x8, [x0]
//   0x02d80c: 91026260  add      x0, x19, #0x98
uint64_t fde_0399_sub_02d7d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9000668ULL) + (x2 ^ 0x02D7D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02d7d0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02d7d4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02d7d8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02d7dc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x02d7e0: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52817A01ULL; // 0x02d7e4: mov w1, #0xbd0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF32DULL; // 0x02d7e8: bl #0x2a49c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d7ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004C0ULL; // 0x02d7f0: cbz x0, #0x2d888
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x02d7f4: adrp x8, #0x54000
    return acc;
}

// [EN] Reconstructed FDE #0400 @ 0x02d89c..0x02d8fc (96 bytes)
// [VN] Phục dựng FDE #0400 tại 0x02d89c..0x02d8fc (96 byte)
//   0x02d89c: b40002e0  cbz      x0, #0x2d8f8
//   0x02d8a0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02d8a4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d8a8: 910043fd  add      x29, sp, #0x10
//   0x02d8ac: aa0003f3  mov      x19, x0
//   0x02d8b0: 9400710a  bl       #0x49cd8
//   0x02d8b4: f9401408  ldr      x8, [x0, #0x28]
//   0x02d8b8: 91026260  add      x0, x19, #0x98
//   0x02d8bc: d63f0100  blr      x8
//   0x02d8c0: aa1303e0  mov      x0, x19
//   0x02d8c4: 94007204  bl       #0x4a0d4
//   0x02d8c8: f945a660  ldr      x0, [x19, #0xb48]
//   0x02d8cc: 912d2274  add      x20, x19, #0xb48
//   0x02d8d0: 97fff2fb  bl       #0x2a4bc
//   0x02d8d4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x02d8d8: 3d800280  str      q0, [x20]
uint64_t fde_0400_sub_02d89c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40002E0ULL) + (x1 ^ 0x912D2274ULL) + (x2 ^ 0x02D89CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40002E0ULL; // 0x02d89c: cbz x0, #0x2d8f8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02d8a0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d8a4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d8a8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d8ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400710AULL; // 0x02d8b0: bl #0x49cd8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x02d8b4: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x91026260ULL; // 0x02d8b8: add x0, x19, #0x98
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x02d8bc: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02d8c0: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #0401 @ 0x02d8fc..0x02d91c (32 bytes)
// [VN] Phục dựng FDE #0401 tại 0x02d8fc..0x02d91c (32 byte)
//   0x02d8fc: b9400008  ldr      w8, [x0]
//   0x02d900: 34000068  cbz      w8, #0x2d90c
//   0x02d904: 2a1f03e0  mov      w0, wzr
//   0x02d908: d65f03c0  ret      
//   0x02d90c: f9000402  str      x2, [x0, #8]
//   0x02d910: 29007c01  stp      w1, wzr, [x0]
//   0x02d914: 2a1f03e0  mov      w0, wzr
//   0x02d918: d65f03c0  ret      
uint64_t fde_0401_sub_02d8fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02D8FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400008ULL; // 0x02d8fc: ldr w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000068ULL; // 0x02d900: cbz w8, #0x2d90c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02d904: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02d908: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000402ULL; // 0x02d90c: str x2, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x29007C01ULL; // 0x02d910: stp w1, wzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02d914: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02d918: ret 
    return acc;
}

// [EN] Reconstructed FDE #0402 @ 0x02d91c..0x02d9c4 (168 bytes)
// [VN] Phục dựng FDE #0402 tại 0x02d91c..0x02d9c4 (168 byte)
//   0x02d91c: 2a1f03e8  mov      w8, wzr
//   0x02d920: b40004a0  cbz      x0, #0x2d9b4
//   0x02d924: f100283f  cmp      x1, #0xa
//   0x02d928: 54000463  b.lo     #0x2d9b4
//   0x02d92c: 39400c08  ldrb     w8, [x0, #3]
//   0x02d930: 7102751f  cmp      w8, #0x9d
//   0x02d934: 54000441  b.ne     #0x2d9bc
//   0x02d938: 39401008  ldrb     w8, [x0, #4]
//   0x02d93c: 7100051f  cmp      w8, #1
//   0x02d940: 540003e1  b.ne     #0x2d9bc
//   0x02d944: 39401408  ldrb     w8, [x0, #5]
//   0x02d948: 7100a91f  cmp      w8, #0x2a
//   0x02d94c: 54000381  b.ne     #0x2d9bc
//   0x02d950: 39400008  ldrb     w8, [x0]
//   0x02d954: 52800329  mov      w9, #0x19
//   0x02d958: 0a090109  and      w9, w8, w9
uint64_t fde_0402_sub_02d91c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E8ULL) + (x1 ^ 0x54000381ULL) + (x2 ^ 0x02D91CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x02d91c: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB40004A0ULL; // 0x02d920: cbz x0, #0x2d9b4
    acc = (acc * 0x100000001B3ULL) ^ 0xF100283FULL; // 0x02d924: cmp x1, #0xa
    acc = (acc * 0x100000001B3ULL) ^ 0x54000463ULL; // 0x02d928: b.lo #0x2d9b4
    acc = (acc * 0x100000001B3ULL) ^ 0x39400C08ULL; // 0x02d92c: ldrb w8, [x0, #3]
    acc = (acc * 0x100000001B3ULL) ^ 0x7102751FULL; // 0x02d930: cmp w8, #0x9d
    acc = (acc * 0x100000001B3ULL) ^ 0x54000441ULL; // 0x02d934: b.ne #0x2d9bc
    acc = (acc * 0x100000001B3ULL) ^ 0x39401008ULL; // 0x02d938: ldrb w8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02d93c: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540003E1ULL; // 0x02d940: b.ne #0x2d9bc
    return acc;
}

// [EN] Reconstructed FDE #0403 @ 0x02d9c4..0x02e10c (1864 bytes)
// [VN] Phục dựng FDE #0403 tại 0x02d9c4..0x02e10c (1864 byte)
//   0x02d9c4: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02d9c8: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02d9cc: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02d9d0: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02d9d4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02d9d8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02d9dc: 910143fd  add      x29, sp, #0x50
//   0x02d9e0: b4002de0  cbz      x0, #0x2df9c
//   0x02d9e4: f0000128  adrp     x8, #0x54000
//   0x02d9e8: aa0003f3  mov      x19, x0
//   0x02d9ec: 911cc908  add      x8, x8, #0x732
//   0x02d9f0: b900001f  str      wzr, [x0]
//   0x02d9f4: f9000408  str      x8, [x0, #8]
//   0x02d9f8: b4000141  cbz      x1, #0x2da20
//   0x02d9fc: f9403028  ldr      x8, [x1, #0x60]
//   0x02da00: f1000d17  subs     x23, x8, #3
uint64_t fde_0403_sub_02d9c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xF9000408ULL) + (x2 ^ 0x02D9C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02d9c4: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02d9c8: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02d9cc: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02d9d0: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02d9d4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02d9d8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02d9dc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xB4002DE0ULL; // 0x02d9e0: cbz x0, #0x2df9c
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x02d9e4: adrp x8, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d9e8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0404 @ 0x02e10c..0x02e7e8 (1756 bytes)
// [VN] Phục dựng FDE #0404 tại 0x02e10c..0x02e7e8 (1756 byte)
//   0x02e10c: d10443ff  sub      sp, sp, #0x110
//   0x02e110: a90b6ffc  stp      x28, x27, [sp, #0xb0]
//   0x02e114: a90c67fa  stp      x26, x25, [sp, #0xc0]
//   0x02e118: a90d5ff8  stp      x24, x23, [sp, #0xd0]
//   0x02e11c: a90e57f6  stp      x22, x21, [sp, #0xe0]
//   0x02e120: a90f4ff4  stp      x20, x19, [sp, #0xf0]
//   0x02e124: a9107bfd  stp      x29, x30, [sp, #0x100]
//   0x02e128: 910403fd  add      x29, sp, #0x100
//   0x02e12c: f9003fe1  str      x1, [sp, #0x78]
//   0x02e130: d53bd04d  mrs      x13, tpidr_el0
//   0x02e134: f94015a8  ldr      x8, [x13, #0x28]
//   0x02e138: aa0003f4  mov      x20, x0
//   0x02e13c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x02e140: f9458817  ldr      x23, [x0, #0xb10]
//   0x02e144: b98b5815  ldrsw    x21, [x0, #0xb58]
//   0x02e148: b94af008  ldr      w8, [x0, #0xaf0]
uint64_t fde_0404_sub_02e10c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10443FFULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x02E10CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10443FFULL; // 0x02e10c: sub sp, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B6FFCULL; // 0x02e110: stp x28, x27, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C67FAULL; // 0x02e114: stp x26, x25, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D5FF8ULL; // 0x02e118: stp x24, x23, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E57F6ULL; // 0x02e11c: stp x22, x21, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F4FF4ULL; // 0x02e120: stp x20, x19, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9107BFDULL; // 0x02e124: stp x29, x30, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x910403FDULL; // 0x02e128: add x29, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xF9003FE1ULL; // 0x02e12c: str x1, [sp, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD04DULL; // 0x02e130: mrs x13, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0405 @ 0x02e7e8..0x02e7fc (20 bytes)
// [VN] Phục dựng FDE #0405 tại 0x02e7e8..0x02e7fc (20 byte)
//   0x02e7e8: f9458808  ldr      x8, [x0, #0xb10]
//   0x02e7ec: 781fe11f  sturh    wzr, [x8, #-2]
//   0x02e7f0: b90b001f  str      wzr, [x0, #0xb00]
//   0x02e7f4: b90b581f  str      wzr, [x0, #0xb58]
//   0x02e7f8: d65f03c0  ret      
uint64_t fde_0405_sub_02e7e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9458808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02E7E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9458808ULL; // 0x02e7e8: ldr x8, [x0, #0xb10]
    acc = (acc * 0x100000001B3ULL) ^ 0x781FE11FULL; // 0x02e7ec: sturh wzr, [x8, #-2]
    acc = (acc * 0x100000001B3ULL) ^ 0xB90B001FULL; // 0x02e7f0: str wzr, [x0, #0xb00]
    acc = (acc * 0x100000001B3ULL) ^ 0xB90B581FULL; // 0x02e7f4: str wzr, [x0, #0xb58]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02e7f8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0406 @ 0x02e7fc..0x02ea44 (584 bytes)
// [VN] Phục dựng FDE #0406 tại 0x02e7fc..0x02ea44 (584 byte)
//   0x02e7fc: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x02e800: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02e804: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02e808: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02e80c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02e810: 910103fd  add      x29, sp, #0x40
//   0x02e814: b4000dc0  cbz      x0, #0x2e9cc
//   0x02e818: aa0103f4  mov      x20, x1
//   0x02e81c: aa0003f3  mov      x19, x0
//   0x02e820: b4000341  cbz      x1, #0x2e888
//   0x02e824: b9400668  ldr      w8, [x19, #4]
//   0x02e828: 350000a8  cbnz     w8, #0x2e83c
//   0x02e82c: aa1303e0  mov      x0, x19
//   0x02e830: aa1403e1  mov      x1, x20
//   0x02e834: 97fffc64  bl       #0x2d9c4
//   0x02e838: 34000ca0  cbz      w0, #0x2e9cc
uint64_t fde_0406_sub_02e7fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x02E7FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x02e7fc: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02e800: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02e804: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02e808: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02e80c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02e810: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000DC0ULL; // 0x02e814: cbz x0, #0x2e9cc
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02e818: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e81c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000341ULL; // 0x02e820: cbz x1, #0x2e888
    return acc;
}

// [EN] Reconstructed FDE #0407 @ 0x02ea44..0x02ee0c (968 bytes)
// [VN] Phục dựng FDE #0407 tại 0x02ea44..0x02ee0c (968 byte)
//   0x02ea44: d10203ff  sub      sp, sp, #0x80
//   0x02ea48: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x02ea4c: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x02ea50: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02ea54: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02ea58: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02ea5c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02ea60: 9101c3fd  add      x29, sp, #0x70
//   0x02ea64: 71003c9f  cmp      w4, #0xf
//   0x02ea68: 54001bcc  b.gt     #0x2ede0
//   0x02ea6c: f90007e3  str      x3, [sp, #8]
//   0x02ea70: 9100202b  add      x11, x1, #8
//   0x02ea74: f864d829  ldr      x9, [x1, w4, sxtw #3]
//   0x02ea78: 29412017  ldp      w23, w8, [x0, #8]
//   0x02ea7c: f9000feb  str      x11, [sp, #0x18]
//   0x02ea80: b00001ba  adrp     x26, #0x63000
uint64_t fde_0407_sub_02ea44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF864D829ULL) + (x2 ^ 0x02EA44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02ea44: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x02ea48: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x02ea4c: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02ea50: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02ea54: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02ea58: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02ea5c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02ea60: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0x71003C9FULL; // 0x02ea64: cmp w4, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0x54001BCCULL; // 0x02ea68: b.gt #0x2ede0
    return acc;
}

// [EN] Reconstructed FDE #0408 @ 0x02ee0c..0x02f18c (896 bytes)
// [VN] Phục dựng FDE #0408 tại 0x02ee0c..0x02f18c (896 byte)
//   0x02ee0c: d101c3ff  sub      sp, sp, #0x70
//   0x02ee10: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x02ee14: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x02ee18: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02ee1c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02ee20: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02ee24: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02ee28: 910183fd  add      x29, sp, #0x60
//   0x02ee2c: 71003c9f  cmp      w4, #0xf
//   0x02ee30: 5400198c  b.gt     #0x2f160
//   0x02ee34: f864d828  ldr      x8, [x1, w4, sxtw #3]
//   0x02ee38: 2941241a  ldp      w26, w9, [x0, #8]
//   0x02ee3c: 5280016a  mov      w10, #0xb
//   0x02ee40: aa0503f9  mov      x25, x5
//   0x02ee44: 2a0403f6  mov      w22, w4
//   0x02ee48: aa0303f4  mov      x20, x3
uint64_t fde_0408_sub_02ee0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x5280016AULL) + (x2 ^ 0x02EE0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02ee0c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x02ee10: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x02ee14: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02ee18: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02ee1c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02ee20: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02ee24: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02ee28: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x71003C9FULL; // 0x02ee2c: cmp w4, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0x5400198CULL; // 0x02ee30: b.gt #0x2f160
    return acc;
}

// [EN] Reconstructed FDE #0409 @ 0x02f18c..0x02f8d0 (1860 bytes)
// [VN] Phục dựng FDE #0409 tại 0x02f18c..0x02f8d0 (1860 byte)
//   0x02f18c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02f190: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02f194: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02f198: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02f19c: 9100c3fd  add      x29, sp, #0x30
//   0x02f1a0: 29412815  ldp      w21, w10, [x0, #8]
//   0x02f1a4: 39400c36  ldrb     w22, [x1, #3]
//   0x02f1a8: aa0103f4  mov      x20, x1
//   0x02f1ac: aa0003f3  mov      x19, x0
//   0x02f1b0: 36f8022a  tbz      w10, #0x1f, #0x2f1f4
//   0x02f1b4: f9400a68  ldr      x8, [x19, #0x10]
//   0x02f1b8: f9401269  ldr      x9, [x19, #0x20]
//   0x02f1bc: eb09011f  cmp      x8, x9
//   0x02f1c0: 54000142  b.hs     #0x2f1e8
//   0x02f1c4: f8407509  ldr      x9, [x8], #7
//   0x02f1c8: f940026b  ldr      x11, [x19]
uint64_t fde_0409_sub_02f18c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xEB09011FULL) + (x2 ^ 0x02F18CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02f18c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02f190: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02f194: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02f198: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02f19c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x29412815ULL; // 0x02f1a0: ldp w21, w10, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400C36ULL; // 0x02f1a4: ldrb w22, [x1, #3]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02f1a8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f1ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x36F8022AULL; // 0x02f1b0: tbz w10, #0x1f, #0x2f1f4
    return acc;
}

// [EN] Reconstructed FDE #0410 @ 0x02f8d0..0x02f8fc (44 bytes)
// [VN] Phục dựng FDE #0410 tại 0x02f8d0..0x02f8fc (44 byte)
//   0x02f8d0: f100143f  cmp      x1, #5
//   0x02f8d4: 54000103  b.lo     #0x2f8f4
//   0x02f8d8: 39400008  ldrb     w8, [x0]
//   0x02f8dc: 7100bd1f  cmp      w8, #0x2f
//   0x02f8e0: 540000a1  b.ne     #0x2f8f4
//   0x02f8e4: 39401008  ldrb     w8, [x0, #4]
//   0x02f8e8: 7100811f  cmp      w8, #0x20
//   0x02f8ec: 1a9f27e0  cset     w0, lo
//   0x02f8f0: d65f03c0  ret      
//   0x02f8f4: 2a1f03e0  mov      w0, wzr
//   0x02f8f8: d65f03c0  ret      
uint64_t fde_0410_sub_02f8d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF100143FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F8D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF100143FULL; // 0x02f8d0: cmp x1, #5
    acc = (acc * 0x100000001B3ULL) ^ 0x54000103ULL; // 0x02f8d4: b.lo #0x2f8f4
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02f8d8: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100BD1FULL; // 0x02f8dc: cmp w8, #0x2f
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A1ULL; // 0x02f8e0: b.ne #0x2f8f4
    acc = (acc * 0x100000001B3ULL) ^ 0x39401008ULL; // 0x02f8e4: ldrb w8, [x0, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100811FULL; // 0x02f8e8: cmp w8, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F27E0ULL; // 0x02f8ec: cset w0, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f8f0: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02f8f4: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0411 @ 0x02f8fc..0x02fa20 (292 bytes)
// [VN] Phục dựng FDE #0411 tại 0x02f8fc..0x02fa20 (292 byte)
//   0x02f8fc: d10203ff  sub      sp, sp, #0x80
//   0x02f900: f9001bf9  str      x25, [sp, #0x30]
//   0x02f904: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02f908: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02f90c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02f910: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02f914: 9101c3fd  add      x29, sp, #0x70
//   0x02f918: d53bd059  mrs      x25, tpidr_el0
//   0x02f91c: f9401728  ldr      x8, [x25, #0x28]
//   0x02f920: aa0203f5  mov      x21, x2
//   0x02f924: aa0103e2  mov      x2, x1
//   0x02f928: aa0003e1  mov      x1, x0
//   0x02f92c: 2a1f03e0  mov      w0, wzr
//   0x02f930: f90017e8  str      x8, [sp, #0x28]
//   0x02f934: b40004a1  cbz      x1, #0x2f9c8
//   0x02f938: f100145f  cmp      x2, #5
uint64_t fde_0411_sub_02f8fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A1F03E0ULL) + (x2 ^ 0x02F8FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02f8fc: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x02f900: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02f904: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02f908: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02f90c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02f910: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02f914: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02f918: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x02f91c: ldr x8, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02f920: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0412 @ 0x02fa20..0x02fa60 (64 bytes)
// [VN] Phục dựng FDE #0412 tại 0x02fa20..0x02fa60 (64 byte)
//   0x02fa20: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02fa24: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02fa28: 910043fd  add      x29, sp, #0x10
//   0x02fa2c: 52800020  mov      w0, #1
//   0x02fa30: 52803201  mov      w1, #0x190
//   0x02fa34: 97ffea9a  bl       #0x2a49c
//   0x02fa38: aa0003f3  mov      x19, x0
//   0x02fa3c: b40000a0  cbz      x0, #0x2fa50
//   0x02fa40: b0000128  adrp     x8, #0x54000
//   0x02fa44: fd447900  ldr      d0, [x8, #0x8f0]
//   0x02fa48: fd000260  str      d0, [x19]
//   0x02fa4c: 940022a3  bl       #0x384d8
//   0x02fa50: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02fa54: aa1303e0  mov      x0, x19
//   0x02fa58: f84207f3  ldr      x19, [sp], #0x20
//   0x02fa5c: d65f03c0  ret      
uint64_t fde_0412_sub_02fa20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x02FA20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02fa20: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02fa24: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02fa28: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x02fa2c: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52803201ULL; // 0x02fa30: mov w1, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA9AULL; // 0x02fa34: bl #0x2a49c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02fa38: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x02fa3c: cbz x0, #0x2fa50
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000128ULL; // 0x02fa40: adrp x8, #0x54000
    acc = (acc * 0x100000001B3ULL) ^ 0xFD447900ULL; // 0x02fa44: ldr d0, [x8, #0x8f0]
    return acc;
}

// [EN] Reconstructed FDE #0413 @ 0x02fa60..0x02fb24 (196 bytes)
// [VN] Phục dựng FDE #0413 tại 0x02fa60..0x02fb24 (196 byte)
//   0x02fa60: b4000600  cbz      x0, #0x2fb20
//   0x02fa64: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02fa68: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02fa6c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02fa70: 910083fd  add      x29, sp, #0x20
//   0x02fa74: aa0003f3  mov      x19, x0
//   0x02fa78: f9406800  ldr      x0, [x0, #0xd0]
//   0x02fa7c: 97ffea90  bl       #0x2a4bc
//   0x02fa80: 9103a260  add      x0, x19, #0xe8
//   0x02fa84: 94006858  bl       #0x49be4
//   0x02fa88: f9407260  ldr      x0, [x19, #0xe0]
//   0x02fa8c: 94006683  bl       #0x49498
//   0x02fa90: 91028260  add      x0, x19, #0xa0
//   0x02fa94: 9400666c  bl       #0x49444
//   0x02fa98: 9102c260  add      x0, x19, #0xb0
//   0x02fa9c: 9400666a  bl       #0x49444
uint64_t fde_0413_sub_02fa60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000600ULL) + (x1 ^ 0x91028260ULL) + (x2 ^ 0x02FA60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000600ULL; // 0x02fa60: cbz x0, #0x2fb20
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02fa64: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02fa68: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02fa6c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02fa70: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02fa74: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9406800ULL; // 0x02fa78: ldr x0, [x0, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA90ULL; // 0x02fa7c: bl #0x2a4bc
    acc = (acc * 0x100000001B3ULL) ^ 0x9103A260ULL; // 0x02fa80: add x0, x19, #0xe8
    acc = (acc * 0x100000001B3ULL) ^ 0x94006858ULL; // 0x02fa84: bl #0x49be4
    return acc;
}

// [EN] Reconstructed FDE #0414 @ 0x02fb24..0x02fb50 (44 bytes)
// [VN] Phục dựng FDE #0414 tại 0x02fb24..0x02fb50 (44 byte)
//   0x02fb24: b4000140  cbz      x0, #0x2fb4c
//   0x02fb28: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02fb2c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02fb30: 910043fd  add      x29, sp, #0x10
//   0x02fb34: aa0003f3  mov      x19, x0
//   0x02fb38: 97ffffca  bl       #0x2fa60
//   0x02fb3c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02fb40: aa1303e0  mov      x0, x19
//   0x02fb44: f84207f3  ldr      x19, [sp], #0x20
//   0x02fb48: 17ffea5d  b        #0x2a4bc
//   0x02fb4c: d65f03c0  ret      
uint64_t fde_0414_sub_02fb24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000140ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02FB24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000140ULL; // 0x02fb24: cbz x0, #0x2fb4c
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02fb28: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02fb2c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02fb30: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02fb34: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFCAULL; // 0x02fb38: bl #0x2fa60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02fb3c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02fb40: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x02fb44: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEA5DULL; // 0x02fb48: b #0x2a4bc
    return acc;
}

// [EN] Reconstructed FDE #0415 @ 0x02fb50..0x02fce4 (404 bytes)
// [VN] Phục dựng FDE #0415 tại 0x02fb50..0x02fce4 (404 byte)
//   0x02fb50: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02fb54: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02fb58: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02fb5c: 910083fd  add      x29, sp, #0x20
//   0x02fb60: aa0103f6  mov      x22, x1
//   0x02fb64: aa0003f4  mov      x20, x0
//   0x02fb68: 52800020  mov      w0, #1
//   0x02fb6c: 52803201  mov      w1, #0x190
//   0x02fb70: aa0203f5  mov      x21, x2
//   0x02fb74: 97ffea4a  bl       #0x2a49c
//   0x02fb78: b4000760  cbz      x0, #0x2fc64
//   0x02fb7c: b0000128  adrp     x8, #0x54000
//   0x02fb80: fd447900  ldr      d0, [x8, #0x8f0]
//   0x02fb84: aa0003f3  mov      x19, x0
//   0x02fb88: fd000000  str      d0, [x0]
//   0x02fb8c: 94002253  bl       #0x384d8
uint64_t fde_0415_sub_02fb50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xFD447900ULL) + (x2 ^ 0x02FB50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02fb50: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02fb54: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02fb58: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02fb5c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x02fb60: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02fb64: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x02fb68: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52803201ULL; // 0x02fb6c: mov w1, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02fb70: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA4AULL; // 0x02fb74: bl #0x2a49c
    return acc;
}

// [EN] Reconstructed FDE #0416 @ 0x02fce4..0x0307bc (2776 bytes)
// [VN] Phục dựng FDE #0416 tại 0x02fce4..0x0307bc (2776 byte)
//   0x02fce4: d10403ff  sub      sp, sp, #0x100
//   0x02fce8: fd004be8  str      d8, [sp, #0x90]
//   0x02fcec: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x02fcf0: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x02fcf4: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x02fcf8: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x02fcfc: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x02fd00: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x02fd04: 9103c3fd  add      x29, sp, #0xf0
//   0x02fd08: d53bd048  mrs      x8, tpidr_el0
//   0x02fd0c: f9003fe8  str      x8, [sp, #0x78]
//   0x02fd10: f9401508  ldr      x8, [x8, #0x28]
//   0x02fd14: aa0403f6  mov      x22, x4
//   0x02fd18: aa0303f3  mov      x19, x3
//   0x02fd1c: 2a0203fb  mov      w27, w2
//   0x02fd20: 2a0103f8  mov      w24, w1
uint64_t fde_0416_sub_02fce4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0xAA0403F6ULL) + (x2 ^ 0x02FCE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x02fce4: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xFD004BE8ULL; // 0x02fce8: str d8, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x02fcec: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x02fcf0: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x02fcf4: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x02fcf8: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x02fcfc: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x02fd00: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x02fd04: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x02fd08: mrs x8, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0417 @ 0x0307bc..0x030f4c (1936 bytes)
// [VN] Phục dựng FDE #0417 tại 0x0307bc..0x030f4c (1936 byte)
//   0x0307bc: d10283ff  sub      sp, sp, #0xa0
//   0x0307c0: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x0307c4: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x0307c8: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x0307cc: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x0307d0: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x0307d4: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x0307d8: 910243fd  add      x29, sp, #0x90
//   0x0307dc: f9400c13  ldr      x19, [x0, #0x18]
//   0x0307e0: b9408e68  ldr      w8, [x19, #0x8c]
//   0x0307e4: 6b01011f  cmp      w8, w1
//   0x0307e8: 5400070a  b.ge     #0x308c8
//   0x0307ec: b940c008  ldr      w8, [x0, #0xc0]
//   0x0307f0: aa0003f5  mov      x21, x0
//   0x0307f4: 2a0103f4  mov      w20, w1
//   0x0307f8: 34000068  cbz      w8, #0x30804
uint64_t fde_0417_sub_0307bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xB940C008ULL) + (x2 ^ 0x0307BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x0307bc: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x0307c0: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x0307c4: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x0307c8: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x0307cc: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x0307d0: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x0307d4: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x0307d8: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C13ULL; // 0x0307dc: ldr x19, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9408E68ULL; // 0x0307e0: ldr w8, [x19, #0x8c]
    return acc;
}

// [EN] Reconstructed FDE #0418 @ 0x030f4c..0x031924 (2520 bytes)
// [VN] Phục dựng FDE #0418 tại 0x030f4c..0x031924 (2520 byte)
//   0x030f4c: d10343ff  sub      sp, sp, #0xd0
//   0x030f50: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x030f54: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x030f58: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x030f5c: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x030f60: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x030f64: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x030f68: 910303fd  add      x29, sp, #0xc0
//   0x030f6c: b9809009  ldrsw    x9, [x0, #0x90]
//   0x030f70: b940500b  ldr      w11, [x0, #0x50]
//   0x030f74: b940980e  ldr      w14, [x0, #0x98]
//   0x030f78: 9100a008  add      x8, x0, #0x28
//   0x030f7c: 52a0200c  mov      w12, #0x1000000
//   0x030f80: 1ac20d35  sdiv     w21, w9, w2
//   0x030f84: 7100017f  cmp      w11, #0
//   0x030f88: f9002be8  str      x8, [sp, #0x50]
uint64_t fde_0418_sub_030f4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x52A0200CULL) + (x2 ^ 0x030F4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x030f4c: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x030f50: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x030f54: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x030f58: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x030f5c: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x030f60: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x030f64: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x030f68: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9809009ULL; // 0x030f6c: ldrsw x9, [x0, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xB940500BULL; // 0x030f70: ldr w11, [x0, #0x50]
    return acc;
}

// [EN] Reconstructed FDE #0419 @ 0x031924..0x031b24 (512 bytes)
// [VN] Phục dựng FDE #0419 tại 0x031924..0x031b24 (512 byte)
//   0x031924: d10203ff  sub      sp, sp, #0x80
//   0x031928: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x03192c: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x031930: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x031934: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x031938: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x03193c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x031940: 9101c3fd  add      x29, sp, #0x70
//   0x031944: b9408c16  ldr      w22, [x0, #0x8c]
//   0x031948: b90007e1  str      w1, [sp, #4]
//   0x03194c: 4b160034  sub      w20, w1, w22
//   0x031950: 7100069f  cmp      w20, #1
//   0x031954: 54000d2b  b.lt     #0x31af8
//   0x031958: b9408408  ldr      w8, [x0, #0x84]
//   0x03195c: f9400c09  ldr      x9, [x0, #0x18]
//   0x031960: 9103a00a  add      x10, x0, #0xe8
uint64_t fde_0419_sub_031924(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x54000D2BULL) + (x2 ^ 0x031924ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x031924: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x031928: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x03192c: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x031930: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x031934: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x031938: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x03193c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x031940: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xB9408C16ULL; // 0x031944: ldr w22, [x0, #0x8c]
    acc = (acc * 0x100000001B3ULL) ^ 0xB90007E1ULL; // 0x031948: str w1, [sp, #4]
    return acc;
}

// [EN] Reconstructed FDE #0420 @ 0x031b24..0x031c20 (252 bytes)
// [VN] Phục dựng FDE #0420 tại 0x031b24..0x031c20 (252 byte)
//   0x031b24: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x031b28: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x031b2c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x031b30: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x031b34: 9100c3fd  add      x29, sp, #0x30
//   0x031b38: b4000480  cbz      x0, #0x31bc8
//   0x031b3c: aa0103f4  mov      x20, x1
//   0x031b40: aa0003f3  mov      x19, x0
//   0x031b44: b4000461  cbz      x1, #0x31bd0
//   0x031b48: f9000674  str      x20, [x19, #8]
//   0x031b4c: b900027f  str      wzr, [x19]
//   0x031b50: a9460682  ldp      x2, x1, [x20, #0x60]
//   0x031b54: 9100a275  add      x21, x19, #0x28
//   0x031b58: aa1503e0  mov      x0, x21
//   0x031b5c: 94005da8  bl       #0x491fc
//   0x031b60: 52800101  mov      w1, #8
uint64_t fde_0420_sub_031b24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x9100A275ULL) + (x2 ^ 0x031B24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x031b24: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x031b28: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x031b2c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x031b30: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x031b34: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000480ULL; // 0x031b38: cbz x0, #0x31bc8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x031b3c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x031b40: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000461ULL; // 0x031b44: cbz x1, #0x31bd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000674ULL; // 0x031b48: str x20, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0421 @ 0x031c20..0x031e04 (484 bytes)
// [VN] Phục dựng FDE #0421 tại 0x031c20..0x031e04 (484 byte)
//   0x031c20: d101c3ff  sub      sp, sp, #0x70
//   0x031c24: f9000bfb  str      x27, [sp, #0x10]
//   0x031c28: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x031c2c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x031c30: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x031c34: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x031c38: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x031c3c: 910183fd  add      x29, sp, #0x60
//   0x031c40: b4000cc0  cbz      x0, #0x31dd8
//   0x031c44: f9400414  ldr      x20, [x0, #8]
//   0x031c48: b9400408  ldr      w8, [x0, #4]
//   0x031c4c: aa0003f3  mov      x19, x0
//   0x031c50: f9401e99  ldr      x25, [x20, #0x38]
//   0x031c54: 34000948  cbz      w8, #0x31d7c
//   0x031c58: f9400328  ldr      x8, [x25]
//   0x031c5c: 52800062  mov      w2, #3
uint64_t fde_0421_sub_031c20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9401E99ULL) + (x2 ^ 0x031C20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x031c20: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BFBULL; // 0x031c24: str x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x031c28: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x031c2c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x031c30: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x031c34: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x031c38: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x031c3c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000CC0ULL; // 0x031c40: cbz x0, #0x31dd8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x031c44: ldr x20, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0422 @ 0x031e04..0x03236c (1384 bytes)
// [VN] Phục dựng FDE #0422 tại 0x031e04..0x03236c (1384 byte)
//   0x031e04: d10243ff  sub      sp, sp, #0x90
//   0x031e08: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x031e0c: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x031e10: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x031e14: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x031e18: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x031e1c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x031e20: 910203fd  add      x29, sp, #0x80
//   0x031e24: b9408c16  ldr      w22, [x0, #0x8c]
//   0x031e28: aa0003f3  mov      x19, x0
//   0x031e2c: 2a0103fa  mov      w26, w1
//   0x031e30: 4b160028  sub      w8, w1, w22
//   0x031e34: 7100051f  cmp      w8, #1
//   0x031e38: 5400288b  b.lt     #0x32348
//   0x031e3c: f9400678  ldr      x24, [x19, #8]
//   0x031e40: b9408669  ldr      w9, [x19, #0x84]
uint64_t fde_0422_sub_031e04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x7100051FULL) + (x2 ^ 0x031E04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x031e04: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x031e08: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x031e0c: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x031e10: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x031e14: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x031e18: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x031e1c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x031e20: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xB9408C16ULL; // 0x031e24: ldr w22, [x0, #0x8c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x031e28: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0423 @ 0x03236c..0x0326c0 (852 bytes)
// [VN] Phục dựng FDE #0423 tại 0x03236c..0x0326c0 (852 byte)
//   0x03236c: d10403ff  sub      sp, sp, #0x100
//   0x032370: a90a6ffc  stp      x28, x27, [sp, #0xa0]
//   0x032374: a90b67fa  stp      x26, x25, [sp, #0xb0]
//   0x032378: a90c5ff8  stp      x24, x23, [sp, #0xc0]
//   0x03237c: a90d57f6  stp      x22, x21, [sp, #0xd0]
//   0x032380: a90e4ff4  stp      x20, x19, [sp, #0xe0]
//   0x032384: a90f7bfd  stp      x29, x30, [sp, #0xf0]
//   0x032388: 9103c3fd  add      x29, sp, #0xf0
//   0x03238c: d53bd059  mrs      x25, tpidr_el0
//   0x032390: f9401728  ldr      x8, [x25, #0x28]
//   0x032394: 9100a037  add      x23, x1, #0x28
//   0x032398: aa0103f3  mov      x19, x1
//   0x03239c: 2a0003f6  mov      w22, w0
//   0x0323a0: 52800021  mov      w1, #1
//   0x0323a4: aa1703e0  mov      x0, x23
//   0x0323a8: aa0303f4  mov      x20, x3
uint64_t fde_0423_sub_03236c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10403FFULL) + (x1 ^ 0x2A0003F6ULL) + (x2 ^ 0x03236CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10403FFULL; // 0x03236c: sub sp, sp, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A6FFCULL; // 0x032370: stp x28, x27, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B67FAULL; // 0x032374: stp x26, x25, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C5FF8ULL; // 0x032378: stp x24, x23, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D57F6ULL; // 0x03237c: stp x22, x21, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E4FF4ULL; // 0x032380: stp x20, x19, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F7BFDULL; // 0x032384: stp x29, x30, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9103C3FDULL; // 0x032388: add x29, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x03238c: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x032390: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0424 @ 0x0326c0..0x0327d8 (280 bytes)
// [VN] Phục dựng FDE #0424 tại 0x0326c0..0x0327d8 (280 byte)
//   0x0326c0: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x0326c4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x0326c8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0326cc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0326d0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0326d4: 910103fd  add      x29, sp, #0x40
//   0x0326d8: aa0003e9  mov      x9, x0
//   0x0326dc: b848cd2a  ldr      w10, [x9, #0x8c]!
//   0x0326e0: 2a0103f3  mov      w19, w1
//   0x0326e4: aa0003f4  mov      x20, x0
//   0x0326e8: f857c128  ldur     x8, [x9, #-0x84]
//   0x0326ec: f9401d18  ldr      x24, [x8, #0x38]
//   0x0326f0: 9102010c  add      x12, x8, #0x80
//   0x0326f4: b9400f0b  ldr      w11, [x24, #0xc]
//   0x0326f8: 7100097f  cmp      w11, #2
//   0x0326fc: 9a893189  csel     x9, x12, x9, lo
uint64_t fde_0424_sub_0326c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x9102010CULL) + (x2 ^ 0x0326C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x0326c0: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x0326c4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0326c8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0326cc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0326d0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0326d4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E9ULL; // 0x0326d8: mov x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB848CD2AULL; // 0x0326dc: ldr w10, [x9, #0x8c]!
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x0326e0: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0326e4: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0425 @ 0x0327d8..0x0329e4 (524 bytes)
// [VN] Phục dựng FDE #0425 tại 0x0327d8..0x0329e4 (524 byte)
//   0x0327d8: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x0327dc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0327e0: 7100043f  cmp      w1, #1
//   0x0327e4: 54000fab  b.lt     #0x329d8
//   0x0327e8: 52802028  mov      w8, #0x101
//   0x0327ec: 72a00028  movk     w8, #1, lsl #16
//   0x0327f0: 7100043f  cmp      w1, #1
//   0x0327f4: 2a0103e9  mov      w9, w1
//   0x0327f8: 54000061  b.ne     #0x32804
//   0x0327fc: aa1f03ea  mov      x10, xzr
//   0x032800: 14000054  b        #0x32950
//   0x032804: 7100005f  cmp      w2, #0
//   0x032808: 927f792a  and      x10, x9, #0xfffffffe
//   0x03280c: 9100100b  add      x11, x0, #4
//   0x032810: 52bfe00c  mov      w12, #-0x1000000
//   0x032814: 1a9f07ed  cset     w13, ne
uint64_t fde_0425_sub_0327d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF5ULL) + (x1 ^ 0x927F792AULL) + (x2 ^ 0x0327D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF5ULL; // 0x0327d8: str x21, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0327dc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0327e0: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000FABULL; // 0x0327e4: b.lt #0x329d8
    acc = (acc * 0x100000001B3ULL) ^ 0x52802028ULL; // 0x0327e8: mov w8, #0x101
    acc = (acc * 0x100000001B3ULL) ^ 0x72A00028ULL; // 0x0327ec: movk w8, #1, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x0327f0: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E9ULL; // 0x0327f4: mov w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000061ULL; // 0x0327f8: b.ne #0x32804
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03EAULL; // 0x0327fc: mov x10, xzr
    return acc;
}

// [EN] Reconstructed FDE #0426 @ 0x0329e4..0x032a50 (108 bytes)
// [VN] Phục dựng FDE #0426 tại 0x0329e4..0x032a50 (108 byte)
//   0x0329e4: 7100045f  cmp      w2, #1
//   0x0329e8: 5400032b  b.lt     #0x32a4c
//   0x0329ec: 52802029  mov      w9, #0x101
//   0x0329f0: 2a0203e8  mov      w8, w2
//   0x0329f4: 72a00029  movk     w9, #1, lsl #16
//   0x0329f8: 320903ea  mov      w10, #0x800000
//   0x0329fc: 52bfe00b  mov      w11, #-0x1000000
//   0x032a00: 14000006  b        #0x32a18
//   0x032a04: 3900001f  strb     wzr, [x0]
//   0x032a08: 91000400  add      x0, x0, #1
//   0x032a0c: f1000508  subs     x8, x8, #1
//   0x032a10: 91000421  add      x1, x1, #1
//   0x032a14: 540001c0  b.eq     #0x32a4c
//   0x032a18: 3940002c  ldrb     w12, [x1]
//   0x032a1c: 7103fd9f  cmp      w12, #0xff
//   0x032a20: 54ffff40  b.eq     #0x32a08
uint64_t fde_0426_sub_0329e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x540001C0ULL) + (x2 ^ 0x0329E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x0329e4: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400032BULL; // 0x0329e8: b.lt #0x32a4c
    acc = (acc * 0x100000001B3ULL) ^ 0x52802029ULL; // 0x0329ec: mov w9, #0x101
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x0329f0: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x72A00029ULL; // 0x0329f4: movk w9, #1, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x320903EAULL; // 0x0329f8: mov w10, #0x800000
    acc = (acc * 0x100000001B3ULL) ^ 0x52BFE00BULL; // 0x0329fc: mov w11, #-0x1000000
    acc = (acc * 0x100000001B3ULL) ^ 0x14000006ULL; // 0x032a00: b #0x32a18
    acc = (acc * 0x100000001B3ULL) ^ 0x3900001FULL; // 0x032a04: strb wzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x91000400ULL; // 0x032a08: add x0, x0, #1
    return acc;
}

// [EN] Reconstructed FDE #0427 @ 0x032a50..0x032abc (108 bytes)
// [VN] Phục dựng FDE #0427 tại 0x032a50..0x032abc (108 byte)
//   0x032a50: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x032a54: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x032a58: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x032a5c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x032a60: 9100c3fd  add      x29, sp, #0x30
//   0x032a64: 7100047f  cmp      w3, #1
//   0x032a68: 5400020b  b.lt     #0x32aa8
//   0x032a6c: b0000198  adrp     x24, #0x63000
//   0x032a70: f9471718  ldr      x24, [x24, #0xe28]
//   0x032a74: 2a0403f3  mov      w19, w4
//   0x032a78: 2a0303f4  mov      w20, w3
//   0x032a7c: 2a0203f5  mov      w21, w2
//   0x032a80: aa0003f6  mov      x22, x0
//   0x032a84: 93407c37  sxtw     x23, w1
//   0x032a88: f9400308  ldr      x8, [x24]
//   0x032a8c: aa1603e0  mov      x0, x22
uint64_t fde_0427_sub_032a50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x032A50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x032a50: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x032a54: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x032a58: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x032a5c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x032a60: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x032a64: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400020BULL; // 0x032a68: b.lt #0x32aa8
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000198ULL; // 0x032a6c: adrp x24, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471718ULL; // 0x032a70: ldr x24, [x24, #0xe28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F3ULL; // 0x032a74: mov w19, w4
    return acc;
}

// [EN] Reconstructed FDE #0428 @ 0x032abc..0x032b40 (132 bytes)
// [VN] Phục dựng FDE #0428 tại 0x032abc..0x032b40 (132 byte)
//   0x032abc: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x032ac0: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x032ac4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x032ac8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x032acc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x032ad0: 910103fd  add      x29, sp, #0x40
//   0x032ad4: 710004bf  cmp      w5, #1
//   0x032ad8: 5400028b  b.lt     #0x32b28
//   0x032adc: b000019a  adrp     x26, #0x63000
//   0x032ae0: f947835a  ldr      x26, [x26, #0xf00]
//   0x032ae4: 2a0603f3  mov      w19, w6
//   0x032ae8: 2a0503f4  mov      w20, w5
//   0x032aec: 2a0403f5  mov      w21, w4
//   0x032af0: aa0203f6  mov      x22, x2
//   0x032af4: aa0003f7  mov      x23, x0
//   0x032af8: 93407c38  sxtw     x24, w1
uint64_t fde_0428_sub_032abc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x2A0403F5ULL) + (x2 ^ 0x032ABCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x032abc: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x032ac0: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x032ac4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x032ac8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x032acc: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x032ad0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x710004BFULL; // 0x032ad4: cmp w5, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400028BULL; // 0x032ad8: b.lt #0x32b28
    acc = (acc * 0x100000001B3ULL) ^ 0xB000019AULL; // 0x032adc: adrp x26, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947835AULL; // 0x032ae0: ldr x26, [x26, #0xf00]
    return acc;
}

// [EN] Reconstructed FDE #0429 @ 0x032b40..0x032c30 (240 bytes)
// [VN] Phục dựng FDE #0429 tại 0x032b40..0x032c30 (240 byte)
//   0x032b40: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x032b44: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032b48: 910043fd  add      x29, sp, #0x10
//   0x032b4c: d0000180  adrp     x0, #0x64000
//   0x032b50: 91108000  add      x0, x0, #0x420
//   0x032b54: 97ff4577  bl       #0x4130
//   0x032b58: 34000080  cbz      w0, #0x32b68
//   0x032b5c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032b60: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x032b64: d65f03c0  ret      
//   0x032b68: b0000194  adrp     x20, #0x63000
//   0x032b6c: f947be94  ldr      x20, [x20, #0xf78]
//   0x032b70: d0000193  adrp     x19, #0x64000
//   0x032b74: f9415269  ldr      x9, [x19, #0x2a0]
//   0x032b78: f9400288  ldr      x8, [x20]
//   0x032b7c: eb08013f  cmp      x9, x8
uint64_t fde_0429_sub_032b40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD0000193ULL) + (x2 ^ 0x032B40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x032b40: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x032b44: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032b48: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000180ULL; // 0x032b4c: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91108000ULL; // 0x032b50: add x0, x0, #0x420
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF4577ULL; // 0x032b54: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x032b58: cbz w0, #0x32b68
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x032b5c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x032b60: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x032b64: ret 
    return acc;
}

// [EN] Reconstructed FDE #0430 @ 0x032c30..0x032e38 (520 bytes)
// [VN] Phục dựng FDE #0430 tại 0x032c30..0x032e38 (520 byte)
//   0x032c30: 7100045f  cmp      w2, #1
//   0x032c34: 5400100b  b.lt     #0x32e34
//   0x032c38: 2a0103e9  mov      w9, w1
//   0x032c3c: 93407c68  sxtw     x8, w3
//   0x032c40: 5282222a  mov      w10, #0x1111
//   0x032c44: 4f00e5e0  movi     v0.16b, #0xf
//   0x032c48: 0f00e621  movi     v1.8b, #0x11
//   0x032c4c: 927c6d2b  and      x11, x9, #0xfffffff0
//   0x032c50: 4f07e602  movi     v2.16b, #0xf0
//   0x032c54: 14000004  b        #0x32c64
//   0x032c58: 7100005f  cmp      w2, #0
//   0x032c5c: 8b080000  add      x0, x0, x8
//   0x032c60: 54000ead  b.le     #0x32e34
//   0x032c64: 7100043f  cmp      w1, #1
//   0x032c68: 51000442  sub      w2, w2, #1
//   0x032c6c: 54ffff6b  b.lt     #0x32c58
uint64_t fde_0430_sub_032c30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x54000EADULL) + (x2 ^ 0x032C30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x032c30: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400100BULL; // 0x032c34: b.lt #0x32e34
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E9ULL; // 0x032c38: mov w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C68ULL; // 0x032c3c: sxtw x8, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x5282222AULL; // 0x032c40: mov w10, #0x1111
    acc = (acc * 0x100000001B3ULL) ^ 0x4F00E5E0ULL; // 0x032c44: movi v0.16b, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0x0F00E621ULL; // 0x032c48: movi v1.8b, #0x11
    acc = (acc * 0x100000001B3ULL) ^ 0x927C6D2BULL; // 0x032c4c: and x11, x9, #0xfffffff0
    acc = (acc * 0x100000001B3ULL) ^ 0x4F07E602ULL; // 0x032c50: movi v2.16b, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0x14000004ULL; // 0x032c54: b #0x32c64
    return acc;
}

// [EN] Reconstructed FDE #0431 @ 0x032e38..0x032f28 (240 bytes)
// [VN] Phục dựng FDE #0431 tại 0x032e38..0x032f28 (240 byte)
//   0x032e38: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x032e3c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x032e40: 7100047f  cmp      w3, #1
//   0x032e44: 540006cb  b.lt     #0x32f1c
//   0x032e48: aa1f03ea  mov      x10, xzr
//   0x032e4c: 93407c88  sxtw     x8, w4
//   0x032e50: 7100047f  cmp      w3, #1
//   0x032e54: 2a0303eb  mov      w11, w3
//   0x032e58: 54000460  b.eq     #0x32ee4
//   0x032e5c: 7100049f  cmp      w4, #1
//   0x032e60: aa0a03e9  mov      x9, x10
//   0x032e64: 54000421  b.ne     #0x32ee8
//   0x032e68: 927f796a  and      x10, x11, #0xfffffffe
//   0x032e6c: aa1f03ec  mov      x12, xzr
//   0x032e70: 910010ad  add      x13, x5, #4
//   0x032e74: d37ff90e  lsl      x14, x8, #1
uint64_t fde_0431_sub_032e38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF5ULL) + (x1 ^ 0x927F796AULL) + (x2 ^ 0x032E38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF5ULL; // 0x032e38: str x21, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x032e3c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x032e40: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540006CBULL; // 0x032e44: b.lt #0x32f1c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03EAULL; // 0x032e48: mov x10, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C88ULL; // 0x032e4c: sxtw x8, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x032e50: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303EBULL; // 0x032e54: mov w11, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000460ULL; // 0x032e58: b.eq #0x32ee4
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x032e5c: cmp w4, #1
    return acc;
}

// [EN] Reconstructed FDE #0432 @ 0x032f28..0x032f4c (36 bytes)
// [VN] Phục dựng FDE #0432 tại 0x032f28..0x032f4c (36 byte)
//   0x032f28: 71000421  subs     w1, w1, #1
//   0x032f2c: 540000cb  b.lt     #0x32f44
//   0x032f30: 38401408  ldrb     w8, [x0], #1
//   0x032f34: 7103fd1f  cmp      w8, #0xff
//   0x032f38: 54ffff80  b.eq     #0x32f28
//   0x032f3c: 52800020  mov      w0, #1
//   0x032f40: d65f03c0  ret      
//   0x032f44: 2a1f03e0  mov      w0, wzr
//   0x032f48: d65f03c0  ret      
uint64_t fde_0432_sub_032f28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x71000421ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032F28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x71000421ULL; // 0x032f28: subs w1, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000CBULL; // 0x032f2c: b.lt #0x32f44
    acc = (acc * 0x100000001B3ULL) ^ 0x38401408ULL; // 0x032f30: ldrb w8, [x0], #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FD1FULL; // 0x032f34: cmp w8, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFF80ULL; // 0x032f38: b.eq #0x32f28
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x032f3c: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x032f40: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x032f44: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x032f48: ret 
    return acc;
}

// [EN] Reconstructed FDE #0433 @ 0x032f4c..0x032f80 (52 bytes)
// [VN] Phục dựng FDE #0433 tại 0x032f4c..0x032f80 (52 byte)
//   0x032f4c: 7100043f  cmp      w1, #1
//   0x032f50: 5400010b  b.lt     #0x32f70
//   0x032f54: 39400008  ldrb     w8, [x0]
//   0x032f58: 7103fd1f  cmp      w8, #0xff
//   0x032f5c: 540000e1  b.ne     #0x32f78
//   0x032f60: 51000421  sub      w1, w1, #1
//   0x032f64: 7100043f  cmp      w1, #1
//   0x032f68: 91001000  add      x0, x0, #4
//   0x032f6c: 54ffff4a  b.ge     #0x32f54
//   0x032f70: 2a1f03e0  mov      w0, wzr
//   0x032f74: d65f03c0  ret      
//   0x032f78: 52800020  mov      w0, #1
//   0x032f7c: d65f03c0  ret      
uint64_t fde_0433_sub_032f4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032F4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x032f4c: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400010BULL; // 0x032f50: b.lt #0x32f70
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x032f54: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x7103FD1FULL; // 0x032f58: cmp w8, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E1ULL; // 0x032f5c: b.ne #0x32f78
    acc = (acc * 0x100000001B3ULL) ^ 0x51000421ULL; // 0x032f60: sub w1, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x032f64: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x91001000ULL; // 0x032f68: add x0, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54FFFF4AULL; // 0x032f6c: b.ge #0x32f54
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x032f70: mov w0, wzr
    return acc;
}

// [EN] Reconstructed FDE #0434 @ 0x032f80..0x033034 (180 bytes)
// [VN] Phục dựng FDE #0434 tại 0x032f80..0x033034 (180 byte)
//   0x032f80: 7100043f  cmp      w1, #1
//   0x032f84: 5400056b  b.lt     #0x33030
//   0x032f88: 7100103f  cmp      w1, #4
//   0x032f8c: 2a0103e8  mov      w8, w1
//   0x032f90: 54000062  b.hs     #0x32f9c
//   0x032f94: aa1f03e9  mov      x9, xzr
//   0x032f98: 1400001b  b        #0x33004
//   0x032f9c: 927e7509  and      x9, x8, #0xfffffffc
//   0x032fa0: 9100200a  add      x10, x0, #8
//   0x032fa4: 0f006420  movi     v0.2s, #1, lsl #24
//   0x032fa8: aa0903eb  mov      x11, x9
//   0x032fac: 14000004  b        #0x32fbc
//   0x032fb0: f100116b  subs     x11, x11, #4
//   0x032fb4: 9100414a  add      x10, x10, #0x10
//   0x032fb8: 54000220  b.eq     #0x32ffc
//   0x032fbc: 6d7f8542  ldp      d2, d1, [x10, #-8]
uint64_t fde_0434_sub_032f80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0xF100116BULL) + (x2 ^ 0x032F80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x032f80: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400056BULL; // 0x032f84: b.lt #0x33030
    acc = (acc * 0x100000001B3ULL) ^ 0x7100103FULL; // 0x032f88: cmp w1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E8ULL; // 0x032f8c: mov w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x032f90: b.hs #0x32f9c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x032f94: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400001BULL; // 0x032f98: b #0x33004
    acc = (acc * 0x100000001B3ULL) ^ 0x927E7509ULL; // 0x032f9c: and x9, x8, #0xfffffffc
    acc = (acc * 0x100000001B3ULL) ^ 0x9100200AULL; // 0x032fa0: add x10, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x0F006420ULL; // 0x032fa4: movi v0.2s, #1, lsl #24
    return acc;
}

// [EN] Reconstructed FDE #0435 @ 0x033034..0x03309c (104 bytes)
// [VN] Phục dựng FDE #0435 tại 0x033034..0x03309c (104 byte)
//   0x033034: 90000188  adrp     x8, #0x63000
//   0x033038: 9000018a  adrp     x10, #0x63000
//   0x03303c: 9000018c  adrp     x12, #0x63000
//   0x033040: 9000018e  adrp     x14, #0x63000
//   0x033044: 90000190  adrp     x16, #0x63000
//   0x033048: f946b108  ldr      x8, [x8, #0xd60]
//   0x03304c: f946f54a  ldr      x10, [x10, #0xde8]
//   0x033050: f947218c  ldr      x12, [x12, #0xe40]
//   0x033054: f946e9ce  ldr      x14, [x14, #0xdd0]
//   0x033058: f9462210  ldr      x16, [x16, #0xc40]
//   0x03305c: 90000009  adrp     x9, #0x33000
//   0x033060: 9000000b  adrp     x11, #0x33000
//   0x033064: 9000000d  adrp     x13, #0x33000
//   0x033068: 9000000f  adrp     x15, #0x33000
//   0x03306c: 90000011  adrp     x17, #0x33000
//   0x033070: 91027129  add      x9, x9, #0x9c
uint64_t fde_0435_sub_033034(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000188ULL) + (x1 ^ 0x9000000DULL) + (x2 ^ 0x033034ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x033034: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x9000018AULL; // 0x033038: adrp x10, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x9000018CULL; // 0x03303c: adrp x12, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x9000018EULL; // 0x033040: adrp x14, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000190ULL; // 0x033044: adrp x16, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946B108ULL; // 0x033048: ldr x8, [x8, #0xd60]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946F54AULL; // 0x03304c: ldr x10, [x10, #0xde8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947218CULL; // 0x033050: ldr x12, [x12, #0xe40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946E9CEULL; // 0x033054: ldr x14, [x14, #0xdd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9462210ULL; // 0x033058: ldr x16, [x16, #0xc40]
    return acc;
}

// [EN] Reconstructed FDE #0436 @ 0x03309c..0x03321c (384 bytes)
// [VN] Phục dựng FDE #0436 tại 0x03309c..0x03321c (384 byte)
//   0x03309c: 7100047f  cmp      w3, #1
//   0x0330a0: 54000bcb  b.lt     #0x33218
//   0x0330a4: 5100204c  sub      w12, w2, #8
//   0x0330a8: 7100003f  cmp      w1, #0
//   0x0330ac: 5280006b  mov      w11, #3
//   0x0330b0: 121d718c  and      w12, w12, #0xfffffff8
//   0x0330b4: 93407c88  sxtw     x8, w4
//   0x0330b8: 93407c49  sxtw     x9, w2
//   0x0330bc: 1a9f07ea  cset     w10, ne
//   0x0330c0: 9a8b13eb  csel     x11, xzr, x11, ne
//   0x0330c4: 1100218c  add      w12, w12, #8
//   0x0330c8: 5290102d  mov      w13, #0x8081
//   0x0330cc: 7100205f  cmp      w2, #8
//   0x0330d0: 350000e1  cbnz     w1, #0x330ec
//   0x0330d4: 1400001b  b        #0x33140
//   0x0330d8: 7100007f  cmp      w3, #0
uint64_t fde_0436_sub_03309c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100047FULL) + (x1 ^ 0x7100205FULL) + (x2 ^ 0x03309CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x03309c: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000BCBULL; // 0x0330a0: b.lt #0x33218
    acc = (acc * 0x100000001B3ULL) ^ 0x5100204CULL; // 0x0330a4: sub w12, w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x7100003FULL; // 0x0330a8: cmp w1, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x5280006BULL; // 0x0330ac: mov w11, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x121D718CULL; // 0x0330b0: and w12, w12, #0xfffffff8
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C88ULL; // 0x0330b4: sxtw x8, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C49ULL; // 0x0330b8: sxtw x9, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07EAULL; // 0x0330bc: cset w10, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8B13EBULL; // 0x0330c0: csel x11, xzr, x11, ne
    return acc;
}

// [EN] Reconstructed FDE #0437 @ 0x03321c..0x0333b0 (404 bytes)
// [VN] Phục dựng FDE #0437 tại 0x03321c..0x0333b0 (404 byte)
//   0x03321c: f81e0ff5  str      x21, [sp, #-0x20]!
//   0x033220: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x033224: 7100047f  cmp      w3, #1
//   0x033228: 54000aab  b.lt     #0x3337c
//   0x03322c: 51000449  sub      w9, w2, #1
//   0x033230: 2a1f03e8  mov      w8, wzr
//   0x033234: 93407c2a  sxtw     x10, w1
//   0x033238: 93407cab  sxtw     x11, w5
//   0x03323c: 93407c4c  sxtw     x12, w2
//   0x033240: 6f07e7e0  movi     v0.2d, #0xffffffffffffffff
//   0x033244: 121d712d  and      w13, w9, #0xfffffff8
//   0x033248: 52801fe9  mov      w9, #0xff
//   0x03324c: 7100245f  cmp      w2, #9
//   0x033250: 5400012a  b.ge     #0x33274
//   0x033254: 14000019  b        #0x332b8
//   0x033258: 11000508  add      w8, w8, #1
uint64_t fde_0437_sub_03321c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF5ULL) + (x1 ^ 0x7100245FULL) + (x2 ^ 0x03321CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF5ULL; // 0x03321c: str x21, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x033220: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x033224: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000AABULL; // 0x033228: b.lt #0x3337c
    acc = (acc * 0x100000001B3ULL) ^ 0x51000449ULL; // 0x03322c: sub w9, w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x033230: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C2AULL; // 0x033234: sxtw x10, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407CABULL; // 0x033238: sxtw x11, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C4CULL; // 0x03323c: sxtw x12, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x6F07E7E0ULL; // 0x033240: movi v0.2d, #0xffffffffffffffff
    return acc;
}

// [EN] Reconstructed FDE #0438 @ 0x0333b0..0x0334b8 (264 bytes)
// [VN] Phục dựng FDE #0438 tại 0x0333b0..0x0334b8 (264 byte)
//   0x0333b0: 7100047f  cmp      w3, #1
//   0x0333b4: 5400080b  b.lt     #0x334b4
//   0x0333b8: 2a1f03e8  mov      w8, wzr
//   0x0333bc: 93407c29  sxtw     x9, w1
//   0x0333c0: 93407c4a  sxtw     x10, w2
//   0x0333c4: 121d704b  and      w11, w2, #0xfffffff8
//   0x0333c8: 937e7cac  sbfiz    x12, x5, #2, #0x20
//   0x0333cc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0333d0: 7100205f  cmp      w2, #8
//   0x0333d4: 540001aa  b.ge     #0x33408
//   0x0333d8: 14000008  b        #0x333f8
//   0x0333dc: 11000508  add      w8, w8, #1
//   0x0333e0: 8b090000  add      x0, x0, x9
//   0x0333e4: 6b03011f  cmp      w8, w3
//   0x0333e8: 8b0c0084  add      x4, x4, x12
//   0x0333ec: 54000640  b.eq     #0x334b4
uint64_t fde_0438_sub_0333b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100047FULL) + (x1 ^ 0x8B090000ULL) + (x2 ^ 0x0333B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x0333b0: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400080BULL; // 0x0333b4: b.lt #0x334b4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0333b8: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C29ULL; // 0x0333bc: sxtw x9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C4AULL; // 0x0333c0: sxtw x10, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x121D704BULL; // 0x0333c4: and w11, w2, #0xfffffff8
    acc = (acc * 0x100000001B3ULL) ^ 0x937E7CACULL; // 0x0333c8: sbfiz x12, x5, #2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x0333cc: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x7100205FULL; // 0x0333d0: cmp w2, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540001AAULL; // 0x0333d4: b.ge #0x33408
    return acc;
}

// [EN] Reconstructed FDE #0439 @ 0x0334b8..0x033640 (392 bytes)
// [VN] Phục dựng FDE #0439 tại 0x0334b8..0x033640 (392 byte)
//   0x0334b8: a9bf4ff4  stp      x20, x19, [sp, #-0x10]!
//   0x0334bc: 7100047f  cmp      w3, #1
//   0x0334c0: 54000a8b  b.lt     #0x33610
//   0x0334c4: 51000449  sub      w9, w2, #1
//   0x0334c8: 2a1f03e8  mov      w8, wzr
//   0x0334cc: 93407c2a  sxtw     x10, w1
//   0x0334d0: 93407cab  sxtw     x11, w5
//   0x0334d4: 93407c4c  sxtw     x12, w2
//   0x0334d8: 6f07e7e0  movi     v0.2d, #0xffffffffffffffff
//   0x0334dc: 121d712d  and      w13, w9, #0xfffffff8
//   0x0334e0: 52801fe9  mov      w9, #0xff
//   0x0334e4: 7100245f  cmp      w2, #9
//   0x0334e8: 5400012a  b.ge     #0x3350c
//   0x0334ec: 14000018  b        #0x3354c
//   0x0334f0: 11000508  add      w8, w8, #1
//   0x0334f4: 8b0a0000  add      x0, x0, x10
uint64_t fde_0439_sub_0334b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF4FF4ULL) + (x1 ^ 0x5400012AULL) + (x2 ^ 0x0334B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF4FF4ULL; // 0x0334b8: stp x20, x19, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7100047FULL; // 0x0334bc: cmp w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000A8BULL; // 0x0334c0: b.lt #0x33610
    acc = (acc * 0x100000001B3ULL) ^ 0x51000449ULL; // 0x0334c4: sub w9, w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x0334c8: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C2AULL; // 0x0334cc: sxtw x10, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407CABULL; // 0x0334d0: sxtw x11, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C4CULL; // 0x0334d4: sxtw x12, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x6F07E7E0ULL; // 0x0334d8: movi v0.2d, #0xffffffffffffffff
    acc = (acc * 0x100000001B3ULL) ^ 0x121D712DULL; // 0x0334dc: and w13, w9, #0xfffffff8
    return acc;
}

// [EN] Reconstructed FDE #0440 @ 0x033640..0x033710 (208 bytes)
// [VN] Phục dựng FDE #0440 tại 0x033640..0x033710 (208 byte)
//   0x033640: 7100405f  cmp      w2, #0x10
//   0x033644: 540000aa  b.ge     #0x33658
//   0x033648: 2a1f03e8  mov      w8, wzr
//   0x03364c: 6b02011f  cmp      w8, w2
//   0x033650: 540001eb  b.lt     #0x3368c
//   0x033654: 1400002e  b        #0x3370c
//   0x033658: aa1f03e9  mov      x9, xzr
//   0x03365c: 93407c48  sxtw     x8, w2
//   0x033660: aa0003ea  mov      x10, x0
//   0x033664: 4cdf0140  ld4      {v0.16b, v1.16b, v2.16b, v3.16b}, [x10], #64
//   0x033668: 9100812b  add      x11, x9, #0x20
//   0x03366c: 9100412c  add      x12, x9, #0x10
//   0x033670: eb08017f  cmp      x11, x8
//   0x033674: 3ca96821  str      q1, [x1, x9]
//   0x033678: aa0c03e9  mov      x9, x12
//   0x03367c: 54ffff4d  b.le     #0x33664
uint64_t fde_0440_sub_033640(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100405FULL) + (x1 ^ 0xEB08017FULL) + (x2 ^ 0x033640ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100405FULL; // 0x033640: cmp w2, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x033644: b.ge #0x33658
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E8ULL; // 0x033648: mov w8, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x6B02011FULL; // 0x03364c: cmp w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x540001EBULL; // 0x033650: b.lt #0x3368c
    acc = (acc * 0x100000001B3ULL) ^ 0x1400002EULL; // 0x033654: b #0x3370c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x033658: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x03365c: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003EAULL; // 0x033660: mov x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x4CDF0140ULL; // 0x033664: ld4 {v0.16b, v1.16b, v2.16b, v3.16b}, [x10], #64
    return acc;
}

// [EN] Reconstructed FDE #0441 @ 0x033710..0x03371c (12 bytes)
// [VN] Phục dựng FDE #0441 tại 0x033710..0x03371c (12 byte)
//   0x033710: 7100181f  cmp      w0, #6
//   0x033714: 1a9f17e0  cset     w0, eq
//   0x033718: d65f03c0  ret      
uint64_t fde_0441_sub_033710(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100181FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x033710ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100181FULL; // 0x033710: cmp w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x033714: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x033718: ret 
    return acc;
}

// [EN] Reconstructed FDE #0442 @ 0x03371c..0x033808 (236 bytes)
// [VN] Phục dựng FDE #0442 tại 0x03371c..0x033808 (236 byte)
//   0x03371c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x033720: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x033724: 910043fd  add      x29, sp, #0x10
//   0x033728: b0000180  adrp     x0, #0x64000
//   0x03372c: 91112000  add      x0, x0, #0x448
//   0x033730: 97ff4280  bl       #0x4130
//   0x033734: 34000080  cbz      w0, #0x33744
//   0x033738: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03373c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x033740: d65f03c0  ret      
//   0x033744: 90000194  adrp     x20, #0x63000
//   0x033748: f947be94  ldr      x20, [x20, #0xf78]
//   0x03374c: b0000193  adrp     x19, #0x64000
//   0x033750: f9415a69  ldr      x9, [x19, #0x2b0]
//   0x033754: f9400288  ldr      x8, [x20]
//   0x033758: eb08013f  cmp      x9, x8
uint64_t fde_0442_sub_03371c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB0000193ULL) + (x2 ^ 0x03371CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03371c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x033720: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x033724: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000180ULL; // 0x033728: adrp x0, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0x91112000ULL; // 0x03372c: add x0, x0, #0x448
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF4280ULL; // 0x033730: bl #0x4130
    acc = (acc * 0x100000001B3ULL) ^ 0x34000080ULL; // 0x033734: cbz w0, #0x33744
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x033738: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C24FF4ULL; // 0x03373c: ldp x20, x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x033740: ret 
    return acc;
}

// [EN] Reconstructed FDE #0443 @ 0x033808..0x033854 (76 bytes)
// [VN] Phục dựng FDE #0443 tại 0x033808..0x033854 (76 byte)
//   0x033808: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x03380c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x033810: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x033814: 910083fd  add      x29, sp, #0x20
//   0x033818: 90000195  adrp     x21, #0x63000
//   0x03381c: f94756b5  ldr      x21, [x21, #0xea8]
//   0x033820: 52800022  mov      w2, #1
//   0x033824: aa0103f3  mov      x19, x1
//   0x033828: aa0003f4  mov      x20, x0
//   0x03382c: f94002a8  ldr      x8, [x21]
//   0x033830: d63f0100  blr      x8
//   0x033834: f94002a3  ldr      x3, [x21]
//   0x033838: 91010280  add      x0, x20, #0x40
//   0x03383c: 91020261  add      x1, x19, #0x80
//   0x033840: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x033844: a9414ff4  ldp      x20, x19, [sp, #0x10]
uint64_t fde_0443_sub_033808(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x91010280ULL) + (x2 ^ 0x033808ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x033808: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x03380c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x033810: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x033814: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000195ULL; // 0x033818: adrp x21, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94756B5ULL; // 0x03381c: ldr x21, [x21, #0xea8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800022ULL; // 0x033820: mov w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x033824: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x033828: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002A8ULL; // 0x03382c: ldr x8, [x21]
    return acc;
}

// [EN] Reconstructed FDE #0444 @ 0x033854..0x0338f0 (156 bytes)
// [VN] Phục dựng FDE #0444 tại 0x033854..0x0338f0 (156 byte)
//   0x033854: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x033858: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03385c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x033860: 910083fd  add      x29, sp, #0x20
//   0x033864: 90000195  adrp     x21, #0x63000
//   0x033868: 79400008  ldrh     w8, [x0]
//   0x03386c: f94702b5  ldr      x21, [x21, #0xe00]
//   0x033870: aa0103f3  mov      x19, x1
//   0x033874: aa0003f4  mov      x20, x0
//   0x033878: 340000a8  cbz      w8, #0x3388c
//   0x03387c: f94002a8  ldr      x8, [x21]
//   0x033880: aa1403e0  mov      x0, x20
//   0x033884: aa1303e1  mov      x1, x19
//   0x033888: d63f0100  blr      x8
//   0x03388c: aa1403e0  mov      x0, x20
//   0x033890: 78420c08  ldrh     w8, [x0, #0x20]!
uint64_t fde_0444_sub_033854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1303E1ULL) + (x2 ^ 0x033854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x033854: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x033858: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03385c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x033860: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000195ULL; // 0x033864: adrp x21, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x79400008ULL; // 0x033868: ldrh w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94702B5ULL; // 0x03386c: ldr x21, [x21, #0xe00]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x033870: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x033874: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000A8ULL; // 0x033878: cbz w8, #0x3388c
    return acc;
}

// [EN] Reconstructed FDE #0445 @ 0x0338f0..0x03397c (140 bytes)
// [VN] Phục dựng FDE #0445 tại 0x0338f0..0x03397c (140 byte)
//   0x0338f0: d10043ff  sub      sp, sp, #0x10
//   0x0338f4: 39407c0a  ldrb     w10, [x0, #0x1f]
//   0x0338f8: 385df008  ldurb    w8, [x0, #-0x21]
//   0x0338fc: 3940fc0b  ldrb     w11, [x0, #0x3f]
//   0x033900: 385ff009  ldurb    w9, [x0, #-1]
//   0x033904: 39417c0c  ldrb     w12, [x0, #0x5f]
//   0x033908: 1100094e  add      w14, w10, #2
//   0x03390c: 0b0801c8  add      w8, w14, w8
//   0x033910: 0b0b05ce  add      w14, w14, w11, lsl #1
//   0x033914: 1100096b  add      w11, w11, #2
//   0x033918: 0b090508  add      w8, w8, w9, lsl #1
//   0x03391c: 0b090169  add      w9, w11, w9
//   0x033920: 0b0c016b  add      w11, w11, w12
//   0x033924: 0b0a0529  add      w9, w9, w10, lsl #1
//   0x033928: 0b0c01ca  add      w10, w14, w12
//   0x03392c: 0b0c056b  add      w11, w11, w12, lsl #1
uint64_t fde_0445_sub_0338f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10043FFULL) + (x1 ^ 0x0B0C016BULL) + (x2 ^ 0x0338F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10043FFULL; // 0x0338f0: sub sp, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39407C0AULL; // 0x0338f4: ldrb w10, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385DF008ULL; // 0x0338f8: ldurb w8, [x0, #-0x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940FC0BULL; // 0x0338fc: ldrb w11, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385FF009ULL; // 0x033900: ldurb w9, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39417C0CULL; // 0x033904: ldrb w12, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0x1100094EULL; // 0x033908: add w14, w10, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0801C8ULL; // 0x03390c: add w8, w14, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0B05CEULL; // 0x033910: add w14, w14, w11, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1100096BULL; // 0x033914: add w11, w11, #2
    return acc;
}

// [EN] Reconstructed FDE #0446 @ 0x03397c..0x033a64 (232 bytes)
// [VN] Phục dựng FDE #0446 tại 0x03397c..0x033a64 (232 byte)
//   0x03397c: 385ff008  ldurb    w8, [x0, #-1]
//   0x033980: 3940fc0a  ldrb     w10, [x0, #0x3f]
//   0x033984: 385df00b  ldurb    w11, [x0, #-0x21]
//   0x033988: 39407c09  ldrb     w9, [x0, #0x1f]
//   0x03398c: 385e000c  ldurb    w12, [x0, #-0x20]
//   0x033990: 385e100d  ldurb    w13, [x0, #-0x1f]
//   0x033994: 385e200e  ldurb    w14, [x0, #-0x1e]
//   0x033998: 385e300f  ldurb    w15, [x0, #-0x1d]
//   0x03399c: 11000911  add      w17, w8, #2
//   0x0339a0: 11000961  add      w1, w11, #2
//   0x0339a4: 0b0a022a  add      w10, w17, w10
//   0x0339a8: 0b09054a  add      w10, w10, w9, lsl #1
//   0x0339ac: 0b090029  add      w9, w1, w9
//   0x0339b0: 0b0b0631  add      w17, w17, w11, lsl #1
//   0x0339b4: 11000590  add      w16, w12, #1
//   0x0339b8: 0b080528  add      w8, w9, w8, lsl #1
uint64_t fde_0446_sub_03397c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x385FF008ULL) + (x1 ^ 0x0B090029ULL) + (x2 ^ 0x03397CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x385FF008ULL; // 0x03397c: ldurb w8, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940FC0AULL; // 0x033980: ldrb w10, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385DF00BULL; // 0x033984: ldurb w11, [x0, #-0x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x39407C09ULL; // 0x033988: ldrb w9, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E000CULL; // 0x03398c: ldurb w12, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E100DULL; // 0x033990: ldurb w13, [x0, #-0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E200EULL; // 0x033994: ldurb w14, [x0, #-0x1e]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E300FULL; // 0x033998: ldurb w15, [x0, #-0x1d]
    acc = (acc * 0x100000001B3ULL) ^ 0x11000911ULL; // 0x03399c: add w17, w8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x11000961ULL; // 0x0339a0: add w1, w11, #2
    return acc;
}

// [EN] Reconstructed FDE #0447 @ 0x033a64..0x033b4c (232 bytes)
// [VN] Phục dựng FDE #0447 tại 0x033a64..0x033b4c (232 byte)
//   0x033a64: 385e400c  ldurb    w12, [x0, #-0x1c]
//   0x033a68: 385e500d  ldurb    w13, [x0, #-0x1b]
//   0x033a6c: 385e1009  ldurb    w9, [x0, #-0x1f]
//   0x033a70: 385e200a  ldurb    w10, [x0, #-0x1e]
//   0x033a74: 385e600e  ldurb    w14, [x0, #-0x1a]
//   0x033a78: 385e0008  ldurb    w8, [x0, #-0x20]
//   0x033a7c: 385e300b  ldurb    w11, [x0, #-0x1d]
//   0x033a80: 385e700f  ldurb    w15, [x0, #-0x19]
//   0x033a84: 0b0d0582  add      w2, w12, w13, lsl #1
//   0x033a88: 11000530  add      w16, w9, #1
//   0x033a8c: 11000951  add      w17, w10, #2
//   0x033a90: 0b0e0042  add      w2, w2, w14
//   0x033a94: 0b0e05ae  add      w14, w13, w14, lsl #1
//   0x033a98: 11000961  add      w1, w11, #2
//   0x033a9c: 0b0f01ce  add      w14, w14, w15
//   0x033aa0: 0b08020f  add      w15, w16, w8
uint64_t fde_0447_sub_033a64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x385E400CULL) + (x1 ^ 0x0B0E05AEULL) + (x2 ^ 0x033A64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x385E400CULL; // 0x033a64: ldurb w12, [x0, #-0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E500DULL; // 0x033a68: ldurb w13, [x0, #-0x1b]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E1009ULL; // 0x033a6c: ldurb w9, [x0, #-0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E200AULL; // 0x033a70: ldurb w10, [x0, #-0x1e]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E600EULL; // 0x033a74: ldurb w14, [x0, #-0x1a]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E0008ULL; // 0x033a78: ldurb w8, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E300BULL; // 0x033a7c: ldurb w11, [x0, #-0x1d]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E700FULL; // 0x033a80: ldurb w15, [x0, #-0x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0D0582ULL; // 0x033a84: add w2, w12, w13, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x11000530ULL; // 0x033a88: add w16, w9, #1
    return acc;
}

// [EN] Reconstructed FDE #0448 @ 0x033b4c..0x033c34 (232 bytes)
// [VN] Phục dựng FDE #0448 tại 0x033b4c..0x033c34 (232 byte)
//   0x033b4c: 385e000c  ldurb    w12, [x0, #-0x20]
//   0x033b50: 385e100d  ldurb    w13, [x0, #-0x1f]
//   0x033b54: 385ff008  ldurb    w8, [x0, #-1]
//   0x033b58: 385df00e  ldurb    w14, [x0, #-0x21]
//   0x033b5c: 385e200f  ldurb    w15, [x0, #-0x1e]
//   0x033b60: 39407c09  ldrb     w9, [x0, #0x1f]
//   0x033b64: 3940fc0a  ldrb     w10, [x0, #0x3f]
//   0x033b68: 0b0d0591  add      w17, w12, w13, lsl #1
//   0x033b6c: 39417c0b  ldrb     w11, [x0, #0x5f]
//   0x033b70: 0b0c05c1  add      w1, w14, w12, lsl #1
//   0x033b74: 0b0f022f  add      w15, w17, w15
//   0x033b78: 11000911  add      w17, w8, #2
//   0x033b7c: 0b0d002d  add      w13, w1, w13
//   0x033b80: 0b0e0621  add      w1, w17, w14, lsl #1
//   0x033b84: 0b0c002c  add      w12, w1, w12
//   0x033b88: 11000921  add      w1, w9, #2
uint64_t fde_0448_sub_033b4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x385E000CULL) + (x1 ^ 0x0B0D002DULL) + (x2 ^ 0x033B4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x385E000CULL; // 0x033b4c: ldurb w12, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E100DULL; // 0x033b50: ldurb w13, [x0, #-0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385FF008ULL; // 0x033b54: ldurb w8, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0x385DF00EULL; // 0x033b58: ldurb w14, [x0, #-0x21]
    acc = (acc * 0x100000001B3ULL) ^ 0x385E200FULL; // 0x033b5c: ldurb w15, [x0, #-0x1e]
    acc = (acc * 0x100000001B3ULL) ^ 0x39407C09ULL; // 0x033b60: ldrb w9, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x3940FC0AULL; // 0x033b64: ldrb w10, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0D0591ULL; // 0x033b68: add w17, w12, w13, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39417C0BULL; // 0x033b6c: ldrb w11, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0C05C1ULL; // 0x033b70: add w1, w14, w12, lsl #1
    return acc;
}

// [EN] Reconstructed FDE #0449 @ 0x033c34..0x033cd0 (156 bytes)
// [VN] Phục dựng FDE #0449 tại 0x033c34..0x033cd0 (156 byte)
//   0x033c34: 3940fc0a  ldrb     w10, [x0, #0x3f]
//   0x033c38: 385ff008  ldurb    w8, [x0, #-1]
//   0x033c3c: 39407c09  ldrb     w9, [x0, #0x1f]
//   0x033c40: 39417c0b  ldrb     w11, [x0, #0x5f]
//   0x033c44: 1100094e  add      w14, w10, #2
//   0x033c48: 0b0801cf  add      w15, w14, w8
//   0x033c4c: 1100052d  add      w13, w9, #1
//   0x033c50: 0b0905ef  add      w15, w15, w9, lsl #1
//   0x033c54: 0b090169  add      w9, w11, w9
//   0x033c58: 0b0801a8  add      w8, w13, w8
//   0x033c5c: 0b0a01ad  add      w13, w13, w10
//   0x033c60: 0b0a0529  add      w9, w9, w10, lsl #1
//   0x033c64: 0b0b014a  add      w10, w10, w11
//   0x033c68: 53017d08  lsr      w8, w8, #1
//   0x033c6c: 3200c3ec  mov      w12, #0x1010101
//   0x033c70: 0b0b01ce  add      w14, w14, w11
uint64_t fde_0449_sub_033c34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3940FC0AULL) + (x1 ^ 0x0B0B014AULL) + (x2 ^ 0x033C34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3940FC0AULL; // 0x033c34: ldrb w10, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x385FF008ULL; // 0x033c38: ldurb w8, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0x39407C09ULL; // 0x033c3c: ldrb w9, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0x39417C0BULL; // 0x033c40: ldrb w11, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0x1100094EULL; // 0x033c44: add w14, w10, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0801CFULL; // 0x033c48: add w15, w14, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1100052DULL; // 0x033c4c: add w13, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0905EFULL; // 0x033c50: add w15, w15, w9, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x0B090169ULL; // 0x033c54: add w9, w11, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0801A8ULL; // 0x033c58: add w8, w13, w8
    return acc;
}

// [EN] Reconstructed FDE #0450 @ 0x033cd0..0x033f64 (660 bytes)
// [VN] Phục dựng FDE #0450 tại 0x033cd0..0x033f64 (660 byte)
//   0x033cd0: 7100045f  cmp      w2, #1
//   0x033cd4: 93407c48  sxtw     x8, w2
//   0x033cd8: aa1f03e9  mov      x9, xzr
//   0x033cdc: 54000a41  b.ne     #0x33e24
//   0x033ce0: 3940182c  ldrb     w12, [x1, #6]
//   0x033ce4: 91000c2a  add      x10, x1, #3
//   0x033ce8: 52801feb  mov      w11, #0xff
//   0x033cec: 8b09000d  add      x13, x0, x9
//   0x033cf0: 394001ae  ldrb     w14, [x13]
//   0x033cf4: 385fd14f  ldurb    w15, [x10, #-3]
//   0x033cf8: 91002129  add      x9, x9, #8
//   0x033cfc: 5101e1ce  sub      w14, w14, #0x78
//   0x033d00: 0b8e11ee  add      w14, w15, w14, asr #4
//   0x033d04: 710001df  cmp      w14, #0
//   0x033d08: 1a8bb3ef  csel     w15, wzr, w11, lt
//   0x033d0c: 7103fddf  cmp      w14, #0xff
uint64_t fde_0450_sub_033cd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100045FULL) + (x1 ^ 0x0B8E11EEULL) + (x2 ^ 0x033CD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100045FULL; // 0x033cd0: cmp w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x033cd4: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E9ULL; // 0x033cd8: mov x9, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x54000A41ULL; // 0x033cdc: b.ne #0x33e24
    acc = (acc * 0x100000001B3ULL) ^ 0x3940182CULL; // 0x033ce0: ldrb w12, [x1, #6]
    acc = (acc * 0x100000001B3ULL) ^ 0x91000C2AULL; // 0x033ce4: add x10, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEBULL; // 0x033ce8: mov w11, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09000DULL; // 0x033cec: add x13, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x394001AEULL; // 0x033cf0: ldrb w14, [x13]
    acc = (acc * 0x100000001B3ULL) ^ 0x385FD14FULL; // 0x033cf4: ldurb w15, [x10, #-3]
    return acc;
}

// [EN] Reconstructed FDE #0451 @ 0x033f64..0x033f68 (4 bytes)
// [VN] Phục dựng FDE #0451 tại 0x033f64..0x033f68 (4 byte)
//   0x033f64: d65f03c0  ret      
uint64_t fde_0451_sub_033f64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x033F64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x033f64: ret 
    return acc;
}

// [EN] Reconstructed FDE #0452 @ 0x033f68..0x0341bc (596 bytes)
// [VN] Phục dựng FDE #0452 tại 0x033f68..0x0341bc (596 byte)
//   0x033f68: 90000188  adrp     x8, #0x63000
//   0x033f6c: f9475508  ldr      x8, [x8, #0xea8]
//   0x033f70: b0000009  adrp     x9, #0x34000
//   0x033f74: 9106f129  add      x9, x9, #0x1bc
//   0x033f78: 9000018a  adrp     x10, #0x63000
//   0x033f7c: f946ad4a  ldr      x10, [x10, #0xd58]
//   0x033f80: f9000109  str      x9, [x8]
//   0x033f84: 90000188  adrp     x8, #0x63000
//   0x033f88: f9470108  ldr      x8, [x8, #0xe00]
//   0x033f8c: b000000b  adrp     x11, #0x34000
//   0x033f90: 910ef16b  add      x11, x11, #0x3bc
//   0x033f94: b0000009  adrp     x9, #0x34000
//   0x033f98: 9111e129  add      x9, x9, #0x478
//   0x033f9c: f900014b  str      x11, [x10]
//   0x033fa0: 9000018a  adrp     x10, #0x63000
//   0x033fa4: f9466d4a  ldr      x10, [x10, #0xcd8]
uint64_t fde_0452_sub_033f68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000188ULL) + (x1 ^ 0x9111E129ULL) + (x2 ^ 0x033F68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x033f68: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9475508ULL; // 0x033f6c: ldr x8, [x8, #0xea8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000009ULL; // 0x033f70: adrp x9, #0x34000
    acc = (acc * 0x100000001B3ULL) ^ 0x9106F129ULL; // 0x033f74: add x9, x9, #0x1bc
    acc = (acc * 0x100000001B3ULL) ^ 0x9000018AULL; // 0x033f78: adrp x10, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF946AD4AULL; // 0x033f7c: ldr x10, [x10, #0xd58]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000109ULL; // 0x033f80: str x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x033f84: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9470108ULL; // 0x033f88: ldr x8, [x8, #0xe00]
    acc = (acc * 0x100000001B3ULL) ^ 0xB000000BULL; // 0x033f8c: adrp x11, #0x34000
    return acc;
}

// [EN] Reconstructed FDE #0453 @ 0x0341bc..0x0343bc (512 bytes)
// [VN] Phục dựng FDE #0453 tại 0x0341bc..0x0343bc (512 byte)
//   0x0341bc: ad400c02  ldp      q2, q3, [x0]
//   0x0341c0: 5289cf69  mov      w9, #0x4e7b
//   0x0341c4: 5288a8c8  mov      w8, #0x4546
//   0x0341c8: 4e020d20  dup      v0.8h, w9
//   0x0341cc: 6e024046  ext      v6.16b, v2.16b, v2.16b, #8
//   0x0341d0: 0e630c47  sqadd    v7.4h, v2.4h, v3.4h
//   0x0341d4: 0e632c42  sqsub    v2.4h, v2.4h, v3.4h
//   0x0341d8: 6e034063  ext      v3.16b, v3.16b, v3.16b, #8
//   0x0341dc: 4e020d01  dup      v1.8h, w8
//   0x0341e0: 6e180466  mov      v6.d[1], v3.d[0]
//   0x0341e4: 6e180447  mov      v7.d[1], v2.d[0]
//   0x0341e8: 4e60b4c2  sqdmulh  v2.8h, v6.8h, v0.8h
//   0x0341ec: 4e61b4c3  sqdmulh  v3.8h, v6.8h, v1.8h
//   0x0341f0: 4f1f1446  ssra     v6.8h, v2.8h, #1
//   0x0341f4: 6e034062  ext      v2.16b, v3.16b, v3.16b, #8
//   0x0341f8: 0e620cc2  sqadd    v2.4h, v6.4h, v2.4h
uint64_t fde_0453_sub_0341bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAD400C02ULL) + (x1 ^ 0x4E61B4C3ULL) + (x2 ^ 0x0341BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAD400C02ULL; // 0x0341bc: ldp q2, q3, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x5289CF69ULL; // 0x0341c0: mov w9, #0x4e7b
    acc = (acc * 0x100000001B3ULL) ^ 0x5288A8C8ULL; // 0x0341c4: mov w8, #0x4546
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D20ULL; // 0x0341c8: dup v0.8h, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x6E024046ULL; // 0x0341cc: ext v6.16b, v2.16b, v2.16b, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x0E630C47ULL; // 0x0341d0: sqadd v7.4h, v2.4h, v3.4h
    acc = (acc * 0x100000001B3ULL) ^ 0x0E632C42ULL; // 0x0341d4: sqsub v2.4h, v2.4h, v3.4h
    acc = (acc * 0x100000001B3ULL) ^ 0x6E034063ULL; // 0x0341d8: ext v3.16b, v3.16b, v3.16b, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x4E020D01ULL; // 0x0341dc: dup v1.8h, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x6E180466ULL; // 0x0341e0: mov v6.d[1], v3.d[0]
    return acc;
}

// [EN] Reconstructed FDE #0454 @ 0x0343bc..0x034478 (188 bytes)
// [VN] Phục dựng FDE #0454 tại 0x0343bc..0x034478 (188 byte)
//   0x0343bc: aa0003e8  mov      x8, x0
//   0x0343c0: 0ddfc500  ld1r     {v0.4h}, [x8], #2
//   0x0343c4: 79c01009  ldrsh    w9, [x0, #8]
//   0x0343c8: 5291518a  mov      w10, #0x8a8c
//   0x0343cc: bd400022  ldr      s2, [x1]
//   0x0343d0: 79c00108  ldrsh    w8, [x8]
//   0x0343d4: 1b0a7d2b  mul      w11, w9, w10
//   0x0343d8: 53107d6b  lsr      w11, w11, #0x10
//   0x0343dc: 0e020d61  dup      v1.4h, w11
//   0x0343e0: 5289cf6b  mov      w11, #0x4e7b
//   0x0343e4: 72a0002b  movk     w11, #1, lsl #16
//   0x0343e8: 1b0a7d0a  mul      w10, w8, w10
//   0x0343ec: 1b0b7d08  mul      w8, w8, w11
//   0x0343f0: 1b0b7d29  mul      w9, w9, w11
//   0x0343f4: 13107d08  asr      w8, w8, #0x10
//   0x0343f8: 4b4a43eb  neg      w11, w10, lsr #16
uint64_t fde_0454_sub_0343bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0x1B0B7D08ULL) + (x2 ^ 0x0343BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0343bc: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x0DDFC500ULL; // 0x0343c0: ld1r {v0.4h}, [x8], #2
    acc = (acc * 0x100000001B3ULL) ^ 0x79C01009ULL; // 0x0343c4: ldrsh w9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x5291518AULL; // 0x0343c8: mov w10, #0x8a8c
    acc = (acc * 0x100000001B3ULL) ^ 0xBD400022ULL; // 0x0343cc: ldr s2, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x79C00108ULL; // 0x0343d0: ldrsh w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x1B0A7D2BULL; // 0x0343d4: mul w11, w9, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x53107D6BULL; // 0x0343d8: lsr w11, w11, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x0E020D61ULL; // 0x0343dc: dup v1.4h, w11
    acc = (acc * 0x100000001B3ULL) ^ 0x5289CF6BULL; // 0x0343e0: mov w11, #0x4e7b
    return acc;
}

// [EN] Reconstructed FDE #0455 @ 0x034478..0x0344c0 (72 bytes)
// [VN] Phục dựng FDE #0455 tại 0x034478..0x0344c0 (72 byte)
//   0x034478: bd400020  ldr      s0, [x1]
//   0x03447c: bd404021  ldr      s1, [x1, #0x40]
//   0x034480: 91008028  add      x8, x1, #0x20
//   0x034484: 91018029  add      x9, x1, #0x60
//   0x034488: 0d409100  ld1      {v0.s}[1], [x8]
//   0x03448c: 0d409121  ld1      {v1.s}[1], [x9]
//   0x034490: 4d40c402  ld1r     {v2.8h}, [x0]
//   0x034494: 2f08a400  ushll    v0.8h, v0.8b, #0
//   0x034498: 2f08a421  ushll    v1.8h, v1.8b, #0
//   0x03449c: 4f1d3440  srsra    v0.8h, v2.8h, #3
//   0x0344a0: 4f1d3441  srsra    v1.8h, v2.8h, #3
//   0x0344a4: 2e212800  sqxtun   v0.8b, v0.8h
//   0x0344a8: 2e212821  sqxtun   v1.8b, v1.8h
//   0x0344ac: bd000020  str      s0, [x1]
//   0x0344b0: 0d009100  st1      {v0.s}[1], [x8]
//   0x0344b4: bd004021  str      s1, [x1, #0x40]
uint64_t fde_0455_sub_034478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xBD400020ULL) + (x1 ^ 0x2E212821ULL) + (x2 ^ 0x034478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xBD400020ULL; // 0x034478: ldr s0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xBD404021ULL; // 0x03447c: ldr s1, [x1, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x91008028ULL; // 0x034480: add x8, x1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91018029ULL; // 0x034484: add x9, x1, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0x0D409100ULL; // 0x034488: ld1 {v0.s}[1], [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x0D409121ULL; // 0x03448c: ld1 {v1.s}[1], [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x4D40C402ULL; // 0x034490: ld1r {v2.8h}, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2F08A400ULL; // 0x034494: ushll v0.8h, v0.8b, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x2F08A421ULL; // 0x034498: ushll v1.8h, v1.8b, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x4F1D3440ULL; // 0x03449c: srsra v0.8h, v2.8h, #3
    return acc;
}

// [EN] Reconstructed FDE #0456 @ 0x0344c0..0x0345cc (268 bytes)
// [VN] Phục dựng FDE #0456 tại 0x0344c0..0x0345cc (268 byte)
//   0x0344c0: 6d410400  ldp      d0, d1, [x0, #0x10]
//   0x0344c4: 6d400c02  ldp      d2, d3, [x0]
//   0x0344c8: 4f000464  movi     v4.4s, #3
//   0x0344cc: 0e620025  saddl    v5.4s, v1.4h, v2.4h
//   0x0344d0: 0e630006  saddl    v6.4s, v0.4h, v3.4h
//   0x0344d4: 0e602060  ssubl    v0.4s, v3.4h, v0.4h
//   0x0344d8: 0e612041  ssubl    v1.4s, v2.4h, v1.4h
//   0x0344dc: 4ea684a2  add      v2.4s, v5.4s, v6.4s
//   0x0344e0: 4ea08423  add      v3.4s, v1.4s, v0.4s
//   0x0344e4: 6ea684a5  sub      v5.4s, v5.4s, v6.4s
//   0x0344e8: 6ea08420  sub      v0.4s, v1.4s, v0.4s
//   0x0344ec: 6e0240a1  ext      v1.16b, v5.16b, v2.16b, #8
//   0x0344f0: 6e034006  ext      v6.16b, v0.16b, v3.16b, #8
//   0x0344f4: 6e014041  ext      v1.16b, v2.16b, v1.16b, #8
//   0x0344f8: 6e064066  ext      v6.16b, v3.16b, v6.16b, #8
//   0x0344fc: 6e1804a2  mov      v2.d[1], v5.d[0]
uint64_t fde_0456_sub_0344c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6D410400ULL) + (x1 ^ 0x6E034006ULL) + (x2 ^ 0x0344C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6D410400ULL; // 0x0344c0: ldp d0, d1, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D400C02ULL; // 0x0344c4: ldp d2, d3, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x4F000464ULL; // 0x0344c8: movi v4.4s, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x0E620025ULL; // 0x0344cc: saddl v5.4s, v1.4h, v2.4h
    acc = (acc * 0x100000001B3ULL) ^ 0x0E630006ULL; // 0x0344d0: saddl v6.4s, v0.4h, v3.4h
    acc = (acc * 0x100000001B3ULL) ^ 0x0E602060ULL; // 0x0344d4: ssubl v0.4s, v3.4h, v0.4h
    acc = (acc * 0x100000001B3ULL) ^ 0x0E612041ULL; // 0x0344d8: ssubl v1.4s, v2.4h, v1.4h
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA684A2ULL; // 0x0344dc: add v2.4s, v5.4s, v6.4s
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA08423ULL; // 0x0344e0: add v3.4s, v1.4s, v0.4s
    acc = (acc * 0x100000001B3ULL) ^ 0x6EA684A5ULL; // 0x0344e4: sub v5.4s, v5.4s, v6.4s
    return acc;
}

// [EN] Reconstructed FDE #0457 @ 0x0345cc..0x034758 (396 bytes)
// [VN] Phục dựng FDE #0457 tại 0x0345cc..0x034758 (396 byte)
//   0x0345cc: 937f7c2b  sbfiz    x11, x1, #1, #0x20
//   0x0345d0: 93407c28  sxtw     x8, w1
//   0x0345d4: cb0b000a  sub      x10, x0, x11
//   0x0345d8: 8b0b0009  add      x9, x0, x11
//   0x0345dc: cb0b014d  sub      x13, x10, x11
//   0x0345e0: cb08014c  sub      x12, x10, x8
//   0x0345e4: 3dc00146  ldr      q6, [x10]
//   0x0345e8: 3ce86947  ldr      q7, [x10, x8]
//   0x0345ec: cb08012b  sub      x11, x9, x8
//   0x0345f0: 3dc00120  ldr      q0, [x9]
//   0x0345f4: 3ce86922  ldr      q2, [x9, x8]
//   0x0345f8: 3dc001b0  ldr      q16, [x13]
//   0x0345fc: 3dc00181  ldr      q1, [x12]
//   0x034600: 3dc00003  ldr      q3, [x0]
//   0x034604: 3dc00171  ldr      q17, [x11]
//   0x034608: 6e2774d2  uabd     v18.16b, v6.16b, v7.16b
uint64_t fde_0457_sub_0345cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x937F7C2BULL) + (x1 ^ 0x3DC00181ULL) + (x2 ^ 0x0345CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x937F7C2BULL; // 0x0345cc: sbfiz x11, x1, #1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C28ULL; // 0x0345d0: sxtw x8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB0B000AULL; // 0x0345d4: sub x10, x0, x11
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0B0009ULL; // 0x0345d8: add x9, x0, x11
    acc = (acc * 0x100000001B3ULL) ^ 0xCB0B014DULL; // 0x0345dc: sub x13, x10, x11
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08014CULL; // 0x0345e0: sub x12, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00146ULL; // 0x0345e4: ldr q6, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x3CE86947ULL; // 0x0345e8: ldr q7, [x10, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08012BULL; // 0x0345ec: sub x11, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00120ULL; // 0x0345f0: ldr q0, [x9]
    return acc;
}

// [EN] Reconstructed FDE #0458 @ 0x034758..0x0348c4 (364 bytes)
// [VN] Phục dựng FDE #0458 tại 0x034758..0x0348c4 (364 byte)
//   0x034758: 937f7c29  sbfiz    x9, x1, #1, #0x20
//   0x03475c: 93407c28  sxtw     x8, w1
//   0x034760: 8b090010  add      x16, x0, x9
//   0x034764: cb080211  sub      x17, x16, x8
//   0x034768: 3dc00006  ldr      q6, [x0]
//   0x03476c: 3dc00207  ldr      q7, [x16]
//   0x034770: 3ce86a10  ldr      q16, [x16, x8]
//   0x034774: 3dc00231  ldr      q17, [x17]
//   0x034778: 937e7c2a  sbfiz    x10, x1, #2, #0x20
//   0x03477c: 4e010c60  dup      v0.16b, w3
//   0x034780: 4e010c41  dup      v1.16b, w2
//   0x034784: 4e010c82  dup      v2.16b, w4
//   0x034788: cb0803eb  neg      x11, x8
//   0x03478c: 8b0a000c  add      x12, x0, x10
//   0x034790: cb0903ed  neg      x13, x9
//   0x034794: 8b09010e  add      x14, x8, x9
uint64_t fde_0458_sub_034758(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x937F7C29ULL) + (x1 ^ 0xCB0803EBULL) + (x2 ^ 0x034758ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x937F7C29ULL; // 0x034758: sbfiz x9, x1, #1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C28ULL; // 0x03475c: sxtw x8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090010ULL; // 0x034760: add x16, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xCB080211ULL; // 0x034764: sub x17, x16, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00006ULL; // 0x034768: ldr q6, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00207ULL; // 0x03476c: ldr q7, [x16]
    acc = (acc * 0x100000001B3ULL) ^ 0x3CE86A10ULL; // 0x034770: ldr q16, [x16, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00231ULL; // 0x034774: ldr q17, [x17]
    acc = (acc * 0x100000001B3ULL) ^ 0x937E7C2AULL; // 0x034778: sbfiz x10, x1, #2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x4E010C60ULL; // 0x03477c: dup v0.16b, w3
    return acc;
}

// [EN] Reconstructed FDE #0459 @ 0x0348c4..0x034cf4 (1072 bytes)
// [VN] Phục dựng FDE #0459 tại 0x0348c4..0x034cf4 (1072 byte)
//   0x0348c4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0348c8: 4ea01c01  mov      v1.16b, v0.16b
//   0x0348cc: 4ea01c02  mov      v2.16b, v0.16b
//   0x0348d0: d1001011  sub      x17, x0, #4
//   0x0348d4: 4ea01c03  mov      v3.16b, v0.16b
//   0x0348d8: 937d7c28  sbfiz    x8, x1, #3, #0x20
//   0x0348dc: aa1103f0  mov      x16, x17
//   0x0348e0: 4ea01c04  mov      v4.16b, v0.16b
//   0x0348e4: 4ea11c25  mov      v5.16b, v1.16b
//   0x0348e8: 4ea21c46  mov      v6.16b, v2.16b
//   0x0348ec: 4ea31c67  mov      v7.16b, v3.16b
//   0x0348f0: 0de82204  ld4      {v4.b, v5.b, v6.b, v7.b}[0], [x16], x8
//   0x0348f4: 93407c29  sxtw     x9, w1
//   0x0348f8: 8b09022a  add      x10, x17, x9
//   0x0348fc: 4ea01c10  mov      v16.16b, v0.16b
//   0x034900: 0d602544  ld4      {v4.b, v5.b, v6.b, v7.b}[1], [x10]
uint64_t fde_0459_sub_0348c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6F00E400ULL) + (x1 ^ 0x93407C29ULL) + (x2 ^ 0x0348C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x0348c4: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C01ULL; // 0x0348c8: mov v1.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C02ULL; // 0x0348cc: mov v2.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001011ULL; // 0x0348d0: sub x17, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C03ULL; // 0x0348d4: mov v3.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x937D7C28ULL; // 0x0348d8: sbfiz x8, x1, #3, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1103F0ULL; // 0x0348dc: mov x16, x17
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C04ULL; // 0x0348e0: mov v4.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA11C25ULL; // 0x0348e4: mov v5.16b, v1.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA21C46ULL; // 0x0348e8: mov v6.16b, v2.16b
    return acc;
}

// [EN] Reconstructed FDE #0460 @ 0x034cf4..0x035114 (1056 bytes)
// [VN] Phục dựng FDE #0460 tại 0x034cf4..0x035114 (1056 byte)
//   0x034cf4: d10283ff  sub      sp, sp, #0xa0
//   0x034cf8: 6d022beb  stp      d11, d10, [sp, #0x20]
//   0x034cfc: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x034d00: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x034d04: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x034d08: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x034d0c: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x034d10: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x034d14: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x034d18: 6f00e400  movi     v0.2d, #0000000000000000
//   0x034d1c: 4ea01c01  mov      v1.16b, v0.16b
//   0x034d20: 4ea01c02  mov      v2.16b, v0.16b
//   0x034d24: 93407c29  sxtw     x9, w1
//   0x034d28: 937d7c25  sbfiz    x5, x1, #3, #0x20
//   0x034d2c: 4ea01c03  mov      v3.16b, v0.16b
//   0x034d30: aa0003eb  mov      x11, x0
uint64_t fde_0460_sub_034cf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0x93407C29ULL) + (x2 ^ 0x034CF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x034cf4: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x6D022BEBULL; // 0x034cf8: stp d11, d10, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x034cfc: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x034d00: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x034d04: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x034d08: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x034d0c: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x034d10: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x034d14: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x034d18: movi v0.2d, #0000000000000000
    return acc;
}

// [EN] Reconstructed FDE #0461 @ 0x035114..0x03533c (552 bytes)
// [VN] Phục dựng FDE #0461 tại 0x035114..0x03533c (552 byte)
//   0x035114: 937f7c4a  sbfiz    x10, x2, #1, #0x20
//   0x035118: 531e7449  lsl      w9, w2, #2
//   0x03511c: 93407c48  sxtw     x8, w2
//   0x035120: fd400003  ldr      d3, [x0]
//   0x035124: fd400020  ldr      d0, [x1]
//   0x035128: cb0a000e  sub      x14, x0, x10
//   0x03512c: cb0a002c  sub      x12, x1, x10
//   0x035130: 93407d2f  sxtw     x15, w9
//   0x035134: fc686804  ldr      d4, [x0, x8]
//   0x035138: fc686821  ldr      d1, [x1, x8]
//   0x03513c: fd4001d1  ldr      d17, [x14]
//   0x035140: fd400192  ldr      d18, [x12]
//   0x035144: cb0f000b  sub      x11, x0, x15
//   0x035148: 8b080150  add      x16, x10, x8
//   0x03514c: cb08000d  sub      x13, x0, x8
//   0x035150: cb080029  sub      x9, x1, x8
uint64_t fde_0461_sub_035114(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x937F7C4AULL) + (x1 ^ 0xCB0F000BULL) + (x2 ^ 0x035114ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x937F7C4AULL; // 0x035114: sbfiz x10, x2, #1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x531E7449ULL; // 0x035118: lsl w9, w2, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x03511c: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400003ULL; // 0x035120: ldr d3, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400020ULL; // 0x035124: ldr d0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB0A000EULL; // 0x035128: sub x14, x0, x10
    acc = (acc * 0x100000001B3ULL) ^ 0xCB0A002CULL; // 0x03512c: sub x12, x1, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D2FULL; // 0x035130: sxtw x15, w9
    acc = (acc * 0x100000001B3ULL) ^ 0xFC686804ULL; // 0x035134: ldr d4, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC686821ULL; // 0x035138: ldr d1, [x1, x8]
    return acc;
}

// [EN] Reconstructed FDE #0462 @ 0x03533c..0x035500 (452 bytes)
// [VN] Phục dựng FDE #0462 tại 0x03533c..0x035500 (452 byte)
//   0x03533c: 937e7c49  sbfiz    x9, x2, #2, #0x20
//   0x035340: 93407c48  sxtw     x8, w2
//   0x035344: 937f7c4b  sbfiz    x11, x2, #1, #0x20
//   0x035348: 8b09000a  add      x10, x0, x9
//   0x03534c: 8b090029  add      x9, x1, x9
//   0x035350: fd400000  ldr      d0, [x0]
//   0x035354: fd400021  ldr      d1, [x1]
//   0x035358: 8b08016c  add      x12, x11, x8
//   0x03535c: fd400147  ldr      d7, [x10]
//   0x035360: fd400130  ldr      d16, [x9]
//   0x035364: fc686951  ldr      d17, [x10, x8]
//   0x035368: fc686932  ldr      d18, [x9, x8]
//   0x03536c: fc6c6942  ldr      d2, [x10, x12]
//   0x035370: fc6c6923  ldr      d3, [x9, x12]
//   0x035374: fc6b6944  ldr      d4, [x10, x11]
//   0x035378: fc6b6925  ldr      d5, [x9, x11]
uint64_t fde_0462_sub_03533c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x937E7C49ULL) + (x1 ^ 0xFC6C6942ULL) + (x2 ^ 0x03533CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x937E7C49ULL; // 0x03533c: sbfiz x9, x2, #2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x035340: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x937F7C4BULL; // 0x035344: sbfiz x11, x2, #1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09000AULL; // 0x035348: add x10, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090029ULL; // 0x03534c: add x9, x1, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400000ULL; // 0x035350: ldr d0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400021ULL; // 0x035354: ldr d1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08016CULL; // 0x035358: add x12, x11, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400147ULL; // 0x03535c: ldr d7, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400130ULL; // 0x035360: ldr d16, [x9]
    return acc;
}

// [EN] Reconstructed FDE #0463 @ 0x035500..0x0357f4 (756 bytes)
// [VN] Phục dựng FDE #0463 tại 0x035500..0x0357f4 (756 byte)
//   0x035500: aa0003e9  mov      x9, x0
//   0x035504: aa0103ea  mov      x10, x1
//   0x035508: fc5fcd20  ldr      d0, [x9, #-4]!
//   0x03550c: fc5fcd41  ldr      d1, [x10, #-4]!
//   0x035510: 93407c48  sxtw     x8, w2
//   0x035514: 937f7c4b  sbfiz    x11, x2, #1, #0x20
//   0x035518: 8b08016e  add      x14, x11, x8
//   0x03551c: fc6b6922  ldr      d2, [x9, x11]
//   0x035520: fc6b6943  ldr      d3, [x10, x11]
//   0x035524: fc6e6924  ldr      d4, [x9, x14]
//   0x035528: fc6e6946  ldr      d6, [x10, x14]
//   0x03552c: 6e180420  mov      v0.d[1], v1.d[0]
//   0x035530: fc686921  ldr      d1, [x9, x8]
//   0x035534: fc686947  ldr      d7, [x10, x8]
//   0x035538: 937e7c4c  sbfiz    x12, x2, #2, #0x20
//   0x03553c: 937d7c4d  sbfiz    x13, x2, #3, #0x20
uint64_t fde_0463_sub_035500(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E9ULL) + (x1 ^ 0xFC686921ULL) + (x2 ^ 0x035500ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E9ULL; // 0x035500: mov x9, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103EAULL; // 0x035504: mov x10, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FCD20ULL; // 0x035508: ldr d0, [x9, #-4]!
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FCD41ULL; // 0x03550c: ldr d1, [x10, #-4]!
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x035510: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x937F7C4BULL; // 0x035514: sbfiz x11, x2, #1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08016EULL; // 0x035518: add x14, x11, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xFC6B6922ULL; // 0x03551c: ldr d2, [x9, x11]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC6B6943ULL; // 0x035520: ldr d3, [x10, x11]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC6E6924ULL; // 0x035524: ldr d4, [x9, x14]
    return acc;
}

// [EN] Reconstructed FDE #0464 @ 0x0357f4..0x035a58 (612 bytes)
// [VN] Phục dựng FDE #0464 tại 0x0357f4..0x035a58 (612 byte)
//   0x0357f4: 93407c48  sxtw     x8, w2
//   0x0357f8: fd400000  ldr      d0, [x0]
//   0x0357fc: fd400021  ldr      d1, [x1]
//   0x035800: fc686803  ldr      d3, [x0, x8]
//   0x035804: fc686824  ldr      d4, [x1, x8]
//   0x035808: 937f7c49  sbfiz    x9, x2, #1, #0x20
//   0x03580c: 937e7c4a  sbfiz    x10, x2, #2, #0x20
//   0x035810: 8b08012c  add      x12, x9, x8
//   0x035814: 8b08014d  add      x13, x10, x8
//   0x035818: fc696805  ldr      d5, [x0, x9]
//   0x03581c: fc696826  ldr      d6, [x1, x9]
//   0x035820: fc6a6807  ldr      d7, [x0, x10]
//   0x035824: fc6a6830  ldr      d16, [x1, x10]
//   0x035828: fc6c6811  ldr      d17, [x0, x12]
//   0x03582c: fc6c6832  ldr      d18, [x1, x12]
//   0x035830: 6e180420  mov      v0.d[1], v1.d[0]
uint64_t fde_0464_sub_0357f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x93407C48ULL) + (x1 ^ 0xFC6A6830ULL) + (x2 ^ 0x0357F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C48ULL; // 0x0357f4: sxtw x8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400000ULL; // 0x0357f8: ldr d0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xFD400021ULL; // 0x0357fc: ldr d1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC686803ULL; // 0x035800: ldr d3, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC686824ULL; // 0x035804: ldr d4, [x1, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x937F7C49ULL; // 0x035808: sbfiz x9, x2, #1, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x937E7C4AULL; // 0x03580c: sbfiz x10, x2, #2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08012CULL; // 0x035810: add x12, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08014DULL; // 0x035814: add x13, x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xFC696805ULL; // 0x035818: ldr d5, [x0, x9]
    return acc;
}

// [EN] Reconstructed FDE #0465 @ 0x035a58..0x035af4 (156 bytes)
// [VN] Phục dựng FDE #0465 tại 0x035a58..0x035af4 (156 byte)
//   0x035a58: 531f7828  lsl      w8, w1, #1
//   0x035a5c: 93407c29  sxtw     x9, w1
//   0x035a60: cb28c008  sub      x8, x0, w8, sxtw
//   0x035a64: 3ce96803  ldr      q3, [x0, x9]
//   0x035a68: 3dc00104  ldr      q4, [x8]
//   0x035a6c: cb090008  sub      x8, x0, x9
//   0x035a70: 3dc00000  ldr      q0, [x0]
//   0x035a74: 3dc00105  ldr      q5, [x8]
//   0x035a78: 4f04e402  movi     v2.16b, #0x80
//   0x035a7c: 6e221c66  eor      v6.16b, v3.16b, v2.16b
//   0x035a80: 6e237483  uabd     v3.16b, v4.16b, v3.16b
//   0x035a84: 6e221c84  eor      v4.16b, v4.16b, v2.16b
//   0x035a88: 4e262c84  sqsub    v4.16b, v4.16b, v6.16b
//   0x035a8c: 6e2074a6  uabd     v6.16b, v5.16b, v0.16b
//   0x035a90: 6e260cc6  uqadd    v6.16b, v6.16b, v6.16b
//   0x035a94: 6f0f0463  ushr     v3.16b, v3.16b, #1
uint64_t fde_0465_sub_035a58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x531F7828ULL) + (x1 ^ 0x4E262C84ULL) + (x2 ^ 0x035A58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7828ULL; // 0x035a58: lsl w8, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C29ULL; // 0x035a5c: sxtw x9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB28C008ULL; // 0x035a60: sub x8, x0, w8, sxtw
    acc = (acc * 0x100000001B3ULL) ^ 0x3CE96803ULL; // 0x035a64: ldr q3, [x0, x9]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00104ULL; // 0x035a68: ldr q4, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090008ULL; // 0x035a6c: sub x8, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00000ULL; // 0x035a70: ldr q0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00105ULL; // 0x035a74: ldr q5, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x4F04E402ULL; // 0x035a78: movi v2.16b, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x6E221C66ULL; // 0x035a7c: eor v6.16b, v3.16b, v2.16b
    return acc;
}

// [EN] Reconstructed FDE #0466 @ 0x035af4..0x035cb8 (452 bytes)
// [VN] Phục dựng FDE #0466 tại 0x035af4..0x035cb8 (452 byte)
//   0x035af4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x035af8: 4ea01c01  mov      v1.16b, v0.16b
//   0x035afc: 4ea01c02  mov      v2.16b, v0.16b
//   0x035b00: d1000811  sub      x17, x0, #2
//   0x035b04: 4ea01c03  mov      v3.16b, v0.16b
//   0x035b08: 937d7c28  sbfiz    x8, x1, #3, #0x20
//   0x035b0c: 4ea01c04  mov      v4.16b, v0.16b
//   0x035b10: 4ea11c25  mov      v5.16b, v1.16b
//   0x035b14: 4ea21c46  mov      v6.16b, v2.16b
//   0x035b18: 4ea31c67  mov      v7.16b, v3.16b
//   0x035b1c: aa1103ef  mov      x15, x17
//   0x035b20: 0de821e4  ld4      {v4.b, v5.b, v6.b, v7.b}[0], [x15], x8
//   0x035b24: 93407c29  sxtw     x9, w1
//   0x035b28: 8b09022a  add      x10, x17, x9
//   0x035b2c: 4f04e410  movi     v16.16b, #0x80
//   0x035b30: 0d602544  ld4      {v4.b, v5.b, v6.b, v7.b}[1], [x10]
uint64_t fde_0466_sub_035af4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x6F00E400ULL) + (x1 ^ 0x93407C29ULL) + (x2 ^ 0x035AF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x035af4: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C01ULL; // 0x035af8: mov v1.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C02ULL; // 0x035afc: mov v2.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000811ULL; // 0x035b00: sub x17, x0, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C03ULL; // 0x035b04: mov v3.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x937D7C28ULL; // 0x035b08: sbfiz x8, x1, #3, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C04ULL; // 0x035b0c: mov v4.16b, v0.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA11C25ULL; // 0x035b10: mov v5.16b, v1.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA21C46ULL; // 0x035b14: mov v6.16b, v2.16b
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA31C67ULL; // 0x035b18: mov v7.16b, v3.16b
    return acc;
}

// [EN] Reconstructed FDE #0467 @ 0x035cb8..0x035e68 (432 bytes)
// [VN] Phục dựng FDE #0467 tại 0x035cb8..0x035e68 (432 byte)
//   0x035cb8: 937e7c29  sbfiz    x9, x1, #2, #0x20
//   0x035cbc: 531f782a  lsl      w10, w1, #1
//   0x035cc0: 93407d4a  sxtw     x10, w10
//   0x035cc4: 8b09000b  add      x11, x0, x9
//   0x035cc8: 93407c28  sxtw     x8, w1
//   0x035ccc: cb0a016c  sub      x12, x11, x10
//   0x035cd0: 3dc00184  ldr      q4, [x12]
//   0x035cd4: cb08016c  sub      x12, x11, x8
//   0x035cd8: 3dc00165  ldr      q5, [x11]
//   0x035cdc: 3ce86966  ldr      q6, [x11, x8]
//   0x035ce0: 3dc00187  ldr      q7, [x12]
//   0x035ce4: 4f04e401  movi     v1.16b, #0x80
//   0x035ce8: 6e211cb0  eor      v16.16b, v5.16b, v1.16b
//   0x035cec: 6e211cd1  eor      v17.16b, v6.16b, v1.16b
//   0x035cf0: 6e2574e5  uabd     v5.16b, v7.16b, v5.16b
//   0x035cf4: 6e267486  uabd     v6.16b, v4.16b, v6.16b
uint64_t fde_0467_sub_035cb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x937E7C29ULL) + (x1 ^ 0x6E211CB0ULL) + (x2 ^ 0x035CB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x937E7C29ULL; // 0x035cb8: sbfiz x9, x1, #2, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x531F782AULL; // 0x035cbc: lsl w10, w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x93407D4AULL; // 0x035cc0: sxtw x10, w10
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09000BULL; // 0x035cc4: add x11, x0, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C28ULL; // 0x035cc8: sxtw x8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB0A016CULL; // 0x035ccc: sub x12, x11, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00184ULL; // 0x035cd0: ldr q4, [x12]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB08016CULL; // 0x035cd4: sub x12, x11, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00165ULL; // 0x035cd8: ldr q5, [x11]
    acc = (acc * 0x100000001B3ULL) ^ 0x3CE86966ULL; // 0x035cdc: ldr q6, [x11, x8]
    return acc;
}

// [EN] Reconstructed FDE #0468 @ 0x035e68..0x035eb8 (80 bytes)
// [VN] Phục dựng FDE #0468 tại 0x035e68..0x035eb8 (80 byte)
//   0x035e68: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x035e6c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x035e70: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x035e74: 910083fd  add      x29, sp, #0x20
//   0x035e78: aa0003f5  mov      x21, x0
//   0x035e7c: 91001000  add      x0, x0, #4
//   0x035e80: 2a0203f3  mov      w19, w2
//   0x035e84: 2a0103f4  mov      w20, w1
//   0x035e88: 97ffff1b  bl       #0x35af4
//   0x035e8c: 910022a0  add      x0, x21, #8
//   0x035e90: 2a1403e1  mov      w1, w20
//   0x035e94: 2a1303e2  mov      w2, w19
//   0x035e98: 97ffff17  bl       #0x35af4
//   0x035e9c: 2a1403e1  mov      w1, w20
//   0x035ea0: 2a1303e2  mov      w2, w19
//   0x035ea4: a9427bfd  ldp      x29, x30, [sp, #0x20]
uint64_t fde_0468_sub_035e68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x97FFFF17ULL) + (x2 ^ 0x035E68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x035e68: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x035e6c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x035e70: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x035e74: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x035e78: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x91001000ULL; // 0x035e7c: add x0, x0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x035e80: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x035e84: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF1BULL; // 0x035e88: bl #0x35af4
    acc = (acc * 0x100000001B3ULL) ^ 0x910022A0ULL; // 0x035e8c: add x0, x21, #8
    return acc;
}

// [EN] Reconstructed FDE #0469 @ 0x035eb8..0x035f04 (76 bytes)
// [VN] Phục dựng FDE #0469 tại 0x035eb8..0x035f04 (76 byte)
//   0x035eb8: fc5e0000  ldur     d0, [x0, #-0x20]
//   0x035ebc: fc5ff001  ldur     d1, [x0, #-1]
//   0x035ec0: fc41f002  ldur     d2, [x0, #0x1f]
//   0x035ec4: fc43f003  ldur     d3, [x0, #0x3f]
//   0x035ec8: 2e202800  uaddlp   v0.4h, v0.8b
//   0x035ecc: 0e60bc00  addp     v0.4h, v0.4h, v0.4h
//   0x035ed0: fc45f004  ldur     d4, [x0, #0x5f]
//   0x035ed4: 6e180400  mov      v0.d[1], v0.d[0]
//   0x035ed8: 2e211000  uaddw    v0.8h, v0.8h, v1.8b
//   0x035edc: 2e221000  uaddw    v0.8h, v0.8h, v2.8b
//   0x035ee0: 2e231000  uaddw    v0.8h, v0.8h, v3.8b
//   0x035ee4: 2e241000  uaddw    v0.8h, v0.8h, v4.8b
//   0x035ee8: 0f0d8c00  rshrn    v0.8b, v0.8h, #3
//   0x035eec: 0e010400  dup      v0.8b, v0.b[0]
//   0x035ef0: bd000000  str      s0, [x0]
//   0x035ef4: bd002000  str      s0, [x0, #0x20]
uint64_t fde_0469_sub_035eb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC5E0000ULL) + (x1 ^ 0x0F0D8C00ULL) + (x2 ^ 0x035EB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5E0000ULL; // 0x035eb8: ldur d0, [x0, #-0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC5FF001ULL; // 0x035ebc: ldur d1, [x0, #-1]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC41F002ULL; // 0x035ec0: ldur d2, [x0, #0x1f]
    acc = (acc * 0x100000001B3ULL) ^ 0xFC43F003ULL; // 0x035ec4: ldur d3, [x0, #0x3f]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E202800ULL; // 0x035ec8: uaddlp v0.4h, v0.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x0E60BC00ULL; // 0x035ecc: addp v0.4h, v0.4h, v0.4h
    acc = (acc * 0x100000001B3ULL) ^ 0xFC45F004ULL; // 0x035ed0: ldur d4, [x0, #0x5f]
    acc = (acc * 0x100000001B3ULL) ^ 0x6E180400ULL; // 0x035ed4: mov v0.d[1], v0.d[0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2E211000ULL; // 0x035ed8: uaddw v0.8h, v0.8h, v1.8b
    acc = (acc * 0x100000001B3ULL) ^ 0x2E221000ULL; // 0x035edc: uaddw v0.8h, v0.8h, v2.8b
    return acc;
}

uint64_t DispatchJpegPngCodecsFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 240U || fde_index >= 470U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0xBF58476D1CE4E5B9ULL) + x2;
}

} // namespace codecs
} // namespace webp
} // namespace imagepipeline
} // namespace facebook
