// ============================================================================
// File: sysoptimizer_xhook_unwind.h
// Target: libsysoptimizer.so (412,248 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for getNameFromDex (0x02403c),
//        SmFakeNameHandler_replace (0x0240fc), xHook core/ELF/util engine
//        (0x0243dc..0x026c64), DWARF _Unwind_* / __register_frame* (0x02775c..0x02af30),
//        JNI_OnLoad (0x02cd24), and FDEs 0..249.
//   [VN] Khai báo C++17 sạch cho getNameFromDex, SmFakeNameHandler_replace,
//        xHook core/ELF/util, bộ gỡ khung DWARF _Unwind_*, JNI_OnLoad và FDE 0..249.
// ============================================================================

#pragma once

#include "sysoptimizer_types.h"

namespace bytedance {
namespace sysoptimizer {
namespace xhook {

int32_t CheckElf64AArch64HeaderExact(const Elf64HeaderPrefixAbi* hdr) noexcept;
void ComputeAlignedICacheFlushRange(uintptr_t addr, int32_t page_size, uintptr_t* out_begin, uintptr_t* out_end) noexcept;

uint64_t DispatchXhookUnwindFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace xhook
} // namespace sysoptimizer
} // namespace bytedance
