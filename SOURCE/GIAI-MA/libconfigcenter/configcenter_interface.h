// ============================================================================
// File: configcenter_interface.h
// Library: libconfigcenter.so (51,144 bytes, 65 dynamic symbols, ARM64-v8a)
// Task ID: TASK-089-RECONSTRUCTION-LIBCONFIGCENTER (Target 50 / TASK_SO_150)
// Description:
//   EN: Unified public C++17 interface for libconfigcenter.so, aggregating
//       configcenter_types.h, configcenter_base_config.h, and
//       configcenter_manager_jni.h, plus closed-loop verification harness.
//   VN: Giao diện C++17 công khai hợp nhất cho libconfigcenter.so, tích hợp
//       configcenter_types.h, configcenter_base_config.h, và
//       configcenter_manager_jni.h, kèm bộ kiểm chứng khép kín.
// ============================================================================

#pragma once

#include "configcenter_types.h"
#include "configcenter_base_config.h"
#include "configcenter_manager_jni.h"

namespace NextAI {
namespace OpenCut {
namespace configcenter {

class ConfigcenterEngine {
public:
    ConfigcenterEngine() noexcept;
    virtual ~ConfigcenterEngine() = default;

    // EN: Executes a comprehensive closed-loop verification of BaseConfig
    //     priority-gated options, atomic permission freeze, ConfigCenter
    //     module slots, observer notification, and AArch64 hash math.
    // VN: Thực thi kiểm chứng khép kín toàn diện cho các tùy chọn theo độ ưu
    //     tiên của BaseConfig, đóng băng quyền nguyên tử, các khe mô-đun của
    //     ConfigCenter, thông báo bộ lắng nghe, và toán học băm AArch64.
    bool RunSelfTest() const;
};

} // namespace configcenter
} // namespace OpenCut
} // namespace NextAI
