/**
 * @file ttheif_anim.h
 * @brief Multi-Frame Animated HEIF Sequence Decoder Header
 *        Tiêu đề bộ giải mã chuỗi ảnh động đa khung hình Animated HEIF
 *
 * Implements frame track indexing, access unit slicing, and sequential decoding.
 * Triển khai chỉ mục track khung hình, phân đoạn access unit và giải mã tuần tự.
 */

#ifndef TTHEIF_ANIM_H
#define TTHEIF_ANIM_H

#include "ttheif_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// Animation Decoder Lifecycle / Vòng đời bộ giải mã hoạt ảnh
void* heif_anim_decoder_init(void);
void heif_anim_decoder_close(void* decoder);

// Context management / Quản lý ngữ cảnh
int heif_anim_heif_ctx_init(heif_anim_context_t** ctx, const uint8_t* data, size_t size);
void heif_anim_heif_ctx_release(heif_anim_context_t* ctx);

// Container and Bitstream Parsing / Phân tích container và luồng bitstream
int heif_anim_parse_heif_box(heif_anim_context_t* ctx);
int heif_anim_parse_bytevc1_stream(heif_anim_context_t* ctx);

// Playback and Packet Query / Truy vấn phát và gói dữ liệu
int heif_anim_get_current_frame_index(const heif_anim_context_t* ctx);
int heif_anim_get_one_packet(heif_anim_context_t* ctx, uint8_t** out_pkt, size_t* out_pkt_len);

// Frame Decoding / Giải mã khung hình
int heif_anim_decode_one_frame(heif_anim_context_t* ctx);
int heif_anim_decode_one_frame_opt(heif_anim_context_t* ctx);
int heif_anim_decode_to_rgba(heif_anim_context_t* ctx, heif_output_stream_t** out_stream);
int heif_anim_decode_to_rgba_opt(heif_anim_context_t* ctx, heif_output_stream_t** out_stream);
int heif_anim_decode_to_rgb(heif_anim_context_t* ctx, heif_output_stream_t** out_stream);
int heif_anim_decode_to_yuv420p(heif_anim_context_t* ctx, heif_output_stream_t** out_stream);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_ANIM_H