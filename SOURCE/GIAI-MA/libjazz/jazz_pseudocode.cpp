// ============================================================================
// File: jazz_pseudocode.cpp
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Subsystem: Full AArch64 Disassembly-Matched Pseudocode & Self-Verification
//            Suite for AmazingEngine Jazz JS Engine Runtime Bridge
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (TASK_SO_122_libjazz)
// ============================================================================
// [EN] Clean-room C++17 reference translation unit providing:
//      1. Instruction-accurate AArch64 pseudocode mirrors for the core symbols
//         of `libjazz.so` (`sub_17a08`, `BEFBaseRunner::_PumpLoop`,
//         `BEFBaseRunner::GetNext`, `BEFBaseRunner::PostDelayedTask`,
//         `ContextExecutor::ExecuteProgram`, `Platform::CreateRuntime`,
//         `Runtime::Runtime`, `VM::CreateVM`, `CreateQuickJSVM`,
//         `FileSystemModule::Stats`, `RequireModule`, and `TimerModule`).
//      2. Deterministic self-verification harness (`RunJazzSelfVerification`)
//         validating all mathematical invariants and ABI layouts.
// [VN] Đơn vị dịch C++17 tham chiếu tái tạo sạch cung cấp:
//      1. Bản đối chiếu mã giả AArch64 chuẩn xác tới từng lệnh cho các ký hiệu
//         cốt lõi của `libjazz.so`.
//      2. Bộ khung tự kiểm thử tất định (`RunJazzSelfVerification`) xác minh
//         toàn bộ các bất biến toán học và bố cục ABI.
// ============================================================================

#include "jazz_interface.h"

