// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Qualcomm FastCV Computer Vision SDK & GPU Image Processing
// File: fastcv_imgproc.cpp
// Description: Implementation of cvtColor, alphaBlend, downScale, copyMakeBorder,
//              copyROI, and combineAndConvertTo matching AArch64 opcodes.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "fastcv_imgproc.h"
#include <algorithm>
#include <cmath>
#include <cstring>

namespace FASTCV {
namespace EXPORTS {

/**
 * @brief cvtColor: Color space conversion engine.
 * EN: Matches AArch64 opcode 0x5e468 (156 bytes).
 *     Supports RGB/BGR/GRAY/YUV conversions with fixed-point arithmetic.
 * VN: Khớp opcode AArch64 0x5e468. Chuyển đổi không gian màu RGB, BGR, Grayscale và YUV.
 */
void cvtColor(const Mat& src, Mat& dst, int code, int dstCn) {
    if (src.empty()) {
        dst.release();
        return;
    }

    int rows = src.rows;
    int cols = src.cols;

    switch (code) {
        case COLOR_BGR2GRAY:
        case COLOR_RGB2GRAY: {
            dst = Mat(rows, cols, FCV_8UC1);
            bool is_bgr = (code == COLOR_BGR2GRAY);
            for (int r = 0; r < rows; ++r) {
                const uint8_t* s = src.ptr(r);
                uint8_t* d = dst.ptr(r);
                for (int c = 0; c < cols; ++c) {
                    uint8_t b = is_bgr ? s[c * 3 + 0] : s[c * 3 + 2];
                    uint8_t g = s[c * 3 + 1];
                    uint8_t red = is_bgr ? s[c * 3 + 2] : s[c * 3 + 0];
                    // Y = 0.299R + 0.587G + 0.114B (Fixed-point: (77R + 150G + 29B + 128) >> 8)
                    uint32_t y = (77 * red + 150 * g + 29 * b + 128) >> 8;
                    d[c] = static_cast<uint8_t>(std::min(255u, y));
                }
            }
            break;
        }
        case COLOR_GRAY2BGR:
        case COLOR_GRAY2RGB: {
            dst = Mat(rows, cols, FCV_8UC3);
            for (int r = 0; r < rows; ++r) {
                const uint8_t* s = src.ptr(r);
                uint8_t* d = dst.ptr(r);
                for (int c = 0; c < cols; ++c) {
                    uint8_t g = s[c];
                    d[c * 3 + 0] = g;
                    d[c * 3 + 1] = g;
                    d[c * 3 + 2] = g;
                }
            }
            break;
        }
        case COLOR_BGR2RGB: {
            dst = Mat(rows, cols, FCV_8UC3);
            for (int r = 0; r < rows; ++r) {
                const uint8_t* s = src.ptr(r);
                uint8_t* d = dst.ptr(r);
                for (int c = 0; c < cols; ++c) {
                    d[c * 3 + 0] = s[c * 3 + 2];
                    d[c * 3 + 1] = s[c * 3 + 1];
                    d[c * 3 + 2] = s[c * 3 + 0];
                }
            }
            break;
        }
        case COLOR_RGB2RGBA:
        case COLOR_BGR2BGRA: {
            dst = Mat(rows, cols, FCV_8UC4);
            for (int r = 0; r < rows; ++r) {
                const uint8_t* s = src.ptr(r);
                uint8_t* d = dst.ptr(r);
                for (int c = 0; c < cols; ++c) {
                    d[c * 4 + 0] = s[c * 3 + 0];
                    d[c * 4 + 1] = s[c * 3 + 1];
                    d[c * 4 + 2] = s[c * 3 + 2];
                    d[c * 4 + 3] = 255;
                }
            }
            break;
        }
        case COLOR_RGBA2RGB:
        case COLOR_BGRA2BGR: {
            dst = Mat(rows, cols, FCV_8UC3);
            for (int r = 0; r < rows; ++r) {
                const uint8_t* s = src.ptr(r);
                uint8_t* d = dst.ptr(r);
                for (int c = 0; c < cols; ++c) {
                    d[c * 3 + 0] = s[c * 4 + 0];
                    d[c * 3 + 1] = s[c * 4 + 1];
                    d[c * 3 + 2] = s[c * 4 + 2];
                }
            }
            break;
        }
        case COLOR_YUV2RGB_NV12:
        case COLOR_YUV2RGB_NV21: {
            // Mobile camera preview decoding: Y plane followed by interleaved UV/VU plane
            int y_rows = rows * 2 / 3;
            dst = Mat(y_rows, cols, FCV_8UC3);
            const uint8_t* y_plane = src.ptr(0);
            const uint8_t* uv_plane = y_plane + y_rows * cols;
            bool is_nv21 = (code == COLOR_YUV2RGB_NV21);

            for (int r = 0; r < y_rows; ++r) {
                uint8_t* d = dst.ptr(r);
                int uv_row = r / 2;
                for (int c = 0; c < cols; ++c) {
                    int uv_col = (c / 2) * 2;
                    int y_val = y_plane[r * cols + c];
                    int u_val = is_nv21 ? uv_plane[uv_row * cols + uv_col + 1] : uv_plane[uv_row * cols + uv_col];
                    int v_val = is_nv21 ? uv_plane[uv_row * cols + uv_col] : uv_plane[uv_row * cols + uv_col + 1];

                    int c_y = y_val - 16;
                    int d_u = u_val - 128;
                    int e_v = v_val - 128;

                    int red   = (298 * c_y + 409 * e_v + 128) >> 8;
                    int green = (298 * c_y - 100 * d_u - 208 * e_v + 128) >> 8;
                    int blue  = (298 * c_y + 516 * d_u + 128) >> 8;

                    d[c * 3 + 0] = static_cast<uint8_t>(std::max(0, std::min(255, red)));
                    d[c * 3 + 1] = static_cast<uint8_t>(std::max(0, std::min(255, green)));
                    d[c * 3 + 2] = static_cast<uint8_t>(std::max(0, std::min(255, blue)));
                }
            }
            break;
        }
        default:
            src.copyTo(dst);
            break;
    }
}

void cvtColor(const UMat& src, UMat& dst, int code, int dstCn) {
    Mat src_mat = src.getMat();
    Mat dst_mat;
    cvtColor(src_mat, dst_mat, code, dstCn);
    dst = UMat(dst_mat.rows, dst_mat.cols, dst_mat.type_);
    dst_mat.copyTo(dst.getMat());
}

/**
 * @brief alphaBlend: Alpha blending between two images.
 * EN: Matches AArch64 opcode 0x5f598 (156 bytes).
 *     Formula: dst = (src1 * alpha + src2 * (255 - alpha)) / 255.
 * VN: Khớp opcode AArch64 0x5f598. Hòa trộn alpha giữa hai hình ảnh theo mặt nạ độ mờ đục.
 */
void alphaBlend(const Mat& src1, const Mat& src2, const Mat& alpha, Mat& dst) {
    if (src1.empty() || src2.empty() || alpha.empty()) {
        dst.release();
        return;
    }

    int rows = src1.rows;
    int cols = src1.cols;
    int cn = src1.channels();

    dst = Mat(rows, cols, src1.type_);

    for (int r = 0; r < rows; ++r) {
        const uint8_t* p1 = src1.ptr(r);
        const uint8_t* p2 = src2.ptr(r);
        const uint8_t* pa = alpha.ptr(r);
        uint8_t* pd = dst.ptr(r);

        for (int c = 0; c < cols; ++c) {
            uint32_t a = pa[c]; // 0 to 255
            uint32_t inv_a = 255 - a;

            for (int k = 0; k < cn; ++k) {
                uint32_t v1 = p1[c * cn + k];
                uint32_t v2 = p2[c * cn + k];
                uint32_t out = (v1 * a + v2 * inv_a + 128) / 255;
                pd[c * cn + k] = static_cast<uint8_t>(std::min(255u, out));
            }
        }
    }
}

/**
 * @brief combineAndConvertTo: Merges 4 single-channel planes into an interleaved image.
 * EN: Matches AArch64 opcode 0x5f76c (576 bytes).
 * VN: Khớp opcode AArch64 0x5f76c. Ghép 4 mặt phẳng đơn kênh thành hình ảnh 4 kênh đan xen.
 */
void combineAndConvertTo(const UMat& p0, const UMat& p1, const UMat& p2,
                         const UMat& p3, UMat& dst, int flags) {
    Mat m0 = p0.getMat();
    Mat m1 = p1.getMat();
    Mat m2 = p2.getMat();
    Mat m3 = p3.getMat();

    if (m0.empty() || m1.empty() || m2.empty() || m3.empty()) {
        dst = UMat();
        return;
    }

    int rows = m0.rows;
    int cols = m0.cols;
    Mat merged(rows, cols, FCV_8UC4);

    for (int r = 0; r < rows; ++r) {
        const uint8_t* s0 = m0.ptr(r);
        const uint8_t* s1 = m1.ptr(r);
        const uint8_t* s2 = m2.ptr(r);
        const uint8_t* s3 = m3.ptr(r);
        uint8_t* d = merged.ptr(r);

        for (int c = 0; c < cols; ++c) {
            d[c * 4 + 0] = s0[c];
            d[c * 4 + 1] = s1[c];
            d[c * 4 + 2] = s2[c];
            d[c * 4 + 3] = s3[c];
        }
    }

    dst = UMat(rows, cols, FCV_8UC4);
    merged.copyTo(dst.getMat());
}

/**
 * @brief downScale: Downsamples image dimensions with bilinear/area filtering.
 * EN: Matches AArch64 opcode 0x60880 (588 bytes).
 * VN: Khớp opcode AArch64 0x60880. Thu nhỏ kích thước ảnh mượt mà bảo toàn chi tiết góc cạnh.
 */
void downScale(const Mat& src, Mat& dst, float fx, float fy) {
    if (src.empty() || fx <= 0.0f || fy <= 0.0f) {
        dst.release();
        return;
    }

    int dst_cols = std::max(1, static_cast<int>(std::round(src.cols * fx)));
    int dst_rows = std::max(1, static_cast<int>(std::round(src.rows * fy)));
    int cn = src.channels();

    dst = Mat(dst_rows, dst_cols, src.type_);

    float scale_x = static_cast<float>(src.cols) / dst_cols;
    float scale_y = static_cast<float>(src.rows) / dst_rows;

    for (int r = 0; r < dst_rows; ++r) {
        float src_y = (r + 0.5f) * scale_y - 0.5f;
        int y0 = std::max(0, std::min(src.rows - 1, static_cast<int>(std::floor(src_y))));
        int y1 = std::max(0, std::min(src.rows - 1, y0 + 1));
        float dy = src_y - y0;

        uint8_t* d_row = dst.ptr(r);
        const uint8_t* s_row0 = src.ptr(y0);
        const uint8_t* s_row1 = src.ptr(y1);

        for (int c = 0; c < dst_cols; ++c) {
            float src_x = (c + 0.5f) * scale_x - 0.5f;
            int x0 = std::max(0, std::min(src.cols - 1, static_cast<int>(std::floor(src_x))));
            int x1 = std::max(0, std::min(src.cols - 1, x0 + 1));
            float dx = src_x - x0;

            float w00 = (1.0f - dx) * (1.0f - dy);
            float w01 = dx * (1.0f - dy);
            float w10 = (1.0f - dx) * dy;
            float w11 = dx * dy;

            for (int k = 0; k < cn; ++k) {
                float val = s_row0[x0 * cn + k] * w00 +
                            s_row0[x1 * cn + k] * w01 +
                            s_row1[x0 * cn + k] * w10 +
                            s_row1[x1 * cn + k] * w11;
                d_row[c * cn + k] = static_cast<uint8_t>(std::max(0.0f, std::min(255.0f, std::round(val))));
            }
        }
    }
}

void downScale(const UMat& src, UMat& dst, float fx, float fy) {
    Mat src_mat = src.getMat();
    Mat dst_mat;
    downScale(src_mat, dst_mat, fx, fy);
    dst = UMat(dst_mat.rows, dst_mat.cols, dst_mat.type_);
    dst_mat.copyTo(dst.getMat());
}

/**
 * @brief copyMakeBorder: Extends image borders with specified padding mode.
 * EN: Matches AArch64 opcode 0x5f18c (880 bytes).
 * VN: Khớp opcode AArch64 0x5f18c. Mở rộng đường viền ảnh (Constant padding hoặc Replicate).
 */
void copyMakeBorder(const Mat& src, Mat& dst, int top, int bottom,
                    int left, int right, int borderType, const Scalar& value) {
    if (src.empty()) {
        dst.release();
        return;
    }

    int dst_rows = src.rows + top + bottom;
    int dst_cols = src.cols + left + right;
    int cn = src.channels();

    dst = Mat(dst_rows, dst_cols, src.type_);

    for (int r = 0; r < dst_rows; ++r) {
        int src_r;
        if (r < top) {
            src_r = (borderType == BORDER_REPLICATE) ? 0 : -1;
        } else if (r >= top + src.rows) {
            src_r = (borderType == BORDER_REPLICATE) ? (src.rows - 1) : -1;
        } else {
            src_r = r - top;
        }

        uint8_t* d_row = dst.ptr(r);

        for (int c = 0; c < dst_cols; ++c) {
            int src_c;
            if (c < left) {
                src_c = (borderType == BORDER_REPLICATE) ? 0 : -1;
            } else if (c >= left + src.cols) {
                src_c = (borderType == BORDER_REPLICATE) ? (src.cols - 1) : -1;
            } else {
                src_c = c - left;
            }

            if (src_r >= 0 && src_c >= 0) {
                const uint8_t* s_pixel = src.ptr(src_r) + src_c * cn;
                for (int k = 0; k < cn; ++k) {
                    d_row[c * cn + k] = s_pixel[k];
                }
            } else {
                // Constant border
                for (int k = 0; k < cn; ++k) {
                    d_row[c * cn + k] = static_cast<uint8_t>(value[k]);
                }
            }
        }
    }
}

void copyMakeBorder(const UMat& src, UMat& dst, int top, int bottom,
                    int left, int right, int borderType, const Scalar& value) {
    Mat src_mat = src.getMat();
    Mat dst_mat;
    copyMakeBorder(src_mat, dst_mat, top, bottom, left, right, borderType, value);
    dst = UMat(dst_mat.rows, dst_mat.cols, dst_mat.type_);
    dst_mat.copyTo(dst.getMat());
}

/**
 * @brief copyROI: Blits rectangular region into target matrix.
 * EN: Matches AArch64 opcode 0x5fa48 (492 bytes).
 * VN: Khớp opcode AArch64 0x5fa48. Sao chép vùng chữ nhật con ROI sang ma trận đích.
 */
void copyROI(const Mat& src, Mat& dst, int x, int y, int width, int height) {
    if (src.empty() || width <= 0 || height <= 0) {
        dst.release();
        return;
    }

    int cl = std::max(0, std::min(src.cols - 1, x));
    int ct = std::max(0, std::min(src.rows - 1, y));
    int w = std::min(width, src.cols - cl);
    int h = std::min(height, src.rows - ct);

    dst = Mat(h, w, src.type_);
    int cn = src.channels();
    size_t line_bytes = static_cast<size_t>(w) * cn * src.elemSize1();

    for (int r = 0; r < h; ++r) {
        const uint8_t* s = src.ptr(ct + r) + cl * cn * src.elemSize1();
        uint8_t* d = dst.ptr(r);
        std::memcpy(d, s, line_bytes);
    }
}

} // namespace EXPORTS
} // namespace FASTCV
