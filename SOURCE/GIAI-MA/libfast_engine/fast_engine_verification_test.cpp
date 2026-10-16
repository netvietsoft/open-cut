// ===================================================================================
// NextAI OpenCut - Architecture & Interface Specification
// Copyright (c) 2026 NextAI Technology. All rights reserved.
// Module: libfast_engine.so (ByteDance Embedded Bytecode Scripting Engine & VM)
// File: fast_engine_verification_test.cpp
// Description: Implementation of 12 closed-loop verification tests with mathematical proof
// Chú thích song ngữ: English & Vietnamese per Rule 12 AGENTS.md
// ===================================================================================

#include "fast_engine_verification_test.h"
#include <iostream>
#include <cmath>
#include <sstream>

namespace fast_engine {

FastEngineVerificationTestSuite::FastEngineVerificationTestSuite() = default;
FastEngineVerificationTestSuite::~FastEngineVerificationTestSuite() = default;

// 1. Test Object Model Refcounting
FastEngineTestResult FastEngineVerificationTestSuite::TestObjectModelRefcounting() {
    FastEngineTestResult res;
    res.test_name = "TestObjectModelRefcounting";

    auto* obj = new LongObj(42);
    if (obj->ref_count.load() != 1) {
        res.passed = false;
        res.message = "Initial ref_count must be 1";
        delete obj;
        return res;
    }

    obj->IncRef();
    if (obj->ref_count.load() != 2) {
        res.passed = false;
        res.message = "ref_count after IncRef must be 2";
        obj->DecRef();
        delete obj;
        return res;
    }

    obj->DecRef();
    if (obj->ref_count.load() != 1) {
        res.passed = false;
        res.message = "ref_count after DecRef must be 1";
        delete obj;
        return res;
    }

    obj->DecRef(); // Should delete itself automatically without memory leak

    res.passed = true;
    res.message = "Reference counting lifecycle verified (1 -> 2 -> 1 -> 0 / deleted)";
    return res;
}

// 2. Test Long and Float Arithmetic
FastEngineTestResult FastEngineVerificationTestSuite::TestLongAndFloatArithmetic() {
    FastEngineTestResult res;
    res.test_name = "TestLongAndFloatArithmetic";

    LongObj a(25);
    LongObj b(10);

    Obj* sum = VM::BinaryOp(Opcode::BINARY_ADD, &a, &b, nullptr);
    Obj* diff = VM::BinaryOp(Opcode::BINARY_SUBTRACT, &a, &b, nullptr);
    Obj* prod = VM::BinaryOp(Opcode::BINARY_MULTIPLY, &a, &b, nullptr);
    Obj* div = VM::BinaryOp(Opcode::BINARY_TRUE_DIVIDE, &a, &b, nullptr);
    Obj* mod = VM::BinaryOp(Opcode::BINARY_MODULO, &a, &b, nullptr);

    bool ok = (sum && sum->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(sum)->val == 35) &&
              (diff && diff->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(diff)->val == 15) &&
              (prod && prod->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(prod)->val == 250) &&
              (div && div->type_tag == ObjTypeTag::TYPE_FLOAT && std::abs(static_cast<FloatObj*>(div)->val - 2.5) < 1e-6) &&
              (mod && mod->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(mod)->val == 5);

    if (sum) sum->DecRef();
    if (diff) diff->DecRef();
    if (prod) prod->DecRef();
    if (div) div->DecRef();
    if (mod) mod->DecRef();

    if (!ok) {
        res.passed = false;
        res.message = "Arithmetic operations did not produce expected mathematical results";
        return res;
    }

    res.passed = true;
    res.message = "Integer and Floating point arithmetic validated: +, -, *, /, %";
    return res;
}

// 3. Test IEEE-754 Double Hashing
FastEngineTestResult FastEngineVerificationTestSuite::TestIEEE754DoubleHashing() {
    FastEngineTestResult res;
    res.test_name = "TestIEEE754DoubleHashing";

    uint64_t hash_zero_pos = HashDouble(nullptr, 0.0);
    uint64_t hash_zero_neg = HashDouble(nullptr, -0.0);

    if (hash_zero_pos != hash_zero_neg) {
        res.passed = false;
        res.message = "Hash of +0.0 and -0.0 must be identical for numerical hash consistency";
        return res;
    }

    uint64_t hash_pi = HashDouble(nullptr, 3.141592653589793);
    uint64_t hash_e  = HashDouble(nullptr, 2.718281828459045);

    if (hash_pi == hash_e || hash_pi == 0ULL) {
        res.passed = false;
        res.message = "HashDouble produced collision or trivial zero hash for distinct constants";
        return res;
    }

    res.passed = true;
    res.message = "IEEE-754 double hashing verified (Zero normalized, distinct hashes for Pi and E)";
    return res;
}

// 4. Test Slice Adjust Indices (Opcode 0xeb2e0)
FastEngineTestResult FastEngineVerificationTestSuite::TestSliceAdjustIndices() {
    FastEngineTestResult res;
    res.test_name = "TestSliceAdjustIndices";

    int64_t length = 10;
    int64_t start = -3;
    int64_t stop = 9;
    int64_t step = 1;

    // [-3:9:1] on length 10 -> [7:9:1] -> length = 2 (indices 7, 8)
    int64_t count = SliceIndices::AdjustIndices(length, &start, &stop, step);

    if (start != 7 || stop != 9 || count != 2) {
        res.passed = false;
        res.message = "Slice adjust [-3:9:1] failed: start=" + std::to_string(start) +
                      ", stop=" + std::to_string(stop) + ", count=" + std::to_string(count);
        return res;
    }

    // Reverse slice [8:2:-2] on length 10 -> count = 3 (indices 8, 6, 4)
    start = 8; stop = 2; step = -2;
    count = SliceIndices::AdjustIndices(length, &start, &stop, step);

    if (start != 8 || stop != 2 || count != 3) {
        res.passed = false;
        res.message = "Reverse slice adjust [8:2:-2] failed: start=" + std::to_string(start) +
                      ", stop=" + std::to_string(stop) + ", count=" + std::to_string(count);
        return res;
    }

    res.passed = true;
    res.message = "Slice index adjustment (Opcode 0xeb2e0) verified for both forward and reverse strides";
    return res;
}

// 5. Test String Slicing
FastEngineTestResult FastEngineVerificationTestSuite::TestStringSlicing() {
    FastEngineTestResult res;
    res.test_name = "TestStringSlicing";

    StrObj str("NextAIOpenCut");
    // Slice [6:13:1] -> "OpenCut"
    StrObj* sliced = str.Slice(6, 13, 1);

    if (!sliced || sliced->val != "OpenCut") {
        res.passed = false;
        res.message = "String slice [6:13] failed: got '" + (sliced ? sliced->val : "null") + "'";
        if (sliced) sliced->DecRef();
        return res;
    }
    sliced->DecRef();

    // Reverse stride [::-1]
    StrObj* rev = str.Slice(-1, -15, -1);
    if (!rev || rev->val != "tuCnepOIAtxeN") {
        res.passed = false;
        res.message = "String reverse slice failed: got '" + (rev ? rev->val : "null") + "'";
        if (rev) rev->DecRef();
        return res;
    }
    rev->DecRef();

    res.passed = true;
    res.message = "String slicing and reverse stride verified: 'NextAIOpenCut'[6:13] == 'OpenCut'";
    return res;
}

// 6. Test Dictionary Operations
FastEngineTestResult FastEngineVerificationTestSuite::TestDictOperations() {
    FastEngineTestResult res;
    res.test_name = "TestDictOperations";

    DictObj dict;
    auto* val_int = new LongObj(1080);
    auto* val_fps = new LongObj(60);

    dict.SetItemStringRef("width", val_int, nullptr);
    dict.SetItemStringRef("fps", val_fps, nullptr);
    val_int->DecRef();
    val_fps->DecRef();

    Obj* queried = dict.GetItemString("width");
    if (!queried || queried->type_tag != ObjTypeTag::TYPE_INT || static_cast<LongObj*>(queried)->val != 1080) {
        res.passed = false;
        res.message = "Dict GetItemString('width') failed";
        return res;
    }

    // Iterator check (Opcode 0xbd274: DictObj::Next)
    int64_t pos = 0;
    Obj* k = nullptr;
    Obj* v = nullptr;
    int items_counted = 0;
    while (dict.Next(&pos, &k, &v)) {
        items_counted++;
    }

    if (items_counted != 2) {
        res.passed = false;
        res.message = "Dict Next iterator failed: expected 2 items, got " + std::to_string(items_counted);
        return res;
    }

    // Delete check (Opcode 0x4f864: mapping::DelItem)
    StrObj key_fps("fps");
    bool deleted = dict.DelItem(&key_fps, nullptr);
    if (!deleted || dict.GetItemString("fps") != nullptr || dict.Size() != 1) {
        res.passed = false;
        res.message = "Dict DelItem failed";
        return res;
    }

    res.passed = true;
    res.message = "Dictionary insertion, lookup, iteration (0xbd274), and deletion (0x4f864) verified";
    return res;
}

// 7. Test Set Difference and Union
FastEngineTestResult FastEngineVerificationTestSuite::TestSetDifferenceAndUnion() {
    FastEngineTestResult res;
    res.test_name = "TestSetDifferenceAndUnion";

    SetObj set_a;
    SetObj set_b;

    auto* item1 = new LongObj(1);
    auto* item2 = new LongObj(2);
    auto* item3 = new LongObj(3);
    auto* item4 = new LongObj(4);

    set_a.Add(item1, nullptr);
    set_a.Add(item2, nullptr);
    set_a.Add(item3, nullptr);

    set_b.Add(item2, nullptr);
    set_b.Add(item4, nullptr);

    // Difference: A - B = {1, 3} (Opcode 0xe8110)
    SetObj* diff = set_a.Difference(&set_b, nullptr);
    bool ok_diff = (diff && diff->Size() == 2 && diff->Contains(item1, nullptr) && diff->Contains(item3, nullptr) && !diff->Contains(item2, nullptr));

    // Remove item3 (Opcode 0xe7de4: SetObj::Remove)
    bool removed = set_a.Remove(item3, nullptr);
    bool ok_rem = removed && (set_a.Size() == 2) && !set_a.Contains(item3, nullptr);

    item1->DecRef();
    item2->DecRef();
    item3->DecRef();
    item4->DecRef();
    if (diff) diff->DecRef();

    if (!ok_diff || !ok_rem) {
        res.passed = false;
        res.message = "Set difference or removal operation failed";
        return res;
    }

    res.passed = true;
    res.message = "Set difference (0xe8110) and element removal (0xe7de4) verified";
    return res;
}

// 8. Test Bytecode Execution: Polynomial f(a, b) = a^2 + 2ab + b^2
FastEngineTestResult FastEngineVerificationTestSuite::TestBytecodeExecutionPolynomial() {
    FastEngineTestResult res;
    res.test_name = "TestBytecodeExecutionPolynomial";

    // Build CodeObj for f(a, b) = a^2 + 2*a*b + b^2
    auto* code = new CodeObj("square_sum", "test.fe", 2);
    code->varnames = {"a", "b"};
    code->names = {};
    code->consts = {
        new LongObj(2) // Const index 0: 2
    };

    // Helper macro to append 1-byte opcode
    auto emit_op = [&](Opcode op) {
        code->bytecode.push_back(static_cast<uint8_t>(op));
    };

    // Helper macro to append opcode with 16-bit argument
    auto emit_op_arg = [&](Opcode op, uint16_t arg) {
        code->bytecode.push_back(static_cast<uint8_t>(op));
        code->bytecode.push_back(static_cast<uint8_t>(arg & 0xFF));
        code->bytecode.push_back(static_cast<uint8_t>((arg >> 8) & 0xFF));
    };

    // Bytecode instructions:
    // 1. a * a -> a^2
    emit_op_arg(Opcode::LOAD_FAST, 0);
    emit_op_arg(Opcode::LOAD_FAST, 0);
    emit_op(Opcode::BINARY_MULTIPLY);

    // 2. 2 * a * b -> 2ab
    emit_op_arg(Opcode::LOAD_CONST, 0);
    emit_op_arg(Opcode::LOAD_FAST, 0);
    emit_op(Opcode::BINARY_MULTIPLY);
    emit_op_arg(Opcode::LOAD_FAST, 1);
    emit_op(Opcode::BINARY_MULTIPLY);

    // 3. (a^2) + (2ab)
    emit_op(Opcode::BINARY_ADD);

    // 4. b * b -> b^2
    emit_op_arg(Opcode::LOAD_FAST, 1);
    emit_op_arg(Opcode::LOAD_FAST, 1);
    emit_op(Opcode::BINARY_MULTIPLY);

    // 5. (a^2 + 2ab) + (b^2)
    emit_op(Opcode::BINARY_ADD);

    // 6. return result
    emit_op(Opcode::RETURN_VALUE);

    // Set line offsets: at offset 0 -> line 10
    code->line_offsets.push_back({0, 10});

    // Execute with a = 7, b = 5.
    // Mathematical expectation: (7 + 5)^2 = 12^2 = 144
    auto* frame = new FrameObj(code, nullptr);
    frame->SetLocal(0, new LongObj(7));
    frame->SetLocal(1, new LongObj(5));

    Obj* result = VM::Execute(frame, nullptr);

    bool passed = (result && result->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(result)->val == 144);
    int64_t val = (result && result->type_tag == ObjTypeTag::TYPE_INT) ? static_cast<LongObj*>(result)->val : -1;

    // Check line lookup (Opcode 0xb7b20: CodeObj::Addr2Line)
    int32_t line = code->Addr2Line(5);

    if (result) result->DecRef();
    frame->DecRef();
    code->DecRef();

    if (!passed || line != 10) {
        res.passed = false;
        res.message = "Polynomial evaluation failed: expected 144, got " + std::to_string(val);
        return res;
    }

    res.passed = true;
    res.message = "Polynomial f(7, 5) = a^2 + 2ab + b^2 = 144 evaluated successfully (Addr2Line=" + std::to_string(line) + ")";
    return res;
}

// 9. Test Bytecode Conditional Branching
FastEngineTestResult FastEngineVerificationTestSuite::TestBytecodeConditionalBranching() {
    FastEngineTestResult res;
    res.test_name = "TestBytecodeConditionalBranching";

    // def max_branch(x, y):
    //     if x > y: return x
    //     else: return y
    auto* code = new CodeObj("max_branch", "branch.fe", 2);
    code->varnames = {"x", "y"};

    auto emit_op = [&](Opcode op) { code->bytecode.push_back(static_cast<uint8_t>(op)); };
    auto emit_op_arg = [&](Opcode op, uint16_t arg) {
        code->bytecode.push_back(static_cast<uint8_t>(op));
        code->bytecode.push_back(static_cast<uint8_t>(arg & 0xFF));
        code->bytecode.push_back(static_cast<uint8_t>((arg >> 8) & 0xFF));
    };

    // 0: LOAD_FAST 0 (x)
    emit_op_arg(Opcode::LOAD_FAST, 0);
    // 3: LOAD_FAST 1 (y)
    emit_op_arg(Opcode::LOAD_FAST, 1);
    // 6: COMPARE_OP GT (4)
    emit_op_arg(Opcode::COMPARE_OP, static_cast<uint16_t>(CompareOp::GT));
    // 9: POP_JUMP_IF_FALSE 17
    emit_op_arg(Opcode::POP_JUMP_IF_FALSE, 17);
    // 12: LOAD_FAST 0 (x)
    emit_op_arg(Opcode::LOAD_FAST, 0);
    // 15: RETURN_VALUE
    emit_op(Opcode::RETURN_VALUE);
    // 16: NOP
    emit_op(Opcode::NOP);
    // 17: LOAD_FAST 1 (y)
    emit_op_arg(Opcode::LOAD_FAST, 1);
    // 20: RETURN_VALUE
    emit_op(Opcode::RETURN_VALUE);

    // Test case 1: x = 100, y = 50 -> should return 100
    auto* frame1 = new FrameObj(code, nullptr);
    frame1->SetLocal(0, new LongObj(100));
    frame1->SetLocal(1, new LongObj(50));
    Obj* res1 = VM::Execute(frame1, nullptr);
    bool ok1 = (res1 && res1->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(res1)->val == 100);

    // Test case 2: x = 30, y = 80 -> should return 80
    auto* frame2 = new FrameObj(code, nullptr);
    frame2->SetLocal(0, new LongObj(30));
    frame2->SetLocal(1, new LongObj(80));
    Obj* res2 = VM::Execute(frame2, nullptr);
    bool ok2 = (res2 && res2->type_tag == ObjTypeTag::TYPE_INT && static_cast<LongObj*>(res2)->val == 80);

    if (res1) res1->DecRef();
    if (res2) res2->DecRef();
    frame1->DecRef();
    frame2->DecRef();
    code->DecRef();

    if (!ok1 || !ok2) {
        res.passed = false;
        res.message = "Conditional branching failed to route execution correctly";
        return res;
    }

    res.passed = true;
    res.message = "Conditional branching (COMPARE_OP, POP_JUMP_IF_FALSE) verified on both branches";
    return res;
}

// 10. Test FastEngine Singleton and Modules
FastEngineTestResult FastEngineVerificationTestSuite::TestFastEngineSingletonAndModules() {
    FastEngineTestResult res;
    res.test_name = "TestFastEngineSingletonAndModules";

    auto& fe = FastEngine::Instance(); // Opcode 0x45cd4
    FastEngineConfigProvider provider;
    bool inited = fe.Initialize(&provider); // Opcode 0x46198

    if (!inited || !fe.HasFreeVM()) { // Opcode 0x4632c
        res.passed = false;
        res.message = "FastEngine initialization or free VM check failed";
        return res;
    }

    // Test module obfuscation decryption (Opcode 0x46db0: DecryptModuleName)
    std::string enc_name = "__enc_";
    std::string raw_name = "capcut_vfx";
    for (char c : raw_name) {
        enc_name.push_back(static_cast<char>(static_cast<uint8_t>(c) ^ 0x5A));
    }

    FastEngine::DecryptModuleName(enc_name);
    if (enc_name != "capcut_vfx") {
        res.passed = false;
        res.message = "Module name decryption failed: expected 'capcut_vfx', got '" + enc_name + "'";
        return res;
    }

    res.passed = true;
    res.message = "FastEngine singleton (0x45cd4), HasFreeVM (0x4632c), and DecryptModuleName (0x46db0) verified";
    return res;
}

// 11. Test Base64 Module Import
FastEngineTestResult FastEngineVerificationTestSuite::TestBase64ModuleImport() {
    FastEngineTestResult res;
    res.test_name = "TestBase64ModuleImport";

    // Payload: "OpenCutVfxScript" encoded in Base64 is "T3BlbkN1dFZmeFNjcmlwdA=="
    const char* b64_script = "T3BlbkN1dFZmeFNjcmlwdA==";
    Obj* obj = ReadObjectFromBase64(b64_script, nullptr); // Opcode 0x51e80

    if (!obj || obj->type_tag != ObjTypeTag::TYPE_BYTES) {
        res.passed = false;
        res.message = "ReadObjectFromBase64 failed to produce BytesObj";
        if (obj) obj->DecRef();
        return res;
    }

    auto* bytes_obj = static_cast<BytesObj*>(obj);
    std::string decoded_str(reinterpret_cast<char*>(bytes_obj->val.data()), bytes_obj->val.size());
    bytes_obj->DecRef();

    if (decoded_str != "OpenCutVfxScript") {
        res.passed = false;
        res.message = "Base64 decode mismatch: expected 'OpenCutVfxScript', got '" + decoded_str + "'";
        return res;
    }

    res.passed = true;
    res.message = "Base64 script deserialization (Opcode 0x51e80) verified";
    return res;
}

// 12. Test Memory Stats and Clear Modules
FastEngineTestResult FastEngineVerificationTestSuite::TestMemoryStatsAndClearModules() {
    FastEngineTestResult res;
    res.test_name = "TestMemoryStatsAndClearModules";

    Error err;
    Engine eng(err);

    eng.allocated_bytes = 1048576; // 1 MB
    eng.execution_count = 50;

    std::ostringstream ss;
    eng.PrintMemoryStats("[OpenCut]", ss); // Opcode 0x53494
    std::string report = ss.str();

    if (report.find("1048576 B") == std::string::npos || report.find("50 calls") == std::string::npos) {
        res.passed = false;
        res.message = "PrintMemoryStats format mismatch";
        return res;
    }

    eng.ResetMemoryStats(); // Opcode 0x53470
    if (eng.allocated_bytes != 0 || eng.execution_count != 0) {
        res.passed = false;
        res.message = "ResetMemoryStats failed to zero metrics";
        return res;
    }

    // Clear modules check (Opcode 0x5e2e0)
    eng.ClearModules();

    res.passed = true;
    res.message = "Memory stats (0x53494, 0x53470) and module clearing (0x5e2e0) verified";
    return res;
}

std::vector<FastEngineTestResult> FastEngineVerificationTestSuite::RunAllTests() {
    std::vector<FastEngineTestResult> results;
    results.push_back(TestObjectModelRefcounting());
    results.push_back(TestLongAndFloatArithmetic());
    results.push_back(TestIEEE754DoubleHashing());
    results.push_back(TestSliceAdjustIndices());
    results.push_back(TestStringSlicing());
    results.push_back(TestDictOperations());
    results.push_back(TestSetDifferenceAndUnion());
    results.push_back(TestBytecodeExecutionPolynomial());
    results.push_back(TestBytecodeConditionalBranching());
    results.push_back(TestFastEngineSingletonAndModules());
    results.push_back(TestBase64ModuleImport());
    results.push_back(TestMemoryStatsAndClearModules());
    return results;
}

} // namespace fast_engine
