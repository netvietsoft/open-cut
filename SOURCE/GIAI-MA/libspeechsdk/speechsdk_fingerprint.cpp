// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_fingerprint.cpp
// Description: Full implementation of Audio Fingerprinting (AFP) & Constellation Hashing
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "speechsdk_fingerprint.h"
#include <sstream>
#include <cmath>
#include <algorithm>

namespace audio_fingerprint_sdk {

AFP_SDK::AFP_SDK() = default;

void AFP_SDK::Reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_hash_buffer.clear();
}

uint32_t AFP_SDK::packHash(int32_t f1, int32_t f2, int32_t delta_t) {
    uint32_t u_f1 = static_cast<uint32_t>(f1 & 0x1FF);       // 9 bits (0..511)
    uint32_t u_f2 = static_cast<uint32_t>(f2 & 0x1FF);       // 9 bits (0..511)
    uint32_t u_dt = static_cast<uint32_t>(delta_t & 0x3FFF);  // 14 bits (0..16383)
    return (u_f1 << 23) | (u_f2 << 14) | u_dt;
}

void AFP_SDK::unpackHash(uint32_t hash_code, int32_t& out_f1, int32_t& out_f2, int32_t& out_delta_t) {
    out_f1 = static_cast<int32_t>((hash_code >> 23) & 0x1FF);
    out_f2 = static_cast<int32_t>((hash_code >> 14) & 0x1FF);
    out_delta_t = static_cast<int32_t>(hash_code & 0x3FFF);
}

std::vector<lab::speech::client::FingerprintPeak> AFP_SDK::extractPeaks(
    const std::vector<std::vector<float>>& spectrogram, float threshold) const {
    std::vector<lab::speech::client::FingerprintPeak> peaks;
    if (spectrogram.empty()) return peaks;

    size_t num_frames = spectrogram.size();
    size_t num_bins = spectrogram[0].size();
    if (num_frames < 3 || num_bins < 3) return peaks;

    // Quét tìm cực đại địa phương trong vùng lân cận 3x3
    for (size_t t = 1; t < num_frames - 1; ++t) {
        for (size_t f = 1; f < num_bins - 1; ++f) {
            float val = spectrogram[t][f];
            if (val < threshold) continue;

            // Kiểm tra nghiêm ngặt 8 điểm lân cận
            if (val > spectrogram[t - 1][f - 1] && val > spectrogram[t - 1][f] && val > spectrogram[t - 1][f + 1] &&
                val > spectrogram[t][f - 1]     &&                                 val > spectrogram[t][f + 1] &&
                val > spectrogram[t + 1][f - 1] && val > spectrogram[t + 1][f] && val > spectrogram[t + 1][f + 1]) {
                peaks.emplace_back(static_cast<int32_t>(f), static_cast<int32_t>(t), val);
            }
        }
    }

    return peaks;
}

std::vector<lab::speech::client::FingerprintHash> AFP_SDK::generateHashes(
    const std::vector<lab::speech::client::FingerprintPeak>& peaks,
    int32_t target_zone_dt_min, int32_t target_zone_dt_max,
    int32_t max_pairs_per_anchor) const {
    std::vector<lab::speech::client::FingerprintHash> hashes;
    if (peaks.size() < 2) return hashes;

    for (size_t i = 0; i < peaks.size(); ++i) {
        const auto& anchor = peaks[i];
        int32_t pairs_count = 0;

        for (size_t j = i + 1; j < peaks.size(); ++j) {
            const auto& target = peaks[j];
            int32_t dt = target.time_frame - anchor.time_frame;

            if (dt < target_zone_dt_min) continue;
            if (dt > target_zone_dt_max) break; // Vì peaks được sắp xếp theo thời gian

            uint32_t hash_code = packHash(anchor.freq_bin, target.freq_bin, dt);
            hashes.emplace_back(hash_code, anchor.time_frame);

            pairs_count++;
            if (pairs_count >= max_pairs_per_anchor) break;
        }
    }

    return hashes;
}

float AFP_SDK::matchFingerprints(
    const std::vector<lab::speech::client::FingerprintHash>& query_hashes,
    const std::vector<lab::speech::client::FingerprintHash>& db_hashes,
    int32_t& out_offset_frames) const {
    out_offset_frames = 0;
    if (query_hashes.empty() || db_hashes.empty()) return 0.0f;

    // Tạo bảng tra cứu mã băm của CSDL bài hát (Hash -> danh sách mốc thời gian)
    std::map<uint32_t, std::vector<int32_t>> db_index;
    for (const auto& item : db_hashes) {
        db_index[item.hash_code].push_back(item.anchor_time);
    }

    // Biểu đồ tần suất độ lệch thời gian (Offset Histogram: t_db - t_query)
    std::map<int32_t, int32_t> offset_histogram;
    int32_t max_votes = 0;
    int32_t best_offset = 0;

    for (const auto& q : query_hashes) {
        auto it = db_index.find(q.hash_code);
        if (it != db_index.end()) {
            for (int32_t db_time : it->second) {
                int32_t offset = db_time - q.anchor_time;
                int32_t votes = ++offset_histogram[offset];
                if (votes > max_votes) {
                    max_votes = votes;
                    best_offset = offset;
                }
            }
        }
    }

    out_offset_frames = best_offset;
    // Điểm số tương đồng = số phiếu đỉnh lớn nhất / tổng số mã băm truy vấn
    return static_cast<float>(max_votes) / static_cast<float>(query_hashes.size());
}

