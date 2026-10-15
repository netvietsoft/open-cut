// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_bilateral_filter.h
// Description: Hierarchical Bilateral Filter & Edge-Preserving Skin Smoothing
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "lens_engine_interface.h"
#include <vector>

namespace LENS::ALGORITHM {

// EN: Bilateral Weight Pass computing spatial and photometric weight matrices
// VN: Lớp tính toán ma trận trọng số song phương theo không gian và cường độ màu sắc
class BilateralWeightPass {
public:
    BilateralWeightPass();
    ~BilateralWeightPass() = default;

    // EN: Precompute spatial Gaussian lookup table
    // VN: Tính toán trước bảng tra cứu trọng số không gian Gaussian
    void PrecomputeSpatialKernel(int32_t radius, float sigma_s);

    // EN: Compute photometric range weight
    // VN: Tính toán trọng số khoảng cách màu sắc (photometric)
    inline float ComputeRangeWeight(float delta_lum, float inv_2_sigma_r_sq) const;

    const std::vector<float>& GetSpatialKernel() const { return m_spatial_kernel; }
    int32_t GetRadius() const { return m_radius; }

private:
    int32_t m_radius = 3;
    float m_sigma_s = 2.5f;
    std::vector<float> m_spatial_kernel;
};

// EN: Hierarchical Bilateral Filter matching symbol N2vd27HierarchicalBilateralFilterE
// VN: Bộ lọc song phương phân tầng khớp biểu tượng N2vd27HierarchicalBilateralFilterE
class HierarchicalBilateralFilter : public FRAMEWORK::ILensAlgorithmInterface {
public:
    HierarchicalBilateralFilter();
    ~HierarchicalBilateralFilter() override = default;

    bool Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) override;
    bool Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) override;
    void Reset() override;
    FRAMEWORK::LensAlgorithmType GetType() const override {
        return FRAMEWORK::LensAlgorithmType::LENS_ALGO_BILATERAL;
    }
    const char* GetName() const override {
        return "HierarchicalBilateralFilter";
    }

    // EN: Direct filtering function for buffer testing
    // VN: Hàm lọc trực tiếp phục vụ kiểm thử buffer
    bool FilterBuffer(const uint8_t* src, uint8_t* dst, int32_t width, int32_t height, int32_t channels);

private:
    BilateralWeightPass m_weight_pass;
    float m_sigma_spatial = 3.0f;
    float m_sigma_range = 0.12f;
    float m_smooth_strength = 0.85f;
    int32_t m_radius = 3;
    bool m_skin_detect_only = true;
};

} // namespace LENS::ALGORITHM
