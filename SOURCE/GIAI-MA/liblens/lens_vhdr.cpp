// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_vhdr.cpp
// Description: Implementation of Video HDR Tone Mapping & Dynamic Range Expansion
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "lens_vhdr.h"
#include <cmath>
#include <algorithm>

namespace LENS::ALGORITHM {

LensAlgorithmVHDR::LensAlgorithmVHDR() = default;

bool LensAlgorithmVHDR::Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) {
    m_hdr_strength = std::clamp(config.param_strength, 0.0f, 1.5f);
    m_shadow_lift = std::clamp(config.param_radius * 0.05f, 0.0f, 0.6f);
    m_saturation_boost = 1.0f + 0.25f * m_hdr_strength;
    return true;
}

void LensAlgorithmVHDR::Reset() {
    // Stateless tone mapping
}

float LensAlgorithmVHDR::ReinhardToneMap(float l_in, float l_white_sq) {
    if (l_in <= 0.0f) return 0.0f;
    return (l_in * (1.0f + l_in / l_white_sq)) / (1.0f + l_in);
}

bool LensAlgorithmVHDR::Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) {
    if (!in_frame.isValid()) {
        return false;
    }

    if (out_frame.width != in_frame.width || out_frame.height != in_frame.height || out_frame.channels != in_frame.channels) {
        out_frame = FRAMEWORK::LensImageFrame(in_frame.width, in_frame.height, in_frame.channels);
    }

    EnhanceDynamicRange(in_frame.data.data(), out_frame.data.data(), in_frame.width, in_frame.height, in_frame.channels);
    return true;
}

void LensAlgorithmVHDR::EnhanceDynamicRange(const uint8_t* src, uint8_t* dst, int32_t width, int32_t height, int32_t channels) {
    int32_t total_pixels = width * height;
    float l_white_sq = 2.25f; // Normalized white point square (1.5^2)

    for (int32_t i = 0; i < total_pixels; ++i) {
        int32_t idx = i * channels;
        float r = src[idx + 0] / 255.0f;
        float g = src[idx + 1] / 255.0f;
        float b = src[idx + 2] / 255.0f;

        // ITU-R BT.709 Luminance
        float lum = 0.2126f * r + 0.7152f * g + 0.0722f * b;

        if (lum > 0.0001f) {
            // EN: Shadow lift curve: S(L) = L^(0.75) boosts dark shadows
            // VN: Đường cong nâng sáng vùng tối: S(L) = L^(0.75) làm nổi bật chi tiết khuất
            float shadow_boosted_lum = std::pow(lum, 1.0f - m_shadow_lift * 0.5f);

            // EN: Apply Reinhard tone mapping to compressed dynamic range
            // VN: Ánh xạ sắc độ Reinhard nén dải động bảo toàn vùng cháy sáng
            float tone_mapped_lum = ReinhardToneMap(shadow_boosted_lum * (1.0f + 0.5f * m_hdr_strength), l_white_sq);
            float scale = tone_mapped_lum / lum;

            // EN: Chroma saturation scaling
            // VN: Tinh chỉnh bão hòa sắc độ tránh bợt màu
            float hdr_r = lum + (r - lum) * m_saturation_boost;
            float hdr_g = lum + (g - lum) * m_saturation_boost;
            float hdr_b = lum + (b - lum) * m_saturation_boost;

            dst[idx + 0] = static_cast<uint8_t>(std::clamp(hdr_r * scale * 255.0f, 0.0f, 255.0f));
            dst[idx + 1] = static_cast<uint8_t>(std::clamp(hdr_g * scale * 255.0f, 0.0f, 255.0f));
            dst[idx + 2] = static_cast<uint8_t>(std::clamp(hdr_b * scale * 255.0f, 0.0f, 255.0f));
        } else {
            dst[idx + 0] = 0;
            dst[idx + 1] = 0;
            dst[idx + 2] = 0;
        }

        if (channels >= 4) {
            dst[idx + 3] = src[idx + 3];
        }
    }
}

} // namespace LENS::ALGORITHM
