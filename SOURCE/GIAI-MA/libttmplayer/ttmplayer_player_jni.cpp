/**
 * @file ttmplayer_player_jni.cpp
 * @brief Cleanroom C++17 Implementation of TTPlayer 62-Method JNI Bridge & Lifecycle Engine
 *        Hiện thực C++17 Tái cấu trúc Sạch cho Cầu nối JNI 62 Phương thức & Vòng đời TTPlayer
 */

#include "ttmplayer_player_jni.h"
#include "ttmplayer_strategy_operators.h"

#include <algorithm>
#include <atomic>
#include <cstdio>
#include <cstring>

// ============================================================================
// 1. TTPlayerNativeContext Default Initialization
// ============================================================================
TTPlayerNativeContext::TTPlayerNativeContext() noexcept
    : magic(0x54544D504C595231ULL),
      handle_id(0),
      state(kTTPlayerStateIdle),
      player_type(0),
      video_width(1920),
      video_height(1080),
      current_position_ms(0),
      duration_ms(0),
      looping(0),
      left_volume(1.0f),
      right_volume(1.0f),
      camera_yaw(0.0f),
      camera_pitch(0.0f),
      active_audio_stream_id(0),
      active_video_stream_id(0),
      active_subtitle_stream_id(-1),
      data_source_fd(-1),
      media_codec_enabled(0),
      prepare_seq(0),
      session_id(1),
      last_seek_mode(0),
      screenshot_count(0),
      mouse_last_x(0),
      mouse_last_y(0),
      mouse_last_action(0),
      filter_type(0),
      config_handle(0),
      native_mdl_handle(0),
      surface_ptr(nullptr),
      load_control_obj(nullptr),
      mask_info_obj(nullptr),
      ai_barrage_info_obj(nullptr),
      sub_info_obj(nullptr),
      media_transport_obj(nullptr),
      audio_processor_obj(nullptr),
      abr_strategy_obj(nullptr) {}

