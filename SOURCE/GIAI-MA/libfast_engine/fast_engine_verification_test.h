// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_verification_test.h
// Description: Comprehensive verification test suite for FastEngine Object Model and VM
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#pragma once

#include "fast_engine_types.h"
#include "fast_engine_obj.h"
#include "fast_engine_vm.h"
#include "fast_engine_runtime.h"
#include <string>
#include <vector>

namespace fast_engine {

// EN: Test Result Structure for Closed-Loop Verification
// VN: Cấu trúc kết quả kiểm thử phục vụ xác minh khép kín
struct FastEngineTestResult {
    std::string test_name;
    bool passed = false;
    std::string message;
};

// EN: Verification Test Suite for libfast_engine.so
// VN: Bộ kiểm thử xác minh toàn diện cho libfast_engine.so
class FastEngineVerificationTestSuite {
public:
    FastEngineVerificationTestSuite();
    ~FastEngineVerificationTestSuite();

    std::vector<FastEngineTestResult> RunAllTests();

    FastEngineTestResult TestObjectModelRefcounting();
    FastEngineTestResult TestLongAndFloatArithmetic();
    FastEngineTestResult TestIEEE754DoubleHashing();
    FastEngineTestResult TestSliceAdjustIndices();
    FastEngineTestResult TestStringSlicing();
    FastEngineTestResult TestDictOperations();
    FastEngineTestResult TestSetDifferenceAndUnion();
    FastEngineTestResult TestBytecodeExecutionPolynomial();
    FastEngineTestResult TestBytecodeConditionalBranching();
    FastEngineTestResult TestFastEngineSingletonAndModules();
    FastEngineTestResult TestBase64ModuleImport();
    FastEngineTestResult TestMemoryStatsAndClearModules();
};

} // namespace fast_engine
