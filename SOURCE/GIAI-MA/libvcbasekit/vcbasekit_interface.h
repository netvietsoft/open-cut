// ============================================================================
// File: vcbasekit_interface.h
// Target: libvcbasekit.so (231,568 bytes, SHA-256: d5a87dc8436f7ee8aa114f986f5c9c556b534d4dae750d4f69cbc1b38f679129)
// Task ID: TASK-121-RECONSTRUCTION-LIBVCBASEKIT (Legacy: TASK_SO_072_libvcbasekit)
// Classification: CORE_10_MONITORING (ByteDance Video Cloud BaseKit & Embedded JsonCpp)
//
// Description (EN):
// Master public interface header unifying all reconstructed subsystems of
// libvcbasekit.so:
//   - Subsystem A: Embedded JsonCpp (`Json::Value`, `Json::Reader`,
//     `Json::CharReaderBuilder`, `Json::FastWriter`, `Json::StyledWriter`,
//     `Json::StreamWriterBuilder`, `Json::Path`, and 9 numeric limit constants)
//   - Subsystem B: ByteDance `com::ss::vcbkit` (`BaseRef`, `WeakPtr`,
//     `AutoWaitEvent`, `ManualWaitEvent`, `TimePoint<Steady/System/Fast1>`,
//     24-byte 3-tier COW/SSO `String`, `MsgLoop`, `ThreadPoolHelper`, `Daemon`,
//     `vcbkit_init_logger_wrapper`, `JNI_OnLoad`, and `UnExpected`).
//
// Mô tả (VI):
// Header giao diện tổng hợp toàn bộ các phân hệ tái tạo từ libvcbasekit.so:
//   - Phân hệ A: JsonCpp nhúng (`Json::Value`, `Json::Reader`, `Json::Path`, v.v.)
//   - Phân hệ B: Thư viện nền tảng Video Cloud `com::ss::vcbkit` (`BaseRef`,
//     `AutoWaitEvent`, `ManualWaitEvent`, `TimePoint`, chuỗi 3 tầng `String`,
//     `MsgLoop`, `ThreadPoolHelper`, `Daemon`, cầu nối ALOG & JNI `UnExpected`).
// ============================================================================

#pragma once

#include "vcbasekit_types.h"
#include "vcbasekit_jsoncpp.h"
#include "vcbasekit_sync_string.h"
#include "vcbasekit_thread_jni.h"

namespace com {
namespace ss {
namespace vcbkit {

// ============================================================================
// Self-Test & Diagnostic Verification Suite Entry Points
// Điểm vào kiểm thử tự động xác minh toán học và cấu trúc ABI của libvcbasekit.so.
// ============================================================================
struct VcBaseKitAuditResult {
    bool json_limits_verified = false;
    bool json_dom_verified = false;
    bool string_three_tier_verified = false;
    bool timepoint_math_verified = false;
    bool sync_events_verified = false;
    bool msgloop_verified = false;
    int32_t jni_onload_version = 0;
};

VcBaseKitAuditResult runVcBaseKitSelfVerification();

} // namespace vcbkit
} // namespace ss
} // namespace com
