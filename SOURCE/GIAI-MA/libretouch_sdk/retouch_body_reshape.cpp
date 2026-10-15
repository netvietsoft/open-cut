// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_body_reshape.cpp
// Description: Implementation of body reshaping, Hermite leg elongation, waist contraction
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "retouch_body_reshape.h"
#include <algorithm>
#include <cmath>
#include <cstring>

namespace retouch_sdk {

// EN: Constructor
// VN: Hàm khởi tạo
BodyReshaper::BodyReshaper() = default;

// EN: Destructor
// VN: Hàm hủy
BodyReshaper::~BodyReshaper() = default;

// EN: Configure body reshaping parameters with bounds clamping (Opcode 0x153168)
// VN: Thiết lập cấu hình tham số định hình vóc dáng với giới hạn an toàn (Opcode 0x153168)
void BodyReshaper::SetParams(const BodyReshapeParams& params) {
    m_params.leg_extend_ratio = std::clamp(params.leg_extend_ratio, 0.0f, 0.40f);
    m_params.waist_slim_ratio = std::clamp(params.waist_slim_ratio, 0.0f, 0.30f);
    m_params.hip_line_y       = std::clamp(params.hip_line_y, 0.30f, 0.80f);
    m_params.ankle_line_y     = std::clamp(params.ankle_line_y, m_params.hip_line_y + 0.10f, 0.98f);
}

// EN: Compute sampling source coordinate for a given (x, y) destination coordinate
// VN: Tính toán tọa độ nguồn mẫu (src_x, src_y) cho tọa độ đích (x, y)
Point2F BodyReshaper::ComputeWarpMapping(float dst_x, float dst_y, int32_t width, int32_t height) const {
    if (width <= 0 || height <= 0) {
        return Point2F(dst_x, dst_y);
    }

    float src_y = dst_y;
    float src_x = dst_x;

    // 1. Leg Extension: Vertical warp along Y-axis with Hermite S-Curve
    // VN: Kéo dài chân: Biến dạng trục dọc Y dùng đường cong Hermite trơn
    float y_hip = m_params.hip_line_y * static_cast<float>(height);
    float y_ankle = m_params.ankle_line_y * static_cast<float>(height);
    float leg_height = y_ankle - y_hip;

    if (m_params.leg_extend_ratio > 0.001f && leg_height > 10.0f) {
        float max_stretch = leg_height * m_params.leg_extend_ratio;

        if (dst_y <= y_hip) {
            // Upper torso preserved 100% without vertical shift
            src_y = dst_y;
        } else if (dst_y >= y_ankle) {
            // Feet region shifted down rigidly preserving foot anatomy
            src_y = dst_y - max_stretch;
        } else {
            // Transition zone: smooth cubic Hermite interpolation
            float t = (dst_y - y_hip) / leg_height;
            float s = Smoothstep(t);
            src_y = dst_y - max_stretch * s;
        }
    }

    // 2. Waist Slimming: Horizontal contraction towards vertical midline
    // VN: Thon gọn eo: Thu hẹp chiều ngang hướng vào trục trung tâm
    if (m_params.waist_slim_ratio > 0.001f) {
        float y_waist = (m_params.hip_line_y - 0.15f) * static_cast<float>(height);
        float sigma_y = 0.10f * static_cast<float>(height);
        float dy = src_y - y_waist;
        float gaussian_y = std::exp(-(dy * dy) / (2.0f * sigma_y * sigma_y));

        float x_center = static_cast<float>(width) * 0.5f;
        float dx = dst_x - x_center;

        // Inverse mapping: sample from wider region in source
        float contraction_factor = 1.0f + m_params.waist_slim_ratio * gaussian_y * 0.40f;
        src_x = x_center + dx * contraction_factor;
    }

    return Point2F(src_x, src_y);
}

// EN: Apply in-frame leg extension using C1-continuous Hermite S-curve warp
// VN: Áp dụng thuật toán kéo dài chân bảo toàn tỉ lệ với đường cong chữ S Hermite liên tục bậc 1
void BodyReshaper::ApplyLegExtension(const ImageBuffer& src, ImageBuffer& dst) {
    if (m_params.leg_extend_ratio <= 0.001f) {
        dst = src;
        return;
    }

    dst = ImageBuffer(src.width, src.height);

    for (int y = 0; y < src.height; ++y) {
        Point2F mapped = ComputeWarpMapping(0.0f, static_cast<float>(y), src.width, src.height);
        float src_y = mapped.y;

        int y0 = std::clamp(static_cast<int>(src_y), 0, src.height - 1);
        int y1 = std::clamp(y0 + 1, 0, src.height - 1);
        float fy = src_y - static_cast<float>(y0);

        for (int x = 0; x < src.width; ++x) {
            const uint8_t* p0 = src.GetPixel(x, y0);
            const uint8_t* p1 = src.GetPixel(x, y1);
            uint8_t* out_p = dst.GetPixel(x, y);

            if (p0 && p1 && out_p) {
                for (int c = 0; c < 4; ++c) {
                    float val = (1.0f - fy) * p0[c] + fy * p1[c];
                    out_p[c] = static_cast<uint8_t>(std::clamp(val, 0.0f, 255.0f));
                }
            }
        }
    }
}

// EN: Apply waist slimming contraction with vertical Gaussian decay profile
// VN: Áp dụng thuật toán thon gọn eo với phân phối suy giảm Gauss theo phương đứng
void BodyReshaper::ApplyWaistSlimming(const ImageBuffer& src, ImageBuffer& dst) {
    if (m_params.waist_slim_ratio <= 0.001f) {
        dst = src;
        return;
    }

    dst = ImageBuffer(src.width, src.height);

    for (int y = 0; y < src.height; ++y) {
        for (int x = 0; x < src.width; ++x) {
            Point2F mapped = ComputeWarpMapping(static_cast<float>(x), static_cast<float>(y), src.width, src.height);
            float src_x = mapped.x;

            int x0 = std::clamp(static_cast<int>(src_x), 0, src.width - 1);
            int x1 = std::clamp(x0 + 1, 0, src.width - 1);
            float fx = src_x - static_cast<float>(x0);

            const uint8_t* p0 = src.GetPixel(x0, y);
            const uint8_t* p1 = src.GetPixel(x1, y);
            uint8_t* out_p = dst.GetPixel(x, y);

            if (p0 && p1 && out_p) {
                for (int c = 0; c < 4; ++c) {
                    float val = (1.0f - fx) * p0[c] + fx * p1[c];
                    out_p[c] = static_cast<uint8_t>(std::clamp(val, 0.0f, 255.0f));
                }
            }
        }
    }
}

// EN: Execute complete body reshaping pipeline combining leg extension and waist slimming (Opcode 0x153168)
// VN: Thực thi toàn bộ chu trình định hình vóc dáng kết hợp kéo dài chân và thon gọn eo (Opcode 0x153168)
bool BodyReshaper::ProcessFrame(const ImageBuffer& src, ImageBuffer& dst) {
    if (src.data.empty() || src.width <= 0 || src.height <= 0) {
        return false;
    }

    dst = ImageBuffer(src.width, src.height);

    // Fast unified pass: evaluate full 2D mapping (src_x, src_y) with bilinear interpolation
    for (int y = 0; y < src.height; ++y) {
        for (int x = 0; x < src.width; ++x) {
            Point2F mapped = ComputeWarpMapping(static_cast<float>(x), static_cast<float>(y), src.width, src.height);

            int x0 = std::clamp(static_cast<int>(mapped.x), 0, src.width - 1);
            int y0 = std::clamp(static_cast<int>(mapped.y), 0, src.height - 1);
            int x1 = std::clamp(x0 + 1, 0, src.width - 1);
            int y1 = std::clamp(y0 + 1, 0, src.height - 1);

            float fx = mapped.x - static_cast<float>(x0);
            float fy = mapped.y - static_cast<float>(y0);

            const uint8_t* p00 = src.GetPixel(x0, y0);
            const uint8_t* p10 = src.GetPixel(x1, y0);
            const uint8_t* p01 = src.GetPixel(x0, y1);
            const uint8_t* p11 = src.GetPixel(x1, y1);
            uint8_t* out_p = dst.GetPixel(x, y);

            if (p00 && p10 && p01 && p11 && out_p) {
                for (int c = 0; c < 4; ++c) {
                    float val = (1.0f - fx) * (1.0f - fy) * p00[c] +
                                fx * (1.0f - fy) * p10[c] +
                                (1.0f - fx) * fy * p01[c] +
                                fx * fy * p11[c];
                    out_p[c] = static_cast<uint8_t>(std::clamp(val, 0.0f, 255.0f));
                }
            }
        }
    }

    return true;
}

} // namespace retouch_sdk
