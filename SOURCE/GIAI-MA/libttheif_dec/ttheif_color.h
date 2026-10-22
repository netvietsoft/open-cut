/**
 * @file ttheif_color.h
 * @brief High-Performance YUV to RGB Color Space Conversion Engine
 *        Động cơ chuyển đổi không gian màu YUV sang RGB hiệu năng cao
 *
 * Implements BT.601 / BT.709 color matrices for RGBA8888, RGB888, and RGB565.
 * Triển khai ma trận màu BT.601 / BT.709 cho RGBA8888, RGB888, và RGB565.
 */

#ifndef TTHEIF_COLOR_H
#define TTHEIF_COLOR_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Convert YUV420P planar frame to 32-bit RGBA8888 packed buffer
 *        Chuyển đổi khung hình phẳng YUV420P sang vùng nhớ đóng gói 32-bit RGBA8888
 * @param y_plane Pointer to Y luminance plane / Con trỏ mặt phẳng Y
 * @param u_plane Pointer to U chroma plane / Con trỏ mặt phẳng U
 * @param v_plane Pointer to V chroma plane / Con trỏ mặt phẳng V
 * @param y_stride Stride of Y plane / Bước nhảy dòng mặt phẳng Y
 * @param uv_stride Stride of U and V planes / Bước nhảy dòng U và V
 * @param width Image width / Chiều rộng ảnh
 * @param height Image height / Chiều cao ảnh
 * @param dst_rgba Output RGBA buffer / Bộ đệm RGBA đầu ra
 * @param dst_stride Row stride of destination / Bước nhảy dòng đầu ra
 */
void ttheif_yuv420p_to_rgba(const uint8_t* y_plane, const uint8_t* u_plane, const uint8_t* v_plane,
                            uint32_t y_stride, uint32_t uv_stride,
                            uint32_t width, uint32_t height,
                            uint8_t* dst_rgba, uint32_t dst_stride);

/**
 * @brief Convert YUV420P planar frame to 24-bit RGB888 packed buffer
 *        Chuyển đổi khung hình phẳng YUV420P sang vùng nhớ đóng gói 24-bit RGB888
 */
void ttheif_yuv420p_to_rgb(const uint8_t* y_plane, const uint8_t* u_plane, const uint8_t* v_plane,
                           uint32_t y_stride, uint32_t uv_stride,
                           uint32_t width, uint32_t height,
                           uint8_t* dst_rgb, uint32_t dst_stride);

/**
 * @brief Convert YUV420P planar frame to 16-bit RGB565 packed buffer
 *        Chuyển đổi khung hình phẳng YUV420P sang vùng nhớ đóng gói 16-bit RGB565
 */
void ttheif_yuv420p_to_rgb565(const uint8_t* y_plane, const uint8_t* u_plane, const uint8_t* v_plane,
                              uint32_t y_stride, uint32_t uv_stride,
                              uint32_t width, uint32_t height,
                              uint16_t* dst_rgb565, uint32_t dst_stride_pixels);

#ifdef __cplusplus
}
#endif

#endif // TTHEIF_COLOR_H