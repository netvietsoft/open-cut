// ============================================================================
// File: serval_svg_dom_and_jni.h
// Target: libserval_svg.so (282,912 bytes / 0x45120, SHA-256: 742e48019f3701911055dc50691d61bb7b517be98800be8b0dcdf9918f0d296a)
// Classification: OBSERVED (Direct Binary Disassembly of .text 0x00ab2c..0x0126cc
//                 and 0x015174..0x01a200)
// ============================================================================
// [EN] Declarations for ByteDance Lynx Serval SVG DOM Tree Hierarchy, CSS Style
//      & Presentation Attribute Inheritance, SrCanvas / SrAndroidCanvas JNI
//      Bridge, and JNI_OnLoad / SVGRenderEngine native entrypoints.
// [VN] Khai báo cây phân cấp Serval SVG DOM, kế thừa thuộc tính trình bày & CSS,
//      cầu nối JNI SrCanvas / SrAndroidCanvas, và điểm vào JNI_OnLoad / SVGRenderEngine.
// ============================================================================

#pragma once

#include "serval_svg_types.h"
#include "serval_svg_rodata_tables.h"
#include "serval_svg_math_and_parser.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace serval {
namespace svg {

// ============================================================================
// 1. Abstract SrCanvas & Concrete SrAndroidCanvas (0x0158a0 .. 0x019f00)
//    OBSERVED JNI signatures in .rodata 0x0336bf..0x033d50
// ============================================================================
struct SrFillPaintModel {
    int32_t     type;         // 0=none, 1=color, 2=iri
    std::string iri;          // gradient id (#id)
    uint64_t    color;        // ARGB8888
    int32_t     fill_rule;    // 0=winding, 1=evenodd
    float       fill_opacity; // [0.0..1.0]
};

struct SrStrokePaintModel {
    int32_t            type;              // 0=none, 1=color, 2=iri
    std::string        iri;               // gradient id (#id)
    uint64_t           color;             // ARGB8888
    float              width;             // stroke-width in px
    float              stroke_opacity;    // [0.0..1.0]
    int32_t            stroke_line_cap;   // 0=butt, 1=round, 2=square
    int32_t            stroke_line_join;  // 0=miter, 1=round, 2=bevel
    float              stroke_miter_limit;// default 4.0f
    float              stroke_dash_offset;// default 0.0f
    std::vector<float> dash_array;        // stroke-dasharray floats
};

struct SrCanvasDrawRecord {
    std::string        op_name;
    std::vector<float> params;
    SrFillPaintModel   fill;
    SrStrokePaintModel stroke;
};

class SrCanvas {
public:
    virtual ~SrCanvas() = default;

    // Virtual methods matching vtable at .data.rel.ro 0x047ea0
    virtual void setViewBox(float left, float top, float width, float height) = 0;
    virtual void save() = 0;
    virtual void restore() = 0;
    virtual void translate(float dx, float dy) = 0;
    virtual void transform(const float xform[6]) = 0;
    virtual void clipPath(const SrSVGPathData* path, int32_t clip_rule) = 0;

    virtual void drawRect(float x, float y, float rx, float ry, float width, float height,
                          const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) = 0;
    virtual void drawCircle(float cx, float cy, float r,
                            const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) = 0;
    virtual void drawEllipse(float cx, float cy, float rx, float ry,
                             const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) = 0;
    virtual void drawLine(float x1, float y1, float x2, float y2,
                          const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) = 0;
    virtual void drawPolygon(const float* pts, uint32_t n_floats, bool close_path,
                             const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) = 0;
    virtual void drawPath(const SrSVGPathData* path,
                          const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) = 0;
    virtual void drawImage(const char* href, float x, float y, float w, float h,
                           int32_t align_x, int32_t align_y, int32_t scale) = 0;
    virtual void drawText(const char* text, float x, float y, float font_size,
                          int32_t text_anchor, uint32_t argb_color) = 0;

