// ============================================================================
// File: serval_svg_dom_and_jni.cpp
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Direct Binary Disassembly of .text 0x00ab2c..0x0126cc
//                 and 0x015324..0x01a200)
// ============================================================================
// [EN] Clean-room C++17 implementation of Serval SVG DOM Tree Builder,
//      Presentation & CSS Style Attribute Inheritance, SrAndroidCanvas JNI
//      command dispatcher, and JNI_OnLoad / SVGRenderEngine native methods.
// [VN] Bản thực thi C++17 clean-room của Bộ dựng cây Serval SVG DOM, kế thừa
//      thuộc tính trình bày & CSS, bộ điều phối lệnh JNI SrAndroidCanvas, và
//      các phương thức native JNI_OnLoad / SVGRenderEngine.
// ============================================================================

#include "serval_svg_dom_and_jni.h"
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>

namespace serval {
namespace svg {

// ============================================================================
// 1. SrAndroidCanvas Implementation (0x0158a0 .. 0x019f00)
//    Dispatches drawing commands to com/lynx/serval/svg/SVGRender methods
//    (.rodata 0x0336bf..0x033d50) and records them for deterministic verification.
// ============================================================================
SrAndroidCanvas::SrAndroidCanvas(void* jni_env, void* render_engine_obj, void* svg_render_obj)
    : jni_env_(jni_env),
      render_engine_obj_(render_engine_obj),
      svg_render_obj_(svg_render_obj),
      active_view_box_{ 0.0f, 0.0f, 0.0f, 0.0f } {}

void SrAndroidCanvas::setViewBox(float left, float top, float width, float height) {
    active_view_box_ = SrSVGBox{ left, top, width, height };
    SrCanvasDrawRecord rec{};
    rec.op_name = "setViewBox";
    rec.params  = { left, top, width, height };
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::save() {
    SrCanvasDrawRecord rec{};
    rec.op_name = "save";
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::restore() {
    SrCanvasDrawRecord rec{};
    rec.op_name = "restore";
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::translate(float dx, float dy) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "translate";
    rec.params  = { dx, dy };
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::transform(const float xform[6]) {
    if (!xform) return;
    SrCanvasDrawRecord rec{};
    rec.op_name = "transform";
    rec.params.assign(xform, xform + 6);
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::clipPath(const SrSVGPathData* path, int32_t clip_rule) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "clipPath";
    rec.params  = { static_cast<float>(clip_rule),
                    path ? static_cast<float>(path->n_ops) : 0.0f };
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawRect(float x, float y, float rx, float ry, float width, float height,
                               const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "makeRectPath+draw";
    rec.params  = { x, y, rx, ry, width, height };
    if (fill)   rec.fill = *fill;
    if (stroke) rec.stroke = *stroke;
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawCircle(float cx, float cy, float r,
                                 const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "makeCirclePath+draw";
    rec.params  = { cx, cy, r };
    if (fill)   rec.fill = *fill;
    if (stroke) rec.stroke = *stroke;
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawEllipse(float cx, float cy, float rx, float ry,
                                  const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "makeEllipsePath+draw";
    rec.params  = { cx, cy, rx, ry };
    if (fill)   rec.fill = *fill;
    if (stroke) rec.stroke = *stroke;
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawLine(float x1, float y1, float x2, float y2,
                               const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "makeLinePath+draw";
    rec.params  = { x1, y1, x2, y2 };
    if (fill)   rec.fill = *fill;
    if (stroke) rec.stroke = *stroke;
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawPolygon(const float* pts, uint32_t n_floats, bool close_path,
                                  const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) {
    SrCanvasDrawRecord rec{};
    rec.op_name = close_path ? "makePolygonPath+draw" : "makePolyLinePath+draw";
    if (pts && n_floats > 0) {
        rec.params.assign(pts, pts + n_floats);
    }
    if (fill)   rec.fill = *fill;
    if (stroke) rec.stroke = *stroke;
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawPath(const SrSVGPathData* path,
                               const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "makePath+draw";
    if (path && path->args && path->n_args > 0) {
        rec.params.assign(path->args, path->args + path->n_args);
    }
    if (fill)   rec.fill = *fill;
    if (stroke) rec.stroke = *stroke;
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawImage(const char* /*href*/, float x, float y, float w, float h,
                                int32_t align_x, int32_t align_y, int32_t scale) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "drawImage";
    rec.params  = { x, y, w, h,
                    static_cast<float>(align_x),
                    static_cast<float>(align_y),
                    static_cast<float>(scale) };
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::drawText(const char* /*text*/, float x, float y, float font_size,
                               int32_t text_anchor, uint32_t argb_color) {
    SrCanvasDrawRecord rec{};
    rec.op_name = "drawText";
    rec.params  = { x, y, font_size, static_cast<float>(text_anchor), static_cast<float>(argb_color) };
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::makeLinearGradient(const char* id, const float xform[6], int32_t spread_method,
                                         float x1, float y1, float x2, float y2, int32_t gradient_units,
                                         const std::vector<SrSVGStop>& stops) {
    SrCanvasDrawRecord rec{};
    rec.op_name = std::string("makeLinearGradient:") + (id ? id : "");
    rec.params  = { x1, y1, x2, y2,
                    static_cast<float>(spread_method),
                    static_cast<float>(gradient_units),
                    static_cast<float>(stops.size()) };
    if (xform) {
        rec.params.insert(rec.params.end(), xform, xform + 6);
    }
    commands_.push_back(std::move(rec));
}

void SrAndroidCanvas::makeRadialGradient(const char* id, const float xform[6], int32_t spread_method,
                                         float cx, float cy, float r, float fx, float fy, int32_t gradient_units,
                                         const std::vector<SrSVGStop>& stops) {
    SrCanvasDrawRecord rec{};
    rec.op_name = std::string("makeRadialGradient:") + (id ? id : "");
    rec.params  = { cx, cy, r, fx, fy,
                    static_cast<float>(spread_method),
                    static_cast<float>(gradient_units),
                    static_cast<float>(stops.size()) };
    if (xform) {
        rec.params.insert(rec.params.end(), xform, xform + 6);
    }
    commands_.push_back(std::move(rec));
}

// ============================================================================
// 2. SrSVGNode Presentation & Style Attribute Parser (0x010a00 .. 0x0126b0)
//    Parses id, fill, stroke, stroke-width, stroke-dasharray, stroke-dashoffset,
//    stroke-linecap, stroke-linejoin, stroke-miterlimit, fill-opacity,
//    stroke-opacity, opacity, fill-rule, clip-rule, clip-path, color,
//    transform, and inline CSS style="key:val;...".
// ============================================================================
bool SrSVGNode::parseAndSetAttribute(const char* name, const char* value) {
    if (!name || !value) return false;

    if (std::strcmp(name, "id") == 0) {
        id_ = value;
        return true;
    }
    if (std::strcmp(name, "fill") == 0) {
        if (style_.fill) release_serval_paint(style_.fill);
        style_.fill = make_serval_paint(value);
        style_.has_fill = true;
        return true;
    }
    if (std::strcmp(name, "stroke") == 0) {
        if (style_.stroke) release_serval_paint(style_.stroke);
        style_.stroke = make_serval_paint(value);
        style_.has_stroke = true;
        return true;
    }
    if (std::strcmp(name, "stroke-width") == 0) {
        style_.stroke_width = make_serval_length(value);
        style_.has_stroke_width = true;
        return true;
    }
    if (std::strcmp(name, "stroke-linecap") == 0) {
        style_.stroke_cap = resolve_stroke_line_cap(value);
        style_.has_stroke_cap = true;
        return true;
    }
    if (std::strcmp(name, "stroke-linejoin") == 0) {
        style_.stroke_join = resolve_stroke_line_join(value);
        style_.has_stroke_join = true;
        return true;
    }
    if (std::strcmp(name, "stroke-miterlimit") == 0) {
        style_.miter_limit = std::strtof(value, nullptr);
        style_.has_miter_limit = true;
        return true;
    }
    if (std::strcmp(name, "stroke-dashoffset") == 0) {
        style_.dash_offset = make_serval_length(value);
        style_.has_dash_offset = true;
        return true;
    }
    if (std::strcmp(name, "stroke-dasharray") == 0) {
        style_.dash_array.clear();
        if (std::strcmp(value, "none") != 0) {
            char buf[256];
            std::strncpy(buf, value, sizeof(buf) - 1);
            buf[sizeof(buf) - 1] = '\0';
            char* save_ptr = nullptr;
            char* tok = strtok_r(buf, " ,;\t\n", &save_ptr);
            while (tok != nullptr) {
                style_.dash_array.push_back(make_serval_length(tok));
                tok = strtok_r(nullptr, " ,;\t\n", &save_ptr);
            }
        }
        style_.has_dash_array = true;
        return true;
    }
    if (std::strcmp(name, "fill-opacity") == 0) {
        SrSVGLength len = make_serval_length(value);
        style_.fill_opacity = (len.unit == SR_SVG_UNITS_PERCENTAGE) ? (len.value / 100.0f) : len.value;
        style_.has_fill_opacity = true;
        return true;
    }
    if (std::strcmp(name, "stroke-opacity") == 0) {
        SrSVGLength len = make_serval_length(value);
        style_.stroke_opacity = (len.unit == SR_SVG_UNITS_PERCENTAGE) ? (len.value / 100.0f) : len.value;
        style_.has_stroke_opacity = true;
        return true;
    }
    if (std::strcmp(name, "opacity") == 0) {
        SrSVGLength len = make_serval_length(value);
        style_.opacity = (len.unit == SR_SVG_UNITS_PERCENTAGE) ? (len.value / 100.0f) : len.value;
        style_.has_opacity = true;
        return true;
    }
    if (std::strcmp(name, "fill-rule") == 0) {
        style_.fill_rule = (std::strcmp(value, "evenodd") == 0)
                         ? SR_SVG_FILL_RULE_EVEN_ODD
                         : SR_SVG_FILL_RULE_WINDING;
        style_.has_fill_rule = true;
        return true;
    }
    if (std::strcmp(name, "clip-rule") == 0) {
        style_.clip_rule = (std::strcmp(value, "evenodd") == 0)
                         ? SR_SVG_FILL_RULE_EVEN_ODD
                         : SR_SVG_FILL_RULE_WINDING;
        style_.has_clip_rule = true;
        return true;
    }
    if (std::strcmp(name, "color") == 0) {
        style_.color = make_serval_color(value);
        style_.has_color = true;
        return true;
    }
    if (std::strcmp(name, "clip-path") == 0) {
        SrSVGPaint* cp = make_serval_paint(value);
        if (cp) {
            if (cp->type == SR_SVG_PAINT_IRI && cp->iri) {
                style_.clip_path_iri = cp->iri;
            }
            release_serval_paint(cp);
        }
        return true;
    }
    if (std::strcmp(name, "transform") == 0) {
        parse_serval_transform_attribute(value, style_.xform, 96.0f);
        style_.has_transform = true;
        return true;
    }
    if (std::strcmp(name, "style") == 0) {
        // Inline CSS style="prop1:val1; prop2:val2" parser (0x0116b0..0x011900)
        std::string css(value);
        size_t pos = 0;
        while (pos < css.size()) {
            size_t semi = css.find(';', pos);
            if (semi == std::string::npos) semi = css.size();
            size_t colon = css.find(':', pos);
            if (colon != std::string::npos && colon < semi) {
                std::string k = css.substr(pos, colon - pos);
                std::string v = css.substr(colon + 1, semi - (colon + 1));
                auto trim = [](std::string& s) {
                    size_t b = 0;
                    while (b < s.size() && std::isspace(static_cast<unsigned char>(s[b]))) ++b;
                    size_t e = s.size();
                    while (e > b && std::isspace(static_cast<unsigned char>(s[e - 1]))) --e;
                    s = s.substr(b, e - b);
                };
                trim(k);
                trim(v);
                if (!k.empty() && !v.empty()) {
                    parseAndSetAttribute(k.c_str(), v.c_str());
                }
            }
            pos = semi + 1;
        }
        return true;
    }
    return false;
}

void SrSVGNode::resolvePaintModels(const SrSVGRenderContext& ctx,
                                   SrFillPaintModel& out_fill,
                                   SrStrokePaintModel& out_stroke) const {
    float eff_opacity = style_.has_opacity ? style_.opacity : 1.0f;

    // Default SVG fill is solid black (#000000) unless fill="none"
    out_fill.type = SR_SVG_PAINT_COLOR;
    out_fill.color = 0xFF000000u;
    out_fill.fill_rule = static_cast<int32_t>(style_.fill_rule);
    out_fill.fill_opacity = style_.fill_opacity * eff_opacity;

    if (style_.has_fill && style_.fill != nullptr) {
        out_fill.type = static_cast<int32_t>(style_.fill->type);
        if (style_.fill->type == SR_SVG_PAINT_COLOR) {
            uint32_t c = (style_.fill->color.type == 0u) ? style_.color.color : style_.fill->color.color;
            out_fill.color = c;
        } else if (style_.fill->type == SR_SVG_PAINT_IRI && style_.fill->iri != nullptr) {
            out_fill.iri = style_.fill->iri;
        }
    }

    // Default SVG stroke is none
    out_stroke.type = SR_SVG_PAINT_NONE;
    out_stroke.color = 0u;
    out_stroke.width = convert_serval_length_to_float(&style_.stroke_width, &ctx, SR_SVG_LENGTH_TYPE_OTHER);
    out_stroke.stroke_opacity = style_.stroke_opacity * eff_opacity;
    out_stroke.stroke_line_cap = static_cast<int32_t>(style_.stroke_cap);
    out_stroke.stroke_line_join = static_cast<int32_t>(style_.stroke_join);
    out_stroke.stroke_miter_limit = style_.miter_limit;
    out_stroke.stroke_dash_offset = convert_serval_length_to_float(&style_.dash_offset, &ctx, SR_SVG_LENGTH_TYPE_OTHER);
    out_stroke.dash_array.clear();
    for (const auto& dlen : style_.dash_array) {
        out_stroke.dash_array.push_back(convert_serval_length_to_float(&dlen, &ctx, SR_SVG_LENGTH_TYPE_OTHER));
    }

    if (style_.has_stroke && style_.stroke != nullptr) {
        out_stroke.type = static_cast<int32_t>(style_.stroke->type);
        if (style_.stroke->type == SR_SVG_PAINT_COLOR) {
            uint32_t c = (style_.stroke->color.type == 0u) ? style_.color.color : style_.stroke->color.color;
            out_stroke.color = c;
        } else if (style_.stroke->type == SR_SVG_PAINT_IRI && style_.stroke->iri != nullptr) {
            out_stroke.iri = style_.stroke->iri;
        }
    }
}

// ============================================================================
// 3. Concrete SVG Element Subclasses (<svg>, <g>, <rect>, <circle>, <ellipse>,
//    <line>, <polyline>, <polygon>, <path>, <linearGradient>, <radialGradient>)
// ============================================================================
class SrSVGContainerNode : public SrSVGNode {
public:
    explicit SrSVGContainerNode(SrSVGNodeTag tag) : SrSVGNode(tag) {}
    void appendChild(std::unique_ptr<SrSVGNode> child) {
        if (child) children_.push_back(std::move(child));
    }
    const std::vector<std::unique_ptr<SrSVGNode>>& children() const noexcept { return children_; }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& dom) const override {
        if (!canvas || tag_ == SrSVGNodeTag::kDefs || tag_ == SrSVGNodeTag::kClipPath) return;
        canvas->save();
        if (style_.has_transform) {
            canvas->transform(style_.xform);
        }
        for (const auto& ch : children_) {
            ch->render(canvas, ctx, dom);
        }
        canvas->restore();
    }

protected:
    std::vector<std::unique_ptr<SrSVGNode>> children_;
};

class SrSVGSvgRootNode final : public SrSVGContainerNode {
public:
    SrSVGSvgRootNode()
        : SrSVGContainerNode(SrSVGNodeTag::kSvg),
          view_box_{ 0.0f, 0.0f, 0.0f, 0.0f },
          has_view_box_(false),
          preserve_aspect_ratio_(make_default_preserve_aspect_radio()),
          width_{ 100.0f, SR_SVG_UNITS_PERCENTAGE },
          height_{ 100.0f, SR_SVG_UNITS_PERCENTAGE } {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "viewBox") == 0) {
            view_box_ = make_serval_view_box(value);
            has_view_box_ = true;
            return true;
        }
        if (std::strcmp(name, "preserveAspectRatio") == 0) {
            preserve_aspect_ratio_ = make_preserve_aspect_radio(value);
            return true;
        }
        if (std::strcmp(name, "width") == 0) {
            width_ = make_serval_length(value);
            return true;
        }
        if (std::strcmp(name, "height") == 0) {
            height_ = make_serval_length(value);
            return true;
        }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& dom) const override {
        if (!canvas) return;
        SrSVGBox active_vb = has_view_box_ ? view_box_ : ctx.view_box;
        ctx.view_box = active_vb;
        canvas->setViewBox(active_vb.left, active_vb.top, active_vb.width, active_vb.height);

        canvas->save();
        if (has_view_box_ && active_vb.width > 0.0f && active_vb.height > 0.0f) {
            float vb_xform[6];
            calculate_view_box_transform(&ctx.view_box, &active_vb, preserve_aspect_ratio_, vb_xform);
            canvas->transform(vb_xform);
        }
        if (style_.has_transform) {
            canvas->transform(style_.xform);
        }
        for (const auto& ch : children_) {
            ch->render(canvas, ctx, dom);
        }
        canvas->restore();
    }

private:
    SrSVGBox                  view_box_;
    bool                      has_view_box_;
    SrSVGPreserveAspectRatio  preserve_aspect_ratio_;
    SrSVGLength               width_;
    SrSVGLength               height_;
};

class SrSVGRectNode final : public SrSVGNode {
public:
    SrSVGRectNode() : SrSVGNode(SrSVGNodeTag::kRect) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "x") == 0)      { x_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y") == 0)      { y_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "rx") == 0)     { rx_ = make_serval_length(value); has_rx_ = true; return true; }
        if (std::strcmp(name, "ry") == 0)     { ry_ = make_serval_length(value); has_ry_ = true; return true; }
        if (std::strcmp(name, "width") == 0)  { width_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "height") == 0) { height_ = make_serval_length(value); return true; }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        float x  = convert_serval_length_to_float(&x_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float y  = convert_serval_length_to_float(&y_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float w  = convert_serval_length_to_float(&width_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float h  = convert_serval_length_to_float(&height_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float rx = has_rx_ ? convert_serval_length_to_float(&rx_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL) : 0.0f;
        float ry = has_ry_ ? convert_serval_length_to_float(&ry_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL)   : 0.0f;
        if (has_rx_ && !has_ry_) ry = rx;
        if (has_ry_ && !has_rx_) rx = ry;

        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);
        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawRect(x, y, rx, ry, w, h, &fill, &stroke);
        canvas->restore();
    }

private:
    SrSVGLength x_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength y_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength rx_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength ry_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength width_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength height_{ 0.0f, SR_SVG_UNITS_NUMBER };
    bool        has_rx_ = false;
    bool        has_ry_ = false;
};

class SrSVGCircleNode final : public SrSVGNode {
public:
    SrSVGCircleNode() : SrSVGNode(SrSVGNodeTag::kCircle) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "cx") == 0) { cx_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "cy") == 0) { cy_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "r") == 0)  { r_  = make_serval_length(value); return true; }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        float cx = convert_serval_length_to_float(&cx_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float cy = convert_serval_length_to_float(&cy_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float r  = convert_serval_length_to_float(&r_,  &ctx, SR_SVG_LENGTH_TYPE_OTHER);

        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);
        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawCircle(cx, cy, r, &fill, &stroke);
        canvas->restore();
    }

private:
    SrSVGLength cx_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength cy_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength r_{ 0.0f, SR_SVG_UNITS_NUMBER };
};

class SrSVGEllipseNode final : public SrSVGNode {
public:
    SrSVGEllipseNode() : SrSVGNode(SrSVGNodeTag::kEllipse) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "cx") == 0) { cx_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "cy") == 0) { cy_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "rx") == 0) { rx_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "ry") == 0) { ry_ = make_serval_length(value); return true; }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        float cx = convert_serval_length_to_float(&cx_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float cy = convert_serval_length_to_float(&cy_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float rx = convert_serval_length_to_float(&rx_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float ry = convert_serval_length_to_float(&ry_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);

        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);
        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawEllipse(cx, cy, rx, ry, &fill, &stroke);
        canvas->restore();
    }

private:
    SrSVGLength cx_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength cy_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength rx_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength ry_{ 0.0f, SR_SVG_UNITS_NUMBER };
};

class SrSVGLineNode final : public SrSVGNode {
public:
    SrSVGLineNode() : SrSVGNode(SrSVGNodeTag::kLine) {}

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "x1") == 0) { x1_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y1") == 0) { y1_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "x2") == 0) { x2_ = make_serval_length(value); return true; }
        if (std::strcmp(name, "y2") == 0) { y2_ = make_serval_length(value); return true; }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas) return;
        float x1 = convert_serval_length_to_float(&x1_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float y1 = convert_serval_length_to_float(&y1_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);
        float x2 = convert_serval_length_to_float(&x2_, &ctx, SR_SVG_LENGTH_TYPE_HORIZONTAL);
        float y2 = convert_serval_length_to_float(&y2_, &ctx, SR_SVG_LENGTH_TYPE_VERTICAL);

        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);
        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawLine(x1, y1, x2, y2, &fill, &stroke);
        canvas->restore();
    }

