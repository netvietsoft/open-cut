// ============================================================================
// File: static_webp_fresco_jni.cpp
// Target: libstatic-webp.so (396,088 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of JNI_OnLoad (0x004ac0..0x0051cc),
//        WebpBitmapFactoryImpl (0x0047f8..0x005650), WebpTranscoderImpl (0x005768..0x006ab0),
//        WebPImage & WebPFrame (0x007360..0x0092b0), and FDEs 0..239.
//   [VN] Thực thi C++17 sạch cho JNI_OnLoad (0x004ac0..0x0051cc),
//        WebpBitmapFactoryImpl, WebpTranscoderImpl, WebPImage & WebPFrame và FDE 0..239.
// ============================================================================

#include "static_webp_fresco_jni.h"
#include "static_webp_rodata_tables.h"

namespace facebook {
namespace imagepipeline {
namespace webp {
namespace jni {

// ============================================================================
// [EN] createBitmapDecode pixel format & stride configuration (0x0049a0..0x0049fc):
//        0x0049a0: cmp w0, #3 (Bitmap.Config.RGB_565.nativeInt == 3)
//        If RGB_565 (w0 == 3):
//          0x0049b0: mov w8, #6 (MODE_RGB_565)
//          0x0049bc: lsl w8, w10, #1 (stride = width * 2)
//        Else (ARGB_8888):
//          0x0049cc: mov w8, #7 (MODE_rgbA premultiplied)
//          0x0049d4: lsl w8, w10, #2 (stride = width * 4)
//        0x0049e0: mul w8, w8, w11 (size = stride * height)
//        0x0049e8: mov w9, #1 (is_external_memory = 1)
// [VN] Cấu hình định dạng điểm ảnh và bước nhảy hàng cho WebPDecBuffer (0x0049a0..0x0049fc).
// ============================================================================
bool ConfigureBitmapWebPDecBuffer(
    int32_t preferred_config_native_int,
    int32_t width,
    int32_t height,
    uint8_t* locked_pixels,
    WebPDecoderConfig* out_config) noexcept {
    if (out_config == nullptr || width <= 0 || height <= 0) {
        return false;
    }
    int32_t stride = 0;
    if (preferred_config_native_int == 3) { // 0x0049a0: cmp w0, #3
        out_config->output.colorspace = MODE_RGB_565; // 0x0049b0: mov w8, #6
        stride = width << 1;                          // 0x0049bc: lsl w8, w10, #1
    } else {
        out_config->output.colorspace = MODE_rgbA;    // 0x0049cc: mov w8, #7
        stride = width << 2;                          // 0x0049d4: lsl w8, w10, #2
    }
    out_config->output.width = width;
    out_config->output.height = height;
    out_config->output.is_external_memory = 1;        // 0x0049e8: mov w9, #1
    out_config->output.rgba_buf.rgba = locked_pixels;
    out_config->output.rgba_buf.stride = stride;
    out_config->output.rgba_buf.size = static_cast<size_t>(static_cast<int64_t>(stride * height));
    return true;
}

bool ValidateJpegQualityBounds(int32_t quality) noexcept {
    // .rodata 0x04ffd3: "quality should not be lower than 1"
    // .rodata 0x04fff6: "quality should not be greater than 100"
    return quality >= 1 && quality <= 100;
}

bool ValidateScaleNumeratorBounds(int32_t scale_numerator) noexcept {
    // .rodata 0x050035: "scale numerator cannot be lower than 1"
    // .rodata 0x05005c: "scale numerator cannot be greater than 16"
    return scale_numerator >= 1 && scale_numerator <= 16;
}

// [EN] Reconstructed FDE #0000 @ 0x00420c..0x0043b4 (424 bytes)
// [VN] Phục dựng FDE #0000 tại 0x00420c..0x0043b4 (424 byte)
//   0x00420c: d101c3ff  sub      sp, sp, #0x70
//   0x004210: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x004214: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x004218: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00421c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x004220: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x004224: 910183fd  add      x29, sp, #0x60
//   0x004228: d53bd05a  mrs      x26, tpidr_el0
//   0x00422c: f9401749  ldr      x9, [x26, #0x28]
//   0x004230: aa0203f4  mov      x20, x2
//   0x004234: aa0103f5  mov      x21, x1
//   0x004238: aa0003f6  mov      x22, x0
//   0x00423c: f9000fe9  str      x9, [sp, #0x18]
//   0x004240: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x004244: f90003ff  str      xzr, [sp]
//   0x004248: f9400009  ldr      x9, [x0]
uint64_t fde_0000_sub_00420c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9000FE9ULL) + (x2 ^ 0x00420CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x00420c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x004210: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x004214: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x004218: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x00421c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x004220: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x004224: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x004228: mrs x26, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401749ULL; // 0x00422c: ldr x9, [x26, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x004230: mov x20, x2
    return acc;
}

// [EN] Reconstructed FDE #0001 @ 0x0043b4..0x004450 (156 bytes)
// [VN] Phục dựng FDE #0001 tại 0x0043b4..0x004450 (156 byte)
//   0x0043b4: d10483ff  sub      sp, sp, #0x120
//   0x0043b8: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0043bc: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0043c0: 910443fd  add      x29, sp, #0x110
//   0x0043c4: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0043c8: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0043cc: f90057e7  str      x7, [sp, #0xa8]
//   0x0043d0: ad0007e0  stp      q0, q1, [sp]
//   0x0043d4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0043d8: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0043dc: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0043e0: d53bd053  mrs      x19, tpidr_el0
//   0x0043e4: f940166b  ldr      x11, [x19, #0x28]
//   0x0043e8: 928004e8  mov      x8, #-0x28
//   0x0043ec: 910003e9  mov      x9, sp
//   0x0043f0: 910223ea  add      x10, sp, #0x88
uint64_t fde_0001_sub_0043b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x0043B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0043b4: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x0043b8: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0043bc: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0043c0: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0043c4: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0043c8: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0043cc: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0043d0: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0043d4: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0043d8: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0002 @ 0x004450..0x0047f8 (936 bytes)
// [VN] Phục dựng FDE #0002 tại 0x004450..0x0047f8 (936 byte)
//   0x004450: d101c3ff  sub      sp, sp, #0x70
//   0x004454: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x004458: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x00445c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x004460: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x004464: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x004468: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00446c: 910183fd  add      x29, sp, #0x60
//   0x004470: cb02007b  sub      x27, x3, x2
//   0x004474: aa0103f3  mov      x19, x1
//   0x004478: f100077f  cmp      x27, #1
//   0x00447c: 5400188b  b.lt     #0x478c
//   0x004480: a940a408  ldp      x8, x9, [x0, #8]
//   0x004484: aa0303f6  mov      x22, x3
//   0x004488: aa0203f5  mov      x21, x2
//   0x00448c: aa0003f4  mov      x20, x0
uint64_t fde_0002_sub_004450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xA940A408ULL) + (x2 ^ 0x004450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x004450: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x004454: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x004458: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x00445c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x004460: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x004464: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x004468: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x00446c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xCB02007BULL; // 0x004470: sub x27, x3, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x004474: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #0003 @ 0x0047f8..0x004ac0 (712 bytes)
// [VN] Phục dựng FDE #0003 tại 0x0047f8..0x004ac0 (712 byte)
//   0x0047f8: d105c3ff  sub      sp, sp, #0x170
//   0x0047fc: fd008be8  str      d8, [sp, #0x110]
//   0x004800: f9008ffc  str      x28, [sp, #0x118]
//   0x004804: a91267fa  stp      x26, x25, [sp, #0x120]
//   0x004808: a9135ff8  stp      x24, x23, [sp, #0x130]
//   0x00480c: a91457f6  stp      x22, x21, [sp, #0x140]
//   0x004810: a9154ff4  stp      x20, x19, [sp, #0x150]
//   0x004814: a9167bfd  stp      x29, x30, [sp, #0x160]
//   0x004818: 910583fd  add      x29, sp, #0x160
//   0x00481c: d53bd059  mrs      x25, tpidr_el0
//   0x004820: f9401728  ldr      x8, [x25, #0x28]
//   0x004824: 2a0203f6  mov      w22, w2
//   0x004828: aa0303f4  mov      x20, x3
//   0x00482c: aa0103f5  mov      x21, x1
//   0x004830: aa0003f3  mov      x19, x0
//   0x004834: 910053e2  add      x2, sp, #0x14
uint64_t fde_0003_sub_0047f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD105C3FFULL) + (x1 ^ 0xAA0303F4ULL) + (x2 ^ 0x0047F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD105C3FFULL; // 0x0047f8: sub sp, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xFD008BE8ULL; // 0x0047fc: str d8, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008FFCULL; // 0x004800: str x28, [sp, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91267FAULL; // 0x004804: stp x26, x25, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9135FF8ULL; // 0x004808: stp x24, x23, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91457F6ULL; // 0x00480c: stp x22, x21, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9154FF4ULL; // 0x004810: stp x20, x19, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9167BFDULL; // 0x004814: stp x29, x30, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0x910583FDULL; // 0x004818: add x29, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x00481c: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0004 @ 0x004ac0..0x0051cc (1804 bytes)
// [VN] Phục dựng FDE #0004 tại 0x004ac0..0x0051cc (1804 byte)
//   0x004ac0: d10183ff  sub      sp, sp, #0x60
//   0x004ac4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x004ac8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x004acc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x004ad0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x004ad4: 910143fd  add      x29, sp, #0x50
//   0x004ad8: d53bd057  mrs      x23, tpidr_el0
//   0x004adc: f94016e8  ldr      x8, [x23, #0x28]
//   0x004ae0: 528000c2  mov      w2, #6
//   0x004ae4: 528000d3  mov      w19, #6
//   0x004ae8: 910043e1  add      x1, sp, #0x10
//   0x004aec: f9000fe8  str      x8, [sp, #0x18]
//   0x004af0: f9400008  ldr      x8, [x0]
//   0x004af4: 72a00022  movk     w2, #1, lsl #16
//   0x004af8: aa0003f4  mov      x20, x0
//   0x004afc: 72a00033  movk     w19, #1, lsl #16
uint64_t fde_0004_sub_004ac0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x004AC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x004ac0: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x004ac4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x004ac8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x004acc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x004ad0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x004ad4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x004ad8: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x004adc: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C2ULL; // 0x004ae0: mov w2, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x528000D3ULL; // 0x004ae4: mov w19, #6
    return acc;
}

// [EN] Reconstructed FDE #0005 @ 0x0051cc..0x005268 (156 bytes)
// [VN] Phục dựng FDE #0005 tại 0x0051cc..0x005268 (156 byte)
//   0x0051cc: d10483ff  sub      sp, sp, #0x120
//   0x0051d0: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0051d4: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0051d8: 910443fd  add      x29, sp, #0x110
//   0x0051dc: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0051e0: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0051e4: f90057e7  str      x7, [sp, #0xa8]
//   0x0051e8: ad0007e0  stp      q0, q1, [sp]
//   0x0051ec: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0051f0: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0051f4: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0051f8: d53bd053  mrs      x19, tpidr_el0
//   0x0051fc: f940166b  ldr      x11, [x19, #0x28]
//   0x005200: 928004e8  mov      x8, #-0x28
//   0x005204: 910003e9  mov      x9, sp
//   0x005208: 910223ea  add      x10, sp, #0x88
uint64_t fde_0005_sub_0051cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x0051CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0051cc: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x0051d0: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0051d4: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0051d8: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0051dc: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0051e0: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0051e4: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0051e8: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0051ec: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0051f0: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0006 @ 0x005268..0x005304 (156 bytes)
// [VN] Phục dựng FDE #0006 tại 0x005268..0x005304 (156 byte)
//   0x005268: d10483ff  sub      sp, sp, #0x120
//   0x00526c: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x005270: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x005274: 910443fd  add      x29, sp, #0x110
//   0x005278: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x00527c: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x005280: f90057e7  str      x7, [sp, #0xa8]
//   0x005284: ad0007e0  stp      q0, q1, [sp]
//   0x005288: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x00528c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x005290: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x005294: d53bd053  mrs      x19, tpidr_el0
//   0x005298: f940166b  ldr      x11, [x19, #0x28]
//   0x00529c: 928004e8  mov      x8, #-0x28
//   0x0052a0: 910003e9  mov      x9, sp
//   0x0052a4: 910223ea  add      x10, sp, #0x88
uint64_t fde_0006_sub_005268(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x005268ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x005268: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x00526c: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x005270: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x005274: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x005278: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x00527c: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x005280: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x005284: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x005288: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x00528c: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0007 @ 0x005304..0x0053a0 (156 bytes)
// [VN] Phục dựng FDE #0007 tại 0x005304..0x0053a0 (156 byte)
//   0x005304: d10483ff  sub      sp, sp, #0x120
//   0x005308: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x00530c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x005310: 910443fd  add      x29, sp, #0x110
//   0x005314: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x005318: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x00531c: f90057e7  str      x7, [sp, #0xa8]
//   0x005320: ad0007e0  stp      q0, q1, [sp]
//   0x005324: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x005328: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x00532c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x005330: d53bd053  mrs      x19, tpidr_el0
//   0x005334: f940166b  ldr      x11, [x19, #0x28]
//   0x005338: 928004e8  mov      x8, #-0x28
//   0x00533c: 910003e9  mov      x9, sp
//   0x005340: 910223ea  add      x10, sp, #0x88
uint64_t fde_0007_sub_005304(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x005304ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x005304: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x005308: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x00530c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x005310: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x005314: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x005318: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x00531c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x005320: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x005324: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x005328: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0008 @ 0x0053a0..0x005450 (176 bytes)
// [VN] Phục dựng FDE #0008 tại 0x0053a0..0x005450 (176 byte)
//   0x0053a0: d10143ff  sub      sp, sp, #0x50
//   0x0053a4: fd0013e8  str      d8, [sp, #0x20]
//   0x0053a8: f90017f5  str      x21, [sp, #0x28]
//   0x0053ac: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0053b0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0053b4: 910103fd  add      x29, sp, #0x40
//   0x0053b8: aa0203e1  mov      x1, x2
//   0x0053bc: 910023e8  add      x8, sp, #8
//   0x0053c0: aa0403e2  mov      x2, x4
//   0x0053c4: 4ea01c08  mov      v8.16b, v0.16b
//   0x0053c8: aa0303f4  mov      x20, x3
//   0x0053cc: aa0003f5  mov      x21, x0
//   0x0053d0: 97fffb8f  bl       #0x420c
//   0x0053d4: a940a3f3  ldp      x19, x8, [sp, #8]
//   0x0053d8: eb08027f  cmp      x19, x8
//   0x0053dc: 54000260  b.eq     #0x5428
uint64_t fde_0008_sub_0053a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x97FFFB8FULL) + (x2 ^ 0x0053A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0053a0: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xFD0013E8ULL; // 0x0053a4: str d8, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017F5ULL; // 0x0053a8: str x21, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0053ac: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0053b0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0053b4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x0053b8: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E8ULL; // 0x0053bc: add x8, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E2ULL; // 0x0053c0: mov x2, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA01C08ULL; // 0x0053c4: mov v8.16b, v0.16b
    return acc;
}

// [EN] Reconstructed FDE #0009 @ 0x005450..0x0055b4 (356 bytes)
// [VN] Phục dựng FDE #0009 tại 0x005450..0x0055b4 (356 byte)
//   0x005450: fc1b0fe8  str      d8, [sp, #-0x50]!
//   0x005454: f90007f9  str      x25, [sp, #8]
//   0x005458: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00545c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x005460: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x005464: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x005468: 910103fd  add      x29, sp, #0x40
//   0x00546c: f9400008  ldr      x8, [x0]
//   0x005470: aa0203f4  mov      x20, x2
//   0x005474: aa0203e1  mov      x1, x2
//   0x005478: aa1f03e2  mov      x2, xzr
//   0x00547c: f942e108  ldr      x8, [x8, #0x5c0]
//   0x005480: aa0603f9  mov      x25, x6
//   0x005484: 4ea01c08  mov      v8.16b, v0.16b
//   0x005488: aa0503f5  mov      x21, x5
//   0x00548c: 2a0403f6  mov      w22, w4
uint64_t fde_0009_sub_005450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC1B0FE8ULL) + (x1 ^ 0xAA0603F9ULL) + (x2 ^ 0x005450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC1B0FE8ULL; // 0x005450: str d8, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007F9ULL; // 0x005454: str x25, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x005458: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00545c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x005460: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x005464: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x005468: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x00546c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x005470: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x005474: mov x1, x2
    return acc;
}

// [EN] Reconstructed FDE #0010 @ 0x0055b4..0x005654 (160 bytes)
// [VN] Phục dựng FDE #0010 tại 0x0055b4..0x005654 (160 byte)
//   0x0055b4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0055b8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0055bc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0055c0: 910083fd  add      x29, sp, #0x20
//   0x0055c4: f00002e8  adrp     x8, #0x64000
//   0x0055c8: f941c501  ldr      x1, [x8, #0x388]
//   0x0055cc: b40003a1  cbz      x1, #0x5640
//   0x0055d0: f9400008  ldr      x8, [x0]
//   0x0055d4: aa0303f3  mov      x19, x3
//   0x0055d8: aa0203f5  mov      x21, x2
//   0x0055dc: d0000242  adrp     x2, #0x4f000
//   0x0055e0: f9417908  ldr      x8, [x8, #0x2f0]
//   0x0055e4: f0000243  adrp     x3, #0x50000
//   0x0055e8: 913c9042  add      x2, x2, #0xf24
//   0x0055ec: 91190063  add      x3, x3, #0x640
//   0x0055f0: 2a0403f4  mov      w20, w4
uint64_t fde_0010_sub_0055b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF0000243ULL) + (x2 ^ 0x0055B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0055b4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0055b8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0055bc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0055c0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF00002E8ULL; // 0x0055c4: adrp x8, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF941C501ULL; // 0x0055c8: ldr x1, [x8, #0x388]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40003A1ULL; // 0x0055cc: cbz x1, #0x5640
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0055d0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x0055d4: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x0055d8: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0011 @ 0x005654..0x005668 (20 bytes)
// [VN] Phục dựng FDE #0011 tại 0x005654..0x005668 (20 byte)
//   0x005654: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x005658: 910003fd  mov      x29, sp
//   0x00565c: d0000240  adrp     x0, #0x4f000
//   0x005660: 913cbc00  add      x0, x0, #0xf2f
//   0x005664: 94000001  bl       #0x5668
uint64_t fde_0011_sub_005654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x94000001ULL) + (x2 ^ 0x005654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x005654: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x005658: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000240ULL; // 0x00565c: adrp x0, #0x4f000
    acc = (acc * 0x100000001B3ULL) ^ 0x913CBC00ULL; // 0x005660: add x0, x0, #0xf2f
    acc = (acc * 0x100000001B3ULL) ^ 0x94000001ULL; // 0x005664: bl #0x5668
    return acc;
}

// [EN] Reconstructed FDE #0012 @ 0x005668..0x0056b8 (80 bytes)
// [VN] Phục dựng FDE #0012 tại 0x005668..0x0056b8 (80 byte)
//   0x005668: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00566c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005670: 910043fd  add      x29, sp, #0x10
//   0x005674: aa0003f4  mov      x20, x0
//   0x005678: 52800200  mov      w0, #0x10
//   0x00567c: 97fffa0d  bl       #0x3eb0
//   0x005680: aa0003f3  mov      x19, x0
//   0x005684: aa1403e1  mov      x1, x20
//   0x005688: 9400000c  bl       #0x56b8
//   0x00568c: d00002e1  adrp     x1, #0x63000
//   0x005690: d00002e2  adrp     x2, #0x63000
//   0x005694: f9470c21  ldr      x1, [x1, #0xe18]
//   0x005698: f9467c42  ldr      x2, [x2, #0xcf8]
//   0x00569c: aa1303e0  mov      x0, x19
//   0x0056a0: 97fffa8c  bl       #0x40d0
//   0x0056a4: aa0003f4  mov      x20, x0
uint64_t fde_0012_sub_005668(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9467C42ULL) + (x2 ^ 0x005668ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x005668: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00566c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x005670: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x005674: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x005678: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFA0DULL; // 0x00567c: bl #0x3eb0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x005680: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x005684: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000CULL; // 0x005688: bl #0x56b8
    acc = (acc * 0x100000001B3ULL) ^ 0xD00002E1ULL; // 0x00568c: adrp x1, #0x63000
    return acc;
}

// [EN] Reconstructed FDE #0013 @ 0x0056b8..0x0056e8 (48 bytes)
// [VN] Phục dựng FDE #0013 tại 0x0056b8..0x0056e8 (48 byte)
//   0x0056b8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0056bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0056c0: 910043fd  add      x29, sp, #0x10
//   0x0056c4: aa0003f3  mov      x19, x0
//   0x0056c8: 97fff9e6  bl       #0x3e60
//   0x0056cc: d00002e8  adrp     x8, #0x63000
//   0x0056d0: f9472d08  ldr      x8, [x8, #0xe58]
//   0x0056d4: 91004108  add      x8, x8, #0x10
//   0x0056d8: f9000268  str      x8, [x19]
//   0x0056dc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0056e0: f84207f3  ldr      x19, [sp], #0x20
//   0x0056e4: d65f03c0  ret      
uint64_t fde_0013_sub_0056b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0056B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0056b8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0056bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0056c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0056c4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF9E6ULL; // 0x0056c8: bl #0x3e60
    acc = (acc * 0x100000001B3ULL) ^ 0xD00002E8ULL; // 0x0056cc: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9472D08ULL; // 0x0056d0: ldr x8, [x8, #0xe58]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x0056d4: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0056d8: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0056dc: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0014 @ 0x0056e8..0x005704 (28 bytes)
// [VN] Phục dựng FDE #0014 tại 0x0056e8..0x005704 (28 byte)
//   0x0056e8: 7100041f  cmp      w0, #1
//   0x0056ec: 1a9f17e8  cset     w8, eq
//   0x0056f0: 7100001f  cmp      w0, #0
//   0x0056f4: 531e7508  lsl      w8, w8, #2
//   0x0056f8: 52800069  mov      w9, #3
//   0x0056fc: 1a880120  csel     w0, w9, w8, eq
//   0x005700: d65f03c0  ret      
uint64_t fde_0014_sub_0056e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100041FULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0056E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100041FULL; // 0x0056e8: cmp w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E8ULL; // 0x0056ec: cset w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x7100001FULL; // 0x0056f0: cmp w0, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x531E7508ULL; // 0x0056f4: lsl w8, w8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800069ULL; // 0x0056f8: mov w9, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x1A880120ULL; // 0x0056fc: csel w0, w9, w8, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x005700: ret 
    return acc;
}

// [EN] Reconstructed FDE #0015 @ 0x005704..0x005768 (100 bytes)
// [VN] Phục dựng FDE #0015 tại 0x005704..0x005768 (100 byte)
//   0x005704: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x005708: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00570c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x005710: 910083fd  add      x29, sp, #0x20
//   0x005714: f9400008  ldr      x8, [x0]
//   0x005718: aa0203f3  mov      x19, x2
//   0x00571c: aa0003f4  mov      x20, x0
//   0x005720: aa0103f5  mov      x21, x1
//   0x005724: f9439108  ldr      x8, [x8, #0x720]
//   0x005728: d63f0100  blr      x8
//   0x00572c: 72001c1f  tst      w0, #0xff
//   0x005730: 540000a0  b.eq     #0x5744
//   0x005734: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x005738: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x00573c: f84307f5  ldr      x21, [sp], #0x30
//   0x005740: d65f03c0  ret      
uint64_t fde_0015_sub_005704(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xA9427BFDULL) + (x2 ^ 0x005704ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x005704: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x005708: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00570c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x005710: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x005714: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x005718: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00571c: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x005720: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x005724: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x005728: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0016 @ 0x005768..0x005ab8 (848 bytes)
// [VN] Phục dựng FDE #0016 tại 0x005768..0x005ab8 (848 byte)
//   0x005768: f81b0ffc  str      x28, [sp, #-0x50]!
//   0x00576c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x005770: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x005774: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x005778: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00577c: 910103fd  add      x29, sp, #0x40
//   0x005780: d11183ff  sub      sp, sp, #0x460
//   0x005784: d53bd057  mrs      x23, tpidr_el0
//   0x005788: f94016e8  ldr      x8, [x23, #0x28]
//   0x00578c: aa0003f6  mov      x22, x0
//   0x005790: f81b83a8  stur     x8, [x29, #-0x48]
//   0x005794: b9401028  ldr      w8, [x1, #0x10]
//   0x005798: 34000128  cbz      w8, #0x57bc
//   0x00579c: d00002e8  adrp     x8, #0x63000
//   0x0057a0: f947f508  ldr      x8, [x8, #0xfe8]
//   0x0057a4: d0000242  adrp     x2, #0x4f000
uint64_t fde_0016_sub_005768(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FFCULL) + (x1 ^ 0x34000128ULL) + (x2 ^ 0x005768ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FFCULL; // 0x005768: str x28, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00576c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x005770: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x005774: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x005778: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00577c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD11183FFULL; // 0x005780: sub sp, sp, #0x460
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x005784: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x005788: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x00578c: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #0017 @ 0x005ab8..0x005aec (52 bytes)
// [VN] Phục dựng FDE #0017 tại 0x005ab8..0x005aec (52 byte)
//   0x005ab8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x005abc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005ac0: 910043fd  add      x29, sp, #0x10
//   0x005ac4: aa0003f3  mov      x19, x0
//   0x005ac8: a91b7c1f  stp      xzr, xzr, [x0, #0x1b0]
//   0x005acc: f900d401  str      x1, [x0, #0x1a8]
//   0x005ad0: 94002a08  bl       #0x102f0
//   0x005ad4: 90000008  adrp     x8, #0x5000
//   0x005ad8: 912bb108  add      x8, x8, #0xaec
//   0x005adc: f9000268  str      x8, [x19]
//   0x005ae0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x005ae4: f84207f3  ldr      x19, [sp], #0x20
//   0x005ae8: d65f03c0  ret      
uint64_t fde_0017_sub_005ab8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x005AB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x005ab8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x005abc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x005ac0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x005ac4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B7C1FULL; // 0x005ac8: stp xzr, xzr, [x0, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900D401ULL; // 0x005acc: str x1, [x0, #0x1a8]
    acc = (acc * 0x100000001B3ULL) ^ 0x94002A08ULL; // 0x005ad0: bl #0x102f0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x005ad4: adrp x8, #0x5000
    acc = (acc * 0x100000001B3ULL) ^ 0x912BB108ULL; // 0x005ad8: add x8, x8, #0xaec
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x005adc: str x8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0018 @ 0x005aec..0x005b1c (48 bytes)
// [VN] Phục dựng FDE #0018 tại 0x005aec..0x005b1c (48 byte)
//   0x005aec: d103c3ff  sub      sp, sp, #0xf0
//   0x005af0: f9006bf3  str      x19, [sp, #0xd0]
//   0x005af4: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x005af8: 910383fd  add      x29, sp, #0xe0
//   0x005afc: f9400008  ldr      x8, [x0]
//   0x005b00: 910023e1  add      x1, sp, #8
//   0x005b04: aa0003f3  mov      x19, x0
//   0x005b08: f9400d08  ldr      x8, [x8, #0x18]
//   0x005b0c: d63f0100  blr      x8
//   0x005b10: 910023e1  add      x1, sp, #8
//   0x005b14: aa1303e0  mov      x0, x19
//   0x005b18: 94000004  bl       #0x5b28
uint64_t fde_0018_sub_005aec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0x94000004ULL) + (x2 ^ 0x005AECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x005aec: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9006BF3ULL; // 0x005af0: str x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x005af4: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x005af8: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x005afc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x005b00: add x1, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x005b04: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400D08ULL; // 0x005b08: ldr x8, [x8, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x005b0c: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E1ULL; // 0x005b10: add x1, sp, #8
    return acc;
}

// [EN] Reconstructed FDE #0019 @ 0x005b1c..0x005b28 (12 bytes)
// [VN] Phục dựng FDE #0019 tại 0x005b1c..0x005b28 (12 byte)
//   0x005b1c: f9000020  str      x0, [x1]
//   0x005b20: f900dc01  str      x1, [x0, #0x1b8]
//   0x005b24: d65f03c0  ret      
uint64_t fde_0019_sub_005b1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9000020ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x005B1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000020ULL; // 0x005b1c: str x0, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900DC01ULL; // 0x005b20: str x1, [x0, #0x1b8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x005b24: ret 
    return acc;
}

// [EN] Reconstructed FDE #0020 @ 0x005b28..0x005b7c (84 bytes)
// [VN] Phục dựng FDE #0020 tại 0x005b28..0x005b7c (84 byte)
//   0x005b28: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x005b2c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005b30: 910043fd  add      x29, sp, #0x10
//   0x005b34: f9400013  ldr      x19, [x0]
//   0x005b38: aa0103f4  mov      x20, x1
//   0x005b3c: f940d660  ldr      x0, [x19, #0x1a8]
//   0x005b40: f9400008  ldr      x8, [x0]
//   0x005b44: f9439108  ldr      x8, [x8, #0x720]
//   0x005b48: d63f0100  blr      x8
//   0x005b4c: 72001c1f  tst      w0, #0xff
//   0x005b50: 54000121  b.ne     #0x5b74
//   0x005b54: f940d660  ldr      x0, [x19, #0x1a8]
//   0x005b58: d00002e9  adrp     x9, #0x63000
//   0x005b5c: aa1403e2  mov      x2, x20
//   0x005b60: f9400008  ldr      x8, [x0]
//   0x005b64: f947f529  ldr      x9, [x9, #0xfe8]
uint64_t fde_0020_sub_005b28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD00002E9ULL) + (x2 ^ 0x005B28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x005b28: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x005b2c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x005b30: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x005b34: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x005b38: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF940D660ULL; // 0x005b3c: ldr x0, [x19, #0x1a8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x005b40: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x005b44: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x005b48: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C1FULL; // 0x005b4c: tst w0, #0xff
    return acc;
}

// [EN] Reconstructed FDE #0021 @ 0x005b7c..0x005bb8 (60 bytes)
// [VN] Phục dựng FDE #0021 tại 0x005b7c..0x005bb8 (60 byte)
//   0x005b7c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x005b80: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005b84: 910043fd  add      x29, sp, #0x10
//   0x005b88: aa0003f3  mov      x19, x0
//   0x005b8c: f940d800  ldr      x0, [x0, #0x1b0]
//   0x005b90: b4000060  cbz      x0, #0x5b9c
//   0x005b94: 940029d6  bl       #0x102ec
//   0x005b98: f900da7f  str      xzr, [x19, #0x1b0]
//   0x005b9c: f940de60  ldr      x0, [x19, #0x1b8]
//   0x005ba0: b4000060  cbz      x0, #0x5bac
//   0x005ba4: 94000ed6  bl       #0x96fc
//   0x005ba8: f900de7f  str      xzr, [x19, #0x1b8]
//   0x005bac: 9102a260  add      x0, x19, #0xa8
//   0x005bb0: 52800021  mov      w1, #1
//   0x005bb4: 97fff8a7  bl       #0x3e50
uint64_t fde_0021_sub_005b7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x9102A260ULL) + (x2 ^ 0x005B7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x005b7c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x005b80: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x005b84: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x005b88: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF940D800ULL; // 0x005b8c: ldr x0, [x0, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x005b90: cbz x0, #0x5b9c
    acc = (acc * 0x100000001B3ULL) ^ 0x940029D6ULL; // 0x005b94: bl #0x102ec
    acc = (acc * 0x100000001B3ULL) ^ 0xF900DA7FULL; // 0x005b98: str xzr, [x19, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940DE60ULL; // 0x005b9c: ldr x0, [x19, #0x1b8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x005ba0: cbz x0, #0x5bac
    return acc;
}

// [EN] Reconstructed FDE #0022 @ 0x005bb8..0x005bf4 (60 bytes)
// [VN] Phục dựng FDE #0022 tại 0x005bb8..0x005bf4 (60 byte)
//   0x005bb8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x005bbc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005bc0: 910043fd  add      x29, sp, #0x10
//   0x005bc4: f9400013  ldr      x19, [x0]
//   0x005bc8: f940d660  ldr      x0, [x19, #0x1a8]
//   0x005bcc: f9400008  ldr      x8, [x0]
//   0x005bd0: f9439108  ldr      x8, [x8, #0x720]
//   0x005bd4: d63f0100  blr      x8
//   0x005bd8: 72001c1f  tst      w0, #0xff
//   0x005bdc: 54000081  b.ne     #0x5bec
//   0x005be0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x005be4: f84207f3  ldr      x19, [sp], #0x20
//   0x005be8: d65f03c0  ret      
//   0x005bec: aa1303e0  mov      x0, x19
//   0x005bf0: 97ffffe3  bl       #0x5b7c
uint64_t fde_0022_sub_005bb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x005BB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x005bb8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x005bbc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x005bc0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x005bc4: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940D660ULL; // 0x005bc8: ldr x0, [x19, #0x1a8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x005bcc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x005bd0: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x005bd4: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C1FULL; // 0x005bd8: tst w0, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x54000081ULL; // 0x005bdc: b.ne #0x5bec
    return acc;
}

// [EN] Reconstructed FDE #0023 @ 0x005bf4..0x005c1c (40 bytes)
// [VN] Phục dựng FDE #0023 tại 0x005bf4..0x005c1c (40 byte)
//   0x005bf4: 90000008  adrp     x8, #0x5000
//   0x005bf8: 90000009  adrp     x9, #0x5000
//   0x005bfc: 9000000a  adrp     x10, #0x5000
//   0x005c00: 91307108  add      x8, x8, #0xc1c
//   0x005c04: 91326129  add      x9, x9, #0xc98
//   0x005c08: 9134614a  add      x10, x10, #0xd18
//   0x005c0c: f9002001  str      x1, [x0, #0x40]
//   0x005c10: a902080a  stp      x10, x2, [x0, #0x20]
//   0x005c14: a9012408  stp      x8, x9, [x0, #0x10]
//   0x005c18: d65f03c0  ret      
uint64_t fde_0023_sub_005bf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x005BF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x005bf4: adrp x8, #0x5000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x005bf8: adrp x9, #0x5000
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000AULL; // 0x005bfc: adrp x10, #0x5000
    acc = (acc * 0x100000001B3ULL) ^ 0x91307108ULL; // 0x005c00: add x8, x8, #0xc1c
    acc = (acc * 0x100000001B3ULL) ^ 0x91326129ULL; // 0x005c04: add x9, x9, #0xc98
    acc = (acc * 0x100000001B3ULL) ^ 0x9134614AULL; // 0x005c08: add x10, x10, #0xd18
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002001ULL; // 0x005c0c: str x1, [x0, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA902080AULL; // 0x005c10: stp x10, x2, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9012408ULL; // 0x005c14: stp x8, x9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x005c18: ret 
    return acc;
}

// [EN] Reconstructed FDE #0024 @ 0x005c1c..0x005c98 (124 bytes)
// [VN] Phục dựng FDE #0024 tại 0x005c1c..0x005c98 (124 byte)
//   0x005c1c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x005c20: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x005c24: 910043fd  add      x29, sp, #0x10
//   0x005c28: f9401414  ldr      x20, [x0, #0x28]
//   0x005c2c: aa0003f3  mov      x19, x0
//   0x005c30: 52840001  mov      w1, #0x2000
//   0x005c34: f9402280  ldr      x0, [x20, #0x40]
//   0x005c38: f9400008  ldr      x8, [x0]
//   0x005c3c: f942c108  ldr      x8, [x8, #0x580]
//   0x005c40: d63f0100  blr      x8
//   0x005c44: f9001a80  str      x0, [x20, #0x30]
//   0x005c48: aa1303e0  mov      x0, x19
//   0x005c4c: 97ffffdb  bl       #0x5bb8
//   0x005c50: f9400668  ldr      x8, [x19, #8]
//   0x005c54: 52800021  mov      w1, #1
//   0x005c58: 52840002  mov      w2, #0x2000
uint64_t fde_0024_sub_005c1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FFFFDBULL) + (x2 ^ 0x005C1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x005c1c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x005c20: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x005c24: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401414ULL; // 0x005c28: ldr x20, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x005c2c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52840001ULL; // 0x005c30: mov w1, #0x2000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402280ULL; // 0x005c34: ldr x0, [x20, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x005c38: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF942C108ULL; // 0x005c3c: ldr x8, [x8, #0x580]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x005c40: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0025 @ 0x005c98..0x005d18 (128 bytes)
// [VN] Phục dựng FDE #0025 tại 0x005c98..0x005d18 (128 byte)
//   0x005c98: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x005c9c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x005ca0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x005ca4: 910083fd  add      x29, sp, #0x20
//   0x005ca8: f9401415  ldr      x21, [x0, #0x28]
//   0x005cac: aa0003f3  mov      x19, x0
//   0x005cb0: 52840003  mov      w3, #0x2000
//   0x005cb4: 2a1f03e2  mov      w2, wzr
//   0x005cb8: a943d2a4  ldp      x4, x20, [x21, #0x38]
//   0x005cbc: f9401aa1  ldr      x1, [x21, #0x30]
//   0x005cc0: 52840016  mov      w22, #0x2000
//   0x005cc4: f9400288  ldr      x8, [x20]
//   0x005cc8: aa1403e0  mov      x0, x20
//   0x005ccc: f9434108  ldr      x8, [x8, #0x680]
//   0x005cd0: d63f0100  blr      x8
//   0x005cd4: aa1303e0  mov      x0, x19
uint64_t fde_0025_sub_005c98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x005C98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x005c98: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x005c9c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x005ca0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x005ca4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401415ULL; // 0x005ca8: ldr x21, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x005cac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52840003ULL; // 0x005cb0: mov w3, #0x2000
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x005cb4: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xA943D2A4ULL; // 0x005cb8: ldp x4, x20, [x21, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401AA1ULL; // 0x005cbc: ldr x1, [x21, #0x30]
    return acc;
}

