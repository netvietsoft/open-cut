/**
 * @file ttheif_vvif.h
 * @brief Versatile Video Image Format (VVIF / H.266 / ByteVC2) Decoder Header
 *        Tiêu đề bộ giải mã định dạng ảnh và hoạt ảnh VVIF (ByteVC2/VVC)
 *
 * Cleanroom implementation reconstructed from ByteDance libttheif_dec.so (AArch64).
 * Tái cấu trúc phòng sạch từ libttheif_dec.so (AArch64) của ByteDance.
 */

#ifndef TTHEIF_VVIF_H
#define TTHEIF_VVIF_H

#include "ttheif_types.h"

#ifdef __cplusplus
extern "C" {
#endif

// File Type & Metadata / Kiểu tệp & Siêu dữ liệu VVIF
int vvif_judge_file_type(const uint8_t* data, size_t size);
int vvif_parse_meta(const uint8_t* data, size_t size, heif_image_meta_t* meta);

// VVIF Static Image Decoding - RGBA / Giải mã ảnh tĩnh VVIF sang RGBA
int vvif_decode_to_rgba(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int vvif_decode_to_rgba_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int vvif_decode_to_rgba_extern_buffer(const uint8_t* data, size_t size, uint8_t* ext_buf, uint32_t stride);
int vvif_decode_to_rgba_ext_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);

// VVIF Static Image Decoding - RGB565 / Giải mã ảnh tĩnh VVIF sang RGB565
int vvif_decode_to_rgb565(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int vvif_decode_to_rgb565_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int vvif_decode_to_rgb565_extern_buffer(const uint8_t* data, size_t size, uint16_t* ext_buf, uint32_t stride_pixels);
int vvif_decode_to_rgb565_ext_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);

// VVIF Bitstream & YUV Decoding / Giải mã luồng bitstream và YUV VVIF
int vvif_decode_to_yuv420p(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int vvif_decode_to_bytevc2(const uint8_t* data, size_t size, uint8_t** out_nal, size_t* out_nal_len);
int vvif_decode_bs_to_yuv(const uint8_t* bs_data, size_t bs_len, heif_output_stream_t** out_stream);

// VVIF Animation Context & Playback / Hoạt ảnh động VVIF
int vvif_anim_vvif_ctx_init(heif_anim_context_t** ctx, const uint8_t* data, size_t size);
void vvif_anim_vvif_ctx_release(heif_anim_context_t* ctx);
int vvif_anim_parse_vvif_box(heif_anim_context_t* ctx);
int vvif_anim_get_current_frame_index(const heif_anim_context_t* ctx);
int vvif_anim_decode_one_frame(heif_anim_context_t* ctx);

// Muxing Utility / Tiện ích đóng gói luồng VVC sang container VVIF
int mux_vvc_to_vvif(const uint8_t* vvc_stream, size_t vvc_len,
                    uint32_t width, uint32_t height,
                    uint8_t** out_vvif, size_t* out_vvif_len);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_VVIF_H