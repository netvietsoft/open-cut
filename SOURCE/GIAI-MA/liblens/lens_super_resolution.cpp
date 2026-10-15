// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_super_resolution.cpp
// Description: Implementation of Video Super Resolution (VSM) and Detail Synthesis
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "lens_super_resolution.h"
#include <cmath>
#include <algorithm>
#include <vector>

namespace LENS::ALGORITHM {

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

LensAlgorithmVSM::LensAlgorithmVSM() = default;

bool LensAlgorithmVSM::Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) {
    m_scale_factor = config.param_strength > 1.0f ? config.param_strength : 2.0f;
    m_sharpen_strength = std::clamp(config.param_radius * 0.1f, 0.1f, 1.0f);
    m_enable_edge_sharpen = true;
    return true;
}

void LensAlgorithmVSM::Reset() {
    // Reset temporal SR state
}

float LensAlgorithmVSM::Lanczos3Kernel(float x) {
    if (std::abs(x) < 1e-6f) return 1.0f;
    if (std::abs(x) >= 3.0f) return 0.0f;
    float pi_x = static_cast<float>(M_PI) * x;
    return (std::sin(pi_x) / pi_x) * (std::sin(pi_x / 3.0f) / (pi_x / 3.0f));
}

float LensAlgorithmVSM::BicubicKernel(float t) {
    float a = -0.5f;
    float x = std::abs(t);
    if (x <= 1.0f) {
        return (a + 2.0f) * (x * x * x) - (a + 3.0f) * (x * x) + 1.0f;
    } else if (x < 2.0f) {
        return a * (x * x * x) - 5.0f * a * (x * x) + 8.0f * a * x - 4.0f * a;
    }
    return 0.0f;
}

bool LensAlgorithmVSM::Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) {
    if (!in_frame.isValid()) {
        return false;
    }

    int32_t target_w = static_cast<int32_t>(in_frame.width * m_scale_factor);
    int32_t target_h = static_cast<int32_t>(in_frame.height * m_scale_factor);

    if (out_frame.width != target_w || out_frame.height != target_h || out_frame.channels != in_frame.channels) {
        out_frame = FRAMEWORK::LensImageFrame(target_w, target_h, in_frame.channels);
    }

    bool ok = Upscale2x(in_frame.data.data(), in_frame.width, in_frame.height, in_frame.channels,
                        out_frame.data.data(), target_w, target_h);

    if (ok && m_enable_edge_sharpen) {
        ApplyHighFrequencySharpening(out_frame.data.data(), target_w, target_h, out_frame.channels, m_sharpen_strength);
    }

    return ok;
}

bool LensAlgorithmVSM::Upscale2x(const uint8_t* src, int32_t src_w, int32_t src_h, int32_t channels,
                                uint8_t* dst, int32_t dst_w, int32_t dst_h) {
    if (!src || !dst || src_w <= 0 || src_h <= 0 || dst_w <= 0 || dst_h <= 0) {
        return false;
    }

    float scale_x = static_cast<float>(src_w) / static_cast<float>(dst_w);
    float scale_y = static_cast<float>(src_h) / static_cast<float>(dst_h);

    for (int32_t y = 0; y < dst_h; ++y) {
        float src_y = (y + 0.5f) * scale_y - 0.5f;
        int32_t y_int = static_cast<int32_t>(std::floor(src_y));
        float y_frac = src_y - y_int;

        for (int32_t x = 0; x < dst_w; ++x) {
            float src_x = (x + 0.5f) * scale_x - 0.5f;
            int32_t x_int = static_cast<int32_t>(std::floor(src_x));
            float x_frac = src_x - x_int;

            for (int32_t c = 0; c < channels; ++c) {
                float val_sum = 0.0f;
                float w_sum = 0.0f;

                for (int32_t dy = -1; dy <= 2; ++dy) {
                    int32_t sy = std::clamp(y_int + dy, 0, src_h - 1);
                    float wy = BicubicKernel(dy - y_frac);

                    for (int32_t dx = -1; dx <= 2; ++dx) {
                        int32_t sx = std::clamp(x_int + dx, 0, src_w - 1);
                        float wx = BicubicKernel(dx - x_frac);
                        float w = wx * wy;

                        uint8_t pixel_val = src[(sy * src_w + sx) * channels + c];
                        val_sum += pixel_val * w;
                        w_sum += w;
                    }
                }

                float final_val = (w_sum > 0.0001f) ? (val_sum / w_sum) : 0.0f;
                dst[(y * dst_w + x) * channels + c] = static_cast<uint8_t>(std::clamp(final_val, 0.0f, 255.0f));
            }
        }
    }

    return true;
}

void LensAlgorithmVSM::ApplyHighFrequencySharpening(uint8_t* buffer, int32_t width, int32_t height, int32_t channels, float strength) {
    if (!buffer || width < 3 || height < 3) return;

    std::vector<uint8_t> temp(buffer, buffer + (width * height * channels));

    // EN: Discrete 3x3 Laplacian edge convolution:
    //     [  0, -1,  0 ]
    //     [ -1,  4, -1 ]
    //     [  0, -1,  0 ]
    // VN: Tích chập ma trận Laplace 3x3 trích xuất biên độ tương phản cao
    for (int32_t y = 1; y < height - 1; ++y) {
        for (int32_t x = 1; x < width - 1; ++x) {
            int32_t center_idx = (y * width + x) * channels;

            for (int32_t c = 0; c < std::min(channels, 3); ++c) {
                float center = temp[center_idx + c];
                float top    = temp[((y - 1) * width + x) * channels + c];
                float bottom = temp[((y + 1) * width + x) * channels + c];
                float left   = temp[(y * width + (x - 1)) * channels + c];
                float right  = temp[(y * width + (x + 1)) * channels + c];

                float laplacian = 4.0f * center - top - bottom - left - right;
                float sharpened = center + strength * laplacian;

                buffer[center_idx + c] = static_cast<uint8_t>(std::clamp(sharpened, 0.0f, 255.0f));
            }
        }
    }
}

} // namespace LENS::ALGORITHM
