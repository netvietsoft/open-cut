// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Acoustic Landmark & Constellation Map Engine
// File: afp_landmark_detector.cpp
// Description: Implementation of spectral peak detection, Hamming windowing,
//              and constellation map generation matching AArch64 binary opcodes.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "afp_landmark_detector.h"
#include <cmath>
#include <cstring>
#include <algorithm>
#include <iostream>

namespace audio_fingerprint_sdk {

landmark_peak_afp_t::landmark_peak_afp_t()
    : initialized_(false), total_frames_processed_(0) {
    inner_init();
}

landmark_peak_afp_t::~landmark_peak_afp_t() {
    reset();
}

/**
 * @brief init: Initializes detector with configuration parameters.
 * Matches AArch64 opcode 0x323c (24 bytes).
 * Loads 3 128-bit vector registers q0, q1, q2 into para_ struct.
 */
void landmark_peak_afp_t::init(const landmark_peak_para_t& para) {
    para_ = para;
    inner_init();
}

/**
 * @brief inner_init: Allocates FFT buffers, tables, and window functions.
 * Matches AArch64 opcode 0x3254 (1728 bytes).
 */
void landmark_peak_afp_t::inner_init() {
    if (para_.frame_size <= 0) {
        para_.frame_size = kDefaultFrameSize;
    }
    if (para_.hop_size <= 0) {
        para_.hop_size = kDefaultHopSize;
    }

    gen_ham_win(hamming_window_, para_.frame_size);
    fft_ = std::make_unique<FastFourierTransform>(para_.frame_size);

    reset();
    initialized_ = true;
}

/**
 * @brief gen_ham_win: Generates symmetric Hamming window of length n.
 * Matches AArch64 opcode 0x3914 (448 bytes).
 * Formula: w[i] = 0.54 - 0.46 * cos(2.0 * pi * i / (n - 1)).
 */
void landmark_peak_afp_t::gen_ham_win(std::vector<float>& win, int n) {
    if (n <= 0) {
        win.clear();
        return;
    }

    win.resize(n);
    if (n == 1) {
        win[0] = 1.0f;
        return;
    }

    float inv_n_minus_1 = 1.0f / static_cast<float>(n - 1);
    for (int i = 0; i < n; ++i) {
        float angle = 2.0f * kPI * static_cast<float>(i) * inv_n_minus_1;
        win[i] = 0.54f - 0.46f * std::cos(angle);
    }
}

/**
 * @brief reset: Resets internal state, queues, and frame counters.
 * Matches AArch64 opcode 0x3b80 (84 bytes).
 */
void landmark_peak_afp_t::reset() {
    total_frames_processed_ = 0;
    pcm_residual_buffer_.clear();
    spectrogram_history_.clear();
    detected_landmarks_.clear();
    landmark_pairs_.clear();
}

/**
 * @brief process: Ingests raw audio PCM bytes (16-bit signed LE).
 * Matches AArch64 opcode 0x3bd4 (304 bytes).
 */
int landmark_peak_afp_t::process(unsigned char* pcm_data, int length_bytes) {
    if (!pcm_data || length_bytes <= 0 || !initialized_) {
        return static_cast<int>(AFPStatus::INVALID_PARAM);
    }

    size_t num_samples = length_bytes / sizeof(int16_t);
    if (num_samples == 0) return static_cast<int>(AFPStatus::SUCCESS);

    const int16_t* samples = reinterpret_cast<const int16_t*>(pcm_data);
    push_frames(samples, samples + num_samples);

    return static_cast<int>(AFPStatus::SUCCESS);
}

/**
 * @brief push_frames: Pushes audio samples, applies windowing and FFT.
 * Matches AArch64 opcode 0x3d04 (1364 bytes).
 */
void landmark_peak_afp_t::push_frames(const int16_t* pcm_begin, const int16_t* pcm_end) {
    if (!pcm_begin || !pcm_end || pcm_begin >= pcm_end) return;

    size_t incoming_samples = pcm_end - pcm_begin;
    pcm_residual_buffer_.insert(pcm_residual_buffer_.end(), pcm_begin, pcm_end);

    size_t frame_size = para_.frame_size;
    size_t hop_size = para_.hop_size;
    size_t num_bins = frame_size / 2 + 1;

    std::vector<float> windowed_frame(frame_size, 0.0f);
    std::vector<float> mag_db(num_bins, 0.0f);

    size_t offset = 0;
    while (offset + frame_size <= pcm_residual_buffer_.size()) {
        // Apply Hamming window and normalize to [-1.0, 1.0]
        for (size_t i = 0; i < frame_size; ++i) {
            float sample_f = static_cast<float>(pcm_residual_buffer_[offset + i]) / 32768.0f;
            windowed_frame[i] = sample_f * hamming_window_[i];
        }

        // Compute FFT magnitude in decibels (dB)
        fft_->ComputeMagnitudeDB(windowed_frame.data(), mag_db.data(), frame_size);

        // Store frame in spectrogram history
        std::vector<std::pair<float, bool>> frame_bins(num_bins);
        for (size_t k = 0; k < num_bins; ++k) {
            frame_bins[k] = std::make_pair(mag_db[k], false);
        }
        spectrogram_history_.push_back(std::move(frame_bins));
        total_frames_processed_++;

        offset += hop_size;
    }

    // Keep unprocessed residual samples
    if (offset > 0) {
        pcm_residual_buffer_.erase(pcm_residual_buffer_.begin(), pcm_residual_buffer_.begin() + offset);
    }

    // Locate spectral peaks across recent frames
    if (spectrogram_history_.size() >= static_cast<size_t>(para_.neighborhood_time * 2 + 1)) {
        int start_f = std::max(0, static_cast<int>(spectrogram_history_.size()) - para_.neighborhood_time * 2 - 10);
        int end_f = static_cast<int>(spectrogram_history_.size()) - para_.neighborhood_time;

        std::vector<std::pair<int, int>> new_peaks;
        locate_peaks(new_peaks, spectrogram_history_, start_f, end_f);
        filter_peaks(spectrogram_history_, para_.max_peaks_per_frame);

        for (const auto& p : new_peaks) {
            int t = p.first;
            int f = p.second;
            if (t >= 0 && t < static_cast<int>(spectrogram_history_.size())) {
                if (spectrogram_history_[t][f].second) {
                    detected_landmarks_.emplace_back(t, f, spectrogram_history_[t][f].first);
                }
            }
        }

        GeneratePairs();
    }
}

/**
 * @brief locate_peaks: Extracts local maxima peaks in 2D time-frequency neighborhood.
 * Matches AArch64 opcode 0x4258 (608 bytes).
 */
void landmark_peak_afp_t::locate_peaks(std::vector<std::pair<int, int>>& out_peaks,
                                       const std::vector<std::vector<std::pair<float, bool>>>& spec_matrix,
                                       int start_frame, int end_frame) {
    if (spec_matrix.empty()) return;

    int total_frames = static_cast<int>(spec_matrix.size());
    int num_bins = static_cast<int>(spec_matrix[0].size());

    int dt = para_.neighborhood_time;
    int df = para_.neighborhood_freq;
    float thresh = para_.threshold_db;

    // Convert frequency bounds to bin indices
    float bin_resolution = static_cast<float>(para_.sample_rate) / static_cast<float>(para_.frame_size);
    int min_bin = std::max(1, static_cast<int>(para_.min_freq_hz / bin_resolution));
    int max_bin = std::min(num_bins - 1, static_cast<int>(para_.max_freq_hz / bin_resolution));

    int s_f = std::max(dt, start_frame);
    int e_f = std::min(total_frames - dt - 1, end_frame);

    for (int t = s_f; t <= e_f; ++t) {
        for (int f = min_bin; f <= max_bin; ++f) {
            float val = spec_matrix[t][f].first;
            if (val < thresh) continue;

            bool is_local_max = true;
            for (int nt = t - dt; nt <= t + dt && is_local_max; ++nt) {
                for (int nf = f - df; nf <= f + df; ++nf) {
                    if (nt == t && nf == f) continue;
                    if (nf < 0 || nf >= num_bins) continue;
                    if (spec_matrix[nt][nf].first >= val) {
                        is_local_max = false;
                        break;
                    }
                }
            }

            if (is_local_max) {
                out_peaks.emplace_back(t, f);
            }
        }
    }
}

/**
 * @brief filter_peaks: Applies density suppression to retain top-K peaks.
 * Matches AArch64 opcode 0x5eb4 (808 bytes).
 */
void landmark_peak_afp_t::filter_peaks(std::vector<std::vector<std::pair<float, bool>>>& spec_matrix, int max_peaks) {
    for (size_t t = 0; t < spec_matrix.size(); ++t) {
        std::vector<std::pair<float, int>> frame_peaks;
        for (size_t f = 0; f < spec_matrix[t].size(); ++f) {
            if (spec_matrix[t][f].first > para_.threshold_db) {
                frame_peaks.emplace_back(spec_matrix[t][f].first, static_cast<int>(f));
            }
        }

        // Sort peaks descending by energy
        std::sort(frame_peaks.begin(), frame_peaks.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });

        // Flag top-K peaks
        int count = 0;
        for (const auto& p : frame_peaks) {
            if (count < max_peaks) {
                spec_matrix[t][p.second].second = true;
                count++;
            } else {
                spec_matrix[t][p.second].second = false;
            }
        }
    }
}

