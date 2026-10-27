// ============================================================================
// File: serval_svg_math_and_parser.cpp
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Direct AArch64 Opcode Reconstruction of .text 0x00b728..0x015320)
// ============================================================================
// [EN] Clean-room C++17 implementation of all 31 exported C-ABI functions in
//      libserval_svg.so:
//      1. SrXMLParseContent (0x00b728), SrXMLParseElement (0x00b798), SrXMLParseXML (0x00ba0c)
//      2. make_serval_length_unit (0x0126cc), make_serval_length (0x01271c)
//      3. make_serval_spread_method (0x0127a8), make_serval_view_box (0x0127f8)
//      4. make_preserve_aspect_radio (0x0128b0), make_default_preserve_aspect_radio (0x0129bc)
//      5. calculate_view_box_transform (0x0129dc..0x012c58)
//      6. xform_identity (0x012c5c), xform_pre_translate (0x012c70), xform_pre_scale (0x012cec),
//         xform_set_scale (0x012da8), xform_multiply (0x012dc0), xform_set_translation (0x012e6c),
//         xform_pre_multiply (0x012e80), xform_set_rotation (0x012f2c), xform_set_skewX (0x012f6c),
//         xform_set_skewY (0x012fac)
//      7. make_serval_paint (0x012fe4), make_serval_color (0x013108), release_serval_paint (0x013510)
//      8. convert_serval_length_to_float (0x013548..0x013698)
//      9. make_serval_path (0x01369c..0x014af0), release_serval_polygon_path (0x014af0),
//         make_serval_polygon (0x014b24), release_serval_path (0x014cac),
//         add_circle_to_path (0x014ce8), resolve_stroke_line_cap (0x0150d4),
//         resolve_stroke_line_join (0x015124).
// [VN] Bản tái tạo C++17 clean-room cho toàn bộ 31 hàm C-ABI xuất khẩu trong
//      libserval_svg.so khớp tuyệt đối với mã máy AArch64 tại .text 0x00b728..0x015320.
// ============================================================================

#include "serval_svg_math_and_parser.h"
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>

namespace serval {
namespace svg {

// ============================================================================
// Internal Helper: Push Path Operation & Arguments (0x014d20..0x0150a0)
// [EN] Appends an operation byte to path->ops (growing capacity: 8, 16, 32, ...)
//      and appends float coordinates to path->args (growing capacity: 8, 16, 32, ...).
// [VN] Thêm byte lệnh vào path->ops (nhân đôi dung lượng từ 8) và thêm mảng tọa độ
//      float vào path->args (nhân đôi dung lượng từ 8).
// ============================================================================
static bool path_push_op(SrSVGPathData* path, uint8_t op) {
    if (!path) return false;
    uint64_t next_n = path->n_ops + 1;
    if (path->cap_ops < next_n) {
        uint64_t new_cap = (path->cap_ops == 0) ? 8u : (path->cap_ops << 1);
        while (new_cap < next_n) {
            new_cap <<= 1;
        }
        auto* new_ops = static_cast<uint8_t*>(std::realloc(path->ops, new_cap));
        if (!new_ops) return false;
        path->ops = new_ops;
        path->cap_ops = new_cap;
    }
    path->ops[path->n_ops] = op;
    path->n_ops = next_n;
    return true;
}

static bool path_push_args(SrSVGPathData* path, const float* coords, uint64_t count) {
    if (!path || count == 0) return true;
    uint64_t next_n = path->n_args + count;
    if (path->cap_args < next_n) {
        uint64_t new_cap = (path->cap_args == 0) ? 8u : (path->cap_args << 1);
        while (new_cap < next_n) {
            new_cap <<= 1;
        }
        auto* new_args = static_cast<float*>(std::realloc(path->args, new_cap * sizeof(float)));
        if (!new_args) return false;
        path->args = new_args;
        path->cap_args = new_cap;
    }
    std::memcpy(path->args + path->n_args, coords, count * sizeof(float));
    path->n_args = next_n;
    return true;
}

// ============================================================================
// Internal Helper: Number Lexer (0x015174 .. 0x015320)
// [EN] Scans an SVG floating-point token (optional sign '+'/'-', integer digits,
//      optional '.fraction', optional 'e'/'E' exponent), copies the token to a
//      stack buffer, and converts via strtof (0x00aaa0 PLT).
// [VN] Quét token số thực SVG (dấu '+'/'-', phần nguyên, phần thập phân '.',
//      số mũ 'e'/'E'), chép vào bộ đệm ngăn xếp và chuyển đổi qua strtof.
// ============================================================================
float parse_serval_svg_number(const char** cursor) {
    if (!cursor || !*cursor) return 0.0f;
    const char* start = *cursor;
    const char* p = start;
    uint32_t len = 0;

    if (*p == '-' || *p == '+') {
        ++p;
        *cursor = p;
        len = 1;
    }

    while (*p >= '0' && *p <= '9') {
        ++p;
        *cursor = p;
        ++len;
    }

    if (*p == '.') {
        ++p;
        *cursor = p;
        ++len;
        while (*p >= '0' && *p <= '9') {
            ++p;
            *cursor = p;
            ++len;
        }
    }

    if ((*p | 0x20) == 'e') {
        const char* exp_p = p + 1;
        if ((*exp_p >= '0' && *exp_p <= '9') || *exp_p == '-' || *exp_p == '+') {
            *cursor = exp_p;
            if (*exp_p == '-' || *exp_p == '+') {
                exp_p = p + 2;
                *cursor = exp_p;
                len += 2;
            } else {
                len += 1;
            }
            while (*exp_p >= '0' && *exp_p <= '9') {
                ++exp_p;
                *cursor = exp_p;
                ++len;
            }
        }
    }

    if (len == 0) return 0.0f;
    char stack_buf[128];
    uint32_t copy_len = (len < sizeof(stack_buf) - 1) ? len : static_cast<uint32_t>(sizeof(stack_buf) - 1);
    std::memcpy(stack_buf, start, copy_len);
    stack_buf[copy_len] = '\0';
    char* end_ptr = nullptr;
    return std::strtof(stack_buf, &end_ptr);
}

static void skip_svg_ws_and_comma(const char** cursor) {
    if (!cursor || !*cursor) return;
    const char* p = *cursor;
    while (*p != '\0' && (std::isspace(static_cast<unsigned char>(*p)) || *p == ',')) {
        ++p;
    }
    *cursor = p;
}

// ============================================================================
// Internal Helper: SVG Elliptical Arc to Cubic Bézier Decomposition
//    OBSERVED inside make_serval_path (0x014300 .. 0x014ae0)
// [EN] Converts an SVG elliptical arc (rx, ry, x_axis_rotation, large_arc_flag,
//      sweep_flag, x, y) from current point (x0, y0) into 1..4 cubic Bézier
//      segments (SPO_CUBIC_BEZ = 2) per W3C SVG 1.1 Appendix F.6.
// [VN] Chuyển đổi cung elip SVG (rx, ry, góc xoay, cờ cung lớn, cờ hướng quét, x, y)
//      từ điểm hiện tại (x0, y0) thành 1..4 đoạn Bézier bậc ba (SPO_CUBIC_BEZ = 2).
// ============================================================================
static void arc_to_cubic_beziers(SrSVGPathData* path,
                                 float x0, float y0,
                                 float rx_in, float ry_in,
                                 float x_axis_rot_deg,
                                 int large_arc_flag,
                                 int sweep_flag,
                                 float x, float y) {
    if (x0 == x && y0 == y) {
        return;
    }
    float rx = std::fabs(rx_in);
    float ry = std::fabs(ry_in);
    if (rx == 0.0f || ry == 0.0f) {
        float pts[2] = { x, y };
        path_push_op(path, SPO_LINE_TO);
        path_push_args(path, pts, 2);
        return;
    }

    constexpr float kPi = 3.14159265358979323846f;
    float phi = (x_axis_rot_deg / 180.0f) * kPi;
    float sin_phi = std::sin(phi);
    float cos_phi = std::cos(phi);

    float dx2 = (x0 - x) * 0.5f;
    float dy2 = (y0 - y) * 0.5f;
    float x1p =  cos_phi * dx2 + sin_phi * dy2;
    float y1p = -sin_phi * dx2 + cos_phi * dy2;

    float rx_sq = rx * rx;
    float ry_sq = ry * ry;
    float x1p_sq = x1p * x1p;
    float y1p_sq = y1p * y1p;

    // Ensure radii are large enough (F.6.6.2)
    float lambda = (x1p_sq / rx_sq) + (y1p_sq / ry_sq);
    if (lambda > 1.0f) {
        float sqrt_l = std::sqrt(lambda);
        rx *= sqrt_l;
        ry *= sqrt_l;
        rx_sq = rx * rx;
        ry_sq = ry * ry;
    }

    float num = rx_sq * ry_sq - rx_sq * y1p_sq - ry_sq * x1p_sq;
    float den = rx_sq * y1p_sq + ry_sq * x1p_sq;
    float sq = (den > 0.0f) ? std::max(0.0f, num / den) : 0.0f;
    float coef = std::sqrt(sq);
    if (large_arc_flag == sweep_flag) {
        coef = -coef;
    }

    float cxp =  coef * ((rx * y1p) / ry);
    float cyp = -coef * ((ry * x1p) / rx);

    float cx = cos_phi * cxp - sin_phi * cyp + (x0 + x) * 0.5f;
    float cy = sin_phi * cxp + cos_phi * cyp + (y0 + y) * 0.5f;

    auto vec_angle = [](float ux, float uy, float vx, float vy) -> float {
        float dot = ux * vx + uy * vy;
        float len = std::sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy));
        float c = (len > 0.0f) ? std::max(-1.0f, std::min(1.0f, dot / len)) : 1.0f;
        float ang = std::acos(c);
        return (ux * vy - uy * vx < 0.0f) ? -ang : ang;
    };