    virtual void makeLinearGradient(const char* id, const float xform[6], int32_t spread_method,
                                    float x1, float y1, float x2, float y2, int32_t gradient_units,
                                    const std::vector<SrSVGStop>& stops) = 0;
    virtual void makeRadialGradient(const char* id, const float xform[6], int32_t spread_method,
                                    float cx, float cy, float r, float fx, float fy, int32_t gradient_units,
                                    const std::vector<SrSVGStop>& stops) = 0;
};

// [EN] Concrete Android Canvas implementation (allocated 0x20 bytes at 0x00acc0:
//      vtable+0x00, jni_env+0x08, svg_render_engine+0x10, svg_render+0x18).
// [VN] Lớp thực thi Android Canvas cụ thể (cấp phát 32 byte tại 0x00acc0).
class SrAndroidCanvas final : public SrCanvas {
public:
    SrAndroidCanvas(void* jni_env, void* render_engine_obj, void* svg_render_obj);
    ~SrAndroidCanvas() override = default;

    void setViewBox(float left, float top, float width, float height) override;
    void save() override;
    void restore() override;
    void translate(float dx, float dy) override;
    void transform(const float xform[6]) override;
    void clipPath(const SrSVGPathData* path, int32_t clip_rule) override;

    void drawRect(float x, float y, float rx, float ry, float width, float height,
                  const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) override;
    void drawCircle(float cx, float cy, float r,
                    const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) override;
    void drawEllipse(float cx, float cy, float rx, float ry,
                     const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) override;
    void drawLine(float x1, float y1, float x2, float y2,
                  const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) override;
    void drawPolygon(const float* pts, uint32_t n_floats, bool close_path,
                     const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) override;
    void drawPath(const SrSVGPathData* path,
                  const SrFillPaintModel* fill, const SrStrokePaintModel* stroke) override;
    void drawImage(const char* href, float x, float y, float w, float h,
                   int32_t align_x, int32_t align_y, int32_t scale) override;
    void drawText(const char* text, float x, float y, float font_size,
                  int32_t text_anchor, uint32_t argb_color) override;

    void makeLinearGradient(const char* id, const float xform[6], int32_t spread_method,
                            float x1, float y1, float x2, float y2, int32_t gradient_units,
                            const std::vector<SrSVGStop>& stops) override;
    void makeRadialGradient(const char* id, const float xform[6], int32_t spread_method,
                            float cx, float cy, float r, float fx, float fy, int32_t gradient_units,
                            const std::vector<SrSVGStop>& stops) override;

    const std::vector<SrCanvasDrawRecord>& recorded_commands() const noexcept { return commands_; }
    const SrSVGBox& active_view_box() const noexcept { return active_view_box_; }

private:
    void*                           jni_env_;           // +0x08
    void*                           render_engine_obj_; // +0x10
    void*                           svg_render_obj_;    // +0x18
    SrSVGBox                        active_view_box_;
    std::vector<SrCanvasDrawRecord> commands_;
};

// ============================================================================
// 2. SVG DOM Node & Element Hierarchy (0x00d7fc .. 0x0126cc)
// ============================================================================
enum class SrSVGNodeTag : uint8_t {
    kSvg,
    kG,
    kDefs,
    kClipPath,
    kRect,
    kCircle,
    kEllipse,
    kLine,
    kPolyline,
    kPolygon,
    kPath,
    kText,
    kTSpan,
    kImage,
    kUse,
    kLinearGradient,
    kRadialGradient,
    kStop,
};

struct SrSVGPresentationStyle {
    bool               has_fill = false;
    SrSVGPaint*        fill = nullptr;
    bool               has_stroke = false;
    SrSVGPaint*        stroke = nullptr;
    bool               has_fill_opacity = false;
    float              fill_opacity = 1.0f;
    bool               has_stroke_opacity = false;
    float              stroke_opacity = 1.0f;
    bool               has_opacity = false;
    float              opacity = 1.0f;
    bool               has_stroke_width = false;
    SrSVGLength        stroke_width{ 1.0f, SR_SVG_UNITS_NUMBER };
    bool               has_stroke_cap = false;
    SrSVGStrokeCap     stroke_cap = SR_SVG_CAP_BUTT;
    bool               has_stroke_join = false;
    SrSVGStrokeJoin    stroke_join = SR_SVG_JOIN_MITER;
    bool               has_miter_limit = false;
    float              miter_limit = 4.0f;
    bool               has_dash_offset = false;
    SrSVGLength        dash_offset{ 0.0f, SR_SVG_UNITS_NUMBER };
    bool               has_dash_array = false;
    std::vector<SrSVGLength> dash_array;
    bool               has_fill_rule = false;
    SrSVGFillRule      fill_rule = SR_SVG_FILL_RULE_WINDING;
    bool               has_clip_rule = false;
    SrSVGFillRule      clip_rule = SR_SVG_FILL_RULE_WINDING;
    bool               has_color = false;
    SrSVGColor         color{ 1u, 0xFF000000u };
    std::string        clip_path_iri;
    float              xform[6] = { 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f };
    bool               has_transform = false;