// [EN] Reconstructed FDE #0026 @ 0x005d18..0x005dac (148 bytes)
// [VN] Phục dựng FDE #0026 tại 0x005d18..0x005dac (148 byte)
//   0x005d18: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x005d1c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x005d20: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x005d24: 910083fd  add      x29, sp, #0x20
//   0x005d28: f9401416  ldr      x22, [x0, #0x28]
//   0x005d2c: 52840009  mov      w9, #0x2000
//   0x005d30: f94006c8  ldr      x8, [x22, #8]
//   0x005d34: eb080134  subs     x20, x9, x8
//   0x005d38: 54000320  b.eq     #0x5d9c
//   0x005d3c: a943d6c4  ldp      x4, x21, [x22, #0x38]
//   0x005d40: f9401ac1  ldr      x1, [x22, #0x30]
//   0x005d44: aa0003f3  mov      x19, x0
//   0x005d48: 2a1f03e2  mov      w2, wzr
//   0x005d4c: f94002a8  ldr      x8, [x21]
//   0x005d50: aa1503e0  mov      x0, x21
//   0x005d54: 2a1403e3  mov      w3, w20
uint64_t fde_0026_sub_005d18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x2A1F03E2ULL) + (x2 ^ 0x005D18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x005d18: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x005d1c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x005d20: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x005d24: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401416ULL; // 0x005d28: ldr x22, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52840009ULL; // 0x005d2c: mov w9, #0x2000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94006C8ULL; // 0x005d30: ldr x8, [x22, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB080134ULL; // 0x005d34: subs x20, x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000320ULL; // 0x005d38: b.eq #0x5d9c
    acc = (acc * 0x100000001B3ULL) ^ 0xA943D6C4ULL; // 0x005d3c: ldp x4, x21, [x22, #0x38]
    return acc;
}

// [EN] Reconstructed FDE #0027 @ 0x005dac..0x005e48 (156 bytes)
// [VN] Phục dựng FDE #0027 tại 0x005dac..0x005e48 (156 byte)
//   0x005dac: d10483ff  sub      sp, sp, #0x120
//   0x005db0: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x005db4: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x005db8: 910443fd  add      x29, sp, #0x110
//   0x005dbc: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x005dc0: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x005dc4: f90057e7  str      x7, [sp, #0xa8]
//   0x005dc8: ad0007e0  stp      q0, q1, [sp]
//   0x005dcc: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x005dd0: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x005dd4: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x005dd8: d53bd053  mrs      x19, tpidr_el0
//   0x005ddc: f940166b  ldr      x11, [x19, #0x28]
//   0x005de0: 928004e8  mov      x8, #-0x28
//   0x005de4: 910003e9  mov      x9, sp
//   0x005de8: 910223ea  add      x10, sp, #0x88
uint64_t fde_0027_sub_005dac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x005DACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x005dac: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x005db0: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x005db4: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x005db8: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x005dbc: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x005dc0: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x005dc4: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x005dc8: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x005dcc: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x005dd0: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0028 @ 0x005e48..0x006094 (588 bytes)
// [VN] Phục dựng FDE #0028 tại 0x005e48..0x006094 (588 byte)
//   0x005e48: d10283ff  sub      sp, sp, #0xa0
//   0x005e4c: f90023fb  str      x27, [sp, #0x40]
//   0x005e50: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x005e54: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x005e58: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x005e5c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x005e60: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x005e64: 910243fd  add      x29, sp, #0x90
//   0x005e68: d53bd059  mrs      x25, tpidr_el0
//   0x005e6c: f9401728  ldr      x8, [x25, #0x28]
//   0x005e70: aa0003f7  mov      x23, x0
//   0x005e74: f9001fe8  str      x8, [sp, #0x38]
//   0x005e78: b9401028  ldr      w8, [x1, #0x10]
//   0x005e7c: 7100051f  cmp      w8, #1
//   0x005e80: 54000581  b.ne     #0x5f30
//   0x005e84: f0000240  adrp     x0, #0x50000
uint64_t fde_0028_sub_005e48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xB9401028ULL) + (x2 ^ 0x005E48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x005e48: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023FBULL; // 0x005e4c: str x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x005e50: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x005e54: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x005e58: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x005e5c: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x005e60: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x005e64: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x005e68: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x005e6c: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0029 @ 0x006094..0x0060a0 (12 bytes)
// [VN] Phục dựng FDE #0029 tại 0x006094..0x0060a0 (12 byte)
//   0x006094: f81f0ffe  str      x30, [sp, #-0x10]!
//   0x006098: 97fff806  bl       #0x40b0
//   0x00609c: 97fff83d  bl       #0x4190
uint64_t fde_0029_sub_006094(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FFEULL) + (x1 ^ 0x97FFF83DULL) + (x2 ^ 0x006094ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FFEULL; // 0x006094: str x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF806ULL; // 0x006098: bl #0x40b0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF83DULL; // 0x00609c: bl #0x4190
    return acc;
}

// [EN] Reconstructed FDE #0030 @ 0x0060a0..0x0060a4 (4 bytes)
// [VN] Phục dựng FDE #0030 tại 0x0060a0..0x0060a4 (4 byte)
//   0x0060a0: d65f03c0  ret      
uint64_t fde_0030_sub_0060a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0060A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0060a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0031 @ 0x0060a4..0x0060e0 (60 bytes)
// [VN] Phục dựng FDE #0031 tại 0x0060a4..0x0060e0 (60 byte)
//   0x0060a4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0060a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0060ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0060b0: 910083fd  add      x29, sp, #0x20
//   0x0060b4: aa0203f3  mov      x19, x2
//   0x0060b8: aa0103f4  mov      x20, x1
//   0x0060bc: aa0003f5  mov      x21, x0
//   0x0060c0: 94006a98  bl       #0x20b20
//   0x0060c4: aa1403e2  mov      x2, x20
//   0x0060c8: aa1303e3  mov      x3, x19
//   0x0060cc: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0060d0: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x0060d4: aa1503e1  mov      x1, x21
//   0x0060d8: f84307f5  ldr      x21, [sp], #0x30
//   0x0060dc: 14000001  b        #0x60e0
uint64_t fde_0031_sub_0060a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1503E1ULL) + (x2 ^ 0x0060A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0060a4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0060a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0060ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0060b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0060b4: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0060b8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0060bc: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94006A98ULL; // 0x0060c0: bl #0x20b20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x0060c4: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x0060c8: mov x3, x19
    return acc;
}

// [EN] Reconstructed FDE #0032 @ 0x0060e0..0x0061c8 (232 bytes)
// [VN] Phục dựng FDE #0032 tại 0x0060e0..0x0061c8 (232 byte)
//   0x0060e0: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0060e4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0060e8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0060ec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0060f0: 9100c3fd  add      x29, sp, #0x30
//   0x0060f4: b4000503  cbz      x3, #0x6194
//   0x0060f8: b00002f8  adrp     x24, #0x63000
//   0x0060fc: f9471b18  ldr      x24, [x24, #0xe30]
//   0x006100: aa0303f4  mov      x20, x3
//   0x006104: aa0203f5  mov      x21, x2
//   0x006108: aa0103f3  mov      x19, x1
//   0x00610c: aa0003f6  mov      x22, x0
//   0x006110: f94002c0  ldr      x0, [x22]
//   0x006114: b9401ac9  ldr      w9, [x22, #0x18]
//   0x006118: f9400ac1  ldr      x1, [x22, #0x10]
//   0x00611c: 2a1f03e2  mov      w2, wzr
uint64_t fde_0032_sub_0060e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xF94002C0ULL) + (x2 ^ 0x0060E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0060e0: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0060e4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0060e8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0060ec: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0060f0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000503ULL; // 0x0060f4: cbz x3, #0x6194
    acc = (acc * 0x100000001B3ULL) ^ 0xB00002F8ULL; // 0x0060f8: adrp x24, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9471B18ULL; // 0x0060fc: ldr x24, [x24, #0xe30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x006100: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x006104: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0033 @ 0x0061c8..0x006214 (76 bytes)
// [VN] Phục dựng FDE #0033 tại 0x0061c8..0x006214 (76 byte)
//   0x0061c8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0061cc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0061d0: 910043fd  add      x29, sp, #0x10
//   0x0061d4: a9000801  stp      x1, x2, [x0]
//   0x0061d8: b9001803  str      w3, [x0, #0x18]
//   0x0061dc: f9400028  ldr      x8, [x1]
//   0x0061e0: aa0103f3  mov      x19, x1
//   0x0061e4: aa0003f4  mov      x20, x0
//   0x0061e8: aa0103e0  mov      x0, x1
//   0x0061ec: f942c108  ldr      x8, [x8, #0x580]
//   0x0061f0: 2a0303e1  mov      w1, w3
//   0x0061f4: d63f0100  blr      x8
//   0x0061f8: f9000a80  str      x0, [x20, #0x10]
//   0x0061fc: f9400268  ldr      x8, [x19]
//   0x006200: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x006204: aa1303e0  mov      x0, x19
uint64_t fde_0033_sub_0061c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000A80ULL) + (x2 ^ 0x0061C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0061c8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0061cc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0061d0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000801ULL; // 0x0061d4: stp x1, x2, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9001803ULL; // 0x0061d8: str w3, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x0061dc: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0061e0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0061e4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x0061e8: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF942C108ULL; // 0x0061ec: ldr x8, [x8, #0x580]
    return acc;
}

// [EN] Reconstructed FDE #0034 @ 0x006214..0x00640c (504 bytes)
// [VN] Phục dựng FDE #0034 tại 0x006214..0x00640c (504 byte)
//   0x006214: d101c3ff  sub      sp, sp, #0x70
//   0x006218: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x00621c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x006220: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x006224: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x006228: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00622c: 910183fd  add      x29, sp, #0x60
//   0x006230: d53bd059  mrs      x25, tpidr_el0
//   0x006234: f9401729  ldr      x9, [x25, #0x28]
//   0x006238: aa0103f5  mov      x21, x1
//   0x00623c: aa0003f4  mov      x20, x0
//   0x006240: aa0803f3  mov      x19, x8
//   0x006244: f9000fe9  str      x9, [sp, #0x18]
//   0x006248: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x00624c: f90003ff  str      xzr, [sp]
//   0x006250: f9400009  ldr      x9, [x0]
uint64_t fde_0034_sub_006214(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF9000FE9ULL) + (x2 ^ 0x006214ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x006214: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x006218: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x00621c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x006220: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x006224: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x006228: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x00622c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x006230: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401729ULL; // 0x006234: ldr x9, [x25, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x006238: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0035 @ 0x00640c..0x00653c (304 bytes)
// [VN] Phục dựng FDE #0035 tại 0x00640c..0x00653c (304 byte)
//   0x00640c: d10243ff  sub      sp, sp, #0x90
//   0x006410: f9002bf7  str      x23, [sp, #0x50]
//   0x006414: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x006418: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x00641c: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x006420: 910203fd  add      x29, sp, #0x80
//   0x006424: d53bd056  mrs      x22, tpidr_el0
//   0x006428: aa0803f3  mov      x19, x8
//   0x00642c: f94016c8  ldr      x8, [x22, #0x28]
//   0x006430: aa0003f5  mov      x21, x0
//   0x006434: 910003e0  mov      x0, sp
//   0x006438: 528020e3  mov      w3, #0x107
//   0x00643c: f81c83a8  stur     x8, [x29, #-0x38]
//   0x006440: a9402428  ldp      x8, x9, [x1]
//   0x006444: 2a1f03e1  mov      w1, wzr
//   0x006448: aa1f03e2  mov      x2, xzr
uint64_t fde_0035_sub_00640c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x00640CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x00640c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF9002BF7ULL; // 0x006410: str x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x006414: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x006418: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x00641c: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x006420: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x006424: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x006428: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x00642c: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x006430: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0036 @ 0x00653c..0x0065c4 (136 bytes)
// [VN] Phục dựng FDE #0036 tại 0x00653c..0x0065c4 (136 byte)
//   0x00653c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x006540: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x006544: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x006548: 910083fd  add      x29, sp, #0x20
//   0x00654c: eb010055  subs     x21, x2, x1
//   0x006550: a9007c1f  stp      xzr, xzr, [x0]
//   0x006554: f900081f  str      xzr, [x0, #0x10]
//   0x006558: 540001a0  b.eq     #0x658c
//   0x00655c: aa0003f3  mov      x19, x0
//   0x006560: b7f801f5  tbnz     x21, #0x3f, #0x659c
//   0x006564: aa0103f4  mov      x20, x1
//   0x006568: aa1503e0  mov      x0, x21
//   0x00656c: 97fff6f5  bl       #0x4140
//   0x006570: 8b150016  add      x22, x0, x21
//   0x006574: aa1403e1  mov      x1, x20
//   0x006578: aa1503e2  mov      x2, x21
uint64_t fde_0036_sub_00653c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x97FFF6F5ULL) + (x2 ^ 0x00653CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00653c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x006540: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x006544: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x006548: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xEB010055ULL; // 0x00654c: subs x21, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C1FULL; // 0x006550: stp xzr, xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900081FULL; // 0x006554: str xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x540001A0ULL; // 0x006558: b.eq #0x658c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00655c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB7F801F5ULL; // 0x006560: tbnz x21, #0x3f, #0x659c
    return acc;
}

// [EN] Reconstructed FDE #0037 @ 0x0065c4..0x0067b8 (500 bytes)
// [VN] Phục dựng FDE #0037 tại 0x0065c4..0x0067b8 (500 byte)
//   0x0065c4: d101c3ff  sub      sp, sp, #0x70
//   0x0065c8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0065cc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0065d0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0065d4: 910183fd  add      x29, sp, #0x60
//   0x0065d8: d53bd056  mrs      x22, tpidr_el0
//   0x0065dc: aa0803f3  mov      x19, x8
//   0x0065e0: f94016c8  ldr      x8, [x22, #0x28]
//   0x0065e4: 2a0203f4  mov      w20, w2
//   0x0065e8: aa0003f5  mov      x21, x0
//   0x0065ec: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0065f0: 910083e8  add      x8, sp, #0x20
//   0x0065f4: 97ffff08  bl       #0x6214
//   0x0065f8: f94002a8  ldr      x8, [x21]
//   0x0065fc: f9439108  ldr      x8, [x8, #0x720]
//   0x006600: aa1503e0  mov      x0, x21
uint64_t fde_0037_sub_0065c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x97FFFF08ULL) + (x2 ^ 0x0065C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0065c4: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0065c8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0065cc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0065d0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0065d4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0065d8: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x0065dc: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0065e0: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x0065e4: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0065e8: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0038 @ 0x0067b8..0x006840 (136 bytes)
// [VN] Phục dựng FDE #0038 tại 0x0067b8..0x006840 (136 byte)
//   0x0067b8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0067bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0067c0: 910043fd  add      x29, sp, #0x10
//   0x0067c4: f9400008  ldr      x8, [x0]
//   0x0067c8: d0000241  adrp     x1, #0x50000
//   0x0067cc: 91094421  add      x1, x1, #0x251
//   0x0067d0: aa0003f3  mov      x19, x0
//   0x0067d4: f9401908  ldr      x8, [x8, #0x30]
//   0x0067d8: d63f0100  blr      x8
//   0x0067dc: b40001a0  cbz      x0, #0x6810
//   0x0067e0: f9400268  ldr      x8, [x19]
//   0x0067e4: d00002e2  adrp     x2, #0x64000
//   0x0067e8: aa0003e1  mov      x1, x0
//   0x0067ec: 91014042  add      x2, x2, #0x50
//   0x0067f0: f9435d08  ldr      x8, [x8, #0x6b8]
//   0x0067f4: 52800043  mov      w3, #2
uint64_t fde_0038_sub_0067b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x0067B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0067b8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0067bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0067c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0067c4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000241ULL; // 0x0067c8: adrp x1, #0x50000
    acc = (acc * 0x100000001B3ULL) ^ 0x91094421ULL; // 0x0067cc: add x1, x1, #0x251
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0067d0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x0067d4: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0067d8: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A0ULL; // 0x0067dc: cbz x0, #0x6810
    return acc;
}

// [EN] Reconstructed FDE #0039 @ 0x006840..0x006954 (276 bytes)
// [VN] Phục dựng FDE #0039 tại 0x006840..0x006954 (276 byte)
//   0x006840: d10103ff  sub      sp, sp, #0x40
//   0x006844: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x006848: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00684c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x006850: 9100c3fd  add      x29, sp, #0x30
//   0x006854: d53bd056  mrs      x22, tpidr_el0
//   0x006858: f94016c8  ldr      x8, [x22, #0x28]
//   0x00685c: aa0203e1  mov      x1, x2
//   0x006860: 2a1f03e2  mov      w2, wzr
//   0x006864: 2a0403f3  mov      w19, w4
//   0x006868: f90007e8  str      x8, [sp, #8]
//   0x00686c: 910003e8  mov      x8, sp
//   0x006870: aa0303f4  mov      x20, x3
//   0x006874: aa0003f5  mov      x21, x0
//   0x006878: 97ffff53  bl       #0x65c4
//   0x00687c: f94002a8  ldr      x8, [x21]
uint64_t fde_0039_sub_006840(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0303F4ULL) + (x2 ^ 0x006840ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x006840: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x006844: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x006848: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00684c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x006850: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x006854: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x006858: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x00685c: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x006860: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F3ULL; // 0x006864: mov w19, w4
    return acc;
}

// [EN] Reconstructed FDE #0040 @ 0x006954..0x006a60 (268 bytes)
// [VN] Phục dựng FDE #0040 tại 0x006954..0x006a60 (268 byte)
//   0x006954: d10103ff  sub      sp, sp, #0x40
//   0x006958: f9000bf5  str      x21, [sp, #0x10]
//   0x00695c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x006960: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x006964: 9100c3fd  add      x29, sp, #0x30
//   0x006968: d53bd055  mrs      x21, tpidr_el0
//   0x00696c: f94016a8  ldr      x8, [x21, #0x28]
//   0x006970: aa0203e1  mov      x1, x2
//   0x006974: 52800022  mov      w2, #1
//   0x006978: aa0303f3  mov      x19, x3
//   0x00697c: f90007e8  str      x8, [sp, #8]
//   0x006980: 910003e8  mov      x8, sp
//   0x006984: aa0003f4  mov      x20, x0
//   0x006988: 97ffff0f  bl       #0x65c4
//   0x00698c: f9400288  ldr      x8, [x20]
//   0x006990: f9439108  ldr      x8, [x8, #0x720]
uint64_t fde_0040_sub_006954(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x006954ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x006954: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x006958: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00695c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x006960: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x006964: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x006968: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x00696c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x006970: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x52800022ULL; // 0x006974: mov w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x006978: mov x19, x3
    return acc;
}

// [EN] Reconstructed FDE #0041 @ 0x006a60..0x006b3c (220 bytes)
// [VN] Phục dựng FDE #0041 tại 0x006a60..0x006b3c (220 byte)
//   0x006a60: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x006a64: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x006a68: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x006a6c: 910083fd  add      x29, sp, #0x20
//   0x006a70: d11403ff  sub      sp, sp, #0x500
//   0x006a74: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x006a78: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x006a7c: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x006a80: ad0007e0  stp      q0, q1, [sp]
//   0x006a84: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x006a88: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x006a8c: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x006a90: d53bd054  mrs      x20, tpidr_el0
//   0x006a94: f940168c  ldr      x12, [x20, #0x28]
//   0x006a98: 928005e9  mov      x9, #-0x30
//   0x006a9c: 910003ea  mov      x10, sp
uint64_t fde_0041_sub_006a60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xD53BD054ULL) + (x2 ^ 0x006A60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x006a60: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x006a64: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x006a68: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x006a6c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD11403FFULL; // 0x006a70: sub sp, sp, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xA9080FE2ULL; // 0x006a74: stp x2, x3, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90917E4ULL; // 0x006a78: stp x4, x5, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A1FE6ULL; // 0x006a7c: stp x6, x7, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x006a80: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x006a84: stp q2, q3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0042 @ 0x006b3c..0x006c18 (220 bytes)
// [VN] Phục dựng FDE #0042 tại 0x006b3c..0x006c18 (220 byte)
//   0x006b3c: f81d0ffc  str      x28, [sp, #-0x30]!
//   0x006b40: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x006b44: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x006b48: 910083fd  add      x29, sp, #0x20
//   0x006b4c: d11403ff  sub      sp, sp, #0x500
//   0x006b50: a9080fe2  stp      x2, x3, [sp, #0x80]
//   0x006b54: a90917e4  stp      x4, x5, [sp, #0x90]
//   0x006b58: a90a1fe6  stp      x6, x7, [sp, #0xa0]
//   0x006b5c: ad0007e0  stp      q0, q1, [sp]
//   0x006b60: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x006b64: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x006b68: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x006b6c: d53bd054  mrs      x20, tpidr_el0
//   0x006b70: f940168c  ldr      x12, [x20, #0x28]
//   0x006b74: 928005e9  mov      x9, #-0x30
//   0x006b78: 910003ea  mov      x10, sp
uint64_t fde_0042_sub_006b3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FFCULL) + (x1 ^ 0xD53BD054ULL) + (x2 ^ 0x006B3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FFCULL; // 0x006b3c: str x28, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x006b40: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x006b44: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x006b48: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD11403FFULL; // 0x006b4c: sub sp, sp, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xA9080FE2ULL; // 0x006b50: stp x2, x3, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90917E4ULL; // 0x006b54: stp x4, x5, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A1FE6ULL; // 0x006b58: stp x6, x7, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x006b5c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x006b60: stp q2, q3, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0043 @ 0x006c18..0x006c60 (72 bytes)
// [VN] Phục dựng FDE #0043 tại 0x006c18..0x006c60 (72 byte)
//   0x006c18: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x006c1c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x006c20: 910043fd  add      x29, sp, #0x10
//   0x006c24: f9400008  ldr      x8, [x0]
//   0x006c28: aa0003f3  mov      x19, x0
//   0x006c2c: f9401908  ldr      x8, [x8, #0x30]
//   0x006c30: d63f0100  blr      x8
//   0x006c34: b4000100  cbz      x0, #0x6c54
//   0x006c38: f9400268  ldr      x8, [x19]
//   0x006c3c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x006c40: aa0003e1  mov      x1, x0
//   0x006c44: aa1303e0  mov      x0, x19
//   0x006c48: f9405502  ldr      x2, [x8, #0xa8]
//   0x006c4c: f84207f3  ldr      x19, [sp], #0x20
//   0x006c50: d61f0040  br       x2
//   0x006c54: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_0043_sub_006c18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9405502ULL) + (x2 ^ 0x006C18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x006c18: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x006c1c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x006c20: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x006c24: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x006c28: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x006c2c: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x006c30: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000100ULL; // 0x006c34: cbz x0, #0x6c54
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x006c38: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x006c3c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0044 @ 0x006c60..0x006c6c (12 bytes)
// [VN] Phục dựng FDE #0044 tại 0x006c60..0x006c6c (12 byte)
//   0x006c60: f9400008  ldr      x8, [x0]
//   0x006c64: f9417904  ldr      x4, [x8, #0x2f0]
//   0x006c68: d61f0080  br       x4
uint64_t fde_0044_sub_006c60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0080ULL) + (x2 ^ 0x006C60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x006c60: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9417904ULL; // 0x006c64: ldr x4, [x8, #0x2f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0080ULL; // 0x006c68: br x4
    return acc;
}

// [EN] Reconstructed FDE #0045 @ 0x006c6c..0x006c78 (12 bytes)
// [VN] Phục dựng FDE #0045 tại 0x006c6c..0x006c78 (12 byte)
//   0x006c6c: f9400008  ldr      x8, [x0]
//   0x006c70: f9408504  ldr      x4, [x8, #0x108]
//   0x006c74: d61f0080  br       x4
uint64_t fde_0045_sub_006c6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0080ULL) + (x2 ^ 0x006C6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x006c6c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408504ULL; // 0x006c70: ldr x4, [x8, #0x108]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0080ULL; // 0x006c74: br x4
    return acc;
}

// [EN] Reconstructed FDE #0046 @ 0x006c78..0x0070c4 (1100 bytes)
// [VN] Phục dựng FDE #0046 tại 0x006c78..0x0070c4 (1100 byte)
//   0x006c78: d103c3ff  sub      sp, sp, #0xf0
//   0x006c7c: f9004bfb  str      x27, [sp, #0x90]
//   0x006c80: a90a67fa  stp      x26, x25, [sp, #0xa0]
//   0x006c84: a90b5ff8  stp      x24, x23, [sp, #0xb0]
//   0x006c88: a90c57f6  stp      x22, x21, [sp, #0xc0]
//   0x006c8c: a90d4ff4  stp      x20, x19, [sp, #0xd0]
//   0x006c90: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x006c94: 910383fd  add      x29, sp, #0xe0
//   0x006c98: d53bd059  mrs      x25, tpidr_el0
//   0x006c9c: f9401728  ldr      x8, [x25, #0x28]
//   0x006ca0: aa0103f7  mov      x23, x1
//   0x006ca4: aa0003f4  mov      x20, x0
//   0x006ca8: f81a83a8  stur     x8, [x29, #-0x58]
//   0x006cac: 52800900  mov      w0, #0x48
//   0x006cb0: 97fff524  bl       #0x4140
//   0x006cb4: 6f00e400  movi     v0.2d, #0000000000000000
uint64_t fde_0046_sub_006c78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0xF81A83A8ULL) + (x2 ^ 0x006C78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x006c78: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BFBULL; // 0x006c7c: str x27, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A67FAULL; // 0x006c80: stp x26, x25, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B5FF8ULL; // 0x006c84: stp x24, x23, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C57F6ULL; // 0x006c88: stp x22, x21, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D4FF4ULL; // 0x006c8c: stp x20, x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x006c90: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x006c94: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x006c98: mrs x25, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401728ULL; // 0x006c9c: ldr x8, [x25, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0047 @ 0x0070c4..0x007160 (156 bytes)
// [VN] Phục dựng FDE #0047 tại 0x0070c4..0x007160 (156 byte)
//   0x0070c4: d10483ff  sub      sp, sp, #0x120
//   0x0070c8: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x0070cc: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x0070d0: 910443fd  add      x29, sp, #0x110
//   0x0070d4: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x0070d8: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x0070dc: f90057e7  str      x7, [sp, #0xa8]
//   0x0070e0: ad0007e0  stp      q0, q1, [sp]
//   0x0070e4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x0070e8: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x0070ec: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x0070f0: d53bd053  mrs      x19, tpidr_el0
//   0x0070f4: f940166b  ldr      x11, [x19, #0x28]
//   0x0070f8: 928004e8  mov      x8, #-0x28
//   0x0070fc: 910003e9  mov      x9, sp
//   0x007100: 910223ea  add      x10, sp, #0x88
uint64_t fde_0047_sub_0070c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166BULL) + (x2 ^ 0x0070C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x0070c4: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x0070c8: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x0070cc: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x0070d0: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x0070d4: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x0070d8: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x0070dc: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x0070e0: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x0070e4: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x0070e8: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0048 @ 0x007160..0x0072a4 (324 bytes)
// [VN] Phục dựng FDE #0048 tại 0x007160..0x0072a4 (324 byte)
//   0x007160: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x007164: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x007168: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00716c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x007170: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x007174: 910103fd  add      x29, sp, #0x40
//   0x007178: a900011f  stp      xzr, x0, [x8]
//   0x00717c: f9000901  str      x1, [x8, #0x10]
//   0x007180: aa0803f3  mov      x19, x8
//   0x007184: f9400008  ldr      x8, [x0]
//   0x007188: aa0103f4  mov      x20, x1
//   0x00718c: aa0003f5  mov      x21, x0
//   0x007190: f9436508  ldr      x8, [x8, #0x6c8]
//   0x007194: d63f0100  blr      x8
//   0x007198: f94002a8  ldr      x8, [x21]
//   0x00719c: b00002e9  adrp     x9, #0x64000
uint64_t fde_0048_sub_007160(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF9436508ULL) + (x2 ^ 0x007160ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x007160: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x007164: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x007168: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00716c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x007170: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x007174: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA900011FULL; // 0x007178: stp xzr, x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000901ULL; // 0x00717c: str x1, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803F3ULL; // 0x007180: mov x19, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x007184: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #0049 @ 0x0072a4..0x007360 (188 bytes)
// [VN] Phục dựng FDE #0049 tại 0x0072a4..0x007360 (188 byte)
//   0x0072a4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0072a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0072ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0072b0: 910083fd  add      x29, sp, #0x20
//   0x0072b4: f9400015  ldr      x21, [x0]
//   0x0072b8: f900001f  str      xzr, [x0]
//   0x0072bc: b4000495  cbz      x21, #0x734c
//   0x0072c0: a940d013  ldp      x19, x20, [x0, #8]
//   0x0072c4: f9400268  ldr      x8, [x19]
//   0x0072c8: f9436508  ldr      x8, [x8, #0x6c8]
//   0x0072cc: aa1303e0  mov      x0, x19
//   0x0072d0: aa1403e1  mov      x1, x20
//   0x0072d4: d63f0100  blr      x8
//   0x0072d8: f94022a8  ldr      x8, [x21, #0x40]
//   0x0072dc: f1000508  subs     x8, x8, #1
//   0x0072e0: f90022a8  str      x8, [x21, #0x40]
uint64_t fde_0049_sub_0072a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x0072A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0072a4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0072a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0072ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0072b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400015ULL; // 0x0072b4: ldr x21, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x0072b8: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000495ULL; // 0x0072bc: cbz x21, #0x734c
    acc = (acc * 0x100000001B3ULL) ^ 0xA940D013ULL; // 0x0072c0: ldp x19, x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0072c4: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x0072c8: ldr x8, [x8, #0x6c8]
    return acc;
}

// [EN] Reconstructed FDE #0050 @ 0x007360..0x0074f4 (404 bytes)
// [VN] Phục dựng FDE #0050 tại 0x007360..0x0074f4 (404 byte)
//   0x007360: d10143ff  sub      sp, sp, #0x50
//   0x007364: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x007368: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00736c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x007370: 910103fd  add      x29, sp, #0x40
//   0x007374: d53bd056  mrs      x22, tpidr_el0
//   0x007378: f94016c8  ldr      x8, [x22, #0x28]
//   0x00737c: aa0203e1  mov      x1, x2
//   0x007380: aa0003f3  mov      x19, x0
//   0x007384: aa0203f5  mov      x21, x2
//   0x007388: f9000fe8  str      x8, [sp, #0x18]
//   0x00738c: f9400008  ldr      x8, [x0]
//   0x007390: f9439908  ldr      x8, [x8, #0x730]
//   0x007394: d63f0100  blr      x8
//   0x007398: b4000780  cbz      x0, #0x7488
//   0x00739c: f9400268  ldr      x8, [x19]
uint64_t fde_0050_sub_007360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9439908ULL) + (x2 ^ 0x007360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x007360: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x007364: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x007368: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00736c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x007370: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x007374: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x007378: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x00737c: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x007380: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x007384: mov x21, x2
    return acc;
}

// [EN] Reconstructed FDE #0051 @ 0x0074f4..0x007654 (352 bytes)
// [VN] Phục dựng FDE #0051 tại 0x0074f4..0x007654 (352 byte)
//   0x0074f4: d10183ff  sub      sp, sp, #0x60
//   0x0074f8: f90013f7  str      x23, [sp, #0x20]
//   0x0074fc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x007500: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x007504: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x007508: 910143fd  add      x29, sp, #0x50
//   0x00750c: d53bd057  mrs      x23, tpidr_el0
//   0x007510: f94016e8  ldr      x8, [x23, #0x28]
//   0x007514: 2a0303f6  mov      w22, w3
//   0x007518: aa0003f3  mov      x19, x0
//   0x00751c: 93407ed4  sxtw     x20, w22
//   0x007520: f9000fe8  str      x8, [sp, #0x18]
//   0x007524: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x007528: f90003ff  str      xzr, [sp]
//   0x00752c: b4000574  cbz      x20, #0x75d8
//   0x007530: b7f807d4  tbnz     x20, #0x3f, #0x7628
uint64_t fde_0051_sub_0074f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xA900FFFFULL) + (x2 ^ 0x0074F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x0074f4: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x0074f8: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0074fc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x007500: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x007504: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x007508: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x00750c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x007510: ldr x8, [x23, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F6ULL; // 0x007514: mov w22, w3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x007518: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0052 @ 0x007654..0x0076e4 (144 bytes)
// [VN] Phục dựng FDE #0052 tại 0x007654..0x0076e4 (144 byte)
//   0x007654: d10103ff  sub      sp, sp, #0x40
//   0x007658: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00765c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x007660: 9100c3fd  add      x29, sp, #0x30
//   0x007664: d53bd054  mrs      x20, tpidr_el0
//   0x007668: f9401688  ldr      x8, [x20, #0x28]
//   0x00766c: aa0003f3  mov      x19, x0
//   0x007670: f9000fe8  str      x8, [sp, #0x18]
//   0x007674: 910003e8  mov      x8, sp
//   0x007678: 97fffeba  bl       #0x7160
//   0x00767c: f94003e8  ldr      x8, [sp]
//   0x007680: b4000068  cbz      x8, #0x768c
//   0x007684: b9401113  ldr      w19, [x8, #0x10]
//   0x007688: 14000006  b        #0x76a0
//   0x00768c: b0000241  adrp     x1, #0x50000
//   0x007690: 9111b021  add      x1, x1, #0x46c
uint64_t fde_0052_sub_007654(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9401113ULL) + (x2 ^ 0x007654ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x007654: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x007658: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00765c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x007660: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x007664: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x007668: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00766c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x007670: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x007674: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFEBAULL; // 0x007678: bl #0x7160
    return acc;
}

// [EN] Reconstructed FDE #0053 @ 0x0076e4..0x007774 (144 bytes)
// [VN] Phục dựng FDE #0053 tại 0x0076e4..0x007774 (144 byte)
//   0x0076e4: d10103ff  sub      sp, sp, #0x40
//   0x0076e8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0076ec: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0076f0: 9100c3fd  add      x29, sp, #0x30
//   0x0076f4: d53bd054  mrs      x20, tpidr_el0
//   0x0076f8: f9401688  ldr      x8, [x20, #0x28]
//   0x0076fc: aa0003f3  mov      x19, x0
//   0x007700: f9000fe8  str      x8, [sp, #0x18]
//   0x007704: 910003e8  mov      x8, sp
//   0x007708: 97fffe96  bl       #0x7160
//   0x00770c: f94003e8  ldr      x8, [sp]
//   0x007710: b4000068  cbz      x8, #0x771c
//   0x007714: b9401513  ldr      w19, [x8, #0x14]
//   0x007718: 14000006  b        #0x7730
//   0x00771c: b0000241  adrp     x1, #0x50000
//   0x007720: 9111b021  add      x1, x1, #0x46c
uint64_t fde_0053_sub_0076e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9401513ULL) + (x2 ^ 0x0076E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0076e4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0076e8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0076ec: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0076f0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0076f4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0076f8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0076fc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x007700: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x007704: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE96ULL; // 0x007708: bl #0x7160
    return acc;
}

// [EN] Reconstructed FDE #0054 @ 0x007774..0x007804 (144 bytes)
// [VN] Phục dựng FDE #0054 tại 0x007774..0x007804 (144 byte)
//   0x007774: d10103ff  sub      sp, sp, #0x40
//   0x007778: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00777c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x007780: 9100c3fd  add      x29, sp, #0x30
//   0x007784: d53bd054  mrs      x20, tpidr_el0
//   0x007788: f9401688  ldr      x8, [x20, #0x28]
//   0x00778c: aa0003f3  mov      x19, x0
//   0x007790: f9000fe8  str      x8, [sp, #0x18]
//   0x007794: 910003e8  mov      x8, sp
//   0x007798: 97fffe72  bl       #0x7160
//   0x00779c: f94003e8  ldr      x8, [sp]
//   0x0077a0: b4000068  cbz      x8, #0x77ac
//   0x0077a4: b9401913  ldr      w19, [x8, #0x18]
//   0x0077a8: 14000006  b        #0x77c0
//   0x0077ac: b0000241  adrp     x1, #0x50000
//   0x0077b0: 9111b021  add      x1, x1, #0x46c
uint64_t fde_0054_sub_007774(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9401913ULL) + (x2 ^ 0x007774ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x007774: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x007778: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00777c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x007780: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x007784: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x007788: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00778c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x007790: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x007794: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE72ULL; // 0x007798: bl #0x7160
    return acc;
}

// [EN] Reconstructed FDE #0055 @ 0x007804..0x007894 (144 bytes)
// [VN] Phục dựng FDE #0055 tại 0x007804..0x007894 (144 byte)
//   0x007804: d10103ff  sub      sp, sp, #0x40
//   0x007808: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00780c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x007810: 9100c3fd  add      x29, sp, #0x30
//   0x007814: d53bd054  mrs      x20, tpidr_el0
//   0x007818: f9401688  ldr      x8, [x20, #0x28]
//   0x00781c: aa0003f3  mov      x19, x0
//   0x007820: f9000fe8  str      x8, [sp, #0x18]
//   0x007824: 910003e8  mov      x8, sp
//   0x007828: 97fffe4e  bl       #0x7160
//   0x00782c: f94003e8  ldr      x8, [sp]
//   0x007830: b4000068  cbz      x8, #0x783c
//   0x007834: b9402113  ldr      w19, [x8, #0x20]
//   0x007838: 14000006  b        #0x7850
//   0x00783c: b0000241  adrp     x1, #0x50000
//   0x007840: 9111b021  add      x1, x1, #0x46c
uint64_t fde_0055_sub_007804(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9402113ULL) + (x2 ^ 0x007804ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x007804: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x007808: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00780c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x007810: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x007814: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x007818: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00781c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x007820: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x007824: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE4EULL; // 0x007828: bl #0x7160
    return acc;
}

// [EN] Reconstructed FDE #0056 @ 0x007894..0x007924 (144 bytes)
// [VN] Phục dựng FDE #0056 tại 0x007894..0x007924 (144 byte)
//   0x007894: d10103ff  sub      sp, sp, #0x40
//   0x007898: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00789c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0078a0: 9100c3fd  add      x29, sp, #0x30
//   0x0078a4: d53bd054  mrs      x20, tpidr_el0
//   0x0078a8: f9401688  ldr      x8, [x20, #0x28]
//   0x0078ac: aa0003f3  mov      x19, x0
//   0x0078b0: f9000fe8  str      x8, [sp, #0x18]
//   0x0078b4: 910003e8  mov      x8, sp
//   0x0078b8: 97fffe2a  bl       #0x7160
//   0x0078bc: f94003e8  ldr      x8, [sp]
//   0x0078c0: b4000068  cbz      x8, #0x78cc
//   0x0078c4: b9401d13  ldr      w19, [x8, #0x1c]
//   0x0078c8: 14000006  b        #0x78e0
//   0x0078cc: b0000241  adrp     x1, #0x50000
//   0x0078d0: 9111b021  add      x1, x1, #0x46c
uint64_t fde_0056_sub_007894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9401D13ULL) + (x2 ^ 0x007894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x007894: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x007898: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00789c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0078a0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0078a4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0078a8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0078ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0078b0: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x0078b4: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFE2AULL; // 0x0078b8: bl #0x7160
    return acc;
}

