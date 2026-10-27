// ============================================================================
// File: applovin_crash_types.h
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// SHA-256: ecf2a7327be482870f4c791392a50cecfeaabb2c76a7224898e9713a18c4c36a
// EN: Exact AArch64 ABI struct layouts for NativeCrashReporterContext
//     (0x0606e8..0x060b4c), AArch64 stack_t, sigaction64, and .bss state globals.
// VI: Bố cục struct ABI AArch64 chính xác cho NativeCrashReporterContext
//     (0x0606e8..0x060b4c), stack_t, sigaction64 và các biến trạng thái .bss.
// ============================================================================
#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <atomic>
#include <exception>

namespace applovin {

struct AArch64SigInfo {
    int32_t si_signo{0};
    int32_t si_errno{0};
    int32_t si_code{0};
    uint32_t pad_0c{0};
    void* si_addr{nullptr};
};

using SignalHandlerFn = void (*)(int, AArch64SigInfo*, void*);
using LegacySignalFn  = void (*)(int);
using TerminateFn     = void (*)();

// EN: 24-byte AArch64 stack_t layout embedded at +0x18 in NativeCrashReporterContext:
//     +0x18: void* ss_sp (`str x0, [x25, #0x18]!` @ 0x06074c)
//     +0x20: int32_t ss_flags (`str wzr, [x19, #0x20]` @ 0x060740; `mov w8, #2 (SS_DISABLE); str w8, [x20, #8]` @ 0x060a38..0x060a44)
//     +0x28: size_t ss_size (`mov w8, #0x8000; str x8, [x19, #0x28]` @ 0x060720..0x06073c)
// VI: Bố cục stack_t 24 byte trên AArch64 nhúng tại +0x18 trong NativeCrashReporterContext:
struct AArch64StackT {
    void*    ss_sp;    // +0x00 (context +0x18)
    int32_t  ss_flags; // +0x08 (context +0x20)
    uint32_t pad_0c;   // +0x0C
    size_t   ss_size;  // +0x10 (context +0x28, 0x8000 = 32,768 bytes)
};
static_assert(sizeof(AArch64StackT) == 24, "AArch64StackT must be 24 bytes");

// EN: 32-byte AArch64 kernel/bionic struct sigaction layout verified at 0x060768..0x060b3c:
//     +0x00: int32_t sa_flags (0x08000004 = SA_SIGINFO | SA_ONSTACK @ 0x060768..0x060778)
//     +0x08: union { SignalHandlerFn sa_sigaction; LegacySignalFn sa_handler; } (`ldr x4, [x8, #8]` @ 0x060b28)
//     +0x10: uint64_t sa_mask
//     +0x18: void* sa_restorer
// VI: Bố cục struct sigaction 32 byte xác minh tại 0x060768..0x060b3c:
struct AArch64SigAction {
    int32_t         sa_flags;     // +0x00
    uint32_t        pad_04;       // +0x04
    SignalHandlerFn sa_sigaction; // +0x08
    uint64_t        sa_mask;      // +0x10
    void*           sa_restorer;  // +0x18
};
static_assert(sizeof(AArch64SigAction) == 32, "AArch64SigAction must be 32 bytes (lsl #5 stride)");

// EN: Exact 112-byte (0x70) ABI layout of NativeCrashReporterContext verified at 0x0606e8..0x060b4c:
//     +0x00: int32_t* signals_begin (`ldp x8, x10, [x0]` @ 0x060abc)
//     +0x08: int32_t* signals_end
//     +0x10: int32_t* signals_cap
//     +0x18: AArch64StackT alt_stack (`ss_sp` @ +0x18, `ss_flags` @ +0x20, `ss_size=0x8000` @ +0x28)
//     +0x30: AArch64SigAction new_action (`sa_flags=0x08000004` @ +0x30, `sa_sigaction` @ +0x38)
//     +0x50: AArch64SigAction* old_actions_begin (`ldr x10, [x0, #0x50]` @ 0x060af0)
//     +0x58: AArch64SigAction* old_actions_end
//     +0x60: AArch64SigAction* old_actions_cap
//     +0x68: TerminateFn old_terminate_handler (`ldr x0, [x0, #0x68]` @ 0x060b40)
// VI: Bố cục ABI 112 byte (0x70) chính xác của NativeCrashReporterContext xác minh tại 0x0606e8..0x060b4c:
struct NativeCrashReporterContextAbiLayout {
    int32_t*          signals_begin;         // +0x00
    int32_t*          signals_end;           // +0x08
    int32_t*          signals_cap;           // +0x10
    AArch64StackT     alt_stack;             // +0x18..0x2F
    AArch64SigAction  new_action;            // +0x30..0x4F
    AArch64SigAction* old_actions_begin;     // +0x50
    AArch64SigAction* old_actions_end;       // +0x58
    AArch64SigAction* old_actions_cap;       // +0x60
    TerminateFn       old_terminate_handler; // +0x68
};
static_assert(offsetof(NativeCrashReporterContextAbiLayout, alt_stack) == 0x18, "alt_stack must be at +0x18");
static_assert(offsetof(NativeCrashReporterContextAbiLayout, new_action) == 0x30, "new_action must be at +0x30");
static_assert(offsetof(NativeCrashReporterContextAbiLayout, old_actions_begin) == 0x50, "old_actions_begin must be at +0x50");
static_assert(offsetof(NativeCrashReporterContextAbiLayout, old_terminate_handler) == 0x68, "old_terminate_handler must be at +0x68");
static_assert(sizeof(NativeCrashReporterContextAbiLayout) == 0x70, "NativeCrashReporterContextAbiLayout must be 0x70 bytes");

} // namespace applovin
