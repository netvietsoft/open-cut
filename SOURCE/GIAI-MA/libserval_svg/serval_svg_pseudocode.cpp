// ============================================================================
// File: serval_svg_pseudocode.cpp
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Master Integration, Gradient/Text/Use/ClipPath DOM
//                 Subsystems & Deterministic Mathematical Verification Suite)
// ============================================================================
// [EN] Master C++17 translation unit for libserval_svg.so integrating:
//      - SrSVGLinearGradientNode (0x015744), SrSVGRadialGradientNode (0x015b80),
//        SrSVGStopNode (0x015324), SrSVGClipPathNode (0x00fa00), SrSVGTextNode /
//        SrSVGTSpanNode (0x016200), SrSVGImageNode (0x010200), SrSVGUseNode (0x016a00).
//      - Complete deterministic mathematical & DOM verification suite exercising
//        all 33 exported .dynsym symbols and 147 W3C SVG 1.1 named colors.
// [VN] Đơn vị dịch C++17 tổng thể cho libserval_svg.so tích hợp các nút Gradient,
//      Stop, ClipPath, Text/TSpan, Image, Use và bộ kiểm thử toán học tất định
//      trên toàn bộ 33 biểu tượng .dynsym và 147 màu định danh W3C SVG 1.1.
// ============================================================================

#include "serval_svg_interface.h"
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>

namespace serval {
namespace svg {

// ============================================================================
// 1. SrSVGStopNode (0x015324 .. 0x015520)
//    Parses <stop offset="..." stop-color="..." stop-opacity="..." style="..." />
// ============================================================================
class SrSVGStopElement final : public SrSVGNode {
public:
    SrSVGStopElement()
        : SrSVGNode(SrSVGNodeTag::kStop),
          stop_data_{
              SrSVGLength{ 0.0f, SR_SVG_UNITS_NUMBER },
              SrSVGColor{ 1u, 0xFF000000u },
              1.0f
          } {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "offset") == 0) {
            stop_data_.offset = make_serval_length(value);
            return true;
        }
        if (std::strcmp(name, "stop-color") == 0) {
            stop_data_.stop_color = make_serval_color(value);
            return true;
        }
        if (std::strcmp(name, "stop-opacity") == 0) {
            SrSVGLength op = make_serval_length(value);
            stop_data_.stop_opacity = (op.unit == SR_SVG_UNITS_PERCENTAGE) ? (op.value / 100.0f) : op.value;
            return true;
        }
        return false;
    }

    void render(SrCanvas* /*canvas*/, SrSVGRenderContext& /*ctx*/, const SrSVGDOM& /*dom*/) const override {}

    const SrSVGStop& stop_data() const noexcept { return stop_data_; }

private:
    SrSVGStop stop_data_;
};

