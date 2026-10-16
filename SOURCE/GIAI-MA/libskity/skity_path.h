// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 2D Vector Path Geometry & Tessellation
// File: skity_path.h
// Description: Skity Path vector contour representation supporting lines,
//              quadratics, cubics, conics, and elliptical arcs.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_PATH_H_
#define NEXTAI_OPENCUT_SKITY_PATH_H_

#include <vector>
#include <memory>
#include "skity_geometry.h"
#include "skity_matrix.h"

namespace skity {

class Path {
public:
    enum Verb {
        kMove = 0,
        kLine = 1,
        kQuad = 2,
        kConic = 3,
        kCubic = 4,
        kClose = 5,
        kDone = 6,
    };

    enum Direction {
        kCW = 0,  // Clockwise (Thuận chiều kim đồng hồ)
        kCCW = 1, // Counter-Clockwise (Ngược chiều kim đồng hồ)
    };

    enum ArcSize {
        kSmall = 0,
        kLarge = 1,
    };

    enum FillType {
        kWinding = 0,
        kEvenOdd = 1,
        kInverseWinding = 2,
        kInverseEvenOdd = 3,
    };

    Path();
    Path(const Path& other);
    Path& operator=(const Path& other);
    ~Path() = default;

    // Contour primitives
    Path& MoveTo(float x, float y);
    Path& MoveTo(const Point& p) { return MoveTo(p.x, p.y); }
    Path& LineTo(float x, float y);
    Path& LineTo(const Point& p) { return LineTo(p.x, p.y); }
    Path& QuadTo(float x1, float y1, float x2, float y2);
    Path& ConicTo(float x1, float y1, float x2, float y2, float weight);
    Path& CubicTo(float x1, float y1, float x2, float y2, float x3, float y3);
    Path& Close();
    void Reset();

    // Opcode 0xf7f30: AddRect
    Path& AddRect(const Rect& rect, Direction dir = kCW, uint32_t start_index = 0);

    // Opcode 0xf87e8: AddCircle
    // Calculates bounding box [cx-r, cy-r, cx+r, cy+r] and adds 4 cubic segments
    Path& AddCircle(float cx, float cy, float radius, Direction dir = kCW);

    // Add Oval
    Path& AddOval(const Rect& oval, Direction dir = kCW);

    // Add Rounded Rectangle
    Path& AddRRect(const RRect& rrect, Direction dir = kCW);

    // Opcode 0xf79b8: ArcTo (W3C SVG Elliptical Arc to Cubic Beziers)
    Path& ArcTo(float rx, float ry, float x_axis_rotate, ArcSize arc_size,
                Direction sweep, float x, float y);

    // Opcode 0xf802c: HasOnlyMoveTos
    bool HasOnlyMoveTos() const;

    bool IsEmpty() const { return verbs_.empty(); }
    FillType GetFillType() const { return fill_type_; }
    void SetFillType(FillType ft) { fill_type_ = ft; }

    // Fast & Exact bounds
    Rect ComputeBounds() const;

    // Transformation
    void Transform(const Matrix& matrix);

    // Iterators
    class Iter {
    public:
        Iter(const Path& path, bool force_close);
        Verb Next(Point pts[4]);
        // Opcode 0xf6cf0: IsClosedContour
        bool IsClosedContour() const;
        // Opcode 0xf6cec: ConicWeight
        float ConicWeight() const { return conic_weight_; }

    private:
        const Path& path_;
        bool force_close_;
        size_t verb_idx_;
        size_t pt_idx_;
        size_t weight_idx_;
        Point last_move_to_;
        Point last_pt_;
        bool closed_contour_;
        float conic_weight_;
    };

    class RawIter {
    public:
        RawIter() : path_(nullptr), verb_idx_(0), pt_idx_(0), weight_idx_(0) {}
        explicit RawIter(const Path& path) { SetPath(path); }
        // Opcode 0xf6d64: SetPath
        void SetPath(const Path& path);
        Verb Next(Point pts[4]);
        float ConicWeight() const { return conic_weight_; }

    private:
        const Path* path_;
        size_t verb_idx_;
        size_t pt_idx_;
        size_t weight_idx_;
        float conic_weight_;
    };

    // Low-level access
    const std::vector<uint8_t>& verbs() const { return verbs_; }
    const std::vector<Point>& points() const { return points_; }
    const std::vector<float>& weights() const { return conic_weights_; }

private:
    std::vector<uint8_t> verbs_;
    std::vector<Point> points_;
    std::vector<float> conic_weights_;
    FillType fill_type_;
    Point current_pt_;
    Point last_move_to_;
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_PATH_H_
