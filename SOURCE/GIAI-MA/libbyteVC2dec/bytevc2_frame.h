/**
 * @file bytevc2_frame.h
 * @brief Decoded Picture Frame Buffer and Plane Layout Management for ByteVC2
 *        Quản lý đệm khung hình đã giải mã và bố cục mặt phẳng ảnh cho ByteVC2
 *
 * Implements frame allocation, planar YUV management, and property queries matching libbyteVC2dec.so.
 * Thực thi cấp phát khung hình, quản lý YUV phẳng và truy vấn thuộc tính khớp với libbyteVC2dec.so.
 */

#ifndef BYTEVC2_FRAME_H
#define BYTEVC2_FRAME_H

#include "bytevc2_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Allocate a new decoded frame container
 *        Cấp phát bộ chứa khung hình giải mã mới
 * @return Pointer to allocated ByteVC2Frame or NULL
 *         Con trỏ tới ByteVC2Frame đã cấp phát hoặc NULL
 */
ByteVC2Frame* byteVC2dec_alloc_frame(void);

/**
 * @brief Release decoded frame structure and internal planes
 *        Giải phóng cấu trúc khung hình và các mặt phẳng bên trong
 * @param frame Pointer to frame to release / Con trỏ khung hình cần giải phóng
 */
void byteVC2dec_release_frame(ByteVC2Frame* frame);

/**
 * @brief Query integer property from decoded frame
 *        Truy vấn thuộc tính số nguyên từ khung hình giải mã
 * @param frame Pointer to frame / Con trỏ khung hình
 * @param key Property name string / Chuỗi tên thuộc tính
 * @param plane_index Sub-index or plane index (0=Y, 1=U, 2=V) / Chỉ số mặt phẳng (0=Y, 1=U, 2=V)
 * @return Integer value or 0 on error
 *         Giá trị nguyên hoặc 0 khi lỗi
 */
int64_t byteVC2dec_get_frame_integer_info(const ByteVC2Frame* frame, const char* key, int32_t plane_index);

/**
 * @brief Query floating-point property from decoded frame
 *        Truy vấn thuộc tính số thực từ khung hình giải mã
 * @param frame Pointer to frame / Con trỏ khung hình
 * @param key Property name string / Chuỗi tên thuộc tính
 * @return Always returns 0.0f / Luôn trả về 0.0f
 */
float byteVC2dec_get_frame_float_info(const ByteVC2Frame* frame, const char* key);

/**
 * @brief Query pointer property from decoded frame (data plane or hardware buffer)
 *        Truy vấn thuộc tính con trỏ từ khung hình (mặt phẳng dữ liệu hoặc đệm phần cứng)
 * @param frame Pointer to frame / Con trỏ khung hình
 * @param key Property name ("data" or "hardware_buffer") / Tên thuộc tính ("data" hoặc "hardware_buffer")
 * @param plane_index Plane index (0=Y, 1=U, 2=V) for "data" / Chỉ số mặt phẳng (0..2) cho "data"
 * @return Pointer to buffer or NULL / Con trỏ vùng đệm hoặc NULL
 */
void* byteVC2dec_get_frame_pointer_info(const ByteVC2Frame* frame, const char* key, int32_t plane_index);

/**
 * @brief Allocate planar memory for frame with given dimensions
 *        Cấp phát bộ nhớ phẳng cho khung hình với kích thước cho trước
 * @param frame Frame to allocate buffers for / Khung hình cần cấp phát đệm
 * @param width Luma width / Chiều rộng độ sáng
 * @param height Luma height / Chiều cao độ sáng
 * @param pix_fmt Pixel format / Định dạng pixel
 * @return 0 on success, -1 on failure / 0 nếu thành công, -1 nếu lỗi
 */
int32_t bytevc2_frame_alloc_buffers(ByteVC2Frame* frame, int32_t width, int32_t height, ByteVC2PixelFormat pix_fmt);

#ifdef __cplusplus
}
#endif

#endif // BYTEVC2_FRAME_H