// [EN] Reconstructed FDE #0057 @ 0x007924..0x0079fc (216 bytes)
// [VN] Phục dựng FDE #0057 tại 0x007924..0x0079fc (216 byte)
//   0x007924: d10143ff  sub      sp, sp, #0x50
//   0x007928: f90013f5  str      x21, [sp, #0x20]
//   0x00792c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x007930: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x007934: 910103fd  add      x29, sp, #0x40
//   0x007938: d53bd055  mrs      x21, tpidr_el0
//   0x00793c: f94016a8  ldr      x8, [x21, #0x28]
//   0x007940: aa0003f3  mov      x19, x0
//   0x007944: f9000fe8  str      x8, [sp, #0x18]
//   0x007948: 910003e8  mov      x8, sp
//   0x00794c: 97fffe05  bl       #0x7160
//   0x007950: f94003e8  ldr      x8, [sp]
//   0x007954: b4000248  cbz      x8, #0x799c
//   0x007958: f9400269  ldr      x9, [x19]
//   0x00795c: b9401901  ldr      w1, [x8, #0x18]
//   0x007960: f942cd28  ldr      x8, [x9, #0x598]
uint64_t fde_0057_sub_007924(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xB4000248ULL) + (x2 ^ 0x007924ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x007924: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x007928: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00792c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x007930: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x007934: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x007938: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x00793c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x007940: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x007944: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x007948: mov x8, sp
    return acc;
}

// [EN] Reconstructed FDE #0058 @ 0x0079fc..0x007c84 (648 bytes)
// [VN] Phục dựng FDE #0058 tại 0x0079fc..0x007c84 (648 byte)
//   0x0079fc: d10303ff  sub      sp, sp, #0xc0
//   0x007a00: f90043f7  str      x23, [sp, #0x80]
//   0x007a04: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x007a08: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x007a0c: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x007a10: 9102c3fd  add      x29, sp, #0xb0
//   0x007a14: d53bd056  mrs      x22, tpidr_el0
//   0x007a18: f94016c8  ldr      x8, [x22, #0x28]
//   0x007a1c: 2a0203f3  mov      w19, w2
//   0x007a20: aa0003f4  mov      x20, x0
//   0x007a24: f81c83a8  stur     x8, [x29, #-0x38]
//   0x007a28: 910023e8  add      x8, sp, #8
//   0x007a2c: 97fffdcd  bl       #0x7160
//   0x007a30: f94007e8  ldr      x8, [sp, #8]
//   0x007a34: b4000588  cbz      x8, #0x7ae4
//   0x007a38: 6f00e400  movi     v0.2d, #0000000000000000
uint64_t fde_0058_sub_0079fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0x97FFFDCDULL) + (x2 ^ 0x0079FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0079fc: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90043F7ULL; // 0x007a00: str x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x007a04: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x007a08: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x007a0c: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x007a10: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x007a14: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x007a18: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x007a1c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x007a20: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0059 @ 0x007c84..0x007d20 (156 bytes)
// [VN] Phục dựng FDE #0059 tại 0x007c84..0x007d20 (156 byte)
//   0x007c84: d10103ff  sub      sp, sp, #0x40
//   0x007c88: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x007c8c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x007c90: 9100c3fd  add      x29, sp, #0x30
//   0x007c94: d53bd054  mrs      x20, tpidr_el0
//   0x007c98: f9401688  ldr      x8, [x20, #0x28]
//   0x007c9c: aa0003f3  mov      x19, x0
//   0x007ca0: f9000fe8  str      x8, [sp, #0x18]
//   0x007ca4: 910003e8  mov      x8, sp
//   0x007ca8: 97fffd2e  bl       #0x7160
//   0x007cac: f94003e8  ldr      x8, [sp]
//   0x007cb0: b40000c8  cbz      x8, #0x7cc8
//   0x007cb4: f9400108  ldr      x8, [x8]
//   0x007cb8: b9402109  ldr      w9, [x8, #0x20]
//   0x007cbc: b9401908  ldr      w8, [x8, #0x18]
//   0x007cc0: 4b080133  sub      w19, w9, w8
uint64_t fde_0059_sub_007c84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x007C84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x007c84: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x007c88: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x007c8c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x007c90: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x007c94: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x007c98: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x007c9c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x007ca0: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E8ULL; // 0x007ca4: mov x8, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFD2EULL; // 0x007ca8: bl #0x7160
    return acc;
}

// [EN] Reconstructed FDE #0060 @ 0x007d20..0x007e2c (268 bytes)
// [VN] Phục dựng FDE #0060 tại 0x007d20..0x007e2c (268 byte)
//   0x007d20: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x007d24: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x007d28: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x007d2c: 910083fd  add      x29, sp, #0x20
//   0x007d30: f9400008  ldr      x8, [x0]
//   0x007d34: aa0003f3  mov      x19, x0
//   0x007d38: aa0103f4  mov      x20, x1
//   0x007d3c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x007d40: d63f0100  blr      x8
//   0x007d44: f9400268  ldr      x8, [x19]
//   0x007d48: b00002f6  adrp     x22, #0x64000
//   0x007d4c: f941eac2  ldr      x2, [x22, #0x3d0]
//   0x007d50: aa1303e0  mov      x0, x19
//   0x007d54: f9419508  ldr      x8, [x8, #0x328]
//   0x007d58: aa1403e1  mov      x1, x20
//   0x007d5c: d63f0100  blr      x8
uint64_t fde_0060_sub_007d20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x007D20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x007d20: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x007d24: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x007d28: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x007d2c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x007d30: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x007d34: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x007d38: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x007d3c: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x007d40: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x007d44: ldr x8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0061 @ 0x007e2c..0x007e30 (4 bytes)
// [VN] Phục dựng FDE #0061 tại 0x007e2c..0x007e30 (4 byte)
//   0x007e2c: 17ffffbd  b        #0x7d20
uint64_t fde_0061_sub_007e2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFFBDULL) + (x1 ^ 0x17FFFFBDULL) + (x2 ^ 0x007E2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFBDULL; // 0x007e2c: b #0x7d20
    return acc;
}

// [EN] Reconstructed FDE #0062 @ 0x007e30..0x00846c (1596 bytes)
// [VN] Phục dựng FDE #0062 tại 0x007e30..0x00846c (1596 byte)
//   0x007e30: d10603ff  sub      sp, sp, #0x180
//   0x007e34: a9126ffc  stp      x28, x27, [sp, #0x120]
//   0x007e38: a91367fa  stp      x26, x25, [sp, #0x130]
//   0x007e3c: a9145ff8  stp      x24, x23, [sp, #0x140]
//   0x007e40: a91557f6  stp      x22, x21, [sp, #0x150]
//   0x007e44: a9164ff4  stp      x20, x19, [sp, #0x160]
//   0x007e48: a9177bfd  stp      x29, x30, [sp, #0x170]
//   0x007e4c: 9105c3fd  add      x29, sp, #0x170
//   0x007e50: d53bd05b  mrs      x27, tpidr_el0
//   0x007e54: f9401768  ldr      x8, [x27, #0x28]
//   0x007e58: aa0403f6  mov      x22, x4
//   0x007e5c: 2a0303f7  mov      w23, w3
//   0x007e60: 2a0203f8  mov      w24, w2
//   0x007e64: f81a03a8  stur     x8, [x29, #-0x60]
//   0x007e68: f9400008  ldr      x8, [x0]
//   0x007e6c: aa0003f3  mov      x19, x0
uint64_t fde_0062_sub_007e30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10603FFULL) + (x1 ^ 0x2A0203F8ULL) + (x2 ^ 0x007E30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10603FFULL; // 0x007e30: sub sp, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xA9126FFCULL; // 0x007e34: stp x28, x27, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91367FAULL; // 0x007e38: stp x26, x25, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9145FF8ULL; // 0x007e3c: stp x24, x23, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91557F6ULL; // 0x007e40: stp x22, x21, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9164FF4ULL; // 0x007e44: stp x20, x19, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9177BFDULL; // 0x007e48: stp x29, x30, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x9105C3FDULL; // 0x007e4c: add x29, sp, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05BULL; // 0x007e50: mrs x27, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401768ULL; // 0x007e54: ldr x8, [x27, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0063 @ 0x00846c..0x008624 (440 bytes)
// [VN] Phục dựng FDE #0063 tại 0x00846c..0x008624 (440 byte)
//   0x00846c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x008470: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x008474: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008478: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00847c: 9100c3fd  add      x29, sp, #0x30
//   0x008480: f9400008  ldr      x8, [x0]
//   0x008484: aa0003f3  mov      x19, x0
//   0x008488: aa0103f4  mov      x20, x1
//   0x00848c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x008490: d63f0100  blr      x8
//   0x008494: f9400268  ldr      x8, [x19]
//   0x008498: 900002e9  adrp     x9, #0x64000
//   0x00849c: f941f522  ldr      x2, [x9, #0x3e8]
//   0x0084a0: f9419508  ldr      x8, [x8, #0x328]
//   0x0084a4: aa1303e0  mov      x0, x19
//   0x0084a8: aa1403e1  mov      x1, x20
uint64_t fde_0063_sub_00846c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x00846CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x00846c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x008470: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x008474: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x008478: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00847c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x008480: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x008484: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x008488: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x00848c: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x008490: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0064 @ 0x008624..0x0087dc (440 bytes)
// [VN] Phục dựng FDE #0064 tại 0x008624..0x0087dc (440 byte)
//   0x008624: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x008628: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00862c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008630: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008634: 9100c3fd  add      x29, sp, #0x30
//   0x008638: f9400008  ldr      x8, [x0]
//   0x00863c: aa0003f3  mov      x19, x0
//   0x008640: aa0103f4  mov      x20, x1
//   0x008644: f9436508  ldr      x8, [x8, #0x6c8]
//   0x008648: d63f0100  blr      x8
//   0x00864c: f9400268  ldr      x8, [x19]
//   0x008650: 900002e9  adrp     x9, #0x64000
//   0x008654: f941f522  ldr      x2, [x9, #0x3e8]
//   0x008658: f9419508  ldr      x8, [x8, #0x328]
//   0x00865c: aa1303e0  mov      x0, x19
//   0x008660: aa1403e1  mov      x1, x20
uint64_t fde_0064_sub_008624(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x008624ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x008624: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x008628: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00862c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x008630: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x008634: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x008638: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00863c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x008640: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x008644: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x008648: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0065 @ 0x0087dc..0x008994 (440 bytes)
// [VN] Phục dựng FDE #0065 tại 0x0087dc..0x008994 (440 byte)
//   0x0087dc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0087e0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0087e4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0087e8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0087ec: 9100c3fd  add      x29, sp, #0x30
//   0x0087f0: f9400008  ldr      x8, [x0]
//   0x0087f4: aa0003f3  mov      x19, x0
//   0x0087f8: aa0103f4  mov      x20, x1
//   0x0087fc: f9436508  ldr      x8, [x8, #0x6c8]
//   0x008800: d63f0100  blr      x8
//   0x008804: f9400268  ldr      x8, [x19]
//   0x008808: 900002e9  adrp     x9, #0x64000
//   0x00880c: f941f522  ldr      x2, [x9, #0x3e8]
//   0x008810: f9419508  ldr      x8, [x8, #0x328]
//   0x008814: aa1303e0  mov      x0, x19
//   0x008818: aa1403e1  mov      x1, x20
uint64_t fde_0065_sub_0087dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x0087DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0087dc: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0087e0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0087e4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0087e8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0087ec: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0087f0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0087f4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0087f8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x0087fc: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x008800: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0066 @ 0x008994..0x008b4c (440 bytes)
// [VN] Phục dựng FDE #0066 tại 0x008994..0x008b4c (440 byte)
//   0x008994: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x008998: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00899c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0089a0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0089a4: 9100c3fd  add      x29, sp, #0x30
//   0x0089a8: f9400008  ldr      x8, [x0]
//   0x0089ac: aa0003f3  mov      x19, x0
//   0x0089b0: aa0103f4  mov      x20, x1
//   0x0089b4: f9436508  ldr      x8, [x8, #0x6c8]
//   0x0089b8: d63f0100  blr      x8
//   0x0089bc: f9400268  ldr      x8, [x19]
//   0x0089c0: 900002e9  adrp     x9, #0x64000
//   0x0089c4: f941f522  ldr      x2, [x9, #0x3e8]
//   0x0089c8: f9419508  ldr      x8, [x8, #0x328]
//   0x0089cc: aa1303e0  mov      x0, x19
//   0x0089d0: aa1403e1  mov      x1, x20
uint64_t fde_0066_sub_008994(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x008994ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x008994: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x008998: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00899c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0089a0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0089a4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0089a8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0089ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x0089b0: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x0089b4: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0089b8: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0067 @ 0x008b4c..0x008d04 (440 bytes)
// [VN] Phục dựng FDE #0067 tại 0x008b4c..0x008d04 (440 byte)
//   0x008b4c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x008b50: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x008b54: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008b58: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008b5c: 9100c3fd  add      x29, sp, #0x30
//   0x008b60: f9400008  ldr      x8, [x0]
//   0x008b64: aa0003f3  mov      x19, x0
//   0x008b68: aa0103f4  mov      x20, x1
//   0x008b6c: f9436508  ldr      x8, [x8, #0x6c8]
//   0x008b70: d63f0100  blr      x8
//   0x008b74: f9400268  ldr      x8, [x19]
//   0x008b78: 900002e9  adrp     x9, #0x64000
//   0x008b7c: f941f522  ldr      x2, [x9, #0x3e8]
//   0x008b80: f9419508  ldr      x8, [x8, #0x328]
//   0x008b84: aa1303e0  mov      x0, x19
//   0x008b88: aa1403e1  mov      x1, x20
uint64_t fde_0067_sub_008b4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x008B4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x008b4c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x008b50: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x008b54: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x008b58: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x008b5c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x008b60: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x008b64: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x008b68: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x008b6c: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x008b70: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0068 @ 0x008d04..0x008ebc (440 bytes)
// [VN] Phục dựng FDE #0068 tại 0x008d04..0x008ebc (440 byte)
//   0x008d04: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x008d08: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x008d0c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008d10: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008d14: 9100c3fd  add      x29, sp, #0x30
//   0x008d18: f9400008  ldr      x8, [x0]
//   0x008d1c: aa0003f3  mov      x19, x0
//   0x008d20: aa0103f4  mov      x20, x1
//   0x008d24: f9436508  ldr      x8, [x8, #0x6c8]
//   0x008d28: d63f0100  blr      x8
//   0x008d2c: f9400268  ldr      x8, [x19]
//   0x008d30: 900002e9  adrp     x9, #0x64000
//   0x008d34: f941f522  ldr      x2, [x9, #0x3e8]
//   0x008d38: f9419508  ldr      x8, [x8, #0x328]
//   0x008d3c: aa1303e0  mov      x0, x19
//   0x008d40: aa1403e1  mov      x1, x20
uint64_t fde_0068_sub_008d04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x008D04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x008d04: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x008d08: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x008d0c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x008d10: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x008d14: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x008d18: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x008d1c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x008d20: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x008d24: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x008d28: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0069 @ 0x008ebc..0x009074 (440 bytes)
// [VN] Phục dựng FDE #0069 tại 0x008ebc..0x009074 (440 byte)
//   0x008ebc: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x008ec0: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x008ec4: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x008ec8: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x008ecc: 9100c3fd  add      x29, sp, #0x30
//   0x008ed0: f9400008  ldr      x8, [x0]
//   0x008ed4: aa0003f3  mov      x19, x0
//   0x008ed8: aa0103f4  mov      x20, x1
//   0x008edc: f9436508  ldr      x8, [x8, #0x6c8]
//   0x008ee0: d63f0100  blr      x8
//   0x008ee4: f9400268  ldr      x8, [x19]
//   0x008ee8: 900002e9  adrp     x9, #0x64000
//   0x008eec: f941f522  ldr      x2, [x9, #0x3e8]
//   0x008ef0: f9419508  ldr      x8, [x8, #0x328]
//   0x008ef4: aa1303e0  mov      x0, x19
//   0x008ef8: aa1403e1  mov      x1, x20
uint64_t fde_0069_sub_008ebc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xF941F522ULL) + (x2 ^ 0x008EBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x008ebc: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x008ec0: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x008ec4: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x008ec8: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x008ecc: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x008ed0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x008ed4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x008ed8: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x008edc: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x008ee0: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0070 @ 0x009074..0x009170 (252 bytes)
// [VN] Phục dựng FDE #0070 tại 0x009074..0x009170 (252 byte)
//   0x009074: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x009078: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00907c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x009080: 910083fd  add      x29, sp, #0x20
//   0x009084: f9400008  ldr      x8, [x0]
//   0x009088: aa0003f3  mov      x19, x0
//   0x00908c: aa0103f4  mov      x20, x1
//   0x009090: f9436508  ldr      x8, [x8, #0x6c8]
//   0x009094: d63f0100  blr      x8
//   0x009098: f9400268  ldr      x8, [x19]
//   0x00909c: f00002d6  adrp     x22, #0x64000
//   0x0090a0: f941f6c2  ldr      x2, [x22, #0x3e8]
//   0x0090a4: aa1303e0  mov      x0, x19
//   0x0090a8: f9419508  ldr      x8, [x8, #0x328]
//   0x0090ac: aa1403e1  mov      x1, x20
//   0x0090b0: d63f0100  blr      x8
uint64_t fde_0070_sub_009074(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x009074ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x009074: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x009078: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00907c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x009080: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x009084: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009088: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00908c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9436508ULL; // 0x009090: ldr x8, [x8, #0x6c8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x009094: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x009098: ldr x8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0071 @ 0x009170..0x009174 (4 bytes)
// [VN] Phục dựng FDE #0071 tại 0x009170..0x009174 (4 byte)
//   0x009170: 17ffffc1  b        #0x9074
uint64_t fde_0071_sub_009170(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFFC1ULL) + (x1 ^ 0x17FFFFC1ULL) + (x2 ^ 0x009170ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFC1ULL; // 0x009170: b #0x9074
    return acc;
}

// [EN] Reconstructed FDE #0072 @ 0x009174..0x0092b4 (320 bytes)
// [VN] Phục dựng FDE #0072 tại 0x009174..0x0092b4 (320 byte)
//   0x009174: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x009178: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00917c: 910043fd  add      x29, sp, #0x10
//   0x009180: d0000221  adrp     x1, #0x4f000
//   0x009184: 91362c21  add      x1, x1, #0xd8b
//   0x009188: aa0003f3  mov      x19, x0
//   0x00918c: 97fff6a3  bl       #0x6c18
//   0x009190: f00002d4  adrp     x20, #0x64000
//   0x009194: f901e280  str      x0, [x20, #0x3c0]
//   0x009198: b4000860  cbz      x0, #0x92a4
//   0x00919c: f0000222  adrp     x2, #0x50000
//   0x0091a0: d0000223  adrp     x3, #0x4f000
//   0x0091a4: aa0003e1  mov      x1, x0
//   0x0091a8: 91152042  add      x2, x2, #0x548
//   0x0091ac: 912f5c63  add      x3, x3, #0xbd7
//   0x0091b0: aa1303e0  mov      x0, x19
uint64_t fde_0072_sub_009174(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x009174ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x009174: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x009178: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00917c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000221ULL; // 0x009180: adrp x1, #0x4f000
    acc = (acc * 0x100000001B3ULL) ^ 0x91362C21ULL; // 0x009184: add x1, x1, #0xd8b
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009188: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF6A3ULL; // 0x00918c: bl #0x6c18
    acc = (acc * 0x100000001B3ULL) ^ 0xF00002D4ULL; // 0x009190: adrp x20, #0x64000
    acc = (acc * 0x100000001B3ULL) ^ 0xF901E280ULL; // 0x009194: str x0, [x20, #0x3c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000860ULL; // 0x009198: cbz x0, #0x92a4
    return acc;
}

// [EN] Reconstructed FDE #0073 @ 0x0092b4..0x009304 (80 bytes)
// [VN] Phục dựng FDE #0073 tại 0x0092b4..0x009304 (80 byte)
//   0x0092b4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0092b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0092bc: 910043fd  add      x29, sp, #0x10
//   0x0092c0: aa0003f3  mov      x19, x0
//   0x0092c4: f9400c00  ldr      x0, [x0, #0x18]
//   0x0092c8: d00002c8  adrp     x8, #0x63000
//   0x0092cc: 910b2108  add      x8, x8, #0x2c8
//   0x0092d0: f9000268  str      x8, [x19]
//   0x0092d4: b4000060  cbz      x0, #0x92e0
//   0x0092d8: f9001260  str      x0, [x19, #0x20]
//   0x0092dc: 97ffead5  bl       #0x3e30
//   0x0092e0: f9400660  ldr      x0, [x19, #8]
//   0x0092e4: f900067f  str      xzr, [x19, #8]
//   0x0092e8: b4000060  cbz      x0, #0x92f4
//   0x0092ec: f9400a68  ldr      x8, [x19, #0x10]
//   0x0092f0: d63f0100  blr      x8
uint64_t fde_0073_sub_0092b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF900067FULL) + (x2 ^ 0x0092B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0092b4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0092b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0092bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0092c0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x0092c4: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00002C8ULL; // 0x0092c8: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x910B2108ULL; // 0x0092cc: add x8, x8, #0x2c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x0092d0: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x0092d4: cbz x0, #0x92e0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001260ULL; // 0x0092d8: str x0, [x19, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0074 @ 0x009304..0x009358 (84 bytes)
// [VN] Phục dựng FDE #0074 tại 0x009304..0x009358 (84 byte)
//   0x009304: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x009308: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00930c: 910043fd  add      x29, sp, #0x10
//   0x009310: aa0003f3  mov      x19, x0
//   0x009314: f9400c00  ldr      x0, [x0, #0x18]
//   0x009318: d00002c8  adrp     x8, #0x63000
//   0x00931c: 910b2108  add      x8, x8, #0x2c8
//   0x009320: f9000268  str      x8, [x19]
//   0x009324: b4000060  cbz      x0, #0x9330
//   0x009328: f9001260  str      x0, [x19, #0x20]
//   0x00932c: 97ffeac1  bl       #0x3e30
//   0x009330: f9400660  ldr      x0, [x19, #8]
//   0x009334: f900067f  str      xzr, [x19, #8]
//   0x009338: b4000060  cbz      x0, #0x9344
//   0x00933c: f9400a68  ldr      x8, [x19, #0x10]
//   0x009340: d63f0100  blr      x8
uint64_t fde_0074_sub_009304(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF900067FULL) + (x2 ^ 0x009304ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x009304: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x009308: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00930c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009310: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x009314: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xD00002C8ULL; // 0x009318: adrp x8, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0x910B2108ULL; // 0x00931c: add x8, x8, #0x2c8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000268ULL; // 0x009320: str x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x009324: cbz x0, #0x9330
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001260ULL; // 0x009328: str x0, [x19, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0075 @ 0x009358..0x009450 (248 bytes)
// [VN] Phục dựng FDE #0075 tại 0x009358..0x009450 (248 byte)
//   0x009358: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x00935c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x009360: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x009364: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x009368: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00936c: 910103fd  add      x29, sp, #0x40
//   0x009370: a9402014  ldp      x20, x8, [x0]
//   0x009374: aa0003f3  mov      x19, x0
//   0x009378: cb140115  sub      x21, x8, x20
//   0x00937c: 9342feb8  asr      x24, x21, #2
//   0x009380: 91000708  add      x8, x24, #1
//   0x009384: d37efd09  lsr      x9, x8, #0x3e
//   0x009388: b5000609  cbnz     x9, #0x9448
//   0x00938c: f9400a69  ldr      x9, [x19, #0x10]
//   0x009390: b27fefea  mov      x10, #0x1ffffffffffffffe
//   0x009394: aa0103f6  mov      x22, x1
uint64_t fde_0075_sub_009358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB5000609ULL) + (x2 ^ 0x009358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x009358: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00935c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x009360: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x009364: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x009368: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00936c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402014ULL; // 0x009370: ldp x20, x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009374: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xCB140115ULL; // 0x009378: sub x21, x8, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x9342FEB8ULL; // 0x00937c: asr x24, x21, #2
    return acc;
}

// [EN] Reconstructed FDE #0076 @ 0x009450..0x0095ac (348 bytes)
// [VN] Phục dựng FDE #0076 tại 0x009450..0x0095ac (348 byte)
//   0x009450: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x009454: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x009458: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00945c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x009460: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x009464: 910103fd  add      x29, sp, #0x40
//   0x009468: f9400808  ldr      x8, [x0, #0x10]
//   0x00946c: f9400017  ldr      x23, [x0]
//   0x009470: cb010055  sub      x21, x2, x1
//   0x009474: 9342feb9  asr      x25, x21, #2
//   0x009478: aa0103f4  mov      x20, x1
//   0x00947c: cb170109  sub      x9, x8, x23
//   0x009480: aa0003f3  mov      x19, x0
//   0x009484: eb890b3f  cmp      x25, x9, asr #2
//   0x009488: 540002a9  b.ls     #0x94dc
//   0x00948c: b40000f7  cbz      x23, #0x94a8
uint64_t fde_0076_sub_009450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x009450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x009450: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x009454: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x009458: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00945c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x009460: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x009464: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x009468: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400017ULL; // 0x00946c: ldr x23, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010055ULL; // 0x009470: sub x21, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9342FEB9ULL; // 0x009474: asr x25, x21, #2
    return acc;
}

// [EN] Reconstructed FDE #0077 @ 0x0095ac..0x0095d0 (36 bytes)
// [VN] Phục dựng FDE #0077 tại 0x0095ac..0x0095d0 (36 byte)
//   0x0095ac: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0095b0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0095b4: 910043fd  add      x29, sp, #0x10
//   0x0095b8: aa0003f3  mov      x19, x0
//   0x0095bc: 97ffea65  bl       #0x3f50
//   0x0095c0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0095c4: aa1303e0  mov      x0, x19
//   0x0095c8: f84207f3  ldr      x19, [sp], #0x20
//   0x0095cc: 17ffea19  b        #0x3e30
uint64_t fde_0077_sub_0095ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFEA19ULL) + (x2 ^ 0x0095ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0095ac: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0095b0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0095b4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0095b8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFEA65ULL; // 0x0095bc: bl #0x3f50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0095c0: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0095c4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x0095c8: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEA19ULL; // 0x0095cc: b #0x3e30
    return acc;
}

// [EN] Reconstructed FDE #0078 @ 0x0095d0..0x0095e8 (24 bytes)
// [VN] Phục dựng FDE #0078 tại 0x0095d0..0x0095e8 (24 byte)
//   0x0095d0: f9400c00  ldr      x0, [x0, #0x18]
//   0x0095d4: b4000080  cbz      x0, #0x95e4
//   0x0095d8: f9400008  ldr      x8, [x0]
//   0x0095dc: f9400501  ldr      x1, [x8, #8]
//   0x0095e0: d61f0020  br       x1
//   0x0095e4: d65f03c0  ret      
uint64_t fde_0078_sub_0095d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400C00ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0095D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C00ULL; // 0x0095d0: ldr x0, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x0095d4: cbz x0, #0x95e4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0095d8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400501ULL; // 0x0095dc: ldr x1, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x0095e0: br x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0095e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0079 @ 0x0095e8..0x0095ec (4 bytes)
// [VN] Phục dựng FDE #0079 tại 0x0095e8..0x0095ec (4 byte)
//   0x0095e8: 17ffea12  b        #0x3e30
uint64_t fde_0079_sub_0095e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFEA12ULL) + (x1 ^ 0x17FFEA12ULL) + (x2 ^ 0x0095E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEA12ULL; // 0x0095e8: b #0x3e30
    return acc;
}

// [EN] Reconstructed FDE #0080 @ 0x0095ec..0x0096fc (272 bytes)
// [VN] Phục dựng FDE #0080 tại 0x0095ec..0x0096fc (272 byte)
//   0x0095ec: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0095f0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0095f4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0095f8: 910083fd  add      x29, sp, #0x20
//   0x0095fc: aa0203f4  mov      x20, x2
//   0x009600: aa0003f3  mov      x19, x0
//   0x009604: 7101403f  cmp      w1, #0x50
//   0x009608: f900041f  str      xzr, [x0, #8]
//   0x00960c: 54000160  b.eq     #0x9638
//   0x009610: f0000229  adrp     x9, #0x50000
//   0x009614: f9400268  ldr      x8, [x19]
//   0x009618: fd440920  ldr      d0, [x9, #0x810]
//   0x00961c: aa1303e0  mov      x0, x19
//   0x009620: fd001500  str      d0, [x8, #0x28]
//   0x009624: f9400268  ldr      x8, [x19]
//   0x009628: b9003101  str      w1, [x8, #0x30]
uint64_t fde_0080_sub_0095ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x0095ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0095ec: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0095f0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0095f4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0095f8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F4ULL; // 0x0095fc: mov x20, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009600: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7101403FULL; // 0x009604: cmp w1, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF900041FULL; // 0x009608: str xzr, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x54000160ULL; // 0x00960c: b.eq #0x9638
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000229ULL; // 0x009610: adrp x9, #0x50000
    return acc;
}

// [EN] Reconstructed FDE #0081 @ 0x0096fc..0x009700 (4 bytes)
// [VN] Phục dựng FDE #0081 tại 0x0096fc..0x009700 (4 byte)
//   0x0096fc: 14001026  b        #0xd794
uint64_t fde_0081_sub_0096fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14001026ULL) + (x1 ^ 0x14001026ULL) + (x2 ^ 0x0096FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14001026ULL; // 0x0096fc: b #0xd794
    return acc;
}

// [EN] Reconstructed FDE #0082 @ 0x009700..0x009794 (148 bytes)
// [VN] Phục dựng FDE #0082 tại 0x009700..0x009794 (148 byte)
//   0x009700: f9403808  ldr      x8, [x0, #0x70]
//   0x009704: b4000048  cbz      x8, #0x970c
//   0x009708: b9008101  str      w1, [x8, #0x80]
//   0x00970c: f9403c08  ldr      x8, [x0, #0x78]
//   0x009710: b4000048  cbz      x8, #0x9718
//   0x009714: b9008101  str      w1, [x8, #0x80]
//   0x009718: f9404008  ldr      x8, [x0, #0x80]
//   0x00971c: b4000048  cbz      x8, #0x9724
//   0x009720: b9008101  str      w1, [x8, #0x80]
//   0x009724: f9404408  ldr      x8, [x0, #0x88]
//   0x009728: b4000048  cbz      x8, #0x9730
//   0x00972c: b9008101  str      w1, [x8, #0x80]
//   0x009730: f9405008  ldr      x8, [x0, #0xa0]
//   0x009734: b4000048  cbz      x8, #0x973c
//   0x009738: b9011501  str      w1, [x8, #0x114]
//   0x00973c: f9406008  ldr      x8, [x0, #0xc0]
uint64_t fde_0082_sub_009700(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9403808ULL) + (x1 ^ 0xF9405008ULL) + (x2 ^ 0x009700ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403808ULL; // 0x009700: ldr x8, [x0, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000048ULL; // 0x009704: cbz x8, #0x970c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9008101ULL; // 0x009708: str w1, [x8, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403C08ULL; // 0x00970c: ldr x8, [x0, #0x78]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000048ULL; // 0x009710: cbz x8, #0x9718
    acc = (acc * 0x100000001B3ULL) ^ 0xB9008101ULL; // 0x009714: str w1, [x8, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404008ULL; // 0x009718: ldr x8, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000048ULL; // 0x00971c: cbz x8, #0x9724
    acc = (acc * 0x100000001B3ULL) ^ 0xB9008101ULL; // 0x009720: str w1, [x8, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404408ULL; // 0x009724: ldr x8, [x0, #0x88]
    return acc;
}

// [EN] Reconstructed FDE #0083 @ 0x009794..0x0098f4 (352 bytes)
// [VN] Phục dựng FDE #0083 tại 0x009794..0x0098f4 (352 byte)
//   0x009794: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x009798: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00979c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0097a0: 910083fd  add      x29, sp, #0x20
//   0x0097a4: b9402408  ldr      w8, [x0, #0x24]
//   0x0097a8: aa0003f3  mov      x19, x0
//   0x0097ac: 51019509  sub      w9, w8, #0x65
//   0x0097b0: 7100093f  cmp      w9, #2
//   0x0097b4: 540001c2  b.hs     #0x97ec
//   0x0097b8: b9415668  ldr      w8, [x19, #0x154]
//   0x0097bc: b9403669  ldr      w9, [x19, #0x34]
//   0x0097c0: 6b09011f  cmp      w8, w9
//   0x0097c4: 540000e2  b.hs     #0x97e0
//   0x0097c8: f9400268  ldr      x8, [x19]
//   0x0097cc: 528008aa  mov      w10, #0x45
//   0x0097d0: aa1303e0  mov      x0, x19
uint64_t fde_0083_sub_009794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x540000E2ULL) + (x2 ^ 0x009794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x009794: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x009798: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00979c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0097a0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402408ULL; // 0x0097a4: ldr w8, [x0, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0097a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x51019509ULL; // 0x0097ac: sub w9, w8, #0x65
    acc = (acc * 0x100000001B3ULL) ^ 0x7100093FULL; // 0x0097b0: cmp w9, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C2ULL; // 0x0097b4: b.hs #0x97ec
    acc = (acc * 0x100000001B3ULL) ^ 0xB9415668ULL; // 0x0097b8: ldr w8, [x19, #0x154]
    return acc;
}

// [EN] Reconstructed FDE #0084 @ 0x0098f4..0x009968 (116 bytes)
// [VN] Phục dựng FDE #0084 tại 0x0098f4..0x009968 (116 byte)
//   0x0098f4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0098f8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0098fc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x009900: 910083fd  add      x29, sp, #0x20
//   0x009904: b9415409  ldr      w9, [x0, #0x154]
//   0x009908: b9402408  ldr      w8, [x0, #0x24]
//   0x00990c: 2a0203f3  mov      w19, w2
//   0x009910: aa0003f4  mov      x20, x0
//   0x009914: 2a0103f5  mov      w21, w1
//   0x009918: 35000089  cbnz     w9, #0x9928
//   0x00991c: 51019509  sub      w9, w8, #0x65
//   0x009920: 71000d3f  cmp      w9, #3
//   0x009924: 54000103  b.lo     #0x9944
//   0x009928: f9400289  ldr      x9, [x20]
//   0x00992c: 528002aa  mov      w10, #0x15
//   0x009930: aa1403e0  mov      x0, x20
uint64_t fde_0084_sub_0098f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000103ULL) + (x2 ^ 0x0098F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0098f4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0098f8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0098fc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x009900: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9415409ULL; // 0x009904: ldr w9, [x0, #0x154]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402408ULL; // 0x009908: ldr w8, [x0, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x00990c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x009910: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x009914: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x35000089ULL; // 0x009918: cbnz w9, #0x9928
    return acc;
}

// [EN] Reconstructed FDE #0085 @ 0x009968..0x009974 (12 bytes)
// [VN] Phục dựng FDE #0085 tại 0x009968..0x009974 (12 byte)
//   0x009968: f9410808  ldr      x8, [x0, #0x210]
//   0x00996c: f9401902  ldr      x2, [x8, #0x30]
//   0x009970: d61f0040  br       x2
uint64_t fde_0085_sub_009968(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9410808ULL) + (x1 ^ 0xD61F0040ULL) + (x2 ^ 0x009968ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410808ULL; // 0x009968: ldr x8, [x0, #0x210]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401902ULL; // 0x00996c: ldr x2, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x009970: br x2
    return acc;
}

// [EN] Reconstructed FDE #0086 @ 0x009974..0x009a1c (168 bytes)
// [VN] Phục dựng FDE #0086 tại 0x009974..0x009a1c (168 byte)
//   0x009974: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x009978: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00997c: 910043fd  add      x29, sp, #0x10
//   0x009980: b9402408  ldr      w8, [x0, #0x24]
//   0x009984: aa0003f3  mov      x19, x0
//   0x009988: 2a0103f4  mov      w20, w1
//   0x00998c: 7101911f  cmp      w8, #0x64
//   0x009990: 54000100  b.eq     #0x99b0
//   0x009994: f9400269  ldr      x9, [x19]
//   0x009998: 528002aa  mov      w10, #0x15
//   0x00999c: aa1303e0  mov      x0, x19
//   0x0099a0: 2905212a  stp      w10, w8, [x9, #0x28]
//   0x0099a4: f9400268  ldr      x8, [x19]
//   0x0099a8: f9400108  ldr      x8, [x8]
//   0x0099ac: d63f0100  blr      x8
//   0x0099b0: 34000094  cbz      w20, #0x99c0
uint64_t fde_0086_sub_009974(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x009974ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x009974: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x009978: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00997c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402408ULL; // 0x009980: ldr w8, [x0, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009984: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x009988: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x7101911FULL; // 0x00998c: cmp w8, #0x64
    acc = (acc * 0x100000001B3ULL) ^ 0x54000100ULL; // 0x009990: b.eq #0x99b0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400269ULL; // 0x009994: ldr x9, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x528002AAULL; // 0x009998: mov w10, #0x15
    return acc;
}