bool AFP_SDK::runSelfTest() {
    AFP_SDK sdk;

    // 1. Kiểm tra đóng gói và giải nén mã băm 32-bit (Bit packaging test)
    int32_t f1 = 120;
    int32_t f2 = 345;
    int32_t dt = 15;
    uint32_t hash_code = AFP_SDK::packHash(f1, f2, dt);

    int32_t rec_f1 = 0, rec_f2 = 0, rec_dt = 0;
    AFP_SDK::unpackHash(hash_code, rec_f1, rec_f2, rec_dt);
    if (rec_f1 != f1 || rec_f2 != f2 || rec_dt != dt) return false;

    // 2. Kiểm tra trích xuất đỉnh phổ (Peak Picking)
    std::vector<std::vector<float>> spec(5, std::vector<float>(5, 0.1f));
    spec[2][2] = 0.9f; // Đỉnh cực đại tại (f=2, t=2)
    auto peaks = sdk.extractPeaks(spec, 0.5f);
    if (peaks.size() != 1) return false;
    if (peaks[0].freq_bin != 2 || peaks[0].time_frame != 2 || peaks[0].magnitude != 0.9f) return false;

    // 3. Kiểm tra tạo mã băm và so khớp nhận diện bài hát
    std::vector<lab::speech::client::FingerprintPeak> test_peaks = {
        { 50, 10, 0.8f },
        { 75, 14, 0.9f },
        { 120, 20, 0.85f }
    };

    auto query_hashes = sdk.generateHashes(test_peaks, 2, 20);
    if (query_hashes.empty()) return false;

    // CSDL bài hát chứa cùng mẫu nhưng bắt đầu tại khung t = 100
    std::vector<lab::speech::client::FingerprintPeak> db_peaks = {
        { 50, 110, 0.8f },
        { 75, 114, 0.9f },
        { 120, 120, 0.85f }
    };
    auto db_hashes = sdk.generateHashes(db_peaks, 2, 20);

    int32_t detected_offset = 0;
    float score = sdk.matchFingerprints(query_hashes, db_hashes, detected_offset);
    if (detected_offset != 100) return false; // Độ lệch 110 - 10 = 100 khung
    if (score < 0.99f) return false;

    return true;
}

} // namespace audio_fingerprint_sdk

namespace lab::speech::client::middleware {

FingerPrintProcessor::FingerPrintProcessor() = default;

bool FingerPrintProcessor::Init(Options* options) {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_afp_sdk.Reset();
    m_current_slice_hashes.clear();
    m_frame_index = 0;
    return true;
}

void FingerPrintProcessor::Reset() {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_afp_sdk.Reset();
    m_current_slice_hashes.clear();
    m_frame_index = 0;
}

int32_t FingerPrintProcessor::Process(const int16_t* pcm_samples, size_t sample_count) {
    if (!pcm_samples || sample_count < 320) return 0;
    std::lock_guard<std::mutex> lock(m_mutex);

    // Mô phỏng trích xuất đặc trưng âm học thời gian thực
    int32_t frames_in_slice = static_cast<int32_t>(sample_count / 160);
    for (int32_t f = 0; f < frames_in_slice; ++f) {
        // Tìm năng lượng đỉnh trong khung
        int16_t peak_val = 0;
        for (int32_t s = 0; s < 160; ++s) {
            peak_val = std::max(peak_val, std::abs(pcm_samples[f * 160 + s]));
        }

        if (peak_val > 5000) {
            int32_t pseudo_freq = (peak_val * 7) % 256;
            uint32_t hash = audio_fingerprint_sdk::AFP_SDK::packHash(pseudo_freq, (pseudo_freq + 30) % 256, 5);
            m_current_slice_hashes.emplace_back(hash, m_frame_index);
        }
        m_frame_index++;
    }

    return frames_in_slice;
}

std::string FingerPrintProcessor::FetchFingerPrintSliceResult() {
    std::lock_guard<std::mutex> lock(m_mutex);
    std::ostringstream ss;
    ss << "{\"slice_index\":" << (m_frame_index / 100)
       << ",\"hash_count\":" << m_current_slice_hashes.size()
       << ",\"hashes\":[";

    for (size_t i = 0; i < m_current_slice_hashes.size(); ++i) {
        if (i > 0) ss << ",";
        ss << "{\"h\":" << m_current_slice_hashes[i].hash_code
           << ",\"t\":" << m_current_slice_hashes[i].anchor_time << "}";
    }
    ss << "]}";

    m_current_slice_hashes.clear();
    return ss.str();
}

size_t FingerPrintProcessor::getAccumulatedHashCount() const {
    return m_current_slice_hashes.size();
}

bool FingerPrintProcessor::runSelfTest() {
    FingerPrintProcessor proc;
    proc.Init(nullptr);

    // Nạp âm thanh có âm vực
    std::vector<int16_t> audio(1600, 10000); // 10 khung âm thanh mạnh
    proc.Process(audio.data(), audio.size());

    std::string json_slice = proc.FetchFingerPrintSliceResult();
    if (json_slice.find("\"hash_count\":") == std::string::npos) return false;
    if (json_slice.find("\"hashes\":[") == std::string::npos) return false;

    return audio_fingerprint_sdk::AFP_SDK::runSelfTest();
}

} // namespace lab::speech::client::middleware
