// ============================================================================
// File: serval_svg_math_and_parser.h
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (31 Exported .dynsym C Functions at 0x00b728..0x015170)
// ============================================================================
// [EN] Public C-ABI declarations for ByteDance Lynx Serval SVG XML Parser,
//      Length/Unit Resolver, ViewBox Transform Solver, 2D Affine Matrix Engine,
//      Color/Paint Parser, and Path/Polygon/Circle Bezier Geometry Builder.
// [VN] Khai báo C-ABI công khai cho Bộ phân tích XML Serval SVG, Bộ giải độ dài/đơn vị,
//      Bộ giải ma trận biến đổi ViewBox, Động cơ ma trận Affine 2D, Bộ phân tích
//      Màu sắc/Paint, và Bộ dựng hình học Bézier Đường dẫn/Đa giác/Hình tròn.
// ============================================================================

#pragma once

#include "serval_svg_types.h"
#include "serval_svg_rodata_tables.h"

extern "C" {

// --- XML Recursive-Descent Streaming Parser (0x00b728 .. 0x00ba0c) ---
using SrXMLStartElementCb = void (*)(void* user_data, const char* name, const char** atts);
using SrXMLEndElementCb   = void (*)(void* user_data, const char* name);
using SrXMLContentCb      = void (*)(void* user_data, const char* content);

void SrXMLParseContent(char* buf, SrXMLContentCb content_cb, void* user_data);
void SrXMLParseElement(char* buf, SrXMLStartElementCb start_cb, SrXMLEndElementCb end_cb, void* user_data);
int  SrXMLParseXML(char* xml_mutable, SrXMLStartElementCb start_cb, SrXMLEndElementCb end_cb,
                   SrXMLContentCb content_cb, void* user_data);

// --- SVG Units, Lengths, ViewBox & PreserveAspectRatio (0x0126cc .. 0x012c58) ---
serval::svg::SrSVGLengthUnit make_serval_length_unit(const char* unit_str);
serval::svg::SrSVGLength     make_serval_length(const char* str);
serval::svg::SrSVGSpreadMethod make_serval_spread_method(const char* str);
serval::svg::SrSVGBox        make_serval_view_box(const char* str);
serval::svg::SrSVGPreserveAspectRatio make_preserve_aspect_radio(const char* str);
serval::svg::SrSVGPreserveAspectRatio make_default_preserve_aspect_radio(void);

void calculate_view_box_transform(const serval::svg::SrSVGBox* view_port,
                                  const serval::svg::SrSVGBox* view_box,
                                  serval::svg::SrSVGPreserveAspectRatio preserve_aspect_ratio,
                                  float* xform_out6);

// --- 2D Affine Matrix Engine (xform[6] = [a, b, c, d, tx, ty]) (0x012c5c .. 0x012fe0) ---
void xform_identity(float* xform);
void xform_pre_translate(float* xform, float tx, float ty);
void xform_pre_scale(float* xform, float sx, float sy);
void xform_set_scale(float* xform, float sx, float sy);
void xform_multiply(float* dst, const float* src);
void xform_set_translation(float* xform, float tx, float ty);
void xform_pre_multiply(float* dst, const float* src);
void xform_set_rotation(float* xform, float radians);
void xform_set_skewX(float* xform, float radians);
void xform_set_skewY(float* xform, float radians);

// --- Paint, Color & Length-to-Float Conversion (0x012fe4 .. 0x013698) ---
serval::svg::SrSVGPaint* make_serval_paint(const char* str);
serval::svg::SrSVGColor  make_serval_color(const char* str);
void                     release_serval_paint(serval::svg::SrSVGPaint* paint);
float                    convert_serval_length_to_float(const serval::svg::SrSVGLength* length,
                                                        const serval::svg::SrSVGRenderContext* ctx,
                                                        int32_t type);

// --- SVG Path, Polygon, Circle Bezier & Stroke Style (0x01369c .. 0x015170) ---
serval::svg::SrSVGPathData*        make_serval_path(const char* d_str);
void                               release_serval_polygon_path(serval::svg::SrSVGPolygonPathData* poly);
serval::svg::SrSVGPolygonPathData* make_serval_polygon(const char* points_str);
void                               release_serval_path(serval::svg::SrSVGPathData* path);
void                               add_circle_to_path(serval::svg::SrSVGPathData* path, float cx, float cy, float r);
serval::svg::SrSVGStrokeCap        resolve_stroke_line_cap(const char* str);
serval::svg::SrSVGStrokeJoin       resolve_stroke_line_join(const char* str);

} // extern "C"

namespace serval {
namespace svg {

// [EN] Internal number lexer reconstructed from 0x015174..0x015320
// [VN] Bộ tách số nội bộ được tái tạo từ 0x015174..0x015320
float parse_serval_svg_number(const char** cursor);

// [EN] CSS/SVG transform="..." attribute parser (matrix, translate, scale, rotate, skewX, skewY)
//      reconstructed from 0x011a40..0x012080.
// [VN] Bộ phân tích thuộc tính transform="..." (matrix, translate, scale, rotate, skewX, skewY)
//      được tái tạo từ 0x011a40..0x012080.
void parse_serval_transform_attribute(const char* transform_str, float* xform_out6, float dpi);

} // namespace svg
} // namespace serval
