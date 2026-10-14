// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so
// File: audioeffect_reverb.h
// Description: Reverberation processor reverse-engineered from mammon::Reverb
// ===================================================================================

#pragma once

#include "audioeffect_types.h"
#include <vector>

namespace mammon {

/**
 * @brief Lowpass-Feedback Comb Filter (LBCF)
 */
class CombFilter {
public:
    CombFilter();
    void setBufferSize(int32_t size);
    void setFeedback(float val);
    void setDamp(float val);
    void reset();

    float process(float input);

private:
    std::vector<float> m_buffer;
    int32_t m_buf_size;
    int32_t m_buf_idx;
    float m_feedback;
    float m_damp1;
    float m_damp2;
    float m_filter_store;
};

/**
 * @brief Schroeder Allpass Filter
 */
class AllpassFilter {
public:
    AllpassFilter();
    void setBufferSize(int32_t size);
    void setFeedback(float val);
    void reset();

    float process(float input);

private:
    std::vector<float> m_buffer;
    int32_t m_buf_size;
    int32_t m_buf_idx;
    float m_feedback;
};

/**
 * @brief Complete Stereo Reverb Network (mammon::Reverb at opcode 0x192d88..0x193b80)
 */
class Reverb {
public:
    Reverb(float sample_rate = 44100.0f);
    ~Reverb() = default;

    void reset();

    /// Sets dry level (linear gain, offset 0x3c at opcode 0x193ac0)
    void setDry(float dry);
    float getDry() const { return m_params.dry; }

    /// Sets wet level (linear gain, offset 0x40 at opcode 0x193adc)
    void setWet(float wet);
    float getWet() const { return m_params.wet; }

    /// Sets room size (0.0 .. 1.0, opcode 0x193a50)
    void setRoomSize(float room_size);
    float getRoomSize() const { return m_params.room_size; }

    /// Sets high frequency damping (0.0 .. 1.0, opcode 0x193a90)
    void setDamp(float damp);
    float getDamp() const { return m_params.damp; }

    /// Sets stereo width expansion (0.0 .. 1.0, opcode 0x193ab0)
    void setStereoDepth(float depth);
    float getStereoDepth() const { return m_params.stereo_depth; }

    /// Decibels to linear conversion: 10^(db / 20) (opcode 0x193520)
    static float db2Linear(float db);

    /// Linear to decibels conversion: 20 * log10(lin) (opcode 0x193b40)
    static float linear2Db(float lin);

    /// Processes stereo planar audio
    void process(float* in_l, float* in_r, float* out_l, float* out_r, int32_t num_samples);

    /// Processes interleaved stereo audio in-place
    void processInterleaved(float* in_out_data, int32_t num_samples);

private:
    float m_sample_rate;
    ReverbParams m_params;

    // 8 parallel comb filters per stereo channel
    CombFilter m_comb_l[8];
    CombFilter m_comb_r[8];

    // 4 series allpass filters per stereo channel
    AllpassFilter m_allpass_l[4];
    AllpassFilter m_allpass_r[4];

    void updateInternalParameters();
};

} // namespace mammon