namespace AmazingEngine {

namespace DisassemblyReference {

// ============================================================================
// 1. AArch64 Reference: sub_17a08 (0x017a08..0x017a38)
//    256-Byte GF(2)^8 Affine Involution S-Box Decoder
// ============================================================================
// [EN] Disassembly @ 0x017a08..0x017a38:
//      0x017a08: f1000448  subs x8, x2, #1
//      0x017a0c: 54000120  b.eq 0x17a30
//      0x017a10: 90000089  adrp x9, #0x28000
//      0x017a14: 912fc129  add  x9, x9, #0xbf0
//      0x017a18: aa0003ea  mov  x10, x0
//      0x017a1c: aa0803eb  mov  x11, x8
//      0x017a20: 3840142c  ldrb w12, [x1], #1
//      0x017a24: 386c692c  ldrb w12, [x9, x12]
//      0x017a28: f100056b  subs x11, x11, #1
//      0x017a2c: 3800154c  strb w12, [x10], #1
//      0x017a30: 54ffffa1  b.ne 0x17a20
//      0x017a34: 3828681f  strb wzr, [x0, x8]
//      0x017a38: d65f03c0  ret
// [VN] Giải mã chính xác mảng byte đã xáo trộn bằng bảng tra `0x028bf0`.
void AArch64_sub_17a08(char* x0_dst, const uint8_t* x1_src, size_t x2_len) noexcept {
    if (!x0_dst || !x1_src || x2_len == 0) {
        return;
    }
    const size_t x8 = x2_len - 1;
    if (x8 != 0) {
        const uint8_t* x9 = kJazzSBoxTable_28bf0;
        char* x10 = x0_dst;
        size_t x11 = x8;
        const uint8_t* srcCursor = x1_src;
        do {
            const uint8_t w12_in = *srcCursor++;
            const uint8_t w12_out = x9[w12_in];
            --x11;
            *x10++ = static_cast<char>(w12_out);
        } while (x11 != 0);
    }
    x0_dst[x8] = '\0';
}

// ============================================================================
// 2. AArch64 Reference: FileSystemModule::Stats (0x01d074..0x01d0c8)
// ============================================================================
// [EN] Disassembly @ 0x01d074..0x01d0b0:
//      Stats::getSize() @ 0x01d074:
//        fd402400  ldr   d0, [x0, #0x48]
//        5e61d800  scvtf d0, d0
//        52800020  mov   w0, #1
//        d65f03c0  ret
//      Stats::isDirectory() @ 0x01d084:
//        b9402808  ldr   w8, [x0, #0x28]
//        12140d08  and   w8, w8, #0xf000
//        52800040  mov   w0, #2
//        7140111f  cmp   w8, #4, lsl #12
//        1a9f17e1  cset  w1, eq
//        d65f03c0  ret
//      Stats::isFile() @ 0x01d09c:
//        b9402808  ldr   w8, [x0, #0x28]
//        12140d08  and   w8, w8, #0xf000
//        52800040  mov   w0, #2
//        7140211f  cmp   w8, #8, lsl #12
//        1a9f17e1  cset  w1, eq
//        d65f03c0  ret
// [VN] Kiểm chứng trực tiếp các thanh ghi trả về của `Stats`.
double AArch64_Stats_getSize(int64_t rawSizeAtOffset48) noexcept {
    return static_cast<double>(rawSizeAtOffset48);
}

bool AArch64_Stats_isDirectory(uint32_t rawModeAtOffset28) noexcept {
    return (rawModeAtOffset28 & 0xF000u) == (4u << 12);
}

bool AArch64_Stats_isFile(uint32_t rawModeAtOffset28) noexcept {
    return (rawModeAtOffset28 & 0xF000u) == (8u << 12);
}

// ============================================================================
// 3. AArch64 Reference: NEON Popcount Hash Bucket Index (0x0220b4 & 0x0221c4)
// ============================================================================
// [EN] Disassembly @ 0x0220b4..0x0220dc:
//      9e670100  fmov   d0, x8
//      0e205800  cnt    v0.8b, v0.8b
//      2e303800  uaddlv h0, v0.8b
//      1e260009  fmov   w9, s0
//      7100053f  cmp    w9, #1
//      54000088  b.hi   0x0220d8
//      d1000509  sub    x9, x8, #1
//      8a0902a8  and    x8, x21, x9
//      ...
//      9ac80aa9  udiv   x9, x21, x8
//      9b08d528  msub   x8, x9, x8, x21
// [VN] Minh chứng toán học của phép thu gọn chỉ số bucket bằng đếm bit NEON.
size_t AArch64_NeonBucketIndex(size_t x21_hash, size_t x8_bucketCount) noexcept {
    return RequireModule::ComputeBucketIndexNeonPopcount(x21_hash, x8_bucketCount);
}

} // namespace DisassemblyReference

// ============================================================================
// 4. Deterministic Self-Verification Suite (`RunJazzSelfVerification`)
// ============================================================================
JazzVerificationReport RunJazzSelfVerification() {
    JazzVerificationReport report{};

    // ------------------------------------------------------------------------
    // Check 1 & 2: S-Box Closed-Form Formula & Self-Inverse Involution (256 B)
    // ------------------------------------------------------------------------
    bool formulaOk = true;
    bool involutionOk = true;
    for (uint32_t x = 0; x < 256; ++x) {
        const uint8_t expected = JazzSBoxEval(static_cast<uint8_t>(x));
        const uint8_t actual = kJazzSBoxTable_28bf0[x];
        if (actual != expected) {
            formulaOk = false;
        }
        if (kJazzSBoxTable_28bf0[actual] != static_cast<uint8_t>(x)) {
            involutionOk = false;
        }
    }
    report.sboxFormulaMatchesAll256 = formulaOk;
    if (formulaOk) {
        ++report.totalPassedChecks;
    }
    report.sboxIsInvolutionAll256 = involutionOk;
    if (involutionOk) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 3: Decoded `makeRequire.js` (.rodata 0x0297d2, 582 bytes -> 581 chars)
    // ------------------------------------------------------------------------
    const std::string decodedMakeRequire = GetDecodedMakeRequireJs();
    report.makeRequireDecodedExact =
        (decodedMakeRequire.size() == kJazzMakeRequireEncodedLen - 1) &&
        (decodedMakeRequire.find("(function(e,s){function t(e){") == 0) &&
        (decodedMakeRequire.find("e.loadScript(s)") != std::string::npos);
    if (report.makeRequireDecodedExact) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 4: Decoded `/bootstrap.js` AMD Modules & `effect.Amaz` Binding
    // ------------------------------------------------------------------------
    const std::string& bootstrapJs = GetDecodedBootstrapJs();
    report.bootstrapModulesPresent =
        (bootstrapJs.find("define(\"bootstrap\"") != std::string::npos) &&
        (bootstrapJs.find("define(\"console\"") != std::string::npos) &&
        (bootstrapJs.find("define(\"timer\"") != std::string::npos) &&
        (bootstrapJs.find("define(\"filesystem\"") != std::string::npos) &&
        (bootstrapJs.find("define(\"event\"") != std::string::npos) &&
        (bootstrapJs.find("define(\"native_callback\"") != std::string::npos) &&
        (bootstrapJs.find("define(\"framework\"") != std::string::npos) &&
        (bootstrapJs.find("effect.Amaz") != std::string::npos);
    if (report.bootstrapModulesPresent) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 5: BEFBaseRunner Priority Queue & PostDelayedTask (0x00cbc4, 0x00ce74)
    // ------------------------------------------------------------------------
    BEFBaseRunner runner;
    std::vector<int> executionOrder;
    runner.PostDelayedTask([&executionOrder]() { executionOrder.push_back(2); }, 5.0);
    runner.PostDelayedTask([&executionOrder]() { executionOrder.push_back(1); }, 0.0);
    std::shared_ptr<BEFTask> firstTask;
    const bool gotFirst = runner.GetNext(firstTask, false);
    if (gotFirst && firstTask) {
        firstTask->Run();
    }
    report.runnerDelayOrderedExact =
        (executionOrder.size() == 1 && executionOrder[0] == 1 &&
         runner.GetPendingTaskCount() == 1);
    if (report.runnerDelayOrderedExact) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 6: ContextExecutor CommonJS Wrapper (0x011a44, .rodata 0x025fe3/0x026009)
    // ------------------------------------------------------------------------
    const std::string wrapped =
        ContextExecutor::WrapModuleCode("return 42;", "/effects/filter/main.js");
    report.contextExecutorWrapsCommonJs =
        (wrapped.find("(function(require){const __filename='/effects/filter/main.js';") == 0) &&
        (wrapped.find("const __dirname=__filename.slice(0, __filename.lastIndexOf('/') + 1);") !=
         std::string::npos) &&
        (wrapped.find("return 42;})") != std::string::npos);
    if (report.contextExecutorWrapsCommonJs) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 7: FileSystemModule::Stats Mode & Size Checks (0x01d074..0x01d0b0)
    // ------------------------------------------------------------------------
    const FileSystemModule::Stats dirStats(0x41EDu, 4096);
    const FileSystemModule::Stats fileStats(0x81A4u, 231840);
    report.statsModeAndSizeExact =
        dirStats.isDirectory().ToBoolean() &&
        !dirStats.isFile().ToBoolean() &&
        fileStats.isFile().ToBoolean() &&
        !fileStats.isDirectory().ToBoolean() &&
        (fileStats.getSize().ToNumber() == 231840.0);
    if (report.statsModeAndSizeExact) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 8: NEON Popcount Hash Bucket Index (0x0220b4 & 0x0221c4)
    // ------------------------------------------------------------------------
    const size_t idxPow2 =
        RequireModule::ComputeBucketIndexNeonPopcount(0x12345678ULL, 64ULL);
    const size_t idxPrime =
        RequireModule::ComputeBucketIndexNeonPopcount(0x12345678ULL, 61ULL);
    report.neonPopcountBucketIndexExact =
        (idxPow2 == (0x12345678ULL & 63ULL)) &&
        (idxPrime == (0x12345678ULL % 61ULL));
    if (report.neonPopcountBucketIndexExact) {
        ++report.totalPassedChecks;
    }

    // ------------------------------------------------------------------------
    // Check 9: Platform / Runtime / VM / TimerModule Lifecycle
    // ------------------------------------------------------------------------
    Platform platform(JSEngineType::QUICKJS);
    const int64_t rtId1 = platform.CreateRuntime(RuntimeMode::MULTI_CONTEXT);
    const int64_t rtId2 = platform.CreateRuntime(RuntimeMode::SINGLE_CONTEXT);
    const int32_t subCtxId = platform.CreateNewContextInRuntime(rtId1);
    const Value evalResult =
        platform.ExecuteProgram(rtId1, "console.log('jazz');", "/app/index.js");
    const bool destroyed1 = platform.DestroyRuntime(rtId1);
    platform.Shutdown();

    report.platformRuntimeLifecycleExact =
        (rtId1 == 1) &&
        (rtId2 == 2) &&
        (subCtxId > 0) &&
        evalResult.IsString() &&
        destroyed1;
    if (report.platformRuntimeLifecycleExact) {
        ++report.totalPassedChecks;
    }

    return report;
}

} // namespace AmazingEngine
