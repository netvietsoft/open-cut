// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libaudioeffect.so (ByteDance Mammon SAMICore Audio DSP Engine)
// File: audioeffect_types.h
// Description: Audio DSP data types, biquad coefficients, reverb network structures,
//              and SAMICore AArch64 ABI contracts reverse-engineered from ARM64 opcodes
//              (0x1544ac, 0x1886c4, 0x188c38, 0x193520, 0x193b40, 0x193ac0).
// ===================================================================================

#pragma once

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <cmath>

#ifdef __cplusplus
namespace mammon {

// ===================================================================================
// 1. EQUALIZER CONSTANTS & 10-BAND OCTAVE TABLE
// Bảng tần số trung tâm 10 băng tần chuẩn ISO trích xuất từ opcode 0x188c38 & 0x3a5cd4
// ===================================================================================

constexpr uint32_t EQ_BAND_COUNT = 10; // Opcode 0x1544ac: mov w0, #0xa; ret

/// Bảng 10 tần số trung tâm (Hz) khớp chính xác dữ liệu bộ nhớ tại 0x3a5cd4
inline const float EQ_CENTER_FREQUENCIES[EQ_BAND_COUNT] = {
    31.25f,   // Band 0: Sub-bass cực trầm
    62.5f,    // Band 1: Bass trầm
    125.0f,   // Band 2: Mid-bass
    250.0f,   // Band 3: Low-mid ấm
    500.0f,   // Band 4: Mid giọng hát
    1000.0f,  // Band 5: High-mid rõ nét
    2000.0f,  // Band 6: Presence tươi sáng
    4000.0f,  // Band 7: Treble bổng
    8000.0f,  // Band 8: Air bay bổng
    16000.0f  // Band 9: Brilliance long lanh
};

/// Ngưỡng chặn dải động Equalizer (clamped range [-20 dB, +20 dB] tại opcode 0x1886c4)
constexpr float EQ_MIN_GAIN_DB = -20.0f;
constexpr float EQ_MAX_GAIN_DB = 20.0f;


// ===================================================================================
// 2. BIQUAD IIR FILTER COEFFICIENTS & STATE
// Cấu trúc hệ số bộ lọc số lưỡng nhị phương Direct Form II
// ===================================================================================

enum class FilterType {
    PEAKING = 0,
    LOW_SHELF = 1,
    HIGH_SHELF = 2,
    LOW_PASS = 3,
    HIGH_PASS = 4,
    BAND_PASS = 5,
    NOTCH = 6
};

/**
 * @brief Second-Order IIR Biquad filter normalized coefficients
 * y[n] = b0*x[n] + b1*x[n-1] + b2*x[n-2] - a1*y[n-1] - a2*y[n-2]  (a0 = 1.0)
 */
struct BiquadCoeffs {
    float b0;
    float b1;
    float b2;
    float a1;
    float a2;

    BiquadCoeffs() : b0(1.0f), b1(0.0f), b2(0.0f), a1(0.0f), a2(0.0f) {}
};

/**
 * @brief Per-channel direct form II transposed state memory
 */
struct BiquadState {
    float s1;
    float s2;

    BiquadState() : s1(0.0f), s2(0.0f) {}
    void reset() { s1 = 0.0f; s2 = 0.0f; }
};


// ===================================================================================
// 3. REVERB CONFIGURATION & FREEVERB DELAY LINE TUNING
// Cấu trúc tham số Reverb mô phỏng mạng Schroeder / Freeverb tại opcode 0x193ac0
// ===================================================================================

struct ReverbParams {
    float dry;           // 0x3c: Hệ số âm mộc (Dry Gain, opcode 0x193ac0)
    float wet;           // 0x40: Hệ số âm vang (Wet Gain, opcode 0x193adc)
    float room_size;     // Kích thước phòng (Phản hồi trễ 0.7 .. 0.98)
    float damp;          // Độ tiêu âm tần số cao (0.0 .. 1.0)
    float stereo_depth;  // Độ rộng không gian stereo (0.0 .. 1.0)

