/**
 * @file ttmplayer_interface.cpp
 * @brief Cleanroom C++17 Implementation of TTMPlayerEngine & 7-Stage Self-Test
 *        Hiện thực C++17 Tái cấu trúc Sạch cho TTMPlayerEngine & Bộ Tự Kiểm thử 7 Giai đoạn
 */

#include "ttmplayer_interface.h"

#include <cmath>
#include <cstring>

namespace nextai {
namespace opencut {
namespace ttmplayer {

namespace {

class TestStrategyCenter final : public com::ss::ttm::player::AVStrategyCenterProtocol {
public:
    int32_t last_event_id = 0;
    int64_t last_arg1 = 0;
    int64_t last_arg2 = 0;

    int32_t onEvent(int32_t event_id, int64_t arg1, int64_t arg2) override {
        last_event_id = event_id;
        last_arg1 = arg1;
        last_arg2 = arg2;
        return event_id + static_cast<int32_t>(arg1 & 0xFF);
    }

    std::string packStrategyLogInfo(int64_t handle) override {
        return "{\"custom_strategy\":1,\"handle\":" + std::to_string(handle) + "}";
    }
};

}  // namespace

TTMPlayerSelfTestReport TTMPlayerEngine::runSelfTest() noexcept {
    TTMPlayerSelfTestReport report{};
    report.total_stages = 7;
    report.passed_stages = 0;

    // Stage 1: VString (24-byte SSO/Heap), Value (32-byte variant), and Parcel (32-byte vector)
    const bool s1_vstr = (ttmplayer_verify_vstring_sso_and_heap(
                              "short_ttm",
                              "long_ttmplayer_string_exceeding_22_characters_limit") == 1);
    const bool s1_val = (ttmplayer_verify_value_polymorphism(
                             -42, 0x1122334455667788LL, 3.5f, 2.718281828, "parcel_str") == 1);
    const bool s1_parcel = (ttmplayer_verify_parcel_container(6) == 1);
    report.stage1_vstring_value_parcel_ok = s1_vstr && s1_val && s1_parcel;
    if (report.stage1_vstring_value_parcel_ok) ++report.passed_stages;

    // Stage 2: AVStrategyUtils::convertTTCodecIDToFF (0x1660cc -> 0x261f20)
    using com::ss::ttm::player::AVStrategyUtils;
    const bool s2_h264 = (AVStrategyUtils::convertTTCodecIDToFF(0, -1) == 28);
    const bool s2_hevc = (AVStrategyUtils::convertTTCodecIDToFF(1, -1) == 174);
    const bool s2_aac  = (AVStrategyUtils::convertTTCodecIDToFF(2, -1) == 86018);
    const bool s2_vvc  = (AVStrategyUtils::convertTTCodecIDToFF(33, -1) == 266240);
    const bool s2_av1  = (AVStrategyUtils::convertTTCodecIDToFF(49, -1) == 197);
    const bool s2_hole = (AVStrategyUtils::convertTTCodecIDToFF(23, 777) == 777) &&
                         (AVStrategyUtils::convertTTCodecIDToFF(41, 777) == 777) &&
                         (AVStrategyUtils::convertTTCodecIDToFF(50, 777) == 777);
    report.stage2_codec_id_bitmask_table_ok =
        s2_h264 && s2_hevc && s2_aac && s2_vvc && s2_av1 && s2_hole;
    if (report.stage2_codec_id_bitmask_table_ok) ++report.passed_stages;

    // Stage 3: AVStrategyUtils::setPlayerGlobalConfigIntValue (0x1660d0) & get (0x166124)
    const bool s3_set519 = (AVStrategyUtils::setPlayerGlobalConfigIntValue(0x519, 1024) == 0);
    const bool s3_set518 = (AVStrategyUtils::setPlayerGlobalConfigIntValue(0x518, 2048) == 0);
    const bool s3_bad    = (AVStrategyUtils::setPlayerGlobalConfigIntValue(0x517, 99) == -1);
    const bool s3_get519 = (AVStrategyUtils::getPlayerGlobalConfigIntValue(0x519, -1) == 1024);
    const bool s3_get518 = (AVStrategyUtils::getPlayerGlobalConfigIntValue(0x518, -1) == 2048);
    const bool s3_getbad = (AVStrategyUtils::getPlayerGlobalConfigIntValue(0x517, 77) == 77);
    report.stage3_global_config_mapping_ok =
        s3_set519 && s3_set518 && s3_bad && s3_get519 && s3_get518 && s3_getbad;
    if (report.stage3_global_config_mapping_ok) ++report.passed_stages;

    // Stage 4: mdlInfoCallback (0x0c4af8), AVDropFrameOperator (0x16cde8), AVLoadControlOperator (0x16ce04)
    AVStrategyUtils::resetStrategyCenterForTesting();
    TestStrategyCenter custom_center;
    AVStrategyUtils::registerStrategyCenter(&custom_center);
    const int64_t r_ev4 = mdlInfoCallback(reinterpret_cast<void*>(0x10), 4, 5);
    const int64_t r_ev3 = mdlInfoCallback(reinterpret_cast<void*>(0x20), 3, 99);
    const int64_t r_ev0 = mdlInfoCallback(reinterpret_cast<void*>(0x30), 0, 123);
    com::ss::ttm::player::AVDropFrameOperator drop_op;
    com::ss::ttm::player::AVLoadControlOperator load_op;
    const bool s4_ops = (drop_op.refcount_ == 0) && (load_op.refcount_ == 1) &&
                        drop_op.shouldDropVideoFrame(100000, 160000, 1, false) &&
                        !drop_op.shouldDropVideoFrame(100000, 160000, 1, true) &&
                        load_op.shouldStartPlayback(3000, 1.0f, false);
    report.stage4_mdl_callback_and_strategy_ok =
        (r_ev4 == (0xFA4 + 5)) && (r_ev3 == (0xFA2 + 0x20)) && (r_ev0 == (0xFA1 + 0x30)) && s4_ops;
    AVStrategyUtils::resetStrategyCenterForTesting();
    if (report.stage4_mdl_callback_and_strategy_ok) ++report.passed_stages;

    // Stage 5: AJMediaCodecNative 64-slot lock-free ring buffer & YUV420 format sizing
    AJMediaCodecNative codec;
    int64_t codec_h = reinterpret_cast<int64_t>(&codec);
    ttmplayer_ajmediacodec_on_format_changed(
        nullptr, nullptr, codec_h, 0, 1920, 1080, 21, 1920, 1088, 0, 0, 1919, 1079);
    ttmplayer_ajmediacodec_on_filled_buffer(nullptr, nullptr, codec_h, 3, 0, 65536, 33333LL, 1);
    AJMediaCodecBufferSlot out_slot{};
    const int32_t deq = ttmplayer_ajmediacodec_dequeue_filled_buffer(&codec, &out_slot);
    report.stage5_ajmediacodec_ring_buffer_ok =
        (codec.yuv420_frame_bytes == (1088 * 1920 * 3) / 2) && (deq == 1) &&
        (out_slot.buffer_index == 3) && (out_slot.size == 65536) && (out_slot.pts_us == 33333LL);
    if (report.stage5_ajmediacodec_ring_buffer_ok) ++report.passed_stages;

    // Stage 6: register_FFmpegAudioDecoders (0x1e7fa4), unregister (0x1e8b24), SAMICore DSP
    const int32_t reg_n = register_FFmpegAudioDecoders(nullptr);
    float in_samples[4] = {0.25f, -0.25f, 0.5f, -0.5f};
    float out_samples[4] = {0.0f};
    const int32_t dsp_n = ttmplayer_sami_audio_process_f32(in_samples, out_samples, 2, 2, 6.0206f);
    unregister_FFmpegAudioDecoders();
    const int32_t unreg_n = ttmplayer_get_registered_audio_decoder_count();
    report.stage6_ffmpeg_audio_decoders_sami_ok =
        (reg_n == 9) && (dsp_n == 4) && (std::fabs(out_samples[0] - 0.5f) < 0.01f) && (unreg_n == 0);
    if (report.stage6_ffmpeg_audio_decoders_sami_ok) ++report.passed_stages;

    // Stage 7: JNI_OnLoad (0x197174) & TTPlayer 62-method lifecycle state machine
    size_t jni_count = 0;
    const auto* jni_table = ttmplayer_get_ttplayer_jni_table(&jni_count);
    const int32_t onload_ver = JNI_OnLoad(reinterpret_cast<void*>(0xCAFEBABEULL), nullptr);
    int64_t player_h = ttmplayer_native_create(nullptr, 1, 0, 0, "NextAI_OpenCut");
    ttmplayer_native_set_data_source(player_h, "https://cdn.nextai.tech/video/4k_hdr.mp4");
    const int32_t prep_rc = ttmplayer_native_prepare(player_h);
    const int32_t start_rc = ttmplayer_native_start(player_h);
    const int32_t playing = ttmplayer_native_is_playing(player_h);
    const int32_t seek_rc = ttmplayer_native_seek2(player_h, 12500, 2);
    const int32_t cur_pos = ttmplayer_native_get_current_position(player_h);
    ttmplayer_native_release(player_h);
    JNI_OnUnload(reinterpret_cast<void*>(0xCAFEBABEULL), nullptr);

    report.stage7_ttplayer_62_jni_lifecycle_ok =
        (jni_table != nullptr) && (jni_count == 62) && (onload_ver == 0x00010004) &&
        (prep_rc == 0) && (start_rc == 0) && (playing == 1) && (seek_rc == 0) && (cur_pos == 12500);
    if (report.stage7_ttplayer_62_jni_lifecycle_ok) ++report.passed_stages;

    return report;
}

}  // namespace ttmplayer
}  // namespace opencut
}  // namespace nextai

extern "C" {

int32_t ttmplayer_run_self_test() {
    auto rep = nextai::opencut::ttmplayer::TTMPlayerEngine::runSelfTest();
    return (rep.passed_stages == rep.total_stages) ? 1 : 0;
}

}  // extern "C"
