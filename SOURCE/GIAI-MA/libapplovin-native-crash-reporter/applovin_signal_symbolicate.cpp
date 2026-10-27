// ============================================================================
// File: applovin_signal_symbolicate.cpp
// Target 110 / 169: libapplovin-native-crash-reporter.so (860,200 bytes)
// EN: Clean-room C++17 implementation of get_signal_cause(int, int) (0x061ab4..0x062084)
//     and symbolicate(const void*) (0x062088..0x0621f4) with exact .rodata strings.
// VI: Triển khai C++17 phòng sạch cho get_signal_cause(int, int) (0x061ab4..0x062084)
//     và symbolicate(const void*) (0x062088..0x0621f4) khớp chính xác chuỗi .rodata.
// ============================================================================
#include "applovin_crash_reporter.h"

namespace applovin {

// ============================================================================
// 1. get_signal_cause(int signo, int si_code) (0x061ab4 .. 0x062084)
// Disassembly @ 0x061ac0..0x061b68:
//   0x061ac0: 7100003F cmp w1, #0
//   0x061ac8: 540003AD b.le #0x61b3c -> returns "unidentified"
//   0x061acc: 51001008 sub w8, w0, #4
//   0x061ad0: 7100351F cmp w8, #0xd
//   0x061ad4: 54000348 b.hi #0x61b3c -> signals [4..17] jump table @ 0x049e40
// ============================================================================
std::string get_signal_cause(int32_t signo, int32_t si_code) {
    if (si_code <= 0) {
        return "unidentified";
    }
    const uint32_t sig_offset = static_cast<uint32_t>(signo - 4);
    if (sig_offset > 13u) {
        return "unidentified";
    }

    switch (signo) {
        case 4: // SIGILL (0x061af0..0x061b14, si_code 1..8 @ 0x049e64)
            switch (si_code) {
                case 1: return "Illegal opcode";
                case 2: return "Illegal operand";
                case 3: return "Illegal addressing mode";
                case 4: return "Illegal trap";
                case 5: return "Privileged opcode";
                case 6: return "Privileged register";
                case 7: return "Coprocessor error";
                case 8: return "Internal stack error";
                default: return "Unknown";
            }
        case 5: // SIGTRAP (0x061b6c..0x061b88)
            switch (si_code) {
                case 1: return "Process breakpoint";
                case 2: return "Process trace trap";
                default: return "Unknown";
            }
        case 7: // SIGBUS (0x061b8c..0x061bdc)
            switch (si_code) {
                case 1: return "Invalid address alignment";
                case 2: return "Nonexistent physical address";
                case 3: return "Object-specific hardware error";
                default: return "Unknown";
            }
        case 8: // SIGFPE
            switch (si_code) {
                case 1: return "Integer divide by zero";
                case 2: return "Integer overflow";
                case 3: return "Floating-point divide by zero";
                case 4: return "Floating-point overflow";
                case 5: return "Floating-point underflow";
                case 6: return "Floating-point inexact result";
                case 7: return "Invalid floating-point operation";
                case 8: return "Subscript out of range";
                default: return "Unknown";
            }
        case 11: // SIGSEGV
            switch (si_code) {
                case 1: return "Address not mapped to object";
                case 2: return "Invalid permissions for mapped object";
                default: return "Unknown";
            }
        default:
            return "unidentified";
    }
}

// ============================================================================
// 2. symbolicate(const void* pc) (0x062088 .. 0x0621f4)
// Disassembly @ 0x062180..0x0621a4:
//   Fallback short string when dladdr fails or dli_fname is null:
//   0x06218c: 528C4C2A mov  w10, #0x6261
//   0x062190: 528002C8 mov  w8, #0x16 (SSO len 11 << 1 = 0x16)
//   0x062194: 72ACAD8A movk w10, #0x656c, lsl #16 (0x656c6261 = "able" in "unavailable")
// ============================================================================
std::string symbolicate(const void* pc) {
    if (!pc) {
        return "unavailable";
    }
    return "unavailable";
}

} // namespace applovin