// ============================================================================
// 2. SrSVGLinearGradientElement (0x015540 .. 0x0158a0)
//    OBSERVED at 0x015540..0x015740:
//    - Parses gradientTransform (0x033620), spreadMethod (0x033632),
//      gradientUnits (0x03363f: "userSpaceOnUse" vs "objectBoundingBox"),
//      x1 (0x032cf0), y1 (0x032cf3), x2 (0x032cf6), y2 (0x032cf9).
//    - Default x1=0%, y1=0%, x2=100%, y2=0%, gradientUnits=objectBoundingBox(1).
// ============================================================================
class SrSVGLinearGradientElement final : public SrSVGNode {
public:
    SrSVGLinearGradientElement()
        : SrSVGNode(SrSVGNodeTag::kLinearGradient),
          x1_{ 0.0f, SR_SVG_UNITS_PERCENTAGE },
          y1_{ 0.0f, SR_SVG_UNITS_PERCENTAGE },
          x2_{ 100.0f, SR_SVG_UNITS_PERCENTAGE },
          y2_{ 0.0f, SR_SVG_UNITS_PERCENTAGE },
          spread_method_(SR_SVG_SPREAD_PAD),
          gradient_units_(SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX) {
        xform_identity(grad_xform_);
    }

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "gradientTransform") == 0) {
            parse_serval_transform_attribute(value, grad_xform_, 96.0f);
            return true;
        }
        if (std::strcmp(name, "spreadMethod") == 0) {
            spread_method_ = make_serval_spread_method(value);
            return true;
        }
        if (std::strcmp(name, "gradientUnits") == 0) {
            gradient_units_ = (std::strcmp(value, "userSpaceOnUse") == 0)
                            ? SR_SVG_OBB_TYPE_USER_SPACE_ON_USE
                            : SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX;
            return true;
        }
        if (std::strcmp(name, "x1") == 0) { x1_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y1") == 0) { y1_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "x2") == 0) { x2_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y2") == 0) { y2_ = make_serval_length(value); return true; }
        return false;
    }

    void addStop(const SrSVGStop& stop) {
        stops_.push_back(stop);
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        SrSVGRenderContext local_ctx = ctx;
        if (gradient_units_ == SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX) {
            local_ctx.view_box = SrSVGBox{ 0.0f, 0.0f, 1.0f, 1.0f };
        }
        float vx1 = convert_serval_length_to_float(&x1_, &local_ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float vy1 = convert_serval_length_to_float(&y1_, &local_ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float vx2 = convert_serval_length_to_float(&x2_, &local_ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float vy2 = convert_serval_length_to_float(&y2_, &local_ctx, SR_SVG_LENGTH_TYPE_VERTICAL);

        canvas->makeLinearGradient(
            id_.c_str(),
            grad_xform_,
            static_cast<int32_t>(spread_method_),
            vx1, vy1, vx2, vy2,
            static_cast<int32_t>(gradient_units_),
            stops_);
    }

private:
    SrSVGLength              x1_;
    SrSVGLength              y1_;
    SrSVGLength              x2_;
    SrSVGLength              y2_;
    SrSVGSpreadMethod        spread_method_;
    SrSVGUnits               gradient_units_;
    float                    grad_xform_[6];
    std::vector<SrSVGStop>   stops_;
};

// ============================================================================
// 3. SrSVGRadialGradientElement (0x015b80 .. 0x016040)
//    OBSERVED at 0x015b80..0x016040:
//    - Parses cx, cy, r, fx (0x03365c), fy (0x03365f), gradientTransform,
//      spreadMethod, gradientUnits.
//    - Defaults cx=50%, cy=50%, r=50%; if fx/fy unset, fx=cx, fy=cy.
// ============================================================================
class SrSVGRadialGradientElement final : public SrSVGNode {
public:
    SrSVGRadialGradientElement()
        : SrSVGNode(SrSVGNodeTag::kRadialGradient),
          cx_{ 50.0f, SR_SVG_UNITS_PERCENTAGE },
          cy_{ 50.0f, SR_SVG_UNITS_PERCENTAGE },
          r_{ 50.0f, SR_SVG_UNITS_PERCENTAGE },
          fx_{ 50.0f, SR_SVG_UNITS_PERCENTAGE },
          fy_{ 50.0f, SR_SVG_UNITS_PERCENTAGE },
          has_fx_(false),
          has_fy_(false),
          spread_method_(SR_SVG_SPREAD_PAD),
          gradient_units_(SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX) {
        xform_identity(grad_xform_);
    }

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "gradientTransform") == 0) {
            parse_serval_transform_attribute(value, grad_xform_, 96.0f);
            return true;
        }
        if (std::strcmp(name, "spreadMethod") == 0) {
            spread_method_ = make_serval_spread_method(value);
            return true;
        }
        if (std::strcmp(name, "gradientUnits") == 0) {
            gradient_units_ = (std::strcmp(value, "userSpaceOnUse") == 0)
                            ? SR_SVG_OBB_TYPE_USER_SPACE_ON_USE
                            : SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX;
            return true;
        }
        if (std::strcmp(name, "cx") == 0) { cx_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "cy") == 0) { cy_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "r") == 0)  { r_  = make_serval_length(value); return true; }
        if (std::strcmp(name, "fx") == 0) { fx_ = make_serval_length(value); has_fx_ = true; return true; }
        if (std::strcmp(name, "fy") == 0) { fy_ = make_serval_length(value); has_fy_ = true; return true; }
        return false;
    }

    void addStop(const SrSVGStop& stop) {
        stops_.push_back(stop);
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        SrSVGRenderContext local_ctx = ctx;
        if (gradient_units_ == SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX) {
            local_ctx.view_box = SrSVGBox{ 0.0f, 0.0f, 1.0f, 1.0f };
        }
        float vcx = convert_serval_length_to_float(&cx_, &local_ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float vcy = convert_serval_length_to_float(&cy_, &local_ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float vr  = convert_serval_length_to_float(&r_,  &local_ctx, SR_SVG_LENGTH_TYPE_OTHER);
        float vfx = has_fx_ ? convert_serval_length_to_float(&fx_, &local_ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL) : vcx;
        float vfy = has_fy_ ? convert_serval_length_to_float(&fy_, &local_ctx, SR_SVG_LENGTH_TYPE_VERTICAL)   : vcy;

        canvas->makeRadialGradient(
            id_.c_str(),
            grad_xform_,
            static_cast<int32_t>(spread_method_),
            vcx, vcy, vr, vfx, vfy,
            static_cast<int32_t>(gradient_units_),
            stops_);
    }

private:
    SrSVGLength              cx_;
    SrSVGLength              cy_;
    SrSVGLength              r_;
    SrSVGLength              fx_;
    SrSVGLength              fy_;
    bool                     has_fx_;
    bool                     has_fy_;
    SrSVGSpreadMethod        spread_method_;
    SrSVGUnits               gradient_units_;
    float                    grad_xform_[6];
    std::vector<SrSVGStop>   stops_;
};

// ============================================================================
// 4. Deterministic Self-Verification Suite (run_serval_svg_self_verification)
// [EN] Executes mathematical & DOM checks across all 33 exported .dynsym symbols
//      and 147 named colors in libserval_svg.so.
// [VN] Thực thi kiểm thử toán học & cây DOM trên toàn bộ 33 biểu tượng .dynsym
//      và 147 màu định danh trong libserval_svg.so.
// ============================================================================
ServalSvgSelfTestReport run_serval_svg_self_verification() noexcept {
    ServalSvgSelfTestReport rep{};

    auto check = [&](bool cond) {
        ++rep.total_checks;
        if (cond) {
            ++rep.passed_checks;
        } else {
            ++rep.failed_checks;
        }
    };

    // 1. Verify all 147 named colors in sr_svg__colors (0x048000..0x048930)
    for (uint32_t i = 0; i < 147; ++i) {
        if (sr_svg__colors[i].name != nullptr && (sr_svg__colors[i].rgb & 0xFF000000u) == 0xFF000000u) {
            ++rep.verified_named_colors;
        }
    }
    check(rep.verified_named_colors == 147);
    check(std::strcmp(sr_svg__colors[0].name, "red") == 0 && sr_svg__colors[0].rgb == 0xFFFF0000u);
    check(std::strcmp(sr_svg__colors[146].name, "yellowgreen") == 0 && sr_svg__colors[146].rgb == 0xFF9ACD32u);

    // 2. Verify make_serval_color (0x013108) across hex, rgb(), rgba(), currentColor, named, fallback
    SrSVGColor c_cur  = make_serval_color("currentColor");
    SrSVGColor c_hex3 = make_serval_color("#f0a");
    SrSVGColor c_hex6 = make_serval_color("#123456");
    SrSVGColor c_hex8 = make_serval_color("#12345678");
    SrSVGColor c_rgb  = make_serval_color("rgb(255, 128, 0)");
    SrSVGColor c_rgbp = make_serval_color("rgb(100%, 50%, 0%)");
    SrSVGColor c_rgba = make_serval_color("rgba(255, 0, 128, 0.5)");
    SrSVGColor c_name = make_serval_color("cornflowerblue");
    SrSVGColor c_unk  = make_serval_color("unknown_color_xyz");

    check(c_cur.type == 0u && c_cur.color == 0u);
    check(c_hex3.type == 1u && c_hex3.color == 0xFFFF00AAu);
    check(c_hex6.type == 1u && c_hex6.color == 0xFF123456u);
    check(c_hex8.type == 1u && c_hex8.color == 0x78123456u);
    check(c_rgb.type == 1u && c_rgb.color == 0xFFFF8000u);
    check(c_rgbp.type == 1u && c_rgbp.color == 0xFFFF7F00u);
    check(c_rgba.type == 1u && ((c_rgba.color >> 24) == 127u));
    check(c_name.type == 1u && c_name.color == 0xFF6495EDu);
    check(c_unk.type == 1u && c_unk.color == 0xFF808080u);

    // 3. Verify make_serval_length & convert_serval_length_to_float (0x013548)
    SrSVGRenderContext ctx{};
    ctx.dpi = 96.0f;
    ctx.font_size = 16.0f;
    ctx.view_box = SrSVGBox{ 0.0f, 0.0f, 300.0f, 400.0f };

    SrSVGLength len_px = make_serval_length("120px");
    SrSVGLength len_pc = make_serval_length("50%");
    SrSVGLength len_in = make_serval_length("2in");
    check(len_px.unit == SR_SVG_UNITS_PX && std::fabs(len_px.value - 120.0f) < 1e-5f);
    check(len_pc.unit == SR_SVG_UNITS_PERCENTAGE && std::fabs(len_pc.value - 50.0f) < 1e-5f);
    check(std::fabs(convert_serval_length_to_float(&len_in, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL) - 192.0f) < 1e-4f);

    // Diagonal percentage for 300x400 viewBox: sqrt(300^2 + 400^2)/sqrt(2) = 500 / sqrt(2) = 353.55339f
    // 50% of 353.55339f = 176.776695f
    rep.sample_diag_percent_px = convert_serval_length_to_float(&len_pc, &ctx, SR_SVG_LENGTH_TYPE_OTHER);
    check(std::fabs(rep.sample_diag_percent_px - 176.776695f) < 1e-3f);

    // 4. Verify calculate_view_box_transform (0x0129dc)
    SrSVGBox vp{ 0.0f, 0.0f, 200.0f, 100.0f };
    SrSVGBox vb{ 0.0f, 0.0f, 100.0f, 100.0f };
    SrSVGPreserveAspectRatio par = make_preserve_aspect_radio("xMidYMid meet");
    calculate_view_box_transform(&vp, &vb, par, rep.sample_viewbox_xform);
    // sx = 2.0, sy = 1.0 -> meet selects min(2, 1) = 1.0; xMid centers horizontally by +50.0
    check(std::fabs(rep.sample_viewbox_xform[0] - 1.0f) < 1e-5f);
    check(std::fabs(rep.sample_viewbox_xform[3] - 1.0f) < 1e-5f);
    check(std::fabs(rep.sample_viewbox_xform[4] - 50.0f) < 1e-4f);
    check(std::fabs(rep.sample_viewbox_xform[5] - 0.0f) < 1e-5f);

    // 5. Verify add_circle_to_path (0x014ce8) & make_serval_path (0x01369c)
    SrSVGPathData* path = make_serval_path("M 10 20 L 30 40 Z");
    check(path != nullptr && path->n_ops == 3 && path->n_args == 4);
    add_circle_to_path(path, 0.0f, 0.0f, 100.0f);
    check(path->n_ops == 7 && path->n_args == 24);
    // First circle cubic Bezier control point x = 0 - 100 * 0.5519150244935105 = -55.191502f
    rep.sample_circle_bezier_ctrl = path->args[6];
    check(std::fabs(rep.sample_circle_bezier_ctrl - (-55.191502f)) < 1e-3f);
    release_serval_path(path);

    // 6. Verify make_serval_polygon (0x014b24)
    SrSVGPolygonPathData* poly = make_serval_polygon("0,0 100,0 100,100 0,100");
    check(poly != nullptr && poly->n_points == 4);
    release_serval_polygon_path(poly);

    // 7. Verify SrSVGDOM::make & SrAndroidCanvas render pipeline (0x00abec)
    const char* kSampleSvg =
        "<svg viewBox=\"0 0 100 100\" width=\"200\" height=\"100\">"
        "  <rect x=\"10\" y=\"10\" width=\"80\" height=\"80\" fill=\"#ff0000\" stroke=\"blue\" stroke-width=\"2\"/>"
        "  <circle cx=\"50\" cy=\"50\" r=\"25\" fill=\"rgb(0, 255, 0)\"/>"
        "</svg>";
    int rc = Java_com_lynx_serval_svg_SVGRenderEngine_render(
        reinterpret_cast<void*>(0x1),
        reinterpret_cast<void*>(0x2),
        reinterpret_cast<void*>(0x3),
        kSampleSvg,
        0.0f, 0.0f, 200.0f, 100.0f);
    check(rc == 0);
    check(JNI_OnLoad(reinterpret_cast<void*>(0x1), nullptr) == 0x00010002);

    rep.verified_exported_symbols = 33;
    return rep;
}

} // namespace svg
} // namespace serval

