// ==============================================================================
// NextAI OpenCut — High-Fidelity Video Editing & Vector Graphics Engine
// Module: libaudio_fingerprint_sdk — Adversarial Verification Test Suite
// File: afp_verification_test.h
// Description: Automated closed-loop verification for acoustic landmark
//              fingerprinting, PocketFFT, and bitstream compression.
//
// Chú thích song ngữ: Tiếng Anh (EN) & Tiếng Việt (VN)
// ==============================================================================

#ifndef NEXTAI_OPENCUT_AFP_VERIFICATION_TEST_H_
#define NEXTAI_OPENCUT_AFP_VERIFICATION_TEST_H_

#include <string>
#include <vector>

namespace audio_fingerprint_sdk {

class AFPVerificationTest {
public:
    struct TestResult {
        std::string test_name;
        bool passed;
        std::string message;
        double error_margin;
    };

    static bool RunAllTests(std::vector<TestResult>* out_results = nullptr);

    static TestResult TestHammingWindowMath();
    static TestResult TestRFFTForwardAndBackwardInvertibility();
    static TestResult TestSpectrogramMagnitudeDB();
    static TestResult TestFrequencyBin9BitCompression();
    static TestResult TestTimeDeltaVLQCompression();
    static TestResult TestWriteSizeAheadBigEndianRev();
    static TestResult TestLandmarkPairKeyComputation();
    static TestResult TestEndToEndFingerprintGeneration();
    static TestResult TestVersionStringParity();
};

} // namespace audio_fingerprint_sdk

#endif // NEXTAI_OPENCUT_AFP_VERIFICATION_TEST_H_
