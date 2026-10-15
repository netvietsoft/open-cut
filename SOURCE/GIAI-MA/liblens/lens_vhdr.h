// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_vhdr.h
// Description: Video HDR Tone Mapping & Dynamic Range Expansion (VHDR)
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "lens_engine_interface.h"

namespace LENS::ALGORITHM {

// EN: LensAlgorithmVHDR matching symbol N4LENS9ALGORITHM17LensAlgorithmVHDRE
// VN: Thuật toán Video HDR mở rộng dải động khớp biểu tượng N4LENS9ALGORITHM17LensAlgorithmVHDRE
class LensAlgorithmVHDR : public FRAMEWORK::ILensAlgorithmInterface {
public:
    LensAlgorithmVHDR();
    ~LensAlgorithmVHDR() override = default;

    bool Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) override;
    bool Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) override;
    void Reset() override;
    FRAMEWORK::LensAlgorithmType GetType() const override {
        return FRAMEWORK::LensAlgorithmType::LENS_ALGO_VHDR;
    }
    const char* GetName() const override {
        return "LensAlgorithmVHDR";
    }

    // EN: Extended Reinhard tone mapping: L_out = L_in * (1 + L_in / (L_white^2)) / (1 + L_in)
    // VN: Ánh xạ sắc độ mở rộng Reinhard cân bằng vùng sáng và vùng tối
    static float ReinhardToneMap(float l_in, float l_white_sq);

    // EN: Fast adaptive histogram local contrast enhancement
    // VN: Tăng cường tương phản cục bộ thích ứng dải động
    void EnhanceDynamicRange(const uint8_t* src, uint8_t* dst, int32_t width, int32_t height, int32_t channels);

private:
    float m_hdr_strength = 0.80f;
    float m_shadow_lift = 0.35f;
    float m_saturation_boost = 1.15f;
};

} // namespace LENS::ALGORITHM
