/**
 * @file ttmplayer_interface.h
 * @brief Master Facade & 7-Stage Deterministic Self-Test for libttmplayer.so
 *        Giao diện Điều phối Tổng thể & Tự Kiểm thử 7 Giai đoạn cho libttmplayer.so
 */

#ifndef NEXTAI_OPENCUT_TTMPLAYER_INTERFACE_H_
#define NEXTAI_OPENCUT_TTMPLAYER_INTERFACE_H_

#include "ttmplayer_ajmediacodec_audio.h"
#include "ttmplayer_player_jni.h"
#include "ttmplayer_strategy_operators.h"
#include "ttmplayer_types.h"
#include "ttmplayer_value_parcel.h"

namespace nextai {
namespace opencut {
namespace ttmplayer {

struct TTMPlayerSelfTestReport {
    int32_t total_stages;
    int32_t passed_stages;
    bool stage1_vstring_value_parcel_ok;
    bool stage2_codec_id_bitmask_table_ok;
    bool stage3_global_config_mapping_ok;
    bool stage4_mdl_callback_and_strategy_ok;
    bool stage5_ajmediacodec_ring_buffer_ok;
    bool stage6_ffmpeg_audio_decoders_sami_ok;
    bool stage7_ttplayer_62_jni_lifecycle_ok;
};

class TTMPlayerEngine {
public:
    TTMPlayerEngine() noexcept = default;
    ~TTMPlayerEngine() noexcept = default;

    static TTMPlayerSelfTestReport runSelfTest() noexcept;
};

}  // namespace ttmplayer
}  // namespace opencut
}  // namespace nextai

extern "C" {

int32_t ttmplayer_run_self_test();

}  // extern "C"

#endif  // NEXTAI_OPENCUT_TTMPLAYER_INTERFACE_H_
