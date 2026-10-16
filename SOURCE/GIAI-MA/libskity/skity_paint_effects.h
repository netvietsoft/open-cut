// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Paint, Shaders, MaskFilters, and Color Pipeline
// File: skity_paint_effects.h
// Description: Paint styling attributes, Linear/Radial/Sweep gradient shaders,
//              Gaussian Blur mask filters, and Color transformation filters.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_PAINT_EFFECTS_H_
#define NEXTAI_OPENCUT_SKITY_PAINT_EFFECTS_H_

#include <vector>
#include <memory>
#include "skity_geometry.h"
#include "skity_matrix.h"

namespace skity {

enum class TileMode {
    kClamp = 0,
    kRepeat = 1,
    kMirror = 2,
    kDecal = 3,
};

enum class BlurStyle {
    kNormal = 0,
    kSolid = 1,
    kOuter = 2,
    kInner = 3,
};

enum class BlendMode {
    kClear = 0,
    kSrc = 1,
    kDst = 2,
    kSrcOver = 3,
    kDstOver = 4,
    kSrcIn = 5,
    kDstIn = 6,
    kSrcOut = 7,
    kDstOut = 8,
    kSrcATop = 9,
    kDstATop = 10,
    kXor = 11,
    kPlus = 12,
    kMultiply = 13,
    kScreen = 14,
};

// ==============================================================================
// 1. ColorFilter & ColorFilters
// ==============================================================================
class ColorFilter {
public:
    virtual ~ColorFilter() = default;
    virtual Vec4 FilterColor(const Vec4& in_color) const = 0;
};

class ColorFilters {
public:
    // Opcode 0xe85f0: Matrix (4x5 color transform)
    static std::shared_ptr<ColorFilter> Matrix(const float* row_major_20);

    // Opcode 0xe8464: Blend
    static std::shared_ptr<ColorFilter> Blend(uint32_t color_argb, BlendMode mode);

    // Opcode 0xe881c: LinearToSRGBGamma
    static std::shared_ptr<ColorFilter> LinearToSRGBGamma();

    // Opcode 0xe8a80: SRGBToLinearGamma
    static std::shared_ptr<ColorFilter> SRGBToLinearGamma();
};

// ==============================================================================
// 2. MaskFilter (Blur & Morphology)
// ==============================================================================
class MaskFilter {
public:
    virtual ~MaskFilter() = default;
    virtual BlurStyle style() const = 0;
    virtual float radius() const = 0;

    // Opcode 0xebcdc: MakeBlur
    // Checks radius > 0.0f, creates Gaussian blur mask filter
    static std::shared_ptr<MaskFilter> MakeBlur(BlurStyle style, float radius);
};

// ==============================================================================
// 3. Shader (Gradients & Textures)
// ==============================================================================
class Shader {
public:
    virtual ~Shader() = default;
    virtual Vec4 Shade(float x, float y) const = 0;

    // Opcode 0xec754: MakeLinear
    static std::shared_ptr<Shader> MakeLinear(const Point pts[2], const Vec4* colors,
                                             const float* pos, int count, TileMode mode);

    // Opcode 0xec89c: MakeRadial
    static std::shared_ptr<Shader> MakeRadial(const Point& center, float radius,
                                             const Vec4* colors, const float* pos,
                                             int count, TileMode mode);

    // Opcode 0xece0c: MakeSweep
    static std::shared_ptr<Shader> MakeSweep(float cx, float cy, float start_angle,
                                            float end_angle, const Vec4* colors,
                                            const float* pos, int count,
                                            TileMode mode, int flag);
};

// ==============================================================================
// 4. Paint
// ==============================================================================
class Paint {
public:
    enum Style {
        kFill = 0,
        kStroke = 1,
        kStrokeAndFill = 2,
    };

    enum Cap {
        kButt = 0,
        kRound = 1,
        kSquare = 2,
    };

    enum Join {
        kMiter = 0,
        kRound = 1,
        kBevel = 2,
    };

    Paint();
    Paint(const Paint& other);
    Paint& operator=(const Paint& other);
    ~Paint() = default;

    // Opcode 0xf6568: SetStyle
    void SetStyle(Style style) { style_ = style; }
    Style GetStyle() const { return style_; }

    // Opcode 0xf65a0: SetStrokeCap
    void SetStrokeCap(Cap cap) { cap_ = cap; }
    Cap GetStrokeCap() const { return cap_; }

    // Opcode 0xf65b0: SetStrokeJoin
    void SetStrokeJoin(Join join) { join_ = join; }
    Join GetStrokeJoin() const { return join_; }

    void SetStrokeWidth(float width) { stroke_width_ = width; }
    float GetStrokeWidth() const { return stroke_width_; }

    void SetStrokeMiter(float miter) { miter_limit_ = miter; }
    float GetStrokeMiter() const { return miter_limit_; }

    void SetColor(const Vec4& color) { color_ = color; }
    Vec4 GetColor() const { return color_; }

    // Opcode 0xf66b8: SetAlphaF
    void SetAlphaF(float a) { color_.w = std::max(0.0f, std::min(1.0f, a)); }
    float GetAlphaF() const { return color_.w; }

    // Opcode 0xf6878: SetAdjustStroke
    void SetAdjustStroke(bool adjust) { adjust_stroke_ = adjust; }
    bool GetAdjustStroke() const { return adjust_stroke_; }

    // Opcode 0xf6718: ComputeFastBounds
    // Expands rectangle by half-stroke width if style is stroke
    Rect ComputeFastBounds(const Rect& src) const;

    void SetShader(std::shared_ptr<Shader> shader) { shader_ = shader; }
    std::shared_ptr<Shader> GetShader() const { return shader_; }

    void SetMaskFilter(std::shared_ptr<MaskFilter> mf) { mask_filter_ = mf; }
    std::shared_ptr<MaskFilter> GetMaskFilter() const { return mask_filter_; }

    void SetColorFilter(std::shared_ptr<ColorFilter> cf) { color_filter_ = cf; }
    std::shared_ptr<ColorFilter> GetColorFilter() const { return color_filter_; }

private:
    Style style_;
    Cap cap_;
    Join join_;
    float stroke_width_;
    float miter_limit_;
    Vec4 color_;
    bool adjust_stroke_;
    std::shared_ptr<Shader> shader_;
    std::shared_ptr<MaskFilter> mask_filter_;
    std::shared_ptr<ColorFilter> color_filter_;
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_PAINT_EFFECTS_H_
