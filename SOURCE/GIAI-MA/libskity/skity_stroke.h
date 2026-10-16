// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Path Stroking & Outline Tessellation
// File: skity_stroke.h
// Description: Stroke expansion engine supporting Butt/Round/Square caps,
//              Miter/Round/Bevel joins, and Miter Limit clipping.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_STROKE_H_
#define NEXTAI_OPENCUT_SKITY_STROKE_H_

#include "skity_geometry.h"
#include "skity_path.h"

namespace skity {

class Paint; // Forward declaration

class Stroke {
public:
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

    Stroke();
    explicit Stroke(const Paint& paint);
    Stroke(float width, float miter_limit, Cap cap, Join join);
    ~Stroke() = default;

    // Opcode 0xf2828: StrokePath
    // Expands a 1D skeleton path into a 2D outlined fillable closed boundary
    bool StrokePath(const Path& src, Path* dst) const;

    float width() const { return width_; }
    void set_width(float w) { width_ = w; }

    float miter_limit() const { return miter_limit_; }
    void set_miter_limit(float m) { miter_limit_ = m; }

    Cap cap() const { return cap_; }
    void set_cap(Cap c) { cap_ = c; }

    Join join() const { return join_; }
    void set_join(Join j) { join_ = j; }

private:
    void AppendJoin(Path* outer, Path* inner, const Point& p,
                    const Vec2& n1, const Vec2& n2, float half_width) const;
    void AppendCap(Path* path, const Point& p, const Vec2& n, const Vec2& t,
                   float half_width, bool is_start) const;

    float width_;
    float miter_limit_;
    Cap cap_;
    Join join_;
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_STROKE_H_