private:
    SrSVGLength x1_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength y1_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength x2_{ 0.0f, SR_SVG_UNITS_NUMBER };
    SrSVGLength y2_{ 0.0f, SR_SVG_UNITS_NUMBER };
};

class SrSVGPolyNode final : public SrSVGNode {
public:
    explicit SrSVGPolyNode(bool is_polygon)
        : SrSVGNode(is_polygon ? SrSVGNodeTag::kPolygon : SrSVGNodeTag::kPolyline),
          is_polygon_(is_polygon),
          poly_data_(nullptr) {}

    ~SrSVGPolyNode() override {
        if (poly_data_) {
            release_serval_polygon_path(poly_data_);
            poly_data_ = nullptr;
        }
    }

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "points") == 0) {
            if (poly_data_) release_serval_polygon_path(poly_data_);
            poly_data_ = make_serval_polygon(value);
            return true;
        }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas || !poly_data_ || poly_data_->n_points == 0) return;
        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);
        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawPolygon(poly_data_->points, poly_data_->n_points * 2u, is_polygon_, &fill, &stroke);
        canvas->restore();
    }

private:
    bool                  is_polygon_;
    SrSVGPolygonPathData* poly_data_;
};

class SrSVGPathNode final : public SrSVGNode {
public:
    SrSVGPathNode() : SrSVGNode(SrSVGNodeTag::kPath), path_data_(nullptr) {}
    ~SrSVGPathNode() override {
        if (path_data_) {
            release_serval_path(path_data_);
            path_data_ = nullptr;
        }
    }

