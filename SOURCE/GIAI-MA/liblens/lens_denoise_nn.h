// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_denoise_nn.h
// Description: Video Neural Denoising Process with Motion-Adaptive Temporal Filtering
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "lens_engine_interface.h"
#include <vector>

namespace LENS::ALGORITHM {

// EN: VideoDenoiseNNProcess matching symbol N4LENS9ALGORITHM21VideoDenoiseNNProcessE
// VN: Tiến trình khử nhiễu video nơ-ron khớp biểu tượng N4LENS9ALGORITHM21VideoDenoiseNNProcessE
class VideoDenoiseNNProcess : public FRAMEWORK::ILensAlgorithmInterface {
public:
    VideoDenoiseNNProcess();
    ~VideoDenoiseNNProcess() override = default;

    bool Init(const FRAMEWORK::LensAlgorithmJsonInfo& config) override;
    bool Process(const FRAMEWORK::LensImageFrame& in_frame, FRAMEWORK::LensImageFrame& out_frame) override;
    void Reset() override;
    FRAMEWORK::LensAlgorithmType GetType() const override {
        return FRAMEWORK::LensAlgorithmType::LENS_ALGO_NN_DENOISE;
    }
    const char* GetName() const override {
        return "VideoDenoiseNNProcess";
    }

    // EN: Estimate noise standard deviation in image patch
    // VN: Ước lượng độ lệch chuẩn tạp âm trên mảng điểm ảnh
    static float EstimateNoiseFloor(const uint8_t* buffer, int32_t width, int32_t height, int32_t channels);

    // EN: Motion-adaptive temporal recursive filter
    // VN: Bộ lọc đệ quy thời gian thích ứng chuyển động
    void TemporalDenoisePass(const uint8_t* current, const uint8_t* previous, uint8_t* dst,
                             int32_t width, int32_t height, int32_t channels, float noise_sigma);

private:
    float m_denoise_strength = 0.70f;
    bool m_has_previous_frame = false;
    std::vector<uint8_t> m_previous_frame_buffer;
};

} // namespace LENS::ALGORITHM
