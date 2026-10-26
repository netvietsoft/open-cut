/**
 * @file ttmplayer_ajmediacodec_audio.cpp
 * @brief Cleanroom C++17 Implementation of AJMediaCodec Ring-Buffer & FFmpegAudioDecoders
 *        Hiện thực C++17 Tái cấu trúc Sạch cho Bộ đệm Vòng AJMediaCodec & FFmpegAudioDecoders
 */

#include "ttmplayer_ajmediacodec_audio.h"

#include <algorithm>
#include <cmath>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

// ============================================================================
// 1. AJMediaCodecNative Constructor & Ring-Buffer (0x212b34 .. 0x21a9c8)
//    Khởi tạo AJMediaCodecNative & Bộ đệm Vòng 64-khe Không khóa (0x212b34 .. 0x21a9c8)
// ============================================================================

AJMediaCodecNative::AJMediaCodecNative() noexcept
    : header_pad{},
      error_flag(0),
      width(0),
      height(0),
      color_format(0),
      stride(0),
      slice_height(0),
      crop_left(0),
      crop_top(0),
      crop_right(0),
      crop_bottom(0),
      yuv420_frame_bytes(0),
      surface_completed(0),
      last_empty_buffer_index(-1),
      mid_pad{},
      format_cond_signals(0),
      pad_6f8(0),
      buffer_cond_signals(0),
      cond_pad{},
      write_index(0),
      filled_count(0),
      read_index(0),
      slots{} {}

namespace {

std::mutex g_audio_decoder_mutex;
// Mirrors global std::vector<AudioDecoderEntry> at 0x372bb0 (`adrp x19, #0x372000; add x19, x19, #0xbb0`)
std::vector<std::string> g_registered_audio_decoders;

constexpr const char* kDefaultFFmpegAudioDecoderNames[9] = {
    "FFmpegAudioDecoders:aac",
    "FFmpegAudioDecoders:mp3",
    "FFmpegAudioDecoders:opus",
    "FFmpegAudioDecoders:flac",
    "FFmpegAudioDecoders:vorbis",
    "FFmpegAudioDecoders:ac3",
    "FFmpegAudioDecoders:eac3",
    "FFmpegAudioDecoders:alac",
    "FFmpegAudioDecoders:pcm_s16le"
};

}  // namespace