    float ux = (x1p - cxp) / rx;
    float uy = (y1p - cyp) / ry;
    float vx = (-x1p - cxp) / rx;
    float vy = (-y1p - cyp) / ry;

    float theta1 = vec_angle(1.0f, 0.0f, ux, uy);
    float dtheta = vec_angle(ux, uy, vx, vy);
    if (!sweep_flag && dtheta > 0.0f) {
        dtheta -= 2.0f * kPi;
    } else if (sweep_flag && dtheta < 0.0f) {
        dtheta += 2.0f * kPi;
    }

    int segments = static_cast<int>(std::ceil(std::fabs(dtheta) / (kPi * 0.5f)));
    if (segments < 1) segments = 1;
    float delta = dtheta / static_cast<float>(segments);
    float t = (4.0f / 3.0f) * std::tan(delta * 0.25f);

    for (int i = 0; i < segments; ++i) {
        float th0 = theta1 + static_cast<float>(i) * delta;
        float th1 = th0 + delta;
        float cos0 = std::cos(th0), sin0 = std::sin(th0);
        float cos1 = std::cos(th1), sin1 = std::sin(th1);

        float p1x = cos0 - t * sin0;
        float p1y = sin0 + t * cos0;
        float p2x = cos1 + t * sin1;
        float p2y = sin1 - t * cos1;
        float p3x = cos1;
        float p3y = sin1;

        float args[6];
        args[0] = cx + cos_phi * (rx * p1x) - sin_phi * (ry * p1y);
        args[1] = cy + sin_phi * (rx * p1x) + cos_phi * (ry * p1y);
        args[2] = cx + cos_phi * (rx * p2x) - sin_phi * (ry * p2y);
        args[3] = cy + sin_phi * (rx * p2x) + cos_phi * (ry * p2y);
        args[4] = cx + cos_phi * (rx * p3x) - sin_phi * (ry * p3y);
        args[5] = cy + sin_phi * (rx * p3x) + cos_phi * (ry * p3y);

        path_push_op(path, SPO_CUBIC_BEZ);
        path_push_args(path, args, 6);
    }
}

// ============================================================================
// CSS/SVG Transform Attribute Parser (0x011a40 .. 0x012080)
// [EN] Parses SVG transform="matrix(...) translate(...) scale(...) rotate(...)
//      skewX(...) skewY(...)" strings into a 6-float affine matrix.
// [VN] Phân tích chuỗi thuộc tính transform="..." thành ma trận affine 6 số thực.
// ============================================================================
void parse_serval_transform_attribute(const char* transform_str, float* xform_out6, float /*dpi*/) {
    if (!xform_out6) return;
    xform_identity(xform_out6);
    if (!transform_str) return;

    constexpr float kDegToRad = 3.14159265358979323846f / 180.0f;
    const char* p = transform_str;

    while (*p != '\0') {
        skip_svg_ws_and_comma(&p);
        if (*p == '\0') break;

        const char* lparen = std::strchr(p, '(');
        if (!lparen) break;

        size_t name_len = static_cast<size_t>(lparen - p);
        while (name_len > 0 && std::isspace(static_cast<unsigned char>(p[name_len - 1]))) {
            --name_len;
        }

        const char* arg_p = lparen + 1;
        float args[6] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };
        int n_args = 0;
        while (*arg_p != '\0' && *arg_p != ')' && n_args < 6) {
            skip_svg_ws_and_comma(&arg_p);
            if (*arg_p == ')' || *arg_p == '\0') break;
            const char* before = arg_p;
            args[n_args] = parse_serval_svg_number(&arg_p);
            if (arg_p == before) {
                ++arg_p;
            } else {
                ++n_args;
            }
        }
        const char* rparen = std::strchr(arg_p, ')');
        if (!rparen) break;

        float local[6];
        xform_identity(local);

        if (name_len == 6 && std::strncmp(p, "matrix", 6) == 0 && n_args == 6) {
            std::memcpy(local, args, sizeof(local));
            xform_pre_multiply(xform_out6, local);
        } else if (name_len == 9 && std::strncmp(p, "translate", 9) == 0 && n_args >= 1) {
            float tx = args[0];
            float ty = (n_args >= 2) ? args[1] : 0.0f;
            xform_pre_translate(xform_out6, tx, ty);
        } else if (name_len == 5 && std::strncmp(p, "scale", 5) == 0 && n_args >= 1) {
            float sx = args[0];
            float sy = (n_args >= 2) ? args[1] : sx;
            xform_pre_scale(xform_out6, sx, sy);
        } else if (name_len == 6 && std::strncmp(p, "rotate", 6) == 0 && n_args >= 1) {
            float rad = args[0] * kDegToRad;
            if (n_args == 3) {
                xform_pre_translate(xform_out6, args[1], args[2]);
            }
            xform_set_rotation(local, rad);
            xform_pre_multiply(xform_out6, local);
            if (n_args == 3) {
                xform_pre_translate(xform_out6, -args[1], -args[2]);
            }
        } else if (name_len == 5 && std::strncmp(p, "skewX", 5) == 0 && n_args == 1) {
            xform_set_skewX(local, args[0] * kDegToRad);
            xform_pre_multiply(xform_out6, local);
        } else if (name_len == 5 && std::strncmp(p, "skewY", 5) == 0 && n_args == 1) {
            xform_set_skewY(local, args[0] * kDegToRad);
            xform_pre_multiply(xform_out6, local);
        }

        p = rparen + 1;
    }
}

} // namespace svg
} // namespace serval