    ReverbParams() : dry(1.0f), wet(0.35f), room_size(0.8f), damp(0.3f), stereo_depth(1.0f) {}
};

/// Hằng số độ dài dòng trễ (Comb delay lines) ở tần số mẫu 44100 Hz
inline const int32_t COMB_TUNING_L[8] = { 1116, 1188, 1277, 1356, 1422, 1491, 1557, 1617 };
inline const int32_t COMB_TUNING_R[8] = { 1116 + 23, 1188 + 23, 1277 + 23, 1356 + 23, 1422 + 23, 1491 + 23, 1557 + 23, 1617 + 23 };
inline const int32_t ALLPASS_TUNING_L[4] = { 556, 441, 341, 225 };
inline const int32_t ALLPASS_TUNING_R[4] = { 556 + 23, 441 + 23, 341 + 23, 225 + 23 };


// ===================================================================================
// 4. VOICE EFFECTS & PITCH SHIFT PRESETS
// Các chế độ biến đổi giọng nói CapCut (Chipmunk, Monster, Robot, Echo)
// ===================================================================================

enum class VoicePreset : int32_t {
    NONE = 0,
    CHIPMUNK = 1,       // Sóc chuột: +12 semitones (Pitch Scale = 2.0x)
    MONSTER = 2,        // Quái vật trầm: -12 semitones (Pitch Scale = 0.5x)
    BARITONE = 3,       // Giọng trầm nam tính: -5 semitones (Pitch Scale ≈ 0.749x)
    ELF = 4,            // Nữ thần / Yêu tinh: +7 semitones (Pitch Scale ≈ 1.498x)
    ROBOT = 5,          // Người máy: Điều chế vòng chuông 50 Hz (Ring Modulation)
    ECHO_STUDIO = 6,    // Vọng phòng thu: Delay 250ms, Feedback 0.45
    MEGAPHONE = 7,      // Loa phát thanh: Băng thông hẹp 500Hz - 3kHz + méo nhẹ
    KARAOKE_VOCAL = 8   // Nâng tiếng hát: EQ Presence + Reverb vừa + Limiter
};

struct PitchTempoConfig {
    float pitch_scale;  // Hệ số tần số cơ bản F0 (0.25x .. 4.0x)
    float time_ratio;   // Hệ số thời lượng (1.0 = không đổi tốc độ phát)
    int32_t window_opt; // Cửa sổ phân tích FFT/SOLA (opcode 0x175cc8)

    PitchTempoConfig() : pitch_scale(1.0f), time_ratio(1.0f), window_opt(1) {}
};


// ===================================================================================
// 5. SAMICORE HOST BRIDGE INTERFACES
// Giao diện C-API SAMICore Host Bridge (JNI bindings tại 0x133ee0)
// ===================================================================================

enum SAMICoreIdentify : int32_t {
    SAMI_IDENTIFY_UNKNOWN               = 0,
    SAMI_IDENTIFY_EQUALIZER             = 1,
    SAMI_IDENTIFY_REVERB                = 2,
    SAMI_IDENTIFY_PITCH_SHIFTER         = 3,
    SAMI_IDENTIFY_AUDIO_CLEANER_DENOISE = 4,
    SAMI_IDENTIFY_COMPRESSOR_LIMITER    = 5
};

enum SAMICorePropertyId : int32_t {
    SAMI_PROP_NONE                      = 0,
    SAMI_PROP_EQ_BAND_GAIN              = 101, // Đặt gain từng băng tần (-20dB .. +20dB)
    SAMI_PROP_REVERB_DRY                = 201, // Đặt hệ số dry (opcode 0x193ac0)
    SAMI_PROP_REVERB_WET                = 202, // Đặt hệ số wet (opcode 0x193adc)
    SAMI_PROP_REVERB_ROOM_SIZE          = 203, // Đặt kích thước phòng
    SAMI_PROP_PITCH_RATIO               = 301, // Đặt hệ số dịch cao độ
    SAMI_PROP_VOICE_PRESET              = 302, // Đặt preset giọng nói
    SAMI_PROP_DENOISE_INTENSITY         = 401  // Cường độ khử ồn (0.0 .. 1.0)
};

struct SAMICoreBlock {
    float** data;       // Con trỏ mảng kênh (planar planar data: data[ch][sample])
    int32_t channels;   // Số kênh (1 = mono, 2 = stereo)
    int32_t samples;    // Số mẫu trên mỗi kênh

    SAMICoreBlock() : data(nullptr), channels(0), samples(0) {}
};

} // namespace mammon
#endif // __cplusplus