// [EN] Reconstructed FDE #0087 @ 0x009a1c..0x009b40 (292 bytes)
// [VN] Phục dựng FDE #0087 tại 0x009a1c..0x009b40 (292 byte)
//   0x009a1c: d10103ff  sub      sp, sp, #0x40
//   0x009a20: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x009a24: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x009a28: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x009a2c: 9100c3fd  add      x29, sp, #0x30
//   0x009a30: d53bd056  mrs      x22, tpidr_el0
//   0x009a34: f94016c8  ldr      x8, [x22, #0x28]
//   0x009a38: 2a0203f4  mov      w20, w2
//   0x009a3c: aa0003f3  mov      x19, x0
//   0x009a40: aa0103f5  mov      x21, x1
//   0x009a44: f90007e8  str      x8, [sp, #8]
//   0x009a48: b9402408  ldr      w8, [x0, #0x24]
//   0x009a4c: 7101951f  cmp      w8, #0x65
//   0x009a50: 54000100  b.eq     #0x9a70
//   0x009a54: f9400269  ldr      x9, [x19]
//   0x009a58: 528002aa  mov      w10, #0x15
uint64_t fde_0087_sub_009a1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x7101951FULL) + (x2 ^ 0x009A1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x009a1c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x009a20: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x009a24: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x009a28: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x009a2c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x009a30: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x009a34: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x009a38: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009a3c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x009a40: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #0088 @ 0x009b40..0x009c18 (216 bytes)
// [VN] Phục dựng FDE #0088 tại 0x009b40..0x009c18 (216 byte)
//   0x009b40: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x009b44: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x009b48: 910043fd  add      x29, sp, #0x10
//   0x009b4c: 2a1f03e1  mov      w1, wzr
//   0x009b50: aa0003f3  mov      x19, x0
//   0x009b54: 94000b4a  bl       #0xc87c
//   0x009b58: b9412268  ldr      w8, [x19, #0x120]
//   0x009b5c: 35000108  cbnz     w8, #0x9b7c
//   0x009b60: aa1303e0  mov      x0, x19
//   0x009b64: 9400296f  bl       #0x14120
//   0x009b68: aa1303e0  mov      x0, x19
//   0x009b6c: 94001702  bl       #0xf774
//   0x009b70: aa1303e0  mov      x0, x19
//   0x009b74: 2a1f03e1  mov      w1, wzr
//   0x009b78: 940014cf  bl       #0xeeb4
//   0x009b7c: aa1303e0  mov      x0, x19
uint64_t fde_0088_sub_009b40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x009B40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x009b40: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x009b44: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x009b48: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x009b4c: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009b50: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x94000B4AULL; // 0x009b54: bl #0xc87c
    acc = (acc * 0x100000001B3ULL) ^ 0xB9412268ULL; // 0x009b58: ldr w8, [x19, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x35000108ULL; // 0x009b5c: cbnz w8, #0x9b7c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x009b60: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400296FULL; // 0x009b64: bl #0x14120
    return acc;
}

// [EN] Reconstructed FDE #0089 @ 0x009c18..0x009cf0 (216 bytes)
// [VN] Phục dựng FDE #0089 tại 0x009c18..0x009cf0 (216 byte)
//   0x009c18: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x009c1c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x009c20: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x009c24: 910083fd  add      x29, sp, #0x20
//   0x009c28: f9400408  ldr      x8, [x0, #8]
//   0x009c2c: 2a0103f4  mov      w20, w1
//   0x009c30: 52800021  mov      w1, #1
//   0x009c34: 52800e02  mov      w2, #0x70
//   0x009c38: f9400108  ldr      x8, [x8]
//   0x009c3c: aa0003f3  mov      x19, x0
//   0x009c40: d63f0100  blr      x8
//   0x009c44: 90000008  adrp     x8, #0x9000
//   0x009c48: 9133c108  add      x8, x8, #0xcf0
//   0x009c4c: f900fe60  str      x0, [x19, #0x1f8]
//   0x009c50: f9000008  str      x8, [x0]
//   0x009c54: b9412268  ldr      w8, [x19, #0x120]
uint64_t fde_0089_sub_009c18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x9133C108ULL) + (x2 ^ 0x009C18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x009c18: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x009c1c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x009c20: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x009c24: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x009c28: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x009c2c: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x009c30: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800E02ULL; // 0x009c34: mov w2, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x009c38: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009c3c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0090 @ 0x009cf0..0x009d40 (80 bytes)
// [VN] Phục dựng FDE #0090 tại 0x009cf0..0x009d40 (80 byte)
//   0x009cf0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x009cf4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x009cf8: 910043fd  add      x29, sp, #0x10
//   0x009cfc: b9412008  ldr      w8, [x0, #0x120]
//   0x009d00: 350001a8  cbnz     w8, #0x9d34
//   0x009d04: f940fc14  ldr      x20, [x0, #0x1f8]
//   0x009d08: 2a0103f3  mov      w19, w1
//   0x009d0c: 340000c1  cbz      w1, #0x9d24
//   0x009d10: f9400008  ldr      x8, [x0]
//   0x009d14: 5280006a  mov      w10, #3
//   0x009d18: f9400109  ldr      x9, [x8]
//   0x009d1c: b900290a  str      w10, [x8, #0x28]
//   0x009d20: d63f0120  blr      x9
//   0x009d24: 90000008  adrp     x8, #0x9000
//   0x009d28: 91350108  add      x8, x8, #0xd40
//   0x009d2c: 29034e9f  stp      wzr, w19, [x20, #0x18]
uint64_t fde_0090_sub_009cf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD63F0120ULL) + (x2 ^ 0x009CF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x009cf0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x009cf4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x009cf8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9412008ULL; // 0x009cfc: ldr w8, [x0, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0x350001A8ULL; // 0x009d00: cbnz w8, #0x9d34
    acc = (acc * 0x100000001B3ULL) ^ 0xF940FC14ULL; // 0x009d04: ldr x20, [x0, #0x1f8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F3ULL; // 0x009d08: mov w19, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x340000C1ULL; // 0x009d0c: cbz w1, #0x9d24
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x009d10: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280006AULL; // 0x009d14: mov w10, #3
    return acc;
}

// [EN] Reconstructed FDE #0091 @ 0x009d40..0x009e50 (272 bytes)
// [VN] Phục dựng FDE #0091 tại 0x009d40..0x009e50 (272 byte)
//   0x009d40: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x009d44: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x009d48: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x009d4c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x009d50: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x009d54: 910103fd  add      x29, sp, #0x40
//   0x009d58: f940fc19  ldr      x25, [x0, #0x1f8]
//   0x009d5c: b9416c09  ldr      w9, [x0, #0x16c]
//   0x009d60: b9401328  ldr      w8, [x25, #0x10]
//   0x009d64: 6b09011f  cmp      w8, w9
//   0x009d68: 54000682  b.hs     #0x9e38
//   0x009d6c: aa1903f7  mov      x23, x25
//   0x009d70: b8414ee8  ldr      w8, [x23, #0x14]!
//   0x009d74: 2a0303f4  mov      w20, w3
//   0x009d78: aa0203f3  mov      x19, x2
//   0x009d7c: aa0003f5  mov      x21, x0
uint64_t fde_0091_sub_009d40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xB8414EE8ULL) + (x2 ^ 0x009D40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x009d40: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x009d44: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x009d48: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x009d4c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x009d50: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x009d54: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF940FC19ULL; // 0x009d58: ldr x25, [x0, #0x1f8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416C09ULL; // 0x009d5c: ldr w9, [x0, #0x16c]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401328ULL; // 0x009d60: ldr w8, [x25, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x009d64: cmp w8, w9
    return acc;
}

// [EN] Reconstructed FDE #0092 @ 0x009e50..0x009edc (140 bytes)
// [VN] Phục dựng FDE #0092 tại 0x009e50..0x009edc (140 byte)
//   0x009e50: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x009e54: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x009e58: 910043fd  add      x29, sp, #0x10
//   0x009e5c: f9400408  ldr      x8, [x0, #8]
//   0x009e60: 52800021  mov      w1, #1
//   0x009e64: 52800802  mov      w2, #0x40
//   0x009e68: aa0003f3  mov      x19, x0
//   0x009e6c: f9400108  ldr      x8, [x8]
//   0x009e70: d63f0100  blr      x8
//   0x009e74: 90000008  adrp     x8, #0x9000
//   0x009e78: b0000009  adrp     x9, #0xa000
//   0x009e7c: 913b7108  add      x8, x8, #0xedc
//   0x009e80: 912ed129  add      x9, x9, #0xbb4
//   0x009e84: 9e670100  fmov     d0, x8
//   0x009e88: d0000008  adrp     x8, #0xb000
//   0x009e8c: 9e670121  fmov     d1, x9
uint64_t fde_0092_sub_009e50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x912ED129ULL) + (x2 ^ 0x009E50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x009e50: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x009e54: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x009e58: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x009e5c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x009e60: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800802ULL; // 0x009e64: mov w2, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009e68: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x009e6c: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x009e70: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x009e74: adrp x8, #0x9000
    return acc;
}

// [EN] Reconstructed FDE #0093 @ 0x009edc..0x00aa80 (2980 bytes)
// [VN] Phục dựng FDE #0093 tại 0x009edc..0x00aa80 (2980 byte)
//   0x009edc: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x009ee0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x009ee4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x009ee8: 910083fd  add      x29, sp, #0x20
//   0x009eec: aa0003f4  mov      x20, x0
//   0x009ef0: f8428e88  ldr      x8, [x20, #0x28]!
//   0x009ef4: 52801fea  mov      w10, #0xff
//   0x009ef8: aa0003f3  mov      x19, x0
//   0x009efc: f9400109  ldr      x9, [x8]
//   0x009f00: f940f695  ldr      x21, [x20, #0x1e8]
//   0x009f04: 9100052b  add      x11, x9, #1
//   0x009f08: f900010b  str      x11, [x8]
//   0x009f0c: 3900012a  strb     w10, [x9]
//   0x009f10: f9400509  ldr      x9, [x8, #8]
//   0x009f14: f1000529  subs     x9, x9, #1
//   0x009f18: f9000509  str      x9, [x8, #8]
uint64_t fde_0093_sub_009edc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x3900012AULL) + (x2 ^ 0x009EDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x009edc: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x009ee0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x009ee4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x009ee8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x009eec: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8428E88ULL; // 0x009ef0: ldr x8, [x20, #0x28]!
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEAULL; // 0x009ef4: mov w10, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x009ef8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x009efc: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940F695ULL; // 0x009f00: ldr x21, [x20, #0x1e8]
    return acc;
}

// [EN] Reconstructed FDE #0094 @ 0x00aa80..0x00abb4 (308 bytes)
// [VN] Phục dựng FDE #0094 tại 0x00aa80..0x00abb4 (308 byte)
//   0x00aa80: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00aa84: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00aa88: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00aa8c: 910083fd  add      x29, sp, #0x20
//   0x00aa90: b9405c08  ldr      w8, [x0, #0x5c]
//   0x00aa94: aa0003f3  mov      x19, x0
//   0x00aa98: 7100051f  cmp      w8, #1
//   0x00aa9c: 540001cb  b.lt     #0xaad4
//   0x00aaa0: f9403668  ldr      x8, [x19, #0x68]
//   0x00aaa4: 2a1f03f4  mov      w20, wzr
//   0x00aaa8: 2a1f03f5  mov      w21, wzr
//   0x00aaac: 91004116  add      x22, x8, #0x10
//   0x00aab0: b84606c1  ldr      w1, [x22], #0x60
//   0x00aab4: aa1303e0  mov      x0, x19
//   0x00aab8: 940004b0  bl       #0xbd78
//   0x00aabc: b9405e68  ldr      w8, [x19, #0x5c]
uint64_t fde_0094_sub_00aa80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB84606C1ULL) + (x2 ^ 0x00AA80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00aa80: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00aa84: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00aa88: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00aa8c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405C08ULL; // 0x00aa90: ldr w8, [x0, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00aa94: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x00aa98: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001CBULL; // 0x00aa9c: b.lt #0xaad4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403668ULL; // 0x00aaa0: ldr x8, [x19, #0x68]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03F4ULL; // 0x00aaa4: mov w20, wzr
    return acc;
}

// [EN] Reconstructed FDE #0095 @ 0x00abb4..0x00b834 (3200 bytes)
// [VN] Phục dựng FDE #0095 tại 0x00abb4..0x00b834 (3200 byte)
//   0x00abb4: d102c3ff  sub      sp, sp, #0xb0
//   0x00abb8: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x00abbc: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x00abc0: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x00abc4: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x00abc8: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x00abcc: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x00abd0: 910283fd  add      x29, sp, #0xa0
//   0x00abd4: d53bd057  mrs      x23, tpidr_el0
//   0x00abd8: f94016e8  ldr      x8, [x23, #0x28]
//   0x00abdc: aa0003f3  mov      x19, x0
//   0x00abe0: f90027e8  str      x8, [sp, #0x48]
//   0x00abe4: b9412408  ldr      w8, [x0, #0x124]
//   0x00abe8: f9410816  ldr      x22, [x0, #0x210]
//   0x00abec: 340001a8  cbz      w8, #0xac20
//   0x00abf0: a902ffff  stp      xzr, xzr, [sp, #0x28]
uint64_t fde_0095_sub_00abb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0xB9412408ULL) + (x2 ^ 0x00ABB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x00abb4: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x00abb8: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x00abbc: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x00abc0: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x00abc4: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x00abc8: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x00abcc: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x00abd0: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x00abd4: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x00abd8: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0096 @ 0x00b834..0x00b8f8 (196 bytes)
// [VN] Phục dựng FDE #0096 tại 0x00b834..0x00b8f8 (196 byte)
//   0x00b834: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00b838: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00b83c: 910043fd  add      x29, sp, #0x10
//   0x00b840: f9401408  ldr      x8, [x0, #0x28]
//   0x00b844: 52801fea  mov      w10, #0xff
//   0x00b848: aa0003f3  mov      x19, x0
//   0x00b84c: f9400109  ldr      x9, [x8]
//   0x00b850: 9100052b  add      x11, x9, #1
//   0x00b854: f900010b  str      x11, [x8]
//   0x00b858: 3900012a  strb     w10, [x9]
//   0x00b85c: f9400509  ldr      x9, [x8, #8]
//   0x00b860: f1000529  subs     x9, x9, #1
//   0x00b864: f9000509  str      x9, [x8, #8]
//   0x00b868: 54000161  b.ne     #0xb894
//   0x00b86c: f9400d08  ldr      x8, [x8, #0x18]
//   0x00b870: aa1303e0  mov      x0, x19
uint64_t fde_0096_sub_00b834(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000509ULL) + (x2 ^ 0x00B834ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00b834: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00b838: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00b83c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00b840: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEAULL; // 0x00b844: mov w10, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00b848: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00b84c: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100052BULL; // 0x00b850: add x11, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900010BULL; // 0x00b854: str x11, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3900012AULL; // 0x00b858: strb w10, [x9]
    return acc;
}

// [EN] Reconstructed FDE #0097 @ 0x00b8f8..0x00bb74 (636 bytes)
// [VN] Phục dựng FDE #0097 tại 0x00b8f8..0x00bb74 (636 byte)
//   0x00b8f8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00b8fc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00b900: 910043fd  add      x29, sp, #0x10
//   0x00b904: f9401408  ldr      x8, [x0, #0x28]
//   0x00b908: 52801fea  mov      w10, #0xff
//   0x00b90c: aa0003f3  mov      x19, x0
//   0x00b910: f9400109  ldr      x9, [x8]
//   0x00b914: 9100052b  add      x11, x9, #1
//   0x00b918: f900010b  str      x11, [x8]
//   0x00b91c: 3900012a  strb     w10, [x9]
//   0x00b920: f9400509  ldr      x9, [x8, #8]
//   0x00b924: f1000529  subs     x9, x9, #1
//   0x00b928: f9000509  str      x9, [x8, #8]
//   0x00b92c: 54000161  b.ne     #0xb958
//   0x00b930: f9400d08  ldr      x8, [x8, #0x18]
//   0x00b934: aa1303e0  mov      x0, x19
uint64_t fde_0097_sub_00b8f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000509ULL) + (x2 ^ 0x00B8F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00b8f8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00b8fc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00b900: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00b904: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEAULL; // 0x00b908: mov w10, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00b90c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00b910: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100052BULL; // 0x00b914: add x11, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900010BULL; // 0x00b918: str x11, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3900012AULL; // 0x00b91c: strb w10, [x9]
    return acc;
}

// [EN] Reconstructed FDE #0098 @ 0x00bb74..0x00bd0c (408 bytes)
// [VN] Phục dựng FDE #0098 tại 0x00bb74..0x00bd0c (408 byte)
//   0x00bb74: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00bb78: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00bb7c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00bb80: 910083fd  add      x29, sp, #0x20
//   0x00bb84: 529fffc8  mov      w8, #0xfffe
//   0x00bb88: 2a0203f4  mov      w20, w2
//   0x00bb8c: 2a0103f5  mov      w21, w1
//   0x00bb90: 6b08005f  cmp      w2, w8
//   0x00bb94: aa0003f3  mov      x19, x0
//   0x00bb98: 540000e3  b.lo     #0xbbb4
//   0x00bb9c: f9400268  ldr      x8, [x19]
//   0x00bba0: 5280018a  mov      w10, #0xc
//   0x00bba4: aa1303e0  mov      x0, x19
//   0x00bba8: f9400109  ldr      x9, [x8]
//   0x00bbac: b900290a  str      w10, [x8, #0x28]
//   0x00bbb0: d63f0120  blr      x9
uint64_t fde_0098_sub_00bb74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00BB74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00bb74: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00bb78: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00bb7c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00bb80: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x529FFFC8ULL; // 0x00bb84: mov w8, #0xfffe
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x00bb88: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x00bb8c: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08005FULL; // 0x00bb90: cmp w2, w8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00bb94: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000E3ULL; // 0x00bb98: b.lo #0xbbb4
    return acc;
}

// [EN] Reconstructed FDE #0099 @ 0x00bd0c..0x00bd78 (108 bytes)
// [VN] Phục dựng FDE #0099 tại 0x00bd0c..0x00bd78 (108 byte)
//   0x00bd0c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00bd10: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00bd14: 910043fd  add      x29, sp, #0x10
//   0x00bd18: f9401408  ldr      x8, [x0, #0x28]
//   0x00bd1c: f9400109  ldr      x9, [x8]
//   0x00bd20: 9100052a  add      x10, x9, #1
//   0x00bd24: f900010a  str      x10, [x8]
//   0x00bd28: 39000121  strb     w1, [x9]
//   0x00bd2c: f9400509  ldr      x9, [x8, #8]
//   0x00bd30: f1000529  subs     x9, x9, #1
//   0x00bd34: f9000509  str      x9, [x8, #8]
//   0x00bd38: 540000a1  b.ne     #0xbd4c
//   0x00bd3c: f9400d08  ldr      x8, [x8, #0x18]
//   0x00bd40: aa0003f3  mov      x19, x0
//   0x00bd44: d63f0100  blr      x8
//   0x00bd48: 34000080  cbz      w0, #0xbd58
uint64_t fde_0099_sub_00bd0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400D08ULL) + (x2 ^ 0x00BD0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00bd0c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00bd10: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00bd14: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00bd18: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00bd1c: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100052AULL; // 0x00bd20: add x10, x9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xF900010AULL; // 0x00bd24: str x10, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000121ULL; // 0x00bd28: strb w1, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400509ULL; // 0x00bd2c: ldr x9, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF1000529ULL; // 0x00bd30: subs x9, x9, #1
    return acc;
}

// [EN] Reconstructed FDE #0100 @ 0x00bd78..0x00c06c (756 bytes)
// [VN] Phục dựng FDE #0100 tại 0x00bd78..0x00c06c (756 byte)
//   0x00bd78: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x00bd7c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00bd80: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00bd84: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00bd88: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00bd8c: 910103fd  add      x29, sp, #0x40
//   0x00bd90: 8b21cc08  add      x8, x0, w1, sxtw #3
//   0x00bd94: f9403916  ldr      x22, [x8, #0x70]
//   0x00bd98: 2a0103f5  mov      w21, w1
//   0x00bd9c: aa0003f3  mov      x19, x0
//   0x00bda0: b5000116  cbnz     x22, #0xbdc0
//   0x00bda4: f9400268  ldr      x8, [x19]
//   0x00bda8: 528006c9  mov      w9, #0x36
//   0x00bdac: aa1303e0  mov      x0, x19
//   0x00bdb0: 29055509  stp      w9, w21, [x8, #0x28]
//   0x00bdb4: f9400268  ldr      x8, [x19]
uint64_t fde_0100_sub_00bd78(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x528006C9ULL) + (x2 ^ 0x00BD78ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x00bd78: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00bd7c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00bd80: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00bd84: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00bd88: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00bd8c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21CC08ULL; // 0x00bd90: add x8, x0, w1, sxtw #3
    acc = (acc * 0x100000001B3ULL) ^ 0xF9403916ULL; // 0x00bd94: ldr x22, [x8, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x00bd98: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00bd9c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0101 @ 0x00c06c..0x00c514 (1192 bytes)
// [VN] Phục dựng FDE #0101 tại 0x00c06c..0x00c514 (1192 byte)
//   0x00c06c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00c070: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00c074: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00c078: 910083fd  add      x29, sp, #0x20
//   0x00c07c: f9401408  ldr      x8, [x0, #0x28]
//   0x00c080: 52801fea  mov      w10, #0xff
//   0x00c084: 2a0103f4  mov      w20, w1
//   0x00c088: aa0003f3  mov      x19, x0
//   0x00c08c: f9400109  ldr      x9, [x8]
//   0x00c090: 9100052b  add      x11, x9, #1
//   0x00c094: f900010b  str      x11, [x8]
//   0x00c098: 3900012a  strb     w10, [x9]
//   0x00c09c: f9400509  ldr      x9, [x8, #8]
//   0x00c0a0: f1000529  subs     x9, x9, #1
//   0x00c0a4: f9000509  str      x9, [x8, #8]
//   0x00c0a8: 54000161  b.ne     #0xc0d4
uint64_t fde_0101_sub_00c06c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9400509ULL) + (x2 ^ 0x00C06CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00c06c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00c070: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00c074: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00c078: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00c07c: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEAULL; // 0x00c080: mov w10, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x00c084: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00c088: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00c08c: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100052BULL; // 0x00c090: add x11, x9, #1
    return acc;
}

// [EN] Reconstructed FDE #0102 @ 0x00c514..0x00c87c (872 bytes)
// [VN] Phục dựng FDE #0102 tại 0x00c514..0x00c87c (872 byte)
//   0x00c514: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00c518: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00c51c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00c520: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00c524: 9100c3fd  add      x29, sp, #0x30
//   0x00c528: 8b21cc08  add      x8, x0, w1, sxtw #3
//   0x00c52c: 91030109  add      x9, x8, #0xc0
//   0x00c530: 91028108  add      x8, x8, #0xa0
//   0x00c534: 7100005f  cmp      w2, #0
//   0x00c538: 9a890108  csel     x8, x8, x9, eq
//   0x00c53c: f9400114  ldr      x20, [x8]
//   0x00c540: 11004028  add      w8, w1, #0x10
//   0x00c544: aa0003f3  mov      x19, x0
//   0x00c548: 1a880035  csel     w21, w1, w8, eq
//   0x00c54c: b4000094  cbz      x20, #0xc55c
//   0x00c550: b9411688  ldr      w8, [x20, #0x114]
uint64_t fde_0102_sub_00c514(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x00C514ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x00c514: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00c518: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00c51c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00c520: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00c524: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21CC08ULL; // 0x00c528: add x8, x0, w1, sxtw #3
    acc = (acc * 0x100000001B3ULL) ^ 0x91030109ULL; // 0x00c52c: add x9, x8, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0x91028108ULL; // 0x00c530: add x8, x8, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100005FULL; // 0x00c534: cmp w2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890108ULL; // 0x00c538: csel x8, x8, x9, eq
    return acc;
}

// [EN] Reconstructed FDE #0103 @ 0x00c87c..0x00d0bc (2112 bytes)
// [VN] Phục dựng FDE #0103 tại 0x00c87c..0x00d0bc (2112 byte)
//   0x00c87c: fc190fe8  str      d8, [sp, #-0x70]!
//   0x00c880: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x00c884: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x00c888: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x00c88c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00c890: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00c894: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00c898: 910183fd  add      x29, sp, #0x60
//   0x00c89c: d12983ff  sub      sp, sp, #0xa60
//   0x00c8a0: d53bd058  mrs      x24, tpidr_el0
//   0x00c8a4: f9401708  ldr      x8, [x24, #0x28]
//   0x00c8a8: 2a0103f4  mov      w20, w1
//   0x00c8ac: 52800021  mov      w1, #1
//   0x00c8b0: 52800702  mov      w2, #0x38
//   0x00c8b4: f81903a8  stur     x8, [x29, #-0x70]
//   0x00c8b8: f9400408  ldr      x8, [x0, #8]
uint64_t fde_0103_sub_00c87c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC190FE8ULL) + (x1 ^ 0x52800021ULL) + (x2 ^ 0x00C87CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC190FE8ULL; // 0x00c87c: str d8, [sp, #-0x70]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x00c880: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x00c884: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x00c888: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x00c88c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x00c890: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x00c894: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x00c898: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD12983FFULL; // 0x00c89c: sub sp, sp, #0xa60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x00c8a0: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #0104 @ 0x00d0bc..0x00d2b8 (508 bytes)
// [VN] Phục dựng FDE #0104 tại 0x00d0bc..0x00d2b8 (508 byte)
//   0x00d0bc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00d0c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d0c4: 910043fd  add      x29, sp, #0x10
//   0x00d0c8: f940f814  ldr      x20, [x0, #0x1f0]
//   0x00d0cc: aa0003f3  mov      x19, x0
//   0x00d0d0: b9402288  ldr      w8, [x20, #0x20]
//   0x00d0d4: 7100091f  cmp      w8, #2
//   0x00d0d8: 54000a40  b.eq     #0xd220
//   0x00d0dc: 7100051f  cmp      w8, #1
//   0x00d0e0: 54000600  b.eq     #0xd1a0
//   0x00d0e4: 35000808  cbnz     w8, #0xd1e4
//   0x00d0e8: aa1303e0  mov      x0, x19
//   0x00d0ec: 940000a5  bl       #0xd380
//   0x00d0f0: aa1303e0  mov      x0, x19
//   0x00d0f4: 94000125  bl       #0xd588
//   0x00d0f8: b9412268  ldr      w8, [x19, #0x120]
uint64_t fde_0104_sub_00d0bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x940000A5ULL) + (x2 ^ 0x00D0BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00d0bc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d0c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d0c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF940F814ULL; // 0x00d0c8: ldr x20, [x0, #0x1f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d0cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402288ULL; // 0x00d0d0: ldr w8, [x20, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100091FULL; // 0x00d0d4: cmp w8, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000A40ULL; // 0x00d0d8: b.eq #0xd220
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x00d0dc: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000600ULL; // 0x00d0e0: b.eq #0xd1a0
    return acc;
}

// [EN] Reconstructed FDE #0105 @ 0x00d2b8..0x00d2f4 (60 bytes)
// [VN] Phục dựng FDE #0105 tại 0x00d2b8..0x00d2f4 (60 byte)
//   0x00d2b8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d2bc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d2c0: 910043fd  add      x29, sp, #0x10
//   0x00d2c4: f940f808  ldr      x8, [x0, #0x1f0]
//   0x00d2c8: aa0003f3  mov      x19, x0
//   0x00d2cc: b900191f  str      wzr, [x8, #0x18]
//   0x00d2d0: f9410808  ldr      x8, [x0, #0x210]
//   0x00d2d4: f9400508  ldr      x8, [x8, #8]
//   0x00d2d8: d63f0100  blr      x8
//   0x00d2dc: f9410a68  ldr      x8, [x19, #0x210]
//   0x00d2e0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d2e4: aa1303e0  mov      x0, x19
//   0x00d2e8: f9400901  ldr      x1, [x8, #0x10]
//   0x00d2ec: f84207f3  ldr      x19, [sp], #0x20
//   0x00d2f0: d61f0020  br       x1
uint64_t fde_0105_sub_00d2b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400901ULL) + (x2 ^ 0x00D2B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d2b8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d2bc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d2c0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF940F808ULL; // 0x00d2c4: ldr x8, [x0, #0x1f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d2c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB900191FULL; // 0x00d2cc: str wzr, [x8, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410808ULL; // 0x00d2d0: ldr x8, [x0, #0x210]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400508ULL; // 0x00d2d4: ldr x8, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00d2d8: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410A68ULL; // 0x00d2dc: ldr x8, [x19, #0x210]
    return acc;
}

// [EN] Reconstructed FDE #0106 @ 0x00d2f4..0x00d380 (140 bytes)
// [VN] Phục dựng FDE #0106 tại 0x00d2f4..0x00d380 (140 byte)
//   0x00d2f4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00d2f8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d2fc: 910043fd  add      x29, sp, #0x10
//   0x00d300: f9411808  ldr      x8, [x0, #0x230]
//   0x00d304: f940f814  ldr      x20, [x0, #0x1f0]
//   0x00d308: aa0003f3  mov      x19, x0
//   0x00d30c: f9400908  ldr      x8, [x8, #0x10]
//   0x00d310: d63f0100  blr      x8
//   0x00d314: b9402288  ldr      w8, [x20, #0x20]
//   0x00d318: 7100091f  cmp      w8, #2
//   0x00d31c: 54000120  b.eq     #0xd340
//   0x00d320: 7100051f  cmp      w8, #1
//   0x00d324: 540001e0  b.eq     #0xd360
//   0x00d328: 35000208  cbnz     w8, #0xd368
//   0x00d32c: 52800048  mov      w8, #2
//   0x00d330: b9002288  str      w8, [x20, #0x20]
uint64_t fde_0106_sub_00d2f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x540001E0ULL) + (x2 ^ 0x00D2F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00d2f4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d2f8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d2fc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411808ULL; // 0x00d300: ldr x8, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xF940F814ULL; // 0x00d304: ldr x20, [x0, #0x1f0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d308: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400908ULL; // 0x00d30c: ldr x8, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00d310: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402288ULL; // 0x00d314: ldr w8, [x20, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100091FULL; // 0x00d318: cmp w8, #2
    return acc;
}

// [EN] Reconstructed FDE #0107 @ 0x00d380..0x00d588 (520 bytes)
// [VN] Phục dựng FDE #0107 tại 0x00d380..0x00d588 (520 byte)
//   0x00d380: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d384: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d388: 910043fd  add      x29, sp, #0x10
//   0x00d38c: f9408c08  ldr      x8, [x0, #0x118]
//   0x00d390: aa0003f3  mov      x19, x0
//   0x00d394: b40001c8  cbz      x8, #0xd3cc
//   0x00d398: f940fa69  ldr      x9, [x19, #0x1f0]
//   0x00d39c: 5280048a  mov      w10, #0x24
//   0x00d3a0: b9802d29  ldrsw    x9, [x9, #0x2c]
//   0x00d3a4: 9b0a7d2a  mul      x10, x9, x10
//   0x00d3a8: b86a690b  ldr      w11, [x8, x10]
//   0x00d3ac: 7100057f  cmp      w11, #1
//   0x00d3b0: b901726b  str      w11, [x19, #0x170]
//   0x00d3b4: 540007cb  b.lt     #0xd4ac
//   0x00d3b8: f940366a  ldr      x10, [x19, #0x68]
//   0x00d3bc: 7100117f  cmp      w11, #4
uint64_t fde_0107_sub_00d380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB901726BULL) + (x2 ^ 0x00D380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d380: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d384: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d388: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408C08ULL; // 0x00d38c: ldr x8, [x0, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d390: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001C8ULL; // 0x00d394: cbz x8, #0xd3cc
    acc = (acc * 0x100000001B3ULL) ^ 0xF940FA69ULL; // 0x00d398: ldr x9, [x19, #0x1f0]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280048AULL; // 0x00d39c: mov w10, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0xB9802D29ULL; // 0x00d3a0: ldrsw x9, [x9, #0x2c]
    acc = (acc * 0x100000001B3ULL) ^ 0x9B0A7D2AULL; // 0x00d3a4: mul x10, x9, x10
    return acc;
}

// [EN] Reconstructed FDE #0108 @ 0x00d588..0x00d744 (444 bytes)
// [VN] Phục dựng FDE #0108 tại 0x00d588..0x00d744 (444 byte)
//   0x00d588: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00d58c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d590: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d594: 910083fd  add      x29, sp, #0x20
//   0x00d598: b9417008  ldr      w8, [x0, #0x170]
//   0x00d59c: aa0003f3  mov      x19, x0
//   0x00d5a0: 71000509  subs     w9, w8, #1
//   0x00d5a4: 54000281  b.ne     #0xd5f4
//   0x00d5a8: f940be68  ldr      x8, [x19, #0x178]
//   0x00d5ac: f000020a  adrp     x10, #0x50000
//   0x00d5b0: 3dc21540  ldr      q0, [x10, #0x850]
//   0x00d5b4: d000020b  adrp     x11, #0x4f000
//   0x00d5b8: b9401d09  ldr      w9, [x8, #0x1c]
//   0x00d5bc: b9019a69  str      w9, [x19, #0x198]
//   0x00d5c0: b9402109  ldr      w9, [x8, #0x20]
//   0x00d5c4: b9019e69  str      w9, [x19, #0x19c]
uint64_t fde_0108_sub_00d588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB9401D09ULL) + (x2 ^ 0x00D588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00d588: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00d58c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00d590: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00d594: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9417008ULL; // 0x00d598: ldr w8, [x0, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d59c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71000509ULL; // 0x00d5a0: subs w9, w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000281ULL; // 0x00d5a4: b.ne #0xd5f4
    acc = (acc * 0x100000001B3ULL) ^ 0xF940BE68ULL; // 0x00d5a8: ldr x8, [x19, #0x178]
    acc = (acc * 0x100000001B3ULL) ^ 0xF000020AULL; // 0x00d5ac: adrp x10, #0x50000
    return acc;
}

// [EN] Reconstructed FDE #0109 @ 0x00d744..0x00d794 (80 bytes)
// [VN] Phục dựng FDE #0109 tại 0x00d744..0x00d794 (80 byte)
//   0x00d744: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d748: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d74c: 910043fd  add      x29, sp, #0x10
//   0x00d750: f9400408  ldr      x8, [x0, #8]
//   0x00d754: b40001a8  cbz      x8, #0xd788
//   0x00d758: f9402508  ldr      x8, [x8, #0x48]
//   0x00d75c: 52800021  mov      w1, #1
//   0x00d760: aa0003f3  mov      x19, x0
//   0x00d764: d63f0100  blr      x8
//   0x00d768: b9402268  ldr      w8, [x19, #0x20]
//   0x00d76c: 340000a8  cbz      w8, #0xd780
//   0x00d770: 52801908  mov      w8, #0xc8
//   0x00d774: b9002668  str      w8, [x19, #0x24]
//   0x00d778: f900ca7f  str      xzr, [x19, #0x190]
//   0x00d77c: 14000003  b        #0xd788
//   0x00d780: 52800c88  mov      w8, #0x64
uint64_t fde_0109_sub_00d744(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB9002668ULL) + (x2 ^ 0x00D744ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d744: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d748: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d74c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00d750: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001A8ULL; // 0x00d754: cbz x8, #0xd788
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402508ULL; // 0x00d758: ldr x8, [x8, #0x48]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x00d75c: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d760: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00d764: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402268ULL; // 0x00d768: ldr w8, [x19, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #0110 @ 0x00d794..0x00d7cc (56 bytes)
// [VN] Phục dựng FDE #0110 tại 0x00d794..0x00d7cc (56 byte)
//   0x00d794: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00d798: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00d79c: 910043fd  add      x29, sp, #0x10
//   0x00d7a0: f9400408  ldr      x8, [x0, #8]
//   0x00d7a4: aa0003f3  mov      x19, x0
//   0x00d7a8: b4000088  cbz      x8, #0xd7b8
//   0x00d7ac: f9402908  ldr      x8, [x8, #0x50]
//   0x00d7b0: aa1303e0  mov      x0, x19
//   0x00d7b4: d63f0100  blr      x8
//   0x00d7b8: f900067f  str      xzr, [x19, #8]
//   0x00d7bc: b900267f  str      wzr, [x19, #0x24]
//   0x00d7c0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x00d7c4: f84207f3  ldr      x19, [sp], #0x20
//   0x00d7c8: d65f03c0  ret      
uint64_t fde_0110_sub_00d794(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x00D794ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00d794: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00d798: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00d79c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00d7a0: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d7a4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x00d7a8: cbz x8, #0xd7b8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402908ULL; // 0x00d7ac: ldr x8, [x8, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00d7b0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00d7b4: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF900067FULL; // 0x00d7b8: str xzr, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0111 @ 0x00d7cc..0x00d7f4 (40 bytes)
// [VN] Phục dựng FDE #0111 tại 0x00d7cc..0x00d7f4 (40 byte)
//   0x00d7cc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00d7d0: 910003fd  mov      x29, sp
//   0x00d7d4: f9400408  ldr      x8, [x0, #8]
//   0x00d7d8: 52801082  mov      w2, #0x84
//   0x00d7dc: 2a1f03e1  mov      w1, wzr
//   0x00d7e0: f9400108  ldr      x8, [x8]
//   0x00d7e4: d63f0100  blr      x8
//   0x00d7e8: b900801f  str      wzr, [x0, #0x80]
//   0x00d7ec: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00d7f0: d65f03c0  ret      
uint64_t fde_0111_sub_00d7cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00D7CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00d7cc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00d7d0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00d7d4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801082ULL; // 0x00d7d8: mov w2, #0x84
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x00d7dc: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x00d7e0: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00d7e4: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB900801FULL; // 0x00d7e8: str wzr, [x0, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x00d7ec: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00d7f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0112 @ 0x00d7f4..0x00d81c (40 bytes)
// [VN] Phục dựng FDE #0112 tại 0x00d7f4..0x00d81c (40 byte)
//   0x00d7f4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x00d7f8: 910003fd  mov      x29, sp
//   0x00d7fc: f9400408  ldr      x8, [x0, #8]
//   0x00d800: 52802302  mov      w2, #0x118
//   0x00d804: 2a1f03e1  mov      w1, wzr
//   0x00d808: f9400108  ldr      x8, [x8]
//   0x00d80c: d63f0100  blr      x8
//   0x00d810: b901141f  str      wzr, [x0, #0x114]
//   0x00d814: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x00d818: d65f03c0  ret      
uint64_t fde_0112_sub_00d7f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00D7F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x00d7f4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x00d7f8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00d7fc: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52802302ULL; // 0x00d800: mov w2, #0x118
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x00d804: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x00d808: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00d80c: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB901141FULL; // 0x00d810: str wzr, [x0, #0x114]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x00d814: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00d818: ret 
    return acc;
}

// [EN] Reconstructed FDE #0113 @ 0x00d81c..0x00d9a4 (392 bytes)
// [VN] Phục dựng FDE #0113 tại 0x00d81c..0x00d9a4 (392 byte)
//   0x00d81c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00d820: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d824: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d828: 910083fd  add      x29, sp, #0x20
//   0x00d82c: b9402408  ldr      w8, [x0, #0x24]
//   0x00d830: 2a0203f3  mov      w19, w2
//   0x00d834: aa0003f4  mov      x20, x0
//   0x00d838: 2a0103f5  mov      w21, w1
//   0x00d83c: 7101911f  cmp      w8, #0x64
//   0x00d840: 54000100  b.eq     #0xd860
//   0x00d844: f9400289  ldr      x9, [x20]
//   0x00d848: 528002aa  mov      w10, #0x15
//   0x00d84c: aa1403e0  mov      x0, x20
//   0x00d850: 2905212a  stp      w10, w8, [x9, #0x28]
//   0x00d854: f9400288  ldr      x8, [x20]
//   0x00d858: f9400108  ldr      x8, [x8]
uint64_t fde_0113_sub_00d81c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x00D81CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00d81c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00d820: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00d824: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00d828: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402408ULL; // 0x00d82c: ldr w8, [x0, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x00d830: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00d834: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x00d838: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x7101911FULL; // 0x00d83c: cmp w8, #0x64
    acc = (acc * 0x100000001B3ULL) ^ 0x54000100ULL; // 0x00d840: b.eq #0xd860
    return acc;
}

