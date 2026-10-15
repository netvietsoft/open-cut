// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_body_reshape.h
// Description: Body reshaping algorithms, leg extension with S-curve continuity, waist slimming
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "retouch_types.h"
#include "retouch_beauty_engine.h"
#include <vector>
#include <cmath>
#include <algorithm>

namespace retouch_sdk {

// EN: Body Reshaping & Silhouette Optimization Engine
// VN: Động cơ định hình cơ thể, kéo dài chân và thon gọn eo
class BodyReshaper {
public:
    BodyReshaper();
    ~BodyReshaper();

    // EN: Configure body reshaping parameters (Opcode 0x153168: nativeSetManualBodyIntensity)
    // VN: Thiết lập tham số định hình vóc dáng cơ thể (Opcode 0x153168: nativeSetManualBodyIntensity)
    void SetParams(const BodyReshapeParams& params);

    // EN: Get current body reshape configuration
    // VN: Lấy cấu hình tham số định hình hiện hành
    const BodyReshapeParams& GetParams() const { return m_params; }

    // EN: Apply in-frame leg extension using C1-continuous Hermite S-curve warp
    // VN: Áp dụng thuật toán kéo dài chân bảo toàn tỉ lệ với đường cong chữ S Hermite liên tục bậc 1
    void ApplyLegExtension(const ImageBuffer& src, ImageBuffer& dst);

    // EN: Apply waist slimming contraction with vertical Gaussian decay profile
    // VN: Áp dụng thuật toán thon gọn eo với phân phối suy giảm Gauss theo phương đứng
    void ApplyWaistSlimming(const ImageBuffer& src, ImageBuffer& dst);

    // EN: Execute complete body reshaping pipeline
    // VN: Thực thi toàn bộ chu trình định hình vóc dáng cơ thể
    bool ProcessFrame(const ImageBuffer& src, ImageBuffer& dst);

    // EN: Compute sampling source coordinate for a given (x, y) destination coordinate
    // VN: Tính toán tọa độ nguồn mẫu (src_x, src_y) cho tọa độ đích (x, y)
    Point2F ComputeWarpMapping(float dst_x, float dst_y, int32_t width, int32_t height) const;

private:
    BodyReshapeParams m_params;

    // EN: Cubic Hermite Smoothstep function: S(t) = 3t^2 - 2t^3 with S'(0)=0 and S'(1)=0
    // VN: Hàm trơn Hermite bậc 3: S(t) = 3t^2 - 2t^3 đảm bảo đạo hàm biên bằng 0
    static inline float Smoothstep(float t) {
        t = std::clamp(t, 0.0f, 1.0f);
        return t * t * (3.0f - 2.0f * t);
    }
};

} // namespace retouch_sdk
