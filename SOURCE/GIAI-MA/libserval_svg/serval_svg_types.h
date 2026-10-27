// ============================================================================
// File: serval_svg_types.h
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Architecture: AArch64 (ARM64-v8a) - ByteDance Lynx Serval SVG Engine
// Calling Convention: AAPCS64 (LP64)
// Classification: OBSERVED (Direct Binary Disassembly + .dynsym + .rodata + .data)
// ============================================================================
// [EN] Clean-room C++17 ABI data structures, enumerations, and class layouts
//      reconstructed from libserval_svg.so (.text 0x00aaf0..0x032ae0,
//      .rodata 0x032ae0..0x036121, .data.rel.ro 0x044da8, .data 0x048000).
// [VN] Các cấu trúc dữ liệu ABI C++17 clean-room, enum và bố cục lớp được tái tạo
//      từ libserval_svg.so (.text 0x00aaf0..0x032ae0, .rodata 0x032ae0..0x036121,
//      .data.rel.ro 0x044da8, .data 0x048000).
// ============================================================================

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace serval {
namespace svg {

// ============================================================================
// 1. SVG Length & Coordinate Units (Đơn vị độ dài và tọa độ SVG)
//    OBSERVED at make_serval_length_unit (0x0126cc), make_serval_length (0x01271c),
//    and convert_serval_length_to_float (0x013548..0x013698).
// ============================================================================
enum SrSVGLengthUnit : uint32_t {
    SR_SVG_UNITS_UNKNOWN    = 0,  // [EN] Unset/unknown / [VN] Chưa xác định
    SR_SVG_UNITS_NUMBER     = 1,  // [EN] Unitless number / [VN] Số không đơn vị (0x100000000)
    SR_SVG_UNITS_PERCENTAGE = 2,  // [EN] Percentage '%' (.rodata 0x034ea8) / [VN] Phần trăm '%' (0x200000000)
    SR_SVG_UNITS_EM         = 3,  // [EN] Font-relative 'em' / [VN] Đơn vị tương đối theo font 'em'
    SR_SVG_UNITS_EX         = 4,  // [EN] x-height 'ex' (* 0.52f = 0x3f051eb8) / [VN] Chiều cao chữ x 'ex'
    SR_SVG_UNITS_PX         = 5,  // [EN] Pixels 'px' (.rodata 0x0333db) / [VN] Điểm ảnh 'px' (0x500000000)
    SR_SVG_UNITS_CM         = 6,  // [EN] Centimeters 'cm' (dpi / 2.54f = 0x40228f5c) / [VN] Centimet 'cm'
    SR_SVG_UNITS_MM         = 7,  // [EN] Millimeters 'mm' (dpi / 25.4f = 0x41cb3333) / [VN] Milimet 'mm'
    SR_SVG_UNITS_IN         = 8,  // [EN] Inches 'in' (* dpi) / [VN] Inch 'in'
    SR_SVG_UNITS_PT         = 9,  // [EN] Points 'pt' (dpi / 72.0f = 0x42900000) / [VN] Point 'pt'
    SR_SVG_UNITS_PC         = 10, // [EN] Picas 'pc' (dpi / 6.0f = 0x40c00000) / [VN] Pica 'pc'
};

// [EN] Axis / dimension context passed in w2 to convert_serval_length_to_float (0x013548).
// [VN] Ngữ cảnh trục / chiều truyền qua thanh ghi w2 vào convert_serval_length_to_float (0x013548).
enum SrSVGLengthType : int32_t {
    SR_SVG_LENGTH_TYPE_HORIZONTAL = 0, // [EN] Uses view_box.width ([ctx + 0x30]) / [VN] Dùng chiều rộng viewBox
    SR_SVG_LENGTH_TYPE_VERTICAL   = 1, // [EN] Uses view_box.height ([ctx + 0x34]) / [VN] Dùng chiều cao viewBox
    SR_SVG_LENGTH_TYPE_OTHER      = 2, // [EN] Uses sqrt(w^2 + h^2) / sqrt(2) (0x01366c) / [VN] Đường chéo chuẩn hóa
    SR_SVG_LENGTH_TYPE_ABSOLUTE   = 3, // [EN] Multiplier 1.0f (0x0135a4) / [VN] Hệ số nhân 1.0f
};

// [EN] 8-byte SVG Length struct returned packed in x0 (low 32 bits = float value, high 32 bits = unit).
//      Verified at make_serval_length (0x01278c: fmov w9, s8; orr x0, x8, x9) and
//      convert_serval_length_to_float (0x013548: ldr w8, [x0, #4]; ldr s0, [x0]).
// [VN] Cấu trúc độ dài SVG 8 byte trả về đóng gói trong x0 (32 bit thấp = float value, 32 bit cao = unit).
struct SrSVGLength {
    float           value; // +0x00: [EN] Numeric length value / [VN] Giá trị số
    SrSVGLengthUnit unit;  // +0x04: [EN] Unit enum (0..10) / [VN] Mã đơn vị (0..10)

    uint64_t pack_u64() const noexcept {
        uint32_t v_bits = 0;
        std::memcpy(&v_bits, &value, sizeof(uint32_t));
        return (static_cast<uint64_t>(unit) << 32) | static_cast<uint64_t>(v_bits);
    }

    static SrSVGLength unpack_u64(uint64_t packed) noexcept {
        SrSVGLength out{};
        uint32_t v_bits = static_cast<uint32_t>(packed & 0xFFFFFFFFu);
        std::memcpy(&out.value, &v_bits, sizeof(float));
        out.unit = static_cast<SrSVGLengthUnit>((packed >> 32) & 0xFFFFFFFFu);
        return out;
    }
};
static_assert(sizeof(SrSVGLength) == 8, "SrSVGLength must be 8 bytes");

// ============================================================================
// 2. ViewBox & PreserveAspectRatio (Khung nhìn và Tỷ lệ khung hình SVG)
//    OBSERVED at make_serval_view_box (0x0127f8), make_preserve_aspect_radio (0x0128b0),
//    make_default_preserve_aspect_radio (0x0129bc), calculate_view_box_transform (0x0129dc).
// ============================================================================
struct SrSVGBox {
    float left;   // +0x00 (s0)
    float top;    // +0x04 (s1)
    float width;  // +0x08 (s2)
    float height; // +0x0c (s3)
};
static_assert(sizeof(SrSVGBox) == 16, "SrSVGBox must be 16 bytes");

// [EN] Alignment enum along X or Y axis (make_preserve_aspect_radio @ 0x0128b0..0x0129b8).
// [VN] Enum căn chỉnh theo trục X hoặc Y (make_preserve_aspect_radio @ 0x0128b0..0x0129b8).
enum SrSVGAlign : int32_t {
    SR_SVG_ALIGN_NONE = 0, // "none" (.rodata 0x0333f3)
    SR_SVG_ALIGN_MIN  = 1, // "xMin" (.rodata 0x0333f8) / "YMin" (.rodata 0x033407)
    SR_SVG_ALIGN_MID  = 2, // "xMid" (.rodata 0x0333fd) / "YMid" (.rodata 0x03340c)
    SR_SVG_ALIGN_MAX  = 3, // "xMax" (.rodata 0x033402) / "YMax" (.rodata 0x033411)
};

// [EN] Meet or Slice scale mode (make_preserve_aspect_radio @ 0x012988..0x0129a0).
// [VN] Chế độ co giãn Meet hoặc Slice (make_preserve_aspect_radio @ 0x012988..0x0129a0).
enum SrSVGScale : int32_t {
    SR_SVG_SCALE_NONE  = 0, // when align is "none" -> non-uniform scale (sx, sy)
    SR_SVG_SCALE_MEET  = 1, // default "meet" -> min(sx, sy) (0x012ab8: fcmp s6, s3; fcsel s3, s6, s3, mi)
    SR_SVG_SCALE_SLICE = 2, // "slice" (.rodata 0x033416) -> max(sx, sy) (0x012ac4: fcmp s6, s3; fcsel s3, s6, s3, gt)
};

// [EN] 12-byte PreserveAspectRatio struct returned in (x0, x1) per AAPCS64 HFA/struct return rules:
//      x0 = align_x | (uint64_t(align_y) << 32), w1 = scale.
//      Verified at 0x00adc8..0x00add4 (bfi x2, x3, #32, #32; mov w3, w4) and 0x0129a4..0x0129b8.
// [VN] Cấu trúc PreserveAspectRatio 12 byte trả về trong (x0, x1) theo chuẩn AAPCS64:
//      x0 = align_x | (uint64_t(align_y) << 32), w1 = scale.
struct SrSVGPreserveAspectRatio {
    int32_t align_x; // +0x00: 0=none, 1=xMin, 2=xMid, 3=xMax
    int32_t align_y; // +0x04: 0=none, 1=YMin, 2=YMid, 3=YMax
    int32_t scale;   // +0x08: 0=none, 1=meet, 2=slice
};
static_assert(sizeof(SrSVGPreserveAspectRatio) == 12, "SrSVGPreserveAspectRatio must be 12 bytes");

// ============================================================================
// 3. Paint, Color, Gradient, and Stroke Enumerations (Màu sắc, Tô vẽ và Nét vẽ)
//    OBSERVED at make_serval_spread_method (0x0127a8), make_serval_paint (0x012fe4),
//    make_serval_color (0x013108), resolve_stroke_line_cap (0x0150d4),
//    resolve_stroke_line_join (0x015124).
// ============================================================================
enum SrSVGSpreadMethod : int32_t {
    SR_SVG_SPREAD_PAD     = 0, // default "pad"
    SR_SVG_SPREAD_REFLECT = 1, // "reflect" (.rodata 0x0333de)
    SR_SVG_SPREAD_REPEAT  = 2, // "repeat"  (.rodata 0x0333e6)
};

enum SrSVGStrokeCap : int32_t {
    SR_SVG_CAP_BUTT   = 0, // default "butt"
    SR_SVG_CAP_ROUND  = 1, // "round"  (.rodata 0x033438) -> mov w0, #1 at 0x015114
    SR_SVG_CAP_SQUARE = 2, // "square" (.rodata 0x03343e) -> lsl w0, w8, #1 at 0x01510c
};

enum SrSVGStrokeJoin : int32_t {
    SR_SVG_JOIN_MITER = 0, // default "miter"
    SR_SVG_JOIN_ROUND = 1, // "round" (.rodata 0x033438) -> mov w0, #1 at 0x015164
    SR_SVG_JOIN_BEVEL = 2, // "bevel" (.rodata 0x033445) -> lsl w0, w8, #1 at 0x01515c
};

enum SrSVGFillRule : int32_t {
    SR_SVG_FILL_RULE_WINDING  = 0, // default "nonzero"
    SR_SVG_FILL_RULE_EVEN_ODD = 1, // "evenodd" (.rodata 0x032def)
};

enum SrSVGUnits : int32_t {
    SR_SVG_OBB_TYPE_USER_SPACE_ON_USE   = 0, // "userSpaceOnUse" (.rodata 0x03364d)
    SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX = 1, // "objectBoundingBox" (.rodata 0x03367c)
};

enum SrSVGPaintType : int32_t {
    SR_SVG_PAINT_NONE  = 0, // "none" (.rodata 0x0333f3)
    SR_SVG_PAINT_COLOR = 1, // solid color (calls make_serval_color @ 0x013024)
    SR_SVG_PAINT_IRI   = 2, // "url(#id)" (.rodata 0x03341c, strchr '(' & ')')
};

// [EN] 8-byte SVG Color struct returned packed in x0 by make_serval_color (0x013108):
//      low 32 bits (w9) = type (0 = currentColor, 1 = normal ARGB color),
//      high 32 bits (w8) = 0xAARRGGBB color value.
//      Verified at 0x013250..0x013288 (lsl x8, x8, #32; mov w9, #1; orr x0, x9, x8).
// [VN] Cấu trúc màu SVG 8 byte trả về đóng gói trong x0 bởi make_serval_color (0x013108).
struct SrSVGColor {
    uint32_t type;  // +0x00: 0 = currentColor ("currentColor" @ 0x033421), 1 = normal ARGB
    uint32_t color; // +0x04: ARGB8888 (e.g. 0xFFFF0000 for red, fallback 0xFF808080 @ 0x013494)

    uint64_t pack_u64() const noexcept {
        return (static_cast<uint64_t>(color) << 32) | static_cast<uint64_t>(type);
    }

    static SrSVGColor unpack_u64(uint64_t packed) noexcept {
        return SrSVGColor{
            static_cast<uint32_t>(packed & 0xFFFFFFFFu),
            static_cast<uint32_t>((packed >> 32) & 0xFFFFFFFFu)
        };
    }
};
static_assert(sizeof(SrSVGColor) == 8, "SrSVGColor must be 8 bytes");

// [EN] 16-byte Named Color entry in sr_svg__colors (.data 0x048000..0x048930, 147 entries).
//      Verified at 0x013478..0x0134a4: ldr x0, [x22, x20]; ldr w8, [x8, #8]; add x20, x20, #0x10; cmp x20, #0x930.
// [VN] Mục màu định danh 16 byte trong bảng sr_svg__colors (.data 0x048000..0x048930, 147 mục).
struct SrSVGNamedColor {
    const char* name;     // +0x00: Pointer to color name in .rodata
    uint32_t    rgb;      // +0x08: ARGB8888 value (0xFFRRGGBB)
    uint32_t    reserved; // +0x0c: Alignment padding (0)
};
static_assert(sizeof(SrSVGNamedColor) == 16, "SrSVGNamedColor must be 16 bytes");

// [EN] 16-byte Paint descriptor allocated via malloc(0x10) in make_serval_paint (0x012fe4)
//      and freed in release_serval_paint (0x013510).
// [VN] Cấu trúc mô tả Paint 16 byte được cấp phát qua malloc(0x10) trong make_serval_paint (0x012fe4).
struct SrSVGPaint {
    SrSVGPaintType type;     // +0x00: 0 = NONE, 1 = COLOR, 2 = IRI
    uint32_t       reserved; // +0x04: Padding
    union {
        SrSVGColor color;    // +0x08: When type == SR_SVG_PAINT_COLOR (stored as 64-bit packed at [x0, #8])
        char*      iri;      // +0x08: When type == SR_SVG_PAINT_IRI (heap string freed if type == 2 @ 0x013528)
    };
};
static_assert(sizeof(SrSVGPaint) == 16, "SrSVGPaint must be 16 bytes");

// [EN] Gradient stop model passed to makeStopModel(FJF)Lcom/lynx/serval/svg/model/StopModel;
// [VN] Mô hình điểm dừng gradient truyền vào makeStopModel.
struct SrSVGStop {
    SrSVGLength offset;       // +0x00: Stop offset (number or percentage)
    SrSVGColor  stop_color;   // +0x08: Stop ARGB color
    float       stop_opacity; // +0x10: Stop opacity [0.0..1.0]
};

// ============================================================================
// 4. Path & Polygon Geometry Structures (Cấu trúc Hình học Đường dẫn & Đa giác)
//    OBSERVED at make_serval_path (0x01369c), release_serval_path (0x014cac),
//    make_serval_polygon (0x014b24), release_serval_polygon_path (0x014af0),
//    and add_circle_to_path (0x014ce8).
// ============================================================================
enum SrSVGPathOp : uint8_t {
    SPO_MOVE_TO   = 0, // 'M'/'m': consumes 2 floats (x, y)
    SPO_LINE_TO   = 1, // 'L'/'l'/'H'/'h'/'V'/'v': consumes 2 floats (x, y)
    SPO_CUBIC_BEZ = 2, // 'C'/'c'/'S'/'s'/'A'/'a': consumes 6 floats (x1, y1, x2, y2, x, y)
    SPO_QUAD_BEZ  = 3, // 'Q'/'q'/'T'/'t': consumes 4 floats (x1, y1, x, y)
    SPO_CLOSE     = 4, // 'Z'/'z': consumes 0 floats (or 2 floats in Serval path stream)
};

// [EN] 48-byte Path Data structure allocated by make_serval_path (0x0136c4: mov w0, #0x30; bl malloc)
//      and mutated by add_circle_to_path (0x014ce8) and released by release_serval_path (0x014cac).
// [VN] Cấu trúc dữ liệu Path 48 byte được cấp phát bởi make_serval_path (malloc(0x30)).
struct SrSVGPathData {
    uint8_t* ops;        // +0x00: Dynamic array of SrSVGPathOp bytes
    uint64_t n_ops;      // +0x08: Number of path operations ([x19, #8])
    uint64_t cap_ops;    // +0x10: Capacity of ops array ([x19, #0x10])
    float*   args;       // +0x18: Dynamic array of float coordinates ([x19, #0x18])
    uint64_t n_args;     // +0x20: Number of float coordinates ([x19, #0x20])
    uint64_t cap_args;   // +0x28: Capacity of args array ([x19, #0x28])
};
static_assert(sizeof(SrSVGPathData) == 48, "SrSVGPathData must be 48 bytes");

// [EN] 16-byte Polygon/Polyline Path Data structure allocated by make_serval_polygon (0x014b48: mov w0, #0x10)
//      and freed by release_serval_polygon_path (0x014af0).
// [VN] Cấu trúc dữ liệu Đa giác/Đường gấp khúc 16 byte được cấp phát bởi make_serval_polygon (malloc(0x10)).
struct SrSVGPolygonPathData {
    float*   points;     // +0x00: Interleaved (x, y) float array (2 * n_points floats)
    uint32_t n_points;   // +0x08: Number of (x, y) vertices ([x19, #8])
    uint32_t cap_points; // +0x0c: Vertex capacity ([x19, #0xc])
};
static_assert(sizeof(SrSVGPolygonPathData) == 16, "SrSVGPolygonPathData must be 16 bytes");

// ============================================================================
// 5. XML Parser & DOM Structures (Cấu trúc Bộ phân tích XML & Cây DOM)
//    OBSERVED at 0x00aed8..0x00ba0c (SrXMLParseContent, SrXMLParseElement, SrXMLParseXML).
// ============================================================================
struct SrXMLAttribute {
    char* name;  // +0x00: Attribute name string
    char* value; // +0x08: Attribute value string
};
static_assert(sizeof(SrXMLAttribute) == 16, "SrXMLAttribute must be 16 bytes");

// [EN] 40-byte XML DOM Element node allocated in SrXMLDOMBuilder (0x00b1a8: mov w0, #0x28; bl malloc)
//      and freed recursively at 0x00aed8..0x00af68.
// [VN] Nút phần tử XML DOM 40 byte được cấp phát trong SrXMLDOMBuilder (malloc(0x28)).
struct SrXMLElement {
    char*           name;       // +0x00: Tag name or text content ([x19, #0x00])
    SrXMLElement*   first_child;// +0x08: First child element ([x19, #0x08])
    SrXMLElement*   next_sibling;// +0x10: Next sibling element ([x19, #0x10])
    SrXMLAttribute* attrs;      // +0x18: Array of attributes ([x19, #0x18])
    uint16_t        n_attrs;    // +0x20: Number of attributes ([x19, #0x20])
    uint8_t         is_text;    // +0x22: 0 = element tag, 1 = text content ([x19, #0x22])
    uint8_t         padding[5]; // +0x23..0x27
};
static_assert(sizeof(SrXMLElement) == 40, "SrXMLElement must be 40 bytes");

// ============================================================================
// 6. Render Context & Abstract Canvas Interface (Ngữ cảnh Render & Giao diện Canvas)
//    OBSERVED at convert_serval_length_to_float (0x013548) and SrAndroidCanvas (0x0156c4).
// ============================================================================
struct SrSVGRenderContext {
    void*    canvas;      // +0x00: Pointer to SrCanvas
    float    dpi;         // +0x08: Target display DPI (default 96.0f, used at 0x0135ec..0x013638)
    float    font_size;   // +0x0c: Current font size in px (default 14.0f, used at 0x0135bc..0x0135cc)
    uint8_t  reserved[24];// +0x10..0x27: Internal state pointers
    SrSVGBox view_box;    // +0x28: Current active viewBox {left(+0x28), top(+0x2c), width(+0x30), height(+0x34)}
    float    xform[6];    // +0x38: Current 2D affine matrix [a, b, c, d, tx, ty]
};

} // namespace svg
} // namespace serval