// [EN] Reconstructed FDE #0114 @ 0x00d9a4..0x00d9d8 (52 bytes)
// [VN] Phục dựng FDE #0114 tại 0x00d9a4..0x00d9d8 (52 byte)
//   0x00d9a4: 7100043f  cmp      w1, #1
//   0x00d9a8: 1a9fc428  csinc    w8, w1, wzr, gt
//   0x00d9ac: 7101911f  cmp      w8, #0x64
//   0x00d9b0: 52800c89  mov      w9, #0x64
//   0x00d9b4: 1a89b108  csel     w8, w8, w9, lt
//   0x00d9b8: 7100c51f  cmp      w8, #0x31
//   0x00d9bc: 5400008c  b.gt     #0xd9cc
//   0x00d9c0: 52827109  mov      w9, #0x1388
//   0x00d9c4: 1ac80921  udiv     w1, w9, w8
//   0x00d9c8: 17ffff95  b        #0xd81c
//   0x00d9cc: 52801909  mov      w9, #0xc8
//   0x00d9d0: 4b080521  sub      w1, w9, w8, lsl #1
//   0x00d9d4: 17ffff92  b        #0xd81c
uint64_t fde_0114_sub_00d9a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100043FULL) + (x1 ^ 0x17FFFF92ULL) + (x2 ^ 0x00D9A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100043FULL; // 0x00d9a4: cmp w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9FC428ULL; // 0x00d9a8: csinc w8, w1, wzr, gt
    acc = (acc * 0x100000001B3ULL) ^ 0x7101911FULL; // 0x00d9ac: cmp w8, #0x64
    acc = (acc * 0x100000001B3ULL) ^ 0x52800C89ULL; // 0x00d9b0: mov w9, #0x64
    acc = (acc * 0x100000001B3ULL) ^ 0x1A89B108ULL; // 0x00d9b4: csel w8, w8, w9, lt
    acc = (acc * 0x100000001B3ULL) ^ 0x7100C51FULL; // 0x00d9b8: cmp w8, #0x31
    acc = (acc * 0x100000001B3ULL) ^ 0x5400008CULL; // 0x00d9bc: b.gt #0xd9cc
    acc = (acc * 0x100000001B3ULL) ^ 0x52827109ULL; // 0x00d9c0: mov w9, #0x1388
    acc = (acc * 0x100000001B3ULL) ^ 0x1AC80921ULL; // 0x00d9c4: udiv w1, w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF95ULL; // 0x00d9c8: b #0xd81c
    return acc;
}

// [EN] Reconstructed FDE #0115 @ 0x00d9d8..0x00db68 (400 bytes)
// [VN] Phục dựng FDE #0115 tại 0x00d9d8..0x00db68 (400 byte)
//   0x00d9d8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00d9dc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00d9e0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00d9e4: 910083fd  add      x29, sp, #0x20
//   0x00d9e8: b9402408  ldr      w8, [x0, #0x24]
//   0x00d9ec: aa0003f3  mov      x19, x0
//   0x00d9f0: 7101911f  cmp      w8, #0x64
//   0x00d9f4: 54000100  b.eq     #0xda14
//   0x00d9f8: f9400269  ldr      x9, [x19]
//   0x00d9fc: 528002aa  mov      w10, #0x15
//   0x00da00: aa1303e0  mov      x0, x19
//   0x00da04: 2905212a  stp      w10, w8, [x9, #0x28]
//   0x00da08: f9400268  ldr      x8, [x19]
//   0x00da0c: f9400108  ldr      x8, [x8]
//   0x00da10: d63f0100  blr      x8
//   0x00da14: f9403668  ldr      x8, [x19, #0x68]
uint64_t fde_0115_sub_00d9d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400268ULL) + (x2 ^ 0x00D9D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00d9d8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00d9dc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00d9e0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00d9e4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402408ULL; // 0x00d9e8: ldr w8, [x0, #0x24]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00d9ec: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x7101911FULL; // 0x00d9f0: cmp w8, #0x64
    acc = (acc * 0x100000001B3ULL) ^ 0x54000100ULL; // 0x00d9f4: b.eq #0xda14
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400269ULL; // 0x00d9f8: ldr x9, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x528002AAULL; // 0x00d9fc: mov w10, #0x15
    return acc;
}

// [EN] Reconstructed FDE #0116 @ 0x00db68..0x00dee4 (892 bytes)
// [VN] Phục dựng FDE #0116 tại 0x00db68..0x00dee4 (892 byte)
//   0x00db68: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00db6c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00db70: 910043fd  add      x29, sp, #0x10
//   0x00db74: b9403c08  ldr      w8, [x0, #0x3c]
//   0x00db78: aa0003f3  mov      x19, x0
//   0x00db7c: 71003d1f  cmp      w8, #0xf
//   0x00db80: 54000548  b.hi     #0xdc28
//   0x00db84: f0000209  adrp     x9, #0x50000
//   0x00db88: 91258129  add      x9, x9, #0x960
//   0x00db8c: 1000008a  adr      x10, #0xdb9c
//   0x00db90: 3868692b  ldrb     w11, [x9, x8]
//   0x00db94: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x00db98: d61f0140  br       x10
//   0x00db9c: b9402668  ldr      w8, [x19, #0x24]
//   0x00dba0: 7101911f  cmp      w8, #0x64
//   0x00dba4: 54000100  b.eq     #0xdbc4
uint64_t fde_0116_sub_00db68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD61F0140ULL) + (x2 ^ 0x00DB68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00db68: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00db6c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00db70: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403C08ULL; // 0x00db74: ldr w8, [x0, #0x3c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00db78: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x71003D1FULL; // 0x00db7c: cmp w8, #0xf
    acc = (acc * 0x100000001B3ULL) ^ 0x54000548ULL; // 0x00db80: b.hi #0xdc28
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000209ULL; // 0x00db84: adrp x9, #0x50000
    acc = (acc * 0x100000001B3ULL) ^ 0x91258129ULL; // 0x00db88: add x9, x9, #0x960
    acc = (acc * 0x100000001B3ULL) ^ 0x1000008AULL; // 0x00db8c: adr x10, #0xdb9c
    return acc;
}

// [EN] Reconstructed FDE #0117 @ 0x00dee4..0x00dfb8 (212 bytes)
// [VN] Phục dựng FDE #0117 tại 0x00dee4..0x00dfb8 (212 byte)
//   0x00dee4: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00dee8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00deec: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00def0: 910083fd  add      x29, sp, #0x20
//   0x00def4: f9400028  ldr      x8, [x1]
//   0x00def8: b5000588  cbnz     x8, #0xdfa8
//   0x00defc: aa0303f4  mov      x20, x3
//   0x00df00: aa0203f6  mov      x22, x2
//   0x00df04: aa0103f3  mov      x19, x1
//   0x00df08: aa0003f5  mov      x21, x0
//   0x00df0c: 97fffe3a  bl       #0xd7f4
//   0x00df10: f9000260  str      x0, [x19]
//   0x00df14: 394042c8  ldrb     w8, [x22, #0x10]
//   0x00df18: 3dc002c0  ldr      q0, [x22]
//   0x00df1c: 39004008  strb     w8, [x0, #0x10]
//   0x00df20: 3d800000  str      q0, [x0]
uint64_t fde_0117_sub_00dee4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x394042C8ULL) + (x2 ^ 0x00DEE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00dee4: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00dee8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00deec: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00def0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x00def4: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000588ULL; // 0x00def8: cbnz x8, #0xdfa8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x00defc: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F6ULL; // 0x00df00: mov x22, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x00df04: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x00df08: mov x21, x0
    return acc;
}

// [EN] Reconstructed FDE #0118 @ 0x00dfb8..0x00e010 (88 bytes)
// [VN] Phục dựng FDE #0118 tại 0x00dfb8..0x00e010 (88 byte)
//   0x00dfb8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x00dfbc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00dfc0: 910043fd  add      x29, sp, #0x10
//   0x00dfc4: f9400408  ldr      x8, [x0, #8]
//   0x00dfc8: 52800021  mov      w1, #1
//   0x00dfcc: 52801702  mov      w2, #0xb8
//   0x00dfd0: aa0003f3  mov      x19, x0
//   0x00dfd4: f9400108  ldr      x8, [x8]
//   0x00dfd8: d63f0100  blr      x8
//   0x00dfdc: b0000008  adrp     x8, #0xe000
//   0x00dfe0: 91004108  add      x8, x8, #0x10
//   0x00dfe4: 6f00e400  movi     v0.2d, #0000000000000000
//   0x00dfe8: f9011a60  str      x0, [x19, #0x230]
//   0x00dfec: f900341f  str      xzr, [x0, #0x68]
//   0x00dff0: f9000008  str      x8, [x0]
//   0x00dff4: 3c8a8000  stur     q0, [x0, #0xa8]
uint64_t fde_0118_sub_00dfb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9011A60ULL) + (x2 ^ 0x00DFB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x00dfb8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00dfbc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00dfc0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00dfc4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x00dfc8: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52801702ULL; // 0x00dfcc: mov w2, #0xb8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00dfd0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x00dfd4: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x00dfd8: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000008ULL; // 0x00dfdc: adrp x8, #0xe000
    return acc;
}

// [EN] Reconstructed FDE #0119 @ 0x00e010..0x00e1cc (444 bytes)
// [VN] Phục dựng FDE #0119 tại 0x00e010..0x00e1cc (444 byte)
//   0x00e010: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x00e014: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00e018: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00e01c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00e020: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00e024: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00e028: 910143fd  add      x29, sp, #0x50
//   0x00e02c: f9411816  ldr      x22, [x0, #0x230]
//   0x00e030: 2a0103f4  mov      w20, w1
//   0x00e034: aa0003f3  mov      x19, x0
//   0x00e038: f90022c0  str      x0, [x22, #0x40]
//   0x00e03c: b9001ac1  str      w1, [x22, #0x18]
//   0x00e040: b941cc17  ldr      w23, [x0, #0x1cc]
//   0x00e044: b941d408  ldr      w8, [x0, #0x1d4]
//   0x00e048: 710002ff  cmp      w23, #0
//   0x00e04c: 1a9f17f5  cset     w21, eq
uint64_t fde_0119_sub_00e010(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xB941CC17ULL) + (x2 ^ 0x00E010ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x00e010: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00e014: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00e018: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00e01c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00e020: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00e024: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00e028: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411816ULL; // 0x00e02c: ldr x22, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x00e030: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00e034: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0120 @ 0x00e1cc..0x00e360 (404 bytes)
// [VN] Phục dựng FDE #0120 tại 0x00e1cc..0x00e360 (404 byte)
//   0x00e1cc: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00e1d0: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00e1d4: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00e1d8: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00e1dc: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00e1e0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00e1e4: 910143fd  add      x29, sp, #0x50
//   0x00e1e8: f9401408  ldr      x8, [x0, #0x28]
//   0x00e1ec: f9411813  ldr      x19, [x0, #0x230]
//   0x00e1f0: b941d817  ldr      w23, [x0, #0x1d8]
//   0x00e1f4: aa0003f4  mov      x20, x0
//   0x00e1f8: 3dc00100  ldr      q0, [x8]
//   0x00e1fc: aa0103f5  mov      x21, x1
//   0x00e200: 3d800a60  str      q0, [x19, #0x20]
//   0x00e204: b9413c08  ldr      w8, [x0, #0x13c]
//   0x00e208: 340000c8  cbz      w8, #0xe220
uint64_t fde_0120_sub_00e1cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x00E1CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x00e1cc: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00e1d0: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00e1d4: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00e1d8: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00e1dc: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00e1e0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00e1e4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00e1e8: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411813ULL; // 0x00e1ec: ldr x19, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xB941D817ULL; // 0x00e1f0: ldr w23, [x0, #0x1d8]
    return acc;
}

// [EN] Reconstructed FDE #0121 @ 0x00e360..0x00e5a0 (576 bytes)
// [VN] Phục dựng FDE #0121 tại 0x00e360..0x00e5a0 (576 byte)
//   0x00e360: d101c3ff  sub      sp, sp, #0x70
//   0x00e364: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x00e368: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x00e36c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x00e370: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x00e374: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x00e378: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x00e37c: 910183fd  add      x29, sp, #0x60
//   0x00e380: f9401408  ldr      x8, [x0, #0x28]
//   0x00e384: f9411813  ldr      x19, [x0, #0x230]
//   0x00e388: b981d017  ldrsw    x23, [x0, #0x1d0]
//   0x00e38c: aa0003f4  mov      x20, x0
//   0x00e390: 3dc00100  ldr      q0, [x8]
//   0x00e394: b941d808  ldr      w8, [x0, #0x1d8]
//   0x00e398: aa0103f5  mov      x21, x1
//   0x00e39c: 3d800a60  str      q0, [x19, #0x20]
uint64_t fde_0121_sub_00e360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x3DC00100ULL) + (x2 ^ 0x00E360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x00e360: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x00e364: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x00e368: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x00e36c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x00e370: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x00e374: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x00e378: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x00e37c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00e380: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411813ULL; // 0x00e384: ldr x19, [x0, #0x230]
    return acc;
}

// [EN] Reconstructed FDE #0122 @ 0x00e5a0..0x00e674 (212 bytes)
// [VN] Phục dựng FDE #0122 tại 0x00e5a0..0x00e674 (212 byte)
//   0x00e5a0: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x00e5a4: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00e5a8: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00e5ac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00e5b0: 9100c3fd  add      x29, sp, #0x30
//   0x00e5b4: f9401408  ldr      x8, [x0, #0x28]
//   0x00e5b8: f9411813  ldr      x19, [x0, #0x230]
//   0x00e5bc: b941d816  ldr      w22, [x0, #0x1d8]
//   0x00e5c0: aa0003f4  mov      x20, x0
//   0x00e5c4: 3dc00100  ldr      q0, [x8]
//   0x00e5c8: aa0103f5  mov      x21, x1
//   0x00e5cc: 3d800a60  str      q0, [x19, #0x20]
//   0x00e5d0: b9413c08  ldr      w8, [x0, #0x13c]
//   0x00e5d4: 340000c8  cbz      w8, #0xe5ec
//   0x00e5d8: b9407268  ldr      w8, [x19, #0x70]
//   0x00e5dc: 35000088  cbnz     w8, #0xe5ec
uint64_t fde_0122_sub_00e5a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB9413C08ULL) + (x2 ^ 0x00E5A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x00e5a0: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00e5a4: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00e5a8: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00e5ac: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00e5b0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00e5b4: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411813ULL; // 0x00e5b8: ldr x19, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xB941D816ULL; // 0x00e5bc: ldr w22, [x0, #0x1d8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00e5c0: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00100ULL; // 0x00e5c4: ldr q0, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0123 @ 0x00e674..0x00e998 (804 bytes)
// [VN] Phục dựng FDE #0123 tại 0x00e674..0x00e998 (804 byte)
//   0x00e674: d10643ff  sub      sp, sp, #0x190
//   0x00e678: a9136ffc  stp      x28, x27, [sp, #0x130]
//   0x00e67c: a91467fa  stp      x26, x25, [sp, #0x140]
//   0x00e680: a9155ff8  stp      x24, x23, [sp, #0x150]
//   0x00e684: a91657f6  stp      x22, x21, [sp, #0x160]
//   0x00e688: a9174ff4  stp      x20, x19, [sp, #0x170]
//   0x00e68c: a9187bfd  stp      x29, x30, [sp, #0x180]
//   0x00e690: 910603fd  add      x29, sp, #0x180
//   0x00e694: d53bd048  mrs      x8, tpidr_el0
//   0x00e698: f9000be8  str      x8, [sp, #0x10]
//   0x00e69c: f9401508  ldr      x8, [x8, #0x28]
//   0x00e6a0: aa0003f6  mov      x22, x0
//   0x00e6a4: aa0103f5  mov      x21, x1
//   0x00e6a8: f81a03a8  stur     x8, [x29, #-0x60]
//   0x00e6ac: f9401408  ldr      x8, [x0, #0x28]
//   0x00e6b0: f9411813  ldr      x19, [x0, #0x230]
uint64_t fde_0123_sub_00e674(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10643FFULL) + (x1 ^ 0xAA0103F5ULL) + (x2 ^ 0x00E674ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10643FFULL; // 0x00e674: sub sp, sp, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xA9136FFCULL; // 0x00e678: stp x28, x27, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91467FAULL; // 0x00e67c: stp x26, x25, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9155FF8ULL; // 0x00e680: stp x24, x23, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91657F6ULL; // 0x00e684: stp x22, x21, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9174FF4ULL; // 0x00e688: stp x20, x19, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9187BFDULL; // 0x00e68c: stp x29, x30, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0x910603FDULL; // 0x00e690: add x29, sp, #0x180
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x00e694: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BE8ULL; // 0x00e698: str x8, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0124 @ 0x00e998..0x00eab4 (284 bytes)
// [VN] Phục dựng FDE #0124 tại 0x00e998..0x00eab4 (284 byte)
//   0x00e998: d10203ff  sub      sp, sp, #0x80
//   0x00e99c: f90013fb  str      x27, [sp, #0x20]
//   0x00e9a0: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x00e9a4: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x00e9a8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x00e9ac: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x00e9b0: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x00e9b4: 9101c3fd  add      x29, sp, #0x70
//   0x00e9b8: d53bd055  mrs      x21, tpidr_el0
//   0x00e9bc: f94016a8  ldr      x8, [x21, #0x28]
//   0x00e9c0: aa0003f3  mov      x19, x0
//   0x00e9c4: f9000fe8  str      x8, [sp, #0x18]
//   0x00e9c8: f9411814  ldr      x20, [x0, #0x230]
//   0x00e9cc: aa1403e0  mov      x0, x20
//   0x00e9d0: 940000fd  bl       #0xedc4
//   0x00e9d4: b941ce76  ldr      w22, [x19, #0x1cc]
uint64_t fde_0124_sub_00e998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9411814ULL) + (x2 ^ 0x00E998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x00e998: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013FBULL; // 0x00e99c: str x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x00e9a0: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x00e9a4: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x00e9a8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x00e9ac: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x00e9b0: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x00e9b4: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x00e9b8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x00e9bc: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0125 @ 0x00eab4..0x00eb0c (88 bytes)
// [VN] Phục dựng FDE #0125 tại 0x00eab4..0x00eb0c (88 byte)
//   0x00eab4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00eab8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00eabc: 910043fd  add      x29, sp, #0x10
//   0x00eac0: f9401408  ldr      x8, [x0, #0x28]
//   0x00eac4: f9411814  ldr      x20, [x0, #0x230]
//   0x00eac8: aa0003f3  mov      x19, x0
//   0x00eacc: 3dc00100  ldr      q0, [x8]
//   0x00ead0: aa1403e0  mov      x0, x20
//   0x00ead4: 3d800a80  str      q0, [x20, #0x20]
//   0x00ead8: 940000bb  bl       #0xedc4
//   0x00eadc: 52800fe1  mov      w1, #0x7f
//   0x00eae0: 528000e2  mov      w2, #7
//   0x00eae4: aa1403e0  mov      x0, x20
//   0x00eae8: 94000059  bl       #0xec4c
//   0x00eaec: f9001a9f  str      xzr, [x20, #0x30]
//   0x00eaf0: b9003a9f  str      wzr, [x20, #0x38]
uint64_t fde_0125_sub_00eab4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x00EAB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00eab4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00eab8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00eabc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401408ULL; // 0x00eac0: ldr x8, [x0, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411814ULL; // 0x00eac4: ldr x20, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00eac8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00100ULL; // 0x00eacc: ldr q0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x00ead0: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x3D800A80ULL; // 0x00ead4: str q0, [x20, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x940000BBULL; // 0x00ead8: bl #0xedc4
    return acc;
}

// [EN] Reconstructed FDE #0126 @ 0x00eb0c..0x00ec4c (320 bytes)
// [VN] Phục dựng FDE #0126 tại 0x00eb0c..0x00ec4c (320 byte)
//   0x00eb0c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00eb10: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00eb14: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00eb18: 910083fd  add      x29, sp, #0x20
//   0x00eb1c: 2a0103f4  mov      w20, w1
//   0x00eb20: aa0003f3  mov      x19, x0
//   0x00eb24: 940000a8  bl       #0xedc4
//   0x00eb28: b9401a68  ldr      w8, [x19, #0x18]
//   0x00eb2c: 350006a8  cbnz     w8, #0xec00
//   0x00eb30: 52800fe1  mov      w1, #0x7f
//   0x00eb34: 528000e2  mov      w2, #7
//   0x00eb38: aa1303e0  mov      x0, x19
//   0x00eb3c: 94000044  bl       #0xec4c
//   0x00eb40: f9401268  ldr      x8, [x19, #0x20]
//   0x00eb44: 52801fe9  mov      w9, #0xff
//   0x00eb48: f9001a7f  str      xzr, [x19, #0x30]
uint64_t fde_0126_sub_00eb0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x94000044ULL) + (x2 ^ 0x00EB0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00eb0c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00eb10: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00eb14: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00eb18: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x00eb1c: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00eb20: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x940000A8ULL; // 0x00eb24: bl #0xedc4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401A68ULL; // 0x00eb28: ldr w8, [x19, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x350006A8ULL; // 0x00eb2c: cbnz w8, #0xec00
    acc = (acc * 0x100000001B3ULL) ^ 0x52800FE1ULL; // 0x00eb30: mov w1, #0x7f
    return acc;
}

// [EN] Reconstructed FDE #0127 @ 0x00ec4c..0x00edc4 (376 bytes)
// [VN] Phục dựng FDE #0127 tại 0x00ec4c..0x00edc4 (376 byte)
//   0x00ec4c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x00ec50: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x00ec54: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x00ec58: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x00ec5c: 9100c3fd  add      x29, sp, #0x30
//   0x00ec60: b9403816  ldr      w22, [x0, #0x38]
//   0x00ec64: 2a0203f4  mov      w20, w2
//   0x00ec68: aa0003f3  mov      x19, x0
//   0x00ec6c: 2a0103f5  mov      w21, w1
//   0x00ec70: 34000082  cbz      w2, #0xec80
//   0x00ec74: b9401a68  ldr      w8, [x19, #0x18]
//   0x00ec78: 350009c8  cbnz     w8, #0xedb0
//   0x00ec7c: 14000009  b        #0xeca0
//   0x00ec80: f9402260  ldr      x0, [x19, #0x40]
//   0x00ec84: 5280052a  mov      w10, #0x29
//   0x00ec88: f9400008  ldr      x8, [x0]
uint64_t fde_0127_sub_00ec4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x14000009ULL) + (x2 ^ 0x00EC4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x00ec4c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x00ec50: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x00ec54: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x00ec58: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x00ec5c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403816ULL; // 0x00ec60: ldr w22, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x00ec64: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00ec68: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x00ec6c: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x34000082ULL; // 0x00ec70: cbz w2, #0xec80
    return acc;
}

// [EN] Reconstructed FDE #0128 @ 0x00edc4..0x00eeb4 (240 bytes)
// [VN] Phục dựng FDE #0128 tại 0x00edc4..0x00eeb4 (240 byte)
//   0x00edc4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x00edc8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00edcc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00edd0: 910083fd  add      x29, sp, #0x20
//   0x00edd4: b9405c08  ldr      w8, [x0, #0x5c]
//   0x00edd8: 34000568  cbz      w8, #0xee84
//   0x00eddc: aa0003f3  mov      x19, x0
//   0x00ede0: 12800014  mov      w20, #-1
//   0x00ede4: 128001f5  mov      w21, #-0x10
//   0x00ede8: 13017d08  asr      w8, w8, #1
//   0x00edec: 11000694  add      w20, w20, #1
//   0x00edf0: 110042b5  add      w21, w21, #0x10
//   0x00edf4: 35ffffa8  cbnz     w8, #0xede8
//   0x00edf8: 71003e9f  cmp      w20, #0xf
//   0x00edfc: 540000e3  b.lo     #0xee18
//   0x00ee00: f9402260  ldr      x0, [x19, #0x40]
uint64_t fde_0128_sub_00edc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x35FFFFA8ULL) + (x2 ^ 0x00EDC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x00edc4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00edc8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00edcc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00edd0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405C08ULL; // 0x00edd4: ldr w8, [x0, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000568ULL; // 0x00edd8: cbz w8, #0xee84
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00eddc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x12800014ULL; // 0x00ede0: mov w20, #-1
    acc = (acc * 0x100000001B3ULL) ^ 0x128001F5ULL; // 0x00ede4: mov w21, #-0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x13017D08ULL; // 0x00ede8: asr w8, w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0129 @ 0x00eeb4..0x00f224 (880 bytes)
// [VN] Phục dựng FDE #0129 tại 0x00eeb4..0x00f224 (880 byte)
//   0x00eeb4: d10303ff  sub      sp, sp, #0xc0
//   0x00eeb8: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x00eebc: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x00eec0: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x00eec4: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x00eec8: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x00eecc: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x00eed0: 9102c3fd  add      x29, sp, #0xb0
//   0x00eed4: aa0003f3  mov      x19, x0
//   0x00eed8: 340000e1  cbz      w1, #0xeef4
//   0x00eedc: f9400268  ldr      x8, [x19]
//   0x00eee0: 5280006a  mov      w10, #3
//   0x00eee4: aa1303e0  mov      x0, x19
//   0x00eee8: f9400109  ldr      x9, [x8]
//   0x00eeec: b900290a  str      w10, [x8, #0x28]
//   0x00eef0: d63f0120  blr      x9
uint64_t fde_0129_sub_00eeb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x00EEB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x00eeb4: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x00eeb8: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x00eebc: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x00eec0: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x00eec4: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x00eec8: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x00eecc: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x00eed0: add x29, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00eed4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E1ULL; // 0x00eed8: cbz w1, #0xeef4
    return acc;
}

// [EN] Reconstructed FDE #0130 @ 0x00f224..0x00f278 (84 bytes)
// [VN] Phục dựng FDE #0130 tại 0x00f224..0x00f278 (84 byte)
//   0x00f224: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x00f228: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x00f22c: 910043fd  add      x29, sp, #0x10
//   0x00f230: f9410014  ldr      x20, [x0, #0x200]
//   0x00f234: aa0003f3  mov      x19, x0
//   0x00f238: 340000e1  cbz      w1, #0xf254
//   0x00f23c: f9400268  ldr      x8, [x19]
//   0x00f240: 5280006a  mov      w10, #3
//   0x00f244: aa1303e0  mov      x0, x19
//   0x00f248: f9400109  ldr      x9, [x8]
//   0x00f24c: b900290a  str      w10, [x8, #0x28]
//   0x00f250: d63f0120  blr      x9
//   0x00f254: b9403668  ldr      w8, [x19, #0x34]
//   0x00f258: 290cfe9f  stp      wzr, wzr, [x20, #0x64]
//   0x00f25c: b9006288  str      w8, [x20, #0x60]
//   0x00f260: b9416268  ldr      w8, [x19, #0x160]
uint64_t fde_0130_sub_00f224(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xB9403668ULL) + (x2 ^ 0x00F224ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x00f224: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x00f228: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x00f22c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410014ULL; // 0x00f230: ldr x20, [x0, #0x200]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x00f234: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E1ULL; // 0x00f238: cbz w1, #0xf254
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x00f23c: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280006AULL; // 0x00f240: mov w10, #3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x00f244: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x00f248: ldr x9, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0131 @ 0x00f278..0x00f508 (656 bytes)
// [VN] Phục dựng FDE #0131 tại 0x00f278..0x00f508 (656 byte)
//   0x00f278: d10243ff  sub      sp, sp, #0x90
//   0x00f27c: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x00f280: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x00f284: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x00f288: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x00f28c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x00f290: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x00f294: 910203fd  add      x29, sp, #0x80
//   0x00f298: b94000a8  ldr      w8, [x5]
//   0x00f29c: f9000fe4  str      x4, [sp, #0x18]
//   0x00f2a0: f90007e1  str      x1, [sp, #8]
//   0x00f2a4: b90027e6  str      w6, [sp, #0x24]
//   0x00f2a8: 6b06011f  cmp      w8, w6
//   0x00f2ac: 540011e2  b.hs     #0xf4e8
//   0x00f2b0: b9416008  ldr      w8, [x0, #0x160]
//   0x00f2b4: f9410013  ldr      x19, [x0, #0x200]
uint64_t fde_0131_sub_00f278(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x6B06011FULL) + (x2 ^ 0x00F278ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x00f278: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x00f27c: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x00f280: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x00f284: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x00f288: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x00f28c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x00f290: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x00f294: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xB94000A8ULL; // 0x00f298: ldr w8, [x5]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE4ULL; // 0x00f29c: str x4, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0132 @ 0x00f508..0x00f774 (620 bytes)
// [VN] Phục dựng FDE #0132 tại 0x00f508..0x00f774 (620 byte)
//   0x00f508: d10243ff  sub      sp, sp, #0x90
//   0x00f50c: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x00f510: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x00f514: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x00f518: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x00f51c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x00f520: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x00f524: 910203fd  add      x29, sp, #0x80
//   0x00f528: b9400048  ldr      w8, [x2]
//   0x00f52c: f9000be4  str      x4, [sp, #0x10]
//   0x00f530: f90013e1  str      x1, [sp, #0x20]
//   0x00f534: 6b03011f  cmp      w8, w3
//   0x00f538: 540010e2  b.hs     #0xf754
//   0x00f53c: f9410013  ldr      x19, [x0, #0x200]
//   0x00f540: 2a0603f7  mov      w23, w6
//   0x00f544: aa0503f4  mov      x20, x5
uint64_t fde_0132_sub_00f508(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x540010E2ULL) + (x2 ^ 0x00F508ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x00f508: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x00f50c: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x00f510: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x00f514: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x00f518: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x00f51c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x00f520: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x00f524: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400048ULL; // 0x00f528: ldr w8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BE4ULL; // 0x00f52c: str x4, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0133 @ 0x00f774..0x00f9a8 (564 bytes)
// [VN] Phục dựng FDE #0133 tại 0x00f774..0x00f9a8 (564 byte)
//   0x00f774: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x00f778: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00f77c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00f780: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00f784: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00f788: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00f78c: 910143fd  add      x29, sp, #0x50
//   0x00f790: f9400408  ldr      x8, [x0, #8]
//   0x00f794: 52800021  mov      w1, #1
//   0x00f798: 52800d02  mov      w2, #0x68
//   0x00f79c: aa0003f3  mov      x19, x0
//   0x00f7a0: f9400108  ldr      x8, [x8]
//   0x00f7a4: d63f0100  blr      x8
//   0x00f7a8: 90000008  adrp     x8, #0xf000
//   0x00f7ac: 90000009  adrp     x9, #0xf000
//   0x00f7b0: 9126a108  add      x8, x8, #0x9a8
uint64_t fde_0133_sub_00f774(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x00F774ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x00f774: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00f778: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00f77c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00f780: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00f784: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00f788: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00f78c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x00f790: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x00f794: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800D02ULL; // 0x00f798: mov w2, #0x68
    return acc;
}

// [EN] Reconstructed FDE #0134 @ 0x00f9a8..0x00f9ac (4 bytes)
// [VN] Phục dựng FDE #0134 tại 0x00f9a8..0x00f9ac (4 byte)
//   0x00f9a8: d65f03c0  ret      
uint64_t fde_0134_sub_00f9a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x00F9A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x00f9a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0135 @ 0x00f9ac..0x00fa4c (160 bytes)
// [VN] Phục dựng FDE #0135 tại 0x00f9ac..0x00fa4c (160 byte)
//   0x00f9ac: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x00f9b0: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00f9b4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00f9b8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00f9bc: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00f9c0: 910103fd  add      x29, sp, #0x40
//   0x00f9c4: b9405c08  ldr      w8, [x0, #0x5c]
//   0x00f9c8: 7100051f  cmp      w8, #1
//   0x00f9cc: 5400034b  b.lt     #0xfa34
//   0x00f9d0: f9411008  ldr      x8, [x0, #0x220]
//   0x00f9d4: f9403417  ldr      x23, [x0, #0x68]
//   0x00f9d8: 2a0403f3  mov      w19, w4
//   0x00f9dc: aa0303f4  mov      x20, x3
//   0x00f9e0: aa0003f5  mov      x21, x0
//   0x00f9e4: aa0103f6  mov      x22, x1
//   0x00f9e8: aa1f03f8  mov      x24, xzr
uint64_t fde_0135_sub_00f9ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0xAA0303F4ULL) + (x2 ^ 0x00F9ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x00f9ac: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00f9b0: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00f9b4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00f9b8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00f9bc: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00f9c0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405C08ULL; // 0x00f9c4: ldr w8, [x0, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x00f9c8: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400034BULL; // 0x00f9cc: b.lt #0xfa34
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411008ULL; // 0x00f9d0: ldr x8, [x0, #0x220]
    return acc;
}

// [EN] Reconstructed FDE #0136 @ 0x00fa4c..0x00fbf8 (428 bytes)
// [VN] Phục dựng FDE #0136 tại 0x00fa4c..0x00fbf8 (428 byte)
//   0x00fa4c: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x00fa50: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00fa54: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00fa58: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00fa5c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00fa60: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00fa64: 910143fd  add      x29, sp, #0x50
//   0x00fa68: b9416008  ldr      w8, [x0, #0x160]
//   0x00fa6c: b9401c29  ldr      w9, [x1, #0x1c]
//   0x00fa70: aa0303f3  mov      x19, x3
//   0x00fa74: aa0203f4  mov      x20, x2
//   0x00fa78: 11000908  add      w8, w8, #2
//   0x00fa7c: aa0003f6  mov      x22, x0
//   0x00fa80: aa0103f5  mov      x21, x1
//   0x00fa84: 7100051f  cmp      w8, #1
//   0x00fa88: 531d7138  lsl      w24, w9, #3
uint64_t fde_0136_sub_00fa4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x00FA4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x00fa4c: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00fa50: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00fa54: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00fa58: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00fa5c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00fa60: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00fa64: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416008ULL; // 0x00fa68: ldr w8, [x0, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C29ULL; // 0x00fa6c: ldr w9, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x00fa70: mov x19, x3
    return acc;
}

// [EN] Reconstructed FDE #0137 @ 0x00fbf8..0x00fc8c (148 bytes)
// [VN] Phục dựng FDE #0137 tại 0x00fbf8..0x00fc8c (148 byte)
//   0x00fbf8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x00fbfc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x00fc00: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x00fc04: 910083fd  add      x29, sp, #0x20
//   0x00fc08: b9416004  ldr      w4, [x0, #0x160]
//   0x00fc0c: b9403005  ldr      w5, [x0, #0x30]
//   0x00fc10: aa0303f3  mov      x19, x3
//   0x00fc14: aa0003f4  mov      x20, x0
//   0x00fc18: aa0103f5  mov      x21, x1
//   0x00fc1c: aa0203e0  mov      x0, x2
//   0x00fc20: 2a1f03e1  mov      w1, wzr
//   0x00fc24: aa0303e2  mov      x2, x3
//   0x00fc28: 2a1f03e3  mov      w3, wzr
//   0x00fc2c: 94000273  bl       #0x105f8
//   0x00fc30: b9416296  ldr      w22, [x20, #0x160]
//   0x00fc34: 710006df  cmp      w22, #1
uint64_t fde_0137_sub_00fbf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x2A1F03E3ULL) + (x2 ^ 0x00FBF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x00fbf8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x00fbfc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x00fc00: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x00fc04: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416004ULL; // 0x00fc08: ldr w4, [x0, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403005ULL; // 0x00fc0c: ldr w5, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x00fc10: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x00fc14: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x00fc18: mov x21, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E0ULL; // 0x00fc1c: mov x0, x2
    return acc;
}

