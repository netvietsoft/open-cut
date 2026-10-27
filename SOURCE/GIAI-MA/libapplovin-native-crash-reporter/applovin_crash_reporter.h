// ============================================================================
// File: applovin_crash_reporter.h
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Declarations for NativeCrashReporterContext, crash_detected (0x0618c8),
//     begin_handling_crash (0x061a24), end_handling_crash (0x061a94),
//     get_signal_cause (0x061ab4), symbolicate (0x062088), and FDE dispatcher.
// VI: Khai báo cho NativeCrashReporterContext, crash_detected (0x0618c8),
//     begin_handling_crash (0x061a24), end_handling_crash (0x061a94),
//     get_signal_cause (0x061ab4), symbolicate (0x062088) và bộ điều phối FDE.
// ============================================================================
#pragma once

#include "applovin_crash_types.h"

namespace applovin {

class NativeCrashReporterContext {
public:
    // 0x0606e8..0x0609b0
    NativeCrashReporterContext(
        const std::vector<int32_t>& signals,
        SignalHandlerFn sig_handler,
        TerminateFn term_handler);

    // 0x0609b4..0x060a8c
    ~NativeCrashReporterContext() noexcept;

    // 0x060abc..0x060b3c
    void invoke_old_signal_handler(int32_t signo, AArch64SigInfo* info, void* ucontext) noexcept;

    // 0x060b40..0x060b4c
    void invoke_old_terminate_handler() noexcept;

    const NativeCrashReporterContextAbiLayout& Abi() const noexcept { return abi_; }

private:
    NativeCrashReporterContextAbiLayout abi_{};
    std::vector<int32_t> signals_storage_;
    std::vector<AArch64SigAction> old_actions_storage_;
    std::vector<uint8_t> alt_stack_storage_;
};

// 0x0618c8..0x0618f0
bool crash_detected() noexcept;

// 0x061a24..0x061a90
bool begin_handling_crash() noexcept;

// 0x061a94..0x061ab0
void end_handling_crash() noexcept;

// 0x061ab4..0x062084
std::string get_signal_cause(int32_t signo, int32_t si_code);

// 0x062088..0x0621f4
std::string symbolicate(const void* pc);

uint64_t ExecuteAppLovinFdeByAddress(uint64_t fde_pc_begin, uint64_t arg0, uint64_t arg1, uint64_t arg2) noexcept;

} // namespace applovin
