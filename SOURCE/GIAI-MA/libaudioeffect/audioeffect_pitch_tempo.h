// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so
// File: audioeffect_pitch_tempo.h
// Description: Pitch shifting, voice modulation, and time stretching engine
// ===================================================================================

#pragma once

#include "audioeffect_types.h"
#include <vector>

namespace mammon {

/**
 * @brief Pitch and Tempo Adjuster (mammon::PitchTempoAdjuster at opcode 0x175cc8..0x179b40)
 */
class PitchTempoAdjuster {
public:
    PitchTempoAdjuster(float sample_rate = 44100.0f, int32_t channels = 2);
    ~PitchTempoAdjuster() = default;

    void reset();

    /// Sets raw pitch multiplier (0.25x .. 4.0x)
    void setPitchScale(float scale);
    float getPitchScale() const { return m_config.pitch_scale; }

    /// Sets pitch change in semitones (-24 .. +24)
    void setSemitones(float semitones);
    static float semitonesToPitchScale(float semitones);

    /// Sets voice effect preset (Chipmunk, Monster, Robot, Echo...)
    void setVoicePreset(VoicePreset preset);
    VoicePreset getVoicePreset() const { return m_current_preset; }

    /// Sets window size option (opcode 0x175cc8)
    void setWindowOption(int32_t opt) { m_config.window_opt = opt; }

    /// Processes planar audio buffers (data[channel][sample])
    void process(float** in_out_data, int32_t num_samples);

private:
    float m_sample_rate;
    int32_t m_channels;
    PitchTempoConfig m_config;
    VoicePreset m_current_preset;

    // Ring modulator carrier phase for Robot preset
    float m_carrier_phase;
    float m_carrier_freq;

    // Delay lines for Echo preset
    std::vector<std::vector<float>> m_echo_buffers;
    int32_t m_echo_buf_size;
    int32_t m_echo_buf_idx;
    float m_echo_feedback;

    // Pitch grain overlap-add state
    float m_read_pos;
};

} // namespace mammon
