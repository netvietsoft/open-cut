/**
 * @file ttheif_core.h
 * @brief ByteDance HEIF Core Decoder API Declarations
 *        Khai báo API bộ giải mã ảnh tĩnh HEIF cốt lõi của ByteDance
 *
 * Cleanroom implementation reconstructed from ByteDance libttheif_dec.so (AArch64).
 * Tái cấu trúc phòng sạch từ libttheif_dec.so (AArch64) của ByteDance.
 */

#ifndef TTHEIF_CORE_H
#define TTHEIF_CORE_H

#include "ttheif_types.h"
#include "ttheif_isobmff.h"
#include "ttheif_color.h"
#include "ttheif_exif.h"

#ifdef __cplusplus
extern "C" {
#endif

// Version and identification / Phiên bản và nhận diện định dạng
const char* heif_get_version(void);
int heif_judge_file_type(const uint8_t* data, size_t size);

// Metadata extraction / Bóc tách siêu dữ liệu
int heif_parse_meta(const uint8_t* data, size_t size, heif_image_meta_t* meta);
int heif_parse_simple_meta(const uint8_t* data, size_t size, uint32_t* width, uint32_t* height);
int heif_parse_thumb(const uint8_t* data, size_t size, uint32_t* thumb_width, uint32_t* thumb_height);

// Primary Image Decoding - RGBA / Giải mã ảnh chính sang RGBA
int heif_decode_to_rgba(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_to_rgba_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_to_rgba_ext_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_to_rgba_extern_buffer(const uint8_t* data, size_t size, uint8_t* ext_buf, uint32_t stride);

// Primary Image Decoding - RGB / Giải mã ảnh chính sang RGB888
int heif_decode_to_rgb(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);

// Primary Image Decoding - RGB565 / Giải mã ảnh chính sang RGB565
int heif_decode_to_rgb565(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_to_rgb565_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_to_rgb565_extern_buffer(const uint8_t* data, size_t size, uint16_t* ext_buf, uint32_t stride_pixels);
int heif_decode_to_rgb565_ext_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);

// Primary Image Decoding - YUV420P / Giải mã ảnh chính sang YUV420P
int heif_decode_to_yuv420p(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_to_bytevc1(const uint8_t* data, size_t size, uint8_t** out_nal, size_t* out_nal_len);

// Thumbnail Image Decoding / Giải mã ảnh thu nhỏ (Thumbnail)
int heif_decode_thumb_to_rgba(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_thumb_to_rgba_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);
int heif_decode_thumb_to_rgba_extern_buffer(const uint8_t* data, size_t size, uint8_t* ext_buf, uint32_t stride);
int heif_decode_thumb_to_rgba_ext_opt(const uint8_t* data, size_t size, heif_output_stream_t** out_stream);

// Utilities & Buffer Management / Tiện ích & Quản lý bộ đệm
int heif_repack_data(const uint8_t* in_data, size_t in_size, uint8_t* out_data, size_t* out_size);
void heif_release_output_stream(heif_output_stream_t* stream);
void heif_release_output_stream_extern(heif_output_stream_t* stream);
void release_heif_data(void* ptr);

// Underling ByteVC1 Decoder Lifecycle Bridge / Cầu nối vòng đời bộ giải mã ByteVC1
void* create_bytevc1_decoder(void);
void destroy_bytevc1_decoder(void* decoder);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_CORE_H