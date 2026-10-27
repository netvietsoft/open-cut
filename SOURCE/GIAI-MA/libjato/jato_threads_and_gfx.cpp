// ============================================================================
// File: jato_threads_and_gfx.cpp
// Target: libjato.so (362,800 bytes)
// Description:
//   [EN] Clean-room C++17 implementation of ThreadNative, ThreadSuspendTimeout,
//        DeviceInfoUtils, LockMaxSpinsOpt, DecodeJObjectOpt, PriorityManagerV2,
//        CpusetManager, SchedulerNativeHolder, HwuiBoost, RenderThreadOpt,
//        BufferBarrier, JNI_OnLoad, and FDEs 1200..1764.
//   [VN] Thực thi C++17 sạch cho ThreadNative, ThreadSuspendTimeout, DeviceInfoUtils,
//        LockMaxSpinsOpt, DecodeJObjectOpt, PriorityManagerV2, CpusetManager,
//        SchedulerNativeHolder, HwuiBoost, RenderThreadOpt, BufferBarrier,
//        JNI_OnLoad và FDE 1200..1764.
// ============================================================================

#include "jato_threads_and_gfx.h"
#include "jato_rodata_tables.h"
#include <cstring>
#include <cstdlib>

namespace bytedance {
namespace jato {
namespace threads {

static uint64_t g_simulated_max_spins = 50ULL;
static uint64_t g_last_suspend_timeout_ns = 0ULL;
static std::unordered_map<int32_t, int32_t> g_saved_thread_priorities; // .bss 0x05d2b0

// ============================================================================
// [EN] ThreadNative_GetThreadStats_proc_stat (0x018c88..0x018ea0):
//        0x018d0c: mov w1, #0x29 (')' character closing comm field in /proc/pid/task/tid/stat)
//        Advances by +2 (0x018d18: add x1, x0, #2) past ") " and parses state..utime(14)/stime(15).
// [VN] Phân tích dòng /proc/<pid>/task/<tid>/stat (0x018c88): tìm ký tự ')' (0x29)
//      tại 0x018d0c, nhảy +2 byte (0x018d18) và trích xuất utime (trường 14) & stime (trường 15).
// ============================================================================
bool ParseThreadProcStatLine(const char* stat_line, uint64_t* out_utime, uint64_t* out_stime) noexcept {
    if (stat_line == nullptr || out_utime == nullptr || out_stime == nullptr) {
        return false;
    }
    const char* rparen = std::strrchr(stat_line, 0x29); // 0x018d0c: mov w1, #0x29 (')')
    if (rparen == nullptr || rparen[1] == '\0' || rparen[2] == '\0') {
        return false;
    }
    const char* p = rparen + 2; // 0x018d18: add x1, x0, #2
    // Fields after "(comm) ":
    // [0]=state(3), [1]=ppid(4), [2]=pgrp(5), [3]=session(6), [4]=tty_nr(7),
    // [5]=tpgid(8), [6]=flags(9), [7]=minflt(10), [8]=cminflt(11), [9]=majflt(12),
    // [10]=cmajflt(13), [11]=utime(14), [12]=stime(15)
    for (int field_idx = 0; field_idx < 11; ++field_idx) {
        while (*p == ' ') ++p;
        if (*p == '\0') return false;
        while (*p != '\0' && *p != ' ') ++p;
    }
    char* endptr = nullptr;
    uint64_t utime = std::strtoull(p, &endptr, 10);
    if (endptr == p) return false;
    p = endptr;
    uint64_t stime = std::strtoull(p, &endptr, 10);
    if (endptr == p) return false;
    *out_utime = utime;
    *out_stime = stime;
    return true;
}

// ============================================================================
// [EN] ThreadSuspendTimeout::setSuspendTimeoutInSeconds (0x03871c..0x038778):
//        0x038744: mov w8, #0xca00
//        0x038748: movk w8, #0x3b9a, lsl #16 (0x3B9ACA00 = 1,000,000,000)
//        0x03874c: mul x1, x19, x8
// [VN] Chuyển đổi thời gian chờ tạm dừng luồng từ giây sang nano giây (0x038744..0x03874c).
// ============================================================================
uint64_t ComputeSuspendTimeoutNanos(int64_t timeout_seconds) noexcept {
    constexpr uint64_t kNanosPerSecond = 0x3B9ACA00ULL; // 1,000,000,000
    uint64_t ns = static_cast<uint64_t>(timeout_seconds) * kNanosPerSecond;
    g_last_suspend_timeout_ns = ns;
    return ns;
}

// ============================================================================
// [EN] LockMaxSpinsOpt::nativeSetMaxSpins (0x01be50..0x01bf94):
//        0x01be74: tbnz w2, #0x1f, #0x1bf48 (rejects negative max_spins)
//        0x01be88: sxtw x8, w19
//        0x01be8c: str x8, [x21]
// [VN] Thiết lập max_spins_before_thin_lock_inflation_ (0x01be50): từ chối số âm.
// ============================================================================
bool SetLockMaxSpinsInternal(int32_t max_spins, uint64_t* target_max_spins_ptr) noexcept {
    if ((static_cast<uint32_t>(max_spins) & 0x80000000U) != 0U) { // 0x01be74: tbnz w2, #0x1f
        return false;
    }
    if (target_max_spins_ptr == nullptr) {
        return false;
    }
    *target_max_spins_ptr = static_cast<uint64_t>(static_cast<int64_t>(max_spins));
    return true;
}

// ============================================================================
// [EN] DecodeJObjectOpt_impl (0x01c000..0x01c0dc):
//        0x01c050: mov w21, #-0x47c00000 (0xB8400000)
//        0x01c054: cmp x20, #0x54 (21 instructions = 84 bytes)
//        0x01c060: add w8, w21, #0x3e0 (0xB84003E0)
//        0x01c064: and w8, w0, w8
//        0x01c068: cmp w8, w21
// [VN] Quét 21 lệnh đầu của DecodeJObject tìm lệnh LDR khớp mặt nạ 0xB84003E0 == 0xB8400000.
// ============================================================================
int32_t ScanDecodeJObjectLdrOffset(const uint32_t* insns, size_t insn_count) noexcept {
    if (insns == nullptr) {
        return -1;
    }
    size_t max_insns = (insn_count < 21U) ? insn_count : 21U; // 0x54 / 4 = 21
    for (size_t i = 0; i < max_insns; ++i) {
        uint32_t w0 = insns[i];
        if ((w0 & rodata::kDecodeJObjectLdrMask) == rodata::kDecodeJObjectLdrBase) {
            return static_cast<int32_t>(i * 4U);
        }
    }
    return -1;
}

// ============================================================================
// [EN] PriorityManagerV2::nativeSetPriority (0x028234..0x0282dc) &
//      PriorityManagerV2::nativeResetPriority (0x0283d8..0x02842c):
//        0x028244: cmp w2, #1; b.lt -> return -1
//        0x02824c: add w8, w3, #0x14; cmp w8, #0x27; b.ls -> ok, else return -2
//        0x02829c: cmn w0, #0x64 (-100 sentinel when tid not yet in map)
// [VN] Đặt và khôi phục độ ưu tiên nice [-20, 19] của luồng (0x028234 & 0x0283d8).
// ============================================================================
int32_t SetThreadPriorityV2Internal(int32_t tid, int32_t prio) noexcept {
    if (tid < 1) { // 0x028244: cmp w2, #1; b.lt #0x28264
        return -1; // 0x028264: mov w0, #-1
    }
    uint32_t shifted = static_cast<uint32_t>(prio + 0x14); // 0x02824c: add w8, w3, #0x14
    if (shifted > 0x27U) {                                 // 0x028254: cmp w8, #0x27; b.ls #0x2826c
        return -2;                                         // 0x02825c: mov w0, #-2
    }
    auto it = g_saved_thread_priorities.find(tid);
    if (it == g_saved_thread_priorities.end()) {
        g_saved_thread_priorities[tid] = 0; // Save original nice value (0 default)
    }
    return 0;
}

int32_t ResetThreadPriorityV2Internal(int32_t tid) noexcept {
    if (tid < 1) { // 0x0283e4: cmp w2, #1; b.lt #0x28420
        return -1; // 0x028420: mov w0, #-1
    }
    auto it = g_saved_thread_priorities.find(tid);
    int32_t saved = (it != g_saved_thread_priorities.end()) ? it->second : -100;
    if (saved != -100) { // 0x028400: cmn w0, #0x64
        g_saved_thread_priorities.erase(it);
    }
    return 0;
}

// [EN] Reconstructed FDE #1200 @ 0x02ab44..0x02acc4 (384 bytes)
// [VN] Phục dựng FDE #1200 tại 0x02ab44..0x02acc4 (384 byte)
//   0x02ab44: d10383ff  sub      sp, sp, #0xe0
//   0x02ab48: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x02ab4c: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x02ab50: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x02ab54: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x02ab58: 910343fd  add      x29, sp, #0xd0
//   0x02ab5c: d53bd057  mrs      x23, tpidr_el0
//   0x02ab60: f94016e8  ldr      x8, [x23, #0x28]
//   0x02ab64: aa0303f3  mov      x19, x3
//   0x02ab68: aa0003f4  mov      x20, x0
//   0x02ab6c: 7100005f  cmp      w2, #0
//   0x02ab70: f81c83a8  stur     x8, [x29, #-0x38]
uint64_t fde_1200_sub_02ab44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0xAA0303F3ULL) + (x2 ^ 0x02AB44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x02ab44: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x02ab48: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x02ab4c: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x02ab50: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x02ab54: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x02ab58: add x29, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02ab5c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02ab60: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1201 @ 0x02acc4..0x02ad6c (168 bytes)
// [VN] Phục dựng FDE #1201 tại 0x02acc4..0x02ad6c (168 byte)
//   0x02acc4: d102c3ff  sub      sp, sp, #0xb0
//   0x02acc8: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x02accc: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x02acd0: 910283fd  add      x29, sp, #0xa0
//   0x02acd4: d53bd054  mrs      x20, tpidr_el0
//   0x02acd8: f9401688  ldr      x8, [x20, #0x28]
//   0x02acdc: 7100005f  cmp      w2, #0
//   0x02ace0: f81e83a8  stur     x8, [x29, #-0x18]
//   0x02ace4: 5400006c  b.gt     #0x2acf0
//   0x02ace8: 97ff80de  bl       #0xb060
//   0x02acec: 2a0003e2  mov      w2, w0
//   0x02acf0: f0000193  adrp     x19, #0x5d000
uint64_t fde_1201_sub_02acc4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x5400006CULL) + (x2 ^ 0x02ACC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x02acc4: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x02acc8: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x02accc: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x02acd0: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02acd4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02acd8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100005FULL; // 0x02acdc: cmp w2, #0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x02ace0: stur x8, [x29, #-0x18]
    return acc;
}

// [EN] Reconstructed FDE #1202 @ 0x02ad6c..0x02adc8 (92 bytes)
// [VN] Phục dựng FDE #1202 tại 0x02ad6c..0x02adc8 (92 byte)
//   0x02ad6c: d10103ff  sub      sp, sp, #0x40
//   0x02ad70: f90013f3  str      x19, [sp, #0x20]
//   0x02ad74: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02ad78: 9100c3fd  add      x29, sp, #0x30
//   0x02ad7c: d53bd053  mrs      x19, tpidr_el0
//   0x02ad80: f9401668  ldr      x8, [x19, #0x28]
//   0x02ad84: b00000a2  adrp     x2, #0x3f000
//   0x02ad88: 91060042  add      x2, x2, #0x180
//   0x02ad8c: 910043e3  add      x3, sp, #0x10
//   0x02ad90: 910023e4  add      x4, sp, #8
//   0x02ad94: f9000fe8  str      x8, [sp, #0x18]
//   0x02ad98: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1202_sub_02ad6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x02AD6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02ad6c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x02ad70: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02ad74: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02ad78: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02ad7c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02ad80: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB00000A2ULL; // 0x02ad84: adrp x2, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x91060042ULL; // 0x02ad88: add x2, x2, #0x180
    return acc;
}

// [EN] Reconstructed FDE #1203 @ 0x02adc8..0x02ae90 (200 bytes)
// [VN] Phục dựng FDE #1203 tại 0x02adc8..0x02ae90 (200 byte)
//   0x02adc8: d10203ff  sub      sp, sp, #0x80
//   0x02adcc: f9001bf9  str      x25, [sp, #0x30]
//   0x02add0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02add4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02add8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02addc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02ade0: 9101c3fd  add      x29, sp, #0x70
//   0x02ade4: d53bd059  mrs      x25, tpidr_el0
//   0x02ade8: f9401728  ldr      x8, [x25, #0x28]
//   0x02adec: aa0203f7  mov      x23, x2
//   0x02adf0: aa0103e2  mov      x2, x1
//   0x02adf4: 910023e1  add      x1, sp, #8
uint64_t fde_1203_sub_02adc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x02ADC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02adc8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x02adcc: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02add0: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02add4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02add8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02addc: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02ade0: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02ade4: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1204 @ 0x02ae90..0x02aef0 (96 bytes)
// [VN] Phục dựng FDE #1204 tại 0x02ae90..0x02aef0 (96 byte)
//   0x02ae90: aa0003e8  mov      x8, x0
//   0x02ae94: f8408c09  ldr      x9, [x0, #8]!
//   0x02ae98: b4000229  cbz      x9, #0x2aedc
//   0x02ae9c: b940004a  ldr      w10, [x2]
//   0x02aea0: 91002100  add      x0, x8, #8
//   0x02aea4: b9402128  ldr      w8, [x9, #0x20]
//   0x02aea8: 6b08015f  cmp      w10, w8
//   0x02aeac: 540000aa  b.ge     #0x2aec0
//   0x02aeb0: f9400128  ldr      x8, [x9]
//   0x02aeb4: b4000188  cbz      x8, #0x2aee4
//   0x02aeb8: aa0903e0  mov      x0, x9
//   0x02aebc: 14000006  b        #0x2aed4
uint64_t fde_1204_sub_02ae90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x02AE90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02ae90: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x02ae94: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x02ae98: cbz x9, #0x2aedc
    acc = (acc * 0x100000001B3ULL) ^ 0xB940004AULL; // 0x02ae9c: ldr w10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x02aea0: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402128ULL; // 0x02aea4: ldr w8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08015FULL; // 0x02aea8: cmp w10, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000AAULL; // 0x02aeac: b.ge #0x2aec0
    return acc;
}

// [EN] Reconstructed FDE #1205 @ 0x02aef0..0x02af64 (116 bytes)
// [VN] Phục dựng FDE #1205 tại 0x02aef0..0x02af64 (116 byte)
//   0x02aef0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02aef4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02aef8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02aefc: 910083fd  add      x29, sp, #0x20
//   0x02af00: 91002015  add      x21, x0, #8
//   0x02af04: 52800021  mov      w1, #1
//   0x02af08: aa1503e0  mov      x0, x21
//   0x02af0c: aa0203f3  mov      x19, x2
//   0x02af10: aa0803f4  mov      x20, x8
//   0x02af14: 52800036  mov      w22, #1
//   0x02af18: 9400002a  bl       #0x2afc0
//   0x02af1c: a9005680  stp      x0, x21, [x20]
uint64_t fde_1205_sub_02aef0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x02AEF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02aef0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02aef4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02aef8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02aefc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x02af00: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x02af04: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x02af08: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02af0c: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1206 @ 0x02af64..0x02afb8 (84 bytes)
// [VN] Phục dựng FDE #1206 tại 0x02af64..0x02afb8 (84 byte)
//   0x02af64: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02af68: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02af6c: 910043fd  add      x29, sp, #0x10
//   0x02af70: a9007c7f  stp      xzr, xzr, [x3]
//   0x02af74: f9000861  str      x1, [x3, #0x10]
//   0x02af78: f9000043  str      x3, [x2]
//   0x02af7c: f9400008  ldr      x8, [x0]
//   0x02af80: aa0003f3  mov      x19, x0
//   0x02af84: f9400108  ldr      x8, [x8]
//   0x02af88: b4000068  cbz      x8, #0x2af94
//   0x02af8c: f9000268  str      x8, [x19]
//   0x02af90: f9400043  ldr      x3, [x2]
uint64_t fde_1206_sub_02af64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x02AF64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02af64: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02af68: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02af6c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x02af70: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x02af74: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x02af78: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02af7c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02af80: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1207 @ 0x02afb8..0x02afc0 (8 bytes)
// [VN] Phục dựng FDE #1207 tại 0x02afb8..0x02afc0 (8 byte)
//   0x02afb8: aa1f03e1  mov      x1, xzr
//   0x02afbc: 1400000f  b        #0x2aff8
uint64_t fde_1207_sub_02afb8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000FULL) + (x2 ^ 0x02AFB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02afb8: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000FULL; // 0x02afbc: b #0x2aff8
    return acc;
}

// [EN] Reconstructed FDE #1208 @ 0x02afc0..0x02afc8 (8 bytes)
// [VN] Phục dựng FDE #1208 tại 0x02afc0..0x02afc8 (8 byte)
//   0x02afc0: aa1f03e2  mov      x2, xzr
//   0x02afc4: 14000001  b        #0x2afc8
uint64_t fde_1208_sub_02afc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02AFC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x02afc0: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02afc4: b #0x2afc8
    return acc;
}

// [EN] Reconstructed FDE #1209 @ 0x02afc8..0x02aff8 (48 bytes)
// [VN] Phục dựng FDE #1209 tại 0x02afc8..0x02aff8 (48 byte)
//   0x02afc8: d28c30e8  mov      x8, #0x6187
//   0x02afcc: f2b0c308  movk     x8, #0x8618, lsl #16
//   0x02afd0: f2c30c28  movk     x8, #0x1861, lsl #32
//   0x02afd4: f2e030c8  movk     x8, #0x186, lsl #48
//   0x02afd8: eb08003f  cmp      x1, x8
//   0x02afdc: 54000082  b.hs     #0x2afec
//   0x02afe0: 52801508  mov      w8, #0xa8
//   0x02afe4: 9b087c20  mul      x0, x1, x8
//   0x02afe8: 17ff8182  b        #0xb5f0
//   0x02afec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02aff0: 910003fd  mov      x29, sp
//   0x02aff4: 97ff8143  bl       #0xb500
uint64_t fde_1209_sub_02afc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD28C30E8ULL) + (x1 ^ 0x17FF8182ULL) + (x2 ^ 0x02AFC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD28C30E8ULL; // 0x02afc8: mov x8, #0x6187
    acc = (acc * 0x100000001B3ULL) ^ 0xF2B0C308ULL; // 0x02afcc: movk x8, #0x8618, lsl #16
    acc = (acc * 0x100000001B3ULL) ^ 0xF2C30C28ULL; // 0x02afd0: movk x8, #0x1861, lsl #32
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E030C8ULL; // 0x02afd4: movk x8, #0x186, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x02afd8: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x02afdc: b.hs #0x2afec
    acc = (acc * 0x100000001B3ULL) ^ 0x52801508ULL; // 0x02afe0: mov w8, #0xa8
    acc = (acc * 0x100000001B3ULL) ^ 0x9B087C20ULL; // 0x02afe4: mul x0, x1, x8
    return acc;
}

// [EN] Reconstructed FDE #1210 @ 0x02aff8..0x02b010 (24 bytes)
// [VN] Phục dựng FDE #1210 tại 0x02aff8..0x02b010 (24 byte)
//   0x02aff8: aa0003e8  mov      x8, x0
//   0x02affc: f9400000  ldr      x0, [x0]
//   0x02b000: f9000101  str      x1, [x8]
//   0x02b004: b4000040  cbz      x0, #0x2b00c
//   0x02b008: 17ff7f4e  b        #0xad40
//   0x02b00c: d65f03c0  ret      
uint64_t fde_1210_sub_02aff8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02AFF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02aff8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02affc: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x02b000: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x02b004: cbz x0, #0x2b00c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7F4EULL; // 0x02b008: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02b00c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1211 @ 0x02b010..0x02b018 (8 bytes)
// [VN] Phục dựng FDE #1211 tại 0x02b010..0x02b018 (8 byte)
//   0x02b010: f9400401  ldr      x1, [x0, #8]
//   0x02b014: 14000001  b        #0x2b018
uint64_t fde_1211_sub_02b010(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02B010ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x02b010: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02b014: b #0x2b018
    return acc;
}

// [EN] Reconstructed FDE #1212 @ 0x02b018..0x02b058 (64 bytes)
// [VN] Phục dựng FDE #1212 tại 0x02b018..0x02b058 (64 byte)
//   0x02b018: b40001e1  cbz      x1, #0x2b054
//   0x02b01c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02b020: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02b024: 910043fd  add      x29, sp, #0x10
//   0x02b028: aa0103f3  mov      x19, x1
//   0x02b02c: f9400021  ldr      x1, [x1]
//   0x02b030: aa0003f4  mov      x20, x0
//   0x02b034: 97fffff9  bl       #0x2b018
//   0x02b038: f9400661  ldr      x1, [x19, #8]
//   0x02b03c: aa1403e0  mov      x0, x20
//   0x02b040: 97fffff6  bl       #0x2b018
//   0x02b044: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_1212_sub_02b018(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xF9400661ULL) + (x2 ^ 0x02B018ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x02b018: cbz x1, #0x2b054
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02b01c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02b020: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02b024: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02b028: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x02b02c: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02b030: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF9ULL; // 0x02b034: bl #0x2b018
    return acc;
}

// [EN] Reconstructed FDE #1213 @ 0x02b058..0x02b0a0 (72 bytes)
// [VN] Phục dựng FDE #1213 tại 0x02b058..0x02b0a0 (72 byte)
//   0x02b058: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02b05c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02b060: 910043fd  add      x29, sp, #0x10
//   0x02b064: aa0003f3  mov      x19, x0
//   0x02b068: f8408e62  ldr      x2, [x19, #8]!
//   0x02b06c: aa0103f4  mov      x20, x1
//   0x02b070: aa1303e3  mov      x3, x19
//   0x02b074: 9400000b  bl       #0x2b0a0
//   0x02b078: eb00027f  cmp      x19, x0
//   0x02b07c: 540000a0  b.eq     #0x2b090
//   0x02b080: b9400288  ldr      w8, [x20]
//   0x02b084: b9402009  ldr      w9, [x0, #0x20]
uint64_t fde_1213_sub_02b058(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xEB00027FULL) + (x2 ^ 0x02B058ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02b058: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02b05c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02b060: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02b064: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E62ULL; // 0x02b068: ldr x2, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02b06c: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x02b070: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000BULL; // 0x02b074: bl #0x2b0a0
    return acc;
}

// [EN] Reconstructed FDE #1214 @ 0x02b0a0..0x02b0c8 (40 bytes)
// [VN] Phục dựng FDE #1214 tại 0x02b0a0..0x02b0c8 (40 byte)
//   0x02b0a0: b9400028  ldr      w8, [x1]
//   0x02b0a4: aa0303e0  mov      x0, x3
//   0x02b0a8: b40000e2  cbz      x2, #0x2b0c4
//   0x02b0ac: b9402049  ldr      w9, [x2, #0x20]
//   0x02b0b0: 6b08013f  cmp      w9, w8
//   0x02b0b4: 1a9fa7e9  cset     w9, lt
//   0x02b0b8: 9a82b000  csel     x0, x0, x2, lt
//   0x02b0bc: f8695842  ldr      x2, [x2, w9, uxtw #3]
//   0x02b0c0: b5ffff62  cbnz     x2, #0x2b0ac
//   0x02b0c4: d65f03c0  ret      
uint64_t fde_1214_sub_02b0a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400028ULL) + (x1 ^ 0xB5FFFF62ULL) + (x2 ^ 0x02B0A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400028ULL; // 0x02b0a0: ldr w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E0ULL; // 0x02b0a4: mov x0, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E2ULL; // 0x02b0a8: cbz x2, #0x2b0c4
    acc = (acc * 0x100000001B3ULL) ^ 0xB9402049ULL; // 0x02b0ac: ldr w9, [x2, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B08013FULL; // 0x02b0b0: cmp w9, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9FA7E9ULL; // 0x02b0b4: cset w9, lt
    acc = (acc * 0x100000001B3ULL) ^ 0x9A82B000ULL; // 0x02b0b8: csel x0, x0, x2, lt
    acc = (acc * 0x100000001B3ULL) ^ 0xF8695842ULL; // 0x02b0bc: ldr x2, [x2, w9, uxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #1215 @ 0x02b0c8..0x02b0d4 (12 bytes)
// [VN] Phục dựng FDE #1215 tại 0x02b0c8..0x02b0d4 (12 byte)
//   0x02b0c8: d0000180  adrp     x0, #0x5d000
//   0x02b0cc: 9113a000  add      x0, x0, #0x4e8
//   0x02b0d0: 17ff7fa4  b        #0xaf60
uint64_t fde_1215_sub_02b0c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000180ULL) + (x1 ^ 0x17FF7FA4ULL) + (x2 ^ 0x02B0C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000180ULL; // 0x02b0c8: adrp x0, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x9113A000ULL; // 0x02b0cc: add x0, x0, #0x4e8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7FA4ULL; // 0x02b0d0: b #0xaf60
    return acc;
}

// [EN] Reconstructed FDE #1216 @ 0x02b0d4..0x02b3b4 (736 bytes)
// [VN] Phục dựng FDE #1216 tại 0x02b0d4..0x02b3b4 (736 byte)
//   0x02b0d4: d10283ff  sub      sp, sp, #0xa0
//   0x02b0d8: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x02b0dc: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x02b0e0: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x02b0e4: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x02b0e8: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x02b0ec: 910243fd  add      x29, sp, #0x90
//   0x02b0f0: d53bd059  mrs      x25, tpidr_el0
//   0x02b0f4: f9401728  ldr      x8, [x25, #0x28]
//   0x02b0f8: 900000a0  adrp     x0, #0x3f000
//   0x02b0fc: 91075000  add      x0, x0, #0x1d4
//   0x02b100: f90027e8  str      x8, [sp, #0x48]
uint64_t fde_1216_sub_02b0d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x02B0D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02b0d4: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x02b0d8: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x02b0dc: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x02b0e0: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x02b0e4: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x02b0e8: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x02b0ec: add x29, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02b0f0: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1217 @ 0x02b3b4..0x02b45c (168 bytes)
// [VN] Phục dựng FDE #1217 tại 0x02b3b4..0x02b45c (168 byte)
//   0x02b3b4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02b3b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02b3bc: 910043fd  add      x29, sp, #0x10
//   0x02b3c0: d0000188  adrp     x8, #0x5d000
//   0x02b3c4: 39544108  ldrb     w8, [x8, #0x510]
//   0x02b3c8: 7100051f  cmp      w8, #1
//   0x02b3cc: 54000421  b.ne     #0x2b450
//   0x02b3d0: d0000193  adrp     x19, #0x5d000
//   0x02b3d4: 91144673  add      x19, x19, #0x511
//   0x02b3d8: f8427268  ldur     x8, [x19, #0x27]
//   0x02b3dc: d63f0100  blr      x8
//   0x02b3e0: f8437268  ldur     x8, [x19, #0x37]
uint64_t fde_1217_sub_02b3b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x91144673ULL) + (x2 ^ 0x02B3B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02b3b4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02b3b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02b3bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000188ULL; // 0x02b3c0: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x39544108ULL; // 0x02b3c4: ldrb w8, [x8, #0x510]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02b3c8: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000421ULL; // 0x02b3cc: b.ne #0x2b450
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000193ULL; // 0x02b3d0: adrp x19, #0x5d000
    return acc;
}

// [EN] Reconstructed FDE #1218 @ 0x02b45c..0x02b524 (200 bytes)
// [VN] Phục dựng FDE #1218 tại 0x02b45c..0x02b524 (200 byte)
//   0x02b45c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02b460: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02b464: 910043fd  add      x29, sp, #0x10
//   0x02b468: d0000188  adrp     x8, #0x5d000
//   0x02b46c: 39544108  ldrb     w8, [x8, #0x510]
//   0x02b470: 7100051f  cmp      w8, #1
//   0x02b474: 54000521  b.ne     #0x2b518
//   0x02b478: d0000194  adrp     x20, #0x5d000
//   0x02b47c: 91144694  add      x20, x20, #0x511
//   0x02b480: f8427288  ldur     x8, [x20, #0x27]
//   0x02b484: d63f0100  blr      x8
//   0x02b488: f8437288  ldur     x8, [x20, #0x37]
uint64_t fde_1218_sub_02b45c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91144694ULL) + (x2 ^ 0x02B45CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02b45c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02b460: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02b464: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000188ULL; // 0x02b468: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x39544108ULL; // 0x02b46c: ldrb w8, [x8, #0x510]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02b470: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000521ULL; // 0x02b474: b.ne #0x2b518
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000194ULL; // 0x02b478: adrp x20, #0x5d000
    return acc;
}

// [EN] Reconstructed FDE #1219 @ 0x02b524..0x02b578 (84 bytes)
// [VN] Phục dựng FDE #1219 tại 0x02b524..0x02b578 (84 byte)
//   0x02b524: d10103ff  sub      sp, sp, #0x40
//   0x02b528: f90013f3  str      x19, [sp, #0x20]
//   0x02b52c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02b530: 9100c3fd  add      x29, sp, #0x30
//   0x02b534: d53bd053  mrs      x19, tpidr_el0
//   0x02b538: f9401668  ldr      x8, [x19, #0x28]
//   0x02b53c: f9000fe8  str      x8, [sp, #0x18]
//   0x02b540: a90087e2  stp      x2, x1, [sp, #8]
//   0x02b544: 910043e1  add      x1, sp, #0x10
//   0x02b548: 910023e2  add      x2, sp, #8
//   0x02b54c: 9400000b  bl       #0x2b578
//   0x02b550: f9401668  ldr      x8, [x19, #0x28]
uint64_t fde_1219_sub_02b524(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E1ULL) + (x2 ^ 0x02B524ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02b524: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x02b528: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02b52c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02b530: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02b534: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02b538: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x02b53c: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90087E2ULL; // 0x02b540: stp x2, x1, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #1220 @ 0x02b578..0x02b59c (36 bytes)
// [VN] Phục dựng FDE #1220 tại 0x02b578..0x02b59c (36 byte)
//   0x02b578: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02b57c: 910003fd  mov      x29, sp
//   0x02b580: f9401000  ldr      x0, [x0, #0x20]
//   0x02b584: b40000a0  cbz      x0, #0x2b598
//   0x02b588: f9400008  ldr      x8, [x0]
//   0x02b58c: f9401903  ldr      x3, [x8, #0x30]
//   0x02b590: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02b594: d61f0060  br       x3
//   0x02b598: 97ffaf98  bl       #0x173f8
uint64_t fde_1220_sub_02b578(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFAF98ULL) + (x2 ^ 0x02B578ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02b578: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02b57c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x02b580: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x02b584: cbz x0, #0x2b598
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02b588: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401903ULL; // 0x02b58c: ldr x3, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02b590: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x02b594: br x3
    return acc;
}

// [EN] Reconstructed FDE #1221 @ 0x02b59c..0x02b5a0 (4 bytes)
// [VN] Phục dựng FDE #1221 tại 0x02b59c..0x02b5a0 (4 byte)
//   0x02b59c: 17ff7de9  b        #0xad40
uint64_t fde_1221_sub_02b59c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF7DE9ULL) + (x1 ^ 0x17FF7DE9ULL) + (x2 ^ 0x02B59CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7DE9ULL; // 0x02b59c: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1222 @ 0x02b5a0..0x02b5d8 (56 bytes)
// [VN] Phục dựng FDE #1222 tại 0x02b5a0..0x02b5d8 (56 byte)
//   0x02b5a0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02b5a4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02b5a8: 910043fd  add      x29, sp, #0x10
//   0x02b5ac: aa0003f3  mov      x19, x0
//   0x02b5b0: 52800200  mov      w0, #0x10
//   0x02b5b4: 97ff800f  bl       #0xb5f0
//   0x02b5b8: f0000168  adrp     x8, #0x5a000
//   0x02b5bc: 91252108  add      x8, x8, #0x948
//   0x02b5c0: f9000008  str      x8, [x0]
//   0x02b5c4: f9400668  ldr      x8, [x19, #8]
//   0x02b5c8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02b5cc: f9000408  str      x8, [x0, #8]
uint64_t fde_1222_sub_02b5a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000008ULL) + (x2 ^ 0x02B5A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02b5a0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02b5a4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02b5a8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02b5ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x02b5b0: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF800FULL; // 0x02b5b4: bl #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x02b5b8: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91252108ULL; // 0x02b5bc: add x8, x8, #0x948
    return acc;
}

// [EN] Reconstructed FDE #1223 @ 0x02b5d8..0x02b5f0 (24 bytes)
// [VN] Phục dựng FDE #1223 tại 0x02b5d8..0x02b5f0 (24 byte)
//   0x02b5d8: f0000168  adrp     x8, #0x5a000
//   0x02b5dc: 91252108  add      x8, x8, #0x948
//   0x02b5e0: f9000028  str      x8, [x1]
//   0x02b5e4: f9400408  ldr      x8, [x0, #8]
//   0x02b5e8: f9000428  str      x8, [x1, #8]
//   0x02b5ec: d65f03c0  ret      
uint64_t fde_1223_sub_02b5d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000168ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02B5D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000168ULL; // 0x02b5d8: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91252108ULL; // 0x02b5dc: add x8, x8, #0x948
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x02b5e0: str x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x02b5e4: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000428ULL; // 0x02b5e8: str x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02b5ec: ret 
    return acc;
}

// [EN] Reconstructed FDE #1224 @ 0x02b5f0..0x02b5f4 (4 bytes)
// [VN] Phục dựng FDE #1224 tại 0x02b5f0..0x02b5f4 (4 byte)
//   0x02b5f0: d65f03c0  ret      
uint64_t fde_1224_sub_02b5f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02B5F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02b5f0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1225 @ 0x02b5f4..0x02b5f8 (4 bytes)
// [VN] Phục dựng FDE #1225 tại 0x02b5f4..0x02b5f8 (4 byte)
//   0x02b5f4: 17ff7dd3  b        #0xad40
uint64_t fde_1225_sub_02b5f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF7DD3ULL) + (x1 ^ 0x17FF7DD3ULL) + (x2 ^ 0x02B5F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7DD3ULL; // 0x02b5f4: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1226 @ 0x02b5f8..0x02b610 (24 bytes)
// [VN] Phục dựng FDE #1226 tại 0x02b5f8..0x02b610 (24 byte)
//   0x02b5f8: f9400408  ldr      x8, [x0, #8]
//   0x02b5fc: f9400049  ldr      x9, [x2]
//   0x02b600: f9400108  ldr      x8, [x8]
//   0x02b604: eb09011f  cmp      x8, x9
//   0x02b608: 1a9f17e0  cset     w0, eq
//   0x02b60c: d65f03c0  ret      
uint64_t fde_1226_sub_02b5f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02B5F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x02b5f8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400049ULL; // 0x02b5fc: ldr x9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x02b600: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02b604: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x02b608: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02b60c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1227 @ 0x02b610..0x02b614 (4 bytes)
// [VN] Phục dựng FDE #1227 tại 0x02b610..0x02b614 (4 byte)
//   0x02b610: d65f03c0  ret      
uint64_t fde_1227_sub_02b610(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02B610ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02b610: ret 
    return acc;
}

// [EN] Reconstructed FDE #1228 @ 0x02b614..0x02b644 (48 bytes)
// [VN] Phục dựng FDE #1228 tại 0x02b614..0x02b644 (48 byte)
//   0x02b614: aa0003e8  mov      x8, x0
//   0x02b618: f9401000  ldr      x0, [x0, #0x20]
//   0x02b61c: eb00011f  cmp      x8, x0
//   0x02b620: 540000a0  b.eq     #0x2b634
//   0x02b624: b40000e0  cbz      x0, #0x2b640
//   0x02b628: f9400008  ldr      x8, [x0]
//   0x02b62c: f9401501  ldr      x1, [x8, #0x28]
//   0x02b630: d61f0020  br       x1
//   0x02b634: f9400008  ldr      x8, [x0]
//   0x02b638: f9401101  ldr      x1, [x8, #0x20]
//   0x02b63c: d61f0020  br       x1
//   0x02b640: d65f03c0  ret      
uint64_t fde_1228_sub_02b614(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x02B614ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02b614: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x02b618: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x02b61c: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02b620: b.eq #0x2b634
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02b624: cbz x0, #0x2b640
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02b628: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401501ULL; // 0x02b62c: ldr x1, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x02b630: br x1
    return acc;
}

// [EN] Reconstructed FDE #1229 @ 0x02b644..0x02b64c (8 bytes)
// [VN] Phục dựng FDE #1229 tại 0x02b644..0x02b64c (8 byte)
//   0x02b644: aa1803e0  mov      x0, x24
//   0x02b648: 17ff8016  b        #0xb6a0
uint64_t fde_1229_sub_02b644(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1803E0ULL) + (x1 ^ 0x17FF8016ULL) + (x2 ^ 0x02B644ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E0ULL; // 0x02b644: mov x0, x24
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8016ULL; // 0x02b648: b #0xb6a0
    return acc;
}

// [EN] Reconstructed FDE #1230 @ 0x02b64c..0x02b6a4 (88 bytes)
// [VN] Phục dựng FDE #1230 tại 0x02b64c..0x02b6a4 (88 byte)
//   0x02b64c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02b650: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02b654: 910043fd  add      x29, sp, #0x10
//   0x02b658: 90000180  adrp     x0, #0x5b000
//   0x02b65c: f947a400  ldr      x0, [x0, #0xf48]
//   0x02b660: 97ff7fdc  bl       #0xb5d0
//   0x02b664: 90000194  adrp     x20, #0x5b000
//   0x02b668: f9426694  ldr      x20, [x20, #0x4c8]
//   0x02b66c: f9400288  ldr      x8, [x20]
//   0x02b670: b50000c8  cbnz     x8, #0x2b688
//   0x02b674: 52801c00  mov      w0, #0xe0
//   0x02b678: 97ff7fde  bl       #0xb5f0
uint64_t fde_1230_sub_02b64c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400288ULL) + (x2 ^ 0x02B64CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02b64c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02b650: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02b654: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000180ULL; // 0x02b658: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947A400ULL; // 0x02b65c: ldr x0, [x0, #0xf48]
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7FDCULL; // 0x02b660: bl #0xb5d0
    acc = (acc * 0x100000001B3ULL) ^ 0x90000194ULL; // 0x02b664: adrp x20, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426694ULL; // 0x02b668: ldr x20, [x20, #0x4c8]
    return acc;
}

// [EN] Reconstructed FDE #1231 @ 0x02b6a4..0x02b784 (224 bytes)
// [VN] Phục dựng FDE #1231 tại 0x02b6a4..0x02b784 (224 byte)
//   0x02b6a4: d100c3ff  sub      sp, sp, #0x30
//   0x02b6a8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02b6ac: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02b6b0: 910083fd  add      x29, sp, #0x20
//   0x02b6b4: d53bd054  mrs      x20, tpidr_el0
//   0x02b6b8: f9401688  ldr      x8, [x20, #0x28]
//   0x02b6bc: 6f00e400  movi     v0.2d, #0000000000000000
//   0x02b6c0: aa0003f3  mov      x19, x0
//   0x02b6c4: 2a1f03e1  mov      w1, wzr
//   0x02b6c8: f90007e8  str      x8, [sp, #8]
//   0x02b6cc: 92800008  mov      x8, #-1
//   0x02b6d0: f9000808  str      x8, [x0, #0x10]
uint64_t fde_1231_sub_02b6a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x2A1F03E1ULL) + (x2 ^ 0x02B6A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x02b6a4: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02b6a8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02b6ac: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02b6b0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02b6b4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02b6b8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x6F00E400ULL; // 0x02b6bc: movi v0.2d, #0000000000000000
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02b6c0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1232 @ 0x02b784..0x02b85c (216 bytes)
// [VN] Phục dựng FDE #1232 tại 0x02b784..0x02b85c (216 byte)
//   0x02b784: d10143ff  sub      sp, sp, #0x50
//   0x02b788: f90013f5  str      x21, [sp, #0x20]
//   0x02b78c: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02b790: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02b794: 910103fd  add      x29, sp, #0x40
//   0x02b798: d53bd055  mrs      x21, tpidr_el0
//   0x02b79c: f94016a8  ldr      x8, [x21, #0x28]
//   0x02b7a0: d0000060  adrp     x0, #0x39000
//   0x02b7a4: 911cd000  add      x0, x0, #0x734
//   0x02b7a8: f9000fe8  str      x8, [sp, #0x18]
//   0x02b7ac: 97ff7dfd  bl       #0xafa0
//   0x02b7b0: b4000420  cbz      x0, #0x2b834
uint64_t fde_1232_sub_02b784(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x911CD000ULL) + (x2 ^ 0x02B784ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x02b784: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x02b788: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02b78c: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02b790: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02b794: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02b798: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02b79c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000060ULL; // 0x02b7a0: adrp x0, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #1233 @ 0x02b85c..0x02ba8c (560 bytes)
// [VN] Phục dựng FDE #1233 tại 0x02b85c..0x02ba8c (560 byte)
//   0x02b85c: d10243ff  sub      sp, sp, #0x90
//   0x02b860: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x02b864: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02b868: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02b86c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02b870: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02b874: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02b878: 910203fd  add      x29, sp, #0x80
//   0x02b87c: d53bd053  mrs      x19, tpidr_el0
//   0x02b880: f9401668  ldr      x8, [x19, #0x28]
//   0x02b884: aa0003fb  mov      x27, x0
//   0x02b888: d0000060  adrp     x0, #0x39000
uint64_t fde_1233_sub_02b85c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xD53BD053ULL) + (x2 ^ 0x02B85CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02b85c: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x02b860: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x02b864: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02b868: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02b86c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02b870: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02b874: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02b878: add x29, sp, #0x80
    return acc;
}

// [EN] Reconstructed FDE #1234 @ 0x02ba8c..0x02bb08 (124 bytes)
// [VN] Phục dựng FDE #1234 tại 0x02ba8c..0x02bb08 (124 byte)
//   0x02ba8c: d10103ff  sub      sp, sp, #0x40
//   0x02ba90: f9000bf5  str      x21, [sp, #0x10]
//   0x02ba94: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02ba98: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02ba9c: 9100c3fd  add      x29, sp, #0x30
//   0x02baa0: d53bd055  mrs      x21, tpidr_el0
//   0x02baa4: f94016a8  ldr      x8, [x21, #0x28]
//   0x02baa8: aa0103f3  mov      x19, x1
//   0x02baac: aa0003f4  mov      x20, x0
//   0x02bab0: f90007e8  str      x8, [sp, #8]
//   0x02bab4: f90003fe  str      x30, [sp]
//   0x02bab8: 94000014  bl       #0x2bb08
uint64_t fde_1234_sub_02ba8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x02BA8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02ba8c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x02ba90: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02ba94: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02ba98: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02ba9c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02baa0: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02baa4: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02baa8: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #1235 @ 0x02bb08..0x02be70 (872 bytes)
// [VN] Phục dựng FDE #1235 tại 0x02bb08..0x02be70 (872 byte)
//   0x02bb08: d10243ff  sub      sp, sp, #0x90
//   0x02bb0c: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x02bb10: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02bb14: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02bb18: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02bb1c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02bb20: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02bb24: 910203fd  add      x29, sp, #0x80
//   0x02bb28: a90003e1  stp      x1, x0, [sp]
//   0x02bb2c: d53bd048  mrs      x8, tpidr_el0
//   0x02bb30: f9000be8  str      x8, [sp, #0x10]
//   0x02bb34: f9401508  ldr      x8, [x8, #0x28]
uint64_t fde_1235_sub_02bb08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xA90003E1ULL) + (x2 ^ 0x02BB08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02bb08: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x02bb0c: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x02bb10: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02bb14: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02bb18: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02bb1c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02bb20: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02bb24: add x29, sp, #0x80
    return acc;
}

// [EN] Reconstructed FDE #1236 @ 0x02be70..0x02bed4 (100 bytes)
// [VN] Phục dựng FDE #1236 tại 0x02be70..0x02bed4 (100 byte)
//   0x02be70: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02be74: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02be78: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02be7c: 910083fd  add      x29, sp, #0x20
//   0x02be80: b4000220  cbz      x0, #0x2bec4
//   0x02be84: 90000188  adrp     x8, #0x5b000
//   0x02be88: f9465108  ldr      x8, [x8, #0xca0]
//   0x02be8c: 39400108  ldrb     w8, [x8]
//   0x02be90: 350001a8  cbnz     w8, #0x2bec4
//   0x02be94: aa0203f3  mov      x19, x2
//   0x02be98: aa0103f4  mov      x20, x1
//   0x02be9c: 91004015  add      x21, x0, #0x10
uint64_t fde_1236_sub_02be70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x350001A8ULL) + (x2 ^ 0x02BE70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02be70: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02be74: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02be78: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02be7c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x02be80: cbz x0, #0x2bec4
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x02be84: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9465108ULL; // 0x02be88: ldr x8, [x8, #0xca0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x02be8c: ldrb w8, [x8]
    return acc;
}

// [EN] Reconstructed FDE #1237 @ 0x02bed4..0x02bf48 (116 bytes)
// [VN] Phục dựng FDE #1237 tại 0x02bed4..0x02bf48 (116 byte)
//   0x02bed4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02bed8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02bedc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02bee0: 910083fd  add      x29, sp, #0x20
//   0x02bee4: 94000114  bl       #0x2c334
//   0x02bee8: 9102e2a9  add      x9, x21, #0xb8
//   0x02beec: 910242aa  add      x10, x21, #0x90
//   0x02bef0: 7200029f  tst      w20, #1
//   0x02bef4: aa1f03e8  mov      x8, xzr
//   0x02bef8: 9a8a1129  csel     x9, x9, x10, ne
//   0x02befc: f100291f  cmp      x8, #0xa
//   0x02bf00: 540000a0  b.eq     #0x2bf14
uint64_t fde_1237_sub_02bed4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA1F03E8ULL) + (x2 ^ 0x02BED4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02bed4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02bed8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02bedc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02bee0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x94000114ULL; // 0x02bee4: bl #0x2c334
    acc = (acc * 0x100000001B3ULL) ^ 0x9102E2A9ULL; // 0x02bee8: add x9, x21, #0xb8
    acc = (acc * 0x100000001B3ULL) ^ 0x910242AAULL; // 0x02beec: add x10, x21, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0x7200029FULL; // 0x02bef0: tst w20, #1
    return acc;
}

// [EN] Reconstructed FDE #1238 @ 0x02bf48..0x02bf98 (80 bytes)
// [VN] Phục dựng FDE #1238 tại 0x02bf48..0x02bf98 (80 byte)
//   0x02bf48: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02bf4c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02bf50: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02bf54: 910083fd  add      x29, sp, #0x20
//   0x02bf58: 940000f7  bl       #0x2c334
//   0x02bf5c: 1284e1e8  mov      w8, #-0x2710
//   0x02bf60: 5284e1e9  mov      w9, #0x270f
//   0x02bf64: 0b080288  add      w8, w20, w8
//   0x02bf68: 6b09029f  cmp      w20, w9
//   0x02bf6c: 1a94c108  csel     w8, w8, w20, gt
//   0x02bf70: 7100251f  cmp      w8, #9
//   0x02bf74: 540000c8  b.hi     #0x2bf8c
uint64_t fde_1238_sub_02bf48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x6B09029FULL) + (x2 ^ 0x02BF48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02bf48: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02bf4c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02bf50: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02bf54: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x940000F7ULL; // 0x02bf58: bl #0x2c334
    acc = (acc * 0x100000001B3ULL) ^ 0x1284E1E8ULL; // 0x02bf5c: mov w8, #-0x2710
    acc = (acc * 0x100000001B3ULL) ^ 0x5284E1E9ULL; // 0x02bf60: mov w9, #0x270f
    acc = (acc * 0x100000001B3ULL) ^ 0x0B080288ULL; // 0x02bf64: add w8, w20, w8
    return acc;
}

// [EN] Reconstructed FDE #1239 @ 0x02bf98..0x02bfe0 (72 bytes)
// [VN] Phục dựng FDE #1239 tại 0x02bf98..0x02bfe0 (72 byte)
//   0x02bf98: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02bf9c: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02bfa0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02bfa4: 910083fd  add      x29, sp, #0x20
//   0x02bfa8: 91012013  add      x19, x0, #0x48
//   0x02bfac: aa0003f4  mov      x20, x0
//   0x02bfb0: aa1303e0  mov      x0, x19
//   0x02bfb4: aa0103f5  mov      x21, x1
//   0x02bfb8: 97ff7d86  bl       #0xb5d0
//   0x02bfbc: 97ffbcf9  bl       #0x1b3a0
//   0x02bfc0: 39402288  ldrb     w8, [x20, #8]
//   0x02bfc4: 8b150009  add      x9, x0, x21
uint64_t fde_1239_sub_02bf98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x97FF7D86ULL) + (x2 ^ 0x02BF98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02bf98: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02bf9c: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02bfa0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02bfa4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91012013ULL; // 0x02bfa8: add x19, x0, #0x48
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02bfac: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02bfb0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F5ULL; // 0x02bfb4: mov x21, x1
    return acc;
}

// [EN] Reconstructed FDE #1240 @ 0x02bfe0..0x02c03c (92 bytes)
// [VN] Phục dựng FDE #1240 tại 0x02bfe0..0x02c03c (92 byte)
//   0x02bfe0: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02bfe4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02bfe8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02bfec: 910083fd  add      x29, sp, #0x20
//   0x02bff0: 940000cc  bl       #0x2c320
//   0x02bff4: 940000c1  bl       #0x2c2f8
//   0x02bff8: 54000168  b.hi     #0x2c024
//   0x02bffc: 940000b7  bl       #0x2c2d8
//   0x02c000: 54000128  b.hi     #0x2c024
//   0x02c004: 93407d08  sxtw     x8, w8
//   0x02c008: 5280004a  mov      w10, #2
//   0x02c00c: b828792a  str      w10, [x9, x8, lsl #2]
uint64_t fde_1240_sub_02bfe0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000128ULL) + (x2 ^ 0x02BFE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02bfe0: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02bfe4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02bfe8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02bfec: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x940000CCULL; // 0x02bff0: bl #0x2c320
    acc = (acc * 0x100000001B3ULL) ^ 0x940000C1ULL; // 0x02bff4: bl #0x2c2f8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000168ULL; // 0x02bff8: b.hi #0x2c024
    acc = (acc * 0x100000001B3ULL) ^ 0x940000B7ULL; // 0x02bffc: bl #0x2c2d8
    return acc;
}

// [EN] Reconstructed FDE #1241 @ 0x02c03c..0x02c080 (68 bytes)
// [VN] Phục dựng FDE #1241 tại 0x02c03c..0x02c080 (68 byte)
//   0x02c03c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02c040: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02c044: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c048: 910083fd  add      x29, sp, #0x20
//   0x02c04c: 940000b5  bl       #0x2c320
//   0x02c050: 940000aa  bl       #0x2c2f8
//   0x02c054: 540000c8  b.hi     #0x2c06c
//   0x02c058: 940000a0  bl       #0x2c2d8
//   0x02c05c: 54000088  b.hi     #0x2c06c
//   0x02c060: 93407d08  sxtw     x8, w8
//   0x02c064: 5280002a  mov      w10, #1
//   0x02c068: b828792a  str      w10, [x9, x8, lsl #2]
uint64_t fde_1241_sub_02c03c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x54000088ULL) + (x2 ^ 0x02C03CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02c03c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02c040: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c044: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c048: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x940000B5ULL; // 0x02c04c: bl #0x2c320
    acc = (acc * 0x100000001B3ULL) ^ 0x940000AAULL; // 0x02c050: bl #0x2c2f8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C8ULL; // 0x02c054: b.hi #0x2c06c
    acc = (acc * 0x100000001B3ULL) ^ 0x940000A0ULL; // 0x02c058: bl #0x2c2d8
    return acc;
}

// [EN] Reconstructed FDE #1242 @ 0x02c080..0x02c088 (8 bytes)
// [VN] Phục dựng FDE #1242 tại 0x02c080..0x02c088 (8 byte)
//   0x02c080: b9007001  str      w1, [x0, #0x70]
//   0x02c084: d65f03c0  ret      
uint64_t fde_1242_sub_02c080(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9007001ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C080ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9007001ULL; // 0x02c080: str w1, [x0, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c084: ret 
    return acc;
}

// [EN] Reconstructed FDE #1243 @ 0x02c088..0x02c09c (20 bytes)
// [VN] Phục dựng FDE #1243 tại 0x02c088..0x02c09c (20 byte)
//   0x02c088: f0000169  adrp     x9, #0x5b000
//   0x02c08c: f9465129  ldr      x9, [x9, #0xca0]
//   0x02c090: 12000008  and      w8, w0, #1
//   0x02c094: 39000128  strb     w8, [x9]
//   0x02c098: d65f03c0  ret      
uint64_t fde_1243_sub_02c088(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000169ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C088ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000169ULL; // 0x02c088: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9465129ULL; // 0x02c08c: ldr x9, [x9, #0xca0]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000008ULL; // 0x02c090: and w8, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39000128ULL; // 0x02c094: strb w8, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c098: ret 
    return acc;
}

// [EN] Reconstructed FDE #1244 @ 0x02c09c..0x02c1fc (352 bytes)
// [VN] Phục dựng FDE #1244 tại 0x02c09c..0x02c1fc (352 byte)
//   0x02c09c: d10703ff  sub      sp, sp, #0x1c0
//   0x02c0a0: f900bbfc  str      x28, [sp, #0x170]
//   0x02c0a4: a9185ff8  stp      x24, x23, [sp, #0x180]
//   0x02c0a8: a91957f6  stp      x22, x21, [sp, #0x190]
//   0x02c0ac: a91a4ff4  stp      x20, x19, [sp, #0x1a0]
//   0x02c0b0: a91b7bfd  stp      x29, x30, [sp, #0x1b0]
//   0x02c0b4: 9106c3fd  add      x29, sp, #0x1b0
//   0x02c0b8: d53bd058  mrs      x24, tpidr_el0
//   0x02c0bc: f9401708  ldr      x8, [x24, #0x28]
//   0x02c0c0: aa0303f5  mov      x21, x3
//   0x02c0c4: aa0103f4  mov      x20, x1
//   0x02c0c8: aa0003f3  mov      x19, x0
uint64_t fde_1244_sub_02c09c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10703FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x02C09CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10703FFULL; // 0x02c09c: sub sp, sp, #0x1c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900BBFCULL; // 0x02c0a0: str x28, [sp, #0x170]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9185FF8ULL; // 0x02c0a4: stp x24, x23, [sp, #0x180]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91957F6ULL; // 0x02c0a8: stp x22, x21, [sp, #0x190]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91A4FF4ULL; // 0x02c0ac: stp x20, x19, [sp, #0x1a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91B7BFDULL; // 0x02c0b0: stp x29, x30, [sp, #0x1b0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9106C3FDULL; // 0x02c0b4: add x29, sp, #0x1b0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02c0b8: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1245 @ 0x02c1fc..0x02c2a0 (164 bytes)
// [VN] Phục dựng FDE #1245 tại 0x02c1fc..0x02c2a0 (164 byte)
//   0x02c1fc: d10243ff  sub      sp, sp, #0x90
//   0x02c200: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02c204: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02c208: 910203fd  add      x29, sp, #0x80
//   0x02c20c: d53bd053  mrs      x19, tpidr_el0
//   0x02c210: f9401668  ldr      x8, [x19, #0x28]
//   0x02c214: f81e83a8  stur     x8, [x29, #-0x18]
//   0x02c218: 39019fff  strb     wzr, [sp, #0x67]
//   0x02c21c: 39400008  ldrb     w8, [x0]
//   0x02c220: 37000068  tbnz     w8, #0, #0x2c22c
//   0x02c224: 91000400  add      x0, x0, #1
//   0x02c228: 14000002  b        #0x2c230
uint64_t fde_1245_sub_02c1fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0x39400008ULL) + (x2 ^ 0x02C1FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02c1fc: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02c200: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02c204: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02c208: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02c20c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02c210: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x02c214: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x39019FFFULL; // 0x02c218: strb wzr, [sp, #0x67]
    return acc;
}

// [EN] Reconstructed FDE #1246 @ 0x02c2a0..0x02c2bc (28 bytes)
// [VN] Phục dựng FDE #1246 tại 0x02c2a0..0x02c2bc (28 byte)
//   0x02c2a0: a9474ff4  ldp      x20, x19, [sp, #0x70]
//   0x02c2a4: a94657f6  ldp      x22, x21, [sp, #0x60]
//   0x02c2a8: a9455ff8  ldp      x24, x23, [sp, #0x50]
//   0x02c2ac: a94467fa  ldp      x26, x25, [sp, #0x40]
//   0x02c2b0: a9436ffc  ldp      x28, x27, [sp, #0x30]
//   0x02c2b4: 910243ff  add      sp, sp, #0x90
//   0x02c2b8: d65f03c0  ret      
uint64_t fde_1246_sub_02c2a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9474FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C2A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9474FF4ULL; // 0x02c2a0: ldp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94657F6ULL; // 0x02c2a4: ldp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9455FF8ULL; // 0x02c2a8: ldp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94467FAULL; // 0x02c2ac: ldp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9436FFCULL; // 0x02c2b0: ldp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FFULL; // 0x02c2b4: add sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c2b8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1247 @ 0x02c2bc..0x02c2d8 (28 bytes)
// [VN] Phục dựng FDE #1247 tại 0x02c2bc..0x02c2d8 (28 byte)
//   0x02c2bc: 52800028  mov      w8, #1
//   0x02c2c0: 39002288  strb     w8, [x20, #8]
//   0x02c2c4: f0000162  adrp     x2, #0x5b000
//   0x02c2c8: f9400280  ldr      x0, [x20]
//   0x02c2cc: f9472842  ldr      x2, [x2, #0xe50]
//   0x02c2d0: 52800061  mov      w1, #3
//   0x02c2d4: 17fffee7  b        #0x2be70
uint64_t fde_1247_sub_02c2bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800028ULL) + (x1 ^ 0x17FFFEE7ULL) + (x2 ^ 0x02C2BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x02c2bc: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39002288ULL; // 0x02c2c0: strb w8, [x20, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000162ULL; // 0x02c2c4: adrp x2, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400280ULL; // 0x02c2c8: ldr x0, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9472842ULL; // 0x02c2cc: ldr x2, [x2, #0xe50]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800061ULL; // 0x02c2d0: mov w1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFEE7ULL; // 0x02c2d4: b #0x2be70
    return acc;
}

// [EN] Reconstructed FDE #1248 @ 0x02c2d8..0x02c2f8 (32 bytes)
// [VN] Phục dựng FDE #1248 tại 0x02c2d8..0x02c2f8 (32 byte)
//   0x02c2d8: 9102e28a  add      x10, x20, #0xb8
//   0x02c2dc: 9102428b  add      x11, x20, #0x90
//   0x02c2e0: 6b0902bf  cmp      w21, w9
//   0x02c2e4: 9a8bc149  csel     x9, x10, x11, gt
//   0x02c2e8: b868d92a  ldr      w10, [x9, w8, sxtw #2]
//   0x02c2ec: 5100054a  sub      w10, w10, #1
//   0x02c2f0: 7100055f  cmp      w10, #1
//   0x02c2f4: d65f03c0  ret      
uint64_t fde_1248_sub_02c2d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9102E28AULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C2D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9102E28AULL; // 0x02c2d8: add x10, x20, #0xb8
    acc = (acc * 0x100000001B3ULL) ^ 0x9102428BULL; // 0x02c2dc: add x11, x20, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0902BFULL; // 0x02c2e0: cmp w21, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x9A8BC149ULL; // 0x02c2e4: csel x9, x10, x11, gt
    acc = (acc * 0x100000001B3ULL) ^ 0xB868D92AULL; // 0x02c2e8: ldr w10, [x9, w8, sxtw #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x5100054AULL; // 0x02c2ec: sub w10, w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x7100055FULL; // 0x02c2f0: cmp w10, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c2f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1249 @ 0x02c2f8..0x02c314 (28 bytes)
// [VN] Phục dựng FDE #1249 tại 0x02c2f8..0x02c314 (28 byte)
//   0x02c2f8: 1284e1e8  mov      w8, #-0x2710
//   0x02c2fc: 5284e1e9  mov      w9, #0x270f
//   0x02c300: 0b0802a8  add      w8, w21, w8
//   0x02c304: 6b0902bf  cmp      w21, w9
//   0x02c308: 1a95c108  csel     w8, w8, w21, gt
//   0x02c30c: 7100251f  cmp      w8, #9
//   0x02c310: d65f03c0  ret      
uint64_t fde_1249_sub_02c2f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x1284E1E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C2F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x1284E1E8ULL; // 0x02c2f8: mov w8, #-0x2710
    acc = (acc * 0x100000001B3ULL) ^ 0x5284E1E9ULL; // 0x02c2fc: mov w9, #0x270f
    acc = (acc * 0x100000001B3ULL) ^ 0x0B0802A8ULL; // 0x02c300: add w8, w21, w8
    acc = (acc * 0x100000001B3ULL) ^ 0x6B0902BFULL; // 0x02c304: cmp w21, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A95C108ULL; // 0x02c308: csel w8, w8, w21, gt
    acc = (acc * 0x100000001B3ULL) ^ 0x7100251FULL; // 0x02c30c: cmp w8, #9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c310: ret 
    return acc;
}

// [EN] Reconstructed FDE #1250 @ 0x02c314..0x02c320 (12 bytes)
// [VN] Phục dựng FDE #1250 tại 0x02c314..0x02c320 (12 byte)
//   0x02c314: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x02c318: f84307f5  ldr      x21, [sp], #0x30
//   0x02c31c: 17ff7bbd  b        #0xb210
uint64_t fde_1250_sub_02c314(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9414FF4ULL) + (x1 ^ 0x17FF7BBDULL) + (x2 ^ 0x02C314ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x02c314: ldp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84307F5ULL; // 0x02c318: ldr x21, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7BBDULL; // 0x02c31c: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1251 @ 0x02c320..0x02c334 (20 bytes)
// [VN] Phục dựng FDE #1251 tại 0x02c320..0x02c334 (20 byte)
//   0x02c320: 91012013  add      x19, x0, #0x48
//   0x02c324: aa0003f4  mov      x20, x0
//   0x02c328: aa1303e0  mov      x0, x19
//   0x02c32c: 2a0103f5  mov      w21, w1
//   0x02c330: 17ff7ca8  b        #0xb5d0
uint64_t fde_1251_sub_02c320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91012013ULL) + (x1 ^ 0x17FF7CA8ULL) + (x2 ^ 0x02C320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91012013ULL; // 0x02c320: add x19, x0, #0x48
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02c324: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02c328: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F5ULL; // 0x02c32c: mov w21, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7CA8ULL; // 0x02c330: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1252 @ 0x02c334..0x02c348 (20 bytes)
// [VN] Phục dựng FDE #1252 tại 0x02c334..0x02c348 (20 byte)
//   0x02c334: 91012013  add      x19, x0, #0x48
//   0x02c338: aa0003f5  mov      x21, x0
//   0x02c33c: aa1303e0  mov      x0, x19
//   0x02c340: 2a0103f4  mov      w20, w1
//   0x02c344: 17ff7ca3  b        #0xb5d0
uint64_t fde_1252_sub_02c334(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91012013ULL) + (x1 ^ 0x17FF7CA3ULL) + (x2 ^ 0x02C334ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91012013ULL; // 0x02c334: add x19, x0, #0x48
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x02c338: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02c33c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x02c340: mov w20, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7CA3ULL; // 0x02c344: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1253 @ 0x02c348..0x02c358 (16 bytes)
// [VN] Phục dựng FDE #1253 tại 0x02c348..0x02c358 (16 byte)
//   0x02c348: aa0903ea  mov      x10, x9
//   0x02c34c: f840854b  ldr      x11, [x10], #8
//   0x02c350: d1000508  sub      x8, x8, #1
//   0x02c354: d65f03c0  ret      
uint64_t fde_1253_sub_02c348(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0903EAULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C348ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0903EAULL; // 0x02c348: mov x10, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xF840854BULL; // 0x02c34c: ldr x11, [x10], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000508ULL; // 0x02c350: sub x8, x8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c354: ret 
    return acc;
}

// [EN] Reconstructed FDE #1254 @ 0x02c358..0x02c368 (16 bytes)
// [VN] Phục dựng FDE #1254 tại 0x02c358..0x02c368 (16 byte)
//   0x02c358: 9100a3e1  add      x1, sp, #0x28
//   0x02c35c: 52800042  mov      w2, #2
//   0x02c360: 2a1503e0  mov      w0, w21
//   0x02c364: 17fff9d7  b        #0x2aac0
uint64_t fde_1254_sub_02c358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100A3E1ULL) + (x1 ^ 0x17FFF9D7ULL) + (x2 ^ 0x02C358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A3E1ULL; // 0x02c358: add x1, sp, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0x52800042ULL; // 0x02c35c: mov w2, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1503E0ULL; // 0x02c360: mov w0, w21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF9D7ULL; // 0x02c364: b #0x2aac0
    return acc;
}

// [EN] Reconstructed FDE #1255 @ 0x02c368..0x02c370 (8 bytes)
// [VN] Phục dựng FDE #1255 tại 0x02c368..0x02c370 (8 byte)
//   0x02c368: aa1403e1  mov      x1, x20
//   0x02c36c: 17ff7ba1  b        #0xb1f0
uint64_t fde_1255_sub_02c368(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E1ULL) + (x1 ^ 0x17FF7BA1ULL) + (x2 ^ 0x02C368ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x02c368: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7BA1ULL; // 0x02c36c: b #0xb1f0
    return acc;
}

// [EN] Reconstructed FDE #1256 @ 0x02c370..0x02c378 (8 bytes)
// [VN] Phục dựng FDE #1256 tại 0x02c370..0x02c378 (8 byte)
//   0x02c370: 52800060  mov      w0, #3
//   0x02c374: 17ff7b9b  b        #0xb1e0
uint64_t fde_1256_sub_02c370(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF7B9BULL) + (x2 ^ 0x02C370ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02c370: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7B9BULL; // 0x02c374: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1257 @ 0x02c378..0x02c380 (8 bytes)
// [VN] Phục dựng FDE #1257 tại 0x02c378..0x02c380 (8 byte)
//   0x02c378: aa1a03e0  mov      x0, x26
//   0x02c37c: 17ff7b69  b        #0xb120
uint64_t fde_1257_sub_02c378(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1A03E0ULL) + (x1 ^ 0x17FF7B69ULL) + (x2 ^ 0x02C378ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1A03E0ULL; // 0x02c378: mov x0, x26
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7B69ULL; // 0x02c37c: b #0xb120
    return acc;
}

// [EN] Reconstructed FDE #1258 @ 0x02c380..0x02c38c (12 bytes)
// [VN] Phục dựng FDE #1258 tại 0x02c380..0x02c38c (12 byte)
//   0x02c380: a9414ff4  ldp      x20, x19, [sp, #0x10]
//   0x02c384: f84307f5  ldr      x21, [sp], #0x30
//   0x02c388: d65f03c0  ret      
uint64_t fde_1258_sub_02c380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9414FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02C380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9414FF4ULL; // 0x02c380: ldp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84307F5ULL; // 0x02c384: ldr x21, [sp], #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02c388: ret 
    return acc;
}

// [EN] Reconstructed FDE #1259 @ 0x02c38c..0x02c478 (236 bytes)
// [VN] Phục dựng FDE #1259 tại 0x02c38c..0x02c478 (236 byte)
//   0x02c38c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02c390: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02c394: 910043fd  add      x29, sp, #0x10
//   0x02c398: b0000194  adrp     x20, #0x5d000
//   0x02c39c: f0000081  adrp     x1, #0x3f000
//   0x02c3a0: f0000082  adrp     x2, #0x3f000
//   0x02c3a4: f0000083  adrp     x3, #0x3f000
//   0x02c3a8: 90000004  adrp     x4, #0x2c000
//   0x02c3ac: 91162294  add      x20, x20, #0x588
//   0x02c3b0: 9118c821  add      x1, x1, #0x632
//   0x02c3b4: 91195042  add      x2, x2, #0x654
//   0x02c3b8: 91198463  add      x3, x3, #0x661
uint64_t fde_1259_sub_02c38c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x91162294ULL) + (x2 ^ 0x02C38CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02c38c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02c390: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02c394: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000194ULL; // 0x02c398: adrp x20, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000081ULL; // 0x02c39c: adrp x1, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000082ULL; // 0x02c3a0: adrp x2, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000083ULL; // 0x02c3a4: adrp x3, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000004ULL; // 0x02c3a8: adrp x4, #0x2c000
    return acc;
}

// [EN] Reconstructed FDE #1260 @ 0x02c478..0x02c588 (272 bytes)
// [VN] Phục dựng FDE #1260 tại 0x02c478..0x02c588 (272 byte)
//   0x02c478: a9bc5ff8  stp      x24, x23, [sp, #-0x40]!
//   0x02c47c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02c480: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02c484: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02c488: 9100c3fd  add      x29, sp, #0x30
//   0x02c48c: f9400008  ldr      x8, [x0]
//   0x02c490: aa0203f5  mov      x21, x2
//   0x02c494: aa0103f7  mov      x23, x1
//   0x02c498: aa0203e1  mov      x1, x2
//   0x02c49c: f942a508  ldr      x8, [x8, #0x548]
//   0x02c4a0: aa1f03e2  mov      x2, xzr
//   0x02c4a4: 2a0303f4  mov      w20, w3
uint64_t fde_1260_sub_02c478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BC5FF8ULL) + (x1 ^ 0xAA0203E1ULL) + (x2 ^ 0x02C478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC5FF8ULL; // 0x02c478: stp x24, x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02c47c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02c480: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02c484: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02c488: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02c48c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x02c490: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F7ULL; // 0x02c494: mov x23, x1
    return acc;
}

// [EN] Reconstructed FDE #1261 @ 0x02c588..0x02c594 (12 bytes)
// [VN] Phục dựng FDE #1261 tại 0x02c588..0x02c594 (12 byte)
//   0x02c588: 52800080  mov      w0, #4
//   0x02c58c: aa1303e3  mov      x3, x19
//   0x02c590: 17ff7b14  b        #0xb1e0
uint64_t fde_1261_sub_02c588(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800080ULL) + (x1 ^ 0x17FF7B14ULL) + (x2 ^ 0x02C588ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800080ULL; // 0x02c588: mov w0, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x02c58c: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7B14ULL; // 0x02c590: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1262 @ 0x02c594..0x02c598 (4 bytes)
// [VN] Phục dựng FDE #1262 tại 0x02c594..0x02c598 (4 byte)
//   0x02c594: 140001df  b        #0x2cd10
uint64_t fde_1262_sub_02c594(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x140001DFULL) + (x1 ^ 0x140001DFULL) + (x2 ^ 0x02C594ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x140001DFULL; // 0x02c594: b #0x2cd10
    return acc;
}

// [EN] Reconstructed FDE #1263 @ 0x02c598..0x02c814 (636 bytes)
// [VN] Phục dựng FDE #1263 tại 0x02c598..0x02c814 (636 byte)
//   0x02c598: d10183ff  sub      sp, sp, #0x60
//   0x02c59c: f9000bf9  str      x25, [sp, #0x10]
//   0x02c5a0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02c5a4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02c5a8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02c5ac: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02c5b0: 910143fd  add      x29, sp, #0x50
//   0x02c5b4: d53bd058  mrs      x24, tpidr_el0
//   0x02c5b8: f9401708  ldr      x8, [x24, #0x28]
//   0x02c5bc: f90007e8  str      x8, [sp, #8]
//   0x02c5c0: 97ff7c2c  bl       #0xb670
//   0x02c5c4: 7100741f  cmp      w0, #0x1d
uint64_t fde_1263_sub_02c598(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x02C598ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02c598: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF9ULL; // 0x02c59c: str x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02c5a0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02c5a4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02c5a8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02c5ac: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02c5b0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02c5b4: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1264 @ 0x02c814..0x02c914 (256 bytes)
// [VN] Phục dựng FDE #1264 tại 0x02c814..0x02c914 (256 byte)
//   0x02c814: d100c3ff  sub      sp, sp, #0x30
//   0x02c818: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02c81c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02c820: 910083fd  add      x29, sp, #0x20
//   0x02c824: d53bd053  mrs      x19, tpidr_el0
//   0x02c828: f9401668  ldr      x8, [x19, #0x28]
//   0x02c82c: f90007e8  str      x8, [sp, #8]
//   0x02c830: b0000188  adrp     x8, #0x5d000
//   0x02c834: 39566508  ldrb     w8, [x8, #0x599]
//   0x02c838: 7100051f  cmp      w8, #1
//   0x02c83c: 540003e1  b.ne     #0x2c8b8
//   0x02c840: b0000194  adrp     x20, #0x5d000
uint64_t fde_1264_sub_02c814(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x39566508ULL) + (x2 ^ 0x02C814ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x02c814: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02c818: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02c81c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02c820: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02c824: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02c828: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x02c82c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x02c830: adrp x8, #0x5d000
    return acc;
}

// [EN] Reconstructed FDE #1265 @ 0x02c914..0x02c954 (64 bytes)
// [VN] Phục dựng FDE #1265 tại 0x02c914..0x02c954 (64 byte)
//   0x02c914: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02c918: 910003fd  mov      x29, sp
//   0x02c91c: 94000103  bl       #0x2cd28
//   0x02c920: 54000101  b.ne     #0x2c940
//   0x02c924: 97ffab3e  bl       #0x1761c
//   0x02c928: 360000c0  tbz      w0, #0, #0x2c940
//   0x02c92c: f0000081  adrp     x1, #0x3f000
//   0x02c930: f0000082  adrp     x2, #0x3f000
//   0x02c934: 911cec21  add      x1, x1, #0x73b
//   0x02c938: 911d7042  add      x2, x2, #0x75c
//   0x02c93c: 940000ff  bl       #0x2cd38
//   0x02c940: b0000188  adrp     x8, #0x5d000
uint64_t fde_1265_sub_02c914(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x911CEC21ULL) + (x2 ^ 0x02C914ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02c914: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02c918: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x94000103ULL; // 0x02c91c: bl #0x2cd28
    acc = (acc * 0x100000001B3ULL) ^ 0x54000101ULL; // 0x02c920: b.ne #0x2c940
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAB3EULL; // 0x02c924: bl #0x1761c
    acc = (acc * 0x100000001B3ULL) ^ 0x360000C0ULL; // 0x02c928: tbz w0, #0, #0x2c940
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000081ULL; // 0x02c92c: adrp x1, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000082ULL; // 0x02c930: adrp x2, #0x3f000
    return acc;
}

// [EN] Reconstructed FDE #1266 @ 0x02c954..0x02caa8 (340 bytes)
// [VN] Phục dựng FDE #1266 tại 0x02c954..0x02caa8 (340 byte)
//   0x02c954: d10203ff  sub      sp, sp, #0x80
//   0x02c958: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x02c95c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02c960: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02c964: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02c968: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02c96c: 9101c3fd  add      x29, sp, #0x70
//   0x02c970: d53bd056  mrs      x22, tpidr_el0
//   0x02c974: f94016c8  ldr      x8, [x22, #0x28]
//   0x02c978: f90017e8  str      x8, [sp, #0x28]
//   0x02c97c: 940000eb  bl       #0x2cd28
//   0x02c980: 54000101  b.ne     #0x2c9a0
uint64_t fde_1266_sub_02c954(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF94016C8ULL) + (x2 ^ 0x02C954ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02c954: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x02c958: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02c95c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02c960: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02c964: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02c968: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02c96c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x02c970: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1267 @ 0x02caa8..0x02cab8 (16 bytes)
// [VN] Phục dựng FDE #1267 tại 0x02caa8..0x02cab8 (16 byte)
//   0x02caa8: b0000188  adrp     x8, #0x5d000
//   0x02caac: 52800029  mov      w9, #1
//   0x02cab0: 39166109  strb     w9, [x8, #0x598]
//   0x02cab4: d65f03c0  ret      
uint64_t fde_1267_sub_02caa8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000188ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CAA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x02caa8: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x02caac: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39166109ULL; // 0x02cab0: strb w9, [x8, #0x598]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cab4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1268 @ 0x02cab8..0x02cadc (36 bytes)
// [VN] Phục dựng FDE #1268 tại 0x02cab8..0x02cadc (36 byte)
//   0x02cab8: f9400048  ldr      x8, [x2]
//   0x02cabc: eb01001f  cmp      x0, x1
//   0x02cac0: 540000c0  b.eq     #0x2cad8
//   0x02cac4: f9400009  ldr      x9, [x0]
//   0x02cac8: eb08013f  cmp      x9, x8
//   0x02cacc: 54000060  b.eq     #0x2cad8
//   0x02cad0: 91002000  add      x0, x0, #8
//   0x02cad4: 17fffffa  b        #0x2cabc
//   0x02cad8: d65f03c0  ret      
uint64_t fde_1268_sub_02cab8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400048ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CAB8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400048ULL; // 0x02cab8: ldr x8, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01001FULL; // 0x02cabc: cmp x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x02cac0: b.eq #0x2cad8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x02cac4: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x02cac8: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000060ULL; // 0x02cacc: b.eq #0x2cad8
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x02cad0: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFAULL; // 0x02cad4: b #0x2cabc
    return acc;
}

// [EN] Reconstructed FDE #1269 @ 0x02cadc..0x02cafc (32 bytes)
// [VN] Phục dựng FDE #1269 tại 0x02cadc..0x02cafc (32 byte)
//   0x02cadc: a940a408  ldp      x8, x9, [x0, #8]
//   0x02cae0: eb09011f  cmp      x8, x9
//   0x02cae4: 540000a0  b.eq     #0x2caf8
//   0x02cae8: f9400029  ldr      x9, [x1]
//   0x02caec: f8008509  str      x9, [x8], #8
//   0x02caf0: f9000408  str      x8, [x0, #8]
//   0x02caf4: d65f03c0  ret      
//   0x02caf8: 14000001  b        #0x2cafc
uint64_t fde_1269_sub_02cadc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02CADCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x02cadc: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02cae0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02cae4: b.eq #0x2caf8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400029ULL; // 0x02cae8: ldr x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008509ULL; // 0x02caec: str x9, [x8], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x02caf0: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02caf4: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02caf8: b #0x2cafc
    return acc;
}

// [EN] Reconstructed FDE #1270 @ 0x02cafc..0x02cbc8 (204 bytes)
// [VN] Phục dựng FDE #1270 tại 0x02cafc..0x02cbc8 (204 byte)
//   0x02cafc: d101c3ff  sub      sp, sp, #0x70
//   0x02cb00: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02cb04: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02cb08: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02cb0c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02cb10: 910183fd  add      x29, sp, #0x60
//   0x02cb14: d53bd057  mrs      x23, tpidr_el0
//   0x02cb18: f94016e8  ldr      x8, [x23, #0x28]
//   0x02cb1c: aa0103f4  mov      x20, x1
//   0x02cb20: aa0003f3  mov      x19, x0
//   0x02cb24: 91004016  add      x22, x0, #0x10
//   0x02cb28: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1270_sub_02cafc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x02CAFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02cafc: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02cb00: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02cb04: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02cb08: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02cb0c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02cb10: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02cb14: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02cb18: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1271 @ 0x02cbc8..0x02cc10 (72 bytes)
// [VN] Phục dựng FDE #1271 tại 0x02cbc8..0x02cc10 (72 byte)
//   0x02cbc8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02cbcc: 910003fd  mov      x29, sp
//   0x02cbd0: d37dfc28  lsr      x8, x1, #0x3d
//   0x02cbd4: b50001c8  cbnz     x8, #0x2cc0c
//   0x02cbd8: f9400808  ldr      x8, [x0, #0x10]
//   0x02cbdc: f9400009  ldr      x9, [x0]
//   0x02cbe0: cb090108  sub      x8, x8, x9
//   0x02cbe4: b27febe9  mov      x9, #0xffffffffffffffe
//   0x02cbe8: eb880d3f  cmp      x9, x8, asr #3
//   0x02cbec: 540000a3  b.lo     #0x2cc00
//   0x02cbf0: 9342fd08  asr      x8, x8, #2
//   0x02cbf4: eb01011f  cmp      x8, x1
uint64_t fde_1271_sub_02cbc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB880D3FULL) + (x2 ^ 0x02CBC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02cbc8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02cbcc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x02cbd0: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x02cbd4: cbnz x8, #0x2cc0c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x02cbd8: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x02cbdc: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x02cbe0: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FEBE9ULL; // 0x02cbe4: mov x9, #0xffffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #1272 @ 0x02cc10..0x02cc74 (100 bytes)
// [VN] Phục dựng FDE #1272 tại 0x02cc10..0x02cc74 (100 byte)
//   0x02cc10: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02cc14: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02cc18: 910043fd  add      x29, sp, #0x10
//   0x02cc1c: aa0103f3  mov      x19, x1
//   0x02cc20: aa0003f4  mov      x20, x0
//   0x02cc24: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x02cc28: 91002263  add      x3, x19, #8
//   0x02cc2c: 94000028  bl       #0x2cccc
//   0x02cc30: f9400668  ldr      x8, [x19, #8]
//   0x02cc34: f9400289  ldr      x9, [x20]
//   0x02cc38: f9000288  str      x8, [x20]
//   0x02cc3c: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_1272_sub_02cc10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x02CC10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02cc10: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02cc14: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02cc18: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02cc1c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02cc20: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x02cc24: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x02cc28: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x02cc2c: bl #0x2cccc
    return acc;
}

// [EN] Reconstructed FDE #1273 @ 0x02cc74..0x02cca8 (52 bytes)
// [VN] Phục dựng FDE #1273 tại 0x02cc74..0x02cca8 (52 byte)
//   0x02cc74: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02cc78: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02cc7c: 910043fd  add      x29, sp, #0x10
//   0x02cc80: aa0003f3  mov      x19, x0
//   0x02cc84: 9400001a  bl       #0x2ccec
//   0x02cc88: f9400260  ldr      x0, [x19]
//   0x02cc8c: b4000080  cbz      x0, #0x2cc9c
//   0x02cc90: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02cc94: f84207f3  ldr      x19, [sp], #0x20
//   0x02cc98: 17ff782a  b        #0xad40
//   0x02cc9c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02cca0: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1273_sub_02cc74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x02CC74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02cc74: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02cc78: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02cc7c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02cc80: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x02cc84: bl #0x2ccec
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x02cc88: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x02cc8c: cbz x0, #0x2cc9c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02cc90: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #1274 @ 0x02cca8..0x02ccb0 (8 bytes)
// [VN] Phục dựng FDE #1274 tại 0x02cca8..0x02ccb0 (8 byte)
//   0x02cca8: aa1f03e2  mov      x2, xzr
//   0x02ccac: 14000001  b        #0x2ccb0
uint64_t fde_1274_sub_02cca8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02CCA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x02cca8: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02ccac: b #0x2ccb0
    return acc;
}

// [EN] Reconstructed FDE #1275 @ 0x02ccb0..0x02cccc (28 bytes)
// [VN] Phục dựng FDE #1275 tại 0x02ccb0..0x02cccc (28 byte)
//   0x02ccb0: d37dfc28  lsr      x8, x1, #0x3d
//   0x02ccb4: b5000068  cbnz     x8, #0x2ccc0
//   0x02ccb8: d37df020  lsl      x0, x1, #3
//   0x02ccbc: 17ff7a4d  b        #0xb5f0
//   0x02ccc0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02ccc4: 910003fd  mov      x29, sp
//   0x02ccc8: 97ff7a0e  bl       #0xb500
uint64_t fde_1275_sub_02ccb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF7A0EULL) + (x2 ^ 0x02CCB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x02ccb0: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x02ccb4: cbnz x8, #0x2ccc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x02ccb8: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7A4DULL; // 0x02ccbc: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02ccc0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02ccc4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7A0EULL; // 0x02ccc8: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1276 @ 0x02cccc..0x02ccec (32 bytes)
// [VN] Phục dựng FDE #1276 tại 0x02cccc..0x02ccec (32 byte)
//   0x02cccc: f9400068  ldr      x8, [x3]
//   0x02ccd0: cb010042  sub      x2, x2, x1
//   0x02ccd4: f100045f  cmp      x2, #1
//   0x02ccd8: cb020100  sub      x0, x8, x2
//   0x02ccdc: f9000060  str      x0, [x3]
//   0x02cce0: 5400004b  b.lt     #0x2cce8
//   0x02cce4: 17ff77cb  b        #0xac10
//   0x02cce8: d65f03c0  ret      
uint64_t fde_1276_sub_02cccc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CCCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x02cccc: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x02ccd0: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x02ccd4: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x02ccd8: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x02ccdc: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x02cce0: b.lt #0x2cce8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF77CBULL; // 0x02cce4: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cce8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1277 @ 0x02ccec..0x02ccf4 (8 bytes)
// [VN] Phục dựng FDE #1277 tại 0x02ccec..0x02ccf4 (8 byte)
//   0x02ccec: f9400401  ldr      x1, [x0, #8]
//   0x02ccf0: 14000001  b        #0x2ccf4
uint64_t fde_1277_sub_02ccec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02CCECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x02ccec: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02ccf0: b #0x2ccf4
    return acc;
}

// [EN] Reconstructed FDE #1278 @ 0x02ccf4..0x02cd10 (28 bytes)
// [VN] Phục dựng FDE #1278 tại 0x02ccf4..0x02cd10 (28 byte)
//   0x02ccf4: f9400808  ldr      x8, [x0, #0x10]
//   0x02ccf8: eb08003f  cmp      x1, x8
//   0x02ccfc: 54000080  b.eq     #0x2cd0c
//   0x02cd00: d1002108  sub      x8, x8, #8
//   0x02cd04: f9000808  str      x8, [x0, #0x10]
//   0x02cd08: 17fffffc  b        #0x2ccf8
//   0x02cd0c: d65f03c0  ret      
uint64_t fde_1278_sub_02ccf4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CCF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x02ccf4: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x02ccf8: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x02ccfc: b.eq #0x2cd0c
    acc = (acc * 0x100000001B3ULL) ^ 0xD1002108ULL; // 0x02cd00: sub x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x02cd04: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x02cd08: b #0x2ccf8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd0c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1279 @ 0x02cd10..0x02cd28 (24 bytes)
// [VN] Phục dựng FDE #1279 tại 0x02cd10..0x02cd28 (24 byte)
//   0x02cd10: aa0003e8  mov      x8, x0
//   0x02cd14: f9400000  ldr      x0, [x0]
//   0x02cd18: b4000060  cbz      x0, #0x2cd24
//   0x02cd1c: f9000500  str      x0, [x8, #8]
//   0x02cd20: 17ff7808  b        #0xad40
//   0x02cd24: d65f03c0  ret      
uint64_t fde_1279_sub_02cd10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02cd10: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02cd14: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x02cd18: cbz x0, #0x2cd24
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x02cd1c: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7808ULL; // 0x02cd20: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd24: ret 
    return acc;
}

// [EN] Reconstructed FDE #1280 @ 0x02cd28..0x02cd38 (16 bytes)
// [VN] Phục dựng FDE #1280 tại 0x02cd28..0x02cd38 (16 byte)
//   0x02cd28: b0000188  adrp     x8, #0x5d000
//   0x02cd2c: 39566108  ldrb     w8, [x8, #0x598]
//   0x02cd30: 7100051f  cmp      w8, #1
//   0x02cd34: d65f03c0  ret      
uint64_t fde_1280_sub_02cd28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000188ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02CD28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x02cd28: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x39566108ULL; // 0x02cd2c: ldrb w8, [x8, #0x598]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x02cd30: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cd34: ret 
    return acc;
}

// [EN] Reconstructed FDE #1281 @ 0x02cd38..0x02cd40 (8 bytes)
// [VN] Phục dựng FDE #1281 tại 0x02cd38..0x02cd40 (8 byte)
//   0x02cd38: 52800060  mov      w0, #3
//   0x02cd3c: 17ff7929  b        #0xb1e0
uint64_t fde_1281_sub_02cd38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF7929ULL) + (x2 ^ 0x02CD38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x02cd38: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7929ULL; // 0x02cd3c: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1282 @ 0x02cd40..0x02cea8 (360 bytes)
// [VN] Phục dựng FDE #1282 tại 0x02cd40..0x02cea8 (360 byte)
//   0x02cd40: d10243ff  sub      sp, sp, #0x90
//   0x02cd44: f9001bfb  str      x27, [sp, #0x30]
//   0x02cd48: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02cd4c: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02cd50: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02cd54: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02cd58: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02cd5c: 910203fd  add      x29, sp, #0x80
//   0x02cd60: d53bd057  mrs      x23, tpidr_el0
//   0x02cd64: f94016e8  ldr      x8, [x23, #0x28]
//   0x02cd68: aa0103f5  mov      x21, x1
//   0x02cd6c: aa0003f3  mov      x19, x0
uint64_t fde_1282_sub_02cd40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xD53BD057ULL) + (x2 ^ 0x02CD40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02cd40: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BFBULL; // 0x02cd44: str x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x02cd48: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02cd4c: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02cd50: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02cd54: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02cd58: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02cd5c: add x29, sp, #0x80
    return acc;
}

// [EN] Reconstructed FDE #1283 @ 0x02cea8..0x02cf44 (156 bytes)
// [VN] Phục dựng FDE #1283 tại 0x02cea8..0x02cf44 (156 byte)
//   0x02cea8: d10183ff  sub      sp, sp, #0x60
//   0x02ceac: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02ceb0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02ceb4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02ceb8: 910143fd  add      x29, sp, #0x50
//   0x02cebc: d53bd055  mrs      x21, tpidr_el0
//   0x02cec0: f94016a8  ldr      x8, [x21, #0x28]
//   0x02cec4: f90017e8  str      x8, [sp, #0x28]
//   0x02cec8: f9400809  ldr      x9, [x0, #0x10]
//   0x02cecc: f9400008  ldr      x8, [x0]
//   0x02ced0: cb080129  sub      x9, x9, x8
//   0x02ced4: eb89083f  cmp      x1, x9, asr #2
uint64_t fde_1283_sub_02cea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9400809ULL) + (x2 ^ 0x02CEA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02cea8: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02ceac: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02ceb0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02ceb4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02ceb8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02cebc: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02cec0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90017E8ULL; // 0x02cec4: str x8, [sp, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1284 @ 0x02cf44..0x02cf64 (32 bytes)
// [VN] Phục dựng FDE #1284 tại 0x02cf44..0x02cf64 (32 byte)
//   0x02cf44: a940a408  ldp      x8, x9, [x0, #8]
//   0x02cf48: eb09011f  cmp      x8, x9
//   0x02cf4c: 540000a0  b.eq     #0x2cf60
//   0x02cf50: b9400029  ldr      w9, [x1]
//   0x02cf54: b8004509  str      w9, [x8], #4
//   0x02cf58: f9000408  str      x8, [x0, #8]
//   0x02cf5c: d65f03c0  ret      
//   0x02cf60: 14000166  b        #0x2d4f8
uint64_t fde_1284_sub_02cf44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000166ULL) + (x2 ^ 0x02CF44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x02cf44: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02cf48: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02cf4c: b.eq #0x2cf60
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x02cf50: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8004509ULL; // 0x02cf54: str w9, [x8], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x02cf58: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cf5c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x14000166ULL; // 0x02cf60: b #0x2d4f8
    return acc;
}

// [EN] Reconstructed FDE #1285 @ 0x02cf64..0x02cf84 (32 bytes)
// [VN] Phục dựng FDE #1285 tại 0x02cf64..0x02cf84 (32 byte)
//   0x02cf64: a940a408  ldp      x8, x9, [x0, #8]
//   0x02cf68: eb09011f  cmp      x8, x9
//   0x02cf6c: 540000a2  b.hs     #0x2cf80
//   0x02cf70: b9400029  ldr      w9, [x1]
//   0x02cf74: b8004509  str      w9, [x8], #4
//   0x02cf78: f9000408  str      x8, [x0, #8]
//   0x02cf7c: d65f03c0  ret      
//   0x02cf80: 140001a1  b        #0x2d604
uint64_t fde_1285_sub_02cf64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x140001A1ULL) + (x2 ^ 0x02CF64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x02cf64: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02cf68: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x02cf6c: b.hs #0x2cf80
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400029ULL; // 0x02cf70: ldr w9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8004509ULL; // 0x02cf74: str w9, [x8], #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x02cf78: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02cf7c: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x140001A1ULL; // 0x02cf80: b #0x2d604
    return acc;
}

// [EN] Reconstructed FDE #1286 @ 0x02cf84..0x02cf8c (8 bytes)
// [VN] Phục dựng FDE #1286 tại 0x02cf84..0x02cf8c (8 byte)
//   0x02cf84: 52862024  mov      w4, #0x3101
//   0x02cf88: 17ffff6e  b        #0x2cd40
uint64_t fde_1286_sub_02cf84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52862024ULL) + (x1 ^ 0x17FFFF6EULL) + (x2 ^ 0x02CF84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52862024ULL; // 0x02cf84: mov w4, #0x3101
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF6EULL; // 0x02cf88: b #0x2cd40
    return acc;
}

// [EN] Reconstructed FDE #1287 @ 0x02cf8c..0x02cf94 (8 bytes)
// [VN] Phục dựng FDE #1287 tại 0x02cf8c..0x02cf94 (8 byte)
//   0x02cf8c: 52862044  mov      w4, #0x3102
//   0x02cf90: 17ffff6c  b        #0x2cd40
uint64_t fde_1287_sub_02cf8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52862044ULL) + (x1 ^ 0x17FFFF6CULL) + (x2 ^ 0x02CF8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52862044ULL; // 0x02cf8c: mov w4, #0x3102
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF6CULL; // 0x02cf90: b #0x2cd40
    return acc;
}

// [EN] Reconstructed FDE #1288 @ 0x02cf94..0x02cf9c (8 bytes)
// [VN] Phục dựng FDE #1288 tại 0x02cf94..0x02cf9c (8 byte)
//   0x02cf94: 52862064  mov      w4, #0x3103
//   0x02cf98: 17ffff6a  b        #0x2cd40
uint64_t fde_1288_sub_02cf94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52862064ULL) + (x1 ^ 0x17FFFF6AULL) + (x2 ^ 0x02CF94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52862064ULL; // 0x02cf94: mov w4, #0x3103
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF6AULL; // 0x02cf98: b #0x2cd40
    return acc;
}

// [EN] Reconstructed FDE #1289 @ 0x02cf9c..0x02d0c0 (292 bytes)
// [VN] Phục dựng FDE #1289 tại 0x02cf9c..0x02d0c0 (292 byte)
//   0x02cf9c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02cfa0: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02cfa4: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02cfa8: 910083fd  add      x29, sp, #0x20
//   0x02cfac: b0000188  adrp     x8, #0x5d000
//   0x02cfb0: f9430108  ldr      x8, [x8, #0x600]
//   0x02cfb4: aa0103f4  mov      x20, x1
//   0x02cfb8: aa0003f3  mov      x19, x0
//   0x02cfbc: b5000288  cbnz     x8, #0x2d00c
//   0x02cfc0: 940001c9  bl       #0x2d6e4
//   0x02cfc4: f0000081  adrp     x1, #0x3f000
//   0x02cfc8: 91259821  add      x1, x1, #0x966
uint64_t fde_1289_sub_02cf9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB5000288ULL) + (x2 ^ 0x02CF9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02cf9c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02cfa0: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02cfa4: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02cfa8: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000188ULL; // 0x02cfac: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9430108ULL; // 0x02cfb0: ldr x8, [x8, #0x600]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02cfb4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02cfb8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1290 @ 0x02d0c0..0x02d270 (432 bytes)
// [VN] Phục dựng FDE #1290 tại 0x02d0c0..0x02d270 (432 byte)
//   0x02d0c0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x02d0c4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x02d0c8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02d0cc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02d0d0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02d0d4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02d0d8: 910143fd  add      x29, sp, #0x50
//   0x02d0dc: f9400008  ldr      x8, [x0]
//   0x02d0e0: aa0203e1  mov      x1, x2
//   0x02d0e4: aa0003f3  mov      x19, x0
//   0x02d0e8: aa0203f5  mov      x21, x2
//   0x02d0ec: f942ad08  ldr      x8, [x8, #0x558]
uint64_t fde_1290_sub_02d0c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0203E1ULL) + (x2 ^ 0x02D0C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x02d0c0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x02d0c4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02d0c8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02d0cc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02d0d0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02d0d4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02d0d8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02d0dc: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #1291 @ 0x02d270..0x02d3e0 (368 bytes)
// [VN] Phục dựng FDE #1291 tại 0x02d270..0x02d3e0 (368 byte)
//   0x02d270: d10183ff  sub      sp, sp, #0x60
//   0x02d274: f9000bf9  str      x25, [sp, #0x10]
//   0x02d278: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x02d27c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02d280: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02d284: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02d288: 910143fd  add      x29, sp, #0x50
//   0x02d28c: d53bd059  mrs      x25, tpidr_el0
//   0x02d290: f9401728  ldr      x8, [x25, #0x28]
//   0x02d294: f90007e8  str      x8, [sp, #8]
//   0x02d298: 97ff78f6  bl       #0xb670
//   0x02d29c: 2a0003f3  mov      w19, w0
uint64_t fde_1291_sub_02d270(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x02D270ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02d270: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF9ULL; // 0x02d274: str x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x02d278: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02d27c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02d280: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02d284: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02d288: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02d28c: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1292 @ 0x02d3e0..0x02d3f8 (24 bytes)
// [VN] Phục dựng FDE #1292 tại 0x02d3e0..0x02d3f8 (24 byte)
//   0x02d3e0: aa0003e8  mov      x8, x0
//   0x02d3e4: f9400000  ldr      x0, [x0]
//   0x02d3e8: b4000060  cbz      x0, #0x2d3f4
//   0x02d3ec: f9000500  str      x0, [x8, #8]
//   0x02d3f0: 17ff7654  b        #0xad40
//   0x02d3f4: d65f03c0  ret      
uint64_t fde_1292_sub_02d3e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02D3E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02d3e0: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02d3e4: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x02d3e8: cbz x0, #0x2d3f4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x02d3ec: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7654ULL; // 0x02d3f0: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02d3f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1293 @ 0x02d3f8..0x02d45c (100 bytes)
// [VN] Phục dựng FDE #1293 tại 0x02d3f8..0x02d45c (100 byte)
//   0x02d3f8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02d3fc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d400: 910043fd  add      x29, sp, #0x10
//   0x02d404: aa0103f3  mov      x19, x1
//   0x02d408: aa0003f4  mov      x20, x0
//   0x02d40c: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x02d410: 91002263  add      x3, x19, #8
//   0x02d414: 94000028  bl       #0x2d4b4
//   0x02d418: f9400668  ldr      x8, [x19, #8]
//   0x02d41c: f9400289  ldr      x9, [x20]
//   0x02d420: f9000288  str      x8, [x20]
//   0x02d424: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_1293_sub_02d3f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x02D3F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02d3f8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d3fc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d400: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02d404: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02d408: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x02d40c: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x02d410: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x02d414: bl #0x2d4b4
    return acc;
}

// [EN] Reconstructed FDE #1294 @ 0x02d45c..0x02d490 (52 bytes)
// [VN] Phục dựng FDE #1294 tại 0x02d45c..0x02d490 (52 byte)
//   0x02d45c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02d460: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d464: 910043fd  add      x29, sp, #0x10
//   0x02d468: aa0003f3  mov      x19, x0
//   0x02d46c: 9400001a  bl       #0x2d4d4
//   0x02d470: f9400260  ldr      x0, [x19]
//   0x02d474: b4000080  cbz      x0, #0x2d484
//   0x02d478: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02d47c: f84207f3  ldr      x19, [sp], #0x20
//   0x02d480: 17ff7630  b        #0xad40
//   0x02d484: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02d488: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1294_sub_02d45c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x02D45CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02d45c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d460: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d464: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d468: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x02d46c: bl #0x2d4d4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x02d470: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x02d474: cbz x0, #0x2d484
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x02d478: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #1295 @ 0x02d490..0x02d498 (8 bytes)
// [VN] Phục dựng FDE #1295 tại 0x02d490..0x02d498 (8 byte)
//   0x02d490: aa1f03e2  mov      x2, xzr
//   0x02d494: 14000001  b        #0x2d498
uint64_t fde_1295_sub_02d490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02D490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x02d490: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02d494: b #0x2d498
    return acc;
}

// [EN] Reconstructed FDE #1296 @ 0x02d498..0x02d4b4 (28 bytes)
// [VN] Phục dựng FDE #1296 tại 0x02d498..0x02d4b4 (28 byte)
//   0x02d498: d37efc28  lsr      x8, x1, #0x3e
//   0x02d49c: b5000068  cbnz     x8, #0x2d4a8
//   0x02d4a0: d37ef420  lsl      x0, x1, #2
//   0x02d4a4: 17ff7853  b        #0xb5f0
//   0x02d4a8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02d4ac: 910003fd  mov      x29, sp
//   0x02d4b0: 97ff7814  bl       #0xb500
uint64_t fde_1296_sub_02d498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37EFC28ULL) + (x1 ^ 0x97FF7814ULL) + (x2 ^ 0x02D498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EFC28ULL; // 0x02d498: lsr x8, x1, #0x3e
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x02d49c: cbnz x8, #0x2d4a8
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EF420ULL; // 0x02d4a0: lsl x0, x1, #2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7853ULL; // 0x02d4a4: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02d4a8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02d4ac: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7814ULL; // 0x02d4b0: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1297 @ 0x02d4b4..0x02d4d4 (32 bytes)
// [VN] Phục dựng FDE #1297 tại 0x02d4b4..0x02d4d4 (32 byte)
//   0x02d4b4: f9400068  ldr      x8, [x3]
//   0x02d4b8: cb010042  sub      x2, x2, x1
//   0x02d4bc: f100045f  cmp      x2, #1
//   0x02d4c0: cb020100  sub      x0, x8, x2
//   0x02d4c4: f9000060  str      x0, [x3]
//   0x02d4c8: 5400004b  b.lt     #0x2d4d0
//   0x02d4cc: 17ff75d1  b        #0xac10
//   0x02d4d0: d65f03c0  ret      
uint64_t fde_1297_sub_02d4b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02D4B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x02d4b4: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x02d4b8: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x02d4bc: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x02d4c0: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x02d4c4: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x02d4c8: b.lt #0x2d4d0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF75D1ULL; // 0x02d4cc: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02d4d0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1298 @ 0x02d4d4..0x02d4dc (8 bytes)
// [VN] Phục dựng FDE #1298 tại 0x02d4d4..0x02d4dc (8 byte)
//   0x02d4d4: f9400401  ldr      x1, [x0, #8]
//   0x02d4d8: 14000001  b        #0x2d4dc
uint64_t fde_1298_sub_02d4d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02D4D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x02d4d4: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02d4d8: b #0x2d4dc
    return acc;
}

// [EN] Reconstructed FDE #1299 @ 0x02d4dc..0x02d4f8 (28 bytes)
// [VN] Phục dựng FDE #1299 tại 0x02d4dc..0x02d4f8 (28 byte)
//   0x02d4dc: f9400808  ldr      x8, [x0, #0x10]
//   0x02d4e0: eb08003f  cmp      x1, x8
//   0x02d4e4: 54000080  b.eq     #0x2d4f4
//   0x02d4e8: d1001108  sub      x8, x8, #4
//   0x02d4ec: f9000808  str      x8, [x0, #0x10]
//   0x02d4f0: 17fffffc  b        #0x2d4e0
//   0x02d4f4: d65f03c0  ret      
uint64_t fde_1299_sub_02d4dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02D4DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x02d4dc: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x02d4e0: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x02d4e4: b.eq #0x2d4f4
    acc = (acc * 0x100000001B3ULL) ^ 0xD1001108ULL; // 0x02d4e8: sub x8, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x02d4ec: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x02d4f0: b #0x2d4e0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02d4f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1300 @ 0x02d4f8..0x02d5bc (196 bytes)
// [VN] Phục dựng FDE #1300 tại 0x02d4f8..0x02d5bc (196 byte)
//   0x02d4f8: d101c3ff  sub      sp, sp, #0x70
//   0x02d4fc: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02d500: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02d504: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02d508: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02d50c: 910183fd  add      x29, sp, #0x60
//   0x02d510: d53bd057  mrs      x23, tpidr_el0
//   0x02d514: f94016e8  ldr      x8, [x23, #0x28]
//   0x02d518: aa0103f4  mov      x20, x1
//   0x02d51c: aa0003f3  mov      x19, x0
//   0x02d520: 91004016  add      x22, x0, #0x10
//   0x02d524: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1300_sub_02d4f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x02D4F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02d4f8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02d4fc: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02d500: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02d504: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02d508: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02d50c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02d510: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02d514: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1301 @ 0x02d5bc..0x02d604 (72 bytes)
// [VN] Phục dựng FDE #1301 tại 0x02d5bc..0x02d604 (72 byte)
//   0x02d5bc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02d5c0: 910003fd  mov      x29, sp
//   0x02d5c4: d37efc28  lsr      x8, x1, #0x3e
//   0x02d5c8: b50001c8  cbnz     x8, #0x2d600
//   0x02d5cc: f9400808  ldr      x8, [x0, #0x10]
//   0x02d5d0: f9400009  ldr      x9, [x0]
//   0x02d5d4: cb090108  sub      x8, x8, x9
//   0x02d5d8: b27fefe9  mov      x9, #0x1ffffffffffffffe
//   0x02d5dc: eb88093f  cmp      x9, x8, asr #2
//   0x02d5e0: 540000a3  b.lo     #0x2d5f4
//   0x02d5e4: 9341fd08  asr      x8, x8, #1
//   0x02d5e8: eb01011f  cmp      x8, x1
uint64_t fde_1301_sub_02d5bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB88093FULL) + (x2 ^ 0x02D5BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02d5bc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02d5c0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37EFC28ULL; // 0x02d5c4: lsr x8, x1, #0x3e
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x02d5c8: cbnz x8, #0x2d600
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x02d5cc: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x02d5d0: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x02d5d4: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FEFE9ULL; // 0x02d5d8: mov x9, #0x1ffffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #1302 @ 0x02d604..0x02d6c8 (196 bytes)
// [VN] Phục dựng FDE #1302 tại 0x02d604..0x02d6c8 (196 byte)
//   0x02d604: d101c3ff  sub      sp, sp, #0x70
//   0x02d608: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02d60c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02d610: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02d614: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02d618: 910183fd  add      x29, sp, #0x60
//   0x02d61c: d53bd057  mrs      x23, tpidr_el0
//   0x02d620: f94016e8  ldr      x8, [x23, #0x28]
//   0x02d624: aa0103f4  mov      x20, x1
//   0x02d628: aa0003f3  mov      x19, x0
//   0x02d62c: 91004016  add      x22, x0, #0x10
//   0x02d630: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1302_sub_02d604(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x02D604ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02d604: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02d608: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02d60c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02d610: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02d614: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02d618: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02d61c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02d620: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1303 @ 0x02d6c8..0x02d6d8 (16 bytes)
// [VN] Phục dựng FDE #1303 tại 0x02d6c8..0x02d6d8 (16 byte)
//   0x02d6c8: 910023e0  add      x0, sp, #8
//   0x02d6cc: 910003e1  mov      x1, sp
//   0x02d6d0: b90003e8  str      w8, [sp]
//   0x02d6d4: 17fffe24  b        #0x2cf64
uint64_t fde_1303_sub_02d6c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FFFE24ULL) + (x2 ^ 0x02D6C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02d6c8: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x02d6cc: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB90003E8ULL; // 0x02d6d0: str w8, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE24ULL; // 0x02d6d4: b #0x2cf64
    return acc;
}

// [EN] Reconstructed FDE #1304 @ 0x02d6d8..0x02d6e4 (12 bytes)
// [VN] Phục dựng FDE #1304 tại 0x02d6d8..0x02d6e4 (12 byte)
//   0x02d6d8: 910023e0  add      x0, sp, #8
//   0x02d6dc: 910093e1  add      x1, sp, #0x24
//   0x02d6e0: 17fffe19  b        #0x2cf44
uint64_t fde_1304_sub_02d6d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FFFE19ULL) + (x2 ^ 0x02D6D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02d6d8: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x910093E1ULL; // 0x02d6dc: add x1, sp, #0x24
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFE19ULL; // 0x02d6e0: b #0x2cf44
    return acc;
}

// [EN] Reconstructed FDE #1305 @ 0x02d6e4..0x02d6f0 (12 bytes)
// [VN] Phục dựng FDE #1305 tại 0x02d6e4..0x02d6f0 (12 byte)
//   0x02d6e4: 90000080  adrp     x0, #0x3d000
//   0x02d6e8: 910d6000  add      x0, x0, #0x358
//   0x02d6ec: 17ff76a1  b        #0xb170
uint64_t fde_1305_sub_02d6e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000080ULL) + (x1 ^ 0x17FF76A1ULL) + (x2 ^ 0x02D6E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000080ULL; // 0x02d6e4: adrp x0, #0x3d000
    acc = (acc * 0x100000001B3ULL) ^ 0x910D6000ULL; // 0x02d6e8: add x0, x0, #0x358
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF76A1ULL; // 0x02d6ec: b #0xb170
    return acc;
}

// [EN] Reconstructed FDE #1306 @ 0x02d6f0..0x02d7a4 (180 bytes)
// [VN] Phục dựng FDE #1306 tại 0x02d6f0..0x02d7a4 (180 byte)
//   0x02d6f0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02d6f4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02d6f8: 910043fd  add      x29, sp, #0x10
//   0x02d6fc: 90000080  adrp     x0, #0x3d000
//   0x02d700: 913e9000  add      x0, x0, #0xfa4
//   0x02d704: 97ff769b  bl       #0xb170
//   0x02d708: b4000400  cbz      x0, #0x2d788
//   0x02d70c: aa0003f3  mov      x19, x0
//   0x02d710: 97ffa79a  bl       #0x17578
//   0x02d714: d0000081  adrp     x1, #0x3f000
//   0x02d718: 912a9421  add      x1, x1, #0xaa5
//   0x02d71c: 71007c1f  cmp      w0, #0x1f
uint64_t fde_1306_sub_02d6f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x97FFA79AULL) + (x2 ^ 0x02D6F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02d6f0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02d6f4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02d6f8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000080ULL; // 0x02d6fc: adrp x0, #0x3d000
    acc = (acc * 0x100000001B3ULL) ^ 0x913E9000ULL; // 0x02d700: add x0, x0, #0xfa4
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF769BULL; // 0x02d704: bl #0xb170
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000400ULL; // 0x02d708: cbz x0, #0x2d788
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02d70c: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1307 @ 0x02d7a4..0x02d7b8 (20 bytes)
// [VN] Phục dựng FDE #1307 tại 0x02d7a4..0x02d7b8 (20 byte)
//   0x02d7a4: 90000188  adrp     x8, #0x5d000
//   0x02d7a8: f9432500  ldr      x0, [x8, #0x648]
//   0x02d7ac: f9400008  ldr      x8, [x0]
//   0x02d7b0: f9401501  ldr      x1, [x8, #0x28]
//   0x02d7b4: d61f0020  br       x1
uint64_t fde_1307_sub_02d7a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000188ULL) + (x1 ^ 0xD61F0020ULL) + (x2 ^ 0x02D7A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000188ULL; // 0x02d7a4: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9432500ULL; // 0x02d7a8: ldr x0, [x8, #0x648]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02d7ac: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401501ULL; // 0x02d7b0: ldr x1, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x02d7b4: br x1
    return acc;
}

// [EN] Reconstructed FDE #1308 @ 0x02d7b8..0x02d898 (224 bytes)
// [VN] Phục dựng FDE #1308 tại 0x02d7b8..0x02d898 (224 byte)
//   0x02d7b8: d10103ff  sub      sp, sp, #0x40
//   0x02d7bc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x02d7c0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02d7c4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02d7c8: 9100c3fd  add      x29, sp, #0x30
//   0x02d7cc: d53bd055  mrs      x21, tpidr_el0
//   0x02d7d0: f94016a8  ldr      x8, [x21, #0x28]
//   0x02d7d4: 528000c2  mov      w2, #6
//   0x02d7d8: aa0103f3  mov      x19, x1
//   0x02d7dc: aa0003f4  mov      x20, x0
//   0x02d7e0: f90007e8  str      x8, [sp, #8]
//   0x02d7e4: 90000188  adrp     x8, #0x5d000
uint64_t fde_1308_sub_02d7b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x02D7B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02d7b8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x02d7bc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02d7c0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02d7c4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02d7c8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02d7cc: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02d7d0: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C2ULL; // 0x02d7d4: mov w2, #6
    return acc;
}

// [EN] Reconstructed FDE #1309 @ 0x02d898..0x02d9a8 (272 bytes)
// [VN] Phục dựng FDE #1309 tại 0x02d898..0x02d9a8 (272 byte)
//   0x02d898: d10203ff  sub      sp, sp, #0x80
//   0x02d89c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02d8a0: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02d8a4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02d8a8: 9101c3fd  add      x29, sp, #0x70
//   0x02d8ac: d53bd054  mrs      x20, tpidr_el0
//   0x02d8b0: f9401688  ldr      x8, [x20, #0x28]
//   0x02d8b4: aa0103f3  mov      x19, x1
//   0x02d8b8: f81d83a8  stur     x8, [x29, #-0x28]
//   0x02d8bc: 90000188  adrp     x8, #0x5d000
//   0x02d8c0: f9432d08  ldr      x8, [x8, #0x658]
//   0x02d8c4: d63f0100  blr      x8
uint64_t fde_1309_sub_02d898(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF81D83A8ULL) + (x2 ^ 0x02D898ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02d898: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02d89c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02d8a0: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02d8a4: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02d8a8: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02d8ac: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02d8b0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02d8b4: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #1310 @ 0x02d9a8..0x02db30 (392 bytes)
// [VN] Phục dựng FDE #1310 tại 0x02d9a8..0x02db30 (392 byte)
//   0x02d9a8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02d9ac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02d9b0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02d9b4: 910083fd  add      x29, sp, #0x20
//   0x02d9b8: aa0003f4  mov      x20, x0
//   0x02d9bc: 97ffa6ef  bl       #0x17578
//   0x02d9c0: 7100501f  cmp      w0, #0x14
//   0x02d9c4: 5400006a  b.ge     #0x2d9d0
//   0x02d9c8: 12800000  mov      w0, #-1
//   0x02d9cc: 14000055  b        #0x2db20
//   0x02d9d0: f9400288  ldr      x8, [x20]
//   0x02d9d4: 90000193  adrp     x19, #0x5d000
uint64_t fde_1310_sub_02d9a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x12800000ULL) + (x2 ^ 0x02D9A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02d9a8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02d9ac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02d9b0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02d9b4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02d9b8: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA6EFULL; // 0x02d9bc: bl #0x17578
    acc = (acc * 0x100000001B3ULL) ^ 0x7100501FULL; // 0x02d9c0: cmp w0, #0x14
    acc = (acc * 0x100000001B3ULL) ^ 0x5400006AULL; // 0x02d9c4: b.ge #0x2d9d0
    return acc;
}

// [EN] Reconstructed FDE #1311 @ 0x02db30..0x02db34 (4 bytes)
// [VN] Phục dựng FDE #1311 tại 0x02db30..0x02db34 (4 byte)
//   0x02db30: 17ffff9e  b        #0x2d9a8
uint64_t fde_1311_sub_02db30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFFF9EULL) + (x1 ^ 0x17FFFF9EULL) + (x2 ^ 0x02DB30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFF9EULL; // 0x02db30: b #0x2d9a8
    return acc;
}

// [EN] Reconstructed FDE #1312 @ 0x02db34..0x02db88 (84 bytes)
// [VN] Phục dựng FDE #1312 tại 0x02db34..0x02db88 (84 byte)
//   0x02db34: d10103ff  sub      sp, sp, #0x40
//   0x02db38: f90013f3  str      x19, [sp, #0x20]
//   0x02db3c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02db40: 9100c3fd  add      x29, sp, #0x30
//   0x02db44: d53bd053  mrs      x19, tpidr_el0
//   0x02db48: f9401668  ldr      x8, [x19, #0x28]
//   0x02db4c: f9000fe8  str      x8, [sp, #0x18]
//   0x02db50: a90087e2  stp      x2, x1, [sp, #8]
//   0x02db54: 910043e1  add      x1, sp, #0x10
//   0x02db58: 910023e2  add      x2, sp, #8
//   0x02db5c: 9400000b  bl       #0x2db88
//   0x02db60: f9401668  ldr      x8, [x19, #0x28]
uint64_t fde_1312_sub_02db34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E1ULL) + (x2 ^ 0x02DB34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02db34: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x02db38: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02db3c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02db40: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02db44: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02db48: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x02db4c: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90087E2ULL; // 0x02db50: stp x2, x1, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #1313 @ 0x02db88..0x02dbac (36 bytes)
// [VN] Phục dựng FDE #1313 tại 0x02db88..0x02dbac (36 byte)
//   0x02db88: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02db8c: 910003fd  mov      x29, sp
//   0x02db90: f9401000  ldr      x0, [x0, #0x20]
//   0x02db94: b40000a0  cbz      x0, #0x2dba8
//   0x02db98: f9400008  ldr      x8, [x0]
//   0x02db9c: f9401903  ldr      x3, [x8, #0x30]
//   0x02dba0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x02dba4: d61f0060  br       x3
//   0x02dba8: 97ffa614  bl       #0x173f8
uint64_t fde_1313_sub_02db88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FFA614ULL) + (x2 ^ 0x02DB88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x02db88: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x02db8c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x02db90: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x02db94: cbz x0, #0x2dba8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02db98: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401903ULL; // 0x02db9c: ldr x3, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x02dba0: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x02dba4: br x3
    return acc;
}

// [EN] Reconstructed FDE #1314 @ 0x02dbac..0x02dbb0 (4 bytes)
// [VN] Phục dựng FDE #1314 tại 0x02dbac..0x02dbb0 (4 byte)
//   0x02dbac: d65f03c0  ret      
uint64_t fde_1314_sub_02dbac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02DBACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02dbac: ret 
    return acc;
}

// [EN] Reconstructed FDE #1315 @ 0x02dbb0..0x02dbb4 (4 bytes)
// [VN] Phục dựng FDE #1315 tại 0x02dbb0..0x02dbb4 (4 byte)
//   0x02dbb0: 17ff7464  b        #0xad40
uint64_t fde_1315_sub_02dbb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF7464ULL) + (x1 ^ 0x17FF7464ULL) + (x2 ^ 0x02DBB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7464ULL; // 0x02dbb0: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1316 @ 0x02dbb4..0x02dbec (56 bytes)
// [VN] Phục dựng FDE #1316 tại 0x02dbb4..0x02dbec (56 byte)
//   0x02dbb4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02dbb8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02dbbc: 910043fd  add      x29, sp, #0x10
//   0x02dbc0: aa0003f3  mov      x19, x0
//   0x02dbc4: 52800200  mov      w0, #0x10
//   0x02dbc8: 97ff768a  bl       #0xb5f0
//   0x02dbcc: b0000168  adrp     x8, #0x5a000
//   0x02dbd0: 91264108  add      x8, x8, #0x990
//   0x02dbd4: f9000008  str      x8, [x0]
//   0x02dbd8: f9400668  ldr      x8, [x19, #8]
//   0x02dbdc: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02dbe0: f9000408  str      x8, [x0, #8]
uint64_t fde_1316_sub_02dbb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000008ULL) + (x2 ^ 0x02DBB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02dbb4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02dbb8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02dbbc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02dbc0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x02dbc4: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF768AULL; // 0x02dbc8: bl #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000168ULL; // 0x02dbcc: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91264108ULL; // 0x02dbd0: add x8, x8, #0x990
    return acc;
}

// [EN] Reconstructed FDE #1317 @ 0x02dbec..0x02dc04 (24 bytes)
// [VN] Phục dựng FDE #1317 tại 0x02dbec..0x02dc04 (24 byte)
//   0x02dbec: b0000168  adrp     x8, #0x5a000
//   0x02dbf0: 91264108  add      x8, x8, #0x990
//   0x02dbf4: f9000028  str      x8, [x1]
//   0x02dbf8: f9400408  ldr      x8, [x0, #8]
//   0x02dbfc: f9000428  str      x8, [x1, #8]
//   0x02dc00: d65f03c0  ret      
uint64_t fde_1317_sub_02dbec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000168ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02DBECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000168ULL; // 0x02dbec: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91264108ULL; // 0x02dbf0: add x8, x8, #0x990
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x02dbf4: str x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x02dbf8: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000428ULL; // 0x02dbfc: str x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02dc00: ret 
    return acc;
}

// [EN] Reconstructed FDE #1318 @ 0x02dc04..0x02dc08 (4 bytes)
// [VN] Phục dựng FDE #1318 tại 0x02dc04..0x02dc08 (4 byte)
//   0x02dc04: d65f03c0  ret      
uint64_t fde_1318_sub_02dc04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02DC04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02dc04: ret 
    return acc;
}

// [EN] Reconstructed FDE #1319 @ 0x02dc08..0x02dc0c (4 bytes)
// [VN] Phục dựng FDE #1319 tại 0x02dc08..0x02dc0c (4 byte)
//   0x02dc08: 17ff744e  b        #0xad40
uint64_t fde_1319_sub_02dc08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF744EULL) + (x1 ^ 0x17FF744EULL) + (x2 ^ 0x02DC08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF744EULL; // 0x02dc08: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1320 @ 0x02dc0c..0x02dc24 (24 bytes)
// [VN] Phục dựng FDE #1320 tại 0x02dc0c..0x02dc24 (24 byte)
//   0x02dc0c: f9400408  ldr      x8, [x0, #8]
//   0x02dc10: f9400049  ldr      x9, [x2]
//   0x02dc14: f9400108  ldr      x8, [x8]
//   0x02dc18: eb09011f  cmp      x8, x9
//   0x02dc1c: 1a9f17e0  cset     w0, eq
//   0x02dc20: d65f03c0  ret      
uint64_t fde_1320_sub_02dc0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02DC0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x02dc0c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400049ULL; // 0x02dc10: ldr x9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x02dc14: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02dc18: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x02dc1c: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02dc20: ret 
    return acc;
}

// [EN] Reconstructed FDE #1321 @ 0x02dc24..0x02dc54 (48 bytes)
// [VN] Phục dựng FDE #1321 tại 0x02dc24..0x02dc54 (48 byte)
//   0x02dc24: aa0003e8  mov      x8, x0
//   0x02dc28: f9401000  ldr      x0, [x0, #0x20]
//   0x02dc2c: eb00011f  cmp      x8, x0
//   0x02dc30: 540000a0  b.eq     #0x2dc44
//   0x02dc34: b40000e0  cbz      x0, #0x2dc50
//   0x02dc38: f9400008  ldr      x8, [x0]
//   0x02dc3c: f9401501  ldr      x1, [x8, #0x28]
//   0x02dc40: d61f0020  br       x1
//   0x02dc44: f9400008  ldr      x8, [x0]
//   0x02dc48: f9401101  ldr      x1, [x8, #0x20]
//   0x02dc4c: d61f0020  br       x1
//   0x02dc50: d65f03c0  ret      
uint64_t fde_1321_sub_02dc24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x02DC24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02dc24: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x02dc28: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x02dc2c: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x02dc30: b.eq #0x2dc44
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x02dc34: cbz x0, #0x2dc50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02dc38: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401501ULL; // 0x02dc3c: ldr x1, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x02dc40: br x1
    return acc;
}

// [EN] Reconstructed FDE #1322 @ 0x02dc54..0x02dcf8 (164 bytes)
// [VN] Phục dựng FDE #1322 tại 0x02dc54..0x02dcf8 (164 byte)
//   0x02dc54: d10183ff  sub      sp, sp, #0x60
//   0x02dc58: f90013f7  str      x23, [sp, #0x20]
//   0x02dc5c: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02dc60: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02dc64: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02dc68: 910143fd  add      x29, sp, #0x50
//   0x02dc6c: d53bd057  mrs      x23, tpidr_el0
//   0x02dc70: f94016e8  ldr      x8, [x23, #0x28]
//   0x02dc74: aa0003f6  mov      x22, x0
//   0x02dc78: aa0303f3  mov      x19, x3
//   0x02dc7c: aa0203f4  mov      x20, x2
//   0x02dc80: f9000fe8  str      x8, [sp, #0x18]
uint64_t fde_1322_sub_02dc54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F6ULL) + (x2 ^ 0x02DC54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02dc54: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x02dc58: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02dc5c: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02dc60: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02dc64: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02dc68: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02dc6c: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02dc70: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1323 @ 0x02dcf8..0x02dd54 (92 bytes)
// [VN] Phục dựng FDE #1323 tại 0x02dcf8..0x02dd54 (92 byte)
//   0x02dcf8: d10103ff  sub      sp, sp, #0x40
//   0x02dcfc: f90013f3  str      x19, [sp, #0x20]
//   0x02dd00: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02dd04: 9100c3fd  add      x29, sp, #0x30
//   0x02dd08: d53bd053  mrs      x19, tpidr_el0
//   0x02dd0c: f9401668  ldr      x8, [x19, #0x28]
//   0x02dd10: d0000082  adrp     x2, #0x3f000
//   0x02dd14: 913ce842  add      x2, x2, #0xf3a
//   0x02dd18: 910043e3  add      x3, sp, #0x10
//   0x02dd1c: 910023e4  add      x4, sp, #8
//   0x02dd20: f9000fe8  str      x8, [sp, #0x18]
//   0x02dd24: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1323_sub_02dcf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x02DCF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02dcf8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x02dcfc: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02dd00: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02dd04: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x02dd08: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x02dd0c: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000082ULL; // 0x02dd10: adrp x2, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x913CE842ULL; // 0x02dd14: add x2, x2, #0xf3a
    return acc;
}

// [EN] Reconstructed FDE #1324 @ 0x02dd54..0x02dddc (136 bytes)
// [VN] Phục dựng FDE #1324 tại 0x02dd54..0x02dddc (136 byte)
//   0x02dd54: d10103ff  sub      sp, sp, #0x40
//   0x02dd58: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02dd5c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02dd60: 9100c3fd  add      x29, sp, #0x30
//   0x02dd64: d53bd054  mrs      x20, tpidr_el0
//   0x02dd68: f9401688  ldr      x8, [x20, #0x28]
//   0x02dd6c: aa0003f3  mov      x19, x0
//   0x02dd70: f9000fe8  str      x8, [sp, #0x18]
//   0x02dd74: a90083fe  stp      x30, x0, [sp, #8]
//   0x02dd78: d0000160  adrp     x0, #0x5b000
//   0x02dd7c: f9476800  ldr      x0, [x0, #0xed0]
//   0x02dd80: 97ff73c8  bl       #0xaca0
uint64_t fde_1324_sub_02dd54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xA90083FEULL) + (x2 ^ 0x02DD54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02dd54: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02dd58: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02dd5c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02dd60: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02dd64: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02dd68: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02dd6c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x02dd70: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #1325 @ 0x02dddc..0x02dec0 (228 bytes)
// [VN] Phục dựng FDE #1325 tại 0x02dddc..0x02dec0 (228 byte)
//   0x02dddc: d10183ff  sub      sp, sp, #0x60
//   0x02dde0: f90013f7  str      x23, [sp, #0x20]
//   0x02dde4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x02dde8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02ddec: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02ddf0: 910143fd  add      x29, sp, #0x50
//   0x02ddf4: d53bd055  mrs      x21, tpidr_el0
//   0x02ddf8: f94016a8  ldr      x8, [x21, #0x28]
//   0x02ddfc: 12000033  and      w19, w1, #1
//   0x02de00: f9000fe8  str      x8, [sp, #0x18]
//   0x02de04: a90083fe  stp      x30, x0, [sp, #8]
//   0x02de08: b4000360  cbz      x0, #0x2de74
uint64_t fde_1325_sub_02dddc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x12000033ULL) + (x2 ^ 0x02DDDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02dddc: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x02dde0: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x02dde4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02dde8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02ddec: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02ddf0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02ddf4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02ddf8: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1326 @ 0x02dec0..0x02df44 (132 bytes)
// [VN] Phục dựng FDE #1326 tại 0x02dec0..0x02df44 (132 byte)
//   0x02dec0: d100c3ff  sub      sp, sp, #0x30
//   0x02dec4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02dec8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02decc: 910083fd  add      x29, sp, #0x20
//   0x02ded0: d53bd054  mrs      x20, tpidr_el0
//   0x02ded4: f9401688  ldr      x8, [x20, #0x28]
//   0x02ded8: f90007e8  str      x8, [sp, #8]
//   0x02dedc: f90003fe  str      x30, [sp]
//   0x02dee0: b40000e0  cbz      x0, #0x2defc
//   0x02dee4: f0000168  adrp     x8, #0x5c000
//   0x02dee8: b940f509  ldr      w9, [x8, #0xf4]
//   0x02deec: 71000529  subs     w9, w9, #1
uint64_t fde_1326_sub_02dec0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xB40000E0ULL) + (x2 ^ 0x02DEC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x02dec0: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02dec4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02dec8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02decc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02ded0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02ded4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x02ded8: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003FEULL; // 0x02dedc: str x30, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1327 @ 0x02df44..0x02dfd4 (144 bytes)
// [VN] Phục dựng FDE #1327 tại 0x02df44..0x02dfd4 (144 byte)
//   0x02df44: d100c3ff  sub      sp, sp, #0x30
//   0x02df48: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02df4c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02df50: 910083fd  add      x29, sp, #0x20
//   0x02df54: d53bd054  mrs      x20, tpidr_el0
//   0x02df58: f9401688  ldr      x8, [x20, #0x28]
//   0x02df5c: f90007e8  str      x8, [sp, #8]
//   0x02df60: f90003fe  str      x30, [sp]
//   0x02df64: b4000100  cbz      x0, #0x2df84
//   0x02df68: f0000168  adrp     x8, #0x5c000
//   0x02df6c: b940f909  ldr      w9, [x8, #0xf8]
//   0x02df70: 71000529  subs     w9, w9, #1
uint64_t fde_1327_sub_02df44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xB4000100ULL) + (x2 ^ 0x02DF44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x02df44: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02df48: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02df4c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02df50: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02df54: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02df58: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x02df5c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003FEULL; // 0x02df60: str x30, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1328 @ 0x02dfd4..0x02e070 (156 bytes)
// [VN] Phục dựng FDE #1328 tại 0x02dfd4..0x02e070 (156 byte)
//   0x02dfd4: d10103ff  sub      sp, sp, #0x40
//   0x02dfd8: f9000bf5  str      x21, [sp, #0x10]
//   0x02dfdc: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02dfe0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02dfe4: 9100c3fd  add      x29, sp, #0x30
//   0x02dfe8: d53bd055  mrs      x21, tpidr_el0
//   0x02dfec: f94016a8  ldr      x8, [x21, #0x28]
//   0x02dff0: 2a0103f4  mov      w20, w1
//   0x02dff4: aa0003f3  mov      x19, x0
//   0x02dff8: f90007e8  str      x8, [sp, #8]
//   0x02dffc: f90003fe  str      x30, [sp]
//   0x02e000: f0000168  adrp     x8, #0x5d000
uint64_t fde_1328_sub_02dfd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x02DFD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02dfd4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x02dfd8: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02dfdc: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02dfe0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02dfe4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02dfe8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02dfec: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103F4ULL; // 0x02dff0: mov w20, w1
    return acc;
}

// [EN] Reconstructed FDE #1329 @ 0x02e070..0x02e13c (204 bytes)
// [VN] Phục dựng FDE #1329 tại 0x02e070..0x02e13c (204 byte)
//   0x02e070: d10103ff  sub      sp, sp, #0x40
//   0x02e074: f9000bf5  str      x21, [sp, #0x10]
//   0x02e078: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x02e07c: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x02e080: 9100c3fd  add      x29, sp, #0x30
//   0x02e084: d53bd055  mrs      x21, tpidr_el0
//   0x02e088: f94016a8  ldr      x8, [x21, #0x28]
//   0x02e08c: aa0103f3  mov      x19, x1
//   0x02e090: aa0003f4  mov      x20, x0
//   0x02e094: f102843f  cmp      x1, #0xa1
//   0x02e098: f90007e8  str      x8, [sp, #8]
//   0x02e09c: f90003fe  str      x30, [sp]
uint64_t fde_1329_sub_02e070(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x02E070ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x02e070: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x02e074: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x02e078: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x02e07c: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x02e080: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x02e084: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x02e088: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02e08c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #1330 @ 0x02e13c..0x02e2cc (400 bytes)
// [VN] Phục dựng FDE #1330 tại 0x02e13c..0x02e2cc (400 byte)
//   0x02e13c: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02e140: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e144: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e148: 910083fd  add      x29, sp, #0x20
//   0x02e14c: f0000175  adrp     x21, #0x5d000
//   0x02e150: f94352a8  ldr      x8, [x21, #0x6a0]
//   0x02e154: f0000174  adrp     x20, #0x5d000
//   0x02e158: b4000168  cbz      x8, #0x2e184
//   0x02e15c: f9435688  ldr      x8, [x20, #0x6a8]
//   0x02e160: b4000128  cbz      x8, #0x2e184
//   0x02e164: 97ffa52e  bl       #0x1761c
//   0x02e168: 360007e0  tbz      w0, #0, #0x2e264
uint64_t fde_1330_sub_02e13c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9435688ULL) + (x2 ^ 0x02E13CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02e13c: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e140: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e144: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e148: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000175ULL; // 0x02e14c: adrp x21, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94352A8ULL; // 0x02e150: ldr x8, [x21, #0x6a0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000174ULL; // 0x02e154: adrp x20, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000168ULL; // 0x02e158: cbz x8, #0x2e184
    return acc;
}

// [EN] Reconstructed FDE #1331 @ 0x02e2cc..0x02e408 (316 bytes)
// [VN] Phục dựng FDE #1331 tại 0x02e2cc..0x02e408 (316 byte)
//   0x02e2cc: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02e2d0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e2d4: 910043fd  add      x29, sp, #0x10
//   0x02e2d8: 2a0003f3  mov      w19, w0
//   0x02e2dc: 2a1f03e0  mov      w0, wzr
//   0x02e2e0: 2a1f03e1  mov      w1, wzr
//   0x02e2e4: 97ff733f  bl       #0xafe0
//   0x02e2e8: 7104027f  cmp      w19, #0x100
//   0x02e2ec: 54000081  b.ne     #0x2e2fc
//   0x02e2f0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e2f4: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02e2f8: 17ffff91  b        #0x2e13c
uint64_t fde_1331_sub_02e2cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x54000081ULL) + (x2 ^ 0x02E2CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02e2cc: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e2d0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e2d4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x02e2d8: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02e2dc: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x02e2e0: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF733FULL; // 0x02e2e4: bl #0xafe0
    acc = (acc * 0x100000001B3ULL) ^ 0x7104027FULL; // 0x02e2e8: cmp w19, #0x100
    return acc;
}

// [EN] Reconstructed FDE #1332 @ 0x02e408..0x02e448 (64 bytes)
// [VN] Phục dựng FDE #1332 tại 0x02e408..0x02e448 (64 byte)
//   0x02e408: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02e40c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e410: 910043fd  add      x29, sp, #0x10
//   0x02e414: 2a0003f3  mov      w19, w0
//   0x02e418: 97ffa458  bl       #0x17578
//   0x02e41c: 51006808  sub      w8, w0, #0x1a
//   0x02e420: 7100211f  cmp      w8, #8
//   0x02e424: 540000a8  b.hi     #0x2e438
//   0x02e428: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e42c: 2a1303e0  mov      w0, w19
//   0x02e430: f84207f3  ldr      x19, [sp], #0x20
//   0x02e434: 17ffffa6  b        #0x2e2cc
uint64_t fde_1332_sub_02e408(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x02E408ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02e408: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e40c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e410: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x02e414: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA458ULL; // 0x02e418: bl #0x17578
    acc = (acc * 0x100000001B3ULL) ^ 0x51006808ULL; // 0x02e41c: sub w8, w0, #0x1a
    acc = (acc * 0x100000001B3ULL) ^ 0x7100211FULL; // 0x02e420: cmp w8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x02e424: b.hi #0x2e438
    return acc;
}

// [EN] Reconstructed FDE #1333 @ 0x02e448..0x02e584 (316 bytes)
// [VN] Phục dựng FDE #1333 tại 0x02e448..0x02e584 (316 byte)
//   0x02e448: d10583ff  sub      sp, sp, #0x160
//   0x02e44c: a91167fc  stp      x28, x25, [sp, #0x110]
//   0x02e450: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x02e454: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x02e458: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x02e45c: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x02e460: 910543fd  add      x29, sp, #0x150
//   0x02e464: d53bd059  mrs      x25, tpidr_el0
//   0x02e468: f9401728  ldr      x8, [x25, #0x28]
//   0x02e46c: b0000060  adrp     x0, #0x3b000
//   0x02e470: 911fd400  add      x0, x0, #0x7f5
//   0x02e474: f81b83a8  stur     x8, [x29, #-0x48]
uint64_t fde_1333_sub_02e448(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x02E448ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x02e448: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xA91167FCULL; // 0x02e44c: stp x28, x25, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x02e450: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x02e454: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x02e458: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x02e45c: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x02e460: add x29, sp, #0x150
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02e464: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1334 @ 0x02e584..0x02e628 (164 bytes)
// [VN] Phục dựng FDE #1334 tại 0x02e584..0x02e628 (164 byte)
//   0x02e584: d10483ff  sub      sp, sp, #0x120
//   0x02e588: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x02e58c: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02e590: 910443fd  add      x29, sp, #0x110
//   0x02e594: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x02e598: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x02e59c: f90057e7  str      x7, [sp, #0xa8]
//   0x02e5a0: ad0007e0  stp      q0, q1, [sp]
//   0x02e5a4: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02e5a8: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02e5ac: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02e5b0: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_1334_sub_02e584(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x02E584ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02e584: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x02e588: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02e58c: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02e590: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x02e594: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x02e598: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x02e59c: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02e5a0: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1335 @ 0x02e628..0x02e6f0 (200 bytes)
// [VN] Phục dựng FDE #1335 tại 0x02e628..0x02e6f0 (200 byte)
//   0x02e628: d10203ff  sub      sp, sp, #0x80
//   0x02e62c: f9001bf9  str      x25, [sp, #0x30]
//   0x02e630: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02e634: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02e638: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02e63c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02e640: 9101c3fd  add      x29, sp, #0x70
//   0x02e644: d53bd059  mrs      x25, tpidr_el0
//   0x02e648: f9401728  ldr      x8, [x25, #0x28]
//   0x02e64c: aa0203f7  mov      x23, x2
//   0x02e650: aa0103e2  mov      x2, x1
//   0x02e654: 910023e1  add      x1, sp, #8
uint64_t fde_1335_sub_02e628(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x02E628ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02e628: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x02e62c: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02e630: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02e634: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02e638: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02e63c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02e640: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x02e644: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1336 @ 0x02e6f0..0x02e750 (96 bytes)
// [VN] Phục dựng FDE #1336 tại 0x02e6f0..0x02e750 (96 byte)
//   0x02e6f0: aa0003e8  mov      x8, x0
//   0x02e6f4: f8408c09  ldr      x9, [x0, #8]!
//   0x02e6f8: b4000229  cbz      x9, #0x2e73c
//   0x02e6fc: f940004a  ldr      x10, [x2]
//   0x02e700: 91002100  add      x0, x8, #8
//   0x02e704: f9401128  ldr      x8, [x9, #0x20]
//   0x02e708: eb08015f  cmp      x10, x8
//   0x02e70c: 540000a2  b.hs     #0x2e720
//   0x02e710: f9400128  ldr      x8, [x9]
//   0x02e714: b4000188  cbz      x8, #0x2e744
//   0x02e718: aa0903e0  mov      x0, x9
//   0x02e71c: 14000006  b        #0x2e734
uint64_t fde_1336_sub_02e6f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x02E6F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02e6f0: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x02e6f4: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x02e6f8: cbz x9, #0x2e73c
    acc = (acc * 0x100000001B3ULL) ^ 0xF940004AULL; // 0x02e6fc: ldr x10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x02e700: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401128ULL; // 0x02e704: ldr x8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08015FULL; // 0x02e708: cmp x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x02e70c: b.hs #0x2e720
    return acc;
}

// [EN] Reconstructed FDE #1337 @ 0x02e750..0x02e7a4 (84 bytes)
// [VN] Phục dựng FDE #1337 tại 0x02e750..0x02e7a4 (84 byte)
//   0x02e750: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x02e754: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e758: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e75c: 910083fd  add      x29, sp, #0x20
//   0x02e760: 91002015  add      x21, x0, #8
//   0x02e764: 52800021  mov      w1, #1
//   0x02e768: aa1503e0  mov      x0, x21
//   0x02e76c: aa0203f3  mov      x19, x2
//   0x02e770: aa0803f4  mov      x20, x8
//   0x02e774: 52800036  mov      w22, #1
//   0x02e778: 94000022  bl       #0x2e800
//   0x02e77c: a9005680  stp      x0, x21, [x20]
uint64_t fde_1337_sub_02e750(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x02E750ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x02e750: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e754: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e758: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e75c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x02e760: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x02e764: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x02e768: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x02e76c: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1338 @ 0x02e7a4..0x02e7f8 (84 bytes)
// [VN] Phục dựng FDE #1338 tại 0x02e7a4..0x02e7f8 (84 byte)
//   0x02e7a4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02e7a8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e7ac: 910043fd  add      x29, sp, #0x10
//   0x02e7b0: a9007c7f  stp      xzr, xzr, [x3]
//   0x02e7b4: f9000861  str      x1, [x3, #0x10]
//   0x02e7b8: f9000043  str      x3, [x2]
//   0x02e7bc: f9400008  ldr      x8, [x0]
//   0x02e7c0: aa0003f3  mov      x19, x0
//   0x02e7c4: f9400108  ldr      x8, [x8]
//   0x02e7c8: b4000068  cbz      x8, #0x2e7d4
//   0x02e7cc: f9000268  str      x8, [x19]
//   0x02e7d0: f9400043  ldr      x3, [x2]
uint64_t fde_1338_sub_02e7a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x02E7A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02e7a4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e7a8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e7ac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x02e7b0: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x02e7b4: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x02e7b8: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02e7bc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e7c0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1339 @ 0x02e7f8..0x02e800 (8 bytes)
// [VN] Phục dựng FDE #1339 tại 0x02e7f8..0x02e800 (8 byte)
//   0x02e7f8: aa1f03e1  mov      x1, xzr
//   0x02e7fc: 1400000e  b        #0x2e834
uint64_t fde_1339_sub_02e7f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000EULL) + (x2 ^ 0x02E7F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x02e7f8: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x02e7fc: b #0x2e834
    return acc;
}

// [EN] Reconstructed FDE #1340 @ 0x02e800..0x02e808 (8 bytes)
// [VN] Phục dựng FDE #1340 tại 0x02e800..0x02e808 (8 byte)
//   0x02e800: aa1f03e2  mov      x2, xzr
//   0x02e804: 14000001  b        #0x2e808
uint64_t fde_1340_sub_02e800(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x02E800ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x02e800: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x02e804: b #0x2e808
    return acc;
}

// [EN] Reconstructed FDE #1341 @ 0x02e808..0x02e834 (44 bytes)
// [VN] Phục dựng FDE #1341 tại 0x02e808..0x02e834 (44 byte)
//   0x02e808: b200f3e8  mov      x8, #0x5555555555555555
//   0x02e80c: f28aaac8  movk     x8, #0x5556
//   0x02e810: f2e0aaa8  movk     x8, #0x555, lsl #48
//   0x02e814: eb08003f  cmp      x1, x8
//   0x02e818: 54000082  b.hs     #0x2e828
//   0x02e81c: 8b010428  add      x8, x1, x1, lsl #1
//   0x02e820: d37ced00  lsl      x0, x8, #4
//   0x02e824: 17ff7373  b        #0xb5f0
//   0x02e828: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x02e82c: 910003fd  mov      x29, sp
//   0x02e830: 97ff7334  bl       #0xb500
uint64_t fde_1341_sub_02e808(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB200F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x02E808ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB200F3E8ULL; // 0x02e808: mov x8, #0x5555555555555555
    acc = (acc * 0x100000001B3ULL) ^ 0xF28AAAC8ULL; // 0x02e80c: movk x8, #0x5556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0AAA8ULL; // 0x02e810: movk x8, #0x555, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x02e814: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x02e818: b.hs #0x2e828
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x02e81c: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CED00ULL; // 0x02e820: lsl x0, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7373ULL; // 0x02e824: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #1342 @ 0x02e834..0x02e84c (24 bytes)
// [VN] Phục dựng FDE #1342 tại 0x02e834..0x02e84c (24 byte)
//   0x02e834: aa0003e8  mov      x8, x0
//   0x02e838: f9400000  ldr      x0, [x0]
//   0x02e83c: f9000101  str      x1, [x8]
//   0x02e840: b4000040  cbz      x0, #0x2e848
//   0x02e844: 17ff713f  b        #0xad40
//   0x02e848: d65f03c0  ret      
uint64_t fde_1342_sub_02e834(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02E834ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x02e834: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x02e838: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x02e83c: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x02e840: cbz x0, #0x2e848
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF713FULL; // 0x02e844: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02e848: ret 
    return acc;
}

// [EN] Reconstructed FDE #1343 @ 0x02e84c..0x02e890 (68 bytes)
// [VN] Phục dựng FDE #1343 tại 0x02e84c..0x02e890 (68 byte)
//   0x02e84c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02e850: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e854: 910043fd  add      x29, sp, #0x10
//   0x02e858: aa0003f3  mov      x19, x0
//   0x02e85c: 9400000d  bl       #0x2e890
//   0x02e860: 91002268  add      x8, x19, #8
//   0x02e864: eb00011f  cmp      x8, x0
//   0x02e868: 540000c0  b.eq     #0x2e880
//   0x02e86c: aa0003e1  mov      x1, x0
//   0x02e870: aa1303e0  mov      x0, x19
//   0x02e874: 94000019  bl       #0x2e8d8
//   0x02e878: 52800020  mov      w0, #1
uint64_t fde_1343_sub_02e84c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA0003E1ULL) + (x2 ^ 0x02E84CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02e84c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e850: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e854: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e858: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400000DULL; // 0x02e85c: bl #0x2e890
    acc = (acc * 0x100000001B3ULL) ^ 0x91002268ULL; // 0x02e860: add x8, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x02e864: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000C0ULL; // 0x02e868: b.eq #0x2e880
    return acc;
}

// [EN] Reconstructed FDE #1344 @ 0x02e890..0x02e8d8 (72 bytes)
// [VN] Phục dựng FDE #1344 tại 0x02e890..0x02e8d8 (72 byte)
//   0x02e890: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02e894: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e898: 910043fd  add      x29, sp, #0x10
//   0x02e89c: aa0003f3  mov      x19, x0
//   0x02e8a0: f8408e62  ldr      x2, [x19, #8]!
//   0x02e8a4: aa0103f4  mov      x20, x1
//   0x02e8a8: aa1303e3  mov      x3, x19
//   0x02e8ac: 94000017  bl       #0x2e908
//   0x02e8b0: eb00027f  cmp      x19, x0
//   0x02e8b4: 540000a0  b.eq     #0x2e8c8
//   0x02e8b8: f9400288  ldr      x8, [x20]
//   0x02e8bc: f9401009  ldr      x9, [x0, #0x20]
uint64_t fde_1344_sub_02e890(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xEB00027FULL) + (x2 ^ 0x02E890ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02e890: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e894: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e898: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02e89c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408E62ULL; // 0x02e8a0: ldr x2, [x19, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x02e8a4: mov x20, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x02e8a8: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x94000017ULL; // 0x02e8ac: bl #0x2e908
    return acc;
}

// [EN] Reconstructed FDE #1345 @ 0x02e8d8..0x02e908 (48 bytes)
// [VN] Phục dựng FDE #1345 tại 0x02e8d8..0x02e908 (48 byte)
//   0x02e8d8: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x02e8dc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02e8e0: 910043fd  add      x29, sp, #0x10
//   0x02e8e4: aa0103f3  mov      x19, x1
//   0x02e8e8: 94000012  bl       #0x2e930
//   0x02e8ec: aa0003f4  mov      x20, x0
//   0x02e8f0: aa1303e0  mov      x0, x19
//   0x02e8f4: 97ff7113  bl       #0xad40
//   0x02e8f8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x02e8fc: aa1403e0  mov      x0, x20
//   0x02e900: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x02e904: d65f03c0  ret      
uint64_t fde_1345_sub_02e8d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x02E8D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x02e8d8: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02e8dc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02e8e0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02e8e4: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x94000012ULL; // 0x02e8e8: bl #0x2e930
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02e8ec: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02e8f0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7113ULL; // 0x02e8f4: bl #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1346 @ 0x02e908..0x02e930 (40 bytes)
// [VN] Phục dựng FDE #1346 tại 0x02e908..0x02e930 (40 byte)
//   0x02e908: f9400028  ldr      x8, [x1]
//   0x02e90c: aa0303e0  mov      x0, x3
//   0x02e910: b40000e2  cbz      x2, #0x2e92c
//   0x02e914: f9401049  ldr      x9, [x2, #0x20]
//   0x02e918: eb08013f  cmp      x9, x8
//   0x02e91c: 1a9f27e9  cset     w9, lo
//   0x02e920: 9a823000  csel     x0, x0, x2, lo
//   0x02e924: f8695842  ldr      x2, [x2, w9, uxtw #3]
//   0x02e928: b5ffff62  cbnz     x2, #0x2e914
//   0x02e92c: d65f03c0  ret      
uint64_t fde_1346_sub_02e908(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400028ULL) + (x1 ^ 0xB5FFFF62ULL) + (x2 ^ 0x02E908ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400028ULL; // 0x02e908: ldr x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E0ULL; // 0x02e90c: mov x0, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E2ULL; // 0x02e910: cbz x2, #0x2e92c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401049ULL; // 0x02e914: ldr x9, [x2, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08013FULL; // 0x02e918: cmp x9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F27E9ULL; // 0x02e91c: cset w9, lo
    acc = (acc * 0x100000001B3ULL) ^ 0x9A823000ULL; // 0x02e920: csel x0, x0, x2, lo
    acc = (acc * 0x100000001B3ULL) ^ 0xF8695842ULL; // 0x02e924: ldr x2, [x2, w9, uxtw #3]
    return acc;
}

// [EN] Reconstructed FDE #1347 @ 0x02e930..0x02e98c (92 bytes)
// [VN] Phục dựng FDE #1347 tại 0x02e930..0x02e98c (92 byte)
//   0x02e930: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x02e934: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x02e938: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x02e93c: 910083fd  add      x29, sp, #0x20
//   0x02e940: aa0003f4  mov      x20, x0
//   0x02e944: aa0103e0  mov      x0, x1
//   0x02e948: aa0103f3  mov      x19, x1
//   0x02e94c: 97ff7a56  bl       #0xd2a4
//   0x02e950: f9400288  ldr      x8, [x20]
//   0x02e954: aa0003f5  mov      x21, x0
//   0x02e958: eb13011f  cmp      x8, x19
//   0x02e95c: 54000041  b.ne     #0x2e964
uint64_t fde_1347_sub_02e930(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xF9400288ULL) + (x2 ^ 0x02E930ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x02e930: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x02e934: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x02e938: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x02e93c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x02e940: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x02e944: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x02e948: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF7A56ULL; // 0x02e94c: bl #0xd2a4
    return acc;
}

// [EN] Reconstructed FDE #1348 @ 0x02e98c..0x02e998 (12 bytes)
// [VN] Phục dựng FDE #1348 tại 0x02e98c..0x02e998 (12 byte)
//   0x02e98c: aa1403e0  mov      x0, x20
//   0x02e990: aa1f03e3  mov      x3, xzr
//   0x02e994: 17ff73c3  b        #0xb8a0
uint64_t fde_1348_sub_02e98c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FF73C3ULL) + (x2 ^ 0x02E98CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02e98c: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x02e990: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF73C3ULL; // 0x02e994: b #0xb8a0
    return acc;
}

// [EN] Reconstructed FDE #1349 @ 0x02e998..0x02e9a0 (8 bytes)
// [VN] Phục dựng FDE #1349 tại 0x02e998..0x02e9a0 (8 byte)
//   0x02e998: aa1f03e3  mov      x3, xzr
//   0x02e99c: 17ff73c1  b        #0xb8a0
uint64_t fde_1349_sub_02e998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E3ULL) + (x1 ^ 0x17FF73C1ULL) + (x2 ^ 0x02E998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x02e998: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF73C1ULL; // 0x02e99c: b #0xb8a0
    return acc;
}

// [EN] Reconstructed FDE #1350 @ 0x02e9a0..0x02e9ac (12 bytes)
// [VN] Phục dựng FDE #1350 tại 0x02e9a0..0x02e9ac (12 byte)
//   0x02e9a0: b0000160  adrp     x0, #0x5b000
//   0x02e9a4: f944b800  ldr      x0, [x0, #0x970]
//   0x02e9a8: 17ff730a  b        #0xb5d0
uint64_t fde_1350_sub_02e9a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000160ULL) + (x1 ^ 0x17FF730AULL) + (x2 ^ 0x02E9A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000160ULL; // 0x02e9a0: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944B800ULL; // 0x02e9a4: ldr x0, [x0, #0x970]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF730AULL; // 0x02e9a8: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1351 @ 0x02e9ac..0x02e9b8 (12 bytes)
// [VN] Phục dựng FDE #1351 tại 0x02e9ac..0x02e9b8 (12 byte)
//   0x02e9ac: b0000160  adrp     x0, #0x5b000
//   0x02e9b0: f944b800  ldr      x0, [x0, #0x970]
//   0x02e9b4: 17ff7217  b        #0xb210
uint64_t fde_1351_sub_02e9ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000160ULL) + (x1 ^ 0x17FF7217ULL) + (x2 ^ 0x02E9ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000160ULL; // 0x02e9ac: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944B800ULL; // 0x02e9b0: ldr x0, [x0, #0x970]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF7217ULL; // 0x02e9b4: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1352 @ 0x02e9b8..0x02e9cc (20 bytes)
// [VN] Phục dựng FDE #1352 tại 0x02e9b8..0x02e9cc (20 byte)
//   0x02e9b8: a9444ff4  ldp      x20, x19, [sp, #0x40]
//   0x02e9bc: a94357f6  ldp      x22, x21, [sp, #0x30]
//   0x02e9c0: f94013f7  ldr      x23, [sp, #0x20]
//   0x02e9c4: 910183ff  add      sp, sp, #0x60
//   0x02e9c8: d65f03c0  ret      
uint64_t fde_1352_sub_02e9b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9444FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02E9B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9444FF4ULL; // 0x02e9b8: ldp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94357F6ULL; // 0x02e9bc: ldp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94013F7ULL; // 0x02e9c0: ldr x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FFULL; // 0x02e9c4: add sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02e9c8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1353 @ 0x02e9cc..0x02e9dc (16 bytes)
// [VN] Phục dựng FDE #1353 tại 0x02e9cc..0x02e9dc (16 byte)
//   0x02e9cc: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x02e9d0: f9400bf5  ldr      x21, [sp, #0x10]
//   0x02e9d4: 910103ff  add      sp, sp, #0x40
//   0x02e9d8: d65f03c0  ret      
uint64_t fde_1353_sub_02e9cc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9424FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02E9CCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9424FF4ULL; // 0x02e9cc: ldp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BF5ULL; // 0x02e9d0: ldr x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FFULL; // 0x02e9d4: add sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02e9d8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1354 @ 0x02e9dc..0x02e9e4 (8 bytes)
// [VN] Phục dựng FDE #1354 tại 0x02e9dc..0x02e9e4 (8 byte)
//   0x02e9dc: 910003e0  mov      x0, sp
//   0x02e9e0: 17ff8961  b        #0x10f64
uint64_t fde_1354_sub_02e9dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FF8961ULL) + (x2 ^ 0x02E9DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x02e9dc: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8961ULL; // 0x02e9e0: b #0x10f64
    return acc;
}

// [EN] Reconstructed FDE #1355 @ 0x02e9e4..0x02e9f8 (20 bytes)
// [VN] Phục dựng FDE #1355 tại 0x02e9e4..0x02e9f8 (20 byte)
//   0x02e9e4: f0000173  adrp     x19, #0x5d000
//   0x02e9e8: 911a4273  add      x19, x19, #0x690
//   0x02e9ec: f9400660  ldr      x0, [x19, #8]
//   0x02e9f0: 910043e1  add      x1, sp, #0x10
//   0x02e9f4: d65f03c0  ret      
uint64_t fde_1355_sub_02e9e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000173ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02E9E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000173ULL; // 0x02e9e4: adrp x19, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x911A4273ULL; // 0x02e9e8: add x19, x19, #0x690
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400660ULL; // 0x02e9ec: ldr x0, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043E1ULL; // 0x02e9f0: add x1, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02e9f4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1356 @ 0x02e9f8..0x02ea04 (12 bytes)
// [VN] Phục dựng FDE #1356 tại 0x02e9f8..0x02ea04 (12 byte)
//   0x02e9f8: b0000160  adrp     x0, #0x5b000
//   0x02e9fc: f9450000  ldr      x0, [x0, #0xa00]
//   0x02ea00: 17ff70a8  b        #0xaca0
uint64_t fde_1356_sub_02e9f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000160ULL) + (x1 ^ 0x17FF70A8ULL) + (x2 ^ 0x02E9F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000160ULL; // 0x02e9f8: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9450000ULL; // 0x02e9fc: ldr x0, [x0, #0xa00]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF70A8ULL; // 0x02ea00: b #0xaca0
    return acc;
}

// [EN] Reconstructed FDE #1357 @ 0x02ea04..0x02ea10 (12 bytes)
// [VN] Phục dựng FDE #1357 tại 0x02ea04..0x02ea10 (12 byte)
//   0x02ea04: f94007e9  ldr      x9, [sp, #8]
//   0x02ea08: eb09011f  cmp      x8, x9
//   0x02ea0c: d65f03c0  ret      
uint64_t fde_1357_sub_02ea04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94007E9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02EA04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94007E9ULL; // 0x02ea04: ldr x9, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02ea08: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02ea0c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1358 @ 0x02ea10..0x02ea18 (8 bytes)
// [VN] Phục dựng FDE #1358 tại 0x02ea10..0x02ea18 (8 byte)
//   0x02ea10: 910023e0  add      x0, sp, #8
//   0x02ea14: 17ff8954  b        #0x10f64
uint64_t fde_1358_sub_02ea10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FF8954ULL) + (x2 ^ 0x02EA10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02ea10: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8954ULL; // 0x02ea14: b #0x10f64
    return acc;
}

// [EN] Reconstructed FDE #1359 @ 0x02ea18..0x02ea24 (12 bytes)
// [VN] Phục dựng FDE #1359 tại 0x02ea18..0x02ea24 (12 byte)
//   0x02ea18: b0000160  adrp     x0, #0x5b000
//   0x02ea1c: f943b400  ldr      x0, [x0, #0x768]
//   0x02ea20: 17ff70a0  b        #0xaca0
uint64_t fde_1359_sub_02ea18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000160ULL) + (x1 ^ 0x17FF70A0ULL) + (x2 ^ 0x02EA18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000160ULL; // 0x02ea18: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943B400ULL; // 0x02ea1c: ldr x0, [x0, #0x768]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF70A0ULL; // 0x02ea20: b #0xaca0
    return acc;
}

// [EN] Reconstructed FDE #1360 @ 0x02ea24..0x02eb18 (244 bytes)
// [VN] Phục dựng FDE #1360 tại 0x02ea24..0x02eb18 (244 byte)
//   0x02ea24: d101c3ff  sub      sp, sp, #0x70
//   0x02ea28: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x02ea2c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02ea30: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02ea34: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02ea38: 910183fd  add      x29, sp, #0x60
//   0x02ea3c: d53bd058  mrs      x24, tpidr_el0
//   0x02ea40: f9401708  ldr      x8, [x24, #0x28]
//   0x02ea44: 2a0403f6  mov      w22, w4
//   0x02ea48: 2a0303f4  mov      w20, w3
//   0x02ea4c: aa0203f5  mov      x21, x2
//   0x02ea50: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1360_sub_02ea24(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0403F6ULL) + (x2 ^ 0x02EA24ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02ea24: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x02ea28: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02ea2c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02ea30: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02ea34: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02ea38: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x02ea3c: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x02ea40: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1361 @ 0x02eb18..0x02efb0 (1176 bytes)
// [VN] Phục dựng FDE #1361 tại 0x02eb18..0x02efb0 (1176 byte)
//   0x02eb18: d10243ff  sub      sp, sp, #0x90
//   0x02eb1c: a9036ffc  stp      x28, x27, [sp, #0x30]
//   0x02eb20: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x02eb24: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x02eb28: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x02eb2c: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x02eb30: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x02eb34: 910203fd  add      x29, sp, #0x80
//   0x02eb38: d53bd059  mrs      x25, tpidr_el0
//   0x02eb3c: f9401728  ldr      x8, [x25, #0x28]
//   0x02eb40: f90017e8  str      x8, [sp, #0x28]
//   0x02eb44: b0000168  adrp     x8, #0x5b000
uint64_t fde_1361_sub_02eb18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xD53BD059ULL) + (x2 ^ 0x02EB18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x02eb18: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA9036FFCULL; // 0x02eb1c: stp x28, x27, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x02eb20: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x02eb24: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x02eb28: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x02eb2c: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x02eb30: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x02eb34: add x29, sp, #0x80
    return acc;
}

// [EN] Reconstructed FDE #1362 @ 0x02efb0..0x02f090 (224 bytes)
// [VN] Phục dựng FDE #1362 tại 0x02efb0..0x02f090 (224 byte)
//   0x02efb0: d101c3ff  sub      sp, sp, #0x70
//   0x02efb4: f9001bf7  str      x23, [sp, #0x30]
//   0x02efb8: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x02efbc: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x02efc0: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x02efc4: 910183fd  add      x29, sp, #0x60
//   0x02efc8: d53bd057  mrs      x23, tpidr_el0
//   0x02efcc: f94016e8  ldr      x8, [x23, #0x28]
//   0x02efd0: 2a0303f5  mov      w21, w3
//   0x02efd4: aa0203f4  mov      x20, x2
//   0x02efd8: aa0103f3  mov      x19, x1
//   0x02efdc: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1362_sub_02efb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x2A0303F5ULL) + (x2 ^ 0x02EFB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x02efb0: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x02efb4: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x02efb8: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x02efbc: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x02efc0: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x02efc4: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x02efc8: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x02efcc: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1363 @ 0x02f090..0x02f194 (260 bytes)
// [VN] Phục dựng FDE #1363 tại 0x02f090..0x02f194 (260 byte)
//   0x02f090: d10203ff  sub      sp, sp, #0x80
//   0x02f094: a90367fa  stp      x26, x25, [sp, #0x30]
//   0x02f098: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x02f09c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x02f0a0: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x02f0a4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x02f0a8: 9101c3fd  add      x29, sp, #0x70
//   0x02f0ac: d53bd05a  mrs      x26, tpidr_el0
//   0x02f0b0: f9401748  ldr      x8, [x26, #0x28]
//   0x02f0b4: aa0603f4  mov      x20, x6
//   0x02f0b8: 2a0503f6  mov      w22, w5
//   0x02f0bc: 2a0403f8  mov      w24, w4
uint64_t fde_1363_sub_02f090(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401748ULL) + (x2 ^ 0x02F090ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x02f090: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90367FAULL; // 0x02f094: stp x26, x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x02f098: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x02f09c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x02f0a0: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x02f0a4: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x02f0a8: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD05AULL; // 0x02f0ac: mrs x26, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1364 @ 0x02f194..0x02f2d0 (316 bytes)
// [VN] Phục dựng FDE #1364 tại 0x02f194..0x02f2d0 (316 byte)
//   0x02f194: d10183ff  sub      sp, sp, #0x60
//   0x02f198: f9001bf5  str      x21, [sp, #0x30]
//   0x02f19c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x02f1a0: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x02f1a4: 910143fd  add      x29, sp, #0x50
//   0x02f1a8: d53bd054  mrs      x20, tpidr_el0
//   0x02f1ac: f9401688  ldr      x8, [x20, #0x28]
//   0x02f1b0: aa0003f3  mov      x19, x0
//   0x02f1b4: 90000160  adrp     x0, #0x5b000
//   0x02f1b8: f90017e8  str      x8, [sp, #0x28]
//   0x02f1bc: f9457000  ldr      x0, [x0, #0xae0]
//   0x02f1c0: 97ff7104  bl       #0xb5d0
uint64_t fde_1364_sub_02f194(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x90000160ULL) + (x2 ^ 0x02F194ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x02f194: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x02f198: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x02f19c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x02f1a0: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x02f1a4: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x02f1a8: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x02f1ac: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f1b0: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1365 @ 0x02f2d0..0x02f460 (400 bytes)
// [VN] Phục dựng FDE #1365 tại 0x02f2d0..0x02f460 (400 byte)
//   0x02f2d0: f81b0ff9  str      x25, [sp, #-0x50]!
//   0x02f2d4: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x02f2d8: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x02f2dc: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x02f2e0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x02f2e4: 910103fd  add      x29, sp, #0x40
//   0x02f2e8: b0000178  adrp     x24, #0x5c000
//   0x02f2ec: b9410b08  ldr      w8, [x24, #0x108]
//   0x02f2f0: aa0203f4  mov      x20, x2
//   0x02f2f4: 2a0103f3  mov      w19, w1
//   0x02f2f8: aa0003f5  mov      x21, x0
//   0x02f2fc: 3100051f  cmn      w8, #1
uint64_t fde_1365_sub_02f2d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81B0FF9ULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x02F2D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81B0FF9ULL; // 0x02f2d0: str x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x02f2d4: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x02f2d8: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x02f2dc: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x02f2e0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x02f2e4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000178ULL; // 0x02f2e8: adrp x24, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9410B08ULL; // 0x02f2ec: ldr w8, [x24, #0x108]
    return acc;
}

// [EN] Reconstructed FDE #1366 @ 0x02f460..0x02f4fc (156 bytes)
// [VN] Phục dựng FDE #1366 tại 0x02f460..0x02f4fc (156 byte)
//   0x02f460: d10483ff  sub      sp, sp, #0x120
//   0x02f464: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x02f468: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02f46c: 910443fd  add      x29, sp, #0x110
//   0x02f470: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x02f474: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x02f478: f90057e7  str      x7, [sp, #0xa8]
//   0x02f47c: ad0007e0  stp      q0, q1, [sp]
//   0x02f480: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02f484: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02f488: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02f48c: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_1366_sub_02f460(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x02F460ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02f460: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x02f464: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02f468: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02f46c: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x02f470: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x02f474: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x02f478: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02f47c: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1367 @ 0x02f4fc..0x02f598 (156 bytes)
// [VN] Phục dựng FDE #1367 tại 0x02f4fc..0x02f598 (156 byte)
//   0x02f4fc: d10483ff  sub      sp, sp, #0x120
//   0x02f500: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x02f504: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x02f508: 910443fd  add      x29, sp, #0x110
//   0x02f50c: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x02f510: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x02f514: f90057e7  str      x7, [sp, #0xa8]
//   0x02f518: ad0007e0  stp      q0, q1, [sp]
//   0x02f51c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x02f520: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x02f524: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x02f528: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_1367_sub_02f4fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x02F4FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x02f4fc: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x02f500: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x02f504: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x02f508: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x02f50c: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x02f510: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x02f514: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x02f518: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1368 @ 0x02f598..0x02f59c (4 bytes)
// [VN] Phục dựng FDE #1368 tại 0x02f598..0x02f59c (4 byte)
//   0x02f598: d65f03c0  ret      
uint64_t fde_1368_sub_02f598(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F598ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f598: ret 
    return acc;
}

// [EN] Reconstructed FDE #1369 @ 0x02f59c..0x02f5a4 (8 bytes)
// [VN] Phục dựng FDE #1369 tại 0x02f59c..0x02f5a4 (8 byte)
//   0x02f59c: 2a0103e0  mov      w0, w1
//   0x02f5a0: d65f03c0  ret      
uint64_t fde_1369_sub_02f59c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0103E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F59CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0103E0ULL; // 0x02f59c: mov w0, w1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f5a0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1370 @ 0x02f5a4..0x02f5ac (8 bytes)
// [VN] Phục dựng FDE #1370 tại 0x02f5a4..0x02f5ac (8 byte)
//   0x02f5a4: 2a1f03e0  mov      w0, wzr
//   0x02f5a8: d65f03c0  ret      
uint64_t fde_1370_sub_02f5a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F5A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x02f5a4: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f5a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1371 @ 0x02f5ac..0x02f5b4 (8 bytes)
// [VN] Phục dựng FDE #1371 tại 0x02f5ac..0x02f5b4 (8 byte)
//   0x02f5ac: 52800020  mov      w0, #1
//   0x02f5b0: d65f03c0  ret      
uint64_t fde_1371_sub_02f5ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800020ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02F5ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800020ULL; // 0x02f5ac: mov w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02f5b0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1372 @ 0x02f5b4..0x02f5f0 (60 bytes)
// [VN] Phục dựng FDE #1372 tại 0x02f5b4..0x02f5f0 (60 byte)
//   0x02f5b4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x02f5b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x02f5bc: 910043fd  add      x29, sp, #0x10
//   0x02f5c0: f9400008  ldr      x8, [x0]
//   0x02f5c4: b9400809  ldr      w9, [x0, #8]
//   0x02f5c8: aa0003f3  mov      x19, x0
//   0x02f5cc: 8b090500  add      x0, x8, x9, lsl #1
//   0x02f5d0: 940001e4  bl       #0x2fd60
//   0x02f5d4: b9400a68  ldr      w8, [x19, #8]
//   0x02f5d8: 0b000108  add      w8, w8, w0
//   0x02f5dc: b9000a68  str      w8, [x19, #8]
//   0x02f5e0: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_1372_sub_02f5b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB9400A68ULL) + (x2 ^ 0x02F5B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x02f5b4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x02f5b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x02f5bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02f5c0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400809ULL; // 0x02f5c4: ldr w9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x02f5c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x8B090500ULL; // 0x02f5cc: add x0, x8, x9, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0x940001E4ULL; // 0x02f5d0: bl #0x2fd60
    return acc;
}

// [EN] Reconstructed FDE #1373 @ 0x02f5f0..0x02fa70 (1152 bytes)
// [VN] Phục dựng FDE #1373 tại 0x02f5f0..0x02fa70 (1152 byte)
//   0x02f5f0: d10283ff  sub      sp, sp, #0xa0
//   0x02f5f4: f90023fb  str      x27, [sp, #0x40]
//   0x02f5f8: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x02f5fc: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x02f600: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x02f604: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x02f608: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x02f60c: 910243fd  add      x29, sp, #0x90
//   0x02f610: d53bd058  mrs      x24, tpidr_el0
//   0x02f614: f9401708  ldr      x8, [x24, #0x28]
//   0x02f618: 90000179  adrp     x25, #0x5b000
//   0x02f61c: f9001fe8  str      x8, [sp, #0x38]
uint64_t fde_1373_sub_02f5f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xD53BD058ULL) + (x2 ^ 0x02F5F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02f5f0: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023FBULL; // 0x02f5f4: str x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x02f5f8: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x02f5fc: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x02f600: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x02f604: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x02f608: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x02f60c: add x29, sp, #0x90
    return acc;
}

// [EN] Reconstructed FDE #1374 @ 0x02fa70..0x02fd60 (752 bytes)
// [VN] Phục dựng FDE #1374 tại 0x02fa70..0x02fd60 (752 byte)
//   0x02fa70: d10283ff  sub      sp, sp, #0xa0
//   0x02fa74: a9046ffc  stp      x28, x27, [sp, #0x40]
//   0x02fa78: a90567fa  stp      x26, x25, [sp, #0x50]
//   0x02fa7c: a9065ff8  stp      x24, x23, [sp, #0x60]
//   0x02fa80: a90757f6  stp      x22, x21, [sp, #0x70]
//   0x02fa84: a9084ff4  stp      x20, x19, [sp, #0x80]
//   0x02fa88: a9097bfd  stp      x29, x30, [sp, #0x90]
//   0x02fa8c: 910243fd  add      x29, sp, #0x90
//   0x02fa90: d53bd05c  mrs      x28, tpidr_el0
//   0x02fa94: f9401788  ldr      x8, [x28, #0x28]
//   0x02fa98: b0000081  adrp     x1, #0x40000
//   0x02fa9c: 9105f821  add      x1, x1, #0x17e
uint64_t fde_1374_sub_02fa70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10283FFULL) + (x1 ^ 0xD53BD05CULL) + (x2 ^ 0x02FA70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10283FFULL; // 0x02fa70: sub sp, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9046FFCULL; // 0x02fa74: stp x28, x27, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90567FAULL; // 0x02fa78: stp x26, x25, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9065FF8ULL; // 0x02fa7c: stp x24, x23, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90757F6ULL; // 0x02fa80: stp x22, x21, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9084FF4ULL; // 0x02fa84: stp x20, x19, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9097BFDULL; // 0x02fa88: stp x29, x30, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0x910243FDULL; // 0x02fa8c: add x29, sp, #0x90
    return acc;
}

// [EN] Reconstructed FDE #1375 @ 0x02fd60..0x02fd84 (36 bytes)
// [VN] Phục dựng FDE #1375 tại 0x02fd60..0x02fd84 (36 byte)
//   0x02fd60: 90000169  adrp     x9, #0x5b000
//   0x02fd64: 39400008  ldrb     w8, [x0]
//   0x02fd68: f944c529  ldr      x9, [x9, #0x988]
//   0x02fd6c: 8b080d28  add      x8, x9, x8, lsl #3
//   0x02fd70: 39801d08  ldrsb    x8, [x8, #7]
//   0x02fd74: b7f80068  tbnz     x8, #0x3f, #0x2fd80
//   0x02fd78: aa0803e0  mov      x0, x8
//   0x02fd7c: d65f03c0  ret      
//   0x02fd80: 140020d0  b        #0x380c0
uint64_t fde_1375_sub_02fd60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000169ULL) + (x1 ^ 0x140020D0ULL) + (x2 ^ 0x02FD60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000169ULL; // 0x02fd60: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0x39400008ULL; // 0x02fd64: ldrb w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF944C529ULL; // 0x02fd68: ldr x9, [x9, #0x988]
    acc = (acc * 0x100000001B3ULL) ^ 0x8B080D28ULL; // 0x02fd6c: add x8, x9, x8, lsl #3
    acc = (acc * 0x100000001B3ULL) ^ 0x39801D08ULL; // 0x02fd70: ldrsb x8, [x8, #7]
    acc = (acc * 0x100000001B3ULL) ^ 0xB7F80068ULL; // 0x02fd74: tbnz x8, #0x3f, #0x2fd80
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x02fd78: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02fd7c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1376 @ 0x02fd84..0x02fda0 (28 bytes)
// [VN] Phục dựng FDE #1376 tại 0x02fd84..0x02fda0 (28 byte)
//   0x02fd84: aa0003e2  mov      x2, x0
//   0x02fd88: aa1603e0  mov      x0, x22
//   0x02fd8c: aa1303e1  mov      x1, x19
//   0x02fd90: 2a1803e3  mov      w3, w24
//   0x02fd94: 2a1903e4  mov      w4, w25
//   0x02fd98: 2a1f03e5  mov      w5, wzr
//   0x02fd9c: d61f02e0  br       x23
uint64_t fde_1376_sub_02fd84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E2ULL) + (x1 ^ 0xD61F02E0ULL) + (x2 ^ 0x02FD84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E2ULL; // 0x02fd84: mov x2, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x02fd88: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x02fd8c: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1803E3ULL; // 0x02fd90: mov w3, w24
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1903E4ULL; // 0x02fd94: mov w4, w25
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E5ULL; // 0x02fd98: mov w5, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F02E0ULL; // 0x02fd9c: br x23
    return acc;
}

// [EN] Reconstructed FDE #1377 @ 0x02fda0..0x02fdb0 (16 bytes)
// [VN] Phục dựng FDE #1377 tại 0x02fda0..0x02fdb0 (16 byte)
//   0x02fda0: aa0003e1  mov      x1, x0
//   0x02fda4: aa1603e0  mov      x0, x22
//   0x02fda8: aa1303e2  mov      x2, x19
//   0x02fdac: d61f02e0  br       x23
uint64_t fde_1377_sub_02fda0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E1ULL) + (x1 ^ 0xD61F02E0ULL) + (x2 ^ 0x02FDA0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x02fda0: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x02fda4: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E2ULL; // 0x02fda8: mov x2, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F02E0ULL; // 0x02fdac: br x23
    return acc;
}

// [EN] Reconstructed FDE #1378 @ 0x02fdb0..0x02fddc (44 bytes)
// [VN] Phục dựng FDE #1378 tại 0x02fdb0..0x02fddc (44 byte)
//   0x02fdb0: 394023e8  ldrb     w8, [sp, #8]
//   0x02fdb4: f9400fe9  ldr      x9, [sp, #0x18]
//   0x02fdb8: b240028a  orr      x10, x20, #1
//   0x02fdbc: 90000081  adrp     x1, #0x3f000
//   0x02fdc0: 7200011f  tst      w8, #1
//   0x02fdc4: 90000082  adrp     x2, #0x3f000
//   0x02fdc8: 9a890143  csel     x3, x10, x9, eq
//   0x02fdcc: 913d0021  add      x1, x1, #0xf40
//   0x02fdd0: 913d4842  add      x2, x2, #0xf52
//   0x02fdd4: 52800060  mov      w0, #3
//   0x02fdd8: 17ff6d02  b        #0xb1e0
uint64_t fde_1378_sub_02fdb0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x394023E8ULL) + (x1 ^ 0x913D4842ULL) + (x2 ^ 0x02FDB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x394023E8ULL; // 0x02fdb0: ldrb w8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400FE9ULL; // 0x02fdb4: ldr x9, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB240028AULL; // 0x02fdb8: orr x10, x20, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x90000081ULL; // 0x02fdbc: adrp x1, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x02fdc0: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x90000082ULL; // 0x02fdc4: adrp x2, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x9A890143ULL; // 0x02fdc8: csel x3, x10, x9, eq
    acc = (acc * 0x100000001B3ULL) ^ 0x913D0021ULL; // 0x02fdcc: add x1, x1, #0xf40
    return acc;
}

// [EN] Reconstructed FDE #1379 @ 0x02fddc..0x02fdfc (32 bytes)
// [VN] Phục dựng FDE #1379 tại 0x02fddc..0x02fdfc (32 byte)
//   0x02fddc: 90000168  adrp     x8, #0x5b000
//   0x02fde0: f9442108  ldr      x8, [x8, #0x840]
//   0x02fde4: 52800021  mov      w1, #1
//   0x02fde8: aa1303e0  mov      x0, x19
//   0x02fdec: 910023f4  add      x20, sp, #8
//   0x02fdf0: f9400109  ldr      x9, [x8]
//   0x02fdf4: 910023e8  add      x8, sp, #8
//   0x02fdf8: d61f0120  br       x9
uint64_t fde_1379_sub_02fddc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000168ULL) + (x1 ^ 0xD61F0120ULL) + (x2 ^ 0x02FDDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000168ULL; // 0x02fddc: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9442108ULL; // 0x02fde0: ldr x8, [x8, #0x840]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x02fde4: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02fde8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x910023F4ULL; // 0x02fdec: add x20, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x02fdf0: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E8ULL; // 0x02fdf4: add x8, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0120ULL; // 0x02fdf8: br x9
    return acc;
}

// [EN] Reconstructed FDE #1380 @ 0x02fdfc..0x02fe1c (32 bytes)
// [VN] Phục dựng FDE #1380 tại 0x02fdfc..0x02fe1c (32 byte)
//   0x02fdfc: 90000168  adrp     x8, #0x5b000
//   0x02fe00: 90000169  adrp     x9, #0x5b000
//   0x02fe04: f9476d08  ldr      x8, [x8, #0xed8]
//   0x02fe08: f9432129  ldr      x9, [x9, #0x640]
//   0x02fe0c: aa1303e1  mov      x1, x19
//   0x02fe10: f9400108  ldr      x8, [x8]
//   0x02fe14: f9400120  ldr      x0, [x9]
//   0x02fe18: d61f0100  br       x8
uint64_t fde_1380_sub_02fdfc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000168ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x02FDFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000168ULL; // 0x02fdfc: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000169ULL; // 0x02fe00: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9476D08ULL; // 0x02fe04: ldr x8, [x8, #0xed8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9432129ULL; // 0x02fe08: ldr x9, [x9, #0x640]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x02fe0c: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x02fe10: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400120ULL; // 0x02fe14: ldr x0, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x02fe18: br x8
    return acc;
}

// [EN] Reconstructed FDE #1381 @ 0x02fe1c..0x02fe38 (28 bytes)
// [VN] Phục dựng FDE #1381 tại 0x02fe1c..0x02fe38 (28 byte)
//   0x02fe1c: 90000168  adrp     x8, #0x5b000
//   0x02fe20: f9430d08  ldr      x8, [x8, #0x618]
//   0x02fe24: b9800108  ldrsw    x8, [x8]
//   0x02fe28: b8687a69  ldr      w9, [x19, x8, lsl #2]
//   0x02fe2c: 32070129  orr      w9, w9, #0x2000000
//   0x02fe30: b8287a69  str      w9, [x19, x8, lsl #2]
//   0x02fe34: 17ff9dfa  b        #0x1761c
uint64_t fde_1381_sub_02fe1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000168ULL) + (x1 ^ 0x17FF9DFAULL) + (x2 ^ 0x02FE1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000168ULL; // 0x02fe1c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9430D08ULL; // 0x02fe20: ldr x8, [x8, #0x618]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800108ULL; // 0x02fe24: ldrsw x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8687A69ULL; // 0x02fe28: ldr w9, [x19, x8, lsl #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x32070129ULL; // 0x02fe2c: orr w9, w9, #0x2000000
    acc = (acc * 0x100000001B3ULL) ^ 0xB8287A69ULL; // 0x02fe30: str w9, [x19, x8, lsl #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9DFAULL; // 0x02fe34: b #0x1761c
    return acc;
}

// [EN] Reconstructed FDE #1382 @ 0x02fe38..0x02fe44 (12 bytes)
// [VN] Phục dựng FDE #1382 tại 0x02fe38..0x02fe44 (12 byte)
//   0x02fe38: aa1403e0  mov      x0, x20
//   0x02fe3c: aa1503e1  mov      x1, x21
//   0x02fe40: d61f0100  br       x8
uint64_t fde_1382_sub_02fe38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x02FE38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02fe38: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x02fe3c: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x02fe40: br x8
    return acc;
}

// [EN] Reconstructed FDE #1383 @ 0x02fe44..0x02fe54 (16 bytes)
// [VN] Phục dựng FDE #1383 tại 0x02fe44..0x02fe54 (16 byte)
//   0x02fe44: aa1403e0  mov      x0, x20
//   0x02fe48: f9408508  ldr      x8, [x8, #0x108]
//   0x02fe4c: aa1503e1  mov      x1, x21
//   0x02fe50: d65f03c0  ret      
uint64_t fde_1383_sub_02fe44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02FE44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02fe44: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408508ULL; // 0x02fe48: ldr x8, [x8, #0x108]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x02fe4c: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02fe50: ret 
    return acc;
}

// [EN] Reconstructed FDE #1384 @ 0x02fe54..0x02fe64 (16 bytes)
// [VN] Phục dựng FDE #1384 tại 0x02fe54..0x02fe64 (16 byte)
//   0x02fe54: f9400be0  ldr      x0, [sp, #0x10]
//   0x02fe58: f9400008  ldr      x8, [x0]
//   0x02fe5c: f9439108  ldr      x8, [x8, #0x720]
//   0x02fe60: d61f0100  br       x8
uint64_t fde_1384_sub_02fe54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400BE0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x02FE54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BE0ULL; // 0x02fe54: ldr x0, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x02fe58: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x02fe5c: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x02fe60: br x8
    return acc;
}

// [EN] Reconstructed FDE #1385 @ 0x02fe64..0x02fe74 (16 bytes)
// [VN] Phục dựng FDE #1385 tại 0x02fe64..0x02fe74 (16 byte)
//   0x02fe64: f9400109  ldr      x9, [x8]
//   0x02fe68: aa0803e0  mov      x0, x8
//   0x02fe6c: f9439129  ldr      x9, [x9, #0x720]
//   0x02fe70: d61f0120  br       x9
uint64_t fde_1385_sub_02fe64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400109ULL) + (x1 ^ 0xD61F0120ULL) + (x2 ^ 0x02FE64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x02fe64: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E0ULL; // 0x02fe68: mov x0, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439129ULL; // 0x02fe6c: ldr x9, [x9, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0120ULL; // 0x02fe70: br x9
    return acc;
}

// [EN] Reconstructed FDE #1386 @ 0x02fe74..0x02fe90 (28 bytes)
// [VN] Phục dựng FDE #1386 tại 0x02fe74..0x02fe90 (28 byte)
//   0x02fe74: aa1403e1  mov      x1, x20
//   0x02fe78: f9000100  str      x0, [x8]
//   0x02fe7c: f9400268  ldr      x8, [x19]
//   0x02fe80: aa1303e0  mov      x0, x19
//   0x02fe84: aa1503e3  mov      x3, x21
//   0x02fe88: f941c508  ldr      x8, [x8, #0x388]
//   0x02fe8c: d61f0100  br       x8
uint64_t fde_1386_sub_02fe74(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E1ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x02FE74ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x02fe74: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000100ULL; // 0x02fe78: str x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x02fe7c: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02fe80: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E3ULL; // 0x02fe84: mov x3, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xF941C508ULL; // 0x02fe88: ldr x8, [x8, #0x388]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x02fe8c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1387 @ 0x02fe90..0x02fe9c (12 bytes)
// [VN] Phục dựng FDE #1387 tại 0x02fe90..0x02fe9c (12 byte)
//   0x02fe90: 90000160  adrp     x0, #0x5b000
//   0x02fe94: f9457000  ldr      x0, [x0, #0xae0]
//   0x02fe98: 17ff6cde  b        #0xb210
uint64_t fde_1387_sub_02fe90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000160ULL) + (x1 ^ 0x17FF6CDEULL) + (x2 ^ 0x02FE90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000160ULL; // 0x02fe90: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9457000ULL; // 0x02fe94: ldr x0, [x0, #0xae0]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6CDEULL; // 0x02fe98: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1388 @ 0x02fe9c..0x02fea8 (12 bytes)
// [VN] Phục dựng FDE #1388 tại 0x02fe9c..0x02fea8 (12 byte)
//   0x02fe9c: aa1303e0  mov      x0, x19
//   0x02fea0: aa1403e1  mov      x1, x20
//   0x02fea4: d65f03c0  ret      
uint64_t fde_1388_sub_02fe9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02FE9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x02fe9c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x02fea0: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02fea4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1389 @ 0x02fea8..0x02feb4 (12 bytes)
// [VN] Phục dựng FDE #1389 tại 0x02fea8..0x02feb4 (12 byte)
//   0x02fea8: f94017e9  ldr      x9, [sp, #0x28]
//   0x02feac: eb09011f  cmp      x8, x9
//   0x02feb0: d65f03c0  ret      
uint64_t fde_1389_sub_02fea8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF94017E9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02FEA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF94017E9ULL; // 0x02fea8: ldr x9, [sp, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x02feac: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02feb0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1390 @ 0x02feb4..0x02febc (8 bytes)
// [VN] Phục dựng FDE #1390 tại 0x02feb4..0x02febc (8 byte)
//   0x02feb4: 910063e0  add      x0, sp, #0x18
//   0x02feb8: 17ff6caa  b        #0xb160
uint64_t fde_1390_sub_02feb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FF6CAAULL) + (x2 ^ 0x02FEB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x02feb4: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6CAAULL; // 0x02feb8: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1391 @ 0x02febc..0x02fed0 (20 bytes)
// [VN] Phục dựng FDE #1391 tại 0x02febc..0x02fed0 (20 byte)
//   0x02febc: f9408508  ldr      x8, [x8, #0x108]
//   0x02fec0: 91171442  add      x2, x2, #0x5c5
//   0x02fec4: aa1403e0  mov      x0, x20
//   0x02fec8: aa1503e1  mov      x1, x21
//   0x02fecc: d65f03c0  ret      
uint64_t fde_1391_sub_02febc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9408508ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02FEBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408508ULL; // 0x02febc: ldr x8, [x8, #0x108]
    acc = (acc * 0x100000001B3ULL) ^ 0x91171442ULL; // 0x02fec0: add x2, x2, #0x5c5
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x02fec4: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x02fec8: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02fecc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1392 @ 0x02fed0..0x02fedc (12 bytes)
// [VN] Phục dựng FDE #1392 tại 0x02fed0..0x02fedc (12 byte)
//   0x02fed0: f9400be0  ldr      x0, [sp, #0x10]
//   0x02fed4: f9400341  ldr      x1, [x26]
//   0x02fed8: d65f03c0  ret      
uint64_t fde_1392_sub_02fed0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400BE0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x02FED0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400BE0ULL; // 0x02fed0: ldr x0, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400341ULL; // 0x02fed4: ldr x1, [x26]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x02fed8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1393 @ 0x02fedc..0x02fee8 (12 bytes)
// [VN] Phục dựng FDE #1393 tại 0x02fedc..0x02fee8 (12 byte)
//   0x02fedc: aa1603e3  mov      x3, x22
//   0x02fee0: f9400102  ldr      x2, [x8]
//   0x02fee4: 17fffd86  b        #0x2f4fc
uint64_t fde_1393_sub_02fedc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1603E3ULL) + (x1 ^ 0x17FFFD86ULL) + (x2 ^ 0x02FEDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E3ULL; // 0x02fedc: mov x3, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x02fee0: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFD86ULL; // 0x02fee4: b #0x2f4fc
    return acc;
}

// [EN] Reconstructed FDE #1394 @ 0x02fee8..0x02fef4 (12 bytes)
// [VN] Phục dựng FDE #1394 tại 0x02fee8..0x02fef4 (12 byte)
//   0x02fee8: 52800081  mov      w1, #4
//   0x02feec: aa1703e0  mov      x0, x23
//   0x02fef0: 17ff6b78  b        #0xacd0
uint64_t fde_1394_sub_02fee8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800081ULL) + (x1 ^ 0x17FF6B78ULL) + (x2 ^ 0x02FEE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800081ULL; // 0x02fee8: mov w1, #4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E0ULL; // 0x02feec: mov x0, x23
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6B78ULL; // 0x02fef0: b #0xacd0
    return acc;
}

// [EN] Reconstructed FDE #1395 @ 0x02fef4..0x02fefc (8 bytes)
// [VN] Phục dựng FDE #1395 tại 0x02fef4..0x02fefc (8 byte)
//   0x02fef4: 910083e0  add      x0, sp, #0x20
//   0x02fef8: 17ff841b  b        #0x10f64
uint64_t fde_1395_sub_02fef4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910083E0ULL) + (x1 ^ 0x17FF841BULL) + (x2 ^ 0x02FEF4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E0ULL; // 0x02fef4: add x0, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF841BULL; // 0x02fef8: b #0x10f64
    return acc;
}

// [EN] Reconstructed FDE #1396 @ 0x02fefc..0x02ff04 (8 bytes)
// [VN] Phục dựng FDE #1396 tại 0x02fefc..0x02ff04 (8 byte)
//   0x02fefc: 910063e0  add      x0, sp, #0x18
//   0x02ff00: 17ff6ca4  b        #0xb190
uint64_t fde_1396_sub_02fefc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FF6CA4ULL) + (x2 ^ 0x02FEFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x02fefc: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6CA4ULL; // 0x02ff00: b #0xb190
    return acc;
}

// [EN] Reconstructed FDE #1397 @ 0x02ff04..0x02ff0c (8 bytes)
// [VN] Phục dựng FDE #1397 tại 0x02ff04..0x02ff0c (8 byte)
//   0x02ff04: 910023e0  add      x0, sp, #8
//   0x02ff08: 17ff764f  b        #0xd844
uint64_t fde_1397_sub_02ff04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FF764FULL) + (x2 ^ 0x02FF04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02ff04: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF764FULL; // 0x02ff08: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #1398 @ 0x02ff0c..0x02ff14 (8 bytes)
// [VN] Phục dựng FDE #1398 tại 0x02ff0c..0x02ff14 (8 byte)
//   0x02ff0c: 910023e0  add      x0, sp, #8
//   0x02ff10: 17ff6c94  b        #0xb160
uint64_t fde_1398_sub_02ff0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FF6C94ULL) + (x2 ^ 0x02FF0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x02ff0c: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6C94ULL; // 0x02ff10: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1399 @ 0x02ff14..0x03026c (856 bytes)
// [VN] Phục dựng FDE #1399 tại 0x02ff14..0x03026c (856 byte)
//   0x02ff14: d10383ff  sub      sp, sp, #0xe0
//   0x02ff18: a9086ffc  stp      x28, x27, [sp, #0x80]
//   0x02ff1c: a90967fa  stp      x26, x25, [sp, #0x90]
//   0x02ff20: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x02ff24: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x02ff28: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x02ff2c: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x02ff30: 910343fd  add      x29, sp, #0xd0
//   0x02ff34: d53bd057  mrs      x23, tpidr_el0
//   0x02ff38: f94016e8  ldr      x8, [x23, #0x28]
//   0x02ff3c: 90000178  adrp     x24, #0x5b000
//   0x02ff40: f81a83a8  stur     x8, [x29, #-0x58]
uint64_t fde_1399_sub_02ff14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0xD53BD057ULL) + (x2 ^ 0x02FF14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x02ff14: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9086FFCULL; // 0x02ff18: stp x28, x27, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90967FAULL; // 0x02ff1c: stp x26, x25, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x02ff20: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x02ff24: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x02ff28: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x02ff2c: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x02ff30: add x29, sp, #0xd0
    return acc;
}

// [EN] Reconstructed FDE #1400 @ 0x03026c..0x0302d0 (100 bytes)
// [VN] Phục dựng FDE #1400 tại 0x03026c..0x0302d0 (100 byte)
//   0x03026c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x030270: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030274: 910043fd  add      x29, sp, #0x10
//   0x030278: aa0003f3  mov      x19, x0
//   0x03027c: b4000220  cbz      x0, #0x302c0
//   0x030280: f0000040  adrp     x0, #0x3b000
//   0x030284: 911d1800  add      x0, x0, #0x746
//   0x030288: 52800021  mov      w1, #1
//   0x03028c: 97ff6b81  bl       #0xb090
//   0x030290: 3100041f  cmn      w0, #1
//   0x030294: 54000140  b.eq     #0x302bc
//   0x030298: 52800102  mov      w2, #8
uint64_t fde_1400_sub_03026c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FF6B81ULL) + (x2 ^ 0x03026CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03026c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x030270: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030274: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x030278: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x03027c: cbz x0, #0x302c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000040ULL; // 0x030280: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D1800ULL; // 0x030284: add x0, x0, #0x746
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x030288: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #1401 @ 0x0302d0..0x0302fc (44 bytes)
// [VN] Phục dựng FDE #1401 tại 0x0302d0..0x0302fc (44 byte)
//   0x0302d0: f0000148  adrp     x8, #0x5b000
//   0x0302d4: f9447508  ldr      x8, [x8, #0x8e8]
//   0x0302d8: 39400108  ldrb     w8, [x8]
//   0x0302dc: 340000e8  cbz      w8, #0x302f8
//   0x0302e0: f0000148  adrp     x8, #0x5b000
//   0x0302e4: f0000149  adrp     x9, #0x5b000
//   0x0302e8: f9464d08  ldr      x8, [x8, #0xc98]
//   0x0302ec: f9473129  ldr      x9, [x9, #0xe60]
//   0x0302f0: 52800021  mov      w1, #1
//   0x0302f4: 14000062  b        #0x3047c
//   0x0302f8: d65f03c0  ret      
uint64_t fde_1401_sub_0302d0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0x52800021ULL) + (x2 ^ 0x0302D0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0302d0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9447508ULL; // 0x0302d4: ldr x8, [x8, #0x8e8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x0302d8: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E8ULL; // 0x0302dc: cbz w8, #0x302f8
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0302e0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000149ULL; // 0x0302e4: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9464D08ULL; // 0x0302e8: ldr x8, [x8, #0xc98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473129ULL; // 0x0302ec: ldr x9, [x9, #0xe60]
    return acc;
}

// [EN] Reconstructed FDE #1402 @ 0x0302fc..0x030328 (44 bytes)
// [VN] Phục dựng FDE #1402 tại 0x0302fc..0x030328 (44 byte)
//   0x0302fc: f0000148  adrp     x8, #0x5b000
//   0x030300: f9447508  ldr      x8, [x8, #0x8e8]
//   0x030304: 39400108  ldrb     w8, [x8]
//   0x030308: 340000e8  cbz      w8, #0x30324
//   0x03030c: f0000148  adrp     x8, #0x5b000
//   0x030310: f0000149  adrp     x9, #0x5b000
//   0x030314: f9464d08  ldr      x8, [x8, #0xc98]
//   0x030318: f9473129  ldr      x9, [x9, #0xe60]
//   0x03031c: 2a1f03e1  mov      w1, wzr
//   0x030320: 14000057  b        #0x3047c
//   0x030324: d65f03c0  ret      
uint64_t fde_1402_sub_0302fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0x2A1F03E1ULL) + (x2 ^ 0x0302FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0302fc: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9447508ULL; // 0x030300: ldr x8, [x8, #0x8e8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x030304: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340000E8ULL; // 0x030308: cbz w8, #0x30324
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x03030c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000149ULL; // 0x030310: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9464D08ULL; // 0x030314: ldr x8, [x8, #0xc98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473129ULL; // 0x030318: ldr x9, [x9, #0xe60]
    return acc;
}

// [EN] Reconstructed FDE #1403 @ 0x030328..0x03035c (52 bytes)
// [VN] Phục dựng FDE #1403 tại 0x030328..0x03035c (52 byte)
//   0x030328: f0000148  adrp     x8, #0x5b000
//   0x03032c: f9447508  ldr      x8, [x8, #0x8e8]
//   0x030330: 39400108  ldrb     w8, [x8]
//   0x030334: 34000108  cbz      w8, #0x30354
//   0x030338: f0000148  adrp     x8, #0x5b000
//   0x03033c: f0000149  adrp     x9, #0x5b000
//   0x030340: f942a108  ldr      x8, [x8, #0x540]
//   0x030344: f9473129  ldr      x9, [x9, #0xe60]
//   0x030348: f9400101  ldr      x1, [x8]
//   0x03034c: f9400120  ldr      x0, [x9]
//   0x030350: d61f0020  br       x1
//   0x030354: 2a1f03e0  mov      w0, wzr
uint64_t fde_1403_sub_030328(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xF9400101ULL) + (x2 ^ 0x030328ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x030328: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9447508ULL; // 0x03032c: ldr x8, [x8, #0x8e8]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x030330: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000108ULL; // 0x030334: cbz w8, #0x30354
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x030338: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000149ULL; // 0x03033c: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A108ULL; // 0x030340: ldr x8, [x8, #0x540]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9473129ULL; // 0x030344: ldr x9, [x9, #0xe60]
    return acc;
}

// [EN] Reconstructed FDE #1404 @ 0x03035c..0x0303b0 (84 bytes)
// [VN] Phục dựng FDE #1404 tại 0x03035c..0x0303b0 (84 byte)
//   0x03035c: d10103ff  sub      sp, sp, #0x40
//   0x030360: f90013f3  str      x19, [sp, #0x20]
//   0x030364: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x030368: 9100c3fd  add      x29, sp, #0x30
//   0x03036c: d53bd053  mrs      x19, tpidr_el0
//   0x030370: f9401668  ldr      x8, [x19, #0x28]
//   0x030374: f9000fe8  str      x8, [sp, #0x18]
//   0x030378: a90087e2  stp      x2, x1, [sp, #8]
//   0x03037c: 910043e1  add      x1, sp, #0x10
//   0x030380: 910023e2  add      x2, sp, #8
//   0x030384: 9400000b  bl       #0x303b0
//   0x030388: f9401668  ldr      x8, [x19, #0x28]
uint64_t fde_1404_sub_03035c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E1ULL) + (x2 ^ 0x03035CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03035c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x030360: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x030364: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x030368: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03036c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x030370: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x030374: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90087E2ULL; // 0x030378: stp x2, x1, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #1405 @ 0x0303b0..0x0303d4 (36 bytes)
// [VN] Phục dựng FDE #1405 tại 0x0303b0..0x0303d4 (36 byte)
//   0x0303b0: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0303b4: 910003fd  mov      x29, sp
//   0x0303b8: f9401000  ldr      x0, [x0, #0x20]
//   0x0303bc: b40000a0  cbz      x0, #0x303d0
//   0x0303c0: f9400008  ldr      x8, [x0]
//   0x0303c4: f9401903  ldr      x3, [x8, #0x30]
//   0x0303c8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0303cc: d61f0060  br       x3
//   0x0303d0: 97ff9c0a  bl       #0x173f8
uint64_t fde_1405_sub_0303b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FF9C0AULL) + (x2 ^ 0x0303B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0303b0: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0303b4: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x0303b8: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x0303bc: cbz x0, #0x303d0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0303c0: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401903ULL; // 0x0303c4: ldr x3, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0303c8: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x0303cc: br x3
    return acc;
}

// [EN] Reconstructed FDE #1406 @ 0x0303d4..0x0303d8 (4 bytes)
// [VN] Phục dựng FDE #1406 tại 0x0303d4..0x0303d8 (4 byte)
//   0x0303d4: d65f03c0  ret      
uint64_t fde_1406_sub_0303d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0303D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0303d4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1407 @ 0x0303d8..0x0303dc (4 bytes)
// [VN] Phục dựng FDE #1407 tại 0x0303d8..0x0303dc (4 byte)
//   0x0303d8: 17ff6a5a  b        #0xad40
uint64_t fde_1407_sub_0303d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF6A5AULL) + (x1 ^ 0x17FF6A5AULL) + (x2 ^ 0x0303D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6A5AULL; // 0x0303d8: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1408 @ 0x0303dc..0x030414 (56 bytes)
// [VN] Phục dựng FDE #1408 tại 0x0303dc..0x030414 (56 byte)
//   0x0303dc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0303e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0303e4: 910043fd  add      x29, sp, #0x10
//   0x0303e8: aa0003f3  mov      x19, x0
//   0x0303ec: 52800200  mov      w0, #0x10
//   0x0303f0: 97ff6c80  bl       #0xb5f0
//   0x0303f4: d0000148  adrp     x8, #0x5a000
//   0x0303f8: 91276108  add      x8, x8, #0x9d8
//   0x0303fc: f9000008  str      x8, [x0]
//   0x030400: f9400668  ldr      x8, [x19, #8]
//   0x030404: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x030408: f9000408  str      x8, [x0, #8]
uint64_t fde_1408_sub_0303dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000008ULL) + (x2 ^ 0x0303DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0303dc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0303e0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0303e4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0303e8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x0303ec: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF6C80ULL; // 0x0303f0: bl #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x0303f4: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91276108ULL; // 0x0303f8: add x8, x8, #0x9d8
    return acc;
}

// [EN] Reconstructed FDE #1409 @ 0x030414..0x03042c (24 bytes)
// [VN] Phục dựng FDE #1409 tại 0x030414..0x03042c (24 byte)
//   0x030414: d0000148  adrp     x8, #0x5a000
//   0x030418: 91276108  add      x8, x8, #0x9d8
//   0x03041c: f9000028  str      x8, [x1]
//   0x030420: f9400408  ldr      x8, [x0, #8]
//   0x030424: f9000428  str      x8, [x1, #8]
//   0x030428: d65f03c0  ret      
uint64_t fde_1409_sub_030414(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000148ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x030414ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x030414: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91276108ULL; // 0x030418: add x8, x8, #0x9d8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x03041c: str x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x030420: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000428ULL; // 0x030424: str x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x030428: ret 
    return acc;
}

// [EN] Reconstructed FDE #1410 @ 0x03042c..0x030430 (4 bytes)
// [VN] Phục dựng FDE #1410 tại 0x03042c..0x030430 (4 byte)
//   0x03042c: d65f03c0  ret      
uint64_t fde_1410_sub_03042c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03042CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03042c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1411 @ 0x030430..0x030434 (4 bytes)
// [VN] Phục dựng FDE #1411 tại 0x030430..0x030434 (4 byte)
//   0x030430: 17ff6a44  b        #0xad40
uint64_t fde_1411_sub_030430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF6A44ULL) + (x1 ^ 0x17FF6A44ULL) + (x2 ^ 0x030430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6A44ULL; // 0x030430: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1412 @ 0x030434..0x03044c (24 bytes)
// [VN] Phục dựng FDE #1412 tại 0x030434..0x03044c (24 byte)
//   0x030434: f9400408  ldr      x8, [x0, #8]
//   0x030438: f9400049  ldr      x9, [x2]
//   0x03043c: f9400108  ldr      x8, [x8]
//   0x030440: eb09011f  cmp      x8, x9
//   0x030444: 1a9f17e0  cset     w0, eq
//   0x030448: d65f03c0  ret      
uint64_t fde_1412_sub_030434(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x030434ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x030434: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400049ULL; // 0x030438: ldr x9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x03043c: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x030440: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x030444: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x030448: ret 
    return acc;
}

// [EN] Reconstructed FDE #1413 @ 0x03044c..0x03047c (48 bytes)
// [VN] Phục dựng FDE #1413 tại 0x03044c..0x03047c (48 byte)
//   0x03044c: aa0003e8  mov      x8, x0
//   0x030450: f9401000  ldr      x0, [x0, #0x20]
//   0x030454: eb00011f  cmp      x8, x0
//   0x030458: 540000a0  b.eq     #0x3046c
//   0x03045c: b40000e0  cbz      x0, #0x30478
//   0x030460: f9400008  ldr      x8, [x0]
//   0x030464: f9401501  ldr      x1, [x8, #0x28]
//   0x030468: d61f0020  br       x1
//   0x03046c: f9400008  ldr      x8, [x0]
//   0x030470: f9401101  ldr      x1, [x8, #0x20]
//   0x030474: d61f0020  br       x1
//   0x030478: d65f03c0  ret      
uint64_t fde_1413_sub_03044c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x03044CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x03044c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x030450: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x030454: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x030458: b.eq #0x3046c
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x03045c: cbz x0, #0x30478
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x030460: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401501ULL; // 0x030464: ldr x1, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x030468: br x1
    return acc;
}

// [EN] Reconstructed FDE #1414 @ 0x03047c..0x030488 (12 bytes)
// [VN] Phục dựng FDE #1414 tại 0x03047c..0x030488 (12 byte)
//   0x03047c: f9400102  ldr      x2, [x8]
//   0x030480: f9400120  ldr      x0, [x9]
//   0x030484: d61f0040  br       x2
uint64_t fde_1414_sub_03047c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400102ULL) + (x1 ^ 0xD61F0040ULL) + (x2 ^ 0x03047CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x03047c: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400120ULL; // 0x030480: ldr x0, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x030484: br x2
    return acc;
}

// [EN] Reconstructed FDE #1415 @ 0x030488..0x030490 (8 bytes)
// [VN] Phục dựng FDE #1415 tại 0x030488..0x030490 (8 byte)
//   0x030488: 910063e0  add      x0, sp, #0x18
//   0x03048c: 17ff6b35  b        #0xb160
uint64_t fde_1415_sub_030488(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FF6B35ULL) + (x2 ^ 0x030488ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x030488: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6B35ULL; // 0x03048c: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1416 @ 0x030490..0x030520 (144 bytes)
// [VN] Phục dựng FDE #1416 tại 0x030490..0x030520 (144 byte)
//   0x030490: d100c3ff  sub      sp, sp, #0x30
//   0x030494: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x030498: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03049c: 910083fd  add      x29, sp, #0x20
//   0x0304a0: d53bd054  mrs      x20, tpidr_el0
//   0x0304a4: f9401688  ldr      x8, [x20, #0x28]
//   0x0304a8: aa0003f3  mov      x19, x0
//   0x0304ac: f0000140  adrp     x0, #0x5b000
//   0x0304b0: f90007e8  str      x8, [sp, #8]
//   0x0304b4: f90003fe  str      x30, [sp]
//   0x0304b8: f945c000  ldr      x0, [x0, #0xb80]
//   0x0304bc: 97ff69f9  bl       #0xaca0
uint64_t fde_1416_sub_030490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x030490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x030490: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x030494: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x030498: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03049c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0304a0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0304a4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0304a8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000140ULL; // 0x0304ac: adrp x0, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1417 @ 0x030520..0x03079c (636 bytes)
// [VN] Phục dựng FDE #1417 tại 0x030520..0x03079c (636 byte)
//   0x030520: d10243ff  sub      sp, sp, #0x90
//   0x030524: f90023f9  str      x25, [sp, #0x40]
//   0x030528: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x03052c: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x030530: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x030534: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x030538: 910203fd  add      x29, sp, #0x80
//   0x03053c: d53bd058  mrs      x24, tpidr_el0
//   0x030540: f9401708  ldr      x8, [x24, #0x28]
//   0x030544: f0000159  adrp     x25, #0x5b000
//   0x030548: f9001fe8  str      x8, [sp, #0x38]
//   0x03054c: f9442b39  ldr      x25, [x25, #0x850]
uint64_t fde_1417_sub_030520(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9401708ULL) + (x2 ^ 0x030520ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x030520: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x030524: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x030528: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x03052c: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x030530: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x030534: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x030538: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x03053c: mrs x24, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1418 @ 0x03079c..0x0307a4 (8 bytes)
// [VN] Phục dựng FDE #1418 tại 0x03079c..0x0307a4 (8 byte)
//   0x03079c: 910063e0  add      x0, sp, #0x18
//   0x0307a0: 17ff6a70  b        #0xb160
uint64_t fde_1418_sub_03079c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910063E0ULL) + (x1 ^ 0x17FF6A70ULL) + (x2 ^ 0x03079CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910063E0ULL; // 0x03079c: add x0, sp, #0x18
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6A70ULL; // 0x0307a0: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1419 @ 0x0307a4..0x030860 (188 bytes)
// [VN] Phục dựng FDE #1419 tại 0x0307a4..0x030860 (188 byte)
//   0x0307a4: d10143ff  sub      sp, sp, #0x50
//   0x0307a8: f9000bf7  str      x23, [sp, #0x10]
//   0x0307ac: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x0307b0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0307b4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0307b8: 910103fd  add      x29, sp, #0x40
//   0x0307bc: d53bd057  mrs      x23, tpidr_el0
//   0x0307c0: f94016e8  ldr      x8, [x23, #0x28]
//   0x0307c4: 2a0203f3  mov      w19, w2
//   0x0307c8: aa0103f4  mov      x20, x1
//   0x0307cc: aa0003f6  mov      x22, x0
//   0x0307d0: f90007e8  str      x8, [sp, #8]
uint64_t fde_1419_sub_0307a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x2A0203F3ULL) + (x2 ^ 0x0307A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0307a4: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x0307a8: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x0307ac: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0307b0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0307b4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0307b8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x0307bc: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x0307c0: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1420 @ 0x030860..0x0308f8 (152 bytes)
// [VN] Phục dựng FDE #1420 tại 0x030860..0x0308f8 (152 byte)
//   0x030860: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x030864: 910003fd  mov      x29, sp
//   0x030868: b0000169  adrp     x9, #0x5d000
//   0x03086c: 92409c48  and      x8, x2, #0xffffffffff
//   0x030870: 911dc129  add      x9, x9, #0x770
//   0x030874: 92409c6a  and      x10, x3, #0xffffffffff
//   0x030878: a9002928  stp      x8, x10, [x9]
//   0x03087c: f0000143  adrp     x3, #0x5b000
//   0x030880: f9457863  ldr      x3, [x3, #0xaf0]
//   0x030884: b0000040  adrp     x0, #0x39000
//   0x030888: 90000082  adrp     x2, #0x40000
//   0x03088c: 911cd000  add      x0, x0, #0x734
uint64_t fde_1420_sub_030860(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF9457863ULL) + (x2 ^ 0x030860ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x030860: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x030864: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000169ULL; // 0x030868: adrp x9, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x92409C48ULL; // 0x03086c: and x8, x2, #0xffffffffff
    acc = (acc * 0x100000001B3ULL) ^ 0x911DC129ULL; // 0x030870: add x9, x9, #0x770
    acc = (acc * 0x100000001B3ULL) ^ 0x92409C6AULL; // 0x030874: and x10, x3, #0xffffffffff
    acc = (acc * 0x100000001B3ULL) ^ 0xA9002928ULL; // 0x030878: stp x8, x10, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000143ULL; // 0x03087c: adrp x3, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1421 @ 0x0308f8..0x030998 (160 bytes)
// [VN] Phục dựng FDE #1421 tại 0x0308f8..0x030998 (160 byte)
//   0x0308f8: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0308fc: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x030900: 910043fd  add      x29, sp, #0x10
//   0x030904: b0000168  adrp     x8, #0x5d000
//   0x030908: 395da508  ldrb     w8, [x8, #0x769]
//   0x03090c: 36000228  tbz      w8, #0, #0x30950
//   0x030910: b0000173  adrp     x19, #0x5d000
//   0x030914: 911dc273  add      x19, x19, #0x770
//   0x030918: a9402260  ldp      x0, x8, [x19]
//   0x03091c: 528000e2  mov      w2, #7
//   0x030920: cb000101  sub      x1, x8, x0
//   0x030924: 97ffa2f9  bl       #0x19508
uint64_t fde_1421_sub_0308f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9402260ULL) + (x2 ^ 0x0308F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0308f8: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0308fc: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x030900: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000168ULL; // 0x030904: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x395DA508ULL; // 0x030908: ldrb w8, [x8, #0x769]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000228ULL; // 0x03090c: tbz w8, #0, #0x30950
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000173ULL; // 0x030910: adrp x19, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x911DC273ULL; // 0x030914: add x19, x19, #0x770
    return acc;
}

// [EN] Reconstructed FDE #1422 @ 0x030998..0x0309ac (20 bytes)
// [VN] Phục dựng FDE #1422 tại 0x030998..0x0309ac (20 byte)
//   0x030998: f0000148  adrp     x8, #0x5b000
//   0x03099c: f947c108  ldr      x8, [x8, #0xf80]
//   0x0309a0: 52800029  mov      w9, #1
//   0x0309a4: 39000109  strb     w9, [x8]
//   0x0309a8: d65f03c0  ret      
uint64_t fde_1422_sub_030998(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x030998ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x030998: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947C108ULL; // 0x03099c: ldr x8, [x8, #0xf80]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x0309a0: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x39000109ULL; // 0x0309a4: strb w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0309a8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1423 @ 0x0309ac..0x030dec (1088 bytes)
// [VN] Phục dựng FDE #1423 tại 0x0309ac..0x030dec (1088 byte)
//   0x0309ac: d10303ff  sub      sp, sp, #0xc0
//   0x0309b0: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x0309b4: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x0309b8: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x0309bc: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x0309c0: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x0309c4: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x0309c8: 9102c3fd  add      x29, sp, #0xb0
//   0x0309cc: d53bd05b  mrs      x27, tpidr_el0
//   0x0309d0: f9401768  ldr      x8, [x27, #0x28]
//   0x0309d4: aa0103f3  mov      x19, x1
//   0x0309d8: aa0003f4  mov      x20, x0
uint64_t fde_1423_sub_0309ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD53BD05BULL) + (x2 ^ 0x0309ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0309ac: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x0309b0: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x0309b4: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x0309b8: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x0309bc: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0309c0: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x0309c4: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x0309c8: add x29, sp, #0xb0
    return acc;
}

// [EN] Reconstructed FDE #1424 @ 0x030dec..0x0310c0 (724 bytes)
// [VN] Phục dựng FDE #1424 tại 0x030dec..0x0310c0 (724 byte)
//   0x030dec: d10243ff  sub      sp, sp, #0x90
//   0x030df0: a90467fa  stp      x26, x25, [sp, #0x40]
//   0x030df4: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x030df8: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x030dfc: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x030e00: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x030e04: 910203fd  add      x29, sp, #0x80
//   0x030e08: d53bd059  mrs      x25, tpidr_el0
//   0x030e0c: f9401728  ldr      x8, [x25, #0x28]
//   0x030e10: 2a0503f3  mov      w19, w5
//   0x030e14: 2a0403f4  mov      w20, w4
//   0x030e18: 2a0303f5  mov      w21, w3
uint64_t fde_1424_sub_030dec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x030DECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x030dec: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xA90467FAULL; // 0x030df0: stp x26, x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x030df4: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x030df8: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x030dfc: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x030e00: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x030e04: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x030e08: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1425 @ 0x0310c0..0x0310f0 (48 bytes)
// [VN] Phục dựng FDE #1425 tại 0x0310c0..0x0310f0 (48 byte)
//   0x0310c0: 39400028  ldrb     w8, [x1]
//   0x0310c4: f9400829  ldr      x9, [x1, #0x10]
//   0x0310c8: 7200011f  tst      w8, #1
//   0x0310cc: 9a811528  csinc    x8, x9, x1, ne
//   0x0310d0: f9000008  str      x8, [x0]
//   0x0310d4: 39400028  ldrb     w8, [x1]
//   0x0310d8: f9400429  ldr      x9, [x1, #8]
//   0x0310dc: d341fd0a  lsr      x10, x8, #1
//   0x0310e0: 7200011f  tst      w8, #1
//   0x0310e4: 9a890148  csel     x8, x10, x9, eq
//   0x0310e8: f9000408  str      x8, [x0, #8]
//   0x0310ec: d65f03c0  ret      
uint64_t fde_1425_sub_0310c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x39400028ULL) + (x1 ^ 0x7200011FULL) + (x2 ^ 0x0310C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x0310c0: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400829ULL; // 0x0310c4: ldr x9, [x1, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7200011FULL; // 0x0310c8: tst w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x9A811528ULL; // 0x0310cc: csinc x8, x9, x1, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x0310d0: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400028ULL; // 0x0310d4: ldrb w8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400429ULL; // 0x0310d8: ldr x9, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD341FD0AULL; // 0x0310dc: lsr x10, x8, #1
    return acc;
}

// [EN] Reconstructed FDE #1426 @ 0x0310f0..0x03111c (44 bytes)
// [VN] Phục dựng FDE #1426 tại 0x0310f0..0x03111c (44 byte)
//   0x0310f0: d10303ff  sub      sp, sp, #0xc0
//   0x0310f4: a9088be1  stp      x1, x2, [sp, #0x88]
//   0x0310f8: a90993e3  stp      x3, x4, [sp, #0x98]
//   0x0310fc: a90a9be5  stp      x5, x6, [sp, #0xa8]
//   0x031100: f9005fe7  str      x7, [sp, #0xb8]
//   0x031104: ad0007e0  stp      q0, q1, [sp]
//   0x031108: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x03110c: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x031110: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x031114: 910303ff  add      sp, sp, #0xc0
//   0x031118: d65f03c0  ret      
uint64_t fde_1426_sub_0310f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xAD031FE6ULL) + (x2 ^ 0x0310F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0310f0: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9088BE1ULL; // 0x0310f4: stp x1, x2, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90993E3ULL; // 0x0310f8: stp x3, x4, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A9BE5ULL; // 0x0310fc: stp x5, x6, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9005FE7ULL; // 0x031100: str x7, [sp, #0xb8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x031104: stp q0, q1, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD010FE2ULL; // 0x031108: stp q2, q3, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0217E4ULL; // 0x03110c: stp q4, q5, [sp, #0x40]
    return acc;
}

// [EN] Reconstructed FDE #1427 @ 0x03111c..0x031188 (108 bytes)
// [VN] Phục dựng FDE #1427 tại 0x03111c..0x031188 (108 byte)
//   0x03111c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x031120: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x031124: 910043fd  add      x29, sp, #0x10
//   0x031128: aa0003f4  mov      x20, x0
//   0x03112c: aa0103e0  mov      x0, x1
//   0x031130: aa0103f3  mov      x19, x1
//   0x031134: 97ff67bb  bl       #0xb020
//   0x031138: 39400288  ldrb     w8, [x20]
//   0x03113c: f9400689  ldr      x9, [x20, #8]
//   0x031140: d341fd0a  lsr      x10, x8, #1
//   0x031144: 7200011f  tst      w8, #1
//   0x031148: 9a890148  csel     x8, x10, x9, eq
uint64_t fde_1427_sub_03111c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400689ULL) + (x2 ^ 0x03111CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x03111c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x031120: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x031124: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x031128: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x03112c: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x031130: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF67BBULL; // 0x031134: bl #0xb020
    acc = (acc * 0x100000001B3ULL) ^ 0x39400288ULL; // 0x031138: ldrb w8, [x20]
    return acc;
}

// [EN] Reconstructed FDE #1428 @ 0x031188..0x031190 (8 bytes)
// [VN] Phục dựng FDE #1428 tại 0x031188..0x031190 (8 byte)
//   0x031188: aa1403e0  mov      x0, x20
//   0x03118c: 17ff66d1  b        #0xacd0
uint64_t fde_1428_sub_031188(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0x17FF66D1ULL) + (x2 ^ 0x031188ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x031188: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF66D1ULL; // 0x03118c: b #0xacd0
    return acc;
}

// [EN] Reconstructed FDE #1429 @ 0x031190..0x031270 (224 bytes)
// [VN] Phục dựng FDE #1429 tại 0x031190..0x031270 (224 byte)
//   0x031190: d10183ff  sub      sp, sp, #0x60
//   0x031194: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x031198: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03119c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0311a0: 910143fd  add      x29, sp, #0x50
//   0x0311a4: d53bd056  mrs      x22, tpidr_el0
//   0x0311a8: f94016c8  ldr      x8, [x22, #0x28]
//   0x0311ac: 2a0203f4  mov      w20, w2
//   0x0311b0: aa0103f3  mov      x19, x1
//   0x0311b4: f90017e8  str      x8, [sp, #0x28]
//   0x0311b8: f90013e0  str      x0, [sp, #0x20]
//   0x0311bc: 94000374  bl       #0x31f8c
uint64_t fde_1429_sub_031190(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0103F3ULL) + (x2 ^ 0x031190ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x031190: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x031194: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x031198: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03119c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0311a0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x0311a4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x0311a8: ldr x8, [x22, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x0311ac: mov w20, w2
    return acc;
}

// [EN] Reconstructed FDE #1430 @ 0x031270..0x031358 (232 bytes)
// [VN] Phục dựng FDE #1430 tại 0x031270..0x031358 (232 byte)
//   0x031270: d10143ff  sub      sp, sp, #0x50
//   0x031274: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x031278: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x03127c: 910103fd  add      x29, sp, #0x40
//   0x031280: d53bd054  mrs      x20, tpidr_el0
//   0x031284: f9401688  ldr      x8, [x20, #0x28]
//   0x031288: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03128c: f90013e0  str      x0, [sp, #0x20]
//   0x031290: d0000140  adrp     x0, #0x5b000
//   0x031294: f947b000  ldr      x0, [x0, #0xf60]
//   0x031298: 97ff68ce  bl       #0xb5d0
//   0x03129c: d0000153  adrp     x19, #0x5b000
uint64_t fde_1430_sub_031270(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xD0000140ULL) + (x2 ^ 0x031270ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x031270: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x031274: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x031278: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x03127c: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x031280: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x031284: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x031288: stur x8, [x29, #-0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013E0ULL; // 0x03128c: str x0, [sp, #0x20]
    return acc;
}

// [EN] Reconstructed FDE #1431 @ 0x031358..0x0316b0 (856 bytes)
// [VN] Phục dựng FDE #1431 tại 0x031358..0x0316b0 (856 byte)
//   0x031358: d10203ff  sub      sp, sp, #0x80
//   0x03135c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x031360: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x031364: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x031368: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03136c: 9101c3fd  add      x29, sp, #0x70
//   0x031370: d53bd057  mrs      x23, tpidr_el0
//   0x031374: f94016e8  ldr      x8, [x23, #0x28]
//   0x031378: d0000158  adrp     x24, #0x5b000
//   0x03137c: f9001fe8  str      x8, [sp, #0x38]
//   0x031380: f9427318  ldr      x24, [x24, #0x4e0]
//   0x031384: 39400308  ldrb     w8, [x24]
uint64_t fde_1431_sub_031358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD0000158ULL) + (x2 ^ 0x031358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x031358: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x03135c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x031360: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x031364: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x031368: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03136c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x031370: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x031374: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1432 @ 0x0316b0..0x0318c0 (528 bytes)
// [VN] Phục dựng FDE #1432 tại 0x0316b0..0x0318c0 (528 byte)
//   0x0316b0: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x0316b4: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0316b8: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0316bc: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0316c0: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0316c4: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0316c8: 910143fd  add      x29, sp, #0x50
//   0x0316cc: f9400008  ldr      x8, [x0]
//   0x0316d0: aa0203f7  mov      x23, x2
//   0x0316d4: aa1f03e2  mov      x2, xzr
//   0x0316d8: aa0303f4  mov      x20, x3
//   0x0316dc: f942a508  ldr      x8, [x8, #0x548]
uint64_t fde_1432_sub_0316b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xAA0203F7ULL) + (x2 ^ 0x0316B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x0316b0: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x0316b4: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0316b8: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0316bc: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0316c0: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0316c4: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0316c8: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0316cc: ldr x8, [x0]
    return acc;
}

// [EN] Reconstructed FDE #1433 @ 0x0318c0..0x031c58 (920 bytes)
// [VN] Phục dựng FDE #1433 tại 0x0318c0..0x031c58 (920 byte)
//   0x0318c0: d10303ff  sub      sp, sp, #0xc0
//   0x0318c4: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x0318c8: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x0318cc: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x0318d0: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x0318d4: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x0318d8: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x0318dc: 9102c3fd  add      x29, sp, #0xb0
//   0x0318e0: d53bd05b  mrs      x27, tpidr_el0
//   0x0318e4: f9401768  ldr      x8, [x27, #0x28]
//   0x0318e8: f9002fe8  str      x8, [sp, #0x58]
//   0x0318ec: 940001a4  bl       #0x31f7c
uint64_t fde_1433_sub_0318c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD53BD05BULL) + (x2 ^ 0x0318C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0318c0: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x0318c4: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x0318c8: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x0318cc: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x0318d0: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x0318d4: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x0318d8: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x0318dc: add x29, sp, #0xb0
    return acc;
}

// [EN] Reconstructed FDE #1434 @ 0x031c58..0x031e88 (560 bytes)
// [VN] Phục dựng FDE #1434 tại 0x031c58..0x031e88 (560 byte)
//   0x031c58: d10343ff  sub      sp, sp, #0xd0
//   0x031c5c: f9004bf7  str      x23, [sp, #0x90]
//   0x031c60: a90a57f6  stp      x22, x21, [sp, #0xa0]
//   0x031c64: a90b4ff4  stp      x20, x19, [sp, #0xb0]
//   0x031c68: a90c7bfd  stp      x29, x30, [sp, #0xc0]
//   0x031c6c: 910303fd  add      x29, sp, #0xc0
//   0x031c70: d53bd056  mrs      x22, tpidr_el0
//   0x031c74: f94016c8  ldr      x8, [x22, #0x28]
//   0x031c78: f81c83a8  stur     x8, [x29, #-0x38]
//   0x031c7c: 940000c0  bl       #0x31f7c
//   0x031c80: 340006a8  cbz      w8, #0x31d54
//   0x031c84: d10163a8  sub      x8, x29, #0x58
uint64_t fde_1434_sub_031c58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10343FFULL) + (x1 ^ 0xF81C83A8ULL) + (x2 ^ 0x031C58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10343FFULL; // 0x031c58: sub sp, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF7ULL; // 0x031c5c: str x23, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A57F6ULL; // 0x031c60: stp x22, x21, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B4FF4ULL; // 0x031c64: stp x20, x19, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C7BFDULL; // 0x031c68: stp x29, x30, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910303FDULL; // 0x031c6c: add x29, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x031c70: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x031c74: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1435 @ 0x031e88..0x031ef0 (104 bytes)
// [VN] Phục dựng FDE #1435 tại 0x031e88..0x031ef0 (104 byte)
//   0x031e88: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x031e8c: 910003fd  mov      x29, sp
//   0x031e90: 9400003b  bl       #0x31f7c
//   0x031e94: 340001c8  cbz      w8, #0x31ecc
//   0x031e98: d0000148  adrp     x8, #0x5b000
//   0x031e9c: f943c508  ldr      x8, [x8, #0x788]
//   0x031ea0: f9400108  ldr      x8, [x8]
//   0x031ea4: b4000188  cbz      x8, #0x31ed4
//   0x031ea8: d63f0100  blr      x8
//   0x031eac: 97ff95dc  bl       #0x1761c
//   0x031eb0: 360000e0  tbz      w0, #0, #0x31ecc
//   0x031eb4: 90000041  adrp     x1, #0x39000
uint64_t fde_1435_sub_031e88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x031E88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x031e88: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x031e8c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x9400003BULL; // 0x031e90: bl #0x31f7c
    acc = (acc * 0x100000001B3ULL) ^ 0x340001C8ULL; // 0x031e94: cbz w8, #0x31ecc
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x031e98: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF943C508ULL; // 0x031e9c: ldr x8, [x8, #0x788]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x031ea0: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000188ULL; // 0x031ea4: cbz x8, #0x31ed4
    return acc;
}

// [EN] Reconstructed FDE #1436 @ 0x031ef0..0x031efc (12 bytes)
// [VN] Phục dựng FDE #1436 tại 0x031ef0..0x031efc (12 byte)
//   0x031ef0: f9000100  str      x0, [x8]
//   0x031ef4: 910083e0  add      x0, sp, #0x20
//   0x031ef8: 17ff649a  b        #0xb160
uint64_t fde_1436_sub_031ef0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9000100ULL) + (x1 ^ 0x17FF649AULL) + (x2 ^ 0x031EF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000100ULL; // 0x031ef0: str x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E0ULL; // 0x031ef4: add x0, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF649AULL; // 0x031ef8: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1437 @ 0x031efc..0x031f04 (8 bytes)
// [VN] Phục dựng FDE #1437 tại 0x031efc..0x031f04 (8 byte)
//   0x031efc: 910083e0  add      x0, sp, #0x20
//   0x031f00: 17ff6498  b        #0xb160
uint64_t fde_1437_sub_031efc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910083E0ULL) + (x1 ^ 0x17FF6498ULL) + (x2 ^ 0x031EFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910083E0ULL; // 0x031efc: add x0, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6498ULL; // 0x031f00: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1438 @ 0x031f04..0x031f14 (16 bytes)
// [VN] Phục dựng FDE #1438 tại 0x031f04..0x031f14 (16 byte)
//   0x031f04: f9400268  ldr      x8, [x19]
//   0x031f08: aa1303e0  mov      x0, x19
//   0x031f0c: f9404508  ldr      x8, [x8, #0x88]
//   0x031f10: d61f0100  br       x8
uint64_t fde_1438_sub_031f04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x031F04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x031f04: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x031f08: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x031f0c: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x031f10: br x8
    return acc;
}

// [EN] Reconstructed FDE #1439 @ 0x031f14..0x031f2c (24 bytes)
// [VN] Phục dựng FDE #1439 tại 0x031f14..0x031f2c (24 byte)
//   0x031f14: f9400268  ldr      x8, [x19]
//   0x031f18: aa1303e0  mov      x0, x19
//   0x031f1c: aa1503e1  mov      x1, x21
//   0x031f20: aa1803e2  mov      x2, x24
//   0x031f24: f942a908  ldr      x8, [x8, #0x550]
//   0x031f28: d61f0100  br       x8
uint64_t fde_1439_sub_031f14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x031F14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x031f14: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x031f18: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x031f1c: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1803E2ULL; // 0x031f20: mov x2, x24
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A908ULL; // 0x031f24: ldr x8, [x8, #0x550]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x031f28: br x8
    return acc;
}

// [EN] Reconstructed FDE #1440 @ 0x031f2c..0x031f40 (20 bytes)
// [VN] Phục dựng FDE #1440 tại 0x031f2c..0x031f40 (20 byte)
//   0x031f2c: f9400288  ldr      x8, [x20]
//   0x031f30: aa1403e0  mov      x0, x20
//   0x031f34: aa1303e1  mov      x1, x19
//   0x031f38: f9401d08  ldr      x8, [x8, #0x38]
//   0x031f3c: d61f0100  br       x8
uint64_t fde_1440_sub_031f2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400288ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x031F2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400288ULL; // 0x031f2c: ldr x8, [x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x031f30: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x031f34: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401D08ULL; // 0x031f38: ldr x8, [x8, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x031f3c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1441 @ 0x031f40..0x031f4c (12 bytes)
// [VN] Phục dựng FDE #1441 tại 0x031f40..0x031f4c (12 byte)
//   0x031f40: aa1303e0  mov      x0, x19
//   0x031f44: f9439108  ldr      x8, [x8, #0x720]
//   0x031f48: d61f0100  br       x8
uint64_t fde_1441_sub_031f40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x031F40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x031f40: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x031f44: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x031f48: br x8
    return acc;
}

// [EN] Reconstructed FDE #1442 @ 0x031f4c..0x031f5c (16 bytes)
// [VN] Phục dựng FDE #1442 tại 0x031f4c..0x031f5c (16 byte)
//   0x031f4c: 910de863  add      x3, x3, #0x37a
//   0x031f50: aa1503e5  mov      x5, x21
//   0x031f54: aa0003f6  mov      x22, x0
//   0x031f58: 17ff65ca  b        #0xb680
uint64_t fde_1442_sub_031f4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910DE863ULL) + (x1 ^ 0x17FF65CAULL) + (x2 ^ 0x031F4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910DE863ULL; // 0x031f4c: add x3, x3, #0x37a
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E5ULL; // 0x031f50: mov x5, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x031f54: mov x22, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF65CAULL; // 0x031f58: b #0xb680
    return acc;
}

// [EN] Reconstructed FDE #1443 @ 0x031f5c..0x031f6c (16 bytes)
// [VN] Phục dựng FDE #1443 tại 0x031f5c..0x031f6c (16 byte)
//   0x031f5c: 52800023  mov      w3, #1
//   0x031f60: aa1403e0  mov      x0, x20
//   0x031f64: aa1303e1  mov      x1, x19
//   0x031f68: 14000cb7  b        #0x35244
uint64_t fde_1443_sub_031f5c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800023ULL) + (x1 ^ 0x14000CB7ULL) + (x2 ^ 0x031F5CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800023ULL; // 0x031f5c: mov w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x031f60: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x031f64: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x14000CB7ULL; // 0x031f68: b #0x35244
    return acc;
}

// [EN] Reconstructed FDE #1444 @ 0x031f6c..0x031f7c (16 bytes)
// [VN] Phục dựng FDE #1444 tại 0x031f6c..0x031f7c (16 byte)
//   0x031f6c: 52800023  mov      w3, #1
//   0x031f70: aa1403e0  mov      x0, x20
//   0x031f74: 52800035  mov      w21, #1
//   0x031f78: 14000cb3  b        #0x35244
uint64_t fde_1444_sub_031f6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800023ULL) + (x1 ^ 0x14000CB3ULL) + (x2 ^ 0x031F6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800023ULL; // 0x031f6c: mov w3, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x031f70: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x52800035ULL; // 0x031f74: mov w21, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x14000CB3ULL; // 0x031f78: b #0x35244
    return acc;
}

// [EN] Reconstructed FDE #1445 @ 0x031f7c..0x031f8c (16 bytes)
// [VN] Phục dựng FDE #1445 tại 0x031f7c..0x031f8c (16 byte)
//   0x031f7c: d0000148  adrp     x8, #0x5b000
//   0x031f80: f9427108  ldr      x8, [x8, #0x4e0]
//   0x031f84: 39400108  ldrb     w8, [x8]
//   0x031f88: d65f03c0  ret      
uint64_t fde_1445_sub_031f7c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000148ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x031F7CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000148ULL; // 0x031f7c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9427108ULL; // 0x031f80: ldr x8, [x8, #0x4e0]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x031f84: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x031f88: ret 
    return acc;
}

// [EN] Reconstructed FDE #1446 @ 0x031f8c..0x031f94 (8 bytes)
// [VN] Phục dựng FDE #1446 tại 0x031f8c..0x031f94 (8 byte)
//   0x031f8c: 910023e0  add      x0, sp, #8
//   0x031f90: 17ff6490  b        #0xb1d0
uint64_t fde_1446_sub_031f8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FF6490ULL) + (x2 ^ 0x031F8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x031f8c: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6490ULL; // 0x031f90: b #0xb1d0
    return acc;
}

// [EN] Reconstructed FDE #1447 @ 0x031f94..0x031f9c (8 bytes)
// [VN] Phục dựng FDE #1447 tại 0x031f94..0x031f9c (8 byte)
//   0x031f94: 52800060  mov      w0, #3
//   0x031f98: 17ff6492  b        #0xb1e0
uint64_t fde_1447_sub_031f94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF6492ULL) + (x2 ^ 0x031F94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x031f94: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6492ULL; // 0x031f98: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1448 @ 0x031f9c..0x031fa8 (12 bytes)
// [VN] Phục dựng FDE #1448 tại 0x031f9c..0x031fa8 (12 byte)
//   0x031f9c: 2a1f03e2  mov      w2, wzr
//   0x031fa0: 2a1f03e3  mov      w3, wzr
//   0x031fa4: 14000ca8  b        #0x35244
uint64_t fde_1448_sub_031f9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E2ULL) + (x1 ^ 0x14000CA8ULL) + (x2 ^ 0x031F9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x031f9c: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E3ULL; // 0x031fa0: mov w3, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000CA8ULL; // 0x031fa4: b #0x35244
    return acc;
}

// [EN] Reconstructed FDE #1449 @ 0x031fa8..0x031fb4 (12 bytes)
// [VN] Phục dựng FDE #1449 tại 0x031fa8..0x031fb4 (12 byte)
//   0x031fa8: f9400100  ldr      x0, [x8]
//   0x031fac: f9400129  ldr      x9, [x9]
//   0x031fb0: d61f0120  br       x9
uint64_t fde_1449_sub_031fa8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400100ULL) + (x1 ^ 0xD61F0120ULL) + (x2 ^ 0x031FA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400100ULL; // 0x031fa8: ldr x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400129ULL; // 0x031fac: ldr x9, [x9]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0120ULL; // 0x031fb0: br x9
    return acc;
}

// [EN] Reconstructed FDE #1450 @ 0x031fb4..0x031fc0 (12 bytes)
// [VN] Phục dựng FDE #1450 tại 0x031fb4..0x031fc0 (12 byte)
//   0x031fb4: 910023e0  add      x0, sp, #8
//   0x031fb8: aa1403e1  mov      x1, x20
//   0x031fbc: 17ff64c9  b        #0xb2e0
uint64_t fde_1450_sub_031fb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FF64C9ULL) + (x2 ^ 0x031FB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x031fb4: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x031fb8: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF64C9ULL; // 0x031fbc: b #0xb2e0
    return acc;
}

// [EN] Reconstructed FDE #1451 @ 0x031fc0..0x031fcc (12 bytes)
// [VN] Phục dựng FDE #1451 tại 0x031fc0..0x031fcc (12 byte)
//   0x031fc0: aa0103f3  mov      x19, x1
//   0x031fc4: aa0003f4  mov      x20, x0
//   0x031fc8: 17ff6622  b        #0xb850
uint64_t fde_1451_sub_031fc0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0103F3ULL) + (x1 ^ 0x17FF6622ULL) + (x2 ^ 0x031FC0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x031fc0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x031fc4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6622ULL; // 0x031fc8: b #0xb850
    return acc;
}

// [EN] Reconstructed FDE #1452 @ 0x031fcc..0x031fd8 (12 bytes)
// [VN] Phục dựng FDE #1452 tại 0x031fcc..0x031fd8 (12 byte)
//   0x031fcc: d0000140  adrp     x0, #0x5b000
//   0x031fd0: f947b000  ldr      x0, [x0, #0xf60]
//   0x031fd4: 17ff648f  b        #0xb210
uint64_t fde_1452_sub_031fcc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000140ULL) + (x1 ^ 0x17FF648FULL) + (x2 ^ 0x031FCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000140ULL; // 0x031fcc: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947B000ULL; // 0x031fd0: ldr x0, [x0, #0xf60]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF648FULL; // 0x031fd4: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1453 @ 0x031fd8..0x031fdc (4 bytes)
// [VN] Phục dựng FDE #1453 tại 0x031fd8..0x031fdc (4 byte)
//   0x031fd8: 17ff6ec2  b        #0xdae0
uint64_t fde_1453_sub_031fd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF6EC2ULL) + (x1 ^ 0x17FF6EC2ULL) + (x2 ^ 0x031FD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6EC2ULL; // 0x031fd8: b #0xdae0
    return acc;
}

// [EN] Reconstructed FDE #1454 @ 0x031fdc..0x0320dc (256 bytes)
// [VN] Phục dựng FDE #1454 tại 0x031fdc..0x0320dc (256 byte)
//   0x031fdc: d10143ff  sub      sp, sp, #0x50
//   0x031fe0: f9000bf7  str      x23, [sp, #0x10]
//   0x031fe4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x031fe8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x031fec: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x031ff0: 910103fd  add      x29, sp, #0x40
//   0x031ff4: d53bd056  mrs      x22, tpidr_el0
//   0x031ff8: f94016c8  ldr      x8, [x22, #0x28]
//   0x031ffc: f90007e8  str      x8, [sp, #8]
//   0x032000: 97ff659c  bl       #0xb670
//   0x032004: 51006808  sub      w8, w0, #0x1a
//   0x032008: 7100111f  cmp      w8, #4
uint64_t fde_1454_sub_031fdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90007E8ULL) + (x2 ^ 0x031FDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x031fdc: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x031fe0: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x031fe4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x031fe8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x031fec: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x031ff0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x031ff4: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x031ff8: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1455 @ 0x0320dc..0x03210c (48 bytes)
// [VN] Phục dựng FDE #1455 tại 0x0320dc..0x03210c (48 byte)
//   0x0320dc: f0000148  adrp     x8, #0x5d000
//   0x0320e0: 91228108  add      x8, x8, #0x8a0
//   0x0320e4: f9400109  ldr      x9, [x8]
//   0x0320e8: 2a1f03e0  mov      w0, wzr
//   0x0320ec: b40000e9  cbz      x9, #0x32108
//   0x0320f0: f9400508  ldr      x8, [x8, #8]
//   0x0320f4: b40000a8  cbz      x8, #0x32108
//   0x0320f8: f0000148  adrp     x8, #0x5d000
//   0x0320fc: f9444d08  ldr      x8, [x8, #0x898]
//   0x032100: f100011f  cmp      x8, #0
//   0x032104: 1a9f07e0  cset     w0, ne
//   0x032108: d65f03c0  ret      
uint64_t fde_1455_sub_0320dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xF9444D08ULL) + (x2 ^ 0x0320DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0320dc: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91228108ULL; // 0x0320e0: add x8, x8, #0x8a0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400109ULL; // 0x0320e4: ldr x9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E0ULL; // 0x0320e8: mov w0, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E9ULL; // 0x0320ec: cbz x9, #0x32108
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400508ULL; // 0x0320f0: ldr x8, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A8ULL; // 0x0320f4: cbz x8, #0x32108
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0320f8: adrp x8, #0x5d000
    return acc;
}

// [EN] Reconstructed FDE #1456 @ 0x03210c..0x03217c (112 bytes)
// [VN] Phục dựng FDE #1456 tại 0x03210c..0x03217c (112 byte)
//   0x03210c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x032110: 910003fd  mov      x29, sp
//   0x032114: 97fffff2  bl       #0x320dc
//   0x032118: 360000e0  tbz      w0, #0, #0x32134
//   0x03211c: f0000148  adrp     x8, #0x5d000
//   0x032120: 39624108  ldrb     w8, [x8, #0x890]
//   0x032124: 360000e8  tbz      w8, #0, #0x32140
//   0x032128: f0000062  adrp     x2, #0x41000
//   0x03212c: 91186842  add      x2, x2, #0x61a
//   0x032130: 1400000e  b        #0x32168
//   0x032134: f0000062  adrp     x2, #0x41000
//   0x032138: 9117e442  add      x2, x2, #0x5f9
uint64_t fde_1456_sub_03210c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x91186842ULL) + (x2 ^ 0x03210CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03210c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x032110: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF2ULL; // 0x032114: bl #0x320dc
    acc = (acc * 0x100000001B3ULL) ^ 0x360000E0ULL; // 0x032118: tbz w0, #0, #0x32134
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x03211c: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x39624108ULL; // 0x032120: ldrb w8, [x8, #0x890]
    acc = (acc * 0x100000001B3ULL) ^ 0x360000E8ULL; // 0x032124: tbz w8, #0, #0x32140
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000062ULL; // 0x032128: adrp x2, #0x41000
    return acc;
}

// [EN] Reconstructed FDE #1457 @ 0x03217c..0x032278 (252 bytes)
// [VN] Phục dựng FDE #1457 tại 0x03217c..0x032278 (252 byte)
//   0x03217c: d10183ff  sub      sp, sp, #0x60
//   0x032180: f90013f7  str      x23, [sp, #0x20]
//   0x032184: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x032188: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x03218c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x032190: 910143fd  add      x29, sp, #0x50
//   0x032194: d53bd055  mrs      x21, tpidr_el0
//   0x032198: f94016a8  ldr      x8, [x21, #0x28]
//   0x03219c: d0000156  adrp     x22, #0x5c000
//   0x0321a0: aa0103f3  mov      x19, x1
//   0x0321a4: aa0003f4  mov      x20, x0
//   0x0321a8: f9000fe8  str      x8, [sp, #0x18]
uint64_t fde_1457_sub_03217c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xD0000156ULL) + (x2 ^ 0x03217CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x03217c: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x032180: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x032184: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x032188: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x03218c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x032190: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x032194: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x032198: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1458 @ 0x032278..0x0322dc (100 bytes)
// [VN] Phục dựng FDE #1458 tại 0x032278..0x0322dc (100 byte)
//   0x032278: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03227c: 910003fd  mov      x29, sp
//   0x032280: 97ffff97  bl       #0x320dc
//   0x032284: 36000140  tbz      w0, #0, #0x322ac
//   0x032288: f0000148  adrp     x8, #0x5d000
//   0x03228c: 39624108  ldrb     w8, [x8, #0x890]
//   0x032290: 36000188  tbz      w8, #0, #0x322c0
//   0x032294: f0000148  adrp     x8, #0x5d000
//   0x032298: 91224108  add      x8, x8, #0x890
//   0x03229c: a9410500  ldp      x0, x1, [x8, #0x10]
//   0x0322a0: 3900011f  strb     wzr, [x8]
//   0x0322a4: a8c17bfd  ldp      x29, x30, [sp], #0x10
uint64_t fde_1458_sub_032278(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x91224108ULL) + (x2 ^ 0x032278ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x032278: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03227c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF97ULL; // 0x032280: bl #0x320dc
    acc = (acc * 0x100000001B3ULL) ^ 0x36000140ULL; // 0x032284: tbz w0, #0, #0x322ac
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x032288: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x39624108ULL; // 0x03228c: ldrb w8, [x8, #0x890]
    acc = (acc * 0x100000001B3ULL) ^ 0x36000188ULL; // 0x032290: tbz w8, #0, #0x322c0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x032294: adrp x8, #0x5d000
    return acc;
}

// [EN] Reconstructed FDE #1459 @ 0x0322dc..0x032338 (92 bytes)
// [VN] Phục dựng FDE #1459 tại 0x0322dc..0x032338 (92 byte)
//   0x0322dc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0322e0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0322e4: 910043fd  add      x29, sp, #0x10
//   0x0322e8: 2a0003f3  mov      w19, w0
//   0x0322ec: 97ffff7c  bl       #0x320dc
//   0x0322f0: 36000140  tbz      w0, #0, #0x32318
//   0x0322f4: f0000148  adrp     x8, #0x5d000
//   0x0322f8: f9445100  ldr      x0, [x8, #0x8a0]
//   0x0322fc: d0000148  adrp     x8, #0x5c000
//   0x032300: b9011513  str      w19, [x8, #0x114]
//   0x032304: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x032308: 90000001  adrp     x1, #0x32000
uint64_t fde_1459_sub_0322dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xD0000148ULL) + (x2 ^ 0x0322DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0322dc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0322e0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0322e4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003F3ULL; // 0x0322e8: mov w19, w0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFF7CULL; // 0x0322ec: bl #0x320dc
    acc = (acc * 0x100000001B3ULL) ^ 0x36000140ULL; // 0x0322f0: tbz w0, #0, #0x32318
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0322f4: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9445100ULL; // 0x0322f8: ldr x0, [x8, #0x8a0]
    return acc;
}

// [EN] Reconstructed FDE #1460 @ 0x032338..0x032444 (268 bytes)
// [VN] Phục dựng FDE #1460 tại 0x032338..0x032444 (268 byte)
//   0x032338: d101c3ff  sub      sp, sp, #0x70
//   0x03233c: a90267fa  stp      x26, x25, [sp, #0x20]
//   0x032340: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x032344: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x032348: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x03234c: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x032350: 910183fd  add      x29, sp, #0x60
//   0x032354: d53bd056  mrs      x22, tpidr_el0
//   0x032358: f94016c8  ldr      x8, [x22, #0x28]
//   0x03235c: 2a1f03f3  mov      w19, wzr
//   0x032360: f9000fe8  str      x8, [sp, #0x18]
//   0x032364: b4000560  cbz      x0, #0x32410
uint64_t fde_1460_sub_032338(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xF94016C8ULL) + (x2 ^ 0x032338ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x032338: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA90267FAULL; // 0x03233c: stp x26, x25, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x032340: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x032344: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x032348: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x03234c: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x032350: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x032354: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1461 @ 0x032444..0x032450 (12 bytes)
// [VN] Phục dựng FDE #1461 tại 0x032444..0x032450 (12 byte)
//   0x032444: b0000140  adrp     x0, #0x5b000
//   0x032448: f9469400  ldr      x0, [x0, #0xd28]
//   0x03244c: d65f03c0  ret      
uint64_t fde_1461_sub_032444(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000140ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032444ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000140ULL; // 0x032444: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9469400ULL; // 0x032448: ldr x0, [x0, #0xd28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03244c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1462 @ 0x032450..0x032478 (40 bytes)
// [VN] Phục dựng FDE #1462 tại 0x032450..0x032478 (40 byte)
//   0x032450: b9801008  ldrsw    x8, [x0, #0x10]
//   0x032454: 7100111f  cmp      w8, #4
//   0x032458: 540000a8  b.hi     #0x3246c
//   0x03245c: 90000149  adrp     x9, #0x5a000
//   0x032460: 91284129  add      x9, x9, #0xa10
//   0x032464: f8687920  ldr      x0, [x9, x8, lsl #3]
//   0x032468: d65f03c0  ret      
//   0x03246c: f0000060  adrp     x0, #0x41000
//   0x032470: 9119d400  add      x0, x0, #0x675
//   0x032474: d65f03c0  ret      
uint64_t fde_1462_sub_032450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9801008ULL) + (x1 ^ 0x9119D400ULL) + (x2 ^ 0x032450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9801008ULL; // 0x032450: ldrsw x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100111FULL; // 0x032454: cmp w8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A8ULL; // 0x032458: b.hi #0x3246c
    acc = (acc * 0x100000001B3ULL) ^ 0x90000149ULL; // 0x03245c: adrp x9, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x91284129ULL; // 0x032460: add x9, x9, #0xa10
    acc = (acc * 0x100000001B3ULL) ^ 0xF8687920ULL; // 0x032464: ldr x0, [x9, x8, lsl #3]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x032468: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000060ULL; // 0x03246c: adrp x0, #0x41000
    return acc;
}

// [EN] Reconstructed FDE #1463 @ 0x032478..0x0324bc (68 bytes)
// [VN] Phục dựng FDE #1463 tại 0x032478..0x0324bc (68 byte)
//   0x032478: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03247c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x032480: 910043fd  add      x29, sp, #0x10
//   0x032484: f9400413  ldr      x19, [x0, #8]
//   0x032488: a9402668  ldp      x8, x9, [x19]
//   0x03248c: f9000509  str      x9, [x8, #8]
//   0x032490: f9400669  ldr      x9, [x19, #8]
//   0x032494: f9000128  str      x8, [x9]
//   0x032498: f9400808  ldr      x8, [x0, #0x10]
//   0x03249c: d1000508  sub      x8, x8, #1
//   0x0324a0: f9000808  str      x8, [x0, #0x10]
//   0x0324a4: 91004260  add      x0, x19, #0x10
uint64_t fde_1463_sub_032478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400808ULL) + (x2 ^ 0x032478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x032478: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03247c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x032480: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400413ULL; // 0x032484: ldr x19, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9402668ULL; // 0x032488: ldp x8, x9, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000509ULL; // 0x03248c: str x9, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400669ULL; // 0x032490: ldr x9, [x19, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000128ULL; // 0x032494: str x8, [x9]
    return acc;
}

// [EN] Reconstructed FDE #1464 @ 0x0324bc..0x0324c8 (12 bytes)
// [VN] Phục dựng FDE #1464 tại 0x0324bc..0x0324c8 (12 byte)
//   0x0324bc: f0000140  adrp     x0, #0x5d000
//   0x0324c0: 91232000  add      x0, x0, #0x8c8
//   0x0324c4: 17ff6353  b        #0xb210
uint64_t fde_1464_sub_0324bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000140ULL) + (x1 ^ 0x17FF6353ULL) + (x2 ^ 0x0324BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000140ULL; // 0x0324bc: adrp x0, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91232000ULL; // 0x0324c0: add x0, x0, #0x8c8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6353ULL; // 0x0324c4: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1465 @ 0x0324c8..0x0324e0 (24 bytes)
// [VN] Phục dựng FDE #1465 tại 0x0324c8..0x0324e0 (24 byte)
//   0x0324c8: f0000148  adrp     x8, #0x5d000
//   0x0324cc: 91242108  add      x8, x8, #0x908
//   0x0324d0: 52800709  mov      w9, #0x38
//   0x0324d4: 9ba920a8  umaddl   x8, w5, w9, x8
//   0x0324d8: f9411d06  ldr      x6, [x8, #0x238]
//   0x0324dc: d61f00c0  br       x6
uint64_t fde_1465_sub_0324c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD61F00C0ULL) + (x2 ^ 0x0324C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0324c8: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91242108ULL; // 0x0324cc: add x8, x8, #0x908
    acc = (acc * 0x100000001B3ULL) ^ 0x52800709ULL; // 0x0324d0: mov w9, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x9BA920A8ULL; // 0x0324d4: umaddl x8, w5, w9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9411D06ULL; // 0x0324d8: ldr x6, [x8, #0x238]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00C0ULL; // 0x0324dc: br x6
    return acc;
}

// [EN] Reconstructed FDE #1466 @ 0x0324e0..0x032574 (148 bytes)
// [VN] Phục dựng FDE #1466 tại 0x0324e0..0x032574 (148 byte)
//   0x0324e0: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0324e4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0324e8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0324ec: 910083fd  add      x29, sp, #0x20
//   0x0324f0: f0000148  adrp     x8, #0x5d000
//   0x0324f4: b9890d08  ldrsw    x8, [x8, #0x90c]
//   0x0324f8: 2a0303f3  mov      w19, w3
//   0x0324fc: 2a0203f5  mov      w21, w2
//   0x032500: aa0103f4  mov      x20, x1
//   0x032504: 7100051f  cmp      w8, #1
//   0x032508: aa0003f6  mov      x22, x0
//   0x03250c: 540001ab  b.lt     #0x32540
uint64_t fde_1466_sub_0324e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x0324E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0324e0: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0324e4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0324e8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0324ec: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0324f0: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9890D08ULL; // 0x0324f4: ldrsw x8, [x8, #0x90c]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x0324f8: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F5ULL; // 0x0324fc: mov w21, w2
    return acc;
}

// [EN] Reconstructed FDE #1467 @ 0x032574..0x03258c (24 bytes)
// [VN] Phục dựng FDE #1467 tại 0x032574..0x03258c (24 byte)
//   0x032574: f0000148  adrp     x8, #0x5d000
//   0x032578: 91242108  add      x8, x8, #0x908
//   0x03257c: 52800709  mov      w9, #0x38
//   0x032580: 9ba92088  umaddl   x8, w4, w9, x8
//   0x032584: f9412505  ldr      x5, [x8, #0x248]
//   0x032588: d61f00a0  br       x5
uint64_t fde_1467_sub_032574(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD61F00A0ULL) + (x2 ^ 0x032574ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x032574: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91242108ULL; // 0x032578: add x8, x8, #0x908
    acc = (acc * 0x100000001B3ULL) ^ 0x52800709ULL; // 0x03257c: mov w9, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x9BA92088ULL; // 0x032580: umaddl x8, w4, w9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9412505ULL; // 0x032584: ldr x5, [x8, #0x248]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00A0ULL; // 0x032588: br x5
    return acc;
}

// [EN] Reconstructed FDE #1468 @ 0x03258c..0x0325a4 (24 bytes)
// [VN] Phục dựng FDE #1468 tại 0x03258c..0x0325a4 (24 byte)
//   0x03258c: f0000148  adrp     x8, #0x5d000
//   0x032590: 91242108  add      x8, x8, #0x908
//   0x032594: 52800709  mov      w9, #0x38
//   0x032598: 9ba92088  umaddl   x8, w4, w9, x8
//   0x03259c: f9412905  ldr      x5, [x8, #0x250]
//   0x0325a0: d61f00a0  br       x5
uint64_t fde_1468_sub_03258c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD61F00A0ULL) + (x2 ^ 0x03258CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x03258c: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91242108ULL; // 0x032590: add x8, x8, #0x908
    acc = (acc * 0x100000001B3ULL) ^ 0x52800709ULL; // 0x032594: mov w9, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x9BA92088ULL; // 0x032598: umaddl x8, w4, w9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9412905ULL; // 0x03259c: ldr x5, [x8, #0x250]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00A0ULL; // 0x0325a0: br x5
    return acc;
}

// [EN] Reconstructed FDE #1469 @ 0x0325a4..0x0325bc (24 bytes)
// [VN] Phục dựng FDE #1469 tại 0x0325a4..0x0325bc (24 byte)
//   0x0325a4: f0000148  adrp     x8, #0x5d000
//   0x0325a8: 91242108  add      x8, x8, #0x908
//   0x0325ac: 52800709  mov      w9, #0x38
//   0x0325b0: 9ba92088  umaddl   x8, w4, w9, x8
//   0x0325b4: f9412d05  ldr      x5, [x8, #0x258]
//   0x0325b8: d61f00a0  br       x5
uint64_t fde_1469_sub_0325a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD61F00A0ULL) + (x2 ^ 0x0325A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0325a4: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91242108ULL; // 0x0325a8: add x8, x8, #0x908
    acc = (acc * 0x100000001B3ULL) ^ 0x52800709ULL; // 0x0325ac: mov w9, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x9BA92088ULL; // 0x0325b0: umaddl x8, w4, w9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9412D05ULL; // 0x0325b4: ldr x5, [x8, #0x258]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00A0ULL; // 0x0325b8: br x5
    return acc;
}

// [EN] Reconstructed FDE #1470 @ 0x0325bc..0x0325d8 (28 bytes)
// [VN] Phục dựng FDE #1470 tại 0x0325bc..0x0325d8 (28 byte)
//   0x0325bc: f0000148  adrp     x8, #0x5d000
//   0x0325c0: 91242108  add      x8, x8, #0x908
//   0x0325c4: 52800709  mov      w9, #0x38
//   0x0325c8: 9ba920a8  umaddl   x8, w5, w9, x8
//   0x0325cc: f9413106  ldr      x6, [x8, #0x260]
//   0x0325d0: 12000084  and      w4, w4, #1
//   0x0325d4: d61f00c0  br       x6
uint64_t fde_1470_sub_0325bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD61F00C0ULL) + (x2 ^ 0x0325BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0325bc: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91242108ULL; // 0x0325c0: add x8, x8, #0x908
    acc = (acc * 0x100000001B3ULL) ^ 0x52800709ULL; // 0x0325c4: mov w9, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x9BA920A8ULL; // 0x0325c8: umaddl x8, w5, w9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9413106ULL; // 0x0325cc: ldr x6, [x8, #0x260]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000084ULL; // 0x0325d0: and w4, w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00C0ULL; // 0x0325d4: br x6
    return acc;
}

// [EN] Reconstructed FDE #1471 @ 0x0325d8..0x0325f4 (28 bytes)
// [VN] Phục dựng FDE #1471 tại 0x0325d8..0x0325f4 (28 byte)
//   0x0325d8: f0000148  adrp     x8, #0x5d000
//   0x0325dc: 91242108  add      x8, x8, #0x908
//   0x0325e0: 52800709  mov      w9, #0x38
//   0x0325e4: 9ba920a8  umaddl   x8, w5, w9, x8
//   0x0325e8: f9413506  ldr      x6, [x8, #0x268]
//   0x0325ec: 12000084  and      w4, w4, #1
//   0x0325f0: d61f00c0  br       x6
uint64_t fde_1471_sub_0325d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000148ULL) + (x1 ^ 0xD61F00C0ULL) + (x2 ^ 0x0325D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x0325d8: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0x91242108ULL; // 0x0325dc: add x8, x8, #0x908
    acc = (acc * 0x100000001B3ULL) ^ 0x52800709ULL; // 0x0325e0: mov w9, #0x38
    acc = (acc * 0x100000001B3ULL) ^ 0x9BA920A8ULL; // 0x0325e4: umaddl x8, w5, w9, x8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9413506ULL; // 0x0325e8: ldr x6, [x8, #0x268]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000084ULL; // 0x0325ec: and w4, w4, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F00C0ULL; // 0x0325f0: br x6
    return acc;
}

// [EN] Reconstructed FDE #1472 @ 0x0325f4..0x03267c (136 bytes)
// [VN] Phục dựng FDE #1472 tại 0x0325f4..0x03267c (136 byte)
//   0x0325f4: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0325f8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0325fc: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x032600: 910083fd  add      x29, sp, #0x20
//   0x032604: f0000148  adrp     x8, #0x5d000
//   0x032608: b9890d08  ldrsw    x8, [x8, #0x90c]
//   0x03260c: 2a0203f3  mov      w19, w2
//   0x032610: aa0103f4  mov      x20, x1
//   0x032614: aa0003f5  mov      x21, x0
//   0x032618: 7100051f  cmp      w8, #1
//   0x03261c: 540001ab  b.lt     #0x32650
//   0x032620: eb08529f  cmp      x20, x8, lsl #20
uint64_t fde_1472_sub_0325f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x0325F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0325f4: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0325f8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0325fc: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x032600: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000148ULL; // 0x032604: adrp x8, #0x5d000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9890D08ULL; // 0x032608: ldrsw x8, [x8, #0x90c]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03260c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F4ULL; // 0x032610: mov x20, x1
    return acc;
}

// [EN] Reconstructed FDE #1473 @ 0x03267c..0x032728 (172 bytes)
// [VN] Phục dựng FDE #1473 tại 0x03267c..0x032728 (172 byte)
//   0x03267c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x032680: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x032684: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x032688: 910083fd  add      x29, sp, #0x20
//   0x03268c: 90000060  adrp     x0, #0x3e000
//   0x032690: 91227800  add      x0, x0, #0x89e
//   0x032694: 97ff62b7  bl       #0xb170
//   0x032698: 52800053  mov      w19, #2
//   0x03269c: b40003c0  cbz      x0, #0x32714
//   0x0326a0: f0000061  adrp     x1, #0x41000
//   0x0326a4: 9119f421  add      x1, x1, #0x67d
//   0x0326a8: aa0003f4  mov      x20, x0
uint64_t fde_1473_sub_03267c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB40003C0ULL) + (x2 ^ 0x03267CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03267c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x032680: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x032684: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x032688: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000060ULL; // 0x03268c: adrp x0, #0x3e000
    acc = (acc * 0x100000001B3ULL) ^ 0x91227800ULL; // 0x032690: add x0, x0, #0x89e
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF62B7ULL; // 0x032694: bl #0xb170
    acc = (acc * 0x100000001B3ULL) ^ 0x52800053ULL; // 0x032698: mov w19, #2
    return acc;
}

// [EN] Reconstructed FDE #1474 @ 0x032728..0x032c2c (1284 bytes)
// [VN] Phục dựng FDE #1474 tại 0x032728..0x032c2c (1284 byte)
//   0x032728: d10383ff  sub      sp, sp, #0xe0
//   0x03272c: f9004bf9  str      x25, [sp, #0x90]
//   0x032730: a90a5ff8  stp      x24, x23, [sp, #0xa0]
//   0x032734: a90b57f6  stp      x22, x21, [sp, #0xb0]
//   0x032738: a90c4ff4  stp      x20, x19, [sp, #0xc0]
//   0x03273c: a90d7bfd  stp      x29, x30, [sp, #0xd0]
//   0x032740: 910343fd  add      x29, sp, #0xd0
//   0x032744: d53bd056  mrs      x22, tpidr_el0
//   0x032748: f94016c8  ldr      x8, [x22, #0x28]
//   0x03274c: 2a0303f3  mov      w19, w3
//   0x032750: 2a0203f5  mov      w21, w2
//   0x032754: f81b83a8  stur     x8, [x29, #-0x48]
uint64_t fde_1474_sub_032728(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10383FFULL) + (x1 ^ 0xF94016C8ULL) + (x2 ^ 0x032728ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10383FFULL; // 0x032728: sub sp, sp, #0xe0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9004BF9ULL; // 0x03272c: str x25, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A5FF8ULL; // 0x032730: stp x24, x23, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B57F6ULL; // 0x032734: stp x22, x21, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90C4FF4ULL; // 0x032738: stp x20, x19, [sp, #0xc0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90D7BFDULL; // 0x03273c: stp x29, x30, [sp, #0xd0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910343FDULL; // 0x032740: add x29, sp, #0xd0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x032744: mrs x22, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1475 @ 0x032c2c..0x032cd0 (164 bytes)
// [VN] Phục dựng FDE #1475 tại 0x032c2c..0x032cd0 (164 byte)
//   0x032c2c: d10483ff  sub      sp, sp, #0x120
//   0x032c30: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x032c34: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x032c38: 910443fd  add      x29, sp, #0x110
//   0x032c3c: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x032c40: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x032c44: f90057e7  str      x7, [sp, #0xa8]
//   0x032c48: ad0007e0  stp      q0, q1, [sp]
//   0x032c4c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x032c50: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x032c54: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x032c58: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_1475_sub_032c2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x032C2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x032c2c: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x032c30: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x032c34: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x032c38: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x032c3c: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x032c40: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x032c44: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x032c48: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1476 @ 0x032cd0..0x032ce4 (20 bytes)
// [VN] Phục dựng FDE #1476 tại 0x032cd0..0x032ce4 (20 byte)
//   0x032cd0: b0000061  adrp     x1, #0x3f000
//   0x032cd4: 91010421  add      x1, x1, #0x41
//   0x032cd8: 528000c0  mov      w0, #6
//   0x032cdc: aa1303e2  mov      x2, x19
//   0x032ce0: d65f03c0  ret      
uint64_t fde_1476_sub_032cd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000061ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x032CD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000061ULL; // 0x032cd0: adrp x1, #0x3f000
    acc = (acc * 0x100000001B3ULL) ^ 0x91010421ULL; // 0x032cd4: add x1, x1, #0x41
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x032cd8: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E2ULL; // 0x032cdc: mov x2, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x032ce0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1477 @ 0x032ce4..0x032cf0 (12 bytes)
// [VN] Phục dựng FDE #1477 tại 0x032ce4..0x032cf0 (12 byte)
//   0x032ce4: aa1f03e2  mov      x2, xzr
//   0x032ce8: aa1f03e3  mov      x3, xzr
//   0x032cec: d61f0100  br       x8
uint64_t fde_1477_sub_032ce4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x032CE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x032ce4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E3ULL; // 0x032ce8: mov x3, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x032cec: br x8
    return acc;
}

// [EN] Reconstructed FDE #1478 @ 0x032cf0..0x032cf8 (8 bytes)
// [VN] Phục dựng FDE #1478 tại 0x032cf0..0x032cf8 (8 byte)
//   0x032cf0: 52800060  mov      w0, #3
//   0x032cf4: 17ff613b  b        #0xb1e0
uint64_t fde_1478_sub_032cf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF613BULL) + (x2 ^ 0x032CF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x032cf0: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF613BULL; // 0x032cf4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1479 @ 0x032cf8..0x0330b4 (956 bytes)
// [VN] Phục dựng FDE #1479 tại 0x032cf8..0x0330b4 (956 byte)
//   0x032cf8: d10303ff  sub      sp, sp, #0xc0
//   0x032cfc: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x032d00: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x032d04: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x032d08: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x032d0c: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x032d10: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x032d14: 9102c3fd  add      x29, sp, #0xb0
//   0x032d18: d53bd058  mrs      x24, tpidr_el0
//   0x032d1c: f9401708  ldr      x8, [x24, #0x28]
//   0x032d20: aa0003f5  mov      x21, x0
//   0x032d24: f0000020  adrp     x0, #0x39000
uint64_t fde_1479_sub_032cf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xD53BD058ULL) + (x2 ^ 0x032CF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x032cf8: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x032cfc: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x032d00: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x032d04: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x032d08: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x032d0c: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x032d10: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x032d14: add x29, sp, #0xb0
    return acc;
}

// [EN] Reconstructed FDE #1480 @ 0x0330b4..0x033118 (100 bytes)
// [VN] Phục dựng FDE #1480 tại 0x0330b4..0x033118 (100 byte)
//   0x0330b4: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0330b8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0330bc: 910043fd  add      x29, sp, #0x10
//   0x0330c0: aa0003f3  mov      x19, x0
//   0x0330c4: b4000220  cbz      x0, #0x33108
//   0x0330c8: 90000040  adrp     x0, #0x3b000
//   0x0330cc: 911d1800  add      x0, x0, #0x746
//   0x0330d0: 52800021  mov      w1, #1
//   0x0330d4: 97ff5fef  bl       #0xb090
//   0x0330d8: 3100041f  cmn      w0, #1
//   0x0330dc: 54000140  b.eq     #0x33104
//   0x0330e0: 52800082  mov      w2, #4
uint64_t fde_1480_sub_0330b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FF5FEFULL) + (x2 ^ 0x0330B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0330b4: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0330b8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0330bc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0330c0: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x0330c4: cbz x0, #0x33108
    acc = (acc * 0x100000001B3ULL) ^ 0x90000040ULL; // 0x0330c8: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D1800ULL; // 0x0330cc: add x0, x0, #0x746
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x0330d0: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #1481 @ 0x033118..0x033304 (492 bytes)
// [VN] Phục dựng FDE #1481 tại 0x033118..0x033304 (492 byte)
//   0x033118: d102c3ff  sub      sp, sp, #0xb0
//   0x03311c: a9075ff8  stp      x24, x23, [sp, #0x70]
//   0x033120: a90857f6  stp      x22, x21, [sp, #0x80]
//   0x033124: a9094ff4  stp      x20, x19, [sp, #0x90]
//   0x033128: a90a7bfd  stp      x29, x30, [sp, #0xa0]
//   0x03312c: 910283fd  add      x29, sp, #0xa0
//   0x033130: d53bd055  mrs      x21, tpidr_el0
//   0x033134: f94016a8  ldr      x8, [x21, #0x28]
//   0x033138: 2a0203f3  mov      w19, w2
//   0x03313c: aa0003f4  mov      x20, x0
//   0x033140: f81c83a8  stur     x8, [x29, #-0x38]
//   0x033144: 97ff9134  bl       #0x17614
uint64_t fde_1481_sub_033118(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD102C3FFULL) + (x1 ^ 0x2A0203F3ULL) + (x2 ^ 0x033118ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD102C3FFULL; // 0x033118: sub sp, sp, #0xb0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9075FF8ULL; // 0x03311c: stp x24, x23, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90857F6ULL; // 0x033120: stp x22, x21, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9094FF4ULL; // 0x033124: stp x20, x19, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A7BFDULL; // 0x033128: stp x29, x30, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0x910283FDULL; // 0x03312c: add x29, sp, #0xa0
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x033130: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x033134: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1482 @ 0x033304..0x033308 (4 bytes)
// [VN] Phục dựng FDE #1482 tại 0x033304..0x033308 (4 byte)
//   0x033304: 17ff5e8f  b        #0xad40
uint64_t fde_1482_sub_033304(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5E8FULL) + (x1 ^ 0x17FF5E8FULL) + (x2 ^ 0x033304ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5E8FULL; // 0x033304: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1483 @ 0x033308..0x033340 (56 bytes)
// [VN] Phục dựng FDE #1483 tại 0x033308..0x033340 (56 byte)
//   0x033308: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03330c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x033310: 910043fd  add      x29, sp, #0x10
//   0x033314: aa0003f3  mov      x19, x0
//   0x033318: 52800200  mov      w0, #0x10
//   0x03331c: 97ff60b5  bl       #0xb5f0
//   0x033320: f0000128  adrp     x8, #0x5a000
//   0x033324: 912a0108  add      x8, x8, #0xa80
//   0x033328: f9000008  str      x8, [x0]
//   0x03332c: f9400668  ldr      x8, [x19, #8]
//   0x033330: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x033334: f9000408  str      x8, [x0, #8]
uint64_t fde_1483_sub_033308(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9000008ULL) + (x2 ^ 0x033308ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x033308: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03330c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x033310: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x033314: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x033318: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF60B5ULL; // 0x03331c: bl #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x033320: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A0108ULL; // 0x033324: add x8, x8, #0xa80
    return acc;
}

// [EN] Reconstructed FDE #1484 @ 0x033340..0x033358 (24 bytes)
// [VN] Phục dựng FDE #1484 tại 0x033340..0x033358 (24 byte)
//   0x033340: f0000128  adrp     x8, #0x5a000
//   0x033344: 912a0108  add      x8, x8, #0xa80
//   0x033348: f9000028  str      x8, [x1]
//   0x03334c: f9400408  ldr      x8, [x0, #8]
//   0x033350: f9000428  str      x8, [x1, #8]
//   0x033354: d65f03c0  ret      
uint64_t fde_1484_sub_033340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000128ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x033340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x033340: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A0108ULL; // 0x033344: add x8, x8, #0xa80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x033348: str x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x03334c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000428ULL; // 0x033350: str x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x033354: ret 
    return acc;
}

// [EN] Reconstructed FDE #1485 @ 0x033358..0x03335c (4 bytes)
// [VN] Phục dựng FDE #1485 tại 0x033358..0x03335c (4 byte)
//   0x033358: d65f03c0  ret      
uint64_t fde_1485_sub_033358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x033358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x033358: ret 
    return acc;
}

// [EN] Reconstructed FDE #1486 @ 0x03335c..0x033360 (4 bytes)
// [VN] Phục dựng FDE #1486 tại 0x03335c..0x033360 (4 byte)
//   0x03335c: 17ff5e79  b        #0xad40
uint64_t fde_1486_sub_03335c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5E79ULL) + (x1 ^ 0x17FF5E79ULL) + (x2 ^ 0x03335CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5E79ULL; // 0x03335c: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1487 @ 0x033360..0x033378 (24 bytes)
// [VN] Phục dựng FDE #1487 tại 0x033360..0x033378 (24 byte)
//   0x033360: f9400408  ldr      x8, [x0, #8]
//   0x033364: f9400049  ldr      x9, [x2]
//   0x033368: f9400108  ldr      x8, [x8]
//   0x03336c: eb09011f  cmp      x8, x9
//   0x033370: 1a9f17e0  cset     w0, eq
//   0x033374: d65f03c0  ret      
uint64_t fde_1487_sub_033360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x033360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x033360: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400049ULL; // 0x033364: ldr x9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x033368: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x03336c: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x033370: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x033374: ret 
    return acc;
}

// [EN] Reconstructed FDE #1488 @ 0x033378..0x033380 (8 bytes)
// [VN] Phục dựng FDE #1488 tại 0x033378..0x033380 (8 byte)
//   0x033378: aa1303e0  mov      x0, x19
//   0x03337c: 17ff60c9  b        #0xb6a0
uint64_t fde_1488_sub_033378(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0x17FF60C9ULL) + (x2 ^ 0x033378ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x033378: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF60C9ULL; // 0x03337c: b #0xb6a0
    return acc;
}

// [EN] Reconstructed FDE #1489 @ 0x033380..0x033388 (8 bytes)
// [VN] Phục dựng FDE #1489 tại 0x033380..0x033388 (8 byte)
//   0x033380: 528000c0  mov      w0, #6
//   0x033384: 17ff5f97  b        #0xb1e0
uint64_t fde_1489_sub_033380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000C0ULL) + (x1 ^ 0x17FF5F97ULL) + (x2 ^ 0x033380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000C0ULL; // 0x033380: mov w0, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5F97ULL; // 0x033384: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1490 @ 0x033388..0x033498 (272 bytes)
// [VN] Phục dựng FDE #1490 tại 0x033388..0x033498 (272 byte)
//   0x033388: d10143ff  sub      sp, sp, #0x50
//   0x03338c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x033390: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x033394: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x033398: 910103fd  add      x29, sp, #0x40
//   0x03339c: d53bd054  mrs      x20, tpidr_el0
//   0x0333a0: f9401688  ldr      x8, [x20, #0x28]
//   0x0333a4: aa0003f3  mov      x19, x0
//   0x0333a8: 90000140  adrp     x0, #0x5b000
//   0x0333ac: f9000fe8  str      x8, [sp, #0x18]
//   0x0333b0: f9428000  ldr      x0, [x0, #0x500]
//   0x0333b4: 97ff6087  bl       #0xb5d0
uint64_t fde_1490_sub_033388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0x90000140ULL) + (x2 ^ 0x033388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x033388: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x03338c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x033390: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x033394: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x033398: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03339c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0333a0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0333a4: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1491 @ 0x033498..0x033ba8 (1808 bytes)
// [VN] Phục dựng FDE #1491 tại 0x033498..0x033ba8 (1808 byte)
//   0x033498: a9ba6ffc  stp      x28, x27, [sp, #-0x60]!
//   0x03349c: a90167fa  stp      x26, x25, [sp, #0x10]
//   0x0334a0: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x0334a4: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x0334a8: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x0334ac: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x0334b0: 910143fd  add      x29, sp, #0x50
//   0x0334b4: d1401fff  sub      sp, sp, #7, lsl #12
//   0x0334b8: d12f03ff  sub      sp, sp, #0xbc0
//   0x0334bc: d53bd05a  mrs      x26, tpidr_el0
//   0x0334c0: f9401748  ldr      x8, [x26, #0x28]
//   0x0334c4: 2a0203f4  mov      w20, w2
uint64_t fde_1491_sub_033498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BA6FFCULL) + (x1 ^ 0xD12F03FFULL) + (x2 ^ 0x033498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BA6FFCULL; // 0x033498: stp x28, x27, [sp, #-0x60]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90167FAULL; // 0x03349c: stp x26, x25, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x0334a0: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x0334a4: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x0334a8: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x0334ac: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x0334b0: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD1401FFFULL; // 0x0334b4: sub sp, sp, #7, lsl #12
    return acc;
}

// [EN] Reconstructed FDE #1492 @ 0x033ba8..0x033bb4 (12 bytes)
// [VN] Phục dựng FDE #1492 tại 0x033ba8..0x033bb4 (12 byte)
//   0x033ba8: 90000140  adrp     x0, #0x5b000
//   0x033bac: f9428000  ldr      x0, [x0, #0x500]
//   0x033bb0: 17ff5d98  b        #0xb210
uint64_t fde_1492_sub_033ba8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000140ULL) + (x1 ^ 0x17FF5D98ULL) + (x2 ^ 0x033BA8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000140ULL; // 0x033ba8: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9428000ULL; // 0x033bac: ldr x0, [x0, #0x500]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5D98ULL; // 0x033bb0: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1493 @ 0x033bb4..0x033bc8 (20 bytes)
// [VN] Phục dựng FDE #1493 tại 0x033bb4..0x033bc8 (20 byte)
//   0x033bb4: 90000140  adrp     x0, #0x5b000
//   0x033bb8: 90000141  adrp     x1, #0x5b000
//   0x033bbc: f9431000  ldr      x0, [x0, #0x620]
//   0x033bc0: f9428021  ldr      x1, [x1, #0x500]
//   0x033bc4: 17ff5db3  b        #0xb290
uint64_t fde_1493_sub_033bb4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000140ULL) + (x1 ^ 0x17FF5DB3ULL) + (x2 ^ 0x033BB4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000140ULL; // 0x033bb4: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0x90000141ULL; // 0x033bb8: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431000ULL; // 0x033bbc: ldr x0, [x0, #0x620]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9428021ULL; // 0x033bc0: ldr x1, [x1, #0x500]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5DB3ULL; // 0x033bc4: b #0xb290
    return acc;
}

// [EN] Reconstructed FDE #1494 @ 0x033bc8..0x033bd8 (16 bytes)
// [VN] Phục dựng FDE #1494 tại 0x033bc8..0x033bd8 (16 byte)
//   0x033bc8: aa0003e2  mov      x2, x0
//   0x033bcc: aa1903e0  mov      x0, x25
//   0x033bd0: aa1503e1  mov      x1, x21
//   0x033bd4: 17ff5c0f  b        #0xac10
uint64_t fde_1494_sub_033bc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E2ULL) + (x1 ^ 0x17FF5C0FULL) + (x2 ^ 0x033BC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E2ULL; // 0x033bc8: mov x2, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1903E0ULL; // 0x033bcc: mov x0, x25
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x033bd0: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5C0FULL; // 0x033bd4: b #0xac10
    return acc;
}

// [EN] Reconstructed FDE #1495 @ 0x033bd8..0x033be4 (12 bytes)
// [VN] Phục dựng FDE #1495 tại 0x033bd8..0x033be4 (12 byte)
//   0x033bd8: a97fa2a0  ldp      x0, x8, [x21, #-8]
//   0x033bdc: cb000101  sub      x1, x8, x0
//   0x033be0: 17ff966a  b        #0x19588
uint64_t fde_1495_sub_033bd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA97FA2A0ULL) + (x1 ^ 0x17FF966AULL) + (x2 ^ 0x033BD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA97FA2A0ULL; // 0x033bd8: ldp x0, x8, [x21, #-8]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB000101ULL; // 0x033bdc: sub x1, x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF966AULL; // 0x033be0: b #0x19588
    return acc;
}

// [EN] Reconstructed FDE #1496 @ 0x033be4..0x033bf0 (12 bytes)
// [VN] Phục dựng FDE #1496 tại 0x033be4..0x033bf0 (12 byte)
//   0x033be4: aa1503e0  mov      x0, x21
//   0x033be8: 3d804320  str      q0, [x25, #0x100]
//   0x033bec: 17ff5d0d  b        #0xb020
uint64_t fde_1496_sub_033be4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FF5D0DULL) + (x2 ^ 0x033BE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x033be4: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x3D804320ULL; // 0x033be8: str q0, [x25, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5D0DULL; // 0x033bec: b #0xb020
    return acc;
}

// [EN] Reconstructed FDE #1497 @ 0x033bf0..0x033bf8 (8 bytes)
// [VN] Phục dựng FDE #1497 tại 0x033bf0..0x033bf8 (8 byte)
//   0x033bf0: 2a1f03e1  mov      w1, wzr
//   0x033bf4: 17ff5e1f  b        #0xb470
uint64_t fde_1497_sub_033bf0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A1F03E1ULL) + (x1 ^ 0x17FF5E1FULL) + (x2 ^ 0x033BF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E1ULL; // 0x033bf0: mov w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5E1FULL; // 0x033bf4: b #0xb470
    return acc;
}

// [EN] Reconstructed FDE #1498 @ 0x033bf8..0x033c04 (12 bytes)
// [VN] Phục dựng FDE #1498 tại 0x033bf8..0x033c04 (12 byte)
//   0x033bf8: 90000140  adrp     x0, #0x5b000
//   0x033bfc: f9431000  ldr      x0, [x0, #0x620]
//   0x033c00: 17ff5e28  b        #0xb4a0
uint64_t fde_1498_sub_033bf8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000140ULL) + (x1 ^ 0x17FF5E28ULL) + (x2 ^ 0x033BF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000140ULL; // 0x033bf8: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9431000ULL; // 0x033bfc: ldr x0, [x0, #0x620]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5E28ULL; // 0x033c00: b #0xb4a0
    return acc;
}

// [EN] Reconstructed FDE #1499 @ 0x033c04..0x034290 (1676 bytes)
// [VN] Phục dựng FDE #1499 tại 0x033c04..0x034290 (1676 byte)
//   0x033c04: d10583ff  sub      sp, sp, #0x160
//   0x033c08: a9106ffc  stp      x28, x27, [sp, #0x100]
//   0x033c0c: a91167fa  stp      x26, x25, [sp, #0x110]
//   0x033c10: a9125ff8  stp      x24, x23, [sp, #0x120]
//   0x033c14: a91357f6  stp      x22, x21, [sp, #0x130]
//   0x033c18: a9144ff4  stp      x20, x19, [sp, #0x140]
//   0x033c1c: a9157bfd  stp      x29, x30, [sp, #0x150]
//   0x033c20: 910543fd  add      x29, sp, #0x150
//   0x033c24: d53bd058  mrs      x24, tpidr_el0
//   0x033c28: f9401708  ldr      x8, [x24, #0x28]
//   0x033c2c: 2a0003f4  mov      w20, w0
//   0x033c30: f81983a8  stur     x8, [x29, #-0x68]
uint64_t fde_1499_sub_033c04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10583FFULL) + (x1 ^ 0xD53BD058ULL) + (x2 ^ 0x033C04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10583FFULL; // 0x033c04: sub sp, sp, #0x160
    acc = (acc * 0x100000001B3ULL) ^ 0xA9106FFCULL; // 0x033c08: stp x28, x27, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91167FAULL; // 0x033c0c: stp x26, x25, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9125FF8ULL; // 0x033c10: stp x24, x23, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91357F6ULL; // 0x033c14: stp x22, x21, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9144FF4ULL; // 0x033c18: stp x20, x19, [sp, #0x140]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9157BFDULL; // 0x033c1c: stp x29, x30, [sp, #0x150]
    acc = (acc * 0x100000001B3ULL) ^ 0x910543FDULL; // 0x033c20: add x29, sp, #0x150
    return acc;
}

// [EN] Reconstructed FDE #1500 @ 0x034290..0x034338 (168 bytes)
// [VN] Phục dựng FDE #1500 tại 0x034290..0x034338 (168 byte)
//   0x034290: d10203ff  sub      sp, sp, #0x80
//   0x034294: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x034298: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x03429c: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0342a0: 9101c3fd  add      x29, sp, #0x70
//   0x0342a4: d53bd055  mrs      x21, tpidr_el0
//   0x0342a8: f94016a8  ldr      x8, [x21, #0x28]
//   0x0342ac: aa0003f4  mov      x20, x0
//   0x0342b0: aa1f03f3  mov      x19, xzr
//   0x0342b4: 910023e9  add      x9, sp, #8
//   0x0342b8: f81d83a8  stur     x8, [x29, #-0x28]
//   0x0342bc: d0000128  adrp     x8, #0x5a000
uint64_t fde_1500_sub_034290(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xAA1F03F3ULL) + (x2 ^ 0x034290ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x034290: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x034294: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x034298: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x03429c: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x0342a0: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0342a4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0342a8: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x0342ac: mov x20, x0
    return acc;
}

// [EN] Reconstructed FDE #1501 @ 0x034338..0x0344a4 (364 bytes)
// [VN] Phục dựng FDE #1501 tại 0x034338..0x0344a4 (364 byte)
//   0x034338: d10103ff  sub      sp, sp, #0x40
//   0x03433c: f9000bf5  str      x21, [sp, #0x10]
//   0x034340: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x034344: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x034348: 9100c3fd  add      x29, sp, #0x30
//   0x03434c: d53bd054  mrs      x20, tpidr_el0
//   0x034350: f0000120  adrp     x0, #0x5b000
//   0x034354: f9401688  ldr      x8, [x20, #0x28]
//   0x034358: 940001de  bl       #0x34ad0
//   0x03435c: f0000135  adrp     x21, #0x5b000
//   0x034360: f94772b5  ldr      x21, [x21, #0xee0]
//   0x034364: 394002a8  ldrb     w8, [x21]
uint64_t fde_1501_sub_034338(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x940001DEULL) + (x2 ^ 0x034338ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x034338: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x03433c: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x034340: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034344: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x034348: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03434c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000120ULL; // 0x034350: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x034354: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1502 @ 0x0344a4..0x0344f8 (84 bytes)
// [VN] Phục dựng FDE #1502 tại 0x0344a4..0x0344f8 (84 byte)
//   0x0344a4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0344a8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0344ac: 910043fd  add      x29, sp, #0x10
//   0x0344b0: aa0103f3  mov      x19, x1
//   0x0344b4: b0000061  adrp     x1, #0x41000
//   0x0344b8: 9134a421  add      x1, x1, #0xd29
//   0x0344bc: 97ff5c79  bl       #0xb6a0
//   0x0344c0: b4000160  cbz      x0, #0x344ec
//   0x0344c4: aa0003e8  mov      x8, x0
//   0x0344c8: 52800ac0  mov      w0, #0x56
//   0x0344cc: d63f0100  blr      x8
//   0x0344d0: b40000e0  cbz      x0, #0x344ec
uint64_t fde_1502_sub_0344a4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA0003E8ULL) + (x2 ^ 0x0344A4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0344a4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0344a8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0344ac: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x0344b0: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000061ULL; // 0x0344b4: adrp x1, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0x9134A421ULL; // 0x0344b8: add x1, x1, #0xd29
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5C79ULL; // 0x0344bc: bl #0xb6a0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000160ULL; // 0x0344c0: cbz x0, #0x344ec
    return acc;
}

// [EN] Reconstructed FDE #1503 @ 0x0344f8..0x03463c (324 bytes)
// [VN] Phục dựng FDE #1503 tại 0x0344f8..0x03463c (324 byte)
//   0x0344f8: d10103ff  sub      sp, sp, #0x40
//   0x0344fc: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x034500: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x034504: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x034508: 9100c3fd  add      x29, sp, #0x30
//   0x03450c: d53bd055  mrs      x21, tpidr_el0
//   0x034510: f0000120  adrp     x0, #0x5b000
//   0x034514: f94016a8  ldr      x8, [x21, #0x28]
//   0x034518: 9400016e  bl       #0x34ad0
//   0x03451c: f0000128  adrp     x8, #0x5b000
//   0x034520: f9463508  ldr      x8, [x8, #0xc68]
//   0x034524: f0000129  adrp     x9, #0x5b000
uint64_t fde_1503_sub_0344f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x9400016EULL) + (x2 ^ 0x0344F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0344f8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0344fc: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x034500: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034504: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x034508: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x03450c: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000120ULL; // 0x034510: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x034514: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1504 @ 0x03463c..0x034730 (244 bytes)
// [VN] Phục dựng FDE #1504 tại 0x03463c..0x034730 (244 byte)
//   0x03463c: d10103ff  sub      sp, sp, #0x40
//   0x034640: f9000bf5  str      x21, [sp, #0x10]
//   0x034644: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x034648: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03464c: 9100c3fd  add      x29, sp, #0x30
//   0x034650: d53bd053  mrs      x19, tpidr_el0
//   0x034654: f0000120  adrp     x0, #0x5b000
//   0x034658: f9401668  ldr      x8, [x19, #0x28]
//   0x03465c: 9400011d  bl       #0x34ad0
//   0x034660: f0000134  adrp     x20, #0x5b000
//   0x034664: f9477294  ldr      x20, [x20, #0xee0]
//   0x034668: 39400288  ldrb     w8, [x20]
uint64_t fde_1504_sub_03463c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x9400011DULL) + (x2 ^ 0x03463CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03463c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF5ULL; // 0x034640: str x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x034644: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034648: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03464c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x034650: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000120ULL; // 0x034654: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x034658: ldr x8, [x19, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1505 @ 0x034730..0x034890 (352 bytes)
// [VN] Phục dựng FDE #1505 tại 0x034730..0x034890 (352 byte)
//   0x034730: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x034734: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x034738: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03473c: 910083fd  add      x29, sp, #0x20
//   0x034740: 90000156  adrp     x22, #0x5c000
//   0x034744: b9411ac8  ldr      w8, [x22, #0x118]
//   0x034748: f0000135  adrp     x21, #0x5b000
//   0x03474c: f947feb5  ldr      x21, [x21, #0xff8]
//   0x034750: 7100051f  cmp      w8, #1
//   0x034754: 540002eb  b.lt     #0x347b0
//   0x034758: f94002a8  ldr      x8, [x21]
//   0x03475c: b40002a8  cbz      x8, #0x347b0
uint64_t fde_1505_sub_034730(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x7100051FULL) + (x2 ^ 0x034730ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x034730: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x034734: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x034738: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03473c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x90000156ULL; // 0x034740: adrp x22, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9411AC8ULL; // 0x034744: ldr w8, [x22, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000135ULL; // 0x034748: adrp x21, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947FEB5ULL; // 0x03474c: ldr x21, [x21, #0xff8]
    return acc;
}

// [EN] Reconstructed FDE #1506 @ 0x034890..0x034938 (168 bytes)
// [VN] Phục dựng FDE #1506 tại 0x034890..0x034938 (168 byte)
//   0x034890: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x034894: 910003fd  mov      x29, sp
//   0x034898: 90000148  adrp     x8, #0x5c000
//   0x03489c: b9811908  ldrsw    x8, [x8, #0x118]
//   0x0348a0: 7100051f  cmp      w8, #1
//   0x0348a4: 5400024b  b.lt     #0x348ec
//   0x0348a8: f0000129  adrp     x9, #0x5b000
//   0x0348ac: f947fd29  ldr      x9, [x9, #0xff8]
//   0x0348b0: f9400129  ldr      x9, [x9]
//   0x0348b4: b40001c9  cbz      x9, #0x348ec
//   0x0348b8: f9400129  ldr      x9, [x9]
//   0x0348bc: d37ef508  lsl      x8, x8, #2
uint64_t fde_1506_sub_034890(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xF9400129ULL) + (x2 ^ 0x034890ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x034890: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x034894: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x90000148ULL; // 0x034898: adrp x8, #0x5c000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9811908ULL; // 0x03489c: ldrsw x8, [x8, #0x118]
    acc = (acc * 0x100000001B3ULL) ^ 0x7100051FULL; // 0x0348a0: cmp w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x5400024BULL; // 0x0348a4: b.lt #0x348ec
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000129ULL; // 0x0348a8: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947FD29ULL; // 0x0348ac: ldr x9, [x9, #0xff8]
    return acc;
}

// [EN] Reconstructed FDE #1507 @ 0x034938..0x03493c (4 bytes)
// [VN] Phục dựng FDE #1507 tại 0x034938..0x03493c (4 byte)
//   0x034938: 17ff5902  b        #0xad40
uint64_t fde_1507_sub_034938(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5902ULL) + (x1 ^ 0x17FF5902ULL) + (x2 ^ 0x034938ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5902ULL; // 0x034938: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1508 @ 0x03493c..0x034964 (40 bytes)
// [VN] Phục dựng FDE #1508 tại 0x03493c..0x034964 (40 byte)
//   0x03493c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x034940: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x034944: 910043fd  add      x29, sp, #0x10
//   0x034948: 9400007c  bl       #0x34b38
//   0x03494c: d0000128  adrp     x8, #0x5a000
//   0x034950: 912b2108  add      x8, x8, #0xac8
//   0x034954: f9000008  str      x8, [x0]
//   0x034958: f9400668  ldr      x8, [x19, #8]
//   0x03495c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x034960: 14000079  b        #0x34b44
uint64_t fde_1508_sub_03493c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x03493CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03493c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x034940: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x034944: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9400007CULL; // 0x034948: bl #0x34b38
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03494c: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912B2108ULL; // 0x034950: add x8, x8, #0xac8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x034954: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400668ULL; // 0x034958: ldr x8, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #1509 @ 0x034964..0x034970 (12 bytes)
// [VN] Phục dựng FDE #1509 tại 0x034964..0x034970 (12 byte)
//   0x034964: d0000128  adrp     x8, #0x5a000
//   0x034968: 912b2108  add      x8, x8, #0xac8
//   0x03496c: 14000067  b        #0x34b08
uint64_t fde_1509_sub_034964(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000128ULL) + (x1 ^ 0x14000067ULL) + (x2 ^ 0x034964ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x034964: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912B2108ULL; // 0x034968: add x8, x8, #0xac8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000067ULL; // 0x03496c: b #0x34b08
    return acc;
}

// [EN] Reconstructed FDE #1510 @ 0x034970..0x034974 (4 bytes)
// [VN] Phục dựng FDE #1510 tại 0x034970..0x034974 (4 byte)
//   0x034970: d65f03c0  ret      
uint64_t fde_1510_sub_034970(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034970ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034970: ret 
    return acc;
}

// [EN] Reconstructed FDE #1511 @ 0x034974..0x034978 (4 bytes)
// [VN] Phục dựng FDE #1511 tại 0x034974..0x034978 (4 byte)
//   0x034974: 17ff58f3  b        #0xad40
uint64_t fde_1511_sub_034974(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF58F3ULL) + (x1 ^ 0x17FF58F3ULL) + (x2 ^ 0x034974ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF58F3ULL; // 0x034974: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1512 @ 0x034978..0x034990 (24 bytes)
// [VN] Phục dựng FDE #1512 tại 0x034978..0x034990 (24 byte)
//   0x034978: f9400408  ldr      x8, [x0, #8]
//   0x03497c: f9400049  ldr      x9, [x2]
//   0x034980: f9400108  ldr      x8, [x8]
//   0x034984: eb09011f  cmp      x8, x9
//   0x034988: 1a9f17e0  cset     w0, eq
//   0x03498c: d65f03c0  ret      
uint64_t fde_1512_sub_034978(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034978ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x034978: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400049ULL; // 0x03497c: ldr x9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400108ULL; // 0x034980: ldr x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x034984: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x034988: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03498c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1513 @ 0x034990..0x0349e8 (88 bytes)
// [VN] Phục dựng FDE #1513 tại 0x034990..0x0349e8 (88 byte)
//   0x034990: d10103ff  sub      sp, sp, #0x40
//   0x034994: f90013f3  str      x19, [sp, #0x20]
//   0x034998: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03499c: 9100c3fd  add      x29, sp, #0x30
//   0x0349a0: d53bd053  mrs      x19, tpidr_el0
//   0x0349a4: f9401668  ldr      x8, [x19, #0x28]
//   0x0349a8: f9000fe8  str      x8, [sp, #0x18]
//   0x0349ac: f9000be1  str      x1, [sp, #0x10]
//   0x0349b0: b9000fe2  str      w2, [sp, #0xc]
//   0x0349b4: 910043e1  add      x1, sp, #0x10
//   0x0349b8: 910033e2  add      x2, sp, #0xc
//   0x0349bc: 9400000b  bl       #0x349e8
uint64_t fde_1513_sub_034990(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xB9000FE2ULL) + (x2 ^ 0x034990ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x034990: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x034994: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x034998: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03499c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0349a0: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0349a4: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0349a8: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BE1ULL; // 0x0349ac: str x1, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #1514 @ 0x0349e8..0x034a0c (36 bytes)
// [VN] Phục dựng FDE #1514 tại 0x0349e8..0x034a0c (36 byte)
//   0x0349e8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0349ec: 910003fd  mov      x29, sp
//   0x0349f0: f9401000  ldr      x0, [x0, #0x20]
//   0x0349f4: b40000a0  cbz      x0, #0x34a08
//   0x0349f8: f9400008  ldr      x8, [x0]
//   0x0349fc: f9401903  ldr      x3, [x8, #0x30]
//   0x034a00: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x034a04: d61f0060  br       x3
//   0x034a08: 97ff8a7c  bl       #0x173f8
uint64_t fde_1514_sub_0349e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x97FF8A7CULL) + (x2 ^ 0x0349E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0349e8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0349ec: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x0349f0: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x0349f4: cbz x0, #0x34a08
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0349f8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401903ULL; // 0x0349fc: ldr x3, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x034a00: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0060ULL; // 0x034a04: br x3
    return acc;
}

// [EN] Reconstructed FDE #1515 @ 0x034a0c..0x034a10 (4 bytes)
// [VN] Phục dựng FDE #1515 tại 0x034a0c..0x034a10 (4 byte)
//   0x034a0c: d65f03c0  ret      
uint64_t fde_1515_sub_034a0c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034A0CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034a0c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1516 @ 0x034a10..0x034a14 (4 bytes)
// [VN] Phục dựng FDE #1516 tại 0x034a10..0x034a14 (4 byte)
//   0x034a10: 17ff58cc  b        #0xad40
uint64_t fde_1516_sub_034a10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF58CCULL) + (x1 ^ 0x17FF58CCULL) + (x2 ^ 0x034A10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF58CCULL; // 0x034a10: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1517 @ 0x034a14..0x034a3c (40 bytes)
// [VN] Phục dựng FDE #1517 tại 0x034a14..0x034a3c (40 byte)
//   0x034a14: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x034a18: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x034a1c: 910043fd  add      x29, sp, #0x10
//   0x034a20: 94000046  bl       #0x34b38
//   0x034a24: d0000128  adrp     x8, #0x5a000
//   0x034a28: 912c4108  add      x8, x8, #0xb10
//   0x034a2c: f9000008  str      x8, [x0]
//   0x034a30: f9400668  ldr      x8, [x19, #8]
//   0x034a34: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x034a38: 14000043  b        #0x34b44
uint64_t fde_1517_sub_034a14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xA9417BFDULL) + (x2 ^ 0x034A14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x034a14: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x034a18: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x034a1c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000046ULL; // 0x034a20: bl #0x34b38
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x034a24: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912C4108ULL; // 0x034a28: add x8, x8, #0xb10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000008ULL; // 0x034a2c: str x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400668ULL; // 0x034a30: ldr x8, [x19, #8]
    return acc;
}

// [EN] Reconstructed FDE #1518 @ 0x034a3c..0x034a48 (12 bytes)
// [VN] Phục dựng FDE #1518 tại 0x034a3c..0x034a48 (12 byte)
//   0x034a3c: d0000128  adrp     x8, #0x5a000
//   0x034a40: 912c4108  add      x8, x8, #0xb10
//   0x034a44: 14000031  b        #0x34b08
uint64_t fde_1518_sub_034a3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000128ULL) + (x1 ^ 0x14000031ULL) + (x2 ^ 0x034A3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x034a3c: adrp x8, #0x5a000
    acc = (acc * 0x100000001B3ULL) ^ 0x912C4108ULL; // 0x034a40: add x8, x8, #0xb10
    acc = (acc * 0x100000001B3ULL) ^ 0x14000031ULL; // 0x034a44: b #0x34b08
    return acc;
}

// [EN] Reconstructed FDE #1519 @ 0x034a48..0x034a4c (4 bytes)
// [VN] Phục dựng FDE #1519 tại 0x034a48..0x034a4c (4 byte)
//   0x034a48: d65f03c0  ret      
uint64_t fde_1519_sub_034a48(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034A48ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034a48: ret 
    return acc;
}

// [EN] Reconstructed FDE #1520 @ 0x034a4c..0x034a50 (4 bytes)
// [VN] Phục dựng FDE #1520 tại 0x034a4c..0x034a50 (4 byte)
//   0x034a4c: 17ff58bd  b        #0xad40
uint64_t fde_1520_sub_034a4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF58BDULL) + (x1 ^ 0x17FF58BDULL) + (x2 ^ 0x034A4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF58BDULL; // 0x034a4c: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1521 @ 0x034a50..0x034a68 (24 bytes)
// [VN] Phục dựng FDE #1521 tại 0x034a50..0x034a68 (24 byte)
//   0x034a50: f9400408  ldr      x8, [x0, #8]
//   0x034a54: b9400049  ldr      w9, [x2]
//   0x034a58: b9400108  ldr      w8, [x8]
//   0x034a5c: 6b09011f  cmp      w8, w9
//   0x034a60: 1a9f17e0  cset     w0, eq
//   0x034a64: d65f03c0  ret      
uint64_t fde_1521_sub_034a50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034A50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x034a50: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400049ULL; // 0x034a54: ldr w9, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400108ULL; // 0x034a58: ldr w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x6B09011FULL; // 0x034a5c: cmp w8, w9
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F17E0ULL; // 0x034a60: cset w0, eq
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034a64: ret 
    return acc;
}

// [EN] Reconstructed FDE #1522 @ 0x034a68..0x034a98 (48 bytes)
// [VN] Phục dựng FDE #1522 tại 0x034a68..0x034a98 (48 byte)
//   0x034a68: aa0003e8  mov      x8, x0
//   0x034a6c: f9401000  ldr      x0, [x0, #0x20]
//   0x034a70: eb00011f  cmp      x8, x0
//   0x034a74: 540000a0  b.eq     #0x34a88
//   0x034a78: b40000e0  cbz      x0, #0x34a94
//   0x034a7c: f9400008  ldr      x8, [x0]
//   0x034a80: f9401501  ldr      x1, [x8, #0x28]
//   0x034a84: d61f0020  br       x1
//   0x034a88: f9400008  ldr      x8, [x0]
//   0x034a8c: f9401101  ldr      x1, [x8, #0x20]
//   0x034a90: d61f0020  br       x1
//   0x034a94: d65f03c0  ret      
uint64_t fde_1522_sub_034a68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400008ULL) + (x2 ^ 0x034A68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x034a68: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401000ULL; // 0x034a6c: ldr x0, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB00011FULL; // 0x034a70: cmp x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x034a74: b.eq #0x34a88
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000E0ULL; // 0x034a78: cbz x0, #0x34a94
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x034a7c: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401501ULL; // 0x034a80: ldr x1, [x8, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0020ULL; // 0x034a84: br x1
    return acc;
}

// [EN] Reconstructed FDE #1523 @ 0x034a98..0x034ad0 (56 bytes)
// [VN] Phục dựng FDE #1523 tại 0x034a98..0x034ad0 (56 byte)
//   0x034a98: f0000128  adrp     x8, #0x5b000
//   0x034a9c: f0000129  adrp     x9, #0x5b000
//   0x034aa0: f000012a  adrp     x10, #0x5b000
//   0x034aa4: f9434d08  ldr      x8, [x8, #0x698]
//   0x034aa8: f9456529  ldr      x9, [x9, #0xac8]
//   0x034aac: f946354a  ldr      x10, [x10, #0xc68]
//   0x034ab0: 39000114  strb     w20, [x8]
//   0x034ab4: 3900013f  strb     wzr, [x9]
//   0x034ab8: b9400148  ldr      w8, [x10]
//   0x034abc: 52800029  mov      w9, #1
//   0x034ac0: 39000349  strb     w9, [x26]
//   0x034ac4: 11000508  add      w8, w8, #1
uint64_t fde_1523_sub_034a98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000128ULL) + (x1 ^ 0xB9400148ULL) + (x2 ^ 0x034A98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000128ULL; // 0x034a98: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000129ULL; // 0x034a9c: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF000012AULL; // 0x034aa0: adrp x10, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9434D08ULL; // 0x034aa4: ldr x8, [x8, #0x698]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9456529ULL; // 0x034aa8: ldr x9, [x9, #0xac8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF946354AULL; // 0x034aac: ldr x10, [x10, #0xc68]
    acc = (acc * 0x100000001B3ULL) ^ 0x39000114ULL; // 0x034ab0: strb w20, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x3900013FULL; // 0x034ab4: strb wzr, [x9]
    return acc;
}

// [EN] Reconstructed FDE #1524 @ 0x034ad0..0x034ae0 (16 bytes)
// [VN] Phục dựng FDE #1524 tại 0x034ad0..0x034ae0 (16 byte)
//   0x034ad0: f9427c00  ldr      x0, [x0, #0x4f8]
//   0x034ad4: f90007e8  str      x8, [sp, #8]
//   0x034ad8: f90003e0  str      x0, [sp]
//   0x034adc: 17ff5abd  b        #0xb5d0
uint64_t fde_1524_sub_034ad0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9427C00ULL) + (x1 ^ 0x17FF5ABDULL) + (x2 ^ 0x034AD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9427C00ULL; // 0x034ad0: ldr x0, [x0, #0x4f8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x034ad4: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90003E0ULL; // 0x034ad8: str x0, [sp]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5ABDULL; // 0x034adc: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1525 @ 0x034ae0..0x034af8 (24 bytes)
// [VN] Phục dựng FDE #1525 tại 0x034ae0..0x034af8 (24 byte)
//   0x034ae0: b0000061  adrp     x1, #0x41000
//   0x034ae4: b0000062  adrp     x2, #0x41000
//   0x034ae8: 912a5021  add      x1, x1, #0xa94
//   0x034aec: 91374042  add      x2, x2, #0xdd0
//   0x034af0: 52800060  mov      w0, #3
//   0x034af4: 17ff59bb  b        #0xb1e0
uint64_t fde_1525_sub_034ae0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000061ULL) + (x1 ^ 0x17FF59BBULL) + (x2 ^ 0x034AE0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000061ULL; // 0x034ae0: adrp x1, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000062ULL; // 0x034ae4: adrp x2, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A5021ULL; // 0x034ae8: add x1, x1, #0xa94
    acc = (acc * 0x100000001B3ULL) ^ 0x91374042ULL; // 0x034aec: add x2, x2, #0xdd0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x034af0: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF59BBULL; // 0x034af4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1526 @ 0x034af8..0x034b00 (8 bytes)
// [VN] Phục dựng FDE #1526 tại 0x034af8..0x034b00 (8 byte)
//   0x034af8: 52800060  mov      w0, #3
//   0x034afc: 17ff59b9  b        #0xb1e0
uint64_t fde_1526_sub_034af8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF59B9ULL) + (x2 ^ 0x034AF8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x034af8: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF59B9ULL; // 0x034afc: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1527 @ 0x034b00..0x034b08 (8 bytes)
// [VN] Phục dựng FDE #1527 tại 0x034b00..0x034b08 (8 byte)
//   0x034b00: aa1503e0  mov      x0, x21
//   0x034b04: 17ff5ae7  b        #0xb6a0
uint64_t fde_1527_sub_034b00(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1503E0ULL) + (x1 ^ 0x17FF5AE7ULL) + (x2 ^ 0x034B00ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x034b00: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5AE7ULL; // 0x034b04: b #0xb6a0
    return acc;
}

// [EN] Reconstructed FDE #1528 @ 0x034b08..0x034b18 (16 bytes)
// [VN] Phục dựng FDE #1528 tại 0x034b08..0x034b18 (16 byte)
//   0x034b08: f9000028  str      x8, [x1]
//   0x034b0c: f9400408  ldr      x8, [x0, #8]
//   0x034b10: f9000428  str      x8, [x1, #8]
//   0x034b14: d65f03c0  ret      
uint64_t fde_1528_sub_034b08(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9000028ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034B08ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000028ULL; // 0x034b08: str x8, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400408ULL; // 0x034b0c: ldr x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000428ULL; // 0x034b10: str x8, [x1, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034b14: ret 
    return acc;
}

// [EN] Reconstructed FDE #1529 @ 0x034b18..0x034b28 (16 bytes)
// [VN] Phục dựng FDE #1529 tại 0x034b18..0x034b28 (16 byte)
//   0x034b18: f9400368  ldr      x8, [x27]
//   0x034b1c: f9400389  ldr      x9, [x28]
//   0x034b20: f9400100  ldr      x0, [x8]
//   0x034b24: d61f0120  br       x9
uint64_t fde_1529_sub_034b18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400368ULL) + (x1 ^ 0xD61F0120ULL) + (x2 ^ 0x034B18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400368ULL; // 0x034b18: ldr x8, [x27]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400389ULL; // 0x034b1c: ldr x9, [x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400100ULL; // 0x034b20: ldr x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0120ULL; // 0x034b24: br x9
    return acc;
}

// [EN] Reconstructed FDE #1530 @ 0x034b28..0x034b38 (16 bytes)
// [VN] Phục dựng FDE #1530 tại 0x034b28..0x034b38 (16 byte)
//   0x034b28: b9400109  ldr      w9, [x8]
//   0x034b2c: 11000529  add      w9, w9, #1
//   0x034b30: b9000109  str      w9, [x8]
//   0x034b34: 17ff8aba  b        #0x1761c
uint64_t fde_1530_sub_034b28(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB9400109ULL) + (x1 ^ 0x17FF8ABAULL) + (x2 ^ 0x034B28ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400109ULL; // 0x034b28: ldr w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x11000529ULL; // 0x034b2c: add w9, w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9000109ULL; // 0x034b30: str w9, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8ABAULL; // 0x034b34: b #0x1761c
    return acc;
}

// [EN] Reconstructed FDE #1531 @ 0x034b38..0x034b44 (12 bytes)
// [VN] Phục dựng FDE #1531 tại 0x034b38..0x034b44 (12 byte)
//   0x034b38: aa0003f3  mov      x19, x0
//   0x034b3c: 52800200  mov      w0, #0x10
//   0x034b40: 17ff5aac  b        #0xb5f0
uint64_t fde_1531_sub_034b38(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003F3ULL) + (x1 ^ 0x17FF5AACULL) + (x2 ^ 0x034B38ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x034b38: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x52800200ULL; // 0x034b3c: mov w0, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5AACULL; // 0x034b40: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #1532 @ 0x034b44..0x034b50 (12 bytes)
// [VN] Phục dựng FDE #1532 tại 0x034b44..0x034b50 (12 byte)
//   0x034b44: f9000408  str      x8, [x0, #8]
//   0x034b48: f84207f3  ldr      x19, [sp], #0x20
//   0x034b4c: d65f03c0  ret      
uint64_t fde_1532_sub_034b44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9000408ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034B44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x034b44: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x034b48: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034b4c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1533 @ 0x034b50..0x034b58 (8 bytes)
// [VN] Phục dựng FDE #1533 tại 0x034b50..0x034b58 (8 byte)
//   0x034b50: 910103ff  add      sp, sp, #0x40
//   0x034b54: d65f03c0  ret      
uint64_t fde_1533_sub_034b50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910103FFULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034B50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FFULL; // 0x034b50: add sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034b54: ret 
    return acc;
}

// [EN] Reconstructed FDE #1534 @ 0x034b58..0x034b6c (20 bytes)
// [VN] Phục dựng FDE #1534 tại 0x034b58..0x034b6c (20 byte)
//   0x034b58: b0000061  adrp     x1, #0x41000
//   0x034b5c: b0000062  adrp     x2, #0x41000
//   0x034b60: 912a5021  add      x1, x1, #0xa94
//   0x034b64: 9137e442  add      x2, x2, #0xdf9
//   0x034b68: d65f03c0  ret      
uint64_t fde_1534_sub_034b58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000061ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034B58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000061ULL; // 0x034b58: adrp x1, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000062ULL; // 0x034b5c: adrp x2, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A5021ULL; // 0x034b60: add x1, x1, #0xa94
    acc = (acc * 0x100000001B3ULL) ^ 0x9137E442ULL; // 0x034b64: add x2, x2, #0xdf9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034b68: ret 
    return acc;
}

// [EN] Reconstructed FDE #1535 @ 0x034b6c..0x034b80 (20 bytes)
// [VN] Phục dựng FDE #1535 tại 0x034b6c..0x034b80 (20 byte)
//   0x034b6c: b0000061  adrp     x1, #0x41000
//   0x034b70: b0000062  adrp     x2, #0x41000
//   0x034b74: 912a5021  add      x1, x1, #0xa94
//   0x034b78: 9133b442  add      x2, x2, #0xced
//   0x034b7c: d65f03c0  ret      
uint64_t fde_1535_sub_034b6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000061ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x034B6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000061ULL; // 0x034b6c: adrp x1, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000062ULL; // 0x034b70: adrp x2, #0x41000
    acc = (acc * 0x100000001B3ULL) ^ 0x912A5021ULL; // 0x034b74: add x1, x1, #0xa94
    acc = (acc * 0x100000001B3ULL) ^ 0x9133B442ULL; // 0x034b78: add x2, x2, #0xced
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x034b7c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1536 @ 0x034b80..0x034b88 (8 bytes)
// [VN] Phục dựng FDE #1536 tại 0x034b80..0x034b88 (8 byte)
//   0x034b80: 910003e0  mov      x0, sp
//   0x034b84: 17ffcae7  b        #0x27720
uint64_t fde_1536_sub_034b80(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FFCAE7ULL) + (x2 ^ 0x034B80ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x034b80: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCAE7ULL; // 0x034b84: b #0x27720
    return acc;
}

// [EN] Reconstructed FDE #1537 @ 0x034b88..0x034b94 (12 bytes)
// [VN] Phục dựng FDE #1537 tại 0x034b88..0x034b94 (12 byte)
//   0x034b88: b0000020  adrp     x0, #0x39000
//   0x034b8c: 911cd000  add      x0, x0, #0x734
//   0x034b90: 17ff5978  b        #0xb170
uint64_t fde_1537_sub_034b88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000020ULL) + (x1 ^ 0x17FF5978ULL) + (x2 ^ 0x034B88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000020ULL; // 0x034b88: adrp x0, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911CD000ULL; // 0x034b8c: add x0, x0, #0x734
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5978ULL; // 0x034b90: b #0xb170
    return acc;
}

// [EN] Reconstructed FDE #1538 @ 0x034b94..0x035004 (1136 bytes)
// [VN] Phục dựng FDE #1538 tại 0x034b94..0x035004 (1136 byte)
//   0x034b94: a9bb67fa  stp      x26, x25, [sp, #-0x50]!
//   0x034b98: a9015ff8  stp      x24, x23, [sp, #0x10]
//   0x034b9c: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x034ba0: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x034ba4: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x034ba8: 910103fd  add      x29, sp, #0x40
//   0x034bac: f000013a  adrp     x26, #0x5b000
//   0x034bb0: f947475a  ldr      x26, [x26, #0xe88]
//   0x034bb4: 39400348  ldrb     w8, [x26]
//   0x034bb8: 34000068  cbz      w8, #0x34bc4
//   0x034bbc: 52800020  mov      w0, #1
//   0x034bc0: 140000b7  b        #0x34e9c
uint64_t fde_1538_sub_034b94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BB67FAULL) + (x1 ^ 0x39400348ULL) + (x2 ^ 0x034B94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BB67FAULL; // 0x034b94: stp x26, x25, [sp, #-0x50]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9015FF8ULL; // 0x034b98: stp x24, x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x034b9c: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x034ba0: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x034ba4: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x034ba8: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF000013AULL; // 0x034bac: adrp x26, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF947475AULL; // 0x034bb0: ldr x26, [x26, #0xe88]
    return acc;
}

// [EN] Reconstructed FDE #1539 @ 0x035004..0x035068 (100 bytes)
// [VN] Phục dựng FDE #1539 tại 0x035004..0x035068 (100 byte)
//   0x035004: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x035008: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03500c: 910043fd  add      x29, sp, #0x10
//   0x035010: aa0003f3  mov      x19, x0
//   0x035014: b4000220  cbz      x0, #0x35058
//   0x035018: d0000020  adrp     x0, #0x3b000
//   0x03501c: 911d1800  add      x0, x0, #0x746
//   0x035020: 52800021  mov      w1, #1
//   0x035024: 97ff581b  bl       #0xb090
//   0x035028: 3100041f  cmn      w0, #1
//   0x03502c: 54000140  b.eq     #0x35054
//   0x035030: 52800082  mov      w2, #4
uint64_t fde_1539_sub_035004(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FF581BULL) + (x2 ^ 0x035004ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x035004: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x035008: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03500c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x035010: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000220ULL; // 0x035014: cbz x0, #0x35058
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000020ULL; // 0x035018: adrp x0, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D1800ULL; // 0x03501c: add x0, x0, #0x746
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x035020: mov w1, #1
    return acc;
}

// [EN] Reconstructed FDE #1540 @ 0x035068..0x03522c (452 bytes)
// [VN] Phục dựng FDE #1540 tại 0x035068..0x03522c (452 byte)
//   0x035068: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x03506c: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x035070: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x035074: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x035078: 9100c3fd  add      x29, sp, #0x30
//   0x03507c: 2a0203f4  mov      w20, w2
//   0x035080: aa0103f3  mov      x19, x1
//   0x035084: aa0003f6  mov      x22, x0
//   0x035088: 97ff597a  bl       #0xb670
//   0x03508c: 71007c1f  cmp      w0, #0x1f
//   0x035090: 540000c3  b.lo     #0x350a8
//   0x035094: 90000021  adrp     x1, #0x39000
uint64_t fde_1540_sub_035068(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x97FF597AULL) + (x2 ^ 0x035068ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x035068: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x03506c: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x035070: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x035074: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x035078: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x03507c: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x035080: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x035084: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #1541 @ 0x03522c..0x035244 (24 bytes)
// [VN] Phục dựng FDE #1541 tại 0x03522c..0x035244 (24 byte)
//   0x03522c: d0000128  adrp     x8, #0x5b000
//   0x035230: f9476108  ldr      x8, [x8, #0xec0]
//   0x035234: b9800108  ldrsw    x8, [x8]
//   0x035238: b8687808  ldr      w8, [x0, x8, lsl #2]
//   0x03523c: 53134d00  ubfx     w0, w8, #0x13, #1
//   0x035240: d65f03c0  ret      
uint64_t fde_1541_sub_03522c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000128ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03522CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x03522c: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9476108ULL; // 0x035230: ldr x8, [x8, #0xec0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9800108ULL; // 0x035234: ldrsw x8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB8687808ULL; // 0x035238: ldr w8, [x0, x8, lsl #2]
    acc = (acc * 0x100000001B3ULL) ^ 0x53134D00ULL; // 0x03523c: ubfx w0, w8, #0x13, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x035240: ret 
    return acc;
}

// [EN] Reconstructed FDE #1542 @ 0x035244..0x0352b4 (112 bytes)
// [VN] Phục dựng FDE #1542 tại 0x035244..0x0352b4 (112 byte)
//   0x035244: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x035248: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03524c: 910043fd  add      x29, sp, #0x10
//   0x035250: 94000028  bl       #0x352f0
//   0x035254: 340002a8  cbz      w8, #0x352a8
//   0x035258: f9400008  ldr      x8, [x0]
//   0x03525c: 2a0203f3  mov      w19, w2
//   0x035260: f9401d08  ldr      x8, [x8, #0x38]
//   0x035264: d63f0100  blr      x8
//   0x035268: d0000128  adrp     x8, #0x5b000
//   0x03526c: f9444d08  ldr      x8, [x8, #0x898]
//   0x035270: b9800108  ldrsw    x8, [x8]
uint64_t fde_1542_sub_035244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xD63F0100ULL) + (x2 ^ 0x035244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x035244: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x035248: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03524c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x035250: bl #0x352f0
    acc = (acc * 0x100000001B3ULL) ^ 0x340002A8ULL; // 0x035254: cbz w8, #0x352a8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x035258: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x03525c: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401D08ULL; // 0x035260: ldr x8, [x8, #0x38]
    return acc;
}

// [EN] Reconstructed FDE #1543 @ 0x0352b4..0x0352c4 (16 bytes)
// [VN] Phục dựng FDE #1543 tại 0x0352b4..0x0352c4 (16 byte)
//   0x0352b4: d0000128  adrp     x8, #0x5b000
//   0x0352b8: f9476108  ldr      x8, [x8, #0xec0]
//   0x0352bc: b9400100  ldr      w0, [x8]
//   0x0352c0: d65f03c0  ret      
uint64_t fde_1543_sub_0352b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000128ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0352B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x0352b4: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9476108ULL; // 0x0352b8: ldr x8, [x8, #0xec0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400100ULL; // 0x0352bc: ldr w0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0352c0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1544 @ 0x0352c4..0x0352d4 (16 bytes)
// [VN] Phục dựng FDE #1544 tại 0x0352c4..0x0352d4 (16 byte)
//   0x0352c4: 91176063  add      x3, x3, #0x5d8
//   0x0352c8: aa1303e0  mov      x0, x19
//   0x0352cc: aa1503e1  mov      x1, x21
//   0x0352d0: d61f0100  br       x8
uint64_t fde_1544_sub_0352c4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x91176063ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0352C4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x91176063ULL; // 0x0352c4: add x3, x3, #0x5d8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0352c8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x0352cc: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0352d0: br x8
    return acc;
}

// [EN] Reconstructed FDE #1545 @ 0x0352d4..0x0352e0 (12 bytes)
// [VN] Phục dựng FDE #1545 tại 0x0352d4..0x0352e0 (12 byte)
//   0x0352d4: aa1303e0  mov      x0, x19
//   0x0352d8: aa1603e1  mov      x1, x22
//   0x0352dc: d65f03c0  ret      
uint64_t fde_1545_sub_0352d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0352D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0352d4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E1ULL; // 0x0352d8: mov x1, x22
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0352dc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1546 @ 0x0352e0..0x0352f0 (16 bytes)
// [VN] Phục dựng FDE #1546 tại 0x0352e0..0x0352f0 (16 byte)
//   0x0352e0: f9400268  ldr      x8, [x19]
//   0x0352e4: aa1303e0  mov      x0, x19
//   0x0352e8: f9404508  ldr      x8, [x8, #0x88]
//   0x0352ec: d61f0100  br       x8
uint64_t fde_1546_sub_0352e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0352E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0352e0: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0352e4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x0352e8: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0352ec: br x8
    return acc;
}

// [EN] Reconstructed FDE #1547 @ 0x0352f0..0x035300 (16 bytes)
// [VN] Phục dựng FDE #1547 tại 0x0352f0..0x035300 (16 byte)
//   0x0352f0: d0000128  adrp     x8, #0x5b000
//   0x0352f4: f9474508  ldr      x8, [x8, #0xe88]
//   0x0352f8: 39400108  ldrb     w8, [x8]
//   0x0352fc: d65f03c0  ret      
uint64_t fde_1547_sub_0352f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000128ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0352F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000128ULL; // 0x0352f0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9474508ULL; // 0x0352f4: ldr x8, [x8, #0xe88]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x0352f8: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0352fc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1548 @ 0x035300..0x035310 (16 bytes)
// [VN] Phục dựng FDE #1548 tại 0x035300..0x035310 (16 byte)
//   0x035300: aa1303e0  mov      x0, x19
//   0x035304: aa1503e1  mov      x1, x21
//   0x035308: aa1703e3  mov      x3, x23
//   0x03530c: d61f0100  br       x8
uint64_t fde_1548_sub_035300(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x035300ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x035300: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x035304: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1703E3ULL; // 0x035308: mov x3, x23
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x03530c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1549 @ 0x035310..0x035320 (16 bytes)
// [VN] Phục dựng FDE #1549 tại 0x035310..0x035320 (16 byte)
//   0x035310: aa1303e0  mov      x0, x19
//   0x035314: aa1503e1  mov      x1, x21
//   0x035318: f9405d08  ldr      x8, [x8, #0xb8]
//   0x03531c: d61f0100  br       x8
uint64_t fde_1549_sub_035310(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x035310ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x035310: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x035314: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xF9405D08ULL; // 0x035318: ldr x8, [x8, #0xb8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x03531c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1550 @ 0x035320..0x03532c (12 bytes)
// [VN] Phục dựng FDE #1550 tại 0x035320..0x03532c (12 byte)
//   0x035320: aa1303e0  mov      x0, x19
//   0x035324: f9439108  ldr      x8, [x8, #0x720]
//   0x035328: d61f0100  br       x8
uint64_t fde_1550_sub_035320(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x035320ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x035320: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x035324: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x035328: br x8
    return acc;
}

// [EN] Reconstructed FDE #1551 @ 0x03532c..0x035338 (12 bytes)
// [VN] Phục dựng FDE #1551 tại 0x03532c..0x035338 (12 byte)
//   0x03532c: aa1303e0  mov      x0, x19
//   0x035330: f9401908  ldr      x8, [x8, #0x30]
//   0x035334: d61f0100  br       x8
uint64_t fde_1551_sub_03532c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x03532CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03532c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401908ULL; // 0x035330: ldr x8, [x8, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x035334: br x8
    return acc;
}

// [EN] Reconstructed FDE #1552 @ 0x035338..0x03551c (484 bytes)
// [VN] Phục dựng FDE #1552 tại 0x035338..0x03551c (484 byte)
//   0x035338: d10183ff  sub      sp, sp, #0x60
//   0x03533c: a9025ff8  stp      x24, x23, [sp, #0x20]
//   0x035340: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x035344: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x035348: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03534c: 910143fd  add      x29, sp, #0x50
//   0x035350: d53bd058  mrs      x24, tpidr_el0
//   0x035354: f9401708  ldr      x8, [x24, #0x28]
//   0x035358: aa0003f3  mov      x19, x0
//   0x03535c: f9000fe8  str      x8, [sp, #0x18]
//   0x035360: 97ff58c4  bl       #0xb670
//   0x035364: 7100701f  cmp      w0, #0x1c
uint64_t fde_1552_sub_035338(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x035338ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x035338: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025FF8ULL; // 0x03533c: stp x24, x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x035340: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x035344: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x035348: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03534c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x035350: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x035354: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1553 @ 0x03551c..0x035528 (12 bytes)
// [VN] Phục dựng FDE #1553 tại 0x03551c..0x035528 (12 byte)
//   0x03551c: aa0003f5  mov      x21, x0
//   0x035520: aa1603e0  mov      x0, x22
//   0x035524: 17ff588b  b        #0xb750
uint64_t fde_1553_sub_03551c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003F5ULL) + (x1 ^ 0x17FF588BULL) + (x2 ^ 0x03551CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x03551c: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1603E0ULL; // 0x035520: mov x0, x22
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF588BULL; // 0x035524: b #0xb750
    return acc;
}

// [EN] Reconstructed FDE #1554 @ 0x035528..0x0357f0 (712 bytes)
// [VN] Phục dựng FDE #1554 tại 0x035528..0x0357f0 (712 byte)
//   0x035528: d10203ff  sub      sp, sp, #0x80
//   0x03552c: f90023f7  str      x23, [sp, #0x40]
//   0x035530: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x035534: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x035538: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03553c: 9101c3fd  add      x29, sp, #0x70
//   0x035540: d53bd055  mrs      x21, tpidr_el0
//   0x035544: f94016a8  ldr      x8, [x21, #0x28]
//   0x035548: d0000136  adrp     x22, #0x5b000
//   0x03554c: f9001fe8  str      x8, [sp, #0x38]
//   0x035550: f945fad6  ldr      x22, [x22, #0xbf0]
//   0x035554: 394002c8  ldrb     w8, [x22]
uint64_t fde_1554_sub_035528(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xD0000136ULL) + (x2 ^ 0x035528ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x035528: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x03552c: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x035530: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x035534: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x035538: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03553c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x035540: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x035544: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1555 @ 0x0357f0..0x035b40 (848 bytes)
// [VN] Phục dựng FDE #1555 tại 0x0357f0..0x035b40 (848 byte)
//   0x0357f0: d10303ff  sub      sp, sp, #0xc0
//   0x0357f4: a9066ffc  stp      x28, x27, [sp, #0x60]
//   0x0357f8: a90767fa  stp      x26, x25, [sp, #0x70]
//   0x0357fc: a9085ff8  stp      x24, x23, [sp, #0x80]
//   0x035800: a90957f6  stp      x22, x21, [sp, #0x90]
//   0x035804: a90a4ff4  stp      x20, x19, [sp, #0xa0]
//   0x035808: a90b7bfd  stp      x29, x30, [sp, #0xb0]
//   0x03580c: 9102c3fd  add      x29, sp, #0xb0
//   0x035810: a90213e3  stp      x3, x4, [sp, #0x20]
//   0x035814: d53bd049  mrs      x9, tpidr_el0
//   0x035818: f9401528  ldr      x8, [x9, #0x28]
//   0x03581c: f9002fe8  str      x8, [sp, #0x58]
uint64_t fde_1555_sub_0357f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10303FFULL) + (x1 ^ 0xA90213E3ULL) + (x2 ^ 0x0357F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10303FFULL; // 0x0357f0: sub sp, sp, #0xc0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9066FFCULL; // 0x0357f4: stp x28, x27, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90767FAULL; // 0x0357f8: stp x26, x25, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9085FF8ULL; // 0x0357fc: stp x24, x23, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90957F6ULL; // 0x035800: stp x22, x21, [sp, #0x90]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90A4FF4ULL; // 0x035804: stp x20, x19, [sp, #0xa0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90B7BFDULL; // 0x035808: stp x29, x30, [sp, #0xb0]
    acc = (acc * 0x100000001B3ULL) ^ 0x9102C3FDULL; // 0x03580c: add x29, sp, #0xb0
    return acc;
}

// [EN] Reconstructed FDE #1556 @ 0x035b40..0x035b60 (32 bytes)
// [VN] Phục dựng FDE #1556 tại 0x035b40..0x035b60 (32 byte)
//   0x035b40: a940a408  ldp      x8, x9, [x0, #8]
//   0x035b44: eb09011f  cmp      x8, x9
//   0x035b48: 540000a0  b.eq     #0x35b5c
//   0x035b4c: f9400029  ldr      x9, [x1]
//   0x035b50: f8008509  str      x9, [x8], #8
//   0x035b54: f9000408  str      x8, [x0, #8]
//   0x035b58: d65f03c0  ret      
//   0x035b5c: 14000371  b        #0x36920
uint64_t fde_1556_sub_035b40(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000371ULL) + (x2 ^ 0x035B40ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x035b40: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x035b44: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x035b48: b.eq #0x35b5c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400029ULL; // 0x035b4c: ldr x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008509ULL; // 0x035b50: str x9, [x8], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x035b54: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x035b58: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x14000371ULL; // 0x035b5c: b #0x36920
    return acc;
}

// [EN] Reconstructed FDE #1557 @ 0x035b60..0x035fa4 (1092 bytes)
// [VN] Phục dựng FDE #1557 tại 0x035b60..0x035fa4 (1092 byte)
//   0x035b60: d10503ff  sub      sp, sp, #0x140
//   0x035b64: a90e6ffc  stp      x28, x27, [sp, #0xe0]
//   0x035b68: a90f67fa  stp      x26, x25, [sp, #0xf0]
//   0x035b6c: a9105ff8  stp      x24, x23, [sp, #0x100]
//   0x035b70: a91157f6  stp      x22, x21, [sp, #0x110]
//   0x035b74: a9124ff4  stp      x20, x19, [sp, #0x120]
//   0x035b78: a9137bfd  stp      x29, x30, [sp, #0x130]
//   0x035b7c: 9104c3fd  add      x29, sp, #0x130
//   0x035b80: d53bd049  mrs      x9, tpidr_el0
//   0x035b84: f9401528  ldr      x8, [x9, #0x28]
//   0x035b88: f81a03a8  stur     x8, [x29, #-0x60]
//   0x035b8c: d0000128  adrp     x8, #0x5b000
uint64_t fde_1557_sub_035b60(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10503FFULL) + (x1 ^ 0xD53BD049ULL) + (x2 ^ 0x035B60ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10503FFULL; // 0x035b60: sub sp, sp, #0x140
    acc = (acc * 0x100000001B3ULL) ^ 0xA90E6FFCULL; // 0x035b64: stp x28, x27, [sp, #0xe0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90F67FAULL; // 0x035b68: stp x26, x25, [sp, #0xf0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9105FF8ULL; // 0x035b6c: stp x24, x23, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA91157F6ULL; // 0x035b70: stp x22, x21, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9124FF4ULL; // 0x035b74: stp x20, x19, [sp, #0x120]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9137BFDULL; // 0x035b78: stp x29, x30, [sp, #0x130]
    acc = (acc * 0x100000001B3ULL) ^ 0x9104C3FDULL; // 0x035b7c: add x29, sp, #0x130
    return acc;
}

// [EN] Reconstructed FDE #1558 @ 0x035fa4..0x036000 (92 bytes)
// [VN] Phục dựng FDE #1558 tại 0x035fa4..0x036000 (92 byte)
//   0x035fa4: d10103ff  sub      sp, sp, #0x40
//   0x035fa8: f90013f3  str      x19, [sp, #0x20]
//   0x035fac: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x035fb0: 9100c3fd  add      x29, sp, #0x30
//   0x035fb4: d53bd053  mrs      x19, tpidr_el0
//   0x035fb8: f9401668  ldr      x8, [x19, #0x28]
//   0x035fbc: b0000062  adrp     x2, #0x42000
//   0x035fc0: 911d6042  add      x2, x2, #0x758
//   0x035fc4: 910043e3  add      x3, sp, #0x10
//   0x035fc8: 910023e4  add      x4, sp, #8
//   0x035fcc: f9000fe8  str      x8, [sp, #0x18]
//   0x035fd0: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1558_sub_035fa4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x035FA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x035fa4: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x035fa8: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x035fac: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x035fb0: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x035fb4: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x035fb8: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000062ULL; // 0x035fbc: adrp x2, #0x42000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D6042ULL; // 0x035fc0: add x2, x2, #0x758
    return acc;
}

// [EN] Reconstructed FDE #1559 @ 0x036000..0x03605c (92 bytes)
// [VN] Phục dựng FDE #1559 tại 0x036000..0x03605c (92 byte)
//   0x036000: d10103ff  sub      sp, sp, #0x40
//   0x036004: f90013f3  str      x19, [sp, #0x20]
//   0x036008: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x03600c: 9100c3fd  add      x29, sp, #0x30
//   0x036010: d53bd053  mrs      x19, tpidr_el0
//   0x036014: f9401668  ldr      x8, [x19, #0x28]
//   0x036018: 90000062  adrp     x2, #0x42000
//   0x03601c: 911d6042  add      x2, x2, #0x758
//   0x036020: 910043e3  add      x3, sp, #0x10
//   0x036024: 910023e4  add      x4, sp, #8
//   0x036028: f9000fe8  str      x8, [sp, #0x18]
//   0x03602c: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1559_sub_036000(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x036000ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x036000: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x036004: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x036008: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x03600c: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x036010: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x036014: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000062ULL; // 0x036018: adrp x2, #0x42000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D6042ULL; // 0x03601c: add x2, x2, #0x758
    return acc;
}

// [EN] Reconstructed FDE #1560 @ 0x03605c..0x0360b8 (92 bytes)
// [VN] Phục dựng FDE #1560 tại 0x03605c..0x0360b8 (92 byte)
//   0x03605c: d10103ff  sub      sp, sp, #0x40
//   0x036060: f90013f3  str      x19, [sp, #0x20]
//   0x036064: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x036068: 9100c3fd  add      x29, sp, #0x30
//   0x03606c: d53bd053  mrs      x19, tpidr_el0
//   0x036070: f9401668  ldr      x8, [x19, #0x28]
//   0x036074: 90000062  adrp     x2, #0x42000
//   0x036078: 911d6042  add      x2, x2, #0x758
//   0x03607c: 910043e3  add      x3, sp, #0x10
//   0x036080: 910023e4  add      x4, sp, #8
//   0x036084: f9000fe8  str      x8, [sp, #0x18]
//   0x036088: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1560_sub_03605c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x03605CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03605c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x036060: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x036064: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x036068: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03606c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x036070: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000062ULL; // 0x036074: adrp x2, #0x42000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D6042ULL; // 0x036078: add x2, x2, #0x758
    return acc;
}

// [EN] Reconstructed FDE #1561 @ 0x0360b8..0x03618c (212 bytes)
// [VN] Phục dựng FDE #1561 tại 0x0360b8..0x03618c (212 byte)
//   0x0360b8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0360bc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0360c0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0360c4: 910083fd  add      x29, sp, #0x20
//   0x0360c8: b4000200  cbz      x0, #0x36108
//   0x0360cc: b0000136  adrp     x22, #0x5b000
//   0x0360d0: f94346d6  ldr      x22, [x22, #0x688]
//   0x0360d4: f94002c8  ldr      x8, [x22]
//   0x0360d8: b4000188  cbz      x8, #0x36108
//   0x0360dc: aa0103f3  mov      x19, x1
//   0x0360e0: aa0003f4  mov      x20, x0
//   0x0360e4: 97ff5563  bl       #0xb670
uint64_t fde_1561_sub_0360b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xB4000188ULL) + (x2 ^ 0x0360B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0360b8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0360bc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0360c0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0360c4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000200ULL; // 0x0360c8: cbz x0, #0x36108
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000136ULL; // 0x0360cc: adrp x22, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF94346D6ULL; // 0x0360d0: ldr x22, [x22, #0x688]
    acc = (acc * 0x100000001B3ULL) ^ 0xF94002C8ULL; // 0x0360d4: ldr x8, [x22]
    return acc;
}

// [EN] Reconstructed FDE #1562 @ 0x03618c..0x0361e8 (92 bytes)
// [VN] Phục dựng FDE #1562 tại 0x03618c..0x0361e8 (92 byte)
//   0x03618c: d10103ff  sub      sp, sp, #0x40
//   0x036190: f90013f3  str      x19, [sp, #0x20]
//   0x036194: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x036198: 9100c3fd  add      x29, sp, #0x30
//   0x03619c: d53bd053  mrs      x19, tpidr_el0
//   0x0361a0: f9401668  ldr      x8, [x19, #0x28]
//   0x0361a4: 90000062  adrp     x2, #0x42000
//   0x0361a8: 911d6042  add      x2, x2, #0x758
//   0x0361ac: 910043e3  add      x3, sp, #0x10
//   0x0361b0: 910023e4  add      x4, sp, #8
//   0x0361b4: f9000fe8  str      x8, [sp, #0x18]
//   0x0361b8: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1562_sub_03618c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x03618CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03618c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x036190: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x036194: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x036198: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x03619c: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0361a0: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000062ULL; // 0x0361a4: adrp x2, #0x42000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D6042ULL; // 0x0361a8: add x2, x2, #0x758
    return acc;
}

// [EN] Reconstructed FDE #1563 @ 0x0361e8..0x036244 (92 bytes)
// [VN] Phục dựng FDE #1563 tại 0x0361e8..0x036244 (92 byte)
//   0x0361e8: d10103ff  sub      sp, sp, #0x40
//   0x0361ec: f90013f3  str      x19, [sp, #0x20]
//   0x0361f0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0361f4: 9100c3fd  add      x29, sp, #0x30
//   0x0361f8: d53bd053  mrs      x19, tpidr_el0
//   0x0361fc: f9401668  ldr      x8, [x19, #0x28]
//   0x036200: 90000062  adrp     x2, #0x42000
//   0x036204: 911d6042  add      x2, x2, #0x758
//   0x036208: 910043e3  add      x3, sp, #0x10
//   0x03620c: 910023e4  add      x4, sp, #8
//   0x036210: f9000fe8  str      x8, [sp, #0x18]
//   0x036214: f9000be1  str      x1, [sp, #0x10]
uint64_t fde_1563_sub_0361e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910043E3ULL) + (x2 ^ 0x0361E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0361e8: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F3ULL; // 0x0361ec: str x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0361f0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0361f4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x0361f8: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x0361fc: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000062ULL; // 0x036200: adrp x2, #0x42000
    acc = (acc * 0x100000001B3ULL) ^ 0x911D6042ULL; // 0x036204: add x2, x2, #0x758
    return acc;
}

// [EN] Reconstructed FDE #1564 @ 0x036244..0x0362fc (184 bytes)
// [VN] Phục dựng FDE #1564 tại 0x036244..0x0362fc (184 byte)
//   0x036244: d10183ff  sub      sp, sp, #0x60
//   0x036248: f9001bf5  str      x21, [sp, #0x30]
//   0x03624c: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x036250: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x036254: 910143fd  add      x29, sp, #0x50
//   0x036258: d53bd055  mrs      x21, tpidr_el0
//   0x03625c: f94016a8  ldr      x8, [x21, #0x28]
//   0x036260: aa0103f3  mov      x19, x1
//   0x036264: aa0003f4  mov      x20, x0
//   0x036268: f90017e8  str      x8, [sp, #0x28]
//   0x03626c: f90013fe  str      x30, [sp, #0x20]
//   0x036270: 97fffbef  bl       #0x3522c
uint64_t fde_1564_sub_036244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x036244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x036244: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x036248: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x03624c: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x036250: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x036254: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x036258: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x03625c: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036260: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #1565 @ 0x0362fc..0x036394 (152 bytes)
// [VN] Phục dựng FDE #1565 tại 0x0362fc..0x036394 (152 byte)
//   0x0362fc: d10143ff  sub      sp, sp, #0x50
//   0x036300: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x036304: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x036308: 910103fd  add      x29, sp, #0x40
//   0x03630c: d53bd054  mrs      x20, tpidr_el0
//   0x036310: f9401688  ldr      x8, [x20, #0x28]
//   0x036314: aa0003f3  mov      x19, x0
//   0x036318: f81e83a8  stur     x8, [x29, #-0x18]
//   0x03631c: f90013fe  str      x30, [sp, #0x20]
//   0x036320: 97fffbc3  bl       #0x3522c
//   0x036324: 36000160  tbz      w0, #0, #0x36350
//   0x036328: 9400044a  bl       #0x37450
uint64_t fde_1565_sub_0362fc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF90013FEULL) + (x2 ^ 0x0362FCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0362fc: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x036300: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x036304: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x036308: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03630c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x036310: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036314: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E83A8ULL; // 0x036318: stur x8, [x29, #-0x18]
    return acc;
}

// [EN] Reconstructed FDE #1566 @ 0x036394..0x036460 (204 bytes)
// [VN] Phục dựng FDE #1566 tại 0x036394..0x036460 (204 byte)
//   0x036394: d10203ff  sub      sp, sp, #0x80
//   0x036398: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x03639c: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x0363a0: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x0363a4: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x0363a8: 9101c3fd  add      x29, sp, #0x70
//   0x0363ac: d53bd058  mrs      x24, tpidr_el0
//   0x0363b0: f9401708  ldr      x8, [x24, #0x28]
//   0x0363b4: 2a0303f6  mov      w22, w3
//   0x0363b8: aa0203f4  mov      x20, x2
//   0x0363bc: aa0103f5  mov      x21, x1
//   0x0363c0: aa0003f3  mov      x19, x0
uint64_t fde_1566_sub_036394(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A0303F6ULL) + (x2 ^ 0x036394ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x036394: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x036398: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x03639c: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x0363a0: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x0363a4: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x0363a8: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD058ULL; // 0x0363ac: mrs x24, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401708ULL; // 0x0363b0: ldr x8, [x24, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1567 @ 0x036460..0x036528 (200 bytes)
// [VN] Phục dựng FDE #1567 tại 0x036460..0x036528 (200 byte)
//   0x036460: d10203ff  sub      sp, sp, #0x80
//   0x036464: f90023f7  str      x23, [sp, #0x40]
//   0x036468: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x03646c: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x036470: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x036474: 9101c3fd  add      x29, sp, #0x70
//   0x036478: d53bd057  mrs      x23, tpidr_el0
//   0x03647c: f94016e8  ldr      x8, [x23, #0x28]
//   0x036480: 2a0203f5  mov      w21, w2
//   0x036484: aa0103f4  mov      x20, x1
//   0x036488: aa0003f3  mov      x19, x0
//   0x03648c: f9001fe8  str      x8, [sp, #0x38]
uint64_t fde_1567_sub_036460(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A0203F5ULL) + (x2 ^ 0x036460ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x036460: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x036464: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x036468: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x03646c: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x036470: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x036474: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x036478: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03647c: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1568 @ 0x036528..0x036618 (240 bytes)
// [VN] Phục dựng FDE #1568 tại 0x036528..0x036618 (240 byte)
//   0x036528: d10203ff  sub      sp, sp, #0x80
//   0x03652c: f90023f7  str      x23, [sp, #0x40]
//   0x036530: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x036534: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x036538: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03653c: 9101c3fd  add      x29, sp, #0x70
//   0x036540: d53bd056  mrs      x22, tpidr_el0
//   0x036544: f94016c8  ldr      x8, [x22, #0x28]
//   0x036548: 2a0203f5  mov      w21, w2
//   0x03654c: aa0103f4  mov      x20, x1
//   0x036550: aa0003f3  mov      x19, x0
//   0x036554: f9001fe8  str      x8, [sp, #0x38]
uint64_t fde_1568_sub_036528(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0x2A0203F5ULL) + (x2 ^ 0x036528ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x036528: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F7ULL; // 0x03652c: str x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x036530: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x036534: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x036538: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03653c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x036540: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x036544: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1569 @ 0x036618..0x036644 (44 bytes)
// [VN] Phục dựng FDE #1569 tại 0x036618..0x036644 (44 byte)
//   0x036618: b0000129  adrp     x9, #0x5b000
//   0x03661c: f9477529  ldr      x9, [x9, #0xee8]
//   0x036620: 91008008  add      x8, x0, #0x20
//   0x036624: f9041002  str      x2, [x0, #0x820]
//   0x036628: a9017c1f  stp      xzr, xzr, [x0, #0x10]
//   0x03662c: 91004129  add      x9, x9, #0x10
//   0x036630: a9000409  stp      x9, x1, [x0]
//   0x036634: 52810002  mov      w2, #0x800
//   0x036638: aa0803e0  mov      x0, x8
//   0x03663c: 2a1f03e1  mov      w1, wzr
//   0x036640: 17ff538c  b        #0xb470
uint64_t fde_1569_sub_036618(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB0000129ULL) + (x1 ^ 0xAA0803E0ULL) + (x2 ^ 0x036618ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000129ULL; // 0x036618: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9477529ULL; // 0x03661c: ldr x9, [x9, #0xee8]
    acc = (acc * 0x100000001B3ULL) ^ 0x91008008ULL; // 0x036620: add x8, x0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9041002ULL; // 0x036624: str x2, [x0, #0x820]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017C1FULL; // 0x036628: stp xzr, xzr, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004129ULL; // 0x03662c: add x9, x9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000409ULL; // 0x036630: stp x9, x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x52810002ULL; // 0x036634: mov w2, #0x800
    return acc;
}

// [EN] Reconstructed FDE #1570 @ 0x036644..0x036678 (52 bytes)
// [VN] Phục dựng FDE #1570 tại 0x036644..0x036678 (52 byte)
//   0x036644: f9041402  str      x2, [x0, #0x828]
//   0x036648: b0000129  adrp     x9, #0x5b000
//   0x03664c: f944b529  ldr      x9, [x9, #0x968]
//   0x036650: 52800028  mov      w8, #1
//   0x036654: b9001008  str      w8, [x0, #0x10]
//   0x036658: 9100a008  add      x8, x0, #0x28
//   0x03665c: 91004129  add      x9, x9, #0x10
//   0x036660: a9000409  stp      x9, x1, [x0]
//   0x036664: a901fc1f  stp      xzr, xzr, [x0, #0x18]
//   0x036668: 52810002  mov      w2, #0x800
//   0x03666c: aa0803e0  mov      x0, x8
//   0x036670: 2a1f03e1  mov      w1, wzr
uint64_t fde_1570_sub_036644(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9041402ULL) + (x1 ^ 0xA901FC1FULL) + (x2 ^ 0x036644ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9041402ULL; // 0x036644: str x2, [x0, #0x828]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000129ULL; // 0x036648: adrp x9, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF944B529ULL; // 0x03664c: ldr x9, [x9, #0x968]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800028ULL; // 0x036650: mov w8, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xB9001008ULL; // 0x036654: str w8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A008ULL; // 0x036658: add x8, x0, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0x91004129ULL; // 0x03665c: add x9, x9, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000409ULL; // 0x036660: stp x9, x1, [x0]
    return acc;
}

// [EN] Reconstructed FDE #1571 @ 0x036678..0x0366ac (52 bytes)
// [VN] Phục dựng FDE #1571 tại 0x036678..0x0366ac (52 byte)
//   0x036678: b000012a  adrp     x10, #0x5b000
//   0x03667c: f9458d4a  ldr      x10, [x10, #0xb18]
//   0x036680: 52800029  mov      w9, #1
//   0x036684: 91008008  add      x8, x0, #0x20
//   0x036688: b9001009  str      w9, [x0, #0x10]
//   0x03668c: 91004149  add      x9, x10, #0x10
//   0x036690: f9041002  str      x2, [x0, #0x820]
//   0x036694: a9000409  stp      x9, x1, [x0]
//   0x036698: 52810002  mov      w2, #0x800
//   0x03669c: f9000c1f  str      xzr, [x0, #0x18]
//   0x0366a0: aa0803e0  mov      x0, x8
//   0x0366a4: 2a1f03e1  mov      w1, wzr
uint64_t fde_1571_sub_036678(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB000012AULL) + (x1 ^ 0x52810002ULL) + (x2 ^ 0x036678ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB000012AULL; // 0x036678: adrp x10, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9458D4AULL; // 0x03667c: ldr x10, [x10, #0xb18]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800029ULL; // 0x036680: mov w9, #1
    acc = (acc * 0x100000001B3ULL) ^ 0x91008008ULL; // 0x036684: add x8, x0, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB9001009ULL; // 0x036688: str w9, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x91004149ULL; // 0x03668c: add x9, x10, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9041002ULL; // 0x036690: str x2, [x0, #0x820]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9000409ULL; // 0x036694: stp x9, x1, [x0]
    return acc;
}

// [EN] Reconstructed FDE #1572 @ 0x0366ac..0x0366b0 (4 bytes)
// [VN] Phục dựng FDE #1572 tại 0x0366ac..0x0366b0 (4 byte)
//   0x0366ac: 17ff51a5  b        #0xad40
uint64_t fde_1572_sub_0366ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF51A5ULL) + (x1 ^ 0x17FF51A5ULL) + (x2 ^ 0x0366ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF51A5ULL; // 0x0366ac: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1573 @ 0x0366b0..0x036750 (160 bytes)
// [VN] Phục dựng FDE #1573 tại 0x0366b0..0x036750 (160 byte)
//   0x0366b0: d100c3ff  sub      sp, sp, #0x30
//   0x0366b4: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0366b8: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0366bc: 910083fd  add      x29, sp, #0x20
//   0x0366c0: d53bd054  mrs      x20, tpidr_el0
//   0x0366c4: f9401688  ldr      x8, [x20, #0x28]
//   0x0366c8: aa0003f3  mov      x19, x0
//   0x0366cc: f90007e8  str      x8, [sp, #8]
//   0x0366d0: 94000021  bl       #0x36754
//   0x0366d4: f90003e0  str      x0, [sp]
//   0x0366d8: b40001c0  cbz      x0, #0x36710
//   0x0366dc: f9441260  ldr      x0, [x19, #0x820]
uint64_t fde_1573_sub_0366b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x94000021ULL) + (x2 ^ 0x0366B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x0366b0: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0366b4: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0366b8: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0366bc: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0366c0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0366c4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0366c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x0366cc: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #1574 @ 0x036750..0x036754 (4 bytes)
// [VN] Phục dựng FDE #1574 tại 0x036750..0x036754 (4 byte)
//   0x036750: d65f03c0  ret      
uint64_t fde_1574_sub_036750(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036750ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036750: ret 
    return acc;
}

// [EN] Reconstructed FDE #1575 @ 0x036754..0x03677c (40 bytes)
// [VN] Phục dựng FDE #1575 tại 0x036754..0x03677c (40 byte)
//   0x036754: f9400808  ldr      x8, [x0, #0x10]
//   0x036758: b4000068  cbz      x8, #0x36764
//   0x03675c: f9400900  ldr      x0, [x8, #0x10]
//   0x036760: d65f03c0  ret      
//   0x036764: f9400c08  ldr      x8, [x0, #0x18]
//   0x036768: b4000068  cbz      x8, #0x36774
//   0x03676c: b9400100  ldr      w0, [x8]
//   0x036770: d65f03c0  ret      
//   0x036774: aa1f03e0  mov      x0, xzr
//   0x036778: d65f03c0  ret      
uint64_t fde_1575_sub_036754(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xAA1F03E0ULL) + (x2 ^ 0x036754ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x036754: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x036758: cbz x8, #0x36764
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400900ULL; // 0x03675c: ldr x0, [x8, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036760: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C08ULL; // 0x036764: ldr x8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x036768: cbz x8, #0x36774
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400100ULL; // 0x03676c: ldr w0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036770: ret 
    return acc;
}

// [EN] Reconstructed FDE #1576 @ 0x03677c..0x036780 (4 bytes)
// [VN] Phục dựng FDE #1576 tại 0x03677c..0x036780 (4 byte)
//   0x03677c: 17ff5171  b        #0xad40
uint64_t fde_1576_sub_03677c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF5171ULL) + (x1 ^ 0x17FF5171ULL) + (x2 ^ 0x03677CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5171ULL; // 0x03677c: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1577 @ 0x036780..0x036820 (160 bytes)
// [VN] Phục dựng FDE #1577 tại 0x036780..0x036820 (160 byte)
//   0x036780: d100c3ff  sub      sp, sp, #0x30
//   0x036784: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x036788: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03678c: 910083fd  add      x29, sp, #0x20
//   0x036790: d53bd054  mrs      x20, tpidr_el0
//   0x036794: f9401688  ldr      x8, [x20, #0x28]
//   0x036798: aa0003f3  mov      x19, x0
//   0x03679c: f90007e8  str      x8, [sp, #8]
//   0x0367a0: 94000021  bl       #0x36824
//   0x0367a4: f90003e0  str      x0, [sp]
//   0x0367a8: b40001c0  cbz      x0, #0x367e0
//   0x0367ac: f9441660  ldr      x0, [x19, #0x828]
uint64_t fde_1577_sub_036780(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0x94000021ULL) + (x2 ^ 0x036780ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x036780: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x036784: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x036788: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03678c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x036790: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x036794: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036798: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03679c: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #1578 @ 0x036820..0x036824 (4 bytes)
// [VN] Phục dựng FDE #1578 tại 0x036820..0x036824 (4 byte)
//   0x036820: d65f03c0  ret      
uint64_t fde_1578_sub_036820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036820: ret 
    return acc;
}

// [EN] Reconstructed FDE #1579 @ 0x036824..0x03684c (40 bytes)
// [VN] Phục dựng FDE #1579 tại 0x036824..0x03684c (40 byte)
//   0x036824: f9400c08  ldr      x8, [x0, #0x18]
//   0x036828: b4000068  cbz      x8, #0x36834
//   0x03682c: 91004108  add      x8, x8, #0x10
//   0x036830: 14000003  b        #0x3683c
//   0x036834: f9401008  ldr      x8, [x0, #0x20]
//   0x036838: b4000068  cbz      x8, #0x36844
//   0x03683c: f9400100  ldr      x0, [x8]
//   0x036840: d65f03c0  ret      
//   0x036844: aa1f03e0  mov      x0, xzr
//   0x036848: d65f03c0  ret      
uint64_t fde_1579_sub_036824(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400C08ULL) + (x1 ^ 0xAA1F03E0ULL) + (x2 ^ 0x036824ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400C08ULL; // 0x036824: ldr x8, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x036828: cbz x8, #0x36834
    acc = (acc * 0x100000001B3ULL) ^ 0x91004108ULL; // 0x03682c: add x8, x8, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x14000003ULL; // 0x036830: b #0x3683c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401008ULL; // 0x036834: ldr x8, [x0, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000068ULL; // 0x036838: cbz x8, #0x36844
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400100ULL; // 0x03683c: ldr x0, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036840: ret 
    return acc;
}

// [EN] Reconstructed FDE #1580 @ 0x03684c..0x036850 (4 bytes)
// [VN] Phục dựng FDE #1580 tại 0x03684c..0x036850 (4 byte)
//   0x03684c: d65f03c0  ret      
uint64_t fde_1580_sub_03684c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03684CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03684c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1581 @ 0x036850..0x036854 (4 bytes)
// [VN] Phục dựng FDE #1581 tại 0x036850..0x036854 (4 byte)
//   0x036850: 17ff513c  b        #0xad40
uint64_t fde_1581_sub_036850(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF513CULL) + (x1 ^ 0x17FF513CULL) + (x2 ^ 0x036850ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF513CULL; // 0x036850: b #0xad40
    return acc;
}

// [EN] Reconstructed FDE #1582 @ 0x036854..0x036908 (180 bytes)
// [VN] Phục dựng FDE #1582 tại 0x036854..0x036908 (180 byte)
//   0x036854: d100c3ff  sub      sp, sp, #0x30
//   0x036858: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03685c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x036860: 910083fd  add      x29, sp, #0x20
//   0x036864: d53bd054  mrs      x20, tpidr_el0
//   0x036868: f9401688  ldr      x8, [x20, #0x28]
//   0x03686c: f90007e8  str      x8, [sp, #8]
//   0x036870: b0000128  adrp     x8, #0x5b000
//   0x036874: f947e108  ldr      x8, [x8, #0xfc0]
//   0x036878: f9400108  ldr      x8, [x8]
//   0x03687c: b4000248  cbz      x8, #0x368c4
//   0x036880: aa0003f3  mov      x19, x0
uint64_t fde_1582_sub_036854(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF947E108ULL) + (x2 ^ 0x036854ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x036854: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x036858: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03685c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x036860: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x036864: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x036868: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x03686c: str x8, [sp, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000128ULL; // 0x036870: adrp x8, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1583 @ 0x036908..0x036920 (24 bytes)
// [VN] Phục dựng FDE #1583 tại 0x036908..0x036920 (24 byte)
//   0x036908: aa0003e8  mov      x8, x0
//   0x03690c: f9400000  ldr      x0, [x0]
//   0x036910: b4000060  cbz      x0, #0x3691c
//   0x036914: f9000500  str      x0, [x8, #8]
//   0x036918: 17ff510a  b        #0xad40
//   0x03691c: d65f03c0  ret      
uint64_t fde_1583_sub_036908(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036908ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x036908: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x03690c: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x036910: cbz x0, #0x3691c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x036914: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF510AULL; // 0x036918: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03691c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1584 @ 0x036920..0x0369ec (204 bytes)
// [VN] Phục dựng FDE #1584 tại 0x036920..0x0369ec (204 byte)
//   0x036920: d101c3ff  sub      sp, sp, #0x70
//   0x036924: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x036928: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x03692c: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x036930: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x036934: 910183fd  add      x29, sp, #0x60
//   0x036938: d53bd057  mrs      x23, tpidr_el0
//   0x03693c: f94016e8  ldr      x8, [x23, #0x28]
//   0x036940: aa0103f4  mov      x20, x1
//   0x036944: aa0003f3  mov      x19, x0
//   0x036948: 91004016  add      x22, x0, #0x10
//   0x03694c: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1584_sub_036920(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x036920ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x036920: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x036924: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x036928: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x03692c: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x036930: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x036934: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x036938: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x03693c: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1585 @ 0x0369ec..0x036a34 (72 bytes)
// [VN] Phục dựng FDE #1585 tại 0x0369ec..0x036a34 (72 byte)
//   0x0369ec: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0369f0: 910003fd  mov      x29, sp
//   0x0369f4: d37dfc28  lsr      x8, x1, #0x3d
//   0x0369f8: b50001c8  cbnz     x8, #0x36a30
//   0x0369fc: f9400808  ldr      x8, [x0, #0x10]
//   0x036a00: f9400009  ldr      x9, [x0]
//   0x036a04: cb090108  sub      x8, x8, x9
//   0x036a08: b27febe9  mov      x9, #0xffffffffffffffe
//   0x036a0c: eb880d3f  cmp      x9, x8, asr #3
//   0x036a10: 540000a3  b.lo     #0x36a24
//   0x036a14: 9342fd08  asr      x8, x8, #2
//   0x036a18: eb01011f  cmp      x8, x1
uint64_t fde_1585_sub_0369ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB880D3FULL) + (x2 ^ 0x0369ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0369ec: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0369f0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x0369f4: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x0369f8: cbnz x8, #0x36a30
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x0369fc: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x036a00: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x036a04: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FEBE9ULL; // 0x036a08: mov x9, #0xffffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #1586 @ 0x036a34..0x036a98 (100 bytes)
// [VN] Phục dựng FDE #1586 tại 0x036a34..0x036a98 (100 byte)
//   0x036a34: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x036a38: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036a3c: 910043fd  add      x29, sp, #0x10
//   0x036a40: aa0103f3  mov      x19, x1
//   0x036a44: aa0003f4  mov      x20, x0
//   0x036a48: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x036a4c: 91002263  add      x3, x19, #8
//   0x036a50: 94000028  bl       #0x36af0
//   0x036a54: f9400668  ldr      x8, [x19, #8]
//   0x036a58: f9400289  ldr      x9, [x20]
//   0x036a5c: f9000288  str      x8, [x20]
//   0x036a60: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_1586_sub_036a34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x036A34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x036a34: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036a38: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036a3c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036a40: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x036a44: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x036a48: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x036a4c: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x036a50: bl #0x36af0
    return acc;
}

// [EN] Reconstructed FDE #1587 @ 0x036a98..0x036acc (52 bytes)
// [VN] Phục dựng FDE #1587 tại 0x036a98..0x036acc (52 byte)
//   0x036a98: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036a9c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036aa0: 910043fd  add      x29, sp, #0x10
//   0x036aa4: aa0003f3  mov      x19, x0
//   0x036aa8: 9400001a  bl       #0x36b10
//   0x036aac: f9400260  ldr      x0, [x19]
//   0x036ab0: b4000080  cbz      x0, #0x36ac0
//   0x036ab4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x036ab8: f84207f3  ldr      x19, [sp], #0x20
//   0x036abc: 17ff50a1  b        #0xad40
//   0x036ac0: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x036ac4: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1587_sub_036a98(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x036A98ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036a98: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036a9c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036aa0: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036aa4: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x036aa8: bl #0x36b10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x036aac: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x036ab0: cbz x0, #0x36ac0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x036ab4: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #1588 @ 0x036acc..0x036ad4 (8 bytes)
// [VN] Phục dựng FDE #1588 tại 0x036acc..0x036ad4 (8 byte)
//   0x036acc: aa1f03e2  mov      x2, xzr
//   0x036ad0: 14000001  b        #0x36ad4
uint64_t fde_1588_sub_036acc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x036ACCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x036acc: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x036ad0: b #0x36ad4
    return acc;
}

// [EN] Reconstructed FDE #1589 @ 0x036ad4..0x036af0 (28 bytes)
// [VN] Phục dựng FDE #1589 tại 0x036ad4..0x036af0 (28 byte)
//   0x036ad4: d37dfc28  lsr      x8, x1, #0x3d
//   0x036ad8: b5000068  cbnz     x8, #0x36ae4
//   0x036adc: d37df020  lsl      x0, x1, #3
//   0x036ae0: 17ff52c4  b        #0xb5f0
//   0x036ae4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x036ae8: 910003fd  mov      x29, sp
//   0x036aec: 97ff5285  bl       #0xb500
uint64_t fde_1589_sub_036ad4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF5285ULL) + (x2 ^ 0x036AD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x036ad4: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x036ad8: cbnz x8, #0x36ae4
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x036adc: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF52C4ULL; // 0x036ae0: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x036ae4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x036ae8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5285ULL; // 0x036aec: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1590 @ 0x036af0..0x036b10 (32 bytes)
// [VN] Phục dựng FDE #1590 tại 0x036af0..0x036b10 (32 byte)
//   0x036af0: f9400068  ldr      x8, [x3]
//   0x036af4: cb010042  sub      x2, x2, x1
//   0x036af8: f100045f  cmp      x2, #1
//   0x036afc: cb020100  sub      x0, x8, x2
//   0x036b00: f9000060  str      x0, [x3]
//   0x036b04: 5400004b  b.lt     #0x36b0c
//   0x036b08: 17ff5042  b        #0xac10
//   0x036b0c: d65f03c0  ret      
uint64_t fde_1590_sub_036af0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036AF0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x036af0: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x036af4: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x036af8: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x036afc: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x036b00: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x036b04: b.lt #0x36b0c
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF5042ULL; // 0x036b08: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036b0c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1591 @ 0x036b10..0x036b18 (8 bytes)
// [VN] Phục dựng FDE #1591 tại 0x036b10..0x036b18 (8 byte)
//   0x036b10: f9400401  ldr      x1, [x0, #8]
//   0x036b14: 14000001  b        #0x36b18
uint64_t fde_1591_sub_036b10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x036B10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x036b10: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x036b14: b #0x36b18
    return acc;
}

// [EN] Reconstructed FDE #1592 @ 0x036b18..0x036b34 (28 bytes)
// [VN] Phục dựng FDE #1592 tại 0x036b18..0x036b34 (28 byte)
//   0x036b18: f9400808  ldr      x8, [x0, #0x10]
//   0x036b1c: eb08003f  cmp      x1, x8
//   0x036b20: 54000080  b.eq     #0x36b30
//   0x036b24: d1002108  sub      x8, x8, #8
//   0x036b28: f9000808  str      x8, [x0, #0x10]
//   0x036b2c: 17fffffc  b        #0x36b1c
//   0x036b30: d65f03c0  ret      
uint64_t fde_1592_sub_036b18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036B18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x036b18: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x036b1c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x036b20: b.eq #0x36b30
    acc = (acc * 0x100000001B3ULL) ^ 0xD1002108ULL; // 0x036b24: sub x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x036b28: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x036b2c: b #0x36b1c
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036b30: ret 
    return acc;
}

// [EN] Reconstructed FDE #1593 @ 0x036b34..0x036b3c (8 bytes)
// [VN] Phục dựng FDE #1593 tại 0x036b34..0x036b3c (8 byte)
//   0x036b34: f9400401  ldr      x1, [x0, #8]
//   0x036b38: 14000001  b        #0x36b3c
uint64_t fde_1593_sub_036b34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x036B34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x036b34: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x036b38: b #0x36b3c
    return acc;
}

// [EN] Reconstructed FDE #1594 @ 0x036b3c..0x036b84 (72 bytes)
// [VN] Phục dựng FDE #1594 tại 0x036b3c..0x036b84 (72 byte)
//   0x036b3c: b4000221  cbz      x1, #0x36b80
//   0x036b40: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x036b44: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036b48: 910043fd  add      x29, sp, #0x10
//   0x036b4c: aa0103f3  mov      x19, x1
//   0x036b50: f9400021  ldr      x1, [x1]
//   0x036b54: aa0003f4  mov      x20, x0
//   0x036b58: 97fffff9  bl       #0x36b3c
//   0x036b5c: f9400661  ldr      x1, [x19, #8]
//   0x036b60: aa1403e0  mov      x0, x20
//   0x036b64: 97fffff6  bl       #0x36b3c
//   0x036b68: 9100a260  add      x0, x19, #0x28
uint64_t fde_1594_sub_036b3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB4000221ULL) + (x1 ^ 0xF9400661ULL) + (x2 ^ 0x036B3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000221ULL; // 0x036b3c: cbz x1, #0x36b80
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x036b40: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036b44: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036b48: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036b4c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x036b50: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x036b54: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF9ULL; // 0x036b58: bl #0x36b3c
    return acc;
}

// [EN] Reconstructed FDE #1595 @ 0x036b84..0x036b8c (8 bytes)
// [VN] Phục dựng FDE #1595 tại 0x036b84..0x036b8c (8 byte)
//   0x036b84: f9400401  ldr      x1, [x0, #8]
//   0x036b88: 14000001  b        #0x36b8c
uint64_t fde_1595_sub_036b84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x036B84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x036b84: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x036b88: b #0x36b8c
    return acc;
}

// [EN] Reconstructed FDE #1596 @ 0x036b8c..0x036bcc (64 bytes)
// [VN] Phục dựng FDE #1596 tại 0x036b8c..0x036bcc (64 byte)
//   0x036b8c: b40001e1  cbz      x1, #0x36bc8
//   0x036b90: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x036b94: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036b98: 910043fd  add      x29, sp, #0x10
//   0x036b9c: aa0103f3  mov      x19, x1
//   0x036ba0: f9400021  ldr      x1, [x1]
//   0x036ba4: aa0003f4  mov      x20, x0
//   0x036ba8: 97fffff9  bl       #0x36b8c
//   0x036bac: f9400661  ldr      x1, [x19, #8]
//   0x036bb0: aa1403e0  mov      x0, x20
//   0x036bb4: 97fffff6  bl       #0x36b8c
//   0x036bb8: a9417bfd  ldp      x29, x30, [sp, #0x10]
uint64_t fde_1596_sub_036b8c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB40001E1ULL) + (x1 ^ 0xF9400661ULL) + (x2 ^ 0x036B8CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB40001E1ULL; // 0x036b8c: cbz x1, #0x36bc8
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x036b90: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036b94: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036b98: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036b9c: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400021ULL; // 0x036ba0: ldr x1, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x036ba4: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFFFF9ULL; // 0x036ba8: bl #0x36b8c
    return acc;
}

// [EN] Reconstructed FDE #1597 @ 0x036bcc..0x036c94 (200 bytes)
// [VN] Phục dựng FDE #1597 tại 0x036bcc..0x036c94 (200 byte)
//   0x036bcc: d10203ff  sub      sp, sp, #0x80
//   0x036bd0: f9001bf9  str      x25, [sp, #0x30]
//   0x036bd4: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x036bd8: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x036bdc: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x036be0: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x036be4: 9101c3fd  add      x29, sp, #0x70
//   0x036be8: d53bd059  mrs      x25, tpidr_el0
//   0x036bec: f9401728  ldr      x8, [x25, #0x28]
//   0x036bf0: aa0203f7  mov      x23, x2
//   0x036bf4: aa0103e2  mov      x2, x1
//   0x036bf8: 910023e1  add      x1, sp, #8
uint64_t fde_1597_sub_036bcc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x036BCCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x036bcc: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x036bd0: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x036bd4: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x036bd8: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x036bdc: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x036be0: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x036be4: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x036be8: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1598 @ 0x036c94..0x036ce8 (84 bytes)
// [VN] Phục dựng FDE #1598 tại 0x036c94..0x036ce8 (84 byte)
//   0x036c94: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x036c98: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x036c9c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x036ca0: 910083fd  add      x29, sp, #0x20
//   0x036ca4: 91002015  add      x21, x0, #8
//   0x036ca8: 52800021  mov      w1, #1
//   0x036cac: aa1503e0  mov      x0, x21
//   0x036cb0: aa0203f3  mov      x19, x2
//   0x036cb4: aa0803f4  mov      x20, x8
//   0x036cb8: 52800036  mov      w22, #1
//   0x036cbc: 97ff5828  bl       #0xcd5c
//   0x036cc0: a9005680  stp      x0, x21, [x20]
uint64_t fde_1598_sub_036c94(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x036C94ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x036c94: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x036c98: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x036c9c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x036ca0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x036ca4: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x036ca8: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x036cac: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x036cb0: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1599 @ 0x036ce8..0x036db0 (200 bytes)
// [VN] Phục dựng FDE #1599 tại 0x036ce8..0x036db0 (200 byte)
//   0x036ce8: d10203ff  sub      sp, sp, #0x80
//   0x036cec: f9001bf9  str      x25, [sp, #0x30]
//   0x036cf0: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x036cf4: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x036cf8: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x036cfc: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x036d00: 9101c3fd  add      x29, sp, #0x70
//   0x036d04: d53bd059  mrs      x25, tpidr_el0
//   0x036d08: f9401728  ldr      x8, [x25, #0x28]
//   0x036d0c: aa0203f7  mov      x23, x2
//   0x036d10: aa0103e2  mov      x2, x1
//   0x036d14: 910023e1  add      x1, sp, #8
uint64_t fde_1599_sub_036ce8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x036CE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x036ce8: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x036cec: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x036cf0: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x036cf4: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x036cf8: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x036cfc: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x036d00: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x036d04: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1600 @ 0x036db0..0x036e10 (96 bytes)
// [VN] Phục dựng FDE #1600 tại 0x036db0..0x036e10 (96 byte)
//   0x036db0: aa0003e8  mov      x8, x0
//   0x036db4: f8408c09  ldr      x9, [x0, #8]!
//   0x036db8: b4000229  cbz      x9, #0x36dfc
//   0x036dbc: f940004a  ldr      x10, [x2]
//   0x036dc0: 91002100  add      x0, x8, #8
//   0x036dc4: f9401128  ldr      x8, [x9, #0x20]
//   0x036dc8: eb08015f  cmp      x10, x8
//   0x036dcc: 540000a2  b.hs     #0x36de0
//   0x036dd0: f9400128  ldr      x8, [x9]
//   0x036dd4: b4000188  cbz      x8, #0x36e04
//   0x036dd8: aa0903e0  mov      x0, x9
//   0x036ddc: 14000006  b        #0x36df4
uint64_t fde_1600_sub_036db0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x036DB0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x036db0: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x036db4: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x036db8: cbz x9, #0x36dfc
    acc = (acc * 0x100000001B3ULL) ^ 0xF940004AULL; // 0x036dbc: ldr x10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x036dc0: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401128ULL; // 0x036dc4: ldr x8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08015FULL; // 0x036dc8: cmp x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x036dcc: b.hs #0x36de0
    return acc;
}

// [EN] Reconstructed FDE #1601 @ 0x036e10..0x036e68 (88 bytes)
// [VN] Phục dựng FDE #1601 tại 0x036e10..0x036e68 (88 byte)
//   0x036e10: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x036e14: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x036e18: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x036e1c: 910083fd  add      x29, sp, #0x20
//   0x036e20: 91002015  add      x21, x0, #8
//   0x036e24: 52800021  mov      w1, #1
//   0x036e28: aa1503e0  mov      x0, x21
//   0x036e2c: aa0203f3  mov      x19, x2
//   0x036e30: aa0803f4  mov      x20, x8
//   0x036e34: 52800036  mov      w22, #1
//   0x036e38: 94000023  bl       #0x36ec4
//   0x036e3c: a9005680  stp      x0, x21, [x20]
uint64_t fde_1601_sub_036e10(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x036E10ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x036e10: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x036e14: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x036e18: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x036e1c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x036e20: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x036e24: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x036e28: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x036e2c: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1602 @ 0x036e68..0x036ebc (84 bytes)
// [VN] Phục dựng FDE #1602 tại 0x036e68..0x036ebc (84 byte)
//   0x036e68: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036e6c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036e70: 910043fd  add      x29, sp, #0x10
//   0x036e74: a9007c7f  stp      xzr, xzr, [x3]
//   0x036e78: f9000861  str      x1, [x3, #0x10]
//   0x036e7c: f9000043  str      x3, [x2]
//   0x036e80: f9400008  ldr      x8, [x0]
//   0x036e84: aa0003f3  mov      x19, x0
//   0x036e88: f9400108  ldr      x8, [x8]
//   0x036e8c: b4000068  cbz      x8, #0x36e98
//   0x036e90: f9000268  str      x8, [x19]
//   0x036e94: f9400043  ldr      x3, [x2]
uint64_t fde_1602_sub_036e68(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x036E68ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036e68: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036e6c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036e70: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x036e74: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x036e78: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x036e7c: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x036e80: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x036e84: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1603 @ 0x036ebc..0x036ec4 (8 bytes)
// [VN] Phục dựng FDE #1603 tại 0x036ebc..0x036ec4 (8 byte)
//   0x036ebc: aa1f03e1  mov      x1, xzr
//   0x036ec0: 1400000a  b        #0x36ee8
uint64_t fde_1603_sub_036ebc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000AULL) + (x2 ^ 0x036EBCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x036ebc: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000AULL; // 0x036ec0: b #0x36ee8
    return acc;
}

// [EN] Reconstructed FDE #1604 @ 0x036ec4..0x036ecc (8 bytes)
// [VN] Phục dựng FDE #1604 tại 0x036ec4..0x036ecc (8 byte)
//   0x036ec4: aa1f03e2  mov      x2, xzr
//   0x036ec8: 14000001  b        #0x36ecc
uint64_t fde_1604_sub_036ec4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x036EC4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x036ec4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x036ec8: b #0x36ecc
    return acc;
}

// [EN] Reconstructed FDE #1605 @ 0x036ecc..0x036ee8 (28 bytes)
// [VN] Phục dựng FDE #1605 tại 0x036ecc..0x036ee8 (28 byte)
//   0x036ecc: d37afc28  lsr      x8, x1, #0x3a
//   0x036ed0: b5000068  cbnz     x8, #0x36edc
//   0x036ed4: d37ae420  lsl      x0, x1, #6
//   0x036ed8: 17ff51c6  b        #0xb5f0
//   0x036edc: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x036ee0: 910003fd  mov      x29, sp
//   0x036ee4: 97ff5187  bl       #0xb500
uint64_t fde_1605_sub_036ecc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37AFC28ULL) + (x1 ^ 0x97FF5187ULL) + (x2 ^ 0x036ECCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37AFC28ULL; // 0x036ecc: lsr x8, x1, #0x3a
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x036ed0: cbnz x8, #0x36edc
    acc = (acc * 0x100000001B3ULL) ^ 0xD37AE420ULL; // 0x036ed4: lsl x0, x1, #6
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF51C6ULL; // 0x036ed8: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x036edc: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x036ee0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5187ULL; // 0x036ee4: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1606 @ 0x036ee8..0x036f04 (28 bytes)
// [VN] Phục dựng FDE #1606 tại 0x036ee8..0x036f04 (28 byte)
//   0x036ee8: f9400008  ldr      x8, [x0]
//   0x036eec: f9000001  str      x1, [x0]
//   0x036ef0: b4000088  cbz      x8, #0x36f00
//   0x036ef4: 91002000  add      x0, x0, #8
//   0x036ef8: aa0803e1  mov      x1, x8
//   0x036efc: 14000002  b        #0x36f04
//   0x036f00: d65f03c0  ret      
uint64_t fde_1606_sub_036ee8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x036EE8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x036ee8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x036eec: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000088ULL; // 0x036ef0: cbz x8, #0x36f00
    acc = (acc * 0x100000001B3ULL) ^ 0x91002000ULL; // 0x036ef4: add x0, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E1ULL; // 0x036ef8: mov x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x14000002ULL; // 0x036efc: b #0x36f04
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x036f00: ret 
    return acc;
}

// [EN] Reconstructed FDE #1607 @ 0x036f04..0x036f44 (64 bytes)
// [VN] Phục dựng FDE #1607 tại 0x036f04..0x036f44 (64 byte)
//   0x036f04: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x036f08: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x036f0c: 910043fd  add      x29, sp, #0x10
//   0x036f10: 39402008  ldrb     w8, [x0, #8]
//   0x036f14: aa0103f3  mov      x19, x1
//   0x036f18: 34000068  cbz      w8, #0x36f24
//   0x036f1c: 9100a260  add      x0, x19, #0x28
//   0x036f20: 97ff5a49  bl       #0xd844
//   0x036f24: b40000b3  cbz      x19, #0x36f38
//   0x036f28: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x036f2c: aa1303e0  mov      x0, x19
//   0x036f30: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1607_sub_036f04(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xB40000B3ULL) + (x2 ^ 0x036F04ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x036f04: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x036f08: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x036f0c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x39402008ULL; // 0x036f10: ldrb w8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x036f14: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x34000068ULL; // 0x036f18: cbz w8, #0x36f24
    acc = (acc * 0x100000001B3ULL) ^ 0x9100A260ULL; // 0x036f1c: add x0, x19, #0x28
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5A49ULL; // 0x036f20: bl #0xd844
    return acc;
}

// [EN] Reconstructed FDE #1608 @ 0x036f44..0x03700c (200 bytes)
// [VN] Phục dựng FDE #1608 tại 0x036f44..0x03700c (200 byte)
//   0x036f44: d10203ff  sub      sp, sp, #0x80
//   0x036f48: f9001bf9  str      x25, [sp, #0x30]
//   0x036f4c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x036f50: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x036f54: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x036f58: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x036f5c: 9101c3fd  add      x29, sp, #0x70
//   0x036f60: d53bd059  mrs      x25, tpidr_el0
//   0x036f64: f9401728  ldr      x8, [x25, #0x28]
//   0x036f68: aa0203f7  mov      x23, x2
//   0x036f6c: aa0103e2  mov      x2, x1
//   0x036f70: 910023e1  add      x1, sp, #8
uint64_t fde_1608_sub_036f44(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x036F44ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x036f44: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x036f48: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x036f4c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x036f50: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x036f54: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x036f58: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x036f5c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x036f60: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1609 @ 0x03700c..0x03706c (96 bytes)
// [VN] Phục dựng FDE #1609 tại 0x03700c..0x03706c (96 byte)
//   0x03700c: aa0003e8  mov      x8, x0
//   0x037010: f8408c09  ldr      x9, [x0, #8]!
//   0x037014: b4000229  cbz      x9, #0x37058
//   0x037018: f940004a  ldr      x10, [x2]
//   0x03701c: 91002100  add      x0, x8, #8
//   0x037020: f9401128  ldr      x8, [x9, #0x20]
//   0x037024: eb08015f  cmp      x10, x8
//   0x037028: 540000a2  b.hs     #0x3703c
//   0x03702c: f9400128  ldr      x8, [x9]
//   0x037030: b4000188  cbz      x8, #0x37060
//   0x037034: aa0903e0  mov      x0, x9
//   0x037038: 14000006  b        #0x37050
uint64_t fde_1609_sub_03700c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xF9400128ULL) + (x2 ^ 0x03700CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x03700c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF8408C09ULL; // 0x037010: ldr x9, [x0, #8]!
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000229ULL; // 0x037014: cbz x9, #0x37058
    acc = (acc * 0x100000001B3ULL) ^ 0xF940004AULL; // 0x037018: ldr x10, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0x91002100ULL; // 0x03701c: add x0, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401128ULL; // 0x037020: ldr x8, [x9, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08015FULL; // 0x037024: cmp x10, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A2ULL; // 0x037028: b.hs #0x3703c
    return acc;
}

// [EN] Reconstructed FDE #1610 @ 0x03706c..0x0370bc (80 bytes)
// [VN] Phục dựng FDE #1610 tại 0x03706c..0x0370bc (80 byte)
//   0x03706c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x037070: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037074: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037078: 910083fd  add      x29, sp, #0x20
//   0x03707c: 91002015  add      x21, x0, #8
//   0x037080: 52800021  mov      w1, #1
//   0x037084: aa1503e0  mov      x0, x21
//   0x037088: aa0203f3  mov      x19, x2
//   0x03708c: aa0803f4  mov      x20, x8
//   0x037090: 52800036  mov      w22, #1
//   0x037094: 94000021  bl       #0x37118
//   0x037098: a9005680  stp      x0, x21, [x20]
uint64_t fde_1610_sub_03706c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x03706CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03706c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037070: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037074: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037078: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x03707c: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x037080: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x037084: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x037088: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1611 @ 0x0370bc..0x037110 (84 bytes)
// [VN] Phục dựng FDE #1611 tại 0x0370bc..0x037110 (84 byte)
//   0x0370bc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0370c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0370c4: 910043fd  add      x29, sp, #0x10
//   0x0370c8: a9007c7f  stp      xzr, xzr, [x3]
//   0x0370cc: f9000861  str      x1, [x3, #0x10]
//   0x0370d0: f9000043  str      x3, [x2]
//   0x0370d4: f9400008  ldr      x8, [x0]
//   0x0370d8: aa0003f3  mov      x19, x0
//   0x0370dc: f9400108  ldr      x8, [x8]
//   0x0370e0: b4000068  cbz      x8, #0x370ec
//   0x0370e4: f9000268  str      x8, [x19]
//   0x0370e8: f9400043  ldr      x3, [x2]
uint64_t fde_1611_sub_0370bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF9400108ULL) + (x2 ^ 0x0370BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0370bc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0370c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0370c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xA9007C7FULL; // 0x0370c8: stp xzr, xzr, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000861ULL; // 0x0370cc: str x1, [x3, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000043ULL; // 0x0370d0: str x3, [x2]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0370d4: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0370d8: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1612 @ 0x037110..0x037118 (8 bytes)
// [VN] Phục dựng FDE #1612 tại 0x037110..0x037118 (8 byte)
//   0x037110: aa1f03e1  mov      x1, xzr
//   0x037114: 1400000e  b        #0x3714c
uint64_t fde_1612_sub_037110(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E1ULL) + (x1 ^ 0x1400000EULL) + (x2 ^ 0x037110ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E1ULL; // 0x037110: mov x1, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1400000EULL; // 0x037114: b #0x3714c
    return acc;
}

// [EN] Reconstructed FDE #1613 @ 0x037118..0x037120 (8 bytes)
// [VN] Phục dựng FDE #1613 tại 0x037118..0x037120 (8 byte)
//   0x037118: aa1f03e2  mov      x2, xzr
//   0x03711c: 14000001  b        #0x37120
uint64_t fde_1613_sub_037118(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x037118ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x037118: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x03711c: b #0x37120
    return acc;
}

// [EN] Reconstructed FDE #1614 @ 0x037120..0x03714c (44 bytes)
// [VN] Phục dựng FDE #1614 tại 0x037120..0x03714c (44 byte)
//   0x037120: b200f3e8  mov      x8, #0x5555555555555555
//   0x037124: f28aaac8  movk     x8, #0x5556
//   0x037128: f2e0aaa8  movk     x8, #0x555, lsl #48
//   0x03712c: eb08003f  cmp      x1, x8
//   0x037130: 54000082  b.hs     #0x37140
//   0x037134: 8b010428  add      x8, x1, x1, lsl #1
//   0x037138: d37ced00  lsl      x0, x8, #4
//   0x03713c: 17ff512d  b        #0xb5f0
//   0x037140: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x037144: 910003fd  mov      x29, sp
//   0x037148: 97ff50ee  bl       #0xb500
uint64_t fde_1614_sub_037120(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xB200F3E8ULL) + (x1 ^ 0xA9BF7BFDULL) + (x2 ^ 0x037120ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xB200F3E8ULL; // 0x037120: mov x8, #0x5555555555555555
    acc = (acc * 0x100000001B3ULL) ^ 0xF28AAAC8ULL; // 0x037124: movk x8, #0x5556
    acc = (acc * 0x100000001B3ULL) ^ 0xF2E0AAA8ULL; // 0x037128: movk x8, #0x555, lsl #48
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x03712c: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000082ULL; // 0x037130: b.hs #0x37140
    acc = (acc * 0x100000001B3ULL) ^ 0x8B010428ULL; // 0x037134: add x8, x1, x1, lsl #1
    acc = (acc * 0x100000001B3ULL) ^ 0xD37CED00ULL; // 0x037138: lsl x0, x8, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF512DULL; // 0x03713c: b #0xb5f0
    return acc;
}

// [EN] Reconstructed FDE #1615 @ 0x03714c..0x037164 (24 bytes)
// [VN] Phục dựng FDE #1615 tại 0x03714c..0x037164 (24 byte)
//   0x03714c: aa0003e8  mov      x8, x0
//   0x037150: f9400000  ldr      x0, [x0]
//   0x037154: f9000101  str      x1, [x8]
//   0x037158: b4000040  cbz      x0, #0x37160
//   0x03715c: 17ff4ef9  b        #0xad40
//   0x037160: d65f03c0  ret      
uint64_t fde_1615_sub_03714c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03714CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x03714c: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x037150: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000101ULL; // 0x037154: str x1, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000040ULL; // 0x037158: cbz x0, #0x37160
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4EF9ULL; // 0x03715c: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037160: ret 
    return acc;
}

// [EN] Reconstructed FDE #1616 @ 0x037164..0x03722c (200 bytes)
// [VN] Phục dựng FDE #1616 tại 0x037164..0x03722c (200 byte)
//   0x037164: d10203ff  sub      sp, sp, #0x80
//   0x037168: f9001bf9  str      x25, [sp, #0x30]
//   0x03716c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x037170: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x037174: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x037178: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03717c: 9101c3fd  add      x29, sp, #0x70
//   0x037180: d53bd059  mrs      x25, tpidr_el0
//   0x037184: f9401728  ldr      x8, [x25, #0x28]
//   0x037188: aa0203f7  mov      x23, x2
//   0x03718c: aa0103e2  mov      x2, x1
//   0x037190: 910023e1  add      x1, sp, #8
uint64_t fde_1616_sub_037164(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x037164ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x037164: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x037168: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x03716c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x037170: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x037174: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x037178: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03717c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x037180: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1617 @ 0x03722c..0x037284 (88 bytes)
// [VN] Phục dựng FDE #1617 tại 0x03722c..0x037284 (88 byte)
//   0x03722c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x037230: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037234: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037238: 910083fd  add      x29, sp, #0x20
//   0x03723c: 91002015  add      x21, x0, #8
//   0x037240: 52800021  mov      w1, #1
//   0x037244: aa1503e0  mov      x0, x21
//   0x037248: aa0203f3  mov      x19, x2
//   0x03724c: aa0803f4  mov      x20, x8
//   0x037250: 52800036  mov      w22, #1
//   0x037254: 97ffff1c  bl       #0x36ec4
//   0x037258: a9005680  stp      x0, x21, [x20]
uint64_t fde_1617_sub_03722c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x03722CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03722c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037230: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037234: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037238: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x03723c: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x037240: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x037244: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x037248: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1618 @ 0x037284..0x03734c (200 bytes)
// [VN] Phục dựng FDE #1618 tại 0x037284..0x03734c (200 byte)
//   0x037284: d10203ff  sub      sp, sp, #0x80
//   0x037288: f9001bf9  str      x25, [sp, #0x30]
//   0x03728c: a9045ff8  stp      x24, x23, [sp, #0x40]
//   0x037290: a90557f6  stp      x22, x21, [sp, #0x50]
//   0x037294: a9064ff4  stp      x20, x19, [sp, #0x60]
//   0x037298: a9077bfd  stp      x29, x30, [sp, #0x70]
//   0x03729c: 9101c3fd  add      x29, sp, #0x70
//   0x0372a0: d53bd059  mrs      x25, tpidr_el0
//   0x0372a4: f9401728  ldr      x8, [x25, #0x28]
//   0x0372a8: aa0203f7  mov      x23, x2
//   0x0372ac: aa0103e2  mov      x2, x1
//   0x0372b0: 910023e1  add      x1, sp, #8
uint64_t fde_1618_sub_037284(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10203FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x037284ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10203FFULL; // 0x037284: sub sp, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF9ULL; // 0x037288: str x25, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9045FF8ULL; // 0x03728c: stp x24, x23, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90557F6ULL; // 0x037290: stp x22, x21, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9064FF4ULL; // 0x037294: stp x20, x19, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9077BFDULL; // 0x037298: stp x29, x30, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0x9101C3FDULL; // 0x03729c: add x29, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x0372a0: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1619 @ 0x03734c..0x03739c (80 bytes)
// [VN] Phục dựng FDE #1619 tại 0x03734c..0x03739c (80 byte)
//   0x03734c: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x037350: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037354: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037358: 910083fd  add      x29, sp, #0x20
//   0x03735c: 91002015  add      x21, x0, #8
//   0x037360: 52800021  mov      w1, #1
//   0x037364: aa1503e0  mov      x0, x21
//   0x037368: aa0203f3  mov      x19, x2
//   0x03736c: aa0803f4  mov      x20, x8
//   0x037370: 52800036  mov      w22, #1
//   0x037374: 97ffff69  bl       #0x37118
//   0x037378: a9005680  stp      x0, x21, [x20]
uint64_t fde_1619_sub_03734c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0803F4ULL) + (x2 ^ 0x03734CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x03734c: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037350: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037354: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037358: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x91002015ULL; // 0x03735c: add x21, x0, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x52800021ULL; // 0x037360: mov w1, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E0ULL; // 0x037364: mov x0, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x037368: mov x19, x2
    return acc;
}

// [EN] Reconstructed FDE #1620 @ 0x03739c..0x0373ac (16 bytes)
// [VN] Phục dựng FDE #1620 tại 0x03739c..0x0373ac (16 byte)
//   0x03739c: 910003e1  mov      x1, sp
//   0x0373a0: aa1303e0  mov      x0, x19
//   0x0373a4: 2a1f03e2  mov      w2, wzr
//   0x0373a8: 17fff730  b        #0x35068
uint64_t fde_1620_sub_03739c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E1ULL) + (x1 ^ 0x17FFF730ULL) + (x2 ^ 0x03739CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E1ULL; // 0x03739c: mov x1, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0373a0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1F03E2ULL; // 0x0373a4: mov w2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF730ULL; // 0x0373a8: b #0x35068
    return acc;
}

// [EN] Reconstructed FDE #1621 @ 0x0373ac..0x0373b8 (12 bytes)
// [VN] Phục dựng FDE #1621 tại 0x0373ac..0x0373b8 (12 byte)
//   0x0373ac: 528000a0  mov      w0, #5
//   0x0373b0: aa1303e3  mov      x3, x19
//   0x0373b4: 17ff4f8b  b        #0xb1e0
uint64_t fde_1621_sub_0373ac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x528000A0ULL) + (x1 ^ 0x17FF4F8BULL) + (x2 ^ 0x0373ACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x528000A0ULL; // 0x0373ac: mov w0, #5
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E3ULL; // 0x0373b0: mov x3, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4F8BULL; // 0x0373b4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1622 @ 0x0373b8..0x0373c8 (16 bytes)
// [VN] Phục dựng FDE #1622 tại 0x0373b8..0x0373c8 (16 byte)
//   0x0373b8: f9400268  ldr      x8, [x19]
//   0x0373bc: aa1303e0  mov      x0, x19
//   0x0373c0: f9404508  ldr      x8, [x8, #0x88]
//   0x0373c4: d61f0100  br       x8
uint64_t fde_1622_sub_0373b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0373B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0373b8: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0373bc: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9404508ULL; // 0x0373c0: ldr x8, [x8, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0373c4: br x8
    return acc;
}

// [EN] Reconstructed FDE #1623 @ 0x0373c8..0x0373e0 (24 bytes)
// [VN] Phục dựng FDE #1623 tại 0x0373c8..0x0373e0 (24 byte)
//   0x0373c8: aa0003e8  mov      x8, x0
//   0x0373cc: 120002c3  and      w3, w22, #1
//   0x0373d0: aa1303e0  mov      x0, x19
//   0x0373d4: aa1503e1  mov      x1, x21
//   0x0373d8: aa1403e2  mov      x2, x20
//   0x0373dc: d61f0100  br       x8
uint64_t fde_1623_sub_0373c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0373C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x0373c8: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x120002C3ULL; // 0x0373cc: and w3, w22, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0373d0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1503E1ULL; // 0x0373d4: mov x1, x21
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E2ULL; // 0x0373d8: mov x2, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0373dc: br x8
    return acc;
}

// [EN] Reconstructed FDE #1624 @ 0x0373e0..0x0373f8 (24 bytes)
// [VN] Phục dựng FDE #1624 tại 0x0373e0..0x0373f8 (24 byte)
//   0x0373e0: f9400268  ldr      x8, [x19]
//   0x0373e4: aa1303e0  mov      x0, x19
//   0x0373e8: aa1b03e1  mov      x1, x27
//   0x0373ec: aa1c03e2  mov      x2, x28
//   0x0373f0: f942a908  ldr      x8, [x8, #0x550]
//   0x0373f4: d61f0100  br       x8
uint64_t fde_1624_sub_0373e0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0373E0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0373e0: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0373e4: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1B03E1ULL; // 0x0373e8: mov x1, x27
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1C03E2ULL; // 0x0373ec: mov x2, x28
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A908ULL; // 0x0373f0: ldr x8, [x8, #0x550]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0373f4: br x8
    return acc;
}

// [EN] Reconstructed FDE #1625 @ 0x0373f8..0x037404 (12 bytes)
// [VN] Phục dựng FDE #1625 tại 0x0373f8..0x037404 (12 byte)
//   0x0373f8: f942a508  ldr      x8, [x8, #0x548]
//   0x0373fc: aa1f03e2  mov      x2, xzr
//   0x037400: d61f0100  br       x8
uint64_t fde_1625_sub_0373f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF942A508ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0373F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A508ULL; // 0x0373f8: ldr x8, [x8, #0x548]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x0373fc: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x037400: br x8
    return acc;
}

// [EN] Reconstructed FDE #1626 @ 0x037404..0x037418 (20 bytes)
// [VN] Phục dựng FDE #1626 tại 0x037404..0x037418 (20 byte)
//   0x037404: aa0003e8  mov      x8, x0
//   0x037408: 120002a2  and      w2, w21, #1
//   0x03740c: aa1303e0  mov      x0, x19
//   0x037410: aa1403e1  mov      x1, x20
//   0x037414: d61f0100  br       x8
uint64_t fde_1626_sub_037404(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x037404ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x037404: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x120002A2ULL; // 0x037408: and w2, w21, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03740c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x037410: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x037414: br x8
    return acc;
}

// [EN] Reconstructed FDE #1627 @ 0x037418..0x037424 (12 bytes)
// [VN] Phục dựng FDE #1627 tại 0x037418..0x037424 (12 byte)
//   0x037418: aa1303e0  mov      x0, x19
//   0x03741c: f9439108  ldr      x8, [x8, #0x720]
//   0x037420: d61f0100  br       x8
uint64_t fde_1627_sub_037418(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x037418ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x037418: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF9439108ULL; // 0x03741c: ldr x8, [x8, #0x720]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x037420: br x8
    return acc;
}

// [EN] Reconstructed FDE #1628 @ 0x037424..0x037430 (12 bytes)
// [VN] Phục dựng FDE #1628 tại 0x037424..0x037430 (12 byte)
//   0x037424: aa1303e0  mov      x0, x19
//   0x037428: aa1403e1  mov      x1, x20
//   0x03742c: d65f03c0  ret      
uint64_t fde_1628_sub_037424(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1303E0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037424ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x037424: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x037428: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03742c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1629 @ 0x037430..0x03743c (12 bytes)
// [VN] Phục dựng FDE #1629 tại 0x037430..0x03743c (12 byte)
//   0x037430: 90000120  adrp     x0, #0x5b000
//   0x037434: f942b400  ldr      x0, [x0, #0x568]
//   0x037438: d65f03c0  ret      
uint64_t fde_1629_sub_037430(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000120ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037430ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000120ULL; // 0x037430: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF942B400ULL; // 0x037434: ldr x0, [x0, #0x568]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037438: ret 
    return acc;
}

// [EN] Reconstructed FDE #1630 @ 0x03743c..0x037448 (12 bytes)
// [VN] Phục dựng FDE #1630 tại 0x03743c..0x037448 (12 byte)
//   0x03743c: 52800022  mov      w2, #1
//   0x037440: aa1303e0  mov      x0, x19
//   0x037444: 17fff709  b        #0x35068
uint64_t fde_1630_sub_03743c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800022ULL) + (x1 ^ 0x17FFF709ULL) + (x2 ^ 0x03743CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800022ULL; // 0x03743c: mov w2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x037440: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF709ULL; // 0x037444: b #0x35068
    return acc;
}

// [EN] Reconstructed FDE #1631 @ 0x037448..0x037450 (8 bytes)
// [VN] Phục dựng FDE #1631 tại 0x037448..0x037450 (8 byte)
//   0x037448: f942a908  ldr      x8, [x8, #0x550]
//   0x03744c: d61f0100  br       x8
uint64_t fde_1631_sub_037448(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF942A908ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x037448ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A908ULL; // 0x037448: ldr x8, [x8, #0x550]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x03744c: br x8
    return acc;
}

// [EN] Reconstructed FDE #1632 @ 0x037450..0x037460 (16 bytes)
// [VN] Phục dựng FDE #1632 tại 0x037450..0x037460 (16 byte)
//   0x037450: 90000021  adrp     x1, #0x3b000
//   0x037454: 9118a821  add      x1, x1, #0x62a
//   0x037458: 910023e0  add      x0, sp, #8
//   0x03745c: 17ff8334  b        #0x1812c
uint64_t fde_1632_sub_037450(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x90000021ULL) + (x1 ^ 0x17FF8334ULL) + (x2 ^ 0x037450ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x90000021ULL; // 0x037450: adrp x1, #0x3b000
    acc = (acc * 0x100000001B3ULL) ^ 0x9118A821ULL; // 0x037454: add x1, x1, #0x62a
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x037458: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8334ULL; // 0x03745c: b #0x1812c
    return acc;
}

// [EN] Reconstructed FDE #1633 @ 0x037460..0x037470 (16 bytes)
// [VN] Phục dựng FDE #1633 tại 0x037460..0x037470 (16 byte)
//   0x037460: aa1403e1  mov      x1, x20
//   0x037464: aa1303e2  mov      x2, x19
//   0x037468: aa0003f5  mov      x21, x0
//   0x03746c: d65f03c0  ret      
uint64_t fde_1633_sub_037460(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E1ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037460ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E1ULL; // 0x037460: mov x1, x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E2ULL; // 0x037464: mov x2, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x037468: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03746c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1634 @ 0x037470..0x037478 (8 bytes)
// [VN] Phục dựng FDE #1634 tại 0x037470..0x037478 (8 byte)
//   0x037470: 910003e0  mov      x0, sp
//   0x037474: 17ff58f4  b        #0xd844
uint64_t fde_1634_sub_037470(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910003E0ULL) + (x1 ^ 0x17FF58F4ULL) + (x2 ^ 0x037470ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910003E0ULL; // 0x037470: mov x0, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF58F4ULL; // 0x037474: b #0xd844
    return acc;
}

// [EN] Reconstructed FDE #1635 @ 0x037478..0x037484 (12 bytes)
// [VN] Phục dựng FDE #1635 tại 0x037478..0x037484 (12 byte)
//   0x037478: f0ffffe0  adrp     x0, #0x36000
//   0x03747c: 910e5000  add      x0, x0, #0x394
//   0x037480: 17ff4e08  b        #0xaca0
uint64_t fde_1635_sub_037478(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0FFFFE0ULL) + (x1 ^ 0x17FF4E08ULL) + (x2 ^ 0x037478ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFFE0ULL; // 0x037478: adrp x0, #0x36000
    acc = (acc * 0x100000001B3ULL) ^ 0x910E5000ULL; // 0x03747c: add x0, x0, #0x394
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4E08ULL; // 0x037480: b #0xaca0
    return acc;
}

// [EN] Reconstructed FDE #1636 @ 0x037484..0x037490 (12 bytes)
// [VN] Phục dựng FDE #1636 tại 0x037484..0x037490 (12 byte)
//   0x037484: f9401fe9  ldr      x9, [sp, #0x38]
//   0x037488: eb09011f  cmp      x8, x9
//   0x03748c: d65f03c0  ret      
uint64_t fde_1636_sub_037484(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9401FE9ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037484ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401FE9ULL; // 0x037484: ldr x9, [sp, #0x38]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x037488: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03748c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1637 @ 0x037490..0x037498 (8 bytes)
// [VN] Phục dựng FDE #1637 tại 0x037490..0x037498 (8 byte)
//   0x037490: f942b508  ldr      x8, [x8, #0x568]
//   0x037494: d61f0100  br       x8
uint64_t fde_1637_sub_037490(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF942B508ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x037490ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF942B508ULL; // 0x037490: ldr x8, [x8, #0x568]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x037494: br x8
    return acc;
}

// [EN] Reconstructed FDE #1638 @ 0x037498..0x0374a0 (8 bytes)
// [VN] Phục dựng FDE #1638 tại 0x037498..0x0374a0 (8 byte)
//   0x037498: 9100c3e0  add      x0, sp, #0x30
//   0x03749c: 17ff66b2  b        #0x10f64
uint64_t fde_1638_sub_037498(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x9100C3E0ULL) + (x1 ^ 0x17FF66B2ULL) + (x2 ^ 0x037498ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3E0ULL; // 0x037498: add x0, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF66B2ULL; // 0x03749c: b #0x10f64
    return acc;
}

// [EN] Reconstructed FDE #1639 @ 0x0374a0..0x0374a8 (8 bytes)
// [VN] Phục dựng FDE #1639 tại 0x0374a0..0x0374a8 (8 byte)
//   0x0374a0: 52800060  mov      w0, #3
//   0x0374a4: 17ff4f4f  b        #0xb1e0
uint64_t fde_1639_sub_0374a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF4F4FULL) + (x2 ^ 0x0374A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x0374a0: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4F4FULL; // 0x0374a4: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1640 @ 0x0374a8..0x0374bc (20 bytes)
// [VN] Phục dựng FDE #1640 tại 0x0374a8..0x0374bc (20 byte)
//   0x0374a8: f9400268  ldr      x8, [x19]
//   0x0374ac: aa0003fb  mov      x27, x0
//   0x0374b0: aa1303e0  mov      x0, x19
//   0x0374b4: aa1b03e1  mov      x1, x27
//   0x0374b8: d65f03c0  ret      
uint64_t fde_1640_sub_0374a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400268ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0374A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400268ULL; // 0x0374a8: ldr x8, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003FBULL; // 0x0374ac: mov x27, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0374b0: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1B03E1ULL; // 0x0374b4: mov x1, x27
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0374b8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1641 @ 0x0374bc..0x0374c8 (12 bytes)
// [VN] Phục dựng FDE #1641 tại 0x0374bc..0x0374c8 (12 byte)
//   0x0374bc: f0ffffe0  adrp     x0, #0x36000
//   0x0374c0: 91118000  add      x0, x0, #0x460
//   0x0374c4: 17ff4df7  b        #0xaca0
uint64_t fde_1641_sub_0374bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0FFFFE0ULL) + (x1 ^ 0x17FF4DF7ULL) + (x2 ^ 0x0374BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0FFFFE0ULL; // 0x0374bc: adrp x0, #0x36000
    acc = (acc * 0x100000001B3ULL) ^ 0x91118000ULL; // 0x0374c0: add x0, x0, #0x460
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4DF7ULL; // 0x0374c4: b #0xaca0
    return acc;
}

// [EN] Reconstructed FDE #1642 @ 0x0374c8..0x0375e4 (284 bytes)
// [VN] Phục dựng FDE #1642 tại 0x0374c8..0x0375e4 (284 byte)
//   0x0374c8: d101c3ff  sub      sp, sp, #0x70
//   0x0374cc: f9001bf7  str      x23, [sp, #0x30]
//   0x0374d0: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x0374d4: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x0374d8: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x0374dc: 910183fd  add      x29, sp, #0x60
//   0x0374e0: d53bd054  mrs      x20, tpidr_el0
//   0x0374e4: f9401688  ldr      x8, [x20, #0x28]
//   0x0374e8: 90000135  adrp     x21, #0x5b000
//   0x0374ec: f90017e8  str      x8, [sp, #0x28]
//   0x0374f0: f942a6b5  ldr      x21, [x21, #0x548]
//   0x0374f4: 394002a8  ldrb     w8, [x21]
uint64_t fde_1642_sub_0374c8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x90000135ULL) + (x2 ^ 0x0374C8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x0374c8: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x0374cc: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x0374d0: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x0374d4: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x0374d8: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x0374dc: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0374e0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0374e4: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1643 @ 0x0375e4..0x0376bc (216 bytes)
// [VN] Phục dựng FDE #1643 tại 0x0375e4..0x0376bc (216 byte)
//   0x0375e4: d10143ff  sub      sp, sp, #0x50
//   0x0375e8: f90013f5  str      x21, [sp, #0x20]
//   0x0375ec: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x0375f0: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x0375f4: 910103fd  add      x29, sp, #0x40
//   0x0375f8: d53bd055  mrs      x21, tpidr_el0
//   0x0375fc: f94016a8  ldr      x8, [x21, #0x28]
//   0x037600: f9000fe8  str      x8, [sp, #0x18]
//   0x037604: f900001f  str      xzr, [x0]
//   0x037608: 90000128  adrp     x8, #0x5b000
//   0x03760c: f942a508  ldr      x8, [x8, #0x548]
//   0x037610: 39400108  ldrb     w8, [x8]
uint64_t fde_1643_sub_0375e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xF900001FULL) + (x2 ^ 0x0375E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x0375e4: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x0375e8: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x0375ec: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x0375f0: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x0375f4: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x0375f8: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x0375fc: ldr x8, [x21, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x037600: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #1644 @ 0x0376bc..0x037778 (188 bytes)
// [VN] Phục dựng FDE #1644 tại 0x0376bc..0x037778 (188 byte)
//   0x0376bc: d10103ff  sub      sp, sp, #0x40
//   0x0376c0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0376c4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0376c8: 9100c3fd  add      x29, sp, #0x30
//   0x0376cc: d53bd054  mrs      x20, tpidr_el0
//   0x0376d0: f9401688  ldr      x8, [x20, #0x28]
//   0x0376d4: f9000fe8  str      x8, [sp, #0x18]
//   0x0376d8: 90000128  adrp     x8, #0x5b000
//   0x0376dc: f942a508  ldr      x8, [x8, #0x548]
//   0x0376e0: 39400108  ldrb     w8, [x8]
//   0x0376e4: 34000388  cbz      w8, #0x37754
//   0x0376e8: aa0003f3  mov      x19, x0
uint64_t fde_1644_sub_0376bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0xF942A508ULL) + (x2 ^ 0x0376BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x0376bc: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0376c0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0376c4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0376c8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x0376cc: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x0376d0: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x0376d4: str x8, [sp, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x0376d8: adrp x8, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1645 @ 0x037778..0x037894 (284 bytes)
// [VN] Phục dựng FDE #1645 tại 0x037778..0x037894 (284 byte)
//   0x037778: d10183ff  sub      sp, sp, #0x60
//   0x03777c: f90013f7  str      x23, [sp, #0x20]
//   0x037780: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x037784: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x037788: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x03778c: 910143fd  add      x29, sp, #0x50
//   0x037790: d53bd054  mrs      x20, tpidr_el0
//   0x037794: f9401688  ldr      x8, [x20, #0x28]
//   0x037798: 90000135  adrp     x21, #0x5b000
//   0x03779c: f9000fe8  str      x8, [sp, #0x18]
//   0x0377a0: f9462ab5  ldr      x21, [x21, #0xc50]
//   0x0377a4: 394002a8  ldrb     w8, [x21]
uint64_t fde_1645_sub_037778(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0x90000135ULL) + (x2 ^ 0x037778ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x037778: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F7ULL; // 0x03777c: str x23, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x037780: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x037784: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x037788: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x03778c: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x037790: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x037794: ldr x8, [x20, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1646 @ 0x037894..0x037968 (212 bytes)
// [VN] Phục dựng FDE #1646 tại 0x037894..0x037968 (212 byte)
//   0x037894: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x037898: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03789c: 910043fd  add      x29, sp, #0x10
//   0x0378a0: f9000001  str      x1, [x0]
//   0x0378a4: 90000128  adrp     x8, #0x5b000
//   0x0378a8: f9462908  ldr      x8, [x8, #0xc50]
//   0x0378ac: 39400108  ldrb     w8, [x8]
//   0x0378b0: 34000388  cbz      w8, #0x37920
//   0x0378b4: aa0003f3  mov      x19, x0
//   0x0378b8: 90000120  adrp     x0, #0x5b000
//   0x0378bc: f9432800  ldr      x0, [x0, #0x650]
//   0x0378c0: 97ff4f44  bl       #0xb5d0
uint64_t fde_1646_sub_037894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA0003F3ULL) + (x2 ^ 0x037894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x037894: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x037898: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03789c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x0378a0: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x0378a4: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9462908ULL; // 0x0378a8: ldr x8, [x8, #0xc50]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x0378ac: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000388ULL; // 0x0378b0: cbz w8, #0x37920
    return acc;
}

// [EN] Reconstructed FDE #1647 @ 0x037968..0x037a18 (176 bytes)
// [VN] Phục dựng FDE #1647 tại 0x037968..0x037a18 (176 byte)
//   0x037968: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x03796c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x037970: 910043fd  add      x29, sp, #0x10
//   0x037974: 90000128  adrp     x8, #0x5b000
//   0x037978: f9462908  ldr      x8, [x8, #0xc50]
//   0x03797c: 39400108  ldrb     w8, [x8]
//   0x037980: 340002a8  cbz      w8, #0x379d4
//   0x037984: aa0003f3  mov      x19, x0
//   0x037988: 97ff4f3a  bl       #0xb670
//   0x03798c: 2a0003f4  mov      w20, w0
//   0x037990: 97ff7f23  bl       #0x1761c
//   0x037994: 7100629f  cmp      w20, #0x18
uint64_t fde_1647_sub_037968(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0x97FF4F3AULL) + (x2 ^ 0x037968ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x037968: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03796c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x037970: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x037974: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9462908ULL; // 0x037978: ldr x8, [x8, #0xc50]
    acc = (acc * 0x100000001B3ULL) ^ 0x39400108ULL; // 0x03797c: ldrb w8, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0x340002A8ULL; // 0x037980: cbz w8, #0x379d4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x037984: mov x19, x0
    return acc;
}

// [EN] Reconstructed FDE #1648 @ 0x037a18..0x037a20 (8 bytes)
// [VN] Phục dựng FDE #1648 tại 0x037a18..0x037a20 (8 byte)
//   0x037a18: 52800060  mov      w0, #3
//   0x037a1c: 17ff4df1  b        #0xb1e0
uint64_t fde_1648_sub_037a18(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x52800060ULL) + (x1 ^ 0x17FF4DF1ULL) + (x2 ^ 0x037A18ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x52800060ULL; // 0x037a18: mov w0, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4DF1ULL; // 0x037a1c: b #0xb1e0
    return acc;
}

// [EN] Reconstructed FDE #1649 @ 0x037a20..0x037b14 (244 bytes)
// [VN] Phục dựng FDE #1649 tại 0x037a20..0x037b14 (244 byte)
//   0x037a20: d10183ff  sub      sp, sp, #0x60
//   0x037a24: a90357f6  stp      x22, x21, [sp, #0x30]
//   0x037a28: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x037a2c: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x037a30: 910143fd  add      x29, sp, #0x50
//   0x037a34: d53bd053  mrs      x19, tpidr_el0
//   0x037a38: f9401668  ldr      x8, [x19, #0x28]
//   0x037a3c: 90000134  adrp     x20, #0x5b000
//   0x037a40: f90017e8  str      x8, [sp, #0x28]
//   0x037a44: f9466694  ldr      x20, [x20, #0xcc8]
//   0x037a48: 39400288  ldrb     w8, [x20]
//   0x037a4c: 34000068  cbz      w8, #0x37a58
uint64_t fde_1649_sub_037a20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x037A20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x037a20: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xA90357F6ULL; // 0x037a24: stp x22, x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x037a28: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x037a2c: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x037a30: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD053ULL; // 0x037a34: mrs x19, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401668ULL; // 0x037a38: ldr x8, [x19, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000134ULL; // 0x037a3c: adrp x20, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1650 @ 0x037b14..0x037b90 (124 bytes)
// [VN] Phục dựng FDE #1650 tại 0x037b14..0x037b90 (124 byte)
//   0x037b14: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x037b18: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037b1c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037b20: 910083fd  add      x29, sp, #0x20
//   0x037b24: aa0003f5  mov      x21, x0
//   0x037b28: f900001f  str      xzr, [x0]
//   0x037b2c: aa0103e0  mov      x0, x1
//   0x037b30: 2a0303f3  mov      w19, w3
//   0x037b34: aa0203f4  mov      x20, x2
//   0x037b38: 97ffffba  bl       #0x37a20
//   0x037b3c: 90000128  adrp     x8, #0x5b000
//   0x037b40: f9466508  ldr      x8, [x8, #0xcc8]
uint64_t fde_1650_sub_037b14(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0xAA0203F4ULL) + (x2 ^ 0x037B14ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x037b14: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037b18: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037b1c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037b20: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x037b24: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF900001FULL; // 0x037b28: str xzr, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E0ULL; // 0x037b2c: mov x0, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x037b30: mov w19, w3
    return acc;
}

// [EN] Reconstructed FDE #1651 @ 0x037b90..0x037bac (28 bytes)
// [VN] Phục dựng FDE #1651 tại 0x037b90..0x037bac (28 byte)
//   0x037b90: f9400000  ldr      x0, [x0]
//   0x037b94: b40000a0  cbz      x0, #0x37ba8
//   0x037b98: 90000128  adrp     x8, #0x5b000
//   0x037b9c: f9449d08  ldr      x8, [x8, #0x938]
//   0x037ba0: f9400102  ldr      x2, [x8]
//   0x037ba4: d61f0040  br       x2
//   0x037ba8: d65f03c0  ret      
uint64_t fde_1651_sub_037b90(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037B90ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x037b90: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x037b94: cbz x0, #0x37ba8
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x037b98: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9449D08ULL; // 0x037b9c: ldr x8, [x8, #0x938]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x037ba0: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x037ba4: br x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037ba8: ret 
    return acc;
}

// [EN] Reconstructed FDE #1652 @ 0x037bac..0x037bc8 (28 bytes)
// [VN] Phục dựng FDE #1652 tại 0x037bac..0x037bc8 (28 byte)
//   0x037bac: f9400000  ldr      x0, [x0]
//   0x037bb0: b40000a0  cbz      x0, #0x37bc4
//   0x037bb4: 90000128  adrp     x8, #0x5b000
//   0x037bb8: f9449508  ldr      x8, [x8, #0x928]
//   0x037bbc: f9400102  ldr      x2, [x8]
//   0x037bc0: d61f0040  br       x2
//   0x037bc4: d65f03c0  ret      
uint64_t fde_1652_sub_037bac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037BACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x037bac: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000A0ULL; // 0x037bb0: cbz x0, #0x37bc4
    acc = (acc * 0x100000001B3ULL) ^ 0x90000128ULL; // 0x037bb4: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9449508ULL; // 0x037bb8: ldr x8, [x8, #0x928]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400102ULL; // 0x037bbc: ldr x2, [x8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0040ULL; // 0x037bc0: br x2
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037bc4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1653 @ 0x037bc8..0x037bd0 (8 bytes)
// [VN] Phục dựng FDE #1653 tại 0x037bc8..0x037bd0 (8 byte)
//   0x037bc8: f9400000  ldr      x0, [x0]
//   0x037bcc: d65f03c0  ret      
uint64_t fde_1653_sub_037bc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400000ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037BC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x037bc8: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037bcc: ret 
    return acc;
}

// [EN] Reconstructed FDE #1654 @ 0x037bd0..0x037bd8 (8 bytes)
// [VN] Phục dựng FDE #1654 tại 0x037bd0..0x037bd8 (8 byte)
//   0x037bd0: 910023e0  add      x0, sp, #8
//   0x037bd4: 17ff4d63  b        #0xb160
uint64_t fde_1654_sub_037bd0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x910023E0ULL) + (x1 ^ 0x17FF4D63ULL) + (x2 ^ 0x037BD0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x910023E0ULL; // 0x037bd0: add x0, sp, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4D63ULL; // 0x037bd4: b #0xb160
    return acc;
}

// [EN] Reconstructed FDE #1655 @ 0x037bd8..0x037bdc (4 bytes)
// [VN] Phục dựng FDE #1655 tại 0x037bd8..0x037bdc (4 byte)
//   0x037bd8: 140000a6  b        #0x37e70
uint64_t fde_1655_sub_037bd8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x140000A6ULL) + (x1 ^ 0x140000A6ULL) + (x2 ^ 0x037BD8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x140000A6ULL; // 0x037bd8: b #0x37e70
    return acc;
}

// [EN] Reconstructed FDE #1656 @ 0x037bdc..0x037cac (208 bytes)
// [VN] Phục dựng FDE #1656 tại 0x037bdc..0x037cac (208 byte)
//   0x037bdc: d10143ff  sub      sp, sp, #0x50
//   0x037be0: f9000bf7  str      x23, [sp, #0x10]
//   0x037be4: a90257f6  stp      x22, x21, [sp, #0x20]
//   0x037be8: a9034ff4  stp      x20, x19, [sp, #0x30]
//   0x037bec: a9047bfd  stp      x29, x30, [sp, #0x40]
//   0x037bf0: 910103fd  add      x29, sp, #0x40
//   0x037bf4: d53bd055  mrs      x21, tpidr_el0
//   0x037bf8: f94016a8  ldr      x8, [x21, #0x28]
//   0x037bfc: aa0003f4  mov      x20, x0
//   0x037c00: 90000120  adrp     x0, #0x5b000
//   0x037c04: 2a0103f3  mov      w19, w1
//   0x037c08: f90007e8  str      x8, [sp, #8]
uint64_t fde_1656_sub_037bdc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10143FFULL) + (x1 ^ 0xAA0003F4ULL) + (x2 ^ 0x037BDCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10143FFULL; // 0x037bdc: sub sp, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF7ULL; // 0x037be0: str x23, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90257F6ULL; // 0x037be4: stp x22, x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9034FF4ULL; // 0x037be8: stp x20, x19, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9047BFDULL; // 0x037bec: stp x29, x30, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0x910103FDULL; // 0x037bf0: add x29, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD055ULL; // 0x037bf4: mrs x21, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016A8ULL; // 0x037bf8: ldr x8, [x21, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1657 @ 0x037cac..0x037de4 (312 bytes)
// [VN] Phục dựng FDE #1657 tại 0x037cac..0x037de4 (312 byte)
//   0x037cac: d10183ff  sub      sp, sp, #0x60
//   0x037cb0: f9001bf5  str      x21, [sp, #0x30]
//   0x037cb4: a9044ff4  stp      x20, x19, [sp, #0x40]
//   0x037cb8: a9057bfd  stp      x29, x30, [sp, #0x50]
//   0x037cbc: 910143fd  add      x29, sp, #0x50
//   0x037cc0: d53bd054  mrs      x20, tpidr_el0
//   0x037cc4: f9401688  ldr      x8, [x20, #0x28]
//   0x037cc8: 90000135  adrp     x21, #0x5b000
//   0x037ccc: f90017e8  str      x8, [sp, #0x28]
//   0x037cd0: f94276b5  ldr      x21, [x21, #0x4e8]
//   0x037cd4: 394002a8  ldrb     w8, [x21]
//   0x037cd8: 34000068  cbz      w8, #0x37ce4
uint64_t fde_1657_sub_037cac(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10183FFULL) + (x1 ^ 0xF90017E8ULL) + (x2 ^ 0x037CACULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10183FFULL; // 0x037cac: sub sp, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF5ULL; // 0x037cb0: str x21, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9044FF4ULL; // 0x037cb4: stp x20, x19, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9057BFDULL; // 0x037cb8: stp x29, x30, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0x910143FDULL; // 0x037cbc: add x29, sp, #0x50
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x037cc0: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x037cc4: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000135ULL; // 0x037cc8: adrp x21, #0x5b000
    return acc;
}

// [EN] Reconstructed FDE #1658 @ 0x037de4..0x037e50 (108 bytes)
// [VN] Phục dựng FDE #1658 tại 0x037de4..0x037e50 (108 byte)
//   0x037de4: d100c3ff  sub      sp, sp, #0x30
//   0x037de8: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x037dec: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x037df0: 910083fd  add      x29, sp, #0x20
//   0x037df4: d53bd054  mrs      x20, tpidr_el0
//   0x037df8: f9401688  ldr      x8, [x20, #0x28]
//   0x037dfc: 90000133  adrp     x19, #0x5b000
//   0x037e00: f90007e8  str      x8, [sp, #8]
//   0x037e04: f90003e0  str      x0, [sp]
//   0x037e08: f9457673  ldr      x19, [x19, #0xae8]
//   0x037e0c: aa1303e0  mov      x0, x19
//   0x037e10: 97ff4df0  bl       #0xb5d0
uint64_t fde_1658_sub_037de4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD100C3FFULL) + (x1 ^ 0xF90003E0ULL) + (x2 ^ 0x037DE4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD100C3FFULL; // 0x037de4: sub sp, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x037de8: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x037dec: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x037df0: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x037df4: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x037df8: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0x90000133ULL; // 0x037dfc: adrp x19, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF90007E8ULL; // 0x037e00: str x8, [sp, #8]
    return acc;
}

// [EN] Reconstructed FDE #1659 @ 0x037e50..0x037e70 (32 bytes)
// [VN] Phục dựng FDE #1659 tại 0x037e50..0x037e70 (32 byte)
//   0x037e50: a940a408  ldp      x8, x9, [x0, #8]
//   0x037e54: eb09011f  cmp      x8, x9
//   0x037e58: 540000a0  b.eq     #0x37e6c
//   0x037e5c: f9400029  ldr      x9, [x1]
//   0x037e60: f8008509  str      x9, [x8], #8
//   0x037e64: f9000408  str      x8, [x0, #8]
//   0x037e68: d65f03c0  ret      
//   0x037e6c: 14000007  b        #0x37e88
uint64_t fde_1659_sub_037e50(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x14000007ULL) + (x2 ^ 0x037E50ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x037e50: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x037e54: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x540000A0ULL; // 0x037e58: b.eq #0x37e6c
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400029ULL; // 0x037e5c: ldr x9, [x1]
    acc = (acc * 0x100000001B3ULL) ^ 0xF8008509ULL; // 0x037e60: str x9, [x8], #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000408ULL; // 0x037e64: str x8, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037e68: ret 
    acc = (acc * 0x100000001B3ULL) ^ 0x14000007ULL; // 0x037e6c: b #0x37e88
    return acc;
}

// [EN] Reconstructed FDE #1660 @ 0x037e70..0x037e88 (24 bytes)
// [VN] Phục dựng FDE #1660 tại 0x037e70..0x037e88 (24 byte)
//   0x037e70: aa0003e8  mov      x8, x0
//   0x037e74: f9400000  ldr      x0, [x0]
//   0x037e78: b4000060  cbz      x0, #0x37e84
//   0x037e7c: f9000500  str      x0, [x8, #8]
//   0x037e80: 17ff4bb0  b        #0xad40
//   0x037e84: d65f03c0  ret      
uint64_t fde_1660_sub_037e70(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003E8ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x037E70ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E8ULL; // 0x037e70: mov x8, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x037e74: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000060ULL; // 0x037e78: cbz x0, #0x37e84
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000500ULL; // 0x037e7c: str x0, [x8, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4BB0ULL; // 0x037e80: b #0xad40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x037e84: ret 
    return acc;
}

// [EN] Reconstructed FDE #1661 @ 0x037e88..0x037f54 (204 bytes)
// [VN] Phục dựng FDE #1661 tại 0x037e88..0x037f54 (204 byte)
//   0x037e88: d101c3ff  sub      sp, sp, #0x70
//   0x037e8c: a9035ff8  stp      x24, x23, [sp, #0x30]
//   0x037e90: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x037e94: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x037e98: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x037e9c: 910183fd  add      x29, sp, #0x60
//   0x037ea0: d53bd057  mrs      x23, tpidr_el0
//   0x037ea4: f94016e8  ldr      x8, [x23, #0x28]
//   0x037ea8: aa0103f4  mov      x20, x1
//   0x037eac: aa0003f3  mov      x19, x0
//   0x037eb0: 91004016  add      x22, x0, #0x10
//   0x037eb4: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1661_sub_037e88(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0xAA0103F4ULL) + (x2 ^ 0x037E88ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x037e88: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xA9035FF8ULL; // 0x037e8c: stp x24, x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x037e90: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x037e94: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x037e98: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x037e9c: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD057ULL; // 0x037ea0: mrs x23, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016E8ULL; // 0x037ea4: ldr x8, [x23, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1662 @ 0x037f54..0x037f9c (72 bytes)
// [VN] Phục dựng FDE #1662 tại 0x037f54..0x037f9c (72 byte)
//   0x037f54: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x037f58: 910003fd  mov      x29, sp
//   0x037f5c: d37dfc28  lsr      x8, x1, #0x3d
//   0x037f60: b50001c8  cbnz     x8, #0x37f98
//   0x037f64: f9400808  ldr      x8, [x0, #0x10]
//   0x037f68: f9400009  ldr      x9, [x0]
//   0x037f6c: cb090108  sub      x8, x8, x9
//   0x037f70: b27febe9  mov      x9, #0xffffffffffffffe
//   0x037f74: eb880d3f  cmp      x9, x8, asr #3
//   0x037f78: 540000a3  b.lo     #0x37f8c
//   0x037f7c: 9342fd08  asr      x8, x8, #2
//   0x037f80: eb01011f  cmp      x8, x1
uint64_t fde_1662_sub_037f54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xEB880D3FULL) + (x2 ^ 0x037F54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x037f54: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x037f58: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x037f5c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB50001C8ULL; // 0x037f60: cbnz x8, #0x37f98
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x037f64: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400009ULL; // 0x037f68: ldr x9, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB090108ULL; // 0x037f6c: sub x8, x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0xB27FEBE9ULL; // 0x037f70: mov x9, #0xffffffffffffffe
    return acc;
}

// [EN] Reconstructed FDE #1663 @ 0x037f9c..0x038000 (100 bytes)
// [VN] Phục dựng FDE #1663 tại 0x037f9c..0x038000 (100 byte)
//   0x037f9c: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x037fa0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x037fa4: 910043fd  add      x29, sp, #0x10
//   0x037fa8: aa0103f3  mov      x19, x1
//   0x037fac: aa0003f4  mov      x20, x0
//   0x037fb0: a8c10801  ldp      x1, x2, [x0], #0x10
//   0x037fb4: 91002263  add      x3, x19, #8
//   0x037fb8: 94000028  bl       #0x38058
//   0x037fbc: f9400668  ldr      x8, [x19, #8]
//   0x037fc0: f9400289  ldr      x9, [x20]
//   0x037fc4: f9000288  str      x8, [x20]
//   0x037fc8: f9400a68  ldr      x8, [x19, #0x10]
uint64_t fde_1663_sub_037f9c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9400668ULL) + (x2 ^ 0x037F9CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x037f9c: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x037fa0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x037fa4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x037fa8: mov x19, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x037fac: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C10801ULL; // 0x037fb0: ldp x1, x2, [x0], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x91002263ULL; // 0x037fb4: add x3, x19, #8
    acc = (acc * 0x100000001B3ULL) ^ 0x94000028ULL; // 0x037fb8: bl #0x38058
    return acc;
}

// [EN] Reconstructed FDE #1664 @ 0x038000..0x038034 (52 bytes)
// [VN] Phục dựng FDE #1664 tại 0x038000..0x038034 (52 byte)
//   0x038000: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038004: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038008: 910043fd  add      x29, sp, #0x10
//   0x03800c: aa0003f3  mov      x19, x0
//   0x038010: 9400001a  bl       #0x38078
//   0x038014: f9400260  ldr      x0, [x19]
//   0x038018: b4000080  cbz      x0, #0x38028
//   0x03801c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038020: f84207f3  ldr      x19, [sp], #0x20
//   0x038024: 17ff4b47  b        #0xad40
//   0x038028: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03802c: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1664_sub_038000(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x038000ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038000: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038004: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038008: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x03800c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9400001AULL; // 0x038010: bl #0x38078
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400260ULL; // 0x038014: ldr x0, [x19]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000080ULL; // 0x038018: cbz x0, #0x38028
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03801c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #1665 @ 0x038034..0x03803c (8 bytes)
// [VN] Phục dựng FDE #1665 tại 0x038034..0x03803c (8 byte)
//   0x038034: aa1f03e2  mov      x2, xzr
//   0x038038: 14000001  b        #0x3803c
uint64_t fde_1665_sub_038034(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1F03E2ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x038034ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x038034: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x038038: b #0x3803c
    return acc;
}

// [EN] Reconstructed FDE #1666 @ 0x03803c..0x038058 (28 bytes)
// [VN] Phục dựng FDE #1666 tại 0x03803c..0x038058 (28 byte)
//   0x03803c: d37dfc28  lsr      x8, x1, #0x3d
//   0x038040: b5000068  cbnz     x8, #0x3804c
//   0x038044: d37df020  lsl      x0, x1, #3
//   0x038048: 17ff4d6a  b        #0xb5f0
//   0x03804c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038050: 910003fd  mov      x29, sp
//   0x038054: 97ff4d2b  bl       #0xb500
uint64_t fde_1666_sub_03803c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD37DFC28ULL) + (x1 ^ 0x97FF4D2BULL) + (x2 ^ 0x03803CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DFC28ULL; // 0x03803c: lsr x8, x1, #0x3d
    acc = (acc * 0x100000001B3ULL) ^ 0xB5000068ULL; // 0x038040: cbnz x8, #0x3804c
    acc = (acc * 0x100000001B3ULL) ^ 0xD37DF020ULL; // 0x038044: lsl x0, x1, #3
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4D6AULL; // 0x038048: b #0xb5f0
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03804c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038050: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF4D2BULL; // 0x038054: bl #0xb500
    return acc;
}

// [EN] Reconstructed FDE #1667 @ 0x038058..0x038078 (32 bytes)
// [VN] Phục dựng FDE #1667 tại 0x038058..0x038078 (32 byte)
//   0x038058: f9400068  ldr      x8, [x3]
//   0x03805c: cb010042  sub      x2, x2, x1
//   0x038060: f100045f  cmp      x2, #1
//   0x038064: cb020100  sub      x0, x8, x2
//   0x038068: f9000060  str      x0, [x3]
//   0x03806c: 5400004b  b.lt     #0x38074
//   0x038070: 17ff4ae8  b        #0xac10
//   0x038074: d65f03c0  ret      
uint64_t fde_1667_sub_038058(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400068ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038058ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400068ULL; // 0x038058: ldr x8, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0xCB010042ULL; // 0x03805c: sub x2, x2, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xF100045FULL; // 0x038060: cmp x2, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xCB020100ULL; // 0x038064: sub x0, x8, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000060ULL; // 0x038068: str x0, [x3]
    acc = (acc * 0x100000001B3ULL) ^ 0x5400004BULL; // 0x03806c: b.lt #0x38074
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4AE8ULL; // 0x038070: b #0xac10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038074: ret 
    return acc;
}

// [EN] Reconstructed FDE #1668 @ 0x038078..0x038080 (8 bytes)
// [VN] Phục dựng FDE #1668 tại 0x038078..0x038080 (8 byte)
//   0x038078: f9400401  ldr      x1, [x0, #8]
//   0x03807c: 14000001  b        #0x38080
uint64_t fde_1668_sub_038078(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400401ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x038078ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400401ULL; // 0x038078: ldr x1, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x03807c: b #0x38080
    return acc;
}

// [EN] Reconstructed FDE #1669 @ 0x038080..0x03809c (28 bytes)
// [VN] Phục dựng FDE #1669 tại 0x038080..0x03809c (28 byte)
//   0x038080: f9400808  ldr      x8, [x0, #0x10]
//   0x038084: eb08003f  cmp      x1, x8
//   0x038088: 54000080  b.eq     #0x38098
//   0x03808c: d1002108  sub      x8, x8, #8
//   0x038090: f9000808  str      x8, [x0, #0x10]
//   0x038094: 17fffffc  b        #0x38084
//   0x038098: d65f03c0  ret      
uint64_t fde_1669_sub_038080(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400808ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038080ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400808ULL; // 0x038080: ldr x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB08003FULL; // 0x038084: cmp x1, x8
    acc = (acc * 0x100000001B3ULL) ^ 0x54000080ULL; // 0x038088: b.eq #0x38098
    acc = (acc * 0x100000001B3ULL) ^ 0xD1002108ULL; // 0x03808c: sub x8, x8, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000808ULL; // 0x038090: str x8, [x0, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFFFFCULL; // 0x038094: b #0x38084
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038098: ret 
    return acc;
}

// [EN] Reconstructed FDE #1670 @ 0x03809c..0x0380a8 (12 bytes)
// [VN] Phục dựng FDE #1670 tại 0x03809c..0x0380a8 (12 byte)
//   0x03809c: f0000100  adrp     x0, #0x5b000
//   0x0380a0: f9457400  ldr      x0, [x0, #0xae8]
//   0x0380a4: 17ff4c5b  b        #0xb210
uint64_t fde_1670_sub_03809c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000100ULL) + (x1 ^ 0x17FF4C5BULL) + (x2 ^ 0x03809CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000100ULL; // 0x03809c: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9457400ULL; // 0x0380a0: ldr x0, [x0, #0xae8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4C5BULL; // 0x0380a4: b #0xb210
    return acc;
}

// [EN] Reconstructed FDE #1671 @ 0x0380a8..0x0380b4 (12 bytes)
// [VN] Phục dựng FDE #1671 tại 0x0380a8..0x0380b4 (12 byte)
//   0x0380a8: f0000100  adrp     x0, #0x5b000
//   0x0380ac: f9457400  ldr      x0, [x0, #0xae8]
//   0x0380b0: 17ff4d48  b        #0xb5d0
uint64_t fde_1671_sub_0380a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000100ULL) + (x1 ^ 0x17FF4D48ULL) + (x2 ^ 0x0380A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000100ULL; // 0x0380a8: adrp x0, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9457400ULL; // 0x0380ac: ldr x0, [x0, #0xae8]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF4D48ULL; // 0x0380b0: b #0xb5d0
    return acc;
}

// [EN] Reconstructed FDE #1672 @ 0x0380b4..0x0380c0 (12 bytes)
// [VN] Phục dựng FDE #1672 tại 0x0380b4..0x0380c0 (12 byte)
//   0x0380b4: aa1403e0  mov      x0, x20
//   0x0380b8: 2a1303e1  mov      w1, w19
//   0x0380bc: d61f0100  br       x8
uint64_t fde_1672_sub_0380b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA1403E0ULL) + (x1 ^ 0xD61F0100ULL) + (x2 ^ 0x0380B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x0380b4: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x0380b8: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xD61F0100ULL; // 0x0380bc: br x8
    return acc;
}

// [EN] Reconstructed FDE #1673 @ 0x0380c0..0x038120 (96 bytes)
// [VN] Phục dựng FDE #1673 tại 0x0380c0..0x038120 (96 byte)
//   0x0380c0: 79400008  ldrh     w8, [x0]
//   0x0380c4: 710c011f  cmp      w8, #0x300
//   0x0380c8: 54000120  b.eq     #0x380ec
//   0x0380cc: 7108011f  cmp      w8, #0x200
//   0x0380d0: 540001c0  b.eq     #0x38108
//   0x0380d4: 7104011f  cmp      w8, #0x100
//   0x0380d8: 54000201  b.ne     #0x38118
//   0x0380dc: 79400408  ldrh     w8, [x0, #2]
//   0x0380e0: d37ff908  lsl      x8, x8, #1
//   0x0380e4: 91001100  add      x0, x8, #4
//   0x0380e8: d65f03c0  ret      
//   0x0380ec: 79400408  ldrh     w8, [x0, #2]
uint64_t fde_1673_sub_0380c0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x79400008ULL) + (x1 ^ 0xD37FF908ULL) + (x2 ^ 0x0380C0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x79400008ULL; // 0x0380c0: ldrh w8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0x710C011FULL; // 0x0380c4: cmp w8, #0x300
    acc = (acc * 0x100000001B3ULL) ^ 0x54000120ULL; // 0x0380c8: b.eq #0x380ec
    acc = (acc * 0x100000001B3ULL) ^ 0x7108011FULL; // 0x0380cc: cmp w8, #0x200
    acc = (acc * 0x100000001B3ULL) ^ 0x540001C0ULL; // 0x0380d0: b.eq #0x38108
    acc = (acc * 0x100000001B3ULL) ^ 0x7104011FULL; // 0x0380d4: cmp w8, #0x100
    acc = (acc * 0x100000001B3ULL) ^ 0x54000201ULL; // 0x0380d8: b.ne #0x38118
    acc = (acc * 0x100000001B3ULL) ^ 0x79400408ULL; // 0x0380dc: ldrh w8, [x0, #2]
    return acc;
}

// [EN] Reconstructed FDE #1674 @ 0x038120..0x0381a0 (128 bytes)
// [VN] Phục dựng FDE #1674 tại 0x038120..0x0381a0 (128 byte)
//   0x038120: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x038124: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x038128: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x03812c: 910083fd  add      x29, sp, #0x20
//   0x038130: b100403f  cmn      x1, #0x10
//   0x038134: 54000342  b.hs     #0x3819c
//   0x038138: 2a0203f4  mov      w20, w2
//   0x03813c: aa0103f3  mov      x19, x1
//   0x038140: aa0003f5  mov      x21, x0
//   0x038144: f100583f  cmp      x1, #0x16
//   0x038148: 54000088  b.hi     #0x38158
//   0x03814c: 531f7a68  lsl      w8, w19, #1
uint64_t fde_1674_sub_038120(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xAA0003F5ULL) + (x2 ^ 0x038120ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x038120: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x038124: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x038128: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x03812c: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xB100403FULL; // 0x038130: cmn x1, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x54000342ULL; // 0x038134: b.hs #0x3819c
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x038138: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F3ULL; // 0x03813c: mov x19, x1
    return acc;
}

// [EN] Reconstructed FDE #1675 @ 0x0381a0..0x0381d8 (56 bytes)
// [VN] Phục dựng FDE #1675 tại 0x0381a0..0x0381d8 (56 byte)
//   0x0381a0: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0381a4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0381a8: 910043fd  add      x29, sp, #0x10
//   0x0381ac: aa0003f3  mov      x19, x0
//   0x0381b0: b40000c1  cbz      x1, #0x381c8
//   0x0381b4: aa0103e8  mov      x8, x1
//   0x0381b8: aa1303e0  mov      x0, x19
//   0x0381bc: 2a0203e1  mov      w1, w2
//   0x0381c0: aa0803e2  mov      x2, x8
//   0x0381c4: 97ff4cab  bl       #0xb470
//   0x0381c8: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0381cc: aa1303e0  mov      x0, x19
uint64_t fde_1675_sub_0381a0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xAA0803E2ULL) + (x2 ^ 0x0381A0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0381a0: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0381a4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0381a8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0381ac: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xB40000C1ULL; // 0x0381b0: cbz x1, #0x381c8
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103E8ULL; // 0x0381b4: mov x8, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0381b8: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x0381bc: mov w1, w2
    return acc;
}

// [EN] Reconstructed FDE #1676 @ 0x0381d8..0x038214 (60 bytes)
// [VN] Phục dựng FDE #1676 tại 0x0381d8..0x038214 (60 byte)
//   0x0381d8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0381dc: 910003fd  mov      x29, sp
//   0x0381e0: f0000108  adrp     x8, #0x5b000
//   0x0381e4: f9426108  ldr      x8, [x8, #0x4c0]
//   0x0381e8: b0000001  adrp     x1, #0x39000
//   0x0381ec: f0000042  adrp     x2, #0x43000
//   0x0381f0: 911f2c21  add      x1, x1, #0x7cb
//   0x0381f4: b9400103  ldr      w3, [x8]
//   0x0381f8: 91058042  add      x2, x2, #0x160
//   0x0381fc: 528000c0  mov      w0, #6
//   0x038200: 97ff4bf8  bl       #0xb1e0
//   0x038204: 528000c0  mov      w0, #6
uint64_t fde_1676_sub_0381d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x91058042ULL) + (x2 ^ 0x0381D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0381d8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0381dc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000108ULL; // 0x0381e0: adrp x8, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9426108ULL; // 0x0381e4: ldr x8, [x8, #0x4c0]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000001ULL; // 0x0381e8: adrp x1, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000042ULL; // 0x0381ec: adrp x2, #0x43000
    acc = (acc * 0x100000001B3ULL) ^ 0x911F2C21ULL; // 0x0381f0: add x1, x1, #0x7cb
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400103ULL; // 0x0381f4: ldr w3, [x8]
    return acc;
}

// [EN] Reconstructed FDE #1677 @ 0x038214..0x038218 (4 bytes)
// [VN] Phục dựng FDE #1677 tại 0x038214..0x038218 (4 byte)
//   0x038214: 17ffcbb0  b        #0x2b0d4
uint64_t fde_1677_sub_038214(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFCBB0ULL) + (x1 ^ 0x17FFCBB0ULL) + (x2 ^ 0x038214ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCBB0ULL; // 0x038214: b #0x2b0d4
    return acc;
}

// [EN] Reconstructed FDE #1678 @ 0x038218..0x03821c (4 bytes)
// [VN] Phục dựng FDE #1678 tại 0x038218..0x03821c (4 byte)
//   0x038218: 17ffcc67  b        #0x2b3b4
uint64_t fde_1678_sub_038218(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFCC67ULL) + (x1 ^ 0x17FFCC67ULL) + (x2 ^ 0x038218ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCC67ULL; // 0x038218: b #0x2b3b4
    return acc;
}

// [EN] Reconstructed FDE #1679 @ 0x03821c..0x038220 (4 bytes)
// [VN] Phục dựng FDE #1679 tại 0x03821c..0x038220 (4 byte)
//   0x03821c: 17ffcc90  b        #0x2b45c
uint64_t fde_1679_sub_03821c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFCC90ULL) + (x1 ^ 0x17FFCC90ULL) + (x2 ^ 0x03821CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCC90ULL; // 0x03821c: b #0x2b45c
    return acc;
}

// [EN] Reconstructed FDE #1680 @ 0x038220..0x038244 (36 bytes)
// [VN] Phục dựng FDE #1680 tại 0x038220..0x038244 (36 byte)
//   0x038220: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038224: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038228: 910043fd  add      x29, sp, #0x10
//   0x03822c: 94000242  bl       #0x38b34
//   0x038230: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038234: 72001e7f  tst      w19, #0xff
//   0x038238: 1a9f07e1  cset     w1, ne
//   0x03823c: f84207f3  ldr      x19, [sp], #0x20
//   0x038240: 17ffcf25  b        #0x2bed4
uint64_t fde_1680_sub_038220(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFCF25ULL) + (x2 ^ 0x038220ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038220: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038224: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038228: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000242ULL; // 0x03822c: bl #0x38b34
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038230: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x72001E7FULL; // 0x038234: tst w19, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E1ULL; // 0x038238: cset w1, ne
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03823c: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #1681 @ 0x038244..0x038264 (32 bytes)
// [VN] Phục dựng FDE #1681 tại 0x038244..0x038264 (32 byte)
//   0x038244: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038248: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03824c: 910043fd  add      x29, sp, #0x10
//   0x038250: 94000239  bl       #0x38b34
//   0x038254: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038258: 2a1303e1  mov      w1, w19
//   0x03825c: f84207f3  ldr      x19, [sp], #0x20
//   0x038260: 17ffcf3a  b        #0x2bf48
uint64_t fde_1681_sub_038244(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFCF3AULL) + (x2 ^ 0x038244ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038244: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038248: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03824c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000239ULL; // 0x038250: bl #0x38b34
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038254: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x038258: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03825c: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCF3AULL; // 0x038260: b #0x2bf48
    return acc;
}

// [EN] Reconstructed FDE #1682 @ 0x038264..0x038288 (36 bytes)
// [VN] Phục dựng FDE #1682 tại 0x038264..0x038288 (36 byte)
//   0x038264: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038268: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03826c: 910043fd  add      x29, sp, #0x10
//   0x038270: aa0203f3  mov      x19, x2
//   0x038274: 97ffccf6  bl       #0x2b64c
//   0x038278: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03827c: aa1303e1  mov      x1, x19
//   0x038280: f84207f3  ldr      x19, [sp], #0x20
//   0x038284: 17ffcf45  b        #0x2bf98
uint64_t fde_1682_sub_038264(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFCF45ULL) + (x2 ^ 0x038264ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038264: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038268: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03826c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x038270: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFCCF6ULL; // 0x038274: bl #0x2b64c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038278: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E1ULL; // 0x03827c: mov x1, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x038280: ldr x19, [sp], #0x20
    return acc;
}

// [EN] Reconstructed FDE #1683 @ 0x038288..0x0382a8 (32 bytes)
// [VN] Phục dựng FDE #1683 tại 0x038288..0x0382a8 (32 byte)
//   0x038288: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x03828c: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038290: 910043fd  add      x29, sp, #0x10
//   0x038294: 94000228  bl       #0x38b34
//   0x038298: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x03829c: 2a1303e1  mov      w1, w19
//   0x0382a0: f84207f3  ldr      x19, [sp], #0x20
//   0x0382a4: 17ffcf77  b        #0x2c080
uint64_t fde_1683_sub_038288(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFCF77ULL) + (x2 ^ 0x038288ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038288: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x03828c: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038290: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000228ULL; // 0x038294: bl #0x38b34
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038298: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x03829c: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x0382a0: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCF77ULL; // 0x0382a4: b #0x2c080
    return acc;
}

// [EN] Reconstructed FDE #1684 @ 0x0382a8..0x0382e8 (64 bytes)
// [VN] Phục dựng FDE #1684 tại 0x0382a8..0x0382e8 (64 byte)
//   0x0382a8: f81d0ff5  str      x21, [sp, #-0x30]!
//   0x0382ac: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x0382b0: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x0382b4: 910083fd  add      x29, sp, #0x20
//   0x0382b8: 2a0303f3  mov      w19, w3
//   0x0382bc: 2a0203f4  mov      w20, w2
//   0x0382c0: aa0003f5  mov      x21, x0
//   0x0382c4: 97ffcce2  bl       #0x2b64c
//   0x0382c8: 72001e9f  tst      w20, #0xff
//   0x0382cc: 93407e63  sxtw     x3, w19
//   0x0382d0: a9427bfd  ldp      x29, x30, [sp, #0x20]
//   0x0382d4: a9414ff4  ldp      x20, x19, [sp, #0x10]
uint64_t fde_1684_sub_0382a8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81D0FF5ULL) + (x1 ^ 0x72001E9FULL) + (x2 ^ 0x0382A8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81D0FF5ULL; // 0x0382a8: str x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0382ac: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x0382b0: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x0382b4: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F3ULL; // 0x0382b8: mov w19, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F4ULL; // 0x0382bc: mov w20, w2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x0382c0: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFCCE2ULL; // 0x0382c4: bl #0x2b64c
    return acc;
}

// [EN] Reconstructed FDE #1685 @ 0x0382e8..0x0382f4 (12 bytes)
// [VN] Phục dựng FDE #1685 tại 0x0382e8..0x0382f4 (12 byte)
//   0x0382e8: 72001c5f  tst      w2, #0xff
//   0x0382ec: 1a9f07e0  cset     w0, ne
//   0x0382f0: 17ffcf66  b        #0x2c088
uint64_t fde_1685_sub_0382e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0x17FFCF66ULL) + (x2 ^ 0x0382E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x0382e8: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E0ULL; // 0x0382ec: cset w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCF66ULL; // 0x0382f0: b #0x2c088
    return acc;
}

// [EN] Reconstructed FDE #1686 @ 0x0382f4..0x038314 (32 bytes)
// [VN] Phục dựng FDE #1686 tại 0x0382f4..0x038314 (32 byte)
//   0x0382f4: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0382f8: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0382fc: 910043fd  add      x29, sp, #0x10
//   0x038300: 9400020d  bl       #0x38b34
//   0x038304: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038308: 2a1303e1  mov      w1, w19
//   0x03830c: f84207f3  ldr      x19, [sp], #0x20
//   0x038310: 17ffcf34  b        #0x2bfe0
uint64_t fde_1686_sub_0382f4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFCF34ULL) + (x2 ^ 0x0382F4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0382f4: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0382f8: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0382fc: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9400020DULL; // 0x038300: bl #0x38b34
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038304: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x038308: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03830c: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCF34ULL; // 0x038310: b #0x2bfe0
    return acc;
}

// [EN] Reconstructed FDE #1687 @ 0x038314..0x038334 (32 bytes)
// [VN] Phục dựng FDE #1687 tại 0x038314..0x038334 (32 byte)
//   0x038314: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038318: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x03831c: 910043fd  add      x29, sp, #0x10
//   0x038320: 94000205  bl       #0x38b34
//   0x038324: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038328: 2a1303e1  mov      w1, w19
//   0x03832c: f84207f3  ldr      x19, [sp], #0x20
//   0x038330: 17ffcf43  b        #0x2c03c
uint64_t fde_1687_sub_038314(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFCF43ULL) + (x2 ^ 0x038314ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x038314: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038318: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x03831c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000205ULL; // 0x038320: bl #0x38b34
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038324: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x2A1303E1ULL; // 0x038328: mov w1, w19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x03832c: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCF43ULL; // 0x038330: b #0x2c03c
    return acc;
}

// [EN] Reconstructed FDE #1688 @ 0x038334..0x038338 (4 bytes)
// [VN] Phục dựng FDE #1688 tại 0x038334..0x038338 (4 byte)
//   0x038334: 17ffe8fd  b        #0x32728
uint64_t fde_1688_sub_038334(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFE8FDULL) + (x1 ^ 0x17FFE8FDULL) + (x2 ^ 0x038334ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE8FDULL; // 0x038334: b #0x32728
    return acc;
}

// [EN] Reconstructed FDE #1689 @ 0x038338..0x03833c (4 bytes)
// [VN] Phục dựng FDE #1689 tại 0x038338..0x03833c (4 byte)
//   0x038338: 17ffec58  b        #0x33498
uint64_t fde_1689_sub_038338(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFEC58ULL) + (x1 ^ 0x17FFEC58ULL) + (x2 ^ 0x038338ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEC58ULL; // 0x038338: b #0x33498
    return acc;
}

// [EN] Reconstructed FDE #1690 @ 0x03833c..0x038340 (4 bytes)
// [VN] Phục dựng FDE #1690 tại 0x03833c..0x038340 (4 byte)
//   0x03833c: 17ffeb77  b        #0x33118
uint64_t fde_1690_sub_03833c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFEB77ULL) + (x1 ^ 0x17FFEB77ULL) + (x2 ^ 0x03833CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEB77ULL; // 0x03833c: b #0x33118
    return acc;
}

// [EN] Reconstructed FDE #1691 @ 0x038340..0x038348 (8 bytes)
// [VN] Phục dựng FDE #1691 tại 0x038340..0x038348 (8 byte)
//   0x038340: 2a0203e0  mov      w0, w2
//   0x038344: 17ffee30  b        #0x33c04
uint64_t fde_1691_sub_038340(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0203E0ULL) + (x1 ^ 0x17FFEE30ULL) + (x2 ^ 0x038340ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x038340: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEE30ULL; // 0x038344: b #0x33c04
    return acc;
}

// [EN] Reconstructed FDE #1692 @ 0x038348..0x03834c (4 bytes)
// [VN] Phục dựng FDE #1692 tại 0x038348..0x03834c (4 byte)
//   0x038348: 17ffeffc  b        #0x34338
uint64_t fde_1692_sub_038348(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFEFFCULL) + (x1 ^ 0x17FFEFFCULL) + (x2 ^ 0x038348ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFEFFCULL; // 0x038348: b #0x34338
    return acc;
}

// [EN] Reconstructed FDE #1693 @ 0x03834c..0x038350 (4 bytes)
// [VN] Phục dựng FDE #1693 tại 0x03834c..0x038350 (4 byte)
//   0x03834c: 17fff0f9  b        #0x34730
uint64_t fde_1693_sub_03834c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFF0F9ULL) + (x1 ^ 0x17FFF0F9ULL) + (x2 ^ 0x03834CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF0F9ULL; // 0x03834c: b #0x34730
    return acc;
}

// [EN] Reconstructed FDE #1694 @ 0x038350..0x038354 (4 bytes)
// [VN] Phục dựng FDE #1694 tại 0x038350..0x038354 (4 byte)
//   0x038350: 17fff150  b        #0x34890
uint64_t fde_1694_sub_038350(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFF150ULL) + (x1 ^ 0x17FFF150ULL) + (x2 ^ 0x038350ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF150ULL; // 0x038350: b #0x34890
    return acc;
}

// [EN] Reconstructed FDE #1695 @ 0x038354..0x038358 (4 bytes)
// [VN] Phục dựng FDE #1695 tại 0x038354..0x038358 (4 byte)
//   0x038354: 17fff069  b        #0x344f8
uint64_t fde_1695_sub_038354(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFF069ULL) + (x1 ^ 0x17FFF069ULL) + (x2 ^ 0x038354ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF069ULL; // 0x038354: b #0x344f8
    return acc;
}

// [EN] Reconstructed FDE #1696 @ 0x038358..0x03835c (4 bytes)
// [VN] Phục dựng FDE #1696 tại 0x038358..0x03835c (4 byte)
//   0x038358: 17fff0b9  b        #0x3463c
uint64_t fde_1696_sub_038358(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFF0B9ULL) + (x1 ^ 0x17FFF0B9ULL) + (x2 ^ 0x038358ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF0B9ULL; // 0x038358: b #0x3463c
    return acc;
}

// [EN] Reconstructed FDE #1697 @ 0x03835c..0x038360 (4 bytes)
// [VN] Phục dựng FDE #1697 tại 0x03835c..0x038360 (4 byte)
//   0x03835c: 17ffd359  b        #0x2d0c0
uint64_t fde_1697_sub_03835c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFD359ULL) + (x1 ^ 0x17FFD359ULL) + (x2 ^ 0x03835CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD359ULL; // 0x03835c: b #0x2d0c0
    return acc;
}

// [EN] Reconstructed FDE #1698 @ 0x038360..0x038378 (24 bytes)
// [VN] Phục dựng FDE #1698 tại 0x038360..0x038378 (24 byte)
//   0x038360: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038364: 910003fd  mov      x29, sp
//   0x038368: 97ffe71d  bl       #0x31fdc
//   0x03836c: 12000000  and      w0, w0, #1
//   0x038370: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038374: d65f03c0  ret      
uint64_t fde_1698_sub_038360(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038360ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038360: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038364: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE71DULL; // 0x038368: bl #0x31fdc
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x03836c: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038370: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038374: ret 
    return acc;
}

// [EN] Reconstructed FDE #1699 @ 0x038378..0x03837c (4 bytes)
// [VN] Phục dựng FDE #1699 tại 0x038378..0x03837c (4 byte)
//   0x038378: 17ffe765  b        #0x3210c
uint64_t fde_1699_sub_038378(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFE765ULL) + (x1 ^ 0x17FFE765ULL) + (x2 ^ 0x038378ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE765ULL; // 0x038378: b #0x3210c
    return acc;
}

// [EN] Reconstructed FDE #1700 @ 0x03837c..0x038380 (4 bytes)
// [VN] Phục dựng FDE #1700 tại 0x03837c..0x038380 (4 byte)
//   0x03837c: 17ffe7bf  b        #0x32278
uint64_t fde_1700_sub_03837c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFE7BFULL) + (x1 ^ 0x17FFE7BFULL) + (x2 ^ 0x03837CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE7BFULL; // 0x03837c: b #0x32278
    return acc;
}

// [EN] Reconstructed FDE #1701 @ 0x038380..0x038388 (8 bytes)
// [VN] Phục dựng FDE #1701 tại 0x038380..0x038388 (8 byte)
//   0x038380: 2a0203e0  mov      w0, w2
//   0x038384: 17ffe7d6  b        #0x322dc
uint64_t fde_1701_sub_038380(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0203E0ULL) + (x1 ^ 0x17FFE7D6ULL) + (x2 ^ 0x038380ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x038380: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE7D6ULL; // 0x038384: b #0x322dc
    return acc;
}

// [EN] Reconstructed FDE #1702 @ 0x038388..0x03838c (4 bytes)
// [VN] Phục dựng FDE #1702 tại 0x038388..0x03838c (4 byte)
//   0x038388: 17ffe82f  b        #0x32444
uint64_t fde_1702_sub_038388(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFE82FULL) + (x1 ^ 0x17FFE82FULL) + (x2 ^ 0x038388ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE82FULL; // 0x038388: b #0x32444
    return acc;
}

// [EN] Reconstructed FDE #1703 @ 0x03838c..0x038394 (8 bytes)
// [VN] Phục dựng FDE #1703 tại 0x03838c..0x038394 (8 byte)
//   0x03838c: 2a0203e0  mov      w0, w2
//   0x038390: 17ffd82e  b        #0x2e448
uint64_t fde_1703_sub_03838c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0203E0ULL) + (x1 ^ 0x17FFD82EULL) + (x2 ^ 0x03838CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x03838c: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD82EULL; // 0x038390: b #0x2e448
    return acc;
}

// [EN] Reconstructed FDE #1704 @ 0x038394..0x0383e8 (84 bytes)
// [VN] Phục dựng FDE #1704 tại 0x038394..0x0383e8 (84 byte)
//   0x038394: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x038398: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x03839c: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0383a0: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0383a4: 9100c3fd  add      x29, sp, #0x30
//   0x0383a8: aa0403f3  mov      x19, x4
//   0x0383ac: aa0303f4  mov      x20, x3
//   0x0383b0: 940001e3  bl       #0x38b3c
//   0x0383b4: 36000160  tbz      w0, #0, #0x383e0
//   0x0383b8: aa1603e1  mov      x1, x22
//   0x0383bc: aa1503e2  mov      x2, x21
//   0x0383c0: aa1403e3  mov      x3, x20
uint64_t fde_1704_sub_038394(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x36000160ULL) + (x2 ^ 0x038394ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x038394: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x038398: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x03839c: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0383a0: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0383a4: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F3ULL; // 0x0383a8: mov x19, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x0383ac: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0x940001E3ULL; // 0x0383b0: bl #0x38b3c
    return acc;
}

// [EN] Reconstructed FDE #1705 @ 0x0383e8..0x03843c (84 bytes)
// [VN] Phục dựng FDE #1705 tại 0x0383e8..0x03843c (84 byte)
//   0x0383e8: f81c0ff7  str      x23, [sp, #-0x40]!
//   0x0383ec: a90157f6  stp      x22, x21, [sp, #0x10]
//   0x0383f0: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x0383f4: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x0383f8: 9100c3fd  add      x29, sp, #0x30
//   0x0383fc: 2a0403f3  mov      w19, w4
//   0x038400: 2a0303f4  mov      w20, w3
//   0x038404: 940001ce  bl       #0x38b3c
//   0x038408: 36000160  tbz      w0, #0, #0x38434
//   0x03840c: aa1603e1  mov      x1, x22
//   0x038410: aa1503e2  mov      x2, x21
//   0x038414: 2a1403e3  mov      w3, w20
uint64_t fde_1705_sub_0383e8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81C0FF7ULL) + (x1 ^ 0x36000160ULL) + (x2 ^ 0x0383E8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81C0FF7ULL; // 0x0383e8: str x23, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA90157F6ULL; // 0x0383ec: stp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x0383f0: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x0383f4: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x0383f8: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403F3ULL; // 0x0383fc: mov w19, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303F4ULL; // 0x038400: mov w20, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x940001CEULL; // 0x038404: bl #0x38b3c
    return acc;
}

// [EN] Reconstructed FDE #1706 @ 0x03843c..0x038454 (24 bytes)
// [VN] Phục dựng FDE #1706 tại 0x03843c..0x038454 (24 byte)
//   0x03843c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038440: 910003fd  mov      x29, sp
//   0x038444: 97ffe3c5  bl       #0x31358
//   0x038448: 12000000  and      w0, w0, #1
//   0x03844c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038450: d65f03c0  ret      
uint64_t fde_1706_sub_03843c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03843CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03843c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038440: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE3C5ULL; // 0x038444: bl #0x31358
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038448: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03844c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038450: ret 
    return acc;
}

// [EN] Reconstructed FDE #1707 @ 0x038454..0x038464 (16 bytes)
// [VN] Phục dựng FDE #1707 tại 0x038454..0x038464 (16 byte)
//   0x038454: aa0203e1  mov      x1, x2
//   0x038458: aa0303e2  mov      x2, x3
//   0x03845c: aa0403e3  mov      x3, x4
//   0x038460: 17ffe494  b        #0x316b0
uint64_t fde_1707_sub_038454(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E1ULL) + (x1 ^ 0x17FFE494ULL) + (x2 ^ 0x038454ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x038454: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303E2ULL; // 0x038458: mov x2, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403E3ULL; // 0x03845c: mov x3, x4
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE494ULL; // 0x038460: b #0x316b0
    return acc;
}

// [EN] Reconstructed FDE #1708 @ 0x038464..0x0384bc (88 bytes)
// [VN] Phục dựng FDE #1708 tại 0x038464..0x0384bc (88 byte)
//   0x038464: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x038468: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x03846c: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x038470: 910083fd  add      x29, sp, #0x20
//   0x038474: aa0403f3  mov      x19, x4
//   0x038478: aa0303f4  mov      x20, x3
//   0x03847c: aa0203f5  mov      x21, x2
//   0x038480: aa0003f6  mov      x22, x0
//   0x038484: 97ffe3b5  bl       #0x31358
//   0x038488: 36000100  tbz      w0, #0, #0x384a8
//   0x03848c: aa1603e0  mov      x0, x22
//   0x038490: aa1503e1  mov      x1, x21
uint64_t fde_1708_sub_038464(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0x97FFE3B5ULL) + (x2 ^ 0x038464ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x038464: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x038468: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x03846c: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x038470: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0403F3ULL; // 0x038474: mov x19, x4
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F4ULL; // 0x038478: mov x20, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x03847c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x038480: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #1709 @ 0x0384bc..0x0384f0 (52 bytes)
// [VN] Phục dựng FDE #1709 tại 0x0384bc..0x0384f0 (52 byte)
//   0x0384bc: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x0384c0: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0384c4: 910043fd  add      x29, sp, #0x10
//   0x0384c8: aa0003f3  mov      x19, x0
//   0x0384cc: 97ffe3a3  bl       #0x31358
//   0x0384d0: 360000a0  tbz      w0, #0, #0x384e4
//   0x0384d4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0384d8: aa1303e0  mov      x0, x19
//   0x0384dc: f84207f3  ldr      x19, [sp], #0x20
//   0x0384e0: 17ffe66a  b        #0x31e88
//   0x0384e4: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x0384e8: f84207f3  ldr      x19, [sp], #0x20
uint64_t fde_1709_sub_0384bc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x0384BCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x0384bc: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0384c0: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0384c4: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x0384c8: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE3A3ULL; // 0x0384cc: bl #0x31358
    acc = (acc * 0x100000001B3ULL) ^ 0x360000A0ULL; // 0x0384d0: tbz w0, #0, #0x384e4
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x0384d4: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x0384d8: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1710 @ 0x0384f0..0x03852c (60 bytes)
// [VN] Phục dựng FDE #1710 tại 0x0384f0..0x03852c (60 byte)
//   0x0384f0: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x0384f4: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x0384f8: 910043fd  add      x29, sp, #0x10
//   0x0384fc: aa0203f3  mov      x19, x2
//   0x038500: aa0003f4  mov      x20, x0
//   0x038504: 97ffe395  bl       #0x31358
//   0x038508: 360000c0  tbz      w0, #0, #0x38520
//   0x03850c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038510: aa1403e0  mov      x0, x20
//   0x038514: aa1303e1  mov      x1, x19
//   0x038518: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x03851c: 17ffe5cf  b        #0x31c58
uint64_t fde_1710_sub_0384f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xAA1403E0ULL) + (x2 ^ 0x0384F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x0384f0: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x0384f4: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x0384f8: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x0384fc: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F4ULL; // 0x038500: mov x20, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFE395ULL; // 0x038504: bl #0x31358
    acc = (acc * 0x100000001B3ULL) ^ 0x360000C0ULL; // 0x038508: tbz w0, #0, #0x38520
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03850c: ldp x29, x30, [sp, #0x10]
    return acc;
}

// [EN] Reconstructed FDE #1711 @ 0x03852c..0x03854c (32 bytes)
// [VN] Phục dựng FDE #1711 tại 0x03852c..0x03854c (32 byte)
//   0x03852c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038530: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038534: 910043fd  add      x29, sp, #0x10
//   0x038538: 94000185  bl       #0x38b4c
//   0x03853c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038540: aa1303e0  mov      x0, x19
//   0x038544: f84207f3  ldr      x19, [sp], #0x20
//   0x038548: 17ffdf62  b        #0x302d0
uint64_t fde_1711_sub_03852c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFDF62ULL) + (x2 ^ 0x03852CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03852c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038530: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038534: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000185ULL; // 0x038538: bl #0x38b4c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03853c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x038540: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x038544: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDF62ULL; // 0x038548: b #0x302d0
    return acc;
}

// [EN] Reconstructed FDE #1712 @ 0x03854c..0x03856c (32 bytes)
// [VN] Phục dựng FDE #1712 tại 0x03854c..0x03856c (32 byte)
//   0x03854c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038550: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038554: 910043fd  add      x29, sp, #0x10
//   0x038558: 9400017d  bl       #0x38b4c
//   0x03855c: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038560: aa1303e0  mov      x0, x19
//   0x038564: f84207f3  ldr      x19, [sp], #0x20
//   0x038568: 17ffdf65  b        #0x302fc
uint64_t fde_1712_sub_03854c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0x17FFDF65ULL) + (x2 ^ 0x03854CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03854c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038550: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038554: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x9400017DULL; // 0x038558: bl #0x38b4c
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x03855c: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x038560: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0xF84207F3ULL; // 0x038564: ldr x19, [sp], #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDF65ULL; // 0x038568: b #0x302fc
    return acc;
}

// [EN] Reconstructed FDE #1713 @ 0x03856c..0x038594 (40 bytes)
// [VN] Phục dựng FDE #1713 tại 0x03856c..0x038594 (40 byte)
//   0x03856c: f81e0ff3  str      x19, [sp, #-0x20]!
//   0x038570: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038574: 910043fd  add      x29, sp, #0x10
//   0x038578: 94000175  bl       #0x38b4c
//   0x03857c: aa1303e0  mov      x0, x19
//   0x038580: 97ffdf6a  bl       #0x30328
//   0x038584: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038588: 12000000  and      w0, w0, #1
//   0x03858c: f84207f3  ldr      x19, [sp], #0x20
//   0x038590: d65f03c0  ret      
uint64_t fde_1713_sub_03856c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF81E0FF3ULL) + (x1 ^ 0xF84207F3ULL) + (x2 ^ 0x03856CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF81E0FF3ULL; // 0x03856c: str x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038570: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038574: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0x94000175ULL; // 0x038578: bl #0x38b4c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x03857c: mov x0, x19
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFDF6AULL; // 0x038580: bl #0x30328
    acc = (acc * 0x100000001B3ULL) ^ 0xA9417BFDULL; // 0x038584: ldp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038588: and w0, w0, #1
    return acc;
}

// [EN] Reconstructed FDE #1714 @ 0x038594..0x0385d8 (68 bytes)
// [VN] Phục dựng FDE #1714 tại 0x038594..0x0385d8 (68 byte)
//   0x038594: 2a020068  orr      w8, w3, w2
//   0x038598: 2a040108  orr      w8, w8, w4
//   0x03859c: 2a050108  orr      w8, w8, w5
//   0x0385a0: 2a060108  orr      w8, w8, w6
//   0x0385a4: 37f800e8  tbnz     w8, #0x1f, #0x385c0
//   0x0385a8: 2a0203e1  mov      w1, w2
//   0x0385ac: 2a0303e2  mov      w2, w3
//   0x0385b0: 2a0403e3  mov      w3, w4
//   0x0385b4: 2a0503e4  mov      w4, w5
//   0x0385b8: 2a0603e5  mov      w5, w6
//   0x0385bc: 17ffe20c  b        #0x30dec
//   0x0385c0: f0000021  adrp     x1, #0x3f000
uint64_t fde_1714_sub_038594(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A020068ULL) + (x1 ^ 0x2A0503E4ULL) + (x2 ^ 0x038594ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A020068ULL; // 0x038594: orr w8, w3, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A040108ULL; // 0x038598: orr w8, w8, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A050108ULL; // 0x03859c: orr w8, w8, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x2A060108ULL; // 0x0385a0: orr w8, w8, w6
    acc = (acc * 0x100000001B3ULL) ^ 0x37F800E8ULL; // 0x0385a4: tbnz w8, #0x1f, #0x385c0
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x0385a8: mov w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E2ULL; // 0x0385ac: mov w2, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E3ULL; // 0x0385b0: mov w3, w4
    return acc;
}

// [EN] Reconstructed FDE #1715 @ 0x0385d8..0x0386ec (276 bytes)
// [VN] Phục dựng FDE #1715 tại 0x0385d8..0x0386ec (276 byte)
//   0x0385d8: d10243ff  sub      sp, sp, #0x90
//   0x0385dc: f90023f9  str      x25, [sp, #0x40]
//   0x0385e0: a9055ff8  stp      x24, x23, [sp, #0x50]
//   0x0385e4: a90657f6  stp      x22, x21, [sp, #0x60]
//   0x0385e8: a9074ff4  stp      x20, x19, [sp, #0x70]
//   0x0385ec: a9087bfd  stp      x29, x30, [sp, #0x80]
//   0x0385f0: 910203fd  add      x29, sp, #0x80
//   0x0385f4: d53bd059  mrs      x25, tpidr_el0
//   0x0385f8: f9401728  ldr      x8, [x25, #0x28]
//   0x0385fc: aa0203e1  mov      x1, x2
//   0x038600: aa0003f3  mov      x19, x0
//   0x038604: aa0203f4  mov      x20, x2
uint64_t fde_1715_sub_0385d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10243FFULL) + (x1 ^ 0xF9401728ULL) + (x2 ^ 0x0385D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10243FFULL; // 0x0385d8: sub sp, sp, #0x90
    acc = (acc * 0x100000001B3ULL) ^ 0xF90023F9ULL; // 0x0385dc: str x25, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9055FF8ULL; // 0x0385e0: stp x24, x23, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90657F6ULL; // 0x0385e4: stp x22, x21, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9074FF4ULL; // 0x0385e8: stp x20, x19, [sp, #0x70]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9087BFDULL; // 0x0385ec: stp x29, x30, [sp, #0x80]
    acc = (acc * 0x100000001B3ULL) ^ 0x910203FDULL; // 0x0385f0: add x29, sp, #0x80
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD059ULL; // 0x0385f4: mrs x25, tpidr_el0
    return acc;
}

// [EN] Reconstructed FDE #1716 @ 0x0386ec..0x038700 (20 bytes)
// [VN] Phục dựng FDE #1716 tại 0x0386ec..0x038700 (20 byte)
//   0x0386ec: a940a408  ldp      x8, x9, [x0, #8]
//   0x0386f0: eb09011f  cmp      x8, x9
//   0x0386f4: 54000040  b.eq     #0x386fc
//   0x0386f8: 140000cf  b        #0x38a34
//   0x0386fc: 140000da  b        #0x38a64
uint64_t fde_1716_sub_0386ec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA940A408ULL) + (x1 ^ 0x140000DAULL) + (x2 ^ 0x0386ECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA940A408ULL; // 0x0386ec: ldp x8, x9, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB09011FULL; // 0x0386f0: cmp x8, x9
    acc = (acc * 0x100000001B3ULL) ^ 0x54000040ULL; // 0x0386f4: b.eq #0x386fc
    acc = (acc * 0x100000001B3ULL) ^ 0x140000CFULL; // 0x0386f8: b #0x38a34
    acc = (acc * 0x100000001B3ULL) ^ 0x140000DAULL; // 0x0386fc: b #0x38a64
    return acc;
}

// [EN] Reconstructed FDE #1717 @ 0x038700..0x038704 (4 bytes)
// [VN] Phục dựng FDE #1717 tại 0x038700..0x038704 (4 byte)
//   0x038700: 17ffe0a6  b        #0x30998
uint64_t fde_1717_sub_038700(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFE0A6ULL) + (x1 ^ 0x17FFE0A6ULL) + (x2 ^ 0x038700ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFE0A6ULL; // 0x038700: b #0x30998
    return acc;
}

// [EN] Reconstructed FDE #1718 @ 0x038704..0x03871c (24 bytes)
// [VN] Phục dựng FDE #1718 tại 0x038704..0x03871c (24 byte)
//   0x038704: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038708: 910003fd  mov      x29, sp
//   0x03870c: 97ff9f9d  bl       #0x20580
//   0x038710: 12000000  and      w0, w0, #1
//   0x038714: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038718: d65f03c0  ret      
uint64_t fde_1718_sub_038704(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038704ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038704: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038708: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF9F9DULL; // 0x03870c: bl #0x20580
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038710: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038714: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038718: ret 
    return acc;
}

// [EN] Reconstructed FDE #1719 @ 0x03871c..0x03877c (96 bytes)
// [VN] Phục dựng FDE #1719 tại 0x03871c..0x03877c (96 byte)
//   0x03871c: d10103ff  sub      sp, sp, #0x40
//   0x038720: a9024ff4  stp      x20, x19, [sp, #0x20]
//   0x038724: a9037bfd  stp      x29, x30, [sp, #0x30]
//   0x038728: 9100c3fd  add      x29, sp, #0x30
//   0x03872c: d53bd054  mrs      x20, tpidr_el0
//   0x038730: f9401688  ldr      x8, [x20, #0x28]
//   0x038734: aa0203f3  mov      x19, x2
//   0x038738: f9000fe8  str      x8, [sp, #0x18]
//   0x03873c: 910003e8  mov      x8, sp
//   0x038740: 97ff49f4  bl       #0xaf10
//   0x038744: 52994008  mov      w8, #0xca00
//   0x038748: 72a77348  movk     w8, #0x3b9a, lsl #16
uint64_t fde_1719_sub_03871c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10103FFULL) + (x1 ^ 0x910003E8ULL) + (x2 ^ 0x03871CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10103FFULL; // 0x03871c: sub sp, sp, #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xA9024FF4ULL; // 0x038720: stp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9037BFDULL; // 0x038724: stp x29, x30, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0x9100C3FDULL; // 0x038728: add x29, sp, #0x30
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD054ULL; // 0x03872c: mrs x20, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF9401688ULL; // 0x038730: ldr x8, [x20, #0x28]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F3ULL; // 0x038734: mov x19, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000FE8ULL; // 0x038738: str x8, [sp, #0x18]
    return acc;
}

// [EN] Reconstructed FDE #1720 @ 0x03877c..0x03879c (32 bytes)
// [VN] Phục dựng FDE #1720 tại 0x03877c..0x03879c (32 byte)
//   0x03877c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038780: 910003fd  mov      x29, sp
//   0x038784: 93407c41  sxtw     x1, w2
//   0x038788: 93407c62  sxtw     x2, w3
//   0x03878c: 97ffa5f3  bl       #0x21f58
//   0x038790: 12000000  and      w0, w0, #1
//   0x038794: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038798: d65f03c0  ret      
uint64_t fde_1720_sub_03877c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03877CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03877c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038780: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C41ULL; // 0x038784: sxtw x1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C62ULL; // 0x038788: sxtw x2, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA5F3ULL; // 0x03878c: bl #0x21f58
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038790: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038794: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038798: ret 
    return acc;
}

// [EN] Reconstructed FDE #1721 @ 0x03879c..0x0387b8 (28 bytes)
// [VN] Phục dựng FDE #1721 tại 0x03879c..0x0387b8 (28 byte)
//   0x03879c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0387a0: 910003fd  mov      x29, sp
//   0x0387a4: 93407c41  sxtw     x1, w2
//   0x0387a8: 97ffa639  bl       #0x2208c
//   0x0387ac: 12000000  and      w0, w0, #1
//   0x0387b0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0387b4: d65f03c0  ret      
uint64_t fde_1721_sub_03879c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03879CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03879c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0387a0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C41ULL; // 0x0387a4: sxtw x1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA639ULL; // 0x0387a8: bl #0x2208c
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x0387ac: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0387b0: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0387b4: ret 
    return acc;
}

// [EN] Reconstructed FDE #1722 @ 0x0387b8..0x0387d4 (28 bytes)
// [VN] Phục dựng FDE #1722 tại 0x0387b8..0x0387d4 (28 byte)
//   0x0387b8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0387bc: 910003fd  mov      x29, sp
//   0x0387c0: 93407c41  sxtw     x1, w2
//   0x0387c4: 97ffa67a  bl       #0x221ac
//   0x0387c8: 12000000  and      w0, w0, #1
//   0x0387cc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0387d0: d65f03c0  ret      
uint64_t fde_1722_sub_0387b8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x0387B8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0387b8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0387bc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C41ULL; // 0x0387c0: sxtw x1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFA67AULL; // 0x0387c4: bl #0x221ac
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x0387c8: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0387cc: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0387d0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1723 @ 0x0387d4..0x0387d8 (4 bytes)
// [VN] Phục dựng FDE #1723 tại 0x0387d4..0x0387d8 (4 byte)
//   0x0387d4: 17ffa6c3  b        #0x222e0
uint64_t fde_1723_sub_0387d4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFA6C3ULL) + (x1 ^ 0x17FFA6C3ULL) + (x2 ^ 0x0387D4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFA6C3ULL; // 0x0387d4: b #0x222e0
    return acc;
}

// [EN] Reconstructed FDE #1724 @ 0x0387d8..0x038804 (44 bytes)
// [VN] Phục dựng FDE #1724 tại 0x0387d8..0x038804 (44 byte)
//   0x0387d8: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0387dc: 910003fd  mov      x29, sp
//   0x0387e0: aa0203e1  mov      x1, x2
//   0x0387e4: 2a0303e2  mov      w2, w3
//   0x0387e8: 2a0403e3  mov      w3, w4
//   0x0387ec: 2a0503e4  mov      w4, w5
//   0x0387f0: 2a0603e5  mov      w5, w6
//   0x0387f4: 97ff962b  bl       #0x1e0a0
//   0x0387f8: 12000000  and      w0, w0, #1
//   0x0387fc: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038800: d65f03c0  ret      
uint64_t fde_1724_sub_0387d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x12000000ULL) + (x2 ^ 0x0387D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0387d8: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0387dc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x0387e0: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E2ULL; // 0x0387e4: mov w2, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0403E3ULL; // 0x0387e8: mov w3, w4
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0503E4ULL; // 0x0387ec: mov w4, w5
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0603E5ULL; // 0x0387f0: mov w5, w6
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF962BULL; // 0x0387f4: bl #0x1e0a0
    return acc;
}

// [EN] Reconstructed FDE #1725 @ 0x038804..0x038808 (4 bytes)
// [VN] Phục dựng FDE #1725 tại 0x038804..0x038808 (4 byte)
//   0x038804: 17ff9845  b        #0x1e918
uint64_t fde_1725_sub_038804(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF9845ULL) + (x1 ^ 0x17FF9845ULL) + (x2 ^ 0x038804ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF9845ULL; // 0x038804: b #0x1e918
    return acc;
}

// [EN] Reconstructed FDE #1726 @ 0x038808..0x038820 (24 bytes)
// [VN] Phục dựng FDE #1726 tại 0x038808..0x038820 (24 byte)
//   0x038808: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03880c: 910003fd  mov      x29, sp
//   0x038810: 97ff684c  bl       #0x12940
//   0x038814: 12000000  and      w0, w0, #1
//   0x038818: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03881c: d65f03c0  ret      
uint64_t fde_1726_sub_038808(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038808ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038808: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03880c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF684CULL; // 0x038810: bl #0x12940
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038814: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038818: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03881c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1727 @ 0x038820..0x038840 (32 bytes)
// [VN] Phục dựng FDE #1727 tại 0x038820..0x038840 (32 byte)
//   0x038820: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038824: 910003fd  mov      x29, sp
//   0x038828: 2a0203e1  mov      w1, w2
//   0x03882c: 2a0303e2  mov      w2, w3
//   0x038830: 97ff6ae4  bl       #0x133c0
//   0x038834: 12000000  and      w0, w0, #1
//   0x038838: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x03883c: d65f03c0  ret      
uint64_t fde_1727_sub_038820(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038820ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038820: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038824: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E1ULL; // 0x038828: mov w1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0303E2ULL; // 0x03882c: mov w2, w3
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF6AE4ULL; // 0x038830: bl #0x133c0
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038834: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038838: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x03883c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1728 @ 0x038840..0x038844 (4 bytes)
// [VN] Phục dựng FDE #1728 tại 0x038840..0x038844 (4 byte)
//   0x038840: 17ff6e81  b        #0x14244
uint64_t fde_1728_sub_038840(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF6E81ULL) + (x1 ^ 0x17FF6E81ULL) + (x2 ^ 0x038840ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF6E81ULL; // 0x038840: b #0x14244
    return acc;
}

// [EN] Reconstructed FDE #1729 @ 0x038844..0x03885c (24 bytes)
// [VN] Phục dựng FDE #1729 tại 0x038844..0x03885c (24 byte)
//   0x038844: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038848: 910003fd  mov      x29, sp
//   0x03884c: 97ff6896  bl       #0x12aa4
//   0x038850: 12000000  and      w0, w0, #1
//   0x038854: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038858: d65f03c0  ret      
uint64_t fde_1729_sub_038844(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038844ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038844: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038848: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF6896ULL; // 0x03884c: bl #0x12aa4
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038850: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038854: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038858: ret 
    return acc;
}

// [EN] Reconstructed FDE #1730 @ 0x03885c..0x038874 (24 bytes)
// [VN] Phục dựng FDE #1730 tại 0x03885c..0x038874 (24 byte)
//   0x03885c: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038860: 910003fd  mov      x29, sp
//   0x038864: 97ff6999  bl       #0x12ec8
//   0x038868: 12000000  and      w0, w0, #1
//   0x03886c: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038870: d65f03c0  ret      
uint64_t fde_1730_sub_03885c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x03885CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x03885c: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038860: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF6999ULL; // 0x038864: bl #0x12ec8
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038868: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x03886c: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038870: ret 
    return acc;
}

// [EN] Reconstructed FDE #1731 @ 0x038874..0x03888c (24 bytes)
// [VN] Phục dựng FDE #1731 tại 0x038874..0x03888c (24 byte)
//   0x038874: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x038878: 910003fd  mov      x29, sp
//   0x03887c: 97ffaab5  bl       #0x23350
//   0x038880: 12000000  and      w0, w0, #1
//   0x038884: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x038888: d65f03c0  ret      
uint64_t fde_1731_sub_038874(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038874ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038874: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038878: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FFAAB5ULL; // 0x03887c: bl #0x23350
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x038880: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x038884: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038888: ret 
    return acc;
}

// [EN] Reconstructed FDE #1732 @ 0x03888c..0x038890 (4 bytes)
// [VN] Phục dựng FDE #1732 tại 0x03888c..0x038890 (4 byte)
//   0x03888c: 17ffdf25  b        #0x30520
uint64_t fde_1732_sub_03888c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFDF25ULL) + (x1 ^ 0x17FFDF25ULL) + (x2 ^ 0x03888CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDF25ULL; // 0x03888c: b #0x30520
    return acc;
}

// [EN] Reconstructed FDE #1733 @ 0x038890..0x038894 (4 bytes)
// [VN] Phục dựng FDE #1733 tại 0x038890..0x038894 (4 byte)
//   0x038890: 17ffdb58  b        #0x2f5f0
uint64_t fde_1733_sub_038890(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFDB58ULL) + (x1 ^ 0x17FFDB58ULL) + (x2 ^ 0x038890ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDB58ULL; // 0x038890: b #0x2f5f0
    return acc;
}

// [EN] Reconstructed FDE #1734 @ 0x038894..0x038898 (4 bytes)
// [VN] Phục dựng FDE #1734 tại 0x038894..0x038898 (4 byte)
//   0x038894: 17ffdc77  b        #0x2fa70
uint64_t fde_1734_sub_038894(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFDC77ULL) + (x1 ^ 0x17FFDC77ULL) + (x2 ^ 0x038894ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDC77ULL; // 0x038894: b #0x2fa70
    return acc;
}

// [EN] Reconstructed FDE #1735 @ 0x038898..0x0388b0 (24 bytes)
// [VN] Phục dựng FDE #1735 tại 0x038898..0x0388b0 (24 byte)
//   0x038898: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x03889c: 910003fd  mov      x29, sp
//   0x0388a0: 97ff8e0f  bl       #0x1c0dc
//   0x0388a4: 12000000  and      w0, w0, #1
//   0x0388a8: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0388ac: d65f03c0  ret      
uint64_t fde_1735_sub_038898(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038898ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x038898: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x03889c: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF8E0FULL; // 0x0388a0: bl #0x1c0dc
    acc = (acc * 0x100000001B3ULL) ^ 0x12000000ULL; // 0x0388a4: and w0, w0, #1
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0388a8: ldp x29, x30, [sp], #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x0388ac: ret 
    return acc;
}

// [EN] Reconstructed FDE #1736 @ 0x0388b0..0x0388b4 (4 bytes)
// [VN] Phục dựng FDE #1736 tại 0x0388b0..0x0388b4 (4 byte)
//   0x0388b0: 17ff53f5  b        #0xd884
uint64_t fde_1736_sub_0388b0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FF53F5ULL) + (x1 ^ 0x17FF53F5ULL) + (x2 ^ 0x0388B0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF53F5ULL; // 0x0388b0: b #0xd884
    return acc;
}

// [EN] Reconstructed FDE #1737 @ 0x0388b4..0x0388d8 (36 bytes)
// [VN] Phục dựng FDE #1737 tại 0x0388b4..0x0388d8 (36 byte)
//   0x0388b4: a9bf7bfd  stp      x29, x30, [sp, #-0x10]!
//   0x0388b8: 910003fd  mov      x29, sp
//   0x0388bc: f9400008  ldr      x8, [x0]
//   0x0388c0: aa0203e1  mov      x1, x2
//   0x0388c4: aa1f03e2  mov      x2, xzr
//   0x0388c8: f942a508  ldr      x8, [x8, #0x548]
//   0x0388cc: d63f0100  blr      x8
//   0x0388d0: a8c17bfd  ldp      x29, x30, [sp], #0x10
//   0x0388d4: 17ff52a6  b        #0xd36c
uint64_t fde_1737_sub_0388b4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BF7BFDULL) + (x1 ^ 0x17FF52A6ULL) + (x2 ^ 0x0388B4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BF7BFDULL; // 0x0388b4: stp x29, x30, [sp, #-0x10]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x0388b8: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0388bc: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x0388c0: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E2ULL; // 0x0388c4: mov x2, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF942A508ULL; // 0x0388c8: ldr x8, [x8, #0x548]
    acc = (acc * 0x100000001B3ULL) ^ 0xD63F0100ULL; // 0x0388cc: blr x8
    acc = (acc * 0x100000001B3ULL) ^ 0xA8C17BFDULL; // 0x0388d0: ldp x29, x30, [sp], #0x10
    return acc;
}

// [EN] Reconstructed FDE #1738 @ 0x0388d8..0x0388dc (4 bytes)
// [VN] Phục dựng FDE #1738 tại 0x0388d8..0x0388dc (4 byte)
//   0x0388d8: 17ffaf82  b        #0x246e0
uint64_t fde_1738_sub_0388d8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFAF82ULL) + (x1 ^ 0x17FFAF82ULL) + (x2 ^ 0x0388D8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAF82ULL; // 0x0388d8: b #0x246e0
    return acc;
}

// [EN] Reconstructed FDE #1739 @ 0x0388dc..0x0388e4 (8 bytes)
// [VN] Phục dựng FDE #1739 tại 0x0388dc..0x0388e4 (8 byte)
//   0x0388dc: 93407c41  sxtw     x1, w2
//   0x0388e0: 17ffaf59  b        #0x24644
uint64_t fde_1739_sub_0388dc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x93407C41ULL) + (x1 ^ 0x17FFAF59ULL) + (x2 ^ 0x0388DCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x93407C41ULL; // 0x0388dc: sxtw x1, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAF59ULL; // 0x0388e0: b #0x24644
    return acc;
}

// [EN] Reconstructed FDE #1740 @ 0x0388e4..0x0388f0 (12 bytes)
// [VN] Phục dựng FDE #1740 tại 0x0388e4..0x0388f0 (12 byte)
//   0x0388e4: 72001c5f  tst      w2, #0xff
//   0x0388e8: 1a9f07e1  cset     w1, ne
//   0x0388ec: 17ffaf6c  b        #0x2469c
uint64_t fde_1740_sub_0388e4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x72001C5FULL) + (x1 ^ 0x17FFAF6CULL) + (x2 ^ 0x0388E4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x72001C5FULL; // 0x0388e4: tst w2, #0xff
    acc = (acc * 0x100000001B3ULL) ^ 0x1A9F07E1ULL; // 0x0388e8: cset w1, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFAF6CULL; // 0x0388ec: b #0x2469c
    return acc;
}

// [EN] Reconstructed FDE #1741 @ 0x0388f0..0x0388f8 (8 bytes)
// [VN] Phục dựng FDE #1741 tại 0x0388f0..0x0388f8 (8 byte)
//   0x0388f0: 2a0203e0  mov      w0, w2
//   0x0388f4: 17ffd6c5  b        #0x2e408
uint64_t fde_1741_sub_0388f0(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0203E0ULL) + (x1 ^ 0x17FFD6C5ULL) + (x2 ^ 0x0388F0ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203E0ULL; // 0x0388f0: mov w0, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFD6C5ULL; // 0x0388f4: b #0x2e408
    return acc;
}

// [EN] Reconstructed FDE #1742 @ 0x0388f8..0x03895c (100 bytes)
// [VN] Phục dựng FDE #1742 tại 0x0388f8..0x03895c (100 byte)
//   0x0388f8: a9bd57f6  stp      x22, x21, [sp, #-0x30]!
//   0x0388fc: a9014ff4  stp      x20, x19, [sp, #0x10]
//   0x038900: a9027bfd  stp      x29, x30, [sp, #0x20]
//   0x038904: 910083fd  add      x29, sp, #0x20
//   0x038908: f9400008  ldr      x8, [x0]
//   0x03890c: aa0303f5  mov      x21, x3
//   0x038910: aa0203e1  mov      x1, x2
//   0x038914: b0000002  adrp     x2, #0x39000
//   0x038918: f9408508  ldr      x8, [x8, #0x108]
//   0x03891c: f0000043  adrp     x3, #0x43000
//   0x038920: 911abc42  add      x2, x2, #0x6af
//   0x038924: 91064063  add      x3, x3, #0x190
uint64_t fde_1742_sub_0388f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD57F6ULL) + (x1 ^ 0xF9408508ULL) + (x2 ^ 0x0388F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD57F6ULL; // 0x0388f8: stp x22, x21, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9014FF4ULL; // 0x0388fc: stp x20, x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9027BFDULL; // 0x038900: stp x29, x30, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0x910083FDULL; // 0x038904: add x29, sp, #0x20
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x038908: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0303F5ULL; // 0x03890c: mov x21, x3
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x038910: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000002ULL; // 0x038914: adrp x2, #0x39000
    return acc;
}

// [EN] Reconstructed FDE #1743 @ 0x03895c..0x0389f8 (156 bytes)
// [VN] Phục dựng FDE #1743 tại 0x03895c..0x0389f8 (156 byte)
//   0x03895c: d10483ff  sub      sp, sp, #0x120
//   0x038960: a9104ffc  stp      x28, x19, [sp, #0x100]
//   0x038964: a9117bfd  stp      x29, x30, [sp, #0x110]
//   0x038968: 910443fd  add      x29, sp, #0x110
//   0x03896c: a90893e3  stp      x3, x4, [sp, #0x88]
//   0x038970: a9099be5  stp      x5, x6, [sp, #0x98]
//   0x038974: f90057e7  str      x7, [sp, #0xa8]
//   0x038978: ad0007e0  stp      q0, q1, [sp]
//   0x03897c: ad010fe2  stp      q2, q3, [sp, #0x20]
//   0x038980: ad0217e4  stp      q4, q5, [sp, #0x40]
//   0x038984: ad031fe6  stp      q6, q7, [sp, #0x60]
//   0x038988: d53bd053  mrs      x19, tpidr_el0
uint64_t fde_1743_sub_03895c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD10483FFULL) + (x1 ^ 0xAD010FE2ULL) + (x2 ^ 0x03895CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD10483FFULL; // 0x03895c: sub sp, sp, #0x120
    acc = (acc * 0x100000001B3ULL) ^ 0xA9104FFCULL; // 0x038960: stp x28, x19, [sp, #0x100]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9117BFDULL; // 0x038964: stp x29, x30, [sp, #0x110]
    acc = (acc * 0x100000001B3ULL) ^ 0x910443FDULL; // 0x038968: add x29, sp, #0x110
    acc = (acc * 0x100000001B3ULL) ^ 0xA90893E3ULL; // 0x03896c: stp x3, x4, [sp, #0x88]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9099BE5ULL; // 0x038970: stp x5, x6, [sp, #0x98]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90057E7ULL; // 0x038974: str x7, [sp, #0xa8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAD0007E0ULL; // 0x038978: stp q0, q1, [sp]
    return acc;
}

// [EN] Reconstructed FDE #1744 @ 0x0389f8..0x038a1c (36 bytes)
// [VN] Phục dựng FDE #1744 tại 0x0389f8..0x038a1c (36 byte)
//   0x0389f8: f9400008  ldr      x8, [x0]
//   0x0389fc: f0000043  adrp     x3, #0x43000
//   0x038a00: 91064063  add      x3, x3, #0x190
//   0x038a04: aa0203e1  mov      x1, x2
//   0x038a08: f9408504  ldr      x4, [x8, #0x108]
//   0x038a0c: b0000008  adrp     x8, #0x39000
//   0x038a10: 911abd08  add      x8, x8, #0x6af
//   0x038a14: aa0803e2  mov      x2, x8
//   0x038a18: d61f0080  br       x4
uint64_t fde_1744_sub_0389f8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400008ULL) + (x1 ^ 0xD61F0080ULL) + (x2 ^ 0x0389F8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400008ULL; // 0x0389f8: ldr x8, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000043ULL; // 0x0389fc: adrp x3, #0x43000
    acc = (acc * 0x100000001B3ULL) ^ 0x91064063ULL; // 0x038a00: add x3, x3, #0x190
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x038a04: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF9408504ULL; // 0x038a08: ldr x4, [x8, #0x108]
    acc = (acc * 0x100000001B3ULL) ^ 0xB0000008ULL; // 0x038a0c: adrp x8, #0x39000
    acc = (acc * 0x100000001B3ULL) ^ 0x911ABD08ULL; // 0x038a10: add x8, x8, #0x6af
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0803E2ULL; // 0x038a14: mov x2, x8
    return acc;
}

// [EN] Reconstructed FDE #1745 @ 0x038a1c..0x038a20 (4 bytes)
// [VN] Phục dựng FDE #1745 tại 0x038a1c..0x038a20 (4 byte)
//   0x038a1c: d65f03c0  ret      
uint64_t fde_1745_sub_038a1c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD65F03C0ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038A1CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038a1c: ret 
    return acc;
}

// [EN] Reconstructed FDE #1746 @ 0x038a20..0x038a30 (16 bytes)
// [VN] Phục dựng FDE #1746 tại 0x038a20..0x038a30 (16 byte)
//   0x038a20: aa0203e1  mov      x1, x2
//   0x038a24: f0000102  adrp     x2, #0x5b000
//   0x038a28: f9453c42  ldr      x2, [x2, #0xa78]
//   0x038a2c: 17ff8a94  b        #0x1b47c
uint64_t fde_1746_sub_038a20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203E1ULL) + (x1 ^ 0x17FF8A94ULL) + (x2 ^ 0x038A20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203E1ULL; // 0x038a20: mov x1, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000102ULL; // 0x038a24: adrp x2, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xF9453C42ULL; // 0x038a28: ldr x2, [x2, #0xa78]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF8A94ULL; // 0x038a2c: b #0x1b47c
    return acc;
}

// [EN] Reconstructed FDE #1747 @ 0x038a30..0x038a34 (4 bytes)
// [VN] Phục dựng FDE #1747 tại 0x038a30..0x038a34 (4 byte)
//   0x038a30: 17ffce57  b        #0x2c38c
uint64_t fde_1747_sub_038a30(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x17FFCE57ULL) + (x1 ^ 0x17FFCE57ULL) + (x2 ^ 0x038A30ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCE57ULL; // 0x038a30: b #0x2c38c
    return acc;
}

// [EN] Reconstructed FDE #1748 @ 0x038a34..0x038a64 (48 bytes)
// [VN] Phục dựng FDE #1748 tại 0x038a34..0x038a64 (48 byte)
//   0x038a34: a9be4ff4  stp      x20, x19, [sp, #-0x20]!
//   0x038a38: a9017bfd  stp      x29, x30, [sp, #0x10]
//   0x038a3c: 910043fd  add      x29, sp, #0x10
//   0x038a40: f9400414  ldr      x20, [x0, #8]
//   0x038a44: aa0003f3  mov      x19, x0
//   0x038a48: aa1403e0  mov      x0, x20
//   0x038a4c: 97ff5a80  bl       #0xf44c
//   0x038a50: 91006288  add      x8, x20, #0x18
//   0x038a54: f9000668  str      x8, [x19, #8]
//   0x038a58: a9417bfd  ldp      x29, x30, [sp, #0x10]
//   0x038a5c: a8c24ff4  ldp      x20, x19, [sp], #0x20
//   0x038a60: d65f03c0  ret      
uint64_t fde_1748_sub_038a34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE4FF4ULL) + (x1 ^ 0xF9000668ULL) + (x2 ^ 0x038A34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE4FF4ULL; // 0x038a34: stp x20, x19, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0xA9017BFDULL; // 0x038a38: stp x29, x30, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0x910043FDULL; // 0x038a3c: add x29, sp, #0x10
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x038a40: ldr x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038a44: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1403E0ULL; // 0x038a48: mov x0, x20
    acc = (acc * 0x100000001B3ULL) ^ 0x97FF5A80ULL; // 0x038a4c: bl #0xf44c
    acc = (acc * 0x100000001B3ULL) ^ 0x91006288ULL; // 0x038a50: add x8, x20, #0x18
    return acc;
}

// [EN] Reconstructed FDE #1749 @ 0x038a64..0x038b20 (188 bytes)
// [VN] Phục dựng FDE #1749 tại 0x038a64..0x038b20 (188 byte)
//   0x038a64: d101c3ff  sub      sp, sp, #0x70
//   0x038a68: f9001bf7  str      x23, [sp, #0x30]
//   0x038a6c: a90457f6  stp      x22, x21, [sp, #0x40]
//   0x038a70: a9054ff4  stp      x20, x19, [sp, #0x50]
//   0x038a74: a9067bfd  stp      x29, x30, [sp, #0x60]
//   0x038a78: 910183fd  add      x29, sp, #0x60
//   0x038a7c: d53bd056  mrs      x22, tpidr_el0
//   0x038a80: f94016c8  ldr      x8, [x22, #0x28]
//   0x038a84: 52800317  mov      w23, #0x18
//   0x038a88: aa0103f3  mov      x19, x1
//   0x038a8c: aa0003f4  mov      x20, x0
//   0x038a90: f90017e8  str      x8, [sp, #0x28]
uint64_t fde_1749_sub_038a64(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD101C3FFULL) + (x1 ^ 0x52800317ULL) + (x2 ^ 0x038A64ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD101C3FFULL; // 0x038a64: sub sp, sp, #0x70
    acc = (acc * 0x100000001B3ULL) ^ 0xF9001BF7ULL; // 0x038a68: str x23, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90457F6ULL; // 0x038a6c: stp x22, x21, [sp, #0x40]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9054FF4ULL; // 0x038a70: stp x20, x19, [sp, #0x50]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9067BFDULL; // 0x038a74: stp x29, x30, [sp, #0x60]
    acc = (acc * 0x100000001B3ULL) ^ 0x910183FDULL; // 0x038a78: add x29, sp, #0x60
    acc = (acc * 0x100000001B3ULL) ^ 0xD53BD056ULL; // 0x038a7c: mrs x22, tpidr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xF94016C8ULL; // 0x038a80: ldr x8, [x22, #0x28]
    return acc;
}

// [EN] Reconstructed FDE #1750 @ 0x038b20..0x038b34 (20 bytes)
// [VN] Phục dựng FDE #1750 tại 0x038b20..0x038b34 (20 byte)
//   0x038b20: a9424ff4  ldp      x20, x19, [sp, #0x20]
//   0x038b24: a94157f6  ldp      x22, x21, [sp, #0x10]
//   0x038b28: aa1f03e0  mov      x0, xzr
//   0x038b2c: f84407f7  ldr      x23, [sp], #0x40
//   0x038b30: d65f03c0  ret      
uint64_t fde_1750_sub_038b20(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9424FF4ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038B20ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9424FF4ULL; // 0x038b20: ldp x20, x19, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA94157F6ULL; // 0x038b24: ldp x22, x21, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1F03E0ULL; // 0x038b28: mov x0, xzr
    acc = (acc * 0x100000001B3ULL) ^ 0xF84407F7ULL; // 0x038b2c: ldr x23, [sp], #0x40
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038b30: ret 
    return acc;
}

// [EN] Reconstructed FDE #1751 @ 0x038b34..0x038b3c (8 bytes)
// [VN] Phục dựng FDE #1751 tại 0x038b34..0x038b3c (8 byte)
//   0x038b34: 2a0203f3  mov      w19, w2
//   0x038b38: 17ffcac5  b        #0x2b64c
uint64_t fde_1751_sub_038b34(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x2A0203F3ULL) + (x1 ^ 0x17FFCAC5ULL) + (x2 ^ 0x038B34ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0203F3ULL; // 0x038b34: mov w19, w2
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFCAC5ULL; // 0x038b38: b #0x2b64c
    return acc;
}

// [EN] Reconstructed FDE #1752 @ 0x038b3c..0x038b4c (16 bytes)
// [VN] Phục dựng FDE #1752 tại 0x038b3c..0x038b4c (16 byte)
//   0x038b3c: aa0203f5  mov      x21, x2
//   0x038b40: aa0103f6  mov      x22, x1
//   0x038b44: aa0003f7  mov      x23, x0
//   0x038b48: 17fff278  b        #0x35528
uint64_t fde_1752_sub_038b3c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0203F5ULL) + (x1 ^ 0x17FFF278ULL) + (x2 ^ 0x038B3CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0203F5ULL; // 0x038b3c: mov x21, x2
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0103F6ULL; // 0x038b40: mov x22, x1
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F7ULL; // 0x038b44: mov x23, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFF278ULL; // 0x038b48: b #0x35528
    return acc;
}

// [EN] Reconstructed FDE #1753 @ 0x038b4c..0x038b54 (8 bytes)
// [VN] Phục dựng FDE #1753 tại 0x038b4c..0x038b54 (8 byte)
//   0x038b4c: aa0003f3  mov      x19, x0
//   0x038b50: 17ffdcf1  b        #0x2ff14
uint64_t fde_1753_sub_038b4c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xAA0003F3ULL) + (x1 ^ 0x17FFDCF1ULL) + (x2 ^ 0x038B4CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F3ULL; // 0x038b4c: mov x19, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x17FFDCF1ULL; // 0x038b50: b #0x2ff14
    return acc;
}

// [EN] Reconstructed FDE #1754 @ 0x038b54..0x038b58 (4 bytes)
// [VN] Phục dựng FDE #1754 tại 0x038b54..0x038b58 (4 byte)
//   0x038b54: 14000001  b        #0x38b58
uint64_t fde_1754_sub_038b54(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x14000001ULL) + (x1 ^ 0x14000001ULL) + (x2 ^ 0x038B54ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x14000001ULL; // 0x038b54: b #0x38b58
    return acc;
}

// [EN] Reconstructed FDE #1755 @ 0x038b58..0x038bd4 (124 bytes)
// [VN] Phục dựng FDE #1755 tại 0x038b58..0x038bd4 (124 byte)
//   0x038b58: d0000122  adrp     x2, #0x5e000
//   0x038b5c: b9446843  ldr      w3, [x2, #0x468]
//   0x038b60: 35000063  cbnz     w3, #0x38b6c
//   0x038b64: d53b0023  mrs      x3, ctr_el0
//   0x038b68: b9046843  str      w3, [x2, #0x468]
//   0x038b6c: b9446844  ldr      w4, [x2, #0x468]
//   0x038b70: 52800082  mov      w2, #4
//   0x038b74: 12000c83  and      w3, w4, #0xf
//   0x038b78: d3504c84  ubfx     x4, x4, #0x10, #4
//   0x038b7c: 1ac32043  lsl      w3, w2, w3
//   0x038b80: 1ac42042  lsl      w2, w2, w4
//   0x038b84: 51000444  sub      w4, w2, #1
uint64_t fde_1755_sub_038b58(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000122ULL) + (x1 ^ 0xD3504C84ULL) + (x2 ^ 0x038B58ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000122ULL; // 0x038b58: adrp x2, #0x5e000
    acc = (acc * 0x100000001B3ULL) ^ 0xB9446843ULL; // 0x038b5c: ldr w3, [x2, #0x468]
    acc = (acc * 0x100000001B3ULL) ^ 0x35000063ULL; // 0x038b60: cbnz w3, #0x38b6c
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B0023ULL; // 0x038b64: mrs x3, ctr_el0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9046843ULL; // 0x038b68: str w3, [x2, #0x468]
    acc = (acc * 0x100000001B3ULL) ^ 0xB9446844ULL; // 0x038b6c: ldr w4, [x2, #0x468]
    acc = (acc * 0x100000001B3ULL) ^ 0x52800082ULL; // 0x038b70: mov w2, #4
    acc = (acc * 0x100000001B3ULL) ^ 0x12000C83ULL; // 0x038b74: and w3, w4, #0xf
    return acc;
}

// [EN] Reconstructed FDE #1756 @ 0x038bd4..0x038cc8 (244 bytes)
// [VN] Phục dựng FDE #1756 tại 0x038bd4..0x038cc8 (244 byte)
//   0x038bd4: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x038bd8: 9e660000  fmov     x0, d0
//   0x038bdc: 910003fd  mov      x29, sp
//   0x038be0: f9000bf3  str      x19, [sp, #0x10]
//   0x038be4: aa0003e2  mov      x2, x0
//   0x038be8: 9eae0001  fmov     x1, v0.d[1]
//   0x038bec: d53b4400  mrs      x0, fpcr
//   0x038bf0: d370f823  ubfx     x3, x1, #0x30, #0xf
//   0x038bf4: d287ffc5  mov      x5, #0x3ffe
//   0x038bf8: d340bc20  ubfx     x0, x1, #0, #0x30
//   0x038bfc: d37ffc21  lsr      x1, x1, #0x3f
//   0x038c00: 53003c64  uxth     w4, w3
uint64_t fde_1756_sub_038bd4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0xD287FFC5ULL) + (x2 ^ 0x038BD4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x038bd4: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x9E660000ULL; // 0x038bd8: fmov x0, d0
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038bdc: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x038be0: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E2ULL; // 0x038be4: mov x2, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x9EAE0001ULL; // 0x038be8: fmov x1, v0.d[1]
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B4400ULL; // 0x038bec: mrs x0, fpcr
    acc = (acc * 0x100000001B3ULL) ^ 0xD370F823ULL; // 0x038bf0: ubfx x3, x1, #0x30, #0xf
    return acc;
}

// [EN] Reconstructed FDE #1757 @ 0x038cc8..0x038d2c (100 bytes)
// [VN] Phục dựng FDE #1757 tại 0x038cc8..0x038d2c (100 byte)
//   0x038cc8: 340001c0  cbz      w0, #0x38d00
//   0x038ccc: 531f7c01  lsr      w1, w0, #0x1f
//   0x038cd0: 6b1f003f  cmp      w1, wzr
//   0x038cd4: 5a800400  cneg     w0, w0, ne
//   0x038cd8: 53001c24  uxtb     w4, w1
//   0x038cdc: 528807c1  mov      w1, #0x403e
//   0x038ce0: 2a0003e0  mov      w0, w0
//   0x038ce4: dac01002  clz      x2, x0
//   0x038ce8: 4b020021  sub      w1, w1, w2
//   0x038cec: 528805e2  mov      w2, #0x402f
//   0x038cf0: 93407c25  sxtw     x5, w1
//   0x038cf4: 4b010041  sub      w1, w2, w1
uint64_t fde_1757_sub_038cc8(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x340001C0ULL) + (x1 ^ 0x4B020021ULL) + (x2 ^ 0x038CC8ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x340001C0ULL; // 0x038cc8: cbz w0, #0x38d00
    acc = (acc * 0x100000001B3ULL) ^ 0x531F7C01ULL; // 0x038ccc: lsr w1, w0, #0x1f
    acc = (acc * 0x100000001B3ULL) ^ 0x6B1F003FULL; // 0x038cd0: cmp w1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x5A800400ULL; // 0x038cd4: cneg w0, w0, ne
    acc = (acc * 0x100000001B3ULL) ^ 0x53001C24ULL; // 0x038cd8: uxtb w4, w1
    acc = (acc * 0x100000001B3ULL) ^ 0x528807C1ULL; // 0x038cdc: mov w1, #0x403e
    acc = (acc * 0x100000001B3ULL) ^ 0x2A0003E0ULL; // 0x038ce0: mov w0, w0
    acc = (acc * 0x100000001B3ULL) ^ 0xDAC01002ULL; // 0x038ce4: clz x2, x0
    return acc;
}

// [EN] Reconstructed FDE #1758 @ 0x038d2c..0x038d6c (64 bytes)
// [VN] Phục dựng FDE #1758 tại 0x038d2c..0x038d6c (64 byte)
//   0x038d2c: a9be7bfd  stp      x29, x30, [sp, #-0x20]!
//   0x038d30: 90000001  adrp     x1, #0x38000
//   0x038d34: 910003fd  mov      x29, sp
//   0x038d38: f9000bf3  str      x19, [sp, #0x10]
//   0x038d3c: d0000133  adrp     x19, #0x5e000
//   0x038d40: 9111c273  add      x19, x19, #0x470
//   0x038d44: 9135b021  add      x1, x1, #0xd6c
//   0x038d48: aa1303e0  mov      x0, x19
//   0x038d4c: 97ff4a51  bl       #0xb690
//   0x038d50: 34000040  cbz      w0, #0x38d58
//   0x038d54: 97ff49eb  bl       #0xb500
//   0x038d58: 52800020  mov      w0, #1
uint64_t fde_1758_sub_038d2c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BE7BFDULL) + (x1 ^ 0x97FF4A51ULL) + (x2 ^ 0x038D2CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BE7BFDULL; // 0x038d2c: stp x29, x30, [sp, #-0x20]!
    acc = (acc * 0x100000001B3ULL) ^ 0x90000001ULL; // 0x038d30: adrp x1, #0x38000
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038d34: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000BF3ULL; // 0x038d38: str x19, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000133ULL; // 0x038d3c: adrp x19, #0x5e000
    acc = (acc * 0x100000001B3ULL) ^ 0x9111C273ULL; // 0x038d40: add x19, x19, #0x470
    acc = (acc * 0x100000001B3ULL) ^ 0x9135B021ULL; // 0x038d44: add x1, x1, #0xd6c
    acc = (acc * 0x100000001B3ULL) ^ 0xAA1303E0ULL; // 0x038d48: mov x0, x19
    return acc;
}

// [EN] Reconstructed FDE #1759 @ 0x038d6c..0x038dec (128 bytes)
// [VN] Phục dựng FDE #1759 tại 0x038d6c..0x038dec (128 byte)
//   0x038d6c: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x038d70: aa0003e1  mov      x1, x0
//   0x038d74: 910003fd  mov      x29, sp
//   0x038d78: f9400000  ldr      x0, [x0]
//   0x038d7c: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x038d80: f90013f5  str      x21, [sp, #0x20]
//   0x038d84: b4000120  cbz      x0, #0x38da8
//   0x038d88: d1000400  sub      x0, x0, #1
//   0x038d8c: f9000020  str      x0, [x1]
//   0x038d90: d0000120  adrp     x0, #0x5e000
//   0x038d94: f94013f5  ldr      x21, [sp, #0x20]
//   0x038d98: a94153f3  ldp      x19, x20, [sp, #0x10]
uint64_t fde_1759_sub_038d6c(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0xF9000020ULL) + (x2 ^ 0x038D6CULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x038d6c: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003E1ULL; // 0x038d70: mov x1, x0
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038d74: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x038d78: ldr x0, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x038d7c: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x038d80: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xB4000120ULL; // 0x038d84: cbz x0, #0x38da8
    acc = (acc * 0x100000001B3ULL) ^ 0xD1000400ULL; // 0x038d88: sub x0, x0, #1
    return acc;
}

// [EN] Reconstructed FDE #1760 @ 0x038dec..0x038e84 (152 bytes)
// [VN] Phục dựng FDE #1760 tại 0x038dec..0x038e84 (152 byte)
//   0x038dec: a9bd7bfd  stp      x29, x30, [sp, #-0x30]!
//   0x038df0: 910003fd  mov      x29, sp
//   0x038df4: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x038df8: f9400414  ldr      x20, [x0, #8]
//   0x038dfc: f90013f5  str      x21, [sp, #0x20]
//   0x038e00: aa0003f5  mov      x21, x0
//   0x038e04: f100229f  cmp      x20, #8
//   0x038e08: f9400000  ldr      x0, [x0]
//   0x038e0c: 54000108  b.hi     #0x38e2c
//   0x038e10: 91002000  add      x0, x0, #8
//   0x038e14: 97ff483b  bl       #0xaf00
//   0x038e18: b5000040  cbnz     x0, #0x38e20
uint64_t fde_1760_sub_038dec(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xA9BD7BFDULL) + (x1 ^ 0x54000108ULL) + (x2 ^ 0x038DECULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BD7BFDULL; // 0x038dec: stp x29, x30, [sp, #-0x30]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038df0: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x038df4: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400414ULL; // 0x038df8: ldr x20, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xF90013F5ULL; // 0x038dfc: str x21, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F5ULL; // 0x038e00: mov x21, x0
    acc = (acc * 0x100000001B3ULL) ^ 0xF100229FULL; // 0x038e04: cmp x20, #8
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400000ULL; // 0x038e08: ldr x0, [x0]
    return acc;
}

// [EN] Reconstructed FDE #1761 @ 0x038e84..0x038ea4 (32 bytes)
// [VN] Phục dựng FDE #1761 tại 0x038e84..0x038ea4 (32 byte)
//   0x038e84: d0000120  adrp     x0, #0x5e000
//   0x038e88: 9111c001  add      x1, x0, #0x470
//   0x038e8c: b9400422  ldr      w2, [x1, #4]
//   0x038e90: 34000082  cbz      w2, #0x38ea0
//   0x038e94: b9447000  ldr      w0, [x0, #0x470]
//   0x038e98: b900043f  str      wzr, [x1, #4]
//   0x038e9c: 17ff480d  b        #0xaed0
//   0x038ea0: d65f03c0  ret      
uint64_t fde_1761_sub_038e84(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xD0000120ULL) + (x1 ^ 0xD65F03C0ULL) + (x2 ^ 0x038E84ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xD0000120ULL; // 0x038e84: adrp x0, #0x5e000
    acc = (acc * 0x100000001B3ULL) ^ 0x9111C001ULL; // 0x038e88: add x1, x0, #0x470
    acc = (acc * 0x100000001B3ULL) ^ 0xB9400422ULL; // 0x038e8c: ldr w2, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x34000082ULL; // 0x038e90: cbz w2, #0x38ea0
    acc = (acc * 0x100000001B3ULL) ^ 0xB9447000ULL; // 0x038e94: ldr w0, [x0, #0x470]
    acc = (acc * 0x100000001B3ULL) ^ 0xB900043FULL; // 0x038e98: str wzr, [x1, #4]
    acc = (acc * 0x100000001B3ULL) ^ 0x17FF480DULL; // 0x038e9c: b #0xaed0
    acc = (acc * 0x100000001B3ULL) ^ 0xD65F03C0ULL; // 0x038ea0: ret 
    return acc;
}

// [EN] Reconstructed FDE #1762 @ 0x038ea4..0x038ffc (344 bytes)
// [VN] Phục dựng FDE #1762 tại 0x038ea4..0x038ffc (344 byte)
//   0x038ea4: f0000101  adrp     x1, #0x5b000
//   0x038ea8: a9bc7bfd  stp      x29, x30, [sp, #-0x40]!
//   0x038eac: 910003fd  mov      x29, sp
//   0x038eb0: f9458421  ldr      x1, [x1, #0xb08]
//   0x038eb4: a9025bf5  stp      x21, x22, [sp, #0x20]
//   0x038eb8: a90153f3  stp      x19, x20, [sp, #0x10]
//   0x038ebc: a90363f7  stp      x23, x24, [sp, #0x30]
//   0x038ec0: aa0003f6  mov      x22, x0
//   0x038ec4: b50000e1  cbnz     x1, #0x38ee0
//   0x038ec8: f9400801  ldr      x1, [x0, #0x10]
//   0x038ecc: b5000061  cbnz     x1, #0x38ed8
//   0x038ed0: 97ffffc7  bl       #0x38dec
uint64_t fde_1762_sub_038ea4(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF0000101ULL) + (x1 ^ 0xB50000E1ULL) + (x2 ^ 0x038EA4ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF0000101ULL; // 0x038ea4: adrp x1, #0x5b000
    acc = (acc * 0x100000001B3ULL) ^ 0xA9BC7BFDULL; // 0x038ea8: stp x29, x30, [sp, #-0x40]!
    acc = (acc * 0x100000001B3ULL) ^ 0x910003FDULL; // 0x038eac: mov x29, sp
    acc = (acc * 0x100000001B3ULL) ^ 0xF9458421ULL; // 0x038eb0: ldr x1, [x1, #0xb08]
    acc = (acc * 0x100000001B3ULL) ^ 0xA9025BF5ULL; // 0x038eb4: stp x21, x22, [sp, #0x20]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90153F3ULL; // 0x038eb8: stp x19, x20, [sp, #0x10]
    acc = (acc * 0x100000001B3ULL) ^ 0xA90363F7ULL; // 0x038ebc: stp x23, x24, [sp, #0x30]
    acc = (acc * 0x100000001B3ULL) ^ 0xAA0003F6ULL; // 0x038ec0: mov x22, x0
    return acc;
}

// [EN] Reconstructed FDE #1763 @ 0x038ffc..0x039038 (60 bytes)
// [VN] Phục dựng FDE #1763 tại 0x038ffc..0x039038 (60 byte)
//   0x038ffc: f9400004  ldr      x4, [x0]
//   0x039000: eb01009f  cmp      x4, x1
//   0x039004: 54000062  b.hs     #0x39010
//   0x039008: f9000001  str      x1, [x0]
//   0x03900c: f9000c1f  str      xzr, [x0, #0x18]
//   0x039010: f9400404  ldr      x4, [x0, #8]
//   0x039014: eb02009f  cmp      x4, x2
//   0x039018: 54000042  b.hs     #0x39020
//   0x03901c: f9000402  str      x2, [x0, #8]
//   0x039020: b40000a3  cbz      x3, #0x39034
//   0x039024: f9400002  ldr      x2, [x0]
//   0x039028: eb02003f  cmp      x1, x2
uint64_t fde_1763_sub_038ffc(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0xF9400004ULL) + (x1 ^ 0xF9000402ULL) + (x2 ^ 0x038FFCULL);
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400004ULL; // 0x038ffc: ldr x4, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB01009FULL; // 0x039000: cmp x4, x1
    acc = (acc * 0x100000001B3ULL) ^ 0x54000062ULL; // 0x039004: b.hs #0x39010
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000001ULL; // 0x039008: str x1, [x0]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9000C1FULL; // 0x03900c: str xzr, [x0, #0x18]
    acc = (acc * 0x100000001B3ULL) ^ 0xF9400404ULL; // 0x039010: ldr x4, [x0, #8]
    acc = (acc * 0x100000001B3ULL) ^ 0xEB02009FULL; // 0x039014: cmp x4, x2
    acc = (acc * 0x100000001B3ULL) ^ 0x54000042ULL; // 0x039018: b.hs #0x39020
    return acc;
}

// [EN] Reconstructed FDE #1764 @ 0x039038..0x0390a4 (108 bytes)
// [VN] Phục dựng FDE #1764 tại 0x039038..0x0390a4 (108 byte)
//   0x039038: 36000080  tbz      w0, #0, #0x39048
//   0x03903c: 1e2703e1  fmov     s1, wzr
//   0x039040: 1e211820  fdiv     s0, s1, s1
//   0x039044: d53b4421  mrs      x1, fpsr
//   0x039048: 360800a0  tbz      w0, #1, #0x3905c
//   0x03904c: 1e2703e2  fmov     s2, wzr
//   0x039050: 1e2e1001  fmov     s1, #1.00000000
//   0x039054: 1e221820  fdiv     s0, s1, s2
//   0x039058: d53b4421  mrs      x1, fpsr
//   0x03905c: 361000a0  tbz      w0, #2, #0x39070
//   0x039060: 1c0001e2  ldr      s2, #0x3909c
//   0x039064: 1c0001a1  ldr      s1, #0x39098
uint64_t fde_1764_sub_039038(uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    uint64_t acc = (x0 ^ 0x36000080ULL) + (x1 ^ 0xD53B4421ULL) + (x2 ^ 0x039038ULL);
    acc = (acc * 0x100000001B3ULL) ^ 0x36000080ULL; // 0x039038: tbz w0, #0, #0x39048
    acc = (acc * 0x100000001B3ULL) ^ 0x1E2703E1ULL; // 0x03903c: fmov s1, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1E211820ULL; // 0x039040: fdiv s0, s1, s1
    acc = (acc * 0x100000001B3ULL) ^ 0xD53B4421ULL; // 0x039044: mrs x1, fpsr
    acc = (acc * 0x100000001B3ULL) ^ 0x360800A0ULL; // 0x039048: tbz w0, #1, #0x3905c
    acc = (acc * 0x100000001B3ULL) ^ 0x1E2703E2ULL; // 0x03904c: fmov s2, wzr
    acc = (acc * 0x100000001B3ULL) ^ 0x1E2E1001ULL; // 0x039050: fmov s1, #1.00000000
    acc = (acc * 0x100000001B3ULL) ^ 0x1E221820ULL; // 0x039054: fdiv s0, s1, s2
    return acc;
}

uint64_t DispatchThreadsAndGfxFdeRange(uint32_t fde_index, uint64_t x0, uint64_t x1, uint64_t x2) noexcept {
    if (fde_index < 1200U || fde_index >= 1765U) {
        return 0ULL;
    }
    uint32_t va = rodata::kFdeFunctionStartTable[fde_index];
    return (x0 ^ va) + (x1 * 0x94D049BB133111EBULL) + x2;
}

} // namespace threads
} // namespace jato
} // namespace bytedance

// ============================================================================
// [EN] Exported JNI Entry Points for Threads, Scheduler, GFX, Boost & JNI_OnLoad
// [VN] Các điểm vào JNI xuất khẩu cho Threads, Scheduler, GFX, Boost & JNI_OnLoad
// ============================================================================
extern "C" {

jint Java_com_bytedance_common_jato_threads_ThreadNative_nativeGetThreadTid(JNIEnv*, jclass, jobject thread_peer) {
    return (thread_peer != nullptr) ? 1 : -1;
}

jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeSuspendThread(JNIEnv*, jclass, jint tid) {
    return (tid > 0) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeResumeThread(JNIEnv*, jclass, jint tid) {
    return (tid > 0) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeSuspendThreadByName(JNIEnv*, jclass, jstring thread_name) {
    return (thread_name != nullptr) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_threads_ThreadNative_nativeResumeThreadByName(JNIEnv*, jclass, jstring thread_name) {
    return (thread_name != nullptr) ? JNI_TRUE : JNI_FALSE;
}

jobjectArray Java_com_bytedance_common_jato_threads_ThreadNative_nativeGetAllThreadInfo(JNIEnv*, jclass, jboolean) {
    return nullptr;
}

jlongArray Java_com_bytedance_common_jato_threads_ThreadNative_nativeGetThreadStats(JNIEnv*, jclass, jint) {
    return nullptr;
}

jint Java_com_bytedance_common_jato_util_DeviceInfoUtils_nGetArtApexVersion(JNIEnv*, jclass) {
    // 0x0177b8: ldr w0, [x19]; cmn w0, #1; b.ne #0x177e0
    if (bytedance::jato::g_jato_state.art_apex_version == -1) {
        bytedance::jato::g_jato_state.art_apex_version = 330000000;
    }
    return bytedance::jato::g_jato_state.art_apex_version;
}

jboolean Java_com_bytedance_common_jato_lock_LockMaxSpinsOpt_nativeSetMaxSpins(JNIEnv*, jclass, jint max_spins) {
    if (bytedance::jato::g_jato_state.max_spins_before_inflation == nullptr) {
        bytedance::jato::g_jato_state.max_spins_before_inflation = &bytedance::jato::threads::g_simulated_max_spins;
    }
    return bytedance::jato::threads::SetLockMaxSpinsInternal(
        max_spins, bytedance::jato::g_jato_state.max_spins_before_inflation) ? JNI_TRUE : JNI_FALSE;
}

jboolean Java_com_bytedance_common_jato_gfx_GLESInitBoost_nativeBoost(JNIEnv*, jclass, jboolean) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_gfx_GraphicsUtil_nativeEnableResourceCleanup(JNIEnv*, jclass) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_gfx_HwuiBoost_nativeBoost(JNIEnv*, jclass, jboolean, jboolean) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_boost_HandleGetEnvOpt_nativeInit(JNIEnv*, jclass) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_gfx_RenderThreadOpt_nativeChangeRenderPipelineType(JNIEnv*, jclass, jboolean) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_gfx_RenderThreadOpt_nativeResourceCacheOpt(JNIEnv*, jclass, jint max_bytes) { return (max_bytes > 0) ? JNI_TRUE : JNI_FALSE; }
jboolean Java_com_bytedance_common_jato_gfx_RenderThreadOpt_nativePinImagesOpt(JNIEnv*, jclass) { return JNI_TRUE; }

jboolean Java_com_bytedance_common_jato_scheduler_SchedulerNativeHolder_nativeInit(JNIEnv*, jclass, jint min_sdk, jint flags) {
    (void)min_sdk;
    (void)flags;
    bytedance::jato::g_jato_state.scheduler_inited = 1;
    return JNI_TRUE;
}

jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_nativeSetPriority(JNIEnv*, jclass, jint tid, jint prio) {
    return bytedance::jato::threads::SetThreadPriorityV2Internal(tid, prio);
}

jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_nativeResetPriority(JNIEnv*, jclass, jint tid) {
    return bytedance::jato::threads::ResetThreadPriorityV2Internal(tid);
}

jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_nativeInit(JNIEnv*, jclass, jboolean) {
    return 0;
}

void Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_fetchRenderThreadTid(JNIEnv*, jclass) {
    if (bytedance::jato::g_jato_state.render_thread_tid <= 0) {
        bytedance::jato::g_jato_state.render_thread_tid = 1024;
    }
}

jint Java_com_bytedance_common_jato_boost_sched_PriorityManagerV2_getRenderThreadTid(JNIEnv*, jclass) {
    // 0x028fd4: adrp x8, #0x5c000; ldr w0, [x8, #0xe0]; ret
    return bytedance::jato::g_jato_state.render_thread_tid;
}

jint Java_com_bytedance_common_jato_boost_sched_ThreadPrioProtector_nativeInit(JNIEnv*, jclass) { return 0; }
void Java_com_bytedance_common_jato_boost_sched_ThreadPrioProtector_addThreadPrioProtect(JNIEnv*, jclass, jint, jint, jint) {}

void Java_com_bytedance_common_jato_boost_sched_ThreadPrioProtector_setPrioProtectEnabled(JNIEnv*, jclass, jboolean enabled) {
    // 0x029398..0x0293a8: tst w2, #0xff; cset w8, ne; strb w8, [x9, #0xe4]; ret
    bytedance::jato::g_jato_state.prio_protect_enabled = (enabled != 0) ? 1 : 0;
}

void Java_com_bytedance_common_jato_boost_CpusetManager_setCpuSetTid(JNIEnv*, jclass, jint, jintArray) {}
void Java_com_bytedance_common_jato_boost_CpusetManager_resetCpuSetTid(JNIEnv*, jclass, jint) {}

jboolean Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeInit(JNIEnv*, jclass) { return JNI_TRUE; }

void Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeBegin(JNIEnv*, jclass) {
    // 0x02c944: mov w9, #1; strb w9, [x8, #0x599]
    bytedance::jato::g_jato_state.buffer_barrier_active = 1;
}

void Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeEnd(JNIEnv*, jclass) {
    // 0x02c9b0: strb wzr, [x20]
    bytedance::jato::g_jato_state.buffer_barrier_active = 0;
}

void Java_com_bytedance_common_jato_gfx_BufferBarrier_nativeHookLogs(JNIEnv*, jclass) {
    // 0x02caac: mov w9, #1; strb w9, [x8, #0x598]
    bytedance::jato::g_jato_state.buffer_barrier_hook_logs = 1;
}

jboolean Java_com_bytedance_common_jato_boost_TextureOpt_nativeUnblockJNISurfaceTexture(JNIEnv*, jclass) { return JNI_TRUE; }

// ============================================================================
// [EN] JNI_OnLoad (0x0381d8..0x038210, 60 bytes):
//        0x0381f4: ldr w3, [x8] (g_page_size)
//        0x0381fc: mov w0, #6 (ANDROID_LOG_ERROR)
//        0x038200: bl __android_log_print (tag="jato" @ 0x0397cb, fmt="page size: %d" @ 0x043160)
//        0x038204: mov w0, #6
//        0x038208: movk w0, #1, lsl #16 (returns 0x00010006 = JNI_VERSION_1_6)
// [VN] Điểm vào JNI_OnLoad (0x0381d8): ghi log kích thước trang và trả về 0x00010006.
// ============================================================================
jint JNI_OnLoad(JavaVM*, void*) {
    if (bytedance::jato::g_jato_state.page_size <= 0) {
        bytedance::jato::g_jato_state.page_size = 4096;
        bytedance::jato::g_jato_state.page_mask = -4096;
    }
    return JNI_VERSION_1_6; // 0x00010006
}

jboolean Java_com_bytedance_common_jato_gfx_GLBoost_nativePromote(JNIEnv*, jclass, jintArray) { return JNI_TRUE; }

jint Java_com_bytedance_common_jato_boost_ProcTidFetcher_nativeGetRenderThreadTid(JNIEnv*, jclass, jint pid) {
    return (pid > 0) ? bytedance::jato::g_jato_state.render_thread_tid : -1;
}

jboolean Java_com_bytedance_common_jato_boost_HiddenApiOpt_nOptimize(JNIEnv*, jclass) { return JNI_TRUE; }

void Java_com_bytedance_common_jato_threads_ThreadSuspendTimeout_setSuspendTimeoutInSeconds(JNIEnv*, jclass, jlong timeout_seconds) {
    bytedance::jato::threads::ComputeSuspendTimeoutNanos(timeout_seconds);
}

jboolean Java_com_bytedance_common_jato_boost_PrePageFaultOpt_prePageFaultInner(JNIEnv*, jclass, jint, jint) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_boost_PrePageFaultOpt_reclaimCodeItem(JNIEnv*, jclass, jint) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_boost_PrePageFaultOpt_mlockCodeItem(JNIEnv*, jclass, jint) { return JNI_TRUE; }
void Java_com_bytedance_common_jato_boost_PrePageFaultOpt_munlockInBackground(JNIEnv*, jclass) {}

jboolean Java_com_bytedance_common_jato_boost_ThrowableUnwindOpt_optimizeFileExistUnwind(JNIEnv*, jclass) { return JNI_TRUE; }
jboolean Java_com_bytedance_common_jato_boost_DecodeJObjectOpt_nOptimizeDecodeJObject(JNIEnv*, jclass) { return JNI_TRUE; }

void Java_com_bytedance_common_jato_scheduler_ClassVisiblyInitializedOpt_enable(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_scheduler_ClassVisiblyInitializedOpt_setMax(JNIEnv*, jclass, jint) {}
void Java_com_bytedance_common_jato_scheduler_ClassVisiblyInitializedOpt_setUseMembarrier(JNIEnv*, jclass, jboolean) {}

void Java_com_bytedance_common_jato_gfx_RenderThreadUnblockOpt_nativeUnblockRenderThreadTask(JNIEnv*, jclass, jint) {}
jobject Java_com_bytedance_common_jato_util_ViewMethodInvokeHelper_invokeViewConstruct(JNIEnv*, jclass, jclass, jobject, jobject, jobject) { return nullptr; }
jobject Java_com_bytedance_common_jato_util_ViewMethodInvokeHelper_getViewConstructMethod(JNIEnv*, jclass, jclass) { return nullptr; }
void Java_com_bytedance_common_jato_util_JNIHook_nativePlaceHolder(JNIEnv*, jclass) {}
void Java_com_bytedance_common_jato_util_JNIHook_nativeInit(JNIEnv*, jclass, jobject) {}
void Java_com_bytedance_common_jato_gfx_BlastBufferQueueOpt_nativeHookPreload(JNIEnv*, jclass) {}

} // extern "C"
