// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libfastcv — Adversarial Verification Test Suite
// File: fastcv_verification_test.h
// Description: Automated closed-loop verification for Qualcomm FastCV
//              computer vision algorithms and AArch64 opcode alignments.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_FASTCV_VERIFICATION_TEST_H_
#define NEXTAI_OPENCUT_FASTCV_VERIFICATION_TEST_H_

#include <string>
#include <vector>

namespace FASTCV {
namespace EXPORTS {

class FastCVVerificationTest {
public:
    struct TestResult {
        std::string test_name;
        bool passed;
        std::string message;
        double error_margin;
    };

    static bool RunAllTests(std::vector<TestResult>* out_results = nullptr);

    static TestResult TestMatChannelsAndEmpty();
    static TestResult TestColorConversionRGB2GrayAndNV12();
    static TestResult TestAlphaBlendMath();
    static TestResult TestDownScaleAndMakeBorder();
    static TestResult TestThresholdAndAbsDiff();
    static TestResult TestAffineTransformLinearSolvers();
    static TestResult TestDCTAndIDCTInvertibility();
    static TestResult TestGPUContextStatusParity();
};

} // namespace EXPORTS
} // namespace FASTCV

#endif // NEXTAI_OPENCUT_FASTCV_VERIFICATION_TEST_H_