// [EN] Reconstructed FDE #0138 @ 0x00fc8c..0x00fd84 (248 bytes)
// [VN] Phục dựng FDE #0138 tại 0x00fc8c..0x00fd84 (248 byte)
//   0x00fc8c: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x00fc90: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00fc94: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00fc98: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00fc9c: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00fca0: 910103fd  add      x29, sp, #0x40
//   0x00fca4: b9416018  ldr      w24, [x0, #0x160]
//   0x00fca8: b9401c37  ldr      w23, [x1, #0x1c]
//   0x00fcac: aa0303f3  mov      x19, x3
//   0x00fcb0: aa0103f4  mov      x20, x1
//   0x00fcb4: 7100071f  cmp      w24, #1
//   0x00fcb8: aa0203f5  mov      x21, x2
//   0x00fcbc: 5400022b  b.lt     #0xfd00
//   0x00fcc0: b9403019  ldr      w25, [x0, #0x30]
//   0x00fcc4: 531c6ee8  lsl      w8, w23, #4
//   0x00fcc8: 4b190109  sub      w9, w8, w25
uint64_t fde_0138_sub_00fc8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x5400022BULL) + (x2 ^ 0x00FC8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x00fc8c: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00fc90: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00fc94: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00fc98: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00fc9c: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00fca0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416018ULL; // 0x00fca4: ldr w24, [x0, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C37ULL; // 0x00fca8: ldr w23, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x00fcac: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x00fcb0: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0139 @ 0x00fd84..0x00ffe0 (604 bytes)
// [VN] Phục dựng FDE #0139 tại 0x00fd84..0x00ffe0 (604 byte)
//   0x00fd84: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x00fd88: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x00fd8c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x00fd90: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x00fd94: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x00fd98: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x00fd9c: 910143fd  add      x29, sp, #0x50
//   0x00fda0: b9416008  ldr      w8, [x0, #0x160]
//   0x00fda4: b9401c38  ldr      w24, [x1, #0x1c]
//   0x00fda8: aa0303f3  mov      x19, x3
//   0x00fdac: aa0003f6  mov      x22, x0
//   0x00fdb0: 11000908  add      w8, w8, #2
//   0x00fdb4: aa0103f4  mov      x20, x1
//   0x00fdb8: 7100051f  cmp      w8, #1
//   0x00fdbc: aa0203f5  mov      x21, x2
//   0x00fdc0: 5400024b  b.lt     #0xfe08
uint64_t fde_0139_sub_00fd84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x00FD84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x00fd84: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x00fd88: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x00fd8c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x00fd90: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x00fd94: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x00fd98: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x00fd9c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416008ULL; // 0x00fda0: ldr w8, [x0, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C38ULL; // 0x00fda4: ldr w24, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x00fda8: mov x19, x3
    return acc;
}

// [EN] Reconstructed FDE #0140 @ 0x00ffe0..0x0100fc (284 bytes)
// [VN] Phục dựng FDE #0140 tại 0x00ffe0..0x0100fc (284 byte)
//   0x00ffe0: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x00ffe4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x00ffe8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x00ffec: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x00fff0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x00fff4: 910103fd  add      x29, sp, #0x40
//   0x00fff8: b9416018  ldr      w24, [x0, #0x160]
//   0x00fffc: b9401c37  ldr      w23, [x1, #0x1c]
//   0x010000: aa0303f3  mov      x19, x3
//   0x010004: aa0103f4  mov      x20, x1
//   0x010008: 7100071f  cmp      w24, #1
//   0x01000c: aa0203f5  mov      x21, x2
//   0x010010: 5400022b  b.lt     #0x10054
//   0x010014: b9403019  ldr      w25, [x0, #0x30]
//   0x010018: 531c6ee8  lsl      w8, w23, #4
//   0x01001c: 4b190109  sub      w9, w8, w25
uint64_t fde_0140_sub_00ffe0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x5400022BULL) + (x2 ^ 0x00FFE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x00ffe0: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x00ffe4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x00ffe8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x00ffec: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x00fff0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x00fff4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB9416018ULL; // 0x00fff8: ldr w24, [x0, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9401C37ULL; // 0x00fffc: ldr w23, [x1, #0x1c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F3ULL; // 0x010000: mov x19, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x010004: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #0141 @ 0x0100fc..0x0102ec (496 bytes)
// [VN] Phục dựng FDE #0141 tại 0x0100fc..0x0102ec (496 byte)
//   0x0100fc: d101c3ff  sub      sp, sp, #0x70
//   0x010100: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x010104: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x010108: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01010c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x010110: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x010114: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x010118: 910183fd  add      x29, sp, #0x60
//   0x01011c: b9415c08  ldr      w8, [x0, #0x15c]
//   0x010120: b941601c  ldr      w28, [x0, #0x160]
//   0x010124: 29414029  ldp      w9, w16, [x1, #8]
//   0x010128: b9401c2a  ldr      w10, [x1, #0x1c]
//   0x01012c: aa0303f3  mov      x19, x3
//   0x010130: aa0203f4  mov      x20, x2
//   0x010134: 1ac90d17  sdiv     w23, w8, w9
//   0x010138: 1ad00f98  sdiv     w24, w28, w16
uint64_t fde_0141_sub_0100fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0303F3ULL) + (x2 ^ 0x0100FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0100fc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x010100: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x010104: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x010108: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01010c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x010110: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x010114: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x010118: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9415C08ULL; // 0x01011c: ldr w8, [x0, #0x15c]
    acc = (acc * 0x100000001B3ULL) ^ 0xB941601CULL; // 0x010120: ldr w28, [x0, #0x160]
    return acc;
}

// [EN] Reconstructed FDE #0142 @ 0x0102ec..0x0102f0 (4 bytes)
// [VN] Phục dựng FDE #0142 tại 0x0102ec..0x0102f0 (4 byte)
//   0x0102ec: 17fff52a  b        #0xd794
uint64_t fde_0142_sub_0102ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFF52AULL) + (x1 ^ 0x17FFF52AULL) + (x2 ^ 0x0102ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF52AULL; // 0x0102ec: b #0xd794
    return acc;
}

// [EN] Reconstructed FDE #0143 @ 0x0102f0..0x010348 (88 bytes)
// [VN] Phục dựng FDE #0143 tại 0x0102f0..0x010348 (88 byte)
//   0x0102f0: 90000008  adrp     x8, #0x10000
//   0x0102f4: 90000009  adrp     x9, #0x10000
//   0x0102f8: 910d2108  add      x8, x8, #0x348
//   0x0102fc: 910dd129  add      x9, x9, #0x374
//   0x010300: 9000000a  adrp     x10, #0x10000
//   0x010304: a9002408  stp      x8, x9, [x0]
//   0x010308: 90000008  adrp     x8, #0x10000
//   0x01030c: 910f614a  add      x10, x10, #0x3d8
//   0x010310: 91111108  add      x8, x8, #0x444
//   0x010314: a901200a  stp      x10, x8, [x0, #0x10]
//   0x010318: 90000008  adrp     x8, #0x10000
//   0x01031c: 91148108  add      x8, x8, #0x520
//   0x010320: b9007c1f  str      wzr, [x0, #0x7c]
//   0x010324: b900281f  str      wzr, [x0, #0x28]
//   0x010328: f9001008  str      x8, [x0, #0x20]
//   0x01032c: f0000288  adrp     x8, #0x63000
uint64_t fde_0143_sub_0102f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000008ULL) + (x1 ^ 0xB9007C1FULL) + (x2 ^ 0x0102F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x0102f0: adrp x8, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x0102f4: adrp x9, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x910D2108ULL; // 0x0102f8: add x8, x8, #0x348
    acc = (acc * 0x100000001B3ULL) ^ 0x910DD129ULL; // 0x0102fc: add x9, x9, #0x374
    acc = (acc * 0x100000001B3ULL) ^ 0x9000000AULL; // 0x010300: adrp x10, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0xA9002408ULL; // 0x010304: stp x8, x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x010308: adrp x8, #0x10000
    acc = (acc * 0x100000001B3ULL) ^ 0x910F614AULL; // 0x01030c: add x10, x10, #0x3d8
    acc = (acc * 0x100000001B3ULL) ^ 0x91111108ULL; // 0x010310: add x8, x8, #0x444
    acc = (acc * 0x100000001B3ULL) ^ 0xA901200AULL; // 0x010314: stp x10, x8, [x0, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0144 @ 0x010348..0x010374 (44 bytes)
// [VN] Phục dựng FDE #0144 tại 0x010348..0x010374 (44 byte)
//   0x010348: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x01034c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x010350: 910043fd  add      x29, sp, #0x10
//   0x010354: f9400008  ldr      x8, [x0]
//   0x010358: aa0003f3  mov      x19, x0
//   0x01035c: f9400908  ldr      x8, [x8, #0x10]
//   0x010360: d63f0100  blr      x8
//   0x010364: aa1303e0  mov      x0, x19
//   0x010368: 97fff50b  bl       #0xd794
//   0x01036c: 52800020  mov      w0, #1
//   0x010370: 97ffcf60  bl       #0x40f0
uint64_t fde_0144_sub_010348(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFCF60ULL) + (x2 ^ 0x010348ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010348: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x01034c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x010350: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x010354: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x010358: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400908ULL; // 0x01035c: ldr x8, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x010360: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x010364: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFF50BULL; // 0x010368: bl #0xd794
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x01036c: mov w0, #1
    return acc;
}

// [EN] Reconstructed FDE #0145 @ 0x010374..0x0103d8 (100 bytes)
// [VN] Phục dựng FDE #0145 tại 0x010374..0x0103d8 (100 byte)
//   0x010374: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x010378: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x01037c: 910043fd  add      x29, sp, #0x10
//   0x010380: f9400013  ldr      x19, [x0]
//   0x010384: 37f80101  tbnz     w1, #0x1f, #0x103a4
//   0x010388: b9407e68  ldr      w8, [x19, #0x7c]
//   0x01038c: 6b01011f  cmp      w8, w1
//   0x010390: 540001eb  b.lt     #0x103cc
//   0x010394: f9400a61  ldr      x1, [x19, #0x10]
//   0x010398: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x01039c: f84207f3  ldr      x19, [sp], #0x20
//   0x0103a0: d61f0020  br       x1
//   0x0103a4: f9404268  ldr      x8, [x19, #0x80]
//   0x0103a8: b4000088  cbz      x8, #0x103b8
//   0x0103ac: b9407e69  ldr      w9, [x19, #0x7c]
//   0x0103b0: 71000d3f  cmp      w9, #3
uint64_t fde_0145_sub_010374(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9404268ULL) + (x2 ^ 0x010374ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x010374: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x010378: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x01037c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400013ULL; // 0x010380: ldr x19, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x37F80101ULL; // 0x010384: tbnz w1, #0x1f, #0x103a4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9407E68ULL; // 0x010388: ldr w8, [x19, #0x7c]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B01011FULL; // 0x01038c: cmp w8, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x540001EBULL; // 0x010390: b.lt #0x103cc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400A61ULL; // 0x010394: ldr x1, [x19, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x010398: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0146 @ 0x0103d8..0x010444 (108 bytes)
// [VN] Phục dựng FDE #0146 tại 0x0103d8..0x010444 (108 byte)
//   0x0103d8: d103c3ff  sub      sp, sp, #0xf0
//   0x0103dc: f9006bf3  str      x19, [sp, #0xd0]
//   0x0103e0: a90e7bfd  stp      x29, x30, [sp, #0xe0]
//   0x0103e4: 910383fd  add      x29, sp, #0xe0
//   0x0103e8: d53bd053  mrs      x19, tpidr_el0
//   0x0103ec: f9401668  ldr      x8, [x19, #0x28]
//   0x0103f0: 910003e1  mov      x1, sp
//   0x0103f4: f81e83a8  stur     x8, [x29, #-0x18]
//   0x0103f8: f9400008  ldr      x8, [x0]
//   0x0103fc: f9400d08  ldr      x8, [x8, #0x18]
//   0x010400: d63f0100  blr      x8
//   0x010404: f0000288  adrp     x8, #0x63000
//   0x010408: f9467508  ldr      x8, [x8, #0xce8]
//   0x01040c: b0000201  adrp     x1, #0x51000
//   0x010410: 913da821  add      x1, x1, #0xf6a
//   0x010414: 910003e2  mov      x2, sp
uint64_t fde_0146_sub_0103d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD103C3FFULL) + (x1 ^ 0xF9467508ULL) + (x2 ^ 0x0103D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD103C3FFULL; // 0x0103d8: sub sp, sp, #0xf0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9006BF3ULL; // 0x0103dc: str x19, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E7BFDULL; // 0x0103e0: stp x29, x30, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910383FDULL; // 0x0103e4: add x29, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0103e8: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0103ec: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x0103f0: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x0103f4: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0103f8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400D08ULL; // 0x0103fc: ldr x8, [x8, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #0147 @ 0x010444..0x010520 (220 bytes)
// [VN] Phục dựng FDE #0147 tại 0x010444..0x010520 (220 byte)
//   0x010444: d100c3ff  sub      sp, sp, #0x30
//   0x010448: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x01044c: 910083fd  add      x29, sp, #0x20
//   0x010450: f9400008  ldr      x8, [x0]
//   0x010454: aa0103e0  mov      x0, x1
//   0x010458: b9402909  ldr      w9, [x8, #0x28]
//   0x01045c: 7100053f  cmp      w9, #1
//   0x010460: 5400008b  b.lt     #0x10470
//   0x010464: b940910a  ldr      w10, [x8, #0x90]
//   0x010468: 6b0a013f  cmp      w9, w10
//   0x01046c: 5400050d  b.le     #0x1050c
//   0x010470: f9404d0a  ldr      x10, [x8, #0x98]
//   0x010474: b400012a  cbz      x10, #0x10498
//   0x010478: b940a10b  ldr      w11, [x8, #0xa0]
//   0x01047c: 6b0b012b  subs     w11, w9, w11
//   0x010480: 540000cb  b.lt     #0x10498
uint64_t fde_0147_sub_010444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xB400012AULL) + (x2 ^ 0x010444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x010444: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x010448: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x01044c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x010450: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x010454: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402909ULL; // 0x010458: ldr w9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100053FULL; // 0x01045c: cmp w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400008BULL; // 0x010460: b.lt #0x10470
    acc = (acc * 0x100000001B3ULL) ^ 0xB940910AULL; // 0x010464: ldr w10, [x8, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0A013FULL; // 0x010468: cmp w9, w10
    return acc;
}

// [EN] Reconstructed FDE #0148 @ 0x010520..0x010530 (16 bytes)
// [VN] Phục dựng FDE #0148 tại 0x010520..0x010530 (16 byte)
//   0x010520: f9400008  ldr      x8, [x0]
//   0x010524: f900411f  str      xzr, [x8, #0x80]
//   0x010528: b900291f  str      wzr, [x8, #0x28]
//   0x01052c: d65f03c0  ret      
uint64_t fde_0148_sub_010520(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x010520ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x010520: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900411FULL; // 0x010524: str xzr, [x8, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900291FULL; // 0x010528: str wzr, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01052c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0149 @ 0x010530..0x0105d4 (164 bytes)
// [VN] Phục dựng FDE #0149 tại 0x010530..0x0105d4 (164 byte)
//   0x010530: d10483ff  sub      sp, sp, #0x120
//   0x010534: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x010538: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x01053c: 910443fd  add      x29, sp, #0x110
//   0x010540: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x010544: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x010548: f90057e7  str      x7, [sp, #0xa8]
//   0x01054c: ad0007e0  stp      q0, q1, [sp]
//   0x010550: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x010554: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x010558: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x01055c: d53bd053  mrs      x19, tpidr_el0
//   0x010560: f940166a  ldr      x10, [x19, #0x28]
//   0x010564: 910223eb  add      x11, sp, #0x88
//   0x010568: 928004ed  mov      x13, #-0x28
//   0x01056c: 910043ac  add      x12, x29, #0x10
uint64_t fde_0149_sub_010530(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xF940166AULL) + (x2 ^ 0x010530ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x010530: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x010534: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x010538: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x01053c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x010540: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x010544: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x010548: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x01054c: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x010550: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x010554: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #0150 @ 0x0105d4..0x0105e4 (16 bytes)
// [VN] Phục dựng FDE #0150 tại 0x0105d4..0x0105e4 (16 byte)
//   0x0105d4: 8b010008  add      x8, x0, x1
//   0x0105d8: d1000508  sub      x8, x8, #1
//   0x0105dc: 9ac10d00  sdiv     x0, x8, x1
//   0x0105e0: d65f03c0  ret      
uint64_t fde_0150_sub_0105d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x8B010008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0105D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010008ULL; // 0x0105d4: add x8, x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000508ULL; // 0x0105d8: sub x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC10D00ULL; // 0x0105dc: sdiv x0, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0105e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0151 @ 0x0105e4..0x0105f8 (20 bytes)
// [VN] Phục dựng FDE #0151 tại 0x0105e4..0x0105f8 (20 byte)
//   0x0105e4: 8b010008  add      x8, x0, x1
//   0x0105e8: d1000508  sub      x8, x8, #1
//   0x0105ec: 9ac10d08  sdiv     x8, x8, x1
//   0x0105f0: 9b017d00  mul      x0, x8, x1
//   0x0105f4: d65f03c0  ret      
uint64_t fde_0151_sub_0105e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x8B010008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0105E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010008ULL; // 0x0105e4: add x8, x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000508ULL; // 0x0105e8: sub x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9AC10D08ULL; // 0x0105ec: sdiv x8, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x9B017D00ULL; // 0x0105f0: mul x0, x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0105f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0152 @ 0x0105f8..0x01064c (84 bytes)
// [VN] Phục dựng FDE #0152 tại 0x0105f8..0x01064c (84 byte)
//   0x0105f8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0105fc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x010600: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x010604: 910083fd  add      x29, sp, #0x20
//   0x010608: 7100049f  cmp      w4, #1
//   0x01060c: 5400018b  b.lt     #0x1063c
//   0x010610: 2a0403f3  mov      w19, w4
//   0x010614: 2a0503f4  mov      w20, w5
//   0x010618: 8b23cc55  add      x21, x2, w3, sxtw #3
//   0x01061c: 8b21cc16  add      x22, x0, w1, sxtw #3
//   0x010620: f84086c1  ldr      x1, [x22], #8
//   0x010624: f84086a0  ldr      x0, [x21], #8
//   0x010628: aa1403e2  mov      x2, x20
//   0x01062c: 97ffcdf9  bl       #0x3e10
//   0x010630: 51000673  sub      w19, w19, #1
//   0x010634: 7100027f  cmp      w19, #0
uint64_t fde_0152_sub_0105f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA1403E2ULL) + (x2 ^ 0x0105F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0105f8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0105fc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x010600: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x010604: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x010608: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400018BULL; // 0x01060c: b.lt #0x1063c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F3ULL; // 0x010610: mov w19, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F4ULL; // 0x010614: mov w20, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x8B23CC55ULL; // 0x010618: add x21, x2, w3, sxtw #3
    acc = (acc * 0x100000001B3ULL) ^ 0x8B21CC16ULL; // 0x01061c: add x22, x0, w1, sxtw #3
    return acc;
}

// [EN] Reconstructed FDE #0153 @ 0x01064c..0x010658 (12 bytes)
// [VN] Phục dựng FDE #0153 tại 0x01064c..0x010658 (12 byte)
//   0x01064c: aa0103e2  mov      x2, x1
//   0x010650: 2a1f03e1  mov      w1, wzr
//   0x010654: 17ffce7f  b        #0x4050
uint64_t fde_0153_sub_01064c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E2ULL) + (x1 ^ 0x17FFCE7FULL) + (x2 ^ 0x01064CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E2ULL; // 0x01064c: mov x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x010650: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCE7FULL; // 0x010654: b #0x4050
    return acc;
}

// [EN] Reconstructed FDE #0154 @ 0x010658..0x0107f8 (416 bytes)
// [VN] Phục dựng FDE #0154 tại 0x010658..0x0107f8 (416 byte)
//   0x010658: d10143ff  sub      sp, sp, #0x50
//   0x01065c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x010660: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x010664: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x010668: 910103fd  add      x29, sp, #0x40
//   0x01066c: d53bd056  mrs      x22, tpidr_el0
//   0x010670: f94016c8  ldr      x8, [x22, #0x28]
//   0x010674: aa0003f4  mov      x20, x0
//   0x010678: f9000fe8  str      x8, [sp, #0x18]
//   0x01067c: f900041f  str      xzr, [x0, #8]
//   0x010680: 94000bcb  bl       #0x135ac
//   0x010684: aa0003f5  mov      x21, x0
//   0x010688: f9000be0  str      x0, [sp, #0x10]
//   0x01068c: 52801501  mov      w1, #0xa8
//   0x010690: aa1403e0  mov      x0, x20
//   0x010694: 94000bb1  bl       #0x13558
uint64_t fde_0154_sub_010658(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF9000BE0ULL) + (x2 ^ 0x010658ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x010658: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x01065c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x010660: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x010664: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x010668: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01066c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x010670: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x010674: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x010678: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF900041FULL; // 0x01067c: str xzr, [x0, #8]
    return acc;
}

// [EN] Reconstructed FDE #0155 @ 0x0107f8..0x0109d4 (476 bytes)
// [VN] Phục dựng FDE #0155 tại 0x0107f8..0x0109d4 (476 byte)
//   0x0107f8: fc1a0fe8  str      d8, [sp, #-0x60]!
//   0x0107fc: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x010800: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x010804: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x010808: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x01080c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x010810: 910143fd  add      x29, sp, #0x50
//   0x010814: f9400416  ldr      x22, [x0, #8]
//   0x010818: 5299401a  mov      w26, #0xca00
//   0x01081c: 72a7735a  movk     w26, #0x3b9a, lsl #16
//   0x010820: aa0203f5  mov      x21, x2
//   0x010824: aa0003f3  mov      x19, x0
//   0x010828: eb1a005f  cmp      x2, x26
//   0x01082c: 2a0103f4  mov      w20, w1
//   0x010830: 54000129  b.ls     #0x10854
//   0x010834: d0000209  adrp     x9, #0x52000
uint64_t fde_0155_sub_0107f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xFC1A0FE8ULL) + (x1 ^ 0xEB1A005FULL) + (x2 ^ 0x0107F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xFC1A0FE8ULL; // 0x0107f8: str d8, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0107fc: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x010800: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x010804: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x010808: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x01080c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x010810: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400416ULL; // 0x010814: ldr x22, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x5299401AULL; // 0x010818: mov w26, #0xca00
    acc = (acc * 0x100000001B3ULL) ^ 0x72A7735AULL; // 0x01081c: movk w26, #0x3b9a, lsl #16
    return acc;
}

// [EN] Reconstructed FDE #0156 @ 0x0109d4..0x010b00 (300 bytes)
// [VN] Phục dựng FDE #0156 tại 0x0109d4..0x010b00 (300 byte)
//   0x0109d4: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x0109d8: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0109dc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0109e0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0109e4: 9100c3fd  add      x29, sp, #0x30
//   0x0109e8: f9400417  ldr      x23, [x0, #8]
//   0x0109ec: 52994016  mov      w22, #0xca00
//   0x0109f0: 72a77356  movk     w22, #0x3b9a, lsl #16
//   0x0109f4: aa0203f5  mov      x21, x2
//   0x0109f8: aa0003f4  mov      x20, x0
//   0x0109fc: eb16005f  cmp      x2, x22
//   0x010a00: 2a0103f3  mov      w19, w1
//   0x010a04: 54000129  b.ls     #0x10a28
//   0x010a08: d0000209  adrp     x9, #0x52000
//   0x010a0c: f9400288  ldr      x8, [x20]
//   0x010a10: fd406920  ldr      d0, [x9, #0xd0]
uint64_t fde_0156_sub_0109d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x54000129ULL) + (x2 ^ 0x0109D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x0109d4: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0109d8: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0109dc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0109e0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0109e4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400417ULL; // 0x0109e8: ldr x23, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52994016ULL; // 0x0109ec: mov w22, #0xca00
    acc = (acc * 0x100000001B3ULL) ^ 0x72A77356ULL; // 0x0109f0: movk w22, #0x3b9a, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x0109f4: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0109f8: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #0157 @ 0x010b00..0x010c28 (296 bytes)
// [VN] Phục dựng FDE #0157 tại 0x010b00..0x010c28 (296 byte)
//   0x010b00: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x010b04: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x010b08: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x010b0c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x010b10: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x010b14: 910103fd  add      x29, sp, #0x40
//   0x010b18: 52993d18  mov      w24, #0xc9e8
//   0x010b1c: f9400419  ldr      x25, [x0, #8]
//   0x010b20: 72a77358  movk     w24, #0x3b9a, lsl #16
//   0x010b24: 11006308  add      w8, w24, #0x18
//   0x010b28: 2a0303f3  mov      w19, w3
//   0x010b2c: 2a0203f6  mov      w22, w2
//   0x010b30: aa0003f4  mov      x20, x0
//   0x010b34: 6b08005f  cmp      w2, w8
//   0x010b38: 2a0103f5  mov      w21, w1
//   0x010b3c: 54000129  b.ls     #0x10b60
uint64_t fde_0157_sub_010b00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x010B00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x010b00: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x010b04: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x010b08: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x010b0c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x010b10: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x010b14: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x52993D18ULL; // 0x010b18: mov w24, #0xc9e8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400419ULL; // 0x010b1c: ldr x25, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x72A77358ULL; // 0x010b20: movk w24, #0x3b9a, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x11006308ULL; // 0x010b24: add w8, w24, #0x18
    return acc;
}

// [EN] Reconstructed FDE #0158 @ 0x010c28..0x010d20 (248 bytes)
// [VN] Phục dựng FDE #0158 tại 0x010c28..0x010d20 (248 byte)
//   0x010c28: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x010c2c: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x010c30: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x010c34: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x010c38: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x010c3c: 910103fd  add      x29, sp, #0x40
//   0x010c40: 2a0203e8  mov      w8, w2
//   0x010c44: f9400416  ldr      x22, [x0, #8]
//   0x010c48: d379e117  lsl      x23, x8, #7
//   0x010c4c: 52993d08  mov      w8, #0xc9e8
//   0x010c50: 72a77348  movk     w8, #0x3b9a, lsl #16
//   0x010c54: 9ad70918  udiv     x24, x8, x23
//   0x010c58: 2a0303f3  mov      w19, w3
//   0x010c5c: aa0003f4  mov      x20, x0
//   0x010c60: f100031f  cmp      x24, #0
//   0x010c64: 2a0103f5  mov      w21, w1
uint64_t fde_0158_sub_010c28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x2A0303F3ULL) + (x2 ^ 0x010C28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x010c28: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x010c2c: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x010c30: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x010c34: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x010c38: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x010c3c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E8ULL; // 0x010c40: mov w8, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400416ULL; // 0x010c44: ldr x22, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD379E117ULL; // 0x010c48: lsl x23, x8, #7
    acc = (acc * 0x100000001B3ULL) ^ 0x52993D08ULL; // 0x010c4c: mov w8, #0xc9e8
    return acc;
}

// [EN] Reconstructed FDE #0159 @ 0x010d20..0x010dc0 (160 bytes)
// [VN] Phục dựng FDE #0159 tại 0x010d20..0x010dc0 (160 byte)
//   0x010d20: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x010d24: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x010d28: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x010d2c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x010d30: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x010d34: 910103fd  add      x29, sp, #0x40
//   0x010d38: f9400419  ldr      x25, [x0, #8]
//   0x010d3c: 2a0503f3  mov      w19, w5
//   0x010d40: 2a0403f5  mov      w21, w4
//   0x010d44: 2a0303f4  mov      w20, w3
//   0x010d48: aa0003f7  mov      x23, x0
//   0x010d4c: 2a0103f8  mov      w24, w1
//   0x010d50: 7100043f  cmp      w1, #1
//   0x010d54: 2a0203f6  mov      w22, w2
//   0x010d58: 54000100  b.eq     #0x10d78
//   0x010d5c: f94002e8  ldr      x8, [x23]
uint64_t fde_0159_sub_010d20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x7100043FULL) + (x2 ^ 0x010D20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x010d20: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x010d24: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x010d28: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x010d2c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x010d30: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x010d34: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400419ULL; // 0x010d38: ldr x25, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F3ULL; // 0x010d3c: mov w19, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F5ULL; // 0x010d40: mov w21, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x010d44: mov w20, w3
    return acc;
}

// [EN] Reconstructed FDE #0160 @ 0x010dc0..0x010e60 (160 bytes)
// [VN] Phục dựng FDE #0160 tại 0x010dc0..0x010e60 (160 byte)
//   0x010dc0: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x010dc4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x010dc8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x010dcc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x010dd0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x010dd4: 910103fd  add      x29, sp, #0x40
//   0x010dd8: f9400419  ldr      x25, [x0, #8]
//   0x010ddc: 2a0503f3  mov      w19, w5
//   0x010de0: 2a0403f5  mov      w21, w4
//   0x010de4: 2a0303f4  mov      w20, w3
//   0x010de8: aa0003f7  mov      x23, x0
//   0x010dec: 2a0103f8  mov      w24, w1
//   0x010df0: 7100043f  cmp      w1, #1
//   0x010df4: 2a0203f6  mov      w22, w2
//   0x010df8: 54000100  b.eq     #0x10e18
//   0x010dfc: f94002e8  ldr      x8, [x23]
uint64_t fde_0160_sub_010dc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0x7100043FULL) + (x2 ^ 0x010DC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x010dc0: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x010dc4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x010dc8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x010dcc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x010dd0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x010dd4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400419ULL; // 0x010dd8: ldr x25, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503F3ULL; // 0x010ddc: mov w19, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F5ULL; // 0x010de0: mov w21, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x010de4: mov w20, w3
    return acc;
}

// [EN] Reconstructed FDE #0161 @ 0x010e60..0x01128c (1068 bytes)
// [VN] Phục dựng FDE #0161 tại 0x010e60..0x01128c (1068 byte)
//   0x010e60: d10283ff  sub      sp, sp, #0xa0
//   0x010e64: fd0013ea  str      d10, [sp, #0x20]
//   0x010e68: 6d0323e9  stp      d9, d8, [sp, #0x30]
//   0x010e6c: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x010e70: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x010e74: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x010e78: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x010e7c: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x010e80: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x010e84: 910243fd  add      x29, sp, #0x90
//   0x010e88: f9400418  ldr      x24, [x0, #8]
//   0x010e8c: aa0003f3  mov      x19, x0
//   0x010e90: f9404716  ldr      x22, [x24, #0x88]
//   0x010e94: b4000376  cbz      x22, #0x10f00
//   0x010e98: d0000208  adrp     x8, #0x52000
//   0x010e9c: fd407908  ldr      d8, [x8, #0xf0]
uint64_t fde_0161_sub_010e60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xF9404716ULL) + (x2 ^ 0x010E60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x010e60: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xFD0013EAULL; // 0x010e64: str d10, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6D0323E9ULL; // 0x010e68: stp d9, d8, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x010e6c: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x010e70: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x010e74: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x010e78: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x010e7c: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x010e80: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x010e84: add x29, sp, #0x90
    return acc;
}

// [EN] Reconstructed FDE #0162 @ 0x01128c..0x011608 (892 bytes)
// [VN] Phục dựng FDE #0162 tại 0x01128c..0x011608 (892 byte)
//   0x01128c: d101c3ff  sub      sp, sp, #0x70
//   0x011290: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x011294: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x011298: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x01129c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0112a0: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0112a4: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0112a8: 910183fd  add      x29, sp, #0x60
//   0x0112ac: b9400828  ldr      w8, [x1, #8]
//   0x0112b0: 0b02007b  add      w27, w3, w2
//   0x0112b4: 2a0303f6  mov      w22, w3
//   0x0112b8: aa0103f3  mov      x19, x1
//   0x0112bc: 2a0203f4  mov      w20, w2
//   0x0112c0: 6b08037f  cmp      w27, w8
//   0x0112c4: aa0003f7  mov      x23, x0
//   0x0112c8: b9000fe4  str      w4, [sp, #0xc]
uint64_t fde_0162_sub_01128c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x01128CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x01128c: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x011290: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x011294: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x011298: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x01129c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0112a0: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0112a4: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0112a8: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400828ULL; // 0x0112ac: ldr w8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B02007BULL; // 0x0112b0: add w27, w3, w2
    return acc;
}

// [EN] Reconstructed FDE #0163 @ 0x011608..0x011990 (904 bytes)
// [VN] Phục dựng FDE #0163 tại 0x011608..0x011990 (904 byte)
//   0x011608: d101c3ff  sub      sp, sp, #0x70
//   0x01160c: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x011610: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x011614: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x011618: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x01161c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x011620: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x011624: 910183fd  add      x29, sp, #0x60
//   0x011628: b9400828  ldr      w8, [x1, #8]
//   0x01162c: 0b02007b  add      w27, w3, w2
//   0x011630: 2a0303f6  mov      w22, w3
//   0x011634: aa0103f3  mov      x19, x1
//   0x011638: 2a0203f4  mov      w20, w2
//   0x01163c: 6b08037f  cmp      w27, w8
//   0x011640: aa0003f7  mov      x23, x0
//   0x011644: b9000fe4  str      w4, [sp, #0xc]
uint64_t fde_0163_sub_011608(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x011608ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x011608: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x01160c: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x011610: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x011614: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x011618: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x01161c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x011620: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x011624: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400828ULL; // 0x011628: ldr w8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B02007BULL; // 0x01162c: add w27, w3, w2
    return acc;
}

// [EN] Reconstructed FDE #0164 @ 0x011990..0x011ae8 (344 bytes)
// [VN] Phục dựng FDE #0164 tại 0x011990..0x011ae8 (344 byte)
//   0x011990: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x011994: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x011998: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x01199c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0119a0: 9100c3fd  add      x29, sp, #0x30
//   0x0119a4: f9400415  ldr      x21, [x0, #8]
//   0x0119a8: aa0003f3  mov      x19, x0
//   0x0119ac: 2a0103f4  mov      w20, w1
//   0x0119b0: 7100083f  cmp      w1, #2
//   0x0119b4: 54000123  b.lo     #0x119d8
//   0x0119b8: f9400268  ldr      x8, [x19]
//   0x0119bc: 528001e9  mov      w9, #0xf
//   0x0119c0: aa1303e0  mov      x0, x19
//   0x0119c4: 29055109  stp      w9, w20, [x8, #0x28]
//   0x0119c8: f9400268  ldr      x8, [x19]
//   0x0119cc: f9400108  ldr      x8, [x8]
uint64_t fde_0164_sub_011990(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xAA1303E0ULL) + (x2 ^ 0x011990ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x011990: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x011994: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x011998: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x01199c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0119a0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400415ULL; // 0x0119a4: ldr x21, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0119a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x0119ac: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100083FULL; // 0x0119b0: cmp w1, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000123ULL; // 0x0119b4: b.lo #0x119d8
    return acc;
}

// [EN] Reconstructed FDE #0165 @ 0x011ae8..0x011b30 (72 bytes)
// [VN] Phục dựng FDE #0165 tại 0x011ae8..0x011b30 (72 byte)
//   0x011ae8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x011aec: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x011af0: 910043fd  add      x29, sp, #0x10
//   0x011af4: 52800021  mov      w1, #1
//   0x011af8: aa0003f3  mov      x19, x0
//   0x011afc: 97ffffa5  bl       #0x11990
//   0x011b00: aa1303e0  mov      x0, x19
//   0x011b04: 2a1f03e1  mov      w1, wzr
//   0x011b08: 97ffffa2  bl       #0x11990
//   0x011b0c: f9400661  ldr      x1, [x19, #8]
//   0x011b10: 52801502  mov      w2, #0xa8
//   0x011b14: aa1303e0  mov      x0, x19
//   0x011b18: 94000692  bl       #0x13560
//   0x011b1c: f900067f  str      xzr, [x19, #8]
//   0x011b20: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x011b24: aa1303e0  mov      x0, x19
uint64_t fde_0165_sub_011ae8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x94000692ULL) + (x2 ^ 0x011AE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x011ae8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x011aec: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x011af0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x011af4: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x011af8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFA5ULL; // 0x011afc: bl #0x11990
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x011b00: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x011b04: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFA2ULL; // 0x011b08: bl #0x11990
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400661ULL; // 0x011b0c: ldr x1, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #0166 @ 0x011b30..0x011bc0 (144 bytes)
// [VN] Phục dựng FDE #0166 tại 0x011b30..0x011bc0 (144 byte)
//   0x011b30: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x011b34: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x011b38: 910043fd  add      x29, sp, #0x10
//   0x011b3c: f9400408  ldr      x8, [x0, #8]
//   0x011b40: 52800021  mov      w1, #1
//   0x011b44: 52802e02  mov      w2, #0x170
//   0x011b48: aa0003f3  mov      x19, x0
//   0x011b4c: f9400108  ldr      x8, [x8]
//   0x011b50: d63f0100  blr      x8
//   0x011b54: 90000008  adrp     x8, #0x11000
//   0x011b58: 912f0108  add      x8, x8, #0xbc0
//   0x011b5c: f9011a60  str      x0, [x19, #0x230]
//   0x011b60: f9000008  str      x8, [x0]
//   0x011b64: 90000008  adrp     x8, #0x11000
//   0x011b68: 91373108  add      x8, x8, #0xdcc
//   0x011b6c: 6f00e400  movi     v0.2d, #0000000000000000
uint64_t fde_0166_sub_011b30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000008ULL) + (x2 ^ 0x011B30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x011b30: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x011b34: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x011b38: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x011b3c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x011b40: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52802E02ULL; // 0x011b44: mov w2, #0x170
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x011b48: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x011b4c: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x011b50: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x011b54: adrp x8, #0x11000
    return acc;
}

// [EN] Reconstructed FDE #0167 @ 0x011bc0..0x011dcc (524 bytes)
// [VN] Phục dựng FDE #0167 tại 0x011bc0..0x011dcc (524 byte)
//   0x011bc0: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x011bc4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x011bc8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x011bcc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x011bd0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x011bd4: 910103fd  add      x29, sp, #0x40
//   0x011bd8: f9411814  ldr      x20, [x0, #0x230]
//   0x011bdc: aa0003f3  mov      x19, x0
//   0x011be0: 340000e1  cbz      w1, #0x11bfc
//   0x011be4: f9400268  ldr      x8, [x19]
//   0x011be8: 5280062a  mov      w10, #0x31
//   0x011bec: aa1303e0  mov      x0, x19
//   0x011bf0: f9400109  ldr      x9, [x8]
//   0x011bf4: b900290a  str      w10, [x8, #0x28]
//   0x011bf8: d63f0120  blr      x9
//   0x011bfc: b9415a68  ldr      w8, [x19, #0x158]
uint64_t fde_0167_sub_011bc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xF9400109ULL) + (x2 ^ 0x011BC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x011bc0: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x011bc4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x011bc8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x011bcc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x011bd0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x011bd4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411814ULL; // 0x011bd8: ldr x20, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x011bdc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E1ULL; // 0x011be0: cbz w1, #0x11bfc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x011be4: ldr x8, [x19]
    return acc;
}