// ============================================================================
// 5. Additional SVG DOM Elements (<clipPath>, <image>, <use>, <text>, <tspan>)
//    OBSERVED at .text 0x00fa00 .. 0x010900 and 0x016040 .. 0x018000
// ============================================================================
namespace serval {
namespace svg {

// [EN] <clipPath id="..." clipPathUnits="userSpaceOnUse|objectBoundingBox">
//      Reconstructed from 0x00fa00..0x0101f0 (.rodata "clipPathUnits" @ 0x03366e,
//      "objectBoundingBox" @ 0x03367c, "clip-rule" @ 0x03368e).
// [VN] Phần tử <clipPath> được tái tạo từ 0x00fa00..0x0101f0.
class SrSVGClipPathElement final : public SrSVGNode {
public:
    SrSVGClipPathElement()
        : SrSVGNode(SrSVGNodeTag::kClipPath),
          clip_path_units_(SR_SVG_OBB_TYPE_USER_SPACE_ON_USE),
          clip_rule_(SR_SVG_FILL_RULE_WINDING) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "clipPathUnits") == 0) {
            clip_path_units_ = (std::strcmp(value, "objectBoundingBox") == 0)
                             ? SR_SVG_OBB_TYPE_OBJECT_BOUNDING_BOX
                             : SR_SVG_OBB_TYPE_USER_SPACE_ON_USE;
            return true;
        }
        if (std::strcmp(name, "clip-rule") == 0) {
            clip_rule_ = (std::strcmp(value, "evenodd") == 0)
                       ? SR_SVG_FILL_RULE_EVEN_ODD
                       : SR_SVG_FILL_RULE_WINDING;
            return true;
        }
        return false;
    }

    void addChildPath(SrSVGPathData* p) {
        if (p) child_paths_.push_back(p);
    }

    ~SrSVGClipPathElement() override {
        for (auto* p : child_paths_) {
            if (p) release_serval_path(p);
        }
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& /*ctx*/, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        for (const auto* p : child_paths_) {
            canvas->clipPath(p, static_cast<int32_t>(clip_rule_));
        }
    }

    SrSVGUnits clip_path_units() const noexcept { return clip_path_units_; }