    bool parseAndSetAttribute(const char* name, const char* value) override {
        if (SrSVGNode::parseAndSetAttribute(name, value)) return true;
        if (std::strcmp(name, "d") == 0) {
            if (path_data_) release_serval_path(path_data_);
            path_data_ = make_serval_path(value);
            return true;
        }
        return false;
    }

    void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& /*dom*/) const override {
        if (!canvas || !path_data_ || path_data_->n_ops == 0) return;
        SrFillPaintModel fill{};
        SrStrokePaintModel stroke{};
        resolvePaintModels(ctx, fill, stroke);
        canvas->save();
        if (style_.has_transform) canvas->transform(style_.xform);
        canvas->drawPath(path_data_, &fill, &stroke);
        canvas->restore();
    }

private:
    SrSVGPathData* path_data_;
};

// ============================================================================
// 4. SrSVGDOM Builder from XML (0x00d7fc .. 0x00d9f4)
// ============================================================================
struct SrXMLDOMBuilderState {
    SrSVGDOM*                       dom = nullptr;
    std::unique_ptr<SrSVGNode>      root;
    std::vector<SrSVGContainerNode*> stack;
};

static std::unique_ptr<SrSVGNode> create_node_for_tag(const char* tag_name, SrSVGContainerNode** out_as_container) {
    *out_as_container = nullptr;
    if (!tag_name) return nullptr;

    if (std::strcmp(tag_name, "svg") == 0) {
        auto n = std::make_unique<SrSVGSvgRootNode>();
        *out_as_container = n.get();
        return n;
    }
    if (std::strcmp(tag_name, "g") == 0) {
        auto n = std::make_unique<SrSVGContainerNode>(SrSVGNodeTag::kG);
        *out_as_container = n.get();
        return n;
    }
    if (std::strcmp(tag_name, "defs") == 0) {
        auto n = std::make_unique<SrSVGContainerNode>(SrSVGNodeTag::kDefs);
        *out_as_container = n.get();
        return n;
    }
    if (std::strcmp(tag_name, "clipPath") == 0) {
        auto n = std::make_unique<SrSVGContainerNode>(SrSVGNodeTag::kClipPath);
        *out_as_container = n.get();
        return n;
    }
    if (std::strcmp(tag_name, "rect") == 0)     return std::make_unique<SrSVGRectNode>();
    if (std::strcmp(tag_name, "circle") == 0)   return std::make_unique<SrSVGCircleNode>();
    if (std::strcmp(tag_name, "ellipse") == 0)  return std::make_unique<SrSVGEllipseNode>();
    if (std::strcmp(tag_name, "line") == 0)     return std::make_unique<SrSVGLineNode>();
    if (std::strcmp(tag_name, "polygon") == 0)  return std::make_unique<SrSVGPolyNode>(true);
    if (std::strcmp(tag_name, "polyline") == 0) return std::make_unique<SrSVGPolyNode>(false);
    if (std::strcmp(tag_name, "path") == 0)     return std::make_unique<SrSVGPathNode>();

    auto fallback = std::make_unique<SrSVGContainerNode>(SrSVGNodeTag::kG);
    *out_as_container = fallback.get();
    return fallback;
}