// [EN] Reconstructed FDE #0168 @ 0x011dcc..0x012340 (1396 bytes)
// [VN] Phục dựng FDE #0168 tại 0x011dcc..0x012340 (1396 byte)
//   0x011dcc: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x011dd0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x011dd4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x011dd8: 910083fd  add      x29, sp, #0x20
//   0x011ddc: f9411814  ldr      x20, [x0, #0x230]
//   0x011de0: aa0003f3  mov      x19, x0
//   0x011de4: b9402288  ldr      w8, [x20, #0x20]
//   0x011de8: f9400e89  ldr      x9, [x20, #0x18]
//   0x011dec: 0b090108  add      w8, w8, w9
//   0x011df0: 51000508  sub      w8, w8, #1
//   0x011df4: 92703d08  and      x8, x8, #0xffff0000
//   0x011df8: eb09011f  cmp      x8, x9
//   0x011dfc: b271010a  orr      x10, x8, #0x8000
//   0x011e00: 9a88b14a  csel     x10, x10, x8, lt
//   0x011e04: 29472289  ldp      w9, w8, [x20, #0x38]
//   0x011e08: 9ac92149  lsl      x9, x10, x9
uint64_t fde_0168_sub_011dcc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB271010AULL) + (x2 ^ 0x011DCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x011dcc: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x011dd0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x011dd4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x011dd8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411814ULL; // 0x011ddc: ldr x20, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x011de0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402288ULL; // 0x011de4: ldr w8, [x20, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400E89ULL; // 0x011de8: ldr x9, [x20, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x0B090108ULL; // 0x011dec: add w8, w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x51000508ULL; // 0x011df0: sub w8, w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0169 @ 0x012340..0x012570 (560 bytes)
// [VN] Phục dựng FDE #0169 tại 0x012340..0x012570 (560 byte)
//   0x012340: d101c3ff  sub      sp, sp, #0x70
//   0x012344: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x012348: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x01234c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x012350: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x012354: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x012358: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x01235c: 910183fd  add      x29, sp, #0x60
//   0x012360: b9413c08  ldr      w8, [x0, #0x13c]
//   0x012364: f9411816  ldr      x22, [x0, #0x230]
//   0x012368: aa0003f3  mov      x19, x0
//   0x01236c: f90007e1  str      x1, [sp, #8]
//   0x012370: 340001a8  cbz      w8, #0x123a4
//   0x012374: b94062c8  ldr      w8, [x22, #0x60]
//   0x012378: 35000128  cbnz     w8, #0x1239c
//   0x01237c: b94066c1  ldr      w1, [x22, #0x64]
uint64_t fde_0169_sub_012340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x340001A8ULL) + (x2 ^ 0x012340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x012340: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x012344: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x012348: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x01234c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x012350: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x012354: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x012358: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x01235c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9413C08ULL; // 0x012360: ldr w8, [x0, #0x13c]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411816ULL; // 0x012364: ldr x22, [x0, #0x230]
    return acc;
}

// [EN] Reconstructed FDE #0170 @ 0x012570..0x01282c (700 bytes)
// [VN] Phục dựng FDE #0170 tại 0x012570..0x01282c (700 byte)
//   0x012570: d10203ff  sub      sp, sp, #0x80
//   0x012574: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x012578: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x01257c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x012580: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x012584: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x012588: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x01258c: 9101c3fd  add      x29, sp, #0x70
//   0x012590: b9413c08  ldr      w8, [x0, #0x13c]
//   0x012594: f9411815  ldr      x21, [x0, #0x230]
//   0x012598: aa0003f3  mov      x19, x0
//   0x01259c: aa0103f4  mov      x20, x1
//   0x0125a0: 340001a8  cbz      w8, #0x125d4
//   0x0125a4: b94062a8  ldr      w8, [x21, #0x60]
//   0x0125a8: 35000128  cbnz     w8, #0x125cc
//   0x0125ac: b94066a1  ldr      w1, [x21, #0x64]
uint64_t fde_0170_sub_012570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x340001A8ULL) + (x2 ^ 0x012570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x012570: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x012574: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x012578: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x01257c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x012580: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x012584: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x012588: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x01258c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xB9413C08ULL; // 0x012590: ldr w8, [x0, #0x13c]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411815ULL; // 0x012594: ldr x21, [x0, #0x230]
    return acc;
}

// [EN] Reconstructed FDE #0171 @ 0x01282c..0x0128e0 (180 bytes)
// [VN] Phục dựng FDE #0171 tại 0x01282c..0x0128e0 (180 byte)
//   0x01282c: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x012830: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x012834: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x012838: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01283c: 9100c3fd  add      x29, sp, #0x30
//   0x012840: b9413c08  ldr      w8, [x0, #0x13c]
//   0x012844: f9411815  ldr      x21, [x0, #0x230]
//   0x012848: aa0003f3  mov      x19, x0
//   0x01284c: aa0103f4  mov      x20, x1
//   0x012850: 340001a8  cbz      w8, #0x12884
//   0x012854: b94062a8  ldr      w8, [x21, #0x60]
//   0x012858: 35000128  cbnz     w8, #0x1287c
//   0x01285c: b94066a1  ldr      w1, [x21, #0x64]
//   0x012860: aa1303e0  mov      x0, x19
//   0x012864: 940001cd  bl       #0x12f98
//   0x012868: b94066a9  ldr      w9, [x21, #0x64]
uint64_t fde_0171_sub_01282c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0xB94066A1ULL) + (x2 ^ 0x01282CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x01282c: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x012830: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x012834: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x012838: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01283c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xB9413C08ULL; // 0x012840: ldr w8, [x0, #0x13c]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411815ULL; // 0x012844: ldr x21, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x012848: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x01284c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x340001A8ULL; // 0x012850: cbz w8, #0x12884
    return acc;
}

// [EN] Reconstructed FDE #0172 @ 0x0128e0..0x012b58 (632 bytes)
// [VN] Phục dựng FDE #0172 tại 0x0128e0..0x012b58 (632 byte)
//   0x0128e0: d101c3ff  sub      sp, sp, #0x70
//   0x0128e4: a9016ffc  stp      x28, x27, [sp, #0x10]
//   0x0128e8: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x0128ec: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x0128f0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0128f4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0128f8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0128fc: 910183fd  add      x29, sp, #0x60
//   0x012900: b9413c08  ldr      w8, [x0, #0x13c]
//   0x012904: f9411815  ldr      x21, [x0, #0x230]
//   0x012908: aa0003f3  mov      x19, x0
//   0x01290c: aa0103f4  mov      x20, x1
//   0x012910: 340001a8  cbz      w8, #0x12944
//   0x012914: b94062a8  ldr      w8, [x21, #0x60]
//   0x012918: 35000128  cbnz     w8, #0x1293c
//   0x01291c: b94066a1  ldr      w1, [x21, #0x64]
uint64_t fde_0172_sub_0128e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x340001A8ULL) + (x2 ^ 0x0128E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0128e0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9016FFCULL; // 0x0128e4: stp x28, x27, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x0128e8: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x0128ec: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0128f0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0128f4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0128f8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0128fc: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9413C08ULL; // 0x012900: ldr w8, [x0, #0x13c]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411815ULL; // 0x012904: ldr x21, [x0, #0x230]
    return acc;
}

// [EN] Reconstructed FDE #0173 @ 0x012b58..0x012f98 (1088 bytes)
// [VN] Phục dựng FDE #0173 tại 0x012b58..0x012f98 (1088 byte)
//   0x012b58: d10243ff  sub      sp, sp, #0x90
//   0x012b5c: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x012b60: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x012b64: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x012b68: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x012b6c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x012b70: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x012b74: 910203fd  add      x29, sp, #0x80
//   0x012b78: b9413c08  ldr      w8, [x0, #0x13c]
//   0x012b7c: f941181c  ldr      x28, [x0, #0x230]
//   0x012b80: aa0003f3  mov      x19, x0
//   0x012b84: f90003e1  str      x1, [sp]
//   0x012b88: 340001a8  cbz      w8, #0x12bbc
//   0x012b8c: b9406388  ldr      w8, [x28, #0x60]
//   0x012b90: 35000128  cbnz     w8, #0x12bb4
//   0x012b94: b9406781  ldr      w1, [x28, #0x64]
uint64_t fde_0173_sub_012b58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x340001A8ULL) + (x2 ^ 0x012B58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x012b58: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x012b5c: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x012b60: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x012b64: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x012b68: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x012b6c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x012b70: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x012b74: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xB9413C08ULL; // 0x012b78: ldr w8, [x0, #0x13c]
    acc = (acc * 0x100000001B3ULL) ^ 0xF941181CULL; // 0x012b7c: ldr x28, [x0, #0x230]
    return acc;
}

// [EN] Reconstructed FDE #0174 @ 0x012f98..0x01312c (404 bytes)
// [VN] Phục dựng FDE #0174 tại 0x012f98..0x01312c (404 byte)
//   0x012f98: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x012f9c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x012fa0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x012fa4: 910083fd  add      x29, sp, #0x20
//   0x012fa8: f9411815  ldr      x21, [x0, #0x230]
//   0x012fac: aa0003f3  mov      x19, x0
//   0x012fb0: 2a0103f4  mov      w20, w1
//   0x012fb4: 97fffb86  bl       #0x11dcc
//   0x012fb8: f9401668  ldr      x8, [x19, #0x28]
//   0x012fbc: 52801fea  mov      w10, #0xff
//   0x012fc0: f9400109  ldr      x9, [x8]
//   0x012fc4: 9100052b  add      x11, x9, #1
//   0x012fc8: f900010b  str      x11, [x8]
//   0x012fcc: 3900012a  strb     w10, [x9]
//   0x012fd0: f9400509  ldr      x9, [x8, #8]
//   0x012fd4: f1000529  subs     x9, x9, #1
uint64_t fde_0174_sub_012f98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF900010BULL) + (x2 ^ 0x012F98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x012f98: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x012f9c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x012fa0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x012fa4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411815ULL; // 0x012fa8: ldr x21, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x012fac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x012fb0: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFB86ULL; // 0x012fb4: bl #0x11dcc
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x012fb8: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x52801FEAULL; // 0x012fbc: mov w10, #0xff
    return acc;
}

// [EN] Reconstructed FDE #0175 @ 0x01312c..0x013558 (1068 bytes)
// [VN] Phục dựng FDE #0175 tại 0x01312c..0x013558 (1068 byte)
//   0x01312c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x013130: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x013134: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x013138: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01313c: 9100c3fd  add      x29, sp, #0x30
//   0x013140: 39400028  ldrb     w8, [x1]
//   0x013144: 90000289  adrp     x9, #0x63000
//   0x013148: f9411814  ldr      x20, [x0, #0x230]
//   0x01314c: f947c129  ldr      x9, [x9, #0xf80]
//   0x013150: 9240190a  and      x10, x8, #0x7f
//   0x013154: aa0003f3  mov      x19, x0
//   0x013158: f940128b  ldr      x11, [x20, #0x20]
//   0x01315c: f86a7929  ldr      x9, [x9, x10, lsl #3]
//   0x013160: 6b481c5f  cmp      w2, w8, lsr #7
//   0x013164: 9350fd2a  asr      x10, x9, #0x10
//   0x013168: cb0a016b  sub      x11, x11, x10
uint64_t fde_0175_sub_01312c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xF86A7929ULL) + (x2 ^ 0x01312CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x01312c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x013130: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x013134: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x013138: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01313c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x013140: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000289ULL; // 0x013144: adrp x9, #0x63000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411814ULL; // 0x013148: ldr x20, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0xF947C129ULL; // 0x01314c: ldr x9, [x9, #0xf80]
    acc = (acc * 0x100000001B3ULL) ^ 0x9240190AULL; // 0x013150: and x10, x8, #0x7f
    return acc;
}

// [EN] Reconstructed FDE #0176 @ 0x013558..0x013560 (8 bytes)
// [VN] Phục dựng FDE #0176 tại 0x013558..0x013560 (8 byte)
//   0x013558: aa0103e0  mov      x0, x1
//   0x01355c: 17ffc275  b        #0x3f30
uint64_t fde_0176_sub_013558(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E0ULL) + (x1 ^ 0x17FFC275ULL) + (x2 ^ 0x013558ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x013558: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC275ULL; // 0x01355c: b #0x3f30
    return acc;
}

// [EN] Reconstructed FDE #0177 @ 0x013560..0x013568 (8 bytes)
// [VN] Phục dựng FDE #0177 tại 0x013560..0x013568 (8 byte)
//   0x013560: aa0103e0  mov      x0, x1
//   0x013564: 17ffc267  b        #0x3f00
uint64_t fde_0177_sub_013560(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E0ULL) + (x1 ^ 0x17FFC267ULL) + (x2 ^ 0x013560ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x013560: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC267ULL; // 0x013564: b #0x3f00
    return acc;
}

// [EN] Reconstructed FDE #0178 @ 0x013568..0x013570 (8 bytes)
// [VN] Phục dựng FDE #0178 tại 0x013568..0x013570 (8 byte)
//   0x013568: aa0103e0  mov      x0, x1
//   0x01356c: 17ffc271  b        #0x3f30
uint64_t fde_0178_sub_013568(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E0ULL) + (x1 ^ 0x17FFC271ULL) + (x2 ^ 0x013568ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x013568: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC271ULL; // 0x01356c: b #0x3f30
    return acc;
}

// [EN] Reconstructed FDE #0179 @ 0x013570..0x013578 (8 bytes)
// [VN] Phục dựng FDE #0179 tại 0x013570..0x013578 (8 byte)
//   0x013570: aa0103e0  mov      x0, x1
//   0x013574: 17ffc263  b        #0x3f00
uint64_t fde_0179_sub_013570(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103E0ULL) + (x1 ^ 0x17FFC263ULL) + (x2 ^ 0x013570ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x013570: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFC263ULL; // 0x013574: b #0x3f00
    return acc;
}

// [EN] Reconstructed FDE #0180 @ 0x013578..0x013598 (32 bytes)
// [VN] Phục dựng FDE #0180 tại 0x013578..0x013598 (32 byte)
//   0x013578: f9400408  ldr      x8, [x0, #8]
//   0x01357c: f9402d08  ldr      x8, [x8, #0x58]
//   0x013580: b4000088  cbz      x8, #0x13590
//   0x013584: eb030108  subs     x8, x8, x3
//   0x013588: 9a8833e0  csel     x0, xzr, x8, lo
//   0x01358c: d65f03c0  ret      
//   0x013590: aa0203e0  mov      x0, x2
//   0x013594: d65f03c0  ret      
uint64_t fde_0180_sub_013578(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013578ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x013578: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9402D08ULL; // 0x01357c: ldr x8, [x8, #0x58]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x013580: cbz x8, #0x13590
    acc = (acc * 0x100000001B3ULL) ^ 0xEB030108ULL; // 0x013584: subs x8, x8, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8833E0ULL; // 0x013588: csel x0, xzr, x8, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01358c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E0ULL; // 0x013590: mov x0, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013594: ret 
    return acc;
}

// [EN] Reconstructed FDE #0181 @ 0x013598..0x0135ac (20 bytes)
// [VN] Phục dựng FDE #0181 tại 0x013598..0x0135ac (20 byte)
//   0x013598: f9400008  ldr      x8, [x0]
//   0x01359c: 52800669  mov      w9, #0x33
//   0x0135a0: f9400101  ldr      x1, [x8]
//   0x0135a4: b9002909  str      w9, [x8, #0x28]
//   0x0135a8: d61f0020  br       x1
uint64_t fde_0181_sub_013598(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0020ULL) + (x2 ^ 0x013598ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x013598: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800669ULL; // 0x01359c: mov w9, #0x33
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400101ULL; // 0x0135a0: ldr x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9002909ULL; // 0x0135a4: str w9, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x0135a8: br x1
    return acc;
}

// [EN] Reconstructed FDE #0182 @ 0x0135ac..0x0135b4 (8 bytes)
// [VN] Phục dựng FDE #0182 tại 0x0135ac..0x0135b4 (8 byte)
//   0x0135ac: aa1f03e0  mov      x0, xzr
//   0x0135b0: d65f03c0  ret      
uint64_t fde_0182_sub_0135ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x0135ac: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135b0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0183 @ 0x0135b4..0x0135b8 (4 bytes)
// [VN] Phục dựng FDE #0183 tại 0x0135b4..0x0135b8 (4 byte)
//   0x0135b4: d65f03c0  ret      
uint64_t fde_0183_sub_0135b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135b4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0184 @ 0x0135b8..0x0135c0 (8 bytes)
// [VN] Phục dựng FDE #0184 tại 0x0135b8..0x0135c0 (8 byte)
//   0x0135b8: 2a1f03e0  mov      w0, wzr
//   0x0135bc: d65f03c0  ret      
uint64_t fde_0184_sub_0135b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0135b8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135bc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0185 @ 0x0135c0..0x0135c8 (8 bytes)
// [VN] Phục dựng FDE #0185 tại 0x0135c0..0x0135c8 (8 byte)
//   0x0135c0: 2a1f03e0  mov      w0, wzr
//   0x0135c4: d65f03c0  ret      
uint64_t fde_0185_sub_0135c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0135c0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135c4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0186 @ 0x0135c8..0x0135cc (4 bytes)
// [VN] Phục dựng FDE #0186 tại 0x0135c8..0x0135cc (4 byte)
//   0x0135c8: d65f03c0  ret      
uint64_t fde_0186_sub_0135c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0187 @ 0x0135cc..0x0135d0 (4 bytes)
// [VN] Phục dựng FDE #0187 tại 0x0135cc..0x0135d0 (4 byte)
//   0x0135cc: d65f03c0  ret      
uint64_t fde_0187_sub_0135cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135cc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0188 @ 0x0135d0..0x0135d8 (8 bytes)
// [VN] Phục dựng FDE #0188 tại 0x0135d0..0x0135d8 (8 byte)
//   0x0135d0: 2a1f03e0  mov      w0, wzr
//   0x0135d4: d65f03c0  ret      
uint64_t fde_0188_sub_0135d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0135d0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135d4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0189 @ 0x0135d8..0x0135e0 (8 bytes)
// [VN] Phục dựng FDE #0189 tại 0x0135d8..0x0135e0 (8 byte)
//   0x0135d8: 2a1f03e0  mov      w0, wzr
//   0x0135dc: d65f03c0  ret      
uint64_t fde_0189_sub_0135d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0135d8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0190 @ 0x0135e0..0x0135e4 (4 bytes)
// [VN] Phục dựng FDE #0190 tại 0x0135e0..0x0135e4 (4 byte)
//   0x0135e0: d65f03c0  ret      
uint64_t fde_0190_sub_0135e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135e0: ret 
    return acc;
}

// [EN] Reconstructed FDE #0191 @ 0x0135e4..0x0135e8 (4 bytes)
// [VN] Phục dựng FDE #0191 tại 0x0135e4..0x0135e8 (4 byte)
//   0x0135e4: d65f03c0  ret      
uint64_t fde_0191_sub_0135e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135e4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0192 @ 0x0135e8..0x0135f0 (8 bytes)
// [VN] Phục dựng FDE #0192 tại 0x0135e8..0x0135f0 (8 byte)
//   0x0135e8: 2a1f03e0  mov      w0, wzr
//   0x0135ec: d65f03c0  ret      
uint64_t fde_0192_sub_0135e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0135e8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #0193 @ 0x0135f0..0x0135f8 (8 bytes)
// [VN] Phục dựng FDE #0193 tại 0x0135f0..0x0135f8 (8 byte)
//   0x0135f0: 2a1f03e0  mov      w0, wzr
//   0x0135f4: d65f03c0  ret      
uint64_t fde_0193_sub_0135f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0135f0: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #0194 @ 0x0135f8..0x0135fc (4 bytes)
// [VN] Phục dựng FDE #0194 tại 0x0135f8..0x0135fc (4 byte)
//   0x0135f8: d65f03c0  ret      
uint64_t fde_0194_sub_0135f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135f8: ret 
    return acc;
}

// [EN] Reconstructed FDE #0195 @ 0x0135fc..0x013600 (4 bytes)
// [VN] Phục dựng FDE #0195 tại 0x0135fc..0x013600 (4 byte)
//   0x0135fc: d65f03c0  ret      
uint64_t fde_0195_sub_0135fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0135FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0135fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #0196 @ 0x013600..0x013608 (8 bytes)
// [VN] Phục dựng FDE #0196 tại 0x013600..0x013608 (8 byte)
//   0x013600: 2a1f03e0  mov      w0, wzr
//   0x013604: d65f03c0  ret      
uint64_t fde_0196_sub_013600(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013600ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x013600: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013604: ret 
    return acc;
}

// [EN] Reconstructed FDE #0197 @ 0x013608..0x013610 (8 bytes)
// [VN] Phục dựng FDE #0197 tại 0x013608..0x013610 (8 byte)
//   0x013608: 2a1f03e0  mov      w0, wzr
//   0x01360c: d65f03c0  ret      
uint64_t fde_0197_sub_013608(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013608ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x013608: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01360c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0198 @ 0x013610..0x013618 (8 bytes)
// [VN] Phục dựng FDE #0198 tại 0x013610..0x013618 (8 byte)
//   0x013610: 2a1f03e0  mov      w0, wzr
//   0x013614: d65f03c0  ret      
uint64_t fde_0198_sub_013610(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013610ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x013610: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013614: ret 
    return acc;
}

// [EN] Reconstructed FDE #0199 @ 0x013618..0x01361c (4 bytes)
// [VN] Phục dựng FDE #0199 tại 0x013618..0x01361c (4 byte)
//   0x013618: d65f03c0  ret      
uint64_t fde_0199_sub_013618(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013618ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013618: ret 
    return acc;
}

// [EN] Reconstructed FDE #0200 @ 0x01361c..0x013620 (4 bytes)
// [VN] Phục dựng FDE #0200 tại 0x01361c..0x013620 (4 byte)
//   0x01361c: d65f03c0  ret      
uint64_t fde_0200_sub_01361c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01361CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x01361c: ret 
    return acc;
}

// [EN] Reconstructed FDE #0201 @ 0x013620..0x013624 (4 bytes)
// [VN] Phục dựng FDE #0201 tại 0x013620..0x013624 (4 byte)
//   0x013620: d65f03c0  ret      
uint64_t fde_0201_sub_013620(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013620ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013620: ret 
    return acc;
}

// [EN] Reconstructed FDE #0202 @ 0x013624..0x01362c (8 bytes)
// [VN] Phục dựng FDE #0202 tại 0x013624..0x01362c (8 byte)
//   0x013624: 2a1f03e0  mov      w0, wzr
//   0x013628: d65f03c0  ret      
uint64_t fde_0202_sub_013624(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013624ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x013624: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013628: ret 
    return acc;
}

// [EN] Reconstructed FDE #0203 @ 0x01362c..0x013634 (8 bytes)
// [VN] Phục dựng FDE #0203 tại 0x01362c..0x013634 (8 byte)
//   0x01362c: 2a1f03e0  mov      w0, wzr
//   0x013630: d65f03c0  ret      
uint64_t fde_0203_sub_01362c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01362CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x01362c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013630: ret 
    return acc;
}

// [EN] Reconstructed FDE #0204 @ 0x013634..0x013638 (4 bytes)
// [VN] Phục dựng FDE #0204 tại 0x013634..0x013638 (4 byte)
//   0x013634: d65f03c0  ret      
uint64_t fde_0204_sub_013634(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013634ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013634: ret 
    return acc;
}

// [EN] Reconstructed FDE #0205 @ 0x013638..0x01363c (4 bytes)
// [VN] Phục dựng FDE #0205 tại 0x013638..0x01363c (4 byte)
//   0x013638: d65f03c0  ret      
uint64_t fde_0205_sub_013638(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013638ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013638: ret 
    return acc;
}

// [EN] Reconstructed FDE #0206 @ 0x01363c..0x013644 (8 bytes)
// [VN] Phục dựng FDE #0206 tại 0x01363c..0x013644 (8 byte)
//   0x01363c: 2a1f03e0  mov      w0, wzr
//   0x013640: d65f03c0  ret      
uint64_t fde_0206_sub_01363c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x01363CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x01363c: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013640: ret 
    return acc;
}

// [EN] Reconstructed FDE #0207 @ 0x013644..0x01364c (8 bytes)
// [VN] Phục dựng FDE #0207 tại 0x013644..0x01364c (8 byte)
//   0x013644: aa1f03e0  mov      x0, xzr
//   0x013648: d65f03c0  ret      
uint64_t fde_0207_sub_013644(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x013644ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x013644: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x013648: ret 
    return acc;
}

// [EN] Reconstructed FDE #0208 @ 0x01364c..0x01378c (320 bytes)
// [VN] Phục dựng FDE #0208 tại 0x01364c..0x01378c (320 byte)
//   0x01364c: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x013650: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x013654: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x013658: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x01365c: 9100c3fd  add      x29, sp, #0x30
//   0x013660: f9400408  ldr      x8, [x0, #8]
//   0x013664: 2a0103f5  mov      w21, w1
//   0x013668: 52800021  mov      w1, #1
//   0x01366c: 52801802  mov      w2, #0xc0
//   0x013670: f9400108  ldr      x8, [x8]
//   0x013674: aa0003f3  mov      x19, x0
//   0x013678: d63f0100  blr      x8
//   0x01367c: 90000008  adrp     x8, #0x13000
//   0x013680: aa0003f4  mov      x20, x0
//   0x013684: 911e3108  add      x8, x8, #0x78c
//   0x013688: f9010660  str      x0, [x19, #0x208]
uint64_t fde_0208_sub_01364c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0x90000008ULL) + (x2 ^ 0x01364CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x01364c: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x013650: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x013654: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x013658: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x01365c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x013660: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x013664: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x013668: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52801802ULL; // 0x01366c: mov w2, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x013670: ldr x8, [x8]
    return acc;
}

// [EN] Reconstructed FDE #0209 @ 0x01378c..0x01388c (256 bytes)
// [VN] Phục dựng FDE #0209 tại 0x01378c..0x01388c (256 byte)
//   0x01378c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x013790: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x013794: 910043fd  add      x29, sp, #0x10
//   0x013798: f9410413  ldr      x19, [x0, #0x208]
//   0x01379c: b900127f  str      wzr, [x19, #0x10]
//   0x0137a0: b9417008  ldr      w8, [x0, #0x170]
//   0x0137a4: 7100051f  cmp      w8, #1
//   0x0137a8: 5400006d  b.le     #0x137b4
//   0x0137ac: 52800028  mov      w8, #1
//   0x0137b0: 14000008  b        #0x137d0
//   0x0137b4: b9416c08  ldr      w8, [x0, #0x16c]
//   0x0137b8: f940bc09  ldr      x9, [x0, #0x178]
//   0x0137bc: 5280018a  mov      w10, #0xc
//   0x0137c0: 7100051f  cmp      w8, #1
//   0x0137c4: 52800988  mov      w8, #0x4c
//   0x0137c8: 9a8a0108  csel     x8, x8, x10, eq
uint64_t fde_0209_sub_01378c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x5280018AULL) + (x2 ^ 0x01378CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x01378c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x013790: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x013794: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410413ULL; // 0x013798: ldr x19, [x0, #0x208]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900127FULL; // 0x01379c: str wzr, [x19, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9417008ULL; // 0x0137a0: ldr w8, [x0, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x0137a4: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006DULL; // 0x0137a8: b.le #0x137b4
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x0137ac: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000008ULL; // 0x0137b0: b #0x137d0
    return acc;
}

// [EN] Reconstructed FDE #0210 @ 0x01388c..0x013b6c (736 bytes)
// [VN] Phục dựng FDE #0210 tại 0x01388c..0x013b6c (736 byte)
//   0x01388c: d10243ff  sub      sp, sp, #0x90
//   0x013890: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x013894: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x013898: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x01389c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0138a0: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0138a4: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0138a8: 910203fd  add      x29, sp, #0x80
//   0x0138ac: f941041a  ldr      x26, [x0, #0x208]
//   0x0138b0: aa0003f3  mov      x19, x0
//   0x0138b4: 29432349  ldp      w9, w8, [x26, #0x18]
//   0x0138b8: b9002fe9  str      w9, [sp, #0x2c]
//   0x0138bc: 6b08013f  cmp      w9, w8
//   0x0138c0: aa1a03e9  mov      x9, x26
//   0x0138c4: 540011ca  b.ge     #0x13afc
//   0x0138c8: b9419a69  ldr      w9, [x19, #0x198]
uint64_t fde_0210_sub_01388c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x6B08013FULL) + (x2 ^ 0x01388CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x01388c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x013890: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x013894: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x013898: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x01389c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x0138a0: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0138a4: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0138a8: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF941041AULL; // 0x0138ac: ldr x26, [x0, #0x208]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0138b0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0211 @ 0x013b6c..0x013e7c (784 bytes)
// [VN] Phục dựng FDE #0211 tại 0x013b6c..0x013e7c (784 byte)
//   0x013b6c: d102c3ff  sub      sp, sp, #0xb0
//   0x013b70: a9056ffc  stp      x28, x27, [sp, #0x50]
//   0x013b74: a90667fa  stp      x26, x25, [sp, #0x60]
//   0x013b78: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x013b7c: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x013b80: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x013b84: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x013b88: 910283fd  add      x29, sp, #0xa0
//   0x013b8c: b9405c08  ldr      w8, [x0, #0x5c]
//   0x013b90: aa0003f3  mov      x19, x0
//   0x013b94: f9001be1  str      x1, [sp, #0x30]
//   0x013b98: 7100051f  cmp      w8, #1
//   0x013b9c: 540015cb  b.lt     #0x13e54
//   0x013ba0: f9410668  ldr      x8, [x19, #0x208]
//   0x013ba4: f9403678  ldr      x24, [x19, #0x68]
//   0x013ba8: aa1f03f4  mov      x20, xzr
uint64_t fde_0211_sub_013b6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x540015CBULL) + (x2 ^ 0x013B6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x013b6c: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9056FFCULL; // 0x013b70: stp x28, x27, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90667FAULL; // 0x013b74: stp x26, x25, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x013b78: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x013b7c: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x013b80: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x013b84: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x013b88: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405C08ULL; // 0x013b8c: ldr w8, [x0, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x013b90: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0212 @ 0x013e7c..0x014120 (676 bytes)
// [VN] Phục dựng FDE #0212 tại 0x013e7c..0x014120 (676 byte)
//   0x013e7c: d10203ff  sub      sp, sp, #0x80
//   0x013e80: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x013e84: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x013e88: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x013e8c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x013e90: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x013e94: 9101c3fd  add      x29, sp, #0x70
//   0x013e98: d53bd055  mrs      x21, tpidr_el0
//   0x013e9c: f94016a8  ldr      x8, [x21, #0x28]
//   0x013ea0: aa0003f3  mov      x19, x0
//   0x013ea4: f90017e8  str      x8, [sp, #0x28]
//   0x013ea8: b9417009  ldr      w9, [x0, #0x170]
//   0x013eac: f9410416  ldr      x22, [x0, #0x208]
//   0x013eb0: 7100053f  cmp      w9, #1
//   0x013eb4: 540002cb  b.lt     #0x13f0c
//   0x013eb8: aa1f03f4  mov      x20, xzr
uint64_t fde_0212_sub_013e7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9410416ULL) + (x2 ^ 0x013E7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x013e7c: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x013e80: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x013e84: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x013e88: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x013e8c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x013e90: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x013e94: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x013e98: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x013e9c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x013ea0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0213 @ 0x014120..0x014468 (840 bytes)
// [VN] Phục dựng FDE #0213 tại 0x014120..0x014468 (840 byte)
//   0x014120: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x014124: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x014128: 910043fd  add      x29, sp, #0x10
//   0x01412c: f9400408  ldr      x8, [x0, #8]
//   0x014130: 52800021  mov      w1, #1
//   0x014134: 52800302  mov      w2, #0x18
//   0x014138: aa0003f4  mov      x20, x0
//   0x01413c: f9400108  ldr      x8, [x8]
//   0x014140: d63f0100  blr      x8
//   0x014144: 90000008  adrp     x8, #0x14000
//   0x014148: 9111a108  add      x8, x8, #0x468
//   0x01414c: f9010e80  str      x0, [x20, #0x218]
//   0x014150: f9000008  str      x8, [x0]
//   0x014154: b9403e88  ldr      w8, [x20, #0x3c]
//   0x014158: aa0003f3  mov      x19, x0
//   0x01415c: 51000509  sub      w9, w8, #1
uint64_t fde_0213_sub_014120(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000008ULL) + (x2 ^ 0x014120ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x014120: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x014124: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x014128: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x01412c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x014130: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52800302ULL; // 0x014134: mov w2, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x014138: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x01413c: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x014140: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x014144: adrp x8, #0x14000
    return acc;
}

// [EN] Reconstructed FDE #0214 @ 0x014468..0x01446c (4 bytes)
// [VN] Phục dựng FDE #0214 tại 0x014468..0x01446c (4 byte)
//   0x014468: d65f03c0  ret      
uint64_t fde_0214_sub_014468(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x014468ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x014468: ret 
    return acc;
}

// [EN] Reconstructed FDE #0215 @ 0x01446c..0x0144cc (96 bytes)
// [VN] Phục dựng FDE #0215 tại 0x01446c..0x0144cc (96 byte)
//   0x01446c: 7100049f  cmp      w4, #1
//   0x014470: 540002cb  b.lt     #0x144c8
//   0x014474: b9403008  ldr      w8, [x0, #0x30]
//   0x014478: b9803809  ldrsw    x9, [x0, #0x38]
//   0x01447c: 14000005  b        #0x14490
//   0x014480: 7100049f  cmp      w4, #1
//   0x014484: aa0a03e1  mov      x1, x10
//   0x014488: 2a0b03e3  mov      w3, w11
//   0x01448c: 540001eb  b.lt     #0x144c8
//   0x014490: 51000484  sub      w4, w4, #1
//   0x014494: 9100202a  add      x10, x1, #8
//   0x014498: 1100046b  add      w11, w3, #1
//   0x01449c: 34ffff28  cbz      w8, #0x14480
//   0x0144a0: f940004c  ldr      x12, [x2]
//   0x0144a4: f940002d  ldr      x13, [x1]
//   0x0144a8: aa0803ee  mov      x14, x8
uint64_t fde_0215_sub_01446c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x7100049FULL) + (x1 ^ 0x34FFFF28ULL) + (x2 ^ 0x01446CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x01446c: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x540002CBULL; // 0x014470: b.lt #0x144c8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403008ULL; // 0x014474: ldr w8, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9803809ULL; // 0x014478: ldrsw x9, [x0, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000005ULL; // 0x01447c: b #0x14490
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x014480: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0A03E1ULL; // 0x014484: mov x1, x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0B03E3ULL; // 0x014488: mov w3, w11
    acc = (acc * 0x100000001B3ULL) ^ 0x540001EBULL; // 0x01448c: b.lt #0x144c8
    acc = (acc * 0x100000001B3ULL) ^ 0x51000484ULL; // 0x014490: sub w4, w4, #1
    return acc;
}

// [EN] Reconstructed FDE #0216 @ 0x0144cc..0x0145fc (304 bytes)
// [VN] Phục dựng FDE #0216 tại 0x0144cc..0x0145fc (304 byte)
//   0x0144cc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0144d0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0144d4: 910043fd  add      x29, sp, #0x10
//   0x0144d8: f9400408  ldr      x8, [x0, #8]
//   0x0144dc: f9410c13  ldr      x19, [x0, #0x218]
//   0x0144e0: 52800021  mov      w1, #1
//   0x0144e4: 52880002  mov      w2, #0x4000
//   0x0144e8: f9400108  ldr      x8, [x8]
//   0x0144ec: d63f0100  blr      x8
//   0x0144f0: 900001ee  adrp     x14, #0x50000
//   0x0144f4: 3dc211c0  ldr      q0, [x14, #0x840]
//   0x0144f8: 5290000f  mov      w15, #0x8000
//   0x0144fc: 528fffee  mov      w14, #0x7fff
//   0x014500: 72a0100e  movk     w14, #0x80, lsl #16
//   0x014504: 4e080de1  dup      v1.2d, x15
//   0x014508: 5280004f  mov      w15, #2
uint64_t fde_0216_sub_0144cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x528FFFEEULL) + (x2 ^ 0x0144CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0144cc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0144d0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0144d4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0144d8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410C13ULL; // 0x0144dc: ldr x19, [x0, #0x218]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0144e0: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52880002ULL; // 0x0144e4: mov w2, #0x4000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0144e8: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0144ec: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x900001EEULL; // 0x0144f0: adrp x14, #0x50000
    return acc;
}

// [EN] Reconstructed FDE #0217 @ 0x0145fc..0x014a24 (1064 bytes)
// [VN] Phục dựng FDE #0217 tại 0x0145fc..0x014a24 (1064 byte)
//   0x0145fc: b9403c08  ldr      w8, [x0, #0x3c]
//   0x014600: 51001908  sub      w8, w8, #6
//   0x014604: 7100251f  cmp      w8, #9
//   0x014608: 54001328  b.hi     #0x1486c
//   0x01460c: d00001e9  adrp     x9, #0x52000
//   0x014610: 91069129  add      x9, x9, #0x1a4
//   0x014614: 1000008a  adr      x10, #0x14624
//   0x014618: 3868692b  ldrb     w11, [x9, x8]
//   0x01461c: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x014620: d61f0140  br       x10
//   0x014624: 7100049f  cmp      w4, #1
//   0x014628: 54001fcb  b.lt     #0x14a20
//   0x01462c: f9410c08  ldr      x8, [x0, #0x218]
//   0x014630: b9403009  ldr      w9, [x0, #0x30]
//   0x014634: f9400908  ldr      x8, [x8, #0x10]
//   0x014638: 14000005  b        #0x1464c
uint64_t fde_0217_sub_0145fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9403C08ULL) + (x1 ^ 0xF9410C08ULL) + (x2 ^ 0x0145FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403C08ULL; // 0x0145fc: ldr w8, [x0, #0x3c]
    acc = (acc * 0x100000001B3ULL) ^ 0x51001908ULL; // 0x014600: sub w8, w8, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x7100251FULL; // 0x014604: cmp w8, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x54001328ULL; // 0x014608: b.hi #0x1486c
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001E9ULL; // 0x01460c: adrp x9, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x91069129ULL; // 0x014610: add x9, x9, #0x1a4
    acc = (acc * 0x100000001B3ULL) ^ 0x1000008AULL; // 0x014614: adr x10, #0x14624
    acc = (acc * 0x100000001B3ULL) ^ 0x3868692BULL; // 0x014618: ldrb w11, [x9, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0B094AULL; // 0x01461c: add x10, x10, x11, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0140ULL; // 0x014620: br x10
    return acc;
}

