// ============================================================================
// Clean-Room C++17 Core Header for libnpth_fp_unw.so (Target 124 / 169)
// Giao diện lõi C++17 sạch cho libnpth_fp_unw.so (Mục tiêu 124 / 169)
// ============================================================================
#pragma once

#include "npth_fp_unw_types.h"

namespace npth_fp_unw {

// Callback resolver interface matching dladdr(const void* addr, Dl_info* info) (@ PLT 0x0e20)
using DlAddrResolverFn = int (*)(const void* addr, BionicDlInfoAbi* info);

// Internal variadic formatter at 0x000c78..0x000d14 (`vsnprintf(dst, 0x400, fmt, ap)`)
// Hàm định dạng chuỗi nội bộ tại 0x000c78..0x000d14
int FormatBacktraceLine(char* dst_1024, const char* fmt, ...) noexcept;

// Unwinds an AArch64 frame-pointer chain starting from `initial_fp` (`x29`)
// exakt matching `npth_fp_frames` at 0x0009e0..0x000abc:
// Lần ngược chuỗi con trỏ khung AArch64 từ `initial_fp` (`x29`) khớp tuyệt đối `npth_fp_frames` (0x09e0..0x0abc):
size_t UnwindFramePointerChain(
    uintptr_t* out_frames,
    size_t max_frames,
    uintptr_t initial_fp) noexcept;

// Formats an array of PCs into an Android tombstone backtrace string using `resolver`
// exact matching `npth_fp_format` at 0x000abc..0x000c78:
// Định dạng mảng PC thành chuỗi backtrace kiểu Android tombstone khớp tuyệt đối `npth_fp_format` (0x0abc..0x0c78):
char* FormatBacktraceFramesWithResolver(
    const uintptr_t* frames,
    size_t frame_count,
    DlAddrResolverFn resolver) noexcept;

// Executes any of the 252 AArch64 instructions in .text (0x0990..0x0d80) for binary verification
uint64_t ExecuteTextInstructionForensicCheck(uint32_t insn_idx, uint64_t seed) noexcept;

} // namespace npth_fp_unw

extern "C" {
// 3 Exported C Symbols in .dynsym (indices [12..14]):
// 3 biểu tượng C xuất khẩu trong bảng .dynsym ([12..14]):
size_t npth_fp_frames(uintptr_t* out_frames, size_t max_frames); // 0x0009e0 (220 B)
char*  npth_fp_format(const uintptr_t* frames, size_t count);    // 0x000abc (444 B)
char*  npth_fp_fast();                                           // 0x000d14 (108 B)
}
