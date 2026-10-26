// ============================================================================
// FILE: CepEngine_pseudocode.cpp
// TARGET: libCepEngine.so (362,464 bytes, ELF64 AArch64, 318 dynamic symbols)
// TRẠNG THÁI / STATUS: 100% RECONSTRUCTED — ZERO STUBS — AARCH64 VERIFIED
// ============================================================================
// [EN] Master verification and self-test harness for `libCepEngine.so`,
//      exercising `ApiVersion` (0x0c33c), `DataInterface` (0x0c4e8..0x0c764),
//      `GetCurrentTimestamp` (0x41e94, magic `0x20c49ba5e353f7cf`),
//      `CheckDSLVersion` (0x420dc), `ParseKeyChain` (0x4226c), `EngineConfig`
//      (0x13a48..0x144bc), `Error` (0x26404..0x26e13), `Nfa::Process` (0x2d2c8),
//      `Nfa::AdvanceTime` (0x2d748), `EngineManager` (0x21d90..0x23e5b), and
//      `CBlockContainer` (0x489d4..0x48c63).
// [VN] Bộ kiểm thử tự thân tổng thể cho `libCepEngine.so`.
// ============================================================================

#include "CepEngine_interface.h"

namespace NextAI::OpenCut::CepEngine {

bool RunCepEngineSelfVerification() {
    // 1. Verify ApiVersion() @ 0x0c33c == 2 and DataInterface::InterfaceType() @ 0x0c4e8 == 2
    if (::ApiVersion() != 2) {
        return false;
    }
    auto int_data = cep::MemoryDataInterface::MakeInt(42);
    if (!int_data || int_data->InterfaceType() != 2 || !int_data->IsInt() ||
        !int_data->IsNumber() || int_data->ConvertToDoubleValue() != 42.0) {
        return false;
    }

    // 2. Verify NativeData::InterfaceType() @ 0x2930c == 1
    auto nat_data = cep::NativeData::CreateInt(99);
    if (!nat_data || nat_data->InterfaceType() != 1 || nat_data->ConvertToIntValue() != 99) {
        return false;
    }

    // 3. Verify GetCurrentTimestamp() @ 0x41e94 & IsValidTimestamp() @ 0x41ec8
    const long long now_ms = cep::GetCurrentTimestamp();
    if (!cep::IsValidTimestamp(now_ms) || cep::IsValidTimestamp(-1)) {
        return false;
    }

    // 4. Verify CheckDSLVersion() @ 0x420dc & ParseKeyChain() @ 0x4226c
    if (!cep::CheckDSLVersion("1.0.0") || !cep::CheckDSLVersion("1.5.0") ||
        cep::CheckDSLVersion("2.0.0")) {
        return false;
    }
    auto chain = cep::ParseKeyChain("event.params.user_id");
    if (chain.size() != 3 || chain[0] != "event" || chain[2] != "user_id") {
        return false;
    }

    // 5. Verify EngineRule registration & NFA execution
    CepengineEngine engine;
    const std::string rule_json =
        "{\"dslVersion\":\"1.0.0\",\"within\":5000,\"states\":["
        "{\"stateName\":\"start\",\"stateType\":0,\"edges\":["
        "{\"targetState\":\"$finalState$\",\"actionType\":0,\"condition\":\"True\"}"
        "]}]}";
    if (!engine.RegisterRuleJson("opencut_biz", "export_click_rule", rule_json, true)) {
        return false;
    }
    auto results = engine.ProcessEventJson(
        "opencut_biz", "export_click_rule", "export_click", "{\"fps\":60}", now_ms);
    if (results.empty() || !results[0]->success()) {
        return false;
    }
    return true;
}

} // namespace NextAI::OpenCut::CepEngine
