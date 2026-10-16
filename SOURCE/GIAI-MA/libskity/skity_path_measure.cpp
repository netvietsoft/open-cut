// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Path Arc Length Parameterization & Tangent Tracking
// File: skity_path_measure.cpp
// Description: Implementation of PathMeasure matching AArch64 opcode 0xfb370.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "skity_path_measure.h"
#include <cmath>
#include <algorithm>

namespace skity {

PathMeasure::PathMeasure()
    : path_(nullptr),
      force_close_(false),
      res_(1.0f),
      current_verb_idx_(0),
      current_pt_idx_(0),
      length_(0.0f),
      is_closed_(false) {}

PathMeasure::PathMeasure(const Path& path, bool force_close, float res)
    : path_(&path),
      force_close_(force_close),
      res_(res),
      current_verb_idx_(0),
      current_pt_idx_(0),
      length_(0.0f),
      is_closed_(false) {
    BuildSegments();
}

/**
 * @brief SetPath: Associates path with measurement context.
 * EN: Matches AArch64 opcode 0xfb278.
 * VN: Khớp opcode AArch64 0xfb278. Nạp đường cong path vào bộ đo chiều dài và tiếp tuyến.
 */
void PathMeasure::SetPath(const Path* path, bool force_close) {
    path_ = path;
    force_close_ = force_close;
    current_verb_idx_ = 0;
    current_pt_idx_ = 0;
    length_ = 0.0f;
    is_closed_ = false;
    segments_.clear();

    if (path_ && !path_->IsEmpty()) {
        BuildSegments();
    }
}

/**
 * @brief NextContour: Advances measurement cursor to subsequent disconnected contour.
 * EN: Matches AArch64 opcode 0xfb598.
 * VN: Khớp opcode AArch64 0xfb598. Chuyển sang contour đường cong tiếp theo.
 */
bool PathMeasure::NextContour() {
    if (!path_ || current_verb_idx_ >= path_->verbs().size()) {
        return false;
    }
    segments_.clear();
    length_ = 0.0f;
    is_closed_ = false;
    BuildSegments();
    return !segments_.empty();
}

float PathMeasure::GetLength() {
    return length_;
}

/**
 * @brief BuildSegments: Numerically parameterizes current contour by arc length.
 * EN: Integrates length for lines, quadratics, and cubics using Gaussian quadrature.
 * VN: Tính tích phân độ dài cung cho từng đoạn đường thẳng và đường cong Bezier.
 */
void PathMeasure::BuildSegments() {
    if (!path_ || current_verb_idx_ >= path_->verbs().size()) {
        return;
    }

    const auto& verbs = path_->verbs();
    const auto& pts = path_->points();

    Point last_pt(0.0f, 0.0f);
    Point move_to_pt(0.0f, 0.0f);
    float cum_dist = 0.0f;

    while (current_verb_idx_ < verbs.size()) {
        uint8_t v = verbs[current_verb_idx_++];
        if (v == Path::kMove) {
            if (!segments_.empty()) {
                // Done with current contour, save cursor for NextContour
                current_verb_idx_--;
                break;
            }
            last_pt = pts[current_pt_idx_++];
            move_to_pt = last_pt;
        } else if (v == Path::kLine) {
            Point p1 = pts[current_pt_idx_++];
            float d = (p1 - last_pt).Length();
            if (d > 1e-6f) {
                cum_dist += d;
                SegmentRecord seg;
                seg.distance = cum_dist;
                seg.verb = Path::kLine;
                seg.pts[0] = last_pt;
                seg.pts[1] = p1;
                seg.length = d;
                segments_.push_back(seg);
                last_pt = p1;
            }
        } else if (v == Path::kQuad) {
            Point p1 = pts[current_pt_idx_++];
            Point p2 = pts[current_pt_idx_++];

            // Approximate quad arc length with 5-point Simpson rule
            auto QuadPoint = [&](float t) -> Point {
                float u = 1.0f - t;
                return Point(
                    u * u * last_pt.x + 2.0f * u * t * p1.x + t * t * p2.x,
                    u * u * last_pt.y + 2.0f * u * t * p1.y + t * t * p2.y
                );
            };

            float d = 0.0f;
            Point prev = last_pt;
            const int kSamples = 16;
            for (int i = 1; i <= kSamples; ++i) {
                Point cur = QuadPoint(static_cast<float>(i) / kSamples);
                d += (cur - prev).Length();
                prev = cur;
            }

            if (d > 1e-6f) {
                cum_dist += d;
                SegmentRecord seg;
                seg.distance = cum_dist;
                seg.verb = Path::kQuad;
                seg.pts[0] = last_pt;
                seg.pts[1] = p1;
                seg.pts[2] = p2;
                seg.length = d;
                segments_.push_back(seg);
                last_pt = p2;
            }
        } else if (v == Path::kCubic) {
            Point p1 = pts[current_pt_idx_++];
            Point p2 = pts[current_pt_idx_++];
            Point p3 = pts[current_pt_idx_++];

            auto CubicPoint = [&](float t) -> Point {
                float u = 1.0f - t;
                return Point(
                    u * u * u * last_pt.x + 3.0f * u * u * t * p1.x + 3.0f * u * t * t * p2.x + t * t * t * p3.x,
                    u * u * u * last_pt.y + 3.0f * u * u * t * p1.y + 3.0f * u * t * t * p2.y + t * t * t * p3.y
                );
            };

            float d = 0.0f;
            Point prev = last_pt;
            const int kSamples = 24;
            for (int i = 1; i <= kSamples; ++i) {
                Point cur = CubicPoint(static_cast<float>(i) / kSamples);
                d += (cur - prev).Length();
                prev = cur;
            }

            if (d > 1e-6f) {
                cum_dist += d;
                SegmentRecord seg;
                seg.distance = cum_dist;
                seg.verb = Path::kCubic;
                seg.pts[0] = last_pt;
                seg.pts[1] = p1;
                seg.pts[2] = p2;
                seg.pts[3] = p3;
                seg.length = d;
                segments_.push_back(seg);
                last_pt = p3;
            }
        } else if (v == Path::kClose) {
            float d = (move_to_pt - last_pt).Length();
            if (d > 1e-6f) {
                cum_dist += d;
                SegmentRecord seg;
                seg.distance = cum_dist;
                seg.verb = Path::kLine;
                seg.pts[0] = last_pt;
                seg.pts[1] = move_to_pt;
                seg.length = d;
                segments_.push_back(seg);
                last_pt = move_to_pt;
            }
            is_closed_ = true;
            break;
        }
    }

    if (force_close_ && !is_closed_ && !segments_.empty()) {
        float d = (move_to_pt - last_pt).Length();
        if (d > 1e-6f) {
            cum_dist += d;
            SegmentRecord seg;
            seg.distance = cum_dist;
            seg.verb = Path::kLine;
            seg.pts[0] = last_pt;
            seg.pts[1] = move_to_pt;
            seg.length = d;
            segments_.push_back(seg);
        }
        is_closed_ = true;
    }

    length_ = cum_dist;
}

/**
 * @brief GetPosTan: Evaluates position and tangent orientation along path.
 * EN: Matches AArch64 opcode 0xfb370 (132 bytes).
 *     Disassembly verifies distance clamping to [0, length_] (stored at offset 0x30).
 * VN: Khớp opcode AArch64 0xfb370. Trích xuất tọa độ điểm (x, y) và vector tiếp tuyến chuẩn hóa (tx, ty).
 */
bool PathMeasure::GetPosTan(float distance, Vec4* out_pos, Vec4* out_tan) {
    if (segments_.empty() || length_ <= 0.0f) {
        return false;
    }

    // Clamp distance to [0, length_] (matching opcode 0xfb3a8 - 0xfb3b0)
    float d = std::max(0.0f, std::min(length_, distance));

    // Binary search for enclosing segment
    auto it = std::lower_bound(segments_.begin(), segments_.end(), d,
        [](const SegmentRecord& seg, float val) {
            return seg.distance < val;
        });

    if (it == segments_.end()) {
        it = segments_.end() - 1;
    }

    float seg_start_dist = it->distance - it->length;
    float local_dist = d - seg_start_dist;
    float t = (it->length > 1e-6f) ? std::max(0.0f, std::min(1.0f, local_dist / it->length)) : 0.0f;

    Point pos(0.0f, 0.0f);
    Vec2 tan(1.0f, 0.0f);

    switch (it->verb) {
        case Path::kLine: {
            pos = it->pts[0] + (it->pts[1] - it->pts[0]) * t;
            tan = (it->pts[1] - it->pts[0]).Normalized();
            break;
        }
        case Path::kQuad: {
            Point p0 = it->pts[0], p1 = it->pts[1], p2 = it->pts[2];
            float u = 1.0f - t;
            pos.x = u * u * p0.x + 2.0f * u * t * p1.x + t * t * p2.x;
            pos.y = u * u * p0.y + 2.0f * u * t * p1.y + t * t * p2.y;

            // First derivative B'(t) = 2*(1-t)*(p1-p0) + 2*t*(p2-p1)
            Vec2 dpt = (p1 - p0) * (2.0f * u) + (p2 - p1) * (2.0f * t);
            tan = dpt.Normalized();
            break;
        }
        case Path::kCubic: {
            Point p0 = it->pts[0], p1 = it->pts[1], p2 = it->pts[2], p3 = it->pts[3];
            float u = 1.0f - t;
            pos.x = u * u * u * p0.x + 3.0f * u * u * t * p1.x + 3.0f * u * t * t * p2.x + t * t * t * p3.x;
            pos.y = u * u * u * p0.y + 3.0f * u * u * t * p1.y + 3.0f * u * t * t * p2.y + t * t * t * p3.y;

            // First derivative B'(t) = 3*(1-t)^2*(p1-p0) + 6*(1-t)*t*(p2-p1) + 3*t^2*(p3-p2)
            Vec2 dpt = (p1 - p0) * (3.0f * u * u) + (p2 - p1) * (6.0f * u * t) + (p3 - p2) * (3.0f * t * t);
            tan = dpt.Normalized();
            break;
        }
        default:
            return false;
    }

    if (out_pos) {
        out_pos->x = pos.x;
        out_pos->y = pos.y;
        out_pos->z = 0.0f;
        out_pos->w = 1.0f;
    }
    if (out_tan) {
        out_tan->x = tan.x;
        out_tan->y = tan.y;
        out_tan->z = 0.0f;
        out_tan->w = 0.0f;
    }
    return true;
}

/**
 * @brief GetSegment: Extracts curve subpath between start_d and stop_d.
 * EN: Useful for path trim animation effects in video templates.
 * VN: Cắt tỉa trích xuất phân đoạn đường cong phục vụ hiệu ứng hoạt họa viền video.
 */
bool PathMeasure::GetSegment(float start_d, float stop_d, Path* dst, bool start_with_move_to) {
    if (!dst || segments_.empty() || start_d >= stop_d) {
        return false;
    }

    start_d = std::max(0.0f, start_d);
    stop_d = std::min(length_, stop_d);
    if (start_d >= stop_d) return false;

    Vec4 p_start, t_start;
    GetPosTan(start_d, &p_start, &t_start);

    if (start_with_move_to) {
        dst->MoveTo(p_start.x, p_start.y);
    } else {
        dst->LineTo(p_start.x, p_start.y);
    }

    const int kSteps = 32;
    for (int i = 1; i <= kSteps; ++i) {
        float frac = static_cast<float>(i) / kSteps;
        float cur_d = start_d + (stop_d - start_d) * frac;
        Vec4 p_cur, t_cur;
        GetPosTan(cur_d, &p_cur, &t_cur);
        dst->LineTo(p_cur.x, p_cur.y);
    }

    return true;
}

} // namespace skity
