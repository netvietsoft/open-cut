// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so (ByteDance Mammon SAMICore Audio DSP Engine)
// File: audioeffect_cleaner.cpp
// Description: Intelligent Audio Denoising, Spectral Subtraction, and VAD Engine
//              Arm64 parity: SAMICore Audio Cleaner DSP Pipeline
// ===================================================================================

#include "audioeffect_cleaner.h"
#include <cmath>
#include <algorithm>

namespace mammon {

// ===================================================================================
// Constructor & Initialization / Khởi tạo & Thiết lập ban đầu
// ===================================================================================

AudioCleaner::AudioCleaner(float sample_rate, int32_t channels)
    : m_sample_rate(sample_rate > 8000.0f ? sample_rate : 44100.0f),
      m_channels(channels > 0 ? channels : 2),
      m_intensity(0.5f),
      m_bypass(false),
      m_vad_threshold(0.0005f),
      m_alpha(2.0f),
      m_beta(0.05f)
{
    m_noise_floor_estimate.assign(m_channels, 0.0001f);
    m_smoothed_gain.assign(m_channels, 1.0f);
    m_prev_samples.assign(m_channels, 0.0f);

    setIntensity(m_intensity);
    reset();
}

void AudioCleaner::reset() {
    // Đặt lại các hệ số ước lượng sàn tạp âm ban đầu
    // Reset initial noise floor estimates
    for (int32_t c = 0; c < m_channels; ++c) {
        m_noise_floor_estimate[c] = 0.0001f;
        m_smoothed_gain[c] = 1.0f;
        m_prev_samples[c] = 0.0f;
    }
}

// ===================================================================================
// Parameter Controls / Điều khiển tham số
// ===================================================================================

void AudioCleaner::setIntensity(float intensity) {
    // Giới hạn cường độ trong dải [0.0 .. 1.0]
    // Clamp denoise intensity in range [0.0 .. 1.0]
    m_intensity = std::clamp(intensity, 0.0f, 1.0f);

    // Điều chỉnh hệ số trừ quá mức alpha (1.0 .. 4.0) và sàn quang phổ beta (0.20 .. 0.01)
    // Scale over-subtraction alpha (1.0 .. 4.0) and spectral floor beta (0.20 .. 0.01)
    m_alpha = 1.0f + 3.0f * m_intensity;
    m_beta = std::max(0.01f, 0.20f * (1.0f - m_intensity));
}

float AudioCleaner::getNoiseFloorDb() const {
    // Tính trung bình năng lượng tạp âm sàn trên tất cả các kênh và quy đổi sang dB
    // Average noise floor across channels and convert to decibels
    float avg_energy = 0.0f;
    for (int32_t c = 0; c < m_channels; ++c) {
        avg_energy += m_noise_floor_estimate[c];
    }
    avg_energy /= static_cast<float>(m_channels);

    if (avg_energy <= 1e-12f) {
        return -120.0f;
    }
    return 10.0f * std::log10(avg_energy);
}

// ===================================================================================
// Audio Processing Engine / Động cơ xử lý khử ồn âm thanh
// ===================================================================================

void AudioCleaner::process(float** in_out_data, int32_t num_samples) {
    if (!in_out_data || num_samples <= 0 || m_bypass || m_intensity <= 0.001f) {
        return;
    }

    // Xử lý từng khối mẫu (Frame-based processing với block size = 128 mẫu)
    // Process in sub-frames of 128 samples for spectral tracking
    const int32_t frame_size = 128;

    for (int32_t c = 0; c < m_channels; ++c) {
        if (!in_out_data[c] || c >= static_cast<int32_t>(m_noise_floor_estimate.size())) {
            continue;
        }

        float* channel_buf = in_out_data[c];
        float noise_est = m_noise_floor_estimate[c];
        float gain = m_smoothed_gain[c];

        for (int32_t offset = 0; offset < num_samples; offset += frame_size) {
            int32_t current_len = std::min(frame_size, num_samples - offset);

            // 1. Tính toán năng lượng tức thời của frame: E = sum(x[n]^2) / N
            // 1. Calculate short-time frame energy: E = sum(x[n]^2) / N
            float frame_energy = 0.0f;
            for (int32_t i = 0; i < current_len; ++i) {
                float sample = channel_buf[offset + i];
                frame_energy += sample * sample;
            }
            frame_energy /= static_cast<float>(current_len);

            // 2. Bộ nhận diện tiếng nói VAD và cập nhật thích nghi tạp âm sàn
            // 2. VAD & adaptive noise floor tracking
            if (frame_energy < (noise_est * 2.2f) || frame_energy < m_vad_threshold) {
                // Khối không có tiếng nói rõ rệt (Khoảng lặng / Tạp âm nền): Cập nhật ước lượng tạp âm sàn
                // Unvoiced block: Track noise floor with exponential smoothing
                noise_est = 0.95f * noise_est + 0.05f * frame_energy;
            }

            // 3. Tính toán hệ số suy giảm quang phổ theo tỷ số SNR
            // 3. Spectral subtraction gain calculation
            float target_gain = 1.0f;
            if (frame_energy > 1e-9f) {
                float snr = frame_energy / (noise_est + 1e-9f);
                float sub_factor = 1.0f - (m_alpha / snr);
                if (sub_factor < (m_beta * m_beta)) {
                    target_gain = m_beta;
                } else {
                    target_gain = std::sqrt(sub_factor);
                }
            } else {
                target_gain = m_beta;
            }

            // 4. Áp dụng hệ số khuếch đại mượt mà vào từng mẫu và giới hạn biên độ
            // 4. Smooth gain trajectory to eliminate musical artifacts
            for (int32_t i = 0; i < current_len; ++i) {
                gain = 0.92f * gain + 0.08f * target_gain;
                float filtered = channel_buf[offset + i] * gain;

                // Soft-clipping để tránh hiện tượng tràn bit âm sắc (Anti-clipping protection)
                channel_buf[offset + i] = std::clamp(filtered, -1.0f, 1.0f);
            }
        }

        m_noise_floor_estimate[c] = noise_est;
        m_smoothed_gain[c] = gain;
    }
}

} // namespace mammon
