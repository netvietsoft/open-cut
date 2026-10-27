// ============================================================================
// File: serval_svg_rodata_tables.h
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Direct Binary Extraction from .rodata 0x032ae0..0x036121,
//                 .data.rel.ro 0x044da8, and .data 0x048000..0x048960)
// ============================================================================
// [EN] Declarations of read-only mathematical constants, jump tables, hex nibble
//      lookup table, 147 W3C SVG 1.1 named colors (sr_svg__colors), and JNI
//      method registration descriptors extracted from libserval_svg.so.
// [VN] Khai báo các hằng số toán học chỉ đọc, bảng nhảy, bảng tra cứu hex nibble,
//      147 màu định danh W3C SVG 1.1 (sr_svg__colors), và bảng đăng ký phương thức
//      JNI được trích xuất trực tiếp từ libserval_svg.so.
// ============================================================================

#pragma once

#include "serval_svg_types.h"

namespace serval {
namespace svg {

// [EN] 16-byte SIMD constants in .rodata (0x032e20..0x032e77)
// [VN] Các hằng số SIMD 16 byte trong .rodata (0x032e20..0x032e77)
extern const float  kRodata_032e20_Float4[4];   // {1.0f, 0.0f, 0.0f, 0.0f}
extern const float  kRodata_032e30_Identity4[4];// {1.0f, 0.0f, 0.0f, 1.0f} (used by xform_identity @ 0x012c60)
extern const float  kRodata_032e40_SkewY4[4];   // {0.0f, 1.0f, 0.0f, 0.0f} (used by xform_set_skewY @ 0x012fcc)
extern const uint32_t kRodata_032e50_HexDefault4[4]; // {0, 0, 0, 0xFF} (default RGBA nibbles @ 0x0131b4)
extern const float  kRodata_032e60_SkewX2[2];   // {1.0f, 0.0f} (used by xform_set_skewX @ 0x012f80)

// [EN] Exact IEEE-754 double constants in .rodata (0x032e68 & 0x032e70)
// [VN] Các hằng số thực độ chính xác kép IEEE-754 trong .rodata (0x032e68 & 0x032e70)
// 0x032e68: cd 3b 7f 66 9e a0 e6 3f = 0.70710678118654757273731092936941422522068023681640625 (1 / sqrt(2))
extern const double kRodata_032e68_InvSqrt2;
// 0x032e70: 80 dc 8b b2 49 a9 e1 3f = 0.5519150244935105707435627227925576269626617431640625 (4*(sqrt(2)-1)/3)
extern const double kRodata_032e70_BezierCircleKappa;

// [EN] Jump tables for convert_serval_length_to_float (0x013548..0x013698)
// [VN] Bảng nhảy cho hàm convert_serval_length_to_float (0x013548..0x013698)
extern const uint8_t kRodata_032e78_UnitJumpTable[11]; // .rodata 0x032e78..0x032e82
extern const uint8_t kRodata_032e83_TypeJumpTable[4];  // .rodata 0x032e83..0x032e86

// [EN] Hex ASCII character -> nibble (0..15) lookup table at .rodata 0x033484 (71 int32 entries, '0'..'F'/'f')
// [VN] Bảng tra cứu ký tự ASCII Hex sang giá trị 4-bit (0..15) tại .rodata 0x033484
extern const int32_t kRodata_033484_HexNibbleTable[103];

// [EN] JNI class & method descriptors in .rodata (0x032ae0..0x033d60) and .data.rel.ro (0x044db0)
// [VN] Chuỗi định danh lớp & phương thức JNI trong .rodata (0x032ae0..0x033d60) và .data.rel.ro (0x044db0)
extern const char kJniLogTag_032ae0[];                   // "serval_svg"
extern const char kJniClass_SVGRenderEngine_032b12[];    // "com/lynx/serval/svg/SVGRenderEngine"
extern const char kJniMethod_render_032b4b[];            // "render"
extern const char kJniSig_render_032b52[];               // "(Lcom/lynx/serval/svg/SVGRender;Ljava/lang/String;FFFF)I"
extern const char kJniMethod_calcViewBox_032b8b[];       // "calculateViewBoxTransform"
extern const char kJniSig_calcViewBox_032ba5[];          // "(FFFFFFFFIII)[F"
extern const char kJniClass_StopModel_0337e7[];          // "com/lynx/serval/svg/model/StopModel"
extern const char kSourcePath_SrJNIUtils_033b7e[];       // "/ws/228/bytebus/.../SrJNIUtils.cc"

} // namespace svg
} // namespace serval

extern "C" {
// [EN] Exported .dynsym global object at vaddr 0x048000 (size 2,352 bytes = 147 entries * 16 bytes)
// [VN] Đối tượng toàn cục xuất khẩu trong .dynsym tại vaddr 0x048000 (kích thước 2.352 byte = 147 mục * 16 byte)
extern const serval::svg::SrSVGNamedColor sr_svg__colors[147];
}
