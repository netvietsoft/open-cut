// ============================================================================
// File: jato_threads_and_gfx.h
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Clean-room C++17 declarations for ThreadNative, ThreadSuspendTimeout,
//        DeviceInfoUtils, LockMaxSpinsOpt, DecodeJObjectOpt, PriorityManagerV2,
//        ThreadPrioProtector, CpusetManager, SchedulerNativeHolder, HwuiBoost,
//        RenderThreadOpt, BufferBarrier, JNI_OnLoad, and FDEs 1200..1764.
//   [VN] Khai báo C++17 sạch cho ThreadNative, ThreadSuspendTimeout, DeviceInfoUtils,
//        LockMaxSpinsOpt, DecodeJObjectOpt, PriorityManagerV2, ThreadPrioProtector,
//        CpusetManager, SchedulerNativeHolder, HwuiBoost, RenderThreadOpt,
//        BufferBarrier, JNI_OnLoad và FDE 1200..1764.
// ============================================================================

#pragma once

#include "jato_types.h"

namespace bytedance {
namespace jato {
namespace threads {

// [EN] /proc/<pid>/task/<tid>/stat parser (0x018c88, searching for ')' = 0x29 @ 0x018d0c)
// [VN] Bộ phân tích /proc/<pid>/task/<tid>/stat (0x018c88, tìm dấu đóng ngoặc ')' = 0x29 @ 0x018d0c)
bool ParseThreadProcStatLine(const char* stat_line, uint64_t* out_utime, uint64_t* out_stime) noexcept;

// [EN] ThreadSuspendTimeout::setSuspendTimeoutInSeconds (0x03871c: mul x1, x19, 0x3b9aca00)
// [VN] Tính thời gian chờ tạm dừng luồng theo nano giây (0x03871c: nhân với 10^9 = 0x3b9aca00)
uint64_t ComputeSuspendTimeoutNanos(int64_t timeout_seconds) noexcept;

// [EN] LockMaxSpinsOpt::nativeSetMaxSpins (0x01be50: tbnz w2, #0x1f; sxtw x8, w19)
// [VN] Thiết lập số vòng quay tối đa trước khi phóng đại khóa mỏng (0x01be50)
bool SetLockMaxSpinsInternal(int32_t max_spins, uint64_t* target_max_spins_ptr) noexcept;

// [EN] DecodeJObjectOpt_impl (0x01c000..0x01c0dc: scans 0..0x54 for (insn & 0xB84003E0) == 0xB8400000)
// [VN] Quét mã máy AArch64 của DecodeJObject (0x01c000: quét 21 lệnh tìm LDR 0xB8400000)
int32_t ScanDecodeJObjectLdrOffset(const uint32_t* insns, size_t insn_count) noexcept;

// [EN] PriorityManagerV2::nativeSetPriority (0x028234) & nativeResetPriority (0x0283d8)
// [VN] Quản lý độ ưu tiên luồng PriorityManagerV2 (0x028234 & 0x0283d8)
int32_t SetThreadPriorityV2Internal(int32_t tid, int32_t prio) noexcept;
int32_t ResetThreadPriorityV2Internal(int32_t tid) noexcept;

uint64_t DispatchThreadsAndGfxFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept;

} // namespace threads
} // namespace jato
} // namespace bytedance
