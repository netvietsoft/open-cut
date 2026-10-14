// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libcccreator.so
// File: cccreator_clip.cpp
// Description: Full implementation of CCClip and updateClipCurveSpeedCCModel
// ===================================================================================

#include "cccreator_clip.h"
#include <algorithm>
#include <stdexcept>

namespace vesdk {
namespace ccmodel {

/**
 * @brief updateClipCurveSpeedCCModel
 * 
 * ARM64 Disassembly Parity (0x6180ec - 0x618148):
 *   0x6180ec: ldp x8, x9, [x22, #0x10]       ; nạp begin và end pointers
 *   0x6180f0: cmp x8, x9                     ; so sánh rỗng
 *   0x6180f4: b.eq #0x61814c                 ; nếu rỗng -> dọn sạch vector
 *   0x6180f8: sub x8, x9, x8                 ; byte size
 *   0x6180fc: sbfx x20, x8, #4, #0x20        ; số phần tử = byte_size >> 4 (16B / điểm)
 *   ...
 *   0x618118: cmp x11, x20                   ; so sánh chỉ số lặp
 *   0x61811c: b.ge #0x618188                 ; kết thúc vòng lặp
 *   0x618120: ldr x12, [x22, #0x10]          ; nạp mảng điểm
 *   0x618124: ldr x12, [x12, x8]             ; con trỏ điểm
 *   0x61812c: ldr d0, [x12, #8]              ; nạp double thời gian (offset 8)
 *   0x618130: fcvt s0, d0                    ; chuyển đổi double sang float
 *   0x618134: str s0, [x9, x11, lsl #2]      ; lưu float vào out_times (offset x11 * 4)
 *   0x618138: ldr d0, [x12, #0x10]           ; nạp double tốc độ (offset 16)
 *   0x61813c: fcvt s0, d0                    ; chuyển đổi double sang float
 *   0x618140: str s0, [x10, x11, lsl #2]     ; lưu float vào out_speeds (offset x11 * 4)
 *   0x618144: add x11, x11, #1               ; tăng chỉ số i++
 *   0x618148: b #0x618118
 */
int32_t updateClipCurveSpeedCCModel(
    const std::vector<DoubleCurvePoint>& input_points,
    std::vector<float>& out_times,
    std::vector<float>& out_speeds
) {
    size_t count = input_points.size();
    if (count == 0) {
        // Opcode 0x61814c..0x618150: zero out target vectors
        out_times.clear();
        out_speeds.clear();
        return 0;
    }

    out_times.resize(count);
    out_speeds.resize(count);

    // Exact AArch64 conversion loop
    for (size_t i = 0; i < count; ++i) {
        // d0 -> s0 conversion
        double t_d = input_points[i].time;
        double s_d = input_points[i].speed;

        float t_f = static_cast<float>(t_d);
        float s_f = static_cast<float>(s_d);

        out_times[i] = t_f;
        out_speeds[i] = s_f;
    }

    return static_cast<int32_t>(count);
}


// ===================================================================================
// CCCLIP MANAGER IMPLEMENTATION
// ===================================================================================

std::shared_ptr<CCClip> CCClipManager::createClip(
    const std::string& clip_id,
    VETimeCode start_time,
    VETimeCode end_time,
    VETimeCode trim_in,
    VETimeCode trim_out,
    double speed
) {
    auto clip = std::make_shared<CCClip>(clip_id);
    clip->setStartTime(start_time);
    clip->setEndTime(end_time);
    clip->setTrimIn(trim_in);
    clip->setTrimOut(trim_out);
    clip->speed = (speed <= 0.0) ? 1.0 : speed;
    return clip;
}

bool CCClipManager::validateClipBounds(const CCClip& clip) {
    // Timeline duration must be strictly positive
    if (clip.getEndTime() <= clip.getStartTime()) {
        return false;
    }
    // Source duration must be non-negative
    if (clip.getTrimOut() < clip.getTrimIn()) {
        return false;
    }
    return true;
}

VETimeCode CCClipManager::mapTimelineToSourceTime(const CCClip& clip, VETimeCode timeline_pos) {
    if (timeline_pos < clip.getStartTime()) {
        return clip.getTrimIn();
    }
    if (timeline_pos >= clip.getEndTime()) {
        return clip.getTrimOut();
    }

    VETimeCode timeline_offset = timeline_pos - clip.getStartTime();
    double effective_speed = (clip.speed > 0.0) ? clip.speed : 1.0;

    VETimeCode source_offset = static_cast<VETimeCode>(static_cast<double>(timeline_offset) * effective_speed);
    VETimeCode result = clip.getTrimIn() + source_offset;

    if (result > clip.getTrimOut()) {
        return clip.getTrimOut();
    }
    return result;
}

VETimeCode CCClipManager::mapSourceToTimelineTime(const CCClip& clip, VETimeCode source_pos) {
    if (source_pos < clip.getTrimIn()) {
        return clip.getStartTime();
    }
    if (source_pos >= clip.getTrimOut()) {
        return clip.getEndTime();
    }

    VETimeCode source_offset = source_pos - clip.getTrimIn();
    double effective_speed = (clip.speed > 0.0) ? clip.speed : 1.0;

    VETimeCode timeline_offset = static_cast<VETimeCode>(static_cast<double>(source_offset) / effective_speed);
    VETimeCode result = clip.getStartTime() + timeline_offset;

    if (result > clip.getEndTime()) {
        return clip.getEndTime();
    }
    return result;
}

} // namespace ccmodel
} // namespace vesdk
