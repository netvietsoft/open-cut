// ============================================================================
// File: serval_svg_rodata_tables.cpp
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Byte-Exact Extraction from .rodata 0x032ae0..0x036121
//                 and .data 0x048000..0x048930)
// ============================================================================
// [EN] Defines all read-only tables, IEEE-754 SIMD/double constants, jump tables,
//      hex lookup table, and all 147 W3C SVG 1.1 named colors (sr_svg__colors).
// [VN] Định nghĩa toàn bộ các bảng chỉ đọc, hằng số IEEE-754 SIMD/double, bảng nhảy,
//      bảng tra cứu hex, và toàn bộ 147 màu định danh W3C SVG 1.1 (sr_svg__colors).
// ============================================================================

#include "serval_svg_rodata_tables.h"

namespace serval {
namespace svg {

// .rodata 0x032e20: 00 00 80 3f 00 00 00 00 00 00 00 00 00 00 00 00
const float kRodata_032e20_Float4[4] = { 1.0f, 0.0f, 0.0f, 0.0f };

// .rodata 0x032e30: 00 00 80 3f 00 00 00 00 00 00 00 00 00 00 80 3f
const float kRodata_032e30_Identity4[4] = { 1.0f, 0.0f, 0.0f, 1.0f };

// .rodata 0x032e40: 00 00 00 00 00 00 80 3f 00 00 00 00 00 00 00 00
const float kRodata_032e40_SkewY4[4] = { 0.0f, 1.0f, 0.0f, 0.0f };

// .rodata 0x032e50: 00 00 00 00 00 00 00 00 00 00 00 00 ff 00 00 00
const uint32_t kRodata_032e50_HexDefault4[4] = { 0u, 0u, 0u, 0xFFu };

// .rodata 0x032e60: 00 00 80 3f 00 00 00 00
const float kRodata_032e60_SkewX2[2] = { 1.0f, 0.0f };

// .rodata 0x032e68: cd 3b 7f 66 9e a0 e6 3f = 1.0 / sqrt(2.0)
const double kRodata_032e68_InvSqrt2 = 0.70710678118654757273731092936941422522068023681640625;

// .rodata 0x032e70: 80 dc 8b b2 49 a9 e1 3f = 4.0 * (sqrt(2.0) - 1.0) / 3.0
const double kRodata_032e70_BezierCircleKappa = 0.5519150244935105707435627227925576269626617431640625;

// .rodata 0x032e78..0x032e82: Jump table for SrSVGLengthUnit (0..10) in convert_serval_length_to_float
const uint8_t kRodata_032e78_UnitJumpTable[11] = {
    0x00, 0x00, 0x02, 0x13, 0x17, 0x00, 0x1f, 0x24, 0x29, 0x2d, 0x32
};

// .rodata 0x032e83..0x032e86: Jump table for SrSVGLengthType (0..3) in convert_serval_length_to_float
const uint8_t kRodata_032e83_TypeJumpTable[4] = {
    0x00, 0x2d, 0x30, 0x2b
};

// .rodata 0x033484: Hex nibble lookup table used in make_serval_color (0x0131f8..0x013244)
const int32_t kRodata_033484_HexNibbleTable[103] = {
    -1,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  1,  2,  3,  4,  5,  6,  7,
     8,  9,  0,  0,  0,  0,  0,  0,
     0, 10, 11, 12, 13, 14, 15, -1,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0,  0,  0,  0,  0,  0,  0,  0,
     0, 10, 11, 12, 13, 14, 15,
};

const char kJniLogTag_032ae0[]                = "serval_svg";
const char kJniClass_SVGRenderEngine_032b12[] = "com/lynx/serval/svg/SVGRenderEngine";
const char kJniMethod_render_032b4b[]         = "render";
const char kJniSig_render_032b52[]            = "(Lcom/lynx/serval/svg/SVGRender;Ljava/lang/String;FFFF)I";
const char kJniMethod_calcViewBox_032b8b[]    = "calculateViewBoxTransform";
const char kJniSig_calcViewBox_032ba5[]       = "(FFFFFFFFIII)[F";
const char kJniClass_StopModel_0337e7[]       = "com/lynx/serval/svg/model/StopModel";
const char kSourcePath_SrJNIUtils_033b7e[]    = "/ws/228/bytebus/repositories/3d3250950c2f6d5f34b6e9471f2edcf3/9e5930d5629725e4c9332725e6b7ec7c/Svg/src/cpp/canvas/android/SrJNIUtils.cc";

} // namespace svg
} // namespace serval