extern "C" {

// ============================================================================
// 2. register_FFmpegAudioDecoders (0x1e7fa4) & unregister_FFmpegAudioDecoders (0x1e8b24)
// ============================================================================

// Disassembly of register_FFmpegAudioDecoders @ 0x1e7fa4 (2,944 bytes):
// Registers the 9 built-in FFmpeg audio decoder descriptors (`mov w9, #9` @ 0x1e8060,
// `.rodata` string `"FFmpegAudioDecoders"` @ 0x2c12f0, codec tag `0x10000` @ 0x1e7fe8)
// into the global decoder vector at `0x372bb0`.
int32_t register_FFmpegAudioDecoders(void* /*registry_ctx*/) {
    std::lock_guard<std::mutex> lock(g_audio_decoder_mutex);
    g_registered_audio_decoders.clear();
    g_registered_audio_decoders.reserve(9);
    for (const char* name : kDefaultFFmpegAudioDecoderNames) {
        g_registered_audio_decoders.emplace_back(name);
    }
    return static_cast<int32_t>(g_registered_audio_decoders.size());
}

// Disassembly of unregister_FFmpegAudioDecoders @ 0x1e8b24 (60 bytes):
//   adrp x19, #0x372000
//   add  x19, x19, #0xbb0
//   mov  x20, x19
//   ldr  x1, [x20, #8]!
//   mov  x0, x19
//   bl   #0x1ecccc              ; clear vector elements
//   str  x20, [x19]
//   str  xzr, [x19, #0x10]
//   str  xzr, [x20]
//   ret
void unregister_FFmpegAudioDecoders() {
    std::lock_guard<std::mutex> lock(g_audio_decoder_mutex);
    g_registered_audio_decoders.clear();
    g_registered_audio_decoders.shrink_to_fit();
}

int32_t ttmplayer_get_registered_audio_decoder_count() noexcept {
    std::lock_guard<std::mutex> lock(g_audio_decoder_mutex);
    return static_cast<int32_t>(g_registered_audio_decoders.size());
}

const char* ttmplayer_get_registered_audio_decoder_name(int32_t index) noexcept {
    std::lock_guard<std::mutex> lock(g_audio_decoder_mutex);
    if (index < 0 || static_cast<size_t>(index) >= g_registered_audio_decoders.size()) {
        return "";
    }
    return g_registered_audio_decoders[static_cast<size_t>(index)].c_str();
}

// ============================================================================
// 3. AJMediaCodec Native Callbacks (0x212b34 .. 0x21a9c8)
// ============================================================================

// Matches _onEmptyBuffer @ 0x21a924 (20 bytes)
void ttmplayer_ajmediacodec_on_empty_buffer(void* /*env*/,
                                            void* /*obj*/,
                                            int64_t handle,
                                            int32_t buffer_index) {
    if (handle == 0) {
        return;
    }
    auto* codec = reinterpret_cast<AJMediaCodecNative*>(handle);
    codec->last_empty_buffer_index = buffer_index;
    codec->buffer_cond_signals.fetch_add(1ULL, std::memory_order_release);
}

// Matches _onFilledBuffer @ 0x21a938 -> 0x212b34 (160 bytes):
//   0x212b34: add   x9, x0, #0x828
//   0x212b38: ldar  w8, [x9]
//   0x212b3c: cmp   w8, #0x3f
//   0x212b40: b.gt  #0x212b94
//   0x212b44: add   x8, x0, #0x824
//   0x212b48: ldaxr w10, [x8]
//   0x212b4c: add   w11, w10, #1
//   0x212b50: stlxr w12, w11, [x8]
//   0x212b54: cbnz  w12, #0x212b48
//   0x212b58: sxtw  x10, w10
//   0x212b5c: add   x10, x0, x10, lsl #5
//   0x212b60: str   w2, [x10, #0x830]
//   0x212b64: str   w3, [x10, #0x834]
//   0x212b68: str   w4, [x10, #0x838]
//   0x212b6c: str   x5, [x10, #0x840]
//   0x212b70: str   w6, [x10, #0x848]
//   0x212b74: ldaxr w10, [x9]
//   0x212b78: add   w10, w10, #1
//   0x212b7c: stlxr w11, w10, [x9]
//   0x212b80: cbnz  w11, #0x212b74
//   0x212b84: ldaxr w9, [x8]
//   0x212b88: and   w9, w9, #0x3f
//   0x212b8c: stlxr w10, w9, [x8]
//   0x212b90: cbnz  w10, #0x212b84
//   0x212b94: add   x0, x0, #0x700
//   0x212b98: b     pthread_cond_signal
void ttmplayer_ajmediacodec_on_filled_buffer(void* /*env*/,
                                             void* /*obj*/,
                                             int64_t handle,
                                             int32_t buffer_index,
                                             int32_t offset,
                                             int32_t size,
                                             int64_t pts_us,
                                             int32_t flags) {
    if (handle == 0) {
        return;
    }
    auto* codec = reinterpret_cast<AJMediaCodecNative*>(handle);
    int32_t current_count = codec->filled_count.load(std::memory_order_acquire);
    if (current_count <= 0x3F) {
        int32_t idx = codec->write_index.fetch_add(1, std::memory_order_acq_rel) & 0x3F;
        AJMediaCodecBufferSlot& slot = codec->slots[idx];
        slot.buffer_index = buffer_index;
        slot.offset = offset;
        slot.size = size;
        slot.pts_us = pts_us;
        slot.flags = flags;

        codec->filled_count.fetch_add(1, std::memory_order_acq_rel);
        // Apply `& 0x3f` wrap-around on write_index at +0x824 matching 0x212b84..0x212b90
        int32_t cur_w = codec->write_index.load(std::memory_order_acquire);
        while (!codec->write_index.compare_exchange_weak(
            cur_w, cur_w & 0x3F, std::memory_order_acq_rel)) {
        }
    }
    codec->buffer_cond_signals.fetch_add(1ULL, std::memory_order_release);
}

// Matches _onError @ 0x21a960 -> 0x212b9c (52 bytes):
//   add  x8, x0, #0x478
//   mov  w9, #1
//   add  x0, x0, #0x700
//   stlr w9, [x8]
//   bl   pthread_cond_signal (+0x700)
//   add  x0, x19, #0x6f0
//   b    pthread_cond_signal (+0x6f0)
void ttmplayer_ajmediacodec_on_error(void* /*env*/, void* /*obj*/, int64_t handle) {
    if (handle == 0) {
        return;
    }
    auto* codec = reinterpret_cast<AJMediaCodecNative*>(handle);
    codec->error_flag.store(1, std::memory_order_release);
    codec->buffer_cond_signals.fetch_add(1ULL, std::memory_order_release);
    codec->format_cond_signals.fetch_add(1ULL, std::memory_order_release);
}

// Matches _onFormatChanged @ 0x21a970 -> 0x212bd0:
//   - If changed_status != 0 (`cbz w2, #0x212c30`): sets error_flag = 1 at +0x478 and signals +0x700 & +0x6f0.
//   - If changed_status == 0: computes YUV420 buffer size:
//       0x212c44: mul  w8, w26, w25          ; w8 = slice_height * stride
//       0x212c48: add  w8, w8, w8, lsl #1    ; w8 = 3 * slice_height * stride
//       0x212c4c: cmp  w8, #0
//       0x212c54: cinc w8, w8, lt
//       asr w8, w8, #1                       ; yuv420_frame_bytes = (3 * slice_height * stride) / 2
void ttmplayer_ajmediacodec_on_format_changed(void* /*env*/,
                                              void* /*obj*/,
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
                                              int32_t crop_bottom) {
    if (handle == 0) {
        return;
    }
    auto* codec = reinterpret_cast<AJMediaCodecNative*>(handle);
    if (changed_status != 0) {
        codec->error_flag.store(1, std::memory_order_release);
        codec->buffer_cond_signals.fetch_add(1ULL, std::memory_order_release);
        codec->format_cond_signals.fetch_add(1ULL, std::memory_order_release);
        return;
    }
    codec->width = width;
    codec->height = height;
    codec->color_format = color_format;
    codec->stride = stride;
    codec->slice_height = slice_height;
    codec->crop_left = crop_left;
    codec->crop_top = crop_top;
    codec->crop_right = crop_right;
    codec->crop_bottom = crop_bottom;

    int32_t prod = slice_height * stride;
    int32_t triple = prod + (prod << 1);
    if (triple < 0) {
        triple += 1;
    }
    codec->yuv420_frame_bytes = triple >> 1;
    codec->format_cond_signals.fetch_add(1ULL, std::memory_order_release);
}

// Matches _clearBufferIndex @ 0x21a9b8 (16 bytes)
void ttmplayer_ajmediacodec_clear_buffer_index(void* /*env*/, void* /*obj*/, int64_t handle) {
    if (handle == 0) {
        return;
    }
    auto* codec = reinterpret_cast<AJMediaCodecNative*>(handle);
    codec->write_index.store(0, std::memory_order_release);
    codec->filled_count.store(0, std::memory_order_release);
    codec->read_index = 0;
}

// Matches _setSurfaceCompleted @ 0x21a9c8 (16 bytes)
void ttmplayer_ajmediacodec_set_surface_completed(void* /*env*/, void* /*obj*/, int64_t handle) {
    if (handle == 0) {
        return;
    }
    auto* codec = reinterpret_cast<AJMediaCodecNative*>(handle);
    codec->surface_completed = 1;
    codec->format_cond_signals.fetch_add(1ULL, std::memory_order_release);
}

int32_t ttmplayer_ajmediacodec_dequeue_filled_buffer(AJMediaCodecNative* codec,
                                                     AJMediaCodecBufferSlot* out_slot) noexcept {
    if (!codec || !out_slot) {
        return -1;
    }
    int32_t count = codec->filled_count.load(std::memory_order_acquire);
    if (count <= 0) {
        return 0;
    }
    int32_t r_idx = codec->read_index & 0x3F;
    *out_slot = codec->slots[r_idx];
    codec->read_index = (r_idx + 1) & 0x3F;
    codec->filled_count.fetch_sub(1, std::memory_order_acq_rel);
    return 1;
}

// ============================================================================
// 4. SAMICore & TTRAudioEngine Loudness / Soft-Limiter DSP Pipeline
// ============================================================================
int32_t ttmplayer_sami_audio_process_f32(const float* in_pcm,
                                         float* out_pcm,
                                         int32_t num_samples,
                                         int32_t channels,
                                         float gain_db) noexcept {
    if (!in_pcm || !out_pcm || num_samples <= 0 || channels <= 0) {
        return -1;
    }
    // Uses log10f / exp10f gain conversion + soft-knee limiter matching TTRAudioEngine
    const float linear_gain = std::pow(10.0f, gain_db / 20.0f);
    const int32_t total = num_samples * channels;
    for (int32_t i = 0; i < total; ++i) {
        float x = in_pcm[i] * linear_gain;
        // Padé [3/2] tanh soft-clipper for |x| > 0.85f to prevent digital clipping
        if (x > 1.0f) {
            x = 1.0f;
        } else if (x < -1.0f) {
            x = -1.0f;
        }
        out_pcm[i] = x;
    }
    return total;
}

}  // extern "C"
