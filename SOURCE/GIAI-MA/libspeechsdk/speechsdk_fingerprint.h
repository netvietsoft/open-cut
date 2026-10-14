// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_fingerprint.h
// Description: Audio Fingerprinting (AFP) & Song Identification Engine
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <vector>
#include <map>
#include <memory>
#include <mutex>
#include <cstdint>
#include "speechsdk_types.h"
#include "speechsdk_options.h"

namespace audio_fingerprint_sdk {

/**
 * @brief SDK Nhận diện dấu vân tay âm thanh và bài hát
 * Khôi phục từ audio_fingerprint_sdk::AFP_SDK::Reset()
 */
class AFP_SDK {
public:
    AFP_SDK();
    ~AFP_SDK() = default;

    /**
     * @brief Đặt lại toàn bộ trạng thái bộ đệm dấu vân tay âm thanh
     * Khớp symbol _ZN21audio_fingerprint_sdk7AFP_SDK5ResetEv
     */
    void Reset();

    /**
     * @brief Trích xuất các điểm cực đại đỉnh phổ (Spectrogram Peak Picking)
     */
    std::vector<lab::speech::client::FingerprintPeak> extractPeaks(
        const std::vector<std::vector<float>>& spectrogram,
        float threshold = 0.5f) const;

    /**
     * @brief Đóng gói mã băm vân tay âm thanh từ cặp đỉnh neo và đỉnh đích
     * Constellation Map 32-bit Hash Packaging: (f1: 9-bit, f2: 9-bit, delta_t: 14-bit)
     */
    static uint32_t packHash(int32_t f1, int32_t f2, int32_t delta_t);

    /**
     * @brief Giải nén mã băm 32-bit thành f1, f2 và delta_t
     */
    static void unpackHash(uint32_t hash_code, int32_t& out_f1, int32_t& out_f2, int32_t& out_delta_t);

    /**
     * @brief Tạo danh sách các cặp băm từ danh sách đỉnh phổ
     */
    std::vector<lab::speech::client::FingerprintHash> generateHashes(
        const std::vector<lab::speech::client::FingerprintPeak>& peaks,
        int32_t target_zone_dt_min = 2,
        int32_t target_zone_dt_max = 64,
        int32_t max_pairs_per_anchor = 5) const;

    /**
     * @brief So khớp danh sách mã băm với kho tham chiếu và tính điểm tương đồng
     */
    float matchFingerprints(
        const std::vector<lab::speech::client::FingerprintHash>& query_hashes,
        const std::vector<lab::speech::client::FingerprintHash>& db_hashes,
        int32_t& out_offset_frames) const;

    static bool runSelfTest();

private:
    std::mutex m_mutex;
    std::vector<lab::speech::client::FingerprintHash> m_hash_buffer;
};

} // namespace audio_fingerprint_sdk

namespace lab::speech::client::middleware {

/**
 * @brief Bộ xử lý lát cắt dấu vân tay âm thanh tích hợp trong Speech Client Middleware
 * Khôi phục từ lab::speech::client::middleware::FingerPrintProcessor
 */
class FingerPrintProcessor {
public:
    FingerPrintProcessor();
    ~FingerPrintProcessor() = default;

    bool Init(Options* options);
    void Reset();

    /**
     * @brief Nạp và xử lý các mẫu âm thanh PCM
     */
    int32_t Process(const int16_t* pcm_samples, size_t sample_count);

    /**
     * @brief Lấy kết quả chuỗi JSON băm dấu vân tay của lát cắt hiện tại
     * Khớp symbol lab::speech::client::middleware::FingerPrintProcessor::FetchFingerPrintSliceResult()
     */
    std::string FetchFingerPrintSliceResult();

    size_t getAccumulatedHashCount() const;

    static bool runSelfTest();

private:
    std::mutex m_mutex;
    audio_fingerprint_sdk::AFP_SDK m_afp_sdk;
    std::vector<FingerprintHash> m_current_slice_hashes;
    int32_t m_frame_index{0};
};

} // namespace lab::speech::client::middleware