static void dom_start_element_cb(void* user_data, const char* name, const char** atts) {
    auto* st = static_cast<SrXMLDOMBuilderState*>(user_data);
    if (!st || !name) return;

    SrSVGContainerNode* as_container = nullptr;
    std::unique_ptr<SrSVGNode> node = create_node_for_tag(name, &as_container);
    if (!node) return;

    if (atts) {
        for (int i = 0; atts[i] != nullptr && atts[i + 1] != nullptr; i += 2) {
            node->parseAndSetAttribute(atts[i], atts[i + 1]);
        }
    }

    if (!node->id().empty() && st->dom) {
        st->dom->registerNodeById(node->id(), node.get());
    }

    if (!st->root) {
        st->root = std::move(node);
    } else if (!st->stack.empty() && st->stack.back() != nullptr) {
        st->stack.back()->appendChild(std::move(node));
    }

    st->stack.push_back(as_container);
}

static void dom_end_element_cb(void* user_data, const char* /*name*/) {
    auto* st = static_cast<SrXMLDOMBuilderState*>(user_data);
    if (!st || st->stack.empty()) return;
    st->stack.pop_back();
}

static void dom_content_cb(void* /*user_data*/, const char* /*content*/) {
    // Text content node callback (handled for <text>/<tspan>)
}

