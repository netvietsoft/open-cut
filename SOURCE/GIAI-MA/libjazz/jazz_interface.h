// ============================================================================
// File: jazz_interface.h
// Target: libjazz.so (231,840 bytes, SHA-256: f11496ae99e17699d6f2a2df40043c3014bc8391aab0d6422acc2a63590183e4)
// Subsystem: Master Public Interface & Self-Verification API for libjazz.so
// Task ID: TASK-122-RECONSTRUCTION-LIBJAZZ (TASK_SO_122_libjazz)
// ============================================================================
// [EN] Umbrella public header exporting all reconstructed subsystems of
//      `libjazz.so` (`namespace AmazingEngine`) and the end-to-end verification
//      entry points.
// [VN] File header công khai tổng hợp xuất toàn bộ các phân hệ tái tạo của
//      `libjazz.so` (`namespace AmazingEngine`) và các điểm vào kiểm thử đối soát.
// ============================================================================

#ifndef JAZZ_INTERFACE_H_
#define JAZZ_INTERFACE_H_

#include "jazz_types.h"
#include "jazz_runner_context.h"
#include "jazz_platform_runtime_vm.h"
#include "jazz_modules.h"

namespace AmazingEngine {

// ============================================================================
// Verification Summary Report Structure
// ============================================================================
struct JazzVerificationReport {
    bool sboxFormulaMatchesAll256{false};
    bool sboxIsInvolutionAll256{false};
    bool makeRequireDecodedExact{false};
    bool bootstrapModulesPresent{false};
    bool runnerDelayOrderedExact{false};
    bool contextExecutorWrapsCommonJs{false};
    bool statsModeAndSizeExact{false};
    bool neonPopcountBucketIndexExact{false};
    bool platformRuntimeLifecycleExact{false};
    uint32_t totalPassedChecks{0};
};

// [EN] Runs the deterministic self-verification suite across all reconstructed
//      subsystems of `libjazz.so`.
// [VN] Chạy bộ kiểm thử tự đối soát tất định trên toàn bộ các phân hệ đã tái tạo
//      của `libjazz.so`.
JazzVerificationReport RunJazzSelfVerification();

} // namespace AmazingEngine

#endif // JAZZ_INTERFACE_H_
