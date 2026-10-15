// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_super_resolution.h
// Description: Video Super Resolution (VSM) using Lanczos-3 & Edge Detail Enhancement
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "lens_engine_interface.h"

namespace LENS::ALGORITHM {

// EN: LensAlgorithmVSM matching symbol N4LENS9ALGORITHM16LensAlgorithmVSME
// VN: Thuật toán siêu phân giải video khớp biểu tượng N4LENS9ALGORITHM16LensAlgorithmVSME
class LensAlgorithmVSM : public FRAMEWORK::ILensAlgorithmInterface {
public:
    LensAlgorithmVSM();
    ~LensAlgorithmVSM() override = default;

    bool Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) override;
    bool Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) override;
    void Reset() override;
    FRAMEWORK::LensAlgorithmType GetType() const override {
        return FRAMEWORK::LensAlgorithmType::LENS_ALGO_VSM;
    }
    const char* GetName() const override {
        return "LensAlgorithmVSM";
    }

    // EN: Mathematical Lanczos-3 kernel function L(x) = sinc(x) * sinc(x / 3)
    // VN: Hàm nhân nội suy toán học Lanczos-3 L(x) = sinc(x) * sinc(x / 3)
    static float Lanczos3Kernel(float x);

    // EN: Bicubic Hermite kernel B(t)
    // VN: Hàm nhân Bicubic nội suy chuyển tiếp
    static float BicubicKernel(float t);

    // EN: Upscale buffer by factor of 2.0x
    // VN: Phóng đại buffer điểm ảnh theo tỷ lệ 2 lần
    bool Upscale2x(const uint8_t* src, int32_t src_w, int32_t src_h, int32_t channels,
                   uint8_t* dst, int32_t dst_w, int32_t dst_h);

    // EN: High frequency edge sharpening (Laplacian unsharp masking)
    // VN: Tăng cường độ nét chi tiết biên tần số cao (Laplacian)
    void ApplyHighFrequencySharpening(uint8_t* buffer, int32_t width, int32_t height, int32_t channels, float strength);

private:
    float m_scale_factor = 2.0f;
    float m_sharpen_strength = 0.45f;
    bool m_enable_edge_sharpen = true;
};

} // namespace LENS::ALGORITHM
