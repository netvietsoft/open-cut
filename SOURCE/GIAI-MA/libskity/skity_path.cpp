// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — 2D Vector Path Geometry & Tessellation
// File: skity_path.cpp
// Description: Implementation of Skity Path vector contour generation,
//              SVG elliptical arc-to-cubics parameterization, and iterators.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_path.h"
#include <cmath>
#include <algorithm>

namespace skity {

constexpr float kSkityPi = 3.14159265358979323846f;
// Cubic Bezier constant for circle approximation: 4/3 * (sqrt(2) - 1)
constexpr float kSkityKappa = 0.55228474983079356f;

Path::Path()
    : fill_type_(kWinding),
      current_pt_(0.0f, 0.0f),
      last_move_to_(0.0f, 0.0f) {}

Path::Path(const Path& other)
    : verbs_(other.verbs_),
      points_(other.points_),
      conic_weights_(other.conic_weights_),
      fill_type_(other.fill_type_),
      current_pt_(other.current_pt_),
      last_move_to_(other.last_move_to_) {}

Path& Path::operator=(const Path& other) {
    if (this != &other) {
        verbs_ = other.verbs_;
        points_ = other.points_;
        conic_weights_ = other.conic_weights_;
        fill_type_ = other.fill_type_;
        current_pt_ = other.current_pt_;
        last_move_to_ = other.last_move_to_;
    }
    return *this;
}

Path& Path::MoveTo(float x, float y) {
    verbs_.push_back(kMove);
    points_.emplace_back(x, y);
    current_pt_ = Point(x, y);
    last_move_to_ = current_pt_;
    return *this;
}

Path& Path::LineTo(float x, float y) {
    if (verbs_.empty()) {
        MoveTo(0.0f, 0.0f);
    }
    verbs_.push_back(kLine);
    points_.emplace_back(x, y);
    current_pt_ = Point(x, y);
    return *this;
}

Path& Path::QuadTo(float x1, float y1, float x2, float y2) {
    if (verbs_.empty()) {
        MoveTo(0.0f, 0.0f);
    }
    verbs_.push_back(kQuad);
    points_.emplace_back(x1, y1);
    points_.emplace_back(x2, y2);
    current_pt_ = Point(x2, y2);
    return *this;
}

Path& Path::ConicTo(float x1, float y1, float x2, float y2, float weight) {
    if (verbs_.empty()) {
        MoveTo(0.0f, 0.0f);
    }
    verbs_.push_back(kConic);
    points_.emplace_back(x1, y1);
    points_.emplace_back(x2, y2);
    conic_weights_.push_back(weight);
    current_pt_ = Point(x2, y2);
    return *this;
}

Path& Path::CubicTo(float x1, float y1, float x2, float y2, float x3, float y3) {
    if (verbs_.empty()) {
        MoveTo(0.0f, 0.0f);
    }
    verbs_.push_back(kCubic);
    points_.emplace_back(x1, y1);
    points_.emplace_back(x2, y2);
    points_.emplace_back(x3, y3);
    current_pt_ = Point(x3, y3);
    return *this;
}

Path& Path::Close() {
    if (!verbs_.empty() && verbs_.back() != kClose) {
        verbs_.push_back(kClose);
        current_pt_ = last_move_to_;
    }
    return *this;
}

void Path::Reset() {
    verbs_.clear();
    points_.clear();
    conic_weights_.clear();
    fill_type_ = kWinding;
    current_pt_ = Point(0.0f, 0.0f);
    last_move_to_ = Point(0.0f, 0.0f);
}

/**
 * @brief AddRect: Adds rectangular contour.
 * EN: Matches AArch64 opcode 0xf7f30.
 *     Supports CW (0->1->2->3) and CCW (0->3->2->1) traversal order.
 * VN: Khớp opcode AArch64 0xf7f30. Thêm đường viền hình chữ nhật theo chiều kim đồng hồ hoặc ngược chiều.
 */
Path& Path::AddRect(const Rect& rect, Direction dir, uint32_t start_index) {
    if (rect.IsEmpty()) return *this;

    Point pts[4] = {
        Point(rect.left,  rect.top),
        Point(rect.right, rect.top),
        Point(rect.right, rect.bottom),
        Point(rect.left,  rect.bottom)
    };

    if (dir == kCCW) {
        std::swap(pts[1], pts[3]);
    }

    uint32_t s = start_index % 4;
    MoveTo(pts[s].x, pts[s].y);
    LineTo(pts[(s + 1) % 4].x, pts[(s + 1) % 4].y);
    LineTo(pts[(s + 2) % 4].x, pts[(s + 2) % 4].y);
    LineTo(pts[(s + 3) % 4].x, pts[(s + 3) % 4].y);
    Close();

    return *this;
}

/**
 * @brief AddCircle: Adds circular contour.
 * EN: Matches AArch64 opcode 0xf87e8.
 *     Disassembly verifies radius > 0.0f check and delegates to AddOval.
 * VN: Khớp opcode AArch64 0xf87e8. Thêm đường tròn bằng 4 đoạn cubic Bezier xấp xỉ liên tục C1.
 */
Path& Path::AddCircle(float cx, float cy, float radius, Direction dir) {
    if (radius <= 0.0f) {
        return *this;
    }
    Rect oval(cx - radius, cy - radius, cx + radius, cy + radius);
    return AddOval(oval, dir);
}

/**
 * @brief AddOval: Adds elliptical contour using 4 cubic Bezier segments.
 * EN: Standard vector graphics 4-segment cubic spline using kappa = 0.55228475.
 * VN: Xấp xỉ hình bầu dục elip chuẩn xác bằng hằng số kappa = 0.55228475.
 */
Path& Path::AddOval(const Rect& oval, Direction dir) {
    if (oval.IsEmpty()) return *this;

    float cx = (oval.left + oval.right) * 0.5f;
    float cy = (oval.top + oval.bottom) * 0.5f;
    float rx = (oval.right - oval.left) * 0.5f;
    float ry = (oval.bottom - oval.top) * 0.5f;

    float dx = rx * kSkityKappa;
    float dy = ry * kSkityKappa;

    if (dir == kCW) {
        MoveTo(cx + rx, cy);
        CubicTo(cx + rx, cy + dy, cx + dx, cy + ry, cx, cy + ry);
        CubicTo(cx - dx, cy + ry, cx - rx, cy + dy, cx - rx, cy);
        CubicTo(cx - rx, cy - dy, cx - dx, cy - ry, cx, cy - ry);
        CubicTo(cx + dx, cy - ry, cx + rx, cy - dy, cx + rx, cy);
    } else {
        MoveTo(cx + rx, cy);
        CubicTo(cx + rx, cy - dy, cx + dx, cy - ry, cx, cy - ry);
        CubicTo(cx - dx, cy - ry, cx - rx, cy - dy, cx - rx, cy);
        CubicTo(cx - rx, cy + dy, cx - dx, cy + ry, cx, cy + ry);
        CubicTo(cx + dx, cy + ry, cx + rx, cy + dy, cx + rx, cy);
    }
    Close();

    return *this;
}

/**
 * @brief AddRRect: Adds rounded rectangle path.
 * EN: Converts 4 rounded corners into circular/elliptical arcs connected by straight lines.
 * VN: Thêm đường bao hình chữ nhật bo tròn với 4 góc bo elip.
 */
Path& Path::AddRRect(const RRect& rrect, Direction dir) {
    if (rrect.rect().IsEmpty()) return *this;

    if (rrect.type() == RRect::kRect) {
        return AddRect(rrect.rect(), dir);
    }
    if (rrect.type() == RRect::kOval) {
        return AddOval(rrect.rect(), dir);
    }

    const Rect& bounds = rrect.rect();
    const auto& radii = rrect.radii();

    float l = bounds.left, t = bounds.top, r = bounds.right, b = bounds.bottom;
    const Vec2& ul = radii[RRect::kUpperLeft];
    const Vec2& ur = radii[RRect::kUpperRight];
    const Vec2& br = radii[RRect::kLowerRight];
    const Vec2& bl = radii[RRect::kLowerLeft];

    if (dir == kCW) {
        MoveTo(l + ul.x, t);
        LineTo(r - ur.x, t);
        if (ur.x > 0.0f || ur.y > 0.0f) {
            CubicTo(r - ur.x + ur.x * kSkityKappa, t,
                    r, t + ur.y - ur.y * kSkityKappa,
                    r, t + ur.y);
        }
        LineTo(r, b - br.y);
        if (br.x > 0.0f || br.y > 0.0f) {
            CubicTo(r, b - br.y + br.y * kSkityKappa,
                    r - br.x + br.x * kSkityKappa, b,
                    r - br.x, b);
        }
        LineTo(l + bl.x, b);
        if (bl.x > 0.0f || bl.y > 0.0f) {
            CubicTo(l + bl.x - bl.x * kSkityKappa, b,
                    l, b - bl.y + bl.y * kSkityKappa,
                    l, b - bl.y);
        }
        LineTo(l, t + ul.y);
        if (ul.x > 0.0f || ul.y > 0.0f) {
            CubicTo(l, t + ul.y - ul.y * kSkityKappa,
                    l + ul.x - ul.x * kSkityKappa, t,
                    l + ul.x, t);
        }
    } else {
        MoveTo(l + ul.x, t);
        if (ul.x > 0.0f || ul.y > 0.0f) {
            CubicTo(l + ul.x - ul.x * kSkityKappa, t,
                    l, t + ul.y - ul.y * kSkityKappa,
                    l, t + ul.y);
        }
        LineTo(l, b - bl.y);
        if (bl.x > 0.0f || bl.y > 0.0f) {
            CubicTo(l, b - bl.y + bl.y * kSkityKappa,
                    l + bl.x - bl.x * kSkityKappa, b,
                    l + bl.x, b);
        }
        LineTo(r - br.x, b);
        if (br.x > 0.0f || br.y > 0.0f) {
            CubicTo(r - br.x + br.x * kSkityKappa, b,
                    r, b - br.y + br.y * kSkityKappa,
                    r, b - br.y);
        }
        LineTo(r, t + ur.y);
        if (ur.x > 0.0f || ur.y > 0.0f) {
            CubicTo(r, t + ur.y - ur.y * kSkityKappa,
                    r - ur.x + ur.x * kSkityKappa, t,
                    r - ur.x, t);
        }
        LineTo(l + ul.x, t);
    }
    Close();

    return *this;
}

/**
 * @brief ArcTo: W3C SVG Elliptical Arc to Cubic Beziers.
 * EN: Matches AArch64 opcode 0xf79b8 (1368 bytes in binary).
 *     Converts endpoint parameterization (rx, ry, phi, largeArc, sweep, x, y)
 *     into center parameterization, scales radii if necessary, and subdivides
 *     the angular span into cubic Bezier segments <= pi / 2.
 * VN: Khớp opcode AArch64 0xf79b8 (1368 bytes). Giải mã thuật toán W3C SVG ArcTo
 *     chuyển cung tròn elip thành chuỗi đường cong cubic Bezier trơn mượt.
 */
Path& Path::ArcTo(float rx, float ry, float x_axis_rotate, ArcSize arc_size,
                  Direction sweep, float x, float y) {
    if (verbs_.empty()) {
        MoveTo(0.0f, 0.0f);
    }
    float x0 = current_pt_.x;
    float y0 = current_pt_.y;

    // Check degenerate points
    if (std::fabs(x0 - x) < 1e-6f && std::fabs(y0 - y) < 1e-6f) {
        return *this;
    }

    rx = std::fabs(rx);
    ry = std::fabs(ry);
    if (rx < 1e-6f || ry < 1e-6f) {
        return LineTo(x, y);
    }

    float phi = x_axis_rotate * (kSkityPi / 180.0f);
    float cos_phi = std::cos(phi);
    float sin_phi = std::sin(phi);

    // Compute (x1', y1') in rotated coordinate frame
    float dx = (x0 - x) * 0.5f;
    float dy = (y0 - y) * 0.5f;
    float x1_prime = cos_phi * dx + sin_phi * dy;
    float y1_prime = -sin_phi * dx + cos_phi * dy;

    // Correct radii if necessary (Step 3: Ensure radii are large enough)
    float lambda = (x1_prime * x1_prime) / (rx * rx) + (y1_prime * y1_prime) / (ry * ry);
    if (lambda > 1.0f) {
        float sqrt_lambda = std::sqrt(lambda);
        rx *= sqrt_lambda;
        ry *= sqrt_lambda;
    }

    // Step 2: Compute center (cx', cy')
    float rx_sq = rx * rx;
    float ry_sq = ry * ry;
    float x1_prime_sq = x1_prime * x1_prime;
    float y1_prime_sq = y1_prime * y1_prime;

    float numerator = rx_sq * ry_sq - rx_sq * y1_prime_sq - ry_sq * x1_prime_sq;
    float denominator = rx_sq * y1_prime_sq + ry_sq * x1_prime_sq;
    float sq = (denominator > 1e-7f) ? std::max(0.0f, numerator / denominator) : 0.0f;
    float coef = std::sqrt(sq);
    if ((arc_size == kLarge) == (sweep == kCW)) {
        coef = -coef;
    }

    float cx_prime = coef * ((rx * y1_prime) / ry);
    float cy_prime = coef * (-(ry * x1_prime) / rx);

    // Compute center in original frame (cx, cy)
    float mid_x = (x0 + x) * 0.5f;
    float mid_y = (y0 + y) * 0.5f;
    float cx = cos_phi * cx_prime - sin_phi * cy_prime + mid_x;
    float cy = sin_phi * cx_prime + cos_phi * cy_prime + mid_y;

    // Step 4: Compute angles theta1 and delta_theta
    auto AngleBetween = [](float ux, float uy, float vx, float vy) -> float {
        float dot = ux * vx + uy * vy;
        float len = std::sqrt((ux * ux + uy * uy) * (vx * vx + vy * vy));
        if (len < 1e-7f) return 0.0f;
        float cos_a = std::max(-1.0f, std::min(1.0f, dot / len));
        float angle = std::acos(cos_a);
        if (ux * vy - uy * vx < 0.0f) {
            angle = -angle;
        }
        return angle;
    };

    float vx1 = (x1_prime - cx_prime) / rx;
    float vy1 = (y1_prime - cy_prime) / ry;
    float vx2 = (-x1_prime - cx_prime) / rx;
    float vy2 = (-y1_prime - cy_prime) / ry;

    float theta1 = AngleBetween(1.0f, 0.0f, vx1, vy1);
    float delta_theta = AngleBetween(vx1, vy1, vx2, vy2);

    if (sweep == kCCW && delta_theta > 0.0f) {
        delta_theta -= 2.0f * kSkityPi;
    } else if (sweep == kCW && delta_theta < 0.0f) {
        delta_theta += 2.0f * kSkityPi;
    }

    // Subdivide delta_theta into segments of <= pi / 2
    int num_segments = static_cast<int>(std::ceil(std::fabs(delta_theta) / (kSkityPi * 0.5f)));
    if (num_segments < 1) num_segments = 1;
    float step = delta_theta / num_segments;

    float current_theta = theta1;
    for (int i = 0; i < num_segments; ++i) {
        float next_theta = current_theta + step;

        // Approximate arc segment with cubic Bezier
        float half_step = step * 0.5f;
        float alpha = (4.0f / 3.0f) * std::tan(half_step * 0.5f);

        float cos_t1 = std::cos(current_theta);
        float sin_t1 = std::sin(current_theta);
        float cos_t2 = std::cos(next_theta);
        float sin_t2 = std::sin(next_theta);

        // Control points in unit ellipse frame
        float ep1_x = cos_t1 - alpha * sin_t1;
        float ep1_y = sin_t1 + alpha * cos_t1;
        float ep2_x = cos_t2 + alpha * sin_t2;
        float ep2_y = sin_t2 - alpha * cos_t2;

        // Map back to screen space
        auto MapToScreen = [&](float ex, float ey) -> Point {
            float sx = rx * ex;
            float sy = ry * ey;
            return Point(
                cos_phi * sx - sin_phi * sy + cx,
                sin_phi * sx + cos_phi * sy + cy
            );
        };

        Point cp1 = MapToScreen(ep1_x, ep1_y);
        Point cp2 = MapToScreen(ep2_x, ep2_y);
        Point p2  = (i == num_segments - 1) ? Point(x, y) : MapToScreen(cos_t2, sin_t2);

        CubicTo(cp1.x, cp1.y, cp2.x, cp2.y, p2.x, p2.y);
        current_theta = next_theta;
    }

    return *this;
}

/**
 * @brief HasOnlyMoveTos: Fast inspection if path has no drawable contours.
 * EN: Matches AArch64 opcode 0xf802c.
 * VN: Khớp opcode AArch64 0xf802c. Kiểm tra nếu path chỉ chứa lệnh di chuyển con trỏ MoveTo.
 */
bool Path::HasOnlyMoveTos() const {
    for (uint8_t verb : verbs_) {
        if (verb != kMove) {
            return false;
        }
    }
    return true;
}

Rect Path::ComputeBounds() const {
    if (points_.empty()) return Rect::MakeEmpty();

    float l = points_[0].x, r = points_[0].x;
    float t = points_[0].y, b = points_[0].y;

    for (const auto& pt : points_) {
        l = std::min(l, pt.x);
        r = std::max(r, pt.x);
        t = std::min(t, pt.y);
        b = std::max(b, pt.y);
    }
    return Rect(l, t, r, b);
}

void Path::Transform(const Matrix& matrix) {
    if (matrix.IsIdentity() || points_.empty()) return;
    matrix.MapPoints(points_.data(), points_.data(), static_cast<int>(points_.size()));
}

// ==============================================================================
// Path Iterators (Iter & RawIter)
// ==============================================================================

Path::Iter::Iter(const Path& path, bool force_close)
    : path_(path),
      force_close_(force_close),
      verb_idx_(0),
      pt_idx_(0),
      weight_idx_(0),
      last_move_to_(0.0f, 0.0f),
      last_pt_(0.0f, 0.0f),
      closed_contour_(false),
      conic_weight_(1.0f) {}

Path::Verb Path::Iter::Next(Point pts[4]) {
    if (verb_idx_ >= path_.verbs().size()) {
        return kDone;
    }

    Verb v = static_cast<Verb>(path_.verbs()[verb_idx_++]);
    switch (v) {
        case kMove:
            pts[0] = path_.points()[pt_idx_++];
            last_move_to_ = pts[0];
            last_pt_ = pts[0];
            closed_contour_ = false;
            break;
        case kLine:
            pts[0] = last_pt_;
            pts[1] = path_.points()[pt_idx_++];
            last_pt_ = pts[1];
            break;
        case kQuad:
            pts[0] = last_pt_;
            pts[1] = path_.points()[pt_idx_++];
            pts[2] = path_.points()[pt_idx_++];
            last_pt_ = pts[2];
            break;
        case kConic:
            pts[0] = last_pt_;
            pts[1] = path_.points()[pt_idx_++];
            pts[2] = path_.points()[pt_idx_++];
            conic_weight_ = path_.weights()[weight_idx_++];
            last_pt_ = pts[2];
            break;
        case kCubic:
            pts[0] = last_pt_;
            pts[1] = path_.points()[pt_idx_++];
            pts[2] = path_.points()[pt_idx_++];
            pts[3] = path_.points()[pt_idx_++];
            last_pt_ = pts[3];
            break;
        case kClose:
            pts[0] = last_pt_;
            pts[1] = last_move_to_;
            last_pt_ = last_move_to_;
            closed_contour_ = true;
            break;
        default:
            return kDone;
    }
    return v;
}

/**
 * @brief IsClosedContour: Checks if current contour was explicitly closed.
 * EN: Matches AArch64 opcode 0xf6cf0.
 * VN: Khớp opcode AArch64 0xf6cf0. Kiểm tra contour hiện tại có khép kín không.
 */
bool Path::Iter::IsClosedContour() const {
    return closed_contour_ || force_close_;
}

/**
 * @brief SetPath: Resets RawIter to start of new path.
 * EN: Matches AArch64 opcode 0xf6d64.
 * VN: Khớp opcode AArch64 0xf6d64. Thiết lập path mới cho bộ duyệt RawIter.
 */
void Path::RawIter::SetPath(const Path& path) {
    path_ = &path;
    verb_idx_ = 0;
    pt_idx_ = 0;
    weight_idx_ = 0;
    conic_weight_ = 1.0f;
}

Path::Verb Path::RawIter::Next(Point pts[4]) {
    if (!path_ || verb_idx_ >= path_->verbs().size()) {
        return kDone;
    }

    Verb v = static_cast<Verb>(path_->verbs()[verb_idx_++]);
    switch (v) {
        case kMove:
            pts[0] = path_->points()[pt_idx_++];
            break;
        case kLine:
            pts[0] = path_->points()[pt_idx_ - 1];
            pts[1] = path_->points()[pt_idx_++];
            break;
        case kQuad:
            pts[0] = path_->points()[pt_idx_ - 1];
            pts[1] = path_->points()[pt_idx_++];
            pts[2] = path_->points()[pt_idx_++];
            break;
        case kConic:
            pts[0] = path_->points()[pt_idx_ - 1];
            pts[1] = path_->points()[pt_idx_++];
            pts[2] = path_->points()[pt_idx_++];
            conic_weight_ = path_->weights()[weight_idx_++];
            break;
        case kCubic:
            pts[0] = path_->points()[pt_idx_ - 1];
            pts[1] = path_->points()[pt_idx_++];
            pts[2] = path_->points()[pt_idx_++];
            pts[3] = path_->points()[pt_idx_++];
            break;
        case kClose:
            break;
        default:
            return kDone;
    }
    return v;
}

} // namespace skity
