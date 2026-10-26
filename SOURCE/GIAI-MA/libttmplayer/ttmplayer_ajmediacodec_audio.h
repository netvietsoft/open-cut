/**
 * @file ttmplayer_ajmediacodec_audio.h
 * @brief Cleanroom C++17 Header for AJMediaCodec Hardware Ring-Buffer & FFmpegAudioDecoders
 *        Header C++17 Tái cấu trúc Sạch cho Bộ đệm Vòng AJMediaCodec & FFmpegAudioDecoders
 *
 * Binary Ground Truth / Tham chiếu Nhị phân Gốc (libttmplayer.so):
 * - register_FFmpegAudioDecoders           @ 0x1e7fa4 (2,944 bytes)
 * - unregister_FFmpegAudioDecoders         @ 0x1e8b24 (   60 bytes)
 * - AJMediaCodec::_onEmptyBuffer           @ 0x21a924 (   20 bytes)
 * - AJMediaCodec::_onFilledBuffer          @ 0x21a938 -> 0x212b34 (160 bytes)
 * - AJMediaCodec::_onError                 @ 0x21a960 -> 0x212b9c ( 52 bytes)
 * - AJMediaCodec::_onFormatChanged         @ 0x21a970 -> 0x212bd0 (416 bytes)
 * - AJMediaCodec::_clearBufferIndex        @ 0x21a9b8 (   16 bytes)
 * - AJMediaCodec::_setSurfaceCompleted     @ 0x21a9c8 (   16 bytes)
 */

#ifndef NEXTAI_OPENCUT_TTMPLAYER_AJMEDIACODEC_AUDIO_H_
#define NEXTAI_OPENCUT_TTMPLAYER_AJMEDIACODEC_AUDIO_H_

#include "ttmplayer_types.h"

extern "C" {

// Exported global functions in .dynsym
int32_t register_FFmpegAudioDecoders(void* registry_ctx);
void unregister_FFmpegAudioDecoders();
int32_t ttmplayer_get_registered_audio_decoder_count() noexcept;
const char* ttmplayer_get_registered_audio_decoder_name(int32_t index) noexcept;

// AJMediaCodec JNI & native ring-buffer functions (0x212b34 .. 0x21a9c8)
void ttmplayer_ajmediacodec_on_empty_buffer(void* env,
                                            void* obj,
                                            int64_t handle,
                                            int32_t buffer_index);

void ttmplayer_ajmediacodec_on_filled_buffer(void* env,
                                             void* obj,
                                             int64_t handle,
                                             int32_t buffer_index,
                                             int32_t offset,
                                             int32_t size,
                                             int64_t pts_us,
                                             int32_t flags);

void ttmplayer_ajmediacodec_on_error(void* env, void* obj, int64_t handle);

void ttmplayer_ajmediacodec_on_format_changed(void* env,
                                              void* obj,
                                              int64_t handle,
                                              int32_t changed_status,
                                              int32_t width,
                                              int32_t height,
                                              int32_t color_format,
                                              int32_t stride,
                                              int32_t slice_height,
                                              int32_t crop_left,
                                              int32_t crop_top,
                                              int32_t crop_right,
                                              int32_t crop_bottom);

void ttmplayer_ajmediacodec_clear_buffer_index(void* env, void* obj, int64_t handle);
void ttmplayer_ajmediacodec_set_surface_completed(void* env, void* obj, int64_t handle);

// Dequeue helper for consumer thread & verification tests
int32_t ttmplayer_ajmediacodec_dequeue_filled_buffer(AJMediaCodecNative* codec,
                                                     AJMediaCodecBufferSlot* out_slot) noexcept;

// SAMICore & TTRAudioEngine biquad / loudness audio processing pipeline
int32_t ttmplayer_sami_audio_process_f32(const float* in_pcm,
                                         float* out_pcm,
                                         int32_t num_samples,
                                         int32_t channels,
                                         float gain_db) noexcept;

}  // extern "C"

#endif  // NEXTAI_OPENCUT_TTMPLAYER_AJMEDIACODEC_AUDIO_H_