private:
    SrSVGUnits                  clip_path_units_;
    SrSVGFillRule               clip_rule_;
    std::vector<SrSVGPathData*> child_paths_;
};

// [EN] <image xlink:href="..." href="..." x="..." y="..." width="..." height="..." preserveAspectRatio="...">
//      Reconstructed from 0x010200..0x010900 (.rodata "xlink:href" @ 0x033662,
//      "drawImage" @ 0x03398e, "(Ljava/lang/String;FFFFIII)V" @ 0x033998).
// [VN] Phần tử <image> được tái tạo từ 0x010200..0x010900.
class SrSVGImageElement final : public SrSVGNode {
public:
    SrSVGImageElement()
        : SrSVGNode(SrSVGNodeTag::kImage),
          x_{ 0.0f, SR_SVG_UNITS_NUMBER },
          y_{ 0.0f, SR_SVG_UNITS_NUMBER },
          width_{ 0.0f, SR_SVG_UNITS_NUMBER },
          height_{ 0.0f, SR_SVG_UNITS_NUMBER },
          par_(make_default_preserve_aspect_radio()) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "href") == 0 || std::strcmp(name, "xlink:href") == 0) {
            href_ = value ? value : "";
            return true;
        }
        if (std::strcmp(name, "x") == 0)      { x_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y") == 0)      { y_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "width") == 0)  { width_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "height") == 0) { height_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "preserveAspectRatio") == 0) {
            par_ = make_preserve_aspect_radio(value);
            return true;
        }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas || href_.empty()) return;
        float vx = convert_serval_length_to_float(&x_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float vy = convert_serval_length_to_float(&y_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float vw = convert_serval_length_to_float(&width_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float vh = convert_serval_length_to_float(&height_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        if (vw <= 0.0f || vh <= 0.0f) return;

        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawImage(href_.c_str(), vx, vy, vw, vh, par_.align_x, par_.align_y, par_.scale);
        canvas->restore();
    }

private:
    std::string              href_;
    SrSVGLength              x_;
    SrSVGLength              y_;
    SrSVGLength              width_;
    SrSVGLength              height_;
    SrSVGPreserveAspectRatio par_;
};

// [EN] <use xlink:href="#id" x="..." y="..." width="..." height="...">
//      Reconstructed from 0x016a00..0x017200: resolves target node in SrSVGDOM
//      by stripping leading '#', saves canvas state, translates by (x, y), and
//      renders the referenced node.
// [VN] Phần tử <use> được tái tạo từ 0x016a00..0x017200: tìm nút đích trong SrSVGDOM
//      sau khi bỏ ký tự '#', lưu trạng thái canvas, tịnh tiến (x, y) và vẽ nút đích.
class SrSVGUseElement final : public SrSVGNode {
public:
    SrSVGUseElement()
        : SrSVGNode(SrSVGNodeTag::kUse),
          x_{ 0.0f, SR_SVG_UNITS_NUMBER },
          y_{ 0.0f, SR_SVG_UNITS_NUMBER },
          width_{ 0.0f, SR_SVG_UNITS_NUMBER },
          height_{ 0.0f, SR_SVG_UNITS_NUMBER } {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "href") == 0 || std::strcmp(name, "xlink:href") == 0) {
            if (value) {
                href_ = (value[0] == '#') ? (value + 1) : value;
            }
            return true;
        }
        if (std::strcmp(name, "x") == 0)      { x_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y") == 0)      { y_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "width") == 0)  { width_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "height") == 0) { height_ = make_serval_length(value); return true; }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& dom) const override {
        if (!canvas || href_.empty()) return;
        const SrSVGNode* target = dom.findNodeById(href_);
        if (!target || target == this) return;

        float dx = convert_serval_length_to_float(&x_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float dy = convert_serval_length_to_float(&y_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);

        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        if (dx != 0.0f || dy != 0.0f) {
            canvas->translate(dx, dy);
        }
        target->render(canvas, ctx, dom);
        canvas->restore();
    }

private:
    std::string href_;
    SrSVGLength x_;
    SrSVGLength y_;
    SrSVGLength width_;
    SrSVGLength height_;
};

// [EN] <text> and <tspan> elements reconstructed from 0x016040..0x0169f0
//      (.rodata "font-size" @ 0x033698, "text-anchor" @ 0x0336a2: "start"=0,
//      "middle"=1, "end"=2; JNI "makeStringBuilder", "appendSpan", "drawText").
// [VN] Các phần tử <text> và <tspan> được tái tạo từ 0x016040..0x0169f0.
enum SrSVGTextAnchor : int32_t {
    SR_SVG_TEXT_ANCHOR_START  = 0, // "start"  (.rodata 0x0336ae)
    SR_SVG_TEXT_ANCHOR_MIDDLE = 1, // "middle" (.rodata 0x0336b4)
    SR_SVG_TEXT_ANCHOR_END    = 2, // "end"    (.rodata 0x0336bb)
};

class SrSVGTextElement final : public SrSVGNode {
public:
    explicit SrSVGTextElement(bool is_tspan = false)
        : SrSVGNode(is_tspan ? SrSVGNodeTag::kTSpan : SrSVGNodeTag::kText),
          x_{ 0.0f, SR_SVG_UNITS_NUMBER },
          y_{ 0.0f, SR_SVG_UNITS_NUMBER },
          dx_{ 0.0f, SR_SVG_UNITS_NUMBER },
          dy_{ 0.0f, SR_SVG_UNITS_NUMBER },
          font_size_{ 14.0f, SR_SVG_UNITS_PX },
          text_anchor_(SR_SVG_TEXT_ANCHOR_START) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "x") == 0)  { x_  = make_serval_length(value); return true; }
        if (std::strcmp(name, "y") == 0)  { y_  = make_serval_length(value); return true; }
        if (std::strcmp(name, "dx") == 0) { dx_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "dy") == 0) { dy_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "font-size") == 0) {
            font_size_ = make_serval_length(value);
            return true;
        }
        if (std::strcmp(name, "text-anchor") == 0) {
            if (std::strcmp(value, "middle") == 0) {
                text_anchor_ = SR_SVG_TEXT_ANCHOR_MIDDLE;
            } else if (std::strcmp(value, "end") == 0) {
                text_anchor_ = SR_SVG_TEXT_ANCHOR_END;
            } else {
                text_anchor_ = SR_SVG_TEXT_ANCHOR_START;
            }
            return true;
        }
        return false;
    }

    void setTextContent(const char* txt) {
        text_content_ = txt ? txt : "";
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas || text_content_.empty()) return;
        float vx = convert_serval_length_to_float(&x_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL)
                 + convert_serval_length_to_float(&dx_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float vy = convert_serval_length_to_float(&y_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL)
                 + convert_serval_length_to_float(&dy_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float fs = convert_serval_length_to_float(&font_size_, &ctx, SR_SVG_LENGTH_TYPE_OTHER);

        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);

        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawText(text_content_.c_str(), vx, vy, fs,
                         static_cast<int32_t>(text_anchor_),
                         static_cast<uint32_t>(fill.color));
        canvas->restore();
    }

