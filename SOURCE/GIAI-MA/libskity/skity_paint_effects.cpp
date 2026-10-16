// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Paint, Shaders, MaskFilters, and Color Pipeline
// File: skity_paint_effects.cpp
// Description: Implementation of Linear/Radial/Sweep shaders, Gaussian blur
//              mask filter, and color matrix transformations.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_paint_effects.h"
#include <cmath>
#include <algorithm>

namespace skity {

constexpr float kPaintPi = 3.14159265358979323846f;

// Helper: TileMode coordinate mapping
static float ApplyTileMode(float t, TileMode mode) {
    switch (mode) {
        case TileMode::kClamp:
            return std::max(0.0f, std::min(1.0f, t));
        case TileMode::kRepeat: {
            float frac = t - std::floor(t);
            return (frac < 0.0f) ? frac + 1.0f : frac;
        }
        case TileMode::kMirror: {
            float cycle = std::floor(t);
            float frac = t - cycle;
            int c = static_cast<int>(std::abs(cycle));
            return (c % 2 == 1) ? (1.0f - frac) : frac;
        }
        case TileMode::kDecal:
            return (t >= 0.0f && t <= 1.0f) ? t : -1.0f;
    }
    return std::max(0.0f, std::min(1.0f, t));
}

// Helper: Interpolates color stop array
static Vec4 InterpolateStops(float t, const std::vector<Vec4>& colors, const std::vector<float>& pos) {
    if (t < 0.0f) return Vec4(0.0f, 0.0f, 0.0f, 0.0f); // Decal transparent
    if (colors.empty()) return Vec4(0.0f, 0.0f, 0.0f, 1.0f);
    if (colors.size() == 1 || t <= pos.front()) return colors.front();
    if (t >= pos.back()) return colors.back();

    for (size_t i = 0; i < pos.size() - 1; ++i) {
        if (t >= pos[i] && t <= pos[i + 1]) {
            float span = pos[i + 1] - pos[i];
            float frac = (span > 1e-6f) ? (t - pos[i]) / span : 0.0f;
            const Vec4& c0 = colors[i];
            const Vec4& c1 = colors[i + 1];
            return Vec4(
                c0.x + (c1.x - c0.x) * frac,
                c0.y + (c1.y - c0.y) * frac,
                c0.z + (c1.z - c0.z) * frac,
                c0.w + (c1.w - c0.w) * frac
            );
        }
    }
    return colors.back();
}

// ==============================================================================
// Linear Gradient Shader Implementation
// Opcode 0xec754: MakeLinear
// ==============================================================================
class LinearGradientShader : public Shader {
public:
    LinearGradientShader(Point p0, Point p1, const Vec4* colors, const float* pos,
                         int count, TileMode mode)
        : p0_(p0), p1_(p1), mode_(mode) {
        colors_.assign(colors, colors + count);
        if (pos) {
            pos_.assign(pos, pos + count);
        } else {
            pos_.resize(count);
            for (int i = 0; i < count; ++i) {
                pos_[i] = static_cast<float>(i) / (count - 1);
            }
        }
        dir_ = p1_ - p0_;
        length_sq_ = dir_.LengthSq();
    }

