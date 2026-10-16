// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libskity — Adversarial Verification Test Suite
// File: skity_verification_test.h
// Description: Automated closed-loop verification for Skity 2D vector graphics
//              engine algorithms and AArch64 opcode alignments.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_SKITY_VERIFICATION_TEST_H_
#define NEXTAI_OPENCUT_SKITY_VERIFICATION_TEST_H_

#include <string>
#include <vector>

namespace skity {

class SkityVerificationTest {
public:
    struct TestResult {
        std::string test_name;
        bool passed;
        std::string message;
        double error_margin;
    };

    static bool RunAllTests(std::vector<TestResult>* out_results = nullptr);

    static TestResult TestRectRoundOutAndInset();
    static TestResult TestMatrixAffineAndPerspective();
    static TestResult TestQuaternionDotSlerpReciprocal();
    static TestResult TestPathAddCircleAndArcTo();
    static TestResult TestStrokeMiterJoinAndLimit();
    static TestResult TestPathMeasurePosTanAndLength();
    static TestResult TestShaderGradientAndMaskFilter();
    static TestResult TestRecordingCanvasDisplayList();
};

} // namespace skity

#endif // NEXTAI_OPENCUT_SKITY_VERIFICATION_TEST_H_
