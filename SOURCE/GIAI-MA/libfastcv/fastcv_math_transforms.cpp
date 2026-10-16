// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Mathematical Transforms, DCT, Affine, & Thresholding
// File: fastcv_math_transforms.cpp
// Description: Implementation of threshold, absdiff, normalize, bitwise_and,
//              calcHist, getAffineTransform, dct, and idct.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "fastcv_math_transforms.h"
#include <cmath>
#include <algorithm>
#include <cstring>

namespace FASTCV {
namespace EXPORTS {

constexpr double kFastCVPi = 3.14159265358979323846;

/**
 * @brief threshold: Fixed-level thresholding of a grayscale matrix.
 * EN: Matches AArch64 opcode 0x607d4 (172 bytes).
 * VN: Khớp opcode AArch64 0x607d4. Phân ngưỡng nhị phân / cắt cụt giá trị ảnh.
 */
void threshold(const Mat& src, Mat& dst, double thresh, double maxval, int type) {
    if (src.empty()) {
        dst.release();
        return;
    }

    int rows = src.rows;
    int cols = src.cols;
    int cn = src.channels();
    dst = Mat(rows, cols, src.type_);

    uint8_t th = static_cast<uint8_t>(std::max(0.0, std::min(255.0, thresh)));
    uint8_t mv = static_cast<uint8_t>(std::max(0.0, std::min(255.0, maxval)));

    for (int r = 0; r < rows; ++r) {
        const uint8_t* s = src.ptr(r);
        uint8_t* d = dst.ptr(r);
        for (int c = 0; c < cols * cn; ++c) {
            uint8_t v = s[c];
            switch (type) {
                case THRESH_BINARY:
                    d[c] = (v > th) ? mv : 0;
                    break;
                case THRESH_BINARY_INV:
                    d[c] = (v > th) ? 0 : mv;
                    break;
                case THRESH_TRUNC:
                    d[c] = (v > th) ? th : v;
                    break;
                case THRESH_TOZERO:
                    d[c] = (v > th) ? v : 0;
                    break;
                case THRESH_TOZERO_INV:
                    d[c] = (v > th) ? 0 : v;
                    break;
                default:
                    d[c] = (v > th) ? mv : 0;
                    break;
            }
        }
    }
}

/**
 * @brief absdiff: Calculates per-element absolute difference |src1 - src2|.
 * EN: Matches AArch64 opcode 0x5dd60 (156 bytes).
 * VN: Khớp opcode AArch64 0x5dd60. Tính khoảng cách tuyệt đối từng pixel phục vụ phát hiện chuyển động.
 */
void absdiff(const Mat& src1, const Mat& src2, Mat& dst, int flags) {
    if (src1.empty() || src2.empty() || src1.rows != src2.rows || src1.cols != src2.cols) {
        dst.release();
        return;
    }

    int rows = src1.rows;
    int cols = src1.cols;
    int total_elems = cols * src1.channels();
    dst = Mat(rows, cols, src1.type_);

    for (int r = 0; r < rows; ++r) {
        const uint8_t* p1 = src1.ptr(r);
        const uint8_t* p2 = src2.ptr(r);
        uint8_t* pd = dst.ptr(r);
        for (int c = 0; c < total_elems; ++c) {
            pd[c] = static_cast<uint8_t>(std::abs(static_cast<int>(p1[c]) - static_cast<int>(p2[c])));
        }
    }
}

/**
 * @brief normalize: Normalizes array norm or value range.
 * EN: Matches AArch64 opcode 0x6052c (156 bytes).
 * VN: Khớp opcode AArch64 0x6052c. Chuẩn hóa dải giá trị ma trận theo MinMax hoặc L2-norm.
 */
void normalize(const Mat& src, Mat& dst, double alpha, double beta, int norm_type, int dtype) {
    if (src.empty()) {
        dst.release();
        return;
    }

    int rows = src.rows;
    int cols = src.cols;
    int cn = src.channels();
    int total_elems = cols * cn;

    if (norm_type == NORM_MINMAX) {
        double min_val = 1e30;
        double max_val = -1e30;

        for (int r = 0; r < rows; ++r) {
            const uint8_t* s = src.ptr(r);
            for (int c = 0; c < total_elems; ++c) {
                double v = s[c];
                min_val = std::min(min_val, v);
                max_val = std::max(max_val, v);
            }
        }

        dst = Mat(rows, cols, src.type_);
        double span = max_val - min_val;
        double target_span = beta - alpha;

        for (int r = 0; r < rows; ++r) {
            const uint8_t* s = src.ptr(r);
            uint8_t* d = dst.ptr(r);
            for (int c = 0; c < total_elems; ++c) {
                double norm_v = (span > 1e-7) ? alpha + (s[c] - min_val) * target_span / span : alpha;
                d[c] = static_cast<uint8_t>(std::max(0.0, std::min(255.0, std::round(norm_v))));
            }
        }
    } else {
        // L2 Norm
        double sum_sq = 0.0;
        for (int r = 0; r < rows; ++r) {
            const uint8_t* s = src.ptr(r);
            for (int c = 0; c < total_elems; ++c) {
                sum_sq += s[c] * s[c];
            }
        }
        double l2 = std::sqrt(sum_sq);
        double factor = (l2 > 1e-7) ? alpha / l2 : 0.0;

        dst = Mat(rows, cols, src.type_);
        for (int r = 0; r < rows; ++r) {
            const uint8_t* s = src.ptr(r);
            uint8_t* d = dst.ptr(r);
            for (int c = 0; c < total_elems; ++c) {
                d[c] = static_cast<uint8_t>(std::max(0.0, std::min(255.0, std::round(s[c] * factor))));
            }
        }
    }
}

void normalize(const UMat& src, UMat& dst, double alpha, double beta, int norm_type, int dtype) {
    Mat src_mat = src.getMat();
    Mat dst_mat;
    normalize(src_mat, dst_mat, alpha, beta, norm_type, dtype);
    dst = UMat(dst_mat.rows, dst_mat.cols, dst_mat.type_);
    dst_mat.copyTo(dst.getMat());
}

/**
 * @brief bitwise_and: Computes bitwise conjunction of two arrays.
 * EN: Matches AArch64 opcode 0x5dfe0 (156 bytes).
 * VN: Khớp opcode AArch64 0x5dfe0. Phép toán AND bitwise từng byte dữ liệu.
 */
void bitwise_and(const Mat& src1, const Mat& src2, Mat& dst, const Mat& mask, int flags) {
    if (src1.empty() || src2.empty() || src1.rows != src2.rows || src1.cols != src2.cols) {
        dst.release();
        return;
    }

    int rows = src1.rows;
    int cols = src1.cols;
    int total_elems = cols * src1.channels();
    dst = Mat(rows, cols, src1.type_);

    bool has_mask = !mask.empty() && mask.rows == rows && mask.cols == cols;

    for (int r = 0; r < rows; ++r) {
        const uint8_t* p1 = src1.ptr(r);
        const uint8_t* p2 = src2.ptr(r);
        const uint8_t* pm = has_mask ? mask.ptr(r) : nullptr;
        uint8_t* pd = dst.ptr(r);

        for (int c = 0; c < total_elems; ++c) {
            if (!pm || pm[c / src1.channels()]) {
                pd[c] = p1[c] & p2[c];
            } else {
                pd[c] = 0;
            }
        }
    }
}

/**
 * @brief calcHist: Calculates 256-bin intensity histogram.
 * EN: Matches AArch64 opcode 0x603f4 (156 bytes).
 * VN: Khớp opcode AArch64 0x603f4. Thống kê biểu đồ tần suất lược đồ xám 256 mức.
 */
void calcHist(const Mat& src, Mat& hist, const Mat& mask) {
    if (src.empty()) {
        hist.release();
        return;
    }

    hist = Mat(256, 1, FCV_32SC1);
    std::memset(hist.ptr(0), 0, 256 * sizeof(int));
    int* h_data = reinterpret_cast<int*>(hist.ptr(0));

    int rows = src.rows;
    int cols = src.cols;
    bool has_mask = !mask.empty();

    for (int r = 0; r < rows; ++r) {
        const uint8_t* s = src.ptr(r);
        const uint8_t* m = has_mask ? mask.ptr(r) : nullptr;
        for (int c = 0; c < cols; ++c) {
            if (!m || m[c]) {
                h_data[s[c]]++;
            }
        }
    }
}

void calcHist(const UMat& src, UMat& hist, const UMat& mask) {
    Mat src_mat = src.getMat();
    Mat mask_mat = mask.getMat();
    Mat hist_mat;
    calcHist(src_mat, hist_mat, mask_mat);
    hist = UMat(hist_mat.rows, hist_mat.cols, hist_mat.type_);
    hist_mat.copyTo(hist.getMat());
}

/**
 * @brief getAffineTransform: Solves 2x3 affine matrix from 3 point pairs.
 * EN: Matches AArch64 opcode 0x5c3f0 (168 bytes).
 *     Given:
 *       x'_i = a00*x_i + a01*y_i + a02
 *       y'_i = a10*x_i + a11*y_i + a12
 *     Solves 3x3 linear system for each coordinate axis using Cramer's rule.
 * VN: Khớp opcode AArch64 0x5c3f0. Giải hệ phương trình ma trận Affine 2x3 từ 3 cặp điểm mốc.
 */
Mat getAffineTransform(const Point2f src[3], const Point2f dst[3]) {
    if (!src || !dst) return Mat();

    Mat M(2, 3, FCV_32FC1);
    float* m = reinterpret_cast<float*>(M.ptr(0));

    // Linear system determinant
    // D = x0*(y1 - y2) + x1*(y2 - y0) + x2*(y0 - y1)
    float d = src[0].x * (src[1].y - src[2].y) +
              src[1].x * (src[2].y - src[0].y) +
              src[2].x * (src[0].y - src[1].y);

    if (std::fabs(d) < 1e-7f) {
        // Degenerate collinear points, return Identity
        m[0] = 1.0f; m[1] = 0.0f; m[2] = 0.0f;
        m[3] = 0.0f; m[4] = 1.0f; m[5] = 0.0f;
        return M;
    }

    float inv_d = 1.0f / d;

    // Row 0 (X mapping)
    m[0] = (dst[0].x * (src[1].y - src[2].y) + dst[1].x * (src[2].y - src[0].y) + dst[2].x * (src[0].y - src[1].y)) * inv_d;
    m[1] = (dst[0].x * (src[2].x - src[1].x) + dst[1].x * (src[0].x - src[2].x) + dst[2].x * (src[1].x - src[0].x)) * inv_d;
    m[2] = (dst[0].x * (src[1].x * src[2].y - src[2].x * src[1].y) +
            dst[1].x * (src[2].x * src[0].y - src[0].x * src[2].y) +
            dst[2].x * (src[0].x * src[1].y - src[1].x * src[0].y)) * inv_d;

    // Row 1 (Y mapping)
    m[3] = (dst[0].y * (src[1].y - src[2].y) + dst[1].y * (src[2].y - src[0].y) + dst[2].y * (src[0].y - src[1].y)) * inv_d;
    m[4] = (dst[0].y * (src[2].x - src[1].x) + dst[1].y * (src[0].x - src[2].x) + dst[2].y * (src[1].x - src[0].x)) * inv_d;
    m[5] = (dst[0].y * (src[1].x * src[2].y - src[2].x * src[1].y) +
            dst[1].y * (src[2].x * src[0].y - src[0].x * src[2].y) +
            dst[2].y * (src[0].x * src[1].y - src[1].x * src[0].y)) * inv_d;

    return M;
}

/**
 * @brief dct: 2D Discrete Cosine Transform.
 * EN: Matches AArch64 opcode 0x60acc (488 bytes).
 * VN: Khớp opcode AArch64 0x60acc. Biến đổi Cosine rời rạc 2 chiều DCT.
 */
void dct(const Mat& src, Mat& dst, int flags) {
    if (src.empty()) {
        dst.release();
        return;
    }

    int N = src.rows;
    int M = src.cols;
    dst = Mat(N, M, FCV_32FC1);

    double c_u_base = std::sqrt(1.0 / M);
    double c_u_high = std::sqrt(2.0 / M);
    double c_v_base = std::sqrt(1.0 / N);
    double c_v_high = std::sqrt(2.0 / N);

    for (int u = 0; u < N; ++u) {
        double cv = (u == 0) ? c_v_base : c_v_high;
        float* d_row = reinterpret_cast<float*>(dst.ptr(u));

        for (int v = 0; v < M; ++v) {
            double cu = (v == 0) ? c_u_base : c_u_high;
            double sum = 0.0;

            for (int y = 0; y < N; ++y) {
                const uint8_t* s_row = src.ptr(y);
                double cos_v = std::cos((2.0 * y + 1.0) * u * kFastCVPi / (2.0 * N));

                for (int x = 0; x < M; ++x) {
                    double cos_u = std::cos((2.0 * x + 1.0) * v * kFastCVPi / (2.0 * M));
                    sum += s_row[x] * cos_v * cos_u;
                }
            }
            d_row[v] = static_cast<float>(cu * cv * sum);
        }
    }
}

/**
 * @brief idct: 2D Inverse Discrete Cosine Transform.
 * EN: Matches AArch64 opcode 0x61220 (548 bytes).
 * VN: Khớp opcode AArch64 0x61220. Biến đổi Cosine rời rạc nghịch đảo 2 chiều IDCT.
 */
void idct(const Mat& src, Mat& dst, int flags) {
    if (src.empty()) {
        dst.release();
        return;
    }

    int N = src.rows;
    int M = src.cols;
    dst = Mat(N, M, FCV_8UC1);

    double c_u_base = std::sqrt(1.0 / M);
    double c_u_high = std::sqrt(2.0 / M);
    double c_v_base = std::sqrt(1.0 / N);
    double c_v_high = std::sqrt(2.0 / N);

    for (int y = 0; y < N; ++y) {
        uint8_t* d_row = dst.ptr(y);

        for (int x = 0; x < M; ++x) {
            double sum = 0.0;

            for (int u = 0; u < N; ++u) {
                double cv = (u == 0) ? c_v_base : c_v_high;
                const float* s_row = reinterpret_cast<const float*>(src.ptr(u));
                double cos_v = std::cos((2.0 * y + 1.0) * u * kFastCVPi / (2.0 * N));

                for (int v = 0; v < M; ++v) {
                    double cu = (v == 0) ? c_u_base : c_u_high;
                    double cos_u = std::cos((2.0 * x + 1.0) * v * kFastCVPi / (2.0 * M));
                    sum += cu * cv * s_row[v] * cos_v * cos_u;
                }
            }
            d_row[x] = static_cast<uint8_t>(std::max(0.0, std::min(255.0, std::round(sum))));
        }
    }
}

void idct(const UMat& src, UMat& dst, int flags) {
    Mat src_mat = src.getMat();
    Mat dst_mat;
    idct(src_mat, dst_mat, flags);
    dst = UMat(dst_mat.rows, dst_mat.cols, dst_mat.type_);
    dst_mat.copyTo(dst.getMat());
}

} // namespace EXPORTS
} // namespace FASTCV
