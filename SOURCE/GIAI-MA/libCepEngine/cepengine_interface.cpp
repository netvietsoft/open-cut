// ============================================================================
// FILE: cepengine_interface.cpp
// TARGET: libCepEngine.so — NextAI OpenCut CepengineEngine Facade Implementation
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Implements `NextAI::OpenCut::CepEngine::CepengineEngine` over the
//      reconstructed `cep::EngineManager`, `cep::EngineCore`, and `cep::Env`.
// [VN] Cài đặt `NextAI::OpenCut::CepEngine::CepengineEngine` trên nền
//      `cep::EngineManager`, `cep::EngineCore`, và `cep::Env` đã tái cấu trúc.
// ============================================================================

#include "CepEngine_interface.h"

namespace NextAI::OpenCut::CepEngine {

CepengineEngine::CepengineEngine() {
    cep::Env::Instance();
    cep::EngineManager::Instance();
}

CepengineEngine::~CepengineEngine() = default;

int CepengineEngine::GetApiVersion() const {
    return ::ApiVersion(); // @ 0x0c33c -> 2
}

std::string CepengineEngine::GetEngineVersion() const {
    return cep::Env::Instance()->version(); // @ 0x4bfe0 -> "1.5.0"
}

bool CepengineEngine::RegisterRuleJson(const std::string& biz_name,
                                       const std::string& rule_name,
                                       const std::string& rule_json,
                                       bool real_time_process) {
    auto res = cep::EngineManager::Instance()->RegisterRule(
        biz_name, rule_name, rule_json, real_time_process, nullptr, true);
    return res && res->success();
}

std::vector<std::shared_ptr<cep::Result>> CepengineEngine::ProcessEventJson(
    const std::string& biz_name,
    const std::string& rule_name,
    const std::string& event_name,
    const std::string& event_json,
    long long timestamp_ms) {
    auto ev_data = cep::MemoryDataInterface::ParseJson(event_json);
    const long long ts = (timestamp_ms > 0) ? timestamp_ms : cep::GetCurrentTimestamp();
    auto eng_res = cep::EngineCore::SyncProcess(biz_name, rule_name, event_name, ev_data, ts);
    std::vector<std::shared_ptr<cep::Result>> out;
    out.reserve(eng_res.size());
    for (const auto& er : eng_res) {
        if (er) {
            out.push_back(er->ToPublicResult());
        }
    }
    return out;
}

std::string CepengineEngine::CollectCrashDiagnostics() const {
    return cep::EngineManager::Instance()->CollectCrashInfo();
}

} // namespace NextAI::OpenCut::CepEngine