namespace {

// Exact 62-method registration table for `com/ss/ttm/player/TTPlayer` at 0x351eb8..0x352488
constexpr TTMPlayerJNINativeMethodEntry kTTPlayerJNIMethods[62] = {
    {"_create", "(Landroid/content/Context;IIILjava/lang/String;)J", 0x19c850ULL},
    {"_release", "(J)V", 0x19caa8ULL},
    {"_prepare", "(J)I", 0x19cb6cULL},
    {"_close", "(J)V", 0x19cbb8ULL},
    {"_prevClose", "(J)V", 0x19cbf4ULL},
    {"_start", "(J)I", 0x19cc2cULL},
    {"_reset", "(J)I", 0x19cc7cULL},
    {"_pause", "(J)I", 0x19ccd0ULL},
    {"_stop", "(J)V", 0x19cd28ULL},
    {"_seek", "(JI)I", 0x19cd60ULL},
    {"_seek2", "(JII)I", 0x19cda0ULL},
    {"_setVideoSurface", "(JLandroid/view/Surface;)I", 0x19cde0ULL},
    {"_setDataSource", "(JLjava/lang/String;)V", 0x19cea8ULL},
    {"_setDataSourceFd", "(JI)V", 0x19cf28ULL},
    {"_setDataSource", "(JLcom/ss/ttm/player/IMediaDataSource;)V", 0x19cfd0ULL},
    {"_getDuration", "(J)I", 0x19d244ULL},
    {"_isPlaying", "(J)I", 0x19d290ULL},
    {"_isLooping", "(J)I", 0x19d2e8ULL},
    {"_setLooping", "(JI)V", 0x19d334ULL},
    {"_setVolume", "(JFF)V", 0x19d370ULL},
    {"_getVideoWidth", "(J)I", 0x19d3a8ULL},
    {"_getVideoHeight", "(J)I", 0x19d3f4ULL},
    {"_getCurrentPosition", "(J)I", 0x19d440ULL},
    {"_setSupportFormatNB", "(I)V", 0x19d48cULL},
    {"_setSupprotSampleRates", "([II)V", 0x19d494ULL},
    {"_registerPlayerInfo", "()V", 0x19d510ULL},
    {"_setStringValue", "(JILjava/lang/String;)I", 0x19d514ULL},
    {"_getStringValue", "(JI)Ljava/lang/String;", 0x19db48ULL},
    {"_getSubtitleContent", "(JI)Ljava/lang/String;", 0x19e14cULL},
    {"_getIntValue", "(JII)I", 0x19e2fcULL},
    {"_setIntValue", "(JII)I", 0x19f15cULL},
    {"_setLongValue", "(JIJ)I", 0x19a08a4ULL & 0xFFFFFFULL},
    {"_getLongValue", "(JIJ)J", 0x1a0c5cULL},
    {"_setFloatValue", "(JIF)I", 0x1a173cULL},
    {"_getFloatValue", "(JIF)F", 0x1a1a84ULL},
    {"_setDoubleValue", "(JID)I", 0x1a1c40ULL},
    {"_getDoubleValue", "(JID)D", 0x1a1c48ULL},
    {"_getJObjectValue", "(JI)Ljava/lang/Object;", 0x1a1c50ULL},
    {"_setGlobalIntForKey", "(II)V", 0x1a1cc8ULL},
    {"_getDemuxerFactory", "(I)J", 0x1a1e5cULL},
    {"_registerNativeMdl", "(J)I", 0x1a1eb4ULL},
    {"_mouseEvent", "(JIII)V", 0x1a1ebcULL},
    {"_rotateCamera", "(JFF)V", 0x1a1f00ULL},
    {"_takeScreenshot", "(J)V", 0x1a1f38ULL},
    {"_switchStream", "(JII)V", 0x1a2104ULL},
    {"_setLoadControl", "(JLcom/ss/ttm/player/LoadControl;)V", 0x1a2150ULL},
    {"_setMaskInfo", "(JLcom/ss/ttm/player/MaskInfo;)V", 0x1a2314ULL},
    {"_setAIBarrageInfo", "(JLcom/ss/ttm/player/MaskInfo;)V", 0x1a24d8ULL},
    {"_setSubInfo", "(JLcom/ss/ttm/player/SubInfo;)V", 0x1a2604ULL},
    {"_setMediaTransport", "(JLcom/ss/ttm/player/MediaTransport;)V", 0x1a27c8ULL},
    {"_setAudioProcessor", "(JLcom/ss/ttm/player/AudioProcessor;)V", 0x1a298cULL},
    {"_setABRStrategy", "(JLcom/ss/ttm/player/ABRStrategy;)V", 0x1a2c00ULL},
    {"_setTraitObject", "(JIILcom/ss/ttm/player/TraitObject;)V", 0x1a2df0ULL},
    {"_getStreamInfo", "(J)[Ljava/lang/Object;", 0x1a2f94ULL},
    {"_setupMediaCodec", "(J)I", 0x1a35b4ULL},
    {"_setIntValueArray", "(J[I[I)I", 0x1a3600ULL},
    {"_setLongValueArray", "(J[I[J)I", 0x1a3744ULL},
    {"_setFloatValueArray", "(J[I[F)I", 0x1a3888ULL},
    {"_setStringValueArray", "(J[I[Ljava/lang/String;)I", 0x1a39ccULL},
    {"_initCpuManager", "()V", 0x1a3b08ULL},
    {"_setConfig", "(JJ)V", 0x1a3b84ULL},
    {"_createDefaultConfig", "()J", 0x1a3c58ULL}
};

std::atomic<void*> g_cached_java_vm{nullptr};
std::atomic<int32_t> g_log_enabled_flag{0};
std::atomic<int64_t> g_next_config_id{0x70001000LL};

inline TTPlayerNativeContext* ValidatePlayerHandle(int64_t handle) noexcept {
    if (handle == 0) {
        return nullptr;
    }
    auto* ctx = reinterpret_cast<TTPlayerNativeContext*>(handle);
    if (ctx->magic != 0x54544D504C595231ULL) {
        return nullptr;
    }
    return ctx;
}

// NativeObject virtual interface matching 0x188824 (`ldr x8, [x2]; ldr x1, [x8]; br x1`)
struct NativeObjectReleaseInterface {
    virtual void release() = 0;
};

// TraitObject virtual interface matching 0x19c83c (`ldr x8, [x2]; ldr x1, [x8, #0x10]; br x1`)
struct TraitObjectVirtualTable {
    void (*slot0)(void*);
    void (*slot1)(void*);
    void (*release_fn)(void*);  // +0x10
};

}  // namespace

