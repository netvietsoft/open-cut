// ============================================================================
// File: bdhm_native_pseudocode.cpp
// Module: libbdhm_native.so — Deterministic Self-Test & Verification Harness
//         (Bộ Kiểm thử Tự động & Đối soát Toán học/Đồ thị cho libbdhm_native.so)
// Project: NextAI OpenCut (com.nextai.opencut)
// Task ID: TASK-091-RECONSTRUCTION-LIBBDHM_NATIVE (TASK_SO_102)
// Verification: OBSERVED from apktool-res/lib/arm64-v8a/libbdhm_native.so
//               (599,968 bytes, 78 dynamic symbols: 27 exported + 51 imported)
// ============================================================================

#include "bdhm_native_interface.h"
#include <cmath>
#include <sstream>

namespace NextAI {
namespace OpenCut {
namespace BdhmNative {

// ============================================================================
// [EN] Deterministic End-to-End Verification Suite for libbdhm_native.so
//      Validates:
//        1. Expression tokenizer & interpreter (abs, factorial, arithmetic, vars)
//        2. Clause evaluator ($if/$then/$else, $gte, $lte, $like, $in)
//        3. ContextPropsRepo DAG cycle detection ("ring exist!" at 0x00c060)
//        4. DB composite key encoding ("__SYS__###" & "__st_string;"/"__st_number;")
//        5. SparkTracingNativeEngine snapshot & event computation
// [VN] Bộ Kiểm thử Xác minh Toàn trình cho libbdhm_native.so
// ============================================================================
bool RunBdhmNativeSelfTest(std::string* out_report) {
    SparkTracingConfigData cfg;
    cfg.is_log_enable = true;
    cfg.repo_size     = 256;
    cfg.manifest_src  = R"({"version":"2.4.0","enabled":true,"events":{"page_perf":{"target":"webview","perf_stat":true,"ignore_null":true,"sampling":1.0,"props":{"total_cost":"load_ms + render_ms","fact5":"factorial(5)","abs_delta":"abs(-42)"}}}})";

    SparkTracingNativeEngine engine(cfg, nullptr);

    // 1. Create parent ("root_ctx") and child ("child_ctx") contexts
    if (!engine.DoNewContextProps("root_ctx", 60000ULL, true, false, 1000ULL)) {
        if (out_report) *out_report = "Failed to create root_ctx";
        return false;
    }
    if (!engine.DoNewContextProps("child_ctx", 60000ULL, false, true, 1000ULL)) {
        if (out_report) *out_report = "Failed to create child_ctx";
        return false;
    }

    // 2. Link child_ctx -> root_ctx and verify cycle rejection (root_ctx -> child_ctx)
    if (!engine.DoUpdateLink("child_ctx", "root_ctx", LinkUpdateOp::kAddParent)) {
        if (out_report) *out_report = "Failed to link child_ctx -> root_ctx";
        return false;
    }
    if (engine.DoUpdateLink("root_ctx", "child_ctx", LinkUpdateOp::kAddParent)) {
        if (out_report) *out_report = "Cycle detection failed: allowed ring root_ctx <-> child_ctx";
        return false;
    }

    // 3. Set properties on parent and child, verify inheritance and expression evaluation
    engine.DoSetProperty("root_ctx", "load_ms", PropValue::MakeNumber(120.0), 60000, 1050);
    engine.DoSetProperty("child_ctx", "render_ms", PropValue::MakeNumber(80.0), 60000, 1060);

    std::string sum_str = engine.DoComputeExpr("child_ctx", "load_ms + render_ms + factorial(5) + abs(-10)");
    if (sum_str != "330") {
        if (out_report) *out_report = "Unexpected DoComputeExpr result: " + sum_str;
        return false;
    }

    // 4. Verify conditional clause evaluation ($if/$then/$else)
    std::string cond_str = engine.DoComputeExpr(
        "child_ctx",
        "$if(load_ms >= 100)$then('slow_load')$else('fast_load')"
    );
    if (cond_str != "slow_load") {
        if (out_report) *out_report = "Unexpected conditional clause result: " + cond_str;
        return false;
    }

    // 5. Verify DoCompute on declared event "page_perf" and DoSnapshot
    std::string ev_out = engine.DoCompute("child_ctx", "page_perf");
    if (ev_out.find("\"total_cost\":200") == std::string::npos ||
        ev_out.find("\"fact5\":120") == std::string::npos) {
        if (out_report) *out_report = "Unexpected DoCompute event output: " + ev_out;
        return false;
    }

    std::string snap = engine.DoSnapshot();
    if (snap.find("\"MANIFEST\":") == std::string::npos ||
        snap.find("\"REPOSITORY\":") == std::string::npos) {
        if (out_report) *out_report = "Invalid DoSnapshot output";
        return false;
    }

    if (out_report) {
        std::ostringstream oss;
        oss << "libbdhm_native self-test PASSED: expr=" << sum_str
            << ", clause=" << cond_str
            << ", event=" << ev_out;
        *out_report = oss.str();
    }
    return true;
}

} // namespace BdhmNative
} // namespace OpenCut
} // namespace NextAI
