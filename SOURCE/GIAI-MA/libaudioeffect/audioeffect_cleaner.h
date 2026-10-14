// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so (ByteDance Mammon SAMICore Audio DSP Engine)
// File: audioeffect_cleaner.h
// Description: Intelligent Audio Denoising, Spectral Subtraction, and VAD Engine
//              Reverse-engineered from SAMICore Audio Cleaner / SAMI_IDENTIFY_AUDIO_CLEANER_DENOISE
// ===================================================================================

#pragma once

#include "audioeffect_types.h"
#include <vector>

namespace mammon {

/**
 * @brief Bộ khử ồn và làm sạch âm thanh thông minh (Audio Cleaner / Denoise Processor)
 * Áp dụng thuật toán trừ phổ nhiều băng (Multiband Spectral Subtraction) kết hợp
 * nhận dạng giọng nói VAD và kiểm soát sàn tạp âm (Noise Floor Tracking).
 */
class AudioCleaner {
public:
    AudioCleaner(float sample_rate = 44100.0f, int32_t channels = 2);
    ~AudioCleaner() = default;

    /// Đặt lại toàn bộ bộ nhớ đệm và ước lượng tạp âm
    void reset();

    /// Cài đặt cường độ khử ồn (0.0 = không can thiệp, 1.0 = triệt tiêu tối đa)
    void setIntensity(float intensity);
    float getIntensity() const { return m_intensity; }

    /// Bật/tắt chế độ bypass
    void setBypass(bool bypass) { m_bypass = bypass; }
    bool isBypassed() const { return m_bypass; }

    /// Xử lý tín hiệu mảng kênh (Planar Audio Data: data[ch][sample])
    void process(float** in_out_data, int32_t num_samples);

    /// Ước tính mức tạp âm sàn hiện tại (dB)
    float getNoiseFloorDb() const;

private:
    float m_sample_rate;
    int32_t m_channels;
    float m_intensity;        // 0.0 .. 1.0
    bool m_bypass;

    // Bộ nhớ trạng thái lọc dải tần (Subband Filter States)
    std::vector<float> m_noise_floor_estimate; // Ước lượng năng lượng tạp âm sàn theo kênh
    std::vector<float> m_smoothed_gain;        // Hệ số khuếch đại làm mượt để tránh musical noise
    std::vector<float> m_prev_samples;         // Mẫu lịch sử bậc 1

    float m_vad_threshold;    // Ngưỡng năng lượng VAD phân biệt tiếng nói và khoảng lặng
    float m_alpha;            // Hệ số trừ quá mức (Over-subtraction factor)
    float m_beta;             // Sàn quang phổ tối thiểu (Spectral floor limit)
};

} // namespace mammon
