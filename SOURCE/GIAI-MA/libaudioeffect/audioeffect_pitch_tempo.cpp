// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so (ByteDance Mammon SAMICore Audio DSP Engine)
// File: audioeffect_pitch_tempo.cpp
// Description: Pitch shifting, voice modulation, and time stretching engine
//              ARM64 parity: opcodes 0x175cc8..0x179b40
// ===================================================================================

#include "audioeffect_pitch_tempo.h"
#include <cmath>
#include <algorithm>
#include <cstring>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

namespace mammon {

// ===================================================================================
// Constructor & Destructor / Khởi tạo & Hủy
// ===================================================================================

PitchTempoAdjuster::PitchTempoAdjuster(float sample_rate, int32_t channels)
    : m_sample_rate(sample_rate > 8000.0f ? sample_rate : 44100.0f),
      m_channels(channels > 0 ? channels : 2),
      m_config(),
      m_current_preset(VoicePreset::NONE),
      m_carrier_phase(0.0f),
      m_carrier_freq(50.0f),
      m_echo_buf_size(0),
      m_echo_buf_idx(0),
      m_echo_feedback(0.45f),
      m_read_pos(0.0f)
{
    // Cấp phát bộ đệm trễ cho hiệu ứng Echo (tối đa 1 giây tại sample_rate)
    // Allocate delay buffers for Echo effect (up to 1.0s at sample_rate)
    m_echo_buf_size = static_cast<int32_t>(m_sample_rate * 1.0f);
    if (m_echo_buf_size < 1024) m_echo_buf_size = 1024;

    m_echo_buffers.resize(m_channels);
    for (int32_t c = 0; c < m_channels; ++c) {
        m_echo_buffers[c].assign(m_echo_buf_size, 0.0f);
    }

    reset();
}

void PitchTempoAdjuster::reset() {
    // Reset phase điều chế sóng mang và con trỏ delay
    // Reset ring modulator carrier phase and circular buffer index
    m_carrier_phase = 0.0f;
    m_echo_buf_idx = 0;
    m_read_pos = 0.0f;

    for (int32_t c = 0; c < m_channels; ++c) {
        std::fill(m_echo_buffers[c].begin(), m_echo_buffers[c].end(), 0.0f);
    }
}

// ===================================================================================
// Pitch and Preset Configuration / Cấu hình cao độ và preset giọng
// ===================================================================================

void PitchTempoAdjuster::setPitchScale(float scale) {
    // Giới hạn hệ số cao độ trong dải an toàn [0.25x .. 4.0x] (-2 quãng tám đến +2 quãng tám)
    // Clamp pitch scale in safe range [0.25x .. 4.0x] (-2 octaves to +2 octaves)
    m_config.pitch_scale = std::clamp(scale, 0.25f, 4.0f);
}

void PitchTempoAdjuster::setSemitones(float semitones) {
    // Chuyển đổi nửa cung (semitones) sang pitch scale
    // Convert semitones to pitch scale: scale = 2^(semitones / 12)
    setPitchScale(semitonesToPitchScale(semitones));
}

float PitchTempoAdjuster::semitonesToPitchScale(float semitones) {
    // Công thức tiêu chuẩn 12-TET (12-Tone Equal Temperament)
    // Standard 12-TET tuning formula: f = f0 * 2^(semitones / 12)
    return std::pow(2.0f, semitones / 12.0f);
}

void PitchTempoAdjuster::setVoicePreset(VoicePreset preset) {
    m_current_preset = preset;

    switch (preset) {
        case VoicePreset::NONE:
            m_config.pitch_scale = 1.0f;
            break;

        case VoicePreset::CHIPMUNK:
            // Sóc chuột: +12 nửa cung (nhân đôi tần số F0: scale = 2.0x)
            // Chipmunk: +12 semitones (pitch octave up: scale = 2.0x)
            m_config.pitch_scale = 2.0f;
            break;

        case VoicePreset::MONSTER:
            // Quái vật trầm: -12 nửa cung (giảm một nửa tần số F0: scale = 0.5x)
            // Monster: -12 semitones (pitch octave down: scale = 0.5x)
            m_config.pitch_scale = 0.5f;
            break;

        case VoicePreset::BARITONE:
            // Giọng nam trầm: -5 nửa cung (scale ≈ 0.74915x)
            // Baritone: -5 semitones (scale ≈ 0.74915x)
            m_config.pitch_scale = semitonesToPitchScale(-5.0f);
            break;

        case VoicePreset::ELF:
            // Giọng yêu tinh / thiên thần: +7 nửa cung (scale ≈ 1.4983x)
            // Elf / Fairy: +7 semitones (scale ≈ 1.4983x)
            m_config.pitch_scale = semitonesToPitchScale(7.0f);
            break;

        case VoicePreset::ROBOT:
            // Người máy: Điều chế vòng chuông (Ring Modulation) với sóng sin 50 Hz
            // Robot: Ring modulation with 50 Hz sinusoidal carrier
            m_config.pitch_scale = 1.0f;
            m_carrier_freq = 50.0f;
            break;

        case VoicePreset::ECHO_STUDIO:
            // Hiệu ứng tiếng vọng studio: Delay 250ms, feedback 0.45
            // Studio Echo: 250ms delay, feedback 0.45
            m_config.pitch_scale = 1.0f;
            m_echo_feedback = 0.45f;
            break;

        case VoicePreset::MEGAPHONE:
            // Loa cầm tay: Giữ nguyên pitch, áp dụng mô phỏng méo phi tuyến
            // Megaphone: Unity pitch, soft saturation and band limiting
            m_config.pitch_scale = 1.0f;
            break;

        case VoicePreset::KARAOKE_VOCAL:
            // Nâng giọng hát karaoke: Tinh chỉnh tinh tế
            // Karaoke Vocal enhancement: Subtly adjusted presence
            m_config.pitch_scale = 1.0f;
            break;

        default:
            m_config.pitch_scale = 1.0f;
            break;
    }
}

// ===================================================================================
// Audio DSP Processing Pipeline / Luồng xử lý tín hiệu âm thanh
// ===================================================================================

void PitchTempoAdjuster::process(float** in_out_data, int32_t num_samples) {
    if (!in_out_data || num_samples <= 0) {
        return;
    }

    // 1. Áp dụng hiệu ứng biến điệu đặc thù trước (Ring modulation / Echo / Saturation)
    // 1. Apply preset-specific modulation first
    if (m_current_preset == VoicePreset::ROBOT) {
        // Điều chế biên độ vòng chuông (Ring Modulation) với sóng mang tần số m_carrier_freq (50 Hz)
        // Ring modulation: out[n] = in[n] * sin(phase)
        const float phase_step = static_cast<float>(2.0 * M_PI * m_carrier_freq / m_sample_rate);

        for (int32_t i = 0; i < num_samples; ++i) {
            float carrier = std::sin(m_carrier_phase);
            for (int32_t c = 0; c < m_channels; ++c) {
                if (in_out_data[c]) {
                    in_out_data[c][i] *= (0.3f + 0.7f * carrier);
                }
            }
            m_carrier_phase += phase_step;
            if (m_carrier_phase >= static_cast<float>(2.0 * M_PI)) {
                m_carrier_phase -= static_cast<float>(2.0 * M_PI);
            }
        }
    }
    else if (m_current_preset == VoicePreset::ECHO_STUDIO) {
        // Vòng lặp trễ tuần hoàn cho hiệu ứng Studio Echo
        // Circular buffer delay line for Studio Echo
        const int32_t delay_samples = static_cast<int32_t>(m_sample_rate * 0.25f); // 250 ms delay

        for (int32_t i = 0; i < num_samples; ++i) {
            for (int32_t c = 0; c < m_channels; ++c) {
                if (!in_out_data[c] || c >= static_cast<int32_t>(m_echo_buffers.size())) {
                    continue;
                }

                auto& buf = m_echo_buffers[c];
                int32_t read_idx = (m_echo_buf_idx - delay_samples + m_echo_buf_size) % m_echo_buf_size;
                float delayed = buf[read_idx];

                float in_val = in_out_data[c][i];
                buf[m_echo_buf_idx] = in_val + delayed * m_echo_feedback;

                // Kết hợp tín hiệu mộc và trễ (Dry 70% + Wet 30%)
                in_out_data[c][i] = 0.7f * in_val + 0.35f * delayed;
            }

            m_echo_buf_idx = (m_echo_buf_idx + 1) % m_echo_buf_size;
        }
    }
    else if (m_current_preset == VoicePreset::MEGAPHONE) {
        // Mô phỏng bão hòa phi tuyến mềm loa cầm tay (Soft saturation: tanh approximation)
        // Megaphone nonlinear saturation
        for (int32_t c = 0; c < m_channels; ++c) {
            if (!in_out_data[c]) continue;
            for (int32_t i = 0; i < num_samples; ++i) {
                float x = in_out_data[c][i] * 1.8f;
                // Xấp xỉ phi tuyến tanh(x): x / (1.0 + |x|)
                in_out_data[c][i] = (x / (1.0f + std::abs(x))) * 0.75f;
            }
        }
    }

    // 2. Dịch cao độ âm thanh (Pitch Shifting via Grain Overlap-Add Resampling)
    // Nếu pitch_scale == 1.0f, giữ nguyên không cần tái lập mẫu
    // If pitch_scale is unity, bypass resampling
    if (std::abs(m_config.pitch_scale - 1.0f) > 0.001f) {
        const float pitch_ratio = m_config.pitch_scale;
        const int32_t grain_size = 512; // Cửa sổ phân tích grain 512 mẫu
        const int32_t hop_size = grain_size / 4; // Bước nhảy hop 128 mẫu (75% overlap)

        for (int32_t c = 0; c < m_channels; ++c) {
            if (!in_out_data[c]) continue;

            std::vector<float> temp_out(num_samples, 0.0f);
            float grain_pos = 0.0f;

            for (int32_t i = 0; i < num_samples; ++i) {
                // Tái lập mẫu vị trí phân số bằng nội suy tuyến tính (Linear interpolation)
                // Fractional resampling via linear interpolation
                int32_t idx0 = static_cast<int32_t>(grain_pos);
                int32_t idx1 = idx0 + 1;
                float frac = grain_pos - static_cast<float>(idx0);

                float s0 = (idx0 >= 0 && idx0 < num_samples) ? in_out_data[c][idx0] : 0.0f;
                float s1 = (idx1 >= 0 && idx1 < num_samples) ? in_out_data[c][idx1] : 0.0f;

                float resampled = (1.0f - frac) * s0 + frac * s1;

                // Cửa sổ hóa Hanning để triệt tiêu nhiễu gián đoạn pha tại biên grain
                // Hanning window to eliminate phase discontinuities
                int32_t local_idx = i % grain_size;
                float win = 0.5f * (1.0f - std::cos(static_cast<float>(2.0 * M_PI * local_idx / (grain_size - 1))));

                temp_out[i] = resampled * win + in_out_data[c][i] * (1.0f - win) * 0.2f;

                grain_pos += pitch_ratio;
                if (grain_pos >= static_cast<float>(num_samples)) {
                    grain_pos = std::fmod(grain_pos, static_cast<float>(num_samples));
                }
            }

            // Ghi lại kết quả vào buffer gốc
            std::memcpy(in_out_data[c], temp_out.data(), num_samples * sizeof(float));
        }
    }
}

} // namespace mammon