    Vec4 Shade(float x, float y) const override {
        if (length_sq_ < 1e-7f) {
            return colors_.empty() ? Vec4(0, 0, 0, 1) : colors_.front();
        }
        // Projection t = (P - P0) . (P1 - P0) / ||P1 - P0||^2
        Vec2 v = Vec2(x, y) - p0_;
        float t = (v.x * dir_.x + v.y * dir_.y) / length_sq_;
        t = ApplyTileMode(t, mode_);
        return InterpolateStops(t, colors_, pos_);
    }

private:
    Point p0_;
    Point p1_;
    Vec2 dir_;
    float length_sq_;
    TileMode mode_;
    std::vector<Vec4> colors_;
    std::vector<float> pos_;
};

std::shared_ptr<Shader> Shader::MakeLinear(const Point pts[2], const Vec4* colors,
                                           const float* pos, int count, TileMode mode) {
    if (!pts || !colors || count < 2) return nullptr;
    return std::make_shared<LinearGradientShader>(pts[0], pts[1], colors, pos, count, mode);
}

// ==============================================================================
// Radial Gradient Shader Implementation
// Opcode 0xec89c: MakeRadial
// ==============================================================================
class RadialGradientShader : public Shader {
public:
    RadialGradientShader(Point center, float radius, const Vec4* colors,
                         const float* pos, int count, TileMode mode)
        : center_(center), radius_(radius), mode_(mode) {
        colors_.assign(colors, colors + count);
        if (pos) {
            pos_.assign(pos, pos + count);
        } else {
            pos_.resize(count);
            for (int i = 0; i < count; ++i) {
                pos_[i] = static_cast<float>(i) / (count - 1);
            }
        }
        inv_radius_ = (radius_ > 1e-6f) ? (1.0f / radius_) : 0.0f;
    }

    Vec4 Shade(float x, float y) const override {
        float dx = x - center_.x;
        float dy = y - center_.y;
        float dist = std::sqrt(dx * dx + dy * dy);
        float t = dist * inv_radius_;
        t = ApplyTileMode(t, mode_);
        return InterpolateStops(t, colors_, pos_);
    }

private:
    Point center_;
    float radius_;
    float inv_radius_;
    TileMode mode_;
    std::vector<Vec4> colors_;
    std::vector<float> pos_;
};

std::shared_ptr<Shader> Shader::MakeRadial(const Point& center, float radius,
                                           const Vec4* colors, const float* pos,
                                           int count, TileMode mode) {
    // Opcode 0xec89c disassembly checks: count >= 2 (cmp w3, #1; b.le) and radius > 0.0f (fcmp s0, #0.0; b.pl)
    if (!colors || count < 2 || radius <= 0.0f) {
        return nullptr;
    }
    return std::make_shared<RadialGradientShader>(center, radius, colors, pos, count, mode);
}

// ==============================================================================
// Sweep Gradient Shader Implementation
// Opcode 0xece0c: MakeSweep
// ==============================================================================
class SweepGradientShader : public Shader {
public:
    SweepGradientShader(float cx, float cy, float start_angle, float end_angle,
                        const Vec4* colors, const float* pos, int count, TileMode mode)
        : cx_(cx), cy_(cy), start_angle_(start_angle), end_angle_(end_angle), mode_(mode) {
        colors_.assign(colors, colors + count);
        if (pos) {
            pos_.assign(pos, pos + count);
        } else {
            pos_.resize(count);
            for (int i = 0; i < count; ++i) {
                pos_[i] = static_cast<float>(i) / (count - 1);
            }
        }
        angle_span_ = end_angle_ - start_angle_;
        if (std::fabs(angle_span_) < 1e-5f) {
            angle_span_ = 360.0f;
        }
    }

    Vec4 Shade(float x, float y) const override {
        float dx = x - cx_;
        float dy = y - cy_;
        float rad = std::atan2(dy, dx);
        float deg = rad * (180.0f / kPaintPi);
        if (deg < 0.0f) deg += 360.0f;

        float t = (deg - start_angle_) / angle_span_;
        t = ApplyTileMode(t, mode_);
        return InterpolateStops(t, colors_, pos_);
    }

private:
    float cx_;
    float cy_;
    float start_angle_;
    float end_angle_;
    float angle_span_;
    TileMode mode_;
    std::vector<Vec4> colors_;
    std::vector<float> pos_;
};

std::shared_ptr<Shader> Shader::MakeSweep(float cx, float cy, float start_angle,
                                          float end_angle, const Vec4* colors,
                                          const float* pos, int count,
                                          TileMode mode, int flag) {
    if (!colors || count < 2) return nullptr;
    return std::make_shared<SweepGradientShader>(cx, cy, start_angle, end_angle, colors, pos, count, mode);
}

// ==============================================================================
// MaskFilter (Blur) Implementation
// Opcode 0xebcdc: MakeBlur
// ==============================================================================
class BlurMaskFilter : public MaskFilter {
public:
    BlurMaskFilter(BlurStyle style, float radius)
        : style_(style), radius_(radius) {}

