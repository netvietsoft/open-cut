// ==============================================================================
// FILE: ttmachinecore_interface.cpp
// TARGET: libTTMachineCore.so (429,872 bytes, 830 dynamic symbols, 19 JNI methods)
// PURPOSE: Implementation of Unified Facade `TtmachinecoreEngine`
//          (Triển khai lớp Facade hợp nhất `TtmachinecoreEngine`)
// EVIDENCE CLASSIFICATION: OBSERVED (AArch64 Disassembly & Symbol Cross-References)
// ==============================================================================

#include "TTMachineCore_interface.h"

namespace NextAI::OpenCut::TTMachineCore {

TtmachinecoreEngine::TtmachinecoreEngine() {
    Initialize();
}

TtmachinecoreEngine::~TtmachinecoreEngine() {
    Shutdown();
}

bool TtmachinecoreEngine::Initialize() {
    if (initialized_) {
        return true;
    }
    TTMUniversalBdiFunLoader core_loader;
    AnTTMUniversalBdiFunLoader android_loader;
    (void)core_loader;
    (void)android_loader;
    initialized_ = true;
    return true;
}

void TtmachinecoreEngine::Shutdown() {
    if (!initialized_) {
        return;
    }
    ttm_am_clean_objs(nullptr);
    initialized_ = false;
}

std::int32_t TtmachinecoreEngine::ExecuteBytecode(
    const std::vector<std::uint8_t>& bytecode,
    TTMRegisterSlot& out_result) {
    if (!initialized_) {
        return TTMStateErrorCodeTTMIsUnEnable;
    }
    if (bytecode.empty()) {
        return TTMStateErrorCodeBytecodeIsNull;
    }
    __TTMTransparentStruct ctx{};
    return ttm_state_mn_run_with_bytes(bytecode.data(), bytecode.size(), &ctx, &out_result);
}

std::int32_t TtmachinecoreEngine::FormatBusinessErrorCode(
    std::int32_t base_code,
    std::int32_t sub_code) const noexcept {
    return ttm_state_error_code_for_business(base_code, sub_code);
}

} // namespace NextAI::OpenCut::TTMachineCore