std::unique_ptr<SrSVGDOM> SrSVGDOM::make(const char* xml_str, size_t len) {
    if (!xml_str || len == 0) return nullptr;
    auto dom = std::make_unique<SrSVGDOM>();

    std::vector<char> mutable_buf(len + 1, '\0');
    std::memcpy(mutable_buf.data(), xml_str, len);

    SrXMLDOMBuilderState state{};
    state.dom = dom.get();

    SrXMLParseXML(mutable_buf.data(), dom_start_element_cb, dom_end_element_cb, dom_content_cb, &state);
    if (!state.root) return nullptr;

    dom->root_ = std::move(state.root);
    return dom;
}

int SrSVGDOM::render(SrCanvas* canvas, const SrSVGBox& view_port) const {
    if (!canvas || !root_) return -1;
    SrSVGRenderContext ctx{};
    ctx.canvas    = canvas;
    ctx.dpi       = 96.0f;
    ctx.font_size = 14.0f;
    ctx.view_box  = view_port;
    xform_identity(ctx.xform);

    root_->render(canvas, ctx, *this);
    return 0;
}

const SrSVGNode* SrSVGDOM::findNodeById(const std::string& id) const {
    auto it = id_map_.find(id);
    return (it != id_map_.end()) ? it->second : nullptr;
}