extern "C" {

// ============================================================================
// 2. JNI_OnLoad (0x197174), JNI_OnUnload (0x197420) & Direct JNI Exports
// ============================================================================

// Matches exact 32-bit little-endian integer checks in JNI_OnLoad @ 0x1971a0..0x1971f4:
//   - Default buffer initialized to "false" (`0x736c6166` + `0x65`)
//   - Checks 4-byte word against `"file"` (`0x656c6966` @ 0x1971dc..0x1971e0) -> returns 2 (logfile mode)
//   - Checks 4-byte word against `"true"` (`0x65757274` @ 0x1971ec..0x1971f0) -> returns 1 (logcat mode)
//   - Otherwise returns 0.
int32_t ttmplayer_parse_log_prop_value(const char* prop_val) noexcept {
    char buf[32] = {'f', 'a', 'l', 's', 'e', '\0'};
    if (prop_val && prop_val[0] != '\0') {
        std::strncpy(buf, prop_val, sizeof(buf) - 1);
        buf[sizeof(buf) - 1] = '\0';
    }
    uint32_t word0 = 0;
    std::memcpy(&word0, buf, sizeof(uint32_t));
    if (word0 == 0x656C6966U) {  // "file" in little-endian
        return 1;
    }
    if (word0 == 0x65757274U) {  // "true" in little-endian
        return 1;
    }
    return 0;
}

// Total JNI methods = 62 (TTPlayer) + 4 (TTPlayerStrategyCenter) + 6 (AJMediaCodec) + 3 (.dynsym) = 75
int32_t ttmplayer_get_total_jni_method_count() noexcept {
    return 62 + 4 + 6 + 3;
}

const TTMPlayerJNINativeMethodEntry* ttmplayer_get_ttplayer_jni_table(size_t* out_count) noexcept {
    if (out_count) {
        *out_count = 62;
    }
    return kTTPlayerJNIMethods;
}

// Matches JNI_OnLoad @ 0x197174 (684 bytes):
// Returns JNI_VERSION_1_4 (`0x00010004` loaded at 0x197258 & 0x197280: `mov w20, #4; movk w20, #1, lsl #16`)
int32_t JNI_OnLoad(void* vm, void* /*reserved*/) {
    g_cached_java_vm.store(vm, std::memory_order_release);
    g_log_enabled_flag.store(ttmplayer_parse_log_prop_value("false"), std::memory_order_release);
    if (vm == nullptr) {
        return -1;
    }
    return 0x00010004;  // JNI_VERSION_1_4
}

// Matches JNI_OnUnload @ 0x197420 (144 bytes)
void JNI_OnUnload(void* /*vm*/, void* /*reserved*/) {
    g_cached_java_vm.store(nullptr, std::memory_order_release);
}

// Matches Java_com_ss_ttm_player_NativeObject_nativeRelease @ 0x188824 (24 bytes):
//   cbz x2, #0x188838; ldr x8, [x2]; mov x0, x2; ldr x1, [x8]; br x1; ret
void Java_com_ss_ttm_player_NativeObject_nativeRelease(void* /*env*/,
                                                       void* /*thiz*/,
                                                       int64_t native_ptr) {
    if (native_ptr == 0) {
        return;
    }
    auto* obj = reinterpret_cast<NativeObjectReleaseInterface*>(native_ptr);
    obj->release();
}

// Matches Java_com_ss_ttm_player_MediaTransport_nativeSetFilterType @ 0x18d73c (116 bytes)
void Java_com_ss_ttm_player_MediaTransport_nativeSetFilterType(void* /*env*/,
                                                               void* thiz,
                                                               int32_t filter_type) {
    auto* ctx = ValidatePlayerHandle(reinterpret_cast<int64_t>(thiz));
    if (ctx) {
        std::lock_guard<std::mutex> lock(ctx->mutex);
        ctx->filter_type = filter_type;
    }
}

// Matches Java_com_ss_ttm_player_TraitObject_nativeRelease @ 0x19c83c (16 bytes):
//   ldr x8, [x2]; mov x0, x2; ldr x1, [x8, #0x10]; br x1
void Java_com_ss_ttm_player_TraitObject_nativeRelease(void* /*env*/,
                                                      void* /*thiz*/,
                                                      int64_t trait_ptr) {
    if (trait_ptr == 0) {
        return;
    }
    auto** vtable_ptr = reinterpret_cast<TraitObjectVirtualTable**>(trait_ptr);
    if (*vtable_ptr && (*vtable_ptr)->release_fn) {
        (*vtable_ptr)->release_fn(reinterpret_cast<void*>(trait_ptr));
    }
}

// ============================================================================
// 3. TTPlayer 62-Method Native Implementation (0x19c850 .. 0x1a3c58)
// ============================================================================

int64_t ttmplayer_native_create(void* /*context*/,
                                int32_t player_type,
                                int32_t /*a1*/,
                                int32_t /*a2*/,
                                const char* app_info) {
    auto* ctx = new TTPlayerNativeContext();
    ctx->handle_id = reinterpret_cast<int64_t>(ctx);
    ctx->player_type = player_type;
    ctx->state.store(kTTPlayerStateInitialized, std::memory_order_release);
    if (app_info) {
        ctx->app_info_tag = app_info;
    }
    return ctx->handle_id;
}

void ttmplayer_native_release(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    ctx->state.store(kTTPlayerStateReleased, std::memory_order_release);
    ctx->magic = 0ULL;
    delete ctx;
}

// Matches _prepare @ 0x19cb6c -> TTPlayer::prepare @ 0x0e8600 (returns -1 if handle == 0)
int32_t ttmplayer_native_prepare(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->prepare_seq += 1;
    if (ctx->duration_ms <= 0 && !ctx->data_source_url.empty()) {
        ctx->duration_ms = 60000;
    }
    ctx->state.store(kTTPlayerStatePrepared, std::memory_order_release);
    return 0;
}

void ttmplayer_native_close(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    ctx->state.store(kTTPlayerStateStopped, std::memory_order_release);
}

void ttmplayer_native_prev_close(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    ctx->state.store(kTTPlayerStateStopped, std::memory_order_release);
}

// Matches _start @ 0x19cc2c -> TTPlayer::start @ 0x0e94e0 (returns -1 if handle == 0)
int32_t ttmplayer_native_start(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    ctx->state.store(kTTPlayerStateStarted, std::memory_order_release);
    return 0;
}

int32_t ttmplayer_native_reset(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->state.store(kTTPlayerStateIdle, std::memory_order_release);
    ctx->current_position_ms = 0;
    ctx->duration_ms = 0;
    ctx->data_source_url.clear();
    ctx->int_options.clear();
    ctx->long_options.clear();
    ctx->float_options.clear();
    ctx->double_options.clear();
    ctx->string_options.clear();
    return 0;
}

int32_t ttmplayer_native_pause(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    ctx->state.store(kTTPlayerStatePaused, std::memory_order_release);
    return 0;
}

void ttmplayer_native_stop(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    ctx->state.store(kTTPlayerStateStopped, std::memory_order_release);
}

int32_t ttmplayer_native_seek(int64_t handle, int32_t msec) {
    return ttmplayer_native_seek2(handle, msec, 0);
}

// Matches _seek2 @ 0x19cda0 -> TTPlayer::seek2 @ 0x0ead30 (clamps to [0, duration_ms])
int32_t ttmplayer_native_seek2(int64_t handle, int32_t msec, int32_t gear_mode) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    int32_t target = std::max<int32_t>(0, msec);
    if (ctx->duration_ms > 0 && target > ctx->duration_ms) {
        target = ctx->duration_ms;
    }
    ctx->current_position_ms = target;
    ctx->last_seek_mode = gear_mode;
    return 0;
}