/**
 * @brief GeneratePairs: Creates landmark anchor-target pairs (Shazam constellation pairing).
 */
void landmark_peak_afp_t::GeneratePairs() {
    if (detected_landmarks_.size() < 2) return;

    size_t n = detected_landmarks_.size();
    for (size_t i = 0; i < n; ++i) {
        const auto& anchor = detected_landmarks_[i];
        int pairs_formed = 0;

        for (size_t j = i + 1; j < n && pairs_formed < para_.target_pair_count; ++j) {
            const auto& target = detected_landmarks_[j];
            int dt = target.time_frame - anchor.time_frame;

            if (dt > 0 && dt <= para_.max_time_delta) {
                landmark_pairs_.emplace_back(anchor.freq_bin, target.freq_bin, dt, anchor.time_frame);
                pairs_formed++;
            }
        }
    }
}

/**
 * @brief get_afp: Generates serialized audio fingerprint byte vector.
 * Matches AArch64 opcode 0x44b8 (1076 bytes).
 */
int landmark_peak_afp_t::get_afp(std::vector<unsigned char>& out_fingerprint) {
    out_fingerprint.clear();
    if (landmark_pairs_.empty()) {
        return static_cast<int>(AFPStatus::SUCCESS);
    }

    // Binary payload layout:
    // [Header 8B]: 'AFPV' (4B) + Version (2B) + Count (2B)
    // [Data]: For each pair -> anchor_freq(9b) + target_freq(9b) + dt(14b) + time(32b) = 8 bytes
    out_fingerprint.push_back('A');
    out_fingerprint.push_back('F');
    out_fingerprint.push_back('P');
    out_fingerprint.push_back('V');

    uint16_t ver = static_cast<uint16_t>(para_.format_version);
    out_fingerprint.push_back(static_cast<uint8_t>(ver >> 8));
    out_fingerprint.push_back(static_cast<uint8_t>(ver & 0xFF));

    uint16_t count = static_cast<uint16_t>(std::min(static_cast<size_t>(0xFFFF), landmark_pairs_.size()));
    out_fingerprint.push_back(static_cast<uint8_t>(count >> 8));
    out_fingerprint.push_back(static_cast<uint8_t>(count & 0xFF));

    for (size_t i = 0; i < count; ++i) {
        const auto& p = landmark_pairs_[i];
        uint32_t key = p.ComputeKey();

        // 4 bytes key (Big-endian)
        out_fingerprint.push_back(static_cast<uint8_t>((key >> 24) & 0xFF));
        out_fingerprint.push_back(static_cast<uint8_t>((key >> 16) & 0xFF));
        out_fingerprint.push_back(static_cast<uint8_t>((key >> 8) & 0xFF));
        out_fingerprint.push_back(static_cast<uint8_t>(key & 0xFF));

        // 4 bytes time (Big-endian)
        out_fingerprint.push_back(static_cast<uint8_t>((p.anchor_time >> 24) & 0xFF));
        out_fingerprint.push_back(static_cast<uint8_t>((p.anchor_time >> 16) & 0xFF));
        out_fingerprint.push_back(static_cast<uint8_t>((p.anchor_time >> 8) & 0xFF));
        out_fingerprint.push_back(static_cast<uint8_t>(p.anchor_time & 0xFF));
    }

    return static_cast<int>(AFPStatus::SUCCESS);
}

/**
 * @brief get_afp (3D matrix): Generates constellation map vector of vectors.
 * Matches AArch64 opcode 0x5888 (1580 bytes).
 * Layout: [time_index][peak_index] -> [freq_bin, magnitude_int, delta_time]
 */
void landmark_peak_afp_t::get_afp(std::vector<std::vector<std::vector<int>>>& out_constellation) {
    out_constellation.clear();
    if (detected_landmarks_.empty()) return;

    int max_time = 0;
    for (const auto& l : detected_landmarks_) {
        max_time = std::max(max_time, l.time_frame);
    }

    out_constellation.resize(max_time + 1);

    for (const auto& l : detected_landmarks_) {
        std::vector<int> peak_entry = {
            l.freq_bin,
            static_cast<int>(std::round(l.magnitude)),
            0
        };
        out_constellation[l.time_frame].push_back(std::move(peak_entry));
    }
}

} // namespace audio_fingerprint_sdk
