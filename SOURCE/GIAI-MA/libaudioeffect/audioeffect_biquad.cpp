// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so
// File: audioeffect_biquad.cpp
// Description: Full implementation of Biquad IIR filter and 10-Band Equalizer
// ===================================================================================

#include "audioeffect_biquad.h"
#include <cmath>
#include <algorithm>

namespace mammon {

Biquad::Biquad() {
    reset();
}

void Biquad::reset() {
    m_coeffs = BiquadCoeffs();
}

void Biquad::setCoefficients(const BiquadCoeffs& coeffs) {
    m_coeffs = coeffs;
}

/**
 * @brief Direct Form II Transposed Sample Filter
 * 
 * Difference equation:
 *   y[n] = b0 * x[n] + s1[n-1]
 *   s1[n] = b1 * x[n] - a1 * y[n] + s2[n-1]
 *   s2[n] = b2 * x[n] - a2 * y[n]
 */
float Biquad::processSample(float in_sample, BiquadState& state) {
    float out_sample = m_coeffs.b0 * in_sample + state.s1;
    state.s1 = m_coeffs.b1 * in_sample - m_coeffs.a1 * out_sample + state.s2;
    state.s2 = m_coeffs.b2 * in_sample - m_coeffs.a2 * out_sample;

    // Flush denormals to prevent high CPU utilization
    if (std::abs(state.s1) < 1e-15f) state.s1 = 0.0f;
    if (std::abs(state.s2) < 1e-15f) state.s2 = 0.0f;

    return out_sample;
}

BiquadCoeffs Biquad::designPeakingEQ(float sample_rate, float center_freq, float Q, float gain_dB) {
    BiquadCoeffs c;
    if (sample_rate <= 0.0f || center_freq <= 0.0f || Q <= 0.0f) {
        return c;
    }

    float A = std::pow(10.0f, gain_dB / 40.0f);
    float omega = 2.0f * static_cast<float>(M_PI) * (center_freq / sample_rate);
    float sin_omega = std::sin(omega);
    float cos_omega = std::cos(omega);
    float alpha = sin_omega / (2.0f * Q);

    float a0 = 1.0f + alpha / A;
    c.b0 = (1.0f + alpha * A) / a0;
    c.b1 = (-2.0f * cos_omega) / a0;
    c.b2 = (1.0f - alpha * A) / a0;
    c.a1 = (-2.0f * cos_omega) / a0;
    c.a2 = (1.0f - alpha / A) / a0;

    return c;
}

BiquadCoeffs Biquad::designLowShelf(float sample_rate, float cutoff_freq, float Q, float gain_dB) {
    BiquadCoeffs c;
    if (sample_rate <= 0.0f || cutoff_freq <= 0.0f) return c;

    float A = std::pow(10.0f, gain_dB / 40.0f);
    float omega = 2.0f * static_cast<float>(M_PI) * (cutoff_freq / sample_rate);
    float sin_omega = std::sin(omega);
    float cos_omega = std::cos(omega);
    float alpha = sin_omega / (2.0f * Q);
    float beta = 2.0f * std::sqrt(A) * alpha;

    float a0 = (A + 1.0f) + (A - 1.0f) * cos_omega + beta;
    c.b0 = (A * ((A + 1.0f) - (A - 1.0f) * cos_omega + beta)) / a0;
    c.b1 = (2.0f * A * ((A - 1.0f) - (A + 1.0f) * cos_omega)) / a0;
    c.b2 = (A * ((A + 1.0f) - (A - 1.0f) * cos_omega - beta)) / a0;
    c.a1 = (-2.0f * ((A - 1.0f) + (A + 1.0f) * cos_omega)) / a0;
    c.a2 = ((A + 1.0f) + (A - 1.0f) * cos_omega - beta) / a0;

    return c;
}

BiquadCoeffs Biquad::designHighShelf(float sample_rate, float cutoff_freq, float Q, float gain_dB) {
    BiquadCoeffs c;
    if (sample_rate <= 0.0f || cutoff_freq <= 0.0f) return c;

    float A = std::pow(10.0f, gain_dB / 40.0f);
    float omega = 2.0f * static_cast<float>(M_PI) * (cutoff_freq / sample_rate);
    float sin_omega = std::sin(omega);
    float cos_omega = std::cos(omega);
    float alpha = sin_omega / (2.0f * Q);
    float beta = 2.0f * std::sqrt(A) * alpha;

    float a0 = (A + 1.0f) - (A - 1.0f) * cos_omega + beta;
    c.b0 = (A * ((A + 1.0f) + (A - 1.0f) * cos_omega + beta)) / a0;
    c.b1 = (-2.0f * A * ((A - 1.0f) + (A + 1.0f) * cos_omega)) / a0;
    c.b2 = (A * ((A + 1.0f) + (A - 1.0f) * cos_omega - beta)) / a0;
    c.a1 = (2.0f * ((A - 1.0f) - (A + 1.0f) * cos_omega)) / a0;
    c.a2 = ((A + 1.0f) - (A - 1.0f) * cos_omega - beta) / a0;

    return c;
}

BiquadCoeffs Biquad::designLowPass(float sample_rate, float cutoff_freq, float Q) {
    BiquadCoeffs c;
    if (sample_rate <= 0.0f || cutoff_freq <= 0.0f) return c;

    float omega = 2.0f * static_cast<float>(M_PI) * (cutoff_freq / sample_rate);
    float sin_omega = std::sin(omega);
    float cos_omega = std::cos(omega);
    float alpha = sin_omega / (2.0f * Q);

    float a0 = 1.0f + alpha;
    c.b0 = ((1.0f - cos_omega) / 2.0f) / a0;
    c.b1 = (1.0f - cos_omega) / a0;
    c.b2 = ((1.0f - cos_omega) / 2.0f) / a0;
    c.a1 = (-2.0f * cos_omega) / a0;
    c.a2 = (1.0f - alpha) / a0;

    return c;
}

BiquadCoeffs Biquad::designHighPass(float sample_rate, float cutoff_freq, float Q) {
    BiquadCoeffs c;
    if (sample_rate <= 0.0f || cutoff_freq <= 0.0f) return c;

    float omega = 2.0f * static_cast<float>(M_PI) * (cutoff_freq / sample_rate);
    float sin_omega = std::sin(omega);
    float cos_omega = std::cos(omega);
    float alpha = sin_omega / (2.0f * Q);

    float a0 = 1.0f + alpha;
    c.b0 = ((1.0f + cos_omega) / 2.0f) / a0;
    c.b1 = -(1.0f + cos_omega) / a0;
    c.b2 = ((1.0f + cos_omega) / 2.0f) / a0;
    c.a1 = (-2.0f * cos_omega) / a0;
    c.a2 = (1.0f - alpha) / a0;

    return c;
}


// ===================================================================================
// 10-BAND EQUALIZER IMPLEMENTATION
// ===================================================================================

Equalizer::Equalizer(float sample_rate, int32_t channels)
    : m_sample_rate(sample_rate), m_channels(channels) {
    if (m_channels < 1) m_channels = 1;
    if (m_channels > 8) m_channels = 8;

    m_channel_states.resize(EQ_BAND_COUNT);
    for (uint32_t b = 0; b < EQ_BAND_COUNT; ++b) {
        m_band_gains_db[b] = 0.0f;
        m_channel_states[b].resize(m_channels);
        updateBandFilter(b);
    }
}

void Equalizer::reset() {
    for (uint32_t b = 0; b < EQ_BAND_COUNT; ++b) {
        for (int32_t ch = 0; ch < m_channels; ++ch) {
            m_channel_states[b][ch].reset();
        }
    }
}

/**
 * @brief eqGetBandFre
 * 
 * ARM64 Disassembly Parity (0x188c38):
 *   0x188c38: cmp w1, #0xa              ; so sánh chỉ số với 10
 *   0x188c3c: b.ls #0x188c48            ; nếu <= 10 -> tải bảng
 *   0x188c40: fmov s0, #-1.0            ; nếu > 10 -> trả về -1.0f
 *   0x188c44: ret
 *   0x188c48: adrp x8, #0x3a5000
 *   0x188c4c: add x8, x8, #0xcd4        ; con trỏ bảng 10 tần số trung tâm
 *   0x188c50: ldr s0, [x8, w1, uxtw #2] ; nạp float từ bảng (offset w1 * 4)
 *   0x188c54: ret
 */
float Equalizer::eqGetBandFre(uint32_t band_idx) {
    if (band_idx >= EQ_BAND_COUNT) {
        return -1.0f; // Opcode 0x188c40
    }
    return EQ_CENTER_FREQUENCIES[band_idx]; // Opcode 0x188c50
}

/**
 * @brief eqdB2Gain
 * 
 * ARM64 Disassembly Parity (0x1886c4):
 *   0x1886c4: fmov s2, #-20.0           ; min gain = -20 dB
 *   0x1886c8: fcmp s0, s2               ; so sánh dưới
 *   0x1886cc: fmov s1, #20.0            ; max gain = +20 dB
 *   0x1886d0: b.mi #0x1886e4            ; kẹp biên dưới
 *   0x1886d4: fcmp s0, s1               ; so sánh trên
 *   0x1886d8: mov v2.16b, v0.16b
 *   0x1886dc: b.le #0x1886e4
 *   0x1886e0: mov v2.16b, v1.16b        ; kẹp biên trên
 *   0x1886e4: ... -> powf(10.0f, clamped / 20.0f)
 */
float Equalizer::eqdB2Gain(float db) {
    float clamped = std::max(EQ_MIN_GAIN_DB, std::min(EQ_MAX_GAIN_DB, db));
    return std::pow(10.0f, clamped / 20.0f);
}

void Equalizer::setBandGain(uint32_t band_idx, float gain_dB) {
    if (band_idx >= EQ_BAND_COUNT) return;
    float clamped_db = std::max(EQ_MIN_GAIN_DB, std::min(EQ_MAX_GAIN_DB, gain_dB));
    if (std::abs(m_band_gains_db[band_idx] - clamped_db) > 1e-4f) {
        m_band_gains_db[band_idx] = clamped_db;
        updateBandFilter(band_idx);
    }
}

float Equalizer::getBandGain(uint32_t band_idx) const {
    if (band_idx >= EQ_BAND_COUNT) return 0.0f;
    return m_band_gains_db[band_idx];
}

void Equalizer::updateBandFilter(uint32_t band_idx) {
    float freq = EQ_CENTER_FREQUENCIES[band_idx];
    float gain_db = m_band_gains_db[band_idx];
    float Q = 1.414f; // 1-octave bandwidth Q factor

    BiquadCoeffs coeffs;
    if (std::abs(gain_db) < 1e-4f) {
        // Flat response bypass
        coeffs = BiquadCoeffs();
    } else if (band_idx == 0) {
        coeffs = Biquad::designLowShelf(m_sample_rate, freq, Q, gain_db);
    } else if (band_idx == EQ_BAND_COUNT - 1) {
        coeffs = Biquad::designHighShelf(m_sample_rate, freq, Q, gain_db);
    } else {
        coeffs = Biquad::designPeakingEQ(m_sample_rate, freq, Q, gain_db);
    }

    m_biquads[band_idx].setCoefficients(coeffs);
}

void Equalizer::process(float** in_out_data, int32_t samples) {
    if (!in_out_data || samples <= 0) return;

    for (int32_t ch = 0; ch < m_channels; ++ch) {
        float* channel_buf = in_out_data[ch];
        if (!channel_buf) continue;

        for (uint32_t b = 0; b < EQ_BAND_COUNT; ++b) {
            if (std::abs(m_band_gains_db[b]) < 1e-4f) {
                continue; // Bypass flat bands
            }

            Biquad& filter = m_biquads[b];
            BiquadState& state = m_channel_states[b][ch];

            for (int32_t i = 0; i < samples; ++i) {
                channel_buf[i] = filter.processSample(channel_buf[i], state);
            }
        }
    }
}

void Equalizer::processInterleaved(float* in_out_data, int32_t samples) {
    if (!in_out_data || samples <= 0) return;

    for (uint32_t b = 0; b < EQ_BAND_COUNT; ++b) {
        if (std::abs(m_band_gains_db[b]) < 1e-4f) {
            continue;
        }

        Biquad& filter = m_biquads[b];
        for (int32_t ch = 0; ch < m_channels; ++ch) {
            BiquadState& state = m_channel_states[b][ch];
            for (int32_t i = 0; i < samples; ++i) {
                int32_t idx = i * m_channels + ch;
                in_out_data[idx] = filter.processSample(in_out_data[idx], state);
            }
        }
    }
}

} // namespace mammon