    BlurStyle style() const override { return style_; }
    float radius() const override { return radius_; }

private:
    BlurStyle style_;
    float radius_;
};

std::shared_ptr<MaskFilter> MaskFilter::MakeBlur(BlurStyle style, float radius) {
    // Opcode 0xebcdc: checks radius > 0.0f (fcmp s0, #0.0; b.ls)
    if (radius <= 0.0f) {
        return nullptr;
    }
    return std::make_shared<BlurMaskFilter>(style, radius);
}

// ==============================================================================
// ColorFilters Implementation
// ==============================================================================
class MatrixColorFilter : public ColorFilter {
public:
    explicit MatrixColorFilter(const float* mat20) {
        for (int i = 0; i < 20; ++i) {
            mat_[i] = mat20[i];
        }
    }

    Vec4 FilterColor(const Vec4& c) const override {
        // [R' G' B' A'] = M4x4 * [R G B A] + T
        float r = mat_[0] * c.x + mat_[1] * c.y + mat_[2] * c.z + mat_[3] * c.w + mat_[4];
        float g = mat_[5] * c.x + mat_[6] * c.y + mat_[7] * c.z + mat_[8] * c.w + mat_[9];
        float b = mat_[10] * c.x + mat_[11] * c.y + mat_[12] * c.z + mat_[13] * c.w + mat_[14];
        float a = mat_[15] * c.x + mat_[16] * c.y + mat_[17] * c.z + mat_[18] * c.w + mat_[19];

        return Vec4(
            std::max(0.0f, std::min(1.0f, r)),
            std::max(0.0f, std::min(1.0f, g)),
            std::max(0.0f, std::min(1.0f, b)),
            std::max(0.0f, std::min(1.0f, a))
        );
    }

private:
    float mat_[20];
};

std::shared_ptr<ColorFilter> ColorFilters::Matrix(const float* row_major_20) {
    if (!row_major_20) return nullptr;
    return std::make_shared<MatrixColorFilter>(row_major_20);
}

class BlendColorFilter : public ColorFilter {
public:
    BlendColorFilter(uint32_t color_argb, BlendMode mode)
        : mode_(mode) {
        src_color_ = Vec4(
            ((color_argb >> 16) & 0xff) / 255.0f,
            ((color_argb >> 8) & 0xff) / 255.0f,
            (color_argb & 0xff) / 255.0f,
            ((color_argb >> 24) & 0xff) / 255.0f
        );
    }

