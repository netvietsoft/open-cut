// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Path Arc Length Parameterization & Tangent Tracking
// File: skity_path_measure.h
// Description: Skity PathMeasure implementation for calculating curve position,
//              tangent orientation, and subsegment extraction along vector paths.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_PATH_MEASURE_H_
#define NEXTAI_OPENCUT_SKITY_PATH_MEASURE_H_

#include <vector>
#include <memory>
#include "skity_geometry.h"
#include "skity_path.h"

namespace skity {

class PathMeasure {
public:
    PathMeasure();
    PathMeasure(const Path& path, bool force_close, float res = 1.0f);
    ~PathMeasure() = default;

    // Opcode 0xfb278: SetPath
    void SetPath(const Path* path, bool force_close);

    // Opcode 0xfb598: NextContour
    bool NextContour();

    // Arc length of current contour (stored at offset 0x30)
    float GetLength();

    // Opcode 0xfb370: GetPosTan
    // Evaluates position (x, y) and normalized tangent (tx, ty) at arc distance
    bool GetPosTan(float distance, Vec4* out_pos, Vec4* out_tan);

    // Subsegment extraction
    bool GetSegment(float start_d, float stop_d, Path* dst, bool start_with_move_to = true);

    bool IsClosed() const { return is_closed_; }

private:
    struct SegmentRecord {
        float distance; // Cumulative distance to end of segment
        Path::Verb verb;
        Point pts[4];
        float length;
    };

    void BuildSegments();

    const Path* path_;
    bool force_close_;
    float res_;
    size_t current_verb_idx_;
    size_t current_pt_idx_;
    float length_;
    bool is_closed_;
    std::vector<SegmentRecord> segments_;
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_PATH_MEASURE_H_
