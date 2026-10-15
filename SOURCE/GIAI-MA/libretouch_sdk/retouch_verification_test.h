// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libretouch_sdk.so (ByteDance Face & Body Retouch SDK)
// File: retouch_verification_test.h
// Description: Comprehensive verification test suite for Face106, Beauty, and Body engines
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "retouch_types.h"
#include "retouch_face_align.h"
#include "retouch_beauty_engine.h"
#include "retouch_body_reshape.h"
#include "retouch_painter_sdk.h"
#include <string>
#include <vector>

namespace retouch_sdk {

// EN: Test Result Summary for Closed-Loop Verification Gate
// VN: Tóm tắt kết quả kiểm thử phục vụ cổng xác minh khép kín
struct RetouchTestResult {
    std::string test_name;
    bool passed = false;
    std::string message;
};

// EN: Complete Verification Test Runner for libretouch_sdk
// VN: Bộ chạy kiểm thử xác minh toàn diện cho libretouch_sdk
class RetouchVerificationTestSuite {
public:
    RetouchVerificationTestSuite();
    ~RetouchVerificationTestSuite();

    // EN: Run all verification tests and return results
    // VN: Chạy toàn bộ các bài kiểm thử xác minh và trả về kết quả
    std::vector<RetouchTestResult> RunAllTests();

    // Individual test cases
    RetouchTestResult TestFace106ParserAndBBox();
    RetouchTestResult TestHeadPoseEstimator();
    RetouchTestResult TestAffineCanonicalTransform();
    RetouchTestResult TestSkinToneYCrCbMask();
    RetouchTestResult TestBilateralSmoother();
    RetouchTestResult TestSkinWhitening();
    RetouchTestResult TestTeethWhitening();
    RetouchTestResult TestEyeEnlargementRadialWarp();
    RetouchTestResult TestFaceSlimmingVectors();
    RetouchTestResult TestLegExtensionHermiteContinuity();
    RetouchTestResult TestWaistSlimmingContraction();
    RetouchTestResult TestPainterRuntimeAndVipLayers();
};

} // namespace retouch_sdk