    Vec4 FilterColor(const Vec4& dst) const override {
        const Vec4& src = src_color_;
        switch (mode_) {
            case BlendMode::kSrc: return src;
            case BlendMode::kDst: return dst;
            case BlendMode::kSrcOver:
                return Vec4(
                    src.x + dst.x * (1.0f - src.w),
                    src.y + dst.y * (1.0f - src.w),
                    src.z + dst.z * (1.0f - src.w),
                    src.w + dst.w * (1.0f - src.w)
                );
            case BlendMode::kMultiply:
                return Vec4(src.x * dst.x, src.y * dst.y, src.z * dst.z, src.w * dst.w);
            case BlendMode::kScreen:
                return Vec4(
                    src.x + dst.x - src.x * dst.x,
                    src.y + dst.y - src.y * dst.y,
                    src.z + dst.z - src.z * dst.z,
                    src.w + dst.w - src.w * dst.w
                );
            default:
                return src;
        }
    }

private:
    BlendMode mode_;
    Vec4 src_color_;
};

std::shared_ptr<ColorFilter> ColorFilters::Blend(uint32_t color_argb, BlendMode mode) {
    return std::make_shared<BlendColorFilter>(color_argb, mode);
}

class LinearToSRGBColorFilter : public ColorFilter {
public:
    Vec4 FilterColor(const Vec4& c) const override {
        auto ToSRGB = [](float val) -> float {
            if (val <= 0.0031308f) {
                return val * 12.92f;
            }
            return 1.055f * std::pow(val, 1.0f / 2.4f) - 0.055f;
        };
        return Vec4(ToSRGB(c.x), ToSRGB(c.y), ToSRGB(c.z), c.w);
    }
};

std::shared_ptr<ColorFilter> ColorFilters::LinearToSRGBGamma() {
    return std::make_shared<LinearToSRGBColorFilter>();
}

class SRGBToLinearColorFilter : public ColorFilter {
public:
    Vec4 FilterColor(const Vec4& c) const override {
        auto ToLinear = [](float val) -> float {
            if (val <= 0.04045f) {
                return val / 12.92f;
            }
            return std::pow((val + 0.055f) / 1.055f, 2.4f);
        };
        return Vec4(ToLinear(c.x), ToLinear(c.y), ToLinear(c.z), c.w);
    }
};

std::shared_ptr<ColorFilter> ColorFilters::SRGBToLinearGamma() {
    return std::make_shared<SRGBToLinearColorFilter>();
}

// ==============================================================================
// Paint Implementation
// ==============================================================================
Paint::Paint()
    : style_(kFill),
      cap_(kButt),
      join_(kMiter),
      stroke_width_(1.0f),
      miter_limit_(4.0f),
      color_(0.0f, 0.0f, 0.0f, 1.0f),
      adjust_stroke_(false),
      shader_(nullptr),
      mask_filter_(nullptr),
      color_filter_(nullptr) {}

Paint::Paint(const Paint& other)
    : style_(other.style_),
      cap_(other.cap_),
      join_(other.join_),
      stroke_width_(other.stroke_width_),
      miter_limit_(other.miter_limit_),
      color_(other.color_),
      adjust_stroke_(other.adjust_stroke_),
      shader_(other.shader_),
      mask_filter_(other.mask_filter_),
      color_filter_(other.color_filter_) {}

Paint& Paint::operator=(const Paint& other) {
    if (this != &other) {
        style_ = other.style_;
        cap_ = other.cap_;
        join_ = other.join_;
        stroke_width_ = other.stroke_width_;
        miter_limit_ = other.miter_limit_;
        color_ = other.color_;
        adjust_stroke_ = other.adjust_stroke_;
        shader_ = other.shader_;
        mask_filter_ = other.mask_filter_;
        color_filter_ = other.color_filter_;
    }
    return *this;
}

/**
 * @brief ComputeFastBounds: Estimates outer bounds of styled primitive.
 * EN: Matches AArch64 opcode 0xf6718 (352 bytes).
 *     If style == kStroke or kStrokeAndFill, expands rect by half_width * miter_limit.
 *     If mask_filter is active, further expands bounds by 3 * blur_radius.
 * VN: Khớp opcode AArch64 0xf6718. Tính nhanh khung bao ngoài khi có viền stroke và blur.
 */
Rect Paint::ComputeFastBounds(const Rect& src) const {
    if (src.IsEmpty()) return Rect::MakeEmpty();

    float inset = 0.0f;
    if (style_ != kFill) {
        float half_w = stroke_width_ * 0.5f;
        if (join_ == kMiter) {
            inset += half_w * miter_limit_;
        } else {
            inset += half_w;
        }
    }

    if (mask_filter_) {
        // Gaussian blur 3-sigma bounding box coverage
        inset += mask_filter_->radius() * 3.0f;
    }

    return Rect(
        src.left - inset,
        src.top - inset,
        src.right + inset,
        src.bottom + inset
    );
}

} // namespace skity
