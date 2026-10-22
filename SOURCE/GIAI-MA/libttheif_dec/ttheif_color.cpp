/**
 * @file ttheif_color.cpp
 * @brief High-Performance YUV to RGB Color Space Conversion Implementation
 *        Triển khai động cơ chuyển đổi không gian màu YUV sang RGB hiệu năng cao
 *
 * Cleanroom implementation reconstructed from ByteDance libttheif_dec.so (AArch64).
 * Tái cấu trúc phòng sạch từ libttheif_dec.so (AArch64) của ByteDance.
 */

#include "ttheif_color.h"

static inline uint8_t clamp_u8(int32_t val) {
    if (val < 0) return 0;
    if (val > 255) return 255;
    return (uint8_t)val;
}

/**
 * Standard BT.601 YUV to RGB Conversion Matrix (Integer Scaled by 1024):
 *   C = Y - 16
 *   D = U - 128
 *   E = V - 128
 *   R = clamp((298 * C + 409 * E + 128) >> 8)
 *   G = clamp((298 * C - 100 * D - 208 * E + 128) >> 8)
 *   B = clamp((298 * C + 516 * D + 128) >> 8)
 */
void ttheif_yuv420p_to_rgba(const uint8_t* y_plane, const uint8_t* u_plane, const uint8_t* v_plane,
                            uint32_t y_stride, uint32_t uv_stride,
                            uint32_t width, uint32_t height,
                            uint8_t* dst_rgba, uint32_t dst_stride) {
    for (uint32_t j = 0; j < height; ++j) {
        const uint8_t* py = y_plane + j * y_stride;
        const uint8_t* pu = u_plane + (j / 2) * uv_stride;
        const uint8_t* pv = v_plane + (j / 2) * uv_stride;
        uint8_t* pdst = dst_rgba + j * dst_stride;

        for (uint32_t i = 0; i < width; ++i) {
            int32_t c = (int32_t)py[i] - 16;
            int32_t d = (int32_t)pu[i / 2] - 128;
            int32_t e = (int32_t)pv[i / 2] - 128;

            int32_t r = (298 * c + 409 * e + 128) >> 8;
            int32_t g = (298 * c - 100 * d - 208 * e + 128) >> 8;
            int32_t b = (298 * c + 516 * d + 128) >> 8;

            pdst[i * 4 + 0] = clamp_u8(r);
            pdst[i * 4 + 1] = clamp_u8(g);
            pdst[i * 4 + 2] = clamp_u8(b);
            pdst[i * 4 + 3] = 255; // Full opacity alpha / Độ mờ đục tối đa
        }
    }
}

void ttheif_yuv420p_to_rgb(const uint8_t* y_plane, const uint8_t* u_plane, const uint8_t* v_plane,
                           uint32_t y_stride, uint32_t uv_stride,
                           uint32_t width, uint32_t height,
                           uint8_t* dst_rgb, uint32_t dst_stride) {
    for (uint32_t j = 0; j < height; ++j) {
        const uint8_t* py = y_plane + j * y_stride;
        const uint8_t* pu = u_plane + (j / 2) * uv_stride;
        const uint8_t* pv = v_plane + (j / 2) * uv_stride;
        uint8_t* pdst = dst_rgb + j * dst_stride;

        for (uint32_t i = 0; i < width; ++i) {
            int32_t c = (int32_t)py[i] - 16;
            int32_t d = (int32_t)pu[i / 2] - 128;
            int32_t e = (int32_t)pv[i / 2] - 128;

            int32_t r = (298 * c + 409 * e + 128) >> 8;
            int32_t g = (298 * c - 100 * d - 208 * e + 128) >> 8;
            int32_t b = (298 * c + 516 * d + 128) >> 8;

            pdst[i * 3 + 0] = clamp_u8(r);
            pdst[i * 3 + 1] = clamp_u8(g);
            pdst[i * 3 + 2] = clamp_u8(b);
        }
    }
}

void ttheif_yuv420p_to_rgb565(const uint8_t* y_plane, const uint8_t* u_plane, const uint8_t* v_plane,
                              uint32_t y_stride, uint32_t uv_stride,
                              uint32_t width, uint32_t height,
                              uint16_t* dst_rgb565, uint32_t dst_stride_pixels) {
    for (uint32_t j = 0; j < height; ++j) {
        const uint8_t* py = y_plane + j * y_stride;
        const uint8_t* pu = u_plane + (j / 2) * uv_stride;
        const uint8_t* pv = v_plane + (j / 2) * uv_stride;
        uint16_t* pdst = dst_rgb565 + j * dst_stride_pixels;

        for (uint32_t i = 0; i < width; ++i) {
            int32_t c = (int32_t)py[i] - 16;
            int32_t d = (int32_t)pu[i / 2] - 128;
            int32_t e = (int32_t)pv[i / 2] - 128;

            uint32_t r = clamp_u8((298 * c + 409 * e + 128) >> 8);
            uint32_t g = clamp_u8((298 * c - 100 * d - 208 * e + 128) >> 8);
            uint32_t b = clamp_u8((298 * c + 516 * d + 128) >> 8);

            // RGB565 packing: 5 bits R, 6 bits G, 5 bits B
            // Đóng gói RGB565: 5 bit R, 6 bit G, 5 bit B
            pdst[i] = (uint16_t)(((r >> 3) << 11) | ((g >> 2) << 5) | (b >> 3));
        }
    }
}
