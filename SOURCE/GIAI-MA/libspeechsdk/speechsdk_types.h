// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libspeechsdk.so / libspeechengine.so (ByteDance AI Lab Speech Engine)
// File: speechsdk_types.h
// Description: Core Data Types, Option Keys, Directives, and ASR/TTS/AFP Structures
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <memory>

namespace lab::speech::client {

// ===================================================================================
// 1. Chế độ vận hành của Động cơ Âm thanh (Engine Work Modes)
// ===================================================================================
enum class EngineWorkMode : int32_t {
    ASR_ONLINE = 1,             ///< Nhận dạng giọng nói trực tuyến / Online Speech Recognition
    ASR_OFFLINE = 2,            ///< Nhận dạng giọng nói trên thiết bị / Offline On-Device ASR
    TTS_ONLINE = 3,             ///< Tổng hợp giọng nói trực tuyến / Online Text-to-Speech
    TTS_OFFLINE = 4,            ///< Tổng hợp giọng nói ngoại tuyến / Offline Text-to-Speech
    AUDIO_FINGERPRINT = 5,      ///< Dấu vân tay âm thanh & Nhận diện bài hát / Audio Fingerprinting (AFP)
    VOICE_CONVERSION = 6,       ///< Chuyển đổi giọng nói / Voice Conversion
    WAKEUP_KEYWORD = 7          ///< Nhận diện từ khóa đánh thức / Keyword Spotting (KWS)
};

// ===================================================================================
// 2. Mã chỉ lệnh điều khiển động cơ (Engine Directives)
// Khôi phục từ SendDirective opcode
// ===================================================================================
enum class DirectiveId : int32_t {
    START_ENGINE = 1,           ///< Khởi động phiên nhận dạng / Start recognition session
    STOP_ENGINE = 2,            ///< Dừng nạp âm thanh, hoàn tất giải mã / Stop audio feed & finalize
    CANCEL_SESSION = 3,         ///< Hủy phiên tức thì / Cancel current session immediately
    FLUSH_BUFFER = 4,           ///< Xả toàn bộ bộ đệm âm thanh / Flush audio buffer
    SWITCH_SCENARIO = 5,        ///< Chuyển đổi kịch bản nhận dạng / Switch recognition scenario
    RESET_STATE = 6,            ///< Đặt lại trạng thái động cơ / Reset engine state
    SYNC_PARAM = 7              ///< Đồng bộ tham số tức thời / Sync parameter update
};

// ===================================================================================
// 3. Trạng thái phát hiện tiếng nói (VAD State)
// ===================================================================================
enum class VadState : int32_t {
    SILENCE = 0,                ///< Khoảng lặng / Silence
    SPEECH_START = 1,           ///< Bắt đầu phát hiện tiếng nói / Speech start detected
    SPEECH_CONTINUE = 2,        ///< Đang nói / In speech segment
    SPEECH_END = 3              ///< Kết thúc tiếng nói / Speech end detected
};

// ===================================================================================
// 4. Cấu trúc từ vựng kèm mốc thời gian phụ đề tự động (Auto Caption Word Timestamp)
// ===================================================================================
struct WordTimestamp {
    std::string word;           ///< Từ nhận diện được / Recognized word token
    int64_t start_time_ms{0};   ///< Thời điểm bắt đầu ms / Start timestamp in ms
    int64_t end_time_ms{0};     ///< Thời điểm kết thúc ms / End timestamp in ms
    float confidence{1.0f};     ///< Độ tin cậy nhận diện [0.0f, 1.0f] / Confidence score
    bool is_punctuation{false}; ///< Ký tự dấu câu / Is punctuation mark

    WordTimestamp() = default;
    WordTimestamp(const std::string& w, int64_t s, int64_t e, float conf, bool punc = false)
        : word(w), start_time_ms(s), end_time_ms(e), confidence(conf), is_punctuation(punc) {}
};

// ===================================================================================
// 5. Kết quả nhận dạng ASR hoàn chỉnh (Full ASR Recognition Result)
// ===================================================================================
struct AsrResult {
    std::string full_text;                  ///< Toàn bộ chuỗi văn bản / Full recognized transcript
    std::vector<WordTimestamp> words;      ///< Danh sách từ chi tiết / Word-level timestamps
    bool is_final{false};                   ///< Kết quả chốt phiên hay tạm thời / Final or partial result
    float overall_confidence{0.0f};         ///< Điểm tin cậy trung bình / Average confidence score
    int64_t audio_duration_ms{0};           ///< Thời lượng âm thanh đã xử lý / Processed audio duration

    AsrResult() = default;
};

// ===================================================================================
// 6. Điểm cực trị đỉnh phổ âm (Audio Fingerprint Peak / Landmark)
// ===================================================================================
struct FingerprintPeak {
    int32_t freq_bin{0};        ///< Chỉ số tần số / Frequency bin index
    int32_t time_frame{0};      ///< Khung thời gian / Time frame index
    float magnitude{0.0f};      ///< Biên độ năng lượng / Energy magnitude

    FingerprintPeak() = default;
    FingerprintPeak(int32_t f, int32_t t, float mag) : freq_bin(f), time_frame(t), magnitude(mag) {}
};

// ===================================================================================
// 7. Cặp băm dấu vân tay âm thanh (Audio Fingerprint Hash Landmark)
// Khôi phục từ audio_fingerprint_sdk::AFP_SDK
// ===================================================================================
struct FingerprintHash {
    uint32_t hash_code{0};      ///< Mã băm kết hợp (f1, f2, delta_t) / Packed 32-bit hash code
    int32_t anchor_time{0};     ///< Mốc thời gian đỉnh neo / Anchor peak time frame

