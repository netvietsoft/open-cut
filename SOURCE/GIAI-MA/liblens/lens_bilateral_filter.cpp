// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_bilateral_filter.cpp
// Description: Implementation of Bilateral Weight Pass & Hierarchical Skin Filter
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "lens_bilateral_filter.h"
#include <cmath>
#include <algorithm>

namespace LENS::ALGORITHM {

BilateralWeightPass::BilateralWeightPass() {
    PrecomputeSpatialKernel(3, 2.5f);
}

// EN: Precompute Gaussian weights G_s(dx, dy) = exp(-(dx^2 + dy^2)/(2*sigma_s^2))
// VN: Tính trước bảng trọng số không gian Gaussian
void BilateralWeightPass::PrecomputeSpatialKernel(int32_t radius, float sigma_s) {
    m_radius = radius;
    m_sigma_s = std::max(0.1f, sigma_s);
    int32_t size = 2 * m_radius + 1;
    m_spatial_kernel.resize(size * size);

    float inv_2_sigma_sq = 1.0f / (2.0f * m_sigma_s * m_sigma_s);
    for (int32_t dy = -m_radius; dy <= m_radius; ++dy) {
        for (int32_t dx = -m_radius; dx <= m_radius; ++dx) {
            float dist_sq = static_cast<float>(dx * dx + dy * dy);
            float weight = std::exp(-dist_sq * inv_2_sigma_sq);
            int32_t idx = (dy + m_radius) * size + (dx + m_radius);
            m_spatial_kernel[idx] = weight;
        }
    }
}

inline float BilateralWeightPass::ComputeRangeWeight(float delta_lum, float inv_2_sigma_r_sq) const {
    return std::exp(-delta_lum * delta_lum * inv_2_sigma_r_sq);
}

HierarchicalBilateralFilter::HierarchicalBilateralFilter() {
    m_weight_pass.PrecomputeSpatialKernel(m_radius, m_sigma_spatial);
}

bool HierarchicalBilateralFilter::Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) {
    m_sigma_spatial = config.param_sigma_spatial > 0.0f ? config.param_sigma_spatial : 3.0f;
    m_sigma_range = config.param_sigma_range > 0.0f ? config.param_sigma_range : 0.12f;
    m_smooth_strength = std::clamp(config.param_strength, 0.0f, 1.0f);
    m_radius = std::clamp(static_cast<int32_t>(config.param_radius), 1, 7);

    m_weight_pass.PrecomputeSpatialKernel(m_radius, m_sigma_spatial);
    return true;
}

void HierarchicalBilateralFilter::Reset() {
    // Stateless filter, resets default configurations
}

bool HierarchicalBilateralFilter::Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) {
    if (!in_frame.isValid()) {
        return false;
    }

    if (out_frame.width != in_frame.width || out_frame.height != in_frame.height || out_frame.channels != in_frame.channels) {
        out_frame = FRAMEWORK::LensImageFrame(in_frame.width, in_frame.height, in_frame.channels);
    }

    return FilterBuffer(in_frame.data.data(), out_frame.data.data(), in_frame.width, in_frame.height, in_frame.channels);
}

bool HierarchicalBilateralFilter::FilterBuffer(const uint8_t* src, uint8_t* dst, int32_t width, int32_t height, int32_t channels) {
    if (!src || !dst || width <= 0 || height <= 0 || channels < 3) {
        return false;
    }

    const auto& spatial_kernel = m_weight_pass.GetSpatialKernel();
    int32_t radius = m_weight_pass.GetRadius();
    int32_t k_size = 2 * radius + 1;
    float inv_2_sigma_r_sq = 1.0f / (2.0f * m_sigma_range * m_sigma_range * 255.0f * 255.0f);

    for (int32_t y = 0; y < height; ++y) {
        for (int32_t x = 0; x < width; ++x) {
            int32_t center_idx = (y * width + x) * channels;
            uint8_t c_r = src[center_idx + 0];
            uint8_t c_g = src[center_idx + 1];
            uint8_t c_b = src[center_idx + 2];
            float c_lum = 0.299f * c_r + 0.587f * c_g + 0.114f * c_b;

            // EN: Skin detection mask heuristic: R > G > B and (R - G) > 15
            // VN: Heuristic phát hiện vùng da: R > G > B và (R - G) > 15
            bool is_skin = (c_r > c_g) && (c_g > c_b) && ((c_r - c_g) > 15) && (c_r > 60);

            if (!is_skin && m_skin_detect_only) {
                // EN: Bypass non-skin regions (preserve sharp eyes, eyebrows, background)
                // VN: Giữ nguyên vùng không phải da (bảo tồn mắt sắc nét, chân mày, phông nền)
                for (int32_t c = 0; c < channels; ++c) {
                    dst[center_idx + c] = src[center_idx + c];
                }
                continue;
            }

            float sum_r = 0.0f, sum_g = 0.0f, sum_b = 0.0f;
            float sum_w = 0.0f;

            for (int32_t dy = -radius; dy <= radius; ++dy) {
                int32_t ny = std::clamp(y + dy, 0, height - 1);
                for (int32_t dx = -radius; dx <= radius; ++dx) {
                    int32_t nx = std::clamp(x + dx, 0, width - 1);

                    int32_t n_idx = (ny * width + nx) * channels;
                    uint8_t n_r = src[n_idx + 0];
                    uint8_t n_g = src[n_idx + 1];
                    uint8_t n_b = src[n_idx + 2];
                    float n_lum = 0.299f * n_r + 0.587f * n_g + 0.114f * n_b;

                    float delta_lum = n_lum - c_lum;
                    float s_weight = spatial_kernel[(dy + radius) * k_size + (dx + radius)];
                    float r_weight = m_weight_pass.ComputeRangeWeight(delta_lum, inv_2_sigma_r_sq);
                    float total_w = s_weight * r_weight;

                    sum_r += n_r * total_w;
                    sum_g += n_g * total_w;
                    sum_b += n_b * total_w;
                    sum_w += total_w;
                }
            }

            if (sum_w > 0.0001f) {
                float inv_w = 1.0f / sum_w;
                float filtered_r = sum_r * inv_w;
                float filtered_g = sum_g * inv_w;
                float filtered_b = sum_b * inv_w;

                // EN: Blend with original using smooth_strength parameter
                // VN: Hòa trộn với điểm ảnh gốc theo tham số cường độ làm mịn
                dst[center_idx + 0] = static_cast<uint8_t>(std::clamp((1.0f - m_smooth_strength) * c_r + m_smooth_strength * filtered_r, 0.0f, 255.0f));
                dst[center_idx + 1] = static_cast<uint8_t>(std::clamp((1.0f - m_smooth_strength) * c_g + m_smooth_strength * filtered_g, 0.0f, 255.0f));
                dst[center_idx + 2] = static_cast<uint8_t>(std::clamp((1.0f - m_smooth_strength) * c_b + m_smooth_strength * filtered_b, 0.0f, 255.0f));
            } else {
                dst[center_idx + 0] = c_r;
                dst[center_idx + 1] = c_g;
                dst[center_idx + 2] = c_b;
            }

            if (channels >= 4) {
                dst[center_idx + 3] = src[center_idx + 3]; // Preserve alpha channel
            }
        }
    }

    return true;
}

} // namespace LENS::ALGORITHM