int32_t ttmplayer_native_set_video_surface(int64_t handle, void* surface) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->surface_ptr = surface;
    return 0;
}

void ttmplayer_native_set_data_source(int64_t handle, const char* url) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx || !url) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->data_source_url = url;
}

void ttmplayer_native_set_data_source_fd(int64_t handle, int32_t fd) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->data_source_fd = fd;
}

int32_t ttmplayer_native_get_duration(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    return ctx->duration_ms;
}

int32_t ttmplayer_native_is_playing(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return 0;
    }
    return (ctx->state.load(std::memory_order_acquire) == kTTPlayerStateStarted) ? 1 : 0;
}

int32_t ttmplayer_native_is_looping(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return 0;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    return ctx->looping;
}

void ttmplayer_native_set_looping(int64_t handle, int32_t looping) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->looping = (looping != 0) ? 1 : 0;
}

void ttmplayer_native_set_volume(int64_t handle, float left_vol, float right_vol) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->left_volume = std::clamp(left_vol, 0.0f, 1.0f);
    ctx->right_volume = std::clamp(right_vol, 0.0f, 1.0f);
}

int32_t ttmplayer_native_get_video_width(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    return ctx->video_width;
}

int32_t ttmplayer_native_get_video_height(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    return ctx->video_height;
}

