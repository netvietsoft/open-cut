// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: liblens.so (ByteDance Lens AI & Computer Vision Engine)
// File: lens_verification_test.h
// Description: Automated closed-loop verification test harness for Lens algorithms
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include <cstdint>
#include <string>

namespace LENS::TEST {

// EN: Test execution result container
// VN: Cấu trúc kết quả thực thi kiểm thử
struct LensTestResult {
    bool passed = false;
    int32_t total_tests = 10;
    int32_t passed_tests = 0;
    std::string report = "";
};

// EN: Run the complete 10-point mathematical and ABI verification suite
// VN: Chạy bộ 10 bài kiểm thử toán học và tính tương thích ABI khép kín
LensTestResult RunLensSelfTest();

} // namespace LENS::TEST
