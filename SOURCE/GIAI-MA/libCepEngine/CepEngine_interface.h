// ============================================================================
// FILE: CepEngine_interface.h
// TARGET: libCepEngine.so (362,464 bytes, ELF64 AArch64, 318 dynamic symbols)
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Master umbrella C++17 interface header for `libCepEngine.so`, unifying
//      `cepengine_types.h`, `cepengine_data_error_utils.h`,
//      `cepengine_nfa_evaluator.h`, `cepengine_manager_core.h`, and
//      `cepengine_platform_jni.h`.
// [VN] Header giao diện tổng C++17 cho `libCepEngine.so`, hợp nhất
//      `cepengine_types.h`, `cepengine_data_error_utils.h`,
//      `cepengine_nfa_evaluator.h`, `cepengine_manager_core.h`, và
//      `cepengine_platform_jni.h`.
// ============================================================================

#pragma once

#include "cepengine_types.h"
#include "cepengine_data_error_utils.h"
#include "cepengine_nfa_evaluator.h"
#include "cepengine_manager_core.h"
#include "cepengine_platform_jni.h"

namespace NextAI::OpenCut::CepEngine {

// [EN] High-level NextAI OpenCut orchestrator facade wrapping `cep::EngineManager`
//      and `cep::Env` for CapCut / Pitaya Complex Event Processing rules.
// [VN] Facade điều phối cấp cao của NextAI OpenCut bọc `cep::EngineManager`
//      và `cep::Env` cho các quy tắc xử lý sự kiện phức hợp CapCut / Pitaya.
class CepengineEngine {
public:
    CepengineEngine();
    virtual ~CepengineEngine();

    int GetApiVersion() const;
    std::string GetEngineVersion() const;
    bool RegisterRuleJson(const std::string& biz_name,
                          const std::string& rule_name,
                          const std::string& rule_json,
                          bool real_time_process = true);
    std::vector<std::shared_ptr<cep::Result>> ProcessEventJson(
        const std::string& biz_name,
        const std::string& rule_name,
        const std::string& event_name,
        const std::string& event_json,
        long long timestamp_ms = 0);
    std::string CollectCrashDiagnostics() const;
};

} // namespace NextAI::OpenCut::CepEngine
