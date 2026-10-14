// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_frontend.h
// Description: Acoustic Frontend: Framing, Hamming Window, Mel Filterbank, and VAD
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <vector>
#include <cmath>
#include <cstdint>
#include "speechsdk_types.h"

namespace lab::speech::client::frontware {

/**
 * @brief Bộ lọc ngân hàng Mel (Triangular Mel Filterbank)
 */
struct MelFilter {
    int32_t start_bin{0};       ///< Chỉ số FFT bắt đầu / Start FFT bin
    int32_t center_bin{0};      ///< Chỉ số FFT đỉnh giữa / Center FFT bin
    int32_t end_bin{0};         ///< Chỉ số FFT kết thúc / End FFT bin
    std::vector<float> weights; ///< Trọng số tam giác / Triangle filter weights
};

/**
 * @brief Bộ tiền xử lý tín hiệu âm thanh và trích xuất đặc trưng âm học
 * Acoustic Frontend & Feature Extraction Pipeline (Khôi phục từ EngineImpl)
 */
class AcousticFrontend {
public:
    AcousticFrontend(int32_t sample_rate = 16000, int32_t frame_size = 400,
                     int32_t hop_size = 160, int32_t num_mel_bins = 40);
    ~AcousticFrontend() = default;

    /**
     * @brief Đặt lại trạng thái bộ lọc tiền tăng cường và VAD
     */
    void reset();

    /**
     * @brief Nạp dữ liệu PCM 16-bit và xử lý các khung âm thanh hoàn chỉnh
     * @param pcm_samples Mảng mẫu âm thanh 16-bit PCM
     * @param sample_count Số lượng mẫu
     * @param is_last Cờ đánh dấu khung cuối cùng của luồng
     * @return Số lượng khung đã xử lý thành công
     */
    int32_t processPcm(const int16_t* pcm_samples, size_t sample_count, bool is_last);

    /**
     * @brief Áp dụng bộ lọc tiền tăng cường (Pre-emphasis filter: y[n] = x[n] - alpha * x[n-1])
     */
    static void applyPreEmphasis(const float* in, float* out, size_t size, float alpha = 0.97f);

    /**
     * @brief Nhân cửa sổ Hamming (Hamming Window: 0.54 - 0.46 * cos(2*pi*n / (N-1)))
     */
    void applyHammingWindow(float* frame) const;

    /**
     * @brief Tính toán phổ năng lượng thực (Real FFT Power Spectrum)
     */
    void computePowerSpectrum(const float* windowed_frame, float* power_spectrum) const;

    /**
     * @brief Áp dụng ngân hàng bộ lọc Mel 40 kênh (Mel Filterbank Energies)
     */
    void computeMelEnergies(const float* power_spectrum, float* mel_energies) const;

    /**
     * @brief Bộ phát hiện tiếng nói thích nghi VAD (Adaptive Voice Activity Detector)
     * @param frame_energy Năng lượng logarithmic của khung âm thanh
     * @return Trạng thái VAD hiện tại (SILENCE, SPEECH_START, SPEECH_CONTINUE, SPEECH_END)
     */
    VadState updateVad(float frame_energy);

    // Getters
    VadState getCurrentVadState() const { return m_vad_state; }
    int32_t getProcessedFrameCount() const { return m_frame_counter; }
    int64_t getCurrentAudioTimeMs() const;

    static float hzToMel(float hz) {
        return 2595.0f * std::log10(1.0f + hz / 700.0f);
    }

    static float melToHz(float mel) {
        return 700.0f * (std::pow(10.0f, mel / 2595.0f) - 1.0f);
    }

    static bool runSelfTest();

private:
    void initMelFilterbank();

    int32_t m_sample_rate;
    int32_t m_frame_size;       // 400 mẫu = 25ms @ 16kHz
    int32_t m_hop_size;         // 160 mẫu = 10ms @ 16kHz
    int32_t m_num_mel_bins;     // 40 kênh Mel
    int32_t m_fft_size;         // 512 điểm FFT

    std::vector<float> m_hamming_table;
    std::vector<MelFilter> m_mel_filters;
    std::vector<float> m_sample_buffer;

    float m_pre_emphasis_prev{0.0f};

    // Biến trạng thái VAD thích nghi
    VadState m_vad_state{VadState::SILENCE};
    float m_noise_floor{20.0f};
    int32_t m_speech_frames{0};
    int32_t m_silence_frames{0};
    int32_t m_frame_counter{0};
};

} // namespace lab::speech::client::frontware
