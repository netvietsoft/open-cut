// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_denoise_nn.cpp
// Description: Implementation of Video Neural Denoising Process
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "lens_denoise_nn.h"
#include <cmath>
#include <algorithm>
#include <numeric>

namespace LENS::ALGORITHM {

VideoDenoiseNNProcess::VideoDenoiseNNProcess() = default;

bool VideoDenoiseNNProcess::Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) {
    m_denoise_strength = std::clamp(config.param_strength, 0.0f, 1.0f);
    Reset();
    return true;
}

void VideoDenoiseNNProcess::Reset() {
    m_has_previous_frame = false;
    m_previous_frame_buffer.clear();
}

float VideoDenoiseNNProcess::EstimateNoiseFloor(const uint8_t* buffer, int32_t width, int32_t height, int32_t channels) {
    if (!buffer || width < 4 || height < 4) return 5.0f;

    // EN: Fast Immerkaer noise estimator: sigma = sqrt(pi/2) * (1 / (6*(W-2)*(H-2))) * sum(|N(x, y)|)
    // VN: Ước tính độ lệch chuẩn nhiễu nhanh theo công thức Immerkaer
    float sum_lap = 0.0f;
    int32_t count = 0;

    for (int32_t y = 1; y < height - 1; y += 2) {
        for (int32_t x = 1; x < width - 1; x += 2) {
            int32_t idx = (y * width + x) * channels;
            float c = buffer[idx];
            float top = buffer[((y - 1) * width + x) * channels];
            float bot = buffer[((y + 1) * width + x) * channels];
            float lft = buffer[(y * width + (x - 1)) * channels];
            float rgt = buffer[(y * width + (x + 1)) * channels];

            float lap = std::abs(4.0f * c - top - bot - lft - rgt);
            sum_lap += lap;
            count++;
        }
    }

    if (count == 0) return 5.0f;
    float sigma = (1.253314f * sum_lap) / (static_cast<float>(count) * 6.0f);
    return std::clamp(sigma, 2.0f, 30.0f);
}

bool VideoDenoiseNNProcess::Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) {
    if (!in_frame.isValid()) {
        return false;
    }

    if (out_frame.width != in_frame.width || out_frame.height != in_frame.height || out_frame.channels != in_frame.channels) {
        out_frame = FRAMEWORK::LensImageFrame(in_frame.width, in_frame.height, in_frame.channels);
    }

    float noise_sigma = EstimateNoiseFloor(in_frame.data.data(), in_frame.width, in_frame.height, in_frame.channels);

    if (!m_has_previous_frame || m_previous_frame_buffer.size() != in_frame.data.size()) {
        // First frame: direct copy to output and initialize temporal history
        std::copy(in_frame.data.begin(), in_frame.data.end(), out_frame.data.begin());
        m_previous_frame_buffer = in_frame.data;
        m_has_previous_frame = true;
        return true;
    }

    TemporalDenoisePass(in_frame.data.data(), m_previous_frame_buffer.data(), out_frame.data.data(),
                        in_frame.width, in_frame.height, in_frame.channels, noise_sigma);

    // Save filtered result to temporal feedback loop
    std::copy(out_frame.data.begin(), out_frame.data.end(), m_previous_frame_buffer.begin());
    return true;
}

void VideoDenoiseNNProcess::TemporalDenoisePass(const uint8_t* current, const uint8_t* previous, uint8_t* dst,
                                                int32_t width, int32_t height, int32_t channels, float noise_sigma) {
    int32_t total_pixels = width * height;
    float threshold = std::max(4.0f, noise_sigma * 2.5f);

    for (int32_t i = 0; i < total_pixels; ++i) {
        int32_t base = i * channels;

        float diff_sum = 0.0f;
        for (int32_t c = 0; c < std::min(channels, 3); ++c) {
            diff_sum += std::abs(static_cast<float>(current[base + c]) - static_cast<float>(previous[base + c]));
        }
        float mean_diff = diff_sum / 3.0f;

        // EN: Motion-adaptive blending factor alpha: High motion -> alpha = 1.0 (keep current), Static -> alpha = 0.2 (strong temporal averaging)
        // VN: Hệ số hòa trộn thích ứng chuyển động: Chuyển động nhanh -> giữ khung hiện tại, Tĩnh -> khử nhiễu thời gian sâu
        float motion_factor = std::clamp(mean_diff / threshold, 0.0f, 1.0f);
        float alpha = std::clamp((1.0f - m_denoise_strength) + m_denoise_strength * motion_factor, 0.15f, 1.0f);

        for (int32_t c = 0; c < std::min(channels, 3); ++c) {
            float cur = current[base + c];
            float prv = previous[base + c];
            float denoised = alpha * cur + (1.0f - alpha) * prv;
            dst[base + c] = static_cast<uint8_t>(std::clamp(denoised, 0.0f, 255.0f));
        }

        if (channels >= 4) {
            dst[base + 3] = current[base + 3];
        }
    }
}

} // namespace LENS::ALGORITHM