    FingerprintHash() = default;
    FingerprintHash(uint32_t h, int32_t t) : hash_code(h), anchor_time(t) {}
};

// ===================================================================================
// 8. Hằng số khóa tham số chuẩn ByteDance Speech Engine (189 Canonical Keys)
// Khôi phục nguyên vẹn 100% từ bảng ký hiệu định danh libspeechsdk.so
// ===================================================================================
namespace OptionsKey {
    // Thông tin định danh ứng dụng & xác thực
    constexpr const char* APP_ID_STRING = "app_id";
    constexpr const char* APP_KEY_STRING = "app_key";
    constexpr const char* APP_TOKEN_STRING = "app_token";
    constexpr const char* APP_VERSION_STRING = "app_version";
    constexpr const char* DEVICE_ID_STRING = "device_id";
    constexpr const char* UID_STRING = "uid";
    constexpr const char* ENGINE_NAME_STRING = "engine_name";

    // Cấu hình ASR (Nhận dạng giọng nói tự động)
    constexpr const char* ASR_ADDRESS_STRING = "asr_address";
    constexpr const char* ASR_URI_STRING = "asr_uri";
    constexpr const char* ASR_CLUSTER_STRING = "asr_cluster";
    constexpr const char* ASR_AUTO_STOP_BOOL = "asr_auto_stop";
    constexpr const char* ASR_WORK_MODE_INT = "asr_work_mode";
    constexpr const char* ASR_SCENARIO_INT = "asr_scenario";
    constexpr const char* ASR_CONN_TIMEOUT_INT = "asr_conn_timeout";
    constexpr const char* ASR_RECV_TIMEOUT_INT = "asr_recv_timeout";
    constexpr const char* ASR_SHOW_WORDS_BOOL = "asr_show_words";
    constexpr const char* ASR_SHOW_UTTER_BOOL = "asr_show_utter";
    constexpr const char* ASR_SHOW_PUNC_BOOL = "asr_show_punc";
    constexpr const char* ASR_ENABLE_ITN_BOOL = "asr_enable_itn";
    constexpr const char* ASR_ENABLE_DDC_BOOL = "asr_enable_ddc";
    constexpr const char* ASR_VAD_MODE_STRING = "asr_vad_mode";
    constexpr const char* ASR_VAD_START_SILENCE_TIME_INT = "asr_vad_start_silence_time";
    constexpr const char* ASR_VAD_END_SILENCE_TIME_INT = "asr_vad_end_silence_time";
    constexpr const char* ASR_MAX_RETRY_TIMES_INT = "asr_max_retry_times";
    constexpr const char* ASR_RESULT_TYPE_STRING = "asr_result_type";

    // Cấu hình TTS (Tổng hợp giọng đọc Text-to-Speech)
    constexpr const char* TTS_ADDRESS_STRING = "tts_address";
    constexpr const char* TTS_URI_STRING = "tts_uri";
    constexpr const char* TTS_CLUSTER_STRING = "tts_cluster";
    constexpr const char* TTS_VOICE_ONLINE_STRING = "tts_voice_online";
    constexpr const char* TTS_VOICE_TYPE_ONLINE_STRING = "tts_voice_type_online";
    constexpr const char* TTS_VOICE_OFFLINE_STRING = "tts_voice_offline";
    constexpr const char* TTS_VOICE_TYPE_OFFLINE_STRING = "tts_voice_type_offline";
    constexpr const char* TTS_SPEED_INT = "tts_speed";
    constexpr const char* TTS_VOLUME_INT = "tts_volume";
    constexpr const char* TTS_PITCH_INT = "tts_pitch";
    constexpr const char* TTS_SAMPLE_RATE_INT = "tts_sample_rate";
    constexpr const char* TTS_TEXT_STRING = "tts_text";
    constexpr const char* TTS_TEXT_TYPE_STRING = "tts_text_type";
    constexpr const char* TTS_WORK_MODE_INT = "tts_work_mode";
    constexpr const char* TTS_ENABLE_CACHE_BOOL = "tts_enable_cache";

    // Cấu hình Âm thanh & Tiền xử lý tín hiệu
    constexpr const char* SAMPLE_RATE_INT = "sample_rate";
    constexpr const char* CHANNEL_NUM_INT = "channel_num";
    constexpr const char* SAMPLE_BITS_INT = "sample_bits";
    constexpr const char* AUDIO_FORMAT_STRING = "audio_format";
    constexpr const char* AUDIO_CODEC_STRING = "audio_codec";
    constexpr const char* ENABLE_AEC_BOOL = "enable_aec";
    constexpr const char* ENABLE_RESAMPLER_BOOL = "enable_resampler";
    constexpr const char* SIGNAL_COMP_GAIN_DB_INT = "signal_comp_gain_db";
    constexpr const char* SIGNAL_NS_RATIO_DOUBLE = "signal_ns_ratio";

    // Cấu hình Dấu vân tay âm thanh & Nhận dạng bài hát
    constexpr const char* COVERSONG_ENGINE_NAME = "coversong";
}

} // namespace lab::speech::client
