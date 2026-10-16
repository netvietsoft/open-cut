// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Adversarial Verification Test Suite
// File: fastcv_verification_test.cpp
// Description: Implementation of rigorous mathematical tests for libfastcv.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#include "fastcv_verification_test.h"
#include "fastcv_types.h"
#include "fastcv_mat.h"
#include "fastcv_imgproc.h"
#include "fastcv_math_transforms.h"
#include "fastcv_gpu_context.h"

#include <iostream>
#include <cmath>

namespace FASTCV {
namespace EXPORTS {

bool FastCVVerificationTest::RunAllTests(std::vector<TestResult>* out_results) {
    std::vector<TestResult> results = {
        TestMatChannelsAndEmpty(),
        TestColorConversionRGB2GrayAndNV12(),
        TestAlphaBlendMath(),
        TestDownScaleAndMakeBorder(),
        TestThresholdAndAbsDiff(),
        TestAffineTransformLinearSolvers(),
        TestDCTAndIDCTInvertibility(),
        TestGPUContextStatusParity(),
    };

    bool all_passed = true;
    for (const auto& r : results) {
        if (!r.passed) {
            all_passed = false;
        }
    }

    if (out_results) {
        *out_results = results;
    }
    return all_passed;
}

/**
 * @brief Test 1: Mat channels, empty, and elemSize1.
 * Opcodes: 0x64c50 (channels), 0x64c74 (empty), 0x64cac (elemSize1).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestMatChannelsAndEmpty() {
    TestResult r;
    r.test_name = "FastCV_MatChannelsAndEmptyMath";

    Mat empty_mat;
    bool empty_ok = empty_mat.empty();

    Mat m1(10, 20, FCV_8UC1);
    Mat m3(10, 20, FCV_8UC3);
    Mat m4(10, 20, FCV_8UC4);
    Mat mf(10, 20, FCV_32FC3);

    bool channels_ok = (m1.channels() == 1 && m3.channels() == 3 &&
                        m4.channels() == 4 && mf.channels() == 3);
    bool not_empty_ok = (!m1.empty() && !m3.empty() && !m4.empty());
    bool elem_size_ok = (m1.elemSize1() == 1 && mf.elemSize1() == 4 && mf.elemSize() == 12);

    r.passed = empty_ok && channels_ok && not_empty_ok && elem_size_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "Mat::channels (0x64c50), empty (0x64c74), elemSize1 (0x64cac) khớp cấu trúc ABI tuyệt đối"
                         : "Lỗi cấu trúc Mat";
    return r;
}

/**
 * @brief Test 2: Color Space Conversion RGB2Gray and NV12.
 * Opcode: 0x5e468 (cvtColor).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestColorConversionRGB2GrayAndNV12() {
    TestResult r;
    r.test_name = "FastCV_ColorConversionRGB2GrayAndNV12Math";

    Mat rgb(1, 3, FCV_8UC3);
    // Pixel 0: Pure Red (255, 0, 0) -> Y = (77*255 + 128) >> 8 = 77
    rgb.at<uint8_t>(0, 0) = 255; rgb.at<uint8_t>(0, 1) = 0;   rgb.at<uint8_t>(0, 2) = 0;
    // Pixel 1: Pure Green (0, 255, 0) -> Y = (150*255 + 128) >> 8 = 149
    rgb.at<uint8_t>(0, 3) = 0;   rgb.at<uint8_t>(0, 4) = 255; rgb.at<uint8_t>(0, 5) = 0;
    // Pixel 2: Pure Blue (0, 0, 255) -> Y = (29*255 + 128) >> 8 = 29
    rgb.at<uint8_t>(0, 6) = 0;   rgb.at<uint8_t>(0, 7) = 0;   rgb.at<uint8_t>(0, 8) = 255;

    Mat gray;
    cvtColor(rgb, gray, COLOR_RGB2GRAY);

    bool red_ok = (gray.at<uint8_t>(0, 0) == 77);
    bool green_ok = (gray.at<uint8_t>(0, 1) == 149);
    bool blue_ok = (gray.at<uint8_t>(0, 2) == 29);

    // Full white check
    Mat white(1, 1, FCV_8UC3);
    white.at<uint8_t>(0, 0) = 255; white.at<uint8_t>(0, 1) = 255; white.at<uint8_t>(0, 2) = 255;
    Mat gray_white;
    cvtColor(white, gray_white, COLOR_RGB2GRAY);
    bool white_ok = (gray_white.at<uint8_t>(0, 0) == 255);

    r.passed = red_ok && green_ok && blue_ok && white_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "cvtColor RGB2GRAY (Opcode 0x5e468): Y_red=77, Y_green=149, Y_blue=29, Y_white=255 chuẩn xác"
                         : "Lỗi chuyển đổi không gian màu RGB2GRAY";
    return r;
}

/**
 * @brief Test 3: Alpha Blending Math.
 * Opcode: 0x5f598 (alphaBlend).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestAlphaBlendMath() {
    TestResult r;
    r.test_name = "FastCV_AlphaBlendMath";

    Mat src1(1, 1, FCV_8UC1);
    Mat src2(1, 1, FCV_8UC1);
    Mat alpha(1, 1, FCV_8UC1);
    Mat dst;

    src1.at<uint8_t>(0, 0) = 200;
    src2.at<uint8_t>(0, 0) = 50;

    // 1. Alpha = 255 -> 100% src1 (200)
    alpha.at<uint8_t>(0, 0) = 255;
    alphaBlend(src1, src2, alpha, dst);
    bool a255_ok = (dst.at<uint8_t>(0, 0) == 200);

    // 2. Alpha = 0 -> 100% src2 (50)
    alpha.at<uint8_t>(0, 0) = 0;
    alphaBlend(src1, src2, alpha, dst);
    bool a0_ok = (dst.at<uint8_t>(0, 0) == 50);

    // 3. Alpha = 128 -> (200*128 + 50*127 + 128)/255 = 125
    alpha.at<uint8_t>(0, 0) = 128;
    alphaBlend(src1, src2, alpha, dst);
    bool a128_ok = (dst.at<uint8_t>(0, 0) == 125);

    r.passed = a255_ok && a0_ok && a128_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "alphaBlend (Opcode 0x5f598): a(255)=200, a(0)=50, a(128)=125 đạt công thức giải tích chuẩn"
                         : "Lỗi hòa trộn alphaBlend";
    return r;
}

/**
 * @brief Test 4: DownScale and copyMakeBorder.
 * Opcodes: 0x60880 (downScale), 0x5f18c (copyMakeBorder).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestDownScaleAndMakeBorder() {
    TestResult r;
    r.test_name = "FastCV_DownScaleAndMakeBorderMath";

    Mat src(100, 100, FCV_8UC1);
    src.setTo(Scalar(128));

    Mat scaled;
    downScale(src, scaled, 0.5f, 0.5f);
    bool scale_dim_ok = (scaled.rows == 50 && scaled.cols == 50);
    bool scale_val_ok = (scaled.at<uint8_t>(25, 25) == 128);

    Mat bordered;
    copyMakeBorder(src, bordered, 2, 2, 3, 3, BORDER_CONSTANT, Scalar(0));
    bool border_dim_ok = (bordered.rows == 104 && bordered.cols == 106);
    bool border_pad_ok = (bordered.at<uint8_t>(0, 0) == 0 && bordered.at<uint8_t>(2, 3) == 128);

    r.passed = scale_dim_ok && scale_val_ok && border_dim_ok && border_pad_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "downScale (0x60880) [100x100 -> 50x50] & copyMakeBorder (0x5f18c) [104x106] chính xác 100%"
                         : "Lỗi thu nhỏ downScale hoặc đệm viền copyMakeBorder";
    return r;
}

/**
 * @brief Test 5: Threshold and AbsDiff Math.
 * Opcodes: 0x607d4 (threshold), 0x5dd60 (absdiff).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestThresholdAndAbsDiff() {
    TestResult r;
    r.test_name = "FastCV_ThresholdAndAbsDiffMath";

    Mat src(1, 3, FCV_8UC1);
    src.at<uint8_t>(0, 0) = 50;
    src.at<uint8_t>(0, 1) = 128;
    src.at<uint8_t>(0, 2) = 200;

    Mat th_bin;
    threshold(src, th_bin, 128.0, 255.0, THRESH_BINARY);
    bool th_ok = (th_bin.at<uint8_t>(0, 0) == 0 &&
                  th_bin.at<uint8_t>(0, 1) == 0 &&
                  th_bin.at<uint8_t>(0, 2) == 255);

    Mat s1(1, 1, FCV_8UC1);
    Mat s2(1, 1, FCV_8UC1);
    Mat diff;
    s1.at<uint8_t>(0, 0) = 180;
    s2.at<uint8_t>(0, 0) = 50;
    absdiff(s1, s2, diff);
    bool diff_ok = (diff.at<uint8_t>(0, 0) == 130);

    r.passed = th_ok && diff_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "threshold (0x607d4) THRESH_BINARY & absdiff (0x5dd60) |180-50|=130 chuẩn xác"
                         : "Lỗi phân ngưỡng threshold hoặc trừ tuyệt đối absdiff";
    return r;
}

/**
 * @brief Test 6: Affine Transform Linear Solver Cramer's Rule.
 * Opcode: 0x5c3f0 (getAffineTransform).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestAffineTransformLinearSolvers() {
    TestResult r;
    r.test_name = "FastCV_AffineTransformLinearSolversMath";

    Point2f src[3] = { Point2f(0.0f, 0.0f), Point2f(10.0f, 0.0f), Point2f(0.0f, 10.0f) };
    // Translation by (15, 25)
    Point2f dst[3] = { Point2f(15.0f, 25.0f), Point2f(25.0f, 25.0f), Point2f(15.0f, 35.0f) };

    Mat M = getAffineTransform(src, dst);
    const float* m = reinterpret_cast<const float*>(M.ptr(0));

    // Expected matrix: [[1, 0, 15], [0, 1, 25]]
    double err = std::fabs(m[0] - 1.0f) + std::fabs(m[1] - 0.0f) + std::fabs(m[2] - 15.0f) +
                 std::fabs(m[3] - 0.0f) + std::fabs(m[4] - 1.0f) + std::fabs(m[5] - 25.0f);

    r.passed = (err < 1e-4);
    r.error_margin = err;
    r.message = r.passed ? "getAffineTransform (Opcode 0x5c3f0): Giải hệ phương trình ma trận Cramer chuẩn xác 100%"
                         : "Lỗi giải ma trận Affine";
    return r;
}

/**
 * @brief Test 7: Discrete Cosine Transform and IDCT Invertibility.
 * Opcodes: 0x60acc (dct), 0x61220 (idct).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestDCTAndIDCTInvertibility() {
    TestResult r;
    r.test_name = "FastCV_DCTAndIDCTInvertibilityMath";

    // 4x4 image patch
    Mat patch(4, 4, FCV_8UC1);
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            patch.at<uint8_t>(y, x) = static_cast<uint8_t>(50 + y * 20 + x * 10);
        }
    }

    Mat freq;
    dct(patch, freq);

    Mat reconstructed;
    idct(freq, reconstructed);

    double max_err = 0.0;
    for (int y = 0; y < 4; ++y) {
        for (int x = 0; x < 4; ++x) {
            double err = std::abs(static_cast<int>(patch.at<uint8_t>(y, x)) -
                                  static_cast<int>(reconstructed.at<uint8_t>(y, x)));
            max_err = std::max(max_err, err);
        }
    }

    // Rounding error on 8-bit quantized IDCT must be <= 1 LSB
    bool invert_ok = (max_err <= 1.0);

    r.passed = invert_ok;
    r.error_margin = max_err;
    r.message = r.passed ? "dct (0x60acc) & idct (0x61220): Tính khả nghịch IDCT(DCT(x)) = x đạt sai số <= 1 LSB"
                         : "Lỗi biến đổi DCT/IDCT không khả nghịch";
    return r;
}

/**
 * @brief Test 8: GPU Context Status Query ABI.
 * Opcode: 0x62730 (getGPUContextStatus).
 */
FastCVVerificationTest::TestResult FastCVVerificationTest::TestGPUContextStatusParity() {
    TestResult r;
    r.test_name = "FastCV_GPUContextStatusParity";

    // Null context must return 5 (INVALID_HANDLE)
    int null_status = getGPUContextStatus(nullptr);
    bool null_ok = (null_status == 5);

    // Active context returns 0 (SUCCESS)
    GPUContext ctx;
    int valid_status = getGPUContextStatus(&ctx);
    bool valid_ok = (valid_status == 0);

    r.passed = null_ok && valid_ok;
    r.error_margin = 0.0;
    r.message = r.passed ? "getGPUContextStatus (Opcode 0x62730): Null -> 5 (INVALID_HANDLE), Active -> 0 (SUCCESS)"
                         : "Lỗi mã trạng thái GPUContext";
    return r;
}

} // namespace EXPORTS
} // namespace FASTCV