extern "C" {

// ============================================================================
// [EN] 147 W3C SVG 1.1 Named Colors at .data 0x048000..0x048930 (2,352 bytes).
//      Linearly scanned at 0x013478..0x013490 (cmp x20, #0x930; b.ne #0x13478).
// [VN] 147 màu định danh W3C SVG 1.1 tại .data 0x048000..0x048930 (2.352 byte).
//      Được quét tuyến tính tại 0x013478..0x013490 (cmp x20, #0x930; b.ne #0x13478).
// ============================================================================
const serval::svg::SrSVGNamedColor sr_svg__colors[147] = {
    /* [  0] 0x048000 -> .rodata 0x0332fd */ { "red", 0xffff0000u, 0u },
    /* [  1] 0x048010 -> .rodata 0x033025 */ { "green", 0xff008000u, 0u },
    /* [  2] 0x048020 -> .rodata 0x032f07 */ { "blue", 0xff0000ffu, 0u },
    /* [  3] 0x048030 -> .rodata 0x033171 */ { "yellow", 0xffffff00u, 0u },
    /* [  4] 0x048040 -> .rodata 0x032fa1 */ { "cyan", 0xff00ffffu, 0u },
    /* [  5] 0x048050 -> .rodata 0x032fde */ { "magenta", 0xffff00ffu, 0u },
    /* [  6] 0x048060 -> .rodata 0x032efc */ { "black", 0xff000000u, 0u },
    /* [  7] 0x048070 -> .rodata 0x033050 */ { "grey", 0xff808080u, 0u },
    /* [  8] 0x048080 -> .rodata 0x033042 */ { "gray", 0xff808080u, 0u },
    /* [  9] 0x048090 -> .rodata 0x032f13 */ { "white", 0xffffffffu, 0u },
    /* [ 10] 0x0480a0 -> .rodata 0x032f02 */ { "aliceblue", 0xfff0f8ffu, 0u },
    /* [ 11] 0x0480b0 -> .rodata 0x032f0c */ { "antiquewhite", 0xfffaebd7u, 0u },
    /* [ 12] 0x0480c0 -> .rodata 0x032f19 */ { "aqua", 0xff00ffffu, 0u },
    /* [ 13] 0x0480d0 -> .rodata 0x033223 */ { "aquamarine", 0xff7fffd4u, 0u },
    /* [ 14] 0x0480e0 -> .rodata 0x032f1e */ { "azure", 0xfff0ffffu, 0u },
    /* [ 15] 0x0480f0 -> .rodata 0x032f24 */ { "beige", 0xfff5f5dcu, 0u },
    /* [ 16] 0x048100 -> .rodata 0x032f2a */ { "bisque", 0xffffe4c4u, 0u },
    /* [ 17] 0x048110 -> .rodata 0x032f31 */ { "blanchedalmond", 0xffffebcdu, 0u },
    /* [ 18] 0x048120 -> .rodata 0x032f40 */ { "blueviolet", 0xff8a2be2u, 0u },
    /* [ 19] 0x048130 -> .rodata 0x033379 */ { "brown", 0xffa52a2au, 0u },
    /* [ 20] 0x048140 -> .rodata 0x032f4b */ { "burlywood", 0xffdeb887u, 0u },
    /* [ 21] 0x048150 -> .rodata 0x032f55 */ { "cadetblue", 0xff5f9ea0u, 0u },
    /* [ 22] 0x048160 -> .rodata 0x032f5f */ { "chartreuse", 0xff7fff00u, 0u },
    /* [ 23] 0x048170 -> .rodata 0x032f6a */ { "chocolate", 0xffd2691eu, 0u },
    /* [ 24] 0x048180 -> .rodata 0x033153 */ { "coral", 0xffff7f50u, 0u },
    /* [ 25] 0x048190 -> .rodata 0x032f74 */ { "cornflowerblue", 0xff6495edu, 0u },
    /* [ 26] 0x0481a0 -> .rodata 0x032f83 */ { "cornsilk", 0xfffff8dcu, 0u },
    /* [ 27] 0x0481b0 -> .rodata 0x032f8c */ { "crimson", 0xffdc143cu, 0u },
    /* [ 28] 0x0481c0 -> .rodata 0x032f94 */ { "darkblue", 0xff00008bu, 0u },
    /* [ 29] 0x0481d0 -> .rodata 0x032f9d */ { "darkcyan", 0xff008b8bu, 0u },
    /* [ 30] 0x0481e0 -> .rodata 0x032fa6 */ { "darkgoldenrod", 0xffb8860bu, 0u },
    /* [ 31] 0x0481f0 -> .rodata 0x032fb4 */ { "darkgray", 0xffa9a9a9u, 0u },
    /* [ 32] 0x048200 -> .rodata 0x032fbd */ { "darkgreen", 0xff006400u, 0u },
    /* [ 33] 0x048210 -> .rodata 0x032fc7 */ { "darkgrey", 0xffa9a9a9u, 0u },
    /* [ 34] 0x048220 -> .rodata 0x032fd0 */ { "darkkhaki", 0xffbdb76bu, 0u },
    /* [ 35] 0x048230 -> .rodata 0x032fda */ { "darkmagenta", 0xff8b008bu, 0u },
    /* [ 36] 0x048240 -> .rodata 0x032fe6 */ { "darkolivegreen", 0xff556b2fu, 0u },
    /* [ 37] 0x048250 -> .rodata 0x032ff5 */ { "darkorange", 0xffff8c00u, 0u },
    /* [ 38] 0x048260 -> .rodata 0x033000 */ { "darkorchid", 0xff9932ccu, 0u },
    /* [ 39] 0x048270 -> .rodata 0x03300b */ { "darkred", 0xff8b0000u, 0u },
    /* [ 40] 0x048280 -> .rodata 0x033013 */ { "darksalmon", 0xffe9967au, 0u },
    /* [ 41] 0x048290 -> .rodata 0x03301e */ { "darkseagreen", 0xff8fbc8fu, 0u },
    /* [ 42] 0x0482a0 -> .rodata 0x03302b */ { "darkslateblue", 0xff483d8bu, 0u },
    /* [ 43] 0x0482b0 -> .rodata 0x033039 */ { "darkslategray", 0xff2f4f4fu, 0u },
    /* [ 44] 0x0482c0 -> .rodata 0x033047 */ { "darkslategrey", 0xff2f4f4fu, 0u },
    /* [ 45] 0x0482d0 -> .rodata 0x033055 */ { "darkturquoise", 0xff00ced1u, 0u },
    /* [ 46] 0x0482e0 -> .rodata 0x033063 */ { "darkviolet", 0xff9400d3u, 0u },
    /* [ 47] 0x0482f0 -> .rodata 0x03306e */ { "deeppink", 0xffff1493u, 0u },
    /* [ 48] 0x048300 -> .rodata 0x033077 */ { "deepskyblue", 0xff00bfffu, 0u },
    /* [ 49] 0x048310 -> .rodata 0x033083 */ { "dimgray", 0xff696969u, 0u },
    /* [ 50] 0x048320 -> .rodata 0x03308b */ { "dimgrey", 0xff696969u, 0u },
    /* [ 51] 0x048330 -> .rodata 0x033093 */ { "dodgerblue", 0xff1e90ffu, 0u },
    /* [ 52] 0x048340 -> .rodata 0x03309e */ { "firebrick", 0xffb22222u, 0u },
    /* [ 53] 0x048350 -> .rodata 0x0330a8 */ { "floralwhite", 0xfffffaf0u, 0u },
    /* [ 54] 0x048360 -> .rodata 0x0330b4 */ { "forestgreen", 0xff228b22u, 0u },
    /* [ 55] 0x048370 -> .rodata 0x0330c0 */ { "fuchsia", 0xffff00ffu, 0u },
    /* [ 56] 0x048380 -> .rodata 0x0330c8 */ { "gainsboro", 0xffdcdcdcu, 0u },
    /* [ 57] 0x048390 -> .rodata 0x0330d2 */ { "ghostwhite", 0xfff8f8ffu, 0u },
    /* [ 58] 0x0483a0 -> .rodata 0x0330dd */ { "gold", 0xffffd700u, 0u },
    /* [ 59] 0x0483b0 -> .rodata 0x033305 */ { "goldenrod", 0xffdaa520u, 0u },
    /* [ 60] 0x0483c0 -> .rodata 0x0330e2 */ { "greenyellow", 0xffadff2fu, 0u },
    /* [ 61] 0x0483d0 -> .rodata 0x0330ee */ { "honeydew", 0xfff0fff0u, 0u },
    /* [ 62] 0x0483e0 -> .rodata 0x0330f7 */ { "hotpink", 0xffff69b4u, 0u },
    /* [ 63] 0x0483f0 -> .rodata 0x0330ff */ { "indianred", 0xffcd5c5cu, 0u },
    /* [ 64] 0x048400 -> .rodata 0x033109 */ { "indigo", 0xff4b0082u, 0u },
    /* [ 65] 0x048410 -> .rodata 0x033110 */ { "ivory", 0xfffffff0u, 0u },
    /* [ 66] 0x048420 -> .rodata 0x032fd4 */ { "khaki", 0xfff0e68cu, 0u },
    /* [ 67] 0x048430 -> .rodata 0x033116 */ { "lavender", 0xffe6e6fau, 0u },
    /* [ 68] 0x048440 -> .rodata 0x03311f */ { "lavenderblush", 0xfffff0f5u, 0u },
    /* [ 69] 0x048450 -> .rodata 0x03312d */ { "lawngreen", 0xff7cfc00u, 0u },
    /* [ 70] 0x048460 -> .rodata 0x033137 */ { "lemonchiffon", 0xfffffacdu, 0u },
    /* [ 71] 0x048470 -> .rodata 0x033144 */ { "lightblue", 0xffadd8e6u, 0u },
    /* [ 72] 0x048480 -> .rodata 0x03314e */ { "lightcoral", 0xfff08080u, 0u },
    /* [ 73] 0x048490 -> .rodata 0x033159 */ { "lightcyan", 0xffe0ffffu, 0u },
    /* [ 74] 0x0484a0 -> .rodata 0x033163 */ { "lightgoldenrodyellow", 0xfffafad2u, 0u },
    /* [ 75] 0x0484b0 -> .rodata 0x033178 */ { "lightgray", 0xffd3d3d3u, 0u },
    /* [ 76] 0x0484c0 -> .rodata 0x033182 */ { "lightgreen", 0xff90ee90u, 0u },
    /* [ 77] 0x0484d0 -> .rodata 0x03318d */ { "lightgrey", 0xffd3d3d3u, 0u },
    /* [ 78] 0x0484e0 -> .rodata 0x033197 */ { "lightpink", 0xffffb6c1u, 0u },
    /* [ 79] 0x0484f0 -> .rodata 0x0331a1 */ { "lightsalmon", 0xffffa07au, 0u },
    /* [ 80] 0x048500 -> .rodata 0x0331ad */ { "lightseagreen", 0xff20b2aau, 0u },
    /* [ 81] 0x048510 -> .rodata 0x0331bb */ { "lightskyblue", 0xff87cefau, 0u },
    /* [ 82] 0x048520 -> .rodata 0x0331c8 */ { "lightslategray", 0xff778899u, 0u },
    /* [ 83] 0x048530 -> .rodata 0x0331d7 */ { "lightslategrey", 0xff778899u, 0u },
    /* [ 84] 0x048540 -> .rodata 0x0331e6 */ { "lightsteelblue", 0xffb0c4deu, 0u },
    /* [ 85] 0x048550 -> .rodata 0x0331f5 */ { "lightyellow", 0xffffffe0u, 0u },
    /* [ 86] 0x048560 -> .rodata 0x033201 */ { "lime", 0xff00ff00u, 0u },
    /* [ 87] 0x048570 -> .rodata 0x033206 */ { "limegreen", 0xff32cd32u, 0u },
    /* [ 88] 0x048580 -> .rodata 0x033210 */ { "linen", 0xfffaf0e6u, 0u },
    /* [ 89] 0x048590 -> .rodata 0x033216 */ { "maroon", 0xff800000u, 0u },
    /* [ 90] 0x0485a0 -> .rodata 0x03321d */ { "mediumaquamarine", 0xff66cdaau, 0u },
    /* [ 91] 0x0485b0 -> .rodata 0x03322e */ { "mediumblue", 0xff0000cdu, 0u },
    /* [ 92] 0x0485c0 -> .rodata 0x033239 */ { "mediumorchid", 0xffba55d3u, 0u },
    /* [ 93] 0x0485d0 -> .rodata 0x033246 */ { "mediumpurple", 0xff9370dbu, 0u },
    /* [ 94] 0x0485e0 -> .rodata 0x033253 */ { "mediumseagreen", 0xff3cb371u, 0u },
    /* [ 95] 0x0485f0 -> .rodata 0x033262 */ { "mediumslateblue", 0xff7b68eeu, 0u },
    /* [ 96] 0x048600 -> .rodata 0x033272 */ { "mediumspringgreen", 0xff00fa9au, 0u },
    /* [ 97] 0x048610 -> .rodata 0x033284 */ { "mediumturquoise", 0xff48d1ccu, 0u },
    /* [ 98] 0x048620 -> .rodata 0x033294 */ { "mediumvioletred", 0xffc71585u, 0u },
    /* [ 99] 0x048630 -> .rodata 0x0332a4 */ { "midnightblue", 0xff191970u, 0u },
    /* [100] 0x048640 -> .rodata 0x0332b1 */ { "mintcream", 0xfff5fffau, 0u },
    /* [101] 0x048650 -> .rodata 0x0332bb */ { "mistyrose", 0xffffe4e1u, 0u },
    /* [102] 0x048660 -> .rodata 0x0332c5 */ { "moccasin", 0xffffe4b5u, 0u },
    /* [103] 0x048670 -> .rodata 0x0332ce */ { "navajowhite", 0xffffdeadu, 0u },
    /* [104] 0x048680 -> .rodata 0x0332da */ { "navy", 0xff000080u, 0u },
    /* [105] 0x048690 -> .rodata 0x0332df */ { "oldlace", 0xfffdf5e6u, 0u },
    /* [106] 0x0486a0 -> .rodata 0x0332e7 */ { "olive", 0xff808000u, 0u },
    /* [107] 0x0486b0 -> .rodata 0x0332ed */ { "olivedrab", 0xff6b8e23u, 0u },
    /* [108] 0x0486c0 -> .rodata 0x032ff9 */ { "orange", 0xffffa500u, 0u },
    /* [109] 0x0486d0 -> .rodata 0x0332f7 */ { "orangered", 0xffff4500u, 0u },
    /* [110] 0x0486e0 -> .rodata 0x033004 */ { "orchid", 0xffda70d6u, 0u },
    /* [111] 0x0486f0 -> .rodata 0x033301 */ { "palegoldenrod", 0xffeee8aau, 0u },
    /* [112] 0x048700 -> .rodata 0x03330f */ { "palegreen", 0xff98fb98u, 0u },
    /* [113] 0x048710 -> .rodata 0x033319 */ { "paleturquoise", 0xffafeeeeu, 0u },
    /* [114] 0x048720 -> .rodata 0x033327 */ { "palevioletred", 0xffdb7093u, 0u },
    /* [115] 0x048730 -> .rodata 0x033335 */ { "papayawhip", 0xffffefd5u, 0u },
    /* [116] 0x048740 -> .rodata 0x033340 */ { "peachpuff", 0xffffdab9u, 0u },
    /* [117] 0x048750 -> .rodata 0x03334a */ { "peru", 0xffcd853fu, 0u },
    /* [118] 0x048760 -> .rodata 0x033072 */ { "pink", 0xffffc0cbu, 0u },
    /* [119] 0x048770 -> .rodata 0x03334f */ { "plum", 0xffdda0ddu, 0u },
    /* [120] 0x048780 -> .rodata 0x033354 */ { "powderblue", 0xffb0e0e6u, 0u },
    /* [121] 0x048790 -> .rodata 0x03324c */ { "purple", 0xff800080u, 0u },
    /* [122] 0x0487a0 -> .rodata 0x03335f */ { "rosybrown", 0xffbc8f8fu, 0u },
    /* [123] 0x0487b0 -> .rodata 0x033369 */ { "royalblue", 0xff4169e1u, 0u },
    /* [124] 0x0487c0 -> .rodata 0x033373 */ { "saddlebrown", 0xff8b4513u, 0u },
    /* [125] 0x0487d0 -> .rodata 0x033017 */ { "salmon", 0xfffa8072u, 0u },
    /* [126] 0x0487e0 -> .rodata 0x03337f */ { "sandybrown", 0xfff4a460u, 0u },
    /* [127] 0x0487f0 -> .rodata 0x033022 */ { "seagreen", 0xff2e8b57u, 0u },
    /* [128] 0x048800 -> .rodata 0x03338a */ { "seashell", 0xfffff5eeu, 0u },
    /* [129] 0x048810 -> .rodata 0x033393 */ { "sienna", 0xffa0522du, 0u },
    /* [130] 0x048820 -> .rodata 0x03339a */ { "silver", 0xffc0c0c0u, 0u },
    /* [131] 0x048830 -> .rodata 0x03307b */ { "skyblue", 0xff87ceebu, 0u },
    /* [132] 0x048840 -> .rodata 0x03302f */ { "slateblue", 0xff6a5acdu, 0u },
    /* [133] 0x048850 -> .rodata 0x03303d */ { "slategray", 0xff708090u, 0u },
    /* [134] 0x048860 -> .rodata 0x03304b */ { "slategrey", 0xff708090u, 0u },
    /* [135] 0x048870 -> .rodata 0x0333a1 */ { "snow", 0xfffffafau, 0u },
    /* [136] 0x048880 -> .rodata 0x033278 */ { "springgreen", 0xff00ff7fu, 0u },
    /* [137] 0x048890 -> .rodata 0x0331eb */ { "steelblue", 0xff4682b4u, 0u },
    /* [138] 0x0488a0 -> .rodata 0x0333a6 */ { "tan", 0xffd2b48cu, 0u },
    /* [139] 0x0488b0 -> .rodata 0x0333aa */ { "teal", 0xff008080u, 0u },
    /* [140] 0x0488c0 -> .rodata 0x0333af */ { "thistle", 0xffd8bfd8u, 0u },
    /* [141] 0x0488d0 -> .rodata 0x0333b7 */ { "tomato", 0xffff6347u, 0u },
    /* [142] 0x0488e0 -> .rodata 0x03331d */ { "turquoise", 0xff40e0d0u, 0u },
    /* [143] 0x0488f0 -> .rodata 0x032f44 */ { "violet", 0xffee82eeu, 0u },
    /* [144] 0x048900 -> .rodata 0x0333be */ { "wheat", 0xfff5deb3u, 0u },
    /* [145] 0x048910 -> .rodata 0x0333c4 */ { "whitesmoke", 0xfff5f5f5u, 0u },
    /* [146] 0x048920 -> .rodata 0x0333cf */ { "yellowgreen", 0xff9acd32u, 0u },
};

} // extern "C"
