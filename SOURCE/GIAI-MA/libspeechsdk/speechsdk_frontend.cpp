// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_frontend.cpp
// Description: Full implementation of Acoustic Frontend, Mel Filterbank, and VAD
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "speechsdk_frontend.h"
#include <algorithm>
#include <cmath>

namespace lab::speech::client::frontware {

constexpr float PI = 3.14159265358979323846f;

AcousticFrontend::AcousticFrontend(int32_t sample_rate, int32_t frame_size,
                                   int32_t hop_size, int32_t num_mel_bins)
    : m_sample_rate(sample_rate), m_frame_size(frame_size),
      m_hop_size(hop_size), m_num_mel_bins(num_mel_bins) {
    // Kích thước FFT là lũy thừa 2 nhỏ nhất >= frame_size
    m_fft_size = 1;
    while (m_fft_size < m_frame_size) {
        m_fft_size <<= 1;
    }

    // Khởi tạo bảng tra cứu cửa sổ Hamming
    m_hamming_table.resize(m_frame_size);
    for (int32_t n = 0; n < m_frame_size; ++n) {
        m_hamming_table[n] = 0.54f - 0.46f * std::cos((2.0f * PI * n) / (m_frame_size - 1));
    }

    initMelFilterbank();
}

void AcousticFrontend::reset() {
    m_sample_buffer.clear();
    m_pre_emphasis_prev = 0.0f;
    m_vad_state = VadState::SILENCE;
    m_noise_floor = 20.0f;
    m_speech_frames = 0;
    m_silence_frames = 0;
    m_frame_counter = 0;
}

void AcousticFrontend::initMelFilterbank() {
    m_mel_filters.clear();
    m_mel_filters.resize(m_num_mel_bins);

    float low_freq_mel = hzToMel(0.0f);
    float high_freq_mel = hzToMel(static_cast<float>(m_sample_rate) / 2.0f);
    float mel_step = (high_freq_mel - low_freq_mel) / (m_num_mel_bins + 1);

    int32_t num_fft_bins = m_fft_size / 2 + 1;
    float hz_per_bin = static_cast<float>(m_sample_rate) / static_cast<float>(m_fft_size);

    std::vector<int32_t> bin_points(m_num_mel_bins + 2);
    for (int32_t i = 0; i < m_num_mel_bins + 2; ++i) {
        float mel = low_freq_mel + i * mel_step;
        float hz = melToHz(mel);
        bin_points[i] = std::clamp(static_cast<int32_t>(std::floor(hz / hz_per_bin)), 0, num_fft_bins - 1);
    }

    for (int32_t m = 0; m < m_num_mel_bins; ++m) {
        MelFilter& filter = m_mel_filters[m];
        filter.start_bin = bin_points[m];
        filter.center_bin = bin_points[m + 1];
        filter.end_bin = bin_points[m + 2];

        int32_t total_bins = filter.end_bin - filter.start_bin + 1;
        if (total_bins > 0) {
            filter.weights.resize(total_bins, 0.0f);

            // Nhánh dốc lên của tam giác
            int32_t up_span = filter.center_bin - filter.start_bin;
            if (up_span > 0) {
                for (int32_t k = filter.start_bin; k <= filter.center_bin; ++k) {
                    filter.weights[k - filter.start_bin] = static_cast<float>(k - filter.start_bin) / up_span;
                }
            }

            // Nhánh dốc xuống của tam giác
            int32_t down_span = filter.end_bin - filter.center_bin;
            if (down_span > 0) {
                for (int32_t k = filter.center_bin; k <= filter.end_bin; ++k) {
                    filter.weights[k - filter.start_bin] = static_cast<float>(filter.end_bin - k) / down_span;
                }
            }
        }
    }
}

void AcousticFrontend::applyPreEmphasis(const float* in, float* out, size_t size, float alpha) {
    if (size == 0) return;
    out[0] = in[0];
    for (size_t i = 1; i < size; ++i) {
        out[i] = in[i] - alpha * in[i - 1];
    }
}

void AcousticFrontend::applyHammingWindow(float* frame) const {
    for (int32_t i = 0; i < m_frame_size; ++i) {
        frame[i] *= m_hamming_table[i];
    }
}

void AcousticFrontend::computePowerSpectrum(const float* windowed_frame, float* power_spectrum) const {
    int32_t num_bins = m_fft_size / 2 + 1;
    // Biến đổi Fourier rời rạc DFT thực (Real DFT Power Spectrum)
    for (int32_t k = 0; k < num_bins; ++k) {
        float real_sum = 0.0f;
        float imag_sum = 0.0f;
        float angle_step = 2.0f * PI * k / m_fft_size;

        for (int32_t n = 0; n < m_frame_size; ++n) {
            float angle = angle_step * n;
            real_sum += windowed_frame[n] * std::cos(angle);
            imag_sum -= windowed_frame[n] * std::sin(angle);
        }

        power_spectrum[k] = real_sum * real_sum + imag_sum * imag_sum;
    }
}

void AcousticFrontend::computeMelEnergies(const float* power_spectrum, float* mel_energies) const {
    for (int32_t m = 0; m < m_num_mel_bins; ++m) {
        const MelFilter& filter = m_mel_filters[m];
        float energy_sum = 0.0f;

        for (int32_t k = filter.start_bin; k <= filter.end_bin; ++k) {
            int32_t weight_idx = k - filter.start_bin;
            if (weight_idx >= 0 && weight_idx < static_cast<int32_t>(filter.weights.size())) {
                energy_sum += power_spectrum[k] * filter.weights[weight_idx];
            }
        }

        // Năng lượng phổ Mel dạng Logarithmic (dB)
        mel_energies[m] = std::log(std::max(1e-5f, energy_sum));
    }
}

VadState AcousticFrontend::updateVad(float frame_energy) {
    // Thích nghi mức sàn tạp âm nền
    if (frame_energy < m_noise_floor) {
        m_noise_floor = 0.95f * m_noise_floor + 0.05f * frame_energy;
    } else {
        m_noise_floor = 0.999f * m_noise_floor + 0.001f * frame_energy;
    }

    // Ngưỡng năng lượng phát hiện tiếng nói (+15 dB trên sàn nhiễu)
    float speech_threshold = m_noise_floor + 15.0f;
    bool is_active = (frame_energy > speech_threshold);

    if (is_active) {
        m_speech_frames++;
        m_silence_frames = 0;
        if (m_speech_frames >= 3) {
            m_vad_state = (m_vad_state == VadState::SILENCE) ? VadState::SPEECH_START : VadState::SPEECH_CONTINUE;
        }
    } else {
        m_silence_frames++;
        if (m_silence_frames >= 15) { // 15 khung ~ 150ms im lặng
            m_vad_state = (m_vad_state == VadState::SPEECH_CONTINUE || m_vad_state == VadState::SPEECH_START)
                          ? VadState::SPEECH_END : VadState::SILENCE;
            m_speech_frames = 0;
        }
    }

    return m_vad_state;
}

int32_t AcousticFrontend::processPcm(const int16_t* pcm_samples, size_t sample_count, bool is_last) {
    if (!pcm_samples && sample_count > 0) return 0;

    // Chuyển đổi mẫu 16-bit PCM sang chuẩn hóa [-1.0f, +1.0f]
    m_sample_buffer.reserve(m_sample_buffer.size() + sample_count);
    for (size_t i = 0; i < sample_count; ++i) {
        m_sample_buffer.push_back(static_cast<float>(pcm_samples[i]) / 32768.0f);
    }

    int32_t frames_processed = 0;
    std::vector<float> frame_raw(m_frame_size);
    std::vector<float> frame_pre(m_frame_size);
    std::vector<float> power_spectrum(m_fft_size / 2 + 1);
    std::vector<float> mel_energies(m_num_mel_bins);

    while (m_sample_buffer.size() >= static_cast<size_t>(m_frame_size)) {
        // Trích xuất 1 khung mẫu
        std::copy(m_sample_buffer.begin(), m_sample_buffer.begin() + m_frame_size, frame_raw.begin());

        // 1. Tiền tăng cường
        applyPreEmphasis(frame_raw.data(), frame_pre.data(), m_frame_size, 0.97f);

        // 2. Tính năng lượng khung (Frame Energy)
        float energy_sum = 0.0f;
        for (float val : frame_pre) {
            energy_sum += val * val;
        }
        float log_energy = 10.0f * std::log10(std::max(1e-6f, energy_sum) * 32768.0f * 32768.0f);

        // 3. Cập nhật VAD
        updateVad(log_energy);

        // 4. Cửa sổ Hamming
        applyHammingWindow(frame_pre.data());

        // 5. Phổ năng lượng FFT
        computePowerSpectrum(frame_pre.data(), power_spectrum.data());

        // 6. Ngân hàng bộ lọc Mel
        computeMelEnergies(power_spectrum.data(), mel_energies.data());

        m_frame_counter++;
        frames_processed++;

        // Dịch chuyển bước nhảy hop_size
        m_sample_buffer.erase(m_sample_buffer.begin(), m_sample_buffer.begin() + m_hop_size);
    }

    if (is_last) {
        m_sample_buffer.clear();
        m_vad_state = VadState::SILENCE;
    }

    return frames_processed;
}

int64_t AcousticFrontend::getCurrentAudioTimeMs() const {
    return static_cast<int64_t>(m_frame_counter) * (m_hop_size * 1000 / m_sample_rate);
}

// ===================================================================================
// Bộ tự kiểm chứng tính đúng đắn AcousticFrontend (Self-Test Suite)
// ===================================================================================
bool AcousticFrontend::runSelfTest() {
    AcousticFrontend frontend(16000, 400, 160, 40);

    // 1. Kiểm tra tính khả nghịch Hz <-> Mel
    float hz_test = 1000.0f;
    float mel_val = AcousticFrontend::hzToMel(hz_test);
    float hz_recovered = AcousticFrontend::melToHz(mel_val);
    if (std::abs(hz_test - hz_recovered) > 0.01f) return false;

    // 2. Kiểm tra bộ lọc tiền tăng cường (Pre-emphasis filter)
    float in_sig[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
    float out_sig[4] = { 0.0f };
    AcousticFrontend::applyPreEmphasis(in_sig, out_sig, 4, 0.97f);
    // Tín hiệu DC: out[1] = 1.0 - 0.97 * 1.0 = 0.03
    if (std::abs(out_sig[1] - 0.03f) > 1e-4) return false;

    // 3. Kiểm tra tính đối xứng của cửa sổ Hamming
    std::vector<float> hamming_test(400, 1.0f);
    frontend.applyHammingWindow(hamming_test.data());
    // Điểm đầu và điểm cuối xấp xỉ 0.08 (0.54 - 0.46)
    if (std::abs(hamming_test[0] - 0.08f) > 0.01f) return false;
    if (std::abs(hamming_test[399] - 0.08f) > 0.01f) return false;
    // Điểm giữa xấp xỉ 1.0 (0.54 + 0.46)
    if (std::abs(hamming_test[200] - 1.0f) > 0.01f) return false;

    // 4. Kiểm tra nạp luồng âm thanh PCM giả lập và bước nhảy khung
    std::vector<int16_t> pcm_noise(1600, 50); // 1600 mẫu im lặng ~ 100ms
    int32_t frames = frontend.processPcm(pcm_noise.data(), pcm_noise.size(), false);
    // (1600 - 400) / 160 + 1 = 8 khung
    if (frames != 8) return false;
    if (frontend.getCurrentVadState() != VadState::SILENCE) return false;

    // 5. Kiểm tra âm thanh lớn kích hoạt VAD
    std::vector<int16_t> pcm_loud(1600, 15000); // Tín hiệu biên độ lớn
    frontend.processPcm(pcm_loud.data(), pcm_loud.size(), false);
    // Sau khi nạp tín hiệu lớn, VAD phải chuyển sang SPEECH_START hoặc SPEECH_CONTINUE
    if (frontend.getCurrentVadState() == VadState::SILENCE) return false;

    return true;
}

} // namespace lab::speech::client::frontware
