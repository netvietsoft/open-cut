// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so
// File: audioeffect_reverb.cpp
// Description: Full implementation of stereo reverberation network
// ===================================================================================

#include "audioeffect_reverb.h"
#include <cmath>
#include <algorithm>

namespace mammon {

// ===================================================================================
// COMB FILTER
// ===================================================================================

CombFilter::CombFilter()
    : m_buf_size(0), m_buf_idx(0), m_feedback(0.5f), m_damp1(0.5f), m_damp2(0.5f), m_filter_store(0.0f) {
}

void CombFilter::setBufferSize(int32_t size) {
    m_buf_size = (size < 1) ? 1 : size;
    m_buffer.assign(m_buf_size, 0.0f);
    m_buf_idx = 0;
    m_filter_store = 0.0f;
}

void CombFilter::setFeedback(float val) {
    m_feedback = val;
}

void CombFilter::setDamp(float val) {
    m_damp1 = val;
    m_damp2 = 1.0f - val;
}

void CombFilter::reset() {
    std::fill(m_buffer.begin(), m_buffer.end(), 0.0f);
    m_filter_store = 0.0f;
    m_buf_idx = 0;
}

float CombFilter::process(float input) {
    if (m_buf_size == 0) return input;

    float output = m_buffer[m_buf_idx];

    // Lowpass filter inside the feedback loop
    m_filter_store = (output * m_damp2) + (m_filter_store * m_damp1);

    // Write back to circular delay buffer
    m_buffer[m_buf_idx] = input + (m_filter_store * m_feedback);

    if (++m_buf_idx >= m_buf_size) {
        m_buf_idx = 0;
    }

    return output;
}


// ===================================================================================
// ALLPASS FILTER
// ===================================================================================

AllpassFilter::AllpassFilter()
    : m_buf_size(0), m_buf_idx(0), m_feedback(0.5f) {
}

void AllpassFilter::setBufferSize(int32_t size) {
    m_buf_size = (size < 1) ? 1 : size;
    m_buffer.assign(m_buf_size, 0.0f);
    m_buf_idx = 0;
}

void AllpassFilter::setFeedback(float val) {
    m_feedback = val;
}

void AllpassFilter::reset() {
    std::fill(m_buffer.begin(), m_buffer.end(), 0.0f);
    m_buf_idx = 0;
}

float AllpassFilter::process(float input) {
    if (m_buf_size == 0) return input;

    float buf_out = m_buffer[m_buf_idx];
    float output = -input + buf_out;

    m_buffer[m_buf_idx] = input + (buf_out * m_feedback);

    if (++m_buf_idx >= m_buf_size) {
        m_buf_idx = 0;
    }

    return output;
}


// ===================================================================================
// STEREO REVERB PROCESSOR
// ===================================================================================

Reverb::Reverb(float sample_rate)
    : m_sample_rate(sample_rate) {
    float rate_scale = (sample_rate > 0.0f) ? (sample_rate / 44100.0f) : 1.0f;

    for (int i = 0; i < 8; ++i) {
        m_comb_l[i].setBufferSize(static_cast<int32_t>(COMB_TUNING_L[i] * rate_scale));
        m_comb_r[i].setBufferSize(static_cast<int32_t>(COMB_TUNING_R[i] * rate_scale));
    }

    for (int i = 0; i < 4; ++i) {
        m_allpass_l[i].setBufferSize(static_cast<int32_t>(ALLPASS_TUNING_L[i] * rate_scale));
        m_allpass_r[i].setBufferSize(static_cast<int32_t>(ALLPASS_TUNING_R[i] * rate_scale));
        m_allpass_l[i].setFeedback(0.5f);
        m_allpass_r[i].setFeedback(0.5f);
    }

    updateInternalParameters();
}

void Reverb::reset() {
    for (int i = 0; i < 8; ++i) {
        m_comb_l[i].reset();
        m_comb_r[i].reset();
    }
    for (int i = 0; i < 4; ++i) {
        m_allpass_l[i].reset();
        m_allpass_r[i].reset();
    }
}

void Reverb::setDry(float dry) {
    m_params.dry = (dry < 0.0f) ? 0.0f : dry;
}

void Reverb::setWet(float wet) {
    m_params.wet = (wet < 0.0f) ? 0.0f : wet;
}

void Reverb::setRoomSize(float room_size) {
    m_params.room_size = std::max(0.0f, std::min(1.0f, room_size));
    updateInternalParameters();
}

void Reverb::setDamp(float damp) {
    m_params.damp = std::max(0.0f, std::min(1.0f, damp));
    updateInternalParameters();
}

void Reverb::setStereoDepth(float depth) {
    m_params.stereo_depth = std::max(0.0f, std::min(1.0f, depth));
}

void Reverb::updateInternalParameters() {
    float room_feedback = 0.7f + (m_params.room_size * 0.28f);
    float damp_val = m_params.damp * 0.4f;

    for (int i = 0; i < 8; ++i) {
        m_comb_l[i].setFeedback(room_feedback);
        m_comb_r[i].setFeedback(room_feedback);
        m_comb_l[i].setDamp(damp_val);
        m_comb_r[i].setDamp(damp_val);
    }
}

/**
 * @brief db2Linear
 * 
 * ARM64 Disassembly Parity (0x193520):
 *   0x193520: adrp x8, #0x3a5000; ldr s1, [x8, #0x3bc] (s1 = 0.05f = 1/20)
 *   0x193528: fmul s0, s0, s1
 *   0x19352c: b #0xaebe0 -> powf(10.0f, db / 20.0f)
 */
float Reverb::db2Linear(float db) {
    return std::pow(10.0f, db * 0.05f);
}

/**
 * @brief linear2Db
 * 
 * ARM64 Disassembly Parity (0x193b40):
 *   0x193b40: bl #0xb0080 -> log10f(lin)
 *   0x193b44: fmov s1, #20.0
 *   0x193b48: fmul s0, s0, s1
 *   0x193b4c: ret
 */
float Reverb::linear2Db(float lin) {
    if (lin <= 1e-6f) return -120.0f;
    return 20.0f * std::log10(lin);
}

void Reverb::process(float* in_l, float* in_r, float* out_l, float* out_r, int32_t num_samples) {
    if (num_samples <= 0 || !out_l || !out_r) return;

    float wet1 = m_params.wet * (m_params.stereo_depth * 0.5f + 0.5f);
    float wet2 = m_params.wet * ((1.0f - m_params.stereo_depth) * 0.5f);
    float dry = m_params.dry;

    for (int32_t i = 0; i < num_samples; ++i) {
        float input_l = in_l ? in_l[i] : 0.0f;
        float input_r = in_r ? in_r[i] : input_l;
        float input_mono = (input_l + input_r) * 0.015f; // input attenuation gain

        float out_comb_l = 0.0f;
        float out_comb_r = 0.0f;

        for (int c = 0; c < 8; ++c) {
            out_comb_l += m_comb_l[c].process(input_mono);
            out_comb_r += m_comb_r[c].process(input_mono);
        }

        for (int a = 0; a < 4; ++a) {
            out_comb_l = m_allpass_l[a].process(out_comb_l);
            out_comb_r = m_allpass_r[a].process(out_comb_r);
        }

        out_l[i] = (out_comb_l * wet1) + (out_comb_r * wet2) + (input_l * dry);
        out_r[i] = (out_comb_r * wet1) + (out_comb_l * wet2) + (input_r * dry);
    }
}

void Reverb::processInterleaved(float* in_out_data, int32_t num_samples) {
    if (!in_out_data || num_samples <= 0) return;

    std::vector<float> in_l(num_samples);
    std::vector<float> in_r(num_samples);
    std::vector<float> out_l(num_samples);
    std::vector<float> out_r(num_samples);

    for (int32_t i = 0; i < num_samples; ++i) {
        in_l[i] = in_out_data[i * 2];
        in_r[i] = in_out_data[i * 2 + 1];
    }

    process(in_l.data(), in_r.data(), out_l.data(), out_r.data(), num_samples);

    for (int32_t i = 0; i < num_samples; ++i) {
        in_out_data[i * 2] = out_l[i];
        in_out_data[i * 2 + 1] = out_r[i];
    }
}

} // namespace mammon