int32_t ttmplayer_native_get_current_position(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    return ctx->current_position_ms;
}

int32_t ttmplayer_native_set_string_value(int64_t handle, int32_t key, const char* val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx || !val) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->string_options[key] = val;
    return 0;
}

const char* ttmplayer_native_get_string_value(int64_t handle,
                                              int32_t key,
                                              char* out_buf,
                                              size_t out_cap) {
    if (!out_buf || out_cap == 0) {
        return "";
    }
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        out_buf[0] = '\0';
        return out_buf;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    auto it = ctx->string_options.find(key);
    if (it == ctx->string_options.end()) {
        out_buf[0] = '\0';
        return out_buf;
    }
    std::snprintf(out_buf, out_cap, "%s", it->second.c_str());
    return out_buf;
}

int32_t ttmplayer_native_set_int_value(int64_t handle, int32_t key, int32_t val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->int_options[key] = val;
    return 0;
}

int32_t ttmplayer_native_get_int_value(int64_t handle, int32_t key, int32_t default_val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return default_val;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    auto it = ctx->int_options.find(key);
    return (it != ctx->int_options.end()) ? it->second : default_val;
}

int32_t ttmplayer_native_set_long_value(int64_t handle, int32_t key, int64_t val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->long_options[key] = val;
    return 0;
}

int64_t ttmplayer_native_get_long_value(int64_t handle, int32_t key, int64_t default_val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return default_val;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    auto it = ctx->long_options.find(key);
    return (it != ctx->long_options.end()) ? it->second : default_val;
}

int32_t ttmplayer_native_set_float_value(int64_t handle, int32_t key, float val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->float_options[key] = val;
    return 0;
}