// [EN] Reconstructed FDE #0218 @ 0x014a24..0x014cf0 (716 bytes)
// [VN] Phục dựng FDE #0218 tại 0x014a24..0x014cf0 (716 byte)
//   0x014a24: f81c0ff9  str      x25, [sp, #-0x40]!
//   0x014a28: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x014a2c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x014a30: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x014a34: b9405c09  ldr      w9, [x0, #0x5c]
//   0x014a38: b9403008  ldr      w8, [x0, #0x30]
//   0x014a3c: 71000d3f  cmp      w9, #3
//   0x014a40: 54000480  b.eq     #0x14ad0
//   0x014a44: 7100113f  cmp      w9, #4
//   0x014a48: 54001121  b.ne     #0x14c6c
//   0x014a4c: 7100049f  cmp      w4, #1
//   0x014a50: 540000ca  b.ge     #0x14a68
//   0x014a54: 140000a2  b        #0x14cdc
//   0x014a58: 7100049f  cmp      w4, #1
//   0x014a5c: aa0903e1  mov      x1, x9
//   0x014a60: 2a0a03e3  mov      w3, w10
uint64_t fde_0218_sub_014a24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF9ULL) + (x1 ^ 0x140000A2ULL) + (x2 ^ 0x014A24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF9ULL; // 0x014a24: str x25, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x014a28: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x014a2c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x014a30: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405C09ULL; // 0x014a34: ldr w9, [x0, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403008ULL; // 0x014a38: ldr w8, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x71000D3FULL; // 0x014a3c: cmp w9, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x54000480ULL; // 0x014a40: b.eq #0x14ad0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100113FULL; // 0x014a44: cmp w9, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x54001121ULL; // 0x014a48: b.ne #0x14c6c
    return acc;
}

// [EN] Reconstructed FDE #0219 @ 0x014cf0..0x0158e0 (3056 bytes)
// [VN] Phục dựng FDE #0219 tại 0x014cf0..0x0158e0 (3056 byte)
//   0x014cf0: f81b0ffb  str      x27, [sp, #-0x50]!
//   0x014cf4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x014cf8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x014cfc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x014d00: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x014d04: b9403c08  ldr      w8, [x0, #0x3c]
//   0x014d08: 51001908  sub      w8, w8, #6
//   0x014d0c: 7100251f  cmp      w8, #9
//   0x014d10: 540036a8  b.hi     #0x153e4
//   0x014d14: d00001e9  adrp     x9, #0x52000
//   0x014d18: 9106b929  add      x9, x9, #0x1ae
//   0x014d1c: 1000008a  adr      x10, #0x14d2c
//   0x014d20: 7868792b  ldrh     w11, [x9, x8, lsl #1]
//   0x014d24: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x014d28: d61f0140  br       x10
//   0x014d2c: 7100049f  cmp      w4, #1
uint64_t fde_0219_sub_014cf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FFBULL) + (x1 ^ 0x7868792BULL) + (x2 ^ 0x014CF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FFBULL; // 0x014cf0: str x27, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x014cf4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x014cf8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x014cfc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x014d00: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403C08ULL; // 0x014d04: ldr w8, [x0, #0x3c]
    acc = (acc * 0x100000001B3ULL) ^ 0x51001908ULL; // 0x014d08: sub w8, w8, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x7100251FULL; // 0x014d0c: cmp w8, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x540036A8ULL; // 0x014d10: b.hi #0x153e4
    acc = (acc * 0x100000001B3ULL) ^ 0xD00001E9ULL; // 0x014d14: adrp x9, #0x52000
    return acc;
}

// [EN] Reconstructed FDE #0220 @ 0x0158e0..0x016090 (1968 bytes)
// [VN] Phục dựng FDE #0220 tại 0x0158e0..0x016090 (1968 byte)
//   0x0158e0: a9bf4ff4  stp      x20, x19, [sp, #-0x10]!
//   0x0158e4: b9403c08  ldr      w8, [x0, #0x3c]
//   0x0158e8: 51001908  sub      w8, w8, #6
//   0x0158ec: 7100251f  cmp      w8, #9
//   0x0158f0: 54002328  b.hi     #0x15d54
//   0x0158f4: b00001e9  adrp     x9, #0x52000
//   0x0158f8: 91070929  add      x9, x9, #0x1c2
//   0x0158fc: 1000008a  adr      x10, #0x1590c
//   0x015900: 7868792b  ldrh     w11, [x9, x8, lsl #1]
//   0x015904: 8b0b094a  add      x10, x10, x11, lsl #2
//   0x015908: d61f0140  br       x10
//   0x01590c: 7100049f  cmp      w4, #1
//   0x015910: 54003bcb  b.lt     #0x16088
//   0x015914: f9410c08  ldr      x8, [x0, #0x218]
//   0x015918: b9403009  ldr      w9, [x0, #0x30]
//   0x01591c: f9400908  ldr      x8, [x8, #0x10]
uint64_t fde_0220_sub_0158e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF4FF4ULL) + (x1 ^ 0x54003BCBULL) + (x2 ^ 0x0158E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF4FF4ULL; // 0x0158e0: stp x20, x19, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403C08ULL; // 0x0158e4: ldr w8, [x0, #0x3c]
    acc = (acc * 0x100000001B3ULL) ^ 0x51001908ULL; // 0x0158e8: sub w8, w8, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x7100251FULL; // 0x0158ec: cmp w8, #9
    acc = (acc * 0x100000001B3ULL) ^ 0x54002328ULL; // 0x0158f0: b.hi #0x15d54
    acc = (acc * 0x100000001B3ULL) ^ 0xB00001E9ULL; // 0x0158f4: adrp x9, #0x52000
    acc = (acc * 0x100000001B3ULL) ^ 0x91070929ULL; // 0x0158f8: add x9, x9, #0x1c2
    acc = (acc * 0x100000001B3ULL) ^ 0x1000008AULL; // 0x0158fc: adr x10, #0x1590c
    acc = (acc * 0x100000001B3ULL) ^ 0x7868792BULL; // 0x015900: ldrh w11, [x9, x8, lsl #1]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B0B094AULL; // 0x015904: add x10, x10, x11, lsl #2
    return acc;
}

// [EN] Reconstructed FDE #0221 @ 0x016090..0x0161b0 (288 bytes)
// [VN] Phục dựng FDE #0221 tại 0x016090..0x0161b0 (288 byte)
//   0x016090: f81f0ff3  str      x19, [sp, #-0x10]!
//   0x016094: 7100049f  cmp      w4, #1
//   0x016098: 5400088b  b.lt     #0x161a8
//   0x01609c: f9410c08  ldr      x8, [x0, #0x218]
//   0x0160a0: b9403009  ldr      w9, [x0, #0x30]
//   0x0160a4: 5280a00a  mov      w10, #0x500
//   0x0160a8: f9400908  ldr      x8, [x8, #0x10]
//   0x0160ac: 14000005  b        #0x160c0
//   0x0160b0: 7100049f  cmp      w4, #1
//   0x0160b4: aa0b03e1  mov      x1, x11
//   0x0160b8: 2a0c03e3  mov      w3, w12
//   0x0160bc: 5400076b  b.lt     #0x161a8
//   0x0160c0: 51000484  sub      w4, w4, #1
//   0x0160c4: 9100202b  add      x11, x1, #8
//   0x0160c8: 1100046c  add      w12, w3, #1
//   0x0160cc: 34ffff29  cbz      w9, #0x160b0
uint64_t fde_0221_sub_016090(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81F0FF3ULL) + (x1 ^ 0x51000484ULL) + (x2 ^ 0x016090ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81F0FF3ULL; // 0x016090: str x19, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x016094: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400088BULL; // 0x016098: b.lt #0x161a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9410C08ULL; // 0x01609c: ldr x8, [x0, #0x218]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9403009ULL; // 0x0160a0: ldr w9, [x0, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x5280A00AULL; // 0x0160a4: mov w10, #0x500
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400908ULL; // 0x0160a8: ldr x8, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000005ULL; // 0x0160ac: b #0x160c0
    acc = (acc * 0x100000001B3ULL) ^ 0x7100049FULL; // 0x0160b0: cmp w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0B03E1ULL; // 0x0160b4: mov x1, x11
    return acc;
}

// [EN] Reconstructed FDE #0222 @ 0x0161b0..0x0163bc (524 bytes)
// [VN] Phục dựng FDE #0222 tại 0x0161b0..0x0163bc (524 byte)
//   0x0161b0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0161b4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0161b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0161bc: 910083fd  add      x29, sp, #0x20
//   0x0161c0: f9400408  ldr      x8, [x0, #8]
//   0x0161c4: 52800021  mov      w1, #1
//   0x0161c8: 52801202  mov      w2, #0x90
//   0x0161cc: aa0003f3  mov      x19, x0
//   0x0161d0: f9400108  ldr      x8, [x8]
//   0x0161d4: d63f0100  blr      x8
//   0x0161d8: 90000008  adrp     x8, #0x16000
//   0x0161dc: 910ef108  add      x8, x8, #0x3bc
//   0x0161e0: f9011660  str      x0, [x19, #0x228]
//   0x0161e4: f9000008  str      x8, [x0]
//   0x0161e8: b9413a68  ldr      w8, [x19, #0x138]
//   0x0161ec: aa0003f4  mov      x20, x0
uint64_t fde_0222_sub_0161b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9011660ULL) + (x2 ^ 0x0161B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0161b0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0161b4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0161b8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0161bc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0161c0: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0161c4: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52801202ULL; // 0x0161c8: mov w2, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0161cc: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0161d0: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0161d4: blr x8
    return acc;
}

// [EN] Reconstructed FDE #0223 @ 0x0163bc..0x0168a0 (1252 bytes)
// [VN] Phục dựng FDE #0223 tại 0x0163bc..0x0168a0 (1252 byte)
//   0x0163bc: d10343ff  sub      sp, sp, #0xd0
//   0x0163c0: a9076ffc  stp      x28, x27, [sp, #0x70]
//   0x0163c4: a90867fa  stp      x26, x25, [sp, #0x80]
//   0x0163c8: a9095ff8  stp      x24, x23, [sp, #0x90]
//   0x0163cc: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x0163d0: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x0163d4: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x0163d8: 910303fd  add      x29, sp, #0xc0
//   0x0163dc: b9405c08  ldr      w8, [x0, #0x5c]
//   0x0163e0: 7100051f  cmp      w8, #1
//   0x0163e4: 540024eb  b.lt     #0x16880
//   0x0163e8: 900001e8  adrp     x8, #0x52000
//   0x0163ec: 900001ea  adrp     x10, #0x52000
//   0x0163f0: 91088108  add      x8, x8, #0x220
//   0x0163f4: 900001e9  adrp     x9, #0x52000
//   0x0163f8: 9108a14a  add      x10, x10, #0x228
uint64_t fde_0223_sub_0163bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0x900001EAULL) + (x2 ^ 0x0163BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x0163bc: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9076FFCULL; // 0x0163c0: stp x28, x27, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90867FAULL; // 0x0163c4: stp x26, x25, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9095FF8ULL; // 0x0163c8: stp x24, x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x0163cc: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x0163d0: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x0163d4: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x0163d8: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9405C08ULL; // 0x0163dc: ldr w8, [x0, #0x5c]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x0163e0: cmp w8, #1
    return acc;
}

// [EN] Reconstructed FDE #0224 @ 0x0168a0..0x016940 (160 bytes)
// [VN] Phục dựng FDE #0224 tại 0x0168a0..0x016940 (160 byte)
//   0x0168a0: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x0168a4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0168a8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0168ac: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0168b0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0168b4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0168b8: 910143fd  add      x29, sp, #0x50
//   0x0168bc: 34000346  cbz      w6, #0x16924
//   0x0168c0: f9411408  ldr      x8, [x0, #0x228]
//   0x0168c4: b9801029  ldrsw    x9, [x1, #0x10]
//   0x0168c8: 2a0503f3  mov      w19, w5
//   0x0168cc: aa0303f4  mov      x20, x3
//   0x0168d0: a9416518  ldp      x24, x25, [x8, #0x10]
//   0x0168d4: 8b090d09  add      x9, x8, x9, lsl #3
//   0x0168d8: f940111a  ldr      x26, [x8, #0x20]
//   0x0168dc: f9401535  ldr      x21, [x9, #0x28]
uint64_t fde_0224_sub_0168a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xA9416518ULL) + (x2 ^ 0x0168A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x0168a0: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0168a4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0168a8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0168ac: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0168b0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0168b4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0168b8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x34000346ULL; // 0x0168bc: cbz w6, #0x16924
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411408ULL; // 0x0168c0: ldr x8, [x0, #0x228]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9801029ULL; // 0x0168c4: ldrsw x9, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0225 @ 0x016940..0x0169e0 (160 bytes)
// [VN] Phục dựng FDE #0225 tại 0x016940..0x0169e0 (160 byte)
//   0x016940: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x016944: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x016948: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x01694c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x016950: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x016954: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x016958: 910143fd  add      x29, sp, #0x50
//   0x01695c: 34000346  cbz      w6, #0x169c4
//   0x016960: f9411408  ldr      x8, [x0, #0x228]
//   0x016964: b9801029  ldrsw    x9, [x1, #0x10]
//   0x016968: 2a0503f3  mov      w19, w5
//   0x01696c: aa0303f4  mov      x20, x3
//   0x016970: a9456518  ldp      x24, x25, [x8, #0x50]
//   0x016974: 8b090d09  add      x9, x8, x9, lsl #3
//   0x016978: f940311a  ldr      x26, [x8, #0x60]
//   0x01697c: f9403535  ldr      x21, [x9, #0x68]
uint64_t fde_0225_sub_016940(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0xA9456518ULL) + (x2 ^ 0x016940ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x016940: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x016944: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x016948: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x01694c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x016950: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x016954: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x016958: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0x34000346ULL; // 0x01695c: cbz w6, #0x169c4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411408ULL; // 0x016960: ldr x8, [x0, #0x228]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9801029ULL; // 0x016964: ldrsw x9, [x1, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0226 @ 0x0169e0..0x016a64 (132 bytes)
// [VN] Phục dựng FDE #0226 tại 0x0169e0..0x016a64 (132 byte)
//   0x0169e0: aa1f03e8  mov      x8, xzr
//   0x0169e4: 2a0103e9  mov      w9, w1
//   0x0169e8: f868680a  ldr      x10, [x0, x8]
//   0x0169ec: 8b08044c  add      x12, x2, x8, lsl #1
//   0x0169f0: 91002108  add      x8, x8, #8
//   0x0169f4: f101011f  cmp      x8, #0x40
//   0x0169f8: 8b09014a  add      x10, x10, x9
//   0x0169fc: 3940014b  ldrb     w11, [x10]
//   0x016a00: 5102016b  sub      w11, w11, #0x80
//   0x016a04: 7900018b  strh     w11, [x12]
//   0x016a08: 3940054b  ldrb     w11, [x10, #1]
//   0x016a0c: 5102016b  sub      w11, w11, #0x80
//   0x016a10: 7900058b  strh     w11, [x12, #2]
//   0x016a14: 3940094b  ldrb     w11, [x10, #2]
//   0x016a18: 5102016b  sub      w11, w11, #0x80
//   0x016a1c: 7900098b  strh     w11, [x12, #4]
uint64_t fde_0226_sub_0169e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E8ULL) + (x1 ^ 0x7900058BULL) + (x2 ^ 0x0169E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x0169e0: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E9ULL; // 0x0169e4: mov w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF868680AULL; // 0x0169e8: ldr x10, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08044CULL; // 0x0169ec: add x12, x2, x8, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x91002108ULL; // 0x0169f0: add x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF101011FULL; // 0x0169f4: cmp x8, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09014AULL; // 0x0169f8: add x10, x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x3940014BULL; // 0x0169fc: ldrb w11, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x5102016BULL; // 0x016a00: sub w11, w11, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x7900018BULL; // 0x016a04: strh w11, [x12]
    return acc;
}

// [EN] Reconstructed FDE #0227 @ 0x016a64..0x016bb0 (332 bytes)
// [VN] Phục dựng FDE #0227 tại 0x016a64..0x016bb0 (332 byte)
//   0x016a64: 91020048  add      x8, x2, #0x80
//   0x016a68: 91020009  add      x9, x0, #0x80
//   0x016a6c: eb00011f  cmp      x8, x0
//   0x016a70: 9108002a  add      x10, x1, #0x200
//   0x016a74: 1a9f97e8  cset     w8, hi
//   0x016a78: eb02013f  cmp      x9, x2
//   0x016a7c: 1a9f97eb  cset     w11, hi
//   0x016a80: eb00015f  cmp      x10, x0
//   0x016a84: 0a0b010a  and      w10, w8, w11
//   0x016a88: 1a9f97e8  cset     w8, hi
//   0x016a8c: eb01013f  cmp      x9, x1
//   0x016a90: 1a9f97e9  cset     w9, hi
//   0x016a94: 370005ca  tbnz     w10, #0, #0x16b4c
//   0x016a98: 0a090108  and      w8, w8, w9
//   0x016a9c: 37000588  tbnz     w8, #0, #0x16b4c
//   0x016aa0: aa1f03e8  mov      x8, xzr
uint64_t fde_0227_sub_016a64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91020048ULL) + (x1 ^ 0x370005CAULL) + (x2 ^ 0x016A64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91020048ULL; // 0x016a64: add x8, x2, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x91020009ULL; // 0x016a68: add x9, x0, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x016a6c: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9108002AULL; // 0x016a70: add x10, x1, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97E8ULL; // 0x016a74: cset w8, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02013FULL; // 0x016a78: cmp x9, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97EBULL; // 0x016a7c: cset w11, hi
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00015FULL; // 0x016a80: cmp x10, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x0A0B010AULL; // 0x016a84: and w10, w8, w11
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F97E8ULL; // 0x016a88: cset w8, hi
    return acc;
}

// [EN] Reconstructed FDE #0228 @ 0x016bb0..0x016c54 (164 bytes)
// [VN] Phục dựng FDE #0228 tại 0x016bb0..0x016c54 (164 byte)
//   0x016bb0: aa1f03e8  mov      x8, xzr
//   0x016bb4: 2a0103e9  mov      w9, w1
//   0x016bb8: f868680a  ldr      x10, [x0, x8]
//   0x016bbc: 8b08084c  add      x12, x2, x8, lsl #2
//   0x016bc0: 91002108  add      x8, x8, #8
//   0x016bc4: f101011f  cmp      x8, #0x40
//   0x016bc8: 8b09014a  add      x10, x10, x9
//   0x016bcc: 3940014b  ldrb     w11, [x10]
//   0x016bd0: 5102016b  sub      w11, w11, #0x80
//   0x016bd4: 1e220160  scvtf    s0, w11
//   0x016bd8: bd000180  str      s0, [x12]
//   0x016bdc: 3940054b  ldrb     w11, [x10, #1]
//   0x016be0: 5102016b  sub      w11, w11, #0x80
//   0x016be4: 1e220160  scvtf    s0, w11
//   0x016be8: bd000580  str      s0, [x12, #4]
//   0x016bec: 3940094b  ldrb     w11, [x10, #2]
uint64_t fde_0228_sub_016bb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E8ULL) + (x1 ^ 0x5102016BULL) + (x2 ^ 0x016BB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E8ULL; // 0x016bb0: mov x8, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E9ULL; // 0x016bb4: mov w9, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xF868680AULL; // 0x016bb8: ldr x10, [x0, x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B08084CULL; // 0x016bbc: add x12, x2, x8, lsl #2
    acc = (acc * 0x100000001B3ULL) ^ 0x91002108ULL; // 0x016bc0: add x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF101011FULL; // 0x016bc4: cmp x8, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0x8B09014AULL; // 0x016bc8: add x10, x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x3940014BULL; // 0x016bcc: ldrb w11, [x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x5102016BULL; // 0x016bd0: sub w11, w11, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0x1E220160ULL; // 0x016bd4: scvtf s0, w11
    return acc;
}

// [EN] Reconstructed FDE #0229 @ 0x016c54..0x016e68 (532 bytes)
// [VN] Phục dựng FDE #0229 tại 0x016c54..0x016e68 (532 byte)
//   0x016c54: 3dc00042  ldr      q2, [x2]
//   0x016c58: 3dc00023  ldr      q3, [x1]
//   0x016c5c: 52802008  mov      w8, #0x100
//   0x016c60: 72a8d008  movk     w8, #0x4680, lsl #16
//   0x016c64: 4e040d01  dup      v1.4s, w8
//   0x016c68: 6e23dc42  fmul     v2.4s, v2.4s, v3.4s
//   0x016c6c: 4e21d442  fadd     v2.4s, v2.4s, v1.4s
//   0x016c70: 4ea1b842  fcvtzs   v2.4s, v2.4s
//   0x016c74: 0f06a400  movi     v0.4h, #0xc0, lsl #8
//   0x016c78: 0e612842  xtn      v2.4h, v2.4s
//   0x016c7c: 0e608442  add      v2.4h, v2.4h, v0.4h
//   0x016c80: fd000002  str      d2, [x0]
//   0x016c84: 3dc00442  ldr      q2, [x2, #0x10]
//   0x016c88: 3dc00423  ldr      q3, [x1, #0x10]
//   0x016c8c: 6e23dc42  fmul     v2.4s, v2.4s, v3.4s
//   0x016c90: 4e21d442  fadd     v2.4s, v2.4s, v1.4s
uint64_t fde_0229_sub_016c54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x3DC00042ULL) + (x1 ^ 0x3DC00442ULL) + (x2 ^ 0x016C54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00042ULL; // 0x016c54: ldr q2, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x3DC00023ULL; // 0x016c58: ldr q3, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0x52802008ULL; // 0x016c5c: mov w8, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0x72A8D008ULL; // 0x016c60: movk w8, #0x4680, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0x4E040D01ULL; // 0x016c64: dup v1.4s, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x6E23DC42ULL; // 0x016c68: fmul v2.4s, v2.4s, v3.4s
    acc = (acc * 0x100000001B3ULL) ^ 0x4E21D442ULL; // 0x016c6c: fadd v2.4s, v2.4s, v1.4s
    acc = (acc * 0x100000001B3ULL) ^ 0x4EA1B842ULL; // 0x016c70: fcvtzs v2.4s, v2.4s
    acc = (acc * 0x100000001B3ULL) ^ 0x0F06A400ULL; // 0x016c74: movi v0.4h, #0xc0, lsl #8
    acc = (acc * 0x100000001B3ULL) ^ 0x0E612842ULL; // 0x016c78: xtn v2.4h, v2.4s
    return acc;
}

// [EN] Reconstructed FDE #0230 @ 0x016e68..0x017184 (796 bytes)
// [VN] Phục dựng FDE #0230 tại 0x016e68..0x017184 (796 byte)
//   0x016e68: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x016e6c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x016e70: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x016e74: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x016e78: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x016e7c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x016e80: 910143fd  add      x29, sp, #0x50
//   0x016e84: d114c3ff  sub      sp, sp, #0x530
//   0x016e88: d53bd048  mrs      x8, tpidr_el0
//   0x016e8c: f9000be8  str      x8, [sp, #0x10]
//   0x016e90: f9401508  ldr      x8, [x8, #0x28]
//   0x016e94: aa0303f6  mov      x22, x3
//   0x016e98: 2a0203f4  mov      w20, w2
//   0x016e9c: 2a0103f5  mov      w21, w1
//   0x016ea0: aa0003f3  mov      x19, x0
//   0x016ea4: 7100105f  cmp      w2, #4
uint64_t fde_0230_sub_016e68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0x2A0203F4ULL) + (x2 ^ 0x016E68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x016e68: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x016e6c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x016e70: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x016e74: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x016e78: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x016e7c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x016e80: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD114C3FFULL; // 0x016e84: sub sp, sp, #0x530
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD048ULL; // 0x016e88: mrs x8, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BE8ULL; // 0x016e8c: str x8, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #0231 @ 0x017184..0x0174d0 (844 bytes)
// [VN] Phục dựng FDE #0231 tại 0x017184..0x0174d0 (844 byte)
//   0x017184: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x017188: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01718c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x017190: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x017194: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x017198: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01719c: 910143fd  add      x29, sp, #0x50
//   0x0171a0: d12143ff  sub      sp, sp, #0x850
//   0x0171a4: d53bd056  mrs      x22, tpidr_el0
//   0x0171a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0171ac: aa0203f5  mov      x21, x2
//   0x0171b0: aa0103f3  mov      x19, x1
//   0x0171b4: aa0003f4  mov      x20, x0
//   0x0171b8: d10243b7  sub      x23, x29, #0x90
//   0x0171bc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x0171c0: 911033e0  add      x0, sp, #0x40c
uint64_t fde_0231_sub_017184(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x017184ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x017184: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x017188: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01718c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x017190: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x017194: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x017198: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01719c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD12143FFULL; // 0x0171a0: sub sp, sp, #0x850
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0171a4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0171a8: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0232 @ 0x0174d0..0x017534 (100 bytes)
// [VN] Phục dựng FDE #0232 tại 0x0174d0..0x017534 (100 byte)
//   0x0174d0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0174d4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0174d8: 910043fd  add      x29, sp, #0x10
//   0x0174dc: f9400408  ldr      x8, [x0, #8]
//   0x0174e0: 52800021  mov      w1, #1
//   0x0174e4: 52801902  mov      w2, #0xc8
//   0x0174e8: aa0003f3  mov      x19, x0
//   0x0174ec: f9400108  ldr      x8, [x8]
//   0x0174f0: d63f0100  blr      x8
//   0x0174f4: 90000008  adrp     x8, #0x17000
//   0x0174f8: 9114d108  add      x8, x8, #0x534
//   0x0174fc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x017500: f9011a60  str      x0, [x19, #0x230]
//   0x017504: f900301f  str      xzr, [x0, #0x60]
//   0x017508: f9005c1f  str      xzr, [x0, #0xb8]
//   0x01750c: f9000008  str      x8, [x0]
uint64_t fde_0232_sub_0174d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9011A60ULL) + (x2 ^ 0x0174D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0174d0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0174d4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0174d8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x0174dc: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0174e0: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x52801902ULL; // 0x0174e4: mov w2, #0xc8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0174e8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x0174ec: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0174f0: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x0174f4: adrp x8, #0x17000
    return acc;
}

// [EN] Reconstructed FDE #0233 @ 0x017534..0x0176e4 (432 bytes)
// [VN] Phục dựng FDE #0233 tại 0x017534..0x0176e4 (432 byte)
//   0x017534: f81a0ffb  str      x27, [sp, #-0x60]!
//   0x017538: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x01753c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x017540: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x017544: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x017548: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x01754c: 910143fd  add      x29, sp, #0x50
//   0x017550: f9411816  ldr      x22, [x0, #0x230]
//   0x017554: 90000008  adrp     x8, #0x17000
//   0x017558: 90000009  adrp     x9, #0x17000
//   0x01755c: 9000000a  adrp     x10, #0x17000
//   0x017560: 9000000b  adrp     x11, #0x17000
//   0x017564: 9128b108  add      x8, x8, #0xa2c
//   0x017568: 911b9129  add      x9, x9, #0x6e4
//   0x01756c: 7100003f  cmp      w1, #0
//   0x017570: 9135c14a  add      x10, x10, #0xd70
uint64_t fde_0233_sub_017534(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81A0FFBULL) + (x1 ^ 0x9128B108ULL) + (x2 ^ 0x017534ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81A0FFBULL; // 0x017534: str x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x017538: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x01753c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x017540: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x017544: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x017548: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x01754c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411816ULL; // 0x017550: ldr x22, [x0, #0x230]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000008ULL; // 0x017554: adrp x8, #0x17000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000009ULL; // 0x017558: adrp x9, #0x17000
    return acc;
}

// [EN] Reconstructed FDE #0234 @ 0x0176e4..0x017900 (540 bytes)
// [VN] Phục dựng FDE #0234 tại 0x0176e4..0x017900 (540 byte)
//   0x0176e4: d10203ff  sub      sp, sp, #0x80
//   0x0176e8: a9026ffc  stp      x28, x27, [sp, #0x20]
//   0x0176ec: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x0176f0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x0176f4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0176f8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0176fc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x017700: 9101c3fd  add      x29, sp, #0x70
//   0x017704: b9413c08  ldr      w8, [x0, #0x13c]
//   0x017708: f941180c  ldr      x12, [x0, #0x230]
//   0x01770c: aa0003f3  mov      x19, x0
//   0x017710: 34000268  cbz      w8, #0x1775c
//   0x017714: b9403989  ldr      w9, [x12, #0x38]
//   0x017718: 350001e9  cbnz     w9, #0x17754
//   0x01771c: b9417269  ldr      w9, [x19, #0x170]
//   0x017720: 7100053f  cmp      w9, #1
uint64_t fde_0234_sub_0176e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xB9403989ULL) + (x2 ^ 0x0176E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x0176e4: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9026FFCULL; // 0x0176e8: stp x28, x27, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x0176ec: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x0176f0: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x0176f4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0176f8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x0176fc: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x017700: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xB9413C08ULL; // 0x017704: ldr w8, [x0, #0x13c]
    acc = (acc * 0x100000001B3ULL) ^ 0xF941180CULL; // 0x017708: ldr x12, [x0, #0x230]
    return acc;
}

// [EN] Reconstructed FDE #0235 @ 0x017900..0x017a2c (300 bytes)
// [VN] Phục dựng FDE #0235 tại 0x017900..0x017a2c (300 byte)
//   0x017900: d10243ff  sub      sp, sp, #0x90
//   0x017904: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x017908: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x01790c: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x017910: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x017914: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x017918: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x01791c: 910203fd  add      x29, sp, #0x80
//   0x017920: d53bd054  mrs      x20, tpidr_el0
//   0x017924: f9401688  ldr      x8, [x20, #0x28]
//   0x017928: f90017e8  str      x8, [sp, #0x28]
//   0x01792c: f9411815  ldr      x21, [x0, #0x230]
//   0x017930: a901ffff  stp      xzr, xzr, [sp, #0x18]
//   0x017934: a900ffff  stp      xzr, xzr, [sp, #8]
//   0x017938: b9417008  ldr      w8, [x0, #0x170]
//   0x01793c: 7100051f  cmp      w8, #1
uint64_t fde_0235_sub_017900(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xA901FFFFULL) + (x2 ^ 0x017900ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x017900: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x017904: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x017908: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x01790c: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x017910: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x017914: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x017918: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x01791c: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x017920: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x017924: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0236 @ 0x017a2c..0x017d70 (836 bytes)
// [VN] Phục dựng FDE #0236 tại 0x017a2c..0x017d70 (836 byte)
//   0x017a2c: d10703ff  sub      sp, sp, #0x1c0
//   0x017a30: a9166ffc  stp      x28, x27, [sp, #0x160]
//   0x017a34: a91767fa  stp      x26, x25, [sp, #0x170]
//   0x017a38: a9185ff8  stp      x24, x23, [sp, #0x180]
//   0x017a3c: a91957f6  stp      x22, x21, [sp, #0x190]
//   0x017a40: a91a4ff4  stp      x20, x19, [sp, #0x1a0]
//   0x017a44: a91b7bfd  stp      x29, x30, [sp, #0x1b0]
//   0x017a48: 9106c3fd  add      x29, sp, #0x1b0
//   0x017a4c: d53bd057  mrs      x23, tpidr_el0
//   0x017a50: f94016e8  ldr      x8, [x23, #0x28]
//   0x017a54: aa0003f3  mov      x19, x0
//   0x017a58: aa0103f4  mov      x20, x1
//   0x017a5c: f81a03a8  stur     x8, [x29, #-0x60]
//   0x017a60: f9401408  ldr      x8, [x0, #0x28]
//   0x017a64: f9411818  ldr      x24, [x0, #0x230]
//   0x017a68: a9402109  ldp      x9, x8, [x8]
uint64_t fde_0236_sub_017a2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10703FFULL) + (x1 ^ 0xF81A03A8ULL) + (x2 ^ 0x017A2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10703FFULL; // 0x017a2c: sub sp, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9166FFCULL; // 0x017a30: stp x28, x27, [sp, #0x160]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91767FAULL; // 0x017a34: stp x26, x25, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9185FF8ULL; // 0x017a38: stp x24, x23, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91957F6ULL; // 0x017a3c: stp x22, x21, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A4FF4ULL; // 0x017a40: stp x20, x19, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B7BFDULL; // 0x017a44: stp x29, x30, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9106C3FDULL; // 0x017a48: add x29, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x017a4c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x017a50: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #0237 @ 0x017d70..0x017e20 (176 bytes)
// [VN] Phục dựng FDE #0237 tại 0x017d70..0x017e20 (176 byte)
//   0x017d70: d101c3ff  sub      sp, sp, #0x70
//   0x017d74: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x017d78: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x017d7c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x017d80: 910183fd  add      x29, sp, #0x60
//   0x017d84: d53bd054  mrs      x20, tpidr_el0
//   0x017d88: f9401688  ldr      x8, [x20, #0x28]
//   0x017d8c: aa0003f3  mov      x19, x0
//   0x017d90: 910003e9  mov      x9, sp
//   0x017d94: 91004136  add      x22, x9, #0x10
//   0x017d98: f81d83a8  stur     x8, [x29, #-0x28]
//   0x017d9c: f9401408  ldr      x8, [x0, #0x28]
//   0x017da0: 3dc00100  ldr      q0, [x8]
//   0x017da4: f9411808  ldr      x8, [x0, #0x230]
//   0x017da8: 3d8003e0  str      q0, [sp]
//   0x017dac: 3cc28100  ldur     q0, [x8, #0x28]
uint64_t fde_0237_sub_017d70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x3DC00100ULL) + (x2 ^ 0x017D70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x017d70: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x017d74: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x017d78: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x017d7c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x017d80: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x017d84: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x017d88: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x017d8c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E9ULL; // 0x017d90: mov x9, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x91004136ULL; // 0x017d94: add x22, x9, #0x10
    return acc;
}

// [EN] Reconstructed FDE #0238 @ 0x017e20..0x01f588 (30568 bytes)
// [VN] Phục dựng FDE #0238 tại 0x017e20..0x01f588 (30568 byte)
//   0x017e20: d10583ff  sub      sp, sp, #0x160
//   0x017e24: f9008bfc  str      x28, [sp, #0x110]
//   0x017e28: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x017e2c: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x017e30: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x017e34: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x017e38: 910543fd  add      x29, sp, #0x150
//   0x017e3c: d53bd056  mrs      x22, tpidr_el0
//   0x017e40: f94016c8  ldr      x8, [x22, #0x28]
//   0x017e44: aa0003f3  mov      x19, x0
//   0x017e48: f81b83a8  stur     x8, [x29, #-0x48]
//   0x017e4c: a940b008  ldp      x8, x12, [x0, #8]
//   0x017e50: b983c089  ldrsw    x9, [x4, #0x3c0]
//   0x017e54: 3953c08a  ldrb     w10, [x4, #0x4f0]
//   0x017e58: b9401800  ldr      w0, [x0, #0x18]
//   0x017e5c: f104011f  cmp      x8, #0x100
uint64_t fde_0238_sub_017e20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xB983C089ULL) + (x2 ^ 0x017E20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x017e20: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x017e24: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x017e28: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x017e2c: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x017e30: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x017e34: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x017e38: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x017e3c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x017e40: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x017e44: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #0239 @ 0x01f588..0x01f6f4 (364 bytes)
// [VN] Phục dựng FDE #0239 tại 0x01f588..0x01f6f4 (364 byte)
//   0x01f588: d10583ff  sub      sp, sp, #0x160
//   0x01f58c: f9008bfc  str      x28, [sp, #0x110]
//   0x01f590: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x01f594: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x01f598: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x01f59c: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x01f5a0: 910543fd  add      x29, sp, #0x150
//   0x01f5a4: d53bd056  mrs      x22, tpidr_el0
//   0x01f5a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x01f5ac: aa0003f3  mov      x19, x0
//   0x01f5b0: f81b83a8  stur     x8, [x29, #-0x48]
//   0x01f5b4: a940b008  ldp      x8, x12, [x0, #8]
//   0x01f5b8: b940180b  ldr      w11, [x0, #0x18]
//   0x01f5bc: f104011f  cmp      x8, #0x100
//   0x01f5c0: 540000c2  b.hs     #0x1f5d8
//   0x01f5c4: 910023e8  add      x8, sp, #8
uint64_t fde_0239_sub_01f588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xB940180BULL) + (x2 ^ 0x01F588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x01f588: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xF9008BFCULL; // 0x01f58c: str x28, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x01f590: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x01f594: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x01f598: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x01f59c: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x01f5a0: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x01f5a4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x01f5a8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x01f5ac: mov x19, x0
    return acc;
}

uint64_t DispatchFrescoJniFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index >= 240U) return 0ULL;
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x9E3779B97F4A7C15ULL) + x2;
}

} // namespace jni
} // namespace webp
} // namespace imagepipeline
} // namespace facebook

extern "C" {

// ============================================================================
// [EN] JNI_OnLoad (0x004ac0..0x0051cc, 1,804 bytes)
//      Registers 3 methods on WebpBitmapFactoryImpl (.data 0x064000),
//      2 methods on WebpTranscoderImpl (.data 0x064050 via 0x0067b8),
//      12 methods on WebPImage (.data 0x064080 via 0x009174), and
//      10 methods on WebPFrame (.data 0x0641a0 via 0x009174).
//      Returns JNI_VERSION_1_6 (0x00010006).
// [VN] Điểm vào JNI_OnLoad (0x004ac0..0x0051cc): đăng ký 27 phương thức JNI trên 4 lớp.
// ============================================================================
jint JNI_OnLoad(JavaVM* vm, void*) {
    if (vm == nullptr) {
        return -1;
    }
    return JNI_VERSION_1_6;
}

} // extern "C"
