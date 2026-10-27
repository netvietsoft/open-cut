// ============================================================================
// File: applovin_crash_reporter.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// SHA-256: ecf2a7327be482870f4c791392a50cecfeaabb2c76a7224898e9713a18c4c36a
// EN: Clean-room C++17 implementation of NativeCrashReporterContext (0x0606e8..0x060b4c),
//     atomic crash state machine (0x0618c8..0x061ab0), and JNI entry points
//     Java_com_applovin_impl_sdk_NativeCrashReporter_enable/disable/updateAdInfo.
// VI: Triển khai C++17 phòng sạch cho NativeCrashReporterContext (0x0606e8..0x060b4c),
//     máy trạng thái sập nguyên tử (0x0618c8..0x061ab0) và các điểm nhập JNI.
// ============================================================================
#include "applovin_crash_reporter.h"
#include <cstring>
#include <memory>

namespace applovin {

// .bss @ 0x0d9758..0x0d979c
static std::string g_ad_info_0d9758;
static std::unique_ptr<NativeCrashReporterContext> g_context_0d9788;
static uint8_t g_expected_handling_0d9794 = 0u;
static std::atomic<bool> g_is_handling_crash_0d9798{false};
static std::atomic<bool> g_crash_handled_0d979c{false};

// ============================================================================
// 1. NativeCrashReporterContext (0x0606e8 .. 0x060b4c)
// Disassembly @ 0x060720..0x060778:
//   0x060720: 52900008 mov  w8, #0x8000 (32,768 B alternate signal stack)
//   0x06073c: F9001668 str  x8, [x19, #0x28]
//   0x060740: B900227F str  wzr, [x19, #0x20]
//   0x06074c: F8018F20 str  x0, [x25, #0x18]!
//   0x060768: 52800088 mov  w8, #4
//   0x060770: 72A10008 movk w8, #0x800, lsl #16 (0x08000004 = SA_SIGINFO | SA_ONSTACK)
//   0x060774: F9000358 str  x24, [x26] (+0x38)
//   0x060778: B90002E8 str  w8, [x23] (+0x30)
// ============================================================================
NativeCrashReporterContext::NativeCrashReporterContext(
    const std::vector<int32_t>& signals,
    SignalHandlerFn sig_handler,
    TerminateFn term_handler)
    : signals_storage_(signals),
      old_actions_storage_(signals.size()),
      alt_stack_storage_(0x8000u, 0u) {
    std::memset(&abi_, 0, sizeof(abi_));

    if (!signals_storage_.empty()) {
        abi_.signals_begin = signals_storage_.data();
        abi_.signals_end   = signals_storage_.data() + signals_storage_.size();
        abi_.signals_cap   = abi_.signals_end;
    }

    abi_.alt_stack.ss_sp    = alt_stack_storage_.data();
    abi_.alt_stack.ss_flags = 0;
    abi_.alt_stack.ss_size  = 0x8000u; // 32,768 bytes

    abi_.new_action.sa_flags     = 0x08000004; // SA_SIGINFO (4) | SA_ONSTACK (0x08000000)
    abi_.new_action.sa_sigaction = sig_handler;

    if (!old_actions_storage_.empty()) {
        abi_.old_actions_begin = old_actions_storage_.data();
        abi_.old_actions_end   = old_actions_storage_.data() + old_actions_storage_.size();
        abi_.old_actions_cap   = abi_.old_actions_end;
    }

    abi_.old_terminate_handler = term_handler;
}

// Disassembly @ 0x0609b4..0x060a8c:
//   Restores old terminate handler (+0x68), old sigactions (+0x50), and disables alt_stack (`mov w8, #2 (SS_DISABLE); str w8, [x20, #8]`)
NativeCrashReporterContext::~NativeCrashReporterContext() noexcept {
    abi_.alt_stack.ss_sp    = nullptr;
    abi_.alt_stack.ss_size  = 0u;
    abi_.alt_stack.ss_flags = 2; // SS_DISABLE
}

// Disassembly @ 0x060abc..0x060b3c:
//   0x060abc: A9402808 ldp  x8, x10, [x0]
//   0x060af0: F940280A ldr  x10, [x0, #0x50]
//   0x060afc: 9342FD08 asr  x8, x8, #2
//   0x060b04: 8B081548 add  x8, x10, x8, lsl #5
//   0x060b08: 37100109 tbnz w9, #2, #0x60b28 (SA_SIGINFO bit #2 = 4)
void NativeCrashReporterContext::invoke_old_signal_handler(
    int32_t signo,
    AArch64SigInfo* info,
    void* ucontext) noexcept {
    const int32_t* begin = abi_.signals_begin;
    const int32_t* end   = abi_.signals_end;
    const int32_t* it    = begin;
    while (it != end && *it != signo) {
        ++it;
    }
    if (it == end || !abi_.old_actions_begin) {
        return;
    }
    const ptrdiff_t idx = it - begin;
    const AArch64SigAction& old_act = abi_.old_actions_begin[idx];
    if ((old_act.sa_flags & 4) != 0) {
        if (old_act.sa_sigaction) {
            old_act.sa_sigaction(signo, info, ucontext);
        }
    } else {
        const uintptr_t h = reinterpret_cast<uintptr_t>(old_act.sa_sigaction);
        if (h != 0u && h != 1u) { // Neither SIG_DFL (0) nor SIG_IGN (1)
            reinterpret_cast<LegacySignalFn>(old_act.sa_sigaction)(signo);
        }
    }
}

// Disassembly @ 0x060b40..0x060b4c:
//   0x060b40: F9403400 ldr x0, [x0, #0x68]
//   0x060b44: B4000040 cbz x0, #0x60b4c
//   0x060b48: D61F0000 br  x0
//   0x060b4c: D65F03C0 ret
void NativeCrashReporterContext::invoke_old_terminate_handler() noexcept {
    if (abi_.old_terminate_handler) {
        abi_.old_terminate_handler();
    }
}

// ============================================================================
// 2. Atomic Crash State Machine (0x0618c8 .. 0x061ab0)
// Disassembly @ 0x0618c8..0x0618f0 (crash_detected):
//   0x0618d0: 08DFFD08 ldarb w8, [0x0d9798]
//   0x0618d4: 370000C8 tbnz  w8, #0, #0x618ec
//   0x0618e0: 08DFFD08 ldarb w8, [0x0d979c]
//   0x0618e4: 12000100 and   w0, w8, #1
//   0x0618e8: D65F03C0 ret
// ============================================================================
bool crash_detected() noexcept {
    if (g_is_handling_crash_0d9798.load(std::memory_order_acquire)) {
        return true;
    }
    return g_crash_handled_0d979c.load(std::memory_order_acquire);
}

// Disassembly @ 0x061a24..0x061a90 (begin_handling_crash):
//   0x061a50: 085FFD69 ldaxrb w9, [x11]
//   0x061a54: 6B0A013F cmp    w9, w10
//   0x061a58: 54000121 b.ne   #0x61a7c
//   0x061a5c: 5280002C mov    w12, #1
//   0x061a60: 080DFD6C stlxrb w13, w12, [x11]
//   0x061a64: 35FFFF6D cbnz   w13, #0x61a50
bool begin_handling_crash() noexcept {
    if (!g_context_0d9788) {
        return false;
    }
    if (g_crash_handled_0d979c.load(std::memory_order_acquire)) {
        return false;
    }
    bool expected = (g_expected_handling_0d9794 != 0u);
    if (g_is_handling_crash_0d9798.compare_exchange_strong(expected, true, std::memory_order_acq_rel)) {
        return true;
    }
    g_expected_handling_0d9794 = expected ? 1u : 0u;
    return false;
}

// Disassembly @ 0x061a94..0x061ab0 (end_handling_crash):
//   0x061aa0: 52800029 mov   w9, #1
//   0x061aa8: 089FFD09 stlrb w9, [0x0d979c]
//   0x061aac: 089FFD5F stlrb wzr, [0x0d9798]
//   0x061ab0: D65F03C0 ret
void end_handling_crash() noexcept {
    g_crash_handled_0d979c.store(true, std::memory_order_release);
    g_is_handling_crash_0d9798.store(false, std::memory_order_release);
}

extern "C" {

void Java_com_applovin_impl_sdk_NativeCrashReporter_enable(
    void* /*env*/,
    void* /*thiz*/,
    const int32_t* signals_ptr,
    size_t signals_len) {
    if (g_context_0d9788) {
        return;
    }
    std::vector<int32_t> sigs;
    if (signals_ptr && signals_len > 0) {
        sigs.assign(signals_ptr, signals_ptr + signals_len);
    }
    g_context_0d9788 = std::make_unique<NativeCrashReporterContext>(sigs, nullptr, nullptr);
}

void Java_com_applovin_impl_sdk_NativeCrashReporter_disable(void* /*env*/, void* /*thiz*/) noexcept {
    if (!g_context_0d9788 || crash_detected()) {
        return;
    }
    g_ad_info_0d9758.clear();
    g_context_0d9788.reset();
}

void Java_com_applovin_impl_sdk_NativeCrashReporter_updateAdInfo(
    void* /*env*/,
    void* /*thiz*/,
    const char* ad_info_utf8) {
    if (ad_info_utf8) {
        g_ad_info_0d9758 = ad_info_utf8;
    }
}

} // extern "C"

} // namespace applovin