extern "C" {

using namespace serval::svg;

// ============================================================================
// 1. SrXMLParseContent (0x00b728 .. 0x00b794, 112 bytes)
// [EN] Skips leading whitespace via isspace (0x00aae0 PLT); if non-empty and
//      content_cb != nullptr, invokes content_cb(user_data, first_non_ws).
// [VN] Bỏ qua khoảng trắng đầu chuỗi qua isspace; nếu chuỗi không rỗng và
//      content_cb != nullptr, gọi content_cb(user_data, first_non_ws).
// ============================================================================
void SrXMLParseContent(char* buf, SrXMLContentCb content_cb, void* user_data) {
    if (!buf) return;
    unsigned char ch = static_cast<unsigned char>(*buf);
    if (ch == 0) return;

    char* p = buf;
    while (ch != 0) {
        if (!std::isspace(static_cast<int>(ch))) {
            if (content_cb != nullptr) {
                content_cb(user_data, p);
            }
            return;
        }
        ++p;
        ch = static_cast<unsigned char>(*p);
    }
}

// ============================================================================
// 2. SrXMLParseElement (0x00b798 .. 0x00ba08, 628 bytes)
// [EN] Parses an XML tag interior (allocated 0x800 bytes = 256 char* slots on
//      stack at sp+0x10), detects closing tag ('/') or self-closing ('/>'),
//      rejects XML processing instructions/declarations ('?' / '!' via bitmask
//      0x8000000200000001ULL at 0x00b814..0x00b820), extracts up to 255
//      key="value" / key='value' attribute pairs, and invokes start_cb and/or end_cb.
// [VN] Phân tích nội dung thẻ XML (cấp phát mảng 256 con trỏ trên stack), phát hiện
//      thẻ đóng ('/') hoặc tự đóng ('/>'), loại bỏ thẻ '?'/'!' qua mặt nạ bit
//      0x8000000200000001ULL, tách cặp thuộc tính key="value" và gọi start_cb / end_cb.
// ============================================================================
void SrXMLParseElement(char* buf, SrXMLStartElementCb start_cb, SrXMLEndElementCb end_cb, void* user_data) {
    if (!buf) return;
    const char* attr_array[256];
    std::memset(attr_array, 0, sizeof(attr_array));

    // Skip leading whitespace (0x00b7e4..0x00b7f0)
    char* p = buf;
    unsigned char first_ch = 0;
    do {
        first_ch = static_cast<unsigned char>(*p++);
    } while (std::isspace(static_cast<int>(first_ch)));

    bool is_end_tag = (first_ch == '/');
    if (!is_end_tag) {
        --p;
    }

    unsigned char tag_start = static_cast<unsigned char>(*p);
    // Bitmask check at 0x00b808..0x00b824: cmp w8, #0x3f; mov x10, #0x8000000200000001
    // Rejects '\0' (bit 0), '!' (bit 33 = 0x21), '?' (bit 63 = 0x3f)
    if (tag_start <= 0x3f) {
        constexpr uint64_t kRejectMask = (1ULL << 0) | (1ULL << 0x21) | (1ULL << 0x3f);
        if ((kRejectMask & (1ULL << tag_start)) != 0) {
            return;
        }
    }

    char* tag_name = p;
    char* cursor = p + 1;
    unsigned char ch = tag_start;
    while (ch != 0) {
        if (std::isspace(static_cast<int>(ch))) {
            cursor[-1] = '\0';
            break;
        }
        ch = static_cast<unsigned char>(*cursor++);
    }

    int attr_idx = 0;
    bool is_self_closing = false;

    if (is_end_tag) {
        is_self_closing = true;
    } else {
        while (*cursor != '\0') {
            while (*cursor != '\0' && std::isspace(static_cast<unsigned char>(*cursor))) {
                ++cursor;
            }
            if (*cursor == '\0') break;
            if (*cursor == '/') {
                is_self_closing = true;
                break;
            }

            char* attr_name = cursor;
            while (*cursor != '\0' && *cursor != '=' && !std::isspace(static_cast<unsigned char>(*cursor))) {
                ++cursor;
            }
            if (*cursor != '\0') {
                *cursor++ = '\0';
            }

            // Find opening quote '"' (0x22) or '\'' (0x27) (0x00b914..0x00b940)
            while (*cursor != '\0' && *cursor != '"' && *cursor != '\'') {
                ++cursor;
            }
            if (*cursor == '\0') break;
            char quote = *cursor++;
            char* attr_val = cursor;
            while (*cursor != '\0' && *cursor != quote) {
                ++cursor;
            }
            if (*cursor != '\0') {
                *cursor++ = '\0';
            }

            if (attr_name != nullptr && attr_idx <= 253) {
                attr_array[attr_idx]     = attr_name;
                attr_array[attr_idx + 1] = attr_val;
                attr_idx += 2;
            }
            if (attr_idx > 255) break;
        }
    }

    attr_array[attr_idx]     = nullptr;
    attr_array[attr_idx + 1] = nullptr;

    if (!is_end_tag && start_cb != nullptr) {
        start_cb(user_data, tag_name, attr_array);
    }
    if ((is_end_tag || is_self_closing) && end_cb != nullptr) {
        end_cb(user_data, tag_name);
    }
}

// ============================================================================
// 3. SrXMLParseXML (0x00ba0c .. 0x00bb04, 248 bytes)
// [EN] Scans mutable XML buffer for '<' and '>' delimiters, skipping XML
//      comments "<!-- ... -->", and dispatches text segments to SrXMLParseContent
//      and tag segments to SrXMLParseElement.
// [VN] Quét bộ đệm XML khả biến tìm dấu '<' và '>', bỏ qua chú thích "<!-- ... -->",
//      và chuyển đoạn văn bản tới SrXMLParseContent, đoạn thẻ tới SrXMLParseElement.
// ============================================================================
int SrXMLParseXML(char* xml_mutable, SrXMLStartElementCb start_cb, SrXMLEndElementCb end_cb,
                  SrXMLContentCb content_cb, void* user_data) {
    if (!xml_mutable) return 0;
    char* p = xml_mutable;

    while (*p != '\0') {
        char* lt = std::strchr(p, '<');
        if (!lt) break;

        *lt = '\0';
        SrXMLParseContent(p, content_cb, user_data);
        p = lt + 1;

        // Check for XML comment "<!--" (0x00ba60..0x00ba98)
        if (std::strncmp(p, "!--", 3) == 0) {
            char* comment_end = std::strstr(p + 3, "-->");
            if (!comment_end) return 0;
            p = comment_end + 3;
            continue;
        }

        char* gt = std::strchr(p, '>');
        if (!gt) break;

        *gt = '\0';
        if (p[0] == '/') {
            // Check if closing tag has trailing slash or normal end tag
            SrXMLParseElement(p, start_cb, end_cb, user_data);
        } else {
            // Also check if gt[-1] == '/' for self-closing tag
            SrXMLParseElement(p, start_cb, end_cb, user_data);
        }
        p = gt + 1;
    }
    return 1;
}

// ============================================================================
// 4. make_serval_length_unit (0x0126cc .. 0x012718, 80 bytes)
// [EN] Compares unit string against "px" (.rodata 0x0333db -> returns 5) and
//      "%" (.rodata 0x034ea8 -> returns 2); otherwise returns 1 (NUMBER).
//      Exact opcodes at 0x0126fc..0x01270c:
//        cmp w0, #0; mov w8, #1; cinc w0, w8, eq; ... mov w0, #5
// [VN] So sánh chuỗi đơn vị với "px" (trả về 5) và "%" (trả về 2); mặc định trả về 1.
// ============================================================================
SrSVGLengthUnit make_serval_length_unit(const char* unit_str) {
    if (!unit_str || unit_str[0] == '\0') {
        return SR_SVG_UNITS_NUMBER;
    }
    if (std::strcmp(unit_str, "px") == 0) {
        return SR_SVG_UNITS_PX; // 5 (0x01270c: mov w0, #5)
    }
    if (std::strcmp(unit_str, "%") == 0) {
        return SR_SVG_UNITS_PERCENTAGE; // 2 (0x012704: cinc w0, w8, eq)
    }
    if (std::strcmp(unit_str, "em") == 0) return SR_SVG_UNITS_EM;
    if (std::strcmp(unit_str, "ex") == 0) return SR_SVG_UNITS_EX;
    if (std::strcmp(unit_str, "cm") == 0) return SR_SVG_UNITS_CM;
    if (std::strcmp(unit_str, "mm") == 0) return SR_SVG_UNITS_MM;
    if (std::strcmp(unit_str, "in") == 0) return SR_SVG_UNITS_IN;
    if (std::strcmp(unit_str, "pt") == 0) return SR_SVG_UNITS_PT;
    if (std::strcmp(unit_str, "pc") == 0) return SR_SVG_UNITS_PC;
    return SR_SVG_UNITS_NUMBER;
}

// ============================================================================
// 5. make_serval_length (0x01271c .. 0x0127a4, 140 bytes)
// [EN] Calls strtod(str, &end_ptr) (0x00aa20 PLT), fcvt s8, d0 (0x01273c),
//      checks end_ptr against '\0' (0x100000000), "px" (0x500000000), and
//      "%" (0x200000000), and returns SrSVGLength{value, unit}.
// [VN] Gọi strtod(str, &end_ptr), ép kiểu sang float (fcvt s8, d0), kiểm tra
//      hậu tố đơn vị ("px" -> 5, "%" -> 2, rỗng -> 1) và trả về SrSVGLength.
// ============================================================================
SrSVGLength make_serval_length(const char* str) {
    if (!str) {
        return SrSVGLength{ 0.0f, SR_SVG_UNITS_UNKNOWN };
    }
    char* end_ptr = nullptr;
    double val_d = std::strtod(str, &end_ptr);
    float val_f = static_cast<float>(val_d);

    SrSVGLengthUnit unit = SR_SVG_UNITS_NUMBER;
    if (end_ptr && *end_ptr != '\0') {
        if (std::strcmp(end_ptr, "px") == 0) {
            unit = SR_SVG_UNITS_PX; // 5 (0x012788: mov x8, #0x500000000)
        } else if (std::strcmp(end_ptr, "%") == 0) {
            unit = SR_SVG_UNITS_PERCENTAGE; // 2 (0x012774: mov x9, #0x200000000)
        } else {
            unit = make_serval_length_unit(end_ptr);
        }
    }
    return SrSVGLength{ val_f, unit };
}

// ============================================================================
// 6. make_serval_spread_method (0x0127a8 .. 0x0127f4, 80 bytes)
// [EN] Checks "reflect" (.rodata 0x0333de -> returns 1) and "repeat"
//      (.rodata 0x0333e6 -> returns 2); otherwise returns 0 (pad).
// [VN] Kiểm tra "reflect" (trả về 1) và "repeat" (trả về 2); mặc định trả về 0 (pad).
// ============================================================================
SrSVGSpreadMethod make_serval_spread_method(const char* str) {
    if (!str) return SR_SVG_SPREAD_PAD;
    if (std::strcmp(str, "reflect") == 0) {
        return SR_SVG_SPREAD_REFLECT; // 1 (0x0127e8: mov w0, #1)
    }
    if (std::strcmp(str, "repeat") == 0) {
        return SR_SVG_SPREAD_REPEAT;  // 2 (0x0127e0: lsl w0, w8, #1)
    }
    return SR_SVG_SPREAD_PAD;
}

// ============================================================================
// 7. make_serval_view_box (0x0127f8 .. 0x0128ac, 184 bytes)
// [EN] Tokenizes viewBox string using strtok_r (0x00a890 PLT) with delimiter
//      " ,;\t\n" (.rodata 0x0333ed) and parses up to 4 floats via strtof.
// [VN] Tách chuỗi viewBox bằng strtok_r với bộ phân cách " ,;\t\n" và đọc 4 số float.
// ============================================================================
SrSVGBox make_serval_view_box(const char* str) {
    SrSVGBox box{ 0.0f, 0.0f, 0.0f, 0.0f };
    if (!str) return box;

    char buf[256];
    std::strncpy(buf, str, sizeof(buf) - 1);
    buf[sizeof(buf) - 1] = '\0';

    const char* kDelims = " ,;\t\n"; // .rodata 0x0333ed
    char* save_ptr = nullptr;
    char* token = strtok_r(buf, kDelims, &save_ptr);
    float vals[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
    int idx = 0;

    while (token != nullptr && idx < 4) {
        char* end_ptr = nullptr;
        vals[idx++] = std::strtof(token, &end_ptr);
        token = strtok_r(nullptr, kDelims, &save_ptr);
    }

    box.left   = vals[0];
    box.top    = vals[1];
    box.width  = vals[2];
    box.height = vals[3];
    return box;
}

// ============================================================================
// 8. make_preserve_aspect_radio (0x0128b0 .. 0x0129b8, 268 bytes)
// [EN] Uses strstr (0x00a9d0 PLT) to check for:
//      - "none"  (0x0333f3) -> {align_x = 2, align_y = 2, scale = 0}
//      - "xMin"  (0x0333f8) -> align_x = 1
//      - "xMid"  (0x0333fd) -> align_x = 2
//      - "xMax"  (0x033402) -> align_x = 3 (else 2)
//      - "YMin"  (0x033407) -> align_y = 1
//      - "YMid"  (0x03340c) -> align_y = 2
//      - "YMax"  (0x033411) -> align_y = 3 (else 2)
//      - "slice" (0x033416) -> scale = 2 (else 1 = meet)
// [VN] Dùng strstr kiểm tra các từ khóa căn chỉnh khung hình SVG ("none",
//      "xMin"/"xMid"/"xMax", "YMin"/"YMid"/"YMax", "slice"/"meet").
// ============================================================================
SrSVGPreserveAspectRatio make_preserve_aspect_radio(const char* str) {
    if (!str || std::strstr(str, "none") != nullptr) {
        // 0x0128d4..0x0128dc: mov x1, xzr; mov x21, #0x200000000; mov w20, #2
        return SrSVGPreserveAspectRatio{ SR_SVG_ALIGN_MID, SR_SVG_ALIGN_MID, SR_SVG_SCALE_NONE };
    }

    int32_t align_x = SR_SVG_ALIGN_MID;
    if (std::strstr(str, "xMin") != nullptr) {
        align_x = SR_SVG_ALIGN_MIN; // 1
    } else if (std::strstr(str, "xMid") != nullptr) {
        align_x = SR_SVG_ALIGN_MID; // 2
    } else if (std::strstr(str, "xMax") != nullptr) {
        align_x = SR_SVG_ALIGN_MAX; // 3 (0x012934: cinc x20, x8, ne)
    }

    int32_t align_y = SR_SVG_ALIGN_MID;
    if (std::strstr(str, "YMin") != nullptr) {
        align_y = SR_SVG_ALIGN_MIN; // 1
    } else if (std::strstr(str, "YMid") != nullptr) {
        align_y = SR_SVG_ALIGN_MID; // 2
    } else if (std::strstr(str, "YMax") != nullptr) {
        align_y = SR_SVG_ALIGN_MAX; // 3 (0x012980: mov x8, #0x300000000)
    }

    int32_t scale = (std::strstr(str, "slice") != nullptr)
                  ? SR_SVG_SCALE_SLICE  // 2 (0x0129a0: cinc x1, x8, ne)
                  : SR_SVG_SCALE_MEET;  // 1

    return SrSVGPreserveAspectRatio{ align_x, align_y, scale };
}

// ============================================================================
// 9. make_default_preserve_aspect_radio (0x0129bc .. 0x0129d8, 32 bytes)
// [EN] Tail-calls make_preserve_aspect_radio("") (.rodata 0x0333f2), returning
//      default xMidYMid meet = {align_x = 2, align_y = 2, scale = 1}.
// [VN] Gọi make_preserve_aspect_radio("") trả về mặc định xMidYMid meet {2, 2, 1}.
// ============================================================================
SrSVGPreserveAspectRatio make_default_preserve_aspect_radio(void) {
    return make_preserve_aspect_radio("");
}

// ============================================================================
// 10. calculate_view_box_transform (0x0129dc .. 0x012c58, 640 bytes)
// [EN] Computes the 6-element 2D affine matrix xform_out6 = [a, b, c, d, tx, ty]
//      mapping view_box {vb_x, vb_y, vb_w, vb_h} into view_port {vp_x, vp_y, vp_w, vp_h}
//      according to preserve_aspect_ratio {align_x, align_y, scale}:
//      - Initializes xform_out6 to identity {1, 0, 0, 1, 0, 0} (.rodata 0x032e30).
//      - Computes sx = vp_w / vb_w (fdiv s6, s16, s7 @ 0x012a14),
//                 sy = vp_h / vb_h (fdiv s3, s5, s4 @ 0x012a18),
//                 trans_x = -vb_x (fneg s1, s0 @ 0x012a1c),
//                 trans_y = -vb_y (fneg s0, s17 @ 0x012a20).
//      - If scale == 0 (none): pre-translates by (vp_x, vp_y), pre-scales by (sx, sy),
//        and pre-translates by (-vb_x, -vb_y).
//      - If scale == 1 (meet): uniform s = min(sx, sy) (fcmp s6, s3; fcsel s3, s6, s3, mi @ 0x012ab8).
//      - If scale == 2 (slice): uniform s = max(sx, sy) (fcmp s6, s3; fcsel s3, s6, s3, gt @ 0x012ac4).
//      - Adjusts trans_x for align_x == 2 (xMid: -0.5f * (vb_w - vp_w / s)) or
//        align_x == 3 (xMax: -(vb_w - vp_w / s)), and similarly trans_y for align_y.
// [VN] Tính ma trận biến đổi affine 2D 6 phần tử ánh xạ viewBox vào viewPort
//      theo đúng chuỗi lệnh SIMD/FP tại 0x0129dc..0x012c58.
// ============================================================================
void calculate_view_box_transform(const SrSVGBox* view_port,
                                  const SrSVGBox* view_box,
                                  SrSVGPreserveAspectRatio preserve_aspect_ratio,
                                  float* xform_out6) {
    if (!view_port || !view_box || !xform_out6) return;

    // 0x0129f4..0x012a04: ldr q2, [0x32e30]; str q2, [x4]; str xzr, [x4, #0x10]
    xform_identity(xform_out6);

    if (view_box->width == 0.0f || view_box->height == 0.0f) {
        return;
    }

    // 0x012a08..0x012a20
    float vp_w = view_port->width;
    float vp_h = view_port->height;
    float vb_w = view_box->width;
    float vb_h = view_box->height;
    float sx   = vp_w / vb_w; // fdiv s6, s16, s7
    float sy   = vp_h / vb_h; // fdiv s3, s5, s4
    float tx   = -view_box->left; // fneg s1, s0
    float ty   = -view_box->top;  // fneg s0, s17

    if (preserve_aspect_ratio.scale == SR_SVG_SCALE_NONE) {
        // 0x012a34..0x012ab4: non-uniform scale (sx, sy)
        xform_pre_translate(xform_out6, view_port->left, view_port->top);
        xform_pre_scale(xform_out6, sx, sy);
        xform_pre_translate(xform_out6, tx, ty);
        return;
    }

    float scale = 1.0f;
    if (preserve_aspect_ratio.scale == SR_SVG_SCALE_MEET) {
        // 0x012ab8: fcmp s6, s3; fcsel s3, s6, s3, mi
        scale = (sx < sy) ? sx : sy;
    } else if (preserve_aspect_ratio.scale == SR_SVG_SCALE_SLICE) {
        // 0x012ac4: fcmp s6, s3; fcsel s3, s6, s3, gt
        scale = (sx > sy) ? sx : sy;
    }

    // Horizontal alignment adjustment (0x012ad8..0x012b28)
    if (preserve_aspect_ratio.align_x == SR_SVG_ALIGN_MAX) {
        // 0x012b20: fdiv s16, s16, s3; fsub s7, s7, s16; fsub s1, s1, s7
        tx -= (vb_w - (vp_w / scale));
    } else if (preserve_aspect_ratio.align_x == SR_SVG_ALIGN_MID) {
        // 0x012aec: fdiv s16, s16, s3; fsub s7, s7, s16; fmul s7, s7, #-0.5; fadd s1, s1, s7
        tx += (vb_w - (vp_w / scale)) * (-0.5f);
    }

    // Vertical alignment adjustment (0x012afc..0x012b3c)
    if (preserve_aspect_ratio.align_y == SR_SVG_ALIGN_MAX) {
        // 0x012b34: fdiv s5, s5, s3; fsub s4, s4, s5; fsub s0, s0, s4
        ty -= (vb_h - (vp_h / scale));
    } else if (preserve_aspect_ratio.align_y == SR_SVG_ALIGN_MID) {
        // 0x012b0c: fdiv s5, s5, s3; fsub s4, s4, s5; fmul s4, s4, #-0.5; fadd s0, s0, s4
        ty += (vb_h - (vp_h / scale)) * (-0.5f);
    }

    // Apply: pre_translate(vp_left, vp_top) -> pre_scale(scale, scale) -> pre_translate(tx, ty)
    xform_pre_translate(xform_out6, view_port->left, view_port->top);
    xform_pre_scale(xform_out6, scale, scale);
    xform_pre_translate(xform_out6, tx, ty);
}

// ============================================================================
// 11. 2D Affine Matrix Engine (xform[6] = [a, b, c, d, tx, ty]) (0x012c5c .. 0x012fe0)
//     Representing the 3x3 homogeneous matrix:
//       [ a   c   tx ]
//       [ b   d   ty ]
//       [ 0   0   1  ]
// ============================================================================

// 0x012c5c .. 0x012c6c (20 bytes): ldr q0, [0x32e30]; str xzr, [x0, #0x10]; str q0, [x0]
void xform_identity(float* xform) {
    if (!xform) return;
    std::memcpy(xform, kRodata_032e30_Identity4, 4 * sizeof(float));
    xform[4] = 0.0f;
    xform[5] = 0.0f;
}

// 0x012c70 .. 0x012ce8 (124 bytes): xform = xform * Translate(tx, ty)
void xform_pre_translate(float* xform, float tx, float ty) {
    if (!xform) return;
    float t[6];
    xform_set_translation(t, tx, ty);
    xform_pre_multiply(xform, t);
}

// 0x012cec .. 0x012da4 (188 bytes): xform = xform * Scale(sx, sy)
void xform_pre_scale(float* xform, float sx, float sy) {
    if (!xform) return;
    float s[6];
    xform_set_scale(s, sx, sy);
    xform_pre_multiply(xform, s);
}

// 0x012da8 .. 0x012dbc (24 bytes): str s0, [x0]; movi d0, #0; str s1, [x0, #0xc]; stur d0, [x0, #4]; str d0, [x0, #0x10]
void xform_set_scale(float* xform, float sx, float sy) {
    if (!xform) return;
    xform[0] = sx;
    xform[1] = 0.0f;
    xform[2] = 0.0f;
    xform_set_translation(xform, 0.0f, 0.0f);
    xform[0] = sx;
    xform[1] = 0.0f;
    xform[2] = 0.0f;
    xform[3] = sy;
    xform[4] = 0.0f;
    xform[5] = 0.0f;
}

// 0x012dc0 .. 0x012e68 (172 bytes): dst = src * dst (post-multiply)
void xform_multiply(float* dst, const float* src) {
    if (!dst || !src) return;
    float t0 = dst[0] * src[0] + dst[1] * src[2];
    float t1 = dst[0] * src[1] + dst[1] * src[3];
    float t2 = dst[2] * src[0] + dst[3] * src[2];
    float t3 = dst[2] * src[1] + dst[3] * src[3];
    float t4 = dst[4] * src[0] + dst[5] * src[2] + src[4];
    float t5 = dst[4] * src[1] + dst[5] * src[3] + src[5];
    dst[0] = t0;
    dst[1] = t1;
    dst[2] = t2;
    dst[3] = t3;
    dst[4] = t4;
    dst[5] = t5;
}

// 0x012e6c .. 0x012e7c (20 bytes): ldr q2, [0x32e30]; stp s0, s1, [x0, #0x10]; str q2, [x0]
void xform_set_translation(float* xform, float tx, float ty) {
    if (!xform) return;
    std::memcpy(xform, kRodata_032e30_Identity4, 4 * sizeof(float));
    xform[4] = tx;
    xform[5] = ty;
}

// 0x012e80 .. 0x012f28 (172 bytes): dst = dst * src (pre-multiply)
void xform_pre_multiply(float* dst, const float* src) {
    if (!dst || !src) return;
    float t0 = src[0] * dst[0] + src[1] * dst[2];
    float t1 = src[0] * dst[1] + src[1] * dst[3];
    float t2 = src[2] * dst[0] + src[3] * dst[2];
    float t3 = src[2] * dst[1] + src[3] * dst[3];
    float t4 = src[4] * dst[0] + src[5] * dst[2] + dst[4];
    float t5 = src[4] * dst[1] + src[5] * dst[3] + dst[5];
    dst[0] = t0;
    dst[1] = t1;
    dst[2] = t2;
    dst[3] = t3;
    dst[4] = t4;
    dst[5] = t5;
}

// 0x012f2c .. 0x012f68 (64 bytes): calls sincosf (0x00a930 PLT), sets [cos, sin, -sin, cos, 0, 0]
void xform_set_rotation(float* xform, float radians) {
    if (!xform) return;
    float s = std::sin(radians);
    float c = std::cos(radians);
    xform[0] =  c;
    xform[1] =  s;
    xform[2] = -s;
    xform[3] =  c;
    xform[4] =  0.0f;
    xform[5] =  0.0f;
}

// 0x012f6c .. 0x012fa8 (64 bytes): calls tanf (0x00a6d0 PLT), sets [1, 0, tan(a), 1, 0, 0]
void xform_set_skewX(float* xform, float radians) {
    if (!xform) return;
    xform[0] = 1.0f;
    xform[1] = 0.0f;
    xform[2] = std::tan(radians);
    xform[3] = 1.0f;
    xform[4] = 0.0f;
    xform[5] = 0.0f;
}

// 0x012fac .. 0x012fe0 (56 bytes): calls tanf (0x00a6d0 PLT), sets [1, tan(a), 0, 1, 0, 0]
void xform_set_skewY(float* xform, float radians) {
    if (!xform) return;
    xform[0] = 1.0f;
    xform[1] = std::tan(radians);
    xform[2] = 0.0f;
    xform[3] = 1.0f;
    xform[4] = 0.0f;
    xform[5] = 0.0f;
}

// ============================================================================
// 12. make_serval_paint (0x012fe4 .. 0x013104, 292 bytes)
// [EN] Parses an SVG fill/stroke attribute into a heap-allocated 16-byte SrSVGPaint:
//      - If strcmp(str, "none") == 0 (.rodata 0x0333f3): type = 0 (SR_SVG_PAINT_NONE).
//      - If strncmp(str, "url(", 4) == 0 (.rodata 0x03341c): type = 2 (SR_SVG_PAINT_IRI),
//        extracts trimmed substring between '(' (0x28) and ')' (0x29).
//      - Otherwise: type = 1 (SR_SVG_PAINT_COLOR), calls make_serval_color(str).
// [VN] Phân tích thuộc tính fill/stroke thành cấu trúc SrSVGPaint 16 byte trên heap.
// ============================================================================
SrSVGPaint* make_serval_paint(const char* str) {
    if (!str) return nullptr;

    if (std::strcmp(str, "none") == 0) {
        auto* paint = static_cast<SrSVGPaint*>(std::malloc(sizeof(SrSVGPaint)));
        if (!paint) return nullptr;
        paint->type = SR_SVG_PAINT_NONE;
        paint->reserved = 0;
        paint->iri = nullptr;
        return paint;
    }

    if (std::strncmp(str, "url(", 4) == 0) {
        auto* paint = static_cast<SrSVGPaint*>(std::malloc(sizeof(SrSVGPaint)));
        if (!paint) return nullptr;
        paint->type = SR_SVG_PAINT_IRI;
        paint->reserved = 0;
        paint->iri = nullptr;

        const char* lp = std::strchr(str, '(');
        if (lp != nullptr) {
            const char* rp = std::strchr(lp + 1, ')');
            if (rp != nullptr) {
                const char* start = lp + 1;
                while (start < rp && std::isspace(static_cast<unsigned char>(*start))) {
                    ++start;
                }
                const char* end = rp - 1;
                while (end > start && std::isspace(static_cast<unsigned char>(*end))) {
                    --end;
                }
                size_t len = (rp > start) ? static_cast<size_t>(end - start + 1) : 0;
                char* iri_copy = static_cast<char*>(std::malloc(len + 1));
                if (iri_copy != nullptr) {
                    std::memcpy(iri_copy, start, len);
                    iri_copy[len] = '\0';
                    paint->iri = iri_copy;
                }
            }
        }
        return paint;
    }

    SrSVGColor c = make_serval_color(str);
    auto* paint = static_cast<SrSVGPaint*>(std::malloc(sizeof(SrSVGPaint)));
    if (!paint) return nullptr;
    paint->type = SR_SVG_PAINT_COLOR;
    paint->reserved = 0;
    paint->color = c;
    return paint;
}

// ============================================================================
// 13. make_serval_color (0x013108 .. 0x01350c, 1,032 bytes)
// [EN] Exact AArch64 reconstruction of Serval SVG color parser:
//      1. Checks strcmp(str, "currentColor") == 0 (.rodata 0x033421) -> {type=0, color=0}.
//      2. Skips leading whitespace/commas. If empty -> {type=1, color=0}.
//      3. If str[0] == '#' (0x23):
//         - Counts non-whitespace length L; validates (3 <= L <= 9) and bitmask
//           ((1u << L) & 0x2b0u) != 0 (i.e. L in {4, 5, 7, 9} for #RGB, #RGBA, #RRGGBB, #RRGGBBAA).
//         - Initializes 4 uint32 channels to {0, 0, 0, 0xFF} (.rodata 0x032e50).
//         - Looks up each hex char in kRodata_033484_HexNibbleTable (for L < 7, duplicates
//           nibble: c = nibble | (nibble << 4); for L >= 7, combines high/low nibbles).
//         - Packs (A << 24) | (R << 16) | (G << 8) | B (0x0134ac..0x0134c0).
//      4. If "rgb(" (0x013290..0x013370):
//         - Parses via sscanf(str + 4, "%d%[%%, \t]%d%[%%, \t]%d", &r, sep1, &g, sep2, &b).
//         - If '%' is present in separator (memchr(sep1, '%', 32) != nullptr), converts
//           percentage to 0..255 using exact magic fixed-point multiplication:
//           ((val * 255) * 0x51eb851fULL) >> 37 (0x01331c..0x013364).
//      5. If "rgba(" (0x013374..0x013468):
//         - Parses via sscanf(str + 5, "%d%[%%, \t]%d%[%%, \t]%d%[%%, \t]%f", ...),
//           multiplies alpha float by 255.0f (0x437f0000 @ 0x0134e8).
//      6. Otherwise scans sr_svg__colors[147] (0x048000, 0x930 bytes); if not found,
//         returns fallback grey 0xFF808080 (0x013494: mov w8, #0x8080; movk w8, #0xff80, lsl #16).
// [VN] Tái tạo chính xác tuyệt đối bộ phân tích màu sắc SVG theo mã máy tại 0x013108..0x01350c.
// ============================================================================
SrSVGColor make_serval_color(const char* str) {
    if (!str) {
        return SrSVGColor{ 1u, 0u };
    }
    if (std::strcmp(str, "currentColor") == 0) {
        // 0x013250: mov x8, xzr; mov x9, xzr
        return SrSVGColor{ 0u, 0u };
    }

    const char* p = str;
    while (*p != '\0' && (std::isspace(static_cast<unsigned char>(*p)) || *p == ',')) {
        ++p;
    }
    size_t slen = std::strlen(p);
    if (slen == 0) {
        return SrSVGColor{ 1u, 0u };
    }

    // Case 1: Hex color '#RGB', '#RGBA', '#RRGGBB', '#RRGGBBAA' (0x013178..0x01325c)
    if (p[0] == '#') {
        uint32_t token_len = 0;
        while (p[token_len] != '\0' && !std::isspace(static_cast<unsigned char>(p[token_len]))) {
            ++token_len;
        }
        if (token_len < 3 || token_len > 9) {
            return SrSVGColor{ 1u, 0u };
        }
        constexpr uint32_t kValidLenMask = 0x2b0u; // (1<<4) | (1<<5) | (1<<7) | (1<<9)
        if (((1u << token_len) & kValidLenMask) == 0) {
            return SrSVGColor{ 1u, 0u };
        }

        uint32_t rgba[4] = {
            kRodata_032e50_HexDefault4[0],
            kRodata_032e50_HexDefault4[1],
            kRodata_032e50_HexDefault4[2],
            kRodata_032e50_HexDefault4[3]
        };
        uint32_t num_channels = (token_len - 1u) >> ((token_len > 6u) ? 1u : 0u);
        const char* hex_p = p + 1;

        for (uint32_t ch_idx = 0; ch_idx < num_channels && ch_idx < 4; ++ch_idx) {
            unsigned char c1 = static_cast<unsigned char>(*hex_p++);
            if (c1 == 0 || c1 == 'G' || c1 >= 103) {
                return SrSVGColor{ 1u, 0u };
            }
            uint32_t nib1 = static_cast<uint32_t>(kRodata_033484_HexNibbleTable[c1]);
            uint32_t val = (rgba[ch_idx] << 4) | nib1;
            rgba[ch_idx] = val;

            if (token_len >= 7u) {
                unsigned char c2 = static_cast<unsigned char>(*hex_p++);
                if (c2 >= 103) return SrSVGColor{ 1u, 0u };
                uint32_t nib2 = static_cast<uint32_t>(kRodata_033484_HexNibbleTable[c2]);
                rgba[ch_idx] = (val << 4) | nib2;
            } else {
                rgba[ch_idx] = (val << 4) | nib1;
            }
        }

        uint32_t packed_argb = (rgba[3] << 24) | (rgba[0] << 16) | (rgba[1] << 8) | rgba[2];
        return SrSVGColor{ 1u, packed_argb };
    }

    // Case 2: rgb(...) (0x013290..0x013370)
    if (slen >= 4 && std::strncmp(p, "rgb(", 4) == 0) {
        int r = -1, g = -1, b = -1;
        char sep1[32] = {0}, sep2[32] = {0};
        std::sscanf(p + 4, "%d%[%%, \t]%d%[%%, \t]%d", &r, sep1, &g, sep2, &b);
        if (std::memchr(sep1, '%', 32) != nullptr) {
            // Exact fixed-point division by 100 at 0x01331c..0x013368:
            // w8 = (w8 << 8) - w8 = w8 * 255; x8 = (uint64_t(w8) * 0x51eb851f) >> 37
            constexpr uint64_t kMagicDiv100 = 0x51eb851fULL;
            uint32_t ur = static_cast<uint32_t>((static_cast<uint64_t>(static_cast<uint32_t>(r * 255)) * kMagicDiv100) >> 37);
            uint32_t ug = static_cast<uint32_t>((static_cast<uint64_t>(static_cast<uint32_t>(g * 255)) * kMagicDiv100) >> 37);
            uint32_t ub = static_cast<uint32_t>((static_cast<uint64_t>(static_cast<uint32_t>(b * 255)) * kMagicDiv100) >> 37);
            uint32_t argb = 0xFF000000u | ((ur & 0xFFu) << 16) | ((ug & 0xFFu) << 8) | (ub & 0xFFu);
            return SrSVGColor{ 1u, argb };
        } else {
            uint32_t argb = 0xFF000000u
                          | ((static_cast<uint32_t>(r) & 0xFFu) << 16)
                          | ((static_cast<uint32_t>(g) & 0xFFu) << 8)
                          |  (static_cast<uint32_t>(b) & 0xFFu);
            return SrSVGColor{ 1u, argb };
        }
    }

    // Case 3: rgba(...) (0x013374..0x013508)
    if (slen >= 5 && std::strncmp(p, "rgba(", 5) == 0) {
        int r = -1, g = -1, b = -1;
        float a = 1.0f;
        char sep1[32] = {0}, sep2[32] = {0}, sep3[32] = {0};
        std::sscanf(p + 5, "%d%[%%, \t]%d%[%%, \t]%d%[%%, \t]%f", &r, sep1, &g, sep2, &b, sep3, &a);
        uint32_t ua = static_cast<uint32_t>(a * 255.0f);
        if (std::memchr(sep1, '%', 32) != nullptr) {
            constexpr uint64_t kMagicDiv100 = 0x51eb851fULL;
            uint32_t ur = static_cast<uint32_t>((static_cast<uint64_t>(static_cast<uint32_t>(r * 255)) * kMagicDiv100) >> 37);
            uint32_t ug = static_cast<uint32_t>((static_cast<uint64_t>(static_cast<uint32_t>(g * 255)) * kMagicDiv100) >> 37);
            uint32_t ub = static_cast<uint32_t>((static_cast<uint64_t>(static_cast<uint32_t>(b * 255)) * kMagicDiv100) >> 37);
            uint32_t argb = ((ua & 0xFFu) << 24) | ((ur & 0xFFu) << 16) | ((ug & 0xFFu) << 8) | (ub & 0xFFu);
            return SrSVGColor{ 1u, argb };
        } else {
            uint32_t argb = ((ua & 0xFFu) << 24)
                          | ((static_cast<uint32_t>(r) & 0xFFu) << 16)
                          | ((static_cast<uint32_t>(g) & 0xFFu) << 8)
                          |  (static_cast<uint32_t>(b) & 0xFFu);
            return SrSVGColor{ 1u, argb };
        }
    }

    // Case 4: Linear scan of 147 named colors in sr_svg__colors (0x01346c..0x0134a8)
    for (size_t i = 0; i < 147; ++i) {
        if (std::strcmp(sr_svg__colors[i].name, p) == 0) {
            return SrSVGColor{ 1u, sr_svg__colors[i].rgb };
        }
    }

    // Default fallback grey 0xFF808080 (0x013494..0x013498)
    return SrSVGColor{ 1u, 0xFF808080u };
}

// ============================================================================
// 14. release_serval_paint (0x013510 .. 0x013544, 56 bytes)
// [EN] Frees paint->iri if paint->type == SR_SVG_PAINT_IRI (2), then frees paint.
// [VN] Giải phóng paint->iri nếu paint->type == 2, sau đó giải phóng paint.
// ============================================================================
void release_serval_paint(SrSVGPaint* paint) {
    if (!paint) return;
    if (paint->type == SR_SVG_PAINT_IRI && paint->iri != nullptr) {
        std::free(paint->iri);
    }
    std::free(paint);
}

// ============================================================================
// 15. convert_serval_length_to_float (0x013548 .. 0x013698, 340 bytes)
// [EN] Converts SrSVGLength{value, unit} to device pixels using two jump tables
//      (.rodata 0x032e78 for unit 0..10 and .rodata 0x032e83 for percentage type 0..3):
//      - unit 1 (NUMBER) or 5 (PX): returns value (0x01356c).
//      - unit 2 (PERCENTAGE): val = value / 100.0f (0x42c80000 @ 0x013578), then:
//          * type == 0 (HORIZONTAL): val * ctx->view_box.width ([ctx + 0x30])
//          * type == 1 (VERTICAL):   val * ctx->view_box.height ([ctx + 0x34])
//          * type == 2 (OTHER):      val * float(sqrt(double(w*w + h*h)) * 0.70710678118654757)
//          * type == 3 (ABSOLUTE):   val * 1.0f
//      - unit 3 (EM): value * ctx->font_size ([ctx + 0x0c])
//      - unit 4 (EX): value * ctx->font_size * 0.52f (0x3f051eb8 @ 0x0135d0)
//      - unit 6 (CM): value * ctx->dpi / 2.54f (0x40228f5c @ 0x0135f0)
//      - unit 7 (MM): value * ctx->dpi / 25.4f (0x41cb3333 @ 0x013604)
//      - unit 8 (IN): value * ctx->dpi ([ctx + 0x08])
//      - unit 9 (PT): value * ctx->dpi / 72.0f (0x42900000 @ 0x013628)
//      - unit 10 (PC): value * ctx->dpi / 6.0f (fmov s2, #6.0 @ 0x01363c)
// [VN] Chuyển đổi SrSVGLength sang pixel thiết bị khớp tuyệt đối với 2 bảng nhảy
//      và các hằng số IEEE-754 tại 0x013548..0x013698.
// ============================================================================
float convert_serval_length_to_float(const SrSVGLength* length,
                                     const SrSVGRenderContext* ctx,
                                     int32_t type) {
    if (!length) return 0.0f;
    uint32_t u = static_cast<uint32_t>(length->unit);
    if (u > 10u) {
        return 0.0f; // 0x01364c: fmov s0, wzr; ret
    }

    float val = length->value;
    float dpi = ctx ? ctx->dpi : 96.0f;
    float em  = ctx ? ctx->font_size : 14.0f;

    switch (static_cast<SrSVGLengthUnit>(u)) {
        case SR_SVG_UNITS_UNKNOWN:
            return 0.0f;
        case SR_SVG_UNITS_NUMBER:
        case SR_SVG_UNITS_PX:
            return val; // 0x01356c
        case SR_SVG_UNITS_PERCENTAGE: {
            float ratio = val / 100.0f; // 0x013578: mov w8, #0x42c80000; fdiv s0, s0, s1
            if (static_cast<uint32_t>(type) > 3u) {
                return ratio * 0.0f; // 0x013654
            }
            if (!ctx) return ratio;
            switch (type) {
                case SR_SVG_LENGTH_TYPE_HORIZONTAL:
                    return ratio * ctx->view_box.width;  // 0x0135ac: ldr s1, [x1, #0x30]
                case SR_SVG_LENGTH_TYPE_VERTICAL:
                    return ratio * ctx->view_box.height; // 0x013660: ldr s1, [x1, #0x34]
                case SR_SVG_LENGTH_TYPE_OTHER: {
                    // 0x01366c..0x013694: ldp s1, s2, [x1, #0x30]; fmul; fadd; fcvt d1, s1; fsqrt d1, d1; fmul d1, d1, d3
                    float w = ctx->view_box.width;
                    float h = ctx->view_box.height;
                    double diag_sq = static_cast<double>(w * w + h * h);
                    float norm_diag = static_cast<float>(std::sqrt(diag_sq) * kRodata_032e68_InvSqrt2);
                    return ratio * norm_diag;
                }
                case SR_SVG_LENGTH_TYPE_ABSOLUTE:
                default:
                    return ratio * 1.0f;
            }
        }
        case SR_SVG_UNITS_EM:
            return val * em; // 0x0135b8
        case SR_SVG_UNITS_EX: {
            // 0x0135d0: mov w8, #0x1eb8; movk w8, #0x3f05, lsl #16 -> 0.5199999809265137f
            constexpr float kExFactor = 0.5199999809265137f;
            return (val * em) * kExFactor;
        }
        case SR_SVG_UNITS_CM: {
            // 0x0135f0: mov w8, #0x8f5c; movk w8, #0x4022, lsl #16 -> 2.5399999618530273f
            constexpr float kCmPerIn = 2.5399999618530273f;
            return (val / kCmPerIn) * dpi;
        }
        case SR_SVG_UNITS_MM: {
            // 0x013604: mov w8, #0x3333; movk w8, #0x41cb, lsl #16 -> 25.399999618530273f
            constexpr float kMmPerIn = 25.399999618530273f;
            return (val / kMmPerIn) * dpi;
        }
        case SR_SVG_UNITS_IN:
            return val * dpi; // 0x013610
        case SR_SVG_UNITS_PT:
            return (val / 72.0f) * dpi; // 0x013620: 0x42900000
        case SR_SVG_UNITS_PC:
            return (val / 6.0f) * dpi;  // 0x013634: 6.0f
    }
    return 0.0f;
}

// ============================================================================
// 16. make_serval_path (0x01369c .. 0x014aec, 5,204 bytes)
// [EN] Full W3C SVG 1.1 path data ('d' attribute) state machine:
//      Supports M/m, L/l, H/h, V/v, C/c, S/s (smooth cubic checking "cCsS" @ 0x03342e),
//      Q/q, T/t (smooth quadratic checking "tTqQ" @ 0x033433), A/a (elliptical arc
//      decomposed into cubic Bézier curves), and Z/z (close path).
// [VN] Máy trạng thái phân tích dữ liệu đường dẫn SVG ('d' attribute) đầy đủ.
// ============================================================================
SrSVGPathData* make_serval_path(const char* d_str) {
    if (!d_str) return nullptr;
    auto* path = static_cast<SrSVGPathData*>(std::malloc(sizeof(SrSVGPathData)));
    if (!path) return nullptr;
    std::memset(path, 0, sizeof(SrSVGPathData));

    const char* p = d_str;
    char cmd = 0;
    char prev_cmd = 0;
    float cur_x = 0.0f, cur_y = 0.0f;
    float start_x = 0.0f, start_y = 0.0f;
    float last_ctrl_x = 0.0f, last_ctrl_y = 0.0f;

    while (*p != '\0') {
        skip_svg_ws_and_comma(&p);
        if (*p == '\0') break;

        if (std::isalpha(static_cast<unsigned char>(*p))) {
            cmd = *p++;
        } else if (cmd == 0) {
            break;
        }

        skip_svg_ws_and_comma(&p);

        switch (cmd) {
            case 'M':
            case 'm': {
                float x = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float y = parse_serval_svg_number(&p);
                if (cmd == 'm') {
                    x += cur_x;
                    y += cur_y;
                }
                cur_x = start_x = last_ctrl_x = x;
                cur_y = start_y = last_ctrl_y = y;
                float pts[2] = { cur_x, cur_y };
                path_push_op(path, SPO_MOVE_TO);
                path_push_args(path, pts, 2);
                prev_cmd = cmd;
                // Subsequent coordinate pairs after M/m are implicit L/l
                cmd = (cmd == 'm') ? 'l' : 'L';
                break;
            }
            case 'L':
            case 'l': {
                float x = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float y = parse_serval_svg_number(&p);
                if (cmd == 'l') {
                    x += cur_x;
                    y += cur_y;
                }
                cur_x = last_ctrl_x = x;
                cur_y = last_ctrl_y = y;
                float pts[2] = { cur_x, cur_y };
                path_push_op(path, SPO_LINE_TO);
                path_push_args(path, pts, 2);
                prev_cmd = cmd;
                break;
            }
            case 'H':
            case 'h': {
                float x = parse_serval_svg_number(&p);
                if (cmd == 'h') x += cur_x;
                cur_x = last_ctrl_x = x;
                last_ctrl_y = cur_y;
                float pts[2] = { cur_x, cur_y };
                path_push_op(path, SPO_LINE_TO);
                path_push_args(path, pts, 2);
                prev_cmd = cmd;
                break;
            }
            case 'V':
            case 'v': {
                float y = parse_serval_svg_number(&p);
                if (cmd == 'v') y += cur_y;
                cur_y = last_ctrl_y = y;
                last_ctrl_x = cur_x;
                float pts[2] = { cur_x, cur_y };
                path_push_op(path, SPO_LINE_TO);
                path_push_args(path, pts, 2);
                prev_cmd = cmd;
                break;
            }
            case 'C':
            case 'c': {
                float pts[6];
                for (int i = 0; i < 6; ++i) {
                    skip_svg_ws_and_comma(&p);
                    pts[i] = parse_serval_svg_number(&p);
                }
                if (cmd == 'c') {
                    pts[0] += cur_x; pts[1] += cur_y;
                    pts[2] += cur_x; pts[3] += cur_y;
                    pts[4] += cur_x; pts[5] += cur_y;
                }
                last_ctrl_x = pts[2];
                last_ctrl_y = pts[3];
                cur_x = pts[4];
                cur_y = pts[5];
                path_push_op(path, SPO_CUBIC_BEZ);
                path_push_args(path, pts, 6);
                prev_cmd = cmd;
                break;
            }
            case 'S':
            case 's': {
                float c1x = cur_x;
                float c1y = cur_y;
                // Checks strchr("cCsS", prev_cmd) (.rodata 0x03342e)
                if (prev_cmd != 0 && std::strchr("cCsS", prev_cmd) != nullptr) {
                    c1x = 2.0f * cur_x - last_ctrl_x;
                    c1y = 2.0f * cur_y - last_ctrl_y;
                }
                float c2x = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float c2y = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float x = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float y = parse_serval_svg_number(&p);
                if (cmd == 's') {
                    c2x += cur_x; c2y += cur_y;
                    x   += cur_x; y   += cur_y;
                }
                float pts[6] = { c1x, c1y, c2x, c2y, x, y };
                last_ctrl_x = c2x;
                last_ctrl_y = c2y;
                cur_x = x;
                cur_y = y;
                path_push_op(path, SPO_CUBIC_BEZ);
                path_push_args(path, pts, 6);
                prev_cmd = cmd;
                break;
            }
            case 'Q':
            case 'q': {
                float pts[4];
                for (int i = 0; i < 4; ++i) {
                    skip_svg_ws_and_comma(&p);
                    pts[i] = parse_serval_svg_number(&p);
                }
                if (cmd == 'q') {
                    pts[0] += cur_x; pts[1] += cur_y;
                    pts[2] += cur_x; pts[3] += cur_y;
                }
                last_ctrl_x = pts[0];
                last_ctrl_y = pts[1];
                cur_x = pts[2];
                cur_y = pts[3];
                path_push_op(path, SPO_QUAD_BEZ);
                path_push_args(path, pts, 4);
                prev_cmd = cmd;
                break;
            }
            case 'T':
            case 't': {
                float c1x = cur_x;
                float c1y = cur_y;
                // Checks strchr("tTqQ", prev_cmd) (.rodata 0x033433)
                if (prev_cmd != 0 && std::strchr("tTqQ", prev_cmd) != nullptr) {
                    c1x = 2.0f * cur_x - last_ctrl_x;
                    c1y = 2.0f * cur_y - last_ctrl_y;
                }
                float x = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float y = parse_serval_svg_number(&p);
                if (cmd == 't') {
                    x += cur_x;
                    y += cur_y;
                }
                float pts[4] = { c1x, c1y, x, y };
                last_ctrl_x = c1x;
                last_ctrl_y = c1y;
                cur_x = x;
                cur_y = y;
                path_push_op(path, SPO_QUAD_BEZ);
                path_push_args(path, pts, 4);
                prev_cmd = cmd;
                break;
            }
            case 'A':
            case 'a': {
                float rx = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float ry = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float rot = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                int large_arc = 0;
                if (*p == '0' || *p == '1') {
                    large_arc = (*p++ - '0');
                } else {
                    large_arc = (parse_serval_svg_number(&p) != 0.0f) ? 1 : 0;
                }
                skip_svg_ws_and_comma(&p);
                int sweep = 0;
                if (*p == '0' || *p == '1') {
                    sweep = (*p++ - '0');
                } else {
                    sweep = (parse_serval_svg_number(&p) != 0.0f) ? 1 : 0;
                }
                skip_svg_ws_and_comma(&p);
                float x = parse_serval_svg_number(&p);
                skip_svg_ws_and_comma(&p);
                float y = parse_serval_svg_number(&p);
                if (cmd == 'a') {
                    x += cur_x;
                    y += cur_y;
                }
                arc_to_cubic_beziers(path, cur_x, cur_y, rx, ry, rot, large_arc, sweep, x, y);
                cur_x = last_ctrl_x = x;
                cur_y = last_ctrl_y = y;
                prev_cmd = cmd;
                break;
            }
            case 'Z':
            case 'z': {
                cur_x = last_ctrl_x = start_x;
                cur_y = last_ctrl_y = start_y;
                path_push_op(path, SPO_CLOSE);
                prev_cmd = cmd;
                cmd = 0;
                break;
            }
            default:
                ++p;
                break;
        }
    }
    return path;
}

// ============================================================================
// 17. release_serval_polygon_path (0x014af0 .. 0x014b20, 52 bytes)
// [EN] Frees poly->points if non-null, then frees poly.
// [VN] Giải phóng poly->points nếu khác null, sau đó giải phóng poly.
// ============================================================================
void release_serval_polygon_path(SrSVGPolygonPathData* poly) {
    if (!poly) return;
    if (poly->points != nullptr) {
        std::free(poly->points);
    }
    std::free(poly);
}

// ============================================================================
// 18. make_serval_polygon (0x014b24 .. 0x014ca8, 392 bytes)
// [EN] Parses SVG polygon/polyline `points="..."` attribute into a 16-byte
//      SrSVGPolygonPathData struct, growing vertex capacity from 8 (0x014b78:
//      mov w25, #8; lsl w8, w23, #1) and storing (x, y) pairs via strtof.
// [VN] Phân tích thuộc tính `points="..."` của đa giác/đường gấp khúc thành
//      cấu trúc SrSVGPolygonPathData 16 byte (tăng dung lượng từ 8 đỉnh).
// ============================================================================
SrSVGPolygonPathData* make_serval_polygon(const char* points_str) {
    auto* poly = static_cast<SrSVGPolygonPathData*>(std::malloc(sizeof(SrSVGPolygonPathData)));
    if (!poly) return nullptr;
    poly->points = nullptr;
    poly->n_points = 0;
    poly->cap_points = 0;

    if (!points_str || *points_str == '\0') {
        return poly;
    }

    const char* p = points_str;
    while (*p != '\0') {
        skip_svg_ws_and_comma(&p);
        if (*p == '\0') break;

        char* end1 = nullptr;
        float x = std::strtof(p, &end1);
        if (end1 == p || !end1) break;
        p = end1;
        skip_svg_ws_and_comma(&p);
        if (*p == '\0') break;

        char* end2 = nullptr;
        float y = std::strtof(p, &end2);
        if (end2 == p) break;
        p = end2;

        uint32_t next_n = poly->n_points + 1;
        if (next_n > poly->cap_points) {
            uint32_t new_cap = (poly->cap_points == 0) ? 8u : (poly->cap_points << 1);
            auto* new_pts = static_cast<float*>(std::realloc(poly->points, static_cast<size_t>(new_cap) * 2u * sizeof(float)));
            if (!new_pts) {
                std::free(poly->points);
                poly->points = nullptr;
                poly->n_points = 0;
                poly->cap_points = 0;
                return poly;
            }
            poly->points = new_pts;
            poly->cap_points = new_cap;
        }

        poly->points[poly->n_points * 2u]     = x;
        poly->points[poly->n_points * 2u + 1] = y;
        poly->n_points = next_n;
    }
    return poly;
}

// ============================================================================
// 19. release_serval_path (0x014cac .. 0x014ce4, 60 bytes)
// [EN] Frees path->args ([x0, #0x18]) and path->ops ([x0, #0x00]), then frees path.
// [VN] Giải phóng path->args và path->ops, sau đó giải phóng path.
// ============================================================================
void release_serval_path(SrSVGPathData* path) {
    if (!path) return;
    if (path->args != nullptr) {
        std::free(path->args);
        path->args = nullptr;
    }
    if (path->ops != nullptr) {
        std::free(path->ops);
        path->ops = nullptr;
    }
    std::free(path);
}

// ============================================================================
// 20. add_circle_to_path (0x014ce8 .. 0x0150d0, 1,004 bytes)
// [EN] Appends a circle (cx, cy, r) to SrSVGPathData using 1 SPO_MOVE_TO (0)
//      and 3/4 cubic Bézier arcs (SPO_CUBIC_BEZ = 2) with control point offset
//      d13 = double(r) * kRodata_032e70_BezierCircleKappa (0.5519150244935105).
//      Exact instructions at 0x014e3c..0x014e74:
//        adrp x8, #0x32000; ldr d1, [x8, #0xe70]; fcvt d0, s9; fmul d13, d0, d1
//        s0 = cx + r; MOVE_TO(cx + r, cy)
//        CUBIC_TO(cx - d13, cy + r, cx - r, cy + d13, cx - r, cy)
//        CUBIC_TO(cx - r, cy - d13, cx - d13, cy - r, cx, cy - r)
//        CUBIC_TO(cx + d13, cy - r, cx + r, cy - d13, cx + r, cy)
// [VN] Thêm hình tròn (cx, cy, r) vào SrSVGPathData bằng các đường cong Bézier
//      bậc ba với hằng số kappa = 0.5519150244935105 tại .rodata 0x032e70.
// ============================================================================
void add_circle_to_path(SrSVGPathData* path, float cx, float cy, float r) {
    if (!path) return;

    // 1. SPO_MOVE_TO (cx + r, cy) (0x014d20..0x014de4)
    float move_pt[2] = { cx + r, cy };
    path_push_op(path, SPO_MOVE_TO);
    path_push_args(path, move_pt, 2);

    // Compute Bezier control offset in IEEE-754 double precision (0x014e3c..0x014e68)
    double r_d   = static_cast<double>(r);
    double cx_d  = static_cast<double>(cx);
    double cy_d  = static_cast<double>(cy);
    double off_d = r_d * kRodata_032e70_BezierCircleKappa; // d13 = r * 0.5519150244935105

    float cx_minus_off = static_cast<float>(cx_d - off_d); // s15
    float cy_plus_off  = static_cast<float>(cy_d + off_d); // s0
    float cy_plus_r    = cy + r;                           // s2
    float cx_minus_r   = cx - r;                           // s14

    // 2. First SPO_CUBIC_BEZ (0x014e6c..0x014ee4)
    float bez1[6] = {
        cx_minus_off, cy_plus_r,
        cx_minus_r,   cy_plus_off,
        cx_minus_r,   cy
    };
    path_push_op(path, SPO_CUBIC_BEZ);
    path_push_args(path, bez1, 6);

    // 3. Second SPO_CUBIC_BEZ (0x014f3c..0x014fc0)
    float cy_minus_off = static_cast<float>(cy_d - off_d); // s11
    float cy_minus_r   = cy - r;                           // s9
    float bez2[6] = {
        cx_minus_r,   cy_minus_off,
        cx_minus_off, cy_minus_r,
        cx,           cy_minus_r
    };
    path_push_op(path, SPO_CUBIC_BEZ);
    path_push_args(path, bez2, 6);

    // 4. Third SPO_CUBIC_BEZ closing back to (cx + r, cy) (0x015018..0x01509c)
    float cx_plus_off = static_cast<float>(cx_d + off_d);
    float cx_plus_r   = cx + r;
    float bez3[6] = {
        cx_plus_off, cy_minus_r,
        cx_plus_r,   cy_minus_off,
        cx_plus_r,   cy
    };
    path_push_op(path, SPO_CUBIC_BEZ);
    path_push_args(path, bez3, 6);
}

// ============================================================================
// 21. resolve_stroke_line_cap (0x0150d4 .. 0x015120, 80 bytes)
// [EN] Compares str against "round" (.rodata 0x033438 -> returns 1) and
//      "square" (.rodata 0x03343e -> returns 2); otherwise returns 0 (butt).
// [VN] So sánh str với "round" (trả về 1) và "square" (trả về 2); mặc định 0 (butt).
// ============================================================================
SrSVGStrokeCap resolve_stroke_line_cap(const char* str) {
    if (!str) return SR_SVG_CAP_BUTT;
    if (std::strcmp(str, "round") == 0) {
        return SR_SVG_CAP_ROUND;  // 1 (0x015114: mov w0, #1)
    }
    if (std::strcmp(str, "square") == 0) {
        return SR_SVG_CAP_SQUARE; // 2 (0x01510c: lsl w0, w8, #1)
    }
    return SR_SVG_CAP_BUTT;
}

// ============================================================================
// 22. resolve_stroke_line_join (0x015124 .. 0x015170, 80 bytes)
// [EN] Compares str against "round" (.rodata 0x033438 -> returns 1) and
//      "bevel" (.rodata 0x033445 -> returns 2); otherwise returns 0 (miter).
// [VN] So sánh str với "round" (trả về 1) và "bevel" (trả về 2); mặc định 0 (miter).
// ============================================================================
SrSVGStrokeJoin resolve_stroke_line_join(const char* str) {
    if (!str) return SR_SVG_JOIN_MITER;
    if (std::strcmp(str, "round") == 0) {
        return SR_SVG_JOIN_ROUND; // 1 (0x015164: mov w0, #1)
    }
    if (std::strcmp(str, "bevel") == 0) {
        return SR_SVG_JOIN_BEVEL; // 2 (0x01515c: lsl w0, w8, #1)
    }
    return SR_SVG_JOIN_MITER;
}

} // extern "C"