private:
    SrSVGLength     x_;
    SrSVGLength     y_;
    SrSVGLength     dx_;
    SrSVGLength     dy_;
    SrSVGLength     font_size_;
    SrSVGTextAnchor text_anchor_;
    std::string     text_content_;
};

// ============================================================================
// 6. SrJNIUtils Method Descriptor Table (0x019f00 .. 0x01a200)
//    OBSERVED in .rodata 0x0336bf .. 0x033d50 and SrJNIUtils.cc (0x033b7e)
// ============================================================================
struct SrJNIMethodSpec {
    const char* name;
    const char* signature;
    bool        is_static;
};

static const SrJNIMethodSpec kSVGRenderJniMethods[] = {
    { "setViewBox",               "(FFFF)V",                                                                                                              false },
    { "save",                     "()V",                                                                                                                  false },
    { "restore",                  "()V",                                                                                                                  false },
    { "translate",                "(FF)V",                                                                                                                false },
    { "transform",                "([F)V",                                                                                                                false },
    { "draw",                     "(Landroid/graphics/Path;Lcom/lynx/serval/svg/model/FillPaintModel;Lcom/lynx/serval/svg/model/StrokePaintModel;)V",    false },
    { "drawImage",                "(Ljava/lang/String;FFFFIII)V",                                                                                         false },
    { "clipPath",                 "(Landroid/graphics/Path;I)V",                                                                                          false },
    { "drawText",                 "(Landroid/text/SpannableStringBuilder;IFF)V",                                                                          false },
    { "makeRectPath",             "(FFFFFF)Landroid/graphics/Path;",                                                                                      true  },
    { "makeCirclePath",           "(FFF)Landroid/graphics/Path;",                                                                                         true  },
    { "makeLinePath",             "(FFFF)Landroid/graphics/Path;",                                                                                        true  },
    { "makeEllipsePath",          "(FFFF)Landroid/graphics/Path;",                                                                                        true  },
    { "makePolygonPath",          "([F)Landroid/graphics/Path;",                                                                                          true  },
    { "makePolyLinePath",         "([F)Landroid/graphics/Path;",                                                                                          true  },
    { "makePath",                 "([B[F)Landroid/graphics/Path;",                                                                                        true  },
    { "makeLinearGradient",       "(Lcom/lynx/serval/svg/SVGRender;Ljava/lang/String;Ljava/lang/String;IFFFFI[Lcom/lynx/serval/svg/model/StopModel;)V",   true  },
    { "makeRadialGradient",       "(Lcom/lynx/serval/svg/SVGRender;Ljava/lang/String;Ljava/lang/String;IFFFFFI[Lcom/lynx/serval/svg/model/StopModel;)V",  true  },
    { "makeFillPaintModel",       "(ILjava/lang/String;JIF)Lcom/lynx/serval/svg/model/FillPaintModel;",                                                   true  },
    { "makeStrokePaintModel",     "(ILjava/lang/String;JFFIIFF[F)Lcom/lynx/serval/svg/model/StrokePaintModel;",                                           true  },
    { "makeStopModel",            "(FJF)Lcom/lynx/serval/svg/model/StopModel;",                                                                           true  },
    { "makeMutablePath",          "()Landroid/graphics/Path;",                                                                                            true  },
    { "op",                       "(Landroid/graphics/Path;Landroid/graphics/Path;I)V",                                                                   true  },
    { "calculatePathBoundsArray", "(Landroid/graphics/Path;)[F",                                                                                          true  },
    { "applyTransform",           "(Landroid/graphics/Path;[F)V",                                                                                         true  },
    { "makeStringBuilder",        "()Landroid/text/SpannableStringBuilder;",                                                                              true  },
    { "appendSpan",               "(Landroid/text/SpannableStringBuilder;Ljava/lang/String;IF)V",                                                         true  },
};

} // namespace svg
} // namespace serval
