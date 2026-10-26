/**
 * @file ttmplayer_player_jni.h
 * @brief Cleanroom C++17 Header for TTPlayer 62-Method JNI Bridge & Lifecycle Engine
 *        Header C++17 Tái cấu trúc Sạch cho Cầu nối JNI 62 Phương thức & Vòng đời TTPlayer
 *
 * Binary Ground Truth / Tham chiếu Nhị phân Gốc (libttmplayer.so):
 * - JNI_OnLoad                                                @ 0x197174 (684 bytes)
 * - JNI_OnUnload                                              @ 0x197420 (144 bytes)
 * - Java_com_ss_ttm_player_NativeObject_nativeRelease         @ 0x188824 ( 24 bytes)
 * - Java_com_ss_ttm_player_MediaTransport_nativeSetFilterType @ 0x18d73c (116 bytes)
 * - Java_com_ss_ttm_player_TraitObject_nativeRelease          @ 0x19c83c ( 16 bytes)
 * - com/ss/ttm/player/TTPlayer JNINativeMethod[62]            @ 0x351eb8 .. 0x352488
 */

#ifndef NEXTAI_OPENCUT_TTMPLAYER_PLAYER_JNI_H_
#define NEXTAI_OPENCUT_TTMPLAYER_PLAYER_JNI_H_

#include "ttmplayer_types.h"

struct TTMPlayerJNINativeMethodEntry {
    const char* name;
    const char* signature;
    uint64_t binary_vaddr;
};

extern "C" {

// Direct .dynsym JNI exports
int32_t JNI_OnLoad(void* vm, void* reserved);
void JNI_OnUnload(void* vm, void* reserved);
void Java_com_ss_ttm_player_NativeObject_nativeRelease(void* env, void* thiz, int64_t native_ptr);
void Java_com_ss_ttm_player_MediaTransport_nativeSetFilterType(void* env,
                                                               void* thiz,
                                                               int32_t filter_type);
void Java_com_ss_ttm_player_TraitObject_nativeRelease(void* env, void* thiz, int64_t trait_ptr);

// Inspection & log property helpers
int32_t ttmplayer_parse_log_prop_value(const char* prop_val) noexcept;
int32_t ttmplayer_get_total_jni_method_count() noexcept;
const TTMPlayerJNINativeMethodEntry* ttmplayer_get_ttplayer_jni_table(size_t* out_count) noexcept;

// Core TTPlayer 62-method native bridge (0x19c850 .. 0x1a3c58)
int64_t ttmplayer_native_create(void* context,
                                int32_t player_type,
                                int32_t a1,
                                int32_t a2,
                                const char* app_info);
void ttmplayer_native_release(int64_t handle);
int32_t ttmplayer_native_prepare(int64_t handle);
void ttmplayer_native_close(int64_t handle);
void ttmplayer_native_prev_close(int64_t handle);
int32_t ttmplayer_native_start(int64_t handle);
int32_t ttmplayer_native_reset(int64_t handle);
int32_t ttmplayer_native_pause(int64_t handle);
void ttmplayer_native_stop(int64_t handle);
int32_t ttmplayer_native_seek(int64_t handle, int32_t msec);
int32_t ttmplayer_native_seek2(int64_t handle, int32_t msec, int32_t gear_mode);
int32_t ttmplayer_native_set_video_surface(int64_t handle, void* surface);
void ttmplayer_native_set_data_source(int64_t handle, const char* url);
void ttmplayer_native_set_data_source_fd(int64_t handle, int32_t fd);
int32_t ttmplayer_native_get_duration(int64_t handle);
int32_t ttmplayer_native_is_playing(int64_t handle);
int32_t ttmplayer_native_is_looping(int64_t handle);
void ttmplayer_native_set_looping(int64_t handle, int32_t looping);
void ttmplayer_native_set_volume(int64_t handle, float left_vol, float right_vol);
int32_t ttmplayer_native_get_video_width(int64_t handle);
int32_t ttmplayer_native_get_video_height(int64_t handle);
int32_t ttmplayer_native_get_current_position(int64_t handle);
int32_t ttmplayer_native_set_string_value(int64_t handle, int32_t key, const char* val);
const char* ttmplayer_native_get_string_value(int64_t handle,
                                              int32_t key,
                                              char* out_buf,
                                              size_t out_cap);
int32_t ttmplayer_native_set_int_value(int64_t handle, int32_t key, int32_t val);
int32_t ttmplayer_native_get_int_value(int64_t handle, int32_t key, int32_t default_val);
int32_t ttmplayer_native_set_long_value(int64_t handle, int32_t key, int64_t val);
int64_t ttmplayer_native_get_long_value(int64_t handle, int32_t key, int64_t default_val);
int32_t ttmplayer_native_set_float_value(int64_t handle, int32_t key, float val);
float ttmplayer_native_get_float_value(int64_t handle, int32_t key, float default_val);
int32_t ttmplayer_native_set_double_value(int64_t handle, int32_t key, double val);
double ttmplayer_native_get_double_value(int64_t handle, int32_t key, double default_val);
void ttmplayer_native_set_global_int_for_key(int32_t key, int32_t val);
int64_t ttmplayer_native_get_demuxer_factory(int32_t type);
int32_t ttmplayer_native_register_native_mdl(int64_t mdl_handle);
void ttmplayer_native_mouse_event(int64_t handle, int32_t x, int32_t y, int32_t action);
void ttmplayer_native_rotate_camera(int64_t handle, float yaw, float pitch);
void ttmplayer_native_take_screenshot(int64_t handle);
void ttmplayer_native_switch_stream(int64_t handle, int32_t stream_id, int32_t stream_type);
int32_t ttmplayer_native_setup_media_codec(int64_t handle);
int32_t ttmplayer_native_set_int_value_array(int64_t handle,
                                             const int32_t* keys,
                                             const int32_t* vals,
                                             int32_t count);
int32_t ttmplayer_native_set_long_value_array(int64_t handle,
                                              const int32_t* keys,
                                              const int64_t* vals,
                                              int32_t count);
int32_t ttmplayer_native_set_float_value_array(int64_t handle,
                                               const int32_t* keys,
                                               const float* vals,
                                               int32_t count);
int64_t ttmplayer_native_create_default_config();
void ttmplayer_native_set_config(int64_t handle, int64_t config_handle);

}  // extern "C"

#endif  // NEXTAI_OPENCUT_TTMPLAYER_PLAYER_JNI_H_
