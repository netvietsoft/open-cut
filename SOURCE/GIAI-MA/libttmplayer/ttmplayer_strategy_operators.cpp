/**
 * @file ttmplayer_strategy_operators.cpp
 * @brief Cleanroom C++17 Implementation of AVStrategyUtils, Operators & MDL Callback
 *        Hiện thực C++17 Tái cấu trúc Sạch cho AVStrategyUtils, Các Toán tử & MDL Callback
 */

#include "ttmplayer_strategy_operators.h"

#include <atomic>
#include <cstdio>
#include <cstring>
#include <mutex>

namespace com {
namespace ss {
namespace ttm {
namespace player {

namespace {

// Matches BSS atomic pointer at 0x371918 (`adrp x8, #0x371000; add x8, x8, #0x918`)
std::atomic<AVStrategyCenterProtocol*> g_strategy_center{nullptr};

// Global configuration table backing `0x23dd3c` / `0x23e19c` / `0x23ddbc`
std::mutex g_global_config_mutex;
int32_t g_global_config_slots[128] = {0};
bool g_global_config_initialized[128] = {false};

// Exact 50-entry lookup table extracted from `.rodata` @ 0x2cf040 (bytes 0x2cf040..0x2cf107)
// Bảng tra cứu 50 phần tử trích xuất chính xác từ `.rodata` tại 0x2cf040
constexpr int32_t kTTCodecIdToFFCodecIdTable[50] = {
    28,      //  0 (0x00): H.264 / AVC      -> AV_CODEC_ID_H264 (28)
    174,     //  1 (0x01): ByteVC1 / HEVC   -> AV_CODEC_ID_HEVC (174)
    86018,   //  2 (0x02): AAC              -> AV_CODEC_ID_AAC (0x15002)
    86017,   //  3 (0x03): MP3              -> AV_CODEC_ID_MP3 (0x15001)
    65536,   //  4 (0x04): PCM_S16LE        -> AV_CODEC_ID_PCM_S16LE (0x10000)
    65548,   //  5 (0x05): PCM_U8           -> AV_CODEC_ID_PCM_U8 (0x1000C)
    65557,   //  6 (0x06): PCM_F32LE        -> AV_CODEC_ID_PCM_F32LE (0x10015)
    5,       //  7 (0x07): H.263            -> AV_CODEC_ID_H263 (5)
    1,       //  8 (0x08): MPEG1VIDEO       -> AV_CODEC_ID_MPEG1VIDEO (1)
    2,       //  9 (0x09): MPEG2VIDEO       -> AV_CODEC_ID_MPEG2VIDEO (2)
    13,      // 10 (0x0a): MPEG4            -> AV_CODEC_ID_MPEG4 (13)
    140,     // 11 (0x0b): VP8              -> AV_CODEC_ID_VP8 (140)
    168,     // 12 (0x0c): VP9              -> AV_CODEC_ID_VP9 (168)
    22,      // 13 (0x0d): FLV1             -> AV_CODEC_ID_FLV1 (22)
    86016,   // 14 (0x0e): MP2              -> AV_CODEC_ID_MP2 (0x15000)
    73728,   // 15 (0x0f): AMR_NB           -> AV_CODEC_ID_AMR_NB (0x12000)
    86077,   // 16 (0x10): OPUS             -> AV_CODEC_ID_OPUS (0x1503D)
    86036,   // 17 (0x11): ALAC             -> AV_CODEC_ID_ALAC (0x15014)
    69,      // 18 (0x12): RV30             -> AV_CODEC_ID_RV30 (69)
    70,      // 19 (0x13): RV40             -> AV_CODEC_ID_RV40 (70)
    86019,   // 20 (0x14): AC3              -> AV_CODEC_ID_AC3 (0x15003)
    86057,   // 21 (0x15): EAC3             -> AV_CODEC_ID_EAC3 (0x15029)
    86020,   // 22 (0x16): DTS              -> AV_CODEC_ID_DTS (0x15004)
    28,      // 23 (0x17): unmapped (mask bit 23 = 0)
    8,       // 24 (0x18): MJPEG            -> AV_CODEC_ID_MJPEG (8)
    86021,   // 25 (0x19): VORBIS           -> AV_CODEC_ID_VORBIS (0x15005)
    86049,   // 26 (0x1a): COOK             -> AV_CODEC_ID_COOK (0x15021)
    86028,   // 27 (0x1b): FLAC             -> AV_CODEC_ID_FLAC (0x1500C)
    86023,   // 28 (0x1c): WMAV1            -> AV_CODEC_ID_WMAV1 (0x15007)
    86024,   // 29 (0x1d): WMAV2            -> AV_CODEC_ID_WMAV2 (0x15008)
    86054,   // 30 (0x1e): WMAPRO           -> AV_CODEC_ID_WMAPRO (0x15026)
    86053,   // 31 (0x1f): WMALOSSLESS      -> AV_CODEC_ID_WMALOSSLESS (0x15025)
    86055,   // 32 (0x20): ATRAC3P          -> AV_CODEC_ID_ATRAC3P (0x15027)
    266240,  // 33 (0x21): ByteVC2 / VVC    -> AV_CODEC_ID_BYTEVC2 (0x41000)
    69651,   // 34 (0x22): ADPCM_IMA_WAV    -> AV_CODEC_ID_ADPCM_IMA_WAV (0x11013)
    73729,   // 35 (0x23): AMR_WB           -> AV_CODEC_ID_AMR_WB (0x12001)
    86029,   // 36 (0x24): MP3ADU           -> AV_CODEC_ID_MP3ADU (0x1500D)
    86030,   // 37 (0x25): MP3ON4           -> AV_CODEC_ID_MP3ON4 (0x1500E)
    92,      // 38 (0x26): WEBP             -> AV_CODEC_ID_WEBP (92)
    93,      // 39 (0x27): H264_MVC         -> (93)
    65543,   // 40 (0x28): PCM_ALAW         -> AV_CODEC_ID_PCM_ALAW (0x10007)
    28,      // 41 (0x29): unmapped (mask bit 41 = 0)
    28,      // 42 (0x2a): unmapped (mask bit 42 = 0)
    28,      // 43 (0x2b): unmapped (mask bit 43 = 0)
    86059,   // 44 (0x2c): AAC_LATM         -> AV_CODEC_ID_AAC_LATM (0x1502B)
    86032,   // 45 (0x2d): SHORTEN          -> AV_CODEC_ID_SHORTEN (0x15010)
    65544,   // 46 (0x2e): PCM_MULAW        -> AV_CODEC_ID_PCM_MULAW (0x10008)
    67584,   // 47 (0x2f): PCM_DVD          -> (0x10800)
    65559,   // 48 (0x30): PCM_S24LE        -> (0x10017)
    197      // 49 (0x31): AV1              -> AV_CODEC_ID_AV1 (197)
};

// Exact 64-bit validity bitmask synthesized at 0x261f28..0x261f30:
//   mov  x8, #-0x800001         -> 0xffffffffff7fffff
//   movk x8, #0xf1ff, lsl #32   -> 0xfffff1ffff7fffff
//   movk x8, #3, lsl #48        -> 0x0003f1ffff7fffff
constexpr uint64_t kTTCodecValidBitmask = 0x0003F1FFFF7FFFFFULL;

// Helper matching opcode sequence at 0x1660dc..0x1660f0:
//   cmp   w0, #0x519
//   mov   w8, #0x3a
//   csinv w8, w8, wzr, eq       ; w8 = (key == 0x519) ? 0x3a : -1
//   cmp   w0, #0x518
//   mov   w9, #0x3d
//   csel  w20, w9, w8, eq       ; w20 = (key == 0x518) ? 0x3d : w8
inline int32_t MapPlayerGlobalConfigKey(int32_t key) noexcept {
    int32_t w8 = (key == 0x519) ? 0x3a : ~0;
    int32_t w20 = (key == 0x518) ? 0x3d : w8;
    return w20;
}

}  // namespace

// ============================================================================
// 1. AVStrategyUtils Implementation (0x1660b0 .. 0x166174, 0x261f20)
// ============================================================================

// Matches 0x1660b0:
//   adrp x8, #0x371000; add x8, x8, #0x918
//   ldar x9, [x8]; cbz x9, #store; ret; store: stlr x0, [x8]; ret
// Note: Only stores `center` if current pointer at 0x371918 is nullptr!
void AVStrategyUtils::registerStrategyCenter(AVStrategyCenterProtocol* center) noexcept {
    AVStrategyCenterProtocol* current = g_strategy_center.load(std::memory_order_acquire);
    if (current == nullptr) {
        g_strategy_center.store(center, std::memory_order_release);
    }
}

AVStrategyCenterProtocol* AVStrategyUtils::getRegisteredStrategyCenter() noexcept {
    return g_strategy_center.load(std::memory_order_acquire);
}

void AVStrategyUtils::resetStrategyCenterForTesting() noexcept {
    g_strategy_center.store(nullptr, std::memory_order_release);
}

// Matches 0x1660cc -> 0x261f20
int32_t AVStrategyUtils::convertTTCodecIDToFF(int32_t tt_codec_id,
                                              int32_t default_ff_codec_id) noexcept {
    if (static_cast<uint32_t>(tt_codec_id) > 0x31U) {
        return default_ff_codec_id;
    }
    if (((kTTCodecValidBitmask >> static_cast<uint32_t>(tt_codec_id)) & 1ULL) != 0ULL) {
        return kTTCodecIdToFFCodecIdTable[tt_codec_id];
    }
    return default_ff_codec_id;
}

// Matches 0x1660d0 (84 bytes)
int32_t AVStrategyUtils::setPlayerGlobalConfigIntValue(int32_t key, int32_t value) noexcept {
    int32_t mapped_slot = MapPlayerGlobalConfigKey(key);
    if (mapped_slot < 0) {
        return -1;
    }
    setDirectGlobalConfigSlot(mapped_slot, value);
    return 0;
}

// Matches 0x166124 (84 bytes)
int32_t AVStrategyUtils::getPlayerGlobalConfigIntValue(int32_t key,
                                                       int32_t default_value) noexcept {
    int32_t mapped_slot = MapPlayerGlobalConfigKey(key);
    if (mapped_slot < 0) {
        return default_value;
    }
    return getDirectGlobalConfigSlot(mapped_slot, default_value);
}

void AVStrategyUtils::setDirectGlobalConfigSlot(int32_t internal_slot, int32_t value) noexcept {
    if (internal_slot < 0 || internal_slot >= 128) {
        return;
    }
    std::lock_guard<std::mutex> lock(g_global_config_mutex);
    g_global_config_slots[internal_slot] = value;
    g_global_config_initialized[internal_slot] = true;
}

int32_t AVStrategyUtils::getDirectGlobalConfigSlot(int32_t internal_slot,
                                                   int32_t default_value) noexcept {
    if (internal_slot < 0 || internal_slot >= 128) {
        return default_value;
    }
    std::lock_guard<std::mutex> lock(g_global_config_mutex);
    if (!g_global_config_initialized[internal_slot]) {
        return default_value;
    }
    return g_global_config_slots[internal_slot];
}

// ============================================================================
// 2. AVDropFrameOperator & AVLoadControlOperator (0x16cde4 .. 0x16ce34)
// ============================================================================

// Matches AVDropFrameOperator::ctor() @ 0x16cde8:
//   str wzr, [x0, #8] ; refcount_ = 0
AVDropFrameOperator::AVDropFrameOperator() noexcept
    : refcount_(0), max_drop_streak_(4), drop_threshold_us_(40000) {}

// Matches AVDropFrameOperator::dtor() @ 0x16cde4 & deleting dtor @ 0x16ce00
AVDropFrameOperator::~AVDropFrameOperator() noexcept = default;

bool AVDropFrameOperator::shouldDropVideoFrame(int64_t video_pts_us,
                                               int64_t audio_pts_us,
                                               int32_t consecutive_drops,
                                               bool is_keyframe) noexcept {
    if (is_keyframe || consecutive_drops >= max_drop_streak_) {
        return false;
    }
    int64_t lag_us = audio_pts_us - video_pts_us;
    return lag_us > drop_threshold_us_;
}

// Matches AVLoadControlOperator::ctor() @ 0x16ce04:
//   mov w8, #1; str w8, [x0, #8] ; refcount_ = 1
AVLoadControlOperator::AVLoadControlOperator() noexcept
    : refcount_(1),
      min_buffer_ms_(15000),
      max_buffer_ms_(50000),
      playback_start_ms_(2500),
      rebuffer_start_ms_(5000) {}

// Matches AVLoadControlOperator::dtor() @ 0x16ce28, thunk @ 0x16ce2c, deleting dtor @ 0x16ce30
AVLoadControlOperator::~AVLoadControlOperator() noexcept = default;

bool AVLoadControlOperator::shouldStartPlayback(int64_t buffered_duration_ms,
                                                float playback_speed,
                                                bool rebuffering) const noexcept {
    float speed = (playback_speed > 0.1f) ? playback_speed : 1.0f;
    int64_t threshold_ms = rebuffering ? rebuffer_start_ms_ : playback_start_ms_;
    int64_t scaled_threshold = static_cast<int64_t>(static_cast<double>(threshold_ms) * speed);
    return buffered_duration_ms >= scaled_threshold;
}

bool AVLoadControlOperator::shouldContinueLoading(int64_t buffered_duration_ms,
                                                  int64_t target_bitrate_bps) const noexcept {
    if (buffered_duration_ms < min_buffer_ms_) {
        return true;
    }
    if (buffered_duration_ms >= max_buffer_ms_) {
        return false;
    }
    return target_bitrate_bps <= 25000000LL;
}

int32_t AVLoadControlOperator::onTrackSelected(int32_t track_type, int32_t bitrate_bps) noexcept {
    if (track_type == 0 && bitrate_bps > 0) {
        // Adjust max_buffer_ms_ dynamically for high-bitrate 4K streams
        max_buffer_ms_ = (bitrate_bps > 15000000) ? 65000 : 50000;
    }
    return 0;
}

}  // namespace player
}  // namespace ttm
}  // namespace ss
}  // namespace com

