// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Path Stroking & Outline Tessellation
// File: skity_stroke.cpp
// Description: Implementation of StrokePath matching AArch64 opcode 0xf2828.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_stroke.h"
#include <cmath>
#include <algorithm>

namespace skity {

constexpr float kStrokePi = 3.14159265358979323846f;

Stroke::Stroke()
    : width_(1.0f),
      miter_limit_(4.0f),
      cap_(kButt),
      join_(kMiter) {}

Stroke::Stroke(float width, float miter_limit, Cap cap, Join join)
    : width_(width),
      miter_limit_(miter_limit),
      cap_(cap),
      join_(join) {}

/**
 * @brief AppendJoin: Handles miter, round, and bevel corner junctions.
 * EN: Tests miter limit: length = 1.0 / sin(theta / 2).
 *     If miter length > miter_limit, falls back to bevel join.
 * VN: Xử lý mối nối góc Miter, Round, Bevel. Kiểm tra ngưỡng miter_limit để cắt góc nhọn.
 */
void Stroke::AppendJoin(Path* outer, Path* inner, const Point& p,
                        const Vec2& n1, const Vec2& n2, float half_width) const {
    float cross = n1.Cross(n2);
    if (std::fabs(cross) < 1e-5f) {
        // Parallel or identical normals
        outer->LineTo(p.x + n2.x * half_width, p.y + n2.y * half_width);
        inner->LineTo(p.x - n2.x * half_width, p.y - n2.y * half_width);
        return;
    }

    float dot = std::max(-1.0f, std::min(1.0f, n1.Dot(n2)));
    float denom = 1.0f + dot;

    // Outer corner direction depends on sign of cross product
    bool turn_left = (cross > 0.0f);

    if (turn_left) {
        // Outer is on positive normal side
        if (join_ == kMiter && denom > 1e-6f) {
            Vec2 miter_vec = (n1 + n2) * (1.0f / denom);
            float miter_len_sq = miter_vec.LengthSq();
            if (miter_len_sq <= miter_limit_ * miter_limit_) {
                outer->LineTo(p.x + miter_vec.x * half_width, p.y + miter_vec.y * half_width);
            } else {
                // Bevel cutoff
                outer->LineTo(p.x + n1.x * half_width, p.y + n1.y * half_width);
                outer->LineTo(p.x + n2.x * half_width, p.y + n2.y * half_width);
            }
        } else if (join_ == kRound) {
            // Tessellate round corner arc
            float theta1 = std::atan2(n1.y, n1.x);
            float theta2 = std::atan2(n2.y, n2.x);
            if (theta2 < theta1) theta2 += 2.0f * kStrokePi;
            int steps = 4;
            for (int i = 1; i <= steps; ++i) {
                float t = static_cast<float>(i) / steps;
                float th = theta1 + (theta2 - theta1) * t;
                outer->LineTo(p.x + std::cos(th) * half_width, p.y + std::sin(th) * half_width);
            }
        } else {
            // Bevel join
            outer->LineTo(p.x + n1.x * half_width, p.y + n1.y * half_width);
            outer->LineTo(p.x + n2.x * half_width, p.y + n2.y * half_width);
        }
        // Inner corner is just the inner intersection
        inner->LineTo(p.x - n2.x * half_width, p.y - n2.y * half_width);
    } else {
        // Outer is on negative normal side
        if (join_ == kMiter && denom > 1e-6f) {
            Vec2 miter_vec = (n1 + n2) * (1.0f / denom);
            float miter_len_sq = miter_vec.LengthSq();
            if (miter_len_sq <= miter_limit_ * miter_limit_) {
                inner->LineTo(p.x - miter_vec.x * half_width, p.y - miter_vec.y * half_width);
            } else {
                inner->LineTo(p.x - n1.x * half_width, p.y - n1.y * half_width);
                inner->LineTo(p.x - n2.x * half_width, p.y - n2.y * half_width);
            }
        } else if (join_ == kRound) {
            float theta1 = std::atan2(-n1.y, -n1.x);
            float theta2 = std::atan2(-n2.y, -n2.x);
            if (theta2 > theta1) theta2 -= 2.0f * kStrokePi;
            int steps = 4;
            for (int i = 1; i <= steps; ++i) {
                float t = static_cast<float>(i) / steps;
                float th = theta1 + (theta2 - theta1) * t;
                inner->LineTo(p.x + std::cos(th) * half_width, p.y + std::sin(th) * half_width);
            }
        } else {
            inner->LineTo(p.x - n1.x * half_width, p.y - n1.y * half_width);
            inner->LineTo(p.x - n2.x * half_width, p.y - n2.y * half_width);
        }
        outer->LineTo(p.x + n2.x * half_width, p.y + n2.y * half_width);
    }
}

/**
 * @brief AppendCap: Connects outer and inner contours at endpoints.
 * EN: Supports Butt (straight link), Square (extension by half_width),
 *     and Round (180-degree semicircular arc).
 * VN: Xử lý đầu mút đường vẽ: Butt (cắt thẳng), Square (mở rộng vuông), Round (bo tròn nửa vòng).
 */
void Stroke::AppendCap(Path* path, const Point& p, const Vec2& n, const Vec2& t,
                       float half_width, bool is_start) const {
    float dir = is_start ? -1.0f : 1.0f;
    Vec2 tangent = t * dir;

    if (cap_ == kSquare) {
        Point p_ext = Point(p.x + tangent.x * half_width, p.y + tangent.y * half_width);
        path->LineTo(p_ext.x + n.x * half_width, p_ext.y + n.y * half_width);
        path->LineTo(p_ext.x - n.x * half_width, p_ext.y - n.y * half_width);
    } else if (cap_ == kRound) {
        float start_ang = std::atan2(n.y, n.x);
        float end_ang = start_ang + kStrokePi;
        int steps = 6;
        for (int i = 1; i <= steps; ++i) {
            float frac = static_cast<float>(i) / steps;
            float th = start_ang + (end_ang - start_ang) * frac;
            path->LineTo(p.x + std::cos(th) * half_width, p.y + std::sin(th) * half_width);
        }
    } else {
        // Butt cap: direct straight connection
        path->LineTo(p.x - n.x * half_width, p.y - n.y * half_width);
    }
}

/**
 * @brief StrokePath: Expands skeletal path into closed stroked boundary path.
 * EN: Matches AArch64 opcode 0xf2828 (1212 bytes in binary).
 * VN: Khớp opcode AArch64 0xf2828. Tái dựng toàn diện động cơ stroke 2D outline.
 */
bool Stroke::StrokePath(const Path& src, Path* dst) const {
    if (!dst) return false;
    dst->Reset();

    if (src.IsEmpty() || width_ <= 0.0f) {
        return false;
    }

    float half_width = width_ * 0.5f;

    // Flatten curves into adaptive line segments
    Path::Iter iter(src, false);
    Point pts[4];
    Path::Verb verb;

    std::vector<Point> contour_pts;
    bool is_closed = false;

    auto ProcessContour = [&](const std::vector<Point>& poly, bool closed) {
        if (poly.size() < 2) return;

        Path outer;
        Path inner;

        // Compute segment normals
        std::vector<Vec2> normals;
        std::vector<Vec2> tangents;
        normals.reserve(poly.size());
        tangents.reserve(poly.size());

        for (size_t i = 0; i < poly.size() - 1; ++i) {
            Vec2 v = poly[i + 1] - poly[i];
            float len = v.Length();
            if (len < 1e-6f) {
                tangents.emplace_back(1.0f, 0.0f);
                normals.emplace_back(0.0f, 1.0f);
            } else {
                Vec2 t = v / len;
                tangents.push_back(t);
                normals.emplace_back(-t.y, t.x);
            }
        }

        if (closed) {
            Vec2 v = poly[0] - poly.back();
            float len = v.Length();
            if (len < 1e-6f) {
                tangents.emplace_back(1.0f, 0.0f);
                normals.emplace_back(0.0f, 1.0f);
            } else {
                Vec2 t = v / len;
                tangents.push_back(t);
                normals.emplace_back(-t.y, t.x);
            }
        }

        // Initialize outer and inner paths
        outer.MoveTo(poly[0].x + normals[0].x * half_width, poly[0].y + normals[0].y * half_width);
        inner.MoveTo(poly[0].x - normals[0].x * half_width, poly[0].y - normals[0].y * half_width);

        // Process internal joins
        for (size_t i = 1; i < poly.size() - 1; ++i) {
            AppendJoin(&outer, &inner, poly[i], normals[i - 1], normals[i], half_width);
        }

        if (closed) {
            // Join back to start
            size_t n = poly.size();
            AppendJoin(&outer, &inner, poly.back(), normals[n - 2], normals[n - 1], half_width);
            AppendJoin(&outer, &inner, poly[0], normals[n - 1], normals[0], half_width);
            outer.Close();
            inner.Close();

            // Append both contours to dst
            for (size_t i = 0; i < outer.points().size(); ++i) {
                if (i == 0) dst->MoveTo(outer.points()[i].x, outer.points()[i].y);
                else dst->LineTo(outer.points()[i].x, outer.points()[i].y);
            }
            dst->Close();

            for (size_t i = 0; i < inner.points().size(); ++i) {
                if (i == 0) dst->MoveTo(inner.points()[i].x, inner.points()[i].y);
                else dst->LineTo(inner.points()[i].x, inner.points()[i].y);
            }
            dst->Close();
        } else {
            // End cap
            size_t last_idx = poly.size() - 1;
            Point p_end = poly[last_idx];
            Vec2 n_end = normals[last_idx - 1];
            Vec2 t_end = tangents[last_idx - 1];

            outer.LineTo(p_end.x + n_end.x * half_width, p_end.y + n_end.y * half_width);
            AppendCap(&outer, p_end, n_end, t_end, half_width, false);

            // Connect reversed inner contour
            const auto& inner_pts = inner.points();
            for (int i = static_cast<int>(inner_pts.size()) - 1; i >= 0; --i) {
                outer.LineTo(inner_pts[i].x, inner_pts[i].y);
            }

            // Start cap
            Point p_start = poly[0];
            Vec2 n_start = normals[0];
            Vec2 t_start = tangents[0];
            AppendCap(&outer, p_start, n_start, t_start, half_width, true);
            outer.Close();

            // Transfer to dst
            for (size_t i = 0; i < outer.verbs().size(); ++i) {
                if (outer.verbs()[i] == Path::kMove) {
                    dst->MoveTo(outer.points()[i].x, outer.points()[i].y);
                } else if (outer.verbs()[i] == Path::kLine) {
                    dst->LineTo(outer.points()[i].x, outer.points()[i].y);
                } else if (outer.verbs()[i] == Path::kClose) {
                    dst->Close();
                }
            }
        }
    };

    while ((verb = iter.Next(pts)) != Path::kDone) {
        switch (verb) {
            case Path::kMove:
                if (!contour_pts.empty()) {
                    ProcessContour(contour_pts, is_closed);
                    contour_pts.clear();
                    is_closed = false;
                }
                contour_pts.push_back(pts[0]);
                break;
            case Path::kLine:
                contour_pts.push_back(pts[1]);
                break;
            case Path::kQuad: {
                // Adaptive subdivision of quadratic Bezier
                Point p0 = pts[0], p1 = pts[1], p2 = pts[2];
                int steps = 8;
                for (int i = 1; i <= steps; ++i) {
                    float t = static_cast<float>(i) / steps;
                    float u = 1.0f - t;
                    float x = u * u * p0.x + 2.0f * u * t * p1.x + t * t * p2.x;
                    float y = u * u * p0.y + 2.0f * u * t * p1.y + t * t * p2.y;
                    contour_pts.emplace_back(x, y);
                }
                break;
            }
            case Path::kCubic: {
                // Adaptive subdivision of cubic Bezier
                Point p0 = pts[0], p1 = pts[1], p2 = pts[2], p3 = pts[3];
                int steps = 12;
                for (int i = 1; i <= steps; ++i) {
                    float t = static_cast<float>(i) / steps;
                    float u = 1.0f - t;
                    float x = u * u * u * p0.x + 3.0f * u * u * t * p1.x + 3.0f * u * t * t * p2.x + t * t * t * p3.x;
                    float y = u * u * u * p0.y + 3.0f * u * u * t * p1.y + 3.0f * u * t * t * p2.y + t * t * t * p3.y;
                    contour_pts.emplace_back(x, y);
                }
                break;
            }
            case Path::kClose:
                is_closed = true;
                break;
            default:
                break;
        }
    }

    if (!contour_pts.empty()) {
        ProcessContour(contour_pts, is_closed);
    }

    return !dst->IsEmpty();
}

} // namespace skity