    ~SrSVGPresentationStyle() {
        if (fill) { release_serval_paint(fill); fill = nullptr; }
        if (stroke) { release_serval_paint(stroke); stroke = nullptr; }
    }
};

class SrSVGDOM;

class SrSVGNode {
public:
    explicit SrSVGNode(SrSVGNodeTag tag) : tag_(tag) {
        xform_identity(style_.xform);
    }
    virtual ~SrSVGNode() = default;

    SrSVGNodeTag tag() const noexcept { return tag_; }
    const std::string& id() const noexcept { return id_; }

    virtual bool parseAndSetAttribute(const char* name, const char* value);
    virtual void render(SrCanvas* canvas, SrSVGRenderContext& ctx, const SrSVGDOM& dom) const = 0;

protected:
    void resolvePaintModels(const SrSVGRenderContext& ctx,
                            SrFillPaintModel& out_fill,
                            SrStrokePaintModel& out_stroke) const;

    SrSVGNodeTag           tag_;
    std::string            id_;
    SrSVGPresentationStyle style_;
};

class SrSVGDOM {
public:
    SrSVGDOM() = default;
    ~SrSVGDOM() = default;

    // [EN] Reconstructed from SrSVGDOM::make(const char*, size_t) at 0x00d7fc..0x00d978
    // [VN] Tái tạo từ SrSVGDOM::make(const char*, size_t) tại 0x00d7fc..0x00d978
    static std::unique_ptr<SrSVGDOM> make(const char* xml_str, size_t len);

    // [EN] Reconstructed from SrSVGDOM::render(SrCanvas*, SrSVGBox) at 0x00d97c..0x00d9f4
    // [VN] Tái tạo từ SrSVGDOM::render(SrCanvas*, SrSVGBox) tại 0x00d97c..0x00d9f4
    int render(SrCanvas* canvas, const SrSVGBox& view_port) const;

    const SrSVGNode* findNodeById(const std::string& id) const;
    void registerNodeById(const std::string& id, const SrSVGNode* node);

private:
    std::unique_ptr<SrSVGNode>                     root_;
    std::unordered_map<std::string, const SrSVGNode*> id_map_;
};

} // namespace svg
} // namespace serval

extern "C" {

// ============================================================================
// 3. JNI Entrypoints (0x00ab2c, 0x00abec, 0x00adac)
// ============================================================================
int   JNI_OnLoad(void* vm, void* reserved);
int   Java_com_lynx_serval_svg_SVGRenderEngine_render(
          void* env, void* thiz, void* svg_render, const char* content_utf8,
          float left, float top, float width, float height);
void  Java_com_lynx_serval_svg_SVGRenderEngine_calculateViewBoxTransform(
          float vp_left, float vp_top, float vp_width, float vp_height,
          float vb_left, float vb_top, float vb_width, float vb_height,
          int32_t align_x, int32_t align_y, int32_t scale,
          float out_xform6[6]);

} // extern "C"