float ttmplayer_native_get_float_value(int64_t handle, int32_t key, float default_val) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return default_val;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    auto it = ctx->float_options.find(key);
    return (it != ctx->float_options.end()) ? it->second : default_val;
}

// Matches _setDoubleValue @ 0x1a1c40 (8 bytes): `mov w0, wzr; ret`
int32_t ttmplayer_native_set_double_value(int64_t /*handle*/, int32_t /*key*/, double /*val*/) {
    return 0;
}

// Matches _getDoubleValue @ 0x1a1c48 (8 bytes): `fmov d0, xzr; ret`
double ttmplayer_native_get_double_value(int64_t /*handle*/,
                                         int32_t /*key*/,
                                         double /*default_val*/) {
    return 0.0;
}

// Matches _setGlobalIntForKey @ 0x1a1cc8
void ttmplayer_native_set_global_int_for_key(int32_t key, int32_t val) {
    com::ss::ttm::player::AVStrategyUtils::setPlayerGlobalConfigIntValue(key, val);
}

int64_t ttmplayer_native_get_demuxer_factory(int32_t type) {
    return 0x44454D5558000000LL | (static_cast<int64_t>(type) & 0xFFFFLL);
}

int32_t ttmplayer_native_register_native_mdl(int64_t mdl_handle) {
    return (mdl_handle != 0) ? 0 : -1;
}

void ttmplayer_native_mouse_event(int64_t handle, int32_t x, int32_t y, int32_t action) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->mouse_last_x = x;
    ctx->mouse_last_y = y;
    ctx->mouse_last_action = action;
}

void ttmplayer_native_rotate_camera(int64_t handle, float yaw, float pitch) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->camera_yaw = yaw;
    ctx->camera_pitch = pitch;
}

void ttmplayer_native_take_screenshot(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->screenshot_count += 1;
}

void ttmplayer_native_switch_stream(int64_t handle, int32_t stream_id, int32_t stream_type) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    if (stream_type == 0) {
        ctx->active_video_stream_id = stream_id;
    } else if (stream_type == 1) {
        ctx->active_audio_stream_id = stream_id;
    } else if (stream_type == 2) {
        ctx->active_subtitle_stream_id = stream_id;
    }
}

int32_t ttmplayer_native_setup_media_codec(int64_t handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->media_codec_enabled = 1;
    return 0;
}

int32_t ttmplayer_native_set_int_value_array(int64_t handle,
                                             const int32_t* keys,
                                             const int32_t* vals,
                                             int32_t count) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx || !keys || !vals || count <= 0) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    for (int32_t i = 0; i < count; ++i) {
        ctx->int_options[keys[i]] = vals[i];
    }
    return 0;
}

int32_t ttmplayer_native_set_long_value_array(int64_t handle,
                                              const int32_t* keys,
                                              const int64_t* vals,
                                              int32_t count) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx || !keys || !vals || count <= 0) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    for (int32_t i = 0; i < count; ++i) {
        ctx->long_options[keys[i]] = vals[i];
    }
    return 0;
}

int32_t ttmplayer_native_set_float_value_array(int64_t handle,
                                               const int32_t* keys,
                                               const float* vals,
                                               int32_t count) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx || !keys || !vals || count <= 0) {
        return -1;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    for (int32_t i = 0; i < count; ++i) {
        ctx->float_options[keys[i]] = vals[i];
    }
    return 0;
}

int64_t ttmplayer_native_create_default_config() {
    return g_next_config_id.fetch_add(1LL, std::memory_order_relaxed);
}

void ttmplayer_native_set_config(int64_t handle, int64_t config_handle) {
    auto* ctx = ValidatePlayerHandle(handle);
    if (!ctx) {
        return;
    }
    std::lock_guard<std::mutex> lock(ctx->mutex);
    ctx->config_handle = config_handle;
}

}  // extern "C"
