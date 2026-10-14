// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so
// File: cccreator_clip.h
// Description: CCClip operations and curve speed synchronization engine
// ===================================================================================

#pragma once

#include "cccreator_types.h"
#include <vector>
#include <memory>

namespace vesdk {
namespace ccmodel {

/**
 * @brief Double-precision Bezier control point for curve speed ramping in CapCut templates
 */
struct DoubleCurvePoint {
    double time;        // offset 0x08: Điểm thời gian chuẩn hóa [0.0 .. 1.0] hoặc micro-giây
    double speed;       // offset 0x10: Hệ số tốc độ biến thiên [0.1x .. 100.0x]

    DoubleCurvePoint() : time(0.0), speed(1.0) {}
    DoubleCurvePoint(double t, double s) : time(t), speed(s) {}
};

/**
 * @brief Synchronizes and converts double-precision Bezier curve speed points
 *        into single-precision float arrays for shader uniforms and playback runtime.
 *        Khớp 100% thuật toán vòng lặp dịch mã máy tại opcode 0x618118..0x618148.
 *
 * @param input_points Mảng điểm vận tốc double (từ CapCut template project JSON)
 * @param out_times Mảng thời gian single-precision float (thanh ghi x9)
 * @param out_speeds Mảng tốc độ single-precision float (thanh ghi x10)
 * @return int32_t Số điểm đã chuyển đổi
 */
int32_t updateClipCurveSpeedCCModel(
    const std::vector<DoubleCurvePoint>& input_points,
    std::vector<float>& out_times,
    std::vector<float>& out_speeds
);

/**
 * @brief Clip Manager providing segment calculations and trimming validation
 */
class CCClipManager {
public:
    static std::shared_ptr<CCClip> createClip(
        const std::string& clip_id,
        VETimeCode start_time,
        VETimeCode end_time,
        VETimeCode trim_in,
        VETimeCode trim_out,
        double speed = 1.0
    );

    static bool validateClipBounds(const CCClip& clip);
    static VETimeCode mapTimelineToSourceTime(const CCClip& clip, VETimeCode timeline_pos);
    static VETimeCode mapSourceToTimelineTime(const CCClip& clip, VETimeCode source_pos);
};

} // namespace ccmodel
} // namespace vesdk
