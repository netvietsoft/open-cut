// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_asr_engine.h
// Description: Central Speech Engine: ASR, Auto Caption, TTS Synthesizer & Directive Dispatcher
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <string>
#include <vector>
#include <memory>
#include <mutex>
#include <atomic>
#include "speechsdk_types.h"
#include "speechsdk_options.h"
#include "speechsdk_frontend.h"
#include "speechsdk_fingerprint.h"

namespace lab::speech::client {

/**
 * @brief Động cơ Âm thanh & Tiếng nói trung tâm (Central Speech Engine)
 * Khôi phục từ lab::speech::client::Engine
 */
class Engine {
public:
    static std::string GetVersion();

    Engine();
    virtual ~Engine();

    /**
     * @brief Khởi tạo động cơ với bảng tham số cấu hình
     * Khớp symbol _ZN3lab6speech6client6Engine4InitEPNS1_7OptionsE
     */
    bool Init(Options* options);

    /**
     * @brief Nạp luồng âm thanh PCM đa kênh
     * Khớp symbol _ZN3lab6speech6client6Engine4FeedEiPKsib
     */
    int32_t Feed(int32_t channel, const int16_t* pcm_data, int32_t sample_count, bool is_last);

    /**
     * @brief Nạp luồng âm thanh PCM đơn kênh
     * Khớp symbol _ZN3lab6speech6client6Engine4FeedEPKsi
     */
    int32_t Feed(const int16_t* pcm_data, int32_t sample_count);

    /**
     * @brief Xử lý trực tiếp một khối âm thanh hoàn chỉnh
     * Khớp symbol _ZN3lab6speech6client6Engine7ProcessEPKsib
     */
    int32_t Process(const int16_t* pcm_data, int32_t sample_count, bool is_last);

    /**
     * @brief Gửi chỉ lệnh điều khiển động cơ qua JSON
     * Khớp symbol _ZN3lab6speech6client6Engine13SendDirectiveEiRKNSt6__ndk112basic_stringIcNS2_11char_traitsIcEENS2_9allocatorIcEEEE
     */
    int32_t SendDirective(int32_t directive_id, const std::string& directive_json);

    /**
     * @brief Trích xuất kết quả nhận dạng mới nhất dưới dạng JSON
     * Dùng cho phụ đề tự động (Auto Caption) và tìm kiếm tiếng nói
     */
    std::string fetchResult(int32_t result_type = 0);

    /**
     * @brief Đặt lại trạng thái phiên
     */
    void Reset();

    /**
     * @brief Hủy động cơ và giải phóng tài nguyên
     */
    void Destroy();

    // Getters
    EngineWorkMode getWorkMode() const { return m_work_mode; }
    bool isRunning() const { return m_is_running.load(); }
    Options* getOptions() { return &m_options; }

    static bool runSelfTest();

private:
    void processAsrFrame(VadState vad_state, int64_t current_time_ms);
    std::string serializeAsrResultJson(const AsrResult& result) const;

    mutable std::mutex m_engine_mutex;
    std::atomic<bool> m_is_initialized{false};
    std::atomic<bool> m_is_running{false};

    Options m_options;
    EngineWorkMode m_work_mode{EngineWorkMode::ASR_ONLINE};

    std::unique_ptr<frontware::AcousticFrontend> m_frontend;
    std::unique_ptr<middleware::FingerPrintProcessor> m_fingerprint_proc;

    AsrResult m_current_asr_result;
    std::vector<AsrResult> m_history_results;
    int32_t m_session_token_counter{0};
    int64_t m_speech_start_time_ms{0};
};

} // namespace lab::speech::client