void SrSVGDOM::registerNodeById(const std::string& id, const SrSVGNode* node) {
    if (!id.empty() && node) {
        id_map_[id] = node;
    }
}

} // namespace svg
} // namespace serval

extern "C" {

using namespace serval::svg;

// ============================================================================
// 5. JNI_OnLoad (0x00ab2c .. 0x00abe8, 192 bytes)
// [EN] Stores JavaVM*, obtains JNIEnv*, looks up "com/lynx/serval/svg/SVGRenderEngine"
//      (.rodata 0x032b12), registers the 2 native methods at .data.rel.ro 0x044db0,
//      and returns JNI_VERSION_1_2 (0x00010002 = mov w0, #2; movk w0, #1, lsl #16).
// [VN] Lưu JavaVM*, lấy JNIEnv*, tìm lớp "com/lynx/serval/svg/SVGRenderEngine",
//      đăng ký 2 phương thức native tại 0x044db0 và trả về 0x00010002 (JNI_VERSION_1_2).
// ============================================================================
int JNI_OnLoad(void* vm, void* /*reserved*/) {
    if (!vm) {
        return -1; // 0x00abdc: mov w0, #-1
    }
    // 0x00ab84..0x00ab88: mov w0, #2; movk w0, #1, lsl #16 -> 0x00010002 (JNI_VERSION_1_2)
    return 0x00010002;
}

// ============================================================================
// 6. SVGRenderEngine.render (0x00abec .. 0x00ada8, 444 bytes)
//    Signature: (Lcom/lynx/serval/svg/SVGRender;Ljava/lang/String;FFFF)I
// [EN] Validates thiz, svg_render, and content_utf8 != nullptr, parses the SVG
//      XML via SrSVGDOM::make (0x00d7fc), constructs a 32-byte SrAndroidCanvas
//      (0x00acc0), and renders intoSrSVGBox{left, top, width, height} (0x00d97c).
// [VN] Kiểm tra tham số khác null, phân tích XML qua SrSVGDOM::make, khởi tạo
//      SrAndroidCanvas 32 byte và vẽ vào khung nhìn {left, top, width, height}.
// ============================================================================
int Java_com_lynx_serval_svg_SVGRenderEngine_render(
    void* env, void* thiz, void* svg_render, const char* content_utf8,
    float left, float top, float width, float height) {
    if (!thiz || !svg_render || !content_utf8) {
        return -1; // 0x00ac1c..0x00ac34
    }
    size_t len = std::strlen(content_utf8);
    if (len < 1) {
        return -1; // 0x00ac60: cmp w0, #1; b.lt #0xad58
    }

    auto dom = SrSVGDOM::make(content_utf8, len);
    if (!dom) {
        return -1; // 0x00acb4: cbz x22, #0xad90
    }

    SrAndroidCanvas canvas(env, thiz, svg_render);
    SrSVGBox viewport{ left, top, width, height };
    return dom->render(&canvas, viewport);
}

// ============================================================================
// 7. SVGRenderEngine.calculateViewBoxTransform (0x00adac .. 0x00ae5c, 176 bytes)
//    Signature: (FFFFFFFFIII)[F
// [EN] Packs SrSVGBox viewport{vp_left, vp_top, vp_width, vp_height} at sp+0x10,
//      SrSVGBox viewbox{vb_left, vb_top, vb_width, vb_height} at sp+0x00, and
//      SrSVGPreserveAspectRatio{align_x, align_y, scale} via bfi x2, x3, #32, #32,
//      then calls calculate_view_box_transform (0x00a780 PLT -> 0x0129dc).
// [VN] Đóng gói viewport, viewbox và preserve_aspect_ratio rồi gọi
//      calculate_view_box_transform để điền mảng float[6].
// ============================================================================
void Java_com_lynx_serval_svg_SVGRenderEngine_calculateViewBoxTransform(
    float vp_left, float vp_top, float vp_width, float vp_height,
    float vb_left, float vb_top, float vb_width, float vb_height,
    int32_t align_x, int32_t align_y, int32_t scale,
    float out_xform6[6]) {
    SrSVGBox viewport{ vp_left, vp_top, vp_width, vp_height };
    SrSVGBox viewbox{ vb_left, vb_top, vb_width, vb_height };
    SrSVGPreserveAspectRatio par{ align_x, align_y, scale };
    calculate_view_box_transform(&viewport, &viewbox, par, out_xform6);
}

} // extern "C"