// ============================================================================
// 3. mdlInfoCallback (0x0c4af8) & TTPlayerStrategyCenter (0x1ee348 .. 0x1ee3a4)
// ============================================================================
namespace {

std::atomic<int32_t> g_mdl_enable_event0{1};
void* g_mdl_fallback_opaque = nullptr;
TTMPlayerMdlFallbackCallback g_mdl_fallback_cb = nullptr;

std::atomic<bool> g_strategy_center_initialized{false};
std::atomic<int32_t> g_strategy_last_event{0};
std::atomic<int64_t> g_strategy_datacenter_handle{0};

}  // namespace

extern "C" {

void ttmplayer_set_mdl_callback_state(int32_t enable_event0_forward,
                                      void* fallback_opaque,
                                      TTMPlayerMdlFallbackCallback fallback_cb) noexcept {
    g_mdl_enable_event0.store(enable_event0_forward, std::memory_order_release);
    g_mdl_fallback_opaque = fallback_opaque;
    g_mdl_fallback_cb = fallback_cb;
}

// Disassembly of mdlInfoCallback @ 0x0c4af8 (208 bytes):
//   - Calls getStrategyCenter() (`0x14e498`):
//     - If what == 4: calls vtable[+0x20](center, 0xfa4 (4004), (int32_t)arg)
//     - If what == 3: calls vtable[+0x10](center, task_ctx, 0xfa2 (4002), arg)
//     - If what == 0 and data@0x370098 != 0: calls vtable[+0x10](center, task_ctx, 0xfa1 (4001), arg)
//   - Otherwise if fallback callback @ 0x3700c0 != nullptr: invokes fallback_cb(opaque@0x3700b8, task_ctx, what, arg)
//   - Otherwise returns -1.
int64_t mdlInfoCallback(void* task_ctx, int32_t what, int64_t arg) {
    using com::ss::ttm::player::AVStrategyCenterProtocol;
    using com::ss::ttm::player::AVStrategyUtils;

    AVStrategyCenterProtocol* center = AVStrategyUtils::getRegisteredStrategyCenter();
    if (center != nullptr) {
        if (what == 4) {
            return static_cast<int64_t>(center->onEvent(0xFA4, static_cast<int32_t>(arg), 0));
        }
        if (what == 3) {
            return static_cast<int64_t>(
                center->onEvent(0xFA2, reinterpret_cast<int64_t>(task_ctx), arg));
        }
        if (what == 0 && g_mdl_enable_event0.load(std::memory_order_acquire) != 0) {
            return static_cast<int64_t>(
                center->onEvent(0xFA1, reinterpret_cast<int64_t>(task_ctx), arg));
        }
    }
    if (g_mdl_fallback_cb != nullptr) {
        return g_mdl_fallback_cb(g_mdl_fallback_opaque, task_ctx, what, arg);
    }
    return -1;
}

void ttmplayer_strategy_center_init(void* /*env*/, void* /*clazz*/) {
    g_strategy_center_initialized.store(true, std::memory_order_release);
}

void ttmplayer_strategy_center_notify_event(void* /*env*/, void* /*clazz*/, int32_t event_code) {
    g_strategy_last_event.store(event_code, std::memory_order_release);
    auto* center = com::ss::ttm::player::AVStrategyUtils::getRegisteredStrategyCenter();
    if (center) {
        center->onEvent(event_code, 0, 0);
    }
}

void ttmplayer_strategy_center_set_data_center_handle(void* /*env*/,
                                                      void* /*clazz*/,
                                                      int64_t handle) {
    g_strategy_datacenter_handle.store(handle, std::memory_order_release);
}

const char* ttmplayer_strategy_center_pack_log_info(int64_t handle,
                                                    char* out_buf,
                                                    size_t out_cap) {
    if (!out_buf || out_cap == 0) {
        return "";
    }
    auto* center = com::ss::ttm::player::AVStrategyUtils::getRegisteredStrategyCenter();
    if (center) {
        std::string s = center->packStrategyLogInfo(handle);
        std::snprintf(out_buf, out_cap, "%s", s.c_str());
        return out_buf;
    }
    std::snprintf(out_buf,
                  out_cap,
                  "{\"strategy_init\":%d,\"last_event\":%d,\"dc_handle\":%lld,\"req_handle\":%lld}",
                  g_strategy_center_initialized.load(std::memory_order_acquire) ? 1 : 0,
                  g_strategy_last_event.load(std::memory_order_acquire),
                  static_cast<long long>(g_strategy_datacenter_handle.load(std::memory_order_acquire)),
                  static_cast<long long>(handle));
    return out_buf;
}

}  // extern "C"
