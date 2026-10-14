// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so
// File: audioeffect_biquad.h
// Description: Biquad IIR filters and 10-Band Graphic/Parametric Equalizer
// ===================================================================================

#pragma once

#include "audioeffect_types.h"
#include <vector>

namespace mammon {

/**
 * @brief Direct Form II Transposed Biquad IIR Filter
 */
class Biquad {
public:
    Biquad();
    void reset();

    void setCoefficients(const BiquadCoeffs& coeffs);
    const BiquadCoeffs& getCoefficients() const { return m_coeffs; }

    /// Processes a single audio sample (mono)
    float processSample(float in_sample, BiquadState& state);

    // Filter Designers (Robert Bristow-Johnson Audio EQ Cookbook)
    static BiquadCoeffs designPeakingEQ(float sample_rate, float center_freq, float Q, float gain_dB);
    static BiquadCoeffs designLowShelf(float sample_rate, float cutoff_freq, float Q, float gain_dB);
    static BiquadCoeffs designHighShelf(float sample_rate, float cutoff_freq, float Q, float gain_dB);
    static BiquadCoeffs designLowPass(float sample_rate, float cutoff_freq, float Q);
    static BiquadCoeffs designHighPass(float sample_rate, float cutoff_freq, float Q);

private:
    BiquadCoeffs m_coeffs;
};

/**
 * @brief 10-Band Equalizer reverse-engineered from mammon::Equalizer (opcode 0x1544ac, 0x188c38, 0x1886c4)
 */
class Equalizer {
public:
    Equalizer(float sample_rate = 44100.0f, int32_t channels = 2);
    ~Equalizer() = default;

    void reset();

    /// Returns band count (opcode 0x1544ac: mov w0, #0xa; ret -> 10)
    static uint32_t eqGetBandCount() { return EQ_BAND_COUNT; }

    /// Returns center frequency of band in Hz (opcode 0x188c38 / 0x3a5cd4)
    static float eqGetBandFre(uint32_t band_idx);

    /// Converts dB gain into linear gain with clamping [-20dB, +20dB] (opcode 0x1886c4)
    static float eqdB2Gain(float db);

    /// Sets gain in dB for specific band (-20 dB to +20 dB)
    void setBandGain(uint32_t band_idx, float gain_dB);
    float getBandGain(uint32_t band_idx) const;

    /// Processes planar audio buffers (data[channel][sample])
    void process(float** in_out_data, int32_t samples);

    /// Processes interleaved audio buffer
    void processInterleaved(float* in_out_data, int32_t samples);

private:
    float m_sample_rate;
    int32_t m_channels;
    float m_band_gains_db[EQ_BAND_COUNT];
    Biquad m_biquads[EQ_BAND_COUNT];
    std::vector<std::vector<BiquadState>> m_channel_states; // [band][channel]

    void updateBandFilter(uint32_t band_idx);
};

} // namespace mammon
